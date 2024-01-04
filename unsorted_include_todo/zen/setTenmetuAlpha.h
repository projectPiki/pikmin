#ifndef _ZEN_SETTENMETUALPHA_H
#define _ZEN_SETTENMETUALPHA_H

/*
 * @brief TODO
 */
namespace zen {
struct setTenmetuAlpha {
	setTenmetuAlpha(P2DPicture*, float, float, unsigned char, unsigned char);
	setTenmetuAlpha(P2DPicture*, float);
	void updateColor();
	void start();
	void startFadeIn(float, float, float);
	void startFadeOut(float, float, float);
	void update();
};
} // namespace zen

#endif
