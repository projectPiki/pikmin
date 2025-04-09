#ifndef _TAI_KABEKUIC_H
#define _TAI_KABEKUIC_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Areaction.h"
#include "TAI/Amove.h"
#include "TAI/Ajudge.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "zen/particle.h"
#include "PaniAnimator.h"

/////////// Shearwig AI Actions ///////////

namespace {

/*
 * @brief TODO
 */
struct rippleEffect : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator*); // _08

	// TODO: members
};

} // namespace

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

/**
 * @brief TODO
 */
struct TAIAsleepKabekuiC : public TAIAtimerReaction {
	TAIAsleepKabekuiC(int nextState)
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
struct TAIAdiveKabekuiC : public TAIAtimerReaction {
	TAIAdiveKabekuiC(int nextState)
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
struct TAIAattackWorkObjectKabekuiC : public TAIAattackWorkObject {
	inline TAIAattackWorkObjectKabekuiC() // TODO: this is a guess
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
struct TAIAlandingKabekuiC : public TAIAreserveMotion {
	inline TAIAlandingKabekuiC() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAmoreLifeKabekuiC : public TAIAmoreLife {
	inline TAIAmoreLifeKabekuiC() // TODO: this is a guess
	{
	}

	virtual f32 getLifePercentThreshold(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAmoreLife?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAlessLifeKabekuiC : public TAIAlessLife {
	inline TAIAlessLifeKabekuiC() // TODO: this is a guess
	{
	}

	virtual f32 getLifePercentThreshold(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAmoreLife?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckPikiFlyKabekuiC : public TAIAhitCheckFlyingPiki {
	inline TAIAcheckPikiFlyKabekuiC() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TAIAhitCheckFlyingPiki?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingMotionKabekuiC : public TAIAreserveMotion {
	inline TAIAflyingMotionKabekuiC() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingBaseKabekuiC : public TAIAflyingBase {
	inline TAIAflyingBaseKabekuiC() // TODO: this is a guess
	{
	}

	virtual f32 getFlyingStayVelocity(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAflyingBase?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtakeOffKabekuiC : public TAIAreserveMotion {
	inline TAIAtakeOffKabekuiC() // TODO: this is a guess
	    : TAIAreserveMotion(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAbiteForKabekuiC : public TAIAbiteForKabekui {
	inline TAIAbiteForKabekuiC() // TODO: this is a guess
	{
	}

	virtual f32 getPikiAttackSize(Teki&); // _1C
	virtual f32 getNaviAttackSize(Teki&); // _20

	// _04     = VTBL
	// _00-_08 = TAIAbiteForKabekui?
	// TODO: members
};

#endif
