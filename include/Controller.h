#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "types.h"
#include "Node.h"

/**
 * @brief TODO
 */
struct Controller : public Node {
	void reset(u32);
	void updateCont(u32);
	void update();
	f32 getMainStickX();
	f32 getMainStickY();
	f32 getSubStickX();
	f32 getSubStickY();

	// _00     = VTBL
	// _00-_20 = Node

	// THIS IS NODE!!! WHY IS IT FAILING BUILD IF I ADD THE MEMBER TO IT?
	s32 _14; // _14
	s32 _18; // _18
	s32 _1C; // _1C

	u32 _20;        // _20
	u32 mPrevInput; // _24
	u32 _28;        // _28
	u32 _2C;        // _2C
	u32 _30;        // _30
	u32 _34;        // _34
	u32 _38;        // _38
	u32 _3C;        // _3C
	u32 _40;        // _40
	bool _44;       // _44
	s8 _45;         // _45
	s8 _46;         // _46
	s8 _47;         // _47
	s8 _48;         // _48
	s8 _49;         // _49
	s8 _4A;         // _4A
	s8 _4B;         // _4B
	s8 _4C;         // _4C
};

/**
 * @brief TODO
 */
struct ControllerMgr {
	virtual void keyDown(int); // _08

	void update();
	void init();
	void updateController(Controller*);
};

#endif // CONTROLLER_H
