#include "TAI/MotionActions.h"
#include "teki.h"
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
DEFINE_PRINT("taimotionactions")

/*
 * --INFO--
 * Address:	80134018
 * Size:	000038
 */
void TaiMotionAction::start(Teki& teki)
{
	teki.startMotion(mMotionIdx);
}

/*
 * --INFO--
 * Address:	80134050
 * Size:	000020
 */
bool TaiMotionAction::act(Teki& teki)
{
	if (teki.animationFinished()) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80134070
 * Size:	0000FC
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

		teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
	}
}

/*
 * --INFO--
 * Address:	8013416C
 * Size:	000074
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

/*
 * --INFO--
 * Address:	801341E0
 * Size:	000024
 */
bool TaiContinuousMotionAction::motionStarted(Teki& teki)
{
	int currMotionIdx = teki.mTekiAnimator->getCurrentMotionIndex();
	if (currMotionIdx == mMotionIdx) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80134204
 * Size:	00004C
 */
void TaiFinishMotionAction::start(Teki& teki)
{
	teki.mTekiAnimator->finishMotion(PaniMotionInfo(-1, &teki));
}

/*
 * --INFO--
 * Address:	80134250
 * Size:	000020
 */
bool TaiAnimationKeyAction::act(Teki& teki)
{
	if (teki.getAnimationKeyOption(mAnimKeyOpt)) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	80134270
 * Size:	00000C
 */
void TaiCountLoopAction::start(Teki& teki)
{
	teki.mMotionLoopCount = 0;
}

/*
 * --INFO--
 * Address:	8013427C
 * Size:	00003C
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

/*
 * --INFO--
 * Address:	801342B8
 * Size:	00005C
 */
void TaiSwitchMotionAction::start(Teki& teki)
{
	f32 counter = teki.mTekiAnimator->getCounter();
	TaiMotionAction::start(teki);
	teki.mTekiAnimator->setCounter(counter);
}

/*
 * --INFO--
 * Address:	80134314
 * Size:	0000D4
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

/*
 * --INFO--
 * Address:	801343E8
 * Size:	000004
 */
void TaiStoppingMoveAction::start(Teki& teki)
{
}

/*
 * --INFO--
 * Address:	801343EC
 * Size:	000064
 */
bool TaiStoppingMoveAction::act(Teki& teki)
{
	int currMotionidx = teki.mTekiAnimator->getCurrentMotionIndex();
	if (currMotionidx == mMotionIdx) {
		if (teki.getAnimationKeyOption(BTeki::ANIMATION_KEY_OPTION_LOOPEND)) {
			PRINT("TaiStoppingMoveAction::act:%08x:LOOPEND:%f,%f\n", &teki, teki.mAnimationSpeed, teki.mPreStopAnimationSpeed);
			teki.startStoppingMove();
		} else if (teki.animationFinished()) {
			PRINT("TaiStoppingMoveAction::act:%08x:animationFinished\n", &teki);
			teki.finishStoppingMove();
		}
	}
	return false;
}

/*
 * --INFO--
 * Address:	80134450
 * Size:	000004
 */
void TaiStoppingMoveAction::finish(Teki& teki)
{
}

/*
 * --INFO--
 * Address:	80134454
 * Size:	000024
 */
void TaiFinishStoppingMoveAction::start(Teki& teki)
{
	teki.finishStoppingMove();
}

/*
 * --INFO--
 * Address:	80134478
 * Size:	00003C
 */
void TaiSetFrameMotionAction::start(Teki& teki)
{
	teki.mTekiAnimator->setCounter(teki.mTekiAnimator->getKeyValueByKeyType(mKeyType));
}

/*
 * --INFO--
 * Address:	801344B4
 * Size:	0000AC
 */
void TaiRandomSetAnimationCounterAction::start(Teki& teki)
{
	f32 min = teki.mTekiAnimator->getKeyValueByKeyType(mMinKeyType);
	f32 max = teki.mTekiAnimator->getKeyValueByKeyType(mMaxKeyType);
	teki.mTekiAnimator->setCounter(NMathF::rangeRandom(min, max - 1.0f));
}
