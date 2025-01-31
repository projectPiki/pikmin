#ifndef _JAUDIO_VERYSIMPLE_H
#define _JAUDIO_VERYSIMPLE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO "VERY SIMPLE" FUNCTIONS ////////////
void Jac_StopSe(s32);
BOOL Jac_PauseCheck();
void Jac_SysSEDemoFadeCheck();
void Jac_PlaySystemSe(s32);
void Jac_StopSystemSe(s32);
BOOL Jac_CheckBootOk();
void Jac_Start(void* heap, u32 heapSize, u32 aramSize);
void Jac_Freeze_Precall();
void Jac_Freeze();
void Jac_AddDVDBuffer(u8* buf, u32);
void Jac_BackDVDBuffer();

///////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
