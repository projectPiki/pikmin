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
 * Address:	801436D0
 * Size:	000020
 */
void TaiTimerAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x3C
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801436F0
 * Size:	000028
 */
void TaiTimerAction::act(Teki &)
{
/*
.loc_0x0:
  lwz       r0, 0x8(r3)
  lfs       f0, -0x58F8(r2)
  rlwinm    r0,r0,2,0,29
  add       r3, r4, r0
  lfs       f1, 0x3C4(r3)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  mfcr      r0
  rlwinm    r3,r0,3,31,31
  blr
*/
}

/*
 * --INFO--
 * Address:	80143718
 * Size:	0000A8
 */
void TaiTimerAction::resetTimer(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stfd      f31, 0x38(r1)
  stfd      f30, 0x30(r1)
  stw       r31, 0x2C(r1)
  mr        r31, r4
  stw       r30, 0x28(r1)
  mr        r30, r3
  lfs       f30, 0x10(r3)
  lfs       f31, 0xC(r3)
  bl        0xD492C
  xoris     r3, r3, 0x8000
  lwz       r0, 0x8(r30)
  stw       r3, 0x24(r1)
  lis       r3, 0x4330
  rlwinm    r0,r0,2,0,29
  lfd       f1, -0x58E0(r2)
  stw       r3, 0x20(r1)
  lfs       f3, -0x58F0(r2)
  add       r3, r31, r0
  lfd       f0, 0x20(r1)
  lfs       f2, -0x58F4(r2)
  fsubs     f4, f0, f1
  lfs       f0, -0x58E8(r2)
  lfs       f1, -0x58EC(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fsubs     f0, f2, f0
  fmuls     f0, f1, f0
  fmuls     f0, f31, f0
  fmuls     f0, f30, f0
  fadds     f0, f31, f0
  stfs      f0, 0x3C4(r3)
  lwz       r0, 0x44(r1)
  lfd       f31, 0x38(r1)
  lfd       f30, 0x30(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801437C0
 * Size:	000020
 */
void TaiResetTimerAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        .loc_0x20
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr       

.loc_0x20:
*/
}

/*
 * --INFO--
 * Address:	801437E0
 * Size:	0000A8
 */
void TaiResetTimerAction::resetTimer(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stfd      f31, 0x38(r1)
  stfd      f30, 0x30(r1)
  stw       r31, 0x2C(r1)
  mr        r31, r4
  stw       r30, 0x28(r1)
  mr        r30, r3
  lfs       f30, 0x10(r3)
  lfs       f31, 0xC(r3)
  bl        0xD4864
  xoris     r3, r3, 0x8000
  lwz       r0, 0x8(r30)
  stw       r3, 0x24(r1)
  lis       r3, 0x4330
  rlwinm    r0,r0,2,0,29
  lfd       f1, -0x58E0(r2)
  stw       r3, 0x20(r1)
  lfs       f3, -0x58F0(r2)
  add       r3, r31, r0
  lfd       f0, 0x20(r1)
  lfs       f2, -0x58F4(r2)
  fsubs     f4, f0, f1
  lfs       f0, -0x58E8(r2)
  lfs       f1, -0x58EC(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fsubs     f0, f2, f0
  fmuls     f0, f1, f0
  fmuls     f0, f31, f0
  fmuls     f0, f30, f0
  fadds     f0, f31, f0
  stfs      f0, 0x3C4(r3)
  lwz       r0, 0x44(r1)
  lfd       f31, 0x38(r1)
  lfd       f30, 0x30(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80143888
 * Size:	000028
 */
void TaiTimerElapsedAction::act(Teki &)
{
/*
.loc_0x0:
  lwz       r0, 0x8(r3)
  lfs       f0, -0x58F8(r2)
  rlwinm    r0,r0,2,0,29
  add       r3, r4, r0
  lfs       f1, 0x3C4(r3)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  mfcr      r0
  rlwinm    r3,r0,3,31,31
  blr
*/
}

/*
 * --INFO--
 * Address:	801438B0
 * Size:	000084
 */
void TaiStartingTimerAction::start(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stfd      f31, 0x28(r1)
  stfd      f30, 0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r4
  stw       r30, 0x18(r1)
  mr        r30, r3
  lwz       r3, 0x3150(r13)
  lfs       f30, 0x10(r30)
  lfs       f31, 0xC(r30)
  lfs       f1, -0x58F4(r2)
  bl        .loc_0x84
  lfs       f0, -0x58E8(r2)
  lwz       r0, 0x8(r30)
  fsubs     f0, f1, f0
  lfs       f1, -0x58EC(r2)
  rlwinm    r0,r0,2,0,29
  add       r3, r31, r0
  fmuls     f0, f1, f0
  fmuls     f0, f31, f0
  fmuls     f0, f30, f0
  fadds     f0, f31, f0
  stfs      f0, 0x3C4(r3)
  lwz       r0, 0x34(r1)
  lfd       f31, 0x28(r1)
  lfd       f30, 0x20(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr       

.loc_0x84:
*/
}

/*
 * --INFO--
 * Address:	80143934
 * Size:	000054
 */
void StdSystem::getRand(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stfd      f31, 0x18(r1)
  fmr       f31, f1
  bl        0xD4728
  xoris     r0, r3, 0x8000
  lfd       f2, -0x58E0(r2)
  stw       r0, 0x14(r1)
  lis       r0, 0x4330
  lfs       f0, -0x58F0(r2)
  stw       r0, 0x10(r1)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fdivs     f0, f1, f0
  fmuls     f1, f31, f0
  lwz       r0, 0x24(r1)
  lfd       f31, 0x18(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80143988
 * Size:	000114
 */
void TaiStartingTimerAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stfd      f31, 0x50(r1)
  stfd      f30, 0x48(r1)
  stw       r31, 0x44(r1)
  stw       r30, 0x40(r1)
  addi      r30, r4, 0
  stw       r29, 0x3C(r1)
  mr        r29, r3
  lwz       r0, 0x8(r3)
  lfs       f0, -0x58F8(r2)
  rlwinm    r0,r0,2,0,29
  add       r3, r30, r0
  lfs       f1, 0x3C4(r3)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0xEC
  lfs       f31, 0x14(r29)
  bl        0xD469C
  xoris     r0, r3, 0x8000
  lfd       f3, -0x58E0(r2)
  stw       r0, 0x34(r1)
  lis       r31, 0x4330
  lfs       f1, -0x58F0(r2)
  stw       r31, 0x30(r1)
  lfs       f0, -0x58F4(r2)
  lfd       f2, 0x30(r1)
  fsubs     f2, f2, f3
  fdivs     f1, f2, f1
  fmuls     f0, f0, f1
  fcmpo     cr0, f0, f31
  bge-      .loc_0x8C
  li        r3, 0x1
  b         .loc_0xF0

.loc_0x8C:
  lfs       f30, 0x10(r29)
  lfs       f31, 0xC(r29)
  bl        0xD4654
  xoris     r3, r3, 0x8000
  lwz       r0, 0x8(r29)
  stw       r3, 0x34(r1)
  rlwinm    r0,r0,2,0,29
  lfd       f1, -0x58E0(r2)
  stw       r31, 0x30(r1)
  add       r3, r30, r0
  lfs       f3, -0x58F0(r2)
  lfd       f0, 0x30(r1)
  lfs       f2, -0x58F4(r2)
  fsubs     f4, f0, f1
  lfs       f0, -0x58E8(r2)
  lfs       f1, -0x58EC(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fsubs     f0, f2, f0
  fmuls     f0, f1, f0
  fmuls     f0, f31, f0
  fmuls     f0, f30, f0
  fadds     f0, f31, f0
  stfs      f0, 0x3C4(r3)

.loc_0xEC:
  li        r3, 0

.loc_0xF0:
  lwz       r0, 0x5C(r1)
  lfd       f31, 0x50(r1)
  lfd       f30, 0x48(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  lwz       r29, 0x3C(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}
