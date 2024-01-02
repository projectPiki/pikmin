#include "types.h"

/*
 * --INFO--
 * Address:	8021CEE0
 * Size:	000014
 */
void TRKInitializeDispatcher(void)
{
	/*
	.loc_0x0:
	  lis       r3, 0x803D
	  li        r0, 0x20
	  stw       r0, 0x5CE8(r3)
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void TRKOverrideDispatch(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021CEF4
 * Size:	000084
 */
void TRKDispatchMessage(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0x500
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x858
	  addi      r3, r30, 0
	  addi      r4, r1, 0x8
	  bl        -0x4E0
	  lis       r3, 0x803D
	  lbz       r4, 0x8(r1)
	  lwz       r0, 0x5CE8(r3)
	  cmplw     r4, r0
	  bge-      .loc_0x68
	  lis       r3, 0x802F
	  rlwinm    r4,r4,2,0,29
	  subi      r0, r3, 0x6B40
	  add       r3, r0, r4
	  lwz       r12, 0x0(r3)
	  addi      r3, r30, 0
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x68:
	  mr        r3, r31
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}
