#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801ACC54
 * Size:	000024
 */
TAIAmotion::TAIAmotion(int, int)
{
	/*
	.loc_0x0:
	  lis       r6, 0x802C
	  addi      r0, r6, 0x6620
	  stw       r0, 0x4(r3)
	  lis       r6, 0x802E
	  subi      r0, r6, 0x31C
	  stw       r4, 0x0(r3)
	  stw       r0, 0x4(r3)
	  stw       r5, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ACC78
 * Size:	00004C
 */
void TAIAmotion::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr.       r31, r4
	  addi      r5, r31, 0
	  beq-      .loc_0x20
	  lwz       r5, 0x2C0(r31)

	.loc_0x20:
	  lwz       r4, 0x8(r3)
	  addi      r3, r1, 0x10
	  bl        -0x8DD14
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8DAEC
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ACCC4
 * Size:	00001C
 */
void TAIAmotion::act(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ACCE0
 * Size:	000024
 */
TAIAreserveMotion::TAIAreserveMotion(int, int)
{
	/*
	.loc_0x0:
	  lis       r6, 0x802C
	  addi      r0, r6, 0x6620
	  stw       r0, 0x4(r3)
	  lis       r6, 0x802E
	  subi      r0, r6, 0x344
	  stw       r4, 0x0(r3)
	  stw       r0, 0x4(r3)
	  stw       r5, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ACD04
 * Size:	0001B4
 */
void TAIAreserveMotion::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r4
	  stw       r30, 0x68(r1)
	  mr        r30, r3
	  lwz       r5, 0x2CC(r4)
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x44(r5)
	  cmpw      r4, r0
	  beq-      .loc_0xF4
	  cmpwi     r0, 0
	  bge-      .loc_0x64
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x4C
	  lwz       r5, 0x2C0(r31)

	.loc_0x4C:
	  addi      r3, r1, 0x54
	  bl        -0x8DDC8
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8DBA0
	  b         .loc_0x198

	.loc_0x64:
	  lwz       r3, 0x28(r5)
	  lis       r0, 0x4330
	  lfd       f1, -0x49F0(r2)
	  lwz       r3, 0x68(r3)
	  lfs       f2, 0x2C(r5)
	  lwz       r3, 0x30(r3)
	  subi      r3, r3, 0x2
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x64(r1)
	  stw       r0, 0x60(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xC8
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0xB0
	  lwz       r5, 0x2C0(r31)

	.loc_0xB0:
	  addi      r3, r1, 0x4C
	  bl        -0x8DE2C
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8DC04
	  b         .loc_0x198

	.loc_0xC8:
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0xD8
	  lwz       r5, 0x2C0(r31)

	.loc_0xD8:
	  addi      r3, r1, 0x44
	  li        r4, -0x1
	  bl        -0x8DE58
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8DBC0
	  b         .loc_0x198

	.loc_0xF4:
	  lwz       r3, 0x28(r5)
	  lis       r0, 0x4330
	  lfd       f1, -0x49F0(r2)
	  lwz       r3, 0x68(r3)
	  lfs       f2, 0x2C(r5)
	  lwz       r3, 0x30(r3)
	  subi      r3, r3, 0x2
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x64(r1)
	  stw       r0, 0x60(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x154
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x140
	  lwz       r5, 0x2C0(r31)

	.loc_0x140:
	  addi      r3, r1, 0x3C
	  bl        -0x8DEBC
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8DC94

	.loc_0x154:
	  lwz       r3, 0x2CC(r31)
	  lbz       r0, 0x48(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x198
	  cmplwi    r31, 0
	  lfs       f31, 0x2C(r3)
	  mr        r5, r31
	  beq-      .loc_0x178
	  lwz       r5, 0x2C0(r31)

	.loc_0x178:
	  lwz       r4, 0x8(r30)
	  addi      r3, r1, 0x34
	  bl        -0x8DEF8
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8DCD0
	  lwz       r3, 0x2CC(r31)
	  stfs      f31, 0x2C(r3)

	.loc_0x198:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ACEB8
 * Size:	000088
 */
void TAIAreserveMotion::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  lwz       r4, 0x8(r3)
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x44(r3)
	  cmpw      r4, r0
	  beq-      .loc_0x70
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x68
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x44
	  lwz       r5, 0x2C0(r31)

	.loc_0x44:
	  addi      r3, r1, 0x1C
	  bl        -0x8DF74
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x8DD4C
	  li        r0, 0x9
	  stw       r0, 0x3A8(r31)
	  li        r3, 0x1
	  b         .loc_0x74

	.loc_0x68:
	  li        r3, 0
	  b         .loc_0x74

	.loc_0x70:
	  li        r3, 0x1

	.loc_0x74:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ACF40
 * Size:	000034
 */
void TAIAmotionLoop::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x250
	  lfs       f0, -0x49E8(r2)
	  stfs      f0, 0x478(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ACF74
 * Size:	000118
 */
void TAIAmotionLoop::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  li        r31, 0
	  stw       r30, 0x48(r1)
	  mr        r30, r4
	  stw       r29, 0x44(r1)
	  mr        r29, r3
	  lwz       r5, 0x2CC(r4)
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x44(r5)
	  cmpw      r4, r0
	  beq-      .loc_0x84
	  lwz       r0, 0x38(r5)
	  cmpwi     r0, 0
	  bge-      .loc_0x7C
	  cmplwi    r30, 0
	  addi      r5, r30, 0
	  beq-      .loc_0x58
	  lwz       r5, 0x2C0(r30)

	.loc_0x58:
	  addi      r3, r1, 0x2C
	  bl        -0x8E044
	  mr        r4, r3
	  lwz       r3, 0x2CC(r30)
	  bl        -0x8DE1C
	  li        r0, 0x9
	  stw       r0, 0x3A8(r30)
	  li        r0, 0x1
	  b         .loc_0x88

	.loc_0x7C:
	  li        r0, 0
	  b         .loc_0x88

	.loc_0x84:
	  li        r0, 0x1

	.loc_0x88:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xF4
	  lwz       r5, 0x2DEC(r13)
	  mr        r3, r29
	  lfs       f1, 0x478(r30)
	  mr        r4, r30
	  lfs       f0, 0x28C(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x478(r30)
	  lwz       r12, 0x4(r29)
	  lfs       f31, 0x478(r30)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  fcmpo     cr0, f31, f1
	  ble-      .loc_0xF4
	  cmplwi    r30, 0
	  addi      r5, r30, 0
	  li        r31, 0x1
	  beq-      .loc_0xDC
	  lwz       r5, 0x2C0(r30)

	.loc_0xDC:
	  addi      r3, r1, 0x34
	  li        r4, -0x1
	  bl        -0x8E0CC
	  mr        r4, r3
	  lwz       r3, 0x2CC(r30)
	  bl        -0x8DE34

	.loc_0xF4:
	  mr        r3, r31
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AD08C
 * Size:	000008
 */
void TAIAmotionLoop::getFrameMax(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0xC(r3)
	  blr
	*/
}
