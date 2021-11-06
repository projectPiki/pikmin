

/*
 * --INFO--
 * Address:	801F7BCC
 * Size:	0000F4
 */
void SetExiInterruptMask(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x803D
  stw       r0, 0x4(r1)
  cmpwi     r3, 0x1
  addi      r5, r5, 0x23F0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  addi      r4, r5, 0x70
  beq-      .loc_0x80
  bge-      .loc_0x38
  cmpwi     r3, 0
  bge-      .loc_0x44
  b         .loc_0xE0

.loc_0x38:
  cmpwi     r3, 0x3
  bge-      .loc_0xE0
  b         .loc_0xB0

.loc_0x44:
  lwz       r0, 0x0(r31)
  cmplwi    r0, 0
  bne-      .loc_0x5C
  lwz       r0, 0x0(r4)
  cmplwi    r0, 0
  beq-      .loc_0x68

.loc_0x5C:
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,27,27
  beq-      .loc_0x74

.loc_0x68:
  lis       r3, 0x41
  bl        0x16E4
  b         .loc_0xE0

.loc_0x74:
  lis       r3, 0x41
  bl        0x1760
  b         .loc_0xE0

.loc_0x80:
  lwz       r0, 0x0(r31)
  cmplwi    r0, 0
  beq-      .loc_0x98
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,27,27
  beq-      .loc_0xA4

.loc_0x98:
  lis       r3, 0x8
  bl        0x16B4
  b         .loc_0xE0

.loc_0xA4:
  lis       r3, 0x8
  bl        0x1730
  b         .loc_0xE0

.loc_0xB0:
  li        r3, 0x19
  bl        0x1364
  cmplwi    r3, 0
  beq-      .loc_0xCC
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,27,27
  beq-      .loc_0xD8

.loc_0xCC:
  li        r3, 0x40
  bl        0x1680
  b         .loc_0xE0

.loc_0xD8:
  li        r3, 0x40
  bl        0x16FC

.loc_0xE0:
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
 * Size:	000164
 */
void CompleteTransfer(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F7CC0
 * Size:	00025C
 */
void EXIImm(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stmw      r19, 0x24(r1)
  addi      r28, r3, 0
  lis       r3, 0x803D
  mulli     r8, r28, 0x38
  addi      r0, r3, 0x23F0
  addi      r29, r4, 0
  addi      r30, r5, 0
  addi      r31, r6, 0
  addi      r19, r7, 0
  add       r27, r0, r8
  bl        0x1288
  lwz       r0, 0xC(r27)
  addi      r26, r3, 0
  rlwinm.   r0,r0,0,30,31
  bne-      .loc_0x54
  lwz       r0, 0xC(r27)
  rlwinm.   r0,r0,0,29,29
  bne-      .loc_0x64

.loc_0x54:
  mr        r3, r26
  bl        0x128C
  li        r3, 0
  b         .loc_0x248

.loc_0x64:
  stw       r19, 0x4(r27)
  lwz       r0, 0x4(r27)
  cmplwi    r0, 0
  beq-      .loc_0x98
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0x1
  li        r6, 0
  bl        0x56C
  mulli     r0, r28, 0x3
  lis       r3, 0x20
  srw       r3, r3, r0
  bl        0x1650

.loc_0x98:
  lwz       r0, 0xC(r27)
  cmplwi    r31, 0
  ori       r0, r0, 0x2
  stw       r0, 0xC(r27)
  beq-      .loc_0x1EC
  li        r24, 0
  cmpw      r24, r30
  li        r25, 0
  bge-      .loc_0x1D8
  cmpwi     r30, 0x8
  subi      r3, r30, 0x8
  ble-      .loc_0x240
  addi      r0, r3, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r3, 0
  mtctr     r0
  addi      r12, r29, 0
  ble-      .loc_0x240

.loc_0xE0:
  subfic    r3, r24, 0x3
  lbz       r9, 0x0(r12)
  addi      r0, r24, 0x1
  lbz       r10, 0x1(r12)
  rlwinm    r7,r3,3,0,28
  lbz       r8, 0x2(r12)
  subfic    r5, r0, 0x3
  lbz       r6, 0x3(r12)
  addi      r3, r24, 0x2
  lbz       r4, 0x4(r12)
  slw       r11, r9, r7
  lbz       r0, 0x5(r12)
  rlwinm    r9,r5,3,0,28
  lbz       r20, 0x6(r12)
  subfic    r3, r3, 0x3
  lbz       r22, 0x7(r12)
  rlwinm    r7,r3,3,0,28
  neg       r5, r24
  addi      r3, r24, 0x4
  rlwinm    r5,r5,3,0,28
  subfic    r3, r3, 0x3
  addi      r19, r24, 0x5
  rlwinm    r3,r3,3,0,28
  subfic    r19, r19, 0x3
  addi      r21, r24, 0x6
  rlwinm    r19,r19,3,0,28
  subfic    r21, r21, 0x3
  addi      r23, r24, 0x7
  rlwinm    r21,r21,3,0,28
  subfic    r23, r23, 0x3
  rlwinm    r23,r23,3,0,28
  or        r25, r25, r11
  slw       r9, r10, r9
  or        r25, r25, r9
  slw       r7, r8, r7
  or        r25, r25, r7
  slw       r5, r6, r5
  or        r25, r25, r5
  slw       r3, r4, r3
  or        r25, r25, r3
  slw       r0, r0, r19
  or        r25, r25, r0
  slw       r0, r20, r21
  or        r25, r25, r0
  slw       r0, r22, r23
  or        r25, r25, r0
  addi      r12, r12, 0x8
  addi      r24, r24, 0x8
  bdnz+     .loc_0xE0
  b         .loc_0x240

.loc_0x1A8:
  sub       r0, r30, r24
  cmpw      r24, r30
  mtctr     r0
  bge-      .loc_0x1D8

.loc_0x1B8:
  subfic    r0, r24, 0x3
  lbz       r3, 0x0(r4)
  rlwinm    r0,r0,3,0,28
  slw       r0, r3, r0
  or        r25, r25, r0
  addi      r4, r4, 0x1
  addi      r24, r24, 0x1
  bdnz+     .loc_0x1B8

.loc_0x1D8:
  mulli     r0, r28, 0x14
  lis       r3, 0xCC00
  addi      r3, r3, 0x6800
  add       r3, r3, r0
  stw       r25, 0x10(r3)

.loc_0x1EC:
  cmplwi    r31, 0x1
  stw       r29, 0x14(r27)
  beq-      .loc_0x200
  mr        r3, r30
  b         .loc_0x204

.loc_0x200:
  li        r3, 0

.loc_0x204:
  mulli     r0, r28, 0x14
  stw       r3, 0x10(r27)
  rlwinm    r5,r31,2,0,29
  subi      r4, r30, 0x1
  lis       r3, 0xCC00
  addi      r3, r3, 0x6800
  ori       r5, r5, 0x1
  rlwinm    r4,r4,4,0,27
  or        r4, r5, r4
  add       r3, r3, r0
  stw       r4, 0xC(r3)
  mr        r3, r26
  bl        0x10B0
  li        r3, 0x1
  b         .loc_0x248

.loc_0x240:
  add       r4, r29, r24
  b         .loc_0x1A8

.loc_0x248:
  lmw       r19, 0x24(r1)
  lwz       r0, 0x5C(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F7F1C
 * Size:	0000A0
 */
void EXIImmEx(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  addi      r27, r3, 0
  addi      r28, r4, 0
  addi      r29, r5, 0
  addi      r30, r6, 0
  b         .loc_0x80

.loc_0x24:
  cmpwi     r29, 0x4
  bge-      .loc_0x34
  mr        r31, r29
  b         .loc_0x38

.loc_0x34:
  li        r31, 0x4

.loc_0x38:
  addi      r5, r31, 0
  addi      r3, r27, 0
  addi      r4, r28, 0
  addi      r6, r30, 0
  li        r7, 0
  bl        -0x2A8
  cmpwi     r3, 0
  bne-      .loc_0x60
  li        r3, 0
  b         .loc_0x8C

.loc_0x60:
  mr        r3, r27
  bl        0x128
  cmpwi     r3, 0
  bne-      .loc_0x78
  li        r3, 0
  b         .loc_0x8C

.loc_0x78:
  add       r28, r28, r31
  sub       r29, r29, r31

.loc_0x80:
  cmpwi     r29, 0
  bne+      .loc_0x24
  li        r3, 0x1

.loc_0x8C:
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F7FBC
 * Size:	0000EC
 */
void EXIDma(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stmw      r25, 0x24(r1)
  addi      r27, r3, 0
  lis       r3, 0x803D
  mulli     r8, r27, 0x38
  addi      r0, r3, 0x23F0
  addi      r28, r4, 0
  addi      r29, r5, 0
  addi      r30, r6, 0
  addi      r25, r7, 0
  add       r26, r0, r8
  bl        0xF8C
  lwz       r0, 0xC(r26)
  addi      r31, r3, 0
  rlwinm.   r0,r0,0,30,31
  bne-      .loc_0x54
  lwz       r0, 0xC(r26)
  rlwinm.   r0,r0,0,29,29
  bne-      .loc_0x64

.loc_0x54:
  mr        r3, r31
  bl        0xF90
  li        r3, 0
  b         .loc_0xD8

.loc_0x64:
  stw       r25, 0x4(r26)
  lwz       r0, 0x4(r26)
  cmplwi    r0, 0
  beq-      .loc_0x98
  addi      r3, r27, 0
  li        r4, 0
  li        r5, 0x1
  li        r6, 0
  bl        0x270
  mulli     r0, r27, 0x3
  lis       r3, 0x20
  srw       r3, r3, r0
  bl        0x1354

.loc_0x98:
  lwz       r0, 0xC(r26)
  lis       r3, 0xCC00
  mulli     r5, r27, 0x14
  ori       r4, r0, 0x1
  addi      r0, r3, 0x6800
  stw       r4, 0xC(r26)
  rlwinm    r3,r28,0,6,26
  add       r4, r0, r5
  stw       r3, 0x4(r4)
  rlwinm    r0,r30,2,0,29
  ori       r0, r0, 0x3
  stw       r29, 0x8(r4)
  mr        r3, r31
  stw       r0, 0xC(r4)
  bl        0xF18
  li        r3, 0x1

.loc_0xD8:
  lmw       r25, 0x24(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F80A8
 * Size:	000208
 */
void EXISync(void)
{
/*
.loc_0x0:
  mflr      r0
  mulli     r6, r3, 0x38
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  lis       r5, 0x803D
  lis       r4, 0xCC00
  stmw      r27, 0x1C(r1)
  addi      r0, r5, 0x23F0
  mulli     r30, r3, 0x14
  addi      r29, r4, 0x6800
  add       r31, r0, r6
  add       r29, r29, r30
  li        r28, 0
  b         .loc_0x1E4

.loc_0x38:
  lwz       r0, 0xC(r29)
  rlwinm.   r0,r0,0,31,31
  bne-      .loc_0x1E4
  bl        0xE90
  lwz       r0, 0xC(r31)
  addi      r27, r3, 0
  rlwinm.   r0,r0,0,29,29
  beq-      .loc_0x1D8
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,30,31
  beq-      .loc_0x194
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,30,30
  beq-      .loc_0x188
  lwz       r4, 0x10(r31)
  cmpwi     r4, 0
  beq-      .loc_0x188
  lis       r3, 0xCC00
  lwz       r7, 0x14(r31)
  addi      r0, r3, 0x6800
  add       r3, r0, r30
  lwz       r6, 0x10(r3)
  li        r5, 0
  ble-      .loc_0x188
  cmpwi     r4, 0x8
  subi      r3, r4, 0x8
  ble-      .loc_0x15C
  addi      r0, r3, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r3, 0
  mtctr     r0
  ble-      .loc_0x15C

.loc_0xB8:
  subfic    r0, r5, 0x3
  rlwinm    r3,r0,3,0,28
  addi      r0, r5, 0x1
  srw       r8, r6, r3
  subfic    r0, r0, 0x3
  stb       r8, 0x0(r7)
  rlwinm    r3,r0,3,0,28
  addi      r0, r5, 0x2
  srw       r3, r6, r3
  subfic    r0, r0, 0x3
  stb       r3, 0x1(r7)
  rlwinm    r0,r0,3,0,28
  srw       r0, r6, r0
  neg       r8, r5
  stb       r0, 0x2(r7)
  rlwinm    r9,r8,3,0,28
  addi      r8, r5, 0x4
  srw       r12, r6, r9
  subfic    r8, r8, 0x3
  stb       r12, 0x3(r7)
  rlwinm    r9,r8,3,0,28
  addi      r8, r5, 0x5
  srw       r11, r6, r9
  subfic    r8, r8, 0x3
  stb       r11, 0x4(r7)
  rlwinm    r9,r8,3,0,28
  srw       r10, r6, r9
  addi      r8, r5, 0x6
  stb       r10, 0x5(r7)
  subfic    r9, r8, 0x3
  addi      r8, r5, 0x7
  rlwinm    r9,r9,3,0,28
  srw       r9, r6, r9
  subfic    r8, r8, 0x3
  stb       r9, 0x6(r7)
  rlwinm    r8,r8,3,0,28
  srw       r8, r6, r8
  stb       r8, 0x7(r7)
  addi      r7, r7, 0x8
  addi      r5, r5, 0x8
  bdnz+     .loc_0xB8

.loc_0x15C:
  sub       r0, r4, r5
  cmpw      r5, r4
  mtctr     r0
  bge-      .loc_0x188

.loc_0x16C:
  subfic    r0, r5, 0x3
  rlwinm    r0,r0,3,0,28
  srw       r0, r6, r0
  stb       r0, 0x0(r7)
  addi      r7, r7, 0x1
  addi      r5, r5, 0x1
  bdnz+     .loc_0x16C

.loc_0x188:
  lwz       r0, 0xC(r31)
  rlwinm    r0,r0,0,0,29
  stw       r0, 0xC(r31)

.loc_0x194:
  bl        -0x2190
  cmplwi    r3, 0xFF
  bne-      .loc_0x1D4
  lwz       r0, 0x10(r31)
  cmpwi     r0, 0x4
  bne-      .loc_0x1D4
  lwz       r0, 0x0(r29)
  rlwinm.   r0,r0,0,25,27
  bne-      .loc_0x1D4
  lis       r3, 0xCC00
  addi      r0, r3, 0x6800
  add       r3, r0, r30
  lwz       r3, 0x10(r3)
  subis     r0, r3, 0x101
  cmplwi    r0, 0
  beq-      .loc_0x1D8

.loc_0x1D4:
  li        r28, 0x1

.loc_0x1D8:
  mr        r3, r27
  bl        0xD20
  b         .loc_0x1F0

.loc_0x1E4:
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,29,29
  bne+      .loc_0x38

.loc_0x1F0:
  mr        r3, r28
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F82B0
 * Size:	000048
 */
void EXIClearInterrupts(void)
{
/*
.loc_0x0:
  mulli     r0, r3, 0x14
  lis       r3, 0xCC00
  addi      r7, r3, 0x6800
  add       r7, r7, r0
  lwz       r0, 0x0(r7)
  mr        r3, r0
  andi.     r0, r0, 0x7F5
  cmpwi     r4, 0
  beq-      .loc_0x28
  ori       r0, r0, 0x2

.loc_0x28:
  cmpwi     r5, 0
  beq-      .loc_0x34
  ori       r0, r0, 0x8

.loc_0x34:
  cmpwi     r6, 0
  beq-      .loc_0x40
  ori       r0, r0, 0x800

.loc_0x40:
  stw       r0, 0x0(r7)
  blr
*/
}

/*
 * --INFO--
 * Address:	801F82F8
 * Size:	00007C
 */
void EXISetExiCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  addi      r27, r3, 0
  lis       r3, 0x803D
  mulli     r0, r27, 0x38
  addi      r31, r3, 0x23F0
  add       r30, r31, r0
  addi      r28, r4, 0
  bl        0xC5C
  lwz       r29, 0x0(r30)
  cmpwi     r27, 0x2
  stw       r28, 0x0(r30)
  mr        r28, r3
  beq-      .loc_0x50
  addi      r3, r27, 0
  addi      r4, r30, 0
  bl        -0x774
  b         .loc_0x5C

.loc_0x50:
  addi      r4, r31, 0
  li        r3, 0
  bl        -0x784

.loc_0x5C:
  mr        r3, r28
  bl        0xC4C
  mr        r3, r29
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void EXIProbeReset(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F8374
 * Size:	000168
 */
void EXIProbe(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  addi      r29, r3, 0
  lis       r3, 0x803D
  mulli     r4, r29, 0x38
  addi      r0, r3, 0x23F0
  cmpwi     r29, 0x2
  add       r27, r0, r4
  bne-      .loc_0x34
  li        r3, 0x1
  b         .loc_0x154

.loc_0x34:
  li        r30, 0x1
  bl        0xBD0
  mulli     r5, r29, 0x14
  lwz       r0, 0xC(r27)
  lis       r4, 0xCC00
  addi      r6, r4, 0x6800
  add       r6, r6, r5
  rlwinm.   r0,r0,0,28,28
  lwz       r7, 0x0(r6)
  mr        r31, r3
  bne-      .loc_0x120
  rlwinm.   r0,r7,0,20,20
  beq-      .loc_0x8C
  lwz       r5, 0x0(r6)
  lis       r3, 0x8000
  rlwinm    r0,r29,2,0,29
  andi.     r5, r5, 0x7F5
  addi      r3, r3, 0x30C0
  li        r4, 0
  ori       r5, r5, 0x800
  stw       r5, 0x0(r6)
  stwx      r4, r3, r0

.loc_0x8C:
  rlwinm.   r0,r7,0,19,19
  beq-      .loc_0x104
  lis       r28, 0x8000
  lwz       r0, 0xF8(r28)
  lis       r3, 0x1062
  addi      r3, r3, 0x4DD3
  rlwinm    r0,r0,30,2,31
  mulhwu    r0, r3, r0
  rlwinm    r27,r0,26,6,31
  bl        0x4F7C
  addi      r6, r27, 0
  li        r5, 0
  bl        0x1CB78
  li        r5, 0
  li        r6, 0x64
  bl        0x1CB6C
  rlwinm    r0,r29,2,0,29
  addi      r3, r28, 0x30C0
  add       r3, r3, r0
  lwz       r0, 0x0(r3)
  addi      r4, r4, 0x1
  cmplwi    r0, 0
  bne-      .loc_0xEC
  stw       r4, 0x0(r3)

.loc_0xEC:
  lwz       r0, 0x0(r3)
  sub       r0, r4, r0
  cmpwi     r0, 0x3
  bge-      .loc_0x148
  li        r30, 0
  b         .loc_0x148

.loc_0x104:
  lis       r3, 0x8000
  rlwinm    r0,r29,2,0,29
  addi      r3, r3, 0x30C0
  li        r4, 0
  stwx      r4, r3, r0
  li        r30, 0
  b         .loc_0x148

.loc_0x120:
  rlwinm.   r0,r7,0,19,19
  beq-      .loc_0x130
  rlwinm.   r0,r7,0,20,20
  beq-      .loc_0x148

.loc_0x130:
  lis       r3, 0x8000
  rlwinm    r0,r29,2,0,29
  addi      r3, r3, 0x30C0
  li        r4, 0
  stwx      r4, r3, r0
  li        r30, 0

.loc_0x148:
  mr        r3, r31
  bl        0xAE4
  mr        r3, r30

.loc_0x154:
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F84DC
 * Size:	000060
 */
void EXIProbeEx(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        -0x17C
  cmpwi     r3, 0
  beq-      .loc_0x28
  li        r3, 0x1
  b         .loc_0x4C

.loc_0x28:
  lis       r3, 0x8000
  rlwinm    r0,r31,2,0,29
  addi      r3, r3, 0x30C0
  lwzx      r0, r3, r0
  cmplwi    r0, 0
  beq-      .loc_0x48
  li        r3, 0
  b         .loc_0x4C

.loc_0x48:
  li        r3, -0x1

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
 * Address:	801F853C
 * Size:	0000E4
 */
void EXIAttach(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  addi      r29, r4, 0
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  mulli     r5, r28, 0x38
  lis       r3, 0x803D
  addi      r0, r3, 0x23F0
  add       r31, r0, r5
  bl        0xA0C
  lwz       r0, 0xC(r31)
  addi      r30, r3, 0
  rlwinm.   r0,r0,0,28,28
  beq-      .loc_0x58
  mr        r3, r30
  bl        0xA1C
  li        r3, 0
  b         .loc_0xC4

.loc_0x58:
  mr        r3, r28
  bl        -0x224
  cmpwi     r3, 0
  bne-      .loc_0x78
  mr        r3, r30
  bl        0x9FC
  li        r3, 0
  b         .loc_0xC4

.loc_0x78:
  mulli     r0, r28, 0x14
  lis       r3, 0xCC00
  addi      r5, r3, 0x6800
  add       r5, r5, r0
  lwz       r4, 0x0(r5)
  mulli     r0, r28, 0x3
  andi.     r4, r4, 0x7F5
  lis       r3, 0x10
  srw       r3, r3, r0
  ori       r4, r4, 0x2
  stw       r4, 0x0(r5)
  stw       r29, 0x8(r31)
  bl        0xDC0
  lwz       r0, 0xC(r31)
  addi      r3, r30, 0
  ori       r0, r0, 0x8
  stw       r0, 0xC(r31)
  bl        0x9AC
  li        r3, 0x1

.loc_0xC4:
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
 * Address:	801F8620
 * Size:	0000BC
 */
void EXIDetach(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  mulli     r4, r29, 0x38
  lis       r3, 0x803D
  addi      r0, r3, 0x23F0
  add       r31, r0, r4
  bl        0x930
  lwz       r0, 0xC(r31)
  addi      r30, r3, 0
  rlwinm.   r0,r0,0,28,28
  bne-      .loc_0x50
  mr        r3, r30
  bl        0x940
  li        r3, 0x1
  b         .loc_0xA0

.loc_0x50:
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,27,27
  beq-      .loc_0x78
  lwz       r0, 0x18(r31)
  cmplwi    r0, 0
  bne-      .loc_0x78
  mr        r3, r30
  bl        0x918
  li        r3, 0
  b         .loc_0xA0

.loc_0x78:
  lwz       r3, 0xC(r31)
  mulli     r0, r29, 0x3
  rlwinm    r4,r3,0,29,27
  lis       r3, 0x70
  stw       r4, 0xC(r31)
  srw       r3, r3, r0
  bl        0xC6C
  mr        r3, r30
  bl        0x8EC
  li        r3, 0x1

.loc_0xA0:
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
 * Address:	801F86DC
 * Size:	00012C
 */
void EXISelect(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  addi      r27, r3, 0
  lis       r3, 0x803D
  mulli     r6, r27, 0x38
  addi      r0, r3, 0x23F0
  addi      r28, r4, 0
  addi      r29, r5, 0
  add       r31, r0, r6
  bl        0x874
  lwz       r0, 0xC(r31)
  addi      r30, r3, 0
  rlwinm.   r0,r0,0,29,29
  bne-      .loc_0x84
  cmpwi     r27, 0x2
  beq-      .loc_0x94
  cmplwi    r28, 0
  bne-      .loc_0x6C
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,28,28
  bne-      .loc_0x6C
  mr        r3, r27
  bl        -0x3C8
  cmpwi     r3, 0
  beq-      .loc_0x84

.loc_0x6C:
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,27,27
  beq-      .loc_0x84
  lwz       r0, 0x18(r31)
  cmplw     r0, r28
  beq-      .loc_0x94

.loc_0x84:
  mr        r3, r30
  bl        0x840
  li        r3, 0
  b         .loc_0x118

.loc_0x94:
  lwz       r4, 0xC(r31)
  lis       r3, 0xCC00
  mulli     r0, r27, 0x14
  ori       r4, r4, 0x4
  addi      r5, r3, 0x6800
  stw       r4, 0xC(r31)
  add       r5, r5, r0
  lwz       r4, 0x0(r5)
  li        r0, 0x1
  slw       r0, r0, r28
  rlwinm    r3,r0,7,0,24
  rlwinm    r0,r29,4,0,27
  andi.     r4, r4, 0x405
  or        r0, r3, r0
  or        r4, r4, r0
  stw       r4, 0x0(r5)
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,28,28
  beq-      .loc_0x10C
  cmpwi     r27, 0x1
  beq-      .loc_0x104
  bge-      .loc_0x10C
  cmpwi     r27, 0
  bge-      .loc_0xF8
  b         .loc_0x10C

.loc_0xF8:
  lis       r3, 0x10
  bl        0xB44
  b         .loc_0x10C

.loc_0x104:
  lis       r3, 0x2
  bl        0xB38

.loc_0x10C:
  mr        r3, r30
  bl        0x7B8
  li        r3, 0x1

.loc_0x118:
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8808
 * Size:	000110
 */
void EXIDeselect(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  lis       r3, 0x803D
  stw       r30, 0x18(r1)
  mulli     r4, r31, 0x38
  stw       r29, 0x14(r1)
  addi      r0, r3, 0x23F0
  stw       r28, 0x10(r1)
  add       r30, r0, r4
  bl        0x744
  lwz       r0, 0xC(r30)
  addi      r28, r3, 0
  rlwinm.   r0,r0,0,29,29
  bne-      .loc_0x54
  mr        r3, r28
  bl        0x754
  li        r3, 0
  b         .loc_0xF0

.loc_0x54:
  lwz       r4, 0xC(r30)
  lis       r3, 0xCC00
  mulli     r0, r31, 0x14
  rlwinm    r4,r4,0,30,28
  addi      r3, r3, 0x6800
  stw       r4, 0xC(r30)
  add       r3, r3, r0
  lwz       r29, 0x0(r3)
  andi.     r0, r29, 0x405
  stw       r0, 0x0(r3)
  lwz       r0, 0xC(r30)
  rlwinm.   r0,r0,0,28,28
  beq-      .loc_0xB4
  cmpwi     r31, 0x1
  beq-      .loc_0xAC
  bge-      .loc_0xB4
  cmpwi     r31, 0
  bge-      .loc_0xA0
  b         .loc_0xB4

.loc_0xA0:
  lis       r3, 0x10
  bl        0xAF8
  b         .loc_0xB4

.loc_0xAC:
  lis       r3, 0x2
  bl        0xAEC

.loc_0xB4:
  mr        r3, r28
  bl        0x6E4
  cmpwi     r31, 0x2
  beq-      .loc_0xEC
  rlwinm.   r0,r29,0,24,24
  beq-      .loc_0xEC
  mr        r3, r31
  bl        -0x564
  cmpwi     r3, 0
  beq-      .loc_0xE4
  li        r3, 0x1
  b         .loc_0xF0

.loc_0xE4:
  li        r3, 0
  b         .loc_0xF0

.loc_0xEC:
  li        r3, 0x1

.loc_0xF0:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8918
 * Size:	000080
 */
void EXIIntrruptHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  extsh     r5, r3
  stw       r0, 0x4(r1)
  lis       r3, 0x5555
  subi      r0, r5, 0x9
  addi      r3, r3, 0x5556
  stwu      r1, -0x8(r1)
  mulhw     r3, r3, r0
  rlwinm    r0,r3,1,31,31
  add       r3, r3, r0
  lis       r5, 0xCC00
  addi      r8, r5, 0x6800
  mulli     r0, r3, 0x14
  add       r8, r8, r0
  lwz       r7, 0x0(r8)
  mulli     r6, r3, 0x38
  andi.     r7, r7, 0x7F5
  lis       r5, 0x803D
  addi      r0, r5, 0x23F0
  ori       r7, r7, 0x2
  stw       r7, 0x0(r8)
  add       r5, r0, r6
  lwz       r0, 0x0(r5)
  cmplwi    r0, 0
  mr        r12, r0
  beq-      .loc_0x70
  mtlr      r12
  blrl      

.loc_0x70:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8998
 * Size:	0001F4
 */
void TCIntrruptHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  extsh     r6, r3
  stw       r0, 0x4(r1)
  lis       r3, 0x5555
  subi      r0, r6, 0xA
  addi      r3, r3, 0x5556
  stwu      r1, -0x30(r1)
  mulhw     r3, r3, r0
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  stw       r29, 0x24(r1)
  rlwinm    r0,r3,1,31,31
  add       r30, r3, r0
  lis       r3, 0x803D
  stw       r28, 0x20(r1)
  mulli     r5, r30, 0x38
  addi      r3, r3, 0x23F0
  lis       r0, 0x8000
  add       r31, r3, r5
  addi      r29, r4, 0
  srw       r3, r0, r6
  bl        0x930
  mulli     r6, r30, 0x14
  lis       r3, 0xCC00
  addi      r4, r3, 0x6800
  add       r4, r4, r6
  lwz       r0, 0x0(r4)
  andi.     r0, r0, 0x7F5
  ori       r0, r0, 0x8
  stw       r0, 0x0(r4)
  lwz       r0, 0x4(r31)
  cmplwi    r0, 0
  mr        r12, r0
  beq-      .loc_0x1D4
  li        r5, 0
  stw       r5, 0x4(r31)
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,30,31
  beq-      .loc_0x1C4
  lwz       r0, 0xC(r31)
  rlwinm.   r0,r0,0,30,30
  beq-      .loc_0x1B8
  lwz       r4, 0x10(r31)
  cmpwi     r4, 0
  beq-      .loc_0x1B8
  addi      r0, r3, 0x6800
  lwz       r7, 0x14(r31)
  add       r3, r0, r6
  lwz       r6, 0x10(r3)
  ble-      .loc_0x1B8
  cmpwi     r4, 0x8
  subi      r3, r4, 0x8
  ble-      .loc_0x18C
  addi      r0, r3, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r3, 0
  mtctr     r0
  ble-      .loc_0x18C

.loc_0xE8:
  subfic    r0, r5, 0x3
  rlwinm    r3,r0,3,0,28
  addi      r0, r5, 0x1
  srw       r8, r6, r3
  subfic    r0, r0, 0x3
  stb       r8, 0x0(r7)
  rlwinm    r3,r0,3,0,28
  addi      r0, r5, 0x2
  srw       r3, r6, r3
  subfic    r0, r0, 0x3
  stb       r3, 0x1(r7)
  rlwinm    r0,r0,3,0,28
  srw       r0, r6, r0
  neg       r8, r5
  stb       r0, 0x2(r7)
  rlwinm    r9,r8,3,0,28
  addi      r8, r5, 0x4
  srw       r28, r6, r9
  subfic    r8, r8, 0x3
  stb       r28, 0x3(r7)
  rlwinm    r9,r8,3,0,28
  addi      r8, r5, 0x5
  srw       r11, r6, r9
  subfic    r8, r8, 0x3
  stb       r11, 0x4(r7)
  rlwinm    r9,r8,3,0,28
  srw       r10, r6, r9
  addi      r8, r5, 0x6
  stb       r10, 0x5(r7)
  subfic    r9, r8, 0x3
  addi      r8, r5, 0x7
  rlwinm    r9,r9,3,0,28
  srw       r9, r6, r9
  subfic    r8, r8, 0x3
  stb       r9, 0x6(r7)
  rlwinm    r8,r8,3,0,28
  srw       r8, r6, r8
  stb       r8, 0x7(r7)
  addi      r7, r7, 0x8
  addi      r5, r5, 0x8
  bdnz+     .loc_0xE8

.loc_0x18C:
  sub       r0, r4, r5
  cmpw      r5, r4
  mtctr     r0
  bge-      .loc_0x1B8

.loc_0x19C:
  subfic    r0, r5, 0x3
  rlwinm    r0,r0,3,0,28
  srw       r0, r6, r0
  stb       r0, 0x0(r7)
  addi      r7, r7, 0x1
  addi      r5, r5, 0x1
  bdnz+     .loc_0x19C

.loc_0x1B8:
  lwz       r0, 0xC(r31)
  rlwinm    r0,r0,0,0,29
  stw       r0, 0xC(r31)

.loc_0x1C4:
  mtlr      r12
  addi      r3, r30, 0
  addi      r4, r29, 0
  blrl      

.loc_0x1D4:
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
 * Address:	801F8B8C
 * Size:	0000AC
 */
void EXTIntrruptHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  extsh     r5, r3
  stw       r0, 0x4(r1)
  lis       r3, 0x5555
  subi      r0, r5, 0xB
  addi      r3, r3, 0x5556
  stwu      r1, -0x18(r1)
  mulhw     r3, r3, r0
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  rlwinm    r0,r3,1,31,31
  add       r31, r3, r0
  mulli     r0, r31, 0x3
  lis       r3, 0x70
  addi      r30, r4, 0
  srw       r3, r3, r0
  bl        0x750
  mulli     r6, r31, 0x14
  lis       r5, 0xCC00
  lis       r3, 0x803D
  mulli     r4, r31, 0x38
  addi      r0, r3, 0x23F0
  addi      r3, r5, 0x6800
  li        r5, 0
  stwx      r5, r3, r6
  add       r3, r0, r4
  lwz       r12, 0x8(r3)
  lwz       r0, 0xC(r3)
  cmplwi    r12, 0
  rlwinm    r0,r0,0,29,27
  stw       r0, 0xC(r3)
  beq-      .loc_0x94
  stw       r5, 0x8(r3)
  mtlr      r12
  addi      r3, r31, 0
  addi      r4, r30, 0
  blrl      

.loc_0x94:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8C38
 * Size:	000104
 */
void EXIInit(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x80
  stw       r0, 0x4(r1)
  subi      r3, r3, 0x8000
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r29, 0xC(r1)
  stw       r28, 0x8(r1)
  bl        0x6C0
  lis       r5, 0xCC00
  li        r28, 0
  stw       r28, 0x6800(r5)
  li        r0, 0x2000
  lis       r3, 0x8020
  stw       r28, 0x6814(r5)
  subi      r29, r3, 0x76E8
  addi      r4, r29, 0
  stw       r28, 0x6828(r5)
  li        r3, 0x9
  stw       r0, 0x6800(r5)
  bl        0x33C
  lis       r3, 0x8020
  subi      r30, r3, 0x7668
  addi      r4, r30, 0
  li        r3, 0xA
  bl        0x328
  lis       r3, 0x8020
  subi      r31, r3, 0x7474
  addi      r4, r31, 0
  li        r3, 0xB
  bl        0x314
  addi      r4, r29, 0
  li        r3, 0xC
  bl        0x308
  addi      r4, r30, 0
  li        r3, 0xD
  bl        0x2FC
  addi      r4, r31, 0
  li        r3, 0xE
  bl        0x2F0
  addi      r4, r29, 0
  li        r3, 0xF
  bl        0x2E4
  addi      r4, r30, 0
  li        r3, 0x10
  bl        0x2D8
  bl        -0x334C
  rlwinm.   r0,r3,0,3,3
  beq-      .loc_0xE4
  lis       r4, 0x8000
  stw       r28, 0x30C4(r4)
  li        r3, 0
  stw       r28, 0x30C0(r4)
  bl        -0x99C
  li        r3, 0x1
  bl        -0x9A4

.loc_0xE4:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  lwz       r29, 0xC(r1)
  lwz       r28, 0x8(r1)
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8D3C
 * Size:	0000F4
 */
void EXILock(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  addi      r27, r3, 0
  lis       r3, 0x803D
  mulli     r6, r27, 0x38
  addi      r0, r3, 0x23F0
  add       r31, r0, r6
  addi      r28, r4, 0
  addi      r29, r5, 0
  bl        0x214
  lwz       r0, 0xC(r31)
  addi      r30, r3, 0
  rlwinm.   r0,r0,0,27,27
  beq-      .loc_0xB8
  cmplwi    r29, 0
  beq-      .loc_0xA8
  lwz       r4, 0x1C(r31)
  addi      r3, r31, 0
  cmpwi     r4, 0
  mtctr     r4
  ble-      .loc_0x80

.loc_0x5C:
  lwz       r0, 0x20(r3)
  cmplw     r0, r28
  bne-      .loc_0x78
  mr        r3, r30
  bl        0x1FC
  li        r3, 0
  b         .loc_0xE0

.loc_0x78:
  addi      r3, r3, 0x8
  bdnz+     .loc_0x5C

.loc_0x80:
  rlwinm    r0,r4,3,0,28
  add       r3, r31, r0
  stw       r29, 0x24(r3)
  lwz       r0, 0x1C(r31)
  rlwinm    r0,r0,3,0,28
  add       r3, r31, r0
  stw       r28, 0x20(r3)
  lwz       r3, 0x1C(r31)
  addi      r0, r3, 0x1
  stw       r0, 0x1C(r31)

.loc_0xA8:
  mr        r3, r30
  bl        0x1BC
  li        r3, 0
  b         .loc_0xE0

.loc_0xB8:
  lwz       r0, 0xC(r31)
  addi      r3, r27, 0
  addi      r4, r31, 0
  ori       r0, r0, 0x10
  stw       r0, 0xC(r31)
  stw       r28, 0x18(r31)
  bl        -0x1240
  mr        r3, r30
  bl        0x190
  li        r3, 0x1

.loc_0xE0:
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8E30
 * Size:	0000DC
 */
void EXIUnlock(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  stw       r28, 0x10(r1)
  addi      r28, r3, 0
  mulli     r4, r28, 0x38
  lis       r3, 0x803D
  addi      r0, r3, 0x23F0
  add       r31, r0, r4
  bl        0x11C
  lwz       r0, 0xC(r31)
  addi      r30, r3, 0
  rlwinm.   r0,r0,0,27,27
  bne-      .loc_0x54
  mr        r3, r30
  bl        0x12C
  li        r3, 0
  b         .loc_0xBC

.loc_0x54:
  lwz       r0, 0xC(r31)
  addi      r3, r28, 0
  addi      r4, r31, 0
  rlwinm    r0,r0,0,28,26
  stw       r0, 0xC(r31)
  bl        -0x12CC
  lwz       r3, 0x1C(r31)
  cmpwi     r3, 0
  ble-      .loc_0xB0
  subic.    r0, r3, 0x1
  lwz       r29, 0x24(r31)
  stw       r0, 0x1C(r31)
  ble-      .loc_0x9C
  lwz       r0, 0x1C(r31)
  addi      r3, r31, 0x20
  addi      r4, r31, 0x28
  rlwinm    r5,r0,3,0,28
  bl        0x1D314

.loc_0x9C:
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r28, 0
  li        r4, 0
  blrl      

.loc_0xB0:
  mr        r3, r30
  bl        0xC0
  li        r3, 0x1

.loc_0xBC:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801F8F0C
 * Size:	000018
 */
void EXIGetState(void)
{
/*
.loc_0x0:
  mulli     r4, r3, 0x38
  lis       r3, 0x803D
  addi      r0, r3, 0x23F0
  add       r3, r0, r4
  lwz       r3, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002D4
 */
void EXIGetID(void)
{
	// UNUSED FUNCTION
}
