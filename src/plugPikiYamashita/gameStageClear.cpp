#include "GameStageClearSection.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("GameStageClearSection");

/*
 * --INFO--
 * Address:	8019B804
 * Size:	000080
 */
GameStageClearSection::GameStageClearSection()
{
	Node::init("<GameStageClearSection>");
	gsys->setFrameClamp(1);
}
