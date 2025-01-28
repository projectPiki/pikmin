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
 * Size:	0000F4
 */
DEFINE_PRINT("aiEscape")

/*
 * --INFO--
 * Address:	800B8828
 * Size:	00007C
 */
ActEscape::ActEscape(Piki* piki)
    : Action(piki, false)
{
	mTarget.reset();
}

/*
 * --INFO--
 * Address:	800B88A4
 * Size:	000004
 */
void ActEscape::Initialiser::initialise(Action*)
{
}

/*
 * --INFO--
 * Address:	800B88A8
 * Size:	0000F8
 */
void ActEscape::init(Creature* target)
{
	mEscapeTimer = randFloat(2.0f) + 4.0f;
	mTarget.set(target);
	mState = STATE_Normal;
	mActor->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	PRINT(" escape start\n");
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Nigeru), PaniMotionInfo(PIKIANIM_Nigeru));
}

/*
 * --INFO--
 * Address:	800B89A0
 * Size:	000040
 */
void ActEscape::cleanup()
{
	mTarget.reset();
}

/*
 * --INFO--
 * Address:	800B89E0
 * Size:	0002CC
 */
int ActEscape::exec()
{
	Creature* target = mTarget.getPtr();
	if (!target->isVisible()) {
		return ACTOUT_Fail;
	}

	mEscapeTimer -= gsys->getFrameTime();
	if (mEscapeTimer < 0.0f) {
		return ACTOUT_Success;
	}

	bool unused;
	if (mEscapeTimer > 10.0f) {
		unused       = false;
		mEscapeTimer = 10.0f;
	}

	switch (mState) {
	case STATE_Normal:
		Vector3f dir = mActor->mPosition - target->mPosition;
		Vector3f tmp(dir);
		f32 dist = dir.length();
		if (dist > 0.0f) {
			dir = (1.0f / dist) * dir;
		} else {
			f32 randAngle = 2.0f * randFloat(PI);
			dir.set(cosf(randAngle), 0.0f, sinf(randAngle));
		}

		mActor->setSpeed(1.0f, dir);
		if (mActor->getAvoid(mActor->mTargetVelocity, _24)) {
			mState = STATE_Avoid;
			Vector3f moveDir(-_24.z, 0.0f, _24.x);
			mActor->setSpeed(1.0f, moveDir);
		}
		break;
	case STATE_Avoid:
		if (mActor->getAvoid(mActor->mTargetVelocity, _24)) {
			Vector3f moveDir(-_24.z, 0.0f, _24.x);
			mActor->setSpeed(1.0f, moveDir);
		} else {
			mState = STATE_Normal;
		}
		break;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800B8CAC
 * Size:	000058
 */
void ActEscape::getInfo(char* buf)
{
	sprintf(buf, "esc(%s) (%.1f,%.1f)", mState == STATE_Normal ? "NORMAL" : "AVOID", mActor->mTargetVelocity.x, mActor->mTargetVelocity.z);
}
