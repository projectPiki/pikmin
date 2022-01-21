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
 * Address:	801ED8AC
 * Size:	000150
 */
void zen::DrawCMscoreObj::modeMove()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  li        r31, 0
	  stw       r30, 0x30(r1)
	  mr        r30, r3
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x18(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r3)
	  lfs       f1, 0x18(r3)
	  lfs       f0, 0x1C(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x80
	  stfs      f0, 0x18(r30)
	  lis       r3, 0x802E
	  li        r0, 0
	  lfs       f1, -0x3E88(r2)
	  addi      r4, r3, 0x6DC0
	  lfs       f5, -0x3E84(r2)
	  li        r31, 0x1
	  stfs      f5, 0x18(r30)
	  stw       r0, 0x14(r30)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x44(r30)
	  stw       r0, 0x48(r30)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x4C(r30)
	  b         .loc_0x98

	.loc_0x80:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x3E80(r2)
	  fmuls     f1, f1, f0
	  bl        0x2E3B0
	  lfs       f0, -0x3E88(r2)
	  fsubs     f5, f0, f1

	.loc_0x98:
	  lfs       f0, 0x3C(r30)
	  lfs       f2, 0x30(r30)
	  fmuls     f3, f0, f1
	  lfs       f0, -0x3E84(r2)
	  fmuls     f2, f2, f5
	  fadds     f2, f3, f2
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xC8
	  lfs       f0, -0x3E7C(r2)
	  fadds     f2, f0, f2
	  b         .loc_0xD0

	.loc_0xC8:
	  lfs       f0, -0x3E7C(r2)
	  fsubs     f2, f2, f0

	.loc_0xD0:
	  lfs       f0, 0x38(r30)
	  fctiwz    f4, f2
	  lfs       f2, 0x2C(r30)
	  fmuls     f3, f0, f1
	  lfs       f0, -0x3E84(r2)
	  fmuls     f1, f2, f5
	  stfd      f4, 0x28(r1)
	  fadds     f1, f3, f1
	  lwz       r5, 0x2C(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x10C
	  lfs       f0, -0x3E7C(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x114

	.loc_0x10C:
	  lfs       f0, -0x3E7C(r2)
	  fsubs     f0, f1, f0

	.loc_0x114:
	  lwz       r3, 0x0(r30)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x28(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x2C(r1)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED9FC
 * Size:	000008
 */
u32 zen::DrawCMscoreObj::modeWait() { return 0x0; }

/*
 * --INFO--
 * Address:	801EDA04
 * Size:	0004E4
 */
void zen::DrawCMscoreMgr::init(P2DScreen*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stmw      r19, 0xA4(r1)
	  addi      r22, r3, 0
	  addi      r29, r4, 0
	  lwz       r19, 0x28C4(r13)
	  mulli     r3, r19, 0x50
	  addi      r3, r3, 0x8
	  bl        -0x1A6A2C
	  lis       r4, 0x801F
	  subi      r4, r4, 0x207C
	  addi      r7, r19, 0
	  li        r5, 0
	  li        r6, 0x50
	  bl        0x271E0
	  stw       r3, 0x0(r22)
	  lis       r6, 0x802D
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lfd       f30, -0x3E78(r2)
	  lis       r3, 0x802E
	  lfs       f31, -0x3E84(r2)
	  addi      r28, r6, 0x3004
	  addi      r27, r5, 0x2FF4
	  addi      r26, r4, 0x2FE4
	  addi      r25, r3, 0x6DD8
	  li        r30, 0
	  li        r24, 0
	  lis       r23, 0x4330
	  b         .loc_0x494

	.loc_0x84:
	  lwz       r0, 0x0(r22)
	  addi      r3, r1, 0x80
	  addi      r5, r30, 0x1
	  crclr     6, 0x6
	  add       r31, r0, r24
	  addi      r4, r13, 0x28A4
	  bl        0x28AF8
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lbz       r0, 0x81(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x80(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x82(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x83(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  stw       r3, 0x0(r31)
	  addi      r3, r1, 0x80
	  addi      r5, r30, 0x1
	  crclr     6, 0x6
	  lwz       r8, 0x0(r31)
	  addi      r4, r13, 0x28AC
	  lha       r6, 0x18(r8)
	  lha       r0, 0x1C(r8)
	  lha       r7, 0x1A(r8)
	  sub       r0, r0, r6
	  lha       r6, 0x1E(r8)
	  srawi     r0, r0, 0x1
	  sub       r7, r6, r7
	  extsh     r6, r0
	  srawi     r0, r7, 0x1
	  sth       r6, 0xB8(r8)
	  extsh     r0, r0
	  sth       r0, 0xBA(r8)
	  lwz       r6, 0x0(r31)
	  lha       r0, 0x18(r6)
	  lha       r6, 0x1A(r6)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x9C(r1)
	  xoris     r0, r6, 0x8000
	  stw       r23, 0x98(r1)
	  stw       r0, 0x94(r1)
	  lfd       f0, 0x98(r1)
	  stw       r23, 0x90(r1)
	  fsubs     f1, f0, f30
	  lfd       f0, 0x90(r1)
	  fsubs     f0, f0, f30
	  stfs      f1, 0x20(r31)
	  stfs      f0, 0x24(r31)
	  lfs       f0, 0x28A0(r13)
	  stfs      f0, 0x28(r31)
	  bl        0x28A30
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lbz       r0, 0x81(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x80(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x82(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x83(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  addi      r21, r3, 0
	  li        r3, 0x1C
	  bl        -0x1A6BA8
	  addi      r20, r3, 0
	  mr.       r19, r20
	  beq-      .loc_0x240
	  stw       r28, 0x0(r20)
	  addi      r4, r21, 0
	  addi      r3, r20, 0x4
	  li        r5, 0x12
	  bl        -0x3D4CC
	  stw       r27, 0x0(r20)
	  addi      r3, r20, 0x4
	  bl        -0x2E4E8
	  addi      r0, r31, 0x10
	  stw       r0, 0x4(r20)
	  li        r0, 0x64
	  li        r6, 0
	  stw       r0, 0x8(r20)
	  addi      r3, r20, 0
	  addi      r4, r21, 0
	  stw       r26, 0x0(r20)
	  stb       r6, 0x18(r20)
	  lwz       r5, 0x4(r20)
	  lwz       r0, 0x0(r5)
	  stw       r0, 0x10(r20)
	  stw       r6, 0x14(r20)
	  stfs      f31, 0xC(r20)
	  bl        .loc_0x4E4
	  addi      r3, r21, 0x18
	  bl        -0x356E8
	  addi      r20, r3, 0
	  addi      r3, r21, 0x18
	  bl        -0x35704
	  srawi     r0, r3, 0x1
	  extsh     r3, r0
	  srawi     r0, r20, 0x1
	  sth       r3, 0xB8(r21)
	  extsh     r0, r0
	  sth       r0, 0xBA(r21)

	.loc_0x240:
	  addi      r3, r21, 0
	  addi      r4, r19, 0
	  bl        -0x3D5B0
	  lhz       r0, 0x8(r21)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x25C
	  stw       r21, 0xC(r31)

	.loc_0x25C:
	  addi      r3, r1, 0x80
	  crclr     6, 0x6
	  addi      r5, r30, 0x1
	  addi      r4, r13, 0x28B4
	  bl        0x28928
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lbz       r0, 0x81(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x80(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x82(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x83(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  addi      r21, r3, 0
	  li        r3, 0x1C
	  bl        -0x1A6CB0
	  addi      r20, r3, 0
	  mr.       r19, r20
	  beq-      .loc_0x348
	  stw       r28, 0x0(r20)
	  addi      r4, r21, 0
	  addi      r3, r20, 0x4
	  li        r5, 0x12
	  bl        -0x3D5D4
	  stw       r27, 0x0(r20)
	  addi      r3, r20, 0x4
	  bl        -0x2E5F0
	  addi      r0, r31, 0x10
	  stw       r0, 0x4(r20)
	  li        r0, 0xA
	  li        r6, 0
	  stw       r0, 0x8(r20)
	  addi      r3, r20, 0
	  addi      r4, r21, 0
	  stw       r26, 0x0(r20)
	  stb       r6, 0x18(r20)
	  lwz       r5, 0x4(r20)
	  lwz       r0, 0x0(r5)
	  stw       r0, 0x10(r20)
	  stw       r6, 0x14(r20)
	  stfs      f31, 0xC(r20)
	  bl        .loc_0x4E4
	  addi      r3, r21, 0x18
	  bl        -0x357F0
	  addi      r20, r3, 0
	  addi      r3, r21, 0x18
	  bl        -0x3580C
	  srawi     r0, r3, 0x1
	  extsh     r3, r0
	  srawi     r0, r20, 0x1
	  sth       r3, 0xB8(r21)
	  extsh     r0, r0
	  sth       r0, 0xBA(r21)

	.loc_0x348:
	  addi      r3, r21, 0
	  addi      r4, r19, 0
	  bl        -0x3D6B8
	  lhz       r0, 0x8(r21)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x364
	  stw       r21, 0x8(r31)

	.loc_0x364:
	  addi      r3, r1, 0x80
	  crclr     6, 0x6
	  addi      r5, r30, 0x1
	  addi      r4, r13, 0x28BC
	  bl        0x28820
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lbz       r0, 0x81(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x80(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x82(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x83(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  addi      r21, r3, 0
	  li        r3, 0x1C
	  bl        -0x1A6DB8
	  addi      r20, r3, 0
	  mr.       r19, r20
	  beq-      .loc_0x450
	  stw       r28, 0x0(r20)
	  addi      r4, r21, 0
	  addi      r3, r20, 0x4
	  li        r5, 0x12
	  bl        -0x3D6DC
	  stw       r27, 0x0(r20)
	  addi      r3, r20, 0x4
	  bl        -0x2E6F8
	  addi      r0, r31, 0x10
	  stw       r0, 0x4(r20)
	  li        r0, 0x1
	  li        r6, 0
	  stw       r0, 0x8(r20)
	  addi      r3, r20, 0
	  addi      r4, r21, 0
	  stw       r26, 0x0(r20)
	  stb       r6, 0x18(r20)
	  lwz       r5, 0x4(r20)
	  lwz       r0, 0x0(r5)
	  stw       r0, 0x10(r20)
	  stw       r6, 0x14(r20)
	  stfs      f31, 0xC(r20)
	  bl        .loc_0x4E4
	  addi      r3, r21, 0x18
	  bl        -0x358F8
	  addi      r20, r3, 0
	  addi      r3, r21, 0x18
	  bl        -0x35914
	  srawi     r0, r3, 0x1
	  extsh     r3, r0
	  srawi     r0, r20, 0x1
	  sth       r3, 0xB8(r21)
	  extsh     r0, r0
	  sth       r0, 0xBA(r21)

	.loc_0x450:
	  addi      r3, r21, 0
	  addi      r4, r19, 0
	  bl        -0x3D7C0
	  lhz       r0, 0x8(r21)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x46C
	  stw       r21, 0x4(r31)

	.loc_0x46C:
	  li        r0, 0
	  stw       r0, 0x14(r31)
	  addi      r24, r24, 0x50
	  addi      r30, r30, 0x1
	  lwz       r3, 0x0(r25)
	  lwz       r0, 0x4(r25)
	  stw       r3, 0x44(r31)
	  stw       r0, 0x48(r31)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x4C(r31)

	.loc_0x494:
	  lwz       r0, 0x28C4(r13)
	  cmpw      r30, r0
	  blt+      .loc_0x84
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x4(r22)
	  addi      r4, r3, 0x6DE4
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x8(r22)
	  stw       r0, 0xC(r22)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x10(r22)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lmw       r19, 0xA4(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr

	.loc_0x4E4:
	*/
}

/*
 * --INFO--
 * Address:	801EDEE8
 * Size:	00009C
 */
void zen::NumberPicCallBack<int>::setTexture(P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  lbz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x58
	  addi      r3, r5, 0x4
	  lwz       r4, 0x4(r5)
	  bl        -0x6CEC0
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x88
	  stw       r0, 0xEC(r31)
	  b         .loc_0x88

	.loc_0x58:
	  addi      r3, r5, 0x4
	  lwz       r4, 0x4(r5)
	  bl        -0x6CEF4
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x88
	  stw       r0, 0xEC(r31)

	.loc_0x88:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EDF84
 * Size:	000074
 */
zen::DrawCMscoreObj::DrawCMscoreObj()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x3E84(r2)
	  lis       r4, 0x8022
	  li        r6, 0
	  stfs      f0, 0x28(r3)
	  li        r0, 0x141
	  addi      r5, r4, 0x2758
	  stfs      f0, 0x24(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x34(r3)
	  stfs      f0, 0x30(r3)
	  stfs      f0, 0x2C(r3)
	  stfs      f0, 0x40(r3)
	  stfs      f0, 0x3C(r3)
	  stfs      f0, 0x38(r3)
	  stw       r6, 0x0(r3)
	  stw       r6, 0x4(r3)
	  stw       r6, 0x8(r3)
	  stw       r6, 0xC(r3)
	  stw       r0, 0x10(r3)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x1C(r3)
	  stw       r6, 0x14(r3)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x44(r3)
	  stw       r0, 0x48(r3)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x4C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EDFF8
 * Size:	00007C
 */
void zen::DrawCMscoreMgr::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  addi      r12, r29, 0x8
	  stw       r31, 0x1C(r3)
	  bl        0x26D10
	  nop
	  li        r30, 0
	  b         .loc_0x54

	.loc_0x38:
	  lwz       r0, 0x0(r29)
	  add       r3, r0, r31
	  addi      r12, r3, 0x44
	  bl        0x26CF4
	  nop
	  addi      r31, r31, 0x50
	  addi      r30, r30, 0x1

	.loc_0x54:
	  lwz       r0, 0x28C4(r13)
	  cmpw      r30, r0
	  blt+      .loc_0x38
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void zen::DrawCMscoreMgr::show()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801EE074
 * Size:	00003C
 */
void zen::DrawCMscoreMgr::hide()
{
	/*
	.loc_0x0:
	  li        r6, 0
	  addi      r5, r6, 0
	  li        r7, 0
	  b         .loc_0x2C

	.loc_0x10:
	  lwz       r4, 0x0(r3)
	  addi      r7, r7, 0x1
	  lwzx      r4, r4, r6
	  addi      r6, r6, 0x50
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)

	.loc_0x2C:
	  lwz       r0, 0x28C4(r13)
	  cmpw      r7, r0
	  blt+      .loc_0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EE0B0
 * Size:	000064
 */
void zen::DrawCMscoreMgr::sleep()
{
	/*
	.loc_0x0:
	  li        r6, 0
	  addi      r7, r6, 0
	  addi      r5, r6, 0
	  b         .loc_0x2C

	.loc_0x10:
	  lwz       r4, 0x0(r3)
	  addi      r6, r6, 0x1
	  lwzx      r4, r4, r7
	  addi      r7, r7, 0x50
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)

	.loc_0x2C:
	  lwz       r0, 0x28C4(r13)
	  cmpw      r6, r0
	  blt+      .loc_0x10
	  li        r0, -0x1
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r5, r4, 0x6DF0
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EE114
 * Size:	000114
 */
void zen::DrawCMscoreMgr::appear(float)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  li        r9, 0
	  lis       r4, 0x802E
	  stw       r9, 0x4(r3)
	  addi      r7, r4, 0x6DFC
	  lis       r4, 0x802E
	  lwz       r6, 0x0(r7)
	  addi      r5, r4, 0x6DCC
	  lwz       r0, 0x4(r7)
	  li        r10, 0
	  stw       r6, 0x8(r3)
	  lis       r6, 0x4330
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x8(r7)
	  stw       r0, 0x10(r3)
	  lfs       f5, -0x3E84(r2)
	  lfs       f4, -0x3E70(r2)
	  lfd       f3, -0x3E78(r2)
	  lfs       f2, -0x3E6C(r2)
	  b         .loc_0x100

	.loc_0x50:
	  lwz       r4, 0x0(r3)
	  li        r7, 0x1
	  lwzx      r4, r4, r9
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r0, 0x0(r3)
	  add       r8, r0, r9
	  stfs      f5, 0x18(r8)
	  addi      r9, r9, 0x50
	  lwz       r0, 0x28C4(r13)
	  sub       r4, r0, r10
	  subi      r0, r4, 0x1
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1C(r1)
	  addi      r10, r10, 0x1
	  stw       r6, 0x18(r1)
	  lfd       f0, 0x18(r1)
	  fsubs     f0, f0, f3
	  fmuls     f0, f4, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r8)
	  stw       r7, 0x14(r8)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x44(r8)
	  stw       r0, 0x48(r8)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x4C(r8)
	  lfs       f0, 0x20(r8)
	  stfs      f0, 0x2C(r8)
	  lfs       f0, 0x24(r8)
	  stfs      f0, 0x30(r8)
	  lfs       f0, 0x28(r8)
	  stfs      f0, 0x34(r8)
	  lfs       f0, 0x2C(r8)
	  fadds     f0, f0, f2
	  stfs      f0, 0x2C(r8)
	  lfs       f0, 0x20(r8)
	  stfs      f0, 0x38(r8)
	  lfs       f0, 0x24(r8)
	  stfs      f0, 0x3C(r8)
	  lfs       f0, 0x28(r8)
	  stfs      f0, 0x40(r8)

	.loc_0x100:
	  lwz       r0, 0x28C4(r13)
	  cmpw      r10, r0
	  blt+      .loc_0x50
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EE228
 * Size:	000008
 */
u32 zen::DrawCMscoreMgr::modeSleep() { return 0x0; }

/*
 * --INFO--
 * Address:	801EE230
 * Size:	00007C
 */
void zen::DrawCMscoreMgr::modeAppear()
{
	/*
	.loc_0x0:
	  lwz       r6, 0x28C4(r13)
	  li        r7, 0
	  li        r5, 0
	  cmpwi     r6, 0
	  mtctr     r6
	  ble-      .loc_0x38

	.loc_0x18:
	  lwz       r4, 0x0(r3)
	  addi      r0, r5, 0x14
	  lwzx      r0, r4, r0
	  cmpwi     r0, 0
	  bne-      .loc_0x30
	  addi      r7, r7, 0x1

	.loc_0x30:
	  addi      r5, r5, 0x50
	  bdnz+     .loc_0x18

	.loc_0x38:
	  cmpw      r7, r6
	  bne-      .loc_0x74
	  li        r0, 0x1
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r5, r4, 0x6E08
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0x1C(r3)
	  ori       r0, r0, 0x1
	  stw       r0, 0x1C(r3)

	.loc_0x74:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EE2AC
 * Size:	000014
 */
void zen::DrawCMscoreMgr::modeWait()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x1C(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x1C(r3)
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EE2C0
 * Size:	000028
 */
void zen::DrawCMscoreMgr::setScore(int, int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bltlr-
	  lwz       r0, 0x28C4(r13)
	  cmpw      r4, r0
	  bgelr-
	  mulli     r4, r4, 0x50
	  lwz       r3, 0x0(r3)
	  addi      r0, r4, 0x10
	  stwx      r5, r3, r0
	  blr
	*/
}
