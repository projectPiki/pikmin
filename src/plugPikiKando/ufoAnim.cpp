#include "UfoItem.h"
#include "sysNew.h"
#include "Shape.h"
#include "PlayerState.h"
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
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	800E97AC
 * Size:	000158
 */
UfoShapeObject::UfoShapeObject(Shape* shape)
{
	mAnimContexts   = new AnimContext[8];
	mShape          = shape;
	char* path      = "objects/ufo/ufo0705.bin";
	mAnimMgr        = new AnimMgr(shape, path, ANIMMGR_LOAD_BUNDLE, nullptr);
	mAnimMgr->mName = "ufo shape";

	mShape->overrideAnim(0, &mAnimContexts[0]);
	mShape->overrideAnim(38, &mAnimContexts[1]);
	mShape->overrideAnim(36, &mAnimContexts[2]);
	mShape->overrideAnim(19, &mAnimContexts[3]);
	mShape->overrideAnim(32, &mAnimContexts[4]);
	mShape->overrideAnim(37, &mAnimContexts[5]);
	mShape->overrideAnim(29, &mAnimContexts[6]);
	mShape->overrideAnim(53, &mAnimContexts[7]);
}

char* PaniUfoAnimator::motionLabels[17] = {
	"wait tut", "wait",    "takeoff",   "henka1",    "henka1b",   "henka1d",   "henka2",    "henka2d",    "henka3",
	"henka4a",  "henka4b", "takeoff-1", "takeoff-2", "takeoff-3", "takeoff-4", "takeoff-5", "open-close",
};

/*
 * --INFO--
 * Address:	800E992C
 * Size:	0002B0
 */
PaniMotionTable* PaniUfoAnimator::createMotionTable()
{
	PaniMotionTable* table = new PaniMotionTable(17);

	table->setMotion(0, new PaniMotion(0));
	table->setMotion(1, new PaniMotion(1));
	table->setMotion(2, new PaniMotion(2));
	table->setMotion(3, new PaniMotion(3));
	table->setMotion(4, new PaniMotion(4));
	table->setMotion(5, new PaniMotion(5));
	table->setMotion(6, new PaniMotion(6));
	table->setMotion(7, new PaniMotion(7));
	table->setMotion(8, new PaniMotion(8));
	table->setMotion(9, new PaniMotion(9));
	table->setMotion(10, new PaniMotion(10));
	table->setMotion(11, new PaniMotion(11));
	table->setMotion(12, new PaniMotion(12));
	table->setMotion(13, new PaniMotion(13));
	table->setMotion(14, new PaniMotion(14));
	table->setMotion(15, new PaniMotion(15));
	table->setMotion(16, new PaniMotion(16));
	return table;
}

/*
 * --INFO--
 * Address:	800E9BDC
 * Size:	00003C
 */
PaniUfoAnimator::PaniUfoAnimator()
{
}

/*
 * --INFO--
 * Address:	800E9C18
 * Size:	00005C
 */
UfoAnimator::UfoAnimator()
{
	mAnims      = new PaniUfoAnimator[8];
	mAnimSpeeds = new f32[8];
}

/*
 * --INFO--
 * Address:	800E9C74
 * Size:	0000A4
 */
void UfoAnimator::init(UfoShapeObject* shape, PaniMotionTable* table)
{
	for (int i = 0; i < 8; i++) {
		mAnims[i].init(shape->mAnimContexts + i, shape->mAnimMgr, table);
		mAnimSpeeds[i] = 0.0f;
		mAnims[i].startMotion(PaniMotionInfo(0));
	}
}

/*
 * --INFO--
 * Address:	800E9D18
 * Size:	000038
 */
void UfoAnimator::startMotion(int id, PaniMotionInfo* info)
{
	if (info) {
		mAnims[id].startMotion(*info);
	}
}

/*
 * --INFO--
 * Address:	800E9D50
 * Size:	000010
 */
void UfoAnimator::setMotionSpeed(int id, f32 speed)
{
	mAnimSpeeds[id] = speed;
}

/*
 * --INFO--
 * Address:	800E9D60
 * Size:	000014
 */
int UfoAnimator::getMotionIndex(int id)
{
	return mAnims[id].getCurrentMotionIndex();
}

/*
 * --INFO--
 * Address:	800E9D74
 * Size:	000048
 */
void UfoAnimator::stopAllMotions()
{
	for (int i = 0; i < 8; i++) {
		setMotionSpeed(i, 0.0f);
	}
}

/*
 * --INFO--
 * Address:	800E9DBC
 * Size:	000120
 */
void UfoAnimator::initFlagMotions(int id)
{
	for (int i = 1; i < 8; i++) {
		startMotion(i, &PaniMotionInfo(i + 2));
		setMotionSpeed(i, 0.0f);
	}
	startFlagMotions(id);

	switch (id) {
	case 4:
	case 5:
		setMotionLastFrame(6);
	case 3:
		setMotionLastFrame(7);
		setMotionLastFrame(3);
	case 2:
		setMotionLastFrame(4);
		setMotionLastFrame(5);
	case 1:
		setMotionLastFrame(1);
		setMotionLastFrame(2);
	default:
		playerState->startAfterMotions();
		if (id == 5) {
			playerState->startSpecialMotions();
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	800E9EDC
 * Size:	000144
 */
void UfoAnimator::startFlagMotions(int id)
{
	switch (id) {
	case 5:
		startMotion(7, &PaniMotionInfo(10));
		playerState->startSpecialMotions();
	case 4:
		setMotionSpeed(6, 30.0f);
	case 3:
		setMotionSpeed(7, 30.0f);
		setMotionSpeed(3, 30.0f);
	case 2:
		setMotionSpeed(4, 30.0f);
		setMotionSpeed(5, 30.0f);
	case 1:
		setMotionSpeed(1, 30.0f);
		setMotionSpeed(2, 30.0f);
		break;
	case 0:
		for (int i = 1; i < 8; i++) {
			startMotion(i, &PaniMotionInfo(i + 2));
			setMotionSpeed(i, 0.0f);
		}
		break;
	}
}

/*
 * --INFO--
 * Address:	800EA020
 * Size:	000088
 */
void UfoAnimator::setMotionLastFrame(int id)
{
	int keys                     = mAnims[id].mAnimInfo->countAKeys();
	mAnims[id].mAnimationCounter = (f32)mAnims[id].mAnimInfo->getKeyValue(keys - 1) - 1.0f;
}

/*
 * --INFO--
 * Address:	800EA0A8
 * Size:	000080
 */
void UfoAnimator::updateAnimation()
{
	for (int i = 0; i < 8; i++) {
		mAnims[i].animate(mAnimSpeeds[i]);
	}
}

/*
 * --INFO--
 * Address:	800EA128
 * Size:	000068
 */
void UfoAnimator::updateContext()
{
	for (int i = 0; i < 8; i++) {
		mAnims[i].updateContext();
	}
}
