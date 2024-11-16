#ifndef _JAUDIO_AICTRL_H
#define _JAUDIO_AICTRL_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO AI CONTROL FUNCTIONS ////////////
void Jac_HeapSetup(u8*, s32); // args
void OSAlloc2(void);          // args
void Jac_Init(void);          // args
void Jac_VframeWork(void);    // args
void Jac_UpdateDAC(void);     // args
void Jac_SetOutputMode(int mode);
int Jac_GetOutputMode();          // args
void Jac_SetMixerLevel(f32, f32); // args

////////////////////////////////////////////////////

extern int JAC_SYSTEM_OUTPUT_MODE;

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
