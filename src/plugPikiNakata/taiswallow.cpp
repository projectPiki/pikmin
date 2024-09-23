#include "TAI/Swallow.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8013F304
 * Size:	000084
 */
TaiSwallowSoundTable::TaiSwallowSoundTable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x8
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0x202B0
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0xF8334
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x1
	  stw       r0, 0x0(r3)

	.loc_0x48:
	  lwz       r4, 0x4(r29)
	  addi      r30, r30, 0x1
	  stwx      r3, r4, r31
	  addi      r31, r31, 0x4

	.loc_0x58:
	  lwz       r0, 0x0(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x30
	  mr        r3, r29
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
 * Address:	8013F388
 * Size:	000448
 */
TaiSwallowParameters::TaiSwallowParameters()
    : TekiParameters(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  li        r5, 0x38
	  stwu      r1, -0xF8(r1)
	  stw       r31, 0xF4(r1)
	  subi      r31, r4, 0x42B8
	  li        r4, 0x14
	  stw       r30, 0xF0(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xEC(r1)
	  stw       r28, 0xE8(r1)
	  bl        0xC990
	  lis       r3, 0x802D
	  subi      r0, r3, 0x3C4C
	  stw       r0, 0x0(r30)
	  li        r6, 0x32
	  li        r5, 0x33
	  lwz       r7, 0x84(r30)
	  li        r4, 0x34
	  li        r3, 0x35
	  lwz       r7, 0x4(r7)
	  li        r0, 0x36
	  mulli     r6, r6, 0xC
	  lwz       r8, 0x8(r7)
	  add       r7, r8, r6
	  addi      r6, r31, 0x1C
	  stw       r6, 0x0(r7)
	  mulli     r6, r5, 0xC
	  lfs       f8, -0x59D0(r2)
	  mulli     r5, r4, 0xC
	  stfs      f8, 0x4(r7)
	  lfs       f0, -0x59CC(r2)
	  mulli     r4, r3, 0xC
	  stfs      f0, 0x8(r7)
	  add       r6, r8, r6
	  addi      r3, r31, 0x2C
	  stw       r3, 0x0(r6)
	  mulli     r3, r0, 0xC
	  stfs      f8, 0x4(r6)
	  li        r0, 0x37
	  lfs       f7, -0x59C8(r2)
	  mulli     r0, r0, 0xC
	  stfs      f7, 0x8(r6)
	  add       r6, r8, r5
	  addi      r5, r31, 0x40
	  stw       r5, 0x0(r6)
	  add       r12, r8, r4
	  addi      r5, r31, 0x58
	  stfs      f8, 0x4(r6)
	  add       r29, r8, r3
	  addi      r4, r31, 0x7C
	  stfs      f7, 0x8(r6)
	  add       r28, r8, r0
	  addi      r3, r31, 0x9C
	  stw       r5, 0x0(r12)
	  li        r11, 0x1
	  li        r10, 0
	  stfs      f8, 0x4(r12)
	  li        r9, -0x1
	  li        r8, 0x3
	  lfs       f2, -0x59C4(r2)
	  li        r7, 0x5
	  li        r6, 0xA
	  stfs      f2, 0x8(r12)
	  li        r5, 0x14
	  li        r0, 0x8
	  stw       r4, 0x0(r29)
	  stfs      f8, 0x4(r29)
	  stfs      f8, 0x8(r29)
	  stw       r3, 0x0(r28)
	  stfs      f8, 0x4(r28)
	  lfs       f6, -0x59C0(r2)
	  stfs      f6, 0x8(r28)
	  lwz       r4, 0x84(r30)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r11, 0x0(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r10, 0x18(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r9, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x24(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x28(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x2C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x30(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x34(r3)
	  lwz       r3, 0x0(r4)
	  li        r5, 0xC
	  li        r0, 0xE
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x38(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x3C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x59BC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x59B8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x10(r3)
	  lfs       f0, -0x1CA4(r13)
	  lwz       r3, 0x4(r4)
	  fmuls     f1, f1, f0
	  lfs       f0, -0x59B4(r2)
	  lwz       r3, 0x0(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x59B0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x59AC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f5, -0x59A8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x59A4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f4, -0x59A0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x599C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x5998(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5994(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x44(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x48(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5990(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x4C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x50(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x54(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x598C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x58(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5988(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x5C(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r30
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x6C(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f2, -0x5984(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x78(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f1, -0x5980(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x7C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x80(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x597C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x84(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5978(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x88(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f8, 0x8C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f8, 0x90(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5974(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x94(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5970(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x98(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0x9C(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x596C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xA0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0xAC(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5968(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xB0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0xB4(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f8, 0xC8(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0xCC(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0xD0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0xD4(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5964(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xD8(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f6, 0xDC(r4)
	  lwz       r0, 0xFC(r1)
	  lwz       r31, 0xF4(r1)
	  lwz       r30, 0xF0(r1)
	  lwz       r29, 0xEC(r1)
	  lwz       r28, 0xE8(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013F7D0
 * Size:	00043C
 */
TaiBlackSwallowParameters::TaiBlackSwallowParameters()
    : TekiParameters(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  li        r5, 0x38
	  stwu      r1, -0xF8(r1)
	  stw       r31, 0xF4(r1)
	  subi      r31, r4, 0x42B8
	  li        r4, 0x14
	  stw       r30, 0xF0(r1)
	  addi      r30, r3, 0
	  stw       r29, 0xEC(r1)
	  bl        0xC54C
	  lis       r3, 0x802D
	  subi      r0, r3, 0x3CB8
	  stw       r0, 0x0(r30)
	  li        r6, 0x32
	  li        r5, 0x33
	  lwz       r7, 0x84(r30)
	  li        r4, 0x34
	  li        r3, 0x35
	  lwz       r7, 0x4(r7)
	  li        r0, 0x36
	  mulli     r6, r6, 0xC
	  lwz       r8, 0x8(r7)
	  add       r7, r8, r6
	  addi      r6, r31, 0x1C
	  stw       r6, 0x0(r7)
	  mulli     r6, r5, 0xC
	  lfs       f8, -0x59D0(r2)
	  mulli     r5, r4, 0xC
	  stfs      f8, 0x4(r7)
	  lfs       f0, -0x59CC(r2)
	  mulli     r4, r3, 0xC
	  stfs      f0, 0x8(r7)
	  add       r6, r8, r6
	  addi      r3, r31, 0x2C
	  stw       r3, 0x0(r6)
	  mulli     r3, r0, 0xC
	  stfs      f8, 0x4(r6)
	  li        r0, 0x37
	  lfs       f7, -0x59C8(r2)
	  mulli     r0, r0, 0xC
	  stfs      f7, 0x8(r6)
	  add       r6, r8, r5
	  addi      r5, r31, 0x40
	  stw       r5, 0x0(r6)
	  add       r11, r8, r4
	  addi      r5, r31, 0x58
	  stfs      f8, 0x4(r6)
	  add       r12, r8, r3
	  addi      r4, r31, 0x7C
	  stfs      f7, 0x8(r6)
	  add       r29, r8, r0
	  addi      r3, r31, 0x9C
	  stw       r5, 0x0(r11)
	  li        r10, 0x1
	  li        r9, 0
	  stfs      f8, 0x4(r11)
	  li        r8, -0x1
	  li        r7, 0x5
	  lfs       f3, -0x59C4(r2)
	  li        r6, 0xA
	  li        r5, 0x14
	  stfs      f3, 0x8(r11)
	  li        r0, 0x4
	  stw       r4, 0x0(r12)
	  stfs      f8, 0x4(r12)
	  stfs      f8, 0x8(r12)
	  stw       r3, 0x0(r29)
	  stfs      f8, 0x4(r29)
	  lfs       f6, -0x59C0(r2)
	  stfs      f6, 0x8(r29)
	  lwz       r4, 0x84(r30)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r10, 0x0(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r9, 0x18(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x24(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r7, 0x28(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x2C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x30(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x34(r3)
	  lwz       r3, 0x0(r4)
	  li        r5, 0x6
	  li        r0, 0x8
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x38(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x3C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5960(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x59B8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x10(r3)
	  lfs       f2, -0x595C(r2)
	  lfs       f0, -0x1CA4(r13)
	  lwz       r3, 0x4(r4)
	  fmuls     f1, f2, f0
	  lfs       f0, -0x59B4(r2)
	  lwz       r3, 0x0(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x59B0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x59AC(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f5, -0x59A8(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x59A4(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x59A0(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0xB4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f4, -0x599C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5998(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x44(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5994(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x48(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x5990(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x4C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x50(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x54(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x598C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x58(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r30
	  lfs       f0, -0x5988(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x5C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x6C(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f3, -0x5984(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0x78(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f2, -0x5980(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x7C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x80(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x84(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f1, -0x596C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x88(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f8, 0x8C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f8, 0x90(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5974(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x94(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5958(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x98(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x9C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0xA0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0xAC(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5968(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xB0(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x597C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xC8(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0xCC(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0xD0(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0xD4(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5964(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xD8(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f6, 0xDC(r4)
	  lwz       r0, 0xFC(r1)
	  lwz       r31, 0xF4(r1)
	  lwz       r30, 0xF0(r1)
	  lwz       r29, 0xEC(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8013FC0C
 * Size:	0016EC
 */
TaiSwallowStrategy::TaiSwallowStrategy(TekiParameters*)
    : TaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0xF
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x200(r1)
	  stmw      r14, 0x1B8(r1)
	  mr        r29, r3
	  stw       r4, 0x190(r1)
	  li        r4, 0x10
	  bl        -0x18848
	  lis       r3, 0x802D
	  subi      r0, r3, 0x3DCC
	  stw       r0, 0x0(r29)
	  li        r3, 0x8
	  bl        -0xF8C3C
	  stw       r3, 0x1B4(r1)
	  lwz       r0, 0x1B4(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x74
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x1B4(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x1B4(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6140
	  lwz       r3, 0x1B4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x74:
	  li        r3, 0xC
	  bl        -0xF8C80
	  addi      r18, r3, 0
	  mr.       r0, r18
	  beq-      .loc_0xB0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r18)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r18)
	  subi      r3, r3, 0x6C44
	  li        r0, 0x7
	  stw       r3, 0x4(r18)
	  stw       r0, 0x8(r18)

	.loc_0xB0:
	  li        r3, 0x8
	  bl        -0xF8CBC
	  stw       r3, 0x1B0(r1)
	  lwz       r0, 0x1B0(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xF4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x1B0(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x1B0(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x6C84
	  lwz       r3, 0x1B0(r1)
	  stw       r0, 0x4(r3)

	.loc_0xF4:
	  li        r3, 0x8
	  bl        -0xF8D00
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0x128
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, 0
	  lis       r3, 0x802D
	  stw       r0, 0x0(r22)
	  subi      r0, r3, 0x42D8
	  stw       r0, 0x4(r22)

	.loc_0x128:
	  li        r3, 0x8
	  bl        -0xF8D34
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x15C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0x45B8
	  stw       r0, 0x4(r20)

	.loc_0x15C:
	  li        r3, 0x8
	  bl        -0xF8D68
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x190
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, 0x3
	  lis       r3, 0x802D
	  stw       r0, 0x0(r23)
	  subi      r0, r3, 0x4580
	  stw       r0, 0x4(r23)

	.loc_0x190:
	  li        r3, 0x8
	  bl        -0xF8D9C
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x1C4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0xA
	  lis       r3, 0x802C
	  stw       r0, 0x0(r19)
	  addi      r0, r3, 0x677C
	  stw       r0, 0x4(r19)

	.loc_0x1C4:
	  li        r3, 0x8
	  bl        -0xF8DD0
	  stw       r3, 0x1AC(r1)
	  lwz       r0, 0x1AC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x208
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x1AC(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x1AC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x7B5C
	  lwz       r3, 0x1AC(r1)
	  stw       r0, 0x4(r3)

	.loc_0x208:
	  li        r3, 0x8
	  bl        -0xF8E14
	  stw       r3, 0x1A8(r1)
	  lwz       r0, 0x1A8(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x24C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x1A8(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, 0x7
	  lwz       r3, 0x1A8(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x7B5C
	  lwz       r3, 0x1A8(r1)
	  stw       r0, 0x4(r3)

	.loc_0x24C:
	  li        r3, 0x8
	  bl        -0xF8E58
	  addi      r15, r3, 0
	  mr.       r0, r15
	  beq-      .loc_0x280
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r15)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r15)
	  subi      r0, r3, 0x46F8
	  stw       r0, 0x4(r15)

	.loc_0x280:
	  li        r3, 0x8
	  bl        -0xF8E8C
	  stw       r3, 0x1A4(r1)
	  lwz       r0, 0x1A4(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2C4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x1A4(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, 0x4
	  lwz       r3, 0x1A4(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x46F8
	  lwz       r3, 0x1A4(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2C4:
	  li        r3, 0x8
	  bl        -0xF8ED0
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x2F8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r21)
	  subi      r0, r3, 0x46B0
	  stw       r0, 0x4(r21)

	.loc_0x2F8:
	  li        r3, 0xC
	  bl        -0xF8F04
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0x344
	  lwz       r3, 0x190(r1)
	  lis       r4, 0x802C
	  addi      r4, r4, 0x6620
	  lwz       r5, 0x84(r3)
	  lis       r3, 0x802D
	  li        r0, 0xB
	  lwz       r5, 0x4(r5)
	  subi      r3, r3, 0x7AD4
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0x3C(r5)
	  stw       r4, 0x4(r14)
	  stw       r0, 0x0(r14)
	  stw       r3, 0x4(r14)
	  stfs      f0, 0x8(r14)

	.loc_0x344:
	  li        r3, 0x8
	  bl        -0xF8F50
	  stw       r3, 0x1A0(r1)
	  lwz       r0, 0x1A0(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x388
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x1A0(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, 0x5
	  lwz       r3, 0x1A0(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x7A98
	  lwz       r3, 0x1A0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x388:
	  li        r3, 0x8
	  bl        -0xF8F94
	  stw       r3, 0x19C(r1)
	  lwz       r0, 0x19C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x3CC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x19C(r1)
	  lis       r4, 0x802D
	  stw       r0, 0x4(r3)
	  li        r0, 0x4
	  lwz       r3, 0x19C(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x7A18
	  lwz       r3, 0x19C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x3CC:
	  li        r3, 0x8
	  bl        -0xF8FD8
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x400
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, 0x5
	  lis       r3, 0x802D
	  stw       r0, 0x0(r17)
	  subi      r0, r3, 0x7A58
	  stw       r0, 0x4(r17)

	.loc_0x400:
	  li        r3, 0x8
	  bl        -0xF900C
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x434
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, 0x9
	  lis       r3, 0x802C
	  stw       r0, 0x0(r16)
	  addi      r0, r3, 0x69A4
	  stw       r0, 0x4(r16)

	.loc_0x434:
	  li        r3, 0x24
	  bl        -0xF9040
	  stw       r3, 0x198(r1)
	  lwz       r3, 0x198(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x454
	  lfs       f1, -0x5954(r2)
	  bl        0x1D68

	.loc_0x454:
	  li        r3, 0x8
	  bl        -0xF9060
	  stw       r3, 0x194(r1)
	  lwz       r0, 0x194(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x498
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x194(r1)
	  lis       r4, 0x802C
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lwz       r3, 0x194(r1)
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x6A60
	  lwz       r3, 0x194(r1)
	  stw       r0, 0x4(r3)

	.loc_0x498:
	  li        r3, 0xC
	  bl        -0xF90A4
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x4E0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0
	  subi      r3, r3, 0x447C
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x4E0:
	  li        r3, 0x8
	  bl        -0xF90EC
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x514
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0x43C0
	  stw       r0, 0x4(r28)

	.loc_0x514:
	  li        r3, 0xC
	  bl        -0xF9120
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x530
	  li        r4, 0x3
	  bl        -0x190A0

	.loc_0x530:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x1B4(r1)
	  stwx      r0, r3, r4
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r27)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r29)
	  stw       r27, 0x0(r4)
	  bl        -0xF9178
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x5A8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r3, r3, 0x6A6C
	  li        r0, 0x9
	  stw       r3, 0x4(r27)
	  stw       r0, 0x8(r27)

	.loc_0x5A8:
	  li        r3, 0x8
	  bl        -0xF91B4
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x5DC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, 0x2
	  lis       r3, 0x802D
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x46F8
	  stw       r0, 0x4(r24)

	.loc_0x5DC:
	  li        r3, 0x8
	  bl        -0xF91E8
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x610
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r25)
	  subi      r0, r3, 0x4094
	  stw       r0, 0x4(r25)

	.loc_0x610:
	  li        r3, 0xC
	  bl        -0xF921C
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x64C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  lis       r3, 0x802D
	  stw       r0, 0x0(r28)
	  subi      r3, r3, 0x3E38
	  li        r0, 0
	  stw       r3, 0x4(r28)
	  stw       r0, 0x8(r28)

	.loc_0x64C:
	  li        r3, 0x8
	  bl        -0xF9258
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x680
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, 0x2
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x40D4
	  stw       r0, 0x4(r26)

	.loc_0x680:
	  li        r3, 0x10
	  bl        -0xF928C
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x6C4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6D08
	  li        r3, 0
	  stw       r0, 0x4(r30)
	  li        r0, 0x1
	  stw       r3, 0x8(r30)
	  stw       r0, 0xC(r30)

	.loc_0x6C4:
	  li        r3, 0xC
	  bl        -0xF92D0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x6E0
	  li        r4, 0xA
	  bl        -0x19250

	.loc_0x6E0:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r22, r3, r0
	  li        r0, 0x1
	  li        r3, 0x2
	  lwz       r4, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r19, r4, r0
	  li        r7, 0x4
	  li        r8, 0x5
	  lwz       r4, 0x8(r31)
	  rlwinm    r0,r3,2,0,29
	  li        r9, 0x6
	  stwx      r21, r4, r0
	  li        r5, 0x7
	  li        r4, 0x8
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r6,2,0,29
	  li        r6, 0x9
	  stwx      r23, r3, r0
	  rlwinm    r0,r7,2,0,29
	  rlwinm    r7,r8,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r8,r9,2,0,29
	  rlwinm    r9,r5,2,0,29
	  stwx      r24, r3, r0
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r6,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r3, 0xC
	  stwx      r27, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r25, r4, r8
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r9
	  lwz       r4, 0x8(r31)
	  stwx      r26, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r5
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x3C(r4)
	  bl        -0xF9394
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x7A4
	  li        r4, 0x9
	  bl        -0x19314

	.loc_0x7A4:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r22, r3, r0
	  li        r3, 0x1
	  li        r0, 0x2
	  lwz       r4, 0x8(r31)
	  rlwinm    r3,r3,2,0,29
	  li        r8, 0x3
	  stwx      r19, r4, r3
	  li        r7, 0x4
	  li        r6, 0x5
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x6
	  stwx      r21, r3, r0
	  li        r3, 0x7
	  li        r9, 0x8
	  lwz       r4, 0x8(r31)
	  rlwinm    r0,r8,2,0,29
	  rlwinm    r8,r7,2,0,29
	  stwx      r23, r4, r0
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r7,r5,2,0,29
	  lwz       r4, 0x8(r31)
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r5,r9,2,0,29
	  stwx      r24, r4, r8
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r25, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r28, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r26, r4, r5
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x4(r4)
	  bl        -0xF9448
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x884
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0x4
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x1
	  subi      r3, r3, 0x4650
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x884:
	  li        r3, 0x8
	  bl        -0xF9490
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x8B8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x48A8
	  stw       r0, 0x4(r27)

	.loc_0x8B8:
	  li        r3, 0xC
	  bl        -0xF94C4
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x8D4
	  li        r4, 0x4
	  bl        -0x19444

	.loc_0x8D4:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r0, 0x1
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0x1B4(r1)
	  lwz       r4, 0x8(r28)
	  li        r5, 0x2
	  stwx      r0, r4, r3
	  rlwinm    r0,r5,2,0,29
	  li        r6, 0x3
	  lwz       r4, 0x8(r28)
	  rlwinm    r5,r6,2,0,29
	  li        r3, 0xC
	  stwx      r22, r4, r0
	  lwz       r4, 0x8(r28)
	  stwx      r30, r4, r5
	  lwz       r4, 0x8(r29)
	  stw       r28, 0xC(r4)
	  bl        -0xF952C
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x968
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0x4
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0
	  subi      r3, r3, 0x6AD8
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x968:
	  li        r3, 0xC
	  bl        -0xF9574
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x984
	  li        r4, 0x8
	  bl        -0x194F4

	.loc_0x984:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r7, 0x3
	  stwx      r22, r3, r4
	  li        r6, 0x4
	  li        r5, 0x5
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r0,2,0,29
	  li        r0, 0x6
	  stwx      r19, r3, r4
	  li        r4, 0x7
	  rlwinm    r7,r7,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r5,r5,2,0,29
	  stwx      r27, r3, r7
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r7,r4,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  stwx      r21, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r20, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r15, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r7
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x8(r4)
	  bl        -0xF9618
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xA78
	  lwz       r3, 0x190(r1)
	  lis       r7, 0x802C
	  lis       r6, 0x802D
	  lwz       r3, 0x84(r3)
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lwz       r3, 0x4(r3)
	  addi      r7, r7, 0x6620
	  li        r0, 0x5
	  lwz       r3, 0x0(r3)
	  subi      r6, r6, 0x6A6C
	  subi      r5, r5, 0x6A8C
	  lfs       f0, 0x14(r3)
	  li        r3, 0x4
	  subi      r4, r4, 0x3E84
	  stw       r7, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r3, 0x8(r30)
	  stw       r5, 0x4(r30)
	  stw       r4, 0x4(r30)
	  stfs      f0, 0xC(r30)

	.loc_0xA78:
	  li        r3, 0xC
	  bl        -0xF9684
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xA94
	  li        r4, 0xA
	  bl        -0x19604

	.loc_0xA94:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r3, 0x1
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r0, 0x2
	  rlwinm    r0,r0,2,0,29
	  stwx      r22, r4, r5
	  li        r3, 0x3
	  li        r7, 0x4
	  lwz       r5, 0x8(r31)
	  li        r4, 0x5
	  li        r8, 0x6
	  stwx      r19, r5, r0
	  rlwinm    r5,r3,2,0,29
	  li        r0, 0x7
	  lwz       r6, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r9, 0x8
	  stwx      r21, r6, r5
	  rlwinm    r6,r7,2,0,29
	  rlwinm    r5,r4,2,0,29
	  lwz       r7, 0x8(r31)
	  rlwinm    r4,r8,2,0,29
	  li        r3, 0x9
	  stwx      r20, r7, r6
	  rlwinm    r8,r3,2,0,29
	  rlwinm    r6,r9,2,0,29
	  lwz       r7, 0x8(r31)
	  li        r3, 0x8
	  stwx      r16, r7, r5
	  lwz       r5, 0x8(r31)
	  stwx      r15, r5, r4
	  lwz       r4, 0x8(r31)
	  stwx      r17, r4, r0
	  lwz       r0, 0x198(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r0, r4, r8
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x10(r4)
	  bl        -0xF974C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xB74
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x6
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x6DDC
	  stw       r0, 0x4(r27)

	.loc_0xB74:
	  li        r3, 0xC
	  bl        -0xF9780
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xB90
	  li        r4, 0xA
	  bl        -0x19700

	.loc_0xB90:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r3, 0x1
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r0, 0x2
	  rlwinm    r0,r0,2,0,29
	  stwx      r22, r4, r5
	  li        r3, 0x3
	  li        r7, 0x4
	  lwz       r5, 0x8(r31)
	  li        r4, 0x5
	  li        r8, 0x6
	  stwx      r19, r5, r0
	  rlwinm    r5,r3,2,0,29
	  li        r0, 0x7
	  lwz       r6, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  li        r9, 0x8
	  stwx      r21, r6, r5
	  rlwinm    r6,r7,2,0,29
	  rlwinm    r5,r4,2,0,29
	  lwz       r7, 0x8(r31)
	  rlwinm    r4,r8,2,0,29
	  li        r3, 0x9
	  stwx      r20, r7, r6
	  rlwinm    r8,r3,2,0,29
	  rlwinm    r6,r9,2,0,29
	  lwz       r7, 0x8(r31)
	  li        r3, 0xC
	  stwx      r16, r7, r5
	  lwz       r7, 0x1A4(r1)
	  lwz       r5, 0x8(r31)
	  stwx      r7, r5, r4
	  lwz       r4, 0x8(r31)
	  stwx      r14, r4, r0
	  lwz       r0, 0x1A8(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r0, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r8
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x14(r4)
	  bl        -0xF984C
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xC88
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0xB
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x3
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0xC88:
	  li        r3, 0xC
	  bl        -0xF9894
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xCA4
	  li        r4, 0x9
	  bl        -0x19814

	.loc_0xCA4:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r8, 0x3
	  stwx      r22, r3, r4
	  li        r6, 0x4
	  li        r5, 0x5
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r8,r8,2,0,29
	  stwx      r19, r3, r0
	  li        r0, 0x7
	  li        r7, 0x6
	  lwz       r4, 0x8(r31)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r5,r5,2,0,29
	  stwx      r21, r4, r8
	  rlwinm    r4,r7,2,0,29
	  li        r3, 0x8
	  lwz       r7, 0x8(r31)
	  rlwinm    r8,r3,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r7, r6
	  li        r3, 0x10
	  lwz       r6, 0x8(r31)
	  stwx      r16, r6, r5
	  lwz       r6, 0x1A4(r1)
	  lwz       r5, 0x8(r31)
	  stwx      r6, r5, r4
	  lwz       r5, 0x1A8(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r8
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x18(r4)
	  bl        -0xF9950
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xDB0
	  lwz       r3, 0x190(r1)
	  lis       r7, 0x802C
	  lis       r6, 0x802D
	  lwz       r3, 0x84(r3)
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lwz       r3, 0x4(r3)
	  addi      r7, r7, 0x6620
	  li        r0, 0x8
	  lwz       r3, 0x0(r3)
	  subi      r6, r6, 0x6A6C
	  subi      r5, r5, 0x6A8C
	  lfs       f0, 0x14(r3)
	  li        r3, 0x4
	  subi      r4, r4, 0x6734
	  stw       r7, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r3, 0x8(r30)
	  stw       r5, 0x4(r30)
	  stw       r4, 0x4(r30)
	  stfs      f0, 0xC(r30)

	.loc_0xDB0:
	  li        r3, 0xC
	  bl        -0xF99BC
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xDCC
	  li        r4, 0xB
	  bl        -0x1993C

	.loc_0xDCC:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r5, 0x2
	  li        r0, 0x3
	  stwx      r22, r3, r4
	  li        r7, 0x4
	  li        r4, 0x5
	  lwz       r3, 0x8(r31)
	  rlwinm    r5,r5,2,0,29
	  li        r8, 0x6
	  stwx      r19, r3, r5
	  li        r6, 0x8
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r7,r7,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r21, r3, r0
	  li        r0, 0xA
	  rlwinm    r8,r8,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r5, 0x7
	  rlwinm    r6,r6,2,0,29
	  stwx      r20, r3, r7
	  rlwinm    r7,r5,2,0,29
	  li        r9, 0x9
	  lwz       r3, 0x8(r31)
	  rlwinm    r5,r9,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r16, r3, r4
	  li        r3, 0x8
	  lwz       r4, 0x8(r31)
	  stwx      r15, r4, r8
	  lwz       r8, 0x19C(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r8, r4, r7
	  lwz       r7, 0x1A0(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r7, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r5
	  lwz       r5, 0x198(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x1C(r4)
	  bl        -0xF9A9C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0xEC4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x7
	  lis       r3, 0x802D
	  stw       r0, 0x0(r27)
	  subi      r0, r3, 0x6784
	  stw       r0, 0x4(r27)

	.loc_0xEC4:
	  li        r3, 0x10
	  bl        -0xF9AD0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xF30
	  lwz       r3, 0x190(r1)
	  lis       r7, 0x802C
	  lis       r6, 0x802D
	  lwz       r3, 0x84(r3)
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lwz       r3, 0x4(r3)
	  addi      r7, r7, 0x6620
	  li        r0, -0x1
	  lwz       r3, 0x0(r3)
	  subi      r6, r6, 0x6A6C
	  subi      r5, r5, 0x6A8C
	  lfs       f0, 0x10(r3)
	  li        r3, 0x7
	  subi      r4, r4, 0x6574
	  stw       r7, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r3, 0x8(r30)
	  stw       r5, 0x4(r30)
	  stw       r4, 0x4(r30)
	  stfs      f0, 0xC(r30)

	.loc_0xF30:
	  li        r3, 0xC
	  bl        -0xF9B3C
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xF4C
	  li        r4, 0xE
	  bl        -0x19ABC

	.loc_0xF4C:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x1B0(r1)
	  li        r7, 0x3
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r6,r4,2,0,29
	  stwx      r30, r3, r0
	  rlwinm    r8,r7,2,0,29
	  li        r0, 0x4
	  lwz       r5, 0x8(r31)
	  li        r4, 0x6
	  li        r9, 0x7
	  stwx      r22, r5, r6
	  li        r7, 0x9
	  rlwinm    r0,r0,2,0,29
	  lwz       r5, 0x8(r31)
	  li        r3, 0x5
	  rlwinm    r4,r4,2,0,29
	  stwx      r19, r5, r8
	  li        r10, 0xC
	  rlwinm    r12,r9,2,0,29
	  lwz       r8, 0x8(r31)
	  rlwinm    r9,r10,2,0,29
	  li        r6, 0x8
	  stwx      r21, r8, r0
	  rlwinm    r8,r3,2,0,29
	  li        r0, 0xD
	  lwz       r3, 0x8(r31)
	  rlwinm    r10,r0,2,0,29
	  lwz       r0, 0x19C(r1)
	  rlwinm    r7,r7,2,0,29
	  stwx      r20, r3, r8
	  rlwinm    r8,r6,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r5, 0xA
	  rlwinm    r6,r5,2,0,29
	  stwx      r16, r3, r4
	  li        r11, 0xB
	  rlwinm    r5,r11,2,0,29
	  lwz       r4, 0x8(r31)
	  li        r3, 0xC
	  stwx      r0, r4, r12
	  lwz       r0, 0x1A0(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r15, r4, r8
	  lwz       r4, 0x8(r31)
	  stwx      r14, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r0, r4, r6
	  lwz       r0, 0x1AC(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r0, r4, r5
	  lwz       r0, 0x198(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r9
	  lwz       r4, 0x8(r31)
	  stwx      r0, r4, r10
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x20(r4)
	  bl        -0xF9C54
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1090
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0x5
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x8
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x1090:
	  li        r3, 0x8
	  bl        -0xF9C9C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x10C4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0xE
	  lis       r3, 0x802C
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x68C8
	  stw       r0, 0x4(r27)

	.loc_0x10C4:
	  li        r3, 0xC
	  bl        -0xF9CD0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x10E0
	  li        r4, 0x7
	  bl        -0x19C50

	.loc_0x10E0:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r4, 0x1
	  rlwinm    r4,r4,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2
	  li        r6, 0x3
	  stwx      r22, r3, r4
	  rlwinm    r3,r0,2,0,29
	  li        r0, 0x6
	  lwz       r5, 0x8(r31)
	  li        r4, 0x4
	  li        r7, 0x5
	  stwx      r21, r5, r3
	  rlwinm    r3,r6,2,0,29
	  rlwinm    r5,r4,2,0,29
	  lwz       r6, 0x8(r31)
	  rlwinm    r4,r7,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r6, r3
	  li        r3, 0xC
	  lwz       r6, 0x8(r31)
	  stwx      r27, r6, r5
	  lwz       r5, 0x8(r31)
	  stwx      r30, r5, r4
	  lwz       r5, 0x194(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x24(r4)
	  bl        -0xF9D68
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x11A0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r31)
	  li        r0, 0x5
	  lis       r3, 0x802D
	  stw       r0, 0x0(r31)
	  subi      r4, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r4, 0x4(r31)
	  subi      r3, r3, 0x6B9C
	  stw       r0, 0x8(r31)
	  stw       r3, 0x4(r31)

	.loc_0x11A0:
	  li        r3, 0x24
	  bl        -0xF9DAC
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x11BC
	  lfs       f1, -0x5954(r2)
	  bl        0x111C

	.loc_0x11BC:
	  li        r3, 0xC
	  bl        -0xF9DC8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x11D8
	  li        r4, 0x5
	  bl        -0x19D48

	.loc_0x11D8:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r22, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  li        r5, 0x3
	  stwx      r21, r3, r0
	  li        r0, 0x4
	  rlwinm    r4,r4,2,0,29
	  lwz       r3, 0x8(r30)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r30)
	  stwx      r31, r4, r5
	  lwz       r4, 0x8(r30)
	  stwx      r23, r4, r0
	  lwz       r4, 0x8(r29)
	  stw       r30, 0x38(r4)
	  bl        -0xF9E3C
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x1278
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r31)
	  li        r0, 0x5
	  lis       r3, 0x802D
	  stw       r0, 0x0(r31)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r31)
	  li        r0, 0xA
	  subi      r3, r3, 0x3F50
	  stw       r0, 0x8(r31)
	  stw       r3, 0x4(r31)

	.loc_0x1278:
	  li        r3, 0xC
	  bl        -0xF9E84
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1294
	  li        r4, 0x5
	  bl        -0x19E04

	.loc_0x1294:
	  li        r0, 0
	  lwz       r3, 0x8(r30)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x1B4(r1)
	  li        r5, 0x3
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r22, r3, r0
	  li        r0, 0x4
	  rlwinm    r5,r5,2,0,29
	  lwz       r3, 0x8(r30)
	  rlwinm    r0,r0,2,0,29
	  stwx      r21, r3, r4
	  li        r3, 0x10
	  lwz       r4, 0x8(r30)
	  stwx      r20, r4, r5
	  lwz       r4, 0x8(r30)
	  stwx      r31, r4, r0
	  lwz       r4, 0x8(r29)
	  stw       r30, 0x28(r4)
	  bl        -0xF9EFC
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x135C
	  lwz       r3, 0x190(r1)
	  lis       r7, 0x802C
	  lis       r6, 0x802D
	  lwz       r3, 0x84(r3)
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lwz       r3, 0x4(r3)
	  addi      r7, r7, 0x6620
	  li        r0, 0xC
	  lwz       r3, 0x0(r3)
	  subi      r6, r6, 0x6A6C
	  subi      r5, r5, 0x6A8C
	  lfs       f0, 0x14(r3)
	  li        r3, 0x4
	  subi      r4, r4, 0x67CC
	  stw       r7, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r3, 0x8(r30)
	  stw       r5, 0x4(r30)
	  stw       r4, 0x4(r30)
	  stfs      f0, 0xC(r30)

	.loc_0x135C:
	  li        r3, 0x8
	  bl        -0xF9F68
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x1390
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r26)
	  subi      r0, r3, 0x69B4
	  stw       r0, 0x4(r26)

	.loc_0x1390:
	  li        r3, 0xC
	  bl        -0xF9F9C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x13DC
	  lwz       r3, 0x190(r1)
	  lis       r4, 0x802C
	  addi      r4, r4, 0x6620
	  lwz       r5, 0x84(r3)
	  lis       r3, 0x802D
	  li        r0, 0xD
	  lwz       r5, 0x4(r5)
	  subi      r3, r3, 0x7B18
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0x40(r5)
	  stw       r4, 0x4(r27)
	  stw       r0, 0x0(r27)
	  stw       r3, 0x4(r27)
	  stfs      f0, 0x8(r27)

	.loc_0x13DC:
	  li        r3, 0xC
	  bl        -0xF9FE8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x13F8
	  li        r4, 0x9
	  bl        -0x19F68

	.loc_0x13F8:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2
	  li        r4, 0x3
	  stwx      r22, r3, r5
	  li        r5, 0x4
	  li        r6, 0x5
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r19, r3, r0
	  li        r0, 0x7
	  rlwinm    r8,r5,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r7, 0x6
	  rlwinm    r6,r6,2,0,29
	  stwx      r21, r3, r4
	  rlwinm    r5,r7,2,0,29
	  li        r9, 0x8
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r7,r9,2,0,29
	  stwx      r20, r3, r8
	  li        r3, 0x10
	  lwz       r4, 0x8(r31)
	  stwx      r16, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r26, r4, r5
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r0
	  lwz       r0, 0x198(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r0, r4, r7
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x2C(r4)
	  bl        -0xFA0A0
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1500
	  lwz       r3, 0x190(r1)
	  lis       r7, 0x802C
	  lis       r6, 0x802D
	  lwz       r3, 0x84(r3)
	  lis       r5, 0x802D
	  lis       r4, 0x802D
	  lwz       r3, 0x4(r3)
	  addi      r7, r7, 0x6620
	  li        r0, -0x1
	  lwz       r3, 0x0(r3)
	  subi      r6, r6, 0x6A6C
	  subi      r5, r5, 0x6A8C
	  lfs       f0, 0x10(r3)
	  li        r3, 0x7
	  subi      r4, r4, 0x65C4
	  stw       r7, 0x4(r30)
	  stw       r0, 0x0(r30)
	  stw       r6, 0x4(r30)
	  stw       r3, 0x8(r30)
	  stw       r5, 0x4(r30)
	  stw       r4, 0x4(r30)
	  stfs      f0, 0xC(r30)

	.loc_0x1500:
	  li        r3, 0xC
	  bl        -0xFA10C
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x151C
	  li        r4, 0xA
	  bl        -0x1A08C

	.loc_0x151C:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x1B0(r1)
	  li        r5, 0x3
	  stwx      r0, r3, r4
	  li        r4, 0x1
	  rlwinm    r7,r5,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r4,r4,2,0,29
	  li        r0, 0x2
	  stwx      r30, r3, r4
	  rlwinm    r4,r0,2,0,29
	  li        r0, 0x6
	  lwz       r3, 0x8(r31)
	  li        r6, 0x4
	  li        r8, 0x5
	  stwx      r22, r3, r4
	  li        r4, 0x7
	  li        r5, 0x9
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r19, r3, r7
	  rlwinm    r7,r6,2,0,29
	  rlwinm    r6,r8,2,0,29
	  lwz       r3, 0x8(r31)
	  rlwinm    r8,r5,2,0,29
	  li        r9, 0x8
	  stwx      r21, r3, r7
	  rlwinm    r7,r9,2,0,29
	  li        r3, 0xC
	  lwz       r5, 0x8(r31)
	  stwx      r20, r5, r6
	  lwz       r5, 0x8(r31)
	  stwx      r16, r5, r0
	  lwz       r0, 0x1A4(r1)
	  lwz       r5, 0x8(r31)
	  stwx      r0, r5, r4
	  lwz       r0, 0x198(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r27, r4, r7
	  lwz       r4, 0x8(r31)
	  stwx      r0, r4, r8
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x30(r4)
	  bl        -0xFA1DC
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x1618
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, 0x1
	  lis       r3, 0x802D
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x6A6C
	  lis       r3, 0x802D
	  stw       r0, 0x4(r30)
	  li        r0, 0x3
	  subi      r3, r3, 0x6A8C
	  stw       r0, 0x8(r30)
	  stw       r3, 0x4(r30)

	.loc_0x1618:
	  li        r3, 0xC
	  bl        -0xFA224
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x1634
	  li        r4, 0x9
	  bl        -0x1A1A4

	.loc_0x1634:
	  li        r0, 0
	  lwz       r3, 0x8(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r18, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r6, 0x2
	  rlwinm    r7,r6,2,0,29
	  stwx      r22, r3, r4
	  li        r0, 0x3
	  li        r4, 0x4
	  lwz       r3, 0x8(r31)
	  li        r5, 0x5
	  rlwinm    r0,r0,2,0,29
	  stwx      r19, r3, r7
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r5,r5,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r6, 0x6
	  li        r7, 0x7
	  stwx      r21, r3, r0
	  rlwinm    r0,r6,2,0,29
	  rlwinm    r6,r7,2,0,29
	  lwz       r3, 0x8(r31)
	  li        r8, 0x8
	  rlwinm    r7,r8,2,0,29
	  stwx      r20, r3, r4
	  mr        r3, r29
	  lwz       r4, 0x8(r31)
	  stwx      r16, r4, r5
	  lwz       r4, 0x1A4(r1)
	  lwz       r5, 0x8(r31)
	  stwx      r4, r5, r0
	  lwz       r0, 0x1A8(r1)
	  lwz       r4, 0x8(r31)
	  stwx      r0, r4, r6
	  lwz       r4, 0x8(r31)
	  stwx      r30, r4, r7
	  lwz       r4, 0x8(r29)
	  stw       r31, 0x34(r4)
	  lmw       r14, 0x1B8(r1)
	  lwz       r0, 0x204(r1)
	  addi      r1, r1, 0x200
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801412F8
 * Size:	000084
 */
void TaiSwallowStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  addi      r5, r1, 0x10
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  li        r4, 0x65
	  lfs       f0, -0xC5C(r13)
	  lfs       f1, -0xC58(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0xC54(r13)
	  stfs      f1, 0x14(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x18(r1)
	  bl        0x5B7F8
	  lwz       r5, 0x3D8(r31)
	  mr        r4, r31
	  stw       r3, 0x0(r5)
	  mr        r3, r30
	  bl        -0x19EC0
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x86BC
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
 * Address:	8014137C
 * Size:	0000FC
 */
void TaiSwallowStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stfd      f30, 0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  bl        0xBE24
	  lwz       r3, 0x3D8(r31)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xDC
	  lwz       r3, 0x410(r31)
	  lwz       r0, -0x9AC(r13)
	  and.      r0, r3, r0
	  bne-      .loc_0x58
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x8650
	  b         .loc_0xDC

	.loc_0x58:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x1C4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDC
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        0x8608
	  addi      r3, r1, 0x30
	  bl        -0x245A4
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xDA750
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xDA8D8
	  stfs      f1, 0x30(r1)
	  mr        r3, r31
	  lfs       f0, -0xC60(r13)
	  addi      r5, r1, 0x30
	  li        r4, 0
	  stfs      f0, 0x34(r1)
	  stfs      f31, 0x38(r1)
	  bl        0x8640
	  addi      r3, r1, 0x24
	  bl        -0x245E4
	  addi      r3, r31, 0
	  addi      r4, r1, 0x24
	  bl        0x516C
	  addi      r3, r31, 0
	  addi      r5, r1, 0x24
	  li        r4, 0
	  bl        0x85EC

	.loc_0xDC:
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lfd       f30, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80141478
 * Size:	000128
 */
void TaiSwallowStrategy::interact(Teki&, TekiInteractionKey&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x88(r1)
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  bne-      .loc_0x108
	  lwz       r3, 0x410(r31)
	  lwz       r0, -0x9B4(r13)
	  lwz       r30, 0x4(r5)
	  and.      r0, r3, r0
	  beq-      .loc_0x40
	  li        r3, 0
	  b         .loc_0x110

	.loc_0x40:
	  lwz       r0, -0x9A4(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0xB0
	  mr        r3, r30
	  bl        -0xC5488
	  cmpwi     r3, 0x1
	  beq-      .loc_0xA0
	  lwz       r3, 0x2C4(r31)
	  lfs       f1, 0x8(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xCC(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8(r30)
	  lwz       r3, 0x2C4(r31)
	  lfs       f1, 0x340(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xD0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x340(r31)
	  b         .loc_0xB0

	.loc_0xA0:
	  lfs       f1, 0x340(r31)
	  lfs       f0, -0x59C8(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x340(r31)

	.loc_0xB0:
	  mr        r3, r30
	  bl        -0xC54EC
	  stw       r3, 0x344(r31)
	  lfs       f1, 0x33C(r31)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x33C(r31)
	  lwz       r3, 0x41C(r31)
	  lwz       r30, 0x4(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xEC
	  beq-      .loc_0xEC
	  bl        -0x5D1EC
	  li        r0, 0
	  stw       r0, 0x41C(r31)

	.loc_0xEC:
	  stw       r30, 0x41C(r31)
	  lwz       r3, 0x41C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x100
	  bl        -0x5D218

	.loc_0x100:
	  li        r3, 0x1
	  b         .loc_0x110

	.loc_0x108:
	  mr        r4, r31
	  bl        0xBCA8

	.loc_0x110:
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801415A0
 * Size:	000024
 */
bool TaiSwallowStrategy::isSleeping(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x324(r4)
	  li        r3, 0x1
	  cmpwi     r0, 0xF
	  beqlr-
	  lwz       r0, 0x324(r4)
	  cmpwi     r0, 0x1
	  beqlr-
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801415C4
 * Size:	000034
 */
void TaiSwallowStrategy::drawDebugInfo(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r4)
	  mr        r4, r5
	  lwz       r12, 0x1B8(r12)
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
 * Address:	801415F8
 * Size:	00001C
 */
bool TaiSwallowReceiveMessageAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x4
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80141614
 * Size:	0001DC
 */
bool TaiSwallowTurningAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x148(r1)
	  stfd      f31, 0x140(r1)
	  stmw      r26, 0x128(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  bl        -0xD4C4
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  mr        r4, r30
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x1C4

	.loc_0x48:
	  lwz       r31, 0x418(r30)
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  bne-      .loc_0x60
	  li        r3, 0x1
	  b         .loc_0x1C4

	.loc_0x60:
	  lis       r3, 0x802B
	  subi      r26, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r26, 0x118(r1)
	  addi      r27, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r27, 0x118(r1)
	  subi      r28, r3, 0x295C
	  stw       r28, 0x118(r1)
	  addi      r3, r1, 0x118
	  stw       r30, 0x11C(r1)
	  bl        0x87F0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA0
	  li        r3, 0x1
	  b         .loc_0x1C4

	.loc_0xA0:
	  stw       r26, 0xF0(r1)
	  lis       r3, 0x802C
	  addi      r6, r3, 0x685C
	  stw       r26, 0xE0(r1)
	  lis       r5, 0x802D
	  subi      r7, r5, 0x2B68
	  stw       r26, 0xE8(r1)
	  addi      r5, r1, 0xE8
	  addi      r0, r1, 0xE0
	  stw       r27, 0xF0(r1)
	  addi      r4, r1, 0xF0
	  addi      r3, r30, 0
	  stw       r27, 0xE0(r1)
	  stw       r27, 0xE8(r1)
	  stw       r6, 0xF0(r1)
	  stw       r7, 0xE0(r1)
	  stw       r28, 0xE8(r1)
	  stw       r5, 0xF4(r1)
	  stw       r30, 0xE4(r1)
	  stw       r30, 0xEC(r1)
	  stw       r0, 0xF8(r1)
	  bl        0x6D58
	  addi      r28, r3, 0
	  addi      r3, r1, 0xFC
	  addi      r4, r1, 0x110
	  bl        -0x25EA0
	  lwz       r4, 0x2C4(r30)
	  addi      r3, r1, 0xFC
	  lfs       f1, -0x59D0(r2)
	  lwz       r4, 0x84(r4)
	  lfs       f2, -0x59C8(r2)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f4, 0xD8(r4)
	  lfs       f3, 0xD4(r4)
	  bl        -0x25E24
	  xoris     r0, r28, 0x8000
	  lfd       f1, -0x5950(r2)
	  stw       r0, 0x124(r1)
	  lis       r0, 0x4330
	  addi      r3, r1, 0xFC
	  stw       r0, 0x120(r1)
	  lfd       f0, 0x120(r1)
	  fsubs     f1, f0, f1
	  bl        -0x25DB8
	  lfs       f2, 0xC(r29)
	  lfs       f0, -0x59D0(r2)
	  fmuls     f31, f2, f1
	  stfs      f0, 0xBC(r1)
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xB4(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x94(r30)
	  lfs       f4, 0x9C(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r30)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x98(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0xA0(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0xA0(r1)
	  stfs      f0, 0xB4(r1)
	  stfs      f1, 0xB8(r1)
	  stfs      f3, 0xBC(r1)
	  lfs       f1, 0xB4(r1)
	  lfs       f2, 0xBC(r1)
	  bl        -0x239B8
	  stfs      f1, 0x394(r30)
	  fmr       f2, f31
	  mr        r3, r30
	  lfs       f1, 0x394(r30)
	  bl        0x5DF8

	.loc_0x1C4:
	  lmw       r26, 0x128(r1)
	  lwz       r0, 0x14C(r1)
	  lfd       f31, 0x140(r1)
	  addi      r1, r1, 0x148
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801417F0
 * Size:	000044
 */
void TaiSwallowFlickingAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0xD7EC
	  mr        r3, r31
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80141834
 * Size:	000034
 */
void TaiSwallowFlickingAction::finish(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x1CC(r12)
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
 * Address:	80141868
 * Size:	00007C
 */
bool TaiSwallowFlickingAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r4, 0x2CC(r4)
	  lwz       r0, 0x38(r4)
	  cmpwi     r0, 0
	  bge-      .loc_0x44
	  mr        r3, r31
	  lwz       r4, -0x9A4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1
	  b         .loc_0x68

	.loc_0x44:
	  lwz       r4, 0x414(r31)
	  lwz       r0, -0x99C(r13)
	  and.      r0, r4, r0
	  beq-      .loc_0x64
	  mr        r4, r31
	  bl        .loc_0x7C
	  lfs       f0, -0x59D0(r2)
	  stfs      f0, 0x340(r31)

	.loc_0x64:
	  li        r3, 0

	.loc_0x68:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0x7C:
	*/
}

/*
 * --INFO--
 * Address:	801418E4
 * Size:	0001DC
 */
void TaiSwallowFlickingAction::flick(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F0(r1)
	  stfd      f31, 0x1E8(r1)
	  stfd      f30, 0x1E0(r1)
	  stmw      r24, 0x1C0(r1)
	  addi      r28, r4, 0
	  addi      r3, r28, 0
	  bl        0x64E8
	  lwz       r3, 0x2C4(r28)
	  lis       r7, 0x802B
	  lis       r6, 0x802B
	  lfs       f0, -0x5948(r2)
	  lwz       r3, 0x84(r3)
	  lis       r5, 0x802B
	  lwz       r8, 0x4(r3)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r8, 0x0(r8)
	  subi      r7, r7, 0x3064
	  subi      r6, r6, 0x3168
	  lfs       f1, 0x90(r8)
	  subi      r30, r5, 0xF68
	  lfs       f2, 0x88(r8)
	  addi      r31, r4, 0x6964
	  subi      r0, r3, 0x2C1C
	  stw       r7, 0x1A8(r1)
	  addi      r29, r1, 0x1A8
	  li        r4, 0
	  stw       r28, 0x1AC(r1)
	  stw       r6, 0x1A8(r1)
	  stfs      f2, 0x1B0(r1)
	  stfs      f1, 0x1B4(r1)
	  stfs      f0, 0x1B8(r1)
	  lwz       r3, 0x2C4(r28)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xDC(r3)
	  stw       r30, 0x158(r1)
	  stw       r31, 0x158(r1)
	  stw       r0, 0x158(r1)
	  stw       r28, 0x15C(r1)
	  stfs      f0, 0x160(r1)
	  lwz       r3, 0x2C8(r28)
	  lwz       r3, 0x34(r3)
	  bl        -0x1E78C
	  lwz       r3, 0x2C4(r28)
	  fmr       f30, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x1E7A0
	  lwz       r3, 0x2C4(r28)
	  fmr       f31, f1
	  li        r4, 0x2D
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x1F4F4
	  stw       r30, 0x164(r1)
	  fmuls     f0, f31, f30
	  lis       r3, 0x802D
	  stw       r30, 0x170(r1)
	  lis       r6, 0x802C
	  subi      r24, r3, 0x29D8
	  stw       r30, 0x190(r1)
	  addi      r25, r6, 0x685C
	  lis       r4, 0x802C
	  fmuls     f0, f1, f0
	  stw       r30, 0x19C(r1)
	  lis       r3, 0x802D
	  stw       r31, 0x164(r1)
	  addi      r11, r4, 0x6890
	  subi      r9, r3, 0x295C
	  stw       r31, 0x170(r1)
	  lis       r7, 0x802D
	  subi      r12, r7, 0x2924
	  stw       r30, 0x180(r1)
	  addi      r26, r1, 0x164
	  addi      r8, r1, 0x188
	  stw       r30, 0x188(r1)
	  addi      r6, r1, 0x190
	  addi      r27, r1, 0x158
	  stw       r31, 0x190(r1)
	  addi      r10, r1, 0x17C
	  addi      r7, r1, 0x180
	  stw       r31, 0x19C(r1)
	  addi      r0, r1, 0x170
	  addi      r5, r1, 0x19C
	  stw       r24, 0x164(r1)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  stw       r25, 0x170(r1)
	  stw       r30, 0x17C(r1)
	  stw       r31, 0x180(r1)
	  stw       r31, 0x188(r1)
	  stw       r25, 0x190(r1)
	  stw       r25, 0x19C(r1)
	  stw       r28, 0x168(r1)
	  stw       r26, 0x174(r1)
	  stw       r31, 0x17C(r1)
	  stw       r11, 0x180(r1)
	  stw       r9, 0x188(r1)
	  stw       r8, 0x194(r1)
	  stw       r6, 0x1A0(r1)
	  stfs      f0, 0x16C(r1)
	  stw       r27, 0x178(r1)
	  stw       r12, 0x17C(r1)
	  stw       r10, 0x184(r1)
	  stw       r28, 0x18C(r1)
	  stw       r7, 0x198(r1)
	  stw       r0, 0x1A4(r1)
	  bl        0x6078
	  lmw       r24, 0x1C0(r1)
	  lwz       r0, 0x1F4(r1)
	  lfd       f31, 0x1E8(r1)
	  lfd       f30, 0x1E0(r1)
	  addi      r1, r1, 0x1F0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80141AC0
 * Size:	0001F0
 */
bool TaiSwallowSwallowingFlickAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F8(r1)
	  stfd      f31, 0x1F0(r1)
	  stfd      f30, 0x1E8(r1)
	  stmw      r24, 0x1C8(r1)
	  mr        r28, r4
	  lwz       r0, -0x99C(r13)
	  lwz       r3, 0x414(r4)
	  and.      r0, r3, r0
	  beq-      .loc_0x1D0
	  lwz       r3, 0x2C4(r28)
	  lis       r7, 0x802B
	  lis       r6, 0x802B
	  lfs       f0, 0xA0(r28)
	  lwz       r3, 0x84(r3)
	  lfs       f1, -0x1CA4(r13)
	  lis       r5, 0x802B
	  lwz       r8, 0x4(r3)
	  lis       r4, 0x802C
	  lis       r3, 0x802D
	  lwz       r8, 0x0(r8)
	  subi      r0, r7, 0x3064
	  subi      r6, r6, 0x3168
	  fadds     f0, f1, f0
	  lfs       f1, 0x90(r8)
	  lfs       f2, 0x88(r8)
	  subi      r30, r5, 0xF68
	  addi      r31, r4, 0x6964
	  stw       r0, 0x1B4(r1)
	  subi      r0, r3, 0x2C1C
	  addi      r29, r1, 0x1B4
	  stw       r28, 0x1B8(r1)
	  li        r4, 0
	  stw       r6, 0x1B4(r1)
	  stfs      f2, 0x1BC(r1)
	  stfs      f1, 0x1C0(r1)
	  stfs      f0, 0x1C4(r1)
	  lwz       r3, 0x2C4(r28)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xDC(r3)
	  stw       r30, 0x164(r1)
	  stw       r31, 0x164(r1)
	  stw       r0, 0x164(r1)
	  stw       r28, 0x168(r1)
	  stfs      f0, 0x16C(r1)
	  lwz       r3, 0x2C8(r28)
	  lwz       r3, 0x34(r3)
	  bl        -0x1E978
	  lwz       r3, 0x2C4(r28)
	  fmr       f30, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x1E98C
	  lwz       r3, 0x2C4(r28)
	  fmr       f31, f1
	  li        r4, 0x2D
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x1F6E0
	  stw       r30, 0x170(r1)
	  fmuls     f0, f31, f30
	  lis       r3, 0x802D
	  stw       r30, 0x17C(r1)
	  lis       r6, 0x802C
	  subi      r24, r3, 0x29D8
	  stw       r30, 0x19C(r1)
	  addi      r25, r6, 0x685C
	  lis       r4, 0x802C
	  fmuls     f0, f1, f0
	  stw       r30, 0x1A8(r1)
	  lis       r3, 0x802D
	  stw       r31, 0x170(r1)
	  addi      r11, r4, 0x6890
	  subi      r9, r3, 0x295C
	  stw       r31, 0x17C(r1)
	  lis       r7, 0x802D
	  subi      r12, r7, 0x2924
	  stw       r30, 0x18C(r1)
	  addi      r26, r1, 0x170
	  addi      r8, r1, 0x194
	  stw       r30, 0x194(r1)
	  addi      r6, r1, 0x19C
	  addi      r27, r1, 0x164
	  stw       r31, 0x19C(r1)
	  addi      r10, r1, 0x188
	  addi      r7, r1, 0x18C
	  stw       r31, 0x1A8(r1)
	  addi      r0, r1, 0x17C
	  addi      r5, r1, 0x1A8
	  stw       r24, 0x170(r1)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  stw       r25, 0x17C(r1)
	  stw       r30, 0x188(r1)
	  stw       r31, 0x18C(r1)
	  stw       r31, 0x194(r1)
	  stw       r25, 0x19C(r1)
	  stw       r25, 0x1A8(r1)
	  stw       r28, 0x174(r1)
	  stw       r26, 0x180(r1)
	  stw       r31, 0x188(r1)
	  stw       r11, 0x18C(r1)
	  stw       r9, 0x194(r1)
	  stw       r8, 0x1A0(r1)
	  stw       r6, 0x1AC(r1)
	  stfs      f0, 0x178(r1)
	  stw       r27, 0x184(r1)
	  stw       r12, 0x188(r1)
	  stw       r10, 0x190(r1)
	  stw       r28, 0x198(r1)
	  stw       r7, 0x1A4(r1)
	  stw       r0, 0x1B0(r1)
	  bl        0x5E8C

	.loc_0x1D0:
	  lmw       r24, 0x1C8(r1)
	  li        r3, 0
	  lwz       r0, 0x1FC(r1)
	  lfd       f31, 0x1F0(r1)
	  lfd       f30, 0x1E8(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80141CB0
 * Size:	000028
 */
void TaiSwallowSnoreAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0
	  stwu      r1, -0x8(r1)
	  bl        0x7D34
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80141CD8
 * Size:	000028
 */
void TaiSwallowSnoreAction::finish(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0
	  stwu      r1, -0x8(r1)
	  bl        0x7D30
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80141D00
 * Size:	0000C4
 */
bool TaiSwallowNoticeAction::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802B
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802C
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  mr        r30, r4
	  lwz       r3, 0x2C4(r4)
	  addi      r4, r1, 0x50
	  lwz       r7, 0x84(r3)
	  lis       r3, 0x802D
	  subi      r0, r3, 0x29D8
	  lwz       r8, 0x4(r7)
	  subi      r7, r6, 0xF68
	  addi      r6, r5, 0x6964
	  lwz       r5, 0x0(r8)
	  addi      r3, r30, 0
	  lfs       f0, 0xC8(r5)
	  li        r5, 0
	  stw       r7, 0x50(r1)
	  stw       r6, 0x50(r1)
	  stw       r0, 0x50(r1)
	  stw       r30, 0x54(r1)
	  stfs      f0, 0x58(r1)
	  bl        0x597C
	  mr.       r31, r3
	  bne-      .loc_0x78
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0x78:
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x94
	  beq-      .loc_0x94
	  bl        -0x5DA1C
	  li        r0, 0
	  stw       r0, 0x418(r30)

	.loc_0x94:
	  stw       r31, 0x418(r30)
	  lwz       r3, 0x418(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  bl        -0x5DA48

	.loc_0xA8:
	  li        r3, 0x1

	.loc_0xAC:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80141DC4
 * Size:	000058
 */
TaiSwallowLegEffectAction::TaiSwallowLegEffectAction(f32 p1)
    : TaiJointEffectAction(p1, 0, 0, 0, 0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x6C6C
	  stw       r0, 0x4(r1)
	  lis       r4, 0x726C
	  addi      r6, r4, 0x6567
	  stwu      r1, -0x18(r1)
	  addi      r5, r5, 0x6567
	  li        r4, 0x2
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x137BC
	  lis       r3, 0x802D
	  subi      r0, r3, 0x4118
	  stw       r0, 0x4(r31)
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
 * Address:	80141E1C
 * Size:	0000C4
 */
void TaiSwallowLegEffectAction::setType(Vector3f&, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x30(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x28(r1)
	  addi      r28, r3, 0
	  addi      r3, r1, 0x18
	  bl        -0xFDFF0
	  addi      r3, r1, 0x18
	  addi      r4, r31, 0
	  bl        -0xFDF94
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x0(r29)
	  lfs       f2, 0x8(r29)
	  bl        -0xD9F68
	  cmpwi     r30, 0x5
	  stfs      f1, 0x4(r29)
	  bne-      .loc_0x6C
	  li        r0, 0xF
	  stw       r0, 0x14(r28)
	  b         .loc_0x88

	.loc_0x6C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x80
	  li        r0, -0x1
	  stw       r0, 0x14(r28)
	  b         .loc_0x88

	.loc_0x80:
	  li        r0, 0x43
	  stw       r0, 0x14(r28)

	.loc_0x88:
	  li        r0, 0x1
	  stw       r0, 0x18(r28)
	  addi      r6, r29, 0
	  li        r4, 0xF
	  lwz       r3, 0x3178(r13)
	  li        r5, 0
	  bl        0x3AF18
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80141EE0
 * Size:	000054
 */
TaiSwallowMissAttackingEffectAction::TaiSwallowMissAttackingEffectAction(f32 p1)
    : TaiJointEffectAction(p1, 0, 0, 0, 0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x6861
	  stw       r0, 0x4(r1)
	  addi      r5, r4, 0x6E61
	  li        r4, 0x1
	  stwu      r1, -0x18(r1)
	  li        r6, 0
	  li        r7, 0
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  li        r8, 0
	  bl        -0x138D4
	  lis       r3, 0x802D
	  subi      r0, r3, 0x4170
	  stw       r0, 0x4(r31)
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
 * Address:	80141F34
 * Size:	00009C
 */
void TaiSwallowMissAttackingEffectAction::setType(Vector3f&, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r5
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r4)
	  lfs       f2, 0x8(r4)
	  li        r4, 0x1
	  bl        -0xDA064
	  cmpwi     r31, 0x5
	  stfs      f1, 0x4(r30)
	  bne-      .loc_0x50
	  li        r0, 0xF
	  stw       r0, 0x14(r29)
	  b         .loc_0x6C

	.loc_0x50:
	  cmpwi     r31, -0x1
	  bne-      .loc_0x64
	  li        r0, -0x1
	  stw       r0, 0x14(r29)
	  b         .loc_0x6C

	.loc_0x64:
	  li        r0, 0x43
	  stw       r0, 0x14(r29)

	.loc_0x6C:
	  lwz       r3, 0x3178(r13)
	  addi      r6, r30, 0
	  li        r4, 0x2
	  li        r5, 0
	  bl        0x3AE24
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}
