#ifndef _NLIB_GEOMETRY_H
#define _NLIB_GEOMETRY_H

#include "Dolphin/mtx.h"
#include "nlib/Math.h"
#include "Matrix4f.h"
#include "Vector.h"
#include "types.h"

struct Stream;
struct NTransform3D;

/**
 * @brief TODO
 */
struct NVector {
	NVector();
	NVector(f32*, int); // unused/inlined

	void construct(f32*, int);
	void makeZero();

	// unused/inlined:
	void add(NVector&);
	void dot(NVector&);
	void input(NVector&);
	void println();

	inline int getSize() { return mSize; }

	f32* mValues; // _00, array of size mSize
	int mSize;    // _04
};

/**
 * @brief TODO
 */
struct NVector3f : public Vector3f {
	NVector3f();
	NVector3f(Vector3f&);
	NVector3f(f32, f32, f32);
	NVector3f(Vector3f&, Vector3f&);

	void construct(Vector3f&);
	void construct(f32, f32, f32);
	void construct(Vector3f&, Vector3f&);
	bool isParallel(Vector3f&);
	void println();
	bool normalizeCheck();
	void normalize();

	// unused/inlined:
	void printVector3f(Vector3f&);
	void printlnVector3f(Vector3f&);
	void interpolate(Vector3f&, Vector3f&, f32);
	bool isZero();
	void equals(Vector3f&);
	void isVertical(Vector3f&);
	void makeUnitVector(Vector3f&, Vector3f&);
	void outputQuat(f32, Quat&);
	void calcAngle(NVector3f&);
	void calcLargerAngle(NVector3f&);
	void print();
	void normalizeByLength(f32);

	inline void setNVec(NVector3f& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}

	// _00-_0C = Vector3f
};

/**
 * @brief TODO
 */
struct NVector3fIO {
	virtual void input(NVector3f&)  = 0; // _08
	virtual void output(NVector3f&) = 0; // _0C

	// _00 = VTBL
};

/**
 * @brief TODO
 */
struct NVector3fIOClass : public NVector3fIO {
	virtual void input(NVector3f&);  // _08
	virtual void output(NVector3f&); // _0C

	// _00 = VTBL
	// _00-_04 = NVector3fIO
	NVector3f _04; // _04, maybe in NVector3fIO, no idea.
};

/**
 * @brief TODO
 */
struct NMatrix4f : public Matrix4f {
	NMatrix4f();
	NMatrix4f(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	NMatrix4f(Matrix4f&); // unused/inlined
	NMatrix4f(Mtx);       // unused/inlined

	void construct(Matrix4f&);
	void input(Matrix4f&);
	void set(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	void outputCol(int, Vector3f&);
	void makeIdentRow(int);

	// unused/inlined:
	void construct(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	void construct(Mtx);
	void input(Mtx);
	void output(Mtx);
	void setRow(int, f32, f32, f32);
	void inputRow(int, Vector3f&);
	void inputRow(int, Vector3f&, f32);
	void outputRow(int, Vector3f&);
	void inputRows(NVector3f&, NVector3f&, NVector3f&);
	void setCol(int, f32, f32, f32);
	void inputCol(int, Vector3f&);
	void inputCol(int, Vector3f&, f32);
	void inputCols(NVector3f&, NVector3f&, NVector3f&);
	void mul(Matrix4f&);
	void mul2(Matrix4f&, Matrix4f&);
	void scale(f32);
	void transpose();
	void println();

	// _00-_30 = Matrix4f
};

/**
 * @brief TODO
 */
struct NSpecialMatrix {
	NSpecialMatrix(int); // unused/inlined

	virtual void setDimension(int); // _08

	// unused/inlined:
	void construct(int);

	// _00 = VTBL
	int mDimension; // _04
};

/**
 * @brief TODO
 */
struct NUpperMatrix : public NSpecialMatrix {
	NUpperMatrix(f32*, f32*, int); // unused/inlined

	// unused/inlined:
	void construct(f32*, f32*, int);
	void solve(NVector&, NVector&);
	void println();

	// TODO: members
};

/**
 * @brief TODO
 */
struct NLowerMatrix : public NSpecialMatrix {
	NLowerMatrix(f32*, int);

	// unused/inlined:
	void construct(f32*, int);
	void solve(NVector&, NVector&);
	void println();

	// TODO: members
};

/**
 * @brief TODO
 */
struct LUMatrix : public NSpecialMatrix {
	LUMatrix(f32*, f32*, f32*, int); // unused/inlined

	virtual void setDimension(int); // _08

	// unused/inlined:
	void construct(f32*, f32*, f32*, int);
	void solve(NVector&, NVector&);
	void decompose();
	void println();

	// _00 = VTBL
	// _00-_08 = NSpecialMatrix
	NSpecialMatrix _08; // _08, maybe NLowerMatrix?
	u8 _10[0x4];        // _10, unknown
	NSpecialMatrix _14; // _14, maybe NUpperMatrix?
};

/**
 * @brief TODO
 */
struct NOrientation {
	NOrientation(Vector3f&);
	NOrientation();                     // unused/inlined
	NOrientation(Vector3f&, Vector3f&); // unused/inlined

	void construct(Vector3f&);
	void normalize();
	void outputLeft(NVector3f&);
	void makeUp();

	// unused/inlined:
	void construct(Vector3f&, Vector3f&);
	void transform(NTransform3D&);
	void outputRight(NVector3f&);
	void outputTransform(NTransform3D&);
	void inputTransform(NTransform3D&);
	void outputRotation(NTransform3D&);
	void inputRotation(NTransform3D&);
	void println();

	NVector3f mDirection; // _00
	NVector3f mUpVector;  // _0C
};

/**
 * @brief TODO
 */
struct NPolar3f {
	NPolar3f();
	NPolar3f(Vector3f&);
	NPolar3f(f32, f32, f32); // unused/inlined
	NPolar3f(NPolar3f&);     // unused/inlined

	void construct(Vector3f&);
	void set(f32, f32, f32);
	void input(Vector3f&);
	void output(Vector3f&);

	// unused/inlined:
	void construct(f32, f32, f32);
	void construct(NPolar3f&);
	void input(NPolar3f&);
	void negate();
	void interpolate(NPolar3f&, NPolar3f&, f32);
	void roundMeridian();
	void clampMeridian(f32);
	void println();

	f32 mRadius;      // _00
	f32 mInclination; // _04
	f32 mAzimuth;     // _08
};

/**
 * @brief TODO
 */
struct NAxisAngle4f {
	NAxisAngle4f(); // unused/inlined
	NAxisAngle4f(NVector3f&, f32);

	void construct(NVector3f&, f32);

	NVector3f mAxis; // _00
	f32 mAngle;      // _0C
};

/**
 * @brief TODO
 */
struct NPosture2D {
	NPosture2D();               // unused/inlined
	NPosture2D(Vector3f&, f32); // unused/inlined

	virtual void readData(Stream&); // _08

	// unused/inlined:
	void construct(Vector3f&, f32);
	void outputTransform(NTransform3D&);
	void outputInverseTransform(NTransform3D&);
	void outputAxisAngle(NAxisAngle4f&);
	void println();

	// _00 = VTBL
	f32 _04; // _04
	f32 _08; // _08
	f32 _0C; // _0C
	f32 _10; // _10
};

/**
 * @brief TODO
 */
struct NPosture3D {
	NPosture3D();
	NPosture3D(Vector3f&, Vector3f&);
	NPosture3D(NPosture3D&); // unused/inlined

	virtual void readData(Stream&); // _08

	void construct(Vector3f&, Vector3f&);
	void normalize();
	void outputRelative(NVector3f&);
	void translate(Vector3f&);

	// unused/inlined:
	void construct(NPosture3D&);
	void outputUnitVector(NVector3f&);
	void transform(NTransform3D&);
	void rotate(NVector3f&, NPolar3f&);
	void rotatePoint(NVector3f&, NVector3f&, NPolar3f&);
	void interpolate(NPosture3D&, NPosture3D&, f32);
	void input(NPosture2D&);
	void output(NPosture2D&);
	void outputTransform(NPosture3D&, NTransform3D&);
	void outputTransform(NTransform3D&);
	void outputInverseTransform(NTransform3D&);
	void inputTransform(NTransform3D&);
	void calcDirection();
	void println();

	// _00 = VTBL
	NVector3f mDirection; // _04
	NVector3f mUp;        // _10
};

/**
 * @brief TODO
 */
struct NPosture3DIO {
	virtual void input(NPosture3D&)  = 0; // _08
	virtual void output(NPosture3D&) = 0; // _0C

	// TODO: members
};

/**
 * @brief TODO
 */
struct NTransform3D {
	NTransform3D();
	NTransform3D(NMatrix4f&); // unused/inlined

	void rotate(Vector3f&);
	void transform(Vector3f&);
	void inputAxisAngle(NAxisAngle4f&);
	void outputRotation(Matrix4f&);

	// unused/inlined:
	void construct(NMatrix4f&);
	void translate(Vector3f&);
	void transform(Vector3f&, Vector3f&);
	void transform(NVector&);
	void transform(NVector&, NVector&);
	void inputVector(Vector3f&);
	void inputTranslation(Vector3f&);
	void outputTranslation(Vector3f&);
	void inputRotation(Matrix4f&);
	void inputRotation(NAxisAngle4f&);

	NMatrix4f mMtx; // _00
};

struct NAlphaMode {
	enum _ {
		Linear    = 0,
		FadeOut   = 1,
		FadeIn    = 2,
		FadeInOut = 3,
		FadeOutIn = 4,
	};
};

/**
 * @brief TODO
 */
struct NAlpha {
	NAlpha(); // unused/inlined

	virtual void readData(Stream&); // _08

	void reset();
	f32 getValue(f32);

	// inlined
	f32 fadeInValue(f32 x);
	f32 fadeOutValue(f32 x);
	f32 fadeInOutValue(f32 x);
	f32 fadeOutInValue(f32 x);

	// _00 = VTBL
	f32 mValue;  // _04
	f32 mOffset; // _08
	f32 mScale;  // _0C, actually named 'period'
	u8 mMode;    // _10
};

#endif
