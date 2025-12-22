#include "PowerPC_EABI_Support/MetroTRK/trk.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00002C
 */
/*
void TRKMessageAdd(void)
{
    // UNUSED FUNCTION
}
*/

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008
 */
/*
void TRKMessageGet(void)
{
    // UNUSED FUNCTION
}
*/

/**
 * @TODO: Documentation
 */
DSError TRKMessageSend(TRKBuffer* param_1)
{
	return TRKWriteUARTN(param_1->data, param_1->length);
}
