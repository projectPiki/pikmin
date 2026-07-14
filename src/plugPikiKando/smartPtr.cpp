#include "RefCountable.h"

#include "DebugLog.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("smartPtr") // Never used in the DLL

/**
 * @todo: Documentation
 */
RefCountable::RefCountable()
{
	mCount = 0;
}

/**
 * @todo: Documentation
 */
void RefCountable::clearCnt()
{
	mCount = 0;
}

/**
 * @todo: Documentation
 */
void RefCountable::addCnt()
{
	mCount++;
#if defined(WIN32)
	addCntCallback();
#endif
}

/**
 * @todo: Documentation
 */
void RefCountable::subCnt()
{
	mCount--;
#if defined(WIN32)
	subCntCallback();
#endif
	if (mCount < 0) {
		mCount = 0;
	}
}
