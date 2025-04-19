#include "TAI/Miurin.h"
#include "TAI/Aeffect.h"
#include "SoundMgr.h"
#include "Pcam/CameraManager.h"
#include "ComplexCreature.h"
#include "PikiHeadItem.h"
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
DEFINE_PRINT("TAImiurin")

/**
 * @brief TODO
 */
struct TAIAangryMiurin : public TAIAmotion {
	TAIAangryMiurin(int nextState, int motionID)
	    : TAIAmotion(nextState, motionID)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAmotion::start(teki);
		teki.setFrameCounter(0.0f);
		InteractFlick& flick = InteractFlick(&teki, teki.getParameterF(TPF_UpperFlickPower), teki.getParameterF(TPF_UpperAttackPower),
		                                     teki.mFaceDirection + PI);
		teki.flick(flick, flick);
		cameraMgr->startVibrationEvent(3, teki.getPosition());
		rumbleMgr->start(11, 0, teki.getPosition());
	}
	virtual bool act(Teki& teki) // _10
	{
		bool res = false;
		TAIAmotion::act(teki);
		teki.addFrameCounter(gsys->getFrameTime());
		Navi* navi        = naviMgr->getNavi();
		teki.mTargetAngle = teki.calcTargetDirection(navi->getPosition());

		if (teki.mCurrentAnimEvent == KEY_Action0) {
			Vector3f pos(teki.getPosition());
			pos.y += 50.0f;
			effectMgr->create(EffectMgr::EFF_Miurin_A01, pos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Miurin_A02, pos, nullptr, nullptr);
		}

		if (teki.getFrameCounter() < 0.5f) {
			teki.turnToward(teki.mTargetAngle, 4.0f * PI / 3.0f);
		}

		if (teki.mCurrentAnimEvent == KEY_Finished) {
			res = true;
		}

		PRINT("fake", navi ? "fake" : "fake");
		return res;
	}
	virtual f32 getFlickDirection(Teki& teki) // _1C
	{
		return teki.mFaceDirection + PI;
	}

	// _04     = VTBL
	// _00-_0C = TAIAmotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckNaviMiurin : public TAIAinsideTerritoryRangeNavi {
	TAIAcheckNaviMiurin(int nextState)
	    : TAIAinsideTerritoryRangeNavi(nextState)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		bool res = false;
		if (zen::Rand(100.0f) < teki.getParameterF(TAImiurinFloatParams::CheckNaviPercent)) {
			res = TAIAinsideTerritoryRangeNavi::act(teki);
			if (res) {
				PRINT("watch Navi \n");
			}
		}

		return res;
	}

	// _04     = VTBL
	// _00-_08 = TAIAinsideTerritoryRangeNavi?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckFlowerPikmin : public TaiAction {
	TAIAcheckFlowerPikmin(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		bool res        = false;
		int flowerCount = 0;

		Iterator iter(itemMgr->getPikiHeadMgr());
		CI_LOOP(iter)
		{
			PikiHeadItem* sprout = (PikiHeadItem*)*iter;
			if (sprout->mFlowerStage == Flower
			    && teki.getPosition().distance(sprout->getPosition()) < teki.getParameterF(TPF_SafetyTerritoryRange)) {
				flowerCount++;
			}

			if (flowerCount >= teki.getParameterI(TAImiurinIntParams::RelaxingFlowerNum)) {
				PRINT("Flower pikmins are more than %d.\n", teki.getParameterI(TAImiurinIntParams::RelaxingFlowerNum));
				res = true;
				break;
			}
		}

		if (res) {
			PRINT("SATISFY! \n");
		}

		return res;
	}

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/*
 * --INFO--
 * Address:	801D624C
 * Size:	000084
 */
TAImiurinSoundTable::TAImiurinSoundTable()
    : PaniSoundTable(3)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_MIURIN_WALK);
	}
}

/*
 * --INFO--
 * Address:	801D62D0
 * Size:	000404
 */
TAImiurinParameters::TAImiurinParameters()
    : TekiParameters(TAImiurinIntParams::COUNT, TAImiurinFloatParams::COUNT)
{
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	int j                           = TPI_COUNT;
	iParams[j++].init("最大引っ付きピキ", 0, 100);             // 'max stick piki'
	iParams[j++].init("振り払い発生打撃数", 0, 100);           // 'number of shake-off hits'
	iParams[j++].init("リラックスする花ピクミンの数", 0, 100); // 'relaxing flower pikmin number'

	j = TPF_COUNT;
	fParams[j++].init("リラックスの長さ（秒）", 0.0f, 60.0f);  // 'relax length (sec)'
	fParams[j++].init("目を回す時間（秒）", 0.0f, 60.0f);      // 'eye rolling time (sec)'
	fParams[j++].init("ナビをチェックする割合", 0.0f, 100.0f); // 'checking navi percent'
	fParams[j++].init("怒り時の回転速度", 0.0f, PI);           // 'angry rotation speed'

	multiP->setI(TAImiurinIntParams::MaxStickPiki, 10);
	multiP->setI(TAImiurinIntParams::ShakeOffHitCount, 30);
	multiP->setI(TAImiurinIntParams::RelaxingFlowerNum, 10);

	multiP->setF(TAImiurinFloatParams::RelaxTime, 10.0f);
	multiP->setF(TAImiurinFloatParams::EyeRollTime, 10.0f);
	multiP->setF(TAImiurinFloatParams::CheckNaviPercent, 50.0f);
	multiP->setF(TAImiurinFloatParams::AngryRotationSpeed, 5.0f * PI / 6.0f);

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
	multiP->setI(TPI_CarcassSize, 0);

	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 15000.0f);

	multiP->setF(TPF_WalkVelocity, 30.0f);
	multiP->setF(TPF_RunVelocity, 120.0f);
	multiP->setF(TPF_TurnVelocity, 50.0f * PI / 180.0f);

	multiP->setF(TPF_VisibleRange, 400.0f);
	multiP->setF(TPF_VisibleAngle, 180.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);

	multiP->setF(TPF_AttackableRange, 70.0f);
	multiP->setF(TPF_AttackableAngle, 40.0f);
	multiP->setF(TPF_AttackRange, 20.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 5.0f);

	multiP->setF(TPF_DangerTerritoryRange, 300.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 200.0f);

	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.15f);

	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 100.0f);
	multiP->setF(TPF_LowerFlickPower, 0.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);

	multiP->setF(TPF_LifeRecoverRate, 0.0f);
	multiP->setF(TPF_LifeGaugeOffset, 42.0f);

	multiP->setF(TPF_ShadowSize, 50.0f);
	multiP->setF(TPF_TraceAngle, 60.0f);

	multiP->setF(TPF_CorpseSize, 70.0f);
	multiP->setF(TPF_CorpseHeight, 50.0f);
	multiP->setF(TPF_SpawnDistance, 0.0f);
	multiP->setF(TPF_SpawnHeight, 20.0f);
	multiP->setF(TPF_SpawnVelocity, 0.0f);
}

/*
 * --INFO--
 * Address:	801D66D4
 * Size:	0019CC
 */
TAImiurinStrategy::TAImiurinStrategy()
    : YaiStrategy(TAImiurinStateID::COUNT, TAImiurinStateID::Unk1)
{
	TAIAinitMiurin* init       = new TAIAinitMiurin(TAImiurinStateID::Unk3);
	TAIAdeadCheck* deadCheck   = new TAIAdeadCheck(TAImiurinStateID::Unk0);
	TAIAdyingMiurin* dying     = new TAIAdyingMiurin(TAI_NO_TRANSIT, TAImiurinMotionID::Unk0);
	TAIAdamage* damage         = new TAIAdamage(TAI_NO_TRANSIT, true);
	TAIAstop* stop             = new TAIAstop(TAI_NO_TRANSIT);
	TAIAreserveMotion* motion1 = new TAIAreserveMotion(TAI_NO_TRANSIT, TAImiurinMotionID::Unk2);
	TAIAeffCloudOfDust* effCloud1
	    = new TAIAeffCloudOfDust(TAI_NO_TRANSIT, EffectMgr::EFF_SmokeRing_S, SE_MIURIN_WALK, 15, -0.5f, 2, 'asi1', 'asi2', 0, 0);
	TAIAeffCloudOfDust* effCloud2
	    = new TAIAeffCloudOfDust(TAI_NO_TRANSIT, EffectMgr::EFF_SmokeRing_M, SE_KABUTO_WALK, 15, -0.5f, 2, 'asi1', 'asi2', 0, 0);
	TAIAturnFocusCreatureMiurin* turnFocus1
	    = new TAIAturnFocusCreatureMiurin(TAImiurinStateID::Unk9, TAImiurinMotionID::Unk4, TAImiurinMotionID::Unk4, false);
	TAIAapproachTargetPriorityFaceDirMiurin* approachTarget
	    = new TAIAapproachTargetPriorityFaceDirMiurin(TAI_NO_TRANSIT, TAImiurinMotionID::Unk6);
	TAIAattackableTargetMiurin* attackableTarget1  = new TAIAattackableTargetMiurin(TAImiurinStateID::Unk10);
	TAIAattackPosture* attackPosture1              = new TAIAattackPosture(TAImiurinStateID::Unk11, TAImiurinMotionID::Unk8);
	TAIAattackMiurin* attack1                      = new TAIAattackMiurin(TAImiurinStateID::Unk12, 12, TAImiurinMotionID::Unk10, 11);
	TAIAcheckSatisfyMiurin* checkSatisfy1          = new TAIAcheckSatisfyMiurin(TAImiurinStateID::Unk3);
	TAIAcheckSatisfyMiurin* checkSatisfy2          = new TAIAcheckSatisfyMiurin(TAImiurinStateID::Unk15);
	TAIAattackableTargetMiurin* attackableTarget2  = new TAIAattackableTargetMiurin(TAImiurinStateID::Unk11);
	TAIAnoReaction* noReact1                       = new TAIAnoReaction(TAImiurinStateID::Unk13);
	TAIAreserveMotion* motion2                     = new TAIAreserveMotion(TAImiurinStateID::Unk14, TAImiurinMotionID::Unk13);
	TAIAinsideTerritoryRangeNavi* insideRangeNavi1 = new TAIAinsideTerritoryRangeNavi(TAImiurinStateID::Unk8);
	TAIAnoReaction* noReact2                       = new TAIAnoReaction(TAImiurinStateID::Unk2);
	TAIAstickingPikiMiurin* stickingPiki           = new TAIAstickingPikiMiurin(TAImiurinStateID::Unk16);
	TAIAflickCheckMiurin* flickCheck               = new TAIAflickCheckMiurin(TAImiurinStateID::Unk16);
	TAIAflickingMiurin* flicking1                  = new TAIAflickingMiurin(TAImiurinStateID::Unk10, TAImiurinMotionID::Unk9);
	TAIAoutsideTerritoryMiurin* outsideTerritory   = new TAIAoutsideTerritoryMiurin(TAImiurinStateID::Unk17);
	TAIAflickingMiurin* flicking2                  = new TAIAflickingMiurin(TAImiurinStateID::Unk19, TAImiurinMotionID::Unk9);
	TAIAturnFocusCreature* turnFocus2 = new TAIAturnFocusCreature(TAI_NO_TRANSIT, TAImiurinMotionID::Unk7, TAImiurinMotionID::Unk7, false);
	TAIAunvisibleTarget* unvisibleTarget = new TAIAunvisibleTarget(TAImiurinStateID::Unk3);
	new TAIAinsideTerritoryRangeNavi(TAImiurinStateID::Unk3);
	TAIAattackableTargetMiurin* attackableTarget3 = new TAIAattackableTargetMiurin(TAImiurinStateID::Unk19);
	TAIAattackPosture* attackPosture2             = new TAIAattackPosture(TAImiurinStateID::Unk20, TAImiurinMotionID::Unk8);
	TAIAattackMiurin* attack2                     = new TAIAattackMiurin(TAImiurinStateID::Unk21, 12, TAImiurinMotionID::Unk10, 11);
	TAIAnoReaction* noReact3                      = new TAIAnoReaction(TAImiurinStateID::Unk22);
	TAIAattackableTargetMiurin* attackableTarget4 = new TAIAattackableTargetMiurin(TAImiurinStateID::Unk20);
	TAIAreserveMotion* motion3                    = new TAIAreserveMotion(TAImiurinStateID::Unk3, TAImiurinMotionID::Unk13);
	TAIAsetTargetPointCircle* setTargetCircle     = new TAIAsetTargetPointCircle(TAImiurinStateID::Unk5, PI / 3.0f);
	TAIAturnToTarget* turnToTarget = new TAIAturnToTarget(TAImiurinStateID::Unk6, TAImiurinMotionID::Unk4, TAImiurinMotionID::Unk4, true);
	TAIAgoTarget* goTarget         = new TAIAgoTarget(TAImiurinStateID::Unk2, TAImiurinMotionID::Unk6);
	TAIAtimerReaction* timer1      = new TAIAtimerReaction(TAImiurinStateID::Unk3, 1.5f);
	TAIAtimerReaction* timer2      = new TAIAtimerReaction(TAImiurinStateID::Unk3, 5.0f);
	TAIAwatchNaviMiurin* watchNavi = new TAIAwatchNaviMiurin(TAImiurinStateID::Unk7, 16);
	TAIAsatisfyMiurin* satisfy     = new TAIAsatisfyMiurin(TAImiurinStateID::Unk3, TAImiurinMotionID::Unk5);
	TAIAcheckFlowerPikmin* checkFlowers = new TAIAcheckFlowerPikmin(TAImiurinStateID::Unk15);
	TAIAcheckNaviMiurin* checkNavi      = new TAIAcheckNaviMiurin(TAImiurinStateID::Unk4);
	TAIAturnFocusCreature* turnfocus3
	    = new TAIAturnFocusCreature(TAImiurinStateID::Unk2, TAImiurinMotionID::Unk4, TAImiurinMotionID::Unk4, false);
	TAIAangryMiurin* angry                   = new TAIAangryMiurin(TAImiurinStateID::Unk9, TAImiurinMotionID::Unk3);
	TAIAresetAnimSpeedMiurin* resetAnimSpeed = new TAIAresetAnimSpeedMiurin();
	new TAIAcheckTurnAngle(TAImiurinStateID::Unk23, 2.0f * TAU, true);
	TAIAgroggyMiurin* groggy = new TAIAgroggyMiurin(TAImiurinStateID::Unk3, TAImiurinMotionID::Unk5);

	// STATE 1 - Init
	TaiState* state = new TaiState(1);
	int j           = 0;
	state->setAction(j++, init);
	setState(TAImiurinStateID::Unk1, state);

	// STATE 0 - Unknown
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, dying);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk0, state);

	// STATE 3 - Unknown
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, stop);
	state->setAction(j++, checkNavi);
	state->setAction(j++, setTargetCircle);
	setState(TAImiurinStateID::Unk3, state);

	// STATE 4 - Unknown
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud1);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, watchNavi);
	state->setAction(j++, stickingPiki);
	state->setAction(j++, flickCheck);
	state->setAction(j++, turnfocus3);
	setState(TAImiurinStateID::Unk4, state);

	// STATE 5 - Unknown
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud1);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, watchNavi);
	state->setAction(j++, stickingPiki);
	state->setAction(j++, flickCheck);
	state->setAction(j++, turnToTarget);
	setState(TAImiurinStateID::Unk5, state);

	// STATE 6 - Unknown
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud1);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, watchNavi);
	state->setAction(j++, stickingPiki);
	state->setAction(j++, flickCheck);
	state->setAction(j++, goTarget);
	state->setAction(j++, timer2);
	setState(TAImiurinStateID::Unk6, state);

	// STATE 2 - Unknown
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud1);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, watchNavi);
	state->setAction(j++, stickingPiki);
	state->setAction(j++, flickCheck);
	state->setAction(j++, motion1);
	state->setAction(j++, timer1);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk2, state);

	// STATE 7 - Unknown
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, angry);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk7, state);

	// STATE 8 - Unknown
	state = new TaiState(10);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, watchNavi);
	state->setAction(j++, checkSatisfy1);
	state->setAction(j++, turnFocus1);
	state->setAction(j++, attackableTarget1);
	state->setAction(j++, stickingPiki);
	state->setAction(j++, flickCheck);
	setState(TAImiurinStateID::Unk8, state);

	// STATE 9 - Unknown
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, attackableTarget1);
	state->setAction(j++, outsideTerritory);
	state->setAction(j++, stickingPiki);
	state->setAction(j++, flickCheck);
	state->setAction(j++, checkSatisfy1);
	state->setAction(j++, approachTarget);
	setState(TAImiurinStateID::Unk9, state);

	// STATE 10 - Unknown
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, attackPosture1);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk10, state);

	// STATE 11 - Unknown
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, attack1);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk11, state);

	// STATE 12 - Unknown
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, attackableTarget2);
	state->setAction(j++, noReact1);
	setState(TAImiurinStateID::Unk12, state);

	// STATE 13 - Unknown
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, checkSatisfy2);
	state->setAction(j++, checkFlowers);
	state->setAction(j++, motion2);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk13, state);

	// STATE 14 - Unknown
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, insideRangeNavi1);
	state->setAction(j++, noReact2);
	setState(TAImiurinStateID::Unk14, state);

	// STATE 15 - Unknown
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud1);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, watchNavi);
	state->setAction(j++, satisfy);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk15, state);

	// STATE 16 - Unknown
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud2);
	state->setAction(j++, flicking1);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk16, state);

	// STATE 17 - Unknown
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, stop);
	state->setAction(j++, effCloud2);
	state->setAction(j++, flicking2);
	setState(TAImiurinStateID::Unk17, state);

	// STATE 18 - Unknown
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, attackableTarget3);
	state->setAction(j++, turnFocus2);
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, unvisibleTarget);
	state->setAction(j++, stickingPiki);
	state->setAction(j++, flickCheck);
	setState(TAImiurinStateID::Unk18, state);

	// STATE 19 - Unknown
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, attackPosture2);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk19, state);

	// STATE 20 - Unknown
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, attack2);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk20, state);

	// STATE 21 - Unknown
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, attackableTarget4);
	state->setAction(j++, noReact3);
	setState(TAImiurinStateID::Unk21, state);

	// STATE 22 - Unknown
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, checkSatisfy2);
	state->setAction(j++, checkFlowers);
	state->setAction(j++, motion3);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk22, state);

	// STATE 23 - Unknown
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud1);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, groggy);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Unk23, state);

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	801D80A0
 * Size:	0000C4
 */
bool TAImiurinStrategy::interact(Teki& teki, TekiInteractionKey& interaction)
{
	switch (interaction.mInteractionType) {
	case TekiInteractType::Attack:
		InteractAttack* attack = (InteractAttack*)interaction.mInteraction;
		if (!teki.getTekiOption(BTeki::TEKI_OPTION_INVINCIBLE)) {
			teki.mStoredDamage += attack->mDamage;
			if (teki.getTekiOption(BTeki::TEKI_OPTION_DAMAGE_COUNTABLE)) {
				teki.mDamageCount++;
			}
		}

		teki.setCreaturePointer(1, attack->mOwner);
		return true;
	}

	u32 badCompiler[2];
	return true;
}

/*
 * --INFO--
 * Address:	801D8164
 * Size:	0006FC
 */
void TAImiurinAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_KabekuiB]->mShape;
	addAnimation("tekis/miurin/motion/dead.dca");

	addAnimation("tekis/miurin/motion/damage.dca");

	addAnimation("tekis/miurin/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/miurin/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/miurin/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/miurin/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/miurin/motion/move1.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/miurin/motion/move2.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/miurin/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/miurin/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/miurin/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}

/*
 * --INFO--
 * Address:	801D8F6C
 * Size:	0000E8
 */
bool TAIAwatchNaviMiurin::act(Teki& teki)
{

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r3, 0x3120(r13)
	  bl        -0xC1BD4
	  lfs       f1, 0x340(r29)
	  mr        r31, r3
	  lfs       f0, -0x4260(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x4C
	  li        r30, 0x1
	  b         .loc_0x74

	.loc_0x4C:
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        -0x922AC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  mr        r3, r31
	  bl        -0xE0BB8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  li        r30, 0x1

	.loc_0x74:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0xC4
	  lwz       r3, 0x3120(r13)
	  bl        -0xC1C28
	  addi      r31, r3, 0
	  addi      r4, r31, 0
	  addi      r3, r29, 0x418
	  bl        .loc_0xE8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xBC
	  lwz       r0, 0xC(r28)
	  stw       r0, 0x0(r28)
	  b         .loc_0xC4

	.loc_0xBC:
	  lwz       r0, 0x8(r28)
	  stw       r0, 0x0(r28)

	.loc_0xC4:
	  mr        r3, r30
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0xE8:
	*/
}

/*
 * --INFO--
 * Address:	801D90B8
 * Size:	0000C4
 */
bool TAIAwatchNaviMiurin::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  li        r29, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xA0
	  lwz       r3, 0x8(r30)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x36
	  bne-      .loc_0xA0
	  bl        -0xE0CE4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA0
	  lwz       r31, 0x4(r30)
	  li        r29, 0x1
	  lwz       r3, 0x3120(r13)
	  bl        -0xC1D50
	  addi      r30, r3, 0
	  addi      r4, r30, 0
	  addi      r3, r31, 0x418
	  bl        -0xD0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x98
	  lwz       r0, 0xC(r28)
	  stw       r0, 0x0(r28)
	  b         .loc_0xA0

	.loc_0x98:
	  lwz       r0, 0x8(r28)
	  stw       r0, 0x0(r28)

	.loc_0xA0:
	  mr        r3, r29
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D917C
 * Size:	000174
 */
bool TAIAoutsideTerritoryMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stw       r31, 0xB4(r1)
	  li        r31, 0
	  stw       r30, 0xB0(r1)
	  mr        r30, r4
	  lwz       r3, 0x2C4(r4)
	  li        r4, 0xF
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xB6CD8
	  lwz       r3, 0x2C8(r30)
	  fmr       f31, f1
	  lfs       f0, -0x4260(r2)
	  addi      r6, r1, 0x74
	  addi      r8, r3, 0x10
	  stfs      f0, 0x90(r1)
	  addi      r5, r1, 0x70
	  stfs      f0, 0x8C(r1)
	  addi      r4, r1, 0x6C
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x18(r3)
	  addi      r3, r1, 0x88
	  lfs       f1, 0x9C(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x6C(r1)
	  bl        -0x17BB80
	  lfs       f1, 0x88(r1)
	  lfs       f0, 0x8C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x90(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CB5F0
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0x154
	  lwz       r4, 0x2C8(r30)
	  lwz       r3, 0x418(r30)
	  lfs       f0, -0x4260(r2)
	  stfs      f0, 0xA8(r1)
	  stfs      f0, 0xA4(r1)
	  stfs      f0, 0xA0(r1)
	  lfsu      f1, 0x10(r4)
	  lfsu      f0, 0x94(r3)
	  lfs       f4, 0x8(r4)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x4(r4)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x98(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x98(r1)
	  stfs      f0, 0xA0(r1)
	  stfs      f1, 0xA4(r1)
	  stfs      f3, 0xA8(r1)
	  lfs       f1, 0xA0(r1)
	  lfs       f0, 0xA4(r1)
	  lfs       f2, 0xA8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CB66C
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x3C(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x154
	  li        r31, 0x1

	.loc_0x154:
	  mr        r3, r31
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D92F0
 * Size:	000010
 */
f32 TAIAflickingMiurin::getFlickDirection(Teki& teki)
{
	return teki.mFaceDirection + PI;
}

/*
 * --INFO--
 * Address:	801D9300
 * Size:	000020
 */
bool TAIAflickCheckMiurin::act(Teki& teki)
{
	return TAIAflickCheck::act(teki);
}

/*
 * --INFO--
 * Address:	801D9320
 * Size:	000018
 */
int TAIAflickCheckMiurin::getDamageCountLimit(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x54(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9338
 * Size:	000018
 */
int TAIAstickingPikiMiurin::getPikiNum(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x50(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9350
 * Size:	000050
 */
bool TAIAcheckSatisfyMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  lwz       r3, 0x3120(r13)
	  bl        -0xC1FA4
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x38
	  li        r31, 0x1

	.loc_0x38:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D93A0
 * Size:	000128
 */
void TAIAattackMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r3, 0x3120(r13)
	  bl        -0xC1FFC
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x8(r3)
	  lfs       f0, 0x9C(r31)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        -0xBB5D4
	  lfs       f2, 0xA0(r31)
	  lfs       f0, -0x4260(r2)
	  fsubs     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  fmr       f2, f1
	  bge-      .loc_0x60
	  fneg      f1, f2
	  b         .loc_0x64

	.loc_0x60:
	  fmr       f1, f2

	.loc_0x64:
	  lfs       f0, -0x4254(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x90
	  lfs       f0, -0x4260(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x88
	  lfs       f0, -0x41D8(r2)
	  fsubs     f2, f2, f0
	  b         .loc_0x90

	.loc_0x88:
	  lfs       f0, -0x41D8(r2)
	  fadds     f2, f2, f0

	.loc_0x90:
	  lfs       f0, -0x4260(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0xA4
	  fneg      f1, f2
	  b         .loc_0xA8

	.loc_0xA4:
	  fmr       f1, f2

	.loc_0xA8:
	  lfs       f0, -0x41D4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xC0
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x8(r30)
	  b         .loc_0x104

	.loc_0xC0:
	  lfs       f0, -0x4234(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xD8
	  lwz       r0, 0xC(r30)
	  stw       r0, 0x8(r30)
	  b         .loc_0x104

	.loc_0xD8:
	  lfs       f0, -0x41D0(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xFC
	  lfs       f0, -0x41CC(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0xFC
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x8(r30)
	  b         .loc_0x104

	.loc_0xFC:
	  lwz       r0, 0x10(r30)
	  stw       r0, 0x8(r30)

	.loc_0x104:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x2C7A8
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D94C8
 * Size:	000900
 */
bool TAIAattackMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1B8(r1)
	  stfd      f31, 0x1B0(r1)
	  stfd      f30, 0x1A8(r1)
	  stmw      r22, 0x180(r1)
	  addi      r31, r4, 0
	  li        r30, 0
	  bl        -0x2C630
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8E0
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x464
	  lis       r4, 0x686E
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x6452
	  bl        -0x14FDFC
	  lfs       f0, -0x4260(r2)
	  mr.       r29, r3
	  stfs      f0, 0x13C(r1)
	  stfs      f0, 0x138(r1)
	  stfs      f0, 0x134(r1)
	  beq-      .loc_0x464
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x4(r29)
	  lfs       f2, 0xC(r29)
	  bl        -0x171634
	  lfs       f0, 0x4(r29)
	  addi      r5, r1, 0x134
	  li        r4, 0x43
	  stfs      f0, 0x134(r1)
	  li        r6, 0
	  li        r7, 0
	  stfs      f1, 0x138(r1)
	  lfs       f0, 0xC(r29)
	  stfs      f0, 0x13C(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x3CA2C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x4
	  li        r4, 0x4C
	  li        r6, 0
	  li        r7, 0
	  bl        -0x3CA44
	  lwz       r3, 0x3120(r13)
	  li        r0, 0
	  stw       r3, 0x144(r1)
	  addi      r3, r1, 0x140
	  stw       r0, 0x148(r1)
	  bl        -0x1497D8
	  lis       r4, 0x802B
	  lfs       f30, -0x4220(r2)
	  lis       r3, 0x802B
	  lfs       f31, -0x4260(r2)
	  subi      r28, r4, 0x3064
	  subi      r27, r3, 0x2EF0
	  addi      r26, r29, 0x4
	  addi      r25, r1, 0x7C
	  addi      r24, r1, 0x78
	  addi      r23, r1, 0x74
	  b         .loc_0x218

	.loc_0xFC:
	  lwz       r4, 0x140(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x124
	  lwz       r3, 0x144(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x138

	.loc_0x124:
	  lwz       r3, 0x144(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x138:
	  stfs      f31, 0xDC(r1)
	  addi      r7, r3, 0x94
	  addi      r22, r3, 0
	  stfs      f31, 0xD8(r1)
	  addi      r4, r23, 0
	  addi      r5, r24, 0
	  stfs      f31, 0xD4(r1)
	  addi      r6, r25, 0
	  addi      r3, r1, 0xD4
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x8(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x7C(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x74(r1)
	  bl        -0x17BFC8
	  lfs       f1, 0xD4(r1)
	  lfs       f0, 0xD8(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xDC(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CBA38
	  lfs       f0, 0x0(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x210
	  stw       r28, 0x14C(r1)
	  li        r0, 0x1
	  addi      r3, r22, 0
	  stw       r31, 0x150(r1)
	  addi      r4, r1, 0x14C
	  stw       r27, 0x14C(r1)
	  stb       r0, 0x154(r1)
	  stfs      f30, 0x158(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x36C74
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x210
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x33
	  addi      r3, r3, 0x70
	  bl        -0x155CD4

	.loc_0x210:
	  addi      r3, r1, 0x140
	  bl        -0x149A44

	.loc_0x218:
	  lwz       r3, 0x144(r1)
	  lwz       r4, 0x140(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x240
	  li        r0, 0x1
	  b         .loc_0x26C

	.loc_0x240:
	  lwz       r3, 0x144(r1)
	  lwz       r4, 0x140(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x268
	  li        r0, 0x1
	  b         .loc_0x26C

	.loc_0x268:
	  li        r0, 0

	.loc_0x26C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xFC
	  lwz       r3, 0x3068(r13)
	  li        r0, 0
	  stw       r3, 0x160(r1)
	  addi      r3, r1, 0x15C
	  stw       r0, 0x164(r1)
	  bl        -0x149994
	  lis       r4, 0x802B
	  lfs       f30, -0x4250(r2)
	  lis       r3, 0x802B
	  lfs       f31, -0x4260(r2)
	  subi      r28, r4, 0x3064
	  subi      r27, r3, 0x2EF0
	  addi      r26, r29, 0x4
	  addi      r23, r1, 0x70
	  addi      r24, r1, 0x6C
	  addi      r25, r1, 0x68
	  b         .loc_0x3D0

	.loc_0x2B8:
	  lwz       r4, 0x15C(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x2E4
	  lwz       r3, 0x160(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  b         .loc_0x2FC

	.loc_0x2E4:
	  lwz       r3, 0x160(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0x2FC:
	  lwz       r12, 0x0(r22)
	  mr        r3, r22
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C8
	  stfs      f31, 0xC4(r1)
	  mr        r4, r25
	  addi      r5, r24, 0
	  stfs      f31, 0xC0(r1)
	  addi      r6, r23, 0
	  addi      r3, r1, 0xBC
	  stfs      f31, 0xBC(r1)
	  lfs       f1, 0x9C(r22)
	  lfs       f0, 0x8(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  lfs       f1, 0x98(r22)
	  lfs       f0, 0x4(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x6C(r1)
	  lfs       f1, 0x94(r22)
	  lfs       f0, 0x0(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x68(r1)
	  bl        -0x17C1A0
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xC4(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CBC10
	  lfs       f0, 0x0(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3C8
	  stw       r28, 0x168(r1)
	  li        r0, 0x1
	  addi      r3, r22, 0
	  stw       r31, 0x16C(r1)
	  addi      r4, r1, 0x168
	  stw       r27, 0x168(r1)
	  stb       r0, 0x170(r1)
	  stfs      f30, 0x174(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x3C8:
	  addi      r3, r1, 0x15C
	  bl        -0x149BFC

	.loc_0x3D0:
	  lwz       r3, 0x160(r1)
	  lwz       r4, 0x15C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3F8
	  li        r0, 0x1
	  b         .loc_0x424

	.loc_0x3F8:
	  lwz       r3, 0x160(r1)
	  lwz       r4, 0x15C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x420
	  li        r0, 0x1
	  b         .loc_0x424

	.loc_0x420:
	  li        r0, 0

	.loc_0x424:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2B8
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x87
	  bl        -0x14F34C
	  addi      r22, r31, 0x94
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r22, 0
	  li        r4, 0x3
	  bl        -0xB593C
	  lwz       r3, 0x3178(r13)
	  addi      r6, r22, 0
	  li        r4, 0xA
	  li        r5, 0
	  bl        -0x5CB54

	.loc_0x464:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x89C
	  lis       r4, 0x686E
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x644C
	  bl        -0x150234
	  lfs       f0, -0x4260(r2)
	  mr.       r27, r3
	  stfs      f0, 0xF8(r1)
	  stfs      f0, 0xF4(r1)
	  stfs      f0, 0xF0(r1)
	  beq-      .loc_0x89C
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x4(r27)
	  lfs       f2, 0xC(r27)
	  bl        -0x171A6C
	  lfs       f0, 0x4(r27)
	  addi      r5, r1, 0xF0
	  li        r4, 0x43
	  stfs      f0, 0xF0(r1)
	  li        r6, 0
	  li        r7, 0
	  stfs      f1, 0xF4(r1)
	  lfs       f0, 0xC(r27)
	  stfs      f0, 0xF8(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x3CE64
	  lwz       r3, 0x3180(r13)
	  addi      r5, r27, 0x4
	  li        r4, 0x4C
	  li        r6, 0
	  li        r7, 0
	  bl        -0x3CE7C
	  lwz       r3, 0x3120(r13)
	  li        r0, 0
	  stw       r3, 0x100(r1)
	  addi      r3, r1, 0xFC
	  stw       r0, 0x104(r1)
	  bl        -0x149C10
	  lis       r4, 0x802B
	  lfs       f30, -0x4220(r2)
	  lis       r3, 0x802B
	  lfs       f31, -0x4260(r2)
	  subi      r28, r4, 0x3064
	  subi      r29, r3, 0x2EF0
	  addi      r26, r27, 0x4
	  addi      r23, r1, 0x64
	  addi      r24, r1, 0x60
	  addi      r25, r1, 0x5C
	  b         .loc_0x650

	.loc_0x534:
	  lwz       r4, 0xFC(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x55C
	  lwz       r3, 0x100(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x570

	.loc_0x55C:
	  lwz       r3, 0x100(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x570:
	  stfs      f31, 0xA4(r1)
	  addi      r7, r3, 0x94
	  addi      r22, r3, 0
	  stfs      f31, 0xA0(r1)
	  addi      r4, r25, 0
	  addi      r5, r24, 0
	  stfs      f31, 0x9C(r1)
	  addi      r6, r23, 0
	  addi      r3, r1, 0x9C
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x8(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x5C(r1)
	  bl        -0x17C400
	  lfs       f1, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xA4(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CBE70
	  lfs       f0, 0x0(r27)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x648
	  stw       r28, 0x108(r1)
	  li        r0, 0x1
	  addi      r3, r22, 0
	  stw       r31, 0x10C(r1)
	  addi      r4, r1, 0x108
	  stw       r29, 0x108(r1)
	  stb       r0, 0x110(r1)
	  stfs      f30, 0x114(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x370AC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x648
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x33
	  addi      r3, r3, 0x70
	  bl        -0x15610C

	.loc_0x648:
	  addi      r3, r1, 0xFC
	  bl        -0x149E7C

	.loc_0x650:
	  lwz       r3, 0x100(r1)
	  lwz       r4, 0xFC(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x678
	  li        r0, 0x1
	  b         .loc_0x6A4

	.loc_0x678:
	  lwz       r3, 0x100(r1)
	  lwz       r4, 0xFC(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x6A0
	  li        r0, 0x1
	  b         .loc_0x6A4

	.loc_0x6A0:
	  li        r0, 0

	.loc_0x6A4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x534
	  lwz       r3, 0x3068(r13)
	  li        r0, 0
	  stw       r3, 0x11C(r1)
	  addi      r3, r1, 0x118
	  stw       r0, 0x120(r1)
	  bl        -0x149DCC
	  lis       r4, 0x802B
	  lfs       f31, -0x4250(r2)
	  lis       r3, 0x802B
	  lfs       f30, -0x4260(r2)
	  subi      r29, r4, 0x3064
	  subi      r28, r3, 0x2EF0
	  addi      r26, r27, 0x4
	  addi      r23, r1, 0x58
	  addi      r24, r1, 0x54
	  addi      r25, r1, 0x50
	  b         .loc_0x808

	.loc_0x6F0:
	  lwz       r4, 0x118(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x71C
	  lwz       r3, 0x11C(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  b         .loc_0x734

	.loc_0x71C:
	  lwz       r3, 0x11C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0x734:
	  lwz       r12, 0x0(r22)
	  mr        r3, r22
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x800
	  stfs      f30, 0x8C(r1)
	  mr        r4, r25
	  addi      r5, r24, 0
	  stfs      f30, 0x88(r1)
	  addi      r6, r23, 0
	  addi      r3, r1, 0x84
	  stfs      f30, 0x84(r1)
	  lfs       f1, 0x9C(r22)
	  lfs       f0, 0x8(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r1)
	  lfs       f1, 0x98(r22)
	  lfs       f0, 0x4(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x54(r1)
	  lfs       f1, 0x94(r22)
	  lfs       f0, 0x0(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x50(r1)
	  bl        -0x17C5D8
	  lfs       f1, 0x84(r1)
	  lfs       f0, 0x88(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CC048
	  lfs       f0, 0x0(r27)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x800
	  stw       r29, 0x124(r1)
	  li        r0, 0x1
	  addi      r3, r22, 0
	  stw       r31, 0x128(r1)
	  addi      r4, r1, 0x124
	  stw       r28, 0x124(r1)
	  stb       r0, 0x12C(r1)
	  stfs      f31, 0x130(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x800:
	  addi      r3, r1, 0x118
	  bl        -0x14A034

	.loc_0x808:
	  lwz       r3, 0x11C(r1)
	  lwz       r4, 0x118(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x830
	  li        r0, 0x1
	  b         .loc_0x85C

	.loc_0x830:
	  lwz       r3, 0x11C(r1)
	  lwz       r4, 0x118(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x858
	  li        r0, 0x1
	  b         .loc_0x85C

	.loc_0x858:
	  li        r0, 0

	.loc_0x85C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x6F0
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x87
	  bl        -0x14F784
	  addi      r22, r31, 0x94
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r22, 0
	  li        r4, 0x3
	  bl        -0xB5D74
	  lwz       r3, 0x3178(r13)
	  addi      r6, r22, 0
	  li        r4, 0xA
	  li        r5, 0
	  bl        -0x5CF8C

	.loc_0x89C:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x5
	  bne-      .loc_0x8D0
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x8B8
	  lwz       r5, 0x2C0(r31)

	.loc_0x8B8:
	  addi      r3, r1, 0x178
	  li        r4, -0x1
	  bl        -0xBADFC
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0xBAB64

	.loc_0x8D0:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x8E0
	  li        r30, 0x1

	.loc_0x8E0:
	  mr        r3, r30
	  lmw       r22, 0x180(r1)
	  lwz       r0, 0x1BC(r1)
	  lfd       f31, 0x1B0(r1)
	  lfd       f30, 0x1A8(r1)
	  addi      r1, r1, 0x1B8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9DC8
 * Size:	00005C
 */
bool TAIAattackPosture::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  bl        -0x2CF28
	  rlwinm.   r0,r3,0,24,31
	  addi      r31, r3, 0
	  beq-      .loc_0x40
	  mr        r3, r30
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9E24
 * Size:	00005C
 */
bool TAIAattackableTargetMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bl        -0x2C04C
	  rlwinm.   r0,r3,0,24,31
	  addi      r31, r3, 0
	  beq-      .loc_0x44
	  lwz       r3, 0x3120(r13)
	  bl        -0xC2A84
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x44
	  li        r31, 0

	.loc_0x44:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9E80
 * Size:	00004C
 */
void TAIAapproachTargetPriorityFaceDirMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  bl        -0x30590
	  mr        r3, r31
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x425C(r2)
	  stfs      f0, 0x3B4(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9ECC
 * Size:	000018
 */
f32 TAIAapproachTargetPriorityFaceDirMiurin::getVelocity(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9EE4
 * Size:	00004C
 */
void TAIAturnFocusCreatureMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  bl        -0x2FAE0
	  mr        r3, r31
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x425C(r2)
	  stfs      f0, 0x3B4(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9F30
 * Size:	000018
 */
f32 TAIAturnFocusCreatureMiurin::getTurnVelocity(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xD4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9F48
 * Size:	000034
 */
void TAIAdyingMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x31A30
	  lfs       f0, -0x4260(r2)
	  stfs      f0, 0x478(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9F7C
 * Size:	0000F0
 */
bool TAIAdyingMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  mr        r30, r3
	  lwz       r5, 0x2DEC(r13)
	  lfs       f1, 0x478(r4)
	  lfs       f0, 0x28C(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x478(r4)
	  lfs       f1, 0x478(r4)
	  lfs       f0, -0x41F8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x68
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x50
	  lwz       r5, 0x2C0(r31)

	.loc_0x50:
	  addi      r3, r1, 0x28
	  li        r4, -0x1
	  bl        -0xBB048
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0xBADB0

	.loc_0x68:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xCC
	  lfs       f0, 0x94(r31)
	  li        r4, 0x1
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x9C(r31)
	  stfs      f0, 0x38(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x30(r1)
	  lfs       f2, 0x38(r1)
	  bl        -0x172114
	  stfs      f1, 0x34(r1)
	  addi      r5, r1, 0x30
	  li        r4, 0x43
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        -0x3D4FC
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x7
	  bl        -0x14FA90

	.loc_0xCC:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x31A2C
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DA06C
 * Size:	000014
 */
void TAIAinitMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x4260(r2)
	  stfs      f0, 0x340(r4)
	  lfs       f0, -0x424C(r2)
	  stfs      f0, 0x270(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DA080
 * Size:	000008
 */
bool TAIAinitMiurin::act(Teki&)
{
	return true;
}
