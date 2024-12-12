#include "RumbleMgr.h"
#include "Dolphin/pad.h"

/*
 * --INFO--
 * Address:	8017D680
 * Size:	000014
 */
RumbleSample::RumbleSample(int chan)
{
	mCurrentIntensity = 0.0f;
	mTotalIntensity   = 0.0f;
	mChannel          = chan;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void RumbleSample::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017D694
 * Size:	000028
 */
void RumbleSample::simpleStop() { PADStopMotorHard(mChannel); }

/*
 * --INFO--
 * Address:	8017D6BC
 * Size:	000088
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
