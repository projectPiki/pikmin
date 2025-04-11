#include "TAI/Tamago.h"
#include "TAI/Amove.h"
#include "teki.h"
#include "zen/Math.h"
#include "SoundMgr.h"
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
DEFINE_PRINT("TAItamago")

/*
 * --INFO--
 * Address:	801CFE0C
 * Size:	000084
 */
TAItamagoSoundTable::TAItamagoSoundTable()
    : PaniSoundTable(1)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_DORORO_EGG_CRASH);
	}
}

/*
 * --INFO--
 * Address:	801CFE90
 * Size:	0002F4
 */
TAItamagoParameters::TAItamagoParameters()
    : TekiParameters(TPI_COUNT, TAMAGOPF_COUNT)
{
	int j                           = TPF_COUNT;
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("羽化の最短時間（秒）", 0.0f, 1200.0f); // 'min emergence time (sec)'
	fParams[j++].init("羽化の最長時間（秒）", 0.0f, 1200.0f); // 'max emergence time (sec)'

	multiP->setF(TAMAGOPF_MinEmergenceTime, 10.0f);
	multiP->setF(TAMAGOPF_MaxEmergenceTime, 11.0f);

	multiP->setI(TPI_SpawnType, TEKI_Dororo);
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 2);
	multiP->setI(TPI_FlickPikiCount2, 5);
	multiP->setI(TPI_FlickPikiCount3, 10);
	multiP->setI(TPI_FlickDamageCount1, 3);
	multiP->setI(TPI_FlickDamageCount2, 3);
	multiP->setI(TPI_FlickDamageCount3, 3);
	multiP->setI(TPI_FlickDamageCount4, 3);
	multiP->setI(TPI_CullingType, CULLAI_NeverCullAI);

	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 1100.0f);
	multiP->setF(TPF_WalkVelocity, 20.0f);
	multiP->setF(TPF_RunVelocity, 120.0f);
	multiP->setF(TPF_TurnVelocity, 0.9948377f);
	multiP->setF(TPF_VisibleRange, 200.0f);
	multiP->setF(TPF_VisibleAngle, 180.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 200.0f);
	multiP->setF(TPF_AttackableAngle, 30.0f);
	multiP->setF(TPF_AttackRange, 30.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 5.0f);
	multiP->setF(TPF_DangerTerritoryRange, 150.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 120.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.2f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 100.0f);
	multiP->setF(TPF_LowerFlickPower, 100.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_LifeRecoverRate, 0.0f);
	multiP->setF(TPF_LifeGaugeOffset, 70.0f);
	multiP->setF(TPF_ShadowSize, 50.0f);
	multiP->setF(TPF_TraceAngle, 60.0f);
	multiP->setF(TPF_SpawnDistance, 0.0f);
	multiP->setF(TPF_SpawnHeight, 0.0f);
	multiP->setF(TPF_SpawnVelocity, 0.0f);
}

/*
 * --INFO--
 * Address:	801D0184
 * Size:	0002DC
 */
TAItamagoStrategy::TAItamagoStrategy()
    : YaiStrategy(TAMAGOSTATE_COUNT, TAMAGOSTATE_Wait)
{
	TAIAdeadCheck* deadCheck            = new TAIAdeadCheck(TAMAGOSTATE_Dead);
	TAIAdyingTamago* dying              = new TAIAdyingTamago(TAI_NO_TRANSIT, 0);
	TAIAdamage* damage                  = new TAIAdamage(TAI_NO_TRANSIT, false);
	TAIAstop* stop                      = new TAIAstop(TAI_NO_TRANSIT);
	TAIAtimerReactionTamago* timerReact = new TAIAtimerReactionTamago(TAMAGOSTATE_Hatch);
	TAIAhatch* hatch                    = new TAIAhatch(TAI_NO_TRANSIT, TAMAGOSTATE_Dead);
	TAIAcountStartTamago* countStart    = new TAIAcountStartTamago(TAMAGOSTATE_CountDown);

	// DEAD STATE - egg dead.
	TaiState* state = new TaiState(2);
	int j           = 0;
	state->setAction(j++, dying);
	state->setAction(j++, stop);
	setState(TAMAGOSTATE_Dead, state);

	// WAIT STATE - chillin waiting for something to happen
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);  // if dead, transit to dead
	state->setAction(j++, countStart); // on trigger, transit to countdown
	setState(TAMAGOSTATE_Wait, state);

	// COUNTDOWN STATE - something came close enough, waiting to hatch
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);  // if dead, transit to dead
	state->setAction(j++, timerReact); // on timer finish, transit to hatch
	setState(TAMAGOSTATE_CountDown, state);

	// HATCH STATE - it's alive!
	state = new TaiState(1);
	j     = 0;
	state->setAction(j++, hatch); // once hatched, transit to dead
	setState(TAMAGOSTATE_Hatch, state);
}

/*
 * --INFO--
 * Address:	801D0460
 * Size:	0006FC
 */
void TAItamagoAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	// why.
	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_KabekuiB]->mShape;
	addAnimation("tekis/tamago/motion/dead.dca");

	addAnimation("tekis/tamago/motion/damage.dca");

	addAnimation("tekis/tamago/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/tamago/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/tamago/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/tamago/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/tamago/motion/move1.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/tamago/motion/move2.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/tamago/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/tamago/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/tamago/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}
