#ifndef _MATRIX3F_H
#define _MATRIX3F_H

#include "Dolphin/mtx.h"
#include "Vector.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct Matrix3f {
	enum mode {
		MODE_Unk0 = 0,
	};
	enum do_not_initialize { };

	Matrix3f() { identity(); }

	Matrix3f(const Mtx33 mtx)
	{
		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++)
				(*this)(row, col) = mtx[row][col];
		}
	};

	Matrix3f(mode)
	{
		for (int row = 0; row < 3; row++) {
			mMtx[row][0] = 0.0f;
			mMtx[row][1] = 0.0f;
			mMtx[row][2] = 0.0f;
		}
	}

	Matrix3f(const Vector3f& vec, mode)
	{
		(*this)(0, 0) = 0.0f;
		(*this)(0, 1) = -vec.z;
		(*this)(0, 2) = vec.y;
		(*this)(1, 0) = vec.z;
		(*this)(1, 1) = 0.0f;
		(*this)(1, 2) = -vec.x;
		(*this)(2, 0) = -vec.y;
		(*this)(2, 1) = vec.x;
		(*this)(2, 2) = 0.0f;
	}

protected:
	Matrix3f(do_not_initialize) { }

public:
	void identity()
	{
		for (int i = 0; i < 9; i++) {
			mMtx[0][i] = 0.0f; // sure.
		}

		mMtx[0][0] = mMtx[1][1] = mMtx[2][2] = 1.0f;
	}

	f32& operator()(int row, int col) { return mMtx[row][col]; }
	const f32& operator()(int row, int col) const { return mMtx[row][col]; }
	f32 GetElement(int row, int col) const { return mMtx[row][col]; }
	Matrix3f& SetElement(int row, int col, f32 val)
	{
		mMtx[row][col] = val;
		return *this;
	}

	Mtx33 mMtx; // _00
};

// DLL inlines:
inline Matrix3f operator*(f32 scale, const Matrix3f& inMtx)
{
	Matrix3f outMtx;
	for (int i = 0; i < 3; i++) {
		outMtx(0, i) = scale * inMtx(0, i);
		outMtx(1, i) = scale * inMtx(1, i);
		outMtx(2, i) = scale * inMtx(2, i);
	}
	return outMtx;
}
inline Matrix3f operator*(const Matrix3f& mtxA, const Matrix3f& mtxB)
{
	Matrix3f outMtx;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			f32 elem = 0.0f;
			for (int k = 0; k < 3; k++) {
				elem += mtxA.GetElement(i, k) * mtxB.GetElement(k, j);
			}
			outMtx.SetElement(i, j, elem);
		}
	}
	return outMtx;
}
inline Matrix3f operator+(const Matrix3f& mtxA, const Matrix3f& mtxB)
{
	Matrix3f outMtx;
	for (int i = 0; i < 3; i++) {
		outMtx(0, i) = mtxA(0, i) + mtxB(0, i);
		outMtx(1, i) = mtxA(1, i) + mtxB(1, i);
		outMtx(2, i) = mtxA(2, i) + mtxB(2, i);
	}
	return outMtx;
}
inline Vector3f operator*(const Matrix3f& mtx, const Vector3f& inVec)
{
	Vector3f outVec;
	outVec.x = mtx.GetElement(0, 0) * inVec.x + mtx.GetElement(0, 1) * inVec.y + mtx.GetElement(0, 2) * inVec.z;
	outVec.y = mtx.GetElement(1, 0) * inVec.x + mtx.GetElement(1, 1) * inVec.y + mtx.GetElement(1, 2) * inVec.z;
	outVec.z = mtx.GetElement(2, 0) * inVec.x + mtx.GetElement(2, 1) * inVec.y + mtx.GetElement(2, 2) * inVec.z;
	return outVec;
}
inline Matrix3f Transpose(const Matrix3f& inMtx)
{
	Matrix3f outMtx;
	for (int i = 0; i < 3; i++) {
		outMtx(0, i) = inMtx(i, 0);
		outMtx(1, i) = inMtx(i, 1);
		outMtx(2, i) = inMtx(i, 2);
	}
	return outMtx;
}
inline void OrthonormaliseOrientation(Matrix3f& mtx)
{
	Vector3f vec1(mtx(0, 0), mtx(1, 0), mtx(2, 0));
	Vector3f vec2(mtx(0, 1), mtx(1, 1), mtx(2, 1));
	Vector3f vec3;
	vec1.normalise();
	vec3 = CP(vec1, vec2);
	vec3.normalise();
	vec2 = CP(vec3, vec1);
	vec2.normalise();

	mtx(0, 0) = vec1.x;
	mtx(0, 1) = vec2.x;
	mtx(0, 2) = vec3.x;
	mtx(1, 0) = vec1.y;
	mtx(1, 1) = vec2.y;
	mtx(1, 2) = vec3.y;
	mtx(2, 0) = vec1.z;
	mtx(2, 1) = vec2.z;
	mtx(2, 2) = vec3.z;
}

#endif
