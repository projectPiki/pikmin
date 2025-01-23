#include "PikiAI.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	800BDFF0
 * Size:	0000A0
 */
ActPush::ActPush(Piki* piki)
    : Action(piki, false)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  extsh.    r0, r4
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x30
	  addi      r0, r31, 0x48
	  lis       r3, 0x802B
	  stw       r0, 0x14(r31)
	  subi      r0, r3, 0x246C
	  stw       r0, 0x48(r31)

	.loc_0x30:
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  li        r5, 0x1
	  bl        0x5DA4
	  lis       r3, 0x802B
	  addi      r3, r3, 0x7434
	  stw       r3, 0x0(r31)
	  addi      r6, r3, 0x68
	  addi      r5, r31, 0x48
	  lwz       r3, 0x14(r31)
	  subi      r4, r13, 0x46E0
	  li        r0, 0
	  stw       r6, 0x0(r3)
	  mr        r3, r31
	  lwz       r6, 0x14(r31)
	  sub       r5, r5, r6
	  stw       r5, 0x4(r6)
	  lfs       f0, -0x6C20(r2)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x30(r31)
	  stfs      f0, 0x2C(r31)
	  stw       r4, 0x10(r31)
	  stw       r0, 0x18(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BE090
 * Size:	000098
 */
void ActPush::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x2
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  cmplwi    r4, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stb       r5, 0x1C(r3)
	  lwz       r3, 0xC(r3)
	  stb       r5, 0x408(r3)
	  lwz       r3, 0xC(r30)
	  stb       r0, 0x400(r3)
	  stw       r0, 0x18(r30)
	  beq-      .loc_0x70
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x26
	  bne-      .loc_0x70
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x160(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x70
	  stw       r31, 0x18(r30)

	.loc_0x70:
	  li        r0, 0
	  sth       r0, 0x1E(r30)
	  stb       r0, 0x3C(r30)
	  stb       r0, 0x44(r30)
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
 * Address:	........
 * Size:	000050
 */
bool ActPush::collideRockSurface()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800BE128
 * Size:	0000CC
 */
int ActPush::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x44(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0xBC

	.loc_0x20:
	  cmplwi    r0, 0x2
	  bne-      .loc_0x3C
	  lwz       r4, 0xC(r3)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0xBC

	.loc_0x3C:
	  lwz       r4, 0x18(r3)
	  lbz       r4, 0x444(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x74
	  lbz       r0, 0x3C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x74
	  li        r0, 0
	  stb       r0, 0x3C(r3)
	  lwz       r4, 0x3068(r13)
	  lwz       r4, 0x68(r4)
	  lfs       f0, 0x4A8(r4)
	  stfs      f0, 0x40(r3)
	  b         .loc_0x84

	.loc_0x74:
	  cmplwi    r4, 0
	  bne-      .loc_0x84
	  li        r0, 0x1
	  stb       r0, 0x3C(r3)

	.loc_0x84:
	  li        r0, 0
	  stb       r0, 0x44(r3)
	  lhz       r0, 0x1E(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xB0
	  bge-      .loc_0xB8
	  cmpwi     r0, 0
	  bge-      .loc_0xA8
	  b         .loc_0xB8

	.loc_0xA8:
	  bl        .loc_0xCC
	  b         .loc_0xBC

	.loc_0xB0:
	  bl        0x268
	  b         .loc_0xBC

	.loc_0xB8:
	  li        r3, 0

	.loc_0xBC:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0xCC:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void ActPush::initApproach()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800BE1F4
 * Size:	000110
 */
int ActPush::exeApproach()
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
	  bne-      .loc_0x28
	  li        r3, 0x1
	  b         .loc_0xFC

	.loc_0x28:
	  lwz       r4, 0xC(r31)
	  addi      r4, r4, 0x94
	  bl        -0x21DCC
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x4
	  bne-      .loc_0x50
	  mr        r3, r31
	  bl        .loc_0x110
	  li        r3, 0
	  b         .loc_0xFC

	.loc_0x50:
	  lfs       f0, -0x6C20(r2)
	  cmplwi    r0, 0xC
	  stfs      f0, 0x14(r1)
	  stfs      f0, 0x10(r1)
	  stfs      f0, 0xC(r1)
	  bgt-      .loc_0xE8
	  lis       r3, 0x802B
	  addi      r3, r3, 0x737C
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  li        r3, 0x1
	  b         .loc_0xFC
	  addi      r3, r1, 0xC
	  lwz       r4, 0x18(r31)
	  bl        -0x21FBC
	  b         .loc_0xE8
	  addi      r3, r1, 0xC
	  lwz       r4, 0x18(r31)
	  bl        -0x21F04
	  lfs       f0, 0xC(r1)
	  lfs       f1, -0x6C1C(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC(r1)
	  lfs       f0, 0x10(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x10(r1)
	  lfs       f0, 0x14(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x14(r1)
	  b         .loc_0xE8
	  addi      r3, r1, 0xC
	  lwz       r4, 0x18(r31)
	  bl        -0x21F3C
	  b         .loc_0xE8
	  li        r3, 0x1
	  b         .loc_0xFC

	.loc_0xE8:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0xC
	  lfs       f1, -0x6C18(r2)
	  bl        0xDAF0
	  li        r3, 0

	.loc_0xFC:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0x110:
	*/
}

/*
 * --INFO--
 * Address:	800BE304
 * Size:	00013C
 */
void ActPush::initGo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x2
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x40(r1)
	  sth       r0, 0x1E(r3)
	  li        r0, 0
	  addi      r3, r1, 0x20
	  stb       r0, 0x46(r31)
	  bl        0x60C24
	  addi      r30, r3, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x2
	  bl        0x60C14
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xC684
	  li        r0, 0x2
	  stb       r0, 0x1C(r31)
	  lwz       r0, 0x18(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x9C
	  bl        0x159D04
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x6C08(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f1, -0x6C10(r2)
	  stw       r0, 0x38(r1)
	  lfs       f0, -0x6C14(r2)
	  lfd       f2, 0x38(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r31)

	.loc_0x9C:
	  lwz       r3, 0x3068(r13)
	  lwz       r3, 0x68(r3)
	  lfs       f0, 0x4A8(r3)
	  stfs      f0, 0x40(r31)
	  lbz       r0, 0x3C(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xC0
	  li        r0, 0x1
	  stb       r0, 0x3C(r31)

	.loc_0xC0:
	  li        r0, 0x1
	  stb       r0, 0x46(r31)
	  bl        0x159CA4
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6C08(r2)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x6C10(r2)
	  stw       r0, 0x38(r1)
	  lfs       f1, -0x6C14(r2)
	  lfd       f3, 0x38(r1)
	  lfs       f0, -0x6C0C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r3, 0x34(r1)
	  addi      r0, r3, 0x5
	  stb       r0, 0x45(r31)
	  lwz       r3, 0x18(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x124
	  bl        -0x23320

	.loc_0x124:
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
 * Address:	800BE440
 * Size:	000214
 */
int ActPush::exeGo()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  lwz       r3, 0x18(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x34
	  bl        -0x23354
	  li        r3, 0x1
	  b         .loc_0x1F8

	.loc_0x34:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5C
	  lwz       r3, 0x18(r31)
	  bl        -0x2337C
	  li        r3, 0x2
	  b         .loc_0x1F8

	.loc_0x5C:
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x18(r31)
	  addi      r4, r4, 0x94
	  bl        -0x22050
	  rlwinm    r0,r3,0,24,31
	  cmplwi    r0, 0x4
	  beq-      .loc_0xD0
	  lwz       r3, 0x18(r31)
	  bl        -0x233A8
	  li        r0, 0
	  cmplwi    r31, 0
	  sth       r0, 0x1E(r31)
	  mr        r29, r31
	  beq-      .loc_0x98
	  lwz       r29, 0x14(r31)

	.loc_0x98:
	  addi      r3, r1, 0x14
	  li        r4, 0
	  bl        0x60A78
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0xC
	  li        r4, 0
	  bl        0x60A98
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xC4D4
	  li        r3, 0
	  b         .loc_0x1F8

	.loc_0xD0:
	  addi      r3, r1, 0x2C
	  lwz       r4, 0x18(r31)
	  bl        -0x22250
	  lfs       f1, 0x2C(r1)
	  addi      r4, r1, 0x44
	  lfs       f0, 0x30(r1)
	  stfs      f1, 0x44(r1)
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x34(r1)
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x44(r1)
	  lfs       f1, -0x6C1C(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x48(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  lwz       r3, 0xC(r31)
	  lfs       f1, -0x6C14(r2)
	  bl        0xD870
	  lwz       r3, 0xC(r31)
	  bl        -0x34328
	  cmplwi    r3, 0
	  beq-      .loc_0x150
	  lwz       r0, 0x18(r31)
	  cmplw     r3, r0
	  bne-      .loc_0x150
	  li        r0, 0x1
	  b         .loc_0x154

	.loc_0x150:
	  li        r0, 0

	.loc_0x154:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1F4
	  lis       r3, 0x802B
	  lwz       r4, 0xC(r31)
	  subi      r0, r3, 0x3064
	  stw       r0, 0x38(r1)
	  lis       r3, 0x802B
	  addi      r3, r3, 0x13C4
	  stw       r4, 0x3C(r1)
	  li        r0, 0x1
	  addi      r4, r1, 0x38
	  stw       r3, 0x38(r1)
	  stw       r0, 0x40(r1)
	  lwz       r3, 0x18(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0x46(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1F4
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x1B8
	  lwz       r29, 0x14(r31)

	.loc_0x1B8:
	  addi      r3, r1, 0x1C
	  li        r4, 0x56
	  bl        0x60958
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x24
	  li        r4, 0x56
	  bl        0x60978
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xC3B4
	  li        r0, 0
	  stb       r0, 0x1C(r31)
	  stb       r0, 0x46(r31)

	.loc_0x1F4:
	  li        r3, 0

	.loc_0x1F8:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BE654
 * Size:	0002D4
 */
void ActPush::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stw       r31, 0x9C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x98(r1)
	  stw       r29, 0x94(r1)
	  stw       r28, 0x90(r1)
	  mr        r28, r4
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x5
	  beq-      .loc_0x2B4
	  bge-      .loc_0x4C
	  cmpwi     r0, 0
	  beq-      .loc_0x204
	  blt-      .loc_0x2B4
	  cmpwi     r0, 0x3
	  bge-      .loc_0x2B4
	  b         .loc_0x58

	.loc_0x4C:
	  cmpwi     r0, 0x7
	  bge-      .loc_0x2B4
	  b         .loc_0xEC

	.loc_0x58:
	  lbz       r0, 0x1C(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x2B4
	  lwz       r3, 0x18(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x2B4
	  lbz       r0, 0x444(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x2B4
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x8C
	  lwz       r29, 0x14(r31)

	.loc_0x8C:
	  addi      r3, r1, 0x70
	  li        r4, 0x57
	  bl        0x60870
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x78
	  li        r4, 0x57
	  bl        0x60890
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xC2CC
	  lwz       r0, 0x0(r28)
	  lfs       f0, -0x6C00(r2)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xD0
	  lfs       f0, -0x6BFC(r2)

	.loc_0xD0:
	  lwz       r3, 0xC(r31)
	  li        r0, 0x1
	  stfs      f0, 0x384(r3)
	  lwz       r3, 0xC(r31)
	  stfs      f0, 0x3D8(r3)
	  stb       r0, 0x1C(r31)
	  b         .loc_0x2B4

	.loc_0xEC:
	  lbz       r0, 0x1C(r31)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x1B8
	  lwz       r3, 0x18(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1B8
	  lbz       r0, 0x444(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x1B8
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x120
	  lwz       r29, 0x14(r31)

	.loc_0x120:
	  addi      r3, r1, 0x60
	  li        r4, 0x56
	  bl        0x607DC
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x68
	  li        r4, 0x56
	  bl        0x607FC
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xC238
	  bl        0x1598CC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6C08(r2)
	  stw       r0, 0x8C(r1)
	  lis       r3, 0x4330
	  lfs       f2, -0x6C10(r2)
	  li        r0, 0
	  stw       r3, 0x88(r1)
	  lfs       f1, -0x6C14(r2)
	  lfd       f3, 0x88(r1)
	  lfs       f0, -0x6C0C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r3, 0x84(r1)
	  addi      r3, r3, 0x5
	  stb       r3, 0x45(r31)
	  lfs       f0, -0x6BF8(r2)
	  lwz       r3, 0xC(r31)
	  stfs      f0, 0x384(r3)
	  lwz       r3, 0xC(r31)
	  stfs      f0, 0x3D8(r3)
	  stb       r0, 0x1C(r31)

	.loc_0x1B8:
	  lbz       r0, 0x1C(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x1F8
	  lbz       r3, 0x45(r31)
	  subi      r0, r3, 0x1
	  stb       r0, 0x45(r31)
	  lbz       r0, 0x45(r31)
	  extsb.    r0, r0
	  bgt-      .loc_0x1F8
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x1EC
	  lwz       r4, 0x14(r31)

	.loc_0x1EC:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x61278

	.loc_0x1F8:
	  li        r0, 0x1
	  stw       r0, 0x24(r31)
	  b         .loc_0x2B4

	.loc_0x204:
	  lbz       r0, 0x44(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x21C
	  li        r0, 0x2
	  stb       r0, 0x44(r31)
	  b         .loc_0x2B4

	.loc_0x21C:
	  lhz       r0, 0x1E(r31)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x2B4
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x238
	  lwz       r29, 0x14(r31)

	.loc_0x238:
	  addi      r3, r1, 0x50
	  li        r4, 0x56
	  bl        0x606C4
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x58
	  li        r4, 0x56
	  bl        0x606E4
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xC120
	  bl        0x1597B4
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6C08(r2)
	  stw       r0, 0x84(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x6C10(r2)
	  stw       r0, 0x80(r1)
	  lfs       f1, -0x6C14(r2)
	  lfd       f3, 0x80(r1)
	  lfs       f0, -0x6C0C(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x88(r1)
	  lwz       r3, 0x8C(r1)
	  addi      r0, r3, 0x5
	  stb       r0, 0x45(r31)

	.loc_0x2B4:
	  lwz       r0, 0xA4(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  lwz       r29, 0x94(r1)
	  lwz       r28, 0x90(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BE928
 * Size:	000038
 */
void ActPush::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lhz       r0, 0x1E(r3)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x28
	  lwz       r3, 0x18(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  bl        -0x23838

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BE960
 * Size:	000080
 */
ActPush::~ActPush()
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
	  beq-      .loc_0x64
	  lis       r3, 0x802B
	  addi      r3, r3, 0x7434
	  stw       r3, 0x0(r30)
	  addi      r6, r3, 0x68
	  addi      r0, r30, 0x48
	  lwz       r5, 0x14(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r30)
	  sub       r0, r0, r5
	  stw       r0, 0x4(r5)
	  bl        0x5458
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x77814

	.loc_0x64:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
