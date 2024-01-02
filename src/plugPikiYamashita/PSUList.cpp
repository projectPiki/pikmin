#include "types.h"

/*
 * --INFO--
 * Address:	801B33C8
 * Size:	000018
 */
PSUPtrLink::PSUPtrLink(void*)
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x4(r3)
	  stw       r4, 0x0(r3)
	  stw       r0, 0x8(r3)
	  stw       r0, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B33E0
 * Size:	000060
 */
PSUPtrLink::~PSUPtrLink()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x44
	  lwz       r3, 0x4(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  mr        r4, r30
	  bl        0x168

	.loc_0x34:
	  extsh.    r0, r31
	  ble-      .loc_0x44
	  mr        r3, r30
	  bl        -0x16C274

	.loc_0x44:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
PSUPtrList::PSUPtrList(bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B3440
 * Size:	000068
 */
PSUPtrList::~PSUPtrList()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x50
	  lwz       r5, 0x0(r31)
	  li        r6, 0
	  li        r3, 0
	  b         .loc_0x34

	.loc_0x28:
	  stw       r3, 0x4(r5)
	  addi      r6, r6, 0x1
	  lwz       r5, 0xC(r5)

	.loc_0x34:
	  lwz       r0, 0x8(r31)
	  cmplw     r6, r0
	  blt+      .loc_0x28
	  extsh.    r0, r4
	  ble-      .loc_0x50
	  mr        r3, r31
	  bl        -0x16C2E0

	.loc_0x50:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B34A8
 * Size:	000014
 */
void PSUPtrList::initiate()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  stw       r0, 0x4(r3)
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void PSUPtrList::setFirst(PSUPtrLink*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B34BC
 * Size:	0000BC
 */
void PSUPtrList::append(PSUPtrLink*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lwz       r4, 0x4(r4)
	  neg       r0, r4
	  cntlzw    r0, r0
	  cmplwi    r4, 0
	  rlwinm    r3,r0,27,5,31
	  beq-      .loc_0x40
	  addi      r3, r4, 0
	  addi      r4, r31, 0
	  bl        .loc_0xBC

	.loc_0x40:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA4
	  lwz       r0, 0x8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x78
	  stw       r30, 0x4(r31)
	  li        r4, 0
	  li        r0, 0x1
	  stw       r4, 0x8(r31)
	  stw       r4, 0xC(r31)
	  stw       r31, 0x4(r30)
	  stw       r31, 0x0(r30)
	  stw       r0, 0x8(r30)
	  b         .loc_0xA4

	.loc_0x78:
	  stw       r30, 0x4(r31)
	  li        r0, 0
	  lwz       r4, 0x4(r30)
	  stw       r4, 0x8(r31)
	  stw       r0, 0xC(r31)
	  lwz       r4, 0x4(r30)
	  stw       r31, 0xC(r4)
	  stw       r31, 0x4(r30)
	  lwz       r4, 0x8(r30)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r30)

	.loc_0xA4:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0xBC:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void PSUPtrList::prepend(PSUPtrLink*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001DC
 */
void PSUPtrList::insert(PSUPtrLink*, PSUPtrLink*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B3578
 * Size:	0000B0
 */
void PSUPtrList::remove(PSUPtrLink*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r4)
	  sub       r0, r3, r5
	  cntlzw    r0, r0
	  cmplw     r5, r3
	  rlwinm    r6,r0,27,5,31
	  bne-      .loc_0xA8
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x34
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  stw       r0, 0x4(r3)
	  b         .loc_0x94

	.loc_0x34:
	  lwz       r0, 0x0(r3)
	  cmplw     r4, r0
	  bne-      .loc_0x58
	  lwz       r5, 0xC(r4)
	  li        r0, 0
	  stw       r0, 0x8(r5)
	  lwz       r0, 0xC(r4)
	  stw       r0, 0x0(r3)
	  b         .loc_0x94

	.loc_0x58:
	  lwz       r0, 0x4(r3)
	  cmplw     r4, r0
	  bne-      .loc_0x7C
	  lwz       r5, 0x8(r4)
	  li        r0, 0
	  stw       r0, 0xC(r5)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x4(r3)
	  b         .loc_0x94

	.loc_0x7C:
	  lwz       r0, 0xC(r4)
	  lwz       r5, 0x8(r4)
	  stw       r0, 0xC(r5)
	  lwz       r0, 0x8(r4)
	  lwz       r5, 0xC(r4)
	  stw       r0, 0x8(r5)

	.loc_0x94:
	  li        r0, 0
	  stw       r0, 0x4(r4)
	  lwz       r4, 0x8(r3)
	  subi      r0, r4, 0x1
	  stw       r0, 0x8(r3)

	.loc_0xA8:
	  mr        r3, r6
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void PSUPtrList::getNthLink(u32) const
{
	// UNUSED FUNCTION
}
