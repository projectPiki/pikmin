#include "types.h"

typedef struct Jac_MessageQueue Jac_MessageQueue;

/*
 * --INFO--
 * Address:	80008160
 * Size:	000018
 */
void Jac_InitMessageQueue(Jac_MessageQueue*, void**, s32)
{
	/*
	.loc_0x0:
	  stw       r4, 0x10(r3)
	  li        r0, 0
	  stw       r5, 0x14(r3)
	  stw       r0, 0x18(r3)
	  stw       r0, 0x1C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void Jac_SendMessageBlock(Jac_MessageQueue*, void*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80008180
 * Size:	000080
 */
void Jac_SendMessage(Jac_MessageQueue*, void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  bl        0x1F0DE4
	  b         .loc_0x2C

	.loc_0x20:
	  bl        0x1F0E04
	  li        r3, 0
	  b         .loc_0x6C

	.loc_0x2C:
	  lwz       r4, 0x14(r30)
	  lwz       r6, 0x1C(r30)
	  cmpw      r4, r6
	  ble+      .loc_0x20
	  lwz       r0, 0x18(r30)
	  subi      r4, r4, 0x1
	  lwz       r5, 0x10(r30)
	  add       r0, r0, r6
	  and       r0, r4, r0
	  rlwinm    r0,r0,2,0,29
	  stwx      r31, r5, r0
	  lwz       r4, 0x1C(r30)
	  addi      r0, r4, 0x1
	  stw       r0, 0x1C(r30)
	  bl        0x1F0DC0
	  li        r3, 0x1

	.loc_0x6C:
	  lwz       r0, 0x24(r1)
	  lmw       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008200
 * Size:	000058
 */
void Jac_ReceiveMessage(Jac_MessageQueue*, void**)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  addi      r31, r3, 0
	  addi      r30, r4, 0
	  bl        0x1F0D64
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  mr        r31, r0
	  addi      r4, r30, 0
	  bl        0x34
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  mr        r31, r0
	  bl        0x1F0D68
	  mr        r3, r31
	  lmw       r30, 0x10(r1)
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008260
 * Size:	000060
 */
void Jac_ReceiveMessage_Fast(Jac_MessageQueue*, void**)
{
	/*
	.loc_0x0:
	  b         .loc_0xC

	.loc_0x4:
	  li        r3, 0
	  blr

	.loc_0xC:
	  lwz       r0, 0x1C(r3)
	  cmpwi     r0, 0
	  beq+      .loc_0x4
	  cmplwi    r4, 0
	  beq-      .loc_0x34
	  lwz       r0, 0x18(r3)
	  lwz       r5, 0x10(r3)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r5, r0
	  stw       r0, 0x0(r4)

	.loc_0x34:
	  lwz       r5, 0x18(r3)
	  lwz       r4, 0x14(r3)
	  addi      r5, r5, 0x1
	  subi      r0, r4, 0x1
	  and       r0, r5, r0
	  stw       r0, 0x18(r3)
	  lwz       r4, 0x1C(r3)
	  subi      r0, r4, 0x1
	  stw       r0, 0x1C(r3)
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void Jac_JamMessage(Jac_MessageQueue*, void*)
{
	// UNUSED FUNCTION
}
