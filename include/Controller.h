#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "types.h"
#include "Node.h"

/**
 * @brief TODO
 */
struct Controller : public Node {
	enum EButton {
		False = 0x0,

		PRESS_DPAD_LEFT  = 0x1,
		PRESS_DPAD_RIGHT = 0x2,
		PRESS_DPAD_DOWN  = 0x4,
		PRESS_DPAD_UP    = 0x8,

		PRESS_Z = 0x10,
		PRESS_R = 0x20,
		PRESS_L = 0x40,

		PRESS_A     = 0x100,
		PRESS_B     = 0x200,
		PRESS_X     = 0x400,
		PRESS_Y     = 0x800,
		PRESS_START = 0x1000,

		ANALOG_LEFT  = 0x1000000,
		ANALOG_RIGHT = 0x2000000,
		ANALOG_DOWN  = 0x4000000,
		ANALOG_UP    = 0x8000000,

		CSTICK_LEFT  = 0x10000,
		CSTICK_RIGHT = 0x20000,
		CSTICK_DOWN  = 0x40000,
		CSTICK_UP    = 0x80000,

		PRESS_DPAD = (PRESS_DPAD_LEFT | PRESS_DPAD_RIGHT | PRESS_DPAD_DOWN | PRESS_DPAD_UP),

		PRESS_LEFT  = (PRESS_DPAD_LEFT | ANALOG_LEFT),
		PRESS_RIGHT = (PRESS_DPAD_RIGHT | ANALOG_RIGHT),
		PRESS_DOWN  = (PRESS_DPAD_DOWN | ANALOG_DOWN),
		PRESS_UP    = (PRESS_DPAD_UP | ANALOG_UP),

		PRESS_ABXYLRZ = (PRESS_A | PRESS_B | PRESS_X | PRESS_Y | PRESS_L | PRESS_R | PRESS_Z),
	};

	void reset(u32);
	void updateCont(u32 keyStatus);
	void update();
	f32 getMainStickX();
	f32 getMainStickY();
	f32 getSubStickX();
	f32 getSubStickY();

	// _00     = VTBL
	// _00-_20 = Node

	u32 mCurrentInput;        // _20
	u32 mPrevInput;           // _24
	u32 mInputPressed;        // _28
	u32 mInputReleased;       // _2C
	u32 mButtonState;         // _30
	u32 mButtonMask;          // _34
	u32 _38;                  // _38
	u32 _3C;                  // _3C
	u32 mInputDelay;          // _40
	bool mIsControllerFrozen; // _44
	s8 mMainStickX;           // _45
	s8 mMainStickY;           // _46
	s8 mSubStickX;            // _47
	s8 mSubStickY;            // _48
	s8 _49;                   // _49
	s8 _4A;                   // _4A
	s8 _4B;                   // _4B
	s8 _4C;                   // _4C
};

/**
 * @brief TODO
 */
struct ControllerMgr {
	virtual bool keyDown(int); // _08

	void update();
	void init();
	void updateController(Controller*);
};

#endif // CONTROLLER_H
