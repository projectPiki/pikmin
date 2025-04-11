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

	// DLL inlines to do:
	Colour getCharColor() const;
	Colour getGradColor() const;
	int getCursorX();
	int getCursorY();
	u8 getAlpha();
	u8 getAlphaChar();
	u8 getAlphaGrad();
	void getFontColor(Colour&, Colour&);
	void setAlpha(u8);
	void setAlpha(u8, u8);
	void setCharColor(Colour);
	void setGradColor(Colour);

	// _00     = VTBL
	// _00-_EC = P2DPane
	char* _EC;                    // _EC
	P2DFont* mFont;               // _F0
	Colour _F4;                   // _F4
	Colour _F8;                   // _F8
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
