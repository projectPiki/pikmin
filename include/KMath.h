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

	void set(Vector3f&, Vector3f&, Vector3f&);

	Vector3f _00; // _00
	Vector3f _0C; // _0C
	Vector3f _18; // _18
};

/**
 * @brief TODO
 */
struct KRect {
	void inside(Vector3f&);

	// TODO: members
};

/**
 * @brief TODO
 */
struct KSegment {
	// unused/inlined:
	KSegment();

	// TODO: members
};

// Global utility functions:
bool isNan(f32);
void makePostureMatrix(Vector3f&, Vector3f&, Vector3f&, Matrix4f&);
void calcImpulse(Vector3f&, f32, Vector3f&, Matrix4f&, Vector3f&, Vector3f&);
void CRSpline(f32, Vector3f*);
void CRSplineTangent(f32, Vector3f*);
void getThrowVelocity(Vector3f&, f32, Vector3f&, Vector3f&);
void getCameraSafeAngle(Vector3f&, f32, f32);

#endif
