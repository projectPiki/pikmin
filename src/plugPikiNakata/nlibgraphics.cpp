#include "Camera.h"
#include "DebugLog.h"
#include "nlib/Graphics.h"
#include "nlib/Math.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT(nullptr);

NCamera::NCamera(Camera* cam)
{
	mCamera = cam;
	mViewpoint.set(0.0f, 0.0f, 0.0f);
	mWatchpoint.set(0.0f, 0.0f, 1.0f);
	mRotationAngle = 0.0f;
}

void NCamera::makeMatrix()
{
	NVector3f direction(getViewpoint(), getWatchpoint());
	direction.normalize();

	NOrientation orient(direction);
	orient.normalize();

	NVector3f upVector(orient.getUp());

	NAxisAngle4f angle(direction, mRotationAngle);
	NTransform3D transform;
	transform.inputAxisAngle(angle);
	transform.transform(upVector);
	upVector.normalize();
	mCamera->calcLookAt(mViewpoint, mWatchpoint, &upVector);
}

void NCamera::makeCamera()
{
	mViewpoint.output(mCamera->mPosition);
	NVector3f directionVec(mWatchpoint, mViewpoint);

	// Calculate the rotation of the camera based on the direction
	NPolar3f polar(directionVec);
	mCamera->mRotation.x = polar.mInclination - NMathF::pi / 2.0f;
	mCamera->mRotation.y = polar.mAzimuth;
	mCamera->mRotation.z = 0.0f;
}
