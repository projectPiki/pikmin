#ifndef _WORLDCLOCK_H
#define _WORLDCLOCK_H

#include "types.h"

/// How many total in-game hours are there in a "full" in-game day - not playable hours!
#define HOURS_IN_DAY (24)

/// Time of day to set the "Day 1" tutorial to (mostly for lighting) - 2:48pm!
#define TUTORIAL_TIME_OF_DAY (14.8f)

/**
 * @brief Global managing structure for in-game-time calculations.
 *
 * @note Size: 0x2C.
 */
struct WorldClock {

	void setTime(f32 timeOfDay);
	void update(f32 playRate);

	// unused/inlined:

	void setClockSpd(f32 minsPerGameDay);
	void reset(f32 minsPerGameDay);
	f32 age(f32 referenceDay);

	f32 mRealSecsPerGameHour; ///< _00, how many real life seconds each in-game hour lasts.
	f32 mHoursInDay;          ///< _04, how many in-game hours are in an in-game day.
	f32 mRealSecsPerGameDay;  ///< _08, how many real life seconds each "full" (24hr) in-game day lasts.
	u8 _0C[0x4];              ///< _0C, unknown/unused.
	f32 mPrevTimeOfDay;       ///< _10, last stored in-game time of day, for delta calculations.
	f32 mRealSecsIntoHour;    ///< _14, how many real seconds have passed since the last in-game hour change.
	f32 mTimeOfDay;           ///< _18, in-game time, as a float - 7:30am would be a value of 7.5f.
	f32 mDeltaTimeOfDay;      ///< _1C, difference between current time and last updated time.
	int mCurrentGameHour;     ///< _20, current in-game hour (rounded down).
	int mCurrentDay;          ///< _24, current in-game day.
	int mCurrentGameMinute;   ///< _28, current in-game minute (rounded down).
};

#endif
