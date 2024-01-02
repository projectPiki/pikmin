#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void __exit(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021553C
 * Size:	00010C
 */
void exit(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  lwz       r0, 0x3478(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x9C
	  lis       r3, 0x803D
	  addi      r31, r3, 0x40F0
	  b         .loc_0x48

	.loc_0x28:
	  lwz       r3, 0x347C(r13)
	  subi      r3, r3, 0x1
	  rlwinm    r0,r3,2,0,29
	  stw       r3, 0x347C(r13)
	  add       r3, r31, r0
	  lwz       r12, 0x0(r3)
	  mtlr      r12
	  blrl

	.loc_0x48:
	  lwz       r0, 0x347C(r13)
	  cmpwi     r0, 0
	  bgt+      .loc_0x28
	  bl        -0xC2C
	  lis       r3, 0x8022
	  addi      r0, r3, 0x1FC0
	  mr        r31, r0
	  b         .loc_0x74

	.loc_0x68:
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x4

	.loc_0x74:
	  lwz       r12, 0x0(r31)
	  cmplwi    r12, 0
	  bne+      .loc_0x68
	  lwz       r12, 0x3484(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x9C
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x3484(r13)

	.loc_0x9C:
	  lis       r3, 0x803D
	  addi      r31, r3, 0x41F0
	  b         .loc_0xC8

	.loc_0xA8:
	  lwz       r3, 0x3480(r13)
	  subi      r3, r3, 0x1
	  rlwinm    r0,r3,2,0,29
	  stw       r3, 0x3480(r13)
	  add       r3, r31, r0
	  lwz       r12, 0x0(r3)
	  mtlr      r12
	  blrl

	.loc_0xC8:
	  lwz       r0, 0x3480(r13)
	  cmpwi     r0, 0
	  bgt+      .loc_0xA8
	  bl        0x7A0
	  lwz       r12, 0x3488(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0xF4
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x3488(r13)

	.loc_0xF4:
	  bl        -0x17BA8
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void __atexit(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void atexit(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void abort(void)
{
	// UNUSED FUNCTION
}
