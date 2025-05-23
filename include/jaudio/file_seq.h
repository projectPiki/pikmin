#ifndef _JAUDIO_FILE_SEQ_H
#define _JAUDIO_FILE_SEQ_H

#include "types.h"

void Jaf_InitSeqArchive2(char*, u8*, u8*);
u32 Jaf_CheckSeqSize(u32 arcHandleMask);
BOOL Jaf_LoadSeq(u32, u8*);
void Jaf_ClearSeq(u32);
u8* Jaf_CheckSeq(u32);
unknown Jaf_ReadySeq(u32, u32);
BOOL Jaf_PlaySeq(u32);
BOOL Jaf_StartSeq(u32, u32);
BOOL Jaf_StopSeq(u32);
void Jaf_GetJamHandle(u32);
int* Jaf_HandleToSeq(u32);
void Jaf_LoadStartFinish(u32);
void Jaf_LoadStartSeqA(u32, u32, u8*);
void Jaf_LoadSeqA(u32, u8*);

#endif
