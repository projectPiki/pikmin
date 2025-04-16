#include "TAI/KabekuiA.h"
#include "sysNew.h"
#include "DebugLog.h"
#include "SoundID.h"
#include "TAI/Amove.h"
#include "TAI/Ajudge.h"

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
    : TekiParameters(TPI_COUNT, TAIkabekuiAFloatParms::COUNT)
{
	int j                           = TAIkabekuiAFloatParms::BridgeAttackRange;
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("壁食いポイントの大きさ", 0.0f, 1000.0f); // 'Size of wall bite point'
	fParams[j++].init("壁食いダメージ", 0.0f, 100.0f);          // 'wall eating damage'
	fParams[j++].init("潜るまでの時間（秒）", 0.0f, 100.0f);    // 'Time until diving (sec)'
	fParams[j++].init("スリープ時間（秒）", 0.0f, 100.0f);      // 'Sleep Time (seconds)'

	multiP->setF(TAIkabekuiAFloatParms::BridgeAttackRange, 8.0f);
	multiP->setF(TAIkabekuiAFloatParms::BridgeDamage, 0.00000001f);
	multiP->setF(TAIkabekuiAFloatParms::TimeUntilBurrow, 3.0f);
	multiP->setF(TAIkabekuiAFloatParms::MaxSleepTime, 3.0f);

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
    : YaiStrategy(TAIkabekuiAStateID::COUNT, TAIkabekuiAStateID::Waiting) // TODO: fix
{
	TAIAdeadCheck* deadCheck       = new TAIAdeadCheck(TAIkabekuiAStateID::Dying);
	TAIAdyingKabekui* dyingKabekui = new TAIAdyingKabekui(TAI_NO_TRANSIT, TAIkabekuiAMotionID::Dead, EffectMgr::EFF_SmokeRing_S);
	TAIAdamage* damage             = new TAIAdamage(TAI_NO_TRANSIT, 1);
	TAIAstop* stop                 = new TAIAstop(TAI_NO_TRANSIT);

	new TAIArandomWalk(TAI_NO_TRANSIT, TAIkabekuiAMotionID::Move); // unused

	TAIAsetMotionSpeed* setMotionSpeedAppear = new TAIAsetMotionSpeed(TAI_NO_TRANSIT, TAIkabekuiAMotionID::Appear, 0.0f);
	TAIAvisibleNavi* visibleNaviThenAppear   = new TAIAvisibleNavi(TAIkabekuiAStateID::Appearing);

	new TAIAvisiblePiki(TAIkabekuiAStateID::Appearing); // unused

	TAIAappearKabekui* appearThenSetupMove = new TAIAappearKabekui(TAIkabekuiAStateID::MovingSetup, TAIkabekuiAMotionID::Appear, 30.0f, 1);
	TAIAsetTargetPointCircleRandom* setTargetThenMove = new TAIAsetTargetPointCircleRandom(TAIkabekuiAStateID::Moving);
	TAIAgoTargetPriorityFaceDir* turnToTargetThenSetup
	    = new TAIAgoTargetPriorityFaceDir(TAIkabekuiAStateID::MovingSetup, TAIkabekuiAMotionID::Move);

	TAIAhitCheckFlyingPiki* pressCheck = new TAIAhitCheckFlyingPiki(TAIkabekuiAStateID::CrushDying);
	TAIAdyingCrushKabekui* crushDying  = new TAIAdyingCrushKabekui(TAI_NO_TRANSIT, TAIkabekuiAMotionID::Press, EffectMgr::EFF_SmokeRing_S);
	TAIAsearchWorkObject* searchWorkObjectThenChase   = new TAIAsearchWorkObject(TAIkabekuiAStateID::ChasingSetup);
	TAIAinvincibleOn* invincibleOn                    = new TAIAinvincibleOn(TAI_NO_TRANSIT);
	TAIAinvincibleOff* invincibleOff                  = new TAIAinvincibleOff(TAI_NO_TRANSIT);
	TAIAsetTargetPointWorkObject* setTargetWorkObject = new TAIAsetTargetPointWorkObject(TAIkabekuiAStateID::Chasing);
	TAIAgoTargetPriorityFaceDir* targetFaceDirThenEat
	    = new TAIAgoTargetPriorityFaceDir(TAIkabekuiAStateID::Eating, TAIkabekuiAMotionID::Move);

	TAIAattackWorkObjectKabekuiA* attackWorkObject
	    = new TAIAattackWorkObjectKabekuiA(TAIkabekuiAStateID::Moving, TAIkabekuiAMotionID::Move, 8);

	TAIAsearchWorkObject* searchWorkObjectThenAppear = new TAIAsearchWorkObject(TAIkabekuiAStateID::Appearing);
	TAIAdiveKabekuiA* diveKabekuiA                   = new TAIAdiveKabekuiA(TAIkabekuiAStateID::Burrowing);
	TAIAappearKabekui* burrowKabekui = new TAIAappearKabekui(TAIkabekuiAStateID::WaitingSetup, TAIkabekuiAMotionID::Burrow, 30.0f, 0);
	TAIAsleepKabekuiA* sleepKabekuiA = new TAIAsleepKabekuiA(TAIkabekuiAStateID::Waiting);
	TAIAshadowOn* shadowOn           = new TAIAshadowOn(TAI_NO_TRANSIT);
	TAIAshadowOff* shadowOff         = new TAIAshadowOff(TAI_NO_TRANSIT);
	TAIAinWaterDamage* inWaterDamage = new TAIAinWaterDamage(TAI_NO_TRANSIT, 20.0f, 1);

	// STATE 0 - Dying
	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, dyingKabekui);
	state->setAction(j++, stop);
	setState(TAIkabekuiAStateID::Dying, state);

	// STATE 1 - Waiting
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, shadowOff);
	state->setAction(j++, invincibleOn);
	state->setAction(j++, setMotionSpeedAppear);       // set animation speed to zero while waiting
	state->setAction(j++, visibleNaviThenAppear);      // if there's a navi, transit to Appearing
	state->setAction(j++, searchWorkObjectThenAppear); // if there's a bridge, transit to Appearing
	setState(TAIkabekuiAStateID::Waiting, state);

	// STATE 2 - Appearing
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, shadowOn);
	state->setAction(j++, appearThenSetupMove); // Play the appearing animation, then setup Moving
	setState(TAIkabekuiAStateID::Appearing, state);

	// STATE 3 - MovingSetup
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, invincibleOff);
	state->setAction(j++, setTargetThenMove); // set a random target, then transit to Moving
	setState(TAIkabekuiAStateID::MovingSetup, state);

	// STATE 4 - Moving
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, pressCheck);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, turnToTargetThenSetup);     // turn to the current target, and if its reached, go back to MovingSetup
	state->setAction(j++, searchWorkObjectThenChase); // if there's a work object, setup Chasing
	state->setAction(j++, diveKabekuiA);              // burrow back underground after 3 seconds in this state
	setState(TAIkabekuiAStateID::Moving, state);

	// STATE 5 - CrushDying
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, crushDying);
	state->setAction(j++, stop);
	setState(TAIkabekuiAStateID::CrushDying, state);

	// STATE 6 - ChasingSetup
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, setTargetWorkObject);
	setState(TAIkabekuiAStateID::ChasingSetup, state);

	// STATE 7 - Chasing
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, pressCheck);
	state->setAction(j++, targetFaceDirThenEat); // after reaching the target, start eating the bridge
	setState(TAIkabekuiAStateID::Chasing, state);

	// STATE 8 - Eating
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, inWaterDamage);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, pressCheck);
	state->setAction(j++, attackWorkObject); // eat that bridge!
	setState(TAIkabekuiAStateID::Eating, state);

	// STATE 9 -
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, invincibleOn);
	state->setAction(j++, burrowKabekui);
	state->setAction(j++, stop);
	setState(TAIkabekuiAStateID::Burrowing, state);

	// STATE 10 -
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, shadowOff);
	state->setAction(j++, sleepKabekuiA); // go back to waiting after 3 seconds
	setState(TAIkabekuiAStateID::WaitingSetup, state);

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
