#ifndef _SYSMATH_H
#define _SYSMATH_H

#include "types.h"
#include <math.h>

struct Vector3f;
struct BoundBox;
struct KTri;
struct KRect;
struct KSegment;

#define SQUARE(v) ((v) * (v))

#define DEG2RAD            (1.0f / 180.0f)
#define TORADIANS(degrees) (PI * (DEG2RAD * degrees))
#define RAD2DEG            (180.0f / PI)
#define TODEGREES(radians) (radians * RAD2DEG)

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

inline f32 absF(f32 val)
{
	return (f32)fabsf(val);
}

// TODO: probably change this to zen::abs in some zenMath library later
inline f32 absVal(f32 val)
{
	if (val > 0.0f) {
		return val;
	}
	return -val;
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

#endif // _SYSMATH_H
