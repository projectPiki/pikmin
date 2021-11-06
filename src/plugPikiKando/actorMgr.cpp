#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
ActorMgr::ActorMgr(MapMgr *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void ActorMgr::createObject()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80119AB4
 * Size:	00007C
 */
void ActorMgr::newActor(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r4
  stw       r29, 0x14(r1)
  mr        r29, r3
  lwz       r12, 0x0(r29)
  lwz       r12, 0x78(r12)
  mtlr      r12
  blrl      
  mr.       r31, r3
  beq-      .loc_0x5C
  lwz       r5, 0x40(r29)
  mr        r3, r31
  lwz       r6, 0x44(r29)
  mr        r4, r30
  lwz       r7, 0x48(r29)
  lwz       r5, 0x0(r5)
  lwz       r6, 0x0(r6)
  lwz       r7, 0x0(r7)
  bl        -0xFC

.loc_0x5C:
  mr        r3, r31
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
 * Address:	........
 * Size:	000084
 */
ActorMgr::~ActorMgr()
{
	// UNUSED FUNCTION
}
