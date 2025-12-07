#ifndef _NLIB_GEOMETRY_H
#define _NLIB_GEOMETRY_H

#include "Dolphin/mtx.h"
#include "Matrix4f.h"
#include "Vector.h"
#include "nlib/Math.h"
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
	void add(immut NVector&);
	f32 dot(immut NVector&) immut;
	void input(immut NVector&);
	void println() immut;

	int getDimension() immut { return mSize; }

	f32* mValues; // _00, array of size mSize
	int mSize;    // _04
};

/**
 * @brief TODO
 */
struct NVector3f : public Vector3f {
	NVector3f();
	NVector3f(immut Vector3f&);
	NVector3f(f32, f32, f32);
	NVector3f(immut Vector3f&, immut Vector3f&);

	void construct(immut Vector3f&);
	void construct(f32, f32, f32);
	void construct(immut Vector3f&, immut Vector3f&);
	bool isParallel(immut Vector3f&) immut;
	void println() immut;
	bool normalizeCheck();
	void normalize();

	// unused/inlined:
	void interpolate(immut Vector3f&, immut Vector3f&, f32);
	bool isZero() immut;
	bool equals(immut Vector3f&) immut;
	bool isVertical(immut Vector3f&) immut;
	void makeUnitVector(immut Vector3f&, immut Vector3f&);
	void outputQuat(f32, Quat&) immut;
	f32 calcAngle(immut NVector3f&) immut;
	f32 calcLargerAngle(immut NVector3f&) immut;
	void print() immut;
	void normalizeByLength(f32);
	static void printVector3f(immut Vector3f&);
	static void printlnVector3f(immut Vector3f&);

	f32 distanceXZ(immut Vector3f& other) immut { return NMathF::length(x - other.x, z - other.z); }
	f32 lengthXZ() immut { return NMathF::length(x, z); }

	// _00-_0C = Vector3f
};

/**
 * @brief TODO
 *
 * @note Size: 0x4.
 */
struct NVector3fIO {
	virtual void input(immut NVector3f&)  = 0; // _08
	virtual void output(NVector3f&) immut = 0; // _0C

	// _00 = VTBL
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct NVector3fIOClass : public NVector3fIO {
	virtual void input(immut NVector3f& vec) { _04.input(vec); }         // _08
	virtual void output(NVector3f& outVec) immut { _04.output(outVec); } // _0C

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
	NMatrix4f(immut Matrix4f&); // unused/inlined
	NMatrix4f(immut Mtx);       // unused/inlined

	void construct(immut Matrix4f&);
	void input(immut Matrix4f&);
	void set(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	void outputCol(int, Vector3f&) immut;
	void makeIdentRow(int);

	// unused/inlined:
	void construct(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	void construct(immut Mtx);
	void input(immut Mtx);
	void output(Mtx) immut;
	void setRow(int, f32, f32, f32);
	void inputRow(int, immut Vector3f&);
	void inputRow(int, immut Vector3f&, f32);
	void outputRow(int, Vector3f&) immut;
	void inputRows(immut NVector3f&, immut NVector3f&, immut NVector3f&);
	void setCol(int, f32, f32, f32);
	void inputCol(int, immut Vector3f&);
	void inputCol(int, immut Vector3f&, f32);
	void inputCols(immut NVector3f&, immut NVector3f&, immut NVector3f&);
	void mul(immut Matrix4f&);
	void mul2(immut Matrix4f&, Matrix4f&) immut;
	void scale(f32);
	void transpose();
	void println() immut;

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

	int getDimension() immut { return mDimension; }

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
	void solve(immut NVector&, NVector&);
	void println() immut;

	f32 getCenter(int idx) immut { return mCentre[idx]; }
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
	void solve(immut NVector&, NVector&);
	void println() immut;

	f32 getLower(int idx) immut { return mLower[idx - 1]; }
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
	void solve(immut NVector&, NVector&);
	void decompose();
	void println() immut;

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
	NOrientation(immut Vector3f&);
	NOrientation();                                 // unused/inlined
	NOrientation(immut Vector3f&, immut Vector3f&); // unused/inlined

	void construct(immut Vector3f&);
	void normalize();
	void outputLeft(NVector3f&) immut;
	void makeUp();

	// unused/inlined:
	void construct(immut Vector3f&, immut Vector3f&);
	void transform(immut NTransform3D&);
	void outputRight(NVector3f&) immut;
	void outputTransform(NTransform3D&) immut;
	void inputTransform(immut NTransform3D&);
	void outputRotation(NTransform3D&) immut;
	void inputRotation(immut NTransform3D&);
	void println() immut;

	NVector3f& getFore() { return mDirection; }
	NVector3f& getUp() { return mUpVector; }

	void input(immut Vector3f& direction, immut Vector3f& up)
	{
		mDirection.input(direction);
		mUpVector.input(up);
	}

	void inputUp(immut Vector3f& up) { mUpVector.input(up); }

	// FABRICATED, but necessary for opt-in const-correctness...
	const NVector3f& getFore() const { return mDirection; }
	const NVector3f& getUp() const { return mUpVector; }

	NVector3f mDirection; // _00, a.k.a. 'fore'/forward
	NVector3f mUpVector;  // _0C, a.k.a. 'up'
};

/**
 * @brief TODO
 */
struct NPolar3f {
	NPolar3f();
	NPolar3f(immut Vector3f&);
	NPolar3f(f32, f32, f32);   // unused/inlined
	NPolar3f(immut NPolar3f&); // unused/inlined

	void construct(immut Vector3f&);
	void set(f32 radius, f32 incl, f32 azimuth);
	void input(immut Vector3f&);
	void output(Vector3f&) immut;

	// unused/inlined:
	void construct(f32, f32, f32);
	void construct(immut NPolar3f&);
	void input(immut NPolar3f&);
	void negate();
	void interpolate(immut NPolar3f&, immut NPolar3f&, f32);
	void roundMeridian();
	bool clampMeridian(f32);
	void println() immut;

	void round()
	{
		roundMeridian();
		roundAzimuth();
	}

	void roundAzimuth() { mAzimuth = NMathF::roundAngle(mAzimuth); }

	void add(immut NPolar3f& other) { add2(*this, other); } // yeah, really

	void add2(immut NPolar3f& pol1, immut NPolar3f& pol2)
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
	NAxisAngle4f(immut NVector3f&, f32);

	void construct(immut NVector3f&, f32);

	NVector3f& getAxis() { return mAxis; }
	f32 getAngle() immut { return mAngle; }
	void inputAxis(immut NVector3f& axis) { mAxis.input(axis); }
	void setAngle(f32 angle) { mAngle = angle; }

	// FABRICATED, but necessary for opt-in const-correctness...
	const NVector3f& getAxis() const { return mAxis; }

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
	void construct(immut Vector3f&, f32);
	void outputTransform(NTransform3D&);
	void outputInverseTransform(NTransform3D&);
	void outputAxisAngle(NAxisAngle4f&);
	void println() immut;

	NVector3f& getTranslation() { return mTranslation; }
	f32 getDirection() immut { return mDirection; }

	void inputTranslation(immut Vector3f& trans) { mTranslation.input(trans); }
	void setDirection(f32 dir) { mDirection = dir; }

	// FABRICATED, but necessary for opt-in const-correctness...
	const NVector3f& getTranslation() const { return mTranslation; }

	// _00 = VTBL
	NVector3f mTranslation; // _04
	f32 mDirection;         // _10
};

/**
 * @brief TODO
 */
struct NPosture3D {
	NPosture3D();
	NPosture3D(immut Vector3f&, immut Vector3f&);
	NPosture3D(immut NPosture3D&); // unused/inlined

	virtual void readData(Stream&); // _08

	void construct(immut Vector3f&, immut Vector3f&);
	void normalize();
	void outputRelative(NVector3f&) immut;
	void translate(immut Vector3f&);

	// unused/inlined:
	void construct(immut NPosture3D&);
	void outputUnitVector(NVector3f&) immut;
	void transform(immut NTransform3D&);
	void rotate(immut NVector3f&, immut NPolar3f&);
	void rotatePoint(NVector3f&, immut NVector3f&, immut NPolar3f&) immut;
	void interpolate(immut NPosture3D&, immut NPosture3D&, f32);
	void input(immut NPosture2D&);
	void output(NPosture2D&) immut;
	void outputTransform(immut NPosture3D&, NTransform3D&) immut;
	void outputTransform(NTransform3D&) immut;
	void outputInverseTransform(NTransform3D&) immut;
	void inputTransform(immut NTransform3D&);
	f32 calcDirection() immut;
	void println() immut;

	NVector3f& getViewpoint() { return mViewpoint; }
	void inputViewpoint(immut Vector3f& view) { mViewpoint.input(view); }

	NVector3f& getWatchpoint() { return mWatchpoint; }
	void inputWatchpoint(immut Vector3f& watch) { mWatchpoint.input(watch); }

	void input(immut NPosture3D& other)
	{
		inputViewpoint(other.getViewpoint());
		inputWatchpoint(other.getWatchpoint());
	}

	void output(NPosture3D& output) immut
	{
		output.inputViewpoint(mViewpoint);
		output.inputWatchpoint(mWatchpoint);
	}

	// FABRICATED, but necessary for opt-in const-correctness...
	const NVector3f& getViewpoint() const { return mViewpoint; }
	const NVector3f& getWatchpoint() const { return mWatchpoint; }

	// _00 = VTBL
	NVector3f mViewpoint;  // _04, i.e. where we *are*
	NVector3f mWatchpoint; // _10, i.e. where we're *looking* at
};

/**
 * @brief TODO
 */
struct NPosture3DIO {
	virtual void input(immut NPosture3D&)  = 0; // _08
	virtual void output(NPosture3D&) immut = 0; // _0C

	// _00 = VTBL
};

/**
 * @brief TODO
 */
struct NTransform3D : public NMatrix4f {
	NTransform3D();
	NTransform3D(immut NMatrix4f&); // unused/inlined

	void rotate(immut Vector3f&);
	void transform(Vector3f&) immut;
	void inputAxisAngle(immut NAxisAngle4f&);
	void outputRotation(Matrix4f&) immut;

	// unused/inlined:
	void construct(immut NMatrix4f&);
	void translate(immut Vector3f&);
	void transform(immut Vector3f&, Vector3f&) immut;
	void transform(NVector&) immut;
	void transform(immut NVector&, NVector&) immut;
	void inputVector(immut Vector3f&);
	void inputTranslation(immut Vector3f&);
	void outputTranslation(Vector3f&) immut;
	void inputRotation(immut Matrix4f&);
	void inputRotation(immut NAxisAngle4f&);

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
