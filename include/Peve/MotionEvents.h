#ifndef _PEVE_MOTIONEVENTS_H
#define _PEVE_MOTIONEVENTS_H

#include "Peve/Condition.h"
#include "Peve/Event.h"
#include "Peve/IO.h"
#include "nlib/Geometry.h"
#include "nlib/Spline.h"
#include "types.h"

class NFunction3D;
class NPosture3DIO;
class NVector3f;
class NVector3fIO;
struct PeveHomingPositionEvent; // I don't feel like reordering the classes right now.
class Vector3f;

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct PeveAccelerationEvent : public PeveEvent {
	PeveAccelerationEvent();

	virtual void update(); // _24

	void makeAccelerationEvent(PeveCondition*, NVector3fIO*, NVector3fIO*, NVector3fIO*);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	NVector3fIO* mPositionIO; // _10
	NVector3fIO* mVelocityIO; // _14
	NVector3fIO* mAccelIO;    // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x38.
 */
struct PeveCircleMoveEvent : public PeveEvent {
	PeveCircleMoveEvent();

	virtual void reset();  // _20
	virtual void update(); // _24

	void makeCircleMoveEvent(f32 timeLimit, NVector3fIO* positionIO, NVector3fIO* centerPositionIO, f32 positionLerpFactor, f32 radius,
	                         f32 heightOffset, f32 angularSpeed);
	void outputPosition(Vector3f&);
	f32 calcAngle();

	// _00     = VTBL
	// _00-_10 = PeveEvent
	f32 mAngle;                       // _10
	PeveTimeCondition mTimeCondition; // _14
	NVector3fIO* mPositionIO;         // _20
	NVector3fIO* mCenterPositionIO;   // _24
	f32 mPositionLerpFactor;          // _28
	f32 mRadius;                      // _2C
	f32 mHeightOffset;                // _30
	f32 mAngularSpeed;                // _34
};

/**
 * @brief TODO
 */
struct PeveCircleMoveWatchEvent : public PeveParallelEvent {
	PeveCircleMoveWatchEvent(); // unused/inlined

	// unused/inlined:
	void makeCircleMoveWatchEvent(f32 timeLimit, NVector3fIO* circlePositionIO, NVector3fIO* homingPositionIO,
	                              NVector3fIO* centerPositionIO, f32 positionLerpFactor, f32 homingRate, f32 radius, f32 heightOffset,
	                              f32 angularSpeed);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	PeveTimeCondition mTimeCondition;              // _10
	PeveCircleMoveEvent* mCircleMoveEvent;         // _14
	PeveHomingPositionEvent* mHomingPositionEvent; // _18
};

/**
 * @brief TODO
 */
struct PeveFunctionCurveEvent : public PeveEvent {
	PeveFunctionCurveEvent(); // unused/inlined

	virtual void reset();  // _20
	virtual void update(); // _24

	// unused/inlined:
	void makeFunctionCurveEvent(PeveCondition* cond, NVector3fIO* positionIO, NFunction3D* func, f32 startParam, f32 paramStep,
	                            bool useFrameTimeScaledStep);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	f32 mCurrentParam;        // _10
	NVector3fIO* mPositionIO; // _14
	NFunction3D* mFunction; // _18
	f32 mStartParam;        // _1C
	f32 mParamStep;         // _20
	bool mUseFrameTimeScaledStep; // _24
};

/**
 * @brief TODO
 */
struct PeveHomingPositionEvent : public PeveEvent {
	PeveHomingPositionEvent(); // unused/inlined

	virtual void update(); // _24

	// unused/inlined:
	void makeHomingPositionEvent(PeveCondition* cond, NVector3fIO* positionIO, NVector3fIO* targetPositionIO, f32 homingRate);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	NVector3fIO* mPositionIO;       // _10
	NVector3fIO* mTargetPositionIO; // _14
	f32 mHomingRate;                // _18
};

/**
 * @brief TODO
 */
struct PeveHomingPostureEvent : public PeveParallelEvent {
	PeveHomingPostureEvent(); // unused/inlined;

	// unused/inlined:
	void makeHomingPostureEvent(PeveCondition* condA, NVector3fIO* positionIOA, NVector3fIO* targetPositionIOA, f32 homingRateA,
	                            PeveCondition* condB, NVector3fIO* positionIOB, NVector3fIO* targetPositionIOB, f32 homingRateB);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	PeveHomingPositionEvent* mHomingPositionEvent1; // _10
	PeveHomingPositionEvent* mHomingPositionEvent2; // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x34.
 */
struct PeveHorizontalSinWaveEvent : public PeveEvent {
	PeveHorizontalSinWaveEvent()
	    : PeveEvent(0)
	{
	}

	virtual void reset();  // _20
	virtual void update(); // _24

	void makeHorizontalSinWaveEvent(PeveCondition* cond, NVector3fIO* positionIO, NVector3f linearVelocity, f32 offset, f32 amplitude,
	                                f32 startTheta, f32 angularVelocity);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	NVector3fIO* mPositionIO;  // _10
	NVector3f mLinearVelocity; // _14
	f32 mOffset;          // _20
	f32 mAmplitude;       // _24
	f32 mStartingTheta;   // _28
	f32 mAngularVelocity; // _2C
	f32 mTheta;           // _30
};

/**
 * @brief TODO
 */
struct PeveInterpolationEvent : public PeveEvent {
	PeveInterpolationEvent(int, NPool<SplineSegment>*);

	virtual void reset();                                                // _20
	virtual void update();                                               // _24
	virtual bool isFinished() { return mAlpha.isFinished(); }            // _28
	virtual void setStartTime(f32 start) { mAlpha.setStartTime(start); } // _3C
	virtual f32 getStartTime() { return mAlpha.getStartTime(); }         // _40
	virtual void setPeriod(f32 period) { mAlpha.setPeriod(period); }     // _44
	virtual f32 getPeriod() { return mAlpha.getPeriod(); }               // _48
	virtual void setTime(f32 time) { mAlpha.setTime(time); }             // _4C
	virtual f32 getTime() { return mAlpha.getTime(); }                   // _50
	virtual f32 getEndTime() { return mAlpha.getEndTime(); }             // _54

	// unused/inlined:
	void makeInterpolationEvent(PeveCondition*, NPosture3DIO*);

	// DLL inlines:
	SplineKeyFrame* getFrame(int idx) { return mSplineInterpolator->getFrame(idx); }

	// _00     = VTBL
	// _00-_10 = PeveEvent
	int mCurrentFrameIndex;                  // _10
	f32 mNextFrameParam;                     // _14
	NAlpha mAlpha;                           // _18
	SplineInterpolator* mSplineInterpolator; // _2C
	NPosture3DIO* mPostureIO;                // _30
};

/**
 * @brief TODO
 */
struct PeveMoveEvent : public PeveEvent {
	PeveMoveEvent();

	virtual void reset(); // _20

	// unused/inlined:
	void makeMoveEvent(NPosture3DIO*, NPosture3D&);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	PeveBooleanCondition mBoolCondition; // _10
	NPosture3DIO* mPostureIO;            // _18
	NPosture3D mPosture;                 // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x40.
 */
struct PeveParabolaEvent : public PeveAccelerationEvent {
	PeveParabolaEvent();

	void makeParabolaEvent(PeveCondition* cond, NVector3fIO* positionIO, NVector3f& initialVelocity, f32 maxLength, f32 gravityStrength);

	// _00     = VTBL
	// _00-_1C = PeveAccelerationEvent
	NVector3fIOClass mGravityAccelIO;       // _1C
	PeveClampVector3fIO mClampedVelocityIO; // _2C
};

/**
 * @brief TODO
 *
 * @note Size: 0x48.
 */
struct PeveVibrationEvent : public PeveEvent {
	PeveVibrationEvent();

	virtual void update(); // _24

	void makeVibrationEvent(f32 duration, NPosture3DIO* postureIO, NVector3f& up, f32 intensity, f32 frequency, f32);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	NPosture3DIO* mPostureIO;          // _10
	NVector3f mUpVector;               // _14
	PeveTimeCondition mTimeCondition;  // _20
	NVibrationFunction mVibFunction;   // _2C
	NPolynomialFunction mPolyFunction; // _3C
};

/**
 * @brief TODO
 */
struct PeveWaitEvent : public PeveEvent {
	PeveWaitEvent();

	// unused/inlined:
	void makeWaitEvent(f32);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	PeveTimeCondition mTimeCondition; // _10
};

#endif
