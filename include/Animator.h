#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#include "types.h"

/**
 * @brief TODO
 */
struct AnimContext {
	AnimContext();

	// _0C = VTBL
	int mFrameCount;   // _00
	f32 mCurrentFrame; // _04
	f32 _08;           // _08

	virtual void animate(f32 time); // _08
};

/**
 * @brief TODO
 */
struct Animator {
	void startAnim(int, int, int, int);
	void updateContext();

	// _30 = VTBL
	u8 _00[0x18]; // _00, unknown
	int _18;      // _18
	int _1C;      // _1C
	int _20;      // _20
	int _24;      // _24
	u32 _28;      // _28, unknown
	f32 _2C;      // _2C

	virtual void changeContext(AnimContext*); // _08
	virtual void animate(f32);                // _0C
	virtual void finishOneShot();             // _10
	virtual void finishLoop();                // _14
};

/**
 * @brief TODO
 */
struct AnimMgr {
};

#endif
