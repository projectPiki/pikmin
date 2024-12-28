#ifndef _TIMERS_H
#define _TIMERS_H

#include "types.h"

struct Graphics;
struct Font;

struct Timers {

	void reset();
	void newFrame();
	void _start(char*, bool);
	void _stop(char*);
	void showTimes();
	void draw(Graphics&, Font*);

	/*TimerInf* mTimers <-- instead of mWord0*/
	u32 _00;         // _00
	u32 mFrameCount; // _04
	u32 _08;         // _08
};

#endif
