#ifndef _JAUDIO_DSPPROC_H
#define _JAUDIO_DSPPROC_H

#include "types.h"

/////////// JAUDIO DSP PROC DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
s32 DSPSendCommands(u32* commands, u32 count);
u32 DSPReleaseHalt();
void DSPWaitFinish();
void DsetupTable(u32 cmd1, u32 cmd2, u32 cmd3, u32 cmd4, u32 cmd5);
void DsetMixerLevel(f32 level);
void DsyncFrame(u32 subframes, u32 dspbufStart, u32 dspbufEnd);
void DwaitFrame();
void DiplSec(u32 cmd);
void DagbSec(u32 cmd);

#if defined(VERSION_GPIP01_00)
void DsyncFrame2(u32 subframes, u32 dspbufStart, u32 dspbufEnd);
#endif

///////////////////////////////////////////////////

#endif
