#ifndef _TIMERS_H
#define _TIMERS_H

#include "types.h"
#include "VersionGroups.h"

struct Graphics;
struct Font;

/*
 * @note Size: 0x28
 */
struct TimerInf {
	TimerInf(char*);

	char* mTimerName; // _00
	f32 mStartTime;   // _04
	f32 mDuration;    // _08
	f32 mAverageTime; // _0C
	f32 mPeakTime;    // _10
	f32 mDecayTime;   // _14
	u32 mSampleTime;  // _18
	u32 _1C;          // _1C
	u8 _20;           // _20
	TimerInf* mNext;  // _24
};

struct Timers {
	Timers()
	{
		mTimerInf   = nullptr;
		_08         = 0;
		mFrameCount = -1;
	}

	void reset();
	void newFrame();
	void _start(char*, bool);
	void _stop(char*);
	void showTimes();
	void draw(Graphics&, Font*);

	void start(char* name, bool p2)
	{
#if defined(VERSION_PIKIDEMO)
		_start(name, p2);
#endif
	}

	void stop(char* name)
	{
#if defined(VERSION_PIKIDEMO)
		_stop(name);
#endif
	}

	TimerInf* mTimerInf; // _00
	s32 mFrameCount;     // _04
	u32 _08;             // _08
};

// For some reason, certain functions cannot have known timers added to them without messing up matching.  At the same time, other functions
// require known timers to be added in order to match, so it's not like they were *all* originally behind a macro.  This macro aims to solve
// the first case (timers that cannot exist in retail but did exist in demo versions), but one should avoid these macros whenever possible.
#if !defined(DEVELOP) && (defined(VERSION_GPIE01_00) || defined(VERSION_GPIE01_01) || defined(VERSION_GPIP01_00))
#define MATCHING_START_TIMER(name, p2) (void)0
#define MATCHING_STOP_TIMER(name)      (void)0
#else
#define MATCHING_START_TIMER(name, p2) gsys->mTimer->start(name, p2)
#define MATCHING_STOP_TIMER(name)      gsys->mTimer->stop(name)
#endif

#endif
