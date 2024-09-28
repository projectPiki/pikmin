#ifndef _TAI_KABEKUIA_H
#define _TAI_KABEKUIA_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

/////////// Female Sheargrub AI Actions ///////////

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
	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAsleepKabekuiA : public TAIAtimerReaction {
	inline TAIAsleepKabekuiA() // TODO: this is a guess
	{
	}

	virtual f32 getFrameMax(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdiveKabekuiA : public TAIAtimerReaction {
	inline TAIAdiveKabekuiA() // TODO: this is a guess
	{
	}

	virtual f32 getFrameMax(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAattackWorkObjectKabekuiA : public TAIAattackWorkObject {
	inline TAIAattackWorkObjectKabekuiA() // TODO: this is a guess
	{
	}

	virtual void start(Teki&);               // _08
	virtual bool act(Teki&);                 // _10
	virtual f32 getDamage(Teki&);            // _1C
	virtual f32 getAttackPointRadius(Teki&); // _20
	virtual void attackEffect(Teki&);        // _24

	// _04     = VTBL
	// _00-_08 = TAIAattackWorkObject?
	// TODO: members
};

#endif
