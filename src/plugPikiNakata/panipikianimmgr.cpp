#include "PaniPikiAnimator.h"
#include "DebugLog.h"

PaniMotionTable* PaniPikiAnimMgr::motionTable;

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
void PaniPikiAnimMgr::startMotion(PaniMotionInfo* motion1, PaniMotionInfo* motion2)
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
void PaniPikiAnimMgr::finishMotion(PaniMotionInfo* motion1, PaniMotionInfo* motion2)
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
void PaniPikiAnimMgr::startMotion(PaniMotionInfo& motion1, PaniMotionInfo& motion2)
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
	finishMotion(&PaniMotionInfo(-1, listener), &PaniMotionInfo(-1, nullptr));
}

/*
 * --INFO--
 * Address:	8011FB44
 * Size:	0000C0
 */
void PaniPikiAnimMgr::updateAnimation(f32 speed)
{
	u32 badCompiler; // i tried really hard to get the inlines to work, i promise

	if (isFinished()) {
		if (mAnimSpeed < mUpperAnimator.mAnimInfo->mParams.mSpeed()) {
			setAnimSpeed(mUpperAnimator.mAnimInfo->mParams.mSpeed());
		}
	} else {
		setAnimSpeed(speed);
	}

	f32 currSpeed = mAnimSpeed;
	if (!(mUpperAnimator.mAnimInfo->mParams.mFlags() & ANIMFLAG_UseDynamicSpeed)) {
		setAnimSpeed(mUpperAnimator.mAnimInfo->mParams.mSpeed());
	}

	mUpperAnimator.animate(mAnimSpeed);

	if (!(mLowerAnimator.mAnimInfo->mParams.mFlags() & ANIMFLAG_UseDynamicSpeed)) {
		setAnimSpeed(mLowerAnimator.mAnimInfo->mParams.mSpeed());
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
