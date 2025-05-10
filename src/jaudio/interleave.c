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
	if (buf->mStreamFree < size) {
		return FALSE;
	}
	for (int i = 0; i < size; ++i, ++data) {
		buf->mBufData[buf->mBufSendIdx++] = *data;
		if (buf->mBufSendIdx == buf->mBufSize) {
			buf->mBufSendIdx = 0;
		}
	}
	buf->mStreamFree -= size;
	buf->mStreamRemain += size;
	return TRUE;
}

/*
 * --INFO--
 * Address:	8001DB20
 * Size:	000020
 */
BOOL Jac_CheckStreamFree(u32 size)
{
	return (buf->mStreamFree >= size) ? TRUE : FALSE;
}

/*
 * --INFO--
 * Address:	8001DB40
 * Size:	000020
 */
BOOL Jac_CheckStreamRemain(u32 size)
{
	return (buf->mStreamRemain < size) ? FALSE : TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 * Note: Unused in the final game but easy to guess at its contents
 */
u32 Jac_GetStreamRemain()
{
	return buf->mStreamRemain;
}

/*
 * --INFO--
 * Address:	8001DB60
 * Size:	0000C0
 */
u32 Jac_GetStreamData(u8* data, u32 size)
{
	if (buf->mIsInitialized) {
		if (buf->mStreamRemain < buf->mBufSize / 2) {
			return 0;
		}
		buf->mIsInitialized = FALSE;
	}
	if (buf->mStreamRemain < size) {
		size = buf->mStreamRemain;
	}
	for (int i = 0; i < size; ++i, ++data) {
		*data = buf->mBufData[buf->mBufGetIdx++];
		if (buf->mBufGetIdx == buf->mBufSize) {
			buf->mBufGetIdx = 0;
		}
	}
	buf->mStreamRemain -= size;
	buf->mStreamFree += size;
	return size;
}

/*
 * --INFO--
 * Address:	8001DC20
 * Size:	000044
 */
void Jac_InitStreamData(u8* data, u32 size)
{
	buf->mBufData       = data;
	buf->mBufSize       = size;
	buf->mBufSendIdx    = 0;
	buf->mBufGetIdx     = 0;
	buf->mStreamRemain  = 0;
	buf->mStreamFree    = size;
	buf->mIsInitialized = TRUE;
}
