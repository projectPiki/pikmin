#include "types.h"

/*
 * --INFO--
 * Address:	8021C0B4
 * Size:	00005C
 */
void TRKInitializeEventQueue(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  addi      r31, r3, 0x42F0
	  addi      r3, r31, 0
	  bl        0x25C8
	  mr        r3, r31
	  bl        0x25C8
	  li        r3, 0
	  stw       r3, 0x4(r31)
	  li        r0, 0x100
	  stw       r3, 0x8(r31)
	  mr        r3, r31
	  stw       r0, 0x24(r31)
	  bl        0x25B4
	  li        r3, 0
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C110
 * Size:	000024
 */
void TRKCopyEvent(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0xC
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x218CBC
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C134
 * Size:	0000C0
 */
void TRKGetNextEvent(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0x42F0
	  stw       r30, 0x10(r1)
	  stw       r29, 0xC(r1)
	  li        r29, 0
	  stw       r28, 0x8(r1)
	  addi      r28, r3, 0
	  addi      r3, r31, 0
	  bl        0x253C
	  addi      r30, r31, 0x4
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0x90
	  addi      r29, r31, 0x8
	  lwz       r0, 0x8(r31)
	  addi      r3, r28, 0
	  mulli     r0, r0, 0xC
	  add       r4, r31, r0
	  addi      r4, r4, 0xC
	  bl        -0x80
	  lwz       r3, 0x0(r30)
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r29)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r29)
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x8C
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x8C:
	  li        r29, 0x1

	.loc_0x90:
	  lis       r3, 0x803D
	  addi      r3, r3, 0x42F0
	  bl        0x24DC
	  mr        r3, r29
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  lwz       r29, 0xC(r1)
	  lwz       r28, 0x8(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C1F4
 * Size:	0000E0
 */
void TRKPostEvent(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0x42F0
	  addi      r3, r30, 0
	  stw       r29, 0xC(r1)
	  stw       r28, 0x8(r1)
	  li        r28, 0
	  bl        0x247C
	  addi      r29, r30, 0x4
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0x2
	  bne-      .loc_0x4C
	  li        r28, 0x100
	  b         .loc_0xB0

	.loc_0x4C:
	  lwz       r0, 0x8(r30)
	  addi      r4, r31, 0
	  add       r0, r0, r3
	  srawi     r3, r0, 0x1
	  addze     r3, r3
	  rlwinm    r3,r3,1,0,30
	  subc      r3, r0, r3
	  mulli     r0, r3, 0xC
	  add       r31, r30, r0
	  addi      r3, r31, 0xC
	  bl        -0x158
	  addi      r4, r30, 0x24
	  lwz       r0, 0x24(r30)
	  stw       r0, 0x10(r31)
	  lwz       r3, 0x24(r30)
	  addi      r0, r3, 0x1
	  stw       r0, 0x24(r30)
	  lwz       r0, 0x24(r30)
	  cmplwi    r0, 0x100
	  bge-      .loc_0xA4
	  li        r0, 0x100
	  stw       r0, 0x0(r4)

	.loc_0xA4:
	  lwz       r3, 0x0(r29)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r29)

	.loc_0xB0:
	  lis       r3, 0x803D
	  addi      r3, r3, 0x42F0
	  bl        0x23FC
	  mr        r3, r28
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  lwz       r29, 0xC(r1)
	  lwz       r28, 0x8(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C2D4
 * Size:	000018
 */
void TRKConstructEvent(void)
{
	/*
	.loc_0x0:
	  stb       r4, 0x0(r3)
	  li        r4, 0
	  li        r0, -0x1
	  stw       r4, 0x4(r3)
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C2EC
 * Size:	000024
 */
void TRKDestructEvent(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x8(r3)
	  bl        0x318
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}
