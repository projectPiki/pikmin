#include "Boss.h"
#include "Dolphin/os.h"
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

DEFINE_PRINT("BossAnimMgr") //! TODO: Why is the size not proper?

/*
 * --INFO--
 * Address:	8014FA68
 * Size:	000094
 */
BossAnimationManager::BossAnimationManager(BossMgr* mgr)
    : Node("BossAnimationManager")
{
	mBossMgr = mgr;
}
