#include "AIConstant.h"
#include "DebugLog.h"
#include "sysNew.h"

AIConstant* AIConstant::_instance;

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @todo: Documentation
 */
void AIConstant::createInstance()
{
	if (_instance == nullptr) {
		_instance = new AIConstant();
	}
}

/**
 * @todo: Documentation
 */
AIConstant::AIConstant()
{
	load("parms/", "aiconst.bin", 1);
}
