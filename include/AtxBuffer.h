#ifndef _ATXBUFFER_H
#define _ATXBUFFER_H

#include "types.h"

class RandomAccessStream;

/**
 * @todo Documentation
 */
class AtxBuffer {
public:
	/**
	 * @brief Fabricated.  See `getReadWrite` and `setReadWrite`.
	 */
	struct ReadWrite {
		int w; // _00
		int r; // _04
	};

	void init(RandomAccessStream*, u32, u32);
	void open(int);
	void close();

	void getReadWrite();
	void setReadWrite();

	int getAvailable();
	int getPending();

	void read(void*, int);
	void write(immut void*, int);

private:
	ReadWrite mReadWrite;        // _00
	RandomAccessStream* mStream; // _08
	u32 mStreamBasePos;          // _0C, name is iffy
	u32 mFallbackPos;            // _10, name is iffy
	u32 mWritePos;               // _14
	u32 mReadPos;                // _18
	bool mIsOpen;                // _1C
	int mWriteCounter;           // _20
	int _24;                     // _24, set in `open`.
};

#endif
