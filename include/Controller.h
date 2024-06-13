#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "types.h"
#include "Node.h"

/**
 * @brief TODO
 */
struct Controller : public Node {
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
