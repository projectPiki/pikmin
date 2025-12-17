#ifndef _P2D_FONT_H
#define _P2D_FONT_H

#include "Colour.h"
#include "Dolphin/gx.h"
#include "GfxObject.h"
#include "Texture.h"
#include "types.h"
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
	P2DFont(immut char*);

	Font* loadFont(immut char* fileName, int&, int&);
	void setGX();
	void setGradColor(const Colour& topColour, const Colour& bottomColour);
	f32 getWidth(int charCode, int drawWidth);
	f32 drawChar(f32 xPos, f32 yPos, int charCode, int drawWidth, int drawHeight);

	// unused/inlined:
	int charToIndex(int c);

	int getHeight() { return mFont->mCharHeight; }
	int getNormalWidth() { return mWidth; }
	u16 getWidth() { return mWidth; }
	u16 getLeading() { return mLeading; }
	u16 getFontType() { return mFontType; }

	int getAscent() { return mAscent; }
	int getDescent() { return mDescent; }

	u8 getAlpha() { return mTLColour.a; }

	void makeResident() { mFont->mTexture->makeResident(); }
	void loadFontTexture()
	{
		mFont->mTexture->makeResident();
		GXLoadTexObj(mFont->mTexture->mTexObj, GX_TEXMAP0);
	}

	Font* mFont;      // _00
	u16 mFontType;    // _04
	u16 mWidth;       // _06
	u16 mLeading;     // _08
	u16 mAscent;      // _0A
	u16 mDescent;     // _0C
	Colour mTLColour; // _0E, top left corner colour
	Colour mTRColour; // _12, top right corner colour
	Colour mBLColour; // _16, bottom left corner colour
	Colour mBRColour; // _1A, bottom right corner colour
};

#endif
