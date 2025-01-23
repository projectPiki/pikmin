#include "P2D/Window.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	801B37F0
 * Size:	000088
 */
void P2DWindow::makeResident()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x104(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10C(r31)
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x108(r31)
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x110(r31)
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
Texture* P2DWindow::loadResource(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B3878
 * Size:	000160
 */
void P2DWindow::loadResource()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r3, 0
	  li        r3, 0x4
	  stw       r30, 0x50(r1)
	  bl        -0x16C890
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x50
	  lwz       r3, 0xEC(r31)
	  li        r0, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x3ED24
	  mr        r0, r3

	.loc_0x4C:
	  stw       r0, 0x0(r30)

	.loc_0x50:
	  stw       r30, 0x104(r31)
	  li        r3, 0x4
	  bl        -0x16C8CC
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x8C
	  lwz       r3, 0xF0(r31)
	  li        r0, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x88
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x3ECE8
	  mr        r0, r3

	.loc_0x88:
	  stw       r0, 0x0(r30)

	.loc_0x8C:
	  stw       r30, 0x108(r31)
	  li        r3, 0x4
	  bl        -0x16C908
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xC8
	  lwz       r3, 0xF4(r31)
	  li        r0, 0
	  cmplwi    r3, 0
	  beq-      .loc_0xC4
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x3ECAC
	  mr        r0, r3

	.loc_0xC4:
	  stw       r0, 0x0(r30)

	.loc_0xC8:
	  stw       r30, 0x10C(r31)
	  li        r3, 0x4
	  bl        -0x16C944
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x104
	  lwz       r3, 0xF8(r31)
	  li        r0, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x100
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x3EC70
	  mr        r0, r3

	.loc_0x100:
	  stw       r0, 0x0(r30)

	.loc_0x104:
	  stw       r30, 0x110(r31)
	  lwz       r4, 0x104(r31)
	  lwz       r3, 0x108(r31)
	  lwz       r4, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  lhz       r4, 0x8(r4)
	  lhz       r0, 0x8(r3)
	  add       r0, r4, r0
	  sth       r0, 0x128(r31)
	  lwz       r4, 0x104(r31)
	  lwz       r3, 0x10C(r31)
	  lwz       r4, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  lhz       r4, 0xA(r4)
	  lhz       r0, 0xA(r3)
	  add       r0, r4, r0
	  sth       r0, 0x12A(r31)
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B39D8
 * Size:	000258
 */
P2DWindow::P2DWindow(P2DPane*, RandomAccessStream*, u16)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  mr        r29, r5
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        -0x2EC8
	  lwz       r30, 0x8(r1)
	  lis       r3, 0x802E
	  addi      r0, r3, 0x848
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0xFC
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  bl        -0x3FC
	  stw       r29, 0x2C(r1)
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  sth       r0, 0xFC(r30)
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  sth       r0, 0xFE(r30)
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lha       r0, 0xFC(r30)
	  add       r0, r0, r3
	  sth       r0, 0x100(r30)
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lha       r0, 0xFE(r30)
	  lis       r31, 0x5449
	  addi      r4, r31, 0x4D47
	  add       r0, r0, r3
	  sth       r0, 0x102(r30)
	  addi      r3, r1, 0x2C
	  bl        -0x83C
	  stw       r3, 0xEC(r30)
	  addi      r3, r1, 0x2C
	  addi      r4, r31, 0x4D47
	  bl        -0x84C
	  stw       r3, 0xF0(r30)
	  addi      r3, r1, 0x2C
	  addi      r4, r31, 0x4D47
	  bl        -0x85C
	  stw       r3, 0xF4(r30)
	  addi      r3, r1, 0x2C
	  addi      r4, r31, 0x4D47
	  bl        -0x86C
	  stw       r3, 0xF8(r30)
	  lis       r4, 0x544C
	  addi      r3, r1, 0x2C
	  addi      r4, r4, 0x5554
	  bl        -0x880
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  stw       r0, 0x114(r30)
	  addi      r4, r1, 0x28
	  li        r5, 0x4
	  lwz       r3, 0x2C(r1)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lbz       r7, 0x2B(r1)
	  addi      r4, r1, 0x24
	  lbz       r6, 0x2A(r1)
	  li        r5, 0x4
	  lbz       r3, 0x29(r1)
	  lbz       r0, 0x28(r1)
	  stb       r0, 0x118(r30)
	  stb       r3, 0x119(r30)
	  stb       r6, 0x11A(r30)
	  stb       r7, 0x11B(r30)
	  lwz       r3, 0x2C(r1)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lbz       r7, 0x27(r1)
	  addi      r4, r1, 0x20
	  lbz       r6, 0x26(r1)
	  li        r5, 0x4
	  lbz       r3, 0x25(r1)
	  lbz       r0, 0x24(r1)
	  stb       r0, 0x11C(r30)
	  stb       r3, 0x11D(r30)
	  stb       r6, 0x11E(r30)
	  stb       r7, 0x11F(r30)
	  lwz       r3, 0x2C(r1)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lbz       r7, 0x23(r1)
	  addi      r4, r1, 0x1C
	  lbz       r6, 0x22(r1)
	  li        r5, 0x4
	  lbz       r3, 0x21(r1)
	  lbz       r0, 0x20(r1)
	  stb       r0, 0x120(r30)
	  stb       r3, 0x121(r30)
	  stb       r6, 0x122(r30)
	  stb       r7, 0x123(r30)
	  lwz       r3, 0x2C(r1)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lbz       r7, 0x1F(r1)
	  addi      r3, r1, 0x2C
	  lbz       r6, 0x1E(r1)
	  li        r4, 0x4
	  lbz       r5, 0x1D(r1)
	  lbz       r0, 0x1C(r1)
	  stb       r0, 0x124(r30)
	  stb       r5, 0x125(r30)
	  stb       r6, 0x126(r30)
	  stb       r7, 0x127(r30)
	  bl        -0x8D4
	  mr        r3, r30
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B3C30
 * Size:	000068
 */
void P2DWindow::drawSelf(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x60(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x5C(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x14
	  bl        -0x175E9C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x30(r12)
	  addi      r6, r1, 0x14
	  mtlr      r12
	  blrl
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B3C98
 * Size:	000098
 */
void P2DWindow::drawSelf(int, int, Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x28(r1)
	  mr        r30, r5
	  stw       r29, 0x24(r1)
	  mr        r29, r4
	  stw       r28, 0x20(r1)
	  mr        r28, r3
	  lha       r0, 0x24(r3)
	  lha       r7, 0x26(r3)
	  lha       r4, 0x20(r3)
	  mr        r6, r0
	  lha       r5, 0x22(r3)
	  addi      r3, r1, 0x18
	  bl        -0x6B4
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  bl        -0x67C
	  addi      r3, r28, 0
	  addi      r6, r31, 0
	  addi      r4, r1, 0x18
	  addi      r5, r28, 0xFC
	  bl        .loc_0x98
	  addi      r3, r28, 0
	  addi      r4, r28, 0xFC
	  bl        -0x29C4
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x98:
	*/
}

/*
 * --INFO--
 * Address:	801B3D30
 * Size:	000394
 */
void P2DWindow::draw_private(const PUTRect&, const PUTRect&, Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stmw      r26, 0xA8(r1)
	  addi      r27, r4, 0
	  addi      r31, r3, 0
	  mr        r26, r5
	  lha       r4, 0x0(r4)
	  lha       r3, 0x4(r27)
	  lha       r0, 0x128(r31)
	  sub       r3, r3, r4
	  cmpw      r3, r0
	  blt-      .loc_0x380
	  lha       r4, 0x2(r27)
	  lha       r3, 0x6(r27)
	  lha       r0, 0x12A(r31)
	  sub       r3, r3, r4
	  cmpw      r3, r0
	  blt-      .loc_0x380
	  addi      r3, r6, 0
	  addi      r4, r31, 0x78
	  addi      r5, r1, 0x68
	  bl        -0x175CB4
	  addi      r3, r1, 0x68
	  li        r4, 0
	  bl        0x606C0
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        .loc_0x394
	  lwz       r3, 0x110(r31)
	  lha       r5, 0x0(r27)
	  lwz       r7, 0x0(r3)
	  lha       r4, 0x4(r27)
	  lha       r3, 0x2(r27)
	  lha       r0, 0x6(r27)
	  sub       r5, r4, r5
	  lhz       r6, 0x8(r7)
	  lhz       r4, 0xA(r7)
	  sub       r0, r0, r3
	  sub       r29, r5, r6
	  sub       r30, r0, r4
	  bl        0x5BE28
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x5B620
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x5B614
	  li        r3, 0xD
	  li        r4, 0x1
	  bl        0x5B608
	  li        r3, 0x1
	  bl        0x5C928
	  lwz       r8, 0x114(r31)
	  li        r4, 0
	  lwz       r3, 0x104(r31)
	  li        r5, 0
	  rlwinm    r0,r8,0,24,24
	  neg       r7, r0
	  subic     r6, r7, 0x1
	  rlwinm    r0,r8,0,25,25
	  subfe     r7, r6, r7
	  neg       r6, r0
	  subic     r0, r6, 0x1
	  subfe     r0, r0, r6
	  rlwinm    r6,r7,0,24,31
	  rlwinm    r7,r0,0,24,31
	  bl        0x514
	  lwz       r8, 0x114(r31)
	  mr        r4, r29
	  lwz       r3, 0x108(r31)
	  li        r5, 0
	  rlwinm    r0,r8,0,26,26
	  neg       r7, r0
	  subic     r6, r7, 0x1
	  rlwinm    r0,r8,0,27,27
	  subfe     r7, r6, r7
	  neg       r6, r0
	  subic     r0, r6, 0x1
	  subfe     r0, r0, r6
	  rlwinm    r6,r7,0,24,31
	  rlwinm    r7,r0,0,24,31
	  bl        0x4D8
	  lwz       r8, 0x114(r31)
	  mr        r5, r30
	  lwz       r3, 0x10C(r31)
	  li        r4, 0
	  rlwinm    r0,r8,0,28,28
	  neg       r7, r0
	  subic     r6, r7, 0x1
	  rlwinm    r0,r8,0,29,29
	  subfe     r7, r6, r7
	  neg       r6, r0
	  subic     r0, r6, 0x1
	  subfe     r0, r0, r6
	  rlwinm    r6,r7,0,24,31
	  rlwinm    r7,r0,0,24,31
	  bl        0x49C
	  lwz       r8, 0x114(r31)
	  mr        r4, r29
	  lwz       r3, 0x110(r31)
	  addi      r5, r30, 0
	  rlwinm    r0,r8,0,30,30
	  neg       r7, r0
	  subic     r6, r7, 0x1
	  rlwinm    r0,r8,0,31,31
	  subfe     r7, r6, r7
	  neg       r6, r0
	  subic     r0, r6, 0x1
	  subfe     r0, r0, r6
	  rlwinm    r6,r7,0,24,31
	  rlwinm    r7,r0,0,24,31
	  bl        0x460
	  lwz       r3, 0x104(r31)
	  lwz       r5, 0x114(r31)
	  lwz       r4, 0x0(r3)
	  rlwinm.   r0,r5,0,26,26
	  lhz       r26, 0x8(r4)
	  lhz       r28, 0xA(r4)
	  beq-      .loc_0x1EC
	  lis       r3, 0x1
	  subi      r3, r3, 0x8000
	  b         .loc_0x1F0

	.loc_0x1EC:
	  li        r3, 0

	.loc_0x1F0:
	  rlwinm.   r0,r5,0,27,27
	  addi      r10, r3, 0
	  addi      r8, r10, 0
	  beq-      .loc_0x208
	  li        r0, 0
	  b         .loc_0x210

	.loc_0x208:
	  lis       r3, 0x1
	  subi      r0, r3, 0x8000

	.loc_0x210:
	  lwz       r3, 0x108(r31)
	  mr        r9, r0
	  sub       r27, r29, r26
	  lwz       r4, 0x0(r3)
	  xori      r0, r0, 0x8000
	  addi      r6, r27, 0
	  lhz       r7, 0xA(r4)
	  addi      r4, r26, 0
	  li        r5, 0
	  stw       r0, 0x8(r1)
	  bl        0x2E8
	  lwz       r4, 0x114(r31)
	  rlwinm.   r0,r4,0,30,30
	  beq-      .loc_0x254
	  lis       r3, 0x1
	  subi      r10, r3, 0x8000
	  b         .loc_0x258

	.loc_0x254:
	  li        r10, 0

	.loc_0x258:
	  rlwinm.   r0,r4,0,31,31
	  beq-      .loc_0x268
	  li        r9, 0
	  b         .loc_0x270

	.loc_0x268:
	  lis       r3, 0x1
	  subi      r9, r3, 0x8000

	.loc_0x270:
	  lwz       r3, 0x110(r31)
	  xori      r0, r9, 0x8000
	  mr        r4, r26
	  lwz       r5, 0x0(r3)
	  addi      r6, r27, 0
	  mr        r8, r10
	  lhz       r7, 0xA(r5)
	  addi      r5, r30, 0
	  stw       r0, 0x8(r1)
	  bl        0x28C
	  lwz       r4, 0x114(r31)
	  rlwinm.   r0,r4,0,28,28
	  beq-      .loc_0x2AC
	  li        r8, 0
	  b         .loc_0x2B4

	.loc_0x2AC:
	  lis       r3, 0x1
	  subi      r8, r3, 0x8000

	.loc_0x2B4:
	  rlwinm.   r0,r4,0,29,29
	  xori      r10, r8, 0x8000
	  beq-      .loc_0x2CC
	  lis       r3, 0x1
	  subi      r9, r3, 0x8000
	  b         .loc_0x2D0

	.loc_0x2CC:
	  li        r9, 0

	.loc_0x2D0:
	  lwz       r3, 0x10C(r31)
	  sub       r30, r30, r28
	  addi      r5, r28, 0
	  lwz       r4, 0x0(r3)
	  addi      r7, r30, 0
	  lhz       r6, 0x8(r4)
	  li        r4, 0
	  stw       r9, 0x8(r1)
	  bl        0x230
	  lwz       r4, 0x114(r31)
	  rlwinm.   r0,r4,0,30,30
	  beq-      .loc_0x308
	  li        r8, 0
	  b         .loc_0x310

	.loc_0x308:
	  lis       r3, 0x1
	  subi      r8, r3, 0x8000

	.loc_0x310:
	  rlwinm.   r0,r4,0,31,31
	  xori      r10, r8, 0x8000
	  beq-      .loc_0x328
	  lis       r3, 0x1
	  subi      r9, r3, 0x8000
	  b         .loc_0x32C

	.loc_0x328:
	  li        r9, 0

	.loc_0x32C:
	  lwz       r3, 0x110(r31)
	  mr        r4, r29
	  addi      r7, r30, 0
	  lwz       r5, 0x0(r3)
	  lhz       r6, 0x8(r5)
	  addi      r5, r28, 0
	  stw       r9, 0x8(r1)
	  bl        0x1D8
	  li        r3, 0
	  bl        0x5C6A8
	  li        r3, 0
	  li        r4, 0x4
	  bl        0x5EF10
	  li        r3, 0
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0x4
	  bl        0x5F724
	  li        r3, 0xD
	  li        r4, 0
	  bl        0x5B354

	.loc_0x380:
	  lmw       r26, 0xA8(r1)
	  lwz       r0, 0xC4(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr

	.loc_0x394:
	*/
}

/*
 * --INFO--
 * Address:	801B40C4
 * Size:	00018C
 */
void P2DWindow::drawContents(const PUTRect&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  bl        -0x924
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x174
	  bl        0x5BB0C
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x5B304
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x5B2F8
	  li        r3, 0x1
	  bl        0x5DDC4
	  li        r3, 0
	  bl        0x5C610
	  li        r3, 0x1
	  bl        0x5F844
	  li        r3, 0
	  li        r4, 0x4
	  bl        0x5EE70
	  li        r3, 0
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0x4
	  bl        0x5F684
	  li        r3, 0x4
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  li        r9, 0x2
	  bl        0x5DDC0
	  lbz       r0, 0x11B(r30)
	  cmplwi    r0, 0xFF
	  bne-      .loc_0xE8
	  lbz       r0, 0x11F(r30)
	  cmplwi    r0, 0xFF
	  bne-      .loc_0xE8
	  lbz       r0, 0x123(r30)
	  cmplwi    r0, 0xFF
	  bne-      .loc_0xE8
	  lbz       r0, 0x127(r30)
	  cmplwi    r0, 0xFF
	  bne-      .loc_0xE8
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0xF
	  bl        0x5FAA8
	  b         .loc_0xFC

	.loc_0xE8:
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0xF
	  bl        0x5FA90

	.loc_0xFC:
	  li        r3, 0x80
	  li        r4, 0
	  li        r5, 0x4
	  bl        0x5CA08
	  lha       r7, 0x2(r31)
	  lis       r5, 0xCC01
	  lha       r6, 0x0(r31)
	  li        r4, 0
	  sth       r6, -0x8000(r5)
	  sth       r7, -0x8000(r5)
	  sth       r4, -0x8000(r5)
	  lwz       r0, 0x118(r30)
	  stw       r0, -0x8000(r5)
	  lha       r3, 0x4(r31)
	  sth       r3, -0x8000(r5)
	  sth       r7, -0x8000(r5)
	  sth       r4, -0x8000(r5)
	  lwz       r0, 0x11C(r30)
	  stw       r0, -0x8000(r5)
	  lha       r7, 0x6(r31)
	  sth       r3, -0x8000(r5)
	  sth       r7, -0x8000(r5)
	  sth       r4, -0x8000(r5)
	  lwz       r0, 0x124(r30)
	  stw       r0, -0x8000(r5)
	  sth       r6, -0x8000(r5)
	  sth       r7, -0x8000(r5)
	  sth       r4, -0x8000(r5)
	  lwz       r0, 0x120(r30)
	  stw       r0, -0x8000(r5)

	.loc_0x174:
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
 * Address:	801B4250
 * Size:	000100
 */
void P2DWindow::P2DWindowTexture::draw(int, int, int, int, u16, u16, u16, u16)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r23, 0x2C(r1)
	  mr        r23, r3
	  addi      r24, r4, 0
	  lhz       r29, 0x5A(r1)
	  addi      r25, r5, 0
	  addi      r26, r8, 0
	  addi      r27, r9, 0
	  addi      r28, r10, 0
	  add       r31, r24, r6
	  add       r30, r25, r7
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r23)
	  li        r4, 0
	  lwz       r3, 0x24(r3)
	  bl        0x5E4C0
	  mr        r3, r23
	  bl        0x144
	  li        r3, 0x80
	  li        r4, 0
	  li        r5, 0x4
	  bl        0x5C918
	  extsh     r8, r24
	  lis       r7, 0xCC01
	  sth       r8, -0x8000(r7)
	  extsh     r6, r25
	  li        r5, 0
	  sth       r6, -0x8000(r7)
	  li        r4, -0x1
	  extsh     r3, r31
	  sth       r5, -0x8000(r7)
	  extsh     r0, r30
	  stw       r4, -0x8000(r7)
	  sth       r28, -0x8000(r7)
	  sth       r29, -0x8000(r7)
	  sth       r3, -0x8000(r7)
	  sth       r6, -0x8000(r7)
	  sth       r5, -0x8000(r7)
	  stw       r4, -0x8000(r7)
	  sth       r26, -0x8000(r7)
	  sth       r29, -0x8000(r7)
	  sth       r3, -0x8000(r7)
	  sth       r0, -0x8000(r7)
	  sth       r5, -0x8000(r7)
	  stw       r4, -0x8000(r7)
	  sth       r26, -0x8000(r7)
	  sth       r27, -0x8000(r7)
	  sth       r8, -0x8000(r7)
	  sth       r0, -0x8000(r7)
	  sth       r5, -0x8000(r7)
	  stw       r4, -0x8000(r7)
	  sth       r28, -0x8000(r7)
	  sth       r27, -0x8000(r7)
	  lwz       r0, 0x54(r1)
	  lmw       r23, 0x2C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B4350
 * Size:	0000A0
 */
void P2DWindow::P2DWindowTexture::draw(int, int, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r7,0,24,31
	  stwu      r1, -0x20(r1)
	  beq-      .loc_0x20
	  lis       r8, 0x1
	  subi      r9, r8, 0x8000
	  b         .loc_0x24

	.loc_0x20:
	  li        r9, 0

	.loc_0x24:
	  rlwinm.   r0,r6,0,24,31
	  beq-      .loc_0x38
	  lis       r8, 0x1
	  subi      r10, r8, 0x8000
	  b         .loc_0x3C

	.loc_0x38:
	  li        r10, 0

	.loc_0x3C:
	  rlwinm.   r0,r7,0,24,31
	  beq-      .loc_0x4C
	  li        r11, 0
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r7, 0x1
	  subi      r11, r7, 0x8000

	.loc_0x54:
	  rlwinm.   r0,r6,0,24,31
	  beq-      .loc_0x64
	  li        r7, 0
	  b         .loc_0x6C

	.loc_0x64:
	  lis       r6, 0x1
	  subi      r7, r6, 0x8000

	.loc_0x6C:
	  lwz       r12, 0x0(r3)
	  rlwinm    r0,r9,0,16,31
	  rlwinm    r8,r7,0,16,31
	  stw       r0, 0x8(r1)
	  rlwinm    r9,r11,0,16,31
	  rlwinm    r10,r10,0,16,31
	  lhz       r6, 0x8(r12)
	  lhz       r7, 0xA(r12)
	  bl        -0x18C
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B43F0
 * Size:	000058
 */
void P2DWindow::P2DWindowTexture::setTevMode()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x5F564
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x5F3B0
	  li        r3, 0
	  li        r4, 0x3
	  bl        0x5EB7C
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0xF
	  bl        0x5F818
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B4448
 * Size:	000064
 */
P2DWindow::~P2DWindow()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x48
	  lis       r3, 0x802E
	  addi      r0, r3, 0x848
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x36B8
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x16D2E0

	.loc_0x48:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
