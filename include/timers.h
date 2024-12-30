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
	u32 _04;          // _04
	u32 _08;          // _08
	u32 _0C;          // _0C
	u32 _10;          // _10
	u32 _14;          // _14
	u32 _18;          // _18
	u32 _1C;          // _1C
	u8 _20;           // _20
	u32 _24;          // _24
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

	TimerInf* mTimerInf; // _00
	s32 mFrameCount;     // _04
	u32 _08;             // _08
};

#endif
