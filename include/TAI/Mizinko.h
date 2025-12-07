#ifndef _TAI_MIZINKO_H
#define _TAI_MIZINKO_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Action.h"
#include "TekiParameters.h"

/////////// Honeywisp (ピキマキ) [Generator] ///////////

/**
 * @brief TODO
 */
enum TaiMizigenStateID {
	MIZIGENSTATE_Wait     = 0,
	MIZIGENSTATE_Generate = 1,
	MIZIGENSTATE_COUNT, // 2
};

/**
 * @brief TODO
 */
struct TaiMizigenParameters : public TekiParameters {
	TaiMizigenParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TaiMizigenStrategy : public TaiStrategy {
	TaiMizigenStrategy(TekiParameters*);

	virtual void start(Teki&); // _08

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

/////////// Honeywisp (ピキマキ) ///////////

/**
 * @brief TODO
 */
enum TaiMizinkoFloatParams {
	MIZINKOPF_DropDistance = TPF_COUNT,  // 50
	MIZINKOPF_PathDistance,              // 51
	MIZINKOPF_FlyingAwayVelocity,        // 52
	MIZINKOPF_FlyingAwayAccel,           // 53
	MIZINKOPF_FadePeriod,                // 54
	MIZINKOPF_HidingPeriod,              // 55
	MIZINKOPF_HidingPeriodRandomRate,    // 56
	MIZINKOPF_FlightHeightRandomRate,    // 57
	MIZINKOPF_FlightAmplitude,           // 58
	MIZINKOPF_FlightAmplitudeRandomRate, // 59
	MIZINKOPF_AngularVelocity,           // 60
	MIZINKOPF_AngularVelocityRandomRate, // 61
	MIZINKOPF_CryPeriod,                 // 62
	MIZINKOPF_CryPeriodRandomRate,       // 63
	MIZINKOPF_COUNT,                     // 64
};

/**
 * @brief TODO
 */
enum TaiMizinkoStateID {
	MIZINKOSTATE_Going       = 0,
	MIZINKOSTATE_HidingDest  = 1,
	MIZINKOSTATE_Coming      = 2,
	MIZINKOSTATE_HidingStart = 3,
	MIZINKOSTATE_DropWater   = 4,
	MIZINKOSTATE_FlyingAway  = 5,
	MIZINKOSTATE_Dead        = 6,
	MIZINKOSTATE_COUNT, // 7
};

/**
 * @brief TODO
 */
struct TaiMizinkoSoundTable : public PaniSoundTable {
	TaiMizinkoSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizinkoParameters : public TekiParameters {
	TaiMizinkoParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizinkoStrategy : public TaiStrategy {
	TaiMizinkoStrategy(TekiParameters*);

	virtual void start(Teki&);           // _08
	virtual void draw(Teki&, Graphics&); // _18

	bool hasWater(Teki&);

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

#endif
