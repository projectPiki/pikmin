#include "SoundMgr.h"
#include "Dolphin/os.h"
#include "DebugLog.h"

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

/**
 * --INFO--
 * Address:	800A3B04
 * Size:	000134
 */
SeConstant::SeConstant()
{
	load("parms/", "sound.bin", 1);
}
