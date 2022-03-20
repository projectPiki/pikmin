#ifndef _ODOMETER_H
#define _ODOMETER_H
#include "types.h"
#include "Vector3f.h"
#include "math.h"

struct OdoMeter { // TODO: figure out what these actually are
	float A;      // _00
	float B;      // _04
	float C;      // _08
	float D;      // _0C

	OdoMeter();
	void start(float argA, float argB);
	bool moving(Vector3f& argA, Vector3f& argB);
	inline void odoGsys(void) // made up for OdoMeter::moving
	{
		if (B > 0.0f) {
			B -= gsys->m_28C;
		}
	}
	inline bool odoRet(void) // made up for OdoMeter::moving
	{
		if (B <= 0.0f) {
			if (A < C) {
				A = 0.0f;
				return false;
			}
			B = D;
			A = 0.0f;
		}
		return true;
	}
};

#endif
