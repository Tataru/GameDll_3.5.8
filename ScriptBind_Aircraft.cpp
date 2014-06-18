#include "StdAfx.h"
#include "ScriptBind_Aircraft.h"



const char *keyHold1 = "";
const char *keyHold2 = "";
const char *keyHold3 = "";
const char *keyHold4 = "";

const char *customKeyPressVar = "";
const char *playerKeyPressVar = "";

IView *sView;
IView *tView = 0;

CScriptBind_Aircraft::CScriptBind_Aircraft(ISystem *pSystem)
{
	CScriptableBase::Init(pSystem->GetIScriptSystem(), pSystem);

	SetGlobalName("csb");

	#undef SCRIPT_REG_CLASSNAME
	#define SCRIPT_REG_CLASSNAME &CScriptBind_Aircraft::

	SCRIPT_REG_FUNC(mouseX);
	SCRIPT_REG_FUNC(mouseY);
	SCRIPT_REG_FUNC(GetWidth);
	SCRIPT_REG_FUNC(GetHeight);
	SCRIPT_REG_FUNC(customKeyHold1);
	SCRIPT_REG_FUNC(customKeyHold2);
	SCRIPT_REG_FUNC(customKeyHold3);
	SCRIPT_REG_FUNC(customKeyHold4);
	SCRIPT_REG_FUNC(customKeyPress);
	SCRIPT_REG_FUNC(playerKeyPress);
	SCRIPT_REG_FUNC(customView);
	SCRIPT_REG_FUNC(resetView);
	SCRIPT_REG_TEMPLFUNC(DrawTextCustom, "x, y, size, color, alpha, textInput");
	SCRIPT_REG_TEMPLFUNC(customRotate, "thisID, x, y, z");
	SCRIPT_REG_TEMPLFUNC(setPlayerGroundFriction, "friction");
}

/////////////////////////////////////////////////////////Mouse x, y//////////////////////////////////////////////////////////////////////////////////

int CScriptBind_Aircraft::mouseX(IFunctionHandler *pH)
{
	gEnv->pHardwareMouse->GetHardwareMouseClientPosition(&x, &y);


		static bool initialized;
		if (!initialized) 
		{
			initialized = true;
			numberX=0;
		}


	if (x < 300)
	{
		gEnv->pHardwareMouse->SetHardwareMouseClientPosition(400, y);
		numberX = numberX - 100;
		x = x + 100;
	}
	
	sendX = x + numberX;
	
	if (x > 500)
	{
		gEnv->pHardwareMouse->SetHardwareMouseClientPosition(400, y);
		numberX = numberX + 100;
		x = x - 100;
	}
	
	sendX = x + numberX;
	
	return pH->EndFunction(sendX);
}

int CScriptBind_Aircraft::mouseY(IFunctionHandler *pH)
{
	gEnv->pHardwareMouse->GetHardwareMouseClientPosition(&x, &y);


		static bool initialized;
		if (!initialized) 
		{
			initialized = true;
			numberY=0;
		}

	if (y < 300)
	{
		gEnv->pHardwareMouse->SetHardwareMouseClientPosition(x, 400);
		numberY = numberY - 100;
		y = y + 100;
	}	
	
	if (y > 500)
	{
		gEnv->pHardwareMouse->SetHardwareMouseClientPosition(x, 400);
		numberY = numberY + 100;
		y = y - 100;
	}	
	
	sendY = y + numberY;

	return pH->EndFunction(sendY);
}

////////////////////////////////////////////////////////Resolution x, y///////////////////////////////////////////////////////////////////////////////////

int CScriptBind_Aircraft::GetWidth(IFunctionHandler *pH)
{
	return pH->EndFunction(gEnv->pRenderer->GetWidth());
}


int CScriptBind_Aircraft::GetHeight(IFunctionHandler *pH)
{
	return pH->EndFunction(gEnv->pRenderer->GetHeight());
}

////////////////////////////////////////////////////////Key input///////////////////////////////////////////////////////////////////////////////////

int CScriptBind_Aircraft::customKeyHold1(IFunctionHandler *pH)
{
	return pH->EndFunction(keyHold1);
}

int CScriptBind_Aircraft::customKeyHold2(IFunctionHandler *pH)
{
	return pH->EndFunction(keyHold2);
}

int CScriptBind_Aircraft::customKeyHold3(IFunctionHandler *pH)
{
	return pH->EndFunction(keyHold3);
}

int CScriptBind_Aircraft::customKeyHold4(IFunctionHandler *pH)
{
	return pH->EndFunction(keyHold4);
}

//////////////

int CScriptBind_Aircraft::customKeyPress(IFunctionHandler *pH)
{
	return pH->EndFunction(customKeyPressVar);
}

int CScriptBind_Aircraft::playerKeyPress(IFunctionHandler *pH)
{
	return pH->EndFunction(playerKeyPressVar);
}

////////////////////////////////////////////////////////Camera///////////////////////////////////////////////////////////////////////////////////

int CScriptBind_Aircraft::customView(IFunctionHandler *pH)
{
	IViewSystem* pViewSystem = gEnv->pGame->GetIGameFramework()->GetIViewSystem();

	static bool initialized;
	if (!initialized)
	{
		initialized = true;
		sView = pViewSystem->GetActiveView();
	}


	tView = pViewSystem->CreateView();
	unsigned int ViewId = pViewSystem->GetViewId(tView);
	pViewSystem->SetActiveView(ViewId);


	IEntity *pEntity = gEnv->pSystem->GetIEntitySystem()->FindEntityByName("Camera1");

	//EntityId gameCamId = pEntity->GetId();

	tView->LinkTo(pEntity);

	return pH->EndFunction();
}


int CScriptBind_Aircraft::resetView(IFunctionHandler *pH)
{
	IViewSystem* pViewSystem = gEnv->pGame->GetIGameFramework()->GetIViewSystem();

	unsigned int ViewId = pViewSystem->GetViewId(sView);

	pViewSystem->SetActiveView(ViewId);

	pViewSystem->RemoveView(tView);

	return  pH->EndFunction();
}


////////////////////////////////////////////////////////Draw text///////////////////////////////////////////////////////////////

int CScriptBind_Aircraft::DrawTextCustom(IFunctionHandler *pH, float x, float y, float size, Vec3 colorInput, float alpha, const char *textInput)
{
	const float color[] = {colorInput.x, colorInput.y, colorInput.z, alpha};
	gEnv->pRenderer->Draw2dLabel(x, y, size, color, false, textInput);

	return  pH->EndFunction();
}

////////////////////////////////////////////////////////Rotate///////////////////////////////////////////////////////////////

int CScriptBind_Aircraft::customRotate(IFunctionHandler *pH, int thisID, float x, float y, float z)
{
	EntityId entID = thisID;

	Vec3 rotSpeed;

	rotSpeed.x = x;
	rotSpeed.y = y;
	rotSpeed.z = z;

	Quat rotation = gEnv->pEntitySystem->GetEntity(entID)->GetRotation();
	
	Quat rotDelta (Ang3(DEG2RAD(rotSpeed)));

	rotation *= rotDelta;

	gEnv->pEntitySystem->GetEntity(entID)->SetRotation(rotation);

	return  pH->EndFunction();
}

////////////////////////////////////////////////////////Player friction///////////////////////////////////////////////////////////////

int CScriptBind_Aircraft::setPlayerGroundFriction(IFunctionHandler *pH, float friction)
{
	IActor *pPlayerActor = gEnv->pGame->GetIGameFramework()->GetClientActor();
	if(pPlayerActor)
	{
		IPhysicalEntity *pPhysicalEntity=pPlayerActor->GetEntity()->GetPhysics();
		if(pPhysicalEntity)
		{
			pe_player_dynamics ppd;
			ppd.maxVelGround=friction;
			pPhysicalEntity->SetParams(&ppd);
		}
	}

	return  pH->EndFunction();
}