#include "FastGrid.h"
#include "DebugLog.h"

u32 FastGrid::aiGridMap;
u16 FastGrid::aiGridSize;
u16 FastGrid::aiGridShift = 12;

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
 * Address:	80094098
 * Size:	000024
 */
FastGrid::FastGrid()
{
	_00 = _04 = _08 = _0C = _10 = 0;
	_14                         = 1;
}

/*
 * --INFO--
 * Address:	800940BC
 * Size:	000078
 */
void FastGrid::initAIGrid(u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r3,0,24,31
	  subi      r4, r13, 0x5A04
	  stwu      r1, -0x18(r1)
	  sth       r0, -0x5A08(r13)
	  lwz       r3, 0x2FE8(r13)
	  lhz       r0, -0x5A08(r13)
	  subfic    r0, r0, 0x10
	  slw       r0, r5, r0
	  sth       r0, 0x300C(r13)
	  bl        -0xD9B4
	  lhz       r0, 0x300C(r13)
	  li        r4, 0x20
	  mullw     r3, r0, r0
	  bl        -0x4CF94
	  stw       r3, 0x3008(r13)
	  bl        .loc_0x78
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x5A04
	  bl        -0xD8C8
	  lhz       r3, 0x300C(r13)
	  lis       r0, 0x4330
	  stw       r3, 0x14(r1)
	  stw       r0, 0x10(r1)
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x78:
	*/
}

/*
 * --INFO--
 * Address:	80094134
 * Size:	00002C
 */
void FastGrid::clearAIGrid()
{
	/*
	.loc_0x0:
	  li        r5, 0
	  li        r4, 0
	  b         .loc_0x18

	.loc_0xC:
	  lwz       r3, 0x3008(r13)
	  stbx      r4, r3, r5
	  addi      r5, r5, 0x1

	.loc_0x18:
	  lhz       r0, 0x300C(r13)
	  mullw     r0, r0, r0
	  cmpw      r5, r0
	  blt+      .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void FastGrid::addAIGrid()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80094160
 * Size:	000030
 */
void FastGrid::delAIGrid()
{
	/*
	.loc_0x0:
	  lha       r4, 0xC(r3)
	  lhz       r0, 0x300C(r13)
	  lha       r3, 0x10(r3)
	  mullw     r0, r4, r0
	  lwz       r5, 0x3008(r13)
	  add       r4, r3, r0
	  lbzx      r3, r5, r4
	  cmplwi    r3, 0
	  beqlr-
	  subi      r0, r3, 0x1
	  stbx      r0, r5, r4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80094190
 * Size:	0001A8
 */
bool FastGrid::aiCulling()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, -0x5F08(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x198

	.loc_0x20:
	  lhz       r4, 0x14(r3)
	  cmplwi    r4, 0x1
	  beq-      .loc_0x34
	  bl        .loc_0x1A8
	  b         .loc_0x198

	.loc_0x34:
	  lha       r0, 0xC(r3)
	  lhz       r4, 0x300C(r13)
	  lha       r7, 0x10(r3)
	  mullw     r5, r0, r4
	  lwz       r3, 0x3008(r13)
	  add       r6, r7, r5
	  lbzx      r5, r3, r6
	  cmplwi    r5, 0
	  beq-      .loc_0x60
	  li        r3, 0
	  b         .loc_0x198

	.loc_0x60:
	  subi      r8, r4, 0x1
	  cmpw      r7, r8
	  bge-      .loc_0x84
	  add       r5, r3, r6
	  lbz       r5, 0x1(r5)
	  cmplwi    r5, 0
	  beq-      .loc_0x84
	  li        r3, 0
	  b         .loc_0x198

	.loc_0x84:
	  extsh.    r5, r7
	  ble-      .loc_0xA4
	  add       r5, r3, r6
	  lbz       r5, -0x1(r5)
	  cmplwi    r5, 0
	  beq-      .loc_0xA4
	  li        r3, 0
	  b         .loc_0x198

	.loc_0xA4:
	  cmpw      r0, r8
	  bge-      .loc_0xC4
	  add       r5, r6, r4
	  lbzx      r5, r3, r5
	  cmplwi    r5, 0
	  beq-      .loc_0xC4
	  li        r3, 0
	  b         .loc_0x198

	.loc_0xC4:
	  extsh.    r5, r0
	  ble-      .loc_0xE4
	  sub       r5, r6, r4
	  lbzx      r5, r3, r5
	  cmplwi    r5, 0
	  beq-      .loc_0xE4
	  li        r3, 0
	  b         .loc_0x198

	.loc_0xE4:
	  cmpw      r7, r8
	  bge-      .loc_0x110
	  extsh.    r5, r0
	  ble-      .loc_0x110
	  addi      r5, r6, 0x1
	  sub       r5, r5, r4
	  lbzx      r5, r3, r5
	  cmplwi    r5, 0
	  beq-      .loc_0x110
	  li        r3, 0
	  b         .loc_0x198

	.loc_0x110:
	  cmpw      r7, r8
	  bge-      .loc_0x13C
	  cmpw      r0, r8
	  bge-      .loc_0x13C
	  add       r5, r3, r6
	  add       r5, r5, r4
	  lbz       r5, 0x1(r5)
	  cmplwi    r5, 0
	  beq-      .loc_0x13C
	  li        r3, 0
	  b         .loc_0x198

	.loc_0x13C:
	  extsh.    r5, r7
	  ble-      .loc_0x168
	  extsh.    r5, r0
	  ble-      .loc_0x168
	  subi      r5, r6, 0x1
	  sub       r5, r5, r4
	  lbzx      r5, r3, r5
	  cmplwi    r5, 0
	  beq-      .loc_0x168
	  li        r3, 0
	  b         .loc_0x198

	.loc_0x168:
	  extsh.    r5, r7
	  ble-      .loc_0x194
	  cmpw      r0, r8
	  bge-      .loc_0x194
	  add       r0, r3, r6
	  add       r3, r0, r4
	  lbz       r0, -0x1(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x194
	  li        r3, 0
	  b         .loc_0x198

	.loc_0x194:
	  li        r3, 0x1

	.loc_0x198:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x1A8:
	*/
}

/*
 * --INFO--
 * Address:	80094338
 * Size:	0000B8
 */
bool FastGrid::aiCullingLarge(int)
{
	/*
	.loc_0x0:
	  lbz       r0, -0x5F08(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x14
	  li        r3, 0
	  blr

	.loc_0x14:
	  lha       r9, 0xC(r3)
	  neg       r8, r4
	  lhz       r7, 0x300C(r13)
	  mr        r11, r8
	  lha       r10, 0x10(r3)
	  mullw     r3, r9, r7
	  lwz       r0, 0x3008(r13)
	  add       r3, r10, r3
	  mullw     r5, r11, r7
	  add       r6, r0, r3
	  b         .loc_0xA8

	.loc_0x40:
	  add.      r0, r9, r11
	  blt-      .loc_0xA0
	  cmpw      r0, r7
	  bge-      .loc_0xA0
	  addi      r12, r8, 0
	  addi      r0, r4, 0x1
	  sub       r0, r0, r12
	  add       r3, r5, r8
	  mtctr     r0
	  cmpw      r12, r4
	  add       r3, r6, r3
	  bgt-      .loc_0xA0

	.loc_0x70:
	  add.      r0, r10, r12
	  blt-      .loc_0x94
	  cmpw      r0, r7
	  bge-      .loc_0x94
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x94
	  li        r3, 0
	  blr

	.loc_0x94:
	  addi      r3, r3, 0x1
	  addi      r12, r12, 0x1
	  bdnz+     .loc_0x70

	.loc_0xA0:
	  add       r5, r5, r7
	  addi      r11, r11, 0x1

	.loc_0xA8:
	  cmpw      r11, r4
	  ble+      .loc_0x40
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800943F0
 * Size:	000130
 */
bool FastGrid::doCulling(const FastGrid&, f32)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  fctiwz    f0, f1
	  lha       r5, 0x0(r4)
	  lha       r0, 0x0(r3)
	  stfd      f0, 0x18(r1)
	  sub       r0, r0, r5
	  lwz       r6, -0x5F0C(r13)
	  extsh     r7, r0
	  lwz       r5, 0x1C(r1)
	  extsh.    r0, r7
	  extsh     r0, r5
	  sraw      r0, r0, r6
	  extsh     r6, r0
	  ble-      .loc_0x40
	  mr        r0, r7
	  b         .loc_0x44

	.loc_0x40:
	  neg       r0, r7

	.loc_0x44:
	  extsh     r5, r0
	  extsh.    r0, r5
	  bne-      .loc_0x58
	  li        r0, 0
	  b         .loc_0x5C

	.loc_0x58:
	  subi      r0, r5, 0x1

	.loc_0x5C:
	  extsh     r0, r0
	  cmpw      r0, r6
	  ble-      .loc_0x70
	  li        r3, 0x1
	  b         .loc_0x128

	.loc_0x70:
	  lha       r5, 0x8(r4)
	  lha       r0, 0x8(r3)
	  sub       r0, r0, r5
	  extsh     r5, r0
	  extsh.    r0, r5
	  ble-      .loc_0x90
	  mr        r0, r5
	  b         .loc_0x94

	.loc_0x90:
	  neg       r0, r5

	.loc_0x94:
	  extsh     r5, r0
	  extsh.    r0, r5
	  bne-      .loc_0xA8
	  li        r0, 0
	  b         .loc_0xAC

	.loc_0xA8:
	  subi      r0, r5, 0x1

	.loc_0xAC:
	  extsh     r0, r0
	  cmpw      r0, r6
	  ble-      .loc_0xC0
	  li        r3, 0x1
	  b         .loc_0x128

	.loc_0xC0:
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xD4
	  li        r3, 0
	  b         .loc_0x128

	.loc_0xD4:
	  lha       r4, 0x4(r4)
	  lha       r0, 0x4(r3)
	  sub       r0, r0, r4
	  extsh     r3, r0
	  extsh.    r0, r3
	  ble-      .loc_0xF4
	  mr        r0, r3
	  b         .loc_0xF8

	.loc_0xF4:
	  neg       r0, r3

	.loc_0xF8:
	  extsh     r3, r0
	  extsh.    r0, r3
	  bne-      .loc_0x10C
	  li        r0, 0
	  b         .loc_0x110

	.loc_0x10C:
	  subi      r0, r3, 0x1

	.loc_0x110:
	  extsh     r0, r0
	  cmpw      r0, r6
	  ble-      .loc_0x124
	  li        r3, 0x1
	  b         .loc_0x128

	.loc_0x124:
	  li        r3, 0

	.loc_0x128:
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80094520
 * Size:	00009C
 */
void FastGrid::updateGrid(const Vector3f&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x94
	  lfs       f0, 0x0(r4)
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  sth       r0, 0x0(r3)
	  lha       r5, 0x0(r3)
	  lwz       r0, -0x5F0C(r13)
	  sraw      r0, r5, r0
	  extsh     r0, r0
	  sth       r0, 0x0(r3)
	  lfs       f0, 0x8(r4)
	  fctiwz    f0, f0
	  stfd      f0, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  sth       r0, 0x8(r3)
	  lha       r5, 0x8(r3)
	  lwz       r0, -0x5F0C(r13)
	  sraw      r0, r5, r0
	  extsh     r0, r0
	  sth       r0, 0x8(r3)
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x94
	  lfs       f0, 0x4(r4)
	  fctiwz    f0, f0
	  stfd      f0, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  sth       r0, 0x4(r3)
	  lha       r4, 0x4(r3)
	  lwz       r0, -0x5F0C(r13)
	  sraw      r0, r4, r0
	  extsh     r0, r0
	  sth       r0, 0x4(r3)

	.loc_0x94:
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800945BC
 * Size:	0000E8
 */
void FastGrid::updateAIGrid(const Vector3f&, bool)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x28(r1)
	  lbz       r0, -0x5F08(r13)
	  lfs       f0, 0x0(r4)
	  cmplwi    r0, 0
	  lfs       f2, 0x8(r4)
	  lha       r7, 0xC(r3)
	  lha       r8, 0x10(r3)
	  beq-      .loc_0xE0
	  fctiwz    f1, f0
	  rlwinm.   r0,r5,0,24,31
	  fctiwz    f0, f2
	  stfd      f1, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stfd      f0, 0x18(r1)
	  sth       r0, 0xC(r3)
	  lwz       r0, 0x1C(r1)
	  lhz       r6, 0x300C(r13)
	  lha       r5, 0xC(r3)
	  lhz       r4, -0x5A08(r13)
	  srawi     r6, r6, 0x1
	  sraw      r4, r5, r4
	  add       r4, r6, r4
	  sth       r4, 0xC(r3)
	  sth       r0, 0x10(r3)
	  lhz       r5, 0x300C(r13)
	  lha       r4, 0x10(r3)
	  lhz       r0, -0x5A08(r13)
	  srawi     r5, r5, 0x1
	  sraw      r0, r4, r0
	  add       r0, r5, r0
	  sth       r0, 0x10(r3)
	  beq-      .loc_0xE0
	  lha       r0, 0xC(r3)
	  cmpw      r0, r7
	  bne-      .loc_0x98
	  lha       r0, 0x10(r3)
	  cmpw      r0, r8
	  beq-      .loc_0xE0

	.loc_0x98:
	  lhz       r0, 0x300C(r13)
	  lwz       r6, 0x3008(r13)
	  mullw     r0, r7, r0
	  add       r5, r8, r0
	  lbzx      r4, r6, r5
	  cmplwi    r4, 0
	  beq-      .loc_0xBC
	  subi      r0, r4, 0x1
	  stbx      r0, r6, r5

	.loc_0xBC:
	  lha       r4, 0xC(r3)
	  lhz       r0, 0x300C(r13)
	  lwz       r6, 0x3008(r13)
	  mullw     r0, r4, r0
	  lha       r5, 0x10(r3)
	  add       r4, r0, r6
	  lbzx      r3, r5, r4
	  addi      r0, r3, 0x1
	  stbx      r0, r5, r4

	.loc_0xE0:
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000820
 */
void FastGrid::renderAIGrid2D(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000348
 */
void FastGrid::renderAIGrid(Graphics&)
{
	// UNUSED FUNCTION
}
