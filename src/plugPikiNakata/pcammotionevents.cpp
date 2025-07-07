#include "DebugLog.h"
#include "Pcam/Camera.h"
#include "Pcam/MotionEvents.h"
#include "sysNew.h"

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
DEFINE_PRINT("pcammotionevents")

/*
 * --INFO--
 * Address:	801241A8
 * Size:	0000CC
 */
PcamLongVibrationEvent::PcamLongVibrationEvent(PcamCamera* camera)
    : PeveSerialEvent(2)
{
	mCamera = camera;
	mEventA = new PeveVibrationEvent();
	mEventB = new PeveVibrationEvent();
	addChild(mEventA);
	addChild(mEventB);
	mPostureIO.construct(mCamera);
}

/*
 * --INFO--
 * Address:	80124274
 * Size:	0000D8
 */
void PcamLongVibrationEvent::makePcamLongVibrationEvent(f32 p1, f32 p2, f32 p3, f32 p4)
{
	NVector3f& dir = NVector3f(mCamera->getViewpoint(), mCamera->getWatchpoint());
	dir.normalize();
	NOrientation& orient = NOrientation(dir);
	orient.normalize();
	mEventA->makeVibrationEvent(p1, &mPostureIO, orient.getUp(), p3, p4, 0.0f);
	mEventB->makeVibrationEvent(p2, &mPostureIO, orient.getUp(), p3, p4, -p4 / p2);
}

/*
 * --INFO--
 * Address:	8012434C
 * Size:	000078
 */
PcamVibrationEvent::PcamVibrationEvent(PcamCamera* camera)
{
	mCamera = camera;
	mPostureIO.construct(mCamera);
	mVibrationDuration  = 0.8f;
	mVibrationAmplitude = 0.2f;
	mVibrationFrequency = 16.0f;
}

/*
 * --INFO--
 * Address:	801243C4
 * Size:	000084
 */
void PcamVibrationEvent::makePcamVibrationEvent()
{
	NVector3f& dir = NVector3f(mCamera->getViewpoint(), mCamera->getWatchpoint());
	dir.normalize();
	NOrientation& orient = NOrientation(dir);
	orient.normalize();
	makeVibrationEvent(mVibrationDuration, &mPostureIO, orient.getUp(), mVibrationAmplitude, mVibrationFrequency,
	                   -mVibrationFrequency / mVibrationDuration);
}

/*
 * --INFO--
 * Address:	80124448
 * Size:	000078
 */
PcamDamageEvent::PcamDamageEvent(PcamCamera* camera)
{
	mCamera = camera;
	mPostureIO.construct(mCamera);
	mVibrationDuration  = 0.8f;
	mVibrationAmplitude = 0.2f;
	mVibrationFrequency = 16.0f;
}

/*
 * --INFO--
 * Address:	801244C0
 * Size:	000070
 */
void PcamDamageEvent::makePcamDamageEvent()
{
	NVector3f& dir = NVector3f(mCamera->getViewpoint(), mCamera->getWatchpoint());
	dir.normalize();
	makeVibrationEvent(mVibrationDuration, &mPostureIO, dir, mVibrationAmplitude, mVibrationFrequency,
	                   -mVibrationFrequency / mVibrationDuration);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
PcamRandomMoveEvent::PcamRandomMoveEvent(PcamCamera* camera)
    : PeveEvent(0)
{
	mCamera    = camera;
	_10        = 1.0f;
	mMoveScale = 1.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void PcamRandomMoveEvent::makePcamRandomMoveEvent()
{
	mTimeCondition.setPeriod(_10);
	makeEvent(&mTimeCondition);
}

/*
 * --INFO--
 * Address:	80124530
 * Size:	000290
 */
void PcamRandomMoveEvent::update()
{
	PeveEvent::update();
	NVector3f offset;
	offset.x = NMathF::rangeRandom(-1.0f, 1.0f);
	offset.y = NMathF::rangeRandom(-1.0f, 1.0f);
	offset.z = NMathF::rangeRandom(-1.0f, 1.0f);
	offset.scale(mMoveScale);
	mCamera->getViewpoint().add(offset);

	offset.x = NMathF::rangeRandom(-1.0f, 1.0f);
	offset.y = NMathF::rangeRandom(-1.0f, 1.0f);
	offset.z = NMathF::rangeRandom(-1.0f, 1.0f);
	offset.scale(mMoveScale);
	mCamera->getWatchpoint().add(offset);
}

/*
 * --INFO--
 * Address:	801247C0
 * Size:	0000C4
 */
PcamSideVibrationEvent::PcamSideVibrationEvent(PcamCamera* camera)
    : PeveEvent(0)
{
	mCamera = camera;

	mPolyFunction.construct(new f32[2], 2);
	mTimeCondition.construct(0.0f);
	mEventPeriod        = 0.6f;
	mVibrationMagnitude = 0.2f;
	mMaxRotation        = NMathF::pi / 8.0f;
}

/*
 * --INFO--
 * Address:	80124884
 * Size:	000070
 */
void PcamSideVibrationEvent::makePcamSideVibrationEvent()
{
	mTimeCondition.setPeriod(mEventPeriod);
	makeEvent(&mTimeCondition);
	mVibFunction.makeVibrationFunction(0.0f, mVibrationMagnitude, 1.0f);
	mPolyFunction.mData.mValues[0] = mMaxRotation;
	mPolyFunction.mData.mValues[1] = -mMaxRotation / mEventPeriod;
}

/*
 * --INFO--
 * Address:	801248F4
 * Size:	000098
 */
void PcamSideVibrationEvent::update()
{
	PeveEvent::update();
	f32 time                = mTimeCondition.getTime();
	mCamera->mRotationAngle = mPolyFunction.getValue(time) * mVibFunction.getValue(time);
}

/*
 * --INFO--
 * Address:	8012498C
 * Size:	000010
 */
void PcamSideVibrationEvent::finish()
{
	mCamera->mRotationAngle = 0.0f;
}
