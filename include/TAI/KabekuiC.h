#ifndef _TAI_KABEKUIC_H
#define _TAI_KABEKUIC_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

/////////// Shearwig AI Actions ///////////

BEGIN_ENUM_TYPE(TAIkabekuiCFloatParms)
enum {
	BridgeAttackRange = TPF_COUNT,
	BridgeDamage,
	FlightAlertLifePercent,
	MaxFlightLifePercent,
	FlightYVelocity,
	TakeoffYVelocity,
	TimeUntilBurrow,
	MaxSleepTime,
	PikiAttackRange,
	NaviAttackRange,
	COUNT,
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAIkabekuiCStateID)
enum {
	Dying        = 0,
	Waiting      = 1,
	Appearing    = 2,
	MovingSetup  = 3,
	MovingBridge = 4,
	MovingPiki   = 5,
	BiteAttack   = 6,
	BiteChewing  = 7,
	Takeoff      = 8,
	Flying       = 9,
	Landing      = 10,
	CrushDying   = 11,
	ChasingSetup = 12,
	Chasing      = 13,
	EatingBridge = 14,
	Burrowing    = 15,
	WaitingSetup = 16,
	COUNT, // 17
} END_ENUM_TYPE;

/*
 * @brief TODO
 */
struct TAIkabekuiCSoundTable : public PaniSoundTable {
	TAIkabekuiCSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIkabekuiCParameters : public TekiParameters {
	TAIkabekuiCParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIkabekuiCStrategy : public YaiStrategy {
	TAIkabekuiCStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIkabekuiCAnimation : public TAIanimation {
	TAIkabekuiCAnimation()
	    : TAIanimation(TEKI_KabekuiC, "tekis/kabekuiC/anims.bun")
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

#endif
