#ifndef _TAI_TAMAGO_H
#define _TAI_TAMAGO_H

#include "PaniAnimator.h"
#include "Pcam/CameraManager.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "TAI/Aattack.h"
#include "TAI/Animation.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"
#include "types.h"
#include "zen/CallBack.h"
#include "zen/Math.h"

/////////// Giant Egg AI Actions ///////////

/**
 * @brief TODO
 */
enum TAItamagoStateID {
	TAMAGOSTATE_Dead      = 0,
	TAMAGOSTATE_Wait      = 1,
	TAMAGOSTATE_CountDown = 2,
	TAMAGOSTATE_Hatch     = 3,
	TAMAGOSTATE_COUNT, // 4
};

/**
 * @brief TODO
 */
enum TAItamagoFloatParams {
	TAMAGOPF_MinEmergenceTime = TPF_COUNT, // 50
	TAMAGOPF_MaxEmergenceTime,             // 51
	TAMAGOPF_COUNT,                        // 52
};

/**
 * @brief TODO
 */
struct TAItamagoSoundTable : public PaniSoundTable {
	TAItamagoSoundTable();

	// _00-_08 = PaniSoundTable
};

/**
 * @brief TODO
 */
struct TAItamagoParameters : public TekiParameters {
	TAItamagoParameters();

	// _00     = VTBL
	// _00-_88 = TekiParameters
};

/**
 * @brief TODO
 */
struct TAItamagoStrategy : public YaiStrategy {
	TAItamagoStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy
};

/**
 * @brief TODO
 */
struct TAItamagoAnimation : public TAIanimation {
	TAItamagoAnimation()
	    : TAIanimation(TEKI_KabekuiB, "tekis/tamago/anims.bun") // yep, they really had this
	{
	}

	virtual void makeDefaultAnimations(); // _08

	// _0C     = VTBL
	// _00-_0C = TAIanimation
};

/**
 * @brief TODO
 */
struct TAIAcountStartTamago : public TaiAction {
	TAIAcountStartTamago(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		return teki.isNaviWatch();
	}

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TAIAhatch : public TAIAmotion {
	TAIAhatch(int nextState, int motionIdx)
	    : TAIAmotion(nextState, motionIdx)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAmotion::start(teki);
		teki.disableStick();
		teki.setTekiOption(BTeki::TEKI_OPTION_INVINCIBLE);
	}
	virtual bool act(Teki& teki) // _10
	{
		bool res = false;
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			birth(teki);
			teki.flick();
		}
		if (teki.mCurrentAnimEvent == KEY_Finished) {
			teki.die();
			res = true;
		}

		return res;
	}

	void birth(Teki& teki)
	{
		Vector3f effPos(teki.getPosition());
		effPos.y += 35.0f;
		effectMgr->create(EffectMgr::EFF_Tamago_DeadFragments, effPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Tamago_DeadSmoke, effPos, nullptr, nullptr);
		teki.flick();
		teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
		teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
		teki.mPlatMgr.release();

		teki.spawnTeki(teki.getParameterI(TPI_SpawnType));
		teki.playEventSound(&teki, SE_DORORO_EGG_CRASH);
		cameraMgr->startVibrationEvent(2, teki.getPosition());
		rumbleMgr->start(RUMBLE_Unk11, 0, teki.getPosition());
	}

	// _04     = VTBL
	// _00-_0C = TAIAmotion
};

/**
 * @brief TODO
 */
struct TAIAtimerReactionTamago : public TAIAtimerReaction {
	TAIAtimerReactionTamago(int nextState)
	    : TAIAtimerReaction(nextState, 0.0f)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.setFrameCounter(0.0f);
		teki.setFrameCounterMax(teki.getParameterF(TAMAGOPF_MinEmergenceTime)
		                        + zen::Rand(teki.getParameterF(TAMAGOPF_MaxEmergenceTime) - teki.getParameterF(TAMAGOPF_MinEmergenceTime)));
	}
	virtual bool act(Teki& teki) // _10
	{
		return TAIAtimerReaction::act(teki);
	}
	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getFrameCounterMax();
	}

	// _04     = VTBL
	// _00-_0C = TAIAtimerReaction
};

/**
 * @brief TODO
 */
struct TAIAdyingTamago : public TAIAmotion {
	TAIAdyingTamago(int nextState, int motionIdx)
	    : TAIAmotion(nextState, motionIdx)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAmotion::start(teki);
		teki.disableStick();
		teki.setTekiOption(BTeki::TEKI_OPTION_INVINCIBLE);
		teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
	}
	virtual bool act(Teki& teki) // _10
	{
		bool res = false;
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			Vector3f effPos(teki.getPosition());
			effPos.y += 35.0f;
			effectMgr->create(EffectMgr::EFF_Tamago_DeadFragments, effPos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Tamago_EyeGlow, effPos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Tamago_DeadFumes, effPos, nullptr, nullptr);
			teki.playEventSound(&teki, SE_DORORO_EGG_CRASH);
		}
		if (teki.mCurrentAnimEvent == KEY_Finished) {
			teki.die();
			res = true;
		}

		return res;
	}

	// _04     = VTBL
	// _00-_0C = TAIAmotion
	// TODO: members
};

#endif
