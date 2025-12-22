#include "Boss.h"
#include "DebugLog.h"
#include "Dolphin/os.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */

DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */

DEFINE_PRINT("BossAnimMgr") //! TODO: Why is the size not proper?

/**
 * @TODO: Documentation
 */
BossAnimationManager::BossAnimationManager(BossMgr* mgr)
    : Node("BossAnimationManager")
{
	mBossMgr = mgr;
}
