#ifndef  _SCRIPTBIND_AIRCRAFT_
#define _SCRIPTBIND_AIRCRAFT_

#include <ScriptHelpers.h>
#include <IScriptSystem.h>
#include "IFlashUI.h"
#include "IHardwareMouse.h"
#include "Game.h" 
#include "IInput.h"

#include <IActionMapManager.h>
#include "PlayerInput.h"
#include "GameActions.h"

extern const char *keyHold1;
extern const char *keyHold2;
extern const char *keyHold3;
extern const char *keyHold4;

extern const char *customKeyPressVar;

class CScriptBind_Aircraft : public CScriptableBase
{
public:
	CScriptBind_Aircraft(ISystem *pSystem); 
	CScriptBind_Aircraft();
	virtual ~CScriptBind_Aircraft(){};

	int mouseX(IFunctionHandler *pH);
	int mouseY(IFunctionHandler *pH);
	float numberX;
	float numberY;
	float x;
	float y;
	float sendX;
	float sendY;

	//

	int GetWidth(IFunctionHandler *pH);
	int GetHeight(IFunctionHandler *pH);


	int customKeyHold1(IFunctionHandler *pH);
	int customKeyHold2(IFunctionHandler *pH);
	int customKeyHold3(IFunctionHandler *pH);
	int customKeyHold4(IFunctionHandler *pH);

	int customKeyPress(IFunctionHandler *pH);
	int playerKeyPress(IFunctionHandler *pH);

	int customView(IFunctionHandler *pH);
	int resetView(IFunctionHandler *pH);

	//

	int DrawTextCustom(IFunctionHandler *pH, float x, float y, float size, Vec3 colorInput, float alpha, const char *textInput);

	int customRotate(IFunctionHandler *pH, int thisID, float x, float y, float z);

	int setPlayerGroundFriction(IFunctionHandler *pH, float friction);

};



class CCustomInput : public IActionListener
{
public:

	CCustomInput()
	{
		if (m_actionHandler.GetNumHandlers() == 0)
		{
			const CGameActions& actions = g_pGame->Actions();

			m_actionHandler.AddHandler(actions.q,&CCustomInput::q);
			m_actionHandler.AddHandler(actions.w,&CCustomInput::w);
			m_actionHandler.AddHandler(actions.e,&CCustomInput::e);
			m_actionHandler.AddHandler(actions.r,&CCustomInput::r);
			m_actionHandler.AddHandler(actions.t,&CCustomInput::t);
			m_actionHandler.AddHandler(actions.y,&CCustomInput::y);
			m_actionHandler.AddHandler(actions.u,&CCustomInput::u);
			m_actionHandler.AddHandler(actions.i,&CCustomInput::i);
			m_actionHandler.AddHandler(actions.o,&CCustomInput::o);
			m_actionHandler.AddHandler(actions.p,&CCustomInput::p);
			m_actionHandler.AddHandler(actions.a,&CCustomInput::a);
			m_actionHandler.AddHandler(actions.s,&CCustomInput::s);
			m_actionHandler.AddHandler(actions.d,&CCustomInput::d);
			m_actionHandler.AddHandler(actions.f,&CCustomInput::f);
			m_actionHandler.AddHandler(actions.g,&CCustomInput::g);
			m_actionHandler.AddHandler(actions.h,&CCustomInput::h);
			m_actionHandler.AddHandler(actions.j,&CCustomInput::j);
			m_actionHandler.AddHandler(actions.k,&CCustomInput::k);
			m_actionHandler.AddHandler(actions.l,&CCustomInput::l);
			m_actionHandler.AddHandler(actions.z,&CCustomInput::z);
			m_actionHandler.AddHandler(actions.x,&CCustomInput::x);
			m_actionHandler.AddHandler(actions.c,&CCustomInput::c);
			m_actionHandler.AddHandler(actions.v,&CCustomInput::v);
			m_actionHandler.AddHandler(actions.b,&CCustomInput::b);
			m_actionHandler.AddHandler(actions.n,&CCustomInput::n);
			m_actionHandler.AddHandler(actions.m,&CCustomInput::m);

			m_actionHandler.AddHandler(actions.n1,&CCustomInput::n1);
			m_actionHandler.AddHandler(actions.n2,&CCustomInput::n2);
			m_actionHandler.AddHandler(actions.n3,&CCustomInput::n3);
			m_actionHandler.AddHandler(actions.n4,&CCustomInput::n4);
			m_actionHandler.AddHandler(actions.n5,&CCustomInput::n5);
			m_actionHandler.AddHandler(actions.n6,&CCustomInput::n6);
			m_actionHandler.AddHandler(actions.n7,&CCustomInput::n7);
			m_actionHandler.AddHandler(actions.n8,&CCustomInput::n8);
			m_actionHandler.AddHandler(actions.n9,&CCustomInput::n9);
			m_actionHandler.AddHandler(actions.n0,&CCustomInput::n0);

			m_actionHandler.AddHandler(actions.f1,&CCustomInput::f1);
			m_actionHandler.AddHandler(actions.f2,&CCustomInput::f2);
			m_actionHandler.AddHandler(actions.f3,&CCustomInput::f3);
			m_actionHandler.AddHandler(actions.f4,&CCustomInput::f4);
			m_actionHandler.AddHandler(actions.f5,&CCustomInput::f5);
			m_actionHandler.AddHandler(actions.f6,&CCustomInput::f6);
			m_actionHandler.AddHandler(actions.f7,&CCustomInput::f7);
			m_actionHandler.AddHandler(actions.f8,&CCustomInput::f8);
			m_actionHandler.AddHandler(actions.f9,&CCustomInput::f9);
			m_actionHandler.AddHandler(actions.f10,&CCustomInput::f10);
			m_actionHandler.AddHandler(actions.f11,&CCustomInput::f11);
			m_actionHandler.AddHandler(actions.f12,&CCustomInput::f12);
			m_actionHandler.AddHandler(actions.f13,&CCustomInput::f13);
			m_actionHandler.AddHandler(actions.f14,&CCustomInput::f14);
			m_actionHandler.AddHandler(actions.f15,&CCustomInput::f15);

			m_actionHandler.AddHandler(actions.tab,&CCustomInput::tab);
			m_actionHandler.AddHandler(actions.capslock,&CCustomInput::capslock);
			m_actionHandler.AddHandler(actions.lshift,&CCustomInput::lshift);
			m_actionHandler.AddHandler(actions.rshift,&CCustomInput::rshift);
			m_actionHandler.AddHandler(actions.lctrl,&CCustomInput::lctrl);
			m_actionHandler.AddHandler(actions.rctrl,&CCustomInput::rctrl);
			m_actionHandler.AddHandler(actions.lalt,&CCustomInput::lalt);
			m_actionHandler.AddHandler(actions.ralt,&CCustomInput::ralt);
			m_actionHandler.AddHandler(actions.space,&CCustomInput::space);

			m_actionHandler.AddHandler(actions.comma,&CCustomInput::comma);
			m_actionHandler.AddHandler(actions.period,&CCustomInput::period);
			m_actionHandler.AddHandler(actions.slash,&CCustomInput::slash);
			m_actionHandler.AddHandler(actions.backslash,&CCustomInput::backslash);
			m_actionHandler.AddHandler(actions.semicolon,&CCustomInput::semicolon);
			m_actionHandler.AddHandler(actions.apostrophe,&CCustomInput::apostrophe);
			m_actionHandler.AddHandler(actions.enter,&CCustomInput::enter);
			m_actionHandler.AddHandler(actions.lbracket,&CCustomInput::lbracket);
			m_actionHandler.AddHandler(actions.rbracket,&CCustomInput::rbracket);
			m_actionHandler.AddHandler(actions.minus,&CCustomInput::minus);
			m_actionHandler.AddHandler(actions.equals,&CCustomInput::equals);
			m_actionHandler.AddHandler(actions.backspace,&CCustomInput::backspace);

			m_actionHandler.AddHandler(actions.up,&CCustomInput::up);
			m_actionHandler.AddHandler(actions.down,&CCustomInput::down);
			m_actionHandler.AddHandler(actions.left,&CCustomInput::left);
			m_actionHandler.AddHandler(actions.right,&CCustomInput::right);

			m_actionHandler.AddHandler(actions.np_1,&CCustomInput::np_1);
			m_actionHandler.AddHandler(actions.np_2,&CCustomInput::np_2);
			m_actionHandler.AddHandler(actions.np_3,&CCustomInput::np_3);
			m_actionHandler.AddHandler(actions.np_4,&CCustomInput::np_4);
			m_actionHandler.AddHandler(actions.np_5,&CCustomInput::np_5);
			m_actionHandler.AddHandler(actions.np_6,&CCustomInput::np_6);
			m_actionHandler.AddHandler(actions.np_7,&CCustomInput::np_7);
			m_actionHandler.AddHandler(actions.np_8,&CCustomInput::np_8);
			m_actionHandler.AddHandler(actions.np_9,&CCustomInput::np_9);
			m_actionHandler.AddHandler(actions.np_0,&CCustomInput::np_0);
			m_actionHandler.AddHandler(actions.numlock,&CCustomInput::numlock);
			m_actionHandler.AddHandler(actions.np_divide,&CCustomInput::np_divide);
			m_actionHandler.AddHandler(actions.np_multiply,&CCustomInput::np_multiply);
			m_actionHandler.AddHandler(actions.np_subtract,&CCustomInput::np_subtract);
			m_actionHandler.AddHandler(actions.np_add,&CCustomInput::np_add);
			m_actionHandler.AddHandler(actions.np_enter,&CCustomInput::np_enter);
			m_actionHandler.AddHandler(actions.np_period,&CCustomInput::np_period);

			m_actionHandler.AddHandler(actions.home,&CCustomInput::home);
			m_actionHandler.AddHandler(actions.end,&CCustomInput::end);
			m_actionHandler.AddHandler(actions.ddelete,&CCustomInput::ddelete);
			m_actionHandler.AddHandler(actions.pgup,&CCustomInput::pgup);
			m_actionHandler.AddHandler(actions.pgdn,&CCustomInput::pgdn);
			m_actionHandler.AddHandler(actions.insert,&CCustomInput::insert);
			m_actionHandler.AddHandler(actions.scrolllock,&CCustomInput::scrolllock);
			m_actionHandler.AddHandler(actions.print,&CCustomInput::print);
			m_actionHandler.AddHandler(actions.pause,&CCustomInput::pause);

			m_actionHandler.AddHandler(actions.mouse1,&CCustomInput::mouse1);
			m_actionHandler.AddHandler(actions.mouse2,&CCustomInput::mouse2);
			m_actionHandler.AddHandler(actions.mouse3,&CCustomInput::mouse3);
			m_actionHandler.AddHandler(actions.mwheel_up,&CCustomInput::mwheel_up);
			m_actionHandler.AddHandler(actions.mwheel_down,&CCustomInput::mwheel_down);


		}

		IActionMapManager *pActionMapMan = g_pGame->GetIGameFramework()->GetIActionMapManager();
		pActionMapMan->AddExtraActionListener(this);
	}

	~CCustomInput()
	{
		IActionMapManager *pActionMapMan = g_pGame->GetIGameFramework()->GetIActionMapManager();
		pActionMapMan->RemoveExtraActionListener(this);
	}

	virtual void OnAction(const ActionId& action, int activationMode, float value)
	{
		m_actionHandler.Dispatch(this, 0, action, activationMode, value);
	}

	//bool myAction(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	//{
	//	if(activationMode == eAAM_OnPress)
	//	{
	//		CryLogAlways("Forward pressed.");
	//	}
	//	return false;
	//}

	////////////////////////////////////////////////////////////////////////////////////////////////

	void customKeyHoldFunc(int activationMode, const char *car)
	{
		if(activationMode == eAAM_OnPress)
		{
			if (keyHold1 == "")
			{
				keyHold1 = car;
			}
			else if (keyHold2 == "")
			{
				keyHold2 = car;
			}
			else if (keyHold3 == "")
			{
				keyHold3 = car;
			}
			else if (keyHold4 == "")
			{
				keyHold4 = car;
			}
		
		}
		if(activationMode == eAAM_OnRelease)
		{
			if (keyHold1 == car)
			{
				keyHold1 = "";
			}
			if (keyHold2 == car)
			{
				keyHold2 = "";
			}
			if (keyHold3 == car)
			{
				keyHold3 = "";
			}
			if (keyHold4 == car)
			{
				keyHold4 = "";
			}
		}
	}

	void customKeyPressFunc(int activationMode, const char *car)
	{
		if(activationMode == eAAM_OnPress)
		{
			customKeyPressVar = car;
		}
		else if(activationMode == eAAM_OnRelease)
		{
			customKeyPressVar = "";
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////

	bool q(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "q");
		return false;
	}

	bool w(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "w");
		return false;
	}

	bool e(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "e");
		return false;
	}

	bool r(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "r");
		return false;
	}

	bool t(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "t");
		return false;
	}

	bool y(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "y");
		return false;
	}

	bool u(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "u");
		return false;
	}

	bool i(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "i");
		return false;
	}

	bool o(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "o");
		return false;
	}

	bool p(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "p");
		return false;
	}

	bool a(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "a");
		return false;
	}

	bool s(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "s");
		return false;
	}

	bool d(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "d");
		return false;
	}

	bool f(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f");
		customKeyPressFunc(activationMode, "f");
		return false;
	}

	bool g(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "g");
		return false;
	}

	bool h(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "h");
		return false;
	}

	bool j(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "j");
		return false;
	}

	bool k(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "k");
		return false;
	}

	bool l(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "l");
		return false;
	}

	bool z(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "z");
		return false;
	}

	bool x(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "x");
		return false;
	}

	bool c(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "c");
		return false;
	}

	bool v(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "v");
		return false;
	}

	bool b(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "b");
		return false;
	}

	bool n(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "n");
		return false;
	}

	bool m(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "m");
		return false;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////

	bool n1(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "1");
		return false;
	}

	bool n2(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "2");
		return false;
	}

	bool n3(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "3");
		return false;
	}

	bool n4(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "4");
		return false;
	}

	bool n5(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "5");
		return false;
	}

	bool n6(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "6");
		return false;
	}

	bool n7(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "7");
		return false;
	}

	bool n8(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "8");
		return false;
	}

	bool n9(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "9");
		return false;
	}

	bool n0(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "0");
		return false;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////

	bool f1(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f1");
		return false;
	}

	bool f2(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f2");
		return false;
	}

	bool f3(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f3");
		return false;
	}

	bool f4(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f4");
		return false;
	}

	bool f5(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f5");
		return false;
	}

	bool f6(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f6");
		return false;
	}

	bool f7(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f7");
		return false;
	}

	bool f8(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f8");
		return false;
	}

	bool f9(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f9");
		return false;
	}

	bool f10(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f10");
		return false;
	}

	bool f11(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f11");
		return false;
	}

	bool f12(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f12");
		return false;
	}

	bool f13(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f13");
		return false;
	}

	bool f14(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f14");
		return false;
	}

	bool f15(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "f15");
		return false;
	}

	////////////////////////////////////////////////////////////////////////////////////////////////

	bool tab(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "tab");
		return false;
	}

	bool capslock(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "capslock");
		return false;
	}

	bool lshift(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "lshift");
		return false;
	}

	bool rshift(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "rshift");
		return false;
	}

	bool lctrl(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "lctrl");
		return false;
	}

	bool rctrl(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "rctrl");
		return false;
	}

	bool lalt(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "lalt");
		return false;
	}

	bool ralt(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "ralt");
		return false;
	}

	bool space(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "space");
		return false;
	}

	/////////////////////////////////////////////////////////

	bool comma(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "comma");
		return false;
	}

	bool period(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "period");
		return false;
	}

	bool slash(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "slash");
		return false;
	}

	bool backslash(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "backslash");
		return false;
	}

	bool semicolon(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "semicolon");
		return false;
	}

	bool apostrophe(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "apostrophe");
		return false;
	}

	bool enter(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "enter");
		return false;
	}

	bool lbracket(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "lbracket");
		return false;
	}

	bool rbracket(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "rbracket");
		return false;
	}

	bool minus(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "minus");
		return false;
	}

	bool equals(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "equals");
		return false;
	}

	bool backspace(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "backspace");
		return false;
	}

	///////////////////////////////////////////////////////

	bool up(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "up");
		return false;
	}

	bool down(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "down");
		return false;
	}

	bool left(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "left");
		return false;
	}

	bool right(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "right");
		return false;
	}

	/////////////////////////////////////////////////////

	bool np_1(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_1");
		return false;
	}

	bool np_2(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_2");
		return false;
	}

	bool np_3(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_3");
		return false;
	}

	bool np_4(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_4");
		return false;
	}

	bool np_5(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_5");
		return false;
	}

	bool np_6(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_6");
		return false;
	}

	bool np_7(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_7");
		return false;
	}

	bool np_8(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_8");
		return false;
	}

	bool np_9(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_9");
		return false;
	}

	bool np_0(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_0");
		return false;
	}

	bool numlock(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "numlock");
		return false;
	}

	bool np_divide(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_divide");
		return false;
	}

	bool np_multiply(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_multiply");
		return false;
	}

	bool np_subtract(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_subtract");
		return false;
	}

	bool np_add(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_add");
		return false;
	}

	bool np_enter(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_enter");
		return false;
	}

	bool np_period(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "np_period");
		return false;
	}

	/////////////////////////////////////////////////////

	bool home(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "home");
		return false;
	}

	bool end(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "end");
		return false;
	}

	bool ddelete(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "delete");
		return false;
	}

	bool pgup(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "pgup");
		return false;
	}

	bool pgdn(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "pgdn");
		return false;
	}

	bool insert(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "insert");
		return false;
	}

	bool scrolllock(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "scrolllock");
		return false;
	}

	bool print(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "print");
		return false;
	}

	bool pause(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "pause");
		return false;
	}

	///////////////////////////////////////////////////

	bool mouse1(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "mouse1");
		return false;
	}

	bool mouse2(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "mouse2");
		return false;
	}

	bool mouse3(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "mouse3");
		return false;
	}

	bool mwheel_up(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "mwheel_up");
		return false;
	}

	bool mwheel_down(EntityId entityId, const ActionId& actionId, int activationMode, float value)
	{
		customKeyHoldFunc(activationMode, "mwheel_down");
		return false;
	}

	///////////////////////////////////////////////////////



private:

	TActionHandler<CCustomInput> m_actionHandler;
};

#endif //_SCRIPTBIND_AIRCRAFT_

