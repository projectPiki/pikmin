#include "AIConstant.h"
#include "BombItem.h"
#include "CPlate.h"
#include "DebugLog.h"
#include "DoorItem.h"
#include "EffectMgr.h"
#include "FlowController.h"
#include "GameCoreSection.h"
#include "gameflow.h"
#include "Generator.h"
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
#include "Stickers.h"
#include "sysNew.h"
#include "teki.h"
#include "UfoItem.h"
#include "UtEffect.h"
#include "WorkObject.h"
#include "zen/Math.h"

bool DelayPikiBirth = true;

static f32 controllerLen;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

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
	return (gameflow.mDemoFlags & 0x40) != 0;
}

/*
 * --INFO--
 * Address:	800F8530
 * Size:	000014
 */
void Navi::incPlatePiki()
{
	mPlateMgr->mPlatePikiCount++;
}

/*
 * --INFO--
 * Address:	800F8544
 * Size:	000014
 */
void Navi::decPlatePiki()
{
	mPlateMgr->mPlatePikiCount--;
}

/*
 * --INFO--
 * Address:	800F8558
 * Size:	00000C
 */
int Navi::getPlatePikis()
{
	return mPlateMgr->mPlatePikiCount;
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
				Vector3f slotPos  = piki->mNavi->mPlateMgr->mSlotList[slotID].mOffsetFromCenter + piki->mNavi->mPlateMgr->mPlateCenter;
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
	           && !playerState->mDemoFlags.isFlag(DEMOFLAG_OlimarLowHealth)) {
		playerState->mDemoFlags.setFlagOnly(DEMOFLAG_OlimarLowHealth);
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
	f32 randIdx     = gsys->getRand(1.0f);
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
		    && !playerState->mDemoFlags.isFlag(DEMOFLAG_OlimarLowHealth)) {
			playerState->mDemoFlags.setFlagOnly(DEMOFLAG_OlimarLowHealth);
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
	mHealth = static_cast<NaviProp*>(props)->mNaviProps.mHealth();

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
	mSize       = 20.0f;

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

	_72C          = 0;
	_730          = 0;
	mCurrKeyCount = 0;
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
	enableFixPos();
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
	mIsCursorVisible    = 0;
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
	mNaviLightPosition.set(0.0f, 0.0f, 0.0f);
	_724 = 0;

	f32 dist = (NAVI_PROP._38C() + NAVI_PROP._39C()) * 0.5f;
	mCursorPosition.set(dist * sinf(mFaceDirection), 0.0f, dist * cosf(mFaceDirection));
	mCursorNaviDist       = mCursorPosition.length();
	mCursorTargetPosition = mCursorPosition;
	mCursorWorldPos.set(0.0f, 0.0f, 0.0f);
	_7DC           = mFaceDirection;
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

	f32 angle      = zen::Abs(mFaceDirection - _7DC);
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
			UtEffectMgr::cast(KandoEffect::Bubbles, castParm);
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
	_7DC = mFaceDirection;
	Creature::update();

	mapMgr->updatePos(mPosition.x, mPosition.z);

	Vector3f dayEndSep = mDayEndPosition - mPosition;
	if (dayEndSep.length() > 35.0f && mFloorTri) {
		Vector3f parmPos(mPosition.x, mPosition.y + 1.0f, mPosition.z);

		Vector3f parmVel(0.01667f * mVelocity.x, 2.0f, 0.01667f * mVelocity.z);
		int effAttr = MapCode::getAttribute(mFloorTri);
		if (effAttr >= ATTR_Soil && effAttr <= ATTR_Tree) {
			EffectParm parm(parmPos, parmVel);
			UtEffectMgr::cast(effAttr + KandoEffect::SmokeOffset, parm);
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
		int attr = ATTR_Soil;
		if (mFloorTri) {
			attr = MapCode::getAttribute(mFloorTri);
		}
		u16 soundType;
		switch (attr) {
		case ATTR_Soil:
			soundType = 1;
			break;
		case ATTR_Rock:
			soundType = 3;
			break;
		case ATTR_Grass:
			soundType = 0;
			break;
		case ATTR_Tree:
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
	Vector3f unused = mCursorWorldPos - mPosition;
	u32 badCompiler[4];

	Iterator iterPiki(pikiMgr);
	CI_LOOP(iterPiki)
	{
		Piki* piki = static_cast<Piki*>(*iterPiki);
		if (!piki->isAlive()) {
			continue;
		}

		Vector3f sep = piki->mPosition - mCursorWorldPos;
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
					static_cast<PikiEmotionState*>(piki->getCurrState())->mRapCnt = 0;
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
			Vector3f sproutSep   = maybeSprout->mPosition - mCursorWorldPos;
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
		Vector3f tekiSep = teki->mPosition - mCursorWorldPos;
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
		Vector3f pikiSep = piki->mPosition - mCursorWorldPos;
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
		Vector3f tekiSep = teki->mPosition - mCursorWorldPos;
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
 *
 * @brief Releases the Pikmin from the Navi's control and organizes them by color.
 *
 * This function iterates through the Pikmin managed by the Navi, filters out those that are not in a releasable state,
 * and then organizes the remaining Pikmin by their color. It calculates the center of mass and size for each color group,
 * adjusts their positions to avoid overlap, and finally changes their mode to FreeMode.
 *
 * @dor, and bomb-carrying Pikmin are treated as aetails
 * - Pikmin that are dead, dying, or in certain states are not considered for release.
 * - Pikmin are grouped by their col separate group.
 * - The center of mass and size for each color group are calculated.
 * - The positions of the color groups are adjusted to avoid overlap with the Navi and with each other.
 * - The mode of each Pikmin is changed to FreeMode, and their positions are updated based on the calculated center of mass and size.
 *
 * @note
 * - The function assumes a maximum of 200 Pikmin can be managed at a time.
 * - The function uses several constants and enumerations such as PikiColorCount, PikiMode, and PIKISTATE_*.
 * - The function modifies the Pikmin's active action to ActFree and initializes their boid behavior.
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
		if (flowCont.mNaviOnMap == 1 && pikiList[i]->mPlayerId == -1) {
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
	if (gameflow.mDemoFlags & 0x40) {
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
				if (distFromShip < 30.0f && pellet->mCarrierCounter != 0) {
					continue;
				}

				Vector3f pelNaviSep = pellet->mPosition - mPosition;
				f32 distFromNavi    = std::sqrtf(pelNaviSep.x * pelNaviSep.x + pelNaviSep.z * pelNaviSep.z) - pellet->getBottomRadius();
				if (distFromNavi <= 20.0f) {
					int idx = PelletMgr::getUfoIndexFromID(pellet->mConfig->mModelId.mId);
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
			_7D0               = angDist(roundAng(atan2f(sproutSep.x, sproutSep.z)), mFaceDirection) / 10.0f;
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
			_7D0             = angDist(roundAng(atan2f(pikiSep.x, pikiSep.z)), mFaceDirection) / 10.0f;

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
	Creature* collider = event.mCollider;
	if (collider != _2FC) {
		switch (collider->mObjType) {
		case OBJTYPE_WorkObject:
			Bridge* bridge = static_cast<Bridge*>(collider);
			if (bridge->isBridge()) {
				if (bridge->mDoUseJointSegments && getCollidePlatformCreature() == bridge) {
					Vector3f normal(getCollidePlatformNormal());
					if ((normal.DP(bridge->getBridgeZVec()) >= -0.8f)) {
						return;
					}
				} else {
					return;
				}
			}
		case OBJTYPE_SluiceSoft:
		case OBJTYPE_SluiceHard:
		case OBJTYPE_SluiceBomb:
		case OBJTYPE_SluiceBombHard:
		case OBJTYPE_Pellet:
			if (_2FC) {
				_300 = 0.0f;
			}
			_2FC = collider;
			_300 += gsys->getFrameTime();
			if (_300 > 0.5f) {
				letPikiWork();
				_300 = 0.0f;
			}
			break;
		}
	}

	MsgCollide msg(event);
	sendMsg(&msg);

	int state = mStateMachine->getCurrID(this);
	if (collider->isVisible()) {
		switch (collider->mObjType) {
		case OBJTYPE_Key:
			if (collider->mGenerator) {
				PRINT("key->generator->id = %x\n", collider->mGenerator->mGeneratorName.mId);
			}
			Event event(2, collider->getGeneratorID());
			informEvent(event);
			mCurrKeyCount++;
			collider->kill(false);
			break;
		case OBJTYPE_Gate:
			if (mCurrKeyCount > 0 && static_cast<DoorItem*>(collider)->mStateId == DoorState::Active) {
				mCurrKeyCount--;
				static_cast<DoorItem*>(collider)->disappear();
			}
			break;
		case OBJTYPE_Door:
			if (mCurrKeyCount > 0 && state != NAVISTATE_Clear) {
				DoorItem* door = static_cast<DoorItem*>(collider);
				sprintf(flowCont.mStagePath2, "%s", door->mDestinationStagePath);
				Vector3f naviDoorSep = mPosition - door->mPosition;
				naviDoorSep.normalise();
				Vector3f faceDir(sinf(door->mFaceDirection), 0.0f, cosf(door->mFaceDirection));
				if (faceDir.DP(naviDoorSep) >= cosf(HALF_PI)) {
					mStateMachine->transit(this, NAVISTATE_Clear);
				}
			}
			break;
		}
	}
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
void Navi::reviseController(Vector3f& stickPos)
{
	f32 newMag = stickPos.length();
	f32 theta  = roundAng(atan2f(stickPos.x, stickPos.z));

	// bin angle in amounts set by navi parameter
	f32 binWidth    = (PI / 180.0f) * NAVI_PROP.mShakePreventionAngle();
	f32 binnedAngle = binWidth * int((theta + binWidth * 0.5f) / binWidth);

	// calculate amount to boost stick magnitude by
	f32 boostFactor = (binnedAngle - (int)(binnedAngle / QUARTER_PI) * QUARTER_PI);
	theta           = sinf(QUARTER_PI - boostFactor);
	boostFactor     = sinf(boostFactor);
	boostFactor += theta;

	// boost stick magnitude
	f32 len = (sinf(QUARTER_PI) / boostFactor);
	newMag *= (1.0f / len);

	// make 'close enough' good enough
	if (newMag >= NAVI_PROP.mClampStickToMaxThreshold()) {
		newMag = 1.0f;
	}

	// enforce dead zone
	if (newMag < NAVI_PROP.mNeutralStickThreshold()) {
		newMag = 0.0f;
	}

	controllerLen = len;

	stickPos.set(newMag * sinf(binnedAngle), 0.0f, newMag * cosf(binnedAngle));

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	800FDAF0
 * Size:	0008FC
 */
void Navi::makeVelocity(bool p1)
{

	_738 += gsys->getFrameTime();

	if (mKontroller->keyDown(KBBTN_B) || mKontroller->keyDown(KBBTN_A) || mKontroller->keyDown(KBBTN_X) || mKontroller->keyDown(KBBTN_Z)) {
		_738 = 0.0f;
	}

	NVector3f stickVec(mKontroller->getMainStickX(), 0.0f, -mKontroller->getMainStickY());
	if (stickVec.x >= 1.0f) {
		stickVec.x = 1.0f;
	} else if (stickVec.x <= -1.0f) {
		stickVec.x = -1.0f;
	}

	if (stickVec.z >= 1.0f) {
		stickVec.z = 1.0f;
	} else if (stickVec.z <= -1.0f) {
		stickVec.z = -1.0f;
	}

	reviseController(stickVec);

	_740                    = _74C;
	_74C                    = stickVec;
	f32 angle               = NMathF::atan2(mNaviCamera->mViewXAxis.z, mNaviCamera->mViewXAxis.x);
	NAxisAngle4f& axisAngle = NAxisAngle4f(NVector3f(0.0f, 1.0f, 0.0f), angle);
	NTransform3D& transform = NTransform3D();
	transform.inputAxisAngle(axisAngle);

	if (!p1) {
		mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	}

	transform.transform(stickVec);

	if (!p1) {
		Stickers stuckList(this);
		int stickCount = stuckList.getCount();
		f32 drag       = 1.0f;
		if (stickCount > 0) {
			drag -= stickCount * 0.08f;
			if (drag < 0.1f) {
				drag = 0.1f;
			}
		}

		if (mPlateMgr->canNaviRunFast()) {
			mTargetVelocity = (stickVec * NAVI_PROP._DC()) * drag;
		} else {
			mTargetVelocity = (stickVec * NAVI_PROP._CC()) * drag;
		}

		if (mFloorTri) {
			// ?? this does nothing.
			f32 speed    = mTargetVelocity.length();
			Vector3f vec = mTargetVelocity - mTargetVelocity.DP(mFloorTri->mTriangle.mNormal) * mFloorTri->mTriangle.mNormal;
			vec.normalise();
			vec = vec * speed;
		}
	}

	transform.transform(_74C);

	f32 stickMag = stickVec.length();

	Vector3f stickVec2(stickVec);

	stickVec2.normalise();
	stickVec2 = stickVec2 * NAVI_PROP._3AC();

	f32 step           = gsys->getFrameTime();
	Vector3f targetPos = stickVec2 * step + mCursorPosition;
	f32 targetDist     = targetPos.length();
	if (targetDist >= NAVI_PROP._39C()) {
		Vector3f vec(targetPos);
		vec.normalise();
		stickVec2 = stickVec2 - vec.DP(stickVec2) * vec;
		targetPos = stickVec2 * step + mCursorPosition;
	}

	mCursorPosition       = targetPos;
	mCursorNaviDist       = targetPos.length();
	mCursorTargetPosition = targetPos;

	if (!(stickMag <= NAVI_PROP.mNeutralStickThreshold())) {
		_738 = 0.0f;
	}

	bool check = false;
	if (_738 >= NAVI_PROP._33C()) {
		check = true;
	}

	if ((check || (!check && stickMag > NAVI_PROP.mNeutralStickThreshold())) && stickMag <= NAVI_PROP._36C()) {
		mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		Vector3f cursorPos(mCursorPosition);
		mFaceDirection += 0.2f * angDist(roundAng(atan2f(cursorPos.x, cursorPos.z)), mFaceDirection);
		mFaceDirection = roundAng(mFaceDirection);
		mRotation.set(0.0f, mFaceDirection, 0.0f);
		setCreatureFlag(CF_Unk11);
	} else {
		resetCreatureFlag(CF_Unk11);
	}

	stickVec.set(0.0f, 0.0f, 0.0f);
	makeCStick(false);
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
void Navi::makeCStick(bool p1)
{
	f32 angle               = NMathF::atan2(mNaviCamera->mViewXAxis.z, mNaviCamera->mViewXAxis.x);
	NAxisAngle4f& axisAngle = NAxisAngle4f(NVector3f(0.0f, 1.0f, 0.0f), angle);

	NTransform3D& transform = NTransform3D();
	transform.inputAxisAngle(axisAngle);

	NVector3f subStick(mKontroller->getSubStickX(), 0.0f, -mKontroller->getSubStickY());

	if (p1) {
		subStick.set(0.0f, 0.0f, 0.0f);
	}

	reviseController(subStick);

	if (mPlateMgr) {
		if (getCurrState()->getID() != NAVISTATE_DemoSunset && getCurrState()->getID() != NAVISTATE_Dead) {
			if (mPlateMgr->mTotalSlotCount > 0) {
				seMgr->playNaviSound(74.0f * subStick.x, 74.0f * subStick.z);
			} else {
				seMgr->playNaviSound(0, 0);
			}
		}
	}

	subStick.scale(1.0f);
	transform.transform(subStick);

	_764.set(0.0f, 0.0f, 0.0f);

	if (subStick.length() > 0.05f) {
		_738       = 0.0f;
		_764       = subStick;
		f32 angle1 = atan2f(subStick.x, subStick.z);
		f32 angle2 = mPlateMgr->mDirectionAngle;
		Vector3f dir1(sinf(angle1), 0.0f, cosf(angle1));
		Vector3f dir2(sinf(angle2), 0.0f, cosf(angle2));

		f32 newAngle;
		if (dir1.DP(dir2) > cosf(2.0943952f)) {
			newAngle = angDist(angle1, angle2) * 0.4f + angle2;
		} else {
			newAngle = angle1;
		}

		newAngle = roundAng(newAngle);
		_714     = newAngle;

		f32 dist = (subStick.length() - 0.05f) / (1.0f - 0.05f);
		if (dist >= 0.9f) {
			dist = 1.0f;
		} else {
			dist = 0.6f * (dist / 0.9f);
		}

		mPlateMgr->refresh(getPlatePikis(), dist);

		mPlateMgr->setPos(mPosition, newAngle, mVelocity);
		_718 = 0;
		_724 = 0;
	} else {
		if (!_718) {
			_724 = 1;
		}

		f32 backDir = mFaceDirection + PI;
		if (!_718 && mTargetVelocity.length() < 50.0f && mStateMachine->getCurrID(this) != NAVISTATE_ThrowWait) {
			backDir = _714;
			mPlateMgr->setPos(mPosition, backDir, mVelocity);
		} else {
			_718 = 1;
		}

		mPlateMgr->refresh(getPlatePikis(), 0.0f);
		Iterator iter(mPlateMgr);
		f32 minDist = 12800.0f;

		CI_LOOP(iter)
		{
			Creature* c = *iter;
			Piki* piki  = static_cast<Piki*>(c);
			int state   = piki->getState();
			if (state == PIKISTATE_Hanged || state == PIKISTATE_GoHang) {
				continue;
			}

			Vector3f sep = c->mPosition - mPosition;
			f32 dist     = sep.length();
			if (dist < minDist) {
				minDist = dist;
			}
		}

		if (minDist < NAVI_PROP._1DC()) {
			if (_71C == 0) {
				_720++;
			} else {
				_720 = 0;
				_71C = 0;
			}
		} else if (minDist < NAVI_PROP._1EC()) {
			if (_71C == 1) {
				_720++;
			} else {
				_720 = 0;
				_71C = 1;
			}
		} else {
			if (_71C == 2) {
				_720++;
			} else {
				_720 = 0;
				_71C = 2;
			}
		}

		if (_71C == 0) {
			_719 = 1;
		} else if (_71C == 1) {
			_719              = 1;
			Vector3f squadSep = mPlateMgr->mPlateOffset - mPosition;
			squadSep.normalise();
			mPlateMgr->setPosGray(mPosition, atan2f(squadSep.x, squadSep.z), mVelocity);
		} else if (_71C == 2) {
			_724 = 0;
			if (_719) {
				mPlateMgr->rearrangeSlot(mPosition, backDir, mVelocity);
				_719 = 0;
			}
			mPlateMgr->setPos(mPosition, backDir, mVelocity);
		}
	}

	_758 = subStick;

	u32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	800FEC44
 * Size:	0005A8
 */
void Navi::refresh(Graphics& gfx)
{
	draw(gfx);
	if (!movieMode()) {
		if (gsys->mToggleColls) {
			mapMgr->showCollisions(mPosition);
		}

		Matrix4f viewMtx;
		mPlateMgr->render(gfx);

		// these aren't used for anything in the DLL either, lol.
		f32 unusedVal  = sinf(mFaceDirection);
		f32 unusedVal2 = cosf(mFaceDirection);
		f32 badCompiler;

		mCursorWorldPos   = mCursorPosition + mPosition;
		mCursorWorldPos.y = mapMgr->getMinY(mCursorWorldPos.x, mCursorWorldPos.z, true) + 1.0f;

		CollTriInfo* cursorTri = mapMgr->getCurrTri(mCursorWorldPos.x, mCursorWorldPos.z, true);

		Matrix4f orientMatrix;
		orientMatrix.makeIdentity();

		Vector3f cursorDir = mCursorWorldPos - mPosition;
		cursorDir.normalise();

		Vector3f surfaceNormal(0.0f, 1.0f, 0.0f);
		if (cursorTri) {
			surfaceNormal = cursorTri->mTriangle.mNormal;
			surfaceNormal.normalise();
		}

		Vector3f rightVector;
		rightVector = surfaceNormal;
		rightVector.CP(cursorDir);
		rightVector.normalise();

		cursorDir = rightVector;
		cursorDir.CP(surfaceNormal);
		cursorDir.normalise();

		orientMatrix.mMtx[0][0] = rightVector.x;
		orientMatrix.mMtx[1][0] = rightVector.y;
		orientMatrix.mMtx[2][0] = rightVector.z;

		orientMatrix.mMtx[0][1] = surfaceNormal.x;
		orientMatrix.mMtx[1][1] = surfaceNormal.y;
		orientMatrix.mMtx[2][1] = surfaceNormal.z;

		orientMatrix.mMtx[0][2] = cursorDir.x;
		orientMatrix.mMtx[1][2] = cursorDir.y;
		orientMatrix.mMtx[2][2] = cursorDir.z;

		mWorldMtx = orientMatrix;
		mWorldMtx.setTranslation(mCursorWorldPos);

		if (mIsCursorVisible && getCurrState()->getID() != NAVISTATE_DemoSunset) {
			gfx.useMatrix(Matrix4f::ident, 0);
			gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, viewMtx);

			gfx.useMatrix(viewMtx, 0);

			mNaviDynMats.updateContext();
			GlobalShape::cursorShape->drawshape(gfx, *gfx.mCamera, nullptr);

			Colour markerColour;
			if (mNextThrowPiki) {
				markerColour = mNextThrowPiki->mCurrentColour;
			} else {
				markerColour.set(255, 255, 255, 255);
			}

			bool isLighting                                    = gfx.setLighting(false, nullptr);
			GlobalShape::markerShape2->mMaterialList->Colour() = markerColour;
			GlobalShape::markerShape2->drawshape(gfx, *gfx.mCamera, nullptr);
			gfx.setLighting(isLighting, nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	800FF1EC
 * Size:	0000E8
 */
void Navi::demoDraw(Graphics& gfx, Matrix4f* mtx)
{
	mShadowCaster.mSourcePosition.set(mPosition.x + 75.0f, mPosition.y + 100.0f, mPosition.z + 25.0f);
	mShadowCaster.mTargetPosition.set(mPosition.x, mPosition.y + 10.0f, mPosition.z);
	mNaviShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	mCollInfo->updateInfo(gfx, false);
	mNaviLightPosition = mCollInfo->getSphere('ante')->mCentre;
	mNaviLightEfx->updatePos(mNaviLightPosition);
	mNaviLightGlowEfx->updatePos(mNaviLightPosition);
}

/*
 * --INFO--
 * Address:	800FF2D4
 * Size:	0002D8
 */
void Navi::draw(Graphics& gfx)
{
	if (isPellet()) {
		return;
	}

	if (mStateMachine->getCurrID(this) != NAVISTATE_Pressed) {
		f32 scale = NAVI_PROP.mDisplayScale();
		mScale.set(scale, scale, scale);
	}

	if (mRope) {
		mWorldMtx = mConstrainedMoveMtx;
		mWorldMtx.setTranslation(mPosition.x, mPosition.y, mPosition.z);
	} else {
		mWorldMtx.makeSRT(mScale, mRotation, mPosition);
		mConstrainedMoveMtx = mWorldMtx;
	}

	gfx.useMatrix(Matrix4f::ident, 0);

	u32 badCompiler2;
	Matrix4f viewMtx;
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, viewMtx);

	mNaviAnimMgr.updateContext();
	mapMgr->getLight(mPosition.x, mPosition.z);

	bool hasAnimError = false;
	for (int i = 0; i < mNaviShapeObject->mShape->mJointCount; i++) {
		if (mNaviShapeObject->mShape->mAnimOverrides[i]->mData && &mNaviShapeObject->mShape->mAnimOverrides[i]->mCurrentFrame) {
			int frame1 = mNaviShapeObject->mShape->mAnimOverrides[i]->mCurrentFrame;
			int frame2 = mNaviShapeObject->mShape->mAnimOverrides[i]->mCurrentFrame;
			if (frame1 < 0 || frame2 >= mNaviShapeObject->mShape->mAnimOverrides[i]->mData->mNumFrames) {
				PRINT(" NAVI -------- error : joint is %d\n", i);
				PRINT(" motion is %s\n", mNaviAnimMgr.getUpperAnimator().getCurrentMotionName());
				hasAnimError = true;
			}
		}
	}

	if (!hasAnimError) {
		mNaviShapeObject->mShape->updateAnim(gfx, viewMtx, nullptr);
	}

	updateHeadMatrix();
	if (!(gameflow.mDemoFlags & 4) && !_2E0) {
		demoDraw(gfx, nullptr);
	}

	u32 badCompiler[7];
}

/*
 * --INFO--
 * Address:	800FF5AC
 * Size:	0001FC
 */
void Navi::renderCircle(Graphics& gfx)
{
	f32 rad;
	switch (_ABC) {
	case 0:
		rad = NAVI_PROP._9C() + _AC0 * (NAVI_PROP._8C() - NAVI_PROP._9C());
		break;
	case 1:
		f32 val = (_AB8 / NAVI_PROP._AC());
		rad     = NAVI_PROP._9C() + (NAVI_PROP._8C() - NAVI_PROP._9C()) * val;
		break;
	default:
		rad = NAVI_PROP._9C() + _AC0 * (NAVI_PROP._8C() - NAVI_PROP._9C());
		break;
	}

	_AC8 = rad;

	static f32 ang = 0.0f;
	ang            = ang + 0.03f;
	if (ang > TAU) {
		ang -= TAU;
	}

	for (int i = 0; i < 24; i++) {
		f32 angle = i * (TAU / 24.0f);
		angle += ang;
		Vector3f dir(rad * sinf(angle), 0.0f, rad * cosf(angle));
		Vector3f pos(mCursorWorldPos);
		pos     = pos + dir;
		pos.y   = mapMgr->getMinY(pos.x, pos.z, true);
		_938[i] = pos;
	}

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
bool InteractGeyzer::actNavi(Navi* navi)
{
	if (navi->isDamaged()) {
		return false;
	}

	int state = navi->mStateMachine->getCurrID(navi);
	if (state == NAVISTATE_Geyzer) {
		return false;
	}
	if (state == NAVISTATE_Pellet) {
		return false;
	}

	navi->mStateMachine->transit(navi, NAVISTATE_Geyzer);
	NaviGeyzerState* geyzer = static_cast<NaviGeyzerState*>(navi->mStateMachine->getNaviState(navi));
	geyzer->_20             = _08;
	return true;
}

/*
 * --INFO--
 * Address:	800FFAA0
 * Size:	0000FC
 */
bool InteractBury::actNavi(Navi* navi)
{
	NaviState* state = navi->mStateMachine->getNaviState(navi);
	if (state->invincible(navi)) {
		return false;
	}

	navi->mStateMachine->transit(navi, NAVISTATE_Bury);
	rumbleMgr->start(1, 0, nullptr);
	navi->mHealth -= _0C;
	navi->startDamageEffect();
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		navi->mStateMachine->transit(navi, NAVISTATE_Dead);
	}

	return true;
}

/*
 * --INFO--
 * Address:	800FFB9C
 * Size:	000094
 */
bool InteractWind::actNavi(Navi* navi)
{
	NaviState* state = navi->mStateMachine->getNaviState(navi);
	if (state->invincible(navi)) {
		return false;
	}

	navi->mVelocity       = mVelocity;
	navi->mTargetVelocity = mVelocity;
	return true;
}

/*
 * --INFO--
 * Address:	800FFC30
 * Size:	000114
 */
bool InteractSuck::actNavi(Navi* navi)
{
	PRINT("actNavi");
	if (!navi->isAlive()) {
		return false;
	}

	if (!navi->mStateMachine) {
		ERROR("navi->stateM = 0!\n");
	}
	if (!navi->mStateMachine->getNaviState(navi)) {
		ERROR("no navi state:suck!\n");
	}

	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	PRINT("invicible check false");
	navi->mHealth -= mDamage;

	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	rumbleMgr->start(15, 0, nullptr);
	navi->startDamageEffect();
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		navi->mStateMachine->transit(navi, NAVISTATE_Dead);
	}

	return true;
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
	SeSystem::playPlayerSe(SE_DAMAGED);
	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		PRINT("ATTACK DEAD ******\n");
	} else {
		navi->startMotion(PaniMotionInfo(PIKIANIM_Damage, navi), PaniMotionInfo(PIKIANIM_Damage));
	}

	PRINT("navi got attack interaction!\n");
	navi->startMotion(PaniMotionInfo(PIKIANIM_Damage, navi), PaniMotionInfo(PIKIANIM_Damage));
	return true;
}

/*
 * --INFO--
 * Address:	800FFEE8
 * Size:	000110
 */
bool InteractPress::actNavi(Navi* navi)
{
	if (navi->isDamaged()) {
		return false;
	}

	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	rumbleMgr->start(1, 0, nullptr);
	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	navi->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		PRINT("PRESS DEAD ******\n");
	}

	navi->startDamageEffect();
	navi->mStateMachine->transit(navi, NAVISTATE_Pressed);
	return true;
}

/*
 * --INFO--
 * Address:	800FFFF8
 * Size:	0001B8
 */
bool InteractSwallow::actNavi(Navi* navi)
{
	PRINT("NAVI GOT SWALLOW INTERACTION !\n");
	if (!navi->startDamage()) {
		return false;
	}

	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	rumbleMgr->start(1, 0, nullptr);
	navi->mHealth -= 10.0f;
	SeSystem::playPlayerSe(SE_DAMAGED);
	navi->startDamageEffect();
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		PRINT("SWALLOW DEAD ******\n");
	} else {
		navi->startMotion(PaniMotionInfo(PIKIANIM_Damage, navi), PaniMotionInfo(PIKIANIM_Damage));
	}
	navi->startMotion(PaniMotionInfo(PIKIANIM_Damage, navi), PaniMotionInfo(PIKIANIM_Damage));

	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	return true;
}

/*
 * --INFO--
 * Address:	801001B0
 * Size:	000118
 */
bool InteractBomb::actNavi(Navi* navi)
{
	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	if (navi->mStateMachine->getCurrID(navi) == NAVISTATE_PikiZero) {
		return false;
	}

	rumbleMgr->start(1, 0, nullptr);
	SeSystem::playPlayerSe(SE_DAMAGED);
	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	navi->startDamageEffect();
	navi->_704 = 100.0f;
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		PRINT("BOMB DEAD ******\n");
	}
	navi->mStateMachine->transit(navi, NAVISTATE_Flick);

	u32 badCompiler[2];
	return true;
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
bool InteractFlick::actNavi(Navi* navi)
{
	if (navi->mStateMachine->getCurrID(navi) == NAVISTATE_PikiZero) {
		return false;
	}

	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	if (mDamage > 0.0f) {
		rumbleMgr->start(10, 0, nullptr);
		navi->startDamageEffect();
	} else {
		rumbleMgr->start(10, 0, nullptr);
	}

	SeSystem::playPlayerSe(SE_DAMAGED);
	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	navi->_704 = mIntensity;
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
		PRINT("FLICK DEAD ******\n");
	}

	navi->mStateMachine->transit(navi, NAVISTATE_Flick);

	u32 badCompiler[2];
	return true;
}

/*
 * --INFO--
 * Address:	8010048C
 * Size:	0000F0
 */
bool InteractBubble::actNavi(Navi* navi)
{
	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	rumbleMgr->start(1, 0, nullptr);
	SeSystem::playPlayerSe(SE_FIRED);
	navi->startDamageEffect();
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
	}
	navi->_704 = 2.0f;
	navi->mStateMachine->transit(navi, NAVISTATE_Flick);
	return true;
}

/*
 * --INFO--
 * Address:	8010057C
 * Size:	0000F0
 */
bool InteractFire::actNavi(Navi* navi)
{
	if (navi->mStateMachine->getNaviState(navi)->invincible(navi)) {
		return false;
	}

	navi->mHealth -= mDamage;
	navi->mLifeGauge.updValue(navi->mHealth, C_NAVI_PROP(navi).mHealth());
	navi->startDamageEffect();
	rumbleMgr->start(1, 0, nullptr);
	SeSystem::playPlayerSe(SE_FIRED);
	if (navi->mHealth <= 1.0f) {
		GameCoreSection::startPause(COREPAUSE_Unk1 | COREPAUSE_Unk3 | COREPAUSE_Unk16);
	}
	navi->_704 = 2.0f;
	navi->mStateMachine->transit(navi, NAVISTATE_Flick);
	return true;
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
void Navi::throwPiki(Piki* piki, Vector3f& pos)
{
	f32 unused = mFaceDirection + PI;
	piki->mActiveAction->abandon(nullptr);
	rumbleMgr->start(2, 0, nullptr);
	piki->mPosition      = mPosition + Vector3f(0.0f, 10.0f, 0.0f);
	Vector3f throwDir    = pos - piki->mPosition;
	f32 throwDist        = speedy_sqrtf(throwDir.x * throwDir.x + throwDir.z * throwDir.z);
	f32 throwAngle       = atan2f(throwDir.x, throwDir.z);
	piki->mFaceDirection = roundAng(throwAngle);

	f32 halfTime = 0.5f * NAVI_PROP._1AC();
	f32 height;
	if (piki->mColor == Yellow) {
		height = NAVI_PROP._19C();
	} else {
		height = NAVI_PROP._18C() + (_800 / NAVI_PROP._14C()) * (NAVI_PROP._17C() - NAVI_PROP._18C());
	}

	f32 vSpeed = AIConstant::_instance->mConstants.mGravity() * 0.5f * halfTime + (height / halfTime);
	f32 hSpeed = throwDist / (2.0f * halfTime);

	piki->mVelocity.set(hSpeed * sinf(throwAngle), vSpeed, hSpeed * cosf(throwAngle));

	piki->mVelocity       = piki->mVelocity + mVelocity;
	piki->mTargetVelocity = piki->mVelocity;
	piki->mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
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
	f32 angle1;
	f32 angle2;
	f32 val = 0.05f;
	if (mLookAtPosPtr) {
		Vector3f lookDir = *mLookAtPosPtr - mPosition;
		angle2           = atan2f(lookDir.x, lookDir.z);
		f32 dist         = std::sqrtf(lookDir.x * lookDir.x + lookDir.z * lookDir.z);
		angle1           = atan2f(lookDir.y, dist);
	} else {
		f32 factor = 0.2f;
		f32 tmp1   = angDist(0.0f, _2F4);
		_2F4       = roundAng(tmp1 * factor + _2F4);
		f32 tmp2   = angDist(0.0f, _2F8);
		_2F8       = roundAng(tmp2 * factor + _2F8);

		if (zen::Abs(_2F4) < 0.1f && zen::Abs(_2F8) < 0.1f) {
			forceFinishLook();
		}
		return;
	}

	f32 angle3 = roundAng(_2F4 + mFaceDirection);
	f32 angle4 = roundAng(angle2 - mFaceDirection);

	f32 angle5;
	if (angle4 < PI) {
		if (_2F4 > PI) {
			angle5 = TAU - (_2F4 - angle4);
		} else {
			angle5 = angDist(angle2, angle3);
		}
	} else if (_2F4 <= PI) {
		angle5 = (TAU - (_2F4 - angle4));
		angle5 *= -1.0f;
	} else {
		angle5 = angDist(angle2, angle3);
	}

	if (zen::Abs(angle5) < PI / 20.0f) {
		angle5 = 0.0f;
	}

	_2F4 = roundAng(angle5 * val + _2F4);

	if (_2F4 > 2.0f * PI / 3.0f && _2F4 < PI) {
		_2F4 = 2.0f * PI / 3.0f;
	} else if (_2F4 < 4.0f * PI / 3.0f && _2F4 >= PI) {
		_2F4 = 4.0f * PI / 3.0f;
	}

	f32 angle6 = angDist(angle1, _2F8);
	if (zen::Abs(angle6) < PI / 20.0f) {
		angle6 = 0.0f;
	}

	_2F8 = roundAng(angle6 * val + _2F8);

	if (_2F8 > PI / 3.0f && _2F8 < PI) {
		_2F8 = PI / 3.0f;
	} else if (_2F8 < 5.2359877f && _2F8 >= PI) {
		_2F8 = 5.2359877f; // 5 pi / 3 but not quite
	}

	if (_2F0) {
		_2F0--;
		if (_2F0 == 0) {
			forceFinishLook();
		}
	}
}

/*
 * --INFO--
 * Address:	80100D10
 * Size:	00037C
 */
void Navi::updateHeadMatrix()
{
	if (!mLookAtPosPtr && _2F0 == 0) {
		return;
	}

	updateLook();

	Matrix4f animMtx = mNaviShapeObject->mShape->getAnimMatrix(2);
	Matrix4f mtx1;
	Matrix4f mtx2;
	animMtx.inverse(&mtx1);
	Matrix4f mtx3;
	mtx3.makeIdentity();

	f32 sin8 = sinf(-_2F8);
	f32 cos8 = cosf(-_2F8);
	f32 sin4 = sinf(_2F4);
	f32 cos4 = cosf(_2F4);

	mtx3.mMtx[0][0] = cos8;
	mtx3.mMtx[0][1] = -sin8;
	mtx3.mMtx[0][2] = 0.0f;

	mtx3.mMtx[1][0] = cos4 * sin8;
	mtx3.mMtx[1][1] = cos4 * cos8;
	mtx3.mMtx[1][2] = -sin4;

	mtx3.mMtx[2][0] = sin4 * sin8;
	mtx3.mMtx[2][1] = sin4 * cos8;
	mtx3.mMtx[2][2] = cos4;

	animMtx.multiplyTo(mtx3, mtx2);

	mNaviShapeObject->mShape->getAnimMatrix(2) = mtx2;

	for (int i = 3; i <= 6; i++) {
		Matrix4f tempAnim = mNaviShapeObject->mShape->getAnimMatrix(i);
		Matrix4f tmp1;
		Matrix4f tmp2;
		mtx1.multiplyTo(tempAnim, tmp1);
		mtx2.multiplyTo(tmp1, tmp2);
		mNaviShapeObject->mShape->getAnimMatrix(i) = tmp2;
	}

	mNaviShapeObject->mShape->calcWeightedMatrices();
}
