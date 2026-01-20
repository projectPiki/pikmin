#include "Dolphin/trk.h"

/**
 * @TODO: Documentation
 */

unsigned int TRKTargetContinue(void)
{
	TRKTargetSetStopped(FALSE);
	UnreserveEXI2Port();
	TRKSwapAndGo();
	ReserveEXI2Port();
	return 0;
}
