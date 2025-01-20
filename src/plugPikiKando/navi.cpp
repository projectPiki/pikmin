#include "AIConstant.h"
#include "BombItem.h"
#include "CPlate.h"
#include "DebugLog.h"
#include "EffectMgr.h"
#include "FlowController.h"
#include "GameCoreSection.h"
#include "gameflow.h"
#include "GlobalShape.h"
#include "GoalItem.h"
#include "Graphics.h"
#include "Interactions.h"
#include "Interface.h"
#include "ItemMgr.h"
#include "jaudio/PikiPlayer.h"
#include "KIO.h"
#include "Kontroller.h"
#include "MapCode.h"
#include "MemStat.h"
#include "MoviePlayer.h"
#include "Navi.h"
#include "NaviMgr.h"
#include "NaviState.h"
#include "Pcam/Camera.h"
#include "Pcam/CameraManager.h"
#include "Pellet.h"
#include "Piki.h"
#include "PikiAI.h"
#include "PikiHeadItem.h"
#include "PikiMgr.h"
#include "PikiState.h"
#include "PlayerState.h"
#include "RumbleMgr.h"
#include "Shape.h"
#include "SoundMgr.h"
#include "StateMachine.h"
#include "sysNew.h"
#include "teki.h"
#include "UfoItem.h"
#include "UtEffect.h"
#include "WorkObject.h"
#include "zen/Math.h"

bool DelayPikiBirth = true;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("navi");

/*
 * --INFO--
 * Address:	800F82E8
 * Size:	00009C
 */
void Navi::viewDraw(Graphics& gfx, Matrix4f& mtx)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mNaviAnimMgr.updateContext();
	mNaviShapeObject->mShape->updateAnim(gfx, mtx, nullptr);
	demoDraw(gfx, &mtx);
}

/*
 * --INFO--
 * Address:	800F8384
 * Size:	00005C
 */
void Navi::viewStartTrembleMotion(f32)
{
	mNaviAnimMgr.startMotion(PaniMotionInfo(PIKIANIM_OCarry), PaniMotionInfo(PIKIANIM_OCarry));
}

/*
 * --INFO--
 * Address:	800F83E0
 * Size:	000028
 */
void Navi::viewKill()
{
	mPosition = mPellet->mPosition;
	mPellet   = nullptr;
}

/*
 * --INFO--
 * Address:	800F8408
 * Size:	000008
 */
f32 Navi::viewGetBottomRadius()
{
	return 7.5f;
}

/*
 * --INFO--
 * Address:	800F8410
 * Size:	000008
 */
f32 Navi::viewGetHeight()
{
	return 10.0f;
}

/*
 * --INFO--
 * Address:	800F8418
 * Size:	000028
 */
bool Navi::isNuking()
{
	return mStateMachine->getCurrID(this) == NAVISTATE_Nuku;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void Navi::startMovie(bool doStopEffects)
{
	int state = mStateMachine->getCurrID(this);
	if (doStopEffects) {
		mNaviLightEfx->stop();
		mNaviLightGlowEfx->stop();
	}

	if (state != NAVISTATE_DemoInf && state != NAVISTATE_Starting) {
		PRINT("************ NAVI => DEMO_WAIT STATE \n");
		mStateMachine->transit(this, NAVISTATE_DemoWait);
	}
}

/*
 * --INFO--
 * Address:	800F84F8
 * Size:	000038
 */
void Navi::startMovieInf()
{
	PRINT("************ NAVI => DEMO_INF STATE \n");
	mStateMachine->transit(this, NAVISTATE_DemoInf);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
bool Navi::movieMode()
{
	return (gameflow._1D8 & 0x40) != 0;
}

/*
 * --INFO--
 * Address:	800F8530
 * Size:	000014
 */
void Navi::incPlatePiki()
{
	mPlateMgr->_78++;
}

/*
 * --INFO--
 * Address:	800F8544
 * Size:	000014
 */
void Navi::decPlatePiki()
{
	mPlateMgr->_78--;
}

/*
 * --INFO--
 * Address:	800F8558
 * Size:	00000C
 */
int Navi::getPlatePikis()
{
	return mPlateMgr->_78;
}

/*
 * --INFO--
 * Address:	800F8564
 * Size:	00000C
 */
void Navi::startDayEnd()
{
	mIsDayEnd = TRUE;
}

/*
 * --INFO--
 * Address:	800F8570
 * Size:	000410
 * @note: 	100A1AD0 in plugPiki.dll
 */
void Navi::updateDayEnd(Vector3f& pos)
{
	if (mIsDayEnd) {
		mIsDayEnd = 0;

		mPosition       = pos;
		mDayEndPosition = pos;
		mPlateMgr->update();
		makeCStick(false);

		PRINT("********* UPDATE DAY END ** 1ST FRAME\n");
		PRINT("******** FORMATION =====================\n");

		Iterator iter(pikiMgr);
		int pikiCount = 0;
		CI_LOOP(iter)
		{
			Piki* piki = static_cast<Piki*>(*iter);
			piki->mFSM->transit(piki, PIKISTATE_Normal);

			if (piki->mMode != PikiMode::EnterMode) {
				piki->changeMode(PikiMode::FormationMode, piki->mNavi);
				piki->forceFinishLook();
				piki->startLook(&piki->mNavi->mPosition);
				pikiCount++;

				if (piki->mMode != PikiMode::FormationMode) {
					ERROR("nandeyanen!");
				}

				int slotID = ((ActCrowd*)piki->mActiveAction->getCurrAction())->mCPlateSlotID;
				if (slotID == -1) {
					ERROR("slotID = -1 desse\n");
				}

				// Issues here
				Vector3f slotPos  = piki->mNavi->mPlateMgr->mSlotList[slotID]._0C + piki->mNavi->mPlateMgr->_94;
				piki->mPosition   = slotPos;
				piki->mPosition.y = mapMgr->getMinY(piki->mPosition.x, piki->mPosition.z, true);
			}
		}

		PRINT("(( UPDATE DAY END)) %d pikis : formation\n", pikiCount);
		PRINT("** END IF\n");
	}

	mPlateMgr->update();
	mKontroller->mSubStickY = 0;
	mKontroller->mSubStickX = 0;

	makeCStick(false);

	mDayEndPosition = mPosition;
	mPosition       = pos;

	mVelocity  = pos - mDayEndPosition;
	f32 length = mVelocity.length();
	mVelocity.multiply(1.0f / gsys->getFrameTime());
}

/*
 * --INFO--
 * Address:	800F8980
 * Size:	000228
 */
void Navi::enterAllPikis()
{
	Piki* pikiList[200];
	GoalItem* onyons[PikiColorCount];
	int i;
	for (i = 0; i < PikiColorCount; i++) {
		onyons[i] = itemMgr->getContainer(i);
	}

	for (i = 0; i < PikiColorCount; i++) {
		if (!onyons[i]) {
			char goalBuf[256];
			sprintf(goalBuf, "no goal (%d)", i);
			PRINT("no goal %d\n", i);
		}
	}

	int pikiCount = 0;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		if (piki->isAlive() && piki->mMode == PikiMode::FormationMode) {
			pikiList[pikiCount++] = piki;
		}
	}

	PRINT("#### enter pikis  : = %d \n", pikiCount);

	for (i = 0; i < pikiCount; i++) {
		if (pikiList[i]->mColor >= PikiColorCount) {
			PRINT("COLOR ID = %d\n", pikiList[i]->mColor);
			char colorBuf[256];
			sprintf(colorBuf, "COLOR %d !!", pikiList[i]->mColor);
			ERROR(colorBuf);
		}

		mGoalItem = onyons[pikiList[i]->mColor];
		if (mGoalItem) {
			if (pikiList[i]->getState() != PIKISTATE_Nukare) {
				pikiList[i]->changeMode(PikiMode::EnterMode, nullptr);
			}
		} else {
			PRINT("navi accesscontainer = 0\n");
		}
	}
}

/*
 * --INFO--
 * Address:	800F8BA8
 * Size:	000C20
 */
NaviProp::NaviProp()
{
	mCreatureProps.mFriction(1.0f);
	mCreatureProps.mFaceDirAdjust(0.5f);
	mCreatureProps.mAcceleration(0.2f);
}

/*
 * --INFO--
 * Address:	800F97C8
 * Size:	000020
 */
bool Navi::isBuried()
{
	if (getCurrState()->getID() == NAVISTATE_Bury) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800F97E8
 * Size:	000020
 */
bool Navi::isVisible()
{
	if (getCurrState()->getID() == NAVISTATE_Dead) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	800F9808
 * Size:	000020
 */
bool Navi::isRopable()
{
	if (getCurrState()->getID() == NAVISTATE_RopeExit) {
		return false;
	}
	return true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
bool Navi::startDamage()
{
	int stateID      = mStateMachine->getCurrID(this);
	NaviState* state = mStateMachine->getNaviState(this);
	if (state->invincible(this)) {
		return false;
	}

	startDamageEffect();
	setStateDamaged();
	mStateMachine->resume(this);
	return true;
}

/*
 * --INFO--
 * Address:	800F9834
 * Size:	000234
 */
void Navi::startDamageEffect()
{
	CollPart* part = mCollInfo->getSphere('cent');
	if (!part) {
		return;
	}

	if (mHealth <= 1.0f) {
		gameflow.mGameInterface->message(14, 0);
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);

	} else if (!gameflow.mMoviePlayer->mIsActive && mHealth <= 0.25f * NAVI_PROP.mHealth()
	           && !playerState->mDemoFlags.isFlag(DEMOFLAG_Unk29)) {
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Unk29);
		gameflow.mGameInterface->message(0, 24);
	}

	zen::particleGenerator* ptclGenA = effectMgr->create(EffectMgr::EFF_Navi_DamageA, part->mCentre, nullptr, nullptr);
	zen::particleGenerator* ptclGenB = effectMgr->create(EffectMgr::EFF_Navi_DamageB, part->mCentre, nullptr, nullptr);
	if (ptclGenB) {
		ptclGenB->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
	}

	zen::particleGenerator* ptclGenC = effectMgr->create(EffectMgr::EFF_Navi_DamageC, part->mCentre, nullptr, nullptr);
	if (ptclGenC) {
		ptclGenC->setEmitPosPtr(&part->mCentre);
	}

	mDamageEfxA = ptclGenA;
	mDamageEfxB = ptclGenB;
	mDamageEfxC = ptclGenC;

	int vibTypes[2] = { 0, 1 };
	f32 randIdx     = System::getRand(1.0f);
	int vib         = vibTypes[int(2.0f * randIdx * 0.9999999f)];
	cameraMgr->startVibrationEvent(vib, mPosition);

	SeSystem::playPlayerSe(SE_DAMAGED);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x6365
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x6E74
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x44(r1)
	  stw       r28, 0x40(r1)
	  lwz       r3, 0x220(r3)
	  bl        -0x70150
	  mr.       r31, r3
	  beq-      .loc_0x214
	  lfs       f2, 0x58(r30)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x80
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1E8(r3)
	  li        r4, 0xE
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  b         .loc_0xF8

	.loc_0x80:
	  lis       r3, 0x803A
	  subi      r28, r3, 0x2848
	  lwz       r3, 0x1DC(r28)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xF8
	  lwz       r3, 0x224(r30)
	  lfs       f1, -0x6380(r2)
	  lfs       f0, 0x3C8(r3)
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xF8
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1D
	  addi      r3, r3, 0x54
	  bl        -0x77430
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF8
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x1D
	  addi      r3, r3, 0x54
	  bl        -0x771BC
	  lwz       r3, 0x1E8(r28)
	  li        r4, 0
	  li        r5, 0x18
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xF8:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x4
	  li        r6, 0
	  li        r7, 0
	  bl        0xA31F8
	  mr        r28, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x5
	  li        r6, 0
	  li        r7, 0
	  bl        0xA31DC
	  mr.       r29, r3
	  beq-      .loc_0x164
	  lfs       f0, -0x2C74(r13)
	  lfs       f1, -0x2C70(r13)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x2C6C(r13)
	  stfs      f1, 0x20(r1)
	  stfs      f0, 0x24(r1)
	  lwz       r3, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r3, 0x1DC(r29)
	  stw       r0, 0x1E0(r29)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x1E4(r29)

	.loc_0x164:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x6
	  li        r6, 0
	  li        r7, 0
	  bl        0xA318C
	  cmplwi    r3, 0
	  beq-      .loc_0x18C
	  addi      r0, r31, 0x4
	  stw       r0, 0x18(r3)

	.loc_0x18C:
	  stw       r28, 0x2D4(r30)
	  stw       r29, 0x2D8(r30)
	  stw       r3, 0x2DC(r30)
	  lwz       r3, -0x62FC(r2)
	  lwz       r0, -0x62F8(r2)
	  stw       r3, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  bl        0x11E694
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x62E8(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x62F4(r2)
	  addi      r4, r1, 0x28
	  stw       r0, 0x38(r1)
	  lfs       f2, -0x6388(r2)
	  addi      r5, r30, 0x94
	  lfd       f1, 0x38(r1)
	  lfs       f0, -0x6314(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x62F0(r2)
	  lwz       r3, 0x30D8(r13)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  bl        0x2A59C
	  li        r3, 0x13D
	  bl        -0x54668

	.loc_0x214:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  lwz       r28, 0x40(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F9A68
 * Size:	000120
 */
void Navi::finishDamage()
{
	resetStateDamaged();
	mStateMachine->restart(this);

	if (mHealth <= 1.0f) {
		mStateMachine->transit(this, NAVISTATE_Dead);
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
	} else {
		if (!gameflow.mMoviePlayer->mIsActive && mHealth <= 0.25f * NAVI_PROP.mHealth()
		    && !playerState->mDemoFlags.isFlag(DEMOFLAG_Unk29)) {
			playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Unk29);
			gameflow.mGameInterface->message(0, 24);
		}
	}

	mDamageEfxA = mDamageEfxB = mDamageEfxC = nullptr;
}

/*
 * --INFO--
 * Address:	800F9B8C
 * Size:	000668
 */
Navi::Navi(CreatureProp* props, int naviID)
    : Creature(props)
{
	_700 = 4;
	memStat->start("naviCaster");
	mShadowCaster.initCore("");
	mNaviDrawer                     = new NaviDrawer(this);
	mShadowCaster.mLightCamera.mFov = 20.0f;
	memStat->end("naviCaster");

	memStat->start("naviEff");
	mBurnEffect       = new BurnEffect(&mVelocity);
	mRippleEffect     = new RippleEffect();
	mNaviLightEfx     = new PermanentEffect();
	mNaviLightGlowEfx = new PermanentEffect();
	_77C              = new PermanentEffect();
	_780              = new PermanentEffect();
	mSlimeEffect      = new SlimeEffect();
	memStat->end("naviEff");

	mPlateMgr        = nullptr;
	_AD8             = 0.0f;
	mNaviID          = naviID;
	_ACC             = 0;
	_AD0             = 0;
	_738             = 0.0f;
	_718             = 0;
	_720             = 0;
	_71C             = 0;
	mCurrState       = nullptr;
	mNaviShapeObject = naviMgr->mNaviShapeObject[mNaviID];
	mCollInfo        = new CollInfo(5);
	mCollInfo->initInfo(mNaviShapeObject->mShape, nullptr, nullptr);
	mNaviAnimMgr.init(mNaviShapeObject->mAnimMgr, &mNaviShapeObject->mAnimatorB, &mNaviShapeObject->mAnimatorA, naviMgr->mMotionTable);
	_ABC    = 0;
	_AB8    = 0.0f;
	_AC4    = 0.0f;
	mHealth = NAVI_PROP.mHealth();

	mDayEndPosition.set(0.0f, 0.0f, 0.0f);
	_814 = 0.0f;
	_818 = 1.0f;
	_810 = 0;
	_80C = 0;
	startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));

	f32 s = 1.0f;
	mScale.set(s, s, s);
	mRotation.set(0.0f, 0.0f, 0.0f);
	mPosition.set(0.0f, 0.0f, 0.0f);
	mVelocity.set(0.0f, 0.0f, 0.0f);
	mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	_268        = 0.0f;
	mKontroller = new Kontroller(naviID + 1);
	_26C        = 20.0f;

	memStat->start("naviStateM");
	mStateMachine = new NaviStateMachine();
	mStateMachine->init(this);
	memStat->end("naviStateM");

	_828 = 0;
	_724 = 0;
	_800 = 0.0f;
	_7FC = 0;
	_928 = 0;
	resetCreatureFlag(CF_Unk1 | CF_Unk10);
	mObjType = OBJTYPE_Navi;
	mSearchBuffer.init(mNaviSearchData, 6);

	_72C = 0;
	_730 = 0;
	_734 = 0;
	_7D8.clear();
	_770 = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void Navi::Locus::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800FA1F4
 * Size:	000054
 */
void Navi::startKontroller()
{
	if (KIO::kontMode == KONT_Save) {
		mKontroller->save(controllerBuffer, 900);
		return;
	}

	if (KIO::kontMode == KONT_Load) {
		mKontroller->load(controllerBuffer, 900);
	}
}

/*
 * --INFO--
 * Address:	800FA248
 * Size:	000040
 */
void Navi::rideUfo()
{
	_2E0 = 1;
	mNaviLightEfx->kill();
	mNaviLightGlowEfx->kill();
}

/*
 * --INFO--
 * Address:	800FA288
 * Size:	000408
 */
void Navi::reset()
{
	mDamageEfxA = mDamageEfxB = mDamageEfxC = nullptr;
	_304                                    = 0;
	_2F4                                    = 0.0f;
	_2F8                                    = 0.0f;
	setUnk22();
	_830 = 0;
	_2E0 = 0;
	setPellet(false);
	mLookAtPosPtr       = nullptr;
	mIsPlucking         = false;
	mIsFastPluckEnabled = false;
	_2FC                = nullptr;
	_300                = 0.0f;
	mIsInWater          = false;
	_30C                = 0;
	_310                = 0;
	_6FC                = 1;
	_700                = 5;
	_79C.set(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < 32; i++) {
		_938[i].set(0.0f, 0.0f, 0.0f);
	}

	GlobalShape::cursorShape->makeInstance(mNaviDynMats, 0);

	_70C = 0;
	mStateMachine->transit(this, NAVISTATE_Walk);
	mPlateMgr = new CPlate(mapMgr);

	_719 = 0;
	mPlateMgr->init(mPosition);
	_7B4         = 0;
	mWallCollObj = nullptr;
	mAiTickTimer = 0.0f;
	_784.set(0.0f, 0.0f, 0.0f);
	_724 = 0;

	f32 dist = (NAVI_PROP._38C() + NAVI_PROP._39C()) * 0.5f;
	mCursorPosition.set(dist * sinf(mDirection), 0.0f, dist * cosf(mDirection));
	mCursorNaviDist       = mCursorPosition.length();
	mCursorTargetPosition = mCursorPosition;
	_6F0.set(0.0f, 0.0f, 0.0f);
	_7DC           = mDirection;
	mNextThrowPiki = nullptr;
	mNaviLightEfx->changeEffect(EffectMgr::EFF_Navi_Light);
	mNaviLightGlowEfx->changeEffect(EffectMgr::EFF_Navi_LightGlow);
}

/*
 * --INFO--
 * Address:	800FA690
 * Size:	00000C
 */
f32 Navi::getSize()
{
	return NAVI_PROP._1FC();
}

/*
 * --INFO--
 * Address:	800FA69C
 * Size:	000048
 */
f32 Navi::getiMass()
{
	int stateID = mStateMachine->getCurrID(this);
	if (stateID == NAVISTATE_Nuku || stateID == NAVISTATE_NukuAdjust) {
		return 0.0f;
	}

	if (stateID == NAVISTATE_Dead) {
		return 1.0f;
	}

	return NAVI_PROP._21C();
}

/*
 * --INFO--
 * Address:	800FA6E4
 * Size:	00018C
 */
void Navi::findNextThrowPiki()
{
	mNextThrowPiki = nullptr;
	Iterator iter(mPlateMgr);
	f32 minDist = 200.0f;
	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		if (roughCull(this, piki, minDist)) {
			continue;
		}

		f32 dist = qdist2(piki, this);
		if (dist < minDist && piki->getState() == PIKISTATE_Normal && piki->isThrowable()) {
			mNextThrowPiki = piki;
			minDist        = dist;
		}
	}
}

/*
 * --INFO--
 * Address:	800FA870
 * Size:	000038
 */
void Navi::startMotion(PaniMotionInfo& motion1, PaniMotionInfo& motion2)
{
	mNaviAnimMgr.startMotion(motion1, motion2);
	mPreBlendLowerMotionID = -1;
}

/*
 * --INFO--
 * Address:	800FA8A8
 * Size:	000050
 */
void Navi::enableMotionBlend()
{
	mPreBlendLowerMotionID = mNaviAnimMgr.getLowerAnimator().getCurrentMotionIndex();
	mNaviAnimMgr.getLowerAnimator().startMotion(PaniMotionInfo(PIKIANIM_Nigeru));
	mNaviAnimMgr.getLowerAnimator().mAnimationCounter = 10.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
bool Navi::doMotionBlend()
{
	return mPreBlendLowerMotionID != -1;
}

/*
 * --INFO--
 * Address:	800FA8F8
 * Size:	0003BC
 */
void Navi::updateWalkAnimation()
{
	mCollisionRadius  = NAVI_PROP._20C();
	Vector3f sep      = mPosition - _79C;
	sep.y             = 0.0f;
	f32 speed         = sep.length() / gsys->getFrameTime();
	int lowerMotionID = mNaviAnimMgr.getLowerAnimator().getCurrentMotionIndex();
	if (_30) {
		speed = 0.0f;
	}

	if (mRope) {
		return;
	}

	if (lowerMotionID != PIKIANIM_Wait && lowerMotionID != PIKIANIM_Walk && lowerMotionID != PIKIANIM_Asibumi
	    && lowerMotionID != PIKIANIM_Run && lowerMotionID != PIKIANIM_Nigeru) {
		if (!mRope) {
			mMotionSpeed = 30.0f;
		}
		return;
	}

	f32 angle      = zen::Abs(mDirection - _7DC);
	Navi* listener = nullptr;
	int newMotionID;
	if (speed < NAVI_PROP._23C()) {
		newMotionID = PIKIANIM_Wait;
		if (angle > 0.01f) {
			newMotionID = PIKIANIM_Asibumi;
		}
		speed = 30.0f;

	} else if (speed < NAVI_PROP._24C()) {
		newMotionID = PIKIANIM_Asibumi;
		speed       = 30.0f;

	} else if (speed < NAVI_PROP._25C()) {
		newMotionID = PIKIANIM_Walk;
		listener    = this;
		f32 ratio   = (speed - NAVI_PROP._24C()) / (NAVI_PROP._25C() - NAVI_PROP._24C());
		speed       = NAVI_PROP._27C() + (NAVI_PROP._28C() - NAVI_PROP._27C()) * ratio;

	} else if (speed < NAVI_PROP._26C()) {
		newMotionID = PIKIANIM_Run;
		listener    = this;
		f32 ratio   = (speed - NAVI_PROP._25C()) / (NAVI_PROP._26C() - NAVI_PROP._25C());
		speed       = NAVI_PROP._29C() + (NAVI_PROP._2AC() - NAVI_PROP._29C()) * ratio;

	} else {
		speed       = NAVI_PROP._2BC();
		listener    = this;
		newMotionID = PIKIANIM_Nigeru;
	}

	if (newMotionID != lowerMotionID) {
		if (lowerMotionID == PIKIANIM_Wait && newMotionID != PIKIANIM_Asibumi) {
			_700 = 4;
		}

		if (lowerMotionID != PIKIANIM_Asibumi && newMotionID == PIKIANIM_Wait) {
			_700 = 4;
		}

		if (newMotionID != _6FC) {
			_700 = 0;
			_6FC = newMotionID;
		} else {
			_700++;
		}

		if (_700 < 4) {
			return;
		}
	}

	if (lowerMotionID != newMotionID) {
		if (lowerMotionID == PIKIANIM_Wait || lowerMotionID == PIKIANIM_Asibumi || newMotionID == PIKIANIM_Wait
		    || newMotionID == PIKIANIM_Asibumi) {
			if (!doMotionBlend()) {
				startMotion(PaniMotionInfo(newMotionID), PaniMotionInfo(newMotionID, listener));
			} else {
				mNaviAnimMgr.getLowerAnimator().startMotion(PaniMotionInfo(newMotionID, listener));
			}
		} else if (!doMotionBlend()) {

			swapMotion(PaniMotionInfo(newMotionID), PaniMotionInfo(newMotionID, listener));
		} else {
			f32 lowerCounter = mNaviAnimMgr.getLowerAnimator().mAnimationCounter;
			mNaviAnimMgr.getLowerAnimator().startMotion(PaniMotionInfo(newMotionID, listener));
			mNaviAnimMgr.getLowerAnimator().mAnimationCounter = lowerCounter;
		}
	}

	mMotionSpeed = speed;
}

/*
 * --INFO--
 * Address:	800FACB4
 * Size:	000034
 */
void Navi::postUpdate(int p1, f32 p2)
{
	if (!movieMode()) {
		Creature::postUpdate(p1, p2);
	}
}

/*
 * --INFO--
 * Address:	800FACE8
 * Size:	000500
 */
void Navi::update()
{
	if (!mFloorTri) {
		f32 maxY = mapMgr->getMaxY(mPosition.x, mPosition.z, true);
		if (maxY > mPosition.y) {
			PRINT("navi(%.1f %.1f %.1f) : map(%.1f %.1f %.1f)\n", mPosition.x, mPosition.y, mPosition.z, mPosition.x, maxY, mPosition.z);
			PRINT("mapY %.1f srt.t.y %.1f\n", maxY, mPosition.y); // (we know they had mScale/mRotation/mPosition as an SRT already)
			PRINT("navi almost fall !\n");
			mPosition.y = maxY;
		}
	}

	_2FC = nullptr;
	if (movieMode()) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	if (mIsPlucking) {
		int state = mStateMachine->getCurrID(this);
		if (state != NAVISTATE_Nuku && state != NAVISTATE_NukuAdjust) {
			mNoPluckTimer++;
			if (mNoPluckTimer > NAVI_PROP.mPostPluckZoomOutTime()) {
				mIsPlucking         = false;
				mIsFastPluckEnabled = false;
				PRINT("< camera FINISH MOTION");
				cameraMgr->mCamera->finishMotion();
				cameraMgr->mCamera->_30 = 1;
				mNoPluckTimer           = 0;
			}
		}
	}

	int attr = ATTR_NULL;
	if (mFloorTri) {
		attr = MapCode::getAttribute(mFloorTri);
	}

	if (attr == ATTR_Water) {
		if (!mIsInWater) {
			// we just moved into water, create ripple effects
			EffectParm rippleParm(&mPosition);
			EffectParm castParm(mPosition);
			mRippleEffect->emit(rippleParm);
			UtEffectMgr::cast(17, castParm);
			SeSystem::playPlayerSe(SE_PIKI_WATERDROP);
		}
		mIsInWater = true;
	} else {
		if (mIsInWater) {
			mIsInWater = false;
			mRippleEffect->kill();
		}
		// make DOUBLY sure this is set false.
		mIsInWater = false;
	}

	mNaviDynMats.animate(nullptr);

	Vector3f cursorMoveDir = mCursorTargetPosition - mCursorPosition;
	f32 cursorMoveDist     = cursorMoveDir.normalise();
	if (cursorMoveDist > 0.0f) {
		f32 moveDist = gsys->getFrameTime() * NAVI_PROP._3AC();
		if (moveDist > cursorMoveDist) {
			moveDist = cursorMoveDist;
		}

		mCursorPosition = mCursorPosition + moveDist * cursorMoveDir;
	}

	mPlateMgr->update();
	updateWalkAnimation();
	_79C = mPosition;
	mNaviAnimMgr.updateAnimation(mMotionSpeed);

	u32 badCompiler;
	/*
	// game freeze keybind?
	// this has to have been commented out from release or it inflates the stack a LOT
	if (mKontroller->keyClick(KBBTN_R) && mKontroller->keyDown(KBBTN_B) && mKontroller->keyDown(KBBTN_A)) {
	    // flip a debug flag
	}

	// if some other debug flag is true and debug flag is false, flip them both

	if (mKontroller->keyClick(KBBTN_Z)) { // && debug flag
	    // other debug flag = true
	    // debug flag = false
	    int id = getCurrState()->getID();
	    PRINT("---- game frozen : naviState %d\n", id);
	}
	*/

	mKontroller->update();
	_7DC = mDirection;
	Creature::update();

	mapMgr->updatePos(mPosition.x, mPosition.z);

	Vector3f dayEndSep = mDayEndPosition - mPosition;
	if (dayEndSep.length() > 35.0f && mFloorTri) {
		Vector3f parmPos(mPosition.x, mPosition.y + 1.0f, mPosition.z);

		Vector3f parmVel(0.01667f * mVelocity.x, 2.0f, 0.01667f * mVelocity.z);
		int effAttr = MapCode::getAttribute(mFloorTri);
		if (effAttr >= ATTR_Unk0 && effAttr <= ATTR_Unk3) {
			EffectParm parm(parmPos, parmVel);
			UtEffectMgr::cast(effAttr + 3, parm);
			mDayEndPosition = mPosition;
		}
	}
}

/*
 * --INFO--
 * Address:	800FB1E8
 * Size:	0001F4
 */
void Navi::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	// sure kando.
	int lowerMotionID = mNaviAnimMgr.getLowerAnimator().getCurrentMotionIndex();
	int upperMotionID = mNaviAnimMgr.getUpperAnimator().getCurrentMotionIndex();
	if (event.mEventType == KEY_PlaySound) {
		int attr = ATTR_Unk0;
		if (mFloorTri) {
			attr = MapCode::getAttribute(mFloorTri);
		}
		u16 soundType;
		switch (attr) {
		case ATTR_Unk0:
			soundType = 1;
			break;
		case ATTR_Unk1:
			soundType = 3;
			break;
		case ATTR_Unk2:
			soundType = 0;
			break;
		case ATTR_Unk3:
			soundType = 2;
			break;
		case ATTR_Water:
			soundType = 4;
			break;
		case ATTR_Unk4:
			soundType = 5;
			break;
		default:
			soundType = 1;
			break;
		}

		Jac_Orima_Walk(soundType, 0);
	}

	MsgAnim msg(&event);
	sendMsg(&msg);

	if (isDamaged() && event.mEventType == KEY_Finished) {
		PRINT("finish damage\n");
		finishDamage();
	}
}

/*
 * --INFO--
 * Address:	800FB3DC
 * Size:	0007C4
 */
void Navi::callPikis(f32 radius)
{
	Vector3f unused = _6F0 - mPosition;
	u32 badCompiler[4];

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Piki* piki = static_cast<Piki*>(*iterPiki);
		if (!piki->isAlive()) {
			continue;
		}

		Vector3f sep = piki->mPosition - _6F0;
		f32 dist     = speedy_sqrtf(sep.x * sep.x + sep.z * sep.z);
		if (dist >= radius) {
			continue;
		}

		int state = piki->getState();
		if (state == PIKISTATE_Drown) {
			static_cast<PikiDrownState*>(piki->getCurrState())->_28 = true;
			PRINT("call drown piki\n");
		} else if (state == PIKISTATE_Flick) {
			static_cast<PikiFlickState*>(piki->getCurrState())->_14 = 0.0f;
		} else if (state == PIKISTATE_Flown) {
			static_cast<PikiFlownState*>(piki->getCurrState())->_10 = 0.0f;
		}

		if ((piki->mNavi == this || !piki->mNavi) && !piki->isKinoko() && piki->isAlive() && !piki->isBuried()
		    && (piki->mMode != PikiMode::FormationMode || piki->getState() == PIKISTATE_Emotion) && piki->mIsCallable
		    && state != PIKISTATE_Nukare && state != PIKISTATE_Swallowed && state != PIKISTATE_Drown && state != PIKISTATE_Absorb
		    && state != PIKISTATE_LookAt && state != PIKISTATE_Pressed && dist < radius) {
			if (!piki->isDamaged() && state != PIKISTATE_Flick && state != PIKISTATE_GrowUp) {
				if (piki->isFired() && piki->mColor != Red) {
					piki->endFire();
				}

				piki->mNavi = this;
				if (state == PIKISTATE_Emotion) {
					static_cast<PikiEmotionState*>(piki->getCurrState())->_1D = 0;
				}

				if (piki->mMode == PikiMode::PutbombMode && piki->isHolding()) {
					InteractRelease release(piki, 1.0f);
					Creature* held = piki->getHoldCreature();
					held->stimulate(release);
					MsgUser msg(0);
					BombItem* bomb = static_cast<BombItem*>(held);
					bomb->mStateMachine->procMsg(bomb, &msg);
				}

				piki->mFSM->transit(piki, PIKISTATE_LookAt);
			} else {
				piki->mNavi             = this;
				piki->mIsWhistlePending = true;
			}

		} else if (dist < radius && piki->mMode != PikiMode::FormationMode) {
			piki->getState();
		}

		if (AIConstant::_instance->mConstants.mDoPluckWithCursor() && (mNaviID == piki->mPlayerId || piki->mPlayerId == -1)
		    && piki->isBuried() && piki->getState() == PIKISTATE_Bury && dist < radius) {
			piki->mNavi = this;
			piki->mFSM->transit(piki, PIKISTATE_AutoNuki);
			ERROR("cursor nuki!\n");
		}
	}

	Iterator iterSprout(itemMgr->getPikiHeadMgr());
	CI_LOOP(iterSprout)
	{
		Creature* maybeSprout = *iterSprout;
		if (maybeSprout->mObjType == OBJTYPE_Pikihead) {
			PikiHeadItem* sprout = static_cast<PikiHeadItem*>(maybeSprout);
			Vector3f sproutSep   = maybeSprout->mPosition - _6F0;
			f32 sproutDist       = speedy_sqrtf(sproutSep.x * sproutSep.x + sproutSep.z * sproutSep.z);
			if (!AIConstant::_instance->mConstants.mDoPluckWithCursor()) {
				continue;
			}

			if (sprout->canPullout() && sproutDist < radius) {
				ERROR("cursor nuki!\n");
				PikiMgr::meBirthMode = 1;
				Piki* piki           = static_cast<Piki*>(pikiMgr->birth());
				PikiMgr::meBirthMode = 0;

				if (piki) {
					piki->init(this);
					piki->initColor(sprout->mSeedColor);
					piki->setFlower(sprout->mFlowerStage);
					piki->resetPosition(sprout->mPosition);
					piki->mFSM->transit(piki, PIKISTATE_AutoNuki);
					sprout->kill(false);
				}
			}
		}
	}

	if (!tekiMgr) {
		return;
	}

	Iterator iterTeki(tekiMgr);
	CI_LOOP(iterTeki)
	{
		Creature* teki   = *iterTeki;
		Vector3f tekiSep = teki->mPosition - _6F0;
		f32 tekiDist     = speedy_sqrtf(tekiSep.x * tekiSep.x + tekiSep.z * tekiSep.z);
		if (teki->isAlive() && teki->isVisible() && tekiDist < radius) {
			InteractFlute flute(this);
			teki->stimulate(flute);
		}
	}
}

/*
 * --INFO--
 * Address:	800FBBA0
 * Size:	00037C
 */
void Navi::callDebugs(f32 radius)
{
	Iterator iterPiki(pikiMgr);
	int pikiCount = 0;
	CI_LOOP(iterPiki)
	{
		Piki* piki       = static_cast<Piki*>(*iterPiki);
		Vector3f pikiSep = piki->mPosition - _6F0;
		f32 tekiDist     = pikiSep.length();
		if (tekiDist < radius) {
			if (pikiCount == 0) {
				PRINT("--------------- PIKI INFO ------------------\n");
			}
			Piki::directDumpMode = true;
			piki->dump();
			Piki::directDumpMode = false;
			pikiCount++;
		}
	}

	int tekiCount = 0;
	Iterator iterTeki(tekiMgr);
	CI_LOOP(iterTeki)
	{
		Creature* teki   = *iterTeki;
		Vector3f tekiSep = teki->mPosition - _6F0;
		f32 tekiDist     = tekiSep.length();
		if (tekiDist < radius) {
			if (tekiCount == 0) {
				PRINT("--------------- TEKI INFO ------------------\n");
			}
			teki->dump();
			tekiCount++;
		}
	}
}

/*
 * --INFO--
 * Address:	800FBF1C
 * Size:	0007DC
 */
void Navi::releasePikis()
{
	Iterator iter(mPlateMgr);
	Piki* pikiList[200];
	int pikiCount = 0;
	CI_LOOP(iter)
	{
		Piki* piki = static_cast<Piki*>(*iter);
		int state  = piki->getState();
		if (piki->isAlive() && piki->mMode != PikiMode::FreeMode && state != PIKISTATE_GrowUp && state != PIKISTATE_Absorb
		    && state != PIKISTATE_Swallowed && state != PIKISTATE_LookAt && state != PIKISTATE_Dying && state != PIKISTATE_Dead
		    && state != PIKISTATE_Nukare && state != PIKISTATE_NukareWait && state != PIKISTATE_Pressed && state != PIKISTATE_Drown
		    && state != PIKISTATE_KinokoChange && state != PIKISTATE_Flick && !piki->isKinoko() && piki->isAIActive()) {
			pikiList[pikiCount++] = static_cast<Piki*>(*iter);
		}
	}

	if (!pikiCount) {
		// no pikis to dismiss
		return;
	}
	Vector3f colorCoMs[PikiColorCount + 1]; // each color + bomb-carriers
	int colorCounts[PikiColorCount + 1];    // each color + bomb-carriers
	f32 colorSizes[PikiColorCount + 1];
	int j, i;
	for (i = 0; i < PikiColorCount + 1; i++) {
		colorCoMs[i].set(0.0f, 0.0f, 0.0f);
		colorCounts[i] = 0;
	}

	for (i = 0; i < PikiColorCount + 1; i++) {
		for (j = 0; j < pikiCount; j++) {
			if (i == Blue || i == Red) {
				if (i == pikiList[j]->mColor) {
					colorCounts[i]++;
					colorCoMs[i].add(pikiList[j]->mPosition);
				}
			} else {
				if (pikiList[j]->mColor == Yellow) {
					if (pikiList[j]->hasBomb()) {
						colorCounts[3]++;
						colorCoMs[3].add(pikiList[j]->mPosition);
					} else {
						colorCounts[Yellow]++;
						colorCoMs[Yellow].add(pikiList[j]->mPosition);
					}
				}
			}
		}
	}

	for (i = 0; i < PikiColorCount + 1; i++) {
		if (colorCounts[i] > 0) {
			colorCoMs[i].multiply(1.0f / colorCounts[i]);
			colorSizes[i] = (2.5f * pikiList[0]->getSize()) * std::sqrtf(colorCounts[i]);
		}
	}

	for (int i = 0; i < PikiColorCount + 1; i++) {
		if (colorCounts[i] > 0) {
			Vector3f sepNaviGroup = colorCoMs[i] - mPosition;
			f32 dist              = sepNaviGroup.normalise() - colorSizes[i] - 15.0f;
			if (dist < 18.0f) {
				dist = 18.0f - dist;
				Vector3f offsetFromNavi;
				offsetFromNavi = dist * sepNaviGroup;
				colorCoMs[i].add(offsetFromNavi);
			}
		}

		for (int j = i + 1; j < PikiColorCount + 1; j++) {
			if (colorCounts[i] > 0 && colorCounts[j] > 0) {
				Vector3f colorColorSep = colorCoMs[i] - colorCoMs[j];
				f32 colorDist          = colorColorSep.normalise() - colorSizes[i] - colorSizes[j];
				if (colorDist < 18.0f) {
					colorDist = (18.0f - colorDist);
					Vector3f interColorOffset;
					interColorOffset = colorDist * colorColorSep;
					colorCoMs[i].add(interColorOffset);
					colorCoMs[j].sub(interColorOffset);
				}
			}
		}
	}

	for (i = 0; i < pikiCount; i++) {
		pikiList[i]->changeMode(PikiMode::FreeMode, this);
		int color = pikiList[i]->mColor;
		if (pikiList[i]->hasBomb()) {
			color = 3;
		}

		ActFree* action = static_cast<ActFree*>(pikiList[i]->mActiveAction->getCurrAction());
		action->initBoid(colorCoMs[color], colorSizes[color]);
		if (flowCont._230 == 1 && pikiList[i]->mPlayerId == -1) {
			pikiList[i]->mNavi = nullptr;
		}
	}

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	800FC6F8
 * Size:	0000C4
 */
void Navi::doAI()
{
	if (gameflow._1D8 & 0x40) {
		return;
	}

	mAiTickTimer -= gsys->getFrameTime();
	if (mAiTickTimer <= 0.0f) {
		if (_7B4 == 0) {
			offwallCallback(mWallCollObj);
			mWallCollObj = nullptr;
			mAiTickTimer = 0.0f;
		} else {
			mAiTickTimer = 0.1f;
		}
	}

	mStateMachine->exec(this);
	_7B4 = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void Navi::doAttack()
{
	Creature* target = _7D8.getPtr();
	InteractAttack attack(this, nullptr, 1.0f, false);
	target->stimulate(attack);
	_7D8.reset();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
bool Navi::insideOnyon()
{
	for (int i = 0; i < PikiColorCount; i++) {
		GoalItem* onyon = itemMgr->getContainer(i);
		if (onyon) {
			f32 xDiff = onyon->mPosition.x - mPosition.x;
			f32 zDiff = onyon->mPosition.z - mPosition.z;
			f32 sqrXZ = xDiff * xDiff + zDiff * zDiff;

			if (sqrXZ <= SQUARE(220.0f)) {
				return true;
			}
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	800FC7FC
 * Size:	000A40
 */
bool Navi::procActionButton()
{
	// can't fix this with stack alone - needs 0x8 more stack from inlines :(
	u32 badCompiler[4];

	// ACCESS UFO PART INFO - see if there's a ufo part for us to interact with
	if (getCurrState()->getID() == NAVISTATE_Walk) {
		Iterator iter(pelletMgr);
		CI_LOOP(iter)
		{
			Pellet* pellet = static_cast<Pellet*>(*iter);
			if (pellet->mConfig->mPelletType() == PELTYPE_UfoPart && pellet->onGround() && pellet->getState() == 0) {
				UfoItem* ship       = itemMgr->getUfo();
				Vector3f pelShipSep = pellet->mPosition - ship->getGoalPos();
				f32 distFromShip    = std::sqrtf(pelShipSep.x * pelShipSep.x + pelShipSep.z * pelShipSep.z);
				if (distFromShip < 30.0f && pellet->_570 != 0) {
					continue;
				}

				Vector3f pelNaviSep = pellet->mPosition - mPosition;
				f32 distFromNavi    = std::sqrtf(pelNaviSep.x * pelNaviSep.x + pelNaviSep.z * pelNaviSep.z) - pellet->getBottomRadius();
				if (distFromNavi <= 20.0f) {
					int idx = PelletMgr::getUfoIndexFromID(pellet->mConfig->_2C.mId);
					if (idx == -1) {
						ERROR("WHY !! THIS IS NOT UFO PARTS!!\n");
					}
					_304 = pellet;
					mStateMachine->transit(this, NAVISTATE_PartsAccess);
					return true;
				}
			}
		}
	}

	// ACCESS SHIP INFO - see if there's a ship for us to interact with
	if (!gameflow.mMoviePlayer->mIsActive && getCurrState()->getID() == NAVISTATE_Walk
	    && gameflow.mWorldClock.mTimeOfDay < (gameflow.mParameters->mEndHour() - 0.2f)) {
		PRINT("tod = %f : endhour = %f\n", gameflow.mWorldClock.mTimeOfDay, gameflow.mParameters->mEndHour());
		UfoItem* ship = itemMgr->getUfo();
		if (ship) {
			Vector3f naviShipSep = ship->mPosition - mPosition;
			f32 naviShipDist     = std::sqrtf(naviShipSep.x * naviShipSep.x + naviShipSep.z * naviShipSep.z);
			if (naviShipDist <= 50.0f) {
				mStateMachine->transit(this, NAVISTATE_UfoAccess);
				return true;
			}
		}
	}

	// PLUCK A SPROUT - see if there's a sprout near enough for us to pluck
	bool isInsideOnyon = insideOnyon();
	Iterator iter(itemMgr->getPikiHeadMgr());
	PikiHeadItem* closestSprout = nullptr;
	f32 minDist;
	if (isInsideOnyon) {
		minDist = NAVI_PROP._5C();
	} else {
		minDist = NAVI_PROP._7C();
	}
	if (mIsFastPluckEnabled) {
		minDist = NAVI_PROP._6C();
	}
	CI_LOOP(iter)
	{
		Creature* maybeSprout = *iter;
		if (maybeSprout->mObjType == OBJTYPE_Pikihead) {
			PikiHeadItem* sprout = static_cast<PikiHeadItem*>(maybeSprout);
			if (roughCull(this, sprout, minDist)) {
				continue;
			}

			Vector3f sproutNaviSep = sprout->mPosition - mPosition;
			f32 sproutDist         = std::sqrtf(sproutNaviSep.x * sproutNaviSep.x + sproutNaviSep.z * sproutNaviSep.z);
			f32 heightDiff         = zen::Abs(sproutNaviSep.y);
			if (sprout->canPullout() && sproutDist < minDist && heightDiff < 25.0f) {
				minDist       = sproutDist;
				closestSprout = sprout;
			}
		}
	}

	if (closestSprout) {
		if (DelayPikiBirth) {
			_814 = 0.0f;
			startMotion(PaniMotionInfo(PIKIANIM_Asibumi), PaniMotionInfo(PIKIANIM_Asibumi));
			PRINT("nuki d=%.1f rn=%d", minDist, mIsFastPluckEnabled);
			Vector3f sproutSep = closestSprout->mPosition - mPosition;
			_7D0               = angDist(roundAng(atan2f(sproutSep.x, sproutSep.z)), mDirection) / 10.0f;
			f32 dist           = sproutSep.length();
			f32 scaledDist     = 3.0003002f * ((1.0f / dist) * (dist - 15.0f));
			_7C4               = scaledDist * sproutSep;
			_7B8               = 2;
			_7C0               = closestSprout;
			_7BC               = 0;
			mStateMachine->transit(this, NAVISTATE_NukuAdjust);
			return true;
		}

		PikiMgr::meBirthMode = 1;
		Piki* piki           = static_cast<Piki*>(pikiMgr->birth());
		PikiMgr::meBirthMode = 0;

		if (piki) {
			piki->init(this);
			piki->initColor(closestSprout->mSeedColor);
			piki->setFlower(closestSprout->mFlowerStage);
			piki->resetPosition(closestSprout->mPosition);
			piki->changeMode(PikiMode::FreeMode, this);
			piki->mFSM->transit(piki, PIKISTATE_NukareWait);
			closestSprout->kill(false);

			_814 = 0.0f;
			startMotion(PaniMotionInfo(PIKIANIM_Asibumi), PaniMotionInfo(PIKIANIM_Asibumi));

			Vector3f pikiSep = piki->mPosition - mPosition;
			_7D0             = angDist(roundAng(atan2f(pikiSep.x, pikiSep.z)), mDirection) / 10.0f;

			f32 pikiDist   = pikiSep.length();
			f32 scaledDist = 3.0003002f * ((1.0f / pikiDist) * (pikiDist - 15.0f));
			_7C4           = scaledDist * pikiSep;

			_7B8 = 2;
			_7BC = piki;
			mStateMachine->transit(this, NAVISTATE_NukuAdjust);
			PRINT("start nuku !\n");
			return true;
		}
	}

	return false;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2E8(r1)
	  stfd      f31, 0x2E0(r1)
	  stfd      f30, 0x2D8(r1)
	  stfd      f29, 0x2D0(r1)
	  stfd      f28, 0x2C8(r1)
	  stfd      f27, 0x2C0(r1)
	  stfd      f26, 0x2B8(r1)
	  stfd      f25, 0x2B0(r1)
	  stmw      r27, 0x29C(r1)
	  mr        r29, r3
	  lwz       r3, 0xADC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x2E0
	  lwz       r30, 0x301C(r13)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x63A0(r2)
	  mr        r31, r3
	  lfd       f30, -0x6398(r2)
	  lfd       f29, -0x6390(r2)
	  lfs       f28, -0x6338(r2)
	  lfs       f26, -0x62E0(r2)
	  b         .loc_0x284

	.loc_0x74:
	  cmpwi     r31, -0x1
	  bne-      .loc_0x98
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xB0

	.loc_0x98:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xB0:
	  lwz       r4, 0x55C(r3)
	  mr        r28, r3
	  lwz       r0, 0x5C(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x268
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x114(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x268
	  mr        r3, r28
	  bl        -0x673A8
	  cmpwi     r3, 0
	  bne-      .loc_0x268
	  lwz       r3, 0x30AC(r13)
	  bl        -0x9CB8
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  addi      r3, r1, 0x1F0
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x9C(r28)
	  lfs       f2, 0x1F8(r1)
	  lfs       f1, 0x94(r28)
	  lfs       f0, 0x1F0(r1)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f2, f1, f0
	  fcmpo     cr0, f2, f31
	  ble-      .loc_0x18C
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f29, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x16C(r1)
	  lfs       f2, 0x16C(r1)

	.loc_0x18C:
	  fcmpo     cr0, f2, f28
	  bge-      .loc_0x1A0
	  lhz       r0, 0x570(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x268

	.loc_0x1A0:
	  lfs       f3, 0x9C(r28)
	  lfs       f2, 0x9C(r29)
	  lfs       f1, 0x94(r28)
	  lfs       f0, 0x94(r29)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f27, f1, f0
	  fcmpo     cr0, f27, f31
	  ble-      .loc_0x21C
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f29, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f29, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0x168(r1)
	  lfs       f27, 0x168(r1)

	.loc_0x21C:
	  mr        r3, r28
	  bl        -0x66C74
	  fsubs     f0, f27, f1
	  fcmpo     cr0, f0, f26
	  cror      2, 0, 0x2
	  bne-      .loc_0x268
	  lwz       r3, 0x55C(r28)
	  lwz       r3, 0x2C(r3)
	  bl        -0x67F24
	  stw       r28, 0x304(r29)
	  addi      r4, r29, 0
	  li        r5, 0xF
	  lwz       r3, 0x320(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0xA10

	.loc_0x268:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x284:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2AC
	  li        r0, 0x1
	  b         .loc_0x2D8

	.loc_0x2AC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2D4
	  li        r0, 0x1
	  b         .loc_0x2D8

	.loc_0x2D4:
	  li        r0, 0

	.loc_0x2D8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x74

	.loc_0x2E0:
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  lwz       r3, 0x1DC(r4)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x3F0
	  lwz       r3, 0xADC(r29)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x3F0
	  lwz       r3, 0x20(r4)
	  lfs       f0, -0x6360(r2)
	  lfs       f1, 0x20(r3)
	  lfs       f2, 0x2F0(r4)
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x3F0
	  lwz       r3, 0x30AC(r13)
	  bl        -0x9EEC
	  cmplwi    r3, 0
	  beq-      .loc_0x3F0
	  lfs       f3, 0x9C(r3)
	  lfs       f0, 0x9C(r29)
	  lfs       f2, 0x94(r3)
	  lfs       f1, 0x94(r29)
	  fsubs     f3, f3, f0
	  lfs       f0, -0x63A0(r2)
	  fsubs     f2, f2, f1
	  fmuls     f1, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f4, f2, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3BC
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x158(r1)
	  lfs       f4, 0x158(r1)

	.loc_0x3BC:
	  lfs       f0, -0x6304(r2)
	  fcmpo     cr0, f4, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x3F0
	  lwz       r3, 0x320(r29)
	  addi      r4, r29, 0
	  li        r5, 0xE
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0xA10

	.loc_0x3F0:
	  li        r30, 0
	  lfs       f26, -0x62D0(r2)

	.loc_0x3F8:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r30
	  bl        -0xA244
	  cmplwi    r3, 0
	  beq-      .loc_0x444
	  lfs       f3, 0x94(r3)
	  lfs       f2, 0x94(r29)
	  lfs       f1, 0x9C(r3)
	  lfs       f0, 0x9C(r29)
	  fsubs     f2, f3, f2
	  fsubs     f0, f1, f0
	  fmuls     f1, f2, f2
	  fmuls     f0, f0, f0
	  fadds     f0, f1, f0
	  fcmpo     cr0, f0, f26
	  cror      2, 0, 0x2
	  bne-      .loc_0x444
	  li        r0, 0x1
	  b         .loc_0x454

	.loc_0x444:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x3
	  blt+      .loc_0x3F8
	  li        r0, 0

	.loc_0x454:
	  lwz       r3, 0x30AC(r13)
	  rlwinm.   r0,r0,0,24,31
	  li        r30, 0
	  lwz       r31, 0x64(r3)
	  beq-      .loc_0x474
	  lwz       r3, 0x224(r29)
	  lfs       f28, 0x68(r3)
	  b         .loc_0x47C

	.loc_0x474:
	  lwz       r3, 0x224(r29)
	  lfs       f28, 0x88(r3)

	.loc_0x47C:
	  lbz       r0, 0x7E5(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x490
	  lwz       r3, 0x224(r29)
	  lfs       f28, 0x78(r3)

	.loc_0x490:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x63A0(r2)
	  mr        r28, r3
	  lfd       f30, -0x6398(r2)
	  lfd       f31, -0x6390(r2)
	  lfs       f26, -0x62CC(r2)
	  b         .loc_0x5F0

	.loc_0x4BC:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x4E0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4F8

	.loc_0x4E0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x4F8:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0xF
	  bne-      .loc_0x5D4
	  fmr       f1, f28
	  addi      r27, r3, 0
	  addi      r3, r29, 0
	  addi      r4, r27, 0
	  bl        -0x6F480
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x5D4
	  lfs       f3, 0x9C(r27)
	  lfs       f2, 0x9C(r29)
	  lfs       f1, 0x94(r27)
	  lfs       f0, 0x94(r29)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x98(r27)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x98(r29)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fadds     f27, f1, f0
	  fcmpo     cr0, f27, f29
	  ble-      .loc_0x5A8
	  fsqrte    f1, f27
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f27, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f27, f0
	  frsp      f0, f0
	  stfs      f0, 0x140(r1)
	  lfs       f27, 0x140(r1)

	.loc_0x5A8:
	  fabs      f25, f2
	  mr        r3, r27
	  bl        -0x107E0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5D4
	  fcmpo     cr0, f27, f28
	  bge-      .loc_0x5D4
	  fcmpo     cr0, f25, f26
	  bge-      .loc_0x5D4
	  fmr       f28, f27
	  mr        r30, r27

	.loc_0x5D4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x5F0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x618
	  li        r0, 0x1
	  b         .loc_0x644

	.loc_0x618:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x640
	  li        r0, 0x1
	  b         .loc_0x644

	.loc_0x640:
	  li        r0, 0

	.loc_0x644:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4BC
	  cmplwi    r30, 0
	  beq-      .loc_0xA0C
	  lbz       r0, -0x2D80(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x7E4
	  lfs       f0, -0x63A0(r2)
	  addi      r3, r1, 0x1BC
	  li        r4, 0xB
	  stfs      f0, 0x814(r29)
	  bl        0x220EC
	  addi      r3, r1, 0x1C4
	  li        r4, 0xB
	  bl        0x220E0
	  addi      r3, r29, 0x834
	  addi      r4, r1, 0x1C4
	  addi      r5, r1, 0x1BC
	  bl        0x22BE0
	  li        r0, -0x1
	  stw       r0, 0x7E0(r29)
	  lfs       f3, 0x9C(r30)
	  lfs       f2, 0x9C(r29)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x94(r29)
	  fsubs     f30, f3, f2
	  lfs       f2, 0x98(r30)
	  fsubs     f29, f1, f0
	  lfs       f0, 0x98(r29)
	  fsubs     f28, f2, f0
	  fmr       f2, f30
	  fmr       f1, f29
	  bl        0x11EB38
	  bl        -0xC493C
	  lfs       f2, 0xA0(r29)
	  bl        -0xC4918
	  lfs       f3, -0x63A4(r2)
	  fmuls     f2, f29, f29
	  fmuls     f0, f28, f28
	  fdivs     f1, f1, f3
	  stfs      f1, 0x7D0(r29)
	  fadds     f1, f2, f0
	  fmuls     f3, f30, f30
	  lfs       f0, -0x63A0(r2)
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x758
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x120(r1)
	  lfs       f4, 0x120(r1)

	.loc_0x758:
	  lfs       f1, -0x6388(r2)
	  li        r3, 0x2
	  lfs       f0, -0x636C(r2)
	  li        r0, 0
	  fdivs     f1, f1, f4
	  lfs       f2, -0x62C8(r2)
	  addi      r4, r29, 0
	  li        r5, 0x6
	  fsubs     f0, f4, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fmuls     f2, f29, f0
	  fmuls     f1, f28, f0
	  fmuls     f0, f30, f0
	  stfs      f2, 0x114(r1)
	  lfs       f2, 0x114(r1)
	  stfs      f2, 0x1A4(r1)
	  stfs      f1, 0x1A8(r1)
	  stfs      f0, 0x1AC(r1)
	  lwz       r7, 0x1A4(r1)
	  lwz       r6, 0x1A8(r1)
	  stw       r7, 0x7C4(r29)
	  stw       r6, 0x7C8(r29)
	  lwz       r6, 0x1AC(r1)
	  stw       r6, 0x7CC(r29)
	  stw       r3, 0x7B8(r29)
	  stw       r30, 0x7C0(r29)
	  stw       r0, 0x7BC(r29)
	  lwz       r3, 0x320(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0xA10

	.loc_0x7E4:
	  li        r0, 0x1
	  lwz       r3, 0x3068(r13)
	  stb       r0, 0x306D(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  mr.       r27, r3
	  stb       r0, 0x306D(r13)
	  beq-      .loc_0xA0C
	  addi      r3, r27, 0
	  addi      r4, r29, 0
	  bl        -0x30FD0
	  mr        r3, r27
	  lwz       r4, 0x3CC(r30)
	  bl        -0x337A8
	  mr        r3, r27
	  lwz       r4, 0x3D0(r30)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  addi      r4, r30, 0x94
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r27, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  bl        -0x2FE94
	  lwz       r3, 0x490(r27)
	  addi      r4, r27, 0
	  li        r5, 0x4
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x723A8
	  lfs       f0, -0x63A0(r2)
	  addi      r3, r1, 0x194
	  li        r4, 0xB
	  stfs      f0, 0x814(r29)
	  bl        0x21EBC
	  addi      r3, r1, 0x19C
	  li        r4, 0xB
	  bl        0x21EB0
	  addi      r3, r29, 0x834
	  addi      r4, r1, 0x19C
	  addi      r5, r1, 0x194
	  bl        0x229B0
	  li        r0, -0x1
	  stw       r0, 0x7E0(r29)
	  lfs       f3, 0x9C(r27)
	  lfs       f2, 0x9C(r29)
	  lfs       f1, 0x94(r27)
	  lfs       f0, 0x94(r29)
	  fsubs     f30, f3, f2
	  lfs       f2, 0x98(r27)
	  fsubs     f29, f1, f0
	  lfs       f0, 0x98(r29)
	  fsubs     f28, f2, f0
	  fmr       f2, f30
	  fmr       f1, f29
	  bl        0x11E908
	  bl        -0xC4B6C
	  lfs       f2, 0xA0(r29)
	  bl        -0xC4B48
	  lfs       f3, -0x63A4(r2)
	  fmuls     f2, f29, f29
	  fmuls     f0, f28, f28
	  fdivs     f1, f1, f3
	  stfs      f1, 0x7D0(r29)
	  fadds     f1, f2, f0
	  fmuls     f3, f30, f30
	  lfs       f0, -0x63A0(r2)
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x988
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x110(r1)
	  lfs       f4, 0x110(r1)

	.loc_0x988:
	  lfs       f1, -0x6388(r2)
	  li        r0, 0x2
	  lfs       f0, -0x636C(r2)
	  mr        r4, r29
	  fdivs     f1, f1, f4
	  lfs       f2, -0x62C8(r2)
	  li        r5, 0x6
	  fsubs     f0, f4, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fmuls     f2, f29, f0
	  fmuls     f1, f28, f0
	  fmuls     f0, f30, f0
	  stfs      f2, 0x104(r1)
	  lfs       f2, 0x104(r1)
	  stfs      f2, 0x17C(r1)
	  stfs      f1, 0x180(r1)
	  stfs      f0, 0x184(r1)
	  lwz       r6, 0x17C(r1)
	  lwz       r3, 0x180(r1)
	  stw       r6, 0x7C4(r29)
	  stw       r3, 0x7C8(r29)
	  lwz       r3, 0x184(r1)
	  stw       r3, 0x7CC(r29)
	  stw       r0, 0x7B8(r29)
	  stw       r27, 0x7BC(r29)
	  lwz       r3, 0x320(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0xA10

	.loc_0xA0C:
	  li        r3, 0

	.loc_0xA10:
	  lmw       r27, 0x29C(r1)
	  lwz       r0, 0x2EC(r1)
	  lfd       f31, 0x2E0(r1)
	  lfd       f30, 0x2D8(r1)
	  lfd       f29, 0x2D0(r1)
	  lfd       f28, 0x2C8(r1)
	  lfd       f27, 0x2C0(r1)
	  lfd       f26, 0x2B8(r1)
	  lfd       f25, 0x2B0(r1)
	  addi      r1, r1, 0x2E8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FD23C
 * Size:	00003C
 */
void Navi::offwallCallback(DynCollObject* wall)
{
	MsgOffWall msg(wall);
	sendMsg(&msg);
}

/*
 * --INFO--
 * Address:	800FD278
 * Size:	000058
 */
void Navi::wallCallback(Plane& wallPlane, DynCollObject* wallObj)
{
	mWallPlane   = &wallPlane;
	_7B4         = 1;
	mWallCollObj = wallObj;
	mAiTickTimer = 0.1f;
	MsgWall msg(wallPlane, wallObj);
	sendMsg(&msg);
}

/*
 * --INFO--
 * Address:	800FD2D0
 * Size:	000004
 */
void Navi::jumpCallback()
{
}

/*
 * --INFO--
 * Address:	800FD2D4
 * Size:	00004C
 */
bool Navi::isAtari()
{
	int state = mStateMachine->getCurrID(this);
	return state != NAVISTATE_Pressed && state != NAVISTATE_Bury && state != NAVISTATE_Container;
}

/*
 * --INFO--
 * Address:	800FD320
 * Size:	00004C
 */
bool Navi::ignoreAtari(Creature* target)
{
	if (target->mObjType == OBJTYPE_Piki) {
		int state = static_cast<Piki*>(target)->getState();
		if (state == PIKISTATE_Flying || state == PIKISTATE_Hanged) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	800FD36C
 * Size:	000050
 */
void Navi::bounceCallback()
{
	MsgBounce msg(Vector3f(0.0f, 1.0f, 0.0f));
	sendMsg(&msg);
}

/*
 * --INFO--
 * Address:	800FD3BC
 * Size:	0001D8
 */
void Navi::letPikiWork()
{
	Iterator iter(mPlateMgr);
	// this sure is one way to get the first piki in mPlateMgr
	iter.first();
	Piki* piki = static_cast<Piki*>(*iter);
	if (piki) {
		if (_2FC->mObjType == OBJTYPE_WorkObject) {
			WorkObject* obj = static_cast<WorkObject*>(_2FC);
			if (obj->isBridge()) {
				Bridge* bridge = static_cast<Bridge*>(obj);
				Vector3f zVec(bridge->getBridgeZVec());
				zVec.multiply(-1.0f);
				piki->checkBridgeWall(obj, zVec);
				return;
			}
		}
		CollPart* part;
		if (_2FC->isSluice()) {
			part = _2FC->mCollInfo->getSphere('gate');
		}

		CollEvent event(_2FC, part, nullptr);
		_830 = 1;
		piki->collisionCallback(event);
		_830 = 0;
	}
}

/*
 * --INFO--
 * Address:	800FD594
 * Size:	000370
 */
void Navi::collisionCallback(CollEvent& event)
{

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stfd      f30, 0xE8(r1)
	  stfd      f29, 0xE0(r1)
	  stfd      f28, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  stw       r30, 0xD0(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xCC(r1)
	  stw       r28, 0xC8(r1)
	  addi      r28, r4, 0
	  lwz       r0, 0x2FC(r3)
	  lwz       r3, 0x0(r4)
	  cmplw     r3, r0
	  addi      r31, r3, 0
	  beq-      .loc_0x15C
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x26
	  beq-      .loc_0x78
	  bge-      .loc_0x6C
	  cmpwi     r0, 0x1A
	  bge-      .loc_0x15C
	  cmpwi     r0, 0x16
	  bge-      .loc_0x110
	  b         .loc_0x15C

	.loc_0x6C:
	  cmpwi     r0, 0x34
	  beq-      .loc_0x110
	  b         .loc_0x15C

	.loc_0x78:
	  addi      r29, r31, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x110
	  lbz       r0, 0x3C8(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x340
	  mr        r3, r30
	  bl        -0x733F4
	  cmplw     r3, r29
	  bne-      .loc_0x340
	  addi      r3, r1, 0x78
	  addi      r4, r30, 0
	  bl        -0x733EC
	  lfs       f31, 0x78(r1)
	  mr        r4, r29
	  lfs       f30, 0x7C(r1)
	  addi      r3, r1, 0x6C
	  lfs       f29, 0x80(r1)
	  bl        -0x5EB0C
	  lfs       f1, 0x6C(r1)
	  lfs       f0, 0x70(r1)
	  fmuls     f2, f31, f1
	  lfs       f3, 0x74(r1)
	  fmuls     f1, f30, f0
	  lfs       f0, -0x62C0(r2)
	  fmuls     f3, f29, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x110
	  b         .loc_0x340
	  b         .loc_0x340

	.loc_0x110:
	  lwz       r0, 0x2FC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x124
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x300(r30)

	.loc_0x124:
	  stw       r31, 0x2FC(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x300(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x300(r30)
	  lfs       f1, 0x300(r30)
	  lfs       f0, -0x6384(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x15C
	  mr        r3, r30
	  bl        -0x328
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x300(r30)

	.loc_0x15C:
	  li        r0, 0x3
	  stw       r0, 0xA8(r1)
	  addi      r3, r30, 0
	  addi      r4, r1, 0xA8
	  lwz       r0, 0x0(r28)
	  stw       r0, 0xAC(r1)
	  lwz       r0, 0x4(r28)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0x8(r28)
	  stw       r0, 0xB4(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA4(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xADC(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x1A8
	  lwz       r29, 0x4(r3)
	  b         .loc_0x1AC

	.loc_0x1A8:
	  li        r29, -0x1

	.loc_0x1AC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x340
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x260
	  bge-      .loc_0x1E4
	  cmpwi     r0, 0x3
	  bge-      .loc_0x1F0
	  b         .loc_0x340

	.loc_0x1E4:
	  cmpwi     r0, 0x6
	  bge-      .loc_0x340
	  b         .loc_0x234

	.loc_0x1F0:
	  lwz       r0, 0x64(r31)
	  cmplwi    r0, 0
	  mr        r3, r31
	  bl        -0x72F3C
	  li        r0, 0x2
	  stw       r0, 0x9C(r1)
	  addi      r4, r1, 0x9C
	  stw       r3, 0xA0(r1)
	  addi      r3, r30, 0x8
	  bl        -0x69770
	  lwz       r5, 0x734(r30)
	  addi      r3, r31, 0
	  li        r4, 0
	  addi      r0, r5, 0x1
	  stw       r0, 0x734(r30)
	  bl        -0x72AE0
	  b         .loc_0x340

	.loc_0x234:
	  lwz       r3, 0x734(r30)
	  cmpwi     r3, 0
	  ble-      .loc_0x340
	  lwz       r0, 0x3CC(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x340
	  subi      r0, r3, 0x1
	  stw       r0, 0x734(r30)
	  mr        r3, r31
	  bl        -0x101B8
	  b         .loc_0x340

	.loc_0x260:
	  lwz       r0, 0x734(r30)
	  cmpwi     r0, 0
	  ble-      .loc_0x340
	  cmpwi     r29, 0x22
	  beq-      .loc_0x340
	  lis       r3, 0x803A
	  lwz       r5, 0x3D0(r31)
	  subi      r3, r3, 0x24E0
	  crclr     6, 0x6
	  addi      r3, r3, 0x1B0
	  subi      r4, r13, 0x2BC0
	  bl        0x118D78
	  lfs       f3, 0x94(r30)
	  lfs       f2, 0x94(r31)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x98(r31)
	  fsubs     f29, f3, f2
	  lfs       f2, 0x9C(r30)
	  fsubs     f30, f1, f0
	  lfs       f0, 0x9C(r31)
	  fmuls     f1, f29, f29
	  fsubs     f28, f2, f0
	  fmuls     f0, f30, f30
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xEFC1C
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2E4
	  fdivs     f29, f29, f1
	  fdivs     f30, f30, f1
	  fdivs     f28, f28, f1

	.loc_0x2E4:
	  lfs       f1, 0xA0(r31)
	  bl        0x11E2D8
	  fmr       f31, f1
	  lfs       f1, 0xA0(r31)
	  bl        0x11E460
	  lfs       f0, -0x2BC4(r13)
	  fmuls     f2, f1, f29
	  fmuls     f3, f31, f28
	  lfs       f1, -0x62BC(r2)
	  fmuls     f0, f0, f30
	  fadds     f0, f2, f0
	  fadds     f31, f3, f0
	  bl        0x11E2AC
	  fcmpo     cr0, f31, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x340
	  lwz       r3, 0x320(r30)
	  addi      r4, r30, 0
	  li        r5, 0x22
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x340:
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lfd       f28, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  lwz       r29, 0xCC(r1)
	  lwz       r28, 0xC8(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FD904
 * Size:	000004
 */
void Navi::doKill()
{
}

/*
 * --INFO--
 * Address:	800FD908
 * Size:	0001E8
 */
void Navi::reviseController(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stfd      f29, 0x70(r1)
	  stfd      f28, 0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r4
	  stw       r30, 0x60(r1)
	  mr        r30, r3
	  lfs       f2, 0x0(r4)
	  lfs       f1, 0x4(r4)
	  fmuls     f2, f2, f2
	  lfs       f3, 0x8(r4)
	  fmuls     f1, f1, f1
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f31, f3, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0xB0
	  fsqrte    f1, f31
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0x28(r1)
	  lfs       f31, 0x28(r1)

	.loc_0xB0:
	  lfs       f1, 0x0(r31)
	  lfs       f2, 0x8(r31)
	  bl        0x11E038
	  bl        -0xC543C
	  lwz       r4, 0x224(r30)
	  lis       r3, 0x4330
	  lfs       f3, -0x62B8(r2)
	  lfs       f2, 0x328(r4)
	  lfs       f0, -0x6384(r2)
	  fmuls     f4, f3, f2
	  lfd       f3, -0x62E8(r2)
	  lfs       f2, -0x62B4(r2)
	  fmuls     f0, f0, f4
	  fadds     f0, f1, f0
	  fdivs     f0, f0, f4
	  fctiwz    f0, f0
	  stfd      f0, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x54(r1)
	  stw       r3, 0x50(r1)
	  lfd       f0, 0x50(r1)
	  fsubs     f0, f0, f3
	  fmuls     f29, f4, f0
	  fdivs     f0, f29, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x44(r1)
	  stw       r3, 0x40(r1)
	  lfd       f0, 0x40(r1)
	  fsubs     f0, f0, f3
	  fmuls     f0, f2, f0
	  fsubs     f28, f29, f0
	  fsubs     f1, f2, f28
	  bl        0x11E2A0
	  fmr       f30, f1
	  fmr       f1, f28
	  bl        0x11E294
	  fadds     f30, f1, f30
	  lfs       f1, -0x62B4(r2)
	  bl        0x11E288
	  fdivs     f3, f1, f30
	  lfs       f2, -0x6388(r2)
	  lwz       r4, 0x224(r30)
	  lfs       f0, 0x388(r4)
	  fdivs     f1, f2, f3
	  fmuls     f31, f31, f1
	  fcmpo     cr0, f31, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x184
	  fmr       f31, f2

	.loc_0x184:
	  lfs       f0, 0x368(r4)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x194
	  lfs       f31, -0x63A0(r2)

	.loc_0x194:
	  stfs      f3, 0x30B0(r13)
	  fmr       f1, f29
	  bl        0x11E0B0
	  fmuls     f30, f31, f1
	  fmr       f1, f29
	  bl        0x11E238
	  fmuls     f0, f31, f1
	  stfs      f0, 0x0(r31)
	  lfs       f0, -0x2BBC(r13)
	  stfs      f0, 0x4(r31)
	  stfs      f30, 0x8(r31)
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  lfd       f29, 0x70(r1)
	  lfd       f28, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FDAF0
 * Size:	0008FC
 */
void Navi::makeVelocity(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x390(r1)
	  stfd      f31, 0x388(r1)
	  stfd      f30, 0x380(r1)
	  stfd      f29, 0x378(r1)
	  stfd      f28, 0x370(r1)
	  stfd      f27, 0x368(r1)
	  stfd      f26, 0x360(r1)
	  stfd      f25, 0x358(r1)
	  stfd      f24, 0x350(r1)
	  stw       r31, 0x34C(r1)
	  stw       r30, 0x348(r1)
	  mr        r30, r4
	  stw       r29, 0x344(r1)
	  mr        r29, r3
	  stw       r28, 0x340(r1)
	  lwz       r5, 0x2DEC(r13)
	  lfs       f1, 0x738(r3)
	  lfs       f0, 0x28C(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x738(r3)
	  lwz       r3, 0x2E4(r3)
	  lwz       r3, 0x20(r3)
	  rlwinm.   r0,r3,0,18,18
	  bne-      .loc_0x80
	  rlwinm.   r0,r3,0,19,19
	  bne-      .loc_0x80
	  rlwinm.   r0,r3,0,17,17
	  bne-      .loc_0x80
	  rlwinm.   r0,r3,0,15,15
	  beq-      .loc_0x88

	.loc_0x80:
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x738(r29)

	.loc_0x88:
	  lwz       r3, 0x2E4(r29)
	  bl        -0xBD0A8
	  fneg      f24, f1
	  lwz       r3, 0x2E4(r29)
	  bl        -0xBD0EC
	  fmr       f3, f24
	  lfs       f2, -0x63A0(r2)
	  addi      r3, r1, 0x32C
	  bl        0x1F344
	  lfs       f1, 0x32C(r1)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xC8
	  stfs      f0, 0x32C(r1)
	  b         .loc_0xDC

	.loc_0xC8:
	  lfs       f0, -0x62C4(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xDC
	  stfs      f0, 0x32C(r1)

	.loc_0xDC:
	  lfs       f1, 0x334(r1)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xF8
	  stfs      f0, 0x334(r1)
	  b         .loc_0x10C

	.loc_0xF8:
	  lfs       f0, -0x62C4(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x10C
	  stfs      f0, 0x334(r1)

	.loc_0x10C:
	  addi      r3, r29, 0
	  addi      r4, r1, 0x32C
	  bl        -0x2FC
	  lwz       r3, 0x74C(r29)
	  lwz       r0, 0x750(r29)
	  stw       r3, 0x740(r29)
	  stw       r0, 0x744(r29)
	  lwz       r0, 0x754(r29)
	  stw       r0, 0x748(r29)
	  lwz       r3, 0x32C(r1)
	  lwz       r0, 0x330(r1)
	  stw       r3, 0x74C(r29)
	  stw       r0, 0x750(r29)
	  lwz       r0, 0x334(r1)
	  stw       r0, 0x754(r29)
	  lwz       r3, 0x2E8(r29)
	  lfs       f1, 0x184(r3)
	  lfs       f2, 0x17C(r3)
	  bl        0x201C4
	  fmr       f0, f1
	  lfs       f1, -0x63A0(r2)
	  lfs       f2, -0x6388(r2)
	  addi      r3, r1, 0x298
	  fmr       f3, f1
	  fmr       f24, f0
	  bl        0x1F27C
	  fmr       f1, f24
	  addi      r4, r3, 0
	  addi      r3, r1, 0x2A4
	  bl        0x1E010
	  addi      r28, r3, 0
	  addi      r3, r1, 0x258
	  bl        0x1ED84
	  addi      r31, r3, 0
	  addi      r4, r28, 0
	  bl        0x1F048
	  rlwinm.   r0,r30,0,24,31
	  bne-      .loc_0x1BC
	  lfs       f0, -0x2BB8(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x2BB4(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x2BB0(r13)
	  stfs      f0, 0xAC(r29)

	.loc_0x1BC:
	  addi      r3, r31, 0
	  addi      r4, r1, 0x32C
	  bl        0x1EFF0
	  rlwinm.   r0,r30,0,24,31
	  bne-      .loc_0x460
	  addi      r3, r1, 0x318
	  addi      r4, r29, 0
	  bl        -0x6D044
	  lwz       r0, 0x320(r1)
	  lfs       f24, -0x6388(r2)
	  cmpwi     r0, 0
	  ble-      .loc_0x224
	  xoris     r0, r0, 0x8000
	  lfd       f2, -0x62E8(r2)
	  stw       r0, 0x33C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x62B0(r2)
	  stw       r0, 0x338(r1)
	  lfs       f0, -0x637C(r2)
	  lfd       f1, 0x338(r1)
	  fsubs     f1, f1, f2
	  fmuls     f1, f3, f1
	  fsubs     f24, f24, f1
	  fcmpo     cr0, f24, f0
	  bge-      .loc_0x224
	  fmr       f24, f0

	.loc_0x224:
	  lwz       r3, 0x710(r29)
	  bl        -0x58398
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2B0
	  lwz       r3, 0x224(r29)
	  lfs       f0, 0x32C(r1)
	  lfs       f3, 0xE8(r3)
	  lfs       f2, 0x334(r1)
	  fmuls     f1, f0, f3
	  lfs       f0, 0x330(r1)
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f3
	  stfs      f1, 0x1B0(r1)
	  lfs       f1, 0x1B0(r1)
	  stfs      f1, 0x240(r1)
	  stfs      f0, 0x244(r1)
	  stfs      f2, 0x248(r1)
	  lfs       f0, 0x240(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x1A0(r1)
	  lfs       f0, 0x1A0(r1)
	  stfs      f0, 0x24C(r1)
	  lfs       f0, 0x244(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x250(r1)
	  lfs       f0, 0x248(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x254(r1)
	  lwz       r3, 0x24C(r1)
	  lwz       r0, 0x250(r1)
	  stw       r3, 0xA4(r29)
	  stw       r0, 0xA8(r29)
	  lwz       r0, 0x254(r1)
	  stw       r0, 0xAC(r29)
	  b         .loc_0x328

	.loc_0x2B0:
	  lwz       r3, 0x224(r29)
	  lfs       f0, 0x32C(r1)
	  lfs       f3, 0xD8(r3)
	  lfs       f2, 0x334(r1)
	  fmuls     f1, f0, f3
	  lfs       f0, 0x330(r1)
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f3
	  stfs      f1, 0x194(r1)
	  lfs       f1, 0x194(r1)
	  stfs      f1, 0x228(r1)
	  stfs      f0, 0x22C(r1)
	  stfs      f2, 0x230(r1)
	  lfs       f0, 0x228(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x184(r1)
	  lfs       f0, 0x184(r1)
	  stfs      f0, 0x234(r1)
	  lfs       f0, 0x22C(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x238(r1)
	  lfs       f0, 0x230(r1)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x23C(r1)
	  lwz       r3, 0x234(r1)
	  lwz       r0, 0x238(r1)
	  stw       r3, 0xA4(r29)
	  stw       r0, 0xA8(r29)
	  lwz       r0, 0x23C(r1)
	  stw       r0, 0xAC(r29)

	.loc_0x328:
	  lwz       r0, 0x28C(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x460
	  lfs       f1, 0xA4(r29)
	  lfs       f0, 0xA8(r29)
	  fmuls     f2, f1, f1
	  lfs       f3, 0xAC(r29)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3B8
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x130(r1)
	  lfs       f0, 0x130(r1)

	.loc_0x3B8:
	  lwz       r3, 0x28C(r29)
	  addi      r6, r1, 0xDC
	  lfs       f3, 0xA4(r29)
	  addi      r5, r1, 0xD8
	  lfs       f2, 0x18(r3)
	  lfs       f1, 0xA8(r29)
	  addi      r7, r3, 0x18
	  lfs       f0, 0x1C(r3)
	  fmuls     f2, f3, f2
	  lfs       f4, 0xAC(r29)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x20(r3)
	  lfs       f0, 0x20(r3)
	  fmuls     f3, f4, f3
	  addi      r4, r1, 0xD4
	  fadds     f1, f2, f1
	  addi      r3, r1, 0x210
	  fadds     f1, f3, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xD4(r1)
	  bl        -0xC6DF4
	  lfs       f3, 0xA4(r29)
	  lfs       f2, 0x210(r1)
	  lfs       f1, 0xA8(r29)
	  lfs       f0, 0x214(r1)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xAC(r29)
	  fsubs     f4, f1, f0
	  lfs       f0, 0x218(r1)
	  fmuls     f1, f3, f3
	  fsubs     f2, f2, f0
	  fmuls     f0, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF030C

	.loc_0x460:
	  addi      r3, r31, 0
	  addi      r4, r29, 0x74C
	  bl        0x1ED4C
	  lfs       f1, 0x32C(r1)
	  lfs       f0, 0x330(r1)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x334(r1)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f28, f3, f1
	  fcmpo     cr0, f28, f0
	  ble-      .loc_0x4F0
	  fsqrte    f1, f28
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f28, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f28, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f28, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f28, f0
	  frsp      f0, f0
	  stfs      f0, 0x11C(r1)
	  lfs       f28, 0x11C(r1)

	.loc_0x4F0:
	  lfs       f24, 0x32C(r1)
	  lfs       f25, 0x330(r1)
	  fmuls     f1, f24, f24
	  lfs       f26, 0x334(r1)
	  fmuls     f0, f25, f25
	  fmuls     f2, f26, f26
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF03C0
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x52C
	  fdivs     f24, f24, f1
	  fdivs     f25, f25, f1
	  fdivs     f26, f26, f1

	.loc_0x52C:
	  lwz       r4, 0x224(r29)
	  addi      r6, r1, 0xF8
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r1, 0xF4
	  lfs       f0, 0x3B8(r4)
	  lfs       f30, 0x28C(r3)
	  addi      r4, r1, 0xF0
	  fmuls     f31, f26, f0
	  addi      r3, r1, 0x1F4
	  fmuls     f25, f25, f0
	  fmuls     f24, f24, f0
	  fmuls     f2, f31, f30
	  fmuls     f1, f25, f30
	  fmuls     f0, f24, f30
	  stfs      f2, 0xF8(r1)
	  stfs      f1, 0xF4(r1)
	  stfs      f0, 0xF0(r1)
	  bl        -0xC6F44
	  lfs       f1, 0x1F4(r1)
	  lfs       f0, 0x6D4(r29)
	  lfs       f3, 0x1F8(r1)
	  lfs       f2, 0x6D8(r29)
	  fadds     f0, f1, f0
	  lfs       f1, 0x6DC(r29)
	  lfs       f4, 0x1FC(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x2E4(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x2E8(r1)
	  stfs      f0, 0x2EC(r1)
	  lfs       f0, 0x2E4(r1)
	  lfs       f27, 0x2E8(r1)
	  fmuls     f2, f0, f0
	  lfs       f26, 0x2EC(r1)
	  fmuls     f1, f27, f27
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f26, f26
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x628
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x10C(r1)
	  lfs       f4, 0x10C(r1)

	.loc_0x628:
	  lwz       r3, 0x224(r29)
	  lfs       f0, 0x3A8(r3)
	  fcmpo     cr0, f4, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x6F8
	  lfs       f29, 0x2E4(r1)
	  fmuls     f0, f27, f27
	  fmuls     f2, f26, f26
	  fmuls     f1, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF0504
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x670
	  fdivs     f29, f29, f1
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1

	.loc_0x670:
	  fmuls     f1, f29, f24
	  addi      r6, r1, 0xEC
	  fmuls     f0, f27, f25
	  addi      r5, r1, 0xE8
	  fmuls     f2, f26, f31
	  fadds     f0, f1, f0
	  addi      r4, r1, 0xE4
	  addi      r3, r1, 0x1E8
	  fadds     f0, f2, f0
	  fmuls     f2, f26, f0
	  fmuls     f1, f27, f0
	  fmuls     f0, f29, f0
	  stfs      f2, 0xEC(r1)
	  stfs      f1, 0xE8(r1)
	  stfs      f0, 0xE4(r1)
	  bl        -0xC7080
	  lfs       f1, 0x1E8(r1)
	  lfs       f0, 0x1EC(r1)
	  fsubs     f1, f24, f1
	  lfs       f3, 0x1F0(r1)
	  fsubs     f0, f25, f0
	  lfs       f2, 0x6D4(r29)
	  fsubs     f4, f31, f3
	  fmuls     f3, f1, f30
	  fmuls     f1, f0, f30
	  fmuls     f4, f4, f30
	  fadds     f0, f3, f2
	  stfs      f0, 0x2E4(r1)
	  lfs       f0, 0x6D8(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2E8(r1)
	  lfs       f0, 0x6DC(r29)
	  fadds     f0, f4, f0
	  stfs      f0, 0x2EC(r1)

	.loc_0x6F8:
	  lwz       r3, 0x2E4(r1)
	  lwz       r0, 0x2E8(r1)
	  stw       r3, 0x6D4(r29)
	  stw       r0, 0x6D8(r29)
	  lwz       r0, 0x2EC(r1)
	  stw       r0, 0x6DC(r29)
	  lfs       f1, 0x2E4(r1)
	  lfs       f0, 0x2E8(r1)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x2EC(r1)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x794
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0xFC(r1)
	  lfs       f4, 0xFC(r1)

	.loc_0x794:
	  stfs      f4, 0x6E0(r29)
	  lwz       r3, 0x2E4(r1)
	  lwz       r0, 0x2E8(r1)
	  stw       r3, 0x6E4(r29)
	  stw       r0, 0x6E8(r29)
	  lwz       r0, 0x2EC(r1)
	  stw       r0, 0x6EC(r29)
	  lwz       r3, 0x224(r29)
	  lfs       f0, 0x368(r3)
	  fcmpo     cr0, f28, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x7CC
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x738(r29)

	.loc_0x7CC:
	  lwz       r4, 0x224(r29)
	  li        r0, 0
	  lfs       f1, 0x738(r29)
	  lfs       f0, 0x348(r4)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x7EC
	  li        r0, 0x1

	.loc_0x7EC:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x804
	  bne-      .loc_0x88C
	  lfs       f0, 0x368(r4)
	  fcmpo     cr0, f28, f0
	  ble-      .loc_0x88C

	.loc_0x804:
	  lfs       f0, 0x378(r4)
	  fcmpo     cr0, f28, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x88C
	  lfs       f0, -0x2BAC(r13)
	  stfs      f0, 0xA4(r29)
	  lfs       f0, -0x2BA8(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x2BA4(r13)
	  stfs      f0, 0xAC(r29)
	  lfs       f1, 0x6D4(r29)
	  lfs       f2, 0x6DC(r29)
	  bl        0x11D6D4
	  bl        -0xC5DA0
	  lfs       f2, 0xA0(r29)
	  bl        -0xC5D7C
	  lfs       f2, -0x6360(r2)
	  lfs       f0, 0xA0(r29)
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0xA0(r29)
	  lfs       f1, 0xA0(r29)
	  bl        -0xC5DC4
	  stfs      f1, 0xA0(r29)
	  lfs       f0, -0x2BA0(r13)
	  stfs      f0, 0x88(r29)
	  lfs       f0, 0xA0(r29)
	  stfs      f0, 0x8C(r29)
	  lfs       f0, -0x2B9C(r13)
	  stfs      f0, 0x90(r29)
	  lwz       r0, 0xC8(r29)
	  ori       r0, r0, 0x400
	  stw       r0, 0xC8(r29)
	  b         .loc_0x898

	.loc_0x88C:
	  lwz       r0, 0xC8(r29)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0xC8(r29)

	.loc_0x898:
	  lfs       f1, -0x2B98(r13)
	  mr        r3, r29
	  lfs       f0, -0x2B94(r13)
	  li        r4, 0
	  stfs      f1, 0x32C(r1)
	  stfs      f0, 0x330(r1)
	  lfs       f0, -0x2B90(r13)
	  stfs      f0, 0x334(r1)
	  bl        .loc_0x8FC
	  lwz       r0, 0x394(r1)
	  lfd       f31, 0x388(r1)
	  lfd       f30, 0x380(r1)
	  lfd       f29, 0x378(r1)
	  lfd       f28, 0x370(r1)
	  lfd       f27, 0x368(r1)
	  lfd       f26, 0x360(r1)
	  lfd       f25, 0x358(r1)
	  lfd       f24, 0x350(r1)
	  lwz       r31, 0x34C(r1)
	  lwz       r30, 0x348(r1)
	  lwz       r29, 0x344(r1)
	  lwz       r28, 0x340(r1)
	  addi      r1, r1, 0x390
	  mtlr      r0
	  blr

	.loc_0x8FC:
	*/
}

/*
 * --INFO--
 * Address:	800FE3EC
 * Size:	000858
 */
void Navi::makeCStick(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1E8(r1)
	  stfd      f31, 0x1E0(r1)
	  stfd      f30, 0x1D8(r1)
	  stfd      f29, 0x1D0(r1)
	  stfd      f28, 0x1C8(r1)
	  stfd      f27, 0x1C0(r1)
	  stfd      f26, 0x1B8(r1)
	  stw       r31, 0x1B4(r1)
	  mr        r31, r3
	  stw       r30, 0x1B0(r1)
	  mr        r30, r4
	  stw       r29, 0x1AC(r1)
	  stw       r28, 0x1A8(r1)
	  lwz       r3, 0x2E8(r3)
	  lfs       f1, 0x184(r3)
	  lfs       f2, 0x17C(r3)
	  bl        0x1F9D4
	  fmr       f0, f1
	  lfs       f1, -0x63A0(r2)
	  lfs       f2, -0x6388(r2)
	  addi      r3, r1, 0x124
	  fmr       f3, f1
	  fmr       f27, f0
	  bl        0x1EA8C
	  fmr       f1, f27
	  addi      r4, r3, 0
	  addi      r3, r1, 0x130
	  bl        0x1D820
	  addi      r28, r3, 0
	  addi      r3, r1, 0xE4
	  bl        0x1E594
	  addi      r29, r3, 0
	  addi      r4, r28, 0
	  bl        0x1E858
	  lwz       r3, 0x2E4(r31)
	  bl        -0xBD93C
	  fneg      f27, f1
	  lwz       r3, 0x2E4(r31)
	  bl        -0xBD980
	  fmr       f3, f27
	  lfs       f2, -0x63A0(r2)
	  addi      r3, r1, 0x18C
	  bl        0x1EA40
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0xD4
	  lfs       f0, -0x2B8C(r13)
	  lfs       f1, -0x2B88(r13)
	  stfs      f0, 0x18C(r1)
	  lfs       f0, -0x2B84(r13)
	  stfs      f1, 0x190(r1)
	  stfs      f0, 0x194(r1)

	.loc_0xD4:
	  addi      r3, r31, 0
	  addi      r4, r1, 0x18C
	  bl        -0xBC0
	  lwz       r4, 0x710(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x158
	  lwz       r3, 0xADC(r31)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x19
	  beq-      .loc_0x158
	  cmpwi     r0, 0x1D
	  beq-      .loc_0x158
	  lwz       r0, 0x74(r4)
	  cmpwi     r0, 0
	  ble-      .loc_0x148
	  lfs       f2, -0x62AC(r2)
	  lfs       f1, 0x18C(r1)
	  lfs       f0, 0x194(r1)
	  fmuls     f1, f2, f1
	  lwz       r3, 0x3030(r13)
	  fmuls     f0, f2, f0
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x1A0(r1)
	  stfd      f0, 0x198(r1)
	  lwz       r4, 0x1A4(r1)
	  lwz       r5, 0x19C(r1)
	  bl        -0x5AF84
	  b         .loc_0x158

	.loc_0x148:
	  lwz       r3, 0x3030(r13)
	  li        r4, 0
	  li        r5, 0
	  bl        -0x5AF98

	.loc_0x158:
	  lfs       f0, 0x18C(r1)
	  mr        r3, r29
	  lfs       f1, -0x6388(r2)
	  addi      r4, r1, 0x18C
	  fmuls     f0, f0, f1
	  stfs      f0, 0x18C(r1)
	  lfs       f0, 0x190(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x190(r1)
	  lfs       f0, 0x194(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x194(r1)
	  bl        0x1E730
	  lfs       f0, -0x2B80(r13)
	  stfs      f0, 0x764(r31)
	  lfs       f0, -0x2B7C(r13)
	  stfs      f0, 0x768(r31)
	  lfs       f0, -0x2B78(r13)
	  stfs      f0, 0x76C(r31)
	  lfs       f1, 0x18C(r1)
	  lfs       f0, 0x190(r1)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x194(r1)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x228
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0xAC(r1)
	  lfs       f4, 0xAC(r1)

	.loc_0x228:
	  lfs       f0, -0x62A8(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3D4
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x738(r31)
	  lwz       r3, 0x18C(r1)
	  lwz       r0, 0x190(r1)
	  stw       r3, 0x764(r31)
	  stw       r0, 0x768(r31)
	  lwz       r0, 0x194(r1)
	  stw       r0, 0x76C(r31)
	  lfs       f1, 0x18C(r1)
	  lfs       f2, 0x194(r1)
	  bl        0x11D3B0
	  lwz       r3, 0x710(r31)
	  fmr       f31, f1
	  lfs       f26, 0xAC(r3)
	  bl        0x11D4FC
	  fmr       f29, f1
	  fmr       f1, f31
	  bl        0x11D684
	  fmr       f28, f1
	  lfs       f30, -0x2B74(r13)
	  fmr       f1, f26
	  bl        0x11D4E0
	  fmr       f27, f1
	  fmr       f1, f26
	  bl        0x11D668
	  lfs       f0, -0x2B70(r13)
	  fmuls     f2, f28, f1
	  fmuls     f3, f29, f27
	  lfs       f1, -0x62A4(r2)
	  fmuls     f0, f30, f0
	  fadds     f0, f2, f0
	  fadds     f27, f3, f0
	  bl        0x11D4B4
	  fcmpo     cr0, f27, f1
	  ble-      .loc_0x2DC
	  fmr       f1, f31
	  fmr       f2, f26
	  bl        -0xC6100
	  lfs       f0, -0x62A0(r2)
	  fmuls     f0, f0, f1
	  fadds     f1, f26, f0
	  b         .loc_0x2E0

	.loc_0x2DC:
	  fmr       f1, f31

	.loc_0x2E0:
	  bl        -0xC6144
	  fmr       f29, f1
	  stfs      f29, 0x714(r31)
	  lfs       f1, 0x18C(r1)
	  lfs       f0, 0x190(r1)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x194(r1)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x370
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f4, 0xA8(r1)

	.loc_0x370:
	  lfs       f0, -0x62A8(r2)
	  lfs       f1, -0x629C(r2)
	  fsubs     f2, f4, f0
	  lfs       f0, -0x6298(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x398
	  lfs       f1, -0x6388(r2)
	  b         .loc_0x3A4

	.loc_0x398:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x6294(r2)
	  fmuls     f1, f1, f0

	.loc_0x3A4:
	  lwz       r3, 0x710(r31)
	  lwz       r4, 0x78(r3)
	  bl        -0x58128
	  fmr       f1, f29
	  lwz       r3, 0x710(r31)
	  addi      r4, r31, 0x94
	  addi      r5, r31, 0x70
	  bl        -0x58E20
	  li        r0, 0
	  stb       r0, 0x718(r31)
	  stb       r0, 0x724(r31)
	  b         .loc_0x808

	.loc_0x3D4:
	  lbz       r0, 0x718(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x3E8
	  li        r0, 0x1
	  stb       r0, 0x724(r31)

	.loc_0x3E8:
	  lbz       r0, 0x718(r31)
	  lfs       f1, -0x6290(r2)
	  lfs       f0, 0xA0(r31)
	  cmplwi    r0, 0
	  fadds     f28, f1, f0
	  bne-      .loc_0x4CC
	  lfs       f1, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f2, f1, f1
	  lfs       f3, 0xAC(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x63A0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x484
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0xA4(r1)
	  lfs       f4, 0xA4(r1)

	.loc_0x484:
	  lfs       f0, -0x6304(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x4CC
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x4A4
	  lwz       r0, 0x4(r3)
	  b         .loc_0x4A8

	.loc_0x4A4:
	  li        r0, -0x1

	.loc_0x4A8:
	  cmpwi     r0, 0x2
	  beq-      .loc_0x4CC
	  lfs       f28, 0x714(r31)
	  addi      r4, r31, 0x94
	  lwz       r3, 0x710(r31)
	  addi      r5, r31, 0x70
	  fmr       f1, f28
	  bl        -0x58F24
	  b         .loc_0x4D4

	.loc_0x4CC:
	  li        r0, 0x1
	  stb       r0, 0x718(r31)

	.loc_0x4D4:
	  lwz       r3, 0x710(r31)
	  lfs       f1, -0x63A0(r2)
	  lwz       r4, 0x78(r3)
	  bl        -0x5825C
	  lwz       r29, 0x710(r31)
	  lfs       f27, -0x628C(r2)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x63A0(r2)
	  mr        r28, r3
	  lfd       f30, -0x6398(r2)
	  lfd       f31, -0x6390(r2)
	  b         .loc_0x624

	.loc_0x514:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x53C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x558

	.loc_0x53C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x558:
	  mr        r3, r30
	  bl        -0x363F4
	  subi      r0, r3, 0xB
	  cmplwi    r0, 0x1
	  ble-      .loc_0x608
	  lfs       f3, 0x98(r30)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x94(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x9C(r30)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f2, f2, f0
	  fcmpo     cr0, f2, f29
	  ble-      .loc_0x5FC
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f2, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x98(r1)
	  lfs       f2, 0x98(r1)

	.loc_0x5FC:
	  fcmpo     cr0, f2, f27
	  bge-      .loc_0x608
	  fmr       f27, f2

	.loc_0x608:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x624:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x64C
	  li        r0, 0x1
	  b         .loc_0x678

	.loc_0x64C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x674
	  li        r0, 0x1
	  b         .loc_0x678

	.loc_0x674:
	  li        r0, 0

	.loc_0x678:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x514
	  lwz       r4, 0x224(r31)
	  lfs       f0, 0x1E8(r4)
	  fcmpo     cr0, f27, f0
	  bge-      .loc_0x6BC
	  lwz       r0, 0x71C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x6AC
	  lwz       r3, 0x720(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x720(r31)
	  b         .loc_0x724

	.loc_0x6AC:
	  li        r0, 0
	  stw       r0, 0x720(r31)
	  stw       r0, 0x71C(r31)
	  b         .loc_0x724

	.loc_0x6BC:
	  lfs       f0, 0x1F8(r4)
	  fcmpo     cr0, f27, f0
	  bge-      .loc_0x6F8
	  lwz       r0, 0x71C(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x6E4
	  lwz       r3, 0x720(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x720(r31)
	  b         .loc_0x724

	.loc_0x6E4:
	  li        r0, 0
	  stw       r0, 0x720(r31)
	  li        r0, 0x1
	  stw       r0, 0x71C(r31)
	  b         .loc_0x724

	.loc_0x6F8:
	  lwz       r0, 0x71C(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x714
	  lwz       r3, 0x720(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x720(r31)
	  b         .loc_0x724

	.loc_0x714:
	  li        r0, 0
	  stw       r0, 0x720(r31)
	  li        r0, 0x2
	  stw       r0, 0x71C(r31)

	.loc_0x724:
	  lwz       r0, 0x71C(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x73C
	  li        r0, 0x1
	  stb       r0, 0x719(r31)
	  b         .loc_0x808

	.loc_0x73C:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x7C0
	  li        r0, 0x1
	  stb       r0, 0x719(r31)
	  lwz       r3, 0x710(r31)
	  lfsu      f3, 0x5C(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x98(r31)
	  lfs       f2, 0x4(r3)
	  fsubs     f27, f3, f1
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x9C(r31)
	  fsubs     f28, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f27, f27
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF0F34
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x7A0
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x7A0:
	  fmr       f1, f27
	  fmr       f2, f28
	  bl        0x11CE64
	  lwz       r3, 0x710(r31)
	  addi      r4, r31, 0x94
	  addi      r5, r31, 0x70
	  bl        -0x59058
	  b         .loc_0x808

	.loc_0x7C0:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x808
	  li        r30, 0
	  stb       r30, 0x724(r31)
	  lbz       r0, 0x719(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x7F4
	  fmr       f1, f28
	  lwz       r3, 0x710(r31)
	  addi      r4, r31, 0x94
	  addi      r5, r31, 0x70
	  bl        -0x58844
	  stb       r30, 0x719(r31)

	.loc_0x7F4:
	  fmr       f1, f28
	  lwz       r3, 0x710(r31)
	  addi      r4, r31, 0x94
	  addi      r5, r31, 0x70
	  bl        -0x59264

	.loc_0x808:
	  lwz       r3, 0x18C(r1)
	  lwz       r0, 0x190(r1)
	  stw       r3, 0x758(r31)
	  stw       r0, 0x75C(r31)
	  lwz       r0, 0x194(r1)
	  stw       r0, 0x760(r31)
	  lwz       r0, 0x1EC(r1)
	  lfd       f31, 0x1E0(r1)
	  lfd       f30, 0x1D8(r1)
	  lfd       f29, 0x1D0(r1)
	  lfd       f28, 0x1C8(r1)
	  lfd       f27, 0x1C0(r1)
	  lfd       f26, 0x1B8(r1)
	  lwz       r31, 0x1B4(r1)
	  lwz       r30, 0x1B0(r1)
	  lwz       r29, 0x1AC(r1)
	  lwz       r28, 0x1A8(r1)
	  addi      r1, r1, 0x1E8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FEC44
 * Size:	0005A8
 */
void Navi::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x180(r1)
	  stfd      f31, 0x178(r1)
	  stfd      f30, 0x170(r1)
	  stw       r31, 0x16C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x168(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x164(r1)
	  bl        0x668
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x584
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x30(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  lwz       r3, 0x2F00(r13)
	  addi      r4, r30, 0x94
	  bl        -0x9893C

	.loc_0x5C:
	  lwz       r3, 0x710(r30)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xA0(r30)
	  bl        0x11D02C
	  lfs       f1, 0xA0(r30)
	  bl        0x11CE90
	  lfs       f1, 0x6D4(r30)
	  li        r4, 0x1
	  lfs       f0, 0x94(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x88(r1)
	  stfs      f0, 0xA0(r1)
	  lfs       f1, 0x6D8(r30)
	  lfs       f0, 0x98(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA4(r1)
	  lfs       f1, 0x6DC(r30)
	  lfs       f0, 0x9C(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  lwz       r3, 0xA0(r1)
	  lwz       r0, 0xA4(r1)
	  stw       r3, 0x6F0(r30)
	  stw       r0, 0x6F4(r30)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0x6F8(r30)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x6F0(r30)
	  lfs       f2, 0x6F8(r30)
	  bl        -0x96E24
	  lfs       f0, -0x6388(r2)
	  li        r4, 0x1
	  fadds     f0, f0, f1
	  stfs      f0, 0x6F4(r30)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x6F0(r30)
	  lfs       f2, 0x6F8(r30)
	  bl        -0x96B70
	  addi      r29, r3, 0
	  addi      r3, r1, 0xD4
	  bl        -0xC0F98
	  lfs       f1, 0x6F0(r30)
	  lfs       f0, 0x94(r30)
	  lfs       f3, 0x6F4(r30)
	  lfs       f2, 0x98(r30)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x6F8(r30)
	  lfs       f1, 0x9C(r30)
	  fsubs     f2, f3, f2
	  stfs      f0, 0xC8(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0xCC(r1)
	  stfs      f0, 0xD0(r1)
	  lfs       f1, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  lfs       f2, 0xD0(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF1168
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x198
	  lfs       f0, 0xC8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xCC(r1)
	  lfs       f0, 0xD0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xD0(r1)

	.loc_0x198:
	  lfs       f1, -0x2B6C(r13)
	  cmplwi    r29, 0
	  lfs       f0, -0x2B68(r13)
	  stfs      f1, 0xBC(r1)
	  stfs      f0, 0xC0(r1)
	  lfs       f0, -0x2B64(r13)
	  stfs      f0, 0xC4(r1)
	  beq-      .loc_0x224
	  lwz       r3, 0x18(r29)
	  lwz       r0, 0x1C(r29)
	  stw       r3, 0xBC(r1)
	  stw       r0, 0xC0(r1)
	  lwz       r0, 0x20(r29)
	  stw       r0, 0xC4(r1)
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  lfs       f2, 0xC4(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF11F4
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x224
	  lfs       f0, 0xBC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xC4(r1)

	.loc_0x224:
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xB4(r1)
	  lwz       r0, 0xBC(r1)
	  lwz       r3, 0xC0(r1)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xC4(r1)
	  stw       r3, 0xB4(r1)
	  lfs       f6, 0xC8(r1)
	  stw       r0, 0xB8(r1)
	  lfs       f0, 0xB8(r1)
	  lfs       f2, 0xCC(r1)
	  fmuls     f4, f0, f6
	  lfs       f5, 0xB4(r1)
	  lfs       f3, 0xD0(r1)
	  fmuls     f0, f0, f2
	  lfs       f7, 0xB0(r1)
	  fmuls     f1, f5, f3
	  fmuls     f3, f7, f3
	  fmuls     f2, f7, f2
	  fsubs     f0, f1, f0
	  fmuls     f1, f5, f6
	  fsubs     f3, f4, f3
	  stfs      f0, 0xB0(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0xB4(r1)
	  stfs      f0, 0xB8(r1)
	  lfs       f1, 0xB0(r1)
	  lfs       f0, 0xB4(r1)
	  lfs       f2, 0xB8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF12B4
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2E4
	  lfs       f0, 0xB0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0xB4(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xB4(r1)
	  lfs       f0, 0xB8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xB8(r1)

	.loc_0x2E4:
	  lwz       r0, 0xB0(r1)
	  lwz       r3, 0xB4(r1)
	  stw       r0, 0xC8(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r3, 0xCC(r1)
	  lfs       f6, 0xBC(r1)
	  stw       r0, 0xD0(r1)
	  lfs       f0, 0xD0(r1)
	  lfs       f31, 0xC0(r1)
	  lfs       f5, 0xCC(r1)
	  fmuls     f4, f0, f6
	  lfs       f30, 0xC4(r1)
	  fmuls     f0, f0, f31
	  lfs       f2, 0xC8(r1)
	  fmuls     f1, f5, f30
	  fmuls     f3, f2, f30
	  fmuls     f2, f2, f31
	  fsubs     f0, f1, f0
	  fmuls     f1, f5, f6
	  fsubs     f3, f4, f3
	  stfs      f0, 0xC8(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0xCC(r1)
	  stfs      f0, 0xD0(r1)
	  lfs       f1, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  lfs       f2, 0xD0(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xF1368
	  lfs       f0, -0x63A0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x398
	  lfs       f0, 0xC8(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xCC(r1)
	  lfs       f0, 0xD0(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xD0(r1)

	.loc_0x398:
	  lfs       f0, 0xB0(r1)
	  lfs       f1, 0xBC(r1)
	  stfs      f0, 0xD4(r1)
	  lfs       f0, 0xC8(r1)
	  lfs       f2, 0xB4(r1)
	  stfs      f2, 0xE4(r1)
	  lfs       f2, 0xB8(r1)
	  stfs      f2, 0xF4(r1)
	  stfs      f1, 0xD8(r1)
	  stfs      f31, 0xE8(r1)
	  stfs      f30, 0xF8(r1)
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0xCC(r1)
	  stfs      f0, 0xEC(r1)
	  lfs       f0, 0xD0(r1)
	  stfs      f0, 0xFC(r1)
	  lwz       r3, 0xD4(r1)
	  lwz       r0, 0xD8(r1)
	  stw       r3, 0x228(r30)
	  stw       r0, 0x22C(r30)
	  lwz       r3, 0xDC(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r3, 0x230(r30)
	  stw       r0, 0x234(r30)
	  lwz       r3, 0xE4(r1)
	  lwz       r0, 0xE8(r1)
	  stw       r3, 0x238(r30)
	  stw       r0, 0x23C(r30)
	  lwz       r3, 0xEC(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r3, 0x240(r30)
	  stw       r0, 0x244(r30)
	  lwz       r3, 0xF4(r1)
	  lwz       r0, 0xF8(r1)
	  stw       r3, 0x248(r30)
	  stw       r0, 0x24C(r30)
	  lwz       r3, 0xFC(r1)
	  lwz       r0, 0x100(r1)
	  stw       r3, 0x250(r30)
	  stw       r0, 0x254(r30)
	  lwz       r3, 0x104(r1)
	  lwz       r0, 0x108(r1)
	  stw       r3, 0x258(r30)
	  stw       r0, 0x25C(r30)
	  lwz       r3, 0x10C(r1)
	  lwz       r0, 0x110(r1)
	  stw       r3, 0x260(r30)
	  stw       r0, 0x264(r30)
	  lfs       f0, 0x6F0(r30)
	  stfs      f0, 0x234(r30)
	  lfs       f0, 0x6F4(r30)
	  stfs      f0, 0x244(r30)
	  lfs       f0, 0x6F8(r30)
	  stfs      f0, 0x254(r30)
	  lwz       r0, 0x310(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x584
	  lwz       r3, 0xADC(r30)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x19
	  beq-      .loc_0x584
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x120
	  addi      r3, r3, 0x1E0
	  bl        -0xC102C
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x120
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x6C4
	  bl        -0xCFF94
	  lwz       r3, 0x2F64(r13)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  bl        -0xCECCC
	  lwz       r3, 0x7F8(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x510
	  lwz       r0, 0x508(r3)
	  stw       r0, 0xAC(r1)
	  b         .loc_0x524

	.loc_0x510:
	  li        r0, 0xFF
	  stb       r0, 0xAC(r1)
	  stb       r0, 0xAD(r1)
	  stb       r0, 0xAE(r1)
	  stb       r0, 0xAF(r1)

	.loc_0x524:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2F60(r13)
	  mr        r29, r3
	  lwz       r0, 0xAC(r1)
	  li        r6, 0
	  lwz       r3, 0x44(r4)
	  mr        r4, r31
	  stw       r0, 0x2C(r3)
	  lwz       r3, 0x2F60(r13)
	  lwz       r5, 0x2E4(r31)
	  bl        -0xCED3C
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r29, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x584:
	  lwz       r0, 0x184(r1)
	  lfd       f31, 0x178(r1)
	  lfd       f30, 0x170(r1)
	  lwz       r31, 0x16C(r1)
	  lwz       r30, 0x168(r1)
	  lwz       r29, 0x164(r1)
	  addi      r1, r1, 0x180
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FF1EC
 * Size:	0000E8
 */
void Navi::demoDraw(Graphics&, Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lfs       f1, -0x6288(r2)
	  lfs       f0, 0x94(r3)
	  lfs       f3, -0x6368(r2)
	  lfs       f2, 0x98(r3)
	  fadds     f0, f1, f0
	  lfs       f4, -0x62CC(r2)
	  lfs       f1, 0x9C(r3)
	  fadds     f2, f3, f2
	  stfs      f0, 0x6A0(r3)
	  fadds     f0, f4, f1
	  stfs      f2, 0x6A4(r3)
	  stfs      f0, 0x6A8(r3)
	  lfs       f2, -0x63A4(r2)
	  lfs       f1, 0x98(r3)
	  lfs       f0, 0x94(r3)
	  fadds     f1, f2, f1
	  stfs      f0, 0x6AC(r3)
	  stfs      f1, 0x6B0(r3)
	  lfs       f0, 0x9C(r3)
	  stfs      f0, 0x6B4(r3)
	  lwz       r3, 0x82C(r3)
	  lwz       r5, 0x2E4(r31)
	  lwz       r3, 0x0(r3)
	  bl        -0xCEDFC
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x7578C
	  lis       r4, 0x616E
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x7465
	  bl        -0x75B78
	  lwz       r5, 0x4(r3)
	  addi      r4, r30, 0x784
	  lwz       r0, 0x8(r3)
	  stw       r5, 0x784(r30)
	  stw       r0, 0x788(r30)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x78C(r30)
	  lwz       r3, 0x774(r30)
	  bl        0x1517C
	  lwz       r3, 0x778(r30)
	  addi      r4, r30, 0x784
	  bl        0x15170
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
 * Address:	800FF2D4
 * Size:	0002D8
 */
void Navi::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stw       r31, 0xB4(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xB0(r1)
	  mr        r30, r3
	  lbz       r0, 0x2E1(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C0
	  lwz       r3, 0xADC(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  lwz       r0, 0x4(r3)
	  b         .loc_0x40

	.loc_0x3C:
	  li        r0, -0x1

	.loc_0x40:
	  cmpwi     r0, 0x7
	  beq-      .loc_0x5C
	  lwz       r3, 0x224(r30)
	  lfs       f0, 0xF8(r3)
	  stfs      f0, 0x7C(r30)
	  stfs      f0, 0x80(r30)
	  stfs      f0, 0x84(r30)

	.loc_0x5C:
	  lwz       r0, 0x158(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x104
	  lwz       r3, 0x114(r30)
	  lwz       r0, 0x118(r30)
	  stw       r3, 0x228(r30)
	  stw       r0, 0x22C(r30)
	  lwz       r3, 0x11C(r30)
	  lwz       r0, 0x120(r30)
	  stw       r3, 0x230(r30)
	  stw       r0, 0x234(r30)
	  lwz       r3, 0x124(r30)
	  lwz       r0, 0x128(r30)
	  stw       r3, 0x238(r30)
	  stw       r0, 0x23C(r30)
	  lwz       r3, 0x12C(r30)
	  lwz       r0, 0x130(r30)
	  stw       r3, 0x240(r30)
	  stw       r0, 0x244(r30)
	  lwz       r3, 0x134(r30)
	  lwz       r0, 0x138(r30)
	  stw       r3, 0x248(r30)
	  stw       r0, 0x24C(r30)
	  lwz       r3, 0x13C(r30)
	  lwz       r0, 0x140(r30)
	  stw       r3, 0x250(r30)
	  stw       r0, 0x254(r30)
	  lwz       r3, 0x144(r30)
	  lwz       r0, 0x148(r30)
	  stw       r3, 0x258(r30)
	  stw       r0, 0x25C(r30)
	  lwz       r3, 0x14C(r30)
	  lwz       r0, 0x150(r30)
	  stw       r3, 0x260(r30)
	  stw       r0, 0x264(r30)
	  lfs       f2, 0x9C(r30)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x234(r30)
	  stfs      f1, 0x244(r30)
	  stfs      f2, 0x254(r30)
	  b         .loc_0x198

	.loc_0x104:
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0xC12F4
	  lwz       r3, 0x228(r30)
	  lwz       r0, 0x22C(r30)
	  stw       r3, 0x114(r30)
	  stw       r0, 0x118(r30)
	  lwz       r3, 0x230(r30)
	  lwz       r0, 0x234(r30)
	  stw       r3, 0x11C(r30)
	  stw       r0, 0x120(r30)
	  lwz       r3, 0x238(r30)
	  lwz       r0, 0x23C(r30)
	  stw       r3, 0x124(r30)
	  stw       r0, 0x128(r30)
	  lwz       r3, 0x240(r30)
	  lwz       r0, 0x244(r30)
	  stw       r3, 0x12C(r30)
	  stw       r0, 0x130(r30)
	  lwz       r3, 0x248(r30)
	  lwz       r0, 0x24C(r30)
	  stw       r3, 0x134(r30)
	  stw       r0, 0x138(r30)
	  lwz       r3, 0x250(r30)
	  lwz       r0, 0x254(r30)
	  stw       r3, 0x13C(r30)
	  stw       r0, 0x140(r30)
	  lwz       r3, 0x258(r30)
	  lwz       r0, 0x25C(r30)
	  stw       r3, 0x144(r30)
	  stw       r0, 0x148(r30)
	  lwz       r3, 0x260(r30)
	  lwz       r0, 0x264(r30)
	  stw       r3, 0x14C(r30)
	  stw       r0, 0x150(r30)

	.loc_0x198:
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x58
	  addi      r3, r3, 0x1E0
	  bl        -0xC13C8
	  addi      r3, r30, 0x834
	  bl        0x20760
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  bl        -0x9771C
	  lwz       r3, 0x82C(r30)
	  addi      r6, r30, 0x838
	  li        r8, 0
	  lwz       r3, 0x0(r3)
	  li        r5, 0
	  lwz       r4, 0x58(r3)
	  cmpwi     r4, 0
	  mtctr     r4
	  ble-      .loc_0x264

	.loc_0x208:
	  lwz       r4, 0x1C(r3)
	  lwzx      r4, r4, r5
	  lwz       r7, 0x0(r4)
	  cmplwi    r7, 0
	  beq-      .loc_0x25C
	  addic.    r4, r4, 0x4
	  beq-      .loc_0x25C
	  lfs       f0, 0x0(r4)
	  fctiwz    f0, f0
	  stfd      f0, 0xA0(r1)
	  lwz       r4, 0xA4(r1)
	  stfd      f0, 0xA8(r1)
	  cmpwi     r4, 0
	  lwz       r9, 0xAC(r1)
	  blt-      .loc_0x250
	  lwz       r4, 0x30(r7)
	  cmpw      r9, r4
	  blt-      .loc_0x25C

	.loc_0x250:
	  lwz       r4, 0x44(r6)
	  cmpwi     r4, 0
	  li        r8, 0x1

	.loc_0x25C:
	  addi      r5, r5, 0x4
	  bdnz+     .loc_0x208

	.loc_0x264:
	  rlwinm.   r0,r8,0,24,31
	  bne-      .loc_0x27C
	  addi      r4, r31, 0
	  addi      r5, r1, 0x58
	  li        r6, 0
	  bl        -0xCA238

	.loc_0x27C:
	  mr        r3, r30
	  bl        0x17BC
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,29,29
	  bne-      .loc_0x2C0
	  lbz       r0, 0x2E0(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0xFC(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C0:
	  lwz       r0, 0xBC(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FF5AC
 * Size:	0001FC
 */
void Navi::renderCircle(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stfd      f31, 0xD8(r1)
	  stfd      f30, 0xD0(r1)
	  stfd      f29, 0xC8(r1)
	  stfd      f28, 0xC0(r1)
	  stfd      f27, 0xB8(r1)
	  stw       r31, 0xB4(r1)
	  mr        r31, r3
	  stw       r30, 0xB0(r1)
	  stw       r29, 0xAC(r1)
	  stw       r28, 0xA8(r1)
	  lwz       r0, 0xABC(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x70
	  bge-      .loc_0x98
	  cmpwi     r0, 0
	  bge-      .loc_0x50
	  b         .loc_0x98

	.loc_0x50:
	  lwz       r3, 0x224(r31)
	  lfs       f1, 0xAC0(r31)
	  lfs       f0, 0x98(r3)
	  lfs       f2, 0xA8(r3)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f31, f2, f0
	  b         .loc_0xB4

	.loc_0x70:
	  lwz       r4, 0x224(r31)
	  lfs       f2, 0xAB8(r31)
	  lfs       f1, 0xB8(r4)
	  lfs       f0, 0x98(r4)
	  fdivs     f1, f2, f1
	  lfs       f3, 0xA8(r4)
	  fsubs     f0, f0, f3
	  fmuls     f0, f1, f0
	  fadds     f31, f3, f0
	  b         .loc_0xB4

	.loc_0x98:
	  lwz       r3, 0x224(r31)
	  lfs       f1, 0xAC0(r31)
	  lfs       f0, 0x98(r3)
	  lfs       f2, 0xA8(r3)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f31, f2, f0

	.loc_0xB4:
	  stfs      f31, 0xAC8(r31)
	  lbz       r0, 0x30B8(r13)
	  extsb.    r0, r0
	  bne-      .loc_0xD4
	  lfs       f0, -0x63A0(r2)
	  li        r0, 0x1
	  stb       r0, 0x30B8(r13)
	  stfs      f0, 0x30B4(r13)

	.loc_0xD4:
	  lfs       f2, -0x6284(r2)
	  lfs       f1, 0x30B4(r13)
	  lfs       f0, -0x6280(r2)
	  fadds     f1, f2, f1
	  stfs      f1, 0x30B4(r13)
	  lfs       f1, 0x30B4(r13)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xFC
	  fsubs     f0, f1, f0
	  stfs      f0, 0x30B4(r13)

	.loc_0xFC:
	  lfs       f29, -0x627C(r2)
	  mr        r29, r31
	  lfd       f30, -0x62E8(r2)
	  li        r28, 0
	  lis       r30, 0x4330

	.loc_0x110:
	  xoris     r0, r28, 0x8000
	  lfs       f0, 0x30B4(r13)
	  stw       r0, 0xA4(r1)
	  stw       r30, 0xA0(r1)
	  lfd       f1, 0xA0(r1)
	  fsubs     f1, f1, f30
	  fmuls     f27, f29, f1
	  fadds     f27, f27, f0
	  fmr       f1, f27
	  bl        0x11C474
	  fmuls     f28, f31, f1
	  fmr       f1, f27
	  bl        0x11C5FC
	  lfs       f0, 0x6F0(r31)
	  fmuls     f1, f31, f1
	  li        r4, 0x1
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x6F4(r31)
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x6F8(r31)
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x88(r1)
	  lfs       f3, 0x90(r1)
	  fadds     f0, f0, f1
	  lfs       f2, 0x8C(r1)
	  lfs       f1, -0x2B60(r13)
	  fadds     f3, f3, f28
	  fadds     f1, f2, f1
	  stfs      f0, 0x88(r1)
	  stfs      f1, 0x8C(r1)
	  stfs      f3, 0x90(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x88(r1)
	  lfs       f2, 0x90(r1)
	  bl        -0x97840
	  stfs      f1, 0x8C(r1)
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x18
	  lwz       r3, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  stw       r3, 0x938(r29)
	  stw       r0, 0x93C(r29)
	  lwz       r0, 0x90(r1)
	  stw       r0, 0x940(r29)
	  addi      r29, r29, 0xC
	  blt+      .loc_0x110
	  lwz       r0, 0xE4(r1)
	  lfd       f31, 0xD8(r1)
	  lfd       f30, 0xD0(r1)
	  lfd       f29, 0xC8(r1)
	  lfd       f28, 0xC0(r1)
	  lfd       f27, 0xB8(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  lwz       r29, 0xAC(r1)
	  lwz       r28, 0xA8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FF7A8
 * Size:	000004
 */
void Navi::refresh2d(Graphics&)
{
}

/*
 * --INFO--
 * Address:	800FF7AC
 * Size:	00003C
 */
void Navi::sendMsg(Msg* msg)
{
	mStateMachine->procMsg(this, msg);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void Navi::procDamage(f32)
{
}

/*
 * --INFO--
 * Address:	800FF968
 * Size:	000074
 */
bool Navi::stimulate(Interaction& interaction)
{
	if (interaction.actCommon(this)) {
		return interaction.actNavi(this);
	}

	return false;
}

/*
 * --INFO--
 * Address:	800FF9DC
 * Size:	0000C4
 */
bool InteractGeyzer::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  lbz       r0, 0x2B4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0x30:
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  lwz       r0, 0x4(r3)
	  b         .loc_0x48

	.loc_0x44:
	  li        r0, -0x1

	.loc_0x48:
	  cmpwi     r0, 0x14
	  bne-      .loc_0x58
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0x58:
	  cmpwi     r0, 0x18
	  bne-      .loc_0x68
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0x68:
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x14
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x16D8
	  lwz       r4, 0x8(r30)
	  lwz       r0, 0xC(r30)
	  stw       r4, 0x20(r3)
	  stw       r0, 0x24(r3)
	  lwz       r0, 0x10(r30)
	  stw       r0, 0x28(r3)
	  li        r3, 0x1

	.loc_0xAC:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FFAA0
 * Size:	0000FC
 */
bool InteractBury::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0x320(r4)
	  bl        0x1680
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r3, 0
	  b         .loc_0xE4

	.loc_0x48:
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x13
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7D234
	  lfs       f1, 0x58(r31)
	  mr        r3, r31
	  lfs       f0, 0xC(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  bl        -0x62F8
	  lwz       r4, 0x224(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA3ACC
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xE0
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  addi      r4, r31, 0
	  li        r5, 0x1D
	  lwz       r3, 0x320(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0xE0:
	  li        r3, 0x1

	.loc_0xE4:
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
 * Address:	800FFB9C
 * Size:	000094
 */
bool InteractWind::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0x320(r4)
	  bl        0x1584
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x7C

	.loc_0x48:
	  lwz       r4, 0xC(r30)
	  li        r3, 0x1
	  lwz       r0, 0x10(r30)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x78(r31)
	  lwz       r4, 0xC(r30)
	  lwz       r0, 0x10(r30)
	  stw       r4, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x14(r30)
	  stw       r0, 0xAC(r31)

	.loc_0x7C:
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
 * Address:	800FFC30
 * Size:	000114
 */
bool InteractSuck::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x40
	  li        r3, 0
	  b         .loc_0xFC

	.loc_0x40:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x14C8
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x14BC
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C
	  li        r3, 0
	  b         .loc_0xFC

	.loc_0x7C:
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA3C58
	  lwz       r3, 0x3178(r13)
	  li        r4, 0xF
	  li        r5, 0
	  li        r6, 0
	  bl        0x7D068
	  mr        r3, r31
	  bl        -0x64B4
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xF8
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  addi      r4, r31, 0
	  li        r5, 0x1D
	  lwz       r3, 0x320(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0xF8:
	  li        r3, 0x1

	.loc_0xFC:
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
 * Address:	800FFD44
 * Size:	0001A4
 */
bool InteractAttack::actNavi(Navi* navi)
{
	if (navi->isDamaged()) {
		return false;
	}

	if (!navi->startDamage()) {
		return false;
	}

	rumbleMgr->start(1, 0, nullptr);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r4
	  stw       r30, 0x58(r1)
	  addi      r30, r3, 0
	  lbz       r0, 0x2B4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x18C

	.loc_0x30:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x13C4
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x60
	  li        r0, 0
	  b         .loc_0x94

	.loc_0x60:
	  mr        r3, r31
	  bl        -0x6574
	  li        r0, 0x1
	  stb       r0, 0x2B4(r31)
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x90
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
	  li        r0, 0x1

	.loc_0x94:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0xA4
	  li        r3, 0
	  b         .loc_0x18C

	.loc_0xA4:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7CF50
	  li        r3, 0x13D
	  bl        -0x5AA24
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA3DB0
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x108
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  b         .loc_0x148

	.loc_0x108:
	  addi      r3, r1, 0x44
	  li        r4, 0xA
	  bl        0x1F104
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x124
	  addi      r5, r5, 0x2B8

	.loc_0x124:
	  addi      r3, r1, 0x4C
	  li        r4, 0xA
	  bl        0x1F11C
	  addi      r3, r31, 0x834
	  addi      r4, r1, 0x4C
	  addi      r5, r1, 0x44
	  bl        0x1FBE8
	  li        r0, -0x1
	  stw       r0, 0x7E0(r31)

	.loc_0x148:
	  addi      r3, r1, 0x34
	  li        r4, 0xA
	  bl        0x1F0C4
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x164
	  addi      r5, r5, 0x2B8

	.loc_0x164:
	  addi      r3, r1, 0x3C
	  li        r4, 0xA
	  bl        0x1F0DC
	  addi      r3, r31, 0x834
	  addi      r4, r1, 0x3C
	  addi      r5, r1, 0x34
	  bl        0x1FBA8
	  li        r0, -0x1
	  stw       r0, 0x7E0(r31)
	  li        r3, 0x1

	.loc_0x18C:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800FFEE8
 * Size:	000110
 */
bool InteractPress::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lbz       r0, 0x2B4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  li        r3, 0
	  b         .loc_0xF8

	.loc_0x30:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x1220
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x60
	  li        r3, 0
	  b         .loc_0xF8

	.loc_0x60:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7CDF0
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA3F08
	  lfs       f0, -0x2B5C(r13)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, -0x2B58(r13)
	  stfs      f0, 0xA8(r31)
	  lfs       f0, -0x2B54(r13)
	  stfs      f0, 0xAC(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xD0
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)

	.loc_0xD0:
	  mr        r3, r31
	  bl        -0x6788
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x7
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0xF8:
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
 * Address:	800FFFF8
 * Size:	0001B8
 */
bool InteractSwallow::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r4
	  lwz       r3, 0x320(r4)
	  bl        0x1130
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x40
	  li        r0, 0
	  b         .loc_0x74

	.loc_0x40:
	  mr        r3, r31
	  bl        -0x6808
	  li        r0, 0x1
	  stb       r0, 0x2B4(r31)
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl

	.loc_0x70:
	  li        r0, 0x1

	.loc_0x74:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x84
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0x84:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0x10BC
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB4
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0xB4:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7CC8C
	  lfs       f1, 0x58(r31)
	  li        r3, 0x13D
	  lfs       f0, -0x63A4(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  bl        -0x5ACF8
	  mr        r3, r31
	  bl        -0x68A8
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x10C
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)
	  b         .loc_0x14C

	.loc_0x10C:
	  addi      r3, r1, 0x44
	  li        r4, 0xA
	  bl        0x1EE4C
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x128
	  addi      r5, r5, 0x2B8

	.loc_0x128:
	  addi      r3, r1, 0x4C
	  li        r4, 0xA
	  bl        0x1EE64
	  addi      r3, r31, 0x834
	  addi      r4, r1, 0x4C
	  addi      r5, r1, 0x44
	  bl        0x1F930
	  li        r0, -0x1
	  stw       r0, 0x7E0(r31)

	.loc_0x14C:
	  addi      r3, r1, 0x34
	  li        r4, 0xA
	  bl        0x1EE0C
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x168
	  addi      r5, r5, 0x2B8

	.loc_0x168:
	  addi      r3, r1, 0x3C
	  li        r4, 0xA
	  bl        0x1EE24
	  addi      r3, r31, 0x834
	  addi      r4, r1, 0x3C
	  addi      r5, r1, 0x34
	  bl        0x1F8F0
	  li        r0, -0x1
	  stw       r0, 0x7E0(r31)
	  addi      r3, r31, 0x1E0
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA4120
	  li        r3, 0x1

	.loc_0x1A4:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801001B0
 * Size:	000118
 */
bool InteractBomb::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0x320(r4)
	  bl        0xF70
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x100

	.loc_0x48:
	  lwz       r3, 0xADC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  lwz       r0, 0x4(r3)
	  b         .loc_0x60

	.loc_0x5C:
	  li        r0, -0x1

	.loc_0x60:
	  cmpwi     r0, 0x21
	  bne-      .loc_0x70
	  li        r3, 0
	  b         .loc_0x100

	.loc_0x70:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7CB18
	  li        r3, 0x13D
	  bl        -0x5AE5C
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA41E8
	  mr        r3, r31
	  bl        -0x6A30
	  lfs       f0, -0x6368(r2)
	  stfs      f0, 0x704(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xE0
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)

	.loc_0xE0:
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x8
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0x100:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801002C8
 * Size:	000080
 */
bool Navi::orimaDamaged()
{
	int state = mStateMachine->getCurrID(this);
	return isDamaged() || state == NAVISTATE_Flick || state == NAVISTATE_Pressed || state == NAVISTATE_Stuck || state == NAVISTATE_Bury;
}

/*
 * --INFO--
 * Address:	80100348
 * Size:	000144
 */
bool InteractFlick::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  lwz       r4, 0xADC(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x30
	  lwz       r0, 0x4(r4)
	  b         .loc_0x34

	.loc_0x30:
	  li        r0, -0x1

	.loc_0x34:
	  cmpwi     r0, 0x21
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x12C

	.loc_0x44:
	  lwz       r3, 0x320(r31)
	  mr        r4, r31
	  bl        0xDAC
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  li        r3, 0
	  b         .loc_0x12C

	.loc_0x74:
	  lfs       f1, 0xC(r30)
	  lfs       f0, -0x63A0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xA4
	  lwz       r3, 0x3178(r13)
	  li        r4, 0xA
	  li        r5, 0
	  li        r6, 0
	  bl        0x7C96C
	  mr        r3, r31
	  bl        -0x6BB0
	  b         .loc_0xB8

	.loc_0xA4:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0xA
	  li        r5, 0
	  li        r6, 0
	  bl        0x7C94C

	.loc_0xB8:
	  li        r3, 0x13D
	  bl        -0x5B028
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0xC(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA43B4
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x704(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x10C
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)

	.loc_0x10C:
	  lwz       r3, 0x320(r31)
	  addi      r4, r31, 0
	  li        r5, 0x8
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0x12C:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8010048C
 * Size:	0000F0
 */
bool InteractBubble::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0x320(r4)
	  bl        0xC94
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r3, 0
	  b         .loc_0xD8

	.loc_0x48:
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA4480
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7C840
	  li        r3, 0x13E
	  bl        -0x5B134
	  mr        r3, r31
	  bl        -0x6CE4
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xB0
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)

	.loc_0xB0:
	  lfs       f0, -0x6314(r2)
	  addi      r4, r31, 0
	  li        r5, 0x8
	  stfs      f0, 0x704(r31)
	  lwz       r3, 0x320(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0xD8:
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
 * Address:	8010057C
 * Size:	0000F0
 */
bool InteractFire::actNavi(Navi*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0x320(r4)
	  bl        0xBA4
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x48
	  li        r3, 0
	  b         .loc_0xD8

	.loc_0x48:
	  lfs       f1, 0x58(r31)
	  addi      r3, r31, 0x1E0
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r31)
	  lwz       r4, 0x224(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f2, 0x3C8(r4)
	  bl        -0xA4570
	  mr        r3, r31
	  bl        -0x6DB8
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x7C748
	  li        r3, 0x13E
	  bl        -0x5B22C
	  lfs       f1, 0x58(r31)
	  lfs       f0, -0x6388(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xB0
	  lis       r3, 0x1
	  subi      r0, r3, 0x7FFB
	  sth       r0, 0x30C8(r13)

	.loc_0xB0:
	  lfs       f0, -0x6314(r2)
	  addi      r4, r31, 0
	  li        r5, 0x8
	  stfs      f0, 0x704(r31)
	  lwz       r3, 0x320(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0xD8:
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
 * Address:	8010066C
 * Size:	0000C0
 */
void Navi::dump()
{
	if (Piki::directDumpMode) {
		PRINT("-- navi : mode = %d\n", mStateMachine->getCurrID(this));
		PRINT(" onground : %s isFlying %s\n", isCreatureFlag(CF_IsOnGround) ? "true" : "false",
		      isCreatureFlag(CF_IsFlying) ? "true" : "false");
		PRINT(" isAlive=%s isVisible=%s isBuried=%s\n", isAlive() ? "true" : "false", isVisible() ? "true" : "false",
		      isBuried() ? "true" : "false");
		PRINT(" neutralTime = %.2f\n", _738);
	} else {
		PRINT("-- navi : mode = %d\n", mStateMachine->getCurrID(this));
		PRINT(" onground : %s isFlying %s\n", isCreatureFlag(CF_IsOnGround) ? "true" : "false",
		      isCreatureFlag(CF_IsFlying) ? "true" : "false");
		PRINT(" isAlive=%s isVisible=%s isBuried=%s\n", isAlive() ? "true" : "false", isVisible() ? "true" : "false",
		      isBuried() ? "true" : "false");
		PRINT(" neutralTime = %.2f\n", _738);
	}
}

/*
 * --INFO--
 * Address:	8010072C
 * Size:	000234
 */
void Navi::throwPiki(Piki*, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  stfd      f30, 0x120(r1)
	  stfd      f29, 0x118(r1)
	  stfd      f28, 0x110(r1)
	  stw       r31, 0x10C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x108(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x104(r1)
	  addi      r29, r3, 0
	  lwz       r3, 0x4F8(r4)
	  li        r4, 0
	  bl        -0x3B424
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x2
	  li        r5, 0
	  li        r6, 0
	  bl        0x7C5CC
	  lfs       f2, 0x94(r29)
	  lfs       f0, -0x2B50(r13)
	  lfs       f1, -0x2B4C(r13)
	  fadds     f2, f2, f0
	  lfs       f0, -0x2B48(r13)
	  stfs      f2, 0xAC(r1)
	  lfs       f2, 0xAC(r1)
	  stfs      f2, 0xDC(r1)
	  lfs       f2, 0x98(r29)
	  fadds     f1, f2, f1
	  stfs      f1, 0xE0(r1)
	  lfs       f1, 0x9C(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE4(r1)
	  lwz       r3, 0xDC(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r3, 0x94(r30)
	  stw       r0, 0x98(r30)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x9C(r30)
	  lfs       f1, 0x8(r31)
	  lfs       f0, 0x9C(r30)
	  lfs       f3, 0x0(r31)
	  fsubs     f2, f1, f0
	  lfs       f1, 0x94(r30)
	  lfs       f0, -0x63A0(r2)
	  fsubs     f1, f3, f1
	  fmuls     f3, f2, f2
	  fmuls     f4, f1, f1
	  fadds     f31, f4, f3
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0xE8
	  fsqrte    f0, f31
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f31, 0xA8(r1)

	.loc_0xE8:
	  bl        0x11B1E4
	  fmr       f30, f1
	  bl        -0xC8294
	  stfs      f1, 0xA0(r30)
	  lwz       r4, 0x224(r29)
	  lhz       r0, 0x510(r30)
	  lfs       f1, -0x6384(r2)
	  lfs       f0, 0x1B8(r4)
	  cmplwi    r0, 0x2
	  fmuls     f4, f1, f0
	  bne-      .loc_0x11C
	  lfs       f1, 0x1A8(r4)
	  b         .loc_0x13C

	.loc_0x11C:
	  lfs       f1, 0x800(r29)
	  lfs       f0, 0x158(r4)
	  lfs       f2, 0x198(r4)
	  fdivs     f1, f1, f0
	  lfs       f0, 0x188(r4)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f1, f2, f0

	.loc_0x13C:
	  lfs       f0, -0x6314(r2)
	  fdivs     f3, f1, f4
	  lwz       r3, 0x2F80(r13)
	  lfs       f2, -0x6384(r2)
	  lfs       f1, 0x30(r3)
	  fmuls     f0, f0, f4
	  fmuls     f2, f2, f1
	  fmr       f1, f30
	  fdivs     f28, f31, f0
	  fmuls     f0, f4, f2
	  fadds     f29, f3, f0
	  bl        0x11B2C0
	  fmuls     f31, f28, f1
	  fmr       f1, f30
	  bl        0x11B448
	  fmuls     f0, f28, f1
	  stfs      f0, 0x70(r30)
	  stfs      f29, 0x74(r30)
	  stfs      f31, 0x78(r30)
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0x70(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x80(r1)
	  stfs      f0, 0xB8(r1)
	  lfs       f1, 0x74(r30)
	  lfs       f0, 0x74(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0xBC(r1)
	  lfs       f1, 0x78(r30)
	  lfs       f0, 0x78(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lwz       r3, 0xB8(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r3, 0x70(r30)
	  stw       r0, 0x74(r30)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0x78(r30)
	  lwz       r3, 0x70(r30)
	  lwz       r0, 0x74(r30)
	  stw       r3, 0xA4(r30)
	  stw       r0, 0xA8(r30)
	  lwz       r0, 0x78(r30)
	  stw       r0, 0xAC(r30)
	  lfs       f0, -0x2B44(r13)
	  stfs      f0, 0xBC(r30)
	  lfs       f0, -0x2B40(r13)
	  stfs      f0, 0xC0(r30)
	  lfs       f0, -0x2B3C(r13)
	  stfs      f0, 0xC4(r30)
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lfd       f30, 0x120(r1)
	  lfd       f29, 0x118(r1)
	  lfd       f28, 0x110(r1)
	  lwz       r31, 0x10C(r1)
	  lwz       r30, 0x108(r1)
	  lwz       r29, 0x104(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001DC
 */
void Navi::throwLocus(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80100960
 * Size:	00005C
 */
void Navi::swapMotion(PaniMotionInfo& motion1, PaniMotionInfo& motion2)
{
	u32 badCompiler[4];

	f32* frame1 = &mNaviAnimMgr.mUpperAnimator.mAnimationCounter;
	f32* frame2 = &mNaviAnimMgr.mLowerAnimator.mAnimationCounter;
	f32 val1    = *frame1;
	f32 val2    = *frame2;
	mNaviAnimMgr.startMotion(motion1, motion2);
	*frame1 = val1;
	*frame2 = val2;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002D4
 */
void Navi::renderParabola(Graphics&, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801009BC
 * Size:	000014
 */
void Navi::finishLook()
{
	mLookAtPosPtr = nullptr;
	_2F0          = 10;
}

/*
 * --INFO--
 * Address:	801009D0
 * Size:	000340
 */
void Navi::updateLook()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stfd      f29, 0x58(r1)
	  stfd      f28, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r3
	  lwz       r3, 0x2EC(r3)
	  lfs       f29, -0x62A8(r2)
	  cmplwi    r3, 0
	  beq-      .loc_0xEC
	  lfs       f3, 0x8(r3)
	  lfs       f1, 0x9C(r31)
	  lfs       f2, 0x0(r3)
	  lfs       f0, 0x94(r31)
	  fsubs     f28, f3, f1
	  lfs       f1, 0x4(r3)
	  fsubs     f30, f2, f0
	  lfs       f0, 0x98(r31)
	  fmr       f2, f28
	  fsubs     f31, f1, f0
	  fmr       f1, f30
	  bl        0x11AFC8
	  fmuls     f3, f30, f30
	  lfs       f0, -0x63A0(r2)
	  fmuls     f2, f28, f28
	  fmr       f30, f1
	  fadds     f4, f3, f2
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xD8
	  fsqrte    f1, f4
	  lfd       f3, -0x6398(r2)
	  lfd       f2, -0x6390(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x28(r1)
	  lfs       f4, 0x28(r1)

	.loc_0xD8:
	  fmr       f2, f4
	  fmr       f1, f31
	  bl        0x11AF48
	  fmr       f31, f1
	  b         .loc_0x170

	.loc_0xEC:
	  lfs       f28, -0x6360(r2)
	  lfs       f1, -0x63A0(r2)
	  lfs       f2, 0x2F4(r31)
	  bl        -0xC8514
	  fmuls     f0, f1, f28
	  lfs       f1, 0x2F4(r31)
	  fadds     f1, f1, f0
	  bl        -0xC8550
	  stfs      f1, 0x2F4(r31)
	  lfs       f1, -0x63A0(r2)
	  lfs       f2, 0x2F8(r31)
	  bl        -0xC8534
	  fmuls     f0, f1, f28
	  lfs       f1, 0x2F8(r31)
	  fadds     f1, f1, f0
	  bl        -0xC8570
	  stfs      f1, 0x2F8(r31)
	  lfs       f1, 0x2F4(r31)
	  lfs       f0, -0x637C(r2)
	  fabs      f1, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x31C
	  lfs       f1, 0x2F8(r31)
	  fabs      f1, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x31C
	  li        r0, 0
	  stw       r0, 0x2EC(r31)
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x2F8(r31)
	  stfs      f0, 0x2F4(r31)
	  stb       r0, 0x2F0(r31)
	  b         .loc_0x31C

	.loc_0x170:
	  lfs       f1, 0x2F4(r31)
	  lfs       f0, 0xA0(r31)
	  fadds     f1, f1, f0
	  bl        -0xC85C4
	  fmr       f2, f1
	  lfs       f0, 0xA0(r31)
	  fsubs     f1, f30, f0
	  fmr       f28, f2
	  bl        -0xC85D8
	  lfs       f0, -0x6290(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1CC
	  lfs       f2, 0x2F4(r31)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x1BC
	  fsubs     f0, f2, f1
	  lfs       f1, -0x6280(r2)
	  fsubs     f1, f1, f0
	  b         .loc_0x200

	.loc_0x1BC:
	  fmr       f1, f30
	  fmr       f2, f28
	  bl        -0xC85E0
	  b         .loc_0x200

	.loc_0x1CC:
	  lfs       f2, 0x2F4(r31)
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1F4
	  fsubs     f1, f2, f1
	  lfs       f2, -0x6280(r2)
	  lfs       f0, -0x62C4(r2)
	  fsubs     f1, f2, f1
	  fmuls     f1, f1, f0
	  b         .loc_0x200

	.loc_0x1F4:
	  fmr       f1, f30
	  fmr       f2, f28
	  bl        -0xC8618

	.loc_0x200:
	  fabs      f2, f1
	  lfs       f0, -0x6278(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x214
	  lfs       f1, -0x63A0(r2)

	.loc_0x214:
	  fmuls     f0, f1, f29
	  lfs       f1, 0x2F4(r31)
	  fadds     f1, f1, f0
	  bl        -0xC8668
	  stfs      f1, 0x2F4(r31)
	  lfs       f2, 0x2F4(r31)
	  lfs       f1, -0x62A4(r2)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x24C
	  lfs       f0, -0x6290(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x24C
	  stfs      f1, 0x2F4(r31)
	  b         .loc_0x26C

	.loc_0x24C:
	  lfs       f1, -0x6274(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x26C
	  lfs       f0, -0x6290(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x26C
	  stfs      f1, 0x2F4(r31)

	.loc_0x26C:
	  fmr       f1, f31
	  lfs       f2, 0x2F8(r31)
	  bl        -0xC8690
	  fabs      f2, f1
	  lfs       f0, -0x6278(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x28C
	  lfs       f1, -0x63A0(r2)

	.loc_0x28C:
	  fmuls     f0, f1, f29
	  lfs       f1, 0x2F8(r31)
	  fadds     f1, f1, f0
	  bl        -0xC86E0
	  stfs      f1, 0x2F8(r31)
	  lfs       f2, 0x2F8(r31)
	  lfs       f1, -0x6270(r2)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x2C4
	  lfs       f0, -0x6290(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x2C4
	  stfs      f1, 0x2F8(r31)
	  b         .loc_0x2E4

	.loc_0x2C4:
	  lfs       f1, -0x626C(r2)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x2E4
	  lfs       f0, -0x6290(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2E4
	  stfs      f1, 0x2F8(r31)

	.loc_0x2E4:
	  lbz       r3, 0x2F0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x31C
	  subi      r0, r3, 0x1
	  stb       r0, 0x2F0(r31)
	  lbz       r0, 0x2F0(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x31C
	  li        r0, 0
	  stw       r0, 0x2EC(r31)
	  lfs       f0, -0x63A0(r2)
	  stfs      f0, 0x2F8(r31)
	  stfs      f0, 0x2F4(r31)
	  stb       r0, 0x2F0(r31)

	.loc_0x31C:
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lfd       f29, 0x58(r1)
	  lfd       f28, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80100D10
 * Size:	00037C
 */
void Navi::updateHeadMatrix()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F0(r1)
	  stfd      f31, 0x1E8(r1)
	  stfd      f30, 0x1E0(r1)
	  stfd      f29, 0x1D8(r1)
	  stw       r31, 0x1D4(r1)
	  stw       r30, 0x1D0(r1)
	  mr        r30, r3
	  lwz       r0, 0x2EC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x3C
	  lbz       r0, 0x2F0(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x358

	.loc_0x3C:
	  mr        r3, r30
	  bl        -0x380
	  lwz       r3, 0x82C(r30)
	  li        r4, 0x2
	  lwz       r3, 0x0(r3)
	  bl        -0xCBD78
	  lwz       r5, 0x0(r3)
	  addi      r4, r1, 0x14C
	  lwz       r0, 0x4(r3)
	  stw       r5, 0x18C(r1)
	  stw       r0, 0x190(r1)
	  lwz       r5, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  stw       r5, 0x194(r1)
	  stw       r0, 0x198(r1)
	  lwz       r5, 0x10(r3)
	  lwz       r0, 0x14(r3)
	  stw       r5, 0x19C(r1)
	  stw       r0, 0x1A0(r1)
	  lwz       r5, 0x18(r3)
	  lwz       r0, 0x1C(r3)
	  stw       r5, 0x1A4(r1)
	  stw       r0, 0x1A8(r1)
	  lwz       r5, 0x20(r3)
	  lwz       r0, 0x24(r3)
	  stw       r5, 0x1AC(r1)
	  stw       r0, 0x1B0(r1)
	  lwz       r5, 0x28(r3)
	  lwz       r0, 0x2C(r3)
	  stw       r5, 0x1B4(r1)
	  stw       r0, 0x1B8(r1)
	  lwz       r5, 0x30(r3)
	  lwz       r0, 0x34(r3)
	  stw       r5, 0x1BC(r1)
	  stw       r0, 0x1C0(r1)
	  lwz       r5, 0x38(r3)
	  lwz       r0, 0x3C(r3)
	  addi      r3, r1, 0x18C
	  stw       r5, 0x1C4(r1)
	  stw       r0, 0x1C8(r1)
	  bl        -0xC29B0
	  addi      r3, r1, 0xCC
	  bl        -0xC3038
	  lfs       f0, 0x2F8(r30)
	  fneg      f1, f0
	  bl        0x11AEE8
	  lfs       f0, 0x2F8(r30)
	  fmr       f29, f1
	  fneg      f1, f0
	  bl        0x11AD44
	  fmr       f30, f1
	  lfs       f1, 0x2F4(r30)
	  bl        0x11AECC
	  fmr       f31, f1
	  lfs       f1, 0x2F4(r30)
	  bl        0x11AD2C
	  fneg      f2, f29
	  stfs      f30, 0xCC(r1)
	  lfs       f0, -0x63A0(r2)
	  fmuls     f5, f1, f29
	  fmuls     f4, f1, f30
	  stfs      f2, 0xD0(r1)
	  fneg      f3, f31
	  fmuls     f2, f31, f29
	  addi      r3, r1, 0x18C
	  stfs      f0, 0xD4(r1)
	  fmuls     f0, f31, f30
	  stfs      f5, 0xDC(r1)
	  addi      r4, r1, 0xCC
	  stfs      f4, 0xE0(r1)
	  addi      r5, r1, 0x10C
	  stfs      f3, 0xE4(r1)
	  stfs      f2, 0xEC(r1)
	  stfs      f0, 0xF0(r1)
	  stfs      f1, 0xF4(r1)
	  bl        -0xC2DA4
	  lwz       r3, 0x82C(r30)
	  li        r4, 0x2
	  lwz       r3, 0x0(r3)
	  bl        -0xCBEA0
	  lwz       r4, 0x10C(r1)
	  li        r31, 0x3
	  lwz       r0, 0x110(r1)
	  stw       r4, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lwz       r4, 0x114(r1)
	  lwz       r0, 0x118(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r4, 0x11C(r1)
	  lwz       r0, 0x120(r1)
	  stw       r4, 0x10(r3)
	  stw       r0, 0x14(r3)
	  lwz       r4, 0x124(r1)
	  lwz       r0, 0x128(r1)
	  stw       r4, 0x18(r3)
	  stw       r0, 0x1C(r3)
	  lwz       r4, 0x12C(r1)
	  lwz       r0, 0x130(r1)
	  stw       r4, 0x20(r3)
	  stw       r0, 0x24(r3)
	  lwz       r4, 0x134(r1)
	  lwz       r0, 0x138(r1)
	  stw       r4, 0x28(r3)
	  stw       r0, 0x2C(r3)
	  lwz       r4, 0x13C(r1)
	  lwz       r0, 0x140(r1)
	  stw       r4, 0x30(r3)
	  stw       r0, 0x34(r3)
	  lwz       r4, 0x144(r1)
	  lwz       r0, 0x148(r1)
	  stw       r4, 0x38(r3)
	  stw       r0, 0x3C(r3)

	.loc_0x200:
	  lwz       r3, 0x82C(r30)
	  mr        r4, r31
	  lwz       r3, 0x0(r3)
	  bl        -0xCBF34
	  lwz       r6, 0x0(r3)
	  addi      r4, r1, 0x8C
	  lwz       r0, 0x4(r3)
	  addi      r5, r1, 0x4C
	  stw       r6, 0x8C(r1)
	  stw       r0, 0x90(r1)
	  lwz       r6, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  stw       r6, 0x94(r1)
	  stw       r0, 0x98(r1)
	  lwz       r6, 0x10(r3)
	  lwz       r0, 0x14(r3)
	  stw       r6, 0x9C(r1)
	  stw       r0, 0xA0(r1)
	  lwz       r6, 0x18(r3)
	  lwz       r0, 0x1C(r3)
	  stw       r6, 0xA4(r1)
	  stw       r0, 0xA8(r1)
	  lwz       r6, 0x20(r3)
	  lwz       r0, 0x24(r3)
	  stw       r6, 0xAC(r1)
	  stw       r0, 0xB0(r1)
	  lwz       r6, 0x28(r3)
	  lwz       r0, 0x2C(r3)
	  stw       r6, 0xB4(r1)
	  stw       r0, 0xB8(r1)
	  lwz       r6, 0x30(r3)
	  lwz       r0, 0x34(r3)
	  stw       r6, 0xBC(r1)
	  stw       r0, 0xC0(r1)
	  lwz       r6, 0x38(r3)
	  lwz       r0, 0x3C(r3)
	  addi      r3, r1, 0x14C
	  stw       r6, 0xC4(r1)
	  stw       r0, 0xC8(r1)
	  bl        -0xC2ED8
	  addi      r3, r1, 0x10C
	  addi      r4, r1, 0x4C
	  addi      r5, r1, 0xC
	  bl        -0xC2EE8
	  lwz       r3, 0x82C(r30)
	  mr        r4, r31
	  lwz       r3, 0x0(r3)
	  bl        -0xCBFE4
	  lwz       r4, 0xC(r1)
	  addi      r31, r31, 0x1
	  lwz       r0, 0x10(r1)
	  cmpwi     r31, 0x6
	  stw       r4, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lwz       r4, 0x14(r1)
	  lwz       r0, 0x18(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r4, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r4, 0x10(r3)
	  stw       r0, 0x14(r3)
	  lwz       r4, 0x24(r1)
	  lwz       r0, 0x28(r1)
	  stw       r4, 0x18(r3)
	  stw       r0, 0x1C(r3)
	  lwz       r4, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r4, 0x20(r3)
	  stw       r0, 0x24(r3)
	  lwz       r4, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r4, 0x28(r3)
	  stw       r0, 0x2C(r3)
	  lwz       r4, 0x3C(r1)
	  lwz       r0, 0x40(r1)
	  stw       r4, 0x30(r3)
	  stw       r0, 0x34(r3)
	  lwz       r4, 0x44(r1)
	  lwz       r0, 0x48(r1)
	  stw       r4, 0x38(r3)
	  stw       r0, 0x3C(r3)
	  ble+      .loc_0x200
	  lwz       r3, 0x82C(r30)
	  lwz       r3, 0x0(r3)
	  bl        -0xCBA70

	.loc_0x358:
	  lwz       r0, 0x1F4(r1)
	  lfd       f31, 0x1E8(r1)
	  lfd       f30, 0x1E0(r1)
	  lfd       f29, 0x1D8(r1)
	  lwz       r31, 0x1D4(r1)
	  lwz       r30, 0x1D0(r1)
	  addi      r1, r1, 0x1F0
	  mtlr      r0
	  blr
	*/
}
