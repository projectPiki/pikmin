#ifndef _PEVE_MOTIONEVENTS_H
#define _PEVE_MOTIONEVENTS_H

#include "types.h"
#include "Peve/Event.h"
#include "nlib/Spline.h"

struct NFunction3D;
struct NPosture3DIO;
struct NVector3f;
struct NVector3fIO;
struct Vector3f;

/**
 * @brief TODO
 */
struct PeveAccelerationEvent : public PeveEvent {
	PeveAccelerationEvent();

	virtual void update(); // _24

	void makeAccelerationEvent(PeveCondition*, NVector3fIO*, NVector3fIO*, NVector3fIO*);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveCircleMoveEvent : public PeveEvent {
	PeveCircleMoveEvent();

	virtual void reset();  // _20
	virtual void update(); // _24

	void makeCircleMoveEvent(f32, NVector3fIO*, NVector3fIO*, f32, f32, f32, f32);
	void outputPosition(Vector3f&);
	void calcAngle();

	// _00     = VTBL
	// _00-_10 = PeveEvent
	// TODO: members
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
	// TODO: members
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
	// TODO: members
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveInterpolationEvent : public PeveEvent {
	PeveInterpolationEvent(int, NPool<SplineSegment>*);

	virtual void reset();           // _20
	virtual void update();          // _24
	virtual bool isFinished();      // _28
	virtual void setStartTime(f32); // _3C
	virtual void getStartTime();    // _40
	virtual void setPeriod(f32);    // _44
	virtual void getPeriod();       // _48
	virtual void setTime(f32);      // _4C
	virtual void getTime();         // _50
	virtual void getEndTime();      // _54

	// unused/inlined:
	void makeInterpolationEvent(PeveCondition*, NPosture3DIO*);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	// TODO: members
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveParabolaEvent : public PeveAccelerationEvent {
	PeveParabolaEvent();

	void makeParabolaEvent(PeveCondition*, NVector3fIO*, NVector3f&, f32, f32);

	// _00     = VTBL
	// _00-_10 = PeveAccelerationEvent?
	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveVibrationEvent : public PeveEvent {
	PeveVibrationEvent();

	virtual void update(); // _24

	void makeVibrationEvent(f32, NPosture3DIO*, NVector3f&, f32, f32, f32);

	// _00     = VTBL
	// _00-_10 = PeveEvent
	// TODO: members
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
	// TODO: members
};

#endif
