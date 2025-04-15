#include "TAI/Napkid.h"
#include "TAI/MoveActions.h"
#include "TAI/JudgementActions.h"
#include "TAI/ReactionActions.h"
#include "TAI/AttackActions.h"
#include "TAI/TimerActions.h"
#include "TAI/EffectActions.h"
#include "TekiConditions.h"
#include "DebugLog.h"
#include "SoundID.h"
#include "nlib/Math.h"
#include "teki.h"
#include "PikiState.h"
#include "PikiMgr.h"
#include "Peve/MotionEvents.h"
#include "MapCode.h"
#include "Stickers.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("tainapkid")

/*
 * --INFO--
 * Address:	80135C20
 * Size:	000084
 */
TaiNapkidSoundTable::TaiNapkidSoundTable()
    : PaniSoundTable(4)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(SE_SARAI_HOVER + i);
	}
}

/*
 * --INFO--
 * Address:	80135CA4
 * Size:	000564
 */
TaiNapkidParameters::TaiNapkidParameters()
    : TekiParameters(NAPKIDPI_COUNT, NAPKIDPF_COUNT)
{
	int i                           = NAPKIDPI_Unk0;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	iParams[i++].init("STRUGGLE_LOOP_COUNT", 0, 10);

	int j                           = NAPKIDPF_Unk0;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("CARRYING_VELOCITY", 0.0f, 200.0f);
	fParams[j++].init("CARRYING_FLIGHT_HEIGHT", 0.0f, 200.0f);
	fParams[j++].init("TAKING_OFF_FLIGHT_HEIGHT", 0.0f, 200.0f);
	fParams[j++].init("WANDERING_HOVER_PERIOD", 0.0f, 60.0f);
	fParams[j++].init("WANDERING_HOVER_PROBABILITY", 0.0f, 1.0f);
	fParams[j++].init("HOVERING_WANDER_PERIOD", 0.0f, 60.0f);
	fParams[j++].init("HOVERING_WANDER_PROBABILITY", 0.0f, 1.0f);
	fParams[j++].init("HOVERING_WASH_PERIOD", 0.0f, 60.0f);
	fParams[j++].init("HOVERING_WASH_PROBABILITY", 0.0f, 1.0f);
	fParams[j++].init("WASHING_WANDER_PERIOD", 0.0f, 60.0f);
	fParams[j++].init("WASHING_WANDER_PROBABILITY", 0.0f, 1.0f);
	fParams[j++].init("THROW_PERIOD", 0.0f, 10.0f);
	fParams[j++].init("THROW_VELOCITY", 0.0f, 1000.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_CarcassSize, 2);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_SwallowCount, 1);
	multiP->setI(TPI_CullingType, 1);
	multiP->setI(TPI_FlickPikiCount1, 3);
	multiP->setI(TPI_FlickPikiCount2, 8);
	multiP->setI(TPI_FlickPikiCount3, 15);
	multiP->setI(TPI_FlickDamageCount1, 5);
	multiP->setI(TPI_FlickDamageCount2, 10);
	multiP->setI(TPI_FlickDamageCount3, 15);
	multiP->setI(TPI_FlickDamageCount4, 20);

	multiP->setF(TPF_Life, 2000.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, 1.0f);
	multiP->setF(TPF_WalkVelocity, 60.0f);
	multiP->setF(TPF_RunVelocity, 100.0f);
	multiP->setF(TPF_VisibleRange, 420.0f);
	multiP->setF(TPF_VisibleAngle, 180.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 200.0f);
	multiP->setF(TPF_AttackableAngle, NMathF::pi / 3.0f);
	multiP->setF(TPF_AttackRange, 12.0f);
	multiP->setF(TPF_AttackHitRange, 15.0f);
	multiP->setF(TPF_LowerRange, 20.0f);
	multiP->setF(TPF_DangerTerritoryRange, 500.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 10.0f);
	multiP->setF(TPF_LifeGaugeOffset, 30.0f);
	multiP->setF(TPF_ShadowSize, 50.0f);
	multiP->setF(TPF_RippleScale, 2.0f);
	multiP->setF(TPF_CorpseSize, 17.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 60.0f);
	multiP->setF(TPF_LowerFlickPower, 50.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_FlightHeight, 85.0f);
	multiP->setF(TPF_LifeRecoverRate, 0.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 16.0f);

	multiP->setI(NAPKIDPI_Unk0, 1);

	multiP->setF(NAPKIDPF_Unk0, 90.0f);
	multiP->setF(NAPKIDPF_Unk1, 60.0f);
	multiP->setF(NAPKIDPF_Unk2, 60.0f);
	multiP->setF(NAPKIDPF_Unk3, 3.0f);
	multiP->setF(NAPKIDPF_Unk4, 0.5f);
	multiP->setF(NAPKIDPF_Unk5, 3.0f);
	multiP->setF(NAPKIDPF_Unk6, 0.5f);
	multiP->setF(NAPKIDPF_Unk7, 3.0f);
	multiP->setF(NAPKIDPF_Unk8, 0.2f);
	multiP->setF(NAPKIDPF_Unk9, 3.0f);
	multiP->setF(NAPKIDPF_Unk10, 0.7f);
	multiP->setF(NAPKIDPF_Unk11, 4.0f);
	multiP->setF(NAPKIDPF_Unk12, 200.0f);
}

/*
 * --INFO--
 * Address:	80136208
 * Size:	0022C4
 */
TaiNapkidStrategy::TaiNapkidStrategy(TekiParameters* params)
    : TaiStrategy(NAPKIDSTATE_COUNT, NAPKIDSTATE_Unk1)
{
	TaiStopMoveAction* stopMove                      = new TaiStopMoveAction;
	TaiStartFlyingAction* startFlying                = new TaiStartFlyingAction;
	TaiFinishFlyingAction* finishFlying              = new TaiFinishFlyingAction;
	TaiAccelerationAction* acceleration              = new TaiAccelerationAction;
	TaiParabolaAction* parabola                      = new TaiParabolaAction;
	TaiCircleMoveAction* circleMove                  = new TaiCircleMoveAction;
	TaiMakingNextVelocityAction* makingNextVel       = new TaiMakingNextVelocityAction;
	TaiMakeVelocityDirectionAction* makeVelDir       = new TaiMakeVelocityDirectionAction;
	TaiMakeAccelerationDirectionAction* makeAccelDir = new TaiMakeAccelerationDirectionAction;
	TaiHasStickersOnBodyAction* stickersOnBody1      = new TaiHasStickersOnBodyAction(NAPKIDSTATE_Unk15);
	TaiDeadAction* dead1                             = new TaiDeadAction(NAPKIDSTATE_Unk15);
	TaiDeadAction* dead2                             = new TaiDeadAction(NAPKIDSTATE_Dying);
	TaiFlickAction* flick                            = new TaiFlickAction(NAPKIDSTATE_Unk21);
	TaiNapkidTargetPikiAction* targetPiki1           = new TaiNapkidTargetPikiAction(NAPKIDSTATE_Unk4);
	TaiSimultaneousDamageAction* simDamage           = new TaiSimultaneousDamageAction(TAI_NO_TRANSIT);
	TaiNapkidFlyingAction* napkidFlying1             = new TaiNapkidFlyingAction(params->getF(TPF_FlightHeight));
	TaiNapkidFlyingAction* napkidFlying2             = new TaiNapkidFlyingAction(params->getF(NAPKIDPF_Unk1));
	TaiDyingAction* dying                            = new TaiDyingAction(NAPKIDANIM_Unk0);
	TaiStartDyingAction* startDying                  = new TaiStartDyingAction;

	// STATE 0 - Dying
	TaiState* stateDying = new TaiState(3);
	int j                = 0;
	stateDying->setAction(j++, stopMove);
	stateDying->setAction(j++, startDying);
	stateDying->setAction(j++, dying);
	setState(NAPKIDSTATE_Dying, stateDying);

	TaiNapkidWanderingRouteAction* wanderRoute1 = new TaiNapkidWanderingRouteAction(NAPKIDANIM_Unk6, params->getF(TPF_WalkVelocity));
	TaiStartingTimerAction* chanceTimer1
	    = new TaiStartingTimerAction(NAPKIDSTATE_Unk2, 0, params->getF(NAPKIDPF_Unk3), 0.5f, params->getF(NAPKIDPF_Unk4));
	TaiHeadOnCollisionAvoidanceAction* headOnAvoidance = new TaiHeadOnCollisionAvoidanceAction(50.0f);

	// STATE 1 - Wandering?
	TaiState* stateWandering = new TaiState(9);
	j                        = 0;
	stateWandering->setAction(j++, startFlying);
	stateWandering->setAction(j++, simDamage);
	stateWandering->setAction(j++, stickersOnBody1);
	stateWandering->setAction(j++, dead1);
	stateWandering->setAction(j++, targetPiki1);
	stateWandering->setAction(j++, napkidFlying1);
	stateWandering->setAction(j++, chanceTimer1);
	stateWandering->setAction(j++, wanderRoute1);
	stateWandering->setAction(j++, headOnAvoidance);
	setState(NAPKIDSTATE_Unk1, stateWandering);

	TaiContinuousMotionAction* continousMotion1 = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk6);
	TaiStartingTimerAction* chanceTimer2
	    = new TaiStartingTimerAction(NAPKIDSTATE_Unk1, 0, params->getF(NAPKIDPF_Unk5), 0.5f, params->getF(NAPKIDPF_Unk6));
	TaiStartingTimerAction* chanceTimer3
	    = new TaiStartingTimerAction(NAPKIDSTATE_Unk3, 1, params->getF(NAPKIDPF_Unk7), 0.5f, params->getF(NAPKIDPF_Unk8));

	// STATE 2 - Idle?
	TaiState* stateIdle = new TaiState(9);
	j                   = 0;
	stateIdle->setAction(j++, stopMove);
	stateIdle->setAction(j++, simDamage);
	stateIdle->setAction(j++, stickersOnBody1);
	stateIdle->setAction(j++, dead1);
	stateIdle->setAction(j++, targetPiki1);
	stateIdle->setAction(j++, napkidFlying1);
	stateIdle->setAction(j++, chanceTimer2);
	stateIdle->setAction(j++, chanceTimer3);
	stateIdle->setAction(j++, continousMotion1);
	setState(NAPKIDSTATE_Unk2, stateIdle);

	TaiStartingTimerAction* chanceTimer4
	    = new TaiStartingTimerAction(NAPKIDSTATE_Unk1, 0, params->getF(NAPKIDPF_Unk9), 0.5f, params->getF(NAPKIDPF_Unk10));
	TaiContinuousMotionAction* continousMotion2 = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk2);

	// STATE 3 - Go home?
	TaiState* stateGoHome = new TaiState(7);
	j                     = 0;
	stateGoHome->setAction(j++, simDamage);
	stateGoHome->setAction(j++, stickersOnBody1);
	stateGoHome->setAction(j++, dead1);
	stateGoHome->setAction(j++, targetPiki1);
	stateGoHome->setAction(j++, napkidFlying1);
	stateGoHome->setAction(j++, chanceTimer4);
	stateGoHome->setAction(j++, continousMotion2);
	setState(NAPKIDSTATE_Unk3, stateGoHome);

	TaiNapkidTargetPikiAction* targetPiki2    = new TaiNapkidTargetPikiAction(TAI_NO_TRANSIT);
	TaiNapkidApproachPikiAction* approachPiki = new TaiNapkidApproachPikiAction(NAPKIDSTATE_Unk7);
	TaiNapkidPikiLostAction* lostPiki         = new TaiNapkidPikiLostAction(NAPKIDSTATE_Unk1);
	TaiNapkidShortRangeAction* shortRange     = new TaiNapkidShortRangeAction(NAPKIDSTATE_Unk5);
	TaiTracingAction* tracing                 = new TaiTracingAction(NAPKIDANIM_Unk6, params->getF(TPF_RunVelocity));

	// STATE 4 - Chasing?
	TaiState* stateChase = new TaiState(9);
	j                    = 0;
	stateChase->setAction(j++, simDamage);
	stateChase->setAction(j++, stickersOnBody1);
	stateChase->setAction(j++, dead1);
	stateChase->setAction(j++, approachPiki);
	stateChase->setAction(j++, targetPiki2);
	stateChase->setAction(j++, shortRange);
	stateChase->setAction(j++, napkidFlying1);
	stateChase->setAction(j++, lostPiki);
	stateChase->setAction(j++, tracing);
	setState(NAPKIDSTATE_Unk4, stateChase);

	TaiNapkidStraightFlyingAction* straightFlying = new TaiNapkidStraightFlyingAction(NAPKIDSTATE_Unk6, 160.0f);
	TaiTimerAction* timer                         = new TaiTimerAction(NAPKIDSTATE_Unk6, 0, 5.0f, 0.0f);
	TaiContinuousMotionAction* continousMotion3   = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk6);

	// STATE 5 - Outrun target?
	TaiState* stateOutrun = new TaiState(8);
	j                     = 0;
	stateOutrun->setAction(j++, simDamage);
	stateOutrun->setAction(j++, stickersOnBody1);
	stateOutrun->setAction(j++, dead1);
	stateOutrun->setAction(j++, approachPiki);
	stateOutrun->setAction(j++, napkidFlying1);
	stateOutrun->setAction(j++, straightFlying);
	stateOutrun->setAction(j++, timer);
	stateOutrun->setAction(j++, continousMotion3);
	setState(NAPKIDSTATE_Unk5, stateOutrun);

	TaiNapkidCirclingAction* circling       = new TaiNapkidCirclingAction(NAPKIDSTATE_Unk1);
	TaiMakingNextDriveAction* makeNextDrive = new TaiMakingNextDriveAction(150.0f);

	// STATE 6 - Circle target?
	TaiState* stateCircle = new TaiState(6);
	j                     = 0;
	stateCircle->setAction(j++, simDamage);
	stateCircle->setAction(j++, stickersOnBody1);
	stateCircle->setAction(j++, dead1);
	stateCircle->setAction(j++, circleMove);
	stateCircle->setAction(j++, makeNextDrive);
	stateCircle->setAction(j++, circling);
	setState(NAPKIDSTATE_Unk6, stateCircle);

	TaiFinishMotionAction* finishMotion1 = new TaiFinishMotionAction(NAPKIDSTATE_Unk8);

	// STATE 7 - (Unknown)
	TaiState* state7 = new TaiState(5);
	j                = 0;
	state7->setAction(j++, simDamage);
	state7->setAction(j++, stickersOnBody1);
	state7->setAction(j++, dead1);
	state7->setAction(j++, napkidFlying1);
	state7->setAction(j++, finishMotion1);
	setState(NAPKIDSTATE_Unk7, state7);

	TaiNapkidCatchTracingAction* catchTracing       = new TaiNapkidCatchTracingAction;
	TaiNapkidCatchingAction* catching               = new TaiNapkidCatchingAction(NAPKIDSTATE_Unk10);
	TaiMotionAction* motion1                        = new TaiMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk8);
	TaiNapkidCatchDescendingAction* catchDescending = new TaiNapkidCatchDescendingAction;
	TaiClampMinHeightAction* clampMinHeight1        = new TaiClampMinHeightAction(NAPKIDSTATE_Unk9, 10.0f);

	// STATE 8 - (Unknown)
	TaiState* state8 = new TaiState(9);
	j                = 0;
	state8->setAction(j++, simDamage);
	state8->setAction(j++, catchDescending);
	state8->setAction(j++, catchTracing);
	state8->setAction(j++, acceleration);
	state8->setAction(j++, clampMinHeight1);
	state8->setAction(j++, makingNextVel);
	state8->setAction(j++, motion1);
	state8->setAction(j++, catching);
	state8->setAction(j++, makeVelDir);
	setState(NAPKIDSTATE_Unk8, state8);

	TaiNapkidCatchFlyingAction* catchFlying  = new TaiNapkidCatchFlyingAction;
	TaiClampMinHeightAction* clampMinHeight2 = new TaiClampMinHeightAction(TAI_NO_TRANSIT, 10.0f);

	// State 9 - (Unknown)
	TaiState* state9 = new TaiState(8);
	j                = 0;
	state9->setAction(j++, simDamage);
	state9->setAction(j++, catchFlying);
	state9->setAction(j++, catchTracing);
	state9->setAction(j++, acceleration);
	state9->setAction(j++, clampMinHeight2);
	state9->setAction(j++, makingNextVel);
	state9->setAction(j++, catching);
	state9->setAction(j++, makeVelDir);
	setState(NAPKIDSTATE_Unk9, state9);

	TaiHasStickersInMouthAction* stickersInMouth = new TaiHasStickersInMouthAction(NAPKIDSTATE_Unk11);
	TaiOnceAction* once1                         = new TaiOnceAction(NAPKIDSTATE_Unk12);

	// STATE 10 - (Unknown)
	TaiState* state10 = new TaiState(5);
	j                 = 0;
	state10->setAction(j++, acceleration);
	state10->setAction(j++, clampMinHeight2);
	state10->setAction(j++, makingNextVel);
	state10->setAction(j++, stickersInMouth);
	state10->setAction(j++, once1);
	setState(NAPKIDSTATE_Unk10, state10);

	TaiNapkidCatchAscendingAction* ascending = new TaiNapkidCatchAscendingAction;
	TaiClampMaxHeightAction* clampMaxHeight1 = new TaiClampMaxHeightAction(NAPKIDSTATE_Unk1, params->getF(TPF_FlightHeight));

	TaiSerialAction* serial1            = new TaiSerialAction(NAPKIDSTATE_Unk19, 2);
	TaiSwitchMotionAction* switchMotion = new TaiSwitchMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk13);
	serial1->setAction(0, switchMotion);

	TaiMotionAction* motion2 = new TaiMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk6);
	serial1->setAction(1, motion2);

	// STATE 12 - (Unknown)
	TaiState* state12 = new TaiState(7);
	j                 = 0;
	state12->setAction(j++, simDamage);
	state12->setAction(j++, acceleration);
	state12->setAction(j++, clampMinHeight2);
	state12->setAction(j++, makingNextVel);
	state12->setAction(j++, serial1);
	state12->setAction(j++, ascending);
	state12->setAction(j++, clampMaxHeight1);
	setState(NAPKIDSTATE_Unk12, state12);

	TaiNapkidCatchAscendingAction* catchAscending = new TaiNapkidCatchAscendingAction;
	TaiClampMaxHeightAction* clampMaxHeight2      = new TaiClampMaxHeightAction(NAPKIDSTATE_Unk13, params->getF(NAPKIDPF_Unk1));
	TaiContinuousMotionAction* continousMotion4   = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk5);

	// STATE 11 - (Unknown)
	TaiState* state11 = new TaiState(7);
	j                 = 0;
	state11->setAction(j++, simDamage);
	state11->setAction(j++, continousMotion4);
	state11->setAction(j++, catchAscending);
	state11->setAction(j++, acceleration);
	state11->setAction(j++, clampMinHeight2);
	state11->setAction(j++, clampMaxHeight2);
	state11->setAction(j++, makingNextVel);
	setState(NAPKIDSTATE_Unk11, state11);

	TaiNapkidWanderingRouteAction* wanderRoute2 = new TaiNapkidWanderingRouteAction(NAPKIDANIM_Unk5, params->getF(NAPKIDPF_Unk0));
	TaiTimerAction* timer2                      = new TaiTimerAction(NAPKIDSTATE_Unk14, 0, params->getF(NAPKIDPF_Unk11), 0.5f);

	// STATE 13 - (Unknown)
	TaiState* state13 = new TaiState(6);
	j                 = 0;
	state13->setAction(j++, simDamage);
	state13->setAction(j++, stickersOnBody1);
	state13->setAction(j++, dead1);
	state13->setAction(j++, timer2);
	state13->setAction(j++, wanderRoute2);
	state13->setAction(j++, napkidFlying2);
	setState(NAPKIDSTATE_Unk13, state13);

	TaiContinuousMotionAction* continousMotion5 = new TaiContinuousMotionAction(NAPKIDSTATE_Unk13, NAPKIDANIM_Unk4);
	TaiNapkidThrowingPikiAction* throwPiki      = new TaiNapkidThrowingPikiAction;
	TaiNotAction* notStickersInMouth            = new TaiNotAction(NAPKIDSTATE_Unk1, new TaiHasStickersInMouthAction(TAI_NO_TRANSIT));

	// STATE 14 - (Unknown)
	TaiState* state14 = new TaiState(5);
	j                 = 0;
	state14->setAction(j++, stickersOnBody1);
	state14->setAction(j++, dead1);
	state14->setAction(j++, continousMotion5);
	state14->setAction(j++, throwPiki);
	state14->setAction(j++, notStickersInMouth);
	setState(NAPKIDSTATE_Unk14, state14);

	TaiMotionAction* motion3                  = new TaiMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk10);
	TaiNapkidFallingAction* napkidFalling     = new TaiNapkidFallingAction;
	TaiNapkidShockFallingAction* shockFalling = new TaiNapkidShockFallingAction;
	TaiRotatingAction* rotating1              = new TaiRotatingAction(NMathF::pi * 8.0f);
	TaiClampMinHeightAction* clampMinHeight3  = new TaiClampMinHeightAction(NAPKIDSTATE_Unk17, 10.0f);

	// STATE 15 - Falling?
	TaiState* state15 = new TaiState(8);
	j                 = 0;
	state15->setAction(j++, simDamage);
	state15->setAction(j++, shockFalling);
	state15->setAction(j++, motion3);
	state15->setAction(j++, napkidFalling);
	state15->setAction(j++, rotating1);
	state15->setAction(j++, parabola);
	state15->setAction(j++, clampMinHeight3);
	state15->setAction(j++, makingNextVel);
	setState(NAPKIDSTATE_Unk15, state15);

	TaiRotatingAction* rotating2 = new TaiRotatingAction(NMathF::pi * 4.0f);

	// STATE 16 - ...Also falling?
	TaiState* state16 = new TaiState(8);
	j                 = 0;
	state16->setAction(j++, simDamage);
	state16->setAction(j++, motion3);
	state16->setAction(j++, napkidFalling);
	state16->setAction(j++, rotating2);
	state16->setAction(j++, parabola);
	state16->setAction(j++, clampMinHeight3);
	state16->setAction(j++, makingNextVel);
	state16->setAction(j++, makingNextVel);
	setState(NAPKIDSTATE_Unk16, state16);

	TaiFinishMotionAction* finishMotion2                  = new TaiFinishMotionAction(NAPKIDSTATE_Unk18);
	TaiNapkidFallingWaterEffectAction* fallingWaterEffect = new TaiNapkidFallingWaterEffectAction;

	// STATE 18 - Falling in water?
	TaiState* state17 = new TaiState(5);
	j                 = 0;
	state17->setAction(j++, stopMove);
	state17->setAction(j++, finishFlying);
	state17->setAction(j++, simDamage);
	state17->setAction(j++, finishMotion2);
	state17->setAction(j++, fallingWaterEffect);
	setState(NAPKIDSTATE_Unk17, state17);

	TaiContinuousMotionAction* continousMotion6 = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk11);

	TaiSerialAction* serial2      = new TaiSerialAction(NAPKIDSTATE_Unk19, 2);
	TaiCountLoopAction* countLoop = new TaiCountLoopAction(TAI_NO_TRANSIT, params->getI(NAPKIDPI_Unk0));
	serial2->setAction(0, countLoop);

	TaiFinishMotionAction* finishMotion3 = new TaiFinishMotionAction(TAI_NO_TRANSIT);
	serial2->setAction(1, finishMotion3);

	// STATE 18 - (Unknown)
	TaiState* state18 = new TaiState(4);
	j                 = 0;
	state18->setAction(j++, dead2);
	state18->setAction(j++, simDamage);
	state18->setAction(j++, serial2);
	state18->setAction(j++, continousMotion6);
	setState(NAPKIDSTATE_Unk18, state18);

	TaiNapkidStartDroppingWaterAction* startDroppingWater = new TaiNapkidStartDroppingWaterAction;
	TaiNapkidTakingOffAscendingAction* takingOffAscend    = new TaiNapkidTakingOffAscendingAction;
	TaiClampMaxHeightAction* clampMaxHeight3              = new TaiClampMaxHeightAction(NAPKIDSTATE_Unk20, params->getF(NAPKIDPF_Unk2));
	TaiContinuousMotionAction* continousMotion7           = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk12);
	TaiClampMinVelocityYAction* clampMinYVel              = new TaiClampMinVelocityYAction(NAPKIDSTATE_Unk20, 0.0f);

	// STATE 19 - (Unknown)
	TaiState* state19 = new TaiState(9);
	j                 = 0;
	state19->setAction(j++, startFlying);
	state19->setAction(j++, simDamage);
	state19->setAction(j++, takingOffAscend);
	state19->setAction(j++, acceleration);
	state19->setAction(j++, clampMinYVel);
	state19->setAction(j++, clampMaxHeight3);
	state19->setAction(j++, makingNextVel);
	state19->setAction(j++, continousMotion7);
	state19->setAction(j++, startDroppingWater);
	setState(NAPKIDSTATE_Unk19, state19);

	TaiNotAction* notStickersOnBody   = new TaiNotAction(NAPKIDSTATE_Unk22, new TaiHasStickersOnBodyAction(TAI_NO_TRANSIT));
	TaiNapkidFlickAction* napkidFlick = new TaiNapkidFlickAction(NAPKIDSTATE_Unk21);
	TaiOnceAction* once2              = new TaiOnceAction(NAPKIDSTATE_Unk16);
	TaiStopGenParticleGeneratorAction* stopParticleGen = new TaiStopGenParticleGeneratorAction(0);

	// STATE 20 - (Unknown)
	TaiState* state20 = new TaiState(4);
	j                 = 0;
	state20->setAction(j++, stopParticleGen);
	state20->setAction(j++, notStickersOnBody);
	state20->setAction(j++, napkidFlick);
	state20->setAction(j++, once2);
	setState(NAPKIDSTATE_Unk20, state20);

	TaiFlickingUpperAction* flickUpper = new TaiFlickingUpperAction(NAPKIDSTATE_Unk22, NAPKIDANIM_Unk9);

	// STATE 21 - Flick?
	TaiState* state21 = new TaiState(2);
	j                 = 0;
	state21->setAction(j++, simDamage);
	state21->setAction(j++, flickUpper);
	setState(NAPKIDSTATE_Unk21, state21);

	TaiNapkidRisingAscendingAction* napkidRisingAscending = new TaiNapkidRisingAscendingAction;
	TaiClampMaxHeightAction* clampMaxHeight4              = new TaiClampMaxHeightAction(NAPKIDSTATE_Unk1, params->getF(TPF_FlightHeight));
	TaiContinuousMotionAction* continousMotion8           = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk6);

	TaiState* state22 = new TaiState(8);
	j                 = 0;
	state22->setAction(j++, simDamage);
	state22->setAction(j++, stickersOnBody1);
	state22->setAction(j++, dead1);
	state22->setAction(j++, napkidRisingAscending);
	state22->setAction(j++, acceleration);
	state22->setAction(j++, clampMaxHeight4);
	state22->setAction(j++, makingNextVel);
	state22->setAction(j++, continousMotion8);
	setState(NAPKIDSTATE_Unk22, state22);
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x3C8(r1)
	  stmw      r14, 0x380(r1)
	  addi      r22, r4, 0
	  addi      r25, r3, 0
	  li        r4, 0x17
	  bl        -0xEE44
	  lis       r3, 0x802D
	  subi      r0, r3, 0x5770
	  stw       r0, 0x0(r25)
	  li        r3, 0x8
	  bl        -0xEF238
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x64
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r14)
	  subi      r0, r3, 0x6140
	  stw       r0, 0x4(r14)

	.loc_0x64:
	  li        r3, 0x8
	  bl        -0xEF26C
	  stw       r3, 0x378(r1)
	  lwz       r0, 0x378(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xA8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x378(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x378(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x617C
	  lwz       r3, 0x378(r1)
	  stw       r0, 0x4(r3)

	.loc_0xA8:
	  li        r3, 0x8
	  bl        -0xEF2B0
	  stw       r3, 0x374(r1)
	  lwz       r0, 0x374(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xEC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x374(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x374(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x61BC
	  lwz       r3, 0x374(r1)
	  stw       r0, 0x4(r3)

	.loc_0xEC:
	  li        r3, 0x8
	  bl        -0xEF2F4
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x120
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x6318
	  stw       r0, 0x4(r16)

	.loc_0x120:
	  li        r3, 0x8
	  bl        -0xEF328
	  stw       r3, 0x370(r1)
	  lwz       r0, 0x370(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x164
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x370(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x370(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6358
	  lwz       r3, 0x370(r1)
	  stw       r0, 0x4(r3)

	.loc_0x164:
	  li        r3, 0x8
	  bl        -0xEF36C
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0x198
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r18)
	  subi      r0, r3, 0x6394
	  stw       r0, 0x4(r18)

	.loc_0x198:
	  li        r3, 0x8
	  bl        -0xEF3A0
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x1CC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r19)
	  subi      r0, r3, 0x6290
	  stw       r0, 0x4(r19)

	.loc_0x1CC:
	  li        r3, 0x8
	  bl        -0xEF3D4
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x200
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r17)
	  subi      r0, r3, 0x61FC
	  stw       r0, 0x4(r17)

	.loc_0x200:
	  li        r3, 0x8
	  bl        -0xEF408
	  cmplwi    r3, 0
	  beq-      .loc_0x230
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lis       r4, 0x802D
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6244
	  stw       r0, 0x4(r3)

	.loc_0x230:
	  li        r3, 0x8
	  bl        -0xEF438
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x264
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, 0xF
	  lis       r3, 0x802D
	  stw       r0, 0x0(r21)
	  subi      r0, r3, 0x7CA0
	  stw       r0, 0x4(r21)

	.loc_0x264:
	  li        r3, 0x8
	  bl        -0xEF46C
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x298
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, 0xF
	  lis       r3, 0x802D
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0x42D8
	  stw       r0, 0x4(r20)

	.loc_0x298:
	  li        r3, 0x8
	  bl        -0xEF4A0
	  stw       r3, 0x36C(r1)
	  lwz       r0, 0x36C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2DC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x36C(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lwz       r3, 0x36C(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x42D8
	  lwz       r3, 0x36C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2DC:
	  li        r3, 0x8
	  bl        -0xEF4E4
	  cmplwi    r3, 0
	  beq-      .loc_0x30C
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r3)
	  li        r0, 0x15
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x677C
	  stw       r0, 0x4(r3)

	.loc_0x30C:
	  li        r3, 0x8
	  bl        -0xEF514
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x340
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0x4
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x591C
	  stw       r0, 0x4(r26)

	.loc_0x340:
	  li        r3, 0x8
	  bl        -0xEF548
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x374
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x45B8
	  stw       r0, 0x4(r24)

	.loc_0x374:
	  li        r3, 0xC
	  bl        -0xEF57C
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x3BC
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, -0x1
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x5A6C
	  lfs       f0, 0x74(r5)
	  stw       r4, 0x4(r23)
	  stw       r0, 0x0(r23)
	  stw       r3, 0x4(r23)
	  stfs      f0, 0x8(r23)

	.loc_0x3BC:
	  li        r3, 0xC
	  bl        -0xEF5C4
	  addi      r15, r3, 0
	  mr.       r0, r15
	  beq-      .loc_0x404
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, -0x1
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x5A6C
	  lfs       f0, 0xCC(r5)
	  stw       r4, 0x4(r15)
	  stw       r0, 0x0(r15)
	  stw       r3, 0x4(r15)
	  stfs      f0, 0x8(r15)

	.loc_0x404:
	  li        r3, 0xC
	  bl        -0xEF60C
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x44C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r0, 0
	  subi      r3, r3, 0x447C
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x44C:
	  li        r3, 0x8
	  bl        -0xEF654
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x480
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x43C0
	  stw       r0, 0x4(r30)

	.loc_0x480:
	  li        r3, 0xC
	  bl        -0xEF688
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x49C
	  li        r4, 0x3
	  bl        -0xF608

	.loc_0x49C:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r14, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r4
	  li        r3, 0x10
	  lwz       r4, 0x8(r28)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r28, 0x0(r4)
	  bl        -0xEF6DC
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x53C
	  lwz       r3, 0x84(r22)
	  lis       r7, 0x802C
	  lis       r6, 0x802D
	  lwz       r3, 0x4(r3)
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lwz       r3, 0x0(r3)
	  addi      r7, r7, 0x6620
	  li        r0, -0x1
	  lfs       f0, 0xC(r3)
	  subi      r6, r6, 0x6A6C
	  li        r3, 0x6
	  stw       r7, 0x4(r29)
	  subi      r5, r5, 0x6A8C
	  subi      r4, r4, 0x5878
	  stw       r0, 0x0(r29)
	  stw       r6, 0x4(r29)
	  stw       r3, 0x8(r29)
	  stw       r5, 0x4(r29)
	  stw       r4, 0x4(r29)
	  stfs      f0, 0xC(r29)

	.loc_0x53C:
	  li        r3, 0x18
	  bl        -0xEF744
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x5A8
	  lwz       r4, 0x84(r22)
	  lis       r3, 0x802C
	  lis       r6, 0x802D
	  lwz       r4, 0x4(r4)
	  lis       r5, 0x802D
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x0(r4)
	  li        r0, 0x2
	  subi      r7, r6, 0x35D8
	  lfs       f1, 0xD8(r4)
	  li        r6, 0
	  lfs       f0, 0xD4(r4)
	  subi      r4, r5, 0x3670
	  stw       r3, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r7, 0x4(r30)
	  stw       r6, 0x8(r30)
	  stfs      f0, 0xC(r30)
	  lfs       f0, -0x5B34(r2)
	  stfs      f0, 0x10(r30)
	  stw       r4, 0x4(r30)
	  stfs      f1, 0x14(r30)

	.loc_0x5A8:
	  li        r3, 0xC
	  bl        -0xEF7B0
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x5E4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x69F0
	  stw       r0, 0x4(r28)
	  lfs       f0, -0x5B58(r2)
	  stfs      f0, 0x8(r28)

	.loc_0x5E4:
	  li        r3, 0xC
	  bl        -0xEF7EC
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x600
	  li        r4, 0x9
	  bl        -0xF76C

	.loc_0x600:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x378(r1)
	  li        r7, 0x4
	  stwx      r0, r3, r4
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2
	  li        r4, 0x3
	  stwx      r24, r3, r5
	  li        r5, 0x5
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r8,r7,2,0,29
	  stwx      r21, r3, r0
	  li        r6, 0x6
	  li        r0, 0x7
	  lwz       r3, 0x8(r31)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r7,r6,2,0,29
	  stwx      r20, r3, r4
	  li        r9, 0x8
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r6,r9,2,0,29
	  stwx      r26, r3, r8
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stwx      r23, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x4(r4)
	  bl        -0xEF8A4
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x6E4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r28)
	  li        r0, 0x6
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r28)
	  stw       r3, 0x4(r28)

	.loc_0x6E4:
	  li        r3, 0x18
	  bl        -0xEF8EC
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x750
	  lwz       r4, 0x84(r22)
	  lis       r3, 0x802C
	  lis       r6, 0x802D
	  lwz       r4, 0x4(r4)
	  lis       r5, 0x802D
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x0(r4)
	  li        r0, 0x1
	  subi      r7, r6, 0x35D8
	  lfs       f1, 0xE0(r4)
	  li        r6, 0
	  lfs       f0, 0xDC(r4)
	  subi      r4, r5, 0x3670
	  stw       r3, 0x4(r29)
	  stw       r0, 0x0(r29)
	  stw       r7, 0x4(r29)
	  stw       r6, 0x8(r29)
	  stfs      f0, 0xC(r29)
	  lfs       f0, -0x5B34(r2)
	  stfs      f0, 0x10(r29)
	  stw       r4, 0x4(r29)
	  stfs      f1, 0x14(r29)

	.loc_0x750:
	  li        r3, 0x18
	  bl        -0xEF958
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x7BC
	  lwz       r4, 0x84(r22)
	  lis       r3, 0x802C
	  lis       r5, 0x802D
	  lwz       r4, 0x4(r4)
	  lis       r7, 0x802D
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x0(r4)
	  li        r0, 0x3
	  subi      r6, r5, 0x35D8
	  lfs       f1, 0xE8(r4)
	  li        r5, 0x1
	  lfs       f0, 0xE4(r4)
	  subi      r4, r7, 0x3670
	  stw       r3, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r5, 0x8(r30)
	  stfs      f0, 0xC(r30)
	  lfs       f0, -0x5B34(r2)
	  stfs      f0, 0x10(r30)
	  stw       r4, 0x4(r30)
	  stfs      f1, 0x14(r30)

	.loc_0x7BC:
	  li        r3, 0xC
	  bl        -0xEF9C4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x7D8
	  li        r4, 0x9
	  bl        -0xF944

	.loc_0x7D8:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r14, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r5,r4,2,0,29
	  li        r4, 0x3
	  stwx      r24, r3, r5
	  li        r7, 0x4
	  li        r5, 0x5
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x6
	  stwx      r21, r3, r0
	  li        r0, 0x7
	  li        r9, 0x8
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r8,r7,2,0,29
	  stwx      r20, r3, r4
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r7,r6,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r6,r9,2,0,29
	  stwx      r26, r3, r8
	  li        r3, 0x18
	  lwz       r4, 0x8(r31)
	  stwx      r23, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x8(r4)
	  bl        -0xEFA78
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x8DC
	  lwz       r4, 0x84(r22)
	  lis       r3, 0x802C
	  lis       r6, 0x802D
	  lwz       r4, 0x4(r4)
	  lis       r5, 0x802D
	  addi      r3, r3, 0x6620
	  lwz       r4, 0x0(r4)
	  li        r0, 0x1
	  subi      r7, r6, 0x35D8
	  lfs       f1, 0xF0(r4)
	  li        r6, 0
	  lfs       f0, 0xEC(r4)
	  subi      r4, r5, 0x3670
	  stw       r3, 0x4(r31)
	  stw       r0, 0x0(r31)
	  stw       r7, 0x4(r31)
	  stw       r6, 0x8(r31)
	  stfs      f0, 0xC(r31)
	  lfs       f0, -0x5B34(r2)
	  stfs      f0, 0x10(r31)
	  stw       r4, 0x4(r31)
	  stfs      f1, 0x14(r31)

	.loc_0x8DC:
	  li        r3, 0xC
	  bl        -0xEFAE4
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x924
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x2
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x924:
	  li        r3, 0xC
	  bl        -0xEFB2C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x940
	  li        r4, 0x7
	  bl        -0xFAAC

	.loc_0x940:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r3, 0x2
	  lwz       r4, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r21, r4, r0
	  li        r0, 0x4
	  li        r4, 0x5
	  lwz       r5, 0x8(r29)
	  rlwinm    r3,r3,2,0,29
	  li        r7, 0x6
	  stwx      r20, r5, r3
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r5,r0,2,0,29
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r7,2,0,29
	  stwx      r26, r3, r6
	  li        r3, 0x8
	  lwz       r6, 0x8(r29)
	  stwx      r23, r6, r5
	  lwz       r5, 0x8(r29)
	  stwx      r31, r5, r4
	  lwz       r4, 0x8(r29)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r29, 0xC(r4)
	  bl        -0xEFBC0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x9EC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x591C
	  stw       r0, 0x4(r30)

	.loc_0x9EC:
	  li        r3, 0x8
	  bl        -0xEFBF4
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0xA20
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0x7
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x5AF0
	  stw       r0, 0x4(r26)

	.loc_0xA20:
	  li        r3, 0x8
	  bl        -0xEFC28
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xA54
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5960
	  stw       r0, 0x4(r27)

	.loc_0xA54:
	  li        r3, 0x8
	  bl        -0xEFC5C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xA88
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x5
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x59A0
	  stw       r0, 0x4(r28)

	.loc_0xA88:
	  li        r3, 0x10
	  bl        -0xEFC90
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xAF0
	  lwz       r4, 0x84(r22)
	  lis       r5, 0x802C
	  lis       r3, 0x802D
	  lwz       r4, 0x4(r4)
	  lis       r7, 0x802D
	  lis       r8, 0x802D
	  lwz       r4, 0x0(r4)
	  addi      r0, r5, 0x6620
	  li        r6, -0x1
	  lfs       f0, 0x10(r4)
	  subi      r5, r3, 0x6A6C
	  li        r4, 0x6
	  stw       r0, 0x4(r29)
	  subi      r3, r7, 0x6A8C
	  subi      r0, r8, 0x6574
	  stw       r6, 0x0(r29)
	  stw       r5, 0x4(r29)
	  stw       r4, 0x8(r29)
	  stw       r3, 0x4(r29)
	  stw       r0, 0x4(r29)
	  stfs      f0, 0xC(r29)

	.loc_0xAF0:
	  li        r3, 0xC
	  bl        -0xEFCF8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xB0C
	  li        r4, 0x9
	  bl        -0xFC78

	.loc_0xB0C:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r8, 0x3
	  stwx      r21, r3, r4
	  li        r7, 0x4
	  li        r6, 0x5
	  lwz       r4, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x6
	  stwx      r20, r4, r0
	  li        r4, 0x7
	  li        r9, 0x8
	  lwz       r5, 0x8(r31)
	  rlwinm    r0,r8,2,0,29
	  rlwinm    r8,r7,2,0,29
	  stwx      r26, r5, r0
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r7,r3,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r9,2,0,29
	  stwx      r30, r3, r8
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r23, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x10(r4)
	  bl        -0xEFDAC
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xBE0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x6
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x59E4
	  stw       r0, 0x4(r28)
	  lfs       f0, -0x5B28(r2)
	  stfs      f0, 0x8(r28)

	.loc_0xBE0:
	  li        r3, 0x14
	  bl        -0xEFDE8
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xC2C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x6
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r3, r3, 0x35D8
	  li        r0, 0
	  stw       r3, 0x4(r29)
	  stw       r0, 0x8(r29)
	  lfs       f0, -0x5B24(r2)
	  stfs      f0, 0xC(r29)
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0x10(r29)

	.loc_0xC2C:
	  li        r3, 0xC
	  bl        -0xEFE34
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xC74
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x6
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0xC74:
	  li        r3, 0xC
	  bl        -0xEFE7C
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xC90
	  li        r4, 0x8
	  bl        -0xFDFC

	.loc_0xC90:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r5, 0x3
	  stwx      r21, r3, r4
	  li        r4, 0x4
	  li        r7, 0x5
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x6
	  stwx      r20, r3, r0
	  li        r0, 0x7
	  rlwinm    r5,r5,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r7,r7,2,0,29
	  stwx      r26, r3, r5
	  rlwinm    r5,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r6, 0x8(r31)
	  li        r3, 0x8
	  stwx      r23, r6, r4
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x14(r4)
	  bl        -0xEFF20
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xD4C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x5A2C
	  stw       r0, 0x4(r28)

	.loc_0xD4C:
	  li        r3, 0xC
	  bl        -0xEFF54
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xD88
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x62D4
	  stw       r0, 0x4(r30)
	  lfs       f0, -0x5B20(r2)
	  stfs      f0, 0x8(r30)

	.loc_0xD88:
	  li        r3, 0xC
	  bl        -0xEFF90
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xDA4
	  li        r4, 0x6
	  bl        -0xFF10

	.loc_0xDA4:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r6, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r0,2,0,29
	  li        r0, 0x3
	  stwx      r21, r3, r4
	  li        r4, 0x4
	  li        r5, 0x5
	  lwz       r3, 0x8(r29)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r6
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r6,r5,2,0,29
	  lwz       r5, 0x8(r29)
	  li        r3, 0xC
	  stwx      r18, r5, r0
	  lwz       r5, 0x8(r29)
	  stwx      r30, r5, r4
	  lwz       r4, 0x8(r29)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x18(r4)
	  bl        -0xF0014
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xE54
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0x8
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0
	  subi      r3, r3, 0x6AD8
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0xE54:
	  li        r3, 0xC
	  bl        -0xF005C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xE70
	  li        r4, 0x5
	  bl        -0xFFDC

	.loc_0xE70:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r21, r3, r0
	  li        r0, 0x4
	  rlwinm    r4,r4,2,0,29
	  lwz       r3, 0x8(r29)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r4
	  li        r3, 0x8
	  lwz       r4, 0x8(r29)
	  stwx      r23, r4, r5
	  lwz       r4, 0x8(r29)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x1C(r4)
	  bl        -0xF00D0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xEFC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x5C84
	  stw       r0, 0x4(r30)

	.loc_0xEFC:
	  li        r3, 0x8
	  bl        -0xF0104
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xF30
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0xA
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5B34
	  stw       r0, 0x4(r27)

	.loc_0xF30:
	  li        r3, 0xC
	  bl        -0xF0138
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xF6C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0x8
	  stw       r3, 0x4(r28)
	  stw       r0, 0x8(r28)

	.loc_0xF6C:
	  li        r3, 0x8
	  bl        -0xF0174
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0xFA0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x5C3C
	  stw       r0, 0x4(r26)

	.loc_0xFA0:
	  li        r3, 0xC
	  bl        -0xF01A8
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xFDC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x9
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6454
	  stw       r0, 0x4(r29)
	  lfs       f0, -0x5B88(r2)
	  stfs      f0, 0x8(r29)

	.loc_0xFDC:
	  li        r3, 0xC
	  bl        -0xF01E4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xFF8
	  li        r4, 0x9
	  bl        -0x10164

	.loc_0xFF8:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r9, 0x3
	  stwx      r26, r3, r4
	  li        r7, 0x4
	  li        r3, 0x5
	  lwz       r5, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x6
	  stwx      r30, r5, r0
	  li        r5, 0x7
	  li        r8, 0x8
	  lwz       r6, 0x8(r31)
	  rlwinm    r0,r9,2,0,29
	  rlwinm    r9,r7,2,0,29
	  stwx      r16, r6, r0
	  rlwinm    r6,r3,2,0,29
	  rlwinm    r7,r4,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r5,2,0,29
	  rlwinm    r0,r8,2,0,29
	  stwx      r29, r3, r9
	  li        r3, 0x8
	  lwz       r5, 0x8(r31)
	  stwx      r19, r5, r6
	  lwz       r5, 0x8(r31)
	  stwx      r28, r5, r7
	  lwz       r5, 0x8(r31)
	  stwx      r27, r5, r4
	  lwz       r4, 0x8(r31)
	  stwx      r17, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x20(r4)
	  bl        -0xF0298
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x10C4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x5CC8
	  stw       r0, 0x4(r28)

	.loc_0x10C4:
	  li        r3, 0xC
	  bl        -0xF02CC
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1100
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6454
	  stw       r0, 0x4(r29)
	  lfs       f0, -0x5B88(r2)
	  stfs      f0, 0x8(r29)

	.loc_0x1100:
	  li        r3, 0xC
	  bl        -0xF0308
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x111C
	  li        r4, 0x8
	  bl        -0x10288

	.loc_0x111C:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r3, 0x1
	  li        r0, 0x2
	  lwz       r4, 0x8(r31)
	  rlwinm    r5,r3,2,0,29
	  li        r3, 0x3
	  stwx      r28, r4, r5
	  li        r5, 0x4
	  li        r8, 0x5
	  lwz       r4, 0x8(r31)
	  rlwinm    r6,r0,2,0,29
	  li        r0, 0x6
	  stwx      r30, r4, r6
	  li        r4, 0x7
	  rlwinm    r7,r3,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r5,r8,2,0,29
	  stwx      r16, r3, r7
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r7,r4,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r3, 0x8
	  stwx      r29, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r17, r4, r7
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x24(r4)
	  bl        -0xF03AC
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x11D8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0xB
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x7C5C
	  stw       r0, 0x4(r27)

	.loc_0x11D8:
	  li        r3, 0x8
	  bl        -0xF03E0
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x120C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0xC
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x6DDC
	  stw       r0, 0x4(r28)

	.loc_0x120C:
	  li        r3, 0xC
	  bl        -0xF0414
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1228
	  li        r4, 0x5
	  bl        -0x10394

	.loc_0x1228:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r16, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r29, r3, r0
	  li        r0, 0x4
	  rlwinm    r4,r4,2,0,29
	  lwz       r3, 0x8(r30)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r19, r3, r4
	  li        r3, 0x8
	  lwz       r4, 0x8(r30)
	  stwx      r27, r4, r5
	  lwz       r4, 0x8(r30)
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r30, 0x28(r4)
	  bl        -0xF0488
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x12B4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5D0C
	  stw       r0, 0x4(r27)

	.loc_0x12B4:
	  li        r3, 0xC
	  bl        -0xF04BC
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x12FC
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, 0x1
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x6414
	  lfs       f0, 0x74(r5)
	  stw       r4, 0x4(r28)
	  stw       r0, 0x0(r28)
	  stw       r3, 0x4(r28)
	  stfs      f0, 0x8(r28)

	.loc_0x12FC:
	  li        r3, 0x10
	  bl        -0xF0504
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x131C
	  li        r4, 0x13
	  li        r5, 0x2
	  bl        -0x1071C

	.loc_0x131C:
	  li        r3, 0xC
	  bl        -0xF0524
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0x1364
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r5)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r5)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r5)
	  li        r0, 0xD
	  subi      r3, r3, 0x6B9C
	  stw       r0, 0x8(r5)
	  stw       r3, 0x4(r5)

	.loc_0x1364:
	  lwz       r4, 0xC(r26)
	  li        r3, 0xC
	  stw       r5, 0x0(r4)
	  bl        -0xF0574
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0x13A8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r5)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r5)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0x6
	  stw       r3, 0x4(r5)
	  stw       r0, 0x8(r5)

	.loc_0x13A8:
	  lwz       r4, 0xC(r26)
	  li        r3, 0xC
	  stw       r5, 0x4(r4)
	  bl        -0xF05B8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x13CC
	  li        r4, 0x7
	  bl        -0x10538

	.loc_0x13CC:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r3, 0x2
	  lwz       r4, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r16, r4, r0
	  li        r0, 0x4
	  li        r7, 0x5
	  lwz       r4, 0x8(r30)
	  rlwinm    r3,r3,2,0,29
	  li        r6, 0x6
	  stwx      r29, r4, r3
	  rlwinm    r4,r5,2,0,29
	  rlwinm    r5,r0,2,0,29
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r7,2,0,29
	  rlwinm    r6,r6,2,0,29
	  stwx      r19, r3, r4
	  li        r3, 0x8
	  lwz       r4, 0x8(r30)
	  stwx      r26, r4, r5
	  lwz       r4, 0x8(r30)
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r30)
	  stwx      r28, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r30, 0x30(r4)
	  bl        -0xF064C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1478
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5D0C
	  stw       r0, 0x4(r27)

	.loc_0x1478:
	  li        r3, 0xC
	  bl        -0xF0680
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x14C0
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, 0xD
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x6414
	  lfs       f0, 0xCC(r5)
	  stw       r4, 0x4(r28)
	  stw       r0, 0x0(r28)
	  stw       r3, 0x4(r28)
	  stfs      f0, 0x8(r28)

	.loc_0x14C0:
	  li        r3, 0xC
	  bl        -0xF06C8
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x1508
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r31)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r31)
	  li        r0, 0x5
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r31)
	  stw       r3, 0x4(r31)

	.loc_0x1508:
	  li        r3, 0xC
	  bl        -0xF0710
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1524
	  li        r4, 0x7
	  bl        -0x10690

	.loc_0x1524:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r3, 0x1
	  li        r0, 0x2
	  lwz       r4, 0x8(r30)
	  rlwinm    r5,r3,2,0,29
	  li        r3, 0x3
	  stwx      r31, r4, r5
	  li        r4, 0x4
	  li        r5, 0x5
	  lwz       r7, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x6
	  stwx      r27, r7, r0
	  rlwinm    r3,r3,2,0,29
	  rlwinm    r0,r4,2,0,29
	  lwz       r4, 0x8(r30)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r6,r6,2,0,29
	  stwx      r16, r4, r3
	  li        r3, 0x10
	  lwz       r4, 0x8(r30)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r30)
	  stwx      r28, r4, r5
	  lwz       r4, 0x8(r30)
	  stwx      r19, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r30, 0x2C(r4)
	  bl        -0xF07A4
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1604
	  lwz       r3, 0x84(r22)
	  lis       r7, 0x802C
	  lis       r6, 0x802D
	  lwz       r3, 0x4(r3)
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lwz       r3, 0x0(r3)
	  addi      r7, r7, 0x6620
	  li        r0, -0x1
	  lfs       f0, 0xC8(r3)
	  subi      r6, r6, 0x6A6C
	  li        r3, 0x5
	  stw       r7, 0x4(r30)
	  subi      r5, r5, 0x6A8C
	  subi      r4, r4, 0x5878
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r3, 0x8(r30)
	  stw       r5, 0x4(r30)
	  stw       r4, 0x4(r30)
	  stfs      f0, 0xC(r30)

	.loc_0x1604:
	  li        r3, 0x14
	  bl        -0xF080C
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x165C
	  lwz       r4, 0x84(r22)
	  lis       r3, 0x802C
	  lis       r5, 0x802D
	  lwz       r4, 0x4(r4)
	  addi      r3, r3, 0x6620
	  li        r0, 0xE
	  lwz       r4, 0x0(r4)
	  subi      r6, r5, 0x35D8
	  li        r5, 0
	  lfs       f0, 0xF4(r4)
	  stw       r3, 0x4(r31)
	  stw       r0, 0x0(r31)
	  stw       r6, 0x4(r31)
	  stw       r5, 0x8(r31)
	  stfs      f0, 0xC(r31)
	  lfs       f0, -0x5B34(r2)
	  stfs      f0, 0x10(r31)

	.loc_0x165C:
	  li        r3, 0xC
	  bl        -0xF0864
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1678
	  li        r4, 0x6
	  bl        -0x107E4

	.loc_0x1678:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  li        r6, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r0,2,0,29
	  li        r0, 0x3
	  stwx      r21, r3, r4
	  li        r4, 0x4
	  li        r5, 0x5
	  lwz       r3, 0x8(r29)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r6
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r6,r5,2,0,29
	  lwz       r5, 0x8(r29)
	  li        r3, 0xC
	  stwx      r31, r5, r0
	  lwz       r5, 0x8(r29)
	  stwx      r30, r5, r4
	  lwz       r4, 0x8(r29)
	  stwx      r15, r4, r6
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x34(r4)
	  bl        -0xF08E8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1728
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0xD
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x4
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x1728:
	  li        r3, 0x8
	  bl        -0xF0930
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x175C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5DE8
	  stw       r0, 0x4(r27)

	.loc_0x175C:
	  li        r3, 0x8
	  bl        -0xF0964
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1790
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x7C5C
	  stw       r0, 0x4(r29)

	.loc_0x1790:
	  li        r3, 0xC
	  bl        -0xF0998
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x17C8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x7590
	  stw       r0, 0x4(r28)
	  stw       r29, 0x8(r28)

	.loc_0x17C8:
	  li        r3, 0xC
	  bl        -0xF09D0
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x17E4
	  li        r4, 0x5
	  bl        -0x10950

	.loc_0x17E4:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r21, r3, r0
	  li        r0, 0x1
	  li        r5, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x3
	  stwx      r20, r3, r0
	  li        r0, 0x4
	  rlwinm    r5,r5,2,0,29
	  lwz       r3, 0x8(r29)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r5
	  li        r3, 0xC
	  lwz       r5, 0x8(r29)
	  stwx      r27, r5, r4
	  lwz       r4, 0x8(r29)
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x38(r4)
	  bl        -0xF0A44
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1878
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0xA
	  stw       r3, 0x4(r30)
	  stw       r0, 0x8(r30)

	.loc_0x1878:
	  li        r3, 0x8
	  bl        -0xF0A80
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x18AC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5E6C
	  stw       r0, 0x4(r27)

	.loc_0x18AC:
	  li        r3, 0x8
	  bl        -0xF0AB4
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x18E0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x5EAC
	  stw       r0, 0x4(r26)

	.loc_0x18E0:
	  li        r3, 0xC
	  bl        -0xF0AE8
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1924
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6828
	  stw       r0, 0x4(r28)
	  lfs       f1, -0x5B1C(r2)
	  lfs       f0, -0x1CA4(r13)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8(r28)

	.loc_0x1924:
	  li        r3, 0xC
	  bl        -0xF0B2C
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1960
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x11
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6454
	  stw       r0, 0x4(r29)
	  lfs       f0, -0x5B88(r2)
	  stfs      f0, 0x8(r29)

	.loc_0x1960:
	  li        r3, 0xC
	  bl        -0xF0B68
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x197C
	  li        r4, 0x8
	  bl        -0x10AE8

	.loc_0x197C:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r7, 0x4
	  stwx      r26, r3, r4
	  li        r3, 0x5
	  rlwinm    r8,r3,2,0,29
	  lwz       r5, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r30, r5, r0
	  rlwinm    r0,r6,2,0,29
	  li        r5, 0x7
	  lwz       r6, 0x8(r31)
	  li        r4, 0x6
	  rlwinm    r7,r7,2,0,29
	  stwx      r27, r6, r0
	  rlwinm    r0,r4,2,0,29
	  lwz       r6, 0x370(r1)
	  rlwinm    r5,r5,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r3, 0xC
	  stwx      r28, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r6, r4, r8
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r5
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x3C(r4)
	  bl        -0xF0C10
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1A4C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6828
	  stw       r0, 0x4(r28)
	  lfs       f1, -0x5B2C(r2)
	  lfs       f0, -0x1CA4(r13)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8(r28)

	.loc_0x1A4C:
	  li        r3, 0xC
	  bl        -0xF0C54
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x1A68
	  li        r4, 0x8
	  bl        -0x10BD4

	.loc_0x1A68:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r3, 0x1
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r0, 0x2
	  rlwinm    r6,r0,2,0,29
	  stwx      r30, r4, r5
	  li        r3, 0x3
	  li        r0, 0x6
	  lwz       r4, 0x8(r31)
	  rlwinm    r7,r3,2,0,29
	  li        r5, 0x4
	  stwx      r27, r4, r6
	  li        r8, 0x5
	  rlwinm    r6,r5,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r4, 0x7
	  rlwinm    r5,r8,2,0,29
	  stwx      r28, r3, r7
	  rlwinm    r8,r4,2,0,29
	  lwz       r7, 0x370(r1)
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r3, 0xC
	  stwx      r7, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r8
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x40(r4)
	  bl        -0xF0CFC
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1B3C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0x12
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0
	  subi      r3, r3, 0x6AD8
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x1B3C:
	  li        r3, 0x8
	  bl        -0xF0D44
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1B70
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x5EF0
	  stw       r0, 0x4(r28)

	.loc_0x1B70:
	  li        r3, 0xC
	  bl        -0xF0D78
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x1B8C
	  li        r4, 0x5
	  bl        -0x10CF8

	.loc_0x1B8C:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x374(r1)
	  stwx      r14, r3, r0
	  li        r0, 0x1
	  rlwinm    r6,r0,2,0,29
	  lwz       r3, 0x8(r29)
	  li        r5, 0x2
	  li        r0, 0x3
	  stwx      r4, r3, r6
	  li        r4, 0x4
	  rlwinm    r5,r5,2,0,29
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r24, r3, r5
	  li        r3, 0xC
	  lwz       r5, 0x8(r29)
	  stwx      r30, r5, r0
	  lwz       r5, 0x8(r29)
	  stwx      r28, r5, r4
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x44(r4)
	  bl        -0xF0DF0
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1C30
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r0, 0xB
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x1C30:
	  li        r3, 0x10
	  bl        -0xF0E38
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x1C50
	  li        r4, 0x13
	  li        r5, 0x2
	  bl        -0x11050

	.loc_0x1C50:
	  li        r3, 0xC
	  bl        -0xF0E58
	  addi      r4, r3, 0
	  mr.       r0, r4
	  beq-      .loc_0x1C98
	  lwz       r6, 0x84(r22)
	  lis       r5, 0x802C
	  lis       r3, 0x802D
	  lwz       r6, 0x0(r6)
	  addi      r5, r5, 0x6620
	  li        r0, -0x1
	  lwz       r6, 0x0(r6)
	  subi      r3, r3, 0x6B60
	  lwz       r6, 0x50(r6)
	  stw       r5, 0x4(r4)
	  stw       r0, 0x0(r4)
	  stw       r3, 0x4(r4)
	  stw       r6, 0x8(r4)

	.loc_0x1C98:
	  lwz       r5, 0xC(r26)
	  li        r3, 0xC
	  stw       r4, 0x0(r5)
	  bl        -0xF0EA8
	  addi      r5, r3, 0
	  mr.       r0, r5
	  beq-      .loc_0x1CE8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r5)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r5)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r5)
	  li        r0, 0
	  subi      r3, r3, 0x6AD8
	  stw       r0, 0x8(r5)
	  stw       r3, 0x4(r5)

	.loc_0x1CE8:
	  lwz       r4, 0xC(r26)
	  li        r3, 0xC
	  stw       r5, 0x4(r4)
	  bl        -0xF0EF8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1D0C
	  li        r4, 0x4
	  bl        -0x10E78

	.loc_0x1D0C:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x36C(r1)
	  li        r5, 0x2
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r30)
	  li        r3, 0x3
	  stwx      r24, r4, r0
	  rlwinm    r0,r5,2,0,29
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r30)
	  li        r3, 0x8
	  stwx      r26, r4, r0
	  lwz       r4, 0x8(r30)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r25)
	  stw       r30, 0x48(r4)
	  bl        -0xF0F60
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x1D8C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x5F3C
	  stw       r0, 0x4(r26)

	.loc_0x1D8C:
	  li        r3, 0x8
	  bl        -0xF0F94
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1DC0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5D54
	  stw       r0, 0x4(r27)

	.loc_0x1DC0:
	  li        r3, 0xC
	  bl        -0xF0FC8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1E08
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, 0x14
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x6414
	  lfs       f0, 0xD0(r5)
	  stw       r4, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r3, 0x4(r30)
	  stfs      f0, 0x8(r30)

	.loc_0x1E08:
	  li        r3, 0xC
	  bl        -0xF1010
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x1E50
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r0, 0xC
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x1E50:
	  li        r3, 0xC
	  bl        -0xF1058
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1E8C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x14
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x6494
	  stw       r0, 0x4(r28)
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0x8(r28)

	.loc_0x1E8C:
	  li        r3, 0xC
	  bl        -0xF1094
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x1EA8
	  li        r4, 0x9
	  bl        -0x11014

	.loc_0x1EA8:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  lwz       r4, 0x378(r1)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r4, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r7, 0x8
	  stwx      r24, r3, r4
	  li        r4, 0x4
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r6,r4,2,0,29
	  stwx      r27, r3, r0
	  li        r8, 0x6
	  li        r0, 0x7
	  lwz       r3, 0x8(r31)
	  li        r9, 0x5
	  rlwinm    r4,r8,2,0,29
	  stwx      r16, r3, r5
	  rlwinm    r5,r9,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r7,r7,2,0,29
	  stwx      r28, r3, r6
	  li        r3, 0x8
	  lwz       r6, 0x8(r31)
	  stwx      r30, r6, r5
	  lwz       r5, 0x8(r31)
	  stwx      r19, r5, r4
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r26, r4, r7
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x4C(r4)
	  bl        -0xF114C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x1F78
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x7CA0
	  stw       r0, 0x4(r28)

	.loc_0x1F78:
	  li        r3, 0xC
	  bl        -0xF1180
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x1FB0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r31)
	  li        r0, 0x16
	  lis       r3, 0x802D
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x7590
	  stw       r0, 0x4(r31)
	  stw       r28, 0x8(r31)

	.loc_0x1FB0:
	  li        r3, 0x8
	  bl        -0xF11B8
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x1FE4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x15
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x5E2C
	  stw       r0, 0x4(r27)

	.loc_0x1FE4:
	  li        r3, 0x8
	  bl        -0xF11EC
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x2018
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x10
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x6DDC
	  stw       r0, 0x4(r28)

	.loc_0x2018:
	  li        r3, 0xC
	  bl        -0xF1220
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x2054
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802C
	  stw       r0, 0x0(r30)
	  addi      r3, r3, 0x7F58
	  li        r0, 0
	  stw       r3, 0x4(r30)
	  stw       r0, 0x8(r30)

	.loc_0x2054:
	  li        r3, 0xC
	  bl        -0xF125C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x2070
	  li        r4, 0x4
	  bl        -0x111DC

	.loc_0x2070:
	  li        r0, 0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r31, r3, r0
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r5,2,0,29
	  lwz       r4, 0x8(r29)
	  li        r3, 0xC
	  stwx      r27, r4, r0
	  lwz       r4, 0x8(r29)
	  stwx      r28, r4, r5
	  lwz       r4, 0x8(r25)
	  stw       r29, 0x50(r4)
	  bl        -0xF12C0
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x2100
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, 0x16
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802C
	  stw       r0, 0x4(r29)
	  li        r4, 0x9
	  addi      r0, r3, 0x66C0
	  stw       r4, 0x8(r29)
	  stw       r0, 0x4(r29)

	.loc_0x2100:
	  li        r3, 0xC
	  bl        -0xF1308
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x211C
	  li        r4, 0x2
	  bl        -0x11288

	.loc_0x211C:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r3, 0x8
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r25)
	  stw       r28, 0x54(r4)
	  bl        -0xF134C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x2178
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x5DA0
	  stw       r0, 0x4(r28)

	.loc_0x2178:
	  li        r3, 0xC
	  bl        -0xF1380
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x21C0
	  lwz       r5, 0x84(r22)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r5, 0x4(r5)
	  addi      r4, r4, 0x6620
	  li        r0, 0x1
	  lwz       r5, 0x0(r5)
	  subi      r3, r3, 0x6414
	  lfs       f0, 0x74(r5)
	  stw       r4, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r3, 0x4(r30)
	  stfs      f0, 0x8(r30)

	.loc_0x21C0:
	  li        r3, 0xC
	  bl        -0xF13C8
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x2208
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r29)
	  li        r0, 0x6
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r29)
	  stw       r3, 0x4(r29)

	.loc_0x2208:
	  li        r3, 0xC
	  bl        -0xF1410
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x2224
	  li        r4, 0x8
	  bl        -0x11390

	.loc_0x2224:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r24, r3, r0
	  li        r3, 0x1
	  li        r0, 0x2
	  lwz       r4, 0x8(r31)
	  rlwinm    r5,r3,2,0,29
	  li        r3, 0x3
	  stwx      r21, r4, r5
	  li        r6, 0x4
	  li        r5, 0x5
	  lwz       r4, 0x8(r31)
	  rlwinm    r7,r0,2,0,29
	  li        r0, 0x6
	  stwx      r20, r4, r7
	  li        r4, 0x7
	  rlwinm    r7,r3,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r5,r5,2,0,29
	  stwx      r28, r3, r7
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r7,r4,2,0,29
	  lwz       r4, 0x8(r31)
	  mr        r3, r25
	  stwx      r16, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r19, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r29, r4, r7
	  lwz       r4, 0x8(r25)
	  stw       r31, 0x58(r4)
	  lwz       r0, 0x3CC(r1)
	  lmw       r14, 0x380(r1)
	  addi      r1, r1, 0x3C8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801384CC
 * Size:	000084
 */
void TaiNapkidStrategy::start(Teki& teki)
{
	teki.mParticleGenerators[0] = effectMgr->create(EffectMgr::EFF_Frog_Water2, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	teki.stopParticleGenerator(0);
	TaiStrategy::start(teki);
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  addi      r5, r1, 0x10
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  li        r4, 0x54
	  lfs       f0, -0x106C(r13)
	  lfs       f1, -0x1068(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x1064(r13)
	  stfs      f1, 0x14(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x18(r1)
	  bl        0x64624
	  lwz       r5, 0x3D8(r31)
	  li        r4, 0
	  stw       r3, 0x0(r5)
	  mr        r3, r31
	  bl        0x114F4
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x110A0
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138550
 * Size:	0000BC
 */
void TaiNapkidStrategy::draw(Teki& teki, Graphics& gfx)
{
	TekiStrategy::draw(teki, gfx);
	if (teki.mParticleGenerators[0] == nullptr) {
		return;
	}

	NVector3f direction;
	teki.outputDirectionVector(direction);
	teki.setParticleGeneratorDirection(0, direction);

	NVector3f position;
	teki.outputPosition(position);
	teki.setParticleGeneratorPosition(0, position);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  bl        0x14C58
	  lwz       r3, 0x3D8(r31)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xA0
	  addi      r3, r1, 0x2C
	  bl        -0x1B730
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xE35C4
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE374C
	  stfs      f1, 0x2C(r1)
	  mr        r3, r31
	  lfs       f0, -0x1070(r13)
	  addi      r5, r1, 0x2C
	  li        r4, 0
	  stfs      f0, 0x30(r1)
	  stfs      f31, 0x34(r1)
	  bl        0x114B4
	  addi      r3, r1, 0x20
	  bl        -0x1B770
	  lwz       r6, 0x94(r31)
	  mr        r3, r31
	  lwz       r0, 0x98(r31)
	  addi      r5, r1, 0x20
	  li        r4, 0
	  stw       r6, 0x20(r1)
	  stw       r0, 0x24(r1)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x28(r1)
	  bl        0x11454

	.loc_0xA0:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013860C
 * Size:	000250
 */
void TaiNapkidStrategy::drawDebugInfo(Teki& teki, Graphics& gfx)
{
	teki.drawRange(gfx, teki.getPosition(), teki.getParameterF(TPF_VisibleRange), Colour(0, 0, 255, 255));
	teki.drawRange(gfx, teki.getPosition(), 130.0f, Colour(30, 30, 30, 255));
	teki.drawRange(gfx, teki.getPosition(), teki.getAttackableRange(), Colour(255, 255, 0, 255));

	if (teki.mTekiAnimator->getCurrentMotionIndex() == NAPKIDANIM_Unk8) {
		f32 counter  = teki.mTekiAnimator->getCounter();
		f32 startKey = teki.mTekiAnimator->getKeyValueByKeyType(2);
		f32 endKey   = teki.mTekiAnimator->getKeyValueByKeyType(3);
		if (startKey <= counter && counter <= endKey) {
			NVector3f hitCenter;
			teki.outputHitCenter(hitCenter);
			teki.drawRange(gfx, hitCenter, teki.getAttackHitRange(), Colour(255, 0, 0, 255));
		}
	}

	teki.drawRange(gfx, teki.getPosition(), teki.getLowerRange(), Colour(255, 0, 255, 255));
}

/*
 * --INFO--
 * Address:	8013885C
 * Size:	0000BC
 */
bool TekiNapkidTargetPikiCondition::satisfy(Creature* target)
{
	if (target->mObjType != OBJTYPE_Piki) {
		return false;
	}

	if (target->isStickTo()) {
		return false;
	}

	if (!TekiVisibleCondition(mTeki).satisfy(target)) {
		return false;
	}

	if (static_cast<Piki*>(target)->getState() == PIKISTATE_FallMeck) {
		return false;
	}

	TekiVisibleCondition(nullptr);
	return true;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x24
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0x24:
	  lwz       r0, 0x184(r4)
	  addi      r31, r4, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0x3C:
	  lis       r5, 0x802B
	  lwz       r6, 0x4(r3)
	  subi      r0, r5, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x24(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x24(r1)
	  subi      r0, r3, 0x2AF4
	  stw       r0, 0x24(r1)
	  addi      r3, r1, 0x24
	  stw       r6, 0x28(r1)
	  lwz       r12, 0x24(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x8C
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0x8C:
	  mr        r3, r31
	  bl        -0x70398
	  cmpwi     r3, 0x1E
	  bne-      .loc_0xA4
	  li        r3, 0
	  b         .loc_0xA8

	.loc_0xA4:
	  li        r3, 0x1

	.loc_0xA8:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138918
 * Size:	0000A0
 */
bool TekiNapkidShortRangeCondition::satisfy(Creature* target)
{
	if (target->mObjType != OBJTYPE_Piki) {
		return false;
	}

	if (target->isStickTo()) {
		return false;
	}

	if (TekiDistanceCondition(mTeki, 130.0f).satisfy(target)) {
		return true;
	}

	u32 bad[6];
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x20:
	  lwz       r0, 0x184(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x34:
	  lis       r5, 0x802B
	  lwz       r6, 0x4(r3)
	  subi      r0, r5, 0xF68
	  lfs       f0, -0x5B18(r2)
	  lis       r3, 0x802C
	  stw       r0, 0x24(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x24(r1)
	  subi      r0, r3, 0x29D8
	  stw       r0, 0x24(r1)
	  addi      r3, r1, 0x24
	  stw       r6, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  lwz       r12, 0x24(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8C
	  li        r3, 0x1
	  b         .loc_0x90

	.loc_0x8C:
	  li        r3, 0

	.loc_0x90:
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801389B8
 * Size:	000054
 */
void TaiNapkidWanderingRouteAction::start(Teki& teki)
{
	TaiContinuousMotionAction::start(teki);
	teki.mCurrRouteWayPointID = teki.getNearestWayPoint()->mIndex;
	makeTargetPosition(teki);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x4964
	  mr        r3, r31
	  bl        0x1013C
	  lwz       r0, 0x10(r3)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  stw       r0, 0x354(r31)
	  bl        0xC8
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138A0C
 * Size:	0000AC
 */
bool TaiNapkidWanderingRouteAction::act(Teki& teki)
{
	TaiContinuousMotionAction::act(teki);
	if (!motionStarted(teki)) {
		return false;
	}

	WayPoint* currWaypoint = teki.getWayPoint(teki.mCurrRouteWayPointID);
	if (currWaypoint == nullptr) {
		makeTargetPosition(teki);
		return false;
	}

	if (teki.moveToward(currWaypoint->mPosition, _0C)) {
		makeTargetPosition(teki);
	}

	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x48BC
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x94

	.loc_0x48:
	  mr        r3, r31
	  lwz       r4, 0x354(r31)
	  bl        0x100F0
	  mr.       r4, r3
	  bne-      .loc_0x70
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0xAC
	  li        r3, 0
	  b         .loc_0x94

	.loc_0x70:
	  lfs       f1, 0xC(r30)
	  mr        r3, r31
	  bl        0xE96C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x90
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0xAC

	.loc_0x90:
	  li        r3, 0

	.loc_0x94:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0xAC:
	*/
}

/*
 * --INFO--
 * Address:	80138AB8
 * Size:	0000A8
 */
void TaiNapkidWanderingRouteAction::makeTargetPosition(Teki& teki)
{
	WayPoint* currWaypoint = teki.getWayPoint(teki.mCurrRouteWayPointID);
	if (currWaypoint == nullptr) {
		return;
	}

	int i           = 0;
	int randomIndex = NSystem::randomInt(currWaypoint->mLinkCount - 1);
	for (int j = 0; j < currWaypoint->mLinkCount; j++) {
		if (currWaypoint->mLinkIndices[j] > -1) {
			if (i == randomIndex) {
				teki.mCurrRouteWayPointID = currWaypoint->mLinkIndices[j];
				break;
			}
			i++;
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  mr        r3, r30
	  lwz       r4, 0x354(r4)
	  bl        0x10074
	  mr.       r31, r3
	  bne-      .loc_0x30
	  b         .loc_0x90

	.loc_0x30:
	  lwz       r3, 0x34(r31)
	  subi      r3, r3, 0x1
	  bl        -0x1A24C
	  lwz       r0, 0x34(r31)
	  addi      r4, r31, 0
	  li        r6, 0
	  cmpwi     r0, 0
	  mtctr     r0
	  li        r5, 0
	  ble-      .loc_0x90

	.loc_0x58:
	  lwz       r0, 0x14(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x84
	  cmpw      r6, r3
	  bne-      .loc_0x80
	  rlwinm    r0,r5,2,0,29
	  add       r3, r31, r0
	  lwz       r0, 0x14(r3)
	  stw       r0, 0x354(r30)
	  b         .loc_0x90

	.loc_0x80:
	  addi      r6, r6, 0x1

	.loc_0x84:
	  addi      r4, r4, 0x4
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0x58

	.loc_0x90:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138B60
 * Size:	0000B8
 */
bool TaiNapkidTargetPikiAction::act(Teki& teki)
{
	Creature* nearestPiki = pikiMgr->findClosest(teki.getPosition(), &TekiNapkidTargetPikiCondition(&teki));
	if (nearestPiki == nullptr) {
		return false;
	} else {
		teki.setCreaturePointer(0, nearestPiki);
		return true;
	}

	return false;

	TekiNapkidTargetPikiCondition(nullptr);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0xF68
	  lis       r5, 0x802C
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  addi      r4, r30, 0x94
	  stw       r0, 0x18(r1)
	  addi      r0, r5, 0x6964
	  lis       r5, 0x802D
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x18(r1)
	  subi      r0, r5, 0x57CC
	  stw       r0, 0x18(r1)
	  addi      r5, r1, 0x18
	  stw       r30, 0x1C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  bne-      .loc_0x6C
	  li        r3, 0
	  b         .loc_0xA0

	.loc_0x6C:
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x88
	  beq-      .loc_0x88
	  bl        -0x54870
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0x88:
	  stw       r31, 0x418(r30)
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x9C
	  bl        -0x5489C

	.loc_0x9C:
	  li        r3, 0x1

	.loc_0xA0:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138C18
 * Size:	0000A8
 */
bool TaiNapkidPikiLostAction::act(Teki& teki)
{

	Creature* targetCreature = teki.getCreaturePointer(0);
	if (targetCreature == nullptr) {
		return true;
	}

	if (!TekiNapkidTargetPikiCondition(&teki).satisfy(targetCreature)) {
		teki.clearCreaturePointer(0);
		return true;
	}

	return false;

	u32 badCompiler[8];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  lwz       r0, 0x418(r4)
	  cmplwi    r0, 0
	  mr        r4, r0
	  bne-      .loc_0x2C
	  li        r3, 0x1
	  b         .loc_0x94

	.loc_0x2C:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x2C(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x2C(r1)
	  subi      r0, r3, 0x57CC
	  stw       r0, 0x2C(r1)
	  addi      r3, r1, 0x2C
	  stw       r31, 0x30(r1)
	  lwz       r12, 0x2C(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x90
	  lwz       r3, 0x418(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x88
	  bl        -0x54928
	  li        r0, 0
	  stw       r0, 0x418(r31)

	.loc_0x88:
	  li        r3, 0x1
	  b         .loc_0x94

	.loc_0x90:
	  li        r3, 0

	.loc_0x94:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138CC0
 * Size:	000088
 */
bool TaiNapkidShortRangeAction::act(Teki& teki)
{
	Creature* targetCreature = teki.getCreaturePointer(0);
	if (targetCreature == nullptr) {
		return true;
	}

	if (TekiNapkidShortRangeCondition(&teki).satisfy(targetCreature)) {
		return true;
	}

	return false;

	u32 badCompiler[8];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  lwz       r0, 0x418(r4)
	  cmplwi    r0, 0
	  mr        r5, r0
	  bne-      .loc_0x24
	  li        r3, 0x1
	  b         .loc_0x78

	.loc_0x24:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x2C(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x2C(r1)
	  subi      r0, r3, 0x5824
	  stw       r0, 0x2C(r1)
	  addi      r3, r1, 0x2C
	  stw       r4, 0x30(r1)
	  mr        r4, r5
	  lwz       r12, 0x2C(r1)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  li        r3, 0x1
	  b         .loc_0x78

	.loc_0x74:
	  li        r3, 0

	.loc_0x78:
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138D48
 * Size:	0000A8
 */
void TaiNapkidStraightFlyingAction::start(Teki& teki)
{
	NVector3f directionVec;
	teki.outputDirectionVector(directionVec);
	directionVec.scale(150.0f);
	teki.inputDrive(directionVec);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  addi      r3, r1, 0x1C
	  stfd      f30, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  bl        -0x1BF14
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xE2DE0
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE2F68
	  stfs      f1, 0x1C(r1)
	  lfs       f0, -0x1070(r13)
	  stfs      f0, 0x20(r1)
	  stfs      f31, 0x24(r1)
	  lfs       f0, 0x1C(r1)
	  lfs       f1, -0x5B20(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x20(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x24(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x1C(r1)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x20(r1)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0x24(r1)
	  stfs      f0, 0xAC(r31)
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lfd       f30, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138DF0
 * Size:	000098
 */
bool TaiNapkidStraightFlyingAction::act(Teki& teki)
{
	Creature* targetCreature = teki.getCreaturePointer(0);
	if (targetCreature == nullptr) {
		return true;
	}

	NVector3f targetPosition(targetCreature->getPosition());
	if (targetPosition.distanceXZ(teki.getPosition()) >= _08) {
		return true;
	}

	u32 badCompiler[6];
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r4
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  lwz       r4, 0x418(r4)
	  cmplwi    r4, 0
	  bne-      .loc_0x30
	  li        r3, 0x1
	  b         .loc_0x80

	.loc_0x30:
	  addi      r4, r4, 0x94
	  addi      r3, r1, 0x34
	  bl        -0x1BFA8
	  lfs       f3, 0x3C(r1)
	  lfs       f2, 0x9C(r31)
	  lfs       f1, 0x34(r1)
	  lfs       f0, 0x94(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x12B210
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x7C
	  li        r3, 0x1
	  b         .loc_0x80

	.loc_0x7C:
	  li        r3, 0

	.loc_0x80:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80138E88
 * Size:	00029C
 */
void TaiNapkidCirclingAction::start(Teki& teki)
{
	Creature* targetCreature = teki.getCreaturePointer(0);
	if (targetCreature == nullptr) {
		return;
	}

	// im probably not gonna try to properly annotate this math rn
	NVector3f sep;
	sep.sub2(targetCreature->getPosition(), teki.getPosition());
	sep.y = 0;
	sep.normalizeCheck();

	NVector3f directionVec;
	teki.outputDirectionVector(directionVec);

	NVector3f cross;
	NVector3f up(0.0f, 1.0f, 0.0f);
	cross.cross(up, directionVec);
	cross.normalizeCheck();

	f32 dotprod   = cross.dot(sep);
	f32 scaledPi  = NMathF::pi * 50.0f / 150.0f;
	f32 piDivisor = NMathF::pi / scaledPi;

	NVector3f normalized(cross);
	normalized.scale(50.0f);
	if (dotprod < 0.0f) {
		normalized.negate();
		piDivisor = -piDivisor;
	}

	NVector3f targetVelocity;
	targetVelocity.add2(teki.getPosition(), normalized);
	teki.mVelocityIO.input(targetVelocity);

	NVector3f targetPos(teki.getPosition());
	teki.mPositionIO.input(targetPos);

	teki.mCircleMoveEvent->makeCircleMoveEvent(scaledPi, &teki.mPositionIO, &teki.mVelocityIO, 1.0f, 50.0f, 0.0f, piDivisor);
	teki.mCircleMoveEvent->reset();

	teki.mTargetAngle = teki.mCircleMoveEvent->mAngle;
	teki.setCreatureFlag(CF_Unk10);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stfd      f31, 0x100(r1)
	  stfd      f30, 0xF8(r1)
	  stfd      f29, 0xF0(r1)
	  stfd      f28, 0xE8(r1)
	  stfd      f27, 0xE0(r1)
	  stfd      f26, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  stw       r30, 0xD0(r1)
	  mr        r30, r4
	  lwz       r31, 0x418(r4)
	  cmplwi    r31, 0
	  beq-      .loc_0x26C
	  addi      r3, r1, 0xC0
	  bl        -0x1C074
	  lfs       f0, 0x94(r30)
	  addi      r3, r1, 0xC0
	  lfs       f1, 0x94(r31)
	  lfs       f3, 0x98(r31)
	  lfs       f2, 0x98(r30)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x9C(r31)
	  lfs       f1, 0x9C(r30)
	  fsubs     f2, f3, f2
	  stfs      f0, 0xC0(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0xC4(r1)
	  stfs      f0, 0xC8(r1)
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0xC4(r1)
	  bl        -0x1BEF0
	  addi      r3, r1, 0xB4
	  bl        -0x1C0BC
	  lfs       f30, 0xA0(r30)
	  fmr       f1, f30
	  bl        0xE2C38
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE2DC0
	  stfs      f1, 0xB4(r1)
	  addi      r3, r1, 0xA8
	  lfs       f0, -0x1070(r13)
	  stfs      f0, 0xB8(r1)
	  stfs      f31, 0xBC(r1)
	  bl        -0x1C0EC
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x74
	  lfs       f2, -0x5B8C(r2)
	  fmr       f3, f1
	  bl        -0x1C078
	  lfs       f0, 0x78(r1)
	  li        r31, 0
	  lfs       f2, 0xBC(r1)
	  lfs       f3, 0x7C(r1)
	  lfs       f1, 0xB8(r1)
	  fmuls     f5, f0, f2
	  lfs       f6, 0xB4(r1)
	  fmuls     f4, f3, f1
	  lfs       f7, 0x74(r1)
	  fmuls     f0, f0, f6
	  fmuls     f1, f7, f1
	  fsubs     f4, f5, f4
	  fmuls     f3, f3, f6
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0xA8(r1)
	  fsubs     f1, f3, f2
	  stfs      f1, 0xAC(r1)
	  stfs      f0, 0xB0(r1)
	  lfs       f3, 0xA8(r1)
	  lfs       f2, 0xC0(r1)
	  lfs       f1, 0xAC(r1)
	  lfs       f0, 0xC4(r1)
	  fmuls     f2, f3, f2
	  lfs       f4, 0xB0(r1)
	  fmuls     f1, f1, f0
	  lfs       f3, 0xC8(r1)
	  lfs       f0, -0x5B98(r2)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x158
	  li        r31, 0x1

	.loc_0x158:
	  lfs       f28, -0x5B58(r2)
	  addi      r3, r1, 0xA8
	  lfs       f2, -0x1CA4(r13)
	  lfs       f0, -0x5B20(r2)
	  fmuls     f1, f28, f2
	  fdivs     f0, f1, f0
	  fdivs     f26, f2, f0
	  fmr       f27, f0
	  bl        -0x1BFE8
	  lfs       f30, 0xA8(r1)
	  rlwinm.   r0,r31,0,24,31
	  lfs       f0, -0x5B58(r2)
	  lfs       f31, 0xAC(r1)
	  lfs       f29, 0xB0(r1)
	  fmuls     f30, f30, f0
	  fmuls     f31, f31, f0
	  fmuls     f29, f29, f0
	  beq-      .loc_0x1B0
	  fneg      f30, f30
	  fneg      f31, f31
	  fneg      f29, f29
	  fneg      f26, f26

	.loc_0x1B0:
	  addi      r3, r1, 0x80
	  bl        -0x1C1E8
	  addi      r31, r30, 0x94
	  lfs       f0, 0x94(r30)
	  addi      r3, r30, 0x368
	  lfs       f1, 0x98(r30)
	  addi      r4, r1, 0x80
	  fadds     f0, f0, f30
	  lfs       f2, 0x9C(r30)
	  fadds     f1, f1, f31
	  stfs      f0, 0x80(r1)
	  fadds     f0, f2, f29
	  stfs      f1, 0x84(r1)
	  stfs      f0, 0x88(r1)
	  lwz       r12, 0x368(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r4, r31, 0
	  addi      r3, r1, 0x68
	  bl        -0x1C208
	  lwz       r12, 0x358(r30)
	  addi      r4, r3, 0
	  addi      r3, r30, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  fmr       f1, f27
	  lwz       r3, 0x464(r30)
	  fmr       f3, f28
	  lfs       f2, -0x5B8C(r2)
	  fmr       f5, f26
	  lfs       f4, -0x5B98(r2)
	  addi      r4, r30, 0x358
	  addi      r5, r30, 0x368
	  bl        -0x12CD8
	  lwz       r3, 0x464(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x464(r30)
	  lfs       f0, 0x10(r3)
	  stfs      f0, 0x394(r30)
	  lwz       r0, 0xC8(r30)
	  ori       r0, r0, 0x200
	  stw       r0, 0xC8(r30)

	.loc_0x26C:
	  lwz       r0, 0x10C(r1)
	  lfd       f31, 0x100(r1)
	  lfd       f30, 0xF8(r1)
	  lfd       f29, 0xF0(r1)
	  lfd       f28, 0xE8(r1)
	  lfd       f27, 0xE0(r1)
	  lfd       f26, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139124
 * Size:	000018
 */
void TaiNapkidCirclingAction::finish(Teki& teki)
{
	teki.resetCreatureFlag(CF_Unk10);
	teki._3A4 = 0.0f;
}

/*
 * --INFO--
 * Address:	8013913C
 * Size:	000124
 */
bool TaiNapkidCirclingAction::act(Teki& teki)
{
	NVector3f velocity;
	teki.mVelocityIO.output(velocity);

	NVector3f sep;
	sep.sub2(velocity, teki.getPosition());
	sep.normalizeCheck();

	NVector3f direction;
	direction.add2(sep, teki.getDrive());
	teki.inputDirectionVector(direction);

	f32 temp  = NMathF::sin(teki.mCircleMoveEvent->mAngle - teki.mTargetAngle);
	teki._3A4 = -NMathF::pi * 0.25 * temp;

	if (teki.mCircleMoveEvent->isFinished()) {
		return true;
	}

	return false;

	u32 badCompiler[4];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  addi      r3, r1, 0x50
	  bl        -0x1C300
	  addi      r3, r31, 0x368
	  lwz       r12, 0x368(r31)
	  addi      r4, r1, 0x50
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x44
	  bl        -0x1C320
	  lfs       f1, 0x50(r1)
	  addi      r3, r1, 0x44
	  lfs       f0, 0x94(r31)
	  lfs       f3, 0x54(r1)
	  lfs       f2, 0x98(r31)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x9C(r31)
	  lfs       f4, 0x58(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x44(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x48(r1)
	  stfs      f0, 0x4C(r1)
	  bl        -0x1C194
	  addi      r3, r1, 0x38
	  bl        -0x1C360
	  lfs       f1, 0x44(r1)
	  lfs       f0, 0xA4(r31)
	  lfs       f3, 0x48(r1)
	  lfs       f2, 0xA8(r31)
	  fadds     f0, f1, f0
	  lfs       f4, 0x4C(r1)
	  lfs       f1, 0xAC(r31)
	  fadds     f2, f3, f2
	  stfs      f0, 0x38(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f2, 0x40(r1)
	  bl        -0x1B3E8
	  stfs      f1, 0xA0(r31)
	  lwz       r3, 0x464(r31)
	  lfs       f0, 0x394(r31)
	  lfs       f1, 0x10(r3)
	  fsubs     f1, f1, f0
	  bl        0xE2AE0
	  lfs       f2, -0x1CA4(r13)
	  lfs       f0, -0x5B14(r2)
	  fneg      f2, f2
	  fmuls     f0, f2, f0
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3A4(r31)
	  lwz       r3, 0x464(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x10C
	  li        r3, 0x1
	  b         .loc_0x110

	.loc_0x10C:
	  li        r3, 0

	.loc_0x110:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139260
 * Size:	000060
 */
bool TaiNapkidFlyingAction::act(Teki& teki)
{
	f32 seaLevel = teki.getSeaLevel();
	teki.getPosition().y += 0.15f * (_08 + seaLevel - teki.getPosition().y);
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  bl        0xF6E0
	  lfs       f0, 0x8(r30)
	  li        r3, 0
	  lfs       f2, 0x98(r31)
	  fadds     f0, f0, f1
	  lfs       f1, -0x5B10(r2)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x98(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801392C0
 * Size:	000024
 */
bool TaiNapkidAscendingAction::act(Teki& teki)
{
	teki.getPosition().y += NSystem::getFrameTime() * _08;
	return false;
}

/*
 * --INFO--
 * Address:	801392E4
 * Size:	00006C
 */
bool TaiNapkidApproachPikiAction::act(Teki& teki)
{
	Creature* targetCreature = teki.getCreaturePointer(0);
	if (targetCreature == nullptr) {
		return false;
	}

	if (!teki.inSectorPosition(targetCreature->getPosition(), teki.getParameterF(TPF_AttackableRange),
	                           teki.getParameterF(TPF_AttackableAngle))) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	80139350
 * Size:	000364
 */
bool TaiNapkidCatchingAction::act(Teki& teki)
{
	f32 counter = teki.mTekiAnimator->getCounter();
	f32 key     = teki.mTekiAnimator->getKeyValueByKeyType(2);
	if (key > counter) {
		return false;
	}

	key = teki.mTekiAnimator->getKeyValueByKeyType(3);
	if (counter > key) {
		return true;
	}

	Vector3f direction;
	teki.outputDirectionVector(direction);
	direction.scale(teki.getParameterF(TPF_AttackRange));

	NVector3f offset;
	offset.add2(teki.getPosition(), direction);

	TekiAndCondition notStickerAndIsRecognizedCond(&TekiRecognitionCondition(&teki), &TekiNotCondition(&TekiStickerCondition(&teki)));

	Vector3f spherePos;
	spherePos.set(offset);
	TekiPositionSphereDistanceCondition insideSphereCond(spherePos, teki.getParameterF(TPF_AttackHitRange));

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki == nullptr) {
			return false;
		}

		if (TekiAndCondition(&notStickerAndIsRecognizedCond, &insideSphereCond).satisfy(piki)) {
			CollPart* freeSlot = teki.getFreeSlot();
			if (freeSlot == nullptr) {
				return false;
			}

			InteractSwallow swallow(&teki, freeSlot, 0);
			piki->stimulate(swallow);
		}
	}

	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1C0(r1)
	  stfd      f31, 0x1B8(r1)
	  stfd      f30, 0x1B0(r1)
	  stfd      f29, 0x1A8(r1)
	  stmw      r22, 0x180(r1)
	  mr        r26, r4
	  lwz       r3, 0x2CC(r4)
	  li        r4, 0x2
	  lfs       f30, 0x2C(r3)
	  bl        -0x19B88
	  fcmpo     cr0, f30, f1
	  bge-      .loc_0x40
	  li        r3, 0
	  b         .loc_0x344

	.loc_0x40:
	  lwz       r3, 0x2CC(r26)
	  li        r4, 0x3
	  bl        -0x19BA4
	  fcmpo     cr0, f30, f1
	  ble-      .loc_0x5C
	  li        r3, 0x1
	  b         .loc_0x344

	.loc_0x5C:
	  lfs       f31, 0xA0(r26)
	  fmr       f1, f31
	  bl        0xE27A0
	  fmr       f30, f1
	  fmr       f1, f31
	  bl        0xE2928
	  lwz       r3, 0x2C4(r26)
	  fmr       f31, f1
	  lfs       f29, -0x1070(r13)
	  li        r4, 0xA
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x16F08
	  fmuls     f31, f31, f1
	  addi      r3, r1, 0x160
	  fmuls     f29, f29, f1
	  fmuls     f30, f30, f1
	  bl        -0x1C59C
	  lfs       f0, 0x94(r26)
	  lis       r8, 0x802B
	  lfs       f1, 0x98(r26)
	  lis       r5, 0x802C
	  fadds     f0, f0, f31
	  lfs       f2, 0x9C(r26)
	  lis       r7, 0x802D
	  fadds     f1, f1, f29
	  subi      r9, r7, 0x2A4C
	  stfs      f0, 0x160(r1)
	  fadds     f0, f2, f30
	  subi      r30, r8, 0xF68
	  stfs      f1, 0x164(r1)
	  lis       r6, 0x802C
	  addi      r31, r5, 0x6964
	  stfs      f0, 0x168(r1)
	  lis       r3, 0x802C
	  addi      r5, r3, 0x685C
	  stw       r30, 0x154(r1)
	  lis       r4, 0x802D
	  addi      r8, r6, 0x6890
	  stw       r30, 0x124(r1)
	  subi      r6, r4, 0x295C
	  addi      r3, r1, 0x134
	  stw       r30, 0x12C(r1)
	  addi      r7, r1, 0x124
	  addi      r0, r1, 0x12C
	  stw       r30, 0x134(r1)
	  li        r4, 0xB
	  stw       r31, 0x154(r1)
	  stw       r31, 0x124(r1)
	  stw       r31, 0x12C(r1)
	  stw       r31, 0x134(r1)
	  stw       r5, 0x154(r1)
	  stw       r9, 0x124(r1)
	  stw       r8, 0x12C(r1)
	  stw       r6, 0x134(r1)
	  stw       r3, 0x158(r1)
	  stw       r26, 0x128(r1)
	  stw       r7, 0x130(r1)
	  stw       r26, 0x138(r1)
	  stw       r0, 0x15C(r1)
	  lwz       r3, 0x2C4(r26)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x16FD4
	  lfs       f0, 0x160(r1)
	  lis       r4, 0x802D
	  subi      r0, r4, 0x28E0
	  fmr       f31, f1
	  stfs      f0, 0x104(r1)
	  addi      r5, r1, 0x108
	  lfs       f0, 0x164(r1)
	  addi      r6, r1, 0x10C
	  addi      r3, r1, 0x114
	  stfs      f0, 0x108(r1)
	  addi      r4, r1, 0x104
	  lfs       f0, 0x168(r1)
	  stfs      f0, 0x10C(r1)
	  stw       r30, 0x110(r1)
	  lfs       f0, -0x5B98(r2)
	  stw       r31, 0x110(r1)
	  stw       r0, 0x110(r1)
	  stfs      f0, 0x11C(r1)
	  stfs      f0, 0x118(r1)
	  stfs      f0, 0x114(r1)
	  bl        -0xDBE70
	  lwz       r28, 0x3068(r13)
	  addi      r31, r1, 0x154
	  stfs      f31, 0x120(r1)
	  addi      r29, r1, 0x110
	  addi      r3, r28, 0
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802B
	  addi      r27, r3, 0
	  subi      r24, r5, 0x3064
	  subi      r25, r4, 0x3244
	  addi      r30, r1, 0xF4
	  b         .loc_0x2E4

	.loc_0x1F0:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x214
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x22C

	.loc_0x214:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x22C:
	  cmplwi    r3, 0
	  addi      r22, r3, 0
	  beq-      .loc_0x340
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  addi      r4, r22, 0
	  li        r23, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x280
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r22
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x280
	  li        r23, 0x1

	.loc_0x280:
	  rlwinm.   r0,r23,0,24,31
	  beq-      .loc_0x2C8
	  mr        r3, r26
	  bl        0xFF84
	  cmplwi    r3, 0
	  beq-      .loc_0x340
	  stw       r24, 0xF4(r1)
	  li        r0, 0
	  addi      r4, r30, 0
	  stw       r26, 0xF8(r1)
	  stw       r25, 0xF4(r1)
	  stw       r0, 0xFC(r1)
	  stw       r3, 0x100(r1)
	  mr        r3, r22
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x2E4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x30C
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x30C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x334
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x334:
	  li        r0, 0

	.loc_0x338:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x1F0

	.loc_0x340:
	  li        r3, 0

	.loc_0x344:
	  lmw       r22, 0x180(r1)
	  lwz       r0, 0x1C4(r1)
	  lfd       f31, 0x1B8(r1)
	  lfd       f30, 0x1B0(r1)
	  lfd       f29, 0x1A8(r1)
	  addi      r1, r1, 0x1C0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801396B4
 * Size:	00017C
 */
void TaiNapkidCatchDescendingAction::start(Teki& teki)
{
	teki.stopMove();

	NVector3f position(teki.getPosition());
	teki.mPositionIO.input(position);

	NVector3f velocity;
	teki.outputDirectionVector(velocity);
	velocity.scale(160.0f);
	velocity.y = -240.0f;
	teki.mVelocityIO.input(velocity);

	NVector3f acceleration(0.0f, -320.0f, 0.0f);
	teki.mAccelerationIO.input(acceleration);

	teki.mAccelEvent->makeAccelerationEvent(nullptr, &teki.mPositionIO, &teki.mVelocityIO, &teki.mAccelerationIO);
	teki.mAccelEvent->reset();
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x1078
	  stw       r0, 0x4(r1)
	  subi      r6, r13, 0x1074
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  addi      r3, r1, 0x28
	  stfd      f30, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r4, 0
	  subi      r4, r13, 0x107C
	  bl        -0x1025C4
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x28
	  addi      r5, r1, 0x2C
	  addi      r6, r1, 0x30
	  bl        -0xDC068
	  addi      r3, r1, 0x1C
	  subi      r4, r13, 0x1088
	  subi      r5, r13, 0x1084
	  subi      r6, r13, 0x1080
	  bl        -0x1025EC
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x1C
	  addi      r5, r1, 0x20
	  addi      r6, r1, 0x24
	  bl        -0xDC090
	  addi      r4, r31, 0x94
	  addi      r3, r1, 0x34
	  bl        -0x1C8A8
	  lwz       r12, 0x358(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x4C
	  bl        -0x1C8F4
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xE2400
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE2588
	  stfs      f1, 0x4C(r1)
	  addi      r3, r31, 0x368
	  lfs       f0, -0x1070(r13)
	  addi      r4, r1, 0x4C
	  stfs      f0, 0x50(r1)
	  stfs      f31, 0x54(r1)
	  lfs       f0, 0x4C(r1)
	  lfs       f1, -0x5B28(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x54(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x54(r1)
	  lfs       f0, -0x5B0C(r2)
	  stfs      f0, 0x50(r1)
	  lwz       r12, 0x368(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x40
	  lfs       f2, -0x5B08(r2)
	  fmr       f3, f1
	  bl        -0x1C8F0
	  addi      r3, r31, 0x378
	  lwz       r12, 0x378(r31)
	  addi      r4, r1, 0x40
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x460(r31)
	  addi      r5, r31, 0x358
	  addi      r6, r31, 0x368
	  addi      r7, r31, 0x378
	  li        r4, 0
	  bl        -0x138B8
	  lwz       r3, 0x460(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139830
 * Size:	0002CC
 */
bool TaiNapkidCatchTracingAction::act(Teki& teki)
{
	Creature* target = teki.getCreaturePointer(0);
	NVector3f targetPos;
	target->outputPosition(targetPos);
	targetPos.y = 0.0f;

	NVector3f pos;
	teki.outputPosition(pos);
	pos.y = 0.0f;

	NVector3f dir;
	teki.outputDirectionVector(dir);

	NVector3f sep;
	sep.sub2(targetPos, pos);
	sep.normalizeCheck();

	NVector3f crossVec;
	crossVec.cross(sep, dir);

	NVector3f acceleration;
	teki.mAccelerationIO.output(acceleration);

	if (NMathf::absolute(crossVec.y) < 0.1f) {
		acceleration.x = 0.0f;
		acceleration.z = 0.0f;
	} else {
		NVector3f crossVec2;
		crossVec2.cross(dir, NVector3f(0.0f, 1.0f, 0.0f));
		crossVec2.normalizeCheck();
		crossVec2.scale(300.0f);

		if (crossVec.y > 0.0f) {
			acceleration.x = crossVec2.x;
			acceleration.z = crossVec2.z;
		} else {
			acceleration.x = -crossVec2.x;
			acceleration.z = -crossVec2.z;
		}
	}

	teki.mAccelerationIO.input(acceleration);

	// okay i guess
	NVector3f velocity;
	teki.mVelocityIO.output(velocity);
	teki.mVelocityIO.input(velocity);

	return false;

	u32 bad[6];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stfd      f31, 0xD8(r1)
	  addi      r3, r1, 0xB8
	  stfd      f30, 0xD0(r1)
	  stw       r31, 0xCC(r1)
	  stw       r30, 0xC8(r1)
	  mr        r30, r4
	  lwz       r31, 0x418(r4)
	  bl        -0x1CA04
	  lwz       r4, 0x94(r31)
	  addi      r3, r1, 0xAC
	  lwz       r0, 0x98(r31)
	  lfs       f0, -0x5B98(r2)
	  stw       r4, 0xB8(r1)
	  stw       r0, 0xBC(r1)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0xC0(r1)
	  stfs      f0, 0xBC(r1)
	  bl        -0x1CA2C
	  lwz       r4, 0x94(r30)
	  addi      r3, r1, 0xA0
	  lwz       r0, 0x98(r30)
	  lfs       f0, -0x5B98(r2)
	  stw       r4, 0xAC(r1)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0xB4(r1)
	  stfs      f0, 0xB0(r1)
	  bl        -0x1CA54
	  lfs       f30, 0xA0(r30)
	  fmr       f1, f30
	  bl        0xE22A0
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE2428
	  stfs      f1, 0xA0(r1)
	  addi      r3, r1, 0x94
	  lfs       f0, -0x1070(r13)
	  stfs      f0, 0xA4(r1)
	  stfs      f31, 0xA8(r1)
	  bl        -0x1CA84
	  lfs       f1, 0xB8(r1)
	  addi      r3, r1, 0x94
	  lfs       f0, 0xAC(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x94(r1)
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0xB0(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0xC0(r1)
	  lfs       f0, 0xB4(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  bl        -0x1C8F8
	  addi      r3, r1, 0x88
	  bl        -0x1CAC4
	  lfs       f0, 0x98(r1)
	  addi      r3, r1, 0x7C
	  lfs       f2, 0xA8(r1)
	  lfs       f3, 0x9C(r1)
	  lfs       f1, 0xA4(r1)
	  fmuls     f5, f0, f2
	  lfs       f6, 0xA0(r1)
	  fmuls     f4, f3, f1
	  lfs       f7, 0x94(r1)
	  fmuls     f0, f0, f6
	  fmuls     f1, f7, f1
	  fsubs     f4, f5, f4
	  fmuls     f3, f3, f6
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0x88(r1)
	  fsubs     f1, f3, f2
	  stfs      f1, 0x8C(r1)
	  stfs      f0, 0x90(r1)
	  bl        -0x1CB14
	  addi      r3, r30, 0x378
	  lwz       r12, 0x378(r30)
	  addi      r4, r1, 0x7C
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x8C(r1)
	  lfs       f0, -0x5B98(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x168
	  b         .loc_0x16C

	.loc_0x168:
	  fneg      f1, f1

	.loc_0x16C:
	  lfs       f0, -0x5B04(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x188
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0x7C(r1)
	  stfs      f0, 0x84(r1)
	  b         .loc_0x258

	.loc_0x188:
	  addi      r3, r1, 0x70
	  bl        -0x1CB68
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x4C
	  lfs       f2, -0x5B8C(r2)
	  fmr       f3, f1
	  bl        -0x1CAF4
	  lfs       f0, 0xA4(r1)
	  addi      r3, r1, 0x70
	  lfs       f2, 0x54(r1)
	  lfs       f3, 0xA8(r1)
	  lfs       f1, 0x50(r1)
	  fmuls     f5, f0, f2
	  lfs       f6, 0x4C(r1)
	  fmuls     f4, f3, f1
	  lfs       f7, 0xA0(r1)
	  fmuls     f0, f0, f6
	  fmuls     f1, f7, f1
	  fsubs     f4, f5, f4
	  fmuls     f3, f3, f6
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0x70(r1)
	  fsubs     f1, f3, f2
	  stfs      f1, 0x74(r1)
	  stfs      f0, 0x78(r1)
	  bl        -0x1CA08
	  lfs       f0, 0x70(r1)
	  lfs       f1, -0x5B00(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x78(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0x8C(r1)
	  lfs       f0, -0x5B98(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x240
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x84(r1)
	  b         .loc_0x258

	.loc_0x240:
	  lfs       f0, 0x70(r1)
	  fneg      f0, f0
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x78(r1)
	  fneg      f0, f0
	  stfs      f0, 0x84(r1)

	.loc_0x258:
	  addi      r3, r30, 0x378
	  lwz       r12, 0x378(r30)
	  addi      r4, r1, 0x7C
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x64
	  bl        -0x1CC50
	  addi      r3, r30, 0x368
	  lwz       r12, 0x368(r30)
	  addi      r4, r1, 0x64
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x368
	  lwz       r12, 0x368(r30)
	  addi      r4, r1, 0x64
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xE4(r1)
	  li        r3, 0
	  lfd       f31, 0xD8(r1)
	  lfd       f30, 0xD0(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139AFC
 * Size:	0000E4
 */
void TaiNapkidCatchFlyingAction::start(Teki& teki)
{
	teki.mPositionIO.input(NVector3f(teki.getPosition()));

	NVector3f vel;
	teki.mVelocityIO.output(vel);
	vel.y = 0.0f;
	teki.mVelocityIO.input(vel);

	NVector3f accel(0.0f, 0.0f, 0.0f);
	teki.mAccelerationIO.input(accel);

	teki.mAccelEvent->makeAccelerationEvent(nullptr, &teki.mPositionIO, &teki.mVelocityIO, &teki.mAccelerationIO);
	teki.mAccelEvent->reset();
}

/*
 * --INFO--
 * Address:	80139BE0
 * Size:	0000E4
 */
void TaiNapkidCatchAscendingAction::start(Teki& teki)
{
	teki.mPositionIO.input(NVector3f(teki.getPosition()));

	NVector3f vel;
	teki.mVelocityIO.output(vel);
	vel.y = 0.0f;
	teki.mVelocityIO.input(vel);

	NVector3f accel(0.0f, 200.0f, 0.0f);
	teki.mAccelerationIO.input(accel);

	teki.mAccelEvent->makeAccelerationEvent(nullptr, &teki.mPositionIO, &teki.mVelocityIO, &teki.mAccelerationIO);
	teki.mAccelEvent->reset();
}

/*
 * --INFO--
 * Address:	80139CC4
 * Size:	000198
 */
void TaiNapkidTakingOffAscendingAction::start(Teki& teki)
{
	Stickers stickers(&teki);
	int stickerCount = stickers.getCount();

	f32 values[2];
	NClampLinearFunction linearFunc(values);
	linearFunc.makeClampLinearFunction(0.0f, 1.0f, 10.0f, 0.7f);
	f32 linFuncValue = linearFunc.getValue(f32(stickerCount));

	teki.mPositionIO.input(NVector3f(teki.getPosition()));

	NVector3f takeOffVel;
	teki.outputDirectionVector(takeOffVel);
	takeOffVel.scale(30.0f);
	takeOffVel.y = linFuncValue * 270.0f;
	teki.mVelocityIO.input(takeOffVel);

	NVector3f accel(0.0f, -300.0f, 0.0f);
	teki.mAccelerationIO.input(accel);

	teki.mAccelEvent->makeAccelerationEvent(nullptr, &teki.mPositionIO, &teki.mVelocityIO, &teki.mAccelerationIO);
	teki.mAccelEvent->reset();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  addi      r3, r1, 0x60
	  stfd      f30, 0x88(r1)
	  stfd      f29, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  addi      r30, r4, 0
	  bl        -0xA9068
	  lwz       r31, 0x68(r1)
	  addi      r3, r1, 0x44
	  addi      r4, r1, 0x58
	  bl        -0x1E484
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x44
	  lfs       f2, -0x5B8C(r2)
	  lfs       f3, -0x5B88(r2)
	  lfs       f4, -0x5B30(r2)
	  bl        -0x1E3F8
	  xoris     r0, r31, 0x8000
	  lfd       f1, -0x5AF0(r2)
	  stw       r0, 0x74(r1)
	  lis       r0, 0x4330
	  addi      r3, r1, 0x44
	  stw       r0, 0x70(r1)
	  lfd       f0, 0x70(r1)
	  fsubs     f1, f0, f1
	  bl        -0x1E38C
	  fmr       f30, f1
	  addi      r4, r30, 0x94
	  addi      r3, r1, 0x20
	  bl        -0x1CEC8
	  lwz       r12, 0x358(r30)
	  addi      r4, r3, 0
	  addi      r3, r30, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x38
	  bl        -0x1CF14
	  lfs       f29, 0xA0(r30)
	  fmr       f1, f29
	  bl        0xE1DE0
	  fmr       f31, f1
	  fmr       f1, f29
	  bl        0xE1F68
	  stfs      f1, 0x38(r1)
	  addi      r3, r30, 0x368
	  lfs       f0, -0x1070(r13)
	  addi      r4, r1, 0x38
	  stfs      f0, 0x3C(r1)
	  stfs      f31, 0x40(r1)
	  lfs       f0, 0x38(r1)
	  lfs       f1, -0x5B5C(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x40(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x40(r1)
	  lfs       f0, -0x5AFC(r2)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x3C(r1)
	  lwz       r12, 0x368(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x2C
	  lfs       f2, -0x5AF8(r2)
	  fmr       f3, f1
	  bl        -0x1CF14
	  addi      r3, r30, 0x378
	  lwz       r12, 0x378(r30)
	  addi      r4, r1, 0x2C
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x460(r30)
	  addi      r5, r30, 0x358
	  addi      r6, r30, 0x368
	  addi      r7, r30, 0x378
	  li        r4, 0
	  bl        -0x13EDC
	  lwz       r3, 0x460(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  lfd       f29, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139E5C
 * Size:	00012C
 */
void TaiNapkidRisingAscendingAction::start(Teki& teki)
{
	teki.mPositionIO.input(NVector3f(teki.getPosition()));

	NVector3f newVel;
	teki.outputDirectionVector(newVel);
	newVel.scale(30.0f);
	newVel.y = 0.0f;
	teki.mVelocityIO.input(newVel);

	NVector3f ascendingAccel(0.0f, 200.0f, 0.0f);
	teki.mAccelerationIO.input(ascendingAccel);

	teki.mAccelEvent->makeAccelerationEvent(nullptr, &teki.mPositionIO, &teki.mVelocityIO, &teki.mAccelerationIO);
	teki.mAccelEvent->reset();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  addi      r3, r1, 0x1C
	  stfd      f30, 0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r4, 0
	  addi      r4, r31, 0x94
	  bl        -0x1D000
	  lwz       r12, 0x358(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x34
	  bl        -0x1D04C
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xE1CA8
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xE1E30
	  stfs      f1, 0x34(r1)
	  addi      r3, r31, 0x368
	  lfs       f0, -0x1070(r13)
	  addi      r4, r1, 0x34
	  stfs      f0, 0x38(r1)
	  stfs      f31, 0x3C(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f1, -0x5B5C(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x38(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  lfs       f0, -0x5B98(r2)
	  stfs      f0, 0x38(r1)
	  lwz       r12, 0x368(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x28
	  lfs       f2, -0x5B94(r2)
	  fmr       f3, f1
	  bl        -0x1D048
	  addi      r3, r31, 0x378
	  lwz       r12, 0x378(r31)
	  addi      r4, r1, 0x28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x460(r31)
	  addi      r5, r31, 0x358
	  addi      r6, r31, 0x368
	  addi      r7, r31, 0x378
	  li        r4, 0
	  bl        -0x14010
	  lwz       r3, 0x460(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lfd       f30, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80139F88
 * Size:	0001D4
 */
bool TaiNapkidThrowingPikiAction::act(Teki& teki)
{

	// regswaps here
	if (teki.getAnimationKeyOption(Teki::ANIMATION_KEY_OPTION_ACTION_0)) {
		NVector3f throwVel(teki.mVelocity);
		throwVel.y = -teki.getParameterF(NAPKIDPF_Unk12);

		Stickers stickers(&teki);
		Iterator iter(&stickers);
		CI_LOOP(iter)
		{
			Creature* throwPiki = *iter;
			if (throwPiki != nullptr) {
				if (throwPiki->isStickToMouth()) {
					throwPiki->endStickMouth();

					throwPiki->stimulate(InteractThrowAway(&teki));

					throwPiki->mVelocity.set(throwVel);
					return false;
				}
			} else {
				break;
			}
		}
	}

	u32 bad[8];
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  mr        r31, r4
	  stw       r30, 0xA0(r1)
	  stw       r29, 0x9C(r1)
	  stw       r28, 0x98(r1)
	  lwz       r0, -0x99C(r13)
	  lwz       r3, 0x414(r4)
	  and.      r0, r3, r0
	  beq-      .loc_0x1B0
	  addi      r4, r31, 0x70
	  addi      r3, r1, 0x8C
	  bl        -0x1D140
	  lwz       r3, 0x2C4(r31)
	  mr        r4, r31
	  lwz       r5, 0x84(r3)
	  addi      r3, r1, 0x7C
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0xF8(r5)
	  fneg      f0, f0
	  stfs      f0, 0x90(r1)
	  bl        -0xA9364
	  addi      r29, r1, 0x7C
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x154

	.loc_0x84:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xAC
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xC8

	.loc_0xAC:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xC8:
	  cmplwi    r30, 0
	  beq-      .loc_0x1B0
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x138
	  mr        r3, r30
	  bl        -0xAA04C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x68(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2F38
	  stw       r31, 0x6C(r1)
	  addi      r4, r1, 0x68
	  addi      r3, r30, 0
	  stw       r0, 0x68(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x8C(r1)
	  li        r3, 0
	  stfs      f0, 0x70(r30)
	  lfs       f0, 0x90(r1)
	  stfs      f0, 0x74(r30)
	  lfs       f0, 0x94(r1)
	  stfs      f0, 0x78(r30)
	  b         .loc_0x1B4

	.loc_0x138:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x154:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x17C
	  li        r0, 0x1
	  b         .loc_0x1A8

	.loc_0x17C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1A4
	  li        r0, 0x1
	  b         .loc_0x1A8

	.loc_0x1A4:
	  li        r0, 0

	.loc_0x1A8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x84

	.loc_0x1B0:
	  li        r3, 0

	.loc_0x1B4:
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  lwz       r28, 0x98(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013A15C
 * Size:	0000C4
 */
bool TaiNapkidFlickAction::act(Teki& teki)
{
	Stickers stickers(&teki);
	int stickCount = stickers.getCount();

	f32 linValues[1];
	NClampLinearFunction cLinearFunc(linValues);
	cLinearFunc.makeClampLinearFunction(1.0f, 0.1f, 5.0f, 0.7f);

	f32 flickChance = cLinearFunc.getValue(f32(stickCount));
	if (NMathF::occurred(flickChance)) {
		return false;
	}

	u32 bad[4];
	return true;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  addi      r3, r1, 0x44
	  stw       r31, 0x6C(r1)
	  bl        -0xA94F0
	  lwz       r31, 0x4C(r1)
	  addi      r3, r1, 0x28
	  addi      r4, r1, 0x3C
	  bl        -0x1E90C
	  lfs       f1, -0x5B8C(r2)
	  addi      r3, r1, 0x28
	  lfs       f2, -0x5B04(r2)
	  lfs       f3, -0x5B24(r2)
	  lfs       f4, -0x5B30(r2)
	  bl        -0x1E880
	  xoris     r0, r31, 0x8000
	  lfd       f1, -0x5AF0(r2)
	  stw       r0, 0x64(r1)
	  lis       r31, 0x4330
	  addi      r3, r1, 0x28
	  stw       r31, 0x60(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f1, f0, f1
	  bl        -0x1E814
	  fmr       f31, f1
	  bl        0xDDEA8
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x5AF0(r2)
	  stw       r0, 0x5C(r1)
	  lfs       f1, -0x5AE8(r2)
	  stw       r31, 0x58(r1)
	  lfs       f0, -0x5B8C(r2)
	  lfd       f2, 0x58(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0xA8
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0xA8:
	  li        r3, 0x1

	.loc_0xAC:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013A220
 * Size:	0001A8
 */
void TaiNapkidFallingAction::start(Teki& teki)
{
	teki.mPositionIO.input(NVector3f(teki.getPosition()));

	NVector3f fallVel(0.0f, -20.0f, 0.0f);
	teki.mParabolaEvent->makeParabolaEvent(nullptr, &teki.mPositionIO, fallVel, 1000.0f, teki.getGravity());
	teki.mParabolaEvent->reset();

	Stickers stickers(&teki);
	Iterator iter(&stickers);
	CI_LOOP(iter)
	{
		Creature* heldPiki = *iter;
		if (heldPiki == nullptr) {
			return;
		}

		if (heldPiki != nullptr && heldPiki->isStickToMouth()) {
			heldPiki->endStickMouth();
			iter.dec();
		}
	}

	u32 bad[4];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r3, r1, 0x28
	  stw       r30, 0x60(r1)
	  addi      r30, r4, 0
	  addi      r4, r30, 0x94
	  bl        -0x1D3C0
	  lwz       r12, 0x358(r30)
	  addi      r4, r3, 0
	  addi      r3, r30, 0x358
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5B98(r2)
	  addi      r3, r1, 0x50
	  lfs       f2, -0x5AE4(r2)
	  fmr       f3, f1
	  bl        -0x1D390
	  mr        r3, r30
	  bl        0xE6B4
	  fmr       f2, f1
	  lwz       r3, 0x45C(r30)
	  lfs       f1, -0x5B84(r2)
	  addi      r5, r30, 0x358
	  addi      r6, r1, 0x50
	  li        r4, 0
	  bl        -0x14148
	  lwz       r3, 0x45C(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x40
	  addi      r4, r30, 0
	  bl        -0xA962C
	  addi      r31, r1, 0x40
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x134

	.loc_0xB4:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xD8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xF0

	.loc_0xD8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xF0:
	  cmplwi    r3, 0
	  beq-      .loc_0x190
	  beq-      .loc_0x118
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x118
	  bl        -0xAA30C
	  cmpwi     r30, 0
	  blt-      .loc_0x118
	  subi      r30, r30, 0x1

	.loc_0x118:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x134:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x15C
	  li        r0, 0x1
	  b         .loc_0x188

	.loc_0x15C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x184
	  li        r0, 0x1
	  b         .loc_0x188

	.loc_0x184:
	  li        r0, 0

	.loc_0x188:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB4

	.loc_0x190:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013A3C8
 * Size:	000008
 */
bool TaiNapkidFallingAction::act(Teki&)
{
	return false;
}

/*
 * --INFO--
 * Address:	8013A3D0
 * Size:	000014
 */
void TaiNapkidShockFallingAction::start(Teki& teki)
{
	teki.getPosition().y += 10.0f;
}

/*
 * --INFO--
 * Address:	8013A3E4
 * Size:	0000D8
 */
void TaiNapkidFallingWaterEffectAction::start(Teki& teki)
{
	int mapCode = teki.getPositionMapCode();

	Vector3f pos(teki.getPosition());
	f32 minY = mapMgr->getMinY(pos.x, pos.z, true);
	pos.y    = minY;

	if (mapCode == ATTR_Water) {
		effectMgr->create(EffectMgr::EFF_Frog_BubbleRingS, pos, nullptr, nullptr);
		teki.playSound(SE_FLOG_WATERLAND);
	} else {
		effectMgr->create(EffectMgr::EFF_SmokeRing_S, pos, nullptr, nullptr);
		teki.playSound(SE_FLOG_LAND);
	}

	u32 bad[2];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  addi      r3, r30, 0
	  bl        0xF534
	  lfs       f0, 0x94(r30)
	  mr        r31, r3
	  li        r4, 0x1
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x24(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x1C(r1)
	  lfs       f2, 0x24(r1)
	  bl        -0xD252C
	  cmpwi     r31, 0x5
	  stfs      f1, 0x20(r1)
	  bne-      .loc_0x90
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x1C
	  li        r4, 0x55
	  li        r6, 0
	  li        r7, 0
	  bl        0x626E4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0x15
	  lwz       r12, 0x1C0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xC0

	.loc_0x90:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x1C
	  li        r4, 0x44
	  li        r6, 0
	  li        r7, 0
	  bl        0x626B0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0x10
	  lwz       r12, 0x1C0(r12)
	  mtlr      r12
	  blrl

	.loc_0xC0:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013A4BC
 * Size:	000044
 */
void TaiNapkidStartDroppingWaterAction::start(Teki& teki)
{
	if (teki.getPositionMapCode() == ATTR_Water) {
		teki.startParticleGenerator(0);
	}
}
