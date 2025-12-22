#include "TAI/Palm.h"

#include "DayMgr.h"
#include "DebugLog.h"
#include "MapMgr.h"
#include "Pellet.h"
#include "SoundMgr.h"
#include "TAI/MotionActions.h"
#include "TAI/ReactionActions.h"
#include "TAI/TimerActions.h"
#include "TekiConditions.h"
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
 * Size:	0000F0
 */
DEFINE_PRINT("taipalm")

/**
 * @brief TODO
 */
struct TaiPalmMotionAction : public TaiMotionAction {
	TaiPalmMotionAction(int nextState, int motionIdx)
	    : TaiMotionAction(nextState, motionIdx)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiMotionAction?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiPalmDyingAction : public TaiDyingAction {
	TaiPalmDyingAction(int motionIdx)
	    : TaiDyingAction(motionIdx)
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
struct TaiPalmDamagingAction : public TaiDamagingAction {
	TaiPalmDamagingAction(int nextState, int p2)
	    : TaiDamagingAction(nextState, p2)
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
struct TaiPalmGrowingAction : public TaiAction {
	TaiPalmGrowingAction()
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
struct TaiPalmGrowAction : public TaiAction {
	TaiPalmGrowAction(int nextState, int timerIdx)
	    : TaiAction(nextState)
	{
		mTimerIdx = timerIdx;
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mTimerIdx; // _08
};

/**
 * @brief TODO
 */
struct TaiPalmFlowerDamageAction : public TaiAction {
	TaiPalmFlowerDamageAction(int nextState)
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
struct TaiPalmSunflowerAction : public TaiAction {
	TaiPalmSunflowerAction()
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
struct TaiPalmSettingPelletAction : public TaiAction {
	TaiPalmSettingPelletAction()
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
struct TaiPalmChangingColorAction : public TaiAction {
	TaiPalmChangingColorAction(int p1, f32 p2, f32 p3)
	    : TaiAction(TAI_NO_TRANSIT)
	{
		mTimerIdx      = p1;
		mAvgTimerValue = p2;
		mTimerRange    = p3;
	}

	virtual void start(Teki&); // _08
	virtual bool act(Teki&);   // _10

	void resetTimer(Teki&);

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mTimerIdx;      // _08
	f32 mAvgTimerValue; // _0C
	f32 mTimerRange;    // _10
};

/**
 * @TODO: Documentation
 */
TaiPalmSoundTable::TaiPalmSoundTable()
    : PaniSoundTable(5)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_FLOWER_DOWN);
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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
	TaiPalmDyingAction* dyingAction                 = new TaiPalmDyingAction(TekiMotion::Dead);

	// DEAD STATE - dead.
	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, settingPelletAction);
	state->setAction(j++, dyingAction);
	setState(PALMSTATE_Dead, state);

	TaiPalmDamagingAction* damagingAction = new TaiPalmDamagingAction(PALMSTATE_Normal, TekiMotion::Damage);

	// DAMAGE STATE - taking damage (and screaming about it)
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, deadAction);         // if dead, transit to dead
	state->setAction(j++, flowerDamageAction); // if hit directly on flower, transit to dead
	state->setAction(j++, damagingAction);     // when damaging motion complete, transit to normal state
	state->setAction(j++, changingColorAction);
	setState(PALMSTATE_Damage, state);

	TaiPalmMotionAction* motionAction1  = new TaiPalmMotionAction(PALMSTATE_Normal, TekiMotion::WaitAct1);
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
	TaiPalmMotionAction* motionAction2 = new TaiPalmMotionAction(TAI_NO_TRANSIT, TekiMotion::Wait1);

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

/**
 * @TODO: Documentation
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

	TekiAndCondition NRef cond
	    = TekiAndCondition(&TekiNotCondition(&TekiCreaturePointerCondition(&teki)),
	                       &TekiAndCondition(&TekiTypeCondition(teki.mTekiType), &TekiDistanceCondition(&teki, rad)));
	Creature* neighbor = tekiMgr->findClosest(teki.getPosition(), &cond);
	PRINT_NAKATA("TaiPalmStrategy::start:%08x:neighbor:%08x\n", &teki, neighbor);

	if (neighbor) {
		PRINT_NAKATA("TaiPalmStrategy::start:%08x:neighbor!=null:%08x\n", &teki, neighbor);
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

/**
 * @TODO: Documentation
 */
void TaiPalmStrategy::draw(Teki& teki, Graphics& gfx)
{
	teki.inputPosition(teki.mTargetPosition);
	TekiStrategy::draw(teki, gfx);
}

/**
 * @TODO: Documentation
 */
void TaiPalmStrategy::createEffect(Teki& teki, int palmEffectID)
{
	PRINT_NAKATA("TaiPalmStrategy::createEffect:%08x:%d\n", &teki, palmEffectID);
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

/**
 * @TODO: Documentation
 */
int TaiPalmStrategy::translateMotionIndex(Teki& teki, int tekiMotionIdx)
{
	enum PalmMotion {
		Size0_Dead,
		Size0_Damage,
		Size0_Wait1,

		Size1_Dead,
		Size1_Damage,
		Size1_Wait1,

		Size2_Dead,
		Size2_Damage,
		Size2_Wait1,

		Size0_Flick,
		Size1_Flick,
	};

	int size = teki.getPersonalityF(TekiPersonality::FLT_Strength);

	if (size == 0) {
		if (tekiMotionIdx == TekiMotion::Dead) {
			return Size0_Dead;
		}
		if (tekiMotionIdx == TekiMotion::Damage) {
			return Size0_Damage;
		}
		if (tekiMotionIdx == TekiMotion::Wait1) {
			return Size0_Wait1;
		}
		if (tekiMotionIdx == TekiMotion::WaitAct1) {
			return Size0_Flick;
		}
	} else if (size == 1) {
		if (tekiMotionIdx == TekiMotion::Dead) {
			return Size1_Dead;
		}
		if (tekiMotionIdx == TekiMotion::Damage) {
			return Size1_Damage;
		}
		if (tekiMotionIdx == TekiMotion::Wait1) {
			return Size1_Wait1;
		}
		if (tekiMotionIdx == TekiMotion::WaitAct1) {
			return Size1_Flick;
		}
	} else if (size == 2) {
		if (tekiMotionIdx == TekiMotion::Dead) {
			return Size2_Dead;
		}
		if (tekiMotionIdx == TekiMotion::Damage) {
			return Size2_Damage;
		}
		if (tekiMotionIdx == TekiMotion::Wait1) {
			return Size2_Wait1;
		}
	}

	PRINT("!TaiPalmStrategy::start:%08x:%d,%d\n", &teki, size, tekiMotionIdx);
	return TekiMotion::Dead;
}

/**
 * @TODO: Documentation
 */
void TaiPalmMotionAction::start(Teki& teki)
{
	TaiPalmStrategy* strat = (TaiPalmStrategy*)teki.getStrategy();
	int motionIdx          = strat->translateMotionIndex(teki, mMotionIdx);
	teki.startMotion(motionIdx);
	PRINT_NAKATA("TaiPalmMotionAction::start:%08x:%d->%d\n", &teki, mMotionIdx, motionIdx);
}

/**
 * @TODO: Documentation
 */
void TaiPalmDyingAction::start(Teki& teki)
{
	TaiPalmStrategy* strat = (TaiPalmStrategy*)teki.getStrategy();
	int motionIdx          = strat->translateMotionIndex(teki, mMotionIdx);
	teki.startMotion(motionIdx);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
	teki.mHealth = 0.0f;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void TaiPalmDamagingAction::start(Teki& teki)
{
	TaiPalmStrategy* strat = (TaiPalmStrategy*)teki.getStrategy();
	int motionIdx          = strat->translateMotionIndex(teki, mMotionIdx);
	teki.startMotion(motionIdx);
	PRINT_NAKATA("TaiPalmDamagingAction::start:%08x:%d->%d\n", &teki, mMotionIdx, motionIdx);
	teki.makeDamaged();
}

/**
 * @TODO: Documentation
 */
void TaiPalmGrowingAction::start(Teki& teki)
{
	int size = teki.getPersonalityF(TekiPersonality::FLT_Strength);
	size++;
	teki.setPersonalityF(TekiPersonality::FLT_Strength, size);
	PRINT_NAKATA("TaiPalmGrowingAction::start:%08x:%d\n", &teki, size);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
bool TaiPalmFlowerDamageAction::act(Teki& teki)
{
	if (teki.mStoredDamage <= 0.0f) {
		return false;
	}
	if (teki._344 == 0) {
		PRINT_NAKATA("TaiPalmFlowerDamageAction::act:%08x:DMG_0\n", &teki);
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool TaiPalmSunflowerAction::act(Teki& teki)
{
	teki.turnTo(mapMgr->mDayMgr->mSunPosition);
	return false;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void TaiPalmChangingColorAction::start(Teki&)
{
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void TaiPalmChangingColorAction::resetTimer(Teki& teki)
{
	teki.mTimers[mTimerIdx] = NMathF::rateRandom(mAvgTimerValue, mTimerRange);
}
