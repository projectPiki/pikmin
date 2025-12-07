#ifndef _TAI_KABEKUIB_H
#define _TAI_KABEKUIB_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

/////////// Male Sheargrub AI Actions ///////////

/**
 * @brief
 */
BEGIN_ENUM_TYPE(TAIkabekuiBFloatParms)
enum {
	BridgeAttackRange = TPF_COUNT,
	BridgeDamage,
	TimeUntilBurrow,
	MaxSleepTime,
	PikiAttackRange,
	NaviAttackRange,
	COUNT, // 56
} END_ENUM_TYPE;

/**
 * @brief
 */
BEGIN_ENUM_TYPE(TAIkabekuiBStateID)
enum {
	Dying        = 0,
	Waiting      = 1,
	Appearing    = 2,
	MovingSetup  = 3,
	MovingBridge = 4,
	MovingPiki   = 5,
	BiteAttack   = 6,
	BiteChewing  = 7,
	CrushDying   = 8,
	ChasingSetup = 9,
	Chasing      = 10,
	EatingBridge = 11,
	Burrowing    = 12,
	WaitingSetup = 13,
	COUNT, // 14
} END_ENUM_TYPE;

/*
 * @brief TODO
 */
struct TAIkabekuiBSoundTable : public PaniSoundTable {
	TAIkabekuiBSoundTable();

	// _00-_08 = PaniSoundTable
};

/*
 * @brief TODO
 */
struct TAIkabekuiBParameters : public TekiParameters {
	TAIkabekuiBParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters
};

/*
 * @brief TODO
 */
struct TAIkabekuiBStrategy : public YaiStrategy {
	TAIkabekuiBStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy
};

/**
 * @brief TODO
 */
struct TAIkabekuiBAnimation : public TAIanimation {
	TAIkabekuiBAnimation()
	    : TAIanimation(TEKI_KabekuiB, "tekis/kabekuiB/anims.bun")
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
};

#endif
