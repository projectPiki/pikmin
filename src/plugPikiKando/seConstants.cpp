#include "SoundMgr.h"
#include "Dolphin/os.h"
#include "DebugLog.h"

/**
 * @brief Error function for seConstants.cpp, stripped in retail.
 *
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/**
 * @brief Print function for seConstants.cpp, stripped in retail.
 *
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
