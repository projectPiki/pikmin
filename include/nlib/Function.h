#ifndef _NLIB_FUNCTION_H
#define _NLIB_FUNCTION_H

#include "nlib/Geometry.h"

/**
 * @brief TODO
 */
struct NFunction {
	virtual f32 getValue(f32) = 0; // _08

	// _00 = VTBL
};

/**
 * @brief TODO
 */
struct NPolynomialFunction : public NFunction {
	NPolynomialFunction(f32*, int);                  // unused/inlined
	NPolynomialFunction(f32*, NPolynomialFunction&); // unused/inlined

	virtual f32 getValue(f32); // _08
	virtual void println();    // _0C

	void construct(f32*, int);

	// unused/inlined:
	void construct(f32*, NPolynomialFunction&);
	void mul2(NPolynomialFunction&, NPolynomialFunction&);
	f32 getCoefficient(int);

	// _00     = VTBL
	// _00-_04 = NFunction
	NVector mData; // _04
};

/**
 * @brief TODO
 */
struct NLinearFunction : public NPolynomialFunction {
	NLinearFunction(f32*); // unused/inlined

	// unused/inlined:
	void construct(f32*);
	void makeLinearFunction(f32, f32, f32, f32);

	// _00     = VTBL
	// _00-_0C = NPolynomialFunction
};

/**
 * @brief TODO
 */
struct NClampLinearFunction : public NLinearFunction {
	NClampLinearFunction(f32*);

	virtual f32 getValue(f32); // _08
	virtual void println();    // _0C

	void construct(f32*);
	void makeClampLinearFunction(f32, f32, f32, f32);

	// _00     = VTBL
	// _00-_0C = NLinearFunction
	f32 mMinValue; // _0C
	f32 mMaxValue; // _10
};

/**
 * @brief TODO
 */
struct NVibrationFunction : public NFunction {
	NVibrationFunction();

	virtual f32 getValue(f32); // _08

	void makeVibrationFunction(f32, f32, f32);

	// _00     = VTBL
	// _00-_04 = NFunction
	f32 mPhase;       // _04
	f32 mAngularFreq; // _08
	f32 mAmplitude;   // _0C
};

/**
 * @brief TODO
 */
struct NFunction3D {
	NFunction3D(); // unused/inlined

	void outputPosition(f32, NVector3f&);

	// unused/inlined:
	void construct(NFunction*, NFunction*, NFunction*);

	NFunction* mFunctionX; // _00
	NFunction* mFunctionY; // _04
	NFunction* mFunctionZ; // _08
};

#endif
