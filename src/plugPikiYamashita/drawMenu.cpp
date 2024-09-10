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
 * Address:	801C277C
 * Size:	0000AC
 */
void zen::DrawMenuText::init(bool, Colour&, Colour&)
{
	/*
	.loc_0x0:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x4C
	  lfs       f0, -0x4690(r2)
	  stfs      f0, 0x10(r3)
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0x0(r5)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0xF8(r4)
	  lwz       r4, 0x4(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x8C
	  lwz       r0, 0x0(r5)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x4(r3)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0xF8(r4)
	  b         .loc_0x8C

	.loc_0x4C:
	  lfs       f0, -0x468C(r2)
	  stfs      f0, 0x10(r3)
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0xF8(r4)
	  lwz       r4, 0x4(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x8C
	  lwz       r0, 0x8(r3)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x4(r3)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0xF8(r4)

	.loc_0x8C:
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beqlr-
	  li        r0, 0x50
	  stb       r0, 0xF7(r3)
	  li        r0, 0x40
	  stb       r0, 0xFB(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C2828
 * Size:	0000F4
 */
void zen::DrawMenuText::setPane(P2DPane*, P2DPane*)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x88(r1)
	  lhz       r0, 0x8(r4)
	  cmplwi    r0, 0x13
	  bne-      .loc_0xA0
	  stw       r4, 0x0(r3)
	  lwz       r4, 0x0(r3)
	  lbz       r0, 0xF4(r4)
	  stb       r0, 0x80(r1)
	  lbz       r0, 0xF5(r4)
	  stb       r0, 0x81(r1)
	  lbz       r0, 0xF6(r4)
	  stb       r0, 0x82(r1)
	  lbz       r0, 0xF7(r4)
	  stb       r0, 0x83(r1)
	  lwz       r0, 0x80(r1)
	  stw       r0, 0x8(r3)
	  lwz       r4, 0x0(r3)
	  lbz       r0, 0xF8(r4)
	  stb       r0, 0x7C(r1)
	  lbz       r0, 0xF9(r4)
	  stb       r0, 0x7D(r1)
	  lbz       r0, 0xFA(r4)
	  stb       r0, 0x7E(r1)
	  lbz       r0, 0xFB(r4)
	  stb       r0, 0x7F(r1)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0xC(r3)
	  lwz       r7, 0x0(r3)
	  lha       r4, 0x18(r7)
	  lha       r0, 0x1C(r7)
	  lha       r6, 0x1A(r7)
	  sub       r0, r0, r4
	  lha       r4, 0x1E(r7)
	  srawi     r0, r0, 0x1
	  sub       r6, r4, r6
	  extsh     r4, r0
	  srawi     r0, r6, 0x1
	  sth       r4, 0xB8(r7)
	  extsh     r0, r0
	  sth       r0, 0xBA(r7)

	.loc_0xA0:
	  cmplwi    r5, 0
	  beq-      .loc_0xEC
	  lhz       r0, 0x8(r5)
	  cmplwi    r0, 0x13
	  bne-      .loc_0xEC
	  stw       r5, 0x4(r3)
	  lwz       r5, 0x4(r3)
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)

	.loc_0xEC:
	  addi      r1, r1, 0x88
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void zen::DrawMenuText::setScale(f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C291C
 * Size:	0005C4
 */
void zen::DrawMenuText::update(bool, Colour&, Colour&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0xC8(r1)
	  lbz       r0, 0x14(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x53C
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x30
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x10(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r3)
	  b         .loc_0x44

	.loc_0x30:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x10(r3)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10(r3)

	.loc_0x44:
	  lfs       f1, 0x10(r3)
	  lfs       f0, -0x468C(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x58
	  stfs      f0, 0x10(r3)

	.loc_0x58:
	  lfs       f1, 0x10(r3)
	  lfs       f0, -0x4690(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x6C
	  stfs      f0, 0x10(r3)

	.loc_0x6C:
	  lfs       f0, 0x10(r3)
	  lis       r0, 0x4330
	  lfs       f6, -0x4690(r2)
	  lbz       r4, 0x8(r3)
	  fdivs     f1, f0, f6
	  lbz       r7, 0x0(r5)
	  stw       r4, 0xBC(r1)
	  lfs       f0, -0x4688(r2)
	  stw       r7, 0xC4(r1)
	  stw       r0, 0xC0(r1)
	  fsubs     f0, f0, f1
	  lfd       f5, -0x4680(r2)
	  stw       r0, 0xB8(r1)
	  lfd       f2, 0xC0(r1)
	  lfd       f3, 0xB8(r1)
	  fsubs     f4, f2, f5
	  lfs       f2, -0x468C(r2)
	  fsubs     f3, f3, f5
	  fmuls     f4, f4, f1
	  fmuls     f3, f3, f0
	  fadds     f3, f4, f3
	  fcmpo     cr0, f3, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x100
	  stw       r7, 0xBC(r1)
	  stw       r4, 0xC4(r1)
	  stw       r0, 0xB8(r1)
	  stw       r0, 0xC0(r1)
	  lfd       f3, 0xB8(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f3, f3, f5
	  fsubs     f2, f2, f5
	  fmuls     f3, f3, f1
	  fmuls     f2, f2, f0
	  fadds     f2, f3, f2
	  fadds     f2, f6, f2
	  b         .loc_0x130

	.loc_0x100:
	  stw       r7, 0xBC(r1)
	  stw       r4, 0xC4(r1)
	  stw       r0, 0xB8(r1)
	  stw       r0, 0xC0(r1)
	  lfd       f3, 0xB8(r1)
	  lfd       f2, 0xC0(r1)
	  fsubs     f3, f3, f5
	  fsubs     f2, f2, f5
	  fmuls     f3, f3, f1
	  fmuls     f2, f2, f0
	  fadds     f2, f3, f2
	  fsubs     f2, f2, f6

	.loc_0x130:
	  fctiwz    f3, f2
	  lis       r0, 0x4330
	  lfd       f5, -0x4680(r2)
	  lfs       f2, -0x468C(r2)
	  stfd      f3, 0xB8(r1)
	  lwz       r4, 0xBC(r1)
	  stb       r4, 0xA8(r1)
	  lbz       r4, 0x9(r3)
	  lbz       r7, 0x1(r5)
	  stw       r4, 0xB4(r1)
	  stw       r7, 0xC4(r1)
	  stw       r0, 0xC0(r1)
	  stw       r0, 0xB0(r1)
	  lfd       f4, 0xC0(r1)
	  lfd       f3, 0xB0(r1)
	  fsubs     f4, f4, f5
	  fsubs     f3, f3, f5
	  fmuls     f4, f4, f1
	  fmuls     f3, f3, f0
	  fadds     f3, f4, f3
	  fcmpo     cr0, f3, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1C4
	  stw       r7, 0xB4(r1)
	  lfs       f4, -0x4690(r2)
	  stw       r4, 0xBC(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xB8(r1)
	  lfd       f3, 0xB0(r1)
	  lfd       f2, 0xB8(r1)
	  fsubs     f3, f3, f5
	  fsubs     f2, f2, f5
	  fmuls     f3, f3, f1
	  fmuls     f2, f2, f0
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  b         .loc_0x1F8

	.loc_0x1C4:
	  stw       r7, 0xB4(r1)
	  lfs       f2, -0x4690(r2)
	  stw       r4, 0xBC(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xB8(r1)
	  lfd       f4, 0xB0(r1)
	  lfd       f3, 0xB8(r1)
	  fsubs     f4, f4, f5
	  fsubs     f3, f3, f5
	  fmuls     f4, f4, f1
	  fmuls     f3, f3, f0
	  fadds     f3, f4, f3
	  fsubs     f2, f3, f2

	.loc_0x1F8:
	  fctiwz    f3, f2
	  lis       r0, 0x4330
	  lfd       f5, -0x4680(r2)
	  lfs       f2, -0x468C(r2)
	  stfd      f3, 0xB0(r1)
	  lwz       r4, 0xB4(r1)
	  stb       r4, 0xA9(r1)
	  lbz       r4, 0xA(r3)
	  lbz       r5, 0x2(r5)
	  stw       r4, 0xC4(r1)
	  stw       r5, 0xBC(r1)
	  stw       r0, 0xB8(r1)
	  stw       r0, 0xC0(r1)
	  lfd       f4, 0xB8(r1)
	  lfd       f3, 0xC0(r1)
	  fsubs     f4, f4, f5
	  fsubs     f3, f3, f5
	  fmuls     f4, f4, f1
	  fmuls     f3, f3, f0
	  fadds     f3, f4, f3
	  fcmpo     cr0, f3, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x28C
	  stw       r5, 0xB4(r1)
	  lfs       f4, -0x4690(r2)
	  stw       r4, 0xBC(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xB8(r1)
	  lfd       f3, 0xB0(r1)
	  lfd       f2, 0xB8(r1)
	  fsubs     f3, f3, f5
	  fsubs     f2, f2, f5
	  fmuls     f3, f3, f1
	  fmuls     f2, f2, f0
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  b         .loc_0x2C0

	.loc_0x28C:
	  stw       r5, 0xB4(r1)
	  lfs       f2, -0x4690(r2)
	  stw       r4, 0xBC(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xB8(r1)
	  lfd       f4, 0xB0(r1)
	  lfd       f3, 0xB8(r1)
	  fsubs     f4, f4, f5
	  fsubs     f3, f3, f5
	  fmuls     f4, f4, f1
	  fmuls     f3, f3, f0
	  fadds     f3, f4, f3
	  fsubs     f2, f3, f2

	.loc_0x2C0:
	  fctiwz    f3, f2
	  lis       r0, 0x4330
	  lfd       f5, -0x4680(r2)
	  lfs       f2, -0x468C(r2)
	  stfd      f3, 0xB0(r1)
	  lwz       r4, 0xB4(r1)
	  stb       r4, 0xAA(r1)
	  lwz       r4, 0x0(r3)
	  lbz       r7, 0xF7(r4)
	  stb       r7, 0xAB(r1)
	  lbz       r4, 0xC(r3)
	  lbz       r5, 0x0(r6)
	  stw       r4, 0xC4(r1)
	  stw       r5, 0xBC(r1)
	  stw       r0, 0xB8(r1)
	  stw       r0, 0xC0(r1)
	  lfd       f4, 0xB8(r1)
	  lfd       f3, 0xC0(r1)
	  fsubs     f4, f4, f5
	  fsubs     f3, f3, f5
	  fmuls     f4, f4, f1
	  fmuls     f3, f3, f0
	  fadds     f3, f4, f3
	  fcmpo     cr0, f3, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x360
	  stw       r5, 0xB4(r1)
	  lfs       f4, -0x4690(r2)
	  stw       r4, 0xBC(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xB8(r1)
	  lfd       f3, 0xB0(r1)
	  lfd       f2, 0xB8(r1)
	  fsubs     f3, f3, f5
	  fsubs     f2, f2, f5
	  fmuls     f3, f3, f1
	  fmuls     f2, f2, f0
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  b         .loc_0x394

	.loc_0x360:
	  stw       r5, 0xB4(r1)
	  lfs       f2, -0x4690(r2)
	  stw       r4, 0xBC(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xB8(r1)
	  lfd       f4, 0xB0(r1)
	  lfd       f3, 0xB8(r1)
	  fsubs     f4, f4, f5
	  fsubs     f3, f3, f5
	  fmuls     f4, f4, f1
	  fmuls     f3, f3, f0
	  fadds     f3, f4, f3
	  fsubs     f2, f3, f2

	.loc_0x394:
	  fctiwz    f3, f2
	  lis       r0, 0x4330
	  lfd       f5, -0x4680(r2)
	  lfs       f2, -0x468C(r2)
	  stfd      f3, 0xB0(r1)
	  lwz       r4, 0xB4(r1)
	  stb       r4, 0xA4(r1)
	  lbz       r4, 0xD(r3)
	  lbz       r5, 0x1(r6)
	  stw       r4, 0xC4(r1)
	  stw       r5, 0xBC(r1)
	  stw       r0, 0xB8(r1)
	  stw       r0, 0xC0(r1)
	  lfd       f4, 0xB8(r1)
	  lfd       f3, 0xC0(r1)
	  fsubs     f4, f4, f5
	  fsubs     f3, f3, f5
	  fmuls     f4, f4, f1
	  fmuls     f3, f3, f0
	  fadds     f3, f4, f3
	  fcmpo     cr0, f3, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x428
	  stw       r5, 0xB4(r1)
	  lfs       f4, -0x4690(r2)
	  stw       r4, 0xBC(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xB8(r1)
	  lfd       f3, 0xB0(r1)
	  lfd       f2, 0xB8(r1)
	  fsubs     f3, f3, f5
	  fsubs     f2, f2, f5
	  fmuls     f3, f3, f1
	  fmuls     f2, f2, f0
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  b         .loc_0x45C

	.loc_0x428:
	  stw       r5, 0xB4(r1)
	  lfs       f2, -0x4690(r2)
	  stw       r4, 0xBC(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xB8(r1)
	  lfd       f4, 0xB0(r1)
	  lfd       f3, 0xB8(r1)
	  fsubs     f4, f4, f5
	  fsubs     f3, f3, f5
	  fmuls     f4, f4, f1
	  fmuls     f3, f3, f0
	  fadds     f3, f4, f3
	  fsubs     f2, f3, f2

	.loc_0x45C:
	  fctiwz    f3, f2
	  lis       r0, 0x4330
	  lfd       f5, -0x4680(r2)
	  lfs       f2, -0x468C(r2)
	  stfd      f3, 0xB0(r1)
	  lwz       r4, 0xB4(r1)
	  stb       r4, 0xA5(r1)
	  lbz       r4, 0xE(r3)
	  lbz       r5, 0x2(r6)
	  stw       r4, 0xC4(r1)
	  stw       r5, 0xBC(r1)
	  stw       r0, 0xB8(r1)
	  stw       r0, 0xC0(r1)
	  lfd       f4, 0xB8(r1)
	  lfd       f3, 0xC0(r1)
	  fsubs     f4, f4, f5
	  fsubs     f3, f3, f5
	  fmuls     f4, f4, f1
	  fmuls     f3, f3, f0
	  fadds     f3, f4, f3
	  fcmpo     cr0, f3, f2
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4F0
	  stw       r5, 0xB4(r1)
	  lfs       f4, -0x4690(r2)
	  stw       r4, 0xBC(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xB8(r1)
	  lfd       f3, 0xB0(r1)
	  lfd       f2, 0xB8(r1)
	  fsubs     f3, f3, f5
	  fsubs     f2, f2, f5
	  fmuls     f1, f3, f1
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  fadds     f0, f4, f0
	  b         .loc_0x524

	.loc_0x4F0:
	  stw       r5, 0xB4(r1)
	  lfs       f2, -0x4690(r2)
	  stw       r4, 0xBC(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xB8(r1)
	  lfd       f4, 0xB0(r1)
	  lfd       f3, 0xB8(r1)
	  fsubs     f4, f4, f5
	  fsubs     f3, f3, f5
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fadds     f0, f1, f0
	  fsubs     f0, f0, f2

	.loc_0x524:
	  fctiwz    f0, f0
	  stfd      f0, 0xB0(r1)
	  lwz       r0, 0xB4(r1)
	  stb       r0, 0xA6(r1)
	  stb       r7, 0xA7(r1)
	  b         .loc_0x574

	.loc_0x53C:
	  lfs       f0, -0x468C(r2)
	  li        r4, 0x64
	  li        r0, 0x32
	  stfs      f0, 0x10(r3)
	  lwz       r5, 0x0(r3)
	  lbz       r5, 0xF7(r5)
	  stb       r4, 0xA8(r1)
	  stb       r0, 0xA4(r1)
	  stb       r4, 0xA9(r1)
	  stb       r0, 0xA5(r1)
	  stb       r4, 0xAA(r1)
	  stb       r0, 0xA6(r1)
	  stb       r5, 0xAB(r1)
	  stb       r5, 0xA7(r1)

	.loc_0x574:
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0xA4(r1)
	  stw       r0, 0xF8(r4)
	  lwz       r5, 0x4(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x5BC
	  lbz       r0, 0xF7(r5)
	  stb       r0, 0xAB(r1)
	  lbz       r4, 0xFB(r5)
	  lwz       r0, 0xA8(r1)
	  stb       r4, 0xA7(r1)
	  stw       r0, 0xF4(r5)
	  lwz       r3, 0x4(r3)
	  lwz       r0, 0xA4(r1)
	  stw       r0, 0xF8(r3)

	.loc_0x5BC:
	  addi      r1, r1, 0xC8
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C2EE0
 * Size:	000088
 */
void zen::DrawMenuTitle::setPane(P2DScreen*, P2DPane*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r5
	  li        r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x0(r4)
	  addi      r4, r6, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x4(r30)
	  lwz       r0, 0x4(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  li        r0, 0
	  stw       r0, 0x0(r30)
	  mr        r4, r31
	  lwz       r3, 0x4(r30)
	  lfs       f0, -0x468C(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x4(r30)
	  bl        -0x33AC

	.loc_0x70:
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
 * Address:	801C2F68
 * Size:	00000C
 */
void zen::DrawMenuTitle::start()
{
	// Generated from stw r0, 0x0(r3)
	_00 = 1;
}

/*
 * --INFO--
 * Address:	801C2F74
 * Size:	00000C
 */
void zen::DrawMenuTitle::wait()
{
	// Generated from stw r0, 0x0(r3)
	_00 = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void zen::DrawMenuTitle::operation()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C2F80
 * Size:	00000C
 */
void zen::DrawMenuTitle::end()
{
	// Generated from stw r0, 0x0(r3)
	_00 = 3;
}

/*
 * --INFO--
 * Address:	801C2F8C
 * Size:	000170
 */
void zen::DrawMenuTitle::update(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  fmr       f31, f1
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x148
	  lwz       r0, 0x0(r31)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xCC
	  bge-      .loc_0x48
	  cmpwi     r0, 0
	  beq-      .loc_0x54
	  bge-      .loc_0x68
	  b         .loc_0x148

	.loc_0x48:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x148
	  b         .loc_0xE0

	.loc_0x54:
	  lfs       f0, -0x468C(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x148

	.loc_0x68:
	  lfs       f0, -0x4678(r2)
	  fmuls     f1, f0, f31
	  bl        0x58CEC
	  lfs       f0, -0x4670(r2)
	  lfs       f5, -0x4688(r2)
	  fsubs     f3, f31, f0
	  lfs       f2, -0x466C(r2)
	  fsubs     f1, f5, f1
	  lfs       f4, -0x4674(r2)
	  lfs       f0, -0x468C(r2)
	  fdivs     f2, f3, f2
	  fmuls     f1, f4, f1
	  fcmpo     cr0, f2, f0
	  fadds     f31, f5, f1
	  bge-      .loc_0xA8
	  fmr       f2, f0

	.loc_0xA8:
	  lfs       f0, -0x4678(r2)
	  fmuls     f1, f0, f2
	  bl        0x58CAC
	  lwz       r3, 0x4(r31)
	  stfs      f31, 0xC0(r3)
	  stfs      f1, 0xC4(r3)
	  lfs       f0, -0x4688(r2)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x148

	.loc_0xCC:
	  lfs       f0, -0x4688(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  b         .loc_0x148

	.loc_0xE0:
	  lfs       f1, -0x4688(r2)
	  lfs       f0, -0x4678(r2)
	  fsubs     f31, f1, f31
	  fmuls     f1, f0, f31
	  bl        0x58C6C
	  lfs       f0, -0x4670(r2)
	  lfs       f5, -0x4688(r2)
	  fsubs     f3, f31, f0
	  lfs       f2, -0x466C(r2)
	  fsubs     f1, f5, f1
	  lfs       f4, -0x4674(r2)
	  lfs       f0, -0x468C(r2)
	  fdivs     f2, f3, f2
	  fmuls     f1, f4, f1
	  fcmpo     cr0, f2, f0
	  fadds     f31, f5, f1
	  bge-      .loc_0x128
	  fmr       f2, f0

	.loc_0x128:
	  lfs       f0, -0x4678(r2)
	  fmuls     f1, f0, f2
	  bl        0x58C2C
	  lwz       r3, 0x4(r31)
	  stfs      f31, 0xC0(r3)
	  stfs      f1, 0xC4(r3)
	  lfs       f0, -0x4688(r2)
	  stfs      f0, 0xC8(r3)

	.loc_0x148:
	  lwz       r0, 0x0(r31)
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C30FC
 * Size:	000AFC
 */
zen::DrawMenu::DrawMenu(char*, bool, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r7, r6
	  stw       r0, 0x4(r1)
	  addi      r6, r5, 0
	  li        r5, 0
	  stwu      r1, -0x238(r1)
	  stfd      f31, 0x230(r1)
	  stfd      f30, 0x228(r1)
	  stfd      f29, 0x220(r1)
	  stfd      f28, 0x218(r1)
	  stfd      f27, 0x210(r1)
	  stmw      r27, 0x1FC(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        -0x3BC0
	  lwz       r29, 0x8(r1)
	  lis       r3, 0x802E
	  addi      r0, r3, 0x1768
	  stw       r0, 0x0(r29)
	  li        r8, 0
	  lis       r3, 0x100
	  stw       r8, 0x148(r29)
	  li        r7, 0x1
	  addi      r6, r3, 0x1000
	  stw       r8, 0x144(r29)
	  li        r5, 0x2000
	  li        r0, 0x11D
	  stw       r8, 0x14C(r29)
	  addi      r3, r29, 0
	  li        r4, -0x1
	  stw       r8, 0x150(r29)
	  lfs       f0, -0x4688(r2)
	  stfs      f0, 0x158(r29)
	  stfs      f0, 0x154(r29)
	  lfs       f2, -0x468C(r2)
	  stfs      f2, 0x168(r29)
	  stfs      f2, 0x164(r29)
	  stfs      f2, 0x160(r29)
	  stfs      f2, 0x15C(r29)
	  stfs      f0, 0x170(r29)
	  stfs      f0, 0x16C(r29)
	  stfs      f0, 0x178(r29)
	  stfs      f0, 0x174(r29)
	  stw       r8, 0x17C(r29)
	  stw       r8, 0x180(r29)
	  stfs      f0, 0x188(r29)
	  stfs      f0, 0x184(r29)
	  stfs      f2, 0x198(r29)
	  stfs      f2, 0x194(r29)
	  stfs      f2, 0x190(r29)
	  stfs      f2, 0x18C(r29)
	  stfs      f0, 0x1A0(r29)
	  stfs      f0, 0x19C(r29)
	  stfs      f0, 0x1A8(r29)
	  stfs      f0, 0x1A4(r29)
	  stw       r8, 0x1B4(r29)
	  stfs      f2, 0x1B8(r29)
	  stfs      f0, 0x1BC(r29)
	  lfs       f1, 0x1B8(r29)
	  lfs       f0, 0x1BC(r29)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x1C0(r29)
	  stw       r8, 0x100(r29)
	  stfs      f2, 0x104(r29)
	  lfs       f0, -0x4690(r2)
	  stfs      f0, 0x108(r29)
	  stfs      f2, 0x10C(r29)
	  stw       r8, 0x110(r29)
	  stw       r7, 0x114(r29)
	  stw       r6, 0x1C4(r29)
	  stw       r5, 0x1C8(r29)
	  stw       r0, 0x1CC(r29)
	  stb       r8, 0x1D4(r29)
	  bl        0x1718
	  addi      r3, r29, 0x4
	  lwz       r12, 0x4(r29)
	  lis       r4, 0x7061
	  addi      r4, r4, 0x6C6C
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x134(r29)
	  lis       r4, 0x7365
	  addi      r3, r29, 0x4
	  lwz       r8, 0x134(r29)
	  addi      r4, r4, 0x5F63
	  li        r5, 0x1
	  lha       r6, 0x18(r8)
	  lha       r0, 0x1C(r8)
	  lha       r7, 0x1A(r8)
	  sub       r0, r0, r6
	  lha       r6, 0x1E(r8)
	  srawi     r0, r0, 0x1
	  sub       r7, r6, r7
	  extsh     r6, r0
	  srawi     r0, r7, 0x1
	  sth       r6, 0xB8(r8)
	  extsh     r0, r0
	  sth       r0, 0xBA(r8)
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x13
	  bne-      .loc_0x1BC
	  lwz       r0, 0xF4(r3)
	  stw       r0, 0x1AC(r29)
	  lwz       r0, 0xF8(r3)
	  stw       r0, 0x1B0(r29)

	.loc_0x1BC:
	  lwz       r29, 0x8(r1)
	  lwz       r5, 0x134(r29)
	  addi      r3, r29, 0x1B4
	  addi      r4, r29, 0x4
	  bl        0x6204
	  addi      r3, r29, 0x4
	  lwz       r28, 0x134(r29)
	  lwz       r12, 0x4(r29)
	  lis       r4, 0x796F
	  addi      r4, r4, 0x6B6F
	  lwz       r12, 0x34(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  stw       r3, 0x148(r29)
	  lwz       r0, 0x148(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x22C
	  li        r0, 0
	  stw       r0, 0x144(r29)
	  mr        r4, r28
	  lwz       r3, 0x148(r29)
	  lfs       f0, -0x468C(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x148(r29)
	  bl        -0x3784

	.loc_0x22C:
	  addi      r3, r1, 0x1B0
	  crclr     6, 0x6
	  li        r27, 0
	  addi      r4, r13, 0x1B70
	  li        r5, 0
	  bl        0x5325C
	  b         .loc_0x260

	.loc_0x248:
	  addi      r27, r27, 0x1
	  crclr     6, 0x6
	  addi      r5, r27, 0
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B70
	  bl        0x53240

	.loc_0x260:
	  lwz       r28, 0x8(r1)
	  li        r5, 0
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r28)
	  addi      r3, r28, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  cmplwi    r3, 0
	  bne+      .loc_0x248
	  stw       r27, 0x114(r28)
	  lwz       r29, 0x114(r28)
	  mulli     r3, r29, 0xC
	  addi      r3, r3, 0x8
	  bl        -0x17C3AC
	  lis       r4, 0x801C
	  lis       r5, 0x801C
	  addi      r4, r4, 0x3C4C
	  addi      r5, r5, 0x3BF8
	  addi      r7, r29, 0
	  li        r6, 0xC
	  bl        0x5185C
	  li        r31, 0
	  stw       r3, 0x138(r28)
	  mr        r30, r31
	  b         .loc_0x510

	.loc_0x2E4:
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B78
	  bl        0x531A8
	  lwz       r28, 0x8(r1)
	  li        r5, 0
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r28)
	  addi      r3, r28, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  mr.       r27, r3
	  beq-      .loc_0x348
	  mr        r3, r27
	  lwz       r4, 0x134(r28)
	  bl        -0x38A0

	.loc_0x348:
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B70
	  bl        0x53144
	  lwz       r29, 0x8(r1)
	  li        r5, 0x1
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r29)
	  addi      r3, r29, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  lwz       r4, 0x134(r29)
	  mr        r28, r3
	  bl        -0x38FC
	  lwz       r0, 0x138(r29)
	  addi      r4, r28, 0
	  addi      r5, r27, 0
	  add       r3, r0, r30
	  lwz       r3, 0x0(r3)
	  bl        -0xC8C
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B80
	  bl        0x530D0
	  lwz       r12, 0x4(r29)
	  addi      r3, r29, 0x4
	  lbz       r0, 0x1B1(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x1B2(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x1B3(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  lwz       r5, 0x138(r29)
	  cmplwi    r0, 0x12
	  lwz       r4, 0x134(r29)
	  add       r6, r5, r30
	  bne-      .loc_0x440
	  stw       r3, 0x4(r6)
	  li        r5, 0
	  lwz       r3, 0x4(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x4(r6)
	  bl        -0x3998

	.loc_0x440:
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B88
	  bl        0x5304C
	  lwz       r29, 0x8(r1)
	  li        r5, 0x1
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r29)
	  addi      r3, r29, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  mr        r28, r3
	  lwz       r3, 0x138(r29)
	  lhz       r0, 0x8(r28)
	  lwz       r4, 0x134(r29)
	  add       r6, r3, r30
	  cmplwi    r0, 0x12
	  bne-      .loc_0x4CC
	  stw       r28, 0x8(r6)
	  li        r5, 0
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8(r6)
	  bl        -0x3A24

	.loc_0x4CC:
	  lwz       r4, 0x8(r1)
	  lhz       r0, 0x8(r28)
	  lwz       r3, 0x138(r4)
	  cmplwi    r0, 0x12
	  lwz       r4, 0x134(r4)
	  add       r6, r3, r30
	  bne-      .loc_0x508
	  stw       r28, 0x8(r6)
	  li        r5, 0
	  lwz       r3, 0x8(r6)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8(r6)
	  bl        -0x3A60

	.loc_0x508:
	  addi      r30, r30, 0xC
	  addi      r31, r31, 0x1

	.loc_0x510:
	  lwz       r3, 0x8(r1)
	  lwz       r0, 0x114(r3)
	  cmpw      r31, r0
	  blt+      .loc_0x2E4
	  addi      r3, r1, 0x1B0
	  crclr     6, 0x6
	  li        r29, 0
	  addi      r4, r13, 0x1B90
	  li        r5, 0
	  bl        0x52F68
	  b         .loc_0x554

	.loc_0x53C:
	  addi      r29, r29, 0x1
	  crclr     6, 0x6
	  addi      r5, r29, 0
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B90
	  bl        0x52F4C

	.loc_0x554:
	  lwz       r28, 0x8(r1)
	  li        r5, 0
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r28)
	  addi      r3, r28, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  cmplwi    r3, 0
	  bne+      .loc_0x53C
	  stw       r29, 0x118(r28)
	  lwz       r0, 0x118(r28)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x17C69C
	  stw       r3, 0x13C(r28)
	  lwz       r0, 0x118(r28)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x17C6AC
	  stw       r3, 0x140(r28)
	  lis       r30, 0x4330
	  lwz       r3, 0x118(r28)
	  lfs       f28, -0x4668(r2)
	  subi      r28, r3, 0x1
	  lfs       f29, -0x4688(r2)
	  lfd       f30, -0x4660(r2)
	  rlwinm    r29,r28,2,0,29
	  lfs       f31, -0x4690(r2)
	  lfs       f27, -0x468C(r2)
	  b         .loc_0x91C

	.loc_0x5E4:
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B90
	  bl        0x52EA8
	  lwz       r31, 0x8(r1)
	  li        r5, 0x1
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r31)
	  addi      r3, r31, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x77C
	  lwz       r4, 0x13C(r31)
	  stwx      r3, r4, r29
	  lwz       r3, 0x13C(r31)
	  lwz       r4, 0x134(r31)
	  lwzx      r3, r3, r29
	  bl        -0x3BB0
	  lwz       r0, 0x110(r31)
	  lwz       r3, 0x13C(r31)
	  mulli     r4, r0, 0xC
	  lwz       r5, 0x138(r31)
	  lwzx      r3, r3, r29
	  addi      r0, r4, 0x4
	  lwz       r12, 0x0(r3)
	  lwzx      r4, r5, r0
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  mtlr      r12
	  subi      r4, r4, 0x280
	  blrl
	  lwz       r3, 0x13C(r31)
	  li        r4, 0x1
	  cmpwi     r28, 0
	  lwzx      r3, r3, r29
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x13C(r31)
	  lwzx      r5, r3, r29
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  lwz       r3, 0x13C(r31)
	  lwzx      r3, r3, r29
	  stfs      f27, 0xC0(r3)
	  stfs      f27, 0xC4(r3)
	  stfs      f27, 0xC8(r3)
	  bne-      .loc_0x710
	  lwz       r3, 0x13C(r31)
	  li        r4, 0xFF
	  lwzx      r3, r3, r29
	  bl        -0x3F2C
	  b         .loc_0x77C

	.loc_0x710:
	  lwz       r0, 0x118(r31)
	  xoris     r3, r28, 0x8000
	  stw       r3, 0x1F4(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1EC(r1)
	  stw       r30, 0x1F0(r1)
	  stw       r30, 0x1E8(r1)
	  lfd       f1, 0x1F0(r1)
	  lfd       f0, 0x1E8(r1)
	  fsubs     f1, f1, f30
	  fsubs     f0, f0, f30
	  fdivs     f0, f1, f0
	  fsubs     f0, f29, f0
	  fmuls     f0, f28, f0
	  fcmpo     cr0, f0, f27
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x75C
	  fadds     f0, f31, f0
	  b         .loc_0x760

	.loc_0x75C:
	  fsubs     f0, f0, f31

	.loc_0x760:
	  fctiwz    f0, f0
	  lwz       r3, 0x13C(r31)
	  lwzx      r3, r3, r29
	  stfd      f0, 0x1E8(r1)
	  lwz       r0, 0x1EC(r1)
	  rlwinm    r4,r0,0,24,31
	  bl        -0x3F9C

	.loc_0x77C:
	  addi      r5, r28, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x1B0
	  addi      r4, r13, 0x1B98
	  bl        0x52D10
	  lwz       r31, 0x8(r1)
	  li        r5, 0x1
	  lbz       r0, 0x1B1(r1)
	  lwz       r12, 0x4(r31)
	  addi      r3, r31, 0x4
	  lbz       r4, 0x1B0(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x1B2(r1)
	  lbz       r4, 0x1B3(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x914
	  lwz       r4, 0x140(r31)
	  stwx      r3, r4, r29
	  lwz       r3, 0x140(r31)
	  lwz       r4, 0x134(r31)
	  lwzx      r3, r3, r29
	  bl        -0x3D48
	  lwz       r0, 0x110(r31)
	  lwz       r3, 0x140(r31)
	  mulli     r4, r0, 0xC
	  lwz       r5, 0x138(r31)
	  lwzx      r3, r3, r29
	  addi      r0, r4, 0x8
	  lwz       r12, 0x0(r3)
	  lwzx      r4, r5, r0
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  mtlr      r12
	  addi      r4, r4, 0x280
	  blrl
	  lwz       r3, 0x140(r31)
	  li        r4, 0x1
	  cmpwi     r28, 0
	  lwzx      r3, r3, r29
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x140(r31)
	  lwzx      r5, r3, r29
	  lha       r3, 0x18(r5)
	  lha       r0, 0x1C(r5)
	  lha       r4, 0x1A(r5)
	  sub       r0, r0, r3
	  lha       r3, 0x1E(r5)
	  srawi     r0, r0, 0x1
	  sub       r4, r3, r4
	  extsh     r3, r0
	  srawi     r0, r4, 0x1
	  sth       r3, 0xB8(r5)
	  extsh     r0, r0
	  sth       r0, 0xBA(r5)
	  lwz       r3, 0x140(r31)
	  lwzx      r3, r3, r29
	  stfs      f27, 0xC0(r3)
	  stfs      f27, 0xC4(r3)
	  stfs      f27, 0xC8(r3)
	  bne-      .loc_0x8A8
	  lwz       r3, 0x140(r31)
	  li        r4, 0xFF
	  lwzx      r3, r3, r29
	  bl        -0x40C4
	  b         .loc_0x914

	.loc_0x8A8:
	  lwz       r0, 0x118(r31)
	  xoris     r3, r28, 0x8000
	  stw       r3, 0x1EC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1F4(r1)
	  stw       r30, 0x1E8(r1)
	  stw       r30, 0x1F0(r1)
	  lfd       f1, 0x1E8(r1)
	  lfd       f0, 0x1F0(r1)
	  fsubs     f1, f1, f30
	  fsubs     f0, f0, f30
	  fdivs     f0, f1, f0
	  fsubs     f0, f29, f0
	  fmuls     f0, f28, f0
	  fcmpo     cr0, f0, f27
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x8F4
	  fadds     f0, f31, f0
	  b         .loc_0x8F8

	.loc_0x8F4:
	  fsubs     f0, f0, f31

	.loc_0x8F8:
	  fctiwz    f0, f0
	  lwz       r3, 0x140(r31)
	  lwzx      r3, r3, r29
	  stfd      f0, 0x1E8(r1)
	  lwz       r0, 0x1EC(r1)
	  rlwinm    r4,r0,0,24,31
	  bl        -0x4134

	.loc_0x914:
	  subi      r29, r29, 0x4
	  subi      r28, r28, 0x1

	.loc_0x91C:
	  cmpwi     r28, 0
	  bge+      .loc_0x5E4
	  lwz       r31, 0x8(r1)
	  lis       r28, 0x7A2A
	  lfs       f0, -0x468C(r2)
	  lis       r30, 0x4330
	  addi      r3, r31, 0x14C
	  stfs      f0, 0x11C(r31)
	  addi      r4, r31, 0x4
	  addi      r6, r28, 0x2A6C
	  lfs       f0, -0x4690(r2)
	  stfs      f0, 0x120(r31)
	  lwz       r0, 0x110(r31)
	  lwz       r7, 0x138(r31)
	  mulli     r5, r0, 0xC
	  lfd       f2, -0x4660(r2)
	  addi      r0, r5, 0x4
	  lwzx      r5, r7, r0
	  lha       r5, 0x18(r5)
	  subi      r0, r5, 0x280
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1EC(r1)
	  stw       r30, 0x1E8(r1)
	  lfd       f0, 0x1E8(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x124(r31)
	  lwz       r0, 0x110(r31)
	  lwz       r7, 0x138(r31)
	  mulli     r5, r0, 0xC
	  addi      r0, r5, 0x4
	  lwzx      r5, r7, r0
	  lha       r0, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1F4(r1)
	  stw       r30, 0x1F0(r1)
	  lfd       f0, 0x1F0(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x128(r31)
	  lwz       r0, 0x110(r31)
	  lwz       r7, 0x138(r31)
	  mulli     r5, r0, 0xC
	  addi      r0, r5, 0x8
	  lwzx      r5, r7, r0
	  lha       r5, 0x18(r5)
	  addi      r0, r5, 0x280
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1E4(r1)
	  stw       r30, 0x1E0(r1)
	  lfd       f0, 0x1E0(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x12C(r31)
	  lwz       r0, 0x110(r31)
	  lwz       r7, 0x138(r31)
	  mulli     r5, r0, 0xC
	  addi      r0, r5, 0x8
	  lwzx      r5, r7, r0
	  lha       r0, 0x1A(r5)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1DC(r1)
	  stw       r30, 0x1D8(r1)
	  lfd       f0, 0x1D8(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x130(r31)
	  lwz       r0, 0x110(r31)
	  lwz       r8, 0x138(r31)
	  mulli     r7, r0, 0xC
	  lwz       r5, 0x134(r31)
	  addi      r0, r7, 0x4
	  lwzx      r8, r8, r0
	  lha       r7, 0x18(r8)
	  lha       r8, 0x1A(r8)
	  subi      r0, r7, 0x280
	  xoris     r7, r0, 0x8000
	  xoris     r0, r8, 0x8000
	  stw       r7, 0x1D4(r1)
	  stw       r0, 0x1CC(r1)
	  stw       r30, 0x1D0(r1)
	  stw       r30, 0x1C8(r1)
	  lfd       f1, 0x1D0(r1)
	  lfd       f0, 0x1C8(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x170DC
	  lwz       r0, 0x110(r31)
	  addi      r3, r31, 0x17C
	  lwz       r7, 0x138(r31)
	  addi      r4, r31, 0x4
	  mulli     r6, r0, 0xC
	  lfd       f2, -0x4660(r2)
	  lwz       r5, 0x134(r31)
	  addi      r0, r6, 0x8
	  lwzx      r8, r7, r0
	  addi      r6, r28, 0x2A72
	  lha       r7, 0x18(r8)
	  lha       r8, 0x1A(r8)
	  addi      r0, r7, 0x280
	  xoris     r7, r0, 0x8000
	  xoris     r0, r8, 0x8000
	  stw       r7, 0x1C4(r1)
	  stw       r0, 0x1BC(r1)
	  stw       r30, 0x1C0(r1)
	  stw       r30, 0x1B8(r1)
	  lfd       f1, 0x1C0(r1)
	  lfd       f0, 0x1B8(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x1707C
	  mr        r3, r31
	  bl        0x48C
	  mr        r3, r31
	  lmw       r27, 0x1FC(r1)
	  lwz       r0, 0x23C(r1)
	  lfd       f31, 0x230(r1)
	  lfd       f30, 0x228(r1)
	  lfd       f29, 0x220(r1)
	  lfd       f28, 0x218(r1)
	  lfd       f27, 0x210(r1)
	  addi      r1, r1, 0x238
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C3BF8
 * Size:	000054
 */
zen::DrawMenuItem::~DrawMenuItem()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x38
	  lwz       r3, 0x0(r30)
	  bl        -0x17CA70
	  extsh.    r0, r31
	  ble-      .loc_0x38
	  mr        r3, r30
	  bl        -0x17CA80

	.loc_0x38:
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
 * Address:	801C3C4C
 * Size:	00006C
 */
zen::DrawMenuItem::DrawMenuItem()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  li        r3, 0x18
	  bl        -0x17CC60
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  lfs       f0, -0x468C(r2)
	  li        r4, 0
	  li        r0, 0x1
	  stfs      f0, 0x10(r3)
	  stw       r4, 0x0(r3)
	  stb       r0, 0x14(r3)
	  stw       r4, 0x4(r3)
	  stw       r4, 0x0(r3)

	.loc_0x44:
	  stw       r3, 0x0(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x4(r31)
	  stw       r0, 0x8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C3CB8
 * Size:	00039C
 */
void zen::DrawMenu::start(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x1C8(r1)
	  stfd      f31, 0x1C0(r1)
	  stw       r31, 0x1BC(r1)
	  stw       r30, 0x1B8(r1)
	  stw       r29, 0x1B4(r1)
	  addi      r29, r3, 0
	  stw       r0, 0x100(r3)
	  lfs       f1, -0x468C(r2)
	  stfs      f1, 0x104(r3)
	  lfs       f0, -0x4690(r2)
	  stfs      f0, 0x108(r3)
	  stfs      f1, 0x10C(r3)
	  blt-      .loc_0x48
	  stw       r4, 0x110(r29)

	.loc_0x48:
	  li        r0, 0
	  stb       r0, 0x1D4(r29)
	  li        r30, 0
	  rlwinm    r31,r30,2,0,29
	  lfs       f31, -0x468C(r2)
	  b         .loc_0x100

	.loc_0x60:
	  lwz       r0, 0x110(r29)
	  lwz       r3, 0x13C(r29)
	  mulli     r4, r0, 0xC
	  lwz       r5, 0x138(r29)
	  lwzx      r3, r3, r31
	  addi      r0, r4, 0x4
	  lwz       r12, 0x0(r3)
	  lwzx      r4, r5, r0
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  mtlr      r12
	  subi      r4, r4, 0x280
	  blrl
	  lwz       r3, 0x13C(r29)
	  lwzx      r3, r3, r31
	  stfs      f31, 0xC0(r3)
	  stfs      f31, 0xC4(r3)
	  stfs      f31, 0xC8(r3)
	  lwz       r0, 0x110(r29)
	  lwz       r3, 0x140(r29)
	  mulli     r4, r0, 0xC
	  lwz       r5, 0x138(r29)
	  lwzx      r3, r3, r31
	  addi      r0, r4, 0x8
	  lwz       r12, 0x0(r3)
	  lwzx      r4, r5, r0
	  lwz       r12, 0x14(r12)
	  lha       r5, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  mtlr      r12
	  addi      r4, r4, 0x280
	  blrl
	  lwz       r3, 0x140(r29)
	  addi      r30, r30, 0x1
	  lwzx      r3, r3, r31
	  addi      r31, r31, 0x4
	  stfs      f31, 0xC0(r3)
	  stfs      f31, 0xC4(r3)
	  stfs      f31, 0xC8(r3)

	.loc_0x100:
	  lwz       r0, 0x118(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x60
	  lfs       f0, -0x468C(r2)
	  lis       r31, 0x4330
	  addi      r3, r29, 0
	  stfs      f0, 0x11C(r29)
	  lfs       f0, -0x4690(r2)
	  stfs      f0, 0x120(r29)
	  lwz       r0, 0x110(r29)
	  lwz       r5, 0x138(r29)
	  mulli     r4, r0, 0xC
	  lfd       f1, -0x4660(r2)
	  addi      r0, r4, 0x4
	  lwzx      r4, r5, r0
	  lha       r4, 0x18(r4)
	  subi      r0, r4, 0x280
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1AC(r1)
	  stw       r31, 0x1A8(r1)
	  lfd       f0, 0x1A8(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x124(r29)
	  lwz       r0, 0x110(r29)
	  lwz       r5, 0x138(r29)
	  mulli     r4, r0, 0xC
	  addi      r0, r4, 0x4
	  lwzx      r4, r5, r0
	  lha       r0, 0x1A(r4)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1A4(r1)
	  stw       r31, 0x1A0(r1)
	  lfd       f0, 0x1A0(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x128(r29)
	  lwz       r0, 0x110(r29)
	  lwz       r5, 0x138(r29)
	  mulli     r4, r0, 0xC
	  addi      r0, r4, 0x8
	  lwzx      r4, r5, r0
	  lha       r4, 0x18(r4)
	  addi      r0, r4, 0x280
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x19C(r1)
	  stw       r31, 0x198(r1)
	  lfd       f0, 0x198(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x12C(r29)
	  lwz       r0, 0x110(r29)
	  lwz       r5, 0x138(r29)
	  mulli     r4, r0, 0xC
	  addi      r0, r4, 0x8
	  lwzx      r4, r5, r0
	  lha       r0, 0x1A(r4)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x194(r1)
	  stw       r31, 0x190(r1)
	  lfd       f0, 0x190(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x130(r29)
	  bl        .loc_0x39C
	  lfs       f1, 0x120(r29)
	  li        r0, 0x1
	  lis       r30, 0x7A2A
	  stw       r0, 0x1B4(r29)
	  addi      r3, r29, 0x14C
	  addi      r4, r29, 0x4
	  lfs       f0, -0x468C(r2)
	  addi      r6, r30, 0x2A6C
	  stfs      f0, 0x1B8(r29)
	  stfs      f1, 0x1BC(r29)
	  stw       r0, 0x144(r29)
	  lwz       r0, 0x110(r29)
	  lwz       r8, 0x138(r29)
	  mulli     r7, r0, 0xC
	  lfd       f2, -0x4660(r2)
	  lwz       r5, 0x134(r29)
	  addi      r0, r7, 0x4
	  lwzx      r8, r8, r0
	  lha       r7, 0x18(r8)
	  lha       r8, 0x1A(r8)
	  subi      r0, r7, 0x280
	  xoris     r7, r0, 0x8000
	  xoris     r0, r8, 0x8000
	  stw       r7, 0x18C(r1)
	  stw       r0, 0x184(r1)
	  stw       r31, 0x188(r1)
	  stw       r31, 0x180(r1)
	  lfd       f1, 0x188(r1)
	  lfd       f0, 0x180(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x16D14
	  lwz       r0, 0x110(r29)
	  addi      r3, r29, 0x17C
	  lwz       r7, 0x138(r29)
	  addi      r4, r29, 0x4
	  mulli     r6, r0, 0xC
	  lfd       f2, -0x4660(r2)
	  lwz       r5, 0x134(r29)
	  addi      r0, r6, 0x8
	  lwzx      r8, r7, r0
	  addi      r6, r30, 0x2A72
	  lha       r7, 0x18(r8)
	  lha       r8, 0x1A(r8)
	  addi      r0, r7, 0x280
	  xoris     r7, r0, 0x8000
	  xoris     r0, r8, 0x8000
	  stw       r7, 0x17C(r1)
	  stw       r0, 0x174(r1)
	  stw       r31, 0x178(r1)
	  stw       r31, 0x170(r1)
	  lfd       f1, 0x178(r1)
	  lfd       f0, 0x170(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x16CB4
	  lwz       r0, 0x110(r29)
	  addi      r3, r29, 0x14C
	  lwz       r5, 0x138(r29)
	  mulli     r4, r0, 0xC
	  lfd       f2, -0x4660(r2)
	  lfs       f3, -0x4690(r2)
	  addi      r0, r4, 0x4
	  lwzx      r4, r5, r0
	  lha       r0, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  xoris     r4, r4, 0x8000
	  stw       r0, 0x164(r1)
	  stw       r4, 0x16C(r1)
	  stw       r31, 0x168(r1)
	  stw       r31, 0x160(r1)
	  lfd       f1, 0x168(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x16BCC
	  lwz       r0, 0x110(r29)
	  addi      r3, r29, 0x17C
	  lwz       r5, 0x138(r29)
	  mulli     r4, r0, 0xC
	  lfd       f2, -0x4660(r2)
	  lfs       f3, -0x4690(r2)
	  addi      r0, r4, 0x8
	  lwzx      r4, r5, r0
	  lha       r0, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  xoris     r4, r4, 0x8000
	  stw       r0, 0x154(r1)
	  stw       r4, 0x15C(r1)
	  stw       r31, 0x158(r1)
	  stw       r31, 0x150(r1)
	  lfd       f1, 0x158(r1)
	  lfd       f0, 0x150(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x16B78
	  lwz       r0, 0x1CC(r1)
	  lfd       f31, 0x1C0(r1)
	  lwz       r31, 0x1BC(r1)
	  lwz       r30, 0x1B8(r1)
	  lwz       r29, 0x1B4(r1)
	  addi      r1, r1, 0x1C8
	  mtlr      r0
	  blr

	.loc_0x39C:
	*/
}

/*
 * --INFO--
 * Address:	801C4054
 * Size:	00038C
 */
void zen::DrawMenu::updateMenuPanes()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stfd      f31, 0xE8(r1)
	  stfd      f30, 0xE0(r1)
	  stfd      f29, 0xD8(r1)
	  stfd      f28, 0xD0(r1)
	  stfd      f27, 0xC8(r1)
	  stw       r31, 0xC4(r1)
	  li        r31, 0
	  stw       r30, 0xC0(r1)
	  li        r30, 0
	  stw       r29, 0xBC(r1)
	  mr        r29, r3
	  stw       r28, 0xB8(r1)
	  lfs       f28, -0x468C(r2)
	  lfs       f30, -0x4654(r2)
	  lfs       f31, -0x4688(r2)
	  lfs       f29, -0x4658(r2)
	  lfs       f27, -0x4690(r2)
	  b         .loc_0x33C

	.loc_0x54:
	  lwz       r0, 0x110(r29)
	  cmpw      r30, r0
	  bne-      .loc_0x80
	  lwz       r0, 0x138(r29)
	  addi      r5, r29, 0x1AC
	  addi      r6, r29, 0x1B0
	  add       r3, r0, r31
	  lwz       r3, 0x0(r3)
	  li        r4, 0x1
	  bl        -0x17B0
	  b         .loc_0x9C

	.loc_0x80:
	  lwz       r0, 0x138(r29)
	  addi      r5, r29, 0x1AC
	  addi      r6, r29, 0x1B0
	  add       r3, r0, r31
	  lwz       r3, 0x0(r3)
	  li        r4, 0
	  bl        -0x17D0

	.loc_0x9C:
	  lwz       r0, 0x100(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x168
	  bge-      .loc_0xB8
	  cmpwi     r0, 0x1
	  bge-      .loc_0xC4
	  b         .loc_0x334

	.loc_0xB8:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x334
	  b         .loc_0x1EC

	.loc_0xC4:
	  lfs       f0, 0x10C(r29)
	  fsubs     f0, f0, f27
	  fmuls     f0, f29, f0
	  fcmpo     cr0, f0, f28
	  fmr       f1, f0
	  bge-      .loc_0xE0
	  fmr       f1, f28

	.loc_0xE0:
	  fsubs     f0, f29, f1
	  lwz       r0, 0x138(r29)
	  addi      r3, r1, 0x98
	  stfs      f1, 0x90(r1)
	  add       r6, r0, r31
	  stfs      f0, 0x94(r1)
	  addi      r4, r1, 0x94
	  addi      r5, r1, 0x90
	  lwz       r28, 0x0(r6)
	  addi      r6, r13, 0x1B68
	  bl        -0x18D040
	  lwz       r4, 0x0(r28)
	  lwz       r3, 0x98(r1)
	  lwz       r0, 0x9C(r1)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r0, 0xA0(r1)
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0x4(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x334
	  addi      r3, r1, 0xA4
	  addi      r4, r1, 0x94
	  addi      r5, r1, 0x90
	  addi      r6, r13, 0x1B6C
	  bl        -0x18D07C
	  lwz       r4, 0x4(r28)
	  lwz       r3, 0xA4(r1)
	  lwz       r0, 0xA8(r1)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r0, 0xAC(r1)
	  stw       r0, 0xC8(r4)
	  b         .loc_0x334

	.loc_0x168:
	  lwz       r0, 0x138(r29)
	  addi      r3, r1, 0x78
	  addi      r4, r1, 0x74
	  stfs      f31, 0x70(r1)
	  add       r7, r0, r31
	  addi      r5, r1, 0x70
	  stfs      f31, 0x74(r1)
	  addi      r6, r13, 0x1B68
	  lwz       r28, 0x0(r7)
	  bl        -0x18D0C4
	  lwz       r4, 0x0(r28)
	  lwz       r3, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r0, 0x80(r1)
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0x4(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x334
	  addi      r3, r1, 0x84
	  addi      r4, r1, 0x74
	  addi      r5, r1, 0x70
	  addi      r6, r13, 0x1B6C
	  bl        -0x18D100
	  lwz       r4, 0x4(r28)
	  lwz       r3, 0x84(r1)
	  lwz       r0, 0x88(r1)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r0, 0x8C(r1)
	  stw       r0, 0xC8(r4)
	  b         .loc_0x334

	.loc_0x1EC:
	  lwz       r0, 0x1D0(r29)
	  cmpwi     r0, 0
	  blt-      .loc_0x204
	  lwz       r0, 0x110(r29)
	  cmpw      r30, r0
	  beq-      .loc_0x2A4

	.loc_0x204:
	  lfs       f1, 0x10C(r29)
	  fmuls     f0, f29, f1
	  fsubs     f2, f31, f0
	  fcmpo     cr0, f2, f28
	  bge-      .loc_0x21C
	  fmr       f2, f28

	.loc_0x21C:
	  fadds     f0, f31, f1
	  lwz       r0, 0x138(r29)
	  addi      r3, r1, 0x58
	  stfs      f2, 0x50(r1)
	  add       r6, r0, r31
	  stfs      f0, 0x54(r1)
	  addi      r4, r1, 0x54
	  addi      r5, r1, 0x50
	  lwz       r28, 0x0(r6)
	  addi      r6, r13, 0x1B68
	  bl        -0x18D17C
	  lwz       r4, 0x0(r28)
	  lwz       r3, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0x4(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x334
	  addi      r3, r1, 0x64
	  addi      r4, r1, 0x54
	  addi      r5, r1, 0x50
	  addi      r6, r13, 0x1B6C
	  bl        -0x18D1B8
	  lwz       r4, 0x4(r28)
	  lwz       r3, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0xC8(r4)
	  b         .loc_0x334

	.loc_0x2A4:
	  lfs       f0, 0x10C(r29)
	  fmuls     f1, f30, f0
	  bl        0x579E8
	  fadds     f0, f31, f1
	  lwz       r0, 0x138(r29)
	  addi      r3, r1, 0x38
	  stfs      f31, 0x34(r1)
	  add       r6, r0, r31
	  stfs      f0, 0x30(r1)
	  addi      r4, r1, 0x34
	  addi      r5, r1, 0x30
	  lwz       r28, 0x0(r6)
	  addi      r6, r13, 0x1B68
	  bl        -0x18D210
	  lwz       r4, 0x0(r28)
	  lwz       r3, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r0, 0x40(r1)
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0x4(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x334
	  addi      r3, r1, 0x44
	  addi      r4, r1, 0x34
	  addi      r5, r1, 0x30
	  addi      r6, r13, 0x1B6C
	  bl        -0x18D24C
	  lwz       r4, 0x4(r28)
	  lwz       r3, 0x44(r1)
	  lwz       r0, 0x48(r1)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r0, 0x4C(r1)
	  stw       r0, 0xC8(r4)

	.loc_0x334:
	  addi      r31, r31, 0xC
	  addi      r30, r30, 0x1

	.loc_0x33C:
	  lwz       r0, 0x114(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x54
	  addi      r3, r29, 0x14C
	  bl        0x16474
	  addi      r3, r29, 0x17C
	  bl        0x1646C
	  lwz       r0, 0xF4(r1)
	  lfd       f31, 0xE8(r1)
	  lfd       f30, 0xE0(r1)
	  lfd       f29, 0xD8(r1)
	  lfd       f28, 0xD0(r1)
	  lfd       f27, 0xC8(r1)
	  lwz       r31, 0xC4(r1)
	  lwz       r30, 0xC0(r1)
	  lwz       r29, 0xBC(r1)
	  lwz       r28, 0xB8(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void zen::DrawMenu::setMirror(P2DPane*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003E4
 */
void zen::DrawMenu::updateSpectPanes(P2DPane*, P2DPicture**, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C43E0
 * Size:	0000F4
 */
void zen::DrawMenu::updateSelectMenuNo(Controller*)
{
	/*
	.loc_0x0:
	  lwz       r7, 0x28(r4)
	  lwz       r0, 0x110(r3)
	  rlwinm    r4,r7,0,12,12
	  neg       r6, r4
	  subic     r5, r6, 0x1
	  rlwinm    r4,r7,0,10,10
	  subfe     r6, r5, r6
	  neg       r5, r4
	  subic     r4, r5, 0x1
	  subfe     r4, r4, r5
	  rlwinm    r5,r6,0,24,31
	  rlwinm    r4,r4,0,24,31
	  sub       r4, r4, r5
	  add       r0, r0, r4
	  stw       r0, 0x110(r3)
	  mr        r5, r4
	  lwz       r0, 0x110(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x58
	  lwz       r4, 0x114(r3)
	  subi      r0, r4, 0x1
	  stw       r0, 0x110(r3)

	.loc_0x58:
	  lwz       r4, 0x110(r3)
	  lwz       r0, 0x114(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x70
	  li        r0, 0
	  stw       r0, 0x110(r3)

	.loc_0x70:
	  lwz       r0, 0x110(r3)
	  lwz       r4, 0x138(r3)
	  mulli     r0, r0, 0xC
	  lwzx      r4, r4, r0
	  lbz       r0, 0x14(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0xA4
	  cmpwi     r5, 0
	  bne-      .loc_0x98
	  li        r5, 0x1

	.loc_0x98:
	  lwz       r0, 0x110(r3)
	  add       r0, r0, r5
	  stw       r0, 0x110(r3)

	.loc_0xA4:
	  lwz       r0, 0x110(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0xBC
	  lwz       r4, 0x114(r3)
	  subi      r0, r4, 0x1
	  stw       r0, 0x110(r3)

	.loc_0xBC:
	  lwz       r4, 0x110(r3)
	  lwz       r0, 0x114(r3)
	  cmpw      r4, r0
	  blt-      .loc_0xD4
	  li        r0, 0
	  stw       r0, 0x110(r3)

	.loc_0xD4:
	  lwz       r0, 0x110(r3)
	  lwz       r4, 0x138(r3)
	  mulli     r0, r0, 0xC
	  lwzx      r4, r4, r0
	  lbz       r0, 0x14(r4)
	  cmplwi    r0, 0
	  beq+      .loc_0x70
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C44D4
 * Size:	00040C
 */
void zen::DrawMenu::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stw       r31, 0xEC(r1)
	  stw       r30, 0xE8(r1)
	  li        r30, 0
	  stw       r29, 0xE4(r1)
	  mr        r29, r4
	  stw       r28, 0xE0(r1)
	  mr        r28, r3
	  lwz       r0, 0x100(r3)
	  lwz       r31, 0x110(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x3E8
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x104(r28)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x104(r28)
	  lfs       f0, 0x104(r28)
	  lfs       f1, 0x108(r28)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x60
	  stfs      f1, 0x104(r28)

	.loc_0x60:
	  lfs       f1, 0x104(r28)
	  lfs       f0, 0x108(r28)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x10C(r28)
	  lwz       r0, 0x100(r28)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xEC
	  bge-      .loc_0x8C
	  cmpwi     r0, 0x1
	  bge-      .loc_0x98
	  b         .loc_0x3C4

	.loc_0x8C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x3C4
	  b         .loc_0x328

	.loc_0x98:
	  lfs       f1, -0x4688(r2)
	  lfs       f0, 0x10C(r28)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x3C4
	  addi      r3, r28, 0x1B4
	  bl        0x5920
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C4
	  lfs       f1, -0x468C(r2)
	  li        r0, 0x2
	  stfs      f1, 0x104(r28)
	  lfs       f0, -0x4650(r2)
	  stfs      f0, 0x108(r28)
	  stfs      f1, 0x10C(r28)
	  stw       r0, 0x100(r28)
	  stw       r0, 0x1B4(r28)
	  stfs      f1, 0x1B8(r28)
	  lfs       f0, -0x4688(r2)
	  stfs      f0, 0x1BC(r28)
	  stw       r0, 0x144(r28)
	  b         .loc_0x3C4

	.loc_0xEC:
	  lfs       f1, -0x4688(r2)
	  lfs       f0, 0x10C(r28)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x3C4
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0x1F8
	  lwz       r0, 0x28(r29)
	  andis.    r0, r0, 0x28
	  beq-      .loc_0x278
	  lwz       r0, 0x110(r28)
	  cmpw      r0, r31
	  beq-      .loc_0x270
	  li        r3, 0x112
	  bl        -0x11F284
	  lfs       f0, -0x468C(r2)
	  lis       r31, 0x4330
	  addi      r3, r28, 0x14C
	  stfs      f0, 0x11C(r28)
	  lwz       r4, 0x13C(r28)
	  lfd       f2, -0x4660(r2)
	  lwz       r4, 0x0(r4)
	  lha       r0, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xDC(r1)
	  stw       r31, 0xD8(r1)
	  lfd       f0, 0xD8(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x124(r28)
	  lwz       r4, 0x13C(r28)
	  lwz       r4, 0x0(r4)
	  lha       r0, 0x1A(r4)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xD4(r1)
	  stw       r31, 0xD0(r1)
	  lfd       f0, 0xD0(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x128(r28)
	  lwz       r4, 0x140(r28)
	  lwz       r4, 0x0(r4)
	  lha       r0, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xCC(r1)
	  stw       r31, 0xC8(r1)
	  lfd       f0, 0xC8(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x12C(r28)
	  lwz       r4, 0x140(r28)
	  lwz       r4, 0x0(r4)
	  lha       r0, 0x1A(r4)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xC4(r1)
	  stw       r31, 0xC0(r1)
	  lfd       f0, 0xC0(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x130(r28)
	  lwz       r0, 0x110(r28)
	  lwz       r5, 0x138(r28)
	  mulli     r4, r0, 0xC
	  lfs       f3, -0x4690(r2)
	  addi      r0, r4, 0x4
	  lwzx      r4, r5, r0
	  lha       r0, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  xoris     r4, r4, 0x8000
	  stw       r0, 0xB4(r1)
	  stw       r4, 0xBC(r1)
	  stw       r31, 0xB8(r1)
	  stw       r31, 0xB0(r1)
	  lfd       f1, 0xB8(r1)
	  lfd       f0, 0xB0(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x164C0
	  lwz       r0, 0x110(r28)
	  addi      r3, r28, 0x17C
	  lwz       r5, 0x138(r28)
	  mulli     r4, r0, 0xC
	  lfd       f2, -0x4660(r2)
	  lfs       f3, -0x4690(r2)
	  addi      r0, r4, 0x8
	  lwzx      r4, r5, r0
	  lha       r0, 0x1A(r4)
	  lha       r4, 0x18(r4)
	  xoris     r0, r0, 0x8000
	  xoris     r4, r4, 0x8000
	  stw       r0, 0xA4(r1)
	  stw       r4, 0xAC(r1)
	  stw       r31, 0xA8(r1)
	  stw       r31, 0xA0(r1)
	  lfd       f1, 0xA8(r1)
	  lfd       f0, 0xA0(r1)
	  fsubs     f1, f1, f2
	  fsubs     f2, f0, f2
	  bl        0x1646C
	  b         .loc_0x278

	.loc_0x270:
	  li        r3, 0x119
	  bl        -0x11F3D4

	.loc_0x278:
	  lwz       r3, 0x28(r29)
	  lwz       r0, 0x1C4(r28)
	  and.      r0, r3, r0
	  beq-      .loc_0x298
	  li        r3, 0x111
	  bl        -0x11F3EC
	  li        r0, 0x3
	  stw       r0, 0x100(r28)

	.loc_0x298:
	  lwz       r3, 0x28(r29)
	  lwz       r0, 0x1C8(r28)
	  and.      r0, r3, r0
	  beq-      .loc_0x2D0
	  lwz       r3, 0x1CC(r28)
	  bl        -0x11F40C
	  li        r0, 0x3
	  stw       r0, 0x100(r28)
	  li        r0, 0x1
	  stb       r0, 0x1D4(r28)
	  lwz       r0, 0x1D0(r28)
	  cmpwi     r0, 0
	  blt-      .loc_0x2D0
	  stw       r0, 0x110(r28)

	.loc_0x2D0:
	  lwz       r0, 0x100(r28)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x3C4
	  lfs       f1, -0x468C(r2)
	  li        r29, 0x3
	  addi      r3, r28, 0x14C
	  stfs      f1, 0x104(r28)
	  lfs       f0, -0x4690(r2)
	  stfs      f0, 0x108(r28)
	  stfs      f1, 0x10C(r28)
	  lfs       f0, 0x108(r28)
	  stw       r29, 0x1B4(r28)
	  stfs      f1, 0x1B8(r28)
	  stfs      f0, 0x1BC(r28)
	  lfs       f2, 0x108(r28)
	  bl        0x16438
	  lfs       f1, -0x468C(r2)
	  addi      r3, r28, 0x17C
	  lfs       f2, 0x108(r28)
	  bl        0x16428
	  stw       r29, 0x144(r28)
	  b         .loc_0x3C4

	.loc_0x328:
	  lfs       f1, -0x4688(r2)
	  lfs       f0, 0x10C(r28)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x3C4
	  addi      r3, r28, 0x1B4
	  bl        0x5690
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C4
	  lfs       f1, 0x154(r28)
	  li        r0, 0
	  lfs       f0, 0x158(r28)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x378
	  lfs       f1, 0x16C(r28)
	  lfs       f0, 0x170(r28)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x378
	  li        r0, 0x1

	.loc_0x378:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x3C4
	  lfs       f1, 0x184(r28)
	  li        r0, 0
	  lfs       f0, 0x188(r28)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3B0
	  lfs       f1, 0x19C(r28)
	  lfs       f0, 0x1A0(r28)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3B0
	  li        r0, 0x1

	.loc_0x3B0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x3C4
	  li        r0, 0
	  stw       r0, 0x100(r28)
	  li        r30, 0x1

	.loc_0x3C4:
	  mr        r3, r28
	  bl        -0x848
	  addi      r3, r28, 0x1B4
	  bl        0x5588
	  mr        r3, r28
	  bl        -0x5230
	  addi      r3, r28, 0x144
	  lfs       f1, 0x10C(r28)
	  bl        -0x192C

	.loc_0x3E8:
	  mr        r3, r30
	  lwz       r0, 0xF4(r1)
	  lwz       r31, 0xEC(r1)
	  lwz       r30, 0xE8(r1)
	  lwz       r29, 0xE4(r1)
	  lwz       r28, 0xE0(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C48E0
 * Size:	00002C
 */
void zen::DrawMenu::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x100(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x1C
	  bl        -0x5258

	.loc_0x1C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C490C
 * Size:	00002C
 */
void zen::DrawMenu::setMenuItemActiveSw(int, bool)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bltlr-
	  lwz       r0, 0x114(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x18
	  blr

	.loc_0x18:
	  mulli     r0, r4, 0xC
	  lwz       r3, 0x138(r3)
	  lwzx      r3, r3, r0
	  stb       r5, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C4938
 * Size:	000028
 */
void zen::DrawMenu::setCancelSelectMenuNo(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bge-      .loc_0x14
	  li        r0, -0x1
	  stw       r0, 0x1D0(r3)
	  blr

	.loc_0x14:
	  lwz       r0, 0x114(r3)
	  cmpw      r4, r0
	  bgelr-
	  stw       r4, 0x1D0(r3)
	  blr
	*/
}
