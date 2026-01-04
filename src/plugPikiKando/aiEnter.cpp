#include "DebugLog.h"
#include "GoalItem.h"
#include "Interactions.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "zen/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(18)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Enter")

/**
 * @todo: Documentation
 */
ActEnter::ActEnter(Piki* piki)
    : Action(piki, true)
{
	setName("Enter");
	mCurrActionIdx = PikiAction::NOACTION;
}

/**
 * @todo: Documentation
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

	Vector3f onionPosition(mOnyon->mSRT.t);
	onionPosition       = onionPosition - mPiki->mSRT.t;
	f32 distanceToOnion = onionPosition.length();
	if (distanceToOnion > 400.0f) {
		mState = 0;
		if (!mPiki->initRouteTrace(mOnyon->mSRT.t, false)) {
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 000064
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
int ActEnter::exec()
{
	if (mState == STATE_Climb) {
		if (PikiMgr::containerDebug) {
			PRINT("  %x enter (%.1f %.1f %.1f) : ropePos %f\n", mPiki, mPiki->mSRT.t.x, mPiki->mSRT.t.y, mPiki->mSRT.t.z,
			      mPiki->mRopePosRatio);
			if (absF(mPiki->mSRT.t.x) > 10000.0f || absF(mPiki->mSRT.t.y) > 10000.0f || absF(mPiki->mSRT.t.z) > 10000.0f) {
				ERROR("stoP!\n");
			}
		}
	}

	switch (mState) {
	case STATE_RouteMove:
	{
		return routeMove();
	}
	case STATE_GotoLeg:
	{
		return gotoLeg();
	}
	case STATE_Climb:
	{
		return climb();
	}
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActEnter::procCollideMsg(Piki*, MsgCollide* msg)
{
	if (msg->mEvent.mCollider->mObjType == OBJTYPE_Pellet && (mState == STATE_GotoLeg || mState == STATE_Climb)) {
		PRINT("enter : collide with %s\n", ObjType::getName(msg->mEvent.mCollider->mObjType));
		mHasCollided = true;
	}
}

/**
 * @todo: Documentation
 */
int ActEnter::gotoLeg()
{
	if (mPiki->mRope) {
		PRINT_KANDO("goto leg ok! %x\n", mPiki);
		mState = STATE_Climb;
		mPiki->playEventSound(mOnyon, SE_CONTAINER_CLIMB);
		mPiki->mVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_HNoboru), PaniMotionInfo(PIKIANIM_HNoboru));
		return ACTOUT_Continue;
	}

	if (mHasCollided && !mPiki->mOdometer.moving(mPiki->mSRT.t, mLastPosition)) {
		return ACTOUT_Fail;
	}

	mLastPosition   = mPiki->mSRT.t;
	Vector3f legDir = mLeg->mCentre - mPiki->mSRT.t;
	f32 unused      = legDir.normalise();
	mPiki->setSpeed(0.5f, legDir);
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
int ActEnter::climb()
{
	if (!mPiki->mRope || mPiki->mRopePosRatio > 0.9f) {
		PRINT_KANDO("enter goal ???\n");
		mOnyon->enterGoal(mPiki);
		return ACTOUT_Fail;
	}

	if (mHasCollided) {
		return ACTOUT_Fail;
	}

	if (mPiki->mRopePosRatio > 0.72f) {
		PRINT_KANDO("piki->ropePos = %f\n", mPiki->mRopePosRatio);
		mPiki->mIsCallable = false;
		f32 scale          = (1.0f - mPiki->mRopePosRatio) / (1.0f - 0.72f) * 1.0f;
		if (scale < 0.0f) {
			scale = 0.0f;
		}
		mPiki->mSRT.s.set(scale, scale, scale);
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

/**
 * @todo: Documentation
 */
void ActEnter::cleanup()
{
	mPiki->endRope();
}
