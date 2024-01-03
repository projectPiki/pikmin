#ifndef _DOLPHIN_MATH_H
#define _DOLPHIN_MATH_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

#ifndef __MWERKS__
// Get clangd to shut up about __fabs being undefined.
#define __fabs(x)    (x)
#define __frsqrte(x) (x)
#endif

#define FABS(x) (f32) __fabs(x)
// #define __frsqrtes opword

#define SQUARE(v) ((v) * (v))

#define TAU     6.2831855f
#define PI      3.1415927f
#define HALF_PI 1.5707964f

#define LONG_TAU 6.2831854820251465

f64 cos(f64);
f32 cosf(f32);
f64 sin(f64);
f64 tan(f64);
f32 tanf(f32);
f64 atan(f64);
f64 atan2(f64, f64);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
