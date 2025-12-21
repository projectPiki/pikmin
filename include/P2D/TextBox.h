#ifndef _P2D_TEXTBOX_H
#define _P2D_TEXTBOX_H

#include "Colour.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"
#include "types.h"

struct Texture;
struct P2DFont;

/**
 * @brief TODO
 *
 * @note Size: 0x118.
 */
struct P2DTextBox : public P2DPane {
public:
	P2DTextBox(P2DPane*, RandomAccessStream*, u16);

	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DTextBox() { }                   // _10 (weak)

	char* getString() { return mText; }
	void setString(char* text) { mText = text; }

	void getFontColor(Colour& charColor, Colour& gradColor)
	{
		charColor = mCharColor;
		gradColor = mGradColor;
	}

	Colour getCharColor() const { return mCharColor; }
	void setCharColor(Colour charColor) { mCharColor = charColor; }
	u8 getAlphaChar() { return mCharColor.a; }

	Colour getGradColor() const { return mGradColor; }
	void setGradColor(Colour gradColor) { mGradColor = gradColor; }
	u8 getAlphaGrad() { return mGradColor.a; }

	u8 getAlpha() { return mCharColor.a; }
	void setAlpha(u8 alpha)
	{
		mCharColor.a = alpha;
		mGradColor.a = alpha;
	}
	void setAlpha(u8 charAlpha, u8 gradAlpha)
	{
		mCharColor.a = charAlpha;
		mGradColor.a = gradAlpha;
	}

	int getCursorX() { return mCursorX; }
	int getCursorY() { return mCursorY; }

protected:
	virtual void drawSelf(int, int);                  // _2C
	virtual void drawSelf(int, int, immut Matrix4f*); // _30

private:
	// _00     = VTBL
	// _00-_EC = P2DPane
	immut char* mFontString;        // _EC
	P2DFont* mFont;                 // _F0
	Colour mCharColor;              // _F4
	Colour mGradColor;              // _F8
	P2DTextBoxHBinding mAlignmentH; // _FC
	P2DTextBoxVBinding mAlignmentV; // _100
	s16 mSpacing;                   // _104
	s16 mLeading;                   // _106
	s16 mFontWidth;                 // _108
	s16 mFontHeight;                // _10A
	char* mText;                    // _10C
	s16 mOffsetX;                   // _110
	s16 mOffsetY;                   // _112
	s16 mCursorX;                   // _114
	s16 mCursorY;                   // _116
};

#endif
