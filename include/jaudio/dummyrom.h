#ifndef _JAUDIO_DUMMYROM_H
#define _JAUDIO_DUMMYROM_H

#include "jaudio/audiostruct.h"
#include "types.h"

/////////// JAUDIO DUMMY ROM DEFINITIONS ///////////
// Global declarations.
extern u8* JAC_ARAM_DMA_BUFFER_TOP;
extern ALHeap aram_hp;

// Global functions (all C++, so no extern C wrap).
void Jac_SetAudioARAMSize(u32 size);
void* ARAllocFull(u32* outSize);
void Jac_InitARAM(u32 loadAudiorom);

////////////////////////////////////////////////////

#endif
