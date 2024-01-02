#ifndef _HMRUMBLE_H
#define _HMRUMBLE_H

#include "types.h"

typedef class RumbleSample;

extern "C" void PADControlMotor(int, int);

class RumbleSample {
	f32 _00; // _00
	f32 _04; // _04
	int _08; // _08

	RumbleSample(int);
	void simpleStop();
	void simpleStart(f32);
};

#endif
