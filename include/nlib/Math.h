#ifndef _NLIB_MATH_H
#define _NLIB_MATH_H

#include "types.h"
#include "Dolphin/mtx.h"

namespace NMathF {
f32 cos(f32)
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
f32 sin(f32)
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
} // namespace NMathF

template <typename T>
struct NMath {
	void copyArray44(Mtx44, Mtx44);
	void absolute(f32);
};

#endif
