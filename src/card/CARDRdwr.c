#include "types.h"

/*
 * --INFO--
 * Address:	80209214
 * Size:	0000DC
 */
void BlockReadCallback(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x803D
	  stw       r30, 0x18(r1)
	  mulli     r5, r31, 0x108
	  stw       r29, 0x14(r1)
	  addi      r0, r3, 0x3420
	  mr.       r29, r4
	  add       r30, r0, r5
	  blt-      .loc_0x80
	  lwz       r3, 0xB8(r30)
	  addi      r0, r3, 0x200
	  stw       r0, 0xB8(r30)
	  lwz       r3, 0xB0(r30)
	  addi      r0, r3, 0x200
	  stw       r0, 0xB0(r30)
	  lwz       r3, 0xB4(r30)
	  addi      r0, r3, 0x200
	  stw       r0, 0xB4(r30)
	  lwz       r3, 0xAC(r30)
	  subic.    r0, r3, 0x1
	  stw       r0, 0xAC(r30)
	  ble-      .loc_0x80
	  lis       r3, 0x8021
	  subi      r4, r3, 0x6DEC
	  addi      r3, r31, 0
	  bl        -0x7F8
	  mr.       r29, r3
	  bge-      .loc_0xC0

	.loc_0x80:
	  lwz       r0, 0xD0(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  bl        -0x388

	.loc_0x98:
	  lwz       r0, 0xD4(r30)
	  cmplwi    r0, 0
	  mr        r12, r0
	  beq-      .loc_0xC0
	  li        r0, 0
	  mtlr      r12
	  stw       r0, 0xD4(r30)
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  blrl

	.loc_0xC0:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	802092F0
 * Size:	000064
 */
void __CARDRead(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mulli     r9, r3, 0x108
	  stw       r0, 0x4(r1)
	  lis       r8, 0x803D
	  stwu      r1, -0x8(r1)
	  addi      r0, r8, 0x3420
	  add       r8, r0, r9
	  lwz       r0, 0x0(r8)
	  cmpwi     r0, 0
	  bne-      .loc_0x30
	  li        r3, -0x3
	  b         .loc_0x54

	.loc_0x30:
	  stw       r7, 0xD4(r8)
	  rlwinm    r0,r5,23,9,31
	  lis       r5, 0x8021
	  stw       r0, 0xAC(r8)
	  subi      r0, r5, 0x6DEC
	  stw       r4, 0xB0(r8)
	  mr        r4, r0
	  stw       r6, 0xB4(r8)
	  bl        -0x8B0

	.loc_0x54:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80209354
 * Size:	0000DC
 */
void BlockWriteCallback(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x803D
	  stw       r30, 0x18(r1)
	  mulli     r5, r31, 0x108
	  stw       r29, 0x14(r1)
	  addi      r0, r3, 0x3420
	  mr.       r29, r4
	  add       r30, r0, r5
	  blt-      .loc_0x80
	  lwz       r3, 0xB8(r30)
	  addi      r0, r3, 0x80
	  stw       r0, 0xB8(r30)
	  lwz       r3, 0xB0(r30)
	  addi      r0, r3, 0x80
	  stw       r0, 0xB0(r30)
	  lwz       r3, 0xB4(r30)
	  addi      r0, r3, 0x80
	  stw       r0, 0xB4(r30)
	  lwz       r3, 0xAC(r30)
	  subic.    r0, r3, 0x1
	  stw       r0, 0xAC(r30)
	  ble-      .loc_0x80
	  lis       r3, 0x8021
	  subi      r4, r3, 0x6CAC
	  addi      r3, r31, 0
	  bl        -0x800
	  mr.       r29, r3
	  bge-      .loc_0xC0

	.loc_0x80:
	  lwz       r0, 0xD0(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  bl        -0x4C8

	.loc_0x98:
	  lwz       r0, 0xD4(r30)
	  cmplwi    r0, 0
	  mr        r12, r0
	  beq-      .loc_0xC0
	  li        r0, 0
	  mtlr      r12
	  stw       r0, 0xD4(r30)
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  blrl

	.loc_0xC0:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80209430
 * Size:	000064
 */
void __CARDWrite(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mulli     r9, r3, 0x108
	  stw       r0, 0x4(r1)
	  lis       r8, 0x803D
	  stwu      r1, -0x8(r1)
	  addi      r0, r8, 0x3420
	  add       r8, r0, r9
	  lwz       r0, 0x0(r8)
	  cmpwi     r0, 0
	  bne-      .loc_0x30
	  li        r3, -0x3
	  b         .loc_0x54

	.loc_0x30:
	  stw       r7, 0xD4(r8)
	  rlwinm    r0,r5,25,7,31
	  lis       r5, 0x8021
	  stw       r0, 0xAC(r8)
	  subi      r0, r5, 0x6CAC
	  stw       r4, 0xB0(r8)
	  mr        r4, r0
	  stw       r6, 0xB4(r8)
	  bl        -0x8B8

	.loc_0x54:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80209494
 * Size:	000018
 */
void CARDGetXferredBytes(void)
{
	/*
	.loc_0x0:
	  mulli     r0, r3, 0x108
	  lis       r3, 0x803D
	  addi      r3, r3, 0x3420
	  add       r3, r3, r0
	  lwz       r3, 0xB8(r3)
	  blr
	*/
}
