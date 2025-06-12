#include "PikiAI.h"
#include "PikiState.h"
#include "zen/Math.h"
#include "KMath.h"
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
DEFINE_PRINT("aiRescue")

/*
 * --INFO--
 * Address:	800C12E8
 * Size:	000098
 */
ActRescue::ActRescue(Piki* piki)
    : Action(piki, true)
{
	setName("Rescue");
}

/*
 * --INFO--
 * Address:	800C1380
 * Size:	000044
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

/*
 * --INFO--
 * Address:	800C13C4
 * Size:	00014C
 */
int ActRescue::exec()
{
	if (!mDrowningPiki) {
		mPiki->mEmotion = PikiEmotion::Unk7;
		return ACTOUT_Fail;
	}

	if (!mDrowningPiki->isAlive()) {
		mPiki->mEmotion = PikiEmotion::Unk1;
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
		if (mTargetSurviveTimer > 20) {
			// target survived on their own for long enough
			mPiki->mEmotion = PikiEmotion::Unk6;
			return ACTOUT_Success;
		}
		return exeApproach();

	case STATE_Go:
		if (mTargetSurviveTimer > 20) {
			// target survived on their own for long enough
			mPiki->mEmotion = PikiEmotion::Unk6;
			return ACTOUT_Success;
		}
		return exeGo();

	case STATE_Throw:
		return exeThrow();

	case STATE_Rescue:
		return exeRescue();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C1510
 * Size:	00006C
 */
void ActRescue::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		if (mState == STATE_Rescue || (!mThrowReady && mState == STATE_Throw)) {
			mGotAnimationAction = 1;
		}
		break;
	case KEY_Finished:
		if (!mThrowReady && mState == STATE_Throw) {
			mAnimationFinished = 1;
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	800C157C
 * Size:	000064
 */
void ActRescue::initApproach()
{
	mState = STATE_Approach;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800C15E0
 * Size:	0000E4
 */
int ActRescue::exeApproach()
{
	Vector3f dir = mDrowningPiki->mPosition - mPiki->mPosition;
	f32 dist     = dir.normalise();
	if (dist < 5.0f) {
		initRescue();
		return ACTOUT_Continue;
	}

	mPiki->setSpeed(0.7f, dir);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C16C4
 * Size:	00008C
 */
void ActRescue::initRescue()
{
	mState = STATE_Rescue;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_ThrowWait, this), PaniMotionInfo(PIKIANIM_ThrowWait));
	mPiki->enableMotionBlend();
	mGotAnimationAction = 0;
}

/*
 * --INFO--
 * Address:	800C1750
 * Size:	000078
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

/*
 * --INFO--
 * Address:	800C17C8
 * Size:	000184
 */
void ActRescue::initGo()
{
	mState                = STATE_Go;
	WayPoint* wp          = routeMgr->findNearestWayPoint('test', mPiki->mPosition, true);
	mRescueTargetPosition = wp->mPosition;
	Vector3f dir          = mPiki->mPosition - mRescueTargetPosition;
	f32 dist              = dir.normalise();
	if (dist > wp->mRadius) {
		mRescueTargetPosition = mRescueTargetPosition + dir * wp->mRadius * 0.8f;
	}

	mRescueTargetPosition.y += 30.0f;
}

/*
 * --INFO--
 * Address:	800C194C
 * Size:	00016C
 */
int ActRescue::exeGo()
{
	Vector3f offset(sinf(mPiki->mFaceDirection), 0.0f, cosf(mPiki->mFaceDirection));
	offset.multiply(-5.0f);
	offset.y += 10.0f;
	mDrowningPiki->mPosition = mPiki->mPosition + offset;
	Vector3f dir             = mRescueTargetPosition - mPiki->mPosition;
	f32 dist                 = dir.normalise();
	if (dist < 200.0f) {
		initThrow();
		return ACTOUT_Continue;
	}

	mPiki->setSpeed(0.5f, dir);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C1AB8
 * Size:	000020
 */
void ActRescue::initThrow()
{
	mState              = STATE_Throw;
	mGotAnimationAction = 0;
	mAnimationFinished  = 0;
	mThrowReady         = 1;
}

/*
 * --INFO--
 * Address:	800C1AD8
 * Size:	0002B4
 */
int ActRescue::exeThrow()
{
	STACK_PAD_VAR(2);
	int state = mDrowningPiki->getState();
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (mThrowReady) {
		Vector3f dir = mRescueTargetPosition - mPiki->mPosition;
		f32 diff     = atan2f(dir.x, dir.z);
		f32 angle    = angDist(diff, mPiki->mFaceDirection);
		if (absF(angle) < 0.25132743f) {
			mThrowReady = 0;
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Throw, this), PaniMotionInfo(PIKIANIM_Throw));
			PRINT("THROW MOTION START\n");
		}

		mPiki->mFaceDirection = roundAng(angle * gsys->getFrameTime() * 0.3f + mPiki->mFaceDirection);
	}

	if (mGotAnimationAction) {
		PRINT("got key : target state = %d\n", mDrowningPiki->getState());
		Vector3f dir = mDrowningPiki->mPosition - mPiki->mPosition;
		f32 dist     = dir.length();
		if (dist < 15.0f) {
			Vector3f vec1(0.0f, 0.0f, 0.0f);
			Vector3f throwVel;
			throwVel = getThrowVelocity(mPiki->mPosition, 200.0f, mRescueTargetPosition, vec1);
			mDrowningPiki->mFSM->transit(mDrowningPiki, PIKISTATE_Flying);
			mDrowningPiki->mVelocity       = throwVel;
			mDrowningPiki->mTargetVelocity = throwVel;
			PRINT("throw Piki !\n");
		}
		mGotAnimationAction = 0;
	}

	if (mAnimationFinished) {
		mPiki->mEmotion = PikiEmotion::Unk6;
		PRINT("rescue done\n");
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C1D8C
 * Size:	000004
 */
void ActRescue::cleanup()
{
}
