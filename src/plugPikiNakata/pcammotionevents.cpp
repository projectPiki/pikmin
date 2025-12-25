#include "DebugLog.h"
#include "Pcam/Camera.h"
#include "Pcam/MotionEvents.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("pcammotionevents")

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void PcamLongVibrationEvent::makePcamLongVibrationEvent(f32 aDuration, f32 bDuration, f32 intensity, f32 frequency)
{
	NVector3f NRef dir = NVector3f(mCamera->getViewpoint(), mCamera->getWatchpoint());
	dir.normalize();
	NOrientation NRef orient = NOrientation(dir);
	orient.normalize();
	mEventA->makeVibrationEvent(aDuration, &mPostureIO, orient.getUp(), intensity, frequency, 0.0f);
	mEventB->makeVibrationEvent(bDuration, &mPostureIO, orient.getUp(), intensity, frequency, -frequency / bDuration);
}

/**
 * @TODO: Documentation
 */
PcamVibrationEvent::PcamVibrationEvent(PcamCamera* camera)
{
	mCamera = camera;
	mPostureIO.construct(mCamera);
	mVibrationDuration  = 0.8f;
	mVibrationAmplitude = 0.2f;
	mVibrationFrequency = 16.0f;
}

/**
 * @TODO: Documentation
 */
void PcamVibrationEvent::makePcamVibrationEvent()
{
	NVector3f NRef dir = NVector3f(mCamera->getViewpoint(), mCamera->getWatchpoint());
	dir.normalize();
	NOrientation NRef orient = NOrientation(dir);
	orient.normalize();
	makeVibrationEvent(mVibrationDuration, &mPostureIO, orient.getUp(), mVibrationAmplitude, mVibrationFrequency,
	                   -mVibrationFrequency / mVibrationDuration);
}

/**
 * @TODO: Documentation
 */
PcamDamageEvent::PcamDamageEvent(PcamCamera* camera)
{
	mCamera = camera;
	mPostureIO.construct(mCamera);
	mVibrationDuration  = 0.8f;
	mVibrationAmplitude = 0.2f;
	mVibrationFrequency = 16.0f;
}

/**
 * @TODO: Documentation
 */
void PcamDamageEvent::makePcamDamageEvent()
{
	NVector3f NRef dir = NVector3f(mCamera->getViewpoint(), mCamera->getWatchpoint());
	dir.normalize();
	makeVibrationEvent(mVibrationDuration, &mPostureIO, dir, mVibrationAmplitude, mVibrationFrequency,
	                   -mVibrationFrequency / mVibrationDuration);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000064
 */
PcamRandomMoveEvent::PcamRandomMoveEvent(PcamCamera* camera)
    : PeveEvent(0)
{
	mCamera    = camera;
	_10        = 1.0f;
	mMoveScale = 1.0f;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014
 */
void PcamRandomMoveEvent::makePcamRandomMoveEvent()
{
	mTimeCondition.setPeriod(_10);
	makeEvent(&mTimeCondition);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void PcamSideVibrationEvent::makePcamSideVibrationEvent()
{
	mTimeCondition.setPeriod(mEventPeriod);
	makeEvent(&mTimeCondition);
	mVibFunction.makeVibrationFunction(0.0f, mVibrationMagnitude, 1.0f);
	mPolyFunction.mData.mValues[0] = mMaxRotation;
	mPolyFunction.mData.mValues[1] = -mMaxRotation / mEventPeriod;
}

/**
 * @TODO: Documentation
 */
void PcamSideVibrationEvent::update()
{
	PeveEvent::update();
	f32 time                = mTimeCondition.getTime();
	mCamera->mRotationAngle = mPolyFunction.getValue(time) * mVibFunction.getValue(time);
}

/**
 * @TODO: Documentation
 */
void PcamSideVibrationEvent::finish()
{
	mCamera->mRotationAngle = 0.0f;
}
