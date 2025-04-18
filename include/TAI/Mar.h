#ifndef _TAI_MAR_H
#define _TAI_MAR_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Amove.h"
#include "TAI/Areaction.h"
#include "TAI/Ajudge.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

/////////// Puffy Blowhog AI Actions ///////////

/*
 * @brief TODO
 */
struct TAImarSoundTable : public PaniSoundTable {
	TAImarSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAImarParameters : public TekiParameters {
	TAImarParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAImarStrategy : public YaiStrategy {
	TAImarStrategy();

	virtual void act(Teki&);                           // _0C
	virtual bool interact(Teki&, TekiInteractionKey&); // _20

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAImarAnimation : public TAIanimation {
	TAImarAnimation()
	    : TAIanimation(TEKI_Mar, "tekis/mar/anims.bun")
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
struct TAIeffectAttackEventCallBackMar : public TAIeffectAttackEventCallBack {
	virtual bool hitCreature(zen::particleGenerator*, TAIeffectAttackParam*, Creature*, Vector3f); // _10
	virtual bool hitMap(TAIeffectAttackParam*);                                                    // _14
	virtual void playEventSound(zen::particleGenerator*, TAIeffectAttackParam*);                   // _18

	// _00     = VTBL
	// _00-_04 = TAIeffectAttackEventCallBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinitMar : public TaiAction {
	inline TAIAinitMar() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingDistanceInTerritoryMar : public TAIAflyingDistanceInTerritory {
	inline TAIAflyingDistanceInTerritoryMar() // TODO: this is a guess
	{
	}

	virtual f32 getVelocity(Teki&); // _20
	virtual f32 getOffset(Teki&);   // _30

	// _04     = VTBL 1
	// _08     = VTBL 2
	// _00-_14 = TAIAflyingDistanceInTerritory
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAfireBreathMar : public TAIAfireBreath {
	inline TAIAfireBreathMar() // TODO: this is a guess
	{
	}

	virtual void start(Teki&);               // _08
	virtual bool act(Teki&);                 // _10
	virtual f32 getPreviousAnimSpeed(Teki&); // _1C
	virtual f32 getAttackAnimSpeed(Teki&);   // _20

	// _04     = VTBL
	// _00-_0C = TAIAfireBreath?
	// TODO: members
};

/**
 * @brief TODO
 */
struct BreathEffect : public zen::CallBack1<Teki&> {
	virtual bool invoke(Teki&); // _08

	// _00     = VTBL
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingDistanceMar : public TAIAflyingDistance {
	inline TAIAflyingDistanceMar() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&);             // _10
	virtual f32 getGoalAreaRange(Teki&); // _28
	virtual f32 getOffset(Teki&);        // _2C

	// _04     = VTBL 1
	// _08     = VTBL 2
	// _00-_10 = FlyingDistance
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAtimerTakeOffMar : public TAIAtimerReaction {
	TAIAtimerTakeOffMar(int nextState)
	    : TAIAtimerReaction(nextState, 0.0f)
	{
	}

	virtual f32 getFrameMax(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAtimerReaction
};

/**
 * @brief TODO
 */
struct TAIAtakeOffMar : public TAIAtakeOff {
	inline TAIAtakeOffMar() // TODO: this is a guess
	{
	}

	virtual void startFlying(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAtakeOff?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAstickingPikiMar : public TAIAstickingPiki {
	inline TAIAstickingPikiMar() // TODO: this is a guess
	{
	}

	virtual int getPikiNum(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAstickingPiki?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickCheckMar : public TAIAflickCheck {
	TAIAflickCheckMar(int nextState) // TODO: check this when used
	    : TAIAflickCheck(nextState, 0)
	{
	}

	virtual int getDamageCountLimit(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAflickCheck?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAlandingMar : public TAIAlanding {
	inline TAIAlandingMar() // TODO: this is a guess
	{
	}

	virtual void landingEffect(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAlanding?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAstickingPikiMarFly : public TAIAstickingPiki {
	inline TAIAstickingPikiMarFly() // TODO: this is a guess
	{
	}

	virtual int getPikiNum(Teki&); // _1C

	// _04     = VTBL
	// _00-_08 = TAIAstickingPiki?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickingMar : public TAIAflicking {
	TAIAflickingMar(int nextState, int motionIdx)
	    : TAIAflicking(nextState, motionIdx)
	{
	}

	virtual void start(Teki&); // _08
	virtual void flick(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAflicking?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickCheckTimerMar : public TaiAction {
	inline TAIAflickCheckTimerMar() // TODO: this is a guess
	    : TaiAction(-1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingBaseMar : public TAIAflyingBase {
	inline TAIAflyingBaseMar(int nextState) // TODO: this is a guess
	    : TAIAflyingBase(nextState)
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
struct TAIAdyingMar : public TAIAdying {
	inline TAIAdyingMar() // TODO: this is a guess
	    : TAIAdying(-1, -1)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

#endif
