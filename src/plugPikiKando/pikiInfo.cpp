#include "PikiInfo.h"

PikiInfo* pikiInfo = nullptr;

/*
 * --INFO--
 * Address:	80119CE4
 * Size:	000024
 */

PikiInfo::PikiInfo()
{
	_04               = 0;
	mFormationPikiCnt = 0;
	_08               = 0;
	_18               = 0;
	_14               = 0;
	_10               = 0;
	_0C               = 0;
}

/*
 * --INFO--
 * Address:	80119D08
 * Size:	000024
 */
void PikiInfo::addFormationPiki(void)
{
	mFormationPikiCnt++;
	if (_04 >= mFormationPikiCnt) {
		return;
	}
	_04 = mFormationPikiCnt;
	return;
}

/*
 * --INFO--
 * Address:	80119D2C
 * Size:	000010
 */

void PikiInfo::subFormationPiki(void)
{
	BUMP_REGISTER(r4);
	mFormationPikiCnt--;
}
