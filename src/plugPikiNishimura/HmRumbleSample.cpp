#include "Dolphin/pad.h"
#include "RumbleMgr.h"

/**
 * @todo: Documentation
 */
RumbleSample::RumbleSample(int chan)
{
	mCurrentIntensity = 0.0f;
	mTotalIntensity   = 0.0f;
	mChannel          = chan;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
void RumbleSample::init()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void RumbleSample::simpleStop()
{
	PADStopMotorHard(mChannel);
}

/**
 * @todo: Documentation
 */
void RumbleSample::simpleStart(f32 intensity)
{
	mCurrentIntensity = intensity;
	mTotalIntensity += mCurrentIntensity;
	if (mCurrentIntensity <= 0.0f) {
		PADStopMotorHard(mChannel);

	} else if (mTotalIntensity < 1.0f) {
		PADStopMotor(mChannel);

	} else {
		mTotalIntensity -= 1.0f;
		PADStartMotor(mChannel);
	}
}
