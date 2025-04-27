#ifndef _ZEN_DRAWCOUNTDOWN_H
#define _ZEN_DRAWCOUNTDOWN_H

#include "types.h"
#include "zen/DrawCommon.h"
#include "zen/Math.h"
#include "Colour.h"
#include "gameflow.h"

struct Graphics;
struct P2DPicture;

namespace zen {

/**
 * @brief TODO
 */
struct DrawCountDown {
	DrawCountDown();

	void setRate(f32, f32, f32);
	void init(f32, f32, f32*);
	void update();
	void draw(Graphics&);

	// DLL inlines to do:
	u8 colorMerge(u8 c1, f32 t1, u8 c2, f32 t2) { return RoundOff(c1 * t1 + c2 * t2); }
	f32 getClock() { return (mTimePtr) ? *mTimePtr : gameflow.mWorldClock.mTimeOfDay; }

	// this is stripped, but I think it just gets defined ahead of the functions in drawCountDown.cpp
	// so the value (11) gets optimised in and the call gets optimised out.
	static const int countPicsNum;

	// TODO: members
	DrawScreen* mScreen;               // _00
	P2DPicture* mGatherYourPikminPane; // _04
	P2DPicture** mNumberPics;          // _08
	P2DPicture* mCurrentDigit;         // _0C
	f32 mCountDownStartHour;           // _10
	f32 mCountDownEndHour;             // _14
	f32 mHiddenRate;                   // _18, as proportion of 'count' period, so [0.0, 1.0]
	f32 mFadeInRate;                   // _1C, as proportion of 'count' period, so [0.0, 1.0]
	f32 mFadeOutRate;                  // _20, as proportion of 'count' period, so [0.0, 1.0]
	u8 mDefaultTextAlpha;              // _24
	Colour mDefaultTextColor;          // _25
	Colour mPopWhiteTextColor;         // _29
	bool mDoPlaySound;                 // _2D
	f32* mTimePtr;                     // _30
	int mPrevDigit;                    // _34
};

} // namespace zen

#endif
