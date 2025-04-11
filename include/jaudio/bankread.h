#ifndef _JAUDIO_BANKREAD_H
#define _JAUDIO_BANKREAD_H

#include "types.h"

void Bank_Test(u8*);
void Bank_Regist(void*, u32);
void Bank_Regist_Direct(void*, u32, u32);
void Bank_Init();
void Bank_Get(u32);

#endif
