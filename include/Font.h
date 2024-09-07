#ifndef _FONT_H
#define _FONT_H

#include "types.h"

struct Texture;

/**
 * @brief TODO
 */
struct Font {
	void setTexture(Texture*, int, int);
	void charToIndex(char);
	void charToIndex(u16);
	void stringWidth(char*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct FontChar {
	FontChar();
};

#endif
