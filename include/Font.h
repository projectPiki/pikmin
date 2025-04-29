#ifndef _FONT_H
#define _FONT_H

#include "types.h"
#include "Geometry.h"

struct Texture;

/**
 * @brief TODO
 */
struct FontChar {
	FontChar();

	u16 _00;                 // _00
	u16 _02;                 // _02
	u16 mWidth;              // _04
	u16 mHeight;             // _06
	u16 mCharSpacing;        // _08
	u16 mLeftOffset;         // _0A
	RectArea mTextureCoords; // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct Font {
	void setTexture(Texture*, int, int);
	int charToIndex(char);
	int stringWidth(char*);
	int charToIndex(u16);

	// DLL inlines:
	int stringHeight(char* str) { return mCharHeight; }

	Texture* mTexture; // _00
	int mCharWidth;    // _04
	int mCharHeight;   // _08
	FontChar* mChars;  // _0C
};

#endif
