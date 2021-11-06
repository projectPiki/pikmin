#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
P2DOrthoGraph::P2DOrthoGraph()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
P2DOrthoGraph::P2DOrthoGraph(const PUTRect &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801AFCF0
 * Size:	0000C4
 */
P2DOrthoGraph::P2DOrthoGraph(int, int, int, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r7
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  mr        r29, r6
  stw       r3, 0x8(r1)
  lwz       r3, 0x8(r1)
  bl        -0x56C
  lwz       r30, 0x8(r1)
  lis       r3, 0x802E
  addi      r0, r3, 0x624
  stw       r0, 0x0(r30)
  addi      r3, r30, 0xD4
  li        r4, 0
  li        r5, 0
  li        r6, 0
  li        r7, 0
  bl        0x38E8
  addi      r6, r29, 0
  addi      r7, r31, 0
  addi      r3, r1, 0x20
  li        r4, 0
  li        r5, 0
  bl        0x38D0
  lwz       r5, 0x20(r1)
  li        r0, -0x1
  lwz       r4, 0x24(r1)
  li        r31, 0x1
  addi      r3, r30, 0
  stw       r5, 0xD4(r30)
  stw       r4, 0xD8(r30)
  stw       r0, 0xDC(r30)
  stw       r31, 0xE0(r30)
  lwz       r12, 0x0(r30)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  stw       r31, 0x4(r30)
  mr        r3, r30
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801AFDB4
 * Size:	0000D8
 */
void P2DOrthoGraph::setPort()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  mr        r31, r3
  bl        -0x568
  lha       r4, 0xD6(r31)
  lis       r8, 0x4330
  lha       r0, 0xDA(r31)
  addi      r3, r31, 0x30
  lha       r6, 0xD4(r31)
  lha       r5, 0xD8(r31)
  xoris     r9, r4, 0x8000
  lwz       r4, 0xE0(r31)
  xoris     r7, r0, 0x8000
  lwz       r0, 0xDC(r31)
  xoris     r6, r6, 0x8000
  stw       r9, 0x3C(r1)
  xoris     r5, r5, 0x8000
  lfd       f6, -0x4990(r2)
  xoris     r4, r4, 0x8000
  stw       r7, 0x34(r1)
  xoris     r0, r0, 0x8000
  stw       r6, 0x2C(r1)
  stw       r5, 0x24(r1)
  stw       r4, 0x1C(r1)
  stw       r0, 0x14(r1)
  stw       r8, 0x38(r1)
  stw       r8, 0x30(r1)
  lfd       f1, 0x38(r1)
  stw       r8, 0x28(r1)
  lfd       f0, 0x30(r1)
  fsubs     f1, f1, f6
  stw       r8, 0x20(r1)
  lfd       f3, 0x28(r1)
  fsubs     f2, f0, f6
  stw       r8, 0x18(r1)
  lfd       f0, 0x20(r1)
  fsubs     f3, f3, f6
  stw       r8, 0x10(r1)
  lfd       f5, 0x18(r1)
  fsubs     f4, f0, f6
  lfd       f0, 0x10(r1)
  fsubs     f5, f5, f6
  fsubs     f6, f0, f6
  bl        0x4E188
  addi      r3, r31, 0x30
  li        r4, 0x1
  bl        0x64480
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void P2DOrthoGraph::setOrtho(const PUTRect &, int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void P2DOrthoGraph::setOrigin(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801AFE8C
 * Size:	00003C
 */
void P2DOrthoGraph::setLookat()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  addi      r3, r31, 0x70
  bl        -0x1720E8
  addi      r3, r31, 0x70
  li        r4, 0
  bl        0x645A4
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801AFEC8
 * Size:	00026C
 */
void P2DOrthoGraph::scissorBounds(PUTRect *, PUTRect *)
{
/*
.loc_0x0:
  stwu      r1, -0xE8(r1)
  lha       r10, 0x8(r3)
  lis       r0, 0x4330
  lha       r7, 0xC(r3)
  lha       r9, 0xD4(r3)
  xoris     r8, r10, 0x8000
  lha       r6, 0xD8(r3)
  sub       r7, r7, r10
  xoris     r7, r7, 0x8000
  sub       r6, r6, r9
  stw       r7, 0xD4(r1)
  xoris     r6, r6, 0x8000
  lha       r7, 0x0(r5)
  stw       r6, 0xCC(r1)
  lfd       f1, -0x4990(r2)
  sub       r6, r7, r9
  stw       r0, 0xD0(r1)
  xoris     r6, r6, 0x8000
  lfs       f2, -0x4988(r2)
  stw       r0, 0xC8(r1)
  lfd       f3, 0xD0(r1)
  lfd       f0, 0xC8(r1)
  fsubs     f3, f3, f1
  stw       r6, 0xDC(r1)
  fsubs     f0, f0, f1
  stw       r0, 0xD8(r1)
  fdivs     f0, f3, f0
  stw       r8, 0xE4(r1)
  lfd       f3, 0xD8(r1)
  stw       r0, 0xE0(r1)
  lfd       f4, 0xE0(r1)
  fsubs     f3, f3, f1
  fsubs     f4, f4, f1
  fmuls     f0, f3, f0
  fadds     f0, f4, f0
  fadds     f0, f2, f0
  fctiwz    f0, f0
  stfd      f0, 0xC0(r1)
  lwz       r6, 0xC4(r1)
  extsh     r6, r6
  sth       r6, 0x0(r4)
  lha       r10, 0x8(r3)
  lha       r7, 0xC(r3)
  lha       r9, 0xD4(r3)
  xoris     r8, r10, 0x8000
  lha       r6, 0xD8(r3)
  sub       r7, r7, r10
  xoris     r7, r7, 0x8000
  sub       r6, r6, r9
  stw       r7, 0xAC(r1)
  xoris     r6, r6, 0x8000
  lha       r7, 0x4(r5)
  stw       r6, 0xA4(r1)
  sub       r6, r7, r9
  lfs       f0, -0x4984(r2)
  stw       r0, 0xA8(r1)
  xoris     r6, r6, 0x8000
  stw       r0, 0xA0(r1)
  lfd       f4, 0xA8(r1)
  lfd       f3, 0xA0(r1)
  stw       r6, 0xB4(r1)
  fsubs     f4, f4, f1
  fsubs     f3, f3, f1
  stw       r0, 0xB0(r1)
  stw       r8, 0xBC(r1)
  fdivs     f3, f4, f3
  lfd       f4, 0xB0(r1)
  stw       r0, 0xB8(r1)
  lfd       f5, 0xB8(r1)
  fsubs     f4, f4, f1
  fsubs     f5, f5, f1
  fmuls     f3, f4, f3
  fadds     f3, f5, f3
  fadds     f3, f0, f3
  fctiwz    f3, f3
  stfd      f3, 0x98(r1)
  lwz       r6, 0x9C(r1)
  extsh     r6, r6
  sth       r6, 0x4(r4)
  lha       r10, 0xA(r3)
  lha       r7, 0xE(r3)
  lha       r9, 0xD6(r3)
  xoris     r8, r10, 0x8000
  lha       r6, 0xDA(r3)
  sub       r7, r7, r10
  xoris     r7, r7, 0x8000
  sub       r6, r6, r9
  stw       r7, 0x84(r1)
  xoris     r6, r6, 0x8000
  lha       r7, 0x2(r5)
  stw       r6, 0x7C(r1)
  sub       r6, r7, r9
  stw       r0, 0x80(r1)
  xoris     r6, r6, 0x8000
  stw       r0, 0x78(r1)
  lfd       f4, 0x80(r1)
  lfd       f3, 0x78(r1)
  stw       r6, 0x8C(r1)
  fsubs     f4, f4, f1
  fsubs     f3, f3, f1
  stw       r0, 0x88(r1)
  stw       r8, 0x94(r1)
  fdivs     f3, f4, f3
  lfd       f4, 0x88(r1)
  stw       r0, 0x90(r1)
  lfd       f5, 0x90(r1)
  fsubs     f4, f4, f1
  fsubs     f5, f5, f1
  fmuls     f3, f4, f3
  fadds     f3, f5, f3
  fadds     f2, f2, f3
  fctiwz    f2, f2
  stfd      f2, 0x70(r1)
  lwz       r6, 0x74(r1)
  extsh     r6, r6
  sth       r6, 0x2(r4)
  lha       r9, 0xA(r3)
  lha       r6, 0xE(r3)
  lha       r8, 0xD6(r3)
  xoris     r7, r9, 0x8000
  lha       r3, 0xDA(r3)
  sub       r6, r6, r9
  xoris     r6, r6, 0x8000
  sub       r3, r3, r8
  stw       r6, 0x5C(r1)
  xoris     r3, r3, 0x8000
  lha       r5, 0x6(r5)
  stw       r3, 0x54(r1)
  sub       r3, r5, r8
  stw       r0, 0x58(r1)
  xoris     r3, r3, 0x8000
  stw       r0, 0x50(r1)
  lfd       f3, 0x58(r1)
  lfd       f2, 0x50(r1)
  fsubs     f3, f3, f1
  stw       r3, 0x64(r1)
  fsubs     f2, f2, f1
  stw       r0, 0x60(r1)
  fdivs     f2, f3, f2
  stw       r7, 0x6C(r1)
  lfd       f3, 0x60(r1)
  stw       r0, 0x68(r1)
  lfd       f4, 0x68(r1)
  fsubs     f3, f3, f1
  fsubs     f4, f4, f1
  fmuls     f1, f3, f2
  fadds     f1, f4, f1
  fadds     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x48(r1)
  lwz       r0, 0x4C(r1)
  extsh     r0, r0
  sth       r0, 0x6(r4)
  addi      r1, r1, 0xE8
  blr
*/
}

/*
 * --INFO--
 * Address:	801B0134
 * Size:	00005C
 */
P2DOrthoGraph::~P2DOrthoGraph()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  beq-      .loc_0x44
  lis       r3, 0x802E
  addi      r0, r3, 0x624
  stw       r0, 0x0(r31)
  beq-      .loc_0x34
  lis       r3, 0x802E
  addi      r0, r3, 0x5D4
  stw       r0, 0x0(r31)

.loc_0x34:
  extsh.    r0, r4
  ble-      .loc_0x44
  mr        r3, r31
  bl        -0x168FC8

.loc_0x44:
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
