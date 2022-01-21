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
 * Address:	8005B690
 * Size:	00009C
 */
GameExitSection::GameExitSection()
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r4, r13, 0x7060
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0x266F0
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0
	  subi      r4, r13, 0x7060
	  bl        -0x1AF84
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x7DA8
	  stw       r0, 0x0(r31)
	  li        r4, 0x2
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x1C6B4
	  lwz       r3, 0x2DEC(r13)
	  li        r5, 0
	  subi      r0, r13, 0x7058
	  stw       r5, 0x19C(r3)
	  mr        r3, r31
	  lwz       r4, 0x2DEC(r13)
	  addi      r4, r4, 0x214
	  stw       r5, 0x10(r4)
	  stw       r5, 0xC(r4)
	  stw       r5, 0x8(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005B72C
 * Size:	000050
 */
void GameExitSection::update()
{
	/*
	.loc_0x0:
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  li        r0, 0
	  lis       r3, 0x803A
	  stw       r0, 0x1F4(r4)
	  subi      r3, r3, 0x24E0
	  lwz       r3, 0x244(r3)
	  cmpwi     r3, 0
	  beq-      .loc_0x38
	  li        r0, 0x2
	  stw       r0, 0x1F0(r4)
	  addi      r0, r3, 0x3
	  stw       r0, 0x2B0(r4)
	  b         .loc_0x40

	.loc_0x38:
	  li        r0, 0x1
	  stw       r0, 0x1F0(r4)

	.loc_0x40:
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0x1
	  stb       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005B77C
 * Size:	000004
 */
void GameExitSection::init() { }
