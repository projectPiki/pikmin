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
 * Address:	........
 * Size:	00009C
 */
P2DGrafContext::P2DGrafContext(const PUTRect&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801AF7AC
 * Size:	0000B4
 */
P2DGrafContext::P2DGrafContext(int, int, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r8, 0x802E
	  stw       r0, 0x4(r1)
	  addi      r0, r8, 0x5D4
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  add       r30, r28, r6
	  add       r31, r29, r7
	  addi      r27, r3, 0
	  addi      r6, r30, 0
	  addi      r7, r31, 0
	  stw       r0, 0x0(r3)
	  addi      r3, r27, 0x8
	  bl        0x3E40
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  addi      r6, r30, 0
	  addi      r7, r31, 0
	  addi      r3, r27, 0x10
	  bl        0x3E28
	  li        r3, 0
	  sth       r3, 0x2A(r27)
	  addi      r4, r1, 0x1C
	  li        r0, 0xFF
	  sth       r3, 0x2C(r27)
	  addi      r3, r27, 0
	  addi      r5, r4, 0
	  stb       r0, 0x1C(r1)
	  addi      r6, r4, 0
	  addi      r7, r4, 0
	  stb       r0, 0x1D(r1)
	  stb       r0, 0x1E(r1)
	  stb       r0, 0x1F(r1)
	  bl        0x340
	  addi      r3, r27, 0
	  li        r4, 0x6
	  bl        0x3E0
	  mr        r3, r27
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AF860
 * Size:	0000CC
 */
void P2DGrafContext::setPort()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x4330
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lha       r6, 0xA(r3)
	  lha       r0, 0xE(r3)
	  xoris     r4, r6, 0x8000
	  lha       r7, 0x8(r3)
	  lha       r3, 0xC(r3)
	  sub       r6, r0, r6
	  xoris     r0, r7, 0x8000
	  stw       r4, 0x24(r1)
	  sub       r3, r3, r7
	  stw       r0, 0x2C(r1)
	  xoris     r3, r3, 0x8000
	  xoris     r0, r6, 0x8000
	  lfd       f4, -0x4998(r2)
	  stw       r3, 0x1C(r1)
	  lfs       f5, -0x49A0(r2)
	  stw       r0, 0x14(r1)
	  lfs       f6, -0x499C(r2)
	  stw       r5, 0x20(r1)
	  stw       r5, 0x28(r1)
	  lfd       f0, 0x20(r1)
	  stw       r5, 0x18(r1)
	  lfd       f1, 0x28(r1)
	  fsubs     f2, f0, f4
	  stw       r5, 0x10(r1)
	  lfd       f3, 0x18(r1)
	  fsubs     f1, f1, f4
	  lfd       f0, 0x10(r1)
	  fsubs     f3, f3, f4
	  fsubs     f4, f0, f4
	  bl        0x64DC0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AF92C
 * Size:	000174
 */
void P2DGrafContext::setup2D()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  bl        0x602BC
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x5FAB4
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x5FAA8
	  li        r3, 0xD
	  li        r4, 0
	  bl        0x5FA9C
	  addi      r3, r31, 0x70
	  li        r4, 0
	  bl        0x64AE4
	  li        r3, 0x1
	  bl        0x6255C
	  li        r3, 0
	  bl        0x60DA8
	  li        r3, 0x1
	  bl        0x63FDC
	  li        r3, 0
	  li        r4, 0x4
	  bl        0x63608
	  li        r3, 0
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0x4
	  bl        0x63E1C
	  li        r3, 0x4
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  li        r9, 0x2
	  bl        0x62558
	  addi      r3, r1, 0xC
	  bl        -0x171C14
	  addi      r3, r1, 0xC
	  li        r4, 0x3C
	  li        r5, 0
	  bl        0x64B2C
	  li        r3, 0
	  bl        0x64AE8
	  li        r3, 0
	  li        r4, 0x3
	  li        r5, 0
	  bl        0x643D8
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0x4
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x60A44
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x3
	  li        r7, 0
	  bl        0x6021C
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x60204
	  li        r3, 0
	  li        r4, 0xD
	  li        r5, 0x1
	  li        r6, 0x2
	  li        r7, 0xF
	  bl        0x601EC
	  li        r3, 0
	  li        r4, 0xE
	  li        r5, 0x1
	  li        r6, 0x2
	  li        r7, 0xF
	  bl        0x601D4
	  lbz       r3, 0x28(r31)
	  li        r4, 0
	  bl        0x612B8
	  li        r3, 0
	  bl        0x613C0
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AFAA0
 * Size:	0000A0
 */
void P2DGrafContext::setScissor()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  li        r6, 0x3E8
	  stwu      r1, -0x28(r1)
	  li        r7, 0x3E8
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x14
	  bl        0x3B60
	  addi      r3, r1, 0xC
	  addi      r4, r31, 0x10
	  bl        0x3B78
	  addi      r3, r31, 0x10
	  addi      r4, r1, 0x14
	  bl        0x3BC4
	  addi      r3, r1, 0xC
	  bl        0x3C9C
	  addi      r3, r1, 0xC
	  li        r4, 0
	  li        r5, -0x1
	  bl        0x3B78
	  addi      r3, r1, 0xC
	  addi      r4, r1, 0x14
	  bl        0x3BA0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8C
	  lha       r4, 0xE(r1)
	  lha       r5, 0x12(r1)
	  lha       r3, 0xC(r1)
	  lha       r0, 0x10(r1)
	  sub       r6, r5, r4
	  sub       r5, r0, r3
	  bl        0x64BA8

	.loc_0x8C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AFB40
 * Size:	000014
 */
void P2DGrafContext::scissor(const PUTRect&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0x10(r3)
	  stw       r0, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AFB54
 * Size:	000024
 */
void P2DGrafContext::place(const PUTRect&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r5, 0x10(r3)
	  stw       r0, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AFB78
 * Size:	0000AC
 */
void P2DGrafContext::setColor(Colour&, Colour&, Colour&, Colour&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  li        r8, 0x1
	  li        r4, 0x4
	  stw       r0, 0x18(r3)
	  li        r0, 0x5
	  lwz       r5, 0x0(r5)
	  stw       r5, 0x1C(r3)
	  lwz       r5, 0x0(r6)
	  stw       r5, 0x20(r3)
	  lwz       r5, 0x0(r7)
	  stw       r5, 0x24(r3)
	  stw       r8, 0xB0(r3)
	  stw       r4, 0xB4(r3)
	  stw       r0, 0xB8(r3)
	  stw       r8, 0xBC(r3)
	  stw       r4, 0xC0(r3)
	  stw       r0, 0xC4(r3)
	  stw       r8, 0xC8(r3)
	  stw       r4, 0xCC(r3)
	  stw       r0, 0xD0(r3)
	  lbz       r0, 0x1B(r3)
	  cmplwi    r0, 0xFF
	  bnelr-
	  li        r4, 0
	  stw       r4, 0xB0(r3)
	  stw       r8, 0xB4(r3)
	  stw       r4, 0xB8(r3)
	  lbz       r0, 0x23(r3)
	  cmplwi    r0, 0xFF
	  bnelr-
	  stw       r4, 0xBC(r3)
	  stw       r8, 0xC0(r3)
	  stw       r4, 0xC4(r3)
	  lbz       r0, 0x1F(r3)
	  cmplwi    r0, 0xFF
	  bnelr-
	  lbz       r0, 0x27(r3)
	  cmplwi    r0, 0xFF
	  bnelr-
	  stw       r4, 0xC8(r3)
	  stw       r8, 0xCC(r3)
	  stw       r4, 0xD0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AFC24
 * Size:	00002C
 */
void P2DGrafContext::setLineWidth(u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  stb       r4, 0x28(r3)
	  li        r4, 0
	  lbz       r3, 0x28(r3)
	  bl        0x610FC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00016C
 */
void P2DGrafContext::fillBox(const PUTRect&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void P2DGrafContext::drawFrame(const PUTRect&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void P2DGrafContext::line(PUTPoint, PUTPoint)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void P2DGrafContext::lineTo(PUTPoint)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001D0
 */
void P2DGrafContext::polyline(PUTPoint*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E4
 */
void P2DGrafContext::polyline(int*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001F8
 */
void P2DGrafContext::polylineTo(PUTPoint*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000218
 */
void P2DGrafContext::polylineTo(int*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801AFC50
 * Size:	00004C
 */
P2DGrafContext::~P2DGrafContext()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x34
	  lis       r3, 0x802E
	  addi      r3, r3, 0x5D4
	  extsh.    r0, r4
	  stw       r3, 0x0(r31)
	  ble-      .loc_0x34
	  mr        r3, r31
	  bl        -0x168AD4

	.loc_0x34:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AFC9C
 * Size:	000050
 */
void P2DGrafContext::place(int, int, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  add       r6, r4, r6
	  stw       r0, 0x4(r1)
	  add       r7, r5, r7
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x1C
	  bl        0x396C
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  addi      r4, r1, 0x1C
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801AFCEC
 * Size:	000004
 */
void P2DGrafContext::setLookat() { }
