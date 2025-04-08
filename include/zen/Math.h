#ifndef _ZEN_MATH_H
#define _ZEN_MATH_H

#include "types.h"
#include "stl/math.h"

struct Vector3f;
struct Matrix3f;
struct Matrix4f;
struct Quat;

namespace zen {
// global utility functions:
f32 getDistPointAndLine(Vector3f, Vector3f, Vector3f, f32&);
void makeRotMatrix(Vector3f&, Matrix3f&);

// DLL inlines:
inline int RoundOff(f32);
inline f32 Rand(f32);
inline f32 correctRad(f32 val);

inline f32 Abs(f32 val)
{
	if (val < 0.0f) {
		return -val;
	}
	return val;
}

// TODO: check this/check it didn't break anything else
inline int Abs(int val)
{
	if (val < 0) {
		return -val;
	}
	return val;
}
} // namespace zen

namespace ZenQuat {

// unused globals
static void GetMatrix(Quat const&, Matrix3f&);
static void GetMatrix(Quat const&, Matrix4f&);
static void GetRotate(Quat const&, Vector3f&);

} // namespace ZenQuat

namespace zenMatrix4f {
static void tMatrixTo(Matrix4f&, Matrix4f&);
}

#endif
