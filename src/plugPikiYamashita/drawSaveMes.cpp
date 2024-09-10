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
 * Address:	801F265C
 * Size:	000348
 */
zen::DrawSaveMes::DrawSaveMes()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stw       r31, 0xBC(r1)
	  stw       r30, 0xB8(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0x34
	  stw       r29, 0xB4(r1)
	  stw       r28, 0xB0(r1)
	  bl        0xEE0
	  li        r3, 0x100
	  bl        -0x1AB684
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x54
	  lis       r4, 0x802E
	  addi      r4, r4, 0x7160
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x33138

	.loc_0x54:
	  stw       r29, 0x8(r30)
	  li        r3, 0x100
	  bl        -0x1AB6B4
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x84
	  lis       r4, 0x802E
	  addi      r4, r4, 0x7178
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x33168

	.loc_0x84:
	  stw       r29, 0xC(r30)
	  lis       r29, 0x7361
	  addi      r4, r29, 0x766B
	  lwz       r3, 0x8(r30)
	  li        r5, 0x1
	  lfs       f0, -0x3DA8(r2)
	  addi      r9, r3, 0x4
	  stfs      f0, 0xC4(r3)
	  addi      r28, r9, 0
	  addi      r3, r28, 0
	  stfs      f0, 0xC4(r9)
	  stfs      f0, 0xC8(r9)
	  lha       r8, 0x1A(r9)
	  lha       r7, 0x1E(r9)
	  lha       r6, 0x18(r9)
	  lha       r0, 0x1C(r9)
	  sub       r7, r7, r8
	  srawi     r7, r7, 0x1
	  sub       r0, r0, r6
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r9)
	  extsh     r0, r7
	  sth       r0, 0xBA(r9)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x18(r30)
	  addi      r3, r28, 0
	  addi      r4, r29, 0x7665
	  lwz       r12, 0x0(r28)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x1C(r30)
	  addi      r3, r28, 0
	  addi      r4, r29, 0x6B63
	  lwz       r12, 0x0(r28)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r30)
	  addi      r3, r28, 0
	  addi      r4, r29, 0x5F63
	  lwz       r12, 0x0(r28)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x24(r30)
	  addi      r3, r28, 0
	  addi      r4, r29, 0x6B73
	  lwz       r12, 0x0(r28)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x28(r30)
	  addi      r3, r28, 0
	  addi      r4, r29, 0x5F73
	  lwz       r12, 0x0(r28)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x2C(r30)
	  addi      r3, r28, 0
	  lis       r4, 0x6162
	  lwz       r12, 0x0(r28)
	  addi      r4, r4, 0x746E
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x30(r30)
	  lis       r3, 0x6261
	  li        r31, 0x1
	  lwz       r6, 0x18(r30)
	  addi      r4, r3, 0x636B
	  li        r5, 0x1
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r6)
	  lwz       r3, 0x1C(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x24(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x28(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x2C(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xC(r30)
	  addi      r28, r3, 0x4
	  lha       r8, 0x1E(r3)
	  lha       r7, 0x22(r3)
	  mr        r3, r28
	  lha       r6, 0x18(r28)
	  lha       r0, 0x1C(r28)
	  sub       r7, r7, r8
	  srawi     r7, r7, 0x1
	  sub       r0, r0, r6
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r28)
	  extsh     r0, r7
	  sth       r0, 0xBA(r28)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x10(r30)
	  lis       r4, 0x6368
	  li        r29, 0
	  lwz       r6, 0x10(r30)
	  addi      r3, r28, 0
	  addi      r4, r4, 0x7569
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r31,7,24,24
	  li        r5, 0x1
	  stb       r0, 0xC(r6)
	  lwz       r6, 0x10(r30)
	  stb       r29, 0xF0(r6)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x14(r30)
	  addi      r3, r30, 0
	  li        r4, -0x1
	  lwz       r7, 0x14(r30)
	  lha       r5, 0x18(r7)
	  lha       r0, 0x1C(r7)
	  lha       r6, 0x1A(r7)
	  sub       r0, r0, r5
	  lha       r5, 0x1E(r7)
	  srawi     r0, r0, 0x1
	  sub       r6, r5, r6
	  extsh     r5, r0
	  srawi     r0, r6, 0x1
	  sth       r5, 0xB8(r7)
	  extsh     r0, r0
	  sth       r0, 0xBA(r7)
	  lfs       f0, -0x3DA8(r2)
	  stfs      f0, 0x4(r30)
	  lwz       r5, 0x8(r30)
	  lbz       r0, 0x10(r5)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0x10(r5)
	  lwz       r5, 0xC(r30)
	  lbz       r0, 0x10(r5)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0x10(r5)
	  bl        0xA14
	  mr        r3, r30
	  lwz       r0, 0xC4(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  lwz       r29, 0xB4(r1)
	  lwz       r28, 0xB0(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F29A4
 * Size:	000024
 */
void zen::DrawSaveMes::sleep()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, -0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x9DC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F29C8
 * Size:	000050
 */
void zen::DrawSaveMes::mesAppear()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lfs       f0, -0x3DA8(r2)
	  stfs      f0, 0x4(r31)
	  bl        0x9A8
	  lwz       r3, 0x8(r31)
	  addi      r3, r3, 0x4
	  bl        -0x33250
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x4
	  bl        -0x3325C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F2A18
 * Size:	000048
 */
void zen::DrawSaveMes::saveFinish()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0x960
	  lwz       r3, 0x8(r31)
	  addi      r3, r3, 0x4
	  bl        -0x33298
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x4
	  bl        -0x332A4
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F2A60
 * Size:	000024
 */
void zen::DrawSaveMes::saveError()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x7
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x920
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void zen::DrawSaveMes::hide()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F2A84
 * Size:	0008A4
 */
void zen::DrawSaveMes::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x158(r1)
	  stfd      f31, 0x150(r1)
	  stfd      f30, 0x148(r1)
	  stw       r31, 0x144(r1)
	  li        r31, 0
	  stw       r30, 0x140(r1)
	  mr        r30, r3
	  stw       r29, 0x13C(r1)
	  addi      r29, r4, 0
	  lwz       r3, 0x0(r3)
	  addi      r0, r3, 0x1
	  cmplwi    r0, 0x9
	  bgt-      .loc_0x854
	  lis       r3, 0x802E
	  addi      r3, r3, 0x7190
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  li        r31, 0x1
	  b         .loc_0x854
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, -0x3DA4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x94
	  lfs       f30, -0x3DA8(r2)
	  addi      r3, r30, 0
	  li        r4, 0x6
	  bl        0x880
	  b         .loc_0xAC

	.loc_0x94:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x3DA0(r2)
	  fmuls     f1, f1, f0
	  bl        0x291C4
	  lfs       f0, -0x3D9C(r2)
	  fsubs     f30, f0, f1

	.loc_0xAC:
	  lwz       r3, 0x8(r30)
	  addi      r3, r3, 0x4
	  stfs      f30, 0xC0(r3)
	  stfs      f30, 0xC4(r3)
	  stfs      f30, 0xC8(r3)
	  lfs       f1, -0x3D98(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f30
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xE4
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xEC

	.loc_0xE4:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0xEC:
	  fctiwz    f0, f0
	  lwz       r5, 0x10(r30)
	  li        r3, 0xFF
	  li        r0, 0x50
	  stfd      f0, 0x130(r1)
	  li        r4, 0
	  lwz       r6, 0x134(r1)
	  stb       r6, 0xF0(r5)
	  lwz       r5, 0x18(r30)
	  stb       r3, 0xF7(r5)
	  stb       r3, 0xFB(r5)
	  lwz       r3, 0x1C(r30)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lwz       r3, 0x20(r30)
	  stb       r4, 0xF7(r3)
	  stb       r4, 0xFB(r3)
	  lwz       r3, 0x24(r30)
	  stb       r4, 0xF7(r3)
	  stb       r4, 0xFB(r3)
	  lwz       r3, 0x28(r30)
	  stb       r4, 0xF7(r3)
	  stb       r4, 0xFB(r3)
	  lwz       r3, 0x2C(r30)
	  stb       r4, 0xF7(r3)
	  stb       r4, 0xFB(r3)
	  lwz       r3, 0x14(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x14(r30)
	  lwz       r12, 0x0(r3)
	  lha       r5, 0x1A(r3)
	  lwz       r12, 0x14(r12)
	  lha       r4, 0x18(r3)
	  addi      r5, r5, 0x1E0
	  mtlr      r12
	  blrl
	  b         .loc_0x854
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, -0x3DA4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1C0
	  lfs       f30, -0x3D9C(r2)
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        0x754
	  b         .loc_0x1D4

	.loc_0x1C0:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x3DA0(r2)
	  fmuls     f1, f1, f0
	  bl        0x29098
	  fmr       f30, f1

	.loc_0x1D4:
	  lwz       r3, 0x8(r30)
	  addi      r3, r3, 0x4
	  stfs      f30, 0xC0(r3)
	  stfs      f30, 0xC4(r3)
	  stfs      f30, 0xC8(r3)
	  lfs       f1, -0x3D98(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f30
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x20C
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x214

	.loc_0x20C:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x214:
	  fctiwz    f0, f0
	  lwz       r5, 0x10(r30)
	  li        r3, 0xFF
	  li        r0, 0x50
	  stfd      f0, 0x130(r1)
	  li        r29, 0
	  lwz       r6, 0x134(r1)
	  li        r4, 0
	  stb       r6, 0xF0(r5)
	  lwz       r5, 0x18(r30)
	  stb       r3, 0xF7(r5)
	  stb       r3, 0xFB(r5)
	  lwz       r3, 0x1C(r30)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lwz       r3, 0x20(r30)
	  stb       r29, 0xF7(r3)
	  stb       r29, 0xFB(r3)
	  lwz       r3, 0x24(r30)
	  stb       r29, 0xF7(r3)
	  stb       r29, 0xFB(r3)
	  lwz       r3, 0x28(r30)
	  stb       r29, 0xF7(r3)
	  stb       r29, 0xFB(r3)
	  lwz       r3, 0x2C(r30)
	  stb       r29, 0xF7(r3)
	  stb       r29, 0xFB(r3)
	  lwz       r3, 0x30(r30)
	  bl        -0x33430
	  lwz       r3, 0x14(r30)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x14(r30)
	  lwz       r12, 0x0(r3)
	  lha       r5, 0x1A(r3)
	  lwz       r12, 0x14(r12)
	  lha       r4, 0x18(r3)
	  addi      r5, r5, 0x1E0
	  mtlr      r12
	  blrl
	  b         .loc_0x854
	  lis       r3, 0x100
	  lwz       r4, 0x28(r29)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0x2E4
	  li        r3, 0x111
	  bl        -0x14D9E4
	  addi      r3, r30, 0
	  li        r4, 0x2
	  bl        0x62C

	.loc_0x2E4:
	  lwz       r0, 0x28(r29)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x308
	  li        r3, 0x11D
	  bl        -0x14DA04
	  addi      r3, r30, 0
	  li        r4, 0x5
	  bl        0x60C
	  b         .loc_0x854

	.loc_0x308:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, -0x3D94(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x33C
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, -0x3D9C(r2)
	  b         .loc_0x344

	.loc_0x33C:
	  lfs       f0, -0x3DA4(r2)
	  fmuls     f1, f1, f0

	.loc_0x344:
	  lfs       f0, -0x3D90(r2)
	  fmuls     f1, f0, f1
	  bl        0x28D84
	  lfs       f0, -0x3D9C(r2)
	  lfs       f2, -0x3D8C(r2)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x37C
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x384

	.loc_0x37C:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x384:
	  fctiwz    f0, f0
	  lwz       r3, 0x30(r30)
	  stfd      f0, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  rlwinm    r4,r0,0,24,31
	  bl        -0x33544
	  b         .loc_0x854
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x4(r30)
	  lfs       f31, -0x3D9C(r2)
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x3D8
	  lfs       f30, -0x3DA8(r2)
	  addi      r3, r30, 0
	  li        r4, 0x3
	  bl        0x53C
	  b         .loc_0x3F4

	.loc_0x3D8:
	  fdivs     f0, f0, f31
	  lfs       f1, -0x3DA0(r2)
	  fmuls     f1, f1, f0
	  bl        0x28E80
	  lfs       f0, -0x3D9C(r2)
	  fmr       f31, f1
	  fsubs     f30, f0, f1

	.loc_0x3F4:
	  lfs       f1, -0x3D88(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f30
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x418
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x420

	.loc_0x418:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x420:
	  fctiwz    f0, f0
	  lwz       r3, 0x18(r30)
	  stfd      f0, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lfs       f1, -0x3D84(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f30
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x45C
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x464

	.loc_0x45C:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x464:
	  fctiwz    f0, f0
	  lwz       r3, 0x1C(r30)
	  stfd      f0, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lfs       f1, -0x3D88(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4A0
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x4A8

	.loc_0x4A0:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x4A8:
	  fctiwz    f0, f0
	  lwz       r3, 0x20(r30)
	  stfd      f0, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lfs       f1, -0x3D84(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4E4
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x4EC

	.loc_0x4E4:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x4EC:
	  fctiwz    f0, f0
	  lwz       r4, 0x24(r30)
	  li        r0, 0
	  stfd      f0, 0x130(r1)
	  lwz       r3, 0x134(r1)
	  stb       r3, 0xF7(r4)
	  stb       r3, 0xFB(r4)
	  lwz       r3, 0x28(r30)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lwz       r3, 0x2C(r30)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lfs       f0, -0x3D80(r2)
	  lfs       f1, -0x3D7C(r2)
	  fmuls     f2, f0, f31
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f30
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x550
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x558

	.loc_0x550:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x558:
	  lwz       r3, 0x14(r30)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x130(r1)
	  lwz       r12, 0x14(r12)
	  lha       r4, 0x18(r3)
	  lwz       r5, 0x134(r1)
	  mtlr      r12
	  blrl
	  b         .loc_0x854
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, -0x3D78(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x854
	  li        r31, 0x1
	  b         .loc_0x854
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f2, 0x4(r30)
	  lfs       f1, -0x3DA4(r2)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x5E8
	  lfs       f31, -0x3D9C(r2)
	  mr        r3, r30
	  lfs       f30, -0x3DA8(r2)
	  li        r4, 0x8
	  bl        0x32C
	  b         .loc_0x604

	.loc_0x5E8:
	  lfs       f0, -0x3DA0(r2)
	  fmuls     f0, f0, f2
	  fdivs     f1, f0, f1
	  bl        0x28ADC
	  lfs       f0, -0x3D9C(r2)
	  fmr       f30, f1
	  fsubs     f31, f0, f1

	.loc_0x604:
	  lwz       r3, 0x18(r30)
	  li        r0, 0
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lwz       r3, 0x1C(r30)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lfs       f1, -0x3D88(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f30
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x644
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x64C

	.loc_0x644:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x64C:
	  fctiwz    f0, f0
	  lwz       r3, 0x20(r30)
	  stfd      f0, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lfs       f1, -0x3D84(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f30
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x688
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x690

	.loc_0x688:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x690:
	  fctiwz    f0, f0
	  lwz       r3, 0x24(r30)
	  stfd      f0, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lfs       f1, -0x3D88(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x6CC
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x6D4

	.loc_0x6CC:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x6D4:
	  fctiwz    f0, f0
	  lwz       r3, 0x28(r30)
	  stfd      f0, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lfs       f1, -0x3D84(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x710
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x718

	.loc_0x710:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x718:
	  fctiwz    f0, f0
	  lwz       r3, 0x2C(r30)
	  stfd      f0, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  lfs       f0, -0x3D80(r2)
	  lfs       f1, -0x3D7C(r2)
	  fmuls     f2, f0, f30
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f31
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x760
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x768

	.loc_0x760:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x768:
	  lwz       r3, 0x14(r30)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x130(r1)
	  lwz       r12, 0x14(r12)
	  lha       r4, 0x18(r3)
	  lwz       r5, 0x134(r1)
	  mtlr      r12
	  blrl
	  b         .loc_0x854
	  li        r31, 0x1
	  b         .loc_0x854
	  addi      r3, r30, 0x34
	  addi      r4, r29, 0
	  bl        0x430
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x854
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, -0x3DA4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7E4
	  lfs       f30, -0x3DA8(r2)
	  addi      r3, r30, 0
	  li        r4, 0x8
	  bl        0x130
	  b         .loc_0x7F0

	.loc_0x7E4:
	  fdivs     f0, f1, f0
	  lfs       f1, -0x3D9C(r2)
	  fsubs     f30, f1, f0

	.loc_0x7F0:
	  lwz       r3, 0x8(r30)
	  addi      r3, r3, 0x4
	  stfs      f30, 0xC0(r3)
	  stfs      f30, 0xC4(r3)
	  stfs      f30, 0xC8(r3)
	  lfs       f1, -0x3D98(r2)
	  lfs       f0, -0x3DA8(r2)
	  fmuls     f1, f1, f30
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x828
	  lfs       f0, -0x3DA4(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x830

	.loc_0x828:
	  lfs       f0, -0x3DA4(r2)
	  fsubs     f0, f1, f0

	.loc_0x830:
	  fctiwz    f0, f0
	  lwz       r3, 0x10(r30)
	  stfd      f0, 0x130(r1)
	  lwz       r0, 0x134(r1)
	  stb       r0, 0xF0(r3)
	  lwz       r3, 0x14(r30)
	  stfs      f30, 0xC0(r3)
	  stfs      f30, 0xC4(r3)
	  stfs      f30, 0xC8(r3)

	.loc_0x854:
	  lwz       r3, 0x8(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r0, 0x15C(r1)
	  lfd       f31, 0x150(r1)
	  lfd       f30, 0x148(r1)
	  lwz       r31, 0x144(r1)
	  lwz       r30, 0x140(r1)
	  lwz       r29, 0x13C(r1)
	  addi      r1, r1, 0x158
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F3328
 * Size:	000068
 */
void zen::DrawSaveMes::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0xC(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x8(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x34
	  addi      r4, r31, 0
	  bl        0x4D0
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
 * Address:	801F3390
 * Size:	0001D0
 */
void zen::DrawSaveMes::setMode(zen::DrawSaveMes::modeFlag)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  mr        r31, r3
	  stw       r30, 0xA0(r1)
	  stw       r4, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  addi      r0, r3, 0x1
	  cmplwi    r0, 0x9
	  bgt-      .loc_0x1B8
	  lis       r3, 0x802E
	  addi      r3, r3, 0x71B8
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x8(r31)
	  li        r4, 0
	  lbz       r0, 0x10(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x10(r3)
	  lwz       r3, 0xC(r31)
	  lbz       r0, 0x10(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x10(r3)
	  b         .loc_0x1B8
	  lfs       f0, -0x3DA8(r2)
	  li        r4, 0x1
	  li        r30, 0
	  stfs      f0, 0x4(r31)
	  li        r5, 0x1E0
	  lwz       r3, 0x8(r31)
	  lbz       r0, 0x10(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x10(r3)
	  lwz       r3, 0x8(r31)
	  addi      r3, r3, 0x4
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0xC(r31)
	  lbz       r0, 0x10(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0x10(r3)
	  lwz       r3, 0x14(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r30,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x14(r31)
	  lwz       r12, 0x0(r3)
	  lha       r4, 0x18(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x10(r31)
	  addi      r3, r31, 0x34
	  stb       r30, 0xF0(r4)
	  bl        0x528
	  b         .loc_0x1B8
	  lfs       f0, -0x3DA8(r2)
	  li        r5, 0x1
	  addi      r3, r31, 0x34
	  stfs      f0, 0x4(r31)
	  lwz       r4, 0x8(r31)
	  lbz       r0, 0x10(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0x10(r4)
	  lwz       r4, 0xC(r31)
	  lbz       r0, 0x10(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0x10(r4)
	  lwz       r4, 0x14(r31)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  bl        0x4E0
	  b         .loc_0x1B8
	  lfs       f0, -0x3DA8(r2)
	  li        r4, 0
	  stfs      f0, 0x4(r31)
	  lwz       r3, 0x14(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x1B8
	  lfs       f0, -0x3DA8(r2)
	  li        r4, 0x1
	  stfs      f0, 0x4(r31)
	  lwz       r3, 0x14(r31)
	  lfs       f0, -0x3D9C(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x14(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x1B8
	  lfs       f0, -0x3DA8(r2)
	  stfs      f0, 0x4(r31)
	  b         .loc_0x1B8
	  lfs       f0, -0x3DA8(r2)
	  addi      r3, r31, 0x34
	  stfs      f0, 0x4(r31)
	  lfs       f1, -0x3D9C(r2)
	  bl        0x348
	  b         .loc_0x1B8
	  lfs       f0, -0x3DA8(r2)
	  stfs      f0, 0x4(r31)

	.loc_0x1B8:
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}
