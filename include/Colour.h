#ifndef _COLOUR_H
#define _COLOUR_H

#include "types.h"

/**
 * @brief TODO
 */
struct Colour {
	Colour();
	Colour(const Colour&);

	// unused/inlined:
	void write(struct Stream&);

	u8 r, g, b, a; // _00-_04
};

/**
 * @brief TODO
 */
struct ShortColour {
	s16 r, g, b, a; // _00-_0A
};

/**
 * @brief TODO
 */
struct LShortColour {
	s16 r, g, b, a; // _00-_0A
};

#endif
