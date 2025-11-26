#ifndef _TAI_KABEKUIB_H
#define _TAI_KABEKUIB_H

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

/**
 * @brief TODO
 */
struct TAIAsleepKabekuiB : public TAIAtimerReaction {
public:
	TAIAsleepKabekuiB(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
	{
	}

protected:
	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiBFloatParms::MaxSleepTime);
	}

	// _04     = VTBL
	// _00-_0C = TAIAtimerReaction
};

/**
 * @brief TODO
 */
struct TAIAdiveKabekuiB : public TAIAtimerReaction {
public:
	TAIAdiveKabekuiB(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
	{
	}

protected:
	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiBFloatParms::TimeUntilBurrow);
	}

	// _04     = VTBL
	// _00-_0C = TAIAtimerReaction
};

/**
 * @brief TODO
 */
struct TAIAattackWorkObjectKabekuiB : public TAIAattackWorkObject {
public:
	inline TAIAattackWorkObjectKabekuiB(int nextState, int motionID, int p3) // TODO: this is a guess
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
		return teki.getParameterF(TAIkabekuiBFloatParms::BridgeDamage);
	}

	virtual f32 getAttackPointRadius(Teki& teki) // _20
	{
		return teki.getParameterF(TAIkabekuiBFloatParms::BridgeAttackRange);
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
	// _00-_14 = TAIAattackWorkObject
};

/**
 * @brief TODO
 */
struct TAIAbiteForKabekuiB : public TAIAbiteForKabekui {
public:
	inline TAIAbiteForKabekuiB(int nextState, int p2, int motionID) // TODO: this is a guess
	    : TAIAbiteForKabekui(nextState, p2, motionID)
	{
	}

protected:
	virtual f32 getPikiAttackSize(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiBFloatParms::PikiAttackRange);
	}

	virtual f32 getNaviAttackSize(Teki& teki) // _20
	{
		return teki.getParameterF(TAIkabekuiBFloatParms::NaviAttackRange);
	}

	// _04     = VTBL
	// _00-_014 = TAIAbiteForKabekui?
	// TODO: members
};

#endif
