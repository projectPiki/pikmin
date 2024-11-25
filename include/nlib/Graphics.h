#ifndef _NLIB_GRAPHICS_H
#define _NLIB_GRAPHICS_H

#include "types.h"
#include "nlib/Geometry.h"

struct Camera;

/**
 * @brief TODO
 */
struct NCamera {
	NCamera(Camera*);

	void makeMatrix();
	void makeCamera();

	f32 _00;         // _00
	Camera* mCamera; // _04
	NVector3f _08;   // _08
	NVector3f _14;   // _14
};

#endif
