#include "DebugLog.h"
#include "Dolphin/os.h"
#include "TAI/Amotion.h"
#include "system.h"
#include "teki.h"

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
DEFINE_PRINT("TAIAmotion")

/*
 * --INFO--
 * Address:	801ACC54
 * Size:	000024
 */
TAIAmotion::TAIAmotion(int nextState, int motionID)
    : TaiAction(nextState)
{
	mMotionID = motionID;
}

/*
 * --INFO--
 * Address:	801ACC78
 * Size:	00004C
 */
void TAIAmotion::start(Teki& teki)
{
	teki.mTekiAnimator->startMotion(PaniMotionInfo(mMotionID, &teki));
}

/*
 * --INFO--
 * Address:	801ACCC4
 * Size:	00001C
 */
bool TAIAmotion::act(Teki& teki)
{
	if (teki.mCurrentAnimEvent == KEY_Finished) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	801ACCE0
 * Size:	000024
 */
TAIAreserveMotion::TAIAreserveMotion(int nextState, int motionID)
    : TaiAction(nextState)
{
	mMotionID = motionID;
}

/*
 * --INFO--
 * Address:	801ACD04
 * Size:	0001B4
 */
void TAIAreserveMotion::start(Teki& teki)
{
	if (mMotionID != teki.mTekiAnimator->mMotionIdx) {
		if (teki.mTekiAnimator->mMotionIdx < 0) {
			teki.mTekiAnimator->startMotion(PaniMotionInfo(mMotionID, &teki));
			return;
		}

		if (teki.mTekiAnimator->getCounter() >= f32(teki.mTekiAnimator->mAnimInfo->mData->mTotalFrameCount - 2)) {
			teki.mTekiAnimator->startMotion(PaniMotionInfo(mMotionID, &teki));
			return;
		}

		teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
		return;
	}

	if (teki.mTekiAnimator->getCounter() >= f32(teki.mTekiAnimator->mAnimInfo->mData->mTotalFrameCount - 2)) {
		teki.mTekiAnimator->startMotion(PaniMotionInfo(mMotionID, &teki));
	}

	if (teki.mTekiAnimator->mIsFinished) {
		f32 frame = teki.mTekiAnimator->getCounter();
		teki.mTekiAnimator->startMotion(PaniMotionInfo(mMotionID, &teki));
		teki.mTekiAnimator->setCounter(frame);
	}
}

/*
 * --INFO--
 * Address:	801ACEB8
 * Size:	000088
 */
bool TAIAreserveMotion::act(Teki& teki)
{
	if (mMotionID != teki.mTekiAnimator->mMotionIdx) {
		if (teki.mTekiAnimator->getCurrentKeyIndex() < 0) {
			teki.mTekiAnimator->startMotion(PaniMotionInfo(mMotionID, &teki));
			teki.mCurrentAnimEvent = KEY_Reserved;
			return true;
		}
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	801ACF40
 * Size:	000034
 */
void TAIAmotionLoop::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFrameCounter(0.0f);
}

/*
 * --INFO--
 * Address:	801ACF74
 * Size:	000118
 */
bool TAIAmotionLoop::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		teki.addFrameCounter(gsys->getFrameTime());
		if (teki.getFrameCounter() > getFrameMax(teki)) {
			res = true;
			teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
		}
	}
	return res;
}
