#include "DebugLog.h"
#include "TAI/MotionActions.h"
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
DEFINE_PRINT("taimotionactions")

/**
 * @TODO: Documentation
 */
void TaiMotionAction::start(Teki& teki)
{
	teki.startMotion(mMotionIdx);
}

/**
 * @TODO: Documentation
 */
bool TaiMotionAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		return true;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
void TaiContinuousMotionAction::start(Teki& teki)
{
	int currMotionIdx = teki.mTekiAnimator->getCurrentMotionIndex();
	if (currMotionIdx < 0) {
		TaiMotionAction::start(teki);
		return;
	}

	if (currMotionIdx == mMotionIdx) {
		if (teki.mTekiAnimator->isFinished()) {
			TaiMotionAction::start(teki);
			return;
		}
		if (teki.mTekiAnimator->isFinishing()) {
			TaiMotionAction::start(teki);
			return;
		}

	} else if (currMotionIdx != mMotionIdx) {

		if (teki.mTekiAnimator->isFinishing()) {
			TaiMotionAction::start(teki);
			return;
		}

		teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
	}
}

/**
 * @TODO: Documentation
 */
bool TaiContinuousMotionAction::act(Teki& teki)
{
	int currMotionIdx = teki.mTekiAnimator->getCurrentMotionIndex();
	if (currMotionIdx != mMotionIdx) {
		if (teki.animationFinished()) {
			teki.startMotion(mMotionIdx);
		}
		return false;
	}

	return TaiMotionAction::act(teki);
}

/**
 * @TODO: Documentation
 */
bool TaiContinuousMotionAction::motionStarted(Teki& teki)
{
	int currMotionIdx = teki.mTekiAnimator->getCurrentMotionIndex();
	if (currMotionIdx == mMotionIdx) {
		return true;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
void TaiFinishMotionAction::start(Teki& teki)
{
	teki.mTekiAnimator->finishMotion(PaniMotionInfo(PANI_NO_MOTION, &teki));
}

/**
 * @TODO: Documentation
 */
bool TaiAnimationKeyAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(mAnimKeyOpt)) {
		return true;
	}
	return false;
}

/**
 * @TODO: Documentation
 */
void TaiCountLoopAction::start(Teki& teki)
{
	teki.mMotionLoopCount = 0;
}

/**
 * @TODO: Documentation
 */
bool TaiCountLoopAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_LOOPEND)) {
		teki.mMotionLoopCount++;
		if (teki.mMotionLoopCount >= mMaxLoopCount) {
			return true;
		}
	}

	return false;
}

/**
 * @TODO: Documentation
 */
void TaiSwitchMotionAction::start(Teki& teki)
{
	f32 counter = teki.mTekiAnimator->getCounter();
	TaiMotionAction::start(teki);
	teki.mTekiAnimator->setCounter(counter);
}

/**
 * @TODO: Documentation
 */
bool TaiOutsideKeyStopMoveAction::act(Teki& teki)
{
	f32 counter  = teki.mTekiAnimator->getCounter();
	f32 startKey = teki.mTekiAnimator->getKeyValueByKeyType(mStartKeyType);
	f32 endKey   = teki.mTekiAnimator->getKeyValueByKeyType(mEndKeyType);

	if (!(startKey <= counter) || !(counter <= endKey)) {
		teki.stopMove();
	}
	return false;
}

/**
 * @TODO: Documentation
 */
void TaiStoppingMoveAction::start(Teki& teki)
{
}

/**
 * @TODO: Documentation
 */
bool TaiStoppingMoveAction::act(Teki& teki)
{
	int currMotionidx = teki.mTekiAnimator->getCurrentMotionIndex();
	if (currMotionidx == mMotionIdx) {
		if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_LOOPEND)) {
			PRINT_NAKATA("TaiStoppingMoveAction::act:%08x:LOOPEND:%f,%f\n", &teki, teki.mAnimationSpeed, teki.mPreStopAnimationSpeed);
			teki.startStoppingMove();
		} else if (teki.animationFinished()) {
			PRINT_NAKATA("TaiStoppingMoveAction::act:%08x:animationFinished\n", &teki);
			teki.finishStoppingMove();
		}
	}
	return false;
}

/**
 * @TODO: Documentation
 */
void TaiStoppingMoveAction::finish(Teki& teki)
{
}

/**
 * @TODO: Documentation
 */
void TaiFinishStoppingMoveAction::start(Teki& teki)
{
	teki.finishStoppingMove();
}

/**
 * @TODO: Documentation
 */
void TaiSetFrameMotionAction::start(Teki& teki)
{
	teki.mTekiAnimator->setCounter(teki.mTekiAnimator->getKeyValueByKeyType(mKeyType));
}

/**
 * @TODO: Documentation
 */
void TaiRandomSetAnimationCounterAction::start(Teki& teki)
{
	f32 min = teki.mTekiAnimator->getKeyValueByKeyType(mMinKeyType);
	f32 max = teki.mTekiAnimator->getKeyValueByKeyType(mMaxKeyType);
	teki.mTekiAnimator->setCounter(NMathF::rangeRandom(min, max - 1.0f));
}
