#ifndef _PEVE_MOTIONEVENTS_H
#define _PEVE_MOTIONEVENTS_H

#include "Peve/Event.h"
#include "Peve/IO.h"
#include "nlib/Geometry.h"
#include "nlib/Spline.h"
#include "types.h"

struct NFunction3D;
struct NPosture3DIO;
struct NVector3f;
struct NVector3fIO;
struct Vector3f;

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

	void makeCircleMoveEvent(f32, NVector3fIO*, NVector3fIO*, f32, f32, f32, f32);
	void outputPosition(Vector3f&);
	f32 calcAngle();

	// _00     = VTBL
	// _00-_10 = PeveEvent
	f32 mAngle;                       // _10
	PeveTimeCondition mTimeCondition; // _14
	NVector3fIO* _20;                 // _20
	NVector3fIO* _24;                 // _24
	f32 _28;                          // _28
	f32 _2C;                          // _2C
	f32 _30;                          // _30
	f32 _34;                          // _34
};

/**
 * @brief TODO
 */
struct PeveCircleMoveWatchEvent : public PeveParallelEvent {
	PeveCircleMoveWatchEvent(); // unused/inlined

	// unused/inlined:
	void makeCircleMoveWatchEvent(f32, NVector3fIO*, NVector3fIO*, NVector3fIO*, f32, f32, f32, f32, f32);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveFunctionCurveEvent : public PeveEvent {
	PeveFunctionCurveEvent(); // unused/inlined

	virtual void reset();  // _20
	virtual void update(); // _24

	// unused/inlined:
	void makeFunctionCurveEvent(PeveCondition*, NVector3fIO*, NFunction3D*, f32, f32, bool);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	f32 _10;                // _10
	NVector3fIO* _14;       // _14
	NFunction3D* mFunction; // _18
	f32 _1C;                // _1C
	f32 _20;                // _20
	bool _24;               // _24
};

/**
 * @brief TODO
 */
struct PeveHomingPositionEvent : public PeveEvent {
	PeveHomingPositionEvent(); // unused/inlined

	virtual void update(); // _24

	// unused/inlined:
	void makeHomingPositionEvent(PeveCondition*, NVector3fIO*, NVector3fIO*, f32);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	NVector3fIO* _10; // _10
	NVector3fIO* _14; // _14
	f32 _18;          // _18
};

/**
 * @brief TODO
 */
struct PeveHomingPostureEvent : public PeveParallelEvent {
	PeveHomingPostureEvent(); // unused/inlined;

	// unused/inlined:
	void makeHomingPostureEvent(PeveCondition*, NVector3fIO*, NVector3fIO*, f32, PeveCondition*, NVector3fIO*, NVector3fIO*, f32);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	// TODO: members
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

	void makeHorizontalSinWaveEvent(PeveCondition*, NVector3fIO*, NVector3f, f32, f32, f32, f32);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	NVector3fIO* _10;     // _10
	NVector3f _14;        // _14
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
	int _10;                                 // _10
	f32 _14;                                 // _14
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

	void makeParabolaEvent(PeveCondition*, NVector3fIO*, NVector3f&, f32, f32);

	// _00     = VTBL
	// _00-_1C = PeveAccelerationEvent
	NVector3fIOClass _1C;    // _1C
	PeveClampVector3fIO _2C; // _2C
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
