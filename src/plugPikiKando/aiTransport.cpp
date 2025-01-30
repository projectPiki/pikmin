#include "PikiAI.h"
#include "Pellet.h"
#include "PikiMgr.h"
#include "PelletState.h"
#include "AIConstant.h"
#include "Stickers.h"
#include "MapCode.h"
#include "UtilityKando.h"
#include "AIPerf.h"
#include "Graphics.h"
#include "GoalItem.h"
#include "teki.h"
#include "Font.h"
#include "UfoItem.h"
#include "FlowController.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "Navi.h"
#include "KMath.h"
#include "MoviePlayer.h"
#include "GameCoreSection.h"
#include "Interface.h"
#include "PlayerState.h"
#include "zen/Math.h"
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
DEFINE_PRINT("Transport")

/*
 * --INFO--
 * Address:	800AEC80
 * Size:	000290
 */
void ActTransport::turnOver()
{
	if (!isStickLeader()) {
		return;
	}

	Pellet* pellet = mPellet.getPtr();
	Stickers attachedPikis(pellet);
	Iterator iter(&attachedPikis);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck->isPiki()) {
			Piki* piki           = static_cast<Piki*>(stuck);
			ActTransport* action = static_cast<ActTransport*>(piki->mActiveAction->getCurrAction());
			action->mState       = STATE_Wait;
			piki->endStickObject();
			piki->mPikiAnimMgr.finishMotion(action);
			iter.dec();
		}
	}

	Vector3f torqueDir = mPiki->mPosition - pellet->mPosition;
	torqueDir.normalise();
	torqueDir.multiply(pellet->getBottomRadius());

	Vector3f upwardForce(0.0f, 400.0f * pellet->getBottomRadius() / 20.0f, 0.0f);
	torqueDir.CP(upwardForce);

	pellet->mAngularMomentum = pellet->mAngularMomentum + torqueDir;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void ActTransport::initWait()
{
	Pellet* pel = mPellet.getPtr();
	mState      = STATE_Wait;
	mPiki->startLook(&pel->mPosition);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait), PaniMotionInfo(PIKIANIM_Wait));
	mWaitTimer = 3.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
int ActTransport::exeWait()
{
	Pellet* pel = mPellet.getPtr();
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (pel->getGroundFlag() == 0x55) {
		mStateProgress = 0;
		mState         = STATE_Go;
	}
	mWaitTimer -= gsys->getFrameTime();
	if (mWaitTimer < 0.0f) {
		mStateProgress = 0;
		mState         = STATE_Go;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AEF10
 * Size:	000150
 */
bool ActTransport::isStickLeader()
{
	Pellet* pel = mPellet.getPtr();
	if (!pel) {
		return false;
	}

	Stickers stuckList(pel);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki->isPiki()) {
			return piki == mPiki;
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	800AF060
 * Size:	000190
 */
f32 ActTransport::getCarriers()
{
	u32 badCompiler;
	Pellet* pel = mPellet.getPtr();
	if (pel) {
		Stickers stuckList(pel);
		u32 badCompiler2[3];
		Iterator iter(&stuckList);
		f32 carriers = 0.0f;
		CI_LOOP(iter)
		{
			Piki* piki = static_cast<Piki*>(*iter);
			if (piki->isPiki()) {
				carriers += 0.5f * piki->mHappa + 1.0f;
			}
		}
		return carriers;
	}
	return 0.0f;

	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
int ActTransport::getNumStickers()
{
	Pellet* pel = mPellet.getPtr();
	if (pel) {
		return pel->mCarrierCounter;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
int ActTransport::calcNumStickers()
{
	Pellet* pel = mPellet.getPtr();
	if (pel) {
		Stickers stuckList(pel);
		Iterator iter(&stuckList);
		int count = 0;
		CI_LOOP(iter)
		{
			Creature* piki = *iter;
			if (piki->isPiki()) {
				count++;
			}
		}

		return count;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	800AF1F0
 * Size:	0000F4
 */
ActTransport::ActTransport(Piki* piki)
    : Action(piki, true)
{
	setName("Transport");
	mPathIndex = -1;
}

/*
 * --INFO--
 * Address:	800AF2E4
 * Size:	000160
 */
Pellet* ActTransport::findPellet()
{
	Iterator iter(pelletMgr);
	f32 minDist           = 200.0f;
	Pellet* closestPellet = nullptr;
	CI_LOOP(iter)
	{
		Pellet* pellet = static_cast<Pellet*>(*iter);
		if (roughCull(pellet, mPiki, minDist)) {
			continue;
		}
		if (pellet->isFree()) {
			f32 dist = qdist2(pellet, mPiki);
			if (dist < minDist) {
				minDist       = dist;
				closestPellet = pellet;
			}
		}
	}

	return closestPellet;
}

/*
 * --INFO--
 * Address:	800AF444
 * Size:	000160
 */
void ActTransport::init(Creature* target)
{
	mPiki->mActionState = 1;
	if (!target) {
		target = findPellet();
	}

	if (target && target->mObjType == OBJTYPE_Pellet && target->isAlive()) {
		mPellet.set(static_cast<Pellet*>(target));
		if (mPellet.getPtr()->isUfoParts()) {
			mPiki->mActionState = 2;
		}
	} else {
		mPellet.reset();
	}

	mStateProgress    = 0;
	mState            = STATE_Go;
	mWaitTimer        = 3.0f;
	mFinishPutting    = 0;
	mIsLiftActionDone = 0;
	mGoal             = nullptr;
	setSlotIndex();
	mCanCarry = 0;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800AF5A4
 * Size:	00004C
 */
void ActTransport::setSlotIndex()
{
	Pellet* pel = mPellet.getPtr();
	if (pel) {
		mSlotIndex = pel->getRandomFreeSlotIndex();
	} else {
		mSlotIndex = -1;
	}
}

/*
 * --INFO--
 * Address:	800AF5F0
 * Size:	000194
 */
void ActTransport::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		mIsLiftActionDone = 1;
		break;
	case KEY_LoopEnd:
		if (mState == STATE_Lift) {
			Pellet* pel  = mPellet.getPtr();
			int numStick = getNumStickers();
			if (pel && numStick < pel->mConfig->mCarryMinPikis()) {
				mLiftRetryCount--;
				if (mLiftRetryCount < 0) {
					mPiki->mPikiAnimMgr.finishMotion(this);
				}
			}
		}
		break;
	case KEY_Finished:
		if (mState == STATE_Put) {
			mFinishPutting = 1;
			break;
		}
		if (mState == STATE_Lift) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_PickLoop, this), PaniMotionInfo(PIKIANIM_PickLoop));
			mIsLiftActionDone = 0;
			mLiftRetryCount   = int(randFloat(3.0f)) + 5;
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void ActTransport::initJump()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mVelocity.y = 0.5f * AIConstant::_instance->mConstants.mGravity();
	mJumpRetryTimer    = 0;
	mState             = STATE_Jump;
}

/*
 * --INFO--
 * Address:	800AF784
 * Size:	0004F0
 */
int ActTransport::execJump()
{
	Pellet* pel = mPellet.getPtr();
	if (mSlotIndex == -1 || !pel) {
		PRINT("JUMP FAILED * PEL IS FULL OR NO PEL\n");
		return ACTOUT_Fail;
	}

	if (!pel->isAlive()) {
		PRINT("JUMP FAILED * PEL IS NOT ALIVE\n");
		return ACTOUT_Fail;
	}

	Vector3f slotPos = pel->getSlotGlobalPos(mSlotIndex, 0.0f);
	Vector3f slotDir = slotPos - mPiki->mPosition;
	f32 slotDistXZ   = speedy_sqrtf(slotDir.x * slotDir.x + slotDir.z * slotDir.z);
	f32 slotHeight   = slotDir.y;
	f32 dist         = slotDir.normalise() - pel->getCentreSize();

	if (slotDistXZ > 60.0f) {
		mStateProgress = 0;
		mState         = STATE_Go;
		return ACTOUT_Continue;
	}

	if (zen::Abs(slotHeight) <= 8.8f) {
		if (!pel->isSlotFree(mSlotIndex)) {
			int oldSlot = mSlotIndex;
			mSlotIndex  = pel->getNearestFreeSlotIndex(mPiki->mPosition);
			if (oldSlot == mSlotIndex) {
				mPiki->mEmotion = 1;
				return ACTOUT_Fail;
			}
			if (mSlotIndex == -1) {
				mPiki->mEmotion = 1;
				return ACTOUT_Fail;
			}

			mStateProgress = 0;
			mState         = STATE_Go;
			mWaitTimer     = 3.0f;
			return ACTOUT_Continue;
		}

		mPiki->mFaceDirection = roundAng(atan2f(slotDir.x, slotDir.z));
		mPiki->mRotation.y    = mPiki->mFaceDirection;
		mState                = STATE_Lift;

		mPiki->startMotion(PaniMotionInfo(PIKIANIM_PickLoop, this), PaniMotionInfo(PIKIANIM_PickLoop));
		mPiki->enableMotionBlend();
		PRINT("start try sound \n");
		pel->setTrySound(true);

		Vector3f pelNorm(0.0f, pel->getCylinderHeight(), 0.0f);
		mIsLiftActionDone = 0;
		mLiftRetryCount   = int(randFloat(3.0f)) + 5;
		mPiki->startStickObject(pel, nullptr, mSlotIndex, 0.0f);

		seSystem->playPikiSound(SEF_PIKI_HANG, mPiki->mPosition);
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);

		int numStickers = calcNumStickers();
		int minWeight   = pel->mConfig->mCarryMinPikis();
		Vector3f carryInfoPos(pel->mPosition);
		carryInfoPos.y += 5.0f + pel->getCylinderHeight();

		pel->mLifeGauge.countOn(carryInfoPos, numStickers, minWeight);
		return ACTOUT_Continue;
	}

	if (mPiki->mFloorTri) {
		mJumpRetryTimer++;
		if (mJumpRetryTimer > 6) {
			mPiki->mVelocity.y = 0.5f * AIConstant::_instance->mConstants.mGravity();
			mJumpRetryTimer    = 0;
		}
	} else {
		mJumpRetryTimer = 0;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AFC74
 * Size:	000740
 */
bool ActTransport::gotoLiftPos()
{
	Pellet* pellet = mPellet.getPtr();
	if (mSlotIndex == -1 || !pellet) {
		return false;
	}

	if (!pellet->isAlive()) {
		return false;
	}

	Vector3f targetSlotPos = pellet->getSlotGlobalPos(mSlotIndex, 0.0f);
	Vector3f slotDirection = targetSlotPos - mPiki->mPosition;
	f32 horizontalDist     = speedy_sqrtf(slotDirection.x * slotDirection.x + slotDirection.z * slotDirection.z);
	f32 verticalDist       = slotDirection.y;
	f32 totalDist          = slotDirection.normalise();
	f32 distToCentre       = totalDist - pellet->getCentreSize();

	if (horizontalDist < 100.0f && ++mStateProgress >= 60) {
		int previousSlot = mSlotIndex;
		mSlotIndex       = pellet->getNearestFreeSlotIndex(mPiki->mPosition);
		if (previousSlot == mSlotIndex) {
			mPiki->mEmotion = 1;
			return false;
		}

		if (mSlotIndex == -1) {
			mPiki->mEmotion = 1;
			return false;
		}

		mStateProgress = 0;
		mState         = STATE_Go;
		mWaitTimer     = 3.0f;
		return true;
	}

	if (horizontalDist > 6.0f) {
		mPiki->setSpeed(1.0f, slotDirection);
		return true;
	}

	if (horizontalDist < 6.0f && verticalDist >= -8.0f) {
		if (verticalDist >= 8.0f) {
			initJump();
			return true;
		}

		if (!pellet->isSlotFree(mSlotIndex)) {
			mSlotIndex = pellet->getNearestFreeSlotIndex(mPiki->mPosition);
			if (mSlotIndex == -1) {
				mPiki->mEmotion = 1;
				return false;
			}

			mStateProgress = 0;
			mState         = STATE_Go;
			mWaitTimer     = 3.0f;
			return true;
		}

		mPiki->mFaceDirection = roundAng(atan2f(slotDirection.x, slotDirection.z));
		mPiki->mRotation.y    = mPiki->mFaceDirection;
		mState                = STATE_Lift;
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_PickLoop, this), PaniMotionInfo(PIKIANIM_PickLoop));
		mPiki->enableMotionBlend();
		if (pellet->isCreatureFlag(CF_IsPositionFixed)) {
			PRINT("start try sound \n");
			pellet->setTrySound(true);
		} else {
			PRINT("*** OMIT try sound \n");
		}

		Vector3f pelNorm(0.0f, pellet->getCylinderHeight(), 0.0f);
		mIsLiftActionDone = 0;
		mLiftRetryCount   = int(randFloat(3.0f)) + 5;
		mPiki->startStickObject(pellet, nullptr, mSlotIndex, 0.0f);
		seSystem->playPikiSound(SEF_PIKI_HANG, mPiki->mPosition);
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);

		int currentCarriers  = calcNumStickers();
		int requiredCarriers = pellet->mConfig->mCarryMinPikis();
		Vector3f carryInfoPos(pellet->mPosition);
		carryInfoPos.y += 5.0f + pellet->getCylinderHeight();
		pellet->mLifeGauge.countOn(carryInfoPos, currentCarriers, requiredCarriers);
		return true;
	}

	Vector3f centreDir = pellet->getCentre() - mPiki->mPosition;
	f32 centreDist     = centreDir.normalise();
	Vector3f orthoDir(slotDirection);
	orthoDir.CP(centreDir);

	if (centreDist < totalDist) {
		Vector3f pikiMoveDir(-slotDirection.z, 0.0f, slotDirection.x);
		if (orthoDir.y > 0.0f) {
			pikiMoveDir.multiply(-1.0f);
		}

		mPiki->setSpeed(0.2f, pikiMoveDir);
		mWaitTimer -= gsys->getFrameTime();

		if (mWaitTimer < 0.0f) {
			mSlotIndex = pellet->getNearestFreeSlotIndex(mPiki->mPosition);
			if (mSlotIndex == -1) {
				mPiki->mEmotion = 1;
				return false;
			}

			mStateProgress = 0;
			mState         = STATE_Go;
			mWaitTimer     = 3.0f;
			return true;
		}
		return true;
	}

	mPiki->setSpeed(0.2f, slotDirection);
	return true;
}

/*
 * --INFO--
 * Address:	800B03B4
 * Size:	000664
 */
void ActTransport::doLift()
{
	Pellet* pel = mPellet.getPtr();
	Stickers stuckList(pel);
	int numStickers = getNumStickers();
	int count       = 0;
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck->isPiki()) {
			Piki* piki = static_cast<Piki*>(stuck);
			if (piki->mMode == PikiMode::TransportMode) {
				ActTransport* action = static_cast<ActTransport*>(piki->mActiveAction->getCurrAction());
				if (action->mIsLiftActionDone) {
					count++;
				}
			}
		}
	}

	if (mIsLiftActionDone) {

		if (count < pel->mConfig->mCarryMinPikis()) {
			return;
		}

		if (SmartTurnOver && pel->getGroundFlag() != 0x55) {
			turnOver();
			return;
		}

		if (isStickLeader()) {
			decideGoal(pel);
			// this isn't in the DLL, but the asm is so dumb it has to be something like this
			// it also fixes the stack, so.
			bool landOnly       = !!doLandOnly();
			WayPoint* nearestWP = nullptr;
			WayPoint* wpA;
			WayPoint* wpB;
			bool fxCheck = false;
			if (pel->mWaterFxTimer) {
				fxCheck = true;
			}
			PRINT("** NEAREST EDGE AVOID OFF =================\n");
			routeMgr->findNearestEdgeAvoidOff(&wpA, &wpB, 'test', mPiki->mPosition, landOnly, false, fxCheck);

			if (wpA && wpB) {
				PRINT("** FIND NEAREST EDGE %d and %d\n", wpA->mIndex, wpB->mIndex);
			}

			if (wpA && wpB) {
				Vector3f sepA = wpA->mPosition - mPiki->mPosition;
				Vector3f sepB = wpB->mPosition - mPiki->mPosition;
				if (sepA.length() > sepB.length()) {
					nearestWP = wpB;
				} else {
					nearestWP = wpA;
				}
			} else {
				PRINT("gakkari desu ...\n");
				nearestWP = routeMgr->findNearestWayPoint('test', mPiki->mPosition, landOnly);
			}

			int idx       = nearestWP->mIndex;
			int goalWPIdx = mGoal->getRouteIndex();
			int maxNumWP  = routeMgr->getNumWayPoints('test') - 1;
			PRINT("PATHFINDING : %d ==> %d\n", idx, goalWPIdx);
			if (idx < 0 || idx > maxNumWP || goalWPIdx < 0 || goalWPIdx > maxNumWP) {
				ERROR("sorry");
			}
			PRINT("start find route\n");
			if (landOnly) {
				PathFinder::setMode(1);
			}

			int routePoints = mPiki->findRoute(idx, goalWPIdx, false, false);
			mNumRoutePoints = routePoints;
			PRINT("numWayPoints = %d\n", routePoints);
			PRINT("done\n");
			if (routePoints == 0) {
				PRINT("SECOND TRY START !!!\n");
				routePoints     = mPiki->findRoute(idx, goalWPIdx, true, false);
				mNumRoutePoints = routePoints;
				if (routePoints == 0) {
					if (landOnly) {
						PRINT("THIRD TRY START !!!\n");
						PathFinder::clearMode();
						routePoints     = mPiki->findRoute(idx, goalWPIdx, true, false);
						mNumRoutePoints = routePoints;
					}

					if (routePoints == 0) {
						PRINT("end of abusan!");
						mState = STATE_Put;
						pel->mVelocity.set(0.0f, 0.0f, 0.0f);
						mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
						mPiki->mPikiAnimMgr.finishMotion(this);
						mPiki->endStickObject();
						return;
					}
				}
			}
			if (landOnly) {
				PathFinder::clearMode();
			}
			mCanCarry    = 1;
			mPathIndex   = 0;
			mGoalWPIndex = goalWPIdx;
			pel->startPick();
			mPiki->playEventSound(pel, SE_LIFT_MOVE);
			crInit();
		}

		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick), PaniMotionInfo(PIKIANIM_Pick));
		mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 11.0f;
		mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 11.0f;
		mPiki->enableMotionBlend();
		mState = STATE_Move;
	} else {
		pel->getPickOffset();
	}
}

/*
 * --INFO--
 * Address:	800B0A18
 * Size:	000168
 */
bool ActTransport::useWaterRoute()
{
	Pellet* pel      = mPellet.getPtr();
	CollTriInfo* tri = pel->mFloorTri;
	if (tri && MapCode::getAttribute(tri) == ATTR_Water) {
		return true;
	}

	bool onlyBlueCarry = true;
	Stickers stuckList(pel);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* stuck = *iter;
		if (stuck->isPiki()) {
			Piki* piki = static_cast<Piki*>(stuck);
			if (piki->mColor != Blue) {
				onlyBlueCarry = false;
				break;
			}
		}
	}

	return onlyBlueCarry;
}

/*
 * --INFO--
 * Address:	800B0B80
 * Size:	0008B4
 */
int ActTransport::exec()
{
	Pellet* pel = mPellet.getPtr();
	if (pel) {
		if (!pel->isVisible()) {
			if (pel->isUfoParts()) {
				if (pel->getState() == PELSTATE_Goal) {
					mPiki->mEmotion          = 9;
					mPiki->mCarryingShipPart = pel;
				} else {
					mPiki->mEmotion = 1;
				}
			} else if (pel->getState() == PELSTATE_Goal) {
				mPiki->mEmotion          = 4;
				mPiki->mCarryingShipPart = pel;
			} else {
				mPiki->mEmotion = 1;
			}
			return ACTOUT_Fail;
		}
	} else {
		PRINT("target is NULL!\n");
		mPiki->mEmotion = 7;
		return ACTOUT_Fail;
	}

	switch (mState) {
	case STATE_Wait:
		return exeWait();

	case STATE_Go:
		if (gotoLiftPos()) {
			break;
		}

		if (mPellet.isNull()) { // lol why even check
			return ACTOUT_Fail;
		}
		return ACTOUT_Fail;

	case STATE_Jump:
		return execJump();

	case STATE_Lift:
		doLift();
		break;

	case STATE_Goal: {
		Stickers stuckList(pel);
		int numStickers = getNumStickers();
		int minWeight   = pel->mConfig->mCarryMinPikis();
		if (numStickers < minWeight) {
			PRINT("小人数!!!\n"); // 'small group!!!' lol
			mState = STATE_Put;
			pel->mVelocity.set(0.0f, 0.0f, 0.0f);
			mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
			mPiki->mPikiAnimMgr.finishMotion(this);
			mPiki->endStickObject();
			return ACTOUT_Continue;
		}

		// sure
		mPiki->mVelocity.set(50.0f * (f32(numStickers) / f32(minWeight)), 0.0f, 0.0f);

		if (isStickLeader() && mPathIndex != -1) {
			if (!mGoal) {
				return ACTOUT_Fail;
			}

			if (mGoal && !pel) {
				PRINT("theGoal = %x target = %x\n", mGoal, pel);
				ERROR("mail to zamsi\n");
			}

			Vector3f goalDir = mGoal->getGoalPos() - pel->mPosition;
			f32 goalDistXZ   = speedy_sqrtf(goalDir.x * goalDir.x + goalDir.z * goalDir.z);
			if (goalDir.normalise() == 0.0f) {
				goalDir.set(0.0f, 0.0f, 0.0f);
			}
			mCanCarry = 1;

			if (goalDistXZ < 10.0f) {
				mState = STATE_Put;
				pel->mVelocity.set(0.0f, 0.0f, 0.0f);
				mPiki->mPikiAnimMgr.finishMotion(this);
				mPiki->endStickObject();
				mPiki->stopEventSound(pel, SE_LIFT_MOVE);

				if (pel->mObjType == OBJTYPE_Pellet) {

					Iterator iter(&stuckList);
					PRINT("begin itdec\n");
					Pellet* p2 = mPellet.getPtr();
					LoopChecker checker("carry-endstick", 5.0f);
					CI_LOOP(iter)
					{
						Creature* piki = *iter;
						if (piki && piki->isPiki()) {
							Piki* p = (Piki*)piki;
							p->endStickObject();
							iter.dec();
						}
						checker.update();
					}

					Pellet* p1 = mPellet.getPtr();

					PRINT("done\n");
					Pellet* pel2 = pel;
					pel2->finishPick();
					pel2->startGoal();
				}
				break;
			}

			if (!mPiki->mNavi) {
				PRINT("colorID = %d : playerID = (%d) navi =%x \n", mPiki->mColor, mPiki->mPlayerId, mPiki->mNavi);
				ERROR("Mr.Blending !\n");
			}

			f32 maxSpeed = 0.7f * pikiMgr->mPikiParms->mPikiParms.mMaxLeafMoveSpeed();
			f32 minSpeed = 0.5f * maxSpeed;
			int minCarry = mPellet.getPtr()->mConfig->mCarryMinPikis();
			int maxCarry = mPellet.getPtr()->mConfig->mCarryMaxPikis();
			f32 carriers = getCarriers();

			f32 speed = ((carriers + 1.0f - f32(minCarry)) / f32(maxCarry)) * (maxSpeed - minSpeed) + minSpeed;
			goalDir.y = 0.0f;
			goalDir.multiply(speed);
			pel->doCarry(mPiki, goalDir, numStickers);
			break;
		}

		if (!mPiki->isStickTo()) {
			mState = STATE_Put;
			pel->mVelocity.set(0.0f, 0.0f, 0.0f);
			mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
			mPiki->mPikiAnimMgr.finishMotion(this);
			mPiki->endStickObject();
		}

	} break;

	case STATE_Move:
		return moveToWayPoint();

	case STATE_Guru:
		return moveGuruGuru();

	case STATE_Put: {
		if (!mFinishPutting) {
			break;
		}

		Pellet* pel = mPellet.getPtr();
		if (pel->isUfoParts()) {
			if (pel->getState() == PELSTATE_Goal) {
				mPiki->mEmotion          = 9;
				mPiki->mCarryingShipPart = mPellet.getPtr();
			} else {
				mPiki->mEmotion = 1;
			}
		} else if (pel->getState() == PELSTATE_Goal) {
			mPiki->mEmotion          = 4;
			mPiki->mEmotion          = 4;
			mPiki->mCarryingShipPart = mPellet.getPtr();
		} else {
			mPiki->mEmotion = 1;
		}
		return ACTOUT_Success;
	}
	}

	return ACTOUT_Continue;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x170(r1)
	  stfd      f31, 0x168(r1)
	  stfd      f30, 0x160(r1)
	  stmw      r27, 0x14C(r1)
	  mr        r29, r3
	  lwz       r30, 0x18(r3)
	  cmplwi    r30, 0
	  beq-      .loc_0xE4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xF8
	  lwz       r3, 0x55C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x64
	  lwz       r0, 0x5C(r3)
	  subfic    r0, r0, 0x3
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  b         .loc_0x68

	.loc_0x64:
	  li        r0, 0

	.loc_0x68:
	  cmpwi     r0, 0
	  beq-      .loc_0xA8
	  mr        r3, r30
	  bl        -0x1B6BC
	  cmpwi     r3, 0x1
	  bne-      .loc_0x98
	  lwz       r3, 0xC(r29)
	  li        r0, 0x9
	  stb       r0, 0x400(r3)
	  lwz       r3, 0xC(r29)
	  stw       r30, 0x404(r3)
	  b         .loc_0xDC

	.loc_0x98:
	  lwz       r3, 0xC(r29)
	  li        r0, 0x1
	  stb       r0, 0x400(r3)
	  b         .loc_0xDC

	.loc_0xA8:
	  mr        r3, r30
	  bl        -0x1B6F4
	  cmpwi     r3, 0x1
	  bne-      .loc_0xD0
	  lwz       r3, 0xC(r29)
	  li        r0, 0x4
	  stb       r0, 0x400(r3)
	  lwz       r3, 0xC(r29)
	  stw       r30, 0x404(r3)
	  b         .loc_0xDC

	.loc_0xD0:
	  lwz       r3, 0xC(r29)
	  li        r0, 0x1
	  stb       r0, 0x400(r3)

	.loc_0xDC:
	  li        r3, 0x1
	  b         .loc_0x898

	.loc_0xE4:
	  lwz       r4, 0xC(r29)
	  li        r0, 0x7
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x898

	.loc_0xF8:
	  lhz       r0, 0x1C(r29)
	  cmplwi    r0, 0x7
	  bgt-      .loc_0x894
	  lis       r3, 0x802B
	  addi      r3, r3, 0x5EDC
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0xC(r29)
	  lwz       r4, 0x18(r29)
	  lfs       f0, -0x4DE0(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4DDC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4DD8(r13)
	  stfs      f0, 0x8(r3)
	  lbz       r0, 0x439(r4)
	  cmplwi    r0, 0x55
	  bne-      .loc_0x154
	  li        r0, 0
	  sth       r0, 0x40(r29)
	  sth       r0, 0x1C(r29)

	.loc_0x154:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xA4(r29)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA4(r29)
	  lfs       f1, 0xA4(r29)
	  lfs       f0, -0x7018(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x184
	  li        r0, 0
	  sth       r0, 0x40(r29)
	  sth       r0, 0x1C(r29)

	.loc_0x184:
	  li        r3, 0
	  b         .loc_0x898
	  mr        r3, r29
	  bl        -0x109C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x894
	  lwz       r0, 0x18(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x1B0
	  li        r3, 0x1
	  b         .loc_0x898

	.loc_0x1B0:
	  li        r3, 0x1
	  b         .loc_0x898
	  mr        r3, r29
	  bl        -0x15B8
	  b         .loc_0x898
	  mr        r3, r29
	  bl        -0x994
	  b         .loc_0x894
	  addi      r3, r1, 0x124
	  addi      r4, r30, 0
	  bl        -0x200D4
	  lwz       r3, 0x18(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x1F0
	  lhz       r31, 0x570(r3)
	  b         .loc_0x1F4

	.loc_0x1F0:
	  li        r31, 0

	.loc_0x1F4:
	  lwz       r3, 0x55C(r30)
	  lwz       r0, 0x7C(r3)
	  cmpw      r31, r0
	  bge-      .loc_0x26C
	  li        r0, 0x6
	  sth       r0, 0x1C(r29)
	  cmplwi    r29, 0
	  mr        r4, r29
	  lfs       f0, -0x4D70(r13)
	  stfs      f0, 0x70(r30)
	  lfs       f0, -0x4D6C(r13)
	  stfs      f0, 0x74(r30)
	  lfs       f0, -0x4D68(r13)
	  stfs      f0, 0x78(r30)
	  lwz       r3, 0xC(r29)
	  lfs       f0, -0x4D64(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x4D60(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4D5C(r13)
	  stfs      f0, 0x8(r3)
	  beq-      .loc_0x250
	  lwz       r4, 0x14(r29)

	.loc_0x250:
	  lwz       r3, 0xC(r29)
	  addi      r3, r3, 0x354
	  bl        0x6ECE8
	  lwz       r3, 0xC(r29)
	  bl        -0x20568
	  li        r3, 0
	  b         .loc_0x898

	.loc_0x26C:
	  xoris     r3, r31, 0x8000
	  lfd       f2, -0x6FE8(r2)
	  xoris     r0, r0, 0x8000
	  stw       r3, 0x144(r1)
	  lis       r3, 0x4330
	  lfs       f3, -0x6FB0(r2)
	  stw       r0, 0x13C(r1)
	  lwz       r4, 0xC(r29)
	  stw       r3, 0x140(r1)
	  stw       r3, 0x138(r1)
	  lfd       f1, 0x140(r1)
	  lfd       f0, 0x138(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fdivs     f0, f1, f0
	  fmuls     f0, f3, f0
	  stfsu     f0, 0x70(r4)
	  lfs       f0, -0x4D58(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4D54(r13)
	  stfs      f0, 0x8(r4)
	  lwz       r4, 0x18(r29)
	  cmplwi    r4, 0
	  bne-      .loc_0x2D4
	  li        r0, 0
	  b         .loc_0x3BC

	.loc_0x2D4:
	  addi      r3, r1, 0xAC
	  bl        -0x201D4
	  addi      r0, r1, 0xAC
	  stw       r0, 0xC0(r1)
	  li        r0, 0
	  addi      r3, r1, 0xBC
	  stw       r0, 0xC4(r1)
	  bl        -0x210B4
	  b         .loc_0x35C

	.loc_0x2F8:
	  lwz       r4, 0xBC(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x320
	  lwz       r3, 0xC0(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x334

	.loc_0x320:
	  lwz       r3, 0xC0(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x334:
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x354
	  lwz       r0, 0xC(r29)
	  sub       r0, r0, r3
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,5,31
	  b         .loc_0x3BC

	.loc_0x354:
	  addi      r3, r1, 0xBC
	  bl        -0x21240

	.loc_0x35C:
	  lwz       r3, 0xC0(r1)
	  lwz       r4, 0xBC(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x384
	  li        r0, 0x1
	  b         .loc_0x3B0

	.loc_0x384:
	  lwz       r3, 0xC0(r1)
	  lwz       r4, 0xBC(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x3AC
	  li        r0, 0x1
	  b         .loc_0x3B0

	.loc_0x3AC:
	  li        r0, 0

	.loc_0x3B0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2F8
	  li        r0, 0

	.loc_0x3BC:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x750
	  lwz       r0, 0xA8(r29)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x750
	  lwz       r4, 0xB0(r29)
	  cmplwi    r4, 0
	  bne-      .loc_0x3E4
	  li        r3, 0x1
	  b         .loc_0x898

	.loc_0x3E4:
	  beq-      .loc_0x3EC
	  cmplwi    r30, 0

	.loc_0x3EC:
	  lwz       r12, 0x0(r4)
	  addi      r28, r30, 0x94
	  addi      r3, r1, 0xDC
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xDC(r1)
	  lfs       f0, 0x0(r28)
	  lfs       f3, 0xE0(r1)
	  lfs       f2, 0x4(r28)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x8(r28)
	  lfs       f4, 0xE4(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x118(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x11C(r1)
	  stfs      f0, 0x120(r1)
	  lfs       f0, 0x118(r1)
	  lfs       f1, 0x120(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x7018(r2)
	  fmuls     f1, f1, f1
	  fadds     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x468
	  fsqrte    f0, f31
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f31, 0xA8(r1)

	.loc_0x468:
	  lfs       f1, 0x118(r1)
	  lfs       f0, 0x11C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x120(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA33C8
	  lfs       f0, -0x7018(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x4BC
	  lfs       f0, 0x118(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x118(r1)
	  lfs       f0, 0x11C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x11C(r1)
	  lfs       f0, 0x120(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x120(r1)

	.loc_0x4BC:
	  lfs       f0, -0x7018(r2)
	  fcmpu     cr0, f0, f1
	  bne-      .loc_0x4E0
	  lfs       f1, -0x4D50(r13)
	  lfs       f0, -0x4D4C(r13)
	  stfs      f1, 0x118(r1)
	  stfs      f0, 0x11C(r1)
	  lfs       f0, -0x4D48(r13)
	  stfs      f0, 0x120(r1)

	.loc_0x4E0:
	  li        r0, 0x1
	  stb       r0, 0xB4(r29)
	  lfs       f0, -0x6FAC(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x680
	  li        r0, 0x6
	  sth       r0, 0x1C(r29)
	  cmplwi    r29, 0
	  mr        r4, r29
	  lfs       f0, -0x4D44(r13)
	  stfs      f0, 0x70(r30)
	  lfs       f0, -0x4D40(r13)
	  stfs      f0, 0x74(r30)
	  lfs       f0, -0x4D3C(r13)
	  stfs      f0, 0x78(r30)
	  beq-      .loc_0x524
	  lwz       r4, 0x14(r29)

	.loc_0x524:
	  lwz       r3, 0xC(r29)
	  addi      r3, r3, 0x354
	  bl        0x6EA14
	  lwz       r3, 0xC(r29)
	  bl        -0x2083C
	  lwz       r3, 0xC(r29)
	  addi      r4, r30, 0
	  li        r5, 0xB9
	  bl        -0x26AD8
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0x34
	  bne-      .loc_0x894
	  lis       r3, 0x802B
	  lfs       f1, -0x6FD0(r2)
	  addi      r4, r3, 0x5ECC
	  addi      r28, r1, 0x124
	  addi      r3, r1, 0xFC
	  bl        0x65304
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x60C

	.loc_0x588:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x5AC
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C4

	.loc_0x5AC:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x5C4:
	  cmplwi    r3, 0
	  beq-      .loc_0x5E8
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x5E8
	  bl        -0x208E0
	  cmpwi     r29, 0
	  blt-      .loc_0x5E8
	  subi      r29, r29, 0x1

	.loc_0x5E8:
	  addi      r3, r1, 0xFC
	  bl        0x6528C
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x60C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x634
	  li        r0, 0x1
	  b         .loc_0x660

	.loc_0x634:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x65C
	  li        r0, 0x1
	  b         .loc_0x660

	.loc_0x65C:
	  li        r0, 0

	.loc_0x660:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x588
	  addi      r28, r30, 0
	  addi      r3, r28, 0
	  bl        -0x1B7A4
	  mr        r3, r28
	  bl        -0x1B72C
	  b         .loc_0x894

	.loc_0x680:
	  lwz       r3, 0xC(r29)
	  lwz       r0, 0x504(r3)
	  cmplwi    r0, 0
	  lwz       r5, 0x3068(r13)
	  mr        r3, r29
	  lwz       r4, 0x18(r29)
	  lwz       r5, 0x68(r5)
	  lwz       r6, 0x55C(r4)
	  lfs       f2, -0x6FA8(r2)
	  lfs       f1, 0x78(r5)
	  lfs       f0, -0x6FF0(r2)
	  fmuls     f31, f2, f1
	  lwz       r28, 0x7C(r6)
	  lwz       r27, 0x8C(r6)
	  fmuls     f30, f0, f31
	  bl        -0x21DC
	  xoris     r0, r28, 0x8000
	  lfs       f2, -0x6FF4(r2)
	  stw       r0, 0x13C(r1)
	  lis       r3, 0x4330
	  xoris     r0, r27, 0x8000
	  lfd       f4, -0x6FE8(r2)
	  stw       r3, 0x138(r1)
	  lfs       f0, -0x7018(r2)
	  fadds     f5, f2, f1
	  stw       r0, 0x144(r1)
	  fsubs     f1, f31, f30
	  lfd       f2, 0x138(r1)
	  stw       r3, 0x140(r1)
	  fsubs     f3, f2, f4
	  mr        r3, r30
	  lfd       f2, 0x140(r1)
	  addi      r5, r1, 0x118
	  stfs      f0, 0x11C(r1)
	  fsubs     f3, f5, f3
	  lfs       f0, 0x118(r1)
	  fsubs     f2, f2, f4
	  rlwinm    r6,r31,0,16,31
	  fdivs     f2, f3, f2
	  fmuls     f1, f2, f1
	  fadds     f1, f30, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x118(r1)
	  lfs       f0, 0x11C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x11C(r1)
	  lfs       f0, 0x120(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x120(r1)
	  lwz       r4, 0xC(r29)
	  bl        -0x1B68C
	  b         .loc_0x894

	.loc_0x750:
	  lwz       r3, 0xC(r29)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x894
	  li        r0, 0x6
	  sth       r0, 0x1C(r29)
	  cmplwi    r29, 0
	  mr        r4, r29
	  lfs       f0, -0x4D38(r13)
	  stfs      f0, 0x70(r30)
	  lfs       f0, -0x4D34(r13)
	  stfs      f0, 0x74(r30)
	  lfs       f0, -0x4D30(r13)
	  stfs      f0, 0x78(r30)
	  lwz       r3, 0xC(r29)
	  lfs       f0, -0x4D2C(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x4D28(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4D24(r13)
	  stfs      f0, 0x8(r3)
	  beq-      .loc_0x7AC
	  lwz       r4, 0x14(r29)

	.loc_0x7AC:
	  lwz       r3, 0xC(r29)
	  addi      r3, r3, 0x354
	  bl        0x6E78C
	  lwz       r3, 0xC(r29)
	  bl        -0x20AC4
	  b         .loc_0x894
	  mr        r3, r29
	  bl        0x2A98
	  b         .loc_0x898
	  mr        r3, r29
	  bl        .loc_0x8B4
	  b         .loc_0x898
	  lbz       r0, 0x9C(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x894
	  lwz       r3, 0x18(r29)
	  lwz       r4, 0x55C(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x80C
	  lwz       r0, 0x5C(r4)
	  subfic    r0, r0, 0x3
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,24,31
	  b         .loc_0x810

	.loc_0x80C:
	  li        r0, 0

	.loc_0x810:
	  cmpwi     r0, 0
	  beq-      .loc_0x850
	  bl        -0x1BE60
	  cmpwi     r3, 0x1
	  bne-      .loc_0x840
	  lwz       r3, 0xC(r29)
	  li        r0, 0x9
	  stb       r0, 0x400(r3)
	  lwz       r0, 0x18(r29)
	  lwz       r3, 0xC(r29)
	  stw       r0, 0x404(r3)
	  b         .loc_0x88C

	.loc_0x840:
	  lwz       r3, 0xC(r29)
	  li        r0, 0x1
	  stb       r0, 0x400(r3)
	  b         .loc_0x88C

	.loc_0x850:
	  bl        -0x1BE98
	  cmpwi     r3, 0x1
	  bne-      .loc_0x880
	  lwz       r3, 0xC(r29)
	  li        r0, 0x4
	  stb       r0, 0x400(r3)
	  lwz       r3, 0xC(r29)
	  stb       r0, 0x400(r3)
	  lwz       r0, 0x18(r29)
	  lwz       r3, 0xC(r29)
	  stw       r0, 0x404(r3)
	  b         .loc_0x88C

	.loc_0x880:
	  lwz       r3, 0xC(r29)
	  li        r0, 0x1
	  stb       r0, 0x400(r3)

	.loc_0x88C:
	  li        r3, 0x2
	  b         .loc_0x898

	.loc_0x894:
	  li        r3, 0

	.loc_0x898:
	  lmw       r27, 0x14C(r1)
	  lwz       r0, 0x174(r1)
	  lfd       f31, 0x168(r1)
	  lfd       f30, 0x160(r1)
	  addi      r1, r1, 0x170
	  mtlr      r0
	  blr

	.loc_0x8B4:
	*/
}

/*
 * --INFO--
 * Address:	800B1434
 * Size:	0008A8
 */
int ActTransport::moveGuruGuru()
{
	Pellet* pel = mPellet.getPtr();
	Stickers stuckList(pel);
	int numStickers = getNumStickers();
	int minWeight   = pel->mConfig->mCarryMinPikis();

	if (numStickers < minWeight) {
		PRINT("小人数!!!\n"); // 'small group!!!'
		mState = STATE_Put;
		pel->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mPikiAnimMgr.finishMotion(this);
		mPiki->endStickObject();
		return ACTOUT_Continue;
	}

	mPiki->mVelocity.set(50.0f * (f32(numStickers) / f32(minWeight)), 0.0f, 0.0f);

	if (isStickLeader() && mPathIndex != -1) {
		WayPoint* wp    = routeMgr->getWayPoint('test', mPiki->mPathBuffers[mPathIndex].mWayPointIdx);
		Vector3f& wpPos = wp->mPosition;

		if (wp->mIsOpen && !(wp->_40 & 2) && crPointOpen(mPathIndex + 1)) {
			PRINT("curr = %d : currBase = %d\n", mPathIndex, mNextPathIndex);
			PRINT("==== 開通ざました ====(%d) : %d (route %d)\n", wp->mIndex, mPathIndex,
			      mPiki->mPathBuffers[mPathIndex].mWayPointIdx); // '==== opened ===='
			PRINT("::: route=%s type=%s\n", (wp->mIsOpen) ? "on" : "*** off ***", (wp->_40 & 2) ? "pebble" : "---");
			mState = STATE_Move;
			return ACTOUT_Continue;
		}

		bool isFirst = false;
		if (mPathIndex >= 1) {
			wp = routeMgr->getWayPoint('test', mPiki->mPathBuffers[mPathIndex - 1].mWayPointIdx);
		} else {
			isFirst = true;
		}

		f32 rad          = wp->mRadius;
		Vector3f pathDir = wpPos - wp->mPosition;
		u32 badCompiler;
		f32 dist = pathDir.normalise();
		dist -= 160.0f;
		if (dist < 0.0f) {
			dist = 0.0f;
		}

		if (isFirst) {
			pathDir = mSpinStartPosition;
			rad     = 10.0f;
		} else {
			pathDir = wp->mPosition + pathDir * dist;
			rad     = 10.0f;
		}

		mWaitTimer += PI * gsys->getFrameTime();

		if (mWaitTimer > TAU) {
			mWaitTimer -= TAU;
			if (!gameflow.mMoviePlayer->mIsActive && !playerState->mDemoFlags.isFlag(DEMOFLAG_Unk28)) {
				playerState->mDemoFlags.setFlagOnly(DEMOFLAG_Unk28);
				if (pel->aiCullable()) {
					gameflow.mGameInterface->message(0, 23);
				} else {
					GameCoreSection::startTextDemo(pel, 23);
				}
			}
		}

		Vector3f dirToPath = pathDir - pel->mPosition;
		f32 distToPath     = dirToPath.length();

		if (distToPath > 80.0f) {
			PRINT("might stray guru : %.1f", distToPath);
			doLift();
			return ACTOUT_Continue;
		}

		Vector3f vel(sinf(mWaitTimer), 0.0f, cosf(mWaitTimer));
		u32 badCompiler2;
		vel.multiply(rad);
		vel.add(pathDir);
		vel = vel - pel->getCentre();
		vel.normalise();

		f32 maxSpeed = 0.7f * pikiMgr->mPikiParms->mPikiParms.mMaxLeafMoveSpeed();
		f32 minSpeed = 0.5f * maxSpeed;
		f32 factor   = (getCarriers() + 1.0f - f32(minWeight)) / f32(pel->mConfig->mCarryMaxPikis());
		f32 speed    = factor * (maxSpeed - minSpeed);
		speed        = (minSpeed + speed);
		speed *= 0.5f;
		vel.multiply(speed);
		pel->doCarry(mPiki, vel, numStickers);

	} else if ((isStickLeader() && mPathIndex == -1) || !mPiki->isStickTo()) {
		mState = STATE_Put;
		pel->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mPikiAnimMgr.finishMotion(this);
		mPiki->endStickObject();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800B1CDC
 * Size:	000318
 */
void ActTransport::decideGoal(Creature* cargo)
{
	Pellet* pel = mPellet.getPtr();
	PRINT("pellet type is %d\n", pel->mConfig->mPelletType());
	if (pel->mConfig->mPelletType() == PELTYPE_UfoPart) {
		mGoal = itemMgr->getUfo();
		if (!mGoal) {
			ERROR("no ufo!");
		}
		mPellet.getPtr()->mTargetGoal = mGoal;
		return;
	}

	// if not ufo part, need to decide onyon colour.
	int colorCounts[PikiColorCount];
	int optionColors[PikiColorCount];
	int numOptions = 0;
	int onyonColor = Blue;
	bool isVsMode  = flowCont.mNaviOnMap == 1;

	PRINT("###### decide goal\n");
	int i;
	for (i = 0; i < PikiColorCount; i++) {
		colorCounts[i] = 0;
	}

	Stickers stuckList(cargo);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		if ((*iter)->isPiki()) {
			Piki* piki = static_cast<Piki*>(*iter);
			if (!isVsMode) {
				colorCounts[piki->mColor]++;
			} else {
				int color = piki->mColor;
				if (color == Yellow) {
					color = piki->mNavi->mNaviID;
				}
				colorCounts[color]++;
			}
		}
	}

	int maxCount = -1;
	for (i = 0; i < PikiColorCount; i++) {
		if (colorCounts[i] > maxCount) {
			maxCount = colorCounts[i];
			PRINT("color %d : is max (%d)\n", i, maxCount);
		}
	}

	for (i = 0; i < PikiColorCount; i++) {
		if (colorCounts[i] == maxCount) {
			optionColors[numOptions++] = i;
		}
	}

	int randColor = randFloat(f32(numOptions));
	if (randColor >= numOptions) {
		PRINT("random select color=%d : maxcols=%d\n", randColor, numOptions);
		randColor = Blue;
	}

	onyonColor = optionColors[randColor];
	PRINT(" ## color %d is selected\n", onyonColor);
	mGoal                     = itemMgr->getContainer(onyonColor);
	mPellet.mPtr->mTargetGoal = mGoal; // hmm.

	if (!mGoal) {
		PRINT("SORRY *** goal(color%d) is required !!\n", onyonColor);
		ERROR("zannnen\n"); // 'too bad'
	}
}

/*
 * --INFO--
 * Address:	800B1FF4
 * Size:	0001B8
 */
void ActTransport::cleanup()
{
	mPiki->endStickObject();
	Pellet* pel = mPellet.getPtr();
	if (pel) {
		int numStickers = calcNumStickers();
		int minCarry    = pel->mConfig->mCarryMinPikis();
		if (numStickers > 0) {
			Vector3f carryInfoPos(pel->mPosition);
			carryInfoPos.y += pel->getCylinderHeight() + 5.0f;
			pel->mLifeGauge.countOn(carryInfoPos, numStickers, minCarry);

		} else {
			pel->mLifeGauge.countOff();
			pel->setTrySound(false);
		}
	}
	mPellet.reset();
}

/*
 * --INFO--
 * Address:	800B21AC
 * Size:	0001D8
 */
Vector3f ActTransport::crGetPoint(int idx)
{
	if (!mGoal) {
		PRINT("NO SUCKABLE !!!!\n");
		Pellet* pel = mPellet.getPtr();
		decideGoal(pel);
	}

	if (idx < 0) {
		return mRouteStartPos;
	}

	if (idx >= mNumRoutePoints) {
		return mGoal->getGoalPos();
	}

	WayPoint* wp = routeMgr->getWayPoint('test', mPiki->mPathBuffers[idx].mWayPointIdx);
	if (!wp) {
		PRINT("numWayPoints=%d idx=%d no waypoint (wp.idx=%d)\n", mNumRoutePoints, idx, mPiki->mPathBuffers[idx].mWayPointIdx);
		ERROR("gakkusi");
	}

	Vector3f dirToGoal = wp->mPosition - mGoal->getGoalPos();
	f32 distToGoal     = dirToGoal.length();
	if (distToGoal <= mGoal->getGoalPosRadius()) {
		return mGoal->getGoalPos();
	}

	return wp->mPosition;
}

/*
 * --INFO--
 * Address:	800B2384
 * Size:	00008C
 */
bool ActTransport::crPointOpen(int idx)
{
	if (idx < 0 || idx >= mNumRoutePoints) {
		return true;
	}

	WayPoint* wp = routeMgr->getWayPoint('test', mPiki->mPathBuffers[idx].mWayPointIdx);
	if (!wp) {
		PRINT("numWayPoints=%d idx=%d no waypoint (wp.idx=%d)\n", mNumRoutePoints, idx, mPiki->mPathBuffers[idx].mWayPointIdx);
		ERROR("gakkusi");
	}

	return wp->mIsOpen && !(wp->_40 & 2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
f32 ActTransport::crGetRadius(int idx)
{
	Pellet* pel = mPellet.getPtr();
	if (idx < 0) {
		return pel->getCentreSize();
	}

	if (idx >= mNumRoutePoints) {
		return 50.0f;
	}

	return routeMgr->getWayPoint('test', mPiki->mPathBuffers[idx].mWayPointIdx)->mRadius;
}

/*
 * --INFO--
 * Address:	800B2410
 * Size:	000514
 */
void ActTransport::crInit()
{
	Pellet* pel     = mPellet.getPtr();
	mNextPathIndex  = -1;
	mRouteStartPos  = pel->mPosition;
	Vector3f point1 = crGetPoint(mNextPathIndex + 1);
	Vector3f point2 = crGetPoint(mNextPathIndex + 2);
	Tube crTube(point1, point2, crGetRadius(mNextPathIndex + 1), crGetRadius(mNextPathIndex + 2));
	f32 collDepth;
	Vector3f pushVec;
	Sphere sphere(pel->mPosition, 0.0f);
	if (crTube.collide(sphere, pushVec, collDepth) && crPointOpen(mNextPathIndex + 2)) {
		PRINT("crInit() TUBE START **\n");
		mNextPathIndex       = 0;
		mSplineControlPts[0] = crGetPoint(-1);
		mSplineControlPts[1] = crGetPoint(-1);
		mSplineControlPts[2] = crGetPoint(1);
		mSplineControlPts[3] = crGetPoint(2);
		mPathType            = 0;
	} else {
		bool landOnly = useWaterRoute() == 0;
		WayPoint* wpA = nullptr;
		WayPoint* wpB = nullptr;

		PRINT("crInit() ** NEAREST EDGE AVOID OFF =================\n");
		wpA = routeMgr->getWayPoint('test', mPiki->mPathBuffers[0].mWayPointIdx);
		if (mNumRoutePoints >= 2) {
			wpB = routeMgr->getWayPoint('test', mPiki->mPathBuffers[1].mWayPointIdx);
		}

		PRINT("nearest edge( %d, %d )\n", (wpA) ? wpA->mIndex : -1, (wpB) ? wpB->mIndex : -1);

		if (wpA && wpB) {
			PRINT("*** VERTICAL POS\n");
			Vector3f nextPoint;
			Vector3f tmpDir  = wpB->mPosition - wpA->mPosition;
			Vector3f pathDir = tmpDir;
			f32 pathDist     = pathDir.normalise();
			f32 proj         = pathDir.DP(pel->mPosition - wpA->mPosition) / pathDist;
			if (proj < 0.0f) {
				nextPoint = wpA->mPosition;
			} else if (proj > 1.0f) {
				nextPoint = wpB->mPosition;
			} else {
				nextPoint = (proj * pathDist) * pathDir + wpA->mPosition;
			}

			crMakeRefs();
			mSplineControlPts[2] = nextPoint;
			mPathType            = 1;

		} else {
			crMakeRefs();
			mPathType = 2;
		}
	}

	findObstacle();

	for (int i = 0; i < 4; i++) {
		PRINT("\tref[%d] = (%.1f,%.1f)\n", i, mSplineControlPts[i].x, mSplineControlPts[i].z);
	}
	mOdometer.start(4.0f, 10.0f);

	u32 badCompiler;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, -0x1
	  stwu      r1, -0x1E8(r1)
	  stfd      f31, 0x1E0(r1)
	  stfd      f30, 0x1D8(r1)
	  stfd      f29, 0x1D0(r1)
	  stfd      f28, 0x1C8(r1)
	  stfd      f27, 0x1C0(r1)
	  stfd      f26, 0x1B8(r1)
	  stfd      f25, 0x1B0(r1)
	  stmw      r27, 0x19C(r1)
	  mr        r30, r3
	  addi      r4, r30, 0
	  lwz       r31, 0x18(r3)
	  stw       r0, 0x44(r3)
	  addi      r3, r1, 0x100
	  lwz       r5, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r5, 0x7C(r30)
	  stw       r0, 0x80(r30)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x84(r30)
	  lwz       r5, 0x44(r30)
	  addi      r5, r5, 0x1
	  bl        -0x2C8
	  lwz       r5, 0x44(r30)
	  mr        r4, r30
	  lfs       f30, 0x100(r1)
	  addi      r3, r1, 0xF4
	  lfs       f31, 0x104(r1)
	  lfs       f28, 0x108(r1)
	  addi      r5, r5, 0x2
	  bl        -0x2E8
	  lwz       r3, 0x44(r30)
	  lfs       f27, 0xF4(r1)
	  addic.    r5, r3, 0x2
	  lfs       f26, 0xF8(r1)
	  lfs       f25, 0xFC(r1)
	  lwz       r3, 0x18(r30)
	  bge-      .loc_0xBC
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f29, f1
	  b         .loc_0xF4

	.loc_0xBC:
	  lhz       r0, 0x3C(r30)
	  cmpw      r5, r0
	  blt-      .loc_0xD0
	  lfs       f29, -0x6FB0(r2)
	  b         .loc_0xF4

	.loc_0xD0:
	  lwz       r4, 0xC(r30)
	  lis       r6, 0x7465
	  rlwinm    r0,r5,3,0,28
	  lwz       r3, 0x302C(r13)
	  lwz       r5, 0x2CC(r4)
	  addi      r4, r6, 0x7374
	  lwzx      r5, r5, r0
	  bl        -0x10E84
	  lfs       f29, 0xC(r3)

	.loc_0xF4:
	  lwz       r4, 0x44(r30)
	  lwz       r3, 0x18(r30)
	  addic.    r5, r4, 0x1
	  bge-      .loc_0x118
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x150

	.loc_0x118:
	  lhz       r0, 0x3C(r30)
	  cmpw      r5, r0
	  blt-      .loc_0x12C
	  lfs       f1, -0x6FB0(r2)
	  b         .loc_0x150

	.loc_0x12C:
	  lwz       r4, 0xC(r30)
	  lis       r6, 0x7465
	  rlwinm    r0,r5,3,0,28
	  lwz       r3, 0x302C(r13)
	  lwz       r5, 0x2CC(r4)
	  addi      r4, r6, 0x7374
	  lwzx      r5, r5, r0
	  bl        -0x10EE0
	  lfs       f1, 0xC(r3)

	.loc_0x150:
	  stfs      f30, 0x15C(r1)
	  addi      r3, r1, 0x15C
	  lfs       f2, -0x7018(r2)
	  addi      r4, r1, 0x13C
	  stfs      f31, 0x160(r1)
	  addi      r5, r1, 0x14C
	  stfs      f28, 0x164(r1)
	  addi      r6, r1, 0x158
	  stfs      f27, 0x168(r1)
	  stfs      f26, 0x16C(r1)
	  stfs      f25, 0x170(r1)
	  stfs      f2, 0x154(r1)
	  stfs      f1, 0x174(r1)
	  stfs      f2, 0x150(r1)
	  stfs      f29, 0x178(r1)
	  stfs      f2, 0x14C(r1)
	  lfs       f0, 0x94(r31)
	  stfs      f0, 0x13C(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x140(r1)
	  lfs       f0, 0x9C(r31)
	  stfs      f0, 0x144(r1)
	  stfs      f2, 0x148(r1)
	  bl        -0x2B230
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2D4
	  lwz       r3, 0x44(r30)
	  addic.    r3, r3, 0x2
	  blt-      .loc_0x1D0
	  lhz       r0, 0x3C(r30)
	  cmpw      r3, r0
	  blt-      .loc_0x1D8

	.loc_0x1D0:
	  li        r4, 0x1
	  b         .loc_0x21C

	.loc_0x1D8:
	  lwz       r4, 0xC(r30)
	  lis       r6, 0x7465
	  rlwinm    r0,r3,3,0,28
	  lwz       r3, 0x302C(r13)
	  lwz       r5, 0x2CC(r4)
	  addi      r4, r6, 0x7374
	  lwzx      r5, r5, r0
	  bl        -0x10F8C
	  cmplwi    r3, 0
	  lbz       r0, 0x38(r3)
	  li        r4, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x21C
	  lbz       r0, 0x40(r3)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x21C
	  li        r4, 0x1

	.loc_0x21C:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x2D4
	  li        r28, 0
	  stw       r28, 0x44(r30)
	  addi      r4, r30, 0
	  addi      r3, r1, 0xE8
	  li        r5, -0x1
	  bl        -0x49C
	  lwz       r6, 0xE8(r1)
	  mr        r4, r30
	  lwz       r0, 0xEC(r1)
	  addi      r3, r1, 0xDC
	  li        r5, -0x1
	  stw       r6, 0x4C(r30)
	  stw       r0, 0x50(r30)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0x54(r30)
	  bl        -0x4C4
	  lwz       r6, 0xDC(r1)
	  mr        r4, r30
	  lwz       r0, 0xE0(r1)
	  addi      r3, r1, 0xD0
	  li        r5, 0x1
	  stw       r6, 0x58(r30)
	  stw       r0, 0x5C(r30)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x60(r30)
	  bl        -0x4EC
	  lwz       r6, 0xD0(r1)
	  mr        r4, r30
	  lwz       r0, 0xD4(r1)
	  addi      r3, r1, 0xC4
	  li        r5, 0x2
	  stw       r6, 0x64(r30)
	  stw       r0, 0x68(r30)
	  lwz       r0, 0xD8(r1)
	  stw       r0, 0x6C(r30)
	  bl        -0x514
	  lwz       r3, 0xC4(r1)
	  lwz       r0, 0xC8(r1)
	  stw       r3, 0x70(r30)
	  stw       r0, 0x74(r30)
	  lwz       r0, 0xCC(r1)
	  stw       r0, 0x78(r30)
	  stb       r28, 0x88(r30)
	  b         .loc_0x4CC

	.loc_0x2D4:
	  mr        r3, r30
	  bl        -0x1CD0
	  lwz       r5, 0xC(r30)
	  lis       r28, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r28, 0x7374
	  lwz       r5, 0x2CC(r5)
	  li        r27, 0
	  lwz       r5, 0x0(r5)
	  bl        -0x11090
	  lhz       r0, 0x3C(r30)
	  addi      r29, r3, 0
	  cmplwi    r0, 0x2
	  blt-      .loc_0x328
	  lwz       r5, 0xC(r30)
	  addi      r4, r28, 0x7374
	  lwz       r3, 0x302C(r13)
	  lwz       r5, 0x2CC(r5)
	  lwz       r5, 0x8(r5)
	  bl        -0x110B8
	  mr        r27, r3

	.loc_0x328:
	  cmplwi    r29, 0
	  beq-      .loc_0x4BC
	  cmplwi    r27, 0
	  beq-      .loc_0x4BC
	  lfs       f0, -0x7018(r2)
	  stfs      f0, 0x134(r1)
	  stfs      f0, 0x130(r1)
	  stfs      f0, 0x12C(r1)
	  lfs       f3, 0x0(r27)
	  lfs       f2, 0x0(r29)
	  lfs       f1, 0x4(r27)
	  lfs       f0, 0x4(r29)
	  fsubs     f31, f3, f2
	  lfs       f2, 0x8(r27)
	  fsubs     f30, f1, f0
	  lfs       f0, 0x8(r29)
	  fmuls     f1, f31, f31
	  fsubs     f29, f2, f0
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA4B50
	  lfs       f0, -0x7018(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x39C
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x39C:
	  lfs       f3, 0x94(r31)
	  lfs       f2, 0x0(r29)
	  lfs       f0, -0x7018(r2)
	  fsubs     f2, f3, f2
	  stfs      f2, 0x84(r1)
	  lfs       f3, 0x98(r31)
	  lfs       f2, 0x4(r29)
	  lfs       f4, 0x84(r1)
	  fsubs     f2, f3, f2
	  lfs       f6, 0x9C(r31)
	  lfs       f5, 0x8(r29)
	  fmuls     f3, f31, f4
	  fsubs     f4, f6, f5
	  fmuls     f2, f30, f2
	  fmuls     f4, f29, f4
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fdivs     f2, f2, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x408
	  lwz       r3, 0x0(r29)
	  lwz       r0, 0x4(r29)
	  stw       r3, 0x12C(r1)
	  stw       r0, 0x130(r1)
	  lwz       r0, 0x8(r29)
	  stw       r0, 0x134(r1)
	  b         .loc_0x490

	.loc_0x408:
	  lfs       f0, -0x6FF4(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x430
	  lwz       r3, 0x0(r27)
	  lwz       r0, 0x4(r27)
	  stw       r3, 0x12C(r1)
	  stw       r0, 0x130(r1)
	  lwz       r0, 0x8(r27)
	  stw       r0, 0x134(r1)
	  b         .loc_0x490

	.loc_0x430:
	  fmuls     f0, f2, f1
	  addi      r6, r1, 0x64
	  addi      r5, r1, 0x60
	  addi      r4, r1, 0x5C
	  fmuls     f2, f29, f0
	  fmuls     f1, f30, f0
	  addi      r3, r1, 0xA0
	  fmuls     f0, f31, f0
	  stfs      f2, 0x64(r1)
	  stfs      f1, 0x60(r1)
	  stfs      f0, 0x5C(r1)
	  bl        -0x7B750
	  lfs       f2, 0xA0(r1)
	  lfs       f0, 0x0(r29)
	  lfs       f1, 0xA4(r1)
	  fadds     f0, f2, f0
	  stfs      f0, 0x12C(r1)
	  lfs       f0, 0x4(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x130(r1)
	  lfs       f1, 0xA8(r1)
	  lfs       f0, 0x8(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x134(r1)

	.loc_0x490:
	  mr        r3, r30
	  bl        .loc_0x514
	  lwz       r4, 0x12C(r1)
	  li        r0, 0x1
	  lwz       r3, 0x130(r1)
	  stw       r4, 0x64(r30)
	  stw       r3, 0x68(r30)
	  lwz       r3, 0x134(r1)
	  stw       r3, 0x6C(r30)
	  stb       r0, 0x88(r30)
	  b         .loc_0x4CC

	.loc_0x4BC:
	  mr        r3, r30
	  bl        .loc_0x514
	  li        r0, 0x2
	  stb       r0, 0x88(r30)

	.loc_0x4CC:
	  mr        r3, r30
	  bl        0xC4
	  lfs       f1, -0x6F94(r2)
	  addi      r3, r30, 0x20
	  lfs       f2, -0x6FAC(r2)
	  bl        0x1AF24
	  lmw       r27, 0x19C(r1)
	  lwz       r0, 0x1EC(r1)
	  lfd       f31, 0x1E0(r1)
	  lfd       f30, 0x1D8(r1)
	  lfd       f29, 0x1D0(r1)
	  lfd       f28, 0x1C8(r1)
	  lfd       f27, 0x1C0(r1)
	  lfd       f26, 0x1B8(r1)
	  lfd       f25, 0x1B0(r1)
	  addi      r1, r1, 0x1E8
	  mtlr      r0
	  blr

	.loc_0x514:
	*/
}

/*
 * --INFO--
 * Address:	800B2924
 * Size:	000080
 */
void ActTransport::crMakeRefs()
{
	for (int i = 0; i < 4; i++) {
		mSplineControlPts[i] = crGetPoint(mNextPathIndex + i - 1);
	}
}

/*
 * --INFO--
 * Address:	800B29A4
 * Size:	00032C
 */
void ActTransport::findObstacle()
{
	_48              = 0;
	Vector3f point1  = mSplineControlPts[1];
	Vector3f point2  = mSplineControlPts[2];
	Vector3f pathDir = point2 - point1;
	f32 pathDist     = pathDir.normalise();

	Iterator iter(tekiMgr);
	CI_LOOP(iter)
	{
		Creature* teki = *iter;
		if (teki->isAlive() && teki->isTerrible()) {
			f32 proj = pathDir.DP(teki->mPosition - point1) / pathDist;
			Vector3f vec;
			vec                   = (proj * pathDist) * pathDir + point1;
			vec                   = vec - teki->mPosition;
			f32 unusedDist        = vec.normalise();
			f32 unusedWeightedVal = crGetRadius(mNextPathIndex) * (1.0f - proj) + crGetRadius(mNextPathIndex + 1) * (proj);
		}
	}

	u32 badCompiler[2];

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x188(r1)
	  stfd      f31, 0x180(r1)
	  stfd      f30, 0x178(r1)
	  stfd      f29, 0x170(r1)
	  stfd      f28, 0x168(r1)
	  stfd      f27, 0x160(r1)
	  stfd      f26, 0x158(r1)
	  stfd      f25, 0x150(r1)
	  stmw      r24, 0x130(r1)
	  addi      r26, r3, 0
	  stw       r0, 0x48(r3)
	  lfs       f25, 0x58(r3)
	  lfs       f1, 0x64(r3)
	  lfs       f26, 0x5C(r3)
	  lfs       f0, 0x68(r3)
	  fsubs     f30, f1, f25
	  lfs       f27, 0x60(r3)
	  fsubs     f29, f0, f26
	  lfs       f0, 0x6C(r3)
	  fmuls     f1, f30, f30
	  fsubs     f28, f0, f27
	  fmuls     f0, f29, f29
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xA4DD4
	  fmr       f31, f1
	  lfs       f0, -0x7018(r2)
	  fcmpu     cr0, f0, f31
	  beq-      .loc_0x90
	  fdivs     f30, f30, f31
	  fdivs     f29, f29, f31
	  fdivs     f28, f28, f31

	.loc_0x90:
	  lwz       r28, 0x3160(r13)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r3, 0
	  addi      r31, r1, 0x5C
	  addi      r30, r1, 0x58
	  addi      r29, r1, 0x54
	  lis       r25, 0x7465
	  b         .loc_0x2A0

	.loc_0xC0:
	  cmpwi     r27, -0x1
	  bne-      .loc_0xE8
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3
	  b         .loc_0x104

	.loc_0xE8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3

	.loc_0x104:
	  lwz       r12, 0x0(r24)
	  mr        r3, r24
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x284
	  mr        r3, r24
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x7C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x284
	  lfs       f0, 0x94(r24)
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  fsubs     f0, f0, f25
	  addi      r6, r31, 0
	  addi      r3, r1, 0xC0
	  stfs      f0, 0xAC(r1)
	  lfs       f0, 0x98(r24)
	  lfs       f2, 0x9C(r24)
	  fsubs     f0, f0, f26
	  lfs       f1, 0xAC(r1)
	  fsubs     f2, f2, f27
	  fmuls     f1, f30, f1
	  fmuls     f0, f29, f0
	  fmuls     f2, f28, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fdivs     f0, f0, f31
	  fmuls     f0, f0, f31
	  fmuls     f2, f28, f0
	  fmuls     f1, f29, f0
	  fmuls     f0, f30, f0
	  stfs      f2, 0x5C(r1)
	  stfs      f1, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  bl        -0x7BA28
	  lfs       f0, 0xC0(r1)
	  lfs       f1, 0xC4(r1)
	  fadds     f4, f0, f25
	  lfs       f2, 0x94(r24)
	  lfs       f0, 0xC8(r1)
	  fadds     f3, f1, f26
	  lfs       f1, 0x98(r24)
	  fsubs     f5, f4, f2
	  lfs       f2, 0x9C(r24)
	  fsubs     f4, f3, f1
	  fadds     f3, f0, f27
	  fmuls     f1, f5, f5
	  fmuls     f0, f4, f4
	  fsubs     f2, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f2, f2
	  fadds     f1, f1, f0
	  bl        -0xA4F4C
	  lwz       r4, 0x44(r26)
	  lwz       r3, 0x18(r26)
	  cmpwi     r4, 0
	  bge-      .loc_0x210
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x238

	.loc_0x210:
	  lhz       r0, 0x3C(r26)
	  cmpw      r4, r0
	  bge-      .loc_0x238
	  lwz       r5, 0xC(r26)
	  rlwinm    r0,r4,3,0,28
	  lwz       r3, 0x302C(r13)
	  addi      r4, r25, 0x7374
	  lwz       r5, 0x2CC(r5)
	  lwzx      r5, r5, r0
	  bl        -0x11560

	.loc_0x238:
	  lwz       r4, 0x44(r26)
	  lwz       r3, 0x18(r26)
	  addic.    r4, r4, 0x1
	  bge-      .loc_0x25C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x284

	.loc_0x25C:
	  lhz       r0, 0x3C(r26)
	  cmpw      r4, r0
	  bge-      .loc_0x284
	  lwz       r5, 0xC(r26)
	  rlwinm    r0,r4,3,0,28
	  lwz       r3, 0x302C(r13)
	  addi      r4, r25, 0x7374
	  lwz       r5, 0x2CC(r5)
	  lwzx      r5, r5, r0
	  bl        -0x115AC

	.loc_0x284:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x2A0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2C8
	  li        r0, 0x1
	  b         .loc_0x2F4

	.loc_0x2C8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2F0
	  li        r0, 0x1
	  b         .loc_0x2F4

	.loc_0x2F0:
	  li        r0, 0

	.loc_0x2F4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xC0
	  lmw       r24, 0x130(r1)
	  lwz       r0, 0x18C(r1)
	  lfd       f31, 0x180(r1)
	  lfd       f30, 0x178(r1)
	  lfd       f29, 0x170(r1)
	  lfd       f28, 0x168(r1)
	  lfd       f27, 0x160(r1)
	  lfd       f26, 0x158(r1)
	  lfd       f25, 0x150(r1)
	  addi      r1, r1, 0x188
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B2CD0
 * Size:	00094C
 */
bool ActTransport::crMove()
{
	Pellet* pel        = mPellet.getPtr();
	Vector3f currPoint = crGetPoint(mNextPathIndex);
	Vector3f point2(mSplineControlPts[2]);

	if ((mNextPathIndex == -1 && !crPointOpen(1)) || (mNextPathIndex != -1 && !crPointOpen(mNextPathIndex + 1))) {
		PRINT("******** GURUGURU START : currBase+1 = %d is off !\n", mNextPathIndex);
		PRINT("ROUTE IS OFF !!! currBase+1 = %d\n", mNextPathIndex + 1);
		PRINT("ROUTE INDEX IS %d\n", mPiki->mPathBuffers[mNextPathIndex + 1].mWayPointIdx);
		PRINT("crPoint : offp=%d", mPiki->mPathBuffers[mNextPathIndex + 1].mWayPointIdx);

		WayPoint* wp = routeMgr->getWayPoint('test', mPiki->mPathBuffers[mNextPathIndex + 1].mWayPointIdx);
		if (wp) {
			PRINT("** ROUTE POINT %d is %s : %s\n", wp->mIndex, wp->mIsOpen ? "on" : "off", wp->_40 & 2 ? "pebble" : "-");
		}

		mState             = STATE_Guru;
		mSpinStartPosition = pel->mPosition;
		mWaitTimer         = 0.0f;
		return true;
	}

	Vector3f dir = point2 - pel->mPosition;
	if (qdist2(point2.x, point2.z, pel->mPosition.x, pel->mPosition.z) < 6.0f) {
		if (mNextPathIndex >= mNumRoutePoints - 2) {
			mState   = STATE_Goal;
			mMoveDir = CRSplineTangent(1.0f, mSplineControlPts);
			mMoveDir.normalise();
			return true;
		}

		mNextPathIndex++;
		mPathIndex++;
		crMakeRefs();
		findObstacle();
		mMoveDir = CRSplineTangent(0.0f, mSplineControlPts);
		mMoveDir.normalise();
		return true;
	}

	Vector3f pathDir = point2 - currPoint;

	f32 pathDist = pathDir.normalise();
	if (pathDist <= 0.0f) {
		PRINT("DANGER ** CYLINDER ZERO! \n");
	}

	f32 factor;
	if (pathDist > 0.0f) {
		factor = pathDir.DP(pel->mPosition - currPoint) / pathDist;
	} else {
		factor = 1.0f;
	}

	if (factor < 0.0f) {
		factor = 0.0f;
	}

	if (factor > 1.0f) {
		factor = 1.0f;
	}

	Vector3f vec;
	vec              = (factor * pathDist) * pathDir + currPoint;
	vec              = vec - pel->mPosition;
	vec.y            = 0.0f;
	f32 val1         = vec.normalise();
	f32 weightedProj = crGetRadius(mNextPathIndex) * (1.0f - factor) + crGetRadius(mNextPathIndex + 1) * factor;

	f32 blend = zen::Abs(val1) / weightedProj;

	if (blend < 0.3f) {
		blend = 0.0f;
	}

	if (blend > 2.0f && zen::Abs(val1) > 130.0f) {
		PRINT("danger root strayed:blend %.2f\n", blend);
		doLift();
		return true;
	}

	if (blend > 1.0f) {
		blend = 1.0f;
	} else if (blend < 0.0f) {
		blend = 0.0f;
	}

	if (factor >= 1.0f) {
		if (mNextPathIndex >= mNumRoutePoints - 2) {
			mState   = STATE_Goal;
			mMoveDir = CRSplineTangent(factor, mSplineControlPts);
			mMoveDir.normalise();
			return true;
		}

		mNextPathIndex++;
		mPathIndex++;
		factor = 0.0f;
		crMakeRefs();
		findObstacle();
		mMoveDir = CRSplineTangent(factor, mSplineControlPts);
		mMoveDir.normalise();
		return true;
	}

	mMoveDir = CRSplineTangent(factor, mSplineControlPts);
	mMoveDir.normalise();

	mMoveDir = (1.0f - blend) * mMoveDir + blend * vec;

	if (mMoveDir.x * pathDir.x + mMoveDir.z * pathDir.z <= 0.0f) {
		mMoveDir = pathDir;
		PRINT("adjust mvDir (%.1f %.1f %.1f)\n", mMoveDir.x, mMoveDir.y, mMoveDir.z);
	}

	if (!gameflow.mMoviePlayer->mIsActive) {
		bool isMoving = mOdometer.moving(pel->mPosition, pel->mLastPosition);
		if (!isMoving) {
			PRINT("pellet %s is not moving", pel->mConfig->mPelletId.mStringID);
			return false;
		}
	}
}

/*
 * --INFO--
 * Address:	800B361C
 * Size:	0007C4
 */
void ActTransport::draw(Graphics& gfx)
{
	if (!AIPerf::kandoOnly) {
		return;
	}

	if (!isStickLeader()) {
		return;
	}

	char* stateNames[] = {
		"go", "wait", "lift", "move", "guru", "goal", "put",
	};

	char* type[] = {
		"tube",
		"vert",
		"other",
	};

	Vector3f pikiPos = mPiki->mPosition;
	char buf2[256];
	char buf1[256];
	sprintf(buf1, " ");

	if (mState == STATE_Move) {
		Pellet* pel        = mPellet.getPtr();
		Vector3f currPoint = crGetPoint(mNextPathIndex);
		Vector3f nextPoint = crGetPoint(mNextPathIndex + 1);
		Vector3f pathDir   = nextPoint - currPoint;
		f32 pathDist       = pathDir.normalise();
		f32 proj           = pathDir.DP(pel->mPosition - currPoint) / pathDist;
		if (proj < 0.0f) {
			proj = 0.0f;
		}
		if (proj > 1.0f) {
			proj = 1.0f;
		}

		Vector3f vec;
		vec              = (proj * pathDist) * pathDir + currPoint;
		vec              = vec - pel->mPosition;
		f32 val1         = vec.normalise();
		f32 weightedProj = crGetRadius(mNextPathIndex) * (1.0f - proj) + crGetRadius(mNextPathIndex + 1) * proj;
		Vector3f vec2;
		vec2 = CRSplineTangent(proj, mSplineControlPts);
		if (vec2.DP(pathDir) <= 0.0f) {
			vec2 = pathDir;
		}
		Vector3f labelPos(pikiPos);
		labelPos.y += 40.0f;
		drawArrow(gfx, labelPos, vec2, 20.0f);
		CRSplineDraw(gfx, 16, mSplineControlPts);
		sprintf(buf2, "%s %d %.1f", stateNames[mState], mNextPathIndex, proj);
		sprintf(buf1, "%.1f/%.1f %s", val1, weightedProj, type[mPathType]);

	} else {
		sprintf(buf2, "%s %d %.1f %s", stateNames[mState], mNextPathIndex, type[mPathType]);
	}

	gfx.useMatrix(Matrix4f::ident, 0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	pikiPos.y += 30.0f;

	Vector3f newVec(pikiPos);
	newVec.multMatrix(gfx.mCamera->mLookAtMtx);

	int width = -gsys->mConsFont->stringWidth(buf2) / 2;
	gfx.perspPrintf(gsys->mConsFont, newVec, width, 0, buf2);

	newVec = pikiPos;
	newVec.y += 15.0f;

	newVec.multMatrix(gfx.mCamera->mLookAtMtx);
	int width2 = -gsys->mConsFont->stringWidth(buf1) / 2;
	gfx.perspPrintf(gsys->mConsFont, newVec, width2, 0, buf1);

	if (mState == STATE_Move) {
		for (int i = 0; i < 4; i++) {
			Vector3f ctrlPt(mSplineControlPts[i]);
			char buf[64];
			sprintf(buf, "%d", i);
			drawBattenPole(gfx, ctrlPt, 50.0f, buf);
		}
		return;
	}

	if (mState == STATE_Goal) {
		Vector3f goalPos = mGoal->getGoalPos();
		drawBattenPole(gfx, goalPos, 50.0f, "goal");
	}
}

/*
 * --INFO--
 * Address:	800B3DE0
 * Size:	0006FC
 */
int ActTransport::moveToWayPoint()
{
	Pellet* pel         = mPellet.getPtr();
	int currentCarriers = getNumStickers();
	int minCarriers     = pel->mConfig->mCarryMinPikis();

	if (currentCarriers < minCarriers) {
		PRINT("小人数!!!\n"); // 'small group!!!'
		mState = STATE_Put;
		pel->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mPikiAnimMgr.finishMotion(this);
		mPiki->endStickObject();
		return ACTOUT_Continue;
	}

	if (isStickLeader() && mPathIndex != -1) {
		if (!mCanCarry) {
			PRINT("おれにはムリデス\n"); // 'i can't do it'
			mState = STATE_Put;
			pel->mVelocity.set(0.0f, 0.0f, 0.0f);
			mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
			mPiki->mPikiAnimMgr.finishMotion(this);
			mPiki->endStickObject();
			return ACTOUT_Continue;
		}

		WayPoint* wp = routeMgr->getWayPoint('test', mPiki->mPathBuffers[mPathIndex].mWayPointIdx);
		if (!wp->mIsOpen || (wp->_40 & 2)) {
			Vector3f currPoint = crGetPoint(mPathIndex);
			Vector3f nextPoint = crGetPoint(mPathIndex + 1);
			Vector3f pathDir   = nextPoint - currPoint;
			pathDir.normalise();
			Plane plane;
			plane.mNormal = pathDir;
			plane.mOffset = pathDir.DP(currPoint);
			if (plane.dist(pel->mPosition) <= 0.0f) {
				PRINT("===== MOVETOWAY POINT !\n");
				PRINT("plane Dist=%f\n", plane.dist(pel->mPosition));
				PRINT("curr=%d : idx=%d **** WAYPOINT IS OFF !!!\n", mPathIndex, mPiki->mPathBuffers[mPathIndex].mWayPointIdx);
				PRINT("moveWay : offp=%d", mPiki->mPathBuffers[mNextPathIndex + 1].mWayPointIdx);
				mSpinStartPosition = pel->mPosition;
				mState             = STATE_Guru;
				mWaitTimer         = 0.0f;
				return ACTOUT_Continue;
			}
		}

		if (!crMove()) {
			mState = STATE_Put;
			pel->mVelocity.set(0.0f, 0.0f, 0.0f);
			mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
			mPiki->mPikiAnimMgr.finishMotion(this);
			mPiki->endStickObject();
			return ACTOUT_Continue;
		}

		f32 maxSpeed = 0.7f * pikiMgr->mPikiParms->mPikiParms.mMaxLeafMoveSpeed();
		f32 minSpeed = 0.5f * maxSpeed;
		f32 factor   = (getCarriers() + 1.0f - f32(minCarriers)) / f32(pel->mConfig->mCarryMaxPikis());
		f32 speed    = factor * (maxSpeed - minSpeed);
		speed        = (minSpeed + speed);
		// speed *= 0.5f;
		mMoveDir.y = 0.0f;
		mMoveDir.normalise();
		mMoveDir.multiply(speed);
		pel->doCarry(mPiki, mMoveDir, currentCarriers);

	} else if ((isStickLeader() && mPathIndex == -1) || !mPiki->isStickTo()) {
		mState = STATE_Put;
		pel->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mPikiAnimMgr.finishMotion(this);
		mPiki->endStickObject();
	}

	return ACTOUT_Continue;

	u32 badCompiler;
}
