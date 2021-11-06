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
 * Address:	80198D2C
 * Size:	0000EC
 */
zen::TextColorCallBack::TextColorCallBack(P2DPane *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x802D
  stw       r0, 0x4(r1)
  addi      r0, r5, 0x3004
  li        r5, 0x13
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r3, 0
  stw       r30, 0x30(r1)
  addi      r30, r4, 0
  stw       r0, 0x0(r3)
  addi      r3, r31, 0x4
  bl        0x179A4
  lis       r3, 0x802D
  addi      r0, r3, 0x2FF4
  lis       r3, 0x802D
  stw       r0, 0x0(r31)
  addi      r0, r3, 0x62F4
  stw       r0, 0x0(r31)
  li        r0, 0
  addi      r3, r31, 0
  stw       r30, 0x4(r31)
  stb       r0, 0x8(r31)
  lfs       f0, -0x4CF0(r2)
  stfs      f0, 0xC(r31)
  lfs       f0, -0x4CEC(r2)
  stfs      f0, 0x10(r31)
  lwz       r4, 0x4(r31)
  lbz       r0, 0xF4(r4)
  stb       r0, 0x2C(r1)
  lbz       r0, 0xF5(r4)
  stb       r0, 0x2D(r1)
  lbz       r0, 0xF6(r4)
  stb       r0, 0x2E(r1)
  lbz       r0, 0xF7(r4)
  stb       r0, 0x2F(r1)
  lwz       r0, 0x2C(r1)
  stw       r0, 0x14(r31)
  lwz       r4, 0x4(r31)
  lbz       r0, 0xF8(r4)
  stb       r0, 0x28(r1)
  lbz       r0, 0xF9(r4)
  stb       r0, 0x29(r1)
  lbz       r0, 0xFA(r4)
  stb       r0, 0x2A(r1)
  lbz       r0, 0xFB(r4)
  stb       r0, 0x2B(r1)
  lwz       r0, 0x28(r1)
  stw       r0, 0x18(r31)
  lwz       r0, 0x14(r31)
  stw       r0, 0x1C(r31)
  lwz       r0, 0x18(r31)
  stw       r0, 0x20(r31)
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80198E18
 * Size:	0000C4
 */
void zen::TextColorCallBack::setTargetColor(Colour &, Colour &, float)
{
/*
.loc_0x0:
  stwu      r1, -0x48(r1)
  lwz       r0, 0x0(r4)
  stw       r0, 0x1C(r3)
  lwz       r0, 0x0(r5)
  stw       r0, 0x20(r3)
  stfs      f1, 0xC(r3)
  lfs       f0, -0x4CEC(r2)
  fcmpo     cr0, f1, f0
  stfs      f0, 0x10(r3)
  ble-      .loc_0x8C
  li        r0, 0x1
  stb       r0, 0x8(r3)
  lwz       r4, 0x4(r3)
  lbz       r0, 0xF4(r4)
  stb       r0, 0x44(r1)
  lbz       r0, 0xF5(r4)
  stb       r0, 0x45(r1)
  lbz       r0, 0xF6(r4)
  stb       r0, 0x46(r1)
  lbz       r0, 0xF7(r4)
  stb       r0, 0x47(r1)
  lwz       r0, 0x44(r1)
  stw       r0, 0x14(r3)
  lwz       r4, 0x4(r3)
  lbz       r0, 0xF8(r4)
  stb       r0, 0x40(r1)
  lbz       r0, 0xF9(r4)
  stb       r0, 0x41(r1)
  lbz       r0, 0xFA(r4)
  stb       r0, 0x42(r1)
  lbz       r0, 0xFB(r4)
  stb       r0, 0x43(r1)
  lwz       r0, 0x40(r1)
  stw       r0, 0x18(r3)
  b         .loc_0xBC

.loc_0x8C:
  li        r0, 0
  stb       r0, 0x8(r3)
  lwz       r0, 0x0(r4)
  stw       r0, 0x14(r3)
  lwz       r0, 0x0(r5)
  stw       r0, 0x18(r3)
  lwz       r6, 0x4(r3)
  lwz       r0, 0x0(r4)
  stw       r0, 0xF4(r6)
  lwz       r3, 0x4(r3)
  lwz       r0, 0x0(r5)
  stw       r0, 0xF8(r3)

.loc_0xBC:
  addi      r1, r1, 0x48
  blr
*/
}

/*
 * --INFO--
 * Address:	80198EDC
 * Size:	000538
 */
void zen::TextColorCallBack::invoke(P2DPane *)
{
/*
.loc_0x0:
  stwu      r1, -0x88(r1)
  lbz       r0, 0x8(r3)
  cmplwi    r0, 0
  beq-      .loc_0x52C
  lwz       r4, 0x2DEC(r13)
  lfs       f1, 0x10(r3)
  lfs       f0, 0x28C(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x10(r3)
  lfs       f1, 0x10(r3)
  lfs       f0, 0xC(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x44
  li        r0, 0
  stb       r0, 0x8(r3)
  lfs       f0, 0xC(r3)
  stfs      f0, 0x10(r3)

.loc_0x44:
  lfs       f1, 0x10(r3)
  lis       r0, 0x4330
  lfs       f0, 0xC(r3)
  lbz       r4, 0x14(r3)
  fdivs     f1, f1, f0
  lbz       r5, 0x1C(r3)
  stw       r4, 0x7C(r1)
  lfs       f0, -0x4CF0(r2)
  stw       r5, 0x84(r1)
  stw       r0, 0x80(r1)
  fsubs     f0, f0, f1
  lfd       f5, -0x4CE0(r2)
  stw       r0, 0x78(r1)
  lfd       f2, 0x80(r1)
  lfd       f3, 0x78(r1)
  fsubs     f4, f2, f5
  lfs       f2, -0x4CEC(r2)
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0xDC
  stw       r5, 0x7C(r1)
  lfs       f4, -0x4CE8(r2)
  stw       r4, 0x84(r1)
  stw       r0, 0x78(r1)
  stw       r0, 0x80(r1)
  lfd       f3, 0x78(r1)
  lfd       f2, 0x80(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f2, f2, f0
  fadds     f2, f3, f2
  fadds     f2, f4, f2
  b         .loc_0x110

.loc_0xDC:
  stw       r5, 0x7C(r1)
  lfs       f2, -0x4CE8(r2)
  stw       r4, 0x84(r1)
  stw       r0, 0x78(r1)
  stw       r0, 0x80(r1)
  lfd       f4, 0x78(r1)
  lfd       f3, 0x80(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fsubs     f2, f3, f2

.loc_0x110:
  fctiwz    f3, f2
  lis       r0, 0x4330
  lfd       f5, -0x4CE0(r2)
  lfs       f2, -0x4CEC(r2)
  stfd      f3, 0x78(r1)
  lwz       r4, 0x7C(r1)
  stb       r4, 0x68(r1)
  lbz       r4, 0x15(r3)
  lbz       r5, 0x1D(r3)
  stw       r4, 0x74(r1)
  stw       r5, 0x84(r1)
  stw       r0, 0x80(r1)
  stw       r0, 0x70(r1)
  lfd       f4, 0x80(r1)
  lfd       f3, 0x70(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x1A4
  stw       r5, 0x74(r1)
  lfs       f4, -0x4CE8(r2)
  stw       r4, 0x7C(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x78(r1)
  lfd       f3, 0x70(r1)
  lfd       f2, 0x78(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f2, f2, f0
  fadds     f2, f3, f2
  fadds     f2, f4, f2
  b         .loc_0x1D8

.loc_0x1A4:
  stw       r5, 0x74(r1)
  lfs       f2, -0x4CE8(r2)
  stw       r4, 0x7C(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x78(r1)
  lfd       f4, 0x70(r1)
  lfd       f3, 0x78(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fsubs     f2, f3, f2

.loc_0x1D8:
  fctiwz    f3, f2
  lis       r0, 0x4330
  lfd       f5, -0x4CE0(r2)
  lfs       f2, -0x4CEC(r2)
  stfd      f3, 0x70(r1)
  lwz       r4, 0x74(r1)
  stb       r4, 0x69(r1)
  lbz       r4, 0x16(r3)
  lbz       r5, 0x1E(r3)
  stw       r4, 0x84(r1)
  stw       r5, 0x7C(r1)
  stw       r0, 0x78(r1)
  stw       r0, 0x80(r1)
  lfd       f4, 0x78(r1)
  lfd       f3, 0x80(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x26C
  stw       r5, 0x74(r1)
  lfs       f4, -0x4CE8(r2)
  stw       r4, 0x7C(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x78(r1)
  lfd       f3, 0x70(r1)
  lfd       f2, 0x78(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f2, f2, f0
  fadds     f2, f3, f2
  fadds     f2, f4, f2
  b         .loc_0x2A0

.loc_0x26C:
  stw       r5, 0x74(r1)
  lfs       f2, -0x4CE8(r2)
  stw       r4, 0x7C(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x78(r1)
  lfd       f4, 0x70(r1)
  lfd       f3, 0x78(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fsubs     f2, f3, f2

.loc_0x2A0:
  fctiwz    f3, f2
  lis       r0, 0x4330
  lfd       f5, -0x4CE0(r2)
  lfs       f2, -0x4CEC(r2)
  stfd      f3, 0x70(r1)
  lwz       r4, 0x74(r1)
  stb       r4, 0x6A(r1)
  lwz       r7, 0x4(r3)
  lbz       r6, 0xF7(r7)
  stb       r6, 0x6B(r1)
  lbz       r4, 0x18(r3)
  lbz       r5, 0x20(r3)
  stw       r4, 0x84(r1)
  stw       r5, 0x7C(r1)
  stw       r0, 0x78(r1)
  stw       r0, 0x80(r1)
  lfd       f4, 0x78(r1)
  lfd       f3, 0x80(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x340
  stw       r5, 0x74(r1)
  lfs       f4, -0x4CE8(r2)
  stw       r4, 0x7C(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x78(r1)
  lfd       f3, 0x70(r1)
  lfd       f2, 0x78(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f2, f2, f0
  fadds     f2, f3, f2
  fadds     f2, f4, f2
  b         .loc_0x374

.loc_0x340:
  stw       r5, 0x74(r1)
  lfs       f2, -0x4CE8(r2)
  stw       r4, 0x7C(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x78(r1)
  lfd       f4, 0x70(r1)
  lfd       f3, 0x78(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fsubs     f2, f3, f2

.loc_0x374:
  fctiwz    f3, f2
  lis       r0, 0x4330
  lfd       f5, -0x4CE0(r2)
  lfs       f2, -0x4CEC(r2)
  stfd      f3, 0x70(r1)
  lwz       r4, 0x74(r1)
  stb       r4, 0x64(r1)
  lbz       r4, 0x19(r3)
  lbz       r5, 0x21(r3)
  stw       r4, 0x84(r1)
  stw       r5, 0x7C(r1)
  stw       r0, 0x78(r1)
  stw       r0, 0x80(r1)
  lfd       f4, 0x78(r1)
  lfd       f3, 0x80(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x408
  stw       r5, 0x74(r1)
  lfs       f4, -0x4CE8(r2)
  stw       r4, 0x7C(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x78(r1)
  lfd       f3, 0x70(r1)
  lfd       f2, 0x78(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f3, f3, f1
  fmuls     f2, f2, f0
  fadds     f2, f3, f2
  fadds     f2, f4, f2
  b         .loc_0x43C

.loc_0x408:
  stw       r5, 0x74(r1)
  lfs       f2, -0x4CE8(r2)
  stw       r4, 0x7C(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x78(r1)
  lfd       f4, 0x70(r1)
  lfd       f3, 0x78(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fsubs     f2, f3, f2

.loc_0x43C:
  fctiwz    f3, f2
  lis       r0, 0x4330
  lfd       f5, -0x4CE0(r2)
  lfs       f2, -0x4CEC(r2)
  stfd      f3, 0x70(r1)
  lwz       r4, 0x74(r1)
  stb       r4, 0x65(r1)
  lbz       r4, 0x1A(r3)
  lbz       r5, 0x22(r3)
  stw       r4, 0x84(r1)
  stw       r5, 0x7C(r1)
  stw       r0, 0x78(r1)
  stw       r0, 0x80(r1)
  lfd       f4, 0x78(r1)
  lfd       f3, 0x80(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f4, f4, f1
  fmuls     f3, f3, f0
  fadds     f3, f4, f3
  fcmpo     cr0, f3, f2
  cror      2, 0x1, 0x2
  bne-      .loc_0x4D0
  stw       r5, 0x74(r1)
  lfs       f4, -0x4CE8(r2)
  stw       r4, 0x7C(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x78(r1)
  lfd       f3, 0x70(r1)
  lfd       f2, 0x78(r1)
  fsubs     f3, f3, f5
  fsubs     f2, f2, f5
  fmuls     f1, f3, f1
  fmuls     f0, f2, f0
  fadds     f0, f1, f0
  fadds     f0, f4, f0
  b         .loc_0x504

.loc_0x4D0:
  stw       r5, 0x74(r1)
  lfs       f2, -0x4CE8(r2)
  stw       r4, 0x7C(r1)
  stw       r0, 0x70(r1)
  stw       r0, 0x78(r1)
  lfd       f4, 0x70(r1)
  lfd       f3, 0x78(r1)
  fsubs     f4, f4, f5
  fsubs     f3, f3, f5
  fmuls     f1, f4, f1
  fmuls     f0, f3, f0
  fadds     f0, f1, f0
  fsubs     f0, f0, f2

.loc_0x504:
  fctiwz    f0, f0
  lwz       r0, 0x68(r1)
  stfd      f0, 0x70(r1)
  lwz       r4, 0x74(r1)
  stb       r4, 0x66(r1)
  stb       r6, 0x67(r1)
  stw       r0, 0xF4(r7)
  lwz       r3, 0x4(r3)
  lwz       r0, 0x64(r1)
  stw       r0, 0xF8(r3)

.loc_0x52C:
  li        r3, 0x1
  addi      r1, r1, 0x88
  blr
*/
}
