#include "types.h"

/*
 * --INFO--
 * Address:	801FD7C4
 * Size:	000048
 */
void InitializeUART(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x7E28
	  rlwinm.   r0,r3,0,3,3
	  bne-      .loc_0x28
	  li        r0, 0
	  stw       r0, 0x3240(r13)
	  li        r3, 0x2
	  b         .loc_0x38

	.loc_0x28:
	  lis       r3, 0xA5FF
	  addi      r0, r3, 0x5A
	  stw       r0, 0x3240(r13)
	  li        r3, 0

	.loc_0x38:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801FD80C
 * Size:	000008
 */
u32 ReadUARTN(void) { return 0x4; }

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void QueueLength(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FD814
 * Size:	000200
 */
void WriteUARTN(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r26, 0x18(r1)
	  addi      r26, r3, 0
	  addi      r27, r4, 0
	  lwz       r5, 0x3240(r13)
	  addis     r0, r5, 0x5A01
	  cmplwi    r0, 0x5A
	  beq-      .loc_0x30
	  li        r3, 0x2
	  b         .loc_0x1EC

	.loc_0x30:
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0
	  bl        -0x4B14
	  cmpwi     r3, 0
	  bne-      .loc_0x50
	  li        r3, 0
	  b         .loc_0x1EC

	.loc_0x50:
	  addi      r4, r26, 0
	  li        r3, 0xD
	  b         .loc_0x70

	.loc_0x5C:
	  lbz       r0, 0x0(r4)
	  cmplwi    r0, 0xA
	  bne-      .loc_0x6C
	  stb       r3, 0x0(r4)

	.loc_0x6C:
	  addi      r4, r4, 0x1

	.loc_0x70:
	  sub       r0, r4, r26
	  cmplw     r0, r27
	  blt+      .loc_0x5C
	  lis       r0, 0xA001
	  stw       r0, 0x14(r1)
	  li        r28, 0
	  lis       r31, 0x2001
	  b         .loc_0x1D8

	.loc_0x90:
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0x3
	  bl        -0x51D4
	  cmpwi     r3, 0
	  bne-      .loc_0xB0
	  li        r0, -0x1
	  b         .loc_0x108

	.loc_0xB0:
	  stw       r31, 0x10(r1)
	  addi      r4, r1, 0x10
	  li        r3, 0
	  li        r5, 0x4
	  li        r6, 0x1
	  li        r7, 0
	  bl        -0x5C1C
	  li        r3, 0
	  bl        -0x583C
	  addi      r4, r1, 0x10
	  li        r3, 0
	  li        r5, 0x1
	  li        r6, 0
	  li        r7, 0
	  bl        -0x5C3C
	  li        r3, 0
	  bl        -0x585C
	  li        r3, 0
	  bl        -0x5104
	  lwz       r0, 0x10(r1)
	  rlwinm    r0,r0,8,24,31
	  subfic    r0, r0, 0x10

	.loc_0x108:
	  cmpwi     r0, 0
	  mr        r29, r0
	  bge-      .loc_0x11C
	  li        r28, -0x1
	  b         .loc_0x1E0

	.loc_0x11C:
	  cmpwi     r0, 0xC
	  bge-      .loc_0x12C
	  cmplw     r0, r27
	  blt-      .loc_0x1D8

	.loc_0x12C:
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0x3
	  bl        -0x5270
	  cmpwi     r3, 0
	  bne-      .loc_0x14C
	  li        r28, -0x1
	  b         .loc_0x1E0

	.loc_0x14C:
	  addi      r4, r1, 0x14
	  li        r3, 0
	  li        r5, 0x4
	  li        r6, 0x1
	  li        r7, 0
	  bl        -0x5CB4
	  li        r3, 0
	  bl        -0x58D4
	  b         .loc_0x1C0

	.loc_0x170:
	  cmpwi     r29, 0x4
	  bge-      .loc_0x180
	  cmplw     r29, r27
	  blt-      .loc_0x1D0

	.loc_0x180:
	  cmplwi    r27, 0x4
	  bge-      .loc_0x190
	  mr        r30, r27
	  b         .loc_0x194

	.loc_0x190:
	  li        r30, 0x4

	.loc_0x194:
	  addi      r5, r30, 0
	  addi      r4, r26, 0
	  li        r3, 0
	  li        r6, 0x1
	  li        r7, 0
	  bl        -0x5CFC
	  add       r26, r26, r30
	  sub       r27, r27, r30
	  sub       r29, r29, r30
	  li        r3, 0
	  bl        -0x5928

	.loc_0x1C0:
	  cmpwi     r29, 0
	  beq-      .loc_0x1D0
	  cmplwi    r27, 0
	  bne+      .loc_0x170

	.loc_0x1D0:
	  li        r3, 0
	  bl        -0x51E0

	.loc_0x1D8:
	  cmplwi    r27, 0
	  bne+      .loc_0x90

	.loc_0x1E0:
	  li        r3, 0
	  bl        -0x4BC8
	  mr        r3, r28

	.loc_0x1EC:
	  lmw       r26, 0x18(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
