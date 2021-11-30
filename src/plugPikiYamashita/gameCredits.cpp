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
 * Address:	8019B888
 * Size:	000094
 */
GameCreditsSection::GameCreditsSection()
{
/*
.loc_0x0:
  mflr      r0
  addi      r4, r13, 0xFD8
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        -0x1668E8
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x0(r31)
  addi      r3, r31, 0
  addi      r4, r13, 0xFD8
  bl        -0x15B17C
  lis       r3, 0x802A
  addi      r0, r3, 0x642C
  lis       r3, 0x802D
  stw       r0, 0x0(r31)
  addi      r0, r3, 0x6C54
  lis       r3, 0x802D
  stw       r0, 0x0(r31)
  addi      r4, r3, 0x6BB4
  addi      r3, r31, 0
  bl        -0x15B1A4
  lwz       r4, 0x2DEC(r13)
  li        r0, 0x1
  lis       r3, 0x803A
  stw       r0, 0x14(r4)
  subi      r4, r3, 0x24E0
  li        r0, 0
  stw       r0, 0x24C(r4)
  mr        r3, r31
  stw       r0, 0x250(r4)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8019B91C
 * Size:	000004
 */
void GameCreditsSection::init()
{
}
