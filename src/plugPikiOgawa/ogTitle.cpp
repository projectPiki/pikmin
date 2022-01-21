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
 * Size:	000068
 */
void zen::ogScrTitleMgr::getGamePrefs()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::ogScrTitleMgr::setGamePrefs()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80181090
 * Size:	0004A8
 */
zen::ogScrTitleMgr::ogScrTitleMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  addi      r31, r3, 0
	  li        r3, 0x1D8
	  stw       r30, 0x70(r1)
	  stw       r29, 0x6C(r1)
	  addi      r29, r4, 0x3010
	  bl        -0x13A0B4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x48
	  addi      r4, r29, 0x1C
	  li        r5, 0
	  li        r6, 0
	  bl        0x42028

	.loc_0x48:
	  stw       r30, 0xC(r31)
	  li        r3, 0x1D8
	  bl        -0x13A0DC
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x70
	  addi      r4, r29, 0x34
	  li        r5, 0
	  li        r6, 0
	  bl        0x42000

	.loc_0x70:
	  stw       r30, 0x10(r31)
	  li        r3, 0x1D8
	  lwz       r0, 0xC(r31)
	  stw       r0, 0x14(r31)
	  bl        -0x13A10C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA0
	  addi      r4, r29, 0x4C
	  li        r5, 0
	  li        r6, 0
	  bl        0x41FD0

	.loc_0xA0:
	  stw       r30, 0x18(r31)
	  li        r3, 0x1D8
	  bl        -0x13A134
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xC8
	  addi      r4, r29, 0x64
	  li        r5, 0
	  li        r6, 0
	  bl        0x41FA8

	.loc_0xC8:
	  stw       r30, 0x1C(r31)
	  li        r3, 0x1D8
	  bl        -0x13A15C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xF0
	  addi      r4, r29, 0x7C
	  li        r5, 0
	  li        r6, 0
	  bl        0x41F80

	.loc_0xF0:
	  stw       r30, 0x20(r31)
	  li        r3, 0x1D8
	  bl        -0x13A184
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x118
	  addi      r4, r29, 0x94
	  li        r5, 0
	  li        r6, 0
	  bl        0x41F58

	.loc_0x118:
	  stw       r30, 0x24(r31)
	  li        r3, 0x6C
	  bl        -0x13A1AC
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x138
	  li        r4, 0
	  bl        0x3F14C

	.loc_0x138:
	  stw       r29, 0x8(r31)
	  lis       r29, 0x6261
	  addi      r4, r29, 0x636B
	  lfs       f0, -0x50A8(r2)
	  li        r5, 0x1
	  stfs      f0, 0x31B0(r13)
	  lwz       r3, 0xC(r31)
	  lwzu      r12, 0x4(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  li        r30, 0
	  stb       r30, 0xF0(r3)
	  addi      r4, r29, 0x636B
	  li        r5, 0x1
	  lwz       r3, 0x10(r31)
	  lwzu      r12, 0x4(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0xF0(r3)
	  addi      r4, r29, 0x636B
	  li        r5, 0x1
	  lwz       r3, 0x18(r31)
	  lwzu      r12, 0x4(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0xF0(r3)
	  addi      r4, r29, 0x636B
	  li        r5, 0x1
	  lwz       r3, 0x1C(r31)
	  lwzu      r12, 0x4(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0xF0(r3)
	  addi      r4, r29, 0x636B
	  li        r5, 0x1
	  lwz       r3, 0x20(r31)
	  lwzu      r12, 0x4(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0xF0(r3)
	  addi      r4, r29, 0x636B
	  li        r5, 0x1
	  lwz       r3, 0x24(r31)
	  lwzu      r12, 0x4(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0xF0(r3)
	  lis       r30, 0x6F6E
	  addi      r4, r30, 0x3231
	  lwz       r3, 0x1C(r31)
	  li        r5, 0x1
	  addi      r0, r3, 0x4
	  stw       r0, 0x2C(r31)
	  lwz       r3, 0x2C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x30(r31)
	  addi      r4, r30, 0x3232
	  li        r5, 0x1
	  lwz       r3, 0x2C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x34(r31)
	  addi      r4, r30, 0x5F63
	  li        r5, 0x1
	  lwz       r3, 0x2C(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x38(r31)
	  lis       r3, 0x6F66
	  addi      r4, r3, 0x6663
	  lwz       r3, 0x2C(r31)
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x3C(r31)
	  li        r3, 0x12C
	  bl        -0x13A330
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x2CC
	  lwz       r4, 0x30(r31)
	  li        r5, 0
	  lfs       f1, -0x50A4(r2)
	  li        r6, 0xFF
	  lfs       f2, -0x50A0(r2)
	  bl        -0x2224

	.loc_0x2CC:
	  stw       r29, 0x28(r31)
	  addi      r29, r31, 0
	  li        r30, 0

	.loc_0x2D8:
	  addi      r3, r1, 0x5C
	  crclr     6, 0x6
	  addi      r5, r30, 0x1
	  addi      r4, r13, 0xA08
	  bl        0x95220
	  lwz       r3, 0x2C(r31)
	  li        r5, 0x1
	  lbz       r0, 0x5D(r1)
	  lwz       r12, 0x0(r3)
	  lbz       r4, 0x5C(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x5E(r1)
	  lbz       r4, 0x5F(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  addi      r30, r30, 0x1
	  stw       r3, 0x40(r29)
	  cmpwi     r30, 0xA
	  addi      r29, r29, 0x4
	  blt+      .loc_0x2D8
	  li        r30, 0
	  addi      r29, r31, 0

	.loc_0x340:
	  addi      r3, r1, 0x5C
	  crclr     6, 0x6
	  addi      r5, r30, 0xB
	  addi      r4, r13, 0xA08
	  bl        0x951B8
	  lwz       r3, 0x2C(r31)
	  li        r5, 0x1
	  lbz       r0, 0x5D(r1)
	  lwz       r12, 0x0(r3)
	  lbz       r4, 0x5C(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x5E(r1)
	  lbz       r4, 0x5F(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  addi      r30, r30, 0x1
	  stw       r3, 0x68(r29)
	  cmpwi     r30, 0xA
	  addi      r29, r29, 0x4
	  blt+      .loc_0x340
	  li        r0, -0x1
	  stw       r0, 0x0(r31)
	  lis       r3, 0x803A
	  subi      r7, r3, 0x2848
	  lwz       r0, 0x0(r31)
	  li        r8, 0
	  addi      r9, r7, 0xAC
	  stw       r0, 0x4(r31)
	  li        r3, 0x3
	  li        r0, 0x111
	  stw       r8, 0x94(r31)
	  li        r4, 0x1
	  li        r5, 0
	  sth       r8, 0x98(r31)
	  lbz       r6, 0xB0(r7)
	  sth       r6, 0x9E(r31)
	  lbz       r6, 0xB1(r7)
	  sth       r6, 0xA0(r31)
	  lwz       r6, 0xAC(r7)
	  rlwinm    r6,r6,0,30,30
	  neg       r7, r6
	  subic     r6, r7, 0x1
	  subfe     r6, r6, r7
	  stb       r6, 0x9C(r31)
	  lwz       r6, 0x0(r9)
	  rlwinm    r6,r6,0,31,31
	  neg       r7, r6
	  subic     r6, r7, 0x1
	  subfe     r6, r6, r7
	  stb       r6, 0xA2(r31)
	  lwz       r6, 0x0(r9)
	  rlwinm    r6,r6,0,29,29
	  neg       r7, r6
	  subic     r6, r7, 0x1
	  subfe     r6, r6, r7
	  stb       r6, 0xA3(r31)
	  stb       r8, 0xA4(r31)
	  sth       r8, 0xA6(r31)
	  lfs       f0, -0x50A0(r2)
	  stfs      f0, 0x90(r31)
	  sth       r3, 0x9A(r31)
	  lwz       r3, 0x24(r31)
	  stw       r0, 0x1CC(r3)
	  lwz       r3, 0x20(r31)
	  stw       r0, 0x1CC(r3)
	  lwz       r3, 0x1C(r31)
	  stw       r0, 0x1CC(r3)
	  lwz       r3, 0x18(r31)
	  bl        0x4341C
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0xBB0
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0xC68
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0xD30
	  mr        r3, r31
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80181538
 * Size:	0000E4
 */
void zen::ogScrTitleMgr::start(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r6, r5, 0x2848
	  rlwinm.   r0,r4,0,24,31
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lbz       r5, 0xB0(r6)
	  sth       r5, 0x9E(r3)
	  lbz       r0, 0xB1(r6)
	  sth       r0, 0xA0(r3)
	  lwz       r0, 0xAC(r6)
	  rlwinm    r0,r0,0,30,30
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x9C(r31)
	  lwz       r0, 0xAC(r6)
	  rlwinm    r0,r0,0,31,31
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0xA2(r31)
	  lwz       r0, 0xAC(r6)
	  rlwinm    r0,r0,0,29,29
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0xA3(r31)
	  beq-      .loc_0x88
	  lwz       r0, 0x10(r31)
	  stw       r0, 0x14(r31)
	  b         .loc_0x90

	.loc_0x88:
	  lwz       r0, 0xC(r31)
	  stw       r0, 0x14(r31)

	.loc_0x90:
	  li        r3, 0x134
	  bl        -0xDC258
	  lwz       r3, 0x14(r31)
	  li        r4, -0x1
	  bl        0x426E0
	  li        r4, 0
	  sth       r4, 0x98(r31)
	  li        r3, 0x3
	  li        r0, 0x1
	  stb       r4, 0xA4(r31)
	  sth       r4, 0xA6(r31)
	  lfs       f0, -0x50A0(r2)
	  stfs      f0, 0x90(r31)
	  stw       r3, 0x4(r31)
	  stw       r0, 0x0(r31)
	  sth       r3, 0x9A(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018161C
 * Size:	0009F8
 */
void zen::ogScrTitleMgr::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stmw      r23, 0xA4(r1)
	  mr        r28, r3
	  addi      r29, r4, 0
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x28
	  b         .loc_0x9E4

	.loc_0x28:
	  cmpwi     r3, 0x1
	  bne-      .loc_0x58
	  lha       r3, 0x9A(r28)
	  subi      r0, r3, 0x1
	  sth       r0, 0x9A(r28)
	  lha       r0, 0x9A(r28)
	  cmpwi     r0, 0
	  bgt-      .loc_0x50
	  li        r0, 0
	  stw       r0, 0x0(r28)

	.loc_0x50:
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x58:
	  cmpwi     r3, 0x2
	  bne-      .loc_0x70
	  lwz       r0, 0x4(r28)
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x70:
	  cmpwi     r3, 0x3
	  blt-      .loc_0x88
	  li        r0, -0x1
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x88:
	  lwz       r3, 0x8(r28)
	  stw       r29, 0x0(r3)
	  lwz       r3, 0x8(r28)
	  bl        0x3ECF4
	  lwz       r0, 0x20(r29)
	  rlwinm.   r0,r0,0,0,31
	  beq-      .loc_0xAC
	  lfs       f0, -0x50A0(r2)
	  stfs      f0, 0x90(r28)

	.loc_0xAC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x90(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x90(r28)
	  lfs       f1, 0x90(r28)
	  lfs       f0, -0x509C(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xEC
	  addi      r3, r29, 0
	  li        r4, 0x2000
	  bl        -0x140D24
	  lwz       r3, 0x14(r28)
	  mr        r4, r29
	  bl        0x42DD0

	.loc_0xEC:
	  lha       r0, 0x98(r28)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x3F4
	  bge-      .loc_0x10C
	  cmpwi     r0, 0
	  beq-      .loc_0x11C
	  bge-      .loc_0x1F4
	  b         .loc_0x9E0

	.loc_0x10C:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x900
	  bge-      .loc_0x9E0
	  b         .loc_0x7E4

	.loc_0x11C:
	  lwz       r3, 0x14(r28)
	  mr        r4, r29
	  bl        0x42D94
	  lwz       r4, 0x14(r28)
	  lwz       r0, 0x1D0(r4)
	  lwz       r3, 0x100(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x144
	  lwz       r0, 0x110(r4)
	  b         .loc_0x15C

	.loc_0x144:
	  lbz       r0, 0x1D4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x158
	  li        r0, -0x1
	  b         .loc_0x15C

	.loc_0x158:
	  lwz       r0, 0x110(r4)

	.loc_0x15C:
	  cmpwi     r3, 0
	  stw       r0, 0x94(r28)
	  bne-      .loc_0x9E0
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x18C
	  li        r0, 0x4
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x18C:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1AC
	  li        r0, 0x1
	  sth       r0, 0x98(r28)
	  li        r4, 0
	  lwz       r3, 0x18(r28)
	  bl        0x424F8
	  b         .loc_0x9E0

	.loc_0x1AC:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x1CC
	  li        r0, 0x6
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x1CC:
	  lwz       r3, 0x14(r28)
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x9E0
	  li        r0, 0x3
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x1F4:
	  lwz       r3, 0x18(r28)
	  mr        r4, r29
	  bl        0x42CBC
	  lwz       r4, 0x18(r28)
	  lwz       r0, 0x1D0(r4)
	  lwz       r3, 0x100(r4)
	  cmpwi     r0, 0
	  blt-      .loc_0x21C
	  lwz       r0, 0x110(r4)
	  b         .loc_0x234

	.loc_0x21C:
	  lbz       r0, 0x1D4(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x230
	  li        r0, -0x1
	  b         .loc_0x234

	.loc_0x230:
	  lwz       r0, 0x110(r4)

	.loc_0x234:
	  cmpwi     r3, 0
	  stw       r0, 0x94(r28)
	  bne-      .loc_0x9E0
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x264
	  li        r0, 0x2
	  sth       r0, 0x98(r28)
	  li        r4, 0
	  lwz       r3, 0x1C(r28)
	  bl        0x42440
	  b         .loc_0x9E0

	.loc_0x264:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x2A0
	  li        r0, 0x4
	  sth       r0, 0x98(r28)
	  lbz       r0, 0xA3(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x290
	  lwz       r3, 0x24(r28)
	  li        r4, 0x1
	  bl        0x42414
	  b         .loc_0x9E0

	.loc_0x290:
	  lwz       r3, 0x24(r28)
	  li        r4, 0
	  bl        0x42404
	  b         .loc_0x9E0

	.loc_0x2A0:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x2DC
	  li        r0, 0x3
	  sth       r0, 0x98(r28)
	  lbz       r0, 0xA2(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x2CC
	  lwz       r3, 0x20(r28)
	  li        r4, 0
	  bl        0x423D8
	  b         .loc_0x9E0

	.loc_0x2CC:
	  lwz       r3, 0x20(r28)
	  li        r4, 0x1
	  bl        0x423C8
	  b         .loc_0x9E0

	.loc_0x2DC:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x2FC
	  li        r0, 0x7
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x2FC:
	  lwz       r3, 0x18(r28)
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x9E0
	  lis       r3, 0x803A
	  subi      r27, r3, 0x2848
	  lwz       r7, 0xAC(r27)
	  addi      r31, r27, 0x24
	  lbz       r30, 0xB0(r27)
	  addi      r3, r31, 0
	  rlwinm    r0,r7,0,31,31
	  neg       r6, r0
	  lbz       r29, 0xB1(r27)
	  subic     r5, r6, 0x1
	  rlwinm    r4,r7,0,30,30
	  rlwinm    r0,r7,0,29,29
	  subfe     r25, r5, r6
	  neg       r5, r4
	  subic     r4, r5, 0x1
	  subfe     r24, r4, r5
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  subfe     r23, r0, r4
	  li        r4, 0x1
	  bl        -0x10DA88
	  cmpwi     r3, 0
	  bne-      .loc_0x37C
	  lwz       r0, 0x5C(r27)
	  cmpwi     r0, 0
	  blt-      .loc_0x37C
	  mr        r3, r31
	  bl        -0x10D6A4

	.loc_0x37C:
	  lis       r3, 0x803A
	  subi      r27, r3, 0x2848
	  addi      r26, r27, 0x94
	  addi      r3, r26, 0
	  addi      r4, r25, 0
	  bl        -0x12DBF4
	  addi      r3, r26, 0
	  addi      r4, r24, 0
	  bl        -0x12DC9C
	  addi      r3, r26, 0
	  addi      r4, r23, 0
	  bl        -0x12DB54
	  addi      r3, r26, 0
	  addi      r4, r30, 0
	  bl        -0x12DD34
	  addi      r3, r26, 0
	  addi      r4, r29, 0
	  bl        -0x12DD00
	  li        r29, 0
	  stb       r29, 0xA8(r27)
	  mr        r3, r31
	  bl        -0x10D658
	  lwz       r3, 0x18(r28)
	  li        r4, -0x1
	  bl        0x42F40
	  lwz       r3, 0x14(r28)
	  li        r4, -0x1
	  bl        0x422B4
	  sth       r29, 0x98(r28)
	  b         .loc_0x9E0

	.loc_0x3F4:
	  lwz       r3, 0x1C(r28)
	  mr        r4, r29
	  bl        0x42ABC
	  lwz       r3, 0x1C(r28)
	  lwz       r0, 0x1D0(r3)
	  lwz       r31, 0x100(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x41C
	  lwz       r0, 0x110(r3)
	  b         .loc_0x434

	.loc_0x41C:
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x430
	  li        r0, -0x1
	  b         .loc_0x434

	.loc_0x430:
	  lwz       r0, 0x110(r3)

	.loc_0x434:
	  stw       r0, 0x94(r28)
	  lwz       r3, 0x8(r28)
	  lwz       r0, 0x4(r3)
	  rlwinm.   r0,r0,0,9,9
	  beq-      .loc_0x5BC
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x4E0
	  bge-      .loc_0x464
	  cmpwi     r0, 0
	  bge-      .loc_0x470
	  b         .loc_0x5BC

	.loc_0x464:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x5BC
	  b         .loc_0x550

	.loc_0x470:
	  lbz       r0, 0x9C(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x5BC
	  li        r0, 0x1
	  stb       r0, 0x9C(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DE1C
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DDEC
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12DDB8
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DD28
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DC7C
	  li        r3, 0x133
	  bl        -0x16AF54
	  b         .loc_0x5BC

	.loc_0x4E0:
	  lha       r3, 0x9E(r28)
	  cmpwi     r3, 0
	  ble-      .loc_0x5BC
	  subi      r0, r3, 0x1
	  sth       r0, 0x9E(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DE8C
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DE5C
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12DE28
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DD98
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DCEC
	  li        r3, 0x133
	  bl        -0x16AFC4
	  b         .loc_0x5BC

	.loc_0x550:
	  lha       r3, 0xA0(r28)
	  cmpwi     r3, 0
	  ble-      .loc_0x5BC
	  subi      r0, r3, 0x1
	  sth       r0, 0xA0(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DEFC
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DECC
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12DE98
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DE08
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DD5C
	  li        r3, 0x133
	  bl        -0x16B034

	.loc_0x5BC:
	  lwz       r3, 0x8(r28)
	  lwz       r0, 0x4(r3)
	  rlwinm.   r0,r0,0,11,11
	  beq-      .loc_0x740
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x664
	  bge-      .loc_0x5E8
	  cmpwi     r0, 0
	  bge-      .loc_0x5F4
	  b         .loc_0x740

	.loc_0x5E8:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x740
	  b         .loc_0x6D4

	.loc_0x5F4:
	  lbz       r0, 0x9C(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x740
	  li        r0, 0
	  stb       r0, 0x9C(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DFA0
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DF70
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12DF3C
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DEAC
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DE00
	  li        r3, 0x133
	  bl        -0x16B0D8
	  b         .loc_0x740

	.loc_0x664:
	  lha       r3, 0x9E(r28)
	  cmpwi     r3, 0xA
	  bge-      .loc_0x740
	  addi      r0, r3, 0x1
	  sth       r0, 0x9E(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E010
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12DFE0
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12DFAC
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DF1C
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DE70
	  li        r3, 0x133
	  bl        -0x16B148
	  b         .loc_0x740

	.loc_0x6D4:
	  lha       r3, 0xA0(r28)
	  cmpwi     r3, 0xA
	  bge-      .loc_0x740
	  addi      r0, r3, 0x1
	  sth       r0, 0xA0(r28)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lha       r0, 0x9E(r28)
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E080
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E050
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12E01C
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12DF8C
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12DEE0
	  li        r3, 0x133
	  bl        -0x16B1B8

	.loc_0x740:
	  lwz       r0, 0x94(r28)
	  addi      r3, r28, 0
	  neg       r0, r0
	  cntlzw    r0, r0
	  rlwinm    r4,r0,27,5,31
	  bl        0x33C
	  lwz       r0, 0x94(r28)
	  addi      r3, r28, 0
	  subfic    r0, r0, 0x1
	  cntlzw    r0, r0
	  rlwinm    r4,r0,27,5,31
	  bl        0x3E8
	  lwz       r0, 0x94(r28)
	  addi      r3, r28, 0
	  subfic    r0, r0, 0x2
	  cntlzw    r0, r0
	  rlwinm    r4,r0,27,5,31
	  bl        0x4A4
	  cmpwi     r31, 0
	  bne-      .loc_0x9E0
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  blt-      .loc_0x7B4
	  lwz       r3, 0x18(r28)
	  li        r4, -0x1
	  bl        0x41EF8
	  li        r0, 0x1
	  sth       r0, 0x98(r28)
	  b         .loc_0x9E0

	.loc_0x7B4:
	  lwz       r3, 0x1C(r28)
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x9E0
	  li        r4, -0x1
	  bl        0x42B54
	  lwz       r3, 0x18(r28)
	  li        r4, -0x1
	  bl        0x41EC8
	  li        r0, 0x1
	  sth       r0, 0x98(r28)
	  b         .loc_0x9E0

	.loc_0x7E4:
	  lwz       r3, 0x20(r28)
	  mr        r4, r29
	  bl        0x426CC
	  lwz       r3, 0x20(r28)
	  lwz       r0, 0x1D0(r3)
	  lwz       r27, 0x100(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x80C
	  lwz       r0, 0x110(r3)
	  b         .loc_0x824

	.loc_0x80C:
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x820
	  li        r0, -0x1
	  b         .loc_0x824

	.loc_0x820:
	  lwz       r0, 0x110(r3)

	.loc_0x824:
	  stw       r0, 0x94(r28)
	  lwz       r0, 0x28(r29)
	  andis.    r0, r0, 0x28
	  beq-      .loc_0x8A4
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x84C
	  li        r0, 0x1
	  stb       r0, 0xA2(r28)
	  b         .loc_0x854

	.loc_0x84C:
	  li        r0, 0
	  stb       r0, 0xA2(r28)

	.loc_0x854:
	  lis       r3, 0x803A
	  lha       r0, 0x9E(r28)
	  subi      r3, r3, 0x2848
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E1EC
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E1BC
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12E188
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12E0F8
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12E04C

	.loc_0x8A4:
	  cmpwi     r27, 0
	  bne-      .loc_0x9E0
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  blt-      .loc_0x8D0
	  lwz       r3, 0x18(r28)
	  li        r4, -0x1
	  bl        0x41DDC
	  li        r0, 0x1
	  sth       r0, 0x98(r28)
	  b         .loc_0x9E0

	.loc_0x8D0:
	  lwz       r3, 0x20(r28)
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x9E0
	  li        r4, -0x1
	  bl        0x42A38
	  lwz       r3, 0x18(r28)
	  li        r4, -0x1
	  bl        0x41DAC
	  li        r0, 0x1
	  sth       r0, 0x98(r28)
	  b         .loc_0x9E0

	.loc_0x900:
	  lwz       r3, 0x24(r28)
	  mr        r4, r29
	  bl        0x425B0
	  lwz       r3, 0x24(r28)
	  lwz       r0, 0x1D0(r3)
	  lwz       r27, 0x100(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x928
	  lwz       r0, 0x110(r3)
	  b         .loc_0x940

	.loc_0x928:
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x93C
	  li        r0, -0x1
	  b         .loc_0x940

	.loc_0x93C:
	  lwz       r0, 0x110(r3)

	.loc_0x940:
	  stw       r0, 0x94(r28)
	  lwz       r0, 0x28(r29)
	  andis.    r0, r0, 0x28
	  beq-      .loc_0x9C0
	  lwz       r0, 0x94(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x968
	  li        r0, 0
	  stb       r0, 0xA3(r28)
	  b         .loc_0x970

	.loc_0x968:
	  li        r0, 0x1
	  stb       r0, 0xA3(r28)

	.loc_0x970:
	  lis       r3, 0x803A
	  lha       r0, 0x9E(r28)
	  subi      r3, r3, 0x2848
	  addi      r26, r3, 0x94
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E308
	  lha       r0, 0xA0(r28)
	  addi      r3, r26, 0
	  rlwinm    r4,r0,0,24,31
	  bl        -0x12E2D8
	  mr        r3, r26
	  lbz       r4, 0x9C(r28)
	  bl        -0x12E2A4
	  mr        r3, r26
	  lbz       r4, 0xA2(r28)
	  bl        -0x12E214
	  mr        r3, r26
	  lbz       r4, 0xA3(r28)
	  bl        -0x12E168

	.loc_0x9C0:
	  cmpwi     r27, 0
	  bne-      .loc_0x9E0
	  li        r0, 0x3
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  stw       r0, 0x0(r28)
	  lwz       r3, 0x0(r28)
	  b         .loc_0x9E4

	.loc_0x9E0:
	  lwz       r3, 0x0(r28)

	.loc_0x9E4:
	  lmw       r23, 0xA4(r1)
	  lwz       r0, 0xCC(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80182014
 * Size:	000098
 */
void zen::ogScrTitleMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x88
	  cmpwi     r0, 0x1
	  beq-      .loc_0x88
	  lha       r0, 0x98(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x68
	  bge-      .loc_0x40
	  cmpwi     r0, 0
	  beq-      .loc_0x50
	  bge-      .loc_0x5C
	  b         .loc_0x88

	.loc_0x40:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x80
	  bge-      .loc_0x88
	  b         .loc_0x74

	.loc_0x50:
	  lwz       r3, 0x14(r3)
	  bl        0x42878
	  b         .loc_0x88

	.loc_0x5C:
	  lwz       r3, 0x18(r3)
	  bl        0x4286C
	  b         .loc_0x88

	.loc_0x68:
	  lwz       r3, 0x1C(r3)
	  bl        0x42860
	  b         .loc_0x88

	.loc_0x74:
	  lwz       r3, 0x20(r3)
	  bl        0x42854
	  b         .loc_0x88

	.loc_0x80:
	  lwz       r3, 0x24(r3)
	  bl        0x42848

	.loc_0x88:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801820AC
 * Size:	0000C4
 */
void zen::ogScrTitleMgr::StereoOnOff(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  mr        r30, r3
	  lbz       r0, 0x9C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  lwz       r3, 0x38(r30)
	  lwz       r4, 0x30(r30)
	  bl        -0x3648
	  lwz       r3, 0x3C(r30)
	  lwz       r4, 0x34(r30)
	  bl        -0x3654
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x5C
	  lwz       r3, 0x28(r30)
	  lwz       r0, 0x30(r30)
	  stw       r0, 0x4(r3)
	  bl        -0x29B8
	  b         .loc_0xAC

	.loc_0x5C:
	  lwz       r3, 0x30(r30)
	  li        r0, 0xFF
	  stb       r0, 0xF0(r3)
	  b         .loc_0xAC

	.loc_0x6C:
	  lwz       r3, 0x3C(r30)
	  lwz       r4, 0x30(r30)
	  bl        -0x368C
	  lwz       r3, 0x38(r30)
	  lwz       r4, 0x34(r30)
	  bl        -0x3698
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0xA0
	  lwz       r3, 0x28(r30)
	  lwz       r0, 0x34(r30)
	  stw       r0, 0x4(r3)
	  bl        -0x29FC
	  b         .loc_0xAC

	.loc_0xA0:
	  lwz       r3, 0x34(r30)
	  li        r0, 0xFF
	  stb       r0, 0xF0(r3)

	.loc_0xAC:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80182170
 * Size:	0000D4
 */
void zen::ogScrTitleMgr::DispBarBGM(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  rlwinm    r31,r4,0,24,31
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  li        r29, 0
	  rlwinm    r0,r29,2,0,29
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  add       r30, r28, r0

	.loc_0x30:
	  lha       r3, 0x9E(r28)
	  subi      r0, r3, 0x1
	  cmpw      r29, r0
	  bge-      .loc_0x5C
	  lwz       r3, 0x38(r28)
	  lwz       r4, 0x40(r30)
	  bl        -0x3724
	  lwz       r3, 0x40(r30)
	  li        r0, 0xFF
	  stb       r0, 0xF0(r3)
	  b         .loc_0xA4

	.loc_0x5C:
	  bne-      .loc_0x98
	  lwz       r3, 0x38(r28)
	  lwz       r4, 0x40(r30)
	  bl        -0x3744
	  cmplwi    r31, 0
	  beq-      .loc_0x88
	  lwz       r3, 0x28(r28)
	  lwz       r0, 0x40(r30)
	  stw       r0, 0x4(r3)
	  bl        -0x2AA8
	  b         .loc_0xA4

	.loc_0x88:
	  lwz       r3, 0x40(r30)
	  li        r0, 0xFF
	  stb       r0, 0xF0(r3)
	  b         .loc_0xA4

	.loc_0x98:
	  lwz       r3, 0x3C(r28)
	  lwz       r4, 0x40(r30)
	  bl        -0x377C

	.loc_0xA4:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0xA
	  addi      r30, r30, 0x4
	  blt+      .loc_0x30
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80182244
 * Size:	0000D4
 */
void zen::ogScrTitleMgr::DispBarSE(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  rlwinm    r31,r4,0,24,31
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  li        r29, 0
	  rlwinm    r0,r29,2,0,29
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  add       r30, r28, r0

	.loc_0x30:
	  lha       r3, 0xA0(r28)
	  subi      r0, r3, 0x1
	  cmpw      r29, r0
	  bge-      .loc_0x5C
	  lwz       r3, 0x38(r28)
	  lwz       r4, 0x68(r30)
	  bl        -0x37F8
	  lwz       r3, 0x68(r30)
	  li        r0, 0xFF
	  stb       r0, 0xF0(r3)
	  b         .loc_0xA4

	.loc_0x5C:
	  bne-      .loc_0x98
	  lwz       r3, 0x38(r28)
	  lwz       r4, 0x68(r30)
	  bl        -0x3818
	  cmplwi    r31, 0
	  beq-      .loc_0x88
	  lwz       r3, 0x28(r28)
	  lwz       r0, 0x68(r30)
	  stw       r0, 0x4(r3)
	  bl        -0x2B7C
	  b         .loc_0xA4

	.loc_0x88:
	  lwz       r3, 0x68(r30)
	  li        r0, 0xFF
	  stb       r0, 0xF0(r3)
	  b         .loc_0xA4

	.loc_0x98:
	  lwz       r3, 0x3C(r28)
	  lwz       r4, 0x68(r30)
	  bl        -0x3850

	.loc_0xA4:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0xA
	  addi      r30, r30, 0x4
	  blt+      .loc_0x30
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
