#ifndef _DOLPHIN_TRK_H
#define _DOLPHIN_TRK_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

unsigned int TRKTargetContinue(void);
void TRKTargetSetStopped(unsigned int);
void TRKSwapAndGo();

void UnreserveEXI2Port();
void ReserveEXI2Port();

END_SCOPE_EXTERN_C

#endif
