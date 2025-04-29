#ifndef _P2D_FONT_H
#define _P2D_FONT_H

#include "types.h"
#include "GfxObject.h"
#include "Colour.h"
#include <Font.h>

/**
 * @brief TODO
 */
struct FntobjInfo : public GfxobjInfo {
	FntobjInfo() { mFont = nullptr; }

	// _1C     = VTBL
	// _00-_20 = GfxobjInfo
	Font* mFont; // _20
};

/**
 * @brief TODO
 */
struct P2DFont {
	P2DFont(char*);

	Font* loadFont(char*, int&, int&);
	void setGX();
	void setGradColor(const Colour&, const Colour&);
	f32 getWidth(int, int);
	f32 drawChar(f32, f32, int, int, int);

	// unused/inlined:
	int charToIndex(int);

	int getHeight() { return mFont->mCharHeight; }
	u16 getWidth() { return mWidth; }
	u16 getLeading() { return mLeading; }

	// DLL inlines to do:
	int getAscent();
	int getDescent();
	int getNormalWidth();
	u16 getFontType();
	u8 getAlpha();
	void loadFontTexture();
	void makeResident();

	Font* mFont;  // _00
	u16 _04;      // _04
	u16 mWidth;   // _06
	u16 mLeading; // _08
	u16 _0A;      // _0A
	u16 _0C;      // _0C
	Colour _10;   // _10
	Colour _14;   // _14
	Colour _18;   // _18
	Colour _1C;   // _1C
};

#endif
