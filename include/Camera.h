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
		mEyePosition.set(0.0f, 0.0f, 0.0f);
		_1CC = 60.0f;
		_1D0 = 1.0f;
		_1D4 = 1000.0f;
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

	int _00;                     // _00
	int _04;                     // _04
	int _08;                     // _08
	CullingPlane mCullPlanes[6]; // _0C
	Plane* _114[6];              // _114, idk how many are in this
	u8 _12C[0x154 - 0x12C];      // _12C, unknown
	u8 _154;                     // _154
	u8 _155;                     // _155
	Vector3f _158;               // _158
	Vector3f mEyePosition;       // _164
	Vector3f mTargetPosition;    // _170
	Vector3f mViewXAxis;         // _17C
	Vector3f mViewYAxis;         // _188
	Vector3f mViewZAxis;         // _194
	Vector3f mInvXAxis;          // _1A0
	Vector3f mInvYAxis;          // _1AC
	Vector3f mInvZAxis;          // _1B8
	f32 _1C4;                    // _1C4
	f32 _1C8;                    // _1C8
	f32 _1CC;                    // _1CC
	f32 _1D0;                    // _1D0
	f32 _1D4;                    // _1D4
	f32 _1D8;                    // _1D8
	f32 _1DC;                    // _1DC
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
	void projectCamPoint(Vector3f&);

	// _00-_260 = CullFrustum
	Matrix4f _260;      // _260
	Matrix4f _2A0;      // _2A0
	Matrix4f _2E0;      // _2E0
	Vector3f mRotation; // _320
	Vector3f _32C;      // _32C
	Vector3f _338;      // _338
	f32 _344;           // _344
};

/**
 * @brief TODO
 */
struct LightCamera : public Camera {
	void initLightmap(int, int);
	void calcProjection(Graphics&, bool, Node*);

	// _00-_348 = Camera
	f32 _348;           // _348
	f32 _34C;           // _34C
	f32 _350;           // _350
	f32 _354;           // _354
	Texture* mLightMap; // _358
	Vector3f _35C;      // _35C
};

/**
 * @brief TODO
 */
struct CamDataInfo {
	void update(f32, Matrix4f&);
};

#endif
