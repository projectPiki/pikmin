#include "TAI/Dororo.h"
#include "TAI/Ajudge.h"
#include "TAI/Aeffect.h"
#include "TekiConditions.h"
#include "MapCode.h"
#include "SoundMgr.h"
#include "ItemMgr.h"
#include "PikiHeadItem.h"
#include "RumbleMgr.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "Pcam/CameraManager.h"
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
DEFINE_PRINT("TAIdororo")

namespace {
/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
CollPart* getCollPartPtr(Teki& teki, u32 partID)
{
	CollPart* part = teki.mCollInfo->getSphere(partID);
	if (!part) {
		ERROR("CollPart [%c%c%c%c] is not found.\n", ((u8*)&partID)[0], ((u8*)&partID)[1], ((u8*)&partID)[2], ((u8*)&partID)[3]);
	}
	return part;
}

/*
 * --INFO--
 * Address:	801D0FBC
 * Size:	0001E4
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

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void killDororoEffect(Teki& teki)
{
	for (int i = 0; i < 9; i++) {
		zen::particleGenerator* ptclGen = teki.getPtclGenPtr((YTeki::ptclIndexFlag)i);
		if (ptclGen) {
			ptclGen->finish();
		}
	}
}
} // namespace

/**
 * @brief TODO
 *
 * @note This is defined here cause it needs to use the ERROR function in this file, sigh.
 */
struct TAIAkillTouchPiki : public TaiAction {
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

	void attack(Teki& teki, u32 partID)
	{
		CollPart* part = teki.mCollInfo->getSphere(partID);
		if (!part) {
			ERROR("CollPart [%c%c%c%c] is not found.\n", ((u8*)&partID)[0], ((u8*)&partID)[1], ((u8*)&partID)[2], ((u8*)&partID)[3]);
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
 *
 * @note This is defined here cause it needs to use the ERROR function in this file, sigh.
 */
struct TAIAtransformationDororo : public TAIAreserveMotion {
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
			for (int i = 0; i < 9; i++) {
				zen::particleGenerator* ptclGen = teki.getPtclGenPtr((YTeki::ptclIndexFlag)i);
				if (ptclGen) {
					ptclGen->finish();
				}
			}
			teki.playEventSound(&teki, SE_DORORO_CRASH);
		}

		return true;
	}

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
 *
 * @note This is defined here cause it needs to use the PRINT function in this file, sigh.
 */
struct TAIAbarkDororo : public TAIAmotionLoop {
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
			rumbleMgr->start(5, 0, teki.getPosition());
		}

		return res;
	}

	// _04     = VTBL
	// _00-_10 = TAIAmotionLoop
};

/**
 * @brief TODO
 *
 * @note This is defined here cause it needs to use the PRINT function in this file, sigh.
 */
struct TAIAbirthDororo : public TAIAreserveMotion {
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

	// _04     = VTBL
	// _00-_0C = TAIAreserveMotion
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note This is defined here cause it needs to use the anonymous namespace functions in this file, sigh.
 */
struct TAIAdyingDororo : public TAIAdying {
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

	// _04     = VTBL
	// _00-_0C = TAIAdying?
	// TODO: members
};

/*
 * --INFO--
 * Address:	801D11A0
 * Size:	000084
 */
TAIdororoSoundTable::TAIdororoSoundTable()
    : PaniSoundTable(6)
{
	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = new PaniSound(i + SE_DORORO_WALK);
	}
}

/*
 * --INFO--
 * Address:	801D1224
 * Size:	0003C0
 */
TAIdororoParameters::TAIdororoParameters()
    : TekiParameters(DOROROPI_COUNT, DOROROPF_COUNT)
{
	ParaMultiParameters* multiP     = mParameters;
	ParaParameterInfo<int>* iParams = mParameters->mIntParams->mParaInfo;
	ParaParameterInfo<f32>* fParams = mParameters->mFloatParams->mParaInfo;
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

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802E
	  stw       r0, 0x4(r1)
	  li        r5, 0x37
	  stwu      r1, -0xD0(r1)
	  stw       r31, 0xCC(r1)
	  addi      r31, r4, 0x3D60
	  li        r4, 0x15
	  stw       r30, 0xC8(r1)
	  addi      r30, r3, 0
	  bl        -0x85504
	  lis       r3, 0x802E
	  addi      r0, r3, 0x4600
	  stw       r0, 0x0(r30)
	  li        r7, 0x32
	  li        r6, 0x33
	  lwz       r4, 0x84(r30)
	  li        r5, 0x34
	  li        r3, 0x35
	  lwz       r8, 0x4(r4)
	  li        r0, 0x36
	  lwz       r9, 0x0(r4)
	  mulli     r7, r7, 0xC
	  lwz       r10, 0x8(r8)
	  lwz       r11, 0x8(r9)
	  add       r8, r10, r7
	  addi      r7, r31, 0x1C
	  stw       r7, 0x0(r8)
	  mulli     r7, r6, 0xC
	  lfs       f7, -0x4360(r2)
	  mulli     r6, r5, 0xC
	  stfs      f7, 0x4(r8)
	  lfs       f0, -0x435C(r2)
	  mulli     r5, r3, 0xC
	  stfs      f0, 0x8(r8)
	  add       r7, r10, r7
	  addi      r3, r31, 0x2C
	  stw       r3, 0x0(r7)
	  mulli     r3, r0, 0xC
	  stfs      f7, 0x4(r7)
	  add       r8, r10, r6
	  stfs      f0, 0x8(r7)
	  addi      r6, r31, 0x3C
	  li        r0, 0x14
	  stw       r6, 0x0(r8)
	  mulli     r0, r0, 0xC
	  stfs      f7, 0x4(r8)
	  add       r9, r10, r5
	  lfs       f6, -0x4358(r2)
	  addi      r5, r31, 0x5C
	  add       r10, r10, r3
	  stfs      f6, 0x8(r8)
	  addi      r7, r31, 0x78
	  add       r11, r11, r0
	  stw       r5, 0x0(r9)
	  addi      r6, r31, 0x88
	  li        r5, 0
	  stfs      f7, 0x4(r9)
	  li        r3, 0x64
	  li        r8, 0x5
	  lfs       f5, -0x4354(r2)
	  li        r0, -0x1
	  stfs      f5, 0x8(r9)
	  stw       r7, 0x0(r10)
	  stfs      f7, 0x4(r10)
	  lfs       f4, -0x4350(r2)
	  stfs      f4, 0x8(r10)
	  stw       r6, 0x0(r11)
	  stw       r5, 0x4(r11)
	  stw       r3, 0x8(r11)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x434C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0xCC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x4348(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0xD0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4344(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4340(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD8(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x50(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x24(r3)
	  lwz       r3, 0x0(r4)
	  li        r7, 0x2
	  li        r6, 0xA
	  lwz       r3, 0x0(r3)
	  li        r5, 0x1E
	  li        r0, 0x1
	  stw       r7, 0x28(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x2C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x30(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x34(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x38(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x3C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x40(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x433C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x4338(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4334(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x4330(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x432C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4328(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4324(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4320(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x30(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x431C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x78(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4318(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x7C(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r30
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0x80(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4314(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x84(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x88(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x8C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x90(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4310(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x94(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x430C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x44(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x48(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4308(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x98(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x58(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0x5C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x60(r5)
	  lwz       r4, 0x0(r4)
	  lwz       r4, 0x0(r4)
	  stw       r0, 0x0(r4)
	  lwz       r0, 0xD4(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D15E4
 * Size:	000AD0
 */
TAIdororoStrategy::TAIdororoStrategy()
    : YaiStrategy(DOROROSTATE_COUNT, DOROROSTATE_Init)
{
	TAIAinitDororo* init             = new TAIAinitDororo(DOROROSTATE_Birth);
	TAIAdeadCheck* deadCheck         = new TAIAdeadCheck(DOROROSTATE_Dead);
	TAIAdyingDororo* dying           = new TAIAdyingDororo(TAI_NO_TRANSIT, 0);
	TAIAdamage* damage               = new TAIAdamage(TAI_NO_TRANSIT, true);
	TAIAstop* stop                   = new TAIAstop(TAI_NO_TRANSIT);
	TAIAkillTouchPiki* killTouchPiki = new TAIAkillTouchPiki(DOROROSTATE_Transform);
	TAIAgoGoalPathDororo* goGoalPath = new TAIAgoGoalPathDororo(DOROROSTATE_BarkGoal, 6);
	TAIAflickCheck* flickCheck       = new TAIAflickCheck(DOROROSTATE_Flick, -1);
	TAIAflickingDororo* flicking     = new TAIAflickingDororo(TAI_RETURN_TRANSIT, 9);
	TAIAwaitDororo* wait             = new TAIAwaitDororo(DOROROSTATE_LookAround, 2);
	TAIAvisiblePiki* visiblePiki     = new TAIAvisiblePiki(DOROROSTATE_GoTargetPiki);
	TAIAnoReaction* noReact          = new TAIAnoReaction(DOROROSTATE_Idle);
	TAIAgoTargetPiki* goTargetPiki   = new TAIAgoTargetPiki(DOROROSTATE_GoGoalPath, 6);
	TAIAeffCloudOfDust* effCloud
	    = new TAIAeffCloudOfDust(TAI_NO_TRANSIT, EffectMgr::EFF_CloudOfDust_2, SOUND_NULL, -0.1f, 2, 'lhnd', 'rhnd', 0, 0);
	TAIAbirthDororo* birth              = new TAIAbirthDororo(DOROROSTATE_GoGoalPath, 10);
	TAIAtransformationDororo* transform = new TAIAtransformationDororo(TAI_NO_TRANSIT, 13);
	TAIAbarkDororo* bark1               = new TAIAbarkDororo(DOROROSTATE_Wait, 11, 2.0f);
	TAIAbarkDororo* bark2               = new TAIAbarkDororo(TAI_RETURN_TRANSIT, 11, 2.0f);
	TAIAreserveMotion* reserveMotion    = new TAIAreserveMotion(DOROROSTATE_Wait, 12);
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

/*
 * --INFO--
 * Address:	801D20B4
 * Size:	0003C8
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

/*
 * --INFO--
 * Address:	801D247C
 * Size:	000020
 */
void TAIdororoStrategy::draw(Teki& teki, Graphics& gfx)
{
	YaiStrategy::draw(teki, gfx);
}

/*
 * --INFO--
 * Address:	801D249C
 * Size:	0000B0
 */
void TAIdororoStrategy::createEffect(Teki& teki, int effType)
{
	TekiStrategy::createEffect(teki, effType);
	switch (effType) {
	case 0:
		createCloudOfDust(teki, mLeftHand);
		break;
	case 1:
		createCloudOfDust(teki, mRightHand);
		break;
	case 2:
		createCloudOfDust(teki, mLeftHand);
		createCloudOfDust(teki, mRightHand);
		break;
	}
}

/*
 * --INFO--
 * Address:	801D254C
 * Size:	000148
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

	rumbleMgr->start(10, 0, part->mCentre);
}

/*
 * --INFO--
 * Address:	801D2694
 * Size:	00008C
 */
void TAIdororoStrategy::start(Teki& teki)
{
	YaiStrategy::start(teki);
	mLeftHand  = getCollPartPtr(teki, 'lhnd');
	mRightHand = getCollPartPtr(teki, 'rhnd');

	if (!mLeftHand || !mRightHand) {
		PRINT("ERROR! No hand collPart.L:%08x R:&08x\n", mLeftHand);
		ERROR("ERROR! No hand collPart.L:%08x R:&08x\n", mLeftHand);
	}
}

/*
 * --INFO--
 * Address:	801D2720
 * Size:	0006FC
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
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/dororo/motion/waitact2.dca");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(7);
	addKeyFrame(27);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/dororo/motion/move1.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
	addKeyFrame(10);
	addKeyFrame(40);
	addInfoKey(1, 0);
	addInfoKey(2, 1);

	addAnimation("tekis/dororo/motion/move2.dck");
	setAnimFlags(ANIMFLAG_Unk2 | ANIMFLAG_Unk3);
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
