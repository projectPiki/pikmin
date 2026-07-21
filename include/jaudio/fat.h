#ifndef _JAUDIO_FAT_H
#define _JAUDIO_FAT_H

#include "types.h"

void Jac_FatMemory_Init(u32 fatMemorySize);
void FAT_InitSystem(u8* basePtr, u32 sizeBytes);
int FAT_AllocateMemory(u32 sizeBytes);
int FAT_FreeMemory(u16 fileHandle);
u8* FAT_GetPointer(u16 fileHandle, u32 offset);
u8 FAT_ReadByte(u16 fileHandle, u32 offset);
u16 FAT_ReadWord(u16 fileHandle, u32 offset);   // UNUSED, but these were probably global
void FAT_ReadWordD(u16 fileHandle, u32 offset); // UNUSED, but these were probably global
u32 FAT_ReadLong(u16 fileHandle, u32 offset);   // UNUSED, but these were probably global
void FAT_ReadLongD(u16 fileHandle, u32 offset); // UNUSED, but these were probably global
int FAT_StoreBlock(u8* src, u16 fileHandle, u32 dstOffset, u32 byteCount);

#endif
