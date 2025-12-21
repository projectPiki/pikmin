#ifndef _KMATH_H
#define _KMATH_H

#include "Vector.h"
#include "types.h"

struct Matrix4f;

/**
 * @brief TODO
 */
struct KTri {
	KTri();

	void set(immut Vector3f& pointA, immut Vector3f& pointB, immut Vector3f& pointC);

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
	bool inside(immut Vector3f& point);

	KTri mBotTri; // _00, bottom left point, left side, bottom side
};

/**
 * @brief TODO
 */
struct KSegment {
	// unused/inlined:
	KSegment();

	Vector3f& Origin() { return mPoint; }
	Vector3f& Direction() { return mDirection; }

	Vector3f mPoint;     // _00, a.k.a. origin
	Vector3f mDirection; // _0C
};

// Global utility functions:
bool isNan(f32 x);
void makePostureMatrix(immut Vector3f& col0, immut Vector3f& col1, immut Vector3f& col2, Matrix4f& outMtx);
f32 calcImpulse(immut Vector3f& relativePos, f32 mass, immut Vector3f& collisionNormal, immut Matrix4f& inertiaTensor,
                immut Vector3f& relativeVel, immut Vector3f& separationVel);
Vector3f CRSpline(f32 t, immut Vector3f* ctrlPts);
Vector3f CRSplineTangent(f32 t, immut Vector3f* ctrlPts);
Vector3f getThrowVelocity(immut Vector3f& startPos, f32 horizSpeed, immut Vector3f& targetPos, Vector3f NRef targetDir);
f32 getCameraSafeAngle(immut Vector3f& cameraPos, f32 checkDistance, f32 heightWeighting);

#endif
