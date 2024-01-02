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
PeveWaitEvent::PeveWaitEvent()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void PeveWaitEvent::makeWaitEvent(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80125F04
 * Size:	000040
 */
PeveAccelerationEvent::PeveAccelerationEvent()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0x9CC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x64CC
	  stw       r0, 0x0(r31)
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
 * Address:	80125F44
 * Size:	000014
 */
void PeveAccelerationEvent::makeAccelerationEvent(PeveCondition*, NVector3fIO*, NVector3fIO*, NVector3fIO*)
{
	/*
	.loc_0x0:
	  stw       r4, 0x8(r3)
	  stw       r5, 0x10(r3)
	  stw       r6, 0x14(r3)
	  stw       r7, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125F58
 * Size:	00017C
 */
void PeveAccelerationEvent::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  stw       r29, 0x5C(r1)
	  stw       r28, 0x58(r1)
	  mr        r28, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x3C:
	  addi      r3, r1, 0x30
	  bl        -0x9144
	  addi      r31, r3, 0
	  addi      r3, r1, 0x24
	  bl        -0x9150
	  addi      r30, r3, 0
	  addi      r3, r1, 0x18
	  bl        -0x915C
	  mr        r0, r3
	  lwz       r3, 0x10(r28)
	  mr        r29, r0
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x14(r28)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x18(r28)
	  mr        r4, r29
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3150(r13)
	  mr        r4, r31
	  lfs       f2, 0x0(r30)
	  lfs       f1, 0x28C(r3)
	  lfs       f3, 0x4(r30)
	  fmuls     f2, f2, f1
	  lfs       f0, 0x0(r31)
	  lfs       f4, 0x8(r30)
	  fmuls     f3, f3, f1
	  lfs       f5, 0x0(r29)
	  lfs       f6, 0x4(r29)
	  fadds     f0, f0, f2
	  lfs       f2, 0x8(r29)
	  fmuls     f4, f4, f1
	  fmuls     f5, f5, f1
	  stfs      f0, 0x0(r31)
	  fmuls     f6, f6, f1
	  lfs       f0, 0x4(r31)
	  fmuls     f2, f2, f1
	  fadds     f0, f0, f3
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x8(r31)
	  fadds     f0, f0, f4
	  stfs      f0, 0x8(r31)
	  lfs       f0, 0x0(r30)
	  fadds     f0, f0, f5
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f0, f6
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f0, f2
	  stfs      f0, 0x8(r30)
	  lwz       r3, 0x10(r28)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x14(r28)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  lwz       r28, 0x58(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801260D4
 * Size:	000074
 */
PeveParabolaEvent::PeveParabolaEvent()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0xB9C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x64CC
	  lis       r3, 0x802C
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x6490
	  lis       r3, 0x802C
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x5CEC
	  lis       r3, 0x802C
	  stw       r0, 0x1C(r31)
	  addi      r0, r3, 0x5BF0
	  stw       r0, 0x1C(r31)
	  addi      r3, r31, 0x20
	  bl        -0x92D0
	  addi      r3, r31, 0x2C
	  bl        -0x7BC
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
 * Address:	80126148
 * Size:	0000B0
 */
void PeveParabolaEvent::makeParabolaEvent(PeveCondition*, NVector3fIO*, NVector3f&, f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  fmr       f31, f2
	  stw       r31, 0x3C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x38(r1)
	  mr        r30, r4
	  addi      r4, r6, 0
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  stfs      f1, 0x3C(r3)
	  addi      r3, r29, 0x2C
	  lwz       r12, 0x2C(r29)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5DF4(r2)
	  fneg      f2, f31
	  addi      r3, r1, 0x20
	  fmr       f3, f1
	  bl        -0x92C4
	  lwz       r12, 0x1C(r29)
	  addi      r0, r3, 0
	  addi      r3, r29, 0x1C
	  lwz       r12, 0x8(r12)
	  mr        r4, r0
	  mtlr      r12
	  blrl
	  stw       r30, 0x8(r29)
	  addi      r3, r29, 0x2C
	  addi      r0, r29, 0x1C
	  stw       r31, 0x10(r29)
	  stw       r3, 0x14(r29)
	  stw       r0, 0x18(r29)
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801261F8
 * Size:	000034
 */
void PeveHorizontalSinWaveEvent::makeHorizontalSinWaveEvent(PeveCondition*, NVector3fIO*, NVector3f, f32, f32, f32, f32)
{
	/*
	.loc_0x0:
	  stw       r4, 0x8(r3)
	  stw       r5, 0x10(r3)
	  lfs       f0, 0x0(r6)
	  stfs      f0, 0x14(r3)
	  lfs       f0, 0x4(r6)
	  stfs      f0, 0x18(r3)
	  lfs       f0, 0x8(r6)
	  stfs      f0, 0x1C(r3)
	  stfs      f1, 0x20(r3)
	  stfs      f2, 0x24(r3)
	  stfs      f3, 0x28(r3)
	  stfs      f4, 0x2C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012622C
 * Size:	00004C
 */
void PeveHorizontalSinWaveEvent::reset()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x30:
	  lfs       f0, 0x28(r31)
	  stfs      f0, 0x30(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126278
 * Size:	000118
 */
void PeveHorizontalSinWaveEvent::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stfd      f30, 0x58(r1)
	  stfd      f29, 0x50(r1)
	  stfd      f28, 0x48(r1)
	  stfd      f27, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x44:
	  lwz       r3, 0x3150(r13)
	  lfs       f1, 0x30(r31)
	  lfs       f31, 0x28C(r3)
	  bl        0xF5A20
	  lfs       f0, 0x2C(r31)
	  addi      r3, r1, 0x1C
	  lfs       f3, 0x24(r31)
	  fmuls     f0, f31, f0
	  lfs       f2, 0x30(r31)
	  lfs       f4, 0x20(r31)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f27, f4, f1
	  stfs      f0, 0x30(r31)
	  lfs       f30, 0x14(r31)
	  lfs       f29, 0x18(r31)
	  lfs       f28, 0x1C(r31)
	  fmuls     f30, f30, f31
	  fmuls     f29, f29, f31
	  fmuls     f28, f28, f31
	  bl        -0x94B8
	  lwz       r3, 0x10(r31)
	  addi      r4, r1, 0x1C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x1C(r1)
	  addi      r4, r1, 0x1C
	  fadds     f0, f0, f30
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x20(r1)
	  fadds     f0, f0, f29
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x24(r1)
	  fadds     f0, f0, f28
	  stfs      f0, 0x24(r1)
	  stfs      f27, 0x20(r1)
	  lwz       r3, 0x10(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lfd       f30, 0x58(r1)
	  lfd       f29, 0x50(r1)
	  lfd       f28, 0x48(r1)
	  lfd       f27, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126390
 * Size:	00005C
 */
PeveCircleMoveEvent::PeveCircleMoveEvent()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0xE58
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6340
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0x14
	  bl        -0x754
	  addi      r3, r31, 0x14
	  lfs       f1, -0x5DF8(r2)
	  bl        -0x718
	  lfs       f0, -0x5DF4(r2)
	  mr        r3, r31
	  stfs      f0, 0x10(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801263EC
 * Size:	000028
 */
void PeveCircleMoveEvent::makeCircleMoveEvent(f32, NVector3fIO*, NVector3fIO*, f32, f32, f32, f32)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x1C(r3)
	  addi      r0, r3, 0x14
	  stw       r0, 0x8(r3)
	  stw       r4, 0x20(r3)
	  stw       r5, 0x24(r3)
	  stfs      f2, 0x28(r3)
	  stfs      f3, 0x2C(r3)
	  stfs      f4, 0x30(r3)
	  stfs      f5, 0x34(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126414
 * Size:	000050
 */
void PeveCircleMoveEvent::reset()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x30:
	  mr        r3, r31
	  bl        0x1FC
	  stfs      f1, 0x10(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126464
 * Size:	000134
 */
void PeveCircleMoveEvent::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x30:
	  lwz       r4, 0x3150(r13)
	  addi      r3, r1, 0x28
	  lfs       f1, 0x34(r31)
	  lfs       f0, 0x28C(r4)
	  lfs       f2, 0x10(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x10(r31)
	  bl        -0x9660
	  lwz       r3, 0x20(r31)
	  addi      r4, r1, 0x28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x1C
	  bl        -0x9680
	  addi      r3, r31, 0
	  addi      r4, r1, 0x1C
	  bl        .loc_0x134
	  lfs       f1, 0x1C(r1)
	  addi      r4, r1, 0x28
	  lfs       f0, 0x28(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x1C(r1)
	  lfs       f1, 0x20(r1)
	  lfs       f0, 0x2C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x20(r1)
	  lfs       f1, 0x24(r1)
	  lfs       f0, 0x30(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x24(r1)
	  lfs       f1, 0x28(r31)
	  lfs       f0, 0x1C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x20(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x24(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x24(r1)
	  lfs       f1, 0x28(r1)
	  lfs       f0, 0x1C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  lfs       f1, 0x2C(r1)
	  lfs       f0, 0x20(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2C(r1)
	  lfs       f1, 0x30(r1)
	  lfs       f0, 0x24(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x30(r1)
	  lwz       r3, 0x20(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr

	.loc_0x134:
	*/
}

/*
 * --INFO--
 * Address:	80126598
 * Size:	0000AC
 */
void PeveCircleMoveEvent::outputPosition(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stfd      f30, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x1C
	  bl        -0x976C
	  lwz       r3, 0x24(r30)
	  addi      r4, r1, 0x1C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x10(r30)
	  bl        0xF5574
	  lfs       f0, 0x2C(r30)
	  lfs       f4, 0x24(r1)
	  fmuls     f3, f0, f1
	  lfs       f2, 0x20(r1)
	  lfs       f0, 0x30(r30)
	  lfs       f1, 0x10(r30)
	  fadds     f30, f4, f3
	  fadds     f31, f2, f0
	  bl        0xF56E4
	  lfs       f0, 0x2C(r30)
	  lfs       f2, 0x1C(r1)
	  fmuls     f0, f0, f1
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r31)
	  stfs      f31, 0x4(r31)
	  stfs      f30, 0x8(r31)
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lfd       f30, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126644
 * Size:	000084
 */
void PeveCircleMoveEvent::calcAngle()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x24
	  bl        -0x9808
	  lwz       r3, 0x24(r31)
	  addi      r4, r1, 0x24
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x18
	  bl        -0x9828
	  lwz       r3, 0x20(r31)
	  addi      r4, r1, 0x18
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0xC
	  addi      r4, r1, 0x24
	  addi      r5, r1, 0x18
	  bl        -0x9778
	  lfs       f1, 0xC(r1)
	  lfs       f2, 0x14(r1)
	  bl        -0x88A8
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
PeveCircleMoveWatchEvent::PeveCircleMoveWatchEvent()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void PeveCircleMoveWatchEvent::makeCircleMoveWatchEvent(f32, NVector3fIO*, NVector3fIO*, NVector3fIO*, f32, f32, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
PeveFunctionCurveEvent::PeveFunctionCurveEvent()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void PeveFunctionCurveEvent::makeFunctionCurveEvent(PeveCondition*, NVector3fIO*, NFunction3D*, f32, f32, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801266C8
 * Size:	00000C
 */
void PeveFunctionCurveEvent::reset()
{
	/*
	.loc_0x0:
	  lfs       f0, 0x1C(r3)
	  stfs      f0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801266D4
 * Size:	0000C0
 */
void PeveFunctionCurveEvent::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  addi      r3, r1, 0x1C
	  bl        -0x98B8
	  mr        r0, r3
	  lwz       r3, 0x18(r30)
	  mr        r31, r0
	  lfs       f1, 0x10(r30)
	  mr        r4, r31
	  bl        -0xAB4C
	  lwz       r3, 0x14(r30)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x24(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x98
	  lwz       r3, 0x3150(r13)
	  lfs       f1, 0x20(r30)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x10(r30)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x10(r30)
	  b         .loc_0xA8

	.loc_0x98:
	  lfs       f1, 0x10(r30)
	  lfs       f0, 0x20(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r30)

	.loc_0xA8:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
PeveHomingPositionEvent::PeveHomingPositionEvent()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void PeveHomingPositionEvent::makeHomingPositionEvent(PeveCondition*, NVector3fIO*, NVector3fIO*, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80126794
 * Size:	000124
 */
void PeveHomingPositionEvent::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x38:
	  addi      r3, r1, 0x24
	  bl        -0x997C
	  mr        r0, r3
	  lwz       r3, 0x10(r29)
	  mr        r31, r0
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x18
	  bl        -0x99A4
	  mr        r0, r3
	  lwz       r3, 0x14(r29)
	  mr        r30, r0
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r4, r31, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0xC
	  bl        -0x98FC
	  lfs       f1, 0x18(r29)
	  mr        r4, r31
	  lfs       f0, 0x0(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r3)
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r31)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r31)
	  lfs       f1, 0x8(r31)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r31)
	  lwz       r3, 0x10(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
PeveHomingPostureEvent::PeveHomingPostureEvent()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void PeveHomingPostureEvent::makeHomingPostureEvent(PeveCondition*, NVector3fIO*, NVector3fIO*, f32, PeveCondition*, NVector3fIO*,
                                                    NVector3fIO*, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
PeveInterpolationEvent::PeveInterpolationEvent(int, NPool<SplineSegment>*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void PeveInterpolationEvent::makeInterpolationEvent(PeveCondition*, NPosture3DIO*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801268B8
 * Size:	0000EC
 */
void PeveInterpolationEvent::reset()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  mr        r30, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  addi      r3, r30, 0x18
	  bl        -0x9714
	  lwz       r3, 0x2C(r30)
	  bl        -0x8A98
	  li        r31, 0
	  stw       r31, 0x10(r30)
	  li        r4, 0
	  lwz       r3, 0x2C(r30)
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r4, r3, 0x4
	  lwz       r3, 0x30(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r30)
	  cmplwi    r3, 0
	  bne-      .loc_0x90
	  b         .loc_0x94

	.loc_0x90:
	  lwz       r31, 0x8(r3)

	.loc_0x94:
	  lwz       r4, 0x10(r30)
	  subi      r0, r31, 0x1
	  cmpw      r4, r0
	  bne-      .loc_0xB0
	  lfs       f0, -0x5DF8(r2)
	  stfs      f0, 0x14(r30)
	  b         .loc_0xD4

	.loc_0xB0:
	  lwz       r3, 0x2C(r30)
	  addi      r4, r4, 0x1
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0x14(r30)

	.loc_0xD4:
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
 * Address:	801269A4
 * Size:	00017C
 */
void PeveInterpolationEvent::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stw       r31, 0x84(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  addi      r3, r31, 0x18
	  lfs       f1, 0x1C(r31)
	  bl        -0x97F8
	  lfs       f0, 0x14(r31)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x108
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x64
	  li        r4, 0
	  b         .loc_0x68

	.loc_0x64:
	  lwz       r4, 0x8(r3)

	.loc_0x68:
	  lwz       r3, 0x10(r31)
	  addi      r0, r3, 0x1
	  cmpw      r0, r4
	  bge-      .loc_0x108
	  stw       r0, 0x10(r31)
	  lwz       r3, 0x2C(r31)
	  lwz       r4, 0x10(r31)
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r4, r3, 0x4
	  lwz       r3, 0x30(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0xC4
	  li        r3, 0
	  b         .loc_0xC8

	.loc_0xC4:
	  lwz       r3, 0x8(r3)

	.loc_0xC8:
	  lwz       r4, 0x10(r31)
	  subi      r0, r3, 0x1
	  cmpw      r4, r0
	  bne-      .loc_0xE4
	  lfs       f0, -0x5DF8(r2)
	  stfs      f0, 0x14(r31)
	  b         .loc_0x108

	.loc_0xE4:
	  lwz       r3, 0x2C(r31)
	  addi      r4, r4, 0x1
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0x14(r31)

	.loc_0x108:
	  addi      r3, r31, 0x18
	  lfs       f1, 0x1C(r31)
	  bl        -0x98CC
	  addi      r3, r1, 0x5C
	  fmr       f31, f1
	  bl        -0xA4A0
	  fmr       f1, f31
	  lwz       r3, 0x2C(r31)
	  addi      r4, r1, 0x5C
	  bl        -0x8C64
	  addi      r3, r1, 0x5C
	  bl        -0xA374
	  lwz       r3, 0x30(r31)
	  addi      r4, r1, 0x5C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3150(r13)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C(r31)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lwz       r31, 0x84(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
PeveMoveEvent::PeveMoveEvent()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void PeveMoveEvent::makeMoveEvent(NPosture3DIO*, NPosture3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80126B20
 * Size:	00005C
 */
void PeveMoveEvent::reset()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x30:
	  lwz       r3, 0x18(r31)
	  addi      r4, r31, 0x1C
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126B7C
 * Size:	00009C
 */
PeveVibrationEvent::PeveVibrationEvent()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0x1644
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6004
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0x14
	  bl        -0x9D54
	  addi      r3, r31, 0x20
	  bl        -0xF48
	  addi      r3, r31, 0x2C
	  bl        -0xB080
	  lis       r3, 0x802C
	  addi      r0, r3, 0x425C
	  lis       r3, 0x802C
	  stw       r0, 0x3C(r31)
	  addi      r0, r3, 0x424C
	  stw       r0, 0x3C(r31)
	  addi      r3, r31, 0x40
	  bl        -0x9E18
	  li        r3, 0x8
	  bl        -0xDFBDC
	  addi      r4, r3, 0
	  addi      r3, r31, 0x3C
	  li        r5, 0x2
	  bl        -0xB50C
	  addi      r3, r31, 0x20
	  lfs       f1, -0x5DF4(r2)
	  bl        -0xF4C
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
 * Address:	80126C18
 * Size:	000088
 */
void PeveVibrationEvent::makeVibrationEvent(f32, NPosture3DIO*, NVector3f&, f32, f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  fmr       f31, f4
	  stfd      f30, 0x30(r1)
	  fmr       f30, f3
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  addi      r0, r31, 0x20
	  stw       r4, 0x10(r3)
	  addi      r3, r31, 0x2C
	  stfs      f1, 0x28(r31)
	  stw       r0, 0x8(r31)
	  lfs       f0, 0x0(r5)
	  stfs      f0, 0x14(r31)
	  lfs       f0, 0x4(r5)
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x8(r5)
	  stfs      f0, 0x1C(r31)
	  lfs       f1, -0x5DF4(r2)
	  lfs       f3, -0x5DF8(r2)
	  bl        -0xB0FC
	  lwz       r3, 0x40(r31)
	  stfs      f30, 0x0(r3)
	  lwz       r3, 0x40(r31)
	  stfs      f31, 0x4(r3)
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lfd       f30, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126CA0
 * Size:	000100
 */
void PeveVibrationEvent::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x38:
	  addi      r3, r31, 0x2C
	  lfs       f30, 0x24(r31)
	  lwz       r12, 0x2C(r31)
	  fmr       f1, f30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r31, 0x3C
	  fmr       f31, f1
	  lwz       r12, 0x3C(r31)
	  fmr       f1, f30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  fmuls     f30, f1, f31
	  addi      r3, r1, 0x2C
	  bl        -0x9EC4
	  lfs       f0, 0x14(r31)
	  addi      r3, r1, 0x10
	  fmuls     f0, f30, f0
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x18(r31)
	  fmuls     f0, f30, f0
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x1C(r31)
	  fmuls     f0, f30, f0
	  stfs      f0, 0x34(r1)
	  bl        -0xA724
	  lwz       r3, 0x10(r31)
	  addi      r4, r1, 0x10
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x10
	  addi      r4, r1, 0x2C
	  bl        -0xA4FC
	  lwz       r3, 0x10(r31)
	  addi      r4, r1, 0x10
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126DA0
 * Size:	000024
 */
void PeveInterpolationEvent::isFinished()
{
	/*
	.loc_0x0:
	  lfs       f1, 0x20(r3)
	  lfs       f0, 0x24(r3)
	  lfs       f2, 0x1C(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  mfcr      r0
	  rlwinm    r3,r0,3,31,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126DC4
 * Size:	000008
 */
void PeveInterpolationEvent::setStartTime(f32)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x20(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126DCC
 * Size:	000008
 */
void PeveInterpolationEvent::getStartTime()
{
	/*
	.loc_0x0:
	  lfs       f1, 0x20(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126DD4
 * Size:	000008
 */
void PeveInterpolationEvent::setPeriod(f32)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126DDC
 * Size:	000008
 */
void PeveInterpolationEvent::getPeriod()
{
	/*
	.loc_0x0:
	  lfs       f1, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126DE4
 * Size:	000008
 */
void PeveInterpolationEvent::setTime(f32)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x1C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126DEC
 * Size:	000008
 */
void PeveInterpolationEvent::getTime()
{
	/*
	.loc_0x0:
	  lfs       f1, 0x1C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126DF4
 * Size:	000010
 */
void PeveInterpolationEvent::getEndTime()
{
	/*
	.loc_0x0:
	  lfs       f1, 0x20(r3)
	  lfs       f0, 0x24(r3)
	  fadds     f1, f1, f0
	  blr
	*/
}
