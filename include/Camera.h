#ifndef _CAMERA_H
#define _CAMERA_H

#include "types.h"
#include "Vector.h"
#include "Matrix4f.h"

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
	Vector3f _00; // _00
	u8 _0C[0x20]; // _0C, unknown
};

/**
 * @brief TODO
 */
struct CullFrustum {
	CullFrustum()
	{
		_155 = 0;
		_164.set(0.0f, 0.0f, 0.0f);
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

	u8 _00[0x4];                 // _00, unknown
	int _04;                     // _04
	u8 _08[0x4];                 // _08, unknown
	CullingPlane mCullPlanes[6]; // _0C
	u8 _114[0x154 - 0x114];      // _114, unknown
	u8 _154;                     // _154
	u8 _155;                     // _155
	Vector3f _158;               // _158
	Vector3f _164;               // _164
	Vector3f _170;               // _170
	Vector3f _17C;               // _17C
	Vector3f _188;               // _188
	Vector3f _194;               // _194
	Vector3f _1A0;               // _1A0
	Vector3f _1AC;               // _1AC
	Vector3f _1B8;               // _1B8
	f32 _1C4;                    // _1C4
	u8 _1C8[0x4];                // _1C8, unknown
	f32 _1CC;                    // _1CC
	f32 _1D0;                    // _1D0
	f32 _1D4;                    // _1D4
	u8 _1D8[0x8];                // _1D8, unknown
	Matrix4f _1E0;               // _1E0
	Matrix4f _220;               // _220
};

/**
 * @brief TODO
 *
 * @note Between 0x348 and 0x350 in size.
 */
struct Camera : public CullFrustum {
	Camera();

	void projectWorldPoint(Graphics&, Vector3f&);

	// unused/inlined:
	void camReflect(Camera&, Plane&);
	void projectCamPoint(Vector3f&);

	// _00-_1D8 = CullFrustum? Unsure on end point of that vs beginning of this, but after _260 and before _320
	u8 _260[0x2A0 - 0x260]; // _260, unknown
	Matrix4f _2A0;          // _2A0
	u8 _2E0[0x320 - 0x2E0]; // _2E0, unknown
	Vector3f _320;          // _320
	Vector3f _32C;          // _32C
	Vector3f _338;          // _338
	f32 _344;               // _344
};

/**
 * @brief TODO
 */
struct LightCamera : public Camera {
	void initLightmap(int, int);
	void calcProjection(Graphics&, bool, Node*);

	// _00-_348 = Camera? Fix when size of camera is known
	u8 _348[0x10];      // _348, unknown
	Texture* mLightMap; // _358
};

/**
 * @brief TODO
 */
struct CamDataInfo {
	void update(f32, Matrix4f&);
};

#endif
