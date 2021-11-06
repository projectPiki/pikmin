#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
NAxisAngle4f::NAxisAngle4f()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BC80
 * Size:	000058
 */
NAxisAngle4f::NAxisAngle4f(NVector3f &, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stfd      f31, 0x20(r1)
  fmr       f31, f1
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  bl        0x11B0
  fmr       f1, f31
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        .loc_0x58
  mr        r3, r30
  lwz       r0, 0x2C(r1)
  lfd       f31, 0x20(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr       

.loc_0x58:
*/
}

/*
 * --INFO--
 * Address:	8011BCD8
 * Size:	000020
 */
void NAxisAngle4f::construct(NVector3f &, float)
{
/*
.loc_0x0:
  lfs       f0, 0x0(r4)
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r4)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r4)
  stfs      f0, 0x8(r3)
  stfs      f1, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8011BCF8
 * Size:	000080
 */
NMatrix4f::NMatrix4f()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stw       r31, 0x74(r1)
  addi      r31, r3, 0
  addi      r3, r1, 0x2C
  lfs       f2, -0x5FF0(r2)
  stfs      f2, 0x8(r1)
  fmr       f3, f2
  fmr       f4, f2
  stfs      f2, 0xC(r1)
  fmr       f5, f2
  fmr       f7, f2
  lfs       f1, -0x5FEC(r2)
  fmr       f8, f2
  stfs      f1, 0x10(r1)
  fmr       f6, f1
  stfs      f2, 0x14(r1)
  stfs      f2, 0x18(r1)
  stfs      f2, 0x1C(r1)
  stfs      f2, 0x20(r1)
  stfs      f1, 0x24(r1)
  bl        0x48
  addi      r4, r3, 0
  addi      r3, r31, 0
  bl        0xAC
  mr        r3, r31
  lwz       r0, 0x7C(r1)
  lwz       r31, 0x74(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NMatrix4f::NMatrix4f(Matrix4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BD78
 * Size:	000020
 */
void NMatrix4f::construct(Matrix4f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x84
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8011BD98
 * Size:	000070
 */
NMatrix4f::NMatrix4f(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stw       r31, 0x54(r1)
  mr        r31, r3
  lfs       f0, 0x60(r1)
  lfs       f9, 0x68(r1)
  stfs      f0, 0x8(r1)
  lfs       f0, 0x64(r1)
  stfs      f0, 0xC(r1)
  lfs       f0, 0x6C(r1)
  stfs      f9, 0x10(r1)
  lfs       f9, 0x70(r1)
  stfs      f0, 0x14(r1)
  lfs       f0, 0x74(r1)
  stfs      f9, 0x18(r1)
  stfs      f0, 0x1C(r1)
  lfs       f0, 0x78(r1)
  stfs      f0, 0x20(r1)
  lfs       f0, 0x7C(r1)
  stfs      f0, 0x24(r1)
  bl        0xAC
  mr        r3, r31
  lwz       r0, 0x5C(r1)
  lwz       r31, 0x54(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void NMatrix4f::construct(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NMatrix4f::NMatrix4f(float (*) [4])
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NMatrix4f::construct(float (*) [4])
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NMatrix4f::input(float (*) [4])
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NMatrix4f::output(float (*) [4])
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BE08
 * Size:	000090
 */
void NMatrix4f::input(Matrix4f &)
{
/*
.loc_0x0:
  lfs       f0, 0x0(r4)
  addi      r5, r4, 0x10
  addi      r6, r3, 0x10
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r4)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r4)
  stfs      f0, 0x8(r3)
  lfs       f0, 0xC(r4)
  stfs      f0, 0xC(r3)
  lfs       f0, 0x10(r4)
  stfs      f0, 0x10(r3)
  lfs       f0, 0x14(r4)
  stfs      f0, 0x14(r3)
  lfs       f0, 0x18(r4)
  stfs      f0, 0x18(r3)
  lfs       f0, 0x1C(r4)
  stfs      f0, 0x1C(r3)
  lfsu      f0, 0x10(r5)
  stfsu     f0, 0x10(r6)
  lfs       f0, 0x4(r5)
  stfs      f0, 0x24(r3)
  lfs       f0, 0x8(r5)
  stfs      f0, 0x8(r6)
  lfs       f0, 0xC(r5)
  stfs      f0, 0xC(r6)
  lfsu      f0, 0x10(r5)
  stfs      f0, 0x10(r6)
  lfs       f0, 0x4(r5)
  stfs      f0, 0x14(r6)
  addi      r6, r6, 0x10
  lfs       f0, 0x8(r5)
  stfs      f0, 0x8(r6)
  lfs       f0, 0xC(r5)
  stfs      f0, 0xC(r6)
  blr
*/
}

/*
 * --INFO--
 * Address:	8011BE98
 * Size:	00006C
 */
void NMatrix4f::set(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
{
/*
.loc_0x0:
  stwu      r1, -0x30(r1)
  stfs      f1, 0x0(r3)
  lfs       f11, 0x38(r1)
  stfs      f2, 0x4(r3)
  lfs       f10, 0x3C(r1)
  stfs      f3, 0x8(r3)
  lfs       f9, 0x40(r1)
  stfs      f4, 0xC(r3)
  lfs       f4, 0x44(r1)
  stfs      f5, 0x10(r3)
  lfs       f3, 0x48(r1)
  stfs      f6, 0x14(r3)
  lfs       f2, 0x4C(r1)
  stfs      f7, 0x18(r3)
  lfs       f1, 0x50(r1)
  stfs      f8, 0x1C(r3)
  lfs       f0, 0x54(r1)
  stfs      f11, 0x20(r3)
  stfs      f10, 0x24(r3)
  stfs      f9, 0x28(r3)
  stfs      f4, 0x2C(r3)
  stfs      f3, 0x30(r3)
  stfs      f2, 0x34(r3)
  stfs      f1, 0x38(r3)
  stfs      f0, 0x3C(r3)
  addi      r1, r1, 0x30
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void NMatrix4f::setRow(int, float, float, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NMatrix4f::inputRow(int, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NMatrix4f::inputRow(int, Vector3f &, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NMatrix4f::outputRow(int, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void NMatrix4f::inputRows(NVector3f &, NVector3f &, NVector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void NMatrix4f::setCol(int, float, float, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NMatrix4f::inputCol(int, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NMatrix4f::inputCol(int, Vector3f &, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BF04
 * Size:	000024
 */
void NMatrix4f::outputCol(int, Vector3f &)
{
/*
.loc_0x0:
  rlwinm    r0,r4,2,0,29
  lfsx      f0, r3, r0
  add       r3, r3, r0
  stfs      f0, 0x0(r5)
  lfs       f0, 0x10(r3)
  stfs      f0, 0x4(r5)
  lfs       f0, 0x20(r3)
  stfs      f0, 0x8(r5)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void NMatrix4f::inputCols(NVector3f &, NVector3f &, NVector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NMatrix4f::mul(Matrix4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NMatrix4f::mul2(Matrix4f &, Matrix4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void NMatrix4f::scale(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
void NMatrix4f::transpose()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BF28
 * Size:	000024
 */
void NMatrix4f::makeIdentRow(int)
{
/*
.loc_0x0:
  lfs       f0, -0x5FF0(r2)
  rlwinm    r0,r4,4,0,27
  add       r4, r3, r0
  stfsx     f0, r3, r0
  stfs      f0, 0x4(r4)
  stfs      f0, 0x8(r4)
  lfs       f0, -0x5FEC(r2)
  stfs      f0, 0xC(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NMatrix4f::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
NOrientation::NOrientation()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BF4C
 * Size:	000050
 */
NOrientation::NOrientation(Vector3f &)
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
  bl        0xEEC
  addi      r3, r30, 0xC
  bl        0xEE4
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        .loc_0x50
  mr        r3, r30
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr       

.loc_0x50:
*/
}

/*
 * --INFO--
 * Address:	8011BF9C
 * Size:	000078
 */
void NOrientation::construct(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r4
  stw       r30, 0x20(r1)
  mr        r30, r3
  addi      r3, r1, 0x10
  lfs       f1, -0x5FF0(r2)
  lfs       f2, -0x5FEC(r2)
  fmr       f3, f1
  bl        0xF14
  lfs       f0, 0x0(r31)
  stfs      f0, 0x0(r30)
  lfs       f0, 0x4(r31)
  stfs      f0, 0x4(r30)
  lfs       f0, 0x8(r31)
  stfs      f0, 0x8(r30)
  lfs       f0, 0x10(r1)
  stfs      f0, 0xC(r30)
  lfs       f0, 0x14(r1)
  stfs      f0, 0x10(r30)
  lfs       f0, 0x18(r1)
  stfs      f0, 0x14(r30)
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
 * Size:	000060
 */
NOrientation::NOrientation(Vector3f &, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NOrientation::construct(Vector3f &, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C014
 * Size:	0000D4
 */
void NOrientation::normalize()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x80(r1)
  stw       r31, 0x7C(r1)
  stw       r30, 0x78(r1)
  stw       r29, 0x74(r1)
  addi      r29, r3, 0
  addi      r4, r29, 0
  addi      r3, r29, 0xC
  bl        0xF68
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x38
  mr        r3, r29
  bl        0xEC

.loc_0x38:
  addi      r3, r1, 0x60
  bl        0xE04
  addi      r31, r3, 0
  addi      r3, r29, 0
  addi      r4, r31, 0
  bl        .loc_0xD4
  addi      r3, r1, 0x20
  bl        0x998
  addi      r30, r3, 0
  addi      r3, r1, 0x10
  bl        0xDE0
  addi      r4, r31, 0
  addi      r3, r1, 0x10
  addi      r5, r31, 0x4
  addi      r6, r31, 0x8
  bl        -0xBE9FC
  lfs       f1, -0x1CA4(r13)
  addi      r4, r1, 0x10
  lfs       f0, -0x5FE8(r2)
  mr        r3, r30
  fmuls     f0, f1, f0
  stfs      f0, 0x1C(r1)
  bl        0xC2C
  lfs       f0, 0x0(r29)
  addi      r3, r30, 0
  addi      r4, r29, 0xC
  stfs      f0, 0xC(r29)
  lfs       f0, 0x4(r29)
  stfs      f0, 0x10(r29)
  lfs       f0, 0x8(r29)
  stfs      f0, 0x14(r29)
  bl        0xBDC
  lwz       r0, 0x84(r1)
  lwz       r31, 0x7C(r1)
  lwz       r30, 0x78(r1)
  lwz       r29, 0x74(r1)
  addi      r1, r1, 0x80
  mtlr      r0
  blr       

.loc_0xD4:
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NOrientation::transform(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NOrientation::outputRight(NVector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C0E8
 * Size:	00004C
 */
void NOrientation::outputLeft(NVector3f &)
{
/*
.loc_0x0:
  lfs       f1, 0x4(r3)
  lfs       f6, 0x14(r3)
  lfs       f2, 0xC(r3)
  lfs       f7, 0x8(r3)
  fmuls     f0, f6, f1
  lfs       f4, 0x10(r3)
  fmuls     f5, f2, f1
  lfs       f3, 0x0(r3)
  fmuls     f1, f4, f7
  fmuls     f4, f4, f3
  fmuls     f3, f6, f3
  fmuls     f2, f2, f7
  fsubs     f0, f1, f0
  fsubs     f1, f5, f4
  fsubs     f2, f3, f2
  stfs      f0, 0x0(r4)
  stfs      f2, 0x4(r4)
  stfs      f1, 0x8(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	8011C134
 * Size:	000254
 */
void NOrientation::makeUp()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE0(r1)
  stw       r31, 0xDC(r1)
  addi      r31, r3, 0
  addi      r3, r1, 0xB4
  stw       r30, 0xD8(r1)
  stw       r29, 0xD4(r1)
  stw       r28, 0xD0(r1)
  bl        0xCFC
  addi      r29, r1, 0xC0
  addi      r3, r29, 0
  bl        0xCF0
  lfs       f1, -0x5FF0(r2)
  addi      r3, r1, 0x1C
  lfs       f2, -0x5FEC(r2)
  fmr       f3, f1
  bl        0xD64
  addi      r4, r31, 0
  addi      r3, r1, 0xB4
  addi      r5, r31, 0x4
  addi      r6, r31, 0x8
  bl        -0xBEB00
  addi      r3, r29, 0
  addi      r4, r1, 0x1C
  addi      r5, r1, 0x20
  addi      r6, r1, 0x24
  bl        -0xBEB14
  lfs       f1, -0x5FF0(r2)
  addi      r0, r1, 0xB4
  lfs       f2, -0x5FEC(r2)
  mr        r28, r0
  fmr       f3, f1
  addi      r3, r1, 0xA8
  bl        0xD20
  addi      r4, r3, 0
  addi      r3, r28, 0
  bl        0xDD8
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0xD0
  lfs       f1, -0x5FF0(r2)
  addi      r3, r1, 0x9C
  lfs       f2, -0x5FEC(r2)
  fmr       f3, f1
  bl        0xCF8
  lfs       f0, 0x9C(r1)
  stfs      f0, 0xC0(r1)
  lfs       f0, 0xA0(r1)
  stfs      f0, 0xC4(r1)
  lfs       f0, 0xA4(r1)
  stfs      f0, 0xC8(r1)
  b         .loc_0x124

.loc_0xD0:
  lfs       f1, -0x5FF0(r2)
  addi      r3, r1, 0x90
  lfs       f3, -0x5FEC(r2)
  fmr       f2, f1
  bl        0xCC8
  addi      r4, r3, 0
  addi      r3, r28, 0
  bl        0xD80
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x124
  lfs       f1, -0x5FF0(r2)
  addi      r3, r1, 0x84
  lfs       f3, -0x5FEC(r2)
  fmr       f2, f1
  bl        0xCA0
  lfs       f0, 0x84(r1)
  stfs      f0, 0xC0(r1)
  lfs       f0, 0x88(r1)
  stfs      f0, 0xC4(r1)
  lfs       f0, 0x8C(r1)
  stfs      f0, 0xC8(r1)

.loc_0x124:
  addi      r3, r28, 0xC
  addi      r4, r28, 0
  bl        0xD40
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x140
  mr        r3, r28
  bl        .loc_0x0

.loc_0x140:
  addi      r3, r1, 0x28
  bl        0xBDC
  lfs       f3, 0xC0(r1)
  mr        r29, r3
  lfs       f2, 0xB8(r1)
  addi      r6, r1, 0x18
  lfs       f1, 0xC4(r1)
  lfs       f0, 0xB4(r1)
  fmuls     f2, f3, f2
  addi      r5, r1, 0x14
  fmuls     f0, f1, f0
  addi      r4, r1, 0x10
  fsubs     f0, f2, f0
  stfs      f0, 0x18(r1)
  lfs       f3, 0xC8(r1)
  lfs       f2, 0xB4(r1)
  lfs       f1, 0xC0(r1)
  lfs       f0, 0xBC(r1)
  fmuls     f2, f3, f2
  fmuls     f0, f1, f0
  fsubs     f0, f2, f0
  stfs      f0, 0x14(r1)
  lfs       f3, 0xC4(r1)
  lfs       f2, 0xBC(r1)
  lfs       f1, 0xC8(r1)
  lfs       f0, 0xB8(r1)
  fmuls     f2, f3, f2
  fmuls     f0, f1, f0
  fsubs     f0, f2, f0
  stfs      f0, 0x10(r1)
  bl        -0xBEC60
  addi      r3, r1, 0x34
  bl        0x70C
  addi      r30, r3, 0
  addi      r3, r1, 0x74
  bl        0xB54
  addi      r3, r1, 0x74
  addi      r4, r29, 0
  bl        .loc_0x254
  lfs       f1, -0x1CA4(r13)
  addi      r4, r1, 0x74
  lfs       f0, -0x5FE8(r2)
  mr        r3, r30
  fmuls     f0, f1, f0
  stfs      f0, 0x80(r1)
  bl        0x9A8
  lfs       f0, 0xB4(r1)
  addi      r3, r30, 0
  addi      r4, r28, 0xC
  stfs      f0, 0xC0(r1)
  lfs       f0, 0xB8(r1)
  stfs      f0, 0xC4(r1)
  lfs       f0, 0xBC(r1)
  stfs      f0, 0xC8(r1)
  bl        0x958
  lfs       f0, 0xC0(r1)
  stfs      f0, 0xC(r31)
  lfs       f0, 0xC4(r1)
  stfs      f0, 0x10(r31)
  lfs       f0, 0xC8(r1)
  stfs      f0, 0x14(r31)
  lwz       r0, 0xE4(r1)
  lwz       r31, 0xDC(r1)
  lwz       r30, 0xD8(r1)
  lwz       r29, 0xD4(r1)
  lwz       r28, 0xD0(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr       

.loc_0x254:
*/
}

/*
 * --INFO--
 * Address:	8011C388
 * Size:	00001C
 */
void Vector3f::input(Vector3f &)
{
/*
.loc_0x0:
  lfs       f0, 0x0(r4)
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r4)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r4)
  stfs      f0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
void NOrientation::outputTransform(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void NOrientation::inputTransform(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void NOrientation::outputRotation(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NOrientation::inputRotation(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NOrientation::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C3A4
 * Size:	00003C
 */
NPolar3f::NPolar3f()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lfs       f2, -0x5FF0(r2)
  lfs       f1, -0x5FEC(r2)
  fmr       f3, f2
  bl        0x6C
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
 * Address:	........
 * Size:	000030
 */
NPolar3f::NPolar3f(float, float, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NPolar3f::construct(float, float, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NPolar3f::NPolar3f(NPolar3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void NPolar3f::construct(NPolar3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C3E0
 * Size:	000030
 */
NPolar3f::NPolar3f(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        .loc_0x30
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr       

.loc_0x30:
*/
}

/*
 * --INFO--
 * Address:	8011C410
 * Size:	000020
 */
void NPolar3f::construct(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x24
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8011C430
 * Size:	000010
 */
void NPolar3f::set(float, float, float)
{
/*
.loc_0x0:
  stfs      f1, 0x0(r3)
  stfs      f2, 0x4(r3)
  stfs      f3, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void NPolar3f::input(NPolar3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C440
 * Size:	0000A8
 */
void NPolar3f::input(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stfd      f31, 0x28(r1)
  stfd      f30, 0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r4
  stw       r30, 0x18(r1)
  mr        r30, r3
  lfs       f1, 0x0(r4)
  lfs       f2, 0x8(r4)
  bl        0x199C
  lfs       f0, 0x8(r31)
  fmr       f30, f1
  lfs       f1, 0x0(r31)
  fmuls     f0, f0, f0
  fmuls     f1, f1, f1
  fadds     f1, f1, f0
  bl        -0x10E848
  lfs       f2, 0x4(r31)
  bl        0x1978
  lfs       f2, 0x0(r31)
  fmr       f31, f1
  lfs       f0, 0x4(r31)
  fmuls     f1, f2, f2
  lfs       f2, 0x8(r31)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x10E878
  stfs      f1, 0x0(r30)
  stfs      f31, 0x4(r30)
  stfs      f30, 0x8(r30)
  lwz       r0, 0x34(r1)
  lfd       f31, 0x28(r1)
  lfd       f30, 0x20(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8011C4E8
 * Size:	0000A4
 */
void NPolar3f::output(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stfd      f31, 0x50(r1)
  stfd      f30, 0x48(r1)
  stfd      f29, 0x40(r1)
  stw       r31, 0x3C(r1)
  mr        r31, r4
  stw       r30, 0x38(r1)
  mr        r30, r3
  lfs       f1, 0x4(r3)
  bl        0xFF7D4
  lfs       f0, 0x4(r30)
  fmr       f29, f1
  fmr       f1, f0
  bl        0xFF630
  lfs       f0, 0x8(r30)
  fmr       f30, f1
  fmr       f1, f0
  bl        0xFF7B4
  lfs       f0, 0x8(r30)
  fmr       f31, f1
  fmr       f1, f0
  bl        0xFF610
  lfs       f0, 0x0(r30)
  fmuls     f3, f0, f29
  fmuls     f0, f0, f30
  fmuls     f2, f31, f3
  fmuls     f1, f1, f3
  stfs      f2, 0x0(r31)
  stfs      f0, 0x4(r31)
  stfs      f1, 0x8(r31)
  lwz       r0, 0x5C(r1)
  lfd       f31, 0x50(r1)
  lfd       f30, 0x48(r1)
  lfd       f29, 0x40(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void NPolar3f::negate()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NMathF::roundAngle(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NPolar3f::interpolate(NPolar3f &, NPolar3f &, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void NPolar3f::roundMeridian()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NPolar3f::clampMeridian(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NPolar3f::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
NPosture2D::NPosture2D()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
NPosture2D::NPosture2D(Vector3f &, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NPosture2D::construct(Vector3f &, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void NPosture2D::outputTransform(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void NPosture2D::outputInverseTransform(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void NPosture2D::outputAxisAngle(NAxisAngle4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C58C
 * Size:	000094
 */
void NPosture2D::readData(Stream &)
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
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x4(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x8(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0xC(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x10(r30)
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
 * Address:	........
 * Size:	000024
 */
void NPosture2D::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C620
 * Size:	0000A0
 */
NPosture3D::NPosture3D()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802C
  stw       r0, 0x4(r1)
  addi      r0, r4, 0x4334
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r3, 0
  stw       r0, 0x0(r3)
  addi      r3, r31, 0x4
  bl        0x810
  addi      r3, r31, 0x10
  bl        0x808
  lfs       f1, -0x5FF0(r2)
  addi      r3, r1, 0x18
  fmr       f2, f1
  fmr       f3, f1
  bl        0x87C
  lfs       f0, 0x18(r1)
  addi      r3, r1, 0xC
  stfs      f0, 0x4(r31)
  lfs       f0, 0x1C(r1)
  stfs      f0, 0x8(r31)
  lfs       f0, 0x20(r1)
  stfs      f0, 0xC(r31)
  lfs       f1, -0x5FF0(r2)
  lfs       f3, -0x5FEC(r2)
  fmr       f2, f1
  bl        0x850
  lfs       f0, 0xC(r1)
  mr        r3, r31
  stfs      f0, 0x10(r31)
  lfs       f0, 0x10(r1)
  stfs      f0, 0x14(r31)
  lfs       f0, 0x14(r1)
  stfs      f0, 0x18(r31)
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
NPosture3D::NPosture3D(NPosture3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void NPosture3D::construct(NPosture3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C6C0
 * Size:	000070
 */
NPosture3D::NPosture3D(Vector3f &, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x802C
  stw       r0, 0x4(r1)
  addi      r0, r6, 0x4334
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r5, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  stw       r0, 0x0(r3)
  addi      r3, r29, 0x4
  bl        0x760
  addi      r3, r29, 0x10
  bl        0x758
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
 * Address:	8011C730
 * Size:	000034
 */
void NPosture3D::construct(Vector3f &, Vector3f &)
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
 * Address:	8011C764
 * Size:	0000D4
 */
void NPosture3D::normalize()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  addi      r30, r3, 0
  addi      r3, r1, 0x1C
  bl        0x6D4
  addi      r31, r3, 0
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        .loc_0xD4
  lfs       f1, 0x0(r31)
  lfs       f0, 0x4(r31)
  fmuls     f1, f1, f1
  lfs       f2, 0x8(r31)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x10EB74
  lfs       f0, -0x5FF0(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x64
  b         .loc_0x68

.loc_0x64:
  fneg      f1, f1

.loc_0x68:
  lfs       f0, -0x1CB0(r13)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0xBC
  lfs       f1, -0x5FF0(r2)
  addi      r3, r1, 0x10
  lfs       f3, -0x5FEC(r2)
  fmr       f2, f1
  bl        0x6F0
  lfs       f1, 0x10(r30)
  lfs       f0, 0x10(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x10(r30)
  lfs       f1, 0x14(r30)
  lfs       f0, 0x14(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x14(r30)
  lfs       f1, 0x18(r30)
  lfs       f0, 0x18(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x18(r30)

.loc_0xBC:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr       

.loc_0xD4:
*/
}

/*
 * --INFO--
 * Address:	8011C838
 * Size:	000034
 */
void NPosture3D::outputRelative(NVector3f &)
{
/*
.loc_0x0:
  lfs       f1, 0x10(r3)
  lfs       f0, 0x4(r3)
  lfs       f3, 0x14(r3)
  lfs       f2, 0x8(r3)
  fsubs     f0, f1, f0
  lfs       f4, 0x18(r3)
  lfs       f1, 0xC(r3)
  fsubs     f2, f3, f2
  stfs      f0, 0x0(r4)
  fsubs     f0, f4, f1
  stfs      f2, 0x4(r4)
  stfs      f0, 0x8(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NPosture3D::outputUnitVector(NVector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NPosture3D::transform(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C86C
 * Size:	000064
 */
void NPosture3D::translate(Vector3f &)
{
/*
.loc_0x0:
  lfs       f1, 0x4(r3)
  lfs       f0, 0x0(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r3)
  lfs       f1, 0x8(r3)
  lfs       f0, 0x4(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r3)
  lfs       f1, 0xC(r3)
  lfs       f0, 0x8(r4)
  fadds     f0, f1, f0
  stfs      f0, 0xC(r3)
  lfs       f1, 0x10(r3)
  lfs       f0, 0x0(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x10(r3)
  lfs       f1, 0x14(r3)
  lfs       f0, 0x4(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x14(r3)
  lfs       f1, 0x18(r3)
  lfs       f0, 0x8(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x18(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void NPosture3D::rotate(NVector3f &, NPolar3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001CC
 */
void NPosture3D::rotatePoint(NVector3f &, NVector3f &, NPolar3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void NPosture3D::interpolate(NPosture3D &, NPosture3D &, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void NPosture3D::input(NPosture2D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void NPosture3D::output(NPosture2D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void NPosture3D::outputTransform(NPosture3D &, NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002A0
 */
void NPosture3D::outputTransform(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000418
 */
void NPosture3D::outputInverseTransform(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void NPosture3D::inputTransform(NTransform3D &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void NPosture3D::calcDirection()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C8D0
 * Size:	0000C4
 */
void NPosture3D::readData(Stream &)
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
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x4(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x8(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0xC(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x10(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x14(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x18(r30)
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
 * Address:	........
 * Size:	000038
 */
void NPosture3D::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
NSpecialMatrix::NSpecialMatrix(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void NSpecialMatrix::construct(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
NLowerMatrix::NLowerMatrix(float *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void NLowerMatrix::construct(float *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void NLowerMatrix::solve(NVector &, NVector &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void NLowerMatrix::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
NUpperMatrix::NUpperMatrix(float *, float *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void NUpperMatrix::construct(float *, float *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void NUpperMatrix::solve(NVector &, NVector &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void NUpperMatrix::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
LUMatrix::LUMatrix(float *, float *, float *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void LUMatrix::construct(float *, float *, float *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C994
 * Size:	000064
 */
void LUMatrix::setDimension(int)
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
  stw       r31, 0x4(r3)
  addi      r3, r30, 0x8
  lwz       r12, 0x8(r30)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  addi      r3, r30, 0x14
  lwz       r12, 0x14(r30)
  mr        r4, r31
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
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
 * Address:	8011C9F8
 * Size:	000008
 */
void NSpecialMatrix::setDimension(int a1)
{
// Generated from stw r4, 0x4(r3)
_04 = a1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00022C
 */
void LUMatrix::solve(NVector &, NVector &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void LUMatrix::decompose()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void LUMatrix::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CA00
 * Size:	000080
 */
NTransform3D::NTransform3D()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stw       r31, 0x74(r1)
  addi      r31, r3, 0
  addi      r3, r1, 0x2C
  lfs       f2, -0x5FF0(r2)
  stfs      f2, 0x8(r1)
  fmr       f3, f2
  fmr       f4, f2
  stfs      f2, 0xC(r1)
  fmr       f5, f2
  fmr       f7, f2
  lfs       f1, -0x5FEC(r2)
  fmr       f8, f2
  stfs      f1, 0x10(r1)
  fmr       f6, f1
  stfs      f2, 0x14(r1)
  stfs      f2, 0x18(r1)
  stfs      f2, 0x1C(r1)
  stfs      f2, 0x20(r1)
  stfs      f1, 0x24(r1)
  bl        -0xBC0
  addi      r3, r31, 0
  addi      r4, r1, 0x2C
  bl        .loc_0x80
  mr        r3, r31
  lwz       r0, 0x7C(r1)
  lwz       r31, 0x74(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr       

.loc_0x80:
*/
}

/*
 * --INFO--
 * Address:	8011CA80
 * Size:	000088
 */
void NMath<float>::copyArray44(float (*) [4], float (*) [4])
{
/*
.loc_0x0:
  lfs       f0, 0x0(r4)
  addi      r6, r3, 0x10
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r4)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r4)
  stfs      f0, 0x8(r3)
  lfs       f0, 0xC(r4)
  stfs      f0, 0xC(r3)
  lfs       f0, 0x10(r4)
  stfs      f0, 0x10(r3)
  lfs       f0, 0x14(r4)
  stfs      f0, 0x14(r3)
  lfs       f0, 0x18(r4)
  stfs      f0, 0x18(r3)
  lfs       f0, 0x1C(r4)
  stfs      f0, 0x1C(r3)
  lfs       f0, 0x20(r4)
  stfsu     f0, 0x10(r6)
  lfs       f0, 0x24(r4)
  stfs      f0, 0x24(r3)
  lfs       f0, 0x28(r4)
  stfs      f0, 0x28(r3)
  lfs       f0, 0x2C(r4)
  stfs      f0, 0xC(r6)
  lfs       f0, 0x30(r4)
  stfs      f0, 0x10(r6)
  lfs       f0, 0x34(r4)
  stfs      f0, 0x14(r6)
  lfs       f0, 0x38(r4)
  stfs      f0, 0x18(r6)
  lfs       f0, 0x3C(r4)
  stfs      f0, 0x1C(r6)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
NTransform3D::NTransform3D(NMatrix4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NTransform3D::construct(NMatrix4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NTransform3D::translate(Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CB08
 * Size:	00019C
 */
void NTransform3D::rotate(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x220(r1)
  stw       r31, 0x21C(r1)
  addi      r31, r3, 0
  addi      r3, r1, 0x14C
  stw       r30, 0x218(r1)
  stw       r29, 0x214(r1)
  addi      r29, r4, 0
  lfs       f2, -0x5FF0(r2)
  stfs      f2, 0x8(r1)
  fmr       f3, f2
  fmr       f4, f2
  stfs      f2, 0xC(r1)
  fmr       f5, f2
  fmr       f7, f2
  lfs       f1, -0x5FEC(r2)
  fmr       f8, f2
  stfs      f1, 0x10(r1)
  fmr       f6, f1
  stfs      f2, 0x14(r1)
  stfs      f2, 0x18(r1)
  stfs      f2, 0x1C(r1)
  stfs      f2, 0x20(r1)
  stfs      f1, 0x24(r1)
  bl        -0xCD4
  addi      r3, r1, 0x1CC
  addi      r4, r1, 0x14C
  bl        -0xF8
  addi      r30, r1, 0x1CC
  addi      r3, r31, 0
  addi      r4, r30, 0
  bl        0x16C
  addi      r3, r1, 0xCC
  bl        -0xDDB74
  lfs       f2, -0x5FF0(r2)
  addi      r3, r1, 0xCC
  stfs      f2, 0x8(r1)
  fmr       f3, f2
  fmr       f4, f2
  stfs      f2, 0xC(r1)
  fmr       f5, f2
  fmr       f7, f2
  lfs       f1, -0x5FEC(r2)
  fmr       f8, f2
  stfs      f1, 0x10(r1)
  fmr       f6, f1
  stfs      f2, 0x14(r1)
  stfs      f2, 0x18(r1)
  stfs      f2, 0x1C(r1)
  stfs      f2, 0x20(r1)
  stfs      f1, 0x24(r1)
  bl        -0xD40
  addi      r3, r1, 0x18C
  addi      r4, r1, 0xCC
  bl        -0x164
  addi      r31, r1, 0x18C
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        0x100
  addi      r3, r1, 0x10C
  bl        -0xDDBE0
  lfs       f2, -0x5FF0(r2)
  addi      r3, r1, 0x4C
  stfs      f2, 0x8(r1)
  fmr       f3, f2
  fmr       f4, f2
  stfs      f2, 0xC(r1)
  fmr       f5, f2
  fmr       f7, f2
  lfs       f1, -0x5FEC(r2)
  fmr       f8, f2
  stfs      f1, 0x10(r1)
  fmr       f6, f1
  stfs      f2, 0x14(r1)
  stfs      f2, 0x18(r1)
  stfs      f2, 0x1C(r1)
  stfs      f2, 0x20(r1)
  stfs      f1, 0x24(r1)
  bl        -0xEAC
  addi      r4, r3, 0
  addi      r3, r1, 0x10C
  bl        -0xE48
  addi      r30, r1, 0x10C
  addi      r3, r31, 0
  addi      r4, r30, 0
  bl        0x94
  addi      r3, r1, 0x8C
  bl        -0xF70
  addi      r31, r1, 0x8C
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        0x7C
  addi      r3, r31, 0
  addi      r4, r29, 0
  bl        .loc_0x0
  lwz       r0, 0x224(r1)
  lwz       r31, 0x21C(r1)
  lwz       r30, 0x218(r1)
  lwz       r29, 0x214(r1)
  addi      r1, r1, 0x220
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8011CCA4
 * Size:	00002C
 */
void NTransform3D::transform(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  addi      r0, r3, 0
  addi      r3, r4, 0
  stwu      r1, -0x8(r1)
  mr        r4, r0
  bl        -0xE5570
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NTransform3D::transform(Vector3f &, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000184
 */
void NTransform3D::transform(NVector &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00018C
 */
void NTransform3D::transform(NVector &, NVector &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void NTransform3D::inputVector(Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CCD0
 * Size:	000024
 */
void NTransform3D::inputAxisAngle(NAxisAngle4f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lfs       f1, 0xC(r4)
  bl        -0xDEE18
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void NTransform3D::inputTranslation(Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void NTransform3D::outputTranslation(Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NTransform3D::inputRotation(Matrix4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CCF4
 * Size:	0000CC
 */
void NTransform3D::outputRotation(Matrix4f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r4, 0
  stw       r30, 0x28(r1)
  addi      r30, r3, 0
  addi      r3, r1, 0x18
  bl        0x140
  lfs       f0, 0x0(r30)
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r30)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r30)
  stfs      f0, 0x8(r3)
  lfs       f0, 0x0(r3)
  stfs      f0, 0x0(r31)
  lfs       f0, 0x4(r3)
  stfs      f0, 0x4(r31)
  lfs       f0, 0x8(r3)
  stfs      f0, 0x8(r31)
  lfs       f0, 0x10(r30)
  stfs      f0, 0x0(r3)
  lfs       f0, 0x14(r30)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x18(r30)
  stfs      f0, 0x8(r3)
  lfs       f0, 0x0(r3)
  stfs      f0, 0x10(r31)
  lfs       f0, 0x4(r3)
  stfs      f0, 0x14(r31)
  lfs       f0, 0x8(r3)
  stfs      f0, 0x18(r31)
  lfs       f0, 0x20(r30)
  stfs      f0, 0x0(r3)
  lfs       f0, 0x24(r30)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x28(r30)
  stfs      f0, 0x8(r3)
  lfs       f0, 0x0(r3)
  stfs      f0, 0x20(r31)
  lfs       f0, 0x4(r3)
  stfs      f0, 0x24(r31)
  lfs       f0, 0x8(r3)
  stfs      f0, 0x28(r31)
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
 * Size:	0000E4
 */
void NTransform3D::inputRotation(NAxisAngle4f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CDC0
 * Size:	000010
 */
NVector::NVector()
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x0(r3)
  stw       r0, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NVector::NVector(float *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CDD0
 * Size:	000028
 */
void NVector::construct(float *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  stw       r4, 0x0(r3)
  stw       r5, 0x4(r3)
  bl        .loc_0x28
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr       

.loc_0x28:
*/
}

/*
 * --INFO--
 * Address:	8011CDF8
 * Size:	000030
 */
void NVector::makeZero()
{
/*
.loc_0x0:
  lfs       f0, -0x5FF0(r2)
  li        r6, 0
  li        r5, 0
  b         .loc_0x20

.loc_0x10:
  lwz       r4, 0x0(r3)
  addi      r6, r6, 0x1
  stfsx     f0, r4, r5
  addi      r5, r5, 0x4

.loc_0x20:
  lwz       r0, 0x4(r3)
  cmpw      r6, r0
  blt+      .loc_0x10
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NVector::add(NVector &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000118
 */
void NVector::dot(NVector &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NVector::input(NVector &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void NVector::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void NVector3f::printVector3f(Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CE28
 * Size:	00002C
 */
void NVector3f::printlnVector3f(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r4, r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  addi      r3, r1, 0xC
  bl        0x44
  bl        0x1D4
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8011CE54
 * Size:	00002C
 */
NVector3f::NVector3f()
{
/*
.loc_0x0:
  lfs       f0, -0x5FF0(r2)
  stfs      f0, 0x8(r3)
  stfs      f0, 0x4(r3)
  stfs      f0, 0x0(r3)
  lfs       f0, -0x1D38(r13)
  stfs      f0, 0x0(r3)
  lfs       f0, -0x1D34(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x1D30(r13)
  stfs      f0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8011CE80
 * Size:	000040
 */
NVector3f::NVector3f(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lfs       f0, -0x5FF0(r2)
  stfs      f0, 0x8(r3)
  stfs      f0, 0x4(r31)
  stfs      f0, 0x0(r31)
  bl        .loc_0x40
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr       

.loc_0x40:
*/
}

/*
 * --INFO--
 * Address:	8011CEC0
 * Size:	00001C
 */
void NVector3f::construct(Vector3f &)
{
/*
.loc_0x0:
  lfs       f0, 0x0(r4)
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r4)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r4)
  stfs      f0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8011CEDC
 * Size:	000040
 */
NVector3f::NVector3f(float, float, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lfs       f0, -0x5FF0(r2)
  stfs      f0, 0x8(r31)
  stfs      f0, 0x4(r31)
  stfs      f0, 0x0(r31)
  bl        .loc_0x40
  mr        r3, r31
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr       

.loc_0x40:
*/
}

/*
 * --INFO--
 * Address:	8011CF1C
 * Size:	000010
 */
void NVector3f::construct(float, float, float)
{
/*
.loc_0x0:
  stfs      f1, 0x0(r3)
  stfs      f2, 0x4(r3)
  stfs      f3, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8011CF2C
 * Size:	000040
 */
NVector3f::NVector3f(Vector3f &, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lfs       f0, -0x5FF0(r2)
  stfs      f0, 0x8(r3)
  stfs      f0, 0x4(r31)
  stfs      f0, 0x0(r31)
  bl        .loc_0x40
  mr        r3, r31
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr       

.loc_0x40:
*/
}

/*
 * --INFO--
 * Address:	8011CF6C
 * Size:	000034
 */
void NVector3f::construct(Vector3f &, Vector3f &)
{
/*
.loc_0x0:
  lfs       f1, 0x0(r5)
  lfs       f0, 0x0(r4)
  lfs       f3, 0x4(r5)
  lfs       f2, 0x4(r4)
  fsubs     f0, f1, f0
  lfs       f4, 0x8(r5)
  lfs       f1, 0x8(r4)
  fsubs     f2, f3, f2
  stfs      f0, 0x0(r3)
  fsubs     f0, f4, f1
  stfs      f2, 0x4(r3)
  stfs      f0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NVector3f::interpolate(Vector3f &, Vector3f &, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void NVector3f::isZero()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void NMath<float>::absolute(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void NVector3f::equals(Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void NVector3f::isVertical(Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CFA0
 * Size:	000074
 */
void NVector3f::isParallel(Vector3f &)
{
/*
.loc_0x0:
  lfs       f3, 0x0(r3)
  lfs       f2, 0x0(r4)
  lfs       f1, 0x4(r3)
  lfs       f0, 0x4(r4)
  fmuls     f2, f3, f2
  lfs       f4, 0x8(r3)
  fmuls     f1, f1, f0
  lfs       f3, 0x8(r4)
  lfs       f0, -0x5FF0(r2)
  fmuls     f3, f4, f3
  fadds     f1, f2, f1
  fadds     f2, f3, f1
  fcmpo     cr0, f2, f0
  ble-      .loc_0x3C
  b         .loc_0x40

.loc_0x3C:
  fneg      f2, f2

.loc_0x40:
  lfs       f1, -0x5FEC(r2)
  lfs       f0, -0x5FF0(r2)
  fsubs     f1, f2, f1
  fcmpo     cr0, f1, f0
  ble-      .loc_0x58
  b         .loc_0x5C

.loc_0x58:
  fneg      f1, f1

.loc_0x5C:
  lfs       f0, -0x1CB0(r13)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  mfcr      r0
  rlwinm    r3,r0,3,31,31
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000144
 */
void NVector3f::makeUnitVector(Vector3f &, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void NVector3f::outputQuat(float, Quat &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void NVector3f::calcAngle(NVector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void NVector3f::calcLargerAngle(NVector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NVector3f::print()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D014
 * Size:	000004
 */
void NVector3f::println()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NVector3f::normalizeByLength(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D018
 * Size:	0000E8
 */
void NVector3f::normalizeCheck()
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lfs       f1, 0x0(r3)
  lfs       f0, 0x4(r3)
  fmuls     f2, f1, f1
  lfs       f3, 0x8(r3)
  fmuls     f1, f0, f0
  lfs       f0, -0x5FF0(r2)
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x88
  fsqrte    f1, f4
  lfd       f3, -0x5FE0(r2)
  lfd       f2, -0x5FD8(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f4, f0
  frsp      f0, f0
  stfs      f0, 0x10(r1)
  lfs       f4, 0x10(r1)

.loc_0x88:
  lfs       f0, -0x5FF0(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0x9C
  fmr       f1, f4
  b         .loc_0xA0

.loc_0x9C:
  fneg      f1, f4

.loc_0xA0:
  lfs       f0, -0x1CB0(r13)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0xB8
  li        r3, 0
  b         .loc_0xE0

.loc_0xB8:
  lfs       f0, 0x0(r3)
  fdivs     f0, f0, f4
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r3)
  fdivs     f0, f0, f4
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r3)
  fdivs     f0, f0, f4
  stfs      f0, 0x8(r3)
  li        r3, 0x1

.loc_0xE0:
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	8011D100
 * Size:	0000DC
 */
void NVector3f::normalize()
{
/*
.loc_0x0:
  stwu      r1, -0x20(r1)
  lfs       f1, 0x0(r3)
  lfs       f0, 0x4(r3)
  fmuls     f2, f1, f1
  lfs       f3, 0x8(r3)
  fmuls     f1, f0, f0
  lfs       f0, -0x5FF0(r2)
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x88
  fsqrte    f1, f4
  lfd       f3, -0x5FE0(r2)
  lfd       f2, -0x5FD8(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f4, f0
  frsp      f0, f0
  stfs      f0, 0x10(r1)
  lfs       f4, 0x10(r1)

.loc_0x88:
  lfs       f0, -0x5FF0(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0x9C
  fmr       f1, f4
  b         .loc_0xA0

.loc_0x9C:
  fneg      f1, f4

.loc_0xA0:
  lfs       f0, -0x1CB0(r13)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  beq-      .loc_0xD4
  lfs       f0, 0x0(r3)
  fdivs     f0, f0, f4
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r3)
  fdivs     f0, f0, f4
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r3)
  fdivs     f0, f0, f4
  stfs      f0, 0x8(r3)

.loc_0xD4:
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NAlpha::fadeInValue(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NAlpha::fadeOutValue(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void NAlpha::fadeInOutValue(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void NAlpha::fadeOutInValue(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NAlpha::NAlpha()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D1DC
 * Size:	00000C
 */
void NAlpha::reset()
{
/*
.loc_0x0:
  lfs       f0, 0x8(r3)
  stfs      f0, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8011D1E8
 * Size:	000198
 */
void NAlpha::getValue(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lfs       f2, 0xC(r3)
  lfs       f0, -0x5FF0(r2)
  fcmpo     cr0, f2, f0
  ble-      .loc_0x20
  b         .loc_0x24

.loc_0x20:
  fneg      f2, f2

.loc_0x24:
  lfs       f0, -0x1CB0(r13)
  fcmpo     cr0, f2, f0
  cror      2, 0, 0x2
  bne-      .loc_0x3C
  lfs       f0, -0x5FEC(r2)
  stfs      f0, 0xC(r3)

.loc_0x3C:
  lfs       f0, 0x8(r3)
  lbz       r0, 0x10(r3)
  fsubs     f1, f1, f0
  lfs       f0, 0xC(r3)
  cmpwi     r0, 0x2
  fdivs     f1, f1, f0
  beq-      .loc_0xA4
  bge-      .loc_0x6C
  cmpwi     r0, 0
  beq-      .loc_0x188
  bge-      .loc_0x80
  b         .loc_0x188

.loc_0x6C:
  cmpwi     r0, 0x4
  beq-      .loc_0x124
  bge-      .loc_0x188
  b         .loc_0xBC
  b         .loc_0x188

.loc_0x80:
  lfs       f2, -0x1CA4(r13)
  lfs       f0, -0x5FE8(r2)
  fmuls     f2, f2, f0
  fmuls     f0, f1, f2
  fadds     f1, f2, f0
  bl        0xFEA6C
  lfs       f0, -0x5FEC(r2)
  fsubs     f1, f0, f1
  b         .loc_0x188

.loc_0xA4:
  lfs       f2, -0x1CA4(r13)
  lfs       f0, -0x5FE8(r2)
  fmuls     f0, f2, f0
  fmuls     f1, f1, f0
  bl        0xFEA4C
  b         .loc_0x188

.loc_0xBC:
  lfs       f3, -0x5FE8(r2)
  fcmpo     cr0, f1, f3
  bge-      .loc_0xF8
  lfs       f2, -0x1CA4(r13)
  lfs       f0, -0x5FD0(r2)
  fmuls     f2, f2, f3
  fmuls     f0, f0, f1
  fmuls     f0, f0, f2
  fadds     f1, f2, f0
  bl        0xFEA20
  lfs       f0, -0x5FEC(r2)
  lfs       f2, -0x5FE8(r2)
  fsubs     f0, f0, f1
  fmuls     f1, f2, f0
  b         .loc_0x188

.loc_0xF8:
  fsubs     f1, f1, f3
  lfs       f2, -0x5FD0(r2)
  lfs       f0, -0x1CA4(r13)
  fmuls     f1, f2, f1
  fmuls     f0, f0, f3
  fmuls     f1, f1, f0
  bl        0xFE9F0
  lfs       f2, -0x5FE8(r2)
  fmuls     f0, f2, f1
  fadds     f1, f2, f0
  b         .loc_0x188

.loc_0x124:
  lfs       f3, -0x5FE8(r2)
  fcmpo     cr0, f1, f3
  bge-      .loc_0x154
  lfs       f2, -0x5FD0(r2)
  lfs       f0, -0x1CA4(r13)
  fmuls     f1, f2, f1
  fmuls     f0, f0, f3
  fmuls     f1, f1, f0
  bl        0xFE9BC
  lfs       f0, -0x5FE8(r2)
  fmuls     f1, f0, f1
  b         .loc_0x188

.loc_0x154:
  fsubs     f0, f1, f3
  lfs       f2, -0x1CA4(r13)
  lfs       f1, -0x5FD0(r2)
  fmuls     f2, f2, f3
  fmuls     f0, f1, f0
  fmuls     f0, f0, f2
  fadds     f1, f2, f0
  bl        0xFE990
  lfs       f0, -0x5FEC(r2)
  lfs       f2, -0x5FE8(r2)
  fsubs     f0, f0, f1
  fmuls     f0, f2, f0
  fadds     f1, f2, f0

.loc_0x188:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8011D380
 * Size:	00007C
 */
void NAlpha::readData(Stream &)
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
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x8(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0xC(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x10(r30)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
