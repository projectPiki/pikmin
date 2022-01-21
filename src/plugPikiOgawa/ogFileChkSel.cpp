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
 * Size:	00001C
 */
void zen::ogScrFileChkSelMgr::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80193594
 * Size:	000110
 */
zen::ogScrFileChkSelMgr::ogScrFileChkSelMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, -0x1
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  li        r31, 0
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  stw       r0, 0x0(r3)
	  li        r3, 0xF8
	  stb       r31, 0x4(r29)
	  stb       r31, 0xD(r29)
	  stb       r31, 0xE(r29)
	  bl        -0x14C5C8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x98
	  addi      r3, r1, 0xC
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x20038
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0xC
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x1D3BC
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r30)
	  stb       r31, 0xEC(r30)
	  stw       r31, 0xF0(r30)
	  stw       r31, 0xF4(r30)

	.loc_0x98:
	  stw       r30, 0x8(r29)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x6010
	  lwz       r3, 0x8(r29)
	  li        r5, 0x1
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        0x1F5B8
	  li        r3, 0x10C
	  bl        -0x14C64C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xD0
	  bl        -0x6614

	.loc_0xD0:
	  stw       r30, 0x10(r29)
	  li        r3, 0x11A4
	  bl        -0x14C668
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xEC
	  bl        -0x9FC0

	.loc_0xEC:
	  stw       r30, 0x14(r29)
	  mr        r3, r29
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
 * Address:	........
 * Size:	000048
 */
void zen::ogScrFileChkSelMgr::startSub()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801936A4
 * Size:	000050
 */
void zen::ogScrFileChkSelMgr::start(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  stb       r4, 0xD(r3)
	  stb       r31, 0x4(r3)
	  stw       r31, 0x0(r3)
	  lwz       r3, 0x10(r3)
	  bl        -0x59A8
	  stb       r31, 0xC(r30)
	  stb       r31, 0xE(r30)
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
 * Address:	801936F4
 * Size:	000054
 */
void zen::ogScrFileChkSelMgr::startSave()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stb       r31, 0xD(r3)
	  stb       r0, 0x4(r3)
	  stw       r31, 0x0(r3)
	  lwz       r3, 0x10(r3)
	  bl        -0x59FC
	  stb       r31, 0xC(r30)
	  stb       r31, 0xE(r30)
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
 * Address:	80193748
 * Size:	000198
 */
void zen::ogScrFileChkSelMgr::update(Controller*, CardQuickInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x34
	  b         .loc_0x17C

	.loc_0x34:
	  cmpwi     r3, 0x1
	  blt-      .loc_0x4C
	  li        r0, -0x1
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x17C

	.loc_0x4C:
	  lwz       r3, 0x10(r29)
	  mr        r4, r30
	  bl        -0x56C0
	  cmpwi     r3, 0x15
	  bne-      .loc_0x98
	  lbz       r0, 0xD(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x7C
	  li        r0, 0x5
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x17C

	.loc_0x7C:
	  lwz       r3, 0x14(r29)
	  li        r5, 0
	  lbz       r4, 0x4(r29)
	  bl        -0x9360
	  li        r0, 0x1
	  stb       r0, 0xE(r29)
	  b         .loc_0x178

	.loc_0x98:
	  cmpwi     r3, 0x14
	  bne-      .loc_0xB0
	  li        r0, 0x5
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x17C

	.loc_0xB0:
	  cmpwi     r3, 0x13
	  bne-      .loc_0xC8
	  li        r0, 0x1
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x17C

	.loc_0xC8:
	  cmpwi     r3, -0x1
	  bne-      .loc_0x178
	  bl        -0x14FC8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xFC
	  li        r3, 0x128
	  bl        -0xEE480
	  li        r3, 0x12A
	  bl        -0xEE4BC
	  li        r0, 0x1
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  b         .loc_0x17C

	.loc_0xFC:
	  lwz       r3, 0x8(r29)
	  bl        0x1F308
	  lwz       r3, 0x14(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        -0x88A8
	  cmpwi     r3, 0x8
	  beq-      .loc_0x158
	  bge-      .loc_0x130
	  cmpwi     r3, 0x6
	  beq-      .loc_0x140
	  bge-      .loc_0x14C
	  b         .loc_0x178

	.loc_0x130:
	  cmpwi     r3, 0xA
	  beq-      .loc_0x170
	  bge-      .loc_0x178
	  b         .loc_0x164

	.loc_0x140:
	  li        r0, 0x1
	  stw       r0, 0x0(r29)
	  b         .loc_0x178

	.loc_0x14C:
	  li        r0, 0x2
	  stw       r0, 0x0(r29)
	  b         .loc_0x178

	.loc_0x158:
	  li        r0, 0x3
	  stw       r0, 0x0(r29)
	  b         .loc_0x178

	.loc_0x164:
	  li        r0, 0x4
	  stw       r0, 0x0(r29)
	  b         .loc_0x178

	.loc_0x170:
	  li        r0, 0x5
	  stw       r0, 0x0(r29)

	.loc_0x178:
	  lwz       r3, 0x0(r29)

	.loc_0x17C:
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
 * Address:	801938E0
 * Size:	0000BC
 */
void zen::ogScrFileChkSelMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xF8(r1)
	  mr        r30, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xA4
	  lbz       r0, 0xE(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x8C
	  lfs       f1, -0x4E18(r2)
	  addi      r3, r1, 0x10
	  lfs       f2, -0x4E14(r2)
	  li        r4, 0
	  lfs       f3, -0x4E10(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1C85C
	  addi      r3, r1, 0x10
	  bl        0x1C964
	  lwz       r3, 0x8(r30)
	  addi      r6, r1, 0x10
	  li        r4, 0
	  li        r5, 0
	  bl        0x1F584
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x10(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x10(r1)

	.loc_0x8C:
	  lwz       r3, 0x14(r30)
	  mr        r4, r31
	  bl        -0x7F80
	  lwz       r3, 0x10(r30)
	  mr        r4, r31
	  bl        -0x49E0

	.loc_0xA4:
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  lwz       r30, 0xF8(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}
