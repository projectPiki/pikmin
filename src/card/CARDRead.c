

/*
 * --INFO--
 * Address:	8020C278
 * Size:	0001B8
 */
void __CARDSeek(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r6, 0
  stw       r30, 0x28(r1)
  addi      r30, r5, 0
  stw       r29, 0x24(r1)
  addi      r29, r4, 0
  addi      r4, r1, 0x18
  stw       r28, 0x20(r1)
  mr        r28, r3
  lwz       r3, 0x0(r3)
  bl        -0x343C
  cmpwi     r3, 0
  bge-      .loc_0x44
  b         .loc_0x198

.loc_0x44:
  lhz       r0, 0x10(r28)
  cmplwi    r0, 0x5
  blt-      .loc_0x74
  lwz       r3, 0x18(r1)
  lhz       r5, 0x10(r3)
  cmplw     r0, r5
  bge-      .loc_0x74
  lwz       r4, 0xC(r3)
  lwz       r0, 0x8(r28)
  mullw     r4, r5, r4
  cmpw      r4, r0
  bgt-      .loc_0x84

.loc_0x74:
  lwz       r3, 0x18(r1)
  li        r4, -0x80
  bl        -0x33D4
  b         .loc_0x198

.loc_0x84:
  bl        -0x2A4C
  lwz       r0, 0x4(r28)
  lwz       r5, 0x18(r1)
  rlwinm    r0,r0,6,0,25
  add       r4, r3, r0
  lwz       r3, 0xC(r5)
  lhz       r0, 0x38(r4)
  mullw     r3, r0, r3
  cmpw      r3, r30
  ble-      .loc_0xB8
  add       r0, r30, r29
  cmpw      r3, r0
  bge-      .loc_0xC8

.loc_0xB8:
  addi      r3, r5, 0
  li        r4, -0xB
  bl        -0x3418
  b         .loc_0x198

.loc_0xC8:
  stw       r28, 0xC0(r5)
  stw       r29, 0xC(r28)
  lwz       r0, 0x8(r28)
  cmpw      r30, r0
  bge-      .loc_0x118
  li        r0, 0
  stw       r0, 0x8(r28)
  lhz       r0, 0x36(r4)
  sth       r0, 0x10(r28)
  lhz       r4, 0x10(r28)
  cmplwi    r4, 0x5
  blt-      .loc_0x108
  lwz       r3, 0x18(r1)
  lhz       r0, 0x10(r3)
  cmplw     r4, r0
  blt-      .loc_0x118

.loc_0x108:
  lwz       r3, 0x18(r1)
  li        r4, -0x6
  bl        -0x3468
  b         .loc_0x198

.loc_0x118:
  lwz       r3, 0x18(r1)
  bl        -0x2EE8
  b         .loc_0x16C

.loc_0x124:
  lwz       r0, 0x8(r28)
  add       r0, r0, r4
  stw       r0, 0x8(r28)
  lhz       r0, 0x10(r28)
  rlwinm    r0,r0,1,0,30
  lhzx      r0, r3, r0
  sth       r0, 0x10(r28)
  lhz       r5, 0x10(r28)
  cmplwi    r5, 0x5
  blt-      .loc_0x15C
  lwz       r4, 0x18(r1)
  lhz       r0, 0x10(r4)
  cmplw     r5, r0
  blt-      .loc_0x16C

.loc_0x15C:
  lwz       r3, 0x18(r1)
  li        r4, -0x6
  bl        -0x34BC
  b         .loc_0x198

.loc_0x16C:
  lwz       r4, 0x18(r1)
  lwz       r5, 0x8(r28)
  lwz       r4, 0xC(r4)
  subi      r0, r4, 0x1
  andc      r0, r30, r0
  cmplw     r5, r0
  blt+      .loc_0x124
  stw       r30, 0x8(r28)
  li        r3, 0
  lwz       r0, 0x18(r1)
  stw       r0, 0x0(r31)

.loc_0x198:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  mtlr      r0
  lwz       r29, 0x24(r1)
  lwz       r28, 0x20(r1)
  addi      r1, r1, 0x30
  blr
*/
}

/*
 * --INFO--
 * Address:	8020C430
 * Size:	000130
 */
void ReadCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  addi      r29, r3, 0
  lis       r3, 0x803D
  mulli     r5, r29, 0x108
  addi      r0, r3, 0x3420
  mr.       r30, r4
  add       r31, r0, r5
  blt-      .loc_0xF0
  lwz       r28, 0xC0(r31)
  lwz       r4, 0xC(r28)
  cmpwi     r4, 0
  bge-      .loc_0x44
  li        r30, -0xE
  b         .loc_0xF0

.loc_0x44:
  lwz       r5, 0xC(r31)
  lwz       r6, 0x8(r28)
  subi      r0, r5, 0x1
  not       r3, r0
  add       r0, r6, r5
  and       r0, r3, r0
  sub       r27, r0, r6
  sub       r0, r4, r27
  stw       r0, 0xC(r28)
  lwz       r0, 0xC(r28)
  cmpwi     r0, 0
  ble-      .loc_0xF0
  mr        r3, r31
  bl        -0x2FFC
  lwz       r0, 0x8(r28)
  add       r0, r0, r27
  stw       r0, 0x8(r28)
  lhz       r0, 0x10(r28)
  rlwinm    r0,r0,1,0,30
  lhzx      r0, r3, r0
  sth       r0, 0x10(r28)
  lhz       r3, 0x10(r28)
  cmplwi    r3, 0x5
  blt-      .loc_0xB0
  lhz       r0, 0x10(r31)
  cmplw     r3, r0
  blt-      .loc_0xB8

.loc_0xB0:
  li        r30, -0x6
  b         .loc_0xF0

.loc_0xB8:
  lwz       r5, 0xC(r28)
  lwz       r0, 0xC(r31)
  cmpw      r5, r0
  bge-      .loc_0xCC
  b         .loc_0xD0

.loc_0xCC:
  mr        r5, r0

.loc_0xD0:
  mullw     r4, r0, r3
  lwz       r6, 0xB4(r31)
  lis       r3, 0x8021
  subi      r7, r3, 0x3BD0
  addi      r3, r29, 0
  bl        -0x3224
  mr.       r30, r3
  bge-      .loc_0x11C

.loc_0xF0:
  lwz       r27, 0xD0(r31)
  li        r0, 0
  addi      r3, r31, 0
  stw       r0, 0xD0(r31)
  mr        r4, r30
  bl        -0x3614
  addi      r12, r27, 0
  mtlr      r12
  addi      r3, r29, 0
  addi      r4, r30, 0
  blrl      

.loc_0x11C:
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8020C560
 * Size:	000144
 */
void CARDReadAsync(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm.   r0,r6,0,23,31
  stwu      r1, -0x38(r1)
  stmw      r27, 0x24(r1)
  addi      r29, r3, 0
  addi      r30, r4, 0
  addi      r31, r5, 0
  addi      r27, r7, 0
  bne-      .loc_0x30
  rlwinm.   r0,r31,0,23,31
  beq-      .loc_0x38

.loc_0x30:
  li        r3, -0x80
  b         .loc_0x130

.loc_0x38:
  addi      r3, r29, 0
  addi      r4, r31, 0
  addi      r5, r6, 0
  addi      r6, r1, 0x1C
  bl        -0x330
  cmpwi     r3, 0
  bge-      .loc_0x58
  b         .loc_0x130

.loc_0x58:
  lwz       r3, 0x1C(r1)
  bl        -0x2D0C
  lwz       r0, 0x4(r29)
  rlwinm    r0,r0,6,0,25
  add       r28, r3, r0
  addi      r3, r28, 0
  bl        -0xAE8
  addi      r4, r3, 0
  cmpwi     r4, -0xA
  bne-      .loc_0x8C
  mr        r3, r28
  bl        -0xA70
  mr        r4, r3

.loc_0x8C:
  cmpwi     r4, 0
  bge-      .loc_0xA0
  lwz       r3, 0x1C(r1)
  bl        -0x36D8
  b         .loc_0x130

.loc_0xA0:
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        -0x15A50
  cmplwi    r27, 0
  beq-      .loc_0xBC
  mr        r0, r27
  b         .loc_0xC4

.loc_0xBC:
  lis       r3, 0x8020
  addi      r0, r3, 0x7E60

.loc_0xC4:
  lwz       r3, 0x1C(r1)
  stw       r0, 0xD0(r3)
  lwz       r3, 0x1C(r1)
  lwz       r4, 0x8(r29)
  lwz       r5, 0xC(r3)
  subi      r0, r5, 0x1
  and       r8, r4, r0
  sub       r3, r5, r8
  cmpw      r31, r3
  bge-      .loc_0xF0
  mr        r3, r31

.loc_0xF0:
  lhz       r0, 0x10(r29)
  lis       r4, 0x8021
  addi      r31, r3, 0
  lwz       r3, 0x0(r29)
  mullw     r0, r5, r0
  subi      r7, r4, 0x3BD0
  addi      r5, r31, 0
  addi      r6, r30, 0
  add       r4, r8, r0
  bl        -0x3384
  mr.       r29, r3
  bge-      .loc_0x12C
  lwz       r3, 0x1C(r1)
  mr        r4, r29
  bl        -0x3768

.loc_0x12C:
  mr        r3, r29

.loc_0x130:
  lmw       r27, 0x24(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8020C6A4
 * Size:	000048
 */
void CARDRead(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x8020
  stw       r0, 0x4(r1)
  addi      r7, r7, 0x7E64
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  bl        -0x160
  cmpwi     r3, 0
  bge-      .loc_0x2C
  b         .loc_0x34

.loc_0x2C:
  lwz       r3, 0x0(r31)
  bl        -0x35A8

.loc_0x34:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void CARDCancel(void)
{
	// UNUSED FUNCTION
}
