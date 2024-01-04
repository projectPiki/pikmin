#ifndef _ZEN_OGSCRTOTALSCOREMGR_H
#define _ZEN_OGSCRTOTALSCOREMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogScrTotalScoreMgr {
	ogScrTotalScoreMgr(zen::TotalScoreType*);
	void start();
	void update(Controller*);
	void draw(Graphics&);
	void setRankInEffect();
	void setRankInColor();
};
} // namespace zen

#endif
