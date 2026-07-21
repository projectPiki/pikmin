#ifndef _JAUDIO_FILE_SEQ_H
#define _JAUDIO_FILE_SEQ_H

#include "types.h"

typedef struct seqp_ seqp_;

void Jaf_InitSeqArchive2(immut char* barcFilepath, u8* barcData, u8* archiveWork);
u32 Jaf_CheckSeqSize(u32 arcHandleMask);
u32 Jaf_LoadSeq(u32 seqIndex, u8* seqBuffer);
void Jaf_ClearSeq(u32 seqIndex);
u8* Jaf_CheckSeq(u32 seqIndex);
u32 Jaf_ReadySeq(u32 rootTrackIndex, u32 seqIndex);
BOOL Jaf_PlaySeq(u32 rootTrackIndex);
BOOL Jaf_StartSeq(u32 rootTrackIndex, u32 seqIndex);
BOOL Jaf_StopSeq(u32 rootTrackIndex);
void Jaf_GetJamHandle(u32 rootTrackIndex);
seqp_* Jaf_HandleToSeq(u32 rootTrackIndex);
void Jaf_LoadStartFinish(u32 asyncContext);
void Jaf_LoadStartSeqA(u32 callbackArg, u32 seqIndex, u8* seqBuffer);
u32 Jaf_LoadSeqA(u32 seqIndex, u8* seqBuffer);

#endif
