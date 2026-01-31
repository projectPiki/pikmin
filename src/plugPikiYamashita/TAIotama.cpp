#include "TAI/Otama.h"

#include "DebugLog.h"
#include "MapCode.h"
#include "NaviMgr.h"
#include "SoundMgr.h"
#include "TAI/Aattack.h"
#include "TAI/Ajudge.h"
#include "TAI/Amove.h"
#include "TAI/Areaction.h"
#include "zen/CallBack.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TAIotama")

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
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
#else
		teki.setAnimSpeed(50.0f);
#endif
	}
	virtual bool act(Teki& teki) // _10
	{
		bool res = false;
		if (TAIAreserveMotion::act(teki)) {
			if (setTargetPosition(teki)) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
#else
				teki.setManualAnimation(false);
#endif
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
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
struct TAIAwaitOtama : public TAIAwait {
public:
	TAIAwaitOtama(int nextState, int motionID)
	    : TAIAwait(nextState, motionID, 0.0f)
	{
		mWaitCounterMax = 0.0f;
	}

#else
struct TAIAwaitOtama : public TAIAreserveMotion {
public:
	TAIAwaitOtama(int nextState, int motionID)
	    : TAIAreserveMotion(nextState, motionID)
	{
	}

#endif
	virtual void start(Teki& teki) // _08
	{
		// What the purpose of this change is, I have no idea
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
		TAIAwait::start(teki);
		mWaitCounterMax
		    = teki.getParameterF(TAIotamaFloatParams::MinWaitTime)
		    + zen::Rand(teki.getParameterF(TAIotamaFloatParams::MaxWaitTime) - teki.getParameterF(TAIotamaFloatParams::MinWaitTime));
#else
		TAIAreserveMotion::start(teki);
		teki.setFrameCounter(0.0f);
		teki.setFrameCounterMax(
		    teki.getParameterF(TAIotamaFloatParams::MinWaitTime)
		    + zen::Rand(teki.getParameterF(TAIotamaFloatParams::MaxWaitTime) - teki.getParameterF(TAIotamaFloatParams::MinWaitTime)));
#endif
	}
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
// This function is completely absent in the demo
#else
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
#endif
protected:
	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
	f32 mWaitCounterMax; // _10

	virtual f32 getWaitCounterMax(Teki&) { return mWaitCounterMax; }
#endif
};

/**
 * @todo: Documentation
 */
TAIotamaSoundTable::TAIotamaSoundTable()
    : PaniSoundTable(3)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_OTAMA_JUMP);
	}
}

/**
 * @todo: Documentation
 */
TAIotamaParameters::TAIotamaParameters()
    : TekiParameters(TPI_COUNT, TAIotamaFloatParams::COUNT)
{
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	int j                           = TPF_COUNT;
	fParams[j++].init("ウエイト最短時間（秒）", 0.0f, 1200.0f); // 'min wait time (sec)'
	fParams[j++].init("ウエイト最長時間（秒）", 0.0f, 1200.0f); // 'max wait time (sec)'

	multiP->setF(TAIotamaFloatParams::MinWaitTime, 1.0f);
	multiP->setF(TAIotamaFloatParams::MaxWaitTime, 5.0f);

	multiP->setI(TPI_SpawnType, TEKI_NULL);
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 2);
	multiP->setI(TPI_FlickPikiCount2, 5);
	multiP->setI(TPI_FlickPikiCount3, 10);
	multiP->setI(TPI_FlickDamageCount1, 3);
	multiP->setI(TPI_FlickDamageCount2, 3);
	multiP->setI(TPI_FlickDamageCount3, 3);
	multiP->setI(TPI_FlickDamageCount4, 3);
	multiP->setI(TPI_CullingType, CULLAI_CullAIOffCamera);
	multiP->setI(TPI_CarcassSize, 2);
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);

	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 50.0f);

	multiP->setF(TPF_WalkVelocity, 70.0f);
	multiP->setF(TPF_RunVelocity, 180.0f);
	multiP->setF(TPF_TurnVelocity, 200.0f * PI / 180.0f);

	multiP->setF(TPF_VisibleRange, 200.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);

	multiP->setF(TPF_AttackableRange, 40.0f);
	multiP->setF(TPF_AttackableAngle, 30.0f);
	multiP->setF(TPF_AttackRange, 10.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 5.0f);

	multiP->setF(TPF_DangerTerritoryRange, 250.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 80.0f);

	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);

	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 70.0f);
	multiP->setF(TPF_LowerFlickPower, 70.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);

	multiP->setF(TPF_LifeRecoverRate, 0.001f);
	multiP->setF(TPF_LifeGaugeOffset, 20.0f);

	multiP->setF(TPF_ShadowSize, 15.0f);
	multiP->setF(TPF_TraceAngle, 60.0f);

	multiP->setF(TPF_SpawnDistance, 0.0f);
	multiP->setF(TPF_SpawnHeight, 0.0f);
	multiP->setF(TPF_SpawnVelocity, 0.0f);
	multiP->setF(TPF_RippleScale, 1.0f);

	STACK_PAD_VAR(1);
}

/**
 * @todo: Documentation
 */
TAIotamaStrategy::TAIotamaStrategy()
    : YaiStrategy(TAIotamaStateID::COUNT, TAIotamaStateID::Wait)
{
	TAIAdeadCheck* deadCheck              = new TAIAdeadCheck(TAIotamaStateID::Dead);
	TAIAdying* dying                      = new TAIAdying(TAI_NO_TRANSIT, TekiMotion::Dead);
	TAIAdamage* damage                    = new TAIAdamage(TAI_NO_TRANSIT, false);
	TAIAstop* stop                        = new TAIAstop(TAI_NO_TRANSIT);
	TAIAwaitOtama* wait                   = new TAIAwaitOtama(TAIotamaStateID::SetTarget, TekiMotion::Wait1);
	TAIAsetTargetOtama* setTarget         = new TAIAsetTargetOtama(TAIotamaStateID::GoTarget, TAIotamaStateID::AppealTarget);
	TAIAgoTargetPriorityFaceDir* goTarget = new TAIAgoTargetPriorityFaceDir(TAIotamaStateID::Wait, TekiMotion::Move1);
	TAIAappealOtama* appeal1              = new TAIAappealOtama(TAIotamaStateID::GoTarget, TekiMotion::WaitAct1);
	TAIAvisibleNavi* visibleNavi          = new TAIAvisibleNavi(TAIotamaStateID::AppealRun);
	TAIAappealOtama* appeal2              = new TAIAappealOtama(TAIotamaStateID::RunAway, TekiMotion::WaitAct1);
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01)
	TAIArunAwayOtama* runAway = new TAIArunAwayOtama(TAIotamaStateID::Wait, TekiMotion::Move1);
	TAIAtimerReaction* timer  = new TAIAtimerReaction(TAIotamaStateID::SetTarget, 3.0f);
#else
	TAIAtimerReaction* timer  = new TAIAtimerReaction(TAIotamaStateID::SetTarget, 3.0f);
	TAIArunAwayOtama* runAway = new TAIArunAwayOtama(TAIotamaStateID::Wait, TekiMotion::Move1);
#endif
	// STATE 0 - Dead
	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, dying);
	state->setAction(j++, stop);
	setState(TAIotamaStateID::Dead, state);

	// STATE 1 - Wait
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, wait);        // after waiting enough time, pick a new target
	state->setAction(j++, visibleNavi); // if navi spotted, appeal 2 (jump then run away)
	setState(TAIotamaStateID::Wait, state);

	// STATE 2 - Set Target
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, setTarget); // after setting target, either go target (95% chance) or jump THEN go target (5% chance)
	setState(TAIotamaStateID::SetTarget, state);

	// STATE 4 - Appeal (jump then go to target)
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, appeal1); // after jump, go target
	setState(TAIotamaStateID::AppealTarget, state);

	// STATE 3 - Go Target
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, goTarget);    // after reaching target, wait
	state->setAction(j++, visibleNavi); // if navi spotted, appeal 2 (jump then run away)
	state->setAction(j++, timer);       // after x time, set new target
	setState(TAIotamaStateID::GoTarget, state);

	// STATE 5 - Appeal (jump then run away)
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, appeal2); // after jump, run away
	setState(TAIotamaStateID::AppealRun, state);

	// STATE 6 - Run Away
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, runAway); // after running away, wait
	setState(TAIotamaStateID::RunAway, state);
}

/**
 * @todo: Documentation
 */
void TAIotamaAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_KabekuiB]->mShape;
	addAnimation("tekis/otama/motion/dead.dca");

	addAnimation("tekis/otama/motion/damage.dca");

	addAnimation("tekis/otama/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/otama/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/otama/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/otama/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/otama/motion/move1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/otama/motion/move2.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/otama/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/otama/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/otama/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}
