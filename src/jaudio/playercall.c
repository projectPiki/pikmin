#include "jaudio/playercall.h"

static PLAYER_CALL PLAYER_CALLLIST[16];

void ResetPlayerCallback()
{
	int i;

	for (i = 0; i < 16; i++) {
		PLAYER_CALLLIST[i].callback = NULL;
	}
}

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

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Jac_RejectPlayerCallback(void)
{
	// UNUSED FUNCTION
}

s32 Jac_RegisterDspPlayerCallback(PlayerCallBack callback, void* arg)
{
	s32 idx = Jac_RegisterPlayerCallback(callback, arg);

	if (idx == -1) {
		return -1;
	}

	PLAYER_CALLLIST[idx].DSP_mode = TRUE;

	return idx;
}

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
