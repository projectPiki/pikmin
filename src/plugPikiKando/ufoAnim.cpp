#include "DebugLog.h"
#include "PlayerState.h"
#include "Shape.h"
#include "UfoItem.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

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

char* PaniUfoAnimator::motionLabels[UfoMotion::COUNT] = {
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
	PaniMotionTable* table = new PaniMotionTable(UfoMotion::COUNT);

	table->setMotion(UfoMotion::WaitTutorial, new PaniMotion(UfoMotion::WaitTutorial));
	table->setMotion(UfoMotion::Wait, new PaniMotion(UfoMotion::Wait));
	table->setMotion(UfoMotion::Takeoff, new PaniMotion(UfoMotion::Takeoff));
	table->setMotion(UfoMotion::Henka1, new PaniMotion(UfoMotion::Henka1));
	table->setMotion(UfoMotion::Henka1b, new PaniMotion(UfoMotion::Henka1b));
	table->setMotion(UfoMotion::Henka1d, new PaniMotion(UfoMotion::Henka1d));
	table->setMotion(UfoMotion::Henka2, new PaniMotion(UfoMotion::Henka2));
	table->setMotion(UfoMotion::Henka2d, new PaniMotion(UfoMotion::Henka2d));
	table->setMotion(UfoMotion::Henka3, new PaniMotion(UfoMotion::Henka3));
	table->setMotion(UfoMotion::Henka4a, new PaniMotion(UfoMotion::Henka4a));
	table->setMotion(UfoMotion::Henka4b, new PaniMotion(UfoMotion::Henka4b));
	table->setMotion(UfoMotion::Takeoff1, new PaniMotion(UfoMotion::Takeoff1));
	table->setMotion(UfoMotion::Takeoff2, new PaniMotion(UfoMotion::Takeoff2));
	table->setMotion(UfoMotion::Takeoff3, new PaniMotion(UfoMotion::Takeoff3));
	table->setMotion(UfoMotion::Takeoff4, new PaniMotion(UfoMotion::Takeoff4));
	table->setMotion(UfoMotion::Takeoff5, new PaniMotion(UfoMotion::Takeoff5));
	table->setMotion(UfoMotion::OpenClose, new PaniMotion(UfoMotion::OpenClose));
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
		mAnims[i].startMotion(PaniMotionInfo(UfoMotion::WaitTutorial));
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
		startMotion(7, &PaniMotionInfo(UfoMotion::Henka4b));
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
			startMotion(i, &PaniMotionInfo(i + UfoMotion::Henka1 - 1));
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
