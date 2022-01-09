#include "types.h"
#include "pikiInfo.h"

/*
 * --INFO--
 * Address:	80119CE4
 * Size:	000024
 */

PikiInfo::PikiInfo()
{
    pikiCountB = 0;
    pikiCountA = 0;
    _08 = 0;
    _18 = 0;
    _14 = 0;
    _10 = 0;
    _0C = 0;
}

/*
 * --INFO--
 * Address:	80119D08
 * Size:	000024
 */
void PikiInfo::addFormationPiki(void) {
    pikiCountA += 1;
    if (pikiCountB >= pikiCountA) {
        return;
    }
    pikiCountB = pikiCountA;
    return;
}

/*
 * --INFO--
 * Address:	80119D2C
 * Size:	000010
 */

void PikiInfo::subFormationPiki(void) {
	BUMP_REGISTER(r4);
	pikiCountA--;
}

extern PikiInfo* pikiInfo = nullptr;
