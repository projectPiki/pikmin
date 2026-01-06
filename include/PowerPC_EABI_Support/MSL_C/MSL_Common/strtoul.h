#ifndef _MSL_STRTOUL_H
#define _MSL_STRTOUL_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

u32 __strtoul(int base, int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg, int* chars_scanned, int* negative,
              int* overflow);
u64 __strtoull(int base, int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg, int* chars_scanned, int* negative,
               int* overflow);
int atoi(const char* str);
u32 strtoul(const char* str, char** end, int base);

END_SCOPE_EXTERN_C

#endif
