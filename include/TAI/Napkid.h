#ifndef _TAI_NAPKID_H
#define _TAI_NAPKID_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/MotionActions.h"
#include "TekiParameters.h"

/////////// Swooping Snitchbug (サライムシ) ///////////

/**
 * @brief TODO: name members
 */
BEGIN_ENUM_TYPE(TaiNapkidIntParms)
enum {
	StruggleLoopCount = TPI_COUNT,
	COUNT,
} END_ENUM_TYPE;

/**
 * @brief TODO: name members
 */
BEGIN_ENUM_TYPE(TaiNapkidFloatParms)
enum {
	CarryingVelocity = TPF_COUNT,
	CarryFlightHeight,
	TakingOffFlightHeight,
	WanderingHoverPeriod,
	WanderingHoverProbability,
	HoveringWanderPeriod,
	HoveringWanderProbability,
	HoveringWashPeriod,
	HoveringWashProbability,
	WashingWanderPeriod,
	WashingWanderProbability,
	ThrowPeriod,
	ThrowVelocity,
	COUNT,
} END_ENUM_TYPE;

/**
 * @brief TODO: name members
 */
BEGIN_ENUM_TYPE(TaiNapkidStateID)
enum {
	Dying          = 0,
	Wandering      = 1,
	IdleFlying     = 2,
	IdleChatting   = 3,
	Chasing        = 4,
	Outrunning     = 5,
	Evading        = 6,
	AttackingSetup = 7,
	Attacking      = 8,
	Catching       = 9,
	AttackDeciding = 10,
	CarryingSetup  = 11,
	AttackMissing  = 12,
	Carrying       = 13,
	Throwing       = 14,
	ShockFalling   = 15,
	LoopFalling    = 16,
	Landing        = 17,
	Struggling     = 18,
	GettingUp      = 19,
	HeightDeciding = 20,
	Flicking       = 21,
	Rising         = 22,
	COUNT, // 23
} END_ENUM_TYPE;

/*
 * @brief TODO
 */
struct TaiNapkidSoundTable : public PaniSoundTable {
	TaiNapkidSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiNapkidParameters : public TekiParameters {
	TaiNapkidParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TaiNapkidStrategy : public TaiStrategy {
	TaiNapkidStrategy(TekiParameters*);

	virtual void start(Teki&);                    // _08
	virtual void draw(Teki&, Graphics&);          // _18
	virtual void drawDebugInfo(Teki&, Graphics&); // _1C

	// _00     = VTBL
	// _00-_10 = TaiStrategy
	// TODO: members
};

#endif
