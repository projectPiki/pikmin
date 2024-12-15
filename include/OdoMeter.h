#ifndef _ODOMETER_H
#define _ODOMETER_H

#include "types.h"
#include "Vector.h"
#include "system.h"

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct OdoMeter {
	OdoMeter();

	void start(f32 startTime, f32 maxDistance);
	bool moving(Vector3f& start, Vector3f& target);

	inline void updateTimer()
	{
		if (mRemainingTime > 0.0f) {
			mRemainingTime -= gsys->mDeltaTime;
		}
	}

	inline bool isMovementComplete()
	{
		// If the time has run out
		if (mRemainingTime <= 0.0f) {
			// And we haven't surpassed the threshold
			if (mTotalDistance < mMinAllowedDistance) {
				mTotalDistance = 0.0f;
				return false;
			}

			mRemainingTime = mResetTimeValue;
			mTotalDistance = 0.0f;
		}

		return true;
	}

	f32 mTotalDistance;      // _00
	f32 mRemainingTime;      // _04
	f32 mMinAllowedDistance; // _08
	f32 mResetTimeValue;     // _0C
};

#endif
