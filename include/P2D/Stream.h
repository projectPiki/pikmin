#ifndef _P2D_STREAM_H
#define _P2D_STREAM_H

#include "types.h"
#include <Stream.h>

struct Colour;

/**
 * @brief TODO
 */
struct P2DStream {
	P2DStream(RandomAccessStream* stream) { mStream = stream; }

	char* getResource(int);
	void align(int);

	// unused/inlined:
	~P2DStream() { }

	// DLL inlines:
	void getColour(Colour*);

	RandomAccessStream* mStream; // _00
};

#endif
