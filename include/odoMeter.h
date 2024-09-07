#ifndef _ODOMETER_H
#define _ODOMETER_H

#include "types.h"
#include "Vector.h"

/**
 * @brief TODO
 */
struct OdoMeter {
	OdoMeter();

	void start(f32 argA, f32 argB);
	bool moving(Vector3f& argA, Vector3f& argB);

	inline void unknown1()
	{
		if (_04 > 0.0f) {
			_04 -= gsys->mDeltaTime;
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

	// TODO: figure out what these actually are
	f32 _00; // _00
	f32 _04; // _04
	f32 _08; // _08
	f32 _0C; // _0C
};

#endif
