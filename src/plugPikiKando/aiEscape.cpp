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
 * Address:	800B8828
 * Size:	00007C
 */
ActEscape::ActEscape(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r3, 0x8(r1)
  lwz       r3, 0x8(r1)
  bl        0xB588
  lis       r3, 0x802B
  lwz       r30, 0x8(r1)
  addi      r0, r3, 0x6654
  stw       r0, 0x0(r30)
  li        r31, 0
  stw       r31, 0x14(r30)
  lfs       f0, -0x6DF0(r2)
  stfs      f0, 0x2C(r30)
  stfs      f0, 0x28(r30)
  stfs      f0, 0x24(r30)
  lwz       r3, 0x14(r30)
  cmplwi    r3, 0
  beq-      .loc_0x60
  bl        0x2BAEC
  stw       r31, 0x14(r30)

.loc_0x60:
  lwz       r3, 0x8(r1)
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
 * Address:	800B88A4
 * Size:	000004
 */
void ActEscape::Initialiser::initialise(Action *)
{
}

/*
 * --INFO--
 * Address:	800B88A8
 * Size:	0000F8
 */
void ActEscape::init(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r4, 0
  stw       r30, 0x30(r1)
  addi      r30, r3, 0
  bl        0x15F7AC
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6DD8(r2)
  stw       r0, 0x2C(r1)
  lis       r0, 0x4330
  lfs       f3, -0x6DE8(r2)
  stw       r0, 0x28(r1)
  lfs       f2, -0x6DEC(r2)
  lfd       f1, 0x28(r1)
  lfs       f0, -0x6DE0(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x6DE4(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fadds     f0, f1, f0
  stfs      f0, 0x18(r30)
  lwz       r3, 0x14(r30)
  cmplwi    r3, 0
  beq-      .loc_0x7C
  beq-      .loc_0x7C
  bl        0x2BA54
  li        r0, 0
  stw       r0, 0x14(r30)

.loc_0x7C:
  stw       r31, 0x14(r30)
  lwz       r3, 0x14(r30)
  cmplwi    r3, 0
  beq-      .loc_0x90
  bl        0x2BA28

.loc_0x90:
  li        r0, 0
  stw       r0, 0x20(r30)
  addi      r3, r1, 0x14
  li        r4, 0x1
  lwz       r5, 0xC(r30)
  lfs       f0, -0x4A30(r13)
  stfsu     f0, 0xA4(r5)
  lfs       f0, -0x4A2C(r13)
  stfs      f0, 0x4(r5)
  lfs       f0, -0x4A28(r13)
  stfs      f0, 0x8(r5)
  bl        0x665F4
  addi      r31, r3, 0
  addi      r3, r1, 0x1C
  li        r4, 0x1
  bl        0x665E4
  mr        r4, r3
  lwz       r3, 0xC(r30)
  mr        r5, r31
  bl        0x12054
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800B89A0
 * Size:	000040
 */
void ActEscape::cleanup()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lwz       r3, 0x14(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2C
  bl        0x2B9AC
  li        r0, 0
  stw       r0, 0x14(r31)

.loc_0x2C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800B89E0
 * Size:	0002CC
 */
void ActEscape::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB0(r1)
  stfd      f31, 0xA8(r1)
  stfd      f30, 0xA0(r1)
  stw       r31, 0x9C(r1)
  stw       r30, 0x98(r1)
  mr        r30, r3
  lwz       r31, 0x14(r3)
  lwz       r12, 0x0(r31)
  mr        r3, r31
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x48
  li        r3, 0x1
  b         .loc_0x2AC

.loc_0x48:
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x18(r30)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x18(r30)
  lfs       f1, 0x18(r30)
  lfs       f0, -0x6DF0(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x74
  li        r3, 0x2
  b         .loc_0x2AC

.loc_0x74:
  lfs       f0, -0x6DD0(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x84
  stfs      f0, 0x18(r30)

.loc_0x84:
  lwz       r0, 0x20(r30)
  cmpwi     r0, 0x1
  beq-      .loc_0x258
  bge-      .loc_0x2A8
  cmpwi     r0, 0
  bge-      .loc_0xA0
  b         .loc_0x2A8

.loc_0xA0:
  lwz       r3, 0xC(r30)
  lfsu      f1, 0x94(r3)
  lfs       f0, 0x94(r31)
  lfs       f3, 0x4(r3)
  lfs       f2, 0x98(r31)
  fsubs     f0, f1, f0
  lfs       f4, 0x8(r3)
  lfs       f1, 0x9C(r31)
  fsubs     f2, f3, f2
  stfs      f0, 0x80(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x84(r1)
  stfs      f0, 0x88(r1)
  lfs       f1, 0x80(r1)
  lfs       f3, 0x88(r1)
  lfs       f0, 0x84(r1)
  fmuls     f2, f1, f1
  fmuls     f3, f3, f3
  fmuls     f1, f0, f0
  lfs       f0, -0x6DF0(r2)
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x158
  fsqrte    f1, f4
  lfd       f3, -0x6DC8(r2)
  lfd       f2, -0x6DC0(r2)
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
  stfs      f0, 0x38(r1)
  lfs       f4, 0x38(r1)

.loc_0x158:
  lfs       f0, -0x6DF0(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0x194
  lfs       f1, -0x6DEC(r2)
  lfs       f0, 0x80(r1)
  fdivs     f3, f1, f4
  lfs       f1, 0x84(r1)
  lfs       f2, 0x88(r1)
  fmuls     f0, f0, f3
  fmuls     f4, f1, f3
  fmuls     f1, f2, f3
  stfs      f0, 0x80(r1)
  stfs      f4, 0x84(r1)
  stfs      f1, 0x88(r1)
  b         .loc_0x1F8

.loc_0x194:
  bl        0x15F4FC
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6DD8(r2)
  stw       r0, 0x94(r1)
  lis       r0, 0x4330
  lfs       f3, -0x6DE8(r2)
  stw       r0, 0x90(r1)
  lfs       f2, -0x6DEC(r2)
  lfd       f1, 0x90(r1)
  lfs       f0, -0x6DB8(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x6DE0(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fmuls     f30, f1, f0
  fmr       f1, f30
  bl        0x163130
  fmr       f31, f1
  fmr       f1, f30
  bl        0x162F90
  stfs      f1, 0x80(r1)
  lfs       f0, -0x4A24(r13)
  stfs      f0, 0x84(r1)
  stfs      f31, 0x88(r1)

.loc_0x1F8:
  lwz       r3, 0xC(r30)
  addi      r4, r1, 0x80
  lfs       f1, -0x6DEC(r2)
  bl        0x131F4
  lwz       r3, 0xC(r30)
  addi      r5, r30, 0x24
  addi      r4, r3, 0xA4
  bl        -0x2B6B8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2A8
  li        r0, 0x1
  stw       r0, 0x20(r30)
  addi      r4, r1, 0x64
  lfs       f1, 0x2C(r30)
  lfs       f0, -0x4A20(r13)
  fneg      f2, f1
  lfs       f1, -0x6DEC(r2)
  stfs      f2, 0x64(r1)
  stfs      f0, 0x68(r1)
  lfs       f0, 0x24(r30)
  stfs      f0, 0x6C(r1)
  lwz       r3, 0xC(r30)
  bl        0x131A8
  b         .loc_0x2A8

.loc_0x258:
  lwz       r3, 0xC(r30)
  addi      r5, r30, 0x24
  addi      r4, r3, 0xA4
  bl        -0x2B708
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2A0
  lfs       f1, 0x2C(r30)
  addi      r4, r1, 0x58
  lfs       f0, -0x4A1C(r13)
  fneg      f2, f1
  lfs       f1, -0x6DEC(r2)
  stfs      f2, 0x58(r1)
  stfs      f0, 0x5C(r1)
  lfs       f0, 0x24(r30)
  stfs      f0, 0x60(r1)
  lwz       r3, 0xC(r30)
  bl        0x13160
  b         .loc_0x2A8

.loc_0x2A0:
  li        r0, 0
  stw       r0, 0x20(r30)

.loc_0x2A8:
  li        r3, 0

.loc_0x2AC:
  lwz       r0, 0xB4(r1)
  lfd       f31, 0xA8(r1)
  lfd       f30, 0xA0(r1)
  lwz       r31, 0x9C(r1)
  lwz       r30, 0x98(r1)
  addi      r1, r1, 0xB0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800B8CAC
 * Size:	000058
 */
void ActEscape::getInfo(char *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x20(r3)
  cmpwi     r0, 0
  bne-      .loc_0x20
  subi      r5, r13, 0x4A18
  b         .loc_0x24

.loc_0x20:
  subi      r5, r13, 0x4A10

.loc_0x24:
  lwz       r6, 0xC(r3)
  lis       r3, 0x802B
  addi      r0, r3, 0x6604
  crset     6, 0x6
  lfs       f1, 0xA4(r6)
  addi      r3, r4, 0
  lfs       f2, 0xAC(r6)
  mr        r4, r0
  bl        0x15D8A8
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800B8D04
 * Size:	000064
 */
ActEscape::~ActEscape()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  mr.       r30, r3
  beq-      .loc_0x48
  lis       r3, 0x802B
  addi      r0, r3, 0x6654
  stw       r0, 0x0(r30)
  addi      r3, r30, 0
  li        r4, 0
  bl        0xB0D0
  extsh.    r0, r31
  ble-      .loc_0x48
  mr        r3, r30
  bl        -0x71B9C

.loc_0x48:
  mr        r3, r30
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
