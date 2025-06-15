#ifndef _ATXSTREAM_H
#define _ATXSTREAM_H

#include "types.h"
#include "Stream.h"

struct AtxStream;

struct AtxRouter {
	virtual bool openRoute(AtxStream*, int) = 0; // _00
	virtual void closeRoute(AtxStream*)     = 0; // _04
	virtual void lock() { }                      // _08
	virtual void unlock() { }                    // _0C
	virtual void closeAll() { }                  // _10
	virtual void reset() = 0;                    // _14
	virtual bool isConnected() { return false; } // _18
	virtual void setWindow(u32) { }              // _1C
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct AtxStream : public Stream {
	AtxStream() { init(); }

	virtual void read(void*, int);  // _3C
	virtual void write(void*, int); // _40
	virtual int getPending();       // _44
	virtual void close();           // _4C
	virtual void flush();           // _54

	bool open(char*, int);

	void init() { _0C = 0; }

	// _04     = VTBL
	// _00-_08 = Stream
	Stream* mNetStream; // _08, TcpStream, stripped
	int _0C;            // _0C
};

struct BaseApp;

/**
 * @brief TODO
 */
struct AtxCommandStream : public AtxStream {
	AtxCommandStream(BaseApp* app)
	    : mParentApp(app)
	{
	}

	BOOL checkCommands();

	// _04     = VTBL
	// _00-_08 = AtxStream
	BaseApp* mParentApp;
};

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct AtxFileStream : public RandomAccessStream {
	virtual void read(void*, int);  // _3C
	virtual void write(void*, int); // _40
	virtual int getPending();       // _44 (weak)
	virtual void close();           // _4C
	virtual int getPosition();      // _58 (weak)
	virtual void setPosition(int);  // _5C
	virtual int getLength();        // _60 (weak)
	virtual void setLength(int);    // _64 (weak)

	bool open(char*, u32);

	// _04     = VTBL
	// _00-_08 = RandomAccessStream
	int mPosition;        // _08
	int mLength;          // _0C
	AtxStream mAtxStream; // _10
};

#endif
