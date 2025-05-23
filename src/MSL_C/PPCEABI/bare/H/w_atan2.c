#include "types.h"

extern f64 __ieee754_atan2();

/*
 * --INFO--
 * Address:	8021B6E8
 * Size:	000020
 */
f64 atan2(f64 __x, f64 __y)
{
	return (f64)__ieee754_atan2();
}
