#ifndef _JAUDIO_DSPINTERFACE_H
#define _JAUDIO_DSPINTERFACE_H

#include "types.h"
#include "jaudio/audiostruct.h"

/////////// JAUDIO DSP INTERFACE DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
void GetDspHandle(u8);
void GetFxHandle(u8);
void DSP_SetPitch(u8, u16);
void DSP_SetMixerInitDelayMax(u8, u8);
void DSP_SetMixerInitVolume(u8, u8, s16, u8);
void DSP_SetMixerVolume(u8, u8, s16, u8);
void DSP_SetOscInfo(u8, u32);
void DSP_SetPauseFlag(u8, u8);
void DSP_SetWaveInfo(u8, Wave*, u32);
void DSP_SetBusConnect(u8, u8, u8);
void DSP_PlayStop(u8);
void DSP_AllocInit(u8);
void DSP_PlayStart(u8);
void DSP_SetDistFilter(u8, s16);
void DSP_SetFilterTable(s16*, s16*, u32);
void DSP_SetIIRFilterParam(u8, s16*);
void DSP_SetFIR8FilterParam(u8, s16*);
void DSP_SetFilterMode(u8, u16);
void DSP_InitFilter(u8);
void DSP_FlushBuffer();
void DSP_FlushChannel(u8);
void DSP_InvalChannelAll();
void DSP_ClearBuffer();
void DSP_SetupBuffer();
void DSP_InitBuffer();

////////////////////////////////////////////////////////

#endif
