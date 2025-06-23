#ifndef _TIMERS_H
#define _TIMERS_H

#include "types.h"

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
#if defined(VERSION_G98E01_PIKIDEMO)
		_start(name, p2);
#endif
	}

	void stop(char* name)
	{
#if defined(VERSION_G98E01_PIKIDEMO)
		_stop(name);
#endif
	}

	TimerInf* mTimerInf; // _00
	s32 mFrameCount;     // _04
	u32 _08;             // _08
};

#endif
