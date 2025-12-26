#include "DebugLog.h"
#include "PikiAI.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @todo: Documentation
 */
ActRope::ActRope(Piki* piki)
    : Action(piki, true)
{
	setName("rope");
	mCurrActionIdx = PikiAction::NOACTION;
}

/**
 * @todo: Documentation
 */
void ActRope::init(Creature*)
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_HNoboru), PaniMotionInfo(PIKIANIM_HNoboru));
	mPiki->setCreatureFlag(CF_IgnoreGravity);
	mSpeed = (gsys->getRand(1.0f) - 0.5f) * 4.0f + 22.0f;
	if (mPiki->isHolding()) {
		mPiki->mActionState = 3;
	}

	if (mPiki->mStickPart) {
		Tube tube;
		mPiki->mStickPart->makeTube(tube);
		Vector3f vec1;
		Vector3f vec2;
		tube.getPosGradient(mPiki->mSRT.t, mPiki->mAttachPosition.x, vec1, vec2);
		mRopeDirection = vec2;
	} else {
		mRopeDirection.set(0.0f, 1.0f, 0.0f);
	}
}

/**
 * @todo: Documentation
 */
int ActRope::exec()
{
	if (!mPiki->mStickPart) {
		return ACTOUT_Fail;
	}

	mPiki->mVelocity = mRopeDirection * mSpeed;
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActRope::cleanup()
{
	mPiki->mVelocity       = mRopeDirection * 150.0f;
	mPiki->mTargetVelocity = mPiki->mVelocity;
	mPiki->mCreatureFlags &= ~(CF_IgnoreGravity);
	mPiki->endStickObject();
}
