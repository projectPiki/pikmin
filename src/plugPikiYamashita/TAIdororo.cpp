#include "TAI/Dororo.h"

#include "DebugLog.h"
#include "ItemMgr.h"
#include "MapCode.h"
#include "NaviMgr.h"
#include "Pcam/CameraManager.h"
#include "Pellet.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "TAI/Aattack.h"
#include "TAI/Aeffect.h"
#include "TAI/Ajudge.h"
#include "TAI/Amove.h"
#include "TAI/Areaction.h"
#include "TAI/EffectAttack.h"
#include "TekiConditions.h"
#include "TekiParameters.h"
#include "zen/CallBack.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(32)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TAIdororo")

namespace {

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
CollPart* getCollPartPtr(Teki& teki, u32 partID)
{
	CollPart* part = teki.mCollInfo->getSphere(partID);
	if (!part) {
		const char* s = reinterpret_cast<char*>(&partID);
		ERROR("CollPart [%c%c%c%c] is not found.\n", s[0], s[1], s[2], s[3]);
	}
	return part;
}

/**
 * @todo: Documentation
 */
void setDororoEffect(Teki& teki)
{
	CollPart* leftEye = getCollPartPtr(teki, 'leye');
	if (leftEye) {
		zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Dororo_Eye, leftEye->mCentre, nullptr, nullptr);
		if (ptclGen) {
			ptclGen->setEmitPosPtr(&leftEye->mCentre);
		}
		teki.setPtclGenPtr(YTeki::PTCL_Unk0, ptclGen);
	}

	CollPart* rightEye = getCollPartPtr(teki, 'reye');
	if (rightEye) {
		zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Dororo_Eye, rightEye->mCentre, nullptr, nullptr);
		if (ptclGen) {
			ptclGen->setEmitPosPtr(&rightEye->mCentre);
		}
		teki.setPtclGenPtr(YTeki::PTCL_Unk1, ptclGen);
	}

	CollPart* kb = getCollPartPtr(teki, 'kb01');
	if (kb) {
		zen::particleGenerator* ptclSmoke = effectMgr->create(EffectMgr::EFF_Dororo_BodySmoke, kb->mCentre, nullptr, nullptr);
		if (ptclSmoke) {
			ptclSmoke->setEmitPosPtr(&kb->mCentre);
		}
		teki.setPtclGenPtr(YTeki::PTCL_Unk6, ptclSmoke);

		zen::particleGenerator* ptclFrag = effectMgr->create(EffectMgr::EFF_Dororo_BodyFragments, kb->mCentre, nullptr, nullptr);
		if (ptclFrag) {
			ptclFrag->setEmitPosPtr(&kb->mCentre);
		}
		teki.setPtclGenPtr(YTeki::PTCL_Unk2, ptclFrag);

		zen::particleGenerator* ptclSpecks = effectMgr->create(EffectMgr::EFF_Dororo_BodySpecks, kb->mCentre, nullptr, nullptr);
		if (ptclSpecks) {
			ptclSpecks->setEmitPosPtr(&kb->mCentre);
		}
		teki.setPtclGenPtr(YTeki::PTCL_Unk3, ptclSpecks);

		zen::particleGenerator* ptclGlow = effectMgr->create(EffectMgr::EFF_Dororo_BodyGlow, kb->mCentre, nullptr, nullptr);
		teki.setPtclGenPtr(YTeki::PTCL_Unk5, ptclGlow);
	}

	CollPart* trail = getCollPartPtr(teki, 'mn01');
	if (trail) {
		zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Dororo_BodyTrail, trail->mCentre, nullptr, nullptr);
		if (ptclGen) {
			ptclGen->setEmitPosPtr(&trail->mCentre);
		}
		teki.setPtclGenPtr(YTeki::PTCL_Unk4, ptclGen);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000DC
 */
void killDororoEffect(Teki& teki)
{
	for (int i = 0; i < YTeki::PTCL_COUNT; i++) {
		zen::particleGenerator* ptclGen = teki.getPtclGenPtr((YTeki::ptclIndexFlag)i);
		if (ptclGen) {
			ptclGen->finish();
		}
	}
}
} // namespace

/**
 * @brief TODO
 */
struct TAIAinitDororo : public TaiAction {
public:
	TAIAinitDororo(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.mCollisionRadius = 64.0f;
		teki.mPathHandle      = 'test';
		teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
		teki.setDesire(0.0f);
	}
	virtual bool act(Teki& teki) // _10
	{
		PRINT("INIT FINISH \n");
		return true;
	}

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgravityDororo : public TaiAction {
public:
	TAIAgravityDororo(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		teki.setDororoGravity(gsys->getFrameTime() * 0.98f);
	}
	virtual bool act(Teki& teki) // _10
	{
		if (teki.getYFromSeaLevel() > 0.0f) {
			teki.mTargetVelocity.y -= teki.getDororoGravity();
		} else {
			teki.mTargetVelocity.y = 0.0f;
		}

		teki.mVelocity.y = teki.mTargetVelocity.y;
		return false;
	}

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAcheckBarkDororo : public TaiAction {
public:
	TAIAcheckBarkDororo(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		bool doBark = false;
		Iterator iter(itemMgr->getPikiHeadMgr());
		CI_LOOP(iter)
		{
			Creature* sprout = *iter;
			if (sprout && sprout->getPosition().distance(teki.getPosition()) < teki.getParameterF(TPF_VisibleRange)) {
				teki.addDesire(gsys->getFrameTime());
			}
		}

		if (teki.getDesire() > 4.0f) {
			teki.setDesire(0.0f);
			doBark = true;
		}

		return doBark;
	}

protected:
	// _04     = VTBL
	// _00-_08 = TaiAction
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAbarkDororo : public TAIAmotionLoop {
public:
	TAIAbarkDororo(int nextState, int motionIdx, f32 frameMax)
	    : TAIAmotionLoop(nextState, motionIdx, frameMax)
	{
	}

	virtual void start(Teki& teki) { TAIAmotionLoop::start(teki); } // _08
	virtual bool act(Teki& teki)                                    // _10
	{
		bool res = false;
		if (TAIAmotionLoop::act(teki) && teki.mTekiAnimator->isFinishing()) {
			res = true;
		}

		if (teki.mCurrentAnimEvent == KEY_Action0) {
			PRINT("BARK! \n");
			Navi* navi = naviMgr->getNavi();
			Iterator iter(itemMgr->getPikiHeadMgr());
			CI_LOOP(iter)
			{
				Creature* sprout = *iter;
				if (sprout && sprout->getPosition().distance(teki.getPosition()) < teki.getParameterF(TPF_VisibleRange)) {
					PRINT("Bikkuri %08x \n", sprout);
					sprout->stimulate(InteractBikkuri(navi));
				}
			}

			CollPart* part = teki.mCollInfo->getSphere('mn01');
			if (part) {
				effectMgr->create(EffectMgr::EFF_Dororo_HowlZigZags, part->mCentre, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Dororo_HowlRipples, part->mCentre, nullptr, nullptr);
				effectMgr->create(EffectMgr::EFF_Dororo_HowlHalo, part->mCentre, nullptr, nullptr);
			}
			killDororoEffect(teki);
			setDororoEffect(teki);
			cameraMgr->startVibrationEvent(3, teki.getPosition());
			teki.playEventSound(&teki, SE_DORORO_CRY);
			rumbleMgr->start(RUMBLE_Unk5, 0, teki.getPosition());
		}

		return res;
	}

protected:
	// _04     = VTBL
	// _00-_10 = TAIAmotionLoop
};

/**
 * @brief TODO
 */
struct TAIAtransformationDororo : public TAIAreserveMotion {
public:
	TAIAtransformationDororo(int nextState, int motionIdx)
	    : TAIAreserveMotion(nextState, motionIdx)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAreserveMotion::start(teki);
		teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
		teki.clearTekiOption(BTeki::TEKI_OPTION_LIFE_GAUGE_VISIBLE);
		teki.playEventSound(&teki, SE_DORORO_DEAD);
	}
	virtual bool act(Teki& teki) // _10
	{
		if (TAIAreserveMotion::act(teki) && teki.mCurrentAnimEvent == KEY_Finished) {
			teki.flick();
			teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
			teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
			corpse(teki);
			teki.die();
			for (int i = 0; i < YTeki::PTCL_COUNT; i++) {
				zen::particleGenerator* ptclGen = teki.getPtclGenPtr((YTeki::ptclIndexFlag)i);
				if (ptclGen) {
					ptclGen->finish();
				}
			}
			teki.playEventSound(&teki, SE_DORORO_CRASH);
		}

		return true;
	}

protected:
	void corpse(Teki& teki)
	{
		int typeID = TekiMgr::getTypeId(teki.mTekiType);
		ID32 unused(typeID);
		teki.becomePellet(typeID, teki.getCentre(), teki.mFaceDirection);
		if (!teki.mPellet) {
			ERROR("?dieSoon:%08x:pellet==null\n", this);
			return;
		}
		NVector3f vel;
		teki.outputDirectionVector(vel);
		vel.scale(teki.getParameterF(TPF_CorpseVelocityHoriz));
		vel.y = teki.getParameterF(TPF_CorpseVelocityVert);
		teki.mPellet->mVelocity.set(vel);
		teki.detachGenerator();
		teki.mDeadState = 2;
	}

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
};

/**
 * @brief TODO
 */
struct TAIAbirthDororo : public TAIAreserveMotion {
public:
	TAIAbirthDororo(int nextState, int motionIdx)
	    : TAIAreserveMotion(nextState, motionIdx)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAreserveMotion::start(teki);
		setDororoEffect(teki);
		zen::particleGenerator* ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk5);
		if (ptclGen) {
			ptclGen->stopGen();
		}

		// someone's excited about the progg.
		PRINT("BIRTH !!! $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		PRINT("BIRTH !!! \n");
		PRINT("BIRTH !!! \n");
		PRINT("BIRTH !!! \n");
	}
	virtual bool act(Teki& teki) // _10
	{
		bool res = false;
		if (TAIAreserveMotion::act(teki) && teki.mTekiAnimator->isFinishing()) {
			teki.setTekiOption(BTeki::TEKI_OPTION_ATARI);
			teki.startFlying();
			teki.mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			teki.mVelocity.set(0.0f, 0.0f, 0.0f);
			zen::particleGenerator* ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk5);
			if (ptclGen) {
				ptclGen->startGen();
			}
			res = true;
		}

		return res;
	}

protected:
	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAwaitDororo : public TAIAwait {
public:
	TAIAwaitDororo(int nextState, int motionIdx)
	    : TAIAwait(nextState, motionIdx, 0.0f)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAwait::start(teki);
		teki.setFrameCounterMax(teki.getParameterF(DOROROPF_WaitTime) + zen::Rand(teki.getParameterF(DOROROPF_WaitTime)));
	}

protected:
	virtual f32 getWaitCounterMax(Teki& teki) { return teki.getFrameCounterMax(); } // _1C

	// _04     = VTBL
	// _00-_08 = TAIAwait?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAflickingDororo : public TAIAflicking {
public:
	TAIAflickingDororo(int nextState, int motionIdx)
	    : TAIAflicking(nextState, motionIdx)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		TAIAflicking::start(teki);
		if (teki.isNaviWatch()) {
			playerState->mResultFlags.setOn(zen::RESFLAG_Dororo);
		}
	}
	virtual bool act(Teki& teki) // _10
	{
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			teki.playEventSound(&teki, SE_DORORO_SWING);
		}
		return TAIAflicking::act(teki);
	}

protected:
	// _04     = VTBL
	// _00-_08 = TAIAflicking?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAgoGoalPathDororo : public TAIAgoGoalPath {
public:
	TAIAgoGoalPathDororo(int nextState, int motionIdx)
	    : TAIAgoGoalPath(nextState, motionIdx)
	{
	}

protected:
	virtual f32 getWalkVelocity(Teki& teki) // _20
	{
		int pikiCount   = teki.countPikis(TekiStickerCondition(&teki));
		f32 speedFactor = f32(pikiCount) / teki.getParameterF(DOROROPF_PikiNumForMaxDrag);
		if (speedFactor > 1.0f) {
			speedFactor = 1.0f;
		}

		speedFactor = (1.0f - teki.getParameterF(DOROROPF_WalkingSpeedDragFactor) * speedFactor);

		return teki.getParameterF(TPF_WalkVelocity) * speedFactor;

		TekiStickerCondition(nullptr);
	}

	// _04     = VTBL
	// _00-_08 = TAIAgoGoalPath?
	// TODO: members
};

/**
 * @brief TODO
 */
struct TAIAkillTouchPiki : public TaiAction {
public:
	TAIAkillTouchPiki(int nextState)
	    : TaiAction(nextState)
	{
	}

	virtual bool act(Teki& teki) // _10
	{
		attack(teki, 'cent');
		attack(teki, 'kb01');
		attack(teki, 'mn01');
		return false;
	}

protected:
	void attack(Teki& teki, u32 partID)
	{
		CollPart* part = teki.mCollInfo->getSphere(partID);
		if (!part) {
			const char* s = reinterpret_cast<char*>(&partID);
			ERROR("CollPart [%c%c%c%c] is not found.\n", s[0], s[1], s[2], s[3]);
			return;
		}

		f32 range  = part->mRadius * 1.5f;
		Navi* navi = naviMgr->getNavi();
		if (part->mCentre.distance(navi->getPosition()) < range) {
			InteractAttack attack(&teki, nullptr, teki.getParameterF(TPF_AttackPower), false);
			navi->stimulate(attack);
		}

		Iterator iter(pikiMgr);
		CI_LOOP(iter)
		{
			Creature* piki = *iter;
			if (piki && part->mCentre.distance(piki->getPosition()) < range) {
				piki->stimulate(InteractKill(&teki, 0));
				iter.dec();
			}
		}
	}

	// _04     = VTBL
	// _00-_08 = TaiAction
};

/**
 * @brief TODO
 */
struct TAIAdyingDororo : public TAIAdying {
public:
	TAIAdyingDororo(int nextState, int motionIdx)
	    : TAIAdying(nextState, motionIdx)
	{
	}

	virtual void start(Teki& teki) // _08
	{
		CollPart* kb = teki.mCollInfo->getSphere('kb01');
		if (kb) {
			effectMgr->create(EffectMgr::EFF_Dororo_DeadFragments, kb->mCentre, nullptr, nullptr);
		}
		CollPart* mn = teki.mCollInfo->getSphere('mn01');
		if (mn) {
			effectMgr->create(EffectMgr::EFF_Dororo_DeadFumes, mn->mCentre, nullptr, nullptr);
		}

		TAIAdying::start(teki);
		killDororoEffect(teki);
		setDororoEffect(teki);
		teki.setFrameCounter(0.0f);
		teki.setFrameCounterMax(4.0f);
	}
	virtual bool act(Teki& teki) // _10
	{
		if (teki.mCurrentAnimEvent == KEY_Action0) {
			teki.playEventSound(&teki, SE_DORORO_DEAD);
		}

		if (teki.animationFinished() && teki.getTekiOption(BTeki::TEKI_OPTION_ATARI)) {
			zen::particleGenerator* ptcl0 = teki.getPtclGenPtr(YTeki::PTCL_Unk0);
			if (ptcl0) {
				ptcl0->finish();
			}
			zen::particleGenerator* ptcl1 = teki.getPtclGenPtr(YTeki::PTCL_Unk1);
			if (ptcl1) {
				ptcl1->finish();
			}
			zen::particleGenerator* ptcl5 = teki.getPtclGenPtr(YTeki::PTCL_Unk5);
			if (ptcl5) {
				ptcl5->finish();
			}
			zen::particleGenerator* ptcl3 = teki.getPtclGenPtr(YTeki::PTCL_Unk3);
			if (ptcl3) {
				ptcl3->finish();
			}

			teki.playEventSound(&teki, SE_DORORO_CRASH);
			teki.clearTekiOption(BTeki::TEKI_OPTION_ALIVE);
			teki.clearTekiOption(BTeki::TEKI_OPTION_ATARI);
		}

		if (!teki.getTekiOption(BTeki::TEKI_OPTION_ATARI)) {
			teki.addFrameCounter(gsys->getFrameTime());
			if (teki.getFrameCounter() > teki.getFrameCounterMax()) {
				TAIAdying::act(teki);
				killDororoEffect(teki);
			}
		}

		return true;
	}

protected:
	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

/**
 * @todo: Documentation
 */
TAIdororoSoundTable::TAIdororoSoundTable()
    : PaniSoundTable(6)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_DORORO_WALK);
	}
}

/**
 * @todo: Documentation
 */
TAIdororoParameters::TAIdororoParameters()
    : TekiParameters(DOROROPI_COUNT, DOROROPF_COUNT)
{
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<int>* iParams = multiP->mIntParams->mParaInfo;
	ParaParameterInfo<f32>* fParams = multiP->mFloatParams->mParaInfo;
	int j                           = TPF_COUNT;
	fParams[j++].init("最短寿命（秒）", 0.0f, 1200.0f);              // 'min lifespan (sec)'
	fParams[j++].init("寿命乱数（秒）", 0.0f, 1200.0f);              // 'random lifespan (sec)'
	fParams[j++].init("歩く速度を遅くする最大ピキ数", 0.0f, 100.0f); // 'max num steps to slow down walking speed'
	fParams[j++].init("歩く速度が遅くなる最大％", 0.0f, 1.0f);       // 'max % walking speed slower'
	fParams[j++].init("ウエイト（秒）", 0.0f, 30.0f);                // 'wait (sec)'

	j = TPI_COUNT;
	iParams[j++].init("ピクミンを殺す最大数", 0, 100); // 'max num pikmin killed'

	multiP->setF(DOROROPF_MinLifespan, 240.0f);
	multiP->setF(DOROROPF_RandomLifespan, 30.0f);
	multiP->setF(DOROROPF_PikiNumForMaxDrag, 20.0f);
	multiP->setF(DOROROPF_WalkingSpeedDragFactor, 0.5f);
	multiP->setF(DOROROPF_WaitTime, 3.0f);

	multiP->setI(DOROROPI_MaxPikminKill, 5);

	multiP->setI(TPI_SpawnType, TEKI_NULL);
	multiP->setI(TPI_SwallowCount, 5);
	multiP->setI(TPI_FlickPikiCount1, 2);
	multiP->setI(TPI_FlickPikiCount2, 5);
	multiP->setI(TPI_FlickPikiCount3, 10);
	multiP->setI(TPI_FlickDamageCount1, 30);
	multiP->setI(TPI_FlickDamageCount2, 30);
	multiP->setI(TPI_FlickDamageCount3, 30);
	multiP->setI(TPI_FlickDamageCount4, 30);
	multiP->setI(TPI_CullingType, CULLAI_NeverCullAI);

	multiP->setF(TPF_Weight, 100.0f);
	multiP->setF(TPF_Scale, 1.0f);
	multiP->setF(TPF_Life, 500000.0f);
	multiP->setF(TPF_WalkVelocity, 100.0f);
	multiP->setF(TPF_RunVelocity, 120.0f);
	multiP->setF(TPF_TurnVelocity, 15.0f * PI / 180.0f);
	multiP->setF(TPF_VisibleRange, 300.0f);
	multiP->setF(TPF_VisibleAngle, 270.0f);
	multiP->setF(TPF_VisibleHeight, 100.0f);
	multiP->setF(TPF_AttackableRange, 40.0f);
	multiP->setF(TPF_AttackableAngle, 30.0f);
	multiP->setF(TPF_AttackRange, 30.0f);
	multiP->setF(TPF_AttackHitRange, 9.0f);
	multiP->setF(TPF_AttackPower, 5.0f);
	multiP->setF(TPF_DangerTerritoryRange, 300.0f);
	multiP->setF(TPF_SafetyTerritoryRange, 120.0f);

	multiP->setF(TPF_DamageMotionPeriod, 0.3f);
	multiP->setF(TPF_DamageMotionAmplitude, 0.05f);

	multiP->setF(TPF_FlickProbability, 1.0f);
	multiP->setF(TPF_UpperFlickPower, 50.0f);
	multiP->setF(TPF_LowerFlickPower, 0.0f);
	multiP->setF(TPF_UpperAttackPower, 0.0f);
	multiP->setF(TPF_LowerAttackPower, 0.0f);

	multiP->setF(TPF_LifeRecoverRate, 0.01f);
	multiP->setF(TPF_LifeGaugeOffset, 45.0f);
	multiP->setF(TPF_ShadowSize, 0.0f);
	multiP->setF(TPF_TraceAngle, 60.0f);
	multiP->setF(TPF_SpawnDistance, 0.0f);
	multiP->setF(TPF_SpawnHeight, 20.0f);
	multiP->setF(TPF_SpawnVelocity, 0.0f);

	multiP->setI(TPI_CorpseType, TEKICORPSE_LeaveCorpse);
}

/**
 * @todo: Documentation
 */
TAIdororoStrategy::TAIdororoStrategy()
    : YaiStrategy(DOROROSTATE_COUNT, DOROROSTATE_Init)
{
	TAIAinitDororo* init             = new TAIAinitDororo(DOROROSTATE_Birth);
	TAIAdeadCheck* deadCheck         = new TAIAdeadCheck(DOROROSTATE_Dead);
	TAIAdyingDororo* dying           = new TAIAdyingDororo(TAI_NO_TRANSIT, TekiMotion::Dead);
	TAIAdamage* damage               = new TAIAdamage(TAI_NO_TRANSIT, true);
	TAIAstop* stop                   = new TAIAstop(TAI_NO_TRANSIT);
	TAIAkillTouchPiki* killTouchPiki = new TAIAkillTouchPiki(DOROROSTATE_Transform);
	TAIAgoGoalPathDororo* goGoalPath = new TAIAgoGoalPathDororo(DOROROSTATE_BarkGoal, TekiMotion::Move1);
	TAIAflickCheck* flickCheck       = new TAIAflickCheck(DOROROSTATE_Flick, -1);
	TAIAflickingDororo* flicking     = new TAIAflickingDororo(TAI_RETURN_TRANSIT, TekiMotion::Flick);
	TAIAwaitDororo* wait             = new TAIAwaitDororo(DOROROSTATE_LookAround, TekiMotion::Wait1);
	TAIAvisiblePiki* visiblePiki     = new TAIAvisiblePiki(DOROROSTATE_GoTargetPiki);
	TAIAnoReaction* noReact          = new TAIAnoReaction(DOROROSTATE_Idle);
	TAIAgoTargetPiki* goTargetPiki   = new TAIAgoTargetPiki(DOROROSTATE_GoGoalPath, TekiMotion::Move1);
	TAIAeffCloudOfDust* effCloud
	    = new TAIAeffCloudOfDust(TAI_NO_TRANSIT, EffectMgr::EFF_CloudOfDust_2, SOUND_NULL, -0.1f, 2, 'lhnd', 'rhnd', 0, 0);
	TAIAbirthDororo* birth              = new TAIAbirthDororo(DOROROSTATE_GoGoalPath, TekiMotion::Type1);
	TAIAtransformationDororo* transform = new TAIAtransformationDororo(TAI_NO_TRANSIT, TekiMotion::Type4);
	TAIAbarkDororo* bark1               = new TAIAbarkDororo(DOROROSTATE_Wait, TekiMotion::Type2, 2.0f);
	TAIAbarkDororo* bark2               = new TAIAbarkDororo(TAI_RETURN_TRANSIT, TekiMotion::Type2, 2.0f);
	TAIAreserveMotion* reserveMotion    = new TAIAreserveMotion(DOROROSTATE_Wait, TekiMotion::Type3);
	TAIAcheckBarkDororo* checkBark      = new TAIAcheckBarkDororo(DOROROSTATE_Bark);
	TAIAgravityDororo* gravity          = new TAIAgravityDororo(TAI_NO_TRANSIT);

	// INIT STATE - here we go.
	TaiState* state = new TaiState(1);
	int j           = 0;
	state->setAction(j++, init); // when done initialising, go to birth
	setState(DOROROSTATE_Init, state);

	// DEAD STATE - dead.
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, dying);
	state->setAction(j++, stop);
	state->setAction(j++, effCloud);
	state->setAction(j++, gravity);
	setState(DOROROSTATE_Dead, state);

	// BIRTH STATE - spawn of satan, now spawning
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, killTouchPiki); // this is always false - otherwise, would transform??
	state->setAction(j++, effCloud);
	state->setAction(j++, birth); // when done spawning, go to 3
	setState(DOROROSTATE_Birth, state);

	// GO GOAL PATH STATE - path to an onyon
	state = new TaiState(8);
	j     = 0;
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);     // if dead, go to dead
	state->setAction(j++, checkBark);     // if planted pikis, go to bark (then back)
	state->setAction(j++, killTouchPiki); // this is always false - otherwise, would transform??
	state->setAction(j++, goGoalPath);    // when reach end, bark
	state->setAction(j++, flickCheck);    // if flick, go to flick
	state->setAction(j++, effCloud);
	state->setAction(j++, gravity);
	setState(DOROROSTATE_GoGoalPath, state);

	// FLICK STATE - flicking pikis and navis
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, flicking); // when done flicking, return to previous state
	state->setAction(j++, effCloud);
	state->setAction(j++, gravity);
	setState(DOROROSTATE_Flick, state);

	// WAIT STATE - we're at an onyon, so now we spawn camp.
	state = new TaiState(9);
	j     = 0;
	state->setAction(j++, stop);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);     // if dead, go to dead
	state->setAction(j++, checkBark);     // if there are planted pikis, go to bark (then back)
	state->setAction(j++, killTouchPiki); // this is always false - otherwise, would transform??
	state->setAction(j++, wait);          // if we've waited long enough, go to 6
	state->setAction(j++, flickCheck);    // if flick, go to flick
	state->setAction(j++, effCloud);
	state->setAction(j++, gravity);
	setState(DOROROSTATE_Wait, state);

	// LOOK AROUND STATE - check for pikmin to chase
	state = new TaiState(3);
	j     = 0;
	state->setAction(j++, gravity);
	state->setAction(j++, visiblePiki); // if visible piki, go to the target piki
	state->setAction(j++, noReact);     // if nothing to chase, go to idle anim
	setState(DOROROSTATE_LookAround, state);

	// IDLE STATE - nothing to see here
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, gravity);
	state->setAction(j++, stop);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);     // if dead, go to dead
	state->setAction(j++, killTouchPiki); // this is always false - otherwise, would transform??
	state->setAction(j++, reserveMotion); // if anim is done, go to wait
	state->setAction(j++, effCloud);
	setState(DOROROSTATE_Idle, state);

	// GO TARGET PIKI STATE - chasing a piki.
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, gravity);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);     // if dead, go to dead
	state->setAction(j++, killTouchPiki); // this is always false - otherwise, would transform??
	state->setAction(j++, goTargetPiki);  // if we reach or lose the piki, go back to the onyon
	state->setAction(j++, flickCheck);    // if flick, go to flick
	state->setAction(j++, effCloud);
	setState(DOROROSTATE_GoTargetPiki, state);

	// TRANSFORM STATE - this seems to be a dead end?
	state = new TaiState(4);
	j     = 0;
	state->setAction(j++, gravity);
	state->setAction(j++, transform);
	state->setAction(j++, stop);
	state->setAction(j++, effCloud);
	setState(DOROROSTATE_Transform, state);

	// BARK GOAL STATE - bark (when first reaching an onyon)
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, gravity);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);     // if dead, go to dead
	state->setAction(j++, killTouchPiki); // this is always false - otherwise, would transform??
	state->setAction(j++, bark1);         // when done barking, go to wait
	state->setAction(j++, effCloud);
	state->setAction(j++, stop);
	setState(DOROROSTATE_BarkGoal, state);

	// BARK STATE - bark (when bark check is satisfied)
	state = new TaiState(7);
	j     = 0;
	state->setAction(j++, gravity);
	state->setAction(j++, damage);
	state->setAction(j++, deadCheck);     // if dead, go to dead
	state->setAction(j++, killTouchPiki); // this is always false - otherwise, would transform??
	state->setAction(j++, bark2);         // when done barking, return to previous
	state->setAction(j++, effCloud);
	state->setAction(j++, stop);
	setState(DOROROSTATE_Bark, state);
}

/**
 * @todo: Documentation
 */
void TAIdororoStrategy::act(Teki& teki)
{
	zen::particleGenerator* ptclGen;

	YaiStrategy::act(teki);
	CollPart* kb = teki.mCollInfo->getSphere('kb01');
	if (!kb) {
		return;
	}

	Matrix4f mtx = kb->getMatrix();
	Vector3f vec;
	vec.set(-mtx.mMtx[0][0], -mtx.mMtx[1][0], -mtx.mMtx[2][0]);
	ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk2); // fragments
	if (ptclGen) {
		ptclGen->setEmitDir(vec);
		ptclGen->setEmitVelocity(Vector3f(teki.mVelocity * 0.035f));
	}

	ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk3); // specks
	if (ptclGen) {
		ptclGen->setEmitDir(vec);
		ptclGen->setEmitVelocity(Vector3f(teki.mVelocity * 0.035f));
	}

	ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk6); // smoke
	if (ptclGen) {
		ptclGen->setEmitDir(vec);
		ptclGen->setEmitVelocity(Vector3f(teki.mVelocity * 0.0175f));
	}

	ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk4); // body trail
	if (ptclGen) {
		ptclGen->setEmitVelocity(Vector3f(teki.mVelocity * 0.01f));
	}

	ptclGen = teki.getPtclGenPtr(YTeki::PTCL_Unk5); // glow
	if (ptclGen) {
		Vector3f emitPos;
		emitPos.set(vec * -16.0f);
		emitPos.add(kb->mCentre);
		ptclGen->setEmitPos(emitPos);
	}
}

/**
 * @todo: Documentation
 */
void TAIdororoStrategy::draw(Teki& teki, Graphics& gfx)
{
	YaiStrategy::draw(teki, gfx);
}

/**
 * @todo: Documentation
 */
void TAIdororoStrategy::createEffect(Teki& teki, int effType)
{
	TekiStrategy::createEffect(teki, effType);
	switch (effType) {
	case 0:
	{
		createCloudOfDust(teki, mLeftHand);
		break;
	}
	case 1:
	{
		createCloudOfDust(teki, mRightHand);
		break;
	}
	case 2:
	{
		createCloudOfDust(teki, mLeftHand);
		createCloudOfDust(teki, mRightHand);
		break;
	}
	}
}

/**
 * @todo: Documentation
 */
void TAIdororoStrategy::createCloudOfDust(Teki& teki, CollPart* part)
{
	if (part->mCentre.y - mapMgr->getMinY(part->mCentre.x, part->mCentre.z, true) < 30.0f) {
		Vector3f partPos(part->mCentre);
		partPos.y        = mapMgr->getMinY(partPos.x, partPos.z, true);
		CollTriInfo* tri = mapMgr->getCurrTri(partPos.x, partPos.z, true);

		if (tri) {
			if (MapCode::getAttribute(tri) == ATTR_Water) {
				effectMgr->create(EffectMgr::EFF_Frog_BubbleRingS, partPos, nullptr, nullptr);
				teki.playEventSound(&teki, SE_FLOG_WATERJUMP);
			} else {
				effectMgr->create(EffectMgr::EFF_SmokeRing_M, partPos, nullptr, nullptr);
				teki.playEventSound(&teki, SE_DORORO_WALK);
			}
		} else {
			effectMgr->create(EffectMgr::EFF_SmokeRing_M, partPos, nullptr, nullptr);
			teki.playEventSound(&teki, SE_DORORO_WALK);
		}
	}

	rumbleMgr->start(RUMBLE_Unk10, 0, part->mCentre);
}

/**
 * @todo: Documentation
 */
void TAIdororoStrategy::start(Teki& teki)
{
	YaiStrategy::start(teki);
	mLeftHand  = getCollPartPtr(teki, 'lhnd');
	mRightHand = getCollPartPtr(teki, 'rhnd');

	if (!mLeftHand || !mRightHand) {
		PRINT("ERROR! No hand collPart.L:%08x R:&08x\n", mLeftHand, mRightHand);
		ERROR("ERROR! No hand collPart.L:%08x R:&08x\n", mLeftHand, mRightHand);
	}
}

/**
 * @todo: Documentation
 */
void TAIdororoAnimation::makeDefaultAnimations()
{
	if (!mAnimMgr) {
		return;
	}

	gsys->mCurrentShape = tekiMgr->mTekiShapes[TEKI_KabekuiB]->mShape; // not a male sheargrub.
	addAnimation("tekis/dororo/motion/dead.dca");

	addAnimation("tekis/dororo/motion/damage.dca");

	addAnimation("tekis/dororo/motion/wait1.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/dororo/motion/wait2.dca");
	addInfoKey(0, 0);
	addInfoKey(1, 1);

	addAnimation("tekis/dororo/motion/waitact1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/dororo/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/dororo/motion/move1.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/dororo/motion/move2.dck");
	setAnimFlags(ANIMFLAG_UseDynamicSpeed | ANIMFLAG_UseCache);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/dororo/motion/attack.dca");
	addKeyFrame(58);
	addInfoKey(1, 2);

	addAnimation("tekis/dororo/motion/type1.dck");
	addKeyFrame(8);
	addKeyFrame(43);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/dororo/motion/type2.dca");
	addKeyFrame(32);
	addInfoKey(1, 2);
}
