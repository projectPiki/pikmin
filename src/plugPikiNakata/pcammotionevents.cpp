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
 * Address:	801241A8
 * Size:	0000CC
 */
PcamLongVibrationEvent::PcamLongVibrationEvent(PcamCamera *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  li        r4, 0x2
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  bl        0x1554
  lis       r3, 0x802C
  addi      r0, r3, 0x559C
  stw       r0, 0x0(r30)
  addi      r3, r30, 0x20
  bl        0x173C
  stw       r31, 0x1C(r30)
  li        r3, 0x48
  bl        -0xDD1E4
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x54
  bl        0x2984

.loc_0x54:
  stw       r31, 0x14(r30)
  li        r3, 0x48
  bl        -0xDD200
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x70
  bl        0x2968

.loc_0x70:
  stw       r31, 0x18(r30)
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r4, 0x14(r30)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r3, r30
  lwz       r4, 0x18(r30)
  lwz       r12, 0x0(r30)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  addi      r3, r30, 0x20
  lwz       r4, 0x1C(r30)
  bl        0x1714
  mr        r3, r30
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
 * Address:	80124274
 * Size:	0000D8
 */
void PcamLongVibrationEvent::makePcamLongVibrationEvent(float, float, float, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stfd      f31, 0x70(r1)
  fmr       f31, f4
  stfd      f30, 0x68(r1)
  fmr       f30, f3
  stfd      f29, 0x60(r1)
  fmr       f29, f2
  stfd      f28, 0x58(r1)
  fmr       f28, f1
  stw       r31, 0x54(r1)
  stw       r30, 0x50(r1)
  mr        r30, r3
  lwz       r4, 0x1C(r3)
  addi      r3, r1, 0x44
  addi      r5, r4, 0x14
  addi      r4, r4, 0x8
  bl        -0x7390
  mr        r31, r3
  bl        -0x71C4
  addi      r3, r1, 0x2C
  addi      r4, r31, 0
  bl        -0x8384
  mr        r31, r3
  bl        -0x82C4
  fmr       f1, f28
  addi      r31, r31, 0xC
  fmr       f2, f30
  lwz       r3, 0x14(r30)
  fmr       f3, f31
  lfs       f4, -0x5EE0(r2)
  addi      r5, r31, 0
  addi      r4, r30, 0x20
  bl        0x291C
  fneg      f0, f31
  lwz       r3, 0x18(r30)
  fmr       f1, f29
  addi      r5, r31, 0
  fmr       f2, f30
  fdivs     f4, f0, f29
  addi      r4, r30, 0x20
  fmr       f3, f31
  bl        0x28F8
  lwz       r0, 0x7C(r1)
  lfd       f31, 0x70(r1)
  lfd       f30, 0x68(r1)
  lfd       f29, 0x60(r1)
  lfd       f28, 0x58(r1)
  lwz       r31, 0x54(r1)
  lwz       r30, 0x50(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012434C
 * Size:	000078
 */
PcamVibrationEvent::PcamVibrationEvent(PcamCamera *)
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
  bl        0x2814
  lis       r3, 0x802C
  addi      r0, r3, 0x5508
  stw       r0, 0x0(r30)
  addi      r3, r30, 0x58
  bl        0x159C
  stw       r31, 0x54(r30)
  addi      r3, r30, 0x58
  lwz       r4, 0x54(r30)
  bl        0x15DC
  lfs       f0, -0x5EDC(r2)
  mr        r3, r30
  stfs      f0, 0x48(r30)
  lfs       f0, -0x5ED8(r2)
  stfs      f0, 0x4C(r30)
  lfs       f0, -0x5ED4(r2)
  stfs      f0, 0x50(r30)
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
 * Address:	801243C4
 * Size:	000084
 */
void PcamVibrationEvent::makePcamVibrationEvent()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  stw       r30, 0x40(r1)
  mr        r30, r3
  lwz       r4, 0x54(r3)
  addi      r3, r1, 0x34
  addi      r5, r4, 0x14
  addi      r4, r4, 0x8
  bl        -0x74C0
  mr        r31, r3
  bl        -0x72F4
  addi      r3, r1, 0x1C
  addi      r4, r31, 0
  bl        -0x84B4
  mr        r31, r3
  bl        -0x83F4
  lfs       f3, 0x50(r30)
  addi      r5, r31, 0xC
  lfs       f1, 0x48(r30)
  mr        r3, r30
  fneg      f0, f3
  lfs       f2, 0x4C(r30)
  addi      r4, r30, 0x58
  fdivs     f4, f0, f1
  bl        0x27EC
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80124448
 * Size:	000078
 */
PcamDamageEvent::PcamDamageEvent(PcamCamera *)
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
  bl        0x2718
  lis       r3, 0x802C
  addi      r0, r3, 0x549C
  stw       r0, 0x0(r30)
  addi      r3, r30, 0x58
  bl        0x14A0
  stw       r31, 0x54(r30)
  addi      r3, r30, 0x58
  lwz       r4, 0x54(r30)
  bl        0x14E0
  lfs       f0, -0x5EDC(r2)
  mr        r3, r30
  stfs      f0, 0x48(r30)
  lfs       f0, -0x5ED8(r2)
  stfs      f0, 0x4C(r30)
  lfs       f0, -0x5ED4(r2)
  stfs      f0, 0x50(r30)
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
 * Address:	801244C0
 * Size:	000070
 */
void PcamDamageEvent::makePcamDamageEvent()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  mr        r30, r3
  lwz       r4, 0x54(r3)
  addi      r3, r1, 0x1C
  addi      r5, r4, 0x14
  addi      r4, r4, 0x8
  bl        -0x75BC
  mr        r31, r3
  bl        -0x73F0
  lfs       f3, 0x50(r30)
  mr        r3, r30
  lfs       f1, 0x48(r30)
  mr        r5, r31
  fneg      f0, f3
  lfs       f2, 0x4C(r30)
  addi      r4, r30, 0x58
  fdivs     f4, f0, f1
  bl        0x2704
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
 * Address:	........
 * Size:	000064
 */
PcamRandomMoveEvent::PcamRandomMoveEvent(PcamCamera *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void PcamRandomMoveEvent::makePcamRandomMoveEvent()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80124530
 * Size:	000290
 */
void PcamRandomMoveEvent::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB0(r1)
  stw       r31, 0xAC(r1)
  stw       r30, 0xA8(r1)
  mr        r30, r3
  lwz       r3, 0x8(r3)
  cmplwi    r3, 0
  beq-      .loc_0x34
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      

.loc_0x34:
  addi      r3, r1, 0x6C
  bl        -0x7714
  bl        0xF3B04
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5EC0(r2)
  stw       r0, 0xA4(r1)
  lis       r31, 0x4330
  lfs       f3, -0x5ECC(r2)
  stw       r31, 0xA0(r1)
  lfs       f2, -0x5ED0(r2)
  lfd       f1, 0xA0(r1)
  lfs       f0, -0x5EC4(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x5EC8(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x6C(r1)
  bl        0xF3AC0
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5EC0(r2)
  stw       r0, 0x9C(r1)
  lfs       f3, -0x5ECC(r2)
  stw       r31, 0x98(r1)
  lfs       f2, -0x5ED0(r2)
  lfd       f1, 0x98(r1)
  lfs       f0, -0x5EC4(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x5EC8(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x70(r1)
  bl        0xF3A80
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5EC0(r2)
  stw       r0, 0x94(r1)
  lfs       f3, -0x5ECC(r2)
  stw       r31, 0x90(r1)
  lfs       f2, -0x5ED0(r2)
  lfd       f1, 0x90(r1)
  lfs       f0, -0x5EC4(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x5EC8(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x74(r1)
  lfs       f1, 0x14(r30)
  lfs       f0, 0x6C(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x6C(r1)
  lfs       f0, 0x70(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x70(r1)
  lfs       f0, 0x74(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x74(r1)
  lwz       r3, 0x24(r30)
  lfs       f0, 0x6C(r1)
  lfsu      f1, 0x8(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x0(r3)
  lfs       f1, 0x4(r3)
  lfs       f0, 0x70(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r3)
  lfs       f1, 0x8(r3)
  lfs       f0, 0x74(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r3)
  bl        0xF39E4
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5EC0(r2)
  stw       r0, 0x8C(r1)
  lfs       f3, -0x5ECC(r2)
  stw       r31, 0x88(r1)
  lfs       f2, -0x5ED0(r2)
  lfd       f1, 0x88(r1)
  lfs       f0, -0x5EC4(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x5EC8(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x6C(r1)
  bl        0xF39A4
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5EC0(r2)
  stw       r0, 0x84(r1)
  lfs       f3, -0x5ECC(r2)
  stw       r31, 0x80(r1)
  lfs       f2, -0x5ED0(r2)
  lfd       f1, 0x80(r1)
  lfs       f0, -0x5EC4(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x5EC8(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x70(r1)
  bl        0xF3964
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5EC0(r2)
  stw       r0, 0x7C(r1)
  lfs       f3, -0x5ECC(r2)
  stw       r31, 0x78(r1)
  lfs       f2, -0x5ED0(r2)
  lfd       f1, 0x78(r1)
  lfs       f0, -0x5EC4(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x5EC8(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x74(r1)
  lfs       f1, 0x14(r30)
  lfs       f0, 0x6C(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x6C(r1)
  lfs       f0, 0x70(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x70(r1)
  lfs       f0, 0x74(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x74(r1)
  lwz       r3, 0x24(r30)
  lfs       f0, 0x6C(r1)
  lfsu      f1, 0x14(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x0(r3)
  lfs       f1, 0x4(r3)
  lfs       f0, 0x70(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r3)
  lfs       f1, 0x8(r3)
  lfs       f0, 0x74(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r3)
  lwz       r0, 0xB4(r1)
  lwz       r31, 0xAC(r1)
  lwz       r30, 0xA8(r1)
  addi      r1, r1, 0xB0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801247C0
 * Size:	0000C4
 */
PcamSideVibrationEvent::PcamSideVibrationEvent(PcamCamera *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  li        r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  bl        0xD70
  lis       r3, 0x802C
  addi      r0, r3, 0x5390
  stw       r0, 0x0(r30)
  addi      r3, r30, 0x1C
  bl        0x1474
  addi      r3, r30, 0x2C
  bl        -0x8CC4
  lis       r3, 0x802C
  addi      r0, r3, 0x425C
  lis       r3, 0x802C
  stw       r0, 0x3C(r30)
  addi      r0, r3, 0x424C
  stw       r0, 0x3C(r30)
  addi      r3, r30, 0x40
  bl        -0x7A5C
  stw       r31, 0x28(r30)
  li        r3, 0x8
  bl        -0xDD824
  addi      r4, r3, 0
  addi      r3, r30, 0x3C
  li        r5, 0x2
  bl        -0x9154
  addi      r3, r30, 0x1C
  lfs       f1, -0x5EE0(r2)
  bl        0x146C
  lfs       f0, -0x5EB8(r2)
  mr        r3, r30
  stfs      f0, 0x10(r30)
  lfs       f0, -0x5ED8(r2)
  stfs      f0, 0x14(r30)
  lfs       f1, -0x1CA4(r13)
  lfs       f0, -0x5EB4(r2)
  fmuls     f0, f1, f0
  stfs      f0, 0x18(r30)
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
 * Address:	80124884
 * Size:	000070
 */
void PcamSideVibrationEvent::makePcamSideVibrationEvent()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  addi      r0, r31, 0x1C
  lfs       f0, 0x10(r3)
  addi      r3, r31, 0x2C
  stfs      f0, 0x24(r31)
  stw       r0, 0x8(r31)
  lfs       f1, -0x5EE0(r2)
  lfs       f2, 0x14(r31)
  lfs       f3, -0x5ED0(r2)
  bl        -0x8D44
  lfs       f0, 0x18(r31)
  lwz       r3, 0x40(r31)
  stfs      f0, 0x0(r3)
  lfs       f1, 0x18(r31)
  lfs       f0, 0x10(r31)
  fneg      f1, f1
  lwz       r3, 0x40(r31)
  fdivs     f0, f1, f0
  stfs      f0, 0x4(r3)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801248F4
 * Size:	000098
 */
void PcamSideVibrationEvent::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stfd      f31, 0x20(r1)
  stfd      f30, 0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lwz       r3, 0x8(r3)
  cmplwi    r3, 0
  beq-      .loc_0x38
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      

.loc_0x38:
  addi      r3, r31, 0x2C
  lfs       f30, 0x20(r31)
  lwz       r12, 0x2C(r31)
  fmr       f1, f30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  addi      r3, r31, 0x3C
  fmr       f31, f1
  lwz       r12, 0x3C(r31)
  fmr       f1, f30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  fmuls     f0, f1, f31
  lwz       r3, 0x28(r31)
  stfs      f0, 0x0(r3)
  lwz       r0, 0x2C(r1)
  lfd       f31, 0x20(r1)
  lfd       f30, 0x18(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012498C
 * Size:	000010
 */
void PcamSideVibrationEvent::finish()
{
/*
.loc_0x0:
  lfs       f0, -0x5EE0(r2)
  lwz       r3, 0x28(r3)
  stfs      f0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8012499C
 * Size:	000010
 */
void PeveEvent::setEventOption(int)
{
/*
.loc_0x0:
  lwz       r0, 0xC(r3)
  or        r0, r0, r4
  stw       r0, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801249AC
 * Size:	000010
 */
void PeveEvent::clearEventOption(int)
{
/*
.loc_0x0:
  lwz       r0, 0xC(r3)
  andc      r0, r0, r4
  stw       r0, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	801249BC
 * Size:	000008
 */
void PeveEvent::setEventOptions(int a1)
{
// Generated from stw r4, 0xC(r3)
_0C = a1;
}
