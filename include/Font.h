#ifndef _FONT_H
#define _FONT_H

#include "Geometry.h"
#include "types.h"

struct Texture;

#define ASCII_PRINTABLE_MIN (0x20) // space
#define ASCII_PRINTABLE_MAX (0x80) // one more than last printable symbol (0x7F = delete)

/**
 * @brief TODO
 */
struct FontChar {
	FontChar()
	{
		mTextureX = mTextureY = 0;
		mWidth = mHeight = 8;
	}

	u16 mTextureX;           // _00
	u16 mTextureY;           // _02
	s16 mWidth;              // _04
	s16 mHeight;             // _06
	s16 mCharSpacing;        // _08
	s16 mLeftOffset;         // _0A
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
