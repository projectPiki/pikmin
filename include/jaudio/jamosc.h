#ifndef _JAUDIO_JAMOSC_H
#define _JAUDIO_JAMOSC_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

typedef struct seqp_ seqp_;

void Osc_Update_Param(seqp_* seq, u8 id, f32 val);
void Osc_Setup_Simple(seqp_*, u8);
void Osc_Clear_Overwrite(seqp_*);
void Osc_Init_Env(seqp_*);
void Osc_Setup_SimpleEnv(seqp_*, u8, u32);
void Osc_Setup_ADSR(seqp_*, s16*);
void Osc_Setup_Full(seqp_*, u8, u32, u32);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
