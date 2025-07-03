#include "TAI/Miurin.h"
#include "TAI/Aeffect.h"
#include "SoundMgr.h"
#include "Pcam/CameraManager.h"
#include "ComplexCreature.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(34)

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
		rumbleMgr->start(RUMBLE_Unk11, 0, teki.getPosition());
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

		STACK_PAD_TERNARY(navi, 1);
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
		if (zen::Rand(100.0f) < teki.getParameterF(TAImiurinFloatParams::CheckNaviChance)) {
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

/**
 * @brief TODO
 */
struct TAIAattackMiurin : public TAIAreserveMotion {
	TAIAattackMiurin(int nextState, int p2, int motionID, int p4)
	    : TAIAreserveMotion(nextState, motionID)
	{
		_0C = p2;
		_10 = p4;
		_14 = motionID;
	}

	virtual void start(Teki& teki) // _08
	{
		Navi* navi    = naviMgr->getNavi();
		f32 a         = NMathF::atan2(navi->getPosition().x - teki.getPosition().x, navi->getPosition().z - teki.getPosition().z);
		f32 angleDiff = a - teki.mFaceDirection;
		if (zen::Abs(angleDiff) > PI) {
			if (angleDiff > 0.0f) {
				angleDiff -= TAU;
			} else {
				angleDiff += TAU;
			}
		}
		if (zen::Abs(angleDiff) > 80.0f * PI / 180.0f) {
			mMotionID = _14;
		} else if (angleDiff > 50.0f * PI / 180.0f) {
			mMotionID = _0C;
		} else if (angleDiff > -(PI / 3.0f) && angleDiff < (PI / 6.0f)) {
			mMotionID = _14;
		} else {
			mMotionID = _10;
		}

		TAIAreserveMotion::start(teki);
	}
	virtual bool act(Teki& teki) // _10
	{
		bool res = false;
		if (TAIAreserveMotion::act(teki)) {
			if (teki.mCurrentAnimEvent == KEY_Action0) {
				attack(teki, 'hndR');
			}
			if (teki.mCurrentAnimEvent == KEY_Action1) {
				attack(teki, 'hndL');
			}

			if (teki.mCurrentAnimEvent == KEY_LoopStart) {
				teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
			}

			if (teki.mCurrentAnimEvent == KEY_Finished) {
				res = true;
			}
		}
		return res;
	}

	void attack(Teki& teki, int handID)
	{
		CollPart* hand = teki.mCollInfo->getSphere(handID);
		Vector3f effPos;
		if (hand) {
			effPos.set(hand->mCentre.x, mapMgr->getMinY(hand->mCentre.x, hand->mCentre.z, true), hand->mCentre.z);
			effectMgr->create(EffectMgr::EFF_SmokeRing_M, effPos, nullptr, nullptr);
			effectMgr->create(EffectMgr::EFF_Miurin_Attack, hand->mCentre, nullptr, nullptr);

			Iterator iterNavi(naviMgr);
			CI_LOOP(iterNavi)
			{
				Creature* navi = *iterNavi;
				if (hand->mCentre.distance(navi->getPosition()) < hand->mRadius) {
					InteractBury bury(&teki, true, 20.0f);
					navi->stimulate(bury);
					PRINT("NAVI BURY !!!\n");
					if (teki.isNaviWatch()) {
						playerState->mResultFlags.setOn(RESFLAG_Miurin);
					}
				}
			}

			Iterator iterPiki(pikiMgr);
			CI_LOOP(iterPiki)
			{
				Creature* piki = *iterPiki;
				if (piki->isAlive() && hand->mCentre.distance(piki->getPosition()) < hand->mRadius) {
					InteractBury bury(&teki, true, 10.0f);
					piki->stimulate(bury);
					PRINT("PIKI BURY !!!\n");
				}
			}

			teki.playEventSound(&teki, SE_MIURIN_PUNCH);
			cameraMgr->startVibrationEvent(3, teki.getPosition());
			rumbleMgr->start(RUMBLE_Unk10, 0, teki.getPosition());

		} else {
			ERROR("ARIMASEN. ITTE YOSI!"); // 'there is nothing. go on!'
		}
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	int _0C; // _0C
	int _10; // _10
	int _14; // _14
};

/**
 * @brief TODO
 */
struct TAIAattackableTargetMiurin : public TAIAattackableTarget {
	TAIAattackableTargetMiurin(int nextState)
	    : TAIAattackableTarget(nextState)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		bool res = TAIAattackableTarget::act(teki);
		if (res) {
			Navi* navi = naviMgr->getNavi();
			if (navi->isBuried()) {
				PRINT("navi is buried.\n"); // he sure is.
				res = false;
			}
		}
		return res;
	}

	// _04     = VTBL
	// _00-_08 = TAIAattackableTarget?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckSatisfyMiurin : public TaiAction {
	TAIAcheckSatisfyMiurin(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		bool res   = false;
		Navi* navi = naviMgr->getNavi();
		if (navi->isBuried()) {
			PRINT("navi is buried.\n");
			res = true;
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

/**
 * @brief TODO
 */
struct TAIAwatchNaviMiurin : public TaiAction {
	TAIAwatchNaviMiurin(int nextState, int nextStateNaviBury)
	    : TaiAction(nextState)
	{
		mNextStateOther      = nextState;
		mNextStateIfNaviBury = nextStateNaviBury;
	}

	virtual bool act(Teki& teki) // _10
	{
		bool res   = false;
		Navi* navi = naviMgr->getNavi();
		if (teki.mDamageCount > 0.0f) {
			PRINT("MIURIN DAMAGE! \n");
			res = true;
		} else {
			if (teki.visibleCreature(*navi) && navi->isNuking()) {
				PRINT("     nuking!!!! \n");
				res = true;
			}
		}

		if (res) {
			goNextState(teki);
		}
		return res;
	}
	virtual bool actByEvent(TekiEvent& event) // _14
	{
		bool res = false;
		if (event.mEventType == TekiEventType::Entity) {
			Creature* coll = event.mOther;
			if (coll->mObjType == OBJTYPE_Navi) {
				Navi* navi = (Navi*)coll;
				if (navi->isNuking()) {
					PRINT("     Nuking Navi touch Miurin. \n");
					res = true;
					goNextState(*event.mTeki);
				}
			}
		}

		return res;
	}

	void goNextState(Teki& teki)
	{
		Navi* navi = naviMgr->getNavi();
		teki.setCreaturePointer(0, navi);
		if (navi->isBuried()) {
			mNextState = mNextStateIfNaviBury;
		} else {
			mNextState = mNextStateOther;
		}
	}

	// _04     = VTBL
	// _00-_08 = TaiAction
	int mNextStateOther;      // _08
	int mNextStateIfNaviBury; // _0C
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
	multiP->setF(TAImiurinFloatParams::CheckNaviChance, 50.0f);
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
    : YaiStrategy(TAImiurinStateID::COUNT, TAImiurinStateID::Init)
{
	TAIAinitMiurin* init       = new TAIAinitMiurin(TAImiurinStateID::Unk3);
	TAIAdeadCheck* deadCheck   = new TAIAdeadCheck(TAImiurinStateID::Dead);
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
	TAIAattackableTargetMiurin* attackableTarget1 = new TAIAattackableTargetMiurin(TAImiurinStateID::Unk10);
	TAIAattackPosture* attackPosture1             = new TAIAattackPosture(TAImiurinStateID::Unk11, TAImiurinMotionID::Unk8);
	TAIAattackMiurin* attack1
	    = new TAIAattackMiurin(TAImiurinStateID::Unk12, TAImiurinMotionID::Unk12, TAImiurinMotionID::Unk10, TAImiurinMotionID::Unk11);
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
	TAIAattackMiurin* attack2
	    = new TAIAattackMiurin(TAImiurinStateID::Unk21, TAImiurinMotionID::Unk12, TAImiurinMotionID::Unk10, TAImiurinMotionID::Unk11);
	TAIAnoReaction* noReact3                      = new TAIAnoReaction(TAImiurinStateID::Unk22);
	TAIAattackableTargetMiurin* attackableTarget4 = new TAIAattackableTargetMiurin(TAImiurinStateID::Unk20);
	TAIAreserveMotion* motion3                    = new TAIAreserveMotion(TAImiurinStateID::Unk3, TAImiurinMotionID::Unk13);
	TAIAsetTargetPointCircle* setTargetCircle     = new TAIAsetTargetPointCircle(TAImiurinStateID::Unk5, PI / 3.0f);
	TAIAturnToTarget* turnToTarget = new TAIAturnToTarget(TAImiurinStateID::Unk6, TAImiurinMotionID::Unk4, TAImiurinMotionID::Unk4, true);
	TAIAgoTarget* goTarget         = new TAIAgoTarget(TAImiurinStateID::Unk2, TAImiurinMotionID::Unk6);
	TAIAtimerReaction* timer1      = new TAIAtimerReaction(TAImiurinStateID::Unk3, 1.5f);
	TAIAtimerReaction* timer2      = new TAIAtimerReaction(TAImiurinStateID::Unk3, 5.0f);
	TAIAwatchNaviMiurin* watchNavi = new TAIAwatchNaviMiurin(TAImiurinStateID::Angry, TAImiurinStateID::Unk16);
	TAIAsatisfyMiurin* satisfy     = new TAIAsatisfyMiurin(TAImiurinStateID::Unk3, TAImiurinMotionID::Unk5);
	TAIAcheckFlowerPikmin* checkFlowers = new TAIAcheckFlowerPikmin(TAImiurinStateID::Unk15);
	TAIAcheckNaviMiurin* checkNavi      = new TAIAcheckNaviMiurin(TAImiurinStateID::Unk4);
	TAIAturnFocusCreature* turnfocus3
	    = new TAIAturnFocusCreature(TAImiurinStateID::Unk2, TAImiurinMotionID::Unk4, TAImiurinMotionID::Unk4, false);
	TAIAangryMiurin* angry                   = new TAIAangryMiurin(TAImiurinStateID::Unk9, TAImiurinMotionID::Unk3);
	TAIAresetAnimSpeedMiurin* resetAnimSpeed = new TAIAresetAnimSpeedMiurin();
	new TAIAcheckTurnAngle(TAImiurinStateID::Groggy, 2.0f * TAU, true);
	TAIAgroggyMiurin* groggy = new TAIAgroggyMiurin(TAImiurinStateID::Unk3, TAImiurinMotionID::Unk5);

	// STATE 1 - Init
	TaiState* state = new TaiState(1);
	int j           = 0;
	state->setAction(j++, init); // when init done, go to 3
	setState(TAImiurinStateID::Init, state);

	// STATE 0 - Dead
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, dying);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Dead, state);

	// STATE 3 - Unknown
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, stop);
	state->setAction(j++, checkNavi);       // chance to check if navi is in territory range, if so, go to 4
	state->setAction(j++, setTargetCircle); // pick a random point as target position and go to 5
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

	// STATE 7 - Angry
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud2);
	state->setAction(j++, damage);
	state->setAction(j++, angry);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Angry, state);

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

	// STATE 23 - Groggy? unused/never transitioned to
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, resetAnimSpeed);
	state->setAction(j++, effCloud1);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);
	state->setAction(j++, groggy);
	state->setAction(j++, stop);
	setState(TAImiurinStateID::Groggy, state);

	STACK_PAD_VAR(2);
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

	STACK_PAD_VAR(2);
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
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/miurin/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/miurin/motion/move1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/miurin/motion/move2.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
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
