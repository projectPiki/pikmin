#ifndef _JAUDIO_VIRLOAD_H
#define _JAUDIO_VIRLOAD_H

#include "jaudio/pikiseq.h"

#include "types.h"

void JV_InitHeader(immut char*);
BOOL JV_InitHeader_M(immut char* fileName, u8* barcData, u8* archiveWork);
u32 JV_GetArchiveHandle(immut char* archiveName);
void JV_GetLogicalHandleS(immut char*, immut char*);
void JV_GetLogicalHandle(immut char*);
void JV_GetHandle(u32);
BarcEntry* JV_GetRealHandle(u32 handle); // Return type unsure
u32 JV_CheckSize(u32 handle);
u32 JV_LoadFile(u32 handle, u8* dst, u32 offset, u32 length);
u32 JV_LoadFile_Async2(u32 handle, u8* dst, u32 offset, u32 length, void (*callback)(u32), u32 owner);
void JV_GetMemoryFile(u32);

#endif
