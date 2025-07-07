#ifndef _P2D_STREAM_H
#define _P2D_STREAM_H

#include "Colour.h"
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
	void getColour(Colour* color)
	{
		u8 comps[4];
		mStream->read(comps, 4);
		color->set(comps[0], comps[1], comps[2], comps[3]);
	}

	RandomAccessStream* mStream; // _00
};

#endif
