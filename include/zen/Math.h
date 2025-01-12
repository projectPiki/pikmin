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

namespace ZenQuat {

// unused globals
void GetMatrix(const Quat&, Matrix3f&);
void GetMatrix(const Quat&, Matrix4f&);
void GetRotate(const Quat&, Vector3f&);

} // namespace ZenQuat

// DLL inlines:
inline f32 Abs(f32 val)
{
	return fabsf(val);
}

} // namespace zen

#endif
