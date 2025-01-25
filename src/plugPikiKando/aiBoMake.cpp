#include "PikiAI.h"
#include "Interactions.h"
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
DEFINE_PRINT("aiBoMake");

/*
 * --INFO--
 * Address:	800AC30C
 * Size:	000054
 */
ActBoMake::ActBoMake(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800AC360
 * Size:	000040
 */
void ActBoMake::init(Creature* creature)
{
	mBuildObject = nullptr;
	if (creature && creature->mObjType == OBJTYPE_BoBase) {
		mBuildObject = creature;
	}

	initApproach();
}

/*
 * --INFO--
 * Address:	800AC3A0
 * Size:	0000A0
 */
int ActBoMake::exec()
{
	if (!mBuildObject) {
		PRINT("done!\n");
		return ACTOUT_Fail;
	}

	if (!mBuildObject->isAlive()) {
		mActor->mEmotion = 0;
		return ACTOUT_Success;
	}

	switch (mState) {
	case STATE_Approach:
		return exeApproach();
	case STATE_Work:
		return exeWork();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AC440
 * Size:	000064
 */
void ActBoMake::initApproach()
{
	mState = STATE_Approach;
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800AC4A4
 * Size:	00012C
 */
int ActBoMake::exeApproach()
{
	Vector3f direction = mBuildObject->mPosition - mActor->mPosition;
	if (direction.normalise() - mBuildObject->getCentreSize() - mActor->getCentreSize() < 3.0f) {
		initWork();
		return ACTOUT_Continue;
	}

	mActor->setSpeed(1.0f, direction);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AC5D0
 * Size:	0000B4
 */
void ActBoMake::initWork()
{
	// can't stick to a work object if piki is already stuck to something
	if (mActor->isStickTo()) {
		return;
	}

	mActor->startStickObject(mBuildObject, mBuildObject->mCollInfo->getSphere('cent'), -1, 0.0f);
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
}

/*
 * --INFO--
 * Address:	800AC684
 * Size:	000008
 */
int ActBoMake::exeWork()
{
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AC68C
 * Size:	000024
 */
void ActBoMake::cleanup()
{
	mActor->endStickObject();
}

/*
 * --INFO--
 * Address:	800AC6B0
 * Size:	000078
 */
void ActBoMake::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
		break;
	case KEY_Action0:
		InteractBuild build(mActor);
		mBuildObject->stimulate(build); // the one time it's not in the same line, smh
		break;
	}
}
