#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void __init_uart_console(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021A510
 * Size:	000008
 */
u32 __close_console(void) { return 0x0; }

/*
 * --INFO--
 * Address:	8021A518
 * Size:	000098
 */
void __write_console(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  lwz       r0, 0x3498(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x48
	  lis       r3, 0x1
	  subi      r3, r3, 0x1F00
	  bl        -0x1CD88
	  cmpwi     r3, 0
	  bne-      .loc_0x48
	  li        r0, 0x1
	  stw       r0, 0x3498(r13)

	.loc_0x48:
	  cmpwi     r3, 0
	  beq-      .loc_0x58
	  li        r3, 0x1
	  b         .loc_0x80

	.loc_0x58:
	  mr        r3, r30
	  lwz       r4, 0x0(r31)
	  bl        -0x1CD64
	  cmpwi     r3, 0
	  beq-      .loc_0x7C
	  li        r0, 0
	  stw       r0, 0x0(r31)
	  li        r3, 0x1
	  b         .loc_0x80

	.loc_0x7C:
	  li        r3, 0

	.loc_0x80:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  mtlr      r0
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021A5B0
 * Size:	0000E0
 */
void __read_console(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r4, 0
	  lwz       r0, 0x3498(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x4C
	  lis       r3, 0x1
	  subi      r3, r3, 0x1F00
	  bl        -0x1CE24
	  cmpwi     r3, 0
	  bne-      .loc_0x4C
	  li        r0, 0x1
	  stw       r0, 0x3498(r13)

	.loc_0x4C:
	  cmpwi     r3, 0
	  beq-      .loc_0x5C
	  li        r3, 0x1
	  b         .loc_0xC4

	.loc_0x5C:
	  lwz       r31, 0x0(r30)
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x0(r30)
	  b         .loc_0x98

	.loc_0x70:
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0x1CE1C
	  lwz       r4, 0x0(r30)
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r30)
	  lbz       r0, 0x0(r29)
	  cmplwi    r0, 0xD
	  beq-      .loc_0xAC
	  addi      r29, r29, 0x1

	.loc_0x98:
	  lwz       r0, 0x0(r30)
	  cmplw     r0, r31
	  bgt-      .loc_0xAC
	  cmpwi     r3, 0
	  beq+      .loc_0x70

	.loc_0xAC:
	  cmpwi     r3, 0
	  bne-      .loc_0xBC
	  li        r0, 0
	  b         .loc_0xC0

	.loc_0xBC:
	  li        r0, 0x1

	.loc_0xC0:
	  rlwinm    r3,r0,0,24,31

	.loc_0xC4:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  mtlr      r0
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  blr
	*/
}
