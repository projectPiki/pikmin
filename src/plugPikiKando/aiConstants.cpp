#include "AIConstant.h"
#include "sysNew.h"
#include "DebugLog.h"

AIConstant* AIConstant::_instance;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	80083E60
 * Size:	00004C
 */
void AIConstant::createInstance()
{
	if (_instance == nullptr) {
		_instance = new AIConstant();
	}
}

/*
 * --INFO--
 * Address:	80083EAC
 * Size:	000470
 */
AIConstant::AIConstant()
{
	load("parms/", "aiconst.bin", 1);
}
