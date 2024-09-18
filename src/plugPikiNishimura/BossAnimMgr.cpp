#include "Boss.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */

static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "BossAnimMgr");
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
 * Address:	8014FA68
 * Size:	000094
 */
BossAnimationManager::BossAnimationManager(BossMgr* mgr)
    : Node("BossAnimationManager")
{
	mBossMgr = mgr;
}
