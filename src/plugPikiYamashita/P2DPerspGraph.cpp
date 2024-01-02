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
 * Size:	000054
 */
P2DPerspGraph::P2DPerspGraph()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
P2DPerspGraph::P2DPerspGraph(const PUTRect&, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B0190
 * Size:	000084
 */
P2DPerspGraph::P2DPerspGraph(int, int, int, int, f32, f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  fmr       f31, f3
	  stfd      f30, 0x38(r1)
	  fmr       f30, f2
	  stfd      f29, 0x30(r1)
	  fmr       f29, f1
	  stw       r31, 0x2C(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        -0xA14
	  lwz       r31, 0x8(r1)
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  fmr       f1, f29
	  fmr       f2, f30
	  fmr       f3, f31
	  stw       r0, 0x0(r31)
	  mr        r3, r31
	  bl        .loc_0x84
	  li        r0, 0x2
	  stw       r0, 0x4(r31)
	  mr        r3, r31
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lfd       f30, 0x38(r1)
	  lfd       f29, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr

	.loc_0x84:
	*/
}

/*
 * --INFO--
 * Address:	801B0214
 * Size:	000060
 */
void P2DPerspGraph::set(f32, f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  fmr       f31, f3
	  stfd      f30, 0x20(r1)
	  fmr       f30, f2
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  bl        .loc_0x60
	  stfs      f30, 0xD8(r31)
	  mr        r3, r31
	  stfs      f31, 0xDC(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lfd       f30, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x60:
	*/
}

/*
 * --INFO--
 * Address:	801B0274
 * Size:	00002C
 */
void P2DPerspGraph::setFovy(f32)
{
	/*
	.loc_0x0:
	  stfs      f1, 0xD4(r3)
	  lfs       f0, -0x4980(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x18
	  stfs      f0, 0xD4(r3)
	  blr

	.loc_0x18:
	  lfs       f0, -0x497C(r2)
	  fcmpo     cr0, f1, f0
	  blelr-
	  stfs      f0, 0xD4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void P2DPerspGraph::getMatrix(Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B02A0
 * Size:	00016C
 */
void P2DPerspGraph::setPort()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r3
	  bl        -0xA54
	  lha       r7, 0x8(r31)
	  lis       r5, 0x4330
	  lha       r6, 0xC(r31)
	  addi      r3, r1, 0x20
	  lha       r4, 0xA(r31)
	  lha       r0, 0xE(r31)
	  sub       r6, r6, r7
	  xoris     r6, r6, 0x8000
	  lfd       f5, -0x4978(r2)
	  sub       r0, r0, r4
	  xoris     r0, r0, 0x8000
	  stw       r6, 0x6C(r1)
	  lfs       f1, 0xD4(r31)
	  stw       r0, 0x64(r1)
	  lfs       f3, 0xD8(r31)
	  stw       r5, 0x68(r1)
	  lfs       f4, 0xDC(r31)
	  stw       r5, 0x60(r1)
	  lfd       f2, 0x68(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f2, f2, f5
	  fsubs     f0, f0, f5
	  fdivs     f2, f2, f0
	  bl        0x4DC0C
	  addi      r3, r1, 0x20
	  li        r4, 0
	  bl        0x63FD4
	  lfs       f0, 0x20(r1)
	  li        r3, 0
	  li        r4, 0x7
	  stfs      f0, 0x30(r31)
	  li        r5, 0
	  lfs       f0, 0x30(r1)
	  stfs      f0, 0x40(r31)
	  lfs       f0, 0x40(r1)
	  stfs      f0, 0x50(r31)
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x60(r31)
	  lfs       f0, 0x24(r1)
	  stfs      f0, 0x34(r31)
	  lfs       f0, 0x34(r1)
	  stfs      f0, 0x44(r31)
	  lfs       f0, 0x44(r1)
	  stfs      f0, 0x54(r31)
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0x64(r31)
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x38(r31)
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x48(r31)
	  lfs       f0, 0x48(r1)
	  stfs      f0, 0x58(r31)
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0x68(r31)
	  lfs       f0, 0x2C(r1)
	  stfs      f0, 0x3C(r31)
	  lfs       f0, 0x3C(r1)
	  stfs      f0, 0x4C(r31)
	  lfs       f0, 0x4C(r1)
	  stfs      f0, 0x5C(r31)
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x6C(r31)
	  lfs       f3, 0xDC(r31)
	  lfs       f0, 0xD8(r31)
	  lfs       f2, -0x4980(r2)
	  fsubs     f1, f3, f0
	  fadds     f0, f3, f0
	  fdivs     f3, f2, f1
	  fneg      f0, f0
	  fmuls     f0, f3, f0
	  stfs      f0, 0x58(r31)
	  lfs       f2, -0x4970(r2)
	  lfs       f1, 0xDC(r31)
	  lfs       f0, 0xD8(r31)
	  fmuls     f1, f2, f1
	  fmuls     f0, f1, f0
	  fneg      f0, f0
	  fmuls     f0, f3, f0
	  stfs      f0, 0x5C(r31)
	  bl        0x639DC
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B040C
 * Size:	000094
 */
void P2DPerspGraph::setLookat()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lfs       f2, -0x4968(r2)
	  lfs       f1, 0xD4(r3)
	  lfs       f0, -0x4964(r2)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x6B69C
	  lha       r5, 0xE(r31)
	  lis       r4, 0x4330
	  lha       r0, 0xA(r31)
	  addi      r3, r31, 0
	  xoris     r5, r5, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r5, 0x1C(r1)
	  lfd       f4, -0x4978(r2)
	  stw       r0, 0x14(r1)
	  lfs       f0, -0x496C(r2)
	  stw       r4, 0x18(r1)
	  stw       r4, 0x10(r1)
	  lfd       f3, 0x18(r1)
	  lfd       f2, 0x10(r1)
	  fsubs     f3, f3, f4
	  fsubs     f2, f2, f4
	  fsubs     f2, f3, f2
	  fmuls     f0, f2, f0
	  fdivs     f0, f0, f1
	  stfs      f0, 0xE0(r31)
	  bl        .loc_0x94
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0x94:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void P2DPerspGraph::setDistance(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B04A0
 * Size:	0001FC
 */
void P2DPerspGraph::makeLookat()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x4330
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  mr        r31, r3
	  lha       r3, 0xC(r3)
	  lha       r0, 0x8(r31)
	  xoris     r5, r3, 0x8000
	  lha       r3, 0xE(r31)
	  xoris     r4, r0, 0x8000
	  stw       r5, 0xA4(r1)
	  lha       r0, 0xA(r31)
	  xoris     r3, r3, 0x8000
	  stw       r4, 0x9C(r1)
	  addi      r4, r1, 0x78
	  xoris     r0, r0, 0x8000
	  stw       r6, 0xA0(r1)
	  addi      r5, r1, 0x6C
	  lfd       f5, -0x4978(r2)
	  stw       r3, 0x94(r1)
	  addi      r3, r31, 0x70
	  lfd       f2, 0xA0(r1)
	  stw       r6, 0x98(r1)
	  lfs       f3, -0x496C(r2)
	  fsubs     f4, f2, f5
	  lfd       f0, 0x98(r1)
	  stw       r0, 0x8C(r1)
	  lfs       f1, -0x4960(r2)
	  fsubs     f0, f0, f5
	  stw       r6, 0x90(r1)
	  stw       r6, 0x88(r1)
	  fsubs     f4, f4, f0
	  lfd       f2, 0x90(r1)
	  addi      r6, r1, 0x60
	  stfs      f1, 0x80(r1)
	  lfd       f0, 0x88(r1)
	  stfs      f1, 0x7C(r1)
	  fsubs     f2, f2, f5
	  fsubs     f0, f0, f5
	  stfs      f1, 0x78(r1)
	  fmuls     f31, f4, f3
	  stfs      f1, 0x74(r1)
	  fsubs     f0, f2, f0
	  stfs      f1, 0x70(r1)
	  fmuls     f30, f0, f3
	  stfs      f1, 0x6C(r1)
	  stfs      f31, 0x78(r1)
	  stfs      f30, 0x7C(r1)
	  lfs       f0, 0xE0(r31)
	  fneg      f0, f0
	  stfs      f0, 0x80(r1)
	  stfs      f31, 0x6C(r1)
	  stfs      f30, 0x70(r1)
	  stfs      f1, 0x74(r1)
	  stfs      f1, 0x68(r1)
	  stfs      f1, 0x64(r1)
	  stfs      f1, 0x60(r1)
	  lfs       f0, -0x495C(r2)
	  stfs      f1, 0x60(r1)
	  stfs      f0, 0x64(r1)
	  stfs      f1, 0x68(r1)
	  bl        -0x171D20
	  lfs       f2, 0x1890(r13)
	  addi      r6, r1, 0x3C
	  lfs       f1, 0x1884(r13)
	  addi      r5, r1, 0x48
	  lfs       f0, 0x1878(r13)
	  stfs      f2, 0x3C(r1)
	  addi      r4, r1, 0x54
	  lfs       f2, 0x1894(r13)
	  addi      r3, r31, 0x70
	  stfs      f1, 0x48(r1)
	  lfs       f1, 0x1888(r13)
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x187C(r13)
	  stfs      f2, 0x40(r1)
	  lfs       f2, 0x1898(r13)
	  stfs      f1, 0x4C(r1)
	  lfs       f1, 0x188C(r13)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x1880(r13)
	  stfs      f2, 0x44(r1)
	  stfs      f1, 0x50(r1)
	  stfs      f0, 0x5C(r1)
	  bl        -0x171D7C
	  lfs       f2, 0x18B4(r13)
	  addi      r7, r1, 0xC
	  lfs       f1, 0x18A8(r13)
	  addi      r6, r1, 0x18
	  lfs       f0, 0x189C(r13)
	  stfs      f2, 0xC(r1)
	  addi      r5, r1, 0x24
	  lfs       f2, 0x18B8(r13)
	  addi      r4, r1, 0x30
	  stfs      f1, 0x18(r1)
	  lfs       f1, 0x18AC(r13)
	  addi      r3, r31, 0x70
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x18A0(r13)
	  stfs      f2, 0x10(r1)
	  lfs       f2, 0x18BC(r13)
	  stfs      f1, 0x1C(r1)
	  lfs       f1, 0x18B0(r13)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x18A4(r13)
	  stfs      f2, 0x14(r1)
	  stfs      f1, 0x20(r1)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0xE0(r31)
	  stfs      f31, 0x30(r1)
	  fneg      f0, f0
	  stfs      f30, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  bl        -0x171AF0
	  addi      r3, r31, 0x70
	  li        r4, 0
	  bl        0x63DD8
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lwz       r31, 0xAC(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}
