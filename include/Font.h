#ifndef _FONT_H
#define _FONT_H

#include "types.h"

struct Texture;

/**
 * @brief TODO
 */
struct FontChar {
	FontChar();

	u16 _00;     // _00
	u16 _02;     // _02
	u16 _04;     // _04
	u16 _06;     // _06
	u8 _08[0x4]; // _08, unknown
	u32 _0C;     // _0C, unknown
	u32 _10;     // _10, unknown
	u32 _14;     // _14, unknown
	u32 _18;     // _18, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct Font {
	void setTexture(Texture*, int, int);
	int charToIndex(char); // may not be int
	void charToIndex(u16);
	int stringWidth(char*);

	// TODO: members
	Texture* mTexture; // _00
	int mCharWidth;    // _04
	int mCharHeight;   // _08
	FontChar* mChars;  // _0C
};

#endif
