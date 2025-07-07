#include "OdoMeter.h"

#include "DebugLog.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("odoMeter");

/*
 * --INFO--
 * Address:	800CD804
 * Size:	000010
 */
OdoMeter::OdoMeter()
{
	mTotalDistance = 0.0f;
	mRemainingTime = 0.0f;
}

/*
 * --INFO--
 * Address:	800CD814
 * Size:	000018
 */
void OdoMeter::start(f32 startTime, f32 maxDistance)
{
	mResetTimeValue     = startTime;
	mRemainingTime      = startTime;
	mMinAllowedDistance = maxDistance;
	mTotalDistance      = 0.0f;
}
/*
 * --INFO--
 * Address:	800CD82C
 * Size:	000124
 */
bool OdoMeter::moving(Vector3f& startPosition, Vector3f& endPosition)
{
	if (mRemainingTime > 0.0f) {
		mRemainingTime -= gsys->getFrameTime();
	}

	if (mTotalDistance < 100.0f) {
		Vector3f positionDifference = startPosition - endPosition;
		f32 distance                = positionDifference.length();
		mTotalDistance += distance;
	}

	if (mRemainingTime <= 0.0f) {
		PRINT("------ timer up -------- : trip %f\n", mTotalDistance);

		if (mTotalDistance < mMinAllowedDistance) {
			PRINT("zannen !\n");
			mTotalDistance = 0.0f;
			return false;
		}

		PRINT("re-calc again\n");
		mRemainingTime = mResetTimeValue;
		mTotalDistance = 0.0f;
	}

	return true;
}
