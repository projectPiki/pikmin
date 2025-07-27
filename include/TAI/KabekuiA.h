#ifndef _TAI_KABEKUIA_H
#define _TAI_KABEKUIA_H

#include "PaniAnimator.h"
#include "PlayerState.h"
#include "SoundID.h"
#include "TAI/Aattack.h"
#include "TAI/Animation.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"
#include "types.h"
#include "zen/CallBack.h"

/////////// Female Sheargrub AI Actions ///////////

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

/**
 * @brief
 */
BEGIN_ENUM_TYPE(TAIkabekuiAMotionID)
enum {
	Dead   = 0, // 'dead'
	Press  = 1, // 'damage'
	Appear = 4, // 'waitact1'
	Burrow = 5, // 'waitact2'
	Move   = 6, // 'move1'
	Eat    = 8, // 'attack'
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

/**
 * @brief TODO
 */
struct TAIAsleepKabekuiA : public TAIAtimerReaction {
public:
	TAIAsleepKabekuiA(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
	{
	}

protected:
	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiAFloatParms::MaxSleepTime);
	}

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdiveKabekuiA : public TAIAtimerReaction {
public:
	TAIAdiveKabekuiA(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
	{
	}

protected:
	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiAFloatParms::TimeUntilBurrow);
	}

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAattackWorkObjectKabekuiA : public TAIAattackWorkObject {
public:
	inline TAIAattackWorkObjectKabekuiA(int nextState, int motionID, int p3) // TODO: this is a guess
	    : TAIAattackWorkObject(nextState, motionID, p3)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAattackWorkObject::start(teki);
	}

	virtual bool act(Teki& teki) // _10
	{
		return TAIAattackWorkObject::act(teki);
	}

protected:
	virtual f32 getDamage(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiAFloatParms::BridgeDamage);
	}

	virtual f32 getAttackPointRadius(Teki& teki) // _20
	{
		return teki.getParameterF(TAIkabekuiAFloatParms::BridgeAttackRange);
	}

	virtual void attackEffect(Teki& teki) // _24
	{
		CollPart* mouthSlot = teki.mCollInfo->getSphere('slot');
		if (mouthSlot == nullptr) {
			return;
		}

		if (teki.mCurrentAnimEvent == KEY_Action0) {
			zen::particleGenerator* generator = effectMgr->create(
			    EffectMgr::EFF_Kabekui_EatBridgeA, mouthSlot->getChildAt(mouthSlot->getChildCount() - 1)->mCentre, nullptr, nullptr);
			if (generator != nullptr) {
				generator->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
			}

			teki.playEventSound(&teki, SE_WALLEAT_EAT);
			if (teki.aiCullable()) {
				playerState->mResultFlags.setOn(RESFLAG_Kabekui);
			}
		}

		if (teki.mCurrentAnimEvent != KEY_Action1 && teki.mCurrentAnimEvent == KEY_Action2) {
			zen::particleGenerator* generator = effectMgr->create(
			    EffectMgr::EFF_Kabekui_EatBridgeB, mouthSlot->getChildAt(mouthSlot->getChildCount() - 1)->mCentre, nullptr, nullptr);
			if (generator != nullptr) {
				generator->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
			}
		}
	}

	// _04     = VTBL
	// _00-_08 = TAIAattackWorkObject?
	// TODO: members
};

#endif
