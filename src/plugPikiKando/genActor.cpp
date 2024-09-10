#include "types.h"

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
 * Address:	80119B30
 * Size:	000078
 */
void makeObjectActor()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x1C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  bl        -0xD2B40
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x60
	  lis       r4, 0x802C
	  lis       r5, 0x802C
	  addi      r6, r4, 0x37E8
	  lis       r4, 0x6163
	  addi      r5, r5, 0x37DC
	  addi      r4, r4, 0x7472
	  bl        -0x3EEB8
	  lis       r3, 0x802C
	  subi      r0, r3, 0x5490
	  lis       r3, 0x802C
	  stw       r0, 0x4(r31)
	  addi      r0, r3, 0x386C
	  stw       r0, 0x4(r31)
	  li        r0, 0
	  stw       r0, 0x18(r31)

	.loc_0x60:
	  mr        r3, r31
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80119BA8
 * Size:	00008C
 */
void GenObjectActor::initialise()
{
	/*
	.loc_0x0:
	  lwz       r7, 0x3074(r13)
	  lwz       r5, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  cmpw      r5, r0
	  bgelr-
	  lis       r4, 0x6163
	  lwz       r3, 0x8(r7)
	  addi      r4, r4, 0x7472
	  rlwinm    r0,r5,4,0,27
	  stwx      r4, r3, r0
	  lis       r6, 0x8012
	  lis       r4, 0x802C
	  lwz       r0, 0x0(r7)
	  lis       r3, 0x7630
	  lwz       r5, 0x8(r7)
	  subi      r6, r6, 0x64D0
	  rlwinm    r0,r0,4,0,27
	  add       r5, r5, r0
	  stw       r6, 0x4(r5)
	  addi      r5, r4, 0x37F8
	  addi      r4, r3, 0x2E30
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r5, 0x8(r3)
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x0(r7)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r7)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80119C34
 * Size:	000040
 */
void GenObjectActor::doRead(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x4(r4)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x18(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80119C74
 * Size:	000070
 */
void GenObjectActor::birth(BirthInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  li        r4, 0
	  lwz       r3, 0x3130(r13)
	  bl        -0x1E0
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
