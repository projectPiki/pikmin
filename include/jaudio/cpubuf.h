#ifndef _JAUDIO_CPUBUF_H
#define _JAUDIO_CPUBUF_H

#include "jaudio/dspbuf.h"
#include "types.h"

/////////// JAUDIO CPU BUFFER DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
s16* CpubufProcess(DSPBUF_EVENTS event);
void CpuFrameEnd();

/////////////////////////////////////////////////////

#endif
