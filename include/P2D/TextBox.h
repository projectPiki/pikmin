#ifndef _P2D_TEXTBOX_H
#define _P2D_TEXTBOX_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"
#include "Colour.h"

struct Texture;

/**
 * @brief TODO
 *
 * @note Size: 0x118.
 */
struct P2DTextBox : public P2DPane {
	P2DTextBox(P2DPane*, RandomAccessStream*, u16);

	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DTextBox();                      // _10 (weak)
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
	u8 _EC[0x10C - 0xEC]; // _EC, unknown
	char* mText;          // _10C
	                      // TODO: members
};

#endif
