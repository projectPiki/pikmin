#ifndef _TAI_HIBAA_H
#define _TAI_HIBAA_H

#include "MapMgr.h"
#include "PaniAnimator.h"
#include "TAI/Animation.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiParameters.h"
#include "YaiStrategy.h"
#include "types.h"
#include "zen/CallBack.h"

/////////// Fire Geyser AI Actions ///////////

BEGIN_ENUM_TYPE(TAIhibaAFloatParams)
enum {
	WaitTime = TPF_COUNT, // 50
	AttackTime,           // 51
	COUNT,                // 52
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAIhibaAStateID)
enum {
	Init   = 0,
	Wait   = 1,
	Attack = 2,
	COUNT, // 3
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(TAIhibaAMotionID)
enum {
	Unk0 = 0, //
	Unk2 = 2, //
	Unk8 = 8, //
} END_ENUM_TYPE;

/**
 * @brief TODO
 */
struct TAIhibaASoundTable : public PaniSoundTable {
	TAIhibaASoundTable();

	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIhibaAParameters : public TekiParameters {
	TAIhibaAParameters();

	// _00     = VTBL
	// _00-_20 = TekiParameters?
	// TODO: members
};

/**
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
	virtual bool hitCreature(TAIeffectAttackParam* param, Creature* target) // _08
	{
		InteractFire fire(target, gsys->getFrameTime() * param->mDamage);
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
				if (t >= 1.0f) { // if we've gone past the "line"
					f32 speed = ptcl->mVelocity.length() * 0.25f;
					ptcl->mVelocity.set(param->mVelocity * speed);
				}
			}
		}
	}
	virtual bool hitCheckCulling(zen::particleGenerator* ptclGen, TAIeffectAttackParam* param, Creature* target) // _20
	{
		bool res  = false;
		f32 limit = target->getCentreSize() + param->mRadius;
		if (zen::Abs(target->getPosition().x - ptclGen->getEmitPos().x) < limit
		    && zen::Abs(target->getPosition().z - ptclGen->getEmitPos().z) < limit) {
			res = true;
		}
		return res;
	}

	// _00     = VTBL
	// _00-_04 = TAIeffectAttackEventCallBack?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAinitHibaA : public TaiAction {
	TAIAinitHibaA(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
		teki.setCreatureFlag(CF_Unk10);
		teki.clearTekiOption(BTeki::TEKI_OPTION_ORGANIC);
	}
	virtual bool act(Teki&) { return true; } // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note In TAIhibaA.cpp to match a function with a PRINT statement.
 */
struct TAIAfireAttackHibaA;

/**
 * @brief TODO
 */
struct TAIAtimerReactionHibaA : public TAIAtimerReaction {
	TAIAtimerReactionHibaA(int nextState)
	    : TAIAtimerReaction(nextState, 0.0f)
	{
	}

	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIhibaAFloatParams::WaitTime);
	}

	// _04     = VTBL
	// _00-_0C = TAIAtimerReaction?
	// TODO: members
};

#endif
