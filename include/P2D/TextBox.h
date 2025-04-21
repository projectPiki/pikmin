#ifndef _P2D_TEXTBOX_H
#define _P2D_TEXTBOX_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"
#include "Colour.h"

struct Texture;
struct P2DFont;

/**
 * @brief TODO
 *
 * @note Size: 0x118.
 */
struct P2DTextBox : public P2DPane {
	P2DTextBox(P2DPane*, RandomAccessStream*, u16);

	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DTextBox() { }                   // _10 (weak)
	virtual void drawSelf(int, int);            // _2C
	virtual void drawSelf(int, int, Matrix4f*); // _30

	char* getString() const { return mText; }
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

	// DLL inlines to do:
	int getCursorX();
	int getCursorY();

	// _00     = VTBL
	// _00-_EC = P2DPane
	char* _EC;                    // _EC
	P2DFont* mFont;               // _F0
	Colour mCharColor;            // _F4
	Colour mGradColor;            // _F8
	P2DTextBoxHBinding mHBinding; // _FC
	P2DTextBoxVBinding mVBinding; // _100
	s16 _104;                     // _104
	s16 _106;                     // _106
	u8 _108[0x4];                 // _108, unknown
	char* mText;                  // _10C
	s16 _110;                     // _110
	s16 _112;                     // _112
	s16 _114;                     // _114
	s16 _116;                     // _116
};

#endif
