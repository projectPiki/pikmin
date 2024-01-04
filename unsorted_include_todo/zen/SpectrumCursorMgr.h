#ifndef _ZEN_SPECTRUMCURSORMGR_H
#define _ZEN_SPECTRUMCURSORMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct SpectrumCursorMgr {
	void update();
	void move(float, float, float);
	void scale(float, float);
	void init(P2DScreen*, P2DPane*, unsigned long, float, float);
	void initPos(float, float);
	void initScale(float);
	void makeTag(unsigned long, int);
};
} // namespace zen

#endif
