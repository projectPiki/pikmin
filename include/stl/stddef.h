#ifndef STL_STDDEF_H
#define STL_STDDEF_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

typedef unsigned long size_t;

#if defined(__cplusplus)
#define NULL (0)
#else
#define NULL ((void*)0)
#endif

#define offsetof(type, memb) ((size_t)&((type*)0)->memb)

END_SCOPE_EXTERN_C

#endif
