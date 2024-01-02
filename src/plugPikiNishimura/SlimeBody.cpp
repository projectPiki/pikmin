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
 * Address:	8016A630
 * Size:	00013C
 */
SlimeBody::SlimeBody(Slime*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  stw       r4, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x390(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x238(r3)
	  rlwinm    r3,r0,1,0,30
	  bl        -0x123660
	  stw       r3, 0x14(r31)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x390(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x58(r3)
	  subi      r0, r3, 0x1
	  rlwinm    r3,r0,2,0,29
	  bl        -0x123680
	  stw       r3, 0x18(r31)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x390(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r29, 0x238(r3)
	  mulli     r3, r29, 0xC
	  addi      r3, r3, 0x8
	  bl        -0x1236A0
	  lis       r4, 0x8003
	  addi      r30, r4, 0x5B24
	  addi      r4, r30, 0
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0xC
	  bl        0xAA568
	  stw       r3, 0x1C(r31)
	  lwz       r3, 0x3168(r13)
	  lwz       r29, 0x28(r3)
	  mulli     r3, r29, 0xC
	  addi      r3, r3, 0x8
	  bl        -0x1236D4
	  addi      r4, r30, 0
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0xC
	  bl        0xAA53C
	  stw       r3, 0x8(r31)
	  lwz       r3, 0x3168(r13)
	  lwz       r29, 0x28(r3)
	  mulli     r3, r29, 0xC
	  addi      r3, r3, 0x8
	  bl        -0x123700
	  addi      r4, r30, 0
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0xC
	  bl        0xAA510
	  stw       r3, 0xC(r31)
	  lwz       r3, 0x3168(r13)
	  lwz       r29, 0x28(r3)
	  mulli     r3, r29, 0xC
	  addi      r3, r3, 0x8
	  bl        -0x12372C
	  addi      r4, r30, 0
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0xC
	  bl        0xAA4E4
	  stw       r3, 0x10(r31)
	  mr        r3, r31
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016A76C
 * Size:	0002A4
 */
void SlimeBody::init(Slime*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stfd      f30, 0x80(r1)
	  stfd      f29, 0x78(r1)
	  stfd      f28, 0x70(r1)
	  stfd      f27, 0x68(r1)
	  stmw      r26, 0x50(r1)
	  mr        r29, r3
	  stw       r4, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r4, 0x14(r29)
	  lwz       r3, 0x390(r3)
	  lwz       r3, 0x0(r3)
	  bl        -0x135024
	  lfs       f30, -0x5428(r2)
	  li        r30, 0x1
	  li        r31, 0x11C
	  li        r27, 0x4
	  b         .loc_0x124

	.loc_0x54:
	  lwz       r0, 0x5C(r3)
	  addi      r3, r31, 0x48
	  lfs       f31, -0x5424(r2)
	  li        r26, 0
	  add       r3, r0, r3
	  lfs       f27, 0xC(r3)
	  li        r28, 0
	  lfs       f28, 0x1C(r3)
	  lfs       f29, 0x2C(r3)
	  b         .loc_0x100

	.loc_0x7C:
	  lwz       r0, 0x23C(r3)
	  stfs      f30, 0x3C(r1)
	  add       r3, r0, r28
	  stfs      f30, 0x38(r1)
	  stfs      f30, 0x34(r1)
	  lfs       f0, 0x0(r3)
	  lfs       f2, 0x8(r3)
	  fsubs     f0, f0, f27
	  lfs       f1, 0x4(r3)
	  fsubs     f2, f2, f29
	  fsubs     f1, f1, f28
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x2C(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f2, 0x3C(r1)
	  lfs       f1, 0x34(r1)
	  lfs       f0, 0x38(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x3C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15CC08
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0xF8
	  lwz       r3, 0x18(r29)
	  fmr       f31, f1
	  subi      r0, r3, 0x4
	  stwx      r26, r27, r0

	.loc_0xF8:
	  addi      r28, r28, 0xC
	  addi      r26, r26, 0x1

	.loc_0x100:
	  lwz       r3, 0x0(r29)
	  lwz       r3, 0x390(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x238(r3)
	  cmpw      r26, r0
	  blt+      .loc_0x7C
	  addi      r31, r31, 0x11C
	  addi      r27, r27, 0x4
	  addi      r30, r30, 0x1

	.loc_0x124:
	  lwz       r3, 0x0(r29)
	  lwz       r3, 0x390(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x58(r3)
	  cmpw      r30, r0
	  blt+      .loc_0x54
	  li        r30, 0
	  lfs       f31, -0x5428(r2)
	  mr        r31, r30
	  b         .loc_0x1FC

	.loc_0x14C:
	  lwz       r5, 0x23C(r3)
	  addi      r4, r31, 0x4
	  lwz       r3, 0x1C(r29)
	  addi      r0, r31, 0x8
	  lfsx      f0, r5, r31
	  stfsx     f0, r3, r31
	  lwz       r5, 0x0(r29)
	  lwz       r3, 0x1C(r29)
	  lwz       r5, 0x390(r5)
	  lwz       r5, 0x0(r5)
	  lwz       r5, 0x23C(r5)
	  lfsx      f0, r5, r4
	  stfsx     f0, r3, r4
	  lwz       r4, 0x0(r29)
	  lwz       r3, 0x1C(r29)
	  lwz       r4, 0x390(r4)
	  lwz       r4, 0x0(r4)
	  lwz       r4, 0x23C(r4)
	  lfsx      f0, r4, r0
	  stfsx     f0, r3, r0
	  lwz       r0, 0x1C(r29)
	  add       r28, r0, r31
	  lfs       f1, 0x0(r28)
	  lfs       f0, 0x4(r28)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r28)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15CCF0
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x1F4
	  lfs       f0, 0x0(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r28)
	  lfs       f0, 0x4(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r28)
	  lfs       f0, 0x8(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r28)

	.loc_0x1F4:
	  addi      r31, r31, 0xC
	  addi      r30, r30, 0x1

	.loc_0x1FC:
	  lwz       r3, 0x0(r29)
	  lwz       r3, 0x390(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x238(r3)
	  cmpw      r30, r0
	  blt+      .loc_0x14C
	  li        r7, 0
	  addi      r6, r7, 0
	  b         .loc_0x26C

	.loc_0x220:
	  lwz       r0, 0x8(r29)
	  addi      r7, r7, 0x1
	  lfs       f0, 0x178(r13)
	  add       r3, r0, r6
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x17C(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x180(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r5, 0x0(r29)
	  lwz       r0, 0xC(r29)
	  lwz       r3, 0x94(r5)
	  add       r4, r0, r6
	  lwz       r0, 0x98(r5)
	  addi      r6, r6, 0xC
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x9C(r5)
	  stw       r0, 0x8(r4)

	.loc_0x26C:
	  lwz       r3, 0x3168(r13)
	  lwz       r0, 0x28(r3)
	  cmpw      r7, r0
	  blt+      .loc_0x220
	  lmw       r26, 0x50(r1)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lfd       f30, 0x80(r1)
	  lfd       f29, 0x78(r1)
	  lfd       f28, 0x70(r1)
	  lfd       f27, 0x68(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
void SlimeBody::traceCreaturePosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void SlimeBody::makeCentrePosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void SlimeBody::makeInnerPosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void SlimeBody::makeMaxRadius()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SlimeBody::setSpherePosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
void SlimeBody::calcVertexScore(Vector3f*, Vector3f*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016AA10
 * Size:	0002EC
 */
void SlimeBody::sortPosition(Vector3f*, Vector3f*, Vector3f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  mr        r31, r5
	  stw       r30, 0xA0(r1)
	  li        r30, 0
	  lfs       f1, -0x5428(r2)
	  lfd       f12, -0x5420(r2)
	  stfs      f1, 0x74(r1)
	  lfd       f11, -0x5418(r2)
	  stfs      f1, 0x70(r1)
	  lwz       r7, 0x3168(r13)
	  stfs      f1, 0x6C(r1)
	  lfs       f0, -0x540C(r2)
	  stfs      f1, 0x80(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f1, 0x78(r1)
	  stfs      f1, 0x8C(r1)
	  stfs      f1, 0x88(r1)
	  stfs      f1, 0x84(r1)
	  stfs      f1, 0x98(r1)
	  stfs      f1, 0x94(r1)
	  stfs      f1, 0x90(r1)
	  lfs       f3, 0x0(r4)
	  lfs       f4, 0x4(r4)
	  lfs       f5, 0x8(r4)
	  lfs       f6, 0x0(r6)
	  lfs       f7, 0x4(r6)
	  lfs       f8, 0x8(r6)
	  b         .loc_0x1E8

	.loc_0x7C:
	  fadds     f10, f3, f6
	  li        r9, 0
	  fadds     f9, f4, f7
	  mr        r10, r9
	  fadds     f2, f5, f8
	  fmuls     f10, f10, f0
	  addi      r11, r1, 0x6C
	  fmuls     f9, f9, f0
	  addi      r12, r1, 0x40
	  fmuls     f2, f2, f0
	  stfs      f10, 0x0(r4)
	  stfs      f9, 0x4(r4)
	  stfs      f2, 0x8(r4)
	  lfs       f2, -0x5428(r2)
	  b         .loc_0x1A8

	.loc_0xB8:
	  lwz       r6, 0x10(r3)
	  addi      r5, r10, 0x4
	  lfs       f10, 0x0(r4)
	  addi      r0, r10, 0x8
	  lfsx      f9, r6, r10
	  fsubs     f9, f10, f9
	  stfs      f9, 0x0(r11)
	  lwz       r6, 0x10(r3)
	  lwz       r8, 0x0(r3)
	  lfs       f10, 0x4(r4)
	  lfsx      f9, r6, r5
	  lfs       f13, 0x3D8(r8)
	  fsubs     f9, f10, f9
	  fmuls     f9, f13, f9
	  stfs      f9, 0x4(r11)
	  lwz       r5, 0x10(r3)
	  lfs       f10, 0x8(r4)
	  lfsx      f9, r5, r0
	  fsubs     f9, f10, f9
	  stfs      f9, 0x8(r11)
	  lfs       f10, 0x0(r11)
	  lfs       f9, 0x4(r11)
	  lfs       f13, 0x8(r11)
	  fmuls     f10, f10, f10
	  fmuls     f9, f9, f9
	  fmuls     f13, f13, f13
	  fadds     f9, f10, f9
	  fadds     f13, f13, f9
	  fcmpo     cr0, f13, f1
	  ble-      .loc_0x180
	  fsqrte    f10, f13
	  fmul      f9, f10, f10
	  fmul      f10, f12, f10
	  fmul      f9, f13, f9
	  fsub      f9, f11, f9
	  fmul      f10, f10, f9
	  fmul      f9, f10, f10
	  fmul      f10, f12, f10
	  fmul      f9, f13, f9
	  fsub      f9, f11, f9
	  fmul      f10, f10, f9
	  fmul      f9, f10, f10
	  fmul      f10, f12, f10
	  fmul      f9, f13, f9
	  fsub      f9, f11, f9
	  fmul      f9, f10, f9
	  fmul      f9, f13, f9
	  frsp      f9, f9
	  stfs      f9, 0x2C(r1)
	  lfs       f13, 0x2C(r1)

	.loc_0x180:
	  lwz       r5, 0x0(r3)
	  addi      r10, r10, 0xC
	  addi      r11, r11, 0xC
	  lfs       f9, 0x3D4(r5)
	  addi      r9, r9, 0x1
	  fdivs     f9, f9, f13
	  stfs      f9, 0x0(r12)
	  lfs       f9, 0x0(r12)
	  addi      r12, r12, 0x4
	  fadds     f2, f2, f9

	.loc_0x1A8:
	  lwz       r0, 0x28(r7)
	  cmpw      r9, r0
	  blt+      .loc_0xB8
	  lwz       r5, 0x0(r3)
	  lwz       r5, 0x224(r5)
	  lfs       f9, 0x390(r5)
	  fcmpo     cr0, f2, f9
	  ble-      .loc_0x1D8
	  lfs       f6, 0x0(r4)
	  lfs       f7, 0x4(r4)
	  lfs       f8, 0x8(r4)
	  b         .loc_0x1E4

	.loc_0x1D8:
	  lfs       f3, 0x0(r4)
	  lfs       f4, 0x4(r4)
	  lfs       f5, 0x8(r4)

	.loc_0x1E4:
	  addi      r30, r30, 0x1

	.loc_0x1E8:
	  lwz       r5, 0x0(r3)
	  lwz       r5, 0x224(r5)
	  lwz       r0, 0x3C0(r5)
	  cmpw      r30, r0
	  blt+      .loc_0x7C
	  lfs       f0, -0x5428(r2)
	  addi      r4, r1, 0x6C
	  addi      r5, r1, 0x40
	  stfs      f0, 0x0(r31)
	  li        r6, 0
	  stfs      f0, 0x4(r31)
	  stfs      f0, 0x8(r31)
	  lwz       r3, 0x3168(r13)
	  b         .loc_0x274

	.loc_0x220:
	  lfs       f1, 0x0(r5)
	  addi      r6, r6, 0x1
	  lfs       f0, 0x0(r4)
	  lfs       f2, 0x0(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r31)
	  lfs       f1, 0x0(r5)
	  lfs       f0, 0x4(r4)
	  lfs       f2, 0x4(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x4(r31)
	  lfs       f1, 0x0(r5)
	  addi      r5, r5, 0x4
	  lfs       f0, 0x8(r4)
	  addi      r4, r4, 0xC
	  lfs       f2, 0x8(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x8(r31)

	.loc_0x274:
	  lwz       r0, 0x28(r3)
	  cmpw      r6, r0
	  blt+      .loc_0x220
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x4(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15D070
	  lfs       f0, -0x5428(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2D4
	  lfs       f0, 0x0(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x4(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x8(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r31)

	.loc_0x2D4:
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void SlimeBody::makeSlimeBody()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016ACFC
 * Size:	000464
 */
void SlimeBody::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stmw      r25, 0x8C(r1)
	  li        r31, 0
	  addi      r25, r3, 0
	  addi      r27, r31, 0
	  addi      r26, r31, 0
	  addi      r30, r1, 0x48
	  addi      r29, r1, 0x44
	  addi      r28, r1, 0x40
	  b         .loc_0x160

	.loc_0x30:
	  lwz       r3, 0x0(r25)
	  mr        r4, r28
	  lwz       r0, 0x8(r25)
	  mr        r5, r29
	  lwz       r3, 0x224(r3)
	  add       r7, r0, r27
	  lfs       f1, 0x3A0(r3)
	  mr        r6, r30
	  lfs       f0, 0x0(r7)
	  addi      r3, r1, 0x7C
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x8(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r7)
	  lwz       r7, 0x0(r25)
	  lwz       r0, 0xC(r25)
	  lwz       r7, 0x3F4(r7)
	  add       r8, r0, r27
	  lwzx      r7, r7, r26
	  lfs       f0, 0x8(r8)
	  addi      r7, r7, 0x94
	  lfs       f1, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x48(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x44(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x40(r1)
	  bl        -0x133CA0
	  lwz       r3, 0x0(r25)
	  addi      r26, r26, 0x4
	  lwz       r0, 0x8(r25)
	  addi      r31, r31, 0x1
	  lwz       r3, 0x224(r3)
	  add       r4, r0, r27
	  lfs       f2, 0x7C(r1)
	  lfs       f1, 0x3B0(r3)
	  lfs       f3, 0x80(r1)
	  fmuls     f2, f2, f1
	  lfs       f0, 0x0(r4)
	  lfs       f4, 0x84(r1)
	  fmuls     f3, f3, f1
	  fadds     f0, f0, f2
	  fmuls     f4, f4, f1
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x4(r4)
	  fadds     f0, f0, f3
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x8(r4)
	  fadds     f0, f0, f4
	  stfs      f0, 0x8(r4)
	  lwz       r3, 0x8(r25)
	  lwz       r0, 0xC(r25)
	  add       r4, r3, r27
	  add       r3, r0, r27
	  lfs       f0, 0x0(r4)
	  lfs       f1, 0x0(r3)
	  addi      r27, r27, 0xC
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x4(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r3)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x8(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r3)

	.loc_0x160:
	  lwz       r3, 0x3168(r13)
	  lwz       r0, 0x28(r3)
	  cmpw      r31, r0
	  blt+      .loc_0x30
	  lwz       r3, 0x0(r25)
	  li        r5, 0
	  lfs       f0, 0x184(r13)
	  mr        r7, r5
	  stfsu     f0, 0x94(r3)
	  lfs       f0, 0x188(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x18C(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x3168(r13)
	  b         .loc_0x1E0

	.loc_0x19C:
	  lwz       r6, 0x0(r25)
	  addi      r5, r5, 0x1
	  lwz       r4, 0x3F4(r6)
	  lfsu      f1, 0x94(r6)
	  lwzx      r4, r4, r7
	  addi      r7, r7, 0x4
	  lfsu      f0, 0x94(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r6)
	  lfs       f1, 0x4(r6)
	  lfs       f0, 0x4(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  lfs       f0, 0x8(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r6)

	.loc_0x1E0:
	  lwz       r0, 0x28(r3)
	  cmpw      r5, r0
	  blt+      .loc_0x19C
	  lwz       r3, 0x0(r25)
	  li        r6, 0
	  lfs       f1, -0x5410(r2)
	  mr        r8, r6
	  lfsu      f0, 0x94(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x3168(r13)
	  b         .loc_0x298

	.loc_0x228:
	  lwz       r5, 0x0(r25)
	  addi      r0, r8, 0x4
	  lwz       r4, 0xC(r25)
	  addi      r6, r6, 0x1
	  addi      r7, r5, 0x94
	  add       r5, r4, r8
	  lfs       f0, 0x0(r7)
	  lfs       f1, 0x0(r5)
	  lwz       r4, 0x10(r25)
	  fsubs     f0, f1, f0
	  add       r4, r4, r8
	  addi      r8, r8, 0xC
	  stfs      f0, 0x0(r4)
	  lfs       f1, 0x4(r5)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4(r4)
	  lfs       f1, 0x8(r5)
	  lfs       f0, 0x8(r7)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x8(r4)
	  lwz       r4, 0x0(r25)
	  lwz       r5, 0x10(r25)
	  lwz       r4, 0x224(r4)
	  lfsx      f1, r5, r0
	  lfs       f0, 0x340(r4)
	  fadds     f0, f1, f0
	  stfsx     f0, r5, r0

	.loc_0x298:
	  lwz       r0, 0x28(r3)
	  cmpw      r6, r0
	  blt+      .loc_0x228
	  lfs       f0, -0x5428(r2)
	  li        r26, 0
	  addi      r27, r26, 0
	  stfs      f0, 0x4(r25)
	  b         .loc_0x2FC

	.loc_0x2B8:
	  lwz       r0, 0x10(r25)
	  add       r3, r0, r27
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15D39C
	  lfs       f0, 0x4(r25)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2F4
	  stfs      f1, 0x4(r25)

	.loc_0x2F4:
	  addi      r27, r27, 0xC
	  addi      r26, r26, 0x1

	.loc_0x2FC:
	  lwz       r3, 0x3168(r13)
	  lwz       r0, 0x28(r3)
	  cmpw      r26, r0
	  blt+      .loc_0x2B8
	  lwz       r3, 0x0(r25)
	  lfs       f1, 0x4(r25)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x370(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r25)
	  lwz       r3, 0x0(r25)
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x450
	  lfs       f1, 0x3D4(r3)
	  lfs       f0, -0x5428(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x450
	  li        r6, 0
	  addi      r7, r6, 0
	  b         .loc_0x3C0

	.loc_0x350:
	  lwz       r3, 0x1C(r25)
	  addi      r4, r7, 0x4
	  lfs       f1, 0x4(r25)
	  addi      r0, r7, 0x8
	  lfsx      f0, r3, r7
	  lwz       r3, 0x23C(r5)
	  addi      r6, r6, 0x1
	  fmuls     f0, f1, f0
	  stfsx     f0, r3, r7
	  addi      r7, r7, 0xC
	  lwz       r3, 0x0(r25)
	  lwz       r5, 0x1C(r25)
	  lwz       r3, 0x390(r3)
	  lfs       f1, 0x4(r25)
	  lfsx      f0, r5, r4
	  lwz       r3, 0x0(r3)
	  fmuls     f0, f1, f0
	  lwz       r3, 0x23C(r3)
	  stfsx     f0, r3, r4
	  lwz       r3, 0x0(r25)
	  lwz       r4, 0x1C(r25)
	  lwz       r3, 0x390(r3)
	  lfs       f1, 0x4(r25)
	  lfsx      f0, r4, r0
	  lwz       r3, 0x0(r3)
	  fmuls     f0, f1, f0
	  lwz       r3, 0x23C(r3)
	  stfsx     f0, r3, r0

	.loc_0x3C0:
	  lwz       r4, 0x0(r25)
	  lwz       r3, 0x390(r4)
	  lwz       r5, 0x0(r3)
	  lwz       r0, 0x238(r5)
	  cmpw      r6, r0
	  blt+      .loc_0x350
	  lwz       r3, 0x224(r4)
	  li        r26, 0
	  lfs       f1, 0x190(r13)
	  mulli     r28, r26, 0xC
	  lfs       f0, 0x194(r13)
	  stfs      f1, 0x5C(r1)
	  rlwinm    r27,r26,1,0,30
	  lfs       f1, 0x340(r3)
	  stfs      f1, 0x60(r1)
	  stfs      f0, 0x64(r1)
	  b         .loc_0x438

	.loc_0x404:
	  lwz       r4, 0x14(r25)
	  mr        r3, r25
	  lwz       r7, 0x23C(r5)
	  addi      r6, r1, 0x5C
	  lhzx      r0, r4, r27
	  lwz       r5, 0x290(r5)
	  add       r4, r7, r28
	  mulli     r0, r0, 0xC
	  add       r5, r5, r0
	  bl        -0x714
	  addi      r27, r27, 0x2
	  addi      r28, r28, 0xC
	  addi      r26, r26, 0x1

	.loc_0x438:
	  lwz       r3, 0x0(r25)
	  lwz       r3, 0x390(r3)
	  lwz       r5, 0x0(r3)
	  lwz       r0, 0x238(r5)
	  cmpw      r26, r0
	  blt+      .loc_0x404

	.loc_0x450:
	  lmw       r25, 0x8C(r1)
	  lwz       r0, 0xAC(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000118
 */
void SlimeBody::setJointPosition(BossShapeObject*, Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016B160
 * Size:	000118
 */
void SlimeBody::refresh(BossShapeObject*, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stmw      r26, 0x98(r1)
	  mr        r31, r5
	  addi      r30, r4, 0
	  addi      r29, r3, 0
	  addi      r4, r1, 0x14
	  lwz       r5, 0x2E4(r5)
	  addi      r3, r5, 0x1E0
	  bl        -0x12CD4C
	  lwz       r3, 0x0(r30)
	  li        r4, 0
	  bl        -0x1361AC
	  addi      r4, r3, 0
	  addi      r3, r1, 0x14
	  addi      r5, r1, 0x54
	  bl        -0x12D0D0
	  lwz       r3, 0x0(r29)
	  li        r4, 0
	  lfsu      f0, 0x94(r3)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x80(r1)
	  lwz       r3, 0x0(r30)
	  bl        -0x1361E4
	  lwz       r4, 0x2E4(r31)
	  addi      r5, r3, 0
	  addi      r3, r4, 0x1E0
	  addi      r4, r1, 0x54
	  bl        -0x12D10C
	  li        r27, 0
	  addi      r26, r27, 0
	  li        r28, 0x1

	.loc_0x90:
	  lwz       r3, 0x0(r30)
	  mr        r4, r28
	  bl        -0x136210
	  addi      r4, r3, 0
	  addi      r3, r1, 0x14
	  addi      r5, r1, 0x54
	  bl        -0x12D134
	  lwz       r3, 0x0(r29)
	  mr        r4, r28
	  lwz       r3, 0x3F4(r3)
	  lwzx      r3, r3, r26
	  lfsu      f0, 0x94(r3)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x80(r1)
	  lwz       r3, 0x0(r30)
	  bl        -0x136250
	  lwz       r4, 0x2E4(r31)
	  addi      r5, r3, 0
	  addi      r3, r4, 0x1E0
	  addi      r4, r1, 0x54
	  bl        -0x12D178
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x4
	  addi      r26, r26, 0x4
	  addi      r28, r28, 0x1
	  blt+      .loc_0x90
	  lmw       r26, 0x98(r1)
	  lwz       r0, 0xB4(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}
