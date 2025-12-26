#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Interactions.h"
#include "PikiAI.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("aiActions");

/**
 * @todo: Documentation
 */
ActPick::ActPick(Piki* piki)
    : Action(piki, true)
{
	mObject.reset();
}

/**
 * @todo: Documentation
 */
void ActPick::Initialiser::initialise(Action* action)
{
#if 0
	ActPick* act = (ActPick*)action;
	PRINT(" initialiser called ###################### \n");
	act->mObject = mObject;
#endif
}

/**
 * @todo: Documentation
 */
void ActPick::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		Creature* obj = mObject.getPtr();
		if (obj && obj->isVisible() && qdist2(obj, mPiki) < 20.0f) {
			obj->stimulate(InteractGrab(mPiki));
		}
		break;

	case KEY_Finished:
		mIsAnimationFinished = true;
		break;
	}
}

/**
 * @todo: Documentation
 */
void ActPick::init(Creature* object)
{
	mIsAnimationFinished = false;
	mObject.set(object);

	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick, this), PaniMotionInfo(PIKIANIM_Pick));
	mPiki->enableMotionBlend();
}

/**
 * @todo: Documentation
 */
void ActPick::cleanup()
{
	Creature* obj = mObject.getPtr();
	mObject.reset();
}

/**
 * @todo: Documentation
 */
int ActPick::exec()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (mIsAnimationFinished) {
		if (!mPiki->isHolding()) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
			mPiki->mEmotion = PikiEmotion::Sad;
			return ACTOUT_Fail;
		}

		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000040
 */
ActPut::ActPut(Piki* piki)
    : Action(piki, false)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void ActPut::Initialiser::initialise(Action*)
{
}

/**
 * @todo: Documentation
 */
void ActPut::init(Creature*)
{
	mFailCountdownTimer = 0.5f;
}

/**
 * @todo: Documentation
 */
void ActPut::cleanup()
{
}

/**
 * @todo: Documentation
 */
int ActPut::exec()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);

	Creature* obj = mPiki->getHoldCreature();
	if (!obj) {
		return ACTOUT_Fail;
	}

	if (obj->stimulate(InteractRelease(mPiki, 1.0f))) {
		PRINT("release ?\n");
		return ACTOUT_Success;
	}

	mFailCountdownTimer -= gsys->getFrameTime();
	if (mFailCountdownTimer < 0.0f) {
		return ACTOUT_Fail;
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
ActAdjust::ActAdjust(Piki* piki)
    : Action(piki, true)
{
	mAdjustTimeLimit = 8;
	mAdjustDistance  = 5.0f;
}

/**
 * @todo: Documentation
 */
void ActAdjust::Initialiser::initialise(Action* action)
{
	PRINT(" initialiser called ###################### \n");
	static_cast<ActAdjust*>(action)->mAdjustDistance  = mAdjustDistance;
	static_cast<ActAdjust*>(action)->mAdjustTimeLimit = mAdjustTimeLimit;
}

/**
 * @todo: Documentation
 */
void ActAdjust::init(Creature* target)
{
	PRINT(" act adjust init\n");
	if (target) {
		PRINT(" target is %x\n", target);
		mForceFail      = false;
		mTargetPosition = target->mSRT.t;
		Vector3f dir    = mTargetPosition - mPiki->mSRT.t;
		f32 adjPerFrame = mAdjustTimeLimit * (1.0f / 30.0f);
		STACK_PAD_VAR(1);
		mTurnSpeed = angDist(atan2f(dir.x, dir.z), mPiki->mFaceDirection) / adjPerFrame;
		f32 dist   = dir.length();

		PRINT(" numFrames = %d \n", mAdjustTimeLimit);
		PRINT(" d = %f\n", dist);
		PRINT(" distance : %f\n", mAdjustDistance);
		PRINT(" sec = %f\n", adjPerFrame);
		PRINT(" (d-distance) is %f : 1.0f/sec = %f\n", dist - mAdjustDistance, 1.0f / adjPerFrame);
		mVelocity = ((dist - mAdjustDistance) * (1.0f / dist) * (1.0f / adjPerFrame)) * dir;

		PRINT(" deltaVec(%.1f,%.1f,%.1f) : deltaF(%.1f)\n", mVelocity.x, mVelocity.y, mVelocity.z, mTurnSpeed);
		mAdjustTimer = 0.0f;
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Asibumi), PaniMotionInfo(PIKIANIM_Asibumi));
		mPiki->setCreatureFlag(CF_UsePriorityFaceDir);
	} else {
		mForceFail = true;
	}
}

/**
 * @todo: Documentation
 */
void ActAdjust::cleanup()
{
	mPiki->resetCreatureFlag(CF_UsePriorityFaceDir);
}

/**
 * @todo: Documentation
 */
int ActAdjust::exec()
{
	if (mForceFail) {
		return ACTOUT_Fail;
	}

	mPiki->mVelocity       = mVelocity;
	mPiki->mTargetVelocity = mVelocity;
	mPiki->mFaceDirection += mTurnSpeed * gsys->getFrameTime();
	mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection);
	mPiki->mSRT.r.set(0.0f, mPiki->mFaceDirection, 0.0f);

	mAdjustTimer += gsys->getFrameTime();
	if (mAdjustTimer > f32(mAdjustTimeLimit) * (1 / 30.0f)) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}
