#include "PowerPC_EABI_Support/MetroTRK/trk.h"

static DSError TRK_mainError;

DSError TRK_main(void)
{
	TRK_mainError = TRKInitializeNub();

	if (TRK_mainError == DS_NoError) {
		TRKNubWelcome();
		TRKNubMainLoop();
	}

	return TRK_mainError = TRKTerminateNub();
}
