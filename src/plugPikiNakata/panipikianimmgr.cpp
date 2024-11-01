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
PaniMotionTable* PaniPikiAnimMgr::getMotionTable() { return motionTable; }

/*
 * --INFO--
 * Address:	8011F8A0
 * Size:	00003C
 */
PaniPikiAnimMgr::PaniPikiAnimMgr() { }

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
	_04.init(context1, mgr, sTable);
	_58.init(context2, mgr, sTable);

	mAnimSpeed = 30.0f;
}

/*
 * --INFO--
 * Address:	8011F958
 * Size:	000060
 */
void PaniPikiAnimMgr::changeContext(AnimContext* context1, AnimContext* context2)
{
	_04.changeContext(context1);
	_58.changeContext(context2);
}

/*
 * --INFO--
 * Address:	8011F9B8
 * Size:	000058
 */
void PaniPikiAnimMgr::startMotion(PaniMotionInfo* motion1, PaniMotionInfo* motion2)
{
	if (motion1) {
		_04.startMotion(*motion1);
	}
	if (motion2) {
		_58.startMotion(*motion2);
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
		_04.finishMotion(*motion1);
	}
	if (motion2) {
		_58.finishMotion(*motion2);
	}
}

/*
 * --INFO--
 * Address:	8011FA68
 * Size:	000058
 */
void PaniPikiAnimMgr::startMotion(PaniMotionInfo& motion1, PaniMotionInfo& motion2) { startMotion(&motion1, &motion2); }

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
		if (mAnimSpeed < _04.mAnimInfo->mParams.mSpeed()) {
			setAnimSpeed(_04.mAnimInfo->mParams.mSpeed());
		}
	} else {
		setAnimSpeed(speed);
	}

	f32 currSpeed = mAnimSpeed;
	if (!(_04.mAnimInfo->mParams.mFlags() & AnimInfo::FLAG_Unk2)) {
		setAnimSpeed(_04.mAnimInfo->mParams.mSpeed());
	}

	_04.animate(mAnimSpeed);

	if (!(_58.mAnimInfo->mParams.mFlags() & AnimInfo::FLAG_Unk2)) {
		setAnimSpeed(_58.mAnimInfo->mParams.mSpeed());
	}

	_58.animate(currSpeed);
}

/*
 * --INFO--
 * Address:	8011FC04
 * Size:	000050
 */
void PaniPikiAnimMgr::updateContext()
{
	_04.updateContext();
	_58.updateContext();
}
