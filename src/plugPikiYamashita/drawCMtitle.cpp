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
 * Address:	801ED480
 * Size:	000158
 */
void zen::DrawCMtitleObj::init(P2DScreen*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x68(r1)
	  addi      r30, r4, 0
	  lis       r4, 0x7469
	  stw       r29, 0x64(r1)
	  addi      r3, r30, 0
	  addi      r4, r4, 0x746C
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r31)
	  lis       r3, 0x802E
	  lis       r4, 0x6D61
	  lwz       r9, 0x0(r31)
	  lis       r6, 0x4330
	  addi      r7, r3, 0x6D98
	  lha       r5, 0x18(r9)
	  mr        r3, r30
	  lha       r0, 0x1C(r9)
	  addi      r4, r4, 0x726B
	  lha       r8, 0x1A(r9)
	  sub       r0, r0, r5
	  lha       r5, 0x1E(r9)
	  srawi     r0, r0, 0x1
	  sub       r8, r5, r8
	  extsh     r5, r0
	  srawi     r0, r8, 0x1
	  sth       r5, 0xB8(r9)
	  extsh     r0, r0
	  sth       r0, 0xBA(r9)
	  li        r5, 0x1
	  lwz       r8, 0x0(r31)
	  lfd       f2, -0x3EB0(r2)
	  lha       r0, 0x18(r8)
	  lha       r8, 0x1A(r8)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x5C(r1)
	  xoris     r0, r8, 0x8000
	  stw       r6, 0x58(r1)
	  stw       r0, 0x54(r1)
	  lfd       f0, 0x58(r1)
	  stw       r6, 0x50(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x50(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x4(r31)
	  stfs      f0, 0x8(r31)
	  lfs       f0, 0x2898(r13)
	  stfs      f0, 0xC(r31)
	  lwz       r6, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  stw       r6, 0x14(r31)
	  stw       r0, 0x18(r31)
	  lwz       r0, 0x8(r7)
	  stw       r0, 0x1C(r31)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  li        r3, 0x40
	  bl        -0x1A6588
	  mr.       r29, r3
	  beq-      .loc_0x128
	  lfs       f1, -0x3EB8(r2)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x2D8E0

	.loc_0x128:
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  bl        -0x3CF14
	  li        r0, 0x2
	  stw       r0, 0x28(r31)
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED5D8
 * Size:	000030
 */
void zen::DrawCMtitleObj::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r12, r3, 0x14
	  stw       r0, 0x4(r1)
	  li        r0, 0x2
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x28(r3)
	  bl        0x27740
	  nop
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED608
 * Size:	00004C
 */
void zen::DrawCMtitleObj::wait(f32)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x3EA8(r2)
	  lis       r4, 0x802E
	  li        r0, 0x1
	  stfs      f0, 0x20(r3)
	  addi      r5, r4, 0x6DA4
	  stfs      f1, 0x24(r3)
	  stw       r0, 0x10(r3)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x14(r3)
	  stw       r0, 0x18(r3)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x1C(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, -0x3EA4(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED654
 * Size:	00004C
 */
void zen::DrawCMtitleObj::appear(f32)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x3EA8(r2)
	  lis       r4, 0x802E
	  li        r0, 0
	  stfs      f0, 0x20(r3)
	  addi      r5, r4, 0x6DB0
	  stfs      f1, 0x24(r3)
	  stw       r0, 0x10(r3)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x14(r3)
	  stw       r0, 0x18(r3)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x1C(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, -0x3EA0(r2)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED6A0
 * Size:	000008
 */
u32 zen::DrawCMtitleObj::modeSleep() { return 0x0; }

/*
 * --INFO--
 * Address:	801ED6A8
 * Size:	000120
 */
void zen::DrawCMtitleObj::modeAppear()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  li        r31, 0
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x20(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r3)
	  lfs       f1, 0x20(r3)
	  lfs       f0, 0x24(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x9C
	  stfs      f0, 0x20(r3)
	  lis       r4, 0x802E
	  li        r0, 0x1
	  lfs       f2, -0x3EA4(r2)
	  addi      r5, r4, 0x6DA4
	  lfs       f3, -0x3EA8(r2)
	  li        r31, 0x1
	  stfs      f3, 0x20(r3)
	  lfs       f0, -0x3E9C(r2)
	  stfs      f0, 0x24(r3)
	  stw       r0, 0x10(r3)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x14(r3)
	  stw       r0, 0x18(r3)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x1C(r3)
	  lwz       r4, 0x0(r3)
	  stfs      f2, 0xC0(r4)
	  stfs      f2, 0xC4(r4)
	  stfs      f2, 0xC8(r4)
	  lwz       r0, 0x28(r3)
	  ori       r0, r0, 0x1
	  stw       r0, 0x28(r3)
	  b         .loc_0xAC

	.loc_0x9C:
	  fdivs     f1, f1, f0
	  lfs       f0, -0x3EA4(r2)
	  fmr       f2, f1
	  fsubs     f3, f0, f1

	.loc_0xAC:
	  lfs       f0, -0x3E98(r2)
	  lfs       f1, -0x3E94(r2)
	  fmuls     f2, f0, f2
	  lfs       f0, -0x3EA8(r2)
	  fmuls     f1, f1, f3
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xDC
	  lfs       f0, -0x3E9C(r2)
	  fadds     f0, f0, f1
	  b         .loc_0xE4

	.loc_0xDC:
	  lfs       f0, -0x3E9C(r2)
	  fsubs     f0, f1, f0

	.loc_0xE4:
	  lwz       r3, 0x0(r3)
	  fctiwz    f0, f0
	  li        r5, 0xF0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x20(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x24(r1)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED7C8
 * Size:	0000E4
 */
void zen::DrawCMtitleObj::modeWait()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x20(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x20(r3)
	  lfs       f2, 0x20(r3)
	  lfs       f1, 0x24(r3)
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x48
	  stfs      f1, 0x20(r31)
	  lfs       f1, -0x3EA4(r2)
	  lfs       f3, -0x3EA8(r2)
	  b         .loc_0x60

	.loc_0x48:
	  lfs       f0, -0x3E90(r2)
	  fmuls     f0, f0, f2
	  fdivs     f1, f0, f1
	  bl        0x2E4CC
	  lfs       f0, -0x3EA4(r2)
	  fsubs     f3, f0, f1

	.loc_0x60:
	  lfs       f0, -0x3E8C(r2)
	  lfs       f2, 0x8(r31)
	  fmuls     f3, f0, f3
	  lfs       f0, -0x3EA8(r2)
	  fmuls     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x90
	  lfs       f0, -0x3E9C(r2)
	  fadds     f1, f0, f1
	  b         .loc_0x98

	.loc_0x90:
	  lfs       f0, -0x3E9C(r2)
	  fsubs     f1, f1, f0

	.loc_0x98:
	  lfs       f0, 0x4(r31)
	  fctiwz    f1, f1
	  lwz       r3, 0x0(r31)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x28(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x20(r1)
	  lwz       r5, 0x2C(r1)
	  mtlr      r12
	  lwz       r0, 0x24(r1)
	  extsh     r4, r0
	  blrl
	  lwz       r0, 0x3C(r1)
	  li        r3, 0
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}
