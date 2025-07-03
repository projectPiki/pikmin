#include "TAI/Beatle.h"
#include "DebugLog.h"
#include "TAI/Aeffect.h"
#include "PikiState.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(38)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TAIbeatle")

/**
 * @brief TODO
 *
 * @note Defined in TAIbeatle.cpp
 */
struct TAIAflickingAfterMotionLoopBeatle : public TAIAflickingAfterMotionLoop {
	TAIAflickingAfterMotionLoopBeatle(int nextState, int motionIdx) // TODO: check this when used
	    : TAIAflickingAfterMotionLoop(nextState, motionIdx, 0.0f)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAflickingAfterMotionLoop::start(teki);

		teki.setPtclGenPtr(YTeki::PTCL_Unk2, nullptr);
		teki.setPtclGenPtr(YTeki::PTCL_Unk3, nullptr);
		teki.setPtclGenPtr(YTeki::PTCL_Unk4, nullptr);
		teki.setPtclGenPtr(YTeki::PTCL_Unk5, nullptr);

		teki.mTekiAnimator->startMotion(PaniMotionInfo(mMotionID, &teki));
		teki.playEventSound(&teki, SE_KABUTO_OVERHEAT);
		teki.mTekiSwitches.m1 = false;
	}

	virtual bool act(Teki& teki) // _10
	{
		zen::particleGenerator* ptclGen;
		CollPart* kutiPart = teki.mCollInfo->getSphere('kuti');

		switch (teki.mCurrentAnimEvent) {
		case KEY_Action1:
			teki.enableStick();

			if (kutiPart != nullptr) {
				Matrix4f mtx = kutiPart->getMatrix();

				Vector3f emitDir;
				emitDir.set(mtx.mMtx[0][0], mtx.mMtx[1][0], mtx.mMtx[2][0]);

				ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_Flick1, kutiPart->mCentre, nullptr, nullptr);
				if (ptclGen != nullptr) {
					ptclGen->setEmitPosPtr(&kutiPart->mCentre);
					ptclGen->setEmitDir(emitDir);
				}
			}
			break;

		case KEY_Action2:
			teki.disableStick();

			ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk2);
			if (ptclGen != nullptr) {
				ptclGen->finish();
			}

			ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk3);
			if (ptclGen != nullptr) {
				ptclGen->finish();
			}

			ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk4);
			if (ptclGen != nullptr) {
				ptclGen->finish();
			}

			ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk5);
			if (ptclGen != nullptr) {
				ptclGen->finish();
			}

			teki.stopEventSound(&teki, SE_KABUTO_COOLDOWN);
			teki.setRunAwaySwitch(false);
			break;

		// ... why is this down here?
		case KEY_Action0:
			if (teki.getCreaturePointer(2) != nullptr) {
				teki.setCreaturePointer(2, nullptr);
			}
			break;

		case KEY_Action3:
			teki.playEventSound(&teki, SE_KABUTO_COOLDOWN);
			createSteamEffect(teki);
			break;

		case KEY_LoopStart:
			teki.setRunAwaySwitch(true);
			break;
		}

		if (teki.getRunAwaySwitch()) {
			runAway(teki);
		}

		return TAIAflickingAfterMotionLoop::act(teki);
	}

	virtual f32 getFrameMax(Teki& teki) // _1C
	{
		return teki.getParameterF(TAIbeatleFloatParms::FlickingTime);
	}

	virtual bool permitFlick(Teki& teki) // _20
	{
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			return true;
		}

		return false;
	}

	void createSteamEffect(Teki& teki)
	{
		// interesting...
		zen::particleGenerator* ptclGen;
		CollPart* kutiPart;
		CollPart* steamEffectPart;

		int i = 0;

		int collPartIDs[6];
		for (i = 0; i < 6; i++) {
			collPartIDs[i] = i;
		}

		for (i = 0; i < 10; i++) {
			int firstID  = zen::Rand(6.0f);
			int secondID = zen::Rand(6.0f);

			int temp              = collPartIDs[firstID];
			collPartIDs[firstID]  = collPartIDs[secondID];
			collPartIDs[secondID] = temp;
		}

		// frankly this is a bizarre way of doing this but whatever i guess
		for (i = 0; i < 3; i++) {
			steamEffectPart;
			switch (collPartIDs[i]) {
			case 0:
				steamEffectPart = teki.mCollInfo->getSphere('stm0');
				break;

			case 1:
				steamEffectPart = teki.mCollInfo->getSphere('stm1');
				break;

			case 2:
				steamEffectPart = teki.mCollInfo->getSphere('stm2');
				break;

			case 3:
				steamEffectPart = teki.mCollInfo->getSphere('stm3');
				break;

			case 4:
				steamEffectPart = teki.mCollInfo->getSphere('stm4');
				break;

			case 5:
				steamEffectPart = teki.mCollInfo->getSphere('stm5');
				break;

			default:
				ERROR("illegal index");
				break;
			}

			if (steamEffectPart != nullptr) {
				ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_Flick2, steamEffectPart->mCentre, nullptr, nullptr);
				if (ptclGen != nullptr) {
					ptclGen->setEmitPosPtr(&steamEffectPart->mCentre);
				}
				teki.setPtclGenPtr((YTeki::ptclIndexFlag)(YTeki::PTCL_Unk3 + i), ptclGen);
			}
		}

		kutiPart = teki.mCollInfo->getSphere('kuti');
		if (kutiPart != nullptr) {
			Matrix4f mtx = kutiPart->getMatrix();

			Vector3f emitDir;
			emitDir.set(mtx.mMtx[0][0], mtx.mMtx[1][0], mtx.mMtx[2][0]);

			ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_Flick3, kutiPart->mCentre, nullptr, nullptr);
			if (ptclGen != nullptr) {
				ptclGen->setEmitPosPtr(&kutiPart->mCentre);
				ptclGen->setEmitDir(emitDir);
			}

			teki.setPtclGenPtr(YTeki::PTCL_Unk2, ptclGen);
		}
	}

	void runAway(Teki& teki)
	{
		Navi* navi = naviMgr->getNavi();

		Vector3f sep;
		sep.set(teki.getPosition() - navi->getPosition());

		sep.multiply(teki.getParameterF(TPF_SafetyTerritoryRange) / sep.length());

		teki.mTargetPosition.set(teki.getPosition() + sep);

		// if distance between target and home is outside territory
		if (teki.mTargetPosition.distance(teki.mPersonality->mNestPosition) > teki.getParameterF(TPF_DangerTerritoryRange)) {
			// reset target to within territory
			sep.set(teki.mTargetPosition - teki.mPersonality->mNestPosition);
			sep.normalize();
			sep.multiply(teki.getParameterF(TPF_DangerTerritoryRange));

			teki.mTargetPosition.set(teki.mPersonality->mNestPosition + sep);
		}

		teki.moveTowardPriorityFaceDir(teki.mTargetPosition, teki.getParameterF(TPF_WalkVelocity) * 0.85f,
		                               teki.getParameterF(TPF_TurnVelocity) * 0.5f);
	}

	// _04     = VTBL
	// _00-_0C = TAIAflickingAfterMotionLoop?
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Defined in TAIbeatle.cpp
 */
struct TAIAinitBeatle : public TaiAction {
	inline TAIAinitBeatle(int nextState) // TODO: this is a guess
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		for (int i = 0; i < YTeki::PTCL_COUNT; i++) {
			teki.setPtclGenPtr((YTeki::ptclIndexFlag)i, nullptr);
		}

		CollPart* leftEye = teki.mCollInfo->getSphere('me_l');
		if (leftEye == nullptr) {
			ERROR("No Left eye");
		} else {
			zen::particleGenerator* eyePtcl = effectMgr->create(EffectMgr::EFF_Beatle_EyeGlow, leftEye->mCentre, nullptr, nullptr);
			if (eyePtcl != nullptr) {
				eyePtcl->stopGen();
			}

			teki.setPtclGenPtr(YTeki::PTCL_Unk0, eyePtcl);
		}

		CollPart* rightEye = teki.mCollInfo->getSphere('me_r');
		if (rightEye == nullptr) {
			ERROR("No right eye");
		} else {
			zen::particleGenerator* eyePtcl = effectMgr->create(EffectMgr::EFF_Beatle_EyeGlow, rightEye->mCentre, nullptr, nullptr);
			if (eyePtcl != nullptr) {
				eyePtcl->stopGen();
			}

			teki.setPtclGenPtr(YTeki::PTCL_Unk1, eyePtcl);
		}

		teki.mCollisionRadius = 64.0f;
	}

	virtual bool act(Teki&) { return true; } // _10

	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/*
 * --INFO--
 * Address:	801C59D4
 * Size:	000084
 */
TAIbeatleSoundTable::TAIbeatleSoundTable()
    : PaniSoundTable(7)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_KABUTO_BREATH);
	}
}

/*
 * --INFO--
 * Address:	801C5A58
 * Size:	000418
 */
TAIbeatleParameters::TAIbeatleParameters()
    : TekiParameters(TPI_COUNT, TAIbeatleFloatParms::COUNT)
{
	int j                           = TAIbeatleFloatParms::FlickingTime;
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
	fParams[j++].init("ピヨリ時間", 0.0f, 100.0f);            // 'Peeing Time' ???
	fParams[j++].init("岩攻撃時に近づく距離", 0.0f, 1000.0f); // 'Approach distance when attacking with rocks'
	fParams[j++].init("吸い込み判定サイズ", 0.0f, 100.0f);    // 'Suction Judgment Size'
	fParams[j++].init("吸い込みの角度", 0.0f, 90.0f);         // 'Suction angle'
	fParams[j++].init("吸い込みの距離", 0.0f, 300.0f);        // 'Suction distance'

	multiP->setF(TAIbeatleFloatParms::FlickingTime, 20.0f);
	multiP->setF(TAIbeatleFloatParms::AttackRange, 200.0f);
	multiP->setF(TAIbeatleFloatParms::Unk2, 40.0f);
	multiP->setF(TAIbeatleFloatParms::SuctionAngle, 60.0f);
	multiP->setF(TAIbeatleFloatParms::SuctionRadius, 110.0f);

	multiP->setI(TPI_SpawnType, TEKI_Iwagon);
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 10);
	multiP->setI(TPI_FlickPikiCount2, 20);
	multiP->setI(TPI_FlickPikiCount3, 30);
	multiP->setI(TPI_FlickDamageCount1, 30);
	multiP->setI(TPI_FlickDamageCount2, 30);
	multiP->setI(TPI_FlickDamageCount3, 30);
	multiP->setI(TPI_FlickDamageCount4, 30);
	multiP->setI(TPI_CarcassSize, 0);

	multiP->setF(TPF_Weight, 300.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 1000.0f);
	multiP->setF(TPF_WalkVelocity, 50.0f);
	multiP->setF(TPF_RunVelocity, 120.0f);
	multiP->setF(TPF_TurnVelocity, 0.69813174f);
	multiP->setF(TPF_VisibleRange, 400.0f);
	multiP->setF(TPF_VisibleAngle, 180.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 30.0f);
	multiP->setF(TPF_AttackableAngle, 20.0f);
	multiP->setF(TPF_AttackRange, 60.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 0.0f);
	multiP->setF(TPF_DangerTerritoryRange, 300.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 200.0f);
	multiP->setF(TPF_LifeGaugeOffset, 60.0f);
	multiP->setF(TPF_ShadowSize, 125.0f);
	multiP->setF(TPF_RippleScale, 5.0f);
	multiP->setF(TPF_LifePeriod, 0.0f);
	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.05f);
	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 200.0f);
	multiP->setF(TPF_LowerFlickPower, 200.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);
	multiP->setF(TPF_LifeRecoverRate, 0.005f);
	multiP->setF(TPF_TraceAngle, 60.0f);
	multiP->setF(TPF_FlightHeight, 60.0f);
	multiP->setF(TPF_SpawnDistance, 75.0f);
	multiP->setF(TPF_SpawnHeight, 10.0f);
	multiP->setF(TPF_SpawnVelocity, 300.0f);
	multiP->setF(TPF_SpawnPelletVelocityHoriz, 50.0f);
	multiP->setF(TPF_SpawnPelletVelocityVert, 400.0f);
	multiP->setF(TPF_CorpseVelocityHoriz, 0.0f);
	multiP->setF(TPF_CorpseVelocityVert, 0.0f);
	multiP->setF(TPF_CorpseSize, 40.0f);
	multiP->setF(TPF_CorpseHeight, 60.0f);

	multiP->setI(TPI_CullingType, 0);
	multiP->setI(TPI_SpawnPelletScaleOff, 1);
	multiP->setI(TPI_CorpseType, 1);

	u32 dumb;
}

/*
 * --INFO--
 * Address:	801C5E70
 * Size:	000EF4
 */
TAIbeatleStrategy::TAIbeatleStrategy()
    : YaiStrategy(TAIbeatleStateID::COUNT, TAIbeatleStateID::Initializing) // TODO: fix
{
	TAIAinitBeatle* initBeatle     = new TAIAinitBeatle(TAIbeatleStateID::Unk2);
	TAIAdeadCheck* deadCheck       = new TAIAdeadCheck(TAIbeatleStateID::Dying);
	TAIAdyingBeatle* dyingBeatle   = new TAIAdyingBeatle(TAI_NO_TRANSIT, 0);
	TAIAstop* stopAct              = new TAIAstop(TAI_NO_TRANSIT);
	TAIAdamageBeatle* damageBeatle = new TAIAdamageBeatle(TAI_NO_TRANSIT);

	TAIAreserveMotion* unused1 = new TAIAreserveMotion(TAI_NO_TRANSIT, 2);

	TAIAtimerReaction* timerReaction = new TAIAtimerReaction(TAIbeatleStateID::Unk3, 3.0f);

	TAIArandomWalk* unused2 = new TAIArandomWalk(TAI_NO_TRANSIT, 6);

	TAIAlookAround* lookAroundAct                        = new TAIAlookAround(TAI_NO_TRANSIT, 2, 10, 11);
	TAIAvisibleNavi* visibleNaviAct                      = new TAIAvisibleNavi(TAIbeatleStateID::Unk6);
	TAIAvisiblePikiBeatle* visiblePikiAct                = new TAIAvisiblePikiBeatle(TAIbeatleStateID::Unk6);
	TAIAturnFocusCreature* focusOnCreatureAct            = new TAIAturnFocusCreature(TAIbeatleStateID::Unk8, 10, 11, true);
	TAIAunvisibleTarget* unvisibleTargetAct              = new TAIAunvisibleTarget(TAIbeatleStateID::Unk2);
	TAIAapproachTargetPriorityFaceDir* approachTargetAct = new TAIAapproachTargetPriorityFaceDir(TAIbeatleStateID::Unk8, 6);

	TAIAinsideOptionalRangeBeatle* inOptionalRange = new TAIAinsideOptionalRangeBeatle(TAIbeatleStateID::Unk8);
	TAIArockAttack* rockAttack                     = new TAIArockAttack(TAIbeatleStateID::Unk13, TAIbeatleStateID::Unk11, 8);
	TAIAoutsideTerritory* outsideTerritoryAct      = new TAIAoutsideTerritory(TAIbeatleStateID::Unk9);

	TAIAturnHome* turnHomeAct = new TAIAturnHome(TAIbeatleStateID::Unk10, 10, 11);
	TAIAgoingHome* goHomeAct  = new TAIAgoingHome(TAIbeatleStateID::Unk2, 6);

	TAIAflickingAfterMotionLoopBeatle* flickAfterMotion = new TAIAflickingAfterMotionLoopBeatle(TAIbeatleStateID::Unk2, 9);
	TAIAinvincibleOff* invincibleOffAct1                = new TAIAinvincibleOff(TAI_NO_TRANSIT);
	TAIAinvincibleOff* invincibleOffAct2                = new TAIAinvincibleOff(TAI_NO_TRANSIT);
	TAIAcheckTurnAngle* checkTurnAngleAct               = new TAIAcheckTurnAngle(TAIbeatleStateID::Unk12, 1.5707964f, false);
	TAIAflickingBeatle* flickingAct                     = new TAIAflickingBeatle(TAIbeatleStateID::Unk13, 12);

	TAIAsetTargetPointCircle* setTargetInRadius = new TAIAsetTargetPointCircle(TAIbeatleStateID::Unk4, 0.69813174f);
	TAIAturnToTarget* turnToTargetAct           = new TAIAturnToTarget(TAIbeatleStateID::Unk5, 10, 11, true);
	TAIAgoTarget* goToTargetAct                 = new TAIAgoTarget(TAIbeatleStateID::Unk2, 6);
	TAIAnoReaction* noReaction                  = new TAIAnoReaction(TAIbeatleStateID::Unk2);
	TAIAdisableStick* disableStickAct           = new TAIAdisableStick(TAI_NO_TRANSIT);
	TAIAeffCloudOfDust* cloudOfDustEffect
	    = new TAIAeffCloudOfDust(TAI_NO_TRANSIT, EffectMgr::EFF_SmokeRing_M, SE_KABUTO_WALK, 15, -0.5f, 4, 'lhnd', 'rhnd', 'lfot', 'rfot');

	TAIAcheckInsideRangePikiBeatle* checkInsideRangeAct = new TAIAcheckInsideRangePikiBeatle(TAI_NO_TRANSIT, 10);

	// the states are all over the place with this one...

	// STATE 1 - Init
	TaiState* state = new TaiState(1);
	int j           = 0;
	state->setAction(j++, initBeatle);
	setState(TAIbeatleStateID::Initializing, state);

	// STATE 0 - Dying
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, dyingBeatle);
	state->setAction(j++, stopAct);
	setState(TAIbeatleStateID::Dying, state);

	// STATE 3 -
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, invincibleOffAct1);
	state->setAction(j++, setTargetInRadius);
	setState(TAIbeatleStateID::Unk3, state);

	// STATE 4 -
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, invincibleOffAct1);
	state->setAction(j++, stopAct);
	state->setAction(j++, deadCheck);
	state->setAction(j++, damageBeatle);
	state->setAction(j++, turnToTargetAct);
	state->setAction(j++, visibleNaviAct);
	state->setAction(j++, visiblePikiAct);
	state->setAction(j++, cloudOfDustEffect);
	state->setAction(j++, checkInsideRangeAct);
	setState(TAIbeatleStateID::Unk4, state);

	// STATE 5 -
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, invincibleOffAct1);
	state->setAction(j++, stopAct);
	state->setAction(j++, deadCheck);
	state->setAction(j++, damageBeatle);
	state->setAction(j++, goToTargetAct);
	state->setAction(j++, visibleNaviAct);
	state->setAction(j++, visiblePikiAct);
	state->setAction(j++, cloudOfDustEffect);
	state->setAction(j++, checkInsideRangeAct);
	setState(TAIbeatleStateID::Unk5, state);

	// STATE 2 -
	state = new TaiState(11);
	j     = 0;
	state->setAction(j++, disableStickAct);
	state->setAction(j++, invincibleOffAct1);
	state->setAction(j++, stopAct);
	state->setAction(j++, deadCheck);
	state->setAction(j++, damageBeatle);
	state->setAction(j++, lookAroundAct);
	state->setAction(j++, visibleNaviAct);
	state->setAction(j++, visiblePikiAct);
	state->setAction(j++, timerReaction);
	state->setAction(j++, cloudOfDustEffect);
	state->setAction(j++, checkInsideRangeAct);
	setState(TAIbeatleStateID::Unk2, state);

	// STATE 6 -
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damageBeatle);
	state->setAction(j++, focusOnCreatureAct);
	state->setAction(j++, unvisibleTargetAct);
	state->setAction(j++, checkTurnAngleAct);
	state->setAction(j++, cloudOfDustEffect);
	state->setAction(j++, checkInsideRangeAct);
	setState(TAIbeatleStateID::Unk6, state);

	// STATE 7 -
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damageBeatle);
	state->setAction(j++, inOptionalRange);
	state->setAction(j++, approachTargetAct);
	state->setAction(j++, outsideTerritoryAct);
	state->setAction(j++, cloudOfDustEffect);
	state->setAction(j++, checkInsideRangeAct);
	setState(TAIbeatleStateID::Unk7, state);

	// STATE 8 -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, stopAct);
	state->setAction(j++, deadCheck);
	state->setAction(j++, damageBeatle);
	state->setAction(j++, rockAttack);
	state->setAction(j++, cloudOfDustEffect);
	setState(TAIbeatleStateID::Unk8, state);

	// STATE 9 -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, stopAct);
	state->setAction(j++, deadCheck);
	state->setAction(j++, damageBeatle);
	state->setAction(j++, turnHomeAct);
	state->setAction(j++, cloudOfDustEffect);
	setState(TAIbeatleStateID::Unk9, state);

	// STATE 10 -
	state = new TaiState(6);
	j     = 0;
	state->setAction(j++, deadCheck);
	state->setAction(j++, damageBeatle);
	state->setAction(j++, goHomeAct);
	state->setAction(j++, visibleNaviAct);
	state->setAction(j++, visiblePikiAct);
	state->setAction(j++, cloudOfDustEffect);
	setState(TAIbeatleStateID::Unk10, state);

	// STATE 11 -
	state = new TaiState(5);
	j     = 0;
	state->setAction(j++, invincibleOffAct2);
	state->setAction(j++, deadCheck);
	state->setAction(j++, damageBeatle);
	state->setAction(j++, flickAfterMotion);
	state->setAction(j++, cloudOfDustEffect);
	setState(TAIbeatleStateID::Unk11, state);

	// STATE 12 -
	state = new TaiState(2);
	j     = 0;
	state->setAction(j++, flickingAct);
	state->setAction(j++, cloudOfDustEffect);
	setState(TAIbeatleStateID::Unk12, state);

	// STATE 13 -
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, visiblePikiAct);
	state->setAction(j++, visibleNaviAct);
	state->setAction(j++, noReaction);
	setState(TAIbeatleStateID::Unk13, state);
}

/*
 * --INFO--
 * Address:	801C6D64
 * Size:	000140
 */
bool TAIbeatleStrategy::interact(Teki& teki, TekiInteractionKey& key)
{
	STACK_PAD_VAR(1);

	switch (key.mInteractionType) {
	case TekiInteractType::Attack: {
		if (teki.getTekiOption(BTeki::TEKI_OPTION_INVINCIBLE)) {
			return false;
		}

		InteractAttack* attack = (InteractAttack*)key.mInteraction;
		teki._344              = attack->getDamagePortion();
		if (teki._344 == 0) {
			teki.mStoredDamage += attack->mDamage;
			teki.mDamageCount += 1.0f;
			teki.setCreaturePointer(1, attack->mOwner);
			return true;
		}

		return false;
	}

	case TekiInteractType::HitEffect: {
		InteractHitEffect* hitEffect = (InteractHitEffect*)key.mInteraction;
		Piki* piki                   = (Piki*)hitEffect->mOwner;
		if (piki->mObjType == OBJTYPE_Piki && piki->getState() == PIKISTATE_Flying) {
			effectMgr->create(EffectMgr::EFF_Piki_BigHit, hitEffect->mEffectPos, nullptr, nullptr);
			if (hitEffect->mCollPart->isBouncy()) {
				teki.playEventSound(&teki, SE_KABUTO_FLIP);
			}
		}

		break;
	}
	}

	return false;
}

/*
 * --INFO--
 * Address:	801C6EA4
 * Size:	00041C
 */
void TAIbeatleStrategy::act(Teki& teki)
{
	YaiStrategy::act(teki);

	zen::particleGenerator* ptclGen;
	Matrix4f eyeMtx;
	Vector3f vec1;
	Vector3f vec2;
	Vector3f vec3;

	CollPart* eyePart = teki.mCollInfo->getSphere('me_l');

	if (eyePart != nullptr) {
		eyeMtx = eyePart->getMatrix();

		vec3.set(eyeMtx.mMtx[0][2], eyeMtx.mMtx[1][2], eyeMtx.mMtx[2][2]);
		vec3.normalize();
		vec3.multiply(-2.0f);

		vec2.set(eyeMtx.mMtx[0][1], eyeMtx.mMtx[1][1], eyeMtx.mMtx[2][1]);
		vec2.normalize();
		vec2.multiply(-2.0f);

		vec1.set(eyeMtx.mMtx[0][0], eyeMtx.mMtx[1][0], eyeMtx.mMtx[2][0]);
		vec1.normalize();
		vec1.multiply(3.0f);

		ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk0);
		if (ptclGen != nullptr) {
			ptclGen->startGen();
			ptclGen->setEmitPos(eyePart->mCentre + vec1 + vec2 + vec3);
		}
	}

	eyePart = teki.mCollInfo->getSphere('me_r');
	if (eyePart != nullptr) {
		eyeMtx = eyePart->getMatrix();

		vec3.set(eyeMtx.mMtx[0][2], eyeMtx.mMtx[1][2], eyeMtx.mMtx[2][2]);
		vec3.normalize();
		vec3.multiply(2.0f);

		vec2.set(eyeMtx.mMtx[0][1], eyeMtx.mMtx[1][1], eyeMtx.mMtx[2][1]);
		vec2.normalize();
		vec2.multiply(-2.0f);

		vec1.set(eyeMtx.mMtx[0][0], eyeMtx.mMtx[1][0], eyeMtx.mMtx[2][0]);
		vec1.normalize();
		vec1.multiply(3.0f);

		ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk1);
		if (ptclGen != nullptr) {
			ptclGen->startGen();
			ptclGen->setEmitPos(eyePart->mCentre + vec1 + vec2 + vec3);
		}
	}
}

/*
 * --INFO--
 * Address:	801C72C0
 * Size:	000024
 */
void TAIbeatleAnimation::makeDefaultAnimations()
{
	if (mAnimMgr != nullptr) {
		gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_Beatle]->mShape;
	}
}
