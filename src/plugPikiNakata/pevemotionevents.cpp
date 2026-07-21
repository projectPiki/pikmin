#include "DebugLog.h"
#include "Peve/MotionEvents.h"
#include "nlib/Geometry.h"
#include "sysNew.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("pevemotionevents")

/**
 * @todo: Documentation
 * @note UNUSED Size: 000054
 */
PeveWaitEvent::PeveWaitEvent()
    : PeveEvent(0)
{
	mTimeCondition.construct(1.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
void PeveWaitEvent::makeWaitEvent(f32 waitTime)
{
	mTimeCondition.setPeriod(waitTime);
	makeEvent(&mTimeCondition);
}

/**
 * @todo: Documentation
 */
PeveAccelerationEvent::PeveAccelerationEvent()
    : PeveEvent(0)
{
}

/**
 * @todo: Documentation
 */
void PeveAccelerationEvent::makeAccelerationEvent(PeveCondition* cond, NVector3fIO* posIO, NVector3fIO* velIO, NVector3fIO* accelIO)
{
	makeEvent(cond);
	mPositionIO = posIO;
	mVelocityIO = velIO;
	mAccelIO    = accelIO;
}

/**
 * @todo: Documentation
 */
void PeveAccelerationEvent::update()
{
	PeveEvent::update();
	NVector3f NRef pos   = NVector3f();
	NVector3f NRef vel   = NVector3f();
	NVector3f NRef accel = NVector3f();

	mPositionIO->output(pos);
	mVelocityIO->output(vel);
	mAccelIO->output(accel);

	f32 fTime = NSystem::getFrameTime();
	Vector3f posChange(vel);
	posChange.scale(fTime);
	Vector3f velChange(accel);
	velChange.scale(fTime);

	pos.add(posChange);
	vel.add(velChange);

	mPositionIO->input(pos);
	mVelocityIO->input(vel);
}

/**
 * @todo: Documentation
 */
PeveParabolaEvent::PeveParabolaEvent()
{
}

/**
 * @todo: Documentation
 */
void PeveParabolaEvent::makeParabolaEvent(PeveCondition* cond, NVector3fIO* positionIO, NVector3f& initialVelocity, f32 maxLength,
                                          f32 gravityStrength)
{
	mClampedVelocityIO.setMaxLength(maxLength);
	mClampedVelocityIO.input(initialVelocity);

	NVector3f NRef gravityAccel = NVector3f(0.0f, -gravityStrength, 0.0f);
	mGravityAccelIO.input(gravityAccel);
	makeAccelerationEvent(cond, positionIO, &mClampedVelocityIO, &mGravityAccelIO);
}

/**
 * @todo: Documentation
 */
void PeveHorizontalSinWaveEvent::makeHorizontalSinWaveEvent(PeveCondition* cond, NVector3fIO* positionIO, NVector3f linearVelocity,
                                                            f32 offset, f32 amplitude, f32 startTheta, f32 angularVelocity)
{
	makeEvent(cond);
	mPositionIO = positionIO;
	mLinearVelocity.input(linearVelocity);
	mOffset          = offset;
	mAmplitude       = amplitude;
	mStartingTheta   = startTheta;
	mAngularVelocity = angularVelocity;
}

/**
 * @todo: Documentation
 */
void PeveHorizontalSinWaveEvent::reset()
{
	PeveEvent::reset();
	mTheta = mStartingTheta;
}

/**
 * @todo: Documentation
 */
void PeveHorizontalSinWaveEvent::update()
{
	PeveEvent::update();
	f32 fTime = NSystem::getFrameTime();
	f32 y     = mAmplitude * NMathF::sin(mTheta) + mOffset;
	mTheta += fTime * mAngularVelocity;

	Vector3f vec1(mLinearVelocity);
	vec1.scale(fTime);

	NVector3f vec2;
	mPositionIO->output(vec2);

	vec2.add(vec1);
	vec2.y = y;
	mPositionIO->input(vec2);
}

/**
 * @todo: Documentation
 */
PeveCircleMoveEvent::PeveCircleMoveEvent()
    : PeveEvent(0)
{
	mTimeCondition.construct(1.0f);
	mAngle = 0.0f;
}

/**
 * @todo: Documentation
 */
void PeveCircleMoveEvent::makeCircleMoveEvent(f32 timeLimit, NVector3fIO* positionIO, NVector3fIO* centerPositionIO, f32 positionLerpFactor,
                                              f32 radius, f32 heightOffset, f32 angularSpeed)
{
	mTimeCondition.setPeriod(timeLimit);
	makeEvent(&mTimeCondition);
	mPositionIO         = positionIO;
	mCenterPositionIO   = centerPositionIO;
	mPositionLerpFactor = positionLerpFactor;
	mRadius             = radius;
	mHeightOffset       = heightOffset;
	mAngularSpeed       = angularSpeed;
}

/**
 * @todo: Documentation
 */
void PeveCircleMoveEvent::reset()
{
	PeveEvent::reset();
	mAngle = calcAngle();
}

/**
 * @todo: Documentation
 */
void PeveCircleMoveEvent::update()
{
	PeveEvent::update();
	mAngle += mAngularSpeed * NSystem::getFrameTime();
	NVector3f vec1;
	mPositionIO->output(vec1);

	NVector3f pos;
	outputPosition(pos);
	pos.sub(vec1);
	pos.scale(mPositionLerpFactor);
	vec1.add(pos);
	mPositionIO->input(vec1);
}

/**
 * @todo: Documentation
 */
void PeveCircleMoveEvent::outputPosition(Vector3f& outPos)
{
	NVector3f vec1;
	mCenterPositionIO->output(vec1);
	outPos.set(mRadius * NMathF::sin(mAngle) + vec1.x, vec1.y + mHeightOffset, mRadius * NMathF::cos(mAngle) + vec1.z);
}

/**
 * @todo: Documentation
 */
f32 PeveCircleMoveEvent::calcAngle()
{
	NVector3f vec1;
	mCenterPositionIO->output(vec1);

	NVector3f vec2;
	mPositionIO->output(vec2);

	NVector3f vec3(vec1, vec2);
	return NMathF::atan2(vec3.x, vec3.z);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0 (Matching by size)
 */
PeveCircleMoveWatchEvent::PeveCircleMoveWatchEvent()
    : PeveParallelEvent(2)
{
	mCircleMoveEvent     = new PeveCircleMoveEvent();
	mHomingPositionEvent = new PeveHomingPositionEvent();
	addChild(mCircleMoveEvent);
	addChild(mHomingPositionEvent);
	mTimeCondition.construct(1.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058 (Matching by size)
 */
void PeveCircleMoveWatchEvent::makeCircleMoveWatchEvent(f32 timeLimit, NVector3fIO* circlePositionIO, NVector3fIO* homingPositionIO,
                                                        NVector3fIO* centerPositionIO, f32 positionLerpFactor, f32 homingRate, f32 radius,
                                                        f32 heightOffset, f32 angularSpeed)
{
	mCircleMoveEvent->makeCircleMoveEvent(timeLimit, circlePositionIO, centerPositionIO, positionLerpFactor, radius, heightOffset,
	                                      angularSpeed);
	mTimeCondition.setPeriod(timeLimit);
	mHomingPositionEvent->makeHomingPositionEvent(&mTimeCondition, homingPositionIO, centerPositionIO, homingRate);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000040 (Matching by size)
 */
PeveFunctionCurveEvent::PeveFunctionCurveEvent()
    : PeveEvent(0)
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
void PeveFunctionCurveEvent::makeFunctionCurveEvent(PeveCondition* cond, NVector3fIO* positionIO, NFunction3D* func, f32 startParam,
                                                    f32 paramStep, bool useFrameTimeScaledStep)
{
	makeEvent(cond);
	mPositionIO             = positionIO;
	mFunction               = func;
	mStartParam             = startParam;
	mParamStep              = paramStep;
	mUseFrameTimeScaledStep = useFrameTimeScaledStep;
}

/**
 * @todo: Documentation
 */
void PeveFunctionCurveEvent::reset()
{
	mCurrentParam = mStartParam;
}

/**
 * @todo: Documentation
 */
void PeveFunctionCurveEvent::update()
{
	PeveEvent::update();
	NVector3f NRef vec1 = NVector3f();
	mFunction->outputPosition(mCurrentParam, vec1);
	mPositionIO->input(vec1);
	if (mUseFrameTimeScaledStep) {
		mCurrentParam += mParamStep * NSystem::getFrameTime();
	} else {
		mCurrentParam += mParamStep;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000040
 */
PeveHomingPositionEvent::PeveHomingPositionEvent()
    : PeveEvent(0)
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000014
 */
void PeveHomingPositionEvent::makeHomingPositionEvent(PeveCondition* cond, NVector3fIO* positionIO, NVector3fIO* targetPositionIO,
                                                      f32 homingRate)
{
	makeEvent(cond);
	mPositionIO       = positionIO;
	mTargetPositionIO = targetPositionIO;
	mHomingRate       = homingRate;
}

/**
 * @todo: Documentation
 */
void PeveHomingPositionEvent::update()
{
	PeveEvent::update();
	NVector3f NRef vec1 = NVector3f();
	mPositionIO->output(vec1);

	NVector3f NRef vec2 = NVector3f();
	mTargetPositionIO->output(vec2);

	NVector3f NRef vec3 = NVector3f(vec1, vec2);
	vec3.scale(mHomingRate);
	vec1.add(vec3);
	mPositionIO->input(vec1);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000D0 (Matching by size)
 */
PeveHomingPostureEvent::PeveHomingPostureEvent()
    : PeveParallelEvent(2)
{
	mHomingPositionEvent1 = new PeveHomingPositionEvent();
	mHomingPositionEvent2 = new PeveHomingPositionEvent();
	addChild(mHomingPositionEvent1);
	addChild(mHomingPositionEvent2);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00002C (Matching by size)
 */
void PeveHomingPostureEvent::makeHomingPostureEvent(PeveCondition* condA, NVector3fIO* positionIOA, NVector3fIO* targetPositionIOA,
                                                    f32 homingRateA, PeveCondition* condB, NVector3fIO* positionIOB,
                                                    NVector3fIO* targetPositionIOB, f32 homingRateB)
{
	mHomingPositionEvent1->makeHomingPositionEvent(condA, positionIOA, targetPositionIOA, homingRateA);
	mHomingPositionEvent2->makeHomingPositionEvent(condB, positionIOB, targetPositionIOB, homingRateB);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
PeveInterpolationEvent::PeveInterpolationEvent(int size, NPool<SplineSegment>* splinePool)
    : PeveEvent(0)
{
	mSplineInterpolator = new SplineInterpolator(size, splinePool);
	mCurrentFrameIndex  = 0;
	mNextFrameParam     = 0;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00002C
 */
void PeveInterpolationEvent::makeInterpolationEvent(PeveCondition* cond, NPosture3DIO* postureIO)
{
	makeEvent(cond);
	mPostureIO = postureIO;
	mSplineInterpolator->makeSpline();
}

/**
 * @todo: Documentation
 */
void PeveInterpolationEvent::reset()
{
	PeveEvent::reset();
	mAlpha.reset();
	mSplineInterpolator->reset();
	mCurrentFrameIndex = 0;
	mPostureIO->input(getFrame(0)->getPosture());
	if (mCurrentFrameIndex == getChildCount() - 1) {
		mNextFrameParam = 1.0f;
	} else {
		mNextFrameParam = getFrame(mCurrentFrameIndex + 1)->getParameter();
	}
}

/**
 * @todo: Documentation
 */
void PeveInterpolationEvent::update()
{
	PeveEvent::update();
	if (mAlpha.getValue() >= mNextFrameParam && mCurrentFrameIndex + 1 < getChildCount()) {
		mCurrentFrameIndex++;
		mPostureIO->input(getFrame(mCurrentFrameIndex)->getPosture());
		if (mCurrentFrameIndex == getChildCount() - 1) {
			mNextFrameParam = 1.0f;
		} else {
			SplineKeyFrame* frame = getFrame(mCurrentFrameIndex + 1);
			mNextFrameParam       = frame->getParameter();
		}
	}

	f32 val = mAlpha.getValue();
	NPosture3D posture;
	mSplineInterpolator->interpolateNext(val, posture);
	posture.normalize();
	mPostureIO->input(posture);
	f32 fTime = NSystem::getFrameTime();
	mAlpha.passTime(fTime);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00005C
 */
PeveMoveEvent::PeveMoveEvent()
    : PeveEvent(0)
{
	mBoolCondition.construct(true);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00006C
 */
void PeveMoveEvent::makeMoveEvent(NPosture3DIO* postureIO, NPosture3D& posture)
{
	makeEvent(&mBoolCondition);
	mPostureIO = postureIO;
	mPosture.input(posture);
}

/**
 * @todo: Documentation
 */
void PeveMoveEvent::reset()
{
	PeveEvent::reset();
	mPostureIO->input(mPosture);
}

/**
 * @todo: Documentation
 */
PeveVibrationEvent::PeveVibrationEvent()
    : PeveEvent(0)
{
	mPolyFunction.construct(new f32[2], 2);
	mTimeCondition.construct(0.0f);
}

/**
 * @todo: Documentation
 */
void PeveVibrationEvent::makeVibrationEvent(f32 duration, NPosture3DIO* postureIO, NVector3f& up, f32 intensity, f32 frequency, f32 p6)
{
	mPostureIO = postureIO;
	mTimeCondition.setPeriod(duration);
	makeEvent(&mTimeCondition);
	mUpVector.input(up);
	mVibFunction.makeVibrationFunction(0.0f, intensity, 1.0f);
	mPolyFunction.mData.mValues[0] = frequency;
	mPolyFunction.mData.mValues[1] = p6;
}

/**
 * @todo: Documentation
 */
void PeveVibrationEvent::update()
{
	PeveEvent::update();
	f32 time = mTimeCondition.getTime();
	f32 val  = mPolyFunction.getValue(time) * mVibFunction.getValue(time);

	NVector3f vec;
	vec.scale2(val, mUpVector);

	NPosture3D posture;
	mPostureIO->output(posture);
	posture.translate(vec);
	mPostureIO->input(posture);
}
