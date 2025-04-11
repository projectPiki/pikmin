#ifndef _P2D_FONT_H
#define _P2D_FONT_H

#include "types.h"
#include "GfxObject.h"
#include "Colour.h"

struct Font;

/**
 * @brief TODO
 */
struct FntobjInfo : public GfxobjInfo {
	// _1C     = VTBL
	// _00-_20 = GfxobjInfo
	// TODO: members
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

	// DLL inlines to do:
	int getAscent();
	int getDescent();
	int getHeight();
	int getNormalWidth();
	u16 getFontType();
	u16 getLeading();
	u16 getWidth();
	u8 getAlpha();
	void loadFontTexture();
	void makeResident();

	Font* mFont; // _00
	u16 _04;     // _04
	u16 _06;     // _06
	u16 _08;     // _08
	u16 _0A;     // _0A
	u16 _0C;     // _0C
	Colour _10;  // _10
	Colour _14;  // _14
	Colour _18;  // _18
	Colour _1C;  // _1C
};

#endif
