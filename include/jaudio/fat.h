#ifndef _JAUDIO_FAT_H
#define _JAUDIO_FAT_H

#include "types.h"

void Jac_FatMemory_Init(u32);
void FAT_InitSystem(u8*, u32);
void FAT_AllocateMemory(u32);
void FAT_FreeMemory(u16);
void FAT_GetPointer(u16, u32);
void FAT_ReadByte(u16, u32);
void FAT_ReadWord(u16, u32);  // UNUSED, but these were probably global
void FAT_ReadWordD(u16, u32); // UNUSED, but these were probably global
void FAT_ReadLong(u16, u32);  // UNUSED, but these were probably global
void FAT_ReadLongD(u16, u32); // UNUSED, but these were probably global
void FAT_StoreBlock(u8*, u16, u32, u32);

#endif
