#include "Boss.h"
#include "Shape.h"
#include "sysNew.h"

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
 * Address:	80152684
 * Size:	000110
 */
BossShapeObject::BossShapeObject(Shape* shape, char* bossName)
{
	mShape               = shape;
	mShape->mFrameCacher = nullptr;

	if (bossName) {
		char binFileName[128];
		sprintf(binFileName, "bosses/%s/anims.bin", bossName);
		mAnimMgr        = new AnimMgr(shape, binFileName, 0x8000, nullptr);
		mAnimMgr->mName = bossName;
	} else {
		mAnimMgr = new AnimMgr(shape, nullptr, 0, nullptr);
	}

	mShape->overrideAnim(0, &mAnimContext);
}
