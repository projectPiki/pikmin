#include "jaudio/playercall.h"

static PLAYER_CALL PLAYER_CALLLIST[16];

/*
 * --INFO--
 * Address:	80007120
 * Size:	00002C
 */
void ResetPlayerCallback()
{
	int i;

	for (i = 0; i < 16; i++) {
		PLAYER_CALLLIST[i].callback = nullptr;
	}
}

/*
 * --INFO--
 * Address:	80007160
 * Size:	000050
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

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Jac_RejectPlayerCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800071C0
 * Size:	000048
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

/*
 * --INFO--
 * Address:	80007220
 * Size:	0000A4
 */
s32 Jac_RegisterPlayerCallback(PlayerCallBack callback, void* arg)
{
	u32 i;

	for (i = 0; i < 16; i++) {
		if (PLAYER_CALLLIST[i].callback == nullptr) {
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

/*
 * --INFO--
 * Address:	800072E0
 * Size:	00007C
 */
void PlayerCallback()
{
	u32 i;

	for (i = 0; i < 16; i++) {
		if (PLAYER_CALLLIST[i].callback != nullptr && PLAYER_CALLLIST[i].DSP_mode == FALSE
		    && PLAYER_CALLLIST[i].callback(PLAYER_CALLLIST[i].arg) == -1) {
			PLAYER_CALLLIST[i].callback = nullptr;
		}
	}
}

/*
 * --INFO--
 * Address:	80007360
 * Size:	00007C
 */
void DspPlayerCallback()
{
	u32 i;

	for (i = 0; i < 16; i++) {
		if (PLAYER_CALLLIST[i].callback != nullptr && PLAYER_CALLLIST[i].DSP_mode == TRUE
		    && PLAYER_CALLLIST[i].callback(PLAYER_CALLLIST[i].arg) == -1) {
			PLAYER_CALLLIST[i].callback = nullptr;
		}
	}
}
