#ifndef _PCAM_MOTIONEVENTS_H
#define _PCAM_MOTIONEVENTS_H

#include "types.h"
#include "Peve/MotionEvents.h"

struct PcamCamera;

/**
 * @brief TODO
 */
struct PcamDamageEvent : public PeveVibrationEvent {
	PcamDamageEvent(PcamCamera*);

	void makePcamDamageEvent();

	// _00     = VTBL
	// _00-_10 = PeveVibrationEvent?
	// TODO: members
};

/**
 * @brief TODO
 */
struct PcamLongVibrationEvent : public PeveSerialEvent {
	PcamLongVibrationEvent(PcamCamera*);

	void makePcamLongVibrationEvent(f32, f32, f32, f32);

	// _00     = VTBL
	// _00-_10 = PeveSerialEvent?
	// TODO: members
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
	// TODO: members
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct PcamVibrationEvent : public PeveVibrationEvent {
	PcamVibrationEvent(PcamCamera*);

	void makePcamVibrationEvent();

	// _00     = VTBL
	// _00-_10 = PeveVibrationEvent?
	// TODO: members
};

#endif
