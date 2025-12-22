#include "DebugLog.h"
#include "Dolphin/os.h"
#include "nlib/Function.h"
#include "nlib/Math.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("nlibfunction");

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000074
 */
NPolynomialFunction::NPolynomialFunction(f32*, int)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void NPolynomialFunction::construct(f32* coefficients, int degree)
{
	mData.construct(coefficients, degree + 1);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000074
 */
NPolynomialFunction::NPolynomialFunction(f32*, NPolynomialFunction&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000050
 */
void NPolynomialFunction::construct(f32*, NPolynomialFunction&)
{
	mData.mValues[0] = 0.0f; // need 0.0f to get used before getValue
	                         // UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00029C
 */
void NPolynomialFunction::mul2(NPolynomialFunction&, NPolynomialFunction&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
f32 NPolynomialFunction::getValue(f32 p1)
{
	f32 factor = 1.0f;
	f32 value  = 0.0f;
	for (int i = 0; i < mData.mSize; i++) {
		value += factor * mData.mValues[i];
		factor *= p1;
	}
	return value;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
f32 NPolynomialFunction::getCoefficient(int)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void NPolynomialFunction::println() immut
{
	PRINT_NAKATA("NPolynomialFunction:%d\n", mData.getDimension());
	for (int i = 0; i < mData.getDimension(); i++) {
		PRINT_NAKATA("NPolynomialFunction:%d:%f\n", i, mData.mValues[i]);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
 */
NLinearFunction::NLinearFunction(f32* values)
    : NPolynomialFunction(values, 1)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000028
 */
void NLinearFunction::construct(f32* values)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000068
 */
void NLinearFunction::makeLinearFunction(f32, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
NClampLinearFunction::NClampLinearFunction(f32* values)
    : NLinearFunction(values)
{
	construct(values);
}

/**
 * @TODO: Documentation
 */
void NClampLinearFunction::construct(f32* values)
{
	mData.construct(values, 2);
}

/**
 * @TODO: Documentation
 */
void NClampLinearFunction::makeClampLinearFunction(f32 x1, f32 y1, f32 x2, f32 y2)
{
	if (NMathF::isZero(x2 - x1)) {
		mData.mValues[1] = 1.0f;
	} else {
		// Slope is rise (y) over (/) run (x)
		mData.mValues[1] = (y2 - y1) / (x2 - x1);
	}

	// Intercept
	mData.mValues[0] = y1 - mData.mValues[1] * x1;

	mMinValue = y1 < y2 ? y1 : y2;
	mMaxValue = y1 < y2 ? y2 : y1;
}

/**
 * @TODO: Documentation
 */
f32 NClampLinearFunction::getValue(f32 p1)
{
	f32 val = NPolynomialFunction::getValue(p1);
	return NMathf::clampMinMax(val, mMinValue, mMaxValue);
}

/**
 * @TODO: Documentation
 */
void NClampLinearFunction::println() immut
{
	NPolynomialFunction::println();
}

/**
 * @TODO: Documentation
 */
NVibrationFunction::NVibrationFunction()
{
	mPhase       = 0.0f;
	mAngularFreq = 2.0f * NMathF::pi;
	mAmplitude   = 1.0f;
}

/**
 * @TODO: Documentation
 */
void NVibrationFunction::makeVibrationFunction(f32 phase, f32 period, f32 amp)
{
	mPhase       = phase;
	mAngularFreq = (2.0f * NMathF::pi) / period;
	mAmplitude   = amp;
}

/**
 * @TODO: Documentation
 */
f32 NVibrationFunction::getValue(f32 p1)
{
	STACK_PAD_VAR(1);
	return mAmplitude * sinf(mPhase + mAngularFreq * p1);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000004
 */
NFunction3D::NFunction3D()
{
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000010
 */
void NFunction3D::construct(NFunction* funX, NFunction* funY, NFunction* funZ)
{
	mFunctionX = funX;
	mFunctionY = funY;
	mFunctionZ = funZ;
}

/**
 * @TODO: Documentation
 */
void NFunction3D::outputPosition(f32 val, NVector3f& vec)
{
	vec.set(mFunctionX->getValue(val), mFunctionY->getValue(val), mFunctionZ->getValue(val));
}
