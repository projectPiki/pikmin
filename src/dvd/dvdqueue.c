

/*
 * --INFO--
 * Address:	80201F04
 * Size:	000038
 */
void __DVDClearWaitingQueue(void)
{
/*
.loc_0x0:
  lis       r3, 0x803D
  addi      r3, r3, 0x31D8
  stw       r3, 0x0(r3)
  addi      r5, r3, 0x8
  addi      r4, r3, 0x10
  stw       r3, 0x4(r3)
  addi      r3, r3, 0x18
  stw       r5, 0x0(r5)
  stw       r5, 0x4(r5)
  stw       r4, 0x0(r4)
  stw       r4, 0x4(r4)
  stw       r3, 0x0(r3)
  stw       r3, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80201F3C
 * Size:	000068
 */
void __DVDPushWaitingQueue(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  bl        -0x8FDC
  lis       r4, 0x803D
  rlwinm    r5,r30,3,0,28
  addi      r0, r4, 0x31D8
  add       r5, r0, r5
  lwz       r4, 0x4(r5)
  stw       r31, 0x0(r4)
  lwz       r0, 0x4(r5)
  stw       r0, 0x4(r31)
  stw       r5, 0x0(r31)
  stw       r31, 0x4(r5)
  bl        -0x8FE0
  lwz       r0, 0x1C(r1)
  li        r3, 0x1
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void PopWaitingQueuePrio(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80201FA4
 * Size:	0000A0
 */
void __DVDPopWaitingQueue(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  bl        -0x9038
  li        r0, 0x4
  lis       r4, 0x803D
  mtctr     r0
  addi      r4, r4, 0x31D8
  li        r31, 0

.loc_0x28:
  lwz       r0, 0x0(r4)
  cmplw     r0, r4
  beq-      .loc_0x78
  bl        -0x9034
  bl        -0x9060
  lis       r4, 0x803D
  rlwinm    r5,r31,3,0,28
  addi      r0, r4, 0x31D8
  add       r5, r0, r5
  lwz       r31, 0x0(r5)
  lwz       r0, 0x0(r31)
  stw       r0, 0x0(r5)
  lwz       r4, 0x0(r31)
  stw       r5, 0x4(r4)
  bl        -0x9060
  li        r0, 0
  stw       r0, 0x0(r31)
  mr        r3, r31
  stw       r0, 0x4(r31)
  b         .loc_0x8C

.loc_0x78:
  addi      r4, r4, 0x8
  addi      r31, r31, 0x1
  bdnz+     .loc_0x28
  bl        -0x9084
  li        r3, 0

.loc_0x8C:
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80202044
 * Size:	000058
 */
void __DVDCheckWaitingQueue(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x90D4
  li        r0, 0x4
  lis       r4, 0x803D
  mtctr     r0
  addi      r4, r4, 0x31D8

.loc_0x20:
  lwz       r0, 0x0(r4)
  cmplw     r0, r4
  beq-      .loc_0x38
  bl        -0x90CC
  li        r3, 0x1
  b         .loc_0x48

.loc_0x38:
  addi      r4, r4, 0x8
  bdnz+     .loc_0x20
  bl        -0x90E0
  li        r3, 0

.loc_0x48:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8020209C
 * Size:	000060
 */
void __DVDDequeueWaitingQueue(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        -0x9134
  lwz       r4, 0x4(r31)
  lwz       r5, 0x0(r31)
  cmplwi    r4, 0
  beq-      .loc_0x30
  cmplwi    r5, 0
  bne-      .loc_0x3C

.loc_0x30:
  bl        -0x9128
  li        r3, 0
  b         .loc_0x4C

.loc_0x3C:
  stw       r5, 0x0(r4)
  stw       r4, 0x4(r5)
  bl        -0x913C
  li        r3, 0x1

.loc_0x4C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void __DVDIsBlockInWaitingQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void DVDDumpWaitingQueue(void)
{
	// UNUSED FUNCTION
}