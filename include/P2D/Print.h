#ifndef _P2D_PRINT_H
#define _P2D_PRINT_H

#include "Colour.h"
#include "P2D/Util.h"
#include "types.h"

struct P2DFont;

/**
 * @brief TODO
 */
struct P2DPrint {
public:
	/**
	 * @brief TODO
	 */
	struct TSize {
		f32 mTotalWidth;      // _00
		f32 mTotalHeight;     // _04
		f32 mWidthFromStart;  // _08
		f32 mHeightFromStart; // _0C
	};

	void setFontSize(int width, int height)
	{
		mFontWidth  = width > 0 ? width : 0;
		mFontHeight = height > 0 ? height : 0;
	}

	f32 getCursorH() { return mCursorX; }
	f32 getCursorV() { return mCursorY; }

	P2DPrint(P2DFont* font, int spacing, int leading, Colour topColour, Colour bottomColour);

	void printReturn(const char* textBuffer, int, int, P2DTextBoxHBinding, P2DTextBoxVBinding, int, int);
	void locate(int x, int y);
	void setFontSize();

private:
	void private_initiate(P2DFont* font, int spacing, int leading, Colour topColour, Colour bottomColour);
	void initchar();
	f32 parse(const u8* textBuffer, int textLen, int maxWidth, u16* outLineWidths, P2DPrint::TSize& textSize, bool doDraw);
	u16 doEscapeCode(const u8** textPtr);
	void doCtrlCode(int charCode);
	s32 getNumber(const u8** textPtr, s32 defaultValue, s32 invalidValue, int base);

	void u32ToColour(u32 value, Colour* outColour)
	{
		outColour->set(((u8*)&value)[0], ((u8*)&value)[1], ((u8*)&value)[2], ((u8*)&value)[3]);
	}
	u32 ColourTou32(const Colour& colour) { return colour.r << 24 | colour.g << 16 | colour.b << 8 | colour.a; }

	P2DFont* mFont;           // _00
	int mFontSpacing;         // _04
	int mFontLeading;         // _08
	bool mFontGradientActive; // _0C
	bool mSkipEscCtrlCodes;   // _0D
	int mInitX;               // _10
	int mInitY;               // _14
	f32 mCursorX;             // _18
	f32 mCursorY;             // _1C
	f32 mCurrCharWidth;       // _20
	Colour mCharTopColour;    // _24
	Colour mFontTopColour;    // _28
	Colour mCharBottomColour; // _2C
	Colour mFontBottomColour; // _30
	int mFontTabWidth;        // _34
	int mFontWidth;           // _38
	int mFontHeight;          // _3C
	int mCharSpacing;         // _40
	int mCharLeading;         // _44
	bool mCharGradientActive; // _48
	int mCharTabWidth;        // _4C
	int mCharWidth;           // _50
	int mCharHeight;          // _54
};

#endif
