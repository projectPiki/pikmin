#ifndef _ZEN_OGTOTALSCORE_H
#define _ZEN_OGTOTALSCORE_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DPane;

namespace zen {

/**
 * @brief TODO
 */
enum TotalScoreType {

};

/**
 * @brief TODO
 */
struct ogScrTotalScoreMgr {
	ogScrTotalScoreMgr(TotalScoreType*);

	void start();
	void update(Controller*);
	void draw(Graphics&);
	void setRankInEffect();
	void setRankInColor();

	// unused/inlined:
	void setEffect(P2DPane*, int);

	// TODO: members
};

} // namespace zen

#endif
