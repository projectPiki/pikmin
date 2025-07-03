#include "zen/particle.h"
#include "zen/bBoardColourAnim.h"
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
DEFINE_PRINT("particleMdlManager");

/*
 * --INFO--
 * Address:	801A17D4
 * Size:	000130
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
