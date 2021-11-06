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
 * Address:	8014A398
 * Size:	000034
 */
TekiEvent::TekiEvent(int, Teki *)
{
/*
.loc_0x0:
  mflr      r0
  li        r6, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  bl        0x4C
  mr        r3, r31
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014A3CC
 * Size:	000030
 */
TekiEvent::TekiEvent(int, Teki *, Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  bl        .loc_0x30
  mr        r3, r31
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr       

.loc_0x30:
*/
}

/*
 * --INFO--
 * Address:	8014A3FC
 * Size:	000010
 */
void TekiEvent::init(int, Teki *, Creature *)
{
/*
.loc_0x0:
  stw       r4, 0x0(r3)
  stw       r5, 0x4(r3)
  stw       r6, 0x8(r3)
  blr
*/
}
