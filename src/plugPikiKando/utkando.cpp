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
 * Address:	80116110
 * Size:	0000B0
 */
void selectRandomly(Choice*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  bl        0x101F44
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x6068(r2)
	  stw       r0, 0x1C(r1)
	  lis       r0, 0x4330
	  lfs       f1, -0x6074(r2)
	  cmpwi     r31, 0
	  stw       r0, 0x18(r1)
	  lfs       f0, -0x6078(r2)
	  mtctr     r31
	  lfd       f2, 0x18(r1)
	  mr        r3, r30
	  lfs       f4, -0x6070(r2)
	  fsubs     f2, f2, f3
	  li        r4, 0
	  fdivs     f1, f2, f1
	  fmuls     f1, f0, f1
	  ble-      .loc_0x8C

	.loc_0x64:
	  lfs       f0, 0x4(r3)
	  fadds     f4, f4, f0
	  fcmpo     cr0, f1, f4
	  bge-      .loc_0x80
	  rlwinm    r0,r4,3,0,28
	  lwzx      r3, r30, r0
	  b         .loc_0x98

	.loc_0x80:
	  addi      r3, r3, 0x8
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x64

	.loc_0x8C:
	  rlwinm    r0,r31,3,0,28
	  add       r3, r30, r0
	  lwz       r3, -0x8(r3)

	.loc_0x98:
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
 * Address:	801161C0
 * Size:	000010
 */
BitFlags::BitFlags()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  sth       r0, 0x6(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801161D0
 * Size:	000058
 */
void BitFlags::dump()
{
	/*
	.loc_0x0:
	  lhz       r5, 0x6(r3)
	  li        r6, 0
	  cmpwi     r5, 0
	  blelr-
	  cmpwi     r5, 0x8
	  subi      r4, r5, 0x8
	  ble-      .loc_0x38
	  addi      r0, r4, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r4, 0
	  mtctr     r0
	  ble-      .loc_0x38

	.loc_0x30:
	  addi      r6, r6, 0x8
	  bdnz+     .loc_0x30

	.loc_0x38:
	  sub       r0, r5, r6
	  cmpw      r6, r5
	  mtctr     r0
	  bgelr-

	.loc_0x48:
	  bdnz-     .loc_0x48
	  blr
	  b         .loc_0x38
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80116228
 * Size:	000070
 */
void BitFlags::loadCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  b         .loc_0x48

	.loc_0x28:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x0(r29)
	  stbx      r3, r4, r31
	  addi      r31, r31, 0x1

	.loc_0x48:
	  lhz       r0, 0x6(r29)
	  cmpw      r31, r0
	  blt+      .loc_0x28
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80116298
 * Size:	000070
 */
void BitFlags::saveCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  b         .loc_0x48

	.loc_0x28:
	  mr        r3, r30
	  lwz       r4, 0x0(r29)
	  lwz       r12, 0x4(r30)
	  lbzx      r4, r4, r31
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x1

	.loc_0x48:
	  lhz       r0, 0x6(r29)
	  cmpw      r31, r0
	  blt+      .loc_0x28
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80116308
 * Size:	000054
 */
void BitFlags::create(u16, u8*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  sth       r4, 0x4(r3)
	  rlwinm    r3,r4,29,19,31
	  addi      r0, r3, 0x1
	  sth       r0, 0x6(r31)
	  beq-      .loc_0x34
	  stw       r5, 0x0(r31)
	  b         .loc_0x40

	.loc_0x34:
	  lhz       r3, 0x6(r31)
	  bl        -0xCF33C
	  stw       r3, 0x0(r31)

	.loc_0x40:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011635C
 * Size:	000028
 */
void BitFlags::reset()
{
	/*
	.loc_0x0:
	  li        r6, 0
	  li        r5, 0
	  b         .loc_0x18

	.loc_0xC:
	  lwz       r4, 0x0(r3)
	  stbx      r5, r4, r6
	  addi      r6, r6, 0x1

	.loc_0x18:
	  lhz       r0, 0x6(r3)
	  cmpw      r6, r0
	  blt+      .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80116384
 * Size:	000030
 */
void BitFlags::setFlag(u16)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r3)
	  rlwinm    r6,r4,0,16,31
	  rlwinm    r0,r4,0,16,28
	  rlwinm    r7,r4,29,19,31
	  sub       r0, r6, r0
	  lbzx      r4, r5, r7
	  rlwinm    r0,r0,0,16,31
	  li        r3, 0x1
	  slw       r0, r3, r0
	  or        r0, r4, r0
	  stbx      r0, r5, r7
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void BitFlags::resetFlag(u16)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801163B4
 * Size:	000038
 */
void BitFlags::isFlag(u16)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x0(r3)
	  rlwinm    r0,r4,29,19,31
	  rlwinm    r5,r4,0,16,31
	  rlwinm    r4,r4,0,16,28
	  lbzx      r0, r3, r0
	  sub       r3, r5, r4
	  rlwinm    r3,r3,0,16,31
	  li        r4, 0x1
	  slw       r3, r4, r3
	  and       r0, r3, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801163EC
 * Size:	00000C
 */
LoopChecker::LoopChecker(char*, f32)
{
	/*
	.loc_0x0:
	  stfs      f1, 0x0(r3)
	  stw       r4, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801163F8
 * Size:	000028
 */
void LoopChecker::update()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x28C(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r3)
	  lfs       f1, 0x0(r3)
	  lfs       f0, -0x6070(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80116420
 * Size:	00016C
 */
void drawBatten(Graphics&, Vector3f&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  fmr       f31, f1
	  stw       r31, 0xC4(r1)
	  mr        r31, r4
	  stw       r30, 0xC0(r1)
	  mr        r30, r3
	  lwz       r12, 0x3B4(r30)
	  lwz       r5, 0x2E4(r30)
	  lwz       r12, 0x74(r12)
	  addi      r4, r5, 0x1E0
	  mtlr      r12
	  li        r5, 0
	  blrl
	  lfs       f0, -0x6070(r2)
	  fneg      f4, f31
	  mr        r3, r30
	  stfs      f0, 0xBC(r1)
	  addi      r4, r1, 0xB4
	  addi      r5, r1, 0x9C
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xB4(r1)
	  stfs      f0, 0xB0(r1)
	  stfs      f0, 0xAC(r1)
	  stfs      f0, 0xA8(r1)
	  stfs      f0, 0xA4(r1)
	  stfs      f0, 0xA0(r1)
	  stfs      f0, 0x9C(r1)
	  stfs      f0, 0x98(r1)
	  stfs      f0, 0x94(r1)
	  stfs      f0, 0x90(r1)
	  lfs       f1, -0x2370(r13)
	  lfs       f0, 0x0(r31)
	  lfs       f2, 0x4(r31)
	  fadds     f0, f0, f31
	  lfs       f3, 0x8(r31)
	  fadds     f2, f2, f1
	  fadds     f1, f3, f31
	  stfs      f0, 0xB4(r1)
	  stfs      f2, 0xB8(r1)
	  stfs      f1, 0xBC(r1)
	  lfs       f0, 0x0(r31)
	  lfs       f3, 0x8(r31)
	  fadds     f0, f0, f31
	  lfs       f2, 0x4(r31)
	  lfs       f1, -0x236C(r13)
	  fadds     f3, f3, f4
	  fadds     f1, f2, f1
	  stfs      f0, 0xA8(r1)
	  stfs      f1, 0xAC(r1)
	  stfs      f3, 0xB0(r1)
	  lfs       f0, 0x0(r31)
	  lfs       f2, 0x4(r31)
	  lfs       f1, -0x2368(r13)
	  fadds     f0, f0, f4
	  lfs       f3, 0x8(r31)
	  fadds     f1, f2, f1
	  stfs      f0, 0x9C(r1)
	  fadds     f0, f3, f4
	  stfs      f1, 0xA0(r1)
	  stfs      f0, 0xA4(r1)
	  lfs       f0, 0x0(r31)
	  lfs       f2, 0x4(r31)
	  lfs       f1, -0x2364(r13)
	  fadds     f0, f0, f4
	  lfs       f3, 0x8(r31)
	  fadds     f1, f2, f1
	  stfs      f0, 0x90(r1)
	  fadds     f0, f3, f31
	  stfs      f1, 0x94(r1)
	  stfs      f0, 0x98(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0xA8
	  addi      r5, r1, 0x90
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lwz       r31, 0xC4(r1)
	  lwz       r30, 0xC0(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011658C
 * Size:	000424
 */
void drawBattenPole(Graphics&, Vector3f&, f32, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x200(r1)
	  stfd      f31, 0x1F8(r1)
	  fmr       f31, f1
	  stw       r31, 0x1F4(r1)
	  stw       r30, 0x1F0(r1)
	  stw       r29, 0x1EC(r1)
	  mr        r29, r5
	  stw       r28, 0x1E8(r1)
	  mr        r28, r3
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x1D8(r1)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x1DC(r1)
	  lfs       f0, 0x8(r4)
	  li        r4, 0x1
	  stfs      f0, 0x1E0(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x1D8(r1)
	  lfs       f2, 0x1E0(r1)
	  bl        -0xAE6DC
	  stfs      f1, 0x1DC(r1)
	  li        r30, 0xFF
	  li        r31, 0
	  lfs       f0, 0x1D8(r1)
	  addi      r4, r1, 0x1C8
	  addi      r3, r28, 0
	  stfs      f0, 0x1CC(r1)
	  li        r5, 0x1
	  lfs       f0, 0x1DC(r1)
	  stfs      f0, 0x1D0(r1)
	  lfs       f0, 0x1E0(r1)
	  stfs      f0, 0x1D4(r1)
	  lfs       f0, 0x1D0(r1)
	  fadds     f0, f0, f31
	  stfs      f0, 0x1D0(r1)
	  stb       r30, 0x1C8(r1)
	  stb       r31, 0x1C9(r1)
	  stb       r31, 0x1CA(r1)
	  stb       r30, 0x1CB(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r4, 0x2E4(r28)
	  lwz       r12, 0x3B4(r28)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x6070(r2)
	  mr        r3, r28
	  addi      r4, r1, 0x150
	  stfs      f0, 0x158(r1)
	  addi      r5, r1, 0x168
	  stfs      f0, 0x154(r1)
	  stfs      f0, 0x150(r1)
	  stfs      f0, 0x164(r1)
	  stfs      f0, 0x160(r1)
	  stfs      f0, 0x15C(r1)
	  stfs      f0, 0x170(r1)
	  stfs      f0, 0x16C(r1)
	  stfs      f0, 0x168(r1)
	  stfs      f0, 0x17C(r1)
	  stfs      f0, 0x178(r1)
	  lfs       f1, -0x6060(r2)
	  lfs       f3, 0x1D8(r1)
	  fneg      f31, f1
	  stfs      f0, 0x174(r1)
	  fadds     f2, f3, f1
	  lfs       f0, -0x2370(r13)
	  fadds     f5, f3, f31
	  stfs      f2, 0x150(r1)
	  lfs       f3, 0x1DC(r1)
	  fadds     f0, f3, f0
	  stfs      f0, 0x154(r1)
	  lfs       f0, 0x1E0(r1)
	  fadds     f4, f0, f1
	  fadds     f1, f0, f31
	  stfs      f4, 0x158(r1)
	  lfs       f0, -0x236C(r13)
	  stfs      f2, 0x15C(r1)
	  fadds     f0, f3, f0
	  stfs      f0, 0x160(r1)
	  stfs      f1, 0x164(r1)
	  lfs       f0, -0x2368(r13)
	  stfs      f5, 0x168(r1)
	  fadds     f0, f3, f0
	  stfs      f0, 0x16C(r1)
	  stfs      f1, 0x170(r1)
	  lfs       f0, -0x2364(r13)
	  stfs      f5, 0x174(r1)
	  fadds     f0, f3, f0
	  stfs      f0, 0x178(r1)
	  stfs      f4, 0x17C(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r1, 0x15C
	  addi      r5, r1, 0x174
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0x1C4(r1)
	  addi      r4, r1, 0x1C4
	  addi      r3, r28, 0
	  stb       r30, 0x1C5(r1)
	  li        r5, 0x1
	  stb       r31, 0x1C6(r1)
	  stb       r30, 0x1C7(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r4, 0x2E4(r28)
	  lwz       r12, 0x3B4(r28)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x6070(r2)
	  mr        r3, r28
	  addi      r4, r1, 0xDC
	  stfs      f0, 0xE4(r1)
	  addi      r5, r1, 0xF4
	  stfs      f0, 0xE0(r1)
	  stfs      f0, 0xDC(r1)
	  stfs      f0, 0xF0(r1)
	  stfs      f0, 0xEC(r1)
	  stfs      f0, 0xE8(r1)
	  stfs      f0, 0xFC(r1)
	  stfs      f0, 0xF8(r1)
	  stfs      f0, 0xF4(r1)
	  stfs      f0, 0x108(r1)
	  stfs      f0, 0x104(r1)
	  lfs       f2, 0x1CC(r1)
	  lfs       f1, -0x6060(r2)
	  fadds     f5, f2, f31
	  stfs      f0, 0x100(r1)
	  fadds     f2, f2, f1
	  lfs       f0, -0x2370(r13)
	  stfs      f2, 0xDC(r1)
	  lfs       f3, 0x1D0(r1)
	  fadds     f0, f3, f0
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0x1D4(r1)
	  fadds     f1, f0, f1
	  fadds     f4, f0, f31
	  stfs      f1, 0xE4(r1)
	  lfs       f0, -0x236C(r13)
	  stfs      f2, 0xE8(r1)
	  fadds     f0, f3, f0
	  stfs      f0, 0xEC(r1)
	  stfs      f4, 0xF0(r1)
	  lfs       f0, -0x2368(r13)
	  stfs      f5, 0xF4(r1)
	  fadds     f0, f3, f0
	  stfs      f0, 0xF8(r1)
	  stfs      f4, 0xFC(r1)
	  lfs       f0, -0x2364(r13)
	  stfs      f5, 0x100(r1)
	  fadds     f0, f3, f0
	  stfs      f0, 0x104(r1)
	  stfs      f1, 0x108(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r1, 0xE8
	  addi      r5, r1, 0x100
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r4, 0x2E4(r28)
	  lwz       r12, 0x3B4(r28)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  stb       r31, 0x1C0(r1)
	  addi      r4, r1, 0x1C0
	  addi      r3, r28, 0
	  stb       r30, 0x1C1(r1)
	  li        r5, 0x1
	  stb       r31, 0x1C2(r1)
	  stb       r30, 0x1C3(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r1, 0x1D8
	  addi      r5, r1, 0x1CC
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r29, 0
	  beq-      .loc_0x400
	  lwz       r12, 0x3B4(r28)
	  lis       r4, 0x803A
	  mr        r3, r28
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  stb       r30, 0x1BC(r1)
	  addi      r4, r1, 0x1BC
	  addi      r3, r28, 0
	  stb       r30, 0x1BD(r1)
	  li        r5, 0x1
	  stb       r30, 0x1BE(r1)
	  stb       r30, 0x1BF(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x1D0(r1)
	  addi      r3, r1, 0x1CC
	  lfs       f0, -0x605C(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1D0(r1)
	  lwz       r4, 0x2E4(r28)
	  addi      r4, r4, 0x1E0
	  bl        -0xDF1F4
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r29
	  lwz       r3, 0x10(r3)
	  bl        -0xEE81C
	  lwz       r12, 0x3B4(r28)
	  neg       r0, r3
	  lwz       r4, 0x2DEC(r13)
	  srawi     r6, r0, 0x1
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r28, 0
	  mtlr      r12
	  addze     r6, r6
	  addi      r8, r29, 0
	  crclr     6, 0x6
	  addi      r5, r1, 0x1CC
	  li        r7, 0
	  blrl

	.loc_0x400:
	  lwz       r0, 0x204(r1)
	  lfd       f31, 0x1F8(r1)
	  lwz       r31, 0x1F4(r1)
	  lwz       r30, 0x1F0(r1)
	  lwz       r29, 0x1EC(r1)
	  lwz       r28, 0x1E8(r1)
	  addi      r1, r1, 0x200
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801169B0
 * Size:	00026C
 */
void drawArrow(Graphics&, Vector3f&, Vector3f&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x148(r1)
	  stfd      f31, 0x140(r1)
	  stfd      f30, 0x138(r1)
	  stfd      f29, 0x130(r1)
	  stfd      f28, 0x128(r1)
	  fmr       f28, f1
	  stw       r31, 0x124(r1)
	  addi      r31, r5, 0
	  li        r5, 0
	  stw       r30, 0x120(r1)
	  mr        r30, r4
	  stw       r29, 0x11C(r1)
	  mr        r29, r3
	  lwz       r12, 0x3B4(r29)
	  lwz       r6, 0x2E4(r29)
	  lwz       r12, 0x74(r12)
	  addi      r4, r6, 0x1E0
	  mtlr      r12
	  blrl
	  li        r6, 0xFF
	  stb       r6, 0xC8(r1)
	  li        r0, 0x7D
	  addi      r4, r1, 0xC8
	  stb       r0, 0xC9(r1)
	  li        r0, 0
	  addi      r3, r29, 0
	  stb       r0, 0xCA(r1)
	  li        r5, 0x1
	  stb       r6, 0xCB(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r30)
	  stfs      f0, 0x108(r1)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x10C(r1)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x110(r1)
	  lfs       f31, 0x0(r31)
	  lfs       f29, -0x6070(r2)
	  fmuls     f1, f31, f31
	  lfs       f30, 0x8(r31)
	  fmuls     f0, f29, f29
	  fmuls     f2, f30, f30
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x108E34
	  lfs       f0, -0x6070(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xE0
	  fdivs     f31, f31, f1
	  fdivs     f29, f29, f1
	  fdivs     f30, f30, f1

	.loc_0xE0:
	  lfs       f0, 0x108(r1)
	  fmuls     f2, f30, f28
	  fmuls     f1, f29, f28
	  addi      r6, r1, 0x5C
	  stfs      f0, 0xF0(r1)
	  fmuls     f0, f31, f28
	  lfs       f3, 0x10C(r1)
	  addi      r5, r1, 0x58
	  stfs      f3, 0xF4(r1)
	  addi      r4, r1, 0x54
	  addi      r3, r1, 0xBC
	  lfs       f3, 0x110(r1)
	  stfs      f3, 0xF8(r1)
	  stfs      f2, 0x5C(r1)
	  stfs      f1, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  bl        -0xDF9B4
	  lfs       f2, 0xF0(r1)
	  fneg      f0, f30
	  lfs       f1, 0xBC(r1)
	  mr        r3, r29
	  lfs       f4, 0xF4(r1)
	  lfs       f3, 0xC0(r1)
	  fadds     f1, f2, f1
	  lfs       f5, 0xF8(r1)
	  lfs       f2, 0xC4(r1)
	  fadds     f3, f4, f3
	  addi      r4, r1, 0x108
	  stfs      f1, 0xF0(r1)
	  fadds     f1, f5, f2
	  addi      r5, r1, 0xF0
	  stfs      f3, 0xF4(r1)
	  stfs      f1, 0xF8(r1)
	  lfs       f1, 0xF0(r1)
	  stfs      f1, 0xE4(r1)
	  lfs       f2, 0xF4(r1)
	  stfs      f2, 0xE8(r1)
	  lfs       f3, 0xF8(r1)
	  stfs      f3, 0xEC(r1)
	  stfs      f1, 0xD8(r1)
	  stfs      f2, 0xDC(r1)
	  stfs      f3, 0xE0(r1)
	  lfs       f4, -0x235C(r13)
	  lfs       f2, -0x2360(r13)
	  fmuls     f0, f0, f4
	  lfs       f1, 0xE4(r1)
	  fmuls     f2, f2, f4
	  lfs       f3, 0xE8(r1)
	  fmuls     f5, f31, f4
	  fadds     f0, f1, f0
	  lfs       f4, 0xEC(r1)
	  fadds     f2, f3, f2
	  fadds     f1, f4, f5
	  stfs      f0, 0xE4(r1)
	  stfs      f2, 0xE8(r1)
	  stfs      f1, 0xEC(r1)
	  lfs       f4, -0x2354(r13)
	  lfs       f2, -0x2358(r13)
	  fmuls     f0, f30, f4
	  lfs       f1, 0xD8(r1)
	  fmuls     f2, f2, f4
	  lfs       f3, 0xDC(r1)
	  fmuls     f5, f31, f4
	  fadds     f0, f1, f0
	  lfs       f4, 0xE0(r1)
	  fadds     f2, f3, f2
	  fadds     f1, f4, f5
	  stfs      f0, 0xD8(r1)
	  stfs      f2, 0xDC(r1)
	  stfs      f1, 0xE0(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r1, 0xF0
	  addi      r5, r1, 0xE4
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r1, 0xF0
	  addi      r5, r1, 0xD8
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x14C(r1)
	  lfd       f31, 0x140(r1)
	  lfd       f30, 0x138(r1)
	  lfd       f29, 0x130(r1)
	  lfd       f28, 0x128(r1)
	  lwz       r31, 0x124(r1)
	  lwz       r30, 0x120(r1)
	  lwz       r29, 0x11C(r1)
	  addi      r1, r1, 0x148
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80116C1C
 * Size:	0001E8
 */
void CRSplineDraw(Graphics&, int, Vector3f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stfd      f31, 0x98(r1)
	  stfd      f30, 0x90(r1)
	  stfd      f29, 0x88(r1)
	  stfd      f28, 0x80(r1)
	  stmw      r27, 0x6C(r1)
	  mr        r27, r3
	  addi      r29, r5, 0
	  addi      r28, r4, 0
	  li        r5, 0
	  lwz       r12, 0x3B4(r27)
	  lwz       r6, 0x2E4(r27)
	  lwz       r12, 0x74(r12)
	  addi      r4, r6, 0x1E0
	  mtlr      r12
	  blrl
	  li        r6, 0xFF
	  stb       r6, 0x24(r1)
	  li        r0, 0xA
	  addi      r4, r1, 0x24
	  stb       r0, 0x25(r1)
	  li        r0, 0x64
	  addi      r3, r27, 0
	  stb       r0, 0x26(r1)
	  li        r5, 0x1
	  stb       r6, 0x27(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  xoris     r0, r28, 0x8000
	  lfs       f28, -0x6070(r2)
	  stw       r0, 0x64(r1)
	  lis       r0, 0x4330
	  lfd       f1, -0x6068(r2)
	  fmr       f30, f28
	  stw       r0, 0x60(r1)
	  lfs       f2, -0x6078(r2)
	  addi      r31, r1, 0x20
	  lfd       f0, 0x60(r1)
	  lfs       f31, -0x605C(r2)
	  li        r30, 0
	  fsubs     f0, f0, f1
	  fdivs     f29, f2, f0
	  b         .loc_0x1BC

	.loc_0xBC:
	  stfs      f30, 0x54(r1)
	  fmr       f1, f28
	  mr        r4, r29
	  stfs      f30, 0x50(r1)
	  addi      r3, r1, 0x4C
	  stfs      f30, 0x4C(r1)
	  stfs      f30, 0x48(r1)
	  stfs      f30, 0x44(r1)
	  stfs      f30, 0x40(r1)
	  bl        -0x4390
	  fadds     f1, f28, f29
	  addi      r4, r29, 0
	  addi      r3, r1, 0x40
	  bl        -0x43A0
	  lfs       f0, 0x50(r1)
	  li        r7, 0xFF
	  li        r6, 0xA
	  fadds     f0, f0, f31
	  li        r0, 0x64
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  stfs      f0, 0x50(r1)
	  li        r5, 0x1
	  lfs       f0, 0x44(r1)
	  fadds     f0, f0, f31
	  stfs      f0, 0x44(r1)
	  stb       r7, 0x20(r1)
	  stb       r6, 0x21(r1)
	  stb       r0, 0x22(r1)
	  stb       r7, 0x23(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r1, 0x4C
	  addi      r5, r1, 0x40
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  fmr       f1, f28
	  addi      r4, r29, 0
	  addi      r3, r1, 0x14
	  bl        -0x425C
	  lfs       f1, 0x14(r1)
	  mr        r3, r27
	  lfs       f0, 0x4C(r1)
	  addi      r4, r1, 0x28
	  stfs      f1, 0x34(r1)
	  lfs       f1, 0x18(r1)
	  addi      r5, r1, 0x34
	  lfs       f2, 0x1C(r1)
	  stfs      f1, 0x38(r1)
	  lfs       f1, -0x605C(r2)
	  stfs      f2, 0x3C(r1)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0x30(r1)
	  bl        -0x41C
	  fadds     f28, f28, f29
	  addi      r30, r30, 0x1

	.loc_0x1BC:
	  cmpw      r30, r28
	  blt+      .loc_0xBC
	  lmw       r27, 0x6C(r1)
	  lwz       r0, 0xA4(r1)
	  lfd       f31, 0x98(r1)
	  lfd       f30, 0x90(r1)
	  lfd       f29, 0x88(r1)
	  lfd       f28, 0x80(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80116E04
 * Size:	0003C0
 */
void drawCube(Graphics&, Vector3f&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2B0(r1)
	  stfd      f31, 0x2A8(r1)
	  fmr       f31, f1
	  stmw      r27, 0x294(r1)
	  mr        r27, r3
	  mr        r28, r4
	  lwz       r12, 0x3B4(r27)
	  lwz       r5, 0x2E4(r27)
	  lwz       r12, 0x74(r12)
	  addi      r4, r5, 0x1E0
	  mtlr      r12
	  li        r5, 0
	  blrl
	  li        r6, 0xFF
	  stb       r6, 0x228(r1)
	  li        r0, 0x7D
	  addi      r4, r1, 0x228
	  stb       r0, 0x229(r1)
	  li        r0, 0
	  addi      r3, r27, 0
	  stb       r0, 0x22A(r1)
	  li        r5, 0x1
	  stb       r6, 0x22B(r1)
	  lwz       r12, 0x3B4(r27)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x6070(r2)
	  fneg      f0, f31
	  stfs      f1, 0x234(r1)
	  stfs      f1, 0x230(r1)
	  stfs      f1, 0x22C(r1)
	  stfs      f1, 0x240(r1)
	  stfs      f1, 0x23C(r1)
	  stfs      f1, 0x238(r1)
	  stfs      f1, 0x24C(r1)
	  stfs      f1, 0x248(r1)
	  stfs      f1, 0x244(r1)
	  stfs      f1, 0x258(r1)
	  stfs      f1, 0x254(r1)
	  stfs      f1, 0x250(r1)
	  stfs      f1, 0x264(r1)
	  stfs      f1, 0x260(r1)
	  stfs      f1, 0x25C(r1)
	  stfs      f1, 0x270(r1)
	  stfs      f1, 0x26C(r1)
	  stfs      f1, 0x268(r1)
	  stfs      f1, 0x27C(r1)
	  stfs      f1, 0x278(r1)
	  stfs      f1, 0x274(r1)
	  stfs      f1, 0x288(r1)
	  stfs      f1, 0x284(r1)
	  stfs      f1, 0x280(r1)
	  lfs       f1, 0x0(r28)
	  lfs       f2, 0x4(r28)
	  fadds     f1, f1, f0
	  lfs       f3, 0x8(r28)
	  fadds     f4, f2, f0
	  fadds     f2, f3, f0
	  stfs      f1, 0x22C(r1)
	  stfs      f4, 0x230(r1)
	  stfs      f2, 0x234(r1)
	  lfs       f1, 0x0(r28)
	  fadds     f1, f1, f0
	  stfs      f1, 0x138(r1)
	  lfs       f1, 0x138(r1)
	  stfs      f1, 0x208(r1)
	  lfs       f1, 0x4(r28)
	  fadds     f1, f1, f0
	  stfs      f1, 0x20C(r1)
	  lfs       f1, 0x8(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0x210(r1)
	  lwz       r0, 0x208(r1)
	  lwz       r3, 0x20C(r1)
	  stw       r0, 0x238(r1)
	  lwz       r0, 0x210(r1)
	  stw       r3, 0x23C(r1)
	  stw       r0, 0x240(r1)
	  lfs       f1, 0x0(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0x12C(r1)
	  lfs       f1, 0x12C(r1)
	  stfs      f1, 0x1E8(r1)
	  lfs       f1, 0x4(r28)
	  fadds     f1, f1, f0
	  stfs      f1, 0x1EC(r1)
	  lfs       f1, 0x8(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0x1F0(r1)
	  lwz       r0, 0x1E8(r1)
	  lwz       r3, 0x1EC(r1)
	  stw       r0, 0x244(r1)
	  lwz       r0, 0x1F0(r1)
	  stw       r3, 0x248(r1)
	  stw       r0, 0x24C(r1)
	  lfs       f1, 0x0(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0x120(r1)
	  lfs       f1, 0x120(r1)
	  stfs      f1, 0x1CC(r1)
	  lfs       f1, 0x4(r28)
	  fadds     f1, f1, f0
	  stfs      f1, 0x1D0(r1)
	  lfs       f1, 0x8(r28)
	  fadds     f1, f1, f0
	  stfs      f1, 0x1D4(r1)
	  lwz       r0, 0x1CC(r1)
	  lwz       r3, 0x1D0(r1)
	  stw       r0, 0x250(r1)
	  lwz       r0, 0x1D4(r1)
	  stw       r3, 0x254(r1)
	  stw       r0, 0x258(r1)
	  lfs       f1, 0x0(r28)
	  fadds     f1, f1, f0
	  stfs      f1, 0x114(r1)
	  lfs       f1, 0x114(r1)
	  stfs      f1, 0x1AC(r1)
	  lfs       f1, 0x4(r28)
	  li        r29, 0
	  lis       r3, 0x5555
	  fadds     f1, f1, f31
	  mulli     r0, r29, 0xC
	  stfs      f1, 0x1B0(r1)
	  addi      r30, r1, 0x22C
	  add       r30, r30, r0
	  lfs       f1, 0x8(r28)
	  addi      r31, r3, 0x5556
	  fadds     f1, f1, f0
	  stfs      f1, 0x1B4(r1)
	  lwz       r0, 0x1AC(r1)
	  lwz       r3, 0x1B0(r1)
	  stw       r0, 0x25C(r1)
	  lwz       r0, 0x1B4(r1)
	  stw       r3, 0x260(r1)
	  stw       r0, 0x264(r1)
	  lfs       f1, 0x0(r28)
	  fadds     f1, f1, f0
	  stfs      f1, 0x108(r1)
	  lfs       f1, 0x108(r1)
	  stfs      f1, 0x18C(r1)
	  lfs       f1, 0x4(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0x190(r1)
	  lfs       f1, 0x8(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0x194(r1)
	  lwz       r0, 0x18C(r1)
	  lwz       r3, 0x190(r1)
	  stw       r0, 0x268(r1)
	  lwz       r0, 0x194(r1)
	  stw       r3, 0x26C(r1)
	  stw       r0, 0x270(r1)
	  lfs       f1, 0x0(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0xFC(r1)
	  lfs       f1, 0xFC(r1)
	  stfs      f1, 0x170(r1)
	  lfs       f1, 0x4(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0x174(r1)
	  lfs       f1, 0x8(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0x178(r1)
	  lwz       r0, 0x170(r1)
	  lwz       r3, 0x174(r1)
	  stw       r0, 0x274(r1)
	  lwz       r0, 0x178(r1)
	  stw       r3, 0x278(r1)
	  stw       r0, 0x27C(r1)
	  lfs       f1, 0x0(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0xF0(r1)
	  lfs       f1, 0xF0(r1)
	  stfs      f1, 0x158(r1)
	  lfs       f1, 0x4(r28)
	  fadds     f1, f1, f31
	  stfs      f1, 0x15C(r1)
	  lfs       f1, 0x8(r28)
	  fadds     f0, f1, f0
	  stfs      f0, 0x160(r1)
	  lwz       r0, 0x158(r1)
	  lwz       r3, 0x15C(r1)
	  stw       r0, 0x280(r1)
	  lwz       r0, 0x160(r1)
	  stw       r3, 0x284(r1)
	  stw       r0, 0x288(r1)

	.loc_0x2F4:
	  addi      r4, r29, 0x1
	  mulhw     r3, r31, r4
	  rlwinm    r0,r3,1,31,31
	  add       r0, r3, r0
	  mulli     r0, r0, 0x3
	  addi      r3, r27, 0
	  lwz       r12, 0x3B4(r27)
	  sub       r0, r4, r0
	  mulli     r0, r0, 0xC
	  lwz       r12, 0x98(r12)
	  addi      r5, r1, 0x22C
	  mtlr      r12
	  addi      r4, r30, 0
	  add       r5, r5, r0
	  blrl
	  addi      r4, r29, 0x5
	  mulhw     r3, r31, r4
	  rlwinm    r0,r3,1,31,31
	  add       r0, r3, r0
	  mulli     r0, r0, 0x3
	  addi      r3, r27, 0
	  addi      r5, r29, 0x4
	  lwz       r12, 0x3B4(r27)
	  sub       r0, r4, r0
	  lwz       r12, 0x98(r12)
	  mulli     r4, r5, 0xC
	  mtlr      r12
	  addi      r28, r1, 0x22C
	  add       r28, r28, r4
	  mulli     r0, r0, 0xC
	  addi      r5, r1, 0x22C
	  addi      r4, r28, 0
	  add       r5, r5, r0
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r30, 0
	  addi      r5, r28, 0
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x4
	  addi      r30, r30, 0xC
	  blt+      .loc_0x2F4
	  lmw       r27, 0x294(r1)
	  lwz       r0, 0x2B4(r1)
	  lfd       f31, 0x2A8(r1)
	  addi      r1, r1, 0x2B0
	  mtlr      r0
	  blr
	*/
}
