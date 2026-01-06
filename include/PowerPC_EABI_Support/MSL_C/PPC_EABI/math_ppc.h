#ifndef _MATH_PPC_H
#define _MATH_PPC_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

f64 nan(const char*);
f32 cosf(f32 __x);
f32 sinf(f32 __x);
f32 tanf(f32 __x);
f32 atan2f(f32 __x, f32 __y);

END_SCOPE_EXTERN_C

#endif
