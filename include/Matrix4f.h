#ifndef _MATRIX4F_H
#define _MATRIX4F_H

#include "types.h"
#include "Dolphin/mtx.h"

/**
 * @brief 4x4 Matrix.
 *
 * @note Size: 0x40.
 */
struct Matrix4f {
	Matrix4f() { }   // probably
	Matrix4f(Mtx44); // stripped, only in matMath.cpp

	void makeIdentity();
	void makeRotate(struct Vector3f&, f32, f32);
	void makeRotate(Vector3f&, f32);
	void multiply(Matrix4f&);
	void multiplyTo(Matrix4f&, Matrix4f&);
	void makeSRT(Vector3f&, Vector3f&, Vector3f&);
	void makeConcatSRT(Matrix4f*, Matrix4f&, struct SRT&);
	void inverse(Matrix4f*);
	void scale(Vector3f&);
	void makeLookat(Vector3f&, Vector3f&, Vector3f*);
	void makeLookat(Vector3f&, Vector3f&, Vector3f&, Vector3f&);
	void transposeTo(Matrix4f&);
	void makeVQS(Vector3f&, struct Quat&, Vector3f&);

	// unused/inlined:
	void blend(Matrix4f&, f32);
	void makeOrtho(f32, f32, f32, f32, f32, f32, f32);
	void makePerspective(f32, f32, f32, f32);
	void makeBallRotate(Vector3f&);
	void rotate(Vector3f&, f32);
	void rotate(f32, f32, f32);
	void makeAligned(Vector3f&, f32);
	void rotateX(f32);
	void rotateY(f32);
	void rotateZ(f32);
	void translate(f32, f32, f32);
	void makeLookfrom(Vector3f&, Vector3f&);
	void makeProjection(Vector3f&, struct Plane&);
	void makeReflection(Plane&);

	inline void set(Matrix4f& other)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mMtx[i][j] = other.mMtx[i][j];
			}
		}
	}

	static Matrix4f ident;

	Mtx44 mMtx; // _00-_40
};

#endif
