#ifndef _JAUDIO_IPLDEC_H
#define _JAUDIO_IPLDEC_H

#include "Dolphin/dsp.h"
#include "types.h"

/////////// JAUDIO IPL DEC DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
BOOL DspExtraTaskCheck();
void Jac_DSPcardDecodeAsync(void*, void*, DSPCallback);

// IPL Decode specific structs.

#define DSPTARGET_IPL 0
#define DSPTARGET_AGB 1

/**
 * @brief TODO.
 */
typedef struct DSPTask {
	u8 target;            // _00, ipl (gc) or agb (gameboy player)
	u32 cmd;              // _04
	void* task;           // _08
	DSPCallback callback; // _0C
} DSPTask;

//////////////////////////////////////////////////

#endif
