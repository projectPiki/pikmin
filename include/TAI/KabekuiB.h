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
#include "PlayerState.h"
#include "SoundID.h"

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
	Unk0  = 0,
	Unk1  = 1,
	Unk2  = 2,
	Unk3  = 3,
	Unk4  = 4,
	Unk5  = 5,
	Unk6  = 6,
	Unk7  = 7,
	Unk8  = 8,
	Unk9  = 9,
	Unk10 = 10,
	Unk11 = 11,
	Unk12 = 12,
	Unk13 = 13,
	COUNT, // 14
} END_ENUM_TYPE;

/**
 * @brief
 */
BEGIN_ENUM_TYPE(TAIkabekuiBMotionID)
enum {
	Unk0  = 0,  // 'dead'
	Unk1  = 1,  // 'damage'
	Unk4  = 4,  // 'waitact1'
	Unk5  = 5,  // 'waitact2'
	Unk6  = 6,  // 'move1'
	Unk8  = 8,  // 'attack'
	Unk10 = 10, //
	Unk11 = 11, //
} END_ENUM_TYPE;

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
	    : TAIAtimerReaction(nextState, 3.0f)
	{
	}

	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiBFloatParms::MaxSleepTime);
	}

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdiveKabekuiB : public TAIAtimerReaction {
	TAIAdiveKabekuiB(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
	{
	}

	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiBFloatParms::TimeUntilBurrow);
	}

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAattackWorkObjectKabekuiB : public TAIAattackWorkObject {
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
	// _00-_08 = TAIAattackWorkObject?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAbiteForKabekuiB : public TAIAbiteForKabekui {
	inline TAIAbiteForKabekuiB(int nextState, int p2, int motionID) // TODO: this is a guess
	    : TAIAbiteForKabekui(nextState, p2, motionID)
	{
	}

	virtual f32 getPikiAttackSize(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiBFloatParms::PikiAttackRange);
	}

	virtual f32 getNaviAttackSize(Teki& teki) // _20
	{
		return teki.getParameterF(TAIkabekuiBFloatParms::NaviAttackRange);
	}

	// _04     = VTBL
	// _00-_08 = TAIAbiteForKabekui?
	// TODO: members
};

#endif
