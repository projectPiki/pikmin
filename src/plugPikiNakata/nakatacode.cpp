#include "CodeInitializer.h"
#include "DebugLog.h"
#include "PaniPikiAnimator.h"
#include "nlib/System.h"
#include "system.h"
#include "teki.h"

BOOL nakataDebugMode;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("nakatacode")

/**
 * @TODO: Documentation
 */
void NakataCodeInitializer::init()
{
	nakataDebugMode = TRUE;
	PRINT_NAKATA("NNNNNNNNNNNNNNNNNNNNNNNakataCodeInitializer::init\n"); // lol
	NSystem::initSystem(gsys);
	PaniPikiAnimMgr::motionTable = nullptr;
	TekiMgr::initTekiMgr();
}
