#ifndef _P2D_STREAM_H
#define _P2D_STREAM_H

#include "types.h"
#include <Stream.h>

/**
 * @brief TODO
 */
struct P2DStream {
	char* getResource(int);
	void align(int);

	// unused/inlined:
	~P2DStream();

	RandomAccessStream* mStream; // _00
};

#endif
