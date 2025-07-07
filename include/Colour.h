#ifndef _COLOUR_H
#define _COLOUR_H

#include "Stream.h"
#include "types.h"

#define COLOUR_TO_U32(colour) ((u8)(colour.a) | (((u8)(colour.b) << 8) | (((u8)(colour.g) << 16) | ((u8)(colour.r) << 24))))

/**
 * @brief TODO
 */
struct Colour {
	Colour() { }

	Colour(u8 _r, u8 _g, u8 _b, u8 _a) { set(_r, _g, _b, _a); }

	void set(u8 _r, u8 _g, u8 _b, u8 _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}

	void set(f32 _r, f32 _g, f32 _b)
	{
		r = _r;
		g = _g;
		b = _b;
		a = 255;
	}

	// unused/inlined:
	void write(struct Stream&);

	void lerpTo(Colour& target, f32 ratio, Colour& outColour)
	{
		outColour.r = (f32(target.r) - f32(r)) * ratio + f32(r);
		outColour.g = (f32(target.g) - f32(g)) * ratio + f32(g);
		outColour.b = (f32(target.b) - f32(b)) * ratio + f32(b);
		outColour.a = (f32(target.a) - f32(a)) * ratio + f32(a);
	}

	// DLL inlines (there are more in sysCore, but they never make it to plugPiki)
	void read(Stream& input)
	{
		r = input.readByte();
		g = input.readByte();
		b = input.readByte();
		a = input.readByte();
	}

	bool operator==(u32 other)
	{
		u32 color = a | ((b << 8) | ((g << 16) | (r << 24)));
		if (color == other) {
			return true;
		}
		return false;
	}

	bool operator!=(u32 other) { return !(*this == other); }

	u8 r, g, b, a; // _00-_04
};

/**
 * @brief TODO
 */
struct ShortColour {
	void read(RandomAccessStream& input)
	{
		r = input.readShort();
		g = input.readShort();
		b = input.readShort();
		a = input.readShort();
	}

	s16 r, g, b, a; // _00-_0A
};

/**
 * @brief TODO
 */
struct LShortColour {
	s16 r, g, b, a; // _00-_0A
};

#endif
