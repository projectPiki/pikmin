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
	f32 age(f32);

	f32 mTimeScale;        // _00
	f32 mHoursInDay;       // _04
	f32 mTicksPerHour;     // _08
	u8 _0C[0x4];           // _0C, unknown
	f32 mLastRecordedTime; // _10
	f32 mFractionalTime;   // _14
	f32 mTimeOfDay;        // _18
	f32 _1C;               // _1C
	int mCurrentTime;      // _20
	int mCurrentDay;       // _24
	int mMinutes;          // _28
};

#endif
