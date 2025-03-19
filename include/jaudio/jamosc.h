#ifndef _JAUDIO_JAMOSC_H
#define _JAUDIO_JAMOSC_H

#include "jaudio/jammain_2.h"

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Osc_Update_Param(void);
void Osc_Setup_Simple(void);
void Osc_Clear_Overwrite(void);
void Osc_Init_Env(void);
void Osc_Setup_SimpleEnv(void);
void Osc_Setup_ADSR(void);
void Osc_Setup_Full(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

void Osc_Setup_Vibrato(seqp_*, u8);
void Osc_Setup_Tremolo(seqp_*, u8);

#endif
