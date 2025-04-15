#include "TAI/KabekuiA.h"
#include "sysNew.h"
#include "DebugLog.h"
#include "SoundID.h"
#include "TAI/Amove.h"
#include "TAI/Ajudge.h"
#include "PlayerState.h"

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
DEFINE_PRINT("TAIkabekuiA")

/*
 * --INFO--
 * Address:	801CA2A8
 * Size:	000084
 */
TAIkabekuiASoundTable::TAIkabekuiASoundTable()
    : PaniSoundTable(3)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_WALLEAT_WALK);
	}
}

/*
 * --INFO--
 * Address:	801CA32C
 * Size:	00036C
 */
TAIkabekuiAParameters::TAIkabekuiAParameters()
    : TekiParameters(TPI_COUNT, KABEKUIAPF_COUNT)
{
	int j                           = KABEKUIAPF_Unk0;
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("壁食いポイントの大きさ", 0.0f, 1000.0f);
	fParams[j++].init("壁食いダメージ", 0.0f, 100.0f);
	fParams[j++].init("潜るまでの時間（秒）", 0.0f, 100.0f);
	fParams[j++].init("スリープ時間（秒）", 0.0f, 100.0f);

	multiP->setF(KABEKUIAPF_Unk0, 8.0f);
	multiP->setF(KABEKUIAPF_Unk1, 0.00000001f);
	multiP->setF(KABEKUIAPF_Unk2, 3.0f);
	multiP->setF(KABEKUIAPF_Unk3, 3.0f);

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
	multiP->setI(TPI_CullingType, CULLAI_NeverCullAI);
	multiP->setI(TPI_CarcassSize, 2);

	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 50.0f);

	multiP->setF(TPF_WalkVelocity, 40.0f);
	multiP->setF(TPF_RunVelocity, 120.0f);
	multiP->setF(TPF_TurnVelocity, 0.9948377f);

	multiP->setF(TPF_VisibleRange, 150.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);

	multiP->setF(TPF_AttackableRange, 40.0f);
	multiP->setF(TPF_AttackableAngle, 30.0f);
	multiP->setF(TPF_AttackRange, 30.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 5.0f);

	multiP->setF(TPF_DangerTerritoryRange, 300.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 120.0f);

	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);

	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 300.0f);
	multiP->setF(TPF_LowerFlickPower, 300.0f);
	multiP->setF(TPF_UpperAttackPower, 20.0f);
	multiP->setF(TPF_LowerAttackPower, 10.0f);

	multiP->setF(TPF_LifeRecoverRate, 0.01f);
	multiP->setF(TPF_LifeGaugeOffset, 20.0f);

	multiP->setF(TPF_ShadowSize, 10.0f);
	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);

	multiP->setF(TPF_TraceAngle, 60.0f);
	multiP->setF(TPF_RippleScale, 1.0f);
}

/*
 * --INFO--
 * Address:	801CA698
 * Size:	000A84
 */
TAIkabekuiAStrategy::TAIkabekuiAStrategy()
    : YaiStrategy(KABEKUIASTATE_COUNT, KABEKUIASTATE_Unk1) // TODO: fix
{
	TAIAdeadCheck* deadCheck       = new TAIAdeadCheck(KABEKUIASTATE_Unk0);
	TAIAdyingKabekui* dyingKabekui = new TAIAdyingKabekui(TAI_NO_TRANSIT, KABEKUIAANIM_Unk0, EffectMgr::EFF_SmokeRing_S);
	TAIAdamage* damage             = new TAIAdamage(TAI_NO_TRANSIT, 1);
	TAIAstop* stop                 = new TAIAstop(TAI_NO_TRANSIT);
	new TAIArandomWalk(TAI_NO_TRANSIT, KABEKUIAANIM_Unk6); // unused
	TAIAsetMotionSpeed* setMotionSpeed = new TAIAsetMotionSpeed(TAI_NO_TRANSIT, KABEKUIAANIM_Unk4, 0.0f);
	TAIAvisibleNavi* visibleNavi       = new TAIAvisibleNavi(KABEKUIASTATE_Unk2);
	new TAIAvisiblePiki(KABEKUIASTATE_Unk2); // unused
	TAIAappearKabekui* appearKabekui1                     = new TAIAappearKabekui(KABEKUIASTATE_Unk3, KABEKUIAANIM_Unk4, 30.0f, 1);
	TAIAsetTargetPointCircleRandom* setRandomTargetCircle = new TAIAsetTargetPointCircleRandom(KABEKUIASTATE_Unk4);
	TAIAgoTargetPriorityFaceDir* targetFaceDir1           = new TAIAgoTargetPriorityFaceDir(KABEKUIASTATE_Unk3, KABEKUIAANIM_Unk6);
	TAIAhitCheckFlyingPiki* pressCheck                    = new TAIAhitCheckFlyingPiki(KABEKUIASTATE_Unk5);
	TAIAdyingCrushKabekui* crushDying       = new TAIAdyingCrushKabekui(TAI_NO_TRANSIT, KABEKUIAANIM_Unk1, EffectMgr::EFF_SmokeRing_S);
	TAIAsearchWorkObject* searchWorkObject1 = new TAIAsearchWorkObject(KABEKUIASTATE_Unk6);
	TAIAinvincibleOn* invincibleOn          = new TAIAinvincibleOn(TAI_NO_TRANSIT);
	TAIAinvincibleOff* invincibleOff        = new TAIAinvincibleOff(TAI_NO_TRANSIT);
	TAIAsetTargetPointWorkObject* setTargetWorkObject = new TAIAsetTargetPointWorkObject(KABEKUIASTATE_Unk7);
	TAIAgoTargetPriorityFaceDir* targetFaceDir2       = new TAIAgoTargetPriorityFaceDir(KABEKUIASTATE_Unk8, KABEKUIAANIM_Unk6);
	TAIAattackWorkObjectKabekuiA* attackWorkObject    = new TAIAattackWorkObjectKabekuiA(KABEKUIASTATE_Unk4, KABEKUIAANIM_Unk6, 8);
	TAIAsearchWorkObject* searchWorkObject2           = new TAIAsearchWorkObject(KABEKUIASTATE_Unk2);
	TAIAdiveKabekuiA* diveKabekuiA                    = new TAIAdiveKabekuiA(KABEKUIASTATE_Unk9);
	TAIAappearKabekui* appearKabekui2                 = new TAIAappearKabekui(KABEKUIASTATE_Unk10, KABEKUIAANIM_Unk5, 30.0f, 0);
	TAIAsleepKabekuiA* sleepKabekuiA                  = new TAIAsleepKabekuiA(KABEKUIASTATE_Unk1);
	TAIAshadowOn* shadowOn                            = new TAIAshadowOn(TAI_NO_TRANSIT);
	TAIAshadowOff* shadowOff                          = new TAIAshadowOff(TAI_NO_TRANSIT);
	TAIAinWaterDamage* inWaterDamage                  = new TAIAinWaterDamage(TAI_NO_TRANSIT, 20.0f, 1);

	// STATE 0 - Dying
	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, dyingKabekui);
	state->setAction(j++, stop);
	setState(KABEKUIASTATE_Unk0, state);

	// STATE 1 -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, shadowOff);
	state->setAction(j++, invincibleOn);
	state->setAction(j++, setMotionSpeed);
	state->setAction(j++, visibleNavi);
	state->setAction(j++, searchWorkObject2);
	setState(KABEKUIASTATE_Unk1, state);

	// STATE 2 -
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, shadowOn);
	state->setAction(j++, appearKabekui1);
	setState(KABEKUIASTATE_Unk2, state);

	// STATE 3 -
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, invincibleOff);
	state->setAction(j++, setRandomTargetCircle);
	setState(KABEKUIASTATE_Unk3, state);

	// STATE 4 -
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, pressCheck);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, targetFaceDir1);
	state->setAction(j++, searchWorkObject1);
	state->setAction(j++, diveKabekuiA);
	setState(KABEKUIASTATE_Unk4, state);

	// STATE 5 -
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, crushDying);
	state->setAction(j++, stop);
	setState(KABEKUIASTATE_Unk5, state);

	// STATE 6 -
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, setTargetWorkObject);
	setState(KABEKUIASTATE_Unk6, state);

	// STATE 7 -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, pressCheck);
	state->setAction(j++, targetFaceDir2);
	setState(KABEKUIASTATE_Unk7, state);

	// STATE 8 -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, pressCheck);
	state->setAction(j++, attackWorkObject);
	setState(KABEKUIASTATE_Unk8, state);

	// STATE 9 -
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, invincibleOn);
	state->setAction(j++, appearKabekui2);
	state->setAction(j++, stop);
	setState(KABEKUIASTATE_Unk9, state);

	// STATE 10 -
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, shadowOff);
	state->setAction(j++, sleepKabekuiA);
	setState(KABEKUIASTATE_Unk10, state);

	u32 bad[2];
}

/*
 * --INFO--
 * Address:	801CB11C
 * Size:	0006FC
 */
void TAIkabekuiAAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	// lol, these are so just copy pasted
	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_KabekuiB]->mShape;
	addAnimation("tekis/kabekuiA/motion/dead.dca");

	addAnimation("tekis/kabekuiA/motion/damage.dca");

	addAnimation("tekis/kabekuiA/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/kabekuiA/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/kabekuiA/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiA/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiA/motion/move1.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiA/motion/move2.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiA/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/kabekuiA/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiA/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}

/*
 * --INFO--
 * Address:	801CB818
 * Size:	000058
 */
void TAIAshadowOff::start(Teki& teki)
{
	teki.clearTekiOption(Teki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
	teki.clearTekiOption(Teki::TEKI_OPTION_SHADOW_VISIBLE);
}

/*
 * --INFO--
 * Address:	801CB870
 * Size:	000058
 */
void TAIAshadowOn::start(Teki& teki)
{
	teki.setTekiOption(Teki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
	teki.setTekiOption(Teki::TEKI_OPTION_SHADOW_VISIBLE);
}

/*
 * --INFO--
 * Address:	801CB8C8
 * Size:	000018
 */
f32 TAIAsleepKabekuiA::getFrameMax(Teki& teki)
{
	return teki.getParameterF(KABEKUIAPF_Unk3);
}

/*
 * --INFO--
 * Address:	801CB8E0
 * Size:	000018
 */
f32 TAIAdiveKabekuiA::getFrameMax(Teki& teki)
{
	return teki.getParameterF(KABEKUIAPF_Unk2);
}

/*
 * --INFO--
 * Address:	801CB8F8
 * Size:	000020
 */
void TAIAattackWorkObjectKabekuiA::start(Teki& teki)
{
	TAIAattackWorkObject::start(teki);
}

/*
 * --INFO--
 * Address:	801CB918
 * Size:	000020
 */
bool TAIAattackWorkObjectKabekuiA::act(Teki& teki)
{
	TAIAattackWorkObject::act(teki);
}

/*
 * --INFO--
 * Address:	801CB938
 * Size:	000018
 */
f32 TAIAattackWorkObjectKabekuiA::getDamage(Teki& teki)
{
	return teki.getParameterF(KABEKUIAPF_Unk1);
}

/*
 * --INFO--
 * Address:	801CB950
 * Size:	000018
 */
f32 TAIAattackWorkObjectKabekuiA::getAttackPointRadius(Teki& teki)
{
	return teki.getParameterF(KABEKUIAPF_Unk0);
}

/*
 * --INFO--
 * Address:	801CB968
 * Size:	00016C
 */
void TAIAattackWorkObjectKabekuiA::attackEffect(Teki& teki)
{
	CollPart* mouthSlot = teki.mCollInfo->getSphere('slot');
	if (mouthSlot == nullptr) {
		return;
	}

	if (teki.mCurrentAnimEvent == KEY_Action0) {
		zen::particleGenerator* generator = effectMgr->create(
		    EffectMgr::EFF_Kabekui_EatBridgeA, mouthSlot->getChildAt(mouthSlot->getChildCount() - 1)->mCentre, nullptr, nullptr);
		if (generator != nullptr) {
			generator->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
		}

		teki.playEventSound(&teki, SE_WALLEAT_EAT);
		if (teki.aiCullable()) {
			playerState->mResultFlags.setOn(RESFLAG_Kabekui);
		}
	}

	if (teki.mCurrentAnimEvent != KEY_Action1 && teki.mCurrentAnimEvent == KEY_Action2) {
		zen::particleGenerator* generator = effectMgr->create(
		    EffectMgr::EFF_Kabekui_EatBridgeB, mouthSlot->getChildAt(mouthSlot->getChildCount() - 1)->mCentre, nullptr, nullptr);
		if (generator != nullptr) {
			generator->setOrientedNormalVector(Vector3f(1.0f, 0.0f, 0.0f));
		}
	}
}

/*
 * --INFO--
 * Address:	801CBAD4
 * Size:	000034
 */
void TAIAinvincibleOn::start(Teki& teki)
{
	teki.setTekiOption(Teki::TEKI_OPTION_INVINCIBLE);
}
