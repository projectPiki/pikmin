#include "types.h"
#include "system.h"
#include "odoMeter.h"
/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

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
 * TODO
 */
bool OdoMeter::moving(Vector3f& startPosition, Vector3f& endPosition)
{
	Vector3f direction;
	f32 dummy[4]; // Match stack allocation

	updateTimer();

	if (mTotalDistance < 100.0f) {
#ifdef __DECOMP_NON_MATCHING
		Vector3f vec;
		vec.sub2(argA, argB);
		f32 distance = vec.length();
#else
		direction.y  = Vector3f_diffY(startPosition, endPosition);
		direction.x  = Vector3f_diffX(startPosition, endPosition);
		direction.z  = Vector3f_diffZ(startPosition, endPosition);
		f32 distance = sqrtf(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
#endif
		mTotalDistance += distance;
	}

	return isMovementComplete();
}
