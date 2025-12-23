#include "Stream.h"

#include "DebugLog.h"
#include "Dolphin/os.h"
#include "sysNew.h"
#include "system.h"
#include <mem.h>

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("streamBufferedInput");

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
BufferedInputStream::BufferedInputStream(Stream* stream, u8* buffer, int bufferSize)
{
	init(stream, buffer, bufferSize);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void BufferedInputStream::read(void* input, int size)
{
	u8* buf = static_cast<u8*>(input);
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
