#include "zen/particle.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A0F24
 * Size:	000158
 */
u8* zen::particleLoader::load(char*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x5F62
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r27, 0x2C(r1)
	  mr        r31, r3
	  addi      r27, r5, 0
	  addi      r30, r4, 0
	  addi      r5, r6, 0x696E
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x161ED4
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  lwz       r3, 0x20(r3)
	  b         .loc_0x144

	.loc_0x3C:
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        .loc_0x158
	  mr.       r29, r3
	  bne-      .loc_0x140
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r30, 0
	  addi      r5, r27, 0
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x1
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r28, r3
	  beq-      .loc_0x140
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r3, 0
	  li        r3, 0x14
	  bl        -0x159FB4
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0xE0
	  lis       r3, 0x802D
	  addi      r0, r3, 0x68DC
	  stw       r0, 0x0(r29)
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5898
	  stw       r29, 0x8(r29)
	  mr        r3, r30
	  stw       r29, 0x4(r29)
	  stw       r0, 0x0(r29)
	  bl        -0x160CAC
	  stw       r3, 0xC(r29)
	  addi      r3, r27, 0
	  li        r4, 0x20
	  bl        -0x159E94
	  stw       r3, 0x10(r29)

	.loc_0xE0:
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  mr        r4, r29
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r29, 0x10(r29)
	  lwz       r12, 0x4(r28)
	  addi      r5, r27, 0
	  addi      r4, r29, 0
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x140:
	  mr        r3, r29

	.loc_0x144:
	  lmw       r27, 0x2C(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr

	.loc_0x158:
	*/
}

/*
 * --INFO--
 * Address:	801A107C
 * Size:	000084
 */
u8* zen::particleLoader::pmFind(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  li        r30, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x20(r1)
	  mr        r28, r3
	  lwz       r3, 0x0(r3)
	  lwz       r31, 0x8(r3)
	  b         .loc_0x54

	.loc_0x34:
	  lwz       r3, 0xC(r31)
	  mr        r4, r29
	  bl        0x7810C
	  cmpwi     r3, 0
	  bne-      .loc_0x50
	  lwz       r30, 0x10(r31)
	  b         .loc_0x60

	.loc_0x50:
	  lwz       r31, 0x8(r31)

	.loc_0x54:
	  lwz       r0, 0x0(r28)
	  cmplw     r31, r0
	  bne+      .loc_0x34

	.loc_0x60:
	  mr        r3, r30
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
