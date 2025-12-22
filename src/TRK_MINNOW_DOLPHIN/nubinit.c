#include "PowerPC_EABI_Support/MetroTRK/trk.h"

BOOL gTRKBigEndian;

DSError TRKInitializeNub(void)
{
	DSError ret;
	DSError uartErr;

	ret = TRKInitializeEndian();

	if (ret == DS_NoError)
		usr_put_initialize();
	if (ret == DS_NoError)
		ret = TRKInitializeEventQueue();
	if (ret == DS_NoError)
		ret = TRKInitializeMessageBuffers();
	if (ret == DS_NoError)
		ret = TRKInitializeDispatcher();

	if (ret == DS_NoError) {
		uartErr = TRKInitializeIntDrivenUART(0x0000e100, 1, 0, (volatile u8**)&gTRKInputPendingPtr);
		TRKTargetSetInputPendingPtr(gTRKInputPendingPtr);
		if (uartErr != DS_NoError) {
			ret = uartErr;
		}
	}

	if (ret == DS_NoError)
		ret = TRKInitializeSerialHandler();
	if (ret == DS_NoError)
		ret = TRKInitializeTarget();

	return ret;
}

DSError TRKTerminateNub(void)
{
	TRKTerminateSerialHandler();
	return DS_NoError;
}

void TRKNubWelcome(void)
{
	TRK_board_display("MetroTRK for Dolphin v0.8");
	return;
}

BOOL TRKInitializeEndian(void)
{
	u8 bendian[4];
	BOOL result   = FALSE;
	gTRKBigEndian = TRUE;

	bendian[0] = 0x12;
	bendian[1] = 0x34;
	bendian[2] = 0x56;
	bendian[3] = 0x78;

	if (*(u32*)bendian == 0x12345678) {
		gTRKBigEndian = TRUE;
	} else if (*(u32*)bendian == 0x78563412) {
		gTRKBigEndian = FALSE;
	} else {
		result = TRUE;
	}
	return result;
}
