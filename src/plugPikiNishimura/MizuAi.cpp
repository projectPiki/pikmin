#include "Mizu.h"
#include "EffectMgr.h"
#include "SoundMgr.h"
#include "NaviMgr.h"
#include "Interactions.h"
#include "MapMgr.h"
#include "DebugLog.h"

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
DEFINE_PRINT("MizuAi");

/*
 * --INFO--
 * Address:	8017B858
 * Size:	000080
 */
MizuAi::MizuAi(Mizu* mizu)
{
	mMizu = mizu;
	_08 = _0C     = nullptr;
	mPuffCallBack = new MizuGenSpringPuffCallBack();
}

/*
 * --INFO--
 * Address:	8017B8D8
 * Size:	0000B8
 */
void MizuAi::initMizu(Mizu* mizu)
{
	mMizu = mizu;
	_0C   = effectMgr->create(EffectMgr::EFF_Unk194, mMizu->mPosition, nullptr, nullptr);
	_08   = effectMgr->create(EffectMgr::EFF_Unk193, mMizu->mPosition, nullptr, nullptr);
	mMizu->setCurrentState(0);
	mMizu->setNextState(0);
	mMizu->mAnimator.startMotion(PaniMotionInfo(2, this));
	mMizu->setAnimTimer(30.0f);
	initWait(0);
}

/*
 * --INFO--
 * Address:	8017B990
 * Size:	0000B8
 */
void MizuAi::initGeyzer(Mizu* geyzer)
{
	mMizu = geyzer;
	_0C   = effectMgr->create(EffectMgr::EFF_Unk194, mMizu->mPosition, nullptr, nullptr);
	_08   = effectMgr->create(EffectMgr::EFF_Unk193, mMizu->mPosition, nullptr, nullptr);
	mMizu->setCurrentState(1);
	mMizu->setNextState(1);
	mMizu->mAnimator.startMotion(PaniMotionInfo(2, this));
	mMizu->setAnimTimer(30.0f);
	initReady(1);
}

/*
 * --INFO--
 * Address:	8017BA48
 * Size:	000004
 */
void MizuAi::animationKeyUpdated(PaniAnimKeyEvent&) { }

/*
 * --INFO--
 * Address:	8017BA4C
 * Size:	00007C
 */
void MizuAi::killCallBackEffect(bool p1)
{
	if (_08) {
		_08->forceFinish();
		_08 = nullptr;
	}

	if (_0C) {
		_0C->forceFinish();
		_0C = nullptr;
	}

	effectMgr->killGenerator(mPuffCallBack, nullptr, p1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void MizuAi::setEveryFrame()
{
	Vector3f* vec      = mMizu->getInitPosition();
	mMizu->mPosition.x = vec->x;
	mMizu->mPosition.y = vec->y;
	mMizu->mPosition.z = vec->z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void MizuAi::naviGeyzerJump()
{
	Vector3f dir(sinf(mMizu->mDirection), 0.0f, cosf(mMizu->mDirection));
	dir.multiply(static_cast<BossProp*>(mMizu->mProps)->mBossProps.mTerritoryRadius());
	Vector3f targetPos = mMizu->mPosition + dir;
	targetPos.y        = mapMgr->getMinY(targetPos.x, targetPos.z, true);

	Navi* navi = naviMgr->getNavi();
	navi->stimulate(InteractGeyzer(mMizu, targetPos));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
bool MizuAi::readyTransit()
{
	return (mMizu->getFlickDamageCount() >= static_cast<BossProp*>(mMizu->mProps)->mBossProps._1CC()) ? true : false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
bool MizuAi::jetTransit() { return mMizu->_3B8 ? true : false; }

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
bool MizuAi::waitTransit() { return (mMizu->get2D4() > 4.0f) ? true : false; }

/*
 * --INFO--
 * Address:	8017BAC8
 * Size:	0000BC
 */
void MizuAi::initWait(int stateID)
{
	mMizu->setNextState(stateID);
	mMizu->mAnimator.startMotion(PaniMotionInfo(2, this));
	mMizu->_3B8 = 1;
	mMizu->_3B9 = true;
	mMizu->setIsAlive(1);
	mMizu->setIsOrganic(1);
	mMizu->set2D4(0.0f);
	mMizu->setFlickDamageCount(0);
	if (_0C) {
		_0C->stop();
	}
	if (_08) {
		_08->stop();
	}
}

/*
 * --INFO--
 * Address:	8017BB84
 * Size:	0000D0
 */
void MizuAi::initReady(int stateID)
{
	mMizu->setNextState(stateID);
	mMizu->mAnimator.startMotion(PaniMotionInfo(2, this));
	mMizu->_3B8 = 0;
	mMizu->_3B9 = false;
	mMizu->setIsAlive(0);
	mMizu->setIsOrganic(0);
	mMizu->set2D4(0.0f);
	mMizu->setFlickDamageCount(0);
	if (_0C) {
		_0C->start();
	}
	if (_08) {
		_08->start();
	}

	if (mMizu->mSeContext) {
		mMizu->mSeContext->playSound(0xA8);
	}
}

/*
 * --INFO--
 * Address:	8017BC54
 * Size:	00026C
 */
void MizuAi::initJet(int stateID)
{
	mMizu->setNextState(stateID);
	mMizu->mAnimator.startMotion(PaniMotionInfo(10, this));
	mMizu->_3B8 = 1;
	mMizu->_3B9 = false;
	mMizu->setIsAlive(0);
	mMizu->setIsOrganic(0);
	mMizu->set2D4(0.0f);
	mMizu->setFlickDamageCount(0);
	naviGeyzerJump();

	if (_0C) {
		_0C->stop();
	}

	if (_08) {
		_08->stop();
	}

	effectMgr->create(EffectMgr::EFF_Unk196, mMizu->mPosition, mPuffCallBack, nullptr);
	zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_Unk195, mMizu->mPosition, nullptr, nullptr);
	mPuffCallBack->setPtcl(ptcl);
	if (ptcl) {
		ptcl->set1DC(Vector3f(1.0f, 0.0f, 0.0f));
	}

	effectMgr->create(EffectMgr::EFF_Unk197, mMizu->mPosition, nullptr, nullptr);

	if (mMizu->mSeContext) {
		mMizu->mSeContext->stopSound(0xA8);
		mMizu->mSeContext->playSound(0xA9);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void MizuAi::waitState() { }

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
void MizuAi::readyState()
{
	if (!mMizu->_3B8) {
		Navi* navi = naviMgr->getNavi();
		if (absVal(mMizu->mPosition.x - navi->mPosition.x) < 7.5f && absVal(mMizu->mPosition.z - navi->mPosition.z) < 7.5f
		    && absVal(mMizu->mPosition.y - navi->mPosition.y) < 10.0f) {
			mMizu->_3B8 = 1;
		}

		if (mMizu->get2D4() > 3.0f) {
			mMizu->set2D4(0.0f);
			if (mMizu->mSeContext) {
				mMizu->mSeContext->playSound(0xA8);
			}
		} else {
			mMizu->add2D4(gsys->getFrameTime());
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void MizuAi::jetState() { mMizu->add2D4(gsys->getFrameTime()); }

/*
 * --INFO--
 * Address:	8017BEC0
 * Size:	000358
 */
void MizuAi::update()
{
	setEveryFrame();

	switch (mMizu->getCurrentState()) {
	case 0:
		waitState();
		if (readyTransit()) {
			initReady(1);
		}
		break;
	case 1:
		readyState();
		if (jetTransit()) {
			initJet(2);
		}
		break;
	case 2:
		jetState();
		if (waitTransit()) {
			initReady(1);
		}
		break;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stw       r31, 0xDC(r1)
	  mr        r31, r3
	  lwz       r3, 0x4(r3)
	  lfs       f0, 0x300(r3)
	  addi      r4, r3, 0x300
	  stfs      f0, 0x94(r3)
	  lfs       f0, 0x304(r3)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x98(r3)
	  lfs       f0, 0x8(r4)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x9C(r3)
	  lwz       r5, 0x4(r31)
	  lwz       r0, 0x2E4(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x13C
	  bge-      .loc_0x5C
	  cmpwi     r0, 0
	  bge-      .loc_0x68
	  b         .loc_0x344

	.loc_0x5C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x344
	  b         .loc_0x260

	.loc_0x68:
	  lwz       r3, 0x224(r5)
	  lwz       r4, 0x2F0(r5)
	  lwz       r0, 0x1D8(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x84
	  li        r0, 0x1
	  b         .loc_0x88

	.loc_0x84:
	  li        r0, 0

	.loc_0x88:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x344
	  li        r0, 0x1
	  stw       r0, 0x2E8(r5)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xC8
	  li        r4, 0x2
	  bl        -0x5CFD8
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5CDB4
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stb       r0, 0x3B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x3B9(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BB(r3)
	  lfs       f0, -0x5158(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2F0(r3)
	  lwz       r3, 0xC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x108
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x108:
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x120
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x120:
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x344
	  li        r4, 0xA8
	  bl        -0xD8224
	  b         .loc_0x344

	.loc_0x13C:
	  lbz       r0, 0x3B8(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x22C
	  lwz       r3, 0x3120(r13)
	  bl        -0x64C48
	  lwz       r4, 0x4(r31)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x94(r4)
	  lfs       f0, -0x5158(r2)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x170
	  b         .loc_0x174

	.loc_0x170:
	  fneg      f1, f1

	.loc_0x174:
	  lfs       f0, -0x5154(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1E0
	  lfs       f2, 0x9C(r4)
	  lfs       f1, 0x9C(r3)
	  lfs       f0, -0x5158(r2)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x19C
	  b         .loc_0x1A0

	.loc_0x19C:
	  fneg      f1, f1

	.loc_0x1A0:
	  lfs       f0, -0x5154(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1E0
	  lfs       f2, 0x98(r4)
	  lfs       f1, 0x98(r3)
	  lfs       f0, -0x5158(r2)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1C8
	  b         .loc_0x1CC

	.loc_0x1C8:
	  fneg      f1, f1

	.loc_0x1CC:
	  lfs       f0, -0x5150(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1E0
	  li        r0, 0x1
	  stb       r0, 0x3B8(r4)

	.loc_0x1E0:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x514C(r2)
	  addi      r4, r3, 0x2D4
	  lfs       f1, 0x2D4(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x21C
	  lfs       f0, -0x5158(r2)
	  stfs      f0, 0x0(r4)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x22C
	  li        r4, 0xA8
	  bl        -0xD8304
	  b         .loc_0x22C

	.loc_0x21C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r4)

	.loc_0x22C:
	  lwz       r3, 0x4(r31)
	  lbz       r0, 0x3B8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x244
	  li        r0, 0x1
	  b         .loc_0x248

	.loc_0x244:
	  li        r0, 0

	.loc_0x248:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x344
	  addi      r3, r31, 0
	  li        r4, 0x2
	  bl        -0x4C4
	  b         .loc_0x344

	.loc_0x260:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D4(r5)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D4(r5)
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x515C(r2)
	  lfs       f1, 0x2D4(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x290
	  li        r0, 0x1
	  b         .loc_0x294

	.loc_0x290:
	  li        r0, 0

	.loc_0x294:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x344
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xB8
	  li        r4, 0x2
	  bl        -0x5D1E4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5CFC0
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stb       r0, 0x3B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x3B9(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BB(r3)
	  lfs       f0, -0x5158(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2F0(r3)
	  lwz       r3, 0xC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x314
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x314:
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x32C
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x32C:
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x344
	  li        r4, 0xA8
	  bl        -0xD8430

	.loc_0x344:
	  lwz       r0, 0xE4(r1)
	  lwz       r31, 0xDC(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017C218
 * Size:	0000B0
 */
bool MizuGenSpringPuffCallBack::invoke(zen::particleGenerator* ptcl)
{
	if (mPtcl) {
		if (mPtcl->isFlag4()) {
			Vector3f* posPtr = (mPtcl->mEmitPosPtr) ? mPtcl->mEmitPosPtr : &mPtcl->_0C;

			Vector3f pos(*posPtr);
			zen::zenList* listStart = mPtcl->_28._00;
			zen::zenList* list      = listStart->mNext;
			while (list != listStart) {
				zen::zenList* next = list->mNext;
				f32 mdlY           = static_cast<zen::particleMdlBase*>(list)->_0C.y + static_cast<zen::particleMdlBase*>(list)->_18.y;
				if (mdlY > pos.y) {
					pos.y = mdlY;
				}
				list = next;
			}
			ptcl->_0C = pos;

		} else {
			mPtcl = nullptr;
		}
	}

	return true;
	/*
	.loc_0x0:
	  stwu      r1, -0x40(r1)
	  lwz       r5, 0x4(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0xA4
	  lwz       r0, 0x80(r5)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x9C
	  lwz       r3, 0x18(r5)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C
	  b         .loc_0x30

	.loc_0x2C:
	  addi      r3, r5, 0xC

	.loc_0x30:
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x3C(r1)
	  lwz       r3, 0x28(r5)
	  lwz       r5, 0x8(r3)
	  b         .loc_0x78

	.loc_0x54:
	  lfs       f2, 0x10(r5)
	  lfs       f1, 0x1C(r5)
	  lfs       f0, 0x38(r1)
	  fadds     f1, f2, f1
	  lwz       r0, 0x8(r5)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x74
	  stfs      f1, 0x38(r1)

	.loc_0x74:
	  mr        r5, r0

	.loc_0x78:
	  cmplw     r5, r3
	  bne+      .loc_0x54
	  lwz       r3, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x14(r4)
	  b         .loc_0xA4

	.loc_0x9C:
	  li        r0, 0
	  stw       r0, 0x4(r3)

	.loc_0xA4:
	  li        r3, 0x1
	  addi      r1, r1, 0x40
	  blr
	*/
}
