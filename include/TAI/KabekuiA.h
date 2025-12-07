#ifndef _TAI_KABEKUIA_H
#define _TAI_KABEKUIA_H

#include "types.h"

#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"

/////////// Female Sheargrub (ウジンコ♀) ///////////

/**
 * @brief
 */
BEGIN_ENUM_TYPE(TAIkabekuiAFloatParms)
enum {
	BridgeAttackRange = TPF_COUNT,
	BridgeDamage,
	TimeUntilBurrow,
	MaxSleepTime,
	COUNT,
} END_ENUM_TYPE;

/**
 * @brief
 */
BEGIN_ENUM_TYPE(TAIkabekuiAStateID)
enum {
	Dying        = 0,
	Waiting      = 1,
	Appearing    = 2,
	MovingSetup  = 3,
	Moving       = 4,
	CrushDying   = 5,
	ChasingSetup = 6,
	Chasing      = 7,
	EatingBridge = 8,
	Burrowing    = 9,
	WaitingSetup = 10,
	COUNT,
} END_ENUM_TYPE;

/*
 * @brief TODO
 */
struct TAIkabekuiASoundTable : public PaniSoundTable {
	TAIkabekuiASoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIkabekuiAParameters : public TekiParameters {
	TAIkabekuiAParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIkabekuiAStrategy : public YaiStrategy {
	TAIkabekuiAStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIkabekuiAAnimation : public TAIanimation {
	TAIkabekuiAAnimation()
	    : TAIanimation(TEKI_KabekuiA, "tekis/kabekuiA/anims.bun")
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

#endif
