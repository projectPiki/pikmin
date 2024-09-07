#ifndef _MATH_PPC_H
#define _MATH_PPC_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

f64 nan(const char*);
f32 cosf(f32 __x);
f32 sinf(f32 __x);
f32 tanf(f32 __x);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
