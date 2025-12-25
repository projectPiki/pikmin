#include "AIConstant.h"
#include "AIPerf.h"
#include "DebugLog.h"
#include "FlowController.h"
#include "Font.h"
#include "GameCoreSection.h"
#include "GoalItem.h"
#include "Graphics.h"
#include "Interface.h"
#include "KMath.h"
#include "MapCode.h"
#include "MoviePlayer.h"
#include "Navi.h"
#include "Pellet.h"
#include "PelletState.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "PlayerState.h"
#include "SoundMgr.h"
#include "Stickers.h"
#include "UfoItem.h"
#include "UtilityKando.h"
#include "gameflow.h"
#include "teki.h"
#include "zen/Math.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(74)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("Transport")

/**
 * @TODO: Documentation
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

	Vector3f torqueDir = mPiki->mSRT.t - pellet->mSRT.t;
	torqueDir.normalise();
	torqueDir.multiply(pellet->getBottomRadius());

	Vector3f upwardForce(0.0f, 400.0f * pellet->getBottomRadius() / 20.0f, 0.0f);
	torqueDir.CP(upwardForce);

	pellet->mAngularMomentum = pellet->mAngularMomentum + torqueDir;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A4
 */
void ActTransport::initWait()
{
	Pellet* pel = mPellet.getPtr();
	mState      = STATE_Wait;
	mPiki->startLook(&pel->mSRT.t);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait), PaniMotionInfo(PIKIANIM_Wait));
	mWaitTimer = 3.0f;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
f32 ActTransport::getCarriers()
{
	STACK_PAD_VAR(1);
	Pellet* pel = mPellet.getPtr();
	if (pel) {
		Stickers stuckList(pel);
		STACK_PAD_VAR(3);
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00001C
 */
int ActTransport::getNumStickers()
{
	Pellet* pel = mPellet.getPtr();
	if (pel) {
		return pel->mCarrierCounter;
	}
	return 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000140
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

/**
 * @TODO: Documentation
 */
ActTransport::ActTransport(Piki* piki)
    : Action(piki, true)
{
	setName("Transport");
	mPathIndex = -1;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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
	mFinishPutting    = false;
	mIsLiftActionDone = false;
	mGoal             = nullptr;
	setSlotIndex();
	mCanCarry = false;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void ActTransport::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		mIsLiftActionDone = true;
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
			mFinishPutting = true;
			break;
		}
		if (mState == STATE_Lift) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_PickLoop, this), PaniMotionInfo(PIKIANIM_PickLoop));
			mIsLiftActionDone = false;
			mLiftRetryCount   = int(3.0f * gsys->getRand(1.0f)) + 5;
		}
		break;
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000064
 */
void ActTransport::initJump()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mVelocity.y = 0.5f * AIConstant::_instance->mConstants.mGravity();
	mJumpRetryTimer    = 0;
	mState             = STATE_Jump;
}

/**
 * @TODO: Documentation
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
	Vector3f slotDir = slotPos - mPiki->mSRT.t;
	f32 slotDistXZ   = speedy_sqrtf(slotDir.x * slotDir.x + slotDir.z * slotDir.z);
	f32 slotHeight   = slotDir.y;
	f32 dist         = slotDir.normalise() - pel->getCentreSize();

	if (slotDistXZ > 60.0f) {
		mStateProgress = 0;
		mState         = STATE_Go;
		return ACTOUT_Continue;
	}

	if (absF(slotHeight) <= 8.8f) {
		if (!pel->isSlotFree(mSlotIndex)) {
			int oldSlot = mSlotIndex;
			mSlotIndex  = pel->getNearestFreeSlotIndex(mPiki->mSRT.t);
			if (oldSlot == mSlotIndex) {
				mPiki->mEmotion = PikiEmotion::Sad;
				return ACTOUT_Fail;
			}
			if (mSlotIndex == -1) {
				mPiki->mEmotion = PikiEmotion::Sad;
				return ACTOUT_Fail;
			}

			mStateProgress = 0;
			mState         = STATE_Go;
			mWaitTimer     = 3.0f;
			return ACTOUT_Continue;
		}

		mPiki->mFaceDirection = roundAng(atan2f(slotDir.x, slotDir.z));
		mPiki->mSRT.r.y       = mPiki->mFaceDirection;
		mState                = STATE_Lift;

		mPiki->startMotion(PaniMotionInfo(PIKIANIM_PickLoop, this), PaniMotionInfo(PIKIANIM_PickLoop));
		mPiki->enableMotionBlend();
		PRINT("start try sound \n");
		pel->setTrySound(true);

		Vector3f pelNorm(0.0f, pel->getCylinderHeight(), 0.0f);
		mIsLiftActionDone = false;
		mLiftRetryCount   = int(3.0f * gsys->getRand(1.0f)) + 5;
		mPiki->startStickObject(pel, nullptr, mSlotIndex, 0.0f);

		seSystem->playPikiSound(SEF_PIKI_HANG, mPiki->mSRT.t);
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);

		int numStickers = calcNumStickers();
		int minWeight   = pel->mConfig->mCarryMinPikis();
		Vector3f carryInfoPos(pel->mSRT.t);
		carryInfoPos.y += 5.0f + pel->getCylinderHeight();

		pel->mLifeGauge.countOn(carryInfoPos, numStickers, minWeight);
		return ACTOUT_Continue;
	}

	if (mPiki->mGroundTriangle) {
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

/**
 * @TODO: Documentation
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
	Vector3f slotDirection = targetSlotPos - mPiki->mSRT.t;
	f32 horizontalDist     = speedy_sqrtf(slotDirection.x * slotDirection.x + slotDirection.z * slotDirection.z);
	f32 verticalDist       = slotDirection.y;
	f32 totalDist          = slotDirection.normalise();
	f32 distToCentre       = totalDist - pellet->getCentreSize();

	if (horizontalDist < 100.0f && ++mStateProgress >= 60) {
		int previousSlot = mSlotIndex;
		mSlotIndex       = pellet->getNearestFreeSlotIndex(mPiki->mSRT.t);
		if (previousSlot == mSlotIndex) {
			mPiki->mEmotion = PikiEmotion::Sad;
			return false;
		}

		if (mSlotIndex == -1) {
			mPiki->mEmotion = PikiEmotion::Sad;
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
			mSlotIndex = pellet->getNearestFreeSlotIndex(mPiki->mSRT.t);
			if (mSlotIndex == -1) {
				mPiki->mEmotion = PikiEmotion::Sad;
				return false;
			}

			mStateProgress = 0;
			mState         = STATE_Go;
			mWaitTimer     = 3.0f;
			return true;
		}

		mPiki->mFaceDirection = roundAng(atan2f(slotDirection.x, slotDirection.z));
		mPiki->mSRT.r.y       = mPiki->mFaceDirection;
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
		mIsLiftActionDone = false;
		mLiftRetryCount   = int(3.0f * gsys->getRand(1.0f)) + 5;
		mPiki->startStickObject(pellet, nullptr, mSlotIndex, 0.0f);
		seSystem->playPikiSound(SEF_PIKI_HANG, mPiki->mSRT.t);
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);

		int currentCarriers  = calcNumStickers();
		int requiredCarriers = pellet->mConfig->mCarryMinPikis();
		Vector3f carryInfoPos(pellet->mSRT.t);
		carryInfoPos.y += 5.0f + pellet->getCylinderHeight();
		pellet->mLifeGauge.countOn(carryInfoPos, currentCarriers, requiredCarriers);
		return true;
	}

	Vector3f centreDir = pellet->getCentre() - mPiki->mSRT.t;
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
			mSlotIndex = pellet->getNearestFreeSlotIndex(mPiki->mSRT.t);
			if (mSlotIndex == -1) {
				mPiki->mEmotion = PikiEmotion::Sad;
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

/**
 * @TODO: Documentation
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
			bool landOnly       = doLandOnly();
			WayPoint* nearestWP = nullptr;
			WayPoint* wpA;
			WayPoint* wpB;
			bool fxCheck = false;
			if (pel->mWaterFxTimer) {
				fxCheck = true;
			}
			PRINT("** NEAREST EDGE AVOID OFF =================\n");
			routeMgr->findNearestEdgeAvoidOff(&wpA, &wpB, 'test', mPiki->mSRT.t, landOnly, false, fxCheck);

			if (wpA && wpB) {
				PRINT("** FIND NEAREST EDGE %d and %d\n", wpA->mIndex, wpB->mIndex);
			}

			if (wpA && wpB) {
				Vector3f sepA = wpA->mPosition - mPiki->mSRT.t;
				Vector3f sepB = wpB->mPosition - mPiki->mSRT.t;
				if (sepA.length() > sepB.length()) {
					nearestWP = wpB;
				} else {
					nearestWP = wpA;
				}
			} else {
				PRINT("gakkari desu ...\n");
				nearestWP = routeMgr->findNearestWayPoint('test', mPiki->mSRT.t, landOnly);
			}

			int idx       = nearestWP->mIndex;
			int goalWPIdx = mGoal->getRouteIndex();
			int maxNumWP  = routeMgr->getNumWayPoints('test') - 1;
			PRINT_KANDO("PATHFINDING : %d ==> %d\n", idx, goalWPIdx);
			if (idx < 0 || idx > maxNumWP || goalWPIdx < 0 || goalWPIdx > maxNumWP) {
				ERROR("sorry");
			}
			PRINT("start find route\n");
			if (landOnly) {
				PathFinder::setMode(PathFinderMode::AvoidWater);
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
						PRINT_GLOBAL("end of abusan!");
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
			mCanCarry    = true;
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

/**
 * @TODO: Documentation
 */
bool ActTransport::useWaterRoute()
{
	Pellet* pel      = mPellet.getPtr();
	CollTriInfo* tri = pel->mGroundTriangle;
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

/**
 * @TODO: Documentation
 */
int ActTransport::exec()
{
	Pellet* pel = mPellet.getPtr();
	if (pel) {
		if (!pel->isVisible()) {
			if (pel->isUfoParts()) {
				if (pel->getState() == PELSTATE_Goal) {
					mPiki->mEmotion          = PikiEmotion::ShipPartCheer;
					mPiki->mCarryingShipPart = pel;
				} else {
					mPiki->mEmotion = PikiEmotion::Sad;
				}
			} else if (pel->getState() == PELSTATE_Goal) {
				mPiki->mEmotion          = PikiEmotion::ShipPartGaze;
				mPiki->mCarryingShipPart = pel;
			} else {
				mPiki->mEmotion = PikiEmotion::Sad;
			}
			return ACTOUT_Fail;
		}
	} else {
		PRINT("target is NULL!\n");
		mPiki->mEmotion = PikiEmotion::Searching;
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

			Vector3f goalDir = mGoal->getGoalPos() - pel->mSRT.t;
			f32 goalDistXZ   = speedy_sqrtf(goalDir.x * goalDir.x + goalDir.z * goalDir.z);
			if (goalDir.normalise() == 0.0f) {
				goalDir.set(0.0f, 0.0f, 0.0f);
			}
			mCanCarry = true;

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

					STACK_PAD_INLINE(1);

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
				mPiki->mEmotion          = PikiEmotion::ShipPartCheer;
				mPiki->mCarryingShipPart = mPellet.getPtr();
			} else {
				mPiki->mEmotion = PikiEmotion::Sad;
			}
		} else if (pel->getState() == PELSTATE_Goal) {
			mPiki->mEmotion          = PikiEmotion::ShipPartGaze;
			mPiki->mEmotion          = PikiEmotion::ShipPartGaze;
			mPiki->mCarryingShipPart = mPellet.getPtr();
		} else {
			mPiki->mEmotion = PikiEmotion::Sad;
		}
		return ACTOUT_Success;
	}
	}

	STACK_PAD_INLINE(1);

	return ACTOUT_Continue;
}

/**
 * @TODO: Documentation
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
		WayPoint* wp          = routeMgr->getWayPoint('test', mPiki->mPathBuffers[mPathIndex].mWayPointIdx);
		immut Vector3f& wpPos = wp->mPosition;

		if (wp->mIsOpen && !(wp->mFlags & WayPointFlags::Pebble) && crPointOpen(mPathIndex + 1)) {
			PRINT("curr = %d : currBase = %d\n", mPathIndex, mNextPathIndex);
			PRINT("==== 開通ざました ====(%d) : %d (route %d)\n", wp->mIndex, mPathIndex,
			      mPiki->mPathBuffers[mPathIndex].mWayPointIdx); // '==== opened ===='
			PRINT("::: route=%s type=%s\n", (wp->mIsOpen) ? "on" : "*** off ***", (wp->mFlags & WayPointFlags::Pebble) ? "pebble" : "---");
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
		STACK_PAD_VAR(1);
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
			if (!gameflow.mMoviePlayer->mIsActive && !playerState->mDemoFlags.isFlag(DEMOFLAG_CarryPathBlocked)) {
				playerState->mDemoFlags.setFlagOnly(DEMOFLAG_CarryPathBlocked);
				if (pel->aiCullable()) {
					gameflow.mGameInterface->message(MOVIECMD_TextDemo, 23);
				} else {
					GameCoreSection::startTextDemo(pel, 23);
				}
			}
		}

		Vector3f dirToPath = pathDir - pel->mSRT.t;
		f32 distToPath     = dirToPath.length();

		if (distToPath > 80.0f) {
			PRINT_GLOBAL("might stray guru : %.1f", distToPath);
			doLift();
			return ACTOUT_Continue;
		}

		Vector3f vel(sinf(mWaitTimer), 0.0f, cosf(mWaitTimer));
		STACK_PAD_VAR(1);
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

/**
 * @TODO: Documentation
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

	PRINT_KANDO("###### decide goal\n");
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
			PRINT_KANDO("color %d : is max (%d)\n", i, maxCount);
		}
	}

	for (i = 0; i < PikiColorCount; i++) {
		if (colorCounts[i] == maxCount) {
			optionColors[numOptions++] = i;
		}
	}

	int randColor = (f32(numOptions) * gsys->getRand(1.0f));
	if (randColor >= numOptions) {
		PRINT_KANDO("random select color=%d : maxcols=%d\n", randColor, numOptions);
		randColor = Blue;
	}

	onyonColor = optionColors[randColor];
	PRINT_KANDO(" ## color %d is selected\n", onyonColor);
	mGoal                     = itemMgr->getContainer(onyonColor);
	mPellet.mPtr->mTargetGoal = mGoal; // hmm.

	if (!mGoal) {
		PRINT("SORRY *** goal(color%d) is required !!\n", onyonColor);
		ERROR("zannnen\n"); // 'too bad'
	}
	STACK_PAD_VAR(1);
}

/**
 * @TODO: Documentation
 */
void ActTransport::cleanup()
{
	mPiki->endStickObject();
	Pellet* pel = mPellet.getPtr();
	if (pel) {
		int numStickers = calcNumStickers();
		int minCarry    = pel->mConfig->mCarryMinPikis();
		if (numStickers > 0) {
			Vector3f carryInfoPos(pel->mSRT.t);
			carryInfoPos.y += pel->getCylinderHeight() + 5.0f;
			pel->mLifeGauge.countOn(carryInfoPos, numStickers, minCarry);

		} else {
			pel->mLifeGauge.countOff();
			pel->setTrySound(false);
		}
	}
	mPellet.reset();
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

	return wp->mIsOpen && !(wp->mFlags & WayPointFlags::Pebble);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000078
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

/**
 * @TODO: Documentation
 */
void ActTransport::crInit()
{
	Pellet* pel     = mPellet.getPtr();
	mNextPathIndex  = -1;
	mRouteStartPos  = pel->mSRT.t;
	Vector3f point1 = crGetPoint(mNextPathIndex + 1);
	Vector3f point2 = crGetPoint(mNextPathIndex + 2);
	Tube crTube(point1, point2, crGetRadius(mNextPathIndex + 1), crGetRadius(mNextPathIndex + 2));
	f32 collDepth;
	Vector3f pushVec;
	Sphere sphere(pel->mSRT.t, 0.0f);
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
			f32 proj         = pathDir.DP(pel->mSRT.t - wpA->mPosition) / pathDist;
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

	STACK_PAD_TERNARY(mPiki, 1);
}

/**
 * @TODO: Documentation
 */
void ActTransport::crMakeRefs()
{
	for (int i = 0; i < 4; i++) {
		mSplineControlPts[i] = crGetPoint(mNextPathIndex + i - 1);
	}
}

/**
 * @TODO: Documentation
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
			f32 proj = pathDir.DP(teki->mSRT.t - point1) / pathDist;
			Vector3f vec;
			STACK_PAD_INLINE(1);
			vec = (proj * pathDist) * pathDir + point1;
			vec = vec - teki->mSRT.t;
			vec.normalise();
			f32 unusedWeightedVal = crGetRadius(mNextPathIndex) * (1.0f - proj) + crGetRadius(mNextPathIndex + 1) * (proj);
		}
	}

	STACK_PAD_INLINE(2);
}

/**
 * @TODO: Documentation
 */
bool ActTransport::crMove()
{
#if 0 // Seems to only exist in the DLL, and it's very repetitive.
#define ASSERT_MVDIR_NOTNAN(...)                                       \
	if (isNan(mMoveDir.x) || isNan(mMoveDir.y) || isNan(mMoveDir.z)) { \
		ERROR(__VA_ARGS__);                                            \
	}
#else
#define ASSERT_MVDIR_NOTNAN(...)
#endif

	Pellet* pel        = mPellet.getPtr();
	Vector3f currPoint = crGetPoint(mNextPathIndex);
	Vector3f point2(mSplineControlPts[2]);

	if ((mNextPathIndex == -1 && !crPointOpen(1)) || (mNextPathIndex != -1 && !crPointOpen(mNextPathIndex + 1))) {
		PRINT("******** GURUGURU START : currBase+1 = %d is off !\n", mNextPathIndex);
		PRINT("ROUTE IS OFF !!! currBase+1 = %d\n", mNextPathIndex + 1);
		PRINT("ROUTE INDEX IS %d\n", mPiki->mPathBuffers[mNextPathIndex + 1].mWayPointIdx);
		PRINT_GLOBAL("crPoint : offp=%d", mPiki->mPathBuffers[mNextPathIndex + 1].mWayPointIdx);

		WayPoint* wp = routeMgr->getWayPoint('test', mPiki->mPathBuffers[mNextPathIndex + 1].mWayPointIdx);
		if (wp) {
			PRINT("** ROUTE POINT %d is %s : %s\n", wp->mIndex, wp->mIsOpen ? "on" : "off",
			      wp->mFlags & WayPointFlags::Pebble ? "pebble" : "-");
		}

		mState             = STATE_Guru;
		mSpinStartPosition = pel->mSRT.t;
		mWaitTimer         = 0.0f;
		return true;
	}

	Vector3f dir = point2 - pel->mSRT.t;
	if (qdist2(point2.x, point2.z, pel->mSRT.t.x, pel->mSRT.t.z) < 6.0f) {
		if (mNextPathIndex >= mNumRoutePoints - 2) {
			mState   = STATE_Goal;
			mMoveDir = CRSplineTangent(1.0f, mSplineControlPts);
			ASSERT_MVDIR_NOTNAN("mvDir 1");
			mMoveDir.normalise();
			return true;
		}

		mNextPathIndex++;
		mPathIndex++;
		crMakeRefs();
		findObstacle();
		mMoveDir = CRSplineTangent(0.0f, mSplineControlPts);
		ASSERT_MVDIR_NOTNAN("mvDir nan 2");
		mMoveDir.normalise();
		return true;
	}

	Vector3f pathDir = point2 - currPoint;

	f32 pathDist = pathDir.normalise();
	if (pathDist <= 0.0f) {
		PRINT("DANGER ** CYLINDER ZERO! \n");
#if defined(VERSION_PIKIDEMO)
		// Kando, just use an ERROR at this point if you're so worried about it.
		for (int i = 0; i < 100; ++i) {
			PRINT("** ABUNAI DESU \n"); // "It's dangerous \n"
		}
#endif
	}

#if defined(VERSION_PIKIDEMO)
	f32 factor = pathDir.DP(pel->mSRT.t - currPoint) / pathDist;
#else
	f32 factor;
	if (pathDist > 0.0f) {
		factor = pathDir.DP(pel->mSRT.t - currPoint) / pathDist;
	} else {
		factor = 1.0f;
	}
#endif

	if (factor < 0.0f) {
		factor = 0.0f;
	}

	if (factor > 1.0f) {
		factor = 1.0f;
	}

	Vector3f vec;
	vec              = (factor * pathDist) * pathDir + currPoint;
	vec              = vec - pel->mSRT.t;
	vec.y            = 0.0f;
	f32 val1         = vec.normalise();
	f32 weightedProj = crGetRadius(mNextPathIndex) * (1.0f - factor) + crGetRadius(mNextPathIndex + 1) * factor;

	f32 blend = absF(val1) / weightedProj;

	if (blend < 0.3f) {
		blend = 0.0f;
	}

	if (blend > 2.0f && absF(val1) > 130.0f) {
		PRINT_GLOBAL("danger root strayed:blend %.2f\n", blend);
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
			ASSERT_MVDIR_NOTNAN("mvDir nan 3");
			mMoveDir.normalise();
			return true;
		}

		mNextPathIndex++;
		mPathIndex++;
		factor = 0.0f;
		crMakeRefs();
		findObstacle();
		mMoveDir = CRSplineTangent(factor, mSplineControlPts);
		ASSERT_MVDIR_NOTNAN("mvDir nan 4");
		mMoveDir.normalise();
		return true;
	}

	mMoveDir = CRSplineTangent(factor, mSplineControlPts);
	ASSERT_MVDIR_NOTNAN("mvDir nan 5");
	mMoveDir.normalise();

	mMoveDir = (1.0f - blend) * mMoveDir + blend * vec;
	ASSERT_MVDIR_NOTNAN("mvDir nan 6 blend=%f", blend);

	if (mMoveDir.x * pathDir.x + mMoveDir.z * pathDir.z <= 0.0f) {
		mMoveDir = pathDir;
		PRINT("adjust mvDir (%.1f %.1f %.1f)\n", mMoveDir.x, mMoveDir.y, mMoveDir.z);
	}

	if (!gameflow.mMoviePlayer->mIsActive) {
		bool isMoving = mOdometer.moving(pel->mSRT.t, pel->mLastPosition);
		if (!isMoving) {
			PRINT_GLOBAL("pellet %s is not moving", pel->mConfig->mPelletId.mStringID);
			return false;
		}
	}

#undef ASSERT_MVDIR_NOTNAN
}

/**
 * @TODO: Documentation
 */
void ActTransport::draw(Graphics& gfx)
{
	if (!AIPerf::kandoOnly) {
		return;
	}

	if (!isStickLeader()) {
		return;
	}

	const char* stateNames[] = {
		"go", "wait", "lift", "move", "guru", "goal", "put",
	};

	const char* type[] = {
		"tube",
		"vert",
		"other",
	};

	Vector3f pikiPos = mPiki->mSRT.t;
	char buf2[256];
	char buf1[256];
	sprintf(buf1, " ");

	if (mState == STATE_Move) {
		Pellet* pel        = mPellet.getPtr();
		Vector3f currPoint = crGetPoint(mNextPathIndex);
		Vector3f nextPoint = crGetPoint(mNextPathIndex + 1);
		Vector3f pathDir   = nextPoint - currPoint;
		f32 pathDist       = pathDir.normalise();
		f32 proj           = pathDir.DP(pel->mSRT.t - currPoint) / pathDist;
		if (proj < 0.0f) {
			proj = 0.0f;
		}
		if (proj > 1.0f) {
			proj = 1.0f;
		}

		Vector3f vec;
		vec              = (proj * pathDist) * pathDir + currPoint;
		vec              = vec - pel->mSRT.t;
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
	gfx.setColour(COLOUR_WHITE, true);
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

/**
 * @TODO: Documentation
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
		if (!wp->mIsOpen || (wp->mFlags & WayPointFlags::Pebble)) {
			Vector3f currPoint = crGetPoint(mPathIndex);
			Vector3f nextPoint = crGetPoint(mPathIndex + 1);
			Vector3f pathDir   = nextPoint - currPoint;
			pathDir.normalise();
			Plane plane;
			plane.mNormal = pathDir;
			plane.mOffset = pathDir.DP(currPoint);
			if (plane.dist(pel->mSRT.t) <= 0.0f) {
				PRINT("===== MOVETOWAY POINT !\n");
				PRINT("plane Dist=%f\n", plane.dist(pel->mSRT.t));
				PRINT("curr=%d : idx=%d **** WAYPOINT IS OFF !!!\n", mPathIndex, mPiki->mPathBuffers[mPathIndex].mWayPointIdx);
				PRINT_GLOBAL("moveWay : offp=%d", mPiki->mPathBuffers[mNextPathIndex + 1].mWayPointIdx);
				mSpinStartPosition = pel->mSRT.t;
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

	STACK_PAD_VAR(1);
}
