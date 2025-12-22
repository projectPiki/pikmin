#include "AIConstant.h"
#include "DebugLog.h"
#include "sysNew.h"

AIConstant* AIConstant::_instance;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr)

/**
 * @TODO: Documentation
 */
void AIConstant::createInstance()
{
	if (_instance == nullptr) {
		_instance = new AIConstant();
	}
}

/**
 * @TODO: Documentation
 */
AIConstant::AIConstant()
{
	load("parms/", "aiconst.bin", 1);
}
