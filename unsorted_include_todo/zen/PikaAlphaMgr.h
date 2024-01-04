#ifndef _ZEN_PIKAALPHAMGR_H
#define _ZEN_PIKAALPHAMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct PikaAlphaMgr {
	PikaAlphaMgr(P2DScreen*);
	void start();
	void startFadeIn(float);
	void startFadeOut(float);
	void update();
};
} // namespace zen

#endif
