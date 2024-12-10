#ifndef _JAUDIO_CPUBUF_H
#define _JAUDIO_CPUBUF_H

#include "types.h"
#include "jaudio/dspbuf.h"

/////////// JAUDIO CPU BUFFER DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
s16* CpubufProcess(DSPBUF_EVENTS event);
void CpuFrameEnd();

/////////////////////////////////////////////////////

#endif
