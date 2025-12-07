#include "TAI/Napkid.h"

#include "DebugLog.h"
#include "MapCode.h"
#include "Peve/MotionEvents.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "SoundID.h"
#include "Stickers.h"
#include "TAI/AttackActions.h"
#include "TAI/EffectActions.h"
#include "TAI/JudgementActions.h"
#include "TAI/MoveActions.h"
#include "TAI/ReactionActions.h"
#include "TAI/TimerActions.h"
#include "TekiConditions.h"
#include "nlib/Math.h"
#include "system.h"
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
DEFINE_PRINT("tainapkid")

/**
 * @brief TODO
 */
struct TaiNapkidWanderingRouteAction : public TaiContinuousMotionAction {
	inline TaiNapkidWanderingRouteAction(int motionIdx, f32 p2) // TODO: this is a guess
	    : TaiContinuousMotionAction(TAI_NO_TRANSIT, motionIdx)
	{
		_0C = p2;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void makeTargetPosition(Teki&);

	// _04     = VTBL
	// _00-_0C = TaiContinuousMotionAction
	f32 _0C;
};

/**
 * @brief TODO
 */
struct TaiNapkidTargetPikiAction : public TaiAction {
	inline TaiNapkidTargetPikiAction(int nextState) // TODO: this is a guess
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
struct TaiNapkidPikiLostAction : public TaiAction {
	inline TaiNapkidPikiLostAction(int nextState) // TODO: this is a guess
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
struct TaiNapkidShortRangeAction : public TaiAction {
	inline TaiNapkidShortRangeAction(int nextState) // TODO: this is a guess
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
struct TaiNapkidStraightFlyingAction : public TaiAction {
	inline TaiNapkidStraightFlyingAction(int nextState, f32 p2) // TODO: this is a guess
	    : TaiAction(nextState)
	{
		_08 = p2;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
	f32 _08;
};

/**
 * @brief TODO
 */
struct TaiNapkidCirclingAction : public TaiAction {
	inline TaiNapkidCirclingAction(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki&);  // _08
	virtual void finish(Teki&); // _0C
	virtual bool act(Teki&);    // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiNapkidFlyingAction : public TaiAction {
	inline TaiNapkidFlyingAction(f32 flightHeight) // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mFlightHeight = flightHeight;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
	f32 mFlightHeight;
};

/**
 * @brief TODO
 */
struct TaiNapkidAscendingAction : public TaiAction {
	inline TaiNapkidAscendingAction() // TODO: i believe this is unused
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
	f32 _08;
};

/**
 * @brief TODO
 */
struct TaiNapkidApproachPikiAction : public TaiAction {
	inline TaiNapkidApproachPikiAction(int nextState) // TODO: this is a guess
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
struct TaiNapkidCatchingAction : public TaiAction {
	inline TaiNapkidCatchingAction(int nextState) // TODO: this is a guess
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
struct TaiNapkidCatchDescendingAction : public TaiAction {
	inline TaiNapkidCatchDescendingAction() // TODO: this is a guess
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
struct TaiNapkidCatchTracingAction : public TaiAction {
	inline TaiNapkidCatchTracingAction() // TODO: this is a guess
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
struct TaiNapkidCatchFlyingAction : public TaiAction {
	inline TaiNapkidCatchFlyingAction() // TODO: this is a guess
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
struct TaiNapkidCatchAscendingAction : public TaiAction {
	inline TaiNapkidCatchAscendingAction() // TODO: this is a guess
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
struct TaiNapkidTakingOffAscendingAction : public TaiAction {
	inline TaiNapkidTakingOffAscendingAction() // TODO: this is a guess
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
struct TaiNapkidRisingAscendingAction : public TaiAction {
	inline TaiNapkidRisingAscendingAction() // TODO: this is a guess
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
struct TaiNapkidThrowingPikiAction : public TaiAction {
	inline TaiNapkidThrowingPikiAction() // TODO: this is a guess
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
struct TaiNapkidFlickAction : public TaiAction {
	inline TaiNapkidFlickAction(int nextState) // TODO: this is a guess
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
struct TaiNapkidFallingAction : public TaiAction {
	inline TaiNapkidFallingAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
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
struct TaiNapkidShockFallingAction : public TaiAction {
	inline TaiNapkidShockFallingAction() // TODO: this is a guess
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
struct TaiNapkidFallingWaterEffectAction : public TaiAction {
	inline TaiNapkidFallingWaterEffectAction() // TODO: this is a guess
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
struct TaiNapkidStartDroppingWaterAction : public TaiAction {
	inline TaiNapkidStartDroppingWaterAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

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
    : TekiParameters(TaiNapkidIntParms::COUNT, TaiNapkidFloatParms::COUNT)
{
	int i                           = TaiNapkidIntParms::StruggleLoopCount;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	iParams[i++].init("STRUGGLE_LOOP_COUNT", 0, 10);

	int j                           = TaiNapkidFloatParms::CarryingVelocity;
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

	multiP->setI(TaiNapkidIntParms::StruggleLoopCount, 1);

	multiP->setF(TaiNapkidFloatParms::CarryingVelocity, 90.0f);
	multiP->setF(TaiNapkidFloatParms::CarryFlightHeight, 60.0f);
	multiP->setF(TaiNapkidFloatParms::TakingOffFlightHeight, 60.0f);
	multiP->setF(TaiNapkidFloatParms::WanderingHoverPeriod, 3.0f);
	multiP->setF(TaiNapkidFloatParms::WanderingHoverProbability, 0.5f);
	multiP->setF(TaiNapkidFloatParms::HoveringWanderPeriod, 3.0f);
	multiP->setF(TaiNapkidFloatParms::HoveringWanderProbability, 0.5f);
	multiP->setF(TaiNapkidFloatParms::HoveringWashPeriod, 3.0f);
	multiP->setF(TaiNapkidFloatParms::HoveringWashProbability, 0.2f);
	multiP->setF(TaiNapkidFloatParms::WashingWanderPeriod, 3.0f);
	multiP->setF(TaiNapkidFloatParms::WashingWanderProbability, 0.7f);
	multiP->setF(TaiNapkidFloatParms::ThrowPeriod, 4.0f);
	multiP->setF(TaiNapkidFloatParms::ThrowVelocity, 200.0f);
}

/*
 * --INFO--
 * Address:	80136208
 * Size:	0022C4
 */
TaiNapkidStrategy::TaiNapkidStrategy(TekiParameters* params)
    : TaiStrategy(TaiNapkidStateID::COUNT, TaiNapkidStateID::Wandering)
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

	TaiHasStickersOnBodyAction* hasStickersToFall = new TaiHasStickersOnBodyAction(TaiNapkidStateID::ShockFalling);
	TaiDeadAction* midairDying                    = new TaiDeadAction(TaiNapkidStateID::ShockFalling);
	TaiDeadAction* groundedDying                  = new TaiDeadAction(TaiNapkidStateID::Dying);

	new TaiFlickAction(TaiNapkidStateID::Flicking); // never actually used

	TaiNapkidTargetPikiAction* targetPikiChase = new TaiNapkidTargetPikiAction(TaiNapkidStateID::Chasing);
	TaiSimultaneousDamageAction* simDamage     = new TaiSimultaneousDamageAction(TAI_NO_TRANSIT);
	TaiNapkidFlyingAction* napkidFlying1       = new TaiNapkidFlyingAction(params->getF(TPF_FlightHeight));
	TaiNapkidFlyingAction* napkidCarryFlying   = new TaiNapkidFlyingAction(params->getF(TaiNapkidFloatParms::CarryFlightHeight));

	TaiDyingAction* dying           = new TaiDyingAction(TekiMotion::Dead);
	TaiStartDyingAction* startDying = new TaiStartDyingAction;

	// STATE 0 - Dying
	TaiState* state = new TaiState(3);
	int j           = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, startDying);
	state->setAction(j++, dying);
	setState(TaiNapkidStateID::Dying, state);

	TaiNapkidWanderingRouteAction* flyWanderRoute = new TaiNapkidWanderingRouteAction(TekiMotion::Move1, params->getF(TPF_WalkVelocity));
	TaiStartingTimerAction* idleChanceTimer
	    = new TaiStartingTimerAction(TaiNapkidStateID::IdleFlying, 0, params->getF(TaiNapkidFloatParms::WanderingHoverPeriod), 0.5f,
	                                 params->getF(TaiNapkidFloatParms::WanderingHoverProbability));
	TaiHeadOnCollisionAvoidanceAction* headOnAvoidance = new TaiHeadOnCollisionAvoidanceAction(50.0f);

	// STATE 1 - Wandering routes
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, startFlying);
	state->setAction(j++, simDamage);
	state->setAction(j++, hasStickersToFall);
	state->setAction(j++, midairDying);
	state->setAction(j++, targetPikiChase);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, idleChanceTimer);
	state->setAction(j++, flyWanderRoute);
	state->setAction(j++, headOnAvoidance);
	setState(TaiNapkidStateID::Wandering, state);

	TaiContinuousMotionAction* flyMotion1 = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Move1);
	TaiStartingTimerAction* wanderChanceTimer1
	    = new TaiStartingTimerAction(TaiNapkidStateID::Wandering, 0, params->getF(TaiNapkidFloatParms::HoveringWanderPeriod), 0.5f,
	                                 params->getF(TaiNapkidFloatParms::HoveringWanderProbability));
	TaiStartingTimerAction* idleChatChanceTimer
	    = new TaiStartingTimerAction(TaiNapkidStateID::IdleChatting, 1, params->getF(TaiNapkidFloatParms::HoveringWashPeriod), 0.5f,
	                                 params->getF(TaiNapkidFloatParms::HoveringWashProbability));

	// STATE 2 - IdleFly (flying in place)
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, simDamage);
	state->setAction(j++, hasStickersToFall);
	state->setAction(j++, midairDying);
	state->setAction(j++, targetPikiChase);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, wanderChanceTimer1);
	state->setAction(j++, idleChatChanceTimer);
	state->setAction(j++, flyMotion1);
	setState(TaiNapkidStateID::IdleFlying, state);

	TaiStartingTimerAction* wanderChanceTimer2
	    = new TaiStartingTimerAction(TaiNapkidStateID::Wandering, 0, params->getF(TaiNapkidFloatParms::WashingWanderPeriod), 0.5f,
	                                 params->getF(TaiNapkidFloatParms::WashingWanderProbability));
	TaiContinuousMotionAction* idleMotion = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Wait1);

	// STATE 3 - IdleChatting (hands rubbing)
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, hasStickersToFall);
	state->setAction(j++, midairDying);
	state->setAction(j++, targetPikiChase);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, wanderChanceTimer2);
	state->setAction(j++, idleMotion);
	setState(TaiNapkidStateID::IdleChatting, state);

	TaiNapkidTargetPikiAction* targetPikiLoop = new TaiNapkidTargetPikiAction(TAI_NO_TRANSIT);
	TaiNapkidApproachPikiAction* approachPiki = new TaiNapkidApproachPikiAction(TaiNapkidStateID::AttackingSetup);
	TaiNapkidPikiLostAction* lostPiki         = new TaiNapkidPikiLostAction(TaiNapkidStateID::Wandering);
	TaiNapkidShortRangeAction* shortRange     = new TaiNapkidShortRangeAction(TaiNapkidStateID::Outrunning);
	TaiTracingAction* tracing                 = new TaiTracingAction(TekiMotion::Move1, params->getF(TPF_RunVelocity));

	// STATE 4 - Chasing target
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, hasStickersToFall);
	state->setAction(j++, midairDying);
	state->setAction(j++, approachPiki);
	state->setAction(j++, targetPikiLoop);
	state->setAction(j++, shortRange);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, lostPiki);
	state->setAction(j++, tracing);
	setState(TaiNapkidStateID::Chasing, state);

	TaiNapkidStraightFlyingAction* straightFlying = new TaiNapkidStraightFlyingAction(TaiNapkidStateID::Evading, 160.0f);
	TaiTimerAction* timeUntilEvade                = new TaiTimerAction(TaiNapkidStateID::Evading, 0, 5.0f, 0.0f);
	TaiContinuousMotionAction* flyMotion2         = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Move1);

	// STATE 5 - Outrunning target
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, hasStickersToFall);
	state->setAction(j++, midairDying);
	state->setAction(j++, approachPiki);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, straightFlying);
	state->setAction(j++, timeUntilEvade);
	state->setAction(j++, flyMotion2);
	setState(TaiNapkidStateID::Outrunning, state);

	TaiNapkidCirclingAction* circling       = new TaiNapkidCirclingAction(TaiNapkidStateID::Wandering);
	TaiMakingNextDriveAction* makeNextDrive = new TaiMakingNextDriveAction(150.0f);

	// STATE 6 - Evading / Circling (turning around after outrunning)
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, hasStickersToFall);
	state->setAction(j++, midairDying);
	state->setAction(j++, circleMove);
	state->setAction(j++, makeNextDrive);
	state->setAction(j++, circling);
	setState(TaiNapkidStateID::Evading, state);

	TaiFinishMotionAction* finishMotionToAttack = new TaiFinishMotionAction(TaiNapkidStateID::Attacking);

	// STATE 7 - AttackingSetup (finishing current animation before attacking)
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, hasStickersToFall);
	state->setAction(j++, midairDying);
	state->setAction(j++, napkidFlying1);
	state->setAction(j++, finishMotionToAttack);
	setState(TaiNapkidStateID::AttackingSetup, state);

	TaiNapkidCatchTracingAction* catchTracing       = new TaiNapkidCatchTracingAction;
	TaiNapkidCatchingAction* catching               = new TaiNapkidCatchingAction(TaiNapkidStateID::AttackDeciding);
	TaiMotionAction* attackMotion                   = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Attack);
	TaiNapkidCatchDescendingAction* catchDescending = new TaiNapkidCatchDescendingAction;
	TaiClampMinHeightAction* catchOnMinHeight       = new TaiClampMinHeightAction(TaiNapkidStateID::Catching, 10.0f);

	// STATE 8 - Attacking
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, catchDescending);
	state->setAction(j++, catchTracing);
	state->setAction(j++, acceleration);
	state->setAction(j++, catchOnMinHeight);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, attackMotion);
	state->setAction(j++, catching);
	state->setAction(j++, makeVelDir);
	setState(TaiNapkidStateID::Attacking, state);

	TaiNapkidCatchFlyingAction* catchFlying = new TaiNapkidCatchFlyingAction;
	TaiClampMinHeightAction* catchMinHeight = new TaiClampMinHeightAction(TAI_NO_TRANSIT, 10.0f);

	// State 9 - Catching pikmin
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, catchFlying);
	state->setAction(j++, catchTracing);
	state->setAction(j++, acceleration);
	state->setAction(j++, catchMinHeight);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, catching);
	state->setAction(j++, makeVelDir);
	setState(TaiNapkidStateID::Catching, state);

	TaiHasStickersInMouthAction* stickersInMouth = new TaiHasStickersInMouthAction(TaiNapkidStateID::CarryingSetup);
	TaiOnceAction* onceThenMiss                  = new TaiOnceAction(TaiNapkidStateID::AttackMissing);

	// STATE 10 - AttackDeciding (decides which state to go to next, after attacking)
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, acceleration);
	state->setAction(j++, catchMinHeight);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, stickersInMouth);
	state->setAction(j++, onceThenMiss);
	setState(TaiNapkidStateID::AttackDeciding, state);

	TaiNapkidCatchAscendingAction* ascending    = new TaiNapkidCatchAscendingAction;
	TaiClampMaxHeightAction* wanderOnMaxHeight1 = new TaiClampMaxHeightAction(TaiNapkidStateID::Wandering, params->getF(TPF_FlightHeight));
	TaiSerialAction* missingSerial              = new TaiSerialAction(TaiNapkidStateID::GettingUp, 2);
	missingSerial->setAction(0, new TaiSwitchMotionAction(TAI_NO_TRANSIT, TekiMotion::Type4));
	missingSerial->setAction(1, new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Move1));

	// STATE 12 - AttackMissing
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, acceleration);
	state->setAction(j++, catchMinHeight);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, missingSerial);
	state->setAction(j++, ascending);
	state->setAction(j++, wanderOnMaxHeight1);
	setState(TaiNapkidStateID::AttackMissing, state);

	TaiNapkidCatchAscendingAction* catchAscending = new TaiNapkidCatchAscendingAction;
	TaiClampMaxHeightAction* carryingOnMaxHeight
	    = new TaiClampMaxHeightAction(TaiNapkidStateID::Carrying, params->getF(TaiNapkidFloatParms::CarryFlightHeight));
	TaiContinuousMotionAction* carryFlyMotion = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::WaitAct2);

	// STATE 11 - CarryingSetup (setting up for Carrying after a max height is met)
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, carryFlyMotion);
	state->setAction(j++, catchAscending);
	state->setAction(j++, acceleration);
	state->setAction(j++, catchMinHeight);
	state->setAction(j++, carryingOnMaxHeight);
	state->setAction(j++, makingNextVel);
	setState(TaiNapkidStateID::CarryingSetup, state);

	TaiNapkidWanderingRouteAction* carryWanderRoute
	    = new TaiNapkidWanderingRouteAction(TekiMotion::WaitAct2, params->getF(TaiNapkidFloatParms::CarryingVelocity));
	TaiTimerAction* throwTimer = new TaiTimerAction(TaiNapkidStateID::Throwing, 0, params->getF(TaiNapkidFloatParms::ThrowPeriod), 0.5f);

	// STATE 13 - Carrying
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, hasStickersToFall);
	state->setAction(j++, midairDying);
	state->setAction(j++, throwTimer);
	state->setAction(j++, carryWanderRoute);
	state->setAction(j++, napkidCarryFlying);
	setState(TaiNapkidStateID::Carrying, state);

	TaiContinuousMotionAction* throwMotionThenCarrying = new TaiContinuousMotionAction(TaiNapkidStateID::Carrying, TekiMotion::WaitAct1);
	TaiNapkidThrowingPikiAction* throwPiki = new TaiNapkidThrowingPikiAction;
	TaiNotAction* noMouthStickersThenWander
	    = new TaiNotAction(TaiNapkidStateID::Wandering, new TaiHasStickersInMouthAction(TAI_NO_TRANSIT));

	// STATE 14 - Throwing pikmin
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, hasStickersToFall);
	state->setAction(j++, midairDying);
	state->setAction(j++, throwMotionThenCarrying);
	state->setAction(j++, throwPiki);
	state->setAction(j++, noMouthStickersThenWander);
	setState(TaiNapkidStateID::Throwing, state);

	TaiMotionAction* fallMotion                 = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Type1);
	TaiNapkidFallingAction* napkidFalling       = new TaiNapkidFallingAction;
	TaiNapkidShockFallingAction* shockFalling   = new TaiNapkidShockFallingAction;
	TaiRotatingAction* fallRotation             = new TaiRotatingAction(NMathF::pi * 8.0f);
	TaiClampMinHeightAction* minHeightToLanding = new TaiClampMinHeightAction(TaiNapkidStateID::Landing, 10.0f);

	// STATE 15 - ShockFalling (falling when a pikmin is first thrown on it)
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, shockFalling);
	state->setAction(j++, fallMotion);
	state->setAction(j++, napkidFalling);
	state->setAction(j++, fallRotation);
	state->setAction(j++, parabola);
	state->setAction(j++, minHeightToLanding);
	state->setAction(j++, makingNextVel);
	setState(TaiNapkidStateID::ShockFalling, state);

	TaiRotatingAction* slowFallRotation = new TaiRotatingAction(NMathF::pi * 4.0f);

	// STATE 16 - LoopFalling (falling when there are already pikmin on its body)
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, fallMotion);
	state->setAction(j++, napkidFalling);
	state->setAction(j++, slowFallRotation);
	state->setAction(j++, parabola);
	state->setAction(j++, minHeightToLanding);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, makingNextVel);
	setState(TaiNapkidStateID::LoopFalling, state);

	TaiFinishMotionAction* finishMotionToFlailing         = new TaiFinishMotionAction(TaiNapkidStateID::Struggling);
	TaiNapkidFallingWaterEffectAction* fallingWaterEffect = new TaiNapkidFallingWaterEffectAction;

	// STATE 18 - Landing (hitting the ground after falling)
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, finishFlying);
	state->setAction(j++, simDamage);
	state->setAction(j++, finishMotionToFlailing);
	state->setAction(j++, fallingWaterEffect);
	setState(TaiNapkidStateID::Landing, state);

	TaiContinuousMotionAction* flailMotion = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Type2);

	TaiSerialAction* flailSerialToGetup = new TaiSerialAction(TaiNapkidStateID::GettingUp, 2);
	TaiCountLoopAction* flailLoop       = new TaiCountLoopAction(TAI_NO_TRANSIT, params->getI(TaiNapkidIntParms::StruggleLoopCount));
	flailSerialToGetup->setAction(0, flailLoop);

	TaiFinishMotionAction* flailFinishMotion = new TaiFinishMotionAction(TAI_NO_TRANSIT);
	flailSerialToGetup->setAction(1, flailFinishMotion);

	// STATE 18 - Flailing on ground
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, groundedDying);
	state->setAction(j++, simDamage);
	state->setAction(j++, flailSerialToGetup);
	state->setAction(j++, flailMotion);
	setState(TaiNapkidStateID::Struggling, state);

	TaiNapkidStartDroppingWaterAction* startDroppingWater = new TaiNapkidStartDroppingWaterAction;
	TaiNapkidTakingOffAscendingAction* takingOffAscend    = new TaiNapkidTakingOffAscendingAction;
	TaiClampMaxHeightAction* maxHeightToDecide
	    = new TaiClampMaxHeightAction(TaiNapkidStateID::HeightDeciding, params->getF(TaiNapkidFloatParms::TakingOffFlightHeight));
	TaiContinuousMotionAction* ascendMotion     = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Type3);
	TaiClampMinVelocityYAction* minYVelToDecide = new TaiClampMinVelocityYAction(TaiNapkidStateID::HeightDeciding, 0.0f);

	// STATE 19 - GettingUp (getting up after landing)
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, startFlying);
	state->setAction(j++, simDamage);
	state->setAction(j++, takingOffAscend);
	state->setAction(j++, acceleration);
	state->setAction(j++, minYVelToDecide);
	state->setAction(j++, maxHeightToDecide);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, ascendMotion);
	state->setAction(j++, startDroppingWater);
	setState(TaiNapkidStateID::GettingUp, state);

	TaiNotAction* noStickersOnBody    = new TaiNotAction(TaiNapkidStateID::Rising, new TaiHasStickersOnBodyAction(TAI_NO_TRANSIT));
	TaiNapkidFlickAction* napkidFlick = new TaiNapkidFlickAction(TaiNapkidStateID::Flicking);
	TaiOnceAction* onceToLoopFall     = new TaiOnceAction(TaiNapkidStateID::LoopFalling);
	TaiStopGenParticleGeneratorAction* stopParticles = new TaiStopGenParticleGeneratorAction(0);

	// STATE 20 - HeightDeciding (deciding next state at the top of GettingUp's height)
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, stopParticles);
	state->setAction(j++, noStickersOnBody);
	state->setAction(j++, napkidFlick);
	state->setAction(j++, onceToLoopFall);
	setState(TaiNapkidStateID::HeightDeciding, state);

	TaiFlickingUpperAction* flickUpperToRising = new TaiFlickingUpperAction(TaiNapkidStateID::Rising, TekiMotion::Flick);

	// STATE 21 - Flicking
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, flickUpperToRising);
	setState(TaiNapkidStateID::Flicking, state);

	TaiNapkidRisingAscendingAction* napkidRisingAscending = new TaiNapkidRisingAscendingAction;
	TaiClampMaxHeightAction* wanderOnMaxHeight2 = new TaiClampMaxHeightAction(TaiNapkidStateID::Wandering, params->getF(TPF_FlightHeight));
	TaiContinuousMotionAction* flyMotion3       = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Move1);

	// STATE 22 - Rising (rising back to flying height)
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, simDamage);
	state->setAction(j++, hasStickersToFall);
	state->setAction(j++, midairDying);
	state->setAction(j++, napkidRisingAscending);
	state->setAction(j++, acceleration);
	state->setAction(j++, wanderOnMaxHeight2);
	state->setAction(j++, makingNextVel);
	state->setAction(j++, flyMotion3);
	setState(TaiNapkidStateID::Rising, state);
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

	if (teki.mTekiAnimator->getCurrentMotionIndex() == TekiMotion::Attack) {
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

	STACK_PAD_VAR(2);
	STACK_PAD_TERNARY(target, 1);
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
		PRINT("?TaiNapkidWanderingRouteAction::act:%08x:wayPoint==null:%d/%d\n", &teki, teki.mCurrRouteWayPointID,
		      teki.mRouteWayPointCount);
		makeTargetPosition(teki);
		return false;
	}

	if (teki.moveToward(currWaypoint->mPosition, _0C)) {
		PRINT_NAKATA("TaiNapkidWanderingRouteAction::act:%08x,%d/%d\n", &teki, teki.mCurrRouteWayPointID, teki.mRouteWayPointCount);
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
	PRINT_NAKATA("TaiNapkidWanderingRouteAction::makeTargetPosition::act:%08x,%d,%d,%d\n", &teki, teki.mCurrRouteWayPointID, randomIndex,
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

	PRINT_NAKATA("TaiNapkidWanderingRouteAction::makeTargetPosition::act:%08x:->%d\n", &teki, teki.mCurrRouteWayPointID);
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
		PRINT_NAKATA("TaiNapkidPikiLostAction::act:target==null:%08x\n", &teki);
		return true;
	}

	if (!TekiNapkidTargetPikiCondition(&teki).satisfy(targetCreature)) {
		PRINT_NAKATA("TaiNapkidPikiLostAction::act:!condition.satisfy:%08x\n", &teki);
		teki.clearCreaturePointer(0);
		return true;
	}

	STACK_PAD_TERNARY(targetCreature, 1);
	return false;

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
		PRINT_NAKATA("TaiNapkidShortRangeAction::act:target==null:%08x\n", &teki);
		return true;
	}

	if (TekiNapkidShortRangeCondition(&teki).satisfy(targetCreature)) {
		PRINT_NAKATA("TaiNapkidShortRangeAction::act:condition.satisfy:%08x\n", &teki);
		return true;
	}

	STACK_PAD_TERNARY(targetCreature, 1);
	return false;

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
		PRINT("!TaiNapkidStraightFlyingAction::act:target==null:%08x\n", &teki);
		return true;
	}

	NVector3f targetPosition(targetCreature->getPosition());
	if (targetPosition.distanceXZ(teki.getPosition()) >= _08) {
		return true;
	}

	STACK_PAD_VAR(1);
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
		PRINT("!TaiNapkidCirclingAction::start:target==null:%08x\n", &teki);
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
	cross.cross(NVector3f(0.0f, 1.0f, 0.0f), directionVec);
	bool check = false;
	if (cross.dot(sep) < 0.0f) {
		check = true;
	}

	f32 rad       = 50.0f;
	f32 timeLimit = rad * NMathF::pi / 150.0f;
	f32 angleInc  = NMathF::pi / timeLimit;

	cross.normalizeCheck();

	NVector3f normalized(cross);
	normalized.scale(rad);
	if (check) {
		normalized.negate();
		angleInc = -angleInc;
	}

	STACK_PAD_VAR(4);
	NVector3f targetVelocity;
	targetVelocity.add2(teki.getPosition(), normalized);
	teki.mVelocityIO.input(targetVelocity);

	teki.mPositionIO.input(NVector3f(teki.getPosition()));

	teki.mCircleMoveEvent->makeCircleMoveEvent(timeLimit, &teki.mPositionIO, &teki.mVelocityIO, 1.0f, rad, 0.0f, angleInc);
	teki.mCircleMoveEvent->reset();

	teki.mTargetAngle = teki.mCircleMoveEvent->mAngle;
	teki.setCreatureFlag(CF_Unk10);
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

	f32 angle = teki.mCircleMoveEvent->mAngle - teki.mTargetAngle;
	teki._3A4 = -NMathF::pi / 4.0f * NMathF::sin(angle);

	if (teki.mCircleMoveEvent->isFinished()) {
		PRINT_NAKATA("TaiNapkidCirclingAction::act:%08x\n", &teki);
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	80139260
 * Size:	000060
 */
bool TaiNapkidFlyingAction::act(Teki& teki)
{
	f32 seaLevel = teki.getSeaLevel();
	teki.getPosition().y += 0.15f * (mFlightHeight + seaLevel - teki.getPosition().y);
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
		PRINT_NAKATA("!TaiNapkidApproachPikiAction::act:target==null:%08x\n", &teki);
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
	if (counter < key) {
		return false;
	}

	if (counter > teki.mTekiAnimator->getKeyValueByKeyType(3)) {
		return true;
	}

	Vector3f direction;
	teki.outputDirectionVector(direction);
	direction.scale(teki.getParameterF(TPF_AttackRange));

	NVector3f offset;
	offset.add2(teki.getPosition(), direction);

	TekiAndCondition notStickerAndIsRecognizedCond(&TekiRecognitionCondition(&teki), &TekiNotCondition(&TekiStickerCondition(&teki)));
	TekiAndCondition posSphereDistAndOtherConds(&notStickerAndIsRecognizedCond,
	                                            &TekiPositionSphereDistanceCondition(offset, teki.getParameterF(TPF_AttackHitRange)));

	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki == nullptr) {
			PRINT("?TaiNapkidCatchingAction::act:%08x:creature==null\n", &teki);
			break;
		}

		if (posSphereDistAndOtherConds.satisfy(piki)) {
			CollPart* freeSlot = teki.getFreeSlot();
			if (freeSlot == nullptr) {
				break;
			}

			piki->stimulate(InteractSwallow(&teki, freeSlot, 0));
		}
	}

	return false;

	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiNotCondition(nullptr);
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
	int stickerCount = stickers.getNumStickers();

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
		PRINT_NAKATA("TaiNapkidThrowingPikiAction::act:%08x:ACTION_0\n", &teki);
		NVector3f throwVel(teki.getVelocity());
		throwVel.y = -teki.getParameterF(TaiNapkidFloatParms::ThrowVelocity);

		Stickers stickers(&teki);
		Iterator iter(&stickers);
		CI_LOOP(iter)
		{
			Creature* throwPiki = *iter;
			if (throwPiki != nullptr) {
				if (throwPiki->isStickToMouth()) {
					PRINT_NAKATA("TaiNapkidThrowingPikiAction::act:%08x:endStickObject\n", &teki);
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
	PRINT_NAKATA("!TaiNapkidThrowingPikiAction::act:%08x\n", &teki);

	STACK_PAD_TERNARY(&teki, 1);
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
	int stickCount = stickers.getNumStickers();

	f32 linValues[2];
	NClampLinearFunction cLinearFunc(linValues);
	cLinearFunc.makeClampLinearFunction(1.0f, 0.1f, 5.0f, 0.7f);

	f32 flickChance = cLinearFunc.getValue(f32(stickCount));
	PRINT_NAKATA("TaiNapkidFlickAction::act:%08x:%f\n", &teki, flickChance);
	if (NMathF::occurred(flickChance)) {
		return false;
	}

	STACK_PAD_VAR(2);
	return true;
}

/*
 * --INFO--
 * Address:	8013A220
 * Size:	0001A8
 */
void TaiNapkidFallingAction::start(Teki& teki)
{
	PRINT_NAKATA("TaiNapkidFallingAction::start:%08x\n", &teki);
	teki.mPositionIO.input(NVector3f(teki.getPosition()));

	NVector3f fallVel(0.0f, -20.0f, 0.0f);
	teki.mParabolaEvent->makeParabolaEvent(nullptr, &teki.mPositionIO, fallVel, 1000.0f, teki.getGravity());
	teki.mParabolaEvent->reset();

	Stickers stickers(&teki);
	Iterator iter(&stickers);
	CI_LOOP(iter)
	{
		Creature* heldPiki = *iter;
		PRINT_NAKATA("TaiNapkidFallingAction::start:%08x:%08x\n", &teki, heldPiki);
		if (heldPiki == nullptr) {
			PRINT("???TaiNapkidFallingAction::start:%08x:creature==null:%08x\n", &teki, nullptr);
			return;
		}

		if (heldPiki != nullptr && heldPiki->isStickToMouth()) {
			PRINT_NAKATA("TaiNapkidFallingAction::start:%08x:endStickObject:%08x\n", &teki, heldPiki);
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
	PRINT_NAKATA("TaiNapkidFallingWaterEffectAction::start:%08x:mapCode:%d\n", &teki, mapCode);

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
}

/*
 * --INFO--
 * Address:	8013A4BC
 * Size:	000044
 */
void TaiNapkidStartDroppingWaterAction::start(Teki& teki)
{
	int mapCode = teki.getPositionMapCode();
	PRINT_NAKATA("TaiNapkidStartDroppingWaterAction::start:%08x:mapCode:%d\n", &teki, mapCode);

	if (mapCode == ATTR_Water) {
		teki.startParticleGenerator(0);
	}
}
