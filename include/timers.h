#ifndef _TIMERS_H
#define _TIMERS_H

#include "types.h"

struct Graphics;
struct Font;

struct Timers {
	/*TimerInf* mTimers <-- instead of mWord0*/
	u32 mWord0;
	u32 mFrameCount;
	u32 mWord8;

	void reset();
	void newFrame();
	void _start(char*, bool);
	void _stop(char*);
	void showTimes();
	void draw(Graphics&, Font*);
};

#endif
