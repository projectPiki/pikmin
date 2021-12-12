#include "types.h"

/*
 * --INFO--
 * Address:	80119CE4
 * Size:	000024
 */
class PikiInfo {
    s32 pikiCountA; // _00
    s32 pikiCountB; // _04
    u32 _08;
    u32 _0C;
    u32 _10;
    u32 _14;
    u32 _18;

    PikiInfo();
    void addFormationPiki();
    void subFormationPiki();
    
    static PikiInfo* pikiInfo;
};

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

// nonmatching due to r5 usage
void PikiInfo::subFormationPiki(void) { pikiCountA--; }

/*
.loc_0x0:
  lwz       r5, 0x0(r3)
  subi      r0, r5, 0x1
  stw       r0, 0x0(r3)
  blr
*/
