#ifndef _JAUDIO_SEQSETUP_H
#define _JAUDIO_SEQSETUP_H

#include "jaudio/jammain_2.h"

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Jaq_Reset(void);
void Jaq_GetRemainFreeTracks(void);
void Jaq_HandleToSeq(void);
void Jaq_StopSeq(void);
void Jaq_SetSeqData(void);
void Jaq_SetSeqData_Limit(void);
void Jaq_SetBankNumber(void);
void Jaq_StartSeq(void);
void Jaq_OpenTrack(void);
void Jaq_CloseTrack(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

void AllocNewRoot(seqp_*);
void DeAllocRoot(seqp_*);

#endif
