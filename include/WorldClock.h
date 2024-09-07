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

	// TODO: members
};

#endif
