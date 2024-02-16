#ifndef _RAND_H
#define _RAND_H

#include "types.h"

void srand(u32);
int rand(void);

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

#define RAND_MAX (32768.0f)

inline f32 randFloat() { return (f32)rand() / RAND_MAX; }
inline int randInt(int multiplier) { return multiplier * randFloat(); }
inline f32 randWeightFloat(f32 range) { return range * ((f32)rand() / RAND_MAX); }

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
