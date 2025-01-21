#ifndef _NLIB_GRAPHICS_H
#define _NLIB_GRAPHICS_H

#include "types.h"
#include "nlib/Geometry.h"

struct Camera;

/**
 * @brief TODO
 *
 * @note Size: 0x20?
 */
struct NCamera {
	NCamera(Camera*);

	void makeMatrix();
	void makeCamera();

	NVector3f& getViewpoint() { return mViewpoint; }
	void inputWatchpoint(Vector3f&);

	NVector3f& getWatchpoint() { return mWatchpoint; }
	void inputViewpoint(Vector3f&);

	f32 getAspect();
	void setAspect(f32);

	f32 getFov();
	void setFov(f32);

	void outputPosture(NPosture3D&);
	void inputPosture(NPosture3D&);

	f32 mRotationAngle;    // _00
	Camera* mCamera;       // _04
	NVector3f mViewpoint;  // _08, a.k.a. position - point we're viewing *from*
	NVector3f mWatchpoint; // _14, a.k.a. target position - point we're *watching*
};

#endif
