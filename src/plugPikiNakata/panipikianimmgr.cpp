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

/*
 * --INFO--
 * Address:	8011F8A0
 * Size:	00003C
 */
PaniPikiAnimMgr::PaniPikiAnimMgr()
{
}

/*
 * --INFO--
 * Address:	8011F8DC
 * Size:	00007C
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

/*
 * --INFO--
 * Address:	8011F958
 * Size:	000060
 */
void PaniPikiAnimMgr::changeContext(AnimContext* context1, AnimContext* context2)
{
	mUpperAnimator.changeContext(context1);
	mLowerAnimator.changeContext(context2);
}

/*
 * --INFO--
 * Address:	8011F9B8
 * Size:	000058
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

/*
 * --INFO--
 * Address:	8011FA10
 * Size:	000058
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

/*
 * --INFO--
 * Address:	8011FA68
 * Size:	000058
 */
void PaniPikiAnimMgr::startMotion(immut PaniMotionInfo& motion1, immut PaniMotionInfo& motion2)
{
	startMotion(&motion1, &motion2);
}

/*
 * --INFO--
 * Address:	8011FAC0
 * Size:	000084
 */
void PaniPikiAnimMgr::finishMotion(PaniAnimKeyListener* listener)
{
	finishMotion(&PaniMotionInfo(PANI_NO_MOTION, listener), &PaniMotionInfo(PANI_NO_MOTION, nullptr));
}

/*
 * --INFO--
 * Address:	8011FB44
 * Size:	0000C0
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

/*
 * --INFO--
 * Address:	8011FC04
 * Size:	000050
 */
void PaniPikiAnimMgr::updateContext()
{
	mUpperAnimator.updateContext();
	mLowerAnimator.updateContext();
}
