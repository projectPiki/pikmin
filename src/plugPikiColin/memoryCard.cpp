#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void MemoryCard::GetBlockSize(s32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800738C8
 * Size:	00000C
 */
void MemoryCard::getOptionsOffset(int)
{
	/*
	.loc_0x0:
	  rlwinm    r3,r4,13,0,18
	  addi      r3, r3, 0x2000
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800738D4
 * Size:	00000C
 */
void MemoryCard::getGameFileOffset(int)
{
	/*
	.loc_0x0:
	  rlwinm    r3,r4,15,0,16
	  addi      r3, r3, 0x6000
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void MemoryCard::getBannerPtr()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void MemoryCard::getOptionsPtr(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void MemoryCard::getGameFilePtr(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void MemoryCard::getBannerStream()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void MemoryCard::getOptionsStream(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void MemoryCard::getGameFileStream(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800738E0
 * Size:	00017C
 */
void MemoryCard::calcChecksum(void*, u32)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x28(r1)
	  rlwinm    r12,r5,30,2,31
	  cmplwi    r12, 0
	  stw       r31, 0x24(r1)
	  lis       r3, 0x3254
	  addi      r31, r3, 0x6532
	  stw       r30, 0x20(r1)
	  li        r30, 0
	  ble-      .loc_0x160
	  rlwinm.   r0,r12,30,2,31
	  mtctr     r0
	  beq-      .loc_0x120

	.loc_0x30:
	  rlwinm    r11,r30,0,24,31
	  lwz       r0, 0x0(r4)
	  addi      r6, r11, 0x1
	  rlwinm    r7,r30,24,0,7
	  rlwinm    r5,r6,16,8,15
	  addi      r30, r30, 0x1
	  addi      r10, r11, 0x2
	  subi      r8, r11, 0x1
	  rlwinm    r11,r30,0,24,31
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  or        r3, r7, r5
	  rlwimi    r3,r10,0,24,31
	  addi      r6, r11, 0x1
	  rlwinm    r7,r30,24,0,7
	  rlwinm    r5,r6,16,8,15
	  addi      r10, r11, 0x2
	  add       r31, r31, r3
	  add       r31, r31, r0
	  lwz       r0, 0x4(r4)
	  subi      r8, r11, 0x1
	  addi      r30, r30, 0x1
	  rlwinm    r11,r30,0,24,31
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  rlwinm    r9,r10,0,24,31
	  or        r3, r7, r5
	  addi      r6, r11, 0x1
	  rlwinm    r7,r30,24,0,7
	  rlwinm    r5,r6,16,8,15
	  or        r3, r9, r3
	  add       r31, r31, r3
	  add       r31, r31, r0
	  lwz       r0, 0x8(r4)
	  subi      r8, r11, 0x1
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  addi      r30, r30, 0x1
	  addi      r10, r11, 0x2
	  rlwinm    r11,r30,0,24,31
	  or        r3, r7, r5
	  rlwimi    r3,r10,0,24,31
	  addi      r6, r11, 0x1
	  add       r31, r31, r3
	  rlwinm    r5,r6,16,8,15
	  rlwimi    r5,r30,24,0,7
	  add       r31, r31, r0
	  lwz       r0, 0xC(r4)
	  subi      r8, r11, 0x1
	  addi      r3, r5, 0
	  addi      r10, r11, 0x2
	  rlwimi    r3,r8,8,16,23
	  rlwimi    r3,r10,0,24,31
	  add       r31, r31, r3
	  add       r31, r31, r0
	  addi      r4, r4, 0x10
	  addi      r30, r30, 0x1
	  bdnz+     .loc_0x30
	  andi.     r12, r12, 0x3
	  beq-      .loc_0x160

	.loc_0x120:
	  mtctr     r12

	.loc_0x124:
	  rlwinm    r11,r30,0,24,31
	  lwz       r0, 0x0(r4)
	  addi      r6, r11, 0x1
	  rlwinm    r5,r6,16,8,15
	  rlwimi    r5,r30,24,0,7
	  subi      r8, r11, 0x1
	  addi      r3, r5, 0
	  addi      r10, r11, 0x2
	  rlwimi    r3,r8,8,16,23
	  rlwimi    r3,r10,0,24,31
	  add       r31, r31, r3
	  add       r31, r31, r0
	  addi      r4, r4, 0x4
	  addi      r30, r30, 0x1
	  bdnz+     .loc_0x124

	.loc_0x160:
	  lis       r3, 0x3254
	  lwz       r30, 0x20(r1)
	  addi      r0, r3, 0x6532
	  sub       r3, r0, r31
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80073A5C
 * Size:	000070
 */
void MemoryCard::hasCardFinished()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  bl        -0x26298
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm    r0,r0,27,5,31
	  mr        r31, r0
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x54
	  li        r3, 0
	  bl        -0x262EC
	  bl        -0x262A0
	  bl        -0x26338
	  cmpwi     r3, -0x1
	  bge-      .loc_0x54
	  li        r0, 0x1
	  stb       r0, 0x68(r30)

	.loc_0x54:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void MemoryCard::waitPolling()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void MemoryCard::createFile(CARDStat&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void MemoryCard::writeOneBanner()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void MemoryCard::writeOneOption(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void MemoryCard::writeOneGameFile(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80073ACC
 * Size:	000134
 */
void MemoryCard::attemptFormatCard(int)
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
	  addi      r3, r31, 0
	  bl        0x196FB8
	  cmpwi     r3, 0
	  beq-      .loc_0x110
	  lis       r3, 0x803A
	  subi      r4, r3, 0x1DA0
	  addi      r3, r31, 0
	  li        r5, 0
	  li        r6, 0
	  bl        0x197478
	  cmpwi     r3, 0
	  bge-      .loc_0x5C
	  li        r0, -0x2
	  stw       r0, 0x44(r30)
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0x5C:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x134
	  cmpwi     r3, -0x6
	  beq-      .loc_0xA0
	  bge-      .loc_0x80
	  cmpwi     r3, -0xD
	  beq-      .loc_0xA0
	  b         .loc_0x88

	.loc_0x80:
	  cmpwi     r3, 0
	  beq-      .loc_0xA0

	.loc_0x88:
	  mr        r3, r31
	  bl        0x197698
	  li        r0, -0x6
	  stw       r0, 0x44(r30)
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0xA0:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x19786C
	  cmpwi     r3, 0
	  bge-      .loc_0xCC
	  mr        r3, r31
	  bl        0x19766C
	  li        r0, -0x6
	  stw       r0, 0x44(r30)
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0xCC:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        .loc_0x134
	  cmpwi     r3, 0
	  bge-      .loc_0xF8
	  mr        r3, r31
	  bl        0x197640
	  li        r0, -0x6
	  stw       r0, 0x44(r30)
	  li        r3, 0
	  b         .loc_0x11C

	.loc_0xF8:
	  mr        r3, r31
	  bl        0x197628
	  li        r0, 0
	  stw       r0, 0x44(r30)
	  li        r3, 0x1
	  b         .loc_0x11C

	.loc_0x110:
	  li        r0, -0x1
	  stw       r0, 0x44(r30)
	  li        r3, 0

	.loc_0x11C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x134:
	*/
}

/*
 * --INFO--
 * Address:	80073C00
 * Size:	000038
 */
void MemoryCard::waitWhileBusy(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4

	.loc_0x14:
	  mr        r3, r31
	  bl        0x195358
	  cmpwi     r3, -0x1
	  beq+      .loc_0x14
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80073C38
 * Size:	0001BC
 */
void MemoryCard::getCardStatus(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  addi      r3, r30, 0
	  bl        0x196E4C
	  cmpwi     r3, 0
	  beq-      .loc_0x198
	  lis       r3, 0x803A
	  subi      r4, r3, 0x1DA0
	  addi      r3, r30, 0
	  li        r5, 0
	  li        r6, 0
	  bl        0x19730C
	  cmpwi     r3, 0
	  bge-      .loc_0x5C
	  li        r0, -0x2
	  stw       r0, 0x44(r31)
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0x5C:
	  mr        r3, r30
	  bl        0x1952D8
	  cmpwi     r3, -0x1
	  beq+      .loc_0x5C
	  cmpwi     r3, -0x6
	  beq-      .loc_0xA8
	  bge-      .loc_0x84
	  cmpwi     r3, -0xD
	  beq-      .loc_0x90
	  b         .loc_0xE4

	.loc_0x84:
	  cmpwi     r3, 0
	  beq-      .loc_0xA8
	  b         .loc_0xE4

	.loc_0x90:
	  mr        r3, r30
	  bl        0x197524
	  li        r0, -0x5
	  stw       r0, 0x44(r31)
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0xA8:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x196D40
	  cmpwi     r3, 0
	  bge-      .loc_0xD4
	  mr        r3, r30
	  bl        0x1974F8
	  li        r0, -0x4
	  stw       r0, 0x44(r31)
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0xD4:
	  mr        r3, r30
	  bl        0x195260
	  cmpwi     r3, -0x1
	  beq+      .loc_0xD4

	.loc_0xE4:
	  cmpwi     r3, -0x3
	  beq-      .loc_0x108
	  bge-      .loc_0xFC
	  cmpwi     r3, -0x6
	  beq-      .loc_0x118
	  b         .loc_0x130

	.loc_0xFC:
	  cmpwi     r3, 0
	  beq-      .loc_0x140
	  b         .loc_0x130

	.loc_0x108:
	  li        r0, -0x1
	  stw       r0, 0x44(r31)
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0x118:
	  mr        r3, r30
	  bl        0x19749C
	  li        r0, -0x4
	  stw       r0, 0x44(r31)
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0x130:
	  li        r0, -0x7
	  stw       r0, 0x44(r31)
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0x140:
	  addi      r3, r30, 0
	  addi      r4, r31, 0x64
	  bl        0x195340
	  cmpwi     r3, 0
	  bge-      .loc_0x16C
	  mr        r3, r30
	  bl        0x197460
	  li        r0, -0x4
	  stw       r0, 0x44(r31)
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0x16C:
	  lwz       r0, 0x64(r31)
	  cmplwi    r0, 0x2000
	  ble-      .loc_0x190
	  mr        r3, r30
	  bl        0x19743C
	  li        r0, -0x6
	  stw       r0, 0x44(r31)
	  li        r3, 0
	  b         .loc_0x1A4

	.loc_0x190:
	  li        r3, 0x1
	  b         .loc_0x1A4

	.loc_0x198:
	  li        r0, -0x1
	  stw       r0, 0x44(r31)
	  li        r3, 0

	.loc_0x1A4:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80073DF4
 * Size:	0000FC
 */
void MemoryCard::checkUseFile()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8000
	  stw       r0, 0x4(r1)
	  lis       r5, 0x51EC
	  stwu      r1, -0xB8(r1)
	  stmw      r27, 0xA4(r1)
	  addi      r27, r3, 0
	  subi      r30, r5, 0x7AE1
	  li        r28, 0
	  lwz       r0, 0xF8(r4)
	  lis       r4, 0x802B
	  subi      r31, r4, 0x5FC4
	  rlwinm    r29,r0,30,2,31

	.loc_0x34:
	  lwz       r3, 0x34(r27)
	  addi      r4, r28, 0
	  addi      r5, r1, 0xC
	  bl        0x19903C
	  cmpwi     r3, 0
	  blt-      .loc_0xDC
	  lwz       r5, 0x30(r1)
	  li        r4, 0
	  mullw     r3, r4, r29
	  mulhwu    r0, r5, r29
	  add       r3, r3, r0
	  mullw     r0, r5, r4
	  mullw     r4, r5, r29
	  add       r3, r3, r0
	  addi      r5, r1, 0x78
	  bl        0x18975C
	  addi      r4, r31, 0
	  addi      r3, r1, 0xC
	  li        r5, 0xF
	  bl        0x1A5310
	  cmpwi     r3, 0
	  bne-      .loc_0xA0
	  addi      r3, r27, 0x14
	  addi      r4, r1, 0xC
	  bl        0x1A54D0
	  stw       r28, 0x38(r27)
	  b         .loc_0xE8

	.loc_0xA0:
	  addi      r3, r1, 0xC
	  subi      r4, r13, 0x654C
	  li        r5, 0x6
	  bl        0x1A52E4
	  cmpwi     r3, 0
	  bne-      .loc_0xC0
	  stw       r28, 0x3C(r27)
	  b         .loc_0xDC

	.loc_0xC0:
	  addi      r3, r1, 0xC
	  subi      r4, r13, 0x6544
	  li        r5, 0x7
	  bl        0x1A52C4
	  cmpwi     r3, 0
	  bne-      .loc_0xDC
	  stw       r28, 0x3C(r27)

	.loc_0xDC:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x7F
	  blt+      .loc_0x34

	.loc_0xE8:
	  lmw       r27, 0xA4(r1)
	  lwz       r0, 0xBC(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80073EF0
 * Size:	000174
 */
void MemoryCard::getMemoryCardState(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  li        r28, -0x1
	  rlwinm    r29,r4,0,24,31
	  addi      r31, r3, 0
	  subi      r30, r5, 0x1DA0
	  li        r27, 0
	  li        r4, 0
	  stw       r28, 0x34(r3)
	  stw       r0, 0x44(r3)
	  stw       r28, 0x38(r31)
	  stw       r28, 0x3C(r31)
	  bl        -0x2F8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF0
	  stw       r27, 0x34(r31)
	  mr        r3, r31
	  bl        -0x150
	  lwz       r0, 0x38(r31)
	  cmpwi     r0, -0x1
	  bne-      .loc_0xF0
	  lwz       r3, 0x34(r31)
	  addi      r4, r1, 0x14
	  addi      r5, r1, 0x10
	  bl        0x195040
	  cmpwi     r3, 0
	  bge-      .loc_0x94
	  lwz       r3, 0x34(r31)
	  bl        0x197280
	  stw       r28, 0x34(r31)
	  li        r0, -0x4
	  stw       r0, 0x44(r31)
	  b         .loc_0x15C

	.loc_0x94:
	  lwz       r0, 0x10(r1)
	  cmpwi     r0, 0x1
	  bge-      .loc_0xBC
	  lwz       r3, 0x34(r31)
	  bl        0x19725C
	  li        r0, -0x2
	  stw       r0, 0x38(r31)
	  li        r0, -0x8
	  stw       r0, 0x44(r31)
	  b         .loc_0x15C

	.loc_0xBC:
	  lwz       r3, 0x14(r1)
	  lwz       r0, 0x40(r31)
	  cmplw     r3, r0
	  bge-      .loc_0xE8
	  lwz       r3, 0x34(r31)
	  bl        0x197230
	  li        r0, -0x2
	  stw       r0, 0x38(r31)
	  li        r0, -0x3
	  stw       r0, 0x44(r31)
	  b         .loc_0x15C

	.loc_0xE8:
	  lwz       r3, 0x34(r31)
	  bl        0x197214

	.loc_0xF0:
	  cmplwi    r29, 0
	  beq-      .loc_0x124
	  lwz       r0, 0x34(r31)
	  cmpwi     r0, 0
	  blt-      .loc_0x124
	  lwz       r0, 0x38(r31)
	  cmpwi     r0, -0x2
	  beq-      .loc_0x124
	  mr        r3, r31
	  bl        .loc_0x174
	  li        r0, 0
	  stw       r0, 0x44(r31)
	  b         .loc_0x15C

	.loc_0x124:
	  lwz       r0, 0x3C(r31)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x15C
	  li        r3, 0
	  addi      r4, r30, 0
	  bl        -0x268B4
	  bl        -0x26834
	  li        r3, 0
	  lwz       r4, 0x3C(r31)
	  bl        -0x26800
	  bl        -0x26844
	  li        r3, 0
	  bl        -0x2689C
	  bl        -0x26850

	.loc_0x15C:
	  lwz       r3, 0x44(r31)
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x174:
	*/
}

/*
 * --INFO--
 * Address:	80074064
 * Size:	0000B0
 */
void MemoryCard::loadCurrentFile()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  subi      r31, r4, 0x1E20
	  addi      r4, r31, 0x80
	  stw       r30, 0x38(r1)
	  addi      r30, r3, 0
	  li        r3, 0
	  bl        -0x26918
	  bl        -0x26898
	  lwz       r4, 0x38(r30)
	  addi      r5, r31, 0
	  li        r3, 0
	  bl        0x198DD0
	  addis     r5, r31, 0x1
	  lwz       r4, 0x38(r30)
	  li        r3, 0
	  subi      r5, r5, 0x5F80
	  bl        -0x26848
	  bl        -0x268C0
	  li        r3, 0
	  bl        -0x26918
	  bl        -0x268CC
	  lis       r3, 0x8000
	  lwz       r7, 0x24(r31)
	  lwz       r0, 0xF8(r3)
	  li        r6, 0
	  addi      r5, r1, 0x10
	  rlwinm    r4,r0,30,2,31
	  mullw     r3, r6, r4
	  mulhwu    r0, r7, r4
	  add       r3, r3, r0
	  mullw     r0, r7, r6
	  mullw     r4, r7, r4
	  add       r3, r3, r0
	  bl        0x1894C8
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80074114
 * Size:	0001DC
 */
void MemoryCard::getNewestOptionsIndex()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x803B
	  stw       r0, 0x4(r1)
	  lis       r5, 0x8022
	  lis       r4, 0x8022
	  stwu      r1, -0x80(r1)
	  lis       r3, 0x802A
	  stmw      r20, 0x50(r1)
	  lis       r26, 0x3254
	  subi      r27, r6, 0x7DA0
	  addi      r28, r26, 0x6532
	  addi      r29, r5, 0x7398
	  addi      r30, r4, 0x74C8
	  addi      r31, r3, 0x755C
	  li        r23, -0x1
	  li        r22, -0x1
	  li        r21, 0
	  li        r25, 0x2000

	.loc_0x48:
	  li        r0, 0x2AA
	  add       r24, r27, r25
	  mtctr     r0
	  addi      r11, r24, 0
	  addi      r10, r26, 0x6532
	  li        r9, 0

	.loc_0x60:
	  rlwinm    r8,r9,0,24,31
	  lwz       r0, 0x0(r11)
	  addi      r4, r8, 0x1
	  rlwinm    r5,r9,24,0,7
	  rlwinm    r3,r4,16,8,15
	  subi      r6, r8, 0x1
	  or        r3, r5, r3
	  rlwinm    r5,r6,8,16,23
	  addi      r9, r9, 0x1
	  addi      r7, r8, 0x2
	  rlwinm    r8,r9,0,24,31
	  or        r3, r5, r3
	  rlwimi    r3,r7,0,24,31
	  add       r10, r10, r3
	  addi      r4, r8, 0x1
	  rlwinm    r5,r9,24,0,7
	  rlwinm    r3,r4,16,8,15
	  add       r10, r10, r0
	  lwz       r0, 0x4(r11)
	  subi      r6, r8, 0x1
	  or        r3, r5, r3
	  rlwinm    r5,r6,8,16,23
	  addi      r7, r8, 0x2
	  addi      r9, r9, 0x1
	  rlwinm    r8,r9,0,24,31
	  or        r3, r5, r3
	  rlwimi    r3,r7,0,24,31
	  add       r10, r10, r3
	  addi      r4, r8, 0x1
	  rlwinm    r3,r4,16,8,15
	  rlwimi    r3,r9,24,0,7
	  subi      r6, r8, 0x1
	  add       r10, r10, r0
	  lwz       r0, 0x8(r11)
	  addi      r7, r8, 0x2
	  rlwimi    r3,r6,8,16,23
	  rlwimi    r3,r7,0,24,31
	  add       r10, r10, r3
	  add       r10, r10, r0
	  addi      r11, r11, 0xC
	  addi      r9, r9, 0x1
	  bdnz+     .loc_0x60
	  sub       r20, r28, r10
	  li        r3, 0x14
	  bl        -0x2D220
	  cmplwi    r3, 0
	  beq-      .loc_0x13C
	  stw       r29, 0x4(r3)
	  li        r4, 0
	  li        r0, 0x2000
	  stw       r30, 0x4(r3)
	  stw       r31, 0x4(r3)
	  stw       r24, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x13C:
	  mr        r24, r3
	  lwz       r12, 0x4(r24)
	  li        r4, 0x1FF8
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r24
	  lwz       r12, 0x4(r24)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r24, 0
	  lwz       r12, 0x4(r24)
	  mr        r24, r0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplw     r3, r20
	  bne-      .loc_0x19C
	  cmpw      r24, r23
	  ble-      .loc_0x19C
	  addi      r23, r24, 0
	  addi      r22, r21, 0

	.loc_0x19C:
	  addi      r21, r21, 0x1
	  cmpwi     r21, 0x2
	  addi      r25, r25, 0x2000
	  blt+      .loc_0x48
	  cmpwi     r22, -0x1
	  beq-      .loc_0x1C4
	  lis       r3, 0x803A
	  addi      r0, r23, 0x1
	  subi      r3, r3, 0x2848
	  stw       r0, 0x174(r3)

	.loc_0x1C4:
	  mr        r3, r22
	  lmw       r20, 0x50(r1)
	  lwz       r0, 0x84(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800742F0
 * Size:	0000A4
 */
void MemoryCard::loadOptions()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  bl        -0x1EC
	  addi      r31, r3, 0
	  cmpwi     r31, -0x1
	  beq-      .loc_0x90
	  li        r3, 0x14
	  bl        -0x2D310
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  lis       r4, 0x8022
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x74C8
	  lis       r5, 0x802A
	  stw       r0, 0x4(r3)
	  lis       r4, 0x803B
	  addi      r0, r5, 0x755C
	  rlwinm    r5,r31,13,0,18
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x7DA0
	  add       r4, r5, r0
	  addi      r0, r4, 0x2000
	  stw       r0, 0x8(r3)
	  li        r4, 0
	  li        r0, 0x2000
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x7C:
	  lis       r4, 0x803A
	  subi      r5, r4, 0x2848
	  addi      r4, r3, 0
	  addi      r3, r5, 0x94
	  bl        -0x1FD60

	.loc_0x90:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80074394
 * Size:	0000D4
 */
void MemoryCard::saveOptions()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r4, 0x2DEC(r13)
	  stw       r0, 0x270(r4)
	  li        r0, 0
	  li        r4, 0x1
	  stb       r0, 0x68(r30)
	  bl        -0x4D4
	  cmpwi     r3, 0
	  bne-      .loc_0xB0
	  lwz       r0, 0x38(r30)
	  cmpwi     r0, 0
	  blt-      .loc_0xB0
	  mr        r3, r30
	  bl        -0x2CC
	  cmpwi     r3, -0x1
	  beq-      .loc_0xB0
	  xori      r31, r3, 0x1
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0xA88
	  lis       r3, 0x803A
	  subi      r4, r3, 0x1DA0
	  li        r3, 0
	  bl        -0x26C94
	  bl        -0x26C14
	  rlwinm    r5,r31,13,0,18
	  lwz       r4, 0x38(r30)
	  lis       r3, 0x803B
	  subi      r0, r3, 0x7DA0
	  addi      r6, r5, 0x2000
	  add       r5, r0, r6
	  li        r3, 0
	  li        r7, 0x2000
	  bl        -0x26B5C

	.loc_0xA0:
	  mr        r3, r30
	  bl        -0x9DC
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0xA0

	.loc_0xB0:
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  stw       r0, 0x270(r3)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80074468
 * Size:	0000AC
 */
void MemoryCard::loadCurrentGame()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x2848
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  li        r3, 0x14
	  stw       r30, 0x28(r1)
	  lbz       r4, 0xB4(r4)
	  subi      r30, r4, 0x1
	  bl        -0x2D490
	  cmplwi    r3, 0
	  beq-      .loc_0x88
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  lis       r4, 0x8022
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x74C8
	  lis       r5, 0x802A
	  stw       r0, 0x4(r3)
	  lis       r4, 0x803B
	  addi      r0, r5, 0x755C
	  rlwinm    r5,r30,15,0,16
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x7DA0
	  add       r4, r5, r0
	  addi      r0, r4, 0x6000
	  lis       r4, 0x1
	  stw       r0, 0x8(r3)
	  li        r0, 0
	  stw       r0, 0xC(r3)
	  subi      r0, r4, 0x8000
	  stw       r0, 0x10(r3)

	.loc_0x88:
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0x568
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80074514
 * Size:	000424
 */
void MemoryCard::saveCurrentGame()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x90(r1)
	  stmw      r25, 0x74(r1)
	  li        r31, 0
	  addi      r26, r3, 0
	  subi      r30, r5, 0x1E20
	  stb       r31, 0x68(r3)
	  lis       r3, 0x803A
	  subi      r4, r3, 0x2848
	  lwz       r3, 0x2DEC(r13)
	  addi      r29, r4, 0xB5
	  stw       r0, 0x270(r3)
	  li        r0, 0x2
	  li        r3, 0x14
	  stb       r0, 0x1C4(r4)
	  lwz       r0, 0x2FC(r4)
	  stb       r0, 0x1C5(r4)
	  lbz       r4, 0xB5(r4)
	  subi      r25, r4, 0x1
	  bl        -0x2D568
	  cmplwi    r3, 0
	  beq-      .loc_0xAC
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  lis       r4, 0x8022
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x74C8
	  lis       r4, 0x802A
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x755C
	  addis     r4, r30, 0x1
	  stw       r0, 0x4(r3)
	  rlwinm    r0,r25,15,0,16
	  add       r4, r0, r4
	  addi      r0, r4, 0x80
	  stw       r0, 0x8(r3)
	  lis       r4, 0x1
	  subi      r0, r4, 0x8000
	  stw       r31, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0xAC:
	  lis       r4, 0x803A
	  addi      r27, r3, 0
	  subi      r5, r4, 0x2848
	  addi      r3, r26, 0
	  addi      r4, r27, 0
	  addi      r5, r5, 0x1A4
	  bl        .loc_0x424
	  mr        r3, r27
	  lwz       r12, 0x4(r27)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lis       r4, 0x1
	  subi      r0, r4, 0x8000
	  sub       r3, r0, r3
	  subi      r28, r3, 0x8
	  li        r25, 0
	  b         .loc_0x110

	.loc_0xF4:
	  mr        r3, r27
	  lwz       r12, 0x4(r27)
	  li        r4, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r25, r25, 0x1

	.loc_0x110:
	  cmpw      r25, r28
	  blt+      .loc_0xF4
	  lbz       r3, 0x0(r29)
	  li        r0, 0x666
	  mtctr     r0
	  lis       r4, 0x3254
	  subi      r0, r3, 0x1
	  addis     r3, r30, 0x1
	  rlwinm    r0,r0,15,0,16
	  add       r12, r0, r3
	  addi      r25, r4, 0x6532
	  li        r11, 0
	  addi      r12, r12, 0x80

	.loc_0x144:
	  rlwinm    r10,r11,0,24,31
	  lwz       r0, 0x0(r12)
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  subi      r7, r10, 0x1
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  addi      r11, r11, 0x1
	  addi      r9, r10, 0x2
	  rlwinm    r10,r11,0,24,31
	  or        r3, r6, r4
	  rlwimi    r3,r9,0,24,31
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  addi      r9, r10, 0x2
	  rlwinm    r4,r5,16,8,15
	  add       r25, r25, r3
	  add       r25, r25, r0
	  lwz       r0, 0x4(r12)
	  addi      r11, r11, 0x1
	  subi      r7, r10, 0x1
	  rlwinm    r10,r11,0,24,31
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  rlwinm    r8,r9,0,24,31
	  or        r3, r6, r4
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  or        r3, r8, r3
	  addi      r9, r10, 0x2
	  add       r25, r25, r3
	  add       r25, r25, r0
	  lwz       r0, 0x8(r12)
	  subi      r7, r10, 0x1
	  addi      r11, r11, 0x1
	  rlwinm    r10,r11,0,24,31
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  rlwinm    r8,r9,0,24,31
	  or        r3, r6, r4
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  or        r3, r8, r3
	  add       r25, r25, r3
	  add       r25, r25, r0
	  lwz       r0, 0xC(r12)
	  subi      r7, r10, 0x1
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  addi      r11, r11, 0x1
	  addi      r9, r10, 0x2
	  rlwinm    r10,r11,0,24,31
	  or        r3, r6, r4
	  rlwimi    r3,r9,0,24,31
	  addi      r5, r10, 0x1
	  add       r25, r25, r3
	  rlwinm    r4,r5,16,8,15
	  rlwimi    r4,r11,24,0,7
	  add       r25, r25, r0
	  lwz       r0, 0x10(r12)
	  subi      r7, r10, 0x1
	  addi      r3, r4, 0
	  addi      r9, r10, 0x2
	  rlwimi    r3,r7,8,16,23
	  rlwimi    r3,r9,0,24,31
	  add       r25, r25, r3
	  add       r25, r25, r0
	  addi      r12, r12, 0x14
	  addi      r11, r11, 0x1
	  bdnz+     .loc_0x144
	  mr        r3, r27
	  lwz       r12, 0x4(r27)
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r12, 0x24(r12)
	  lis       r5, 0x3254
	  addi      r0, r5, 0x6532
	  addi      r31, r4, 0x170
	  mtlr      r12
	  sub       r28, r0, r25
	  lwz       r4, 0x170(r4)
	  mr        r25, r28
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x4(r27)
	  mr        r4, r25
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lbz       r5, 0x0(r29)
	  addi      r4, r30, 0x80
	  li        r3, 0
	  subi      r25, r5, 0x1
	  bl        -0x27064
	  bl        -0x26FE4
	  rlwinm    r3,r25,15,0,16
	  lwz       r4, 0x38(r26)
	  addi      r6, r3, 0x6000
	  addis     r0, r30, 0x1
	  add       r5, r0, r6
	  lis       r3, 0x1
	  subi      r7, r3, 0x8000
	  li        r3, 0
	  subi      r5, r5, 0x5F80
	  bl        -0x26F30
	  li        r27, 0x1

	.loc_0x2F8:
	  bl        -0x27030
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm    r25,r0,27,5,31
	  rlwinm.   r0,r0,27,24,31
	  beq-      .loc_0x32C
	  li        r3, 0
	  bl        -0x27080
	  bl        -0x27034
	  bl        -0x270CC
	  cmpwi     r3, -0x1
	  bge-      .loc_0x32C
	  stb       r27, 0x68(r26)

	.loc_0x32C:
	  rlwinm.   r0,r25,0,24,31
	  beq+      .loc_0x2F8
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x1
	  li        r0, 0
	  stw       r4, 0x270(r3)
	  addi      r3, r26, 0
	  li        r4, 0x1
	  stb       r0, 0x68(r26)
	  bl        -0x974
	  cmpwi     r3, 0
	  bne-      .loc_0x3CC
	  lwz       r0, 0x38(r26)
	  cmpwi     r0, 0
	  blt-      .loc_0x3CC
	  mr        r3, r26
	  bl        -0x76C
	  cmpwi     r3, -0x1
	  beq-      .loc_0x3CC
	  xori      r25, r3, 0x1
	  addi      r3, r26, 0
	  addi      r4, r25, 0
	  bl        0x5E8
	  li        r3, 0
	  addi      r4, r30, 0x80
	  bl        -0x27130
	  bl        -0x270B0
	  rlwinm    r3,r25,13,0,18
	  lwz       r4, 0x38(r26)
	  addi      r6, r3, 0x2000
	  addis     r0, r30, 0x1
	  add       r5, r0, r6
	  li        r3, 0
	  li        r7, 0x2000
	  subi      r5, r5, 0x5F80
	  bl        -0x26FF8

	.loc_0x3BC:
	  mr        r3, r26
	  bl        -0xE78
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x3BC

	.loc_0x3CC:
	  lwz       r4, 0x2DEC(r13)
	  li        r5, 0
	  lis       r3, 0x803A
	  stw       r5, 0x270(r4)
	  subi      r4, r3, 0x2848
	  li        r0, 0x1
	  lbz       r7, 0xB4(r4)
	  lbz       r3, 0x0(r29)
	  stb       r3, 0xB4(r4)
	  stb       r7, 0x0(r29)
	  stw       r28, 0x1A0(r4)
	  lwz       r3, 0x0(r31)
	  addi      r3, r3, 0x1
	  stw       r3, 0x0(r31)
	  stb       r0, 0xB2(r4)
	  lwz       r3, 0x2DEC(r13)
	  stw       r5, 0x270(r3)
	  lmw       r25, 0x74(r1)
	  lwz       r0, 0x94(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr

	.loc_0x424:
	*/
}

/*
 * --INFO--
 * Address:	80074938
 * Size:	000128
 */
void MemoryCard::writeCurrentGame(RandomAccessStream*, PlayState&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x38(r1)
	  addi      r30, r4, 0
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xD8
	  lbz       r0, 0x184(r3)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x54
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  lwz       r4, 0x14(r3)
	  lwz       r0, 0x10(r3)
	  lwz       r3, 0xC(r3)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  b         .loc_0x58

	.loc_0x54:
	  li        r0, -0x1

	.loc_0x58:
	  stw       r0, 0x14(r31)
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x184(r3)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x8C
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  lwz       r4, 0x20(r3)
	  lwz       r0, 0x1C(r3)
	  lwz       r3, 0x18(r3)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  b         .loc_0x90

	.loc_0x8C:
	  li        r0, -0x1

	.loc_0x90:
	  stw       r0, 0x18(r31)
	  lwz       r3, 0x2F6C(r13)
	  lbz       r0, 0x184(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0xC4
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  add       r0, r0, r4
	  add       r0, r3, r0
	  b         .loc_0xC8

	.loc_0xC4:
	  li        r0, -0x1

	.loc_0xC8:
	  stw       r0, 0x1C(r31)
	  lwz       r3, 0x2F6C(r13)
	  bl        0xB218
	  stb       r3, 0x22(r31)

	.loc_0xD8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x20(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x110
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x110
	  mr        r4, r30
	  bl        0xB268

	.loc_0x110:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80074A60
 * Size:	000070
 */
void MemoryCard::readCurrentGame(RandomAccessStream*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  subi      r31, r3, 0x2848
	  addi      r3, r31, 0x1A4
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  bl        -0x20044
	  lbz       r0, 0x1C4(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x48
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  mr        r4, r30
	  bl        0xB604

	.loc_0x48:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lbz       r0, 0x1C5(r3)
	  stw       r0, 0x2FC(r3)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80074AD0
 * Size:	0003B0
 */
void MemoryCard::initBannerArea(CARDStat&, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x7398
	  lis       r3, 0x8022
	  crclr     6, 0x6
	  stwu      r1, -0x88(r1)
	  stw       r31, 0x84(r1)
	  stw       r30, 0x80(r1)
	  li        r30, 0
	  stw       r29, 0x7C(r1)
	  stw       r28, 0x78(r1)
	  addi      r28, r4, 0
	  lwz       r4, 0x20(r4)
	  stw       r0, 0x28(r1)
	  addi      r0, r3, 0x74C8
	  lis       r3, 0x802A
	  stw       r0, 0x28(r1)
	  addi      r0, r3, 0x755C
	  lis       r3, 0x803B
	  stw       r0, 0x28(r1)
	  subi      r0, r3, 0x7DA0
	  lis       r3, 0x802B
	  stw       r0, 0x2C(r1)
	  subi      r31, r3, 0x5FE0
	  addi      r3, r1, 0x58
	  stw       r30, 0x30(r1)
	  stw       r4, 0x34(r1)
	  subi      r4, r13, 0x654C
	  bl        0x1A1A54
	  addi      r3, r1, 0x38
	  crclr     6, 0x6
	  subi      r4, r13, 0x653C
	  bl        0x1A1A44
	  lwz       r0, 0x30(r1)
	  addi      r4, r1, 0x58
	  li        r5, 0x20
	  stw       r0, 0x38(r28)
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  add       r3, r3, r0
	  bl        -0x71760
	  lwz       r3, 0x30(r1)
	  addi      r4, r1, 0x38
	  li        r5, 0x20
	  addi      r0, r3, 0x20
	  stw       r0, 0x30(r1)
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  add       r3, r3, r0
	  bl        -0x71784
	  lwz       r3, 0x30(r1)
	  li        r0, 0x1
	  addi      r4, r31, 0xE40
	  addi      r3, r3, 0x20
	  stw       r3, 0x30(r1)
	  li        r5, 0xC00
	  lwz       r3, 0x30(r1)
	  stw       r3, 0x30(r28)
	  stb       r0, 0x2E(r28)
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  add       r3, r3, r0
	  bl        -0x717B8
	  lwz       r3, 0x30(r1)
	  addi      r4, r31, 0xC40
	  li        r5, 0x200
	  addi      r0, r3, 0xC00
	  stw       r0, 0x30(r1)
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  add       r3, r3, r0
	  bl        -0x717DC
	  lwz       r3, 0x30(r1)
	  addi      r31, r31, 0x1A40
	  li        r29, 0
	  addi      r0, r3, 0x200
	  stw       r0, 0x30(r1)

	.loc_0x138:
	  lwz       r0, 0x0(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x18C
	  li        r0, 0x3
	  lhz       r4, 0x34(r28)
	  slw       r3, r0, r30
	  li        r0, 0x1
	  andc      r3, r4, r3
	  slw       r0, r0, r30
	  or        r0, r3, r0
	  sth       r0, 0x34(r28)
	  li        r5, 0x400
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  lwz       r4, 0x0(r31)
	  add       r3, r3, r0
	  bl        -0x71834
	  lwz       r3, 0x30(r1)
	  addi      r0, r3, 0x400
	  stw       r0, 0x30(r1)
	  b         .loc_0x1A0

	.loc_0x18C:
	  li        r0, 0x3
	  lhz       r3, 0x34(r28)
	  slw       r0, r0, r30
	  andc      r0, r3, r0
	  sth       r0, 0x34(r28)

	.loc_0x1A0:
	  li        r5, 0x3
	  lhz       r0, 0x36(r28)
	  slw       r3, r5, r30
	  andc      r0, r0, r3
	  addi      r29, r29, 0x1
	  or        r0, r0, r3
	  cmpwi     r29, 0x8
	  sth       r0, 0x36(r28)
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x2
	  blt+      .loc_0x138
	  rlwinm    r6,r29,1,0,30
	  subfic    r3, r29, 0x8
	  bge-      .loc_0x2AC
	  rlwinm.   r0,r3,29,3,31
	  mtctr     r0
	  beq-      .loc_0x290

	.loc_0x1E4:
	  lhz       r4, 0x36(r28)
	  slw       r0, r5, r6
	  addi      r6, r6, 0x2
	  andc      r0, r4, r0
	  sth       r0, 0x36(r28)
	  slw       r0, r5, r6
	  addi      r6, r6, 0x2
	  lhz       r4, 0x36(r28)
	  andc      r0, r4, r0
	  sth       r0, 0x36(r28)
	  slw       r0, r5, r6
	  addi      r6, r6, 0x2
	  lhz       r4, 0x36(r28)
	  andc      r0, r4, r0
	  sth       r0, 0x36(r28)
	  slw       r0, r5, r6
	  addi      r6, r6, 0x2
	  lhz       r4, 0x36(r28)
	  andc      r0, r4, r0
	  sth       r0, 0x36(r28)
	  slw       r0, r5, r6
	  addi      r6, r6, 0x2
	  lhz       r4, 0x36(r28)
	  andc      r0, r4, r0
	  sth       r0, 0x36(r28)
	  slw       r0, r5, r6
	  addi      r6, r6, 0x2
	  lhz       r4, 0x36(r28)
	  andc      r0, r4, r0
	  sth       r0, 0x36(r28)
	  slw       r0, r5, r6
	  addi      r6, r6, 0x2
	  lhz       r4, 0x36(r28)
	  andc      r0, r4, r0
	  sth       r0, 0x36(r28)
	  slw       r0, r5, r6
	  addi      r6, r6, 0x2
	  lhz       r4, 0x36(r28)
	  andc      r0, r4, r0
	  sth       r0, 0x36(r28)
	  bdnz+     .loc_0x1E4
	  andi.     r3, r3, 0x7
	  beq-      .loc_0x2AC

	.loc_0x290:
	  mtctr     r3

	.loc_0x294:
	  lhz       r4, 0x36(r28)
	  slw       r0, r5, r6
	  addi      r6, r6, 0x2
	  andc      r0, r4, r0
	  sth       r0, 0x36(r28)
	  bdnz+     .loc_0x294

	.loc_0x2AC:
	  lwz       r3, 0x2C(r1)
	  li        r5, 0x200
	  lwz       r0, 0x30(r1)
	  lwz       r4, -0x6550(r13)
	  add       r3, r3, r0
	  bl        -0x7197C
	  lwz       r4, 0x30(r1)
	  addi      r3, r1, 0x24
	  addi      r0, r4, 0x200
	  stw       r0, 0x30(r1)
	  lbz       r0, 0x2E(r28)
	  rlwinm    r0,r0,0,30,28
	  ori       r0, r0, 0x4
	  stb       r0, 0x2E(r28)
	  lwz       r12, 0x28(r1)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  subfic    r29, r3, 0x1FFC
	  li        r28, 0
	  b         .loc_0x31C

	.loc_0x300:
	  lwz       r12, 0x28(r1)
	  addi      r3, r1, 0x24
	  li        r4, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r28, 0x1

	.loc_0x31C:
	  cmpw      r28, r29
	  blt+      .loc_0x300
	  lis       r3, 0x803B
	  li        r0, 0x7FF
	  subi      r8, r3, 0x7DA0
	  mtctr     r0
	  lis       r3, 0x3254
	  addi      r7, r3, 0x6532
	  li        r6, 0

	.loc_0x340:
	  rlwinm    r5,r6,0,24,31
	  lwz       r0, 0x0(r8)
	  addi      r3, r5, 0x1
	  subi      r4, r5, 0x1
	  rlwinm    r3,r3,16,8,15
	  rlwimi    r3,r6,24,0,7
	  addi      r5, r5, 0x2
	  rlwimi    r3,r4,8,16,23
	  rlwimi    r3,r5,0,24,31
	  add       r7, r7, r3
	  add       r7, r7, r0
	  addi      r8, r8, 0x4
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x340
	  lis       r3, 0x3254
	  addi      r0, r3, 0x6532
	  sub       r0, r0, r7
	  mr        r4, r0
	  addi      r3, r1, 0x24
	  bl        -0x4FB74
	  lwz       r0, 0x8C(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  lwz       r29, 0x7C(r1)
	  lwz       r28, 0x78(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000404
 */
void MemoryCard::initFileArea(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80074E80
 * Size:	000210
 */
void MemoryCard::initOptionsArea(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x14
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x54(r1)
	  stw       r28, 0x50(r1)
	  bl        -0x2DEA0
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  lis       r4, 0x8022
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x74C8
	  lis       r5, 0x802A
	  stw       r0, 0x4(r3)
	  lis       r4, 0x803B
	  addi      r0, r5, 0x755C
	  rlwinm    r5,r30,13,0,18
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x7DA0
	  add       r4, r5, r0
	  addi      r0, r4, 0x2000
	  stw       r0, 0x8(r3)
	  li        r4, 0
	  li        r0, 0x2000
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x7C:
	  lis       r4, 0x803A
	  addi      r31, r3, 0
	  subi      r3, r4, 0x2848
	  addi      r4, r31, 0
	  addi      r3, r3, 0x94
	  bl        -0x20B24
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  subfic    r28, r3, 0x1FF8
	  li        r29, 0
	  b         .loc_0xD0

	.loc_0xB4:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  li        r4, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x1

	.loc_0xD0:
	  cmpw      r29, r28
	  blt+      .loc_0xB4
	  li        r0, 0x2AA
	  lis       r3, 0x803B
	  mtctr     r0
	  lis       r5, 0x3254
	  rlwinm    r4,r30,13,0,18
	  subi      r0, r3, 0x7DA0
	  add       r11, r4, r0
	  addi      r10, r5, 0x6532
	  li        r9, 0
	  addi      r11, r11, 0x2000

	.loc_0x100:
	  rlwinm    r8,r9,0,24,31
	  lwz       r0, 0x0(r11)
	  addi      r4, r8, 0x1
	  rlwinm    r5,r9,24,0,7
	  rlwinm    r3,r4,16,8,15
	  subi      r6, r8, 0x1
	  or        r3, r5, r3
	  rlwinm    r5,r6,8,16,23
	  addi      r9, r9, 0x1
	  addi      r7, r8, 0x2
	  rlwinm    r8,r9,0,24,31
	  or        r3, r5, r3
	  rlwimi    r3,r7,0,24,31
	  add       r10, r10, r3
	  addi      r4, r8, 0x1
	  rlwinm    r5,r9,24,0,7
	  rlwinm    r3,r4,16,8,15
	  add       r10, r10, r0
	  lwz       r0, 0x4(r11)
	  subi      r6, r8, 0x1
	  or        r3, r5, r3
	  rlwinm    r5,r6,8,16,23
	  addi      r7, r8, 0x2
	  addi      r9, r9, 0x1
	  rlwinm    r8,r9,0,24,31
	  or        r3, r5, r3
	  rlwimi    r3,r7,0,24,31
	  add       r10, r10, r3
	  addi      r4, r8, 0x1
	  rlwinm    r3,r4,16,8,15
	  rlwimi    r3,r9,24,0,7
	  subi      r6, r8, 0x1
	  add       r10, r10, r0
	  lwz       r0, 0x8(r11)
	  addi      r7, r8, 0x2
	  rlwimi    r3,r6,8,16,23
	  rlwimi    r3,r7,0,24,31
	  add       r10, r10, r3
	  add       r10, r10, r0
	  addi      r11, r11, 0xC
	  addi      r9, r9, 0x1
	  bdnz+     .loc_0x100
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lis       r5, 0x3254
	  lis       r4, 0x803A
	  lwz       r12, 0x24(r12)
	  addi      r0, r5, 0x6532
	  subi      r4, r4, 0x2848
	  sub       r0, r0, r10
	  mtlr      r12
	  lwz       r4, 0x174(r4)
	  mr        r28, r0
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  mr        r4, r28
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  lwz       r28, 0x50(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80075090
 * Size:	000414
 */
void MemoryCard::makeDefaultFile()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  lis       r5, 0x802B
	  stwu      r1, -0x120(r1)
	  stmw      r14, 0xD8(r1)
	  subi      r17, r4, 0x2848
	  subi      r14, r5, 0x5FE0
	  addi      r31, r3, 0
	  addi      r16, r17, 0x174
	  addi      r30, r17, 0x170
	  li        r5, 0x6C
	  stb       r0, 0x68(r3)
	  lis       r3, 0x803A
	  subi      r15, r3, 0x1E20
	  stw       r0, 0x174(r17)
	  addi      r3, r15, 0
	  stw       r0, 0x170(r17)
	  li        r0, 0x1
	  lwz       r4, 0x2DEC(r13)
	  stw       r0, 0x270(r4)
	  li        r4, 0
	  bl        -0x71DCC
	  lwz       r5, 0x64(r31)
	  addis     r3, r15, 0x1
	  lwz       r4, 0x40(r31)
	  subi      r3, r3, 0x5F80
	  subi      r0, r5, 0x1
	  add       r0, r4, r0
	  divwu     r0, r0, r5
	  mullw     r0, r5, r0
	  stw       r0, 0x20(r15)
	  li        r4, 0
	  lwz       r5, 0x20(r15)
	  bl        -0x71DFC
	  bl        0x188280
	  addi      r5, r1, 0xAC
	  bl        0x188498
	  addi      r3, r1, 0x88
	  crclr     6, 0x6
	  addi      r5, r14, 0x1C
	  subi      r4, r13, 0x6534
	  bl        0x1A145C
	  lwz       r5, 0xBC(r1)
	  addi      r3, r1, 0x64
	  lwz       r6, 0xB8(r1)
	  addi      r4, r14, 0x1B30
	  lwz       r7, 0xB4(r1)
	  lwz       r8, 0xB0(r1)
	  addi      r5, r5, 0x1
	  crclr     6, 0x6
	  bl        0x1A1438
	  addi      r3, r15, 0
	  addi      r4, r1, 0x88
	  li        r5, 0x20
	  bl        0x1A41A4
	  addi      r3, r31, 0
	  addi      r4, r15, 0
	  addi      r5, r1, 0x64
	  bl        -0x6B0
	  lis       r4, 0x8022
	  lis       r3, 0x802A
	  addi      r28, r17, 0x24
	  addi      r18, r17, 0x94
	  addis     r22, r15, 0x1
	  addi      r21, r4, 0x74C8
	  addi      r20, r3, 0x755C
	  li        r19, 0
	  li        r17, 0x2000

	.loc_0x118:
	  li        r3, 0x14
	  bl        -0x2E1A8
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x164
	  addi      r3, r28, 0
	  addi      r4, r19, 0
	  bl        -0x18FC
	  add       r24, r22, r3
	  addi      r3, r23, 0
	  subi      r24, r24, 0x5F80
	  bl        .loc_0x414
	  stw       r21, 0x4(r23)
	  li        r3, 0
	  li        r0, 0x2000
	  stw       r20, 0x4(r23)
	  stw       r24, 0x8(r23)
	  stw       r3, 0xC(r23)
	  stw       r0, 0x10(r23)

	.loc_0x164:
	  addi      r3, r18, 0
	  addi      r4, r23, 0
	  bl        -0x20E10
	  addi      r26, r23, 0
	  addi      r3, r26, 0
	  lwz       r12, 0x4(r26)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  subfic    r25, r3, 0x1FF8
	  li        r24, 0
	  b         .loc_0x1B0

	.loc_0x194:
	  mr        r3, r26
	  lwz       r12, 0x4(r26)
	  li        r4, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r24, r24, 0x1

	.loc_0x1B0:
	  cmpw      r24, r25
	  blt+      .loc_0x194
	  add       r4, r22, r17
	  addi      r3, r31, 0
	  subi      r4, r4, 0x5F80
	  li        r5, 0x1FF8
	  bl        -0x1978
	  lwz       r12, 0x4(r23)
	  mr        r24, r3
	  lwz       r4, 0x0(r16)
	  mr        r3, r23
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r23
	  lwz       r12, 0x4(r23)
	  mr        r4, r24
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r16)
	  addi      r19, r19, 0x1
	  cmpwi     r19, 0x2
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r16)
	  addi      r17, r17, 0x2000
	  blt+      .loc_0x118
	  lis       r8, 0x8022
	  lis       r7, 0x802A
	  lis       r6, 0x1
	  lis       r5, 0x8022
	  lis       r4, 0x8022
	  lis       r3, 0x802A
	  addis     r21, r15, 0x1
	  addi      r22, r8, 0x74C8
	  addi      r23, r7, 0x755C
	  subi      r24, r6, 0x8000
	  addi      r25, r5, 0x738C
	  addi      r26, r4, 0x737C
	  addi      r16, r3, 0x696C
	  li        r27, 0
	  li        r29, 0x6000

	.loc_0x258:
	  li        r3, 0x14
	  bl        -0x2E2E8
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x2A0
	  addi      r3, r28, 0
	  addi      r4, r27, 0
	  bl        -0x1A30
	  add       r17, r21, r3
	  addi      r3, r20, 0
	  subi      r17, r17, 0x5F80
	  bl        .loc_0x414
	  stw       r22, 0x4(r20)
	  li        r0, 0
	  stw       r23, 0x4(r20)
	  stw       r17, 0x8(r20)
	  stw       r0, 0xC(r20)
	  stw       r24, 0x10(r20)

	.loc_0x2A0:
	  stw       r25, 0x38(r1)
	  li        r17, 0
	  addi      r3, r1, 0x38
	  stw       r26, 0x38(r1)
	  addi      r4, r14, 0x1B24
	  stw       r17, 0x48(r1)
	  stw       r17, 0x44(r1)
	  stw       r17, 0x40(r1)
	  bl        -0x5047C
	  stw       r16, 0x38(r1)
	  li        r3, 0x1
	  li        r0, -0x1
	  stb       r17, 0x5B(r1)
	  cmpwi     r27, 0x3
	  stb       r3, 0x58(r1)
	  stb       r3, 0x58(r1)
	  stw       r0, 0x54(r1)
	  stw       r0, 0x50(r1)
	  stw       r0, 0x4C(r1)
	  stb       r3, 0x59(r1)
	  stb       r17, 0x5A(r1)
	  stw       r3, 0x5C(r1)
	  stb       r27, 0x5B(r1)
	  bne-      .loc_0x304
	  stb       r17, 0x5B(r1)

	.loc_0x304:
	  addi      r3, r31, 0
	  addi      r4, r20, 0
	  addi      r5, r1, 0x38
	  bl        -0xA68
	  addi      r17, r20, 0
	  addi      r3, r17, 0
	  lwz       r12, 0x4(r17)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  sub       r3, r24, r3
	  subi      r18, r3, 0x8
	  li        r19, 0
	  b         .loc_0x358

	.loc_0x33C:
	  mr        r3, r17
	  lwz       r12, 0x4(r17)
	  li        r4, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r19, r19, 0x1

	.loc_0x358:
	  cmpw      r19, r18
	  blt+      .loc_0x33C
	  add       r4, r21, r29
	  addi      r3, r31, 0
	  subi      r4, r4, 0x5F80
	  li        r5, 0x7FF8
	  bl        -0x1B20
	  lwz       r12, 0x4(r20)
	  mr        r17, r3
	  lwz       r4, 0x0(r30)
	  mr        r3, r20
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r20
	  lwz       r12, 0x4(r20)
	  mr        r4, r17
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r30)
	  addi      r27, r27, 0x1
	  addis     r29, r29, 0x1
	  addi      r0, r3, 0x1
	  cmpwi     r27, 0x4
	  stw       r0, 0x0(r30)
	  subi      r29, r29, 0x8000
	  blt+      .loc_0x258
	  li        r3, 0
	  addi      r4, r15, 0x80
	  bl        -0x27CEC
	  bl        -0x27C6C
	  addis     r5, r15, 0x1
	  addi      r4, r15, 0
	  li        r3, 0
	  subi      r5, r5, 0x5F80
	  bl        -0x27BD8
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  stw       r0, 0x270(r3)
	  stw       r0, 0x44(r31)
	  lwz       r3, 0x44(r31)
	  lwz       r0, 0x124(r1)
	  lmw       r14, 0xD8(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr

	.loc_0x414:
	*/
}

/*
 * --INFO--
 * Address:	800754A4
 * Size:	000010
 */
Stream::Stream()
{
	/*
	.loc_0x0:
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  stw       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800754B4
 * Size:	000314
 */
void MemoryCard::copyFile(CardQuickInfo&, CardQuickInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x803A
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0xB0(r1)
	  stmw      r24, 0x90(r1)
	  li        r29, 0
	  addi      r26, r5, 0
	  subi      r28, r6, 0x1E20
	  lis       r5, 0x803A
	  addi      r25, r3, 0
	  addis     r30, r28, 0x1
	  lis       r31, 0x1
	  stb       r29, 0x68(r3)
	  subi      r3, r5, 0x2848
	  addi      r27, r3, 0xB5
	  lwz       r5, 0x2DEC(r13)
	  stw       r0, 0x270(r5)
	  subi      r5, r31, 0x8000
	  lbz       r3, 0xB5(r3)
	  lwz       r4, 0x0(r4)
	  subi      r0, r3, 0x1
	  rlwinm    r3,r0,15,0,16
	  rlwinm    r0,r4,15,0,16
	  addi      r3, r3, 0x6000
	  add       r4, r0, r30
	  add       r3, r30, r3
	  subi      r3, r3, 0x5F80
	  addi      r4, r4, 0x80
	  bl        -0x72114
	  lbz       r4, 0x0(r27)
	  li        r3, 0x14
	  subi      r24, r4, 0x1
	  bl        -0x2E534
	  cmplwi    r3, 0
	  beq-      .loc_0xD0
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  lis       r4, 0x8022
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x74C8
	  lis       r4, 0x802A
	  stw       r0, 0x4(r3)
	  addi      r4, r4, 0x755C
	  rlwinm    r0,r24,15,0,16
	  stw       r4, 0x4(r3)
	  add       r4, r0, r30
	  addi      r0, r4, 0x80
	  stw       r0, 0x8(r3)
	  subi      r0, r31, 0x8000
	  stw       r29, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0xD0:
	  mr        r29, r3
	  lwz       r12, 0x4(r29)
	  li        r4, 0x2
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r0, 0x4(r26)
	  lwz       r12, 0x4(r29)
	  rlwinm    r4,r0,0,24,31
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  li        r4, 0x7FF8
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lbz       r3, 0x0(r27)
	  li        r0, 0x666
	  mtctr     r0
	  lis       r4, 0x3254
	  subi      r0, r3, 0x1
	  addis     r3, r28, 0x1
	  rlwinm    r0,r0,15,0,16
	  add       r12, r0, r3
	  addi      r24, r4, 0x6532
	  li        r11, 0
	  addi      r12, r12, 0x80

	.loc_0x148:
	  rlwinm    r10,r11,0,24,31
	  lwz       r0, 0x0(r12)
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  subi      r7, r10, 0x1
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  addi      r11, r11, 0x1
	  addi      r9, r10, 0x2
	  rlwinm    r10,r11,0,24,31
	  or        r3, r6, r4
	  rlwimi    r3,r9,0,24,31
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  addi      r9, r10, 0x2
	  rlwinm    r4,r5,16,8,15
	  add       r24, r24, r3
	  add       r24, r24, r0
	  lwz       r0, 0x4(r12)
	  addi      r11, r11, 0x1
	  subi      r7, r10, 0x1
	  rlwinm    r10,r11,0,24,31
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  rlwinm    r8,r9,0,24,31
	  or        r3, r6, r4
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  or        r3, r8, r3
	  addi      r9, r10, 0x2
	  add       r24, r24, r3
	  add       r24, r24, r0
	  lwz       r0, 0x8(r12)
	  subi      r7, r10, 0x1
	  addi      r11, r11, 0x1
	  rlwinm    r10,r11,0,24,31
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  rlwinm    r8,r9,0,24,31
	  or        r3, r6, r4
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  or        r3, r8, r3
	  add       r24, r24, r3
	  add       r24, r24, r0
	  lwz       r0, 0xC(r12)
	  subi      r7, r10, 0x1
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  addi      r11, r11, 0x1
	  addi      r9, r10, 0x2
	  rlwinm    r10,r11,0,24,31
	  or        r3, r6, r4
	  rlwimi    r3,r9,0,24,31
	  addi      r5, r10, 0x1
	  add       r24, r24, r3
	  rlwinm    r4,r5,16,8,15
	  rlwimi    r4,r11,24,0,7
	  add       r24, r24, r0
	  lwz       r0, 0x10(r12)
	  subi      r7, r10, 0x1
	  addi      r3, r4, 0
	  addi      r9, r10, 0x2
	  rlwimi    r3,r7,8,16,23
	  rlwimi    r3,r9,0,24,31
	  add       r24, r24, r3
	  add       r24, r24, r0
	  addi      r12, r12, 0x14
	  addi      r11, r11, 0x1
	  bdnz+     .loc_0x148
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lis       r5, 0x3254
	  lis       r4, 0x803A
	  lwz       r12, 0x24(r12)
	  addi      r0, r5, 0x6532
	  subi      r4, r4, 0x2848
	  sub       r0, r0, r24
	  mtlr      r12
	  lwz       r4, 0x170(r4)
	  mr        r24, r0
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r24
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lbz       r5, 0x0(r27)
	  addi      r4, r28, 0x80
	  li        r3, 0
	  subi      r24, r5, 0x1
	  bl        -0x28004
	  bl        -0x27F84
	  rlwinm    r3,r24,15,0,16
	  lwz       r4, 0x38(r25)
	  addi      r6, r3, 0x6000
	  addis     r0, r28, 0x1
	  add       r5, r0, r6
	  lis       r3, 0x1
	  subi      r7, r3, 0x8000
	  li        r3, 0
	  subi      r5, r5, 0x5F80
	  bl        -0x27ED0
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  stw       r0, 0x270(r3)
	  lwz       r0, 0xB4(r1)
	  lmw       r24, 0x90(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800757C8
 * Size:	000454
 */
void MemoryCard::delFile(CardQuickInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802B
	  stw       r0, 0x4(r1)
	  lis       r5, 0x8022
	  addi      r0, r5, 0x738C
	  stwu      r1, -0xC8(r1)
	  lis       r5, 0x802A
	  li        r8, 0x1
	  stmw      r26, 0xB0(r1)
	  li        r31, 0
	  addi      r28, r3, 0
	  subi      r6, r6, 0x44BC
	  addi      r5, r5, 0x696C
	  stb       r31, 0x68(r3)
	  lis       r3, 0x8022
	  lwz       r7, 0x2DEC(r13)
	  stw       r8, 0x270(r7)
	  lis       r7, 0x803A
	  subi      r30, r7, 0x1E20
	  stw       r0, 0x84(r1)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x803A
	  stw       r0, 0x84(r1)
	  subi      r3, r3, 0x2848
	  addi      r29, r3, 0xB5
	  stw       r31, 0x94(r1)
	  li        r0, -0x1
	  li        r3, 0x14
	  stw       r31, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  stw       r6, 0x88(r1)
	  stw       r5, 0x84(r1)
	  stb       r31, 0xA7(r1)
	  stb       r8, 0xA4(r1)
	  stb       r8, 0xA4(r1)
	  stw       r0, 0xA0(r1)
	  stw       r0, 0x9C(r1)
	  stw       r0, 0x98(r1)
	  stb       r8, 0xA5(r1)
	  stb       r31, 0xA6(r1)
	  stw       r8, 0xA8(r1)
	  lwz       r0, 0x4(r4)
	  stb       r0, 0xA7(r1)
	  lbz       r4, 0x0(r29)
	  subi      r27, r4, 0x1
	  bl        -0x2E878
	  cmplwi    r3, 0
	  beq-      .loc_0x108
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  lis       r4, 0x8022
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x74C8
	  lis       r4, 0x802A
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x755C
	  addis     r4, r30, 0x1
	  stw       r0, 0x4(r3)
	  rlwinm    r0,r27,15,0,16
	  add       r4, r0, r4
	  addi      r0, r4, 0x80
	  stw       r0, 0x8(r3)
	  lis       r4, 0x1
	  subi      r0, r4, 0x8000
	  stw       r31, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x108:
	  lwz       r4, 0x2F6C(r13)
	  addi      r31, r3, 0
	  cmplwi    r4, 0
	  beq-      .loc_0x1D4
	  lbz       r0, 0x184(r4)
	  addi      r6, r4, 0x184
	  rlwinm    r0,r0,0,30,30
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x158
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  lwz       r5, 0x14(r3)
	  lwz       r0, 0x10(r3)
	  lwz       r3, 0xC(r3)
	  add       r0, r0, r5
	  add       r0, r3, r0
	  b         .loc_0x15C

	.loc_0x158:
	  li        r0, -0x1

	.loc_0x15C:
	  stw       r0, 0x98(r1)
	  lbz       r0, 0x0(r6)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x18C
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  lwz       r5, 0x20(r3)
	  lwz       r0, 0x1C(r3)
	  lwz       r3, 0x18(r3)
	  add       r0, r0, r5
	  add       r0, r3, r0
	  b         .loc_0x190

	.loc_0x18C:
	  li        r0, -0x1

	.loc_0x190:
	  stw       r0, 0x9C(r1)
	  lbz       r0, 0x0(r6)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x1C0
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  lwz       r5, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  add       r0, r0, r5
	  add       r0, r3, r0
	  b         .loc_0x1C4

	.loc_0x1C0:
	  li        r0, -0x1

	.loc_0x1C4:
	  stw       r0, 0xA0(r1)
	  mr        r3, r4
	  bl        0xA28C
	  stb       r3, 0xA6(r1)

	.loc_0x1D4:
	  lwz       r12, 0x84(r1)
	  addi      r4, r31, 0
	  addi      r3, r1, 0x84
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0xA4(r1)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x20C
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x20C
	  mr        r4, r31
	  bl        0xA2DC

	.loc_0x20C:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lis       r4, 0x1
	  subi      r0, r4, 0x8000
	  sub       r3, r0, r3
	  subi      r26, r3, 0x8
	  li        r27, 0
	  b         .loc_0x254

	.loc_0x238:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  li        r4, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r27, r27, 0x1

	.loc_0x254:
	  cmpw      r27, r26
	  blt+      .loc_0x238
	  lbz       r3, 0x0(r29)
	  li        r0, 0x666
	  mtctr     r0
	  lis       r4, 0x3254
	  subi      r0, r3, 0x1
	  addis     r3, r30, 0x1
	  rlwinm    r0,r0,15,0,16
	  add       r12, r0, r3
	  addi      r26, r4, 0x6532
	  li        r11, 0
	  addi      r12, r12, 0x80

	.loc_0x288:
	  rlwinm    r10,r11,0,24,31
	  lwz       r0, 0x0(r12)
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  subi      r7, r10, 0x1
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  addi      r11, r11, 0x1
	  addi      r9, r10, 0x2
	  rlwinm    r10,r11,0,24,31
	  or        r3, r6, r4
	  rlwimi    r3,r9,0,24,31
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  addi      r9, r10, 0x2
	  rlwinm    r4,r5,16,8,15
	  add       r26, r26, r3
	  add       r26, r26, r0
	  lwz       r0, 0x4(r12)
	  addi      r11, r11, 0x1
	  subi      r7, r10, 0x1
	  rlwinm    r10,r11,0,24,31
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  rlwinm    r8,r9,0,24,31
	  or        r3, r6, r4
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  or        r3, r8, r3
	  addi      r9, r10, 0x2
	  add       r26, r26, r3
	  add       r26, r26, r0
	  lwz       r0, 0x8(r12)
	  subi      r7, r10, 0x1
	  addi      r11, r11, 0x1
	  rlwinm    r10,r11,0,24,31
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  rlwinm    r8,r9,0,24,31
	  or        r3, r6, r4
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  or        r3, r8, r3
	  add       r26, r26, r3
	  add       r26, r26, r0
	  lwz       r0, 0xC(r12)
	  subi      r7, r10, 0x1
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  addi      r11, r11, 0x1
	  addi      r9, r10, 0x2
	  rlwinm    r10,r11,0,24,31
	  or        r3, r6, r4
	  rlwimi    r3,r9,0,24,31
	  addi      r5, r10, 0x1
	  add       r26, r26, r3
	  rlwinm    r4,r5,16,8,15
	  rlwimi    r4,r11,24,0,7
	  add       r26, r26, r0
	  lwz       r0, 0x10(r12)
	  subi      r7, r10, 0x1
	  addi      r3, r4, 0
	  addi      r9, r10, 0x2
	  rlwimi    r3,r7,8,16,23
	  rlwimi    r3,r9,0,24,31
	  add       r26, r26, r3
	  add       r26, r26, r0
	  addi      r12, r12, 0x14
	  addi      r11, r11, 0x1
	  bdnz+     .loc_0x288
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lis       r5, 0x3254
	  lis       r4, 0x803A
	  lwz       r12, 0x24(r12)
	  addi      r0, r5, 0x6532
	  subi      r4, r4, 0x2848
	  sub       r0, r0, r26
	  mtlr      r12
	  lwz       r4, 0x170(r4)
	  mr        r26, r0
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  mr        r4, r26
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lbz       r5, 0x0(r29)
	  addi      r4, r30, 0x80
	  li        r3, 0
	  subi      r26, r5, 0x1
	  bl        -0x28458
	  bl        -0x283D8
	  rlwinm    r3,r26,15,0,16
	  lwz       r4, 0x38(r28)
	  addi      r6, r3, 0x6000
	  addis     r0, r30, 0x1
	  add       r5, r0, r6
	  lis       r3, 0x1
	  subi      r7, r3, 0x8000
	  li        r3, 0
	  subi      r5, r5, 0x5F80
	  bl        -0x28324
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  stw       r0, 0x270(r3)
	  lwz       r0, 0xCC(r1)
	  lmw       r26, 0xB0(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80075C1C
 * Size:	00006C
 */
void MemoryCard::doFormatCard()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  stb       r31, 0x68(r3)
	  lwz       r5, 0x2DEC(r13)
	  stw       r0, 0x270(r5)
	  bl        -0x2180
	  lwz       r4, 0x2DEC(r13)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stw       r31, 0x270(r4)
	  addi      r3, r3, 0x24
	  li        r4, 0
	  bl        -0x1D78
	  lwz       r3, 0x44(r30)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80075C88
 * Size:	000034
 */
void MemoryCard::isCardInserted()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x194E0C
	  neg       r3, r3
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r3,r0,0,24,31
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80075CBC
 * Size:	00022C
 */
void MemoryCard::hasCardChanged()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  subi      r31, r4, 0x2848
	  stw       r30, 0x58(r1)
	  addi      r30, r3, 0
	  lbz       r0, 0xB2(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  li        r3, 0
	  bl        0x194DB8
	  cmpwi     r3, 0
	  bne-      .loc_0x44

	.loc_0x3C:
	  li        r3, 0x1
	  b         .loc_0x214

	.loc_0x44:
	  addi      r3, r1, 0x38
	  addi      r4, r30, 0x14
	  bl        0x1A3650
	  addi      r3, r31, 0x24
	  li        r4, 0x1
	  bl        -0x1E24
	  cmpwi     r3, 0
	  bne-      .loc_0x70
	  lwz       r0, 0x5C(r31)
	  cmpwi     r0, 0
	  bge-      .loc_0x78

	.loc_0x70:
	  li        r3, 0x1
	  b         .loc_0x214

	.loc_0x78:
	  addi      r3, r1, 0x38
	  addi      r4, r30, 0x14
	  bl        0x1A3488
	  cmpwi     r3, 0
	  beq-      .loc_0x94
	  li        r3, 0x1
	  b         .loc_0x214

	.loc_0x94:
	  lbz       r4, 0xB4(r31)
	  li        r0, 0x666
	  lis       r3, 0x803B
	  mtctr     r0
	  subi      r4, r4, 0x1
	  subi      r0, r3, 0x7DA0
	  rlwinm    r4,r4,15,0,16
	  add       r31, r4, r0
	  lis       r3, 0x3254
	  addi      r12, r3, 0x6532
	  li        r11, 0
	  addi      r31, r31, 0x6000

	.loc_0xC4:
	  rlwinm    r10,r11,0,24,31
	  lwz       r0, 0x0(r31)
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  subi      r7, r10, 0x1
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  addi      r11, r11, 0x1
	  addi      r9, r10, 0x2
	  rlwinm    r10,r11,0,24,31
	  or        r3, r6, r4
	  rlwimi    r3,r9,0,24,31
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  addi      r9, r10, 0x2
	  rlwinm    r4,r5,16,8,15
	  add       r12, r12, r3
	  add       r12, r12, r0
	  lwz       r0, 0x4(r31)
	  addi      r11, r11, 0x1
	  subi      r7, r10, 0x1
	  rlwinm    r10,r11,0,24,31
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  rlwinm    r8,r9,0,24,31
	  or        r3, r6, r4
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  or        r3, r8, r3
	  addi      r9, r10, 0x2
	  add       r12, r12, r3
	  add       r12, r12, r0
	  lwz       r0, 0x8(r31)
	  subi      r7, r10, 0x1
	  addi      r11, r11, 0x1
	  rlwinm    r10,r11,0,24,31
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  rlwinm    r8,r9,0,24,31
	  or        r3, r6, r4
	  addi      r5, r10, 0x1
	  rlwinm    r6,r11,24,0,7
	  rlwinm    r4,r5,16,8,15
	  or        r3, r8, r3
	  add       r12, r12, r3
	  add       r12, r12, r0
	  lwz       r0, 0xC(r31)
	  subi      r7, r10, 0x1
	  or        r4, r6, r4
	  rlwinm    r6,r7,8,16,23
	  addi      r11, r11, 0x1
	  addi      r9, r10, 0x2
	  rlwinm    r10,r11,0,24,31
	  or        r3, r6, r4
	  rlwimi    r3,r9,0,24,31
	  addi      r5, r10, 0x1
	  add       r12, r12, r3
	  rlwinm    r4,r5,16,8,15
	  rlwimi    r4,r11,24,0,7
	  add       r12, r12, r0
	  lwz       r0, 0x10(r31)
	  subi      r7, r10, 0x1
	  addi      r3, r4, 0
	  addi      r9, r10, 0x2
	  rlwimi    r3,r7,8,16,23
	  rlwimi    r3,r9,0,24,31
	  add       r12, r12, r3
	  add       r12, r12, r0
	  addi      r31, r31, 0x14
	  addi      r11, r11, 0x1
	  bdnz+     .loc_0xC4
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lis       r4, 0x3254
	  lwz       r0, 0x1A0(r3)
	  addi      r3, r4, 0x6532
	  sub       r3, r3, r12
	  cmplw     r3, r0
	  beq-      .loc_0x210
	  li        r3, 0x1
	  b         .loc_0x214

	.loc_0x210:
	  li        r3, 0

	.loc_0x214:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80075EE8
 * Size:	000574
 */
void MemoryCard::getOkSections()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  li        r0, 0x7FF
	  mtctr     r0
	  li        r6, 0
	  stwu      r1, -0x130(r1)
	  stmw      r17, 0xF4(r1)
	  subi      r19, r4, 0x1E20
	  addis     r8, r19, 0x1
	  lis       r4, 0x3254
	  addi      r31, r3, 0
	  addi      r7, r4, 0x6532
	  li        r30, 0x7F
	  subi      r8, r8, 0x5F80

	.loc_0x3C:
	  rlwinm    r5,r6,0,24,31
	  lwz       r0, 0x0(r8)
	  addi      r3, r5, 0x1
	  subi      r4, r5, 0x1
	  rlwinm    r3,r3,16,8,15
	  rlwimi    r3,r6,24,0,7
	  addi      r5, r5, 0x2
	  rlwimi    r3,r4,8,16,23
	  rlwimi    r3,r5,0,24,31
	  add       r7, r7, r3
	  add       r7, r7, r0
	  addi      r8, r8, 0x4
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x3C
	  lis       r3, 0x3254
	  addi      r0, r3, 0x6532
	  sub       r18, r0, r7
	  li        r3, 0x14
	  bl        -0x2EF68
	  cmplwi    r3, 0
	  beq-      .loc_0xD0
	  lis       r4, 0x8022
	  addi      r0, r4, 0x7398
	  lis       r4, 0x8022
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x74C8
	  lis       r4, 0x802A
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x755C
	  addis     r4, r19, 0x1
	  stw       r0, 0x4(r3)
	  subi      r0, r4, 0x5F80
	  stw       r0, 0x8(r3)
	  li        r4, 0
	  li        r0, 0x2000
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0xD0:
	  mr        r20, r3
	  lwz       r12, 0x4(r20)
	  li        r4, 0x1FFC
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r20
	  lwz       r12, 0x4(r20)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplw     r3, r18
	  beq-      .loc_0x108
	  rlwinm    r30,r30,0,0,30

	.loc_0x108:
	  li        r0, 0
	  lis       r24, 0x3254
	  stw       r0, 0x60(r31)
	  lis       r5, 0x8022
	  lis       r4, 0x8022
	  lis       r3, 0x802A
	  addis     r25, r19, 0x1
	  addi      r26, r24, 0x6532
	  addi      r27, r5, 0x7398
	  addi      r28, r4, 0x74C8
	  addi      r20, r3, 0x755C
	  li        r29, 0x1
	  li        r21, 0
	  li        r23, 0x2000

	.loc_0x140:
	  add       r22, r25, r23
	  li        r0, 0x2AA
	  subi      r22, r22, 0x5F80
	  mtctr     r0
	  addi      r11, r22, 0
	  addi      r10, r24, 0x6532
	  li        r9, 0

	.loc_0x15C:
	  rlwinm    r8,r9,0,24,31
	  lwz       r0, 0x0(r11)
	  addi      r4, r8, 0x1
	  rlwinm    r5,r9,24,0,7
	  rlwinm    r3,r4,16,8,15
	  subi      r6, r8, 0x1
	  or        r3, r5, r3
	  rlwinm    r5,r6,8,16,23
	  addi      r9, r9, 0x1
	  addi      r7, r8, 0x2
	  rlwinm    r8,r9,0,24,31
	  or        r3, r5, r3
	  rlwimi    r3,r7,0,24,31
	  add       r10, r10, r3
	  addi      r4, r8, 0x1
	  rlwinm    r5,r9,24,0,7
	  rlwinm    r3,r4,16,8,15
	  add       r10, r10, r0
	  lwz       r0, 0x4(r11)
	  subi      r6, r8, 0x1
	  or        r3, r5, r3
	  rlwinm    r5,r6,8,16,23
	  addi      r7, r8, 0x2
	  addi      r9, r9, 0x1
	  rlwinm    r8,r9,0,24,31
	  or        r3, r5, r3
	  rlwimi    r3,r7,0,24,31
	  add       r10, r10, r3
	  addi      r4, r8, 0x1
	  rlwinm    r3,r4,16,8,15
	  rlwimi    r3,r9,24,0,7
	  subi      r6, r8, 0x1
	  add       r10, r10, r0
	  lwz       r0, 0x8(r11)
	  addi      r7, r8, 0x2
	  rlwimi    r3,r6,8,16,23
	  rlwimi    r3,r7,0,24,31
	  add       r10, r10, r3
	  add       r10, r10, r0
	  addi      r11, r11, 0xC
	  addi      r9, r9, 0x1
	  bdnz+     .loc_0x15C
	  sub       r18, r26, r10
	  li        r3, 0x14
	  bl        -0x2F0F0
	  cmplwi    r3, 0
	  beq-      .loc_0x238
	  stw       r27, 0x4(r3)
	  li        r4, 0
	  li        r0, 0x2000
	  stw       r28, 0x4(r3)
	  stw       r20, 0x4(r3)
	  stw       r22, 0x8(r3)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)

	.loc_0x238:
	  mr        r22, r3
	  lwz       r12, 0x4(r22)
	  li        r4, 0x1FF8
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r22
	  lwz       r12, 0x4(r22)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r22
	  lwz       r12, 0x4(r22)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplw     r3, r18
	  beq-      .loc_0x290
	  li        r0, 0x1
	  slw       r0, r0, r29
	  andc      r30, r30, r0
	  b         .loc_0x29C

	.loc_0x290:
	  lwz       r3, 0x60(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x60(r31)

	.loc_0x29C:
	  addi      r21, r21, 0x1
	  cmpwi     r21, 0x2
	  addi      r29, r29, 0x1
	  addi      r23, r23, 0x2000
	  blt+      .loc_0x140
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0xB8(r1)
	  addi      r0, r3, 0x737C
	  stw       r0, 0xB8(r1)
	  li        r28, 0
	  lis       r4, 0x802B
	  stw       r28, 0xC8(r1)
	  subi      r0, r4, 0x44BC
	  lis       r25, 0x3254
	  stw       r28, 0xC4(r1)
	  lis       r6, 0x8022
	  lis       r5, 0x8022
	  stw       r28, 0xC0(r1)
	  lis       r4, 0x802A
	  lis       r3, 0x802A
	  stw       r0, 0xBC(r1)
	  addi      r0, r3, 0x696C
	  lis       r3, 0x1
	  stw       r0, 0xB8(r1)
	  addis     r24, r19, 0x1
	  li        r0, 0x1
	  stb       r28, 0xDB(r1)
	  addi      r23, r25, 0x6532
	  addi      r22, r6, 0x7398
	  stb       r0, 0xD8(r1)
	  addi      r21, r5, 0x74C8
	  addi      r20, r4, 0x755C
	  stw       r28, 0x5C(r31)
	  subi      r19, r3, 0x8000
	  li        r26, 0x6000
	  stw       r28, 0x4C(r31)
	  stw       r28, 0x50(r31)
	  stw       r28, 0x54(r31)

	.loc_0x33C:
	  add       r27, r24, r26
	  li        r0, 0x666
	  subi      r27, r27, 0x5F80
	  mtctr     r0
	  addi      r3, r27, 0
	  addi      r18, r25, 0x6532
	  li        r12, 0

	.loc_0x358:
	  rlwinm    r11,r12,0,24,31
	  lwz       r0, 0x0(r3)
	  addi      r6, r11, 0x1
	  rlwinm    r7,r12,24,0,7
	  rlwinm    r5,r6,16,8,15
	  subi      r8, r11, 0x1
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  addi      r12, r12, 0x1
	  addi      r10, r11, 0x2
	  rlwinm    r11,r12,0,24,31
	  or        r4, r7, r5
	  rlwimi    r4,r10,0,24,31
	  addi      r6, r11, 0x1
	  rlwinm    r7,r12,24,0,7
	  addi      r10, r11, 0x2
	  rlwinm    r5,r6,16,8,15
	  add       r18, r18, r4
	  add       r18, r18, r0
	  lwz       r0, 0x4(r3)
	  addi      r12, r12, 0x1
	  subi      r8, r11, 0x1
	  rlwinm    r11,r12,0,24,31
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  rlwinm    r9,r10,0,24,31
	  or        r4, r7, r5
	  addi      r6, r11, 0x1
	  rlwinm    r7,r12,24,0,7
	  rlwinm    r5,r6,16,8,15
	  or        r4, r9, r4
	  addi      r10, r11, 0x2
	  add       r18, r18, r4
	  add       r18, r18, r0
	  lwz       r0, 0x8(r3)
	  subi      r8, r11, 0x1
	  addi      r12, r12, 0x1
	  rlwinm    r11,r12,0,24,31
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  rlwinm    r9,r10,0,24,31
	  or        r4, r7, r5
	  addi      r6, r11, 0x1
	  rlwinm    r7,r12,24,0,7
	  rlwinm    r5,r6,16,8,15
	  or        r4, r9, r4
	  add       r18, r18, r4
	  add       r18, r18, r0
	  lwz       r0, 0xC(r3)
	  subi      r8, r11, 0x1
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  addi      r12, r12, 0x1
	  addi      r10, r11, 0x2
	  rlwinm    r11,r12,0,24,31
	  or        r4, r7, r5
	  rlwimi    r4,r10,0,24,31
	  addi      r6, r11, 0x1
	  add       r18, r18, r4
	  rlwinm    r5,r6,16,8,15
	  rlwimi    r5,r12,24,0,7
	  add       r18, r18, r0
	  lwz       r0, 0x10(r3)
	  subi      r8, r11, 0x1
	  addi      r4, r5, 0
	  addi      r10, r11, 0x2
	  rlwimi    r4,r8,8,16,23
	  rlwimi    r4,r10,0,24,31
	  add       r18, r18, r4
	  add       r18, r18, r0
	  addi      r3, r3, 0x14
	  addi      r12, r12, 0x1
	  bdnz+     .loc_0x358
	  sub       r18, r23, r18
	  li        r3, 0x14
	  bl        -0x2F368
	  cmplwi    r3, 0
	  beq-      .loc_0x4AC
	  stw       r22, 0x4(r3)
	  li        r0, 0
	  stw       r21, 0x4(r3)
	  stw       r20, 0x4(r3)
	  stw       r27, 0x8(r3)
	  stw       r0, 0xC(r3)
	  stw       r19, 0x10(r3)

	.loc_0x4AC:
	  addi      r27, r3, 0
	  addi      r4, r27, 0
	  addi      r3, r1, 0xB8
	  bl        -0x21960
	  mr        r3, r27
	  lbz       r17, 0xDB(r1)
	  lwz       r12, 0x4(r27)
	  li        r4, 0x7FF8
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x4(r27)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x4(r27)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplw     r3, r18
	  beq-      .loc_0x518
	  li        r0, 0x1
	  slw       r0, r0, r29
	  andc      r30, r30, r0
	  b         .loc_0x544

	.loc_0x518:
	  rlwinm    r3,r17,2,0,29
	  addi      r3, r3, 0x4C
	  add       r3, r31, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x544
	  li        r0, 0x1
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x5C(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x5C(r31)

	.loc_0x544:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x4
	  addis     r26, r26, 0x1
	  addi      r29, r29, 0x1
	  subi      r26, r26, 0x8000
	  blt+      .loc_0x33C
	  mr        r3, r30
	  lmw       r17, 0xF4(r1)
	  lwz       r0, 0x134(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8007645C
 * Size:	0000A0
 */
void MemoryCard::isFileBroken()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  subi      r31, r4, 0x2848
	  li        r4, 0x1
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0x24
	  bl        -0x2594
	  cmpwi     r3, 0
	  bne-      .loc_0x84
	  lwz       r0, 0x5C(r31)
	  cmpwi     r0, 0
	  blt-      .loc_0x84
	  mr        r3, r30
	  bl        -0x5B8
	  stw       r3, 0x48(r30)
	  li        r3, 0
	  lwz       r0, 0x48(r30)
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x60
	  li        r3, 0x1

	.loc_0x60:
	  lwz       r0, 0x60(r30)
	  cmpwi     r0, 0x1
	  bge-      .loc_0x70
	  li        r3, 0x1

	.loc_0x70:
	  lwz       r0, 0x5C(r30)
	  cmpwi     r0, 0x3
	  bge-      .loc_0x88
	  li        r3, 0x1
	  b         .loc_0x88

	.loc_0x84:
	  li        r3, 0

	.loc_0x88:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void MemoryCard::breakFile()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800764FC
 * Size:	00052C
 */
void MemoryCard::repairFile()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x120(r1)
	  stmw      r14, 0xD8(r1)
	  addi      r31, r3, 0
	  stb       r0, 0x68(r3)
	  lis       r3, 0x803A
	  subi      r22, r3, 0x1E20
	  lwz       r0, 0x48(r31)
	  lis       r3, 0x802B
	  rlwinm.   r0,r0,0,31,31
	  subi      r0, r3, 0x5FE0
	  stw       r0, 0xCC(r1)
	  bne-      .loc_0xE8
	  bl        0x186E68
	  addi      r5, r1, 0xA4
	  bl        0x187080
	  lwz       r5, 0xB4(r1)
	  addi      r3, r1, 0x80
	  lwz       r4, 0xCC(r1)
	  crclr     6, 0x6
	  lwz       r6, 0xB0(r1)
	  lwz       r7, 0xAC(r1)
	  addi      r4, r4, 0x1B30
	  lwz       r8, 0xA8(r1)
	  addi      r5, r5, 0x1
	  bl        0x1A0030
	  addi      r3, r22, 0
	  li        r4, 0
	  li        r5, 0x6C
	  bl        -0x73258
	  lwz       r6, 0x64(r31)
	  mr        r3, r31
	  lwz       r5, 0x40(r31)
	  addi      r4, r22, 0
	  subi      r0, r6, 0x1
	  add       r0, r5, r0
	  divwu     r0, r0, r6
	  mullw     r0, r6, r0
	  stw       r0, 0x20(r22)
	  addi      r5, r1, 0x80
	  bl        -0x1AD4
	  li        r3, 0
	  addi      r4, r22, 0x80
	  bl        -0x28E3C
	  bl        -0x28DBC
	  addis     r5, r22, 0x1
	  lwz       r4, 0x38(r31)
	  li        r3, 0
	  li        r6, 0
	  li        r7, 0x2000
	  subi      r5, r5, 0x5F80
	  bl        -0x28CFC

	.loc_0xD8:
	  mr        r3, r31
	  bl        -0x2B7C
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0xD8

	.loc_0xE8:
	  lwz       r0, 0x60(r31)
	  cmpwi     r0, 0x1
	  bge-      .loc_0x27C
	  lis       r3, 0x803A
	  subi      r5, r3, 0x2848
	  lis       r4, 0x8022
	  lis       r3, 0x802A
	  subfic    r21, r0, 0x1
	  addi      r19, r5, 0x24
	  addi      r20, r5, 0x94
	  addis     r24, r22, 0x1
	  addi      r23, r5, 0x174
	  addi      r18, r4, 0x74C8
	  addi      r17, r3, 0x755C
	  li        r26, 0
	  li        r27, 0x2000

	.loc_0x128:
	  addi      r0, r26, 0x1
	  lwz       r4, 0x48(r31)
	  li        r3, 0x1
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  bne-      .loc_0x26C
	  li        r28, 0
	  stw       r28, 0x0(r23)
	  li        r3, 0x14
	  bl        -0x2F644
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x190
	  addi      r3, r19, 0
	  addi      r4, r26, 0
	  bl        -0x2D98
	  add       r25, r24, r3
	  addi      r3, r30, 0
	  subi      r25, r25, 0x5F80
	  bl        -0x11CC
	  stw       r18, 0x4(r30)
	  li        r0, 0x2000
	  stw       r17, 0x4(r30)
	  stw       r25, 0x8(r30)
	  stw       r28, 0xC(r30)
	  stw       r0, 0x10(r30)

	.loc_0x190:
	  addi      r3, r20, 0
	  addi      r4, r30, 0
	  bl        -0x222A8
	  lwz       r12, 0x4(r30)
	  mr        r3, r30
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  subfic    r28, r3, 0x1FF8
	  li        r29, 0
	  b         .loc_0x1D8

	.loc_0x1BC:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  li        r4, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x1

	.loc_0x1D8:
	  cmpw      r29, r28
	  blt+      .loc_0x1BC
	  add       r4, r24, r27
	  addi      r3, r31, 0
	  subi      r4, r4, 0x5F80
	  li        r5, 0x1FF8
	  bl        -0x2E0C
	  lwz       r12, 0x4(r30)
	  mr        r25, r3
	  lwz       r4, 0x0(r23)
	  mr        r3, r30
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r25
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  addi      r4, r22, 0x80
	  bl        -0x28FB8
	  bl        -0x28F38
	  add       r5, r24, r27
	  lwz       r4, 0x38(r31)
	  addi      r6, r27, 0
	  li        r3, 0
	  li        r7, 0x2000
	  subi      r5, r5, 0x5F80
	  bl        -0x28E78

	.loc_0x254:
	  mr        r3, r31
	  bl        -0x2CF8
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x254
	  subic.    r21, r21, 0x1
	  beq-      .loc_0x27C

	.loc_0x26C:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x2
	  addi      r27, r27, 0x2000
	  blt+      .loc_0x128

	.loc_0x27C:
	  lwz       r0, 0x5C(r31)
	  cmpwi     r0, 0x3
	  bge-      .loc_0x518
	  lis       r7, 0x8022
	  subfic    r19, r0, 0x3
	  addi      r0, r7, 0x737C
	  lis       r3, 0x803A
	  stw       r0, 0xD0(r1)
	  subi      r5, r3, 0x2848
	  lis       r8, 0x802A
	  addi      r0, r8, 0x696C
	  lis       r4, 0x8022
	  stw       r0, 0xD4(r1)
	  lis       r3, 0x802A
	  lis       r17, 0x1
	  lis       r6, 0x8022
	  addi      r18, r5, 0x24
	  addis     r23, r22, 0x1
	  addi      r21, r5, 0x170
	  addi      r16, r4, 0x74C8
	  addi      r15, r3, 0x755C
	  subi      r20, r17, 0x8000
	  addi      r14, r6, 0x738C
	  li        r25, 0
	  li        r26, 0x6000

	.loc_0x2E0:
	  addi      r0, r25, 0x3
	  lwz       r4, 0x48(r31)
	  li        r3, 0x1
	  slw       r0, r3, r0
	  and.      r0, r4, r0
	  bne-      .loc_0x504
	  li        r0, 0x3
	  mtctr     r0
	  addi      r3, r31, 0
	  li        r28, 0

	.loc_0x308:
	  lwz       r0, 0x4C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x4F0
	  li        r24, 0
	  stw       r24, 0x0(r21)
	  li        r3, 0x14
	  bl        -0x2F818
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x360
	  addi      r3, r18, 0
	  addi      r4, r25, 0
	  bl        -0x2F60
	  add       r27, r23, r3
	  addi      r3, r30, 0
	  subi      r27, r27, 0x5F80
	  bl        -0x13A0
	  stw       r16, 0x4(r30)
	  stw       r15, 0x4(r30)
	  stw       r27, 0x8(r30)
	  stw       r24, 0xC(r30)
	  stw       r20, 0x10(r30)

	.loc_0x360:
	  stw       r14, 0x54(r1)
	  li        r27, 0
	  lwz       r0, 0xD0(r1)
	  addi      r3, r1, 0x54
	  lwz       r4, 0xCC(r1)
	  stw       r0, 0x54(r1)
	  addi      r4, r4, 0x1B24
	  stw       r27, 0x64(r1)
	  stw       r27, 0x60(r1)
	  stw       r27, 0x5C(r1)
	  bl        -0x519B0
	  lwz       r0, 0xD4(r1)
	  li        r3, 0x1
	  cmpwi     r28, 0x3
	  stw       r0, 0x54(r1)
	  li        r0, -0x1
	  stb       r27, 0x77(r1)
	  stb       r3, 0x74(r1)
	  stb       r3, 0x74(r1)
	  stw       r0, 0x70(r1)
	  stw       r0, 0x6C(r1)
	  stw       r0, 0x68(r1)
	  stb       r3, 0x75(r1)
	  stb       r27, 0x76(r1)
	  stw       r3, 0x78(r1)
	  stb       r28, 0x77(r1)
	  bne-      .loc_0x3D0
	  stb       r27, 0x77(r1)

	.loc_0x3D0:
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  addi      r5, r1, 0x54
	  bl        -0x1FA0
	  lwz       r12, 0x4(r30)
	  mr        r3, r30
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  sub       r3, r20, r3
	  subi      r27, r3, 0x8
	  li        r29, 0
	  b         .loc_0x420

	.loc_0x404:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  li        r4, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r29, r29, 0x1

	.loc_0x420:
	  cmpw      r29, r27
	  blt+      .loc_0x404
	  add       r4, r23, r26
	  addi      r3, r31, 0
	  subi      r4, r4, 0x5F80
	  li        r5, 0x7FF8
	  bl        -0x3054
	  lwz       r12, 0x4(r30)
	  mr        r24, r3
	  lwz       r4, 0x0(r21)
	  mr        r3, r30
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r4, r24
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  addi      r4, r22, 0x80
	  bl        -0x29200
	  bl        -0x29180
	  add       r5, r23, r26
	  lwz       r4, 0x38(r31)
	  addi      r6, r26, 0
	  subi      r7, r17, 0x8000
	  li        r3, 0
	  subi      r5, r5, 0x5F80
	  bl        -0x290C0
	  li        r30, 0x1

	.loc_0x4A0:
	  bl        -0x291C0
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm    r29,r0,27,5,31
	  rlwinm.   r0,r0,27,24,31
	  beq-      .loc_0x4D4
	  li        r3, 0
	  bl        -0x29210
	  bl        -0x291C4
	  bl        -0x2925C
	  cmpwi     r3, -0x1
	  bge-      .loc_0x4D4
	  stb       r30, 0x68(r31)

	.loc_0x4D4:
	  rlwinm.   r0,r29,0,24,31
	  beq+      .loc_0x4A0
	  rlwinm    r3,r28,2,0,29
	  addi      r0, r3, 0x4C
	  li        r3, 0x1
	  stwx      r3, r31, r0
	  b         .loc_0x4FC

	.loc_0x4F0:
	  addi      r3, r3, 0x4
	  addi      r28, r28, 0x1
	  bdnz+     .loc_0x308

	.loc_0x4FC:
	  subic.    r19, r19, 0x1
	  beq-      .loc_0x518

	.loc_0x504:
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x4
	  addis     r26, r26, 0x1
	  subi      r26, r26, 0x8000
	  blt+      .loc_0x2E0

	.loc_0x518:
	  lmw       r14, 0xD8(r1)
	  lwz       r0, 0x124(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80076A28
 * Size:	000040
 */
void MemoryCard::didSaveFail()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  lbz       r31, 0x68(r3)
	  li        r3, 0
	  bl        0x194064
	  cmpwi     r3, 0
	  bne-      .loc_0x28
	  li        r31, 0x1

	.loc_0x28:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80076A68
 * Size:	000398
 */
void MemoryCard::getQuickInfos(CardQuickInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stwu      r1, -0xE8(r1)
	  li        r10, 0
	  lis       r5, 0x802B
	  stmw      r17, 0xAC(r1)
	  lis       r8, 0x8022
	  lis       r7, 0x8022
	  lis       r6, 0x802A
	  lis       r20, 0x3254
	  lis       r9, 0x803B
	  addi      r30, r4, 0
	  addi      r25, r8, 0x7398
	  addi      r26, r7, 0x74C8
	  addi      r27, r6, 0x755C
	  subi      r18, r9, 0x7DA0
	  addi      r17, r20, 0x6532
	  li        r21, -0x1
	  li        r31, 0
	  li        r24, 0x6000
	  stw       r0, 0x80(r1)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802A
	  stw       r0, 0x80(r1)
	  subi      r0, r5, 0x44BC
	  lis       r5, 0x1
	  stw       r10, 0x90(r1)
	  subi      r28, r5, 0x8000
	  stw       r10, 0x8C(r1)
	  stw       r10, 0x88(r1)
	  stw       r0, 0x84(r1)
	  addi      r0, r3, 0x696C
	  lis       r3, 0x803A
	  stw       r0, 0x80(r1)
	  li        r0, 0x1
	  subi      r29, r3, 0x2848
	  stb       r10, 0xA3(r1)
	  stb       r0, 0xA0(r1)
	  li        r0, -0x1
	  stw       r0, 0x20(r4)
	  stw       r0, 0x0(r4)
	  stw       r0, 0x48(r4)
	  stw       r0, 0x28(r4)
	  stw       r0, 0x70(r4)
	  stw       r0, 0x50(r4)
	  stw       r0, 0x98(r4)
	  stw       r0, 0x78(r4)

	.loc_0xC8:
	  li        r0, 0x666
	  add       r23, r18, r24
	  mtctr     r0
	  addi      r3, r23, 0
	  addi      r19, r20, 0x6532
	  li        r12, 0

	.loc_0xE0:
	  rlwinm    r11,r12,0,24,31
	  lwz       r0, 0x0(r3)
	  addi      r6, r11, 0x1
	  rlwinm    r7,r12,24,0,7
	  rlwinm    r5,r6,16,8,15
	  subi      r8, r11, 0x1
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  addi      r12, r12, 0x1
	  addi      r10, r11, 0x2
	  rlwinm    r11,r12,0,24,31
	  or        r4, r7, r5
	  rlwimi    r4,r10,0,24,31
	  addi      r6, r11, 0x1
	  rlwinm    r7,r12,24,0,7
	  addi      r10, r11, 0x2
	  rlwinm    r5,r6,16,8,15
	  add       r19, r19, r4
	  add       r19, r19, r0
	  lwz       r0, 0x4(r3)
	  addi      r12, r12, 0x1
	  subi      r8, r11, 0x1
	  rlwinm    r11,r12,0,24,31
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  rlwinm    r9,r10,0,24,31
	  or        r4, r7, r5
	  addi      r6, r11, 0x1
	  rlwinm    r7,r12,24,0,7
	  rlwinm    r5,r6,16,8,15
	  or        r4, r9, r4
	  addi      r10, r11, 0x2
	  add       r19, r19, r4
	  add       r19, r19, r0
	  lwz       r0, 0x8(r3)
	  subi      r8, r11, 0x1
	  addi      r12, r12, 0x1
	  rlwinm    r11,r12,0,24,31
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  rlwinm    r9,r10,0,24,31
	  or        r4, r7, r5
	  addi      r6, r11, 0x1
	  rlwinm    r7,r12,24,0,7
	  rlwinm    r5,r6,16,8,15
	  or        r4, r9, r4
	  add       r19, r19, r4
	  add       r19, r19, r0
	  lwz       r0, 0xC(r3)
	  subi      r8, r11, 0x1
	  or        r5, r7, r5
	  rlwinm    r7,r8,8,16,23
	  addi      r12, r12, 0x1
	  addi      r10, r11, 0x2
	  rlwinm    r11,r12,0,24,31
	  or        r4, r7, r5
	  rlwimi    r4,r10,0,24,31
	  addi      r6, r11, 0x1
	  add       r19, r19, r4
	  rlwinm    r5,r6,16,8,15
	  rlwimi    r5,r12,24,0,7
	  add       r19, r19, r0
	  lwz       r0, 0x10(r3)
	  subi      r8, r11, 0x1
	  addi      r4, r5, 0
	  addi      r10, r11, 0x2
	  rlwimi    r4,r8,8,16,23
	  rlwimi    r4,r10,0,24,31
	  add       r19, r19, r4
	  add       r19, r19, r0
	  addi      r3, r3, 0x14
	  addi      r12, r12, 0x1
	  bdnz+     .loc_0xE0
	  sub       r22, r17, r19
	  li        r3, 0x14
	  bl        -0x2FC70
	  cmplwi    r3, 0
	  beq-      .loc_0x234
	  stw       r25, 0x4(r3)
	  li        r0, 0
	  stw       r26, 0x4(r3)
	  stw       r27, 0x4(r3)
	  stw       r23, 0x8(r3)
	  stw       r0, 0xC(r3)
	  stw       r28, 0x10(r3)

	.loc_0x234:
	  mr        r19, r3
	  lwz       r12, 0x4(r19)
	  li        r4, 0x7FF8
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r19
	  lwz       r12, 0x4(r19)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r19, 0
	  lwz       r12, 0x4(r19)
	  mr        r19, r0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplw     r3, r22
	  beq-      .loc_0x290
	  addi      r0, r31, 0x1
	  stb       r0, 0xB5(r29)
	  b         .loc_0x360

	.loc_0x290:
	  cmpw      r19, r21
	  ble-      .loc_0x29C
	  mr        r21, r19

	.loc_0x29C:
	  li        r3, 0x14
	  bl        -0x2FD04
	  cmplwi    r3, 0
	  beq-      .loc_0x2C8
	  stw       r25, 0x4(r3)
	  li        r0, 0
	  stw       r26, 0x4(r3)
	  stw       r27, 0x4(r3)
	  stw       r23, 0x8(r3)
	  stw       r0, 0xC(r3)
	  stw       r28, 0x10(r3)

	.loc_0x2C8:
	  addi      r4, r3, 0
	  addi      r3, r1, 0x80
	  bl        -0x222F8
	  lbz       r4, 0xA3(r1)
	  mulli     r0, r4, 0x28
	  add       r3, r30, r0
	  lwz       r0, 0x20(r3)
	  cmpw      r19, r0
	  ble-      .loc_0x358
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  beq-      .loc_0x300
	  addi      r0, r3, 0x1
	  stb       r0, 0xB5(r29)

	.loc_0x300:
	  lbz       r0, 0xA0(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x360
	  mulli     r0, r4, 0x28
	  add       r3, r30, r0
	  stw       r22, 0x24(r3)
	  stw       r19, 0x20(r3)
	  stw       r31, 0x0(r3)
	  stw       r4, 0x4(r3)
	  lbz       r0, 0xA0(r1)
	  stw       r0, 0x8(r3)
	  lbz       r0, 0xA1(r1)
	  stw       r0, 0xC(r3)
	  lbz       r0, 0xA2(r1)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0x94(r1)
	  stw       r0, 0x14(r3)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x18(r3)
	  lwz       r0, 0x9C(r1)
	  stw       r0, 0x1C(r3)
	  b         .loc_0x360

	.loc_0x358:
	  addi      r0, r31, 0x1
	  stb       r0, 0xB5(r29)

	.loc_0x360:
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x4
	  addis     r24, r24, 0x1
	  subi      r24, r24, 0x8000
	  blt+      .loc_0xC8
	  lis       r3, 0x803A
	  addi      r0, r21, 0x1
	  subi      r3, r3, 0x2848
	  stw       r0, 0x170(r3)
	  lwz       r0, 0xEC(r1)
	  lmw       r17, 0xAC(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80076E00
 * Size:	000034
 */
void MemoryCard::init()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  subi      r3, r3, 0x1DA0
	  addi      r3, r3, 0x2000
	  stwu      r1, -0x8(r1)
	  li        r4, 0x2000
	  li        r5, 0xE
	  bl        -0x292B4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
