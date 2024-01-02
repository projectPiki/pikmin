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
 * Size:	000074
 */
ItemBall::ItemBall(Shape*, CreatureProp*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800F7958
 * Size:	00003C
 */
void ItemBall::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r4, r3, 0
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x3C8
	  addi      r5, r4, 0x3DC
	  stwu      r1, -0x8(r1)
	  addi      r6, r4, 0x7EC
	  stw       r0, 0x220(r3)
	  lwz       r3, 0x220(r3)
	  lwz       r4, 0x308(r4)
	  bl        -0x6DE1C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7994
 * Size:	000008
 */
u32 ItemBall::isAlive() { return 0x1; }

/*
 * --INFO--
 * Address:	800F799C
 * Size:	000008
 */
u32 ItemBall::isVisible() { return 0x1; }

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
ItemObject::ItemObject(int, Shape*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800F79A4
 * Size:	000004
 */
void ItemObject::update() { }

/*
 * --INFO--
 * Address:	800F79A8
 * Size:	00007C
 */
BombGenItem::BombGenItem(Shape*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r6, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0xD
	  li        r5, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0x211C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x694
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x114
	  lis       r3, 0x802C
	  stw       r0, 0x2B8(r31)
	  li        r0, 0xD
	  subi      r3, r3, 0x7F0
	  stw       r0, 0x6C(r31)
	  addi      r5, r3, 0x114
	  li        r4, -0x1
	  stw       r3, 0x0(r31)
	  li        r0, 0x1
	  addi      r3, r31, 0
	  stw       r5, 0x2B8(r31)
	  sth       r4, 0x3C8(r31)
	  sth       r0, 0x3CA(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7A24
 * Size:	000030
 */
void BombGenItem::pickable()
{
	/*
	.loc_0x0:
	  lha       r0, 0x3C8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  lha       r0, 0x3CA(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x28
	  li        r3, 0x1
	  blr

	.loc_0x28:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7A54
 * Size:	00006C
 */
void BombGenItem::pick()
{
	/*
	.loc_0x0:
	  lha       r4, 0x3C8(r3)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x14
	  li        r0, 0x1
	  b         .loc_0x2C

	.loc_0x14:
	  lha       r0, 0x3CA(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x28
	  li        r0, 0x1
	  b         .loc_0x2C

	.loc_0x28:
	  li        r0, 0

	.loc_0x2C:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x3C
	  li        r3, 0
	  blr

	.loc_0x3C:
	  extsh.    r0, r4
	  ble-      .loc_0x64
	  lha       r4, 0x3CA(r3)
	  cmpwi     r4, 0
	  ble-      .loc_0x5C
	  subi      r0, r4, 0x1
	  sth       r0, 0x3CA(r3)
	  b         .loc_0x64

	.loc_0x5C:
	  li        r3, 0
	  blr

	.loc_0x64:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7AC0
 * Size:	00006C
 */
Fulcrum::Fulcrum()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x11
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  li        r6, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0x2234
	  lis       r3, 0x802C
	  subi      r3, r3, 0x694
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x114
	  lis       r3, 0x802C
	  stw       r0, 0x2B8(r31)
	  li        r0, 0x11
	  subi      r4, r3, 0x994
	  stw       r0, 0x6C(r31)
	  addi      r0, r4, 0x114
	  addi      r3, r31, 0
	  stw       r4, 0x0(r31)
	  stw       r0, 0x2B8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7B2C
 * Size:	00006C
 */
NaviDemoSunsetStart::NaviDemoSunsetStart()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1B
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  li        r6, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0x22A0
	  lis       r3, 0x802C
	  subi      r3, r3, 0x694
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x114
	  lis       r3, 0x802C
	  stw       r0, 0x2B8(r31)
	  li        r0, 0x1B
	  subi      r4, r3, 0xB2C
	  stw       r0, 0x6C(r31)
	  addi      r0, r4, 0x114
	  addi      r3, r31, 0
	  stw       r4, 0x0(r31)
	  stw       r0, 0x2B8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7B98
 * Size:	00006C
 */
NaviDemoSunsetGoal::NaviDemoSunsetGoal()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1C
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  li        r6, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        -0x230C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x694
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x114
	  lis       r3, 0x802C
	  stw       r0, 0x2B8(r31)
	  li        r0, 0x1C
	  subi      r4, r3, 0xCD8
	  stw       r0, 0x6C(r31)
	  addi      r0, r4, 0x114
	  addi      r3, r31, 0
	  stw       r4, 0x0(r31)
	  stw       r0, 0x2B8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7C04
 * Size:	000008
 */
u32 ItemObject::needShadow() { return 0x0; }

/*
 * --INFO--
 * Address:	800F7C0C
 * Size:	000004
 */
void ItemObject::postUpdate(int, f32) { }

/*
 * --INFO--
 * Address:	800F7C10
 * Size:	000008
 */
u32 ItemObject::isAtari() { return 0x0; }

/*
 * --INFO--
 * Address:	800F7C18
 * Size:	000030
 */
void BombGenItem::isAtari()
{
	/*
	.loc_0x0:
	  lha       r0, 0x3C8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  lha       r0, 0x3CA(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x28
	  li        r3, 0x1
	  blr

	.loc_0x28:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7C48
 * Size:	000008
 */
u32 BombGenItem::needFlick(Creature*) { return 0x0; }

/*
 * --INFO--
 * Address:	800F7C50
 * Size:	000030
 */
void BombGenItem::isVisible()
{
	/*
	.loc_0x0:
	  lha       r0, 0x3C8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  lha       r0, 0x3CA(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x28
	  li        r3, 0x1
	  blr

	.loc_0x28:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F7C80
 * Size:	000030
 */
void BombGenItem::isAlive()
{
	/*
	.loc_0x0:
	  lha       r0, 0x3C8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  lha       r0, 0x3CA(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x28
	  li        r3, 0x1
	  blr

	.loc_0x28:
	  li        r3, 0
	  blr
	*/
}
