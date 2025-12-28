#include "DebugLog.h"
#include "FlowController.h"
#include "GameCreditsSection.h"
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
DEFINE_PRINT("GameCreditsSection");

/**
 * @todo: Documentation
 */
GameCreditsSection::GameCreditsSection()
{
	Node::init("<GameCreditsSection>");
	gsys->setFrameClamp(1);
	flowCont.mNaviSeedCount = 0;
	flowCont._250           = 0;
}
