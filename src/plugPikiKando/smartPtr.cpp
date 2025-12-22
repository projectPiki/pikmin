#include "RefCountable.h"

char file[] = __FILE__;
char name[] = "smartPtr";

RefCountable::RefCountable()
{
	mCount = 0;
}

void RefCountable::clearCnt()
{
	mCount = 0;
}

void RefCountable::addCnt()
{
	mCount++;
}

void RefCountable::subCnt()
{
	mCount--;
	if (mCount >= 0) {
		return;
	}
	mCount = 0;
	return;
}
