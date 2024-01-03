#ifndef _ATXSTREAM_H
#define _ATXSTREAM_H

#include "types.h"
#include "Stream.h"

/**
 * @brief TODO
 */
struct AtxStream : public Stream {

	virtual void read(void*, int);  // _3C
	virtual void write(void*, int); // _40
	virtual int getPending();       // _44
	virtual void close();           // _4C
	virtual void flush();           // _54

	void open(char*, int);

	// _04     = VTBL
	// _00-_08 = Stream
	// TODO: members
};

/**
 * @brief TODO
 */
struct AtxCommandStream : public AtxStream {
	// _04     = VTBL
	// _00-_08 = AtxStream
	// TODO: members
};

/**
 * @brief TODO
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

	// _04     = VTBL
	// _00-_08 = RandomAccessStream
	// TODO: members
};

#endif
