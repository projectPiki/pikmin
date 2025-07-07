#include "DebugLog.h"
#include "PikiAI.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

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
	mEscapeTimer = (2.0f * gsys->getRand(1.0f)) + 4.0f;
	mTarget.set(target);
	mState = STATE_Normal;
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	PRINT(" escape start\n");
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Nigeru), PaniMotionInfo(PIKIANIM_Nigeru));
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

	bool escapeLimitReached;
	if (mEscapeTimer > 10.0f) {
		escapeLimitReached = false;
		mEscapeTimer       = 10.0f;
	}

	switch (mState) {
	case STATE_Normal:
		Vector3f escapeDirection = mPiki->mPosition - target->mPosition;
		Vector3f tmp(escapeDirection);
		f32 dist = escapeDirection.length();
		if (dist > 0.0f) {
			escapeDirection = (1.0f / dist) * escapeDirection;
		} else {
			f32 randAngle = 2.0f * (PI * gsys->getRand(1.0f));
			escapeDirection.set(cosf(randAngle), 0.0f, sinf(randAngle));
		}

		mPiki->setSpeed(1.0f, escapeDirection);
		if (mPiki->getAvoid(mPiki->mTargetVelocity, mAvoidDirection)) {
			mState = STATE_Avoid;
			Vector3f perpMoveDir(-mAvoidDirection.z, 0.0f, mAvoidDirection.x);
			mPiki->setSpeed(1.0f, perpMoveDir);
		}
		break;

	case STATE_Avoid:
		if (mPiki->getAvoid(mPiki->mTargetVelocity, mAvoidDirection)) {
			Vector3f moveDir(-mAvoidDirection.z, 0.0f, mAvoidDirection.x);
			mPiki->setSpeed(1.0f, moveDir);
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
	sprintf(buf, "esc(%s) (%.1f,%.1f)", mState == STATE_Normal ? "NORMAL" : "AVOID", mPiki->mTargetVelocity.x, mPiki->mTargetVelocity.z);
}
