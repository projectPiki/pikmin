#ifndef _ODOMETER_H
#define _ODOMETER_H

#include "types.h"
#include "Vector3f.h"

struct OdoMeter { // TODO: figure out what these actually are
	float _00;    // _00
	float _04;    // _04
	float _08;    // _08
	float _0C;    // _0C

	OdoMeter();
	void start(float argA, float argB);
	bool moving(Vector3f& argA, Vector3f& argB);

	inline void unknown1()
	{
		if (_04 > 0.0f) {
			_04 -= gsys->m_28C;
		}
	}

	inline bool unknown2()
	{
		if (_04 <= 0.0f) {
			if (_00 < _08) {
				_00 = 0.0f;
				return false;
			}
			_04 = _0C;
			_00 = 0.0f;
		}
		return true;
	}
};

#endif
