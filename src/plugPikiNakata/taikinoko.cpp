#include "TAI/Kinoko.h"

#include "DebugLog.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "TAI/EffectActions.h"
#include "TAI/JudgementActions.h"
#include "TAI/MoveActions.h"
#include "TAI/ReactionActions.h"
#include "TAI/TimerActions.h"
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
DEFINE_PRINT("taikinoko")

/**
 * @brief TODO
 */
struct TaiKinokoTurningOverAction : public TaiAction {
	TaiKinokoTurningOverAction()
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
struct TaiKinokoChargingSporesAction : public TaiAction {
	TaiKinokoChargingSporesAction()
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
struct TaiKinokoDischargingSporesAction : public TaiAction {
	TaiKinokoDischargingSporesAction()
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
struct TaiKinokoTerritoryRunningAwayAction : public TaiAction {
	TaiKinokoTerritoryRunningAwayAction()
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
struct TaiKinokoLegEffectAction : public TaiJointEffectAction {
	TaiKinokoLegEffectAction(f32);

	virtual void setType(Vector3f&, int, int); // _1C

	// _04     = VTBL
	// _00-_08 = TaiJointEffectAction?
	// TODO: members
};

/**
 * @todo: Documentation
 */
TaiKinokoSoundTable::TaiKinokoSoundTable()
    : PaniSoundTable(10)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_MUSH_WALK);
	}
}

/**
 * @todo: Documentation
 */
TaiKinokoParameters::TaiKinokoParameters()
    : TekiParameters(KINOKOPI_COUNT, KINOKOPF_COUNT)
{
	int j                           = TPI_COUNT;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	iParams[j++].init("TUNING_OVER_DAMAGE_COUNT", 0, 30);
	iParams[j++].init("FLICK_LOOP_COUNT", 0, 100);

	j                               = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("TURNING_AWAY_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("RUNNING_AWAY_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("FLICK_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("STANDING_UP_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("STANDING_DAMAGE_RATE", 0.0f, 1.0f);
	fParams[j++].init("NORMAL_EYE_SCALE", 0.0f, 10.0f);
	fParams[j++].init("ANGRY_EYE_SCALE", 0.0f, 10.0f);
	fParams[j++].init("WAITING_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("SLOW_TURN_VELOCITY", 0.0f, NMathF::pi);
	fParams[j++].init("GOING_HOME_TERRITORY_RANGE", 0.0f, 1000.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_CarcassSize, 0);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_FlickPikiCount1, 3);
	multiP->setI(TPI_FlickPikiCount2, 5);
	multiP->setI(TPI_FlickPikiCount3, 10);
	multiP->setI(TPI_FlickDamageCount1, 10);
	multiP->setI(TPI_FlickDamageCount2, 20);
	multiP->setI(TPI_FlickDamageCount3, 40);
	multiP->setI(TPI_FlickDamageCount4, 100);

	multiP->setF(TPF_Weight, 1000.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 2500.0f);
	multiP->setF(TPF_WalkVelocity, 40.0f);
	multiP->setF(TPF_RunVelocity, 80.0f);
	multiP->setF(TPF_TurnVelocity, NMathF::pi / 4.0f);
	multiP->setF(TPF_VisibleRange, 250.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 250.0f);
	multiP->setF(TPF_AttackableAngle, 5.0f);
	multiP->setF(TPF_AttackRange, 100.0f);
	multiP->setF(TPF_LowerRange, 130.0f);
	multiP->setF(TPF_AttackHitRange, 50.0f);
	multiP->setF(TPF_AttackPower, 0.0f);
	multiP->setF(TPF_LifeGaugeOffset, 30.0f);
	multiP->setF(TPF_ShadowSize, 50.0f);
	multiP->setF(TPF_RippleScale, 4.0f);
	multiP->setF(TPF_CorpseSize, 45.0f);
	multiP->setF(TPF_CorpseHeight, 20.0f);
	multiP->setF(TPF_SpawnHeight, 30.0f);
	multiP->setF(TPF_DangerTerritoryRange, 250.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 50.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.1f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 100.0f);
	multiP->setF(TPF_LowerFlickPower, 50.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_TraceAngle, 60.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 28.0f);

	multiP->setI(KINOKOPI_TurningOverDamageCount, 10);
	multiP->setI(KINOKOPI_FlickLoopCount, 20);

	multiP->setF(KINOKOPF_TurningAwayPeriod, 3.0f);
	multiP->setF(KINOKOPF_RunningAwayPeriod, 12.0f);
	multiP->setF(KINOKOPF_FlickPeriod, 10.0f);
	multiP->setF(KINOKOPF_StandingUpPeriod, 30.0f);
	multiP->setF(KINOKOPF_StandingDamageRate, 0.25f);
	multiP->setF(KINOKOPF_NormalEyeScale, 1.0f);
	multiP->setF(KINOKOPF_AngryEyeScale, 1.5f);
	multiP->setF(KINOKOPF_WaitingPeriod, 8.0f);
	multiP->setF(KINOKOPF_SlowTurnVelocity, NMathF::pi / 6.0f);
	multiP->setF(KINOKOPF_GoingHomeTerritoryRange, 100.0f);
}

/**
 * @todo: Documentation
 */
TaiKinokoStrategy::TaiKinokoStrategy(TekiParameters* params)
    : TaiStrategy(KINOKOSTATE_COUNT, KINOKOSTATE_Wait)
{
	TaiStopMoveAction* stopMoveAction                     = new TaiStopMoveAction();
	TaiStoppingMoveAction* stoppingMoveAction             = new TaiStoppingMoveAction(TekiMotion::Move1);
	TaiFinishStoppingMoveAction* finishStoppingMoveAction = new TaiFinishStoppingMoveAction();
	TaiDeadAction* deadAction1                            = new TaiDeadAction(KINOKOSTATE_DeadUpright);
	TaiDeadAction* deadAction2                            = new TaiDeadAction(KINOKOSTATE_DeadFlipped);
	TaiSimultaneousDamageAction* simDamageAction1         = new TaiSimultaneousDamageAction(TAI_NO_TRANSIT);
	TaiDamageScaleAction* damageScaleAction               = new TaiDamageScaleAction(params->getF(KINOKOPF_StandingDamageRate));
	TaiKinokoLegEffectAction* legEffectAction             = new TaiKinokoLegEffectAction(-0.5f);
	TaiDyingAction* dyingAction1                          = new TaiDyingAction(TekiMotion::Dead);
	TaiStartDyingAction* startDyingAction                 = new TaiStartDyingAction();

	// DEAD (UPRIGHT) STATE - die using animation 0
	TaiState* state = new TaiState(3);
	int j           = 0;
	state->setAction(j++, stopMoveAction);
	state->setAction(j++, startDyingAction);
	state->setAction(j++, dyingAction1);
	setState(KINOKOSTATE_DeadUpright, state);

	TaiDyingAction* dyingAction2 = new TaiDyingAction(TekiMotion::Damage);

	// DEAD (FLIPPED) STATE - die using animation 1
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, stopMoveAction);
	state->setAction(j++, startDyingAction);
	state->setAction(j++, dyingAction2);
	setState(KINOKOSTATE_DeadFlipped, state);

	TaiTargetVisibleNaviAction* targetVisNaviAction                = new TaiTargetVisibleNaviAction(KINOKOSTATE_TurningAway);
	TaiContinuousMotionAction* contMotionAction1                   = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Wait1);
	TaiCounterattackSimultaneousDamageAction* counterAttackAction1 = new TaiCounterattackSimultaneousDamageAction(KINOKOSTATE_TurningAway);
	TaiTimerAction* timerAction1 = new TaiTimerAction(TAI_NO_TRANSIT, 0, params->getF(KINOKOPF_WaitingPeriod), 0.4f);
	TaiOutsideTerritoryAction* outsideTerritoryAction
	    = new TaiOutsideTerritoryAction(TAI_NO_TRANSIT, params->getF(KINOKOPF_GoingHomeTerritoryRange));
	TaiAndAction* timerAndTerritory = new TaiAndAction(KINOKOSTATE_TurnToHome, timerAction1, outsideTerritoryAction);

	// WAIT STATE - chillin.
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, stoppingMoveAction);
	state->setAction(j++, deadAction1);          // if dead, transit to dead (standing)
	state->setAction(j++, damageScaleAction);    // 'standing' damage rate applies
	state->setAction(j++, counterAttackAction1); // if counter attack, transit to turning away
	state->setAction(j++, targetVisNaviAction);  // if visible navi, transit to turning away
	state->setAction(j++, timerAndTerritory);    // if wait timer elapses AND outside territory, transit to 10
	state->setAction(j++, contMotionAction1);
	setState(KINOKOSTATE_Wait, state);

	TaiTurningAwayAction* turningAwayAction
	    = new TaiTurningAwayAction(KINOKOSTATE_RunningAway, TekiMotion::WaitAct1, params->getF(TPF_TurnVelocity));
	TaiNotAction* notVisTargetAction = new TaiNotAction(KINOKOSTATE_RunningAway, new TaiVisibleTargetAction(TAI_NO_TRANSIT));
	TaiTimerAction* timerAction2     = new TaiTimerAction(KINOKOSTATE_RunningAway, 0, params->getF(KINOKOPF_TurningAwayPeriod), 0.0f);
	TaiCounterattackSimultaneousDamageAction* counterAttackAction2 = new TaiCounterattackSimultaneousDamageAction(KINOKOSTATE_RunningAway);

	// TURNING AWAY STATE - turning to LEG IT
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, stoppingMoveAction);
	state->setAction(j++, deadAction1);          // if dead, transit to dead (standing)
	state->setAction(j++, damageScaleAction);    // 'standing' damage rate applies
	state->setAction(j++, counterAttackAction2); // if counter attack, transit to 4
	state->setAction(j++, notVisTargetAction);   // if no visible target, transit to 4
	state->setAction(j++, timerAction2);         // if turning away timer elapses, transit to 4
	state->setAction(j++, turningAwayAction);    // when turning away action finishes, transit to 4
	state->setAction(j++, legEffectAction);
	setState(KINOKOSTATE_TurningAway, state);

	TaiTimerAction* timerAction3 = new TaiTimerAction(KINOKOSTATE_SporeAttackRun, 0, params->getF(KINOKOPF_RunningAwayPeriod), 0.0f);
	TaiRunningAwayToTargetDirectionAction* runningAwayAction
	    = new TaiRunningAwayToTargetDirectionAction(TAI_NO_TRANSIT, TekiMotion::Move1, params->getF(TPF_RunVelocity));
	TaiDamageCountAction* damageCountAction
	    = new TaiDamageCountAction(KINOKOSTATE_TurningOver, params->getI(KINOKOPI_TurningOverDamageCount));
	TaiDamageCountResetAction* damageCountReset                  = new TaiDamageCountResetAction();
	TaiKinokoTerritoryRunningAwayAction* kinokoRunningAwayAction = new TaiKinokoTerritoryRunningAwayAction();

	// RUNNING AWAY STATE - LEG IT
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, finishStoppingMoveAction);
	state->setAction(j++, kinokoRunningAwayAction);
	state->setAction(j++, runningAwayAction);
	state->setAction(j++, deadAction1);       // if dead, transit to dead (standing)
	state->setAction(j++, damageScaleAction); // 'standing' damage rate applies
	state->setAction(j++, simDamageAction1);
	state->setAction(j++, damageCountAction); // if damage counter gets high enough, TRIP AND FLIP
	state->setAction(j++, damageCountReset);
	state->setAction(j++, timerAction3); // if running away for too long, do spore attack
	state->setAction(j++, legEffectAction);
	setState(KINOKOSTATE_RunningAway, state);

	TaiKinokoTurningOverAction* turningOverAction = new TaiKinokoTurningOverAction();
	TaiMotionAction* motionAction1                = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Type1);
	TaiAnimationKeyAction* animKeyAction          = new TaiAnimationKeyAction(KINOKOSTATE_Flipped, BTeki::ANIMATION_KEY_OPTION_ACTION_0);

	// TURNING OVER STATE - we tripped, so now we need to flip
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, deadAction2);       // if dead, transit to dead (flipped)
	state->setAction(j++, damageScaleAction); // 'standing' damage rate still applies for now
	state->setAction(j++, simDamageAction1);
	state->setAction(j++, animKeyAction); // on Key Action 0, transit to 6
	state->setAction(j++, motionAction1);
	state->setAction(j++, turningOverAction);
	setState(KINOKOSTATE_TurningOver, state);

	TaiSimultaneousDamageAction* simDamageAction2 = new TaiSimultaneousDamageAction(KINOKOSTATE_Flick);
	TaiTimerAction* timerAction4 = new TaiTimerAction(KINOKOSTATE_SporeAttackFlip, 0, params->getF(KINOKOPF_FlickPeriod), 0.0f);

	// FLIPPED STATE - oops, we're upside down
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, deadAction2); // if dead, transit to dead (flipped)
	state->setAction(j++, stopMoveAction);
	state->setAction(j++, simDamageAction2); // if we're taking damage, flick pikmin off
	state->setAction(j++, timerAction4);     // if timer elapses, flip back upright and attack
	setState(KINOKOSTATE_Flipped, state);

	TaiTimerElapsedAction* timerElapsedAction = new TaiTimerElapsedAction(KINOKOSTATE_SporeAttackFlip, 0);

	// FLICK STATE - throw off pikmin before we flip back upright
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, deadAction2);
	state->setAction(j++, stopMoveAction);
	state->setAction(j++, simDamageAction2);
	state->setAction(j++, timerElapsedAction); // when timer's done, flip back upright and attack
	setState(KINOKOSTATE_Flick, state);

	TaiContinuousMotionAction* contMotionAction2      = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Flick);
	TaiKinokoDischargingSporesAction* dischargeAction = new TaiKinokoDischargingSporesAction();
	TaiKinokoChargingSporesAction* chargeAction       = new TaiKinokoChargingSporesAction();
	TaiSerialAction* serialAction1                    = new TaiSerialAction(KINOKOSTATE_Wait, 2);
	serialAction1->setAction(0, new TaiCountLoopAction(TAI_NO_TRANSIT, params->getI(KINOKOPI_FlickLoopCount)));
	serialAction1->setAction(1, new TaiFinishMotionAction(TAI_NO_TRANSIT));

	// SPORE ATTACK (AFTER FLIPPING) STATE - gas cloud after turning back upright
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, simDamageAction1);
	state->setAction(j++, chargeAction);
	state->setAction(j++, dischargeAction);
	state->setAction(j++, serialAction1); // when loop and motion are both done, transit to waiting
	state->setAction(j++, contMotionAction2);
	setState(KINOKOSTATE_SporeAttackFlip, state);

	TaiContinuousMotionAction* contMotionAction3 = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Type3);

	// SPORE ATTACK (AFTER RUNNING) STATE - gas cloud after running away for too long
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, stoppingMoveAction);
	state->setAction(j++, simDamageAction1);
	state->setAction(j++, chargeAction);
	state->setAction(j++, dischargeAction);
	state->setAction(j++, serialAction1); // when loop and motion are both done, transit to waiting
	state->setAction(j++, contMotionAction3);
	setState(KINOKOSTATE_SporeAttackRun, state);

	TaiSerialAction* serialAction2 = new TaiSerialAction(KINOKOSTATE_Wait, 2);
	serialAction2->setAction(0, new TaiFinishMotionAction(TAI_NO_TRANSIT));
	serialAction2->setAction(1, new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Type2));

	// UNUSED STATE - never gets transitioned to.
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, simDamageAction1);
	state->setAction(j++, serialAction2); // run a motion after the current one ends, then transit to waiting
	setState(KINOKOSTATE_UnusedMotion, state);

	TaiTurningToTargetPositionAction* turningToTargetPosAction
	    = new TaiTurningToTargetPositionAction(KINOKOSTATE_GoingHome, TekiMotion::WaitAct1, params->getF(KINOKOPF_SlowTurnVelocity));
	TaiTargetNestAction* targetNestAction = new TaiTargetNestAction();

	// TURN TO HOME STATE - we're too far from home, (slowly) turn back
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, deadAction1);       // if dead, transit to dead (upright)
	state->setAction(j++, damageScaleAction); // 'standing' damage rate applies
	state->setAction(j++, counterAttackAction1);
	state->setAction(j++, targetVisNaviAction); // if visible navi, transit to turning to run away
	state->setAction(j++, targetNestAction);
	state->setAction(j++, turningToTargetPosAction); // when done turning, transit to going home
	state->setAction(j++, legEffectAction);
	setState(KINOKOSTATE_TurnToHome, state);

	TaiGoingHomeAction* goingHomeAction = new TaiGoingHomeAction(TekiMotion::Move1, params->getF(TPF_WalkVelocity));
	TaiInsideTerritoryAction* insideTerritoryAction
	    = new TaiInsideTerritoryAction(KINOKOSTATE_Wait, params->getF(TPF_SafetyTerritoryRange));

	// GOING HOME STATE - go home.
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, finishStoppingMoveAction);
	state->setAction(j++, goingHomeAction);
	state->setAction(j++, deadAction1);
	state->setAction(j++, damageScaleAction); // 'standing' damage rate applies
	state->setAction(j++, counterAttackAction1);
	state->setAction(j++, targetVisNaviAction);   // if visible navi, transit to turning to run away
	state->setAction(j++, insideTerritoryAction); // once inside territory, transit to waiting
	state->setAction(j++, legEffectAction);
	setState(KINOKOSTATE_GoingHome, state);
}

/**
 * @todo: Documentation
 */
void TaiKinokoStrategy::start(Teki& teki)
{
	teki.mParticleGenerators[0] = effectMgr->create(EffectMgr::EFF_Kinoko_EyeGlow, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	teki.mParticleGenerators[1] = effectMgr->create(EffectMgr::EFF_Kinoko_EyeGlow, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	TaiStrategy::start(teki);
}

/**
 * @todo: Documentation
 */
void TaiKinokoStrategy::draw(Teki& teki, Graphics& gfx)
{
	TekiStrategy::draw(teki, gfx);
	if (!teki.mParticleGenerators[0]) {
		return;
	}

	if (!teki.getTekiOption(BTeki::TEKI_OPTION_DRAWED)) {
		teki.stopParticleGenerator(0);
		teki.stopParticleGenerator(1);
		return;
	}

	teki.startParticleGenerator(0);
	teki.startParticleGenerator(1);

	Matrix4f invCamMtx;
	gfx.mCamera->mLookAtMtx.inverse(&invCamMtx);

	NVector3f dir;
	teki.outputDirectionVector(dir);
	dir.scale(5.0f);

	NVector3f ptclPos;
	teki.outputWorldAnimationPosition(ptclPos, 22, invCamMtx);
	ptclPos.add(dir);
	teki.setParticleGeneratorPosition(0, ptclPos);

	teki.outputWorldAnimationPosition(ptclPos, 17, invCamMtx);
	ptclPos.add(dir);
	teki.setParticleGeneratorPosition(1, ptclPos);

	STACK_PAD_VAR(1);
}

/**
 * @todo: Documentation
 */
void TaiKinokoStrategy::createEffect(Teki& teki, int index)
{
	TekiStrategy::createEffect(teki, index);

	if (!effectMgr) {
		return;
	}

	NVector3f effectPos(teki.getPosition());
	if (index == 0) {
		effectMgr->create(EffectMgr::EFF_Kinoko_SporesUp, effectPos, nullptr, nullptr);
	} else if (index == 1) {
		effectMgr->create(EffectMgr::EFF_Kinoko_AttackSpores, effectPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Kinoko_AttackCloud, effectPos, nullptr, nullptr);

	} else if (index == 2) {
		effectMgr->create(EffectMgr::EFF_Kinoko_PostAttackSpores, effectPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Kinoko_PostAttackCloud, effectPos, nullptr, nullptr);

	} else if (index == 3) {
		effectMgr->create(EffectMgr::EFF_Kinoko_DeathSpores, effectPos, nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Kinoko_DeathSmoke, effectPos, nullptr, nullptr);
	}
}

/**
 * @todo: Documentation
 */
void TaiKinokoTurningOverAction::start(Teki& teki)
{
	Vector3f dir;
	teki.outputDirectionVector(dir);
	dir.scale(100.0f);
	teki.inputDrive(dir);
	teki.flickUpper();
}

/**
 * @todo: Documentation
 */
bool TaiKinokoChargingSporesAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_1)) {
		PRINT_NAKATA("TaiKinokoChargingSporesAction:act:%08x:ACTION_1:\n", &teki);
		NVector3f effectPos(teki.getPosition());
		effectMgr->create(EffectMgr::EFF_Kinoko_ChargeSpores, effectPos, nullptr, nullptr);
		STACK_PAD_VAR(1);
	}
	return false;
}

/**
 * @todo: Documentation
 */
void TaiKinokoDischargingSporesAction::start(Teki&)
{
}

/**
 * @todo: Documentation
 */
bool TaiKinokoDischargingSporesAction::act(Teki& teki)
{
	if (!teki.animationFinished()) {
		if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
			PRINT_NAKATA("TaiKinokoDischargingSporesAction:act:%08x:ACTION_0:\n", &teki);
			teki.flickUpper();
		} else if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_2)) {
			PRINT_NAKATA("TaiKinokoDischargingSporesAction:act:%08x:ACTION_2:\n", &teki);
			InteractSpore NRef spore = InteractSpore(&teki);
			TekiAndCondition andCond(&TekiRecognitionCondition(&teki), &TekiDistanceCondition(&teki, teki.getAttackRange()));
			teki.interactNaviPiki(spore, andCond);
			rumbleMgr->start(RUMBLE_Unk6, 0, teki.getPosition());
		}
	}
	return false;

	// sigh
	TekiAndCondition(nullptr, nullptr);
	TekiDistanceCondition(nullptr, 0.0f);
}

/**
 * @todo: Documentation
 */
bool TaiKinokoTerritoryRunningAwayAction::act(Teki& teki)
{
	f32 territoryDist = teki.getTerritoryDistance();
	if (territoryDist < teki.getParameterF(KINOKOPF_GoingHomeTerritoryRange)) {
		return false;
	}

	NVector3f homeDir;
	homeDir.sub2(teki.getPosition(), teki.getNestPosition());
	homeDir.normalizeCheck();

	NVector3f dir;
	teki.outputDirectionVector(dir);
	f32 dotDirHome = dir.dot(homeDir);

	if (dotDirHome <= 0.0f) {
		return false;
	}

	NVector3f yAxis(0.0f, 1.0f, 0.0f);
	NVector3f posOffset;
	posOffset.cross(homeDir, yAxis);
	NVector3f negOffset(posOffset);
	negOffset.negate();

	f32 dotDirOffset = posOffset.dot(dir);

	if (territoryDist > teki.getParameterF(TPF_DangerTerritoryRange)) {
		if (dotDirOffset >= 0.0f) {
			teki.mTargetAngle = BTeki::calcDirection(posOffset);
		} else {
			teki.mTargetAngle = BTeki::calcDirection(negOffset);
		}
		return false;
	}

	if (NMath<f32>::absolute(dotDirHome) <= NMathF::sqrt(2.0f) / 2.0f) {
		return false;
	}

	NVector3f pos;
	pos.add2(homeDir, posOffset);
	NVector3f neg;
	neg.add2(homeDir, negOffset);

	if (dotDirOffset >= 0.0f) {
		teki.mTargetAngle = BTeki::calcDirection(pos);
	} else {
		teki.mTargetAngle = BTeki::calcDirection(neg);
	}

	return false;
}

/**
 * @todo: Documentation
 */
TaiKinokoLegEffectAction::TaiKinokoLegEffectAction(f32 sinkThreshold)
    : TaiJointEffectAction(sinkThreshold, 2, 'lleg', 'rleg', 0, 0)
{
}

/**
 * @todo: Documentation
 */
void TaiKinokoLegEffectAction::setType(Vector3f& effectPos, int type, int id)
{
	ID32 unusedID;
	unusedID.setID(id);
	effectPos.y = mapMgr->getMinY(effectPos.x, effectPos.z, true);
	if (type == 5) {
		mEffectType = EffectMgr::EFF_P_Bubbles;
	} else if (type == -1) {
		mEffectType = EffectMgr::EFF_NULL;
	} else {
		mEffectType = EffectMgr::EFF_SmokeRing_S;
	}

	mSoundID = 67;
}
