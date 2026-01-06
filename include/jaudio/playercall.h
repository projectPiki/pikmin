#ifndef _JAUDIO_PLAYERCALL_H
#define _JAUDIO_PLAYERCALL_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

//////////// JAUDIO PLAYER CALL (C) DEFINITIONS ////////////
// Structs and function typedefs.
typedef s32 (*PlayerCallBack)(void*);

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
typedef struct PLAYER_CALL_ {
	PlayerCallBack callback; // _00
	void* arg;               // _04
	u32 DSP_mode;            // _08
} PLAYER_CALL;

// Global functions.
void ResetPlayerCallback();
s32 Jac_RegisterDspPlayerCallback(PlayerCallBack, void*);
s32 Jac_RegisterPlayerCallback(PlayerCallBack, void*);

////////////////////////////////////////////////////////////

END_SCOPE_EXTERN_C

/////////// JAUDIO PLAYER CALL (C++) DEFINITIONS ///////////
// Global functions.
s32 Jac_CheckPlayerCallback(PlayerCallBack, void*);
void PlayerCallback();
void DspPlayerCallback();

////////////////////////////////////////////////////////////

#endif
