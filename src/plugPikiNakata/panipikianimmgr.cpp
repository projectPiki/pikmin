#include "PaniPikiAnimator.h"

PaniMotionTable* PaniPikiAnimMgr::motionTable;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

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
	mLowerAnimator.init(context1, mgr, sTable);
	mUpperAnimator.init(context2, mgr, sTable);

	mAnimSpeed = 30.0f;
}

/*
 * --INFO--
 * Address:	8011F958
 * Size:	000060
 */
void PaniPikiAnimMgr::changeContext(AnimContext* context1, AnimContext* context2)
{
	mLowerAnimator.changeContext(context1);
	mUpperAnimator.changeContext(context2);
}

/*
 * --INFO--
 * Address:	8011F9B8
 * Size:	000058
 */
void PaniPikiAnimMgr::startMotion(PaniMotionInfo* motion1, PaniMotionInfo* motion2)
{
	if (motion1) {
		mLowerAnimator.startMotion(*motion1);
	}
	if (motion2) {
		mUpperAnimator.startMotion(*motion2);
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
		mLowerAnimator.finishMotion(*motion1);
	}
	if (motion2) {
		mUpperAnimator.finishMotion(*motion2);
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
		if (mAnimSpeed < mLowerAnimator.mAnimInfo->mParams.mSpeed()) {
			setAnimSpeed(mLowerAnimator.mAnimInfo->mParams.mSpeed());
		}
	} else {
		setAnimSpeed(speed);
	}

	f32 currSpeed = mAnimSpeed;
	if (!(mLowerAnimator.mAnimInfo->mParams.mFlags() & AnimInfo::FLAG_Unk2)) {
		setAnimSpeed(mLowerAnimator.mAnimInfo->mParams.mSpeed());
	}

	mLowerAnimator.animate(mAnimSpeed);

	if (!(mUpperAnimator.mAnimInfo->mParams.mFlags() & AnimInfo::FLAG_Unk2)) {
		setAnimSpeed(mUpperAnimator.mAnimInfo->mParams.mSpeed());
	}

	mUpperAnimator.animate(currSpeed);
}

/*
 * --INFO--
 * Address:	8011FC04
 * Size:	000050
 */
void PaniPikiAnimMgr::updateContext()
{
	mLowerAnimator.updateContext();
	mUpperAnimator.updateContext();
}
