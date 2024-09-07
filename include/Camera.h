#ifndef _CAMERA_H
#define _CAMERA_H

#include "types.h"
#include "Vector.h"

struct Graphics;
struct Node;
struct Plane;

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

	void isPointVisible(Vector3f&, f32);
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

	// TODO: members
};

/**
 * @brief TODO
 */
struct Camera {
	Camera();

	void projectWorldPoint(Graphics&, Vector3f&);

	// unused/inlined:
	void camReflect(Camera&, Plane&);
	void projectCamPoint(Vector3f&);

	u8 _00[0xC];                 // _00, unknown
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
	u8 _1D8[0x320 - 0x1D8];      // _1D8, unknown
	f32 _320;                    // _320
	f32 _324;                    // _324
	f32 _328;                    // _328
	f32 _32C;                    // _32C
	f32 _330;                    // _330
	f32 _334;                    // _334
	f32 _338;                    // _338
	f32 _33C;                    // _33C
	f32 _340;                    // _340
};

/**
 * @brief TODO
 */
struct LightCamera {
	void initLightmap(int, int);
	void calcProjection(Graphics&, bool, Node*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct CamDataInfo {
	void update(f32, Matrix4f&);
};

#endif
