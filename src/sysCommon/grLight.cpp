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
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80029A48
 * Size:	000200
 */
Light::Light()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x738C
	  subi      r6, r13, 0x7D1C
	  stwu      r1, -0x18(r1)
	  lis       r5, 0x8023
	  li        r7, 0x6
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x8003
	  stw       r0, 0x0(r30)
	  subi      r0, r5, 0x7D0C
	  subi      r4, r3, 0x63B8
	  stw       r31, 0x10(r30)
	  addi      r3, r30, 0x80
	  li        r5, 0
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  stw       r6, 0x4(r30)
	  li        r6, 0x2C
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x7D70(r2)
	  stfs      f0, 0x5C(r30)
	  stfs      f0, 0x58(r30)
	  stfs      f0, 0x54(r30)
	  stfs      f0, 0x68(r30)
	  stfs      f0, 0x64(r30)
	  stfs      f0, 0x60(r30)
	  bl        0x1EAFA0
	  lfs       f2, -0x7D70(r2)
	  li        r6, 0x302
	  li        r5, 0x3
	  stfs      f2, 0x1D4(r30)
	  li        r4, 0x2
	  li        r0, 0xFF
	  stfs      f2, 0x1D0(r30)
	  mr        r3, r30
	  stfs      f2, 0x1CC(r30)
	  stfs      f2, 0x1E0(r30)
	  stfs      f2, 0x1DC(r30)
	  stfs      f2, 0x1D8(r30)
	  stfs      f2, 0x1EC(r30)
	  stfs      f2, 0x1E8(r30)
	  stfs      f2, 0x1E4(r30)
	  stfs      f2, 0x1F8(r30)
	  stfs      f2, 0x1F4(r30)
	  stfs      f2, 0x1F0(r30)
	  stfs      f2, 0x204(r30)
	  stfs      f2, 0x200(r30)
	  stfs      f2, 0x1FC(r30)
	  stfs      f2, 0x210(r30)
	  stfs      f2, 0x20C(r30)
	  stfs      f2, 0x208(r30)
	  stfs      f2, 0x21C(r30)
	  stfs      f2, 0x218(r30)
	  stfs      f2, 0x214(r30)
	  stfs      f2, 0x228(r30)
	  stfs      f2, 0x224(r30)
	  stfs      f2, 0x220(r30)
	  stfs      f2, 0x234(r30)
	  stfs      f2, 0x230(r30)
	  stfs      f2, 0x22C(r30)
	  stb       r31, 0x1C9(r30)
	  lfs       f0, -0x7D40(r13)
	  stfs      f0, 0x1D8(r30)
	  lfs       f0, -0x7D3C(r13)
	  stfs      f0, 0x1DC(r30)
	  lfs       f0, -0x7D38(r13)
	  stfs      f0, 0x1E0(r30)
	  lfs       f0, -0x7D6C(r2)
	  stfs      f0, 0x240(r30)
	  lfs       f1, -0x7D68(r2)
	  stfs      f1, 0x244(r30)
	  lfs       f0, -0x7D64(r2)
	  stfs      f0, 0x248(r30)
	  stw       r6, 0x14(r30)
	  stw       r5, 0x24(r30)
	  lfs       f0, -0x7D60(r2)
	  stfs      f0, 0x18(r30)
	  lfs       f0, -0x7D5C(r2)
	  stfs      f0, 0x1C(r30)
	  stw       r4, 0x28(r30)
	  lfs       f0, -0x7D58(r2)
	  stfs      f0, 0x20(r30)
	  stfs      f2, 0x2C(r30)
	  stfs      f2, 0x30(r30)
	  lfs       f0, -0x7D54(r2)
	  stfs      f0, 0x34(r30)
	  stfs      f1, 0x38(r30)
	  stfs      f2, 0x3C(r30)
	  stfs      f2, 0x40(r30)
	  lfs       f0, -0x7D50(r2)
	  stfs      f0, 0x48(r30)
	  lfs       f0, -0x7D4C(r2)
	  stfs      f0, 0x44(r30)
	  lfs       f0, -0x7D34(r13)
	  stfs      f0, 0x54(r30)
	  lfs       f0, -0x7D30(r13)
	  stfs      f0, 0x58(r30)
	  lfs       f0, -0x7D2C(r13)
	  stfs      f0, 0x5C(r30)
	  lfs       f0, -0x7D28(r13)
	  stfs      f0, 0x60(r30)
	  lfs       f0, -0x7D24(r13)
	  stfs      f0, 0x64(r30)
	  lfs       f0, -0x7D20(r13)
	  stfs      f0, 0x68(r30)
	  stb       r0, 0x6C(r30)
	  stb       r0, 0x6D(r30)
	  stb       r0, 0x6E(r30)
	  stb       r0, 0x6F(r30)
	  lfs       f1, 0x18(r30)
	  lfs       f2, 0x1C(r30)
	  lwz       r4, 0x24(r30)
	  bl        0x34
	  mr        r3, r30
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
 * Address:	80029C48
 * Size:	000014
 */
CullingPlane::CullingPlane()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x7D70(r2)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80029C5C
 * Size:	0000E4
 */
void Light::setLightDistAttn(f32, f32, int)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x18(r3)
	  stfs      f2, 0x1C(r3)
	  stw       r4, 0x24(r3)
	  lfs       f0, -0x7D70(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1C
	  li        r4, 0

	.loc_0x1C:
	  lfs       f0, -0x7D70(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x3C
	  lfs       f0, -0x7D68(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x40

	.loc_0x3C:
	  li        r4, 0

	.loc_0x40:
	  cmpwi     r4, 0x2
	  beq-      .loc_0x80
	  bge-      .loc_0x5C
	  cmpwi     r4, 0
	  beq-      .loc_0xC0
	  bge-      .loc_0x68
	  b         .loc_0xC0

	.loc_0x5C:
	  cmpwi     r4, 0x4
	  bge-      .loc_0xC0
	  b         .loc_0xA4

	.loc_0x68:
	  lfs       f5, -0x7D68(r2)
	  fmuls     f0, f2, f1
	  lfs       f4, -0x7D70(r2)
	  fsubs     f1, f5, f2
	  fdivs     f3, f1, f0
	  b         .loc_0xCC

	.loc_0x80:
	  lfs       f5, -0x7D68(r2)
	  fmuls     f4, f2, f1
	  lfs       f3, -0x7D48(r2)
	  fsubs     f2, f5, f2
	  fmuls     f0, f1, f4
	  fmuls     f1, f3, f2
	  fdivs     f3, f1, f4
	  fdivs     f4, f1, f0
	  b         .loc_0xCC

	.loc_0xA4:
	  fmuls     f0, f2, f1
	  lfs       f5, -0x7D68(r2)
	  lfs       f3, -0x7D70(r2)
	  fsubs     f2, f5, f2
	  fmuls     f0, f1, f0
	  fdivs     f4, f2, f0
	  b         .loc_0xCC

	.loc_0xC0:
	  lfs       f3, -0x7D70(r2)
	  lfs       f5, -0x7D68(r2)
	  fmr       f4, f3

	.loc_0xCC:
	  stfs      f5, 0x2C(r3)
	  li        r0, 0x1
	  stfs      f3, 0x30(r3)
	  stfs      f4, 0x34(r3)
	  stw       r0, 0x70(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80029D40
 * Size:	000188
 */
void Light::setLightSpot(f32, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lfs       f0, -0x7D70(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x38
	  lfs       f0, -0x7D44(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x3C

	.loc_0x38:
	  li        r31, 0

	.loc_0x3C:
	  lfs       f2, -0x7D40(r2)
	  lfs       f0, -0x7D3C(r2)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x1F1DC8
	  cmplwi    r31, 0x6
	  bgt-      .loc_0x150
	  lis       r3, 0x8023
	  subi      r3, r3, 0x7D54
	  rlwinm    r0,r31,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lfs       f0, -0x7D38(r2)
	  lfs       f2, -0x7D64(r2)
	  fmuls     f5, f0, f1
	  lfs       f3, -0x7D70(r2)
	  b         .loc_0x15C
	  lfs       f0, -0x7D68(r2)
	  fneg      f2, f1
	  lfs       f3, -0x7D70(r2)
	  fsubs     f1, f0, f1
	  fdivs     f5, f2, f1
	  fdivs     f2, f0, f1
	  b         .loc_0x15C
	  lfs       f0, -0x7D68(r2)
	  fneg      f2, f1
	  lfs       f5, -0x7D70(r2)
	  fsubs     f1, f0, f1
	  fdivs     f2, f2, f1
	  fdivs     f3, f0, f1
	  b         .loc_0x15C
	  lfs       f0, -0x7D68(r2)
	  lfs       f3, -0x7D34(r2)
	  fsubs     f4, f0, f1
	  lfs       f0, -0x7D30(r2)
	  fsubs     f2, f1, f3
	  fmuls     f4, f4, f4
	  fmuls     f1, f1, f2
	  fdivs     f2, f3, f4
	  fdivs     f5, f1, f4
	  fdivs     f3, f0, f4
	  b         .loc_0x15C
	  lfs       f0, -0x7D68(r2)
	  lfs       f3, -0x7D2C(r2)
	  fsubs     f4, f0, f1
	  lfs       f2, -0x7D28(r2)
	  fadds     f0, f0, f1
	  fmuls     f1, f3, f1
	  fmuls     f4, f4, f4
	  fmuls     f0, f2, f0
	  fdivs     f5, f1, f4
	  fdivs     f2, f0, f4
	  fdivs     f3, f3, f4
	  b         .loc_0x15C
	  lfs       f4, -0x7D68(r2)
	  lfs       f0, -0x7D34(r2)
	  fsubs     f5, f4, f1
	  lfs       f2, -0x7D28(r2)
	  fmuls     f3, f0, f1
	  lfs       f0, -0x7D24(r2)
	  fmuls     f2, f2, f1
	  fmuls     f5, f5, f5
	  fmuls     f1, f3, f1
	  fdivs     f2, f2, f5
	  fdivs     f1, f1, f5
	  fdivs     f3, f0, f5
	  fsubs     f5, f4, f1
	  b         .loc_0x15C

	.loc_0x150:
	  lfs       f2, -0x7D70(r2)
	  lfs       f5, -0x7D68(r2)
	  fmr       f3, f2

	.loc_0x15C:
	  stfs      f5, 0x38(r30)
	  li        r0, 0x1
	  stfs      f2, 0x3C(r30)
	  stfs      f3, 0x40(r30)
	  stw       r0, 0x70(r30)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Light::setLightParallel()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000218
 */
void Light::calcLightSizes()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void Light::calcLightMapRadius()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void Light::calcLightObjRadius()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001C4
 */
void Light::refresh(Graphics&, LFlareGroup*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80029EC8
 * Size:	0000D0
 */
void Light::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x14(r3)
	  rlwinm    r0,r0,0,24,31
	  cmpwi     r0, 0x2
	  beq-      .loc_0x6C
	  bge-      .loc_0x34
	  cmpwi     r0, 0x1
	  bge-      .loc_0x40
	  b         .loc_0xBC

	.loc_0x34:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xBC
	  b         .loc_0x98

	.loc_0x40:
	  lfs       f1, -0x7D68(r2)
	  li        r0, 0x1
	  stfs      f1, 0x2C(r31)
	  lfs       f0, -0x7D70(r2)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x30(r31)
	  stfs      f1, 0x38(r31)
	  stfs      f0, 0x40(r31)
	  stfs      f0, 0x3C(r31)
	  stw       r0, 0x70(r31)
	  b         .loc_0xBC

	.loc_0x6C:
	  lfs       f1, 0x18(r31)
	  mr        r3, r31
	  lfs       f2, 0x1C(r31)
	  lwz       r4, 0x24(r31)
	  bl        -0x2E8
	  lfs       f0, -0x7D68(r2)
	  stfs      f0, 0x38(r31)
	  lfs       f0, -0x7D70(r2)
	  stfs      f0, 0x40(r31)
	  stfs      f0, 0x3C(r31)
	  b         .loc_0xBC

	.loc_0x98:
	  lfs       f1, 0x20(r31)
	  mr        r3, r31
	  lwz       r4, 0x28(r31)
	  bl        -0x22C
	  lfs       f0, -0x7D68(r2)
	  stfs      f0, 0x2C(r31)
	  lfs       f0, -0x7D70(r2)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x30(r31)

	.loc_0xBC:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
