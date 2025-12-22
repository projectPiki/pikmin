#include "DebugLog.h"
#include "PaniPikiAnimator.h"

PaniMotionTable* PaniPikiAnimMgr::motionTable;

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
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
PaniMotionTable* PaniPikiAnimMgr::getMotionTable()
{
	return motionTable;
}

/**
 * @TODO: Documentation
 */
PaniPikiAnimMgr::PaniPikiAnimMgr()
{
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
void PaniPikiAnimMgr::changeContext(AnimContext* context1, AnimContext* context2)
{
	mUpperAnimator.changeContext(context1);
	mLowerAnimator.changeContext(context2);
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
void PaniPikiAnimMgr::startMotion(immut PaniMotionInfo& motion1, immut PaniMotionInfo& motion2)
{
	startMotion(&motion1, &motion2);
}

/**
 * @TODO: Documentation
 */
void PaniPikiAnimMgr::finishMotion(PaniAnimKeyListener* listener)
{
	finishMotion(&PaniMotionInfo(PANI_NO_MOTION, listener), &PaniMotionInfo(PANI_NO_MOTION, nullptr));
}

/**
 * @TODO: Documentation
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
 * @TODO: Documentation
 */
void PaniPikiAnimMgr::updateContext()
{
	mUpperAnimator.updateContext();
	mLowerAnimator.updateContext();
}
