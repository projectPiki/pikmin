#include "TAI/MotionActions.h"

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
 * Address:	80134018
 * Size:	000038
 */
void TaiMotionAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r3, 0
	  stw       r0, 0x4(r1)
	  addi      r3, r4, 0
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x8(r5)
	  lwz       r12, 0x174(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134050
 * Size:	000020
 */
bool TaiMotionAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2CC(r4)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x18
	  li        r3, 0x1
	  blr

	.loc_0x18:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134070
 * Size:	0000FC
 */
void TaiContinuousMotionAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  lwz       r5, 0x2CC(r4)
	  mr        r4, r3
	  lwz       r0, 0x44(r5)
	  cmpwi     r0, 0
	  bge-      .loc_0x44
	  mr        r3, r31
	  lwz       r4, 0x8(r4)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x174(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE8

	.loc_0x44:
	  lwz       r4, 0x8(r4)
	  cmpw      r0, r4
	  bne-      .loc_0x98
	  lbz       r0, 0x48(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x74
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x174(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE8

	.loc_0x74:
	  lwz       r0, 0x38(r5)
	  cmpwi     r0, 0
	  bge-      .loc_0xE8
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x174(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE8

	.loc_0x98:
	  beq-      .loc_0xE8
	  lwz       r0, 0x38(r5)
	  cmpwi     r0, 0
	  bge-      .loc_0xC0
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x174(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE8

	.loc_0xC0:
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0xD0
	  lwz       r5, 0x2C0(r31)

	.loc_0xD0:
	  addi      r3, r1, 0x24
	  li        r4, -0x1
	  bl        -0x151BC
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x14F24

	.loc_0xE8:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013416C
 * Size:	000074
 */
bool TaiContinuousMotionAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x8(r3)
	  lwz       r3, 0x2CC(r4)
	  lwz       r0, 0x44(r3)
	  cmpw      r0, r5
	  beq-      .loc_0x4C
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x44
	  mr        r3, r4
	  lwz       r12, 0x0(r4)
	  mr        r4, r5
	  lwz       r12, 0x174(r12)
	  mtlr      r12
	  blrl

	.loc_0x44:
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x4C:
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x60
	  li        r3, 0x1
	  b         .loc_0x64

	.loc_0x60:
	  li        r3, 0

	.loc_0x64:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801341E0
 * Size:	000024
 */
void TaiContinuousMotionAction::motionStarted(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2CC(r4)
	  lwz       r0, 0x8(r3)
	  lwz       r3, 0x44(r4)
	  cmpw      r3, r0
	  bne-      .loc_0x1C
	  li        r3, 0x1
	  blr

	.loc_0x1C:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134204
 * Size:	00004C
 */
void TaiFinishMotionAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr.       r31, r4
	  addi      r5, r31, 0
	  beq-      .loc_0x20
	  lwz       r5, 0x2C0(r31)

	.loc_0x20:
	  addi      r3, r1, 0x10
	  li        r4, -0x1
	  bl        -0x152A0
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0x15008
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134250
 * Size:	000020
 */
bool TaiAnimationKeyAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x414(r4)
	  lwz       r0, 0x8(r3)
	  and.      r0, r4, r0
	  beq-      .loc_0x18
	  li        r3, 0x1
	  blr

	.loc_0x18:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134270
 * Size:	00000C
 */
void TaiCountLoopAction::start(Teki&)
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x3B0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013427C
 * Size:	00003C
 */
bool TaiCountLoopAction::act(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x414(r4)
	  lwz       r0, -0x98C(r13)
	  and.      r0, r5, r0
	  beq-      .loc_0x34
	  lwz       r5, 0x3B0(r4)
	  addi      r0, r5, 0x1
	  stw       r0, 0x3B0(r4)
	  lwz       r4, 0x3B0(r4)
	  lwz       r0, 0x8(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x34
	  li        r3, 0x1
	  blr

	.loc_0x34:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801342B8
 * Size:	00005C
 */
void TaiSwitchMotionAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  addi      r4, r3, 0
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r5, 0x2CC(r31)
	  lwz       r12, 0x174(r12)
	  lwz       r4, 0x8(r4)
	  lfs       f31, 0x2C(r5)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2CC(r31)
	  stfs      f31, 0x2C(r3)
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134314
 * Size:	0000D4
 */
bool TaiOutsideKeyStopMoveAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  lwz       r5, 0x2CC(r4)
	  lwz       r4, 0x8(r3)
	  lfs       f30, 0x2C(r5)
	  mr        r3, r5
	  bl        -0x14B54
	  fmr       f31, f1
	  lwz       r3, 0x2CC(r31)
	  lwz       r4, 0xC(r30)
	  bl        -0x14B64
	  fcmpo     cr0, f31, f30
	  cror      2, 0, 0x2
	  bne-      .loc_0x60
	  fcmpo     cr0, f30, f1
	  cror      2, 0, 0x2
	  beq-      .loc_0xB0

	.loc_0x60:
	  addi      r3, r1, 0x20
	  subi      r4, r13, 0x122C
	  subi      r5, r13, 0x1228
	  subi      r6, r13, 0x1224
	  bl        -0xFD268
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0x20
	  addi      r5, r1, 0x24
	  addi      r6, r1, 0x28
	  bl        -0xD6D0C
	  addi      r3, r1, 0x14
	  subi      r4, r13, 0x1238
	  subi      r5, r13, 0x1234
	  subi      r6, r13, 0x1230
	  bl        -0xFD290
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x14
	  addi      r5, r1, 0x18
	  addi      r6, r1, 0x1C
	  bl        -0xD6D34

	.loc_0xB0:
	  lwz       r0, 0x54(r1)
	  li        r3, 0
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801343E8
 * Size:	000004
 */
void TaiStoppingMoveAction::start(Teki&) { }

/*
 * --INFO--
 * Address:	801343EC
 * Size:	000064
 */
bool TaiStoppingMoveAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x2CC(r4)
	  lwz       r0, 0x8(r3)
	  lwz       r3, 0x44(r5)
	  cmpw      r3, r0
	  bne-      .loc_0x50
	  lwz       r3, 0x414(r4)
	  lwz       r0, -0x98C(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x3C
	  mr        r3, r4
	  bl        0x10C54
	  b         .loc_0x50

	.loc_0x3C:
	  lwz       r0, 0x38(r5)
	  cmpwi     r0, 0
	  bge-      .loc_0x50
	  mr        r3, r4
	  bl        0x10CD4

	.loc_0x50:
	  li        r3, 0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134450
 * Size:	000004
 */
void TaiStoppingMoveAction::finish(Teki&) { }

/*
 * --INFO--
 * Address:	80134454
 * Size:	000024
 */
void TaiFinishStoppingMoveAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x10CA8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80134478
 * Size:	00003C
 */
void TaiSetFrameMotionAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r4, 0x8(r3)
	  lwz       r3, 0x2CC(r31)
	  bl        -0x14CA0
	  lwz       r3, 0x2CC(r31)
	  stfs      f1, 0x2C(r3)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801344B4
 * Size:	0000AC
 */
void TaiRandomSetAnimationCounterAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stfd      f30, 0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r3, 0
	  lwz       r4, 0x8(r3)
	  lwz       r3, 0x2CC(r31)
	  bl        -0x14CEC
	  fmr       f30, f1
	  lwz       r3, 0x2CC(r31)
	  lwz       r4, 0xC(r30)
	  bl        -0x14CFC
	  fmr       f31, f1
	  bl        0xE3B78
	  xoris     r0, r3, 0x8000
	  lfs       f1, -0x5BC0(r2)
	  stw       r0, 0x2C(r1)
	  lis       r0, 0x4330
	  fsubs     f0, f31, f1
	  lfd       f4, -0x5BB8(r2)
	  stw       r0, 0x28(r1)
	  lfs       f2, -0x5BBC(r2)
	  lfd       f3, 0x28(r1)
	  fsubs     f0, f0, f30
	  lwz       r3, 0x2CC(r31)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fadds     f0, f30, f0
	  stfs      f0, 0x2C(r3)
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lfd       f30, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}
