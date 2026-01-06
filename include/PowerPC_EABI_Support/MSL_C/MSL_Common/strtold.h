#ifndef _MSL_STRTOLD_H
#define _MSL_STRTOLD_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

f128 __strtold(int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg, int* chars_scanned, int* overflow);
s32 strtol(const char* str, char** end, int base);
f64 atof(const char* str);

END_SCOPE_EXTERN_C

#endif
