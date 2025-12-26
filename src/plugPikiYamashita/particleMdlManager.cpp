#include "DebugLog.h"
#include "zen/bBoardColourAnim.h"
#include "zen/particle.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("particleMdlManager");

/**
 * @todo: Documentation
 */
void zen::particleMdlManager::init(u32 particleNum, u32 childNum)
{
	int i;

	mPtclList = new particleMdl[particleNum];
	for (i = 0; i < particleNum; i++) {
		mSleepPtclList.put(&mPtclList[i]);
	}

	mChildPtclList = new particleChildMdl[childNum];
	for (i = 0; i < childNum; i++) {
		mSleepPtclChildList.put(&mChildPtclList[i]);
	}
}
