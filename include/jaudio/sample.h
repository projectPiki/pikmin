#ifndef _JAUDIO_SAMPLE_H
#define _JAUDIO_SAMPLE_H

#include "types.h"

/////////// JAUDIO SAMPLE DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
void Jac_imixcopy(s16* ta, s16* tb, s16* td, s32 s);
void Jac_bcopyfast(u32* src, u32* dest, u32 size);
void Jac_bcopy(void* src, void* dest, s32 size);
void Jac_bzerofast(u32* dest, u32 size);
void Jac_bzero(void* dest, s32 size);

/////////////////////////////////////////////////

#endif
