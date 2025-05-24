#ifndef _JAUDIO_SEQSETUP_H
#define _JAUDIO_SEQSETUP_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

typedef struct seqp_ seqp_;

void Jaq_Reset(void);
void Jaq_GetRemainFreeTracks(void);
seqp_* Jaq_HandleToSeq(u32 handle);
BOOL Jaq_StopSeq(u32 index);
unknown Jaq_SetSeqData(unknown, u8*, u32, unknown);
unknown Jaq_SetSeqData_Limit(unknown, u8*, u32, unknown, unknown);
void Jaq_SetBankNumber(int*, u8);
BOOL Jaq_StartSeq(u32);
void Jaq_OpenTrack(seqp_*, unknown, unknown);
void Jaq_CloseTrack(seqp_*);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
