#include "types.h"

extern f64 __ieee754_pow();

/*
 * --INFO--
 * Address:	8021B708
 * Size:	000020
 */
f64 pow(f64 __x, f64 __y)
{
	return (f64)__ieee754_pow();
}
