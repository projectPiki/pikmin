#include "zen/Math.h"
#include "Vector.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void zen::ZenQuat::GetMatrix(const Quat&, Matrix3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void zen::ZenQuat::GetMatrix(const Quat&, Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000238
 */
void zen::ZenQuat::GetRotate(const Quat&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019B920
 * Size:	0001C0
 */
f32 zen::getDistPointAndLine(Vector3f, Vector3f, Vector3f, f32&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0xE0(r1)
	  lfs       f1, 0x0(r4)
	  lfs       f2, 0x0(r3)
	  lfs       f0, 0x0(r5)
	  fsubs     f7, f1, f2
	  lfs       f3, 0x8(r4)
	  fsubs     f0, f0, f2
	  lfs       f6, 0x8(r3)
	  lfs       f1, 0x8(r5)
	  fsubs     f10, f0, f7
	  lfs       f4, -0x4CA4(r2)
	  fsubs     f5, f3, f6
	  lfs       f2, 0x4(r4)
	  fsubs     f1, f1, f6
	  lfs       f3, 0x4(r3)
	  fcmpu     cr0, f4, f10
	  lfs       f0, 0x4(r5)
	  fsubs     f8, f1, f5
	  fsubs     f6, f2, f3
	  fsubs     f0, f0, f3
	  fsubs     f9, f0, f6
	  bne-      .loc_0x68
	  fcmpu     cr0, f4, f9
	  bne-      .loc_0x68
	  fcmpu     cr0, f4, f8
	  beq-      .loc_0x138

	.loc_0x68:
	  fmuls     f2, f7, f10
	  fmuls     f0, f6, f9
	  fmuls     f4, f5, f8
	  fmuls     f1, f10, f10
	  fadds     f3, f2, f0
	  fmuls     f0, f9, f9
	  fmuls     f2, f8, f8
	  fadds     f3, f4, f3
	  fadds     f0, f1, f0
	  fneg      f1, f3
	  fadds     f0, f2, f0
	  fdivs     f0, f1, f0
	  stfs      f0, 0x0(r6)
	  lfs       f3, 0x0(r6)
	  lfs       f0, -0x4CA4(r2)
	  fmuls     f2, f9, f3
	  fmuls     f1, f10, f3
	  fmuls     f3, f8, f3
	  fadds     f4, f6, f2
	  fadds     f2, f7, f1
	  fadds     f3, f5, f3
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x130
	  fsqrte    f1, f4
	  lfd       f3, -0x4CA0(r2)
	  lfd       f2, -0x4C98(r2)
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
	  stfs      f0, 0x7C(r1)
	  lfs       f4, 0x7C(r1)

	.loc_0x130:
	  fmr       f1, f4
	  b         .loc_0x1B8

	.loc_0x138:
	  fmuls     f1, f7, f7
	  lfs       f3, -0x4CA8(r2)
	  fmuls     f0, f6, f6
	  fmuls     f2, f5, f5
	  stfs      f3, 0x0(r6)
	  fadds     f0, f1, f0
	  fadds     f5, f2, f0
	  fcmpo     cr0, f5, f4
	  ble-      .loc_0x1B4
	  fsqrte    f1, f5
	  lfd       f3, -0x4CA0(r2)
	  lfd       f2, -0x4C98(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f5, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f5, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f5, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f5, f0
	  frsp      f0, f0
	  stfs      f0, 0x78(r1)
	  lfs       f5, 0x78(r1)

	.loc_0x1B4:
	  fmr       f1, f5

	.loc_0x1B8:
	  addi      r1, r1, 0xE0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019BAE0
 * Size:	000180
 */
void zen::makeRotMatrix(Vector3f&, Matrix3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stfd      f29, 0x70(r1)
	  stfd      f28, 0x68(r1)
	  stfd      f27, 0x60(r1)
	  stfd      f26, 0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r4
	  stw       r30, 0x50(r1)
	  mr        r30, r3
	  lfs       f6, 0x1024(r13)
	  lfs       f3, 0x8(r3)
	  lfs       f4, 0x1028(r13)
	  lfs       f7, 0x4(r3)
	  fmuls     f2, f6, f3
	  lfs       f8, 0x1020(r13)
	  fmuls     f1, f4, f7
	  lfs       f5, 0x0(r3)
	  lfs       f0, -0x4CA4(r2)
	  fmuls     f4, f4, f5
	  fsubs     f29, f2, f1
	  fmuls     f3, f8, f3
	  fmuls     f2, f8, f7
	  fmuls     f1, f6, f5
	  fcmpu     cr0, f0, f29
	  fsubs     f30, f4, f3
	  fsubs     f31, f2, f1
	  bne-      .loc_0x90
	  bne-      .loc_0x90
	  bne-      .loc_0x90
	  lfs       f29, 0x102C(r13)
	  lfs       f30, 0x1030(r13)
	  lfs       f31, 0x1034(r13)

	.loc_0x90:
	  fmuls     f1, f29, f29
	  fmuls     f0, f30, f30
	  fmuls     f2, f31, f31
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x18DF44
	  lfs       f0, -0x4CA4(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xC0
	  fdivs     f29, f29, f1
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1

	.loc_0xC0:
	  lfs       f4, 0x4(r30)
	  lfs       f0, 0x8(r30)
	  lfs       f5, 0x0(r30)
	  fmuls     f3, f4, f31
	  fmuls     f2, f0, f30
	  fmuls     f1, f0, f29
	  fmuls     f0, f5, f31
	  fsubs     f26, f3, f2
	  fmuls     f3, f5, f30
	  fsubs     f27, f1, f0
	  fmuls     f2, f4, f29
	  fmuls     f1, f26, f26
	  fmuls     f0, f27, f27
	  fsubs     f28, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f28, f28
	  fadds     f1, f1, f0
	  bl        -0x18DFA4
	  lfs       f0, -0x4CA4(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x120
	  fdivs     f26, f26, f1
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x120:
	  stfs      f26, 0x0(r31)
	  stfs      f27, 0xC(r31)
	  stfs      f28, 0x18(r31)
	  lfs       f0, 0x0(r30)
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x10(r31)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x1C(r31)
	  stfs      f29, 0x8(r31)
	  stfs      f30, 0x14(r31)
	  stfs      f31, 0x20(r31)
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  lfd       f29, 0x70(r1)
	  lfd       f28, 0x68(r1)
	  lfd       f27, 0x60(r1)
	  lfd       f26, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}
