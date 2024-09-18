#include "Interactions.h"
#include "teki.h"

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
 * Address:	........
 * Size:	00000C
 */
TekiInteractionKey::TekiInteractionKey(int, Interaction*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014A40C
 * Size:	000044
 */
bool InteractAttack::actTeki(Teki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r0, 0x10(r1)
	  addi      r0, r1, 0x10
	  stw       r3, 0x14(r1)
	  addi      r3, r4, 0
	  mr        r4, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1A4(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A450
 * Size:	000090
 */
bool InteractBomb::actTeki(Teki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r7, r5, 0x3064
	  li        r5, 0
	  stwu      r1, -0x68(r1)
	  lwz       r6, 0x2C4(r4)
	  addi      r0, r1, 0x48
	  lfs       f1, 0x8(r3)
	  addi      r10, r1, 0x5C
	  lwz       r6, 0x84(r6)
	  lwz       r9, 0x4(r3)
	  lis       r3, 0x802B
	  lwz       r8, 0x4(r6)
	  subi      r6, r3, 0x31FC
	  lwz       r3, 0x0(r8)
	  lfs       f0, 0xAC(r3)
	  addi      r3, r4, 0
	  addi      r4, r10, 0
	  stw       r7, 0x48(r1)
	  fmuls     f0, f1, f0
	  stw       r9, 0x4C(r1)
	  stw       r6, 0x48(r1)
	  stfs      f0, 0x50(r1)
	  stw       r5, 0x54(r1)
	  stw       r5, 0x5C(r1)
	  stb       r5, 0x58(r1)
	  stw       r0, 0x60(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1A4(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x6C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A4E0
 * Size:	000044
 */
bool InteractHitEffect::actTeki(Teki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r0, 0x10(r1)
	  addi      r0, r1, 0x10
	  stw       r3, 0x14(r1)
	  addi      r3, r4, 0
	  mr        r4, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1A4(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A524
 * Size:	000008
 */
bool InteractSwallow::actTeki(Teki*) { return true; }

/*
 * --INFO--
 * Address:	8014A52C
 * Size:	000058
 */
bool InteractPress::actTeki(Teki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r3)
	  addi      r3, r1, 0x10
	  li        r4, 0x3
	  bl        -0x184
	  lwz       r12, 0x0(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x1A0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2C(r1)
	  li        r3, 0x1
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A584
 * Size:	000008
 */
bool InteractFlick::actTeki(Teki*) { return true; }
