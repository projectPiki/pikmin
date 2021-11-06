#include "types.h"



/*
 * --INFO--
 * Address:	8020690C
 * Size:	000044
 */
void ARRegisterDMACallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r31, 0x33C8(r13)
  bl        -0xD9AC
  stw       r30, 0x33C8(r13)
  bl        -0xD98C
  lwz       r0, 0x1C(r1)
  mr        r3, r31
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
 * Size:	00003C
 */
void ARGetDMAStatus(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80206950
 * Size:	0000F0
 */
void ARStartDMA(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r6, 0
  stw       r30, 0x20(r1)
  addi      r30, r5, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  stw       r28, 0x18(r1)
  addi      r28, r4, 0
  bl        -0xDA00
  lis       r6, 0xCC00
  lhz       r0, 0x5020(r6)
  addi      r8, r6, 0x5000
  addi      r9, r6, 0x5000
  rlwinm    r4,r0,0,0,21
  rlwinm    r0,r28,16,16,31
  or        r0, r4, r0
  sth       r0, 0x5020(r6)
  rlwinm    r0,r28,0,16,31
  addi      r4, r6, 0x5000
  lhz       r5, 0x5022(r6)
  rlwinm    r5,r5,0,27,15
  or        r0, r5, r0
  sth       r0, 0x5022(r6)
  addi      r5, r6, 0x5000
  rlwinm    r0,r30,16,16,31
  lhz       r6, 0x5024(r6)
  rlwinm    r6,r6,0,0,21
  or        r0, r6, r0
  sth       r0, 0x24(r8)
  rlwinm    r0,r30,0,16,31
  lhz       r6, 0x26(r9)
  rlwinm    r6,r6,0,27,15
  or        r0, r6, r0
  sth       r0, 0x26(r9)
  rlwinm    r6,r31,16,16,31
  rlwinm    r0,r31,0,16,31
  lhz       r7, 0x28(r4)
  rlwinm    r7,r7,0,17,15
  rlwimi    r7,r29,15,0,16
  sth       r7, 0x28(r4)
  lhz       r7, 0x28(r4)
  rlwinm    r7,r7,0,0,21
  or        r6, r7, r6
  sth       r6, 0x28(r4)
  lhz       r4, 0x2A(r5)
  rlwinm    r4,r4,0,27,15
  or        r0, r4, r0
  sth       r0, 0x2A(r5)
  bl        -0xDA78
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
 * Size:	000068
 */
void ARAlloc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void ARFree(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void ARCheckInit(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80206A40
 * Size:	0000F4
 */
void ARInit(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  addi      r30, r4, 0
  stw       r29, 0x24(r1)
  addi      r29, r3, 0
  lwz       r0, 0x33DC(r13)
  cmpwi     r0, 0x1
  bne-      .loc_0x34
  li        r3, 0x4000
  b         .loc_0xD8

.loc_0x34:
  bl        -0xDAF8
  li        r0, 0
  lis       r4, 0x8020
  stw       r0, 0x33C8(r13)
  addi      r31, r3, 0
  addi      r4, r4, 0x6B3C
  li        r3, 0x6
  bl        -0xDAC8
  lis       r3, 0x200
  bl        -0xD6F4
  lis       r3, 0x8000
  lfd       f2, -0x3CD8(r2)
  lwz       r0, 0xF8(r3)
  li        r4, 0x4000
  lis       r3, 0xCC00
  lfs       f0, -0x3CDC(r2)
  stw       r0, 0x1C(r1)
  lis       r0, 0x4330
  lfs       f3, -0x3CE0(r2)
  stw       r0, 0x18(r1)
  addi      r5, r3, 0x5000
  lfd       f1, 0x18(r1)
  stw       r4, 0x33D0(r13)
  fsubs     f1, f1, f2
  stw       r30, 0x33D4(r13)
  fdivs     f0, f1, f0
  stw       r29, 0x33D8(r13)
  lhz       r3, 0x501A(r3)
  fmuls     f0, f3, f0
  fctiwz    f0, f0
  stfd      f0, 0x10(r1)
  lwz       r0, 0x14(r1)
  rlwinm    r0,r0,0,24,31
  rlwimi    r0,r3,0,16,23
  sth       r0, 0x1A(r5)
  bl        0xB4
  li        r0, 0x1
  stw       r0, 0x33DC(r13)
  mr        r3, r31
  bl        -0xDB6C
  lwz       r3, 0x33D0(r13)

.loc_0xD8:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  mtlr      r0
  lwz       r29, 0x24(r1)
  addi      r1, r1, 0x30
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void ARReset(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void ARSetSize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80206B34
 * Size:	000008
 */
u32  ARGetBaseAddress(void)
{
	return 0x4000;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void ARGetSize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80206B3C
 * Size:	000078
 */
void __ARHandler(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0xCC00
  stw       r0, 0x4(r1)
  addi      r3, r3, 0x5000
  li        r0, -0x89
  stwu      r1, -0x2E0(r1)
  stw       r31, 0x2DC(r1)
  addi      r31, r4, 0
  lhz       r5, 0xA(r3)
  and       r0, r5, r0
  ori       r0, r0, 0x20
  sth       r0, 0xA(r3)
  addi      r3, r1, 0x10
  bl        -0xF734
  addi      r3, r1, 0x10
  bl        -0xF904
  lwz       r12, 0x33C8(r13)
  cmplwi    r12, 0
  beq-      .loc_0x54
  mtlr      r12
  blrl      

.loc_0x54:
  addi      r3, r1, 0x10
  bl        -0xF758
  mr        r3, r31
  bl        -0xF928
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
 * Size:	000018
 */
void __ARWaitForDMA(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void __ARWriteDMA(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void __ARReadDMA(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80206BB4
 * Size:	000ECC
 */
void __ARChecksize(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0xDEAE
  stw       r0, 0x4(r1)
  subi      r5, r3, 0x4111
  lis       r3, 0xBAD1
  stwu      r1, -0x140(r1)
  stmw      r14, 0xF8(r1)
  addi      r0, r1, 0xB3
  rlwinm    r23,r0,0,0,26
  addi      r0, r1, 0x73
  rlwinm    r31,r0,0,0,26
  subi      r0, r3, 0x4530
  addi      r4, r1, 0x33
  rlwinm    r24,r4,0,0,26
  addi      r3, r23, 0
  li        r17, 0
  li        r22, 0
  li        r4, 0x20
  stw       r5, 0x0(r23)
  stw       r0, 0x0(r31)
  stw       r5, 0x4(r23)
  stw       r0, 0x4(r31)
  stw       r5, 0x8(r23)
  stw       r0, 0x8(r31)
  stw       r5, 0xC(r23)
  stw       r0, 0xC(r31)
  stw       r5, 0x10(r23)
  stw       r0, 0x10(r31)
  stw       r5, 0x14(r23)
  stw       r0, 0x14(r31)
  stw       r5, 0x18(r23)
  stw       r0, 0x18(r31)
  stw       r5, 0x1C(r23)
  stw       r0, 0x1C(r31)
  bl        -0x10054
  addi      r3, r31, 0
  li        r4, 0x20
  bl        -0x10060
  lis       r3, 0xCC00
  addi      r3, r3, 0x5000

.loc_0xA0:
  lhz       r0, 0x16(r3)
  rlwinm.   r0,r0,0,31,31
  beq+      .loc_0xA0
  lis       r3, 0xCC00
  lhz       r0, 0x5012(r3)
  addi      r14, r3, 0x5000
  rlwinm    r20,r31,16,16,31
  rlwinm    r0,r0,0,0,25
  ori       r0, r0, 0x24
  sthu      r0, 0x12(r14)
  addi      r25, r3, 0x5000
  rlwinm    r21,r31,0,16,31
  lhz       r0, 0x5020(r3)
  addi      r26, r3, 0x5000
  addi      r27, r3, 0x5000
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r20
  sthu      r0, 0x20(r25)
  addi      r28, r3, 0x5000
  addi      r30, r3, 0x5000
  lhz       r0, 0x5022(r3)
  addi      r29, r3, 0x5000
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r21
  sthu      r0, 0x22(r26)
  lhz       r0, 0x5024(r3)
  rlwinm    r0,r0,0,0,21
  nop       
  sthu      r0, 0x24(r27)
  lhz       r0, 0x5026(r3)
  rlwinm    r0,r0,0,27,15
  nop       
  sthu      r0, 0x26(r28)
  lhz       r0, 0x5028(r3)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x5028(r3)
  lhz       r0, 0x5028(r3)
  rlwinm    r0,r0,0,0,21
  nop       
  sthu      r0, 0x28(r30)
  lhz       r0, 0x502A(r3)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sthu      r0, 0x2A(r29)

.loc_0x150:
  addi      r31, r3, 0x5000
  lhzu      r0, 0xA(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x150
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r20
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r21
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  ori       r0, r0, 0x20
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  nop       
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x1CC:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x1CC
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r20
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r21
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x200
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x244:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x244
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r20
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r21
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  ori       r0, r0, 0x100
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  nop       
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x2BC:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x2BC
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r20
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r21
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  ori       r0, r0, 0x40
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  nop       
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x334:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x334
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x203BE0
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10324
  rlwinm    r0,r23,16,16,31
  lhz       r3, 0x0(r25)
  stw       r0, 0xE4(r1)
  rlwinm    r3,r3,0,0,21
  lwz       r0, 0xE4(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r25)
  rlwinm    r0,r23,0,16,31
  stw       r0, 0xE8(r1)
  lhz       r0, 0x0(r26)
  rlwinm    r3,r0,0,27,15
  lwz       r0, 0xE8(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  nop       
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x3E0:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x3E0
  lhz       r0, 0x0(r25)
  rlwinm    r19,r24,16,16,31
  rlwinm    r18,r24,0,16,31
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r19
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r18
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  nop       
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  ori       r0, r0, 0x8000
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x460:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x460
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10470
  lwz       r0, 0x0(r24)
  lwz       r3, 0x0(r23)
  cmplw     r0, r3
  bne-      .loc_0x780
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x203D28
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x1046C
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r19
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r18
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  ori       r0, r0, 0x20
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  nop       
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  ori       r0, r0, 0x8000
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x510:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x510
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10520
  lwz       r0, 0x0(r24)
  lwz       r3, 0x0(r23)
  cmplw     r0, r3
  bne-      .loc_0x544
  li        r17, 0
  lis       r22, 0x20
  b         .loc_0x780

.loc_0x544:
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x203DE4
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10528
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r19
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r18
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  ori       r0, r0, 0x100
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  nop       
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  ori       r0, r0, 0x8000
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x5CC:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x5CC
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x105DC
  lwz       r0, 0x0(r24)
  lwz       r3, 0x0(r23)
  cmplw     r0, r3
  bne-      .loc_0x600
  li        r17, 0x1
  lis       r22, 0x40
  b         .loc_0x780

.loc_0x600:
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x203EA0
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x105E4
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r19
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r18
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x200
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  ori       r0, r0, 0x8000
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x688:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x688
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10698
  lwz       r0, 0x0(r24)
  lwz       r3, 0x0(r23)
  cmplw     r0, r3
  bne-      .loc_0x6BC
  li        r17, 0x2
  lis       r22, 0x80
  b         .loc_0x780

.loc_0x6BC:
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x203F5C
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x106A0
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r19
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r18
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  ori       r0, r0, 0x40
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  nop       
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  ori       r0, r0, 0x8000
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x744:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x744
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10754
  lwz       r0, 0x0(r24)
  lwz       r3, 0x0(r23)
  cmplw     r0, r3
  bne-      .loc_0x778
  li        r17, 0x3
  lis       r22, 0x100
  b         .loc_0x780

.loc_0x778:
  li        r17, 0x4
  lis       r22, 0x200

.loc_0x780:
  lhz       r0, 0x0(r14)
  rlwinm    r15,r22,16,16,31
  rlwinm    r16,r22,0,16,31
  rlwinm    r0,r0,0,0,25
  ori       r0, r0, 0x20
  or        r0, r0, r17
  sth       r0, 0x0(r14)
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r20
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r21
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r15
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r16
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x808:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x808
  addis     r3, r22, 0x20
  lhz       r4, 0x0(r25)
  rlwinm    r0,r3,16,16,31
  stw       r0, 0xE0(r1)
  rlwinm    r0,r4,0,0,21
  or        r0, r0, r20
  sth       r0, 0x0(r25)
  rlwinm    r0,r3,0,16,31
  stw       r0, 0xEC(r1)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r21
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r3,r0,0,0,21
  lwz       r0, 0xE0(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r3,r0,0,27,15
  lwz       r0, 0xEC(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x89C:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x89C
  addis     r3, r22, 0x100
  lhz       r4, 0x0(r25)
  rlwinm    r0,r3,16,16,31
  stw       r0, 0xDC(r1)
  rlwinm    r0,r4,0,0,21
  or        r0, r0, r20
  sth       r0, 0x0(r25)
  rlwinm    r0,r3,0,16,31
  stw       r0, 0xF0(r1)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r21
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r3,r0,0,0,21
  lwz       r0, 0xDC(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r3,r0,0,27,15
  lwz       r0, 0xF0(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x930:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x930
  addi      r3, r22, 0x200
  lhz       r4, 0x0(r25)
  rlwinm    r0,r3,16,16,31
  stw       r0, 0xD8(r1)
  rlwinm    r0,r4,0,0,21
  or        r0, r0, r20
  sth       r0, 0x0(r25)
  rlwinm    r0,r3,0,16,31
  stw       r0, 0xF4(r1)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r21
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r3,r0,0,0,21
  lwz       r0, 0xD8(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r3,r0,0,27,15
  lwz       r0, 0xF4(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0x9C4:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0x9C4
  addis     r3, r22, 0x40
  lhz       r4, 0x0(r25)
  rlwinm    r0,r3,16,16,31
  stw       r0, 0xD4(r1)
  rlwinm    r0,r4,0,0,21
  or        r0, r0, r20
  sth       r0, 0x0(r25)
  rlwinm    r20,r3,0,16,31
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r21
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r3,r0,0,0,21
  lwz       r0, 0xD4(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r20
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0xA50:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0xA50
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x2042FC
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10A40
  lhz       r0, 0x0(r25)
  rlwinm    r3,r0,0,0,21
  lwz       r0, 0xE4(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r3,r0,0,27,15
  lwz       r0, 0xE8(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r15
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r16
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,17,15
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0xAEC:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0xAEC
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r19
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r18
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r15
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r16
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  ori       r0, r0, 0x8000
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0xB64:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0xB64
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10B74
  lwz       r0, 0x0(r24)
  lwz       r3, 0x0(r23)
  cmplw     r0, r3
  bne-      .loc_0xEAC
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x20442C
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10B70
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r19
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r18
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r3,r0,0,0,21
  lwz       r0, 0xE0(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r3,r0,0,27,15
  lwz       r0, 0xEC(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  ori       r0, r0, 0x8000
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0xC1C:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0xC1C
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10C2C
  lwz       r0, 0x0(r24)
  lwz       r3, 0x0(r23)
  cmplw     r0, r3
  bne-      .loc_0xC4C
  addis     r22, r22, 0x20
  b         .loc_0xE9C

.loc_0xC4C:
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x2044EC
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10C30
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r19
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r18
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r3,r0,0,0,21
  lwz       r0, 0xDC(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r3,r0,0,27,15
  lwz       r0, 0xF0(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  ori       r0, r0, 0x8000
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0xCDC:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0xCDC
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10CEC
  lwz       r0, 0x0(r24)
  lwz       r3, 0x0(r23)
  cmplw     r0, r3
  bne-      .loc_0xD10
  ori       r17, r17, 0x8
  addis     r22, r22, 0x40
  b         .loc_0xE9C

.loc_0xD10:
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x2045B0
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10CF4
  lhz       r0, 0x0(r25)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r19
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r18
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r3,r0,0,0,21
  lwz       r0, 0xD8(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r3,r0,0,27,15
  lwz       r0, 0xF4(r1)
  or        r0, r3, r0
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  ori       r0, r0, 0x8000
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0xDA0:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0xDA0
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10DB0
  lwz       r0, 0x0(r24)
  lwz       r3, 0x0(r23)
  cmplw     r0, r3
  bne-      .loc_0xDD4
  ori       r17, r17, 0x10
  addis     r22, r22, 0x80
  b         .loc_0xE9C

.loc_0xDD4:
  addi      r3, r24, 0
  li        r4, 0
  li        r5, 0x20
  bl        -0x204674
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10DB8
  lhz       r0, 0x0(r25)
  lwz       r3, 0xD4(r1)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r19
  sth       r0, 0x0(r25)
  lhz       r0, 0x0(r26)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r18
  sth       r0, 0x0(r26)
  lhz       r0, 0x0(r27)
  rlwinm    r0,r0,0,0,21
  or        r0, r0, r3
  sth       r0, 0x0(r27)
  lhz       r0, 0x0(r28)
  rlwinm    r0,r0,0,27,15
  or        r0, r0, r20
  sth       r0, 0x0(r28)
  lhz       r0, 0x0(r30)
  ori       r0, r0, 0x8000
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r30)
  rlwinm    r0,r0,0,0,21
  nop       
  sth       r0, 0x0(r30)
  lhz       r0, 0x0(r29)
  rlwinm    r0,r0,0,27,15
  ori       r0, r0, 0x20
  sth       r0, 0x0(r29)

.loc_0xE60:
  lhz       r0, 0x0(r31)
  rlwinm.   r0,r0,0,22,22
  bne+      .loc_0xE60
  addi      r3, r24, 0
  li        r4, 0x20
  bl        -0x10E70
  lwz       r3, 0x0(r24)
  lwz       r0, 0x0(r23)
  cmplw     r3, r0
  bne-      .loc_0xE94
  ori       r17, r17, 0x18
  addis     r22, r22, 0x100
  b         .loc_0xE9C

.loc_0xE94:
  ori       r17, r17, 0x20
  addis     r22, r22, 0x200

.loc_0xE9C:
  lhz       r0, 0x0(r14)
  rlwinm    r0,r0,0,0,25
  or        r0, r0, r17
  sth       r0, 0x0(r14)

.loc_0xEAC:
  lis       r3, 0xC000
  stw       r22, 0xD0(r3)
  stw       r22, 0x33CC(r13)
  lwz       r0, 0x144(r1)
  lmw       r14, 0xF8(r1)
  addi      r1, r1, 0x140
  mtlr      r0
  blr
*/
}
