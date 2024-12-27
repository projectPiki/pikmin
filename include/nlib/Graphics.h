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

	f32 mRotationAngle;        // _00
	Camera* mCamera;           // _04
	NVector3f mPosition;       // _08
	NVector3f mTargetPosition; // _14
};

#endif
