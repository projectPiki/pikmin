#include "types.h"

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
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801126C4
 * Size:	00005C
 */
void isNan(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802F
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stfd      f31, 0x18(r1)
	  fmr       f31, f1
	  stw       r31, 0x14(r1)
	  lfs       f1, -0x6B88(r3)
	  bl        0x1026E4
	  mr        r31, r3
	  fmr       f1, f31
	  bl        0x1026D8
	  cmplw     r3, r31
	  bne-      .loc_0x40
	  li        r3, 0x1
	  b         .loc_0x44

	.loc_0x40:
	  li        r3, 0

	.loc_0x44:
	  lwz       r0, 0x24(r1)
	  lfd       f31, 0x18(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80112720
 * Size:	00009C
 */
void makePostureMatrix(Vector3f&, Vector3f&, Vector3f&, Matrix4f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  addi      r3, r31, 0
	  bl        -0xD4994
	  lfs       f0, 0x0(r28)
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x4(r28)
	  stfs      f0, 0x10(r31)
	  lfs       f0, 0x8(r28)
	  stfs      f0, 0x20(r31)
	  lfs       f0, 0x0(r29)
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x4(r29)
	  stfs      f0, 0x14(r31)
	  lfs       f0, 0x8(r29)
	  stfs      f0, 0x24(r31)
	  lfs       f0, 0x0(r30)
	  stfs      f0, 0x8(r31)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x28(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801127BC
 * Size:	0001B0
 */
void calcImpulse(Vector3f&, f32, Vector3f&, Matrix4f&, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  fmr       f30, f1
	  stfd      f29, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  mr        r31, r4
	  stw       r30, 0x78(r1)
	  mr        r30, r3
	  lfs       f2, 0x8(r6)
	  lfs       f4, 0x8(r4)
	  lfs       f0, 0x8(r7)
	  fmuls     f7, f4, f2
	  lfs       f9, 0x0(r4)
	  lfs       f6, 0x0(r6)
	  fmuls     f4, f4, f0
	  lfs       f3, 0x0(r7)
	  lfs       f8, 0x4(r4)
	  fmuls     f6, f9, f6
	  lfs       f5, 0x4(r6)
	  fmuls     f3, f9, f3
	  lfs       f2, 0x4(r7)
	  lfs       f0, -0x6108(r2)
	  fmuls     f5, f8, f5
	  mr        r4, r5
	  stfs      f0, 0x68(r1)
	  fmuls     f2, f8, f2
	  stfs      f0, 0x64(r1)
	  fadds     f5, f6, f5
	  stfs      f0, 0x60(r1)
	  fadds     f0, f3, f2
	  lwz       r3, 0x0(r3)
	  fadds     f31, f7, f5
	  lwz       r0, 0x4(r30)
	  fadds     f29, f4, f0
	  stw       r3, 0x60(r1)
	  addi      r3, r1, 0x60
	  stw       r0, 0x64(r1)
	  lwz       r0, 0x8(r30)
	  stw       r0, 0x68(r1)
	  lfs       f1, 0x68(r1)
	  lfs       f6, 0x4(r31)
	  lfs       f5, 0x0(r31)
	  lfs       f7, 0x64(r1)
	  fmuls     f0, f1, f6
	  lfs       f3, 0x8(r31)
	  fmuls     f4, f1, f5
	  lfs       f2, 0x60(r1)
	  fmuls     f1, f7, f3
	  fmuls     f3, f2, f3
	  fmuls     f2, f2, f6
	  fsubs     f0, f1, f0
	  fmuls     f1, f7, f5
	  fsubs     f3, f4, f3
	  stfs      f0, 0x60(r1)
	  fsubs     f0, f2, f1
	  stfs      f3, 0x64(r1)
	  stfs      f0, 0x68(r1)
	  bl        -0xDB160
	  lfs       f4, 0x68(r1)
	  fdivs     f0, f29, f31
	  lfs       f7, 0x4(r30)
	  lfs       f6, 0x0(r30)
	  lfs       f9, 0x64(r1)
	  lfs       f8, 0x8(r30)
	  lfs       f3, 0x60(r1)
	  fmuls     f2, f9, f8
	  fmuls     f1, f4, f7
	  fmuls     f5, f4, f6
	  fmuls     f4, f3, f8
	  fsubs     f1, f2, f1
	  fmuls     f3, f3, f7
	  fmuls     f2, f9, f6
	  fsubs     f5, f5, f4
	  stfs      f1, 0x60(r1)
	  fneg      f4, f0
	  fsubs     f0, f3, f2
	  stfs      f5, 0x64(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f0, -0x6100(r2)
	  lfs       f5, -0x6104(r2)
	  fdivs     f6, f0, f30
	  lfs       f3, 0x60(r1)
	  lfs       f2, 0x0(r31)
	  lfs       f1, 0x64(r1)
	  lfs       f0, 0x4(r31)
	  fsubs     f7, f5, f4
	  lfs       f5, 0x68(r1)
	  lfs       f4, 0x8(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fmuls     f1, f5, f4
	  fadds     f0, f2, f0
	  fmuls     f2, f7, f31
	  fadds     f0, f1, f0
	  fadds     f0, f6, f0
	  fdivs     f1, f2, f0
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  lfd       f29, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011296C
 * Size:	0001C0
 */
void CRSpline(f32, Vector3f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  fmuls     f9, f1, f1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  fmuls     f10, f9, f1
	  stfd      f31, 0xD8(r1)
	  addi      r6, r1, 0x60
	  addi      r5, r1, 0x5C
	  stw       r31, 0xD4(r1)
	  mr        r31, r4
	  addi      r4, r1, 0x58
	  stw       r30, 0xD0(r1)
	  mr        r30, r3
	  addi      r3, r1, 0x74
	  lfs       f0, -0x60F0(r2)
	  lfs       f3, -0x60FC(r2)
	  lfs       f4, -0x60F4(r2)
	  fmuls     f0, f0, f9
	  fmuls     f5, f3, f10
	  lfs       f7, -0x60F8(r2)
	  fmuls     f4, f4, f10
	  fmuls     f8, f7, f1
	  fadds     f6, f5, f9
	  fsubs     f0, f4, f0
	  lfs       f5, -0x6100(r2)
	  lfs       f3, -0x60EC(r2)
	  fsubs     f6, f6, f8
	  fadds     f4, f5, f0
	  fmuls     f1, f7, f10
	  lfs       f2, -0x60E8(r2)
	  fmuls     f0, f7, f9
	  stfs      f6, 0xCC(r1)
	  fmuls     f3, f3, f10
	  fsubs     f5, f1, f0
	  stfs      f4, 0xC8(r1)
	  fmuls     f1, f2, f9
	  lfs       f0, 0x2C(r31)
	  fmuls     f0, f0, f5
	  fadds     f1, f3, f1
	  stfs      f0, 0x60(r1)
	  fadds     f31, f8, f1
	  lfs       f0, 0x28(r31)
	  fmuls     f0, f0, f5
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x24(r31)
	  fmuls     f0, f0, f5
	  stfs      f0, 0x58(r1)
	  bl        -0xDB90C
	  lfs       f0, 0x20(r31)
	  addi      r6, r1, 0x48
	  addi      r5, r1, 0x44
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x40
	  addi      r3, r1, 0x80
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x1C(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x18(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x40(r1)
	  bl        -0xDB944
	  addi      r3, r1, 0x8C
	  addi      r4, r31, 0xC
	  addi      r5, r1, 0xC8
	  bl        -0x7359C
	  addi      r4, r31, 0
	  addi      r3, r1, 0x98
	  addi      r5, r1, 0xCC
	  bl        -0x735AC
	  lfs       f1, 0xA0(r1)
	  addi      r6, r1, 0x54
	  lfs       f0, 0x94(r1)
	  addi      r5, r1, 0x50
	  lfs       f3, 0x9C(r1)
	  fadds     f4, f1, f0
	  lfs       f2, 0x90(r1)
	  lfs       f1, 0x98(r1)
	  addi      r4, r1, 0x4C
	  lfs       f0, 0x8C(r1)
	  fadds     f2, f3, f2
	  stfs      f4, 0x54(r1)
	  fadds     f0, f1, f0
	  addi      r3, r1, 0xA4
	  stfs      f2, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  bl        -0xDB9A8
	  lfs       f1, 0xA4(r1)
	  lfs       f0, 0x80(r1)
	  lfs       f3, 0xA8(r1)
	  lfs       f2, 0x84(r1)
	  fadds     f1, f1, f0
	  lfs       f0, 0x74(r1)
	  fadds     f3, f3, f2
	  lfs       f2, 0x78(r1)
	  lfs       f5, 0xAC(r1)
	  lfs       f4, 0x88(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0x7C(r1)
	  fadds     f4, f5, f4
	  fadds     f2, f3, f2
	  stfs      f0, 0x0(r30)
	  fadds     f0, f4, f1
	  stfs      f2, 0x4(r30)
	  stfs      f0, 0x8(r30)
	  lwz       r0, 0xE4(r1)
	  lfd       f31, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80112B2C
 * Size:	0001B8
 */
void CRSplineTangent(f32, Vector3f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  fmuls     f6, f1, f1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  addi      r6, r1, 0x60
	  addi      r5, r1, 0x5C
	  stw       r31, 0xDC(r1)
	  mr        r31, r4
	  addi      r4, r1, 0x58
	  stw       r30, 0xD8(r1)
	  mr        r30, r3
	  addi      r3, r1, 0x74
	  lfs       f4, -0x60EC(r2)
	  lfs       f0, -0x60E8(r2)
	  fmuls     f5, f4, f6
	  lfs       f3, -0x60E4(r2)
	  fmuls     f4, f0, f1
	  lfs       f2, -0x60E0(r2)
	  lfs       f0, -0x60F4(r2)
	  fadds     f4, f5, f4
	  lfs       f5, -0x60F8(r2)
	  fmuls     f3, f3, f6
	  fmuls     f2, f2, f1
	  fsubs     f4, f4, f5
	  fmuls     f0, f0, f6
	  fsubs     f2, f3, f2
	  lfs       f3, -0x60DC(r2)
	  stfs      f4, 0xCC(r1)
	  fsubs     f4, f0, f1
	  stfs      f2, 0xC8(r1)
	  lfs       f2, -0x60D8(r2)
	  fmuls     f3, f3, f6
	  lfs       f0, 0x2C(r31)
	  fmuls     f1, f2, f1
	  fmuls     f0, f0, f4
	  fadds     f1, f3, f1
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x28(r31)
	  fadds     f31, f5, f1
	  fmuls     f0, f0, f4
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x24(r31)
	  fmuls     f0, f0, f4
	  stfs      f0, 0x58(r1)
	  bl        -0xDBAC4
	  lfs       f0, 0x20(r31)
	  addi      r6, r1, 0x48
	  addi      r5, r1, 0x44
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x40
	  addi      r3, r1, 0x80
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x1C(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x18(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x40(r1)
	  bl        -0xDBAFC
	  addi      r3, r1, 0x8C
	  addi      r4, r31, 0xC
	  addi      r5, r1, 0xC8
	  bl        -0x73754
	  addi      r4, r31, 0
	  addi      r3, r1, 0x98
	  addi      r5, r1, 0xCC
	  bl        -0x73764
	  lfs       f1, 0xA0(r1)
	  addi      r6, r1, 0x54
	  lfs       f0, 0x94(r1)
	  addi      r5, r1, 0x50
	  lfs       f3, 0x9C(r1)
	  fadds     f4, f1, f0
	  lfs       f2, 0x90(r1)
	  lfs       f1, 0x98(r1)
	  addi      r4, r1, 0x4C
	  lfs       f0, 0x8C(r1)
	  fadds     f2, f3, f2
	  stfs      f4, 0x54(r1)
	  fadds     f0, f1, f0
	  addi      r3, r1, 0xA4
	  stfs      f2, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  bl        -0xDBB60
	  lfs       f1, 0xA4(r1)
	  lfs       f0, 0x80(r1)
	  lfs       f3, 0xA8(r1)
	  lfs       f2, 0x84(r1)
	  fadds     f1, f1, f0
	  lfs       f0, 0x74(r1)
	  fadds     f3, f3, f2
	  lfs       f2, 0x78(r1)
	  lfs       f5, 0xAC(r1)
	  lfs       f4, 0x88(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0x7C(r1)
	  fadds     f4, f5, f4
	  fadds     f2, f3, f2
	  stfs      f0, 0x0(r30)
	  fadds     f0, f4, f1
	  stfs      f2, 0x4(r30)
	  stfs      f0, 0x8(r30)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80112CE4
 * Size:	00022C
 */
void getThrowVelocity(Vector3f&, f32, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  stfd      f30, 0x120(r1)
	  stfd      f29, 0x118(r1)
	  fmr       f29, f1
	  stfd      f28, 0x110(r1)
	  stw       r31, 0x10C(r1)
	  mr        r31, r5
	  stw       r30, 0x108(r1)
	  mr        r30, r4
	  stw       r29, 0x104(r1)
	  mr        r29, r3
	  lfs       f4, 0x4(r4)
	  lfs       f3, 0x4(r5)
	  lfs       f2, 0x0(r4)
	  lfs       f1, 0x0(r5)
	  fsubs     f4, f4, f3
	  lfs       f3, 0x8(r4)
	  fsubs     f5, f2, f1
	  lfs       f2, 0x8(r5)
	  fmuls     f1, f4, f4
	  fsubs     f3, f3, f2
	  lfs       f0, -0x6108(r2)
	  fmuls     f2, f5, f5
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xD4
	  fsqrte    f1, f4
	  lfd       f3, -0x60D0(r2)
	  lfd       f2, -0x60C8(r2)
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
	  stfs      f0, 0x8C(r1)
	  lfs       f4, 0x8C(r1)

	.loc_0xD4:
	  fabs      f1, f29
	  lfs       f0, -0x6108(r2)
	  addi      r0, r1, 0x6C
	  stfs      f0, 0x4(r6)
	  addi      r5, r1, 0x68
	  fdivs     f30, f4, f1
	  lfs       f0, 0x8(r6)
	  addi      r4, r1, 0x64
	  addi      r3, r1, 0xA4
	  fmuls     f0, f0, f30
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x4(r6)
	  fmuls     f0, f0, f30
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x0(r6)
	  mr        r6, r0
	  fmuls     f0, f0, f30
	  stfs      f0, 0x64(r1)
	  bl        -0xDBCE4
	  lfs       f2, 0xAC(r1)
	  addi      r6, r1, 0x78
	  lfs       f3, -0x24C8(r13)
	  addi      r5, r1, 0x74
	  lfs       f1, 0xA8(r1)
	  lfs       f0, 0xA4(r1)
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  addi      r4, r1, 0x70
	  fmuls     f0, f0, f3
	  stfs      f2, 0x78(r1)
	  addi      r3, r1, 0xB0
	  stfs      f1, 0x74(r1)
	  stfs      f0, 0x70(r1)
	  bl        -0xDBD20
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0xB4(r1)
	  lwz       r3, 0x2F80(r13)
	  fadds     f1, f1, f0
	  lfs       f0, 0x4(r30)
	  lfs       f4, -0x6108(r2)
	  lfs       f2, 0x0(r31)
	  fsubs     f3, f1, f0
	  lfs       f1, 0xB0(r1)
	  fmuls     f0, f4, f4
	  lfs       f4, 0x0(r30)
	  fneg      f6, f3
	  fadds     f5, f2, f1
	  lfs       f3, 0x8(r31)
	  lfs       f1, 0xB8(r1)
	  fdivs     f8, f6, f30
	  lfs       f7, -0x60F8(r2)
	  lfs       f6, 0x30(r3)
	  lfs       f2, 0x8(r30)
	  fsubs     f31, f5, f4
	  fadds     f3, f3, f1
	  fmuls     f4, f7, f6
	  fmuls     f1, f31, f31
	  fsubs     f28, f3, f2
	  fmuls     f2, f30, f4
	  fadds     f0, f1, f0
	  fmuls     f1, f28, f28
	  fsubs     f30, f8, f2
	  fadds     f1, f1, f0
	  bl        -0x105274
	  lfs       f0, -0x6108(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1E8
	  fdivs     f31, f31, f1
	  fdivs     f28, f28, f1

	.loc_0x1E8:
	  fmuls     f31, f31, f29
	  fneg      f0, f30
	  fmuls     f28, f28, f29
	  stfs      f31, 0x0(r29)
	  stfs      f0, 0x4(r29)
	  stfs      f28, 0x8(r29)
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lfd       f30, 0x120(r1)
	  lfd       f29, 0x118(r1)
	  lfd       f28, 0x110(r1)
	  lwz       r31, 0x10C(r1)
	  lwz       r30, 0x108(r1)
	  lwz       r29, 0x104(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80112F10
 * Size:	000254
 */
void getCameraSafeAngle(Vector3f&, f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x108(r1)
	  stfd      f31, 0x100(r1)
	  stfd      f30, 0xF8(r1)
	  stfd      f29, 0xF0(r1)
	  stfd      f28, 0xE8(r1)
	  stfd      f27, 0xE0(r1)
	  stfd      f26, 0xD8(r1)
	  fmr       f26, f2
	  stfd      f25, 0xD0(r1)
	  fmr       f25, f1
	  stfd      f24, 0xC8(r1)
	  stmw      r26, 0xB0(r1)
	  addi      r29, r1, 0x7C
	  mr        r26, r3
	  mr        r30, r29
	  li        r28, 0
	  lis       r31, 0x4330
	  stw       r0, 0x7C(r1)
	  lfs       f0, -0x60BC(r2)
	  stw       r0, 0x80(r1)
	  fdivs     f27, f25, f0
	  lfd       f31, -0x60B8(r2)
	  stw       r0, 0x84(r1)
	  lfs       f28, -0x60C0(r2)
	  stw       r0, 0x88(r1)
	  stw       r0, 0x8C(r1)
	  stw       r0, 0x90(r1)
	  stw       r0, 0x94(r1)
	  stw       r0, 0x98(r1)

	.loc_0x80:
	  xoris     r0, r28, 0x8000
	  stw       r0, 0xAC(r1)
	  stw       r31, 0xA8(r1)
	  lfd       f0, 0xA8(r1)
	  fsubs     f0, f0, f31
	  fmuls     f24, f28, f0
	  fmr       f1, f24
	  bl        0x108BA8
	  fmr       f29, f1
	  fmr       f1, f24
	  bl        0x108D30
	  fmr       f30, f1
	  li        r27, 0

	.loc_0xB4:
	  xoris     r0, r27, 0x8000
	  lfs       f3, 0x0(r26)
	  stw       r0, 0xAC(r1)
	  li        r4, 0x1
	  lfs       f2, 0x8(r26)
	  stw       r31, 0xA8(r1)
	  lwz       r3, 0x2F00(r13)
	  lfd       f0, 0xA8(r1)
	  stw       r0, 0xA4(r1)
	  fsubs     f0, f0, f31
	  stw       r31, 0xA0(r1)
	  fmuls     f1, f26, f0
	  lfd       f0, 0xA0(r1)
	  fsubs     f0, f0, f31
	  fmuls     f1, f27, f1
	  fmuls     f0, f27, f0
	  fdivs     f24, f1, f25
	  fmuls     f1, f30, f0
	  fmuls     f0, f29, f0
	  fadds     f1, f3, f1
	  fadds     f2, f2, f0
	  bl        -0xAB114
	  fcmpo     cr0, f1, f24
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x134
	  fsubs     f0, f1, f24
	  lwz       r3, 0x0(r30)
	  fctiwz    f0, f0
	  stfd      f0, 0xA0(r1)
	  lwz       r0, 0xA4(r1)
	  add       r0, r3, r0
	  stw       r0, 0x0(r30)

	.loc_0x134:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x14
	  blt+      .loc_0xB4
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x8
	  addi      r30, r30, 0x4
	  blt+      .loc_0x80
	  lis       r3, 0x2
	  lwz       r0, 0x7C(r1)
	  subi      r4, r3, 0xC00
	  cmpw      r0, r4
	  li        r5, -0x1
	  bge-      .loc_0x170
	  li        r5, 0
	  mr        r4, r0

	.loc_0x170:
	  addi      r3, r29, 0x4
	  lwz       r0, 0x4(r29)
	  cmpw      r0, r4
	  bge-      .loc_0x188
	  li        r5, 0x1
	  mr        r4, r0

	.loc_0x188:
	  lwzu      r0, 0x4(r3)
	  cmpw      r0, r4
	  bge-      .loc_0x19C
	  li        r5, 0x2
	  mr        r4, r0

	.loc_0x19C:
	  lwzu      r0, 0x4(r3)
	  cmpw      r0, r4
	  bge-      .loc_0x1B0
	  li        r5, 0x3
	  mr        r4, r0

	.loc_0x1B0:
	  lwzu      r0, 0x4(r3)
	  cmpw      r0, r4
	  bge-      .loc_0x1C4
	  li        r5, 0x4
	  mr        r4, r0

	.loc_0x1C4:
	  lwzu      r0, 0x4(r3)
	  cmpw      r0, r4
	  bge-      .loc_0x1D8
	  li        r5, 0x5
	  mr        r4, r0

	.loc_0x1D8:
	  lwzu      r0, 0x4(r3)
	  cmpw      r0, r4
	  bge-      .loc_0x1EC
	  li        r5, 0x6
	  mr        r4, r0

	.loc_0x1EC:
	  lwz       r0, 0x4(r3)
	  cmpw      r0, r4
	  bge-      .loc_0x1FC
	  li        r5, 0x7

	.loc_0x1FC:
	  xoris     r0, r5, 0x8000
	  lfd       f2, -0x60B8(r2)
	  stw       r0, 0xA4(r1)
	  lis       r0, 0x4330
	  lmw       r26, 0xB0(r1)
	  stw       r0, 0xA0(r1)
	  lfs       f0, -0x60C0(r2)
	  lfd       f1, 0xA0(r1)
	  lwz       r0, 0x10C(r1)
	  fsubs     f1, f1, f2
	  lfd       f31, 0x100(r1)
	  lfd       f30, 0xF8(r1)
	  lfd       f29, 0xF0(r1)
	  fmuls     f1, f1, f0
	  lfd       f28, 0xE8(r1)
	  lfd       f27, 0xE0(r1)
	  lfd       f26, 0xD8(r1)
	  lfd       f25, 0xD0(r1)
	  lfd       f24, 0xC8(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}
