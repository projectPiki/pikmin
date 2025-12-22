#ifndef _CMDSTREAM_H
#define _CMDSTREAM_H

#include "Stream.h"

// Lightweight command stream parser built on top of a Stream.
struct CmdStream {
	CmdStream();
	CmdStream(Stream* stream);
	immut char* skipLine();
	immut char* getToken(bool skipComments);
	char nextChar();
	void fillBuffer(bool force);
	void copyToToken(int length);
	bool whiteSpace(char toCheck);
	bool endOfCmds();
	bool isToken(immut char* str);
	bool LineIsComment();
	bool endOfSection();
	inline void init(Stream* stream);

	static char* statbuff;

	Stream* mStream;           // _00, backing stream
	char* mBuffer;             // _04, pointer into statbuff (sliding window)
	char mCurrentToken[0x100]; // _08, token/line scratch buffer
	int mTotalStreamSize;      // _108, total readable bytes in stream
	int mBufferUsed;           // _10C, bytes currently loaded in buffer
	int mBufferOffset;         // _110, absolute stream offset corresponding to buffer[0]
	int mCurrentPosition;      // _114, absolute stream offset of the read cursor
	u8 _118[0x4];              // _118, unknown
};

#endif
