#ifndef _JAUDIO_DUMMYPROBE_H
#define _JAUDIO_DUMMYPROBE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO DUMMY PROBE FUNCTIONS ////////////
void Probe_Start(s32 id, const char* label);
void Probe_Finish(s32 id);
void Console_printf(char*, ...);

///////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
