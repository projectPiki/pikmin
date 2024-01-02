#include "RefCountable.h"

char file[] = __FILE__;
char name[] = "smartPtr";

/*
 * --INFO--
 * Address:	800E4338
 * Size:	000018
 */
RefCountable::RefCountable() { mCnt = 0; }

/*
 * --INFO--
 * Address:	800E4350
 * Size:	00000C
 */
void RefCountable::clearCnt() { mCnt = 0; }

/*
 * --INFO--
 * Address:	800E435C
 * Size:	000010
 */
void RefCountable::addCnt() { mCnt++; }

/*
 * --INFO--
 * Address:	800E436C
 * Size:	000024
 */
void RefCountable::subCnt()
{
	mCnt--;
	if (mCnt >= 0) {
		return;
	}
	mCnt = 0;
	return;
}
