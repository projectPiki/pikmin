#include "DebugLog.h"
#include "PaniPikiAnimator.h"

PaniMotionTable* PaniPikiAnimMgr::motionTable;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("TODO: Replace")

/**
 * @todo: Documentation
 * @note UNUSED Size: 000034
 */
PaniMotionTable* PaniPikiAnimMgr::getMotionTable()
{
	return motionTable;
}

/**
 * @todo: Documentation
 */
PaniPikiAnimMgr::PaniPikiAnimMgr()
{
}

/**
 * @todo: Documentation
 */
void PaniPikiAnimMgr::init(AnimMgr* mgr, AnimContext* context1, AnimContext* context2, PaniMotionTable* table)
{
	if (!motionTable) {
		motionTable = PaniPikiAnimator::createMotionTable();
	}

	PaniMotionTable* sTable = getMotionTable();
	mUpperAnimator.init(context1, mgr, sTable);
	mLowerAnimator.init(context2, mgr, sTable);

	mAnimSpeed = 30.0f;
}

/**
 * @todo: Documentation
 */
void PaniPikiAnimMgr::changeContext(AnimContext* context1, AnimContext* context2)
{
	mUpperAnimator.changeContext(context1);
	mLowerAnimator.changeContext(context2);
}

/**
 * @todo: Documentation
 */
void PaniPikiAnimMgr::startMotion(immut PaniMotionInfo* motion1, immut PaniMotionInfo* motion2)
{
	if (motion1) {
		mUpperAnimator.startMotion(*motion1);
	}
	if (motion2) {
		mLowerAnimator.startMotion(*motion2);
	}
}

/**
 * @todo: Documentation
 */
void PaniPikiAnimMgr::finishMotion(immut PaniMotionInfo* motion1, immut PaniMotionInfo* motion2)
{
	if (motion1) {
		mUpperAnimator.finishMotion(*motion1);
	}
	if (motion2) {
		mLowerAnimator.finishMotion(*motion2);
	}
}

/**
 * @todo: Documentation
 */
void PaniPikiAnimMgr::startMotion(immut PaniMotionInfo& motion1, immut PaniMotionInfo& motion2)
{
	startMotion(&motion1, &motion2);
}

/**
 * @todo: Documentation
 */
void PaniPikiAnimMgr::finishMotion(PaniAnimKeyListener* listener)
{
	finishMotion(&PaniMotionInfo(PANI_NO_MOTION, listener), &PaniMotionInfo(PANI_NO_MOTION, nullptr));
}

/**
 * @todo: Documentation
 */
void PaniPikiAnimMgr::updateAnimation(f32 speed)
{
	if (mUpperAnimator.isFinished()) {
		if (mAnimSpeed < mUpperAnimator.getAnimationSpeed()) {
			mAnimSpeed = mUpperAnimator.getAnimationSpeed();
		}
	} else {
		mAnimSpeed = speed;
	}

	f32 currSpeed = mAnimSpeed;
	if (!mUpperAnimator.getCurrentOption(ANIMFLAG_UseDynamicSpeed)) {
		mAnimSpeed = mUpperAnimator.getAnimationSpeed();
	}

	mUpperAnimator.animate(mAnimSpeed);

	if (!mLowerAnimator.getCurrentOption(ANIMFLAG_UseDynamicSpeed)) {
		mAnimSpeed = mLowerAnimator.getAnimationSpeed();
	}

	mLowerAnimator.animate(currSpeed);
}

/**
 * @todo: Documentation
 */
void PaniPikiAnimMgr::updateContext()
{
	mUpperAnimator.updateContext();
	mLowerAnimator.updateContext();
}
