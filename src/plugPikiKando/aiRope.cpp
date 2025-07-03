#include "PikiAI.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	800C1E24
 * Size:	000060
 */
ActRope::ActRope(Piki* piki)
    : Action(piki, true)
{
	setName("rope");
	mCurrActionIdx = PikiAction::NOACTION;
}

/*
 * --INFO--
 * Address:	800C1E84
 * Size:	000178
 */
void ActRope::init(Creature*)
{
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_HNoboru), PaniMotionInfo(PIKIANIM_HNoboru));
	mPiki->setCreatureFlag(CF_Unk8);
	mSpeed = (gsys->getRand(1.0f) - 0.5f) * 4.0f + 22.0f;
	if (mPiki->isHolding()) {
		mPiki->mActionState = 3;
	}

	if (mPiki->mStickPart) {
		Tube tube;
		mPiki->mStickPart->makeTube(tube);
		Vector3f vec1;
		Vector3f vec2;
		tube.getPosGradient(mPiki->mPosition, mPiki->mAttachPosition.x, vec1, vec2);
		mRopeDirection = vec2;
	} else {
		mRopeDirection.set(0.0f, 1.0f, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	800C1FFC
 * Size:	000070
 */
int ActRope::exec()
{
	if (!mPiki->mStickPart) {
		return ACTOUT_Fail;
	}

	mPiki->mVelocity = mRopeDirection * mSpeed;
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C206C
 * Size:	00009C
 */
void ActRope::cleanup()
{
	mPiki->mVelocity       = mRopeDirection * 150.0f;
	mPiki->mTargetVelocity = mPiki->mVelocity;
	mPiki->mCreatureFlags &= ~(CF_Unk8);
	mPiki->endStickObject();
}
