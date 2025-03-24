#include "TAI/Mizinko.h"
#include "TAI/MoveActions.h"
#include "TAI/CollisionActions.h"
#include "TAI/BasicActions.h"
#include "TAI/ReactionActions.h"
#include "Peve/MotionEvents.h"
#include "MizuItem.h"
#include "teki.h"
#include "NaviMgr.h"
#include "SoundMgr.h"
#include "Graphics.h"
#include "DebugLog.h"
#include "sysNew.h"

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
DEFINE_PRINT("taimizinko")

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
	PRINT("TaiMizigenGeneratingAction::start:%08x\n", &teki);
	Teki* wisp = teki.generateTeki(teki.getParameterI(TPI_SpawnType));
	if (!wisp) {
		PRINT("TaiMizigenGeneratingAction::start:teki==null:%08x\n", &teki);
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
	PRINT("TaiMizigenGeneratingAction::start<%08x\n", &teki);
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

	PRINT("TaiMizigenNaviApprouchAction::act:%08x:%f,%f\n", &teki, naviDist, range);
	return true;
}

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
	TaiMotionAction* motionAction1             = new TaiMotionAction(TAI_NO_TRANSIT, 2);
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
	TaiDamagingAction* damagingAction                  = new TaiDamagingAction(MIZINKOSTATE_FlyingAway, 1);
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
	TaiMotionAction* motionAction2               = new TaiMotionAction(TAI_NO_TRANSIT, 0);

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

	u32 badCompiler;
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
		PRINT("TaiMizinkoCryTimerAction::act:%08x,%f\n", &teki, teki.mTimers[mTimerIdx]);
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

	PRINT("fake", &teki ? "yes" : "no", &teki ? "yes" : "no", &teki ? "yes" : "no");
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x1328
	  stw       r0, 0x4(r1)
	  subi      r6, r13, 0x1324
	  stwu      r1, -0x268(r1)
	  stfd      f31, 0x260(r1)
	  addi      r3, r1, 0x17C
	  stfd      f30, 0x258(r1)
	  stfd      f29, 0x250(r1)
	  stfd      f28, 0x248(r1)
	  stfd      f27, 0x240(r1)
	  stw       r31, 0x23C(r1)
	  addi      r31, r4, 0
	  subi      r4, r13, 0x132C
	  stw       r30, 0x238(r1)
	  bl        -0xFC334
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x17C
	  addi      r5, r1, 0x180
	  addi      r6, r1, 0x184
	  bl        -0xD5DD8
	  addi      r3, r1, 0x170
	  subi      r4, r13, 0x1338
	  subi      r5, r13, 0x1334
	  subi      r6, r13, 0x1330
	  bl        -0xFC35C
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x170
	  addi      r5, r1, 0x174
	  addi      r6, r1, 0x178
	  bl        -0xD5E00
	  mr        r3, r31
	  lwz       r4, -0x9D4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r0, -0x9C8(r13)
	  lwz       r12, 0x1CC(r12)
	  lwz       r5, -0x9A8(r13)
	  or        r0, r4, r0
	  lwz       r4, -0x9D0(r13)
	  mtlr      r12
	  or        r0, r5, r0
	  or        r4, r4, r0
	  blrl
	  lwz       r4, 0x2C8(r31)
	  addi      r3, r1, 0x208
	  addi      r4, r4, 0x10
	  bl        -0x1664C
	  lwz       r12, 0x358(r31)
	  addi      r3, r31, 0x358
	  lfs       f28, 0x388(r31)
	  addi      r4, r1, 0x208
	  lwz       r12, 0x8(r12)
	  lfs       f29, 0x38C(r31)
	  mtlr      r12
	  lfs       f30, 0x390(r31)
	  blrl
	  addi      r3, r1, 0x1F0
	  bl        -0x166A4
	  lfs       f0, 0x208(r1)
	  addi      r3, r1, 0x1F0
	  fsubs     f0, f28, f0
	  stfs      f0, 0x1F0(r1)
	  lfs       f0, 0x20C(r1)
	  fsubs     f0, f29, f0
	  stfs      f0, 0x1F4(r1)
	  lfs       f0, 0x210(r1)
	  fsubs     f0, f30, f0
	  stfs      f0, 0x1F8(r1)
	  bl        -0x1650C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x144
	  lfs       f29, 0xA0(r31)
	  fmr       f1, f29
	  bl        0xE861C
	  fmr       f28, f1
	  fmr       f1, f29
	  bl        0xE87A4
	  stfs      f1, 0x1F0(r1)
	  lfs       f0, -0x1320(r13)
	  stfs      f0, 0x1F4(r1)
	  stfs      f28, 0x1F8(r1)

	.loc_0x144:
	  lfs       f1, 0x1F0(r1)
	  lfs       f2, 0x1F8(r1)
	  bl        -0x15758
	  stfs      f1, 0xA0(r31)
	  li        r4, 0x3
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x110A4
	  lfs       f0, 0x1F0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1F0(r1)
	  lfs       f0, 0x1F4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1F4(r1)
	  lfs       f0, 0x1F8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1F8(r1)
	  lwz       r3, 0x2C4(r31)
	  lfs       f1, 0x20C(r1)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x74(r3)
	  lfs       f29, 0xE4(r3)
	  fadds     f28, f1, f0
	  bl        0xE4AB0
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x234(r1)
	  lis       r30, 0x4330
	  lwz       r3, 0x84(r3)
	  stw       r30, 0x230(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x5BC8(r2)
	  lfd       f0, 0x230(r1)
	  lwz       r3, 0x0(r3)
	  fsubs     f3, f0, f1
	  lfs       f1, -0x5BD4(r2)
	  lfs       f2, -0x5C08(r2)
	  lfs       f0, -0x5C0C(r2)
	  fdivs     f3, f3, f1
	  lfs       f1, -0x5BD0(r2)
	  lfs       f31, 0xEC(r3)
	  lfs       f30, 0xE8(r3)
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f28, f0
	  fmuls     f0, f29, f0
	  fadds     f29, f28, f0
	  bl        0xE4A4C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5BC8(r2)
	  stw       r0, 0x22C(r1)
	  lfs       f3, -0x5BD4(r2)
	  stw       r30, 0x228(r1)
	  lfs       f2, -0x5C08(r2)
	  lfd       f1, 0x228(r1)
	  lfs       f0, -0x5C0C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x5BD0(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f30, f0
	  fmuls     f0, f31, f0
	  fadds     f28, f30, f0
	  bl        0xE4A04
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x224(r1)
	  lwz       r3, 0x84(r3)
	  stw       r30, 0x220(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x5BC8(r2)
	  lfd       f0, 0x220(r1)
	  lwz       r3, 0x0(r3)
	  fsubs     f3, f0, f1
	  lfs       f2, -0x5BD4(r2)
	  lfs       f1, -0x5BD0(r2)
	  lfs       f0, -0x1CA4(r13)
	  fdivs     f4, f3, f2
	  lfs       f3, -0x5C08(r2)
	  lfs       f2, -0x5C10(r2)
	  lfs       f30, 0xF4(r3)
	  lfs       f31, 0xF0(r3)
	  fmuls     f0, f1, f0
	  fmuls     f1, f3, f4
	  fsubs     f0, f0, f2
	  fmuls     f0, f0, f1
	  fadds     f27, f2, f0
	  bl        0xE49A4
	  xoris     r0, r3, 0x8000
	  lfs       f0, 0x1F0(r1)
	  stw       r0, 0x21C(r1)
	  fmr       f1, f29
	  lfd       f6, -0x5BC8(r2)
	  fmr       f2, f28
	  stw       r30, 0x218(r1)
	  lfs       f4, -0x5BD4(r2)
	  lfd       f5, 0x218(r1)
	  fmr       f3, f27
	  stfs      f0, 0x1D8(r1)
	  addi      r6, r1, 0x1D8
	  fsubs     f6, f5, f6
	  lfs       f0, 0x1F4(r1)
	  lfs       f5, -0x5C08(r2)
	  addi      r5, r31, 0x358
	  fdivs     f6, f6, f4
	  stfs      f0, 0x1DC(r1)
	  li        r4, 0
	  lfs       f4, -0x5C0C(r2)
	  lfs       f0, 0x1F8(r1)
	  fmuls     f6, f5, f6
	  stfs      f0, 0x1E0(r1)
	  lfs       f5, -0x5BD0(r2)
	  lwz       r3, 0x468(r31)
	  fsubs     f0, f6, f4
	  fmuls     f0, f5, f0
	  fmuls     f0, f31, f0
	  fmuls     f0, f30, f0
	  fadds     f4, f31, f0
	  bl        -0xD550
	  lwz       r3, 0x468(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x468(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x1E4
	  bl        -0x16924
	  addi      r3, r31, 0x358
	  lwz       r12, 0x358(r31)
	  addi      r4, r1, 0x1E4
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x1E4(r1)
	  lwz       r0, 0x1E8(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x1EC(r1)
	  stw       r0, 0x9C(r31)
	  lwz       r0, 0x26C(r1)
	  lfd       f31, 0x260(r1)
	  lfd       f30, 0x258(r1)
	  lfd       f29, 0x250(r1)
	  lfd       f28, 0x248(r1)
	  lfd       f27, 0x240(r1)
	  lwz       r31, 0x23C(r1)
	  lwz       r30, 0x238(r1)
	  addi      r1, r1, 0x268
	  mtlr      r0
	  blr
	*/
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
	dir.sub2(targetPos, nestPos);

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

	PRINT("fake", &teki ? "yes" : "no", &teki ? "yes" : "no", &teki ? "yes" : "no");
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r5, r13, 0x1328
	  stw       r0, 0x4(r1)
	  subi      r6, r13, 0x1324
	  stwu      r1, -0x2B0(r1)
	  stfd      f31, 0x2A8(r1)
	  addi      r3, r1, 0x18C
	  stfd      f30, 0x2A0(r1)
	  stfd      f29, 0x298(r1)
	  stfd      f28, 0x290(r1)
	  stfd      f27, 0x288(r1)
	  stw       r31, 0x284(r1)
	  addi      r31, r4, 0
	  subi      r4, r13, 0x132C
	  stw       r30, 0x280(r1)
	  bl        -0xFC6F8
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x18C
	  addi      r5, r1, 0x190
	  addi      r6, r1, 0x194
	  bl        -0xD619C
	  addi      r3, r1, 0x180
	  subi      r4, r13, 0x1338
	  subi      r5, r13, 0x1334
	  subi      r6, r13, 0x1330
	  bl        -0xFC720
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x180
	  addi      r5, r1, 0x184
	  addi      r6, r1, 0x188
	  bl        -0xD61C4
	  mr        r3, r31
	  lwz       r4, -0x9D4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r0, -0x9C8(r13)
	  lwz       r12, 0x1CC(r12)
	  lwz       r5, -0x9A8(r13)
	  or        r0, r4, r0
	  lwz       r4, -0x9D0(r13)
	  mtlr      r12
	  or        r0, r5, r0
	  or        r4, r4, r0
	  blrl
	  lfs       f0, 0x388(r31)
	  addi      r3, r1, 0x248
	  stfs      f0, 0x254(r1)
	  lfs       f0, 0x38C(r31)
	  stfs      f0, 0x258(r1)
	  lfs       f0, 0x390(r31)
	  stfs      f0, 0x25C(r1)
	  lwz       r4, 0x2C8(r31)
	  addi      r4, r4, 0x10
	  bl        -0x16A28
	  addi      r3, r1, 0x23C
	  bl        -0x16A5C
	  lfs       f1, 0x248(r1)
	  addi      r3, r1, 0x230
	  lfs       f0, 0x254(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x23C(r1)
	  lfs       f1, 0x24C(r1)
	  lfs       f0, 0x258(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x240(r1)
	  lfs       f1, 0x250(r1)
	  lfs       f0, 0x25C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x244(r1)
	  bl        -0x16A94
	  lfs       f1, -0x5C10(r2)
	  addi      r3, r1, 0x20C
	  lfs       f2, -0x5C08(r2)
	  fmr       f3, f1
	  bl        -0x16A20
	  lfs       f0, 0x210(r1)
	  addi      r3, r1, 0x230
	  lfs       f2, 0x244(r1)
	  lfs       f3, 0x214(r1)
	  lfs       f1, 0x240(r1)
	  fmuls     f5, f0, f2
	  lfs       f6, 0x23C(r1)
	  fmuls     f4, f3, f1
	  lfs       f7, 0x20C(r1)
	  fmuls     f0, f0, f6
	  fmuls     f1, f7, f1
	  fsubs     f4, f5, f4
	  fmuls     f3, f3, f6
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0x230(r1)
	  fsubs     f1, f3, f2
	  stfs      f1, 0x234(r1)
	  stfs      f0, 0x238(r1)
	  bl        -0x16934
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x198
	  lfs       f1, -0x1310(r13)
	  lfs       f0, -0x130C(r13)
	  stfs      f1, 0x230(r1)
	  stfs      f0, 0x234(r1)
	  lfs       f0, -0x1308(r13)
	  stfs      f0, 0x238(r1)

	.loc_0x198:
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x33
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x114AC
	  lfs       f0, 0x230(r1)
	  addi      r3, r31, 0x358
	  addi      r4, r1, 0x254
	  fmuls     f0, f0, f1
	  stfs      f0, 0x230(r1)
	  lfs       f0, 0x234(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x234(r1)
	  lfs       f0, 0x238(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x238(r1)
	  lfs       f0, 0x254(r1)
	  lfs       f1, 0x230(r1)
	  fadds     f0, f0, f1
	  stfs      f0, 0x254(r1)
	  lfs       f0, 0x258(r1)
	  lfs       f2, 0x234(r1)
	  fadds     f0, f0, f2
	  stfs      f0, 0x258(r1)
	  lfs       f0, 0x25C(r1)
	  lfs       f3, 0x238(r1)
	  fadds     f0, f0, f3
	  stfs      f0, 0x25C(r1)
	  lfs       f0, 0x248(r1)
	  fadds     f0, f0, f1
	  stfs      f0, 0x248(r1)
	  lfs       f0, 0x24C(r1)
	  fadds     f0, f0, f2
	  stfs      f0, 0x24C(r1)
	  lfs       f0, 0x250(r1)
	  fadds     f0, f0, f3
	  stfs      f0, 0x250(r1)
	  lwz       r12, 0x358(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x224
	  bl        -0x16BC4
	  lfs       f1, 0x248(r1)
	  addi      r3, r1, 0x224
	  lfs       f0, 0x254(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x224(r1)
	  lfs       f1, 0x24C(r1)
	  lfs       f0, 0x258(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x228(r1)
	  lfs       f1, 0x250(r1)
	  lfs       f0, 0x25C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x22C(r1)
	  bl        -0x16A38
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x29C
	  lfs       f1, -0x1304(r13)
	  lfs       f0, -0x1300(r13)
	  stfs      f1, 0x224(r1)
	  stfs      f0, 0x228(r1)
	  lfs       f0, -0x12FC(r13)
	  stfs      f0, 0x22C(r1)

	.loc_0x29C:
	  lfs       f1, 0x224(r1)
	  lfs       f2, 0x22C(r1)
	  bl        -0x15C74
	  stfs      f1, 0xA0(r31)
	  li        r4, 0x3
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x115C0
	  lfs       f0, 0x224(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x224(r1)
	  lfs       f0, 0x228(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x228(r1)
	  lfs       f0, 0x22C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x22C(r1)
	  lwz       r3, 0x2C4(r31)
	  lfs       f1, 0x258(r1)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x74(r3)
	  lfs       f29, 0xE4(r3)
	  fadds     f28, f1, f0
	  bl        0xE4594
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x27C(r1)
	  lis       r30, 0x4330
	  lwz       r3, 0x84(r3)
	  stw       r30, 0x278(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x5BC8(r2)
	  lfd       f0, 0x278(r1)
	  lwz       r3, 0x0(r3)
	  fsubs     f3, f0, f1
	  lfs       f1, -0x5BD4(r2)
	  lfs       f2, -0x5C08(r2)
	  lfs       f0, -0x5C0C(r2)
	  fdivs     f3, f3, f1
	  lfs       f1, -0x5BD0(r2)
	  lfs       f31, 0xEC(r3)
	  lfs       f30, 0xE8(r3)
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f28, f0
	  fmuls     f0, f29, f0
	  fadds     f29, f28, f0
	  bl        0xE4530
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5BC8(r2)
	  stw       r0, 0x274(r1)
	  lfs       f3, -0x5BD4(r2)
	  stw       r30, 0x270(r1)
	  lfs       f2, -0x5C08(r2)
	  lfd       f1, 0x270(r1)
	  lfs       f0, -0x5C0C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x5BD0(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f30, f0
	  fmuls     f0, f31, f0
	  fadds     f28, f30, f0
	  bl        0xE44E8
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x26C(r1)
	  lwz       r3, 0x84(r3)
	  stw       r30, 0x268(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x5BC8(r2)
	  lfd       f0, 0x268(r1)
	  lwz       r3, 0x0(r3)
	  fsubs     f3, f0, f1
	  lfs       f2, -0x5BD4(r2)
	  lfs       f1, -0x5BD0(r2)
	  lfs       f0, -0x1CA4(r13)
	  fdivs     f4, f3, f2
	  lfs       f3, -0x5C08(r2)
	  lfs       f2, -0x5C10(r2)
	  lfs       f30, 0xF4(r3)
	  lfs       f31, 0xF0(r3)
	  fmuls     f0, f1, f0
	  fmuls     f1, f3, f4
	  fsubs     f0, f0, f2
	  fmuls     f0, f0, f1
	  fadds     f27, f2, f0
	  bl        0xE4488
	  xoris     r0, r3, 0x8000
	  lfs       f0, 0x224(r1)
	  stw       r0, 0x264(r1)
	  fmr       f1, f29
	  lfd       f6, -0x5BC8(r2)
	  fmr       f2, f28
	  stw       r30, 0x260(r1)
	  lfs       f4, -0x5BD4(r2)
	  lfd       f5, 0x260(r1)
	  fmr       f3, f27
	  stfs      f0, 0x200(r1)
	  addi      r6, r1, 0x200
	  fsubs     f6, f5, f6
	  lfs       f0, 0x228(r1)
	  lfs       f5, -0x5C08(r2)
	  addi      r5, r31, 0x358
	  fdivs     f6, f6, f4
	  stfs      f0, 0x204(r1)
	  li        r4, 0
	  lfs       f4, -0x5C0C(r2)
	  lfs       f0, 0x22C(r1)
	  fmuls     f6, f5, f6
	  stfs      f0, 0x208(r1)
	  lfs       f5, -0x5BD0(r2)
	  lwz       r3, 0x468(r31)
	  fsubs     f0, f6, f4
	  fmuls     f0, f5, f0
	  fmuls     f0, f31, f0
	  fmuls     f0, f30, f0
	  fadds     f4, f31, f0
	  bl        -0xDA6C
	  lwz       r3, 0x468(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x468(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x218
	  bl        -0x16E40
	  addi      r3, r31, 0x358
	  lwz       r12, 0x358(r31)
	  addi      r4, r1, 0x218
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x218(r1)
	  lwz       r0, 0x21C(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x220(r1)
	  stw       r0, 0x9C(r31)
	  lwz       r0, 0x2B4(r1)
	  lfd       f31, 0x2A8(r1)
	  lfd       f30, 0x2A0(r1)
	  lfd       f29, 0x298(r1)
	  lfd       f28, 0x290(r1)
	  lfd       f27, 0x288(r1)
	  lwz       r31, 0x284(r1)
	  lwz       r30, 0x280(r1)
	  addi      r1, r1, 0x2B0
	  mtlr      r0
	  blr
	*/
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
			PRINT("!TaiMizinkoDropWaterAction::act:%08x\n", this); // think this is a type and is meant to be &teki like the rest
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
