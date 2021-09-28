

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void OSCheckAlarmQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SetTimer(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F60C0
 * Size:	00004C
 */
void OSInitAlarm(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x8
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x160
  lis       r4, 0x801F
  addi      r4, r4, 0x6760
  cmplw     r3, r4
  beq-      .loc_0x3C
  li        r0, 0
  addi      r3, r13, 0x31D8
  stw       r0, 0x4(r3)
  li        r3, 0x8
  stw       r0, 0x31D8(r13)
  bl        -0x1A4

.loc_0x3C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F610C
 * Size:	00000C
 */
void OSCreateAlarm(void)
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6118
 * Size:	000250
 */
void InsertAlarm(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stmw      r25, 0x24(r1)
  li        r28, 0
  mr        r29, r3
  xoris     r4, r28, 0x8000
  addi      r25, r5, 0
  addi      r30, r6, 0
  addi      r31, r7, 0
  lwz       r0, 0x18(r3)
  lwz       r8, 0x1C(r3)
  xoris     r3, r0, 0x8000
  subc      r0, r28, r8
  subfe     r3, r3, r4
  subfe     r3, r4, r4
  neg.      r3, r3
  beq-      .loc_0xC0
  bl        0x7240
  lwz       r7, 0x20(r29)
  xoris     r5, r3, 0x8000
  lwz       r8, 0x24(r29)
  xoris     r6, r7, 0x8000
  subc      r0, r8, r4
  subfe     r5, r5, r6
  subfe     r5, r6, r6
  neg.      r5, r5
  addi      r30, r8, 0
  addi      r25, r7, 0
  beq-      .loc_0xC0
  lwz       r27, 0x18(r29)
  subc      r4, r4, r8
  lwz       r26, 0x1C(r29)
  subfe     r3, r7, r3
  addi      r5, r27, 0
  addi      r6, r26, 0
  bl        0x1EE00
  li        r0, 0x1
  addc      r5, r4, r0
  mullw     r4, r27, r5
  mulhwu    r0, r26, r5
  adde      r3, r3, r28
  add       r4, r4, r0
  mullw     r0, r26, r3
  mullw     r3, r26, r5
  add       r0, r4, r0
  addc      r30, r30, r3
  adde      r25, r25, r0

.loc_0xC0:
  stw       r31, 0x0(r29)
  xoris     r4, r25, 0x8000
  stw       r30, 0xC(r29)
  stw       r25, 0x8(r29)
  lwz       r6, 0x31D8(r13)
  b         .loc_0x198

.loc_0xD8:
  lwz       r0, 0x8(r6)
  lwz       r5, 0xC(r6)
  xoris     r3, r0, 0x8000
  subc      r0, r30, r5
  subfe     r3, r3, r4
  subfe     r3, r4, r4
  neg.      r3, r3
  beq-      .loc_0x194
  lwz       r0, 0x10(r6)
  stw       r0, 0x10(r29)
  stw       r29, 0x10(r6)
  stw       r6, 0x14(r29)
  lwz       r3, 0x10(r29)
  cmplwi    r3, 0
  beq-      .loc_0x11C
  stw       r29, 0x14(r3)
  b         .loc_0x23C

.loc_0x11C:
  stw       r29, 0x31D8(r13)
  bl        0x7168
  lwz       r6, 0xC(r29)
  li        r7, 0
  lwz       r0, 0x8(r29)
  xoris     r5, r7, 0x8000
  subc      r8, r6, r4
  subfe     r0, r3, r0
  xoris     r6, r0, 0x8000
  subc      r0, r8, r7
  subfe     r5, r5, r6
  subfe     r5, r6, r6
  neg.      r5, r5
  beq-      .loc_0x160
  li        r3, 0
  bl        -0x904
  b         .loc_0x23C

.loc_0x160:
  lis       r4, 0x8000
  xoris     r3, r7, 0x8000
  subc      r0, r8, r4
  subfe     r3, r3, r6
  subfe     r3, r6, r6
  neg.      r3, r3
  beq-      .loc_0x188
  mr        r3, r8
  bl        -0x92C
  b         .loc_0x23C

.loc_0x188:
  subi      r3, r4, 0x1
  bl        -0x938
  b         .loc_0x23C

.loc_0x194:
  lwz       r6, 0x14(r6)

.loc_0x198:
  cmplwi    r6, 0
  bne+      .loc_0xD8
  li        r30, 0
  stw       r30, 0x14(r29)
  addi      r3, r13, 0x31D8
  lwz       r4, 0x4(r3)
  stwu      r29, 0x4(r3)
  cmplwi    r4, 0
  stw       r4, 0x10(r29)
  beq-      .loc_0x1C8
  stw       r29, 0x14(r4)
  b         .loc_0x23C

.loc_0x1C8:
  stw       r29, 0x0(r3)
  stw       r29, 0x31D8(r13)
  bl        0x70B8
  lwz       r6, 0xC(r29)
  xoris     r5, r30, 0x8000
  lwz       r0, 0x8(r29)
  subc      r7, r6, r4
  subfe     r0, r3, r0
  xoris     r6, r0, 0x8000
  subc      r0, r7, r30
  subfe     r5, r5, r6
  subfe     r5, r6, r6
  neg.      r5, r5
  beq-      .loc_0x20C
  li        r3, 0
  bl        -0x9B0
  b         .loc_0x23C

.loc_0x20C:
  lis       r4, 0x8000
  xoris     r3, r30, 0x8000
  subc      r0, r7, r4
  subfe     r3, r3, r6
  subfe     r3, r6, r6
  neg.      r3, r3
  beq-      .loc_0x234
  mr        r3, r7
  bl        -0x9D8
  b         .loc_0x23C

.loc_0x234:
  subi      r3, r4, 0x1
  bl        -0x9E4

.loc_0x23C:
  lmw       r25, 0x24(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F6368
 * Size:	000068
 */
void OSSetAlarm(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r27, 0x24(r1)
  addi      r27, r3, 0
  addi      r29, r5, 0
  addi      r28, r6, 0
  addi      r30, r7, 0
  bl        0x2BF4
  li        r0, 0
  stw       r0, 0x1C(r27)
  mr        r31, r3
  stw       r0, 0x18(r27)
  bl        0x7004
  addc      r6, r28, r4
  adde      r5, r29, r3
  addi      r3, r27, 0
  addi      r7, r30, 0
  bl        -0x298
  mr        r3, r31
  bl        0x2BEC
  lmw       r27, 0x24(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F63D0
 * Size:	000064
 */
void OSSetAbsAlarm(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r27, 0x24(r1)
  addi      r27, r3, 0
  addi      r29, r5, 0
  addi      r28, r6, 0
  addi      r30, r7, 0
  bl        0x2B8C
  li        r0, 0
  stw       r0, 0x1C(r27)
  mr        r31, r3
  addi      r3, r27, 0
  stw       r0, 0x18(r27)
  addi      r6, r28, 0
  addi      r5, r29, 0
  addi      r7, r30, 0
  bl        -0x2FC
  mr        r3, r31
  bl        0x2B88
  lmw       r27, 0x24(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void OSSetPeriodicAlarm(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F6434
 * Size:	00011C
 */
void OSCancelAlarm(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r3
  stw       r29, 0x14(r1)
  bl        0x2B2C
  lwz       r0, 0x0(r30)
  addi      r31, r3, 0
  cmplwi    r0, 0
  bne-      .loc_0x3C
  mr        r3, r31
  bl        0x2B3C
  b         .loc_0x100

.loc_0x3C:
  lwz       r29, 0x14(r30)
  cmplwi    r29, 0
  bne-      .loc_0x58
  lwz       r0, 0x10(r30)
  addi      r3, r13, 0x31D8
  stw       r0, 0x4(r3)
  b         .loc_0x60

.loc_0x58:
  lwz       r0, 0x10(r30)
  stw       r0, 0x10(r29)

.loc_0x60:
  lwz       r3, 0x10(r30)
  cmplwi    r3, 0
  beq-      .loc_0x74
  stw       r29, 0x14(r3)
  b         .loc_0xF0

.loc_0x74:
  cmplwi    r29, 0
  stw       r29, 0x31D8(r13)
  beq-      .loc_0xF0
  bl        0x6EEC
  lwz       r6, 0xC(r29)
  li        r7, 0
  lwz       r0, 0x8(r29)
  xoris     r5, r7, 0x8000
  subc      r8, r6, r4
  subfe     r0, r3, r0
  xoris     r6, r0, 0x8000
  subc      r0, r8, r7
  subfe     r5, r5, r6
  subfe     r5, r6, r6
  neg.      r5, r5
  beq-      .loc_0xC0
  li        r3, 0
  bl        -0xB80
  b         .loc_0xF0

.loc_0xC0:
  lis       r4, 0x8000
  xoris     r3, r7, 0x8000
  subc      r0, r8, r4
  subfe     r3, r3, r6
  subfe     r3, r6, r6
  neg.      r3, r3
  beq-      .loc_0xE8
  mr        r3, r8
  bl        -0xBA8
  b         .loc_0xF0

.loc_0xE8:
  subi      r3, r4, 0x1
  bl        -0xBB4

.loc_0xF0:
  li        r0, 0
  stw       r0, 0x0(r30)
  mr        r3, r31
  bl        0x2A74

.loc_0x100:
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
 * Address:	801F6550
 * Size:	000210
 */
void DecrementerExceptionCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  mr        r29, r4
  stw       r28, 0x18(r1)
  bl        0x6E30
  lwz       r0, 0x31D8(r13)
  addi      r28, r4, 0
  addi      r30, r3, 0
  cmplwi    r0, 0
  mr        r31, r0
  bne-      .loc_0x44
  mr        r3, r29
  bl        0xDCC

.loc_0x44:
  lwz       r0, 0x8(r31)
  xoris     r4, r30, 0x8000
  lwz       r5, 0xC(r31)
  xoris     r3, r0, 0x8000
  subc      r0, r28, r5
  subfe     r3, r3, r4
  subfe     r3, r4, r4
  neg.      r3, r3
  beq-      .loc_0xE0
  bl        0x6DE8
  lwz       r6, 0xC(r31)
  li        r7, 0
  lwz       r0, 0x8(r31)
  xoris     r5, r7, 0x8000
  subc      r8, r6, r4
  subfe     r0, r3, r0
  xoris     r6, r0, 0x8000
  subc      r0, r8, r7
  subfe     r5, r5, r6
  subfe     r5, r6, r6
  neg.      r5, r5
  beq-      .loc_0xA8
  li        r3, 0
  bl        -0xC84
  b         .loc_0xD8

.loc_0xA8:
  lis       r4, 0x8000
  xoris     r3, r7, 0x8000
  subc      r0, r8, r4
  subfe     r3, r3, r6
  subfe     r3, r6, r6
  neg.      r3, r3
  beq-      .loc_0xD0
  mr        r3, r8
  bl        -0xCAC
  b         .loc_0xD8

.loc_0xD0:
  subi      r3, r4, 0x1
  bl        -0xCB8

.loc_0xD8:
  mr        r3, r29
  bl        0xD30

.loc_0xE0:
  lwz       r3, 0x14(r31)
  cmplwi    r3, 0
  stw       r3, 0x31D8(r13)
  bne-      .loc_0x100
  li        r0, 0
  addi      r3, r13, 0x31D8
  stw       r0, 0x4(r3)
  b         .loc_0x108

.loc_0x100:
  li        r0, 0
  stw       r0, 0x10(r3)

.loc_0x108:
  lwz       r30, 0x0(r31)
  li        r6, 0
  xoris     r4, r6, 0x8000
  stw       r6, 0x0(r31)
  lwz       r0, 0x18(r31)
  lwz       r5, 0x1C(r31)
  xoris     r3, r0, 0x8000
  subc      r0, r6, r5
  subfe     r3, r3, r4
  subfe     r3, r4, r4
  neg.      r3, r3
  beq-      .loc_0x14C
  addi      r3, r31, 0
  addi      r7, r30, 0
  li        r6, 0
  li        r5, 0
  bl        -0x580

.loc_0x14C:
  lwz       r28, 0x31D8(r13)
  cmplwi    r28, 0
  beq-      .loc_0x1C8
  bl        0x6CF8
  lwz       r6, 0xC(r28)
  li        r7, 0
  lwz       r0, 0x8(r28)
  xoris     r5, r7, 0x8000
  subc      r8, r6, r4
  subfe     r0, r3, r0
  xoris     r6, r0, 0x8000
  subc      r0, r8, r7
  subfe     r5, r5, r6
  subfe     r5, r6, r6
  neg.      r5, r5
  beq-      .loc_0x198
  li        r3, 0
  bl        -0xD74
  b         .loc_0x1C8

.loc_0x198:
  lis       r4, 0x8000
  xoris     r3, r7, 0x8000
  subc      r0, r8, r4
  subfe     r3, r3, r6
  subfe     r3, r6, r6
  neg.      r3, r3
  beq-      .loc_0x1C0
  mr        r3, r8
  bl        -0xD9C
  b         .loc_0x1C8

.loc_0x1C0:
  subi      r3, r4, 0x1
  bl        -0xDA8

.loc_0x1C8:
  bl        0x540C
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r31, 0
  addi      r4, r29, 0
  blrl      
  bl        0x5434
  bl        0x5924
  mr        r3, r29
  bl        0xC20
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
 * Address:	801F6760
 * Size:	00004C
 */
void DecrementerExceptionHandler(void)
{
/*
.loc_0x0:
  stw       r0, 0x0(r4)
  stw       r1, 0x4(r4)
  stw       r2, 0x8(r4)
  stmw      r6, 0x18(r4)
  mfspr     r0, 0x391
  stw       r0, 0x1A8(r4)
  mfspr     r0, 0x392
  stw       r0, 0x1AC(r4)
  mfspr     r0, 0x393
  stw       r0, 0x1B0(r4)
  mfspr     r0, 0x394
  stw       r0, 0x1B4(r4)
  mfspr     r0, 0x395
  stw       r0, 0x1B8(r4)
  mfspr     r0, 0x396
  stw       r0, 0x1BC(r4)
  mfspr     r0, 0x397
  stw       r0, 0x1C0(r4)
  b         -0x258
*/
}