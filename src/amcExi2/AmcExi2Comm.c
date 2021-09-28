

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void EXI2_SetTRKCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80220E2C
 * Size:	000040
 */
void EXI2_CallBack(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x8(r1)
  lwz       r3, 0x2AF0(r13)
  stb       r0, 0x0(r3)
  lwz       r12, 0x34A8(r13)
  cmplwi    r12, 0
  beq-      .loc_0x30
  mtlr      r12
  li        r3, 0
  blrl      

.loc_0x30:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void EXI2_Select(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void EXI2_ToWriteMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void EXI2_ToReadMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void EXI2_StartRead(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void EXI2_FinishRead(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void EXI2_SendCmd(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80220E6C
 * Size:	0000BC
 */
void EXI2_Init(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  mr        r31, r4
  lwz       r0, 0x2AF0(r13)
  stw       r0, 0x0(r3)
  bl        -0x27F0C
  stw       r31, 0x34A8(r13)
  bl        -0x27EEC
  bl        -0xA8
  lis       r4, 0x100
  li        r3, 0
  addi      r0, r4, 0x3
  stw       r3, 0x20(r1)
  stw       r0, 0x1C(r1)
  b         .loc_0x4C

.loc_0x44:
  li        r3, 0x5
  bl        -0x240

.loc_0x4C:
  cmpwi     r3, 0
  beq+      .loc_0x44
  lis       r0, 0x8000
  stw       r0, 0x10(r1)
  addi      r3, r1, 0x10
  li        r4, 0x2
  li        r5, 0x1
  li        r6, 0
  bl        -0x6EC
  bl        -0x4AC
  addi      r3, r1, 0x1C
  li        r4, 0x4
  li        r5, 0x1
  li        r6, 0
  bl        -0x704
  bl        -0x4C4
  addi      r3, r1, 0x20
  li        r4, 0x4
  li        r5, 0x1
  li        r6, 0
  bl        -0x71C
  bl        -0x4DC
  bl        -0x21C
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80220F28
 * Size:	00002C
 */
void EXI2_EnableInterrupts(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x8022
  stw       r0, 0x4(r1)
  addi      r3, r3, 0xE2C
  stwu      r1, -0x8(r1)
  bl        -0x334
  bl        -0x194
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80220F54
 * Size:	000108
 */
void EXI2_Poll(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0xCC00
  stw       r0, 0x4(r1)
  lwz       r0, 0x3000(r3)
  stwu      r1, -0x20(r1)
  rlwinm.   r0,r0,0,19,19
  bne-      .loc_0x38
  lwz       r3, 0x2AF0(r13)
  lbz       r0, 0x0(r3)
  cmplwi    r0, 0
  bne-      .loc_0x38
  li        r0, 0
  stw       r0, 0x18(r1)
  b         .loc_0xF4

.loc_0x38:
  lwz       r0, 0x34A4(r13)
  cmpwi     r0, 0
  bne-      .loc_0xB4
  li        r3, 0
  b         .loc_0x54

.loc_0x4C:
  li        r3, 0x5
  bl        -0x330

.loc_0x54:
  cmpwi     r3, 0
  beq+      .loc_0x4C
  bne-      .loc_0x74
  lis       r3, 0x802F
  crclr     6, 0x6
  subi      r3, r3, 0x69F0
  bl        -0xA860
  b         .loc_0xB4

.loc_0x74:
  li        r3, 0x1
  li        r0, 0
  stw       r3, 0x34A4(r13)
  addi      r3, r1, 0x8
  stw       r0, 0x8(r1)
  li        r4, 0x2
  li        r5, 0x1
  li        r6, 0
  bl        -0x7FC
  bl        -0x5BC
  addi      r3, r1, 0x14
  li        r4, 0x2
  li        r5, 0
  li        r6, 0
  bl        -0x814
  bl        -0x5D4

.loc_0xB4:
  addi      r3, r1, 0x18
  li        r4, 0x4
  li        r5, 0
  li        r6, 0
  bl        -0x82C
  bl        -0x5EC
  lwz       r5, 0x2AF0(r13)
  lbz       r0, 0x0(r5)
  cmplwi    r0, 0
  bne-      .loc_0xF4
  lis       r4, 0xCC00
  lwz       r3, 0x3000(r4)
  li        r0, 0x1
  stb       r0, 0x0(r5)
  rlwinm    r0,r3,0,19,19
  stw       r0, 0x3000(r4)

.loc_0xF4:
  lwz       r0, 0x24(r1)
  lwz       r3, 0x18(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8022105C
 * Size:	0002BC
 */
void EXI2_ReadN(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stmw      r25, 0x2C(r1)
  addi      r25, r3, 0
  addi      r26, r4, 0
  lwz       r0, 0x34A4(r13)
  cmpwi     r0, 0
  beq-      .loc_0x2C
  li        r27, 0x1
  b         .loc_0xA4

.loc_0x2C:
  li        r3, 0
  b         .loc_0x3C

.loc_0x34:
  li        r3, 0x5
  bl        -0x420

.loc_0x3C:
  cmpwi     r3, 0
  beq+      .loc_0x34
  mr        r27, r3
  bne-      .loc_0x64
  lis       r3, 0x802F
  crclr     6, 0x6
  subi      r3, r3, 0x69F0
  bl        -0xA954
  li        r27, 0
  b         .loc_0xA4

.loc_0x64:
  li        r3, 0x1
  li        r0, 0
  stw       r3, 0x34A4(r13)
  addi      r3, r1, 0x14
  stw       r0, 0x14(r1)
  li        r4, 0x2
  li        r5, 0x1
  li        r6, 0
  bl        -0x8F4
  bl        -0x6B4
  addi      r3, r1, 0x1C
  li        r4, 0x2
  li        r5, 0
  li        r6, 0
  bl        -0x90C
  bl        -0x6CC

.loc_0xA4:
  cmpwi     r27, 0
  bne-      .loc_0xB4
  li        r3, 0x1
  b         .loc_0x2A8

.loc_0xB4:
  rlwinm.   r4,r26,0,30,31
  beq-      .loc_0xC4
  li        r3, 0x1
  b         .loc_0xC8

.loc_0xC4:
  li        r3, 0

.loc_0xC8:
  srawi     r28, r26, 0x2
  rlwinm    r0,r26,30,2,31
  addze     r28, r28
  add       r3, r0, r3
  rlwinm    r0,r26,0,31,31
  rlwinm    r28,r28,2,0,29
  add       r29, r4, r0
  subc      r28, r26, r28
  subi      r31, r3, 0x1
  li        r27, 0
  li        r30, 0
  b         .loc_0x278

.loc_0xF8:
  cmplw     r30, r31
  bge-      .loc_0x108
  li        r4, 0x4
  b         .loc_0x11C

.loc_0x108:
  cmplwi    r29, 0x2
  bne-      .loc_0x118
  li        r4, 0x2
  b         .loc_0x11C

.loc_0x118:
  li        r4, 0x4

.loc_0x11C:
  addi      r3, r1, 0x20
  li        r5, 0
  li        r6, 0
  bl        -0x998
  bl        -0x758
  sub       r0, r26, r27
  cmplwi    r0, 0x4
  blt-      .loc_0x144
  li        r5, 0x4
  b         .loc_0x148

.loc_0x144:
  mr        r5, r28

.loc_0x148:
  cmpwi     r5, 0
  li        r4, 0
  ble-      .loc_0x270
  cmpwi     r5, 0x8
  subi      r3, r5, 0x8
  ble-      .loc_0x29C
  addi      r0, r3, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r3, 0
  mtctr     r0
  add       r3, r25, r27
  ble-      .loc_0x29C

.loc_0x178:
  subfic    r0, r4, 0x3
  lwz       r6, 0x20(r1)
  rlwinm    r0,r0,3,0,28
  srw       r0, r6, r0
  stb       r0, 0x0(r3)
  addi      r0, r4, 0x1
  subfic    r0, r0, 0x3
  lwz       r7, 0x20(r1)
  rlwinm    r6,r0,3,0,28
  addi      r0, r4, 0x2
  srw       r6, r7, r6
  stb       r6, 0x1(r3)
  subfic    r0, r0, 0x3
  rlwinm    r7,r0,3,0,28
  lwz       r8, 0x20(r1)
  neg       r6, r4
  addi      r0, r4, 0x4
  srw       r7, r8, r7
  stb       r7, 0x2(r3)
  subfic    r8, r0, 0x3
  addi      r0, r4, 0x5
  lwz       r9, 0x20(r1)
  subfic    r7, r0, 0x3
  rlwinm    r6,r6,3,0,28
  srw       r0, r9, r6
  stb       r0, 0x3(r3)
  addi      r0, r4, 0x6
  subfic    r6, r0, 0x3
  lwz       r9, 0x20(r1)
  addi      r0, r4, 0x7
  rlwinm    r8,r8,3,0,28
  srw       r8, r9, r8
  stb       r8, 0x4(r3)
  subfic    r0, r0, 0x3
  rlwinm    r7,r7,3,0,28
  lwz       r8, 0x20(r1)
  rlwinm    r6,r6,3,0,28
  rlwinm    r0,r0,3,0,28
  srw       r7, r8, r7
  stb       r7, 0x5(r3)
  addi      r4, r4, 0x8
  lwz       r7, 0x20(r1)
  srw       r6, r7, r6
  stb       r6, 0x6(r3)
  lwz       r6, 0x20(r1)
  srw       r0, r6, r0
  stb       r0, 0x7(r3)
  addi      r3, r3, 0x8
  bdnz+     .loc_0x178
  b         .loc_0x29C

.loc_0x240:
  sub       r0, r5, r4
  cmpw      r4, r5
  mtctr     r0
  bge-      .loc_0x270

.loc_0x250:
  subfic    r0, r4, 0x3
  lwz       r3, 0x20(r1)
  rlwinm    r0,r0,3,0,28
  srw       r0, r3, r0
  stb       r0, 0x0(r6)
  addi      r6, r6, 0x1
  addi      r4, r4, 0x1
  bdnz+     .loc_0x250

.loc_0x270:
  addi      r30, r30, 0x1
  addi      r27, r27, 0x4

.loc_0x278:
  cmplw     r27, r26
  blt+      .loc_0xF8
  bl        -0x5E8
  li        r0, 0
  lwz       r4, 0x2AF0(r13)
  stw       r0, 0x34A4(r13)
  li        r3, 0
  stb       r0, 0x0(r4)
  b         .loc_0x2A8

.loc_0x29C:
  add       r6, r27, r4
  add       r6, r25, r6
  b         .loc_0x240

.loc_0x2A8:
  lmw       r25, 0x2C(r1)
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80221318
 * Size:	0001B0
 */
void EXI2_WriteN(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  stw       r30, 0x38(r1)
  stw       r29, 0x34(r1)
  addi      r29, r3, 0
  li        r3, 0
  stw       r28, 0x30(r1)
  stw       r4, 0x28(r1)
  b         .loc_0x34

.loc_0x2C:
  li        r3, 0x5
  bl        -0x6D4

.loc_0x34:
  cmpwi     r3, 0
  beq+      .loc_0x2C
  bne-      .loc_0x48
  li        r3, 0x1
  b         .loc_0x190

.loc_0x48:
  lis       r0, 0x8000
  stw       r0, 0x18(r1)
  addi      r3, r1, 0x18
  li        r4, 0x2
  li        r5, 0x1
  li        r6, 0
  bl        -0xB8C
  bl        -0x94C
  addi      r3, r1, 0x28
  li        r4, 0x4
  li        r5, 0x1
  li        r6, 0
  bl        -0xBA4
  bl        -0x964
  lwz       r4, 0x28(r1)
  rlwinm.   r0,r4,0,30,31
  beq-      .loc_0x94
  li        r3, 0x1
  b         .loc_0x98

.loc_0x94:
  li        r3, 0

.loc_0x98:
  rlwinm    r0,r4,30,2,31
  add       r28, r0, r3
  subi      r31, r28, 0x1
  li        r30, 0
  b         .loc_0xFC

.loc_0xAC:
  cmplw     r30, r31
  bge-      .loc_0xBC
  li        r4, 0x4
  b         .loc_0xE0

.loc_0xBC:
  lwz       r0, 0x28(r1)
  rlwinm    r3,r0,0,30,31
  rlwinm    r0,r0,0,31,31
  add       r0, r3, r0
  cmplwi    r0, 0x2
  bne-      .loc_0xDC
  li        r4, 0x2
  b         .loc_0xE0

.loc_0xDC:
  li        r4, 0x4

.loc_0xE0:
  addi      r3, r29, 0
  li        r5, 0x1
  li        r6, 0
  addi      r29, r29, 0x4
  bl        -0xC1C
  bl        -0x9DC
  addi      r30, r30, 0x1

.loc_0xFC:
  cmplw     r30, r28
  blt+      .loc_0xAC
  bl        -0x728
  li        r3, 0
  b         .loc_0x118

.loc_0x110:
  li        r3, 0x5
  bl        -0x7B8

.loc_0x118:
  cmpwi     r3, 0
  beq+      .loc_0x110
  bne-      .loc_0x12C
  li        r3, 0x1
  b         .loc_0x190

.loc_0x12C:
  lis       r0, 0x1
  stw       r0, 0x10(r1)
  addi      r3, r1, 0x10
  li        r4, 0x2
  li        r5, 0x1
  li        r6, 0
  bl        -0xC70
  bl        -0xA30
  addi      r3, r1, 0x24
  li        r4, 0x2
  li        r5, 0
  li        r6, 0
  bl        -0xC88
  bl        -0xA48

.loc_0x164:
  addi      r3, r1, 0x24
  li        r4, 0x2
  li        r5, 0
  li        r6, 0
  bl        -0xCA0
  bl        -0xA60
  lwz       r0, 0x24(r1)
  rlwinm.   r0,r0,16,31,31
  beq+      .loc_0x164
  bl        -0x7AC
  li        r3, 0

.loc_0x190:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  mtlr      r0
  lwz       r29, 0x34(r1)
  lwz       r28, 0x30(r1)
  addi      r1, r1, 0x40
  blr
*/
}

/*
 * --INFO--
 * Address:	802214C8
 * Size:	000004
 */
void EXI2_Reserve(void)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	802214CC
 * Size:	000004
 */
void EXI2_Unreserve(void)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void EXI2_GetStatusReg(void)
{
	// UNUSED FUNCTION
}