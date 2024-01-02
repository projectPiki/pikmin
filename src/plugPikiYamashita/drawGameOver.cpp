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
 * Address:	801E8900
 * Size:	000334
 */
zen::DrawGameOver::DrawGameOver()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  addi      r30, r3, 0
	  li        r3, 0xC
	  stw       r29, 0x5C(r1)
	  stw       r28, 0x58(r1)
	  bl        -0x1A1920
	  mr.       r31, r3
	  beq-      .loc_0x188
	  li        r3, 0x100
	  bl        -0x1A1930
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x5C
	  lis       r4, 0x802E
	  addi      r4, r4, 0x5A50
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x293E4

	.loc_0x5C:
	  stw       r28, 0x0(r31)
	  li        r0, 0
	  addi      r3, r1, 0x4C
	  crclr     6, 0x6
	  stw       r0, 0x4(r31)
	  addi      r4, r13, 0x2688
	  lwz       r5, 0x4(r31)
	  bl        0x2DC20
	  b         .loc_0xA0

	.loc_0x80:
	  lwz       r5, 0x4(r31)
	  addi      r3, r1, 0x4C
	  crclr     6, 0x6
	  addi      r4, r13, 0x2688
	  addi      r0, r5, 0x1
	  stw       r0, 0x4(r31)
	  lwz       r5, 0x4(r31)
	  bl        0x2DBFC

	.loc_0xA0:
	  lwz       r3, 0x0(r31)
	  li        r5, 0
	  lwzu      r12, 0x4(r3)
	  lbz       r0, 0x4D(r1)
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x4C(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x4E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x4F(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  cmplwi    r3, 0
	  bne+      .loc_0x80
	  lwz       r28, 0x4(r31)
	  mulli     r3, r28, 0x30
	  addi      r3, r3, 0x8
	  bl        -0x1A19E8
	  lis       r4, 0x801F
	  subi      r4, r4, 0x7270
	  addi      r7, r28, 0
	  li        r5, 0
	  li        r6, 0x30
	  bl        0x2C224
	  li        r29, 0
	  stw       r3, 0x8(r31)
	  mulli     r28, r29, 0x30
	  b         .loc_0x17C

	.loc_0x118:
	  addi      r5, r29, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x4C
	  addi      r4, r13, 0x2688
	  bl        0x2DB70
	  lwz       r3, 0x0(r31)
	  li        r5, 0x1
	  lwzu      r12, 0x4(r3)
	  lbz       r0, 0x4D(r1)
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x4C(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x4E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x4F(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lwz       r0, 0x8(r31)
	  addi      r4, r3, 0
	  add       r3, r0, r28
	  bl        .loc_0x334
	  addi      r28, r28, 0x30
	  addi      r29, r29, 0x1

	.loc_0x17C:
	  lwz       r0, 0x4(r31)
	  cmpw      r29, r0
	  blt+      .loc_0x118

	.loc_0x188:
	  stw       r31, 0x4(r30)
	  li        r3, 0xC
	  bl        -0x1A1A8C
	  mr.       r31, r3
	  beq-      .loc_0x2F4
	  li        r3, 0x100
	  bl        -0x1A1A9C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x1C8
	  lis       r4, 0x802E
	  addi      r4, r4, 0x5A68
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x29550

	.loc_0x1C8:
	  stw       r28, 0x0(r31)
	  li        r0, 0
	  addi      r3, r1, 0x44
	  crclr     6, 0x6
	  stw       r0, 0x4(r31)
	  addi      r4, r13, 0x2688
	  lwz       r5, 0x4(r31)
	  bl        0x2DAB4
	  b         .loc_0x20C

	.loc_0x1EC:
	  lwz       r5, 0x4(r31)
	  addi      r3, r1, 0x44
	  crclr     6, 0x6
	  addi      r4, r13, 0x2688
	  addi      r0, r5, 0x1
	  stw       r0, 0x4(r31)
	  lwz       r5, 0x4(r31)
	  bl        0x2DA90

	.loc_0x20C:
	  lwz       r3, 0x0(r31)
	  li        r5, 0
	  lwzu      r12, 0x4(r3)
	  lbz       r0, 0x45(r1)
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x44(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x46(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x47(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  cmplwi    r3, 0
	  bne+      .loc_0x1EC
	  lwz       r28, 0x4(r31)
	  mulli     r3, r28, 0x30
	  addi      r3, r3, 0x8
	  bl        -0x1A1B54
	  lis       r4, 0x801F
	  subi      r4, r4, 0x7270
	  addi      r7, r28, 0
	  li        r5, 0
	  li        r6, 0x30
	  bl        0x2C0B8
	  li        r29, 0
	  stw       r3, 0x8(r31)
	  mulli     r28, r29, 0x30
	  b         .loc_0x2E8

	.loc_0x284:
	  addi      r5, r29, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x44
	  addi      r4, r13, 0x2688
	  bl        0x2DA04
	  lwz       r3, 0x0(r31)
	  li        r5, 0x1
	  lwzu      r12, 0x4(r3)
	  lbz       r0, 0x45(r1)
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x44(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x46(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x47(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lwz       r0, 0x8(r31)
	  addi      r4, r3, 0
	  add       r3, r0, r28
	  bl        .loc_0x334
	  addi      r28, r28, 0x30
	  addi      r29, r29, 0x1

	.loc_0x2E8:
	  lwz       r0, 0x4(r31)
	  cmpw      r29, r0
	  blt+      .loc_0x284

	.loc_0x2F4:
	  stw       r31, 0x8(r30)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r0, 0x0(r30)
	  stw       r0, 0x10(r30)
	  lfs       f0, -0x4058(r2)
	  stfs      f0, 0x14(r30)
	  stw       r0, 0xC(r30)
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  lwz       r28, 0x58(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr

	.loc_0x334:
	*/
}

/*
 * --INFO--
 * Address:	801E8C34
 * Size:	00015C
 */
void zen::DrawGameOverLetter::init(P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r3, 0
	  lhz       r0, 0x8(r4)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x148
	  stw       r4, 0xC(r31)
	  li        r3, 0
	  lis       r0, 0x4330
	  lwz       r4, 0xC(r31)
	  lha       r4, 0x18(r4)
	  stw       r4, 0x10(r31)
	  lwz       r4, 0xC(r31)
	  lha       r4, 0x1A(r4)
	  stw       r4, 0x14(r31)
	  stw       r3, 0x0(r31)
	  lfs       f3, -0x4058(r2)
	  stfs      f3, 0x4(r31)
	  stfs      f3, 0x8(r31)
	  lfs       f0, -0x4054(r2)
	  stfs      f0, 0x18(r31)
	  lwz       r3, 0x14(r31)
	  lfd       f2, -0x4038(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f0, -0x4050(r2)
	  stw       r3, 0x4C(r1)
	  stw       r0, 0x48(r1)
	  lfd       f1, 0x48(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1C(r31)
	  lfs       f1, 0x1C(r31)
	  fcmpo     cr0, f1, f3
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xA0
	  lfs       f0, -0x404C(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xA8

	.loc_0xA0:
	  lfs       f0, -0x404C(r2)
	  fsubs     f0, f1, f0

	.loc_0xA8:
	  lfs       f2, 0x18(r31)
	  fctiwz    f1, f0
	  lfs       f0, -0x4058(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0x48(r1)
	  lwz       r5, 0x4C(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xD4
	  lfs       f0, -0x404C(r2)
	  fadds     f0, f0, f2
	  b         .loc_0xDC

	.loc_0xD4:
	  lfs       f0, -0x404C(r2)
	  fsubs     f0, f2, f0

	.loc_0xDC:
	  lwz       r3, 0xC(r31)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x48(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x4C(r1)
	  mtlr      r12
	  blrl
	  bl        0x2F340
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4038(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x4044(r2)
	  stw       r0, 0x40(r1)
	  lfs       f1, -0x4048(r2)
	  lfd       f3, 0x40(r1)
	  lfs       f0, -0x4040(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lfs       f0, -0x4058(r2)
	  stfs      f0, 0x24(r31)
	  stfs      f0, 0x28(r31)
	  stfs      f0, 0x2C(r31)

	.loc_0x148:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E8D90
 * Size:	00003C
 */
zen::DrawGameOverLetter::DrawGameOverLetter()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  stw       r0, 0xC(r3)
	  stw       r0, 0x10(r3)
	  stw       r0, 0x14(r3)
	  lfs       f0, -0x4058(r2)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x24(r3)
	  stfs      f0, 0x28(r3)
	  stfs      f0, 0x2C(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E8DCC
 * Size:	0000E8
 */
void zen::DrawGameOver::start(zen::DrawGameOver::modeFlag, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stfd      f29, 0x38(r1)
	  stmw      r26, 0x20(r1)
	  stw       r0, 0x0(r3)
	  stw       r4, 0x10(r3)
	  stfs      f1, 0x18(r3)
	  lwz       r0, 0x10(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x54
	  bge-      .loc_0x5C
	  cmpwi     r0, 0
	  bge-      .loc_0x48
	  b         .loc_0x5C

	.loc_0x48:
	  lwz       r0, 0x4(r3)
	  stw       r0, 0xC(r3)
	  b         .loc_0x5C

	.loc_0x54:
	  lwz       r0, 0x8(r3)
	  stw       r0, 0xC(r3)

	.loc_0x5C:
	  li        r29, 0
	  lwz       r28, 0xC(r3)
	  lfs       f29, -0x4058(r2)
	  mr        r26, r29
	  lfs       f30, -0x4030(r2)
	  li        r30, 0x1
	  lfd       f31, -0x4038(r2)
	  lis       r31, 0x4330
	  b         .loc_0xBC

	.loc_0x80:
	  lwz       r0, 0x8(r28)
	  add       r27, r0, r26
	  addi      r3, r27, 0
	  bl        .loc_0xE8
	  xoris     r0, r29, 0x8000
	  stw       r30, 0x0(r27)
	  addi      r26, r26, 0x30
	  stw       r0, 0x1C(r1)
	  addi      r29, r29, 0x1
	  stw       r31, 0x18(r1)
	  lfd       f0, 0x18(r1)
	  stfs      f29, 0x4(r27)
	  fsubs     f0, f0, f31
	  fmuls     f0, f30, f0
	  stfs      f0, 0x8(r27)

	.loc_0xBC:
	  lwz       r0, 0x4(r28)
	  cmpw      r29, r0
	  blt+      .loc_0x80
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lfd       f29, 0x38(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr

	.loc_0xE8:
	*/
}

/*
 * --INFO--
 * Address:	801E8EB4
 * Size:	000134
 */
void zen::DrawGameOverLetter::initParams()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x0(r3)
	  lis       r0, 0x4330
	  lfs       f3, -0x4058(r2)
	  stfs      f3, 0x4(r3)
	  stfs      f3, 0x8(r3)
	  lfs       f0, -0x4054(r2)
	  stfs      f0, 0x18(r3)
	  lwz       r3, 0x14(r3)
	  lfd       f2, -0x4038(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f0, -0x4050(r2)
	  stw       r3, 0x2C(r1)
	  stw       r0, 0x28(r1)
	  lfd       f1, 0x28(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1C(r31)
	  lfs       f1, 0x1C(r31)
	  fcmpo     cr0, f1, f3
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x78
	  lfs       f0, -0x404C(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x80

	.loc_0x78:
	  lfs       f0, -0x404C(r2)
	  fsubs     f0, f1, f0

	.loc_0x80:
	  lfs       f2, 0x18(r31)
	  fctiwz    f1, f0
	  lfs       f0, -0x4058(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0x28(r1)
	  lwz       r5, 0x2C(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xAC
	  lfs       f0, -0x404C(r2)
	  fadds     f0, f0, f2
	  b         .loc_0xB4

	.loc_0xAC:
	  lfs       f0, -0x404C(r2)
	  fsubs     f0, f2, f0

	.loc_0xB4:
	  lwz       r3, 0xC(r31)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x28(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x2C(r1)
	  mtlr      r12
	  blrl
	  bl        0x2F0E8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4038(r2)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x4044(r2)
	  stw       r0, 0x20(r1)
	  lfs       f1, -0x4048(r2)
	  lfd       f3, 0x20(r1)
	  lfs       f0, -0x4040(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lfs       f0, -0x4058(r2)
	  stfs      f0, 0x24(r31)
	  stfs      f0, 0x28(r31)
	  stfs      f0, 0x2C(r31)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E8FE8
 * Size:	000118
 */
void zen::DrawGameOver::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  stw       r28, 0x20(r1)
	  li        r28, 0
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0xF4
	  lwz       r5, 0x2DEC(r13)
	  lfs       f1, 0x14(r3)
	  lfs       f0, 0x28C(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r3)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x80
	  bge-      .loc_0xB0
	  cmpwi     r0, 0x1
	  bge-      .loc_0x5C
	  b         .loc_0xB0

	.loc_0x5C:
	  lfs       f1, 0x14(r3)
	  lfs       f0, -0x402C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xB0
	  li        r0, 0x2
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x4058(r2)
	  stfs      f0, 0x14(r3)
	  b         .loc_0xB0

	.loc_0x80:
	  lis       r5, 0x100
	  lwz       r4, 0x28(r4)
	  addi      r0, r5, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0x98
	  li        r28, 0x1

	.loc_0x98:
	  lfs       f0, 0x14(r3)
	  lfs       f1, 0x18(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0xB0
	  stfs      f1, 0x14(r3)
	  li        r28, 0x1

	.loc_0xB0:
	  li        r31, 0
	  lwz       r30, 0xC(r3)
	  mulli     r29, r31, 0x30
	  b         .loc_0xD4

	.loc_0xC0:
	  lwz       r0, 0x8(r30)
	  add       r3, r0, r29
	  bl        .loc_0x118
	  addi      r29, r29, 0x30
	  addi      r31, r31, 0x1

	.loc_0xD4:
	  lwz       r0, 0x4(r30)
	  cmpw      r31, r0
	  blt+      .loc_0xC0
	  lwz       r3, 0x0(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xF4:
	  mr        r3, r28
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x118:
	*/
}

/*
 * --INFO--
 * Address:	801E9100
 * Size:	000514
 */
void zen::DrawGameOverLetter::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x180(r1)
	  stw       r31, 0x17C(r1)
	  mr        r31, r3
	  stw       r30, 0x178(r1)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x90
	  bge-      .loc_0x38
	  cmpwi     r0, 0
	  beq-      .loc_0x4F8
	  bge-      .loc_0x44
	  b         .loc_0x4F8

	.loc_0x38:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x4F8
	  b         .loc_0x364

	.loc_0x44:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r31)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x8(r31)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x4F8
	  lfs       f0, -0x4058(r2)
	  li        r0, 0x2
	  stfs      f0, 0x4(r31)
	  stw       r0, 0x0(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x404C(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x4F8

	.loc_0x90:
	  lwz       r3, 0x2DEC(r13)
	  lis       r4, 0x4330
	  lfs       f0, -0x4028(r2)
	  lfs       f2, 0x28C(r3)
	  lfs       f1, 0x24(r31)
	  fmuls     f0, f0, f2
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x24(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x24(r31)
	  lfs       f0, 0x28C(r3)
	  lfs       f5, -0x4024(r2)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x1C(r31)
	  fmuls     f0, f5, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x20(r31)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x18(r31)
	  fmuls     f0, f1, f0
	  fmuls     f0, f5, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x18(r31)
	  lwz       r0, 0x14(r31)
	  lfd       f4, -0x4038(r2)
	  xoris     r0, r0, 0x8000
	  lfs       f1, 0x1C(r31)
	  stw       r0, 0x174(r1)
	  stw       r4, 0x170(r1)
	  lfd       f0, 0x170(r1)
	  fsubs     f0, f0, f4
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x20C
	  lwz       r0, 0x10(r31)
	  lwz       r3, 0x2DEC(r13)
	  xoris     r0, r0, 0x8000
	  lfs       f2, 0x18(r31)
	  stw       r0, 0x174(r1)
	  lfs       f1, -0x4020(r2)
	  stw       r4, 0x170(r1)
	  lfs       f0, 0x28C(r3)
	  lfd       f3, 0x170(r1)
	  fsubs     f3, f3, f4
	  fsubs     f2, f3, f2
	  fdivs     f1, f2, f1
	  fmuls     f0, f1, f0
	  fmuls     f0, f5, f0
	  stfs      f0, 0x20(r31)
	  lfs       f1, 0x20(r31)
	  lfs       f0, -0x4048(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x170
	  stfs      f0, 0x20(r31)

	.loc_0x170:
	  lfs       f1, 0x20(r31)
	  lfs       f0, -0x401C(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x184
	  stfs      f0, 0x20(r31)

	.loc_0x184:
	  lwz       r0, 0x14(r31)
	  lis       r30, 0x4330
	  lfd       f1, -0x4038(r2)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x174(r1)
	  stw       r30, 0x170(r1)
	  lfd       f0, 0x170(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x1C(r31)
	  bl        0x2EDC8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4038(r2)
	  stw       r0, 0x16C(r1)
	  lfs       f3, -0x4044(r2)
	  stw       r30, 0x168(r1)
	  lfs       f2, -0x4018(r2)
	  lfd       f1, 0x168(r1)
	  lfs       f0, -0x4014(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, 0x24(r31)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fadds     f0, f0, f2
	  fmuls     f0, f1, f0
	  stfs      f0, 0x24(r31)
	  lfs       f1, -0x4030(r2)
	  lfs       f0, 0x20(r31)
	  lwz       r3, 0x2DEC(r13)
	  fmuls     f1, f1, f0
	  lfs       f2, -0x4024(r2)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  stfs      f0, 0x28(r31)

	.loc_0x20C:
	  lfs       f1, 0x1C(r31)
	  lfs       f0, -0x4058(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x22C
	  lfs       f0, -0x404C(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x234

	.loc_0x22C:
	  lfs       f0, -0x404C(r2)
	  fsubs     f0, f1, f0

	.loc_0x234:
	  lfs       f2, 0x18(r31)
	  fctiwz    f1, f0
	  lfs       f0, -0x4058(r2)
	  fcmpo     cr0, f2, f0
	  stfd      f1, 0x168(r1)
	  lwz       r5, 0x16C(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x260
	  lfs       f0, -0x404C(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x268

	.loc_0x260:
	  lfs       f0, -0x404C(r2)
	  fsubs     f0, f2, f0

	.loc_0x268:
	  lwz       r3, 0xC(r31)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x168(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x16C(r1)
	  mtlr      r12
	  blrl
	  lwz       r5, 0xC(r31)
	  lis       r0, 0x4330
	  lfd       f3, -0x4038(r2)
	  lha       r4, 0x1A(r5)
	  lha       r3, 0x1E(r5)
	  lfs       f4, -0x4010(r2)
	  sub       r3, r3, r4
	  lfs       f0, -0x4058(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f2, 0xBC(r5)
	  stw       r3, 0x174(r1)
	  lfs       f1, 0x28(r31)
	  stw       r0, 0x170(r1)
	  fadds     f1, f1, f2
	  lfd       f2, 0x170(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2E4
	  lfs       f0, -0x404C(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x2EC

	.loc_0x2E4:
	  lfs       f0, -0x404C(r2)
	  fsubs     f0, f2, f0

	.loc_0x2EC:
	  fctiwz    f0, f0
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  li        r4, 0x7A
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  stfd      f0, 0x168(r1)
	  extsh     r3, r0
	  lwz       r0, 0x16C(r1)
	  sth       r3, 0xB8(r5)
	  addi      r3, r5, 0
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  bl        -0x62C14
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r31)
	  lfs       f1, 0x4(r31)
	  lfs       f0, -0x400C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x4F8
	  lfs       f0, -0x4058(r2)
	  li        r0, 0x3
	  stfs      f0, 0x28(r31)
	  stfs      f0, 0x4(r31)
	  stw       r0, 0x0(r31)
	  stfs      f0, 0x2C(r31)
	  b         .loc_0x4F8

	.loc_0x364:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r31)
	  lfs       f1, 0x4(r31)
	  lfs       f0, -0x4040(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x3A0
	  lfs       f0, -0x4058(r2)
	  stfs      f0, 0x4(r31)
	  lfs       f0, -0x4008(r2)
	  stfs      f0, 0x28(r31)
	  lfs       f0, -0x4004(r2)
	  stfs      f0, 0x2C(r31)

	.loc_0x3A0:
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x4000(r2)
	  lfs       f1, 0xBC(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3D4
	  lwz       r3, 0x2DEC(r13)
	  fneg      f1, f1
	  lfs       f2, 0x28(r31)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x28(r31)
	  b         .loc_0x3F4

	.loc_0x3D4:
	  lfs       f0, -0x3FFC(r2)
	  lwz       r3, 0x2DEC(r13)
	  fsubs     f1, f0, f1
	  lfs       f2, 0x28(r31)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x28(r31)

	.loc_0x3F4:
	  lfs       f1, 0x28(r31)
	  lis       r0, 0x4330
	  lfs       f0, -0x3FF8(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x28(r31)
	  lwz       r5, 0xC(r31)
	  lfd       f3, -0x4038(r2)
	  lha       r4, 0x1A(r5)
	  lha       r3, 0x1E(r5)
	  lfs       f4, -0x4010(r2)
	  sub       r3, r3, r4
	  lfs       f0, -0x4058(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f2, 0xBC(r5)
	  stw       r3, 0x16C(r1)
	  lfs       f1, 0x28(r31)
	  stw       r0, 0x168(r1)
	  fadds     f1, f1, f2
	  lfd       f2, 0x168(r1)
	  fsubs     f2, f2, f3
	  fmuls     f2, f4, f2
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x460
	  lfs       f0, -0x404C(r2)
	  fadds     f0, f0, f2
	  b         .loc_0x468

	.loc_0x460:
	  lfs       f0, -0x404C(r2)
	  fsubs     f0, f2, f0

	.loc_0x468:
	  fctiwz    f0, f0
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  li        r4, 0x7A
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  stfd      f0, 0x168(r1)
	  extsh     r3, r0
	  lwz       r0, 0x16C(r1)
	  sth       r3, 0xB8(r5)
	  addi      r3, r5, 0
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  bl        -0x62D90
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f4, 0xC0(r4)
	  lfs       f1, -0x3FF0(r2)
	  lfs       f0, 0x28C(r3)
	  fsubs     f1, f1, f4
	  lfs       f2, -0x3FF4(r2)
	  lfs       f3, 0x2C(r31)
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f1, 0x2C(r31)
	  lfs       f0, -0x3FEC(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f0, 0x2C(r31)
	  lwz       r3, 0xC(r31)
	  fadds     f0, f4, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)

	.loc_0x4F8:
	  lwz       r0, 0x184(r1)
	  li        r3, 0
	  lwz       r31, 0x17C(r1)
	  lwz       r30, 0x178(r1)
	  addi      r1, r1, 0x180
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E9614
 * Size:	000040
 */
void zen::DrawGameOver::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x30
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x30:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
