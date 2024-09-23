#include "P2D/Print.h"
#include "Colour.h"

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
 * Address:	801B49A4
 * Size:	000048
 */
P2DPrint::P2DPrint(P2DFont*, int, int, Colour, Colour)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r0, 0x0(r8)
	  addi      r8, r1, 0x20
	  stw       r0, 0x20(r1)
	  lwz       r0, 0x0(r7)
	  addi      r7, r1, 0x24
	  stw       r0, 0x24(r1)
	  bl        .loc_0x48
	  mr        r3, r31
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x48:
	*/
}

/*
 * --INFO--
 * Address:	801B49EC
 * Size:	000100
 */
void P2DPrint::private_initiate(P2DFont*, int, int, Colour, Colour)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x20
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  stw       r30, 0x38(r1)
	  addi      r30, r8, 0
	  stw       r29, 0x34(r1)
	  addi      r29, r7, 0
	  stw       r4, 0x0(r3)
	  stw       r5, 0x4(r3)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0x0(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x58
	  subis     r0, r6, 0x8000
	  cmplwi    r0, 0
	  beq-      .loc_0x50
	  b         .loc_0x54

	.loc_0x50:
	  lhz       r6, 0x8(r3)

	.loc_0x54:
	  stw       r6, 0x8(r31)

	.loc_0x58:
	  li        r0, 0x1
	  stb       r0, 0xC(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stb       r0, 0xD(r31)
	  li        r4, 0
	  li        r5, 0
	  bl        .loc_0x100
	  lwz       r0, 0x0(r29)
	  stw       r0, 0x28(r31)
	  lwz       r0, 0x0(r30)
	  stw       r0, 0x30(r31)
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xA4
	  lhz       r0, 0x6(r3)
	  rlwinm    r0,r0,2,0,29
	  extsh     r0, r0
	  b         .loc_0xA8

	.loc_0xA4:
	  li        r0, 0x50

	.loc_0xA8:
	  extsh     r0, r0
	  stw       r0, 0x34(r31)
	  lwz       r0, 0x0(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xD0
	  mr        r3, r31
	  bl        0x94
	  lwz       r3, 0x0(r31)
	  bl        0x13BC
	  b         .loc_0xDC

	.loc_0xD0:
	  lis       r0, 0x8000
	  stw       r0, 0x38(r31)
	  stw       r0, 0x3C(r31)

	.loc_0xDC:
	  mr        r3, r31
	  bl        0x9C
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr

	.loc_0x100:
	*/
}

/*
 * --INFO--
 * Address:	801B4AEC
 * Size:	000054
 */
void P2DPrint::locate(int, int)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x28(r1)
	  xoris     r6, r4, 0x8000
	  xoris     r0, r5, 0x8000
	  stw       r4, 0x10(r3)
	  lis       r4, 0x4330
	  stw       r6, 0x24(r1)
	  stw       r5, 0x14(r3)
	  stw       r4, 0x20(r1)
	  lfd       f2, -0x4910(r2)
	  stw       r0, 0x1C(r1)
	  lfd       f0, 0x20(r1)
	  stw       r4, 0x18(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x18(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x18(r3)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, -0x4918(r2)
	  stfs      f0, 0x20(r3)
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B4B40
 * Size:	000028
 */
void P2DPrint::setFontSize()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x0(r3)
	  cmplwi    r4, 0
	  beqlr-
	  lhz       r0, 0x6(r4)
	  stw       r0, 0x38(r3)
	  lwz       r4, 0x0(r3)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x3C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B4B68
 * Size:	000044
 */
void P2DPrint::initchar()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x28(r3)
	  stw       r0, 0x24(r3)
	  lwz       r0, 0x30(r3)
	  stw       r0, 0x2C(r3)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x40(r3)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x44(r3)
	  lbz       r0, 0xC(r3)
	  stb       r0, 0x48(r3)
	  lwz       r0, 0x34(r3)
	  stw       r0, 0x4C(r3)
	  lwz       r0, 0x38(r3)
	  stw       r0, 0x50(r3)
	  lwz       r0, 0x3C(r3)
	  stw       r0, 0x54(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B4BAC
 * Size:	000250
 */
void P2DPrint::printReturn(const char*, int, int, P2DTextBoxHBinding, P2DTextBoxVBinding, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x878(r1)
	  stmw      r23, 0x854(r1)
	  mr        r23, r3
	  addi      r24, r4, 0
	  addi      r25, r5, 0
	  addi      r26, r6, 0
	  addi      r27, r7, 0
	  addi      r28, r8, 0
	  addi      r29, r9, 0
	  addi      r30, r10, 0
	  lwz       r0, 0x28(r3)
	  stw       r0, 0x24(r3)
	  lwz       r0, 0x30(r3)
	  stw       r0, 0x2C(r3)
	  addi      r3, r24, 0
	  lwz       r0, 0x4(r23)
	  stw       r0, 0x40(r23)
	  lwz       r0, 0x8(r23)
	  stw       r0, 0x44(r23)
	  lbz       r0, 0xC(r23)
	  stb       r0, 0x48(r23)
	  lwz       r0, 0x34(r23)
	  stw       r0, 0x4C(r23)
	  lwz       r0, 0x38(r23)
	  stw       r0, 0x50(r23)
	  lwz       r0, 0x3C(r23)
	  stw       r0, 0x54(r23)
	  bl        0x647EC
	  addi      r31, r3, 0
	  cmplwi    r31, 0x400
	  ble-      .loc_0x88
	  li        r31, 0x400

	.loc_0x88:
	  addi      r3, r23, 0
	  addi      r4, r24, 0
	  addi      r5, r31, 0
	  addi      r6, r25, 0
	  addi      r7, r1, 0x38
	  addi      r8, r1, 0x28
	  li        r9, 0
	  bl        .loc_0x250
	  lwz       r3, 0x3C(r23)
	  lis       r0, 0x4330
	  lfd       f2, -0x4910(r2)
	  cmpwi     r28, 0x1
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x84C(r1)
	  stw       r0, 0x848(r1)
	  lfd       f0, 0x848(r1)
	  fsubs     f0, f0, f2
	  fadds     f1, f1, f0
	  beq-      .loc_0xE8
	  bge-      .loc_0x12C
	  cmpwi     r28, 0
	  bge-      .loc_0x108
	  b         .loc_0x12C
	  b         .loc_0x12C

	.loc_0xE8:
	  lfs       f0, -0x4908(r2)
	  fadds     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x848(r1)
	  lwz       r0, 0x84C(r1)
	  sub       r0, r26, r0
	  add       r30, r30, r0
	  b         .loc_0x12C

	.loc_0x108:
	  lfs       f0, -0x4908(r2)
	  fadds     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x848(r1)
	  lwz       r0, 0x84C(r1)
	  sub       r0, r26, r0
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r30, r30, r0

	.loc_0x12C:
	  addi      r4, r1, 0x38
	  li        r3, 0
	  b         .loc_0x180

	.loc_0x138:
	  cmpwi     r27, 0x1
	  beq-      .loc_0x160
	  bge-      .loc_0x150
	  cmpwi     r27, 0
	  bge-      .loc_0x16C
	  b         .loc_0x17C

	.loc_0x150:
	  cmpwi     r27, 0x3
	  bge-      .loc_0x17C
	  sth       r3, 0x0(r4)
	  b         .loc_0x17C

	.loc_0x160:
	  sub       r0, r25, r0
	  sth       r0, 0x0(r4)
	  b         .loc_0x17C

	.loc_0x16C:
	  sub       r0, r25, r0
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  sth       r0, 0x0(r4)

	.loc_0x17C:
	  addi      r4, r4, 0x2

	.loc_0x180:
	  lhz       r0, 0x0(r4)
	  cmplwi    r0, 0xFFFF
	  bne+      .loc_0x138
	  lwz       r4, 0x28(r23)
	  xoris     r0, r29, 0x8000
	  stw       r0, 0x84C(r1)
	  lis       r10, 0x4330
	  addi      r3, r23, 0
	  stw       r4, 0x24(r23)
	  addi      r4, r24, 0
	  addi      r5, r31, 0
	  lwz       r0, 0x30(r23)
	  mr        r6, r25
	  stw       r10, 0x848(r1)
	  addi      r7, r1, 0x38
	  addi      r8, r1, 0x28
	  stw       r0, 0x2C(r23)
	  li        r9, 0x1
	  lfd       f0, 0x848(r1)
	  lwz       r0, 0x4(r23)
	  stw       r0, 0x40(r23)
	  lwz       r0, 0x8(r23)
	  stw       r0, 0x44(r23)
	  lbz       r0, 0xC(r23)
	  stb       r0, 0x48(r23)
	  lwz       r0, 0x34(r23)
	  stw       r0, 0x4C(r23)
	  lwz       r0, 0x38(r23)
	  stw       r0, 0x50(r23)
	  lwz       r0, 0x3C(r23)
	  stw       r0, 0x54(r23)
	  lfd       f2, -0x4910(r2)
	  lfs       f1, 0x18(r23)
	  fsubs     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r23)
	  lwz       r0, 0x3C(r23)
	  lfs       f1, 0x1C(r23)
	  add       r0, r30, r0
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x844(r1)
	  stw       r10, 0x840(r1)
	  lfd       f0, 0x840(r1)
	  fsubs     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r23)
	  bl        .loc_0x250
	  lmw       r23, 0x854(r1)
	  lwz       r0, 0x87C(r1)
	  addi      r1, r1, 0x878
	  mtlr      r0
	  blr

	.loc_0x250:
	*/
}

/*
 * --INFO--
 * Address:	801B4DFC
 * Size:	0005C8
 */
void P2DPrint::parse(const u8*, int, int, u16*, P2DPrint::TSize&, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  stfd      f30, 0x100(r1)
	  stfd      f29, 0xF8(r1)
	  stfd      f28, 0xF0(r1)
	  stfd      f27, 0xE8(r1)
	  stfd      f26, 0xE0(r1)
	  stfd      f25, 0xD8(r1)
	  stfd      f24, 0xD0(r1)
	  stfd      f23, 0xC8(r1)
	  stfd      f22, 0xC0(r1)
	  stmw      r19, 0x8C(r1)
	  mr        r21, r5
	  mr        r19, r6
	  addi      r22, r7, 0
	  addi      r23, r8, 0
	  addi      r24, r9, 0
	  mr        r20, r3
	  li        r27, 0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  li        r9, 0x2
	  stw       r4, 0xC(r1)
	  li        r4, 0
	  lfs       f27, -0x4918(r2)
	  lwz       r28, 0xC(r1)
	  lfs       f29, 0x18(r3)
	  fmr       f26, f27
	  lfs       f28, 0x1C(r3)
	  addi      r0, r28, 0x1
	  stw       r0, 0xC(r1)
	  lfs       f0, 0x18(r3)
	  lfs       f1, 0x1C(r3)
	  li        r3, 0x4
	  fmr       f25, f0
	  lbz       r26, 0x0(r28)
	  fmr       f24, f0
	  fmr       f23, f1
	  fmr       f22, f1
	  bl        0x5D078
	  lwz       r3, 0x0(r20)
	  addi      r4, r20, 0x24
	  addi      r5, r20, 0x2C
	  bl        0x1090
	  lwz       r25, 0x0(r20)
	  lwz       r3, 0x0(r25)
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r25)
	  li        r4, 0
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x24(r3)
	  bl        0x5D87C
	  lfd       f31, -0x4910(r2)
	  rlwinm    r30,r24,0,24,31
	  lfs       f30, -0x4908(r2)
	  xoris     r29, r19, 0x8000
	  lis       r31, 0x4330

	.loc_0x104:
	  cmpwi     r26, 0
	  li        r25, 0x1
	  beq-      .loc_0x120
	  lwz       r4, 0xC(r1)
	  sub       r0, r4, r28
	  cmplw     r0, r21
	  ble-      .loc_0x150

	.loc_0x120:
	  rlwinm.   r0,r24,0,24,31
	  bne-      .loc_0x4FC
	  cmplwi    r22, 0
	  beq-      .loc_0x4FC
	  lfs       f0, -0x4908(r2)
	  rlwinm    r0,r27,1,15,30
	  fadds     f0, f0, f27
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r3, 0x84(r1)
	  sthx      r3, r22, r0
	  b         .loc_0x4FC

	.loc_0x150:
	  lbz       r0, 0xD(r20)
	  cmplwi    r0, 0
	  bne-      .loc_0x220
	  cmpwi     r26, 0x20
	  bge-      .loc_0x220
	  cmpwi     r26, 0x1B
	  bne-      .loc_0x1D0
	  addi      r3, r20, 0
	  addi      r4, r1, 0xC
	  bl        .loc_0x5C8
	  rlwinm    r0,r3,0,16,31
	  cmplwi    r0, 0x484D
	  bne-      .loc_0x1C0
	  cmplwi    r30, 0
	  bne-      .loc_0x1AC
	  cmplwi    r22, 0
	  beq-      .loc_0x1AC
	  fadds     f0, f30, f27
	  rlwinm    r0,r27,1,15,30
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r3, 0x84(r1)
	  sthx      r3, r22, r0

	.loc_0x1AC:
	  stfs      f28, 0x1C(r20)
	  addi      r27, r27, 0x1
	  stfs      f29, 0x18(r20)
	  lfs       f27, -0x4918(r2)
	  b         .loc_0x3E4

	.loc_0x1C0:
	  cmplwi    r0, 0
	  beq-      .loc_0x3E4
	  li        r25, 0
	  b         .loc_0x3E4

	.loc_0x1D0:
	  addi      r3, r20, 0
	  addi      r4, r26, 0
	  bl        0xA14
	  cmpwi     r26, 0xA
	  li        r25, 0
	  bne-      .loc_0x3E4
	  cmplwi    r30, 0
	  bne-      .loc_0x210
	  cmplwi    r22, 0
	  beq-      .loc_0x210
	  fadds     f0, f30, f27
	  rlwinm    r0,r27,1,15,30
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r3, 0x84(r1)
	  sthx      r3, r22, r0

	.loc_0x210:
	  stfs      f29, 0x18(r20)
	  addi      r27, r27, 0x1
	  lfs       f27, -0x4918(r2)
	  b         .loc_0x3E4

	.loc_0x220:
	  lwz       r3, 0x0(r20)
	  li        r19, 0
	  lhz       r0, 0x4(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x264
	  lwz       r3, 0xC(r1)
	  rlwinm    r4,r26,8,0,23
	  addi      r0, r3, 0x1
	  stw       r0, 0xC(r1)
	  lwz       r0, 0xC(r1)
	  lbz       r3, 0x0(r3)
	  sub       r0, r0, r28
	  cmplw     r0, r21
	  or        r26, r4, r3
	  bgt+      .loc_0x104
	  li        r19, 0x1
	  b         .loc_0x2AC

	.loc_0x264:
	  cmplwi    r0, 0x2
	  bne-      .loc_0x2AC
	  cmpwi     r26, 0x80
	  blt-      .loc_0x2AC
	  lbz       r0, 0x0(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x2AC
	  lwz       r3, 0xC(r1)
	  rlwinm    r4,r26,8,0,23
	  addi      r0, r3, 0x1
	  stw       r0, 0xC(r1)
	  lwz       r0, 0xC(r1)
	  lbz       r3, 0x0(r3)
	  sub       r0, r0, r28
	  cmplw     r0, r21
	  or        r26, r4, r3
	  bgt+      .loc_0x104
	  li        r19, 0x1

	.loc_0x2AC:
	  lwz       r3, 0x0(r20)
	  mr        r4, r26
	  lwz       r5, 0x50(r20)
	  bl        0xEB8
	  stfs      f1, 0x20(r20)
	  stw       r29, 0x84(r1)
	  lfs       f1, 0x18(r20)
	  lfs       f0, 0x20(r20)
	  stw       r31, 0x80(r1)
	  fadds     f2, f1, f0
	  lfd       f0, 0x80(r1)
	  fsubs     f2, f2, f29
	  fsubs     f0, f0, f31
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x370
	  fcmpo     cr0, f1, f29
	  ble-      .loc_0x370
	  rlwinm.   r0,r19,0,24,31
	  beq-      .loc_0x300
	  li        r3, 0x2
	  b         .loc_0x304

	.loc_0x300:
	  li        r3, 0x1

	.loc_0x304:
	  lwz       r0, 0xC(r1)
	  cmplwi    r30, 0
	  sub       r0, r0, r3
	  stw       r0, 0xC(r1)
	  lwz       r0, 0x44(r20)
	  lfs       f1, 0x1C(r20)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x84(r1)
	  stw       r31, 0x80(r1)
	  lfd       f0, 0x80(r1)
	  fsubs     f0, f0, f31
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r20)
	  bne-      .loc_0x35C
	  cmplwi    r22, 0
	  beq-      .loc_0x35C
	  fadds     f0, f30, f27
	  rlwinm    r0,r27,1,15,30
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r3, 0x84(r1)
	  sthx      r3, r22, r0

	.loc_0x35C:
	  stfs      f29, 0x18(r20)
	  li        r25, 0
	  addi      r27, r27, 0x1
	  lfs       f27, -0x4918(r2)
	  b         .loc_0x3E4

	.loc_0x370:
	  cmplwi    r30, 0
	  beq-      .loc_0x3D4
	  cmplwi    r22, 0
	  beq-      .loc_0x3BC
	  rlwinm    r0,r27,1,15,30
	  lwz       r3, 0x0(r20)
	  lhax      r0, r22, r0
	  mr        r4, r26
	  lfs       f2, 0x1C(r20)
	  xoris     r0, r0, 0x8000
	  lwz       r5, 0x50(r20)
	  stw       r0, 0x84(r1)
	  lwz       r6, 0x54(r20)
	  stw       r31, 0x80(r1)
	  lfd       f0, 0x80(r1)
	  fsubs     f0, f0, f31
	  fadds     f1, f1, f0
	  bl        0xE80
	  b         .loc_0x3D4

	.loc_0x3BC:
	  lwz       r3, 0x0(r20)
	  mr        r4, r26
	  lfs       f2, 0x1C(r20)
	  lwz       r5, 0x50(r20)
	  lwz       r6, 0x54(r20)
	  bl        0xE64

	.loc_0x3D4:
	  lfs       f1, 0x18(r20)
	  lfs       f0, 0x20(r20)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r20)

	.loc_0x3E4:
	  rlwinm.   r0,r25,0,24,31
	  beq-      .loc_0x4E8
	  lfs       f0, 0x18(r20)
	  fsubs     f0, f0, f29
	  fcmpo     cr0, f0, f27
	  ble-      .loc_0x400
	  fmr       f27, f0

	.loc_0x400:
	  lwz       r0, 0x40(r20)
	  lfs       f1, 0x18(r20)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x84(r1)
	  stw       r31, 0x80(r1)
	  lfd       f0, 0x80(r1)
	  fsubs     f0, f0, f31
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r20)
	  lwz       r0, 0x40(r20)
	  lfs       f1, 0x20(r20)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x7C(r1)
	  stw       r31, 0x78(r1)
	  lfd       f0, 0x78(r1)
	  fsubs     f0, f0, f31
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r20)
	  lwz       r4, 0x0(r20)
	  lwz       r0, 0x54(r20)
	  lwz       r3, 0x0(r4)
	  xoris     r0, r0, 0x8000
	  lhz       r4, 0xC(r4)
	  lwz       r3, 0x8(r3)
	  stw       r0, 0x74(r1)
	  xoris     r0, r4, 0x8000
	  xoris     r3, r3, 0x8000
	  lfs       f2, 0x1C(r20)
	  stw       r3, 0x6C(r1)
	  stw       r31, 0x70(r1)
	  stw       r31, 0x68(r1)
	  lfd       f1, 0x70(r1)
	  lfd       f0, 0x68(r1)
	  fsubs     f1, f1, f31
	  stw       r0, 0x64(r1)
	  fsubs     f0, f0, f31
	  stw       r31, 0x60(r1)
	  fdivs     f1, f1, f0
	  lfd       f0, 0x60(r1)
	  fsubs     f0, f0, f31
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  fcmpo     cr0, f26, f0
	  bge-      .loc_0x4B4
	  fmr       f26, f0

	.loc_0x4B4:
	  lfs       f0, 0x18(r20)
	  fcmpo     cr0, f0, f24
	  ble-      .loc_0x4C4
	  fmr       f24, f0

	.loc_0x4C4:
	  fcmpo     cr0, f0, f25
	  bge-      .loc_0x4D0
	  fmr       f25, f0

	.loc_0x4D0:
	  fcmpo     cr0, f2, f22
	  ble-      .loc_0x4DC
	  fmr       f22, f2

	.loc_0x4DC:
	  fcmpo     cr0, f2, f23
	  bge-      .loc_0x4E8
	  fmr       f23, f2

	.loc_0x4E8:
	  lwz       r3, 0xC(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0xC(r1)
	  lbz       r26, 0x0(r3)
	  b         .loc_0x104

	.loc_0x4FC:
	  cmplwi    r22, 0
	  beq-      .loc_0x518
	  addi      r0, r27, 0x1
	  lis       r3, 0x1
	  subi      r3, r3, 0x1
	  rlwinm    r0,r0,1,15,30
	  sthx      r3, r22, r0

	.loc_0x518:
	  fsubs     f1, f24, f25
	  rlwinm.   r0,r24,0,24,31
	  lis       r4, 0x4330
	  fsubs     f4, f22, f23
	  fsubs     f0, f24, f29
	  stfs      f1, 0x0(r23)
	  fsubs     f1, f22, f28
	  lwz       r3, 0x0(r20)
	  lfd       f3, -0x4900(r2)
	  lhz       r0, 0x8(r3)
	  stw       r0, 0x64(r1)
	  stw       r4, 0x60(r1)
	  lfd       f2, 0x60(r1)
	  fsubs     f2, f2, f3
	  fadds     f2, f4, f2
	  stfs      f2, 0x4(r23)
	  stfs      f0, 0x8(r23)
	  lwz       r3, 0x0(r20)
	  lhz       r0, 0x8(r3)
	  stw       r0, 0x6C(r1)
	  stw       r4, 0x68(r1)
	  lfd       f0, 0x68(r1)
	  fsubs     f0, f0, f3
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r23)
	  bne-      .loc_0x588
	  stfs      f29, 0x18(r20)
	  stfs      f28, 0x1C(r20)

	.loc_0x588:
	  lmw       r19, 0x8C(r1)
	  fmr       f1, f26
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lfd       f30, 0x100(r1)
	  lfd       f29, 0xF8(r1)
	  lfd       f28, 0xF0(r1)
	  lfd       f27, 0xE8(r1)
	  lfd       f26, 0xE0(r1)
	  lfd       f25, 0xD8(r1)
	  lfd       f24, 0xD0(r1)
	  lfd       f23, 0xC8(r1)
	  lfd       f22, 0xC0(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr

	.loc_0x5C8:
	*/
}

/*
 * --INFO--
 * Address:	801B53C4
 * Size:	000624
 */
void P2DPrint::doEscapeCode(const u8**)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  stw       r30, 0x40(r1)
	  lwz       r5, 0x0(r4)
	  lbz       r0, 0x0(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  lbz       r3, 0x1(r5)
	  cmplwi    r3, 0
	  bne-      .loc_0x3C

	.loc_0x34:
	  li        r3, 0
	  b         .loc_0x60C

	.loc_0x3C:
	  rlwinm    r0,r0,8,0,23
	  or        r0, r0, r3
	  rlwinm    r30,r0,0,16,31
	  addi      r0, r5, 0x2
	  cmpwi     r30, 0x4742
	  stw       r0, 0x0(r4)
	  beq-      .loc_0x5F8
	  bge-      .loc_0xC4
	  cmpwi     r30, 0x4352
	  beq-      .loc_0x1E4
	  bge-      .loc_0x98
	  cmpwi     r30, 0x4344
	  beq-      .loc_0x164
	  bge-      .loc_0x8C
	  cmpwi     r30, 0x4342
	  beq-      .loc_0x5F8
	  bge-      .loc_0x3D8
	  cmpwi     r30, 0x4341
	  bge-      .loc_0x2A8
	  b         .loc_0x5F8

	.loc_0x8C:
	  cmpwi     r30, 0x434C
	  beq-      .loc_0x1A4
	  b         .loc_0x5F8

	.loc_0x98:
	  cmpwi     r30, 0x4658
	  beq-      .loc_0x528
	  bge-      .loc_0xB0
	  cmpwi     r30, 0x4355
	  beq-      .loc_0x124
	  b         .loc_0x5F8

	.loc_0xB0:
	  cmpwi     r30, 0x4741
	  bge-      .loc_0x340
	  cmpwi     r30, 0x465A
	  bge-      .loc_0x5F8
	  b         .loc_0x54C

	.loc_0xC4:
	  cmpwi     r30, 0x4C55
	  beq-      .loc_0x224
	  bge-      .loc_0x100
	  cmpwi     r30, 0x484D
	  beq-      .loc_0x608
	  bge-      .loc_0xF4
	  cmpwi     r30, 0x474D
	  beq-      .loc_0x5A8
	  bge-      .loc_0x5F8
	  cmpwi     r30, 0x4744
	  bge-      .loc_0x5F8
	  b         .loc_0x480

	.loc_0xF4:
	  cmpwi     r30, 0x4C44
	  beq-      .loc_0x254
	  b         .loc_0x5F8

	.loc_0x100:
	  cmpwi     r30, 0x5354
	  beq-      .loc_0x284
	  bge-      .loc_0x118
	  cmpwi     r30, 0x5348
	  beq-      .loc_0x570
	  b         .loc_0x5F8

	.loc_0x118:
	  cmpwi     r30, 0x5356
	  beq-      .loc_0x58C
	  b         .loc_0x5F8

	.loc_0x124:
	  addi      r3, r31, 0
	  li        r5, 0x1
	  li        r6, 0
	  li        r7, 0xA
	  bl        0x664
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4910(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f0, 0x1C(r31)
	  stw       r0, 0x38(r1)
	  lfd       f1, 0x38(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f1
	  stfs      f0, 0x1C(r31)
	  b         .loc_0x608

	.loc_0x164:
	  addi      r3, r31, 0
	  li        r5, 0x1
	  li        r6, 0
	  li        r7, 0xA
	  bl        0x624
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4910(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f0, 0x1C(r31)
	  stw       r0, 0x38(r1)
	  lfd       f1, 0x38(r1)
	  fsubs     f1, f1, f2
	  fadds     f0, f0, f1
	  stfs      f0, 0x1C(r31)
	  b         .loc_0x608

	.loc_0x1A4:
	  addi      r3, r31, 0
	  li        r5, 0x1
	  li        r6, 0
	  li        r7, 0xA
	  bl        0x5E4
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4910(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f0, 0x18(r31)
	  stw       r0, 0x38(r1)
	  lfd       f1, 0x38(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f1
	  stfs      f0, 0x18(r31)
	  b         .loc_0x608

	.loc_0x1E4:
	  addi      r3, r31, 0
	  li        r5, 0x1
	  li        r6, 0
	  li        r7, 0xA
	  bl        0x5A4
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4910(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f0, 0x18(r31)
	  stw       r0, 0x38(r1)
	  lfd       f1, 0x38(r1)
	  fsubs     f1, f1, f2
	  fadds     f0, f0, f1
	  stfs      f0, 0x18(r31)
	  b         .loc_0x608

	.loc_0x224:
	  lwz       r3, 0x44(r31)
	  lis       r0, 0x4330
	  lfd       f1, -0x4910(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f2, 0x1C(r31)
	  stw       r3, 0x3C(r1)
	  stw       r0, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  fsubs     f0, f0, f1
	  fsubs     f0, f2, f0
	  stfs      f0, 0x1C(r31)
	  b         .loc_0x608

	.loc_0x254:
	  lwz       r3, 0x44(r31)
	  lis       r0, 0x4330
	  lfd       f1, -0x4910(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f2, 0x1C(r31)
	  stw       r3, 0x3C(r1)
	  stw       r0, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  fsubs     f0, f0, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0x1C(r31)
	  b         .loc_0x608

	.loc_0x284:
	  lwz       r5, 0x4C(r31)
	  addi      r3, r31, 0
	  li        r7, 0xA
	  addi      r6, r5, 0
	  bl        0x504
	  cmpwi     r3, 0
	  ble-      .loc_0x608
	  stw       r3, 0x4C(r31)
	  b         .loc_0x608

	.loc_0x2A8:
	  lbz       r6, 0x25(r31)
	  mr        r3, r31
	  lbz       r0, 0x29(r31)
	  lbz       r9, 0x24(r31)
	  rlwinm    r6,r6,16,0,15
	  lbz       r5, 0x28(r31)
	  rlwinm    r0,r0,16,0,15
	  lbz       r10, 0x26(r31)
	  rlwimi    r6,r9,24,0,7
	  lbz       r7, 0x2A(r31)
	  rlwimi    r0,r5,24,0,7
	  lbz       r11, 0x27(r31)
	  rlwimi    r6,r10,8,16,23
	  lbz       r8, 0x2B(r31)
	  rlwimi    r0,r7,8,16,23
	  or        r6, r11, r6
	  or        r5, r8, r0
	  li        r7, 0x10
	  bl        0x4A8
	  stw       r3, 0x2C(r1)
	  lbz       r5, 0x2F(r1)
	  lbz       r4, 0x2E(r1)
	  lbz       r3, 0x2D(r1)
	  lbz       r0, 0x2C(r1)
	  stb       r0, 0x24(r31)
	  stb       r3, 0x25(r31)
	  stb       r4, 0x26(r31)
	  stb       r5, 0x27(r31)
	  lbz       r0, 0x48(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x32C
	  addi      r5, r31, 0x2C
	  b         .loc_0x330

	.loc_0x32C:
	  addi      r5, r31, 0x24

	.loc_0x330:
	  lwz       r3, 0x0(r31)
	  addi      r4, r31, 0x24
	  bl        0x84C
	  b         .loc_0x608

	.loc_0x340:
	  lbz       r6, 0x2D(r31)
	  mr        r3, r31
	  lbz       r0, 0x31(r31)
	  lbz       r9, 0x2C(r31)
	  rlwinm    r6,r6,16,0,15
	  lbz       r5, 0x30(r31)
	  rlwinm    r0,r0,16,0,15
	  lbz       r10, 0x2E(r31)
	  rlwimi    r6,r9,24,0,7
	  lbz       r7, 0x32(r31)
	  rlwimi    r0,r5,24,0,7
	  lbz       r11, 0x2F(r31)
	  rlwimi    r6,r10,8,16,23
	  lbz       r8, 0x33(r31)
	  rlwimi    r0,r7,8,16,23
	  or        r6, r11, r6
	  or        r5, r8, r0
	  li        r7, 0x10
	  bl        0x410
	  stw       r3, 0x28(r1)
	  lbz       r5, 0x2B(r1)
	  lbz       r4, 0x2A(r1)
	  lbz       r3, 0x29(r1)
	  lbz       r0, 0x28(r1)
	  stb       r0, 0x2C(r31)
	  stb       r3, 0x2D(r31)
	  stb       r4, 0x2E(r31)
	  stb       r5, 0x2F(r31)
	  lbz       r0, 0x48(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C4
	  addi      r5, r31, 0x2C
	  b         .loc_0x3C8

	.loc_0x3C4:
	  addi      r5, r31, 0x24

	.loc_0x3C8:
	  lwz       r3, 0x0(r31)
	  addi      r4, r31, 0x24
	  bl        0x7B4
	  b         .loc_0x608

	.loc_0x3D8:
	  lbz       r6, 0x25(r31)
	  mr        r3, r31
	  lbz       r0, 0x29(r31)
	  lbz       r9, 0x24(r31)
	  rlwinm    r6,r6,16,0,15
	  lbz       r5, 0x28(r31)
	  rlwinm    r0,r0,16,0,15
	  lbz       r10, 0x26(r31)
	  rlwimi    r6,r9,24,0,7
	  lbz       r7, 0x2A(r31)
	  rlwimi    r0,r5,24,0,7
	  lbz       r11, 0x27(r31)
	  rlwimi    r6,r10,8,16,23
	  lbz       r8, 0x2B(r31)
	  rlwimi    r0,r7,8,16,23
	  or        r6, r11, r6
	  or        r5, r8, r0
	  li        r7, 0x10
	  bl        0x378
	  stw       r3, 0x24(r1)
	  lbz       r5, 0x27(r1)
	  lbz       r4, 0x26(r1)
	  lbz       r3, 0x25(r1)
	  lbz       r0, 0x24(r1)
	  stb       r0, 0x24(r31)
	  stb       r3, 0x25(r31)
	  stb       r4, 0x26(r31)
	  stb       r5, 0x27(r31)
	  lwz       r3, 0x0(r31)
	  lbz       r0, 0x11(r3)
	  stb       r0, 0x27(r31)
	  stb       r0, 0x2F(r31)
	  lbz       r0, 0x48(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x46C
	  addi      r5, r31, 0x2C
	  b         .loc_0x470

	.loc_0x46C:
	  addi      r5, r31, 0x24

	.loc_0x470:
	  lwz       r3, 0x0(r31)
	  addi      r4, r31, 0x24
	  bl        0x70C
	  b         .loc_0x608

	.loc_0x480:
	  lbz       r6, 0x2D(r31)
	  mr        r3, r31
	  lbz       r0, 0x31(r31)
	  lbz       r9, 0x2C(r31)
	  rlwinm    r6,r6,16,0,15
	  lbz       r5, 0x30(r31)
	  rlwinm    r0,r0,16,0,15
	  lbz       r10, 0x2E(r31)
	  rlwimi    r6,r9,24,0,7
	  lbz       r7, 0x32(r31)
	  rlwimi    r0,r5,24,0,7
	  lbz       r11, 0x2F(r31)
	  rlwimi    r6,r10,8,16,23
	  lbz       r8, 0x33(r31)
	  rlwimi    r0,r7,8,16,23
	  or        r6, r11, r6
	  or        r5, r8, r0
	  li        r7, 0x10
	  bl        0x2D0
	  stw       r3, 0x1C(r1)
	  lbz       r5, 0x1F(r1)
	  lbz       r4, 0x1E(r1)
	  lbz       r3, 0x1D(r1)
	  lbz       r0, 0x1C(r1)
	  stb       r0, 0x2C(r31)
	  stb       r3, 0x2D(r31)
	  stb       r4, 0x2E(r31)
	  stb       r5, 0x2F(r31)
	  lwz       r3, 0x0(r31)
	  lbz       r0, 0x11(r3)
	  stb       r0, 0x27(r31)
	  stb       r0, 0x2F(r31)
	  lbz       r0, 0x48(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x514
	  addi      r5, r31, 0x2C
	  b         .loc_0x518

	.loc_0x514:
	  addi      r5, r31, 0x24

	.loc_0x518:
	  lwz       r3, 0x0(r31)
	  addi      r4, r31, 0x24
	  bl        0x664
	  b         .loc_0x608

	.loc_0x528:
	  lwz       r5, 0x38(r31)
	  mr        r3, r31
	  lwz       r6, 0x50(r31)
	  li        r7, 0xA
	  bl        0x260
	  cmpwi     r3, 0
	  blt-      .loc_0x608
	  stw       r3, 0x50(r31)
	  b         .loc_0x608

	.loc_0x54C:
	  lwz       r5, 0x3C(r31)
	  mr        r3, r31
	  lwz       r6, 0x54(r31)
	  li        r7, 0xA
	  bl        0x23C
	  cmpwi     r3, 0
	  blt-      .loc_0x608
	  stw       r3, 0x54(r31)
	  b         .loc_0x608

	.loc_0x570:
	  lwz       r5, 0x4(r31)
	  mr        r3, r31
	  lwz       r6, 0x40(r31)
	  li        r7, 0xA
	  bl        0x218
	  stw       r3, 0x40(r31)
	  b         .loc_0x608

	.loc_0x58C:
	  lwz       r5, 0x8(r31)
	  mr        r3, r31
	  lwz       r6, 0x44(r31)
	  li        r7, 0xA
	  bl        0x1FC
	  stw       r3, 0x44(r31)
	  b         .loc_0x608

	.loc_0x5A8:
	  lbz       r6, 0x48(r31)
	  addi      r3, r31, 0
	  li        r7, 0xA
	  cntlzw    r0, r6
	  rlwinm    r5,r0,27,24,31
	  bl        0x1DC
	  neg       r3, r3
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x48(r31)
	  lbz       r0, 0x48(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x5E4
	  addi      r5, r31, 0x2C
	  b         .loc_0x5E8

	.loc_0x5E4:
	  addi      r5, r31, 0x24

	.loc_0x5E8:
	  lwz       r3, 0x0(r31)
	  addi      r4, r31, 0x24
	  bl        0x594
	  b         .loc_0x608

	.loc_0x5F8:
	  lwz       r3, 0x0(r4)
	  li        r30, 0
	  subi      r0, r3, 0x2
	  stw       r0, 0x0(r4)

	.loc_0x608:
	  mr        r3, r30

	.loc_0x60C:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B59E8
 * Size:	000174
 */
void P2DPrint::doCtrlCode(int)
{
	/*
	.loc_0x0:
	  subi      r0, r4, 0x8
	  stwu      r1, -0x20(r1)
	  cmplwi    r0, 0x17
	  bgt-      .loc_0x16C
	  lis       r4, 0x802E
	  addi      r4, r4, 0x8F0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  lfs       f1, 0x18(r3)
	  lfs       f0, 0x20(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x18(r3)
	  lfs       f0, -0x4918(r2)
	  stfs      f0, 0x20(r3)
	  b         .loc_0x16C
	  lwz       r5, 0x4C(r3)
	  cmpwi     r5, 0
	  ble-      .loc_0x16C
	  lfs       f2, 0x18(r3)
	  lis       r0, 0x4330
	  lfd       f1, -0x4910(r2)
	  fctiwz    f0, f2
	  stfd      f0, 0x18(r1)
	  lwz       r4, 0x1C(r1)
	  divw      r4, r4, r5
	  mullw     r4, r5, r4
	  add       r4, r5, r4
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x14(r1)
	  stw       r0, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x18(r3)
	  lfs       f0, 0x18(r3)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x20(r3)
	  b         .loc_0x16C
	  lfs       f0, -0x4918(r2)
	  lis       r4, 0x4330
	  stfs      f0, 0x20(r3)
	  lwz       r0, 0x10(r3)
	  lfd       f2, -0x4910(r2)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x14(r1)
	  stw       r4, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x18(r3)
	  lwz       r0, 0x44(r3)
	  lfs       f1, 0x1C(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1C(r1)
	  stw       r4, 0x18(r1)
	  lfd       f0, 0x18(r1)
	  fsubs     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r3)
	  b         .loc_0x16C
	  lfs       f0, -0x4918(r2)
	  lis       r0, 0x4330
	  stfs      f0, 0x20(r3)
	  lwz       r4, 0x10(r3)
	  lfd       f1, -0x4910(r2)
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x14(r1)
	  stw       r0, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x18(r3)
	  b         .loc_0x16C
	  lfs       f1, 0x18(r3)
	  lfs       f0, -0x48F8(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r3)
	  b         .loc_0x16C
	  lfs       f1, 0x18(r3)
	  lfs       f0, -0x48F8(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x18(r3)
	  b         .loc_0x16C
	  lfs       f1, 0x1C(r3)
	  lfs       f0, -0x48F8(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1C(r3)
	  b         .loc_0x16C
	  lfs       f1, 0x1C(r3)
	  lfs       f0, -0x48F8(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r3)

	.loc_0x16C:
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B5B5C
 * Size:	000108
 */
void P2DPrint::getNumber(const u8**, s32, s32, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  addi      r29, r6, 0
	  stw       r28, 0x20(r1)
	  addi      r28, r5, 0
	  lwz       r30, 0x0(r4)
	  lbz       r0, 0x0(r30)
	  cmplwi    r0, 0x5B
	  beq-      .loc_0x40
	  mr        r3, r28
	  b         .loc_0xE8

	.loc_0x40:
	  addi      r0, r30, 0x1
	  cmpwi     r7, 0xA
	  stw       r0, 0x0(r31)
	  li        r3, 0
	  bne-      .loc_0x68
	  lwz       r3, 0x0(r31)
	  addi      r5, r7, 0
	  addi      r4, r1, 0x1C
	  bl        0x640A4
	  b         .loc_0xB4

	.loc_0x68:
	  cmpwi     r7, 0x10
	  bne-      .loc_0xB4
	  lwz       r3, 0x0(r31)
	  addi      r5, r7, 0
	  addi      r4, r1, 0x1C
	  bl        0x64178
	  lwz       r4, 0x0(r31)
	  lwz       r0, 0x1C(r1)
	  sub       r0, r0, r4
	  cmplwi    r0, 0x8
	  beq-      .loc_0xB4
	  cmplwi    r0, 0x6
	  bne-      .loc_0xA8
	  rlwinm    r0,r3,8,0,23
	  ori       r3, r0, 0xFF
	  b         .loc_0xB4

	.loc_0xA8:
	  stw       r30, 0x0(r31)
	  mr        r3, r29
	  b         .loc_0xE8

	.loc_0xB4:
	  lwz       r4, 0x1C(r1)
	  lbz       r0, 0x0(r4)
	  cmplwi    r0, 0x5D
	  beq-      .loc_0xD0
	  stw       r30, 0x0(r31)
	  mr        r3, r29
	  b         .loc_0xE8

	.loc_0xD0:
	  lwz       r0, 0x0(r31)
	  cmplw     r0, r4
	  bne-      .loc_0xE0
	  mr        r3, r28

	.loc_0xE0:
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r31)

	.loc_0xE8:
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
