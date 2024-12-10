#ifndef _JAUDIO_RANDOM_H
#define _JAUDIO_RANDOM_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO RANDOM (C) DEFINITIONS ////////////
// Global functions.
s32 GetRandom_s32();
u32 GetRandom_u32();
u32 GetRandom_ulimit(u32 limit);
f32 GetRandom_sf32();

///////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
