#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void GemItem::ignoreAtari(Creature *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void GemItem::setAtariFree()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void GemItem::bounceCallback()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
GemItem::GemItem(CreatureProp *, int, Shape **, Shape **, Shape **, SimpleAI *, float, int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void GemItem::initParam(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E4390
 * Size:	0000E4
 */
void GemItem::setColorType(int)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r4, 0x3
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r3, 0
  stw       r4, 0x3E0(r3)
  blt-      .loc_0x78
  bl        0x133CC0
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6710(r2)
  stw       r0, 0x2C(r1)
  lis       r0, 0x4330
  lfs       f2, -0x671C(r2)
  stw       r0, 0x28(r1)
  lfs       f1, -0x6720(r2)
  lfd       f3, 0x28(r1)
  lfs       f0, -0x6718(r2)
  fsubs     f3, f3, f4
  fdivs     f2, f3, f2
  fmuls     f1, f1, f2
  fmuls     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x18(r1)
  lwz       r0, 0x1C(r1)
  stfd      f0, 0x20(r1)
  cmpwi     r0, 0x3
  lwz       r4, 0x24(r1)
  blt-      .loc_0x78
  li        r4, 0

.loc_0x78:
  stw       r4, 0x3E0(r31)
  lwz       r0, 0x3DC(r31)
  cmpwi     r0, 0
  blt-      .loc_0x90
  cmpwi     r0, 0x5
  blt-      .loc_0x98

.loc_0x90:
  li        r0, 0
  stw       r0, 0x3DC(r31)

.loc_0x98:
  lwz       r3, 0x30AC(r13)
  lwz       r4, 0x3E0(r31)
  lwz       r5, 0x3DC(r31)
  bl        0xFF34
  stw       r3, 0x3C0(r31)
  lwz       r4, 0x3C0(r31)
  cmplwi    r4, 0
  beq-      .loc_0xD0
  lwz       r6, 0x30AC(r13)
  addi      r3, r31, 0x36C
  lwz       r5, 0x4(r4)
  addi      r4, r4, 0x8
  lwz       r6, 0x90(r6)
  bl        0x3ACC8

.loc_0xD0:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void GemItem::startAI(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000278
 */
void GemItem::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void GemItem::reachCapacity()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00019C
 */
void GemItem::updateLiftup()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void GemItem::startPick(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void GemItem::finishPick()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void GemItem::getSize()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GemItem::getiMass()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E4474
 * Size:	0001FC
 */
void GemItem::split()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xA0(r1)
  stfd      f31, 0x98(r1)
  stfd      f30, 0x90(r1)
  stfd      f29, 0x88(r1)
  stfd      f28, 0x80(r1)
  stfd      f27, 0x78(r1)
  stfd      f26, 0x70(r1)
  stfd      f25, 0x68(r1)
  stfd      f24, 0x60(r1)
  stfd      f23, 0x58(r1)
  stfd      f22, 0x50(r1)
  stmw      r26, 0x38(r1)
  mr        r31, r3
  lbz       r0, 0x3E4(r3)
  cmplwi    r0, 0
  beq-      .loc_0x1C0
  lwz       r0, 0x3DC(r31)
  lis       r3, 0x802C
  subi      r3, r3, 0x4E50
  mulli     r0, r0, 0x1C
  add       r3, r3, r0
  lwz       r29, 0x14(r3)
  cmpwi     r29, 0
  ble-      .loc_0x1C0
  li        r0, 0
  stb       r0, 0x3E4(r31)
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x5980C
  lwz       r0, 0x3DC(r31)
  cmpwi     r0, 0x1
  bne-      .loc_0x90
  li        r28, 0xB
  b         .loc_0x94

.loc_0x90:
  li        r28, 0x7

.loc_0x94:
  lfs       f24, -0x6708(r2)
  li        r27, 0
  lfd       f25, -0x6710(r2)
  lis       r30, 0x4330
  lfs       f26, -0x671C(r2)
  lfs       f27, -0x6720(r2)
  lfs       f28, -0x6704(r2)
  lfs       f29, -0x6700(r2)
  lfs       f30, -0x66FC(r2)
  lfs       f31, -0x66F8(r2)
  b         .loc_0x1B8

.loc_0xC0:
  lwz       r3, 0x30AC(r13)
  mr        r4, r28
  lwz       r12, 0x0(r3)
  lwz       r12, 0x78(r12)
  mtlr      r12
  blrl      
  lfs       f0, 0x94(r31)
  mr        r26, r3
  stfs      f0, 0x24(r1)
  lfs       f0, 0x98(r31)
  stfs      f0, 0x28(r1)
  lfs       f0, 0x9C(r31)
  stfs      f0, 0x2C(r1)
  lfs       f0, 0x98(r31)
  fadds     f0, f0, f24
  stfs      f0, 0x98(r31)
  bl        0x133AFC
  xoris     r0, r3, 0x8000
  stw       r0, 0x34(r1)
  stw       r30, 0x30(r1)
  lfd       f0, 0x30(r1)
  fsubs     f0, f0, f25
  fdivs     f0, f0, f26
  fmuls     f0, f27, f0
  fmuls     f0, f29, f0
  fmuls     f22, f28, f0
  fmr       f1, f22
  bl        0x1375B4
  fmuls     f23, f30, f1
  fmr       f1, f22
  bl        0x13773C
  fmuls     f0, f30, f1
  cmplwi    r26, 0
  stfs      f0, 0x10(r1)
  stfs      f31, 0x14(r1)
  stfs      f23, 0x18(r1)
  beq-      .loc_0x1B4
  mr        r3, r26
  lwz       r12, 0x0(r26)
  addi      r4, r1, 0x24
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r26
  lwz       r12, 0x0(r26)
  li        r4, 0
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  mr        r3, r26
  lwz       r4, 0x3E0(r31)
  lwz       r12, 0x0(r26)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x10(r1)
  lwz       r0, 0x14(r1)
  stw       r3, 0x70(r26)
  stw       r0, 0x74(r26)
  lwz       r0, 0x18(r1)
  stw       r0, 0x78(r26)

.loc_0x1B4:
  addi      r27, r27, 0x1

.loc_0x1B8:
  cmpw      r27, r29
  blt+      .loc_0xC0

.loc_0x1C0:
  lmw       r26, 0x38(r1)
  lwz       r0, 0xA4(r1)
  lfd       f31, 0x98(r1)
  lfd       f30, 0x90(r1)
  lfd       f29, 0x88(r1)
  lfd       f28, 0x80(r1)
  lfd       f27, 0x78(r1)
  lfd       f26, 0x70(r1)
  lfd       f25, 0x68(r1)
  lfd       f24, 0x60(r1)
  lfd       f23, 0x58(r1)
  lfd       f22, 0x50(r1)
  addi      r1, r1, 0xA0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void GemItem::refresh(Graphics &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void GemItem::doStore(CreatureInf *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void GemItem::doRestore(CreatureInf *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void GemItem::doKill()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GemItem::isAlive()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GemItem::setRouteTracer(RouteTracer *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E4670
 * Size:	00000C
 */
void ItemCreature::finalSetup()
{
// Generated from stb r0, 0x3C4(r3)
_3C4 = 1;
}
