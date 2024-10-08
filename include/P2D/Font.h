#ifndef _P2D_FONT_H
#define _P2D_FONT_H

#include "types.h"
#include "GfxObject.h"

struct Colour;

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

	void loadFont(char*, int&, int&);
	void setGX();
	void setGradColor(const Colour&, const Colour&);
	void getWidth(int, int);
	void drawChar(f32, f32, int, int, int);

	// unused/inlined:
	void charToIndex(int);

	// TODO: members
};

#endif
