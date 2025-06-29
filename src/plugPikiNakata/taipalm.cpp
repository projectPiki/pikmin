#include "TAI/Palm.h"
#include "TAI/TimerActions.h"
#include "teki.h"
#include "TekiConditions.h"
#include "Pellet.h"
#include "MapMgr.h"
#include "DayMgr.h"
#include "SoundMgr.h"
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
 * Size:	0000F0
 */
DEFINE_PRINT("taipalm")

/*
 * --INFO--
 * Address:	8013DAB4
 * Size:	000084
 */
TaiPalmSoundTable::TaiPalmSoundTable()
    : PaniSoundTable(5)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_FLOWER_DOWN);
	}
}

/*
 * --INFO--
 * Address:	8013DB38
 * Size:	0001F4
 */
TaiPalmParameters::TaiPalmParameters()
    : TekiParameters(TPI_COUNT, PALMPF_COUNT)
{
	STACK_PAD_VAR(1);

	int j                           = TPF_COUNT;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("CHANGING_COLOR_PERIOD", 0.0f, 3600.0f);
	fParams[j++].init("CHANGING_COLOR_PERIOD_RANDOM_RATE", 0.0f, 1.0f);
	fParams[j++].init("GROWING_PERIOD", 0.0f, 3600.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CullingType, CULLAI_CullAIOffCamera);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_AnimationType, 1);
	multiP->setI(TPI_SpawnPelletScaleOff, TRUE);

	multiP->setF(TPF_Life, 50.0f);
	multiP->setF(TPF_Life, 1.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, -1.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_LifeGaugeOffset, 100.0f);
	multiP->setF(TPF_ShadowSize, 25.0f);
	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 200.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 16.0f);
	multiP->setF(PALMPF_ChangingColorPeriod, 2.0f);
	multiP->setF(PALMPF_ChangingColorPeriodRandomRate, 0.0f);
	multiP->setF(PALMPF_GrowingPeriod, 1.0f);
}

/*
 * --INFO--
 * Address:	8013DD2C
 * Size:	0004F0
 */
TaiPalmStrategy::TaiPalmStrategy(TekiParameters* params)
    : TaiStrategy(PALMSTATE_COUNT, PALMSTATE_Normal)
{
	TaiDeadAction* deadAction                     = new TaiDeadAction(PALMSTATE_Dead);
	TaiDamageAction* damageAction                 = new TaiDamageAction(PALMSTATE_Damage);
	TaiPalmFlowerDamageAction* flowerDamageAction = new TaiPalmFlowerDamageAction(PALMSTATE_Dead);
	TaiPalmChangingColorAction* changingColorAction
	    = new TaiPalmChangingColorAction(1, params->getF(PALMPF_ChangingColorPeriod), params->getF(PALMPF_ChangingColorPeriodRandomRate));
	TaiPalmSettingPelletAction* settingPelletAction = new TaiPalmSettingPelletAction();
	TaiPalmDyingAction* dyingAction                 = new TaiPalmDyingAction(0);

	// DEAD STATE - dead.
	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, settingPelletAction);
	state->setAction(j++, dyingAction);
	setState(PALMSTATE_Dead, state);

	TaiPalmDamagingAction* damagingAction = new TaiPalmDamagingAction(PALMSTATE_Normal, 1);

	// DAMAGE STATE - taking damage (and screaming about it)
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, deadAction);         // if dead, transit to dead
	state->setAction(j++, flowerDamageAction); // if hit directly on flower, transit to dead
	state->setAction(j++, damagingAction);     // when damaging motion complete, transit to normal state
	state->setAction(j++, changingColorAction);
	setState(PALMSTATE_Damage, state);

	TaiPalmMotionAction* motionAction1  = new TaiPalmMotionAction(PALMSTATE_Normal, 4);
	TaiPalmGrowingAction* growingAction = new TaiPalmGrowingAction();
	TaiTimerAction* timerAction         = new TaiTimerAction(TAI_NO_TRANSIT, 0, params->getF(PALMPF_GrowingPeriod), 0.0f);

	// GROW STATE - growing to new stage
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, motionAction1); // when motion complete, transit to normal state
	state->setAction(j++, growingAction);
	state->setAction(j++, timerAction);
	setState(PALMSTATE_Grow, state);

	TaiPalmGrowAction* growAction      = new TaiPalmGrowAction(PALMSTATE_Grow, 0);
	TaiPalmMotionAction* motionAction2 = new TaiPalmMotionAction(TAI_NO_TRANSIT, 2);

	// NORMAL STATE - straight chillin
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, deadAction);         // if dead, transit to dead
	state->setAction(j++, flowerDamageAction); // if hit directly on flower, transit to dead
	state->setAction(j++, damageAction);       // if taking damage, transit to damage
	state->setAction(j++, motionAction2);
	state->setAction(j++, changingColorAction);
	state->setAction(j++, growAction); // if time to grow, transit to grow
	setState(PALMSTATE_Normal, state);
}

/*
 * --INFO--
 * Address:	8013E21C
 * Size:	0002B4
 */
void TaiPalmStrategy::start(Teki& teki)
{
	TaiStrategy::start(teki);
	if (teki.getPersonalityI(TekiPersonality::INT_Parameter0) == 1) {
		teki._3BC = teki.mPersonality->mPelletColor;
	} else {
		teki._3BC = NMathI::rangeRandom(PELCOLOR_MIN, PELCOLOUR_MAX);
	}

	teki.mTimers[0] = teki.getParameterF(PALMPF_GrowingPeriod);
	f32 dir         = NMathF::d2r(teki.getPersonalityF(TekiPersonality::FLT_TerritoryRange));
	teki.setDirection(dir);

	f32 rad = 2.0f * teki.getParameterF(TPF_CollisionRadius);

	TekiAndCondition& cond = TekiAndCondition(&TekiNotCondition(&TekiCreaturePointerCondition(&teki)),
	                                          &TekiAndCondition(&TekiTypeCondition(teki.mTekiType), &TekiDistanceCondition(&teki, rad)));
	Creature* neighbor     = tekiMgr->findClosest(teki.getPosition(), &cond);
	PRINT("TaiPalmStrategy::start:%08x:neighbor:%08x\n", &teki, neighbor);

	if (neighbor) {
		PRINT("TaiPalmStrategy::start:%08x:neighbor!=null:%08x\n", &teki, neighbor);
		NVector3f::printlnVector3f(teki.getPosition());
		NVector3f vec1;
		vec1.sub(teki.getPosition(), neighbor->getPosition());
		vec1.y = 0.0f;
		if (!vec1.normalizeCheck()) {
			vec1.set(0.0f, 0.0f, 1.0f);
		}

		vec1.scale(rad);
		vec1.add(neighbor->getPosition());
		vec1.y = mapMgr->getMinY(vec1.x, vec1.z, true);

		teki.inputPosition(vec1);

		NVector3f::printlnVector3f(teki.getPosition());
	}

	teki.mTargetPosition.input(teki.getPosition());

	// what did you DO nakata.
	TekiNotCondition(nullptr); // why
	TekiDistanceCondition(&teki, rad);
}

/*
 * --INFO--
 * Address:	8013E4D0
 * Size:	000038
 */
void TaiPalmStrategy::draw(Teki& teki, Graphics& gfx)
{
	teki.inputPosition(teki.mTargetPosition);
	TekiStrategy::draw(teki, gfx);
}

/*
 * --INFO--
 * Address:	8013E508
 * Size:	000148
 */
void TaiPalmStrategy::createEffect(Teki& teki, int palmEffectID)
{
	PRINT("TaiPalmStrategy::createEffect:%08x:%d\n", &teki, palmEffectID);
	TekiStrategy::createEffect(teki, palmEffectID);
	if (!effectMgr) {
		return;
	}

	NVector3f pos(teki.getPosition());
	zen::particleGenerator* ptclGen = nullptr;
	if (palmEffectID == 0) {
		ptclGen = effectMgr->create(EffectMgr::EFF_GrowPellet_A1, pos, nullptr, nullptr);
	} else if (palmEffectID == 1) {
		ptclGen = effectMgr->create(EffectMgr::EFF_GrowPellet_A2, pos, nullptr, nullptr);
	} else if (palmEffectID == 2) {
		effectMgr->create(EffectMgr::EFF_GrowPellet_B, pos, nullptr, nullptr);
		ptclGen = effectMgr->create(EffectMgr::EFF_GrowPellet_C, pos, nullptr, nullptr);
	}

	if (ptclGen) {
		NVector3f dir;
		teki.outputDirectionVector(dir);
		ptclGen->setEmitDir(dir);
	}
}

/*
 * --INFO--
 * Address:	8013E650
 * Size:	000100
 */
int TaiPalmStrategy::translateMotionIndex(Teki& teki, int palmMotionIdx)
{
	int size = teki.getPersonalityF(TekiPersonality::FLT_Strength);

	if (size == 0) {
		if (palmMotionIdx == 0) {
			return 0;
		}
		if (palmMotionIdx == 1) {
			return 1;
		}
		if (palmMotionIdx == 2) {
			return 2;
		}
		if (palmMotionIdx == 4) {
			return 9;
		}
	} else if (size == 1) {
		if (palmMotionIdx == 0) {
			return 3;
		}
		if (palmMotionIdx == 1) {
			return 4;
		}
		if (palmMotionIdx == 2) {
			return 5;
		}
		if (palmMotionIdx == 4) {
			return 10;
		}
	} else if (size == 2) {
		if (palmMotionIdx == 0) {
			return 6;
		}
		if (palmMotionIdx == 1) {
			return 7;
		}
		if (palmMotionIdx == 2) {
			return 8;
		}
	}

	PRINT("!TaiPalmStrategy::start:%08x:%d,%d\n", &teki, size, palmMotionIdx);
	return 0;
}

/*
 * --INFO--
 * Address:	8013E750
 * Size:	000064
 */
void TaiPalmMotionAction::start(Teki& teki)
{
	TaiPalmStrategy* strat = (TaiPalmStrategy*)teki.getStrategy();
	int motionIdx          = strat->translateMotionIndex(teki, mMotionIdx);
	teki.startMotion(motionIdx);
	PRINT("TaiPalmMotionAction::start:%08x:%d->%d\n", &teki, mMotionIdx, motionIdx);
}

/*
 * --INFO--
 * Address:	8013E7B4
 * Size:	000084
 */
void TaiPalmDyingAction::start(Teki& teki)
{
	TaiPalmStrategy* strat = (TaiPalmStrategy*)teki.getStrategy();
	int motionIdx          = strat->translateMotionIndex(teki, mMotionIdx);
	teki.startMotion(motionIdx);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
	teki.mHealth = 0.0f;
}

/*
 * --INFO--
 * Address:	8013E838
 * Size:	000060
 */
bool TaiPalmDyingAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		teki.spawnItems();
		teki.die();
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8013E898
 * Size:	000078
 */
void TaiPalmDamagingAction::start(Teki& teki)
{
	TaiPalmStrategy* strat = (TaiPalmStrategy*)teki.getStrategy();
	int motionIdx          = strat->translateMotionIndex(teki, mMotionIdx);
	teki.startMotion(motionIdx);
	PRINT("TaiPalmDamagingAction::start:%08x:%d->%d\n", &teki, mMotionIdx, motionIdx);
	teki.makeDamaged();
}

/*
 * --INFO--
 * Address:	8013E910
 * Size:	000054
 */
void TaiPalmGrowingAction::start(Teki& teki)
{
	int size = teki.getPersonalityF(TekiPersonality::FLT_Strength);
	size++;
	teki.setPersonalityF(TekiPersonality::FLT_Strength, size);
	PRINT("TaiPalmGrowingAction::start:%08x:%d\n", &teki, size);
}

/*
 * --INFO--
 * Address:	8013E964
 * Size:	000068
 */
bool TaiPalmGrowAction::act(Teki& teki)
{
	STACK_PAD_VAR(1);
	int size = teki.getPersonalityF(TekiPersonality::FLT_Strength);
	if (size >= 2) {
		return false;
	}
	if (!teki.timerElapsed(mTimerIdx)) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	8013E9CC
 * Size:	000038
 */
bool TaiPalmFlowerDamageAction::act(Teki& teki)
{
	if (teki.mStoredDamage <= 0.0f) {
		return false;
	}
	if (teki._344 == 0) {
		PRINT("TaiPalmFlowerDamageAction::act:%08x:DMG_0\n", &teki);
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	8013EA04
 * Size:	000034
 */
bool TaiPalmSunflowerAction::act(Teki& teki)
{
	teki.turnTo(mapMgr->mDayMgr->mSunPosition);
	return false;
}

/*
 * --INFO--
 * Address:	8013EA38
 * Size:	000064
 */
void TaiPalmSettingPelletAction::start(Teki& teki)
{
	teki.mPersonality->mPelletColor = teki._3BC;
	int size                        = teki.getPersonalityF(TekiPersonality::FLT_Strength);
	if (size != 2) {
		teki.setPersonalityI(TekiPersonality::INT_PelletMinCount, 0);
		teki.setPersonalityI(TekiPersonality::INT_PelletMaxCount, 0);
	}
}

/*
 * --INFO--
 * Address:	8013EA9C
 * Size:	000004
 */
void TaiPalmChangingColorAction::start(Teki&)
{
}

/*
 * --INFO--
 * Address:	8013EAA0
 * Size:	000090
 */
bool TaiPalmChangingColorAction::act(Teki& teki)
{
	if (teki.getPersonalityI(TekiPersonality::INT_Parameter0) == 1) {
		return false;
	}

	if (!teki.timerElapsed(mTimerIdx)) {
		return false;
	}

	teki._3BC++;
	if (teki._3BC == 3) {
		teki._3BC = PELCOLOR_Blue;
	}

	resetTimer(teki);
	return false;
}

/*
 * --INFO--
 * Address:	8013EB30
 * Size:	0000A8
 */
void TaiPalmChangingColorAction::resetTimer(Teki& teki)
{
	teki.mTimers[mTimerIdx] = NMathF::rateRandom(mAvgTimerValue, mTimerRange);
}
