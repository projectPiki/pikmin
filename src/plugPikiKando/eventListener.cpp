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
 * Address:	80093FA8
 * Size:	000090
 */
EventTalker::EventTalker()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x738C
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r30)
	  subi      r4, r3, 0x62C
	  addi      r3, r30, 0
	  stw       r31, 0x10(r30)
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  bl        -0x6F120
	  lis       r3, 0x802B
	  subi      r0, r3, 0x5E0
	  stw       r0, 0x0(r30)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x620
	  stw       r31, 0x10(r30)
	  mr        r3, r30
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  stw       r0, 0x4(r30)
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
 * Address:	80094038
 * Size:	00005C
 */
void EventTalker::informEvent(Event&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lwz       r31, 0x10(r3)
	  b         .loc_0x3C

	.loc_0x20:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0xC(r31)

	.loc_0x3C:
	  cmplwi    r31, 0
	  bne+      .loc_0x20
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
 * Address:	80094094
 * Size:	000004
 */
void EventListener::gotEvent(Event&) { }

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void EventTalker::addEventListener(EventListener*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void EventTalker::removeEventListener(EventListener*)
{
	// UNUSED FUNCTION
}
