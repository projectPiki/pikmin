#include "types.h"
#include "Stream.h"
#include "system.h"
#include "sysNew.h"
#include "stl/mem.h"
#include "Dolphin/os.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("streamBufferedInput");

/*
 * --INFO--
 * Address:	80025500
 * Size:	000098
 */
void BufferedInputStream::init(Stream* stream, u8* buffer, int bufferSize)
{
	mPath             = StdSystem::stringDup(stream->mPath);
	mBufferSize       = bufferSize;
	mBuffer           = buffer ? buffer : new (0x20) u8[mBufferSize];
	mPosition         = 0;
	mCurrentBufferPos = 0;
	mRemainingBytes   = 0;
	mStream           = stream;
	fillBuffer();
}

/*
 * --INFO--
 * Address:	80025598
 * Size:	0000C0
 */
BufferedInputStream::BufferedInputStream(Stream* stream, u8* buffer, int bufferSize)
{
	init(stream, buffer, bufferSize);
}

/*
 * --INFO--
 * Address:	80025658
 * Size:	000088
 */
void BufferedInputStream::fillBuffer()
{
	if (mRemainingBytes - mCurrentBufferPos != 0) {
		return;
	}

	mRemainingBytes = getPending();

	if (mRemainingBytes > mBufferSize) {
		mRemainingBytes = mBufferSize;
	}

	mStream->read(mBuffer, mRemainingBytes);
	mCurrentBufferPos = 0;
}

/*
 * --INFO--
 * Address:	80025724
 * Size:	000104
 */
void BufferedInputStream::read(void* input, int size)
{
	u8* buf = (u8*)input;
	while (size != 0) {
		fillBuffer();
		int diff     = mRemainingBytes - mCurrentBufferPos;
		int copySize = size;
		if (copySize > diff) {
			copySize = diff;
		}
		memcpy(buf, mBuffer + mCurrentBufferPos, copySize);
		buf += copySize;
		size -= copySize;
		mCurrentBufferPos += copySize;
		mPosition += copySize;
	}
}
