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
	TaiStopMoveAction* stopMove                = new TaiStopMoveAction;
	TaiStartFlyingAction* startFlying          = new TaiStartFlyingAction;
	TaiFinishFlyingAction* finishFlying        = new TaiFinishFlyingAction;
	TaiAccelerationAction* acceleration        = new TaiAccelerationAction;
	TaiParabolaAction* parabola                = new TaiParabolaAction;
	TaiCircleMoveAction* circleMove            = new TaiCircleMoveAction;
	TaiMakingNextVelocityAction* makingNextVel = new TaiMakingNextVelocityAction;
	TaiMakeVelocityDirectionAction* makeVelDir = new TaiMakeVelocityDirectionAction;
	new TaiMakeAccelerationDirectionAction; // never actually used
	TaiHasStickersOnBodyAction* stickersOnBody1 = new TaiHasStickersOnBodyAction(NAPKIDSTATE_Unk15);
	TaiDeadAction* dead1                        = new TaiDeadAction(NAPKIDSTATE_Unk15);
	TaiDeadAction* dead2                        = new TaiDeadAction(NAPKIDSTATE_Dying);
	new TaiFlickAction(NAPKIDSTATE_Unk21); // never actually used
	TaiNapkidTargetPikiAction* targetPiki1 = new TaiNapkidTargetPikiAction(NAPKIDSTATE_Unk4);
	TaiSimultaneousDamageAction* simDamage = new TaiSimultaneousDamageAction(TAI_NO_TRANSIT);
	TaiNapkidFlyingAction* napkidFlying1   = new TaiNapkidFlyingAction(params->getF(TPF_FlightHeight));
	TaiNapkidFlyingAction* napkidFlying2   = new TaiNapkidFlyingAction(params->getF(NAPKIDPF_Unk1));
	TaiDyingAction* dying                  = new TaiDyingAction(NAPKIDANIM_Unk0);
	TaiStartDyingAction* startDying        = new TaiStartDyingAction;

	// STATE 0 - Dying
	TaiState* state = new TaiState(3);
	int j           = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, startDying);
	state->setAction(j++, dying);
	setState(NAPKIDSTATE_Dying, state);

	TaiNapkidWanderingRouteAction* wanderRoute1 = new TaiNapkidWanderingRouteAction(NAPKIDANIM_Unk6, params->getF(TPF_WalkVelocity));
	TaiStartingTimerAction* chanceTimer1
	    = new TaiStartingTimerAction(NAPKIDSTATE_Unk2, 0, params->getF(NAPKIDPF_Unk3), 0.5f, params->getF(NAPKIDPF_Unk4));
	TaiHeadOnCollisionAvoidanceAction* headOnAvoidance = new TaiHeadOnCollisionAvoidanceAction(50.0f);

	// STATE 1 - Wandering?
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, startFlying);
	state->setAction(j++, simDamage);
	state->setAction(j++, stickersOnBody1);
	state->setAction(j++, dead1);
	state->setAction(j++, targetPiki1);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, chanceTimer1);
	state->setAction(j++, wanderRoute1);
	state->setAction(j++, headOnAvoidance);
	setState(NAPKIDSTATE_Unk1, state);

	TaiContinuousMotionAction* continousMotion1 = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk6);
	TaiStartingTimerAction* chanceTimer2
	    = new TaiStartingTimerAction(NAPKIDSTATE_Unk1, 0, params->getF(NAPKIDPF_Unk5), 0.5f, params->getF(NAPKIDPF_Unk6));
	TaiStartingTimerAction* chanceTimer3
	    = new TaiStartingTimerAction(NAPKIDSTATE_Unk3, 1, params->getF(NAPKIDPF_Unk7), 0.5f, params->getF(NAPKIDPF_Unk8));

	// STATE 2 - Idle?
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, simDamage);
	state->setAction(j++, stickersOnBody1);
	state->setAction(j++, dead1);
	state->setAction(j++, targetPiki1);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, chanceTimer2);
	state->setAction(j++, chanceTimer3);
	state->setAction(j++, continousMotion1);
	setState(NAPKIDSTATE_Unk2, state);

	TaiStartingTimerAction* chanceTimer4
	    = new TaiStartingTimerAction(NAPKIDSTATE_Unk1, 0, params->getF(NAPKIDPF_Unk9), 0.5f, params->getF(NAPKIDPF_Unk10));
	TaiContinuousMotionAction* continousMotion2 = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk2);

	// STATE 3 - Go home?
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, stickersOnBody1);
	state->setAction(j++, dead1);
	state->setAction(j++, targetPiki1);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, chanceTimer4);
	state->setAction(j++, continousMotion2);
	setState(NAPKIDSTATE_Unk3, state);

	TaiNapkidTargetPikiAction* targetPiki2    = new TaiNapkidTargetPikiAction(TAI_NO_TRANSIT);
	TaiNapkidApproachPikiAction* approachPiki = new TaiNapkidApproachPikiAction(NAPKIDSTATE_Unk7);
	TaiNapkidPikiLostAction* lostPiki         = new TaiNapkidPikiLostAction(NAPKIDSTATE_Unk1);
	TaiNapkidShortRangeAction* shortRange     = new TaiNapkidShortRangeAction(NAPKIDSTATE_Unk5);
	TaiTracingAction* tracing                 = new TaiTracingAction(NAPKIDANIM_Unk6, params->getF(TPF_RunVelocity));

	// STATE 4 - Chasing?
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, stickersOnBody1);
	state->setAction(j++, dead1);
	state->setAction(j++, approachPiki);
	state->setAction(j++, targetPiki2);
	state->setAction(j++, shortRange);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, lostPiki);
	state->setAction(j++, tracing);
	setState(NAPKIDSTATE_Unk4, state);

	TaiNapkidStraightFlyingAction* straightFlying = new TaiNapkidStraightFlyingAction(NAPKIDSTATE_Unk6, 160.0f);
	TaiTimerAction* timer                         = new TaiTimerAction(NAPKIDSTATE_Unk6, 0, 5.0f, 0.0f);
	TaiContinuousMotionAction* continousMotion3   = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk6);

	// STATE 5 - Outrun target?
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, stickersOnBody1);
	state->setAction(j++, dead1);
	state->setAction(j++, approachPiki);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, straightFlying);
	state->setAction(j++, timer);
	state->setAction(j++, continousMotion3);
	setState(NAPKIDSTATE_Unk5, state);

	TaiNapkidCirclingAction* circling       = new TaiNapkidCirclingAction(NAPKIDSTATE_Unk1);
	TaiMakingNextDriveAction* makeNextDrive = new TaiMakingNextDriveAction(150.0f);

	// STATE 6 - Circle target?
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, stickersOnBody1);
	state->setAction(j++, dead1);
	state->setAction(j++, circleMove);
	state->setAction(j++, makeNextDrive);
	state->setAction(j++, circling);
	setState(NAPKIDSTATE_Unk6, state);

	TaiFinishMotionAction* finishMotion1 = new TaiFinishMotionAction(NAPKIDSTATE_Unk8);

	// STATE 7 - (Unknown)
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, stickersOnBody1);
	state->setAction(j++, dead1);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, finishMotion1);
	setState(NAPKIDSTATE_Unk7, state);

	TaiNapkidCatchTracingAction* catchTracing       = new TaiNapkidCatchTracingAction;
	TaiNapkidCatchingAction* catching               = new TaiNapkidCatchingAction(NAPKIDSTATE_Unk10);
	TaiMotionAction* motion1                        = new TaiMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk8);
	TaiNapkidCatchDescendingAction* catchDescending = new TaiNapkidCatchDescendingAction;
	TaiClampMinHeightAction* clampMinHeight1        = new TaiClampMinHeightAction(NAPKIDSTATE_Unk9, 10.0f);

	// STATE 8 - (Unknown)
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, catchDescending);
	state->setAction(j++, catchTracing);
	state->setAction(j++, acceleration);
	state->setAction(j++, clampMinHeight1);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, motion1);
	state->setAction(j++, catching);
	state->setAction(j++, makeVelDir);
	setState(NAPKIDSTATE_Unk8, state);

	TaiNapkidCatchFlyingAction* catchFlying  = new TaiNapkidCatchFlyingAction;
	TaiClampMinHeightAction* clampMinHeight2 = new TaiClampMinHeightAction(TAI_NO_TRANSIT, 10.0f);

	// State 9 - (Unknown)
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, catchFlying);
	state->setAction(j++, catchTracing);
	state->setAction(j++, acceleration);
	state->setAction(j++, clampMinHeight2);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, catching);
	state->setAction(j++, makeVelDir);
	setState(NAPKIDSTATE_Unk9, state);

	TaiHasStickersInMouthAction* stickersInMouth = new TaiHasStickersInMouthAction(NAPKIDSTATE_Unk11);
	TaiOnceAction* once1                         = new TaiOnceAction(NAPKIDSTATE_Unk12);

	// STATE 10 - (Unknown)
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, acceleration);
	state->setAction(j++, clampMinHeight2);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, stickersInMouth);
	state->setAction(j++, once1);
	setState(NAPKIDSTATE_Unk10, state);

	TaiNapkidCatchAscendingAction* ascending = new TaiNapkidCatchAscendingAction;
	TaiClampMaxHeightAction* clampMaxHeight1 = new TaiClampMaxHeightAction(NAPKIDSTATE_Unk1, params->getF(TPF_FlightHeight));

	TaiSerialAction* serial1 = new TaiSerialAction(NAPKIDSTATE_Unk19, 2);
	serial1->setAction(0, new TaiSwitchMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk13));
	serial1->setAction(1, new TaiMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk6));

	// STATE 12 - (Unknown)
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, acceleration);
	state->setAction(j++, clampMinHeight2);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, serial1);
	state->setAction(j++, ascending);
	state->setAction(j++, clampMaxHeight1);
	setState(NAPKIDSTATE_Unk12, state);

	TaiNapkidCatchAscendingAction* catchAscending = new TaiNapkidCatchAscendingAction;
	TaiClampMaxHeightAction* clampMaxHeight2      = new TaiClampMaxHeightAction(NAPKIDSTATE_Unk13, params->getF(NAPKIDPF_Unk1));
	TaiContinuousMotionAction* continousMotion4   = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk5);

	// STATE 11 - (Unknown)
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, continousMotion4);
	state->setAction(j++, catchAscending);
	state->setAction(j++, acceleration);
	state->setAction(j++, clampMinHeight2);
	state->setAction(j++, clampMaxHeight2);
	state->setAction(j++, makingNextVel);
	setState(NAPKIDSTATE_Unk11, state);

	TaiNapkidWanderingRouteAction* wanderRoute2 = new TaiNapkidWanderingRouteAction(NAPKIDANIM_Unk5, params->getF(NAPKIDPF_Unk0));
	TaiTimerAction* timer2                      = new TaiTimerAction(NAPKIDSTATE_Unk14, 0, params->getF(NAPKIDPF_Unk11), 0.5f);

	// STATE 13 - (Unknown)
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, stickersOnBody1);
	state->setAction(j++, dead1);
	state->setAction(j++, timer2);
	state->setAction(j++, wanderRoute2);
	state->setAction(j++, napkidFlying2);
	setState(NAPKIDSTATE_Unk13, state);

	TaiContinuousMotionAction* continousMotion5 = new TaiContinuousMotionAction(NAPKIDSTATE_Unk13, NAPKIDANIM_Unk4);
	TaiNapkidThrowingPikiAction* throwPiki      = new TaiNapkidThrowingPikiAction;
	TaiNotAction* notStickersInMouth            = new TaiNotAction(NAPKIDSTATE_Unk1, new TaiHasStickersInMouthAction(TAI_NO_TRANSIT));

	// STATE 14 - (Unknown)
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, stickersOnBody1);
	state->setAction(j++, dead1);
	state->setAction(j++, continousMotion5);
	state->setAction(j++, throwPiki);
	state->setAction(j++, notStickersInMouth);
	setState(NAPKIDSTATE_Unk14, state);

	TaiMotionAction* motion3                  = new TaiMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk10);
	TaiNapkidFallingAction* napkidFalling     = new TaiNapkidFallingAction;
	TaiNapkidShockFallingAction* shockFalling = new TaiNapkidShockFallingAction;
	TaiRotatingAction* rotating1              = new TaiRotatingAction(NMathF::pi * 8.0f);
	TaiClampMinHeightAction* clampMinHeight3  = new TaiClampMinHeightAction(NAPKIDSTATE_Unk17, 10.0f);

	// STATE 15 - Falling?
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, shockFalling);
	state->setAction(j++, motion3);
	state->setAction(j++, napkidFalling);
	state->setAction(j++, rotating1);
	state->setAction(j++, parabola);
	state->setAction(j++, clampMinHeight3);
	state->setAction(j++, makingNextVel);
	setState(NAPKIDSTATE_Unk15, state);

	TaiRotatingAction* rotating2 = new TaiRotatingAction(NMathF::pi * 4.0f);

	// STATE 16 - ...Also falling?
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, motion3);
	state->setAction(j++, napkidFalling);
	state->setAction(j++, rotating2);
	state->setAction(j++, parabola);
	state->setAction(j++, clampMinHeight3);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, makingNextVel);
	setState(NAPKIDSTATE_Unk16, state);

	TaiFinishMotionAction* finishMotion2                  = new TaiFinishMotionAction(NAPKIDSTATE_Unk18);
	TaiNapkidFallingWaterEffectAction* fallingWaterEffect = new TaiNapkidFallingWaterEffectAction;

	// STATE 18 - Falling in water?
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, finishFlying);
	state->setAction(j++, simDamage);
	state->setAction(j++, finishMotion2);
	state->setAction(j++, fallingWaterEffect);
	setState(NAPKIDSTATE_Unk17, state);

	TaiContinuousMotionAction* continousMotion6 = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk11);

	TaiSerialAction* serial2      = new TaiSerialAction(NAPKIDSTATE_Unk19, 2);
	TaiCountLoopAction* countLoop = new TaiCountLoopAction(TAI_NO_TRANSIT, params->getI(NAPKIDPI_Unk0));
	serial2->setAction(0, countLoop);

	TaiFinishMotionAction* finishMotion3 = new TaiFinishMotionAction(TAI_NO_TRANSIT);
	serial2->setAction(1, finishMotion3);

	// STATE 18 - (Unknown)
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, dead2);
	state->setAction(j++, simDamage);
	state->setAction(j++, serial2);
	state->setAction(j++, continousMotion6);
	setState(NAPKIDSTATE_Unk18, state);

	TaiNapkidStartDroppingWaterAction* startDroppingWater = new TaiNapkidStartDroppingWaterAction;
	TaiNapkidTakingOffAscendingAction* takingOffAscend    = new TaiNapkidTakingOffAscendingAction;
	TaiClampMaxHeightAction* clampMaxHeight3              = new TaiClampMaxHeightAction(NAPKIDSTATE_Unk20, params->getF(NAPKIDPF_Unk2));
	TaiContinuousMotionAction* continousMotion7           = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk12);
	TaiClampMinVelocityYAction* clampMinYVel              = new TaiClampMinVelocityYAction(NAPKIDSTATE_Unk20, 0.0f);

	// STATE 19 - (Unknown)
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, startFlying);
	state->setAction(j++, simDamage);
	state->setAction(j++, takingOffAscend);
	state->setAction(j++, acceleration);
	state->setAction(j++, clampMinYVel);
	state->setAction(j++, clampMaxHeight3);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, continousMotion7);
	state->setAction(j++, startDroppingWater);
	setState(NAPKIDSTATE_Unk19, state);

	TaiNotAction* notStickersOnBody   = new TaiNotAction(NAPKIDSTATE_Unk22, new TaiHasStickersOnBodyAction(TAI_NO_TRANSIT));
	TaiNapkidFlickAction* napkidFlick = new TaiNapkidFlickAction(NAPKIDSTATE_Unk21);
	TaiOnceAction* once2              = new TaiOnceAction(NAPKIDSTATE_Unk16);
	TaiStopGenParticleGeneratorAction* stopParticleGen = new TaiStopGenParticleGeneratorAction(0);

	// STATE 20 - (Unknown)
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, stopParticleGen);
	state->setAction(j++, notStickersOnBody);
	state->setAction(j++, napkidFlick);
	state->setAction(j++, once2);
	setState(NAPKIDSTATE_Unk20, state);

	TaiFlickingUpperAction* flickUpper = new TaiFlickingUpperAction(NAPKIDSTATE_Unk22, NAPKIDANIM_Unk9);

	// STATE 21 - Flick?
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, flickUpper);
	setState(NAPKIDSTATE_Unk21, state);

	TaiNapkidRisingAscendingAction* napkidRisingAscending = new TaiNapkidRisingAscendingAction;
	TaiClampMaxHeightAction* clampMaxHeight4              = new TaiClampMaxHeightAction(NAPKIDSTATE_Unk1, params->getF(TPF_FlightHeight));
	TaiContinuousMotionAction* continousMotion8           = new TaiContinuousMotionAction(TAI_NO_TRANSIT, NAPKIDANIM_Unk6);

	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, stickersOnBody1);
	state->setAction(j++, dead1);
	state->setAction(j++, napkidRisingAscending);
	state->setAction(j++, acceleration);
	state->setAction(j++, clampMaxHeight4);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, continousMotion8);
	setState(NAPKIDSTATE_Unk22, state);
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

	Piki* piki = (Piki*)target;
	if (piki->isStickTo()) {
		return false;
	}

	if (!TekiVisibleCondition(mTeki).satisfy(target)) {
		return false;
	}

	if (piki->getState() == PIKISTATE_FallMeck) {
		return false;
	}

	TekiVisibleCondition(nullptr);
	return true;
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

	u32 bad[2];
	PRINT("fake", target ? "fake" : "fake");
	return false;
	TekiDistanceCondition(nullptr, 0.0f);
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
		PRINT("?TaiNapkidWanderingRouteAction::makeTargetPosition:%08x:wayPoint==null:%d/%d\n", &teki, teki.mCurrRouteWayPointID,
		      teki.mRouteWayPointCount);
		return;
	}

	int randomIndex = NSystem::randomInt(currWaypoint->mLinkCount - 1);
	PRINT("TaiNapkidWanderingRouteAction::makeTargetPosition::act:%08x,%d,%d,%d\n", &teki, teki.mCurrRouteWayPointID, randomIndex,
	      currWaypoint->mLinkCount);

	int j;
	int i = 0;
	for (j = 0; j < currWaypoint->mLinkCount; j++) {
		if (currWaypoint->mLinkIndices[j] >= 0) {
			if (i == randomIndex) {
				teki.mCurrRouteWayPointID = currWaypoint->mLinkIndices[j];
				break;
			}
			i++;
		}
	}

	PRINT("TaiNapkidWanderingRouteAction::makeTargetPosition::act:%08x:->%d\n", &teki, teki.mCurrRouteWayPointID);
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

	PRINT("fake", targetCreature ? "fake" : "fake");
	return false;

	TekiNapkidTargetPikiCondition(nullptr);
	TekiNapkidTargetPikiCondition(nullptr);
	TekiNapkidTargetPikiCondition(nullptr);
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

	PRINT("fake", targetCreature ? "fake" : "fake");
	return false;

	TekiNapkidShortRangeCondition(nullptr);
	TekiNapkidShortRangeCondition(nullptr);
	TekiNapkidShortRangeCondition(nullptr);
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

	u32 badCompiler[5];
	return false;
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
	teki._3A4 = -NMathF::pi / 4.0f * temp;

	if (teki.mCircleMoveEvent->isFinished()) {
		return true;
	}

	return false;

	u32 badCompiler[3];
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

	teki.mPositionIO.input(NVector3f(teki.getPosition()));

	NVector3f velocity;
	teki.outputDirectionVector(velocity);
	velocity.scale(160.0f);
	velocity.y = -240.0f;
	teki.mVelocityIO.input(velocity);

	NVector3f acceleration(0.0f, -320.0f, 0.0f);
	teki.mAccelerationIO.input(acceleration);

	teki.mAccelEvent->makeAccelerationEvent(nullptr, &teki.mPositionIO, &teki.mVelocityIO, &teki.mAccelerationIO);
	teki.mAccelEvent->reset();
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
	NVector3f unused = dir;
	unused.scale(160.0f);
	teki.mVelocityIO.input(velocity);

	return false;
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
}

/*
 * --INFO--
 * Address:	80139F88
 * Size:	0001D4
 */
bool TaiNapkidThrowingPikiAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(Teki::ANIMATION_KEY_OPTION_ACTION_0)) {
		PRINT("TaiNapkidThrowingPikiAction::act:%08x:ACTION_0\n", &teki);
		NVector3f throwVel(teki.getVelocity());
		throwVel.y = -teki.getParameterF(NAPKIDPF_Unk12);

		Stickers stickers(&teki);
		Iterator iter(&stickers);
		CI_LOOP(iter)
		{
			Creature* throwPiki = *iter;
			if (throwPiki != nullptr) {
				if (throwPiki->isStickToMouth()) {
					PRINT("TaiNapkidThrowingPikiAction::act:%08x:endStickObject\n", &teki);
					throwPiki->endStickMouth();

					throwPiki->stimulate(InteractThrowAway(&teki));

					throwPiki->mVelocity.set(throwVel);
					iter.dec();
					return false;
				}
			} else {
				PRINT("?TaiNapkidThrowingPikiAction::act:%08x:creature==null\n", &teki);
				break;
			}
		}
	}
	PRINT("!TaiNapkidThrowingPikiAction::act:%08x\n", &teki);

	PRINT("fake", &teki ? "fake" : "fake");
	return false;
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

	f32 linValues[2];
	NClampLinearFunction cLinearFunc(linValues);
	cLinearFunc.makeClampLinearFunction(1.0f, 0.1f, 5.0f, 0.7f);

	f32 flickChance = cLinearFunc.getValue(f32(stickCount));
	if (NMathF::occurred(flickChance)) {
		return false;
	}

	u32 bad[3];
	return true;
}

/*
 * --INFO--
 * Address:	8013A220
 * Size:	0001A8
 */
void TaiNapkidFallingAction::start(Teki& teki)
{
	PRINT("TaiNapkidFallingAction::start:%08x\n", &teki);
	teki.mPositionIO.input(NVector3f(teki.getPosition()));

	NVector3f fallVel(0.0f, -20.0f, 0.0f);
	teki.mParabolaEvent->makeParabolaEvent(nullptr, &teki.mPositionIO, fallVel, 1000.0f, teki.getGravity());
	teki.mParabolaEvent->reset();

	Stickers stickers(&teki);
	Iterator iter(&stickers);
	CI_LOOP(iter)
	{
		Creature* heldPiki = *iter;
		PRINT("TaiNapkidFallingAction::start:%08x:%08x\n", &teki, heldPiki);
		if (heldPiki == nullptr) {
			PRINT("???TaiNapkidFallingAction::start:%08x:creature==null:%08x\n", &teki, nullptr);
			return;
		}

		if (heldPiki != nullptr && heldPiki->isStickToMouth()) {
			PRINT("TaiNapkidFallingAction::start:%08x:endStickObject:%08x\n", &teki, heldPiki);
			heldPiki->endStickMouth();
			iter.dec();
		}
	}
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
