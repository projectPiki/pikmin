#include "AIPerf.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "EffectMgr.h"
#include "Interactions.h"
#include "PikiAI.h"
#include "WorkObject.h"
#include "bugprint.h"
#include "gameflow.h"
#include "zen/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("aiBridge")

/**
 * @todo: Documentation
 */
ActBridge::ActBridge(Piki* piki)
    : Action(piki, true)
{
	setName("Bridge");
	mBridge = nullptr;
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void ActBridge::dump()
{
	const char* stateNames[] = { "approach", "detour", "go", "work" };
	PRINT("state : %s  bridge stage : %d\n", stateNames[mState], mStageID);
	Vector3f stagePos = mBridge->getStagePos(mStageID);
	Vector3f sep      = stagePos - mPiki->mSRT.t;
	Vector3f zVec     = mBridge->getBridgeZVec();
	f32 zdist         = sep.DP(zVec);
	PRINT("zdist is %.1f\n", zdist);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00006C
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000B8
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

/**
 * @todo: Documentation
 */
int ActBridge::exec()
{
	if (!mBridge) {
		PRINT("no bridge!\n");
		mPiki->mEmotion = PikiEmotion::Sad;
		BUGPRINT("exe:no bridge!");
		return ACTOUT_Fail;
	}

	if (mBridge->mDoUseJointSegments) {
		switch (mState) {
		case STATE_Approach:
		{
			return newExeApproach();
		}
		case STATE_Go:
		{
			return newExeGo();
		}
		case STATE_Work:
		{
			return newExeWork();
		}
		default:
		{
			return ACTOUT_Continue;
		}
		}
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C
 */
void ActBridge::initDetour()
{
	mState = STATE_Detour;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
int ActBridge::exeDetour()
{
	TRAP_UNIMPLEMENTED;
	f32 x;
	f32 z;
	mBridge->getBridgePos(mPiki->mSRT.t, x, z);
	f32 xAbs = absF(x);
	if (mBridge->getStageWidth() * 0.5f > xAbs) {
		Vector3f dir = mBridge->getBridgeXVec();
		if (mPiki) { // not sure what this is
			dir.multiply(-1.0f);
		}
		mPiki->setSpeed(0.7f, dir);
	} else {
		initApproach();
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActBridge::procWallMsg(Piki* piki, MsgWall* msg)
{
	mBridgeWallNormal = msg->mWallPlane->mNormal;
	_33               = 8;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000134
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
	mPiki->disableGravity();
	PRINT("climb vel (%.1f %.1f %.1f)\n", mClimbingVelocity.x, mClimbingVelocity.y, mClimbingVelocity.z);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000068
 */
int ActBridge::exeClimb()
{
	if (mClimbingBridge) {
		PRINT("climbing (%.1f %.1f %.1f)\n", mClimbingVelocity.x, mClimbingVelocity.y, mClimbingVelocity.z);
		mPiki->setSpeed(1.0f, mClimbingVelocity);
	} else {
		initApproach();
		mPiki->enableGravity();
	}
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000080
 */
void ActBridge::initApproach()
{
	mState          = STATE_Approach;
	mClimbingBridge = false;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000328
 */
int ActBridge::exeApproach()
{
	TRAP_UNIMPLEMENTED;
	if (!mBridge) {
		mPiki->mEmotion = PikiEmotion::Sad;
		return ACTOUT_Fail;
	}

	if (collideBridgeSurface()) {
		PRINT("INIT GO ************************\n");
		initGo();
		return ACTOUT_Continue;
	}

	Vector3f dir = mBridge->mSRT.t - mPiki->mSRT.t;
	f32 dist     = dir.normalise();
	if (dist < 300.0f) {
		f32 x;
		f32 z;
		mBridge->getBridgePos(mPiki->mSRT.t, x, z);
		f32 xAbs = absF(x);
		if (mBridge->getStageWidth() * 0.5f > xAbs) {
			Vector3f stagePos = mBridge->getStagePos(mStageID);
			stagePos          = stagePos - mPiki->mSRT.t;
			Vector3f zVec     = mBridge->getBridgeZVec();
			f32 dotZ          = stagePos.DP(zVec);
			if (-mBridge->getStageDepth() > dotZ) {
				initDetour();
				return ACTOUT_Continue;
			}

			dir = zVec;
			mPiki->setSpeed(0.7f, dir);
		} else {
			Vector3f dir2;
			if (z > -10.0f) {
				dir2 = mBridge->getBridgeZVec();
				dir2.multiply(-1.0f);
			} else {
				dir2 = mBridge->getBridgeXVec();
				dir2.multiply(-1.0f);
			}
			mPiki->setSpeed(0.7f, dir2);
		}
	} else {
		mPiki->setSpeed(0.7f, dir);
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
void ActBridge::initGo()
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0003F0
 */
int ActBridge::exeGo()
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000E8
 */
void ActBridge::initWork()
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000414
 */
int ActBridge::exeWork()
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A8 (Matching by size)
 */
void ActBridge::doWork(int mins)
{
	InteractBuild build(mPiki, mStageID, mins / 60.0f);
	mBridge->stimulate(build);
	mStartWorkTime = gameflow.mWorldClock.mCurrentGameMinute;
	mIsAttackReady = FALSE;
}

/**
 * @todo: Documentation
 */
void ActBridge::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	STACK_PAD_VAR(1);
	switch (event.mEventType) {
	case KEY_LoopEnd:
	{
		mIsAttackReady = TRUE;
		break;
	}
	case KEY_PlayEffect:
	{
		if (mPiki->aiCullable() && (AIPerf::optLevel <= 0 || mPiki->mOptUpdateContext.updatable())) {
			effectMgr->create(EffectMgr::EFF_Piki_WorkCloud, mPiki->mEffectPos, nullptr, nullptr);
		}
		break;
	}
	case KEY_Finished:
	{
		mAnimationFinished = true;
		break;
	}
	}
}

/**
 * @todo: Documentation
 */
void ActBridge::cleanup()
{
	mPiki->resetCreatureFlag(CF_DisableMovement);
	mPiki->enableGravity();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00007C
 */
void ActBridge::newInitApproach()
{
	mState = STATE_Approach;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
	PRINT("approach init\n");
}

/**
 * @todo: Documentation
 */
int ActBridge::newExeApproach()
{
	if (!mBridge) {
		BUGPRINT("app bri fail");
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
		mBridge->getBridgePos(mPiki->mSRT.t, bridgePosX, bridgePosY);
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
				mBridge->getStagePos(mStageID);
				// stagePos = stagePos - mActor->mSRT.t;
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

/**
 * @todo: Documentation
 */
void ActBridge::newInitGo()
{
	mState = STATE_Go;
	if (mBridge) {
		mStageID           = mBridge->getFirstUnfinishedStage();
		mRandomBridgeWidth = gsys->getRand(1.0f) - 0.5f;
	} else {
		mStageID = -1;
	}

	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk, this), PaniMotionInfo(PIKIANIM_Walk));
}

/**
 * @todo: Documentation
 */
int ActBridge::newExeGo()
{
	if (mStageID == -1) {
		PRINT("stage = -1\n");
		BUGPRINT("go : stage=-1 suc");
		return ACTOUT_Success;
	}

	if (!mBridge) {
		PRINT("failed \n");
		BUGPRINT("no bridge fail");
		mPiki->mEmotion = PikiEmotion::Sad;
		PRINT("NO BRIDGE!\n");
		return ACTOUT_Fail;
	}

	STACK_PAD_STRUCT(3);
	STACK_PAD_TERNARY(this, 1);
	if (mBridge->isStageFinished(mStageID)) {
		PRINT("stage %d is finished\n", mStageID);
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

	Vector3f stagePos = mBridge->getStagePos(mStageID);
	Vector3f xVec     = mBridge->getBridgeXVec();
	xVec.multiply(mRandomBridgeWidth * mBridge->getStageWidth());
	stagePos.add(xVec);

	Vector3f direction = stagePos - mPiki->mSRT.t;
	mBridge->getBridgeZVec();

	direction.normalise();

	mPiki->setSpeed(0.70f, direction);
	STACK_PAD_VAR(1);
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActBridge::newInitWork()
{
	mState          = STATE_Work;
	mStartWorkTime  = gameflow.mWorldClock.mCurrentGameMinute;
	mIsAttackReady  = FALSE;
	mCollisionCount = 0;
	_2A             = 0;

	if (mActionCounter > 0) {
		return;
	}

	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
	mAnimationFinished = false;
	if (AIPerf::bridgeFast) {
		mPiki->setCreatureFlag(CF_DisableMovement);
	}
}

/**
 * @todo: Documentation
 */
int ActBridge::newExeWork()
{
	// If the bridge is finished, continue
	if (mBridge->isStageFinished(mStageID)) {
		PRINT("**** STAGE IS FINISHED *** WORK\n");
		BUGPRINT("stage fin! work->go");
		newInitGo();
		releasePiki();
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
			releasePiki();
			return ACTOUT_Continue;
		}
	}

	if (!mBridge->workable(mPiki->mSRT.t)) {
		mPiki->mEmotion = PikiEmotion::Sad;
		releasePiki();
		return ACTOUT_Fail;
	}

	if (mActionCounter > 0) {
		mActionCounter--;
		if (mActionCounter == 0) {
			newInitWork();
		}
		return ACTOUT_Continue;
	}

	int timeSinceLastWork = (gameflow.mWorldClock.mCurrentGameMinute - mStartWorkTime + 60) % 60;
	if (timeSinceLastWork > 0 && mIsAttackReady) {
		doWork(timeSinceLastWork);
	}

	Vector3f stagePos(mBridge->getStagePos(mStageID));
	STACK_PAD_STRUCT(3);
	Vector3f sep;
	sep.sub2(stagePos, mPiki->mSRT.t);
	Vector3f zVec(mBridge->getBridgeZVec());
	STACK_PAD_VAR(4);
	Vector3f xVec(mBridge->getBridgeXVec());
	f32 zDist = sep.DP(zVec);
	f32 xDist = sep.DP(xVec);

	if (absF(zDist) > 24.0f) {
		releasePiki();
	} else {
		mPiki->setCreatureFlag(CF_DisableMovement);
	}

	if (absF(xDist) > 0.5f * mBridge->getStageWidth()) {
		PRINT("work : x is out of range\n");
		newInitApproach();
		return ACTOUT_Continue;
	}

	if (absF(xDist) > 0.3f * mBridge->getStageWidth()) {
		if (xDist < 0.0f) {
			xVec.multiply(-1.0f);
		}
		zVec = zVec + xVec;
		zVec.normalise();
	}
	mBridge->getStageDepth();
	mPiki->setSpeed(0.5f, zVec);
	STACK_PAD_INLINE(2);
	return ACTOUT_Continue;
}
