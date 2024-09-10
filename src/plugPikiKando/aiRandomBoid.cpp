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
 * Address:	800C0A10
 * Size:	0002F8
 */
void ActRandomBoid::AnimListener::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  stfd      f30, 0xB8(r1)
	  stw       r31, 0xB4(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xB0(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2D8
	  bge-      .loc_0x2D8
	  cmpwi     r0, 0
	  bge-      .loc_0x3C
	  b         .loc_0x2D8

	.loc_0x3C:
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stb       r0, 0x1C(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x74
	  bge-      .loc_0x68
	  cmpwi     r0, 0
	  bge-      .loc_0x288
	  b         .loc_0x2D8

	.loc_0x68:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x2D8
	  b         .loc_0x254

	.loc_0x74:
	  bl        0x1575EC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0xAC(r1)
	  lis       r30, 0x4330
	  lfs       f3, -0x6BA4(r2)
	  stw       r30, 0xA8(r1)
	  lfs       f2, -0x6BA8(r2)
	  lfd       f1, 0xA8(r1)
	  lfs       f0, -0x6B9C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x6BA0(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f31, f1, f0
	  bl        0x1575AC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0xA4(r1)
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0xA0(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0xA0(r1)
	  lfs       f0, -0x6B98(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x15C
	  addi      r3, r1, 0x8C
	  li        r4, 0
	  bl        0x5E454
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x94
	  li        r4, 0
	  bl        0x5E474
	  mr        r4, r3
	  lwz       r3, 0x8(r31)
	  mr        r5, r30
	  bl        0x9EB0
	  fmr       f1, f31
	  bl        0x15B1B8
	  fmr       f30, f1
	  fmr       f1, f31
	  bl        0x15B018
	  stfs      f1, 0x7C(r1)
	  addi      r4, r1, 0x80
	  lfs       f0, -0x4618(r13)
	  lfs       f2, 0x7C(r1)
	  lfs       f1, -0x6B94(r2)
	  stfs      f2, 0x80(r1)
	  stfs      f0, 0x84(r1)
	  stfs      f30, 0x88(r1)
	  lwz       r3, 0x8(r31)
	  bl        0xB274
	  b         .loc_0x2D8

	.loc_0x15C:
	  bl        0x157504
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0xA4(r1)
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0xA0(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0xA0(r1)
	  lfs       f0, -0x6B98(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1E4
	  addi      r3, r1, 0x6C
	  li        r4, 0
	  bl        0x5E3AC
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x74
	  li        r4, 0
	  bl        0x5E3CC
	  mr        r4, r3
	  lwz       r3, 0x8(r31)
	  mr        r5, r30
	  bl        0x9E08
	  lwz       r3, 0x8(r31)
	  lfs       f0, -0x4614(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4610(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x460C(r13)
	  stfs      f0, 0x8(r3)
	  b         .loc_0x2D8

	.loc_0x1E4:
	  addi      r3, r1, 0x5C
	  li        r4, 0
	  bl        0x5E35C
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x64
	  li        r4, 0
	  bl        0x5E37C
	  mr        r4, r3
	  lwz       r3, 0x8(r31)
	  mr        r5, r30
	  bl        0x9DB8
	  fmr       f1, f31
	  bl        0x15B0C0
	  fmr       f30, f1
	  fmr       f1, f31
	  bl        0x15AF20
	  stfs      f1, 0x4C(r1)
	  addi      r4, r1, 0x50
	  lfs       f0, -0x4608(r13)
	  lfs       f2, 0x4C(r1)
	  lfs       f1, -0x6B90(r2)
	  stfs      f2, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f30, 0x58(r1)
	  lwz       r3, 0x8(r31)
	  bl        0xB17C
	  b         .loc_0x2D8

	.loc_0x254:
	  addi      r3, r1, 0x3C
	  li        r4, 0
	  bl        0x5E2EC
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x44
	  li        r4, 0
	  bl        0x5E30C
	  mr        r4, r3
	  lwz       r3, 0x8(r31)
	  mr        r5, r30
	  bl        0x9D48
	  b         .loc_0x2D8

	.loc_0x288:
	  addi      r3, r1, 0x2C
	  li        r4, 0
	  bl        0x5E2B8
	  addi      r30, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x34
	  li        r4, 0
	  bl        0x5E2D8
	  mr        r4, r3
	  lwz       r3, 0x8(r31)
	  mr        r5, r30
	  bl        0x9D14
	  bl        0x1573A8
	  lwz       r3, 0x8(r31)
	  lfs       f0, -0x4604(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x4600(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x45FC(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x2D8:
	  lwz       r0, 0xCC(r1)
	  lfd       f31, 0xC0(r1)
	  lfd       f30, 0xB8(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C0D08
 * Size:	00008C
 */
ActRandomBoid::ActRandomBoid(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        0x30A4
	  lis       r3, 0x802B
	  lwz       r31, 0x8(r1)
	  addi      r0, r3, 0x7734
	  stw       r0, 0x0(r31)
	  li        r3, 0x10
	  bl        -0x79D40
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  lis       r4, 0x802B
	  subi      r0, r4, 0x246C
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x7828
	  stw       r0, 0x0(r3)
	  stw       r31, 0x4(r3)
	  stw       r30, 0x8(r3)

	.loc_0x68:
	  lwz       r4, 0x8(r1)
	  stw       r3, 0x24(r4)
	  mr        r3, r4
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
 * Address:	800C0D94
 * Size:	000004
 */
void ActRandomBoid::Initialiser::initialise(Action*) { }

/*
 * --INFO--
 * Address:	800C0D98
 * Size:	0000E8
 */
void ActRandomBoid::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  stw       r0, 0x14(r3)
	  bl        0x1572B8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x6BA4(r2)
	  stw       r0, 0x38(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x38(r1)
	  lfs       f0, -0x6B80(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r3, 0x34(r1)
	  addi      r0, r3, 0x14
	  stw       r0, 0x18(r30)
	  bl        0x15726C
	  lwz       r5, 0xC(r30)
	  addi      r3, r1, 0x1C
	  lfs       f0, -0x45F8(r13)
	  li        r4, 0
	  stfsu     f0, 0xA4(r5)
	  lfs       f0, -0x45F4(r13)
	  stfs      f0, 0x4(r5)
	  lfs       f0, -0x45F0(r13)
	  stfs      f0, 0x8(r5)
	  lwz       r5, 0x24(r30)
	  bl        0x5E15C
	  lwz       r5, 0x24(r30)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x24
	  li        r4, 0
	  bl        0x5E148
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x9B84
	  lwz       r3, 0x24(r30)
	  li        r0, 0
	  stb       r0, 0xC(r3)
	  stb       r0, 0x1C(r30)
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C0E80
 * Size:	000004
 */
void ActRandomBoid::cleanup() { }

/*
 * --INFO--
 * Address:	800C0E84
 * Size:	0003BC
 */
void ActRandomBoid::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1C8(r1)
	  stw       r31, 0x1C4(r1)
	  mr        r31, r3
	  stw       r30, 0x1C0(r1)
	  stw       r29, 0x1BC(r1)
	  lbz       r0, 0x1C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lwz       r4, 0xC(r31)
	  li        r3, 0
	  lfs       f0, -0x45EC(r13)
	  stfsu     f0, 0xA4(r4)
	  lfs       f0, -0x45E8(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x45E4(r13)
	  stfs      f0, 0x8(r4)
	  b         .loc_0x3A0

	.loc_0x4C:
	  lwz       r3, 0x18(r31)
	  subic.    r0, r3, 0x1
	  stw       r0, 0x18(r31)
	  bge-      .loc_0x2A8
	  bl        0x157190
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x1B4(r1)
	  lis       r30, 0x4330
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0x1B0(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x1B0(r1)
	  lfs       f0, -0x6B7C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x1A8(r1)
	  lwz       r3, 0x1AC(r1)
	  addi      r0, r3, 0x26
	  stw       r0, 0x18(r31)
	  lwz       r29, 0x14(r31)
	  cmpwi     r29, 0x1
	  bne-      .loc_0x160
	  bl        0x157138
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x1AC(r1)
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0x1A8(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x1A8(r1)
	  lfs       f0, -0x6B78(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x160
	  li        r0, 0x3
	  stw       r0, 0x14(r31)
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x24(r31)
	  addi      r3, r3, 0x354
	  bl        0x5EB3C
	  li        r0, 0x1
	  stb       r0, 0x1C(r31)
	  bl        0x1570E0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x1AC(r1)
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0x1A8(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x1A8(r1)
	  lfs       f0, -0x6B74(r2)
	  fsubs     f3, f3, f4
	  lwz       r3, 0x18(r31)
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x1B0(r1)
	  lwz       r0, 0x1B4(r1)
	  add       r3, r0, r3
	  addi      r0, r3, 0x1E
	  stw       r0, 0x18(r31)
	  b         .loc_0x2A0

	.loc_0x160:
	  bl        0x15708C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x1AC(r1)
	  lis       r30, 0x4330
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0x1A8(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x1A8(r1)
	  lfs       f0, -0x6B70(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x25C
	  bl        0x157050
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6B88(r2)
	  stw       r0, 0x1AC(r1)
	  lfs       f2, -0x6BA4(r2)
	  stw       r30, 0x1A8(r1)
	  lfs       f1, -0x6BA8(r2)
	  lfd       f3, 0x1A8(r1)
	  lfs       f0, -0x6B6C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x200
	  li        r0, 0
	  cmpwi     r29, 0
	  stw       r0, 0x14(r31)
	  beq-      .loc_0x22C
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x24(r31)
	  addi      r3, r3, 0x354
	  bl        0x5EA4C
	  li        r0, 0x1
	  stb       r0, 0x1C(r31)
	  b         .loc_0x22C

	.loc_0x200:
	  li        r30, 0x1
	  cmpwi     r29, 0x2
	  stw       r30, 0x14(r31)
	  beq-      .loc_0x22C
	  cmpwi     r29, 0x1
	  beq-      .loc_0x22C
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x24(r31)
	  addi      r3, r3, 0x354
	  bl        0x5EA18
	  stb       r30, 0x1C(r31)

	.loc_0x22C:
	  bl        0x156FC0
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x45E0(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x45DC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x45D8(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0x18(r31)
	  addi      r0, r3, 0x78
	  stw       r0, 0x18(r31)
	  b         .loc_0x2A0

	.loc_0x25C:
	  lwz       r3, 0x18(r31)
	  cmpwi     r29, 0x2
	  li        r0, 0x2
	  addi      r3, r3, 0x78
	  stw       r3, 0x18(r31)
	  stw       r0, 0x14(r31)
	  bne-      .loc_0x280
	  cmpwi     r29, 0x1
	  beq-      .loc_0x2A0

	.loc_0x280:
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x24(r31)
	  addi      r3, r3, 0x354
	  bl        0x5E9B0
	  li        r0, 0x1
	  stb       r0, 0x1C(r31)
	  li        r3, 0
	  b         .loc_0x3A0

	.loc_0x2A0:
	  li        r3, 0
	  b         .loc_0x3A0

	.loc_0x2A8:
	  lwz       r0, 0x14(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x2BC
	  li        r0, 0x1
	  stw       r0, 0x18(r31)

	.loc_0x2BC:
	  lwz       r0, 0x14(r31)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x2E4
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x45D4(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x45D0(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x45CC(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x2E4:
	  lfs       f0, -0x6B90(r2)
	  addi      r5, r1, 0x15C
	  stfs      f0, 0x164(r1)
	  stfs      f0, 0x160(r1)
	  stfs      f0, 0x15C(r1)
	  lwz       r3, 0xC(r31)
	  addi      r4, r3, 0xA4
	  bl        -0x33C48
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x39C
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6B78(r2)
	  bl        0xABCC
	  lfs       f0, 0x15C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x110(r1)
	  lfs       f0, 0x160(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x114(r1)
	  lfs       f0, 0x164(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x118(r1)
	  lwz       r3, 0xC(r31)
	  lfs       f0, 0x110(r1)
	  lfs       f1, 0xA4(r3)
	  addi      r4, r3, 0xA4
	  fadds     f0, f1, f0
	  stfs      f0, 0xF8(r1)
	  lfs       f0, 0xF8(r1)
	  stfs      f0, 0x11C(r1)
	  lfs       f1, 0xA8(r3)
	  lfs       f0, 0x114(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x120(r1)
	  lfs       f1, 0xAC(r3)
	  lfs       f0, 0x118(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x124(r1)
	  lwz       r3, 0x11C(r1)
	  lwz       r0, 0x120(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x124(r1)
	  stw       r0, 0x8(r4)

	.loc_0x39C:
	  li        r3, 0

	.loc_0x3A0:
	  lwz       r0, 0x1CC(r1)
	  lwz       r31, 0x1C4(r1)
	  lwz       r30, 0x1C0(r1)
	  lwz       r29, 0x1BC(r1)
	  addi      r1, r1, 0x1C8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C1240
 * Size:	000044
 */
void ActRandomBoid::getInfo(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  crclr     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x14(r3)
	  lis       r3, 0x802B
	  rlwinm    r5,r0,2,0,29
	  addi      r0, r3, 0x76E8
	  add       r3, r0, r5
	  lwz       r5, 0x0(r3)
	  addi      r3, r4, 0
	  subi      r4, r13, 0x45B8
	  bl        0x155328
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C1284
 * Size:	000064
 */
ActRandomBoid::~ActRandomBoid()
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
	  beq-      .loc_0x48
	  lis       r3, 0x802B
	  addi      r0, r3, 0x7734
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x2B50
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x7A11C

	.loc_0x48:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
