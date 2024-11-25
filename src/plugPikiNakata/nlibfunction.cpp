#include "nlib/Function.h"
#include "nlib/Math.h"
#include "PikiMacros.h"
#include "Dolphin/os.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "nlibfunction");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
NPolynomialFunction::NPolynomialFunction(f32*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011B6E4
 * Size:	000028
 */
void NPolynomialFunction::construct(f32* p1, int p2) { _04.construct(p1, p2 + 1); }

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
NPolynomialFunction::NPolynomialFunction(f32*, NPolynomialFunction&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NPolynomialFunction::construct(f32*, NPolynomialFunction&)
{
	_04.mValues[0] = 0.0f; // need 0.0f to get used before getValue
	                       // UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00029C
 */
void NPolynomialFunction::mul2(NPolynomialFunction&, NPolynomialFunction&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011B70C
 * Size:	000114
 */
f32 NPolynomialFunction::getValue(f32 p1)
{
	f32 factor = 1.0f;
	f32 value  = 0.0f;
	for (int i = 0; i < _04.mSize; i++) {
		value += factor * _04.mValues[i];
		factor *= p1;
	}
	return value;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NPolynomialFunction::getCoefficient(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011B820
 * Size:	000058
 */
void NPolynomialFunction::println()
{
	DEBUGPRINT(_04.mSize);
	for (int i = 0; i < _04.mSize; i++) {
		DEBUGPRINT(_04.mValues[i]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
NLinearFunction::NLinearFunction(f32* values)
    : NPolynomialFunction(values, 1)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NLinearFunction::construct(f32* values)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void NLinearFunction::makeLinearFunction(f32, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011B878
 * Size:	00007C
 */
NClampLinearFunction::NClampLinearFunction(f32* values)
    : NLinearFunction(values)
{
	construct(values);
}

/*
 * --INFO--
 * Address:	8011B8F4
 * Size:	000028
 */
void NClampLinearFunction::construct(f32* values) { _04.construct(values, 2); }

/*
 * --INFO--
 * Address:	8011B91C
 * Size:	000090
 */
void NClampLinearFunction::makeClampLinearFunction(f32 p1, f32 p2, f32 p3, f32 p4)
{
	if (NMathf::absolute(p3 - p1) <= NMathF::error) {
		_04.mValues[1] = 1.0f;
	} else {
		_04.mValues[1] = (p4 - p2) / (p3 - p1);
	}

	_04.mValues[0] = p2 - _04.mValues[1] * p1;

	_0C = p2 < p4 ? p2 : p4;
	_10 = p2 < p4 ? p4 : p2;
}

/*
 * --INFO--
 * Address:	8011B9AC
 * Size:	000134
 */
f32 NClampLinearFunction::getValue(f32 p1)
{
	f32 val = NPolynomialFunction::getValue(p1);
	return NMathf::clamp(val, _0C, _10);
}

/*
 * --INFO--
 * Address:	8011BAE0
 * Size:	000058
 */
void NClampLinearFunction::println()
{
	NPolynomialFunction::println();
	DEBUGPRINT(_0C);
	DEBUGPRINT(_10);
}

/*
 * --INFO--
 * Address:	8011BB38
 * Size:	00003C
 */
NVibrationFunction::NVibrationFunction()
{
	mPhase       = 0.0f;
	mAngularFreq = 2.0f * NMathF::pi;
	mAmplitude   = 1.0f;
}

/*
 * --INFO--
 * Address:	8011BB74
 * Size:	000020
 */
void NVibrationFunction::makeVibrationFunction(f32 phase, f32 period, f32 amp)
{
	mPhase       = phase;
	mAngularFreq = (2.0f * NMathF::pi) / period;
	mAmplitude   = amp;
}

/*
 * --INFO--
 * Address:	8011BB94
 * Size:	000044
 */
f32 NVibrationFunction::getValue(f32 p1)
{
	u32 badCompiler;
	return mAmplitude * sinf(mPhase + mAngularFreq * p1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
NFunction3D::NFunction3D()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void NFunction3D::construct(NFunction*, NFunction*, NFunction*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BBD8
 * Size:	0000A8
 */
void NFunction3D::outputPosition(f32 val, NVector3f& vec) { vec.set(_00->getValue(val), _04->getValue(val), _08->getValue(val)); }
