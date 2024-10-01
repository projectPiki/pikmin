#ifndef _PEVE_MOTIONEVENTS_H
#define _PEVE_MOTIONEVENTS_H

#include "types.h"
#include "Peve/Event.h"
#include "nlib/Spline.h"
#include "nlib/Geometry.h"

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
	u8 _10[0xC]; // _10, unknown
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
	void calcAngle();

	// _00     = VTBL
	// _00-_10 = PeveEvent
	u8 _10[0x38 - 0x10]; // _10, unknown
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
	u8 _10[0x4];         // _10, unknown
	NVector3f _14;       // _14
	u8 _20[0x34 - 0x20]; // _20, unknown
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
 *
 * @note Size: 0x40.
 */
struct PeveParabolaEvent : public PeveAccelerationEvent {
	PeveParabolaEvent();

	void makeParabolaEvent(PeveCondition*, NVector3fIO*, NVector3f&, f32, f32);

	// _00     = VTBL
	// _00-_1C = PeveAccelerationEvent
	u8 _1C[0x40 - 0x1C]; // _1C, unknown
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
