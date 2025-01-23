#include "RefCountable.h"

char file[] = __FILE__;
char name[] = "smartPtr";

/*
 * --INFO--
 * Address:	800E4338
 * Size:	000018
 */
RefCountable::RefCountable()
{
	mCount = 0;
}

/*
 * --INFO--
 * Address:	800E4350
 * Size:	00000C
 */
void RefCountable::clearCnt()
{
	mCount = 0;
}

/*
 * --INFO--
 * Address:	800E435C
 * Size:	000010
 */
void RefCountable::addCnt()
{
	mCount++;
}

/*
 * --INFO--
 * Address:	800E436C
 * Size:	000024
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
