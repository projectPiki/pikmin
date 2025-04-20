#ifndef _TAI_TANK_H
#define _TAI_TANK_H

#include "types.h"
#include "TAI/Aattack.h"
#include "TAI/Amove.h"
#include "TAI/Ajudge.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

/////////// Fiery Blowhog AI Actions ///////////

/*
 * @brief TODO
 */
struct TAItankSoundTable : public PaniSoundTable {
	TAItankSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAItankParameters : public TekiParameters {
	TAItankParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAItankStrategy : public YaiStrategy {
	TAItankStrategy();

	virtual void act(Teki&);                           // _0C
	virtual bool interact(Teki&, TekiInteractionKey&); // _20

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAItankAnimation : public TAIanimation {
	TAItankAnimation()
	    : TAIanimation(TEKI_Tank, "tekis/tank/anims.bun")
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
struct TAIeffectAttackEventCallBackTank : public TAIeffectAttackEventCallBack {
	virtual bool hitCreature(TAIeffectAttackParam*, Creature*);                  // _08
	virtual bool hitMap(TAIeffectAttackParam*);                                  // _14
	virtual void playEventSound(zen::particleGenerator*, TAIeffectAttackParam*); // _18
	virtual void ptclHitMap(zen::particleGenerator*, TAIeffectAttackParam*);     // _1C

	// _00     = VTBL
	// _00-_04 = TAIeffectAttackEventCallBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinitTank : public TaiAction {
	inline TAIAinitTank() // TODO: this is a guess
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
struct TAIAflickingTank : public TAIAflicking {
	TAIAflickingTank(int nextState, int motionIdx)
	    : TAIAflicking(nextState, motionIdx)
	{
	}

	virtual f32 getFlickDirection(Teki&); // _20

	// _04     = VTBL
	// _00-_0C = TAIAflicking?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAfireBreathTank : public TAIAfireBreath {
	inline TAIAfireBreathTank(int nextState, int motionID, zen::CallBack1<Teki&>* cb)
	    : TAIAfireBreath(nextState, motionID, cb)
	{
	}

	virtual void start(Teki&);               // _08
	virtual f32 getPreviousAnimSpeed(Teki&); // _1C
	virtual f32 getAttackAnimSpeed(Teki&);   // _20

	// _04     = VTBL
	// _00-_0C = TAIAfireBreath?
	// TODO: members
};

/**
 * @brief TODO
 */
struct FireEffect : public zen::CallBack1<Teki&> {
	virtual bool invoke(Teki&); // _08

	// _00     = VTBL
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAstepBackTank : public TAIAstepBack {
	inline TAIAstepBackTank() // TODO: this is a guess
	{
	}

	virtual bool act(Teki&);        // _10
	virtual f32 getVelocity(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAstepBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAoutsideOptionalRangeTank : public TAIAoutsideOptionalRange {
	inline TAIAoutsideOptionalRangeTank() // TODO: this is a guess
	{
	}

	virtual bool setTargetPosition(Teki&); // _1C
	virtual f32 getOptionalRange(Teki&);   // _20

	// _04     = VTBL
	// _00-_0C = TAIAoutsideOptionalRange?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIApatrolTank : public TAIApatrol {
	inline TAIApatrolTank() // TODO: this is a guess
	    : TAIApatrol(0, 0, 0, 0, nullptr, 0, false)
	{
	}

	virtual bool act(Teki&);       // _10
	virtual f32 getTimeout(Teki&); // _20

	// _04     = VTBL
	// _00-_08 = TAIAattackableTarget?
	// TODO: members
};

#endif
