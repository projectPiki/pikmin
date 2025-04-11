#ifndef _ZEN_DRAWFINALRESULT_H
#define _ZEN_DRAWFINALRESULT_H

#include "types.h"

struct Graphics;
struct Controller;
struct P2DPane;

namespace zen {

/**
 * @brief TODO
 */
struct TotalScoreRecord {
	int mParts;     // _00
	int mDay;       // _04
	int mPikis;     // _08
	int mDeadPikis; // _0C
	int _10;        // _10
	s16 _14;        // _14
	s16 _16;        // _16
	s16 _18;        // _18
	s16 _1A[5];     // _1A
	s16 _24[5];     // _24
	s16 _2E[5];     // _2E
	s16 _38[5];     // _38
};

/**
 * @brief TODO
 */
struct DrawTotalScore {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		// TODO: this
	};

	DrawTotalScore(TotalScoreRecord*);

	bool update(Controller*);
	void setMode(modeFlag);
	void playRankInFanfare();
	void setRankInEffect();
	void setRankInColor();

	// unused/inlined:
	void draw(Graphics&);
	void sleep();
	void start();
	void setEffect(P2DPane*, int);

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawFinalResult {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		// TODO: this
	};

	DrawFinalResult(TotalScoreRecord*);

	bool update(Controller*);
	void draw(Graphics&);
	void start();
	void setMode(modeFlag);

	// TODO: members
	u8 _00[0x1b4]; // _00
};

} // namespace zen

#endif
