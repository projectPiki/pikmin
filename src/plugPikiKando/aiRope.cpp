#include "PikiAI.h"
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
	mActor->startMotion(PaniMotionInfo(PIKIANIM_HNoboru), PaniMotionInfo(PIKIANIM_HNoboru));
	mActor->setCreatureFlag(CF_Unk8);
	mSpeed = randBalanced(0.5f) * 4.0f + 22.0f;
	if (mActor->isHolding()) {
		mActor->_408 = 3;
	}

	if (mActor->mStickPart) {
		Tube tube;
		mActor->mStickPart->makeTube(tube);
		Vector3f vec1;
		Vector3f vec2;
		tube.getPosGradient(mActor->mPosition, mActor->mAttachPosition.x, vec1, vec2);
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
	if (!mActor->mStickPart) {
		return ACTOUT_Fail;
	}

	mActor->mVelocity = mRopeDirection * mSpeed;
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800C206C
 * Size:	00009C
 */
void ActRope::cleanup()
{
	mActor->mVelocity       = mRopeDirection * 150.0f;
	mActor->mTargetVelocity = mActor->mVelocity;
	mActor->mCreatureFlags &= ~(CF_Unk8);
	mActor->endStickObject();
}
