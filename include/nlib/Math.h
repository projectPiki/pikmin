#ifndef _NLIB_MATH_H
#define _NLIB_MATH_H

#include "types.h"
#include "Dolphin/mtx.h"
#include "system.h"
#include "Vector.h"

namespace NMathF {
static inline f32 cos(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0xD5180
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
static inline f32 sin(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0xD52F4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
f32 atan2(f32, f32);
f32 remainder(f32, f32);

// unused/inlined:
f32 roundAngle(f32);

inline f32 atan2Vec(Vector3f vec) { return atan2(vec.x, vec.z); }

extern f32 pi;

inline f32 getRandomAngle() { return 2.0f * StdSystem::getRand(1.0f) * pi; }

extern f32 error;
} // namespace NMathF

template <typename T>
struct NMath {
	static void copyArray44(Mtx44 output, Mtx44 input)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				output[i][j] = input[i][j];
			}
		}
	}

	static T absolute(T val)
	{
		if (val > 0) {
			return val;
		}
		return -val;
	}

	static T clamp(T val, T lower, T upper)
	{
		if (val < lower) {
			return lower;
		}
		if (val > upper) {
			return upper;
		}
		return val;
	}
};

typedef NMath<f32> NMathf;

#endif
