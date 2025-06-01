#include "PelletAnimator.h"
#include "Pellet.h"
#include "sysNew.h"
#include "DebugLog.h"
#include "gameflow.h"

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
DEFINE_PRINT("animPellet");

/*
 * --INFO--
 * Address:	80099548
 * Size:	000180
 */
PelletAnimInfo::PelletAnimInfo()
    : mFolderPath(this, String("pellets", 0), String("", 0), String("", 0), "x00", nullptr)
    , mFileName(this, String("noname", 0), String("", 0), String("", 0), "x01", nullptr)
{
	mID.setID('none');
	mCreationType = 0;
	mTekiType     = -1;
	mStartAnimId  = -1;

	initCore("pelletAnimInfo");
	mPelletShapeObject = nullptr;
}

/*
 * --INFO--
 * Address:	800996C8
 * Size:	0000D4
 */
PelletShapeObject* PelletAnimInfo::createShapeObject()
{
	char path[PATH_MAX];
	char path2[PATH_MAX];

	sprintf(path, "objects/%s/%s.mod", mFolderPath().mString, mFileName().mString);
	Shape* shape = gameflow.loadShape(path, true);

	if (shape) {
		sprintf(path2, "%s.bin", mFileName().mString);
		mPelletShapeObject = new PelletShapeObject(mID.mStringID, shape, mFolderPath().mString, path2, mStartAnimId);
	} else {
		mPelletShapeObject = nullptr;
	}

	return mPelletShapeObject;
}

/*
 * --INFO--
 * Address:	8009979C
 * Size:	000090
 */
void PelletAnimInfo::read(RandomAccessStream& stream)
{
	mID.read(stream);
	mCreationType = stream.readInt();
	mTekiType     = stream.readInt();
	mStartAnimId  = stream.readInt();
	Parameters::read(stream);
}

/*
 * --INFO--
 * Address:	8009982C
 * Size:	000140
 */
PelletShapeObject::PelletShapeObject(char* str1, Shape* shape, char* str2, char* str3, int animationFlag)
{
	mShape               = shape;
	mShape->mFrameCacher = nullptr;

	if (str2) {
		char path[128];
		sprintf(path, "objects/%s/%s", str2, str3);
		mAnimMgr        = new AnimMgr(shape, path, 0x8000, nullptr);
		mAnimMgr->mName = str1;
	} else {
		mAnimMgr = new AnimMgr(shape, nullptr, 0, nullptr);
	}

	mShape->overrideAnim(0, &mAnimatorA);
	mMotionFlag = 1;

	if (animationFlag != -1) {
		mShape->overrideAnim(animationFlag, &mAnimatorB);
		setMotionFlag(2);
	}
}

char* PaniPelletAnimator::motionLabels[] = { "Carry", "Appear", "3", "4", "5", "6", "7" };

/*
 * --INFO--
 * Address:	8009996C
 * Size:	000038
 */
PelletAnimator::PelletAnimator()
{
}

/*
 * --INFO--
 * Address:	800999A4
 * Size:	00006C
 */
void PelletAnimator::init(AnimContext* context1, AnimContext* context2, AnimMgr* mgr, PaniMotionTable* motionTable)
{
	mLowerAnimator.init(context1, mgr, motionTable);
	mUpperAnimator.init(context2, mgr, motionTable);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void PelletAnimator::startMotion(PaniMotionInfo* motionInfo1, PaniMotionInfo* motionInfo2)
{
	if (motionInfo1) {
		mLowerAnimator.startMotion(*motionInfo1);
	}
	if (motionInfo2) {
		mUpperAnimator.startMotion(*motionInfo2);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80099A10
 * Size:	000058
 */
void PelletAnimator::finishMotion(PaniMotionInfo* motionInfo1, PaniMotionInfo* motionInfo2)
{
	if (motionInfo1) {
		mLowerAnimator.finishMotion(*motionInfo1);
	}
	if (motionInfo2) {
		mUpperAnimator.finishMotion(*motionInfo2);
	}
}

/*
 * --INFO--
 * Address:	80099A68
 * Size:	000058
 */
void PelletAnimator::startMotion(PaniMotionInfo& motionInfo1, PaniMotionInfo& motionInfo2)
{
	startMotion(&motionInfo1, &motionInfo2);
}

/*
 * --INFO--
 * Address:	80099AC0
 * Size:	000028
 */
void PelletAnimator::startMotion(PaniMotionInfo& motionInfo)
{
	startMotion(&motionInfo, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void PelletAnimator::finishMotion(PaniAnimKeyListener*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80099AE8
 * Size:	00005C
 */
void PelletAnimator::updateAnimation(f32 lowerAnimSpeed, f32 upperAnimSpeed)
{
	mLowerAnimator.animate(lowerAnimSpeed);
	mUpperAnimator.animate(upperAnimSpeed);
}

/*
 * --INFO--
 * Address:	80099B44
 * Size:	00004C
 */
void PelletAnimator::updateContext()
{
	mLowerAnimator.updateContext();
	mUpperAnimator.updateContext();
}

/*
 * --INFO--
 * Address:	80099B90
 * Size:	000148
 */
PaniMotionTable* PaniPelletAnimator::createMotionTable()
{
	PaniMotionTable* table = new PaniMotionTable(7);
	table->mMotions[0]     = new PaniMotion(0);
	table->mMotions[1]     = new PaniMotion(1);
	table->mMotions[2]     = new PaniMotion(2);
	table->mMotions[3]     = new PaniMotion(3);
	table->mMotions[4]     = new PaniMotion(4);
	table->mMotions[5]     = new PaniMotion(5);
	table->mMotions[6]     = new PaniMotion(6);
	return table;
}

/*
 * --INFO--
 * Address:	80099CD8
 * Size:	00003C
 */
PaniPelletAnimator::PaniPelletAnimator()
{
}
