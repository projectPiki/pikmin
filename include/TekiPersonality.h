#ifndef _TEKIPERSONALITY_H
#define _TEKIPERSONALITY_H

#include "types.h"

struct RandomAccessStream;

/**
 * @brief TODO
 */
struct TekiPersonality {
	TekiPersonality();

	virtual void read(RandomAccessStream&, int); // _08
	virtual void write(RandomAccessStream&);     // _0C

	void reset();
	void input(TekiPersonality&);

	// _00 = VTBL
	// TODO: members
};

#endif
