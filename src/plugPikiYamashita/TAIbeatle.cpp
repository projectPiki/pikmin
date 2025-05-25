#include "TAI/Beatle.h"
#include "DebugLog.h"
#include "TAI/Aeffect.h"
#include "PikiState.h"

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
		CollPart* kutiPart = teki.mCollInfo->getSphere('kuti');

		switch (teki.mCurrentAnimEvent) {
		case KEY_Action1:
			teki.enableStick();

			if (kutiPart != nullptr) {
				Matrix4f mtx = kutiPart->getMatrix();

				Vector3f emitDir;
				emitDir.set(mtx.mMtx[0][0], mtx.mMtx[1][0], mtx.mMtx[2][0]);

				zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_Flick1, kutiPart->mCentre, nullptr, nullptr);
				if (ptclGen != nullptr) {
					ptclGen->setEmitPosPtr(&kutiPart->mCentre);
					ptclGen->setEmitDir(emitDir);
				}
			}
			break;

		case KEY_Action2:
			teki.disableStick();

			zen::particleGenerator* ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk2);
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
			teki.mTekiSwitches.m1 = false;
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
			teki.mTekiSwitches.m1 = true;
			break;
		}

		if (teki.mTekiSwitches.m1) {
			runAway(teki);
		}

		TAIAflickingAfterMotionLoop::act(teki);
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
			CollPart* steamEffectPart;
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
				zen::particleGenerator* ptclGen
				    = effectMgr->create(EffectMgr::EFF_Beatle_Flick2, steamEffectPart->mCentre, nullptr, nullptr);
				if (ptclGen != nullptr) {
					ptclGen->setEmitPosPtr(&steamEffectPart->mCentre);
				}
				teki.setPtclGenPtr((YTeki::ptclIndexFlag)(YTeki::PTCL_Unk3 + i), ptclGen);
			}
		}

		CollPart* kutiPart = teki.mCollInfo->getSphere('kuti');
		if (kutiPart != nullptr) {
			Matrix4f mtx = kutiPart->getMatrix();

			Vector3f emitDir;
			emitDir.set(mtx.mMtx[0][0], mtx.mMtx[1][0], mtx.mMtx[2][0]);

			zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Beatle_Flick2, kutiPart->mCentre, nullptr, nullptr);
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
	TAIArockAttack* rockAttack                     = new TAIArockAttack(TAIbeatleStateID::Unk13, 11, 8);
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
	u32 badCompiler;

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

	Matrix4f eyeMtx;
	zen::particleGenerator* ptclGen;

	CollPart* eyePart = teki.mCollInfo->getSphere('me_l');

	Vector3f vec3;
	Vector3f vec2;
	Vector3f vec1;

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
			ptclGen->start();
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
			ptclGen->start();
			ptclGen->setEmitPos(eyePart->mCentre + vec1 + vec2 + vec3);
		}
	}

	// u32 bad[4];

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x198(r1)
	  stfd      f31, 0x190(r1)
	  stfd      f30, 0x188(r1)
	  stfd      f29, 0x180(r1)
	  stfd      f28, 0x178(r1)
	  stfd      f27, 0x170(r1)
	  stfd      f26, 0x168(r1)
	  stfd      f25, 0x160(r1)
	  stfd      f24, 0x158(r1)
	  stfd      f23, 0x150(r1)
	  stw       r31, 0x14C(r1)
	  mr        r31, r4
	  stw       r30, 0x148(r1)
	  stw       r29, 0x144(r1)
	  bl        0x22864
	  lis       r4, 0x6D65
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x5F6C
	  bl        -0x13D7E4
	  mr.       r29, r3
	  beq-      .loc_0x210
	  addi      r3, r1, 0xFC
	  addi      r4, r29, 0
	  bl        -0x13EFF0
	  lfs       f24, 0x104(r1)
	  lfs       f25, 0x114(r1)
	  fmuls     f1, f24, f24
	  lfs       f26, 0x124(r1)
	  fmuls     f0, f25, f25
	  fmuls     f2, f26, f26
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B92EC
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xA4
	  fdivs     f24, f24, f1
	  fdivs     f25, f25, f1
	  fdivs     f26, f26, f1

	.loc_0xA4:
	  lfs       f27, 0x100(r1)
	  lfs       f28, 0x110(r1)
	  fmuls     f1, f27, f27
	  lfs       f3, -0x45B0(r2)
	  fmuls     f0, f28, f28
	  lfs       f29, 0x120(r1)
	  fmuls     f24, f24, f3
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fmuls     f25, f25, f3
	  fmuls     f26, f26, f3
	  fadds     f1, f2, f0
	  bl        -0x1B9338
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xF0
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1
	  fdivs     f29, f29, f1

	.loc_0xF0:
	  lfs       f30, 0xFC(r1)
	  lfs       f31, 0x10C(r1)
	  fmuls     f1, f30, f30
	  lfs       f3, -0x45B0(r2)
	  fmuls     f0, f31, f31
	  lfs       f23, 0x11C(r1)
	  fmuls     f27, f27, f3
	  fmuls     f2, f23, f23
	  fadds     f0, f1, f0
	  fmuls     f28, f28, f3
	  fmuls     f29, f29, f3
	  fadds     f1, f2, f0
	  bl        -0x1B9384
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x13C
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1
	  fdivs     f23, f23, f1

	.loc_0x13C:
	  lfs       f0, -0x45BC(r2)
	  lwz       r30, 0x498(r31)
	  fmuls     f30, f30, f0
	  cmplwi    r30, 0
	  fmuls     f31, f31, f0
	  fmuls     f23, f23, f0
	  beq-      .loc_0x210
	  lwz       r0, 0x80(r30)
	  addi      r6, r1, 0x2C
	  addi      r5, r1, 0x28
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r30)
	  addi      r4, r1, 0x24
	  addi      r3, r1, 0xB4
	  lfs       f0, 0xC(r29)
	  fadds     f0, f0, f23
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x8(r29)
	  fadds     f0, f0, f31
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x4(r29)
	  fadds     f0, f0, f30
	  stfs      f0, 0x24(r1)
	  bl        -0x18FF20
	  lfs       f2, 0xBC(r1)
	  addi      r6, r1, 0x50
	  lfs       f1, 0xB8(r1)
	  addi      r5, r1, 0x4C
	  lfs       f0, 0xB4(r1)
	  fadds     f2, f2, f29
	  addi      r4, r1, 0x48
	  fadds     f1, f1, f28
	  addi      r3, r1, 0xC0
	  fadds     f0, f0, f27
	  stfs      f2, 0x50(r1)
	  stfs      f1, 0x4C(r1)
	  stfs      f0, 0x48(r1)
	  bl        -0x18FF58
	  lfs       f0, 0xC0(r1)
	  lfs       f1, 0xC4(r1)
	  fadds     f2, f0, f24
	  lfs       f0, 0xC8(r1)
	  fadds     f1, f1, f25
	  fadds     f0, f0, f26
	  stfs      f2, 0xCC(r1)
	  stfs      f1, 0xD0(r1)
	  stfs      f0, 0xD4(r1)
	  lwz       r3, 0xCC(r1)
	  lwz       r0, 0xD0(r1)
	  stw       r3, 0xC(r30)
	  stw       r0, 0x10(r30)
	  lwz       r0, 0xD4(r1)
	  stw       r0, 0x14(r30)

	.loc_0x210:
	  lis       r4, 0x6D65
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x5F72
	  bl        -0x13D9B0
	  mr.       r29, r3
	  beq-      .loc_0x3DC
	  addi      r3, r1, 0xFC
	  addi      r4, r29, 0
	  bl        -0x13F1BC
	  lfs       f31, 0x104(r1)
	  lfs       f30, 0x114(r1)
	  fmuls     f1, f31, f31
	  lfs       f29, 0x124(r1)
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B94B8
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x270
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x270:
	  lfs       f28, 0x100(r1)
	  lfs       f27, 0x110(r1)
	  fmuls     f1, f28, f28
	  lfs       f3, -0x45AC(r2)
	  fmuls     f0, f27, f27
	  lfs       f26, 0x120(r1)
	  fmuls     f31, f31, f3
	  fmuls     f2, f26, f26
	  fadds     f0, f1, f0
	  fmuls     f30, f30, f3
	  fmuls     f29, f29, f3
	  fadds     f1, f2, f0
	  bl        -0x1B9504
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2BC
	  fdivs     f28, f28, f1
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1

	.loc_0x2BC:
	  lfs       f25, 0xFC(r1)
	  lfs       f24, 0x10C(r1)
	  fmuls     f1, f25, f25
	  lfs       f3, -0x45B0(r2)
	  fmuls     f0, f24, f24
	  lfs       f23, 0x11C(r1)
	  fmuls     f28, f28, f3
	  fmuls     f2, f23, f23
	  fadds     f0, f1, f0
	  fmuls     f27, f27, f3
	  fmuls     f26, f26, f3
	  fadds     f1, f2, f0
	  bl        -0x1B9550
	  lfs       f0, -0x4620(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x308
	  fdivs     f25, f25, f1
	  fdivs     f24, f24, f1
	  fdivs     f23, f23, f1

	.loc_0x308:
	  lfs       f0, -0x45BC(r2)
	  lwz       r30, 0x49C(r31)
	  fmuls     f25, f25, f0
	  cmplwi    r30, 0
	  fmuls     f24, f24, f0
	  fmuls     f23, f23, f0
	  beq-      .loc_0x3DC
	  lwz       r0, 0x80(r30)
	  addi      r6, r1, 0x20
	  addi      r5, r1, 0x1C
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r30)
	  addi      r4, r1, 0x18
	  addi      r3, r1, 0x90
	  lfs       f0, 0xC(r29)
	  fadds     f0, f0, f23
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x8(r29)
	  fadds     f0, f0, f24
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x4(r29)
	  fadds     f0, f0, f25
	  stfs      f0, 0x18(r1)
	  bl        -0x1900EC
	  lfs       f2, 0x98(r1)
	  addi      r6, r1, 0x38
	  lfs       f1, 0x94(r1)
	  addi      r5, r1, 0x34
	  lfs       f0, 0x90(r1)
	  fadds     f2, f2, f26
	  addi      r4, r1, 0x30
	  fadds     f1, f1, f27
	  addi      r3, r1, 0x9C
	  fadds     f0, f0, f28
	  stfs      f2, 0x38(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  bl        -0x190124
	  lfs       f0, 0x9C(r1)
	  lfs       f1, 0xA0(r1)
	  fadds     f2, f0, f31
	  lfs       f0, 0xA4(r1)
	  fadds     f1, f1, f30
	  fadds     f0, f0, f29
	  stfs      f2, 0xA8(r1)
	  stfs      f1, 0xAC(r1)
	  stfs      f0, 0xB0(r1)
	  lwz       r3, 0xA8(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r3, 0xC(r30)
	  stw       r0, 0x10(r30)
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x14(r30)

	.loc_0x3DC:
	  lwz       r0, 0x19C(r1)
	  lfd       f31, 0x190(r1)
	  lfd       f30, 0x188(r1)
	  lfd       f29, 0x180(r1)
	  lfd       f28, 0x178(r1)
	  lfd       f27, 0x170(r1)
	  lfd       f26, 0x168(r1)
	  lfd       f25, 0x160(r1)
	  lfd       f24, 0x158(r1)
	  lfd       f23, 0x150(r1)
	  lwz       r31, 0x14C(r1)
	  lwz       r30, 0x148(r1)
	  lwz       r29, 0x144(r1)
	  addi      r1, r1, 0x198
	  mtlr      r0
	  blr
	*/
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
