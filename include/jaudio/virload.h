#ifndef _JAUDIO_VIRLOAD_H
#define _JAUDIO_VIRLOAD_H

#include "jaudio/pikiseq.h"

#include "types.h"

void JV_InitHeader(immut char*);
BOOL JV_InitHeader_M(immut char*, u8*, u8*);
u32 JV_GetArchiveHandle(immut char*);
void JV_GetLogicalHandleS(immut char*, immut char*);
void JV_GetLogicalHandle(immut char*);
void JV_GetHandle(u32);
BarcEntry* JV_GetRealHandle(u32 handle); // Return type unsure
u32 JV_CheckSize(u32);
u32 JV_LoadFile(u32, u8*, u32, u32);
u32 JV_LoadFile_Async2(u32, u8*, u32, u32, void (*)(u32), u32);
void JV_GetMemoryFile(u32);

#endif
