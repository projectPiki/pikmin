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
 * Size:	000034
 */
void PaniPikiAnimMgr::getMotionTable()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011F8A0
 * Size:	00003C
 */
PaniPikiAnimMgr::PaniPikiAnimMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x4
	  bl        -0x5EE4
	  addi      r3, r31, 0x58
	  bl        -0x5EEC
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
 * Address:	8011F8DC
 * Size:	00007C
 */
void PaniPikiAnimMgr::init(AnimMgr*, AnimContext*, AnimContext*, PaniMotionTable*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  lwz       r0, 0x3158(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x34
	  bl        -0x6C04
	  stw       r3, 0x3158(r13)

	.loc_0x34:
	  lwz       r31, 0x3158(r13)
	  addi      r4, r29, 0
	  addi      r5, r28, 0
	  addi      r6, r31, 0
	  addi      r3, r27, 0x4
	  bl        -0x800
	  addi      r4, r30, 0
	  addi      r5, r28, 0
	  addi      r6, r31, 0
	  addi      r3, r27, 0x58
	  bl        -0x814
	  lfs       f0, -0x5F80(r2)
	  stfs      f0, 0x0(r27)
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F958
 * Size:	000060
 */
void PaniPikiAnimMgr::changeContext(AnimContext*, AnimContext*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r5
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0x4
	  lwz       r12, 0x34(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x58
	  lwz       r12, 0x88(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011F9B8
 * Size:	000058
 */
void PaniPikiAnimMgr::startMotion(PaniMotionInfo*, PaniMotionInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0x2C
	  addi      r3, r30, 0x4
	  bl        -0x820

	.loc_0x2C:
	  cmplwi    r31, 0
	  beq-      .loc_0x40
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0x834

	.loc_0x40:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011FA10
 * Size:	000058
 */
void PaniPikiAnimMgr::finishMotion(PaniMotionInfo*, PaniMotionInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0x2C
	  addi      r3, r30, 0x4
	  bl        -0x808

	.loc_0x2C:
	  cmplwi    r31, 0
	  beq-      .loc_0x40
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0x81C

	.loc_0x40:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011FA68
 * Size:	000058
 */
void PaniPikiAnimMgr::startMotion(PaniMotionInfo&, PaniMotionInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  beq-      .loc_0x2C
	  addi      r3, r30, 0x4
	  bl        -0x8D0

	.loc_0x2C:
	  cmplwi    r31, 0
	  beq-      .loc_0x40
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0x8E4

	.loc_0x40:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011FAC0
 * Size:	000084
 */
void PaniPikiAnimMgr::finishMotion(PaniAnimKeyListener*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  li        r4, -0x1
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x10
	  bl        -0xB60
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, -0x1
	  bl        -0xB74
	  mr.       r4, r3
	  beq-      .loc_0x54
	  addi      r3, r29, 0x4
	  bl        -0x8E0

	.loc_0x54:
	  cmplwi    r31, 0
	  beq-      .loc_0x68
	  addi      r3, r29, 0x58
	  addi      r4, r31, 0
	  bl        -0x8F4

	.loc_0x68:
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
 * Address:	8011FB44
 * Size:	0000C0
 */
void PaniPikiAnimMgr::updateAnimation(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r3
	  lbz       r0, 0x4C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  lwz       r3, 0x2C(r31)
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x34(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x44
	  stfs      f0, 0x0(r31)
	  b         .loc_0x44

	.loc_0x40:
	  stfs      f1, 0x0(r31)

	.loc_0x44:
	  lwz       r4, 0x2C(r31)
	  lfs       f31, 0x0(r31)
	  lwz       r0, 0x24(r4)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x60
	  lfs       f0, 0x34(r4)
	  stfs      f0, 0x0(r31)

	.loc_0x60:
	  addi      r3, r31, 0x4
	  lfs       f1, 0x0(r31)
	  lwz       r12, 0x34(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x80(r31)
	  lwz       r0, 0x24(r4)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x90
	  lfs       f0, 0x34(r4)
	  stfs      f0, 0x0(r31)

	.loc_0x90:
	  addi      r3, r31, 0x58
	  fmr       f1, f31
	  lwz       r12, 0x88(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011FC04
 * Size:	000050
 */
void PaniPikiAnimMgr::updateContext()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x4
	  lwz       r12, 0x34(r31)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r31, 0x58
	  lwz       r12, 0x88(r31)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
