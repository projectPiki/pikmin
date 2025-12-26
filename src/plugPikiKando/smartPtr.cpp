#include "RefCountable.h"

char file[] = __FILE__;
char name[] = "smartPtr";

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
}

/**
 * @todo: Documentation
 */
void RefCountable::subCnt()
{
	mCount--;
	if (mCount >= 0) {
		return;
	}
	mCount = 0;
	return;
}
