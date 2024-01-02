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
 * Size:	00008C
 */
NLine::NLine()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D3FC
 * Size:	000070
 */
NLine::NLine(NVector3f&, NVector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802C
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x4368
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  stw       r0, 0x0(r3)
	  addi      r3, r29, 0x4
	  bl        -0x5DC
	  addi      r3, r29, 0x10
	  bl        -0x5E4
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        .loc_0x70
	  mr        r3, r29
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0x70:
	*/
}

/*
 * --INFO--
 * Address:	8011D46C
 * Size:	000034
 */
void NLine::construct(NVector3f&, NVector3f&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0xC(r3)
	  lfs       f0, 0x0(r5)
	  stfs      f0, 0x10(r3)
	  lfs       f0, 0x4(r5)
	  stfs      f0, 0x14(r3)
	  lfs       f0, 0x8(r5)
	  stfs      f0, 0x18(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
NLine::NLine(NLine&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NLine::construct(NLine&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D4A0
 * Size:	0000C0
 */
void NLine::calcDistance(NVector3f&, f32*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x3C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x38(r1)
	  addi      r28, r3, 0
	  addi      r3, r1, 0x2C
	  bl        -0x67C
	  addi      r31, r3, 0
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        .loc_0xC0
	  fmr       f31, f1
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        0xD4
	  cmplwi    r30, 0
	  beq-      .loc_0x60
	  stfs      f31, 0x0(r30)

	.loc_0x60:
	  lfs       f3, 0x0(r29)
	  lfs       f2, 0x0(r31)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x4(r31)
	  fsubs     f4, f3, f2
	  lfs       f2, 0x8(r29)
	  fsubs     f3, f1, f0
	  lfs       f0, 0x8(r31)
	  fmuls     f1, f4, f4
	  fsubs     f2, f2, f0
	  fmuls     f0, f3, f3
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x10F8F8
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr

	.loc_0xC0:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002AC
 */
void NLine::calcDistance(NLine&, f32*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NLine::outputVerticalPosition(NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D560
 * Size:	000064
 */
void NLine::calcVerticalProjection(NVector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x10
	  addi      r4, r31, 0x4
	  bl        -0x654
	  lfs       f3, 0x10(r31)
	  lfs       f2, 0x0(r3)
	  lfs       f1, 0x14(r31)
	  lfs       f0, 0x4(r3)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x18(r31)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x8(r3)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f1, f1, f0
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011D5C4
 * Size:	00009C
 */
void NLine::outputPosition(f32, NVector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  fmr       f31, f1
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x18
	  bl        -0x798
	  lfs       f0, 0x10(r30)
	  fmuls     f0, f31, f0
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x14(r30)
	  fmuls     f0, f31, f0
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x18(r30)
	  fmuls     f0, f31, f0
	  stfs      f0, 0x8(r3)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x0(r3)
	  lfs       f3, 0x8(r30)
	  lfs       f2, 0x4(r3)
	  fadds     f0, f1, f0
	  lfs       f4, 0xC(r30)
	  lfs       f1, 0x8(r3)
	  fadds     f2, f3, f2
	  stfs      f0, 0x0(r31)
	  fadds     f0, f4, f1
	  stfs      f2, 0x4(r31)
	  stfs      f0, 0x8(r31)
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void NLine::outputPositionY(f32, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D660
 * Size:	00004C
 */
void NLine::transform(NTransform3D&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  addi      r4, r30, 0x4
	  bl        -0x9E0
	  addi      r3, r31, 0
	  addi      r4, r30, 0x10
	  bl        -0xB88
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
 * Address:	8011D6AC
 * Size:	000038
 */
void NLine::println()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x4
	  bl        -0x6B0
	  addi      r3, r31, 0x10
	  bl        -0x6B8
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
NPlane::NPlane()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
NPlane::NPlane(NVector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NPlane::construct(NVector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D6E4
 * Size:	000068
 */
NPlane::NPlane(NVector3f&, NVector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802C
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x4358
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  stw       r0, 0x0(r3)
	  addi      r3, r29, 0x4
	  bl        -0x8C4
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        .loc_0x68
	  mr        r3, r29
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0x68:
	*/
}

/*
 * --INFO--
 * Address:	8011D74C
 * Size:	000050
 */
void NPlane::construct(NVector3f&, NVector3f&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0xC(r3)
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x0(r5)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x4(r5)
	  fmuls     f2, f3, f2
	  lfs       f3, 0xC(r3)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x8(r5)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  fneg      f0, f0
	  stfs      f0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
NPlane::NPlane(NVector3f&, NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void NPlane::construct(NVector3f&, NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
NPlane::NPlane(Plane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void NPlane::construct(Plane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
NPlane::NPlane(NPlane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NPlane::construct(NPlane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void NPlane::intersects(NLine&, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00018C
 */
void NPlane::outputIntersection(NLine&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000154
 */
void NPlane::intersectsRay(NLine&, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void NPlane::outputRayIntersection(NLine&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001DC
 */
void NPlane::intersectsSegment(NSegment&, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000188
 */
void NPlane::outputSegmentIntersection(NSegment&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NPlane::outputPosition(NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D79C
 * Size:	0000DC
 */
void NPlane::outputVerticalPosition(NVector3f&, NVector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r5
	  stw       r30, 0x38(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x34(r1)
	  addi      r29, r3, 0
	  lfs       f3, 0x4(r3)
	  lfs       f2, 0x0(r4)
	  lfs       f1, 0x8(r3)
	  addi      r3, r1, 0x1C
	  lfs       f0, 0x4(r4)
	  fmuls     f2, f3, f2
	  lfs       f3, 0xC(r29)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x8(r4)
	  lfs       f4, 0x10(r29)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  fadds     f31, f4, f0
	  bl        -0x9A8
	  fneg      f1, f31
	  lfs       f0, 0x4(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x8(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0xC(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8(r3)
	  lfs       f1, 0x0(r30)
	  lfs       f0, 0x0(r3)
	  lfs       f3, 0x4(r30)
	  lfs       f2, 0x4(r3)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r30)
	  lfs       f1, 0x8(r3)
	  fadds     f2, f3, f2
	  stfs      f0, 0x0(r31)
	  fadds     f0, f4, f1
	  stfs      f2, 0x4(r31)
	  stfs      f0, 0x8(r31)
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
 * Address:	........
 * Size:	0000B4
 */
void NPlane::negate()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void NPlane::adjustTo(NVector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void NPlane::adjust(NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00028C
 */
void NPlane::outputIntersectionLineY(NPlane&, NLine&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NPlane::calcAngle(NPlane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void NPlane::calcY(f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D878
 * Size:	0000C0
 */
void NPlane::transform(NTransform3D&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x14
	  bl        -0xA48
	  lfs       f1, 0x10(r29)
	  mr        r31, r3
	  lfs       f0, 0x4(r29)
	  addi      r3, r30, 0
	  fneg      f1, f1
	  addi      r4, r29, 0x4
	  fmuls     f0, f1, f0
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x8(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0xC(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8(r31)
	  bl        -0xDD0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0xC40
	  lfs       f3, 0x4(r29)
	  lfs       f2, 0x0(r31)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x4(r31)
	  fmuls     f2, f3, f2
	  lfs       f3, 0xC(r29)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x8(r31)
	  fmuls     f1, f3, f1
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  fneg      f0, f0
	  stfs      f0, 0x10(r29)
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
 * Address:	8011D938
 * Size:	000024
 */
void NPlane::println()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x934
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
NSegment::NSegment()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
NSegment::NSegment(NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void NSegment::construct(NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
NSegment::NSegment(NSegment&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void NSegment::construct(NSegment&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002E0
 */
void NSegment::calcDistanceAsSegment(NVector3f&, f32*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003CC
 */
void NSegment::calcDistanceAsSegment(NLine&, f32*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000230
 */
void NSegment::calcSegmentDistanceAsSegment(NSegment&, f32*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void NSegment::transform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NSegment::translate(NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NSegment::makeProjectionY()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void NSegment::println()
{
	// UNUSED FUNCTION
}
