#include "DebugLog.h"
#include "GameStageClearSection.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameStageClearSection");

/**
 * @todo: Documentation
 */
GameStageClearSection::GameStageClearSection()
{
	Node::init("<GameStageClearSection>");
	gsys->setFrameClamp(1);
}
