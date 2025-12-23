#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Node.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note I think these are more accurate based on Minty's notes.
 */
enum KeyboardButtons {
	KBBTN_NONE = 0x0,
	KBBTN_ANY  = 0xffffffff,

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

	KBBTN_ANY_BUTTON = KBBTN_A | KBBTN_B | KBBTN_X | KBBTN_Y | KBBTN_Z | KBBTN_L | KBBTN_R | KBBTN_START,
};

/**
 * @brief TODO
 */
struct Controller : public Node {

	// I really wanted to make `int playerNum = 1` since it (almost) always is, but guess what?  SOMEHOW, THAT BREAKS MATCHING!  Yeah,
	// a DEFAULT ARGUMENT tips the inlining score enough to stop the `Node` base class constructor from inlining.  This compiler, man.
	Controller(int playerNum)
	    : Node("<Controller>")
	{
		initialise(playerNum);
	}

	virtual void update(); // _10

	void reset(u32 playerNum);
	void updateCont(u32 keyStatus);
	f32 getMainStickX();
	f32 getMainStickY();
	f32 getSubStickX();
	f32 getSubStickY();

	void initialise(u32 playerNum) { reset(playerNum); }

	// use KeyboardButtons enum - could maybe rename these from DLL names
	bool keyDown(u32 button) { return (mCurrentInput & button) != 0; }
	bool keyUp(u32 button) { return (mCurrentInput & button) == 0; }
	bool keyClick(u32 button) { return (mInputPressed & button) != 0; }
	bool keyDoubleClick(u32 button) { return (mInputDoublePressed & button) != 0; }
	bool keyUnClick(u32 button) { return (mInputReleased & button) != 0; }

	// _00     = VTBL
	// _00-_20 = Node
	u32 mCurrentInput;        // _20
	u32 mPrevInput;           // _24
	u32 mInputPressed;        // _28
	u32 mInputReleased;       // _2C
	u32 mInputDoublePressed;  // _30
	u32 mDoublePressMask;     // _34
	u32 mPlayerNum;           // _38, 1 => use controller port 0, etc
	u32 _3C;                  // _3C
	u32 mInputDelay;          // _40
	bool mIsControllerFrozen; // _44
	s8 mMainStickX;           // _45
	s8 mMainStickY;           // _46
	s8 mSubStickX;            // _47
	s8 mSubStickY;            // _48
	u8 mAnalogA;              // _49
	u8 mAnalogB;              // _4A
	u8 mTriggerL;             // _4B
	u8 mTriggerR;             // _4C
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
