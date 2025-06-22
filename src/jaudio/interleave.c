#include "jaudio/interleave.h"

static InterleaveBuffer interleavebuf;
static InterleaveBuffer* buf = &interleavebuf;

/*
 * --INFO--
 * Address:	8001DA80
 * Size:	000090
 */
BOOL Jac_SendStreamData(u8* data, u32 size)
{
	if (buf->streamFree < size) {
		return FALSE;
	}
	for (int i = 0; i < size; ++i, ++data) {
		buf->bufData[buf->bufSendIdx++] = *data;
		if (buf->bufSendIdx == buf->bufSize) {
			buf->bufSendIdx = 0;
		}
	}
	buf->streamFree -= size;
	buf->streamRemain += size;
	return TRUE;
}

/*
 * --INFO--
 * Address:	8001DB20
 * Size:	000020
 */
BOOL Jac_CheckStreamFree(u32 size)
{
	return (buf->streamFree >= size) ? TRUE : FALSE;
}

/*
 * --INFO--
 * Address:	8001DB40
 * Size:	000020
 */
BOOL Jac_CheckStreamRemain(u32 size)
{
	return (buf->streamRemain < size) ? FALSE : TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 * Note: Unused in the final game but easy to guess at its contents
 */
u32 Jac_GetStreamRemain()
{
	return buf->streamRemain;
}

/*
 * --INFO--
 * Address:	8001DB60
 * Size:	0000C0
 */
u32 Jac_GetStreamData(u8* data, u32 size)
{
	if (buf->isInit) {
		if (buf->streamRemain < buf->bufSize / 2) {
			return 0;
		}
		buf->isInit = FALSE;
	}
	if (buf->streamRemain < size) {
		size = buf->streamRemain;
	}
	for (int i = 0; i < size; ++i, ++data) {
		*data = buf->bufData[buf->bufGetIdx++];
		if (buf->bufGetIdx == buf->bufSize) {
			buf->bufGetIdx = 0;
		}
	}
	buf->streamRemain -= size;
	buf->streamFree += size;
	return size;
}

/*
 * --INFO--
 * Address:	8001DC20
 * Size:	000044
 */
void Jac_InitStreamData(u8* data, u32 size)
{
	buf->bufData      = data;
	buf->bufSize      = size;
	buf->bufSendIdx   = 0;
	buf->bufGetIdx    = 0;
	buf->streamRemain = 0;
	buf->streamFree   = size;
	buf->isInit       = TRUE;
}
