#ifndef _TAI_KABEKUIB_H
#define _TAI_KABEKUIB_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

/////////// Male Sheargrub AI Actions ///////////

/*
 * @brief TODO
 */
struct TAIkabekuiBSoundTable : public PaniSoundTable {
	TAIkabekuiBSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIkabekuiBParameters : public TekiParameters {
	TAIkabekuiBParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIkabekuiBStrategy : public YaiStrategy {
	TAIkabekuiBStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAsleepKabekuiB : public TAIAtimerReaction {
	TAIAsleepKabekuiB(int nextState)
	    : TAIAtimerReaction(nextState, 0.0f)
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
struct TAIAdiveKabekuiB : public TAIAtimerReaction {
	TAIAdiveKabekuiB(int nextState)
	    : TAIAtimerReaction(nextState, 0.0f)
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
struct TAIAattackWorkObjectKabekuiB : public TAIAattackWorkObject {
	inline TAIAattackWorkObjectKabekuiB() // TODO: this is a guess
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

/**
 * @brief TODO
 */
struct TAIAbiteForKabekuiB : public TAIAbiteForKabekui {
	inline TAIAbiteForKabekuiB() // TODO: this is a guess
	{
	}

	virtual f32 getPikiAttackSize(Teki&); // _1C
	virtual f32 getNaviAttackSize(Teki&); // _20

	// _04     = VTBL
	// _00-_08 = TAIAbiteForKabekui?
	// TODO: members
};

#endif
