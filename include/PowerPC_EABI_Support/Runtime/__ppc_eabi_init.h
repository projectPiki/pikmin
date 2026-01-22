#ifndef __PPC_EABI_INIT
#define __PPC_EABI_INIT

#include "types.h"

BEGIN_SCOPE_EXTERN_C

extern void __init_user(void);
extern void __init_hardware(void);
extern void __flush_cache(void*, int);

END_SCOPE_EXTERN_C

#endif
