#ifndef _STD_MATH_H
#define _STD_MATH_H

#include "types.h"

/**
 * @brief TODO
 */
#ifdef __cplusplus
namespace std {

inline f32 sqrtf(f32 x)
{
	// these REALLY don't have to be static.
	const f64 _half  = 0.5;
	const f64 _three = 3.0;

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

#ifdef __MWERKS__
#define fabs(x)  __fabs(x)
#define fabsf(x) __fabsf(x)
#else
double fabs(double x);
f32 fabsf(f32 x);
#endif

inline f32 fmodf(f32 x, f32 m)
{
	f32 a = fabsf(m);
	f32 b = fabsf(x);
	if (a > b)
		return x;
	else {
		long long c = (long long)(x / m);
		return x - m * c;
	}
}
} // namespace std
#endif

#endif
