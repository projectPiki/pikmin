#ifndef _CAMERA_H
#define _CAMERA_H

#include "Animator.h"
#include "Matrix4f.h"
#include "Plane.h"
#include "Vector.h"
#include "sysMath.h"
#include "types.h"

struct Graphics;
struct Node;
struct Plane;
struct Texture;
struct SceneData;

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct CullingPlane {
	CullingPlane() { }

	void CheckMinMaxDir();

	Plane mPlane;       // _00
	int mPVertexXIndex; // _10
	int mPVertexYIndex; // _10
	int mPVertexZIndex; // _10
	int mNVertexXIndex; // _10
	int mNVertexYIndex; // _10
	int mNVertexZIndex; // _24
	bool mIsEnabled;    // _28
};

/**
 * @brief TODO
 */
struct CullFrustum {
	CullFrustum()
	{
		_155 = 0;
		mPosition.set(0.0f, 0.0f, 0.0f);
		mFov  = 60.0f;
		mNear = 1.0f;
		mFar  = 1000.0f;
	}

	bool isPointVisible(immut Vector3f&, f32);
	void draw(Graphics&);
	void updateViewPlanes(f32, f32, f32, f32);
	void createViewPlanes();
	void update(f32, f32, f32, f32);
	void calcVectors(immut Vector3f&, immut Vector3f&);
	void calcLookAt(immut Vector3f&, immut Vector3f&, immut Vector3f*);

	// unused/inlined:
	void vectorToWorldPlane(immut Vector3f&, CullingPlane&);
	void additionalPlanes(CullFrustum*);
	void createVecs();
	void createInvVecs();
	void calcLookFrom(immut Vector3f&, immut Vector3f&);

	void projectVector(immut Vector3f& vec, Vector3f& projVec)
	{
		projVec.x = vec.dot(mViewXAxis);
		projVec.y = vec.dot(mViewYAxis);
		projVec.z = vec.dot(mViewZAxis);
	}

	void setBoundOffset(immut Vector3f* pos)
	{
		mHasBoundOffset = pos != nullptr;
		if (mHasBoundOffset) {
			mBoundOffset = *pos;
		}
	}

	int isBoundVisible(immut BoundBox& bound, int planeFlag)
	{
		immut f32* boundArray = (immut f32*)&bound;
		for (int i = 0; i < mActivePlaneCount; i++) {
			CullingPlane* plane = mPlanePointers[i];
			if (plane->mIsEnabled && (planeFlag & (1 << i))) {
				if (mHasBoundOffset) {
					if ((boundArray[plane->mNVertexXIndex] + mBoundOffset.x) * plane->mPlane.mNormal.x
					        + (boundArray[plane->mNVertexYIndex] + mBoundOffset.y) * plane->mPlane.mNormal.y
					        + (boundArray[plane->mNVertexZIndex] + mBoundOffset.z) * plane->mPlane.mNormal.z - plane->mPlane.mOffset
					    < 0.0f) {
						return 0;
					}

					if ((boundArray[plane->mPVertexXIndex] + mBoundOffset.x) * plane->mPlane.mNormal.x
					        + (boundArray[plane->mPVertexYIndex] + mBoundOffset.y) * plane->mPlane.mNormal.y
					        + (boundArray[plane->mPVertexZIndex] + mBoundOffset.z) * plane->mPlane.mNormal.z - plane->mPlane.mOffset
					    >= 0.0f) {
						planeFlag &= ~(1 << i);
					}
				} else {
					if ((boundArray[plane->mNVertexXIndex]) * plane->mPlane.mNormal.x
					        + (boundArray[plane->mNVertexYIndex]) * plane->mPlane.mNormal.y
					        + (boundArray[plane->mNVertexZIndex]) * plane->mPlane.mNormal.z - plane->mPlane.mOffset
					    < 0.0f) {
						return 0;
					}

					if ((boundArray[plane->mPVertexXIndex]) * plane->mPlane.mNormal.x
					        + (boundArray[plane->mPVertexYIndex]) * plane->mPlane.mNormal.y
					        + (boundArray[plane->mPVertexZIndex]) * plane->mPlane.mNormal.z - plane->mPlane.mOffset
					    >= 0.0f) {
						planeFlag &= ~(1 << i);
					}
				}
			}
		}
		return planeFlag;
	}

	int mTotalPlaneCount;            // _00
	int mActivePlaneCount;           // _04
	int mViewPlaneIdx;               // _08
	CullingPlane mCullPlanes[6];     // _0C
	CullingPlane* mPlanePointers[6]; // _114, idk how many are in this
	u8 _12C[0x154 - 0x12C];          // _12C, unknown
	u8 mHasBoundOffset;              // _154
	u8 _155;                         // _155
	Vector3f mBoundOffset;           // _158
	Vector3f mPosition;              // _164
	Vector3f mFocus;                 // _170, aka Target Position
	Vector3f mViewXAxis;             // _17C
	Vector3f mViewYAxis;             // _188
	Vector3f mViewZAxis;             // _194
	Vector3f mInvXAxis;              // _1A0
	Vector3f mInvYAxis;              // _1AC
	Vector3f mInvZAxis;              // _1B8
	f32 mAspectRatio;                // _1C4
	f32 mVerticalScale;              // _1C8
	f32 mFov;                        // _1CC
	f32 mNear;                       // _1D0
	f32 mFar;                        // _1D4
	f32 mDepth;                      // _1D8
	f32 mWidth;                      // _1DC
	Matrix4f mLookAtMtx;             // _1E0
	Matrix4f mInverseLookAtMtx;      // _220
};

/**
 * @brief TODO
 *
 * @note Size: 0x348.
 */
struct Camera : public CullFrustum {
	Camera();

	f32 projectWorldPoint(Graphics&, Vector3f&);

	// unused/inlined:
	void camReflect(Camera&, Plane&);
	f32 projectCamPoint(Vector3f&);

	// _00-_260 = CullFrustum
	Matrix4f mPerspectiveMatrix; // _260, used for perspective projection
	Matrix4f mProjectionMatrix;  // _2A0
	Matrix4f _2E0;               // _2E0
	Vector3f mRotation;          // _320
	Vector3f _32C;               // _32C
	Vector3f _338;               // _338
	f32 mBlurAlpha;              // _344
};

/**
 * @brief TODO
 */
struct LightCamera : public Camera {
	LightCamera() { mLightMap = nullptr; }

	void initLightmap(int size, int texFmt);
	void calcProjection(Graphics&, bool, Node*);

	// _00-_348 = Camera
	f32 mProjectionX;          // _348
	f32 mProjectionY;          // _34C
	f32 mFrustumSize;          // _350
	f32 mFrustumRange;         // _354
	Texture* mLightMap;        // _358
	Vector3f mProjectionScale; // _35C
};

/**
 * @brief TODO
 * @note Size: 0x3F8.
 */
struct CamDataInfo {
	CamDataInfo();

	void update(f32, immut Matrix4f&);

	Vector3f mCameraPosition;    // _00
	Vector3f mCameraLookAt;      // _0C
	Vector3f mStaticLookAt;      // _18
	f32 mTargetFov;              // _24
	f32 mBlendRatio;             // _28
	u8 mUseStaticCamera;         // _2C
	AnimParam mCamPosAnims[3];   // _30
	AnimParam mCamLatAnims[3];   // _54
	AnimParam mCamTwistAnims[1]; // _78
	AnimParam mCamFovyAnims[1];  // _84
	AnimParam mCamNearAnims[1];  // _90
	AnimParam mCamFarAnims[1];   // _9C
	Camera mCamera;              // _A8
	int mCameraIdx;              // _3F0
	SceneData* mSceneData;       // _3F4
};

#endif
