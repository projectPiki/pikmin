#include "AIConstant.h"
#include "sysNew.h"

AIConstant* AIConstant::_instance;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...) { OSPanic(__FILE__, __LINE__, fmt); }

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

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
AIConstant::AIConstant() { load("parms/", "aiconst.bin", 1); }
