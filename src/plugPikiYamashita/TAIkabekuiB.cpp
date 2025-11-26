#include "DebugLog.h"
#include "SoundID.h"
#include "TAI/Ajudge.h"
#include "TAI/Amotion.h"
#include "TAI/Amove.h"
#include "TAI/KabekuiB.h"

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
DEFINE_PRINT("TAIkabekuiB")

/*
 * --INFO--
 * Address:	801CBB68
 * Size:	000084
 */
TAIkabekuiBSoundTable::TAIkabekuiBSoundTable()
    : PaniSoundTable(3)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_WALLEAT_WALK);
	}
}

/*
 * --INFO--
 * Address:	801CBBEC
 * Size:	0003C0
 */
TAIkabekuiBParameters::TAIkabekuiBParameters()
    : TekiParameters(TPI_COUNT, TAIkabekuiBFloatParms::COUNT)
{
	int j                           = TAIkabekuiBFloatParms::BridgeAttackRange;
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("壁食いポイントの大きさ", 0.0f, 1000.0f); // 'Size of wall bite point'
	fParams[j++].init("壁食いダメージ", 0.0f, 100.0f);          // 'wall eating damage'
	fParams[j++].init("潜るまでの時間（秒）", 0.0f, 100.0f);    // 'Time until diving (sec)'
	fParams[j++].init("スリープ時間（秒）", 0.0f, 100.0f);      // 'Sleep Time (seconds)'
	fParams[j++].init("ピキ攻撃判定サイズ", 0.0f, 100.0f);      // 'Piki attack detection size'
	fParams[j++].init("ナビ攻撃判定サイズ", 0.0f, 100.0f);      // 'Navi attack detection size'

	multiP->setF(TAIkabekuiBFloatParms::BridgeAttackRange, 8.0f);
	multiP->setF(TAIkabekuiBFloatParms::BridgeDamage, 1.0f);
	multiP->setF(TAIkabekuiBFloatParms::TimeUntilBurrow, 3.0f);
	multiP->setF(TAIkabekuiBFloatParms::MaxSleepTime, 3.0f);
	multiP->setF(TAIkabekuiBFloatParms::PikiAttackRange, 15.0f);
	multiP->setF(TAIkabekuiBFloatParms::NaviAttackRange, 15.0f);

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

	multiP->setF(TPF_WalkVelocity, 45.0f);
	multiP->setF(TPF_RunVelocity, 120.0f);
	multiP->setF(TPF_TurnVelocity, 1.5009831f);

	multiP->setF(TPF_VisibleRange, 150.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);

	multiP->setF(TPF_AttackableRange, 80.0f);
	multiP->setF(TPF_AttackableAngle, 60.0f);
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
 * Address:	801CBFAC
 * Size:	000E3C
 */
TAIkabekuiBStrategy::TAIkabekuiBStrategy()
    : YaiStrategy(TAIkabekuiBStateID::COUNT, TAIkabekuiBStateID::Waiting)
{
	TAIAdeadCheck* deadCheck       = new TAIAdeadCheck(TAIkabekuiBStateID::Dying);
	TAIAdyingKabekui* dyingKabekui = new TAIAdyingKabekui(TAI_NO_TRANSIT, TAIkabekuiBMotionID::Unk0, EffectMgr::EFF_SmokeRing_S);
	TAIAdamage* damage             = new TAIAdamage(TAI_NO_TRANSIT, true);
	TAIAstop* stop                 = new TAIAstop(TAI_NO_TRANSIT);

	new TAIArandomWalk(TAI_NO_TRANSIT, TAIkabekuiBMotionID::Unk6); // unused

	TAIAsetMotionSpeed* setMotionSpeedAppear = new TAIAsetMotionSpeed(TAI_NO_TRANSIT, TAIkabekuiBMotionID::Unk4, 0.0f);
	TAIAvisibleNavi* visibleNaviThenAppear   = new TAIAvisibleNavi(TAIkabekuiBStateID::Appearing);

	new TAIAvisiblePiki(TAIkabekuiBStateID::Appearing); // unused

	TAIAappearKabekui* appearThenSetupMove = new TAIAappearKabekui(TAIkabekuiBStateID::MovingSetup, TAIkabekuiBMotionID::Unk4, 30.0f, true);
	TAIAsetTargetPointCircleRandom* setTargetThenMove = new TAIAsetTargetPointCircleRandom(TAIkabekuiBStateID::MovingBridge);
	TAIAgoTargetPriorityFaceDir* turnToTargetThenSetup
	    = new TAIAgoTargetPriorityFaceDir(TAIkabekuiBStateID::MovingSetup, TAIkabekuiBMotionID::Unk6);

	TAIAvisibleNavi* visibleNavi2                     = new TAIAvisibleNavi(TAIkabekuiBStateID::MovingPiki);
	TAIAvisiblePiki* visiblePiki                      = new TAIAvisiblePiki(TAIkabekuiBStateID::MovingPiki);
	TAIAapproachTargetPriorityFaceDir* approachTarget = new TAIAapproachTargetPriorityFaceDir(TAI_NO_TRANSIT, TAIkabekuiBMotionID::Unk6);
	TAIAattackableTarget* attackableTarget            = new TAIAattackableTarget(TAIkabekuiBStateID::BiteAttack);
	TAIAunvisibleTarget* unvisibleTarget              = new TAIAunvisibleTarget(TAIkabekuiBStateID::MovingSetup);
	TAIAbiteForKabekuiB* kabekuiBite
	    = new TAIAbiteForKabekuiB(TAIkabekuiBStateID::BiteChewing, TAIkabekuiBStateID::MovingSetup, TAIkabekuiBMotionID::Unk10);
	TAIAeatPiki* eatPiki             = new TAIAeatPiki(TAIkabekuiBStateID::MovingSetup, TAIkabekuiBMotionID::Unk11);

	TAIAhitCheckFlyingPiki* pressCheck = new TAIAhitCheckFlyingPiki(TAIkabekuiBStateID::CrushDying);
	TAIAdyingCrushKabekui* crushDying  = new TAIAdyingCrushKabekui(TAI_NO_TRANSIT, TAIkabekuiBMotionID::Unk1, EffectMgr::EFF_SmokeRing_S);
	TAIAsearchWorkObject* searchWorkObjectThenChase   = new TAIAsearchWorkObject(TAIkabekuiBStateID::ChasingSetup);
	TAIAinvincibleOn* invincibleOn                    = new TAIAinvincibleOn(TAI_NO_TRANSIT);
	TAIAinvincibleOff* invincibleOff                  = new TAIAinvincibleOff(TAI_NO_TRANSIT);
	TAIAsetTargetPointWorkObject* setTargetWorkObject = new TAIAsetTargetPointWorkObject(TAIkabekuiBStateID::Chasing);
	TAIAgoTargetPriorityFaceDir* targetFaceDirThenEat
	    = new TAIAgoTargetPriorityFaceDir(TAIkabekuiBStateID::EatingBridge, TAIkabekuiBMotionID::Unk6);

	TAIAattackWorkObjectKabekuiB* attackWorkObject
	    = new TAIAattackWorkObjectKabekuiB(TAIkabekuiBStateID::MovingBridge, TAIkabekuiBMotionID::Unk6, 8);

	TAIAsearchWorkObject* searchWorkObjectThenAppear = new TAIAsearchWorkObject(TAIkabekuiBStateID::Appearing);
	TAIAdiveKabekuiB* diveKabekuiB                   = new TAIAdiveKabekuiB(TAIkabekuiBStateID::Burrowing);
	TAIAappearKabekui* burrowKabekui = new TAIAappearKabekui(TAIkabekuiBStateID::WaitingSetup, TAIkabekuiBMotionID::Unk5, 30.0f, false);
	TAIAsleepKabekuiB* sleepKabekuiB = new TAIAsleepKabekuiB(TAIkabekuiBStateID::Waiting);
	TAIAshadowOn* shadowOn           = new TAIAshadowOn(TAI_NO_TRANSIT);
	TAIAshadowOff* shadowOff         = new TAIAshadowOff(TAI_NO_TRANSIT);
	TAIAinWaterDamage* inWaterDamage = new TAIAinWaterDamage(TAI_NO_TRANSIT, 20.0f, true);

	// STATE 0 - Dying
	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, dyingKabekui);
	state->setAction(j++, stop);
	setState(TAIkabekuiBStateID::Dying, state);

	// STATE 1 - Waiting
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, shadowOff);
	state->setAction(j++, invincibleOn);
	state->setAction(j++, setMotionSpeedAppear);
	state->setAction(j++, visibleNaviThenAppear);
	state->setAction(j++, searchWorkObjectThenAppear);
	setState(TAIkabekuiBStateID::Waiting, state);

	// STATE 2 - Appearing
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, shadowOn);
	state->setAction(j++, appearThenSetupMove);
	setState(TAIkabekuiBStateID::Appearing, state);

	// STATE 3 - MovingSetup
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, invincibleOff);
	state->setAction(j++, setTargetThenMove);
	setState(TAIkabekuiBStateID::MovingSetup, state);

	// STATE 4 - MovingBridge
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, pressCheck);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, turnToTargetThenSetup);
	state->setAction(j++, visiblePiki);
	state->setAction(j++, visibleNavi2);
	state->setAction(j++, searchWorkObjectThenChase);
	state->setAction(j++, diveKabekuiB);
	setState(TAIkabekuiBStateID::MovingBridge, state);

	// STATE 5 - MovingPiki
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, pressCheck);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, approachTarget);
	state->setAction(j++, attackableTarget);
	state->setAction(j++, unvisibleTarget);
	state->setAction(j++, visiblePiki);
	state->setAction(j++, visibleNavi2);
	setState(TAIkabekuiBStateID::MovingPiki, state);

	// STATE 6 - BiteAttack
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, pressCheck);
	state->setAction(j++, kabekuiBite);
	setState(TAIkabekuiBStateID::BiteAttack, state);

	// STATE 7 - BiteChewing
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, stop);
	state->setAction(j++, pressCheck);
	state->setAction(j++, eatPiki);
	setState(TAIkabekuiBStateID::BiteChewing, state);

	// STATE 8 - CrushDying
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, crushDying);
	state->setAction(j++, stop);
	setState(TAIkabekuiBStateID::CrushDying, state);

	// STATE 9 - ChasingSetup
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, setTargetWorkObject);
	setState(TAIkabekuiBStateID::ChasingSetup, state);

	// STATE 10 - Chasing
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, visiblePiki);
	state->setAction(j++, visibleNavi2);
	state->setAction(j++, pressCheck);
	state->setAction(j++, targetFaceDirThenEat); // after reaching the target, start eating the bridge
	setState(TAIkabekuiBStateID::Chasing, state);

	// STATE 11 - EatingBridge
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, visiblePiki);
	state->setAction(j++, visibleNavi2);
	state->setAction(j++, attackWorkObject); // eat that bridge!
	setState(TAIkabekuiBStateID::EatingBridge, state);

	// STATE 12 - Burrowing
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, invincibleOn);
	state->setAction(j++, burrowKabekui);
	state->setAction(j++, stop);
	setState(TAIkabekuiBStateID::Burrowing, state);

	// STATE 13 - WaitingSetup
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, shadowOff);
	state->setAction(j++, sleepKabekuiB);
	setState(TAIkabekuiBStateID::WaitingSetup, state);

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	801CCDE8
 * Size:	0006FC
 */
void TAIkabekuiBAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	// lol, these are so just copy pasted
	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_KabekuiB]->mShape;
	addAnimation("tekis/kabekuiB/motion/dead.dca");

	addAnimation("tekis/kabekuiB/motion/damage.dca");

	addAnimation("tekis/kabekuiB/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/kabekuiB/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/kabekuiB/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiB/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiB/motion/move1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiB/motion/move2.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiB/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/kabekuiB/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/kabekuiB/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}
