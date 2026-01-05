#include "jaudio/playercall.h"
#include <stddef.h>

static PLAYER_CALL PLAYER_CALLLIST[16];

/**
 * @TODO: Documentation
 */
void ResetPlayerCallback()
{
	int i;

	for (i = 0; i < 16; i++) {
		PLAYER_CALLLIST[i].callback = NULL;
	}
}

/**
 * @TODO: Documentation
 */
s32 Jac_CheckPlayerCallback(PlayerCallBack callback, void* arg)
{
	int i;

	for (i = 0; i < 16; i++) {
		if (PLAYER_CALLLIST[i].callback == callback && PLAYER_CALLLIST[i].arg == arg) {
			return i;
		}
	}
	return -1;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void Jac_RejectPlayerCallback(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
s32 Jac_RegisterDspPlayerCallback(PlayerCallBack callback, void* arg)
{
	s32 idx = Jac_RegisterPlayerCallback(callback, arg);

	if (idx == -1) {
		return -1;
	}

	PLAYER_CALLLIST[idx].DSP_mode = TRUE;

	return idx;
}

/**
 * @TODO: Documentation
 */
s32 Jac_RegisterPlayerCallback(PlayerCallBack callback, void* arg)
{
	u32 i;

	for (i = 0; i < 16; i++) {
		if (PLAYER_CALLLIST[i].callback == NULL) {
			break;
		}
	}

	if (i == 16) {
		return -1;
	}

	if (Jac_CheckPlayerCallback(callback, arg) != -1) {
		return -1;
	} else {
		PLAYER_CALLLIST[i].callback = callback;
		PLAYER_CALLLIST[i].arg      = arg;
		PLAYER_CALLLIST[i].DSP_mode = FALSE;
		return i;
	}

	return -1;
}

/**
 * @TODO: Documentation
 */
void PlayerCallback()
{
	u32 i;

	for (i = 0; i < 16; i++) {
		if (PLAYER_CALLLIST[i].callback != NULL && PLAYER_CALLLIST[i].DSP_mode == FALSE
		    && PLAYER_CALLLIST[i].callback(PLAYER_CALLLIST[i].arg) == -1) {
			PLAYER_CALLLIST[i].callback = NULL;
		}
	}
}

/**
 * @TODO: Documentation
 */
void DspPlayerCallback()
{
	u32 i;

	for (i = 0; i < 16; i++) {
		if (PLAYER_CALLLIST[i].callback != NULL && PLAYER_CALLLIST[i].DSP_mode == TRUE
		    && PLAYER_CALLLIST[i].callback(PLAYER_CALLLIST[i].arg) == -1) {
			PLAYER_CALLLIST[i].callback = NULL;
		}
	}
}
