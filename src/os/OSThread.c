

/*
 * --INFO--
 * Address:	801FB9AC
 * Size:	000128
 */
void __OSThreadInit(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  li        r0, 0x2
  li        r4, 0x10
  stwu      r1, -0x20(r1)
  stmw      r26, 0x8(r1)
  addi      r28, r3, 0x2638
  addi      r31, r28, 0x410
  li        r29, 0
  addi      r3, r31, 0x2E8
  sth       r0, 0x6D8(r28)
  li        r0, 0x1
  sth       r0, 0x6DA(r28)
  li        r0, -0x1
  stw       r4, 0x6E4(r28)
  stw       r4, 0x6E0(r28)
  stw       r29, 0x6DC(r28)
  stw       r0, 0x6E8(r28)
  stw       r29, 0x700(r28)
  bl        .loc_0x128
  stw       r29, 0x708(r28)
  lis       r30, 0x8000
  addi      r3, r31, 0
  stw       r29, 0x704(r28)
  stw       r31, 0xD8(r30)
  bl        -0x45D8
  mr        r3, r31
  bl        -0x47A8
  lis       r3, 0x8040
  subi      r0, r3, 0x37C0
  lis       r3, 0x803F
  stw       r0, 0x714(r28)
  subi      r0, r3, 0x37C0
  addi      r3, r28, 0x718
  stw       r0, 0x718(r28)
  lis       r4, 0xDEAE
  li        r26, 0
  lwz       r3, 0x0(r3)
  subi      r4, r4, 0x4542
  rlwinm    r0,r26,3,0,28
  stw       r4, 0x0(r3)
  add       r27, r28, r0
  stw       r29, 0x3230(r13)
  stw       r31, 0xE4(r30)
  stw       r29, 0x3234(r13)

.loc_0xB8:
  mr        r3, r27
  bl        .loc_0x128
  addi      r26, r26, 0x1
  cmpwi     r26, 0x1F
  addi      r27, r27, 0x8
  ble+      .loc_0xB8
  lis       r30, 0x8000
  addi      r3, r30, 0xDC
  bl        .loc_0x128
  addi      r4, r30, 0xDC
  lwzu      r3, 0x4(r4)
  cmplwi    r3, 0
  bne-      .loc_0xF4
  stw       r31, 0xDC(r30)
  b         .loc_0xF8

.loc_0xF4:
  stw       r31, 0x2FC(r3)

.loc_0xF8:
  stw       r3, 0x300(r31)
  li        r30, 0
  addi      r3, r28, 0x720
  stw       r30, 0x2FC(r31)
  stw       r31, 0x0(r4)
  bl        -0x467C
  stw       r30, 0x3238(r13)
  lmw       r26, 0x8(r1)
  lwz       r0, 0x24(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr       

.loc_0x128:
*/
}

/*
 * --INFO--
 * Address:	801FBAD4
 * Size:	000010
 */
void OSInitThreadQueue(void)
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x4(r3)
  stw       r0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801FBAE4
 * Size:	00000C
 */
void OSGetCurrentThread(void)
{
/*
.loc_0x0:
  lis       r3, 0x8000
  lwz       r3, 0xE4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void __OSSwitchThread(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void OSIsThreadSuspended(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FBAF0
 * Size:	000034
 */
void OSIsThreadTerminated(void)
{
/*
.loc_0x0:
  lhz       r3, 0x2C8(r3)
  li        r0, 0x1
  cmplwi    r3, 0x8
  beq-      .loc_0x1C
  cmplwi    r3, 0
  beq-      .loc_0x1C
  li        r0, 0

.loc_0x1C:
  cmpwi     r0, 0
  beq-      .loc_0x2C
  li        r3, 0x1
  blr       

.loc_0x2C:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void __OSIsThreadActive(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FBB24
 * Size:	000040
 */
void OSDisableScheduler(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  bl        -0x2BB8
  lwz       r4, 0x3238(r13)
  addi      r0, r4, 0x1
  stw       r0, 0x3238(r13)
  mr        r31, r4
  bl        -0x2BA4
  lwz       r0, 0x14(r1)
  mr        r3, r31
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FBB64
 * Size:	000040
 */
void OSEnableScheduler(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  bl        -0x2BF8
  lwz       r4, 0x3238(r13)
  subi      r0, r4, 0x1
  stw       r0, 0x3238(r13)
  mr        r31, r4
  bl        -0x2BE4
  lwz       r0, 0x14(r1)
  mr        r3, r31
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void SetRun(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FBBA4
 * Size:	000068
 */
void UnsetRun(void)
{
/*
.loc_0x0:
  lwz       r4, 0x2E0(r3)
  lwz       r5, 0x2DC(r3)
  cmplwi    r4, 0
  lwz       r6, 0x2E4(r3)
  bne-      .loc_0x1C
  stw       r6, 0x4(r5)
  b         .loc_0x20

.loc_0x1C:
  stw       r6, 0x2E4(r4)

.loc_0x20:
  cmplwi    r6, 0
  bne-      .loc_0x30
  stw       r4, 0x0(r5)
  b         .loc_0x34

.loc_0x30:
  stw       r4, 0x2E0(r6)

.loc_0x34:
  lwz       r0, 0x0(r5)
  cmplwi    r0, 0
  bne-      .loc_0x5C
  lwz       r0, 0x2D0(r3)
  li        r4, 0x1
  lwz       r5, 0x3230(r13)
  subfic    r0, r0, 0x1F
  slw       r0, r4, r0
  andc      r0, r5, r0
  stw       r0, 0x3230(r13)

.loc_0x5C:
  li        r0, 0
  stw       r0, 0x2DC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801FBC0C
 * Size:	00003C
 */
void __OSGetEffectivePriority(void)
{
/*
.loc_0x0:
  lwz       r4, 0x2D4(r3)
  lwz       r5, 0x2F4(r3)
  b         .loc_0x2C

.loc_0xC:
  lwz       r3, 0x0(r5)
  cmplwi    r3, 0
  beq-      .loc_0x28
  lwz       r0, 0x2D0(r3)
  cmpw      r0, r4
  bge-      .loc_0x28
  mr        r4, r0

.loc_0x28:
  lwz       r5, 0x10(r5)

.loc_0x2C:
  cmplwi    r5, 0
  bne+      .loc_0xC
  mr        r3, r4
  blr
*/
}

/*
 * --INFO--
 * Address:	801FBC48
 * Size:	0001C0
 */
void SetEffectivePriority(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  stw       r30, 0x10(r1)
  addi      r30, r4, 0
  lhz       r0, 0x2C8(r3)
  cmpwi     r0, 0x3
  beq-      .loc_0x1A4
  bge-      .loc_0x3C
  cmpwi     r0, 0x1
  beq-      .loc_0x48
  bge-      .loc_0x198
  b         .loc_0x1A4

.loc_0x3C:
  cmpwi     r0, 0x5
  bge-      .loc_0x1A4
  b         .loc_0xC0

.loc_0x48:
  mr        r3, r31
  bl        -0xF0
  stw       r30, 0x2D0(r31)
  lis       r3, 0x803D
  addi      r0, r3, 0x2638
  lwz       r3, 0x2D0(r31)
  rlwinm    r3,r3,3,0,28
  add       r0, r0, r3
  stw       r0, 0x2DC(r31)
  lwz       r4, 0x2DC(r31)
  lwz       r3, 0x4(r4)
  cmplwi    r3, 0
  bne-      .loc_0x84
  stw       r31, 0x0(r4)
  b         .loc_0x88

.loc_0x84:
  stw       r31, 0x2E0(r3)

.loc_0x88:
  stw       r3, 0x2E4(r31)
  li        r0, 0
  li        r3, 0x1
  stw       r0, 0x2E0(r31)
  lwz       r4, 0x2DC(r31)
  stw       r31, 0x4(r4)
  lwz       r0, 0x2D0(r31)
  lwz       r4, 0x3230(r13)
  subfic    r0, r0, 0x1F
  slw       r0, r3, r0
  or        r0, r4, r0
  stw       r0, 0x3230(r13)
  stw       r3, 0x3234(r13)
  b         .loc_0x1A4

.loc_0xC0:
  lwz       r4, 0x2E0(r31)
  lwz       r5, 0x2E4(r31)
  cmplwi    r4, 0
  bne-      .loc_0xDC
  lwz       r3, 0x2DC(r31)
  stw       r5, 0x4(r3)
  b         .loc_0xE0

.loc_0xDC:
  stw       r5, 0x2E4(r4)

.loc_0xE0:
  cmplwi    r5, 0
  bne-      .loc_0xF4
  lwz       r3, 0x2DC(r31)
  stw       r4, 0x0(r3)
  b         .loc_0xF8

.loc_0xF4:
  stw       r4, 0x2E0(r5)

.loc_0xF8:
  stw       r30, 0x2D0(r31)
  lwz       r4, 0x2DC(r31)
  lwz       r5, 0x0(r4)
  b         .loc_0x10C

.loc_0x108:
  lwz       r5, 0x2E0(r5)

.loc_0x10C:
  cmplwi    r5, 0
  beq-      .loc_0x124
  lwz       r3, 0x2D0(r5)
  lwz       r0, 0x2D0(r31)
  cmpw      r3, r0
  ble+      .loc_0x108

.loc_0x124:
  cmplwi    r5, 0
  bne-      .loc_0x15C
  lwz       r3, 0x4(r4)
  cmplwi    r3, 0
  bne-      .loc_0x140
  stw       r31, 0x0(r4)
  b         .loc_0x144

.loc_0x140:
  stw       r31, 0x2E0(r3)

.loc_0x144:
  stw       r3, 0x2E4(r31)
  li        r0, 0
  stw       r0, 0x2E0(r31)
  lwz       r3, 0x2DC(r31)
  stw       r31, 0x4(r3)
  b         .loc_0x184

.loc_0x15C:
  stw       r5, 0x2E0(r31)
  lwz       r3, 0x2E4(r5)
  stw       r31, 0x2E4(r5)
  cmplwi    r3, 0
  stw       r3, 0x2E4(r31)
  bne-      .loc_0x180
  lwz       r3, 0x2DC(r31)
  stw       r31, 0x0(r3)
  b         .loc_0x184

.loc_0x180:
  stw       r31, 0x2E0(r3)

.loc_0x184:
  lwz       r3, 0x2F0(r31)
  cmplwi    r3, 0
  beq-      .loc_0x1A4
  lwz       r3, 0x8(r3)
  b         .loc_0x1A8

.loc_0x198:
  li        r0, 0x1
  stw       r0, 0x3234(r13)
  stw       r30, 0x2D0(r31)

.loc_0x1A4:
  li        r3, 0

.loc_0x1A8:
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
 * Address:	........
 * Size:	000078
 */
void UpdatePriority(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FBE08
 * Size:	000050
 */
void __OSPromoteThread(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r4

.loc_0x14:
  lwz       r0, 0x2CC(r3)
  cmpwi     r0, 0
  bgt-      .loc_0x3C
  lwz       r0, 0x2D0(r3)
  cmpw      r0, r31
  ble-      .loc_0x3C
  mr        r4, r31
  bl        -0x1F0
  cmplwi    r3, 0
  bne+      .loc_0x14

.loc_0x3C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FBE58
 * Size:	000200
 */
void SelectThread(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0x2638
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  lwz       r0, 0x3238(r13)
  cmpwi     r0, 0
  ble-      .loc_0x34
  li        r3, 0
  b         .loc_0x1E8

.loc_0x34:
  bl        -0x4BBC
  lis       r4, 0x8000
  lwz       r6, 0xE4(r4)
  cmplw     r3, r6
  addi      r3, r6, 0
  beq-      .loc_0x54
  li        r3, 0
  b         .loc_0x1E8

.loc_0x54:
  cmplwi    r6, 0
  beq-      .loc_0x114
  lhz       r0, 0x2C8(r6)
  cmplwi    r0, 0x2
  bne-      .loc_0xF4
  cmpwi     r30, 0
  bne-      .loc_0x8C
  lwz       r4, 0x3230(r13)
  lwz       r0, 0x2D0(r6)
  cntlzw    r4, r4
  cmpw      r0, r4
  bgt-      .loc_0x8C
  li        r3, 0
  b         .loc_0x1E8

.loc_0x8C:
  li        r0, 0x1
  sth       r0, 0x2C8(r6)
  lwz       r0, 0x2D0(r6)
  rlwinm    r0,r0,3,0,28
  add       r0, r31, r0
  stw       r0, 0x2DC(r6)
  lwz       r5, 0x2DC(r6)
  lwz       r4, 0x4(r5)
  cmplwi    r4, 0
  bne-      .loc_0xBC
  stw       r6, 0x0(r5)
  b         .loc_0xC0

.loc_0xBC:
  stw       r6, 0x2E0(r4)

.loc_0xC0:
  stw       r4, 0x2E4(r6)
  li        r0, 0
  li        r4, 0x1
  stw       r0, 0x2E0(r6)
  lwz       r5, 0x2DC(r6)
  stw       r6, 0x4(r5)
  lwz       r0, 0x2D0(r6)
  lwz       r5, 0x3230(r13)
  subfic    r0, r0, 0x1F
  slw       r0, r4, r0
  or        r0, r5, r0
  stw       r0, 0x3230(r13)
  stw       r4, 0x3234(r13)

.loc_0xF4:
  lhz       r0, 0x1A2(r6)
  rlwinm.   r0,r0,0,30,30
  bne-      .loc_0x114
  bl        -0x4C7C
  cmplwi    r3, 0
  beq-      .loc_0x114
  li        r3, 0
  b         .loc_0x1E8

.loc_0x114:
  lwz       r0, 0x3230(r13)
  li        r4, 0
  lis       r3, 0x8000
  cmplwi    r0, 0
  stw       r4, 0xE4(r3)
  bne-      .loc_0x15C
  addi      r3, r31, 0x720
  bl        -0x4D14

.loc_0x134:
  bl        -0x2FFC

.loc_0x138:
  lwz       r0, 0x3230(r13)
  cmplwi    r0, 0
  beq+      .loc_0x138
  bl        -0x3020
  lwz       r0, 0x3230(r13)
  cmplwi    r0, 0
  beq+      .loc_0x134
  addi      r3, r31, 0x720
  bl        -0x4B74

.loc_0x15C:
  li        r3, 0
  stw       r3, 0x3234(r13)
  lwz       r0, 0x3230(r13)
  cntlzw    r7, r0
  rlwinm    r0,r7,3,0,28
  add       r4, r31, r0
  lwz       r5, 0x0(r4)
  lwz       r6, 0x2E0(r5)
  addi      r31, r5, 0
  cmplwi    r6, 0
  bne-      .loc_0x190
  stw       r3, 0x4(r4)
  b         .loc_0x194

.loc_0x190:
  stw       r3, 0x2E4(r6)

.loc_0x194:
  stw       r6, 0x0(r4)
  lwz       r0, 0x0(r4)
  cmplwi    r0, 0
  bne-      .loc_0x1BC
  subfic    r0, r7, 0x1F
  lwz       r4, 0x3230(r13)
  li        r3, 0x1
  slw       r0, r3, r0
  andc      r0, r4, r0
  stw       r0, 0x3230(r13)

.loc_0x1BC:
  li        r0, 0
  stw       r0, 0x2DC(r31)
  li        r0, 0x2
  lis       r4, 0x8000
  sth       r0, 0x2C8(r31)
  mr        r3, r31
  stw       r31, 0xE4(r4)
  bl        -0x4DBC
  mr        r3, r31
  bl        -0x4CDC
  mr        r3, r31

.loc_0x1E8:
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
 * Address:	801FC058
 * Size:	000030
 */
void __OSReschedule(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x3234(r13)
  cmpwi     r0, 0
  beq-      .loc_0x20
  li        r3, 0
  bl        -0x21C

.loc_0x20:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FC088
 * Size:	00003C
 */
void OSYieldThread(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  bl        -0x311C
  addi      r31, r3, 0
  li        r3, 0x1
  bl        -0x24C
  mr        r3, r31
  bl        -0x3108
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801FC0C4
 * Size:	000120
 */
void OSCreateThread(void)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r8, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r3, 0
  stw       r30, 0x30(r1)
  addi      r30, r7, 0
  stw       r29, 0x2C(r1)
  addi      r29, r6, 0
  stw       r28, 0x28(r1)
  addi      r28, r5, 0
  blt-      .loc_0x3C
  cmpwi     r8, 0x1F
  ble-      .loc_0x44

.loc_0x3C:
  li        r3, 0
  b         .loc_0x100

.loc_0x44:
  li        r7, 0x1
  sth       r7, 0x2C8(r31)
  rlwinm    r0,r9,0,31,31
  rlwinm    r9,r29,0,0,28
  sth       r0, 0x2CA(r31)
  li        r6, -0x1
  li        r0, 0
  stw       r8, 0x2D4(r31)
  addi      r3, r31, 0
  subi      r5, r9, 0x8
  stw       r8, 0x2D0(r31)
  stw       r7, 0x2CC(r31)
  stw       r6, 0x2D8(r31)
  stw       r0, 0x2F0(r31)
  stw       r0, 0x2EC(r31)
  stw       r0, 0x2E8(r31)
  stw       r0, 0x2F8(r31)
  stw       r0, 0x2F4(r31)
  stw       r0, -0x8(r9)
  stw       r0, -0x4(r9)
  bl        -0x4CF8
  lis       r3, 0x8020
  subi      r0, r3, 0x3E1C
  stw       r0, 0x84(r31)
  lis       r3, 0xDEAE
  sub       r4, r29, r30
  stw       r28, 0xC(r31)
  subi      r0, r3, 0x4542
  stw       r29, 0x304(r31)
  stw       r4, 0x308(r31)
  lwz       r3, 0x308(r31)
  stw       r0, 0x0(r3)
  bl        -0x320C
  lis       r4, 0x8000
  addi      r5, r4, 0xDC
  lwzu      r6, 0x4(r5)
  cmplwi    r6, 0
  bne-      .loc_0xE4
  stw       r31, 0xDC(r4)
  b         .loc_0xE8

.loc_0xE4:
  stw       r31, 0x2FC(r6)

.loc_0xE8:
  stw       r6, 0x300(r31)
  li        r0, 0
  stw       r0, 0x2FC(r31)
  stw       r31, 0x0(r5)
  bl        -0x3218
  li        r3, 0x1

.loc_0x100:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  mtlr      r0
  lwz       r29, 0x2C(r1)
  lwz       r28, 0x28(r1)
  addi      r1, r1, 0x38
  blr
*/
}

/*
 * --INFO--
 * Address:	801FC1E4
 * Size:	0000E4
 */
void OSExitThread(void)
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
  mr        r28, r3
  bl        -0x3288
  lis       r31, 0x8000
  lwz       r30, 0xE4(r31)
  addi      r29, r3, 0
  addi      r3, r30, 0
  bl        -0x4DDC
  lhz       r0, 0x2CA(r30)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x84
  lwz       r4, 0x2FC(r30)
  lwz       r5, 0x300(r30)
  cmplwi    r4, 0
  bne-      .loc_0x5C
  stw       r5, 0xE0(r31)
  b         .loc_0x60

.loc_0x5C:
  stw       r5, 0x300(r4)

.loc_0x60:
  cmplwi    r5, 0
  bne-      .loc_0x74
  lis       r3, 0x8000
  stw       r4, 0xDC(r3)
  b         .loc_0x78

.loc_0x74:
  stw       r4, 0x2FC(r5)

.loc_0x78:
  li        r0, 0
  sth       r0, 0x2C8(r30)
  b         .loc_0x90

.loc_0x84:
  li        r0, 0x8
  sth       r0, 0x2C8(r30)
  stw       r28, 0x2D8(r30)

.loc_0x90:
  mr        r3, r30
  bl        -0x26E4
  addi      r3, r30, 0x2E8
  bl        0x828
  li        r0, 0x1
  stw       r0, 0x3234(r13)
  lwz       r0, 0x3234(r13)
  cmpwi     r0, 0
  beq-      .loc_0xBC
  li        r3, 0
  bl        -0x444

.loc_0xBC:
  mr        r3, r29
  bl        -0x3300
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
 * Address:	801FC2C8
 * Size:	0001BC
 */
void OSCancelThread(void)
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
  bl        -0x3368
  lhz       r0, 0x2C8(r30)
  addi      r31, r3, 0
  cmpwi     r0, 0x3
  beq-      .loc_0x108
  bge-      .loc_0x44
  cmpwi     r0, 0x1
  beq-      .loc_0x50
  bge-      .loc_0x68
  b         .loc_0x108

.loc_0x44:
  cmpwi     r0, 0x5
  bge-      .loc_0x108
  b         .loc_0x74

.loc_0x50:
  lwz       r0, 0x2CC(r30)
  cmpwi     r0, 0
  bgt-      .loc_0x114
  mr        r3, r30
  bl        -0x784
  b         .loc_0x114

.loc_0x68:
  li        r0, 0x1
  stw       r0, 0x3234(r13)
  b         .loc_0x114

.loc_0x74:
  lwz       r4, 0x2E0(r30)
  lwz       r5, 0x2E4(r30)
  cmplwi    r4, 0
  bne-      .loc_0x90
  lwz       r3, 0x2DC(r30)
  stw       r5, 0x4(r3)
  b         .loc_0x94

.loc_0x90:
  stw       r5, 0x2E4(r4)

.loc_0x94:
  cmplwi    r5, 0
  bne-      .loc_0xA8
  lwz       r3, 0x2DC(r30)
  stw       r4, 0x0(r3)
  b         .loc_0xAC

.loc_0xA8:
  stw       r4, 0x2E0(r5)

.loc_0xAC:
  li        r0, 0
  stw       r0, 0x2DC(r30)
  lwz       r0, 0x2CC(r30)
  cmpwi     r0, 0
  bgt-      .loc_0x114
  lwz       r3, 0x2F0(r30)
  cmplwi    r3, 0
  beq-      .loc_0x114
  lwz       r29, 0x8(r3)

.loc_0xD0:
  lwz       r0, 0x2CC(r29)
  cmpwi     r0, 0
  bgt-      .loc_0x114
  mr        r3, r29
  bl        -0x79C
  lwz       r0, 0x2D0(r29)
  addi      r4, r3, 0
  cmpw      r0, r4
  beq-      .loc_0x114
  mr        r3, r29
  bl        -0x778
  mr.       r29, r3
  bne+      .loc_0xD0
  b         .loc_0x114

.loc_0x108:
  mr        r3, r31
  bl        -0x3430
  b         .loc_0x1A0

.loc_0x114:
  mr        r3, r30
  bl        -0x4FA4
  lhz       r0, 0x2CA(r30)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x16C
  lwz       r4, 0x2FC(r30)
  lwz       r5, 0x300(r30)
  cmplwi    r4, 0
  bne-      .loc_0x144
  lis       r3, 0x8000
  stw       r5, 0xE0(r3)
  b         .loc_0x148

.loc_0x144:
  stw       r5, 0x300(r4)

.loc_0x148:
  cmplwi    r5, 0
  bne-      .loc_0x15C
  lis       r3, 0x8000
  stw       r4, 0xDC(r3)
  b         .loc_0x160

.loc_0x15C:
  stw       r4, 0x2FC(r5)

.loc_0x160:
  li        r0, 0
  sth       r0, 0x2C8(r30)
  b         .loc_0x174

.loc_0x16C:
  li        r0, 0x8
  sth       r0, 0x2C8(r30)

.loc_0x174:
  mr        r3, r30
  bl        -0x28AC
  addi      r3, r30, 0x2E8
  bl        0x660
  lwz       r0, 0x3234(r13)
  cmpwi     r0, 0
  beq-      .loc_0x198
  li        r3, 0
  bl        -0x604

.loc_0x198:
  mr        r3, r31
  bl        -0x34C0

.loc_0x1A0:
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
 * Address:	801FC484
 * Size:	000140
 */
void OSJoinThread(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r4, 0
  bl        -0x3528
  lhz       r0, 0x2CA(r31)
  addi      r30, r3, 0
  rlwinm.   r0,r0,0,31,31
  bne-      .loc_0xAC
  lhz       r0, 0x2C8(r31)
  cmplwi    r0, 0x8
  beq-      .loc_0xAC
  lwz       r0, 0x2E8(r31)
  cmplwi    r0, 0
  bne-      .loc_0xAC
  addi      r3, r31, 0x2E8
  bl        0x4E8
  lhz       r0, 0x2C8(r31)
  cmplwi    r0, 0
  bne-      .loc_0x68
  li        r0, 0
  b         .loc_0x94

.loc_0x68:
  lis       r3, 0x8000
  lwz       r3, 0xDC(r3)
  b         .loc_0x88

.loc_0x74:
  cmplw     r31, r3
  bne-      .loc_0x84
  li        r0, 0x1
  b         .loc_0x94

.loc_0x84:
  lwz       r3, 0x2FC(r3)

.loc_0x88:
  cmplwi    r3, 0
  bne+      .loc_0x74
  li        r0, 0

.loc_0x94:
  cmpwi     r0, 0
  bne-      .loc_0xAC
  mr        r3, r30
  bl        -0x3580
  li        r3, 0
  b         .loc_0x124

.loc_0xAC:
  lhz       r0, 0x2C8(r31)
  cmplwi    r0, 0x8
  bne-      .loc_0x118
  cmplwi    r29, 0
  beq-      .loc_0xC8
  lwz       r0, 0x2D8(r31)
  stw       r0, 0x0(r29)

.loc_0xC8:
  lwz       r4, 0x2FC(r31)
  lwz       r5, 0x300(r31)
  cmplwi    r4, 0
  bne-      .loc_0xE4
  lis       r3, 0x8000
  stw       r5, 0xE0(r3)
  b         .loc_0xE8

.loc_0xE4:
  stw       r5, 0x300(r4)

.loc_0xE8:
  cmplwi    r5, 0
  bne-      .loc_0xFC
  lis       r3, 0x8000
  stw       r4, 0xDC(r3)
  b         .loc_0x100

.loc_0xFC:
  stw       r4, 0x2FC(r5)

.loc_0x100:
  li        r0, 0
  sth       r0, 0x2C8(r31)
  mr        r3, r30
  bl        -0x35EC
  li        r3, 0x1
  b         .loc_0x124

.loc_0x118:
  mr        r3, r30
  bl        -0x35FC
  li        r3, 0

.loc_0x124:
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
 * Address:	........
 * Size:	0000A0
 */
void OSDetachThread(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FC5C4
 * Size:	000288
 */
void OSResumeThread(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  mr        r29, r3
  bl        -0x3664
  lwz       r4, 0x2CC(r29)
  addi      r31, r3, 0
  subi      r0, r4, 0x1
  stw       r0, 0x2CC(r29)
  mr        r30, r4
  lwz       r0, 0x2CC(r29)
  cmpwi     r0, 0
  bge-      .loc_0x4C
  li        r0, 0
  stw       r0, 0x2CC(r29)
  b         .loc_0x260

.loc_0x4C:
  bne-      .loc_0x260
  lhz       r0, 0x2C8(r29)
  cmpwi     r0, 0x4
  beq-      .loc_0x110
  bge-      .loc_0x24C
  cmpwi     r0, 0x1
  beq-      .loc_0x6C
  b         .loc_0x24C

.loc_0x6C:
  lwz       r0, 0x2D4(r29)
  lwz       r3, 0x2F4(r29)
  b         .loc_0x98

.loc_0x78:
  lwz       r4, 0x0(r3)
  cmplwi    r4, 0
  beq-      .loc_0x94
  lwz       r4, 0x2D0(r4)
  cmpw      r4, r0
  bge-      .loc_0x94
  mr        r0, r4

.loc_0x94:
  lwz       r3, 0x10(r3)

.loc_0x98:
  cmplwi    r3, 0
  bne+      .loc_0x78
  stw       r0, 0x2D0(r29)
  lis       r3, 0x803D
  addi      r0, r3, 0x2638
  lwz       r3, 0x2D0(r29)
  rlwinm    r3,r3,3,0,28
  add       r0, r0, r3
  stw       r0, 0x2DC(r29)
  lwz       r4, 0x2DC(r29)
  lwz       r3, 0x4(r4)
  cmplwi    r3, 0
  bne-      .loc_0xD4
  stw       r29, 0x0(r4)
  b         .loc_0xD8

.loc_0xD4:
  stw       r29, 0x2E0(r3)

.loc_0xD8:
  stw       r3, 0x2E4(r29)
  li        r0, 0
  li        r3, 0x1
  stw       r0, 0x2E0(r29)
  lwz       r4, 0x2DC(r29)
  stw       r29, 0x4(r4)
  lwz       r0, 0x2D0(r29)
  lwz       r4, 0x3230(r13)
  subfic    r0, r0, 0x1F
  slw       r0, r3, r0
  or        r0, r4, r0
  stw       r0, 0x3230(r13)
  stw       r3, 0x3234(r13)
  b         .loc_0x24C

.loc_0x110:
  lwz       r4, 0x2E0(r29)
  lwz       r5, 0x2E4(r29)
  cmplwi    r4, 0
  bne-      .loc_0x12C
  lwz       r3, 0x2DC(r29)
  stw       r5, 0x4(r3)
  b         .loc_0x130

.loc_0x12C:
  stw       r5, 0x2E4(r4)

.loc_0x130:
  cmplwi    r5, 0
  bne-      .loc_0x144
  lwz       r3, 0x2DC(r29)
  stw       r4, 0x0(r3)
  b         .loc_0x148

.loc_0x144:
  stw       r4, 0x2E0(r5)

.loc_0x148:
  lwz       r0, 0x2D4(r29)
  lwz       r3, 0x2F4(r29)
  b         .loc_0x174

.loc_0x154:
  lwz       r4, 0x0(r3)
  cmplwi    r4, 0
  beq-      .loc_0x170
  lwz       r4, 0x2D0(r4)
  cmpw      r4, r0
  bge-      .loc_0x170
  mr        r0, r4

.loc_0x170:
  lwz       r3, 0x10(r3)

.loc_0x174:
  cmplwi    r3, 0
  bne+      .loc_0x154
  stw       r0, 0x2D0(r29)
  lwz       r4, 0x2DC(r29)
  lwz       r5, 0x0(r4)
  b         .loc_0x190

.loc_0x18C:
  lwz       r5, 0x2E0(r5)

.loc_0x190:
  cmplwi    r5, 0
  beq-      .loc_0x1A8
  lwz       r3, 0x2D0(r5)
  lwz       r0, 0x2D0(r29)
  cmpw      r3, r0
  ble+      .loc_0x18C

.loc_0x1A8:
  cmplwi    r5, 0
  bne-      .loc_0x1E0
  lwz       r3, 0x4(r4)
  cmplwi    r3, 0
  bne-      .loc_0x1C4
  stw       r29, 0x0(r4)
  b         .loc_0x1C8

.loc_0x1C4:
  stw       r29, 0x2E0(r3)

.loc_0x1C8:
  stw       r3, 0x2E4(r29)
  li        r0, 0
  stw       r0, 0x2E0(r29)
  lwz       r3, 0x2DC(r29)
  stw       r29, 0x4(r3)
  b         .loc_0x208

.loc_0x1E0:
  stw       r5, 0x2E0(r29)
  lwz       r3, 0x2E4(r5)
  stw       r29, 0x2E4(r5)
  cmplwi    r3, 0
  stw       r3, 0x2E4(r29)
  bne-      .loc_0x204
  lwz       r3, 0x2DC(r29)
  stw       r29, 0x0(r3)
  b         .loc_0x208

.loc_0x204:
  stw       r29, 0x2E0(r3)

.loc_0x208:
  lwz       r3, 0x2F0(r29)
  cmplwi    r3, 0
  beq-      .loc_0x24C
  lwz       r29, 0x8(r3)

.loc_0x218:
  lwz       r0, 0x2CC(r29)
  cmpwi     r0, 0
  bgt-      .loc_0x24C
  mr        r3, r29
  bl        -0xBE0
  lwz       r0, 0x2D0(r29)
  addi      r4, r3, 0
  cmpw      r0, r4
  beq-      .loc_0x24C
  mr        r3, r29
  bl        -0xBBC
  mr.       r29, r3
  bne+      .loc_0x218

.loc_0x24C:
  lwz       r0, 0x3234(r13)
  cmpwi     r0, 0
  beq-      .loc_0x260
  li        r3, 0
  bl        -0x9C8

.loc_0x260:
  mr        r3, r31
  bl        -0x3884
  lwz       r0, 0x2C(r1)
  mr        r3, r30
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	801FC84C
 * Size:	000170
 */
void OSSuspendThread(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  mr        r29, r3
  bl        -0x38EC
  lwz       r4, 0x2CC(r29)
  addi      r31, r3, 0
  addi      r0, r4, 0x1
  mr.       r30, r4
  stw       r0, 0x2CC(r29)
  bne-      .loc_0x148
  lhz       r0, 0x2C8(r29)
  cmpwi     r0, 0x3
  beq-      .loc_0x134
  bge-      .loc_0x58
  cmpwi     r0, 0x1
  beq-      .loc_0x74
  bge-      .loc_0x64
  b         .loc_0x134

.loc_0x58:
  cmpwi     r0, 0x5
  bge-      .loc_0x134
  b         .loc_0x80

.loc_0x64:
  li        r0, 0x1
  stw       r0, 0x3234(r13)
  sth       r0, 0x2C8(r29)
  b         .loc_0x134

.loc_0x74:
  mr        r3, r29
  bl        -0xD20
  b         .loc_0x134

.loc_0x80:
  lwz       r4, 0x2E0(r29)
  lwz       r5, 0x2E4(r29)
  cmplwi    r4, 0
  bne-      .loc_0x9C
  lwz       r3, 0x2DC(r29)
  stw       r5, 0x4(r3)
  b         .loc_0xA0

.loc_0x9C:
  stw       r5, 0x2E4(r4)

.loc_0xA0:
  cmplwi    r5, 0
  bne-      .loc_0xB4
  lwz       r3, 0x2DC(r29)
  stw       r4, 0x0(r3)
  b         .loc_0xB8

.loc_0xB4:
  stw       r4, 0x2E0(r5)

.loc_0xB8:
  li        r0, 0x20
  stw       r0, 0x2D0(r29)
  lwz       r4, 0x2DC(r29)
  lwz       r3, 0x4(r4)
  cmplwi    r3, 0
  bne-      .loc_0xD8
  stw       r29, 0x0(r4)
  b         .loc_0xDC

.loc_0xD8:
  stw       r29, 0x2E0(r3)

.loc_0xDC:
  stw       r3, 0x2E4(r29)
  li        r0, 0
  stw       r0, 0x2E0(r29)
  lwz       r3, 0x2DC(r29)
  stw       r29, 0x4(r3)
  lwz       r3, 0x2F0(r29)
  cmplwi    r3, 0
  beq-      .loc_0x134
  lwz       r29, 0x8(r3)

.loc_0x100:
  lwz       r0, 0x2CC(r29)
  cmpwi     r0, 0
  bgt-      .loc_0x134
  mr        r3, r29
  bl        -0xD50
  lwz       r0, 0x2D0(r29)
  addi      r4, r3, 0
  cmpw      r0, r4
  beq-      .loc_0x134
  mr        r3, r29
  bl        -0xD2C
  mr.       r29, r3
  bne+      .loc_0x100

.loc_0x134:
  lwz       r0, 0x3234(r13)
  cmpwi     r0, 0
  beq-      .loc_0x148
  li        r3, 0
  bl        -0xB38

.loc_0x148:
  mr        r3, r31
  bl        -0x39F4
  lwz       r0, 0x24(r1)
  mr        r3, r30
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
 * Address:	801FC9BC
 * Size:	0000EC
 */
void OSSleepThread(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  bl        -0x3A58
  lis       r4, 0x8000
  lwz       r4, 0xE4(r4)
  li        r0, 0x4
  mr        r31, r3
  sth       r0, 0x2C8(r4)
  stw       r30, 0x2DC(r4)
  lwz       r5, 0x0(r30)
  b         .loc_0x40

.loc_0x3C:
  lwz       r5, 0x2E0(r5)

.loc_0x40:
  cmplwi    r5, 0
  beq-      .loc_0x58
  lwz       r3, 0x2D0(r5)
  lwz       r0, 0x2D0(r4)
  cmpw      r3, r0
  ble+      .loc_0x3C

.loc_0x58:
  cmplwi    r5, 0
  bne-      .loc_0x8C
  lwz       r3, 0x4(r30)
  cmplwi    r3, 0
  bne-      .loc_0x74
  stw       r4, 0x0(r30)
  b         .loc_0x78

.loc_0x74:
  stw       r4, 0x2E0(r3)

.loc_0x78:
  stw       r3, 0x2E4(r4)
  li        r0, 0
  stw       r0, 0x2E0(r4)
  stw       r4, 0x4(r30)
  b         .loc_0xB0

.loc_0x8C:
  stw       r5, 0x2E0(r4)
  lwz       r3, 0x2E4(r5)
  stw       r4, 0x2E4(r5)
  cmplwi    r3, 0
  stw       r3, 0x2E4(r4)
  bne-      .loc_0xAC
  stw       r4, 0x0(r30)
  b         .loc_0xB0

.loc_0xAC:
  stw       r4, 0x2E0(r3)

.loc_0xB0:
  li        r0, 0x1
  stw       r0, 0x3234(r13)
  lwz       r0, 0x3234(r13)
  cmpwi     r0, 0
  beq-      .loc_0xCC
  li        r3, 0
  bl        -0xC2C

.loc_0xCC:
  mr        r3, r31
  bl        -0x3AE8
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
 * Address:	801FCAA8
 * Size:	000104
 */
void OSWakeupThread(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  bl        -0x3B44
  lis       r4, 0x803D
  addi      r31, r3, 0
  addi      r5, r4, 0x2638
  b         .loc_0xC4

.loc_0x2C:
  lwz       r3, 0x2E0(r6)
  cmplwi    r3, 0
  bne-      .loc_0x44
  li        r0, 0
  stw       r0, 0x4(r30)
  b         .loc_0x4C

.loc_0x44:
  li        r0, 0
  stw       r0, 0x2E4(r3)

.loc_0x4C:
  stw       r3, 0x0(r30)
  li        r0, 0x1
  sth       r0, 0x2C8(r6)
  lwz       r0, 0x2CC(r6)
  cmpwi     r0, 0
  bgt-      .loc_0xC4
  lwz       r0, 0x2D0(r6)
  rlwinm    r0,r0,3,0,28
  add       r0, r5, r0
  stw       r0, 0x2DC(r6)
  lwz       r4, 0x2DC(r6)
  lwz       r3, 0x4(r4)
  cmplwi    r3, 0
  bne-      .loc_0x8C
  stw       r6, 0x0(r4)
  b         .loc_0x90

.loc_0x8C:
  stw       r6, 0x2E0(r3)

.loc_0x90:
  stw       r3, 0x2E4(r6)
  li        r0, 0
  li        r3, 0x1
  stw       r0, 0x2E0(r6)
  lwz       r4, 0x2DC(r6)
  stw       r6, 0x4(r4)
  lwz       r0, 0x2D0(r6)
  lwz       r4, 0x3230(r13)
  subfic    r0, r0, 0x1F
  slw       r0, r3, r0
  or        r0, r4, r0
  stw       r0, 0x3230(r13)
  stw       r3, 0x3234(r13)

.loc_0xC4:
  lwz       r6, 0x0(r30)
  cmplwi    r6, 0
  bne+      .loc_0x2C
  lwz       r0, 0x3234(r13)
  cmpwi     r0, 0
  beq-      .loc_0xE4
  li        r3, 0
  bl        -0xD30

.loc_0xE4:
  mr        r3, r31
  bl        -0x3BEC
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
 * Address:	........
 * Size:	0000C0
 */
void OSSetThreadPriority(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FCBAC
 * Size:	000008
 */
void OSGetThreadPriority(void)
{
/*
.loc_0x0:
  lwz       r3, 0x2D4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void OSSetIdleFunction(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void OSGetIdleFunction(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FCBB4
 * Size:	00009C
 */
void CheckThreadQueue(void)
{
/*
.loc_0x0:
  lwz       r4, 0x0(r3)
  cmplwi    r4, 0
  beq-      .loc_0x20
  lwz       r0, 0x2E4(r4)
  cmplwi    r0, 0
  beq-      .loc_0x20
  li        r3, 0
  blr       

.loc_0x20:
  lwz       r3, 0x4(r3)
  cmplwi    r3, 0
  beq-      .loc_0x40
  lwz       r0, 0x2E0(r3)
  cmplwi    r0, 0
  beq-      .loc_0x40
  li        r3, 0
  blr       

.loc_0x40:
  mr        r5, r4
  b         .loc_0x8C

.loc_0x48:
  lwz       r3, 0x2E0(r5)
  cmplwi    r3, 0
  beq-      .loc_0x68
  lwz       r0, 0x2E4(r3)
  cmplw     r5, r0
  beq-      .loc_0x68
  li        r3, 0
  blr       

.loc_0x68:
  lwz       r4, 0x2E4(r5)
  cmplwi    r4, 0
  beq-      .loc_0x88
  lwz       r0, 0x2E0(r4)
  cmplw     r5, r0
  beq-      .loc_0x88
  li        r3, 0
  blr       

.loc_0x88:
  mr        r5, r3

.loc_0x8C:
  cmplwi    r5, 0
  bne+      .loc_0x48
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void IsMember(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FCC50
 * Size:	000750
 */
void OSCheckActiveThreads(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802E
  stw       r0, 0x4(r1)
  lis       r3, 0x803D
  stwu      r1, -0x38(r1)
  stmw      r26, 0x20(r1)
  addi      r30, r4, 0x7BD8
  addi      r31, r3, 0x2638
  li        r28, 0
  bl        -0x3CF8
  addi      r27, r3, 0
  addi      r29, r31, 0
  li        r26, 0

.loc_0x34:
  subfic    r0, r26, 0x1F
  lwz       r4, 0x3230(r13)
  li        r3, 0x1
  slw       r0, r3, r0
  and.      r0, r4, r0
  beq-      .loc_0x8C
  lwz       r0, 0x0(r29)
  cmplwi    r0, 0
  beq-      .loc_0x64
  lwz       r0, 0x4(r29)
  cmplwi    r0, 0
  bne-      .loc_0xC8

.loc_0x64:
  addi      r3, r30, 0
  crclr     6, 0x6
  li        r4, 0x566
  bl        -0x5430
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x566
  addi      r5, r13, 0x29F8
  bl        -0x53C4
  b         .loc_0xC8

.loc_0x8C:
  lwz       r0, 0x0(r29)
  cmplwi    r0, 0
  bne-      .loc_0xA4
  lwz       r0, 0x4(r29)
  cmplwi    r0, 0
  beq-      .loc_0xC8

.loc_0xA4:
  addi      r3, r30, 0x6C
  crclr     6, 0x6
  li        r4, 0x56B
  bl        -0x5470
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x56B
  addi      r5, r13, 0x29F8
  bl        -0x5404

.loc_0xC8:
  mr        r3, r29
  bl        -0x168
  cmpwi     r3, 0
  bne-      .loc_0xFC
  addi      r3, r30, 0xCC
  crclr     6, 0x6
  li        r4, 0x56D
  bl        -0x54A4
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x56D
  addi      r5, r13, 0x29F8
  bl        -0x5438

.loc_0xFC:
  addi      r26, r26, 0x1
  cmpwi     r26, 0x1F
  addi      r29, r29, 0x8
  ble+      .loc_0x34
  lis       r3, 0x8000
  lwz       r3, 0xDC(r3)
  cmplwi    r3, 0
  beq-      .loc_0x14C
  lwz       r0, 0x300(r3)
  cmplwi    r0, 0
  beq-      .loc_0x14C
  addi      r3, r30, 0x114
  crclr     6, 0x6
  li        r4, 0x572
  bl        -0x54F4
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x572
  addi      r5, r13, 0x29F8
  bl        -0x5488

.loc_0x14C:
  lis       r3, 0x8000
  addi      r3, r3, 0xDC
  lwz       r3, 0x4(r3)
  cmplwi    r3, 0
  beq-      .loc_0x190
  lwz       r0, 0x2FC(r3)
  cmplwi    r0, 0
  beq-      .loc_0x190
  addi      r3, r30, 0x194
  crclr     6, 0x6
  li        r4, 0x574
  bl        -0x5538
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x574
  addi      r5, r13, 0x29F8
  bl        -0x54CC

.loc_0x190:
  lis       r3, 0x8000
  lwz       r29, 0xDC(r3)
  b         .loc_0x728

.loc_0x19C:
  lwz       r3, 0x2FC(r29)
  addi      r28, r28, 0x1
  cmplwi    r3, 0
  beq-      .loc_0x1DC
  lwz       r0, 0x300(r3)
  cmplw     r29, r0
  beq-      .loc_0x1DC
  addi      r3, r30, 0x214
  crclr     6, 0x6
  li        r4, 0x57C
  bl        -0x5584
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x57C
  addi      r5, r13, 0x29F8
  bl        -0x5518

.loc_0x1DC:
  lwz       r3, 0x300(r29)
  cmplwi    r3, 0
  beq-      .loc_0x218
  lwz       r0, 0x2FC(r3)
  cmplw     r29, r0
  beq-      .loc_0x218
  addi      r3, r30, 0x290
  crclr     6, 0x6
  li        r4, 0x57E
  bl        -0x55C0
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x57E
  addi      r5, r13, 0x29F8
  bl        -0x5554

.loc_0x218:
  lwz       r3, 0x308(r29)
  lwz       r3, 0x0(r3)
  addis     r0, r3, 0x2153
  cmplwi    r0, 0xBABE
  beq-      .loc_0x250
  addi      r3, r30, 0x30C
  crclr     6, 0x6
  li        r4, 0x581
  bl        -0x55F8
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x581
  addi      r5, r13, 0x29F8
  bl        -0x558C

.loc_0x250:
  lwz       r0, 0x2D0(r29)
  cmpwi     r0, 0
  blt-      .loc_0x264
  cmpwi     r0, 0x20
  ble-      .loc_0x288

.loc_0x264:
  addi      r3, r30, 0x360
  crclr     6, 0x6
  li        r4, 0x584
  bl        -0x5630
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x584
  addi      r5, r13, 0x29F8
  bl        -0x55C4

.loc_0x288:
  lwz       r0, 0x2CC(r29)
  cmpwi     r0, 0
  bge-      .loc_0x2B8
  addi      r3, r30, 0x3D4
  crclr     6, 0x6
  li        r4, 0x585
  bl        -0x5660
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x585
  addi      r5, r13, 0x29F8
  bl        -0x55F4

.loc_0x2B8:
  addi      r3, r29, 0x2E8
  bl        -0x358
  cmpwi     r3, 0
  bne-      .loc_0x2EC
  addi      r3, r30, 0x410
  crclr     6, 0x6
  li        r4, 0x586
  bl        -0x5694
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x586
  addi      r5, r13, 0x29F8
  bl        -0x5628

.loc_0x2EC:
  lhz       r4, 0x2C8(r29)
  cmpwi     r4, 0x4
  beq-      .loc_0x4F4
  bge-      .loc_0x314
  cmpwi     r4, 0x2
  beq-      .loc_0x42C
  bge-      .loc_0x6CC
  cmpwi     r4, 0x1
  bge-      .loc_0x320
  b         .loc_0x6CC

.loc_0x314:
  cmpwi     r4, 0x8
  beq-      .loc_0x68C
  b         .loc_0x6CC

.loc_0x320:
  lwz       r0, 0x2CC(r29)
  cmpwi     r0, 0
  bgt-      .loc_0x6F0
  lwz       r0, 0x2D0(r29)
  lwz       r3, 0x2DC(r29)
  rlwinm    r0,r0,3,0,28
  add       r0, r31, r0
  cmplw     r3, r0
  beq-      .loc_0x368
  addi      r3, r30, 0x45C
  crclr     6, 0x6
  li        r4, 0x58C
  bl        -0x5710
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x58C
  addi      r5, r13, 0x29F8
  bl        -0x56A4

.loc_0x368:
  lwz       r0, 0x2D0(r29)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r31, r0
  b         .loc_0x38C

.loc_0x378:
  cmplw     r29, r3
  bne-      .loc_0x388
  li        r0, 0x1
  b         .loc_0x398

.loc_0x388:
  lwz       r3, 0x2E0(r3)

.loc_0x38C:
  cmplwi    r3, 0
  bne+      .loc_0x378
  li        r0, 0

.loc_0x398:
  cmpwi     r0, 0
  bne-      .loc_0x3C4
  addi      r3, r30, 0x4B0
  crclr     6, 0x6
  li        r4, 0x58D
  bl        -0x576C
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x58D
  addi      r5, r13, 0x29F8
  bl        -0x5700

.loc_0x3C4:
  lwz       r4, 0x2D4(r29)
  lwz       r3, 0x2F4(r29)
  b         .loc_0x3F0

.loc_0x3D0:
  lwz       r5, 0x0(r3)
  cmplwi    r5, 0
  beq-      .loc_0x3EC
  lwz       r0, 0x2D0(r5)
  cmpw      r0, r4
  bge-      .loc_0x3EC
  mr        r4, r0

.loc_0x3EC:
  lwz       r3, 0x10(r3)

.loc_0x3F0:
  cmplwi    r3, 0
  bne+      .loc_0x3D0
  lwz       r0, 0x2D0(r29)
  cmpw      r0, r4
  beq-      .loc_0x6F0
  addi      r3, r30, 0x504
  crclr     6, 0x6
  li        r4, 0x58E
  bl        -0x57D0
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x58E
  addi      r5, r13, 0x29F8
  bl        -0x5764
  b         .loc_0x6F0

.loc_0x42C:
  lwz       r0, 0x2CC(r29)
  cmpwi     r0, 0
  ble-      .loc_0x45C
  addi      r3, r30, 0x560
  crclr     6, 0x6
  li        r4, 0x592
  bl        -0x5804
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x592
  addi      r5, r13, 0x29F8
  bl        -0x5798

.loc_0x45C:
  lwz       r0, 0x2DC(r29)
  cmplwi    r0, 0
  beq-      .loc_0x48C
  addi      r3, r30, 0x5A4
  crclr     6, 0x6
  li        r4, 0x593
  bl        -0x5834
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x593
  addi      r5, r13, 0x29F8
  bl        -0x57C8

.loc_0x48C:
  lwz       r4, 0x2D4(r29)
  lwz       r3, 0x2F4(r29)
  b         .loc_0x4B8

.loc_0x498:
  lwz       r5, 0x0(r3)
  cmplwi    r5, 0
  beq-      .loc_0x4B4
  lwz       r0, 0x2D0(r5)
  cmpw      r0, r4
  bge-      .loc_0x4B4
  mr        r4, r0

.loc_0x4B4:
  lwz       r3, 0x10(r3)

.loc_0x4B8:
  cmplwi    r3, 0
  bne+      .loc_0x498
  lwz       r0, 0x2D0(r29)
  cmpw      r0, r4
  beq-      .loc_0x6F0
  addi      r3, r30, 0x504
  crclr     6, 0x6
  li        r4, 0x594
  bl        -0x5898
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x594
  addi      r5, r13, 0x29F8
  bl        -0x582C
  b         .loc_0x6F0

.loc_0x4F4:
  lwz       r0, 0x2DC(r29)
  cmplwi    r0, 0
  bne-      .loc_0x524
  addi      r3, r30, 0x5E0
  crclr     6, 0x6
  li        r4, 0x597
  bl        -0x58CC
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x597
  addi      r5, r13, 0x29F8
  bl        -0x5860

.loc_0x524:
  lwz       r3, 0x2DC(r29)
  bl        -0x5C4
  cmpwi     r3, 0
  bne-      .loc_0x558
  addi      r3, r30, 0x61C
  crclr     6, 0x6
  li        r4, 0x598
  bl        -0x5900
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x598
  addi      r5, r13, 0x29F8
  bl        -0x5894

.loc_0x558:
  lwz       r3, 0x2DC(r29)
  lwz       r3, 0x0(r3)
  b         .loc_0x578

.loc_0x564:
  cmplw     r29, r3
  bne-      .loc_0x574
  li        r0, 0x1
  b         .loc_0x584

.loc_0x574:
  lwz       r3, 0x2E0(r3)

.loc_0x578:
  cmplwi    r3, 0
  bne+      .loc_0x564
  li        r0, 0

.loc_0x584:
  cmpwi     r0, 0
  bne-      .loc_0x5B0
  addi      r3, r30, 0x660
  crclr     6, 0x6
  li        r4, 0x599
  bl        -0x5958
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x599
  addi      r5, r13, 0x29F8
  bl        -0x58EC

.loc_0x5B0:
  lwz       r0, 0x2CC(r29)
  cmpwi     r0, 0
  bgt-      .loc_0x624
  lwz       r4, 0x2D4(r29)
  lwz       r3, 0x2F4(r29)
  b         .loc_0x5E8

.loc_0x5C8:
  lwz       r5, 0x0(r3)
  cmplwi    r5, 0
  beq-      .loc_0x5E4
  lwz       r0, 0x2D0(r5)
  cmpw      r0, r4
  bge-      .loc_0x5E4
  mr        r4, r0

.loc_0x5E4:
  lwz       r3, 0x10(r3)

.loc_0x5E8:
  cmplwi    r3, 0
  bne+      .loc_0x5C8
  lwz       r0, 0x2D0(r29)
  cmpw      r0, r4
  beq-      .loc_0x654
  addi      r3, r30, 0x504
  crclr     6, 0x6
  li        r4, 0x59C
  bl        -0x59C8
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x59C
  addi      r5, r13, 0x29F8
  bl        -0x595C
  b         .loc_0x654

.loc_0x624:
  lwz       r0, 0x2D0(r29)
  cmpwi     r0, 0x20
  beq-      .loc_0x654
  addi      r3, r30, 0x6A4
  crclr     6, 0x6
  li        r4, 0x5A0
  bl        -0x59FC
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x5A0
  addi      r5, r13, 0x29F8
  bl        -0x5990

.loc_0x654:
  mr        r3, r29
  bl        -0x3490
  cmpwi     r3, 0
  beq-      .loc_0x6F0
  addi      r3, r30, 0x6E0
  crclr     6, 0x6
  li        r4, 0x5A2
  bl        -0x5A30
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x5A2
  addi      r5, r13, 0x29F8
  bl        -0x59C4
  b         .loc_0x6F0

.loc_0x68C:
  lwz       r0, 0x2F4(r29)
  cmplwi    r0, 0
  bne-      .loc_0x6A4
  lwz       r0, 0x2F8(r29)
  cmplwi    r0, 0
  beq-      .loc_0x6F0

.loc_0x6A4:
  addi      r3, r30, 0x720
  crclr     6, 0x6
  li        r4, 0x5A6
  bl        -0x5A70
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x5A6
  addi      r5, r13, 0x29F8
  bl        -0x5A04
  b         .loc_0x6F0

.loc_0x6CC:
  crclr     6, 0x6
  addi      r5, r29, 0
  addi      r3, r30, 0x788
  bl        -0x5A98
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x5AC
  addi      r5, r13, 0x29F8
  bl        -0x5A2C

.loc_0x6F0:
  mr        r3, r29
  bl        -0x34F4
  cmpwi     r3, 0
  bne-      .loc_0x724
  addi      r3, r30, 0x7D0
  crclr     6, 0x6
  li        r4, 0x5B1
  bl        -0x5ACC
  addi      r3, r30, 0x60
  crclr     6, 0x6
  li        r4, 0x5B1
  addi      r5, r13, 0x29F8
  bl        -0x5A60

.loc_0x724:
  lwz       r29, 0x2FC(r29)

.loc_0x728:
  cmplwi    r29, 0
  bne+      .loc_0x19C
  mr        r3, r27
  bl        -0x43E0
  mr        r3, r28
  lmw       r26, 0x20(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}
