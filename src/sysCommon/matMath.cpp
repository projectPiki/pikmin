#include "types.h"
#include "Vector3f.h"
#include "Matrix4f.h"
extern const float lbl_803E85E0;
extern const float lbl_803E85E4;
/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
/*
void _Error(char *, ...)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
/*
void _Print(char *, ...)
{
   // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
/*
Matrix4f::Matrix4f(float (*) [4])
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	8003DDBC
 * Size:	00004C
 */
void Matrix4f::makeIdentity()
{
	mMatrix[0][0] = lbl_803E85E0;
	mMatrix[0][1] = lbl_803E85E4;
	mMatrix[0][2] = lbl_803E85E4;
	mMatrix[0][3] = lbl_803E85E4;
	mMatrix[1][0] = lbl_803E85E4;
	mMatrix[1][1] = lbl_803E85E0;
	mMatrix[1][2] = lbl_803E85E4;
	mMatrix[1][3] = lbl_803E85E4;
	mMatrix[2][0] = lbl_803E85E4;
	mMatrix[2][1] = lbl_803E85E4;
	mMatrix[2][2] = lbl_803E85E0;
	mMatrix[2][3] = lbl_803E85E4;
	mMatrix[3][0] = lbl_803E85E4;
	mMatrix[3][1] = lbl_803E85E4;
	mMatrix[3][2] = lbl_803E85E4;
	mMatrix[3][3] = lbl_803E85E0;
	return;

	/*
	.loc_0x0:
	  lfs       f1, -0x7C20(r2)
	  stfs      f1, 0x0(r3)
	  lfs       f0, -0x7C1C(r2)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f1, 0x14(r3)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x1C(r3)
	  stfs      f0, 0x20(r3)
	  stfs      f0, 0x24(r3)
	  stfs      f1, 0x28(r3)
	  stfs      f0, 0x2C(r3)
	  stfs      f0, 0x30(r3)
	  stfs      f0, 0x34(r3)
	  stfs      f0, 0x38(r3)
	  stfs      f1, 0x3C(r3)
	  blr
	*/
};

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
/*
void Matrix4f::blend(Matrix4f &, float)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	0001A4
 */
/*
void Matrix4f::makeOrtho(float, float, float, float, float, float, float)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
/*
void Matrix4f::makePerspective(float, float, float, float)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	8003DE08
 * Size:	0000C0
 */
// void Matrix4f::makeRotate(Vector3f &, float, float)
//{
/*
.loc_0x0:
  stwu      r1, -0x20(r1)
  stfd      f31, 0x18(r1)
  lfs       f8, -0x7C20(r2)
  lfs       f3, 0x0(r4)
  fsubs     f0, f8, f2
  lfs       f13, 0x4(r4)
  lfs       f31, 0x8(r4)
  fmuls     f11, f1, f3
  fmuls     f9, f1, f13
  fmuls     f4, f0, f3
  fmuls     f7, f0, f13
  fmuls     f0, f0, f31
  fmuls     f3, f3, f4
  fmuls     f5, f1, f31
  fmuls     f6, f13, f4
  fadds     f1, f2, f3
  fmuls     f10, f31, f4
  fadds     f4, f6, f5
  stfs      f1, 0x0(r3)
  fmuls     f0, f31, f0
  fsubs     f3, f10, f9
  stfs      f4, 0x4(r3)
  fmuls     f12, f31, f7
  stfs      f3, 0x8(r3)
  fmuls     f1, f13, f7
  fsubs     f6, f6, f5
  lfs       f7, -0x7C1C(r2)
  fadds     f5, f2, f1
  stfs      f7, 0xC(r3)
  fadds     f4, f12, f11
  fadds     f3, f10, f9
  stfs      f6, 0x10(r3)
  fsubs     f1, f12, f11
  stfs      f5, 0x14(r3)
  fadds     f0, f2, f0
  stfs      f4, 0x18(r3)
  stfs      f7, 0x1C(r3)
  stfs      f3, 0x20(r3)
  stfs      f1, 0x24(r3)
  stfs      f0, 0x28(r3)
  stfs      f7, 0x2C(r3)
  stfs      f7, 0x30(r3)
  stfs      f7, 0x34(r3)
  stfs      f7, 0x38(r3)
  stfs      f8, 0x3C(r3)
  lfd       f31, 0x18(r1)
  addi      r1, r1, 0x20
  blr
*/
//}

/*
 * --INFO--
 * Address:	8003DEC8
 * Size:	00006C
 */
// void Matrix4f::makeRotate(Vector3f &, float)
//{
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
  bl        0x1DDDFC
  fmr       f0, f1
  fmr       f1, f31
  fmr       f31, f0
  bl        0x1DDC58
  fmr       f0, f1
  mr        r3, r30
  fmr       f1, f31
  mr        r4, r31
  fmr       f2, f0
  bl        -0x10C
  lwz       r0, 0x2C(r1)
  lfd       f31, 0x20(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
//}

/*
 * --INFO--
 * Address:	........
 * Size:	000178
 */
/*
void Matrix4f::makeBallRotate(Vector3f &)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
/*
void Matrix4f::rotate(Vector3f &, float)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	000138
 */
/*
void Matrix4f::rotate(float, float, float)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	8003DF34
 * Size:	0001A0
 */
// void Matrix4f::multiply(Matrix4f &)
//{
/*
.loc_0x0:
  stwu      r1, -0x60(r1)
  addi      r8, r3, 0
  li        r10, 0
  lfs       f3, -0x7C1C(r2)
  addi      r7, r1, 0x1C

.loc_0x14:
  li        r0, 0x2
  mtctr     r0
  addi      r5, r7, 0
  li        r6, 0

.loc_0x24:
  stfs      f3, 0x0(r5)
  add       r9, r4, r6
  addi      r6, r6, 0x4
  lfs       f1, 0x0(r8)
  lfs       f0, 0x0(r9)
  lfs       f2, 0x0(r5)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x0(r5)
  lfs       f1, 0x4(r8)
  lfs       f0, 0x10(r9)
  lfs       f2, 0x0(r5)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x0(r5)
  lfs       f1, 0x8(r8)
  lfs       f0, 0x20(r9)
  lfs       f2, 0x0(r5)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x0(r5)
  lfs       f0, 0x30(r9)
  add       r9, r4, r6
  lfs       f1, 0xC(r8)
  addi      r6, r6, 0x4
  lfs       f2, 0x0(r5)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x0(r5)
  stfs      f3, 0x4(r5)
  lfs       f1, 0x0(r8)
  lfs       f0, 0x0(r9)
  lfs       f2, 0x4(r5)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x4(r5)
  lfs       f1, 0x4(r8)
  lfs       f0, 0x10(r9)
  lfs       f2, 0x4(r5)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x4(r5)
  lfs       f1, 0x8(r8)
  lfs       f0, 0x20(r9)
  lfs       f2, 0x4(r5)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x4(r5)
  lfs       f1, 0xC(r8)
  lfs       f0, 0x30(r9)
  lfs       f2, 0x4(r5)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x4(r5)
  addi      r5, r5, 0x8
  bdnz+     .loc_0x24
  addi      r10, r10, 0x1
  cmpwi     r10, 0x4
  addi      r7, r7, 0x10
  addi      r8, r8, 0x10
  blt+      .loc_0x14
  lwz       r4, 0x1C(r1)
  lwz       r0, 0x20(r1)
  stw       r4, 0x0(r3)
  stw       r0, 0x4(r3)
  lwz       r4, 0x24(r1)
  lwz       r0, 0x28(r1)
  stw       r4, 0x8(r3)
  stw       r0, 0xC(r3)
  lwz       r4, 0x2C(r1)
  lwz       r0, 0x30(r1)
  stw       r4, 0x10(r3)
  stw       r0, 0x14(r3)
  lwz       r4, 0x34(r1)
  lwz       r0, 0x38(r1)
  stw       r4, 0x18(r3)
  stw       r0, 0x1C(r3)
  lwz       r4, 0x3C(r1)
  lwz       r0, 0x40(r1)
  stw       r4, 0x20(r3)
  stw       r0, 0x24(r3)
  lwz       r4, 0x44(r1)
  lwz       r0, 0x48(r1)
  stw       r4, 0x28(r3)
  stw       r0, 0x2C(r3)
  lwz       r4, 0x4C(r1)
  lwz       r0, 0x50(r1)
  stw       r4, 0x30(r3)
  stw       r0, 0x34(r3)
  lwz       r4, 0x54(r1)
  lwz       r0, 0x58(r1)
  stw       r4, 0x38(r3)
  stw       r0, 0x3C(r3)
  addi      r1, r1, 0x60
  blr
*/
//}

/*
 * --INFO--
 * Address:	8003E0D4
 * Size:	000020
 */
// void Matrix4f::multiplyTo(Matrix4f &, Matrix4f &)
//{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x1BFAE0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
//}

/*
 * --INFO--
 * Address:	8003E0F4
 * Size:	00019C
 */
// void Matrix4f::makeSRT(Vector3f &, Vector3f &, Vector3f &)
//{
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
  addi      r31, r6, 0
  stw       r30, 0x38(r1)
  mr        r30, r5
  stw       r29, 0x34(r1)
  addi      r29, r4, 0
  stw       r28, 0x30(r1)
  addi      r28, r3, 0
  lfs       f1, 0x0(r5)
  bl        0x1DDBB0
  fmr       f27, f1
  lfs       f1, 0x4(r30)
  bl        0x1DDBA4
  fmr       f28, f1
  lfs       f1, 0x8(r30)
  bl        0x1DDB98
  fmr       f29, f1
  lfs       f1, 0x0(r30)
  bl        0x1DD9F8
  fmr       f30, f1
  lfs       f1, 0x4(r30)
  bl        0x1DD9EC
  fmr       f31, f1
  lfs       f1, 0x8(r30)
  bl        0x1DD9E0
  fmuls     f0, f31, f1
  lfs       f2, 0x0(r29)
  fmuls     f3, f27, f28
  fmuls     f9, f30, f29
  fmuls     f0, f2, f0
  fmuls     f2, f3, f1
  fmuls     f8, f30, f1
  stfs      f0, 0x0(r28)
  fmuls     f0, f3, f29
  fmuls     f3, f31, f29
  lfs       f4, 0x0(r29)
  fneg      f7, f28
  fmuls     f3, f4, f3
  fsubs     f6, f2, f9
  fadds     f5, f8, f0
  stfs      f3, 0x10(r28)
  fmuls     f4, f27, f31
  fmuls     f3, f8, f28
  lfs       f2, 0x0(r29)
  fmuls     f0, f27, f29
  fmuls     f7, f2, f7
  fmuls     f2, f9, f28
  fmuls     f1, f27, f1
  stfs      f7, 0x20(r28)
  fadds     f3, f3, f0
  fmuls     f0, f30, f31
  lfs       f7, -0x7C1C(r2)
  fsubs     f1, f2, f1
  stfs      f7, 0x38(r28)
  stfs      f7, 0x34(r28)
  stfs      f7, 0x30(r28)
  lfs       f2, 0x4(r29)
  fmuls     f2, f2, f6
  stfs      f2, 0x4(r28)
  lfs       f2, 0x4(r29)
  fmuls     f2, f2, f5
  stfs      f2, 0x14(r28)
  lfs       f2, 0x4(r29)
  fmuls     f2, f2, f4
  stfs      f2, 0x24(r28)
  lfs       f2, 0x8(r29)
  fmuls     f2, f2, f3
  stfs      f2, 0x8(r28)
  lfs       f2, 0x8(r29)
  fmuls     f1, f2, f1
  stfs      f1, 0x18(r28)
  lfs       f1, 0x8(r29)
  fmuls     f0, f1, f0
  stfs      f0, 0x28(r28)
  lfs       f0, 0x0(r31)
  stfs      f0, 0xC(r28)
  lfs       f0, 0x4(r31)
  stfs      f0, 0x1C(r28)
  lfs       f0, 0x8(r31)
  stfs      f0, 0x2C(r28)
  lfs       f0, -0x7C20(r2)
  stfs      f0, 0x3C(r28)
  lwz       r0, 0x6C(r1)
  lfd       f31, 0x60(r1)
  lfd       f30, 0x58(r1)
  lfd       f29, 0x50(r1)
  lfd       f28, 0x48(r1)
  lfd       f27, 0x40(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  lwz       r29, 0x34(r1)
  lwz       r28, 0x30(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
//}

/*
 * --INFO--
 * Address:	8003E290
 * Size:	0001AC
 */
// void Matrix4f::makeConcatSRT(Matrix4f *, Matrix4f &, SRT &)
//{
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
  mr        r31, r6
  stw       r30, 0x38(r1)
  addi      r30, r5, 0
  stw       r29, 0x34(r1)
  addi      r29, r4, 0
  stw       r28, 0x30(r1)
  addi      r28, r3, 0
  lfs       f1, 0xC(r6)
  bl        0x1DDA14
  fmr       f28, f1
  lfs       f1, 0x10(r31)
  bl        0x1DDA08
  fmr       f29, f1
  lfs       f1, 0x14(r31)
  bl        0x1DD9FC
  fmr       f27, f1
  lfs       f1, 0xC(r31)
  bl        0x1DD85C
  fmr       f30, f1
  lfs       f1, 0x10(r31)
  bl        0x1DD850
  fmr       f31, f1
  lfs       f1, 0x14(r31)
  bl        0x1DD844
  fmuls     f0, f31, f1
  lfs       f2, 0x0(r31)
  fmuls     f4, f28, f29
  mr        r3, r29
  fmuls     f9, f30, f27
  fmuls     f0, f2, f0
  mr        r4, r30
  fmuls     f2, f4, f1
  mr        r5, r28
  fmuls     f8, f30, f1
  stfs      f0, 0x0(r30)
  fmuls     f3, f31, f27
  fmuls     f0, f4, f27
  lfs       f4, 0x0(r31)
  fneg      f7, f29
  fsubs     f6, f2, f9
  fmuls     f2, f4, f3
  fadds     f5, f8, f0
  fmuls     f4, f28, f31
  stfs      f2, 0x10(r30)
  fmuls     f3, f8, f29
  fmuls     f0, f28, f27
  lfs       f8, 0x0(r31)
  fmuls     f2, f9, f29
  fmuls     f7, f8, f7
  fmuls     f1, f28, f1
  fadds     f3, f3, f0
  stfs      f7, 0x20(r30)
  fmuls     f0, f30, f31
  fsubs     f1, f2, f1
  lfs       f2, 0x4(r31)
  fmuls     f2, f2, f6
  stfs      f2, 0x4(r30)
  lfs       f2, 0x4(r31)
  fmuls     f2, f2, f5
  stfs      f2, 0x14(r30)
  lfs       f2, 0x4(r31)
  fmuls     f2, f2, f4
  stfs      f2, 0x24(r30)
  lfs       f2, 0x8(r31)
  fmuls     f2, f2, f3
  stfs      f2, 0x8(r30)
  lfs       f2, 0x8(r31)
  fmuls     f1, f2, f1
  stfs      f1, 0x18(r30)
  lfs       f1, 0x8(r31)
  fmuls     f0, f1, f0
  stfs      f0, 0x28(r30)
  lfs       f0, 0x18(r31)
  stfs      f0, 0xC(r30)
  lfs       f0, 0x1C(r31)
  stfs      f0, 0x1C(r30)
  lfs       f0, 0x20(r31)
  stfs      f0, 0x2C(r30)
  lfs       f0, -0x7C1C(r2)
  stfs      f0, 0x30(r30)
  stfs      f0, 0x34(r30)
  stfs      f0, 0x38(r30)
  lfs       f0, -0x7C20(r2)
  stfs      f0, 0x3C(r30)
  bl        0x1BF7BC
  lwz       r0, 0x6C(r1)
  lfd       f31, 0x60(r1)
  lfd       f30, 0x58(r1)
  lfd       f29, 0x50(r1)
  lfd       f28, 0x48(r1)
  lfd       f27, 0x40(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  lwz       r29, 0x34(r1)
  lwz       r28, 0x30(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
//}

/*
 * --INFO--
 * Address:	8003E43C
 * Size:	000380
 */
// void Matrix4f::inverse(Matrix4f *)
//{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stw       r31, 0x5C(r1)
  addi      r31, r4, 0
  stw       r30, 0x58(r1)
  stw       r29, 0x54(r1)
  addi      r29, r3, 0
  cmplw     r31, r29
  bne-      .loc_0x30
  addi      r30, r1, 0x10
  b         .loc_0x34

.loc_0x30:
  mr        r30, r31

.loc_0x34:
  lfs       f11, 0x0(r29)
  lfs       f6, 0x14(r29)
  lfs       f12, 0x18(r29)
  lfs       f5, 0x4(r29)
  fmuls     f1, f11, f6
  lfs       f8, 0x10(r29)
  lfs       f9, 0x28(r29)
  fmuls     f0, f5, f12
  lfs       f2, 0x20(r29)
  lfs       f7, 0x8(r29)
  fmuls     f4, f9, f1
  fmuls     f1, f2, f0
  lfs       f10, 0x24(r29)
  fmuls     f0, f7, f8
  fmuls     f3, f2, f6
  fmuls     f2, f8, f5
  fmuls     f5, f10, f0
  lfs       f0, -0x7C1C(r2)
  fadds     f4, f4, f1
  fmuls     f1, f11, f10
  fmuls     f3, f7, f3
  fadds     f4, f5, f4
  fmuls     f2, f9, f2
  fmuls     f1, f12, f1
  fsubs     f3, f4, f3
  fsubs     f2, f3, f2
  fsubs     f3, f2, f1
  fcmpu     cr0, f0, f3
  bne-      .loc_0xD8
  mr        r3, r30
  bl        -0x72C
  lfs       f0, 0xC(r29)
  fneg      f0, f0
  stfs      f0, 0xC(r30)
  lfs       f0, 0x1C(r29)
  fneg      f0, f0
  stfs      f0, 0x1C(r30)
  lfs       f0, 0x2C(r29)
  fneg      f0, f0
  stfs      f0, 0x2C(r30)
  b         .loc_0x2C0

.loc_0xD8:
  lfs       f0, -0x7C20(r2)
  fmuls     f2, f6, f9
  fmuls     f1, f10, f12
  fdivs     f0, f0, f3
  fsubs     f1, f2, f1
  fmuls     f1, f0, f1
  stfs      f1, 0x0(r30)
  lfs       f4, 0x4(r29)
  lfs       f3, 0x28(r29)
  lfs       f2, 0x24(r29)
  lfs       f1, 0x8(r29)
  fmuls     f3, f4, f3
  fmuls     f1, f2, f1
  fsubs     f1, f3, f1
  fneg      f1, f1
  fmuls     f1, f0, f1
  stfs      f1, 0x4(r30)
  lfs       f4, 0x4(r29)
  lfs       f3, 0x18(r29)
  lfs       f2, 0x14(r29)
  lfs       f1, 0x8(r29)
  fmuls     f3, f4, f3
  fmuls     f1, f2, f1
  fsubs     f1, f3, f1
  fmuls     f1, f0, f1
  stfs      f1, 0x8(r30)
  lfs       f4, 0x10(r29)
  lfs       f3, 0x28(r29)
  lfs       f2, 0x20(r29)
  lfs       f1, 0x18(r29)
  fmuls     f3, f4, f3
  fmuls     f1, f2, f1
  fsubs     f1, f3, f1
  fneg      f1, f1
  fmuls     f1, f0, f1
  stfs      f1, 0x10(r30)
  lfs       f4, 0x0(r29)
  lfs       f3, 0x28(r29)
  lfs       f2, 0x20(r29)
  lfs       f1, 0x8(r29)
  fmuls     f3, f4, f3
  fmuls     f1, f2, f1
  fsubs     f1, f3, f1
  fmuls     f1, f0, f1
  stfs      f1, 0x14(r30)
  lfs       f4, 0x0(r29)
  lfs       f3, 0x18(r29)
  lfs       f2, 0x10(r29)
  lfs       f1, 0x8(r29)
  fmuls     f3, f4, f3
  fmuls     f1, f2, f1
  fsubs     f1, f3, f1
  fneg      f1, f1
  fmuls     f1, f0, f1
  stfs      f1, 0x18(r30)
  lfs       f4, 0x10(r29)
  lfs       f3, 0x24(r29)
  lfs       f2, 0x20(r29)
  lfs       f1, 0x14(r29)
  fmuls     f3, f4, f3
  fmuls     f1, f2, f1
  fsubs     f1, f3, f1
  fmuls     f1, f0, f1
  stfs      f1, 0x20(r30)
  lfs       f4, 0x0(r29)
  lfs       f3, 0x24(r29)
  lfs       f2, 0x20(r29)
  lfs       f1, 0x4(r29)
  fmuls     f3, f4, f3
  fmuls     f1, f2, f1
  fsubs     f1, f3, f1
  fneg      f1, f1
  fmuls     f1, f0, f1
  stfs      f1, 0x24(r30)
  lfs       f4, 0x0(r29)
  lfs       f3, 0x14(r29)
  lfs       f2, 0x10(r29)
  lfs       f1, 0x4(r29)
  fmuls     f3, f4, f3
  fmuls     f1, f2, f1
  fsubs     f1, f3, f1
  fmuls     f0, f0, f1
  stfs      f0, 0x28(r30)
  lfs       f0, 0x0(r30)
  lfs       f4, 0xC(r29)
  fneg      f5, f0
  lfs       f3, 0x4(r30)
  lfs       f2, 0x1C(r29)
  lfs       f1, 0x8(r30)
  lfs       f0, 0x2C(r29)
  fmuls     f4, f5, f4
  fmuls     f2, f3, f2
  fmuls     f0, f1, f0
  fsubs     f1, f4, f2
  fsubs     f0, f1, f0
  stfs      f0, 0xC(r30)
  lfs       f0, 0x10(r30)
  lfs       f4, 0xC(r29)
  fneg      f5, f0
  lfs       f3, 0x14(r30)
  lfs       f2, 0x1C(r29)
  lfs       f1, 0x18(r30)
  lfs       f0, 0x2C(r29)
  fmuls     f4, f5, f4
  fmuls     f2, f3, f2
  fmuls     f0, f1, f0
  fsubs     f1, f4, f2
  fsubs     f0, f1, f0
  stfs      f0, 0x1C(r30)
  lfs       f0, 0x20(r30)
  lfs       f3, 0xC(r29)
  fneg      f4, f0
  lfs       f2, 0x24(r30)
  lfs       f0, 0x1C(r29)
  lfs       f1, 0x28(r30)
  fmuls     f3, f4, f3
  fmuls     f2, f2, f0
  lfs       f0, 0x2C(r29)
  fmuls     f0, f1, f0
  fsubs     f1, f3, f2
  fsubs     f0, f1, f0
  stfs      f0, 0x2C(r30)

.loc_0x2C0:
  lfs       f0, -0x7C1C(r2)
  addi      r0, r1, 0x10
  cmplw     r30, r0
  stfs      f0, 0x30(r30)
  stfs      f0, 0x34(r30)
  stfs      f0, 0x38(r30)
  lfs       f0, -0x7C20(r2)
  stfs      f0, 0x3C(r30)
  bne-      .loc_0x364
  lwz       r3, 0x10(r1)
  lwz       r0, 0x14(r1)
  stw       r3, 0x0(r31)
  stw       r0, 0x4(r31)
  lwz       r3, 0x18(r1)
  lwz       r0, 0x1C(r1)
  stw       r3, 0x8(r31)
  stw       r0, 0xC(r31)
  lwz       r3, 0x20(r1)
  lwz       r0, 0x24(r1)
  stw       r3, 0x10(r31)
  stw       r0, 0x14(r31)
  lwz       r3, 0x28(r1)
  lwz       r0, 0x2C(r1)
  stw       r3, 0x18(r31)
  stw       r0, 0x1C(r31)
  lwz       r3, 0x30(r1)
  lwz       r0, 0x34(r1)
  stw       r3, 0x20(r31)
  stw       r0, 0x24(r31)
  lwz       r3, 0x38(r1)
  lwz       r0, 0x3C(r1)
  stw       r3, 0x28(r31)
  stw       r0, 0x2C(r31)
  lwz       r3, 0x40(r1)
  lwz       r0, 0x44(r1)
  stw       r3, 0x30(r31)
  stw       r0, 0x34(r31)
  lwz       r3, 0x48(r1)
  lwz       r0, 0x4C(r1)
  stw       r3, 0x38(r31)
  stw       r0, 0x3C(r31)

.loc_0x364:
  lwz       r0, 0x64(r1)
  lwz       r31, 0x5C(r1)
  lwz       r30, 0x58(r1)
  lwz       r29, 0x54(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
//}

/*
 * --INFO--
 * Address:	........
 * Size:	000244
 */
/*
void Matrix4f::makeAligned(Vector3f &, float)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
/*
void Matrix4f::rotateX(float)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
/*
void Matrix4f::rotateY(float)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
/*
void Matrix4f::rotateZ(float)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
/*
void Matrix4f::translate(float, float, float)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	8003E7BC
 * Size:	0000C4
 */
// void Matrix4f::scale(Vector3f &)
//{
/*
.loc_0x0:
  lfs       f1, 0x0(r3)
  lfs       f0, 0x0(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x0(r3)
  lfs       f1, 0x10(r3)
  lfs       f0, 0x0(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x10(r3)
  lfs       f1, 0x20(r3)
  lfs       f0, 0x0(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x20(r3)
  lfs       f1, 0x30(r3)
  lfs       f0, 0x0(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x30(r3)
  lfs       f1, 0x4(r3)
  lfs       f0, 0x4(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x4(r3)
  lfs       f1, 0x14(r3)
  lfs       f0, 0x4(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x14(r3)
  lfs       f1, 0x24(r3)
  lfs       f0, 0x4(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x24(r3)
  lfs       f1, 0x34(r3)
  lfs       f0, 0x4(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x34(r3)
  lfs       f1, 0x8(r3)
  lfs       f0, 0x8(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x8(r3)
  lfs       f1, 0x18(r3)
  lfs       f0, 0x8(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x18(r3)
  lfs       f1, 0x28(r3)
  lfs       f0, 0x8(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x28(r3)
  lfs       f1, 0x38(r3)
  lfs       f0, 0x8(r4)
  fmuls     f0, f1, f0
  stfs      f0, 0x38(r3)
  blr
*/
//}

/*
 * --INFO--
 * Address:	........
 * Size:	0003C0
 */
/*
void Matrix4f::makeLookfrom(Vector3f &, Vector3f &)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	8003E880
 * Size:	000300
 */
// void Matrix4f::makeLookat(Vector3f &, Vector3f &, Vector3f *)
//{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x90(r1)
  stw       r31, 0x8C(r1)
  mr        r31, r6
  stw       r30, 0x88(r1)
  addi      r30, r4, 0
  stw       r29, 0x84(r1)
  addi      r29, r3, 0
  lfs       f0, -0x7C1C(r2)
  stfs      f0, 0x7C(r1)
  stfs      f0, 0x78(r1)
  stfs      f0, 0x74(r1)
  stfs      f0, 0x70(r1)
  stfs      f0, 0x6C(r1)
  stfs      f0, 0x68(r1)
  stfs      f0, 0x64(r1)
  stfs      f0, 0x60(r1)
  stfs      f0, 0x5C(r1)
  lfs       f1, 0x0(r4)
  lfs       f0, 0x0(r5)
  fsubs     f0, f1, f0
  stfs      f0, 0x74(r1)
  lfs       f1, 0x4(r4)
  lfs       f0, 0x4(r5)
  fsubs     f0, f1, f0
  stfs      f0, 0x78(r1)
  lfs       f1, 0x8(r4)
  lfs       f0, 0x8(r5)
  fsubs     f0, f1, f0
  stfs      f0, 0x7C(r1)
  lfs       f1, 0x74(r1)
  lfs       f0, 0x78(r1)
  lfs       f2, 0x7C(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x30CDC
  lfs       f0, -0x7C1C(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xD0
  lfs       f0, 0x74(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x74(r1)
  lfs       f0, 0x78(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x78(r1)
  lfs       f0, 0x7C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x7C(r1)

.loc_0xD0:
  cmplwi    r31, 0
  beq-      .loc_0x1A8
  lwz       r3, 0x0(r31)
  lwz       r0, 0x4(r31)
  lfs       f5, 0x74(r1)
  stw       r3, 0x5C(r1)
  stw       r0, 0x60(r1)
  lwz       r0, 0x8(r31)
  stw       r0, 0x64(r1)
  lwz       r0, 0x5C(r1)
  lwz       r3, 0x60(r1)
  stw       r0, 0x68(r1)
  lwz       r0, 0x64(r1)
  stw       r3, 0x6C(r1)
  stw       r0, 0x70(r1)
  lfs       f0, 0x70(r1)
  lfs       f6, 0x78(r1)
  lfs       f7, 0x6C(r1)
  fmuls     f4, f0, f5
  lfs       f3, 0x7C(r1)
  fmuls     f0, f0, f6
  lfs       f2, 0x68(r1)
  fmuls     f1, f7, f3
  fmuls     f3, f2, f3
  fmuls     f2, f2, f6
  fsubs     f0, f1, f0
  fmuls     f1, f7, f5
  fsubs     f3, f4, f3
  stfs      f0, 0x68(r1)
  fsubs     f0, f2, f1
  stfs      f3, 0x6C(r1)
  stfs      f0, 0x70(r1)
  lfs       f1, 0x68(r1)
  lfs       f0, 0x6C(r1)
  lfs       f2, 0x70(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x30DB0
  lfs       f0, -0x7C1C(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x2CC
  lfs       f0, 0x68(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x68(r1)
  lfs       f0, 0x6C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x6C(r1)
  lfs       f0, 0x70(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x70(r1)
  b         .loc_0x2CC

.loc_0x1A8:
  lfs       f1, 0x7C(r1)
  lfs       f0, -0x7A10(r13)
  stfs      f1, 0x68(r1)
  stfs      f0, 0x6C(r1)
  lfs       f0, 0x74(r1)
  fneg      f0, f0
  stfs      f0, 0x70(r1)
  lfs       f1, 0x68(r1)
  lfs       f0, 0x6C(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x70(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x30E24
  lfs       f0, -0x7C1C(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x218
  lfs       f0, 0x68(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x68(r1)
  lfs       f0, 0x6C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x6C(r1)
  lfs       f0, 0x70(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x70(r1)

.loc_0x218:
  lwz       r0, 0x74(r1)
  lwz       r3, 0x78(r1)
  stw       r0, 0x5C(r1)
  lwz       r0, 0x7C(r1)
  stw       r3, 0x60(r1)
  lfs       f5, 0x68(r1)
  stw       r0, 0x64(r1)
  lfs       f0, 0x64(r1)
  lfs       f6, 0x6C(r1)
  lfs       f7, 0x60(r1)
  fmuls     f4, f0, f5
  lfs       f3, 0x70(r1)
  fmuls     f0, f0, f6
  lfs       f2, 0x5C(r1)
  fmuls     f1, f7, f3
  fmuls     f3, f2, f3
  fmuls     f2, f2, f6
  fsubs     f0, f1, f0
  fmuls     f1, f7, f5
  fsubs     f3, f4, f3
  stfs      f0, 0x5C(r1)
  fsubs     f0, f2, f1
  stfs      f3, 0x60(r1)
  stfs      f0, 0x64(r1)
  lfs       f1, 0x5C(r1)
  lfs       f0, 0x60(r1)
  lfs       f2, 0x64(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x30ED8
  lfs       f0, -0x7C1C(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x2CC
  lfs       f0, 0x5C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x5C(r1)
  lfs       f0, 0x60(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x60(r1)
  lfs       f0, 0x64(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x64(r1)

.loc_0x2CC:
  addi      r3, r29, 0
  addi      r4, r30, 0
  addi      r5, r1, 0x68
  addi      r6, r1, 0x5C
  addi      r7, r1, 0x74
  bl        .loc_0x300
  lwz       r0, 0x94(r1)
  lwz       r31, 0x8C(r1)
  lwz       r30, 0x88(r1)
  lwz       r29, 0x84(r1)
  addi      r1, r1, 0x90
  mtlr      r0
  blr

.loc_0x300:
*/
//}

/*
 * --INFO--
 * Address:	8003EB80
 * Size:	000100
 */
// void Matrix4f::makeLookat(Vector3f &, Vector3f &, Vector3f &, Vector3f &)
//{
/*
.loc_0x0:
  lfs       f0, 0x0(r5)
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r5)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r5)
  stfs      f0, 0x8(r3)
  lfs       f3, 0x0(r4)
  lfs       f2, 0x0(r5)
  lfs       f1, 0x4(r4)
  lfs       f0, 0x4(r5)
  fmuls     f2, f3, f2
  lfs       f3, 0x8(r4)
  fmuls     f0, f1, f0
  lfs       f1, 0x8(r5)
  fmuls     f1, f3, f1
  fadds     f0, f2, f0
  fadds     f0, f1, f0
  fneg      f0, f0
  stfs      f0, 0xC(r3)
  lfs       f0, 0x0(r6)
  stfs      f0, 0x10(r3)
  lfs       f0, 0x4(r6)
  stfs      f0, 0x14(r3)
  lfs       f0, 0x8(r6)
  stfs      f0, 0x18(r3)
  lfs       f3, 0x0(r4)
  lfs       f2, 0x0(r6)
  lfs       f1, 0x4(r4)
  lfs       f0, 0x4(r6)
  fmuls     f2, f3, f2
  lfs       f3, 0x8(r4)
  fmuls     f0, f1, f0
  lfs       f1, 0x8(r6)
  fmuls     f1, f3, f1
  fadds     f0, f2, f0
  fadds     f0, f1, f0
  fneg      f0, f0
  stfs      f0, 0x1C(r3)
  lfs       f0, 0x0(r7)
  stfs      f0, 0x20(r3)
  lfs       f0, 0x4(r7)
  stfs      f0, 0x24(r3)
  lfs       f0, 0x8(r7)
  stfs      f0, 0x28(r3)
  lfs       f3, 0x0(r4)
  lfs       f2, 0x0(r7)
  lfs       f1, 0x4(r4)
  lfs       f0, 0x4(r7)
  fmuls     f2, f3, f2
  lfs       f3, 0x8(r4)
  fmuls     f0, f1, f0
  lfs       f1, 0x8(r7)
  fmuls     f1, f3, f1
  fadds     f0, f2, f0
  fadds     f0, f1, f0
  fneg      f0, f0
  stfs      f0, 0x2C(r3)
  lfs       f0, -0x7C1C(r2)
  stfs      f0, 0x30(r3)
  stfs      f0, 0x34(r3)
  stfs      f0, 0x38(r3)
  lfs       f0, -0x7C20(r2)
  stfs      f0, 0x3C(r3)
  blr
*/
//}

/*
 * --INFO--
 * Address:	........
 * Size:	000164
 */
/*
void Matrix4f::makeProjection(Vector3f &, Plane &)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
/*
void Matrix4f::makeReflection(Plane &)
{
    // UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	8003EC80
 * Size:	000084
 */
// void Matrix4f::transposeTo(Matrix4f &)
//{
/*
.loc_0x0:
  lfs       f0, 0x0(r3)
  stfs      f0, 0x0(r4)
  lfs       f0, 0x10(r3)
  stfs      f0, 0x4(r4)
  lfs       f0, 0x20(r3)
  stfs      f0, 0x8(r4)
  lfs       f0, 0x30(r3)
  stfs      f0, 0xC(r4)
  lfs       f0, 0x4(r3)
  stfs      f0, 0x10(r4)
  lfs       f0, 0x14(r3)
  stfs      f0, 0x14(r4)
  lfs       f0, 0x24(r3)
  stfs      f0, 0x18(r4)
  lfs       f0, 0x34(r3)
  stfs      f0, 0x1C(r4)
  lfs       f0, 0x8(r3)
  stfs      f0, 0x20(r4)
  lfs       f0, 0x18(r3)
  stfs      f0, 0x24(r4)
  lfs       f0, 0x28(r3)
  stfs      f0, 0x28(r4)
  lfs       f0, 0x38(r3)
  stfs      f0, 0x2C(r4)
  lfs       f0, 0xC(r3)
  stfs      f0, 0x30(r4)
  lfs       f0, 0x1C(r3)
  stfs      f0, 0x34(r4)
  lfs       f0, 0x2C(r3)
  stfs      f0, 0x38(r4)
  lfs       f0, 0x3C(r3)
  stfs      f0, 0x3C(r4)
  blr
*/
//}

/*
 * --INFO--
 * Address:	8003ED04
 * Size:	00012C
 */
// void Matrix4f::makeVQS(Vector3f &, Quat &, Vector3f &)
//{
/*
.loc_0x0:
  stwu      r1, -0x28(r1)
  stfd      f31, 0x20(r1)
  stfd      f30, 0x18(r1)
  lfs       f3, 0x4(r5)
  lfs       f2, -0x7C18(r2)
  lfs       f6, 0x8(r5)
  fmuls     f9, f2, f3
  lfs       f0, 0xC(r5)
  fmuls     f1, f2, f6
  lfs       f8, 0x0(r5)
  fmuls     f10, f2, f0
  fmuls     f12, f9, f3
  lfs       f7, -0x7C20(r2)
  fmuls     f13, f1, f6
  lfs       f1, 0x0(r6)
  fmuls     f4, f2, f8
  fsubs     f0, f7, f12
  fmuls     f2, f4, f8
  fmuls     f5, f4, f3
  fsubs     f0, f0, f13
  fmuls     f30, f10, f6
  fsubs     f11, f7, f2
  fmuls     f0, f1, f0
  fsubs     f1, f5, f30
  fmuls     f31, f4, f6
  stfs      f0, 0x0(r3)
  fmuls     f3, f10, f3
  fmuls     f9, f9, f6
  lfs       f2, 0x4(r6)
  fadds     f0, f31, f3
  fmuls     f1, f2, f1
  fadds     f5, f5, f30
  fsubs     f4, f11, f13
  stfs      f1, 0x4(r3)
  fmuls     f8, f10, f8
  fsubs     f2, f31, f3
  lfs       f1, 0x8(r6)
  fsubs     f3, f9, f8
  fmuls     f6, f1, f0
  fadds     f1, f9, f8
  fsubs     f0, f11, f12
  stfs      f6, 0x8(r3)
  lfs       f6, 0x0(r6)
  fmuls     f5, f6, f5
  stfs      f5, 0x10(r3)
  lfs       f5, 0x4(r6)
  fmuls     f4, f5, f4
  stfs      f4, 0x14(r3)
  lfs       f4, 0x8(r6)
  fmuls     f3, f4, f3
  stfs      f3, 0x18(r3)
  lfs       f3, 0x0(r6)
  fmuls     f2, f3, f2
  stfs      f2, 0x20(r3)
  lfs       f2, 0x4(r6)
  fmuls     f1, f2, f1
  stfs      f1, 0x24(r3)
  lfs       f1, 0x8(r6)
  fmuls     f0, f1, f0
  stfs      f0, 0x28(r3)
  lfs       f0, 0x0(r4)
  stfs      f0, 0xC(r3)
  lfs       f0, 0x4(r4)
  stfs      f0, 0x1C(r3)
  lfs       f0, 0x8(r4)
  stfs      f0, 0x2C(r3)
  lfs       f0, -0x7C1C(r2)
  stfs      f0, 0x30(r3)
  stfs      f0, 0x34(r3)
  stfs      f0, 0x38(r3)
  stfs      f7, 0x3C(r3)
  lfd       f31, 0x20(r1)
  lfd       f30, 0x18(r1)
  addi      r1, r1, 0x28
  blr
*/
//}

/*
 * --INFO--
 * Address:	8003EE30
 * Size:	000004
 */
// void __sinit_matMath_cpp(void)
//{
//	return;
//}
