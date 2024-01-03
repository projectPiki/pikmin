#ifndef _PELLETVIEW_H
#define _PELLETVIEW_H

#include "types.h"

/**
 * @brief TODO
 */
struct PelletView {
	inline PelletView()
	    : _04(0)
	{
	}

	virtual void viewInit();                                       // _08 (weak)
	virtual void viewKill()                                   = 0; // _0C
	virtual void viewDraw(struct Graphics&, struct Matrix4f&) = 0; // _10
	virtual void viewStartTrembleMotion(f32);                      // _14 (weak)
	virtual void viewStartExplodeMotion(f32);                      // _18 (weak)
	virtual void viewSetMotionSpeed(f32);                          // _1C (weak)
	virtual void viewFinishMotion();                               // _20 (weak)
	virtual void viewDoAnimation();                                // _24 (weak)
	virtual void viewGetBottomRadius() = 0;                        // _28
	virtual void viewGetHeight()       = 0;                        // _2C
	virtual void viewGetScale();                                   // _30 (weak)

	void becomePellet(u32, struct Vector3f&, f32);

	// _00 = VTBL
	u32 _04; // _04, unknown - probably Pellet* mPellet?
};

#endif
