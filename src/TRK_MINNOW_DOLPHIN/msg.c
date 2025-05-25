#include "PowerPC_EABI_Support/MetroTRK/trk.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
/*
void TRKMessageAdd(void)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
/*
void TRKMessageGet(void)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	8021C4A4
 * Size:	000028
 */
DSError TRKMessageSend(TRKBuffer* param_1)
{
	return TRKWriteUARTN(param_1->data, param_1->length);
}
