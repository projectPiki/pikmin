#ifndef _MSL_COMMON_ARITH_H
#define _MSL_COMMON_ARITH_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

typedef struct {
	int quot; /* quotient */
	int rem;  /* remainder */
} div_t;

s32 abs(s32 __x);
s32 labs(s32 __x);
div_t div(s32 __numer, s32 __denom);

inline int _abs(int __x)
{
	return __x > 0 ? __x : -__x;
}

END_SCOPE_EXTERN_C

#endif
