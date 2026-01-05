#include "App.h"

#include "DebugLog.h"
#include "system.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @brief Initiates rendering for the current frame, using the system's graphics context.
 *
 * This function is specific for the DOL version (not the DLL) given it uses the Dolphin graphics context.
 */
void GameApp::renderall()
{
	draw(*gsys->mDGXGfx);
}
