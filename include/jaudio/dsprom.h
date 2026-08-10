#if defined(VERSION_GPIP01)
#include "jaudio/dsprom_pal.h"
#elif defined(VERSION_G98E01_PIKIDEMO)
// Fun Fact: Prior to Dolphin Emulator 5.0-16483, USA Demo's different DSP microcode required DSP LLE to run.
// This wasn't because it was difficult to support or anything, it was just so obscure that nobody had thought to add it yet.
// https://dolphin-emu.org/download/dev/8b3517a9f943b7379805a5a6a5a4d77c60d366f9/
#include "jaudio/dsprom_usa_demo.h"
#else
#include "jaudio/dsprom_ntsc.h"
#endif
