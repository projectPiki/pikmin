#ifndef _TAI_KABEKUIC_H
#define _TAI_KABEKUIC_H

#include "MapCode.h"
#include "PaniAnimator.h"
#include "PlayerState.h"
#include "SoundID.h"
#include "TAI/Aattack.h"
#include "TAI/Ajudge.h"
#include "TAI/Amove.h"
#include "TAI/Animation.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"
#include "types.h"
#include "zen/CallBack.h"
#include "zen/particle.h"

/////////// Shearwig AI Actions ///////////

BEGIN_ENUM_TYPE(TAIkabekuiCFloatParms)
enum {
	BridgeAttackRange = TPF_COUNT,
	BridgeDamage,
	FlightAlertLifePercent,
	MaxFlightLifePercent,
	FlightYVelocity,
	TakeoffYVelocity,
	TimeUntilBurrow,
	MaxSleepTime,
	PikiAttackRange,
	NaviAttackRange,
	COUNT,
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAIkabekuiCStateID)
enum {
	Dying        = 0,
	Waiting      = 1,
	Appearing    = 2,
	MovingSetup  = 3,
	MovingBridge = 4,
	MovingPiki   = 5,
	BiteAttack   = 6,
	BiteChewing  = 7,
	Takeoff      = 8,
	Flying       = 9,
	Landing      = 10,
	CrushDying   = 11,
	ChasingSetup = 12,
	Chasing      = 13,
	EatingBridge = 14,
	Burrowing    = 15,
	WaitingSetup = 16,
	COUNT, // 17
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAIkabekuiCMotionID)
enum {
	Unk0  = 0, // 'dead'
	Unk1  = 1, // 'damage'
	Unk3  = 3,
	Unk4  = 4,  // 'waitact1'
	Unk5  = 5,  // 'waitact2'
	Unk6  = 6,  // 'move1'
	Unk8  = 8,  // 'attack'
	Unk10 = 10, //
	Unk11 = 11, //
	Unk12 = 12, //
	Unk13 = 13, //
} END_ENUM_TYPE;

namespace {

/*
 * @brief TODO
 */
struct rippleEffect : public zen::CallBack1<zen::particleGenerator*> {
	virtual bool invoke(zen::particleGenerator* generator) // _08
	{
		if (generator->getCurrentFrame() >= generator->getMaxFrame() - 1) {
			generator->finish();
		}
		return false;
	}

	void create(Teki& teki)
	{
		Vector3f effectPos;

		effectMgr->create(EffectMgr::EFF_P_Bubbles, teki.getPosition(), nullptr, nullptr);

		effectPos.set(teki.getPosition());
		effectPos.y = mapMgr->getMinY(effectPos.x, effectPos.z, true);

		effectMgr->create(EffectMgr::EFF_RippleWhite, effectPos, this, nullptr);
		effectMgr->create(EffectMgr::EFF_RippleBlack, effectPos, this, nullptr);
		effectMgr->create(EffectMgr::EFF_RippleSurface, effectPos, this, nullptr);

		teki.playEventSound(&teki, SE_OTAMA_WATERJUMP);
	}

	// TODO: members
};

} // namespace

/*
 * @brief TODO
 */
struct TAIkabekuiCSoundTable : public PaniSoundTable {
	TAIkabekuiCSoundTable();

	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIkabekuiCParameters : public TekiParameters {
	TAIkabekuiCParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/*
 * @brief TODO
 */
struct TAIkabekuiCStrategy : public YaiStrategy {
	TAIkabekuiCStrategy();

	// _00     = VTBL
	// _00-_10 = YaiStrategy?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIkabekuiCAnimation : public TAIanimation {
	TAIkabekuiCAnimation()
	    : TAIanimation(TEKI_KabekuiC, "tekis/kabekuiC/anims.bun")
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
struct TAIAsleepKabekuiC : public TAIAtimerReaction {
	TAIAsleepKabekuiC(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
	{
	}

	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiCFloatParms::MaxSleepTime);
	}

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAdiveKabekuiC : public TAIAtimerReaction {
	TAIAdiveKabekuiC(int nextState)
	    : TAIAtimerReaction(nextState, 3.0f)
	{
	}

	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiCFloatParms::TimeUntilBurrow);
	}

	// _04     = VTBL
	// _00-_08 = TAIAtimerReaction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAattackWorkObjectKabekuiC : public TAIAattackWorkObject {
	inline TAIAattackWorkObjectKabekuiC(int nextState, int motionID, int p3) // TODO: this is a guess
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
		return teki.getParameterF(TAIkabekuiCFloatParms::BridgeDamage);
	}

	virtual f32 getAttackPointRadius(Teki& teki) // _20
	{
		return teki.getParameterF(TAIkabekuiCFloatParms::BridgeAttackRange);
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
struct TAIAlandingKabekuiC : public TAIAreserveMotion {
	inline TAIAlandingKabekuiC(int nextState, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAreserveMotion::start(teki);
		teki.setFlag400();
		teki.startFlying();
		teki.setFlyingSwitch(true);
		teki.setDororoGravity(0.0f);
	}

	virtual bool act(Teki& teki) // _10
	{
		bool output = false;
		if (TAIAreserveMotion::act(teki)) {
			if (teki.getFlyingSwitch()) {
				f32 walkSpeed = teki.getParameterF(TPF_WalkVelocity);
				f32 scale     = 1.0f;
				teki.setDororoGravity((teki.mTargetVelocity.y * scale - teki.getYFromSeaLevel()) * 2.0f / scale);
				f32 zDir = cosf(teki.getDirection());
				f32 xDir = sinf(teki.getDirection());
				teki.mTargetVelocity.set(walkSpeed * xDir, teki.mTargetVelocity.y, walkSpeed * zDir);
				teki.setFlyingSwitch(false);
			}

			if (teki.isFlying()) {
				if (teki.getYFromSeaLevel() < 15.0f) {
					Vector3f effectPos(teki.getPosition());
					effectPos.y = mapMgr->getMinY(effectPos.x, effectPos.z, true);
					effectMgr->create(EffectMgr::EFF_SmokeRing_S, effectPos, nullptr, nullptr);

					teki.finishFlying();
					teki.mTargetVelocity.x *= 0.15f;
					teki.mTargetVelocity.z *= 0.15f;
				}

				teki.mTargetVelocity.y += teki.getDororoGravity() * gsys->getFrameTime();
			}

			if (teki.mCurrentAnimEvent == KEY_Finished) {
				teki.stopEventSound(&teki, SE_SARAI_HOVER);
				teki.finishFlying();

				teki.mTargetVelocity.y = 0.0f;
				output                 = true;
			}

			teki.mVelocity = teki.mTargetVelocity;
		}

		STACK_PAD_VAR(2);
		return output;
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAmoreLifeKabekuiC : public TAIAmoreLife {
	TAIAmoreLifeKabekuiC(int nextState)
	    : TAIAmoreLife(nextState)
	{
	}

	virtual f32 getLifePercentThreshold(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiCFloatParms::MaxFlightLifePercent);
	}

	// _04     = VTBL
	// _00-_08 = TAIAmoreLife?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAlessLifeKabekuiC : public TAIAlessLife {
	TAIAlessLifeKabekuiC(int nextState)
	    : TAIAlessLife(nextState)
	{
	}

	virtual f32 getLifePercentThreshold(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiCFloatParms::FlightAlertLifePercent);
	}

	// _04     = VTBL
	// _00-_08 = TAIAmoreLife?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckPikiFlyKabekuiC : public TAIAhitCheckFlyingPiki {
	inline TAIAcheckPikiFlyKabekuiC(int nextState) // TODO: this is a guess
	    : TAIAhitCheckFlyingPiki(nextState)
	{
	}

	virtual bool act(Teki&) // _10
	{
		return false;
	}

	// _04     = VTBL
	// _00-_08 = TAIAhitCheckFlyingPiki?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingMotionKabekuiC : public TAIAreserveMotion {
	inline TAIAflyingMotionKabekuiC(int nextState, int motionID) // TODO: this is a guess
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAreserveMotion::start(teki);
		teki.playEventSound(&teki, SE_SARAI_HOVER);
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflyingBaseKabekuiC : public TAIAflyingBase {
	inline TAIAflyingBaseKabekuiC(int nextState) // TODO: this is a guess
	    : TAIAflyingBase(nextState)
	{
	}

	virtual f32 getFlyingStayVelocity(Teki& teki) // _1C
	{
		if (teki.getChokeSwitch()) {
			return teki.getParameterF(TAIkabekuiCFloatParms::FlightYVelocity);
		}

		return teki.getParameterF(TAIkabekuiCFloatParms::TakeoffYVelocity);
	}

	// _04     = VTBL
	// _00-_08 = TAIAflyingBase?
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Lives in TAIkabekuiC.cpp because it needs PRINT to match.
 */
struct TAIAtakeOffKabekuiC;

/**
 * @brief TODO
 */
struct TAIAbiteForKabekuiC : public TAIAbiteForKabekui {
	inline TAIAbiteForKabekuiC(int nextState, int p2, int motionID) // TODO: this is a guess
	    : TAIAbiteForKabekui(nextState, p2, motionID)
	{
	}

	virtual f32 getPikiAttackSize(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIkabekuiCFloatParms::PikiAttackRange);
	}

	virtual f32 getNaviAttackSize(Teki& teki) // _20
	{
		return teki.getParameterF(TAIkabekuiCFloatParms::NaviAttackRange);
	}

	// _04     = VTBL
	// _00-_08 = TAIAbiteForKabekui?
	// TODO: members
};

#endif
