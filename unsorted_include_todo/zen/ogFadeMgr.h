#ifndef _ZEN_OGFADEMGR_H
#define _ZEN_OGFADEMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogFadeMgr {
	ogFadeMgr(P2DPane*, unsigned char);
	void start(zen::ogFadeMgr::ogFadeStatusFlag, float);
	void setAlpha();
	void update();
};
} // namespace zen

#endif
