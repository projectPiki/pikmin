#ifndef _LIGHTCAMERA_H
#define _LIGHTCAMERA_H

/*
 * @brief TODO
 */
struct LightCamera {
	void initLightmap(int, int);
	void calcProjection(Graphics&, bool, Node*);
};

#endif
