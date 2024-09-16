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
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800BD364
 * Size:	0000CC
 */
ActPickCreature::ActPickCreature(Piki* piki)
    : AndAction(piki)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r3, 0x8(r1)
	  lwz       r30, 0x8(r1)
	  addi      r3, r30, 0
	  bl        0x6A40
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7ED0
	  stw       r0, 0x0(r30)
	  li        r4, 0
	  lis       r3, 0x802B
	  stw       r4, 0x14(r30)
	  addi      r0, r3, 0x70D8
	  li        r3, 0x24
	  stw       r0, 0x0(r30)
	  stw       r4, 0x18(r30)
	  bl        -0x763B8
	  mr.       r30, r3
	  beq-      .loc_0x70
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x2468

	.loc_0x70:
	  li        r3, 0x20
	  bl        -0x763D4
	  mr.       r29, r3
	  beq-      .loc_0x8C
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        -0x159F4

	.loc_0x8C:
	  lwz       r3, 0x8(r1)
	  addi      r5, r30, 0
	  addi      r7, r29, 0
	  crclr     6, 0x6
	  li        r4, 0x2
	  li        r6, 0
	  li        r8, 0
	  bl        0x6F64
	  lwz       r3, 0x8(r1)
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
 * Address:	800BD430
 * Size:	000020
 */
void ActPickCreature::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x6AD8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void ActPickCreature::InitGoto::initialise(Action*, Action*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00019C
 */
ActDeliver::ActDeliver(Piki* piki)
    : AndAction(piki)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800BD450
 * Size:	000064
 */
void ActDeliver::Initialiser::initialise(Action*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lwz       r31, 0x4(r3)
	  lwz       r3, 0x18(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  beq-      .loc_0x38
	  bl        0x26EF0
	  li        r0, 0
	  stw       r0, 0x18(r30)

	.loc_0x38:
	  stw       r31, 0x18(r30)
	  lwz       r3, 0x18(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  bl        0x26EC4

	.loc_0x4C:
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
 * Address:	800BD4B4
 * Size:	000084
 */
void ActDeliver::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  bl        0x6A44
	  lwz       r3, 0x18(r30)
	  cmplwi    r3, 0
	  bne-      .loc_0x58
	  beq-      .loc_0x40
	  beq-      .loc_0x40
	  bl        0x26E84
	  li        r0, 0
	  stw       r0, 0x18(r30)

	.loc_0x40:
	  stw       r31, 0x18(r30)
	  lwz       r3, 0x18(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x6C
	  bl        0x26E58
	  b         .loc_0x6C

	.loc_0x58:
	  lwz       r4, 0x4(r30)
	  lwz       r4, 0xC(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x6C
	  stw       r3, 0x4(r4)

	.loc_0x6C:
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
 * Address:	800BD538
 * Size:	000074
 */
ActDeliver::~ActDeliver()
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
	  beq-      .loc_0x58
	  lis       r3, 0x802B
	  addi      r0, r3, 0x6FF8
	  stw       r0, 0x0(r30)
	  beq-      .loc_0x48
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7ED0
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x688C

	.loc_0x48:
	  extsh.    r0, r31
	  ble-      .loc_0x58
	  mr        r3, r30
	  bl        -0x763E0

	.loc_0x58:
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
 * Address:	800BD5AC
 * Size:	00000C
 */
void ActDeliver::defaultInitialiser()
{
	// Generated from stw r0, 0x18(r3)
	// _18 = 0;
}

/*
 * --INFO--
 * Address:	800BD5B8
 * Size:	000040
 */
void ActDeliver::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x18(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C
	  bl        0x26D94
	  li        r0, 0
	  stw       r0, 0x18(r31)

	.loc_0x2C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BD5F8
 * Size:	000004
 */
void Action::Initialiser::initialise(Action*) { }

/*
 * --INFO--
 * Address:	800BD5FC
 * Size:	000074
 */
ActPickCreature::~ActPickCreature()
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
	  beq-      .loc_0x58
	  lis       r3, 0x802B
	  addi      r0, r3, 0x70D8
	  stw       r0, 0x0(r30)
	  beq-      .loc_0x48
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7ED0
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x67C8

	.loc_0x48:
	  extsh.    r0, r31
	  ble-      .loc_0x58
	  mr        r3, r30
	  bl        -0x764A4

	.loc_0x58:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
