#include "DebugLog.h"
#include "SoundMgr.h"
#include "TAI/Aeffect.h"
#include "TAI/Areaction.h"
#include "TAI/Tank.h"
#include "nlib/Math.h"

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
DEFINE_PRINT(nullptr)

TAIeffectAttackEventCallBackTank FireEffect::eventCallBackFire;

/*
 * --INFO--
 * Address:	801A35D0
 * Size:	000084
 */
TAItankSoundTable::TAItankSoundTable()
    : PaniSoundTable(7)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_TANK_FIRE);
	}
}

/*
 * --INFO--
 * Address:	801A3654
 * Size:	000364
 */
TAItankParameters::TAItankParameters()
    : TekiParameters(TPI_COUNT, TAItankFloatParams::COUNT)
{
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	int j                           = TPF_COUNT;
	fParams[j++].init("炎攻撃時離れる距離", 0.0f, 1000.0f);    // 'distance to move away when attacking with fire'
	fParams[j++].init("炎攻撃のアニメ速度", 0.0f, 300.0f);     // 'fire attack anim speed'
	fParams[j++].init("後退り速度", 0.0f, 1000.0f);            // 'reverse speed'
	fParams[j++].init("パトロールタイムアウト", 0.0f, 100.0f); // 'patrol timeout'

	multiP->setF(TAItankFloatParams::StepBackAttackDistance, 0.0f);
	multiP->setF(TAItankFloatParams::FireAttackAnimSpeed, 50.0f);
	multiP->setF(TAItankFloatParams::StepBackSpeed, 50.0f);
	multiP->setF(TAItankFloatParams::PatrolTimeout, 5.0f);

	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
	multiP->setI(TPI_SpawnType, TEKI_NULL);
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 2);
	multiP->setI(TPI_FlickPikiCount2, 5);
	multiP->setI(TPI_FlickPikiCount3, 10);
	multiP->setI(TPI_FlickDamageCount1, 3);
	multiP->setI(TPI_FlickDamageCount2, 3);
	multiP->setI(TPI_FlickDamageCount3, 3);
	multiP->setI(TPI_FlickDamageCount4, 3);

	multiP->setI(TPI_CarcassSize, 1);

	multiP->setF(TPF_Weight, 1000.0f);
	multiP->setF(TPF_Scale, 1.3f);
	multiP->setF(TPF_Life, 100.0f);

	multiP->setF(TPF_WalkVelocity, 40.0f);
	multiP->setF(TPF_RunVelocity, 120.0f);
	multiP->setF(TPF_TurnVelocity, 20.0f * PI / 180.0f);

	multiP->setF(TPF_VisibleRange, 200.0f);
	multiP->setF(TPF_VisibleAngle, 270.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);

	multiP->setF(TPF_AttackableRange, 5.0f);
	multiP->setF(TPF_AttackableAngle, 5.0f);
	multiP->setF(TPF_AttackRange, 30.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 30.0f);

	multiP->setF(TPF_DangerTerritoryRange, 150.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 100.0f);

	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);

	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 500.0f);
	multiP->setF(TPF_LowerFlickPower, 300.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);

	multiP->setF(TPF_LifeRecoverRate, 0.01f);
	multiP->setF(TPF_LifeGaugeOffset, 20.0f);

	multiP->setF(TPF_ShadowSize, 40.0f);
	multiP->setF(TPF_TraceAngle, 60.0f);

	multiP->setF(TPF_CorpseSize, 20.0f);
	multiP->setF(TPF_CorpseHeight, 18.0f);

	multiP->setI(TPI_CullingType, CULLAI_CullAIOffCamera);

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	801A39B8
 * Size:	000C14
 */
TAItankStrategy::TAItankStrategy()
    : YaiStrategy(TAItankStateID::COUNT, TAItankStateID::Unk1)
{
	Vector3f* vecs = new Vector3f[3];
	vecs[0].set(0.0f, 0.0f, 0.5f);
	vecs[1].set(0.5f, 0.0f, -0.5f);
	vecs[2].set(-0.5f, 0.0f, -0.5f);

	TAIAdeadCheck* deadCheck      = new TAIAdeadCheck(TAItankStateID::Unk0);
	TAIAdying* dying              = new TAIAdying(TAI_NO_TRANSIT, TAItankMotionID::Unk0);
	TAIAdamage* damage            = new TAIAdamage(TAI_NO_TRANSIT, true);
	TAIAstop* stop                = new TAIAstop(TAI_NO_TRANSIT);
	TAIApatrolTank* patrol        = new TAIApatrolTank(TAI_NO_TRANSIT, 6, TAItankMotionID::Unk4, TAItankMotionID::Unk4, vecs, 3);
	TAIAvisiblePiki* visiblePiki1 = new TAIAvisiblePiki(TAItankStateID::Unk3);
	TAIAvisibleNavi* visibleNavi1 = new TAIAvisibleNavi(TAItankStateID::Unk3);
	TAIAwait* wait1               = new TAIAwait(TAItankStateID::Unk5, TAItankMotionID::Unk2, 0.5f);
	TAIAwait* wait2               = new TAIAwait(TAItankStateID::Unk2, TAItankMotionID::Unk5, 0.0f);
	TAIAattackableAngleTarget* attackableAngleTarget = new TAIAattackableAngleTarget(TAItankStateID::Unk6);
	TAIAturnFocusCreature* turnFocus = new TAIAturnFocusCreature(TAItankStateID::Unk7, TAItankMotionID::Unk4, TAItankMotionID::Unk4, true);
	TAIAunvisibleTarget* unvisibleTarget       = new TAIAunvisibleTarget(TAItankStateID::Unk4);
	TAIAoutsideOptionalRangeTank* outsideRange = new TAIAoutsideOptionalRangeTank(TAItankStateID::Unk7);
	TAIAstepBackTank* stepBack                 = new TAIAstepBackTank(TAItankStateID::Unk7, TAItankMotionID::Unk7);
	TAIAfireBreathTank* fireBreath             = new TAIAfireBreathTank(TAItankStateID::Unk8, TAItankMotionID::Unk8, new FireEffect());
	TAIAflickCheck* flickCheck                 = new TAIAflickCheck(TAItankStateID::Unk9, -1);
	TAIAflickingTank* flicking                 = new TAIAflickingTank(TAItankStateID::Unk7, TAItankMotionID::Unk9);
	TAIArandomWalk* randomWalk                 = new TAIArandomWalk(TAItankStateID::Unk11, TAItankMotionID::Unk10);
	TAIAgoingHomePriorityFaceDir* goingHome    = new TAIAgoingHomePriorityFaceDir(TAItankStateID::Unk2, TAItankMotionID::Unk10);
	TAIAoutsideTerritory* outsideTerritory     = new TAIAoutsideTerritory(TAItankStateID::Unk11);
	TAIAeffCloudOfDust* effCloud
	    = new TAIAeffCloudOfDust(TAI_NO_TRANSIT, EffectMgr::EFF_SmokeRing_S, SE_TANK_WALK, -0.5f, 4, 'asi1', 'asi2', 'asi3', 'asi4');
	TAIAinitTank* init            = new TAIAinitTank(TAItankStateID::Unk2);
	TAIAvisiblePiki* visiblePiki2 = new TAIAvisiblePiki(TAItankStateID::Unk5);
	TAIAvisibleNavi* visibleNavi2 = new TAIAvisibleNavi(TAItankStateID::Unk5);
	TAIAnoReaction* noReact       = new TAIAnoReaction(TAItankStateID::Unk2);

	// STATE 1 - Unknown
	TaiState* state = new TaiState(1);
	int j           = 0;
	state->setAction(j++, init);
	setState(TAItankStateID::Unk1, state);

	// STATE 0 - Unknown
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, dying);
	state->setAction(j++, stop);
	setState(TAItankStateID::Unk0, state);

	// STATE 2 - Unknown
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damage);
	state->setAction(j++, patrol);
	state->setAction(j++, visibleNavi1);
	state->setAction(j++, visiblePiki1);
	state->setAction(j++, flickCheck);
	state->setAction(j++, effCloud);
	setState(TAItankStateID::Unk2, state);

	// STATE 3 - Unknown
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damage);
	state->setAction(j++, flickCheck);
	state->setAction(j++, wait1);
	state->setAction(j++, effCloud);
	setState(TAItankStateID::Unk3, state);

	// STATE 4 - Unknown
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damage);
	state->setAction(j++, wait2);
	setState(TAItankStateID::Unk4, state);

	// STATE 5 - Unknown
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damage);
	state->setAction(j++, flickCheck);
	state->setAction(j++, attackableAngleTarget);
	state->setAction(j++, turnFocus);
	state->setAction(j++, unvisibleTarget);
	state->setAction(j++, effCloud);
	setState(TAItankStateID::Unk5, state);

	// STATE 6 - Unknown
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damage);
	state->setAction(j++, outsideTerritory);
	state->setAction(j++, flickCheck);
	state->setAction(j++, stepBack);
	state->setAction(j++, outsideRange);
	state->setAction(j++, unvisibleTarget);
	state->setAction(j++, effCloud);
	setState(TAItankStateID::Unk6, state);

	// STATE 7 - Unknown
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, effCloud);
	state->setAction(j++, deadCheck);
	state->setAction(j++, damage);
	state->setAction(j++, fireBreath);
	state->setAction(j++, stop);
	setState(TAItankStateID::Unk7, state);

	// STATE 8 - Unknown
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, visiblePiki2);
	state->setAction(j++, visibleNavi2);
	state->setAction(j++, noReact);
	setState(TAItankStateID::Unk8, state);

	// STATE 9 - Unknown
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damage);
	state->setAction(j++, flicking);
	state->setAction(j++, effCloud);
	setState(TAItankStateID::Unk9, state);

	// STATE 10 - Unknown
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damage);
	state->setAction(j++, outsideTerritory);
	state->setAction(j++, randomWalk);
	state->setAction(j++, effCloud);
	setState(TAItankStateID::Unk10, state);

	// STATE 11 - Unknown
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damage);
	state->setAction(j++, goingHome);
	state->setAction(j++, effCloud);
	setState(TAItankStateID::Unk11, state);
}

/*
 * --INFO--
 * Address:	801A45CC
 * Size:	000120
 */
void TAItankStrategy::act(Teki& teki)
{
	zen::particleGenerator* ptclGen;
	YaiStrategy::act(teki);
	CollPart* mouth = teki.mCollInfo->getSphere('kuti');
	Vector3f dir(NMathF::sin(teki.mFaceDirection), 0.0f, NMathF::cos(teki.mFaceDirection));
	ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk0);
	if (ptclGen) {
		if (!ptclGen->checkEmit()) {
			teki.setPtclGenPtr(YTeki::PTCL_Unk0, nullptr);
		} else {
			ptclGen->setEmitPos(mouth->mCentre);
			ptclGen->setEmitDir(dir);
		}
	}

	ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk1);
	if (ptclGen) {
		if (!ptclGen->checkEmit()) {
			teki.setPtclGenPtr(YTeki::PTCL_Unk1, nullptr);
		} else {
			ptclGen->setEmitPos(mouth->mCentre);
			ptclGen->setEmitDir(dir);
		}
	}
}

/*
 * --INFO--
 * Address:	801A46EC
 * Size:	0000C4
 */
bool TAItankStrategy::interact(Teki& teki, TekiInteractionKey& key)
{
	switch (key.mInteractionType) {
	case TekiInteractType::Attack:
		InteractAttack* attack = (InteractAttack*)key.mInteraction;
		if (!teki.getTekiOption(BTeki::TEKI_OPTION_INVINCIBLE)) {
			teki.mStoredDamage += attack->mDamage;
			if (teki.getTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE)) {
				teki.mDamageCount++;
			}
		}

		teki.setCreaturePointer(1, attack->mOwner);
		return true;
	}

	STACK_PAD_VAR(2);
	return true;
}

/*
 * --INFO--
 * Address:	801A47B0
 * Size:	0006FC
 */
void TAItankAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_Tank]->mShape;
	addAnimation("tekis/tank/motion/dead.dca");

	addAnimation("tekis/tank/motion/damage.dca");

	addAnimation("tekis/tank/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/tank/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/tank/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/tank/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/tank/motion/move1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/tank/motion/move2.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/tank/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/tank/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/tank/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}
