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
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014A58C
 * Size:	00000C
 */
void TekiMgr::initTekiMgr()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x3160(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void TekiMgr::getTypeIndex(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014A598
 * Size:	000300
 */
TekiMgr::TekiMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stmw      r22, 0xA8(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        -0x69564
	  lis       r3, 0x802D
	  lwz       r22, 0x8(r1)
	  subi      r3, r3, 0x2368
	  stw       r3, 0x0(r22)
	  addi      r0, r3, 0x18
	  subi      r4, r13, 0x7D0
	  stw       r0, 0x8(r22)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0xC3E9C
	  bl        -0x2BCA0
	  addi      r31, r3, 0
	  li        r3, 0x24
	  bl        -0x1035E0
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x64
	  mr        r4, r22
	  bl        -0x67B0

	.loc_0x64:
	  lwz       r22, 0x8(r1)
	  stw       r23, 0x48(r22)
	  bl        -0x2A9B0
	  stw       r3, 0x40(r22)
	  li        r3, 0x8
	  bl        -0x10360C
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x90
	  li        r4, 0x23
	  bl        0x2C40

	.loc_0x90:
	  lwz       r22, 0x8(r1)
	  li        r3, 0x8C
	  stw       r23, 0x3C(r22)
	  bl        -0x103630
	  li        r0, 0x4
	  stw       r3, 0x44(r22)
	  mtctr     r0
	  li        r5, 0
	  li        r4, 0

	.loc_0xB4:
	  lwz       r3, 0x8(r1)
	  addi      r6, r4, 0x4C
	  li        r0, 0
	  stwx      r0, r3, r6
	  addi      r11, r4, 0xD8
	  addi      r10, r4, 0x50
	  lwz       r6, 0x44(r3)
	  addi      r9, r4, 0x4
	  addi      r8, r4, 0xDC
	  stwx      r0, r6, r4
	  addi      r7, r4, 0x54
	  addi      r6, r4, 0x8
	  stwx      r0, r3, r11
	  addi      r22, r4, 0xE0
	  addi      r23, r4, 0x58
	  stwx      r0, r3, r10
	  addi      r24, r4, 0xC
	  addi      r25, r4, 0xE4
	  lwz       r10, 0x44(r3)
	  addi      r26, r4, 0x5C
	  addi      r27, r4, 0x10
	  stwx      r0, r10, r9
	  addi      r30, r4, 0xE8
	  addi      r29, r4, 0x60
	  stwx      r0, r3, r8
	  addi      r28, r4, 0x14
	  addi      r12, r4, 0xEC
	  stwx      r0, r3, r7
	  addi      r11, r4, 0x64
	  addi      r10, r4, 0x18
	  lwz       r7, 0x44(r3)
	  addi      r9, r4, 0xF0
	  addi      r8, r4, 0x68
	  stwx      r0, r7, r6
	  addi      r7, r4, 0x1C
	  addi      r6, r4, 0xF4
	  stwx      r0, r3, r22
	  addi      r4, r4, 0x20
	  addi      r5, r5, 0x8
	  stwx      r0, r3, r23
	  lwz       r23, 0x44(r3)
	  stwx      r0, r23, r24
	  stwx      r0, r3, r25
	  stwx      r0, r3, r26
	  lwz       r26, 0x44(r3)
	  stwx      r0, r26, r27
	  stwx      r0, r3, r30
	  stwx      r0, r3, r29
	  lwz       r29, 0x44(r3)
	  stwx      r0, r29, r28
	  stwx      r0, r3, r12
	  stwx      r0, r3, r11
	  lwz       r11, 0x44(r3)
	  stwx      r0, r11, r10
	  stwx      r0, r3, r9
	  stwx      r0, r3, r8
	  lwz       r8, 0x44(r3)
	  stwx      r0, r8, r7
	  stwx      r0, r3, r6
	  bdnz+     .loc_0xB4
	  b         .loc_0x2E4

	.loc_0x1A8:
	  subfic    r3, r5, 0x23
	  cmpwi     r5, 0x23
	  mtctr     r3
	  bge-      .loc_0x1DC

	.loc_0x1B8:
	  lwz       r5, 0x8(r1)
	  addi      r4, r6, 0x4C
	  addi      r3, r6, 0xD8
	  stwx      r0, r5, r4
	  lwz       r4, 0x44(r5)
	  stwx      r0, r4, r6
	  addi      r6, r6, 0x4
	  stwx      r0, r5, r3
	  bdnz+     .loc_0x1B8

	.loc_0x1DC:
	  lwz       r3, 0x8(r1)
	  bl        0x9AC
	  lwz       r3, 0x8(r1)
	  bl        0x58978
	  li        r24, 0
	  lis       r4, 0x802D
	  lis       r3, 0x802D
	  rlwinm    r5,r24,2,0,29
	  subi      r0, r4, 0x25B8
	  add       r23, r0, r5
	  addi      r22, r24, 0
	  subi      r29, r3, 0x24A0

	.loc_0x20C:
	  lwz       r28, 0x8(r1)
	  addi      r30, r22, 0x4C
	  lwzx      r0, r28, r30
	  cmplwi    r0, 0
	  beq-      .loc_0x248
	  lwz       r5, 0x0(r23)
	  addi      r4, r29, 0
	  addi      r3, r1, 0x14
	  crclr     6, 0x6
	  bl        0xCBDD0
	  lwzx      r3, r28, r30
	  addi      r5, r1, 0x14
	  subi      r4, r13, 0x6CC
	  li        r6, 0x1
	  bl        -0x10A13C

	.loc_0x248:
	  addi      r24, r24, 0x1
	  cmpwi     r24, 0x23
	  addi      r22, r22, 0x4
	  addi      r23, r23, 0x4
	  blt+      .loc_0x20C
	  lwz       r3, 0x8(r1)
	  li        r4, 0
	  bl        0x67C
	  lwz       r3, 0x8(r1)
	  li        r4, 0x1
	  bl        0x718
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x7D0
	  bl        -0xC3FCC
	  bl        -0x2BEE0
	  mr        r29, r3
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x6C8
	  bl        -0xC40F0
	  bl        -0x2BEF4
	  mr        r30, r3
	  lwz       r3, 0x8(r1)
	  li        r4, 0x50
	  bl        -0x6974C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r13, 0x6C8
	  bl        -0xC4000
	  bl        -0x2BF14
	  sub       r0, r30, r3
	  sub       r3, r31, r29
	  xoris     r4, r3, 0x8000
	  lwz       r3, 0x8(r1)
	  xoris     r0, r0, 0x8000
	  stw       r4, 0xA4(r1)
	  lis       r4, 0x4330
	  stw       r0, 0x9C(r1)
	  stw       r4, 0xA0(r1)
	  stw       r4, 0x98(r1)
	  b         .loc_0x2EC

	.loc_0x2E4:
	  rlwinm    r6,r5,2,0,29
	  b         .loc_0x1A8

	.loc_0x2EC:
	  lmw       r22, 0xA8(r1)
	  lwz       r0, 0xD4(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A898
 * Size:	0001F0
 */
void TekiMgr::startStage()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x170(r1)
	  stfd      f31, 0x168(r1)
	  stfd      f30, 0x160(r1)
	  stmw      r20, 0x130(r1)
	  addi      r24, r3, 0
	  subi      r29, r4, 0x25E8
	  bl        0xAAC
	  mr        r3, r24
	  bl        0x589B4
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r29, 0x158
	  bl        -0xC4198
	  bl        -0x2BF9C
	  li        r25, 0
	  rlwinm    r0,r25,2,0,29
	  add       r28, r29, r0
	  lis       r3, 0x803A
	  addi      r27, r24, 0
	  subi      r31, r3, 0x2848
	  li        r26, 0
	  lis       r23, 0x4330
	  addi      r28, r28, 0x30

	.loc_0x64:
	  addi      r0, r25, 0x164
	  lbzx      r0, r24, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x1A4
	  addi      r3, r24, 0
	  addi      r4, r25, 0
	  bl        0x6C0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1A4
	  lwz       r3, 0x2FE8(r13)
	  lwz       r4, 0x0(r28)
	  bl        -0xC41F0
	  lwz       r5, 0x0(r28)
	  addi      r3, r1, 0x14
	  addi      r4, r29, 0x164
	  crclr     6, 0x6
	  bl        0xCBC5C
	  bl        -0x2C008
	  lwz       r5, 0x0(r28)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x94
	  crclr     6, 0x6
	  addi      r6, r5, 0
	  addi      r4, r29, 0x174
	  bl        0xCBC3C
	  li        r3, 0x18
	  bl        -0x103960
	  mr.       r20, r3
	  beq-      .loc_0xF4
	  addi      r3, r31, 0
	  addi      r4, r1, 0x94
	  li        r5, 0x1
	  bl        -0xF7C6C
	  addi      r4, r3, 0
	  addi      r3, r20, 0
	  bl        -0x681C

	.loc_0xF4:
	  stw       r20, 0xD8(r27)
	  bl        -0x2C058
	  lwz       r5, 0x0(r28)
	  addi      r20, r3, 0
	  addi      r3, r1, 0x14
	  crclr     6, 0x6
	  addi      r4, r29, 0x184
	  bl        0xCBBF0
	  bl        -0x2C074
	  lwz       r5, 0x0(r28)
	  addi      r21, r3, 0
	  addi      r3, r1, 0x94
	  crclr     6, 0x6
	  addi      r4, r29, 0x198
	  bl        0xCBBD4
	  lwz       r3, 0xD8(r27)
	  addi      r4, r1, 0x94
	  li        r5, 0
	  lwz       r3, 0x14(r3)
	  bl        -0xF9ED4
	  lwz       r3, 0xD8(r27)
	  lwz       r3, 0x14(r3)
	  bl        -0xF9C6C
	  lwz       r3, 0x2FE8(r13)
	  lwz       r4, 0x0(r28)
	  bl        -0xC41A8
	  bl        -0x2C0BC
	  lwz       r4, 0xD8(r27)
	  addi      r22, r3, 0
	  addi      r3, r24, 0x8
	  lwz       r4, 0x14(r4)
	  bl        -0x10A430
	  sub       r4, r30, r22
	  sub       r3, r30, r20
	  sub       r0, r21, r22
	  xoris     r4, r4, 0x8000
	  xoris     r3, r3, 0x8000
	  stw       r4, 0x12C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r3, 0x124(r1)
	  stw       r0, 0x11C(r1)
	  stw       r23, 0x128(r1)
	  stw       r23, 0x120(r1)
	  stw       r23, 0x118(r1)

	.loc_0x1A4:
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x23
	  addi      r28, r28, 0x4
	  addi      r27, r27, 0x4
	  addi      r26, r26, 0x4
	  blt+      .loc_0x64
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r29, 0x158
	  bl        -0xC4214
	  bl        -0x2C128
	  mr        r3, r24
	  bl        0x160
	  lmw       r20, 0x130(r1)
	  lwz       r0, 0x174(r1)
	  lfd       f31, 0x168(r1)
	  lfd       f30, 0x160(r1)
	  addi      r1, r1, 0x170
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014AA88
 * Size:	000020
 */
void TekiMgr::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x6970C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014AAA8
 * Size:	0000A4
 */
void TekiMgr::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  li        r31, 0
	  stw       r30, 0x20(r1)
	  li        r30, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  b         .loc_0x78

	.loc_0x30:
	  lwz       r3, 0x34(r28)
	  lwzx      r0, r3, r31
	  cmpwi     r0, 0
	  bne-      .loc_0x70
	  lwz       r3, 0x28(r28)
	  lwzx      r3, r3, r31
	  lwz       r4, 0x320(r3)
	  addi      r0, r4, 0x18C
	  lbzx      r0, r28, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  lwz       r12, 0x0(r3)
	  mr        r4, r29
	  lwz       r12, 0xEC(r12)
	  mtlr      r12
	  blrl

	.loc_0x70:
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x78:
	  lwz       r0, 0x2C(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014AB4C
 * Size:	00007C
 */
void TekiMgr::newTeki(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr.       r30, r4
	  blt-      .loc_0x24
	  cmpwi     r30, 0x23
	  blt-      .loc_0x28

	.loc_0x24:
	  li        r30, 0

	.loc_0x28:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x48:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x16C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31

	.loc_0x64:
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
 * Address:	8014ABC8
 * Size:	00010C
 */
void TekiMgr::reset()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  stw       r30, 0x20(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x98

	.loc_0x30:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x54
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x6C

	.loc_0x54:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x6C:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x170(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x98:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC0
	  li        r0, 0x1
	  b         .loc_0xEC

	.loc_0xC0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xE8
	  li        r0, 0x1
	  b         .loc_0xEC

	.loc_0xE8:
	  li        r0, 0

	.loc_0xEC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x30
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014ACD4
 * Size:	000044
 */
void TekiMgr::createObject()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x540
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bl        -0x103CE4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x2C
	  li        r4, 0x1
	  bl        -0x710C

	.loc_0x2C:
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
 * Address:	8014AD18
 * Size:	000014
 */
void TekiMgr::getStrategy(int)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x3C(r3)
	  rlwinm    r0,r4,2,0,29
	  lwz       r3, 0x4(r3)
	  lwzx      r3, r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014AD2C
 * Size:	000010
 */
void TekiMgr::getTekiParameters(int)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r4,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0x4C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014AD3C
 * Size:	000010
 */
void TekiMgr::getTekiShapeObject(int)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r4,2,0,29
	  add       r3, r3, r0
	  lwz       r3, 0xD8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014AD4C
 * Size:	000010
 */
void TekiMgr::getSoundTable(int)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x44(r3)
	  rlwinm    r0,r4,2,0,29
	  lwzx      r3, r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014AD5C
 * Size:	00011C
 */
void TekiMgr::refresh2d(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr        r29, r4
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xA4

	.loc_0x38:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x5C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x74

	.loc_0x5C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r12, 0x0(r3)
	  mr        r4, r29
	  lwz       r12, 0xF0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xA4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCC
	  li        r0, 0x1
	  b         .loc_0xF8

	.loc_0xCC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xF4
	  li        r0, 0x1
	  b         .loc_0xF8

	.loc_0xF4:
	  li        r0, 0

	.loc_0xF8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x38
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014AE78
 * Size:	0000A8
 */
void TekiMgr::setUsingTypeTable(bool)
{
	/*
	.loc_0x0:
	  stb       r4, 0x164(r3)
	  li        r6, 0x20
	  subfic    r0, r6, 0x23
	  stb       r4, 0x165(r3)
	  cmpwi     r6, 0x23
	  mtctr     r0
	  stb       r4, 0x166(r3)
	  stb       r4, 0x167(r3)
	  stb       r4, 0x168(r3)
	  stb       r4, 0x169(r3)
	  stb       r4, 0x16A(r3)
	  stb       r4, 0x16B(r3)
	  stb       r4, 0x16C(r3)
	  stb       r4, 0x16D(r3)
	  stb       r4, 0x16E(r3)
	  stb       r4, 0x16F(r3)
	  stb       r4, 0x170(r3)
	  stb       r4, 0x171(r3)
	  stb       r4, 0x172(r3)
	  stb       r4, 0x173(r3)
	  stb       r4, 0x174(r3)
	  stb       r4, 0x175(r3)
	  stb       r4, 0x176(r3)
	  stb       r4, 0x177(r3)
	  stb       r4, 0x178(r3)
	  stb       r4, 0x179(r3)
	  stb       r4, 0x17A(r3)
	  stb       r4, 0x17B(r3)
	  stb       r4, 0x17C(r3)
	  stb       r4, 0x17D(r3)
	  stb       r4, 0x17E(r3)
	  stb       r4, 0x17F(r3)
	  stb       r4, 0x180(r3)
	  stb       r4, 0x181(r3)
	  stb       r4, 0x182(r3)
	  stb       r4, 0x183(r3)
	  bgelr-

	.loc_0x94:
	  addi      r0, r6, 0x164
	  stbx      r4, r3, r0
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x94
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void TekiMgr::setUsingType(int, bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014AF20
 * Size:	0000A8
 */
void TekiMgr::setVisibleTypeTable(bool)
{
	/*
	.loc_0x0:
	  stb       r4, 0x18C(r3)
	  li        r6, 0x20
	  subfic    r0, r6, 0x23
	  stb       r4, 0x18D(r3)
	  cmpwi     r6, 0x23
	  mtctr     r0
	  stb       r4, 0x18E(r3)
	  stb       r4, 0x18F(r3)
	  stb       r4, 0x190(r3)
	  stb       r4, 0x191(r3)
	  stb       r4, 0x192(r3)
	  stb       r4, 0x193(r3)
	  stb       r4, 0x194(r3)
	  stb       r4, 0x195(r3)
	  stb       r4, 0x196(r3)
	  stb       r4, 0x197(r3)
	  stb       r4, 0x198(r3)
	  stb       r4, 0x199(r3)
	  stb       r4, 0x19A(r3)
	  stb       r4, 0x19B(r3)
	  stb       r4, 0x19C(r3)
	  stb       r4, 0x19D(r3)
	  stb       r4, 0x19E(r3)
	  stb       r4, 0x19F(r3)
	  stb       r4, 0x1A0(r3)
	  stb       r4, 0x1A1(r3)
	  stb       r4, 0x1A2(r3)
	  stb       r4, 0x1A3(r3)
	  stb       r4, 0x1A4(r3)
	  stb       r4, 0x1A5(r3)
	  stb       r4, 0x1A6(r3)
	  stb       r4, 0x1A7(r3)
	  stb       r4, 0x1A8(r3)
	  stb       r4, 0x1A9(r3)
	  stb       r4, 0x1AA(r3)
	  stb       r4, 0x1AB(r3)
	  bgelr-

	.loc_0x94:
	  addi      r0, r6, 0x18C
	  stbx      r4, r3, r0
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x94
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014AFC8
 * Size:	00000C
 */
void TekiMgr::setVisibleType(int, bool)
{
	/*
	.loc_0x0:
	  add       r3, r3, r4
	  stb       r5, 0x18C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014AFD4
 * Size:	000070
 */
void TekiMgr::hasModel(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0x5
	  li        r3, 0x1
	  addi      r5, r3, 0
	  addi      r6, r3, 0
	  addi      r0, r3, 0
	  beq-      .loc_0x24
	  cmpwi     r4, 0x22
	  beq-      .loc_0x24
	  li        r0, 0

	.loc_0x24:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x38
	  cmpwi     r4, 0x1B
	  beq-      .loc_0x38
	  li        r6, 0

	.loc_0x38:
	  rlwinm.   r0,r6,0,24,31
	  bne-      .loc_0x4C
	  cmpwi     r4, 0x1C
	  beq-      .loc_0x4C
	  li        r5, 0

	.loc_0x4C:
	  rlwinm.   r0,r5,0,24,31
	  bne-      .loc_0x60
	  cmpwi     r4, 0x1D
	  beq-      .loc_0x60
	  li        r3, 0

	.loc_0x60:
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014B044
 * Size:	000054
 */
void TekiMgr::getResultFlag(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0x8
	  li        r3, 0
	  bne-      .loc_0x14
	  li        r3, 0x37
	  blr

	.loc_0x14:
	  cmpwi     r4, 0x21
	  bne-      .loc_0x24
	  li        r3, 0x39
	  blr

	.loc_0x24:
	  cmpwi     r4, 0xA
	  bne-      .loc_0x34
	  li        r3, 0x36
	  blr

	.loc_0x34:
	  cmpwi     r4, 0x4
	  bne-      .loc_0x44
	  li        r3, 0x29
	  blr

	.loc_0x44:
	  cmpwi     r4, 0x6
	  bnelr-
	  li        r3, 0x2C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014B098
 * Size:	000084
 */
TekiMgr::~TekiMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x6C
	  lis       r3, 0x802D
	  subi      r3, r3, 0x2368
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x5038
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4F80
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)

	.loc_0x5C:
	  extsh.    r0, r4
	  ble-      .loc_0x6C
	  mr        r3, r31
	  bl        -0x103F54

	.loc_0x6C:
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
 * Address:	8014B11C
 * Size:	000008
 */
void TekiMgr::@8 @update()
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x8
	  b         -0x698
	*/
}
