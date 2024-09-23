#ifndef _P2D_TEXTBOX_H
#define _P2D_TEXTBOX_H

#include "types.h"
#include "P2D/Pane.h"
#include "P2D/Util.h"

struct Texture;

/**
 * @brief TODO
 */
struct P2DTextBox : public P2DPane {
	P2DTextBox(P2DPane*, RandomAccessStream*, u16);

	virtual void loadResource();                // _08
	virtual void makeResident();                // _0C
	virtual ~P2DTextBox();                      // _10 (weak)
	virtual void drawSelf(int, int);            // _2C
	virtual void drawSelf(int, int, Matrix4f*); // _30

	// _00     = VTBL
	// _00-_?? = P2DPane
	// TODO: members
};

#endif
