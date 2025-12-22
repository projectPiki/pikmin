#include "jaudio/ja_calc.h"

#include "Dolphin/math.h"
#include "jaudio/ja_calc.h"
#include "std/Math.h"
#include "stl/math.h"

#define SINTABLE_LENGTH (257)
static f32 SINTABLE[SINTABLE_LENGTH];

f32 sqrtf2(f32 x)
{
	return std::sqrtf(x);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void cosf2(f32)
{
	// UNUSED FUNCTION
}

f32 atanf2(f32 x, f32 y)
{
	return atan2(x, y);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void sinf2(f32)
{
	// UNUSED FUNCTION
}

void Jac_InitSinTable()
{
	for (u32 i = 0; i < SINTABLE_LENGTH; i++) {
		SINTABLE[i] = sinf(i * HALF_PI / 256.0f);
	}
}

f32 sinf3(f32 x)
{
	return SINTABLE[(int)(256.0f * x)];
}
