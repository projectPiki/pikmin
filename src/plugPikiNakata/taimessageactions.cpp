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
 * Address:	80131EF8
 * Size:	00002C
 */
void TaiSendMessageAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  mr        r0, r4
  stwu      r1, -0x8(r1)
  lwz       r4, 0x8(r3)
  mr        r3, r0
  bl        0x19BFC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80131F24
 * Size:	000040
 */
void TaiKeySendMessageAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  mr        r5, r3
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0xC(r3)
  lwz       r3, 0x414(r4)
  and.      r0, r3, r0
  beq-      .loc_0x2C
  mr        r3, r4
  lwz       r4, 0x8(r5)
  bl        0x19BC0

.loc_0x2C:
  li        r3, 0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}
