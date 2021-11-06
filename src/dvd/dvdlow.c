

/*
 * --INFO--
 * Address:	801FE12C
 * Size:	000040
 */
void __DVDInitWA(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  li        r0, 0
  li        r4, 0
  stwu      r1, -0x8(r1)
  stw       r0, 0x3294(r13)
  li        r0, -0x1
  stw       r0, 0x3020(r3)
  li        r3, 0
  bl        0xDE8
  bl        -0x8098
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void ProcessNextCommand(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FE16C
 * Size:	0002F4
 */
void __DVDInterruptHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x2E8(r1)
  stw       r31, 0x2E4(r1)
  stw       r30, 0x2E0(r1)
  addi      r30, r3, 0x3020
  addi      r3, r30, 0x68
  stw       r29, 0x2DC(r1)
  li        r29, 0
  stw       r28, 0x2D8(r1)
  addi      r28, r4, 0
  bl        -0x7D68
  lwz       r0, 0x3290(r13)
  cmpwi     r0, 0
  beq-      .loc_0x7C
  bl        -0xDEC
  stw       r4, 0x3284(r13)
  li        r0, 0
  stw       r3, 0x3280(r13)
  stw       r0, 0x2A08(r13)
  lwz       r0, 0xC4(r30)
  stw       r0, 0xB8(r30)
  lwz       r0, 0xC8(r30)
  stw       r0, 0xBC(r30)
  lwz       r0, 0xCC(r30)
  stw       r0, 0xC0(r30)
  lwz       r0, 0x3250(r13)
  cmpwi     r0, 0x1
  bne-      .loc_0x7C
  ori       r29, r29, 0x8

.loc_0x7C:
  li        r0, 0
  stw       r0, 0x3290(r13)
  lis       r3, 0xCC00
  stw       r0, 0x3250(r13)
  lwz       r0, 0x6000(r3)
  andi.     r4, r0, 0x2A
  andi.     r3, r0, 0x54
  rlwinm    r0,r4,1,0,30
  and       r3, r3, r0
  rlwinm.   r0,r3,0,25,25
  beq-      .loc_0xAC
  ori       r29, r29, 0x8

.loc_0xAC:
  rlwinm.   r0,r3,0,27,27
  beq-      .loc_0xB8
  ori       r29, r29, 0x1

.loc_0xB8:
  rlwinm.   r0,r3,0,29,29
  beq-      .loc_0xC4
  ori       r29, r29, 0x2

.loc_0xC4:
  cmplwi    r29, 0
  beq-      .loc_0xD4
  li        r0, 0
  stw       r0, 0x3268(r13)

.loc_0xD4:
  or        r0, r3, r4
  lis       r31, 0xCC00
  stw       r0, 0x6000(r31)
  lwz       r0, 0x3268(r13)
  cmplwi    r0, 0
  beq-      .loc_0x184
  bl        -0xE98
  lis       r5, 0x8000
  lwz       r7, 0x3260(r13)
  lwz       r6, 0xF8(r5)
  lis       r5, 0x1062
  addi      r5, r5, 0x4DD3
  lwz       r8, 0x3264(r13)
  rlwinm    r6,r6,30,2,31
  mulhwu    r5, r5, r6
  rlwinm    r5,r5,26,6,31
  mulli     r5, r5, 0xC8
  subc      r6, r4, r8
  subfe     r3, r7, r3
  li        r0, 0
  xoris     r4, r3, 0x8000
  xoris     r3, r0, 0x8000
  subc      r0, r6, r5
  subfe     r3, r3, r4
  subfe     r3, r4, r4
  neg.      r3, r3
  beq-      .loc_0x184
  lwzu      r0, 0x6004(r31)
  rlwinm    r3,r0,0,29,29
  rlwinm    r0,r0,1,29,29
  and       r0, r3, r0
  rlwinm.   r0,r0,0,29,29
  beq-      .loc_0x178
  lwz       r12, 0x325C(r13)
  cmplwi    r12, 0
  beq-      .loc_0x170
  mtlr      r12
  li        r3, 0x4
  blrl      

.loc_0x170:
  li        r0, 0
  stw       r0, 0x325C(r13)

.loc_0x178:
  lwz       r0, 0x0(r31)
  stw       r0, 0x0(r31)
  b         .loc_0x1D8

.loc_0x184:
  lwz       r0, 0x326C(r13)
  cmpwi     r0, 0
  beq-      .loc_0x1CC
  lis       r3, 0xCC00
  addi      r5, r3, 0x6000
  lwzu      r0, 0x4(r5)
  rlwinm    r4,r0,0,30,30
  rlwinm    r3,r0,0,29,29
  rlwinm    r0,r0,1,29,29
  and       r3, r3, r0
  rlwinm.   r0,r3,0,29,29
  beq-      .loc_0x1B8
  ori       r29, r29, 0x4

.loc_0x1B8:
  or        r0, r3, r4
  stw       r0, 0x0(r5)
  li        r0, 0
  stw       r0, 0x326C(r13)
  b         .loc_0x1D8

.loc_0x1CC:
  lis       r3, 0xCC00
  li        r0, 0
  stw       r0, 0x6004(r3)

.loc_0x1D8:
  rlwinm.   r0,r29,0,28,28
  beq-      .loc_0x1F0
  lwz       r0, 0x3270(r13)
  cmpwi     r0, 0
  bne-      .loc_0x1F0
  rlwinm    r29,r29,0,29,27

.loc_0x1F0:
  rlwinm.   r0,r29,0,31,31
  beq-      .loc_0x274
  lwz       r0, 0x3294(r13)
  mulli     r0, r0, 0x14
  lwzx      r3, r30, r0
  cmpwi     r3, 0x1
  bne-      .loc_0x238
  lwz       r3, 0x3294(r13)
  add       r6, r30, r0
  addi      r0, r3, 0x1
  stw       r0, 0x3294(r13)
  lwz       r3, 0x4(r6)
  lwz       r4, 0x8(r6)
  lwz       r5, 0xC(r6)
  lwz       r6, 0x10(r6)
  bl        0x1BC
  li        r0, 0x1
  b         .loc_0x268

.loc_0x238:
  cmpwi     r3, 0x2
  bne-      .loc_0x264
  lwz       r3, 0x3294(r13)
  add       r4, r30, r0
  addi      r0, r3, 0x1
  stw       r0, 0x3294(r13)
  lwz       r3, 0xC(r4)
  lwz       r4, 0x10(r4)
  bl        0x5B8
  li        r0, 0x1
  b         .loc_0x268

.loc_0x264:
  li        r0, 0

.loc_0x268:
  cmpwi     r0, 0
  beq-      .loc_0x284
  b         .loc_0x2D4

.loc_0x274:
  li        r0, -0x1
  stw       r0, 0x0(r30)
  li        r0, 0
  stw       r0, 0x3294(r13)

.loc_0x284:
  addi      r3, r1, 0x10
  bl        -0x6FB8
  addi      r3, r1, 0x10
  bl        -0x7188
  cmplwi    r29, 0
  beq-      .loc_0x2C4
  lwz       r12, 0x3258(r13)
  li        r0, 0
  cmplwi    r12, 0
  stw       r0, 0x3258(r13)
  beq-      .loc_0x2BC
  mtlr      r12
  addi      r3, r29, 0
  blrl      

.loc_0x2BC:
  li        r0, 0
  stw       r0, 0x3270(r13)

.loc_0x2C4:
  addi      r3, r1, 0x10
  bl        -0x6FF8
  mr        r3, r28
  bl        -0x71C8

.loc_0x2D4:
  lwz       r0, 0x2EC(r1)
  lwz       r31, 0x2E4(r1)
  lwz       r30, 0x2E0(r1)
  mtlr      r0
  lwz       r29, 0x2DC(r1)
  lwz       r28, 0x2D8(r1)
  addi      r1, r1, 0x2E8
  blr
*/
}

/*
 * --INFO--
 * Address:	801FE460
 * Size:	000084
 */
void AlarmHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  addi      r4, r3, 0x3020
  stwu      r1, -0x8(r1)
  lwz       r0, 0x3294(r13)
  mulli     r0, r0, 0x14
  lwzx      r3, r4, r0
  cmpwi     r3, 0x1
  bne-      .loc_0x50
  lwz       r3, 0x3294(r13)
  add       r6, r4, r0
  addi      r0, r3, 0x1
  stw       r0, 0x3294(r13)
  lwz       r3, 0x4(r6)
  lwz       r4, 0x8(r6)
  lwz       r5, 0xC(r6)
  lwz       r6, 0x10(r6)
  bl        0xAC
  b         .loc_0x74

.loc_0x50:
  cmpwi     r3, 0x2
  bne-      .loc_0x74
  lwz       r3, 0x3294(r13)
  add       r4, r4, r0
  addi      r0, r3, 0x1
  stw       r0, 0x3294(r13)
  lwz       r3, 0xC(r4)
  lwz       r4, 0x10(r4)
  bl        0x4AC

.loc_0x74:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FE4E4
 * Size:	000070
 */
void AlarmHandlerForTimeout(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x400
  stw       r0, 0x4(r1)
  stwu      r1, -0x2E0(r1)
  stw       r31, 0x2DC(r1)
  addi      r31, r4, 0
  bl        -0x51E0
  addi      r3, r1, 0x10
  bl        -0x70C8
  addi      r3, r1, 0x10
  bl        -0x7298
  lwz       r12, 0x3258(r13)
  li        r0, 0
  cmplwi    r12, 0
  stw       r0, 0x3258(r13)
  beq-      .loc_0x4C
  mtlr      r12
  li        r3, 0x10
  blrl      

.loc_0x4C:
  addi      r3, r1, 0x10
  bl        -0x70F8
  mr        r3, r31
  bl        -0x72C8
  lwz       r0, 0x2E4(r1)
  lwz       r31, 0x2DC(r1)
  addi      r1, r1, 0x2E0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void SetTimeoutAlarm(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FE554
 * Size:	000110
 */
void Read(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r5, 0
  stw       r29, 0x1C(r1)
  addi      r29, r4, 0
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  stw       r0, 0x3250(r13)
  li        r0, 0x1
  stw       r6, 0x3258(r13)
  lis       r6, 0x803D
  addi      r31, r6, 0x3020
  stw       r0, 0x3290(r13)
  bl        -0x11D8
  stw       r4, 0x328C(r13)
  lis       r4, 0xCC00
  lis       r0, 0xA0
  stw       r3, 0x3288(r13)
  addi      r4, r4, 0x6000
  lis       r3, 0xA800
  stw       r3, 0x8(r4)
  rlwinm    r3,r30,30,2,31
  cmplw     r29, r0
  stw       r3, 0xC(r4)
  li        r0, 0x3
  stw       r29, 0x10(r4)
  stw       r28, 0x14(r4)
  stw       r29, 0x18(r4)
  stw       r29, 0x3254(r13)
  stw       r0, 0x1C(r4)
  ble-      .loc_0xC0
  lis       r3, 0x8000
  lwz       r0, 0xF8(r3)
  addi      r3, r31, 0x68
  rlwinm    r0,r0,30,2,31
  mulli     r30, r0, 0x14
  bl        -0x84E8
  lis       r3, 0x8020
  subi      r7, r3, 0x1B1C
  addi      r6, r30, 0
  addi      r3, r31, 0x68
  li        r5, 0
  bl        -0x82A4
  b         .loc_0xF0

.loc_0xC0:
  lis       r3, 0x8000
  lwz       r0, 0xF8(r3)
  addi      r3, r31, 0x68
  rlwinm    r0,r0,30,2,31
  mulli     r30, r0, 0xA
  bl        -0x851C
  lis       r3, 0x8020
  subi      r7, r3, 0x1B1C
  addi      r6, r30, 0
  addi      r3, r31, 0x68
  li        r5, 0
  bl        -0x82D8

.loc_0xF0:
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
 * Address:	........
 * Size:	000038
 */
void AudioBufferOn(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void HitCache(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void DoJustRead(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FE664
 * Size:	000080
 */
void SeekTwiceBeforeRead(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x803D
  stw       r0, 0x4(r1)
  rlwinm.   r8,r5,0,0,16
  addi      r9, r7, 0x3020
  stwu      r1, -0x8(r1)
  bne-      .loc_0x24
  li        r10, 0
  b         .loc_0x2C

.loc_0x24:
  lwz       r0, 0x3278(r13)
  add       r10, r8, r0

.loc_0x2C:
  li        r0, 0x2
  stw       r0, 0x0(r9)
  li        r8, 0x1
  li        r7, -0x1
  stw       r10, 0xC(r9)
  li        r0, 0
  stw       r6, 0x10(r9)
  stw       r8, 0x14(r9)
  stw       r3, 0x18(r9)
  mr        r3, r10
  stw       r4, 0x1C(r9)
  mr        r4, r6
  stw       r5, 0x20(r9)
  stw       r6, 0x24(r9)
  stw       r7, 0x28(r9)
  stw       r0, 0x3294(r13)
  bl        0x2AC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void WaitBeforeRead(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FE6E4
 * Size:	000298
 */
void DVDLowRead(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0xCC00
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stmw      r22, 0x18(r1)
  addi      r25, r4, 0
  addi      r4, r7, 0x6000
  lis       r7, 0x803D
  addi      r31, r7, 0x3020
  addi      r24, r3, 0
  addi      r26, r5, 0
  addi      r30, r31, 0xCC
  mr        r27, r6
  stw       r25, 0x18(r4)
  stw       r24, 0xC4(r31)
  stw       r25, 0xC8(r31)
  stw       r26, 0xCC(r31)
  lwz       r0, 0x3274(r13)
  cmplwi    r0, 0
  bne-      .loc_0x78
  li        r0, -0x1
  stw       r0, 0x0(r31)
  li        r0, 0
  addi      r3, r24, 0
  stw       r0, 0x3294(r13)
  addi      r4, r25, 0
  addi      r5, r26, 0
  addi      r6, r27, 0
  bl        -0x200
  b         .loc_0x280

.loc_0x78:
  lwz       r0, 0x3274(r13)
  cmplwi    r0, 0x1
  bne-      .loc_0x280
  lwz       r0, 0x2A08(r13)
  cmpwi     r0, 0
  beq-      .loc_0xA8
  addi      r3, r24, 0
  addi      r4, r25, 0
  addi      r5, r26, 0
  addi      r6, r27, 0
  bl        -0x120
  b         .loc_0x280

.loc_0xA8:
  addi      r29, r31, 0xBC
  lwz       r0, 0x0(r30)
  addi      r28, r31, 0xC0
  lwz       r3, 0xBC(r31)
  lwz       r4, 0xC0(r31)
  rlwinm    r23,r0,17,15,31
  subi      r0, r3, 0x1
  add       r0, r4, r0
  rlwinm    r22,r0,17,15,31
  bl        0x354C
  lbz       r0, 0x8(r3)
  cmplwi    r0, 0
  beq-      .loc_0xE4
  li        r0, 0x1
  b         .loc_0xE8

.loc_0xE4:
  li        r0, 0

.loc_0xE8:
  cmpwi     r0, 0
  beq-      .loc_0xF8
  li        r3, 0x5
  b         .loc_0xFC

.loc_0xF8:
  li        r3, 0xF

.loc_0xFC:
  subi      r0, r22, 0x2
  cmplw     r23, r0
  bgt-      .loc_0x118
  addi      r0, r3, 0x3
  add       r0, r22, r0
  cmplw     r23, r0
  bge-      .loc_0x120

.loc_0x118:
  li        r0, 0x1
  b         .loc_0x124

.loc_0x120:
  li        r0, 0

.loc_0x124:
  cmpwi     r0, 0
  bne-      .loc_0x154
  li        r0, -0x1
  stw       r0, 0x0(r31)
  li        r0, 0
  addi      r3, r24, 0
  stw       r0, 0x3294(r13)
  addi      r4, r25, 0
  addi      r5, r26, 0
  addi      r6, r27, 0
  bl        -0x2DC
  b         .loc_0x280

.loc_0x154:
  lwz       r3, 0x0(r29)
  lwz       r4, 0x0(r28)
  subi      r3, r3, 0x1
  lwz       r0, 0x0(r30)
  add       r3, r4, r3
  rlwinm    r3,r3,17,15,31
  rlwinm    r4,r0,17,15,31
  cmplw     r3, r4
  beq-      .loc_0x184
  addi      r0, r3, 0x1
  cmplw     r0, r4
  bne-      .loc_0x26C

.loc_0x184:
  bl        -0x14A8
  lis       r5, 0x8000
  lwz       r8, 0x3280(r13)
  lwz       r0, 0xF8(r5)
  lis       r5, 0x1062
  lwz       r9, 0x3284(r13)
  li        r6, 0
  rlwinm    r7,r0,30,2,31
  addi      r0, r5, 0x4DD3
  mulhwu    r0, r0, r7
  rlwinm    r0,r0,26,6,31
  subc      r9, r4, r9
  subfe     r8, r8, r3
  mulli     r5, r0, 0x5
  xoris     r4, r6, 0x8000
  xoris     r3, r8, 0x8000
  subc      r0, r5, r9
  subfe     r3, r3, r4
  subfe     r3, r4, r4
  neg.      r3, r3
  beq-      .loc_0x1FC
  li        r0, -0x1
  stw       r0, 0x0(r31)
  addi      r3, r24, 0
  addi      r4, r25, 0
  stw       r6, 0x3294(r13)
  addi      r5, r26, 0
  addi      r6, r27, 0
  bl        -0x384
  b         .loc_0x280

.loc_0x1FC:
  li        r0, 0x1
  stw       r0, 0x0(r31)
  lis       r3, 0x431C
  subi      r0, r3, 0x217D
  stw       r24, 0x4(r31)
  mulhwu    r0, r0, r7
  stw       r25, 0x8(r31)
  stw       r26, 0xC(r31)
  rlwinm    r0,r0,17,15,31
  mulli     r3, r0, 0x1F4
  stw       r27, 0x10(r31)
  li        r0, -0x1
  stw       r0, 0x14(r31)
  subc      r5, r5, r9
  subfe     r4, r8, r6
  rlwinm    r0,r3,29,3,31
  stw       r6, 0x3294(r13)
  addc      r23, r5, r0
  adde      r22, r4, r6
  addi      r3, r31, 0x40
  bl        -0x8824
  lis       r3, 0x8020
  subi      r7, r3, 0x1BA0
  addi      r6, r23, 0
  addi      r5, r22, 0
  addi      r3, r31, 0x40
  bl        -0x85E0
  b         .loc_0x280

.loc_0x26C:
  addi      r3, r24, 0
  addi      r4, r25, 0
  addi      r5, r26, 0
  addi      r6, r27, 0
  bl        -0x2FC

.loc_0x280:
  lmw       r22, 0x18(r1)
  li        r3, 0x1
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FE97C
 * Size:	000094
 */
void DVDLowSeek(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r4, 0x3258(r13)
  lis       r4, 0xCC00
  addi      r4, r4, 0x6000
  stw       r0, 0x3250(r13)
  lis       r0, 0xAB00
  stw       r0, 0x8(r4)
  rlwinm    r0,r3,30,2,31
  lis       r3, 0x803D
  stw       r0, 0xC(r4)
  li        r0, 0x1
  addi      r31, r3, 0x3088
  stw       r0, 0x1C(r4)
  lis       r4, 0x8000
  addi      r3, r31, 0
  lwz       r0, 0xF8(r4)
  rlwinm    r0,r0,30,2,31
  mulli     r30, r0, 0xA
  bl        -0x88CC
  lis       r3, 0x8020
  subi      r7, r3, 0x1B1C
  addi      r3, r31, 0
  addi      r6, r30, 0
  li        r5, 0
  bl        -0x8688
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
 * Address:	801FEA10
 * Size:	00002C
 */
void DVDLowWaitCoverClose(void)
{
/*
.loc_0x0:
  li        r0, 0x1
  stw       r3, 0x3258(r13)
  lis       r3, 0xCC00
  stw       r0, 0x326C(r13)
  li        r0, 0
  addi      r4, r3, 0x6000
  stw       r0, 0x3250(r13)
  li        r0, 0x2
  li        r3, 0x1
  stw       r0, 0x4(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	801FEA3C
 * Size:	0000A4
 */
void DVDLowReadDiskID(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r8, 0
  stw       r0, 0x4(r1)
  lis       r5, 0xA800
  addi      r0, r5, 0x40
  stwu      r1, -0x18(r1)
  li        r6, 0x20
  lis       r5, 0x8000
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r4, 0x3258(r13)
  lis       r4, 0xCC00
  addi      r7, r4, 0x6000
  stw       r8, 0x3250(r13)
  stw       r0, 0x6008(r4)
  lis       r4, 0x803D
  li        r0, 0x3
  stw       r8, 0xC(r7)
  addi      r31, r4, 0x3088
  stw       r6, 0x10(r7)
  stw       r3, 0x14(r7)
  mr        r3, r31
  stw       r6, 0x18(r7)
  stw       r0, 0x1C(r7)
  lwz       r0, 0xF8(r5)
  rlwinm    r0,r0,30,2,31
  mulli     r30, r0, 0xA
  bl        -0x899C
  lis       r3, 0x8020
  subi      r7, r3, 0x1B1C
  addi      r3, r31, 0
  addi      r6, r30, 0
  li        r5, 0
  bl        -0x8758
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
 * Address:	801FEAE0
 * Size:	00008C
 */
void DVDLowStopMotor(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r3, 0x3258(r13)
  lis       r3, 0xCC00
  addi      r4, r3, 0x6000
  stw       r0, 0x3250(r13)
  lis       r0, 0xE300
  stw       r0, 0x6008(r3)
  li        r0, 0x1
  lis       r3, 0x803D
  stw       r0, 0x1C(r4)
  lis       r4, 0x8000
  addi      r31, r3, 0x3088
  lwz       r0, 0xF8(r4)
  addi      r3, r31, 0
  rlwinm    r0,r0,30,2,31
  mulli     r30, r0, 0xA
  bl        -0x8A28
  lis       r3, 0x8020
  subi      r7, r3, 0x1B1C
  addi      r3, r31, 0
  addi      r6, r30, 0
  li        r5, 0
  bl        -0x87E4
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
 * Address:	801FEB6C
 * Size:	00008C
 */
void DVDLowRequestError(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r3, 0x3258(r13)
  lis       r3, 0xCC00
  addi      r4, r3, 0x6000
  stw       r0, 0x3250(r13)
  lis       r0, 0xE000
  stw       r0, 0x6008(r3)
  li        r0, 0x1
  lis       r3, 0x803D
  stw       r0, 0x1C(r4)
  lis       r4, 0x8000
  addi      r31, r3, 0x3088
  lwz       r0, 0xF8(r4)
  addi      r3, r31, 0
  rlwinm    r0,r0,30,2,31
  mulli     r30, r0, 0xA
  bl        -0x8AB4
  lis       r3, 0x8020
  subi      r7, r3, 0x1B1C
  addi      r3, r31, 0
  addi      r6, r30, 0
  li        r5, 0
  bl        -0x8870
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
 * Address:	801FEBF8
 * Size:	00009C
 */
void DVDLowInquiry(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r6, 0x20
  stw       r0, 0x4(r1)
  li        r0, 0
  lis       r5, 0x8000
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r4, 0x3258(r13)
  lis       r4, 0xCC00
  addi      r7, r4, 0x6000
  stw       r0, 0x3250(r13)
  lis       r0, 0x1200
  stw       r0, 0x6008(r4)
  lis       r4, 0x803D
  li        r0, 0x3
  stw       r6, 0x10(r7)
  addi      r31, r4, 0x3088
  stw       r3, 0x14(r7)
  addi      r3, r31, 0
  stw       r6, 0x18(r7)
  stw       r0, 0x1C(r7)
  lwz       r0, 0xF8(r5)
  rlwinm    r0,r0,30,2,31
  mulli     r30, r0, 0xA
  bl        -0x8B50
  lis       r3, 0x8020
  subi      r7, r3, 0x1B1C
  addi      r3, r31, 0
  addi      r6, r30, 0
  li        r5, 0
  bl        -0x890C
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
 * Address:	801FEC94
 * Size:	000098
 */
void DVDLowAudioStream(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r6, 0x3258(r13)
  lis       r6, 0xCC00
  addi      r6, r6, 0x6000
  stw       r0, 0x3250(r13)
  oris      r0, r3, 0xE100
  lis       r3, 0x803D
  stw       r0, 0x8(r6)
  rlwinm    r0,r5,30,2,31
  addi      r31, r3, 0x3088
  stw       r0, 0xC(r6)
  li        r0, 0x1
  addi      r3, r31, 0
  stw       r4, 0x10(r6)
  lis       r4, 0x8000
  stw       r0, 0x1C(r6)
  lwz       r0, 0xF8(r4)
  rlwinm    r0,r0,30,2,31
  mulli     r30, r0, 0xA
  bl        -0x8BE8
  lis       r3, 0x8020
  subi      r7, r3, 0x1B1C
  addi      r3, r31, 0
  addi      r6, r30, 0
  li        r5, 0
  bl        -0x89A4
  lwz       r0, 0x24(r1)
  li        r3, 0x1
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801FED2C
 * Size:	00008C
 */
void DVDLowRequestAudioStatus(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r4, 0x3258(r13)
  lis       r4, 0xCC00
  addi      r4, r4, 0x6000
  stw       r0, 0x3250(r13)
  oris      r0, r3, 0xE200
  lis       r3, 0x803D
  stw       r0, 0x8(r4)
  li        r0, 0x1
  addi      r31, r3, 0x3088
  stw       r0, 0x1C(r4)
  lis       r4, 0x8000
  addi      r3, r31, 0
  lwz       r0, 0xF8(r4)
  rlwinm    r0,r0,30,2,31
  mulli     r30, r0, 0xA
  bl        -0x8C74
  lis       r3, 0x8020
  subi      r7, r3, 0x1B1C
  addi      r3, r31, 0
  addi      r6, r30, 0
  li        r5, 0
  bl        -0x8A30
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
 * Address:	801FEDB8
 * Size:	00009C
 */
void DVDLowAudioBufferConfig(void)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r3, 0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r5, 0x3258(r13)
  stw       r0, 0x3250(r13)
  beq-      .loc_0x2C
  lis       r0, 0x1

.loc_0x2C:
  oris      r0, r0, 0xE400
  lis       r3, 0xCC00
  or        r0, r4, r0
  addi      r3, r3, 0x6000
  stw       r0, 0x8(r3)
  li        r0, 0x1
  lis       r4, 0x8000
  stw       r0, 0x1C(r3)
  lis       r3, 0x803D
  addi      r31, r3, 0x3088
  lwz       r0, 0xF8(r4)
  addi      r3, r31, 0
  rlwinm    r0,r0,30,2,31
  mulli     r30, r0, 0xA
  bl        -0x8D10
  lis       r3, 0x8020
  subi      r7, r3, 0x1B1C
  addi      r3, r31, 0
  addi      r6, r30, 0
  li        r5, 0
  bl        -0x8ACC
  lwz       r0, 0x24(r1)
  li        r3, 0x1
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801FEE54
 * Size:	0000BC
 */
void DVDLowReset(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0xCC00
  stw       r0, 0x4(r1)
  li        r0, 0x2
  stwu      r1, -0x20(r1)
  stmw      r26, 0x8(r1)
  addi      r31, r4, 0x3000
  stw       r0, 0x6004(r4)
  lwz       r30, 0x3024(r4)
  rlwinm    r0,r30,0,30,28
  ori       r0, r0, 0x1
  stwu      r0, 0x24(r31)
  bl        -0x1AC4
  lis       r5, 0x8000
  lwz       r0, 0xF8(r5)
  lis       r5, 0x431C
  subi      r5, r5, 0x217D
  rlwinm    r0,r0,30,2,31
  mulhwu    r0, r5, r0
  rlwinm    r0,r0,17,15,31
  mulli     r0, r0, 0xC
  addi      r26, r4, 0
  addi      r27, r3, 0
  rlwinm    r28,r0,29,3,31
  li        r29, 0

.loc_0x64:
  bl        -0x1AF8
  subc      r5, r4, r26
  subfe     r0, r27, r3
  xoris     r4, r0, 0x8000
  xoris     r3, r29, 0x8000
  subc      r0, r5, r28
  subfe     r3, r3, r4
  subfe     r3, r4, r4
  neg.      r3, r3
  bne+      .loc_0x64
  ori       r0, r30, 0x5
  stw       r0, 0x0(r31)
  li        r0, 0x1
  stw       r0, 0x3268(r13)
  bl        -0x1B30
  stw       r4, 0x3264(r13)
  stw       r3, 0x3260(r13)
  lmw       r26, 0x8(r1)
  lwz       r0, 0x24(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void DVDLowSetResetCoverCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void DoBreak(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void AlarmHandlerForBreak(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void SetBreakAlarm(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FEF10
 * Size:	000014
 */
void DVDLowBreak(void)
{
/*
.loc_0x0:
  li        r0, 0x1
  stw       r0, 0x3250(r13)
  li        r3, 0x1
  stw       r0, 0x3270(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	801FEF24
 * Size:	000018
 */
void DVDLowClearCallback(void)
{
/*
.loc_0x0:
  lis       r3, 0xCC00
  li        r0, 0
  stw       r0, 0x6004(r3)
  lwz       r3, 0x3258(r13)
  stw       r0, 0x3258(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void DVDLowGetCoverStatus(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FEF3C
 * Size:	000044
 */
void __DVDLowSetWAType(void)
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
  bl        -0x5FDC
  stw       r30, 0x3274(r13)
  stw       r31, 0x3278(r13)
  bl        -0x5FC0
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}
