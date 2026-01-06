#ifndef _JAUDIO_DUMMYPROBE_H
#define _JAUDIO_DUMMYPROBE_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

//////////// JAUDIO DUMMY PROBE FUNCTIONS ////////////
void Probe_Start(s32 id, immut char* label);
void Probe_Finish(s32 id);
void Console_printf(immut char*, ...);

///////////////////////////////////////////////////////

END_SCOPE_EXTERN_C

#endif
