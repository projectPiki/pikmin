#ifndef _MATH_H
#define _MATH_H

#include "PowerPC_EABI_Support/MSL_C/PPC_EABI/math_ppc.h"
#include "std/Math.h"
#include "types.h"

#define SQUARE(v) ((v) * (v))

static inline f32 quickABS(f32 x)
{
	*(u32*)&x &= ~0x80000000;
	return x;
}

static inline f32 u32ToFloat(u32 a)
{
	union {
		u32 w;
		f32 f;
	} tmp;
	tmp.w = a;
	return tmp.f;
}

#define LONG_TAU   6.2831854820251465
#define TAU        6.2831855f
#define PI         3.1415927f
#define HALF_PI    1.5707964f
#define THIRD_PI   1.0471976f
#define QUARTER_PI 0.7853982f
#define SIN_2_5    0.43633234f
#define M_SQRT3    1.73205f
#define M_PI       3.1415926535897932

#define FP_NAN       1
#define FP_INFINITE  2
#define FP_ZERO      3
#define FP_NORMAL    4
#define FP_SUBNORMAL 5

#ifndef DEG2RAD

#define DEG2RAD            (1.0f / 180.0f)
#define TORADIANS(degrees) (PI * (DEG2RAD * degrees))
#define RAD2DEG            (180.0f / PI)
#define TODEGREES(radians) (radians * RAD2DEG)

#endif

#define CHECK_BOUNDS_BOTH(min, val1, val2, max) (min <= val1 && val2 < max)

f64 __fabs(f64);
f32 __fabsf(f32);
f64 __fnabs(f64);
f32 __fnabsf(f32);
f64 __fmadd(f64, f64, f64);
f64 __fmsub(f64, f64, f64);
f64 __fnmadd(f64, f64, f64);
f64 __fnmsub(f64, f64, f64);
f32 __fmadds(f32, f32, f32);
f32 __fmsubs(f32, f32, f32);
f32 __fnmadds(f32, f32, f32);
f32 __fnmsubs(f32, f32, f32);
f64 __fsel(f64, f64, f64);
f32 __fsels(f32, f32, f32);
f64 __frsqrte(f64);
f32 __fres(f32);
f64 __fsqrt(f64);
f32 __fsqrts(f32);
s64 __fctid(f64);
s64 __fctiw(f64);
f64 __fcfid(s64);
f64 __mffs(void);
void __mtfsf(int, f64);
void __mtfsfi(int, int);
void __mtfsb0(int);
void __mtfsb1(int);
f64 __setflm(f64);

inline f32 sqrtf(f32 x)
{
	// these REALLY don't have to be static.
	static const f64 _half  = .5;
	static const f64 _three = 3.0;

	vf32 y;
	if (x > 0.0f) {

		f64 guess = __frsqrte((f64)x);                            // returns an approximation to
		guess     = _half * guess * (_three - guess * guess * x); // now have 12 sig bits
		guess     = _half * guess * (_three - guess * guess * x); // now have 24 sig bits
		guess     = _half * guess * (_three - guess * guess * x); // now have 32 sig bits
		y         = (f32)(x * guess);
		return y;
	}
	return x;
}

inline f32 absF(f32 val)
{
	return (f32)__fabsf(val);
}

// TODO: probably change this to zen::abs in some zenMath library later
inline f32 absVal(f32 val)
{
	if (val > 0.0f) {
		return val;
	}
	return -val;
}

#ifdef __cplusplus
// Pikmin-specific global math functions
struct Vector3f;
struct BoundBox;
struct KTri;
struct KRect;
struct KSegment;

inline f32 fmod(f32 x, f32 m)
{
	return std::fmodf(x, m);
}

f32 roundAng(f32 angle);
f32 angDist(f32 x, f32 z);
f32 qdist2(f32 x0, f32 z0, f32 x1, f32 z1);
f32 triRectDistance(immut Vector3f*, immut Vector3f*, immut Vector3f*, BoundBox&, bool);
f32 distanceTriRect(KTri&, KRect&, f32*, f32*, f32*, f32*);
f32 sqrDistance(KSegment&, KTri&, f32*, f32*, f32*);
f32 sqrDistance(KSegment&, KSegment&, f32*, f32*);
f32 sqrDistance(KSegment&, KRect&, f32*, f32*, f32*);
f32 sqrDistance(KTri&, KRect&, f32*, f32*, f32*, f32*);
f32 sqrDistance(immut Vector3f&, KTri&, f32*, f32*);

// unused
f32 qdist3(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1);

inline f32 speedy_sqrtf(f32 x)
{
	vf32 y;
	if (x > 0.0f) {

		f64 guess = __frsqrte((f64)x);
		y         = (f32)(x * guess);
		return y;
	}
	return x;
}

#endif

#endif // _MATH_H
