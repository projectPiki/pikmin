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
#include "PlayerState.h"
#include "SoundMgr.h"
#include "PaniAnimator.h"

/////////// Fiery Blowhog AI Actions ///////////

BEGIN_ENUM_TYPE(TAItankFloatParams)
enum {
	StepBackAttackDistance = TPF_COUNT, // 50
	FireAttackAnimSpeed,                // 51
	StepBackSpeed,                      // 52
	PatrolTimeout,                      // 53
	COUNT,                              // 54
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAItankStateID)
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
	COUNT, // 12
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAItankMotionID)
enum {
	Unk0  = 0,  //
	Unk1  = 1,  //
	Unk2  = 2,  //
	Unk4  = 4,  //
	Unk5  = 5,  //
	Unk7  = 7,  //
	Unk8  = 8,  //
	Unk9  = 9,  //
	Unk10 = 10, //
} END_ENUM_TYPE;

/**
 * @brief TODO
 */
struct TAItankSoundTable : public PaniSoundTable {
	TAItankSoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAItankParameters : public TekiParameters {
	TAItankParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
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
	virtual bool hitCreature(TAIeffectAttackParam* param, Creature* target) // _08
	{
		InteractFire fire(param->mTeki, gsys->getFrameTime() * param->mDamage);
		target->stimulate(fire);
		return false;
	}
	virtual bool hitMap(TAIeffectAttackParam* param) // _14
	{
		bool res = false;
		Vector3f vec1;
		MoveTrace trace(param->mPosition, param->mVelocity, 10.0f, false);
		mapMgr->traceMove(nullptr, trace, gsys->getFrameTime());
		if (param->mVelocity.x != trace.mVelocity.x || param->mVelocity.y != trace.mVelocity.y || param->mVelocity.z != trace.mVelocity.z) {
			trace.mVelocity.normalize();
			param->mVelocity = trace.mVelocity;
			res              = true;
		}

		return res;
	}
	virtual void playEventSound(zen::particleGenerator* ptclGen, TAIeffectAttackParam* param) // _18
	{
		if (param->mTeki && ptclGen->getCurrentFrame() == ptclGen->getMaxFrame() - 2) {
			param->mTeki->stopEventSound(param->mTeki, SE_TANK_FIRE);
		}
	}
	virtual void ptclHitMap(zen::particleGenerator* ptclGen, TAIeffectAttackParam* param) // _1C
	{
		if (!param->mState.mIsMoving) {
			zen::zenListManager& ptclMgr = ptclGen->getPtclMdlListManager();
			zen::zenList* list;
			zen::zenList* end = ptclMgr.getOrigin();
			zen::zenList* next;
			for (list = ptclMgr.getTopList(); list != end; list = next) {
				next = list->mNext;

				zen::particleMdl* ptcl = (zen::particleMdl*)list;
				f32 t;
				zen::getDistPointAndLine(ptcl->mLocalPosition + ptcl->mGlobalPosition, ptclGen->getEmitPos(), param->mPosition, t);
				if (t > 1.0f) { // if we've gone past the "line"
					f32 speed = ptcl->mVelocity.length() * 0.25f;
					ptcl->mVelocity.set(param->mVelocity * speed);
				}
			}
		}
	}

	// _00     = VTBL
	// _00-_04 = TAIeffectAttackEventCallBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinitTank : public TaiAction {
	TAIAinitTank(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.mCollisionRadius = 48.0f;
	}
	virtual bool act(Teki& teki) { return true; } // _10

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

	virtual f32 getFlickDirection(Teki& teki) // _20
	{
		return teki.mFaceDirection + PI;
	}

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

	virtual void start(Teki& teki) // _08
	{
		TAIAfireBreath::start(teki);
		if (teki.isNaviWatch()) {
			playerState->mResultFlags.setOn(RESFLAG_Tank);
		}
	}
	virtual f32 getPreviousAnimSpeed(Teki& teki) // _1C
	{
		return teki.getParameterF(TAItankFloatParams::FireAttackAnimSpeed);
	}
	virtual f32 getAttackAnimSpeed(Teki& teki) // _20
	{
		return teki.getParameterF(TAItankFloatParams::FireAttackAnimSpeed);
	}

	// _04     = VTBL
	// _00-_0C = TAIAfireBreath?
	// TODO: members
};

/**
 * @brief TODO
 */
struct FireEffect : public zen::CallBack1<Teki&> {
	virtual bool invoke(Teki& teki) // _08
	{
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			CollPart* mouth = teki.mCollInfo->getSphere('kuti');
			Vector3f dir(NMathF::sin(teki.mFaceDirection), 0.0f, NMathF::cos(teki.mFaceDirection));
			if (mouth->mCentre.y > mapMgr->getMinY(mouth->mCentre.x, mouth->mCentre.z, true)) {
				Vector3f pos;
				pos = mouth->mCentre + dir * -15.0f;
				teki.initCylinderTYpePtclCallBack(&teki, pos, Vector3f(dir * 10.0f * 30.0f), 0.5f, teki.getParameterF(TPF_AttackPower),
				                                  200.0f, 20.0f, &FireEffect::eventCallBackFire);

				zen::particleGenerator* ptclGen
				    = effectMgr->create(EffectMgr::EFF_Tank_Fire, mouth->mCentre, teki.getCylinderTypePtclCallBack(), nullptr);
				teki.setPtclGenPtr(YTeki::PTCL_Unk0, ptclGen);
				if (ptclGen) {
					ptclGen->setEmitPos(mouth->mCentre);
					ptclGen->setEmitDir(dir);
				}

				teki.initEventTypePtclCallBack();
				ptclGen = effectMgr->create(EffectMgr::EFF_Tank_Smoke, mouth->mCentre, teki.getEventTypePtclCallBack(), nullptr);
				teki.setPtclGenPtr(YTeki::PTCL_Unk1, ptclGen);
				if (ptclGen) {
					ptclGen->setEmitPos(mouth->mCentre);
					ptclGen->setEmitDir(dir);
					teki.playEventSound(&teki, SE_TANK_FIRE);
				}
			}
		}

		return true;
	}

	static TAIeffectAttackEventCallBackTank eventCallBackFire;

	// _00     = VTBL
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAstepBackTank : public TAIAstepBack {
	TAIAstepBackTank(int nextState, int motionID)
	    : TAIAstepBack(nextState, motionID)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		return TAIAstepBack::act(teki);
	}
	virtual f32 getVelocity(Teki& teki) // _1C
	{
		return teki.getParameterF(TAItankFloatParams::StepBackSpeed);
	}

	// _04     = VTBL
	// _00-_0C = TAIAstepBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAoutsideOptionalRangeTank : public TAIAoutsideOptionalRange {
	TAIAoutsideOptionalRangeTank(int nextState)
	    : TAIAoutsideOptionalRange(nextState)
	{
	}

	virtual bool setTargetPosition(Teki& teki) // _1C
	{
		return TAIAjudgeOptionalRange::setTargetPositionCreature(teki);
	}
	virtual f32 getOptionalRange(Teki& teki) // _20
	{
		return teki.getParameterF(TAItankFloatParams::StepBackAttackDistance);
	}

	// _04     = VTBL
	// _00-_0C = TAIAoutsideOptionalRange?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIApatrolTank : public TAIApatrol {
	TAIApatrolTank(int nextState, int p2, int leftMotionID, int rightMotionID, Vector3f* p5, int p6)
	    : TAIApatrol(nextState, p2, leftMotionID, rightMotionID, p5, p6, true)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		return TAIApatrol::act(teki);
	}
	virtual f32 getTimeout(Teki& teki) // _20
	{
		return teki.getParameterF(TAItankFloatParams::PatrolTimeout);
	}

	// _04     = VTBL
	// _00-_08 = TAIAattackableTarget?
	// TODO: members
};

#endif
