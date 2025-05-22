#ifndef _JAUDIO_DSPDRIVER_H
#define _JAUDIO_DSPDRIVER_H

#include "types.h"
#include "jaudio/audiostruct.h"

/////////// JAUDIO DSP DRIVER DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).

dspch_* GetDSPchannelHandle(u32 idx);
void InitDSPchannel();
dspch_* AllocDSPchannel(u32, u32);
void DeAllocDSPchannel(dspch_*, u32);
dspch_* GetLowerDSPchannel();
dspch_* GetLowerActiveDSPchannel();
BOOL ForceStopDSPchannel(dspch_* volatile);
BOOL BreakLowerDSPchannel(volatile u8);
void BreakLowerActiveDSPchannel(u8);
void UpdateDSPchannelAll();

/////////////////////////////////////////////////////

#endif
