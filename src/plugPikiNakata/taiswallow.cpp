#include "TAI/Swallow.h"

#include "DebugLog.h"
#include "MapMgr.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "TAI/AttackActions.h"
#include "TAI/BasicActions.h"
#include "TAI/EffectActions.h"
#include "TAI/JudgementActions.h"
#include "TAI/MotionActions.h"
#include "TAI/MoveActions.h"
#include "TAI/ReactionActions.h"
#include "TekiConditions.h"
#include "teki.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("taiswallow")

/**
 * @brief TODO
 */
struct TaiSwallowReceiveMessageAction : public TaiAction {
	TaiSwallowReceiveMessageAction(int nextState, int p2)
	    : TaiAction(nextState)
	{
		_08 = p2;
	}

	virtual bool actByEvent(immut TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	int _08; // _08
};

/**
 * @brief TODO
 */
struct TaiSwallowTurningAction : public TaiContinuousMotionAction {
	TaiSwallowTurningAction(int nextState, int motionIdx, f32 turnSpeed)
	    : TaiContinuousMotionAction(nextState, motionIdx)
	{
		mTurnSpeed = turnSpeed;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 mTurnSpeed; // _0C
};

/**
 * @brief TODO
 */
struct TaiSwallowFlickingAction : public TaiMotionAction {
	TaiSwallowFlickingAction(int nextState, int motionIdx)
	    : TaiMotionAction(nextState, motionIdx)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	void flick(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiMotionAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowSwallowingFlickAction : public TaiAction {
	inline TaiSwallowSwallowingFlickAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowSnoreAction : public TaiAction {
	TaiSwallowSnoreAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowNoticeAction : public TaiAction {
	TaiSwallowNoticeAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowLegEffectAction : public TaiJointEffectAction {
	TaiSwallowLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiSwallowMissAttackingEffectAction : public TaiJointEffectAction {
	TaiSwallowMissAttackingEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

/**
 * @TODO: Documentation
 */
TaiSwallowSoundTable::TaiSwallowSoundTable()
    : PaniSoundTable(8)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_CHAPPY_WALK);
	}
}

/**
 * @TODO: Documentation
 */
TaiSwallowParameters::TaiSwallowParameters()
    : TekiParameters(TPI_COUNT, SWALLOWPF_COUNT)
{
	int j                           = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("NOTICE_DISTANCE", 0.0f, 1000.0f);
	fParams[j++].init("LOWER_DAMAGE_RATE", 0.0f, 1.0f);
	fParams[j++].init("LOWER_DAMAGE_COUNT_RATE", 0.0f, 1.0f);
	fParams[j++].init("TURN_VELOCITY_FUNCTION_MAX_COUNT", 0.0f, 100.0f);
	fParams[j++].init("TURN_VELOCITY_FUNCTION_MAX_RATE", 0.0f, 0.0f);
	fParams[j++].init("FLICK_LOWER_ANGLE", 0.0f, 360.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_CarcassSize, 0);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_SwallowCount, 3);
	multiP->setI(TPI_FlickPikiCount1, 5);
	multiP->setI(TPI_FlickPikiCount2, 10);
	multiP->setI(TPI_FlickPikiCount3, 20);
	multiP->setI(TPI_FlickDamageCount1, 8);
	multiP->setI(TPI_FlickDamageCount2, 10);
	multiP->setI(TPI_FlickDamageCount3, 12);
	multiP->setI(TPI_FlickDamageCount4, 14);

	multiP->setF(TPF_Life, 1000.0f);
	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 3.0f);
	multiP->setF(TPF_WalkVelocity, 30.0f);
	multiP->setF(TPF_RunVelocity, 100.0f);
	multiP->setF(TPF_TurnVelocity, 3.0f * NMathF::pi / 8.0f);
	multiP->setF(TPF_VisibleRange, 500.0f);
	multiP->setF(TPF_VisibleAngle, 180.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 20.0f);
	multiP->setF(TPF_AttackableAngle, 25.0f);
	multiP->setF(TPF_AttackRange, 10.0f);
	multiP->setF(TPF_AttackHitRange, 10.0f);
	multiP->setF(TPF_DangerTerritoryRange, 400.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 15.0f);
	multiP->setF(TPF_LifeGaugeOffset, 50.0f);
	multiP->setF(TPF_ShadowSize, 50.0f);
	multiP->setF(TPF_RippleScale, 4.0f);
	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 15.0f);
	multiP->setF(TPF_SpawnDistance, 18.0f);
	multiP->setF(TPF_SpawnHeight, 8.0f);
	multiP->setF(TPF_WarnPeriod, 8.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.25f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 200.0f);
	multiP->setF(TPF_LowerFlickPower, 160.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_LifeRecoverRate, 0.005f);
	multiP->setF(TPF_TraceAngle, 90.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 400.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 300.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 64.0f);
	multiP->setF(TPF_LowerRange, 10.0f);

	multiP->setF(SWALLOWPF_NoticeDistance, 0.0f);
	multiP->setF(SWALLOWPF_LowerDamageRate, 0.25f);
	multiP->setF(SWALLOWPF_LowerDamageCountRate, 0.2f);
	multiP->setF(SWALLOWPF_TurnVelocityFuncMaxCount, 20.0f);
	multiP->setF(SWALLOWPF_TurnVelocityFuncMaxRate, 0.1f);
	multiP->setF(SWALLOWPF_FlickLowerAngle, 360.0f);
}

/**
 * @TODO: Documentation
 */
TaiBlackSwallowParameters::TaiBlackSwallowParameters()
    : TekiParameters(TPI_COUNT, SWALLOWPF_COUNT)
{
	int j                           = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("NOTICE_DISTANCE", 0.0f, 1000.0f);
	fParams[j++].init("LOWER_DAMAGE_RATE", 0.0f, 1.0f);
	fParams[j++].init("LOWER_DAMAGE_COUNT_RATE", 0.0f, 1.0f);
	fParams[j++].init("TURN_VELOCITY_FUNCTION_MAX_COUNT", 0.0f, 100.0f);
	fParams[j++].init("TURN_VELOCITY_FUNCTION_MAX_RATE", 0.0f, 0.0f);
	fParams[j++].init("FLICK_LOWER_ANGLE", 0.0f, 360.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_CarcassSize, 0);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 5);
	multiP->setI(TPI_FlickPikiCount2, 10);
	multiP->setI(TPI_FlickPikiCount3, 20);
	multiP->setI(TPI_FlickDamageCount1, 4);
	multiP->setI(TPI_FlickDamageCount2, 6);
	multiP->setI(TPI_FlickDamageCount3, 8);
	multiP->setI(TPI_FlickDamageCount4, 10);

	multiP->setF(TPF_Life, 1000.0f);
	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 3.5f);
	multiP->setF(TPF_WalkVelocity, 30.0f);
	multiP->setF(TPF_RunVelocity, 100.0f);
	multiP->setF(TPF_TurnVelocity, 6.0f * NMathF::pi / 8.0f);
	multiP->setF(TPF_VisibleRange, 500.0f);
	multiP->setF(TPF_VisibleAngle, 180.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 20.0f);
	multiP->setF(TPF_AttackableAngle, 25.0f);
	multiP->setF(TPF_AttackRange, 10.0f);
	multiP->setF(TPF_AttackHitRange, 10.0f);
	multiP->setF(TPF_LowerRange, 10.0f);
	multiP->setF(TPF_DangerTerritoryRange, 400.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 15.0f);
	multiP->setF(TPF_LifeGaugeOffset, 100.0f);
	multiP->setF(TPF_ShadowSize, 50.0f);
	multiP->setF(TPF_RippleScale, 4.0f);
	multiP->setF(TPF_CorpseSize, 6.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_SpawnDistance, 18.0f);
	multiP->setF(TPF_SpawnHeight, 8.0f);
	multiP->setF(TPF_WarnPeriod, 8.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.25f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 400.0f);
	multiP->setF(TPF_LowerFlickPower, 300.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_LifeRecoverRate, 0.005f);
	multiP->setF(TPF_TraceAngle, 120.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 400.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 300.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 64.0f);

	multiP->setF(SWALLOWPF_NoticeDistance, 200.0f);
	multiP->setF(SWALLOWPF_LowerDamageRate, 0.25f);
	multiP->setF(SWALLOWPF_LowerDamageCountRate, 0.2f);
	multiP->setF(SWALLOWPF_TurnVelocityFuncMaxCount, 20.0f);
	multiP->setF(SWALLOWPF_TurnVelocityFuncMaxRate, 0.1f);
	multiP->setF(SWALLOWPF_FlickLowerAngle, 360.0f);
}

/**
 * @TODO: Documentation
 */
TaiSwallowStrategy::TaiSwallowStrategy(TekiParameters* params)
    : TaiStrategy(SWALLOWSTATE_COUNT, SWALLOWSTATE_Unk15)
{
	TaiStopMoveAction* stopMove                          = new TaiStopMoveAction();
	TaiStoppingMoveAction* stoppingMove                  = new TaiStoppingMoveAction(TekiMotion::Move2);
	TaiFinishStoppingMoveAction* finishStoppingMove      = new TaiFinishStoppingMoveAction();
	TaiDeadAction* dead                                  = new TaiDeadAction(SWALLOWSTATE_Unk0);
	TaiSimultaneousDamageAction* simDamage               = new TaiSimultaneousDamageAction(TAI_NO_TRANSIT);
	TaiDamageAction* damage                              = new TaiDamageAction(SWALLOWSTATE_Unk3);
	TaiFlickAction* flick                                = new TaiFlickAction(SWALLOWSTATE_Unk10);
	TaiTargetVisibleNaviPikiAction* targetVisNaviPiki1   = new TaiTargetVisibleNaviPikiAction(TAI_NO_TRANSIT);
	TaiTargetVisibleNaviPikiAction* targetVisNaviPiki2   = new TaiTargetVisibleNaviPikiAction(SWALLOWSTATE_Unk7);
	TaiTargetNearestCollisionAction* targetNearestColl1  = new TaiTargetNearestCollisionAction(TAI_NO_TRANSIT);
	TaiTargetNearestCollisionAction* targetNearestColl2  = new TaiTargetNearestCollisionAction(SWALLOWSTATE_Unk4);
	TaiTargetNearestAssailantAction* targetNearestAssail = new TaiTargetNearestAssailantAction(TAI_NO_TRANSIT);
	TaiOutsideTerritoryAction* outsideTerritory = new TaiOutsideTerritoryAction(SWALLOWSTATE_Unk11, params->getF(TPF_DangerTerritoryRange));
	TaiTargetLostAction* targetLost             = new TaiTargetLostAction(SWALLOWSTATE_Unk5);
	TaiContactTargetAction* contactTarget       = new TaiContactTargetAction(SWALLOWSTATE_Unk4);
	TaiSeparateTargetAction* sepTarget          = new TaiSeparateTargetAction(SWALLOWSTATE_Unk5);
	TaiAttackableNaviPikiAction* attackableNaviPiki     = new TaiAttackableNaviPikiAction(SWALLOWSTATE_Unk9);
	TaiSwallowLegEffectAction* legEffect                = new TaiSwallowLegEffectAction(-0.5f);
	TaiTypeNaviWatchResultOnAction* typeNaviWatchResult = new TaiTypeNaviWatchResultOnAction();
	TaiDyingAction* dying                               = new TaiDyingAction(TekiMotion::Dead);
	TaiStartDyingAction* startDying                     = new TaiStartDyingAction();

	//  STATE -
	TaiState* state = new TaiState(3);
	int j           = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, startDying);
	state->setAction(j++, dying);
	setState(SWALLOWSTATE_Unk0, state);

	TaiMotionAction* motion                               = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Flick);
	TaiTargetNearestCollisionAction* targetNearestColl3   = new TaiTargetNearestCollisionAction(SWALLOWSTATE_Unk2);
	TaiSwallowSnoreAction* snore                          = new TaiSwallowSnoreAction();
	TaiSwallowReceiveMessageAction* receiveMessage        = new TaiSwallowReceiveMessageAction(SWALLOWSTATE_Unk2, 0);
	TaiSwallowNoticeAction* notice                        = new TaiSwallowNoticeAction(SWALLOWSTATE_Unk2);
	TaiRandomSetAnimationCounterAction* randomAnimCounter = new TaiRandomSetAnimationCounterAction(0, 1);

	//  STATE -
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, damage);
	state->setAction(j++, targetNearestColl3);
	state->setAction(j++, motion);
	state->setAction(j++, snore);
	state->setAction(j++, receiveMessage);
	state->setAction(j++, notice);
	state->setAction(j++, randomAnimCounter);
	setState(SWALLOWSTATE_Unk15, state);

	//  STATE -
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, damage);
	state->setAction(j++, targetNearestColl3);
	state->setAction(j++, motion);
	state->setAction(j++, snore);
	state->setAction(j++, receiveMessage);
	state->setAction(j++, notice);
	setState(SWALLOWSTATE_Unk1, state);

	TaiDamagingAction* damaging = new TaiDamagingAction(SWALLOWSTATE_Unk4, TekiMotion::Damage);
	TaiWarnAction* warn         = new TaiWarnAction();

	//  STATE -
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, warn);
	state->setAction(j++, stopMove);
	state->setAction(j++, dead);
	state->setAction(j++, damaging);
	setState(SWALLOWSTATE_Unk3, state);

	TaiFinishMotionAction* finishMotion = new TaiFinishMotionAction(SWALLOWSTATE_Unk4);

	//  STATE -
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, warn);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, targetNearestColl1);
	state->setAction(j++, finishMotion);
	setState(SWALLOWSTATE_Unk2, state);

	TaiSwallowTurningAction* turning = new TaiSwallowTurningAction(SWALLOWSTATE_Unk5, TekiMotion::WaitAct1, params->getF(TPF_TurnVelocity));

	//  STATE -
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, targetNearestColl1);
	state->setAction(j++, sepTarget);
	state->setAction(j++, turning);
	state->setAction(j++, legEffect);
	setState(SWALLOWSTATE_Unk4, state);

	TaiOnceAction* once = new TaiOnceAction(SWALLOWSTATE_Unk6);

	//  STATE -
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, targetNearestColl2);
	state->setAction(j++, outsideTerritory);
	state->setAction(j++, targetVisNaviPiki2);
	state->setAction(j++, once);
	setState(SWALLOWSTATE_Unk5, state);

	TaiContinuousMotionAction* contMotion1 = new TaiContinuousMotionAction(SWALLOWSTATE_Unk11, TekiMotion::Wait2);

	//  STATE -
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, targetNearestColl2);
	state->setAction(j++, targetVisNaviPiki2);
	state->setAction(j++, contMotion1);
	setState(SWALLOWSTATE_Unk6, state);

	TaiTraceTurningAction* traceTurning
	    = new TaiTraceTurningAction(SWALLOWSTATE_Unk8, TekiMotion::WaitAct1, params->getF(TPF_TurnVelocity));

	//  STATE -
	state = new TaiState(11);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, targetNearestColl1);
	state->setAction(j++, contactTarget);
	state->setAction(j++, targetLost);
	state->setAction(j++, traceTurning);
	state->setAction(j++, legEffect);
	setState(SWALLOWSTATE_Unk7, state);

	TaiOutOfTraceAngleAction* outOfTraceAngle = new TaiOutOfTraceAngleAction(SWALLOWSTATE_Unk7);
	TaiTracingAction* tracing                 = new TaiTracingAction(TekiMotion::Move2, params->getF(TPF_RunVelocity));

	//  STATE -
	state = new TaiState(14);
	j     = 0;
	state->setAction(j++, finishStoppingMove);
	state->setAction(j++, tracing);
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, contactTarget);
	state->setAction(j++, targetNearestColl1);
	state->setAction(j++, outsideTerritory);
	state->setAction(j++, targetLost);
	state->setAction(j++, targetVisNaviPiki1);
	state->setAction(j++, outOfTraceAngle);
	state->setAction(j++, legEffect);
	setState(SWALLOWSTATE_Unk8, state);

	TaiContinuousMotionAction* contMotion2       = new TaiContinuousMotionAction(SWALLOWSTATE_Unk5, TekiMotion::Attack);
	TaiAnimationSwallowingAction* animSwallowing = new TaiAnimationSwallowingAction(SWALLOWSTATE_Unk14);

	//  STATE -
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, animSwallowing);
	state->setAction(j++, contMotion2);
	state->setAction(j++, typeNaviWatchResult);
	setState(SWALLOWSTATE_Unk9, state);

	TaiSwitchMotionAction* switchMotion                   = new TaiSwitchMotionAction(SWALLOWSTATE_Unk5, TekiMotion::WaitAct2);
	TaiSwallowMissAttackingEffectAction* missAttackEffect = new TaiSwallowMissAttackingEffectAction(-0.5f);

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, switchMotion);
	state->setAction(j++, missAttackEffect);
	setState(SWALLOWSTATE_Unk14, state);

	TaiSwallowFlickingAction* flicking = new TaiSwallowFlickingAction(SWALLOWSTATE_Unk5, TekiMotion::Type1);

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, dead);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, flicking);
	setState(SWALLOWSTATE_Unk10, state);

	TaiTurningToTargetPositionAction* turnToTargetPos
	    = new TaiTurningToTargetPositionAction(SWALLOWSTATE_Unk12, TekiMotion::WaitAct1, params->getF(TPF_TurnVelocity));
	TaiTargetNestAction* targetNest           = new TaiTargetNestAction();
	TaiInsideTerritoryAction* insideTerritory = new TaiInsideTerritoryAction(SWALLOWSTATE_Unk13, params->getF(TPF_SafetyTerritoryRange));

	//  STATE -
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, targetNest);
	state->setAction(j++, turnToTargetPos);
	state->setAction(j++, legEffect);
	setState(SWALLOWSTATE_Unk11, state);

	TaiGoingHomeAction* goingHome = new TaiGoingHomeAction(TekiMotion::Move2, params->getF(TPF_RunVelocity));

	//  STATE -
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, finishStoppingMove);
	state->setAction(j++, goingHome);
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, targetNearestColl2);
	state->setAction(j++, insideTerritory);
	state->setAction(j++, legEffect);
	setState(SWALLOWSTATE_Unk12, state);

	TaiContinuousMotionAction* contMotion3 = new TaiContinuousMotionAction(SWALLOWSTATE_Unk1, TekiMotion::Wait2);

	//  STATE -
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, stoppingMove);
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, simDamage);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, targetNearestColl2);
	state->setAction(j++, targetVisNaviPiki2);
	state->setAction(j++, contMotion3);
	setState(SWALLOWSTATE_Unk13, state);
}

/**
 * @TODO: Documentation
 */
void TaiSwallowStrategy::start(Teki& teki)
{
	teki.mParticleGenerators[0] = effectMgr->create(EffectMgr::EFF_Chappy_SnoreBubble, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	TaiStrategy::start(teki);
	teki.stopParticleGenerator(0);
}

/**
 * @TODO: Documentation
 */
void TaiSwallowStrategy::draw(Teki& teki, Graphics& gfx)
{
	TekiStrategy::draw(teki, gfx);
	if (!teki.mParticleGenerators[0]) {
		return;
	}

	if (!teki.getTekiOption(BTeki::TEKI_OPTION_DRAWED)) {
		teki.stopParticleGenerator(0);
		return;
	}

	if (isSleeping(teki)) {
		teki.startParticleGenerator(0);
		NVector3f ptclDir;
		teki.outputDirectionVector(ptclDir);
		teki.setParticleGeneratorDirection(0, ptclDir);
		NVector3f ptclPos;
		teki.outputSpawnPosition(ptclPos);
		teki.setParticleGeneratorPosition(0, ptclPos);
		STACK_PAD_VAR(1);
	}
}

/**
 * @TODO: Documentation
 */
bool TaiSwallowStrategy::interact(Teki& teki, immut TekiInteractionKey& key)
{
	if (key.mInteractionType == TekiInteractType::Attack) {
		InteractAttack* attack = (InteractAttack*)key.mInteraction;
		if (teki.getTekiOption(BTeki::TEKI_OPTION_INVINCIBLE)) {
			return false;
		}

		if (teki.getTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE)) {
			if (attack->getDamagePortion() != 1) {
				attack->mDamage *= teki.getParameterF(SWALLOWPF_LowerDamageRate);
				PRINT_NAKATA("TaiSwallowStrategy::interact:%08x:!PART_UPPER\n", &teki);
				teki.mDamageCount += teki.getParameterF(SWALLOWPF_LowerDamageCountRate);
			} else {
				PRINT_NAKATA("TaiSwallowStrategy::interact:%08x:PART_UPPER\n", &teki);
				teki.mDamageCount++;
			}
		}

		teki._344 = attack->getDamagePortion();
		teki.mStoredDamage += attack->mDamage;
		teki.setCreaturePointer(1, attack->mOwner);
		return true;
	}

	return TekiStrategy::interact(teki, key);
	STACK_PAD_VAR(2);
}

/**
 * @TODO: Documentation
 */
bool TaiSwallowStrategy::isSleeping(Teki& teki)
{
	return teki.mStateID == SWALLOWSTATE_Unk15 || teki.mStateID == SWALLOWSTATE_Unk1;
}

/**
 * @TODO: Documentation
 */
void TaiSwallowStrategy::drawDebugInfo(Teki& teki, Graphics& gfx)
{
	teki.drawTekiDebugInfoDefault(gfx);
}

/**
 * @TODO: Documentation
 */
bool TaiSwallowReceiveMessageAction::actByEvent(immut TekiEvent& event)
{
	if (event.mEventType == TekiEventType::WakeUpCall) {
		PRINT_NAKATA("TaiSwallowReceiveMessageAction::act:%08x\n", event.mTeki);
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool TaiSwallowTurningAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	Creature* target = teki.getCreaturePointer(0);
	if (!target) {
		// Looks like someone was copying and pasting code lol (me too buddy, me too)
		PRINT_NAKATA(TERNARY_BUGFIX("!TaiSwallowTurningAction", "!TaiTurnAction") "::act:target==null:%08x\n", &teki);
		return true;
	}

	TekiRecognitionCondition recogCond(&teki);
	if (!recogCond.satisfy(target)) {
		// Same copy-paste mistake as above
		PRINT_NAKATA(TERNARY_BUGFIX("!TaiSwallowTurningAction", "!TaiTurnAction") "::act:!condition.satisfy:%08x\n", &teki);
		return true;
	}

	TekiAndCondition NRef cond = TekiAndCondition(&TekiRecognitionCondition(&teki), &TekiLowerCondition(&teki));
	int pikiCount              = teki.countPikis(cond);
	f32 linFuncValues[2];
	NClampLinearFunction linFunc(linFuncValues);
	linFunc.makeClampLinearFunction(0.0f, 1.0f, teki.getParameterF(SWALLOWPF_TurnVelocityFuncMaxCount),
	                                teki.getParameterF(SWALLOWPF_TurnVelocityFuncMaxRate));

	f32 factor = linFunc.getValue(f32(pikiCount));
	PRINT_NAKATA("TaiSwallowTurningAction::act:%08x:%f,%d\n", &teki, factor, pikiCount);
	f32 speed         = mTurnSpeed * factor;
	teki.mTargetAngle = teki.calcTargetDirection(target->getPosition());
	return teki.turnToward(teki.mTargetAngle, speed);

	// hate it hate it hate it hate it hate it
	STACK_PAD_TERNARY(speed, 5);
}

/**
 * @TODO: Documentation
 */
void TaiSwallowFlickingAction::start(Teki& teki)
{
	TaiMotionAction::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/**
 * @TODO: Documentation
 */
void TaiSwallowFlickingAction::finish(Teki& teki)
{
	teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
}

/**
 * @TODO: Documentation
 */
bool TaiSwallowFlickingAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		teki.setTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE);
		return true;
	}

	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		flick(teki);
		teki.mDamageCount = 0.0f;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
void TaiSwallowFlickingAction::flick(Teki& teki)
{
	teki.flickUpper();
	InteractFlick NRef flick
	    = InteractFlick(&teki, teki.getParameterF(TPF_LowerFlickPower), teki.getParameterF(TPF_LowerAttackPower), FLICK_BACKWARDS_ANGLE);
	TekiAndCondition NRef cond
	    = TekiAndCondition(&TekiAndCondition(&TekiRecognitionCondition(&teki), &TekiNotCondition(&TekiStickingCondition())),
	                       &TekiAndCondition(&TekiDistanceCondition(&teki, teki.getLowerRange()),
	                                         &TekiAngleCondition(&teki, teki.getParameterF(SWALLOWPF_FlickLowerAngle))));
	teki.interactNaviPiki(flick, cond);

	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiNotCondition(nullptr);
}

/**
 * @TODO: Documentation
 */
bool TaiSwallowSwallowingFlickAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		InteractFlick NRef flick = InteractFlick(&teki, teki.getParameterF(TPF_LowerFlickPower), teki.getParameterF(TPF_LowerAttackPower),
		                                         teki.getDirection() + NMathF::pi);
		TekiAndCondition NRef cond
		    = TekiAndCondition(&TekiAndCondition(&TekiRecognitionCondition(&teki), &TekiNotCondition(&TekiStickingCondition())),
		                       &TekiAndCondition(&TekiDistanceCondition(&teki, teki.getLowerRange()),
		                                         &TekiAngleCondition(&teki, teki.getParameterF(SWALLOWPF_FlickLowerAngle))));
		teki.interactNaviPiki(flick, cond);
	}
	return false;

	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiNotCondition(nullptr);
}

/**
 * @TODO: Documentation
 */
void TaiSwallowSnoreAction::start(Teki& teki)
{
	PRINT_NAKATA("TaiSwallowSnoreAction::start:%08x\n", &teki);
	teki.startParticleGenerator(0);
}

/**
 * @TODO: Documentation
 */
void TaiSwallowSnoreAction::finish(Teki& teki)
{
	PRINT_NAKATA("TaiSwallowSnoreAction::finish:%08x\n", &teki);
	teki.stopParticleGenerator(0);
}

/**
 * @TODO: Documentation
 */
bool TaiSwallowNoticeAction::act(Teki& teki)
{
	Creature* naviPiki = teki.getClosestNaviPiki(TekiDistanceCondition(&teki, teki.getParameterF(SWALLOWPF_NoticeDistance)), nullptr);
	if (!naviPiki) {
		return false;
	}

	PRINT_NAKATA("TaiSwallowNoticeAction::act:%08x\n", &teki);
	teki.setCreaturePointer(0, naviPiki);
	return true;

	TekiRecognitionCondition(nullptr);
}

/**
 * @TODO: Documentation
 */
TaiSwallowLegEffectAction::TaiSwallowLegEffectAction(f32 p1)
    : TaiJointEffectAction(p1, 2, 'lleg', 'rleg', 0, 0)
{
}

/**
 * @TODO: Documentation
 */
void TaiSwallowLegEffectAction::setType(Vector3f& effectPos, int type, int id)
{
	ID32 unusedID;
	unusedID.setID(id);
	effectPos.y = mapMgr->getMinY(effectPos.x, effectPos.z, true);
	if (type == 5) {
		mEffectType = EffectMgr::EFF_P_Bubbles;
	} else if (type == -1) {
		mEffectType = EffectMgr::EFF_NULL;
	} else {
		mEffectType = EffectMgr::EFF_SmokeRing_M;
	}

	mSoundID = 1;

	rumbleMgr->start(RUMBLE_Unk15, 0, effectPos);
}

/**
 * @TODO: Documentation
 */
TaiSwallowMissAttackingEffectAction::TaiSwallowMissAttackingEffectAction(f32 p1)
    : TaiJointEffectAction(p1, 1, 'hana', 0, 0, 0)
{
}

/**
 * @TODO: Documentation
 */
void TaiSwallowMissAttackingEffectAction::setType(Vector3f& effectPos, int type, int id)
{
	effectPos.y = mapMgr->getMinY(effectPos.x, effectPos.z, true);
	if (type == 5) {
		mEffectType = EffectMgr::EFF_P_Bubbles;
	} else if (type == -1) {
		mEffectType = EffectMgr::EFF_NULL;
	} else {
		mEffectType = EffectMgr::EFF_SmokeRing_M;
	}

	rumbleMgr->start(RUMBLE_Unk2, 0, effectPos);
}
