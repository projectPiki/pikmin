#ifndef _KMATH_H
#define _KMATH_H

#include "types.h"
#include "Vector.h"

struct Matrix4f;

/**
 * @brief TODO
 */
struct KTri {
	KTri();

	void set(Vector3f& pointA, Vector3f& pointB, Vector3f& pointC);

	inline Vector3f& Origin() { return mVertA; }
	inline Vector3f& Edge0() { return mSideAB; }
	inline Vector3f& Edge1() { return mSideAC; }

	// set clockwise
	Vector3f mVertA;  // _00, vertex
	Vector3f mSideAB; // _0C, line from vertex A to vertex B
	Vector3f mSideAC; // _18, line from vertex A to vertex C
};

/**
 * @brief TODO
 */
struct KRect {
	bool inside(Vector3f& point);

	KTri mBotTri; // _00, bottom left point, left side, bottom side
};

/**
 * @brief TODO
 */
struct KSegment {
	// unused/inlined:
	KSegment();

	Vector3f mPoint;     // _00
	Vector3f mDirection; // _0C
};

// Global utility functions:
bool isNan(f32 x);
void makePostureMatrix(Vector3f& col0, Vector3f& col1, Vector3f& col2, Matrix4f& outMtx);
f32 calcImpulse(Vector3f& relativePos, f32 mass, Vector3f& collisionNormal, Matrix4f& inertiaTensor, Vector3f& relativeVel,
                Vector3f& separationVel);
Vector3f CRSpline(f32 t, Vector3f* ctrlPts);
Vector3f CRSplineTangent(f32 t, Vector3f* ctrlPts);
Vector3f getThrowVelocity(Vector3f& startPos, f32 horizSpeed, Vector3f& targetPos, Vector3f& targetDir);
f32 getCameraSafeAngle(Vector3f& cameraPos, f32 checkDistance, f32 heightWeighting);

#endif
