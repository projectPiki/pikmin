#ifndef _P2D_FONT_H
#define _P2D_FONT_H

#include "types.h"
#include "GfxObject.h"

struct Colour;
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

	// TODO: members
};

#endif
