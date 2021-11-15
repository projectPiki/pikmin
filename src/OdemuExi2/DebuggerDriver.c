#include "types.h"

#define OS_INTERRUPTMASK_EXI_2 0x18000
#define OS_INTERRUPTMASK_PI_DEBUG 0x40
#define __OS_INTERRUPT_PI_DEBUG 0x19
#define DB_NO_ERROR 0
#define ODEMU_ADDR_PC2NNGC 0x10000
#define ODEMU_OFFSET_NNGC2PC 0x405
#define ODEMU_ADDR_NNGC2PC 0x1C000

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
/*
void DBGEXIInit(void)
{
	// UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
/*
void DBGEXISelect(void)
{
	// UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
/*
void DBGEXIDeselect(void)
{
	// UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
/*
void DBGEXISync(void)
{
	// UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	802214D8
 * Size:	000298
 */
void DBGEXIImm(void)
{
/*
.loc_0x0:
  stwu      r1, -0x48(r1)
  cmplwi    r5, 0
  stmw      r22, 0x20(r1)
  beq-      .loc_0x144
  li        r29, 0
  cmpw      r29, r4
  li        r30, 0
  bge-      .loc_0x13C
  cmpwi     r4, 0x8
  subi      r6, r4, 0x8
  ble-      .loc_0x284
  addi      r0, r6, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r6, 0
  mtctr     r0
  addi      r31, r3, 0
  ble-      .loc_0x284

.loc_0x44:
  subfic    r6, r29, 0x3
  lbz       r12, 0x0(r31)
  addi      r0, r29, 0x1
  lbz       r11, 0x1(r31)
  rlwinm    r10,r6,3,0,28
  lbz       r9, 0x2(r31)
  subfic    r8, r0, 0x3
  lbz       r7, 0x3(r31)
  addi      r6, r29, 0x2
  lbz       r0, 0x4(r31)
  slw       r12, r12, r10
  lbz       r23, 0x5(r31)
  rlwinm    r10,r8,3,0,28
  lbz       r25, 0x6(r31)
  subfic    r6, r6, 0x3
  lbz       r27, 0x7(r31)
  rlwinm    r8,r6,3,0,28
  neg       r6, r29
  addi      r22, r29, 0x4
  rlwinm    r6,r6,3,0,28
  subfic    r22, r22, 0x3
  addi      r24, r29, 0x5
  rlwinm    r22,r22,3,0,28
  subfic    r24, r24, 0x3
  addi      r26, r29, 0x6
  rlwinm    r24,r24,3,0,28
  subfic    r26, r26, 0x3
  addi      r28, r29, 0x7
  rlwinm    r26,r26,3,0,28
  subfic    r28, r28, 0x3
  rlwinm    r28,r28,3,0,28
  or        r30, r30, r12
  slw       r10, r11, r10
  or        r30, r30, r10
  slw       r8, r9, r8
  or        r30, r30, r8
  slw       r6, r7, r6
  or        r30, r30, r6
  slw       r0, r0, r22
  or        r30, r30, r0
  slw       r0, r23, r24
  or        r30, r30, r0
  slw       r0, r25, r26
  or        r30, r30, r0
  slw       r0, r27, r28
  or        r30, r30, r0
  addi      r31, r31, 0x8
  addi      r29, r29, 0x8
  bdnz+     .loc_0x44
  b         .loc_0x284

.loc_0x10C:
  sub       r0, r4, r29
  cmpw      r29, r4
  mtctr     r0
  bge-      .loc_0x13C

.loc_0x11C:
  subfic    r0, r29, 0x3
  lbz       r6, 0x0(r7)
  rlwinm    r0,r0,3,0,28
  slw       r0, r6, r0
  or        r30, r30, r0
  addi      r7, r7, 0x1
  addi      r29, r29, 0x1
  bdnz+     .loc_0x11C

.loc_0x13C:
  lis       r6, 0xCC00
  stw       r30, 0x6838(r6)

.loc_0x144:
  subi      r0, r4, 0x1
  lis       r6, 0xCC00
  rlwinm    r7,r5,2,0,29
  addi      r8, r6, 0x6800
  ori       r6, r7, 0x1
  rlwinm    r0,r0,4,0,27
  or        r0, r6, r0
  stwu      r0, 0x34(r8)

.loc_0x164:
  lwz       r0, 0x0(r8)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x164
  cmplwi    r5, 0
  bne-      .loc_0x27C
  li        r5, 0
  lis       r6, 0xCC00
  cmpw      r5, r4
  lwz       r0, 0x6838(r6)
  bge-      .loc_0x27C
  cmpwi     r4, 0x8
  subi      r7, r4, 0x8
  ble-      .loc_0x250
  addi      r6, r7, 0x7
  rlwinm    r6,r6,29,3,31
  cmpwi     r7, 0
  mtctr     r6
  ble-      .loc_0x250

.loc_0x1AC:
  subfic    r6, r5, 0x3
  rlwinm    r7,r6,3,0,28
  addi      r6, r5, 0x1
  srw       r8, r0, r7
  subfic    r6, r6, 0x3
  stb       r8, 0x0(r3)
  rlwinm    r7,r6,3,0,28
  addi      r6, r5, 0x2
  srw       r12, r0, r7
  subfic    r6, r6, 0x3
  stb       r12, 0x1(r3)
  rlwinm    r6,r6,3,0,28
  srw       r11, r0, r6
  neg       r6, r5
  stb       r11, 0x2(r3)
  rlwinm    r7,r6,3,0,28
  addi      r6, r5, 0x4
  srw       r10, r0, r7
  subfic    r6, r6, 0x3
  stb       r10, 0x3(r3)
  rlwinm    r7,r6,3,0,28
  addi      r6, r5, 0x5
  srw       r9, r0, r7
  subfic    r6, r6, 0x3
  stb       r9, 0x4(r3)
  rlwinm    r7,r6,3,0,28
  srw       r8, r0, r7
  addi      r6, r5, 0x6
  stb       r8, 0x5(r3)
  subfic    r7, r6, 0x3
  addi      r6, r5, 0x7
  rlwinm    r7,r7,3,0,28
  srw       r7, r0, r7
  subfic    r6, r6, 0x3
  stb       r7, 0x6(r3)
  rlwinm    r6,r6,3,0,28
  srw       r6, r0, r6
  stb       r6, 0x7(r3)
  addi      r3, r3, 0x8
  addi      r5, r5, 0x8
  bdnz+     .loc_0x1AC

.loc_0x250:
  sub       r6, r4, r5
  cmpw      r5, r4
  mtctr     r6
  bge-      .loc_0x27C

.loc_0x260:
  subfic    r4, r5, 0x3
  rlwinm    r4,r4,3,0,28
  srw       r4, r0, r4
  stb       r4, 0x0(r3)
  addi      r3, r3, 0x1
  addi      r5, r5, 0x1
  bdnz+     .loc_0x260

.loc_0x27C:
  li        r3, 0x1
  b         .loc_0x28C

.loc_0x284:
  add       r7, r3, r29
  b         .loc_0x10C

.loc_0x28C:
  lmw       r22, 0x20(r1)
  addi      r1, r1, 0x48
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
/*
void DBGEXIClearInterrupts(void)
{
	// UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
/*void DBGCheckID(void)
{
	// UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
/*
void DBGWriteMailbox(void)
{
	// UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	80221770
 * Size:	0000AC
 */
void DBGReadMailbox(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x2
  stw       r0, 0x4(r1)
  lis       r0, 0x6000
  stwu      r1, -0x38(r1)
  stmw      r27, 0x24(r1)
  lis       r30, 0xCC00
  addi      r27, r3, 0
  addi      r29, r30, 0x6800
  addi      r3, r1, 0x18
  lwz       r5, 0x6828(r30)
  andi.     r5, r5, 0x405
  ori       r5, r5, 0xC0
  stwu      r5, 0x28(r29)
  li        r5, 0x1
  stw       r0, 0x18(r1)
  bl        -0x2D8
  cntlzw    r0, r3
  rlwinm    r31,r0,27,5,31

.loc_0x4C:
  addi      r28, r30, 0x6800
  lwzu      r0, 0x34(r28)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x4C
  addi      r3, r27, 0
  li        r4, 0x4
  li        r5, 0
  bl        -0x300
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r3, r31, r0

.loc_0x78:
  lwz       r0, 0x0(r28)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x78
  lwz       r4, 0x0(r29)
  cntlzw    r0, r3
  rlwinm    r3,r0,27,5,31
  andi.     r0, r4, 0x405
  stw       r0, 0x0(r29)
  lmw       r27, 0x24(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8022181C
 * Size:	0000DC
 */
void DBGRead(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm    r0,r3,8,7,21
  oris      r0, r0, 0x2000
  stwu      r1, -0x40(r1)
  stmw      r26, 0x28(r1)
  lis       r29, 0xCC00
  addi      r30, r5, 0
  addi      r26, r4, 0
  addi      r31, r29, 0x6800
  addi      r3, r1, 0x24
  li        r4, 0x4
  li        r5, 0x1
  lwz       r6, 0x6828(r29)
  andi.     r6, r6, 0x405
  ori       r6, r6, 0xC0
  stwu      r6, 0x28(r31)
  stw       r0, 0x24(r1)
  bl        -0x38C
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  mr        r27, r0

.loc_0x58:
  addi      r28, r29, 0x6800
  lwzu      r0, 0x34(r28)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x58
  b         .loc_0xAC

.loc_0x6C:
  addi      r3, r1, 0x20
  li        r4, 0x4
  li        r5, 0
  bl        -0x3BC
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r27, r27, r0

.loc_0x88:
  lwz       r0, 0x0(r28)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x88
  lwz       r0, 0x20(r1)
  subic.    r30, r30, 0x4
  stw       r0, 0x0(r26)
  addi      r26, r26, 0x4
  bge-      .loc_0xAC
  li        r30, 0

.loc_0xAC:
  cmpwi     r30, 0
  bne+      .loc_0x6C
  lwz       r4, 0x0(r31)
  cntlzw    r0, r27
  rlwinm    r3,r0,27,5,31
  andi.     r0, r4, 0x405
  stw       r0, 0x0(r31)
  lmw       r26, 0x28(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	802218F8
 * Size:	0000DC
 */
void DBGWrite(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm    r0,r3,8,7,21
  oris      r0, r0, 0xA000
  stwu      r1, -0x40(r1)
  stmw      r26, 0x28(r1)
  lis       r29, 0xCC00
  addi      r30, r5, 0
  addi      r26, r4, 0
  addi      r31, r29, 0x6800
  addi      r3, r1, 0x24
  li        r4, 0x4
  li        r5, 0x1
  lwz       r6, 0x6828(r29)
  andi.     r6, r6, 0x405
  ori       r6, r6, 0xC0
  stwu      r6, 0x28(r31)
  stw       r0, 0x24(r1)
  bl        -0x468
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  mr        r27, r0

.loc_0x58:
  addi      r28, r29, 0x6800
  lwzu      r0, 0x34(r28)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x58
  b         .loc_0xAC

.loc_0x6C:
  lwz       r0, 0x0(r26)
  addi      r3, r1, 0x20
  li        r4, 0x4
  stw       r0, 0x20(r1)
  li        r5, 0x1
  addi      r26, r26, 0x4
  bl        -0x4A4
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r27, r27, r0

.loc_0x94:
  lwz       r0, 0x0(r28)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x94
  subic.    r30, r30, 0x4
  bge-      .loc_0xAC
  li        r30, 0

.loc_0xAC:
  cmpwi     r30, 0
  bne+      .loc_0x6C
  lwz       r4, 0x0(r31)
  cntlzw    r0, r27
  rlwinm    r3,r0,27,5,31
  andi.     r0, r4, 0x405
  stw       r0, 0x0(r31)
  lmw       r26, 0x28(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	802219D4
 * Size:	0000AC
 */
void DBGReadStatus(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x2
  stw       r0, 0x4(r1)
  lis       r0, 0x4000
  stwu      r1, -0x38(r1)
  stmw      r27, 0x24(r1)
  lis       r30, 0xCC00
  addi      r27, r3, 0
  addi      r29, r30, 0x6800
  addi      r3, r1, 0x18
  lwz       r5, 0x6828(r30)
  andi.     r5, r5, 0x405
  ori       r5, r5, 0xC0
  stwu      r5, 0x28(r29)
  li        r5, 0x1
  stw       r0, 0x18(r1)
  bl        -0x53C
  cntlzw    r0, r3
  rlwinm    r31,r0,27,5,31

.loc_0x4C:
  addi      r28, r30, 0x6800
  lwzu      r0, 0x34(r28)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x4C
  addi      r3, r27, 0
  li        r4, 0x4
  li        r5, 0
  bl        -0x564
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r3, r31, r0

.loc_0x78:
  lwz       r0, 0x0(r28)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x78
  lwz       r4, 0x0(r29)
  cntlzw    r0, r3
  rlwinm    r3,r0,27,5,31
  andi.     r0, r4, 0x405
  stw       r0, 0x0(r29)
  lmw       r27, 0x24(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80221A80
 * Size:	00003C
 */
void MWCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x8(r1)
  lwz       r12, 0x34B0(r13)
  stb       r0, 0x34C4(r13)
  cmplwi    r12, 0
  beq-      .loc_0x2C
  mtlr      r12
  li        r3, 0
  blrl      

.loc_0x2C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80221ABC
 * Size:	000040
 */
void DBGHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0xCC00
  stw       r0, 0x4(r1)
  li        r0, 0x1000
  stwu      r1, -0x8(r1)
  lwz       r12, 0x34B4(r13)
  stw       r0, 0x3000(r5)
  cmplwi    r12, 0
  beq-      .loc_0x30
  mtlr      r12
  extsh     r3, r3
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
 * Address:	80221AFC
 * Size:	000078
 */
void DBInitComm(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  addi      r30, r4, 0
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  bl        -0x28BA0
  addi      r0, r13, 0x34C4
  stw       r0, 0x34C0(r13)
  lis       r4, 0x2
  addi      r31, r3, 0
  lwz       r0, 0x34C0(r13)
  subi      r3, r4, 0x8000
  stw       r0, 0x0(r29)
  stw       r30, 0x34B0(r13)
  bl        -0x28824
  lis       r3, 0xCC00
  li        r0, 0
  stw       r0, 0x6828(r3)
  mr        r3, r31
  bl        -0x28BB0
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
 * Address:	80221B74
 * Size:	000054
 */
void DBInitInterrupts(void)	// matches
{
	(void)__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_2);
	(void)__OSMaskInterrupts(OS_INTERRUPTMASK_PI_DEBUG);

	DBGCallback = MWCallback;

	(void)__OSSetInterruptHandler(__OS_INTERRUPT_PI_DEBUG, DBGHandler);

	(void)__OSUnmaskInterrupts(OS_INTERRUPTMASK_PI_DEBUG);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000150
 */
/*
void CheckMailBox(void)
{
	// UNUSED FUNCTION
}
*/
/*
 * --INFO--
 * Address:	80221BC8
 * Size:	00009C
 */
void DBQueryData(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  lwz       r0, 0x34BC(r13)
  stb       r3, 0x34C4(r13)
  cmpwi     r0, 0
  bne-      .loc_0x7C
  bl        -0x28C70
  addi      r31, r3, 0
  addi      r3, r1, 0x8
  bl        -0x224
  lwz       r0, 0x8(r1)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x7C
  addi      r3, r1, 0x8
  bl        -0x49C
  lwz       r0, 0x8(r1)
  rlwinm    r0,r0,0,3,31
  stw       r0, 0x8(r1)
  lwz       r4, 0x8(r1)
  rlwinm    r3,r4,0,3,7
  subis     r0, r3, 0x1F00
  cmplwi    r0, 0
  bne-      .loc_0x7C
  rlwinm    r3,r4,0,17,31
  stw       r4, 0x34B8(r13)
  li        r0, 0x1
  stw       r3, 0x34BC(r13)
  stb       r0, 0x34C4(r13)

.loc_0x7C:
  mr        r3, r31
  bl        -0x28CA4
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  lwz       r3, 0x34BC(r13)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80221C64
 * Size:	00008C
 */
void DBRead(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  addi      r30, r4, 0
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  bl        -0x28D08
  lwz       r0, 0x34B8(r13)
  addi      r31, r3, 0
  rlwinm.   r0,r0,0,15,15
  beq-      .loc_0x3C
  li        r3, 0x1000
  b         .loc_0x40

.loc_0x3C:
  li        r3, 0

.loc_0x40:
  addis     r3, r3, 0x2
  addi      r0, r30, 0x3
  addi      r4, r29, 0
  rlwinm    r5,r0,0,0,29
  subi      r3, r3, 0x2000
  bl        -0x49C
  li        r0, 0
  stw       r0, 0x34BC(r13)
  mr        r3, r31
  stb       r0, 0x34C4(r13)
  bl        -0x28D28
  lwz       r0, 0x24(r1)
  li        r3, 0
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
 * Address:	80221CF0
 * Size:	000260
 */
void DBWrite(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stmw      r24, 0x58(r1)
  addi      r26, r3, 0
  addi      r27, r4, 0
  bl        -0x28D8C
  addi      r28, r3, 0
  lis       r25, 0xCC00
  lis       r31, 0x4000

.loc_0x28:
  lwz       r0, 0x6828(r25)
  addi      r30, r25, 0x6800
  addi      r3, r1, 0x50
  andi.     r0, r0, 0x405
  li        r4, 0x2
  li        r5, 0x1
  ori       r0, r0, 0xC0
  stwu      r0, 0x28(r30)
  stw       r31, 0x50(r1)
  bl        -0x864
  cntlzw    r0, r3
  rlwinm    r24,r0,27,5,31

.loc_0x58:
  addi      r29, r25, 0x6800
  lwzu      r0, 0x34(r29)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x58
  addi      r3, r1, 0x54
  li        r4, 0x4
  li        r5, 0
  bl        -0x88C

.loc_0x78:
  lwz       r0, 0x0(r29)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x78
  lwz       r0, 0x0(r30)
  andi.     r0, r0, 0x405
  stw       r0, 0x0(r30)
  lwz       r0, 0x54(r1)
  rlwinm.   r0,r0,0,30,30
  bne+      .loc_0x28
  lbz       r3, 0x2AF8(r13)
  addi      r0, r3, 0x1
  stb       r0, 0x2AF8(r13)
  lbz       r0, 0x2AF8(r13)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0xBC
  li        r3, 0x1000
  b         .loc_0xC0

.loc_0xBC:
  li        r3, 0

.loc_0xC0:
  addi      r0, r27, 0x3
  oris      r25, r3, 0x1
  rlwinm    r24,r0,0,0,29
  ori       r25, r25, 0xC000

.loc_0xD0:
  addi      r3, r25, 0
  addi      r4, r26, 0
  addi      r5, r24, 0
  bl        -0x4D4
  cmpwi     r3, 0
  beq+      .loc_0xD0
  lis       r31, 0x4000

.loc_0xEC:
  lwz       r0, 0x0(r30)
  addi      r3, r1, 0x4C
  li        r4, 0x2
  andi.     r0, r0, 0x405
  li        r5, 0x1
  ori       r0, r0, 0xC0
  stw       r0, 0x0(r30)
  stw       r31, 0x4C(r1)
  bl        -0x924
  cntlzw    r0, r3
  rlwinm    r26,r0,27,5,31

.loc_0x118:
  lwz       r0, 0x0(r29)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x118
  addi      r3, r1, 0x54
  li        r4, 0x4
  li        r5, 0
  bl        -0x948

.loc_0x134:
  lwz       r0, 0x0(r29)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x134
  lwz       r0, 0x0(r30)
  andi.     r0, r0, 0x405
  stw       r0, 0x0(r30)
  lwz       r0, 0x54(r1)
  rlwinm.   r0,r0,0,30,30
  bne+      .loc_0xEC
  lbz       r0, 0x2AF8(r13)
  rlwinm    r0,r0,16,0,15
  oris      r0, r0, 0x1F00
  or        r0, r0, r27
  rlwinm    r0,r0,0,3,31
  oris      r24, r0, 0xC000

.loc_0x170:
  lwz       r0, 0x0(r30)
  addi      r3, r1, 0x44
  li        r4, 0x4
  andi.     r0, r0, 0x405
  li        r5, 0x1
  ori       r0, r0, 0xC0
  stw       r0, 0x0(r30)
  stw       r24, 0x44(r1)
  bl        -0x9A8
  cntlzw    r0, r3
  rlwinm    r3,r0,27,5,31

.loc_0x19C:
  lwz       r0, 0x0(r29)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x19C
  lwz       r0, 0x0(r30)
  andi.     r0, r0, 0x405
  cmpwi     r3, 0
  stw       r0, 0x0(r30)
  bne+      .loc_0x170
  lis       r27, 0x4000

.loc_0x1C0:
  lwz       r0, 0x0(r30)
  addi      r3, r1, 0x3C
  li        r4, 0x2
  andi.     r0, r0, 0x405
  li        r5, 0x1
  ori       r0, r0, 0xC0
  stw       r0, 0x0(r30)
  stw       r27, 0x3C(r1)
  bl        -0x9F8
  cntlzw    r0, r3
  rlwinm    r26,r0,27,5,31

.loc_0x1EC:
  lwz       r0, 0x0(r29)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x1EC
  addi      r3, r1, 0x54
  li        r4, 0x4
  li        r5, 0
  bl        -0xA1C
  cntlzw    r0, r3
  rlwinm    r0,r0,27,5,31
  or        r3, r26, r0

.loc_0x214:
  lwz       r0, 0x0(r29)
  rlwinm.   r0,r0,0,31,31
  bne+      .loc_0x214
  lwz       r0, 0x0(r30)
  andi.     r0, r0, 0x405
  cmpwi     r3, 0
  stw       r0, 0x0(r30)
  bne+      .loc_0x1C0
  lwz       r0, 0x54(r1)
  rlwinm.   r0,r0,0,30,30
  bne+      .loc_0x1C0
  mr        r3, r28
  bl        -0x28F90
  lmw       r24, 0x58(r1)
  li        r3, 0
  lwz       r0, 0x7C(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80221F50
 * Size:	000004
 */
void DBOpen(void)
{
	return;
}

/*
 * --INFO--
 * Address:	80221F54
 * Size:	000004
 */
void DBClose(void)
{
	return;
}
