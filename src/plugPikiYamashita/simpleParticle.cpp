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
 * Address:	........
 * Size:	000150
 */
void zen::simplePtclManager::create(Texture*, short, const Vector3f&, const Vector3f&, const Vector3f&, float, float, const Colour&,
                                    const Colour&, zen::CallBack1<zen::particleMdl*>*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A226C
 * Size:	0001E0
 */
void zen::simplePtclManager::update(float)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  fmr       f31, f1
	  stfd      f30, 0x60(r1)
	  stfd      f29, 0x58(r1)
	  stfd      f28, 0x50(r1)
	  stfd      f27, 0x48(r1)
	  stmw      r27, 0x34(r1)
	  mr        r29, r3
	  lis       r28, 0x4330
	  lwz       r3, 0x0(r3)
	  lfs       f27, -0x4BF8(r2)
	  lwz       r3, 0x8(r3)
	  lfd       f28, -0x4BE8(r2)
	  lfs       f29, -0x4BF4(r2)
	  lfs       f30, -0x4BF0(r2)
	  b         .loc_0x1AC

	.loc_0x4C:
	  mr        r30, r3
	  lwz       r31, 0x8(r3)
	  lha       r3, 0x2E(r3)
	  lha       r0, 0x2C(r30)
	  addi      r3, r3, 0x1
	  cmpw      r3, r0
	  bne-      .loc_0x9C
	  mr        r3, r30
	  lwz       r27, 0x10(r29)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r27)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1A8

	.loc_0x9C:
	  lwz       r3, 0x7C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x16C

	.loc_0xC0:
	  lfs       f1, 0x34(r30)
	  lfs       f0, 0x40(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x34(r30)
	  lfs       f1, 0x38(r30)
	  lfs       f0, 0x44(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x38(r30)
	  lfs       f1, 0x3C(r30)
	  lfs       f0, 0x48(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, 0x34(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r30)
	  lfs       f1, 0x10(r30)
	  lfs       f0, 0x38(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r30)
	  lfs       f1, 0x14(r30)
	  lfs       f0, 0x3C(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r30)
	  lha       r3, 0x2E(r30)
	  lha       r0, 0x2C(r30)
	  xoris     r3, r3, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r3, 0x2C(r1)
	  stw       r0, 0x24(r1)
	  stw       r28, 0x28(r1)
	  stw       r28, 0x20(r1)
	  lfd       f1, 0x28(r1)
	  lfd       f0, 0x20(r1)
	  fsubs     f1, f1, f28
	  fsubs     f0, f0, f28
	  fdivs     f0, f1, f0
	  fsubs     f0, f27, f0
	  stfs      f0, 0x54(r30)
	  lhz       r3, 0x58(r30)
	  lha       r0, 0x5A(r30)
	  add       r0, r3, r0
	  sth       r0, 0x58(r30)

	.loc_0x16C:
	  lfs       f0, 0x30(r30)
	  fadds     f0, f0, f31
	  stfs      f0, 0x30(r30)
	  lfs       f0, 0x30(r30)
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x190
	  fadds     f0, f30, f0
	  b         .loc_0x194

	.loc_0x190:
	  fsubs     f0, f0, f30

	.loc_0x194:
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  extsh     r0, r0
	  sth       r0, 0x2E(r30)

	.loc_0x1A8:
	  mr        r3, r31

	.loc_0x1AC:
	  lwz       r0, 0x0(r29)
	  cmplw     r3, r0
	  bne+      .loc_0x4C
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lfd       f29, 0x58(r1)
	  lfd       f28, 0x50(r1)
	  lfd       f27, 0x48(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A244C
 * Size:	00028C
 */
void zen::simplePtclManager::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stfd      f29, 0x70(r1)
	  stfd      f28, 0x68(r1)
	  stmw      r24, 0x48(r1)
	  addi      r29, r4, 0
	  addi      r28, r3, 0
	  addi      r3, r29, 0
	  li        r4, 0
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x3B4(r29)
	  mr        r31, r0
	  li        r4, 0x1
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x3B4(r29)
	  mr        r30, r0
	  li        r4, 0
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r4, 0x2E4(r29)
	  lwz       r12, 0x3B4(r29)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  li        r4, 0
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x21C
	  lwz       r3, 0x0(r28)
	  addi      r26, r1, 0x30
	  lfd       f31, -0x4BD8(r2)
	  lis       r27, 0x4330
	  lwz       r25, 0x8(r3)
	  lfs       f28, -0x4BF4(r2)
	  lfs       f29, -0x4BF0(r2)
	  lfs       f30, -0x4BE0(r2)
	  b         .loc_0x210

	.loc_0xE8:
	  mr        r3, r29
	  lwz       r24, 0x8(r25)
	  lwz       r12, 0x3B4(r29)
	  li        r5, 0
	  lwz       r4, 0x78(r25)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  li        r4, 0x54
	  li        r5, 0xB
	  lwz       r12, 0x54(r12)
	  li        r6, 0x2
	  mtlr      r12
	  blrl
	  lbz       r0, 0x2B(r25)
	  lfs       f0, 0x54(r25)
	  stw       r0, 0x44(r1)
	  stw       r27, 0x40(r1)
	  lfd       f1, 0x40(r1)
	  fsubs     f1, f1, f31
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f0, f28
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x158
	  fadds     f0, f29, f0
	  b         .loc_0x15C

	.loc_0x158:
	  fsubs     f0, f0, f29

	.loc_0x15C:
	  lbz       r7, 0x2A(r25)
	  fctiwz    f0, f0
	  lbz       r6, 0x29(r25)
	  mr        r3, r29
	  lbz       r0, 0x28(r25)
	  stfd      f0, 0x40(r1)
	  addi      r4, r1, 0x3C
	  stb       r0, 0x3C(r1)
	  addi      r5, r25, 0x68
	  lwz       r0, 0x44(r1)
	  stb       r6, 0x3D(r1)
	  stb       r7, 0x3E(r1)
	  stb       r0, 0x3F(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xB0(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xC(r25)
	  mr        r3, r29
	  lfs       f0, 0x18(r25)
	  mr        r5, r26
	  lfs       f4, 0x14(r25)
	  lfs       f3, 0x20(r25)
	  fadds     f0, f1, f0
	  lfs       f2, 0x10(r25)
	  lfs       f1, 0x1C(r25)
	  fadds     f3, f4, f3
	  stfs      f0, 0x28(r1)
	  fadds     f1, f2, f1
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f3, 0x38(r1)
	  lwz       r12, 0x3B4(r29)
	  lfs       f1, 0x24(r25)
	  lfs       f0, 0x50(r25)
	  lwz       r12, 0x90(r12)
	  fmuls     f0, f1, f0
	  lhz       r0, 0x58(r25)
	  mtlr      r12
	  lwz       r4, 0x2E4(r29)
	  neg       r6, r0
	  fmuls     f1, f30, f0
	  blrl
	  mr        r25, r24

	.loc_0x210:
	  lwz       r0, 0x0(r28)
	  cmplw     r25, r0
	  bne+      .loc_0xE8

	.loc_0x21C:
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  li        r4, 0x1
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  mr        r4, r30
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lmw       r24, 0x48(r1)
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  lfd       f29, 0x70(r1)
	  lfd       f28, 0x68(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A26D8
 * Size:	00007C
 */
void zen::simplePtclManager::forceFinish()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  b         .loc_0x50

	.loc_0x20:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r31, 0x10(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x50:
	  lwz       r3, 0x0(r29)
	  lwz       r30, 0x8(r3)
	  cmplw     r3, r30
	  bne+      .loc_0x20
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}
