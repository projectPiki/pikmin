#ifndef _COLOUR_H
#define _COLOUR_H

#include "types.h"

/**
 * @brief TODO
 */
struct Colour {
	Colour() { }

	Colour(const Colour& other)
	{
		r = other.r;
		g = other.g;
		b = other.b;
		a = other.a;
	}

	Colour(u8 _r, u8 _g, u8 _b, u8 _a) { set(_r, _g, _b, _a); }

	void set(u8 _r, u8 _g, u8 _b, u8 _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}

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
