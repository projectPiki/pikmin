#include "DebugLog.h"
#include "Interactions.h"
#include "PikiAI.h"
#include "PikiMgr.h"
#include "WorkObject.h"

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
DEFINE_PRINT("aiPush")

/*
 * --INFO--
 * Address:	800BDFF0
 * Size:	0000A0
 */
ActPush::ActPush(Piki* piki)
    : Action(piki, true)
{
	setName("Push");
	mHinderRock = nullptr;
}

/*
 * --INFO--
 * Address:	800BE090
 * Size:	000098
 */
void ActPush::init(Creature* target)
{
	mPushAnimationState = 2;
	mPiki->mActionState = 2;
	mPiki->mEmotion     = PikiEmotion::Happy;
	mHinderRock         = 0;
	if (target && target->mObjType == OBJTYPE_WorkObject) {
		WorkObject* obj = (WorkObject*)target;
		if (obj->isHinderRock()) {
			mHinderRock = (HinderRock*)obj;
		}
	}
	mState             = STATE_Approach;
	mPushObjectStopped = false;
	_44                = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
bool ActPush::collideRockSurface()
{
	Creature* collide = mPiki->getCollidePlatformCreature();
	if (collide && collide == mHinderRock) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800BE128
 * Size:	0000CC
 */
int ActPush::exec()
{
	if (_44 == 1) {
		return ACTOUT_Continue;
	}

	if (_44 == 2) {
		mPiki->mEmotion = PikiEmotion::Sad;
		return ACTOUT_Fail;
	}

	if (mHinderRock->isMoving() && mPushObjectStopped) {
		mPushObjectStopped = false;
		_40                = pikiMgr->mPikiParms->mPikiParms._49C();
	} else if (!mHinderRock->isMoving()) {
		mPushObjectStopped = true;
	}

	_44 = 0;
	switch (mState) {
	case STATE_Approach:
		return exeApproach();
	case STATE_Go:
		return exeGo();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void ActPush::initApproach()
{
	mState = STATE_Approach;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Run, this), PaniMotionInfo(PIKIANIM_Run));
}

/*
 * --INFO--
 * Address:	800BE1F4
 * Size:	000110
 */
int ActPush::exeApproach()
{
	if (!mHinderRock) {
		return ACTOUT_Fail;
	}

	u8 planeFlag = mHinderRock->getPlaneFlag(mPiki->mPosition);
	if (planeFlag == 0x4) {
		initGo();
		return ACTOUT_Continue;
	}

	Vector3f moveDir;
	switch (planeFlag) {
	case 0x2:
	case 0x1 | 0x2:
	case 0x8:
	case 0x8 | 0x1:
		return ACTOUT_Fail;

	case 0:
		moveDir = mHinderRock->getZVector();
		break;

	case 0x2 | 0x4:
		moveDir = mHinderRock->getXVector();
		moveDir.multiply(-1.0f);
		break;

	case 0x4 | 0x8:
		moveDir = mHinderRock->getXVector();
		break;

	case 0x1:
		return ACTOUT_Fail;
	}

	mPiki->setSpeed(0.8f, moveDir);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800BE304
 * Size:	00013C
 */
void ActPush::initGo()
{
	mState       = STATE_Go;
	mIsPushReady = false;
	mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	mPushAnimationState = 2;
	if (mHinderRock) {
		_38 = gsys->getRand(1.0f);
	}

	_40 = pikiMgr->mPikiParms->mPikiParms._49C();
	if (!mPushObjectStopped) {
		mPushObjectStopped = true;
	}

	mIsPushReady = true;
	mPushCount   = int(5.0f * gsys->getRand(1.0f)) + 5;

	if (mHinderRock) {
		mHinderRock->beginPush();
		PRINT("BEGIN PUSH !!\n");
	}
}

/*
 * --INFO--
 * Address:	800BE440
 * Size:	000214
 */
int ActPush::exeGo()
{
	if (!mHinderRock) {
		// sir, what do you think is gonna happen here if mHinderRock is null.
		mHinderRock->endPush();
		return ACTOUT_Fail;
	}

	if (mHinderRock->isFinished()) {
		mHinderRock->endPush();
		return ACTOUT_Success;
	}

	u8 planeFlag = mHinderRock->getPlaneFlag(mPiki->mPosition);

	if (planeFlag != 0x4) {
		mHinderRock->endPush();
		initApproach();
		return ACTOUT_Continue;
	}

	Vector3f zVec = mHinderRock->getZVector();
	zVec.multiply(-1.0f);
	mPiki->setSpeed(1.0f, zVec);

	if (collideRockSurface()) {
		InteractPush push(mPiki, 1);
		mHinderRock->stimulate(push);
		if (mIsPushReady) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Osu, this), PaniMotionInfo(PIKIANIM_Osu));
			mPushAnimationState = 0;
			mIsPushReady        = false;
		}
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800BE654
 * Size:	0002D4
 */
void ActPush::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_LoopStart:
		break;
	case KEY_Action0:
	case KEY_Action1:
		if (mPushAnimationState == 0 && mHinderRock && mHinderRock->isMoving()) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Osu_Walk, this), PaniMotionInfo(PIKIANIM_Osu_Walk));
			f32 frame = 11.0f;
			if (event.mEventType == KEY_Action0) {
				frame = 10.0f;
			}

			mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = frame;
			mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = frame;
			mPushAnimationState                                      = 1;
		}
		break;
	case KEY_LoopEnd:
		if (mPushAnimationState == 1 && mHinderRock && !mHinderRock->isMoving()) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Osu, this), PaniMotionInfo(PIKIANIM_Osu));
			mPushCount                                               = int(5.0f * gsys->getRand(1.0f)) + 5;
			mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 30.0f;
			mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 30.0f;
			mPushAnimationState                                      = 0;
		}

		if (mPushAnimationState == 0) {
			mPushCount--;
			PRINT("loopCnt = %d\n", mPushCount);
			if (mPushCount <= 0) {
				PRINT("osu count = 0: finish motion\n");
				mPiki->mPikiAnimMgr.finishMotion(this);
			}
		}

		_24 = 1;
		break;
	case KEY_Finished:
		if (_44) {
			_44 = 2;
			break;
		}

		if (mState == STATE_Go) {
			PRINT("restart motion !\n");
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Osu, this), PaniMotionInfo(PIKIANIM_Osu));
			mPushCount = int(5.0f * gsys->getRand(1.0f)) + 5;
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	800BE928
 * Size:	000038
 */
void ActPush::cleanup()
{
	if (mState == STATE_Go && mHinderRock) {
		mHinderRock->endPush();
	}
}
