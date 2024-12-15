#ifndef _WORLDCLOCK_H
#define _WORLDCLOCK_H

#include "types.h"

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

	f32 mTimeScale;        // _00
	f32 _04;               // _04
	f32 _08;               // _08
	u8 _0C[0x4];           // _0C, unknown
	f32 mLastRecordedTime; // _10
	f32 mFractionalTime;   // _14
	f32 mTotalTime;        // _18
	u8 _1C[0x4];           // _1C, unknown
	int mCurrentTime;      // _20
	int _24;               // _24, unknown, same as _30 in CreatureInf
	int mMinutes;          // _28
};

#endif
