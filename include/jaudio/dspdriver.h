#ifndef _JAUDIO_DSPDRIVER_H
#define _JAUDIO_DSPDRIVER_H

#include "types.h"
#include "jaudio/audiostruct.h"

/////////// JAUDIO DSP DRIVER DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
void InitDSPchannel();
void AllocDSPchannel(u32, u32);
void DeAlloDSPchannel(dspch_*, u32);
void GetLowerDSPchannel();
void GetLowerActiveDSPchannel();
void ForceStopDSPchannel(dspch_*);
void BreakLowerDSPchannel(u8);
void BreakLowerActiveDSPchannel(u8);
void UpdateDSPchannelAll();

/////////////////////////////////////////////////////

#endif
