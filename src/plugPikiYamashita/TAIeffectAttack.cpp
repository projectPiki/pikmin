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
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C4960
 * Size:	000038
 */
void EventTypeCallBack::invoke(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x4(r3)
	  lwz       r3, 0x44(r5)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C4998
 * Size:	0001E0
 */
void CylinderTypeCallBack::init(TAIeffectAttackParam*, Teki*, Vector3f&, Vector3f, f32, f32, f32, f32, TAIeffectAttackEventCallBack*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  fmr       f31, f4
	  stfd      f30, 0x48(r1)
	  fmr       f30, f2
	  stw       r31, 0x44(r1)
	  mr        r31, r8
	  stw       r30, 0x40(r1)
	  mr        r30, r3
	  stw       r29, 0x3C(r1)
	  stw       r4, 0x4(r3)
	  li        r3, 0
	  lwz       r4, 0x4(r30)
	  stw       r3, 0x38(r4)
	  addi      r0, r4, 0x48
	  lfs       f2, -0x4648(r2)
	  stfs      f2, 0x0(r4)
	  stfs      f2, 0x4(r4)
	  stfs      f2, 0xC(r4)
	  lfs       f0, 0x1BB0(r13)
	  stfs      f0, 0x10(r4)
	  lfs       f0, 0x1BB4(r13)
	  stfs      f0, 0x14(r4)
	  lfs       f0, 0x1BB8(r13)
	  stfs      f0, 0x18(r4)
	  lfs       f0, 0x1BBC(r13)
	  stfs      f0, 0x1C(r4)
	  lfs       f0, 0x1BC0(r13)
	  stfs      f0, 0x20(r4)
	  lfs       f0, 0x1BC4(r13)
	  stfs      f0, 0x24(r4)
	  lfs       f0, 0x1BC8(r13)
	  stfs      f0, 0x28(r4)
	  lfs       f0, 0x1BCC(r13)
	  stfs      f0, 0x2C(r4)
	  lfs       f0, 0x1BD0(r13)
	  stfs      f0, 0x30(r4)
	  stfs      f2, 0x34(r4)
	  stw       r3, 0x40(r4)
	  stw       r3, 0x3C(r4)
	  stw       r0, 0x44(r4)
	  stb       r3, 0x4C(r4)
	  lfs       f0, -0x4644(r2)
	  stfs      f0, 0x8(r4)
	  lwz       r3, 0x4(r30)
	  stw       r5, 0x38(r3)
	  lwz       r3, 0x4(r30)
	  stfs      f2, 0x0(r3)
	  lwz       r3, 0x4(r30)
	  stfs      f1, 0x4(r3)
	  lwz       r3, 0x4(r30)
	  stfs      f3, 0xC(r3)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  stw       r3, 0x1C(r4)
	  stw       r0, 0x20(r4)
	  lwz       r0, 0x8(r7)
	  stw       r0, 0x24(r4)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x0(r6)
	  lwz       r0, 0x4(r6)
	  stw       r3, 0x10(r4)
	  stw       r0, 0x14(r4)
	  lwz       r0, 0x8(r6)
	  stw       r0, 0x18(r4)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  stw       r3, 0x28(r4)
	  stw       r0, 0x2C(r4)
	  lwz       r0, 0x8(r7)
	  stw       r0, 0x30(r4)
	  lwz       r3, 0x4(r30)
	  lfs       f1, 0x28(r3)
	  addi      r29, r3, 0x28
	  lfs       f0, 0x2C(r3)
	  lfs       f2, 0x30(r3)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B6EAC
	  lfs       f0, -0x4648(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x188
	  lfs       f0, 0x0(r29)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x4(r29)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r29)
	  lfs       f0, 0x8(r29)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r29)

	.loc_0x188:
	  lwz       r3, 0x4(r30)
	  cmplwi    r31, 0
	  stfs      f30, 0x34(r3)
	  lwz       r3, 0x4(r30)
	  stfs      f31, 0x8(r3)
	  beq-      .loc_0x1A8
	  lwz       r3, 0x4(r30)
	  stw       r31, 0x44(r3)

	.loc_0x1A8:
	  lwz       r3, 0x4(r30)
	  li        r4, 0x1
	  lbz       r0, 0x4C(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x4C(r3)
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lfd       f30, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C4B78
 * Size:	00019C
 */
void CylinderTypeCallBack::hitCheckCommon(zen::particleGenerator*, Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stfd      f31, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  addi      r31, r5, 0
	  stw       r30, 0xA8(r1)
	  addi      r30, r4, 0
	  stw       r29, 0xA4(r1)
	  mr        r29, r3
	  lwz       r6, 0x4(r3)
	  lwz       r3, 0x44(r6)
	  addi      r5, r6, 0
	  mr        r6, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x17C
	  lwz       r9, 0x18(r30)
	  cmplwi    r9, 0
	  beq-      .loc_0x60
	  b         .loc_0x64

	.loc_0x60:
	  addi      r9, r30, 0xC

	.loc_0x64:
	  lwz       r7, 0x4(r29)
	  addi      r5, r1, 0x60
	  addi      r4, r1, 0x6C
	  lfs       f0, 0x28(r7)
	  addi      r3, r1, 0x78
	  lfs       f4, 0x8(r7)
	  addi      r6, r1, 0x9C
	  lfs       f1, 0x2C(r7)
	  fmuls     f0, f0, f4
	  lfs       f2, 0x30(r7)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x48(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f3, 0x58(r1)
	  stfs      f1, 0x5C(r1)
	  lfsu      f1, 0x10(r7)
	  lfs       f0, 0x54(r1)
	  lfs       f4, 0x8(r7)
	  fadds     f0, f1, f0
	  lfs       f3, 0x5C(r1)
	  lfs       f2, 0x4(r7)
	  lfs       f1, 0x58(r1)
	  fadds     f3, f4, f3
	  stfs      f0, 0x44(r1)
	  fadds     f1, f2, f1
	  lfs       f0, 0x44(r1)
	  stfs      f0, 0x60(r1)
	  stfs      f1, 0x64(r1)
	  stfs      f3, 0x68(r1)
	  lfs       f0, 0x0(r9)
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x4(r9)
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x8(r9)
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x94(r31)
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x9C(r31)
	  stfs      f0, 0x80(r1)
	  bl        -0x29368
	  mr        r3, r31
	  fmr       f31, f1
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x4(r29)
	  lfs       f0, 0x8(r4)
	  fadds     f0, f0, f1
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x17C
	  lfs       f1, 0x9C(r1)
	  lfs       f0, -0x4648(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x17C
	  lfs       f0, -0x4630(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x17C
	  lwz       r3, 0x44(r4)
	  mr        r5, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x17C:
	  lwz       r0, 0xBC(r1)
	  lfd       f31, 0xB0(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  lwz       r29, 0xA4(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003E4
 */
void CylinderTypeCallBack::hitCheck(zen::particleGenerator*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C4D14
 * Size:	000384
 */
void CylinderTypeCallBack::invoke(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stw       r31, 0x9C(r1)
	  mr        r31, r4
	  stw       r30, 0x98(r1)
	  mr        r30, r3
	  stw       r29, 0x94(r1)
	  lwz       r5, 0x4(r3)
	  lwz       r3, 0x44(r5)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x28C(r3)
	  fadds     f1, f1, f0
	  stfs      f1, 0x0(r4)
	  lwz       r4, 0x4(r30)
	  lfs       f0, 0x4(r4)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x348
	  lwz       r3, 0x38(r4)
	  lfs       f0, -0x4648(r2)
	  lfs       f1, 0x58(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x348
	  lbz       r0, 0x4C(r4)
	  rlwinm.   r0,r0,25,31,31
	  beq-      .loc_0x260
	  lwz       r3, 0x2DEC(r13)
	  addi      r7, r4, 0x1C
	  lfs       f0, 0x24(r4)
	  addi      r6, r1, 0x40
	  lfs       f1, 0x28C(r3)
	  addi      r5, r1, 0x3C
	  fmuls     f0, f0, f1
	  addi      r4, r1, 0x38
	  addi      r3, r1, 0x68
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  bl        -0x18DCB8
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x68(r1)
	  lfsu      f1, 0x10(r3)
	  lfs       f2, 0x6C(r1)
	  fadds     f0, f1, f0
	  lfs       f3, 0x70(r1)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f0, f2
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f0, f3
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0x18(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x108
	  b         .loc_0x10C

	.loc_0x108:
	  addi      r4, r31, 0xC

	.loc_0x10C:
	  lwz       r3, 0x4(r30)
	  lfs       f2, 0x4(r4)
	  addi      r3, r3, 0x10
	  lfs       f0, 0x0(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f1, 0x0(r3)
	  fsubs     f4, f3, f2
	  lfs       f2, 0x8(r3)
	  fsubs     f5, f1, f0
	  lfs       f1, 0x8(r4)
	  lfs       f0, -0x4648(r2)
	  fsubs     f3, f2, f1
	  fmuls     f2, f5, f5
	  fmuls     f1, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x1B0
	  fsqrte    f1, f4
	  lfd       f3, -0x4640(r2)
	  lfd       f2, -0x4638(r2)
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
	  stfs      f0, 0x4C(r1)
	  lfs       f4, 0x4C(r1)

	.loc_0x1B0:
	  lwz       r4, 0x4(r30)
	  lfs       f0, 0xC(r4)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x230
	  lbz       r0, 0x4C(r4)
	  li        r3, 0
	  rlwimi    r0,r3,7,24,24
	  stb       r0, 0x4C(r4)
	  lwz       r3, 0x4(r30)
	  addi      r29, r3, 0x1C
	  lfs       f1, 0x1C(r3)
	  lfs       f0, 0x20(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x24(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B72CC
	  lfs       f0, -0x4648(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x260
	  lfs       f0, 0x0(r29)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x4(r29)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r29)
	  lfs       f0, 0x8(r29)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r29)
	  b         .loc_0x260

	.loc_0x230:
	  lwz       r3, 0x44(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x260
	  lwz       r3, 0x4(r30)
	  li        r4, 0
	  lbz       r0, 0x4C(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x4C(r3)

	.loc_0x260:
	  lwz       r3, 0x3120(r13)
	  bl        -0xADBB4
	  addi      r5, r3, 0
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x410
	  lwz       r3, 0x3068(r13)
	  li        r0, 0
	  stw       r3, 0x54(r1)
	  addi      r3, r1, 0x50
	  stw       r0, 0x58(r1)
	  bl        -0x1351E4
	  b         .loc_0x2EC

	.loc_0x294:
	  lwz       r4, 0x50(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x2C0
	  lwz       r3, 0x54(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3
	  b         .loc_0x2D8

	.loc_0x2C0:
	  lwz       r3, 0x54(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3

	.loc_0x2D8:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x47C
	  addi      r3, r1, 0x50
	  bl        -0x135364

	.loc_0x2EC:
	  lwz       r3, 0x54(r1)
	  lwz       r4, 0x50(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x314
	  li        r0, 0x1
	  b         .loc_0x340

	.loc_0x314:
	  lwz       r3, 0x54(r1)
	  lwz       r4, 0x50(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x33C
	  li        r0, 0x1
	  b         .loc_0x340

	.loc_0x33C:
	  li        r0, 0

	.loc_0x340:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x294

	.loc_0x348:
	  lwz       r5, 0x4(r30)
	  mr        r4, r31
	  lwz       r3, 0x44(r5)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xA4(r1)
	  li        r3, 0x1
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  lwz       r29, 0x94(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C5098
 * Size:	0001E8
 */
void ConeTypeCallBack::init(TAIeffectAttackParam*, Teki*, Vector3f&, Vector3f, f32, f32, f32, f32, TAIeffectAttackEventCallBack*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  fmr       f31, f4
	  stfd      f30, 0x50(r1)
	  fmr       f30, f2
	  stw       r31, 0x4C(r1)
	  mr        r31, r8
	  stw       r30, 0x48(r1)
	  addi      r30, r7, 0
	  stw       r29, 0x44(r1)
	  mr        r29, r3
	  stw       r28, 0x40(r1)
	  stw       r4, 0x4(r3)
	  li        r3, 0
	  lwz       r4, 0x4(r29)
	  stw       r3, 0x38(r4)
	  addi      r0, r4, 0x48
	  lfs       f2, -0x4648(r2)
	  stfs      f2, 0x0(r4)
	  stfs      f2, 0x4(r4)
	  stfs      f2, 0xC(r4)
	  lfs       f0, 0x1BB0(r13)
	  stfs      f0, 0x10(r4)
	  lfs       f0, 0x1BB4(r13)
	  stfs      f0, 0x14(r4)
	  lfs       f0, 0x1BB8(r13)
	  stfs      f0, 0x18(r4)
	  lfs       f0, 0x1BBC(r13)
	  stfs      f0, 0x1C(r4)
	  lfs       f0, 0x1BC0(r13)
	  stfs      f0, 0x20(r4)
	  lfs       f0, 0x1BC4(r13)
	  stfs      f0, 0x24(r4)
	  lfs       f0, 0x1BC8(r13)
	  stfs      f0, 0x28(r4)
	  lfs       f0, 0x1BCC(r13)
	  stfs      f0, 0x2C(r4)
	  lfs       f0, 0x1BD0(r13)
	  stfs      f0, 0x30(r4)
	  stfs      f2, 0x34(r4)
	  stw       r3, 0x40(r4)
	  stw       r3, 0x3C(r4)
	  stw       r0, 0x44(r4)
	  stb       r3, 0x4C(r4)
	  lfs       f0, -0x4644(r2)
	  stfs      f0, 0x8(r4)
	  lwz       r3, 0x4(r29)
	  stw       r5, 0x38(r3)
	  lwz       r3, 0x4(r29)
	  stfs      f2, 0x0(r3)
	  lwz       r3, 0x4(r29)
	  stfs      f1, 0x4(r3)
	  lwz       r3, 0x4(r29)
	  stfs      f3, 0xC(r3)
	  lwz       r4, 0x4(r29)
	  lwz       r3, 0x0(r6)
	  lwz       r0, 0x4(r6)
	  stw       r3, 0x10(r4)
	  stw       r0, 0x14(r4)
	  lwz       r0, 0x8(r6)
	  stw       r0, 0x18(r4)
	  lwz       r4, 0x4(r29)
	  lwz       r3, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  stw       r3, 0x28(r4)
	  stw       r0, 0x2C(r4)
	  lwz       r0, 0x8(r7)
	  stw       r0, 0x30(r4)
	  lwz       r3, 0x4(r29)
	  lfs       f1, 0x28(r3)
	  addi      r28, r3, 0x28
	  lfs       f0, 0x2C(r3)
	  lfs       f2, 0x30(r3)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B7598
	  lfs       f0, -0x4648(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x174
	  lfs       f0, 0x0(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r28)
	  lfs       f0, 0x4(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r28)
	  lfs       f0, 0x8(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r28)

	.loc_0x174:
	  lwz       r5, 0x4(r29)
	  li        r0, 0
	  lwz       r4, 0x0(r30)
	  cmplwi    r31, 0
	  lwz       r3, 0x4(r30)
	  stw       r4, 0x1C(r5)
	  stw       r3, 0x20(r5)
	  lwz       r3, 0x8(r30)
	  stw       r3, 0x24(r5)
	  lwz       r3, 0x4(r29)
	  stfs      f31, 0x34(r3)
	  lwz       r3, 0x4(r29)
	  stw       r0, 0x40(r3)
	  lwz       r3, 0x4(r29)
	  stw       r0, 0x3C(r3)
	  beq-      .loc_0x1BC
	  lwz       r3, 0x4(r29)
	  stw       r31, 0x44(r3)

	.loc_0x1BC:
	  stfs      f30, 0x8(r29)
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lfd       f30, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  lwz       r28, 0x40(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C5280
 * Size:	000320
 */
void ConeTypeCallBack::hitCheckCommon(zen::particleGenerator*, Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stfd      f30, 0xE8(r1)
	  stfd      f29, 0xE0(r1)
	  stfd      f28, 0xD8(r1)
	  stfd      f27, 0xD0(r1)
	  stw       r31, 0xCC(r1)
	  addi      r31, r5, 0
	  stw       r30, 0xC8(r1)
	  mr        r30, r4
	  stw       r29, 0xC4(r1)
	  addi      r29, r3, 0
	  lwz       r6, 0x18(r4)
	  cmplwi    r6, 0
	  beq-      .loc_0x4C
	  mr        r3, r6
	  b         .loc_0x50

	.loc_0x4C:
	  addi      r3, r30, 0xC

	.loc_0x50:
	  cmplwi    r6, 0
	  lfs       f0, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f4, 0x8(r3)
	  lfs       f3, 0x94(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f5, 0x9C(r31)
	  beq-      .loc_0x74
	  b         .loc_0x78

	.loc_0x74:
	  addi      r6, r30, 0xC

	.loc_0x78:
	  lwz       r3, 0x4(r29)
	  fsubs     f28, f5, f4
	  fsubs     f29, f3, f0
	  lfs       f0, 0x4(r6)
	  addi      r3, r3, 0x10
	  fsubs     f2, f2, f1
	  lfs       f1, 0x4(r3)
	  lfs       f3, 0x0(r3)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x0(r6)
	  lfs       f6, 0x8(r3)
	  fsubs     f31, f3, f1
	  lfs       f4, 0x8(r6)
	  fmuls     f1, f0, f2
	  lfs       f5, -0x4648(r2)
	  fmuls     f3, f31, f29
	  fsubs     f30, f6, f4
	  fadds     f1, f3, f1
	  fmuls     f3, f30, f28
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f5
	  ble-      .loc_0x2F0
	  fmuls     f3, f31, f31
	  fmuls     f1, f0, f0
	  fmuls     f4, f30, f30
	  fadds     f1, f3, f1
	  fadds     f1, f4, f1
	  fcmpo     cr0, f1, f5
	  ble-      .loc_0x144
	  fsqrte    f4, f1
	  lfd       f6, -0x4640(r2)
	  lfd       f5, -0x4638(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f1, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f1, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f1, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f1, f1, f3
	  frsp      f1, f1
	  stfs      f1, 0x40(r1)
	  lfs       f1, 0x40(r1)

	.loc_0x144:
	  fmuls     f5, f29, f29
	  lfs       f3, -0x4648(r2)
	  fmuls     f4, f2, f2
	  fmuls     f6, f28, f28
	  fadds     f4, f5, f4
	  fadds     f7, f6, f4
	  fcmpo     cr0, f7, f3
	  ble-      .loc_0x1BC
	  fsqrte    f4, f7
	  lfd       f6, -0x4640(r2)
	  lfd       f5, -0x4638(r2)
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f4, f4, f3
	  fmul      f3, f4, f4
	  fmul      f4, f6, f4
	  fmul      f3, f7, f3
	  fsub      f3, f5, f3
	  fmul      f3, f4, f3
	  fmul      f3, f7, f3
	  frsp      f3, f3
	  stfs      f3, 0x3C(r1)
	  lfs       f7, 0x3C(r1)

	.loc_0x1BC:
	  lwz       r3, 0x4(r29)
	  lfs       f4, -0x4648(r2)
	  lfs       f3, 0x1C(r3)
	  fcmpu     cr0, f4, f3
	  bne-      .loc_0x1F0
	  lfs       f3, 0x20(r3)
	  fcmpu     cr0, f4, f3
	  bne-      .loc_0x1F0
	  lfs       f3, 0x24(r3)
	  fcmpu     cr0, f4, f3
	  bne-      .loc_0x1F0
	  lfs       f3, 0xC(r3)
	  b         .loc_0x1F4

	.loc_0x1F0:
	  fmr       f3, f1

	.loc_0x1F4:
	  fcmpo     cr0, f7, f3
	  bge-      .loc_0x2F0
	  lfs       f3, -0x4648(r2)
	  fcmpu     cr0, f3, f1
	  beq-      .loc_0x214
	  fdivs     f31, f31, f1
	  fdivs     f0, f0, f1
	  fdivs     f30, f30, f1

	.loc_0x214:
	  lfs       f1, -0x4648(r2)
	  fcmpu     cr0, f1, f7
	  beq-      .loc_0x22C
	  fdivs     f29, f29, f7
	  fdivs     f2, f2, f7
	  fdivs     f28, f28, f7

	.loc_0x22C:
	  fmuls     f0, f0, f2
	  lfs       f1, 0x8(r29)
	  fmuls     f3, f31, f29
	  fmuls     f2, f30, f28
	  fadds     f0, f3, f0
	  fadds     f27, f2, f0
	  bl        0x56690
	  fcmpo     cr0, f27, f1
	  ble-      .loc_0x2F0
	  lfs       f2, -0x4630(r2)
	  fsubs     f3, f27, f1
	  lfs       f0, -0x462C(r2)
	  fsubs     f1, f2, f1
	  fdivs     f27, f3, f1
	  fmuls     f27, f27, f0
	  fcmpo     cr0, f27, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x278
	  lfs       f27, -0x4628(r2)

	.loc_0x278:
	  fsubs     f31, f29, f31
	  lfs       f29, 0x1BD4(r13)
	  fsubs     f28, f28, f30
	  fmuls     f0, f29, f29
	  fmuls     f1, f31, f31
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1B78D8
	  lfs       f0, -0x4648(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x2B4
	  fdivs     f31, f31, f1
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1

	.loc_0x2B4:
	  fmuls     f31, f31, f27
	  addi      r7, r1, 0x50
	  fmuls     f29, f29, f27
	  mr        r4, r30
	  fmuls     f28, f28, f27
	  stfs      f31, 0x50(r1)
	  mr        r6, r31
	  stfs      f29, 0x54(r1)
	  stfs      f28, 0x58(r1)
	  lwz       r5, 0x4(r29)
	  lwz       r3, 0x44(r5)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x2F0:
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lfd       f28, 0xD8(r1)
	  lfd       f27, 0xD0(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  lwz       r29, 0xC4(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000214
 */
void ConeTypeCallBack::hitCheck(zen::particleGenerator*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C55A0
 * Size:	000434
 */
void ConeTypeCallBack::invoke(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  mr        r31, r4
	  stw       r30, 0xA0(r1)
	  mr        r30, r3
	  lwz       r3, 0x2DEC(r13)
	  lwz       r5, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  lfs       f1, 0x0(r5)
	  fadds     f1, f1, f0
	  stfs      f1, 0x0(r5)
	  lwz       r4, 0x4(r30)
	  lfs       f0, 0x4(r4)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x39C
	  lwz       r3, 0x38(r4)
	  lfs       f0, -0x4648(r2)
	  lfs       f1, 0x58(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x39C
	  lwz       r3, 0x2DEC(r13)
	  addi      r7, r4, 0x1C
	  lfs       f0, 0x24(r4)
	  addi      r6, r1, 0x3C
	  lfs       f1, 0x28C(r3)
	  addi      r5, r1, 0x38
	  fmuls     f0, f0, f1
	  addi      r4, r1, 0x34
	  addi      r3, r1, 0x78
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x4(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x0(r7)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r1)
	  bl        -0x18E51C
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x78(r1)
	  lfsu      f1, 0x10(r3)
	  lfs       f2, 0x7C(r1)
	  fadds     f0, f1, f0
	  lfs       f3, 0x80(r1)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f0, f2
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f0, f3
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0x18(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xE0
	  b         .loc_0xE4

	.loc_0xE0:
	  addi      r4, r31, 0xC

	.loc_0xE4:
	  lwz       r3, 0x4(r30)
	  lfs       f2, 0x4(r4)
	  addi      r3, r3, 0x10
	  lfs       f0, 0x0(r4)
	  lfs       f3, 0x4(r3)
	  lfs       f1, 0x0(r3)
	  fsubs     f4, f3, f2
	  lfs       f2, 0x8(r3)
	  fsubs     f5, f1, f0
	  lfs       f1, 0x8(r4)
	  lfs       f0, -0x4648(r2)
	  fsubs     f3, f2, f1
	  fmuls     f2, f5, f5
	  fmuls     f1, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x188
	  fsqrte    f1, f4
	  lfd       f3, -0x4640(r2)
	  lfd       f2, -0x4638(r2)
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
	  stfs      f0, 0x48(r1)
	  lfs       f4, 0x48(r1)

	.loc_0x188:
	  lwz       r4, 0x4(r30)
	  lfs       f0, 0xC(r4)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x1B4
	  lfs       f0, 0x1BD8(r13)
	  stfs      f0, 0x1C(r4)
	  lfs       f0, 0x1BDC(r13)
	  stfs      f0, 0x20(r4)
	  lfs       f0, 0x1BE0(r13)
	  stfs      f0, 0x24(r4)
	  b         .loc_0x1F8

	.loc_0x1B4:
	  lwz       r0, 0x80(r31)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x1F8
	  lwz       r3, 0x44(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F8
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x1BE4(r13)
	  stfsu     f0, 0x1C(r3)
	  lfs       f0, 0x1BE8(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x1BEC(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x1F8:
	  lwz       r3, 0x3120(r13)
	  li        r0, 0
	  stw       r3, 0x58(r1)
	  addi      r3, r1, 0x54
	  stw       r0, 0x5C(r1)
	  bl        -0x1359F0
	  b         .loc_0x26C

	.loc_0x214:
	  lwz       r4, 0x54(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x240
	  lwz       r3, 0x58(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3
	  b         .loc_0x258

	.loc_0x240:
	  lwz       r3, 0x58(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3

	.loc_0x258:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x580
	  addi      r3, r1, 0x54
	  bl        -0x135B70

	.loc_0x26C:
	  lwz       r3, 0x58(r1)
	  lwz       r4, 0x54(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x294
	  li        r0, 0x1
	  b         .loc_0x2C0

	.loc_0x294:
	  lwz       r3, 0x58(r1)
	  lwz       r4, 0x54(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2BC
	  li        r0, 0x1
	  b         .loc_0x2C0

	.loc_0x2BC:
	  li        r0, 0

	.loc_0x2C0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x214
	  lwz       r3, 0x3068(r13)
	  li        r0, 0
	  stw       r3, 0x64(r1)
	  addi      r3, r1, 0x60
	  stw       r0, 0x68(r1)
	  bl        -0x135AC0
	  b         .loc_0x33C

	.loc_0x2E4:
	  lwz       r4, 0x60(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x310
	  lwz       r3, 0x64(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3
	  b         .loc_0x328

	.loc_0x310:
	  lwz       r3, 0x64(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r5, r3

	.loc_0x328:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x650
	  addi      r3, r1, 0x60
	  bl        -0x135C40

	.loc_0x33C:
	  lwz       r3, 0x64(r1)
	  lwz       r4, 0x60(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x364
	  li        r0, 0x1
	  b         .loc_0x390

	.loc_0x364:
	  lwz       r3, 0x64(r1)
	  lwz       r4, 0x60(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x38C
	  li        r0, 0x1
	  b         .loc_0x390

	.loc_0x38C:
	  li        r0, 0

	.loc_0x390:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2E4
	  b         .loc_0x3E0

	.loc_0x39C:
	  lwz       r0, 0x80(r31)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r31)
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x3C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C4
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x3C4:
	  lwz       r3, 0x4(r30)
	  lwz       r3, 0x40(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x3E0
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x3E0:
	  lwz       r5, 0x4(r30)
	  mr        r4, r31
	  lwz       r3, 0x44(r5)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x4(r30)
	  mr        r4, r31
	  lwz       r3, 0x44(r5)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xAC(r1)
	  li        r3, 0x1
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}
