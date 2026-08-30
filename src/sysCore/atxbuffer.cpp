#include "AtxBuffer.h"

#include "DebugLog.h"
#include "Stream.h"
#include "endianness.h"
#include "system.h"

#include <stddef.h>

DEFINE_ERROR(5)
DEFINE_PRINT("atxBuffer")

/**
 * @todo Documentation
 */
void AtxBuffer::init(RandomAccessStream* stream, u32 streamBasePos, u32 fallbackPos)
{
	mStream        = stream;
	mStreamBasePos = streamBasePos;
	mFallbackPos   = fallbackPos;
	mIsOpen        = false;
}

/**
 * @todo Documentation
 */
void AtxBuffer::open(int param_1)
{
	if (!mStream) {
		ERROR("no stream");
	}

	_24       = param_1;
	mIsOpen   = true;
	mReadPos  = mStreamBasePos + sizeof(ReadWrite);
	mWritePos = mStreamBasePos + sizeof(ReadWrite);

	mStream->writeIntTo(mStreamBasePos + offsetof(ReadWrite, r), mReadPos);
	mStream->writeIntTo(mStreamBasePos + offsetof(ReadWrite, w), mWritePos);
}

/**
 * @todo Documentation
 */
void AtxBuffer::close(void)
{
	mIsOpen = false;
}

/**
 * @todo Documentation
 */
void AtxBuffer::getReadWrite()
{
	mStream->readFrom(mStreamBasePos, &mReadWrite, sizeof(mReadWrite));
	mReadPos  = BE2H32(mReadWrite.r);
	mWritePos = BE2H32(mReadWrite.w);
}

/**
 * @todo Documentation
 */
void AtxBuffer::setReadWrite()
{
	mReadWrite.r = BE2H32(mReadPos);
	mReadWrite.w = BE2H32(mWritePos);
	mStream->writeTo(mStreamBasePos, &mReadWrite, sizeof(mReadWrite));
}

/**
 * @todo Documentation
 */
int AtxBuffer::getAvailable()
{
	getReadWrite();

	int available = mReadPos - mWritePos - sizeof(ReadWrite);
	if (available <= 0) {
		available = mFallbackPos - mWritePos;
	}
	return available;
}

/**
 * @todo Documentation
 */
int AtxBuffer::getPending()
{
	getReadWrite();

	int pending = mWritePos - mReadPos; // Is `+ sizeof(ReadWrite)` missing here?
	if (pending < 0) {
		pending = mFallbackPos - mReadPos;
	}
	return pending;
}

/**
 * @todo Documentation
 */
void AtxBuffer::read(void* buffer, int length)
{
	void* bufferPos = buffer;

	PRINT("reading\n");
	while (length != 0) {

		int pending;
		while ((pending = getPending()) == 0) {
			PRINT("sleep\n");
			gsys->sleep(0.001f); // 1 millisecond
		}

		u32 readingLength = length;
		if (readingLength >= pending) {
			readingLength = pending;
		}

		mStream->readFrom(mReadPos, bufferPos, readingLength);
		bufferPos = static_cast<u8*>(bufferPos) + readingLength;
		mReadPos += readingLength;
		length -= readingLength;
		mStream->writeIntTo(mStreamBasePos + offsetof(ReadWrite, r), mReadPos);
	}
}

/**
 * @todo Documentation
 */
void AtxBuffer::write(immut void* buffer, int length)
{
	immut void* bufferPos = buffer;

	while (length != 0) {

		int pending;
		while ((pending = getPending()) == 0) {
			gsys->sleep(0.001f); // 1 millisecond
			if (mReadPos == mFallbackPos && mWritePos == mFallbackPos) {
				mWritePos = mStreamBasePos + sizeof(ReadWrite);
				mReadPos  = mWritePos;
				setReadWrite();
			}
		}

		u32 writingLength = length;
		if (writingLength >= pending) {
			writingLength = pending;
		}

		mStream->writeTo(mWritePos, bufferPos, writingLength);
		bufferPos = static_cast<immut u8*>(bufferPos) + writingLength;
		mWritePos += writingLength;
		length -= writingLength;
		mStream->writeIntTo(mStreamBasePos + offsetof(ReadWrite, w), mWritePos);

		++mWriteCounter;
	}
}
