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
 * Address:	800B8D68
 * Size:	000060
 */
ActExit::ActExit(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  bl        0xB050
	  lis       r3, 0x802B
	  addi      r0, r3, 0x6764
	  stw       r0, 0x0(r31)
	  subi      r4, r13, 0x49D8
	  li        r0, -0x1
	  lfs       f0, -0x6DB0(r2)
	  mr        r3, r31
	  stfs      f0, 0x1C(r31)
	  stfs      f0, 0x18(r31)
	  stfs      f0, 0x14(r31)
	  stw       r4, 0x10(r31)
	  sth       r0, 0x8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B8DC8
 * Size:	0000C0
 */
void ActExit::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  li        r30, 0
	  stw       r29, 0x24(r1)
	  mr        r29, r3
	  lwz       r4, 0xC(r3)
	  addi      r3, r1, 0x10
	  stb       r30, 0x408(r4)
	  li        r4, 0x3E
	  bl        0x66160
	  addi      r31, r3, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x3E
	  bl        0x66150
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x11BC0
	  lwz       r3, 0xC(r29)
	  lfs       f0, -0x49D0(r13)
	  stfsu     f0, 0x7C(r3)
	  lfs       f0, -0x49CC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x49C8(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0xC(r29)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x14(r29)
	  stw       r0, 0x18(r29)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x1C(r29)
	  lwz       r3, 0xC(r29)
	  lfs       f1, -0x6DAC(r2)
	  lfs       f2, -0x6DA8(r2)
	  addi      r3, r3, 0x2BC
	  bl        0x149B0
	  stb       r30, 0x20(r29)
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
 * Address:	800B8E88
 * Size:	00002C
 */
void ActExit::procCollideMsg(Piki*, MsgCollide*)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x4(r5)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x10
	  beqlr-
	  cmpwi     r0, 0
	  beqlr-
	  cmpwi     r0, 0x36
	  beqlr-
	  li        r0, 0x1
	  stb       r0, 0x20(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B8EB4
 * Size:	0002E8
 */
void ActExit::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  stfd      f30, 0x120(r1)
	  stfd      f29, 0x118(r1)
	  stfd      f28, 0x110(r1)
	  stfd      f27, 0x108(r1)
	  stfd      f26, 0x100(r1)
	  stfd      f25, 0xF8(r1)
	  stw       r31, 0xF4(r1)
	  mr        r31, r3
	  lbz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x4C
	  lwz       r4, 0xC(r31)
	  lwz       r0, 0x158(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x70

	.loc_0x4C:
	  lwz       r4, 0xC(r31)
	  li        r3, 0x1
	  lfs       f0, -0x49C4(r13)
	  stfsu     f0, 0x7C(r4)
	  lfs       f0, -0x49C0(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x49BC(r13)
	  stfs      f0, 0x8(r4)
	  b         .loc_0x2B8

	.loc_0x70:
	  addi      r3, r4, 0x2BC
	  addi      r4, r4, 0x94
	  addi      r5, r31, 0x14
	  bl        0x148FC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xB4
	  lwz       r3, 0xC(r31)
	  bl        -0x28354
	  lwz       r4, 0xC(r31)
	  li        r3, 0x1
	  lfs       f0, -0x49B8(r13)
	  stfsu     f0, 0x7C(r4)
	  lfs       f0, -0x49B4(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x49B0(r13)
	  stfs      f0, 0x8(r4)
	  b         .loc_0x2B8

	.loc_0xB4:
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  stw       r3, 0x14(r31)
	  stw       r0, 0x18(r31)
	  lwz       r0, 0x9C(r4)
	  stw       r0, 0x1C(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x6DA4(r2)
	  lfs       f1, 0x15C(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x124
	  li        r0, 0
	  stb       r0, 0x409(r3)
	  lwz       r3, 0xC(r31)
	  lfs       f2, -0x6DAC(r2)
	  lfs       f0, 0x15C(r3)
	  lfs       f1, -0x6DA0(r2)
	  fsubs     f2, f2, f0
	  lfs       f0, -0x6DB0(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x114
	  fmr       f1, f0

	.loc_0x114:
	  stfsu     f1, 0x7C(r3)
	  stfs      f1, 0x4(r3)
	  stfs      f1, 0x8(r3)
	  b         .loc_0x13C

	.loc_0x124:
	  lfs       f0, -0x49AC(r13)
	  stfsu     f0, 0x7C(r3)
	  lfs       f0, -0x49A8(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x49A4(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x13C:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x28C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  li        r3, 0x2
	  b         .loc_0x2B8

	.loc_0x154:
	  lfs       f1, 0x15C(r3)
	  lfs       f0, -0x6DB0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x16C
	  li        r3, 0x2
	  b         .loc_0x2B8

	.loc_0x16C:
	  bl        0x15F050
	  xoris     r0, r3, 0x8000
	  lwz       r4, 0xC(r31)
	  stw       r0, 0xEC(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x158(r4)
	  stw       r0, 0xE8(r1)
	  lfsu      f31, 0x2C4(r3)
	  lfd       f2, -0x6D88(r2)
	  lfd       f0, 0xE8(r1)
	  lfs       f1, -0x6D9C(r2)
	  fsubs     f4, f0, f2
	  lfs       f3, -0x6DAC(r2)
	  lfs       f0, -0x6D94(r2)
	  lfs       f2, -0x6D98(r2)
	  fdivs     f4, f4, f1
	  lfs       f30, 0x4(r3)
	  lfs       f29, 0x8(r3)
	  lfs       f1, 0xA0(r4)
	  fmuls     f3, f3, f4
	  fsubs     f0, f3, f0
	  fmuls     f28, f2, f0
	  bl        0x162ADC
	  lwz       r3, 0xC(r31)
	  fmr       f27, f1
	  lfs       f1, 0xA0(r3)
	  bl        0x162C60
	  lfs       f6, -0x49A0(r13)
	  fmuls     f4, f27, f30
	  fmuls     f2, f27, f31
	  fmuls     f5, f6, f29
	  fmuls     f0, f1, f29
	  fmuls     f3, f1, f30
	  fsubs     f27, f5, f4
	  fsubs     f26, f2, f0
	  fmuls     f2, f6, f31
	  fmuls     f1, f27, f27
	  fmuls     f0, f26, f26
	  fsubs     f25, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f25, f25
	  fadds     f1, f1, f0
	  bl        -0xAB488
	  lfs       f0, -0x6DB0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x230
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1

	.loc_0x230:
	  lfs       f0, -0x6D90(r2)
	  fmuls     f2, f27, f28
	  fmuls     f1, f26, f28
	  li        r3, 0
	  fneg      f4, f0
	  stfs      f2, 0x6C(r1)
	  fmuls     f0, f25, f28
	  fmuls     f2, f31, f4
	  fmuls     f3, f30, f4
	  stfs      f2, 0x78(r1)
	  fmuls     f2, f29, f4
	  lfs       f4, 0x78(r1)
	  stfs      f4, 0xA0(r1)
	  stfs      f3, 0xA4(r1)
	  stfs      f2, 0xA8(r1)
	  lfs       f3, 0xA0(r1)
	  lfs       f2, 0x6C(r1)
	  fadds     f2, f3, f2
	  stfs      f2, 0x60(r1)
	  lfs       f2, 0x60(r1)
	  stfs      f2, 0xAC(r1)
	  lfs       f2, 0xA4(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xB0(r1)
	  lfs       f1, 0xA8(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xB4(r1)
	  lwz       r5, 0xC(r31)
	  lwz       r4, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r4, 0x70(r5)
	  stw       r0, 0x74(r5)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x78(r5)

	.loc_0x2B8:
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lfd       f30, 0x120(r1)
	  lfd       f29, 0x118(r1)
	  lfd       f28, 0x110(r1)
	  lfd       f27, 0x108(r1)
	  lfd       f26, 0x100(r1)
	  lfd       f25, 0xF8(r1)
	  lwz       r31, 0xF4(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800B919C
 * Size:	0000C0
 */
void ActExit::cleanup()
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
	  lwz       r3, 0xC(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x54
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x499C(r13)
	  stfsu     f0, 0x7C(r3)
	  lfs       f0, -0x4998(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x4994(r13)
	  stfs      f0, 0x8(r3)

	.loc_0x54:
	  lwz       r3, 0xC(r31)
	  li        r0, 0x1
	  stb       r0, 0x409(r3)
	  lwz       r3, 0xC(r31)
	  bl        -0x28614
	  lwz       r3, 0xC(r31)
	  lfs       f30, 0xA0(r3)
	  fmr       f1, f30
	  bl        0x162944
	  lfs       f0, -0x6D80(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x162AC8
	  lfs       f0, -0x6D80(r2)
	  lwz       r3, 0xC(r31)
	  fmuls     f0, f0, f1
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x4990(r13)
	  stfs      f0, 0x4(r3)
	  stfs      f31, 0x8(r3)
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
 * Address:	800B925C
 * Size:	000064
 */
ActExit::~ActExit()
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
	  addi      r0, r3, 0x6764
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0xAB78
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x720F4

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
