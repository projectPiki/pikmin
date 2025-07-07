#ifndef _TAI_DORORO_H
#define _TAI_DORORO_H

#include "NaviMgr.h"
#include "PaniAnimator.h"
#include "Pellet.h"
#include "PikiHeadItem.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "TAI/Aattack.h"
#include "TAI/Amove.h"
#include "TAI/Animation.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiConditions.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"
#include "types.h"
#include "zen/CallBack.h"

struct CollPart;

/////////// Smoky Progg AI Actions ///////////

/**
 * @brief TODO
 */
enum TAIdororoStateID {
	DOROROSTATE_Dead         = 0,
	DOROROSTATE_Init         = 1,
	DOROROSTATE_Birth        = 2,
	DOROROSTATE_GoGoalPath   = 3,
	DOROROSTATE_Flick        = 4,
	DOROROSTATE_Wait         = 5,
	DOROROSTATE_LookAround   = 6,
	DOROROSTATE_GoTargetPiki = 7,
	DOROROSTATE_Transform    = 8,
	DOROROSTATE_BarkGoal     = 9,
	DOROROSTATE_Bark         = 10,
	DOROROSTATE_Idle         = 11,
	DOROROSTATE_COUNT, // 12
};

/**
 * @brief TODO
 */
enum TAIdororoIntParams {
	DOROROPI_MaxPikminKill = TPI_COUNT, // 20
	DOROROPI_COUNT,                     // 21
};

/**
 * @brief TODO
 */
enum TAIdororoFloatParams {
	DOROROPF_MinLifespan = TPF_COUNT, // 50
	DOROROPF_RandomLifespan,          // 51
	DOROROPF_PikiNumForMaxDrag,       // 52, bigger = need more pikis stuck to slow the progg down
	DOROROPF_WalkingSpeedDragFactor,  // 53, bigger = more overall drag when any pikis are stuck
	DOROROPF_WaitTime,                // 54
	DOROROPF_COUNT,                   // 55
};

/**
 * @brief TODO
 */
struct TAIdororoSoundTable : public PaniSoundTable {
	TAIdororoSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIdororoParameters : public TekiParameters {
	TAIdororoParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct TAIdororoStrategy : public YaiStrategy {
	TAIdororoStrategy();

	virtual void start(Teki&);             // _08
	virtual void act(Teki&);               // _0C
	virtual void createEffect(Teki&, int); // _14
	virtual void draw(Teki&, Graphics&);   // _18

	void createCloudOfDust(Teki&, CollPart*);

	// _00     = VTBL
	// _00-_10 = YaiStrategy
	CollPart* mLeftHand;  // _10
	CollPart* mRightHand; // _14
};

/**
 * @brief TODO
 */
struct TAIdororoAnimation : public TAIanimation {
	TAIdororoAnimation()
	    : TAIanimation(TEKI_Dororo, "tekis/dororo/anims.bun")
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
struct TAIAinitDororo : public TaiAction {
	TAIAinitDororo(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.mCollisionRadius = 64.0f;
		teki.mPathHandle      = 'test';
		teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
		teki.setDesire(0.0f);
	}
	virtual bool act(Teki& teki) { return true; } // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgravityDororo : public TaiAction {
	TAIAgravityDororo(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.setDororoGravity(gsys->getFrameTime() * 0.98f);
	}
	virtual bool act(Teki& teki) // _10
	{
		if (teki.getYFromSeaLevel() > 0.0f) {
			teki.mTargetVelocity.y -= teki.getDororoGravity();
		} else {
			teki.mTargetVelocity.y = 0.0f;
		}

		teki.mVelocity.y = teki.mTargetVelocity.y;
		return false;
	}

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckBarkDororo : public TaiAction {
	TAIAcheckBarkDororo(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		bool doBark = false;
		Iterator iter(itemMgr->getPikiHeadMgr());
		CI_LOOP(iter)
		{
			Creature* sprout = *iter;
			if (sprout && sprout->getPosition().distance(teki.getPosition()) < teki.getParameterF(TPF_VisibleRange)) {
				teki.addDesire(gsys->getFrameTime());
			}
		}

		if (teki.getDesire() > 4.0f) {
			teki.setDesire(0.0f);
			doBark = true;
		}

		return doBark;
	}

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note This is defined in TAIdororo.cpp cause it needs to use the PRINT function in that file, sigh.
 */
struct TAIAbarkDororo;

/**
 * @brief TODO
 *
 * @note This is defined in TAIdororo.cpp cause it needs to use the ERROR function in that file, sigh.
 */
struct TAIAtransformationDororo;

/**
 * @brief TODO
 *
 * @note This is defined in TAIdororo.cpp cause it needs to use the PRINT function in that file, sigh.
 */
struct TAIAbirthDororo;

/**
 * @brief TODO
 */
struct TAIAwaitDororo : public TAIAwait {
	TAIAwaitDororo(int nextState, int motionIdx)
	    : TAIAwait(nextState, motionIdx, 0.0f)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAwait::start(teki);
		teki.setFrameCounterMax(teki.getParameterF(DOROROPF_WaitTime) + zen::Rand(teki.getParameterF(DOROROPF_WaitTime)));
	}
	virtual f32 getWaitCounterMax(Teki& teki) { return teki.getFrameCounterMax(); } // _1C

	// _04     = VTBL
	// _00-_08 = TAIAwait?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickingDororo : public TAIAflicking {
	TAIAflickingDororo(int nextState, int motionIdx)
	    : TAIAflicking(nextState, motionIdx)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAflicking::start(teki);
		if (teki.isNaviWatch()) {
			playerState->mResultFlags.setOn(RESFLAG_Dororo);
		}
	}
	virtual bool act(Teki& teki) // _10
	{
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			teki.playEventSound(&teki, SE_DORORO_SWING);
		}
		return TAIAflicking::act(teki);
	}

	// _04     = VTBL
	// _00-_08 = TAIAflicking?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoGoalPathDororo : public TAIAgoGoalPath {
	TAIAgoGoalPathDororo(int nextState, int motionIdx)
	    : TAIAgoGoalPath(nextState, motionIdx)
	{
	}

	virtual f32 getWalkVelocity(Teki& teki) // _20
	{
		int pikiCount   = teki.countPikis(TekiStickerCondition(&teki));
		f32 speedFactor = f32(pikiCount) / teki.getParameterF(DOROROPF_PikiNumForMaxDrag);
		if (speedFactor > 1.0f) {
			speedFactor = 1.0f;
		}

		speedFactor = (1.0f - teki.getParameterF(DOROROPF_WalkingSpeedDragFactor) * speedFactor);

		return teki.getParameterF(TPF_WalkVelocity) * speedFactor;

		TekiStickerCondition(nullptr);
	}

	// _04     = VTBL
	// _00-_08 = TAIAgoGoalPath?
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note This is defined in TAIdororo.cpp because it needs to use the ERROR function in that file, sigh.
 */
struct TAIAkillTouchPiki;

/**
 * @brief TODO
 *
 * @note This is defined in TAIdororo.cpp because it needs to use the anonymous namespace functions in that file, sigh.
 */
struct TAIAdyingDororo;

#endif
