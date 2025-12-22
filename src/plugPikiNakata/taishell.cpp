#include "TAI/Shell.h"

#include "DebugLog.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "Pellet.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "TAI/BasicActions.h"
#include "TAI/EffectActions.h"
#include "TAI/MotionActions.h"
#include "TAI/ReactionActions.h"
#include "TAI/TimerActions.h"
#include "TekiConditions.h"
#include "nlib/Geometry.h"
#include "sysNew.h"
#include "teki.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("taishell");

/**
 * @brief TODO
 */
struct TaiShellSetPositionAction : public TaiAction {
	inline TaiShellSetPositionAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki&); // _10

	void setPosition(Teki&, Creature*);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiShellSaveItemPositionAction : public TaiAction {
	inline TaiShellSaveItemPositionAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual bool act(Teki&); // _10

	void setPosition(Teki&, Creature*);

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TaiShellNaviPikiInsideAction : public TaiAction {
	TaiShellNaviPikiInsideAction(int nextState)
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
struct TaiShellEatAction : public TaiAction {
	TaiShellEatAction(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki&); // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @TODO: Documentation
 */
TaiShellSoundTable::TaiShellSoundTable()
    : PaniSoundTable(5)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(SE_SHELL_CLOSE + i);
	}
}

/**
 * @TODO: Documentation
 */
TaiShellParameters::TaiShellParameters()
    : TekiParameters(SHELLPI_COUNT, SHELLPF_COUNT)
{
	int i = SHELLPI_ClosingLoopCount;
	mParameters->mIntParams->mParaInfo[i++].init("CLOSING_LOOP_COUNT", 0, 30);

	int j = SHELLPF_OpeningPeriod;
	mParameters->mFloatParams->mParaInfo[j++].init("OPENING_PERIOD", 0.0f, 30.0f);

	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_ShadowType, 1);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_CullingType, 0);
	multiP->setF(TPF_Life, 1.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, -1.0f);
	multiP->setF(TPF_AttackableRange, 42.0f);
	multiP->setF(TPF_ShadowSize, 10.0f);
	multiP->setF(TPF_SpawnDistance, 3.0f);
	multiP->setF(TPF_SpawnHeight, 10.0f);
	multiP->setF(TPF_RippleScale, 4.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 24.0f);

	multiP->setI(SHELLPI_ClosingLoopCount, 5);
	multiP->setF(SHELLPF_OpeningPeriod, 4.0f);

	STACK_PAD_VAR(1);
}

/**
 * @TODO: Documentation
 */
TaiShellStrategy::TaiShellStrategy(TekiParameters* params)
    : TaiStrategy(SHELLSTATE_COUNT, SHELLSTATE_Normal)
{
	TaiTypeNaviWatchResultOnAction* naviWatchAction   = new TaiTypeNaviWatchResultOnAction();
	TaiShellSetPositionAction* setPosAction           = new TaiShellSetPositionAction();
	TaiShellSaveItemPositionAction* saveItemPosAction = new TaiShellSaveItemPositionAction();
	TaiContinuousMotionAction* motionAction           = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Wait1);
	TaiShellNaviPikiInsideAction* insideAction        = new TaiShellNaviPikiInsideAction(SHELLSTATE_Open);

	// NORMAL STATE (just chilling)
	TaiState* state0 = new TaiState(4);
	int j            = 0;
	state0->setAction(j++, setPosAction);
	state0->setAction(j++, saveItemPosAction);
	state0->setAction(j++, motionAction);
	state0->setAction(j++, insideAction); // if pikis or navis inside, transit to Open
	setState(SHELLSTATE_Normal, state0);

	motionAction                    = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Type1);
	TaiTimerAction* openTimerAction = new TaiTimerAction(SHELLSTATE_Warn, 0, params->getF(SHELLPF_OpeningPeriod), 0.0f);

	// OPEN STATE (opening wide)
	TaiState* state1 = new TaiState(3);
	j                = 0;
	state1->setAction(j++, setPosAction);
	state1->setAction(j++, motionAction);
	state1->setAction(j++, openTimerAction); // when open timer is done, transit to Warn
	setState(SHELLSTATE_Open, state1);

	motionAction                        = new TaiContinuousMotionAction(TAI_NO_TRANSIT, TekiMotion::Type2);
	TaiCountLoopAction* closeLoopAction = new TaiCountLoopAction(SHELLSTATE_Close, params->getI(SHELLPI_ClosingLoopCount));

	// WARN STATE (warning loops at max open before snapping shut)
	TaiState* state2 = new TaiState(3);
	j                = 0;
	state2->setAction(j++, setPosAction);
	state2->setAction(j++, closeLoopAction); // when warn loops are done, transit to Close
	state2->setAction(j++, motionAction);
	setState(SHELLSTATE_Warn, state2);

	TaiShellEatAction* eatAction = new TaiShellEatAction(SHELLSTATE_Eat);
	TaiOnceAction* onceAction    = new TaiOnceAction(SHELLSTATE_Normal);

	// CLOSE STATE (snapping shut)
	TaiState* state3 = new TaiState(3);
	j                = 0;
	state3->setAction(j++, setPosAction);
	state3->setAction(j++, eatAction);  // if things to eat, transit to Eat
	state3->setAction(j++, onceAction); // nothing to eat, transit to Normal
	setState(SHELLSTATE_Close, state3);

	motionAction = new TaiContinuousMotionAction(SHELLSTATE_Normal, TekiMotion::Type4);

	// EAT STATE (chewing pikis or navis state)
	TaiState* state4 = new TaiState(3);
	j                = 0;
	state4->setAction(j++, setPosAction);
	state4->setAction(j++, motionAction); // eat anim done, transit to Normal
	state4->setAction(j++, naviWatchAction);
	setState(SHELLSTATE_Eat, state4);
}

/**
 * @TODO: Documentation
 */
void TaiShellStrategy::createEffect(Teki& teki, int p2)
{
	TekiStrategy::createEffect(teki, p2);
	if (effectMgr && p2 == 0) {
		NVector3f spawnPos;
		teki.outputSpawnPosition(spawnPos);
		effectMgr->create(EffectMgr::EFF_BigDustRing, spawnPos, nullptr, nullptr);
		rumbleMgr->start(RUMBLE_Unk4, 0, spawnPos);
	}
}

/**
 * @TODO: Documentation
 */
void TaiShellStrategy::start(Teki& teki)
{
	teki.mParticleGenerators[0] = effectMgr->create(EffectMgr::EFF_Shell_Twinkle, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	TaiStrategy::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ORGANIC);
	teki.clearTekiOption(BTeki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
	BOOL hasPart = teki.getPersonalityI(TekiPersonality::INT_Parameter0);
	int type     = TEKI_Pearl;
	if (hasPart == TRUE) {
		ID32& id = teki.mPersonality->mID;
		if (playerState->existUfoParts(id.mId)) {
			PRINT("!!!TaiShellStrategy::start:%08x:%s already exists\n", &teki, id.mStringID);
			teki.mPersonality->mID.setID('none');
		} else {
			type = TEKI_Rocpe;
		}
	}

	Teki* pearl = teki.generateTeki(type);

	if (!pearl) {
		PRINT("!TaiShellStrategy::start:teki==null:%08x\n", &teki);
		return;
	}

	NVector3f spawnPos;
	teki.outputSpawnPosition(spawnPos);
	ID32& id = teki.mPersonality->mID;
	PRINT_NAKATA("TaiShellStrategy:%08x:%d,%s\n", this, type, id.mStringID);
	pearl->mPersonality->mID.setID(id.mId);
	pearl->startAI(0); // unused, will go to default state (PEARLSTATE_Normal)

	pearl->inputPosition(spawnPos);
	pearl->setDirection(teki.getDirection());
	teki.setCreaturePointer(2, pearl);
	pearl->setCreaturePointer(0, &teki);
	teki.mPersonality->mID.setID('none');
}

/**
 * @TODO: Documentation
 */
void TaiShellStrategy::draw(Teki& teki, Graphics& gfx)
{
	teki.moveNestPosition();
	TekiStrategy::draw(teki, gfx);
	if (teki.mParticleGenerators[0]) {
		if (!teki.getTekiOption(BTeki::TEKI_OPTION_DRAWED)) {
			teki.stopParticleGenerator(0);
		} else {
			teki.startParticleGenerator(0);
			Matrix4f invLookMtx;
			gfx.mCamera->mLookAtMtx.inverse(&invLookMtx);
			NVector3f animPos;
			teki.outputWorldAnimationPosition(animPos, 6, invLookMtx);
			teki.setParticleGeneratorPosition(0, animPos);
		}
	}

	STACK_PAD_VAR(1);
}

/**
 * @TODO: Documentation
 */
bool TaiShellSetPositionAction::act(Teki& teki)
{
	BTeki* pearl = static_cast<BTeki*>(teki.getCreaturePointer(2));
	if (pearl->getTekiOption(BTeki::TEKI_OPTION_ALIVE)) {
		setPosition(teki, pearl);
	}
	return false;
}

/**
 * @TODO: Documentation
 */
void TaiShellSetPositionAction::setPosition(Teki& teki, Creature* pearl)
{
	NVector3f spawnPos;
	teki.outputSpawnPosition(spawnPos);
	spawnPos.y = mapMgr->getMinY(spawnPos.x, spawnPos.z, true);
	pearl->inputPosition(spawnPos);
}

/**
 * @TODO: Documentation
 */
bool TaiShellSaveItemPositionAction::act(Teki& teki)
{
	STACK_PAD_VAR(4);
	if (teki.mTekiAnimator->getCounter() > teki.mTekiAnimator->getKeyValueByKeyType(2)) {
		return false;
	}

	Pellet* item = static_cast<Teki*>(teki.getCreaturePointer(2))->mPellet;

	if (!item) {
		PRINT_NAKATA("TaiShellSaveItemPositionAction::act:item==null:%08x\n", &teki);
		return false;
	}

	NVector3f savePos;
	teki.outputSpawnPosition(savePos);
	f32 dist = savePos.distanceXZ(item->getPosition());
	if (dist >= teki.getAttackableRange()) {
		PRINT_NAKATA("TaiShellResetPearlAction::resetPearl:%08x:outside:%f,%f\n", &teki, dist, teki.getAttackableRange());
		return false;
	}

	PRINT_NAKATA("TaiShellResetPearlAction::resetPearl:%08x:inside:%f,%f\n", &teki, dist, teki.getAttackableRange());
	setPosition(teki, item);
	return false;
}

/**
 * @TODO: Documentation
 */
void TaiShellSaveItemPositionAction::setPosition(Teki& teki, Creature* item)
{
	NVector3f spawnPos;
	teki.outputSpawnPosition(spawnPos);
	spawnPos.y = mapMgr->getMinY(spawnPos.x, spawnPos.z, true);
	item->inputPosition(spawnPos);
}

/**
 * @TODO: Documentation
 */
bool TaiShellNaviPikiInsideAction::act(Teki& teki)
{
	NVector3f spawnPos;
	teki.outputSpawnPosition(spawnPos);

	TekiPositionDistanceCondition NRef distCond = TekiPositionDistanceCondition(spawnPos, teki.getAttackableRange());
	return teki.checkNaviPiki(distCond);

	// idk man.
	TekiNotCondition(nullptr);
}

/**
 * @TODO: Documentation
 */
bool TaiShellEatAction::act(Teki& teki)
{
	TekiAndCondition andCond(&TekiRecognitionCondition(&teki), &TekiNotCondition(&TekiStickerCondition(&teki)));

	NVector3f spawnPos;
	teki.outputSpawnPosition(spawnPos);
	TekiAndCondition posDistAndAnd(&andCond, &TekiPositionDistanceCondition(spawnPos, teki.getAttackableRange()));
	return teki.interactNaviPiki(InteractSwallow(&teki, nullptr, 0), posDistAndAnd);

	// i am not proud of what this project has required of me spiritually
	TekiAndCondition(nullptr, nullptr);
	TekiAndCondition(nullptr, nullptr);
	TekiNotCondition(nullptr);
}

/**
 * @brief TODO
 */
struct TaiPearlTresureSoundAction : public TaiAction {
	inline TaiPearlTresureSoundAction() // TODO: this is a guess
	    : TaiAction(TAI_NO_TRANSIT)
	{
	}

	virtual void start(Teki&); // _08

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @TODO: Documentation
 */
TaiPearlSoundTable::TaiPearlSoundTable()
    : PaniSoundTable(5)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(SE_SHELL_CLOSE + i);
	}
}

/**
 * @TODO: Documentation
 */
TaiPearlParameters::TaiPearlParameters()
    : TekiParameters(20, 50)
{
	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, 1);
	multiP->setI(TPI_CarcassSize, 3);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_SpawnPelletForward, 1);

	multiP->setF(TPF_Life, 1.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, 1000.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_LifeGaugeOffset, 30.0f);
	multiP->setF(TPF_ShadowSize, 25.0f);
	multiP->setF(TPF_CorpseSize, 5.0f);
	multiP->setF(TPF_CorpseHeight, 5.0f);
	multiP->setF(TPF_CorpseVelocityHoriz, 400.0f);
	multiP->setF(TPF_CorpseVelocityVert, 300.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 16.0f);

	STACK_PAD_VAR(4);
}

/**
 * @TODO: Documentation
 */
TaiRocpearlParameters::TaiRocpearlParameters()
    : TekiParameters(20, 50)
{
	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_CorpseType, 0);
	multiP->setI(TPI_CarcassSize, 3);
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_SpawnPelletForward, 1);

	multiP->setF(TPF_Life, 1.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Weight, 1000.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_LifeGaugeOffset, 30.0f);
	multiP->setF(TPF_ShadowSize, 25.0f);
	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 400.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 300.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 16.0f);

	STACK_PAD_VAR(4);
}

/**
 * @TODO: Documentation
 */
TaiPearlStrategy::TaiPearlStrategy(TekiParameters*)
    : TaiStrategy(PEARLSTATE_COUNT, PEARLSTATE_Normal)
{
	TaiDeadAction* deadAct               = new TaiDeadAction(PEARLSTATE_Die);
	TaiDamageAction* damageAct           = new TaiDamageAction(PEARLSTATE_Damage);
	TaiDyingAction* dyingAct             = new TaiDyingAction(TekiMotion::Dead);
	TaiSpawnItemsAction* spawnItemsAct   = new TaiSpawnItemsAction();
	TaiEffectAction* effectAct           = new TaiEffectAction(EffectMgr::EFF_Shell_Boom);
	TaiPearlTresureSoundAction* soundAct = new TaiPearlTresureSoundAction();
	TaiSetOptionAction* setOptAct        = new TaiSetOptionAction(BTeki::TEKI_OPTION_SHADOW_VISIBLE, false);

	// DIE STATE (dying, time to yeet out of the clam)
	TaiState* state = new TaiState(5);
	int j           = 0;
	state->setAction(j++, soundAct);
	state->setAction(j++, spawnItemsAct);
	state->setAction(j++, dyingAct);
	state->setAction(j++, setOptAct);
	state->setAction(j++, effectAct);
	setState(PEARLSTATE_Die, state);

	TaiMotionAction* motionAct = new TaiMotionAction(TAI_NO_TRANSIT, TekiMotion::Wait1);

	// NORMAL STATE (just chilling)
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, deadAct);   // if dead, transit to Die
	state->setAction(j++, damageAct); // if being damaged, transit to Damage
	state->setAction(j++, motionAct);
	setState(PEARLSTATE_Normal, state);

	TaiDamagingAction* damagingAct = new TaiDamagingAction(PEARLSTATE_Normal, TekiMotion::Damage);

	// DAMAGE STATE (being attacked)
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, deadAct);     // if dead, transit to Die
	state->setAction(j++, damagingAct); // if no longer being damaged, transit to Normal
	setState(PEARLSTATE_Damage, state);
}

/**
 * @TODO: Documentation
 */
void TaiPearlStrategy::start(Teki& teki)
{
	TaiStrategy::start(teki);
}

/**
 * @TODO: Documentation
 */
void TaiPearlTresureSoundAction::start(Teki& teki)
{
	Creature* maybeClam = teki.getCreaturePointer(0);
	if (maybeClam) {
		Teki* clam = static_cast<Teki*>(maybeClam);
		clam->playSound(SE_SHELL_TRESURE);
		clam->playSound(SE_KURIONE_HIT);
	} else {
		PRINT_NAKATA("TaiPearlTresureSoundAction::start:creature==null:%08x\n", &teki);
	}
}
