#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void __ARQPopTaskQueueHi(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80207A80
 * Size:	000100
 */
void __ARQServiceQueueLo(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x33F4(r13)
  cmplwi    r0, 0
  bne-      .loc_0x30
  lwz       r3, 0x33E8(r13)
  cmplwi    r3, 0
  beq-      .loc_0x30
  stw       r3, 0x33F4(r13)
  lwz       r0, 0x0(r3)
  stw       r0, 0x33E8(r13)

.loc_0x30:
  lwz       r5, 0x33F4(r13)
  cmplwi    r5, 0
  beq-      .loc_0xF0
  lwz       r6, 0x18(r5)
  lwz       r0, 0x3400(r13)
  cmplw     r6, r0
  bgt-      .loc_0x84
  lwz       r3, 0x8(r5)
  cmplwi    r3, 0
  bne-      .loc_0x68
  lwz       r4, 0x10(r5)
  lwz       r5, 0x14(r5)
  bl        -0x1190
  b         .loc_0x74

.loc_0x68:
  lwz       r4, 0x14(r5)
  lwz       r5, 0x10(r5)
  bl        -0x11A0

.loc_0x74:
  lwz       r3, 0x33F4(r13)
  lwz       r0, 0x1C(r3)
  stw       r0, 0x33FC(r13)
  b         .loc_0xB4

.loc_0x84:
  lwz       r3, 0x8(r5)
  cmplwi    r3, 0
  bne-      .loc_0xA4
  lwz       r4, 0x10(r5)
  mr        r6, r0
  lwz       r5, 0x14(r5)
  bl        -0x11CC
  b         .loc_0xB4

.loc_0xA4:
  lwz       r4, 0x14(r5)
  mr        r6, r0
  lwz       r5, 0x10(r5)
  bl        -0x11E0

.loc_0xB4:
  lwz       r3, 0x33F4(r13)
  lwz       r4, 0x3400(r13)
  lwz       r0, 0x18(r3)
  sub       r0, r0, r4
  stw       r0, 0x18(r3)
  lwz       r4, 0x33F4(r13)
  lwz       r0, 0x3400(r13)
  lwz       r3, 0x10(r4)
  add       r0, r3, r0
  stw       r0, 0x10(r4)
  lwz       r4, 0x33F4(r13)
  lwz       r0, 0x3400(r13)
  lwz       r3, 0x14(r4)
  add       r0, r3, r0
  stw       r0, 0x14(r4)

.loc_0xF0:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80207B80
 * Size:	000004
 */
void __ARQCallbackHack(void)
{
}

/*
 * --INFO--
 * Address:	80207B84
 * Size:	0000CC
 */
void __ARQInterruptServiceRoutine(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x33F8(r13)
  cmplwi    r12, 0
  beq-      .loc_0x34
  lwz       r3, 0x33F0(r13)
  mtlr      r12
  blrl      
  li        r0, 0
  stw       r0, 0x33F0(r13)
  stw       r0, 0x33F8(r13)
  b         .loc_0x58

.loc_0x34:
  lwz       r12, 0x33FC(r13)
  cmplwi    r12, 0
  beq-      .loc_0x58
  lwz       r3, 0x33F4(r13)
  mtlr      r12
  blrl      
  li        r0, 0
  stw       r0, 0x33F4(r13)
  stw       r0, 0x33FC(r13)

.loc_0x58:
  lwz       r6, 0x33E0(r13)
  cmplwi    r6, 0
  beq-      .loc_0xAC
  lwz       r3, 0x8(r6)
  cmplwi    r3, 0
  bne-      .loc_0x84
  lwz       r4, 0x10(r6)
  lwz       r5, 0x14(r6)
  lwz       r6, 0x18(r6)
  bl        -0x12B0
  b         .loc_0x94

.loc_0x84:
  lwz       r4, 0x14(r6)
  lwz       r5, 0x10(r6)
  lwz       r6, 0x18(r6)
  bl        -0x12C4

.loc_0x94:
  lwz       r3, 0x33E0(r13)
  lwz       r0, 0x1C(r3)
  stw       r0, 0x33F8(r13)
  stw       r3, 0x33F0(r13)
  lwz       r0, 0x0(r3)
  stw       r0, 0x33E0(r13)

.loc_0xAC:
  lwz       r0, 0x33F0(r13)
  cmplwi    r0, 0
  bne-      .loc_0xBC
  bl        -0x1BC

.loc_0xBC:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void __ARQInitTempQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void __ARQPushTempQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80207C50
 * Size:	000068
 */
void ARQInit(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  lwz       r0, 0x3404(r13)
  cmpwi     r0, 0x1
  beq-      .loc_0x54
  li        r31, 0
  li        r0, 0x1000
  stw       r31, 0x33E8(r13)
  lis       r3, 0x8020
  stw       r31, 0x33E0(r13)
  addi      r3, r3, 0x7B84
  stw       r0, 0x3400(r13)
  bl        -0x137C
  li        r0, 0x1
  stw       r31, 0x33F0(r13)
  stw       r31, 0x33F4(r13)
  stw       r31, 0x33F8(r13)
  stw       r31, 0x33FC(r13)
  stw       r0, 0x3404(r13)

.loc_0x54:
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void ARQReset(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80207CB8
 * Size:	00015C
 */
void ARQPostRequest(void)
{
/*
.loc_0x0:
  mflr      r0
  cmplwi    r10, 0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  addi      r30, r6, 0
  stw       r29, 0x2C(r1)
  addi      r29, r3, 0
  stw       r0, 0x0(r3)
  stw       r4, 0x4(r3)
  stw       r5, 0x8(r3)
  stw       r7, 0x10(r3)
  stw       r8, 0x14(r3)
  stw       r9, 0x18(r3)
  beq-      .loc_0x4C
  stw       r10, 0x1C(r29)
  b         .loc_0x58

.loc_0x4C:
  lis       r3, 0x8020
  addi      r0, r3, 0x7B80
  stw       r0, 0x1C(r29)

.loc_0x58:
  bl        -0xED94
  cmpwi     r30, 0x1
  addi      r31, r3, 0
  beq-      .loc_0x9C
  bge-      .loc_0xBC
  cmpwi     r30, 0
  bge-      .loc_0x78
  b         .loc_0xBC

.loc_0x78:
  lwz       r0, 0x33E8(r13)
  cmplwi    r0, 0
  beq-      .loc_0x90
  lwz       r3, 0x33EC(r13)
  stw       r29, 0x0(r3)
  b         .loc_0x94

.loc_0x90:
  stw       r29, 0x33E8(r13)

.loc_0x94:
  stw       r29, 0x33EC(r13)
  b         .loc_0xBC

.loc_0x9C:
  lwz       r0, 0x33E0(r13)
  cmplwi    r0, 0
  beq-      .loc_0xB4
  lwz       r3, 0x33E4(r13)
  stw       r29, 0x0(r3)
  b         .loc_0xB8

.loc_0xB4:
  stw       r29, 0x33E0(r13)

.loc_0xB8:
  stw       r29, 0x33E4(r13)

.loc_0xBC:
  lwz       r0, 0x33F0(r13)
  cmplwi    r0, 0
  bne-      .loc_0x138
  lwz       r0, 0x33F4(r13)
  cmplwi    r0, 0
  bne-      .loc_0x138
  lwz       r6, 0x33E0(r13)
  cmplwi    r6, 0
  beq-      .loc_0x128
  lwz       r3, 0x8(r6)
  cmplwi    r3, 0
  bne-      .loc_0x100
  lwz       r4, 0x10(r6)
  lwz       r5, 0x14(r6)
  lwz       r6, 0x18(r6)
  bl        -0x1460
  b         .loc_0x110

.loc_0x100:
  lwz       r4, 0x14(r6)
  lwz       r5, 0x10(r6)
  lwz       r6, 0x18(r6)
  bl        -0x1474

.loc_0x110:
  lwz       r3, 0x33E0(r13)
  lwz       r0, 0x1C(r3)
  stw       r0, 0x33F8(r13)
  stw       r3, 0x33F0(r13)
  lwz       r0, 0x0(r3)
  stw       r0, 0x33E0(r13)

.loc_0x128:
  lwz       r0, 0x33F0(r13)
  cmplwi    r0, 0
  bne-      .loc_0x138
  bl        -0x36C

.loc_0x138:
  mr        r3, r31
  bl        -0xEE50
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  mtlr      r0
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void ARQRemoveRequest(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
void ARQRemoveOwnerRequest(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void ARQFlushQueue(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void ARQSetChunkSize(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void ARQGetChunkSize(void)
{
	// UNUSED FUNCTION
}
