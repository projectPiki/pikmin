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
 * Address:	801A2754
 * Size:	0000F8
 */
YTeki::YTeki()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  extsh.    r0, r4
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x30
	  addi      r0, r31, 0x538
	  lis       r3, 0x802B
	  stw       r0, 0x2C0(r31)
	  subi      r0, r3, 0x246C
	  stw       r0, 0x538(r31)

	.loc_0x30:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x56D94
	  lis       r3, 0x802E
	  subi      r4, r3, 0x261C
	  stw       r4, 0x0(r31)
	  lis       r3, 0x802E
	  addi      r0, r4, 0x1F4
	  lwz       r6, 0x2C0(r31)
	  addi      r5, r4, 0x114
	  addi      r4, r31, 0x538
	  stw       r0, 0x0(r6)
	  subi      r0, r3, 0x23C4
	  addi      r3, r31, 0x4CC
	  stw       r5, 0x2B8(r31)
	  lwz       r5, 0x2C0(r31)
	  sub       r4, r4, r5
	  stw       r4, 0x4(r5)
	  lfs       f0, -0x4BD0(r2)
	  stfs      f0, 0x4E4(r31)
	  stfs      f0, 0x4E0(r31)
	  stfs      f0, 0x4DC(r31)
	  stfs      f0, 0x4F0(r31)
	  stfs      f0, 0x4EC(r31)
	  stfs      f0, 0x4E8(r31)
	  stfs      f0, 0x4FC(r31)
	  stfs      f0, 0x4F8(r31)
	  stfs      f0, 0x4F4(r31)
	  stw       r0, 0x514(r31)
	  bl        .loc_0xF8
	  lis       r3, 0x802B
	  addi      r5, r3, 0x600
	  lis       r3, 0x802E
	  stw       r5, 0x51C(r31)
	  addi      r0, r3, 0x17E8
	  stw       r0, 0x51C(r31)
	  lis       r4, 0x802E
	  lis       r3, 0x802E
	  stw       r5, 0x528(r31)
	  addi      r4, r4, 0x1818
	  addi      r0, r3, 0x1844
	  stw       r4, 0x528(r31)
	  mr        r3, r31
	  stw       r5, 0x530(r31)
	  stw       r0, 0x530(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0xF8:
	*/
}

/*
 * --INFO--
 * Address:	801A284C
 * Size:	000084
 */
void TAIeffectAttackParam::init()
{
	/*
	.loc_0x0:
	  li        r4, 0
	  stw       r4, 0x38(r3)
	  addi      r0, r3, 0x48
	  lfs       f1, -0x4BD0(r2)
	  stfs      f1, 0x0(r3)
	  stfs      f1, 0x4(r3)
	  stfs      f1, 0xC(r3)
	  lfs       f0, 0x1168(r13)
	  stfs      f0, 0x10(r3)
	  lfs       f0, 0x116C(r13)
	  stfs      f0, 0x14(r3)
	  lfs       f0, 0x1170(r13)
	  stfs      f0, 0x18(r3)
	  lfs       f0, 0x1174(r13)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, 0x1178(r13)
	  stfs      f0, 0x20(r3)
	  lfs       f0, 0x117C(r13)
	  stfs      f0, 0x24(r3)
	  lfs       f0, 0x1180(r13)
	  stfs      f0, 0x28(r3)
	  lfs       f0, 0x1184(r13)
	  stfs      f0, 0x2C(r3)
	  lfs       f0, 0x1188(r13)
	  stfs      f0, 0x30(r3)
	  stfs      f1, 0x34(r3)
	  stw       r4, 0x40(r3)
	  stw       r4, 0x3C(r3)
	  stw       r0, 0x44(r3)
	  stb       r4, 0x4C(r3)
	  lfs       f0, -0x4BCC(r2)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A28D0
 * Size:	000120
 */
void YTeki::doKill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x5D1AC
	  lwz       r4, 0x498(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x30
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0x30:
	  addi      r3, r31, 0x4
	  lwz       r4, 0x49C(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x4C
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0x4C:
	  lwz       r4, 0x49C(r3)
	  addi      r3, r3, 0x4
	  cmplwi    r4, 0
	  beq-      .loc_0x68
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0x68:
	  lwz       r4, 0x49C(r3)
	  addi      r3, r3, 0x4
	  cmplwi    r4, 0
	  beq-      .loc_0x84
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0x84:
	  lwz       r4, 0x49C(r3)
	  addi      r3, r3, 0x4
	  cmplwi    r4, 0
	  beq-      .loc_0xA0
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0xA0:
	  lwz       r4, 0x49C(r3)
	  addi      r3, r3, 0x4
	  cmplwi    r4, 0
	  beq-      .loc_0xBC
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0xBC:
	  lwz       r4, 0x49C(r3)
	  addi      r3, r3, 0x4
	  cmplwi    r4, 0
	  beq-      .loc_0xD8
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0xD8:
	  lwz       r4, 0x49C(r3)
	  addi      r3, r3, 0x4
	  cmplwi    r4, 0
	  beq-      .loc_0xF4
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0xF4:
	  lwz       r4, 0x49C(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x10C
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0x10C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A29F0
 * Size:	000058
 */
void YTeki::exitCourse()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  stw       r30, 0x10(r1)
	  bl        -0x5D180
	  li        r30, 0

	.loc_0x20:
	  lwz       r3, 0x498(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  bl        -0x1E20

	.loc_0x30:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x9
	  addi      r31, r31, 0x4
	  blt+      .loc_0x20
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A2A48
 * Size:	000080
 */
void YTeki::isNaviWatch()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  li        r31, 0
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  lwz       r3, 0x3120(r13)
	  bl        -0x8B6A4
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  lfs       f4, 0x8(r3)
	  bl        -0x16A454
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x18(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x64
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x64
	  li        r31, 0x1

	.loc_0x64:
	  mr        r3, r31
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void YTeki::getMapAttribute()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A2AC8
 * Size:	000034
 */
void YTeki::moveTowardPriorityFaceDir(Vector3f&, float)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x2C4(r3)
	  lwz       r5, 0x84(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f2, 0x14(r5)
	  bl        .loc_0x34
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x34:
	*/
}

/*
 * --INFO--
 * Address:	801A2AFC
 * Size:	000150
 */
void YTeki::moveTowardPriorityFaceDir(Vector3f&, float, float)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stfd      f30, 0x50(r1)
	  fmr       f30, f1
	  stfd      f29, 0x48(r1)
	  stfd      f28, 0x40(r1)
	  fmr       f28, f2
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lfs       f5, 0x0(r4)
	  lfs       f4, 0x94(r3)
	  lfs       f3, 0x8(r4)
	  lfs       f0, 0x9C(r31)
	  fsubs     f1, f5, f4
	  lfs       f31, 0xA8(r31)
	  fsubs     f2, f3, f0
	  bl        -0x84D3C
	  stfs      f1, 0x394(r31)
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xA0(r31)
	  bl        -0x16A5A0
	  fmr       f29, f1
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0xA0(r31)
	  lfs       f0, 0x28C(r3)
	  fmuls     f1, f29, f28
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xA0(r31)
	  lfs       f1, 0xA0(r31)
	  bl        -0x16A5F4
	  stfs      f1, 0xA0(r31)
	  lfs       f0, 0x118C(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, 0x1190(r13)
	  stfs      f0, 0x90(r31)
	  lfs       f0, -0x4BD0(r2)
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0xB4
	  fneg      f1, f29
	  b         .loc_0xB8

	.loc_0xB4:
	  fmr       f1, f29

	.loc_0xB8:
	  lfs       f0, -0x4BC4(r2)
	  lfs       f2, -0x4BC8(r2)
	  fdivs     f1, f1, f0
	  lfs       f0, -0x4BC0(r2)
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bgt-      .loc_0xDC
	  fsubs     f0, f0, f1
	  fmuls     f30, f30, f0

	.loc_0xDC:
	  lfs       f1, 0xA0(r31)
	  bl        0x78F78
	  lfs       f0, 0xA0(r31)
	  fmr       f29, f1
	  fmr       f1, f0
	  bl        0x790FC
	  stfs      f1, 0xA4(r31)
	  lfs       f0, 0x1194(r13)
	  stfs      f0, 0xA8(r31)
	  stfs      f29, 0xAC(r31)
	  lfs       f0, 0xA4(r31)
	  fmuls     f0, f0, f30
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f0, f0, f30
	  stfs      f0, 0xA8(r31)
	  lfs       f0, 0xAC(r31)
	  fmuls     f0, f0, f30
	  stfs      f0, 0xAC(r31)
	  stfs      f31, 0xA8(r31)
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lfd       f30, 0x50(r1)
	  lfd       f29, 0x48(r1)
	  lfd       f28, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A2C4C
 * Size:	0000FC
 */
void YTeki::turnToTarget()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  lwz       r4, 0x418(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0xE0
	  lfsu      f3, 0x94(r4)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x8(r4)
	  lfs       f0, 0x9C(r31)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        -0x84E80
	  stfs      f1, 0x394(r31)
	  lfs       f1, 0x394(r31)
	  lfs       f2, 0xA0(r31)
	  bl        -0x16A6E4
	  lwz       r4, 0x224(r31)
	  fmr       f31, f1
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x30(r4)
	  lfs       f0, 0x28C(r3)
	  fmuls     f1, f31, f1
	  lfs       f2, -0x4BBC(r2)
	  lfs       f3, 0xA0(r31)
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0xA0(r31)
	  lfs       f1, 0xA0(r31)
	  bl        -0x16A748
	  stfs      f1, 0xA0(r31)
	  lfs       f0, 0x1198(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, 0x119C(r13)
	  stfs      f0, 0x90(r31)
	  lwz       r3, 0x2C4(r31)
	  lfs       f2, -0x4BC4(r2)
	  lwz       r3, 0x84(r3)
	  lfs       f0, -0x4BB8(r2)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0x24(r3)
	  fmuls     f1, f2, f1
	  fdivs     f0, f1, f0
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0xD8
	  li        r3, 0x1
	  b         .loc_0xE4

	.loc_0xD8:
	  li        r3, 0
	  b         .loc_0xE4

	.loc_0xE0:
	  li        r3, 0x1

	.loc_0xE4:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A2D48
 * Size:	000114
 */
void YTeki::flyingStay(float)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  fmr       f31, f1
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  bl        -0x5A3D0
	  lwz       r3, 0x2C4(r31)
	  lfs       f2, -0x4BB4(r2)
	  lwz       r3, 0x84(r3)
	  fmuls     f3, f2, f31
	  lfs       f0, -0x4BD0(r2)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f2, 0x74(r3)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x54
	  fneg      f0, f1
	  b         .loc_0x58

	.loc_0x54:
	  fmr       f0, f1

	.loc_0x58:
	  fcmpo     cr0, f0, f3
	  ble-      .loc_0x7C
	  lfs       f0, -0x4BD0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x74
	  lfs       f0, -0x4BC0(r2)
	  b         .loc_0x78

	.loc_0x74:
	  lfs       f0, -0x4BB0(r2)

	.loc_0x78:
	  fmuls     f1, f3, f0

	.loc_0x7C:
	  lfs       f0, -0x4BAC(r2)
	  lwz       r3, 0x2DEC(r13)
	  fmuls     f0, f0, f1
	  lfs       f1, 0xA8(r31)
	  lfs       f2, 0x28C(r3)
	  fmuls     f0, f0, f2
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r31)
	  lfs       f1, 0xA8(r31)
	  lfs       f0, -0x4BD0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB8
	  fneg      f0, f1
	  b         .loc_0xBC

	.loc_0xB8:
	  fmr       f0, f1

	.loc_0xBC:
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0xE4
	  lfs       f0, -0x4BD0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xD8
	  lfs       f0, -0x4BC0(r2)
	  b         .loc_0xDC

	.loc_0xD8:
	  lfs       f0, -0x4BB0(r2)

	.loc_0xDC:
	  fmuls     f0, f31, f0
	  stfs      f0, 0xA8(r31)

	.loc_0xE4:
	  lwz       r3, 0xA4(r31)
	  lwz       r0, 0xA8(r31)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0xAC(r31)
	  stw       r0, 0x78(r31)
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A2E5C
 * Size:	0001A4
 */
void YTeki::killStickToMouthPiki()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r25, 0x44(r1)
	  addi      r28, r3, 0
	  addi      r4, r28, 0
	  addi      r3, r1, 0x30
	  bl        -0x1121F4
	  addi      r30, r1, 0x30
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802B
	  addi      r29, r3, 0
	  subi      r26, r5, 0x3064
	  subi      r27, r4, 0x328C
	  addi      r31, r1, 0x18
	  b         .loc_0x134

	.loc_0x54:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x7C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3
	  b         .loc_0x98

	.loc_0x7C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3

	.loc_0x98:
	  cmplwi    r25, 0
	  addi      r3, r25, 0
	  beq-      .loc_0x118
	  lwz       r0, 0xC8(r25)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x118
	  stw       r26, 0x18(r1)
	  li        r0, 0
	  mr        r4, r31
	  stw       r28, 0x1C(r1)
	  stw       r27, 0x18(r1)
	  stw       r0, 0x20(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  addi      r25, r25, 0x94
	  lwz       r3, 0x3180(r13)
	  addi      r5, r25, 0
	  li        r4, 0x2F
	  li        r6, 0
	  li        r7, 0
	  bl        -0x6414
	  lwz       r3, 0x3180(r13)
	  addi      r5, r25, 0
	  li        r4, 0x30
	  li        r6, 0
	  li        r7, 0
	  bl        -0x642C
	  cmpwi     r29, 0
	  blt-      .loc_0x118
	  subi      r29, r29, 0x1

	.loc_0x118:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x134:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x15C
	  li        r0, 0x1
	  b         .loc_0x188

	.loc_0x15C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x184
	  li        r0, 0x1
	  b         .loc_0x188

	.loc_0x184:
	  li        r0, 0

	.loc_0x188:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x54
	  lmw       r25, 0x44(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A3000
 * Size:	0000C8
 */
void YTeki::startNewMotion(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  lwz       r3, 0x2CC(r3)
	  lwz       r0, 0x44(r3)
	  cmpw      r31, r0
	  bne-      .loc_0x38
	  lbz       r0, 0x48(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xAC

	.loc_0x38:
	  lbz       r0, 0x48(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x6C
	  cmplwi    r30, 0
	  addi      r5, r30, 0
	  beq-      .loc_0x54
	  lwz       r5, 0x2C0(r30)

	.loc_0x54:
	  addi      r3, r1, 0x2C
	  li        r4, -0x1
	  bl        -0x840D0
	  mr        r4, r3
	  lwz       r3, 0x2CC(r30)
	  bl        -0x83E38

	.loc_0x6C:
	  lwz       r3, 0x2CC(r30)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0xA4
	  cmplwi    r30, 0
	  addi      r5, r30, 0
	  beq-      .loc_0x8C
	  lwz       r5, 0x2C0(r30)

	.loc_0x8C:
	  addi      r4, r31, 0
	  addi      r3, r1, 0x24
	  bl        -0x84108
	  mr        r4, r3
	  lwz       r3, 0x2CC(r30)
	  bl        -0x83EE0

	.loc_0xA4:
	  li        r3, 0
	  b         .loc_0xB0

	.loc_0xAC:
	  li        r3, 0x1

	.loc_0xB0:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A30C8
 * Size:	000008
 */
u32 TAIeffectAttackEventCallBack::hitCreature(zen::particleGenerator*, TAIeffectAttackParam*, Creature*, Vector3f) { return 0x0; }

/*
 * --INFO--
 * Address:	801A30D0
 * Size:	000008
 */
u32 TAIeffectAttackEventCallBack::hitCreature(TAIeffectAttackParam*, Creature*, Vector3f) { return 0x0; }

/*
 * --INFO--
 * Address:	801A30D8
 * Size:	000008
 */
u32 TAIeffectAttackEventCallBack::hitCreature(TAIeffectAttackParam*, Creature*) { return 0x0; }

/*
 * --INFO--
 * Address:	801A30E0
 * Size:	000008
 */
u32 TAIeffectAttackEventCallBack::hitMap(TAIeffectAttackParam*) { return 0x0; }

/*
 * --INFO--
 * Address:	801A30E8
 * Size:	000004
 */
void TAIeffectAttackEventCallBack::playEventSound(zen::particleGenerator*, TAIeffectAttackParam*) { }

/*
 * --INFO--
 * Address:	801A30EC
 * Size:	000004
 */
void TAIeffectAttackEventCallBack::ptclHitMap(zen::particleGenerator*, TAIeffectAttackParam*) { }

/*
 * --INFO--
 * Address:	801A30F0
 * Size:	000008
 */
u32 TAIeffectAttackEventCallBack::hitCheckCulling(zen::particleGenerator*, TAIeffectAttackParam*, Creature*) { return 0x1; }
