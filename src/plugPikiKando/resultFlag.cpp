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
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008358C
 * Size:	0001BC
 */
ResultFlags::ResultFlags()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x26
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  sth       r0, 0x0(r3)
	  li        r0, 0x94
	  rlwinm    r3,r0,2,0,29
	  lhz       r0, 0x0(r31)
	  rlwinm    r0,r0,2,16,29
	  sth       r0, 0x4(r31)
	  bl        -0x3C5C0
	  stw       r3, 0x48(r31)
	  li        r30, 0
	  sth       r30, 0x2(r31)
	  lhz       r3, 0x0(r31)
	  bl        -0x3C5D4
	  stw       r3, 0x8(r31)
	  li        r4, 0
	  b         .loc_0x68

	.loc_0x5C:
	  lwz       r3, 0x8(r31)
	  stbx      r30, r3, r4
	  addi      r4, r4, 0x1

	.loc_0x68:
	  lhz       r0, 0x0(r31)
	  cmpw      r4, r0
	  blt+      .loc_0x5C
	  lis       r3, 0x802B
	  subi      r30, r3, 0x1E04
	  li        r29, 0
	  b         .loc_0xC8

	.loc_0x84:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xD4
	  lwz       r3, 0x48(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  lbz       r0, 0x4(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xB4
	  mr        r3, r31
	  lwz       r4, 0x0(r30)
	  bl        0x3C4

	.loc_0xB4:
	  lhz       r3, 0x2(r31)
	  addi      r30, r30, 0x10
	  addi      r29, r29, 0x1
	  addi      r0, r3, 0x1
	  sth       r0, 0x2(r31)

	.loc_0xC8:
	  lhz       r0, 0x4(r31)
	  cmpw      r29, r0
	  blt+      .loc_0x84

	.loc_0xD4:
	  li        r3, -0x1
	  sth       r3, 0xC(r31)
	  li        r5, 0x18
	  sth       r3, 0xE(r31)
	  sth       r3, 0x10(r31)
	  sth       r3, 0x12(r31)
	  sth       r3, 0x14(r31)
	  sth       r3, 0x16(r31)
	  sth       r3, 0x18(r31)
	  sth       r3, 0x1A(r31)
	  sth       r3, 0x1C(r31)
	  sth       r3, 0x1E(r31)
	  sth       r3, 0x20(r31)
	  sth       r3, 0x22(r31)
	  sth       r3, 0x24(r31)
	  sth       r3, 0x26(r31)
	  sth       r3, 0x28(r31)
	  sth       r3, 0x2A(r31)
	  sth       r3, 0x2C(r31)
	  sth       r3, 0x2E(r31)
	  sth       r3, 0x30(r31)
	  sth       r3, 0x32(r31)
	  sth       r3, 0x34(r31)
	  sth       r3, 0x36(r31)
	  sth       r3, 0x38(r31)
	  sth       r3, 0x3A(r31)
	  b         .loc_0x194

	.loc_0x140:
	  subfic    r0, r5, 0x1E
	  cmpwi     r5, 0x1E
	  mtctr     r0
	  bge-      .loc_0x15C

	.loc_0x150:
	  sth       r3, 0xC(r4)
	  addi      r4, r4, 0x2
	  bdnz+     .loc_0x150

	.loc_0x15C:
	  addi      r3, r31, 0
	  li        r4, 0x1B
	  bl        0x360
	  addi      r3, r31, 0
	  li        r4, 0x1D
	  bl        0x354
	  addi      r3, r31, 0
	  li        r4, 0x1F
	  bl        0x348
	  addi      r3, r31, 0
	  li        r4, 0x26
	  bl        0x33C
	  mr        r3, r31
	  b         .loc_0x1A0

	.loc_0x194:
	  rlwinm    r0,r5,1,0,30
	  add       r4, r31, r0
	  b         .loc_0x140

	.loc_0x1A0:
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
 * Address:	80083748
 * Size:	000178
 */
void ResultFlags::initGame()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  b         .loc_0x34

	.loc_0x28:
	  lwz       r3, 0x8(r31)
	  stbx      r4, r3, r5
	  addi      r5, r5, 0x1

	.loc_0x34:
	  lhz       r0, 0x0(r31)
	  cmpw      r5, r0
	  blt+      .loc_0x28
	  lis       r3, 0x802B
	  subi      r30, r3, 0x1E04
	  li        r29, 0
	  b         .loc_0x88

	.loc_0x50:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x94
	  lwz       r3, 0x48(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  lbz       r0, 0x4(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  mr        r3, r31
	  lwz       r4, 0x0(r30)
	  bl        0x23C

	.loc_0x80:
	  addi      r30, r30, 0x10
	  addi      r29, r29, 0x1

	.loc_0x88:
	  lhz       r0, 0x4(r31)
	  cmpw      r29, r0
	  blt+      .loc_0x50

	.loc_0x94:
	  li        r3, -0x1
	  sth       r3, 0xC(r31)
	  li        r5, 0x18
	  sth       r3, 0xE(r31)
	  sth       r3, 0x10(r31)
	  sth       r3, 0x12(r31)
	  sth       r3, 0x14(r31)
	  sth       r3, 0x16(r31)
	  sth       r3, 0x18(r31)
	  sth       r3, 0x1A(r31)
	  sth       r3, 0x1C(r31)
	  sth       r3, 0x1E(r31)
	  sth       r3, 0x20(r31)
	  sth       r3, 0x22(r31)
	  sth       r3, 0x24(r31)
	  sth       r3, 0x26(r31)
	  sth       r3, 0x28(r31)
	  sth       r3, 0x2A(r31)
	  sth       r3, 0x2C(r31)
	  sth       r3, 0x2E(r31)
	  sth       r3, 0x30(r31)
	  sth       r3, 0x32(r31)
	  sth       r3, 0x34(r31)
	  sth       r3, 0x36(r31)
	  sth       r3, 0x38(r31)
	  sth       r3, 0x3A(r31)
	  b         .loc_0x150

	.loc_0x100:
	  subfic    r0, r5, 0x1E
	  cmpwi     r5, 0x1E
	  mtctr     r0
	  bge-      .loc_0x11C

	.loc_0x110:
	  sth       r3, 0xC(r4)
	  addi      r4, r4, 0x2
	  bdnz+     .loc_0x110

	.loc_0x11C:
	  addi      r3, r31, 0
	  li        r4, 0x1B
	  bl        0x1E4
	  addi      r3, r31, 0
	  li        r4, 0x1D
	  bl        0x1D8
	  addi      r3, r31, 0
	  li        r4, 0x1F
	  bl        0x1CC
	  addi      r3, r31, 0
	  li        r4, 0x26
	  bl        0x1C0
	  b         .loc_0x15C

	.loc_0x150:
	  rlwinm    r0,r5,1,0,30
	  add       r4, r31, r0
	  b         .loc_0x100

	.loc_0x15C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800838C0
 * Size:	0000A4
 */
void ResultFlags::saveCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  b         .loc_0x48

	.loc_0x28:
	  mr        r3, r29
	  lwz       r4, 0x8(r31)
	  lwz       r12, 0x4(r29)
	  lbzx      r4, r4, r30
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r30, 0x1

	.loc_0x48:
	  lhz       r0, 0x0(r31)
	  cmpw      r30, r0
	  blt+      .loc_0x28
	  li        r30, 0
	  rlwinm    r0,r30,1,0,30
	  add       r31, r31, r0

	.loc_0x60:
	  mr        r3, r29
	  lha       r4, 0xC(r31)
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x1E
	  addi      r31, r31, 0x2
	  blt+      .loc_0x60
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80083964
 * Size:	00009C
 */
void ResultFlags::loadCard(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  b         .loc_0x48

	.loc_0x28:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x8(r31)
	  stbx      r3, r4, r30
	  addi      r30, r30, 0x1

	.loc_0x48:
	  lhz       r0, 0x0(r31)
	  cmpw      r30, r0
	  blt+      .loc_0x28
	  li        r30, 0

	.loc_0x58:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  addi      r30, r30, 0x1
	  sth       r3, 0xC(r31)
	  cmpwi     r30, 0x1E
	  addi      r31, r31, 0x2
	  blt+      .loc_0x58
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80083A00
 * Size:	000050
 */
void ResultFlags::setOn(int)
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
	  bl        0x384
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x38
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  li        r5, 0x1
	  bl        0x39C

	.loc_0x38:
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
 * Address:	80083A50
 * Size:	000024
 */
void ResultFlags::setSeen(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x370
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80083A74
 * Size:	0000A0
 */
void ResultFlags::getDayDocument(int, int&)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r4,1,0,30
	  add       r4, r3, r0
	  lha       r7, 0xC(r4)
	  lis       r4, 0x802B
	  subi      r4, r4, 0x1E20
	  cmpwi     r7, -0x1
	  bne-      .loc_0x2C
	  li        r0, 0
	  stw       r0, 0x0(r5)
	  li        r3, -0x1
	  blr

	.loc_0x2C:
	  lhz       r0, 0x2(r3)
	  addi      r6, r4, 0x1C
	  li        r8, 0
	  cmpwi     r0, 0
	  mtctr     r0
	  ble-      .loc_0x90

	.loc_0x44:
	  lwz       r0, 0x0(r6)
	  cmpw      r0, r7
	  mr        r3, r0
	  bne-      .loc_0x84
	  rlwinm    r0,r8,4,0,27
	  add       r4, r4, r0
	  lwz       r6, 0x2C(r4)
	  cmpwi     r6, -0x1
	  bne-      .loc_0x74
	  li        r0, 0x1
	  stw       r0, 0x0(r5)
	  blr

	.loc_0x74:
	  lwz       r0, 0x1C(r4)
	  sub       r0, r6, r0
	  stw       r0, 0x0(r5)
	  blr

	.loc_0x84:
	  addi      r6, r6, 0x10
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x44

	.loc_0x90:
	  li        r0, 0
	  stw       r0, 0x0(r5)
	  li        r3, -0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80083B14
 * Size:	000180
 */
void ResultFlags::getDocument(int&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r24, 0x18(r1)
	  subi      r28, r5, 0x1E20
	  addi      r31, r28, 0x1C
	  lis       r5, 0x2
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  addi      r27, r31, 0
	  subi      r26, r5, 0xC00
	  li        r25, -0x1
	  li        r24, 0
	  b         .loc_0x70

	.loc_0x3C:
	  lwz       r4, 0x0(r27)
	  mr        r3, r29
	  bl        0x248
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x68
	  lwz       r0, 0x8(r27)
	  cmpw      r26, r0
	  ble-      .loc_0x68
	  mr        r26, r0
	  addi      r25, r24, 0

	.loc_0x68:
	  addi      r27, r27, 0x10
	  addi      r24, r24, 0x1

	.loc_0x70:
	  lhz       r0, 0x2(r29)
	  cmpw      r24, r0
	  blt+      .loc_0x3C
	  cmpwi     r25, -0x1
	  beq-      .loc_0x160
	  rlwinm    r4,r25,4,0,27
	  add       r3, r28, r4
	  lwz       r5, 0x2C(r3)
	  cmpwi     r5, -0x1
	  bne-      .loc_0xA4
	  li        r0, 0x1
	  stw       r0, 0x0(r30)
	  b         .loc_0xB0

	.loc_0xA4:
	  lwz       r0, 0x1C(r3)
	  sub       r0, r5, r0
	  stw       r0, 0x0(r30)

	.loc_0xB0:
	  add       r27, r28, r4
	  lwzu      r4, 0x1C(r27)
	  addi      r3, r29, 0
	  li        r5, 0x2
	  bl        0x1FC
	  li        r24, 0
	  b         .loc_0x130

	.loc_0xCC:
	  lwz       r25, 0x0(r31)
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  bl        0x1B4
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x1
	  bne-      .loc_0x128
	  lwz       r0, 0xC(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x118
	  bge-      .loc_0x128
	  cmpwi     r0, 0
	  bge-      .loc_0x104
	  b         .loc_0x128

	.loc_0x104:
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  li        r5, 0x2
	  bl        0x1AC
	  b         .loc_0x128

	.loc_0x118:
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  li        r5, 0
	  bl        0x198

	.loc_0x128:
	  addi      r31, r31, 0x10
	  addi      r24, r24, 0x1

	.loc_0x130:
	  lhz       r0, 0x2(r29)
	  cmpw      r24, r0
	  blt+      .loc_0xCC
	  lwz       r0, 0x0(r27)
	  lwz       r3, 0x2F6C(r13)
	  extsh     r30, r0
	  bl        -0x30AC
	  rlwinm    r0,r3,1,0,30
	  add       r3, r29, r0
	  sth       r30, 0xC(r3)
	  lwz       r3, 0x0(r27)
	  b         .loc_0x16C

	.loc_0x160:
	  mr        r3, r29
	  bl        .loc_0x180
	  li        r3, -0x1

	.loc_0x16C:
	  lmw       r24, 0x18(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr

	.loc_0x180:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void ResultFlags::FlagInfo::type()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80083C94
 * Size:	00010C
 */
void ResultFlags::dump()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r26, 0x28(r1)
	  subi      r30, r4, 0x1E04
	  lis       r4, 0x8022
	  addi      r26, r3, 0
	  addi      r31, r4, 0x23D0
	  li        r29, 0
	  li        r28, 0
	  li        r27, 0
	  b         .loc_0xEC

	.loc_0x34:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xF8
	  lwz       r3, 0x8(r30)
	  cmpwi     r3, 0xC8
	  bge-      .loc_0x54
	  li        r0, 0
	  b         .loc_0x78

	.loc_0x54:
	  cmpwi     r3, 0x190
	  bge-      .loc_0x64
	  li        r0, 0xC8
	  b         .loc_0x78

	.loc_0x64:
	  cmpwi     r3, 0x258
	  bge-      .loc_0x74
	  li        r0, 0x190
	  b         .loc_0x78

	.loc_0x74:
	  li        r0, 0x258

	.loc_0x78:
	  cmpw      r29, r0
	  beq-      .loc_0x84
	  li        r28, 0

	.loc_0x84:
	  cmpwi     r3, 0xC8
	  bge-      .loc_0x94
	  li        r0, 0
	  b         .loc_0xB8

	.loc_0x94:
	  cmpwi     r3, 0x190
	  bge-      .loc_0xA4
	  li        r0, 0xC8
	  b         .loc_0xB8

	.loc_0xA4:
	  cmpwi     r3, 0x258
	  bge-      .loc_0xB4
	  li        r0, 0x190
	  b         .loc_0xB8

	.loc_0xB4:
	  li        r0, 0x258

	.loc_0xB8:
	  mr        r29, r0
	  lwz       r4, 0x0(r31)
	  lwz       r0, 0x4(r31)
	  mr        r3, r26
	  addi      r28, r28, 0x1
	  stw       r4, 0x18(r1)
	  stw       r0, 0x1C(r1)
	  lwz       r0, 0x8(r31)
	  stw       r0, 0x20(r1)
	  lwz       r4, 0x0(r30)
	  bl        .loc_0x10C
	  addi      r30, r30, 0x10
	  addi      r27, r27, 0x1

	.loc_0xEC:
	  lhz       r0, 0x4(r26)
	  cmpw      r27, r0
	  blt+      .loc_0x34

	.loc_0xF8:
	  lmw       r26, 0x28(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr

	.loc_0x10C:
	*/
}

/*
 * --INFO--
 * Address:	80083DA0
 * Size:	000030
 */
void ResultFlags::getFlag(int)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x48(r3)
	  rlwinm    r0,r4,2,0,29
	  lwz       r3, 0x8(r3)
	  lwzx      r4, r5, r0
	  srawi     r5, r4, 0x2
	  rlwinm    r0,r5,2,0,29
	  lbzx      r3, r3, r5
	  sub       r0, r4, r0
	  rlwinm    r0,r0,1,0,30
	  sraw      r0, r3, r0
	  rlwinm    r3,r0,0,30,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80083DD0
 * Size:	000090
 */
void ResultFlags::setFlag(int, u8)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x48(r3)
	  rlwinm    r0,r4,2,0,29
	  lwz       r3, 0x8(r3)
	  rlwinm    r4,r5,0,24,31
	  lwzx      r6, r6, r0
	  rlwinm.   r0,r5,0,31,31
	  srawi     r7, r6, 0x2
	  add       r5, r3, r7
	  rlwinm    r3,r7,2,0,29
	  lbz       r7, 0x0(r5)
	  sub       r6, r6, r3
	  beq-      .loc_0x44
	  rlwinm    r0,r6,1,0,30
	  li        r3, 0x1
	  slw       r0, r3, r0
	  or        r7, r7, r0
	  b         .loc_0x54

	.loc_0x44:
	  rlwinm    r0,r6,1,0,30
	  li        r3, 0x1
	  slw       r0, r3, r0
	  andc      r7, r7, r0

	.loc_0x54:
	  rlwinm.   r0,r4,0,30,30
	  beq-      .loc_0x74
	  rlwinm    r3,r6,1,0,30
	  addi      r0, r3, 0x1
	  li        r3, 0x1
	  slw       r0, r3, r0
	  or        r7, r7, r0
	  b         .loc_0x88

	.loc_0x74:
	  rlwinm    r3,r6,1,0,30
	  addi      r0, r3, 0x1
	  li        r3, 0x1
	  slw       r0, r3, r0
	  andc      r7, r7, r0

	.loc_0x88:
	  stb       r7, 0x0(r5)
	  blr
	*/
}
