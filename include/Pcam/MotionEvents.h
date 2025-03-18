#ifndef _PCAM_MOTIONEVENTS_H
#define _PCAM_MOTIONEVENTS_H

#include "types.h"
#include "Peve/MotionEvents.h"
#include "Peve/IO.h"

struct PcamCamera;

/**
 * @brief TODO
 */
struct PcamDamageEvent : public PeveVibrationEvent {
	PcamDamageEvent(PcamCamera*);

	void makePcamDamageEvent();

	// _00     = VTBL
	// _00-_48 = PeveVibrationEvent
	f32 _48;                        // _48
	f32 _4C;                        // _4C
	f32 _50;                        // _50
	PcamCamera* mCamera;            // _54
	PeveCameraPostureIO mPostureIO; // _58
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct PcamLongVibrationEvent : public PeveSerialEvent {
	PcamLongVibrationEvent(PcamCamera*);

	void makePcamLongVibrationEvent(f32, f32, f32, f32);

	// _00     = VTBL
	// _00-_14 = PeveSerialEvent
	PeveVibrationEvent* _14;        // _14
	PeveVibrationEvent* _18;        // _18
	PcamCamera* mCamera;            // _1C
	PeveCameraPostureIO mPostureIO; // _20
};

/**
 * @brief TODO
 */
struct PcamRandomMoveEvent : public PeveEvent {
	PcamRandomMoveEvent(PcamCamera*);

	virtual void update(); // _24

	// unused/inlined:
	void makePcamRandomMoveEvent();

	// _00     = VTBL
	// _00-_10 = PeveEvent
	f32 _10;                          // _10
	f32 _14;                          // _14
	PeveTimeCondition mTimeCondition; // _18
	PcamCamera* mCamera;              // _24
};

/**
 * @brief TODO
 */
struct PcamSideVibrationEvent : public PeveEvent {
	PcamSideVibrationEvent(PcamCamera*);

	virtual void update(); // _24
	virtual void finish(); // _2C

	void makePcamSideVibrationEvent();

	// _00     = VTBL
	// _00-_10 = PeveEvent
	f32 _10;                           // _10
	f32 _14;                           // _14
	f32 _18;                           // _18
	PeveTimeCondition mTimeCondition;  // _1C
	PcamCamera* mCamera;               // _28
	NVibrationFunction mVibFunction;   // _2C
	NPolynomialFunction mPolyFunction; // _3C
};

/**
 * @brief TODO
 *
 * @note Size: 0x60.
 */
struct PcamVibrationEvent : public PeveVibrationEvent {
	PcamVibrationEvent(PcamCamera*);

	void makePcamVibrationEvent();

	// _00     = VTBL
	// _00-_48 = PeveVibrationEvent
	f32 _48;                        // _48
	f32 _4C;                        // _4C
	f32 _50;                        // _50
	PcamCamera* mCamera;            // _54
	PeveCameraPostureIO mPostureIO; // _58
};

#endif
