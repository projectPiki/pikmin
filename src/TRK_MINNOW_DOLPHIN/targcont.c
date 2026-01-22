#include "PowerPC_EABI_Support/MetroTRK/trk.h"

/**
 * @TODO: Documentation
 */

DSError TRKTargetContinue(void)
{
	TRKTargetSetStopped(FALSE);
	UnreserveEXI2Port();
	TRKSwapAndGo();
	ReserveEXI2Port();
	return DS_NoError;
}
