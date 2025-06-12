#include "TAI/Otama.h"
#include "TAI/Ajudge.h"
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
DEFINE_PRINT("TAIotama")

/*
 * --INFO--
 * Address:	801EAA70
 * Size:	000084
 */
TAIotamaSoundTable::TAIotamaSoundTable()
    : PaniSoundTable(3)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_OTAMA_JUMP);
	}
}

/*
 * --INFO--
 * Address:	801EAAF4
 * Size:	00033C
 */
TAIotamaParameters::TAIotamaParameters()
    : TekiParameters(TPI_COUNT, TAIotamaFloatParams::COUNT)
{
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	int j                           = TPF_COUNT;
	fParams[j++].init("ウエイト最短時間（秒）", 0.0f, 1200.0f); // 'min wait time (sec)'
	fParams[j++].init("ウエイト最長時間（秒）", 0.0f, 1200.0f); // 'max wait time (sec)'

	multiP->setF(TAIotamaFloatParams::MinWaitTime, 1.0f);
	multiP->setF(TAIotamaFloatParams::MaxWaitTime, 5.0f);

	multiP->setI(TPI_SpawnType, TEKI_NULL);
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 2);
	multiP->setI(TPI_FlickPikiCount2, 5);
	multiP->setI(TPI_FlickPikiCount3, 10);
	multiP->setI(TPI_FlickDamageCount1, 3);
	multiP->setI(TPI_FlickDamageCount2, 3);
	multiP->setI(TPI_FlickDamageCount3, 3);
	multiP->setI(TPI_FlickDamageCount4, 3);
	multiP->setI(TPI_CullingType, CULLAI_CullAIOffCamera);
	multiP->setI(TPI_CarcassSize, 2);
	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);

	multiP->setF(TPF_CorpseSize, 10.0f);
	multiP->setF(TPF_CorpseHeight, 10.0f);
	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 50.0f);

	multiP->setF(TPF_WalkVelocity, 70.0f);
	multiP->setF(TPF_RunVelocity, 180.0f);
	multiP->setF(TPF_TurnVelocity, 200.0f * PI / 180.0f);

	multiP->setF(TPF_VisibleRange, 200.0f);
	multiP->setF(TPF_VisibleAngle, 360.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);

	multiP->setF(TPF_AttackableRange, 40.0f);
	multiP->setF(TPF_AttackableAngle, 30.0f);
	multiP->setF(TPF_AttackRange, 10.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 5.0f);

	multiP->setF(TPF_DangerTerritoryRange, 250.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 80.0f);

	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);

	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 70.0f);
	multiP->setF(TPF_LowerFlickPower, 70.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);

	multiP->setF(TPF_LifeRecoverRate, 0.001f);
	multiP->setF(TPF_LifeGaugeOffset, 20.0f);

	multiP->setF(TPF_ShadowSize, 15.0f);
	multiP->setF(TPF_TraceAngle, 60.0f);

	multiP->setF(TPF_SpawnDistance, 0.0f);
	multiP->setF(TPF_SpawnHeight, 0.0f);
	multiP->setF(TPF_SpawnVelocity, 0.0f);
	multiP->setF(TPF_RippleScale, 1.0f);

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	801EAE30
 * Size:	000530
 */
TAIotamaStrategy::TAIotamaStrategy()
    : YaiStrategy(TAIotamaStateID::COUNT, TAIotamaStateID::Wait)
{
	TAIAdeadCheck* deadCheck              = new TAIAdeadCheck(TAIotamaStateID::Dead);
	TAIAdying* dying                      = new TAIAdying(TAI_NO_TRANSIT, TAIotamaMotionID::Unk0);
	TAIAdamage* damage                    = new TAIAdamage(TAI_NO_TRANSIT, false);
	TAIAstop* stop                        = new TAIAstop(TAI_NO_TRANSIT);
	TAIAwaitOtama* wait                   = new TAIAwaitOtama(TAIotamaStateID::SetTarget, TAIotamaMotionID::Unk2);
	TAIAsetTargetOtama* setTarget         = new TAIAsetTargetOtama(TAIotamaStateID::GoTarget, TAIotamaStateID::AppealTarget);
	TAIAgoTargetPriorityFaceDir* goTarget = new TAIAgoTargetPriorityFaceDir(TAIotamaStateID::Wait, TAIotamaMotionID::Unk6);
	TAIAappealOtama* appeal1              = new TAIAappealOtama(TAIotamaStateID::GoTarget, TAIotamaMotionID::Unk4);
	TAIAvisibleNavi* visibleNavi          = new TAIAvisibleNavi(TAIotamaStateID::AppealRun);
	TAIAappealOtama* appeal2              = new TAIAappealOtama(TAIotamaStateID::RunAway, TAIotamaMotionID::Unk4);
	TAIAtimerReaction* timer              = new TAIAtimerReaction(TAIotamaStateID::SetTarget, 3.0f);
	TAIArunAwayOtama* runAway             = new TAIArunAwayOtama(TAIotamaStateID::Wait, TAIotamaMotionID::Unk6);

	// STATE 0 - Dead
	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, dying);
	state->setAction(j++, stop);
	setState(TAIotamaStateID::Dead, state);

	// STATE 1 - Wait
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, wait);        // after waiting enough time, pick a new target
	state->setAction(j++, visibleNavi); // if navi spotted, appeal 2 (jump then run away)
	setState(TAIotamaStateID::Wait, state);

	// STATE 2 - Set Target
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, setTarget); // after setting target, either go target (95% chance) or jump THEN go target (5% chance)
	setState(TAIotamaStateID::SetTarget, state);

	// STATE 4 - Appeal (jump then go to target)
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, appeal1); // after jump, go target
	setState(TAIotamaStateID::AppealTarget, state);

	// STATE 3 - Go Target
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, goTarget);    // after reaching target, wait
	state->setAction(j++, visibleNavi); // if navi spotted, appeal 2 (jump then run away)
	state->setAction(j++, timer);       // after x time, set new target
	setState(TAIotamaStateID::GoTarget, state);

	// STATE 5 - Appeal (jump then run away)
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, appeal2); // after jump, run away
	setState(TAIotamaStateID::AppealRun, state);

	// STATE 6 - Run Away
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, runAway); // after running away, wait
	setState(TAIotamaStateID::RunAway, state);
}

/*
 * --INFO--
 * Address:	801EB360
 * Size:	0006FC
 */
void TAIotamaAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_KabekuiB]->mShape;
	addAnimation("tekis/otama/motion/dead.dca");

	addAnimation("tekis/otama/motion/damage.dca");

	addAnimation("tekis/otama/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/otama/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/otama/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/otama/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/otama/motion/move1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/otama/motion/move2.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/otama/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/otama/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/otama/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}
