#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80086690
 * Size:	000080
 */
MemStat::MemStat()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x738C
	  subi      r4, r13, 0x5E90
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x8022
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  addi      r3, r31, 0
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  stw       r0, 0x10(r31)
	  stw       r0, 0xC(r31)
	  stw       r0, 0x8(r31)
	  bl        -0x61800
	  lis       r3, 0x802B
	  subi      r0, r3, 0x103C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x104C
	  stw       r0, 0x0(r31)
	  mr        r3, r31
	  bl        .loc_0x80
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x80:
	*/
}

/*
 * --INFO--
 * Address:	80086710
 * Size:	000028
 */
void MemStat::reset()
{
	/*
	.loc_0x0:
	  li        r5, 0
	  stw       r5, 0x10(r3)
	  lis       r4, 0x802B
	  subi      r0, r4, 0x10AC
	  stw       r5, 0xC(r3)
	  stw       r5, 0x8(r3)
	  stw       r0, 0x4(r3)
	  stw       r3, 0x18(r3)
	  stw       r5, 0x9C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80086738
 * Size:	000110
 */
void MemStat::start(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  lwz       r0, 0x2FE8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xF4
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        0x188
	  mr.       r30, r3
	  bne-      .loc_0xBC
	  li        r3, 0x18
	  bl        -0x3F778
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x9C
	  lis       r4, 0x8022
	  addi      r0, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r4, 0x737C
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  subi      r4, r13, 0x5E90
	  stw       r0, 0x10(r30)
	  stw       r0, 0xC(r30)
	  stw       r0, 0x8(r30)
	  bl        -0x618E4
	  lis       r3, 0x802B
	  subi      r0, r3, 0x103C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x104C
	  stw       r0, 0x0(r30)

	.loc_0x9C:
	  stw       r29, 0x4(r30)
	  li        r0, 0
	  mr        r4, r30
	  lwz       r3, 0x18(r31)
	  stw       r3, 0x8(r30)
	  stw       r0, 0x14(r30)
	  lwz       r3, 0x18(r31)
	  bl        -0x46218

	.loc_0xBC:
	  cmplwi    r30, 0
	  beq-      .loc_0xF4
	  lwz       r0, 0x9C(r31)
	  lwz       r4, 0x18(r31)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r31, r0
	  stw       r4, 0x1C(r3)
	  lwz       r3, 0x9C(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x9C(r31)
	  stw       r30, 0x18(r31)
	  lwz       r0, 0x18(r31)
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x19C(r3)

	.loc_0xF4:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80086848
 * Size:	000078
 */
void MemStat::end(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x2FE8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  mr        r3, r30
	  bl        0x84
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  lwz       r3, 0x9C(r30)
	  subi      r0, r3, 0x1
	  stw       r0, 0x9C(r30)
	  lwz       r5, 0x9C(r30)
	  rlwinm    r0,r5,2,0,29
	  add       r3, r30, r0
	  lwz       r0, 0x1C(r3)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x18(r30)
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x19C(r3)

	.loc_0x60:
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
 * Size:	000034
 */
void MemStat::getMemorySize(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void MemStat::getRestMemory()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800868C0
 * Size:	000034
 */
void MemStat::print()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x2FE8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x24
	  lwz       r4, 0x10(r3)
	  li        r5, 0x4
	  bl        0x38

	.loc_0x24:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800868F4
 * Size:	000024
 */
void MemStat::getInfo(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x24C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80086918
 * Size:	000238
 */
void MemStat::printInfoRec(MemInfo*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x338(r1)
	  stw       r31, 0x334(r1)
	  mr.       r31, r5
	  stw       r30, 0x330(r1)
	  addi      r30, r4, 0
	  li        r4, 0
	  stw       r29, 0x32C(r1)
	  addi      r29, r3, 0
	  stw       r28, 0x328(r1)
	  ble-      .loc_0x6C
	  cmpwi     r31, 0x8
	  subi      r3, r31, 0x8
	  ble-      .loc_0x58
	  addi      r0, r3, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r3, 0
	  mtctr     r0
	  ble-      .loc_0x58

	.loc_0x50:
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x50

	.loc_0x58:
	  sub       r0, r31, r4
	  cmpw      r4, r31
	  mtctr     r0
	  bge-      .loc_0x6C

	.loc_0x68:
	  bdnz-     .loc_0x68

	.loc_0x6C:
	  lwz       r3, 0x14(r30)
	  lis       r0, 0x10
	  cmpw      r3, r0
	  blt-      .loc_0x90
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x324(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x320(r1)
	  b         .loc_0xA0

	.loc_0x90:
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x324(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x320(r1)

	.loc_0xA0:
	  lwz       r28, 0x10(r30)
	  cmplwi    r28, 0
	  beq-      .loc_0x160
	  addic.    r0, r31, 0x4
	  li        r4, 0
	  ble-      .loc_0xFC
	  addi      r0, r31, 0x4
	  cmpwi     r0, 0x8
	  subi      r3, r31, 0x4
	  ble-      .loc_0xE4
	  addi      r0, r3, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r3, 0
	  mtctr     r0
	  ble-      .loc_0xE4

	.loc_0xDC:
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0xDC

	.loc_0xE4:
	  addi      r3, r31, 0x4
	  sub       r0, r3, r4
	  cmpw      r4, r3
	  mtctr     r0
	  bge-      .loc_0xFC

	.loc_0xF8:
	  bdnz-     .loc_0xF8

	.loc_0xFC:
	  lwz       r3, 0x14(r28)
	  lis       r0, 0x10
	  cmpw      r3, r0
	  blt-      .loc_0x120
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x324(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x320(r1)
	  b         .loc_0x130

	.loc_0x120:
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x324(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x320(r1)

	.loc_0x130:
	  lwz       r4, 0x10(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0x148
	  addi      r3, r29, 0
	  addi      r5, r31, 0x8
	  bl        .loc_0x0

	.loc_0x148:
	  lwz       r4, 0xC(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0x160
	  addi      r3, r29, 0
	  addi      r5, r31, 0x4
	  bl        .loc_0x0

	.loc_0x160:
	  lwz       r28, 0xC(r30)
	  cmplwi    r28, 0
	  beq-      .loc_0x218
	  cmpwi     r31, 0
	  li        r3, 0
	  ble-      .loc_0x1B4
	  cmpwi     r31, 0x8
	  subi      r4, r31, 0x8
	  ble-      .loc_0x1A0
	  addi      r0, r4, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r4, 0
	  mtctr     r0
	  ble-      .loc_0x1A0

	.loc_0x198:
	  addi      r3, r3, 0x8
	  bdnz+     .loc_0x198

	.loc_0x1A0:
	  sub       r0, r31, r3
	  cmpw      r3, r31
	  mtctr     r0
	  bge-      .loc_0x1B4

	.loc_0x1B0:
	  bdnz-     .loc_0x1B0

	.loc_0x1B4:
	  lwz       r3, 0x14(r28)
	  lis       r0, 0x10
	  cmpw      r3, r0
	  blt-      .loc_0x1D8
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x324(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x320(r1)
	  b         .loc_0x1E8

	.loc_0x1D8:
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x324(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x320(r1)

	.loc_0x1E8:
	  lwz       r4, 0x10(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0x200
	  addi      r3, r29, 0
	  addi      r5, r31, 0x4
	  bl        .loc_0x0

	.loc_0x200:
	  lwz       r4, 0xC(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0x218
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  bl        .loc_0x0

	.loc_0x218:
	  lwz       r0, 0x33C(r1)
	  lwz       r31, 0x334(r1)
	  lwz       r30, 0x330(r1)
	  lwz       r29, 0x32C(r1)
	  lwz       r28, 0x328(r1)
	  addi      r1, r1, 0x338
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80086B50
 * Size:	000174
 */
void MemStat::getInfoRec(char*, MemInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x24(r1)
	  mr        r29, r4
	  stw       r28, 0x20(r1)
	  addi      r28, r3, 0
	  lwz       r3, 0x4(r5)
	  bl        0x192648
	  cmpwi     r3, 0
	  bne-      .loc_0x40
	  mr        r3, r30
	  b         .loc_0x154

	.loc_0x40:
	  lwz       r31, 0xC(r30)
	  cmplwi    r31, 0
	  beq-      .loc_0xC8
	  lwz       r3, 0x4(r31)
	  mr        r4, r29
	  bl        0x192620
	  cmpwi     r3, 0
	  bne-      .loc_0x64
	  b         .loc_0xB8

	.loc_0x64:
	  lwz       r5, 0xC(r31)
	  cmplwi    r5, 0
	  beq-      .loc_0x8C
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        .loc_0x0
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  mr        r31, r3
	  b         .loc_0xB8

	.loc_0x8C:
	  lwz       r5, 0x10(r31)
	  cmplwi    r5, 0
	  beq-      .loc_0xB4
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        .loc_0x0
	  cmplwi    r3, 0
	  beq-      .loc_0xB4
	  mr        r31, r3
	  b         .loc_0xB8

	.loc_0xB4:
	  li        r31, 0

	.loc_0xB8:
	  cmplwi    r31, 0
	  beq-      .loc_0xC8
	  mr        r3, r31
	  b         .loc_0x154

	.loc_0xC8:
	  lwz       r31, 0x10(r30)
	  cmplwi    r31, 0
	  beq-      .loc_0x150
	  lwz       r3, 0x4(r31)
	  mr        r4, r29
	  bl        0x192598
	  cmpwi     r3, 0
	  bne-      .loc_0xEC
	  b         .loc_0x140

	.loc_0xEC:
	  lwz       r5, 0xC(r31)
	  cmplwi    r5, 0
	  beq-      .loc_0x114
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        .loc_0x0
	  cmplwi    r3, 0
	  beq-      .loc_0x114
	  mr        r31, r3
	  b         .loc_0x140

	.loc_0x114:
	  lwz       r5, 0x10(r31)
	  cmplwi    r5, 0
	  beq-      .loc_0x13C
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        .loc_0x0
	  cmplwi    r3, 0
	  beq-      .loc_0x13C
	  mr        r31, r3
	  b         .loc_0x140

	.loc_0x13C:
	  li        r31, 0

	.loc_0x140:
	  cmplwi    r31, 0
	  beq-      .loc_0x150
	  mr        r3, r31
	  b         .loc_0x154

	.loc_0x150:
	  li        r3, 0

	.loc_0x154:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
