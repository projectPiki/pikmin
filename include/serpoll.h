#ifndef _SERPOLL_H_
#define _SERPOLL_H_
#include "types.h"

typedef struct TRKFramingState TRKFramingState, *PTRKFramingState;

struct TRKFramingState {
    s32 field0_0x0;
    s32 field1_0x4;
    u8 field2_0x8;
    u32 field3_0xc;
};

extern TRKFramingState gTRKFramingState;

#endif
