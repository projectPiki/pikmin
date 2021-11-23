#include "types.h"
#ifndef _HMRUMBLE_H
#define _HMRUMBLE_H
typedef class RumbleSample;

extern "C" void PADControlMotor(int, int);

class RumbleSample {
	float _00;	// _00
	float _04;	// _04
	int _08;	// _08

	RumbleSample(int);
	void simpleStop();
	void simpleStart(f32);
};

#endif
