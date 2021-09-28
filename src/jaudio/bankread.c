

/*
 * --INFO--
 * Address:	8000BE00
 * Size:	000024
 */
void PTconvert(void **, unsigned long)
{
/*
.loc_0x0:
  lwz       r0, 0x0(r3)
  cmplw     r0, r4
  bgelr-    
  cmplwi    r0, 0
  bne-      .loc_0x18
  blr       

.loc_0x18:
  add       r0, r0, r4
  stw       r0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8000BE40
 * Size:	000270
 */
void Bank_Test(unsigned char *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r22, 0x10(r1)
  addi      r31, r3, 0
  addi      r30, r3, 0x20
  lwz       r4, 0x20(r3)
  subis     r0, r4, 0x4241
  cmplwi    r0, 0x4E4B
  beq-      .loc_0x30
  li        r3, 0
  b         .loc_0x25C

.loc_0x30:
  li        r22, 0
  li        r27, 0

.loc_0x38:
  addi      r28, r27, 0x4
  addi      r4, r31, 0
  add       r28, r30, r28
  addi      r3, r28, 0
  bl        -0x88
  lwz       r26, 0x0(r28)
  cmplwi    r26, 0
  beq-      .loc_0x128
  li        r23, 0
  li        r28, 0

.loc_0x60:
  add       r29, r26, r28
  addi      r4, r31, 0
  addi      r25, r29, 0x10
  addi      r3, r25, 0
  bl        -0xB0
  addi      r3, r29, 0x18
  addi      r4, r31, 0
  bl        -0xBC
  addi      r3, r29, 0x20
  addi      r4, r31, 0
  bl        -0xC8
  lwz       r3, 0x0(r25)
  cmplwi    r3, 0
  beq-      .loc_0xB4
  addi      r3, r3, 0x8
  addi      r4, r31, 0
  bl        -0xE0
  lwz       r3, 0x0(r25)
  addi      r4, r31, 0
  addi      r3, r3, 0xC
  bl        -0xF0

.loc_0xB4:
  addi      r23, r23, 0x1
  addi      r28, r28, 0x4
  cmplwi    r23, 0x2
  blt+      .loc_0x60
  li        r23, 0
  li        r28, 0
  b         .loc_0x11C

.loc_0xD0:
  add       r25, r26, r28
  addi      r4, r31, 0
  addi      r3, r25, 0x2C
  bl        -0x11C
  li        r24, 0
  li        r29, 0
  b         .loc_0x104

.loc_0xEC:
  addi      r3, r29, 0x8
  addi      r4, r31, 0
  add       r3, r5, r3
  bl        -0x138
  addi      r24, r24, 0x1
  addi      r29, r29, 0x4

.loc_0x104:
  lwz       r5, 0x2C(r25)
  lwz       r0, 0x4(r5)
  cmplw     r24, r0
  blt+      .loc_0xEC
  addi      r23, r23, 0x1
  addi      r28, r28, 0x4

.loc_0x11C:
  lwz       r0, 0x28(r26)
  cmplw     r23, r0
  blt+      .loc_0xD0

.loc_0x128:
  addi      r22, r22, 0x1
  addi      r27, r27, 0x4
  cmplwi    r22, 0x80
  blt+      .loc_0x38
  li        r24, 0
  li        r27, 0

.loc_0x140:
  addi      r25, r27, 0x204
  addi      r4, r31, 0
  add       r25, r30, r25
  addi      r3, r25, 0
  bl        -0x190
  lwz       r25, 0x0(r25)
  cmplwi    r25, 0
  beq-      .loc_0x190
  li        r23, 0
  li        r28, 0
  b         .loc_0x184

.loc_0x16C:
  addi      r3, r28, 0xC
  addi      r4, r31, 0
  add       r3, r25, r3
  bl        -0x1B8
  addi      r23, r23, 0x1
  addi      r28, r28, 0x4

.loc_0x184:
  lwz       r0, 0x8(r25)
  cmplw     r23, r0
  blt+      .loc_0x16C

.loc_0x190:
  addi      r24, r24, 0x1
  addi      r27, r27, 0x4
  cmplwi    r24, 0x64
  blt+      .loc_0x140
  li        r24, 0
  li        r29, 0

.loc_0x1A8:
  addi      r25, r29, 0x394
  addi      r4, r31, 0
  add       r25, r30, r25
  addi      r3, r25, 0
  bl        -0x1F8
  lwz       r25, 0x0(r25)
  cmplwi    r25, 0
  beq-      .loc_0x248
  li        r23, 0
  li        r28, 0

.loc_0x1D0:
  addi      r26, r28, 0x88
  addi      r4, r31, 0
  add       r26, r25, r26
  addi      r3, r26, 0
  bl        -0x220
  lwz       r26, 0x0(r26)
  cmplwi    r26, 0
  beq-      .loc_0x238
  addi      r3, r26, 0x8
  addi      r4, r31, 0
  bl        -0x238
  addi      r3, r26, 0xC
  addi      r4, r31, 0
  bl        -0x244
  li        r22, 0
  li        r27, 0
  b         .loc_0x22C

.loc_0x214:
  addi      r3, r27, 0x14
  addi      r4, r31, 0
  add       r3, r26, r3
  bl        -0x260
  addi      r22, r22, 0x1
  addi      r27, r27, 0x4

.loc_0x22C:
  lwz       r0, 0x10(r26)
  cmplw     r22, r0
  blt+      .loc_0x214

.loc_0x238:
  addi      r23, r23, 0x1
  addi      r28, r28, 0x4
  cmplwi    r23, 0x80
  blt+      .loc_0x1D0

.loc_0x248:
  addi      r24, r24, 0x1
  addi      r29, r29, 0x4
  cmplwi    r24, 0xC
  blt+      .loc_0x1A8
  mr        r3, r30

.loc_0x25C:
  lmw       r22, 0x10(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000C0C0
 * Size:	000068
 */
void __Bank_Regist_Inner(unsigned char *, unsigned long, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stmw      r30, 0x18(r1)
  addi      r30, r3, 0
  addi      r31, r4, 0
  addi      r3, r5, 0
  bl        0xE44
  mr        r3, r30
  bl        -0x2A4
  lis       r4, 0x8031
  rlwinm    r5,r31,2,0,29
  subi      r0, r4, 0x3520
  add       r4, r0, r5
  stw       r3, 0x0(r4)
  lwz       r0, 0x0(r4)
  cmplwi    r0, 0
  bne-      .loc_0x50
  li        r3, 0
  b         .loc_0x54

.loc_0x50:
  li        r3, 0x1

.loc_0x54:
  lwz       r0, 0x24(r1)
  lmw       r30, 0x18(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000C140
 * Size:	000024
 */
void Bank_Regist(void *, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x8(r3)
  bl        -0x90
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void Bank_Regist_Direct(void *, unsigned long, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000C180
 * Size:	00002C
 */
void Bank_Init()
{
/*
.loc_0x0:
  li        r3, 0
  lis       r4, 0x8031
  li        r0, 0x100
  addi      r6, r3, 0
  subi      r5, r4, 0x3520
  mtctr     r0

.loc_0x18:
  add       r4, r5, r3
  addi      r3, r3, 0x4
  stw       r6, 0x0(r4)
  bdnz+     .loc_0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	8000C1C0
 * Size:	000028
 */
void Bank_Get(unsigned long)
{
/*
.loc_0x0:
  cmplwi    r3, 0x100
  blt-      .loc_0x10
  li        r3, 0
  blr       

.loc_0x10:
  lis       r4, 0x8031
  rlwinm    r3,r3,2,0,29
  subi      r0, r4, 0x3520
  add       r3, r0, r3
  lwz       r3, 0x0(r3)
  blr
*/
}