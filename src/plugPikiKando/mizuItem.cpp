#include "MizuItem.h"

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
 * Address:	800F7CB0
 * Size:	000068
 */
MizuItem::MizuItem(int p1, CreatureProp* props, ItemShapeObject*, SimpleAI*)
    : ItemCreature(p1, props, nullptr)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r7, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r6, 0
	  li        r6, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  bl        -0x242C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x280
	  stw       r3, 0x0(r29)
	  addi      r0, r3, 0x114
	  addi      r3, r29, 0
	  stw       r0, 0x2B8(r29)
	  stw       r30, 0x3C0(r29)
	  stw       r31, 0x2E8(r29)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7D18
 * Size:	000070
 */
void MizuItem::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x2138
	  lwz       r0, 0x28C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x6
	  bne-      .loc_0x5C
	  li        r0, 0x9
	  stw       r0, 0xC(r1)
	  lwz       r3, 0x2E8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  addi      r5, r1, 0xC
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x5C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7D88
 * Size:	000008
 */
bool MizuItem::needFlick(Creature*) { return false; }

/*
 * --INFO--
 * Address:	800F7D90
 * Size:	000090
 */
void MizuItem::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x10
	  lfs       f0, -0x63B0(r2)
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)
	  bl        0x2719C
	  addi      r4, r3, 0
	  addi      r3, r31, 0x36C
	  bl        0x273F8
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x6C
	  bge-      .loc_0x7C
	  cmpwi     r0, 0x1
	  beq-      .loc_0x58
	  b         .loc_0x7C

	.loc_0x58:
	  lwz       r3, 0x2E8(r31)
	  addi      r4, r31, 0
	  li        r5, 0x3
	  bl        -0x7A69C
	  b         .loc_0x7C

	.loc_0x6C:
	  lwz       r3, 0x2E8(r31)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x7A6B0

	.loc_0x7C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7E20
 * Size:	00006C
 */
bool MizuItem::isAlive()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x6C(r31)
	  lwz       r3, 0x4(r3)
	  cmpwi     r0, 0x6
	  bne-      .loc_0x3C
	  li        r3, 0
	  b         .loc_0x58

	.loc_0x3C:
	  cmpwi     r3, 0x4
	  beq-      .loc_0x4C
	  cmpwi     r3, 0x2
	  bne-      .loc_0x54

	.loc_0x4C:
	  li        r3, 0
	  b         .loc_0x58

	.loc_0x54:
	  li        r3, 0x1

	.loc_0x58:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
