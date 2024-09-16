#include "PikiAI.h"

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
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C1E24
 * Size:	000060
 */
ActRope::ActRope(Piki* piki)
    : Action(piki, false)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0x1F94
	  lis       r3, 0x802B
	  addi      r0, r3, 0x79BC
	  stw       r0, 0x0(r31)
	  subi      r4, r13, 0x4510
	  li        r0, -0x1
	  lfs       f0, -0x6B28(r2)
	  mr        r3, r31
	  stfs      f0, 0x20(r31)
	  stfs      f0, 0x1C(r31)
	  stfs      f0, 0x18(r31)
	  stw       r4, 0x10(r31)
	  sth       r0, 0x8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C1E84
 * Size:	000178
 */
void ActRope::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x3E
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x20
	  stw       r30, 0x70(r1)
	  bl        0x5D0B4
	  addi      r30, r3, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x3E
	  bl        0x5D0A4
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0x8B14
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0xC8(r3)
	  ori       r0, r0, 0x80
	  stw       r0, 0xC8(r3)
	  bl        0x156198
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x6B10(r2)
	  stw       r0, 0x6C(r1)
	  lis       r0, 0x4330
	  lfs       f4, -0x6B20(r2)
	  stw       r0, 0x68(r1)
	  lfs       f3, -0x6B24(r2)
	  lfd       f1, 0x68(r1)
	  lfs       f0, -0x6B14(r2)
	  fsubs     f5, f1, f2
	  lfs       f1, -0x6B18(r2)
	  lfs       f2, -0x6B1C(r2)
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fsubs     f0, f3, f0
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x14(r31)
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xB8
	  li        r0, 0x3
	  stb       r0, 0x408(r3)

	.loc_0xB8:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x188(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x148
	  lfs       f0, -0x6B28(r2)
	  addi      r4, r1, 0x48
	  stfs      f0, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  stfs      f0, 0x48(r1)
	  stfs      f0, 0x5C(r1)
	  stfs      f0, 0x58(r1)
	  stfs      f0, 0x54(r1)
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x188(r3)
	  bl        -0x393E8
	  lfs       f0, -0x6B28(r2)
	  addi      r3, r1, 0x48
	  addi      r5, r1, 0x3C
	  stfs      f0, 0x44(r1)
	  addi      r6, r1, 0x30
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x40(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x3C(r1)
	  stfs      f0, 0x30(r1)
	  lwz       r4, 0xC(r31)
	  lfs       f1, 0x194(r4)
	  addi      r4, r4, 0x94
	  bl        -0x3A71C
	  lwz       r3, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stw       r3, 0x18(r31)
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x38(r1)
	  stw       r0, 0x20(r31)
	  b         .loc_0x160

	.loc_0x148:
	  lfs       f0, -0x4508(r13)
	  stfs      f0, 0x18(r31)
	  lfs       f0, -0x4504(r13)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, -0x4500(r13)
	  stfs      f0, 0x20(r31)

	.loc_0x160:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C1FFC
 * Size:	000070
 */
int ActRope::exec()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x30(r1)
	  lwz       r5, 0xC(r3)
	  lwz       r0, 0x188(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x1C
	  li        r3, 0x1
	  b         .loc_0x68

	.loc_0x1C:
	  lfs       f2, 0x14(r3)
	  lfs       f0, 0x18(r3)
	  lfs       f1, 0x20(r3)
	  fmuls     f0, f0, f2
	  fmuls     f1, f1, f2
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x18(r1)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x1C(r3)
	  li        r3, 0
	  fmuls     f0, f0, f2
	  stfs      f0, 0x24(r1)
	  stfs      f1, 0x28(r1)
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r4, 0x70(r5)
	  stw       r0, 0x74(r5)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x78(r5)

	.loc_0x68:
	  addi      r1, r1, 0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C206C
 * Size:	00009C
 */
void ActRope::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  lfs       f2, -0x44FC(r13)
	  lfs       f0, 0x18(r3)
	  lfs       f1, 0x20(r3)
	  fmuls     f0, f0, f2
	  fmuls     f1, f1, f2
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x18(r1)
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x1C(r3)
	  fmuls     f0, f0, f2
	  stfs      f0, 0x24(r1)
	  stfs      f1, 0x28(r1)
	  lwz       r5, 0xC(r3)
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r4, 0x70(r5)
	  stw       r0, 0x74(r5)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x78(r5)
	  lwz       r5, 0xC(r3)
	  lwz       r4, 0x70(r5)
	  lwz       r0, 0x74(r5)
	  stw       r4, 0xA4(r5)
	  stw       r0, 0xA8(r5)
	  lwz       r0, 0x78(r5)
	  stw       r0, 0xAC(r5)
	  lwz       r4, 0xC(r3)
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,25,23
	  stw       r0, 0xC8(r4)
	  lwz       r3, 0xC(r3)
	  bl        -0x3187C
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C2108
 * Size:	000064
 */
ActRope::~ActRope()
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
	  addi      r0, r3, 0x79BC
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x1CCC
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x7AFA0

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
