#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Interactions.h"
#include "PikiAI.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("aiBoMake");

/**
 * @todo: Documentation
 */
ActBoMake::ActBoMake(Piki* piki)
    : Action(piki, true)
{
}

/**
 * @todo: Documentation
 */
void ActBoMake::init(Creature* creature)
{
	mBuildObject = nullptr;
	if (creature && creature->mObjType == OBJTYPE_BoBase) {
		mBuildObject = creature;
	}

	initApproach();
}

/**
 * @todo: Documentation
 */
int ActBoMake::exec()
{
	if (!mBuildObject) {
		PRINT("done!\n");
		return ACTOUT_Fail;
	}

	if (!mBuildObject->isAlive()) {
		mPiki->mEmotion = PikiEmotion::Happy;
		return ACTOUT_Success;
	}

	switch (mState) {
	case STATE_Approach:
	{
		return exeApproach();
	}
	case STATE_Work:
	{
		return exeWork();
	}
	}

	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActBoMake::initApproach()
{
	mState = STATE_Approach;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
}

/**
 * @todo: Documentation
 */
int ActBoMake::exeApproach()
{
	Vector3f direction = mBuildObject->mSRT.t - mPiki->mSRT.t;
	if (direction.normalise() - mBuildObject->getCentreSize() - mPiki->getCentreSize() < 3.0f) {
		initWork();
		return ACTOUT_Continue;
	}

	mPiki->setSpeed(1.0f, direction);
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActBoMake::initWork()
{
	// can't stick to a work object if piki is already stuck to something
	if (mPiki->isStickTo()) {
		return;
	}

	mPiki->startStickObject(mBuildObject, mBuildObject->mCollInfo->getSphere('cent'), -1, 0.0f);
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
}

/**
 * @todo: Documentation
 */
int ActBoMake::exeWork()
{
	return ACTOUT_Continue;
}

/**
 * @todo: Documentation
 */
void ActBoMake::cleanup()
{
	mPiki->endStickObject();
}

/**
 * @todo: Documentation
 */
void ActBoMake::animationKeyUpdated(immut PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
	{
		break;
	}
	case KEY_Action0:
	{
		InteractBuild build(mPiki, 0, 1.0f);
		mBuildObject->stimulate(build); // the one time it's not in the same line, smh
		break;
	}
	}
}
