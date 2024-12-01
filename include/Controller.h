#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "types.h"
#include "Node.h"

/**
 * @brief TODO
 *
 * @note I think these are more accurate based on Minty's notes.
 */
enum KeyboardButtons {
	KBBTN_NULL = 0x0,

	KBBTN_CSTICK_LEFT  = 0x1,
	KBBTN_CSTICK_RIGHT = 0x2,
	KBBTN_CSTICK_UP    = 0x4,
	KBBTN_CSTICK_DOWN  = 0x8,

	KBBTN_Unk5 = 0x10,
	KBBTN_Unk6 = 0x20,
	KBBTN_Unk7 = 0x40,
	KBBTN_Unk8 = 0x80,

	KBBTN_DPAD_LEFT  = 0x100, // not sure what direction this is
	KBBTN_DPAD_RIGHT = 0x200, // not sure what direction this is
	KBBTN_DPAD_UP    = 0x400, // not sure what direction this is
	KBBTN_DPAD_DOWN  = 0x800, // not sure what direction this is

	KBBTN_A = 0x1000,
	KBBTN_B = 0x2000,
	KBBTN_X = 0x4000,
	KBBTN_Y = 0x8000,

	KBBTN_Z = 0x10000,
	KBBTN_L = 0x20000,
	KBBTN_R = 0x40000,

	KBBTN_MSTICK_UP    = 0x80000,
	KBBTN_MSTICK_RIGHT = 0x100000,
	KBBTN_MSTICK_DOWN  = 0x200000,
	KBBTN_MSTICK_LEFT  = 0x400000,

	KBBTN_UNK24 = 0x800000,

	KBBTN_START = 0x1000000,

	KBBTN_UNK26 = 0x2000000,
	KBBTN_UNK27 = 0x4000000,
	KBBTN_UNK28 = 0x8000000,
	KBBTN_UNK29 = 0x10000000,
	KBBTN_UNK30 = 0x20000000,
	KBBTN_UNK31 = 0x40000000,
	KBBTN_UNK32 = 0x80000000,
};

/**
 * @brief TODO
 */
struct Controller : public Node {

	Controller()
	    : Node("<Controller>")
	{
		reset(1);
	}

	Controller(int p1)
	    : Node("<Controller>")
	{
		reset(p1);
	}

	void reset(u32);
	void updateCont(u32 keyStatus);
	void update();
	f32 getMainStickX();
	f32 getMainStickY();
	f32 getSubStickX();
	f32 getSubStickY();

	// use KeyboardButtons enum
	inline bool isCurrentInput(u32 button) { return mCurrentInput & button; }
	inline bool isReleased(u32 button) { return mInputReleased & button; }
	inline bool isPressed(u32 button) { return mInputPressed & button; }

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
