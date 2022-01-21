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
 * Address:	800BA600
 * Size:	0000CC
 */
ActFree::ActFree(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  extsh.    r0, r4
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r5
	  stw       r3, 0x8(r1)
	  beq-      .loc_0x3C
	  lwz       r4, 0x8(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x246C
	  addi      r3, r4, 0x48
	  stw       r3, 0x14(r4)
	  stw       r0, 0x48(r4)

	.loc_0x3C:
	  lwz       r3, 0x8(r1)
	  addi      r4, r30, 0
	  li        r5, 0x1
	  bl        0x9788
	  lwz       r7, 0x8(r1)
	  lis       r3, 0x802B
	  addi      r3, r3, 0x6AC8
	  stw       r3, 0x0(r7)
	  addi      r6, r3, 0x68
	  addi      r4, r7, 0x48
	  lwz       r5, 0x14(r7)
	  subi      r0, r13, 0x48C0
	  li        r3, 0x20
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r7)
	  sub       r4, r4, r5
	  stw       r4, 0x4(r5)
	  lfs       f0, -0x6D00(r2)
	  stfs      f0, 0x38(r7)
	  stfs      f0, 0x34(r7)
	  stfs      f0, 0x30(r7)
	  stw       r0, 0x10(r7)
	  bl        -0x73690
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xAC
	  mr        r4, r30
	  bl        -0x1018C

	.loc_0xAC:
	  lwz       r3, 0x8(r1)
	  stw       r31, 0x18(r3)
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
 * Address:	800BA6CC
 * Size:	0000D0
 */
void ActFree::initBoid(Vector3f&, float)
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
	  stb       r0, 0x46(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x30(r30)
	  stw       r0, 0x34(r30)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x38(r30)
	  stfs      f1, 0x3C(r30)
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  addi      r3, r1, 0x2C
	  li        r4, 0x4
	  bl        0x64838
	  addi      r31, r3, 0
	  addi      r3, r1, 0x34
	  li        r4, 0x4
	  bl        0x64828
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x10298
	  lwz       r3, 0xC(r30)
	  bl        0x104C4
	  b         .loc_0xB0

	.loc_0x84:
	  addi      r3, r1, 0x1C
	  li        r4, 0x2
	  bl        0x64800
	  addi      r31, r3, 0
	  addi      r3, r1, 0x24
	  li        r4, 0x2
	  bl        0x647F0
	  mr        r4, r3
	  lwz       r3, 0xC(r30)
	  mr        r5, r31
	  bl        0x10260

	.loc_0xB0:
	  lfs       f0, -0x6CFC(r2)
	  stfs      f0, 0x28(r30)
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
 * Address:	800BA79C
 * Size:	0001C4
 */
void ActFree::exeBoid()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stw       r31, 0xAC(r1)
	  mr        r31, r3
	  stw       r30, 0xA8(r1)
	  stw       r29, 0xA4(r1)
	  lwz       r3, 0xC(r3)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x30(r31)
	  lfs       f3, 0x34(r31)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x38(r31)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x90(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  lfs       f2, 0x98(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xACBCC
	  lfs       f0, -0x6D00(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xA4
	  lfs       f0, 0x90(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x94(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x98(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x98(r1)

	.loc_0xA4:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x28(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f2, f0
	  stfs      f0, 0x28(r31)
	  lfs       f2, -0x6CF8(r2)
	  lfs       f0, 0x3C(r31)
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  blt-      .loc_0xE0
	  lfs       f1, 0x28(r31)
	  lfs       f0, -0x6D00(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x198

	.loc_0xE0:
	  lwz       r4, 0xC(r31)
	  li        r0, 0
	  lwz       r3, 0xC8(r4)
	  oris      r3, r3, 0x40
	  stw       r3, 0xC8(r4)
	  lfs       f0, -0x6CFC(r2)
	  stfs      f0, 0x2C(r31)
	  stb       r0, 0x46(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x48B4(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x48B0(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x48AC(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A8
	  lwz       r0, 0x39C(r3)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x1A8
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x148
	  lwz       r29, 0x14(r31)

	.loc_0x148:
	  addi      r3, r1, 0x70
	  li        r4, 0x4
	  bl        0x6466C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x78
	  li        r4, 0x4
	  bl        0x6468C
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x100C8
	  lfs       f0, -0x6CF4(r2)
	  lwz       r3, 0xC(r31)
	  stfs      f0, 0x384(r3)
	  lwz       r3, 0xC(r31)
	  stfs      f0, 0x3D8(r3)
	  lwz       r3, 0xC(r31)
	  bl        0x102E0
	  b         .loc_0x1A8

	.loc_0x198:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x90
	  lfs       f1, -0x6CF0(r2)
	  bl        0x11498

	.loc_0x1A8:
	  lwz       r0, 0xB4(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  lwz       r29, 0xA4(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BA960
 * Size:	0002F4
 */
void ActFree::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0xC0(r1)
	  stw       r31, 0xBC(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xB8(r1)
	  stw       r29, 0xB4(r1)
	  stb       r0, 0x46(r3)
	  lfs       f0, -0x6CEC(r2)
	  stfs      f0, 0x40(r3)
	  bl        0x15D6E4
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0xC(r31)
	  stw       r0, 0xAC(r1)
	  lis       r30, 0x4330
	  lfd       f1, -0x6CE0(r2)
	  stw       r30, 0xA8(r1)
	  lfs       f3, -0x6CE8(r2)
	  lfd       f0, 0xA8(r1)
	  lfs       f2, -0x6CEC(r2)
	  fsubs     f4, f0, f1
	  lwz       r3, 0x224(r3)
	  lfs       f0, -0x6CFC(r2)
	  lfs       f1, 0x2F8(r3)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r31)
	  lfs       f1, -0x6CF8(r2)
	  lfs       f0, 0x28(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lfs       f1, -0x6CE4(r2)
	  lfs       f0, 0x28(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x24(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x48A8(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x48A4(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x48A0(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x108
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0xD4
	  lwz       r29, 0x14(r31)

	.loc_0xD4:
	  addi      r3, r1, 0x50
	  li        r4, 0x3
	  bl        0x6451C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x58
	  li        r4, 0x3
	  bl        0x6453C
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xFF78
	  b         .loc_0x1C0

	.loc_0x108:
	  bl        0x15D608
	  xoris     r0, r3, 0x8000
	  lwz       r3, -0x48B8(r13)
	  stw       r0, 0xAC(r1)
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x6CE0(r2)
	  stw       r30, 0xA8(r1)
	  lfs       f0, -0x6CE8(r2)
	  lfd       f1, 0xA8(r1)
	  stw       r0, 0xA4(r1)
	  fsubs     f2, f1, f3
	  lfs       f1, -0x6CEC(r2)
	  stw       r30, 0xA0(r1)
	  fdivs     f2, f2, f0
	  lfd       f0, 0xA0(r1)
	  fmuls     f1, f1, f2
	  fsubs     f0, f0, f3
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stfd      f0, 0x98(r1)
	  cmpw      r0, r3
	  lwz       r0, 0x9C(r1)
	  blt-      .loc_0x170
	  li        r0, 0

	.loc_0x170:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x180
	  lwz       r29, 0x14(r31)

	.loc_0x180:
	  lis       r3, 0x802B
	  rlwinm    r4,r0,2,0,29
	  addi      r0, r3, 0x6A6C
	  add       r30, r0, r4
	  lwz       r4, 0x0(r30)
	  addi      r3, r1, 0x40
	  bl        0x64460
	  lwz       r4, 0x0(r30)
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x48
	  bl        0x64480
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xFEBC

	.loc_0x1C0:
	  lwz       r3, 0xC(r31)
	  bl        0xEF44
	  li        r0, 0
	  sth       r0, 0x1C(r31)
	  li        r4, 0
	  stb       r0, 0x45(r31)
	  lwz       r3, 0x18(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0xC(r31)
	  lis       r4, 0x803D
	  lis       r3, 0x803D
	  lhz       r5, 0x510(r5)
	  addi      r4, r4, 0x1E88
	  addi      r0, r3, 0x1E7C
	  rlwinm    r3,r5,2,0,29
	  add       r4, r4, r3
	  lwz       r3, 0x0(r4)
	  subi      r3, r3, 0x1
	  stw       r3, 0x0(r4)
	  lwz       r3, 0xC(r31)
	  lhz       r3, 0x510(r3)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x579CC
	  lwz       r4, 0xC(r31)
	  lwz       r0, 0xC8(r4)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x264
	  lbz       r0, 0x306E(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x264
	  lwz       r3, 0x3038(r13)
	  addi      r5, r4, 0x94
	  li        r4, 0xFF
	  bl        -0x167B8

	.loc_0x264:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x60
	  lfs       f1, -0x6D00(r2)
	  addi      r0, r3, 0x464
	  lfs       f0, -0x6CEC(r2)
	  stfs      f1, 0x68(r1)
	  stfs      f1, 0x64(r1)
	  stfs      f1, 0x60(r1)
	  stfs      f1, 0x74(r1)
	  stfs      f1, 0x70(r1)
	  stfs      f1, 0x6C(r1)
	  stw       r0, 0x80(r1)
	  stfs      f0, 0x84(r1)
	  lwz       r3, 0xC(r31)
	  lhz       r0, 0x510(r3)
	  lwz       r3, 0x434(r3)
	  sth       r0, 0xC(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x434(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0xC8(r3)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r3)
	  lfs       f0, -0x6CFC(r2)
	  stfs      f0, 0x2C(r31)
	  lwz       r0, 0xC4(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  lwz       r29, 0xB4(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BAC54
 * Size:	0000AC
 */
void ActFree::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r3, 0xC(r3)
	  lwz       r0, 0xC8(r3)
	  rlwinm    r0,r0,0,10,8
	  stw       r0, 0xC8(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0xC8(r3)
	  rlwinm    r0,r0,0,11,9
	  stw       r0, 0xC8(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x434(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0xC(r31)
	  lis       r4, 0x803D
	  lis       r3, 0x803D
	  lhz       r5, 0x510(r5)
	  addi      r4, r4, 0x1E88
	  addi      r0, r3, 0x1E7C
	  rlwinm    r3,r5,2,0,29
	  add       r4, r4, r3
	  lwz       r3, 0x0(r4)
	  addi      r3, r3, 0x1
	  stw       r3, 0x0(r4)
	  lwz       r3, 0xC(r31)
	  lhz       r3, 0x510(r3)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x57878
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BAD00
 * Size:	000004
 */
void ActFree::animationKeyUpdated(PaniAnimKeyEvent&) { }

/*
 * --INFO--
 * Address:	800BAD04
 * Size:	0000F0
 */
void ActFree::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  mr        r30, r3
	  lfs       f0, -0x6D00(r2)
	  lfs       f1, 0x40(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x38
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x40(r30)

	.loc_0x38:
	  lbz       r0, 0x45(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x68
	  lwz       r4, 0xC(r30)
	  li        r5, 0x1A
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  b         .loc_0xD8

	.loc_0x68:
	  lbz       r0, 0x46(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  mr        r3, r30
	  bl        -0x5E0
	  li        r3, 0
	  b         .loc_0xD8

	.loc_0x84:
	  lwz       r3, 0x18(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0xC(r30)
	  addi      r31, r3, 0
	  addi      r3, r4, 0x40C
	  bl        -0x15950
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xB8
	  li        r3, 0
	  b         .loc_0xD8

	.loc_0xB8:
	  lwz       r3, 0xC(r30)
	  addi      r4, r1, 0x74
	  bl        0xD7B4
	  cmpwi     r3, 0
	  beq-      .loc_0xD4
	  lwz       r3, 0x18(r30)
	  bl        -0x106BC

	.loc_0xD4:
	  mr        r3, r31

	.loc_0xD8:
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BADF4
 * Size:	0000D8
 */
void ActFree::procCollideMsg(Piki*, MsgCollide*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  mr        r30, r4
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lfs       f0, -0x6D00(r2)
	  lfs       f1, 0x40(r3)
	  fcmpo     cr0, f1, f0
	  bgt-      .loc_0xBC
	  lbz       r0, 0x46(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  b         .loc_0xBC

	.loc_0x40:
	  lwz       r31, 0x4(r5)
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x36
	  bne-      .loc_0xBC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xBC
	  lwz       r0, 0x180(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xBC
	  lbz       r0, 0x45(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xBC
	  lwz       r3, 0x43C(r30)
	  cmpwi     r3, -0x1
	  beq-      .loc_0x9C
	  lwz       r0, 0x92C(r31)
	  cmpw      r0, r3
	  bne-      .loc_0xBC

	.loc_0x9C:
	  lwz       r3, 0x3178(r13)
	  li        r4, 0x2
	  li        r5, 0
	  li        r6, 0
	  bl        0xC1EA8
	  li        r0, 0x1
	  stb       r0, 0x45(r29)
	  stw       r31, 0x504(r30)

	.loc_0xBC:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BAECC
 * Size:	000080
 */
ActFree::~ActFree()
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
	  beq-      .loc_0x64
	  lis       r3, 0x802B
	  addi      r3, r3, 0x6AC8
	  stw       r3, 0x0(r30)
	  addi      r6, r3, 0x68
	  addi      r0, r30, 0x48
	  lwz       r5, 0x14(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r30)
	  sub       r0, r0, r5
	  stw       r0, 0x4(r5)
	  bl        0x8EEC
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x73D80

	.loc_0x64:
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
 * Address:	800BAF4C
 * Size:	000008
 */
u32 ActFree::resumable() { return 0x1; }

/*
 * --INFO--
 * Address:	800BAF54
 * Size:	000014
 */
void ActFree::@72 @4 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  li        r11, 0x4
	  lwzx      r11, r3, r11
	  add       r3, r3, r11
	  subi      r3, r3, 0x48
	  b         -0x264
	*/
}
