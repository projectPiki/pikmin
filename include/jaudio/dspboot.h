#ifndef _JAUDIO_DSPBOOT_H
#define _JAUDIO_DSPBOOT_H

#include "types.h"
#include "jaudio/audiocommon.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO DSP BOOT (C) DEFINITIONS ////////////
// Global functions.
void DSPInit();

// Structs.
/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
typedef struct STRUCT_DSP_TASK2 {
	u16* iram_mmem_addr; // _00
	u32 iram_length;     // _04
	u16 iram_addr;       // _08
	u16* dram_mmem_addr; // _0C
	u32 dram_length;     // _10
	u16 dram_addr;       // _14
	u16 dsp_init_vector; // _16
} DSPTaskInfo2;

/////////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

/////////// JAUDIO DSP BOOT (C++) DEFINITIONS ///////////
// Global functions.
s32 __DSPCheckMXICBoot2(DSPTaskInfo2* task);
void DSPInit2(DSPTaskInfo2* task);
void DspBoot();

// Global declarations.
extern u16 jdsp[];

/////////////////////////////////////////////////////////

#endif
