#include <SDL.h>

#include <vector>
#include <array>
#include <string>
#include <map>

extern "C"
{
#include "../d_event.h"
#include "../g_input.h"
#include "../i_joy.h"
#include "../sdl/sdlmain.h"

extern void D_PostEvent(const event_t* ev);

}

std::map<int, SDL_GameController*> _gamepads;

//	static CV_PossibleValue_t joyaxis_cons_t[] = { {0, "None"},
//{1, "X-Axis"}, {2, "Y-Axis"}, {-1, "X-Axis-"}, {-2, "Y-Axis-"},
//#if JOYAXISSET > 1
//{3, "Z-Axis"}, {4, "X-Rudder"}, {-3, "Z-Axis-"}, {-4, "X-Rudder-"},
//#endif
//#if JOYAXISSET > 2
//{5, "Y-Rudder"}, {6, "Z-Rudder"}, {-5, "Y-Rudder-"}, {-6, "Z-Rudder-"},
//#endif
//#if JOYAXISSET > 3
//{7, "U-Axis"}, {8, "V-Axis"}, {-7, "U-Axis-"}, {-8, "V-Axis-"},
//#endif
// {0, NULL} };
//#if JOYAXISSET > 4
//	"More Axis Sets"
//#endif

//	consvar_t cv_moveaxis = CVAR_INIT("joyaxis_move", "Y-Axis", CV_SAVE, joyaxis_cons_t, NULL);
//	consvar_t cv_sideaxis = CVAR_INIT("joyaxis_side", "X-Axis", CV_SAVE, joyaxis_cons_t, NULL);
//	consvar_t cv_lookaxis = CVAR_INIT("joyaxis_look", "X-Rudder-", CV_SAVE, joyaxis_cons_t, NULL);
//	consvar_t cv_turnaxis = CVAR_INIT("joyaxis_turn", "Z-Axis", CV_SAVE, joyaxis_cons_t, NULL);
//	consvar_t cv_jumpaxis = CVAR_INIT("joyaxis_jump", "None", CV_SAVE, joyaxis_cons_t, NULL);
//	consvar_t cv_spinaxis = CVAR_INIT("joyaxis_spin", "None", CV_SAVE, joyaxis_cons_t, NULL);
//	consvar_t cv_shieldaxis = CVAR_INIT("joyaxis_shield", "None", CV_SAVE, joyaxis_cons_t, NULL);
//	consvar_t cv_fireaxis = CVAR_INIT("joyaxis_fire", "Z-Rudder", CV_SAVE, joyaxis_cons_t, NULL);
//	consvar_t cv_firenaxis = CVAR_INIT("joyaxis_firenormal", "Z-Axis", CV_SAVE, joyaxis_cons_t, NULL);
//	consvar_t cv_deadzone = CVAR_INIT("joy_deadzone", "0.125", CV_FLOAT | CV_SAVE, zerotoone_cons_t, NULL);
//	consvar_t cv_digitaldeadzone = CVAR_INIT("joy_digdeadzone", "0.25", CV_FLOAT | CV_SAVE, zerotoone_cons_t, NULL);


static inline int SDLGameControllerAxisToGameAxis(SDL_GameControllerAxis axis)
{
	switch (axis)
	{
	case SDL_CONTROLLER_AXIS_LEFTX:
		return 1; //{1, "X-Axis"};
	case SDL_CONTROLLER_AXIS_LEFTY:
		return 2; //{2, "Y-Axis"}
	case SDL_CONTROLLER_AXIS_RIGHTX:
		return 3; //{3, "Z-Axis"}
	case SDL_CONTROLLER_AXIS_RIGHTY:
		return 4; //{4, "X-Rudder"}
	case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
		return 5; //{5, "Y-Rudder"}
	case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
		return 6; //{6, "Z-Rudder"}
	}
	return 0;
}

static INT32 SDLJoyAxis(const Sint16 axis, evtype_t which)
{
	// -32768 to 32767
	INT32 raxis = axis / 32;
	if (which == ev_joystick)
	{
		raxis = JoyInfo.scale != 1 ? ((raxis / JoyInfo.scale) * JoyInfo.scale) : raxis;
	}
	else if (which == ev_joystick2)
	{
		raxis = JoyInfo2.scale != 1 ? ((raxis / JoyInfo2.scale) * JoyInfo2.scale) : raxis;
	}
	return raxis;
}

/*
		gamecontroldefault[i][GC_JUMP         ][1] = KEY_JOY1+0; // A
		gamecontroldefault[i][GC_SPIN         ][1] = KEY_JOY1+2; // X
		gamecontroldefault[i][GC_SHIELD       ][1] = KEY_JOY1+1; // B
		gamecontroldefault[i][GC_CUSTOM1      ][1] = KEY_JOY1+3; // Y
		gamecontroldefault[i][GC_CUSTOM2      ][1] = KEY_JOY1+4; // LB
		gamecontroldefault[i][GC_CENTERVIEW   ][1] = KEY_JOY1+5; // RB
		gamecontroldefault[i][GC_CUSTOM3      ][1] = KEY_JOY1+8; // Left Stick
		gamecontroldefault[i][GC_CAMTOGGLE    ][1] = KEY_JOY1+9; // Right Stick
		gamecontroldefault[i][GC_SCORES       ][1] = KEY_JOY1+6; // Back
		gamecontroldefault[i][GC_SYSTEMMENU   ][0] = KEY_JOY1+7; // Start
		gamecontroldefault[i][GC_VIEWPOINTNEXT][1] = KEY_HAT1+0; // D-Pad Up
		gamecontroldefault[i][GC_TOSSFLAG     ][1] = KEY_HAT1+1; // D-Pad Down
		gamecontroldefault[i][GC_WEAPONPREV   ][1] = KEY_HAT1+2; // D-Pad Left
		gamecontroldefault[i][GC_WEAPONNEXT   ][1] = KEY_HAT1+3; // D-Pad Right
*/

static inline int MapControllerButtonToJoyKey(INT32 KEY_JOY, INT32 KEY_HAT, SDL_GameControllerButton button)
{
	switch (button)
	{
	case SDL_CONTROLLER_BUTTON_A: return KEY_JOY + 0;
	case SDL_CONTROLLER_BUTTON_B: return KEY_JOY + 1;
	case SDL_CONTROLLER_BUTTON_X: return KEY_JOY + 2;
	case SDL_CONTROLLER_BUTTON_Y: return KEY_JOY + 3;
	case SDL_CONTROLLER_BUTTON_BACK: return KEY_JOY + 6;
	case SDL_CONTROLLER_BUTTON_GUIDE: return -1;
	case SDL_CONTROLLER_BUTTON_START: return KEY_JOY + 7;
	case SDL_CONTROLLER_BUTTON_LEFTSTICK: return KEY_JOY + 8;
	case SDL_CONTROLLER_BUTTON_RIGHTSTICK: return KEY_JOY + 9;
	case SDL_CONTROLLER_BUTTON_LEFTSHOULDER: return KEY_JOY + 4;
	case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER: return KEY_JOY + 5;
	case SDL_CONTROLLER_BUTTON_DPAD_UP: return KEY_HAT + 0;
	case SDL_CONTROLLER_BUTTON_DPAD_DOWN: return KEY_HAT + 1;
	case SDL_CONTROLLER_BUTTON_DPAD_LEFT: return KEY_HAT + 2;
	case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: return KEY_HAT + 3;
	case SDL_CONTROLLER_BUTTON_PADDLE1: return KEY_JOY + 10;  /* Xbox Elite paddle P1 (upper left, facing the back) */
	case SDL_CONTROLLER_BUTTON_PADDLE2: return KEY_JOY + 11;  /* Xbox Elite paddle P3 (upper right, facing the back) */
	case SDL_CONTROLLER_BUTTON_PADDLE3: return KEY_JOY + 12;  /* Xbox Elite paddle P2 (lower left, facing the back) */
	case SDL_CONTROLLER_BUTTON_PADDLE4: return KEY_JOY + 13;  /* Xbox Elite paddle P4 (lower right, facing the back) */
	case SDL_CONTROLLER_BUTTON_TOUCHPAD: return KEY_JOY + 14; /* PS4/PS5 touchpad button */
	}
	return -1;
}

extern "C" void uwp_handle_device_button(SDL_ControllerButtonEvent evt)
{
	event_t event;
	INT32 starting_key = KEY_JOY1;
	INT32 hat_key = KEY_HAT1;

	//Check event validity against current configuration
	if (_gamepads.empty())
		return;
	auto gamepad_it = _gamepads.find(evt.which);
	if (_gamepads.size() == 1 && gamepad_it != _gamepads.end())
		event.type = ev_joystick;
	else if (_gamepads.size() == 2 && gamepad_it != _gamepads.end())
	{
		if (gamepad_it == _gamepads.begin())
			event.type = ev_joystick;
		else
		{
			event.type = ev_joystick2;
			starting_key = KEY_2JOY1;
			hat_key = KEY_2HAT1;
		}
	}
	else
		return;

	/*
		Uint32 type;        /**< ::SDL_CONTROLLERBUTTONDOWN or ::SDL_CONTROLLERBUTTONUP */
		//Uint32 timestamp;   /**< In milliseconds, populated using SDL_GetTicks() */
		//SDL_JoystickID which; /**< The joystick instance id */
		//Uint8 button;       /**< The controller button (SDL_GameControllerButton) */
		//Uint8 state;        /**< ::SDL_PRESSED or ::SDL_RELEASED */
		//Uint8 padding1;
		//Uint8 padding2;


	if (evt.type == SDL_CONTROLLERBUTTONUP)
	{
		event.type = ev_keyup;
	}
	else if (evt.type == SDL_CONTROLLERBUTTONDOWN)
	{
		event.type = ev_keydown;
	}
	else return;
	int key = MapControllerButtonToJoyKey(starting_key, hat_key, (SDL_GameControllerButton)evt.button);

	if (key != -1)
	{
		event.key = key;
	}
	else return;

	if (event.type != ev_console) D_PostEvent(&event);
}

extern "C" void uwp_handle_device_axis(SDL_ControllerAxisEvent evt)
{
	event_t event;
	event.type = ev_joystick;

	//Check event validity against current configuration
	if (_gamepads.empty())
		return;
	auto gamepad_it = _gamepads.find(evt.which);
	if (_gamepads.size() == 1 && gamepad_it != _gamepads.end())
		event.type = ev_joystick;
	else if (_gamepads.size() == 2 && gamepad_it != _gamepads.end())
	{
		if (gamepad_it == _gamepads.begin())
			event.type = ev_joystick;
		else
			event.type = ev_joystick2;
	}
	else
		return;

	//initialize game evers
	event.key = event.x = event.y = INT32_MAX;

	//Uint32 type;        /**< ::SDL_CONTROLLERAXISMOTION */
	//Uint32 timestamp;   /**< In milliseconds, populated using SDL_GetTicks() */
	//SDL_JoystickID which; /**< The joystick instance id */
	//Uint8 axis;         /**< The controller axis (SDL_GameControllerAxis) */
	//Uint8 padding1;
	//Uint8 padding2;
	//Uint8 padding3;
	//Sint16 value;       /**< The axis value (range: -32768 to 32767) */
	//Uint16 padding4;



	//axis
	if (evt.axis > JOYAXISSET * 2)
		return;

	auto axisval = SDLGameControllerAxisToGameAxis((SDL_GameControllerAxis)evt.axis);
	if (axisval == -1) return;

	if (axisval % 2)
	{
		axisval /= 2;
		event.key = axisval;
		event.x = SDLJoyAxis(evt.value, event.type);
	}
	else
	{
		axisval--;
		axisval /= 2;
		event.key = axisval;
		event.y = SDLJoyAxis(evt.value, event.type);
	}


	D_PostEvent(&event);
}

extern "C" void uwp_handle_device_added(SDL_ControllerDeviceEvent device_event)
{
	if (_gamepads.size() < 2)
	{
		auto controller = SDL_GameControllerOpen(device_event.which);
		if (controller != NULL)
		{
			_gamepads[device_event.which] = controller;
			if (_gamepads.size() == 1)
			{
				Joystick.bGamepadStyle = 0;
				Joystick.bJoyNeedPoll = 0;
			}
			else {
				Joystick2.bGamepadStyle = 0;
				Joystick2.bJoyNeedPoll = 0;
			}
		}
	}
}

extern "C" void uwp_handle_device_removed(SDL_ControllerDeviceEvent device_event)
{
	if (_gamepads.size() > 0)
	{
		auto pad = _gamepads.find(device_event.which);
		if (pad != _gamepads.end())
		{
			SDL_GameControllerClose(pad->second);
			_gamepads.erase(pad);
		}
	}
}

extern "C" void uwp_handle_device_remapped(SDL_ControllerDeviceEvent device_event)
{
	//NTD
}