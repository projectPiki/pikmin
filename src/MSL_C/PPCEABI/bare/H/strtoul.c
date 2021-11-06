

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void strtoumax(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
void strtoimax(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void atol(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80219B9C
 * Size:	0000C4
 */
void atoi(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  lis       r31, 0x8000
  subi      r4, r31, 0x1
  stw       r3, 0x18(r1)
  lis       r3, 0x8022
  subi      r5, r3, 0x7EB0
  stw       r0, 0x1C(r1)
  addi      r6, r1, 0x18
  addi      r7, r1, 0xC
  addi      r8, r1, 0x10
  addi      r9, r1, 0x14
  li        r3, 0xA
  bl        0x5EC
  lwz       r0, 0x14(r1)
  cmpwi     r0, 0
  bne-      .loc_0x7C
  lwz       r4, 0x10(r1)
  cmpwi     r4, 0
  bne-      .loc_0x68
  subi      r0, r31, 0x1
  cmplw     r3, r0
  bgt-      .loc_0x7C

.loc_0x68:
  cmpwi     r4, 0
  beq-      .loc_0xA4
  lis       r0, 0x8000
  cmplw     r3, r0
  ble-      .loc_0xA4

.loc_0x7C:
  lwz       r0, 0x10(r1)
  cmpwi     r0, 0
  beq-      .loc_0x90
  lis       r3, 0x8000
  b         .loc_0x98

.loc_0x90:
  lis       r3, 0x8000
  subi      r3, r3, 0x1

.loc_0x98:
  li        r0, 0x22
  stw       r0, 0x3490(r13)
  b         .loc_0xB0

.loc_0xA4:
  cmpwi     r4, 0
  beq-      .loc_0xB0
  neg       r3, r3

.loc_0xB0:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
void strtoll(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80219C60
 * Size:	0000F0
 */
void strtol(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x8000
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r4, 0
  subi      r4, r6, 0x1
  stw       r30, 0x28(r1)
  mr        r30, r3
  lis       r3, 0x8022
  stw       r30, 0x14(r1)
  addi      r6, r1, 0x14
  addi      r7, r1, 0x24
  stw       r0, 0x18(r1)
  subi      r0, r3, 0x7EB0
  addi      r3, r5, 0
  mr        r5, r0
  addi      r8, r1, 0x20
  addi      r9, r1, 0x1C
  bl        0x518
  cmplwi    r31, 0
  beq-      .loc_0x68
  lwz       r0, 0x24(r1)
  add       r0, r30, r0
  stw       r0, 0x0(r31)

.loc_0x68:
  lwz       r0, 0x1C(r1)
  cmpwi     r0, 0
  bne-      .loc_0xA4
  lwz       r5, 0x20(r1)
  cmpwi     r5, 0
  bne-      .loc_0x90
  lis       r4, 0x8000
  subi      r0, r4, 0x1
  cmplw     r3, r0
  bgt-      .loc_0xA4

.loc_0x90:
  cmpwi     r5, 0
  beq-      .loc_0xCC
  lis       r0, 0x8000
  cmplw     r3, r0
  ble-      .loc_0xCC

.loc_0xA4:
  lwz       r0, 0x20(r1)
  cmpwi     r0, 0
  beq-      .loc_0xB8
  lis       r3, 0x8000
  b         .loc_0xC0

.loc_0xB8:
  lis       r3, 0x8000
  subi      r3, r3, 0x1

.loc_0xC0:
  li        r0, 0x22
  stw       r0, 0x3490(r13)
  b         .loc_0xD8

.loc_0xCC:
  cmpwi     r5, 0
  beq-      .loc_0xD8
  neg       r3, r3

.loc_0xD8:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  mtlr      r0
  addi      r1, r1, 0x30
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void strtoull(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80219D50
 * Size:	0000AC
 */
void strtoul(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x8000
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r4, 0
  subi      r4, r6, 0x1
  stw       r30, 0x28(r1)
  mr        r30, r3
  lis       r3, 0x8022
  stw       r30, 0x14(r1)
  addi      r6, r1, 0x14
  addi      r7, r1, 0x24
  stw       r0, 0x18(r1)
  subi      r0, r3, 0x7EB0
  addi      r3, r5, 0
  mr        r5, r0
  addi      r8, r1, 0x20
  addi      r9, r1, 0x1C
  bl        0x428
  cmplwi    r31, 0
  beq-      .loc_0x68
  lwz       r0, 0x24(r1)
  add       r0, r30, r0
  stw       r0, 0x0(r31)

.loc_0x68:
  lwz       r0, 0x1C(r1)
  cmpwi     r0, 0
  beq-      .loc_0x84
  li        r0, 0x22
  stw       r0, 0x3490(r13)
  li        r3, -0x1
  b         .loc_0x94

.loc_0x84:
  lwz       r0, 0x20(r1)
  cmpwi     r0, 0
  beq-      .loc_0x94
  neg       r3, r3

.loc_0x94:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  mtlr      r0
  addi      r1, r1, 0x30
  blr
*/
}

/*
 * --INFO--
 * Address:	80219DFC
 * Size:	0003CC
 */
void __strtoull(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x78(r1)
  stmw      r15, 0x34(r1)
  mr.       r31, r3
  addi      r21, r9, 0
  mr        r16, r8
  addi      r17, r4, 0
  addi      r27, r5, 0
  addi      r26, r6, 0
  addi      r15, r7, 0
  li        r30, 0x1
  li        r29, 0
  li        r28, 0
  li        r25, 0
  li        r23, 0
  li        r24, 0
  stw       r0, 0x0(r9)
  stw       r0, 0x0(r8)
  blt-      .loc_0x6C
  cmpwi     r31, 0x1
  beq-      .loc_0x6C
  cmpwi     r31, 0x24
  bgt-      .loc_0x6C
  cmpwi     r17, 0x1
  bge-      .loc_0x74

.loc_0x6C:
  li        r30, 0x40
  b         .loc_0x94

.loc_0x74:
  addi      r12, r27, 0
  mtlr      r12
  addi      r3, r26, 0
  li        r29, 0x1
  li        r4, 0
  li        r5, 0
  blrl      
  mr        r20, r3

.loc_0x94:
  cmpwi     r31, 0
  beq-      .loc_0xB8
  srawi     r5, r31, 0x1F
  addi      r6, r31, 0
  li        r3, -0x1
  li        r4, -0x1
  bl        -0x4FEC
  addi      r23, r4, 0
  addi      r24, r3, 0

.loc_0xB8:
  lis       r3, 0x8022
  lis       r4, 0x802F
  addi      r22, r3, 0x2808
  subi      r18, r4, 0x6C10
  b         .loc_0x360

.loc_0xCC:
  cmplwi    r30, 0x10
  bgt-      .loc_0x360
  rlwinm    r0,r30,2,0,29
  lwzx      r0, r18, r0
  mtctr     r0
  bctr      
  rlwinm    r0,r20,0,24,31
  add       r3, r22, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,29,30
  beq-      .loc_0x11C
  addi      r12, r27, 0
  mtlr      r12
  addi      r3, r26, 0
  li        r4, 0
  li        r5, 0
  addi      r29, r29, 0x1
  blrl      
  mr        r20, r3
  b         .loc_0x360

.loc_0x11C:
  cmpwi     r20, 0x2B
  bne-      .loc_0x148
  addi      r12, r27, 0
  mtlr      r12
  addi      r3, r26, 0
  li        r4, 0
  li        r5, 0
  addi      r29, r29, 0x1
  blrl      
  mr        r20, r3
  b         .loc_0x178

.loc_0x148:
  cmpwi     r20, 0x2D
  bne-      .loc_0x178
  addi      r12, r27, 0
  mtlr      r12
  addi      r3, r26, 0
  li        r4, 0
  li        r5, 0
  addi      r29, r29, 0x1
  blrl      
  li        r0, 0x1
  stw       r0, 0x0(r16)
  mr        r20, r3

.loc_0x178:
  li        r30, 0x2
  b         .loc_0x360
  cmpwi     r31, 0
  beq-      .loc_0x190
  cmpwi     r31, 0x10
  bne-      .loc_0x1C0

.loc_0x190:
  cmpwi     r20, 0x30
  bne-      .loc_0x1C0
  addi      r12, r27, 0
  mtlr      r12
  addi      r3, r26, 0
  li        r30, 0x4
  li        r4, 0
  li        r5, 0
  addi      r29, r29, 0x1
  blrl      
  mr        r20, r3
  b         .loc_0x360

.loc_0x1C0:
  li        r30, 0x8
  b         .loc_0x360
  cmpwi     r20, 0x58
  beq-      .loc_0x1D8
  cmpwi     r20, 0x78
  bne-      .loc_0x204

.loc_0x1D8:
  addi      r12, r27, 0
  mtlr      r12
  addi      r3, r26, 0
  li        r31, 0x10
  li        r30, 0x8
  li        r4, 0
  li        r5, 0
  addi      r29, r29, 0x1
  blrl      
  mr        r20, r3
  b         .loc_0x360

.loc_0x204:
  cmpwi     r31, 0
  bne-      .loc_0x210
  li        r31, 0x8

.loc_0x210:
  li        r30, 0x10
  b         .loc_0x360
  cmpwi     r31, 0
  bne-      .loc_0x224
  li        r31, 0xA

.loc_0x224:
  li        r0, 0
  xor       r3, r23, r0
  xor       r0, r24, r0
  or.       r0, r3, r0
  bne-      .loc_0x254
  srawi     r5, r31, 0x1F
  addi      r6, r31, 0
  li        r3, -0x1
  li        r4, -0x1
  bl        -0x5188
  addi      r23, r4, 0
  addi      r24, r3, 0

.loc_0x254:
  rlwinm    r0,r20,0,24,31
  add       r3, r22, r0
  lbz       r3, 0x0(r3)
  rlwinm.   r0,r3,0,27,27
  beq-      .loc_0x290
  subi      r20, r20, 0x30
  cmpw      r20, r31
  blt-      .loc_0x2D0
  cmpwi     r30, 0x10
  bne-      .loc_0x284
  li        r30, 0x20
  b         .loc_0x288

.loc_0x284:
  li        r30, 0x40

.loc_0x288:
  addi      r20, r20, 0x30
  b         .loc_0x360

.loc_0x290:
  rlwinm.   r0,r3,0,24,25
  beq-      .loc_0x2AC
  mr        r3, r20
  bl        -0x42E4
  subi      r0, r3, 0x37
  cmpw      r0, r31
  blt-      .loc_0x2C4

.loc_0x2AC:
  cmpwi     r30, 0x10
  bne-      .loc_0x2BC
  li        r30, 0x20
  b         .loc_0x360

.loc_0x2BC:
  li        r30, 0x40
  b         .loc_0x360

.loc_0x2C4:
  mr        r3, r20
  bl        -0x4310
  subi      r20, r3, 0x37

.loc_0x2D0:
  subc      r0, r23, r28
  subfe     r0, r25, r24
  subfe     r0, r19, r19
  neg.      r0, r0
  beq-      .loc_0x2EC
  li        r0, 0x1
  stw       r0, 0x0(r21)

.loc_0x2EC:
  mullw     r4, r25, r31
  mulhwu    r0, r28, r31
  srawi     r3, r31, 0x1F
  add       r4, r4, r0
  mullw     r0, r28, r3
  mullw     r28, r28, r31
  srawi     r5, r20, 0x1F
  li        r3, -0x1
  add       r25, r4, r0
  subc      r0, r3, r28
  subfe     r3, r25, r3
  subc      r0, r0, r20
  subfe     r0, r5, r3
  subfe     r0, r19, r19
  neg.      r0, r0
  beq-      .loc_0x334
  li        r0, 0x1
  stw       r0, 0x0(r21)

.loc_0x334:
  addi      r12, r27, 0
  addc      r28, r28, r20
  mtlr      r12
  adde      r25, r25, r5
  addi      r3, r26, 0
  li        r30, 0x10
  li        r4, 0
  li        r5, 0
  addi      r29, r29, 0x1
  blrl      
  mr        r20, r3

.loc_0x360:
  cmpw      r29, r17
  bgt-      .loc_0x378
  cmpwi     r20, -0x1
  beq-      .loc_0x378
  rlwinm.   r0,r30,0,25,26
  beq+      .loc_0xCC

.loc_0x378:
  andi.     r0, r30, 0x34
  bne-      .loc_0x390
  li        r28, 0
  li        r25, 0
  li        r29, 0
  b         .loc_0x394

.loc_0x390:
  subi      r29, r29, 0x1

.loc_0x394:
  mr        r12, r27
  stw       r29, 0x0(r15)
  mtlr      r12
  addi      r3, r26, 0
  addi      r4, r20, 0
  li        r5, 0x1
  blrl      
  addi      r4, r28, 0
  lwz       r0, 0x7C(r1)
  addi      r3, r25, 0
  lmw       r15, 0x34(r1)
  mtlr      r0
  addi      r1, r1, 0x78
  blr
*/
}

/*
 * --INFO--
 * Address:	8021A1C8
 * Size:	000348
 */
void __strtoul(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x60(r1)
  stmw      r18, 0x28(r1)
  mr.       r28, r3
  addi      r23, r9, 0
  mr        r21, r8
  addi      r22, r4, 0
  addi      r29, r5, 0
  addi      r30, r6, 0
  addi      r19, r7, 0
  li        r24, 0x1
  li        r31, 0
  li        r27, 0
  li        r26, 0
  stw       r0, 0x0(r9)
  stw       r0, 0x0(r8)
  blt-      .loc_0x64
  cmpwi     r28, 0x1
  beq-      .loc_0x64
  cmpwi     r28, 0x24
  bgt-      .loc_0x64
  cmpwi     r22, 0x1
  bge-      .loc_0x6C

.loc_0x64:
  li        r24, 0x40
  b         .loc_0x8C

.loc_0x6C:
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r30, 0
  li        r31, 0x1
  li        r4, 0
  li        r5, 0
  blrl      
  mr        r18, r3

.loc_0x8C:
  cmpwi     r28, 0
  beq-      .loc_0x9C
  li        r0, -0x1
  divwu     r26, r0, r28

.loc_0x9C:
  lis       r3, 0x8022
  lis       r4, 0x802F
  addi      r25, r3, 0x2808
  subi      r20, r4, 0x6BCC
  b         .loc_0x2E4

.loc_0xB0:
  cmplwi    r24, 0x10
  bgt-      .loc_0x2E4
  rlwinm    r0,r24,2,0,29
  lwzx      r0, r20, r0
  mtctr     r0
  bctr      
  rlwinm    r0,r18,0,24,31
  add       r3, r25, r0
  lbz       r0, 0x0(r3)
  rlwinm.   r0,r0,0,29,30
  beq-      .loc_0x100
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r30, 0
  li        r4, 0
  li        r5, 0
  addi      r31, r31, 0x1
  blrl      
  mr        r18, r3
  b         .loc_0x2E4

.loc_0x100:
  cmpwi     r18, 0x2B
  bne-      .loc_0x12C
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r30, 0
  li        r4, 0
  li        r5, 0
  addi      r31, r31, 0x1
  blrl      
  mr        r18, r3
  b         .loc_0x15C

.loc_0x12C:
  cmpwi     r18, 0x2D
  bne-      .loc_0x15C
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r30, 0
  li        r4, 0
  li        r5, 0
  addi      r31, r31, 0x1
  blrl      
  li        r0, 0x1
  stw       r0, 0x0(r21)
  mr        r18, r3

.loc_0x15C:
  li        r24, 0x2
  b         .loc_0x2E4
  cmpwi     r28, 0
  beq-      .loc_0x174
  cmpwi     r28, 0x10
  bne-      .loc_0x1A4

.loc_0x174:
  cmpwi     r18, 0x30
  bne-      .loc_0x1A4
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r30, 0
  li        r24, 0x4
  li        r4, 0
  li        r5, 0
  addi      r31, r31, 0x1
  blrl      
  mr        r18, r3
  b         .loc_0x2E4

.loc_0x1A4:
  li        r24, 0x8
  b         .loc_0x2E4
  cmpwi     r18, 0x58
  beq-      .loc_0x1BC
  cmpwi     r18, 0x78
  bne-      .loc_0x1E8

.loc_0x1BC:
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r30, 0
  li        r28, 0x10
  li        r24, 0x8
  li        r4, 0
  li        r5, 0
  addi      r31, r31, 0x1
  blrl      
  mr        r18, r3
  b         .loc_0x2E4

.loc_0x1E8:
  cmpwi     r28, 0
  bne-      .loc_0x1F4
  li        r28, 0x8

.loc_0x1F4:
  li        r24, 0x10
  b         .loc_0x2E4
  cmpwi     r28, 0
  bne-      .loc_0x208
  li        r28, 0xA

.loc_0x208:
  cmplwi    r26, 0
  bne-      .loc_0x218
  li        r0, -0x1
  divwu     r26, r0, r28

.loc_0x218:
  rlwinm    r0,r18,0,24,31
  add       r3, r25, r0
  lbz       r3, 0x0(r3)
  rlwinm.   r0,r3,0,27,27
  beq-      .loc_0x254
  subi      r18, r18, 0x30
  cmpw      r18, r28
  blt-      .loc_0x294
  cmpwi     r24, 0x10
  bne-      .loc_0x248
  li        r24, 0x20
  b         .loc_0x24C

.loc_0x248:
  li        r24, 0x40

.loc_0x24C:
  addi      r18, r18, 0x30
  b         .loc_0x2E4

.loc_0x254:
  rlwinm.   r0,r3,0,24,25
  beq-      .loc_0x270
  mr        r3, r18
  bl        -0x4674
  subi      r0, r3, 0x37
  cmpw      r0, r28
  blt-      .loc_0x288

.loc_0x270:
  cmpwi     r24, 0x10
  bne-      .loc_0x280
  li        r24, 0x20
  b         .loc_0x2E4

.loc_0x280:
  li        r24, 0x40
  b         .loc_0x2E4

.loc_0x288:
  mr        r3, r18
  bl        -0x46A0
  subi      r18, r3, 0x37

.loc_0x294:
  cmplw     r27, r26
  ble-      .loc_0x2A4
  li        r0, 0x1
  stw       r0, 0x0(r23)

.loc_0x2A4:
  mullw     r27, r27, r28
  subfic    r0, r27, -0x1
  cmplw     r18, r0
  ble-      .loc_0x2BC
  li        r0, 0x1
  stw       r0, 0x0(r23)

.loc_0x2BC:
  addi      r12, r29, 0
  mtlr      r12
  addi      r3, r30, 0
  add       r27, r27, r18
  li        r24, 0x10
  li        r4, 0
  li        r5, 0
  addi      r31, r31, 0x1
  blrl      
  mr        r18, r3

.loc_0x2E4:
  cmpw      r31, r22
  bgt-      .loc_0x2FC
  cmpwi     r18, -0x1
  beq-      .loc_0x2FC
  rlwinm.   r0,r24,0,25,26
  beq+      .loc_0xB0

.loc_0x2FC:
  andi.     r0, r24, 0x34
  bne-      .loc_0x310
  li        r27, 0
  li        r31, 0
  b         .loc_0x314

.loc_0x310:
  subi      r31, r31, 0x1

.loc_0x314:
  mr        r12, r29
  stw       r31, 0x0(r19)
  mtlr      r12
  addi      r3, r30, 0
  addi      r4, r18, 0
  li        r5, 0x1
  blrl      
  mr        r3, r27
  lmw       r18, 0x28(r1)
  lwz       r0, 0x64(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}
