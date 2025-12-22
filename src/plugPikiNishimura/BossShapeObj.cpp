#include "Boss.h"
#include "DebugLog.h"
#include "Shape.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("BossShapeObj");

/**
 * @TODO: Documentation
 */
BossShapeObject::BossShapeObject(Shape* shape, immut char* bossName)
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
