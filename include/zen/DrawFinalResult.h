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
	// TODO: members
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

	void update(Controller*);
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

	void update(Controller*);
	void draw(Graphics&);
	void start();
	void setMode(modeFlag);

	// TODO: members
};

} // namespace zen

#endif
