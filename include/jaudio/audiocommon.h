#ifndef _JAUDIO_AUDIOCOMMON_H
#define _JAUDIO_AUDIOCOMMON_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

///////////////// JAUDIO ENUMS/DEFINES /////////////////
// Members and names from AC Decomp with gratitude.
// Defines.
#define AUDIO_ARAM_SIZE      0x400000 /* 4MB */
#define AUDIO_ARAM_HEAP_SIZE 0xC000

#define S16_MIN (-0x8000)
#define S16_MAX (0x7FFF)

// Enums.

/**
 * @brief TODO
 */
typedef enum DSPBUF_EVENTS {
	DSPBUF_EVENT_INIT      = 0,
	DSPBUF_EVENT_FRAME_END = 1,
	DSPBUF_EVENT_MIX       = 2,
} DSPBUF_EVENTS;

////////////////////////////////////////////////////////

END_SCOPE_EXTERN_C

#endif
