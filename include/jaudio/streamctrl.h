#ifndef _JAUDIO_STREAMCTRL_H
#define _JAUDIO_STREAMCTRL_H

#include "types.h"

/////////// JAUDIO STREAM DEFINITIONS ///////////
// Defines.
#define JSTREAM_NO_TRACK_ID   (-1)
#define JSTREAM_FADEOUT_TIMER (120)

// Structs and enums.
/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
typedef struct JSTREAM_ {
	s32 state;             // _00
	s32 req_stream_id;     // _04
	s32 now_stream_id;     // _08
	f32 fadein_vol;        // _0C
	s32 fadein_vol_timer;  // _10
	s32 _14;               // _14
	s32 fadeout_timer;     // _18
	f32 target_vol1;       // _1C
	s32 change_vol_timer1; // _20
	f32 stream_vol;        // _24
	u32 total_samples;     // _28
} JSTREAM;

/**
 * @brief TODO
 */
typedef enum JSTREAM_STATE_ {
	JSTREAM_STATE_STOPPED        = 0,
	JSTREAM_STATE_REQUEST_STREAM = 1,
	JSTREAM_STATE_START          = 2,
	JSTREAM_STATE_PLAYING        = 3,
	JSTREAM_STATE_CANCELLED      = 4,
	JSTREAM_STATE_FADEOUT        = 5,
	JSTREAM_STATE_STOP           = 6,
	JSTREAM_STATE_CLEANUP        = 7,

	JSTREAM_STATE_NUM, // 8
} JSTREAM_STATE;

// Global functions (all C++, so no extern C wrap).
void StreamMain();

/////////////////////////////////////////////////

#endif
