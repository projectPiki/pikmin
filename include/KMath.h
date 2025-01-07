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
bool isNan(f32);
void makePostureMatrix(Vector3f&, Vector3f&, Vector3f&, Matrix4f&);
f32 calcImpulse(Vector3f&, f32, Vector3f&, Matrix4f&, Vector3f&, Vector3f&);
Vector3f CRSpline(f32, Vector3f*);
Vector3f CRSplineTangent(f32, Vector3f*);
Vector3f getThrowVelocity(Vector3f&, f32, Vector3f&, Vector3f&);
void getCameraSafeAngle(Vector3f&, f32, f32);

#endif
