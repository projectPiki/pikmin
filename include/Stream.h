#ifndef _STREAM_H
#define _STREAM_H

#include "types.h"
#include "String.h"

struct Stream {
	Stream(void);

	virtual int readInt();               // _08
	virtual char readByte();             // _0C
	virtual short readShort();           // _10
	virtual float readFloat();           // _14
	virtual void readString(char*, int); // _18
	virtual void readString(String&);    // _1C
	virtual char* readString();          // _20
	virtual void writeInt(int);          // _24
	virtual void writeByte(u8);          // _28
	virtual void writeShort(s16);        // _2C
	virtual void writeFloat(f32);        // _30
	virtual void writeString(char*);     // _34
	virtual void writeString(String&);   // _38
	virtual void read(void*, int);       // _3C
	virtual void write(void*, int);      // _40
	virtual int getPending();            // _44
	virtual int getAvailable();          // _48
	virtual void close();                // _4C
	virtual bool getClosing();           // _50 (weak)
	virtual void flush();                // _54 (weak)

	void print(char*, ...);
	void vPrintf(char*, char*);

	char* mPath; // _04
};

struct BufferedInputStream : public Stream {
	BufferedInputStream();
	BufferedInputStream(Stream*, u8*, int);

	class BufferedInputStream& operator=(class BufferedInputStream const&);
	virtual void close(void);
	virtual int getPending(void);
	virtual int getPosition(void);
	virtual void read(void*, int);
	void fillBuffer(void);
	void init(Stream*, u8*, int);
	void open(Stream*);
	void resetBuffer(void);

	u8* mBuffer;           // _08
	s32 mBufferSize;       // _0C
	s32 mRemainingBytes;   // _10
	s32 mCurrentBufferPos; // _14
	s32 mPosition;         // _18
	Stream* mStream;       // _1C
};

#endif