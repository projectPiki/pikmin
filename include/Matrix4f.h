#ifndef _MATRIX4F_H
#define _MATRIX4F_H

#include "types.h"
#include "Dolphin/mtx.h"
#include "Vector.h"
#include "SRT.h"

/**
 * @brief 4x4 Matrix.
 *
 * @note Size: 0x40.
 * @note Is sometimes casted to Vector3f*, (Vector3f&), be weary of this.
 */
struct Matrix4f {
	Matrix4f() { }
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
	void makeLookat(Vector3f& cameraPos, Vector3f& targetPos, Vector3f* optionalUp);
	void makeLookat(Vector3f& cameraPos, Vector3f& rightDir, Vector3f& upDir, Vector3f& backDir);
	void transposeTo(Matrix4f&);
	void makeVQS(Vector3f&, struct Quat&, Vector3f&);

	// unused/inlined:
	void blend(Matrix4f&, f32);
	void makeOrtho(f32, f32, f32, f32, f32, f32, f32);
	void makePerspective(f32 fovY, f32 aspectRatio, f32 nearZ, f32 farZ);
	void makeBallRotate(Vector3f&);
	void rotate(Vector3f&, f32);
	void rotate(Vector3f&);
	void rotate(f32, f32, f32);
	void makeAligned(Vector3f&, f32);
	void rotateX(f32);
	void rotateY(f32);
	void rotateZ(f32);
	void translate(f32, f32, f32);
	void makeLookfrom(Vector3f&, Vector3f&);
	void makeProjection(Vector3f&, struct Plane&);
	void makeReflection(Plane&);
	void makeBillVector(Vector3f&, Matrix4f&, Vector3f&);

	// should be without the _ but compiler complains about the vector one
	void makeSRT_(SRT srt) { makeSRT(srt.mScale, srt.mRotation, srt.mTranslation); }

	inline void set(Matrix4f& other)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mMtx[i][j] = other.mMtx[i][j];
			}
		}
	}

	inline void set(f32 value)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mMtx[i][j] = value;
			}
		}
	}

	void getRow(int rowNum, Vector3f& row) { row.set(mMtx[rowNum][0], mMtx[rowNum][1], mMtx[rowNum][2]); }

	void getColumn(int colNum, Vector3f& col)
	{
		col.x = mMtx[0][colNum];
		col.y = mMtx[1][colNum];
		col.z = mMtx[2][colNum];
	}

	void setRow(int rowNum, const Vector3f& row)
	{
		mMtx[rowNum][0] = row.x;
		mMtx[rowNum][1] = row.y;
		mMtx[rowNum][2] = row.z;
	}

	void setColumn(int colNum, const Vector3f& col)
	{
		mMtx[0][colNum] = col.x;
		mMtx[1][colNum] = col.y;
		mMtx[2][colNum] = col.z;
	}

	void setTranslation(Vector3f& trans)
	{
		mMtx[0][3] = trans.x;
		mMtx[1][3] = trans.y;
		mMtx[2][3] = trans.z;
	}

	void setTranslation(f32 x, f32 y, f32 z)
	{
		mMtx[0][3] = x;
		mMtx[1][3] = y;
		mMtx[2][3] = z;
	}

	static Matrix4f ident;

	Mtx44 mMtx; // _00-_40
};

// this is a weird place to put these, but they get initialised in matMath.cpp, so?
extern f32 sintable[0x1000];
extern f32 costable[0x1000];

#endif
