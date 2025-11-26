#ifndef _TAI_OTAMA_H
#define _TAI_OTAMA_H

#include "MapCode.h"
#include "NaviMgr.h"
#include "PaniAnimator.h"
#include "SoundMgr.h"
#include "TAI/Aattack.h"
#include "TAI/Amove.h"
#include "TAI/Animation.h"
#include "TAI/Areaction.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"
#include "types.h"
#include "zen/CallBack.h"

/////////// Wolpole AI Actions ///////////

BEGIN_ENUM_TYPE(TAIotamaFloatParams)
enum {
	MinWaitTime = TPF_COUNT, // 50
	MaxWaitTime,             // 51
	COUNT,                   // 52
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAIotamaStateID)
enum {
	Dead         = 0,
	Wait         = 1,
	SetTarget    = 2,
	GoTarget     = 3,
	AppealTarget = 4,
	AppealRun    = 5,
	RunAway      = 6,
	COUNT, // 7
} END_ENUM_TYPE;

/**
 * @brief TODO
 */
struct TAIotamaSoundTable : public PaniSoundTable {
	TAIotamaSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIotamaParameters : public TekiParameters {
	TAIotamaParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIotamaStrategy : public YaiStrategy {
	TAIotamaStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIotamaAnimation : public TAIanimation {
	TAIotamaAnimation()
	    : TAIanimation(TEKI_KabekuiB, "tekis/otama/anims.bun") // yep, really had this.
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
struct TAIArunAwayOtama : public TAIAreserveMotion {
public:
	TAIArunAwayOtama(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAreserveMotion::start(teki);
		setTargetPosition(teki);
		teki.setAnimSpeed(50.0f);
	}
	virtual bool act(Teki& teki) // _10
	{
		bool res = false;
		if (TAIAreserveMotion::act(teki)) {
			if (setTargetPosition(teki)) {
				teki.setManualAnimation(false);
				res = true;
			}
			teki.moveTowardPriorityFaceDir(teki.mTargetPosition, teki.getParameterF(TPF_RunVelocity));
		}

		return res;
	}

protected:
	bool setTargetPosition(Teki& teki)
	{
		Navi* navi = naviMgr->getNavi();
		Vector3f offset;
		bool res = false;
		offset.set(teki.getPosition() - navi->getPosition());
		f32 dist = offset.length();
		if (dist > teki.getParameterF(TPF_VisibleRange)) {
			res = true;

		} else {
			offset.multiply(teki.getParameterF(TPF_SafetyTerritoryRange) / dist);
			teki.mTargetPosition.set(teki.getPosition() + offset);
			if (teki.mTargetPosition.distance(teki.mPersonality->mNestPosition) > teki.getParameterF(TPF_DangerTerritoryRange)) {
				offset.set(teki.mTargetPosition - teki.mPersonality->mNestPosition);
				offset.normalize();
				offset.multiply(teki.getParameterF(TPF_DangerTerritoryRange));
				teki.mTargetPosition.set(teki.mPersonality->mNestPosition + offset);
			}
		}

		return res;
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
};

/**
 * @brief TODO
 */
struct TAIAappealOtama : public TAIAflickingReserveMotion {
public:
	TAIAappealOtama(int nextState, int motionID)
	    : TAIAflickingReserveMotion(nextState, motionID)
	{
	}

protected:
	virtual void flick(Teki& teki) // _1C
	{
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			teki.flick();
			if (teki.mGroundTriangle) {
				if (MapCode::getAttribute(teki.mGroundTriangle) == ATTR_Water) {
					effectMgr->create(EffectMgr::EFF_P_Bubbles, teki.getPosition(), nullptr, nullptr);
					teki.playEventSound(&teki, SE_OTAMA_WATERJUMP);
				} else {
					teki.playEventSound(&teki, SE_OTAMA_JUMP);
				}
			}
		}
	}

	// _04     = VTBL
	// _00-_0C = TAIAflickingReserveMotion?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAsetTargetOtama : public TAIAsetTargetPointCircleRandom {
public:
	TAIAsetTargetOtama(int nextState, int p2)
	    : TAIAsetTargetPointCircleRandom(nextState)
	{
		mNormalNextState = nextState;
		mRareNextState   = p2;
	}

	virtual bool act(Teki& teki) // _10
	{
		bool res = TAIAsetTargetPointCircleRandom::act(teki);
		if (res) {
			if (zen::Rand(100.0f) > 5.0f) {
				mNextState = mNormalNextState;
			} else {
				mNextState = mRareNextState;
			}
		}
		return res;
	}

protected:
	// _04     = VTBL
	// _00-_08 = TAIAsetTargetPointCircleRandom?
	int mNormalNextState; // _08
	int mRareNextState;   // _0C
};

/**
 * @brief TODO
 */
struct TAIAwaitOtama : public TAIAreserveMotion {
public:
	TAIAwaitOtama(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAreserveMotion::start(teki);
		teki.setFrameCounter(0.0f);
		teki.setFrameCounterMax(
		    teki.getParameterF(TAIotamaFloatParams::MinWaitTime)
		    + zen::Rand(teki.getParameterF(TAIotamaFloatParams::MaxWaitTime) - teki.getParameterF(TAIotamaFloatParams::MinWaitTime)));
	}
	virtual bool act(Teki& teki) // _10
	{
		bool res = false;
		if (TAIAreserveMotion::act(teki)) {
			teki.addFrameCounter(gsys->getFrameTime());
		}
		teki.mTargetVelocity.x *= 0.95f;
		teki.mTargetVelocity.z *= 0.95f;
		teki.mVelocity = teki.mTargetVelocity;
		if (teki.getFrameCounter() > teki.getFrameCounterMax() && zen::Abs(teki.mTargetVelocity.x) < 0.1f
		    && zen::Abs(teki.mTargetVelocity.z) < 0.1f) {
			res = true;
		}
		return res;
	}

protected:
	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

#endif
