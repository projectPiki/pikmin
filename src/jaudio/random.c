#include "jaudio/random.h"
#include "Dolphin/os.h"

static s32 v0 = 0x0001000;
static s32 v1 = 0x0005555;

#define V0_MULT (s32)0x13579BDE
#define V1_MULT (s32)0x98765432

/**
 * @TODO: Documentation
 */
s32 GetRandom_s32()
{
	BOOL level = OSDisableInterrupts();
	s32 tmp;

	tmp = (v1 * V1_MULT) + ((v0 * V0_MULT) >> 4);
	v0  = v1;
	v1  = ++tmp;
	OSRestoreInterrupts(level);
	return tmp;
}

/**
 * @TODO: Documentation
 */
u32 GetRandom_u32()
{
	return GetRandom_s32() & ~0x80000000;
}

/**
 * @TODO: Documentation
 */
u32 GetRandom_ulimit(u32 limit)
{
	return GetRandom_u32() % limit;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void GetRandom_slimit(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
f32 GetRandom_sf32()
{
	s32 rand  = GetRandom_s32();
	s32 piece = rand & 0xFFFFFF;
	f32 frand = f32(piece) / 16777215.0f;
	if (rand < 0) {
		frand = -frand;
	}
	return frand;
}
