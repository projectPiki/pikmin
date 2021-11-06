

/*
 * --INFO--
 * Address:	80215E04
 * Size:	0002DC
 */
void fwrite(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stmw      r25, 0x2C(r1)
  addi      r26, r4, 0
  addi      r27, r6, 0
  addi      r28, r3, 0
  addi      r25, r5, 0
  addi      r3, r27, 0
  li        r4, 0
  bl        0x4864
  cmpwi     r3, 0
  bne-      .loc_0x40
  addi      r3, r27, 0
  li        r4, -0x1
  bl        0x4850

.loc_0x40:
  mullw.    r0, r26, r25
  mr        r29, r0
  beq-      .loc_0x64
  lbz       r0, 0xA(r27)
  cmplwi    r0, 0
  bne-      .loc_0x64
  lhz       r0, 0x4(r27)
  rlwinm.   r0,r0,26,29,31
  bne-      .loc_0x6C

.loc_0x64:
  li        r3, 0
  b         .loc_0x2C8

.loc_0x6C:
  cmpwi     r0, 0x2
  bne-      .loc_0x78
  bl        0x71C

.loc_0x78:
  lbz       r0, 0x5(r27)
  li        r31, 0x1
  addi      r3, r31, 0
  rlwinm.   r0,r0,29,31,31
  addi      r4, r31, 0
  beq-      .loc_0xA4
  lhz       r0, 0x4(r27)
  rlwinm    r0,r0,26,29,31
  cmpwi     r0, 0x3
  beq-      .loc_0xA4
  li        r4, 0

.loc_0xA4:
  cmpwi     r4, 0
  bne-      .loc_0xC0
  lbz       r0, 0x4(r27)
  rlwinm    r0,r0,31,30,31
  cmplwi    r0, 0x2
  beq-      .loc_0xC0
  li        r3, 0

.loc_0xC0:
  cmpwi     r3, 0
  bne-      .loc_0xDC
  lbz       r0, 0x4(r27)
  rlwinm    r0,r0,31,30,31
  cmplwi    r0, 0x1
  beq-      .loc_0xDC
  li        r31, 0

.loc_0xDC:
  lbz       r3, 0x8(r27)
  rlwinm.   r0,r3,27,29,31
  bne-      .loc_0x108
  lbz       r0, 0x4(r27)
  rlwinm.   r0,r0,29,30,30
  beq-      .loc_0x108
  li        r0, 0x1
  rlwimi    r3,r0,5,24,26
  stb       r3, 0x8(r27)
  mr        r3, r27
  bl        -0x18C

.loc_0x108:
  lbz       r0, 0x8(r27)
  rlwinm    r0,r0,27,29,31
  cmplwi    r0, 0x1
  beq-      .loc_0x130
  li        r0, 0x1
  stb       r0, 0xA(r27)
  li        r0, 0
  li        r3, 0
  stw       r0, 0x24(r27)
  b         .loc_0x2C8

.loc_0x130:
  cmplwi    r29, 0
  addi      r30, r28, 0
  li        r28, 0
  beq-      .loc_0x238
  lwz       r4, 0x20(r27)
  lwz       r3, 0x18(r27)
  cmplw     r4, r3
  bne-      .loc_0x158
  cmpwi     r31, 0
  beq-      .loc_0x238

.loc_0x158:
  lwz       r0, 0x1C(r27)
  sub       r3, r4, r3
  sub       r0, r0, r3
  stw       r0, 0x24(r27)

.loc_0x168:
  lwz       r0, 0x24(r27)
  stw       r0, 0x20(r1)
  lwz       r0, 0x20(r1)
  cmplw     r0, r29
  ble-      .loc_0x180
  stw       r29, 0x20(r1)

.loc_0x180:
  lwz       r5, 0x20(r1)
  cmplwi    r5, 0
  beq-      .loc_0x1C4
  lwz       r3, 0x20(r27)
  mr        r4, r30
  bl        -0x212B84
  lwz       r3, 0x20(r1)
  lwz       r0, 0x20(r27)
  add       r30, r30, r3
  add       r0, r0, r3
  stw       r0, 0x20(r27)
  add       r28, r28, r3
  sub       r29, r29, r3
  lwz       r3, 0x20(r1)
  lwz       r0, 0x24(r27)
  sub       r0, r0, r3
  stw       r0, 0x24(r27)

.loc_0x1C4:
  lwz       r3, 0x24(r27)
  cmplwi    r3, 0
  bne-      .loc_0x1E8
  lhz       r0, 0x4(r27)
  rlwinm    r0,r0,26,29,31
  cmpwi     r0, 0x3
  bne-      .loc_0x1E8
  add       r28, r28, r29
  b         .loc_0x238

.loc_0x1E8:
  cmplwi    r3, 0
  beq-      .loc_0x1FC
  lbz       r0, 0x4(r27)
  rlwinm.   r0,r0,31,30,31
  bne-      .loc_0x228

.loc_0x1FC:
  addi      r3, r27, 0
  li        r4, 0
  bl        -0x358
  cmpwi     r3, 0
  beq-      .loc_0x228
  li        r0, 0x1
  stb       r0, 0xA(r27)
  li        r0, 0
  li        r29, 0
  stw       r0, 0x24(r27)
  b         .loc_0x238

.loc_0x228:
  cmplwi    r29, 0
  beq-      .loc_0x238
  cmpwi     r31, 0
  bne+      .loc_0x168

.loc_0x238:
  cmplwi    r29, 0
  beq-      .loc_0x2A4
  cmpwi     r31, 0
  bne-      .loc_0x2A4
  lwz       r31, 0x18(r27)
  add       r0, r30, r29
  lwz       r25, 0x1C(r27)
  addi      r3, r27, 0
  addi      r4, r1, 0x20
  stw       r30, 0x18(r27)
  stw       r29, 0x1C(r27)
  stw       r0, 0x20(r27)
  bl        -0x3BC
  cmpwi     r3, 0
  beq-      .loc_0x284
  li        r0, 0x1
  stb       r0, 0xA(r27)
  li        r0, 0
  stw       r0, 0x24(r27)

.loc_0x284:
  lwz       r0, 0x20(r1)
  mr        r3, r27
  stw       r31, 0x18(r27)
  add       r28, r28, r0
  stw       r25, 0x1C(r27)
  bl        -0x320
  li        r0, 0
  stw       r0, 0x24(r27)

.loc_0x2A4:
  lbz       r0, 0x4(r27)
  rlwinm    r0,r0,31,30,31
  cmplwi    r0, 0x2
  beq-      .loc_0x2BC
  li        r0, 0
  stw       r0, 0x24(r27)

.loc_0x2BC:
  subi      r0, r26, 0x1
  add       r0, r28, r0
  divwu     r3, r0, r26

.loc_0x2C8:
  lmw       r25, 0x2C(r1)
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000378
 */
void fread(void)
{
	// UNUSED FUNCTION
}
