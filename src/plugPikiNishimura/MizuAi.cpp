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
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017B858
 * Size:	000080
 */
MizuAi::MizuAi(Mizu*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0x246C
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x802D
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x18B4
	  li        r3, 0x8
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  stw       r4, 0x4(r31)
	  stw       r0, 0xC(r31)
	  stw       r0, 0x8(r31)
	  bl        -0x134894
	  cmplwi    r3, 0
	  beq-      .loc_0x64
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802D
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x1914
	  stw       r0, 0x0(r3)

	.loc_0x64:
	  stw       r3, 0x10(r31)
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
 * Address:	8017B8D8
 * Size:	0000B8
 */
void MizuAi::initMizu(Mizu*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  stw       r4, 0x4(r3)
	  li        r4, 0xC2
	  lwz       r5, 0x4(r3)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x21230
	  stw       r3, 0xC(r31)
	  li        r4, 0xC1
	  li        r6, 0
	  lwz       r5, 0x4(r31)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x21210
	  stw       r3, 0x8(r31)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x1C
	  li        r4, 0x2
	  stw       r0, 0x2E4(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2E8(r6)
	  bl        -0x5C9C4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5C7A0
	  lfs       f0, -0x5160(r2)
	  mr        r3, r31
	  lwz       r5, 0x4(r31)
	  li        r4, 0
	  stfs      f0, 0x2D8(r5)
	  bl        0x150
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017B990
 * Size:	0000B8
 */
void MizuAi::initGeyzer(Mizu*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  stw       r4, 0x4(r3)
	  li        r4, 0xC2
	  lwz       r5, 0x4(r3)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x21178
	  stw       r3, 0xC(r31)
	  li        r4, 0xC1
	  li        r6, 0
	  lwz       r5, 0x4(r31)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x21158
	  stw       r3, 0x8(r31)
	  li        r0, 0x1
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r31)
	  addi      r3, r1, 0x1C
	  li        r4, 0x2
	  stw       r0, 0x2E4(r6)
	  lwz       r6, 0x4(r31)
	  stw       r0, 0x2E8(r6)
	  bl        -0x5CA7C
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5C858
	  lfs       f0, -0x5160(r2)
	  mr        r3, r31
	  lwz       r5, 0x4(r31)
	  li        r4, 0x1
	  stfs      f0, 0x2D8(r5)
	  bl        0x154
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017BA48
 * Size:	000004
 */
void MizuAi::animationKeyUpdated(PaniAnimKeyEvent&) { }

/*
 * --INFO--
 * Address:	8017BA4C
 * Size:	00007C
 */
void MizuAi::killCallBackEffect(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x8(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  bl        0x25188
	  li        r0, 0
	  stw       r0, 0x8(r30)

	.loc_0x34:
	  lwz       r3, 0xC(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  bl        0x25170
	  li        r0, 0
	  stw       r0, 0xC(r30)

	.loc_0x4C:
	  lwz       r3, 0x3180(r13)
	  mr        r6, r31
	  lwz       r4, 0x10(r30)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x25BB0
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
 * Size:	00002C
 */
void MizuAi::setEveryFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void MizuAi::naviGeyzerJump()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void MizuAi::readyTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void MizuAi::jetTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void MizuAi::waitTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017BAC8
 * Size:	0000BC
 */
void MizuAi::initWait(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r3)
	  addi      r3, r1, 0x2C
	  stw       r4, 0x2E8(r6)
	  li        r4, 0x2
	  bl        -0x5CB64
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5C940
	  lwz       r3, 0x4(r31)
	  li        r4, 0x1
	  li        r0, 0
	  stb       r4, 0x3B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r4, 0x3B9(r3)
	  lwz       r3, 0x4(r31)
	  stb       r4, 0x2B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r4, 0x2BB(r3)
	  lfs       f0, -0x5158(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2F0(r3)
	  lwz       r3, 0xC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x90
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x90:
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0xA8:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017BB84
 * Size:	0000D0
 */
void MizuAi::initReady(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r3)
	  addi      r3, r1, 0x2C
	  stw       r4, 0x2E8(r6)
	  li        r4, 0x2
	  bl        -0x5CC20
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5C9FC
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stb       r0, 0x3B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x3B9(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BB(r3)
	  lfs       f0, -0x5158(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2F0(r3)
	  lwz       r3, 0xC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x8C:
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xA4
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0xA4:
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xBC
	  li        r4, 0xA8
	  bl        -0xD7E6C

	.loc_0xBC:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017BC54
 * Size:	00026C
 */
void MizuAi::initJet(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stfd      f29, 0xA8(r1)
	  stw       r31, 0xA4(r1)
	  mr        r31, r3
	  addi      r5, r31, 0
	  lwz       r6, 0x4(r3)
	  addi      r3, r1, 0x98
	  stw       r4, 0x2E8(r6)
	  li        r4, 0xA
	  bl        -0x5CCFC
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5CAD8
	  lwz       r3, 0x4(r31)
	  li        r4, 0x1
	  li        r0, 0
	  stb       r4, 0x3B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x3B9(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BB(r3)
	  lfs       f0, -0x5158(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2F0(r3)
	  lwz       r3, 0x4(r31)
	  lfs       f1, 0xA0(r3)
	  bl        0x9FE74
	  lwz       r3, 0x4(r31)
	  fmr       f31, f1
	  lfs       f1, 0xA0(r3)
	  bl        0x9FFF8
	  lwz       r4, 0x4(r31)
	  addi      r6, r1, 0x2C
	  lfs       f3, 0x860(r13)
	  addi      r5, r1, 0x28
	  lwz       r3, 0x224(r4)
	  lfs       f0, 0x9C(r4)
	  addi      r7, r4, 0x94
	  lfs       f2, 0x68(r3)
	  addi      r4, r1, 0x24
	  addi      r3, r1, 0x58
	  fmuls     f4, f31, f2
	  fmuls     f3, f3, f2
	  fmuls     f1, f1, f2
	  fadds     f0, f0, f4
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x4(r7)
	  fadds     f0, f0, f3
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x0(r7)
	  fadds     f0, f0, f1
	  stfs      f0, 0x24(r1)
	  bl        -0x144C2C
	  lfs       f30, 0x58(r1)
	  li        r4, 0x1
	  lfs       f29, 0x60(r1)
	  fmr       f1, f30
	  lwz       r3, 0x2F00(r13)
	  fmr       f2, f29
	  bl        -0x113E60
	  fmr       f31, f1
	  lwz       r3, 0x3120(r13)
	  bl        -0x649AC
	  lis       r4, 0x802B
	  lwz       r5, 0x4(r31)
	  subi      r0, r4, 0x3064
	  stw       r0, 0x64(r1)
	  lis       r4, 0x802C
	  addi      r0, r4, 0x174
	  stw       r5, 0x68(r1)
	  addi      r4, r1, 0x64
	  stw       r0, 0x64(r1)
	  stfs      f30, 0x6C(r1)
	  stfs      f31, 0x70(r1)
	  stfs      f29, 0x74(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x178
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x178:
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x190
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x190:
	  lwz       r5, 0x4(r31)
	  li        r4, 0xC4
	  lwz       r3, 0x3180(r13)
	  li        r7, 0
	  lwz       r6, 0x10(r31)
	  addi      r5, r5, 0x94
	  bl        0x20D3C
	  lwz       r5, 0x4(r31)
	  li        r4, 0xC3
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x20D20
	  lwz       r4, 0x10(r31)
	  cmplwi    r3, 0
	  stw       r3, 0x4(r4)
	  beq-      .loc_0x208
	  lfs       f0, 0x864(r13)
	  lfs       f1, 0x868(r13)
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x86C(r13)
	  stfs      f1, 0x90(r1)
	  stfs      f0, 0x94(r1)
	  lwz       r4, 0x8C(r1)
	  lwz       r0, 0x90(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x94(r1)
	  stw       r0, 0x1E4(r3)

	.loc_0x208:
	  lwz       r5, 0x4(r31)
	  li        r4, 0xC5
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x20CC4
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x24C
	  li        r4, 0xA8
	  bl        -0xD7FE8
	  lwz       r3, 0x4(r31)
	  li        r4, 0xA9
	  lwz       r3, 0x2C(r3)
	  bl        -0xD80CC

	.loc_0x24C:
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lfd       f29, 0xA8(r1)
	  lwz       r31, 0xA4(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void MizuAi::waitState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00011C
 */
void MizuAi::readyState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void MizuAi::jetState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017BEC0
 * Size:	000358
 */
void MizuAi::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stw       r31, 0xDC(r1)
	  mr        r31, r3
	  lwz       r3, 0x4(r3)
	  lfs       f0, 0x300(r3)
	  addi      r4, r3, 0x300
	  stfs      f0, 0x94(r3)
	  lfs       f0, 0x304(r3)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x98(r3)
	  lfs       f0, 0x8(r4)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x9C(r3)
	  lwz       r5, 0x4(r31)
	  lwz       r0, 0x2E4(r5)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x13C
	  bge-      .loc_0x5C
	  cmpwi     r0, 0
	  bge-      .loc_0x68
	  b         .loc_0x344

	.loc_0x5C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x344
	  b         .loc_0x260

	.loc_0x68:
	  lwz       r3, 0x224(r5)
	  lwz       r4, 0x2F0(r5)
	  lwz       r0, 0x1D8(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x84
	  li        r0, 0x1
	  b         .loc_0x88

	.loc_0x84:
	  li        r0, 0

	.loc_0x88:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x344
	  li        r0, 0x1
	  stw       r0, 0x2E8(r5)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xC8
	  li        r4, 0x2
	  bl        -0x5CFD8
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5CDB4
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stb       r0, 0x3B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x3B9(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BB(r3)
	  lfs       f0, -0x5158(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2F0(r3)
	  lwz       r3, 0xC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x108
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x108:
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x120
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x120:
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x344
	  li        r4, 0xA8
	  bl        -0xD8224
	  b         .loc_0x344

	.loc_0x13C:
	  lbz       r0, 0x3B8(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x22C
	  lwz       r3, 0x3120(r13)
	  bl        -0x64C48
	  lwz       r4, 0x4(r31)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x94(r4)
	  lfs       f0, -0x5158(r2)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x170
	  b         .loc_0x174

	.loc_0x170:
	  fneg      f1, f1

	.loc_0x174:
	  lfs       f0, -0x5154(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1E0
	  lfs       f2, 0x9C(r4)
	  lfs       f1, 0x9C(r3)
	  lfs       f0, -0x5158(r2)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x19C
	  b         .loc_0x1A0

	.loc_0x19C:
	  fneg      f1, f1

	.loc_0x1A0:
	  lfs       f0, -0x5154(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1E0
	  lfs       f2, 0x98(r4)
	  lfs       f1, 0x98(r3)
	  lfs       f0, -0x5158(r2)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1C8
	  b         .loc_0x1CC

	.loc_0x1C8:
	  fneg      f1, f1

	.loc_0x1CC:
	  lfs       f0, -0x5150(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1E0
	  li        r0, 0x1
	  stb       r0, 0x3B8(r4)

	.loc_0x1E0:
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x514C(r2)
	  addi      r4, r3, 0x2D4
	  lfs       f1, 0x2D4(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x21C
	  lfs       f0, -0x5158(r2)
	  stfs      f0, 0x0(r4)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x22C
	  li        r4, 0xA8
	  bl        -0xD8304
	  b         .loc_0x22C

	.loc_0x21C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r4)

	.loc_0x22C:
	  lwz       r3, 0x4(r31)
	  lbz       r0, 0x3B8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x244
	  li        r0, 0x1
	  b         .loc_0x248

	.loc_0x244:
	  li        r0, 0

	.loc_0x248:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x344
	  addi      r3, r31, 0
	  li        r4, 0x2
	  bl        -0x4C4
	  b         .loc_0x344

	.loc_0x260:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D4(r5)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D4(r5)
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x515C(r2)
	  lfs       f1, 0x2D4(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x290
	  li        r0, 0x1
	  b         .loc_0x294

	.loc_0x290:
	  li        r0, 0

	.loc_0x294:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x344
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0xB8
	  li        r4, 0x2
	  bl        -0x5D1E4
	  lwz       r5, 0x4(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5CFC0
	  lwz       r3, 0x4(r31)
	  li        r0, 0
	  stb       r0, 0x3B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x3B9(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2B8(r3)
	  lwz       r3, 0x4(r31)
	  stb       r0, 0x2BB(r3)
	  lfs       f0, -0x5158(r2)
	  lwz       r3, 0x4(r31)
	  stfs      f0, 0x2D4(r3)
	  lwz       r3, 0x4(r31)
	  stw       r0, 0x2F0(r3)
	  lwz       r3, 0xC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x314
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x314:
	  lwz       r3, 0x8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x32C
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x32C:
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x344
	  li        r4, 0xA8
	  bl        -0xD8430

	.loc_0x344:
	  lwz       r0, 0xE4(r1)
	  lwz       r31, 0xDC(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017C218
 * Size:	0000B0
 */
void MizuGenSpringPuffCallBack::invoke(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x40(r1)
	  lwz       r5, 0x4(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0xA4
	  lwz       r0, 0x80(r5)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x9C
	  lwz       r3, 0x18(r5)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C
	  b         .loc_0x30

	.loc_0x2C:
	  addi      r3, r5, 0xC

	.loc_0x30:
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x3C(r1)
	  lwz       r3, 0x28(r5)
	  lwz       r5, 0x8(r3)
	  b         .loc_0x78

	.loc_0x54:
	  lfs       f2, 0x10(r5)
	  lfs       f1, 0x1C(r5)
	  lfs       f0, 0x38(r1)
	  fadds     f1, f2, f1
	  lwz       r0, 0x8(r5)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x74
	  stfs      f1, 0x38(r1)

	.loc_0x74:
	  mr        r5, r0

	.loc_0x78:
	  cmplw     r5, r3
	  bne+      .loc_0x54
	  lwz       r3, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x14(r4)
	  b         .loc_0xA4

	.loc_0x9C:
	  li        r0, 0
	  stw       r0, 0x4(r3)

	.loc_0xA4:
	  li        r3, 0x1
	  addi      r1, r1, 0x40
	  blr
	*/
}
