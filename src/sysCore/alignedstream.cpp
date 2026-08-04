#include "Stream.h"

/**
 * @todo Documentation
 */
void AlignedStream::read(void* buffer, int length)
{
	void* bufferPos  = buffer;
	int lengthRemain = length;
	int streamPos    = getPosition();
	u8 tempBuffer[4];

	while (lengthRemain != 0) {
		if (lengthRemain <= sizeof(tempBuffer) || (streamPos & 3) != 0 || (reinterpret_cast<u32>(bufferPos) & mAlignment) != 0) {
			int readingLength = lengthRemain;
			int paddingLength = streamPos & 3;

			if (readingLength + paddingLength > 4) {
				readingLength = 4 - paddingLength;
			}

			setPosition(streamPos & ~3);
			alignedRead(tempBuffer, sizeof(tempBuffer));

			for (int i = 0; i < readingLength; ++i) {
				static_cast<u8*>(bufferPos)[i] = tempBuffer[i + paddingLength];
			}

			streamPos += readingLength;
			lengthRemain -= readingLength;
			bufferPos = static_cast<u8*>(bufferPos) + readingLength;
		} else {
			int readingLength = lengthRemain & ~1;

			setPosition(streamPos);
			alignedRead(bufferPos, readingLength);

			streamPos += readingLength;
			bufferPos = static_cast<u8*>(bufferPos) + readingLength;
			lengthRemain -= readingLength;
		}
	}
	setPosition(streamPos);
}

/**
 * @todo Documentation
 */
void AlignedStream::write(immut void* buffer, int length)
{
	immut void* bufferPos = buffer;
	int lengthRemain      = length;
	int streamPos         = getPosition();
	u8 tempBuffer[4];

	while (lengthRemain != 0) {
		if (lengthRemain <= sizeof(tempBuffer) || (streamPos & 3) != 0 || (reinterpret_cast<u32>(bufferPos) & mAlignment) != 0) {
			int writingLength = lengthRemain;
			int paddingLength = streamPos & 3;

			if (writingLength + paddingLength > 4) {
				writingLength = 4 - paddingLength;
			}

			if (paddingLength != 0) {
				setPosition(streamPos & ~3);
				alignedRead(tempBuffer, sizeof(tempBuffer));
			}

			for (int i = 0; i < writingLength; ++i) {
				tempBuffer[i + paddingLength] = static_cast<immut u8*>(bufferPos)[i];
			}

			setPosition(streamPos & ~3);
			alignedWrite(tempBuffer, sizeof(tempBuffer));

			streamPos += writingLength;
			lengthRemain -= writingLength;
			bufferPos = static_cast<immut u8*>(bufferPos) + writingLength;
		} else {
			int writingLength = lengthRemain & ~1;

			setPosition(streamPos);
			alignedWrite(bufferPos, writingLength);

			streamPos += writingLength;
			bufferPos = static_cast<immut u8*>(bufferPos) + writingLength;
			lengthRemain -= writingLength;
		}
	}
	setPosition(streamPos);
}
