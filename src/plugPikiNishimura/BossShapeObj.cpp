#include "Boss.h"
#include "Shape.h"
#include "sysNew.h"
#include "DebugLog.h"

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
DEFINE_PRINT("BossShapeObj");

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
		PRINT("########## AnimMgr Construct Start -> %s\n", bossName);
		char binFileName[128];
		sprintf(binFileName, "bosses/%s/anims.bin", bossName);
		mAnimMgr        = new AnimMgr(shape, binFileName, ANIMMGR_LOAD_BUNDLE, nullptr);
		mAnimMgr->mName = bossName;
		PRINT("########## AnimMgr Construct END\n");
	} else {
		mAnimMgr = new AnimMgr(shape, nullptr, ANIMMGR_LOAD_NOSKIP, nullptr);
	}

	mShape->overrideAnim(0, &mAnimContext);
}
