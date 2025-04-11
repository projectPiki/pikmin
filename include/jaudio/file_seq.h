#ifndef _JAUDIO_FILE_SEQ_H
#define _JAUDIO_FILE_SEQ_H

#include "types.h"

void Jaf_InitSeqArchive2(char*, u8*, u8*);
void Jaf_CheckSeqSize(u32);
void Jaf_LoadSeq(u32, u8*);
void Jaf_ClearSeq(u32);
void Jaf_CheckSeq(u32);
void Jaf_ReadySeq(u32, u32);
void Jaf_PlaySeq(u32);
void Jaf_StartSeq(u32, u32);
void Jaf_StopSeq(u32);
void Jaf_GetJamHandle(u32);
void Jaf_HandleToSeq(u32);
void Jaf_LoadStartFinish(u32);
void Jaf_LoadStartSeqA(u32, u32, u8*);
void Jaf_LoadSeqA(u32, u8*);

#endif
