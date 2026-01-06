#ifndef _MSL_RAND_H
#define _MSL_RAND_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

#define RAND_MAX (0x7fff)

int rand();
void srand(u32 seed);

END_SCOPE_EXTERN_C

#endif
