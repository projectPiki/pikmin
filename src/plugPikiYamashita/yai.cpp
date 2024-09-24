#include "YaiStrategy.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
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
 * Address:	801E9654
 * Size:	000064
 */
YaiStrategy::YaiStrategy(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  bl        -0x9C4D4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x5AA8
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        .loc_0x64
	  mr        r3, r29
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0x64:
	*/
}

/*
 * --INFO--
 * Address:	801E96B8
 * Size:	00004C
 */
void YaiStrategy::init(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r5
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  stw       r4, 0x4(r3)
	  lwz       r0, 0x4(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1A26DC
	  stw       r3, 0x8(r30)
	  stw       r31, 0xC(r30)
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
 * Address:	801E9704
 * Size:	000044
 */
void YaiStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x324(r4)
	  lwz       r0, 0x324(r4)
	  lwz       r3, 0x8(r3)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801E9748
 * Size:	0000AC
 */
void YaiStrategy::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0x324(r4)
	  lwz       r3, 0x8(r3)
	  rlwinm    r0,r0,2,0,29
	  lwz       r31, 0x324(r30)
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x90
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r31,2,0,29
	  addi      r4, r30, 0
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x324(r30)
	  mr        r4, r30
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
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
 * Address:	801E97F4
 * Size:	0000AC
 */
void YaiStrategy::eventPerformed(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r31, 0x4(r4)
	  lwz       r3, 0x8(r3)
	  lwz       r0, 0x324(r31)
	  lwz       r30, 0x324(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x90
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r30,2,0,29
	  addi      r4, r31, 0
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x324(r31)
	  mr        r4, r31
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
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
 * Address:	801E98A0
 * Size:	000020
 */
void YaiStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x9C6E8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
