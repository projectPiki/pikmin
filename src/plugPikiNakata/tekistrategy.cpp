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
 * Address:	8014D1A4
 * Size:	000010
 */
TekiStrategy::TekiStrategy()
{
	/*
	.loc_0x0:
	  lis       r4, 0x802D
	  subi      r0, r4, 0x191C
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014D1B4
 * Size:	000004
 */
void TekiStrategy::start(Teki&) { }

/*
 * --INFO--
 * Address:	8014D1B8
 * Size:	000004
 */
void TekiStrategy::act(Teki&) { }

/*
 * --INFO--
 * Address:	8014D1BC
 * Size:	000004
 */
void TekiStrategy::eventPerformed(TekiEvent&) { }

/*
 * --INFO--
 * Address:	8014D1C0
 * Size:	000004
 */
void TekiStrategy::createEffect(Teki&, int) { }

/*
 * --INFO--
 * Address:	8014D1C4
 * Size:	000034
 */
void TekiStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r4)
	  mr        r4, r5
	  lwz       r12, 0x1AC(r12)
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
 * Address:	8014D1F8
 * Size:	000034
 */
void TekiStrategy::drawDebugInfo(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r4)
	  mr        r4, r5
	  lwz       r12, 0x1B8(r12)
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
 * Address:	8014D22C
 * Size:	000034
 */
void TekiStrategy::interact(Teki&, TekiInteractionKey&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r4)
	  mr        r4, r5
	  lwz       r12, 0x1A8(r12)
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
 * Address:	8014D260
 * Size:	000004
 */
void TekiStrategy::spawnCorpseParts(Teki&) { }

/*
 * --INFO--
 * Address:	8014D264
 * Size:	00006C
 */
TekiStrategyTable::TekiStrategyTable(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  stw       r4, 0x0(r3)
	  lwz       r0, 0x0(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x106280
	  li        r5, 0
	  stw       r3, 0x4(r31)
	  addi      r4, r5, 0
	  li        r6, 0
	  b         .loc_0x48

	.loc_0x38:
	  lwz       r3, 0x4(r31)
	  addi      r6, r6, 0x1
	  stwx      r4, r3, r5
	  addi      r5, r5, 0x4

	.loc_0x48:
	  lwz       r0, 0x0(r31)
	  cmpw      r6, r0
	  blt+      .loc_0x38
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
