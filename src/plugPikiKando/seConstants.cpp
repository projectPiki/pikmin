#include "DebugLog.h"
#include "Dolphin/os.h"
#include "SoundMgr.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("seConstant")

/**
 * @TODO: Documentation
 */
SeConstant::SeConstant()
{
	load("parms/", "sound.bin", 1);
}
