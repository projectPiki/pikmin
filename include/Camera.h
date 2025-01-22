#ifndef _CAMERA_H
#define _CAMERA_H

#include "types.h"
#include "Vector.h"
#include "Matrix4f.h"
#include "Plane.h"

struct Graphics;
struct Node;
struct Plane;
struct Texture;

/**
 * @brief TODO
 */
struct CullingPlane {
	CullingPlane() { }

	void CheckMinMaxDir();

	// TODO: members
	Plane mPlane; // _00
	int _10;      // _10
	int _14;      // _10
	int _18;      // _10
	int _1C;      // _10
	int _20;      // _10
	int _24;      // _24
	u8 _28;       // _28
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

	bool isPointVisible(Vector3f&, f32);
	void draw(Graphics&);
	void updateViewPlanes(f32, f32, f32, f32);
	void createViewPlanes();
	void update(f32, f32, f32, f32);
	void calcVectors(Vector3f&, Vector3f&);
	void calcLookAt(Vector3f&, Vector3f&, Vector3f*);

	// unused/inlined:
	void vectorToWorldPlane(Vector3f&, CullingPlane&);
	void additionalPlanes(CullFrustum*);
	void createVecs();
	void createInvVecs();
	void calcLookFrom(Vector3f&, Vector3f&);

	void projectVector(Vector3f& vec, Vector3f& projVec)
	{
		projVec.x = vec.dot(mViewXAxis);
		projVec.y = vec.dot(mViewYAxis);
		projVec.z = vec.dot(mViewZAxis);
	}

	void setBoundOffset(Vector3f* pos)
	{
		_154 = pos != nullptr;
		if (_154) {
			_158 = *pos;
		}
	}

	int _00;                     // _00
	int _04;                     // _04
	int mViewPlaneIdx;           // _08
	CullingPlane mCullPlanes[6]; // _0C
	Plane* mPlanePointers[6];    // _114, idk how many are in this
	u8 _12C[0x154 - 0x12C];      // _12C, unknown
	u8 _154;                     // _154
	u8 _155;                     // _155
	Vector3f _158;               // _158
	Vector3f mPosition;          // _164
	Vector3f mFocus;             // _170, aka Target Position
	Vector3f mViewXAxis;         // _17C
	Vector3f mViewYAxis;         // _188
	Vector3f mViewZAxis;         // _194
	Vector3f mInvXAxis;          // _1A0
	Vector3f mInvYAxis;          // _1AC
	Vector3f mInvZAxis;          // _1B8
	f32 mAspectRatio;            // _1C4
	f32 mVerticalScale;          // _1C8
	f32 mFov;                    // _1CC
	f32 mNear;                   // _1D0
	f32 mFar;                    // _1D4
	f32 mDepth;                  // _1D8
	f32 mWidth;                  // _1DC
	Matrix4f mLookAtMtx;         // _1E0
	Matrix4f mInverseLookAtMtx;  // _220
};

/**
 * @brief TODO
 *
 * @note Size: 0x348 (probably).
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
	f32 _344;                    // _344
};

/**
 * @brief TODO
 */
struct LightCamera : public Camera {
	void initLightmap(int, int);
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
	void update(f32, Matrix4f&);

	Vector3f _00;   // _00
	Vector3f _0C;   // _0C
	Vector3f _18;   // _18
	u32 _24;        // _24
	u32 _28;        // _28
	char _2C;       // _2C
	u32 _30[9];     // _30, sizeof 0x24
	u32 _54[21];    // _54, sizeof 0x54
	Camera mCamera; // _A8
	f32 _3F0;       // _3F0
	f32 _3F4;       // _3F4
};

#endif
