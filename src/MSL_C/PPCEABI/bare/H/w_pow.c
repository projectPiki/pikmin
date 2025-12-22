#include "types.h"

extern f64 __ieee754_pow();

/**
 * @TODO: Documentation
 */
f64 pow(f64 __x, f64 __y)
{
	return (f64)__ieee754_pow();
}
