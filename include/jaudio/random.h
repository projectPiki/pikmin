#ifndef _JAUDIO_RANDOM_H
#define _JAUDIO_RANDOM_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

//////////// JAUDIO RANDOM (C) DEFINITIONS ////////////
// Global functions.
s32 GetRandom_s32();
u32 GetRandom_u32();
u32 GetRandom_ulimit(u32 limit);
f32 GetRandom_sf32();

///////////////////////////////////////////////////////

END_SCOPE_EXTERN_C

#endif
