#ifndef _JAUDIO_SEQSETUP_H
#define _JAUDIO_SEQSETUP_H

#include "jaudio/jammain_2.h"

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Jaq_Reset(void);
void Jaq_GetRemainFreeTracks(void);
unknown Jaq_HandleToSeq(u32 handle);
BOOL Jaq_StopSeq(u32 index);
unknown Jaq_SetSeqData(unknown, u8*, u32, unknown);
unknown Jaq_SetSeqData_Limit(unknown, u8*, u32, unknown, unknown);
void Jaq_SetBankNumber(void);
void Jaq_StartSeq(u32);
void Jaq_OpenTrack(void);
void Jaq_CloseTrack(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

void AllocNewRoot(seqp_*);
void DeAllocRoot(seqp_*);

#endif
