#include "nlib/Geometry.h"
#include "nlib/Math.h"
#include "Vector.h"

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
NAxisAngle4f::NAxisAngle4f(NVector3f& p1, f32 p2) { construct(p1, p2); }

/*
 * --INFO--
 * Address:	8011BCD8
 * Size:	000020
 */
void NAxisAngle4f::construct(NVector3f& p1, f32 p2)
{
	_00.input(p1);
	_0C = p2;
}

/*
 * --INFO--
 * Address:	8011BCF8
 * Size:	000080
 */
NMatrix4f::NMatrix4f() { input(NMatrix4f(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f)); }

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NMatrix4f::NMatrix4f(Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BD78
 * Size:	000020
 */
void NMatrix4f::construct(Matrix4f& mat) { input(mat); }

/*
 * --INFO--
 * Address:	8011BD98
 * Size:	000070
 */
NMatrix4f::NMatrix4f(f32 x00, f32 x01, f32 x02, f32 x03, f32 x10, f32 x11, f32 x12, f32 x13, f32 x20, f32 x21, f32 x22, f32 x23, f32 x30,
                     f32 x31, f32 x32, f32 x33)
{
	set(x00, x01, x02, x03, x10, x11, x12, x13, x20, x21, x22, x23, x30, x31, x32, x33);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void NMatrix4f::construct(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NMatrix4f::NMatrix4f(Mtx)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NMatrix4f::construct(Mtx)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NMatrix4f::input(Mtx)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NMatrix4f::output(Mtx)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BE08
 * Size:	000090
 */
void NMatrix4f::input(Matrix4f& mat) { NMathf::copyArray44(this->mMtx, mat.mMtx); }

/*
 * --INFO--
 * Address:	8011BE98
 * Size:	00006C
 */
void NMatrix4f::set(f32 x00, f32 x01, f32 x02, f32 x03, f32 x10, f32 x11, f32 x12, f32 x13, f32 x20, f32 x21, f32 x22, f32 x23, f32 x30,
                    f32 x31, f32 x32, f32 x33)
{
	mMtx[0][0] = x00;
	mMtx[0][1] = x01;
	mMtx[0][2] = x02;
	mMtx[0][3] = x03;

	mMtx[1][0] = x10;
	mMtx[1][1] = x11;
	mMtx[1][2] = x12;
	mMtx[1][3] = x13;

	mMtx[2][0] = x20;
	mMtx[2][1] = x21;
	mMtx[2][2] = x22;
	mMtx[2][3] = x23;

	mMtx[3][0] = x30;
	mMtx[3][1] = x31;
	mMtx[3][2] = x32;
	mMtx[3][3] = x33;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void NMatrix4f::setRow(int row, f32 x, f32 y, f32 z)
{
	mMtx[row][0] = x;
	mMtx[row][1] = y;
	mMtx[row][2] = z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NMatrix4f::inputRow(int, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NMatrix4f::inputRow(int, Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NMatrix4f::outputRow(int, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void NMatrix4f::inputRows(NVector3f&, NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void NMatrix4f::setCol(int, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NMatrix4f::inputCol(int col, Vector3f& input)
{
	mMtx[0][col] = input.x;
	mMtx[1][col] = input.y;
	mMtx[2][col] = input.z;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NMatrix4f::inputCol(int, Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BF04
 * Size:	000024
 */
void NMatrix4f::outputCol(int col, Vector3f& output)
{
	output.x = mMtx[0][col];
	output.y = mMtx[1][col];
	output.z = mMtx[2][col];
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void NMatrix4f::inputCols(NVector3f&, NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NMatrix4f::mul(Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NMatrix4f::mul2(Matrix4f&, Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void NMatrix4f::scale(f32)
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
void NMatrix4f::makeIdentRow(int row)
{
	setRow(row, 0.0f, 0.0f, 0.0f);
	mMtx[row][3] = 1.0f;
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
NOrientation::NOrientation(Vector3f& p1) { construct(p1); }

/*
 * --INFO--
 * Address:	8011BF9C
 * Size:	000078
 */
void NOrientation::construct(Vector3f& p1)
{
	NVector3f vert(0.0f, 1.0f, 0.0f);
	_00.input(p1);
	_0C.input(vert);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
NOrientation::NOrientation(Vector3f&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NOrientation::construct(Vector3f&, Vector3f&)
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
	if (_0C.isParallel(_00)) {
		makeUp();
	}

	NVector3f left;
	outputLeft(left);

	NTransform3D transform;

	transform.inputAxisAngle(NAxisAngle4f(left, NMathF::pi * 0.5f));
	_0C.input(_00);
	transform.transform(_0C);
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
void NOrientation::transform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NOrientation::outputRight(NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C0E8
 * Size:	00004C
 */
void NOrientation::outputLeft(NVector3f&)
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
 * Address:	........
 * Size:	000124
 */
void NOrientation::outputTransform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void NOrientation::inputTransform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void NOrientation::outputRotation(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NOrientation::inputRotation(NTransform3D&)
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
NPolar3f::NPolar3f() { set(1.0f, 0.0f, 0.0f); }

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NPolar3f::NPolar3f(f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NPolar3f::construct(f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NPolar3f::NPolar3f(NPolar3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void NPolar3f::construct(NPolar3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C3E0
 * Size:	000030
 */
NPolar3f::NPolar3f(Vector3f& point) { construct(point); }

/*
 * --INFO--
 * Address:	8011C410
 * Size:	000020
 */
void NPolar3f::construct(Vector3f& point) { input(point); }

/*
 * --INFO--
 * Address:	8011C430
 * Size:	000010
 */
void NPolar3f::set(f32 p1, f32 p2, f32 p3)
{
	_00 = p1;
	_04 = p2;
	_08 = p3;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void NPolar3f::input(NPolar3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C440
 * Size:	0000A8
 */
void NPolar3f::input(Vector3f& point)
{
	set(point.length(), NMathF::atan2(point.length2D(), point.y), NMathF::atan2(point.x, point.z));
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
void NPolar3f::output(Vector3f&)
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
f32 NMathF::roundAngle(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NPolar3f::interpolate(NPolar3f&, NPolar3f&, f32)
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
void NPolar3f::clampMeridian(f32)
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
NPosture2D::NPosture2D(Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NPosture2D::construct(Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void NPosture2D::outputTransform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void NPosture2D::outputInverseTransform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void NPosture2D::outputAxisAngle(NAxisAngle4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C58C
 * Size:	000094
 */
void NPosture2D::readData(Stream& input)
{
	_04 = input.readFloat();
	_08 = input.readFloat();
	_0C = input.readFloat();
	_10 = input.readFloat();
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
	NVector3f vec1(0.0f, 0.0f, 0.0f);
	_04.set(vec1);
	NVector3f vec2(0.0f, 0.0f, 1.0f);
	_10.set(vec2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
NPosture3D::NPosture3D(NPosture3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void NPosture3D::construct(NPosture3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C6C0
 * Size:	000070
 */
NPosture3D::NPosture3D(Vector3f& p1, Vector3f& p2) { construct(p1, p2); }

/*
 * --INFO--
 * Address:	8011C730
 * Size:	000034
 */
void NPosture3D::construct(Vector3f& p1, Vector3f& p2)
{
	_04.set(p1);
	_10.set(p2);
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
void NPosture3D::outputRelative(NVector3f&)
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
void NPosture3D::outputUnitVector(NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NPosture3D::transform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C86C
 * Size:	000064
 */
void NPosture3D::translate(Vector3f&)
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
void NPosture3D::rotate(NVector3f&, NPolar3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001CC
 */
void NPosture3D::rotatePoint(NVector3f&, NVector3f&, NPolar3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void NPosture3D::interpolate(NPosture3D&, NPosture3D&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void NPosture3D::input(NPosture2D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void NPosture3D::output(NPosture2D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void NPosture3D::outputTransform(NPosture3D&, NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002A0
 */
void NPosture3D::outputTransform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000418
 */
void NPosture3D::outputInverseTransform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void NPosture3D::inputTransform(NTransform3D&)
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
void NPosture3D::readData(Stream&)
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
NLowerMatrix::NLowerMatrix(f32* p1, int p2)
    : NSpecialMatrix(p2)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void NLowerMatrix::construct(f32*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void NLowerMatrix::solve(NVector&, NVector&)
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
NUpperMatrix::NUpperMatrix(f32* p1, f32* p2, int p3)
    : NSpecialMatrix(p3)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void NUpperMatrix::construct(f32*, f32*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void NUpperMatrix::solve(NVector&, NVector&)
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
LUMatrix::LUMatrix(f32*, f32*, f32*, int p4)
    : NSpecialMatrix(p4)
    , _08(p4)
    , _14(p4)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void LUMatrix::construct(f32*, f32*, f32*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011C994
 * Size:	000064
 */
void LUMatrix::setDimension(int dim)
{
	mDimension = dim;
	_08.setDimension(dim);
	_14.setDimension(dim);
}

/*
 * --INFO--
 * Address:	8011C9F8
 * Size:	000008
 */
void NSpecialMatrix::setDimension(int dim) { mDimension = dim; }

/*
 * --INFO--
 * Address:	........
 * Size:	00022C
 */
void LUMatrix::solve(NVector&, NVector&)
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
NTransform3D::NTransform3D() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
NTransform3D::NTransform3D(NMatrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NTransform3D::construct(NMatrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NTransform3D::translate(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CB08
 * Size:	00019C
 */
void NTransform3D::rotate(Vector3f&)
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
void NTransform3D::transform(Vector3f&)
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
void NTransform3D::transform(Vector3f&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000184
 */
void NTransform3D::transform(NVector&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00018C
 */
void NTransform3D::transform(NVector&, NVector&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void NTransform3D::inputVector(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CCD0
 * Size:	000024
 */
void NTransform3D::inputAxisAngle(NAxisAngle4f&)
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
void NTransform3D::inputTranslation(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void NTransform3D::outputTranslation(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NTransform3D::inputRotation(Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CCF4
 * Size:	0000CC
 */
void NTransform3D::outputRotation(Matrix4f&)
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
void NTransform3D::inputRotation(NAxisAngle4f&)
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
	mValues = nullptr;
	mSize   = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NVector::NVector(f32* values, int size) { construct(values, size); }

/*
 * --INFO--
 * Address:	8011CDD0
 * Size:	000028
 */
void NVector::construct(f32* values, int size)
{
	mValues = values;
	mSize   = size;
	makeZero();
}

/*
 * --INFO--
 * Address:	8011CDF8
 * Size:	000030
 */
void NVector::makeZero()
{
	for (int i = 0; i < mSize; i++) {
		mValues[i] = 0.0f;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NVector::add(NVector&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000118
 */
void NVector::dot(NVector&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NVector::input(NVector&)
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
void NVector3f::printVector3f(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CE28
 * Size:	00002C
 */
void NVector3f::printlnVector3f(Vector3f&)
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
NVector3f::NVector3f() { set(0.0f, 0.0f, 0.0f); }

/*
 * --INFO--
 * Address:	8011CE80
 * Size:	000040
 */
NVector3f::NVector3f(Vector3f& vec) { construct(vec); }

/*
 * --INFO--
 * Address:	8011CEC0
 * Size:	00001C
 */
void NVector3f::construct(Vector3f& vec) { input(vec); }

/*
 * --INFO--
 * Address:	8011CEDC
 * Size:	000040
 */
NVector3f::NVector3f(f32 x, f32 y, f32 z) { construct(x, y, z); }

/*
 * --INFO--
 * Address:	8011CF1C
 * Size:	000010
 */
void NVector3f::construct(f32 x, f32 y, f32 z) { set(x, y, z); }

/*
 * --INFO--
 * Address:	8011CF2C
 * Size:	000040
 */
NVector3f::NVector3f(Vector3f& start, Vector3f& end) { construct(start, end); }

/*
 * --INFO--
 * Address:	8011CF6C
 * Size:	000034
 */
void NVector3f::construct(Vector3f& start, Vector3f& end) { set(end.x - start.x, end.y - start.y, end.z - start.z); }

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NVector3f::interpolate(Vector3f&, Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
bool NVector3f::isZero()
{
	return (NMathf::absolute(x) != 0.0f && NMathf::absolute(y) != 0.0f && NMathf::absolute(z) != 0.0f);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void NVector3f::equals(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void NVector3f::isVertical(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011CFA0
 * Size:	000074
 */
bool NVector3f::isParallel(Vector3f& vec)
{
	return NMathf::absolute(NMathf::absolute(x * vec.x + y * vec.y + z * vec.z) - 1.0f) <= NMathF::error;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000144
 */
void NVector3f::makeUnitVector(Vector3f&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void NVector3f::outputQuat(f32, Quat&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void NVector3f::calcAngle(NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void NVector3f::calcLargerAngle(NVector3f&)
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
void NVector3f::println() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NVector3f::normalizeByLength(f32 length)
{
	x /= length;
	y /= length;
	z /= length;
}

/*
 * --INFO--
 * Address:	8011D018
 * Size:	0000E8
 */
bool NVector3f::normalizeCheck()
{
	f32 len = length();
	if (NMathf::absolute(len) <= NMathF::error) {
		return false;
	}

	normalizeByLength(len);
	return true;
}

/*
 * --INFO--
 * Address:	8011D100
 * Size:	0000DC
 */
void NVector3f::normalize()
{
	u32 badCompiler; // idek man.
	f32 len = length();
	if (NMathf::absolute(len) <= NMathF::error) {
		return;
	}

	normalizeByLength(len);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NAlpha::fadeInValue(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NAlpha::fadeOutValue(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void NAlpha::fadeInOutValue(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void NAlpha::fadeOutInValue(f32)
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
void NAlpha::reset() { _04 = _08; }

/*
 * --INFO--
 * Address:	8011D1E8
 * Size:	000198
 */
f32 NAlpha::getValue(f32 p1)
{
	if (NMathf::absolute(_0C) <= NMathF::error) {
		_0C = 1.0f;
	}

	f32 val = (p1 - _08) / _0C;

	switch (_10) {
	case 0:
		return val;
	case 1:
		return sinf(NMathF::pi + val * (NMathF::pi / 2)) - 1.0f;
	case 2:
		return sinf(val * (NMathF::pi / 2));
	case 3:
		if (val < 0.5f) {
			return 0.5f * (1.0f - sinf((NMathF::pi / 2) + (2.0f * val) * (NMathF::pi / 2)));
		}
		return 0.5f + (0.5f * sinf((2.0f * (val - 0.5f)) * (NMathF::pi / 2)));
	case 4:
		if (val < 0.5f) {
			return (0.5f * sinf((2.0f * val) * (NMathF::pi / 2)));
		}
		return 0.5f + 0.5f * (1.0f - sinf((NMathF::pi / 2) + (2.0f * (val - 0.5f)) * (NMathF::pi / 2)));
	default:
		return val;
	}
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
void NAlpha::readData(Stream& input)
{
	_08 = input.readFloat();
	_0C = input.readFloat();
	_10 = input.readByte();
}
