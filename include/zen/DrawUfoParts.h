#ifndef _ZEN_DRAWUFOPARTS_H
#define _ZEN_DRAWUFOPARTS_H

#include "types.h"
#include "zen/AlphaWipe.h"
#include "zen/DrawCM.h"

struct Graphics;
struct Controller;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x50.
 */
struct DrawUfoParts {

	enum modeFlag {
		MODE_Sleep     = 0,
		MODE_FadeIn    = 1,
		MODE_Operation = 2,
		MODE_FadeOut   = 3,
	};

	enum returnStatusFlag {
		RETSTATE_Unk0 = 0,
		RETSTATE_Unk1 = 1,
		RETSTATE_Unk2 = 2,
	};

	DrawUfoParts();

	bool update(Controller*);
	void draw(Graphics&);
	void sleep();
	void start();
	void operation();
	void dataSet();

	modeFlag getModeFlag() { return mMode; }
	returnStatusFlag getReturnStatusFlag() { return mReturnState; }

	modeFlag mMode;                // _00
	returnStatusFlag mReturnState; // _04
	DrawScreen* mScreen;           // _08
	AlphaWipe mAlphaWipe;          // _0C
	DrawCMbest mBest;              // _34
};

} // namespace zen

#endif
