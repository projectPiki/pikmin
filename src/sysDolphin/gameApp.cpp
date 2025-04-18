#include "App.h"
#include "system.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	8004C908
 * Size:	000034
 */
void GameApp::renderall()
{
	draw((Graphics&)*gsys->mGfx);
}
