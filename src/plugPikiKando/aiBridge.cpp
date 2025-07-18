#include "AIPerf.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "EffectMgr.h"
#include "Interactions.h"
#include "PikiAI.h"
#include "WorkObject.h"
#include "gameflow.h"
#include "zen/Math.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("aiBridge")

/*
 * --INFO--
 * Address:	800ACEA0
 * Size:	0000AC
 */
ActBridge::ActBridge(Piki* piki)
    : Action(piki, true)
{
	mName   = "Bridge";
	mBridge = nullptr;
}

/*
 * --INFO--
 * Address:	800ACF4C
 * Size:	0000DC
 */
void ActBridge::init(Creature* creature)
{
	_33                 = 0;
	mClimbingBridge     = false;
	mPiki->mActionState = 2;
	mPiki->mEmotion     = PikiEmotion::Happy;
	mBridge             = nullptr;

	if (creature && creature->mObjType == OBJTYPE_WorkObject) {
		WorkObject* bridge = static_cast<WorkObject*>(creature);
		if (bridge->isBridge()) {
			mBridge = static_cast<Bridge*>(bridge);
		}
	}

	mState         = STATE_Approach;
	mActionCounter = (4.0f * gsys->getRand(1.0f));
}

/*
 * --INFO--
 * Address:	800AD028
 * Size:	00006C
 */
void ActBridge::dump()
{
	const char* stateNames[] = { "approach", "detour", "go", "work" };
	PRINT("state : %s  bridge stage : %d\n", stateNames[mState], mStageIdx);
	Vector3f stagePos = mBridge->getStagePos(mStageIdx);
	Vector3f sep      = stagePos - mPiki->mPosition;
	Vector3f zVec     = mBridge->getBridgeZVec();
	f32 zdist         = sep.DP(zVec);
	PRINT("zdist is %.1f\n", zdist);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
bool ActBridge::collideBridgeSurface()
{
	Creature* platform = mPiki->getCollidePlatformCreature();
	if (platform && platform == mBridge) {
		Vector3f normal = mPiki->getCollidePlatformNormal();
		if (normal.y > 0.8f) {
			return true;
		}
	}
	STACK_PAD_TERNARY(platform, 1);
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
bool ActBridge::collideBridgeBlocker()
{
	Creature* platform = mPiki->getCollidePlatformCreature();
	if (platform && platform == mBridge) {
		Vector3f normal = mPiki->getCollidePlatformNormal();
		if (normal.dot(mBridge->getBridgeZVec()) < -0.8f) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	800AD094
 * Size:	000094
 */
int ActBridge::exec()
{
	if (!mBridge) {
		PRINT("no bridge!\n");
		mPiki->mEmotion = PikiEmotion::Sad;
		PRINT_GLOBAL("exe:no bridge!");
		return ACTOUT_Fail;
	}

	if (mBridge->mDoUseJointSegments) {
		switch (mState) {
		case STATE_Approach:
			return newExeApproach();
		case STATE_Go:
			return newExeGo();
		case STATE_Work:
			return newExeWork();
		default:
			return ACTOUT_Continue;
		}
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void ActBridge::initDetour()
{
	mState = STATE_Detour;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
int ActBridge::exeDetour()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AD128
 * Size:	000028
 */
void ActBridge::procWallMsg(Piki* piki, MsgWall* msg)
{
	mBridgeWallNormal = *msg->mWallNormal;
	_33               = 8;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
void ActBridge::initClimb()
{
	mState = STATE_Climb;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Noboru, this), PaniMotionInfo(PIKIANIM_Noboru));
	Vector3f normal(mBridgeWallNormal);
	normal.y = 0.0f;
	normal.normalise();
	normal.multiply(-1.0f);

	mClimbingVelocity = Vector3f(0.0f, 1.0f, 0.0f);
	mClimbingVelocity.normalise();
	mPiki->setFlag80();
	PRINT("climb vel (%.1f %.1f %.1f)\n", mClimbingVelocity.x, mClimbingVelocity.y, mClimbingVelocity.z);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
int ActBridge::exeClimb()
{
	if (mClimbingBridge) {
		PRINT("climbing (%.1f %.1f %.1f)\n", mClimbingVelocity.x, mClimbingVelocity.y, mClimbingVelocity.z);
		mPiki->setSpeed(1.0f, mClimbingVelocity);
	} else {
		initApproach();
		mPiki->unsetFlag80();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void ActBridge::initApproach()
{
	mState          = STATE_Approach;
	mClimbingBridge = false;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000328
 */
int ActBridge::exeApproach()
{

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void ActBridge::initGo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003F0
 */
int ActBridge::exeGo()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void ActBridge::initWork()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000414
 */
int ActBridge::exeWork()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void ActBridge::doWork(int mins)
{
	InteractBuild build(mPiki, mStageIdx, mins / 60.0f);
	mBridge->stimulate(build);
	mStartWorkTime = gameflow.mWorldClock.mMinutes;
	mIsAttackReady = FALSE;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800AD150
 * Size:	0000B0
 */
void ActBridge::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	STACK_PAD_VAR(1);
	switch (event.mEventType) {
	case KEY_LoopEnd:
		mIsAttackReady = TRUE;
		break;
	case KEY_PlayEffect:
		if (mPiki->aiCullable() && (AIPerf::optLevel <= 0 || mPiki->mOptUpdateContext.updatable())) {
			effectMgr->create(EffectMgr::EFF_Piki_WorkCloud, mPiki->mEffectPos, nullptr, nullptr);
		}
		break;
	case KEY_Finished:
		mAnimationFinished = true;
		break;
	}
}

/*
 * --INFO--
 * Address:	800AD200
 * Size:	000024
 */
void ActBridge::cleanup()
{
	mPiki->resetCreatureFlag(CF_DisableMovement);
	mPiki->unsetFlag80();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void ActBridge::newInitApproach()
{
	mState = STATE_Approach;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
	PRINT("approach init\n");
}

/*
 * --INFO--
 * Address:	800AD224
 * Size:	000360
 */
int ActBridge::newExeApproach()
{
	if (!mBridge) {
		PRINT_GLOBAL("app bri fail");
		mPiki->mEmotion = PikiEmotion::Sad;
		PRINT("app failed\n");
		return ACTOUT_Fail;
	}

	if (collideBridgeBlocker()) {
		PRINT("approach -> go:blocker found\n");
		newInitGo();
		return ACTOUT_Continue;
	}

	Vector3f direction = mBridge->getStartPos() - mPiki->getPosition();
	STACK_PAD_VAR(1);
	if (direction.normalise() < 300.0f) {
		f32 bridgePosY;
		f32 bridgePosX;
		mBridge->getBridgePos(mPiki->mPosition, bridgePosX, bridgePosY);
		STACK_PAD_VAR(3);
		int currStage = mBridge->getFirstUnfinishedStage();
		if (currStage == -1) {
			PRINT("** newExeApp: SUCCESS * fstStage = -1!\n");
			return ACTOUT_Success;
		}

		f32 stageZ = mBridge->getStageZ(currStage);
		bridgePosY -= (20.0f + stageZ);

		if (absF(bridgePosX) < 0.8f * (0.5f * mBridge->getStageWidth())) {
			if (bridgePosY <= 0.0f) {
				mBridge->getStagePos(mStageIdx);
				// stagePos = stagePos - mActor->mPosition;
				Vector3f zVec = mBridge->getBridgeZVec();
				// f32 val = stagePos.DP(zVec);
				direction = zVec;
				mPiki->setSpeed(0.7f, direction);
			} else {
				PRINT("z:%.1f > 0 : bridge app failed\n", bridgePosY);
				mPiki->mEmotion = PikiEmotion::Sad;
				return ACTOUT_Fail;
			}
		} else {
			STACK_PAD_VAR(1);

			Vector3f newDir;
			if (bridgePosY > -10.0f) {
				newDir = mBridge->getBridgeZVec();
				newDir.multiply(-1.0f);
			} else {
				newDir = mBridge->getBridgeXVec();
				if (bridgePosX > 0.0f) {
					newDir.multiply(-1.0f);
				}
			}
			mPiki->setSpeed(0.7f, newDir);
		}
	} else {
		mPiki->setSpeed(0.7f, direction);
	}

	return ACTOUT_Continue;

	STACK_PAD_TERNARY(mBridge, 6);
}

/*
 * --INFO--
 * Address:	800AD584
 * Size:	0000E0
 */
void ActBridge::newInitGo()
{
	mState = STATE_Go;
	if (mBridge) {
		mStageIdx          = mBridge->getFirstUnfinishedStage();
		mRandomBridgeWidth = gsys->getRand(1.0f) - 0.5f;
	} else {
		mStageIdx = -1;
	}

	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800AD664
 * Size:	00030C
 */
int ActBridge::newExeGo()
{
	if (mStageIdx == -1) {
		PRINT("stage = -1\n");
		PRINT_GLOBAL("go : stage=-1 suc");
		return ACTOUT_Success;
	}

	if (!mBridge) {
		PRINT("failed \n");
		PRINT_GLOBAL("no bridge fail");
		mPiki->mEmotion = PikiEmotion::Sad;
		PRINT("NO BRIDGE!\n");
		return ACTOUT_Fail;
	}

	STACK_PAD_STRUCT(3);
	STACK_PAD_TERNARY(this, 1);
	if (mBridge->isStageFinished(mStageIdx)) {
		PRINT("stage %d is finished\n", mStageIdx);
		newInitGo();
		return ACTOUT_Continue;
	}

	if (collideBridgeBlocker()) {
		newInitWork();
		return ACTOUT_Continue;
	}

	STACK_PAD_INLINE(1);
	bool c = collideBridgeSurface();
	STACK_PAD_TERNARY(c, 2);

	Vector3f stagePos = mBridge->getStagePos(mStageIdx);
	Vector3f xVec     = mBridge->getBridgeXVec();
	xVec.multiply(mRandomBridgeWidth * mBridge->getStageWidth());
	stagePos.add(xVec);

	Vector3f direction = stagePos - mPiki->mPosition;
	mBridge->getBridgeZVec();

	direction.normalise();

	mPiki->setSpeed(0.70f, direction);
	STACK_PAD_VAR(1);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AD970
 * Size:	0000D0
 */
void ActBridge::newInitWork()
{
	mState          = STATE_Work;
	mStartWorkTime  = gameflow.mWorldClock.mMinutes;
	mIsAttackReady  = FALSE;
	mCollisionCount = 0;
	_2A             = 0;

	if (mActionCounter) {
		return;
	}

	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
	mAnimationFinished = false;
	if (AIPerf::bridgeFast) {
		mPiki->setCreatureFlag(CF_DisableMovement);
	}
}

/*
 * --INFO--
 * Address:	800ADA40
 * Size:	000668
 */
int ActBridge::newExeWork()
{
	// If the bridge is finished, continue
	if (mBridge->isStageFinished(mStageIdx)) {
		PRINT("**** STAGE IS FINISHED *** WORK\n");
		PRINT_GLOBAL("stage fin! work->go");
		newInitGo();
		mPiki->resetCreatureFlag(CF_DisableMovement);
		return ACTOUT_Continue;
	}

	if (collideBridgeBlocker()) {
		mCollisionCount = 0;
	} else {
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mCollisionCount++;

		if (mCollisionCount > 3) {
			mPiki->resetCreatureFlag(CF_DisableMovement);
		}

		if (mCollisionCount > 15 && mAnimationFinished) {
			newInitApproach();
			mPiki->resetCreatureFlag(CF_DisableMovement);
			return ACTOUT_Continue;
		}
	}

	if (!mBridge->workable(mPiki->mPosition)) {
		mPiki->mEmotion = PikiEmotion::Sad;
		mPiki->resetCreatureFlag(CF_DisableMovement);
		return ACTOUT_Fail;
	}

	if (mActionCounter != 0) {
		mActionCounter--;
		if (mActionCounter == 0) {
			newInitWork();
		}
		return ACTOUT_Continue;
	}

	int timeSinceLastWork = (gameflow.mWorldClock.mMinutes - mStartWorkTime + 60) % 60;
	if (timeSinceLastWork > 0 && mIsAttackReady) {
		doWork(timeSinceLastWork);
	}

	Vector3f stagePos(mBridge->getStagePos(mStageIdx));
	Vector3f sep = stagePos - mPiki->mPosition;
	Vector3f zVec(mBridge->getBridgeZVec());
	Vector3f xVec(mBridge->getBridgeXVec());
	f32 zDist = sep.DP(zVec);
	f32 xDist = sep.DP(xVec);

	if (absF(zDist) > 24.0f) {
		mPiki->resetCreatureFlag(CF_DisableMovement);
	} else {
		mPiki->setCreatureFlag(CF_DisableMovement);
	}

	if (absF(xDist) > 0.5f * mBridge->getStageWidth()) {
		PRINT("work : x is out of range\n");
		newInitApproach();
		return ACTOUT_Continue;
	}

	STACK_PAD_TERNARY(this, 3);

	if (absF(xDist) > 0.3f * mBridge->getStageWidth()) {
		if (xDist < 0.0f) {
			xVec.multiply(-1.0f);
		}
		zVec = zVec + xVec;
		zVec.normalise();
	}
	mBridge->getStageDepth();
	mPiki->setSpeed(0.5f, zVec);
	return ACTOUT_Continue;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x190(r1)
	  stfd      f31, 0x188(r1)
	  stfd      f30, 0x180(r1)
	  stfd      f29, 0x178(r1)
	  stfd      f28, 0x170(r1)
	  stfd      f27, 0x168(r1)
	  stfd      f26, 0x160(r1)
	  stw       r31, 0x15C(r1)
	  stw       r30, 0x158(r1)
	  mr        r30, r3
	  stw       r29, 0x154(r1)
	  lwz       r3, 0x18(r3)
	  lha       r4, 0x30(r30)
	  bl        -0xF730
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x108
	  li        r0, 0x2
	  sth       r0, 0x1C(r30)
	  lwz       r3, 0x18(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  bl        -0xF860
	  extsh     r0, r3
	  sth       r0, 0x30(r30)
	  bl        0x16A5C8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7088(r2)
	  stw       r0, 0x14C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x7090(r2)
	  stw       r0, 0x148(r1)
	  lfs       f1, -0x7094(r2)
	  lfd       f3, 0x148(r1)
	  lfs       f0, -0x7078(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2C(r30)
	  b         .loc_0xB0

	.loc_0xA8:
	  li        r0, -0x1
	  sth       r0, 0x30(r30)

	.loc_0xB0:
	  cmplwi    r30, 0
	  addi      r29, r30, 0
	  beq-      .loc_0xC0
	  lwz       r29, 0x14(r30)

	.loc_0xC0:
	  addi      r3, r1, 0xD0
	  li        r4, 0x2
	  bl        0x71450
	  addi      r31, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0xC8
	  li        r4, 0x2
	  bl        0x71470
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1CEAC
	  lwz       r4, 0xC(r30)
	  li        r3, 0
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r4)
	  b         .loc_0x634

	.loc_0x108:
	  lwz       r3, 0xC(r30)
	  bl        -0x23904
	  cmplwi    r3, 0
	  beq-      .loc_0x17C
	  lwz       r0, 0x18(r30)
	  cmplw     r3, r0
	  bne-      .loc_0x17C
	  addi      r3, r1, 0xB0
	  lwz       r4, 0xC(r30)
	  bl        -0x23908
	  lfs       f26, 0xB0(r1)
	  addi      r3, r1, 0xBC
	  lfs       f27, 0xB4(r1)
	  lfs       f28, 0xB8(r1)
	  lwz       r4, 0x18(r30)
	  bl        -0xF028
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  fmuls     f2, f26, f1
	  lfs       f3, 0xC4(r1)
	  fmuls     f1, f27, f0
	  lfs       f0, -0x707C(r2)
	  fmuls     f3, f28, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x17C
	  li        r0, 0x1
	  b         .loc_0x180

	.loc_0x17C:
	  li        r0, 0

	.loc_0x180:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x194
	  li        r0, 0
	  sth       r0, 0x28(r30)
	  b         .loc_0x250

	.loc_0x194:
	  lwz       r3, 0xC(r30)
	  lfs       f0, -0x4E5C(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4E58(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4E54(r13)
	  stfs      f0, 0x8(r3)
	  lhz       r3, 0x28(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x28(r30)
	  lhz       r0, 0x28(r30)
	  cmplwi    r0, 0x3
	  ble-      .loc_0x1D8
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0xC8(r3)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r3)

	.loc_0x1D8:
	  lhz       r0, 0x28(r30)
	  cmplwi    r0, 0xF
	  ble-      .loc_0x250
	  lbz       r0, 0x4D(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x250
	  li        r0, 0
	  cmplwi    r30, 0
	  sth       r0, 0x1C(r30)
	  mr        r29, r30
	  beq-      .loc_0x208
	  lwz       r29, 0x14(r30)

	.loc_0x208:
	  addi      r3, r1, 0x98
	  li        r4, 0x2
	  bl        0x71308
	  addi      r31, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x90
	  li        r4, 0x2
	  bl        0x71328
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1CD64
	  lwz       r4, 0xC(r30)
	  li        r3, 0
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r4)
	  b         .loc_0x634

	.loc_0x250:
	  lwz       r3, 0x18(r30)
	  lwz       r4, 0xC(r30)
	  lwz       r12, 0x0(r3)
	  addi      r4, r4, 0x94
	  lwz       r12, 0x168(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x298
	  lwz       r4, 0xC(r30)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  lwz       r4, 0xC(r30)
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r4)
	  b         .loc_0x634

	.loc_0x298:
	  lbz       r3, 0x4C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x358
	  subi      r0, r3, 0x1
	  stb       r0, 0x4C(r30)
	  lbz       r0, 0x4C(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x350
	  li        r0, 0x4
	  lis       r3, 0x803A
	  sth       r0, 0x1C(r30)
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x300(r3)
	  li        r0, 0
	  stw       r3, 0x20(r30)
	  stw       r0, 0x24(r30)
	  sth       r0, 0x28(r30)
	  sth       r0, 0x2A(r30)
	  lbz       r0, 0x4C(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x350
	  cmplwi    r30, 0
	  addi      r29, r30, 0
	  beq-      .loc_0x2FC
	  lwz       r29, 0x14(r30)

	.loc_0x2FC:
	  addi      r3, r1, 0x88
	  li        r4, 0x30
	  bl        0x71214
	  addi      r31, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x80
	  li        r4, 0x30
	  bl        0x71234
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1CC70
	  li        r0, 0
	  stb       r0, 0x4D(r30)
	  lbz       r0, -0x5F15(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x350
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0xC8(r3)
	  oris      r0, r0, 0x4
	  stw       r0, 0xC8(r3)

	.loc_0x350:
	  li        r3, 0
	  b         .loc_0x634

	.loc_0x358:
	  lis       r3, 0x803A
	  lwz       r5, 0x20(r30)
	  subi      r3, r3, 0x2848
	  lwz       r4, 0x300(r3)
	  addi      r31, r3, 0x300
	  lis       r3, 0x8889
	  subi      r0, r3, 0x7777
	  sub       r3, r4, r5
	  addi      r4, r3, 0x3C
	  mulhw     r0, r0, r4
	  add       r0, r0, r4
	  srawi     r0, r0, 0x5
	  rlwinm    r3,r0,1,31,31
	  add       r0, r0, r3
	  mulli     r0, r0, 0x3C
	  sub.      r3, r4, r0
	  ble-      .loc_0x420
	  lwz       r0, 0x24(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x420
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x7088(r2)
	  stw       r0, 0x14C(r1)
	  lis       r0, 0x4330
	  lis       r4, 0x802B
	  lfs       f0, -0x7064(r2)
	  stw       r0, 0x148(r1)
	  lis       r3, 0x802B
	  lha       r6, 0x30(r30)
	  lfd       f1, 0x148(r1)
	  subi      r4, r4, 0x3064
	  lwz       r5, 0xC(r30)
	  addi      r0, r3, 0x10D8
	  fsubs     f1, f1, f2
	  stw       r4, 0x70(r1)
	  addi      r4, r1, 0x70
	  fdivs     f0, f1, f0
	  stw       r5, 0x74(r1)
	  stw       r0, 0x70(r1)
	  stw       r6, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  li        r0, 0
	  stw       r3, 0x20(r30)
	  stw       r0, 0x24(r30)

	.loc_0x420:
	  lwz       r4, 0x18(r30)
	  addi      r3, r1, 0xFC
	  lha       r5, 0x30(r30)
	  bl        -0xF524
	  lwz       r4, 0xC(r30)
	  addi      r3, r1, 0xE4
	  lfs       f4, 0x104(r1)
	  addi      r4, r4, 0x94
	  lfs       f3, 0x100(r1)
	  lfs       f0, 0x8(r4)
	  lfs       f2, 0x4(r4)
	  lfs       f1, 0xFC(r1)
	  fsubs     f31, f4, f0
	  lfs       f0, 0x0(r4)
	  fsubs     f30, f3, f2
	  lwz       r4, 0x18(r30)
	  fsubs     f26, f1, f0
	  bl        -0xF348
	  lfs       f1, 0xE4(r1)
	  addi      r3, r1, 0xD8
	  lfs       f0, 0xE8(r1)
	  stfs      f1, 0x124(r1)
	  stfs      f0, 0x128(r1)
	  lfs       f0, 0xEC(r1)
	  stfs      f0, 0x12C(r1)
	  lwz       r4, 0x18(r30)
	  bl        -0xF30C
	  lfs       f1, 0x124(r1)
	  lfs       f0, 0x128(r1)
	  fmuls     f1, f26, f1
	  lfs       f2, 0x12C(r1)
	  fmuls     f0, f30, f0
	  lfs       f28, 0xD8(r1)
	  fmuls     f3, f31, f2
	  fadds     f1, f1, f0
	  lfs       f29, 0xDC(r1)
	  fmuls     f2, f26, f28
	  lfs       f27, 0xE0(r1)
	  lfs       f0, -0x705C(r2)
	  fadds     f4, f3, f1
	  fmuls     f1, f30, f29
	  fmuls     f3, f31, f27
	  fabs      f4, f4
	  fadds     f1, f2, f1
	  fcmpo     cr0, f4, f0
	  fadds     f30, f3, f1
	  ble-      .loc_0x4F0
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0xC8(r3)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r3)
	  b         .loc_0x500

	.loc_0x4F0:
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0xC8(r3)
	  oris      r0, r0, 0x4
	  stw       r0, 0xC8(r3)

	.loc_0x500:
	  fabs      f26, f30
	  lwz       r3, 0x18(r30)
	  bl        -0xF228
	  lfs       f0, -0x7078(r2)
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f26, f0
	  ble-      .loc_0x56C
	  li        r0, 0
	  cmplwi    r30, 0
	  sth       r0, 0x1C(r30)
	  mr        r29, r30
	  beq-      .loc_0x534
	  lwz       r29, 0x14(r30)

	.loc_0x534:
	  addi      r3, r1, 0x64
	  li        r4, 0x2
	  bl        0x70FDC
	  addi      r31, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x5C
	  li        r4, 0x2
	  bl        0x70FFC
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x1CA38
	  li        r3, 0
	  b         .loc_0x634

	.loc_0x56C:
	  lwz       r3, 0x18(r30)
	  bl        -0xF290
	  lfs       f0, -0x7058(r2)
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f26, f0
	  ble-      .loc_0x618
	  lfs       f0, -0x7098(r2)
	  fcmpo     cr0, f30, f0
	  bge-      .loc_0x5A0
	  lfs       f0, -0x7074(r2)
	  fmuls     f28, f28, f0
	  fmuls     f29, f29, f0
	  fmuls     f27, f27, f0

	.loc_0x5A0:
	  lfs       f0, 0x124(r1)
	  lfs       f1, 0x128(r1)
	  fadds     f0, f0, f28
	  lfs       f2, 0x12C(r1)
	  fadds     f3, f1, f29
	  fadds     f1, f2, f27
	  stfs      f0, 0x124(r1)
	  stfs      f3, 0x128(r1)
	  stfs      f1, 0x12C(r1)
	  lfs       f1, 0x124(r1)
	  lfs       f0, 0x128(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x12C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA03E4
	  lfs       f0, -0x7098(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x618
	  lfs       f0, 0x124(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x124(r1)
	  lfs       f0, 0x128(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x128(r1)
	  lfs       f0, 0x12C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x12C(r1)

	.loc_0x618:
	  lwz       r3, 0x18(r30)
	  bl        -0xF344
	  lwz       r3, 0xC(r30)
	  addi      r4, r1, 0x124
	  lfs       f1, -0x7078(r2)
	  bl        0x1DD6C
	  li        r3, 0

	.loc_0x634:
	  lwz       r0, 0x194(r1)
	  lfd       f31, 0x188(r1)
	  lfd       f30, 0x180(r1)
	  lfd       f29, 0x178(r1)
	  lfd       f28, 0x170(r1)
	  lfd       f27, 0x168(r1)
	  lfd       f26, 0x160(r1)
	  lwz       r31, 0x15C(r1)
	  lwz       r30, 0x158(r1)
	  lwz       r29, 0x154(r1)
	  addi      r1, r1, 0x190
	  mtlr      r0
	  blr
	*/
}
