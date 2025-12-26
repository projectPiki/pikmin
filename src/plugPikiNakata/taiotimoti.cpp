#include "TAI/Otimoti.h"

#include "DebugLog.h"
#include "MapCode.h"
#include "MapMgr.h"
#include "Pcam/CameraManager.h"
#include "Peve/MotionEvents.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "TAI/AttackActions.h"
#include "TAI/BasicActions.h"
#include "TAI/EffectActions.h"
#include "TAI/JudgementActions.h"
#include "TAI/MoveActions.h"
#include "TAI/ReactionActions.h"
#include "TAI/TimerActions.h"
#include "TAI/WaitActions.h"
#include "TekiConditions.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("taiotimoti")

/**
 * @brief TODO
 */
struct TaiOtimotiStartDroppingWaterAction : public TaiAction {
	TaiOtimotiStartDroppingWaterAction()
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiFlickAction : public TaiAction {
	TaiOtimotiFlickAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiOtimotiFailToJumpAction : public TaiAction {
	TaiOtimotiFailToJumpAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TaiOtimotiJumpingAction : public TaiAction {
	TaiOtimotiJumpingAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiAirWaitingAction : public TaiAction {
	TaiOtimotiAirWaitingAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiDroppingAction : public TaiAction {
	TaiOtimotiDroppingAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&);                 // _08
	virtual bool act(Teki&);                   // _10
	virtual bool actByEvent(immut TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiPressingAction : public TaiAction {
	TaiOtimotiPressingAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&);                 // _08
	virtual bool act(Teki&);                   // _10
	virtual bool actByEvent(immut TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiBouncingAction : public TaiAction {
	TaiOtimotiBouncingAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&);                   // _10
	virtual bool actByEvent(immut TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiAttackingAction : public TaiAction {
	TaiOtimotiAttackingAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&);                 // _08
	virtual bool act(Teki&);                   // _10
	virtual bool actByEvent(immut TekiEvent&); // _14

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiAttackingEffectAction : public TaiAction {
	inline TaiOtimotiAttackingEffectAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiOtimotiLegEffectAction : public TaiJointEffectAction {
	TaiOtimotiLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

/**
 * @todo: Documentation
 */
TaiOtimotiSoundTable::TaiOtimotiSoundTable()
    : PaniSoundTable(12)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_FLOG_WALK);
	}
}

/**
 * @todo: Documentation
 */
TaiOtimotiParameters::TaiOtimotiParameters()
    : TekiParameters(OTIMOTIPI_COUNT, OTIMOTIPF_COUNT)
{
	int j                           = TPI_COUNT;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	iParams[j++].init("READY_FOR_JUMP_LOOP_COUNT", 0, 10);

	j                               = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("DROP_VELOCITY", 0.0f, 1000.0f);
	fParams[j++].init("ATTACK_START_HEIGHT", 0.0f, 1000.0f);
	fParams[j++].init("WAITING_WASH_PERIOD", 0.0f, 100.0f);
	fParams[j++].init("WAITING_WASH_PROBABILITY", 0.0f, 1.0f);
	fParams[j++].init("WAITING_TURN_PERIOD", 0.0f, 100.0f);
	fParams[j++].init("WAITING_TURN_PROBABILITY", 0.0f, 1.0f);
	fParams[j++].init("IMPASSABLE_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("IMPASSABLE_DISTANCE", 0.0f, 100.0f);
	fParams[j++].init("MISS_FUNCTION_MIN_COUNT", 0.0f, 100.0f);
	fParams[j++].init("MISS_FUNCTION_MAX_COUNT", 0.0f, 100.0f);
	fParams[j++].init("MISS_FUNCTION_MIN_PROBABILITY", 0.0f, 1.0f);
	fParams[j++].init("MISS_FUNCTION_MAX_PROBABILITY", 0.0f, 1.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_CarcassSize, 1);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_FlickPikiCount1, 5);
	multiP->setI(TPI_FlickPikiCount2, 15);
	multiP->setI(TPI_FlickPikiCount3, 25);
	multiP->setI(TPI_FlickDamageCount1, 10);
	multiP->setI(TPI_FlickDamageCount2, 18);
	multiP->setI(TPI_FlickDamageCount3, 40);
	multiP->setI(TPI_FlickDamageCount4, 70);

	multiP->setF(TPF_Life, 1600.0f);
	multiP->setF(TPF_Weight, 1000.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_WalkVelocity, 30.0f);
	multiP->setF(TPF_RunVelocity, 190.0f);
	multiP->setF(TPF_TurnVelocity, NMathF::pi / 2.0f);
	multiP->setF(TPF_VisibleRange, 300.0f);
	multiP->setF(TPF_VisibleAngle, 270.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 240.0f);
	multiP->setF(TPF_AttackableAngle, 5.0f);
	multiP->setF(TPF_AttackRange, 25.0f);
	multiP->setF(TPF_LowerRange, 38.0f);
	multiP->setF(TPF_AttackPower, 30.0f);
	multiP->setF(TPF_UnguardedPeriod, 1.0f);
	multiP->setF(TPF_DangerTerritoryRange, 400.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 50.0f);
	multiP->setF(TPF_LifeGaugeOffset, 40.0f);
	multiP->setF(TPF_ShadowSize, 35.0f);
	multiP->setF(TPF_RippleScale, 4.0f);
	multiP->setF(TPF_CorpseSize, 17.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_WarnPeriod, 5.0f);
	multiP->setF(TPF_FlightHeight, 100.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 150.0f);
	multiP->setF(TPF_LowerFlickPower, 0.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_LifeRecoverRate, 0.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 24.0f);

	multiP->setF(OTIMOTIPF_DropVelocity, 100.0f);
	multiP->setF(OTIMOTIPF_AttackStartHeight, 60.0f);
	multiP->setF(OTIMOTIPF_WaitingWashPeriod, 6.0f);
	multiP->setF(OTIMOTIPF_WaitingWashChance, 0.3f);
	multiP->setF(OTIMOTIPF_WaitingTurnPeriod, 4.0f);
	multiP->setF(OTIMOTIPF_WaitingTurnChance, 0.6f);
	multiP->setF(OTIMOTIPF_ImpassablePeriod, 4.0f);
	multiP->setF(OTIMOTIPF_ImpassableDistance, 20.0f);
	multiP->setF(OTIMOTIPF_MissFuncMinCount, 3.0f);
	multiP->setF(OTIMOTIPF_MissFuncMaxCount, 10.0f);
	multiP->setF(OTIMOTIPF_MissFuncMinChance, 0.0f);
	multiP->setF(OTIMOTIPF_MissFuncMaxChance, 0.8f);
}

/**
 * @todo: Documentation
 */
TaiBlackFrogSoundTable::TaiBlackFrogSoundTable()
    : PaniSoundTable(10)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_FLOG_WALK);
	}
}

/**
 * @todo: Documentation
 */
TaiBlackFrogParameters::TaiBlackFrogParameters()
    : TekiParameters(OTIMOTIPI_COUNT, OTIMOTIPF_COUNT)
{
	int j                           = TPI_COUNT;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	iParams[j++].init("READY_FOR_JUMP_LOOP_COUNT", 0, 10);

	j                               = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("DROP_VELOCITY", 0.0f, 1000.0f);
	fParams[j++].init("ATTACK_START_HEIGHT", 0.0f, 1000.0f);
	fParams[j++].init("WAITING_WASH_PERIOD", 0.0f, 100.0f);
	fParams[j++].init("WAITING_WASH_PROBABILITY", 0.0f, 1.0f);
	fParams[j++].init("WAITING_TURN_PERIOD", 0.0f, 100.0f);
	fParams[j++].init("WAITING_TURN_PROBABILITY", 0.0f, 1.0f);
	fParams[j++].init("IMPASSABLE_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("IMPASSABLE_DISTANCE", 0.0f, 100.0f);
	fParams[j++].init("MISS_FUNCTION_MIN_COUNT", 0.0f, 100.0f);
	fParams[j++].init("MISS_FUNCTION_MAX_COUNT", 0.0f, 100.0f);
	fParams[j++].init("MISS_FUNCTION_MIN_PROBABILITY", 0.0f, 1.0f);
	fParams[j++].init("MISS_FUNCTION_MAX_PROBABILITY", 0.0f, 1.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_CarcassSize, 1);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_FlickPikiCount1, 5);
	multiP->setI(TPI_FlickPikiCount2, 15);
	multiP->setI(TPI_FlickPikiCount3, 25);
	multiP->setI(TPI_FlickDamageCount1, 10);
	multiP->setI(TPI_FlickDamageCount2, 18);
	multiP->setI(TPI_FlickDamageCount3, 40);
	multiP->setI(TPI_FlickDamageCount4, 70);

	multiP->setF(TPF_Life, 1600.0f);
	multiP->setF(TPF_Weight, 1000.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_WalkVelocity, 30.0f);
	multiP->setF(TPF_RunVelocity, 190.0f);
	multiP->setF(TPF_TurnVelocity, NMathF::pi / 2.0f);
	multiP->setF(TPF_VisibleRange, 360.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 300.0f);
	multiP->setF(TPF_AttackableAngle, 5.0f);
	multiP->setF(TPF_AttackRange, 25.0f);
	multiP->setF(TPF_LowerRange, 38.0f);
	multiP->setF(TPF_AttackPower, 30.0f);
	multiP->setF(TPF_UnguardedPeriod, 1.0f);
	multiP->setF(TPF_DangerTerritoryRange, 400.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 50.0f);
	multiP->setF(TPF_LifeGaugeOffset, 40.0f);
	multiP->setF(TPF_ShadowSize, 35.0f);
	multiP->setF(TPF_RippleScale, 4.0f);
	multiP->setF(TPF_CorpseSize, 17.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_WarnPeriod, 5.0f);
	multiP->setF(TPF_FlightHeight, 100.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 200.0f);
	multiP->setF(TPF_LowerFlickPower, 0.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_LifeRecoverRate, 0.01f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 24.0f);

	multiP->setF(OTIMOTIPF_DropVelocity, 300.0f);
	multiP->setF(OTIMOTIPF_AttackStartHeight, 60.0f);
	multiP->setF(OTIMOTIPF_WaitingWashPeriod, 6.0f);
	multiP->setF(OTIMOTIPF_WaitingWashChance, 0.3f);
	multiP->setF(OTIMOTIPF_WaitingTurnPeriod, 4.0f);
	multiP->setF(OTIMOTIPF_WaitingTurnChance, 0.6f);
	multiP->setF(OTIMOTIPF_ImpassablePeriod, 4.0f);
	multiP->setF(OTIMOTIPF_ImpassableDistance, 50.0f);
	multiP->setF(OTIMOTIPF_MissFuncMinCount, 5.0f);
	multiP->setF(OTIMOTIPF_MissFuncMaxCount, 20.0f);
	multiP->setF(OTIMOTIPF_MissFuncMinChance, 0.0f);
	multiP->setF(OTIMOTIPF_MissFuncMaxChance, 0.7f);
}

/**
 * @todo: Documentation
 */
TaiOtimotiStrategy::TaiOtimotiStrategy(TekiParameters* params)
    : TaiStrategy(OTIMOTISTATE_COUNT, OTIMOTISTATE_Unk2)
{
	TaiTypeNaviWatchResultOnAction* typeNaviWatchResult  = new TaiTypeNaviWatchResultOnAction();
	TaiStopMoveAction* stopMove                          = new TaiStopMoveAction();
	TaiAccelerationAction* accel                         = new TaiAccelerationAction();
	TaiParabolaAction* parabola                          = new TaiParabolaAction();
	TaiMakingNextVelocityAction* makeNextVel             = new TaiMakingNextVelocityAction();
	TaiDeadAction* dead                                  = new TaiDeadAction(OTIMOTISTATE_Unk0);
	TaiOtimotiFlickAction* flick                         = new TaiOtimotiFlickAction(OTIMOTISTATE_Unk6);
	TaiTargetNearestAssailantAction* targetNearestAssail = new TaiTargetNearestAssailantAction(TAI_NO_TRANSIT);
	TaiTargetNearestCollisionAction* targetNearestColl1  = new TaiTargetNearestCollisionAction(TAI_NO_TRANSIT);
	TaiTargetVisibleNaviPikiAction* targetVisNaviPiki1   = new TaiTargetVisibleNaviPikiAction(TAI_NO_TRANSIT);
	TaiTargetVisibleNaviPikiAction* targetVisNaviPiki2   = new TaiTargetVisibleNaviPikiAction(OTIMOTISTATE_Unk5);
	TaiTargetNearestCollisionAction* targetNearestColl2  = new TaiTargetNearestCollisionAction(OTIMOTISTATE_Unk5);
	TaiTargetLostAction* targetLost                      = new TaiTargetLostAction(OTIMOTISTATE_Unk2);
	TaiAttackableNaviPikiAction* attackableNaviPiki      = new TaiAttackableNaviPikiAction(OTIMOTISTATE_Unk6);
	TaiOutsideTerritoryAction* outsideTerritory = new TaiOutsideTerritoryAction(OTIMOTISTATE_Unk14, params->getF(TPF_DangerTerritoryRange));
	TaiDamageAction* unusedDamage               = new TaiDamageAction(OTIMOTISTATE_Unk1);
	TaiSimultaneousDamageAction* simDamage      = new TaiSimultaneousDamageAction(TAI_NO_TRANSIT);
	TaiCounterattackSimultaneousDamageAction* counterAttackSimDamage = new TaiCounterattackSimultaneousDamageAction(OTIMOTISTATE_Unk5);
	TaiOtimotiLegEffectAction* legEffect                             = new TaiOtimotiLegEffectAction(-0.5f);
	TaiDyingAction* dying                                            = new TaiDyingAction(TekiMotion::Dead);
	TaiStartDyingAction* startDying                                  = new TaiStartDyingAction();

	//  STATE -
	TaiState* state = new TaiState(3);
	int j           = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, startDying);
	state->setAction(j++, dying);
	setState(OTIMOTISTATE_Unk0, state);

	TaiDamagingAction* damaging = new TaiDamagingAction(OTIMOTISTATE_Unk2, TekiMotion::Damage);

	//  STATE -
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, simDamage);
	state->setAction(j++, damaging);
	setState(OTIMOTISTATE_Unk1, state);

	TaiStartingTimerAction* startingTimer1 = new TaiStartingTimerAction(OTIMOTISTATE_Unk4, 0, params->getF(OTIMOTIPF_WaitingWashPeriod),
	                                                                    0.5f, params->getF(OTIMOTIPF_WaitingWashChance));
	TaiStartingTimerAction* startingTimer2
	    = new TaiStartingTimerAction(OTIMOTISTATE_Unk3, 1, params->getF(OTIMOTIPF_WaitingTurnPeriod), 0.5f,
	                                 params->getF(OTIMOTIPF_WaitingWashChance)); // is this a typo lol.

	TaiMotionAction* motion1 = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Wait1);

	//  STATE -
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, outsideTerritory);
	state->setAction(j++, counterAttackSimDamage);
	state->setAction(j++, targetNearestColl2);
	state->setAction(j++, targetVisNaviPiki2);
	state->setAction(j++, startingTimer2);
	state->setAction(j++, startingTimer1);
	state->setAction(j++, motion1);
	setState(OTIMOTISTATE_Unk2, state);

	TaiMotionAction* motion2 = new TaiMotionAction(OTIMOTISTATE_Unk2, TekiMotion::WaitAct2);

	//  STATE -
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, counterAttackSimDamage);
	state->setAction(j++, targetNearestColl2);
	state->setAction(j++, targetVisNaviPiki2);
	state->setAction(j++, motion2);
	setState(OTIMOTISTATE_Unk4, state);

	TaiWaitTurningAction* waitTurning = new TaiWaitTurningAction(OTIMOTISTATE_Unk2, TekiMotion::WaitAct1);

	//  STATE -
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, counterAttackSimDamage);
	state->setAction(j++, targetNearestColl2);
	state->setAction(j++, targetVisNaviPiki2);
	state->setAction(j++, waitTurning);
	setState(OTIMOTISTATE_Unk3, state);

	TaiTurningAction* turning = new TaiTurningAction(TAI_NO_TRANSIT, TekiMotion::WaitAct1, params->getF(TPF_TurnVelocity));
	TaiWarnAction* warn       = new TaiWarnAction();

	//  STATE -
	state = new TaiState(11);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, stopMove);
	state->setAction(j++, flick);
	state->setAction(j++, warn);
	state->setAction(j++, targetNearestAssail);
	state->setAction(j++, targetNearestColl1);
	state->setAction(j++, targetVisNaviPiki1);
	state->setAction(j++, simDamage);
	state->setAction(j++, attackableNaviPiki);
	state->setAction(j++, targetLost);
	state->setAction(j++, turning);
	setState(OTIMOTISTATE_Unk5, state);

	TaiOtimotiFailToJumpAction* failToJump = new TaiOtimotiFailToJumpAction(OTIMOTISTATE_Unk7);
	TaiOnceAction* once                    = new TaiOnceAction(OTIMOTISTATE_Unk8);

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, dead);
	state->setAction(j++, simDamage);
	state->setAction(j++, failToJump);
	state->setAction(j++, once);
	setState(OTIMOTISTATE_Unk6, state);

	TaiMotionAction* motion3 = new TaiMotionAction(OTIMOTISTATE_Unk2, TekiMotion::Damage);

	//  STATE -
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, simDamage);
	state->setAction(j++, motion3);
	setState(OTIMOTISTATE_Unk7, state);

	TaiAnimationKeyAction* animKey = new TaiAnimationKeyAction(OTIMOTISTATE_Unk9, BTeki::ANIMATION_KEY_OPTION_ACTION_0);
	TaiMotionAction* motion4       = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Flick);

	//  STATE -
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, motion4);
	state->setAction(j++, animKey);
	setState(OTIMOTISTATE_Unk8, state);

	TaiOtimotiJumpingAction* jumping                  = new TaiOtimotiJumpingAction(OTIMOTISTATE_Unk10);
	TaiOtimotiStartDroppingWaterAction* droppingWater = new TaiOtimotiStartDroppingWaterAction();

	//  STATE -
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, parabola);
	state->setAction(j++, makeNextVel);
	state->setAction(j++, jumping);
	state->setAction(j++, droppingWater);
	state->setAction(j++, typeNaviWatchResult);
	setState(OTIMOTISTATE_Unk9, state);

	TaiOtimotiAirWaitingAction* airWaiting = new TaiOtimotiAirWaitingAction(OTIMOTISTATE_Unk11);
	TaiMotionAction* motion5               = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Wait2);

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, motion5);
	state->setAction(j++, accel);
	state->setAction(j++, makeNextVel);
	state->setAction(j++, airWaiting);
	setState(OTIMOTISTATE_Unk10, state);

	TaiSerialAction* dropThenPressThenBounce = new TaiSerialAction(OTIMOTISTATE_Unk12, 3);
	dropThenPressThenBounce->setAction(0, new TaiOtimotiDroppingAction(TAI_NO_TRANSIT));
	dropThenPressThenBounce->setAction(1, new TaiOtimotiPressingAction(TAI_NO_TRANSIT));
	dropThenPressThenBounce->setAction(2, new TaiOtimotiBouncingAction(TAI_NO_TRANSIT));

	TaiMotionAction* motion6 = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Type1);

	//  STATE -
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, simDamage);
	state->setAction(j++, motion6);
	state->setAction(j++, dropThenPressThenBounce);
	setState(OTIMOTISTATE_Unk11, state);

	TaiOtimotiAttackingAction* attacking             = new TaiOtimotiAttackingAction(OTIMOTISTATE_Unk13);
	TaiOtimotiAttackingEffectAction* attackingEffect = new TaiOtimotiAttackingEffectAction();

	//  STATE -
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, simDamage);
	state->setAction(j++, attacking);
	state->setAction(j++, attackingEffect);
	setState(OTIMOTISTATE_Unk12, state);

	TaiTimerAction* timer    = new TaiTimerAction(OTIMOTISTATE_Unk2, 0, params->getF(TPF_UnguardedPeriod), 0.0f);
	TaiMotionAction* motion7 = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Wait1);

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, simDamage);
	state->setAction(j++, timer);
	state->setAction(j++, motion7);
	setState(OTIMOTISTATE_Unk13, state);

	TaiTurningToTargetPositionAction* turningToTargetPos
	    = new TaiTurningToTargetPositionAction(OTIMOTISTATE_Unk15, TekiMotion::WaitAct1, params->getF(TPF_TurnVelocity));
	TaiTargetNestAction* targetNest = new TaiTargetNestAction();

	//  STATE -
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, stopMove);
	state->setAction(j++, flick);
	state->setAction(j++, simDamage);
	state->setAction(j++, targetNest);
	state->setAction(j++, turningToTargetPos);
	setState(OTIMOTISTATE_Unk14, state);

	TaiImpassableAction* impassable           = new TaiImpassableAction(OTIMOTISTATE_Unk16, 0, params->getF(OTIMOTIPF_ImpassablePeriod),
	                                                                    params->getF(OTIMOTIPF_ImpassableDistance));
	TaiInsideTerritoryAction* insideTerritory = new TaiInsideTerritoryAction(OTIMOTISTATE_Unk16, params->getF(TPF_SafetyTerritoryRange));
	TaiGoingHomeAction* goingHome             = new TaiGoingHomeAction(TekiMotion::Move1, params->getF(TPF_RunVelocity));
	TaiOutsideKeyStopMoveAction* outsideKeyStopMove = new TaiOutsideKeyStopMoveAction(2, 3);

	//  STATE -
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, simDamage);
	state->setAction(j++, insideTerritory);
	state->setAction(j++, goingHome);
	state->setAction(j++, impassable);
	state->setAction(j++, outsideKeyStopMove);
	state->setAction(j++, legEffect);
	setState(OTIMOTISTATE_Unk15, state);

	TaiFinishMotionAction* finishMotion = new TaiFinishMotionAction(OTIMOTISTATE_Unk2);

	//  STATE -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, dead);
	state->setAction(j++, flick);
	state->setAction(j++, simDamage);
	state->setAction(j++, finishMotion);
	state->setAction(j++, outsideKeyStopMove);
	setState(OTIMOTISTATE_Unk16, state);
}

/**
 * @todo: Documentation
 */
void TaiOtimotiStrategy::start(Teki& teki)
{
	teki.mParticleGenerators[0] = effectMgr->create(EffectMgr::EFF_Frog_Water2, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	teki.stopParticleGenerator(0);

	teki.mParticleGenerators[1] = effectMgr->create(EffectMgr::EFF_Frog_Water1, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	teki.stopParticleGenerator(1);

	TaiStrategy::start(teki);
}

/**
 * @todo: Documentation
 */
void TaiOtimotiStrategy::draw(Teki& teki, Graphics& gfx)
{
	TekiStrategy::draw(teki, gfx);
	if (!teki.mParticleGenerators[0]) {
		return;
	}

	NVector3f dir;
	teki.outputDirectionVector(dir);
	teki.setParticleGeneratorDirection(0, dir);
	NVector3f pos;
	teki.outputPosition(pos);
	pos.y += 0.0f;
	teki.setParticleGeneratorPosition(0, pos);

	teki.outputDirectionVector(dir);
	teki.setParticleGeneratorDirection(1, dir);
	teki.outputPosition(pos);
	pos.y += 0.0f;
	teki.setParticleGeneratorPosition(1, pos);
}

/**
 * @todo: Documentation
 */
void TaiOtimotiStrategy::drawDebugInfo(Teki& teki, Graphics& gfx)
{
	teki.drawRange(gfx, teki.getPosition(), teki.getParameterF(TPF_VisibleRange), Colour(0, 0, 255, 255));
	teki.drawRange(gfx, teki.getPosition(), teki.getAttackableRange(), Colour(255, 255, 0, 255));
	teki.drawRange(gfx, teki.getPosition(), teki.getAttackRange(), Colour(255, 0, 0, 255));
	teki.drawRange(gfx, teki.getPosition(), teki.getLowerRange(), Colour(255, 0, 255, 255));
}

/**
 * @todo: Documentation
 */
void TaiOtimotiStartDroppingWaterAction::start(Teki& teki)
{
	int attr = teki.getPositionMapCode();
	PRINT_NAKATA("TaiOtimotiStartDroppingWaterAction::start:%08x:mapCode:%d\n", &teki, attr);
	if (attr == ATTR_Water) {
		teki.startParticleGenerator(0);
	} else {
		teki.startParticleGenerator(1);
	}
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiFlickAction::act(Teki& teki)
{
	int pikiNum    = teki.countPikis(TekiAndCondition(&TekiRecognitionCondition(&teki), &TekiLowerRangeCondition(&teki)));
	int flickCount = teki.getFlickDamageCount(pikiNum);

	if (teki.mDamageCount >= f32(flickCount)) {
		PRINT_NAKATA("TaiOtimotiFlickAction::act:%08x:%d,%d,%d\n", &teki, pikiNum, teki.mDamageCount, flickCount);
		teki.mTargetPosition.input(teki.getPosition());
		teki.setCreaturePointer(0, nullptr);
		return true;
	}

	return false;

	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiFailToJumpAction::act(Teki& teki)
{
	int pikiNum = teki.countPikis(TekiAndCondition(&TekiRecognitionCondition(&teki), &TekiLowerCondition(&teki)));
	f32 linValues[2];
	NClampLinearFunction linFunc(linValues);
	linFunc.makeClampLinearFunction(teki.getParameterF(OTIMOTIPF_MissFuncMinCount), teki.getParameterF(OTIMOTIPF_MissFuncMinChance),
	                                teki.getParameterF(OTIMOTIPF_MissFuncMaxCount), teki.getParameterF(OTIMOTIPF_MissFuncMaxChance));
	f32 failChance = linFunc.getValue(f32(pikiNum));
	PRINT_NAKATA("TaiOtimotiFailToJumpAction::act:%08x:%f,%d\n", &teki, failChance, pikiNum);
	if (NMathF::occurred(failChance)) {
		return true;
	}

	return false;

	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
}

/**
 * @todo: Documentation
 */
void TaiOtimotiJumpingAction::start(Teki& teki)
{
	teki.startFlying();
	teki.flickLower();
	Creature* target = teki.getCreaturePointer(0);
	if (target) {
		target->outputPosition(teki.mTargetPosition);
	}

	Vector3f pos(teki.getPosition());
	NVector3f dir;
	dir.sub2(teki.mTargetPosition, pos);
	dir.y     = 0.0f;
	f32 range = teki.getAttackableRange();
	if (dir.length() > range) {
		dir.normalizeCheck();
		dir.scale(range);
	}

	dir.scale(0.7f);
	f32 gravity = teki.getGravity();
	f32 height  = teki.getParameterF(TPF_FlightHeight);
	f32 val     = NMathF::sqrt(2.0f * gravity * height);
	f32 val2    = val / gravity;

	NVector3f tmp;
	tmp.add2(pos, dir);
	f32 dist = tmp.distance(pos);
	f32 val3 = dist / val2;

	NVector3f vec1;
	vec1.sub2(tmp, pos);
	vec1.normalizeCheck();
	vec1.scale(val3);
	vec1.y = val;

	teki.mPositionIO.input(NVector3f(teki.getPosition()));
	teki.mParabolaEvent->makeParabolaEvent(nullptr, &teki.mPositionIO, vec1, 1000.0f, gravity);
	teki.mParabolaEvent->reset();

	if (teki.inWaterTeki()) {
		teki.playSound(SE_FLOG_WATERJUMP);
	} else {
		teki.playSound(SE_FLOG_HIJUMP);
	}
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiJumpingAction::act(Teki& teki)
{
	NVector3f vec;
	teki.mParabolaEvent->_2C.output(vec);
	if (vec.y <= 0.0f) {
		vec.y = 0.0f;
		teki.mActionVelocity.input(vec);
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
void TaiOtimotiAirWaitingAction::start(Teki& teki)
{
	teki.mPositionIO.input(NVector3f(teki.getPosition()));
	teki.mVelocityIO.input(NVector3f(teki.mActionVelocity));
	NVector3f accel(teki.mActionVelocity);
	accel.normalizeCheck();
	accel.negate();
	accel.scale(1000.0f);
	teki.mAccelerationIO.input(accel);
	teki.mAccelEvent->makeAccelerationEvent(nullptr, &teki.mPositionIO, &teki.mVelocityIO, &teki.mAccelerationIO);
	teki.mAccelEvent->reset();
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiAirWaitingAction::act(Teki& teki)
{
	bool check = true;
	NVector3f vec1(teki.mActionVelocity);
	if (vec1.normalizeCheck()) {
		NVector3f vec2;
		teki.mVelocityIO.output(vec2);
		if (vec2.normalizeCheck()) {
			if (vec2.dot(vec1) > 0.1f) {
				check = false;
			}
		}
	}
	STACK_PAD_VAR(1);

	if (check) {
		teki.stopMove();
	}

	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		PRINT_NAKATA("TaiOtimotiAirWaiting::act:%08x:ACTION_0\n", &teki);
		teki.stopParticleGenerator(0);
		teki.stopParticleGenerator(1);

	} else if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_LOOPEND)) {
		PRINT_NAKATA("TaiOtimotiAirWaiting::act:%08x:LOOPEND\n", &teki);
		return true;
	}
	return false;

	STACK_PAD_TERNARY(check, 2);
}

/**
 * @todo: Documentation
 */
void TaiOtimotiDroppingAction::start(Teki& teki)
{
	teki.finishFlying();
	teki.mActionVelocity.set(0.0f, -teki.getParameterF(OTIMOTIPF_DropVelocity), 0.0f);
	teki.setTekiOption(BTeki::TEKI_OPTION_GRAVITATABLE);
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiDroppingAction::act(Teki& teki)
{
	if (teki.getYFromSeaLevel() <= teki.getParameterF(OTIMOTIPF_AttackStartHeight)) {
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiDroppingAction::actByEvent(immut TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Ground) {
		PRINT_NAKATA("!TaiOtimotiDroppingAction::actByEvent:EVENT_BOUNCED:%08x\n", event.mTeki);
		event.mTeki->finishFlying();
		event.mTeki->clearTekiOption(BTeki::TEKI_OPTION_GRAVITATABLE);
	}
	return false;
}

/**
 * @todo: Documentation
 */
void TaiOtimotiPressingAction::start(Teki& teki)
{
	teki.startMotion(TekiMotion::Attack);
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiPressingAction::act(Teki& teki)
{
	f32 seaLevel = teki.getSeaLevel();
	if (teki.getPosition().y <= seaLevel + 1.0f) {
		teki.getPosition().y = seaLevel;
		return true;
	}
	return false;
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiPressingAction::actByEvent(immut TekiEvent& event)
{
	if (event.mEventType == TekiEventType::Ground) {
		event.mTeki->finishFlying();
		event.mTeki->clearTekiOption(BTeki::TEKI_OPTION_GRAVITATABLE);
		Teki* teki = event.mTeki;

		InteractPress NRef press = InteractPress(teki, teki->getParameterF(TPF_AttackPower));
		TekiAndCondition NRef cond
		    = TekiAndCondition(&TekiRecognitionCondition(teki), &TekiAndCondition(&TekiDistanceCondition(teki, teki->getAttackRange()),
		                                                                          &TekiNotCondition(&TekiStickerCondition(teki))));
		teki->interactNaviPiki(press, cond);
		teki->flickUpper();
		teki->mDamageCount = 0.0f;
		cameraMgr->startVibrationEvent(3, teki->getPosition());
		rumbleMgr->start(RUMBLE_Unk4, 0, teki->getPosition());
		return true;
	}

	return false;

	// lol.
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiBouncingAction::act(Teki& teki)
{
	return true;
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiBouncingAction::actByEvent(immut TekiEvent&)
{
	return false;
}

/**
 * @todo: Documentation
 */
void TaiOtimotiAttackingAction::start(Teki& teki)
{
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiAttackingAction::act(Teki& teki)
{
	f32 seaLevel = teki.getSeaLevel();
	if (teki.getPosition().y <= seaLevel + 1.0f) {
		teki.getPosition().y = seaLevel;
		teki.finishFlying();
		teki.clearTekiOption(BTeki::TEKI_OPTION_GRAVITATABLE);
	}

	if (teki.animationFinished()) {
		return true;
	}

	f32 unused = teki.mTekiAnimator->getCounter();

	if (teki.mTekiAnimator->isFinished()) {
		PRINT_NAKATA("!TaiOtimotiAttackingAction::act:%08x:FINISHED\n", &teki);
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool TaiOtimotiAttackingAction::actByEvent(immut TekiEvent&)
{
	return false;
}

/**
 * @todo: Documentation
 */
void TaiOtimotiAttackingEffectAction::start(Teki& teki)
{
	int attr = teki.getPositionMapCode();
	PRINT_NAKATA("TaiOtimotiAttackingEffectAction::start:%08x:mapCode:%d\n", &teki, attr);
	Vector3f pos(teki.getPosition());
	pos.y = mapMgr->getMinY(pos.x, pos.z, true);
	if (attr == ATTR_Water) {
		effectMgr->create(EffectMgr::EFF_Frog_BubbleRingS, pos, nullptr, nullptr);
		teki.playSound(SE_FLOG_WATERLAND);
	} else {
		effectMgr->create(EffectMgr::EFF_Frog_BubbleRingL, pos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Frog_Bubble2, pos, nullptr, nullptr);
		teki.playSound(SE_FLOG_LAND);
	}
}

/**
 * @todo: Documentation
 */
TaiOtimotiLegEffectAction::TaiOtimotiLegEffectAction(f32 sinkThreshold)
    : TaiJointEffectAction(sinkThreshold, 2, 'lleg', 'rleg', 0, 0)
{
}

/**
 * @todo: Documentation
 */
void TaiOtimotiLegEffectAction::setType(Vector3f& effectPos, int type, int id)
{
	effectPos.y = mapMgr->getMinY(effectPos.x, effectPos.z, true);
	if (type == 5) {
		mEffectType = EffectMgr::EFF_P_Bubbles;
	} else {
		mEffectType = EffectMgr::EFF_SmokeRing_S;
	}

	mSoundID = -1;
}
