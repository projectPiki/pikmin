#ifndef _JAUDIO_VIRLOAD_H
#define _JAUDIO_VIRLOAD_H

#include "types.h"

void JV_InitHeader(char*);
void JV_InitHeader_M(char*, u8*, u8*);
u32 JV_GetArchiveHandle(char*);
void JV_GetLogicalHandleS(char*, char*);
void JV_GetLogicalHandle(char*);
void JV_GetHandle(u32);
void JV_GetRealHandle(u32);
u32 JV_CheckSize(u32);
unknown JV_LoadFile(u32, u8*, u32, u32);
unknown JV_LoadFile_Async2(u32, u8*, u32, u32, void (*)(u32), u32);
void JV_GetMemoryFile(u32);

#endif
