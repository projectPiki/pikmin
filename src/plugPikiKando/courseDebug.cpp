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
 * Address:	........
 * Size:	00011C
 */
GenObjectDebug::GenObjectDebug()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800864A8
 * Size:	00012C
 */
void makeObjectDebug()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x58
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  bl        -0x3F4C0
	  mr.       r31, r3
	  beq-      .loc_0x10C
	  lis       r4, 0x802B
	  lis       r3, 0x802B
	  subi      r5, r4, 0x11AC
	  lis       r4, 0x6465
	  subi      r6, r3, 0x11A0
	  addi      r3, r31, 0
	  addi      r4, r4, 0x6267
	  bl        0x547C8
	  lis       r3, 0x802C
	  subi      r0, r3, 0x5490
	  lis       r3, 0x802B
	  stw       r0, 0x4(r31)
	  subi      r0, r3, 0x112C
	  stw       r0, 0x4(r31)
	  addi      r5, r1, 0x24
	  addi      r4, r31, 0
	  lwz       r0, -0x5ED0(r13)
	  addi      r3, r31, 0x18
	  stw       r0, 0x2C(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r0, 0x24(r1)
	  bl        -0x27AA4
	  lis       r3, 0x802A
	  addi      r29, r3, 0x60C4
	  stw       r29, 0x20(r31)
	  li        r30, 0
	  addi      r5, r1, 0x20
	  stw       r30, 0x24(r31)
	  mr        r4, r31
	  addi      r3, r31, 0x28
	  lwz       r0, -0x5ECC(r13)
	  stw       r0, 0x34(r1)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x20(r1)
	  bl        -0x27AD8
	  stw       r29, 0x30(r31)
	  addi      r5, r1, 0x1C
	  addi      r4, r31, 0
	  stw       r30, 0x34(r31)
	  addi      r3, r31, 0x38
	  lwz       r0, -0x5EC8(r13)
	  stw       r0, 0x3C(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x1C(r1)
	  bl        -0x27B00
	  stw       r29, 0x40(r31)
	  addi      r5, r1, 0x18
	  addi      r4, r31, 0
	  stw       r30, 0x44(r31)
	  addi      r3, r31, 0x48
	  lwz       r0, -0x5EC4(r13)
	  stw       r0, 0x44(r1)
	  lwz       r0, 0x44(r1)
	  stw       r0, 0x18(r1)
	  bl        -0x27B28
	  stw       r29, 0x50(r31)
	  stw       r30, 0x54(r31)

	.loc_0x10C:
	  mr        r3, r31
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800865D4
 * Size:	00008C
 */
void GenObjectDebug::initialise()
{
	/*
	.loc_0x0:
	  lwz       r7, 0x3074(r13)
	  lwz       r5, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  cmpw      r5, r0
	  bgelr-
	  lis       r4, 0x6465
	  lwz       r3, 0x8(r7)
	  addi      r4, r4, 0x6267
	  rlwinm    r0,r5,4,0,27
	  stwx      r4, r3, r0
	  lis       r6, 0x8008
	  lis       r4, 0x802B
	  lwz       r0, 0x0(r7)
	  lis       r3, 0x7630
	  lwz       r5, 0x8(r7)
	  addi      r6, r6, 0x64A8
	  rlwinm    r0,r0,4,0,27
	  add       r5, r5, r0
	  stw       r6, 0x4(r5)
	  subi      r5, r4, 0x11A0
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
 * Address:	80086660
 * Size:	000004
 */
void GenObjectDebug::doRead(RandomAccessStream&) { }

/*
 * --INFO--
 * Address:	80086664
 * Size:	000028
 */
void GenObjectDebug::birth(BirthInfo&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x24(r3)
	  stw       r0, 0x2FD8(r13)
	  lwz       r0, 0x34(r3)
	  stw       r0, 0x2FDC(r13)
	  lwz       r0, 0x44(r3)
	  stw       r0, 0x2FE0(r13)
	  lwz       r0, 0x54(r3)
	  li        r3, 0
	  stw       r0, 0x2FE4(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008668C
 * Size:	000004
 */
void GenObject::render(Graphics&, Generator*) { }
