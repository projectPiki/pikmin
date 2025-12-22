#include "PikiInfo.h"

PikiInfo* pikiInfo = nullptr;

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

void PikiInfo::addFormationPiki()
{
	mFormationPikiCnt++;
	if (_04 >= mFormationPikiCnt) {
		return;
	}
	_04 = mFormationPikiCnt;
	return;
}

void PikiInfo::subFormationPiki()
{
	BUMP_REGISTER(r4);
	mFormationPikiCnt--;
}
