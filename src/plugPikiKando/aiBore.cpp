#include "PikiAI.h"
#include "UtilityKando.h"
#include "teki.h"
#include "ItemMgr.h"
#include "Boss.h"
#include "NaviMgr.h"
#include "NaviState.h"
#include "SoundMgr.h"
#include "system.h"
#include "sysNew.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AA51C
 * Size:	000108
 */
ActFreeSelect::ActFreeSelect(Piki* piki)
    : Action(piki, true)
{
	mName = "freebore";
	setChildren(CHILD_COUNT, new ActWatch(piki), nullptr, new ActBoreTalk(piki), nullptr, new ActBoreOneshot(piki), nullptr,
	            new ActBoreRest(piki), nullptr);
}

/*
 * --INFO--
 * Address:	800AA624
 * Size:	0000F4
 */
void ActFreeSelect::init(Creature* creature)
{
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Wait, mActor), PaniMotionInfo(PIKIANIM_Wait));
	mActionTimer    = 2.0f + gsys->getFrameTime();
	mIsTimerActive  = 1;
	mChildActionIdx = CHILD_NULL;

	_1C                  = PI * (randBalanced(0.5f)) / 3.0f;
	mIsChildActionActive = 0;
	_1A                  = 0;
}

/*
 * --INFO--
 * Address:	800AA718
 * Size:	000084
 */
void ActFreeSelect::finishRest()
{
	switch (mChildActionIdx) {
	case CHILD_BoreRest:
		static_cast<ActBoreRest*>(mChildActions[mChildActionIdx].mAction)->_18 = 1;
		mIsChildActionActive                                                   = 1;
		break;
	case CHILD_BoreOneshot:
		static_cast<ActBoreOneshot*>(mChildActions[mChildActionIdx].mAction)->finish();
		mIsChildActionActive = 1;
		break;
	default:
		_1A = 1;
		break;
	}
}

/*
 * --INFO--
 * Address:	800AA79C
 * Size:	000108
 */
int ActFreeSelect::exec()
{
	if (_1A) {
		return ACTOUT_Success;
	}

	if (mIsChildActionActive) {
		return mChildActions[mChildActionIdx].mAction->exec();
	}

	if (mIsTimerActive) {
		mActor->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mActionTimer -= gsys->getFrameTime();
		if (mActionTimer < 0.0f) {
			determine();
		}
	} else {
		if (mChildActions[mChildActionIdx].mAction->exec()) {
			init(nullptr);
		}
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AA8A4
 * Size:	000004
 */
void ActFreeSelect::cleanup() { }

/*
 * --INFO--
 * Address:	800AA8A8
 * Size:	000078
 */
void ActFreeSelect::procTargetMsg(Piki* piki, MsgTarget* msg)
{
	if (mIsTimerActive) {
		mIsTimerActive  = 0;
		mChildActionIdx = CHILD_Watch;
		mChildActions[mChildActionIdx].initialise(msg->mTarget);
		return;
	}

	if (mChildActionIdx == CHILD_BoreTalk) {
		ActBoreTalk* boreTalk = static_cast<ActBoreTalk*>(mChildActions[mChildActionIdx].mAction);
		boreTalk->_18         = 0;
		boreTalk->mTarget     = msg->mTarget;
	}
}

/*
 * --INFO--
 * Address:	800AA920
 * Size:	0002D8
 */
void ActFreeSelect::determine()
{
	if (coinFlip()) {
		mActionTimer = 2.0f + gsys->getFrameTime();
		return;
	}

	Choice choices[CHILD_COUNT] = {
		{ CHILD_Watch, 0.2f },
		{ CHILD_BoreTalk, 0.1f },
		{ CHILD_BoreOneshot, 0.3f },
		{ CHILD_BoreRest, 0.3f },
	};

	int randIdx = selectRandomly(choices, CHILD_COUNT);

	if (mActor->_2AC) {
		randIdx = CHILD_Watch;
	}

	mIsTimerActive  = 0;
	mChildActionIdx = randIdx;

	Creature* target = nullptr;

	switch (randIdx) {
	case CHILD_Watch:
		Creature* nearestEnemy;
		if (tekiMgr) {
			nearestEnemy = tekiMgr->findClosest(mActor->mPosition, nullptr);
		}

		Creature* nearestItem = itemMgr->findClosest(mActor->mPosition, nullptr);
		Creature* nearestNavi = naviMgr->findClosest(mActor->mPosition, nullptr);

		Creature* nearestBoss = (bossMgr) ? bossMgr->findClosest(mActor->mPosition, nullptr) : nullptr;

		if (nearestBoss) {
			target = nearestBoss;
			break;
		}

		// these are probably not distances, rename later
		f32 enemyDist = (nearestEnemy) ? nearestEnemy->mVelocity.length() : 0.0f;
		f32 itemDist  = (nearestItem) ? nearestItem->mVelocity.length() : 0.0f;
		f32 naviDist  = (nearestNavi) ? nearestNavi->mVelocity.length() : 0.0f;

		if (enemyDist > itemDist && enemyDist > naviDist) {
			target = nearestEnemy;
			break;
		}

		if (itemDist > naviDist) {
			target = nearestItem;
			break;
		}

		target = nearestNavi;
		break;
	case CHILD_BoreTalk:
		break;
	}

	mChildActions[mChildActionIdx].initialise(target);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stfd      f30, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r3
	  stw       r30, 0x68(r1)
	  stw       r29, 0x64(r1)
	  stw       r28, 0x60(r1)
	  bl        0x16D728
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x5C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7100(r2)
	  stw       r0, 0x58(r1)
	  lfs       f1, -0x7104(r2)
	  lfd       f3, 0x58(r1)
	  lfs       f0, -0x70F8(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7108(r2)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r31)
	  b         .loc_0x2B0

	.loc_0x7C:
	  lis       r3, 0x8022
	  addi      r6, r3, 0x2440
	  lwz       r5, 0x0(r6)
	  addi      r3, r1, 0x34
	  lwz       r0, 0x4(r6)
	  li        r4, 0x4
	  stw       r5, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x3C(r1)
	  stw       r0, 0x40(r1)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x44(r1)
	  stw       r0, 0x48(r1)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  bl        0x6B724
	  lwz       r4, 0xC(r31)
	  lwz       r0, 0x2AC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xE4
	  li        r3, 0

	.loc_0xE4:
	  li        r30, 0
	  stb       r30, 0x18(r31)
	  extsh     r0, r3
	  cmpwi     r3, 0x1
	  sth       r0, 0x8(r31)
	  li        r4, 0
	  beq-      .loc_0x29C
	  bge-      .loc_0x29C
	  cmpwi     r3, 0
	  bge-      .loc_0x110
	  b         .loc_0x29C

	.loc_0x110:
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x13C
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x6C(r12)
	  addi      r4, r4, 0x94
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x13C:
	  lwz       r3, 0x30AC(r13)
	  li        r5, 0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  lwz       r3, 0x3120(r13)
	  lwz       r4, 0xC(r31)
	  mr        r29, r0
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x3168(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x1B8
	  mr        r3, r0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1BC

	.loc_0x1B8:
	  li        r3, 0

	.loc_0x1BC:
	  cmplwi    r3, 0
	  beq-      .loc_0x1CC
	  mr        r4, r3
	  b         .loc_0x29C

	.loc_0x1CC:
	  cmplwi    r30, 0
	  beq-      .loc_0x200
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0x74(r30)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r30)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9CED4
	  fmr       f31, f1
	  b         .loc_0x204

	.loc_0x200:
	  lfs       f31, -0x70E8(r2)

	.loc_0x204:
	  cmplwi    r29, 0
	  beq-      .loc_0x238
	  lfs       f1, 0x70(r29)
	  lfs       f0, 0x74(r29)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r29)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9CF0C
	  fmr       f30, f1
	  b         .loc_0x23C

	.loc_0x238:
	  lfs       f30, -0x70E8(r2)

	.loc_0x23C:
	  cmplwi    r28, 0
	  beq-      .loc_0x26C
	  lfs       f1, 0x70(r28)
	  lfs       f0, 0x74(r28)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r28)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9CF44
	  b         .loc_0x270

	.loc_0x26C:
	  lfs       f1, -0x70E8(r2)

	.loc_0x270:
	  fcmpo     cr0, f31, f30
	  ble-      .loc_0x288
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x288
	  mr        r4, r30
	  b         .loc_0x29C

	.loc_0x288:
	  fcmpo     cr0, f30, f1
	  ble-      .loc_0x298
	  mr        r4, r29
	  b         .loc_0x29C

	.loc_0x298:
	  mr        r4, r28

	.loc_0x29C:
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        0x19158

	.loc_0x2B0:
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lfd       f30, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  lwz       r28, 0x60(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AABF8
 * Size:	000104
 */
ActBoreSelect::ActBoreSelect(Piki* piki)
    : Action(piki, true)
{
	mName = "bore";
	setChildren(CHILD_COUNT, new ActWatch(piki), nullptr, new ActBoreTalk(piki), nullptr, new ActBoreOneshot(piki), nullptr,
	            new ActBoreRest(piki), nullptr);
}

/*
 * --INFO--
 * Address:	800AACFC
 * Size:	0000F4
 */
void ActBoreSelect::init(Creature* creature)
{
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Wait, mActor), PaniMotionInfo(PIKIANIM_Wait));
	mActionTimer    = 2.0f + gsys->getFrameTime();
	mIsTimerActive  = 1;
	mChildActionIdx = CHILD_NULL;

	_1C                  = PI * (randBalanced(0.5f)) / 3.0f;
	mIsChildActionActive = 0;
	_1A                  = 0;
}

/*
 * --INFO--
 * Address:	800AADF0
 * Size:	00000C
 */
void ActBoreSelect::stop() { _1A = 1; }

/*
 * --INFO--
 * Address:	800AADFC
 * Size:	000184
 */
int ActBoreSelect::exec()
{
	if (mIsChildActionActive) {
		return mChildActions[mChildActionIdx].mAction->exec();
	}

	if (mActor->mNavi->_738 < 1.0f || _1A) {
		if (mActor->mPikiAnimMgr.mLowerAnimator.mMotionIdx == 3) {
			return ACTOUT_Success;
		}

		if (mChildActionIdx == CHILD_BoreRest) {
			static_cast<ActBoreRest*>(mChildActions[mChildActionIdx].mAction)->_18 = 1;
			mIsChildActionActive                                                   = true;
			return ACTOUT_Continue;
		}

		if (mChildActionIdx == CHILD_BoreOneshot) {
			static_cast<ActBoreOneshot*>(mChildActions[mChildActionIdx].mAction)->finish();
			mIsChildActionActive = true;
			return ACTOUT_Continue;
		}
		return ACTOUT_Success;
	}

	if (mIsTimerActive) {
		mActor->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mActionTimer -= gsys->getFrameTime();
		if (mActionTimer < 0.0f) {
			determine();
		}
	} else {
		if (mChildActions[mChildActionIdx].mAction->exec()) {
			init(nullptr);
		}
	}

	return ACTOUT_Continue;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lbz       r0, 0x19(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x44
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x170

	.loc_0x44:
	  lwz       r4, 0xC(r31)
	  lfs       f0, -0x7104(r2)
	  lwz       r3, 0x504(r4)
	  lfs       f1, 0x738(r3)
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0x68
	  lbz       r0, 0x1A(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xD8

	.loc_0x68:
	  lwz       r0, 0x39C(r4)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x7C
	  li        r3, 0x2
	  b         .loc_0x170

	.loc_0x7C:
	  lha       r0, 0x8(r31)
	  cmpwi     r0, 0x3
	  bne-      .loc_0xA8
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  li        r5, 0x1
	  lwzx      r4, r3, r0
	  li        r3, 0
	  stb       r5, 0x18(r4)
	  stb       r5, 0x19(r31)
	  b         .loc_0x170

	.loc_0xA8:
	  cmpwi     r0, 0x2
	  bne-      .loc_0xD0
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  bl        0xA38
	  li        r0, 0x1
	  stb       r0, 0x19(r31)
	  li        r3, 0
	  b         .loc_0x170

	.loc_0xD0:
	  li        r3, 0x2
	  b         .loc_0x170

	.loc_0xD8:
	  lbz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x12C
	  lfs       f0, -0x4F3C(r13)
	  stfs      f0, 0xA4(r4)
	  lfs       f0, -0x4F38(r13)
	  stfs      f0, 0xA8(r4)
	  lfs       f0, -0x4F34(r13)
	  stfs      f0, 0xAC(r4)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x14(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r31)
	  lfs       f1, 0x14(r31)
	  lfs       f0, -0x70E8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x16C
	  mr        r3, r31
	  bl        0x198
	  b         .loc_0x16C

	.loc_0x12C:
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0
	  beq-      .loc_0x16C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x16C:
	  li        r3, 0

	.loc_0x170:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AAF80
 * Size:	000004
 */
void ActBoreSelect::cleanup() { }

/*
 * --INFO--
 * Address:	800AAF84
 * Size:	000078
 */
void ActBoreSelect::procTargetMsg(Piki* piki, MsgTarget* msg)
{
	if (mIsTimerActive) {
		mIsTimerActive  = 0;
		mChildActionIdx = CHILD_Watch;
		mChildActions[mChildActionIdx].initialise(msg->mTarget);
		return;
	}

	if (mChildActionIdx == CHILD_BoreTalk) {
		ActBoreTalk* boreTalk = static_cast<ActBoreTalk*>(mChildActions[mChildActionIdx].mAction);
		boreTalk->_18         = 0;
		boreTalk->mTarget     = msg->mTarget;
	}
}

/*
 * --INFO--
 * Address:	800AAFFC
 * Size:	0000BC
 */
void ActBoreSelect::procAnimMsg(Piki* piki, MsgAnim* msg)
{
	if (mChildActionIdx != CHILD_NULL) {
		mChildActions[mChildActionIdx].mAction->procAnimMsg(piki, msg);
		return;
	}

	switch (msg->mKeyEvent->mEventType) {
	case KEY_Done:
		piki->startMotion(PaniMotionInfo(PIKIANIM_Wait, piki), PaniMotionInfo(PIKIANIM_Wait));
		break;
	}
}

/*
 * --INFO--
 * Address:	800AB0B8
 * Size:	0002D8
 */
void ActBoreSelect::determine()
{
	if (coinFlip()) {
		mActionTimer = 2.0f + gsys->getFrameTime();
		return;
	}

	Choice choices[CHILD_COUNT] = {
		{ CHILD_Watch, 0.1f },
		{ CHILD_BoreTalk, 0.5f },
		{ CHILD_BoreOneshot, 0.3f },
		{ CHILD_BoreRest, 0.1f },
	};

	int randIdx = selectRandomly(choices, CHILD_COUNT);

	if (mActor->_2AC) {
		randIdx = CHILD_Watch;
	}

	mIsTimerActive  = 0;
	mChildActionIdx = randIdx;

	Creature* target = nullptr;

	switch (randIdx) {
	case CHILD_Watch:
		Creature* nearestEnemy;
		if (tekiMgr) {
			nearestEnemy = tekiMgr->findClosest(mActor->mPosition, nullptr);
		}

		Creature* nearestItem = itemMgr->findClosest(mActor->mPosition, nullptr);
		Creature* nearestNavi = naviMgr->findClosest(mActor->mPosition, nullptr);

		Creature* nearestBoss = (bossMgr) ? bossMgr->findClosest(mActor->mPosition, nullptr) : nullptr;

		if (nearestBoss) {
			target = nearestBoss;
			break;
		}

		// these are probably not distances, rename later
		f32 enemyDist = (nearestEnemy) ? nearestEnemy->mVelocity.length() : 0.0f;
		f32 itemDist  = (nearestItem) ? nearestItem->mVelocity.length() : 0.0f;
		f32 naviDist  = (nearestNavi) ? nearestNavi->mVelocity.length() : 0.0f;

		if (enemyDist > itemDist && enemyDist > naviDist) {
			target = nearestEnemy;
			break;
		}

		if (itemDist > naviDist) {
			target = nearestItem;
			break;
		}

		target = nearestNavi;
		break;
	case CHILD_BoreTalk:
		break;
	}

	mChildActions[mChildActionIdx].initialise(target);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stfd      f30, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r3
	  stw       r30, 0x68(r1)
	  stw       r29, 0x64(r1)
	  stw       r28, 0x60(r1)
	  bl        0x16CF90
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x5C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7100(r2)
	  stw       r0, 0x58(r1)
	  lfs       f1, -0x7104(r2)
	  lfd       f3, 0x58(r1)
	  lfs       f0, -0x70F8(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7108(r2)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r31)
	  b         .loc_0x2B0

	.loc_0x7C:
	  lis       r3, 0x8022
	  addi      r6, r3, 0x2460
	  lwz       r5, 0x0(r6)
	  addi      r3, r1, 0x34
	  lwz       r0, 0x4(r6)
	  li        r4, 0x4
	  stw       r5, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x3C(r1)
	  stw       r0, 0x40(r1)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x44(r1)
	  stw       r0, 0x48(r1)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  bl        0x6AF8C
	  lwz       r4, 0xC(r31)
	  lwz       r0, 0x2AC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xE4
	  li        r3, 0

	.loc_0xE4:
	  li        r30, 0
	  stb       r30, 0x18(r31)
	  extsh     r0, r3
	  cmpwi     r3, 0x1
	  sth       r0, 0x8(r31)
	  li        r4, 0
	  beq-      .loc_0x29C
	  bge-      .loc_0x29C
	  cmpwi     r3, 0
	  bge-      .loc_0x110
	  b         .loc_0x29C

	.loc_0x110:
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x13C
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x6C(r12)
	  addi      r4, r4, 0x94
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x13C:
	  lwz       r3, 0x30AC(r13)
	  li        r5, 0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  lwz       r3, 0x3120(r13)
	  lwz       r4, 0xC(r31)
	  mr        r29, r0
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x3168(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x1B8
	  mr        r3, r0
	  lwz       r4, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  addi      r4, r4, 0x94
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1BC

	.loc_0x1B8:
	  li        r3, 0

	.loc_0x1BC:
	  cmplwi    r3, 0
	  beq-      .loc_0x1CC
	  mr        r4, r3
	  b         .loc_0x29C

	.loc_0x1CC:
	  cmplwi    r30, 0
	  beq-      .loc_0x200
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0x74(r30)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r30)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9D66C
	  fmr       f31, f1
	  b         .loc_0x204

	.loc_0x200:
	  lfs       f31, -0x70E8(r2)

	.loc_0x204:
	  cmplwi    r29, 0
	  beq-      .loc_0x238
	  lfs       f1, 0x70(r29)
	  lfs       f0, 0x74(r29)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r29)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9D6A4
	  fmr       f30, f1
	  b         .loc_0x23C

	.loc_0x238:
	  lfs       f30, -0x70E8(r2)

	.loc_0x23C:
	  cmplwi    r28, 0
	  beq-      .loc_0x26C
	  lfs       f1, 0x70(r28)
	  lfs       f0, 0x74(r28)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r28)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x9D6DC
	  b         .loc_0x270

	.loc_0x26C:
	  lfs       f1, -0x70E8(r2)

	.loc_0x270:
	  fcmpo     cr0, f31, f30
	  ble-      .loc_0x288
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0x288
	  mr        r4, r30
	  b         .loc_0x29C

	.loc_0x288:
	  fcmpo     cr0, f30, f1
	  ble-      .loc_0x298
	  mr        r4, r29
	  b         .loc_0x29C

	.loc_0x298:
	  mr        r4, r28

	.loc_0x29C:
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  bl        0x189C0

	.loc_0x2B0:
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lfd       f30, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  lwz       r28, 0x60(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AB390
 * Size:	000080
 */
ActBoreTalk::ActBoreTalk(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800AB410
 * Size:	0000E8
 */
void ActBoreTalk::init(Creature* creature)
{
	mIsAnimFinished   = false;
	_18               = 0;
	SearchBuffer* buf = &mActor->mSearchBuffer;
	int start         = buf->getFirst();
	mTarget           = buf->getCreatureCheck(start);
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Asibumi, this), PaniMotionInfo(PIKIANIM_Asibumi));
	mActor->enableMotionBlend();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  addi      r29, r3, 0
	  stb       r0, 0x24(r3)
	  stw       r0, 0x18(r3)
	  lwz       r3, 0xC(r3)
	  addi      r30, r3, 0x1B8
	  lwz       r12, 0x0(r30)
	  addi      r3, r30, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r4, r3, 0
	  cmpwi     r4, -0x1
	  bne-      .loc_0x6C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x80

	.loc_0x6C:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x80:
	  cmplwi    r29, 0
	  stw       r3, 0x1C(r29)
	  mr        r30, r29
	  beq-      .loc_0x94
	  lwz       r30, 0x14(r29)

	.loc_0x94:
	  addi      r3, r1, 0x1C
	  li        r4, 0xB
	  bl        0x73AAC
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x24
	  li        r4, 0xB
	  bl        0x73ACC
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1F508
	  lwz       r3, 0xC(r29)
	  bl        0x1F734
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AB4F8
 * Size:	000214
 */
void ActBoreTalk::startTalk()
{
	SearchBuffer* buf = &mActor->mSearchBuffer;
	mActor->turnTo(mTarget->mPosition);

	Iterator iter(buf);
	CI_LOOP(iter) { iter.getCreature()->stimulate(InteractTalk(mActor)); }

	mActor->startMotion(PaniMotionInfo(PIKIANIM_Chatting, this), PaniMotionInfo(PIKIANIM_Chatting));
	mActor->enableMotionBlend();
	_20 = randFloat(2.0f) + 5.0f;

	if (mActor->mMode == 1 && mActor->mNavi->mPlateMgr && mActor->mNavi->mCurrState->getStateID() != NAVISTATE_DemoSunset
	    && mActor->mNavi->mCurrState->getStateID() != NAVISTATE_Dead) {
		seMgr->setPikiNum(0);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stmw      r26, 0x70(r1)
	  mr        r30, r3
	  lwz       r3, 0xC(r3)
	  lwz       r4, 0x1C(r30)
	  addi      r31, r3, 0x1B8
	  addi      r4, r4, 0x94
	  bl        -0x20AE0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802B
	  addi      r26, r3, 0
	  subi      r28, r5, 0x3064
	  subi      r29, r4, 0x2D74
	  addi      r27, r1, 0x50
	  b         .loc_0xD4

	.loc_0x58:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x7C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x94

	.loc_0x7C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x94:
	  lwz       r0, 0xC(r30)
	  mr        r4, r27
	  stw       r28, 0x50(r1)
	  stw       r0, 0x54(r1)
	  stw       r29, 0x50(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0xD4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xFC
	  li        r0, 0x1
	  b         .loc_0x128

	.loc_0xFC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x124
	  li        r0, 0x1
	  b         .loc_0x128

	.loc_0x124:
	  li        r0, 0

	.loc_0x128:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x58
	  cmplwi    r30, 0
	  addi      r27, r30, 0
	  beq-      .loc_0x140
	  lwz       r27, 0x14(r30)

	.loc_0x140:
	  addi      r3, r1, 0x40
	  li        r4, 0x40
	  bl        0x73918
	  addi      r31, r3, 0
	  addi      r5, r27, 0
	  addi      r3, r1, 0x48
	  li        r4, 0x40
	  bl        0x73938
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1F374
	  lwz       r3, 0xC(r30)
	  bl        0x1F5A0
	  bl        0x16CA00
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x6C(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x7100(r2)
	  stw       r0, 0x68(r1)
	  lfs       f2, -0x7104(r2)
	  lfd       f1, 0x68(r1)
	  lfs       f0, -0x7108(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x70E4(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r30)
	  lwz       r3, 0xC(r30)
	  lhz       r0, 0x4FC(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x200
	  lwz       r3, 0x504(r3)
	  lwz       r0, 0x710(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x200
	  lwz       r3, 0xADC(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x19
	  beq-      .loc_0x200
	  cmpwi     r0, 0x1D
	  beq-      .loc_0x200
	  lwz       r3, 0x3030(r13)
	  li        r4, 0
	  bl        -0x80B8

	.loc_0x200:
	  lmw       r26, 0x70(r1)
	  lwz       r0, 0x8C(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AB70C
 * Size:	000128
 */
int ActBoreTalk::exec()
{
	if (!mTarget) {
		return ACTOUT_Fail;
	}

	if (_18 == 0) {
		f32 angle          = angDist(mActor->mPosition.angSep(mTarget->mPosition), mActor->mDirection);
		mActor->mDirection = roundAng(mActor->mDirection + 0.1f * angle);

		// what is going on here, this should have a conversion and a clrlwi r0, r0, 1???
		if (quickABS(angle) < 0.1f) {
			_18 = 1;
			startTalk();
		}
	}

	if (mIsAnimFinished) {
		return ACTOUT_Success;
	}

	_20 -= gsys->getFrameTime();
	if (_20 < 0.0f) {
		mActor->mPikiAnimMgr.finishMotion(this);
	}

	return ACTOUT_Continue;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  lwz       r4, 0x1C(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x2C
	  li        r3, 0x1
	  b         .loc_0x110

	.loc_0x2C:
	  lwz       r0, 0x18(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0xB8
	  lwz       r3, 0xC(r31)
	  lfsu      f3, 0x94(r4)
	  lfsu      f1, 0x94(r3)
	  lfs       f2, 0x8(r4)
	  lfs       f0, 0x8(r3)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x170298
	  lwz       r3, 0xC(r31)
	  lfs       f2, 0xA0(r3)
	  bl        -0x731B8
	  fmr       f31, f1
	  lfs       f0, -0x70E0(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f31
	  lfs       f1, 0xA0(r3)
	  fadds     f1, f1, f0
	  bl        -0x73200
	  lwz       r3, 0xC(r31)
	  stfs      f1, 0xA0(r3)
	  stfs      f31, 0x3C(r1)
	  lfs       f0, -0x70E0(r2)
	  lwz       r0, 0x3C(r1)
	  rlwinm    r0,r0,0,1,31
	  stw       r0, 0x3C(r1)
	  lfs       f1, 0x3C(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB8
	  li        r0, 0x1
	  stw       r0, 0x18(r31)
	  mr        r3, r31
	  bl        -0x2C8

	.loc_0xB8:
	  lbz       r0, 0x24(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xCC
	  li        r3, 0x2
	  b         .loc_0x110

	.loc_0xCC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x20(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lfs       f1, 0x20(r31)
	  lfs       f0, -0x70E8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x10C
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x100
	  lwz       r4, 0x14(r31)

	.loc_0x100:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x742AC

	.loc_0x10C:
	  li        r3, 0

	.loc_0x110:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AB834
 * Size:	000004
 */
void ActBoreTalk::cleanup() { }

/*
 * --INFO--
 * Address:	800AB838
 * Size:	000024
 */
void ActBoreTalk::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	if (_18 && event.mEventType == KEY_Done) {
		mIsAnimFinished = true;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
ActBoreListen::ActBoreListen(Piki* piki)
    : Action(piki, true)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AB85C
 * Size:	000004
 */
void ActBoreListen::init(Creature*) { }

/*
 * --INFO--
 * Address:	800AB860
 * Size:	000008
 */
int ActBoreListen::exec() { return 0; }

/*
 * --INFO--
 * Address:	800AB868
 * Size:	000004
 */
void ActBoreListen::cleanup() { }

/*
 * --INFO--
 * Address:	800AB86C
 * Size:	000004
 */
void ActBoreListen::procAnimMsg(Piki*, MsgAnim*) { }

/*
 * --INFO--
 * Address:	800AB870
 * Size:	000080
 */
ActBoreOneshot::ActBoreOneshot(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800AB8F0
 * Size:	000038
 */
void ActBoreOneshot::finish() { mActor->mPikiAnimMgr.finishMotion(this); }

/*
 * --INFO--
 * Address:	800AB928
 * Size:	0000E0
 */
void ActBoreOneshot::init(Creature* creature)
{
	mIsAnimFinished   = false;
	Choice choices[4] = {
		{ PIKIANIM_Akubi, 0.35f },
		{ PIKIANIM_Rinbow, 0.35f },
		{ PIKIANIM_Sagasu2, 0.2f },
		{ PIKIANIM_Iraira, 0.1f },
	};

	int randAnim = selectRandomly(choices, 4);

	mActor->startMotion(PaniMotionInfo(randAnim, this), PaniMotionInfo(randAnim));
}

/*
 * --INFO--
 * Address:	800ABA08
 * Size:	00001C
 */
int ActBoreOneshot::exec()
{
	if (mIsAnimFinished) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800ABA24
 * Size:	000004
 */
void ActBoreOneshot::cleanup() { }

/*
 * --INFO--
 * Address:	800ABA28
 * Size:	000018
 */
void ActBoreOneshot::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	if (event.mEventType == KEY_Done) {
		mIsAnimFinished = true;
	}
}

/*
 * --INFO--
 * Address:	800ABA40
 * Size:	000080
 */
ActBoreRest::ActBoreRest(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800ABAC0
 * Size:	00008C
 */
void ActBoreRest::init(Creature* creature)
{
	_1C = 0;
	sitDown();
	_20 = 5.0f + randFloat(4.0f);
	_24 = _25 = 0;
	_18       = 0;
}

/*
 * --INFO--
 * Address:	800ABB4C
 * Size:	0000E8
 */
void ActBoreRest::sitDown()
{
	switch (_1C) {
	case 0:
		mActor->startMotion(PaniMotionInfo(PIKIANIM_Suwaru, this), PaniMotionInfo(PIKIANIM_Suwaru));
		_1C = 1;
		break;
	case 1:
		mActor->startMotion(PaniMotionInfo(PIKIANIM_Neru, this), PaniMotionInfo(PIKIANIM_Neru));
		_1C = 3;
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void ActBoreRest::standUp()
{
	switch (_1C) {
	case 1:
		mActor->mPikiAnimMgr.finishMotion(this);
		_24 = 1;
		break;
	case 3:
		mActor->mPikiAnimMgr.finishMotion(this);
		_24 = 1;
		break;
	}
}

/*
 * --INFO--
 * Address:	800ABC34
 * Size:	0002E8
 */
int ActBoreRest::exec()
{
	if (_25) {
		return ACTOUT_Success;
	}

	if (_18) {
		if (!_24) {
			if (_1C >= 1) {
				standUp();
				return ACTOUT_Continue;
			}
			return ACTOUT_Success;
		}
		return ACTOUT_Continue;
	}

	_20 -= gsys->getFrameTime();

	if (!_24 && _20 < 0.0f) {
		if (_1C <= 1 && coinFlip()) {
			sitDown();
		} else if (_1C >= 1) {
			standUp();
		}

		_20 = 3.0f + randFloat(2.0f);
	}

	return ACTOUT_Continue;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  lbz       r0, 0x25(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x30
	  li        r3, 0x2
	  b         .loc_0x2CC

	.loc_0x30:
	  lbz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xDC
	  lbz       r0, 0x24(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xD4
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x1
	  blt-      .loc_0xCC
	  cmpwi     r0, 0x2
	  beq-      .loc_0xC4
	  bge-      .loc_0x6C
	  cmpwi     r0, 0x1
	  bge-      .loc_0x78
	  b         .loc_0xC4

	.loc_0x6C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xC4
	  b         .loc_0xA0

	.loc_0x78:
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x88
	  lwz       r4, 0x14(r31)

	.loc_0x88:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x73DFC
	  li        r0, 0x1
	  stb       r0, 0x24(r31)
	  b         .loc_0xC4

	.loc_0xA0:
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0xB0
	  lwz       r4, 0x14(r31)

	.loc_0xB0:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x73DD4
	  li        r0, 0x1
	  stb       r0, 0x24(r31)

	.loc_0xC4:
	  li        r3, 0
	  b         .loc_0x2CC

	.loc_0xCC:
	  li        r3, 0x2
	  b         .loc_0x2CC

	.loc_0xD4:
	  li        r3, 0
	  b         .loc_0x2CC

	.loc_0xDC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x20(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lbz       r0, 0x24(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x2C8
	  lfs       f1, 0x20(r31)
	  lfs       f0, -0x70E8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x2C8
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x1
	  bgt-      .loc_0x208
	  bl        0x16C324
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7100(r2)
	  stw       r0, 0x40(r1)
	  lfs       f1, -0x7104(r2)
	  lfd       f3, 0x40(r1)
	  lfs       f0, -0x70F8(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x208
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1BC
	  bge-      .loc_0x284
	  cmpwi     r0, 0
	  bge-      .loc_0x170
	  b         .loc_0x284

	.loc_0x170:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x180
	  lwz       r29, 0x14(r31)

	.loc_0x180:
	  addi      r3, r1, 0x24
	  li        r4, 0x32
	  bl        0x7319C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x1C
	  li        r4, 0x32
	  bl        0x731BC
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x1EBF8
	  li        r0, 0x1
	  stw       r0, 0x1C(r31)
	  b         .loc_0x284

	.loc_0x1BC:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x1CC
	  lwz       r29, 0x14(r31)

	.loc_0x1CC:
	  addi      r3, r1, 0x34
	  li        r4, 0x34
	  bl        0x73150
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x2C
	  li        r4, 0x34
	  bl        0x73170
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x1EBAC
	  li        r0, 0x3
	  stw       r0, 0x1C(r31)
	  b         .loc_0x284

	.loc_0x208:
	  lwz       r0, 0x1C(r31)
	  cmpwi     r0, 0x1
	  blt-      .loc_0x284
	  cmpwi     r0, 0x2
	  beq-      .loc_0x284
	  bge-      .loc_0x22C
	  cmpwi     r0, 0x1
	  bge-      .loc_0x238
	  b         .loc_0x284

	.loc_0x22C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x284
	  b         .loc_0x260

	.loc_0x238:
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x248
	  lwz       r4, 0x14(r31)

	.loc_0x248:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x73C3C
	  li        r0, 0x1
	  stb       r0, 0x24(r31)
	  b         .loc_0x284

	.loc_0x260:
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x270
	  lwz       r4, 0x14(r31)

	.loc_0x270:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x73C14
	  li        r0, 0x1
	  stb       r0, 0x24(r31)

	.loc_0x284:
	  bl        0x16C1B8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x70F0(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x7100(r2)
	  stw       r0, 0x40(r1)
	  lfs       f2, -0x7104(r2)
	  lfd       f1, 0x40(r1)
	  lfs       f0, -0x7108(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x70F4(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r31)

	.loc_0x2C8:
	  li        r3, 0

	.loc_0x2CC:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800ABF1C
 * Size:	000004
 */
void ActBoreRest::cleanup() { }

/*
 * --INFO--
 * Address:	800ABF20
 * Size:	000104
 */
void ActBoreRest::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Done:
		if (_24) {
			switch (_1C) {
			case 1:
				_24 = 0;
				_1C = 0;
				_25 = 1;
				break;
			case 3:
				_24 = 0;
				_1C = 1;
				mActor->startMotion(PaniMotionInfo(PIKIANIM_Suwaru, this), PaniMotionInfo(PIKIANIM_Suwaru));
				mActor->mPikiAnimMgr.mLowerAnimator.mCurrentFrame = 30.0f;
				mActor->mPikiAnimMgr.mUpperAnimator.mCurrentFrame = 30.0f;
				break;
			}
		}
		break;
	case KEY_LoopEnd:
		break;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x6
	  beq-      .loc_0xE8
	  bge-      .loc_0xE8
	  cmpwi     r0, 0
	  beq-      .loc_0x38
	  b         .loc_0xE8

	.loc_0x38:
	  lbz       r0, 0x24(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0xE8
	  lwz       r0, 0x1C(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xE8
	  bge-      .loc_0x60
	  cmpwi     r0, 0x1
	  bge-      .loc_0x6C
	  b         .loc_0xE8

	.loc_0x60:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xE8
	  b         .loc_0x84

	.loc_0x6C:
	  li        r3, 0
	  stb       r3, 0x24(r29)
	  li        r0, 0x1
	  stw       r3, 0x1C(r29)
	  stb       r0, 0x25(r29)
	  b         .loc_0xE8

	.loc_0x84:
	  li        r0, 0
	  stb       r0, 0x24(r29)
	  li        r0, 0x1
	  cmplwi    r29, 0
	  stw       r0, 0x1C(r29)
	  mr        r30, r29
	  beq-      .loc_0xA4
	  lwz       r30, 0x14(r29)

	.loc_0xA4:
	  addi      r3, r1, 0x28
	  li        r4, 0x32
	  bl        0x72F8C
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x30
	  li        r4, 0x32
	  bl        0x72FAC
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1E9E8
	  lfs       f0, -0x70D8(r2)
	  lwz       r3, 0xC(r29)
	  stfs      f0, 0x384(r3)
	  lwz       r3, 0xC(r29)
	  stfs      f0, 0x3D8(r3)

	.loc_0xE8:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}
