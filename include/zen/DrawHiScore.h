#ifndef _ZEN_DRAWHISCORE_H
#define _ZEN_DRAWHISCORE_H

#include "types.h"
#include "zen/AlphaWipe.h"
#include "zen/DrawCM.h"

struct Graphics;
struct Controller;
struct P2DScreen;

namespace zen {

/**
 * @brief TODO
 */
struct DrawHiScore {

	enum modeFlag {
		MODE_Sleep     = 0,
		MODE_FadeIn    = 1,
		MODE_Operation = 2,
		MODE_FadeOut   = 3,
	};

	DrawHiScore();

	bool update(Controller*);
	void draw(Graphics&);
	void start();
	void rewriteNumber(P2DScreen*, u32, int, int, bool);

	modeFlag mMode;          // _00
	DrawScreen* mScreen;     // _04
	P2DPane* mTotalsPane;    // _08
	P2DPane* mCMRecordsPane; // _0C
	DrawCMbest mBest;        // _10
	AlphaWipe mAlphaWipe;    // _2C
};

} // namespace zen

#endif
