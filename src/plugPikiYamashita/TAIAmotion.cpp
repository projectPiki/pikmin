#include "DebugLog.h"
#include "Dolphin/os.h"
#include "TAI/Amotion.h"
#include "system.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TAIAmotion")

/**
 * @todo: Documentation
 */
TAIAmotion::TAIAmotion(int nextState, int motionID)
    : TaiAction(nextState)
{
	mMotionID = motionID;
}

/**
 * @todo: Documentation
 */
void TAIAmotion::start(Teki& teki)
{
	teki.mTekiAnimator->startMotion(PaniMotionInfo(mMotionID, &teki));
}

/**
 * @todo: Documentation
 */
bool TAIAmotion::act(Teki& teki)
{
	if (teki.mCurrentAnimEvent == KEY_Finished) {
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
TAIAreserveMotion::TAIAreserveMotion(int nextState, int motionID)
    : TaiAction(nextState)
{
	mMotionID = motionID;
}

/**
 * @todo: Documentation
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

		teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void TAIAmotionLoop::start(Teki& teki)
{
	TAIAreserveMotion::start(teki);
	teki.setFrameCounter(0.0f);
}

/**
 * @todo: Documentation
 */
bool TAIAmotionLoop::act(Teki& teki)
{
	bool res = false;
	if (TAIAreserveMotion::act(teki)) {
		teki.addFrameCounter(gsys->getFrameTime());
		if (teki.getFrameCounter() > getFrameMax(teki)) {
			res = true;
			teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
		}
	}
	return res;
}
