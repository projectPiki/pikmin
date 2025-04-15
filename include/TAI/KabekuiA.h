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

/**
 * @brief
 */
DEFINE_ENUM_TYPE(TAIkabekuiAFloatParms, BridgeAttackRange = TPF_COUNT, BridgeDamage, BurrowingTime, SleepTime, COUNT, );

/**
 * @brief
 */
DEFINE_ENUM_TYPE(TAIkabekuiAStateID,
                 Dying        = 0,  //
                 Waiting      = 1,  //
                 Appearing    = 2,  //
                 MovingSetup  = 3,  //
                 Moving       = 4,  //
                 CrushDying   = 5,  //
                 ChasingSetup = 6,  //
                 Chasing      = 7,  //
                 Eating       = 8,  //
                 Burrowing    = 9,  //
                 WaitingSetup = 10, //
                 COUNT,             //
);

/**
 * @brief
 */
DEFINE_ENUM_TYPE(TAIkabekuiAMotionID,
                 Dead   = 0, // 'dead'
                 Press  = 1, // 'damage'
                 Appear = 4, // 'waitact1'
                 Burrow = 5, // 'waitact2'
                 Move   = 6, // 'move1'
                 Eat    = 8, // 'attack'
);

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

/**
 * @brief TODO
 */
struct TAIAsleepKabekuiA : public TAIAtimerReaction {
	TAIAsleepKabekuiA(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
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
	TAIAdiveKabekuiA(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
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
	inline TAIAattackWorkObjectKabekuiA(int nextState, int motionID, int p3) // TODO: this is a guess
	    : TAIAattackWorkObject(nextState, motionID, p3)
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
