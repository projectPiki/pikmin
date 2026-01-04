#include "DebugLog.h"
#include "KMath.h"
#include "PikiAI.h"
#include "PikiState.h"
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
DEFINE_PRINT("aiRescue")

/**
 * @todo: Documentation
 */
ActRescue::ActRescue(Piki* piki)
    : Action(piki, true)
{
	setName("Rescue");
}

/**
 * @todo: Documentation
 */
void ActRescue::init(Creature* target)
{
	if (!target || !target->isPiki()) {
		mDrowningPiki = nullptr;
	} else {
		mDrowningPiki = static_cast<Piki*>(target);
	}

	initApproach();
}

/**
 * @todo: Documentation
 */
int ActRescue::exec()
{
	if (!mDrowningPiki) {
		mPiki->mEmotion = PikiEmotion::Searching;
		return ACTOUT_Fail;
	}

	if (!mDrowningPiki->isAlive()) {
		mPiki->mEmotion = PikiEmotion::Sad;
		return ACTOUT_Fail;
	}

	int state = mDrowningPiki->getState();
	if (state != PIKISTATE_Drown && state != PIKISTATE_WaterHanged && state != PIKISTATE_Flying) {
		// target is somehow surviving on their own
		mTargetSurviveTimer++;
		PRINT("target survive : timer =%d\n", mTargetSurviveTimer);
	} else {
		mTargetSurviveTimer = 0;
	}

	switch (mState) {
	case STATE_Approach:
	{
		if (mTargetSurviveTimer > 20) {
			// target survived on their own for long enough
			mPiki->mEmotion = PikiEmotion::Victorious;
			return ACTOUT_Success;
		}
		return exeApproach();
	}
	case STATE_Go:
	{
		if (mTargetSurviveTimer > 20) {
			// target survived on their own for long enough
			mPiki->mEmotion = PikiEmotion::Victorious;
			return ACTOUT_Success;
		}
		return exeGo();
	}
	case STATE_Throw:
	{
		return exeThrow();
	}
	case STATE_Rescue:
	{
		return exeRescue();
	}
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActRescue::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
	{
		if (mState == STATE_Rescue || (!mThrowReady && mState == STATE_Throw)) {
			mGotAnimationAction = true;
		}
		break;
	}
	case KEY_Finished:
	{
		if (!mThrowReady && mState == STATE_Throw) {
			mAnimationFinished = true;
		}
		break;
	}
	}
}

/**
 * @todo: Documentation
 */
void ActRescue::initApproach()
{
	mState = STATE_Approach;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
}

/**
 * @todo: Documentation
 */
int ActRescue::exeApproach()
{
	Vector3f dir = mDrowningPiki->mSRT.t - mPiki->mSRT.t;
	f32 dist     = dir.normalise();
	if (dist < 5.0f) {
		initRescue();
		return ACTOUT_Continue;
	}

	mPiki->setSpeed(0.7f, dir);
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActRescue::initRescue()
{
	mState = STATE_Rescue;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_ThrowWait, this), PaniMotionInfo(PIKIANIM_ThrowWait));
	mPiki->enableMotionBlend();
	mGotAnimationAction = false;
}

/**
 * @todo: Documentation
 */
int ActRescue::exeRescue()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (mGotAnimationAction) {
		mDrowningPiki->mFSM->transit(mDrowningPiki, PIKISTATE_WaterHanged);
		initGo();
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActRescue::initGo()
{
	mState                = STATE_Go;
	WayPoint* wp          = routeMgr->findNearestWayPoint('test', mPiki->mSRT.t, true);
	mRescueTargetPosition = wp->mPosition;
	Vector3f dir          = mPiki->mSRT.t - mRescueTargetPosition;
	f32 dist              = dir.normalise();
	if (dist > wp->mRadius) {
		mRescueTargetPosition = mRescueTargetPosition + dir * wp->mRadius * 0.8f;
	}

	mRescueTargetPosition.y += 30.0f;
}

/**
 * @todo: Documentation
 */
int ActRescue::exeGo()
{
	Vector3f offset(sinf(mPiki->mFaceDirection), 0.0f, cosf(mPiki->mFaceDirection));
	offset.multiply(-5.0f);
	offset.y += 10.0f;
	mDrowningPiki->mSRT.t = mPiki->mSRT.t + offset;
	Vector3f dir          = mRescueTargetPosition - mPiki->mSRT.t;
	f32 dist              = dir.normalise();
	if (dist < 200.0f) {
		initThrow();
		return ACTOUT_Continue;
	}

	mPiki->setSpeed(0.5f, dir);
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActRescue::initThrow()
{
	mState              = STATE_Throw;
	mGotAnimationAction = false;
	mAnimationFinished  = false;
	mThrowReady         = true;
	PRINT("INIT THROW!\n");
}

/**
 * @todo: Documentation
 */
int ActRescue::exeThrow()
{
	STACK_PAD_VAR(2);
	int state = mDrowningPiki->getState();
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (mThrowReady) {
		Vector3f dir = mRescueTargetPosition - mPiki->mSRT.t;
		f32 diff     = atan2f(dir.x, dir.z);
		f32 angle    = angDist(diff, mPiki->mFaceDirection);
		if (absF(angle) < 0.25132743f) {
			mThrowReady = false;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Throw, this), PaniMotionInfo(PIKIANIM_Throw));
			PRINT("THROW MOTION START\n");
		}

		mPiki->mFaceDirection = roundAng(angle * gsys->getFrameTime() * 0.3f + mPiki->mFaceDirection);
	}

	if (mGotAnimationAction) {
		PRINT("got key : target state = %d\n", mDrowningPiki->getState());
		Vector3f dir = mDrowningPiki->mSRT.t - mPiki->mSRT.t;
		f32 dist     = dir.length();
		if (dist < 15.0f) {
			Vector3f vec1(0.0f, 0.0f, 0.0f);
			Vector3f throwVel;
			throwVel = getThrowVelocity(mPiki->mSRT.t, 200.0f, mRescueTargetPosition, vec1);
			mDrowningPiki->mFSM->transit(mDrowningPiki, PIKISTATE_Flying);
			mDrowningPiki->mVelocity       = throwVel;
			mDrowningPiki->mTargetVelocity = throwVel;
			PRINT("throw Piki !\n");
		}
		mGotAnimationAction = false;
	}

	if (mAnimationFinished) {
		mPiki->mEmotion = PikiEmotion::Victorious;
		PRINT("rescue done\n");
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActRescue::cleanup()
{
}
