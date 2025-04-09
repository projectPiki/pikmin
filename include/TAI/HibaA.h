#ifndef _TAI_HIBAA_H
#define _TAI_HIBAA_H

#include "types.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "TAI/Animation.h"
#include "YaiStrategy.h"
#include "zen/CallBack.h"
#include "PaniAnimator.h"

/////////// Fire Geyser AI Actions ///////////

/*
 * @brief TODO
 */
struct TAIhibaASoundTable : public PaniSoundTable {
	TAIhibaASoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIhibaAParameters : public TekiParameters {
	TAIhibaAParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIhibaAStrategy : public YaiStrategy {
	TAIhibaAStrategy();

	virtual void act(Teki&);             // _0C
	virtual void draw(Teki&, Graphics&); // _18

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIhibaAAnimation : public TAIanimation {
	TAIhibaAAnimation()
	    : TAIanimation(TEKI_KabekuiB, "tekis/hibaA/anims.bun") // yep, really had this.
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
struct TAIeffectAttackEventCallBackHibaA : public TAIeffectAttackEventCallBack {
	virtual bool hitCreature(TAIeffectAttackParam*, Creature*);                              // _08
	virtual bool hitMap(TAIeffectAttackParam*);                                              // _14
	virtual void ptclHitMap(zen::particleGenerator*, TAIeffectAttackParam*);                 // _1C
	virtual bool hitCheckCulling(zen::particleGenerator*, TAIeffectAttackParam*, Creature*); // _20

	// _00     = VTBL
	// _00-_04 = TAIeffectAttackEventCallBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinitHibaA : public TaiAction {
	inline TAIAinitHibaA() // TODO: this is a guess
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
struct TAIAfireAttackHibaA : public TAIAreserveMotion {
	inline TAIAfireAttackHibaA() // TODO: this is a guess
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
struct TAIAtimerReactionHibaA : public TAIAtimerReaction {
	TAIAtimerReactionHibaA(int nextState)
	    : TAIAtimerReaction(nextState, 0.0f)
	{
	}

	virtual f32 getFrameMax(Teki&); // _1C

	// _04     = VTBL
	// _00-_0C = TAIAtimerReaction?
	// TODO: members
};

#endif
