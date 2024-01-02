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
 * Address:	8011EF58
 * Size:	000034
 */
PaniMotionInfo::PaniMotionInfo(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0x4C
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
 * Address:	8011EF8C
 * Size:	000030
 */
PaniMotionInfo::PaniMotionInfo(int, PaniAnimKeyListener*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  bl        .loc_0x30
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0x30:
	*/
}

/*
 * --INFO--
 * Address:	8011EFBC
 * Size:	00000C
 */
void PaniMotionInfo::init(int, PaniAnimKeyListener*)
{
	/*
	.loc_0x0:
	  stw       r4, 0x0(r3)
	  stw       r5, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011EFC8
 * Size:	000034
 */
PaniMotion::PaniMotion(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        .loc_0x34
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x34:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
PaniMotion::PaniMotion(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011EFFC
 * Size:	00000C
 */
void PaniMotion::init(int, int)
{
	/*
	.loc_0x0:
	  stw       r4, 0x0(r3)
	  stw       r5, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F008
 * Size:	00006C
 */
PaniMotionTable::PaniMotionTable(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  stw       r4, 0x0(r3)
	  lwz       r0, 0x0(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xD8024
	  li        r5, 0
	  stw       r3, 0x4(r31)
	  addi      r4, r5, 0
	  li        r6, 0
	  b         .loc_0x48

	.loc_0x38:
	  lwz       r3, 0x4(r31)
	  addi      r6, r6, 0x1
	  stwx      r4, r3, r5
	  addi      r5, r5, 0x4

	.loc_0x48:
	  lwz       r0, 0x0(r31)
	  cmpw      r6, r0
	  blt+      .loc_0x38
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F074
 * Size:	00006C
 */
PaniSoundTable::PaniSoundTable(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  stw       r4, 0x0(r3)
	  lwz       r0, 0x0(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xD8090
	  li        r5, 0
	  stw       r3, 0x4(r31)
	  addi      r4, r5, 0
	  li        r6, 0
	  b         .loc_0x48

	.loc_0x38:
	  lwz       r3, 0x4(r31)
	  addi      r6, r6, 0x1
	  stwx      r4, r3, r5
	  addi      r5, r5, 0x4

	.loc_0x48:
	  lwz       r0, 0x0(r31)
	  cmpw      r6, r0
	  blt+      .loc_0x38
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F0E0
 * Size:	000044
 */
PaniAnimator::PaniAnimator()
{
	/*
	.loc_0x0:
	  lis       r4, 0x802A
	  addi      r0, r4, 0x5FFC
	  lis       r4, 0x802C
	  stw       r0, 0x30(r3)
	  addi      r0, r4, 0x4D34
	  stw       r0, 0x30(r3)
	  li        r4, -0x1
	  li        r0, 0
	  stw       r4, 0x38(r3)
	  stb       r0, 0x48(r3)
	  stw       r0, 0x34(r3)
	  stw       r0, 0x28(r3)
	  stw       r0, 0x50(r3)
	  stw       r4, 0x44(r3)
	  lfs       f0, -0x5F90(r2)
	  stfs      f0, 0x2C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F124
 * Size:	00006C
 */
void PaniAnimator::init(AnimContext*, AnimMgr*, PaniMotionTable*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  stw       r4, 0x4(r3)
	  stw       r5, 0x0(r3)
	  mr        r3, r5
	  stw       r0, 0x28(r31)
	  lfs       f0, -0x5F90(r2)
	  stfs      f0, 0x2C(r31)
	  stw       r6, 0x50(r31)
	  bl        -0xCE3E0
	  cmpwi     r3, 0
	  beq-      .loc_0x58
	  addi      r3, r31, 0
	  li        r4, 0x2
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x8
	  bl        -0xCE208

	.loc_0x58:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F190
 * Size:	000008
 */
void PaniAnimator::changeContext(AnimContext* a1)
{
	// Generated from stw r4, 0x4(r3)
	_04 = a1;
}

/*
 * --INFO--
 * Address:	8011F198
 * Size:	000028
 */
void PaniAnimator::updateContext()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x28(r3)
	  cmplwi    r4, 0
	  beqlr-
	  lwz       r0, 0x68(r4)
	  lwz       r4, 0x4(r3)
	  stw       r0, 0x0(r4)
	  lfs       f0, 0x2C(r3)
	  lwz       r3, 0x4(r3)
	  stfs      f0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F1C0
 * Size:	000070
 */
void PaniAnimator::startMotion(PaniMotionInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x28(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  lwz       r5, 0x0(r4)
	  li        r0, 0
	  li        r6, 0
	  stw       r5, 0x44(r3)
	  li        r7, 0x8
	  lwz       r5, 0x4(r4)
	  li        r4, 0x2
	  stw       r5, 0x34(r3)
	  stw       r0, 0x38(r3)
	  stw       r0, 0x40(r3)
	  stb       r0, 0x48(r3)
	  lwz       r5, 0x50(r3)
	  lwz       r0, 0x44(r3)
	  lwz       r5, 0x4(r5)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r5, r5, r0
	  lwz       r5, 0x0(r5)
	  bl        -0xCE2AC

	.loc_0x60:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F230
 * Size:	0000B0
 */
void PaniAnimator::finishMotion(PaniMotionInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  lwz       r0, 0x28(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xA0
	  lwz       r4, 0x4(r4)
	  li        r0, 0x1
	  stw       r4, 0x34(r3)
	  stb       r0, 0x48(r3)
	  lwz       r4, 0x28(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x3C
	  li        r0, -0x1
	  b         .loc_0x44

	.loc_0x3C:
	  lwz       r4, 0x68(r4)
	  lwz       r0, 0x30(r4)

	.loc_0x44:
	  xoris     r4, r0, 0x8000
	  lfd       f2, -0x5F88(r2)
	  stw       r4, 0x14(r1)
	  lis       r0, 0x4330
	  lfs       f1, 0x2C(r3)
	  stw       r0, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  stw       r4, 0x1C(r1)
	  fsubs     f0, f0, f2
	  stw       r0, 0x18(r1)
	  fcmpo     cr0, f1, f0
	  lfd       f0, 0x18(r1)
	  fsubs     f0, f0, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x8C
	  stfs      f0, 0x2C(r3)
	  bl        0x4EC
	  b         .loc_0xA0

	.loc_0x8C:
	  lwz       r5, 0x1C(r3)
	  li        r4, 0x2
	  li        r6, -0x1
	  li        r7, 0x8
	  bl        -0xCE35C

	.loc_0xA0:
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F2E0
 * Size:	00010C
 */
void PaniAnimator::animate(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stfd      f29, 0x38(r1)
	  fmr       f29, f1
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  mr        r30, r3
	  lwz       r3, 0x28(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  lfs       f0, -0x5F90(r2)
	  fcmpo     cr0, f29, f0
	  lwz       r0, 0x38(r30)
	  cmpwi     r0, 0
	  blt-      .loc_0xE8
	  lwz       r4, 0x20(r30)
	  bl        -0xCEE68
	  xoris     r0, r3, 0x8000
	  lfd       f1, -0x5F88(r2)
	  stw       r0, 0x2C(r1)
	  lis       r31, 0x4330
	  lwz       r3, 0x28(r30)
	  stw       r31, 0x28(r1)
	  lwz       r4, 0x24(r30)
	  lfd       f0, 0x28(r1)
	  fsubs     f31, f0, f1
	  bl        -0xCEE90
	  xoris     r0, r3, 0x8000
	  lfd       f1, -0x5F88(r2)
	  stw       r0, 0x24(r1)
	  stw       r31, 0x20(r1)
	  lfd       f0, 0x20(r1)
	  fsubs     f30, f0, f1
	  fcmpo     cr0, f31, f30
	  ble-      .loc_0x9C
	  b         .loc_0xE8

	.loc_0x9C:
	  lwz       r4, 0x3150(r13)
	  mr        r3, r30
	  lfs       f0, 0x2C(r30)
	  lfs       f1, 0x28C(r4)
	  fmuls     f29, f29, f1
	  fadds     f0, f0, f29
	  stfs      f0, 0x2C(r30)
	  bl        .loc_0x10C
	  lfs       f2, 0x2C(r30)
	  mr        r3, r30
	  fsubs     f1, f2, f29
	  bl        0x2D4
	  lfs       f0, 0x2C(r30)
	  fcmpo     cr0, f0, f30
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xE8
	  stfs      f30, 0x2C(r30)
	  mr        r3, r30
	  bl        0x3DC

	.loc_0xE8:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lfd       f29, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr

	.loc_0x10C:
	*/
}

/*
 * --INFO--
 * Address:	8011F3EC
 * Size:	0000D0
 */
void PaniAnimator::checkConstantKeys()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  mr        r30, r3
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x30
	  lwz       r3, 0x28(r30)
	  bl        -0xCF00C

	.loc_0x30:
	  lwz       r3, 0x28(r30)
	  bl        -0xCF014
	  cmpwi     r3, 0x10
	  ble-      .loc_0x48
	  lwz       r3, 0x28(r30)
	  bl        -0xCF024

	.loc_0x48:
	  lfd       f31, -0x5F88(r2)
	  lis       r31, 0x4330
	  b         .loc_0xA0

	.loc_0x54:
	  lwz       r3, 0x28(r30)
	  bl        -0xCEFF0
	  lwz       r4, 0x0(r3)
	  lwz       r3, 0x28(r30)
	  bl        -0xCEF8C
	  xoris     r0, r3, 0x8000
	  lfs       f0, 0x2C(r30)
	  stw       r0, 0x1C(r1)
	  stw       r31, 0x18(r1)
	  lfd       f1, 0x18(r1)
	  fsubs     f1, f1, f31
	  fcmpo     cr0, f0, f1
	  blt-      .loc_0xB4
	  mr        r3, r30
	  lwz       r4, 0x38(r30)
	  bl        .loc_0xD0
	  lwz       r3, 0x38(r30)
	  addi      r0, r3, 0x1
	  stw       r0, 0x38(r30)

	.loc_0xA0:
	  lwz       r3, 0x28(r30)
	  bl        -0xCF084
	  lwz       r4, 0x38(r30)
	  cmpw      r4, r3
	  blt+      .loc_0x54

	.loc_0xB4:
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0xD0:
	*/
}

/*
 * --INFO--
 * Address:	8011F4BC
 * Size:	0001C0
 */
void PaniAnimator::checkConstantKey(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  stw       r28, 0x48(r1)
	  addi      r28, r4, 0
	  lwz       r3, 0x28(r3)
	  bl        -0xCF094
	  lbz       r0, 0x48(r31)
	  lbz       r29, 0x6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xDC
	  cmpwi     r29, 0
	  bne-      .loc_0x50
	  stw       r28, 0x40(r31)
	  b         .loc_0xDC

	.loc_0x50:
	  cmpwi     r29, 0x1
	  bne-      .loc_0xDC
	  lwz       r4, 0x40(r31)
	  lwz       r3, 0x28(r31)
	  bl        -0xCF0C8
	  lwz       r30, 0x0(r3)
	  mr        r4, r28
	  lwz       r3, 0x28(r31)
	  bl        -0xCF0D8
	  lwz       r28, 0x0(r3)
	  mr        r4, r30
	  lwz       r3, 0x28(r31)
	  bl        -0xCF078
	  xoris     r0, r3, 0x8000
	  lfd       f1, -0x5F88(r2)
	  stw       r0, 0x44(r1)
	  lis       r30, 0x4330
	  lwz       r3, 0x28(r31)
	  mr        r4, r28
	  stw       r30, 0x40(r1)
	  lfd       f0, 0x40(r1)
	  fsubs     f31, f0, f1
	  bl        -0xCF0A0
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x5F88(r2)
	  stw       r0, 0x3C(r1)
	  lfs       f1, 0x2C(r31)
	  stw       r30, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  fsubs     f0, f0, f2
	  fsubs     f0, f0, f31
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2C(r31)
	  lwz       r0, 0x40(r31)
	  stw       r0, 0x38(r31)

	.loc_0xDC:
	  cmpwi     r29, 0
	  bne-      .loc_0x11C
	  lwz       r0, 0x34(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x158
	  li        r0, 0x5
	  stw       r0, 0x24(r1)
	  li        r0, -0x1
	  addi      r4, r1, 0x24
	  stw       r0, 0x28(r1)
	  lwz       r3, 0x34(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x158

	.loc_0x11C:
	  cmpwi     r29, 0x1
	  bne-      .loc_0x158
	  lwz       r0, 0x34(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x158
	  li        r0, 0x6
	  stw       r0, 0x1C(r1)
	  li        r0, -0x1
	  addi      r4, r1, 0x1C
	  stw       r0, 0x20(r1)
	  lwz       r3, 0x34(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x158:
	  cmpwi     r29, 0x2
	  blt-      .loc_0x19C
	  cmpwi     r29, 0x5
	  bgt-      .loc_0x19C
	  lwz       r0, 0x34(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x19C
	  subi      r0, r29, 0x1
	  stw       r0, 0x14(r1)
	  li        r0, -0x1
	  addi      r4, r1, 0x14
	  stw       r0, 0x18(r1)
	  lwz       r3, 0x34(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x19C:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  lwz       r28, 0x48(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F67C
 * Size:	000124
 */
void PaniAnimator::checkEventKeys(f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stfd      f30, 0x50(r1)
	  fmr       f30, f2
	  stfd      f29, 0x48(r1)
	  fmr       f29, f1
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  stw       r28, 0x38(r1)
	  mr        r28, r3
	  lwz       r0, 0x34(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xF8
	  lfd       f31, -0x5F88(r2)
	  addi      r30, r1, 0x18
	  li        r29, 0
	  lis       r31, 0x4330
	  b         .loc_0xE8

	.loc_0x54:
	  lwz       r3, 0x28(r28)
	  mr        r4, r29
	  bl        -0xCF24C
	  lwz       r0, 0x0(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x2C(r1)
	  stw       r31, 0x28(r1)
	  lfd       f0, 0x28(r1)
	  stw       r0, 0x34(r1)
	  fsubs     f0, f0, f31
	  stw       r31, 0x30(r1)
	  fcmpo     cr0, f29, f0
	  lfd       f0, 0x30(r1)
	  fsubs     f0, f0, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0xE4
	  fcmpo     cr0, f0, f30
	  bge-      .loc_0xE4
	  lha       r4, 0x4(r3)
	  li        r5, 0
	  extsh.    r0, r4
	  bne-      .loc_0xB4
	  li        r5, 0x7
	  b         .loc_0xC0

	.loc_0xB4:
	  cmpwi     r4, 0x1
	  bne-      .loc_0xC0
	  li        r5, 0x8

	.loc_0xC0:
	  lbz       r0, 0x6(r3)
	  mr        r4, r30
	  stw       r5, 0x18(r1)
	  stw       r0, 0x1C(r1)
	  lwz       r3, 0x34(r28)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xE4:
	  addi      r29, r29, 0x1

	.loc_0xE8:
	  lwz       r3, 0x28(r28)
	  bl        -0xCF338
	  cmpw      r29, r3
	  blt+      .loc_0x54

	.loc_0xF8:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lfd       f30, 0x50(r1)
	  lfd       f29, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F7A0
 * Size:	000054
 */
void PaniAnimator::finishAnimation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, -0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r5, 0x38(r3)
	  lwz       r0, 0x34(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x44
	  li        r0, 0
	  stw       r0, 0xC(r1)
	  addi      r4, r1, 0xC
	  stw       r5, 0x10(r1)
	  lwz       r3, 0x34(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x44:
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F7F4
 * Size:	0000AC
 */
void PaniAnimator::getKeyValueByKeyType(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  li        r31, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  b         .loc_0x7C

	.loc_0x28:
	  lwz       r3, 0x28(r29)
	  mr        r4, r31
	  bl        -0xCF3D0
	  lbz       r0, 0x6(r3)
	  cmpw      r30, r0
	  bne-      .loc_0x78
	  lwz       r3, 0x28(r29)
	  mr        r4, r31
	  bl        -0xCF3E8
	  lwz       r4, 0x0(r3)
	  lwz       r3, 0x28(r29)
	  bl        -0xCF384
	  xoris     r0, r3, 0x8000
	  lfd       f1, -0x5F88(r2)
	  stw       r0, 0x1C(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x18(r1)
	  lfd       f0, 0x18(r1)
	  fsubs     f1, f0, f1
	  b         .loc_0x90

	.loc_0x78:
	  addi      r31, r31, 0x1

	.loc_0x7C:
	  lwz       r3, 0x28(r29)
	  bl        -0xCF468
	  cmpw      r31, r3
	  blt+      .loc_0x28
	  lfs       f1, -0x5F90(r2)

	.loc_0x90:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void PaniAnimator::checkCounter_4DEBUG()
{
	// UNUSED FUNCTION
}
