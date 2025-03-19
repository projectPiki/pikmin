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
 *
 * @note Size: 0x8.
 */
struct NVector {
	NVector();
	NVector(f32*, int); // unused/inlined

	void construct(f32*, int);
	void makeZero();

	// unused/inlined:
	void add(NVector&);
	f32 dot(NVector&);
	void input(NVector&);
	void println();

	int getDimension() { return mSize; }

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
	void interpolate(Vector3f&, Vector3f&, f32);
	bool isZero();
	bool equals(Vector3f&);
	bool isVertical(Vector3f&);
	void makeUnitVector(Vector3f&, Vector3f&);
	void outputQuat(f32, Quat&);
	f32 calcAngle(NVector3f&);
	f32 calcLargerAngle(NVector3f&);
	void print();
	void normalizeByLength(f32);
	static void printVector3f(Vector3f&);
	static void printlnVector3f(Vector3f&);

	f32 distanceXZ(Vector3f& other) { return NMathF::length(x - other.x, z - other.z); }

	f32 lengthXZ(); // DLL, to do

	// _00-_0C = Vector3f
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct NVector3fIO {
	virtual void input(NVector3f&)  = 0; // _08
	virtual void output(NVector3f&) = 0; // _0C

	// _00 = VTBL
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NVector3fIOClass : public NVector3fIO {
	virtual void input(NVector3f& vec) { _04.input(vec); }         // _08
	virtual void output(NVector3f& outVec) { _04.output(outVec); } // _0C

	// _00 = VTBL
	// _00-_04 = NVector3fIO
	NVector3f _04; // _04
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

	void makeIdentity()
	{
		input(NMatrix4f(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f));
	}

	// _00-_40 = Matrix4f
};

/**
 * @brief TODO
 */
struct NSpecialMatrix {
	NSpecialMatrix() { } // DLL inline
	NSpecialMatrix(int); // unused/inlined

	virtual void setDimension(int dim) { mDimension = dim; } // _08

	// unused/inlined:
	void construct(int);

	int getDimension() { return mDimension; }

	// _00 = VTBL
	int mDimension; // _04
};

/**
 * @brief TODO
 */
struct NUpperMatrix : public NSpecialMatrix {
	NUpperMatrix() { }             // DLL inline
	NUpperMatrix(f32*, f32*, int); // unused/inlined

	// unused/inlined:
	void construct(f32*, f32*, int);
	void solve(NVector&, NVector&);
	void println();

	f32 getCenter(int idx) { return mCentre[idx]; }
	void setCenter(int idx, f32 val) { mCentre[idx] = val; }
	void setUpper(int idx, f32 val) { mUpper[idx] = val; }

	// _00     = VTBL
	// _00-_08 = NSpecialMatrix
	f32* mCentre; // _08
	f32* mUpper;  // _0C
};

/**
 * @brief TODO
 */
struct NLowerMatrix : public NSpecialMatrix {
	NLowerMatrix() { }
	NLowerMatrix(f32*, int);

	// unused/inlined:
	void construct(f32*, int);
	void solve(NVector&, NVector&);
	void println();

	f32 getLower(int idx) { return mLower[idx - 1]; }
	void setLower(int idx, f32 val) { mLower[idx - 1] = val; }

	// _00     = VTBL
	// _00-_08 = NSpecialMatrix
	f32* mLower; // _08
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

	void setCenter(int, f32); // DLL, to do
	void setLower(int, f32);  // DLL, to do
	void setUpper(int, f32);  // DLL, to do

	// _00 = VTBL
	// _00-_08 = NSpecialMatrix
	NLowerMatrix mLower; // _08
	NUpperMatrix mUpper; // _14
	f32* mCentreVals;    // _24
	f32* mLowerVals;     // _28
	f32* mUpperVals;     // _2C
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

	NVector3f& getFore() { return mDirection; }
	NVector3f& getUp() { return mUpVector; }

	void input(Vector3f& direction, Vector3f& up)
	{
		mDirection.input(direction);
		mUpVector.input(up);
	}

	void inputUp(Vector3f& up) { mUpVector.input(up); }

	NVector3f mDirection; // _00, a.k.a. 'fore'/forward
	NVector3f mUpVector;  // _0C, a.k.a. 'up'
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
	void set(f32 radius, f32 incl, f32 azimuth);
	void input(Vector3f&);
	void output(Vector3f&);

	// unused/inlined:
	void construct(f32, f32, f32);
	void construct(NPolar3f&);
	void input(NPolar3f&);
	void negate();
	void interpolate(NPolar3f&, NPolar3f&, f32);
	void roundMeridian();
	bool clampMeridian(f32);
	void println();

	void round()
	{
		roundMeridian();
		roundAzimuth();
	}

	void roundAzimuth() { mAzimuth = NMathF::roundAngle(mAzimuth); }

	void add(NPolar3f& other) { add2(*this, other); } // yeah, really

	void add2(NPolar3f& pol1, NPolar3f& pol2)
	{
		mRadius      = pol1.mRadius + pol2.mRadius;
		mInclination = pol1.mInclination + pol2.mInclination;
		mAzimuth     = pol1.mAzimuth + pol2.mAzimuth;
		round();
	}

	void rotateAzimuth(f32 amt) { mAzimuth += amt; }

	f32 mRadius;      // _00
	f32 mInclination; // _04, a.k.a. meridian
	f32 mAzimuth;     // _08
};

/**
 * @brief TODO
 */
struct NAxisAngle4f {
	NAxisAngle4f(); // unused/inlined
	NAxisAngle4f(NVector3f&, f32);

	void construct(NVector3f&, f32);

	NVector3f& getAxis() { return mAxis; }
	f32 getAngle() { return mAngle; }
	void inputAxis(NVector3f& axis) { mAxis.input(axis); }
	void setAngle(f32 angle) { mAngle = angle; }

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

	NVector3f& getTranslation() { return mTranslation; }
	f32 getDirection() { return mDirection; }

	void inputTranslation(Vector3f& trans) { mTranslation.input(trans); }
	void setDirection(f32 dir) { mDirection = dir; }

	// _00 = VTBL
	NVector3f mTranslation; // _04
	f32 mDirection;         // _10
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
	f32 calcDirection();
	void println();

	NVector3f& getViewpoint() { return mViewpoint; }
	void inputViewpoint(Vector3f& view) { mViewpoint.input(view); }

	NVector3f& getWatchpoint() { return mWatchpoint; }
	void inputWatchpoint(Vector3f& watch) { mWatchpoint.input(watch); }

	void input(NPosture3D& other)
	{
		inputViewpoint(other.getViewpoint());
		inputWatchpoint(other.getWatchpoint());
	}

	void output(NPosture3D& output)
	{
		output.inputViewpoint(mViewpoint);
		output.inputWatchpoint(mWatchpoint);
	}

	// _00 = VTBL
	NVector3f mViewpoint;  // _04, i.e. where we *are*
	NVector3f mWatchpoint; // _10, i.e. where we're *looking* at
};

/**
 * @brief TODO
 */
struct NPosture3DIO {
	virtual void input(NPosture3D&)  = 0; // _08
	virtual void output(NPosture3D&) = 0; // _0C

	// _00 = VTBL
};

/**
 * @brief TODO
 */
struct NTransform3D : public NMatrix4f {
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

	// _00-_40 = NMatrix4f
};

struct NAlphaMode {
	enum _ {
		Linear    = 0,
		FadeIn    = 1,
		FadeOut   = 2,
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
	static f32 fadeInValue(f32 x);
	static f32 fadeOutValue(f32 x);
	static f32 fadeInOutValue(f32 x);
	static f32 fadeOutInValue(f32 x);

	f32 getValue() { return getValue(mValue); }
	void passTime(f32 inc) { mValue += inc; }

	bool isFinished() { return mValue >= getEndTime(); }

	f32 getStartTime() { return mOffset; }
	void setStartTime(f32 start) { mOffset = start; }

	f32 getPeriod() { return mScale; }
	void setPeriod(f32 period) { mScale = period; }

	f32 getTime() { return mValue; }
	void setTime(f32 time) { mValue = time; }

	f32 getEndTime() { return mOffset + mScale; }

	// _00 = VTBL
	f32 mValue;  // _04, a.k.a. time
	f32 mOffset; // _08, a.k.a. start time
	f32 mScale;  // _0C, a.k.a. period
	u8 mMode;    // _10
};

#endif
