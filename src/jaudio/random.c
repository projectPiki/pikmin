#include "jaudio/random.h"
#include "Dolphin/os.h"

static s32 v0 = 0x0001000;
static s32 v1 = 0x0005555;

#define V0_MULT (s32)0x13579BDE
#define V1_MULT (s32)0x98765432

#pragma dont_inline on

/*
 * --INFO--
 * Address:	8000D740
 * Size:	000064
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

/*
 * --INFO--
 * Address:	8000D7C0
 * Size:	000024
 */
u32 GetRandom_u32() { return GetRandom_s32() & ~0x80000000; }

/*
 * --INFO--
 * Address:	8000D800
 * Size:	000038
 */
u32 GetRandom_ulimit(u32 limit) { return GetRandom_u32() % limit; }

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void GetRandom_slimit(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000D840
 * Size:	000054
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
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  bl        -0x10C
	  rlwinm    r4,r3,0,8,31
	  lis       r0, 0x4330
	  xoris     r4, r4, 0x8000
	  lfd       f2, -0x7F68(r2)
	  stw       r4, 0x14(r1)
	  cmpwi     r3, 0
	  lfs       f0, -0x7F70(r2)
	  stw       r0, 0x10(r1)
	  lfd       f1, 0x10(r1)
	  fsubs     f1, f1, f2
	  fdivs     f1, f1, f0
	  bge-      .loc_0x44
	  fneg      f1, f1

	.loc_0x44:
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

#pragma dont_inline reset
