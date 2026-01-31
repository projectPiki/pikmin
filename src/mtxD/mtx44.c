#include "types.h"

// This file is exclusively present in PAL Demo
// important we keep it entirely seperate from the many existing "abs" functions since we've been using a macro with the same name

WEAKFUNC f64 fabsf__Ff(f32 a)
{
	return __fabs(a);
}
