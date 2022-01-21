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
 * Address:	........
 * Size:	000074
 */
Actor::Actor()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80119A10
 * Size:	0000A4
 */
void Actor::setType(int, PikiShapeObject*, CreatureProp*, SimpleAI*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  mr        r30, r7
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  stw       r6, 0x224(r3)
	  stw       r5, 0x3B0(r3)
	  bl        -0x41154
	  lwz       r4, 0x3B0(r29)
	  stw       r3, 0x24(r4)
	  addi      r3, r29, 0x304
	  lwz       r8, 0x3B0(r29)
	  lwz       r6, 0x3130(r13)
	  lwz       r4, 0x24(r8)
	  addi      r5, r8, 0x14
	  lwz       r7, 0x3C(r6)
	  addi      r6, r8, 0x4
	  bl        0x5E7C
	  addi      r3, r1, 0x1C
	  li        r4, 0x3
	  bl        0x54EC
	  addi      r31, r3, 0
	  addi      r3, r1, 0x24
	  li        r4, 0x3
	  li        r5, 0
	  bl        0x550C
	  addi      r4, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r29, 0x304
	  bl        0x5FD8
	  stw       r30, 0x2E8(r29)
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Actor::startAI(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void Actor::refresh(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void Actor::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Actor::doAnimation()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void Actor::doAI()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Actor::doKill()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void Actor::startMotion(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void Actor::startMotion(int, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void Actor::finishMotion()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void Actor::finishMotion(float)
{
	// UNUSED FUNCTION
}
