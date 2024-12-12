#ifndef _WORLDCLOCK_H
#define _WORLDCLOCK_H

#include "types.h"
#include "CoreNode.h"
#include "Graphics.h"
#include "Matrix4f.h"
#include "Animator.h"

/**
 * @brief TODO
 */
struct WorldClock {

	void setTime(f32);
	void update(f32);

	// unused/inlined:
	void setClockSpd(f32);
	void reset(f32);
	void age(f32);

	f32 _00;            // _00
	u8 _04[0x10 - 0x4]; // _04, unknown
	f32 _10;            // _10
	f32 _14;            // _14
	f32 _18;            // _18
	u8 _1C[0x4];        // _1C, unknown
	int _20;            // _20
	u8 _24[0x4];        // _24, unknown
	int _28;            // _28
};

#endif
