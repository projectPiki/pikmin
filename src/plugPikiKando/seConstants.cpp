#include "DebugLog.h"
#include "Dolphin/os.h"
#include "SoundMgr.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("seConstant")

/**
 * @todo: Documentation
 */
SeConstant::SeConstant()
{
	load("parms/", "sound.bin", 1);
}
