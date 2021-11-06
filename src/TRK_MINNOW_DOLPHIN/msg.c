#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
/*
void TRKMessageAdd(void)
{
	// UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
/*
void TRKMessageGet(void)
{
	// UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	8021C4A4
 * Size:	000028
 */
void TRKMessageSend(int param_1)
{

  TRKWriteUARTN(param_1 + 0x10,*(unsigned int*)(param_1 + 8));
  return;
  
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r4, 0x8(r3)
  addi      r3, r3, 0x10
  bl        0x4238
  addi      r1, r1, 0x8
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}
