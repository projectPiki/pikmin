#include "RefCountable.h"

char file[] = __FILE__;
char name[] = "smartPtr";

/**
 * @TODO: Documentation
 */
RefCountable::RefCountable()
{
	mCount = 0;
}

/**
 * @TODO: Documentation
 */
void RefCountable::clearCnt()
{
	mCount = 0;
}

/**
 * @TODO: Documentation
 */
void RefCountable::addCnt()
{
	mCount++;
}

/**
 * @TODO: Documentation
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
