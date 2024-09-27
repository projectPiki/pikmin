#include "types.h"

/*
 * --INFO--
 * Address:	8021B730
 * Size:	0001F4
 */
void atanf(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x10(r1)
	  lis       r3, 0x8022
	  addi      r4, r3, 0x2C40
	  stfs      f1, 0x8(r1)
	  li        r6, -0x1
	  lfs       f0, -0x3A10(r2)
	  li        r7, 0
	  lwz       r3, 0x8(r1)
	  rlwinm    r0,r3,0,1,31
	  stw       r0, 0x8(r1)
	  rlwinm    r8,r3,0,0,0
	  lfs       f2, 0x8(r1)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x50
	  lfs       f0, -0x3A0C(r2)
	  li        r7, 0x1
	  fdivs     f0, f0, f2
	  stfs      f0, 0xC(r1)
	  b         .loc_0x140

	.loc_0x50:
	  lfs       f0, -0x3A08(r2)
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x13C
	  lwz       r5, 0x8(r1)
	  lis       r0, 0x3F80
	  li        r6, 0
	  rlwinm    r3,r5,0,1,8
	  cmpw      r3, r0
	  beq-      .loc_0xC4
	  bge-      .loc_0x88
	  lis       r0, 0x3F00
	  cmpw      r3, r0
	  beq-      .loc_0x98
	  b         .loc_0xF8

	.loc_0x88:
	  lis       r0, 0x4000
	  cmpw      r3, r0
	  beq-      .loc_0xF4
	  b         .loc_0xF8

	.loc_0x98:
	  lis       r3, 0x3F09
	  subi      r0, r3, 0x2A47
	  cmpw      r5, r0
	  blt-      .loc_0xAC
	  li        r6, 0x1

	.loc_0xAC:
	  lis       r3, 0x3F52
	  addi      r0, r3, 0x1801
	  cmpw      r5, r0
	  blt-      .loc_0xF8
	  addi      r6, r6, 0x1
	  b         .loc_0xF8

	.loc_0xC4:
	  lis       r3, 0x3F9C
	  subi      r0, r3, 0x814
	  cmpw      r5, r0
	  li        r6, 0x2
	  blt-      .loc_0xDC
	  li        r6, 0x3

	.loc_0xDC:
	  lis       r3, 0x3FEF
	  addi      r0, r3, 0x789E
	  cmpw      r5, r0
	  blt-      .loc_0xF8
	  addi      r6, r6, 0x1
	  b         .loc_0xF8

	.loc_0xF4:
	  li        r6, 0x4

	.loc_0xF8:
	  rlwinm    r0,r6,2,0,29
	  lfs       f1, -0x3A0C(r2)
	  add       r3, r4, r0
	  lfs       f3, 0x9C(r3)
	  lfs       f4, 0x84(r3)
	  fadds     f0, f2, f3
	  fadds     f0, f4, f0
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC(r1)
	  lfs       f2, 0xC(r1)
	  lfs       f1, 0x1C(r3)
	  lfs       f0, 0x34(r3)
	  fnmsubs   f1, f2, f1, f4
	  fnmsubs   f0, f2, f0, f3
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r1)
	  b         .loc_0x140

	.loc_0x13C:
	  stfs      f2, 0xC(r1)

	.loc_0x140:
	  lfs       f5, 0xC(r1)
	  rlwinm    r0,r6,2,0,29
	  lfs       f2, 0x18(r4)
	  add       r3, r4, r0
	  fmuls     f6, f5, f5
	  lfs       f1, 0x14(r4)
	  cmpwi     r7, 0
	  lfs       f0, 0x10(r4)
	  fmadds    f3, f6, f2, f1
	  lfs       f2, 0xC(r4)
	  fmuls     f4, f5, f6
	  lfs       f1, 0x8(r4)
	  fmadds    f3, f6, f3, f0
	  lfs       f0, 0x4(r4)
	  fmadds    f2, f6, f3, f2
	  fmadds    f1, f6, f2, f1
	  fmadds    f0, f6, f1, f0
	  fmadds    f0, f4, f0, f5
	  stfs      f0, 0xC(r1)
	  lfs       f1, 0xC(r1)
	  lfs       f0, 0x6C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r1)
	  lfs       f1, 0xC(r1)
	  lfs       f0, 0x50(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r1)
	  beq-      .loc_0x1DC
	  lfs       f1, 0xC(r1)
	  cmpwi     r8, 0
	  lfs       f0, -0x3A04(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC(r1)
	  beq-      .loc_0x1D0
	  lfs       f1, 0xC(r1)
	  b         .loc_0x1EC

	.loc_0x1D0:
	  lfs       f0, 0xC(r1)
	  fneg      f1, f0
	  b         .loc_0x1EC

	.loc_0x1DC:
	  lwz       r0, 0xC(r1)
	  or        r0, r0, r8
	  stw       r0, 0xC(r1)
	  lfs       f1, 0xC(r1)

	.loc_0x1EC:
	  addi      r1, r1, 0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void asinf(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021B924
 * Size:	000020
 */
void atan(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x200
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021B944
 * Size:	000070
 */
void _inv_sqrtf(void)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x3A00(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x50
	  fsqrte    f2, f1
	  lfs       f4, -0x39FC(r2)
	  lfs       f3, -0x39F8(r2)
	  frsp      f2, f2
	  fmuls     f0, f2, f2
	  fmuls     f2, f4, f2
	  fnmsubs   f0, f1, f0, f3
	  fmuls     f2, f2, f0
	  fmuls     f0, f2, f2
	  fmuls     f2, f4, f2
	  fnmsubs   f0, f1, f0, f3
	  fmuls     f2, f2, f0
	  fmuls     f0, f2, f2
	  fmuls     f2, f4, f2
	  fnmsubs   f0, f1, f0, f3
	  fmuls     f1, f2, f0
	  blr

	.loc_0x50:
	  fcmpu     cr0, f1, f0
	  beq-      .loc_0x64
	  lis       r3, 0x802F
	  lfs       f1, -0x6B88(r3)
	  blr

	.loc_0x64:
	  lis       r3, 0x802F
	  lfs       f1, -0x6B84(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021B9B4
 * Size:	000044
 */
void acosf(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stfd      f31, 0x10(r1)
	  fmr       f31, f1
	  lfs       f0, -0x3A0C(r2)
	  fnmsubs   f1, f31, f31, f0
	  bl        -0x8C
	  fmuls     f1, f31, f1
	  bl        -0xB4
	  lfs       f0, -0x3A04(r2)
	  lwz       r0, 0x1C(r1)
	  fsubs     f1, f0, f1
	  lfd       f31, 0x10(r1)
	  mtlr      r0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021B9F8
 * Size:	0000D8
 */
f32 atan2f(f32 __x, f32 __y)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stfs      f1, 0x8(r1)
	  stfs      f2, 0xC(r1)
	  lwz       r0, 0x8(r1)
	  lwz       r3, 0xC(r1)
	  rlwinm    r4,r0,0,0,0
	  rlwinm    r0,r3,0,0,0
	  cmpw      r0, r4
	  bne-      .loc_0x78
	  cmpwi     r0, 0
	  beq-      .loc_0x50
	  lfs       f1, 0x8(r1)
	  lfs       f0, 0xC(r1)
	  fdivs     f1, f1, f0
	  bl        -0x308
	  lfs       f0, -0x39F4(r2)
	  fsubs     f1, f1, f0
	  b         .loc_0xC8

	.loc_0x50:
	  lfs       f1, 0xC(r1)
	  lfs       f0, -0x3A00(r2)
	  fcmpu     cr0, f1, f0
	  beq-      .loc_0x70
	  lfs       f0, 0x8(r1)
	  fdivs     f1, f0, f1
	  bl        -0x330
	  b         .loc_0xC8

	.loc_0x70:
	  lfs       f1, -0x3A04(r2)
	  b         .loc_0xC8

	.loc_0x78:
	  lfs       f1, 0xC(r1)
	  lfs       f0, -0x3A00(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xA0
	  lfs       f0, 0x8(r1)
	  fdivs     f1, f0, f1
	  bl        -0x358
	  lfs       f0, -0x39F4(r2)
	  fadds     f1, f0, f1
	  b         .loc_0xC8

	.loc_0xA0:
	  fcmpu     cr0, f1, f0
	  beq-      .loc_0xB8
	  lfs       f0, 0x8(r1)
	  fdivs     f1, f0, f1
	  bl        -0x378
	  b         .loc_0xC8

	.loc_0xB8:
	  addis     r3, r4, 0x3FC9
	  addi      r0, r3, 0xFDB
	  stw       r0, 0x8(r1)
	  lfs       f1, 0x8(r1)

	.loc_0xC8:
	  lwz       r0, 0x14(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}
