#include "TAI/Mizinko.h"

#include "DebugLog.h"
#include "Graphics.h"
#include "MizuItem.h"
#include "NaviMgr.h"
#include "Peve/MotionEvents.h"
#include "SoundMgr.h"
#include "TAI/BasicActions.h"
#include "TAI/CollisionActions.h"
#include "TAI/MoveActions.h"
#include "TAI/ReactionActions.h"
#include "TAI/TimerActions.h"
#include "sysNew.h"
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
DEFINE_PRINT("taimizinko")

/**
 * @brief TODO
 */
struct TaiMizigenGeneratingAction : public TaiAction {
	TaiMizigenGeneratingAction(int nextState)
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
struct TaiMizigenNaviApprouchAction : public TaiAction {
	TaiMizigenNaviApprouchAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/*
 * --INFO--
 * Address:	80131F64
 * Size:	0000B0
 */
TaiMizigenParameters::TaiMizigenParameters()
    : TekiParameters(TPI_COUNT, TPF_COUNT)
{
	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_SpawnType, TEKI_Qurione);
	multiP->setI(TPI_ModelType, 1);

	multiP->setF(TPF_DangerTerritoryRange, 50.0f);
	multiP->setF(TPF_AttackWaitPeriod, 10.0f);
	multiP->setF(TPF_SpawnDistance, 0.0f);
	multiP->setF(TPF_SpawnHeight, 0.0f);
	multiP->setF(TPF_SpawnVelocity, 0.0f);
}

/*
 * --INFO--
 * Address:	80132014
 * Size:	00017C
 */
TaiMizigenStrategy::TaiMizigenStrategy(TekiParameters* params)
    : TaiStrategy(MIZIGENSTATE_COUNT, MIZIGENSTATE_Wait)
{
	// unused timer
	TaiTimerAction* timerAction = new TaiTimerAction(MIZIGENSTATE_Generate, 0, params->getF(TPF_AttackWaitPeriod), 0.5f);

	TaiMizigenNaviApprouchAction* naviApproachAction = new TaiMizigenNaviApprouchAction(MIZIGENSTATE_Generate);

	TaiState* state = new TaiState(1);
	int j           = 0;
	state->setAction(j++, naviApproachAction); // when navi enter territory, transit to generate
	setState(MIZIGENSTATE_Wait, state);

	TaiMizigenGeneratingAction* genAction = new TaiMizigenGeneratingAction(MIZIGENSTATE_Wait);

	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, genAction); // when done generating, transit to wait
	setState(MIZIGENSTATE_Generate, state);
}

/*
 * --INFO--
 * Address:	80132190
 * Size:	00008C
 */
void TaiMizigenStrategy::start(Teki& teki)
{
	TaiStrategy::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_VISIBLE);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ORGANIC);
	teki.clearTekiOption(BTeki::TEKI_OPTION_SHADOW_VISIBLE);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
}

/*
 * --INFO--
 * Address:	8013221C
 * Size:	000164
 */
void TaiMizigenGeneratingAction::start(Teki& teki)
{
	PRINT_NAKATA("TaiMizigenGeneratingAction::start:%08x\n", &teki);
	Teki* wisp = teki.generateTeki(teki.getParameterI(TPI_SpawnType));
	if (!wisp) {
		PRINT_NAKATA("TaiMizigenGeneratingAction::start:teki==null:%08x\n", &teki);
		return;
	}

	teki.setPersonalityI(TekiPersonality::INT_Parameter0, 0);
	NVector3f dir;
	teki.outputDirectionVector(dir);
	f32 distance = teki.getPersonalityF(TekiPersonality::FLT_TerritoryRange);
	if (distance <= 0.0f) {
		PRINT("!TaiMizigenGeneratingAction::start:%08x:distance<=0:%f\n", &teki, distance);
		distance = 1.0f;
	}

	dir.scale(distance);
	wisp->mTargetPosition.add2(teki.getPosition(), dir);
	wisp->setPersonalityF(TekiPersonality::FLT_TerritoryRange, distance);
	wisp->startAI(0);
	PRINT_NAKATA("TaiMizigenGeneratingAction::start<%08x\n", &teki);
}

/*
 * --INFO--
 * Address:	80132380
 * Size:	000008
 */
bool TaiMizigenGeneratingAction::act(Teki& teki)
{
	return true;
}

/*
 * --INFO--
 * Address:	80132388
 * Size:	0000B8
 */
bool TaiMizigenNaviApprouchAction::act(Teki& teki)
{
	if (teki.getPersonalityI(TekiPersonality::INT_Parameter0) == 0) {
		return false;
	}

	NVector3f wispPos(teki.getPosition());
	Navi* navi   = naviMgr->getNavi(0);
	f32 naviDist = wispPos.distanceXZ(navi->getPosition());
	f32 range    = teki.getParameterF(TPF_DangerTerritoryRange);
	if (naviDist > range) {
		return false;
	}

	PRINT_NAKATA("TaiMizigenNaviApprouchAction::act:%08x:%f,%f\n", &teki, naviDist, range);
	return true;
}

/**
 * @brief TODO
 */
struct TaiMizinkoCryTimerAction : public TaiTimerAction {
	TaiMizinkoCryTimerAction(int p1, f32 p2, f32 p3)
	    : TaiTimerAction(TAI_NO_TRANSIT, p1, p2, p3)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiTimerAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiMizinkoMovingTimerAction : public TaiTimerAction {
	TaiMizinkoMovingTimerAction(int nextState)
	    : TaiTimerAction(nextState, 0, 0.0f, 0.0f)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_10 = TaiTimerAction
};

/**
 * @brief TODO
 */
struct TaiMizinkoFadingAction : public TaiAction {
	TaiMizinkoFadingAction()
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
struct TaiMizinkoGoingAction : public TaiAction {
	TaiMizinkoGoingAction()
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
struct TaiMizinkoComingAction : public TaiAction {
	TaiMizinkoComingAction()
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
struct TaiMizinkoDropWaterAction : public TaiAction {
	TaiMizinkoDropWaterAction()
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
struct TaiMizinkoWaitingAction : public TaiAction {
	TaiMizinkoWaitingAction()
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
struct TaiMizinkoFlyingAwayAction : public TaiAction {
	TaiMizinkoFlyingAwayAction()
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
 * Address:	80132440
 * Size:	000380
 */
TaiMizinkoParameters::TaiMizinkoParameters()
    : TekiParameters(TPI_COUNT, MIZINKOPF_COUNT)
{
	int j                           = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("DROP_DISTANCE", 0.0f, 50.0f);
	fParams[j++].init("PATH_DISTANCE", 0.0f, 100.0f);
	fParams[j++].init("FLYING_AWAY_VELOCITY", 0.0f, 1000.0f);
	fParams[j++].init("FLYING_AWAY_ACCELERATION", 0.0f, 1000.0f);
	fParams[j++].init("FADE_PERIOD", 0.0f, 30.0f);
	fParams[j++].init("HIDING_PERIOD", 0.0f, 60.0f);
	fParams[j++].init("HIDING_PERIOD_RANDOM_RATE", 0.0f, 1.0f);
	fParams[j++].init("FLIGHT_HEIGHT_RANDOM_RATE", 0.0f, 1.0f);
	fParams[j++].init("FLIGHT_AMPLITUDE", 0.0f, 100.0f);
	fParams[j++].init("FLIGHT_AMPLITUDE_RANDOM_RATE", 0.0f, 1.0f);
	fParams[j++].init("ANGULAR_VELOCITY", 0.0f, NMathF::pi);
	fParams[j++].init("ANGULAR_VELOCITY_RANDOM_RATE", 0.0f, 1.0f);
	fParams[j++].init("CRY_PERIOD", 0.0f, 60.0f);
	fParams[j++].init("CRY_PERIOD_RANDOM_RATE", 0.0f, 1.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_LightType, 1);

	multiP->setF(TPF_Weight, 1.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 1.0f);
	multiP->setF(TPF_WalkVelocity, 20.0f);
	multiP->setF(TPF_FlightHeight, 90.0f);
	multiP->setF(TPF_LifePeriod, 5.0f);
	multiP->setF(TPF_LifeGaugeOffset, 30.0f);
	multiP->setF(TPF_ShadowSize, 20.0f);
	multiP->setF(TPF_CorpseSize, 20.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);

	multiP->setF(MIZINKOPF_DropDistance, 10.0f);
	multiP->setF(MIZINKOPF_PathDistance, 40.0f);
	multiP->setF(MIZINKOPF_FlyingAwayVelocity, 200.0f);
	multiP->setF(MIZINKOPF_FlyingAwayAccel, 100.0f);
	multiP->setF(MIZINKOPF_FadePeriod, 1.0f);
	multiP->setF(MIZINKOPF_HidingPeriod, 5.0f);
	multiP->setF(MIZINKOPF_HidingPeriodRandomRate, 0.2f);
	multiP->setF(MIZINKOPF_FlightHeightRandomRate, 0.2f);
	multiP->setF(MIZINKOPF_FlightAmplitude, 30.0f);
	multiP->setF(MIZINKOPF_FlightAmplitudeRandomRate, 0.2f);
	multiP->setF(MIZINKOPF_AngularVelocity, NMathF::pi / 4.0f);
	multiP->setF(MIZINKOPF_AngularVelocityRandomRate, 0.3f);
	multiP->setF(MIZINKOPF_CryPeriod, 5.0f);
	multiP->setF(MIZINKOPF_CryPeriodRandomRate, 0.3f);
}

/*
 * --INFO--
 * Address:	801327C0
 * Size:	000084
 */
TaiMizinkoSoundTable::TaiMizinkoSoundTable()
    : PaniSoundTable(4)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_KURIONE_HIT);
	}
}

/*
 * --INFO--
 * Address:	80132844
 * Size:	0008B4
 */
TaiMizinkoStrategy::TaiMizinkoStrategy(TekiParameters* params)
    : TaiStrategy(MIZINKOSTATE_COUNT, MIZINKOSTATE_Going)
{
	TaiAccelerationAction* accelAction         = new TaiAccelerationAction();
	TaiHorizontalSinWaveAction* hSinWaveAction = new TaiHorizontalSinWaveAction();
	TaiMakingNextVelocityAction* nextVelAction = new TaiMakingNextVelocityAction();
	TaiMizinkoWaitingAction* waitingAction     = new TaiMizinkoWaitingAction();
	TaiMotionAction* motionAction1             = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Wait1);
	TaiMizinkoFadingAction* fadingAction       = new TaiMizinkoFadingAction();
	TaiPikiCollisionAction* pikiCollAction     = new TaiPikiCollisionAction(MIZINKOSTATE_DropWater);
	TaiDamageAction* damageAction              = new TaiDamageAction(MIZINKOSTATE_DropWater);
	TaiMizinkoCryTimerAction* cryTimerAction
	    = new TaiMizinkoCryTimerAction(1, params->getF(MIZINKOPF_CryPeriod), params->getF(MIZINKOPF_CryPeriodRandomRate));
	TaiMizinkoGoingAction* goingAction              = new TaiMizinkoGoingAction();
	TaiMizinkoMovingTimerAction* movingTimerAction1 = new TaiMizinkoMovingTimerAction(MIZINKOSTATE_HidingDest);

	// GOING STATE - travel from spawn pos to target pos
	TaiState* state = new TaiState(9);
	int j           = 0;
	state->setAction(j++, pikiCollAction); // if hit by piki, transit to drop water
	state->setAction(j++, damageAction);   // if takes damage, transit to drop water
	state->setAction(j++, motionAction1);
	state->setAction(j++, hSinWaveAction);
	state->setAction(j++, nextVelAction);
	state->setAction(j++, movingTimerAction1); // after timer elapses, transit to wait end
	state->setAction(j++, goingAction);
	state->setAction(j++, fadingAction);
	state->setAction(j++, cryTimerAction);
	setState(MIZINKOSTATE_Going, state);

	TaiTimerAction* timerAction1
	    = new TaiTimerAction(MIZINKOSTATE_Coming, 0, params->getF(MIZINKOPF_HidingPeriod), params->getF(MIZINKOPF_HidingPeriodRandomRate));

	// HIDING DEST STATE - hiding at target pos before returning
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, timerAction1); // after timer elapses, transit to coming
	state->setAction(j++, waitingAction);
	setState(MIZINKOSTATE_HidingDest, state);

	TaiMizinkoComingAction* comingAction            = new TaiMizinkoComingAction();
	TaiMizinkoMovingTimerAction* movingTimerAction2 = new TaiMizinkoMovingTimerAction(MIZINKOSTATE_HidingStart);

	// COMING STATE - returning from target pos to spawn pos
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, pikiCollAction); // if hit by piki, transit to drop water
	state->setAction(j++, damageAction);   // if takes damage, transit to drop water
	state->setAction(j++, motionAction1);
	state->setAction(j++, hSinWaveAction);
	state->setAction(j++, nextVelAction);
	state->setAction(j++, movingTimerAction2); // if timer elapses, transit to wait start
	state->setAction(j++, comingAction);
	state->setAction(j++, fadingAction);
	state->setAction(j++, cryTimerAction);
	setState(MIZINKOSTATE_Coming, state);

	TaiTimerAction* timerAction2
	    = new TaiTimerAction(MIZINKOSTATE_Going, 0, params->getF(MIZINKOPF_HidingPeriod), params->getF(MIZINKOPF_HidingPeriodRandomRate));

	// HIDING START STATE - hiding at spawn pos before travelling to target pos
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, timerAction2); // if timer elapses, transit to going
	state->setAction(j++, waitingAction);
	setState(MIZINKOSTATE_HidingStart, state);

	TaiTypeNaviWatchResultOnAction* naviWatchResAction = new TaiTypeNaviWatchResultOnAction();
	TaiDamagingAction* damagingAction                  = new TaiDamagingAction(MIZINKOSTATE_FlyingAway, TekiMotion::Damage);
	TaiMizinkoDropWaterAction* dropWaterAction         = new TaiMizinkoDropWaterAction();

	// DROP WATER STATE - has been hit, dropping nectar
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damagingAction); // when motion finishes, transit to flying away
	state->setAction(j++, dropWaterAction);
	state->setAction(j++, naviWatchResAction);
	setState(MIZINKOSTATE_DropWater, state);

	TaiTimerAction* timerAction3                 = new TaiTimerAction(MIZINKOSTATE_Dead, 0, params->getF(TPF_LifePeriod), 0.0f);
	TaiMizinkoFlyingAwayAction* flyingAwayAction = new TaiMizinkoFlyingAwayAction();
	TaiMotionAction* motionAction2               = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Dead);

	// FLYING AWAY STATE - has dropped nectar, disappearing
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, timerAction3); // when timer elapses, transit to dead
	state->setAction(j++, motionAction2);
	state->setAction(j++, accelAction);
	state->setAction(j++, nextVelAction);
	state->setAction(j++, flyingAwayAction);
	setState(MIZINKOSTATE_FlyingAway, state);

	TaiDyeAction* dyeAction = new TaiDyeAction();

	// DEAD STATE - nectar is dropped, wisp is done
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, dyeAction);
	setState(MIZINKOSTATE_Dead, state);
}

/*
 * --INFO--
 * Address:	801330F8
 * Size:	0000A8
 */
void TaiMizinkoStrategy::start(Teki& teki)
{
	teki.mParticleGenerators[0] = effectMgr->create(EffectMgr::EFF_Mizinko_Spawn, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	TaiStrategy::start(teki);
	teki.startFlying();
	teki.clearTekiOption(BTeki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
}

/*
 * --INFO--
 * Address:	801331A0
 * Size:	00010C
 */
void TaiMizinkoStrategy::draw(Teki& teki, Graphics& gfx)
{
	if (hasWater(teki)) { // amazing
		TekiStrategy::draw(teki, gfx);
	} else {
		TekiStrategy::draw(teki, gfx);
	}

	if (!teki.mParticleGenerators[0]) {
		return;
	}

	if (!teki.getTekiOption(BTeki::TEKI_OPTION_DRAWED)) {
		teki.stopParticleGenerator(0);
		return;
	}

	if (!hasWater(teki)) {
		teki.stopParticleGenerator(0);
		return;
	}

	teki.startParticleGenerator(0);
	Matrix4f invCamMtx;
	gfx.mCamera->mLookAtMtx.inverse(&invCamMtx);
	NVector3f worldPos;
	teki.outputWorldAnimationPosition(worldPos, 13, invCamMtx);
	teki.setParticleGeneratorPosition(0, worldPos);

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	801332AC
 * Size:	000014
 */
bool TaiMizinkoStrategy::hasWater(Teki& teki)
{
	return teki.getCreaturePointer(2) == nullptr;
}

/*
 * --INFO--
 * Address:	801332C0
 * Size:	00007C
 */
bool TaiMizinkoCryTimerAction::act(Teki& teki)
{
	if (teki.timerElapsed(mTimerIdx)) {
		PRINT_NAKATA("TaiMizinkoCryTimerAction::act:%08x,%f\n", &teki, teki.mTimers[mTimerIdx]);
		teki.playSound(SE_KURIONE_FLYING);
		resetTimer(teki);
	}
	return false;
}

/*
 * --INFO--
 * Address:	8013333C
 * Size:	000050
 */
void TaiMizinkoMovingTimerAction::start(Teki& teki)
{
	mTimerLength = teki.getPersonalityF(TekiPersonality::FLT_TerritoryRange) / teki.getParameterF(TPF_WalkVelocity);
	resetTimer(teki);
}

/*
 * --INFO--
 * Address:	8013338C
 * Size:	000088
 */
bool TaiMizinkoFadingAction::act(Teki& teki)
{
	f32 travelTime = teki.getPersonalityF(TekiPersonality::FLT_TerritoryRange) / teki.getParameterF(TPF_WalkVelocity);
	f32 timeLeft   = teki.mTimers[0];
	f32 fadePeriod = teki.getParameterF(MIZINKOPF_FadePeriod);

	if (travelTime - timeLeft < fadePeriod) {
		teki._3C0 = (travelTime - timeLeft) / fadePeriod;
	} else if (timeLeft < fadePeriod) {
		teki._3C0 = timeLeft / fadePeriod;
	} else {
		teki._3C0 = 1.0f;
	}

	teki.setPersonalityF(TekiPersonality::FLT_Size, teki._3C0);
	return false;
}

/*
 * --INFO--
 * Address:	80133414
 * Size:	0003C4
 */
void TaiMizinkoGoingAction::start(Teki& teki)
{
	// why.
	teki.stopMove();
	teki.setTekiOption(BTeki::TEKI_OPTION_VISIBLE | BTeki::TEKI_OPTION_ATARI | BTeki::TEKI_OPTION_SHAPE_VISIBLE
	                   | BTeki::TEKI_OPTION_SHADOW_VISIBLE);

	NVector3f nestPos(teki.getNestPosition());
	NVector3f targetPos(teki.mTargetPosition);
	teki.mPositionIO.input(nestPos);

	NVector3f dir;
	dir.sub2(targetPos, nestPos);
	if (!dir.normalizeCheck()) {
		PRINT("!TaiMizinkoGoingAction::start:%08x\n", &teki);
		teki.outputDirectionVector(dir);
	}

	teki.setDirection(teki.calcDirection(dir));
	dir.scale(teki.getParameterF(TPF_WalkVelocity));

	f32 offset = NMathF::rateRandom(teki.getParameterF(TPF_FlightHeight) + nestPos.y, teki.getParameterF(MIZINKOPF_FlightHeightRandomRate));
	f32 amp    = NMathF::rateRandom(teki.getParameterF(MIZINKOPF_FlightAmplitude), teki.getParameterF(MIZINKOPF_FlightAmplitudeRandomRate));
	f32 startTheta = NMathF::rangeRandom(0.0f, 2.0f * NMathF::pi);
	f32 angularVel
	    = NMathF::rateRandom(teki.getParameterF(MIZINKOPF_AngularVelocity), teki.getParameterF(MIZINKOPF_AngularVelocityRandomRate));
	teki.mSinWaveEvent->makeHorizontalSinWaveEvent(nullptr, &teki.mPositionIO, dir, offset, amp, startTheta, angularVel);
	teki.mSinWaveEvent->reset();
	teki.mSinWaveEvent->update();

	NVector3f pos;
	teki.mPositionIO.output(pos);
	teki.inputPosition(pos);
}

/*
 * --INFO--
 * Address:	801337D8
 * Size:	00051C
 */
void TaiMizinkoComingAction::start(Teki& teki)
{
	teki.stopMove();
	teki.setTekiOption(BTeki::TEKI_OPTION_VISIBLE | BTeki::TEKI_OPTION_ATARI | BTeki::TEKI_OPTION_SHAPE_VISIBLE
	                   | BTeki::TEKI_OPTION_SHADOW_VISIBLE);

	NVector3f targetPos(teki.mTargetPosition);
	NVector3f nestPos(teki.getNestPosition());
	NVector3f dir;
	dir.sub2(nestPos, targetPos);

	NVector3f ortho;
	ortho.cross(NVector3f(0.0f, 1.0f, 0.0f), dir);

	if (!ortho.normalizeCheck()) {
		PRINT("!TaiMizinkoComingAction::start:%08x\n", &teki);
		ortho.set(1.0f, 0.0f, 0.0f);
	}
	ortho.scale(teki.getParameterF(MIZINKOPF_PathDistance));
	targetPos.add(ortho);
	nestPos.add(ortho);

	teki.mPositionIO.input(targetPos);

	NVector3f dir2;
	dir2.sub2(nestPos, targetPos);
	if (!dir2.normalizeCheck()) {
		PRINT("!TaiMizinkoComingAction::start:%08x\n", &teki);
		dir2.set(1.0f, 0.0f, 0.0f);
	}

	teki.setDirection(teki.calcDirection(dir2));
	dir2.scale(teki.getParameterF(TPF_WalkVelocity));

	f32 offset
	    = NMathF::rateRandom(teki.getParameterF(TPF_FlightHeight) + targetPos.y, teki.getParameterF(MIZINKOPF_FlightHeightRandomRate));
	f32 amp = NMathF::rateRandom(teki.getParameterF(MIZINKOPF_FlightAmplitude), teki.getParameterF(MIZINKOPF_FlightAmplitudeRandomRate));
	f32 startTheta = NMathF::rangeRandom(0.0f, 2.0f * NMathF::pi);
	f32 angularVel
	    = NMathF::rateRandom(teki.getParameterF(MIZINKOPF_AngularVelocity), teki.getParameterF(MIZINKOPF_AngularVelocityRandomRate));
	teki.mSinWaveEvent->makeHorizontalSinWaveEvent(nullptr, &teki.mPositionIO, dir2, offset, amp, startTheta, angularVel);
	teki.mSinWaveEvent->reset();
	teki.mSinWaveEvent->update();

	NVector3f pos;
	teki.mPositionIO.output(pos);
	teki.inputPosition(pos);
}

/*
 * --INFO--
 * Address:	80133CF4
 * Size:	000104
 */
bool TaiMizinkoDropWaterAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		MizuItem* nectar = (MizuItem*)itemMgr->birth(OBJTYPE_FallWater);
		if (!nectar) {
			// I think this was a typo because it doesn't match the pattern other TAI Actions have.
			PRINT("!TaiMizinkoDropWaterAction::act:%08x\n", TERNARY_BUGFIX(&teki, this));
			return false;
		}

		Vector3f pos(teki.getPosition());
		f32 dropDist = teki.getParameterF(MIZINKOPF_DropDistance);
		pos.y -= dropDist;
		nectar->init(pos);
		nectar->startAI(0);
		teki.setCreaturePointer(2, nectar);
	}

	return false;
}

/*
 * --INFO--
 * Address:	80133DF8
 * Size:	0000A8
 */
void TaiMizinkoWaitingAction::start(Teki& teki)
{
	teki.stopMove();
	teki.clearTekiOption(BTeki::TEKI_OPTION_VISIBLE | BTeki::TEKI_OPTION_ATARI | BTeki::TEKI_OPTION_SHAPE_VISIBLE
	                     | BTeki::TEKI_OPTION_SHADOW_VISIBLE);
}

/*
 * --INFO--
 * Address:	80133EA0
 * Size:	000178
 */
void TaiMizinkoFlyingAwayAction::start(Teki& teki)
{
	teki.startFlying();
	teki.stopMove();
	teki.clearTekiOption(BTeki::TEKI_OPTION_VISIBLE | BTeki::TEKI_OPTION_ATARI);

	teki.mPositionIO.input(NVector3f(teki.getPosition()));
	NVector3f vel(0.0f, teki.getParameterF(MIZINKOPF_FlyingAwayVelocity), 0.0f);
	teki.mVelocityIO.input(vel);
	NVector3f accel(0.0f, teki.getParameterF(MIZINKOPF_FlyingAwayAccel), 0.0f);
	teki.mAccelerationIO.input(accel);

	teki.mAccelEvent->makeAccelerationEvent(nullptr, &teki.mPositionIO, &teki.mVelocityIO, &teki.mAccelerationIO);
	teki.mAccelEvent->reset();
}
