#include "PikiAI.h"
#include "PikiMgr.h"
#include "zen/Math.h"
#include "GoalItem.h"
#include "Interactions.h"
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
 * Size:	0000F0
 */
DEFINE_PRINT("Enter")

/*
 * --INFO--
 * Address:	800B7F64
 * Size:	000060
 */
ActEnter::ActEnter(Piki* piki)
    : Action(piki, true)
{
	setName("Enter");
	mCurrActionIdx = PikiAction::NOACTION;
}

/*
 * --INFO--
 * Address:	800B7FC4
 * Size:	0001F0
 */
void ActEnter::init(Creature* target)
{
	mHasCollided = false;
	if (target && target->mObjType == OBJTYPE_Goal) {
		mOnyon = static_cast<GoalItem*>(target);
	} else {
		PRINT("TARGET IS %x : %d\n", target, target ? target->mObjType : -1);
		ERROR("karl caught a cold !\n");
	}

	findLeg();

	Vector3f onionPosition(mOnyon->mPosition);
	onionPosition       = onionPosition - mPiki->mPosition;
	f32 distanceToOnion = onionPosition.length();
	if (distanceToOnion > 400.0f) {
		mState = 0;
		if (!mPiki->initRouteTrace(mOnyon->mPosition, false)) {
			PRINT("zannen !\n");
			mPiki->mOdometer.start(1.0f, 5.0f);
			mState = STATE_GotoLeg;
		}
	} else {
		mState = STATE_GotoLeg;
		mPiki->mOdometer.start(1.0f, 5.0f);
	}

	if (mPiki->hasBomb()) {
		InteractRelease release(mPiki, 1.0f);
		Creature* held = mPiki->getHoldCreature();
		held->stimulate(release);
	}

	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
int ActEnter::routeMove()
{
	if (!mPiki->moveRouteTrace(1.0f)) {
		mPiki->mOdometer.start(1.0f, 5.0f);
		mState = STATE_GotoLeg;
		return ACTOUT_Continue;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800B81B4
 * Size:	0000CC
 */
void ActEnter::findLeg()
{
	CollPart* legs[3];
	legs[0] = mOnyon->mCollInfo->getSphere('bas1');
	legs[1] = mOnyon->mCollInfo->getSphere('bas2');
	legs[2] = mOnyon->mCollInfo->getSphere('bas3');

	int randIdx = int(3.0f * (0.99999988f * gsys->getRand(1.0f)));
	mLeg        = legs[randIdx];
}

/*
 * --INFO--
 * Address:	800B8280
 * Size:	0000E8
 */
int ActEnter::exec()
{
	if (mState == STATE_Climb) {
		if (PikiMgr::containerDebug) {
			PRINT("  %x enter (%.1f %.1f %.1f) : ropePos %f\n", mPiki, mPiki->mPosition.x, mPiki->mPosition.y, mPiki->mPosition.z,
			      mPiki->mRopePosRatio);
			if (zen::Abs(mPiki->mPosition.x) > 10000.0f || zen::Abs(mPiki->mPosition.y) > 10000.0f
			    || zen::Abs(mPiki->mPosition.z) > 10000.0f) {
				ERROR("stoP!\n");
			}
		}
	}

	switch (mState) {
	case STATE_RouteMove:
		return routeMove();
	case STATE_GotoLeg:
		return gotoLeg();
	case STATE_Climb:
		return climb();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800B8368
 * Size:	000058
 */
void ActEnter::procCollideMsg(Piki*, MsgCollide* msg)
{
	if (msg->mEvent.mCollider->mObjType == OBJTYPE_Pellet && (mState == STATE_GotoLeg || mState == STATE_Climb)) {
		PRINT("enter : collide with %s\n", ObjType::getName(msg->mEvent.mCollider->mObjType));
		mHasCollided = 1;
	}
}

/*
 * --INFO--
 * Address:	800B83C0
 * Size:	0001AC
 */
int ActEnter::gotoLeg()
{
	if (mPiki->mRope) {
		PRINT("goto leg ok! %x\n", mPiki);
		mState = STATE_Climb;
		mPiki->playEventSound(mOnyon, SE_CONTAINER_CLIMB);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_HNoboru), PaniMotionInfo(PIKIANIM_HNoboru));
		return ACTOUT_Continue;
	}

	if (mHasCollided && !mPiki->mOdometer.moving(mPiki->mPosition, mLastPosition)) {
		return ACTOUT_Fail;
	}

	mLastPosition   = mPiki->mPosition;
	Vector3f legDir = mLeg->mCentre - mPiki->mPosition;
	f32 unused      = legDir.normalise();
	mPiki->setSpeed(0.5f, legDir);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800B856C
 * Size:	000234
 */
int ActEnter::climb()
{
	if (!mPiki->mRope || mPiki->mRopePosRatio > 0.9f) {
		PRINT("enter goal ???\n");
		mOnyon->enterGoal(mPiki);
		return ACTOUT_Fail;
	}

	if (mHasCollided) {
		return ACTOUT_Fail;
	}

	if (mPiki->mRopePosRatio > 0.72f) {
		PRINT("piki->ropePos = %f\n", mPiki->mRopePosRatio);
		mPiki->mIsCallable = false;
		f32 scale          = (1.0f - mPiki->mRopePosRatio) / (1.0f - 0.72f) * 1.0f;
		if (scale < 0.0f) {
			scale = 0.0f;
		}
		mPiki->mScale.set(scale, scale, scale);
	}

	f32 sideWeight = 8.0f * (gsys->getRand(1.0f) - 0.5f);
	Vector3f ropeDir(mPiki->mRope->mRopeDirection);
	Vector3f facingVector(sinf(mPiki->mFaceDirection), 0.0f, cosf(mPiki->mFaceDirection));
	Vector3f sideDir(facingVector);
	sideDir.CP(ropeDir);
	sideDir.normalise();
	f32 climbSpeed   = 15.0f;
	mPiki->mVelocity = ropeDir * climbSpeed + sideDir * sideWeight;
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800B87A0
 * Size:	000024
 */
void ActEnter::cleanup()
{
	mPiki->endRope();
}
