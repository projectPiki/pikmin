#include "Peve/MotionEvents.h"
#include "nlib/Geometry.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("pevemotionevents")

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
PeveWaitEvent::PeveWaitEvent()
    : PeveEvent(0)
{
	mTimeCondition.construct(1.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void PeveWaitEvent::makeWaitEvent(f32 waitTime)
{
	mTimeCondition.setPeriod(waitTime);
	makeEvent(&mTimeCondition);
}

/*
 * --INFO--
 * Address:	80125F04
 * Size:	000040
 */
PeveAccelerationEvent::PeveAccelerationEvent()
    : PeveEvent(0)
{
}

/*
 * --INFO--
 * Address:	80125F44
 * Size:	000014
 */
void PeveAccelerationEvent::makeAccelerationEvent(PeveCondition* cond, NVector3fIO* vecIOA, NVector3fIO* vecIOB, NVector3fIO* vecIOC)
{
	makeEvent(cond);
	_10 = vecIOA;
	_14 = vecIOB;
	_18 = vecIOC;
}

/*
 * --INFO--
 * Address:	80125F58
 * Size:	00017C
 */
void PeveAccelerationEvent::update()
{
	PeveEvent::update();
	NVector3f& vec1 = NVector3f();
	NVector3f& vec2 = NVector3f();
	NVector3f& vec3 = NVector3f();

	_10->output(vec1);
	_14->output(vec2);
	_18->output(vec3);

	f32 fTime = NSystem::getFrameTime();
	Vector3f offs1(vec2);
	offs1.scale(fTime);
	Vector3f offs2(vec3);
	offs2.scale(fTime);
	vec1.add(offs1);
	vec2.add(offs2);
	_10->input(vec1);
	_14->input(vec2);
}

/*
 * --INFO--
 * Address:	801260D4
 * Size:	000074
 */
PeveParabolaEvent::PeveParabolaEvent()
{
}

/*
 * --INFO--
 * Address:	80126148
 * Size:	0000B0
 */
void PeveParabolaEvent::makeParabolaEvent(PeveCondition* cond, NVector3fIO* vecIO, NVector3f& p3, f32 maxLength, f32 p5)
{
	_2C.setMaxLength(maxLength);
	_2C.input(p3);

	NVector3f& vec1 = NVector3f(0.0f, -p5, 0.0f);
	_1C.input(vec1);
	makeAccelerationEvent(cond, vecIO, &_2C, &_1C);
}

/*
 * --INFO--
 * Address:	801261F8
 * Size:	000034
 */
void PeveHorizontalSinWaveEvent::makeHorizontalSinWaveEvent(PeveCondition* cond, NVector3fIO* vecIO, NVector3f p3, f32 p4, f32 p5, f32 p6,
                                                            f32 p7)
{
	makeEvent(cond);
	_10 = vecIO;
	_14.input(p3);
	mOffset        = p4;
	mAmplitude     = p5;
	mStartingTheta = p6;
	_2C            = p7;
}

/*
 * --INFO--
 * Address:	8012622C
 * Size:	00004C
 */
void PeveHorizontalSinWaveEvent::reset()
{
	PeveEvent::reset();
	mTheta = mStartingTheta;
}

/*
 * --INFO--
 * Address:	80126278
 * Size:	000118
 */
void PeveHorizontalSinWaveEvent::update()
{
	PeveEvent::update();
	f32 fTime = NSystem::getFrameTime();
	f32 y     = mAmplitude * NMathF::sin(mTheta) + mOffset;
	mTheta += fTime * _2C;

	Vector3f vec1(_14);
	vec1.scale(fTime);

	NVector3f vec2;
	_10->output(vec2);

	vec2.add(vec1);
	vec2.y = y;
	_10->input(vec2);
}

/*
 * --INFO--
 * Address:	80126390
 * Size:	00005C
 */
PeveCircleMoveEvent::PeveCircleMoveEvent()
    : PeveEvent(0)
{
	mTimeCondition.construct(1.0f);
	mAngle = 0.0f;
}

/*
 * --INFO--
 * Address:	801263EC
 * Size:	000028
 */
void PeveCircleMoveEvent::makeCircleMoveEvent(f32 timeLimit, NVector3fIO* vecIOA, NVector3fIO* vecIOB, f32 p4, f32 p5, f32 p6, f32 p7)
{
	mTimeCondition.setPeriod(timeLimit);
	makeEvent(&mTimeCondition);
	_20 = vecIOA;
	_24 = vecIOB;
	_28 = p4;
	_2C = p5;
	_30 = p6;
	_34 = p7;
}

/*
 * --INFO--
 * Address:	80126414
 * Size:	000050
 */
void PeveCircleMoveEvent::reset()
{
	PeveEvent::reset();
	mAngle = calcAngle();
}

/*
 * --INFO--
 * Address:	80126464
 * Size:	000134
 */
void PeveCircleMoveEvent::update()
{
	PeveEvent::update();
	mAngle += _34 * NSystem::getFrameTime();
	NVector3f vec1;
	_20->output(vec1);

	NVector3f pos;
	outputPosition(pos);
	pos.sub(vec1);
	pos.scale(_28);
	vec1.add(pos);
	_20->input(vec1);
}

/*
 * --INFO--
 * Address:	80126598
 * Size:	0000AC
 */
void PeveCircleMoveEvent::outputPosition(Vector3f& outPos)
{
	NVector3f vec1;
	_24->output(vec1);
	outPos.set(_2C * NMathF::sin(mAngle) + vec1.x, vec1.y + _30, _2C * NMathF::cos(mAngle) + vec1.z);
}

/*
 * --INFO--
 * Address:	80126644
 * Size:	000084
 */
f32 PeveCircleMoveEvent::calcAngle()
{
	NVector3f vec1;
	_24->output(vec1);

	NVector3f vec2;
	_20->output(vec2);

	NVector3f vec3(vec1, vec2);
	return NMathF::atan2(vec3.x, vec3.z);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
PeveCircleMoveWatchEvent::PeveCircleMoveWatchEvent()
    : PeveParallelEvent(2)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void PeveCircleMoveWatchEvent::makeCircleMoveWatchEvent(f32, NVector3fIO*, NVector3fIO*, NVector3fIO*, f32, f32, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
PeveFunctionCurveEvent::PeveFunctionCurveEvent()
    : PeveEvent(0)
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void PeveFunctionCurveEvent::makeFunctionCurveEvent(PeveCondition* cond, NVector3fIO* vecIO, NFunction3D* func, f32 p4, f32 p5, bool p6)
{
	makeEvent(cond);
	_14       = vecIO;
	mFunction = func;
	_1C       = p4;
	_20       = p5;
	_24       = p6;
}

/*
 * --INFO--
 * Address:	801266C8
 * Size:	00000C
 */
void PeveFunctionCurveEvent::reset()
{
	_10 = _1C;
}

/*
 * --INFO--
 * Address:	801266D4
 * Size:	0000C0
 */
void PeveFunctionCurveEvent::update()
{
	PeveEvent::update();
	NVector3f& vec1 = NVector3f();
	mFunction->outputPosition(_10, vec1);
	_14->input(vec1);
	if (_24) {
		_10 += _20 * NSystem::getFrameTime();
	} else {
		_10 += _20;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
PeveHomingPositionEvent::PeveHomingPositionEvent()
    : PeveEvent(0)
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void PeveHomingPositionEvent::makeHomingPositionEvent(PeveCondition* cond, NVector3fIO* vecIOA, NVector3fIO* vecIOB, f32 p4)
{
	makeEvent(cond);
	_10 = vecIOA;
	_14 = vecIOB;
	_18 = p4;
}

/*
 * --INFO--
 * Address:	80126794
 * Size:	000124
 */
void PeveHomingPositionEvent::update()
{
	PeveEvent::update();
	NVector3f& vec1 = NVector3f();
	_10->output(vec1);

	NVector3f& vec2 = NVector3f();
	_14->output(vec2);

	NVector3f& vec3 = NVector3f(vec1, vec2);
	vec3.scale(_18);
	vec1.add(vec3);
	_10->input(vec1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
PeveHomingPostureEvent::PeveHomingPostureEvent()
    : PeveParallelEvent(0)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void PeveHomingPostureEvent::makeHomingPostureEvent(PeveCondition*, NVector3fIO*, NVector3fIO*, f32, PeveCondition*, NVector3fIO*,
                                                    NVector3fIO*, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
PeveInterpolationEvent::PeveInterpolationEvent(int p1, NPool<SplineSegment>* p2)
    : PeveEvent(0)
{
	mSplineInterpolator = new SplineInterpolator(p1, p2);
	_10                 = 0;
	_14                 = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void PeveInterpolationEvent::makeInterpolationEvent(PeveCondition* cond, NPosture3DIO* postureIO)
{
	makeEvent(cond);
	mPostureIO = postureIO;
	mSplineInterpolator->makeSpline();
}

/*
 * --INFO--
 * Address:	801268B8
 * Size:	0000EC
 */
void PeveInterpolationEvent::reset()
{
	PeveEvent::reset();
	mAlpha.reset();
	mSplineInterpolator->reset();
	_10 = 0;
	mPostureIO->input(getFrame(0)->getPosture());
	if (_10 == getChildCount() - 1) {
		_14 = 1.0f;
	} else {
		_14 = getFrame(_10 + 1)->getParameter();
	}
}

/*
 * --INFO--
 * Address:	801269A4
 * Size:	00017C
 */
void PeveInterpolationEvent::update()
{
	PeveEvent::update();
	if (mAlpha.getValue() >= _14 && _10 + 1 < getChildCount()) {
		_10++;
		mPostureIO->input(getFrame(_10)->getPosture());
		if (_10 == getChildCount() - 1) {
			_14 = 1.0f;
		} else {
			SplineKeyFrame* frame = getFrame(_10 + 1);
			_14                   = frame->getParameter();
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

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
PeveMoveEvent::PeveMoveEvent()
    : PeveEvent(0)
{
	mBoolCondition.construct(true);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void PeveMoveEvent::makeMoveEvent(NPosture3DIO* postureIO, NPosture3D& posture)
{
	makeEvent(&mBoolCondition);
	mPostureIO = postureIO;
	mPosture.input(posture);
}

/*
 * --INFO--
 * Address:	80126B20
 * Size:	00005C
 */
void PeveMoveEvent::reset()
{
	PeveEvent::reset();
	mPostureIO->input(mPosture);
}

/*
 * --INFO--
 * Address:	80126B7C
 * Size:	00009C
 */
PeveVibrationEvent::PeveVibrationEvent()
    : PeveEvent(0)
{
	mPolyFunction.construct(new f32[2], 2);
	mTimeCondition.construct(0.0f);
}

/*
 * --INFO--
 * Address:	80126C18
 * Size:	000088
 */
void PeveVibrationEvent::makeVibrationEvent(f32 p1, NPosture3DIO* postureIO, NVector3f& p3, f32 p4, f32 p5, f32 p6)
{
	mPostureIO = postureIO;
	mTimeCondition.setPeriod(p1);
	makeEvent(&mTimeCondition);
	_14.input(p3);
	mVibFunction.makeVibrationFunction(0.0f, p4, 1.0f);
	mPolyFunction.mData.mValues[0] = p5;
	mPolyFunction.mData.mValues[1] = p6;
}

/*
 * --INFO--
 * Address:	80126CA0
 * Size:	000100
 */
void PeveVibrationEvent::update()
{
	PeveEvent::update();
	f32 time = mTimeCondition.getTime();
	f32 val  = mPolyFunction.getValue(time) * mVibFunction.getValue(time);

	NVector3f vec;
	vec.scale2(val, _14);

	NPosture3D posture;
	mPostureIO->output(posture);
	posture.translate(vec);
	mPostureIO->input(posture);
}
