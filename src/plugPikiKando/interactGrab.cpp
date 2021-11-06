#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007C89C
 * Size:	00003C
 */
void InteractGrab::actCommon(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r4
  lwz       r4, 0x4(r3)
  mr        r3, r31
  bl        0xDFE4
  lwz       r0, 0x6C(r31)
  cmpwi     r0, 0xE
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007C8D8
 * Size:	000120
 */
void InteractRelease::actCommon(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB8(r1)
  stfd      f31, 0xB0(r1)
  stfd      f30, 0xA8(r1)
  stfd      f29, 0xA0(r1)
  stw       r31, 0x9C(r1)
  addi      r31, r4, 0
  stw       r30, 0x98(r1)
  addi      r30, r3, 0
  addi      r3, r31, 0
  bl        0xE0D0
  lwz       r4, 0x4(r30)
  mr        r5, r31
  lfs       f0, -0x6358(r13)
  addi      r3, r1, 0x60
  lfsu      f1, 0x70(r4)
  lfs       f2, -0x76A8(r2)
  fadds     f1, f1, f0
  lfs       f0, -0x6354(r13)
  stfs      f1, 0x48(r1)
  lfs       f1, 0x48(r1)
  stfs      f1, 0x88(r1)
  lfs       f1, 0x8(r30)
  lfs       f3, 0x4(r4)
  fmuls     f1, f2, f1
  fadds     f1, f3, f1
  stfs      f1, 0x8C(r1)
  lfs       f1, 0x8(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x90(r1)
  lwz       r4, 0x88(r1)
  lwz       r0, 0x8C(r1)
  stw       r4, 0x70(r31)
  stw       r0, 0x74(r31)
  lwz       r0, 0x90(r1)
  stw       r0, 0x78(r31)
  lwz       r4, 0x4(r30)
  lfs       f31, -0x6350(r13)
  lwz       r12, 0x0(r4)
  lfs       f30, -0x634C(r13)
  lwz       r12, 0x100(r12)
  lfs       f29, -0x6348(r13)
  mtlr      r12
  blrl      
  lfs       f0, 0x60(r1)
  li        r3, 0x1
  lfs       f1, 0x64(r1)
  fadds     f2, f0, f31
  lfs       f0, 0x68(r1)
  fadds     f1, f1, f30
  fadds     f0, f0, f29
  stfs      f2, 0x3C(r1)
  lfs       f2, 0x3C(r1)
  stfs      f2, 0x6C(r1)
  stfs      f1, 0x70(r1)
  stfs      f0, 0x74(r1)
  lwz       r4, 0x6C(r1)
  lwz       r0, 0x70(r1)
  stw       r4, 0x94(r31)
  stw       r0, 0x98(r31)
  lwz       r0, 0x74(r1)
  stw       r0, 0x9C(r31)
  lwz       r0, 0xBC(r1)
  lfd       f31, 0xB0(r1)
  lfd       f30, 0xA8(r1)
  lfd       f29, 0xA0(r1)
  lwz       r31, 0x9C(r1)
  lwz       r30, 0x98(r1)
  addi      r1, r1, 0xB8
  mtlr      r0
  blr
*/
}
