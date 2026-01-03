#ifndef _STREAM_H
#define _STREAM_H

#include "types.h"
#include <string.h>

struct String;

/**
 * @brief TODO
 *
 * Size: 0x8.
 */
struct Stream {
	Stream() { }

	// _04 = VTBL
	immut char* mPath; // _00

	virtual int readInt();                      // _08
	virtual u8 readByte();                      // _0C
	virtual s16 readShort();                    // _10
	virtual f32 readFloat();                    // _14
	virtual void readString(char*, int);        // _18
	virtual void readString(String&);           // _1C
	virtual char* readString();                 // _20
	virtual void writeInt(int);                 // _24
	virtual void writeByte(u8);                 // _28
	virtual void writeShort(s16);               // _2C
	virtual void writeFloat(f32);               // _30
	virtual void writeString(immut char*);      // _34
	virtual void writeString(immut String&);    // _38
	virtual void read(void*, int);              // _3C
	virtual void write(immut void*, int);       // _40
	virtual int getPending();                   // _44
	virtual int getAvailable();                 // _48
	virtual void close();                       // _4C
	virtual bool getClosing() { return false; } // _50 (weak)
	virtual void flush() { }                    // _54 (weak)

	void print(immut char*, ...);
};

/**
 * @brief TODO
 */
struct RandomAccessStream : public Stream {
	virtual int getPosition() { return 0; }                          // _58 (weak)
	virtual int getPending() { return getLength() - getPosition(); } // _44 (weak)
	virtual void setPosition(int) { }                                // _5C (weak)
	virtual int getLength() { return getAvailable(); }               // _60 (weak)

	void skipPadding(u32 paddingAmount)
	{
		int length       = getPosition();
		int resultAmount = (~(paddingAmount - 1) & (length + paddingAmount - 1)) - length;

		for (int i = 0; i < resultAmount; i++) {
			readByte();
		}
	}

	void padFile(u32 paddingAmount)
	{
		int length       = getPosition();
		int resultAmount = (~(paddingAmount - 1) & (length + paddingAmount - 1)) - length;
		for (int i = 0; i < resultAmount; i++) {
			writeByte(0);
		}
	}

	void padFileTo(u32 paddingAmount, u32 offset)
	{
		int pos          = getPosition();
		int resultAmount = paddingAmount - pos - offset;
		for (int i = 0; i < resultAmount; i++) {
			writeByte(0);
		}
	}

	inline BOOL checkInput()
	{
		if (readByte() == 0) {
			return false;
		}
		return true;
	}

	// unused/inlined:
	void writeTo(int, void*, int);

	// _04     = VTBL
	// _00-_08 = Stream
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct BufferedInputStream : public RandomAccessStream {
	BufferedInputStream()
	{
		mBuffer = nullptr;
		mStream = nullptr;
	}

	BufferedInputStream(Stream*, u8*, int);

	virtual void read(void*, int);                                         // _3C
	virtual int getPending() { return mStream->getPending() - mPosition; } // _44 (weak)
	virtual void close() { mStream->close(); }                             // _4C (weak)
	virtual int getPosition() { return mPosition; }                        // _58 (weak)

	void init(Stream*, u8*, int);
	void fillBuffer();

	// _04     = VTBL
	// _00-_08 = RandomAccessStream
	u8* mBuffer;           // _08
	int mBufferSize;       // _0C
	int mRemainingBytes;   // _10
	int mCurrentBufferPos; // _14
	int mPosition;         // _18
	Stream* mStream;       // _1C
};

/**
 * @brief TODO
 */
struct RamStream : public RandomAccessStream {
	inline RamStream(void* buffer, int size)
	{
		mBufferAddr = buffer;
		mPosition   = 0;
		mLength     = size;
	}

	virtual int getPending() { return mLength - mPosition; } // _44 (weak)
	virtual void setPosition(int pos) { mPosition = pos; }   // _5C (weak)
	virtual int getPosition() { return mPosition; }          // _58 (weak)
	virtual int getLength() { return mLength; }              // _60 (weak)
	virtual void setLength(int len) { mLength = len; }       // _64 (weak)
	virtual void read(void* dest, int size)                  // _3C (weak)
	{
		memcpy(dest, (const void*)((int)mBufferAddr + mPosition), size);
		mPosition += size;
	}
	virtual void write(immut void* src, int size) // _40 (weak)
	{
		memcpy((void*)((int)mBufferAddr + mPosition), src, size);
		mPosition += size;
	}

	// _04     = VTBL
	// _00-_08 = RandomAccessStream
	void* mBufferAddr; // _08
	int mPosition;     // _0C
	int mLength;       // _10
};

extern Stream* sysCon;
extern Stream* errCon;

#endif
