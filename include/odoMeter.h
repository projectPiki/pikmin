#ifndef _ODOMETER_H
#define _ODOMETER_H
#include "types.h"
#include "Vector3f.h"

struct OdoMeter {
	float A; // _00
	float B; // _04
	float C; // _08
	float D; // _0C

	OdoMeter();
	void start(float argA, float argB);
	bool moving(Vector3f& argA, Vector3f& argB);
};

#endif
