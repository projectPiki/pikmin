#include "DebugLog.h"
#include "Dolphin/os.h"
#include "nlib/Function.h"
#include "nlib/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("nlibfunction");

/**
 * @todo: Documentation
 * @note UNUSED Size: 000074 (Matching by size)
 */
NPolynomialFunction::NPolynomialFunction(f32* coefficients, int degree)
{
	construct(coefficients, degree);
}

/**
 * @todo: Documentation
 */
void NPolynomialFunction::construct(f32* coefficients, int degree)
{
	mData.construct(coefficients, degree + 1);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000074 (Matching by size)
 */
NPolynomialFunction::NPolynomialFunction(f32* coefficients, immut NPolynomialFunction& other)
{
	construct(coefficients, other);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000050 (Matching by size)
 */
void NPolynomialFunction::construct(f32* coefficients, immut NPolynomialFunction& other)
{
	mData.construct(coefficients, other.getFunctionDimension() + 1);
	mData.input(other.mData);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00029C (Matching by size)
 */
void NPolynomialFunction::mul2(immut NPolynomialFunction& lhs, immut NPolynomialFunction& rhs)
{
	if (lhs.getFunctionDimension() + rhs.getFunctionDimension() > getFunctionDimension()) {
		PRINT_NAKATA("?dimension over:%d+%d>%d\n", lhs.getFunctionDimension(), rhs.getFunctionDimension(), getFunctionDimension());
		return;
	}

	for (int i = 0; i < getFunctionDimension(); ++i) {
		mData.mValues[i] = 0.0f;
		for (int j = 0; j <= i; ++j) {
			mData.mValues[i] += rhs.mData.mValues[i - j] * lhs.mData.mValues[j];
		}
	}
}

/**
 * @todo: Documentation
 */
f32 NPolynomialFunction::getValue(f32 x)
{
	f32 factor = 1.0f;
	f32 value  = 0.0f;
	for (int i = 0; i < mData.mSize; i++) {
		value += factor * mData.mValues[i];
		factor *= x;
	}
	return value;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000028 (Matching by size)
 */
f32 NPolynomialFunction::getCoefficient(int idx)
{
	if (getFunctionDimension() < idx) {
		return 0.0f;
	}
	return mData.mValues[idx];
}

/**
 * @todo: Documentation
 */
void NPolynomialFunction::println() immut
{
	PRINT_NAKATA("NPolynomialFunction:%d\n", mData.getDimension());
	for (int i = 0; i < mData.getDimension(); i++) {
		PRINT_NAKATA("NPolynomialFunction:%d:%f\n", i, mData.mValues[i]);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000070 (Matching by size)
 */
NLinearFunction::NLinearFunction(f32* const coefficients)
{
	construct(coefficients);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000028 (Matching by size)
 */
void NLinearFunction::construct(f32* const coefficients)
{
	NPolynomialFunction::construct(coefficients, 1);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000068 (Matching by size)
 */
void NLinearFunction::makeLinearFunction(f32 x1, f32 y1, f32 x2, f32 y2)
{
	f32 dx = x2 - x1;
	if (NMath<f32>::absolute(dx) <= NMathF::error) {
		// We want an average rate of change, not an instantaneous rate of change!
		PRINT_NAKATA("!NLinearFunction::makeLinearFunction:%f,%f\n", x1, x2);
		mData.mValues[1] = 1.0f;
	} else {
		// Slope is dy/dx (rise over run)
		mData.mValues[1] = (y2 - y1) / dx;
	}
	// Convert from point-slope form to slope-intercept form.
	mData.mValues[0] = y1 - mData.mValues[1] * x1;
}

/**
 * @todo: Documentation
 */
NClampLinearFunction::NClampLinearFunction(f32* const coefficients)
{
	construct(coefficients);
}

/**
 * @todo: Documentation
 */
void NClampLinearFunction::construct(f32* const coefficients)
{
	NLinearFunction::construct(coefficients);
}

/**
 * @todo: Documentation
 */
void NClampLinearFunction::makeClampLinearFunction(f32 x1, f32 y1, f32 x2, f32 y2)
{
	makeLinearFunction(x1, y1, x2, y2);
	mMinValue = NMath<f32>::minValue(y1, y2);
	mMaxValue = NMath<f32>::maxValue(y1, y2);
}

/**
 * @todo: Documentation
 */
f32 NClampLinearFunction::getValue(f32 x)
{
	return NMathf::clampMinMax(NPolynomialFunction::getValue(x), mMinValue, mMaxValue);
}

/**
 * @todo: Documentation
 */
void NClampLinearFunction::println() immut
{
	PRINT_NAKATA("NClampLinearFunction:%f,%f\n", mMinValue, mMaxValue);
	NPolynomialFunction::println();
}

/**
 * @todo: Documentation
 */
NVibrationFunction::NVibrationFunction()
{
	mPhase       = 0.0f;
	mAngularFreq = 2.0f * NMathF::pi;
	mAmplitude   = 1.0f;
}

/**
 * @todo: Documentation
 */
void NVibrationFunction::makeVibrationFunction(f32 phase, f32 period, f32 amp)
{
	mPhase       = phase;
	mAngularFreq = 2.0f * NMathF::pi / period;
	mAmplitude   = amp;
}

/**
 * @todo: Documentation
 */
f32 NVibrationFunction::getValue(f32 x)
{
	STACK_PAD_VAR(1);
	return mAmplitude * sinf(mPhase + mAngularFreq * x);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004 (Matching by size)
 */
NFunction3D::NFunction3D()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010 (Matching by size)
 */
void NFunction3D::construct(NFunction* funX, NFunction* funY, NFunction* funZ)
{
	mFunctionX = funX;
	mFunctionY = funY;
	mFunctionZ = funZ;
}

/**
 * @todo: Documentation
 */
void NFunction3D::outputPosition(f32 val, NVector3f& vec)
{
	vec.set(mFunctionX->getValue(val), mFunctionY->getValue(val), mFunctionZ->getValue(val));
}
