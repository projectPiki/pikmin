#include "DebugLog.h"
#include "GameStageClearSection.h"
#include "system.h"

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
DEFINE_PRINT("GameStageClearSection");

/**
 * @TODO: Documentation
 */
GameStageClearSection::GameStageClearSection()
{
	Node::init("<GameStageClearSection>");
	gsys->setFrameClamp(1);
}
