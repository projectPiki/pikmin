#include "zen/DrawFinalResult.h"

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
 * Address:	801F3A38
 * Size:	000AC0
 */
zen::DrawTotalScore::DrawTotalScore(zen::TotalScoreRecord*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stmw      r26, 0x80(r1)
	  li        r30, 0
	  addi      r31, r3, 0
	  stw       r30, 0x24(r3)
	  lis       r3, 0x8022
	  addi      r5, r3, 0x2758
	  stw       r30, 0x28(r31)
	  stw       r30, 0x2C(r31)
	  lwz       r3, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r3, 0x34(r31)
	  stw       r0, 0x38(r31)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x3C(r31)
	  stw       r30, 0x30(r31)
	  stw       r4, 0x844(r31)
	  lwz       r0, 0x844(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x1F0
	  li        r3, 0x44
	  bl        -0x1ACA90
	  stw       r3, 0x844(r31)
	  lis       r3, 0xBC
	  li        r5, 0xB
	  lwz       r7, 0x844(r31)
	  li        r0, 0x16
	  li        r4, 0x14D
	  stw       r5, 0x0(r7)
	  li        r6, 0x115C
	  addi      r5, r3, 0x614E
	  stw       r0, 0x4(r7)
	  li        r3, 0x3
	  li        r0, 0x1
	  stw       r4, 0x8(r7)
	  cmpwi     r30, 0x3
	  li        r4, -0x1
	  stw       r6, 0xC(r7)
	  stw       r5, 0x10(r7)
	  sth       r3, 0x14(r7)
	  sth       r0, 0x16(r7)
	  sth       r4, 0x18(r7)
	  bge-      .loc_0xD0
	  sth       r0, 0x1A(r7)
	  li        r0, 0xA
	  subfic    r3, r30, 0x1388
	  sth       r0, 0x24(r7)
	  sth       r3, 0x2E(r7)
	  sth       r30, 0x38(r7)
	  b         .loc_0xE0

	.loc_0xD0:
	  sth       r4, 0x1A(r7)
	  sth       r4, 0x24(r7)
	  sth       r4, 0x2E(r7)
	  sth       r4, 0x38(r7)

	.loc_0xE0:
	  li        r3, 0x1
	  cmpwi     r3, 0x3
	  addi      r5, r7, 0x2
	  bge-      .loc_0x114
	  li        r0, 0x2
	  sth       r0, 0x1A(r5)
	  li        r0, 0xB
	  subfic    r3, r3, 0x1388
	  sth       r0, 0x24(r5)
	  li        r0, 0xA
	  sth       r3, 0x2E(r5)
	  sth       r0, 0x38(r5)
	  b         .loc_0x124

	.loc_0x114:
	  sth       r4, 0x1A(r5)
	  sth       r4, 0x24(r5)
	  sth       r4, 0x2E(r5)
	  sth       r4, 0x38(r5)

	.loc_0x124:
	  li        r3, 0x2
	  cmpwi     r3, 0x3
	  addi      r5, r5, 0x2
	  bge-      .loc_0x158
	  li        r0, 0x3
	  sth       r0, 0x1A(r5)
	  li        r0, 0xC
	  subfic    r3, r3, 0x1388
	  sth       r0, 0x24(r5)
	  li        r0, 0x14
	  sth       r3, 0x2E(r5)
	  sth       r0, 0x38(r5)
	  b         .loc_0x168

	.loc_0x158:
	  sth       r4, 0x1A(r5)
	  sth       r4, 0x24(r5)
	  sth       r4, 0x2E(r5)
	  sth       r4, 0x38(r5)

	.loc_0x168:
	  li        r3, 0x3
	  cmpwi     r3, 0x3
	  addi      r5, r5, 0x2
	  bge-      .loc_0x19C
	  li        r0, 0x4
	  sth       r0, 0x1A(r5)
	  li        r0, 0xD
	  subfic    r3, r3, 0x1388
	  sth       r0, 0x24(r5)
	  li        r0, 0x1E
	  sth       r3, 0x2E(r5)
	  sth       r0, 0x38(r5)
	  b         .loc_0x1AC

	.loc_0x19C:
	  sth       r4, 0x1A(r5)
	  sth       r4, 0x24(r5)
	  sth       r4, 0x2E(r5)
	  sth       r4, 0x38(r5)

	.loc_0x1AC:
	  li        r3, 0x4
	  cmpwi     r3, 0x3
	  addi      r5, r5, 0x2
	  bge-      .loc_0x1E0
	  li        r0, 0x5
	  sth       r0, 0x1A(r5)
	  li        r0, 0xE
	  subfic    r3, r3, 0x1388
	  sth       r0, 0x24(r5)
	  li        r0, 0x28
	  sth       r3, 0x2E(r5)
	  sth       r0, 0x38(r5)
	  b         .loc_0x1F0

	.loc_0x1E0:
	  sth       r4, 0x1A(r5)
	  sth       r4, 0x24(r5)
	  sth       r4, 0x2E(r5)
	  sth       r4, 0x38(r5)

	.loc_0x1F0:
	  li        r3, 0x100
	  bl        -0x1ACC28
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x21C
	  lis       r4, 0x802E
	  addi      r4, r4, 0x71F0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x346DC

	.loc_0x21C:
	  stw       r27, 0xC(r31)
	  lis       r0, 0x4330
	  lwz       r3, 0xC(r31)
	  lfd       f2, -0x3D48(r2)
	  addi      r5, r3, 0x4
	  lfs       f3, -0x3D58(r2)
	  lha       r4, 0x1E(r3)
	  mr        r30, r5
	  lha       r3, 0x22(r3)
	  lfs       f0, -0x3D54(r2)
	  sub       r3, r3, r4
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x7C(r1)
	  stw       r0, 0x78(r1)
	  lfd       f1, 0x78(r1)
	  fsubs     f1, f1, f2
	  fmuls     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x278
	  lfs       f0, -0x3D50(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x280

	.loc_0x278:
	  lfs       f0, -0x3D50(r2)
	  fsubs     f0, f1, f0

	.loc_0x280:
	  fctiwz    f0, f0
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  addi      r29, r31, 0
	  li        r28, 0
	  stfd      f0, 0x78(r1)
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r3, r0
	  lwz       r0, 0x7C(r1)
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)

	.loc_0x2B4:
	  addi      r3, r1, 0x6C
	  crclr     6, 0x6
	  addi      r5, r28, 0x1
	  addi      r4, r13, 0x29B0
	  bl        0x2289C
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x6D(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x6C(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x6E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x6F(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  addi      r28, r28, 0x1
	  stw       r3, 0x14(r29)
	  cmpwi     r28, 0x4
	  addi      r29, r29, 0x4
	  blt+      .loc_0x2B4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lis       r27, 0x7061
	  addi      r4, r27, 0x5F6C
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x80(r31)
	  addi      r3, r30, 0
	  addi      r4, r27, 0x5F72
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x84(r31)
	  addi      r3, r30, 0
	  lis       r28, 0x6461
	  lwz       r12, 0x0(r30)
	  addi      r4, r28, 0x5F6C
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x88(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F72
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8C(r31)
	  addi      r3, r30, 0
	  lis       r29, 0x6C70
	  lwz       r12, 0x0(r30)
	  addi      r4, r29, 0x5F34
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x90(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F33
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x94(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F32
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x98(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F31
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x9C(r31)
	  addi      r3, r30, 0
	  lis       r28, 0x6470
	  lwz       r12, 0x0(r30)
	  addi      r4, r28, 0x5F34
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xA0(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F33
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xA4(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F32
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xA8(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F31
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xAC(r31)
	  addi      r3, r30, 0
	  lis       r4, 0x7064
	  lwz       r12, 0x0(r30)
	  addi      r4, r4, 0x5F73
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xB0(r31)
	  addi      r3, r30, 0
	  addi      r4, r27, 0x5F6B
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xB4(r31)
	  addi      r3, r30, 0
	  addi      r4, r27, 0x5F64
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xB8(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F68
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xBC(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F68
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC0(r31)
	  li        r3, 0x1
	  lwz       r4, 0x844(r31)
	  lha       r4, 0x1A(r4)
	  bl        -0x73E40
	  lwz       r4, 0x844(r31)
	  li        r3, 0x2
	  lha       r4, 0x24(r4)
	  bl        -0x73E50
	  lwz       r4, 0x844(r31)
	  li        r3, 0x3
	  lha       r4, 0x1C(r4)
	  bl        -0x73E60
	  lwz       r4, 0x844(r31)
	  li        r3, 0x4
	  lha       r4, 0x26(r4)
	  bl        -0x73E70
	  lwz       r4, 0x844(r31)
	  li        r3, 0x5
	  lha       r4, 0x1E(r4)
	  bl        -0x73E80
	  lwz       r4, 0x844(r31)
	  li        r3, 0x6
	  lha       r4, 0x28(r4)
	  bl        -0x73E90
	  lwz       r4, 0x844(r31)
	  li        r3, 0x7
	  lha       r4, 0x20(r4)
	  bl        -0x73EA0
	  lwz       r4, 0x844(r31)
	  li        r3, 0x8
	  lha       r4, 0x2A(r4)
	  bl        -0x73EB0
	  lwz       r4, 0x844(r31)
	  li        r3, 0x9
	  lha       r4, 0x22(r4)
	  bl        -0x73EC0
	  lwz       r4, 0x844(r31)
	  li        r3, 0xA
	  lha       r4, 0x2C(r4)
	  bl        -0x73ED0
	  lwz       r4, 0x844(r31)
	  li        r3, 0xB
	  lha       r4, 0x2E(r4)
	  bl        -0x73EE0
	  lwz       r4, 0x844(r31)
	  li        r3, 0xC
	  lha       r4, 0x30(r4)
	  bl        -0x73EF0
	  lwz       r4, 0x844(r31)
	  li        r3, 0xD
	  lha       r4, 0x32(r4)
	  bl        -0x73F00
	  lwz       r4, 0x844(r31)
	  li        r3, 0xE
	  lha       r4, 0x34(r4)
	  bl        -0x73F10
	  lwz       r4, 0x844(r31)
	  li        r3, 0xF
	  lha       r4, 0x36(r4)
	  bl        -0x73F20
	  lwz       r4, 0x844(r31)
	  li        r3, 0x10
	  lha       r4, 0x38(r4)
	  bl        -0x73F30
	  lwz       r4, 0x844(r31)
	  li        r3, 0x11
	  lha       r4, 0x3A(r4)
	  bl        -0x73F40
	  lwz       r4, 0x844(r31)
	  li        r3, 0x12
	  lha       r4, 0x3C(r4)
	  bl        -0x73F50
	  lwz       r4, 0x844(r31)
	  li        r3, 0x13
	  lha       r4, 0x3E(r4)
	  bl        -0x73F60
	  lwz       r4, 0x844(r31)
	  li        r3, 0x14
	  lha       r4, 0x40(r4)
	  bl        -0x73F70
	  addi      r27, r31, 0
	  addi      r28, r31, 0
	  li        r29, 0

	.loc_0x694:
	  addi      r3, r1, 0x6C
	  crclr     6, 0x6
	  addi      r5, r29, 0x1
	  addi      r4, r13, 0x29B8
	  bl        0x224BC
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x6D(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x6C(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x6E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x6F(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  stw       r3, 0x40(r27)
	  addi      r26, r28, 0xC4
	  addi      r3, r26, 0
	  lwz       r4, 0x40(r27)
	  lwz       r4, 0x10C(r4)
	  bl        0x2522C
	  mr        r3, r26
	  bl        -0x73694
	  lwz       r3, 0x40(r27)
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x5
	  stw       r26, 0x10C(r3)
	  addi      r27, r27, 0x4
	  addi      r28, r28, 0x80
	  blt+      .loc_0x694
	  addi      r27, r31, 0
	  addi      r28, r31, 0
	  li        r29, 0

	.loc_0x728:
	  addi      r3, r1, 0x6C
	  crclr     6, 0x6
	  addi      r5, r29, 0x1
	  addi      r4, r13, 0x29C0
	  bl        0x22428
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x6D(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x6C(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x6E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x6F(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  stw       r3, 0x54(r27)
	  addi      r26, r28, 0x344
	  addi      r3, r26, 0
	  lwz       r4, 0x54(r27)
	  lwz       r4, 0x10C(r4)
	  bl        0x25198
	  mr        r3, r26
	  bl        -0x73728
	  lwz       r3, 0x54(r27)
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x5
	  stw       r26, 0x10C(r3)
	  addi      r27, r27, 0x4
	  addi      r28, r28, 0x80
	  blt+      .loc_0x728
	  addi      r27, r31, 0
	  addi      r28, r31, 0
	  li        r29, 0

	.loc_0x7BC:
	  addi      r3, r1, 0x6C
	  crclr     6, 0x6
	  addi      r5, r29, 0x1
	  addi      r4, r13, 0x29C8
	  bl        0x22394
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x6D(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x6C(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x6E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x6F(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  stw       r3, 0x68(r27)
	  addi      r26, r28, 0x5C4
	  addi      r3, r26, 0
	  lwz       r4, 0x68(r27)
	  lwz       r4, 0x10C(r4)
	  bl        0x25104
	  mr        r3, r26
	  bl        -0x737BC
	  lwz       r3, 0x68(r27)
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x5
	  stw       r26, 0x10C(r3)
	  addi      r27, r27, 0x4
	  addi      r28, r28, 0x80
	  blt+      .loc_0x7BC
	  lis       r28, 0x7061
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F6C
	  li        r6, 0xA
	  bl        -0x759AC
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F72
	  li        r6, 0x1
	  bl        -0x759C0
	  lwz       r5, 0x844(r31)
	  lis       r28, 0x6461
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F6C
	  addi      r5, r5, 0x4
	  li        r6, 0xA
	  bl        -0x759DC
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F72
	  addi      r5, r5, 0x4
	  li        r6, 0x1
	  bl        -0x759F4
	  lwz       r5, 0x844(r31)
	  lis       r28, 0x6C70
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F34
	  addi      r5, r5, 0x8
	  li        r6, 0x3E8
	  bl        -0x75A10
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F33
	  addi      r5, r5, 0x8
	  li        r6, 0x64
	  bl        -0x75A28
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F32
	  addi      r5, r5, 0x8
	  li        r6, 0xA
	  bl        -0x75A40
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F31
	  addi      r5, r5, 0x8
	  li        r6, 0x1
	  bl        -0x75A58
	  lwz       r5, 0x844(r31)
	  lis       r28, 0x6470
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F34
	  addi      r5, r5, 0xC
	  li        r6, 0x3E8
	  bl        -0x75A74
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F33
	  addi      r5, r5, 0xC
	  li        r6, 0x64
	  bl        -0x75A8C
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F32
	  addi      r5, r5, 0xC
	  li        r6, 0xA
	  bl        -0x75AA4
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F31
	  addi      r5, r5, 0xC
	  li        r6, 0x1
	  bl        -0x75ABC
	  lwz       r5, 0x844(r31)
	  lis       r28, 0x7470
	  lis       r6, 0x99
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F38
	  addi      r5, r5, 0x10
	  subi      r6, r6, 0x6980
	  bl        -0x75ADC
	  lwz       r5, 0x844(r31)
	  lis       r6, 0xF
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F37
	  addi      r5, r5, 0x10
	  addi      r6, r6, 0x4240
	  bl        -0x75AF8
	  lwz       r5, 0x844(r31)
	  lis       r6, 0x2
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F36
	  addi      r5, r5, 0x10
	  subi      r6, r6, 0x7960
	  bl        -0x75B14
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F35
	  addi      r5, r5, 0x10
	  li        r6, 0x2710
	  bl        -0x75B2C
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F34
	  addi      r5, r5, 0x10
	  li        r6, 0x3E8
	  bl        -0x75B44
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F33
	  addi      r5, r5, 0x10
	  li        r6, 0x64
	  bl        -0x75B5C
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F32
	  addi      r5, r5, 0x10
	  li        r6, 0xA
	  bl        -0x75B74
	  lwz       r5, 0x844(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F31
	  addi      r5, r5, 0x10
	  li        r6, 0x1
	  bl        -0x75B8C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lis       r4, 0x6E65
	  addi      r4, r4, 0x7764
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x7C(r31)
	  li        r3, 0x4C4
	  bl        -0x1AD498
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xA84
	  li        r4, 0x10
	  li        r5, 0x40
	  li        r6, 0x40
	  bl        -0xABF8

	.loc_0xA84:
	  stw       r27, 0x10(r31)
	  addi      r4, r30, 0
	  addi      r3, r31, 0x24
	  bl        -0x5FB4
	  addi      r3, r31, 0x24
	  bl        -0x5D58
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x1F0
	  mr        r3, r31
	  lmw       r26, 0x80(r1)
	  lwz       r0, 0x9C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F44F8
 * Size:	0001D4
 */
void zen::DrawTotalScore::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  li        r31, 0
	  stw       r30, 0x88(r1)
	  mr        r30, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x158
	  bge-      .loc_0x3C
	  cmpwi     r0, 0x1
	  bge-      .loc_0x48
	  b         .loc_0x190

	.loc_0x3C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x190
	  b         .loc_0x18C

	.loc_0x48:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7C
	  addi      r3, r30, 0
	  li        r4, 0x2
	  bl        .loc_0x1D4
	  b         .loc_0x190

	.loc_0x7C:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x3D40(r2)
	  fmuls     f1, f1, f0
	  bl        0x27768
	  lfs       f0, -0x3D3C(r2)
	  lfs       f2, -0x3D38(r2)
	  fsubs     f31, f0, f1
	  lfs       f0, -0x3D54(r2)
	  fmuls     f1, f2, f31
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xB8
	  lfs       f0, -0x3D50(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xC0

	.loc_0xB8:
	  lfs       f0, -0x3D50(r2)
	  fsubs     f0, f1, f0

	.loc_0xC0:
	  fctiwz    f0, f0
	  lwz       r3, 0xC(r30)
	  lwzu      r12, 0x4(r3)
	  li        r4, 0
	  stfd      f0, 0x80(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r5, 0x84(r1)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x3D3C(r2)
	  li        r4, 0x78
	  lwz       r3, 0xC(r30)
	  fadds     f0, f0, f31
	  addi      r3, r3, 0x4
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f0, -0x3D34(r2)
	  lwz       r3, 0xC(r30)
	  fmuls     f1, f0, f31
	  addi      r3, r3, 0x4
	  bl        -0x6DE00
	  lwz       r3, 0xC(r30)
	  lfs       f0, -0x3D40(r2)
	  addi      r4, r3, 0x4
	  lfs       f1, 0xC0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x144
	  lbz       r0, 0xC(r4)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r4)
	  b         .loc_0x190

	.loc_0x144:
	  lbz       r0, 0xC(r4)
	  li        r3, 0x1
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0xC(r4)
	  b         .loc_0x190

	.loc_0x158:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x190
	  addi      r3, r30, 0
	  li        r4, 0x3
	  bl        .loc_0x1D4
	  b         .loc_0x190

	.loc_0x18C:
	  li        r31, 0x1

	.loc_0x190:
	  lwz       r3, 0xC(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r30)
	  bl        -0xAB18
	  addi      r3, r30, 0x24
	  bl        -0x5F0C
	  mr        r3, r31
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr

	.loc_0x1D4:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void zen::DrawTotalScore::draw(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void zen::DrawTotalScore::sleep()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void zen::DrawTotalScore::start()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F46CC
 * Size:	000138
 */
void zen::DrawTotalScore::setMode(zen::DrawTotalScore::modeFlag)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  stw       r4, 0x0(r3)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xC8
	  bge-      .loc_0x38
	  cmpwi     r0, 0
	  beq-      .loc_0x44
	  bge-      .loc_0x70
	  b         .loc_0x124

	.loc_0x38:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x124
	  b         .loc_0x110

	.loc_0x44:
	  lfs       f0, -0x3D54(r2)
	  addi      r3, r31, 0x24
	  stfs      f0, 0x8(r31)
	  stfs      f0, 0x4(r31)
	  bl        -0x5FA8
	  lwz       r3, 0xC(r31)
	  li        r4, 0
	  lbz       r0, 0x10(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x10(r3)
	  b         .loc_0x124

	.loc_0x70:
	  lfs       f0, -0x3D54(r2)
	  addi      r3, r31, 0x24
	  stfs      f0, 0x4(r31)
	  lfs       f0, -0x3D30(r2)
	  stfs      f0, 0x8(r31)
	  bl        -0x5FD8
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x4
	  bl        -0x34FB8
	  lwz       r3, 0xC(r31)
	  li        r5, 0x1
	  li        r4, 0
	  lbz       r0, 0x10(r3)
	  rlwimi    r0,r5,7,24,24
	  li        r5, -0x3C0
	  stb       r0, 0x10(r3)
	  lwz       r3, 0xC(r31)
	  lwzu      r12, 0x4(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x124

	.loc_0xC8:
	  lfs       f0, -0x3D54(r2)
	  addi      r3, r31, 0x24
	  stfs      f0, 0x4(r31)
	  lfs       f0, -0x3D30(r2)
	  stfs      f0, 0x8(r31)
	  bl        -0x5F90
	  mr        r3, r31
	  bl        0x58
	  mr        r3, r31
	  bl        0x73C
	  mr        r3, r31
	  bl        .loc_0x138
	  lwz       r3, 0xC(r31)
	  li        r4, 0x1
	  lbz       r0, 0x10(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x10(r3)
	  b         .loc_0x124

	.loc_0x110:
	  lwz       r3, 0xC(r31)
	  li        r4, 0x1
	  lbz       r0, 0x10(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x10(r3)

	.loc_0x124:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr

	.loc_0x138:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void zen::DrawTotalScore::setEffect(P2DPane*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F4804
 * Size:	000004
 */
void zen::DrawTotalScore::playRankInFanfare() { }

/*
 * --INFO--
 * Address:	801F4808
 * Size:	0006EC
 */
void zen::DrawTotalScore::setRankInEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1E0(r1)
	  stw       r31, 0x1DC(r1)
	  stw       r30, 0x1D8(r1)
	  mr        r30, r3
	  stw       r29, 0x1D4(r1)
	  lwz       r3, 0x844(r3)
	  lha       r3, 0x14(r3)
	  extsh.    r0, r3
	  blt-      .loc_0x368
	  cmpwi     r3, 0x5
	  bge-      .loc_0x368
	  lwz       r29, 0x14(r30)
	  addi      r4, r1, 0x16C
	  addi      r5, r1, 0x170
	  addi      r3, r29, 0
	  bl        -0x34D1C
	  lha       r3, 0x18(r29)
	  lis       r31, 0x4330
	  lha       r0, 0x1C(r29)
	  li        r7, 0
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0x170(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0x16C(r1)
	  addze     r4, r4
	  lfs       f3, -0x3D54(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0x170(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0x178
	  lwz       r0, 0x170(r1)
	  li        r4, 0x2
	  stw       r3, 0x16C(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0x170(r1)
	  stfs      f3, 0x180(r1)
	  stfs      f3, 0x17C(r1)
	  lwz       r3, 0x16C(r1)
	  lwz       r0, 0x170(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x3D48(r2)
	  stw       r3, 0x1CC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x1C8(r1)
	  stw       r0, 0x1C4(r1)
	  lfd       f0, 0x1C8(r1)
	  stw       r31, 0x1C0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1C0(r1)
	  stfs      f3, 0x178(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x178(r1)
	  stfs      f0, 0x17C(r1)
	  lfs       f0, 0x29D0(r13)
	  stfs      f0, 0x180(r1)
	  lwz       r3, 0x10(r30)
	  bl        -0xADCC
	  lwz       r29, 0x14(r30)
	  addi      r4, r1, 0x14C
	  addi      r5, r1, 0x150
	  addi      r3, r29, 0
	  bl        -0x34DEC
	  lha       r3, 0x18(r29)
	  li        r7, 0
	  lha       r0, 0x1C(r29)
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0x150(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0x14C(r1)
	  addze     r4, r4
	  lfs       f3, -0x3D54(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0x150(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0x158
	  lwz       r0, 0x150(r1)
	  li        r4, 0x3
	  stw       r3, 0x14C(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0x150(r1)
	  stfs      f3, 0x160(r1)
	  stfs      f3, 0x15C(r1)
	  lwz       r3, 0x14C(r1)
	  lwz       r0, 0x150(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x3D48(r2)
	  stw       r3, 0x1BC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x1B8(r1)
	  stw       r0, 0x1B4(r1)
	  lfd       f0, 0x1B8(r1)
	  stw       r31, 0x1B0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1B0(r1)
	  stfs      f3, 0x158(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x158(r1)
	  stfs      f0, 0x15C(r1)
	  lfs       f0, 0x29D0(r13)
	  stfs      f0, 0x160(r1)
	  lwz       r3, 0x10(r30)
	  bl        -0xAE98
	  lwz       r29, 0x18(r30)
	  addi      r4, r1, 0x12C
	  addi      r5, r1, 0x130
	  addi      r3, r29, 0
	  bl        -0x34EB8
	  lha       r3, 0x18(r29)
	  li        r7, 0
	  lha       r0, 0x1C(r29)
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0x130(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0x12C(r1)
	  addze     r4, r4
	  lfs       f3, -0x3D54(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0x130(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0x138
	  lwz       r0, 0x130(r1)
	  li        r4, 0x2
	  stw       r3, 0x12C(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0x130(r1)
	  stfs      f3, 0x140(r1)
	  stfs      f3, 0x13C(r1)
	  lwz       r3, 0x12C(r1)
	  lwz       r0, 0x130(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x3D48(r2)
	  stw       r3, 0x1AC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x1A8(r1)
	  stw       r0, 0x1A4(r1)
	  lfd       f0, 0x1A8(r1)
	  stw       r31, 0x1A0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1A0(r1)
	  stfs      f3, 0x138(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x138(r1)
	  stfs      f0, 0x13C(r1)
	  lfs       f0, 0x29D0(r13)
	  stfs      f0, 0x140(r1)
	  lwz       r3, 0x10(r30)
	  bl        -0xAF64
	  lwz       r29, 0x18(r30)
	  addi      r4, r1, 0x10C
	  addi      r5, r1, 0x110
	  addi      r3, r29, 0
	  bl        -0x34F84
	  lha       r3, 0x18(r29)
	  li        r7, 0
	  lha       r0, 0x1C(r29)
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0x110(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0x10C(r1)
	  addze     r4, r4
	  lfs       f3, -0x3D54(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0x110(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0x118
	  lwz       r0, 0x110(r1)
	  li        r4, 0x3
	  stw       r3, 0x10C(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0x110(r1)
	  stfs      f3, 0x120(r1)
	  stfs      f3, 0x11C(r1)
	  lwz       r3, 0x10C(r1)
	  lwz       r0, 0x110(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x3D48(r2)
	  stw       r3, 0x19C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x198(r1)
	  stw       r0, 0x194(r1)
	  lfd       f0, 0x198(r1)
	  stw       r31, 0x190(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x190(r1)
	  stfs      f3, 0x118(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x118(r1)
	  stfs      f0, 0x11C(r1)
	  lfs       f0, 0x29D0(r13)
	  stfs      f0, 0x120(r1)
	  lwz       r3, 0x10(r30)
	  bl        -0xB030

	.loc_0x368:
	  lwz       r3, 0x844(r30)
	  lha       r3, 0x16(r3)
	  extsh.    r0, r3
	  blt-      .loc_0x51C
	  cmpwi     r3, 0x5
	  bge-      .loc_0x51C
	  lwz       r29, 0x1C(r30)
	  addi      r4, r1, 0xEC
	  addi      r5, r1, 0xF0
	  addi      r3, r29, 0
	  bl        -0x35068
	  lha       r3, 0x18(r29)
	  lis       r31, 0x4330
	  lha       r0, 0x1C(r29)
	  li        r7, 0
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0xF0(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0xEC(r1)
	  addze     r4, r4
	  lfs       f3, -0x3D54(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0xF0(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0xF8
	  lwz       r0, 0xF0(r1)
	  li        r4, 0
	  stw       r3, 0xEC(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0xF0(r1)
	  stfs      f3, 0x100(r1)
	  stfs      f3, 0xFC(r1)
	  lwz       r3, 0xEC(r1)
	  lwz       r0, 0xF0(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x3D48(r2)
	  stw       r3, 0x194(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x190(r1)
	  stw       r0, 0x19C(r1)
	  lfd       f0, 0x190(r1)
	  stw       r31, 0x198(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x198(r1)
	  stfs      f3, 0xF8(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xF8(r1)
	  stfs      f0, 0xFC(r1)
	  lfs       f0, 0x29D0(r13)
	  stfs      f0, 0x100(r1)
	  lwz       r3, 0x10(r30)
	  bl        -0xB118
	  lwz       r29, 0x1C(r30)
	  addi      r4, r1, 0xCC
	  addi      r5, r1, 0xD0
	  addi      r3, r29, 0
	  bl        -0x35138
	  lha       r3, 0x18(r29)
	  li        r7, 0
	  lha       r0, 0x1C(r29)
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0xD0(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0xCC(r1)
	  addze     r4, r4
	  lfs       f3, -0x3D54(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0xD0(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0xD8
	  lwz       r0, 0xD0(r1)
	  li        r4, 0x1
	  stw       r3, 0xCC(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0xD0(r1)
	  stfs      f3, 0xE0(r1)
	  stfs      f3, 0xDC(r1)
	  lwz       r3, 0xCC(r1)
	  lwz       r0, 0xD0(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x3D48(r2)
	  stw       r3, 0x1A4(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x1A0(r1)
	  stw       r0, 0x1AC(r1)
	  lfd       f0, 0x1A0(r1)
	  stw       r31, 0x1A8(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1A8(r1)
	  stfs      f3, 0xD8(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xD8(r1)
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0x29D0(r13)
	  stfs      f0, 0xE0(r1)
	  lwz       r3, 0x10(r30)
	  bl        -0xB1E4

	.loc_0x51C:
	  lwz       r3, 0x844(r30)
	  lha       r3, 0x18(r3)
	  extsh.    r0, r3
	  blt-      .loc_0x6D0
	  cmpwi     r3, 0x5
	  bge-      .loc_0x6D0
	  lwz       r29, 0x20(r30)
	  addi      r4, r1, 0xAC
	  addi      r5, r1, 0xB0
	  addi      r3, r29, 0
	  bl        -0x3521C
	  lha       r3, 0x18(r29)
	  lis       r31, 0x4330
	  lha       r0, 0x1C(r29)
	  li        r7, 0
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0xB0(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0xAC(r1)
	  addze     r4, r4
	  lfs       f3, -0x3D54(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0xB0(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0xB8
	  lwz       r0, 0xB0(r1)
	  li        r4, 0
	  stw       r3, 0xAC(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0xB0(r1)
	  stfs      f3, 0xC0(r1)
	  stfs      f3, 0xBC(r1)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x3D48(r2)
	  stw       r3, 0x194(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x190(r1)
	  stw       r0, 0x19C(r1)
	  lfd       f0, 0x190(r1)
	  stw       r31, 0x198(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x198(r1)
	  stfs      f3, 0xB8(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xB8(r1)
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0x29D0(r13)
	  stfs      f0, 0xC0(r1)
	  lwz       r3, 0x10(r30)
	  bl        -0xB2CC
	  lwz       r29, 0x20(r30)
	  addi      r4, r1, 0x8C
	  addi      r5, r1, 0x90
	  addi      r3, r29, 0
	  bl        -0x352EC
	  lha       r3, 0x18(r29)
	  li        r7, 0
	  lha       r0, 0x1C(r29)
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0x90(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0x8C(r1)
	  addze     r4, r4
	  lfs       f3, -0x3D54(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0x90(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0x98
	  lwz       r0, 0x90(r1)
	  li        r4, 0x1
	  stw       r3, 0x8C(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0x90(r1)
	  stfs      f3, 0xA0(r1)
	  stfs      f3, 0x9C(r1)
	  lwz       r3, 0x8C(r1)
	  lwz       r0, 0x90(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x3D48(r2)
	  stw       r3, 0x1A4(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x1A0(r1)
	  stw       r0, 0x1AC(r1)
	  lfd       f0, 0x1A0(r1)
	  stw       r31, 0x1A8(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1A8(r1)
	  stfs      f3, 0x98(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x98(r1)
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0x29D0(r13)
	  stfs      f0, 0xA0(r1)
	  lwz       r3, 0x10(r30)
	  bl        -0xB398

	.loc_0x6D0:
	  lwz       r0, 0x1E4(r1)
	  lwz       r31, 0x1DC(r1)
	  lwz       r30, 0x1D8(r1)
	  lwz       r29, 0x1D4(r1)
	  addi      r1, r1, 0x1E0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F4EF4
 * Size:	0001D4
 */
void zen::DrawTotalScore::setRankInColor()
{
	/*
	.loc_0x0:
	  stwu      r1, -0xE8(r1)
	  lwz       r4, 0x7C(r3)
	  lbz       r0, 0x108(r4)
	  stb       r0, 0xE4(r1)
	  lbz       r0, 0x109(r4)
	  stb       r0, 0xE5(r1)
	  lbz       r0, 0x10A(r4)
	  stb       r0, 0xE6(r1)
	  lbz       r0, 0x10B(r4)
	  stb       r0, 0xE7(r1)
	  lwz       r4, 0x844(r3)
	  lha       r4, 0x14(r4)
	  extsh.    r0, r4
	  blt-      .loc_0xCC
	  cmpwi     r4, 0x5
	  bge-      .loc_0xCC
	  rlwinm    r4,r4,2,0,29
	  lwz       r0, 0xE4(r1)
	  add       r5, r3, r4
	  lwz       r4, 0x40(r5)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x40(r5)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)
	  lwz       r4, 0x80(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x84(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x88(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x8C(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0xB0(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0xB4(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0xB4(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)
	  lwz       r4, 0xB8(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0xB8(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)

	.loc_0xCC:
	  lwz       r4, 0x844(r3)
	  lha       r4, 0x16(r4)
	  extsh.    r0, r4
	  blt-      .loc_0x14C
	  cmpwi     r4, 0x5
	  bge-      .loc_0x14C
	  rlwinm    r4,r4,2,0,29
	  lwz       r0, 0xE4(r1)
	  add       r5, r3, r4
	  lwz       r4, 0x54(r5)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x54(r5)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)
	  lwz       r4, 0x90(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x94(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x98(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x9C(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0xBC(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0xBC(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)

	.loc_0x14C:
	  lwz       r4, 0x844(r3)
	  lha       r4, 0x18(r4)
	  extsh.    r0, r4
	  blt-      .loc_0x1CC
	  cmpwi     r4, 0x5
	  bge-      .loc_0x1CC
	  rlwinm    r4,r4,2,0,29
	  lwz       r0, 0xE4(r1)
	  add       r5, r3, r4
	  lwz       r4, 0x68(r5)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x68(r5)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)
	  lwz       r4, 0xA0(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0xA4(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0xA8(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0xAC(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0xC0(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF4(r4)
	  lwz       r3, 0xC0(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r3)

	.loc_0x1CC:
	  addi      r1, r1, 0xE8
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F50C8
 * Size:	000070
 */
zen::DrawFinalResult::DrawFinalResult(zen::TotalScoreRecord*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  addi      r3, r29, 0x8
	  bl        -0x338C
	  addi      r3, r29, 0x58
	  bl        0x40C
	  li        r3, 0x848
	  bl        -0x1AE0F8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x4C
	  mr        r4, r30
	  bl        -0x16D8

	.loc_0x4C:
	  stw       r31, 0x4(r29)
	  mr        r3, r29
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
 * Address:	801F5138
 * Size:	0001A4
 */
void zen::DrawFinalResult::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  stw       r30, 0x10(r1)
	  li        r30, 0
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0x6
	  bgt-      .loc_0x188
	  lis       r3, 0x802E
	  addi      r3, r3, 0x7200
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r31, 0x4(r31)
	  li        r4, 0x1
	  lwz       r3, 0x10(r31)
	  bl        -0xB4B0
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0xAC4
	  b         .loc_0x188
	  lwz       r3, 0x4(r31)
	  bl        -0xCA4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x188
	  addi      r3, r31, 0
	  li        r4, 0x2
	  bl        0x288
	  b         .loc_0x188
	  lis       r3, 0x100
	  lwz       r5, 0x28(r4)
	  addi      r0, r3, 0x1000
	  and.      r0, r5, r0
	  beq-      .loc_0xAC
	  li        r3, 0x111
	  bl        -0x14FE5C
	  addi      r3, r31, 0
	  li        r4, 0x3
	  bl        0x25C
	  b         .loc_0x188

	.loc_0xAC:
	  lwz       r3, 0x4(r31)
	  bl        -0xCF0
	  b         .loc_0x188
	  addi      r3, r31, 0x8
	  bl        -0x33A8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x188
	  lwz       r0, 0xC(r31)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xF4
	  bge-      .loc_0x188
	  cmpwi     r0, 0x1
	  bge-      .loc_0xE4
	  b         .loc_0x188

	.loc_0xE4:
	  addi      r3, r31, 0
	  li        r4, 0x2
	  bl        0x214
	  b         .loc_0x188

	.loc_0xF4:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        0x204
	  b         .loc_0x188
	  addi      r3, r31, 0x58
	  bl        0x30C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x188
	  lwz       r0, 0x58(r31)
	  cmpwi     r0, 0x8
	  beq-      .loc_0x160
	  bge-      .loc_0x134
	  cmpwi     r0, 0x6
	  beq-      .loc_0x140
	  bge-      .loc_0x150
	  b         .loc_0x188

	.loc_0x134:
	  cmpwi     r0, 0xA
	  bge-      .loc_0x188
	  b         .loc_0x170

	.loc_0x140:
	  addi      r3, r31, 0
	  li        r4, 0x6
	  bl        0x1B8
	  b         .loc_0x188

	.loc_0x150:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  bl        0x1A8
	  b         .loc_0x188

	.loc_0x160:
	  addi      r3, r31, 0
	  li        r4, 0x5
	  bl        0x198
	  b         .loc_0x188

	.loc_0x170:
	  addi      r3, r31, 0
	  li        r4, 0x6
	  bl        0x188
	  b         .loc_0x188
	  b         .loc_0x188
	  li        r30, 0x1

	.loc_0x188:
	  mr        r3, r30
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
 * Address:	801F52DC
 * Size:	000138
 */
void zen::DrawFinalResult::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0x6
	  bgt-      .loc_0x11C
	  lis       r3, 0x802E
	  addi      r3, r3, 0x721C
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  addi      r3, r29, 0x58
	  bl        0x4B0
	  lwz       r31, 0x4(r29)
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r31)
	  mr        r4, r30
	  bl        -0xB79C
	  b         .loc_0x11C
	  lwz       r31, 0x4(r29)
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r31)
	  mr        r4, r30
	  bl        -0xB7C4
	  b         .loc_0x11C
	  lwz       r0, 0x8(r29)
	  cmpwi     r0, 0x3
	  bne-      .loc_0xB4
	  lwz       r0, 0xC(r29)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xD8

	.loc_0xB4:
	  lwz       r31, 0x4(r29)
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r31)
	  mr        r4, r30
	  bl        -0xB804

	.loc_0xD8:
	  addi      r3, r29, 0x8
	  addi      r4, r30, 0
	  bl        -0x3440
	  b         .loc_0x11C
	  addi      r3, r29, 0x8
	  addi      r4, r30, 0
	  bl        -0x3450
	  addi      r3, r29, 0x58
	  addi      r4, r30, 0
	  bl        0x2FC
	  b         .loc_0x11C
	  addi      r3, r29, 0x8
	  addi      r4, r30, 0
	  bl        -0x346C
	  addi      r3, r29, 0x58
	  addi      r4, r30, 0
	  bl        0x2E0

	.loc_0x11C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F5414
 * Size:	000024
 */
void zen::DrawFinalResult::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        .loc_0x24
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x24:
	*/
}

/*
 * --INFO--
 * Address:	801F5438
 * Size:	0000C8
 */
void zen::DrawFinalResult::setMode(zen::DrawFinalResult::modeFlag)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  stw       r4, 0x0(r3)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0x6
	  bgt-      .loc_0xB0
	  lis       r3, 0x802E
	  addi      r3, r3, 0x7238
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r31, 0x4(r30)
	  li        r4, 0x1
	  lwz       r3, 0x10(r31)
	  bl        -0xB7B0
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0xDC4
	  addi      r3, r30, 0x8
	  bl        -0x3368
	  b         .loc_0xB0
	  lwz       r31, 0x4(r30)
	  li        r4, 0x1
	  lwz       r3, 0x10(r31)
	  bl        -0xB7D8
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0xDEC
	  b         .loc_0xB0
	  addi      r3, r30, 0x8
	  bl        -0x3360
	  b         .loc_0xB0
	  addi      r3, r30, 0x58
	  bl        0x32C
	  b         .loc_0xB0
	  addi      r3, r30, 0x8
	  bl        -0x3310
	  li        r0, 0x3
	  stw       r0, 0x0(r30)

	.loc_0xB0:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
