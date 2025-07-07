#ifndef _JAUDIO_DSPBUF_H
#define _JAUDIO_DSPBUF_H

#include "jaudio/audiocommon.h"
#include "types.h"

/////////// JAUDIO DSP BUFFER DEFINITIONS ///////////
// Defines.
#define DSPBUF_NUM 3

// Global functions (all C++, so no extern C wrap).
u32 Jac_GetCurrentSCounter();
s16* DspbufProcess(DSPBUF_EVENTS event);
void UpdateDSP();
s16* MixDsp(s32 numSamples);
void DspFrameEnd();

/////////////////////////////////////////////////////

#endif
