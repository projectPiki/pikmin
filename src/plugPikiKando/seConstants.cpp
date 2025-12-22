#include "DebugLog.h"
#include "Dolphin/os.h"
#include "SoundMgr.h"

/**
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("seConstant")

SeConstant::SeConstant()
{
	load("parms/", "sound.bin", 1);
}
