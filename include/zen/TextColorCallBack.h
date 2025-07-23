#ifndef _ZEN_OGGRAPH_H
#define _ZEN_OGGRAPH_H

#include "P2D/TextBox.h"
#include "types.h"
#include "zen/Math.h"

struct Colour;

namespace zen {

/**
 * @brief Manages animated color transitions for its parent P2DTextBox.
 */
struct TextColorCallBack : public P2DPaneCallBack {
	TextColorCallBack(P2DPane* parent);

	virtual bool invoke(P2DPane* UNUSED); // _08

	// Configures a new color transition with specified target colors and duration.
	void setTargetColor(Colour& targetCharacterColour, Colour& targetGradientColour, f32 transitionDuration);

	// Utility function to interpolate between two color component values based on given weights
	u8 colorBlend(u8 c1, f32 t1, u8 c2, f32 t2) { return RoundOff(c1 * t1 + c2 * t2); }

	// _00     = VTBL
	P2DTextBox* mTextBox;     // _04
	u8 mIsTransitionActive;   // _08
	f32 mTransitionDuration;  // _0C, total duration in seconds for the current transition
	f32 mElapsedTime;         // _10
	Colour mInitialCharColor; // _14, the character colour of the textbox at the start of the transition
	Colour mInitialGradColor; // _18, the gradient colour of the textbox at the start of the transition
	Colour mTargetCharColor;  // _1C, the target character colour
	Colour mTargetGradColor;  // _20, the target gradient colour
};

} // namespace zen

#endif
