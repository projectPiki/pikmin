#ifndef _NLIB_GRAPHICS_H
#define _NLIB_GRAPHICS_H

#include "Camera.h"
#include "nlib/Geometry.h"
#include "types.h"

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
	void inputViewpoint(immut Vector3f& viewPt) { mViewpoint.input(viewPt); }

	NVector3f& getWatchpoint() { return mWatchpoint; }
	void inputWatchpoint(immut Vector3f& watchPt) { mWatchpoint.input(watchPt); }

	f32 getAspect() immut { return mCamera->mAspectRatio; }
	void setAspect(f32 aspect) { mCamera->mAspectRatio = aspect; }

	f32 getFov() immut { return mCamera->mFov; }
	void setFov(f32 fov) { mCamera->mFov = fov; }

	void outputPosture(NPosture3D& outPosture) immut
	{
		outPosture.inputViewpoint(mViewpoint);
		outPosture.inputWatchpoint(mWatchpoint);
	}
	void inputPosture(immut NPosture3D& posture)
	{
		inputViewpoint(posture.getViewpoint());
		inputWatchpoint(posture.getWatchpoint());
	}

	// FABRICATED, but necessary for opt-in const-correctness...
	const NVector3f& getViewpoint() const { return mViewpoint; }
	const NVector3f& getWatchpoint() const { return mWatchpoint; }

	f32 mRotationAngle;    // _00
	Camera* mCamera;       // _04
	NVector3f mViewpoint;  // _08, a.k.a. position - point we're viewing *from*
	NVector3f mWatchpoint; // _14, a.k.a. target position - point we're *watching*
};

#endif
