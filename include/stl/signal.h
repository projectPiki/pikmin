#ifndef _SIGNAL_H
#define _SIGNAL_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

extern void exit(int);

typedef void (*sig_func)(int sig);

int raise(int sig);

END_SCOPE_EXTERN_C

#endif
