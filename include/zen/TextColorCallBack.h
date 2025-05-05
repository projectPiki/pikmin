#ifndef _ZEN_OGGRAPH_H
#define _ZEN_OGGRAPH_H

#include "types.h"
#include "zen/Math.h"
#include "P2D/TextBox.h"

struct Colour;

namespace zen {

/**
 * @brief TODO
 */
struct TextColorCallBack : public P2DPaneCallBack {
	TextColorCallBack(P2DPane*);

	virtual bool invoke(P2DPane*); // _08

	void setTargetColor(Colour&, Colour&, f32);

	u8 colorMerge(u8 c1, f32 t1, u8 c2, f32 t2) { return RoundOff(c1 * t1 + c2 * t2); }

	P2DTextBox* mTextBox; // _04
	u8 _08;               // _08
	f32 _0C;              // _0C
	f32 _10;              // _10
	Colour _14;           // _14
	Colour _18;           // _14
	Colour _1C;           // _1C
	Colour _20;           // _20
};

} // namespace zen

#endif
