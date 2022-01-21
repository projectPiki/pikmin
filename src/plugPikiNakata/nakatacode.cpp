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
 * Address:	8011B6AC
 * Size:	000038
 */
void NakataCodeInitializer::init()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x3148(r13)
	  bl        0x31D8
	  li        r0, 0
	  stw       r0, 0x3158(r13)
	  bl        0x2EEBC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
