#include "P2D/Picture.h"
#include "P2D/Stream.h"
#include "P2D/Util.h"
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
 * Address:	801B18C4
 * Size:	000074
 */
void P2DPicture::makeResident()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  addi      r31, r29, 0
	  b         .loc_0x4C

	.loc_0x28:
	  lwz       r3, 0xEC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x44:
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x4C:
	  lbz       r0, 0xF1(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x28
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
 * Address:	801B1938
 * Size:	000058
 */
void P2DPicture::loadResource()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x110(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x40C80
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  stw       r3, 0xEC(r31)
	  lbz       r3, 0xF1(r31)
	  addi      r0, r3, 0x1
	  stb       r0, 0xF1(r31)

	.loc_0x44:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B1990
 * Size:	0000B4
 */
P2DPicture::~P2DPicture()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  mr.       r28, r3
	  beq-      .loc_0x90
	  lis       r3, 0x802E
	  addi      r0, r3, 0x728
	  stw       r0, 0x0(r28)
	  addi      r31, r28, 0
	  li        r30, 0
	  b         .loc_0x68

	.loc_0x40:
	  lwz       r3, 0xEC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  addi      r0, r30, 0xF2
	  lbzx      r0, r28, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  bl        -0x16A840

	.loc_0x60:
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x68:
	  lbz       r0, 0xF1(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x40
	  addi      r3, r28, 0
	  li        r4, 0
	  bl        -0xC48
	  extsh.    r0, r29
	  ble-      .loc_0x90
	  mr        r3, r28
	  bl        -0x16A870

	.loc_0x90:
	  mr        r3, r28
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
P2DPicture::P2DPicture()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B1A44
 * Size:	000134
 */
P2DPicture::P2DPicture(P2DPane*, RandomAccessStream*, u16)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  mr        r30, r5
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        -0xF30
	  lis       r3, 0x802E
	  lwz       r31, 0x8(r1)
	  addi      r0, r3, 0x728
	  stw       r0, 0x0(r31)
	  lis       r4, 0x5449
	  addi      r3, r1, 0x18
	  stw       r30, 0x18(r1)
	  addi      r4, r4, 0x4D47
	  bl        0x17EC
	  stw       r3, 0x110(r31)
	  lis       r4, 0x544C
	  addi      r3, r1, 0x18
	  addi      r4, r4, 0x5554
	  bl        0x17D8
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  stw       r0, 0xF4(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r4,r3,0,24,31
	  rlwinm.   r0,r3,0,29,29
	  rlwinm    r3,r3,0,30,31
	  stw       r3, 0xF8(r31)
	  beq-      .loc_0xA8
	  li        r0, 0x1
	  b         .loc_0xAC

	.loc_0xA8:
	  li        r0, 0

	.loc_0xAC:
	  neg       r3, r0
	  lwz       r31, 0x8(r1)
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0xFC(r31)
	  rlwinm    r0,r4,29,30,31
	  addi      r3, r1, 0x18
	  stw       r0, 0x100(r31)
	  li        r4, 0x4
	  lwz       r0, 0x100(r31)
	  stw       r0, 0x104(r31)
	  bl        0x181C
	  li        r5, 0
	  stw       r5, 0xEC(r31)
	  li        r4, 0x1
	  li        r0, 0xFF
	  stb       r5, 0xF1(r31)
	  mr        r3, r31
	  stb       r4, 0xF2(r31)
	  stb       r0, 0xF0(r31)
	  stb       r5, 0x10C(r31)
	  stb       r5, 0x10D(r31)
	  stb       r5, 0x10E(r31)
	  stb       r5, 0x10F(r31)
	  stb       r0, 0x108(r31)
	  stb       r0, 0x109(r31)
	  stb       r0, 0x10A(r31)
	  stb       r0, 0x10B(r31)
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
 * Address:	........
 * Size:	000040
 */
P2DStream::~P2DStream()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B1B78
 * Size:	0000AC
 */
P2DPicture::P2DPicture(Texture*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        -0x1318
	  lis       r3, 0x802E
	  lwz       r31, 0x8(r1)
	  addi      r0, r3, 0x728
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  cmplwi    r30, 0
	  stw       r0, 0xEC(r31)
	  stb       r0, 0xF1(r31)
	  beq-      .loc_0x88
	  lfs       f1, -0x4948(r2)
	  addi      r3, r31, 0
	  lbz       r5, 0xF1(r31)
	  addi      r4, r30, 0
	  bl        .loc_0xAC
	  lwz       r6, 0xEC(r31)
	  addi      r3, r1, 0x10
	  li        r4, 0
	  lhz       r7, 0xA(r6)
	  li        r5, 0
	  lhz       r6, 0x8(r6)
	  bl        0x1A3C
	  lwz       r3, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stw       r3, 0x18(r31)
	  stw       r0, 0x1C(r31)

	.loc_0x88:
	  lwz       r3, 0x8(r1)
	  bl        0xBC
	  lwz       r3, 0x8(r1)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0xAC:
	*/
}

/*
 * --INFO--
 * Address:	801B1C24
 * Size:	00009C
 */
bool P2DPicture::insert(Texture*, u8, f32)
{
	/*
	.loc_0x0:
	  mr        r10, r3
	  lbz       r0, 0xF1(r3)
	  cmplwi    r0, 0x1
	  bge-      .loc_0x24
	  rlwinm    r6,r5,0,24,31
	  cmplwi    r6, 0x1
	  bge-      .loc_0x24
	  cmplw     r6, r0
	  ble-      .loc_0x2C

	.loc_0x24:
	  li        r3, 0
	  blr

	.loc_0x2C:
	  addi      r7, r10, 0
	  addi      r8, r10, 0
	  li        r9, 0
	  b         .loc_0x64

	.loc_0x3C:
	  lwz       r0, 0xE8(r7)
	  rlwinm    r5,r9,0,24,31
	  addi      r3, r5, 0xF1
	  stw       r0, 0xEC(r8)
	  addi      r0, r5, 0xF2
	  subi      r7, r7, 0x4
	  lbzx      r3, r10, r3
	  subi      r8, r8, 0x4
	  subi      r9, r9, 0x1
	  stbx      r3, r10, r0

	.loc_0x64:
	  rlwinm    r0,r9,0,24,31
	  cmplw     r0, r6
	  bgt+      .loc_0x3C
	  rlwinm    r0,r6,2,0,29
	  add       r3, r10, r0
	  stw       r4, 0xEC(r3)
	  add       r3, r10, r6
	  li        r0, 0
	  stb       r0, 0xF2(r3)
	  li        r3, 0x1
	  lbz       r4, 0xF1(r10)
	  addi      r0, r4, 0x1
	  stb       r0, 0xF1(r10)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B1CC0
 * Size:	000054
 */
void P2DPicture::initinfo()
{
	/*
	.loc_0x0:
	  li        r0, 0x12
	  sth       r0, 0x8(r3)
	  li        r0, 0xF
	  li        r5, 0
	  stw       r0, 0xF4(r3)
	  li        r4, -0x1
	  li        r0, 0xFF
	  stw       r5, 0xF8(r3)
	  stb       r5, 0xFC(r3)
	  stw       r4, 0x100(r3)
	  stw       r4, 0x104(r3)
	  stb       r0, 0xF0(r3)
	  stb       r5, 0x10C(r3)
	  stb       r5, 0x10D(r3)
	  stb       r5, 0x10E(r3)
	  stb       r5, 0x10F(r3)
	  stb       r0, 0x108(r3)
	  stb       r0, 0x109(r3)
	  stb       r0, 0x10A(r3)
	  stb       r0, 0x10B(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B1D14
 * Size:	000068
 */
void P2DPicture::drawSelf(int, int)
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
	  bl        -0x173F80
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
 * Address:	801B1D7C
 * Size:	000078
 */
void P2DPicture::drawSelf(int, int, Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  lwz       r0, 0xEC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x68
	  lha       r7, 0x1A(r3)
	  lha       r0, 0x1E(r3)
	  lha       r9, 0x18(r3)
	  lha       r8, 0x1C(r3)
	  sub       r7, r0, r7
	  lwz       r0, 0x100(r3)
	  sub       r8, r8, r9
	  stw       r0, 0x8(r1)
	  lwz       r0, 0x104(r3)
	  stw       r0, 0xC(r1)
	  stw       r6, 0x10(r1)
	  mr        r6, r8
	  lha       r9, 0x20(r3)
	  lha       r0, 0x22(r3)
	  add       r4, r9, r4
	  lwz       r8, 0xF4(r3)
	  lwz       r9, 0xF8(r3)
	  add       r5, r0, r5
	  lbz       r10, 0xFC(r3)
	  bl        .loc_0x78

	.loc_0x68:
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x78:
	*/
}

/*
 * --INFO--
 * Address:	801B1DF4
 * Size:	000664
 */
void P2DPicture::drawFullSet(int, int, int, int, P2DBinding, P2DMirror, bool, P2DWrapmode, P2DWrapmode, Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stmw      r22, 0x50(r1)
	  addi      r23, r4, 0
	  lwz       r11, 0x80(r1)
	  addi      r24, r5, 0
	  lwz       r0, 0x84(r1)
	  cmpwi     r11, 0
	  lwz       r29, 0x88(r1)
	  addi      r22, r3, 0
	  addi      r25, r6, 0
	  addi      r26, r7, 0
	  addi      r27, r9, 0
	  addi      r28, r10, 0
	  addi      r31, r23, 0
	  addi      r30, r24, 0
	  bne-      .loc_0x148
	  rlwinm.   r3,r28,0,24,31
	  bne-      .loc_0x74
	  lwz       r4, 0xEC(r22)
	  lis       r3, 0x4330
	  lfd       f1, -0x4938(r2)
	  lhz       r4, 0x8(r4)
	  stw       r4, 0x4C(r1)
	  stw       r3, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f2, f0, f1
	  b         .loc_0x94

	.loc_0x74:
	  lwz       r4, 0xEC(r22)
	  lis       r3, 0x4330
	  lfd       f1, -0x4938(r2)
	  lhz       r4, 0xA(r4)
	  stw       r4, 0x4C(r1)
	  stw       r3, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f2, f0, f1

	.loc_0x94:
	  rlwinm.   r3,r8,0,28,28
	  beq-      .loc_0xD8
	  rlwinm.   r3,r8,0,29,29
	  bne-      .loc_0x148
	  xoris     r3, r25, 0x8000
	  lfd       f1, -0x4930(r2)
	  stw       r3, 0x4C(r1)
	  lis       r3, 0x4330
	  stw       r3, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x148
	  fctiwz    f0, f2
	  stfd      f0, 0x48(r1)
	  lwz       r25, 0x4C(r1)
	  b         .loc_0x148

	.loc_0xD8:
	  xoris     r3, r25, 0x8000
	  lfd       f1, -0x4930(r2)
	  stw       r3, 0x4C(r1)
	  lis       r3, 0x4330
	  stw       r3, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x148
	  rlwinm.   r3,r8,0,29,29
	  beq-      .loc_0x11C
	  fctiwz    f0, f2
	  add       r3, r23, r25
	  stfd      f0, 0x48(r1)
	  lwz       r4, 0x4C(r1)
	  sub       r3, r3, r4
	  b         .loc_0x138

	.loc_0x11C:
	  fctiwz    f0, f2
	  stfd      f0, 0x48(r1)
	  lwz       r3, 0x4C(r1)
	  sub       r3, r25, r3
	  srawi     r3, r3, 0x1
	  addze     r3, r3
	  add       r3, r23, r3

	.loc_0x138:
	  fctiwz    f0, f2
	  mr        r31, r3
	  stfd      f0, 0x48(r1)
	  lwz       r25, 0x4C(r1)

	.loc_0x148:
	  cmpwi     r0, 0
	  bne-      .loc_0x250
	  rlwinm.   r0,r28,0,24,31
	  bne-      .loc_0x17C
	  lwz       r3, 0xEC(r22)
	  lis       r0, 0x4330
	  lfd       f1, -0x4938(r2)
	  lhz       r3, 0xA(r3)
	  stw       r3, 0x4C(r1)
	  stw       r0, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f2, f0, f1
	  b         .loc_0x19C

	.loc_0x17C:
	  lwz       r3, 0xEC(r22)
	  lis       r0, 0x4330
	  lfd       f1, -0x4938(r2)
	  lhz       r3, 0x8(r3)
	  stw       r3, 0x4C(r1)
	  stw       r0, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f2, f0, f1

	.loc_0x19C:
	  rlwinm.   r0,r8,0,30,30
	  beq-      .loc_0x1E0
	  rlwinm.   r0,r8,0,31,31
	  bne-      .loc_0x250
	  xoris     r0, r26, 0x8000
	  lfd       f1, -0x4930(r2)
	  stw       r0, 0x4C(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x250
	  fctiwz    f0, f2
	  stfd      f0, 0x48(r1)
	  lwz       r26, 0x4C(r1)
	  b         .loc_0x250

	.loc_0x1E0:
	  xoris     r0, r26, 0x8000
	  lfd       f1, -0x4930(r2)
	  stw       r0, 0x4C(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x250
	  rlwinm.   r0,r8,0,31,31
	  beq-      .loc_0x224
	  fctiwz    f0, f2
	  add       r0, r24, r26
	  stfd      f0, 0x48(r1)
	  lwz       r3, 0x4C(r1)
	  sub       r0, r0, r3
	  b         .loc_0x240

	.loc_0x224:
	  fctiwz    f0, f2
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  sub       r0, r26, r0
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r24, r0

	.loc_0x240:
	  fctiwz    f0, f2
	  mr        r30, r0
	  stfd      f0, 0x48(r1)
	  lwz       r26, 0x4C(r1)

	.loc_0x250:
	  rlwinm.   r0,r28,0,24,31
	  bne-      .loc_0x30C
	  rlwinm.   r4,r27,0,30,30
	  beq-      .loc_0x274
	  rlwinm    r0,r8,0,29,29
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  b         .loc_0x284

	.loc_0x274:
	  rlwinm    r0,r8,0,28,28
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3

	.loc_0x284:
	  cmpwi     r4, 0
	  beq-      .loc_0x2A0
	  rlwinm    r3,r8,0,28,28
	  neg       r4, r3
	  subic     r3, r4, 0x1
	  subfe     r3, r3, r4
	  b         .loc_0x2B0

	.loc_0x2A0:
	  rlwinm    r3,r8,0,29,29
	  neg       r4, r3
	  subic     r3, r4, 0x1
	  subfe     r3, r3, r4

	.loc_0x2B0:
	  rlwinm.   r6,r27,0,31,31
	  beq-      .loc_0x2CC
	  rlwinm    r4,r8,0,31,31
	  neg       r5, r4
	  subic     r4, r5, 0x1
	  subfe     r4, r4, r5
	  b         .loc_0x2DC

	.loc_0x2CC:
	  rlwinm    r4,r8,0,30,30
	  neg       r5, r4
	  subic     r4, r5, 0x1
	  subfe     r4, r4, r5

	.loc_0x2DC:
	  cmpwi     r6, 0
	  beq-      .loc_0x2F8
	  rlwinm    r5,r8,0,30,30
	  neg       r6, r5
	  subic     r5, r6, 0x1
	  subfe     r5, r5, r6
	  b         .loc_0x3BC

	.loc_0x2F8:
	  rlwinm    r5,r8,0,31,31
	  neg       r6, r5
	  subic     r5, r6, 0x1
	  subfe     r5, r5, r6
	  b         .loc_0x3BC

	.loc_0x30C:
	  rlwinm.   r4,r27,0,30,30
	  beq-      .loc_0x328
	  rlwinm    r0,r8,0,31,31
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  b         .loc_0x338

	.loc_0x328:
	  rlwinm    r0,r8,0,30,30
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3

	.loc_0x338:
	  cmpwi     r4, 0
	  beq-      .loc_0x354
	  rlwinm    r3,r8,0,30,30
	  neg       r4, r3
	  subic     r3, r4, 0x1
	  subfe     r3, r3, r4
	  b         .loc_0x364

	.loc_0x354:
	  rlwinm    r3,r8,0,31,31
	  neg       r4, r3
	  subic     r3, r4, 0x1
	  subfe     r3, r3, r4

	.loc_0x364:
	  rlwinm.   r6,r27,0,31,31
	  beq-      .loc_0x380
	  rlwinm    r4,r8,0,28,28
	  neg       r5, r4
	  subic     r4, r5, 0x1
	  subfe     r4, r4, r5
	  b         .loc_0x390

	.loc_0x380:
	  rlwinm    r4,r8,0,29,29
	  neg       r5, r4
	  subic     r4, r5, 0x1
	  subfe     r4, r4, r5

	.loc_0x390:
	  cmpwi     r6, 0
	  beq-      .loc_0x3AC
	  rlwinm    r5,r8,0,29,29
	  neg       r6, r5
	  subic     r5, r6, 0x1
	  subfe     r5, r5, r6
	  b         .loc_0x3BC

	.loc_0x3AC:
	  rlwinm    r5,r8,0,28,28
	  neg       r6, r5
	  subic     r5, r6, 0x1
	  subfe     r5, r5, r6

	.loc_0x3BC:
	  lwz       r7, 0xEC(r22)
	  rlwinm    r6,r28,0,24,31
	  lfd       f2, -0x4938(r2)
	  cntlzw    r6, r6
	  lhz       r9, 0x8(r7)
	  lhz       r8, 0xA(r7)
	  rlwinm    r7,r6,27,5,31
	  stw       r9, 0x4C(r1)
	  lis       r9, 0x4330
	  rlwinm.   r6,r6,27,24,31
	  stw       r8, 0x44(r1)
	  stw       r9, 0x48(r1)
	  stw       r9, 0x40(r1)
	  lfd       f1, 0x48(r1)
	  lfd       f0, 0x40(r1)
	  fsubs     f4, f1, f2
	  fsubs     f0, f0, f2
	  beq-      .loc_0x40C
	  mr        r8, r25
	  b         .loc_0x410

	.loc_0x40C:
	  mr        r8, r26

	.loc_0x410:
	  rlwinm.   r6,r7,0,24,31
	  beq-      .loc_0x420
	  mr        r6, r26
	  b         .loc_0x424

	.loc_0x420:
	  mr        r6, r25

	.loc_0x424:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x46C
	  lfs       f1, -0x4944(r2)
	  rlwinm.   r0,r3,0,24,31
	  stfs      f1, 0x34(r1)
	  beq-      .loc_0x444
	  lfs       f1, -0x4948(r2)
	  b         .loc_0x464

	.loc_0x444:
	  xoris     r0, r8, 0x8000
	  lfd       f2, -0x4930(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x40(r1)
	  lfd       f1, 0x40(r1)
	  fsubs     f1, f1, f2
	  fdivs     f1, f1, f4

	.loc_0x464:
	  stfs      f1, 0x2C(r1)
	  b         .loc_0x4E0

	.loc_0x46C:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x4A8
	  xoris     r0, r8, 0x8000
	  lfs       f3, -0x4948(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfd       f2, -0x4930(r2)
	  stw       r0, 0x40(r1)
	  lfd       f1, 0x40(r1)
	  stfs      f3, 0x2C(r1)
	  fsubs     f1, f1, f2
	  fdivs     f1, f1, f4
	  fsubs     f1, f3, f1
	  stfs      f1, 0x34(r1)
	  b         .loc_0x4E0

	.loc_0x4A8:
	  xoris     r0, r8, 0x8000
	  lfd       f2, -0x4930(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x4940(r2)
	  stw       r0, 0x40(r1)
	  lfd       f1, 0x40(r1)
	  fsubs     f1, f1, f2
	  fdivs     f1, f1, f4
	  fmuls     f1, f1, f3
	  fsubs     f2, f3, f1
	  fadds     f1, f3, f1
	  stfs      f2, 0x34(r1)
	  stfs      f1, 0x2C(r1)

	.loc_0x4E0:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x528
	  lfs       f1, -0x4944(r2)
	  rlwinm.   r0,r5,0,24,31
	  stfs      f1, 0x30(r1)
	  beq-      .loc_0x500
	  lfs       f0, -0x4948(r2)
	  b         .loc_0x520

	.loc_0x500:
	  xoris     r0, r6, 0x8000
	  lfd       f2, -0x4930(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x40(r1)
	  lfd       f1, 0x40(r1)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0

	.loc_0x520:
	  stfs      f0, 0x28(r1)
	  b         .loc_0x59C

	.loc_0x528:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x564
	  xoris     r0, r6, 0x8000
	  lfs       f3, -0x4948(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfd       f2, -0x4930(r2)
	  stw       r0, 0x40(r1)
	  lfd       f1, 0x40(r1)
	  stfs      f3, 0x28(r1)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  fsubs     f0, f3, f0
	  stfs      f0, 0x30(r1)
	  b         .loc_0x59C

	.loc_0x564:
	  xoris     r0, r6, 0x8000
	  lfd       f2, -0x4930(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x4940(r2)
	  stw       r0, 0x40(r1)
	  lfd       f1, 0x40(r1)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  fmuls     f0, f0, f3
	  fsubs     f1, f3, f0
	  fadds     f0, f3, f0
	  stfs      f1, 0x30(r1)
	  stfs      f0, 0x28(r1)

	.loc_0x59C:
	  rlwinm.   r0,r27,0,30,30
	  beq-      .loc_0x5B4
	  addi      r3, r22, 0
	  addi      r4, r1, 0x34
	  addi      r5, r1, 0x2C
	  bl        0x798

	.loc_0x5B4:
	  rlwinm.   r0,r27,0,31,31
	  beq-      .loc_0x5CC
	  addi      r3, r22, 0
	  addi      r4, r1, 0x30
	  addi      r5, r1, 0x28
	  bl        0x780

	.loc_0x5CC:
	  rlwinm.   r0,r28,0,24,31
	  bne-      .loc_0x614
	  lfs       f6, 0x28(r1)
	  mr        r3, r22
	  lfs       f3, 0x2C(r1)
	  mr        r6, r25
	  lfs       f2, 0x30(r1)
	  lfs       f1, 0x34(r1)
	  fmr       f7, f3
	  fmr       f4, f2
	  mr        r7, r26
	  fmr       f5, f1
	  fmr       f8, f6
	  mr        r8, r29
	  sub       r4, r31, r23
	  sub       r5, r30, r24
	  bl        .loc_0x664
	  b         .loc_0x650

	.loc_0x614:
	  lfs       f5, 0x2C(r1)
	  mr        r3, r22
	  lfs       f4, 0x30(r1)
	  mr        r6, r25
	  lfs       f2, 0x28(r1)
	  lfs       f1, 0x34(r1)
	  fmr       f7, f5
	  fmr       f6, f2
	  mr        r7, r26
	  fmr       f3, f1
	  fmr       f8, f4
	  mr        r8, r29
	  sub       r4, r31, r23
	  sub       r5, r30, r24
	  bl        .loc_0x664

	.loc_0x650:
	  lmw       r22, 0x50(r1)
	  lwz       r0, 0x7C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr

	.loc_0x664:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00040C
 */
void P2DPicture::draw(int, int, int, int, bool, bool, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002F4
 */
void P2DPicture::drawOut(const PUTRect&, const PUTRect&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B2458
 * Size:	000234
 */
void P2DPicture::drawTexCoord(int, int, int, int, f32, f32, f32, f32, f32, f32, f32, f32, Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  fmr       f31, f8
	  stfd      f30, 0xD8(r1)
	  fmr       f30, f7
	  stfd      f29, 0xD0(r1)
	  fmr       f29, f6
	  stfd      f28, 0xC8(r1)
	  fmr       f28, f5
	  stfd      f27, 0xC0(r1)
	  fmr       f27, f4
	  stfd      f26, 0xB8(r1)
	  fmr       f26, f3
	  stfd      f25, 0xB0(r1)
	  fmr       f25, f2
	  stfd      f24, 0xA8(r1)
	  fmr       f24, f1
	  stmw      r23, 0x84(r1)
	  mr        r23, r3
	  mr        r24, r4
	  mr        r25, r5
	  mr        r26, r6
	  mr        r27, r7
	  addi      r28, r8, 0
	  li        r29, 0
	  b         .loc_0xAC

	.loc_0x70:
	  rlwinm    r31,r29,0,24,31
	  cmplw     r31, r0
	  bge-      .loc_0xA8
	  rlwinm    r3,r31,2,0,29
	  addi      r0, r3, 0xEC
	  lwzx      r30, r23, r0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x24(r30)
	  mr        r4, r31
	  bl        0x60268

	.loc_0xA8:
	  addi      r29, r29, 0x1

	.loc_0xAC:
	  lbz       r0, 0xF1(r23)
	  cmpw      r29, r0
	  blt+      .loc_0x70
	  add       r29, r24, r26
	  add       r30, r25, r27
	  bl        0x5D6E4
	  li        r3, 0x9
	  li        r4, 0x1
	  bl        0x5CEDC
	  li        r3, 0xB
	  li        r4, 0x1
	  bl        0x5CED0
	  li        r3, 0xD
	  li        r4, 0x1
	  bl        0x5CEC4
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x3
	  li        r7, 0
	  bl        0x5D6F4
	  li        r3, 0
	  li        r4, 0xB
	  li        r5, 0x1
	  li        r6, 0x5
	  li        r7, 0
	  bl        0x5D6DC
	  li        r3, 0
	  li        r4, 0xD
	  li        r5, 0x1
	  li        r6, 0x4
	  li        r7, 0
	  bl        0x5D6C4
	  lbz       r3, 0xF1(r23)
	  bl        0x5E19C
	  addi      r3, r28, 0
	  addi      r4, r23, 0x78
	  addi      r5, r1, 0x40
	  bl        -0x1744C8
	  addi      r3, r1, 0x40
	  li        r4, 0
	  bl        0x61EAC
	  mr        r3, r23
	  bl        .loc_0x234
	  li        r3, 0x80
	  li        r4, 0
	  li        r5, 0x4
	  bl        0x5E614
	  extsh     r31, r24
	  lis       r12, 0xCC01
	  sth       r31, -0x8000(r12)
	  extsh     r11, r25
	  li        r10, 0
	  sth       r11, -0x8000(r12)
	  li        r9, -0x1
	  extsh     r8, r29
	  sth       r10, -0x8000(r12)
	  extsh     r0, r30
	  li        r3, 0
	  stw       r9, -0x8000(r12)
	  li        r4, 0xD
	  li        r5, 0x1
	  stfs      f24, -0x8000(r12)
	  li        r6, 0x2
	  li        r7, 0xF
	  stfs      f25, -0x8000(r12)
	  sth       r8, -0x8000(r12)
	  sth       r11, -0x8000(r12)
	  sth       r10, -0x8000(r12)
	  stw       r9, -0x8000(r12)
	  stfs      f26, -0x8000(r12)
	  stfs      f27, -0x8000(r12)
	  sth       r8, -0x8000(r12)
	  sth       r0, -0x8000(r12)
	  sth       r10, -0x8000(r12)
	  stw       r9, -0x8000(r12)
	  stfs      f30, -0x8000(r12)
	  stfs      f31, -0x8000(r12)
	  sth       r31, -0x8000(r12)
	  sth       r0, -0x8000(r12)
	  sth       r10, -0x8000(r12)
	  stw       r9, -0x8000(r12)
	  stfs      f28, -0x8000(r12)
	  stfs      f29, -0x8000(r12)
	  bl        0x5D5F4
	  lmw       r23, 0x84(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lfd       f29, 0xD0(r1)
	  lfd       f28, 0xC8(r1)
	  lfd       f27, 0xC0(r1)
	  lfd       f26, 0xB8(r1)
	  lfd       f25, 0xB0(r1)
	  lfd       f24, 0xA8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr

	.loc_0x234:
	*/
}

/*
 * --INFO--
 * Address:	801B268C
 * Size:	0004B0
 */
void P2DPicture::setTevMode()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  stw       r28, 0x38(r1)
	  li        r28, 0
	  b         .loc_0x48

	.loc_0x28:
	  addi      r3, r28, 0
	  li        r4, 0x1
	  li        r5, 0x4
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x5DD8C
	  addi      r28, r28, 0x1

	.loc_0x48:
	  lbz       r0, 0xF1(r31)
	  cmpw      r28, r0
	  blt+      .loc_0x28
	  li        r3, 0x1
	  bl        0x5F7F0
	  li        r3, 0x4
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  li        r9, 0x2
	  bl        0x5F81C
	  lwz       r0, -0x4928(r2)
	  addi      r4, r1, 0x2C
	  li        r3, 0x4
	  stw       r0, 0x28(r1)
	  lbz       r0, 0xF0(r31)
	  stb       r0, 0x2B(r1)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  bl        0x5F644
	  li        r28, 0
	  b         .loc_0xC0

	.loc_0xA8:
	  addi      r3, r28, 0
	  addi      r4, r28, 0
	  addi      r5, r28, 0
	  li        r6, 0xFF
	  bl        0x61080
	  addi      r28, r28, 0x1

	.loc_0xC0:
	  lbz       r0, 0xF1(r31)
	  cmpw      r28, r0
	  blt+      .loc_0xA8
	  cmplwi    r0, 0x1
	  bne-      .loc_0x184
	  lbz       r0, 0xF0(r31)
	  cmplwi    r0, 0xFF
	  bne-      .loc_0x184
	  lbz       r3, 0x10C(r31)
	  lbz       r0, 0x10D(r31)
	  rlwinm    r3,r3,24,0,7
	  lbz       r4, 0x10E(r31)
	  rlwimi    r3,r0,16,8,15
	  lbz       r5, 0x10F(r31)
	  rlwimi    r3,r4,8,16,23
	  or.       r0, r5, r3
	  bne-      .loc_0x10C
	  li        r0, 0x1
	  b         .loc_0x110

	.loc_0x10C:
	  li        r0, 0

	.loc_0x110:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x184
	  lbz       r3, 0x108(r31)
	  lbz       r0, 0x109(r31)
	  rlwinm    r3,r3,24,0,7
	  lbz       r4, 0x10A(r31)
	  rlwimi    r3,r0,16,8,15
	  lbz       r5, 0x10B(r31)
	  rlwimi    r3,r4,8,16,23
	  or        r3, r5, r3
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x14C
	  li        r0, 0x1
	  b         .loc_0x150

	.loc_0x14C:
	  li        r0, 0

	.loc_0x150:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x184
	  li        r3, 0x1
	  bl        0x6117C
	  li        r3, 0
	  li        r4, 0x3
	  bl        0x607A8
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0xF
	  bl        0x61444
	  b         .loc_0x490

	.loc_0x184:
	  lwz       r0, -0x4924(r2)
	  addi      r4, r1, 0x24
	  li        r3, 0x3
	  stw       r0, 0x20(r1)
	  lwz       r0, 0x20(r1)
	  stw       r0, 0x24(r1)
	  bl        0x60B9C
	  li        r3, 0
	  li        r4, 0x8
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0xF
	  bl        0x60900
	  li        r3, 0
	  li        r4, 0x4
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x7
	  bl        0x60968
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x609D0
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x60A74
	  li        r0, -0x1
	  stw       r0, 0x30(r1)
	  addi      r4, r1, 0x1C
	  li        r3, 0
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x1C(r1)
	  bl        0x60C00
	  li        r30, 0x1
	  rlwinm    r29,r30,2,0,29
	  b         .loc_0x2BC

	.loc_0x230:
	  subfic    r28, r29, 0x20
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        0x60C58
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        0x60CB8
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0xE
	  li        r7, 0xF
	  bl        0x60854
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0x4
	  li        r6, 0x6
	  li        r7, 0x7
	  bl        0x608BC
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x60924
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x609C8
	  addi      r29, r29, 0x4
	  addi      r30, r30, 0x1

	.loc_0x2BC:
	  lbz       r0, 0xF1(r31)
	  cmpw      r30, r0
	  blt+      .loc_0x230
	  lbz       r3, 0x10C(r31)
	  lbz       r0, 0x10D(r31)
	  rlwinm    r3,r3,24,0,7
	  lbz       r4, 0x10E(r31)
	  rlwimi    r3,r0,16,8,15
	  lbz       r5, 0x10F(r31)
	  rlwimi    r3,r4,8,16,23
	  or.       r0, r5, r3
	  bne-      .loc_0x2F4
	  li        r0, 0x1
	  b         .loc_0x2F8

	.loc_0x2F4:
	  li        r0, 0

	.loc_0x2F8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x340
	  lbz       r3, 0x108(r31)
	  lbz       r0, 0x109(r31)
	  rlwinm    r3,r3,24,0,7
	  lbz       r4, 0x10A(r31)
	  rlwimi    r3,r0,16,8,15
	  lbz       r5, 0x10B(r31)
	  rlwimi    r3,r4,8,16,23
	  or        r3, r5, r3
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x334
	  li        r0, 0x1
	  b         .loc_0x338

	.loc_0x334:
	  li        r0, 0

	.loc_0x338:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x3E8

	.loc_0x340:
	  addi      r3, r30, 0
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x60DE8
	  lwz       r0, 0x10C(r31)
	  addi      r4, r1, 0x18
	  li        r3, 0x1
	  stw       r0, 0x18(r1)
	  bl        0x609D4
	  lwz       r0, 0x108(r31)
	  addi      r4, r1, 0x14
	  li        r3, 0x2
	  stw       r0, 0x14(r1)
	  bl        0x609C0
	  addi      r3, r30, 0
	  li        r4, 0x2
	  li        r5, 0x4
	  li        r6, 0
	  li        r7, 0xF
	  bl        0x60724
	  addi      r3, r30, 0
	  li        r4, 0x1
	  li        r5, 0x2
	  li        r6, 0
	  li        r7, 0x7
	  bl        0x6078C
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x607F4
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x60898
	  addi      r30, r30, 0x1

	.loc_0x3E8:
	  lbz       r0, 0xF0(r31)
	  cmplwi    r0, 0xFF
	  beq-      .loc_0x474
	  addi      r3, r30, 0
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0x4
	  bl        0x60D34
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0xF
	  bl        0x60698
	  addi      r3, r30, 0
	  li        r4, 0x7
	  li        r5, 0
	  li        r6, 0x5
	  li        r7, 0x7
	  bl        0x60700
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x60768
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x6080C
	  addi      r30, r30, 0x1

	.loc_0x474:
	  rlwinm    r3,r30,0,24,31
	  bl        0x60E60
	  li        r3, 0x1
	  li        r4, 0x4
	  li        r5, 0x5
	  li        r6, 0xF
	  bl        0x61134

	.loc_0x490:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B2B3C
 * Size:	000014
 */
void P2DPicture::swap(f32&, f32&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x0(r5)
	  stfs      f0, 0x0(r4)
	  stfs      f1, 0x0(r5)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00017C
 */
void P2DPicture::drawTest()
{
	// UNUSED FUNCTION
}
