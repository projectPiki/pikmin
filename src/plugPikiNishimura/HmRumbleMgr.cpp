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
 * Size:	00000C
 */
ChannelDataMgr::ChannelDataMgr()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void ChannelDataMgr::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void ChannelDataMgr::getChannelDataTbl(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017C868
 * Size:	000028
 */
ChannelMgr::ChannelMgr()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x5120(r2)
	  li        r4, -0x1
	  li        r0, 0
	  stfs      f0, 0x0(r3)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x511C(r2)
	  stfs      f0, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void ChannelMgr::init(ChannelDataMgr*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void ChannelMgr::reset()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017C890
 * Size:	000060
 */
void ChannelMgr::start(int, float*)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x5120(r2)
	  mulli     r7, r4, 0xC
	  stfs      f1, 0x0(r3)
	  lis       r6, 0x802D
	  addi      r0, r6, 0x2378
	  add       r0, r0, r7
	  stw       r0, 0x10(r3)
	  cmplwi    r5, 0
	  stw       r4, 0xC(r3)
	  beq-      .loc_0x54
	  lfs       f2, 0x0(r5)
	  lfs       f0, -0x5118(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x4C
	  fdivs     f0, f2, f0
	  lfs       f1, -0x511C(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x8(r3)
	  blr

	.loc_0x4C:
	  stfs      f1, 0x8(r3)
	  blr

	.loc_0x54:
	  lfs       f0, -0x511C(r2)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017C8F0
 * Size:	0000FC
 */
void ChannelMgr::update()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x5120(r2)
	  stfs      f0, 0x4(r3)
	  lwz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xE4
	  lwz       r4, 0x2DEC(r13)
	  li        r8, 0
	  lfs       f1, 0x0(r3)
	  li        r5, 0
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r3)
	  lfs       f3, -0x511C(r2)
	  b         .loc_0x8C

	.loc_0x38:
	  lwz       r0, 0x4(r6)
	  lfs       f2, 0x0(r3)
	  add       r4, r0, r5
	  lfs       f1, 0x0(r4)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x84
	  lfs       f0, 0x4(r4)
	  fsubs     f2, f2, f1
	  lwz       r0, 0x8(r6)
	  fsubs     f0, f0, f1
	  add       r4, r0, r5
	  lfs       f1, 0x0(r4)
	  fdivs     f4, f2, f0
	  lfs       f0, 0x4(r4)
	  fsubs     f2, f3, f4
	  fmuls     f0, f4, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r3)

	.loc_0x84:
	  addi      r5, r5, 0x4
	  addi      r8, r8, 0x1

	.loc_0x8C:
	  lwz       r6, 0x10(r3)
	  lwz       r4, 0x0(r6)
	  lwz       r7, 0x0(r4)
	  subi      r0, r7, 0x1
	  cmpw      r8, r0
	  blt+      .loc_0x38
	  lwz       r4, 0x4(r6)
	  rlwinm    r0,r7,2,0,29
	  lfs       f1, 0x0(r3)
	  add       r4, r4, r0
	  lfs       f0, -0x4(r4)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xE4
	  lfs       f0, -0x5120(r2)
	  li        r4, -0x1
	  li        r0, 0
	  stfs      f0, 0x0(r3)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x511C(r2)
	  stfs      f0, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0xE4:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x4(r3)
	  lfs       f1, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
ControlerMgr::ControlerMgr()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000188
 */
void ControlerMgr::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
void ControlerMgr::reset()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017C9EC
 * Size:	00009C
 */
void ControlerMgr::start(int, float*)
{
	/*
	.loc_0x0:
	  li        r0, 0x20
	  mtctr     r0
	  li        r8, 0
	  li        r6, 0

	.loc_0x10:
	  lwz       r7, 0x4(r3)
	  addi      r0, r6, 0x10
	  lwzx      r0, r7, r0
	  cmplwi    r0, 0
	  bne-      .loc_0x8C
	  mulli     r0, r8, 0x18
	  lfs       f1, -0x5120(r2)
	  add       r7, r7, r0
	  lis       r3, 0x802D
	  stfs      f1, 0x0(r7)
	  mulli     r6, r4, 0xC
	  addi      r0, r3, 0x2378
	  add       r0, r0, r6
	  stw       r0, 0x10(r7)
	  cmplwi    r5, 0
	  stw       r4, 0xC(r7)
	  beq-      .loc_0x80
	  lfs       f2, 0x0(r5)
	  lfs       f0, -0x5118(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x78
	  fdivs     f0, f2, f0
	  lfs       f1, -0x511C(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x8(r7)
	  blr

	.loc_0x78:
	  stfs      f1, 0x8(r7)
	  blr

	.loc_0x80:
	  lfs       f0, -0x511C(r2)
	  stfs      f0, 0x8(r7)
	  blr

	.loc_0x8C:
	  addi      r6, r6, 0x18
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A4
 */
void ControlerMgr::stop()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void ControlerMgr::stop(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void ControlerMgr::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017CA88
 * Size:	000120
 */
RumbleMgr::RumbleMgr(bool, bool, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  stmw      r26, 0x18(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x8018
	  addi      r28, r31, 0
	  addi      r27, r1, 0x10
	  subi      r30, r3, 0x3798
	  li        r26, 0
	  lfs       f0, -0x5120(r2)
	  stfs      f0, 0x0(r31)
	  fmr       f31, f0
	  stfs      f0, 0x4(r31)
	  stb       r4, 0x10(r1)
	  stb       r5, 0x11(r1)
	  stb       r6, 0x12(r1)
	  stb       r7, 0x13(r1)

	.loc_0x4C:
	  li        r0, 0
	  stw       r0, 0x1C(r28)
	  stw       r0, 0xC(r28)
	  lbz       r0, 0x0(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0xC0
	  li        r3, 0xC
	  bl        -0x135AEC
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x9C
	  stfs      f31, 0x0(r29)
	  li        r3, 0x308
	  bl        -0x135B04
	  addi      r4, r30, 0
	  li        r5, 0
	  li        r6, 0x18
	  li        r7, 0x20
	  bl        0x9810C
	  stw       r3, 0x4(r29)

	.loc_0x9C:
	  stw       r29, 0x1C(r28)
	  li        r3, 0xC
	  bl        -0x135B28
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xBC
	  mr        r4, r26
	  bl        0xB40

	.loc_0xBC:
	  stw       r29, 0xC(r28)

	.loc_0xC0:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x4
	  addi      r28, r28, 0x4
	  addi      r27, r27, 0x1
	  blt+      .loc_0x4C
	  li        r30, 0
	  stw       r30, 0x2C(r31)
	  li        r3, 0x4
	  bl        -0x135B64
	  cmplwi    r3, 0
	  beq-      .loc_0xF0
	  stw       r30, 0x0(r3)

	.loc_0xF0:
	  stw       r3, 0x2C(r31)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x8(r31)
	  mr        r3, r31
	  stb       r0, 0x9(r31)
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lmw       r26, 0x18(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001F8
 */
void RumbleMgr::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017CBA8
 * Size:	0001A0
 */
void RumbleMgr::reset()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stfd      f30, 0x38(r1)
	  stmw      r27, 0x24(r1)
	  addi      r30, r3, 0
	  addi      r29, r30, 0
	  li        r31, 0
	  lfs       f30, -0x5120(r2)
	  stfs      f30, 0x0(r3)
	  stfs      f30, 0x4(r3)
	  lfs       f31, -0x511C(r2)

	.loc_0x34:
	  lwz       r7, 0x1C(r29)
	  cmplwi    r7, 0
	  beq-      .loc_0x15C
	  li        r0, 0x4
	  stfs      f30, 0x0(r7)
	  mtctr     r0
	  li        r6, 0

	.loc_0x50:
	  lwz       r0, 0x4(r7)
	  li        r4, -0x1
	  li        r3, 0
	  add       r5, r0, r6
	  stfs      f30, 0x0(r5)
	  addi      r27, r6, 0x18
	  addi      r28, r6, 0x30
	  stfs      f30, 0x4(r5)
	  addi      r12, r6, 0x48
	  addi      r11, r6, 0x60
	  stfs      f31, 0x8(r5)
	  addi      r10, r6, 0x78
	  addi      r9, r6, 0x90
	  stw       r4, 0xC(r5)
	  addi      r8, r6, 0xA8
	  addi      r6, r6, 0xC0
	  stw       r3, 0x10(r5)
	  lwz       r0, 0x4(r7)
	  add       r27, r0, r27
	  stfs      f30, 0x0(r27)
	  stfs      f30, 0x4(r27)
	  stfs      f31, 0x8(r27)
	  stw       r4, 0xC(r27)
	  stw       r3, 0x10(r27)
	  lwz       r0, 0x4(r7)
	  add       r28, r0, r28
	  stfs      f30, 0x0(r28)
	  stfs      f30, 0x4(r28)
	  stfs      f31, 0x8(r28)
	  stw       r4, 0xC(r28)
	  stw       r3, 0x10(r28)
	  lwz       r0, 0x4(r7)
	  add       r12, r0, r12
	  stfs      f30, 0x0(r12)
	  stfs      f30, 0x4(r12)
	  stfs      f31, 0x8(r12)
	  stw       r4, 0xC(r12)
	  stw       r3, 0x10(r12)
	  lwz       r0, 0x4(r7)
	  add       r11, r0, r11
	  stfs      f30, 0x0(r11)
	  stfs      f30, 0x4(r11)
	  stfs      f31, 0x8(r11)
	  stw       r4, 0xC(r11)
	  stw       r3, 0x10(r11)
	  lwz       r0, 0x4(r7)
	  add       r10, r0, r10
	  stfs      f30, 0x0(r10)
	  stfs      f30, 0x4(r10)
	  stfs      f31, 0x8(r10)
	  stw       r4, 0xC(r10)
	  stw       r3, 0x10(r10)
	  lwz       r0, 0x4(r7)
	  add       r9, r0, r9
	  stfs      f30, 0x0(r9)
	  stfs      f30, 0x4(r9)
	  stfs      f31, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r3, 0x10(r9)
	  lwz       r0, 0x4(r7)
	  add       r8, r0, r8
	  stfs      f30, 0x0(r8)
	  stfs      f30, 0x4(r8)
	  stfs      f31, 0x8(r8)
	  stw       r4, 0xC(r8)
	  stw       r3, 0x10(r8)
	  bdnz+     .loc_0x50

	.loc_0x15C:
	  lwz       r3, 0xC(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x16C
	  bl        0x984

	.loc_0x16C:
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x4
	  addi      r29, r29, 0x4
	  blt+      .loc_0x34
	  li        r0, 0
	  stb       r0, 0x9(r30)
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lfd       f30, 0x38(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017CD48
 * Size:	00008C
 */
void RumbleMgr::start(int, int, float*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x9(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x7C
	  lbz       r0, 0x8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x7C
	  rlwinm    r0,r5,2,0,29
	  add       r3, r3, r0
	  lwz       r7, 0x1C(r3)
	  cmplwi    r7, 0
	  beq-      .loc_0x7C
	  li        r0, 0x20
	  li        r3, 0
	  mtctr     r0
	  addi      r5, r3, 0

	.loc_0x48:
	  lwz       r8, 0x4(r7)
	  addi      r0, r5, 0x10
	  lwzx      r0, r8, r0
	  cmplwi    r0, 0
	  bne-      .loc_0x70
	  mulli     r0, r3, 0x18
	  addi      r5, r6, 0
	  add       r3, r8, r0
	  bl        -0x520
	  b         .loc_0x7C

	.loc_0x70:
	  addi      r5, r5, 0x18
	  addi      r3, r3, 0x1
	  bdnz+     .loc_0x48

	.loc_0x7C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017CDD4
 * Size:	000120
 */
void RumbleMgr::start(int, int, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  addi      r30, r6, 0
	  stw       r29, 0x4C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x48(r1)
	  mr        r28, r3
	  lbz       r0, 0x9(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x100
	  lbz       r0, 0x8(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x100
	  rlwinm    r0,r5,2,0,29
	  add       r31, r28, r0
	  lwzu      r0, 0x1C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x100
	  lwz       r3, 0x3120(r13)
	  mr        r4, r5
	  bl        -0x659F8
	  lfs       f0, -0x5120(r2)
	  stfs      f0, 0x40(r1)
	  stfs      f0, 0x3C(r1)
	  stfs      f0, 0x38(r1)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x0(r30)
	  lfs       f4, 0x8(r30)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x4(r30)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x30(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x30(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f1, 0x3C(r1)
	  stfs      f3, 0x40(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  lfs       f2, 0x40(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x16F25C
	  stfs      f1, 0x44(r1)
	  lbz       r0, 0x9(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x100
	  lbz       r0, 0x8(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x100
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x100
	  addi      r4, r29, 0
	  addi      r5, r1, 0x44
	  bl        -0x4E4

	.loc_0x100:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  lwz       r28, 0x48(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017CEF4
 * Size:	0001C4
 */
void RumbleMgr::stop()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x5120(r2)
	  li        r10, 0
	  lfs       f0, -0x511C(r2)

	.loc_0xC:
	  lwz       r8, 0x1C(r3)
	  cmplwi    r8, 0
	  beq-      .loc_0x1B0
	  li        r0, 0x4
	  li        r6, 0
	  mtctr     r0
	  addi      r7, r6, 0
	  addi      r0, r6, 0
	  li        r4, -0x1

	.loc_0x30:
	  lwz       r5, 0x4(r8)
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0x58
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0x58:
	  lwz       r5, 0x4(r8)
	  addi      r7, r7, 0x18
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0x84
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0x84:
	  lwz       r5, 0x4(r8)
	  addi      r7, r7, 0x18
	  addi      r6, r6, 0x1
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0xB4
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0xB4:
	  lwz       r5, 0x4(r8)
	  addi      r7, r7, 0x18
	  addi      r6, r6, 0x1
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0xE4
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0xE4:
	  lwz       r5, 0x4(r8)
	  addi      r7, r7, 0x18
	  addi      r6, r6, 0x1
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0x114
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0x114:
	  lwz       r5, 0x4(r8)
	  addi      r7, r7, 0x18
	  addi      r6, r6, 0x1
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0x144
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0x144:
	  lwz       r5, 0x4(r8)
	  addi      r7, r7, 0x18
	  addi      r6, r6, 0x1
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0x174
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0x174:
	  lwz       r5, 0x4(r8)
	  addi      r7, r7, 0x18
	  addi      r6, r6, 0x1
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0x1A4
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0x1A4:
	  addi      r7, r7, 0x18
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x30

	.loc_0x1B0:
	  addi      r10, r10, 0x1
	  cmpwi     r10, 0x4
	  addi      r3, r3, 0x4
	  blt+      .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017D0B8
 * Size:	000140
 */
void RumbleMgr::stop(int, int)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x9(r3)
	  cmplwi    r0, 0
	  bnelr-
	  lbz       r0, 0x8(r3)
	  cmplwi    r0, 0
	  beqlr-
	  rlwinm    r0,r5,2,0,29
	  add       r3, r3, r0
	  lwz       r8, 0x1C(r3)
	  cmplwi    r8, 0
	  beqlr-
	  li        r0, 0x8
	  lfs       f1, -0x5120(r2)
	  li        r6, 0
	  mtctr     r0
	  lfs       f0, -0x511C(r2)
	  addi      r7, r6, 0
	  addi      r0, r6, 0
	  li        r3, -0x1

	.loc_0x4C:
	  lwz       r5, 0x4(r8)
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0x80
	  lwz       r5, 0xC(r9)
	  cmpw      r4, r5
	  bne-      .loc_0x80
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r3, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0x80:
	  lwz       r5, 0x4(r8)
	  addi      r7, r7, 0x18
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0xB8
	  lwz       r5, 0xC(r9)
	  cmpw      r4, r5
	  bne-      .loc_0xB8
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r3, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0xB8:
	  lwz       r5, 0x4(r8)
	  addi      r7, r7, 0x18
	  addi      r6, r6, 0x1
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0xF4
	  lwz       r5, 0xC(r9)
	  cmpw      r4, r5
	  bne-      .loc_0xF4
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r3, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0xF4:
	  lwz       r5, 0x4(r8)
	  addi      r7, r7, 0x18
	  addi      r6, r6, 0x1
	  add       r9, r5, r7
	  lwz       r5, 0x10(r9)
	  cmplwi    r5, 0
	  beq-      .loc_0x130
	  lwz       r5, 0xC(r9)
	  cmpw      r4, r5
	  bne-      .loc_0x130
	  stfs      f1, 0x0(r9)
	  stfs      f1, 0x4(r9)
	  stfs      f0, 0x8(r9)
	  stw       r3, 0xC(r9)
	  stw       r0, 0x10(r9)

	.loc_0x130:
	  addi      r7, r7, 0x18
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x4C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017D1F8
 * Size:	00016C
 */
void RumbleMgr::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stfd      f30, 0x48(r1)
	  stfd      f29, 0x40(r1)
	  stfd      f28, 0x38(r1)
	  stmw      r26, 0x20(r1)
	  mr        r26, r3
	  lbz       r0, 0x9(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x148
	  lbz       r0, 0x8(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x148
	  lfs       f29, -0x511C(r2)
	  mr        r29, r26
	  lfs       f30, -0x5120(r2)
	  li        r27, 0
	  lfs       f31, -0x5114(r2)

	.loc_0x50:
	  lwz       r28, 0x1C(r29)
	  cmplwi    r28, 0
	  beq-      .loc_0x118
	  li        r31, 0
	  lfs       f28, -0x5120(r2)
	  mulli     r30, r31, 0x18

	.loc_0x68:
	  lwz       r0, 0x4(r28)
	  add       r3, r0, r30
	  bl        -0x978
	  stfs      f1, 0x0(r28)
	  lfs       f0, 0x0(r28)
	  fcmpo     cr0, f0, f28
	  ble-      .loc_0x88
	  fmr       f28, f0

	.loc_0x88:
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x20
	  addi      r30, r30, 0x18
	  blt+      .loc_0x68
	  stfs      f28, 0x0(r28)
	  lfs       f0, 0x0(r28)
	  fcmpo     cr0, f0, f29
	  ble-      .loc_0xB0
	  stfs      f29, 0x0(r28)
	  b         .loc_0xBC

	.loc_0xB0:
	  fcmpo     cr0, f0, f30
	  bge-      .loc_0xBC
	  stfs      f30, 0x0(r28)

	.loc_0xBC:
	  lfs       f0, 0x0(r28)
	  stfs      f0, 0x0(r26)
	  lfs       f0, 0x4(r26)
	  fcmpo     cr0, f0, f30
	  ble-      .loc_0xEC
	  fdivs     f0, f0, f31
	  lfs       f2, 0x0(r26)
	  fsubs     f1, f29, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f29, f0
	  fmuls     f0, f2, f0
	  stfs      f0, 0x0(r26)

	.loc_0xEC:
	  lfs       f0, 0x0(r26)
	  fcmpo     cr0, f0, f29
	  ble-      .loc_0x100
	  stfs      f29, 0x0(r26)
	  b         .loc_0x10C

	.loc_0x100:
	  fcmpo     cr0, f0, f30
	  bge-      .loc_0x10C
	  stfs      f30, 0x0(r26)

	.loc_0x10C:
	  lwz       r3, 0xC(r29)
	  lfs       f1, 0x0(r26)
	  bl        0x3B0

	.loc_0x118:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x4
	  addi      r29, r29, 0x4
	  blt+      .loc_0x50
	  lfs       f1, 0x4(r26)
	  lfs       f0, -0x5120(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x148
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4(r26)

	.loc_0x148:
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lfd       f30, 0x48(r1)
	  lfd       f29, 0x40(r1)
	  lfd       f28, 0x38(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017D364
 * Size:	00031C
 */
void RumbleMgr::rumbleOption(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stfd      f30, 0x48(r1)
	  stmw      r27, 0x34(r1)
	  mr        r31, r3
	  stb       r4, 0x8(r3)
	  lbz       r0, 0x8(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x198
	  lfs       f31, -0x5120(r2)
	  addi      r29, r31, 0
	  li        r30, 0
	  stfs      f31, 0x0(r31)
	  stfs      f31, 0x4(r31)
	  lfs       f30, -0x511C(r2)

	.loc_0x44:
	  lwz       r7, 0x1C(r29)
	  cmplwi    r7, 0
	  beq-      .loc_0x16C
	  li        r0, 0x4
	  stfs      f31, 0x0(r7)
	  mtctr     r0
	  li        r6, 0

	.loc_0x60:
	  lwz       r0, 0x4(r7)
	  li        r4, -0x1
	  li        r3, 0
	  add       r5, r0, r6
	  stfs      f31, 0x0(r5)
	  addi      r27, r6, 0x18
	  addi      r28, r6, 0x30
	  stfs      f31, 0x4(r5)
	  addi      r12, r6, 0x48
	  addi      r11, r6, 0x60
	  stfs      f30, 0x8(r5)
	  addi      r10, r6, 0x78
	  addi      r9, r6, 0x90
	  stw       r4, 0xC(r5)
	  addi      r8, r6, 0xA8
	  addi      r6, r6, 0xC0
	  stw       r3, 0x10(r5)
	  lwz       r0, 0x4(r7)
	  add       r27, r0, r27
	  stfs      f31, 0x0(r27)
	  stfs      f31, 0x4(r27)
	  stfs      f30, 0x8(r27)
	  stw       r4, 0xC(r27)
	  stw       r3, 0x10(r27)
	  lwz       r0, 0x4(r7)
	  add       r28, r0, r28
	  stfs      f31, 0x0(r28)
	  stfs      f31, 0x4(r28)
	  stfs      f30, 0x8(r28)
	  stw       r4, 0xC(r28)
	  stw       r3, 0x10(r28)
	  lwz       r0, 0x4(r7)
	  add       r12, r0, r12
	  stfs      f31, 0x0(r12)
	  stfs      f31, 0x4(r12)
	  stfs      f30, 0x8(r12)
	  stw       r4, 0xC(r12)
	  stw       r3, 0x10(r12)
	  lwz       r0, 0x4(r7)
	  add       r11, r0, r11
	  stfs      f31, 0x0(r11)
	  stfs      f31, 0x4(r11)
	  stfs      f30, 0x8(r11)
	  stw       r4, 0xC(r11)
	  stw       r3, 0x10(r11)
	  lwz       r0, 0x4(r7)
	  add       r10, r0, r10
	  stfs      f31, 0x0(r10)
	  stfs      f31, 0x4(r10)
	  stfs      f30, 0x8(r10)
	  stw       r4, 0xC(r10)
	  stw       r3, 0x10(r10)
	  lwz       r0, 0x4(r7)
	  add       r9, r0, r9
	  stfs      f31, 0x0(r9)
	  stfs      f31, 0x4(r9)
	  stfs      f30, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r3, 0x10(r9)
	  lwz       r0, 0x4(r7)
	  add       r8, r0, r8
	  stfs      f31, 0x0(r8)
	  stfs      f31, 0x4(r8)
	  stfs      f30, 0x8(r8)
	  stw       r4, 0xC(r8)
	  stw       r3, 0x10(r8)
	  bdnz+     .loc_0x60

	.loc_0x16C:
	  lwz       r3, 0xC(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x17C
	  bl        0x1B8

	.loc_0x17C:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x4
	  addi      r29, r29, 0x4
	  blt+      .loc_0x44
	  li        r0, 0
	  stb       r0, 0x9(r31)
	  b         .loc_0x300

	.loc_0x198:
	  lfs       f30, -0x5120(r2)
	  addi      r29, r31, 0
	  li        r30, 0
	  stfs      f30, 0x0(r31)
	  stfs      f30, 0x4(r31)
	  lfs       f31, -0x511C(r2)

	.loc_0x1B0:
	  lwz       r7, 0x1C(r29)
	  cmplwi    r7, 0
	  beq-      .loc_0x2D8
	  li        r0, 0x4
	  stfs      f30, 0x0(r7)
	  mtctr     r0
	  li        r6, 0

	.loc_0x1CC:
	  lwz       r0, 0x4(r7)
	  li        r4, -0x1
	  li        r3, 0
	  add       r5, r0, r6
	  stfs      f30, 0x0(r5)
	  addi      r28, r6, 0x18
	  addi      r27, r6, 0x30
	  stfs      f30, 0x4(r5)
	  addi      r12, r6, 0x48
	  addi      r11, r6, 0x60
	  stfs      f31, 0x8(r5)
	  addi      r10, r6, 0x78
	  addi      r9, r6, 0x90
	  stw       r4, 0xC(r5)
	  addi      r8, r6, 0xA8
	  addi      r6, r6, 0xC0
	  stw       r3, 0x10(r5)
	  lwz       r0, 0x4(r7)
	  add       r28, r0, r28
	  stfs      f30, 0x0(r28)
	  stfs      f30, 0x4(r28)
	  stfs      f31, 0x8(r28)
	  stw       r4, 0xC(r28)
	  stw       r3, 0x10(r28)
	  lwz       r0, 0x4(r7)
	  add       r27, r0, r27
	  stfs      f30, 0x0(r27)
	  stfs      f30, 0x4(r27)
	  stfs      f31, 0x8(r27)
	  stw       r4, 0xC(r27)
	  stw       r3, 0x10(r27)
	  lwz       r0, 0x4(r7)
	  add       r12, r0, r12
	  stfs      f30, 0x0(r12)
	  stfs      f30, 0x4(r12)
	  stfs      f31, 0x8(r12)
	  stw       r4, 0xC(r12)
	  stw       r3, 0x10(r12)
	  lwz       r0, 0x4(r7)
	  add       r11, r0, r11
	  stfs      f30, 0x0(r11)
	  stfs      f30, 0x4(r11)
	  stfs      f31, 0x8(r11)
	  stw       r4, 0xC(r11)
	  stw       r3, 0x10(r11)
	  lwz       r0, 0x4(r7)
	  add       r10, r0, r10
	  stfs      f30, 0x0(r10)
	  stfs      f30, 0x4(r10)
	  stfs      f31, 0x8(r10)
	  stw       r4, 0xC(r10)
	  stw       r3, 0x10(r10)
	  lwz       r0, 0x4(r7)
	  add       r9, r0, r9
	  stfs      f30, 0x0(r9)
	  stfs      f30, 0x4(r9)
	  stfs      f31, 0x8(r9)
	  stw       r4, 0xC(r9)
	  stw       r3, 0x10(r9)
	  lwz       r0, 0x4(r7)
	  add       r8, r0, r8
	  stfs      f30, 0x0(r8)
	  stfs      f30, 0x4(r8)
	  stfs      f31, 0x8(r8)
	  stw       r4, 0xC(r8)
	  stw       r3, 0x10(r8)
	  bdnz+     .loc_0x1CC

	.loc_0x2D8:
	  lwz       r3, 0xC(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x2E8
	  bl        0x4C

	.loc_0x2E8:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x4
	  addi      r29, r29, 0x4
	  blt+      .loc_0x1B0
	  li        r0, 0
	  stb       r0, 0x9(r31)

	.loc_0x300:
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lfd       f30, 0x48(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void RumbleMgr::rumblePause(bool)
{
	// UNUSED FUNCTION
}
