#include "TAI/Iwagen.h"
#include "SoundMgr.h"
#include "teki.h"
#include "TAI/MoveActions.h"
#include "TAI/ReactionActions.h"
#include "TAI/EffectActions.h"
#include "TAI/BasicActions.h"
#include "TAI/TimerActions.h"
#include "TAI/CollisionActions.h"
#include "TAI/AttackActions.h"
#include "MapCode.h"
#include "DebugLog.h"

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
DEFINE_PRINT("taiiwagen")

/*
 * --INFO--
 * Address:	8012E6C8
 * Size:	000108
 */
TaiIwagonParameters::TaiIwagonParameters()
    : TekiParameters(TPI_COUNT, TPF_COUNT)
{
	ParaMultiParameters* multiP = mParameters;
	multiP->setI(TPI_SpawnType, -1);
	multiP->setI(TPI_CullingType, 1);

	multiP->setF(TPF_Weight, 10.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 10.0f);
	multiP->setF(TPF_ShadowSize, 30.0f);
	multiP->setF(TPF_RippleScale, 3.0f);
	multiP->setF(TPF_CorpseSize, 38.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_AttackPower, 10.0f);
	multiP->setF(TPF_LifePeriod, 5.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(TPF_CollisionRadius, 24.0f);
}

/*
 * --INFO--
 * Address:	8012E7D0
 * Size:	000084
 */
TaiIwagonSoundTable::TaiIwagonSoundTable()
    : PaniSoundTable(2)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(SE_ROCK_ROLL + i);
	}
}

/*
 * --INFO--
 * Address:	8012E854
 * Size:	0004C0
 */
TaiIwagonStrategy::TaiIwagonStrategy(TekiParameters* params)
    : TaiStrategy(IWAGONSTATE_COUNT, IWAGONSTATE_Roll)
{
	TaiStopMoveAction* stopMove                = new TaiStopMoveAction();
	TaiDyingAction* dying                      = new TaiDyingAction(0);
	TaiStopGenParticleGeneratorAction* stopGen = new TaiStopGenParticleGeneratorAction(0);
	TaiStopSoundAction* stopSound              = new TaiStopSoundAction(SE_ROCK_ROLL);
	TaiSetOptionAction* setOpt                 = new TaiSetOptionAction(BTeki::TEKI_OPTION_SHADOW_VISIBLE, false);

	TaiState* state = new TaiState(5);
	int j           = 0;
	state->setAction(j++, stopMove);
	state->setAction(j++, dying);
	state->setAction(j++, setOpt);
	state->setAction(j++, stopGen);
	state->setAction(j++, stopSound);
	setState(IWAGONSTATE_Die, state);

	// die after life timer expires
	TaiTimerAction* timer         = new TaiTimerAction(IWAGONSTATE_Die, 0, params->getF(TPF_LifePeriod), 0.0f);
	TaiPlaySoundAction* playSound = new TaiPlaySoundAction(SE_ROCK_ROLL);
	// die on damage
	TaiDamageAction* damage = new TaiDamageAction(IWAGONSTATE_Die);
	// die on wall collision
	TaiWallCollisionAction* wallCollision = new TaiWallCollisionAction(IWAGONSTATE_Die);
	// die colliding with teki
	TaiTekiTypeCollisionAction* tekiCollision = new TaiTekiTypeCollisionAction(IWAGONSTATE_Die, TEKI_Iwagon);
	TaiBangingAction* banging                 = new TaiBangingAction(TAI_NO_TRANSIT);
	// die when rolling (ends?)
	TaiIwagonRollingAction* iwagonRolling       = new TaiIwagonRollingAction(IWAGONSTATE_Die);
	TaiMotionAction* motion                     = new TaiMotionAction(TAI_NO_TRANSIT, 6);
	TaiIwagonDustEffectAction* iwagonDustEffect = new TaiIwagonDustEffectAction();

	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, wallCollision);
	state->setAction(j++, tekiCollision);
	state->setAction(j++, timer);
	state->setAction(j++, banging);
	state->setAction(j++, iwagonRolling);
	state->setAction(j++, motion);
	state->setAction(j++, playSound);
	state->setAction(j++, iwagonDustEffect);
	setState(IWAGONSTATE_Roll, state);
}

/*
 * --INFO--
 * Address:	8012ED14
 * Size:	000114
 */
void TaiIwagonStrategy::start(Teki& teki)
{
	int param = teki.getPersonalityI(TekiPersonality::INT_Parameter0);
	if (param == 0) {
		teki.mParticleGenerators[0] = effectMgr->create(EffectMgr::EFF_Iwagon_Start1, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	} else if (param == 1) {
		teki.mParticleGenerators[0] = effectMgr->create(EffectMgr::EFF_Iwagon_Start2, Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
	} else {
		ERROR("TaiIwagonStrategy::start\n");
	}

	if (teki.mParticleGenerators[0]) {
		teki.mParticleGenerators[0]->setEmitPosPtr(&teki.getPosition());
	}
	teki.stopParticleGenerator(0);
	TaiStrategy::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
}

/*
 * --INFO--
 * Address:	8012EE28
 * Size:	000070
 */
bool TaiIwagonDustEffectAction::act(Teki& teki)
{
	if (teki.mFloorTri) {
		if (MapCode::getAttribute(teki.mFloorTri) != ATTR_Water) {
			teki.startParticleGenerator(0);
		} else {
			teki.stopParticleGenerator(0);
		}
	} else {
		teki.stopParticleGenerator(0);
	}

	return false;
}

/*
 * --INFO--
 * Address:	8012EE98
 * Size:	00001C
 */
void TaiIwagonRollingAction::start(Teki& teki)
{
	teki._398.input(teki.mVelocity);
}

/*
 * --INFO--
 * Address:	8012EEB4
 * Size:	000020
 */
bool TaiIwagonRollingAction::act(Teki& teki)
{
	teki.mTargetVelocity.input(teki._398);
	return false;
}

/*
 * --INFO--
 * Address:	8012EED4
 * Size:	000118
 */
TaiIwagenParameters::TaiIwagenParameters()
    : TekiParameters(TPI_COUNT, IWAGENPF_COUNT)
{
	ParaMultiParameters* multiP = mParameters;
	int j                       = IWAGENPF_IwagonScale;
	multiP->mFloatParams->mParaInfo[j++].init("IWAGON_SCALE", 0.0f, 1.0f);

	multiP->setI(TPI_SpawnType, TEKI_Iwagon);

	multiP->setF(TPF_Weight, 0.0f);
	multiP->setF(TPF_Scale, 1.3f);
	multiP->setF(TPF_Life, 1.0f);
	multiP->setF(TPF_AttackWaitPeriod, 2.0f);
	multiP->setF(TPF_UnguardedPeriod, 0.0f);
	multiP->setF(TPF_SpawnDistance, 19.0f);
	multiP->setF(TPF_SpawnHeight, 23.0f);
	multiP->setF(TPF_SpawnVelocity, 100.0f);
	multiP->setF(TPF_BombDamageRate, 1.0f);
	multiP->setF(IWAGENPF_IwagonScale, 0.5f);
	u32 badCompiler;
}

/*
 * --INFO--
 * Address:	8012EFEC
 * Size:	000210
 */
TaiIwagenStrategy::TaiIwagenStrategy(TekiParameters* params)
    : TaiStrategy(IWAGENSTATE_COUNT, IWAGENSTATE_Wait)
{
	// shoot after attackwait timer
	TaiTimerAction* timer = new TaiTimerAction(IWAGENSTATE_Shoot, 0, params->getF(TPF_AttackWaitPeriod), 0.5f);

	TaiState* state = new TaiState(1);
	int j           = 0;
	state->setAction(j++, timer);
	setState(IWAGENSTATE_Wait, state);

	// wait for anim to finish after spawning rock
	TaiIwagenShootingAction* shoot = new TaiIwagenShootingAction(IWAGENSTATE_Reset);
	TaiMotionAction* motion        = new TaiMotionAction(TAI_NO_TRANSIT, 8);

	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, motion);
	state->setAction(j++, shoot);
	setState(IWAGENSTATE_Shoot, state);

	// after anim is finished, back to waiting
	TaiAnimationKeyAction* keyAnim = new TaiAnimationKeyAction(IWAGENSTATE_Wait, BTeki::ANIMATION_KEY_OPTION_FINISHED);

	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, keyAnim);
	setState(IWAGENSTATE_Reset, state);
}

/*
 * --INFO--
 * Address:	8012F1FC
 * Size:	00007C
 */
void TaiIwagenStrategy::draw(Teki& teki, Graphics& gfx)
{
	if (teki.mStateID == IWAGENSTATE_Wait || teki.mStateID == IWAGENSTATE_Reset) {
		teki.mTekiShape->mShape->mJointList[1].mFlags = 0;
		TekiStrategy::draw(teki, gfx);
		teki.mTekiShape->mShape->mJointList[1].mFlags = 1;
	} else {
		TekiStrategy::draw(teki, gfx);
	}
}

/*
 * --INFO--
 * Address:	8012F278
 * Size:	000044
 */
void TaiIwagenStrategy::start(Teki& teki)
{
	TaiStrategy::start(teki);
	teki.clearTekiOption(BTeki::TEKI_OPTION_ORGANIC);
}

/*
 * --INFO--
 * Address:	8012F2BC
 * Size:	000078
 */
void TaiIwagenShootingAction::start(Teki& teki)
{
	teki.stopMove();
}

/*
 * --INFO--
 * Address:	8012F334
 * Size:	000198
 */
bool TaiIwagenShootingAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_ACTION_0)) {
		Teki* iwagon = teki.generateTeki(teki.getParameterI(TPI_SpawnType));
		if (!iwagon) {
			return true;
		}

		iwagon->setPersonalityF(TekiPersonality::FLT_Size, teki.getParameterF(IWAGENPF_IwagonScale));
		iwagon->setPersonalityI(TekiPersonality::INT_Parameter0, 0);
		Vector3f spawnPos;
		teki.outputSpawnPosition(spawnPos);
		iwagon->inputPosition(spawnPos);
		u32 badCompiler;
		Vector3f spawnVel;
		teki.outputDirectionVector(spawnVel);
		spawnVel.scale(teki.getParameterF(TPF_SpawnVelocity) * teki.getPersonalityF(TekiPersonality::FLT_Strength));
		iwagon->inputVelocity(spawnVel);
		iwagon->startAI(0);
		return true;
	}

	return false;
}
