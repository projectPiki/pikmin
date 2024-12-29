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
struct TotalScoreType { };

/**
 * @brief TODO
 *
 * @note Size: 0x830.
 */
struct ogScrTotalScoreMgr {
	ogScrTotalScoreMgr(TotalScoreType*);

	void start();
	int update(Controller*);
	void draw(Graphics&);
	void setRankInEffect();
	void setRankInColor();

	// unused/inlined:
	void setEffect(P2DPane*, int);

	u8 _00[0x830]; // _00, unknown
};

} // namespace zen

#endif
