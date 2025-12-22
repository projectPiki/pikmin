#include "DebugLog.h"
#include "FlowController.h"
#include "GameCreditsSection.h"
#include "system.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("GameCreditsSection");

/**
 * @TODO: Documentation
 */
GameCreditsSection::GameCreditsSection()
{
	Node::init("<GameCreditsSection>");
	gsys->setFrameClamp(1);
	flowCont._24C = 0;
	flowCont._250 = 0;
}
