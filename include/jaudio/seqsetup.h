#ifndef _JAUDIO_SEQSETUP_H
#define _JAUDIO_SEQSETUP_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

typedef struct seqp_ seqp_;

void Jaq_Reset(void);
void Jaq_GetRemainFreeTracks(void);
seqp_* Jaq_HandleToSeq(u32 handle);
BOOL Jaq_StopSeq(s32 index);
s32 Jaq_SetSeqData(seqp_* track, u8* sequenceData, u32 sequenceSize, u32 sourceMode);
s32 Jaq_SetSeqData_Limit(seqp_* track, u8* sequenceData, u32 sequenceSize, u32 sourceMode, u8 oneShotMode);
BOOL Jaq_SetBankNumber(seqp_* track, u8 bankNum);
BOOL Jaq_StartSeq(u32 trackId);
s32 Jaq_OpenTrack(seqp_*, u32, u32);
u32 Jaq_CloseTrack(seqp_*);

END_SCOPE_EXTERN_C

#endif
