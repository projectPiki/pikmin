#ifndef _FONT_H
#define _FONT_H

#include "types.h"

struct Texture;

/**
 * @brief TODO
 *
 * @note Maybe size 0x10? If not, need to change PaniTestNode
 */
struct Font {
	void setTexture(Texture*, int, int);
	void charToIndex(char);
	void charToIndex(u16);
	void stringWidth(char*);

	// TODO: members
	u8 _00[0x10]; // _00
};

/**
 * @brief TODO
 */
struct FontChar {
	FontChar();
};

#endif
