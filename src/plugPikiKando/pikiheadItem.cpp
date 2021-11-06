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
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800EC4C8
 * Size:	000060
 */
void PikiHeadItem::startWaterEffect()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  addi      r0, r3, 0x94
  stwu      r1, -0x38(r1)
  lfs       f1, -0x6568(r2)
  addi      r4, r1, 0xC
  lfs       f0, -0x6564(r2)
  stfs      f1, 0x14(r1)
  stfs      f1, 0x10(r1)
  stfs      f1, 0xC(r1)
  stfs      f1, 0x20(r1)
  stfs      f1, 0x1C(r1)
  stfs      f1, 0x18(r1)
  stw       r0, 0x2C(r1)
  stfs      f0, 0x30(r1)
  lwz       r3, 0x3F4(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EC528
 * Size:	000030
 */
void PikiHeadItem::finishWaterEffect()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x3F4(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x30(r12)
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
 * Address:	800EC558
 * Size:	000074
 */
void PikiHeadItem::playSound(int)
{
/*
.loc_0x0:
  mflr      r0
  mr        r6, r3
  stw       r0, 0x4(r1)
  addi      r5, r4, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  lwz       r0, 0x3E0(r3)
  cmplwi    r0, 0
  beq-      .loc_0x38
  addi      r3, r6, 0
  mr        r4, r0
  addi      r5, r5, 0xCC
  bl        -0x61FD4
  b         .loc_0x60

.loc_0x38:
  cmpwi     r5, 0
  ble-      .loc_0x60
  addi      r31, r5, 0x108
  lwz       r3, 0x3038(r13)
  addi      r4, r31, 0
  addi      r5, r6, 0x94
  bl        -0x481A0
  lwz       r3, 0x3038(r13)
  mr        r4, r31
  bl        -0x472F0

.loc_0x60:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EC5CC
 * Size:	000058
 */
void PikiHeadItem::canPullout()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x120(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  beq-      .loc_0x2C
  lwz       r3, 0x4(r3)
  b         .loc_0x30

.loc_0x2C:
  li        r3, -0x1

.loc_0x30:
  subi      r0, r3, 0x6
  cmplwi    r0, 0x2
  bgt-      .loc_0x44
  li        r3, 0x1
  b         .loc_0x48

.loc_0x44:
  li        r3, 0

.loc_0x48:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EC624
 * Size:	000008
 */
u32  PikiHeadItem::isVisible()
{
	return 0x1;
}

/*
 * --INFO--
 * Address:	800EC62C
 * Size:	000068
 */
void PikiHeadItem::needShadow()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x120(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  beq-      .loc_0x2C
  lwz       r3, 0x4(r3)
  b         .loc_0x30

.loc_0x2C:
  li        r3, -0x1

.loc_0x30:
  cmpwi     r3, 0x3
  beq-      .loc_0x4C
  cmpwi     r3, 0xE
  beq-      .loc_0x4C
  subi      r0, r3, 0xB
  cmplwi    r0, 0x1
  bgt-      .loc_0x54

.loc_0x4C:
  li        r3, 0
  b         .loc_0x58

.loc_0x54:
  li        r3, 0x1

.loc_0x58:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EC694
 * Size:	000008
 */
u32  PikiHeadItem::isAlive()
{
	return 0x1;
}

/*
 * --INFO--
 * Address:	800EC69C
 * Size:	00018C
 */
PikiHeadItem::PikiHeadItem(CreatureProp *, ItemShapeObject *, SimpleAI *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r5, 0
  addi      r5, r4, 0
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  li        r4, 0xF
  stw       r29, 0x1C(r1)
  addi      r29, r6, 0
  li        r6, 0
  bl        0x91E0
  lis       r3, 0x802C
  subi      r3, r3, 0x31CC
  stw       r3, 0x0(r30)
  addi      r0, r3, 0x114
  addi      r3, r30, 0x3E4
  stw       r0, 0x2B8(r30)
  lfs       f0, -0x6568(r2)
  stfs      f0, 0x3DC(r30)
  stfs      f0, 0x3D8(r30)
  stfs      f0, 0x3D4(r30)
  bl        0x27C70
  stw       r31, 0x3C0(r30)
  li        r31, 0
  li        r3, 0x18
  stw       r29, 0x2E8(r30)
  stw       r31, 0x3CC(r30)
  stw       r31, 0x3D0(r30)
  stw       r31, 0x3E0(r30)
  bl        -0xA5714
  cmplwi    r3, 0
  beq-      .loc_0xE8
  lis       r4, 0x802B
  addi      r0, r4, 0x600
  lis       r4, 0x802B
  stw       r0, 0x0(r3)
  addi      r0, r4, 0x5F4
  lis       r4, 0x802B
  stw       r0, 0x4(r3)
  addi      r0, r4, 0x5E8
  lis       r4, 0x802B
  stw       r0, 0x8(r3)
  addi      r6, r4, 0x5AC
  stw       r6, 0x0(r3)
  addi      r0, r6, 0xC
  lis       r4, 0x802C
  stw       r0, 0x4(r3)
  addi      r5, r4, 0x26D0
  addi      r0, r6, 0x18
  stw       r0, 0x8(r3)
  addi      r4, r5, 0xC
  addi      r0, r5, 0x18
  stw       r5, 0x0(r3)
  stw       r4, 0x4(r3)
  stw       r0, 0x8(r3)
  stw       r31, 0x10(r3)

.loc_0xE8:
  stw       r3, 0x3C8(r30)
  li        r3, 0x18
  bl        -0xA5788
  cmplwi    r3, 0
  beq-      .loc_0x168
  lis       r4, 0x802B
  addi      r0, r4, 0x600
  lis       r4, 0x802B
  stw       r0, 0x0(r3)
  addi      r0, r4, 0x5F4
  lis       r4, 0x802B
  stw       r0, 0x4(r3)
  addi      r0, r4, 0x5E8
  lis       r4, 0x802B
  stw       r0, 0x8(r3)
  addi      r5, r4, 0x5AC
  stw       r5, 0x0(r3)
  addi      r0, r5, 0xC
  lis       r4, 0x802C
  stw       r0, 0x4(r3)
  addi      r6, r4, 0x2660
  addi      r0, r5, 0x18
  stw       r0, 0x8(r3)
  addi      r5, r6, 0xC
  addi      r4, r6, 0x18
  stw       r6, 0x0(r3)
  li        r0, 0
  stw       r5, 0x4(r3)
  stw       r4, 0x8(r3)
  stw       r0, 0xC(r3)
  stw       r0, 0x14(r3)
  stw       r0, 0x10(r3)

.loc_0x168:
  stw       r3, 0x3F4(r30)
  mr        r3, r30
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
 * Address:	800EC828
 * Size:	000150
 */
void PikiHeadItem::startAI(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x68(r1)
  stw       r31, 0x64(r1)
  mr        r31, r3
  lwz       r4, 0xC8(r3)
  addi      r3, r1, 0x1C
  oris      r4, r4, 0x4
  stw       r4, 0xC8(r31)
  li        r4, 0
  stw       r0, 0x3E0(r31)
  bl        0x32700
  addi      r4, r3, 0
  addi      r3, r31, 0x36C
  bl        0x3295C
  lfs       f0, -0x6564(r2)
  stfs      f0, 0x7C(r31)
  stfs      f0, 0x80(r31)
  stfs      f0, 0x84(r31)
  bl        0x12B7F8
  xoris     r3, r3, 0x8000
  lwz       r0, 0xC8(r31)
  stw       r3, 0x5C(r1)
  lis       r3, 0x4330
  lfd       f3, -0x6550(r2)
  ori       r0, r0, 0x10
  stw       r3, 0x58(r1)
  lfs       f0, -0x6560(r2)
  mr        r4, r31
  lfd       f1, 0x58(r1)
  li        r5, 0x6
  lfs       f2, -0x6564(r2)
  fsubs     f1, f1, f3
  stw       r0, 0xC8(r31)
  fdivs     f3, f1, f0
  lfs       f0, -0x6558(r2)
  lfs       f1, -0x655C(r2)
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fsubs     f0, f1, f0
  stfs      f0, 0xCC(r31)
  lwz       r3, 0x2E8(r31)
  bl        -0x6F17C
  lwz       r4, 0x3CC(r31)
  lis       r3, 0x803D
  addi      r0, r3, 0x1E94
  rlwinm    r3,r4,2,0,29
  add       r4, r0, r3
  lwz       r3, 0x0(r4)
  addi      r0, r3, 0x1
  stw       r0, 0x0(r4)
  bl        0x25C68
  lwz       r5, 0x94(r31)
  addi      r0, r31, 0x3D4
  lwz       r3, 0x98(r31)
  addi      r4, r1, 0x24
  stw       r5, 0x3D4(r31)
  stw       r3, 0x3D8(r31)
  lwz       r3, 0x9C(r31)
  stw       r3, 0x3DC(r31)
  lwz       r5, 0x3CC(r31)
  lwz       r3, 0x3C8(r31)
  sth       r5, 0xC(r3)
  lfs       f1, -0x6568(r2)
  lfs       f0, -0x6564(r2)
  stfs      f1, 0x2C(r1)
  stfs      f1, 0x28(r1)
  stfs      f1, 0x24(r1)
  stfs      f1, 0x38(r1)
  stfs      f1, 0x34(r1)
  stfs      f1, 0x30(r1)
  stw       r0, 0x44(r1)
  stfs      f0, 0x48(r1)
  lwz       r3, 0x3C8(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x6C(r1)
  lwz       r31, 0x64(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EC978
 * Size:	00008C
 */
void PikiHeadItem::setPermanentEffects(bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm.   r0,r4,0,24,31
  stwu      r1, -0x40(r1)
  beq-      .loc_0x68
  lwz       r6, 0x3CC(r3)
  addi      r0, r3, 0x3D4
  lwz       r5, 0x3C8(r3)
  addi      r4, r1, 0x10
  sth       r6, 0xC(r5)
  lfs       f1, -0x6568(r2)
  lfs       f0, -0x6564(r2)
  stfs      f1, 0x18(r1)
  stfs      f1, 0x14(r1)
  stfs      f1, 0x10(r1)
  stfs      f1, 0x24(r1)
  stfs      f1, 0x20(r1)
  stfs      f1, 0x1C(r1)
  stw       r0, 0x30(r1)
  stfs      f0, 0x34(r1)
  lwz       r3, 0x3C8(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      
  b         .loc_0x7C

.loc_0x68:
  lwz       r3, 0x3C8(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      

.loc_0x7C:
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ECA04
 * Size:	00008C
 */
void PikiHeadItem::doKill()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  bl        0x9164
  lwz       r0, 0x3CC(r31)
  lis       r4, 0x803D
  lis       r3, 0x803D
  rlwinm    r5,r0,2,0,29
  addi      r0, r4, 0x1E94
  add       r5, r0, r5
  lwz       r4, 0x0(r5)
  addi      r0, r3, 0x1E88
  subi      r3, r4, 0x1
  stw       r3, 0x0(r5)
  lwz       r3, 0x3CC(r31)
  rlwinm    r3,r3,2,0,29
  add       r4, r0, r3
  lwz       r3, 0x0(r4)
  addi      r0, r3, 0x1
  stw       r0, 0x0(r4)
  bl        0x25B04
  lwz       r3, 0x3C8(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  addi      r3, r31, 0x3E4
  bl        0x27A9C
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ECA90
 * Size:	000008
 */
void PikiHeadItem::getSize()
{
/*
.loc_0x0:
  lfs       f1, -0x6548(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	800ECA98
 * Size:	000008
 */
void PikiHeadItem::getiMass()
{
/*
.loc_0x0:
  lfs       f1, -0x6544(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	800ECAA0
 * Size:	000008
 */
void PikiHeadItem::setColor(int a1)
{
// Generated from stw r4, 0x3CC(r3)
_3CC = a1;
}

/*
 * --INFO--
 * Address:	800ECAA8
 * Size:	00054C
 */
void PikiHeadItem::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xD8(r1)
  stw       r31, 0xD4(r1)
  addi      r31, r4, 0
  stw       r30, 0xD0(r1)
  addi      r30, r3, 0
  lfs       f0, -0x6564(r2)
  stfs      f0, 0x7C(r3)
  stfs      f0, 0x80(r3)
  stfs      f0, 0x84(r3)
  lwz       r3, 0x2F00(r13)
  lfs       f1, 0x94(r30)
  lfs       f2, 0x9C(r30)
  bl        -0x84D48
  lwz       r0, 0x3C0(r30)
  cmplwi    r0, 0
  beq-      .loc_0x430
  addi      r3, r30, 0x228
  addi      r4, r30, 0x7C
  addi      r5, r30, 0x88
  addi      r6, r30, 0x94
  bl        -0xAEA0C
  lwz       r3, 0x3C0(r30)
  lis       r4, 0x803D
  lwz       r5, 0x3CC(r30)
  addi      r0, r4, 0x1E18
  lwz       r3, 0x0(r3)
  rlwinm    r4,r5,2,0,29
  lwz       r5, 0x44(r3)
  add       r4, r0, r4
  lwz       r0, 0x4C(r5)
  rlwinm.   r0,r0,0,30,30
  beq-      .loc_0xBC
  lbz       r0, 0x0(r4)
  lwz       r3, 0x90(r5)
  sth       r0, 0x0(r3)
  lbz       r0, 0x1(r4)
  lwz       r3, 0x90(r5)
  sth       r0, 0x2(r3)
  lbz       r0, 0x2(r4)
  lwz       r3, 0x90(r5)
  sth       r0, 0x4(r3)
  lbz       r0, 0x3(r4)
  lwz       r3, 0x90(r5)
  sth       r0, 0x6(r3)
  b         .loc_0xC4

.loc_0xBC:
  lwz       r0, 0x0(r4)
  stw       r0, 0x2C(r5)

.loc_0xC4:
  lwz       r0, 0xC8(r30)
  rlwinm.   r0,r0,0,29,29
  bne-      .loc_0x3B8
  lfs       f1, 0x70(r30)
  lfs       f0, 0x74(r30)
  fmuls     f2, f1, f1
  lfs       f3, 0x78(r30)
  fmuls     f1, f0, f0
  lfs       f0, -0x6568(r2)
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x154
  fsqrte    f1, f4
  lfd       f3, -0x6540(r2)
  lfd       f2, -0x6538(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f4, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f4, f0
  frsp      f0, f0
  stfs      f0, 0x28(r1)
  lfs       f4, 0x28(r1)

.loc_0x154:
  lfs       f0, -0x6568(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0x3B8
  lfs       f0, 0x70(r30)
  stfs      f0, 0x78(r1)
  lfs       f0, 0x74(r30)
  stfs      f0, 0x7C(r1)
  lfs       f0, 0x78(r30)
  stfs      f0, 0x80(r1)
  lfs       f1, 0x78(r1)
  lfs       f0, 0x7C(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x80(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0xDF000
  lfs       f0, -0x6568(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x1CC
  lfs       f0, 0x78(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x78(r1)
  lfs       f0, 0x7C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x7C(r1)
  lfs       f0, 0x80(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x80(r1)

.loc_0x1CC:
  lfs       f4, -0x3400(r13)
  lfs       f0, 0x78(r1)
  lfs       f1, 0x7C(r1)
  fmuls     f0, f0, f4
  lfs       f2, 0x80(r1)
  fmuls     f3, f1, f4
  fmuls     f1, f2, f4
  stfs      f0, 0x78(r1)
  stfs      f3, 0x7C(r1)
  stfs      f1, 0x80(r1)
  lfs       f1, -0x33FC(r13)
  lfs       f0, -0x33F8(r13)
  stfs      f1, 0x6C(r1)
  stfs      f0, 0x70(r1)
  lfs       f0, -0x33F4(r13)
  stfs      f0, 0x74(r1)
  lfs       f0, 0x78(r1)
  stfs      f0, 0x60(r1)
  lfs       f0, 0x7C(r1)
  stfs      f0, 0x64(r1)
  lfs       f0, 0x80(r1)
  stfs      f0, 0x68(r1)
  lfs       f1, 0x68(r1)
  lfs       f6, 0x70(r1)
  lfs       f5, 0x6C(r1)
  lfs       f7, 0x64(r1)
  fmuls     f0, f1, f6
  lfs       f3, 0x74(r1)
  fmuls     f4, f1, f5
  lfs       f2, 0x60(r1)
  fmuls     f1, f7, f3
  fmuls     f3, f2, f3
  fmuls     f2, f2, f6
  fsubs     f0, f1, f0
  fmuls     f1, f7, f5
  fsubs     f3, f4, f3
  stfs      f0, 0x60(r1)
  fsubs     f0, f2, f1
  stfs      f3, 0x64(r1)
  stfs      f0, 0x68(r1)
  lfs       f1, 0x60(r1)
  lfs       f0, 0x64(r1)
  lfs       f2, 0x68(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0xDF0F4
  lfs       f0, -0x6568(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x2C0
  lfs       f0, 0x60(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x60(r1)
  lfs       f0, 0x64(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x64(r1)
  lfs       f0, 0x68(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x68(r1)

.loc_0x2C0:
  lwz       r0, 0x60(r1)
  lwz       r3, 0x64(r1)
  stw       r0, 0x6C(r1)
  lwz       r0, 0x68(r1)
  stw       r3, 0x70(r1)
  lfs       f5, 0x78(r1)
  stw       r0, 0x74(r1)
  lfs       f0, 0x74(r1)
  lfs       f6, 0x7C(r1)
  lfs       f7, 0x70(r1)
  fmuls     f4, f0, f5
  lfs       f3, 0x80(r1)
  fmuls     f0, f0, f6
  lfs       f2, 0x6C(r1)
  fmuls     f1, f7, f3
  fmuls     f3, f2, f3
  fmuls     f2, f2, f6
  fsubs     f0, f1, f0
  fmuls     f1, f7, f5
  fsubs     f3, f4, f3
  stfs      f0, 0x6C(r1)
  fsubs     f0, f2, f1
  stfs      f3, 0x70(r1)
  stfs      f0, 0x74(r1)
  lfs       f1, 0x6C(r1)
  lfs       f0, 0x70(r1)
  lfs       f2, 0x74(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0xDF1A8
  lfs       f0, -0x6568(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x374
  lfs       f0, 0x6C(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x6C(r1)
  lfs       f0, 0x70(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x70(r1)
  lfs       f0, 0x74(r1)
  fdivs     f0, f0, f1
  stfs      f0, 0x74(r1)

.loc_0x374:
  addi      r3, r1, 0x60
  addi      r4, r1, 0x78
  addi      r5, r1, 0x6C
  addi      r6, r30, 0x114
  bl        0x258F4
  lfs       f0, 0x94(r30)
  addi      r4, r30, 0x114
  addi      r5, r1, 0x84
  stfs      f0, 0x120(r30)
  lfs       f0, 0x98(r30)
  stfs      f0, 0x130(r30)
  lfs       f0, 0x9C(r30)
  stfs      f0, 0x140(r30)
  lwz       r3, 0x2E4(r31)
  addi      r3, r3, 0x1E0
  bl        -0xAED84
  b         .loc_0x3CC

.loc_0x3B8:
  lwz       r3, 0x2E4(r31)
  addi      r4, r30, 0x228
  addi      r5, r1, 0x84
  addi      r3, r3, 0x1E0
  bl        -0xAED9C

.loc_0x3CC:
  addi      r3, r30, 0x36C
  lwz       r12, 0x39C(r30)
  lwz       r12, 0x18(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x3C0(r30)
  addi      r4, r31, 0
  addi      r5, r1, 0x84
  lwz       r3, 0x0(r3)
  li        r6, 0
  bl        -0xB7B88
  lwz       r12, 0x3B4(r31)
  lis       r4, 0x803A
  mr        r3, r31
  lwz       r12, 0x74(r12)
  subi      r4, r4, 0x77C0
  li        r5, 0
  mtlr      r12
  blrl      
  lwz       r3, 0x3C0(r30)
  mr        r4, r31
  lwz       r5, 0x2E4(r31)
  li        r6, 0
  lwz       r3, 0x0(r3)
  bl        -0xBCA68

.loc_0x430:
  lwz       r3, 0x3C0(r30)
  li        r4, 0x3
  lwz       r3, 0x0(r3)
  bl        -0xB7EFC
  lwz       r12, 0x3B4(r31)
  addi      r4, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x74(r12)
  li        r5, 0
  mtlr      r12
  blrl      
  lfs       f0, -0x6568(r2)
  stfs      f0, 0x5C(r1)
  stfs      f0, 0x58(r1)
  stfs      f0, 0x54(r1)
  lwz       r0, 0x3D0(r30)
  cmpwi     r0, 0x1
  bne-      .loc_0x494
  lfs       f1, -0x33F0(r13)
  lfs       f0, -0x33EC(r13)
  stfs      f1, 0x54(r1)
  stfs      f0, 0x58(r1)
  lfs       f0, -0x33E8(r13)
  stfs      f0, 0x5C(r1)
  b         .loc_0x4D0

.loc_0x494:
  cmpwi     r0, 0x2
  bne-      .loc_0x4B8
  lfs       f1, -0x33E4(r13)
  lfs       f0, -0x33E0(r13)
  stfs      f1, 0x54(r1)
  stfs      f0, 0x58(r1)
  lfs       f0, -0x33DC(r13)
  stfs      f0, 0x5C(r1)
  b         .loc_0x4D0

.loc_0x4B8:
  lfs       f1, -0x33D8(r13)
  lfs       f0, -0x33D4(r13)
  stfs      f1, 0x54(r1)
  stfs      f0, 0x58(r1)
  lfs       f0, -0x33D0(r13)
  stfs      f0, 0x5C(r1)

.loc_0x4D0:
  lwz       r3, 0x3C0(r30)
  addi      r4, r31, 0
  addi      r6, r1, 0x54
  lwz       r3, 0x0(r3)
  li        r5, 0x3
  bl        -0xB76C8
  lfs       f0, -0x6530(r2)
  lwz       r3, 0x3C8(r30)
  fmuls     f1, f0, f1
  bl        0x2767C
  lwz       r3, 0x54(r1)
  mr        r4, r31
  lwz       r0, 0x58(r1)
  li        r6, 0
  stw       r3, 0x3D4(r30)
  stw       r0, 0x3D8(r30)
  lwz       r0, 0x5C(r1)
  stw       r0, 0x3DC(r30)
  lwz       r0, 0x3D0(r30)
  lwz       r3, 0x3068(r13)
  rlwinm    r0,r0,2,0,29
  lwz       r5, 0x2E4(r31)
  add       r3, r3, r0
  lwz       r3, 0x3C(r3)
  bl        -0xBCB6C
  lwz       r0, 0xDC(r1)
  lwz       r31, 0xD4(r1)
  lwz       r30, 0xD0(r1)
  addi      r1, r1, 0xD8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800ECFF4
 * Size:	000108
 */
void PikiHeadItem::interactBikkuri(InteractBikkuri &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  li        r30, 0x1
  stw       r29, 0x14(r1)
  stw       r28, 0x10(r1)
  addi      r28, r3, 0
  stb       r30, 0x306D(r13)
  lwz       r3, 0x3068(r13)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x78(r12)
  mtlr      r12
  blrl      
  li        r31, 0
  mr.       r29, r3
  stb       r31, 0x306D(r13)
  beq-      .loc_0xE4
  lwz       r3, 0x3120(r13)
  bl        0x2A380
  addi      r4, r3, 0
  addi      r3, r29, 0
  bl        -0x2100C
  mr        r3, r29
  lwz       r4, 0x3CC(r28)
  bl        -0x237E4
  mr        r3, r29
  lwz       r4, 0x3D0(r28)
  lwz       r12, 0x0(r29)
  lwz       r12, 0x130(r12)
  mtlr      r12
  blrl      
  mr        r3, r29
  lwz       r12, 0x0(r29)
  addi      r4, r28, 0x94
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      
  stb       r30, 0x306E(r13)
  addi      r3, r29, 0
  li        r4, 0
  li        r5, 0
  bl        -0x1FED4
  stb       r31, 0x306E(r13)
  addi      r4, r29, 0
  li        r5, 0x5
  lwz       r3, 0x490(r29)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  addi      r3, r28, 0
  li        r4, 0
  bl        -0x623EC
  li        r3, 0x1
  b         .loc_0xE8

.loc_0xE4:
  li        r3, 0

.loc_0xE8:
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
 * Address:	800ED0FC
 * Size:	000100
 */
void PikiHeadItem::interactSwallow(InteractSwallow &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r4
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  stb       r0, 0x306D(r13)
  lwz       r3, 0x3068(r13)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x78(r12)
  mtlr      r12
  blrl      
  li        r0, 0
  mr.       r31, r3
  stb       r0, 0x306D(r13)
  beq-      .loc_0xE0
  lwz       r3, 0x3120(r13)
  bl        0x2A278
  addi      r4, r3, 0
  addi      r3, r31, 0
  bl        -0x21114
  mr        r3, r31
  lwz       r4, 0x3CC(r29)
  bl        -0x238EC
  mr        r3, r31
  lwz       r4, 0x3D0(r29)
  lwz       r12, 0x0(r31)
  lwz       r12, 0x130(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  addi      r4, r29, 0x94
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x490(r31)
  addi      r4, r31, 0
  li        r5, 0x5
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  addi      r3, r29, 0
  li        r4, 0
  bl        -0x624DC
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r31
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  b         .loc_0xE4

.loc_0xE0:
  li        r3, 0

.loc_0xE4:
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
 * Address:	800ED1FC
 * Size:	000008
 */
u32  PikiHeadItem::isAtari()
{
	return 0x0;
}
