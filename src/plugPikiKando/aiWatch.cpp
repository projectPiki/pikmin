#include "DebugLog.h"
#include "PikiAI.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @TODO: Documentation
 */
void ActWatch::AnimListener::animationKeyUpdated(immut PaniAnimKeyEvent&)
{
}

/**
 * @TODO: Documentation
 */
ActWatch::ActWatch(Piki* piki)
    : Action(piki, true)
{
	mTarget.reset();
	mListener = new AnimListener(this, piki);
}

/**
 * @TODO: Documentation
 */
void ActWatch::Initialiser::initialise(Action*)
{
}

/**
 * @TODO: Documentation
 */
void ActWatch::init(Creature* target)
{
	if (target) {
		mWatchRetryTimer = int(20.0f * gsys->getRand(1.0f)) + 50;
		mTarget.set(target);
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait), PaniMotionInfo(PIKIANIM_Wait));
		mPiki->enableMotionBlend();
		mTargetPosition = target->getCentre();
		mTargetPosition.y += 1.6f * target->getBoundingSphereRadius();
	}
}

/**
 * @TODO: Documentation
 */
void ActWatch::cleanup()
{
	mTarget.reset();
	mPiki->finishLook();
}

/**
 * @TODO: Documentation
 */
void ActWatch::getInfo(char* buffer)
{
	sprintf(buffer, "watch(%d)", mWatchRetryTimer);
}

/**
 * @TODO: Documentation
 */
int ActWatch::exec()
{
	Creature* target = mTarget.getPtr();
	if (!target || !target->isVisible()) {
		return ACTOUT_Fail;
	}

	if (--mWatchRetryTimer < 0) {
		return ACTOUT_Success;
	}

	// what the hell did you do man
	Vector3f lookDir = target->mSRT.t - mPiki->mSRT.t;
	Vector3f* p      = &lookDir;

	f32 dist = qdist2(0.0f, 0.0f, lookDir.x, lookDir.z);
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mPiki->mFaceDirection += 0.4f * angDist(atan2f(lookDir.x, lookDir.z), mPiki->mFaceDirection);
	mPiki->mFaceDirection = roundAng(mPiki->mFaceDirection);
	mPiki->mSRT.r.set(0.0f, mPiki->mFaceDirection, 0.0f);
	return ACTOUT_Continue;

	STACK_PAD_VAR(7);
}
