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
 * Address:	800C2C54
 * Size:	000004
 */
void ActWatch::AnimListener::animationKeyUpdated(PaniAnimKeyEvent&)
{
}

/*
 * --INFO--
 * Address:	800C2C58
 * Size:	0000C4
 */
ActWatch::ActWatch(Piki* piki)
    : Action(piki, true)
{
	mTarget.reset();
	mListener = new AnimListener(this, piki);
}

/*
 * --INFO--
 * Address:	800C2D1C
 * Size:	000004
 */
void ActWatch::Initialiser::initialise(Action*)
{
}

/*
 * --INFO--
 * Address:	800C2D20
 * Size:	000148
 */
void ActWatch::init(Creature* target)
{
	if (target) {
		_18 = int(randFloat(20.0f)) + 50;
		mTarget.set(target);
		mActor->startMotion(PaniMotionInfo(PIKIANIM_Wait), PaniMotionInfo(PIKIANIM_Wait));
		mActor->enableMotionBlend();
		_20 = target->getCentre();
		_20.y += 1.6f * target->getBoundingSphereRadius();
	}
}

/*
 * --INFO--
 * Address:	800C2E68
 * Size:	000048
 */
void ActWatch::cleanup()
{
	mTarget.reset();
	mActor->finishLook();
}

/*
 * --INFO--
 * Address:	800C2EB0
 * Size:	000038
 */
void ActWatch::getInfo(char* buffer)
{
	sprintf(buffer, "watch(%d)", _18);
}

/*
 * --INFO--
 * Address:	800C2EE8
 * Size:	00015C
 */
int ActWatch::exec()
{
	Creature* target = mTarget.getPtr();
	if (!target || !target->isVisible()) {
		return ACTOUT_Fail;
	}

	if (--_18 < 0) {
		return ACTOUT_Success;
	}

	// what the hell did you do man
	Vector3f lookDir = target->mPosition - mActor->mPosition;
	Vector3f* p      = &lookDir;

	f32 dist = qdist2(0.0f, 0.0f, lookDir.x, lookDir.z);
	mActor->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mActor->mFaceDirection += 0.4f * angDist(atan2f(lookDir.x, lookDir.z), mActor->mFaceDirection);
	mActor->mFaceDirection = roundAng(mActor->mFaceDirection);
	mActor->mRotation.set(0.0f, mActor->mFaceDirection, 0.0f);
	return ACTOUT_Continue;

	u32 badCompiler[7];
}
