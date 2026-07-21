#ifndef _JAUDIO_BANKREAD_H
#define _JAUDIO_BANKREAD_H

#include "types.h"

typedef struct Bank_ Bank_;

Bank_* Bank_Test(u8* ibnk);
BOOL Bank_Regist(void* ibnk, u32 bankIndex);
BOOL Bank_Regist_Direct(void* ibnk, u32 bankIndex, u32 connectTableId);
void Bank_Init();
Bank_* Bank_Get(u32 index);

#endif
