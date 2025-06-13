#ifndef _ZEN_MATH_H
#define _ZEN_MATH_H

#include "types.h"
#include "stl/math.h"
#include "system.h"

struct Vector3f;
struct Matrix3f;
struct Matrix4f;
struct Quat;

namespace zen {
// global utility functions:
f32 getDistPointAndLine(Vector3f point, Vector3f lineStartPt, Vector3f lineEndPt, f32& t);
void makeRotMatrix(Vector3f&, Matrix3f&);

// DLL inlines:
inline f32 correctRad(f32 val)
{
	if (val < 0.0f) {
		val += TAU;
	} else if (val > TAU) {
		val -= TAU;
	}

	return val;
}

// this VERY delicately matches zen::BalloonPane::invoke, change at your own risk
inline int RoundOff(f32 val)
{
	return int((val >= 0.0f) ? val + 0.5f : val - 0.5f);
}

inline f32 Rand(f32 max)
{
	return 1.0f * gsys->getRand(max);
}

inline f32 Abs(f32 val)
{
	return (val < 0.0f) ? -val : val;
}

// TODO: check this/check it didn't break anything else
inline int Abs(int val)
{
	return (val < 0) ? -val : val;
}

// TODO: I have no idea what this actually is in the map, but it exists as a function
// in particleGenerator at least, so who knows.
inline f32 RandShift(f32 min)
{
	return Rand(2.0f * min) - min;
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
