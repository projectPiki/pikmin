#ifndef _PIKIINFO_H
#define _PIKIINFO_H

#include "types.h"

struct PikiInfo {
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
};

#endif
