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
 * Address:	800A79F8
 * Size:	000080
 */
ActPick::ActPick(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r3, 0x8(r1)
  lwz       r3, 0x8(r1)
  bl        0x1C3B8
  lis       r3, 0x802B
  lwz       r30, 0x8(r1)
  subi      r0, r3, 0x246C
  lis       r3, 0x802B
  stw       r0, 0x14(r30)
  addi      r3, r3, 0x527C
  stw       r3, 0x0(r30)
  addi      r0, r3, 0x64
  li        r31, 0
  stw       r0, 0x14(r30)
  stw       r31, 0x18(r30)
  lwz       r3, 0x18(r30)
  cmplwi    r3, 0
  beq-      .loc_0x64
  bl        0x3C918
  stw       r31, 0x18(r30)

.loc_0x64:
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
 * Address:	800A7A78
 * Size:	000004
 */
void ActPick::Initialiser::initialise(Action *)
{
}

/*
 * --INFO--
 * Address:	800A7A7C
 * Size:	0000D4
 */
void ActPick::animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  lwz       r0, 0x0(r4)
  cmpwi     r0, 0x1
  beq-      .loc_0x34
  bge-      .loc_0xBC
  cmpwi     r0, 0
  bge-      .loc_0xB4
  b         .loc_0xBC

.loc_0x34:
  lwz       r0, 0x18(r30)
  cmplwi    r0, 0
  mr        r31, r0
  beq-      .loc_0xBC
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xBC
  mr        r3, r31
  lwz       r4, 0xC(r30)
  bl        -0x1AC68
  lfs       f0, -0x71A0(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xBC
  lis       r3, 0x802B
  lwz       r5, 0xC(r30)
  subi      r0, r3, 0x3064
  stw       r0, 0x18(r1)
  lis       r3, 0x802B
  subi      r0, r3, 0x2E2C
  stw       r5, 0x1C(r1)
  addi      r4, r1, 0x18
  addi      r3, r31, 0
  stw       r0, 0x18(r1)
  lwz       r12, 0x0(r31)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl      
  b         .loc_0xBC

.loc_0xB4:
  li        r0, 0x1
  stb       r0, 0x1C(r30)

.loc_0xBC:
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
 * Address:	800A7B50
 * Size:	0000B8
 */
void ActPick::init(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  li        r31, 0
  stw       r30, 0x28(r1)
  mr        r30, r4
  stw       r29, 0x24(r1)
  addi      r29, r3, 0
  stb       r31, 0x1C(r3)
  lwz       r3, 0x18(r3)
  cmplwi    r3, 0
  beq-      .loc_0x40
  beq-      .loc_0x40
  bl        0x3C7E4
  stw       r31, 0x18(r29)

.loc_0x40:
  stw       r30, 0x18(r29)
  lwz       r3, 0x18(r29)
  cmplwi    r3, 0
  beq-      .loc_0x54
  bl        0x3C7BC

.loc_0x54:
  cmplwi    r29, 0
  addi      r30, r29, 0
  beq-      .loc_0x64
  addi      r30, r30, 0x14

.loc_0x64:
  addi      r3, r1, 0x10
  li        r4, 0x4
  bl        0x7739C
  addi      r31, r3, 0
  addi      r5, r30, 0
  addi      r3, r1, 0x18
  li        r4, 0x4
  bl        0x773BC
  mr        r4, r3
  lwz       r3, 0xC(r29)
  mr        r5, r31
  bl        0x22DF8
  lwz       r3, 0xC(r29)
  bl        0x23024
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
 * Address:	800A7C08
 * Size:	000040
 */
void ActPick::cleanup()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lwz       r3, 0x18(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2C
  bl        0x3C744
  li        r0, 0
  stw       r0, 0x18(r31)

.loc_0x2C:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A7C48
 * Size:	0000B4
 */
void ActPick::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  mr        r30, r3
  lfs       f0, -0x5090(r13)
  lwz       r3, 0xC(r3)
  stfsu     f0, 0xA4(r3)
  lfs       f0, -0x508C(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x5088(r13)
  stfs      f0, 0x8(r3)
  lbz       r0, 0x1C(r30)
  cmplwi    r0, 0
  beq-      .loc_0x98
  lwz       r3, 0xC(r30)
  lwz       r0, 0x2AC(r3)
  cmplwi    r0, 0
  bne-      .loc_0x90
  addi      r3, r1, 0x14
  li        r4, 0x2
  bl        0x772B8
  addi      r31, r3, 0
  addi      r3, r1, 0x1C
  li        r4, 0x2
  bl        0x772A8
  mr        r4, r3
  lwz       r3, 0xC(r30)
  mr        r5, r31
  bl        0x22D18
  lwz       r4, 0xC(r30)
  li        r0, 0x1
  li        r3, 0x1
  stb       r0, 0x400(r4)
  b         .loc_0x9C

.loc_0x90:
  li        r3, 0x2
  b         .loc_0x9C

.loc_0x98:
  li        r3, 0

.loc_0x9C:
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
 * Size:	000040
 */
ActPut::ActPut(Piki *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A7CFC
 * Size:	000004
 */
void ActPut::Initialiser::initialise(Action *)
{
}

/*
 * --INFO--
 * Address:	800A7D00
 * Size:	00000C
 */
void ActPut::init(Creature *)
{
/*
.loc_0x0:
  lfs       f0, -0x719C(r2)
  stfs      f0, 0x14(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800A7D0C
 * Size:	000004
 */
void ActPut::cleanup()
{
}

/*
 * --INFO--
 * Address:	800A7D10
 * Size:	0000D8
 */
void ActPut::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  mr        r31, r3
  lfs       f0, -0x5084(r13)
  lwz       r3, 0xC(r3)
  stfsu     f0, 0xA4(r3)
  lfs       f0, -0x5080(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x507C(r13)
  stfs      f0, 0x8(r3)
  lwz       r6, 0xC(r31)
  lwz       r0, 0x2AC(r6)
  cmplwi    r0, 0
  mr        r3, r0
  bne-      .loc_0x4C
  li        r3, 0x1
  b         .loc_0xC4

.loc_0x4C:
  lis       r4, 0x802B
  lfs       f0, -0x7198(r2)
  subi      r0, r4, 0x3064
  stw       r0, 0x2C(r1)
  lis       r5, 0x802B
  subi      r0, r5, 0x2E74
  stw       r6, 0x30(r1)
  addi      r4, r1, 0x2C
  stw       r0, 0x2C(r1)
  stfs      f0, 0x34(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x94
  li        r3, 0x2
  b         .loc_0xC4

.loc_0x94:
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x14(r31)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x14(r31)
  lfs       f1, 0x14(r31)
  lfs       f0, -0x7194(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xC0
  li        r3, 0x1
  b         .loc_0xC4

.loc_0xC0:
  li        r3, 0

.loc_0xC4:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A7DE8
 * Size:	00006C
 */
ActAdjust::ActAdjust(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        0x1BFD0
  lis       r3, 0x802B
  addi      r0, r3, 0x50C8
  stw       r0, 0x0(r31)
  li        r0, 0x8
  addi      r3, r31, 0
  lfs       f0, -0x7194(r2)
  stfs      f0, 0x24(r31)
  stfs      f0, 0x20(r31)
  stfs      f0, 0x1C(r31)
  stfs      f0, 0x38(r31)
  stfs      f0, 0x34(r31)
  stfs      f0, 0x30(r31)
  stw       r0, 0x18(r31)
  lfs       f0, -0x7190(r2)
  stfs      f0, 0x14(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A7E54
 * Size:	000014
 */
void ActAdjust::Initialiser::initialise(Action *)
{
/*
.loc_0x0:
  lfs       f0, 0x4(r3)
  stfs      f0, 0x14(r4)
  lwz       r0, 0x8(r3)
  stw       r0, 0x18(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	800A7E68
 * Size:	000200
 */
void ActAdjust::init(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  cmplwi    r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB8(r1)
  stfd      f31, 0xB0(r1)
  stfd      f30, 0xA8(r1)
  stfd      f29, 0xA0(r1)
  stfd      f28, 0x98(r1)
  stw       r31, 0x94(r1)
  stw       r30, 0x90(r1)
  addi      r30, r3, 0
  beq-      .loc_0x1D0
  li        r0, 0
  stb       r0, 0x3C(r30)
  lis       r0, 0x4330
  lwz       r5, 0x94(r4)
  lwz       r3, 0x98(r4)
  stw       r5, 0x1C(r30)
  stw       r3, 0x20(r30)
  lwz       r3, 0x9C(r4)
  stw       r3, 0x24(r30)
  lwz       r31, 0xC(r30)
  lwz       r3, 0x18(r30)
  lfs       f1, 0x24(r30)
  xoris     r3, r3, 0x8000
  lfs       f0, 0x9C(r31)
  stw       r3, 0x8C(r1)
  fsubs     f29, f1, f0
  lfs       f2, 0x1C(r30)
  lfs       f0, 0x94(r31)
  stw       r0, 0x88(r1)
  fsubs     f30, f2, f0
  lfd       f1, -0x7178(r2)
  fmr       f2, f29
  lfd       f0, 0x88(r1)
  lfs       f5, 0x20(r30)
  fsubs     f0, f0, f1
  lfs       f4, 0x98(r31)
  lfs       f3, -0x718C(r2)
  fmr       f1, f30
  fsubs     f31, f5, f4
  fmuls     f28, f3, f0
  bl        0x173AE8
  lfs       f2, 0xA0(r31)
  bl        -0x6F964
  fdivs     f0, f1, f28
  stfs      f0, 0x2C(r30)
  fmuls     f2, f30, f30
  fmuls     f1, f31, f31
  fmuls     f3, f29, f29
  lfs       f0, -0x7194(r2)
  fadds     f1, f2, f1
  fadds     f4, f3, f1
  fcmpo     cr0, f4, f0
  ble-      .loc_0x134
  fsqrte    f1, f4
  lfd       f3, -0x7188(r2)
  lfd       f2, -0x7180(r2)
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
  stfs      f0, 0x40(r1)
  lfs       f4, 0x40(r1)

.loc_0x134:
  lfs       f1, -0x7198(r2)
  addi      r3, r1, 0x48
  lfs       f2, 0x14(r30)
  li        r4, 0xB
  fdivs     f0, f1, f4
  fsubs     f2, f4, f2
  fdivs     f1, f1, f28
  fmuls     f0, f0, f2
  fmuls     f0, f1, f0
  fmuls     f2, f30, f0
  fmuls     f1, f31, f0
  fmuls     f0, f29, f0
  stfs      f2, 0x34(r1)
  lfs       f2, 0x34(r1)
  stfs      f2, 0x58(r1)
  stfs      f1, 0x5C(r1)
  stfs      f0, 0x60(r1)
  lwz       r5, 0x58(r1)
  lwz       r0, 0x5C(r1)
  stw       r5, 0x30(r30)
  stw       r0, 0x34(r30)
  lwz       r0, 0x60(r1)
  stw       r0, 0x38(r30)
  lfs       f0, -0x7194(r2)
  stfs      f0, 0x28(r30)
  bl        0x76F58
  addi      r31, r3, 0
  addi      r3, r1, 0x50
  li        r4, 0xB
  bl        0x76F48
  mr        r4, r3
  lwz       r3, 0xC(r30)
  mr        r5, r31
  bl        0x229B8
  lwz       r3, 0xC(r30)
  lwz       r0, 0xC8(r3)
  ori       r0, r0, 0x400
  stw       r0, 0xC8(r3)
  b         .loc_0x1D8

.loc_0x1D0:
  li        r0, 0x1
  stb       r0, 0x3C(r30)

.loc_0x1D8:
  lwz       r0, 0xBC(r1)
  lfd       f31, 0xB0(r1)
  lfd       f30, 0xA8(r1)
  lfd       f29, 0xA0(r1)
  lfd       f28, 0x98(r1)
  lwz       r31, 0x94(r1)
  lwz       r30, 0x90(r1)
  addi      r1, r1, 0xB8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A8068
 * Size:	000014
 */
void ActAdjust::cleanup()
{
/*
.loc_0x0:
  lwz       r3, 0xC(r3)
  lwz       r0, 0xC8(r3)
  rlwinm    r0,r0,0,22,20
  stw       r0, 0xC8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800A807C
 * Size:	00011C
 */
void ActAdjust::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r3
  lbz       r0, 0x3C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x28
  li        r3, 0x1
  b         .loc_0x108

.loc_0x28:
  lwz       r4, 0xC(r31)
  lwz       r3, 0x30(r31)
  lwz       r0, 0x34(r31)
  stw       r3, 0x70(r4)
  stw       r0, 0x74(r4)
  lwz       r0, 0x38(r31)
  stw       r0, 0x78(r4)
  lwz       r4, 0xC(r31)
  lwz       r3, 0x30(r31)
  lwz       r0, 0x34(r31)
  stw       r3, 0xA4(r4)
  stw       r0, 0xA8(r4)
  lwz       r0, 0x38(r31)
  stw       r0, 0xAC(r4)
  lwz       r3, 0x2DEC(r13)
  lwz       r4, 0xC(r31)
  lfs       f1, 0x2C(r31)
  lfs       f0, 0x28C(r3)
  lfs       f2, 0xA0(r4)
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0xA0(r4)
  lwz       r3, 0xC(r31)
  lfs       f1, 0xA0(r3)
  bl        -0x6FB7C
  lwz       r3, 0xC(r31)
  lis       r0, 0x4330
  stfs      f1, 0xA0(r3)
  lwz       r4, 0xC(r31)
  lfs       f0, -0x5078(r13)
  addi      r3, r4, 0x88
  stfs      f0, 0x88(r4)
  lfs       f0, 0xA0(r4)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x5074(r13)
  stfs      f0, 0x8(r3)
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x28(r31)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x28(r31)
  lwz       r3, 0x18(r31)
  lfd       f1, -0x7178(r2)
  xoris     r3, r3, 0x8000
  lfs       f2, -0x718C(r2)
  stw       r3, 0x2C(r1)
  lfs       f3, 0x28(r31)
  stw       r0, 0x28(r1)
  lfd       f0, 0x28(r1)
  fsubs     f0, f0, f1
  fmuls     f0, f2, f0
  fcmpo     cr0, f3, f0
  ble-      .loc_0x104
  li        r3, 0x2
  b         .loc_0x108

.loc_0x104:
  li        r3, 0

.loc_0x108:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A8198
 * Size:	000064
 */
ActAdjust::~ActAdjust()
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
  addi      r0, r3, 0x50C8
  stw       r0, 0x0(r30)
  addi      r3, r30, 0
  li        r4, 0
  bl        0x1BC3C
  extsh.    r0, r31
  ble-      .loc_0x48
  mr        r3, r30
  bl        -0x61030

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

/*
 * --INFO--
 * Address:	800A81FC
 * Size:	000014
 */
void ActAdjust::defaultInitialiser()
{
/*
.loc_0x0:
  lfs       f0, -0x7170(r2)
  li        r0, 0x8
  stfs      f0, 0x14(r3)
  stw       r0, 0x18(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800A8210
 * Size:	000064
 */
ActPut::~ActPut()
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
  addi      r0, r3, 0x5184
  stw       r0, 0x0(r30)
  addi      r3, r30, 0
  li        r4, 0
  bl        0x1BBC4
  extsh.    r0, r31
  ble-      .loc_0x48
  mr        r3, r30
  bl        -0x610A8

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

/*
 * --INFO--
 * Address:	800A8274
 * Size:	00006C
 */
ActPick::~ActPick()
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
  beq-      .loc_0x50
  lis       r3, 0x802B
  addi      r3, r3, 0x527C
  stw       r3, 0x0(r30)
  addi      r0, r3, 0x64
  addi      r3, r30, 0
  stw       r0, 0x14(r30)
  li        r4, 0
  bl        0x1BB58
  extsh.    r0, r31
  ble-      .loc_0x50
  mr        r3, r30
  bl        -0x61114

.loc_0x50:
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
 * Address:	800A82E0
 * Size:	000008
 */
void ActPick::@20@animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  subi      r3, r3, 0x14
  b         -0x868
*/
}
