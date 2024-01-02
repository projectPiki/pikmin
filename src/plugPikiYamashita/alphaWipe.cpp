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
 * Address:	801F19D8
 * Size:	000048
 */
zen::AlphaWipe::AlphaWipe()
{
	/*
	.loc_0x0:
	  li        r4, 0
	  stw       r4, 0x0(r3)
	  li        r0, 0xFF
	  stw       r4, 0x4(r3)
	  stw       r4, 0x8(r3)
	  lfs       f0, -0x3DC8(r2)
	  stfs      f0, 0xC(r3)
	  lfs       f0, -0x3DC4(r2)
	  stfs      f0, 0x10(r3)
	  stb       r0, 0x20(r3)
	  stb       r0, 0x21(r3)
	  stb       r0, 0x22(r3)
	  stb       r0, 0x23(r3)
	  stb       r0, 0x24(r3)
	  stb       r0, 0x25(r3)
	  stb       r0, 0x26(r3)
	  stb       r0, 0x27(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F1A20
 * Size:	00020C
 */
void zen::AlphaWipe::update()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x40(r1)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x204
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r3)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x14(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r3)
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x10(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x54
	  stfs      f0, 0xC(r3)
	  lfs       f4, -0x3DC4(r2)
	  b         .loc_0x58

	.loc_0x54:
	  fdivs     f4, f1, f0

	.loc_0x58:
	  lfs       f2, 0x14(r3)
	  lfs       f1, 0x10(r3)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x74
	  stfs      f1, 0x14(r3)
	  lfs       f5, -0x3DC4(r2)
	  b         .loc_0x8C

	.loc_0x74:
	  lfs       f0, -0x3DC8(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x88
	  fmr       f5, f0
	  b         .loc_0x8C

	.loc_0x88:
	  fdivs     f5, f2, f1

	.loc_0x8C:
	  lwz       r4, 0x4(r3)
	  rlwinm.   r0,r4,0,31,31
	  beq-      .loc_0xDC
	  lfs       f0, -0x3DC4(r2)
	  lfs       f1, -0x3DC0(r2)
	  fcmpu     cr0, f0, f5
	  fmuls     f6, f1, f4
	  fmuls     f3, f1, f5
	  bne-      .loc_0x114
	  rlwinm    r0,r4,0,0,30
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x4(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x4(r3)
	  lfs       f0, -0x3DC8(r2)
	  stfs      f0, 0xC(r3)
	  lfs       f0, 0x1C(r3)
	  fneg      f0, f0
	  stfs      f0, 0x14(r3)
	  b         .loc_0x114

	.loc_0xDC:
	  rlwinm.   r0,r4,0,30,30
	  beq-      .loc_0x114
	  lfs       f2, -0x3DC4(r2)
	  lfs       f3, -0x3DC0(r2)
	  fsubs     f1, f2, f4
	  fsubs     f0, f2, f5
	  fcmpu     cr0, f2, f5
	  fmuls     f6, f3, f1
	  fmuls     f3, f3, f0
	  bne-      .loc_0x114
	  rlwinm    r0,r4,0,31,29
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  stw       r0, 0x0(r3)

	.loc_0x114:
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x19C
	  bge-      .loc_0x204
	  cmpwi     r0, 0
	  bge-      .loc_0x130
	  b         .loc_0x204

	.loc_0x130:
	  lfs       f0, -0x3DC8(r2)
	  fcmpo     cr0, f6, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x14C
	  lfs       f0, -0x3DBC(r2)
	  fadds     f0, f0, f6
	  b         .loc_0x154

	.loc_0x14C:
	  lfs       f0, -0x3DBC(r2)
	  fsubs     f0, f6, f0

	.loc_0x154:
	  fctiwz    f0, f0
	  stfd      f0, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stb       r0, 0x23(r3)
	  lfs       f0, -0x3DC8(r2)
	  fcmpo     cr0, f3, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x180
	  lfs       f0, -0x3DBC(r2)
	  fadds     f0, f0, f3
	  b         .loc_0x188

	.loc_0x180:
	  lfs       f0, -0x3DBC(r2)
	  fsubs     f0, f3, f0

	.loc_0x188:
	  fctiwz    f0, f0
	  stfd      f0, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stb       r0, 0x27(r3)
	  b         .loc_0x204

	.loc_0x19C:
	  lfs       f0, -0x3DC8(r2)
	  fcmpo     cr0, f3, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1B8
	  lfs       f0, -0x3DBC(r2)
	  fadds     f0, f0, f3
	  b         .loc_0x1C0

	.loc_0x1B8:
	  lfs       f0, -0x3DBC(r2)
	  fsubs     f0, f3, f0

	.loc_0x1C0:
	  fctiwz    f0, f0
	  stfd      f0, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stb       r0, 0x23(r3)
	  lfs       f0, -0x3DC8(r2)
	  fcmpo     cr0, f6, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1EC
	  lfs       f0, -0x3DBC(r2)
	  fadds     f0, f0, f6
	  b         .loc_0x1F4

	.loc_0x1EC:
	  lfs       f0, -0x3DBC(r2)
	  fsubs     f0, f6, f0

	.loc_0x1F4:
	  fctiwz    f0, f0
	  stfd      f0, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stb       r0, 0x27(r3)

	.loc_0x204:
	  addi      r1, r1, 0x40
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F1C2C
 * Size:	0000E4
 */
void zen::AlphaWipe::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x74(r1)
	  mr        r29, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xC8
	  lwz       r6, 0x310(r30)
	  li        r31, 0
	  lwz       r0, 0x30C(r30)
	  addi      r5, r1, 0x20
	  addi      r3, r30, 0
	  stw       r31, 0x20(r1)
	  addi      r4, r1, 0x30
	  stw       r31, 0x24(r1)
	  stw       r0, 0x28(r1)
	  stw       r6, 0x2C(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r29, 0x20
	  li        r5, 0x1
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r29, 0x24
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r30)
	  addi      r4, r1, 0x10
	  lwz       r0, 0x30C(r30)
	  mr        r3, r30
	  stw       r31, 0x10(r1)
	  stw       r31, 0x14(r1)
	  stw       r0, 0x18(r1)
	  stw       r5, 0x1C(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl

	.loc_0xC8:
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F1D10
 * Size:	000050
 */
void zen::AlphaWipe::start(f32, f32, zen::AlphaWipe::typeFlag)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x3DBC(r2)
	  li        r0, 0x1
	  stw       r0, 0x0(r3)
	  fmuls     f1, f1, f0
	  stw       r0, 0x4(r3)
	  lfs       f0, -0x3DC8(r2)
	  fcmpo     cr0, f2, f0
	  stfs      f0, 0xC(r3)
	  stfs      f1, 0x10(r3)
	  bge-      .loc_0x2C
	  fmr       f2, f0

	.loc_0x2C:
	  fneg      f0, f2
	  stfs      f2, 0x1C(r3)
	  li        r0, 0
	  stfs      f0, 0x14(r3)
	  stfs      f1, 0x18(r3)
	  stw       r4, 0x8(r3)
	  stb       r0, 0x23(r3)
	  stb       r0, 0x27(r3)
	  blr
	*/
}
