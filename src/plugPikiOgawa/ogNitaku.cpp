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
 * Address:	80196864
 * Size:	0003E4
 */
zen::ogNitakuMgr::ogNitakuMgr(P2DScreen*, P2DTextBox*, P2DTextBox*, P2DTextBox*, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stmw      r23, 0xBC(r1)
	  li        r23, 0
	  addi      r26, r3, 0
	  lis       r24, 0x6930
	  addi      r27, r7, 0
	  addi      r28, r8, 0
	  addi      r29, r9, 0
	  stw       r23, 0x10(r3)
	  stw       r23, 0x14(r3)
	  lfs       f1, -0x4DA8(r2)
	  stfs      f1, 0x1C(r3)
	  stfs      f1, 0x18(r3)
	  lfs       f0, -0x4DA4(r2)
	  stfs      f0, 0x2C(r3)
	  stfs      f0, 0x28(r3)
	  stfs      f0, 0x24(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f1, 0x34(r3)
	  stfs      f1, 0x30(r3)
	  stfs      f1, 0x3C(r3)
	  stfs      f1, 0x38(r3)
	  stw       r23, 0x50(r3)
	  stw       r23, 0x54(r3)
	  stfs      f1, 0x5C(r3)
	  stfs      f1, 0x58(r3)
	  stfs      f0, 0x6C(r3)
	  stfs      f0, 0x68(r3)
	  stfs      f0, 0x64(r3)
	  stfs      f0, 0x60(r3)
	  stfs      f1, 0x74(r3)
	  stfs      f1, 0x70(r3)
	  stfs      f1, 0x7C(r3)
	  stfs      f1, 0x78(r3)
	  stw       r4, 0x8(r3)
	  addi      r4, r24, 0x306C
	  stw       r5, 0x94(r3)
	  li        r5, 0x1
	  stw       r6, 0x9C(r3)
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3
	  lwz       r3, 0x8(r26)
	  addi      r4, r24, 0x3072
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  lwz       r3, 0x8(r26)
	  addi      r4, r24, 0x316C
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  lwz       r3, 0x8(r26)
	  addi      r4, r24, 0x3172
	  lwz       r12, 0x0(r3)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0xC(r25)
	  rlwimi    r0,r23,7,24,24
	  lis       r4, 0x726F
	  stb       r0, 0xC(r25)
	  lis       r6, 0x4330
	  addi      r4, r4, 0x6F74
	  lbz       r0, 0xC(r30)
	  rlwimi    r0,r23,7,24,24
	  li        r5, 0x1
	  stb       r0, 0xC(r30)
	  lbz       r0, 0xC(r31)
	  rlwimi    r0,r23,7,24,24
	  stb       r0, 0xC(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r23,7,24,24
	  stb       r0, 0xC(r3)
	  lha       r0, 0x18(r25)
	  lfd       f1, -0x4D98(r2)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xB4(r1)
	  stw       r6, 0xB0(r1)
	  lfd       f0, 0xB0(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x40(r26)
	  lha       r0, 0x1A(r25)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xAC(r1)
	  stw       r6, 0xA8(r1)
	  lfd       f0, 0xA8(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x44(r26)
	  lha       r0, 0x18(r31)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xA4(r1)
	  stw       r6, 0xA0(r1)
	  lfd       f0, 0xA0(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x48(r26)
	  lha       r0, 0x1A(r31)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x9C(r1)
	  stw       r6, 0x98(r1)
	  lfd       f0, 0x98(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x4C(r26)
	  lha       r0, 0x18(r30)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x94(r1)
	  stw       r6, 0x90(r1)
	  lfd       f0, 0x90(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x80(r26)
	  lha       r0, 0x1A(r30)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x8C(r1)
	  stw       r6, 0x88(r1)
	  lfd       f0, 0x88(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x84(r26)
	  lha       r0, 0x18(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x84(r1)
	  stw       r6, 0x80(r1)
	  lfd       f0, 0x80(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x88(r26)
	  lha       r0, 0x1A(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x7C(r1)
	  stw       r6, 0x78(r1)
	  lfd       f0, 0x78(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x8C(r26)
	  lwz       r3, 0x8(r26)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xB8(r26)
	  lis       r30, 0x7A30
	  addi      r3, r26, 0x10
	  lwz       r4, 0x8(r26)
	  addi      r6, r30, 0x306C
	  lwz       r5, 0xB8(r26)
	  lfs       f1, 0x48(r26)
	  lfs       f2, 0x4C(r26)
	  bl        0x44168
	  lwz       r4, 0x8(r26)
	  addi      r3, r26, 0x50
	  lwz       r5, 0xB8(r26)
	  addi      r6, r30, 0x3072
	  lfs       f1, 0x88(r26)
	  lfs       f2, 0x8C(r26)
	  bl        0x4414C
	  mr        r3, r26
	  lfs       f1, -0x4DA0(r2)
	  bl        0x308
	  li        r3, 0x24
	  bl        -0x14FB00
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x2B8
	  lwz       r4, 0x94(r26)
	  bl        0x2214

	.loc_0x2B8:
	  stw       r23, 0x98(r26)
	  lwz       r3, 0x94(r26)
	  lwz       r4, 0x98(r26)
	  bl        0x19B74
	  li        r3, 0x24
	  bl        -0x14FB2C
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x2E4
	  lwz       r4, 0x9C(r26)
	  bl        0x21E8

	.loc_0x2E4:
	  stw       r23, 0xA0(r26)
	  lwz       r3, 0x9C(r26)
	  lwz       r4, 0xA0(r26)
	  bl        0x19B48
	  lbz       r0, 0xF4(r27)
	  li        r3, 0
	  stb       r0, 0x74(r1)
	  lbz       r0, 0xF5(r27)
	  stb       r0, 0x75(r1)
	  lbz       r0, 0xF6(r27)
	  stb       r0, 0x76(r1)
	  lbz       r0, 0xF7(r27)
	  stb       r0, 0x77(r1)
	  lwz       r0, 0x74(r1)
	  stw       r0, 0xA4(r26)
	  lbz       r0, 0xF8(r27)
	  stb       r0, 0x70(r1)
	  lbz       r0, 0xF9(r27)
	  stb       r0, 0x71(r1)
	  lbz       r0, 0xFA(r27)
	  stb       r0, 0x72(r1)
	  lbz       r0, 0xFB(r27)
	  stb       r0, 0x73(r1)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0xA8(r26)
	  lwz       r4, 0x94(r26)
	  lbz       r0, 0xF4(r4)
	  stb       r0, 0x6C(r1)
	  lbz       r0, 0xF5(r4)
	  stb       r0, 0x6D(r1)
	  lbz       r0, 0xF6(r4)
	  stb       r0, 0x6E(r1)
	  lbz       r0, 0xF7(r4)
	  stb       r0, 0x6F(r1)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0xAC(r26)
	  lwz       r4, 0x94(r26)
	  lbz       r0, 0xF8(r4)
	  stb       r0, 0x68(r1)
	  lbz       r0, 0xF9(r4)
	  stb       r0, 0x69(r1)
	  lbz       r0, 0xFA(r4)
	  stb       r0, 0x6A(r1)
	  lbz       r0, 0xFB(r4)
	  stb       r0, 0x6B(r1)
	  lwz       r0, 0x68(r1)
	  stw       r0, 0xB0(r26)
	  stb       r28, 0xC(r26)
	  stb       r29, 0xD(r26)
	  stw       r3, 0x0(r26)
	  stw       r3, 0x4(r26)
	  lbz       r0, 0xC(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C8
	  li        r0, 0x1
	  stb       r0, 0x90(r26)
	  b         .loc_0x3CC

	.loc_0x3C8:
	  stb       r3, 0x90(r26)

	.loc_0x3CC:
	  mr        r3, r26
	  lmw       r23, 0xBC(r1)
	  lwz       r0, 0xE4(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void zen::ogNitakuMgr::MoveCursorYes(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void zen::ogNitakuMgr::MoveCursorNo(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000150
 */
void zen::ogNitakuMgr::InitCursor()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80196C48
 * Size:	000168
 */
void zen::ogNitakuMgr::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0x1
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stw       r31, 0x0(r3)
	  lfs       f0, -0x4DA4(r2)
	  stfs      f0, 0xBC(r3)
	  lbz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xB0
	  stb       r31, 0x90(r30)
	  addi      r4, r30, 0xA4
	  addi      r5, r30, 0xA8
	  lwz       r3, 0x98(r30)
	  lfs       f1, -0x4DA0(r2)
	  bl        0x2188
	  lwz       r3, 0xA0(r30)
	  addi      r4, r30, 0xAC
	  lfs       f1, -0x4DA0(r2)
	  addi      r5, r30, 0xB0
	  bl        0x2174
	  lfs       f1, 0x40(r30)
	  addi      r3, r30, 0x10
	  lfs       f2, 0x44(r30)
	  lfs       f3, -0x4DA0(r2)
	  bl        0x43EF0
	  lfs       f1, 0x80(r30)
	  addi      r3, r30, 0x50
	  lfs       f2, 0x84(r30)
	  lfs       f3, -0x4DA0(r2)
	  bl        0x43EDC
	  stb       r31, 0x90(r30)
	  addi      r3, r30, 0x10
	  lfs       f1, 0x40(r30)
	  lfs       f2, 0x44(r30)
	  bl        0x442D0
	  lfs       f1, 0x80(r30)
	  addi      r3, r30, 0x50
	  lfs       f2, 0x84(r30)
	  bl        0x442C0
	  b         .loc_0x12C

	.loc_0xB0:
	  li        r31, 0
	  stb       r31, 0x90(r30)
	  addi      r4, r30, 0xAC
	  addi      r5, r30, 0xB0
	  lwz       r3, 0x98(r30)
	  lfs       f1, -0x4DA0(r2)
	  bl        0x2108
	  lwz       r3, 0xA0(r30)
	  addi      r4, r30, 0xA4
	  lfs       f1, -0x4DA0(r2)
	  addi      r5, r30, 0xA8
	  bl        0x20F4
	  lfs       f1, 0x48(r30)
	  addi      r3, r30, 0x10
	  lfs       f2, 0x4C(r30)
	  lfs       f3, -0x4DA0(r2)
	  bl        0x43E70
	  lfs       f1, 0x88(r30)
	  addi      r3, r30, 0x50
	  lfs       f2, 0x8C(r30)
	  lfs       f3, -0x4DA0(r2)
	  bl        0x43E5C
	  stb       r31, 0x90(r30)
	  addi      r3, r30, 0x10
	  lfs       f1, 0x48(r30)
	  lfs       f2, 0x4C(r30)
	  bl        0x44250
	  lfs       f1, 0x88(r30)
	  addi      r3, r30, 0x50
	  lfs       f2, 0x8C(r30)
	  bl        0x44240

	.loc_0x12C:
	  addi      r3, r30, 0x10
	  lfs       f1, -0x4DA4(r2)
	  bl        0x4433C
	  addi      r3, r30, 0x50
	  lfs       f1, -0x4DA4(r2)
	  bl        0x44330
	  mr        r3, r30
	  lfs       f1, -0x4D90(r2)
	  bl        .loc_0x168
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x168:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000154
 */
void zen::ogNitakuMgr::stop()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80196DB0
 * Size:	000054
 */
void zen::ogNitakuMgr::cursorEnable(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stfd      f31, 0x18(r1)
	  fmr       f31, f1
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  fmr       f2, f31
	  addi      r3, r31, 0x10
	  lfs       f1, -0x4DA8(r2)
	  bl        0x43E40
	  fmr       f2, f31
	  lfs       f1, -0x4DA8(r2)
	  addi      r3, r31, 0x50
	  bl        0x43E30
	  lwz       r0, 0x24(r1)
	  lfd       f31, 0x18(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80196E04
 * Size:	000054
 */
void zen::ogNitakuMgr::cursorDisable(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stfd      f31, 0x18(r1)
	  fmr       f31, f1
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  fmr       f2, f31
	  addi      r3, r31, 0x10
	  lfs       f1, -0x4DA4(r2)
	  bl        0x43DEC
	  fmr       f2, f31
	  lfs       f1, -0x4DA4(r2)
	  addi      r3, r31, 0x50
	  bl        0x43DDC
	  lwz       r0, 0x24(r1)
	  lfd       f31, 0x18(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80196E58
 * Size:	000344
 */
void zen::ogNitakuMgr::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, 0
	  bne-      .loc_0x24
	  b         .loc_0x330

	.loc_0x24:
	  cmpwi     r3, 0x2
	  beq-      .loc_0x7C
	  bge-      .loc_0x3C
	  cmpwi     r3, 0x1
	  bge-      .loc_0x48
	  b         .loc_0x30C

	.loc_0x3C:
	  cmpwi     r3, 0x4
	  bge-      .loc_0x30C
	  b         .loc_0xB0

	.loc_0x48:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xBC(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xBC(r31)
	  lfs       f1, 0xBC(r31)
	  lfs       f0, -0x4D90(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x30C
	  li        r0, 0x3
	  stw       r0, 0x0(r31)
	  b         .loc_0x30C

	.loc_0x7C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xBC(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xBC(r31)
	  lfs       f1, 0xBC(r31)
	  lfs       f0, -0x4D90(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x30C
	  lwz       r0, 0x4(r31)
	  stw       r0, 0x0(r31)
	  b         .loc_0x30C

	.loc_0xB0:
	  lwz       r4, 0x28(r4)
	  rlwinm.   r0,r4,0,12,12
	  beq-      .loc_0x188
	  lbz       r0, 0x90(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x124
	  lwz       r3, 0x98(r31)
	  addi      r4, r31, 0xAC
	  lfs       f1, -0x4D8C(r2)
	  addi      r5, r31, 0xB0
	  bl        0x1EE8
	  lwz       r3, 0xA0(r31)
	  addi      r4, r31, 0xA4
	  lfs       f1, -0x4D8C(r2)
	  addi      r5, r31, 0xA8
	  bl        0x1ED4
	  lfs       f1, 0x48(r31)
	  addi      r3, r31, 0x10
	  lfs       f2, 0x4C(r31)
	  lfs       f3, -0x4D8C(r2)
	  bl        0x43C50
	  lfs       f1, 0x88(r31)
	  addi      r3, r31, 0x50
	  lfs       f2, 0x8C(r31)
	  lfs       f3, -0x4D8C(r2)
	  bl        0x43C3C
	  li        r0, 0
	  stb       r0, 0x90(r31)
	  b         .loc_0x17C

	.loc_0x124:
	  lwz       r3, 0x98(r31)
	  addi      r4, r31, 0xA4
	  lfs       f1, -0x4D8C(r2)
	  addi      r5, r31, 0xA8
	  bl        0x1E8C
	  lwz       r3, 0xA0(r31)
	  addi      r4, r31, 0xAC
	  lfs       f1, -0x4D8C(r2)
	  addi      r5, r31, 0xB0
	  bl        0x1E78
	  lfs       f1, 0x40(r31)
	  addi      r3, r31, 0x10
	  lfs       f2, 0x44(r31)
	  lfs       f3, -0x4D8C(r2)
	  bl        0x43BF4
	  lfs       f1, 0x80(r31)
	  addi      r3, r31, 0x50
	  lfs       f2, 0x84(r31)
	  lfs       f3, -0x4D8C(r2)
	  bl        0x43BE0
	  li        r0, 0x1
	  stb       r0, 0x90(r31)

	.loc_0x17C:
	  li        r3, 0x112
	  bl        -0xF1C64
	  b         .loc_0x30C

	.loc_0x188:
	  rlwinm.   r0,r4,0,10,10
	  beq-      .loc_0x25C
	  lbz       r0, 0x90(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1F8
	  lwz       r3, 0x98(r31)
	  addi      r4, r31, 0xAC
	  lfs       f1, -0x4D8C(r2)
	  addi      r5, r31, 0xB0
	  bl        0x1E14
	  lwz       r3, 0xA0(r31)
	  addi      r4, r31, 0xA4
	  lfs       f1, -0x4D8C(r2)
	  addi      r5, r31, 0xA8
	  bl        0x1E00
	  lfs       f1, 0x48(r31)
	  addi      r3, r31, 0x10
	  lfs       f2, 0x4C(r31)
	  lfs       f3, -0x4D8C(r2)
	  bl        0x43B7C
	  lfs       f1, 0x88(r31)
	  addi      r3, r31, 0x50
	  lfs       f2, 0x8C(r31)
	  lfs       f3, -0x4D8C(r2)
	  bl        0x43B68
	  li        r0, 0
	  stb       r0, 0x90(r31)
	  b         .loc_0x250

	.loc_0x1F8:
	  lwz       r3, 0x98(r31)
	  addi      r4, r31, 0xA4
	  lfs       f1, -0x4D8C(r2)
	  addi      r5, r31, 0xA8
	  bl        0x1DB8
	  lwz       r3, 0xA0(r31)
	  addi      r4, r31, 0xAC
	  lfs       f1, -0x4D8C(r2)
	  addi      r5, r31, 0xB0
	  bl        0x1DA4
	  lfs       f1, 0x40(r31)
	  addi      r3, r31, 0x10
	  lfs       f2, 0x44(r31)
	  lfs       f3, -0x4D8C(r2)
	  bl        0x43B20
	  lfs       f1, 0x80(r31)
	  addi      r3, r31, 0x50
	  lfs       f2, 0x84(r31)
	  lfs       f3, -0x4D8C(r2)
	  bl        0x43B0C
	  li        r0, 0x1
	  stb       r0, 0x90(r31)

	.loc_0x250:
	  li        r3, 0x112
	  bl        -0xF1D38
	  b         .loc_0x30C

	.loc_0x25C:
	  lis       r3, 0x100
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0x2C4
	  lbz       r0, 0x90(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x284
	  li        r0, 0x5
	  stw       r0, 0x4(r31)
	  b         .loc_0x28C

	.loc_0x284:
	  li        r0, 0x6
	  stw       r0, 0x4(r31)

	.loc_0x28C:
	  lfs       f1, -0x4DA4(r2)
	  li        r0, 0x2
	  addi      r3, r31, 0x10
	  stfs      f1, 0xBC(r31)
	  stw       r0, 0x0(r31)
	  lfs       f2, -0x4D90(r2)
	  bl        0x43B1C
	  lfs       f1, -0x4DA4(r2)
	  addi      r3, r31, 0x50
	  lfs       f2, -0x4D90(r2)
	  bl        0x43B0C
	  li        r3, 0x111
	  bl        -0xF1DA0
	  b         .loc_0x30C

	.loc_0x2C4:
	  lbz       r0, 0xD(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x30C
	  rlwinm.   r0,r4,0,18,18
	  beq-      .loc_0x30C
	  li        r0, 0x4
	  stw       r0, 0x4(r31)
	  li        r0, 0x2
	  addi      r3, r31, 0x10
	  lfs       f1, -0x4DA4(r2)
	  stfs      f1, 0xBC(r31)
	  stw       r0, 0x0(r31)
	  lfs       f2, -0x4D90(r2)
	  bl        0x43AC8
	  lfs       f1, -0x4DA4(r2)
	  addi      r3, r31, 0x50
	  lfs       f2, -0x4D90(r2)
	  bl        0x43AB8

	.loc_0x30C:
	  lwz       r3, 0x0(r31)
	  cmpwi     r3, 0x4
	  blt-      .loc_0x31C
	  b         .loc_0x330

	.loc_0x31C:
	  addi      r3, r31, 0x10
	  bl        0x4369C
	  addi      r3, r31, 0x50
	  bl        0x43694
	  lwz       r3, 0x0(r31)

	.loc_0x330:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
