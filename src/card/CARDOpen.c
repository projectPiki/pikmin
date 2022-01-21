#include "types.h"

/*
 * --INFO--
 * Address:	8020BA80
 * Size:	000068
 */
void __CARDCompareFileName(void)
{
	/*
	.loc_0x0:
	  addi      r5, r3, 0x8
	  li        r7, 0x20
	  b         .loc_0x44

	.loc_0xC:
	  lbz       r0, 0x0(r5)
	  addi      r5, r5, 0x1
	  lbz       r6, 0x0(r4)
	  addi      r4, r4, 0x1
	  extsb     r3, r0
	  extsb     r0, r6
	  cmpw      r3, r0
	  beq-      .loc_0x34
	  li        r3, 0
	  blr

	.loc_0x34:
	  extsb.    r0, r6
	  bne-      .loc_0x44
	  li        r3, 0x1
	  blr

	.loc_0x44:
	  subic.    r7, r7, 0x1
	  bge+      .loc_0xC
	  lbz       r0, 0x0(r4)
	  extsb.    r0, r0
	  bne-      .loc_0x60
	  li        r3, 0x1
	  blr

	.loc_0x60:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020BAE8
 * Size:	00008C
 */
void __CARDAccess(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0xFF
	  bne-      .loc_0x28
	  li        r3, -0x4
	  b         .loc_0x78

	.loc_0x28:
	  lis       r3, 0x803D
	  lwz       r4, 0x3408(r13)
	  addi      r0, r3, 0x3630
	  cmplw     r4, r0
	  beq-      .loc_0x6C
	  addi      r3, r31, 0
	  li        r5, 0x4
	  bl        0xA640
	  cmpwi     r3, 0
	  bne-      .loc_0x74
	  lwz       r4, 0x3408(r13)
	  addi      r3, r31, 0x4
	  li        r5, 0x2
	  addi      r4, r4, 0x4
	  bl        0xA624
	  cmpwi     r3, 0
	  bne-      .loc_0x74

	.loc_0x6C:
	  li        r3, 0
	  b         .loc_0x78

	.loc_0x74:
	  li        r3, -0xA

	.loc_0x78:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020BB74
 * Size:	000030
 */
void __CARDIsPublic(void)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0xFF
	  bne-      .loc_0x14
	  li        r3, -0x4
	  blr

	.loc_0x14:
	  lbz       r0, 0x34(r3)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x28
	  li        r3, 0
	  blr

	.loc_0x28:
	  li        r3, -0xA
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
void __CARDGetFileNo(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020BBA4
 * Size:	000174
 */
void CARDFastOpen(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x1C(r1)
	  mr.       r29, r4
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  blt-      .loc_0x34
	  cmpwi     r29, 0x7F
	  blt-      .loc_0x3C

	.loc_0x34:
	  li        r3, -0x80
	  b         .loc_0x154

	.loc_0x3C:
	  li        r0, -0x1
	  stw       r0, 0x0(r30)
	  addi      r3, r28, 0
	  addi      r4, r1, 0x14
	  bl        -0x2D80
	  cmpwi     r3, 0
	  bge-      .loc_0x5C
	  b         .loc_0x154

	.loc_0x5C:
	  lwz       r3, 0x14(r1)
	  bl        -0x2354
	  rlwinm    r0,r29,6,0,25
	  add       r3, r3, r0
	  lbz       r0, 0x0(r3)
	  addi      r31, r3, 0
	  cmplwi    r0, 0xFF
	  bne-      .loc_0x84
	  li        r4, -0x4
	  b         .loc_0xD4

	.loc_0x84:
	  lis       r3, 0x803D
	  lwz       r4, 0x3408(r13)
	  addi      r0, r3, 0x3630
	  cmplw     r4, r0
	  beq-      .loc_0xC8
	  addi      r3, r31, 0
	  li        r5, 0x4
	  bl        0xA528
	  cmpwi     r3, 0
	  bne-      .loc_0xD0
	  lwz       r4, 0x3408(r13)
	  addi      r3, r31, 0x4
	  li        r5, 0x2
	  addi      r4, r4, 0x4
	  bl        0xA50C
	  cmpwi     r3, 0
	  bne-      .loc_0xD0

	.loc_0xC8:
	  li        r4, 0
	  b         .loc_0xD4

	.loc_0xD0:
	  li        r4, -0xA

	.loc_0xD4:
	  cmpwi     r4, -0xA
	  bne-      .loc_0x108
	  lbz       r0, 0x0(r31)
	  cmplwi    r0, 0xFF
	  bne-      .loc_0xF0
	  li        r4, -0x4
	  b         .loc_0x108

	.loc_0xF0:
	  lbz       r0, 0x34(r31)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x104
	  li        r4, 0
	  b         .loc_0x108

	.loc_0x104:
	  li        r4, -0xA

	.loc_0x108:
	  cmpwi     r4, 0
	  blt-      .loc_0x14C
	  lhz       r5, 0x36(r31)
	  cmplwi    r5, 0x5
	  blt-      .loc_0x12C
	  lwz       r3, 0x14(r1)
	  lhz       r0, 0x10(r3)
	  cmplw     r5, r0
	  blt-      .loc_0x134

	.loc_0x12C:
	  li        r4, -0x6
	  b         .loc_0x14C

	.loc_0x134:
	  stw       r28, 0x0(r30)
	  li        r0, 0
	  stw       r29, 0x4(r30)
	  stw       r0, 0x8(r30)
	  lhz       r0, 0x36(r31)
	  sth       r0, 0x10(r30)

	.loc_0x14C:
	  lwz       r3, 0x14(r1)
	  bl        -0x2DD4

	.loc_0x154:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  mtlr      r0
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020BD18
 * Size:	000174
 */
void CARDOpen(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, -0x1
	  stwu      r1, -0x38(r1)
	  stmw      r24, 0x18(r1)
	  addi      r29, r4, 0
	  addi      r30, r5, 0
	  addi      r28, r3, 0
	  addi      r4, r1, 0x14
	  stw       r0, 0x0(r5)
	  bl        -0x2ED0
	  cmpwi     r3, 0
	  bge-      .loc_0x38
	  b         .loc_0x160

	.loc_0x38:
	  lwz       r3, 0x14(r1)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x50
	  li        r24, -0x3
	  b         .loc_0x100

	.loc_0x50:
	  bl        -0x24B8
	  lis       r4, 0x803D
	  addi      r24, r3, 0
	  addi      r27, r4, 0x3630
	  li        r26, 0

	.loc_0x64:
	  lbz       r0, 0x0(r24)
	  addi      r25, r24, 0
	  cmplwi    r0, 0xFF
	  bne-      .loc_0x7C
	  li        r0, -0x4
	  b         .loc_0xC4

	.loc_0x7C:
	  lwz       r4, 0x3408(r13)
	  cmplw     r4, r27
	  beq-      .loc_0xB8
	  addi      r3, r25, 0
	  li        r5, 0x4
	  bl        0xA3C4
	  cmpwi     r3, 0
	  bne-      .loc_0xC0
	  lwz       r4, 0x3408(r13)
	  addi      r3, r25, 0x4
	  li        r5, 0x2
	  addi      r4, r4, 0x4
	  bl        0xA3A8
	  cmpwi     r3, 0
	  bne-      .loc_0xC0

	.loc_0xB8:
	  li        r0, 0
	  b         .loc_0xC4

	.loc_0xC0:
	  li        r0, -0xA

	.loc_0xC4:
	  cmpwi     r0, 0
	  blt-      .loc_0xEC
	  addi      r3, r24, 0
	  addi      r4, r29, 0
	  bl        -0x36C
	  cmpwi     r3, 0
	  beq-      .loc_0xEC
	  addi      r31, r26, 0
	  li        r24, 0
	  b         .loc_0x100

	.loc_0xEC:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x7F
	  addi      r24, r24, 0x40
	  blt+      .loc_0x64
	  li        r24, -0x4

	.loc_0x100:
	  cmpwi     r24, 0
	  blt-      .loc_0x154
	  lwz       r3, 0x14(r1)
	  bl        -0x2574
	  rlwinm    r0,r31,6,0,25
	  add       r5, r3, r0
	  lhz       r4, 0x36(r5)
	  cmplwi    r4, 0x5
	  blt-      .loc_0x134
	  lwz       r3, 0x14(r1)
	  lhz       r0, 0x10(r3)
	  cmplw     r4, r0
	  blt-      .loc_0x13C

	.loc_0x134:
	  li        r24, -0x6
	  b         .loc_0x154

	.loc_0x13C:
	  stw       r28, 0x0(r30)
	  li        r0, 0
	  stw       r31, 0x4(r30)
	  stw       r0, 0x8(r30)
	  lhz       r0, 0x36(r5)
	  sth       r0, 0x10(r30)

	.loc_0x154:
	  lwz       r3, 0x14(r1)
	  mr        r4, r24
	  bl        -0x2F54

	.loc_0x160:
	  lmw       r24, 0x18(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020BE8C
 * Size:	000054
 */
void CARDClose(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  addi      r4, r1, 0xC
	  lwz       r3, 0x0(r3)
	  bl        -0x3038
	  cmpwi     r3, 0
	  bge-      .loc_0x2C
	  b         .loc_0x40

	.loc_0x2C:
	  li        r0, -0x1
	  stw       r0, 0x0(r31)
	  li        r4, 0
	  lwz       r3, 0xC(r1)
	  bl        -0x2FA8

	.loc_0x40:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8020BEE0
 * Size:	000008
 */
u32 __CARDIsOpened(void) { return 0x0; }
