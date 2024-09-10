#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D95C
 * Size:	000084
 */
NCamera::NCamera(Camera*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0x8
	  bl        -0xB28
	  addi      r3, r30, 0x14
	  bl        -0xB30
	  stw       r31, 0x4(r30)
	  mr        r3, r30
	  lfs       f0, -0x1CC8(r13)
	  stfs      f0, 0x8(r30)
	  lfs       f0, -0x1CC4(r13)
	  stfs      f0, 0xC(r30)
	  lfs       f0, -0x1CC0(r13)
	  stfs      f0, 0x10(r30)
	  lfs       f0, -0x1CBC(r13)
	  stfs      f0, 0x14(r30)
	  lfs       f0, -0x1CB8(r13)
	  stfs      f0, 0x18(r30)
	  lfs       f0, -0x1CB4(r13)
	  stfs      f0, 0x1C(r30)
	  lfs       f0, -0x5FC8(r2)
	  stfs      f0, 0x0(r30)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011D9E0
 * Size:	0000D0
 */
void NCamera::makeMatrix()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stw       r31, 0x9C(r1)
	  stw       r30, 0x98(r1)
	  stw       r29, 0x94(r1)
	  addi      r29, r3, 0
	  addi      r31, r29, 0x14
	  addi      r30, r29, 0x8
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x80
	  bl        -0xAE4
	  addi      r3, r1, 0x80
	  bl        -0x918
	  addi      r3, r1, 0x68
	  addi      r4, r1, 0x80
	  bl        -0x1AD8
	  addi      r3, r1, 0x68
	  bl        -0x1A18
	  lfs       f0, 0x74(r1)
	  addi      r3, r1, 0x4C
	  addi      r4, r1, 0x80
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x7C(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x0(r29)
	  bl        -0x1DD4
	  addi      r3, r1, 0xC
	  bl        -0x105C
	  addi      r3, r1, 0xC
	  addi      r4, r1, 0x4C
	  bl        -0xD98
	  addi      r3, r1, 0xC
	  addi      r4, r1, 0x5C
	  bl        -0xDD0
	  addi      r3, r1, 0x5C
	  bl        -0x97C
	  lwz       r3, 0x4(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  addi      r6, r1, 0x5C
	  bl        -0xDAA84
	  lwz       r0, 0xA4(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  lwz       r29, 0x94(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011DAB0
 * Size:	000098
 */
void NCamera::makeCamera()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  addi      r4, r31, 0x14
	  lwz       r5, 0x4(r3)
	  addi      r3, r1, 0x18
	  lfs       f0, 0x8(r31)
	  addi      r6, r5, 0x164
	  stfs      f0, 0x164(r5)
	  addi      r5, r31, 0x8
	  lfs       f0, 0xC(r31)
	  stfs      f0, 0x4(r6)
	  lfs       f0, 0x10(r31)
	  stfs      f0, 0x8(r6)
	  bl        -0xBC4
	  addi      r3, r1, 0xC
	  addi      r4, r1, 0x18
	  bl        -0x171C
	  lfs       f1, -0x1CA4(r13)
	  lfs       f0, -0x5FC4(r2)
	  lfs       f2, 0x10(r1)
	  fmuls     f0, f1, f0
	  lwz       r3, 0x4(r31)
	  fsubs     f0, f2, f0
	  stfs      f0, 0x320(r3)
	  lfs       f0, 0x14(r1)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x324(r3)
	  lfs       f0, -0x5FC8(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x328(r3)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
