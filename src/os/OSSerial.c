

/*
 * --INFO--
 * Address:	801FAFA8
 * Size:	000020
 */
void SIBusy(void)
{
/*
.loc_0x0:
  lis       r3, 0x802E
  lwz       r0, 0x7BC0(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0x18
  li        r3, 0x1
  blr       

.loc_0x18:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FAFC8
 * Size:	000244
 */
void CompleteTransfer(void)
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  lis       r3, 0xCC00
  addi      r6, r3, 0x6400
  stw       r31, 0x14(r1)
  lis       r0, 0x8000
  lis       r4, 0x802E
  stw       r30, 0x10(r1)
  lwz       r3, 0x6438(r3)
  stw       r0, 0x34(r6)
  lwzu      r0, 0x7BC0(r4)
  cmpwi     r0, -0x1
  beq-      .loc_0x234
  addi      r8, r4, 0x8
  lwz       r7, 0xC(r4)
  lwz       r0, 0x8(r4)
  li        r9, 0
  rlwinm    r10,r0,30,2,31
  cmplwi    r10, 0
  ble-      .loc_0xE8
  cmplwi    r10, 0x8
  subi      r5, r10, 0x8
  ble-      .loc_0x220
  addi      r0, r5, 0x7
  rlwinm    r0,r0,29,3,31
  cmplwi    r5, 0
  mtctr     r0
  ble-      .loc_0x220

.loc_0x6C:
  lwz       r0, 0x80(r6)
  addi      r9, r9, 0x8
  stw       r0, 0x0(r7)
  lwz       r0, 0x84(r6)
  stw       r0, 0x4(r7)
  lwz       r0, 0x88(r6)
  stw       r0, 0x8(r7)
  lwz       r0, 0x8C(r6)
  stw       r0, 0xC(r7)
  lwz       r0, 0x90(r6)
  stw       r0, 0x10(r7)
  lwz       r0, 0x94(r6)
  stw       r0, 0x14(r7)
  lwz       r0, 0x98(r6)
  stw       r0, 0x18(r7)
  lwz       r0, 0x9C(r6)
  addi      r6, r6, 0x20
  stw       r0, 0x1C(r7)
  addi      r7, r7, 0x20
  bdnz+     .loc_0x6C
  b         .loc_0x220

.loc_0xC0:
  sub       r0, r10, r9
  cmplw     r9, r10
  mtctr     r0
  bge-      .loc_0xE8

.loc_0xD0:
  lwz       r0, 0x80(r5)
  addi      r5, r5, 0x4
  addi      r9, r9, 0x1
  stw       r0, 0x0(r7)
  addi      r7, r7, 0x4
  bdnz+     .loc_0xD0

.loc_0xE8:
  lwz       r0, 0x0(r8)
  rlwinm.   r5,r0,0,30,31
  beq-      .loc_0x200
  lis       r6, 0xCC00
  addi      r6, r6, 0x6400
  rlwinm    r0,r9,2,0,29
  add       r6, r6, r0
  lwz       r8, 0x80(r6)
  li        r6, 0
  ble-      .loc_0x200
  cmplwi    r5, 0x8
  subi      r9, r5, 0x8
  ble-      .loc_0x1D4
  addi      r0, r9, 0x7
  rlwinm    r0,r0,29,3,31
  cmplwi    r9, 0
  mtctr     r0
  ble-      .loc_0x1D4

.loc_0x130:
  subfic    r0, r6, 0x3
  rlwinm    r9,r0,3,0,28
  addi      r0, r6, 0x1
  srw       r9, r8, r9
  subfic    r0, r0, 0x3
  stb       r9, 0x0(r7)
  rlwinm    r0,r0,3,0,28
  addi      r9, r6, 0x2
  srw       r0, r8, r0
  subfic    r9, r9, 0x3
  stb       r0, 0x1(r7)
  rlwinm    r9,r9,3,0,28
  srw       r30, r8, r9
  neg       r9, r6
  stb       r30, 0x2(r7)
  rlwinm    r10,r9,3,0,28
  addi      r9, r6, 0x4
  srw       r31, r8, r10
  subfic    r9, r9, 0x3
  stb       r31, 0x3(r7)
  rlwinm    r10,r9,3,0,28
  addi      r9, r6, 0x5
  srw       r12, r8, r10
  subfic    r9, r9, 0x3
  stb       r12, 0x4(r7)
  rlwinm    r10,r9,3,0,28
  srw       r11, r8, r10
  addi      r9, r6, 0x6
  stb       r11, 0x5(r7)
  subfic    r10, r9, 0x3
  addi      r9, r6, 0x7
  rlwinm    r10,r10,3,0,28
  srw       r10, r8, r10
  subfic    r9, r9, 0x3
  stb       r10, 0x6(r7)
  rlwinm    r9,r9,3,0,28
  srw       r9, r8, r9
  stb       r9, 0x7(r7)
  addi      r7, r7, 0x8
  addi      r6, r6, 0x8
  bdnz+     .loc_0x130

.loc_0x1D4:
  sub       r0, r5, r6
  cmplw     r6, r5
  mtctr     r0
  bge-      .loc_0x200

.loc_0x1E4:
  subfic    r0, r6, 0x3
  rlwinm    r0,r0,3,0,28
  srw       r0, r8, r0
  stb       r0, 0x0(r7)
  addi      r7, r7, 0x1
  addi      r6, r6, 0x1
  bdnz+     .loc_0x1E4

.loc_0x200:
  lwz       r5, 0x0(r4)
  li        r0, -0x1
  subfic    r5, r5, 0x3
  stw       r0, 0x0(r4)
  rlwinm    r0,r5,3,0,28
  srw       r3, r3, r0
  rlwinm    r3,r3,0,28,31
  b         .loc_0x234

.loc_0x220:
  lis       r5, 0xCC00
  rlwinm    r0,r9,2,0,29
  addi      r5, r5, 0x6400
  add       r5, r5, r0
  b         .loc_0xC0

.loc_0x234:
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void SITransferNext(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FB20C
 * Size:	000118
 */
void SIIntrruptHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x802E
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r24, 0x10(r1)
  addi      r27, r3, 0x7BC0
  mr        r28, r4
  lwz       r31, 0x0(r27)
  bl        -0x264
  lwz       r29, 0x10(r27)
  li        r26, 0
  lis       r4, 0x803D
  stw       r26, 0x10(r27)
  addi      r30, r3, 0
  addi      r25, r31, 0
  addi      r27, r4, 0x2518

.loc_0x40:
  addi      r25, r25, 0x1
  srawi     r0, r25, 0x2
  addze     r0, r0
  rlwinm    r0,r0,2,0,29
  subc      r0, r25, r0
  mr        r25, r0
  rlwinm    r0,r0,5,0,26
  add       r24, r27, r0
  lwz       r0, 0x0(r24)
  cmpwi     r0, -0x1
  beq-      .loc_0xD8
  bl        0x2128
  lwz       r0, 0x18(r24)
  xoris     r5, r3, 0x8000
  lwz       r6, 0x1C(r24)
  xoris     r3, r0, 0x8000
  subc      r0, r4, r6
  subfe     r3, r3, r5
  subfe     r3, r5, r5
  neg.      r3, r3
  bne-      .loc_0xD8
  lwz       r3, 0x0(r24)
  lwz       r4, 0x4(r24)
  lwz       r5, 0x8(r24)
  lwz       r6, 0xC(r24)
  lwz       r7, 0x10(r24)
  lwz       r8, 0x14(r24)
  bl        0xE0
  cmpwi     r3, 0
  beq-      .loc_0xE4
  mulli     r4, r25, 0x28
  lis       r3, 0x803D
  addi      r0, r3, 0x2598
  add       r3, r0, r4
  bl        -0x4EA0
  li        r0, -0x1
  stw       r0, 0x0(r24)
  b         .loc_0xE4

.loc_0xD8:
  addi      r26, r26, 0x1
  cmpwi     r26, 0x4
  blt+      .loc_0x40

.loc_0xE4:
  cmplwi    r29, 0
  beq-      .loc_0x104
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r31, 0
  addi      r4, r30, 0
  addi      r5, r28, 0
  blrl      

.loc_0x104:
  lmw       r24, 0x10(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FB324
 * Size:	000074
 */
void SIInit(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  addi      r6, r3, 0x2518
  li        r5, -0x1
  stwu      r1, -0x8(r1)
  lis       r4, 0xCC00
  li        r0, 0
  stw       r5, 0x60(r6)
  stw       r5, 0x40(r6)
  stw       r5, 0x20(r6)
  stw       r5, 0x0(r6)
  stw       r0, 0x6430(r4)

.loc_0x34:
  addi      r5, r4, 0x6400
  lwzu      r0, 0x34(r5)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x34
  lis       r0, 0x8000
  lis       r3, 0x8020
  stw       r0, 0x0(r5)
  subi      r4, r3, 0x4DF4
  li        r3, 0x14
  bl        -0x23B4
  li        r3, 0x800
  bl        -0x1FE0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FB398
 * Size:	000208
 */
void __SITransfer(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r9, 0x802E
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stmw      r25, 0x2C(r1)
  addi      r26, r3, 0
  addi      r27, r4, 0
  addi      r28, r5, 0
  addi      r29, r6, 0
  addi      r30, r7, 0
  addi      r31, r8, 0
  addi      r25, r9, 0x7BC0
  bl        -0x244C
  lwz       r0, 0x0(r25)
  cmpwi     r0, -0x1
  beq-      .loc_0x4C
  bl        -0x2434
  li        r3, 0
  b         .loc_0x1F4

.loc_0x4C:
  lis       r6, 0xCC00
  rlwinm    r0,r26,3,0,28
  lwz       r7, 0x6438(r6)
  lis       r4, 0xF00
  sraw      r0, r4, r0
  and       r7, r7, r0
  stw       r7, 0x6438(r6)
  addi      r0, r28, 0x3
  rlwinm    r4,r0,30,2,31
  stw       r26, 0x0(r25)
  cmplwi    r4, 0
  li        r5, 0
  stw       r31, 0x10(r25)
  stw       r30, 0x8(r25)
  stw       r29, 0xC(r25)
  ble-      .loc_0x12C
  cmplwi    r4, 0x8
  subi      r7, r4, 0x8
  ble-      .loc_0x1DC
  addi      r0, r7, 0x7
  rlwinm    r0,r0,29,3,31
  cmplwi    r7, 0
  mtctr     r0
  addi      r7, r27, 0
  addi      r6, r6, 0x6400
  ble-      .loc_0x1DC

.loc_0xB4:
  lwz       r0, 0x0(r7)
  addi      r5, r5, 0x8
  stw       r0, 0x80(r6)
  lwz       r0, 0x4(r7)
  stw       r0, 0x84(r6)
  lwz       r0, 0x8(r7)
  stw       r0, 0x88(r6)
  lwz       r0, 0xC(r7)
  stw       r0, 0x8C(r6)
  lwz       r0, 0x10(r7)
  stw       r0, 0x90(r6)
  lwz       r0, 0x14(r7)
  stw       r0, 0x94(r6)
  lwz       r0, 0x18(r7)
  stw       r0, 0x98(r6)
  lwz       r0, 0x1C(r7)
  addi      r7, r7, 0x20
  stw       r0, 0x9C(r6)
  addi      r6, r6, 0x20
  bdnz+     .loc_0xB4
  b         .loc_0x1DC

.loc_0x108:
  sub       r0, r4, r5
  cmplw     r5, r4
  mtctr     r0
  bge-      .loc_0x12C

.loc_0x118:
  lwz       r0, 0x0(r6)
  addi      r6, r6, 0x4
  stw       r0, 0x80(r7)
  addi      r7, r7, 0x4
  bdnz+     .loc_0x118

.loc_0x12C:
  li        r4, 0
  stw       r4, 0x24(r1)
  li        r5, 0x1
  cmplwi    r31, 0
  lbz       r0, 0x24(r1)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0x24(r1)
  beq-      .loc_0x150
  b         .loc_0x154

.loc_0x150:
  mr        r5, r4

.loc_0x154:
  lbz       r0, 0x24(r1)
  rlwimi    r0,r5,6,25,25
  cmplwi    r28, 0x80
  stb       r0, 0x24(r1)
  bne-      .loc_0x170
  li        r0, 0
  b         .loc_0x174

.loc_0x170:
  mr        r0, r28

.loc_0x174:
  rlwinm    r4,r0,0,24,31
  lbz       r0, 0x25(r1)
  rlwimi    r0,r4,0,25,31
  cmplwi    r30, 0x80
  stb       r0, 0x25(r1)
  bne-      .loc_0x194
  li        r0, 0
  b         .loc_0x198

.loc_0x194:
  mr        r0, r30

.loc_0x198:
  rlwinm    r4,r0,0,24,31
  lbz       r0, 0x26(r1)
  rlwimi    r0,r4,0,25,31
  stb       r0, 0x26(r1)
  li        r5, 0x1
  lis       r4, 0xCC00
  lbz       r0, 0x27(r1)
  rlwimi    r0,r26,1,29,30
  stb       r0, 0x27(r1)
  lbz       r0, 0x27(r1)
  rlwimi    r0,r5,0,31,31
  stb       r0, 0x27(r1)
  lwz       r0, 0x24(r1)
  stw       r0, 0x6434(r4)
  bl        -0x25C4
  li        r3, 0x1
  b         .loc_0x1F4

.loc_0x1DC:
  lis       r6, 0xCC00
  rlwinm    r0,r5,2,0,29
  addi      r7, r6, 0x6400
  add       r6, r27, r0
  add       r7, r7, r0
  b         .loc_0x108

.loc_0x1F4:
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
 * Size:	000108
 */
void SISync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FB5A0
 * Size:	000010
 */
void SIGetStatus(void)
{
/*
.loc_0x0:
  lis       r3, 0xCC00
  addi      r3, r3, 0x6400
  lwz       r3, 0x38(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801FB5B0
 * Size:	000014
 */
void SISetCommand(void)
{
/*
.loc_0x0:
  mulli     r0, r3, 0xC
  lis       r3, 0xCC00
  addi      r3, r3, 0x6400
  stwx      r4, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void SIGetCommand(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FB5C4
 * Size:	000010
 */
void SITransferCommands(void)
{
/*
.loc_0x0:
  lis       r3, 0xCC00
  lis       r0, 0x8000
  stw       r0, 0x6438(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801FB5D4
 * Size:	000060
 */
void SISetXY(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm    r0,r4,8,0,23
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  rlwinm    r31,r3,16,0,15
  or        r31, r31, r0
  bl        -0x2674
  lis       r4, 0x802E
  addi      r4, r4, 0x7BC0
  lwzu      r0, 0x4(r4)
  rlwinm    r0,r0,0,24,5
  stw       r0, 0x0(r4)
  lwz       r0, 0x0(r4)
  or        r0, r0, r31
  stw       r0, 0x0(r4)
  lwz       r31, 0x0(r4)
  bl        -0x2674
  lwz       r0, 0x1C(r1)
  mr        r3, r31
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FB634
 * Size:	00009C
 */
void SIEnablePolling(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  bne-      .loc_0x28
  lis       r3, 0x802E
  addi      r3, r3, 0x7BC0
  lwz       r3, 0x4(r3)
  b         .loc_0x88

.loc_0x28:
  bl        -0x26E0
  lis       r4, 0x802E
  addi      r4, r4, 0x7BC0
  rlwinm    r31,r31,8,24,31
  lwz       r0, 0x4(r4)
  addi      r5, r4, 0x4
  rlwinm    r4,r31,28,28,31
  andc      r0, r0, r4
  stw       r0, 0x0(r5)
  oris      r0, r4, 0x3FF
  ori       r0, r0, 0xFFF0
  and       r31, r31, r0
  lwz       r0, 0x0(r5)
  rlwinm    r31,r31,0,24,5
  or        r0, r0, r31
  stw       r0, 0x0(r5)
  lis       r4, 0xCC00
  addi      r4, r4, 0x6400
  lwz       r31, 0x0(r5)
  lis       r0, 0x8000
  stw       r0, 0x38(r4)
  stw       r31, 0x30(r4)
  bl        -0x2710
  mr        r3, r31

.loc_0x88:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FB6D0
 * Size:	00006C
 */
void SIDisablePolling(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  bne-      .loc_0x28
  lis       r3, 0x802E
  addi      r3, r3, 0x7BC0
  lwz       r3, 0x4(r3)
  b         .loc_0x58

.loc_0x28:
  bl        -0x277C
  lis       r4, 0x802E
  addi      r4, r4, 0x7BC0
  lwz       r0, 0x4(r4)
  rlwinm    r31,r31,8,24,27
  addi      r5, r4, 0x4
  lis       r4, 0xCC00
  andc      r31, r0, r31
  stw       r31, 0x6430(r4)
  stw       r31, 0x0(r5)
  bl        -0x277C
  mr        r3, r31

.loc_0x58:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FB73C
 * Size:	000024
 */
void SIGetResponse(void)
{
/*
.loc_0x0:
  mulli     r5, r3, 0xC
  lis       r3, 0xCC00
  addi      r0, r3, 0x6400
  add       r3, r0, r5
  lwz       r0, 0x4(r3)
  stw       r0, 0x0(r4)
  lwz       r0, 0x8(r3)
  stw       r0, 0x4(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	801FB760
 * Size:	00008C
 */
void AlarmHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  addi      r0, r4, 0x2598
  lis       r4, 0x6666
  sub       r0, r3, r0
  stwu      r1, -0x20(r1)
  addi      r3, r4, 0x6667
  mulhw     r0, r3, r0
  stw       r31, 0x1C(r1)
  srawi     r0, r0, 0x4
  rlwinm    r3,r0,1,31,31
  add       r0, r0, r3
  lis       r3, 0x803D
  rlwinm    r4,r0,5,0,26
  addi      r0, r3, 0x2518
  add       r31, r0, r4
  lwz       r3, 0x0(r31)
  cmpwi     r3, -0x1
  beq-      .loc_0x78
  lwz       r4, 0x4(r31)
  lwz       r5, 0x8(r31)
  lwz       r6, 0xC(r31)
  lwz       r7, 0x10(r31)
  lwz       r8, 0x14(r31)
  bl        -0x42C
  cmpwi     r3, 0
  beq-      .loc_0x78
  li        r0, -0x1
  stw       r0, 0x0(r31)

.loc_0x78:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FB7EC
 * Size:	00013C
 */
void SITransfer(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stmw      r22, 0x28(r1)
  addi      r22, r3, 0
  lis       r3, 0x803D
  rlwinm    r11,r22,5,0,26
  addi      r0, r3, 0x2518
  addi      r23, r4, 0
  addi      r24, r5, 0
  addi      r25, r6, 0
  addi      r26, r7, 0
  addi      r27, r8, 0
  addi      r29, r9, 0
  addi      r28, r10, 0
  add       r31, r0, r11
  bl        -0x28B0
  lwz       r0, 0x0(r31)
  addi      r30, r3, 0
  cmpwi     r0, -0x1
  beq-      .loc_0x64
  mr        r3, r30
  bl        -0x28A0
  li        r3, 0
  b         .loc_0x128

.loc_0x64:
  bl        0x1B50
  li        r0, 0
  xor       r5, r28, r0
  xor       r0, r29, r0
  or.       r0, r5, r0
  bne-      .loc_0x84
  addi      r28, r4, 0
  addi      r29, r3, 0

.loc_0x84:
  xoris     r5, r3, 0x8000
  xoris     r3, r29, 0x8000
  subc      r0, r4, r28
  subfe     r3, r3, r5
  subfe     r3, r5, r5
  neg.      r3, r3
  beq-      .loc_0xC8
  mulli     r5, r22, 0x28
  lis       r3, 0x803D
  addi      r0, r3, 0x2598
  lis       r4, 0x8020
  add       r3, r0, r5
  subi      r7, r4, 0x48A0
  addi      r6, r28, 0
  addi      r5, r29, 0
  bl        -0x54DC
  b         .loc_0xFC

.loc_0xC8:
  addi      r3, r22, 0
  addi      r4, r23, 0
  addi      r5, r24, 0
  addi      r6, r25, 0
  addi      r7, r26, 0
  addi      r8, r27, 0
  bl        -0x534
  cmpwi     r3, 0
  beq-      .loc_0xFC
  mr        r3, r30
  bl        -0x2938
  li        r3, 0x1
  b         .loc_0x128

.loc_0xFC:
  stw       r22, 0x0(r31)
  mr        r3, r30
  stw       r23, 0x4(r31)
  stw       r24, 0x8(r31)
  stw       r25, 0xC(r31)
  stw       r26, 0x10(r31)
  stw       r27, 0x14(r31)
  stw       r28, 0x1C(r31)
  stw       r29, 0x18(r31)
  bl        -0x2968
  li        r3, 0x1

.loc_0x128:
  lmw       r22, 0x28(r1)
  lwz       r0, 0x54(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}