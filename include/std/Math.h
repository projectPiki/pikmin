#ifndef _STD_MATH_H
#define _STD_MATH_H

#include "types.h"

/**
 * @brief TODO
 */
namespace std {

inline f32 sqrtf(f32 x)
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

void fmodf(f32, f32);

} // namespace std

#endif
