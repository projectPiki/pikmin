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
 * Size:	000030
 */
PikiInfMgr::PikiInfMgr()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C56D4
 * Size:	000028
 */
void PikiInfMgr::initGame()
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  addi      r3, r3, 0x1DF0
  stwu      r1, -0x8(r1)
  bl        0x180
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C56FC
 * Size:	000078
 */
void PikiInfMgr::saveCard(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  li        r29, 0
  mulli     r0, r29, 0xC
  addi      r27, r4, 0
  add       r30, r3, r0

.loc_0x20:
  li        r28, 0
  rlwinm    r0,r28,2,0,29
  add       r31, r30, r0

.loc_0x2C:
  mr        r3, r27
  lwz       r4, 0x0(r31)
  lwz       r12, 0x4(r27)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  addi      r28, r28, 0x1
  cmpwi     r28, 0x3
  addi      r31, r31, 0x4
  blt+      .loc_0x2C
  addi      r29, r29, 0x1
  cmpwi     r29, 0x3
  addi      r30, r30, 0xC
  blt+      .loc_0x20
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C5774
 * Size:	000070
 */
void PikiInfMgr::loadCard(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  addi      r27, r4, 0
  addi      r30, r3, 0
  li        r29, 0

.loc_0x1C:
  li        r28, 0
  addi      r31, r30, 0

.loc_0x24:
  mr        r3, r27
  lwz       r12, 0x4(r27)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  addi      r28, r28, 0x1
  stw       r3, 0x0(r31)
  cmpwi     r28, 0x3
  addi      r31, r31, 0x4
  blt+      .loc_0x24
  addi      r29, r29, 0x1
  cmpwi     r29, 0x3
  addi      r30, r30, 0xC
  blt+      .loc_0x1C
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C57E4
 * Size:	000034
 */
void PikiInfMgr::incPiki(Piki *)
{
/*
.loc_0x0:
  lhz       r0, 0x510(r4)
  cmplwi    r0, 0x2
  lwz       r5, 0x520(r4)
  cmpwi     r5, 0
  blt-      .loc_0x18
  cmpwi     r5, 0x2

.loc_0x18:
  mulli     r4, r0, 0xC
  rlwinm    r0,r5,2,0,29
  add       r5, r4, r0
  lwzx      r4, r3, r5
  addi      r0, r4, 0x1
  stwx      r0, r3, r5
  blr
*/
}

/*
 * --INFO--
 * Address:	800C5818
 * Size:	00001C
 */
void PikiInfMgr::incPiki(int, int)
{
/*
.loc_0x0:
  mulli     r4, r4, 0xC
  rlwinm    r0,r5,2,0,29
  add       r5, r4, r0
  lwzx      r4, r3, r5
  addi      r0, r4, 0x1
  stwx      r0, r3, r5
  blr
*/
}

/*
 * --INFO--
 * Address:	800C5834
 * Size:	000034
 */
void PikiInfMgr::decPiki(Piki *)
{
/*
.loc_0x0:
  lhz       r0, 0x510(r4)
  cmplwi    r0, 0x2
  lwz       r5, 0x520(r4)
  cmpwi     r5, 0
  blt-      .loc_0x18
  cmpwi     r5, 0x2

.loc_0x18:
  mulli     r4, r0, 0xC
  rlwinm    r0,r5,2,0,29
  add       r5, r4, r0
  lwzx      r4, r3, r5
  subi      r0, r4, 0x1
  stwx      r0, r3, r5
  blr
*/
}

/*
 * --INFO--
 * Address:	800C5868
 * Size:	00002C
 */
void PikiInfMgr::clear()
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x18(r3)
  stw       r0, 0xC(r3)
  stw       r0, 0x0(r3)
  stw       r0, 0x1C(r3)
  stw       r0, 0x10(r3)
  stw       r0, 0x4(r3)
  stw       r0, 0x20(r3)
  stw       r0, 0x14(r3)
  stw       r0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void PikiInfMgr::getTotal()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
BaseInf::BaseInf()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C5894
 * Size:	00005C
 */
void BaseInf::store(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x94(r4)
  lwz       r0, 0x98(r4)
  stw       r5, 0x14(r3)
  stw       r0, 0x18(r3)
  lwz       r0, 0x9C(r4)
  stw       r0, 0x1C(r3)
  lwz       r5, 0x88(r4)
  lwz       r0, 0x8C(r4)
  stw       r5, 0x20(r3)
  stw       r0, 0x24(r3)
  lwz       r0, 0x90(r4)
  stw       r0, 0x28(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C58F0
 * Size:	000004
 */
void BaseInf::doStore(Creature *)
{
}

/*
 * --INFO--
 * Address:	800C58F4
 * Size:	00005C
 */
void BaseInf::restore(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x14(r3)
  lwz       r0, 0x18(r3)
  stw       r5, 0x94(r4)
  stw       r0, 0x98(r4)
  lwz       r0, 0x1C(r3)
  stw       r0, 0x9C(r4)
  lwz       r5, 0x20(r3)
  lwz       r0, 0x24(r3)
  stw       r5, 0x88(r4)
  stw       r0, 0x8C(r4)
  lwz       r0, 0x28(r3)
  stw       r0, 0x90(r4)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C5950
 * Size:	000004
 */
void BaseInf::doRestore(Creature *)
{
}

/*
 * --INFO--
 * Address:	800C5954
 * Size:	0000A0
 */
void BaseInf::saveCard(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r4, 0
  stw       r30, 0x28(r1)
  mr        r30, r3
  lfs       f0, 0x14(r3)
  addi      r3, r31, 0
  lwz       r12, 0x4(r31)
  fctiwz    f0, f0
  lwz       r12, 0x2C(r12)
  stfd      f0, 0x20(r1)
  mtlr      r12
  lwz       r4, 0x24(r1)
  blrl      
  lfs       f0, 0x18(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  fctiwz    f0, f0
  lwz       r12, 0x2C(r12)
  stfd      f0, 0x18(r1)
  mtlr      r12
  lwz       r4, 0x1C(r1)
  blrl      
  lfs       f0, 0x1C(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  fctiwz    f0, f0
  lwz       r12, 0x2C(r12)
  stfd      f0, 0x10(r1)
  mtlr      r12
  lwz       r4, 0x14(r1)
  blrl      
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
 * Address:	800C59F4
 * Size:	0000F4
 */
void BaseInf::loadCard(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  addi      r30, r4, 0
  stw       r29, 0x2C(r1)
  addi      r29, r3, 0
  addi      r3, r30, 0
  lwz       r12, 0x4(r30)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  lfd       f1, -0x6A50(r2)
  xoris     r0, r0, 0x8000
  stw       r0, 0x24(r1)
  lis       r31, 0x4330
  addi      r3, r30, 0
  stw       r31, 0x20(r1)
  lfd       f0, 0x20(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x14(r29)
  lwz       r12, 0x4(r30)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  lfd       f1, -0x6A50(r2)
  xoris     r0, r0, 0x8000
  stw       r0, 0x1C(r1)
  mr        r3, r30
  stw       r31, 0x18(r1)
  lfd       f0, 0x18(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x18(r29)
  lwz       r12, 0x4(r30)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  lfd       f1, -0x6A50(r2)
  xoris     r0, r0, 0x8000
  stw       r0, 0x14(r1)
  stw       r31, 0x10(r1)
  lfd       f0, 0x10(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x1C(r29)
  lfs       f0, -0x4318(r13)
  stfs      f0, 0x20(r29)
  lfs       f0, -0x4314(r13)
  stfs      f0, 0x24(r29)
  lfs       f0, -0x4310(r13)
  stfs      f0, 0x28(r29)
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
 * Address:	........
 * Size:	0000EC
 */
BPikiInf::BPikiInf()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C5AE8
 * Size:	0000C4
 */
void BPikiInf::saveCard(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r4, 0
  stw       r30, 0x28(r1)
  mr        r30, r3
  lfs       f0, 0x14(r3)
  addi      r3, r31, 0
  lwz       r12, 0x4(r31)
  fctiwz    f0, f0
  lwz       r12, 0x2C(r12)
  stfd      f0, 0x20(r1)
  mtlr      r12
  lwz       r4, 0x24(r1)
  blrl      
  lfs       f0, 0x18(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  fctiwz    f0, f0
  lwz       r12, 0x2C(r12)
  stfd      f0, 0x18(r1)
  mtlr      r12
  lwz       r4, 0x1C(r1)
  blrl      
  lfs       f0, 0x1C(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  fctiwz    f0, f0
  lwz       r12, 0x2C(r12)
  stfd      f0, 0x10(r1)
  mtlr      r12
  lwz       r4, 0x14(r1)
  blrl      
  lwz       r12, 0x4(r31)
  mr        r3, r31
  lbz       r4, 0x2D(r30)
  lwz       r12, 0x28(r12)
  lbz       r0, 0x2C(r30)
  rlwinm    r4,r4,2,0,29
  mtlr      r12
  or        r4, r4, r0
  blrl      
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
 * Address:	800C5BAC
 * Size:	000118
 */
void BPikiInf::loadCard(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  addi      r30, r4, 0
  stw       r29, 0x2C(r1)
  addi      r29, r3, 0
  addi      r3, r30, 0
  lwz       r12, 0x4(r30)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  lfd       f1, -0x6A50(r2)
  xoris     r0, r0, 0x8000
  stw       r0, 0x24(r1)
  lis       r31, 0x4330
  addi      r3, r30, 0
  stw       r31, 0x20(r1)
  lfd       f0, 0x20(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x14(r29)
  lwz       r12, 0x4(r30)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  lfd       f1, -0x6A50(r2)
  xoris     r0, r0, 0x8000
  stw       r0, 0x1C(r1)
  mr        r3, r30
  stw       r31, 0x18(r1)
  lfd       f0, 0x18(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x18(r29)
  lwz       r12, 0x4(r30)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  lfd       f1, -0x6A50(r2)
  xoris     r0, r0, 0x8000
  stw       r0, 0x14(r1)
  mr        r3, r30
  stw       r31, 0x10(r1)
  lfd       f0, 0x10(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x1C(r29)
  lfs       f0, -0x4318(r13)
  stfs      f0, 0x20(r29)
  lfs       f0, -0x4314(r13)
  stfs      f0, 0x24(r29)
  lfs       f0, -0x4310(r13)
  stfs      f0, 0x28(r29)
  lwz       r12, 0x4(r30)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  rlwinm    r0,r3,0,30,31
  stb       r0, 0x2C(r29)
  rlwinm    r0,r3,30,26,31
  stb       r0, 0x2D(r29)
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
 * Address:	800C5CC4
 * Size:	000014
 */
void BPikiInf::doStore(Creature *)
{
/*
.loc_0x0:
  lwz       r0, 0x3CC(r4)
  stb       r0, 0x2C(r3)
  lwz       r0, 0x3D0(r4)
  stb       r0, 0x2D(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800C5CD8
 * Size:	000014
 */
void BPikiInf::doRestore(Creature *)
{
/*
.loc_0x0:
  lbz       r0, 0x2C(r3)
  stw       r0, 0x3CC(r4)
  lbz       r0, 0x2D(r3)
  stw       r0, 0x3D0(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	800C5CEC
 * Size:	000170
 */
MonoInfMgr::MonoInfMgr()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802C
  stw       r0, 0x4(r1)
  subi      r0, r4, 0x7C7C
  stwu      r1, -0x30(r1)
  stmw      r25, 0x14(r1)
  addi      r25, r3, 0
  lis       r3, 0x802C
  li        r28, 0
  stw       r0, 0x0(r25)
  subi      r0, r3, 0x7C9C
  lis       r3, 0x8022
  stw       r0, 0x0(r25)
  addi      r26, r3, 0x738C
  lis       r3, 0x8022
  stw       r26, 0xC(r25)
  addi      r27, r3, 0x737C
  lis       r3, 0x802C
  stw       r27, 0xC(r25)
  subi      r29, r3, 0x7DC4
  addi      r4, r29, 0
  stw       r28, 0x1C(r25)
  addi      r3, r25, 0xC
  stw       r28, 0x18(r25)
  stw       r28, 0x14(r25)
  bl        -0xA0E7C
  lis       r3, 0x802C
  subi      r30, r3, 0x7C18
  stw       r30, 0xC(r25)
  subi      r31, r13, 0x4320
  addi      r4, r29, 0
  lfs       f0, -0x6A58(r2)
  addi      r3, r25, 0x38
  stfs      f0, 0x28(r25)
  stfs      f0, 0x24(r25)
  stfs      f0, 0x20(r25)
  stfs      f0, 0x34(r25)
  stfs      f0, 0x30(r25)
  stfs      f0, 0x2C(r25)
  stw       r28, 0x1C(r25)
  stw       r28, 0x18(r25)
  stw       r28, 0x14(r25)
  stw       r31, 0x10(r25)
  lfs       f0, -0x4338(r13)
  stfs      f0, 0x20(r25)
  lfs       f0, -0x4334(r13)
  stfs      f0, 0x24(r25)
  lfs       f0, -0x4330(r13)
  stfs      f0, 0x28(r25)
  lfs       f0, -0x432C(r13)
  stfs      f0, 0x2C(r25)
  lfs       f0, -0x4328(r13)
  stfs      f0, 0x30(r25)
  lfs       f0, -0x4324(r13)
  stfs      f0, 0x34(r25)
  stw       r26, 0x38(r25)
  stw       r27, 0x38(r25)
  stw       r28, 0x48(r25)
  stw       r28, 0x44(r25)
  stw       r28, 0x40(r25)
  bl        -0xA0F08
  stw       r30, 0x38(r25)
  mr        r3, r25
  lfs       f0, -0x6A58(r2)
  stfs      f0, 0x54(r25)
  stfs      f0, 0x50(r25)
  stfs      f0, 0x4C(r25)
  stfs      f0, 0x60(r25)
  stfs      f0, 0x5C(r25)
  stfs      f0, 0x58(r25)
  stw       r28, 0x48(r25)
  stw       r28, 0x44(r25)
  stw       r28, 0x40(r25)
  stw       r31, 0x3C(r25)
  lfs       f0, -0x4338(r13)
  stfs      f0, 0x4C(r25)
  lfs       f0, -0x4334(r13)
  stfs      f0, 0x50(r25)
  lfs       f0, -0x4330(r13)
  stfs      f0, 0x54(r25)
  lfs       f0, -0x432C(r13)
  stfs      f0, 0x58(r25)
  lfs       f0, -0x4328(r13)
  stfs      f0, 0x5C(r25)
  lfs       f0, -0x4324(r13)
  stfs      f0, 0x60(r25)
  stw       r28, 0x8(r25)
  lwz       r0, 0x34(r1)
  lmw       r25, 0x14(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C5E5C
 * Size:	0000D0
 */
void MonoInfMgr::init(int)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x802C
  stw       r0, 0x4(r1)
  subi      r5, r5, 0x7DB8
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  mr        r29, r4
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  stw       r31, 0x1C(r3)
  lis       r3, 0x802C
  subi      r0, r3, 0x7DAC
  stw       r31, 0x18(r28)
  stw       r31, 0x14(r28)
  stw       r5, 0x10(r28)
  stw       r31, 0x48(r28)
  stw       r31, 0x44(r28)
  stw       r31, 0x40(r28)
  stw       r0, 0x3C(r28)
  stw       r29, 0x4(r28)
  lwz       r0, 0x4(r28)
  rlwinm    r3,r0,2,0,29
  bl        -0x7EEBC
  stw       r3, 0x8(r28)
  li        r30, 0
  b         .loc_0xA8

.loc_0x74:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  lwz       r12, 0x1C(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x8(r28)
  stwx      r3, r4, r31
  addi      r3, r28, 0x38
  lwz       r4, 0x8(r28)
  lwzx      r4, r4, r31
  bl        -0x85920
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0xA8:
  cmpw      r30, r29
  blt+      .loc_0x74
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
 * Address:	800C5F2C
 * Size:	000058
 */
void MonoInfMgr::getFreeInf()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r0, 0x48(r3)
  cmplwi    r0, 0
  mr        r31, r0
  beq-      .loc_0x3C
  mr        r3, r31
  bl        -0x85948
  addi      r3, r30, 0xC
  addi      r4, r31, 0
  bl        -0x8598C

.loc_0x3C:
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
 * Address:	800C5F84
 * Size:	000048
 */
void MonoInfMgr::delInf(BaseInf *)
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
  bl        -0x85994
  addi      r3, r30, 0x38
  addi      r4, r31, 0
  bl        -0x859D8
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
 * Address:	800C5FCC
 * Size:	000024
 */
void MonoInfMgr::getActiveNum()
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0xC
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x8595C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C5FF0
 * Size:	000024
 */
void MonoInfMgr::getFreeNum()
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x38
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x85980
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void MonoInfMgr::saveCard(RandomAccessStream &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C6014
 * Size:	0000C4
 */
void MonoInfMgr::loadCard(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  mr        r29, r4
  stw       r28, 0x10(r1)
  mr        r28, r3
  lwz       r31, 0x1C(r3)
  b         .loc_0x48

.loc_0x2C:
  lwz       r30, 0xC(r31)
  mr        r3, r31
  bl        -0x85A38
  addi      r3, r28, 0x38
  addi      r4, r31, 0
  bl        -0x85A7C
  mr        r31, r30

.loc_0x48:
  cmplwi    r31, 0
  bne+      .loc_0x2C
  mr        r3, r29
  lwz       r12, 0x4(r29)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  addi      r31, r3, 0
  li        r30, 0
  b         .loc_0x9C

.loc_0x70:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lwz       r12, 0x0(r3)
  mr        r4, r29
  lwz       r12, 0x1C(r12)
  mtlr      r12
  blrl      
  addi      r30, r30, 0x1

.loc_0x9C:
  cmpw      r30, r31
  blt+      .loc_0x70
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C60D8
 * Size:	0000CC
 */
void BPikiInfMgr::newInf()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x30
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  bl        -0x7F0E8
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0xB4
  lis       r4, 0x802C
  subi      r4, r4, 0x7DC4
  bl        -0x9114C
  lis       r3, 0x802C
  subi      r0, r3, 0x7C18
  stw       r0, 0x0(r31)
  lis       r3, 0x802C
  li        r5, 0
  lfs       f0, -0x6A58(r2)
  subi      r4, r13, 0x4320
  subi      r0, r3, 0x7C38
  stfs      f0, 0x1C(r31)
  stfs      f0, 0x18(r31)
  stfs      f0, 0x14(r31)
  stfs      f0, 0x28(r31)
  stfs      f0, 0x24(r31)
  stfs      f0, 0x20(r31)
  stw       r5, 0x10(r31)
  stw       r5, 0xC(r31)
  stw       r5, 0x8(r31)
  stw       r4, 0x4(r31)
  lfs       f0, -0x4338(r13)
  stfs      f0, 0x14(r31)
  lfs       f0, -0x4334(r13)
  stfs      f0, 0x18(r31)
  lfs       f0, -0x4330(r13)
  stfs      f0, 0x1C(r31)
  lfs       f0, -0x432C(r13)
  stfs      f0, 0x20(r31)
  lfs       f0, -0x4328(r13)
  stfs      f0, 0x24(r31)
  lfs       f0, -0x4324(r13)
  stfs      f0, 0x28(r31)
  stw       r0, 0x0(r31)
  stb       r5, 0x2D(r31)
  stb       r5, 0x2C(r31)

.loc_0xB4:
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
 * Address:	........
 * Size:	000064
 */
void BPikiInfMgr::initGame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C61A4
 * Size:	00002C
 */
void BPikiInfMgr::getPikiCount(int)
{
/*
.loc_0x0:
  lwz       r5, 0x1C(r3)
  li        r3, 0
  b         .loc_0x20

.loc_0xC:
  lbz       r0, 0x2C(r5)
  cmpw      r0, r4
  bne-      .loc_0x1C
  addi      r3, r3, 0x1

.loc_0x1C:
  lwz       r5, 0xC(r5)

.loc_0x20:
  cmplwi    r5, 0
  bne+      .loc_0xC
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void CreatureInfMgr::beginRegister(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void CreatureInfMgr::registerType(int, CreatureInf * (*) (Creature *), Creature * (*) (CreatureInf *))
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CreatureInfMgr::endRegister()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void CreatureInfMgr::getStoreFun(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void CreatureInfMgr::getRestoreFun(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
CreatureInf::CreatureInf()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C61D0
 * Size:	0000D4
 */
void CreatureInfMgr::newInf()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x4C
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  bl        -0x7F1E0
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0xBC
  lis       r4, 0x802C
  subi      r4, r4, 0x7DC4
  bl        -0x91244
  lis       r3, 0x802C
  subi      r0, r3, 0x7C18
  stw       r0, 0x0(r31)
  lis       r3, 0x802C
  li        r5, 0
  lfs       f0, -0x6A58(r2)
  subi      r4, r13, 0x4320
  subi      r3, r3, 0x7D58
  stfs      f0, 0x1C(r31)
  li        r0, -0x1
  stfs      f0, 0x18(r31)
  stfs      f0, 0x14(r31)
  stfs      f0, 0x28(r31)
  stfs      f0, 0x24(r31)
  stfs      f0, 0x20(r31)
  stw       r5, 0x10(r31)
  stw       r5, 0xC(r31)
  stw       r5, 0x8(r31)
  stw       r4, 0x4(r31)
  lfs       f0, -0x4338(r13)
  stfs      f0, 0x14(r31)
  lfs       f0, -0x4334(r13)
  stfs      f0, 0x18(r31)
  lfs       f0, -0x4330(r13)
  stfs      f0, 0x1C(r31)
  lfs       f0, -0x432C(r13)
  stfs      f0, 0x20(r31)
  lfs       f0, -0x4328(r13)
  stfs      f0, 0x24(r31)
  lfs       f0, -0x4324(r13)
  stfs      f0, 0x28(r31)
  stw       r3, 0x0(r31)
  stw       r0, 0x2C(r31)
  stw       r5, 0x34(r31)
  stw       r5, 0x30(r31)

.loc_0xBC:
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
 * Address:	800C62A4
 * Size:	0000E0
 */
void CreatureInf::doStore(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r3, 0
  stw       r30, 0x28(r1)
  li        r30, 0
  stw       r29, 0x24(r1)
  mr        r29, r4
  lwz       r0, 0x6C(r4)
  mr        r4, r31
  stw       r0, 0x2C(r3)
  li        r0, -0x1
  addi      r3, r29, 0
  stw       r30, 0x34(r31)
  stw       r0, 0x30(r31)
  lwz       r0, 0xC8(r29)
  rlwinm    r0,r0,0,15,15
  neg       r5, r0
  subic     r0, r5, 0x1
  subfe     r0, r0, r5
  rlwinm    r0,r0,0,24,31
  stw       r0, 0x38(r31)
  lwz       r12, 0x0(r29)
  lwz       r12, 0x48(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x34(r29)
  cmpwi     r0, 0
  ble-      .loc_0xC4
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xA8
  li        r0, 0x1
  stw       r0, 0x38(r31)
  lwz       r0, 0x34(r29)
  stw       r0, 0x34(r31)
  b         .loc_0xC4

.loc_0xA8:
  lis       r3, 0x803A
  stw       r30, 0x38(r31)
  subi      r3, r3, 0x2848
  lwz       r0, 0x2FC(r3)
  stw       r0, 0x30(r31)
  lwz       r0, 0x34(r29)
  stw       r0, 0x34(r31)

.loc_0xC4:
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
 * Address:	800C6384
 * Size:	000060
 */
void CreatureInf::doRestore(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  mr        r5, r3
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x38(r3)
  cmpwi     r0, 0
  beq-      .loc_0x2C
  lwz       r0, 0xC8(r4)
  oris      r0, r0, 0x1
  stw       r0, 0xC8(r4)
  b         .loc_0x38

.loc_0x2C:
  lwz       r0, 0xC8(r4)
  rlwinm    r0,r0,0,16,14
  stw       r0, 0xC8(r4)

.loc_0x38:
  mr        r3, r4
  lwz       r12, 0x0(r4)
  mr        r4, r5
  lwz       r12, 0x4C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void CreatureInfMgr::updateUseList()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00022C
 */
void CreatureInfMgr::restoreAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C63E4
 * Size:	000030
 */
void StageInf::init()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x64
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C6414
 * Size:	000064
 */
void StageInf::initGame()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  mr        r29, r3
  lwz       r30, 0x1C(r3)
  b         .loc_0x40

.loc_0x24:
  lwz       r31, 0xC(r30)
  mr        r3, r30
  bl        -0x85E30
  addi      r3, r29, 0x38
  addi      r4, r30, 0
  bl        -0x85E74
  mr        r30, r31

.loc_0x40:
  cmplwi    r30, 0
  bne+      .loc_0x24
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
 * Address:	800C6478
 * Size:	000088
 */
void StageInf::saveCard(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  stw       r30, 0x10(r1)
  mr        r30, r4
  lwz       r12, 0x0(r31)
  lwz       r12, 0x18(r12)
  mtlr      r12
  blrl      
  lwz       r12, 0x4(r30)
  addi      r4, r3, 0
  addi      r3, r30, 0
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  lwz       r31, 0x1C(r31)
  b         .loc_0x68

.loc_0x4C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x18(r12)
  mtlr      r12
  blrl      
  lwz       r31, 0xC(r31)

.loc_0x68:
  cmplwi    r31, 0
  bne+      .loc_0x4C
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
 * Address:	800C6500
 * Size:	000020
 */
void StageInf::loadCard(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x4F8
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C6520
 * Size:	000004
 */
void InfMgr::init(int)
{
}

/*
 * --INFO--
 * Address:	800C6524
 * Size:	000034
 */
void __sinit_pikiInf_cpp(void)
{
/*
.loc_0x0:
  lis       r3, 0x803D
  addi      r3, r3, 0x1DF0
  li        r0, 0
  stw       r0, 0x18(r3)
  stw       r0, 0xC(r3)
  stw       r0, 0x0(r3)
  stw       r0, 0x1C(r3)
  stw       r0, 0x10(r3)
  stw       r0, 0x4(r3)
  stw       r0, 0x20(r3)
  stw       r0, 0x14(r3)
  stw       r0, 0x8(r3)
  blr
*/
}
