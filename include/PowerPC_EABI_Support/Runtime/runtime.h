#ifndef _DOLPHIN_RUNTIME_H
#define _DOLPHIN_RUNTIME_H

#include "types.h"
#include <stddef.h>

BEGIN_SCOPE_EXTERN_C

u32 __cvt_fp2unsigned(f64);
// TODO: The rest

void* __copy(char*, char*, size_t);

END_SCOPE_EXTERN_C

#endif
