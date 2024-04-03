#ifndef _MATH_H
#define _MATH_H

#include "types.h"

#define SQUARE(v)                      ((v) * (v))
#define LONG_TAU   6.2831854820251465
#define TAU        6.2831855f
#define PI         3.1415927f
#define HALF_PI    1.5707964f
#define THIRD_PI   1.0471976f
#define QUARTER_PI 0.7853982f

#define SIN_2_5 0.43633234f
#define M_SQRT3 1.73205f

#define DEG2RAD        (1.0f / 180.0f)
#define TORADIANS(val) (PI * (DEG2RAD * val))

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

static inline f32 sqrtf(f32 x)
{
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

#endif // _MATH_H
