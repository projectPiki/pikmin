#ifndef _PELLETVIEW_H
#define _PELLETVIEW_H

#include "Vector.h"
#include "types.h"

struct Pellet;
struct Graphics;
struct Matrix4f;

/**
 * @brief TODO
 */
struct PelletView {
	inline PelletView()
	    : mPellet(nullptr)
	{
	}

	virtual void viewInit() { }                                            // _08 (weak)
	virtual void viewKill()                     = 0;                       // _0C
	virtual void viewDraw(Graphics&, Matrix4f&) = 0;                       // _10
	virtual void viewStartTrembleMotion(f32) { }                           // _14 (weak)
	virtual void viewStartExplodeMotion(f32) { }                           // _18 (weak)
	virtual void viewSetMotionSpeed(f32) { }                               // _1C (weak)
	virtual void viewFinishMotion() { }                                    // _20 (weak)
	virtual void viewDoAnimation() { }                                     // _24 (weak)
	virtual f32 viewGetBottomRadius() = 0;                                 // _28
	virtual f32 viewGetHeight()       = 0;                                 // _2C
	virtual Vector3f viewGetScale() { return Vector3f(1.0f, 1.0f, 1.0f); } // _30 (weak)

	void becomePellet(u32, Vector3f&, f32);

	// _00 = VTBL
	Pellet* mPellet; // _04
};

#endif
