#include "PikiAI.h"
#include "Interactions.h"
#include "system.h"
#include "Dolphin/os.h"
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
DEFINE_PRINT("aiActions");

/*
 * --INFO--
 * Address:	800A79F8
 * Size:	000080
 */
ActPick::ActPick(Piki* piki)
    : Action(piki, true)
{
	mObject.reset();
}

/*
 * --INFO--
 * Address:	800A7A78
 * Size:	000004
 */
void ActPick::Initialiser::initialise(Action* action)
{
	// ActPick* act = (ActPick*)action;
	// PRINT(" initialiser called ###################### \n");
	// act->mObject = mObject;
}

/*
 * --INFO--
 * Address:	800A7A7C
 * Size:	0000D4
 */
void ActPick::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		Creature* obj = mObject.getPtr();
		if (obj && obj->isVisible() && qdist2(obj, mPiki) < 20.0f) {
			obj->stimulate(InteractGrab(mPiki));
		}
		break;

	case KEY_Finished:
		mIsAnimationFinished = 1;
		break;
	}
}

/*
 * --INFO--
 * Address:	800A7B50
 * Size:	0000B8
 */
void ActPick::init(Creature* object)
{
	mIsAnimationFinished = 0;
	mObject.set(object);

	mPiki->startMotion(PaniMotionInfo(4, this), PaniMotionInfo(4));
	mPiki->enableMotionBlend();
}

/*
 * --INFO--
 * Address:	800A7C08
 * Size:	000040
 */
void ActPick::cleanup()
{
	Creature* obj = mObject.getPtr();
	mObject.reset();
}

/*
 * --INFO--
 * Address:	800A7C48
 * Size:	0000B4
 */
int ActPick::exec()
{
	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (mIsAnimationFinished) {
		if (!mPiki->isHolding()) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
			mPiki->mEmotion = PikiEmotion::Unk1;
			return ACTOUT_Fail;
		}

		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
ActPut::ActPut(Piki* piki)
    : Action(piki, false)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A7CFC
 * Size:	000004
 */
void ActPut::Initialiser::initialise(Action*)
{
}

/*
 * --INFO--
 * Address:	800A7D00
 * Size:	00000C
 */
void ActPut::init(Creature*)
{
	mFailCountdownTimer = 0.5f;
}

/*
 * --INFO--
 * Address:	800A7D0C
 * Size:	000004
 */
void ActPut::cleanup()
{
}

/*
 * --INFO--
 * Address:	800A7D10
 * Size:	0000D8
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

/*
 * --INFO--
 * Address:	800A7DE8
 * Size:	00006C
 */
ActAdjust::ActAdjust(Piki* piki)
    : Action(piki, true)
{
	mAdjustTimeLimit = 8;
	mAdjustDistance  = 5.0f;
}

/*
 * --INFO--
 * Address:	800A7E54
 * Size:	000014
 */
void ActAdjust::Initialiser::initialise(Action* action)
{
	PRINT(" initialiser called ###################### \n");
	static_cast<ActAdjust*>(action)->mAdjustDistance  = mAdjustDistance;
	static_cast<ActAdjust*>(action)->mAdjustTimeLimit = mAdjustTimeLimit;
}

/*
 * --INFO--
 * Address:	800A7E68
 * Size:	000200
 */
void ActAdjust::init(Creature* target)
{
	PRINT(" act adjust init\n");
	if (target) {
		PRINT(" target is %x\n", target);
		mForceFail      = 0;
		mTargetPosition = target->mPosition;
		Vector3f dir    = mTargetPosition - mPiki->mPosition;
		f32 adjPerFrame = mAdjustTimeLimit * (1.0f / 30.0f);
		u32 badCompiler;
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
		mPiki->setCreatureFlag(CF_Unk11);
	} else {
		mForceFail = 1;
	}
}

/*
 * --INFO--
 * Address:	800A8068
 * Size:	000014
 */
void ActAdjust::cleanup()
{
	mPiki->resetCreatureFlag(CF_Unk11);
}

/*
 * --INFO--
 * Address:	800A807C
 * Size:	00011C
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
	mPiki->mRotation.set(0.0f, mPiki->mFaceDirection, 0.0f);

	mAdjustTimer += gsys->getFrameTime();
	if (mAdjustTimer > f32(mAdjustTimeLimit) * (1 / 30.0f)) {
		return ACTOUT_Success;
	}

	return ACTOUT_Continue;
}
