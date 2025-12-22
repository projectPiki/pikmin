#include "types.h"

extern int __float_nan[];
extern int __float_huge[];

#define NAN      (*(f32*)__float_nan)
#define INFINITY (*(f32*)__float_huge)

f64 sqrt(f64 x)
{
	if (x > 0.0) {
		f64 guess = __frsqrte(x);                           /* returns an approximation to  */
		guess     = .5 * guess * (3.0 - guess * guess * x); /* now have 8 sig bits          */
		guess     = .5 * guess * (3.0 - guess * guess * x); /* now have 16 sig bits         */
		guess     = .5 * guess * (3.0 - guess * guess * x); /* now have 32 sig bits         */
		guess     = .5 * guess * (3.0 - guess * guess * x); /* now have > 53 sig bits       */
		return x * guess;
	} else if (x == 0.0) {
		return 0;
	} else if (x) {
		return NAN;
	}
	return INFINITY;
}
