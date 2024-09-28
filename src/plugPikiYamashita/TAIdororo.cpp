#include "TAI/Dororo.h"

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

namespace {
/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void getCollPartPtr(Teki&, u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801D0FBC
 * Size:	0001E4
 */
void setDororoEffect(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x6C65
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x7965
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  mr        r30, r3
	  stw       r0, 0x24(r1)
	  lwz       r3, 0x220(r3)
	  lwz       r4, 0x24(r1)
	  bl        -0x1478D8
	  mr.       r31, r3
	  cmplwi    r31, 0
	  beq-      .loc_0x68
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x9D
	  li        r6, 0
	  li        r7, 0
	  bl        -0x344D4
	  cmplwi    r3, 0
	  beq-      .loc_0x64
	  addi      r0, r31, 0x4
	  stw       r0, 0x18(r3)

	.loc_0x64:
	  stw       r3, 0x498(r30)

	.loc_0x68:
	  lis       r3, 0x7265
	  addi      r0, r3, 0x7965
	  stw       r0, 0x1C(r1)
	  lwz       r3, 0x220(r30)
	  lwz       r4, 0x1C(r1)
	  bl        -0x147928
	  mr.       r31, r3
	  cmplwi    r31, 0
	  beq-      .loc_0xB8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0x9D
	  li        r6, 0
	  li        r7, 0
	  bl        -0x34524
	  cmplwi    r3, 0
	  beq-      .loc_0xB4
	  addi      r0, r31, 0x4
	  stw       r0, 0x18(r3)

	.loc_0xB4:
	  stw       r3, 0x49C(r30)

	.loc_0xB8:
	  lis       r3, 0x6B62
	  addi      r0, r3, 0x3031
	  stw       r0, 0x14(r1)
	  lwz       r3, 0x220(r30)
	  lwz       r4, 0x14(r1)
	  bl        -0x147978
	  mr.       r31, r3
	  cmplwi    r31, 0
	  beq-      .loc_0x17C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0xAF
	  li        r6, 0
	  li        r7, 0
	  bl        -0x34574
	  cmplwi    r3, 0
	  beq-      .loc_0x104
	  addi      r0, r31, 0x4
	  stw       r0, 0x18(r3)

	.loc_0x104:
	  stw       r3, 0x4B0(r30)
	  addi      r5, r31, 0x4
	  li        r4, 0xAB
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        -0x345A0
	  cmplwi    r3, 0
	  beq-      .loc_0x130
	  addi      r0, r31, 0x4
	  stw       r0, 0x18(r3)

	.loc_0x130:
	  stw       r3, 0x4A0(r30)
	  addi      r5, r31, 0x4
	  li        r4, 0xAC
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        -0x345CC
	  cmplwi    r3, 0
	  beq-      .loc_0x15C
	  addi      r0, r31, 0x4
	  stw       r0, 0x18(r3)

	.loc_0x15C:
	  stw       r3, 0x4A4(r30)
	  addi      r5, r31, 0x4
	  li        r4, 0xAE
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        -0x345F8
	  stw       r3, 0x4AC(r30)

	.loc_0x17C:
	  lis       r3, 0x6D6E
	  addi      r0, r3, 0x3031
	  stw       r0, 0xC(r1)
	  lwz       r3, 0x220(r30)
	  lwz       r4, 0xC(r1)
	  bl        -0x147A3C
	  mr.       r31, r3
	  cmplwi    r31, 0
	  beq-      .loc_0x1CC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x4
	  li        r4, 0xAD
	  li        r6, 0
	  li        r7, 0
	  bl        -0x34638
	  cmplwi    r3, 0
	  beq-      .loc_0x1C8
	  addi      r0, r31, 0x4
	  stw       r0, 0x18(r3)

	.loc_0x1C8:
	  stw       r3, 0x4A8(r30)

	.loc_0x1CC:
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
 * Address:	........
 * Size:	0000DC
 */
void killDororoEffect(Teki&)
{
	// UNUSED FUNCTION
}
} // namespace

/*
 * --INFO--
 * Address:	801D11A0
 * Size:	000084
 */
TAIdororoSoundTable::TAIdororoSoundTable()
    : PaniSoundTable(6)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x6
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0xB214C
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0x18A1D0
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x96
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
 * Address:	801D1224
 * Size:	0003C0
 */
TAIdororoParameters::TAIdororoParameters()
    : TekiParameters(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802E
	  stw       r0, 0x4(r1)
	  li        r5, 0x37
	  stwu      r1, -0xD0(r1)
	  stw       r31, 0xCC(r1)
	  addi      r31, r4, 0x3D60
	  li        r4, 0x15
	  stw       r30, 0xC8(r1)
	  addi      r30, r3, 0
	  bl        -0x85504
	  lis       r3, 0x802E
	  addi      r0, r3, 0x4600
	  stw       r0, 0x0(r30)
	  li        r7, 0x32
	  li        r6, 0x33
	  lwz       r4, 0x84(r30)
	  li        r5, 0x34
	  li        r3, 0x35
	  lwz       r8, 0x4(r4)
	  li        r0, 0x36
	  lwz       r9, 0x0(r4)
	  mulli     r7, r7, 0xC
	  lwz       r10, 0x8(r8)
	  lwz       r11, 0x8(r9)
	  add       r8, r10, r7
	  addi      r7, r31, 0x1C
	  stw       r7, 0x0(r8)
	  mulli     r7, r6, 0xC
	  lfs       f7, -0x4360(r2)
	  mulli     r6, r5, 0xC
	  stfs      f7, 0x4(r8)
	  lfs       f0, -0x435C(r2)
	  mulli     r5, r3, 0xC
	  stfs      f0, 0x8(r8)
	  add       r7, r10, r7
	  addi      r3, r31, 0x2C
	  stw       r3, 0x0(r7)
	  mulli     r3, r0, 0xC
	  stfs      f7, 0x4(r7)
	  add       r8, r10, r6
	  stfs      f0, 0x8(r7)
	  addi      r6, r31, 0x3C
	  li        r0, 0x14
	  stw       r6, 0x0(r8)
	  mulli     r0, r0, 0xC
	  stfs      f7, 0x4(r8)
	  add       r9, r10, r5
	  lfs       f6, -0x4358(r2)
	  addi      r5, r31, 0x5C
	  add       r10, r10, r3
	  stfs      f6, 0x8(r8)
	  addi      r7, r31, 0x78
	  add       r11, r11, r0
	  stw       r5, 0x0(r9)
	  addi      r6, r31, 0x88
	  li        r5, 0
	  stfs      f7, 0x4(r9)
	  li        r3, 0x64
	  li        r8, 0x5
	  lfs       f5, -0x4354(r2)
	  li        r0, -0x1
	  stfs      f5, 0x8(r9)
	  stw       r7, 0x0(r10)
	  stfs      f7, 0x4(r10)
	  lfs       f4, -0x4350(r2)
	  stfs      f4, 0x8(r10)
	  stw       r6, 0x0(r11)
	  stw       r5, 0x4(r11)
	  stw       r3, 0x8(r11)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x434C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0xCC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x4348(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0xD0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4344(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4340(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xD8(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x50(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0xC(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x24(r3)
	  lwz       r3, 0x0(r4)
	  li        r7, 0x2
	  li        r6, 0xA
	  lwz       r3, 0x0(r3)
	  li        r5, 0x1E
	  li        r0, 0x1
	  stw       r7, 0x28(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r8, 0x2C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r6, 0x30(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x34(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x38(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x3C(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r5, 0x40(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r3, 0x0(r3)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x433C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x4338(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4334(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x4330(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x432C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f6, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4328(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f4, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4324(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4320(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x30(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x3C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x40(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x431C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x78(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4318(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x7C(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r30
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0x80(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4314(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x84(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x88(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x8C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x90(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4310(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x94(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x430C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x44(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x48(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4308(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x98(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x58(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0x5C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x60(r5)
	  lwz       r4, 0x0(r4)
	  lwz       r4, 0x0(r4)
	  stw       r0, 0x0(r4)
	  lwz       r0, 0xD4(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D15E4
 * Size:	000AD0
 */
TAIdororoStrategy::TAIdororoStrategy()
    : YaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0xC
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0xC8(r1)
	  stmw      r14, 0x80(r1)
	  addi      r31, r3, 0
	  bl        0x18054
	  lis       r3, 0x802E
	  addi      r0, r3, 0x3FF4
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0x18A610
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x60
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0x2
	  lis       r3, 0x802E
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x4538
	  stw       r0, 0x4(r28)

	.loc_0x60:
	  li        r3, 0x8
	  bl        -0x18A644
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x94
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r20)
	  li        r0, 0
	  lis       r3, 0x802E
	  stw       r0, 0x0(r20)
	  subi      r0, r3, 0xCB4
	  stw       r0, 0x4(r20)

	.loc_0x94:
	  li        r3, 0xC
	  bl        -0x18A678
	  stw       r3, 0x7C(r1)
	  lwz       r3, 0x7C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xD8
	  li        r4, -0x1
	  li        r5, 0
	  bl        -0x24A44
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lwz       r3, 0x7C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x4500
	  lwz       r3, 0x7C(r1)
	  stw       r0, 0x4(r3)

	.loc_0xD8:
	  li        r3, 0xC
	  bl        -0x18A6BC
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x114
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r26)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r26)
	  subi      r3, r3, 0xE10
	  li        r0, 0x1
	  stw       r3, 0x4(r26)
	  stb       r0, 0x8(r26)

	.loc_0x114:
	  li        r3, 0x8
	  bl        -0x18A6F8
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x148
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r21)
	  subi      r0, r3, 0x6EC
	  stw       r0, 0x4(r21)

	.loc_0x148:
	  li        r3, 0x8
	  bl        -0x18A72C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x17C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r27)
	  li        r0, 0x8
	  lis       r3, 0x802E
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x4498
	  stw       r0, 0x4(r27)

	.loc_0x17C:
	  li        r3, 0xC
	  bl        -0x18A760
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x1C0
	  li        r4, 0x9
	  li        r5, 0x6
	  bl        -0x24A9C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5E8
	  lis       r3, 0x802E
	  stw       r0, 0x4(r25)
	  subi      r0, r3, 0x4C8
	  lis       r3, 0x802E
	  stw       r0, 0x4(r25)
	  addi      r0, r3, 0x4414
	  stw       r0, 0x4(r25)

	.loc_0x1C0:
	  li        r3, 0xC
	  bl        -0x18A7A4
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x1FC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0x4
	  lis       r3, 0x802E
	  stw       r0, 0x0(r19)
	  addi      r3, r3, 0x3CC
	  li        r0, -0x1
	  stw       r3, 0x4(r19)
	  stw       r0, 0x8(r19)

	.loc_0x1FC:
	  li        r3, 0xC
	  bl        -0x18A7E0
	  stw       r3, 0x78(r1)
	  lwz       r3, 0x78(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x240
	  li        r4, -0x2
	  li        r5, 0x9
	  bl        -0x24BAC
	  lis       r3, 0x802E
	  addi      r0, r3, 0x34C
	  lwz       r3, 0x78(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x4388
	  lwz       r3, 0x78(r1)
	  stw       r0, 0x4(r3)

	.loc_0x240:
	  li        r3, 0x10
	  bl        -0x18A824
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x280
	  li        r4, 0x6
	  li        r5, 0x2
	  bl        -0x24B60
	  lis       r3, 0x802E
	  subi      r0, r3, 0x7D4
	  stw       r0, 0x4(r18)
	  lis       r3, 0x802E
	  addi      r0, r3, 0x42FC
	  lfs       f0, -0x4360(r2)
	  stfs      f0, 0xC(r18)
	  stw       r0, 0x4(r18)

	.loc_0x280:
	  li        r3, 0x8
	  bl        -0x18A864
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x2B4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, 0x7
	  lis       r3, 0x802E
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x124
	  stw       r0, 0x4(r16)

	.loc_0x2B4:
	  li        r3, 0x8
	  bl        -0x18A898
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x2E8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, 0xB
	  lis       r3, 0x802E
	  stw       r0, 0x0(r17)
	  subi      r0, r3, 0x211C
	  stw       r0, 0x4(r17)

	.loc_0x2E8:
	  li        r3, 0xC
	  bl        -0x18A8CC
	  stw       r3, 0x74(r1)
	  lwz       r3, 0x74(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x32C
	  li        r4, 0x3
	  li        r5, 0x6
	  bl        -0x24C0C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5E8
	  lwz       r3, 0x74(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x4254
	  lwz       r3, 0x74(r1)
	  stw       r0, 0x4(r3)

	.loc_0x32C:
	  li        r3, 0x24
	  bl        -0x18A910
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x398
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r5, 0x7268
	  lis       r4, 0x802E
	  stw       r0, 0x0(r29)
	  addi      r0, r4, 0x4BA8
	  stw       r0, 0x4(r29)
	  li        r0, 0
	  lis       r4, 0x6C68
	  stw       r0, 0x8(r1)
	  addi      r9, r4, 0x6E64
	  addi      r10, r5, 0x6E64
	  stw       r0, 0xC(r1)
	  li        r4, 0x78
	  li        r5, 0x1
	  lwz       r7, 0x22F0(r13)
	  li        r6, -0x1
	  lfs       f1, -0x4304(r2)
	  li        r8, 0x2
	  bl        0x44D8

	.loc_0x398:
	  li        r3, 0xC
	  bl        -0x18A97C
	  addi      r22, r3, 0
	  mr.       r3, r22
	  beq-      .loc_0x3C4
	  li        r4, 0x3
	  li        r5, 0xA
	  bl        -0x24CB8
	  lis       r3, 0x802E
	  addi      r0, r3, 0x41D8
	  stw       r0, 0x4(r22)

	.loc_0x3C4:
	  li        r3, 0xC
	  bl        -0x18A9A8
	  stw       r3, 0x70(r1)
	  lwz       r3, 0x70(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x3F8
	  li        r4, -0x1
	  li        r5, 0xD
	  bl        -0x24CE8
	  lis       r3, 0x802E
	  addi      r0, r3, 0x4198
	  lwz       r3, 0x70(r1)
	  stw       r0, 0x4(r3)

	.loc_0x3F8:
	  li        r3, 0x10
	  bl        -0x18A9DC
	  addi      r15, r3, 0
	  mr.       r3, r15
	  beq-      .loc_0x438
	  li        r4, 0x5
	  li        r5, 0xB
	  bl        -0x24D18
	  lis       r3, 0x802E
	  subi      r0, r3, 0x364
	  stw       r0, 0x4(r15)
	  lis       r3, 0x802E
	  addi      r0, r3, 0x4110
	  lfs       f0, -0x4300(r2)
	  stfs      f0, 0xC(r15)
	  stw       r0, 0x4(r15)

	.loc_0x438:
	  li        r3, 0x10
	  bl        -0x18AA1C
	  addi      r14, r3, 0
	  mr.       r3, r14
	  beq-      .loc_0x478
	  li        r4, -0x2
	  li        r5, 0xB
	  bl        -0x24D58
	  lis       r3, 0x802E
	  subi      r0, r3, 0x364
	  stw       r0, 0x4(r14)
	  lis       r3, 0x802E
	  addi      r0, r3, 0x4110
	  lfs       f0, -0x4300(r2)
	  stfs      f0, 0xC(r14)
	  stw       r0, 0x4(r14)

	.loc_0x478:
	  li        r3, 0xC
	  bl        -0x18AA5C
	  stw       r3, 0x6C(r1)
	  lwz       r3, 0x6C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x49C
	  li        r4, 0x5
	  li        r5, 0xC
	  bl        -0x24D9C

	.loc_0x49C:
	  li        r3, 0x8
	  bl        -0x18AA80
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x4D0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r23)
	  li        r0, 0xA
	  lis       r3, 0x802E
	  stw       r0, 0x0(r23)
	  addi      r0, r3, 0x4084
	  stw       r0, 0x4(r23)

	.loc_0x4D0:
	  li        r3, 0x8
	  bl        -0x18AAB4
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0x504
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x4048
	  stw       r0, 0x4(r30)

	.loc_0x504:
	  li        r3, 0xC
	  bl        -0x18AAE8
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x520
	  li        r4, 0x1
	  bl        -0xAAA68

	.loc_0x520:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x4(r4)
	  bl        -0x18AB1C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x554
	  li        r4, 0x4
	  bl        -0xAAA9C

	.loc_0x554:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x7C(r1)
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  rlwinm    r0,r0,2,0,29
	  lwz       r5, 0x8(r28)
	  li        r4, 0x2
	  li        r3, 0x3
	  stwx      r21, r5, r0
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r3, 0xC
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r28)
	  stwx      r30, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x0(r4)
	  bl        -0x18AB84
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x5BC
	  li        r4, 0x3
	  bl        -0xAAB04

	.loc_0x5BC:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r22, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x8(r4)
	  bl        -0x18ABD8
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x610
	  li        r4, 0x8
	  bl        -0xAAB58

	.loc_0x610:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r26, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  li        r5, 0x3
	  stwx      r20, r3, r4
	  li        r6, 0x4
	  li        r7, 0x5
	  lwz       r4, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x6
	  stwx      r23, r4, r0
	  li        r4, 0x7
	  rlwinm    r0,r5,2,0,29
	  lwz       r5, 0x8(r28)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r7,r7,2,0,29
	  stwx      r27, r5, r0
	  rlwinm    r5,r3,2,0,29
	  rlwinm    r0,r4,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r3, 0xC
	  stwx      r25, r4, r6
	  lwz       r4, 0x8(r28)
	  stwx      r19, r4, r7
	  lwz       r4, 0x8(r28)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r28)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r28, 0xC(r4)
	  bl        -0x18AC7C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x6B4
	  li        r4, 0x3
	  bl        -0xAABFC

	.loc_0x6B4:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x78(r1)
	  stwx      r0, r3, r4
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r30, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x10(r4)
	  bl        -0x18ACD4
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x70C
	  li        r4, 0x9
	  bl        -0xAAC54

	.loc_0x70C:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r21, r3, r0
	  li        r0, 0x1
	  li        r4, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r5,r0,2,0,29
	  li        r0, 0x3
	  stwx      r26, r3, r5
	  li        r7, 0x4
	  li        r5, 0x5
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  li        r6, 0x6
	  stwx      r20, r3, r4
	  li        r4, 0x7
	  li        r9, 0x8
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r8,r7,2,0,29
	  stwx      r23, r3, r0
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r6,2,0,29
	  lwz       r3, 0x8(r28)
	  rlwinm    r6,r4,2,0,29
	  rlwinm    r7,r9,2,0,29
	  stwx      r27, r3, r8
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r18, r4, r5
	  lwz       r4, 0x8(r28)
	  stwx      r19, r4, r0
	  lwz       r4, 0x8(r28)
	  stwx      r29, r4, r6
	  lwz       r4, 0x8(r28)
	  stwx      r30, r4, r7
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x14(r4)
	  bl        -0x18AD88
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x7C0
	  li        r4, 0x3
	  bl        -0xAAD08

	.loc_0x7C0:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r16, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r17, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x18(r4)
	  bl        -0x18ADDC
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x814
	  li        r4, 0x7
	  bl        -0xAAD5C

	.loc_0x814:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r3, 0x2
	  lwz       r4, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  li        r7, 0x5
	  stwx      r21, r4, r0
	  rlwinm    r3,r3,2,0,29
	  li        r5, 0x3
	  lwz       r4, 0x8(r28)
	  li        r0, 0x4
	  rlwinm    r7,r7,2,0,29
	  stwx      r26, r4, r3
	  rlwinm    r4,r5,2,0,29
	  rlwinm    r5,r0,2,0,29
	  lwz       r3, 0x8(r28)
	  li        r6, 0x6
	  rlwinm    r0,r6,2,0,29
	  stwx      r20, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r27, r4, r5
	  lwz       r5, 0x6C(r1)
	  lwz       r4, 0x8(r28)
	  stwx      r5, r4, r7
	  lwz       r4, 0x8(r28)
	  stwx      r29, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x2C(r4)
	  bl        -0x18AE74
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x8AC
	  li        r4, 0x7
	  bl        -0xAADF4

	.loc_0x8AC:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r3, 0x1
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r0, 0x2
	  li        r7, 0x5
	  stwx      r26, r4, r5
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0x3
	  lwz       r6, 0x8(r28)
	  li        r4, 0x4
	  li        r5, 0x6
	  stwx      r20, r6, r0
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r6,r4,2,0,29
	  lwz       r3, 0x8(r28)
	  rlwinm    r4,r5,2,0,29
	  rlwinm    r7,r7,2,0,29
	  stwx      r27, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0x74(r1)
	  lwz       r5, 0x8(r28)
	  stwx      r0, r5, r6
	  lwz       r5, 0x8(r28)
	  stwx      r19, r5, r7
	  lwz       r5, 0x8(r28)
	  stwx      r29, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x1C(r4)
	  bl        -0x18AF0C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x944
	  li        r4, 0x4
	  bl        -0xAAE8C

	.loc_0x944:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  lwz       r6, 0x70(r1)
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r5, 0x3
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x2
	  stwx      r6, r3, r0
	  rlwinm    r0,r4,2,0,29
	  rlwinm    r5,r5,2,0,29
	  lwz       r4, 0x8(r28)
	  li        r3, 0xC
	  stwx      r21, r4, r0
	  lwz       r4, 0x8(r28)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x20(r4)
	  bl        -0x18AF74
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x9AC
	  li        r4, 0x7
	  bl        -0xAAEF4

	.loc_0x9AC:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r3, 0x2
	  lwz       r4, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  li        r6, 0x3
	  stwx      r26, r4, r0
	  li        r0, 0x4
	  li        r5, 0x5
	  lwz       r4, 0x8(r28)
	  rlwinm    r3,r3,2,0,29
	  li        r7, 0x6
	  stwx      r20, r4, r3
	  rlwinm    r4,r6,2,0,29
	  rlwinm    r6,r0,2,0,29
	  lwz       r3, 0x8(r28)
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r7,2,0,29
	  stwx      r27, r3, r4
	  li        r3, 0xC
	  lwz       r4, 0x8(r28)
	  stwx      r15, r4, r6
	  lwz       r4, 0x8(r28)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r28)
	  stwx      r21, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x24(r4)
	  bl        -0x18B008
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0xA40
	  li        r4, 0x7
	  bl        -0xAAF88

	.loc_0xA40:
	  li        r0, 0
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r28)
	  rlwinm    r5,r4,2,0,29
	  li        r4, 0x3
	  stwx      r26, r3, r5
	  li        r5, 0x4
	  li        r6, 0x5
	  lwz       r3, 0x8(r28)
	  rlwinm    r0,r0,2,0,29
	  li        r7, 0x6
	  stwx      r20, r3, r0
	  rlwinm    r3,r4,2,0,29
	  rlwinm    r0,r5,2,0,29
	  lwz       r4, 0x8(r28)
	  rlwinm    r5,r6,2,0,29
	  rlwinm    r6,r7,2,0,29
	  stwx      r27, r4, r3
	  mr        r3, r31
	  lwz       r4, 0x8(r28)
	  stwx      r14, r4, r0
	  lwz       r4, 0x8(r28)
	  stwx      r29, r4, r5
	  lwz       r4, 0x8(r28)
	  stwx      r21, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r28, 0x28(r4)
	  lwz       r0, 0xCC(r1)
	  lmw       r14, 0x80(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D20B4
 * Size:	0003C8
 */
void TAIdororoStrategy::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x178(r1)
	  stw       r31, 0x174(r1)
	  stw       r30, 0x170(r1)
	  mr        r30, r4
	  stw       r29, 0x16C(r1)
	  bl        0x17678
	  lis       r4, 0x6B62
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x3031
	  bl        -0x1489D0
	  mr.       r31, r3
	  beq-      .loc_0x3AC
	  addi      r3, r1, 0xC8
	  addi      r4, r31, 0
	  bl        -0x14A1DC
	  lwz       r3, 0xC8(r1)
	  lwz       r0, 0xCC(r1)
	  stw       r3, 0x120(r1)
	  lwz       r3, 0xD0(r1)
	  stw       r0, 0x124(r1)
	  lwz       r0, 0xD4(r1)
	  stw       r3, 0x128(r1)
	  lwz       r3, 0xD8(r1)
	  stw       r0, 0x12C(r1)
	  lwz       r0, 0xDC(r1)
	  stw       r3, 0x130(r1)
	  lwz       r3, 0xE0(r1)
	  stw       r0, 0x134(r1)
	  lwz       r0, 0xE4(r1)
	  stw       r3, 0x138(r1)
	  lwz       r3, 0xE8(r1)
	  stw       r0, 0x13C(r1)
	  lwz       r0, 0xEC(r1)
	  stw       r3, 0x140(r1)
	  lwz       r3, 0xF0(r1)
	  stw       r0, 0x144(r1)
	  lwz       r0, 0xF4(r1)
	  stw       r3, 0x148(r1)
	  lwz       r3, 0xF8(r1)
	  stw       r0, 0x14C(r1)
	  lwz       r0, 0xFC(r1)
	  stw       r3, 0x150(r1)
	  lwz       r3, 0x100(r1)
	  stw       r0, 0x154(r1)
	  lwz       r0, 0x104(r1)
	  stw       r3, 0x158(r1)
	  lfs       f2, -0x4360(r2)
	  stw       r0, 0x15C(r1)
	  stfs      f2, 0x11C(r1)
	  stfs      f2, 0x118(r1)
	  lfs       f1, 0x120(r1)
	  lfs       f0, 0x130(r1)
	  fneg      f1, f1
	  stfs      f2, 0x114(r1)
	  fneg      f0, f0
	  stfs      f1, 0x114(r1)
	  stfs      f0, 0x118(r1)
	  lfs       f0, 0x140(r1)
	  fneg      f0, f0
	  stfs      f0, 0x11C(r1)
	  lwz       r29, 0x4A0(r30)
	  cmplwi    r29, 0
	  beq-      .loc_0x188
	  lwz       r3, 0x114(r1)
	  addi      r6, r1, 0x48
	  lwz       r0, 0x118(r1)
	  addi      r5, r1, 0x44
	  addi      r4, r1, 0x40
	  stw       r3, 0xA0(r29)
	  addi      r3, r1, 0xA4
	  stw       r0, 0xA4(r29)
	  lwz       r0, 0x11C(r1)
	  stw       r0, 0xA8(r29)
	  lfs       f0, 0x78(r30)
	  lfs       f1, 0x2124(r13)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x74(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x70(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x40(r1)
	  bl        -0x19B0EC
	  lfs       f0, 0xA4(r1)
	  lfs       f1, 0xA8(r1)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0xAC(r1)
	  stfs      f1, 0xB4(r1)
	  stfs      f0, 0xB8(r1)
	  lwz       r3, 0xB0(r1)
	  lwz       r0, 0xB4(r1)
	  stw       r3, 0x1C(r29)
	  stw       r0, 0x20(r29)
	  lwz       r0, 0xB8(r1)
	  stw       r0, 0x24(r29)

	.loc_0x188:
	  lwz       r29, 0x4A4(r30)
	  cmplwi    r29, 0
	  beq-      .loc_0x218
	  lwz       r3, 0x114(r1)
	  addi      r6, r1, 0x3C
	  lwz       r0, 0x118(r1)
	  addi      r5, r1, 0x38
	  addi      r4, r1, 0x34
	  stw       r3, 0xA0(r29)
	  addi      r3, r1, 0x8C
	  stw       r0, 0xA4(r29)
	  lwz       r0, 0x11C(r1)
	  stw       r0, 0xA8(r29)
	  lfs       f0, 0x78(r30)
	  lfs       f1, 0x2128(r13)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x74(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x70(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x34(r1)
	  bl        -0x19B17C
	  lfs       f0, 0x8C(r1)
	  lfs       f1, 0x90(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f0, 0x94(r1)
	  stfs      f1, 0x9C(r1)
	  stfs      f0, 0xA0(r1)
	  lwz       r3, 0x98(r1)
	  lwz       r0, 0x9C(r1)
	  stw       r3, 0x1C(r29)
	  stw       r0, 0x20(r29)
	  lwz       r0, 0xA0(r1)
	  stw       r0, 0x24(r29)

	.loc_0x218:
	  lwz       r29, 0x4B0(r30)
	  cmplwi    r29, 0
	  beq-      .loc_0x2A8
	  lwz       r3, 0x114(r1)
	  addi      r6, r1, 0x30
	  lwz       r0, 0x118(r1)
	  addi      r5, r1, 0x2C
	  addi      r4, r1, 0x28
	  stw       r3, 0xA0(r29)
	  addi      r3, r1, 0x74
	  stw       r0, 0xA4(r29)
	  lwz       r0, 0x11C(r1)
	  stw       r0, 0xA8(r29)
	  lfs       f0, 0x78(r30)
	  lfs       f1, 0x212C(r13)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x74(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x70(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x28(r1)
	  bl        -0x19B20C
	  lfs       f0, 0x74(r1)
	  lfs       f1, 0x78(r1)
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x7C(r1)
	  stfs      f1, 0x84(r1)
	  stfs      f0, 0x88(r1)
	  lwz       r3, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  stw       r3, 0x1C(r29)
	  stw       r0, 0x20(r29)
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x24(r29)

	.loc_0x2A8:
	  lwz       r29, 0x4A8(r30)
	  cmplwi    r29, 0
	  beq-      .loc_0x320
	  lfs       f0, 0x78(r30)
	  addi      r6, r1, 0x24
	  lfs       f1, 0x2130(r13)
	  addi      r5, r1, 0x20
	  addi      r4, r1, 0x1C
	  fmuls     f0, f0, f1
	  addi      r3, r1, 0x5C
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x74(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x70(r30)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1C(r1)
	  bl        -0x19B284
	  lfs       f0, 0x5C(r1)
	  lfs       f1, 0x60(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x64(r1)
	  stfs      f1, 0x6C(r1)
	  stfs      f0, 0x70(r1)
	  lwz       r3, 0x68(r1)
	  lwz       r0, 0x6C(r1)
	  stw       r3, 0x1C(r29)
	  stw       r0, 0x20(r29)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0x24(r29)

	.loc_0x320:
	  lwz       r4, 0x4AC(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x3AC
	  lfs       f0, -0x4360(r2)
	  stfs      f0, 0x110(r1)
	  stfs      f0, 0x10C(r1)
	  stfs      f0, 0x108(r1)
	  lfs       f4, 0x2134(r13)
	  lfs       f0, 0x114(r1)
	  lfs       f1, 0x118(r1)
	  fmuls     f0, f0, f4
	  lfs       f2, 0x11C(r1)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x108(r1)
	  stfs      f3, 0x10C(r1)
	  stfs      f1, 0x110(r1)
	  lfs       f1, 0x108(r1)
	  lfs       f0, 0x4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x108(r1)
	  lfs       f1, 0x10C(r1)
	  lfs       f0, 0x8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10C(r1)
	  lfs       f1, 0x110(r1)
	  lfs       f0, 0xC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x110(r1)
	  lwz       r3, 0x108(r1)
	  lwz       r0, 0x10C(r1)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x110(r1)
	  stw       r0, 0x14(r4)

	.loc_0x3AC:
	  lwz       r0, 0x17C(r1)
	  lwz       r31, 0x174(r1)
	  lwz       r30, 0x170(r1)
	  lwz       r29, 0x16C(r1)
	  addi      r1, r1, 0x178
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D247C
 * Size:	000020
 */
void TAIdororoStrategy::draw(Teki&, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x17418
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D249C
 * Size:	0000B0
 */
void TAIdororoStrategy::createEffect(Teki&, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  bl        -0x85300
	  cmpwi     r31, 0x1
	  beq-      .loc_0x60
	  bge-      .loc_0x40
	  cmpwi     r31, 0
	  bge-      .loc_0x4C
	  b         .loc_0x94

	.loc_0x40:
	  cmpwi     r31, 0x3
	  bge-      .loc_0x94
	  b         .loc_0x74

	.loc_0x4C:
	  lwz       r5, 0x10(r29)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        .loc_0xB0
	  b         .loc_0x94

	.loc_0x60:
	  lwz       r5, 0x14(r29)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        .loc_0xB0
	  b         .loc_0x94

	.loc_0x74:
	  lwz       r5, 0x10(r29)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        .loc_0xB0
	  lwz       r5, 0x14(r29)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        .loc_0xB0

	.loc_0x94:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0xB0:
	*/
}

/*
 * --INFO--
 * Address:	801D254C
 * Size:	000148
 */
void TAIdororoStrategy::createCloudOfDust(Teki&, CollPart*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r5
	  stw       r30, 0x20(r1)
	  mr        r30, r4
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x4(r5)
	  lfs       f2, 0xC(r5)
	  bl        -0x16A674
	  lfs       f2, 0x8(r31)
	  lfs       f0, -0x4350(r2)
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x11C
	  lfs       f0, 0x4(r31)
	  li        r4, 0x1
	  stfs      f0, 0x14(r1)
	  lfs       f0, 0x8(r31)
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0xC(r31)
	  stfs      f0, 0x1C(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x14(r1)
	  lfs       f2, 0x1C(r1)
	  bl        -0x16A6B4
	  stfs      f1, 0x18(r1)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x14(r1)
	  lfs       f2, 0x1C(r1)
	  bl        -0x16A3F8
	  cmplwi    r3, 0
	  beq-      .loc_0xF4
	  bl        -0xBC55C
	  cmpwi     r3, 0x5
	  bne-      .loc_0xC8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0x55
	  li        r6, 0
	  li        r7, 0
	  bl        -0x35AC4
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x14
	  bl        -0x148058
	  b         .loc_0x11C

	.loc_0xC8:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0x43
	  li        r6, 0
	  li        r7, 0
	  bl        -0x35AF0
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x96
	  bl        -0x148084
	  b         .loc_0x11C

	.loc_0xF4:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x14
	  li        r4, 0x43
	  li        r6, 0
	  li        r7, 0
	  bl        -0x35B1C
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x96
	  bl        -0x1480B0

	.loc_0x11C:
	  lwz       r3, 0x3178(r13)
	  addi      r6, r31, 0x4
	  li        r4, 0xA
	  li        r5, 0
	  bl        -0x558A4
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
 * Address:	801D2694
 * Size:	00008C
 */
void TAIdororoStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  bl        0x17054
	  lis       r3, 0x6C68
	  addi      r0, r3, 0x6E64
	  stw       r0, 0x18(r1)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x18(r1)
	  bl        -0x148FB8
	  cmplwi    r3, 0
	  lis       r4, 0x7268
	  stw       r3, 0x10(r30)
	  addi      r0, r4, 0x6E64
	  stw       r0, 0x10(r1)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x10(r1)
	  bl        -0x148FD8
	  cmplwi    r3, 0
	  stw       r3, 0x14(r30)
	  lwz       r0, 0x10(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x74
	  lwz       r0, 0x14(r30)
	  cmplwi    r0, 0

	.loc_0x74:
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
 * Address:	801D2720
 * Size:	0006FC
 */
void TAIdororoAnimation::makeDefaultAnimations()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stw       r31, 0xD4(r1)
	  mr        r31, r3
	  stw       r30, 0xD0(r1)
	  lwz       r0, 0x4(r3)
	  lis       r3, 0x802E
	  addi      r30, r3, 0x3D60
	  cmplwi    r0, 0
	  beq-      .loc_0x6E4
	  lwz       r6, 0x3160(r13)
	  mr        r3, r31
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r30, 0xA0
	  lwz       r6, 0x124(r6)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0x1FC(r5)
	  bl        -0x2F1D4
	  addi      r3, r31, 0
	  addi      r4, r30, 0xC0
	  bl        -0x2F1E0
	  addi      r3, r31, 0
	  addi      r4, r30, 0xE0
	  bl        -0x2F1EC
	  li        r3, 0x10
	  bl        -0x18B784
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x8C
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x8C:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x18B7CC
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0xD8
	  li        r3, 0x1
	  stw       r3, 0x0(r7)
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0xD8:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x100
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2F28C
	  li        r3, 0x10
	  bl        -0x18B824
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x12C
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x12C:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x18B86C
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x178
	  li        r3, 0x1
	  stw       r3, 0x0(r7)
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x178:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x120
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2F32C
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x182508
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1820C0
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1820D8
	  li        r3, 0x10
	  bl        -0x18B900
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x20C
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x20C:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x18B94C
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x25C
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x25C:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x144
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2F410
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x1825EC
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1821A4
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1821BC
	  li        r3, 0x10
	  bl        -0x18B9E4
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x2F0
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x2F0:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x18BA30
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x340
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x340:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x168
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2F4F4
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x1826D0
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x182288
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1822A0
	  li        r3, 0x10
	  bl        -0x18BAC8
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x3D4
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x3D4:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x18BB14
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x424
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x424:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x188
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2F5D8
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x1827B4
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x18236C
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x182384
	  li        r3, 0x10
	  bl        -0x18BBAC
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x4B8
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x4B8:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x18BBF8
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x508
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x508:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x1A8
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2F6BC
	  lwz       r3, 0x8(r31)
	  li        r0, 0x3A
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x182444
	  li        r3, 0x10
	  bl        -0x18BC6C
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x57C
	  li        r0, 0x1
	  stw       r0, 0x0(r7)
	  li        r3, 0x2
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x57C:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x1C8
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2F730
	  lwz       r3, 0x8(r31)
	  li        r0, 0x8
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1824B8
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x1824D0
	  li        r3, 0x10
	  bl        -0x18BCF8
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x604
	  li        r0, 0x1
	  stw       r0, 0x0(r6)
	  li        r0, 0
	  stb       r0, 0x6(r6)
	  stw       r0, 0x8(r6)
	  stw       r0, 0xC(r6)

	.loc_0x604:
	  lwz       r4, 0x8(r31)
	  li        r3, 0x10
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x18BD44
	  addi      r7, r3, 0
	  mr.       r0, r7
	  beq-      .loc_0x654
	  li        r0, 0x2
	  stw       r0, 0x0(r7)
	  li        r3, 0x1
	  li        r0, 0
	  stb       r3, 0x6(r7)
	  stw       r0, 0x8(r7)
	  stw       r0, 0xC(r7)

	.loc_0x654:
	  lwz       r5, 0x8(r31)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x1E8
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x2F808
	  lwz       r3, 0x8(r31)
	  li        r0, 0x20
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x182590
	  li        r3, 0x10
	  bl        -0x18BDB8
	  cmplwi    r3, 0
	  beq-      .loc_0x6C4
	  li        r0, 0x1
	  stw       r0, 0x0(r3)
	  li        r4, 0x2
	  li        r0, 0
	  stb       r4, 0x6(r3)
	  stw       r0, 0x8(r3)
	  stw       r0, 0xC(r3)

	.loc_0x6C4:
	  lwz       r4, 0x8(r31)
	  lwz       r5, 0x60(r4)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r3)
	  stw       r5, 0x8(r3)
	  lwz       r4, 0xC(r5)
	  stw       r3, 0x8(r4)
	  stw       r3, 0xC(r5)

	.loc_0x6E4:
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
 * Address:	801D2E1C
 * Size:	000018
 */
void TAIAgravityDororo::start(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x42FC(r2)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x4C0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D2E34
 * Size:	000060
 */
bool TAIAgravityDororo::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  bl        -0x8A4B8
	  lfs       f0, -0x4360(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x3C
	  lfs       f1, 0xA8(r31)
	  lfs       f0, 0x4C0(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA8(r31)
	  b         .loc_0x40

	.loc_0x3C:
	  stfs      f0, 0xA8(r31)

	.loc_0x40:
	  lfs       f0, 0xA8(r31)
	  li        r3, 0
	  stfs      f0, 0x74(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D2E94
 * Size:	0001D4
 */
bool TAIAcheckBarkDororo::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC8(r1)
	  stfd      f31, 0xC0(r1)
	  stmw      r27, 0xAC(r1)
	  addi      r29, r4, 0
	  li        r30, 0
	  lwz       r3, 0x30AC(r13)
	  lwz       r31, 0x64(r3)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x4360(r2)
	  addi      r27, r3, 0
	  addi      r28, r29, 0x94
	  b         .loc_0x140

	.loc_0x48:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x6C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x84

	.loc_0x6C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x84:
	  cmplwi    r3, 0
	  beq-      .loc_0x124
	  stfs      f31, 0x90(r1)
	  stfs      f31, 0x8C(r1)
	  stfs      f31, 0x88(r1)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x0(r28)
	  lfs       f4, 0x8(r28)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x4(r28)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x70(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0x88(r1)
	  stfs      f1, 0x8C(r1)
	  stfs      f3, 0x90(r1)
	  lfs       f1, 0x88(r1)
	  lfs       f0, 0x8C(r1)
	  lfs       f2, 0x90(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1C5344
	  lwz       r3, 0x2C4(r29)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x18(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x124
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4C4(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4C4(r29)

	.loc_0x124:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x140:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x168
	  li        r0, 0x1
	  b         .loc_0x194

	.loc_0x168:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x190
	  li        r0, 0x1
	  b         .loc_0x194

	.loc_0x190:
	  li        r0, 0

	.loc_0x194:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x48
	  lfs       f1, 0x4C4(r29)
	  lfs       f0, -0x42F8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1B8
	  lfs       f0, -0x4360(r2)
	  li        r30, 0x1
	  stfs      f0, 0x4C4(r29)

	.loc_0x1B8:
	  mr        r3, r30
	  lmw       r27, 0xAC(r1)
	  lwz       r0, 0xCC(r1)
	  lfd       f31, 0xC0(r1)
	  addi      r1, r1, 0xC8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D3068
 * Size:	000020
 */
void TAIAbarkDororo::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x26134
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D3088
 * Size:	000390
 */
bool TAIAbarkDororo::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stmw      r22, 0xB8(r1)
	  addi      r25, r4, 0
	  li        r26, 0
	  bl        -0x26130
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C
	  lwz       r3, 0x2CC(r25)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x3C
	  li        r26, 0x1

	.loc_0x3C:
	  lwz       r0, 0x3A8(r25)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x374
	  lwz       r3, 0x3120(r13)
	  bl        -0xBBD10
	  lwz       r4, 0x30AC(r13)
	  mr        r31, r3
	  lwz       r28, 0x64(r4)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f31, -0x4360(r2)
	  lis       r4, 0x802C
	  addi      r27, r3, 0
	  subi      r23, r5, 0x3064
	  subi      r24, r4, 0x157C
	  addi      r29, r1, 0xA0
	  addi      r30, r25, 0x94
	  b         .loc_0x1A0

	.loc_0x94:
	  cmpwi     r27, -0x1
	  bne-      .loc_0xB8
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xD0

	.loc_0xB8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xD0:
	  cmplwi    r3, 0
	  addi      r22, r3, 0
	  beq-      .loc_0x184
	  stfs      f31, 0x90(r1)
	  stfs      f31, 0x8C(r1)
	  stfs      f31, 0x88(r1)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x0(r30)
	  lfs       f4, 0x8(r30)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x4(r30)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x70(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0x88(r1)
	  stfs      f1, 0x8C(r1)
	  stfs      f3, 0x90(r1)
	  lfs       f1, 0x88(r1)
	  lfs       f0, 0x8C(r1)
	  lfs       f2, 0x90(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1C5588
	  lwz       r3, 0x2C4(r25)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x18(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x184
	  stw       r23, 0xA0(r1)
	  addi      r3, r22, 0
	  addi      r4, r29, 0
	  stw       r31, 0xA4(r1)
	  stw       r24, 0xA0(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x184:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x1A0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  li        r0, 0x1
	  b         .loc_0x1F4

	.loc_0x1C8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1F0
	  li        r0, 0x1
	  b         .loc_0x1F4

	.loc_0x1F0:
	  li        r0, 0

	.loc_0x1F4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x94
	  lis       r4, 0x6D6E
	  lwz       r3, 0x220(r25)
	  addi      r4, r4, 0x3031
	  bl        -0x149B80
	  mr.       r27, r3
	  beq-      .loc_0x25C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r27, 0x4
	  li        r4, 0xA3
	  li        r6, 0
	  li        r7, 0
	  bl        -0x36778
	  lwz       r3, 0x3180(r13)
	  addi      r5, r27, 0x4
	  li        r4, 0xA4
	  li        r6, 0
	  li        r7, 0
	  bl        -0x36790
	  lwz       r3, 0x3180(r13)
	  addi      r5, r27, 0x4
	  li        r4, 0xA5
	  li        r6, 0
	  li        r7, 0
	  bl        -0x367A8

	.loc_0x25C:
	  lwz       r3, 0x498(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x274
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x274:
	  lwz       r3, 0x49C(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x28C
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x28C:
	  lwz       r3, 0x4A0(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x2A4
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x2A4:
	  lwz       r3, 0x4A4(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x2BC
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x2BC:
	  lwz       r3, 0x4A8(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x2D4
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x2D4:
	  lwz       r3, 0x4AC(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x2EC
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x2EC:
	  lwz       r3, 0x4B0(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x304
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x304:
	  lwz       r3, 0x4B4(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x31C
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x31C:
	  lwz       r3, 0x4B8(r25)
	  cmplwi    r3, 0
	  beq-      .loc_0x334
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x334:
	  mr        r3, r25
	  bl        -0x2404
	  addi      r23, r25, 0x94
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r23, 0
	  li        r4, 0x3
	  bl        -0xAF3FC
	  addi      r3, r25, 0
	  addi      r4, r25, 0
	  li        r5, 0x97
	  bl        -0x148E30
	  lwz       r3, 0x3178(r13)
	  addi      r6, r23, 0
	  li        r4, 0x5
	  li        r5, 0
	  bl        -0x56624

	.loc_0x374:
	  mr        r3, r26
	  lmw       r22, 0xB8(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D3418
 * Size:	00006C
 */
void TAIAtransformationDororo::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x26728
	  mr        r3, r31
	  lwz       r4, -0x9C4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9CC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x98
	  bl        -0x148EB8
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D3484
 * Size:	000298
 */
bool TAIAtransformationDororo::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  mr        r31, r4
	  stw       r30, 0x78(r1)
	  bl        -0x265E8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x278
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x278
	  mr        r3, r31
	  bl        -0x8B748
	  mr        r3, r31
	  lwz       r4, -0x9C4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9C8(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x320(r31)
	  lis       r3, 0x802D
	  subi      r0, r3, 0x252C
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r30, 0x0(r3)
	  addi      r3, r1, 0x4C
	  addi      r4, r30, 0
	  bl        -0x18F67C
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x64
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xA0(r31)
	  addi      r4, r30, 0
	  addi      r3, r31, 0x2B8
	  addi      r5, r1, 0x64
	  bl        -0x13E5C8
	  lwz       r0, 0x2BC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x17C
	  addi      r3, r1, 0x58
	  bl        -0xB66FC
	  lfs       f31, 0xA0(r31)
	  fmr       f1, f31
	  bl        0x485F8
	  stfs      f1, 0x3C(r1)
	  fmr       f1, f31
	  addi      r30, r1, 0x3C
	  bl        0x4877C
	  stfs      f1, 0x38(r1)
	  addi      r4, r1, 0x38
	  addi      r6, r30, 0
	  addi      r3, r1, 0x58
	  addi      r5, r13, 0x2108
	  bl        -0x175EF8
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x29
	  lwz       r3, 0x84(r3)
	  bl        -0xB0384
	  lfs       f0, 0x58(r1)
	  li        r4, 0x2A
	  fmuls     f0, f0, f1
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x5C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x60(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x60(r1)
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xB10F8
	  stfs      f1, 0x5C(r1)
	  mr        r3, r31
	  lwz       r4, 0x2BC(r31)
	  lfs       f0, 0x58(r1)
	  stfsu     f0, 0x70(r4)
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x8(r4)
	  bl        -0x148958
	  li        r0, 0x2
	  stw       r0, 0x31C(r31)

	.loc_0x17C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x178(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x498(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1A8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1A8:
	  lwz       r3, 0x49C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1C0
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1C0:
	  lwz       r3, 0x4A0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1D8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1D8:
	  lwz       r3, 0x4A4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1F0
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1F0:
	  lwz       r3, 0x4A8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x208
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x208:
	  lwz       r3, 0x4AC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x220
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x220:
	  lwz       r3, 0x4B0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x238
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x238:
	  lwz       r3, 0x4B4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x250
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x250:
	  lwz       r3, 0x4B8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x268
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x268:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x9B
	  bl        -0x149144

	.loc_0x278:
	  lwz       r0, 0x8C(r1)
	  li        r3, 0x1
	  lfd       f31, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D371C
 * Size:	00004C
 */
void TAIAbirthDororo::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  bl        -0x26A2C
	  mr        r3, r31
	  bl        -0x277C
	  lwz       r3, 0x4AC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x38:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D3768
 * Size:	0000D0
 */
bool TAIAbirthDororo::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  bl        -0x268CC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB4
	  lwz       r3, 0x2CC(r30)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0xB4
	  mr        r3, r30
	  lwz       r4, -0x9C8(r13)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC8(r30)
	  ori       r0, r0, 0x40
	  stw       r0, 0xC8(r30)
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,31,29
	  stw       r0, 0xC8(r30)
	  lfs       f0, 0x210C(r13)
	  stfs      f0, 0xA4(r30)
	  lfs       f0, 0x2110(r13)
	  stfs      f0, 0xA8(r30)
	  lfs       f0, 0x2114(r13)
	  stfs      f0, 0xAC(r30)
	  lfs       f0, 0x2118(r13)
	  stfs      f0, 0x70(r30)
	  lfs       f0, 0x211C(r13)
	  stfs      f0, 0x74(r30)
	  lfs       f0, 0x2120(r13)
	  stfs      f0, 0x78(r30)
	  lwz       r3, 0x4AC(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xB0
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0xB0:
	  li        r31, 0x1

	.loc_0xB4:
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D3838
 * Size:	000128
 */
bool TAIAgoTargetPiki::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stw       r31, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  mr        r30, r4
	  stw       r29, 0x74(r1)
	  addi      r29, r3, 0
	  lwz       r31, 0x418(r4)
	  cmplwi    r31, 0
	  addi      r3, r31, 0
	  beq-      .loc_0x108
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x100
	  lfs       f0, -0x4360(r2)
	  stfs      f0, 0x68(r1)
	  stfs      f0, 0x64(r1)
	  stfs      f0, 0x60(r1)
	  lfsu      f1, 0x94(r31)
	  lfs       f0, 0x94(r30)
	  lfs       f4, 0x8(r31)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r30)
	  lfs       f2, 0x4(r31)
	  lfs       f1, 0x98(r30)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x50(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x60(r1)
	  stfs      f1, 0x64(r1)
	  stfs      f3, 0x68(r1)
	  lfs       f1, 0x60(r1)
	  lfs       f0, 0x64(r1)
	  lfs       f2, 0x68(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1C5CA8
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x18(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xF8
	  lfs       f0, 0x0(r31)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  stfs      f0, 0x388(r30)
	  lfs       f0, 0x4(r31)
	  stfs      f0, 0x38C(r30)
	  lfs       f0, 0x8(r31)
	  stfs      f0, 0x390(r30)
	  bl        -0x2A190
	  b         .loc_0x10C

	.loc_0xF8:
	  li        r3, 0x1
	  b         .loc_0x10C

	.loc_0x100:
	  li        r3, 0x1
	  b         .loc_0x10C

	.loc_0x108:
	  li        r3, 0x1

	.loc_0x10C:
	  lwz       r0, 0x84(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  lwz       r29, 0x74(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D3960
 * Size:	000008
 */
bool TAIAgoTargetPiki::checkArrival(Teki&) { return false; }

/*
 * --INFO--
 * Address:	801D3968
 * Size:	000094
 */
void TAIAwaitDororo::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r4
	  bl        -0x293D8
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0x36
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xB14C0
	  fmr       f31, f1
	  bl        0x446D4
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x54(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x84(r3)
	  li        r4, 0x36
	  stw       r0, 0x50(r1)
	  lfd       f2, -0x42F0(r2)
	  lfd       f1, 0x50(r1)
	  lfs       f0, -0x42F4(r2)
	  fsubs     f1, f1, f2
	  lwz       r3, 0x4(r3)
	  fdivs     f0, f1, f0
	  fmuls     f31, f31, f0
	  bl        -0xB1504
	  fadds     f0, f1, f31
	  stfs      f0, 0x47C(r31)
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D39FC
 * Size:	000008
 */
f32 TAIAwaitDororo::getWaitCounterMax(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, 0x47C(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D3A04
 * Size:	00004C
 */
void TAIAflickingDororo::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x24CC0
	  mr        r3, r31
	  bl        -0x30FD8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x38
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x28
	  addi      r3, r3, 0x70
	  bl        -0x150038

	.loc_0x38:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D3A50
 * Size:	00005C
 */
bool TAIAflickingDororo::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x38
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x99
	  bl        -0x1494D0

	.loc_0x38:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x24CA4
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
 * Address:	801D3AAC
 * Size:	0000B8
 */
f32 TAIAgoGoalPathDororo::getWalkVelocity(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  addi      r31, r4, 0
	  addi      r4, r1, 0x8C
	  stw       r0, 0x8C(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x8C(r1)
	  subi      r0, r3, 0x2A4C
	  mr        r3, r31
	  stw       r0, 0x8C(r1)
	  stw       r31, 0x90(r1)
	  bl        -0x8B690
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x2C4(r31)
	  stw       r0, 0x9C(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x84(r3)
	  stw       r0, 0x98(r1)
	  lwz       r3, 0x4(r3)
	  lfd       f1, -0x42F0(r2)
	  lfd       f0, 0x98(r1)
	  lwz       r3, 0x0(r3)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x4354(r2)
	  lfs       f2, 0xD0(r3)
	  fdivs     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x8C
	  fmr       f1, f0

	.loc_0x8C:
	  lfs       f0, 0xD4(r3)
	  lfs       f2, -0x4354(r2)
	  fmuls     f1, f1, f0
	  lfs       f0, 0xC(r3)
	  fsubs     f1, f2, f1
	  fmuls     f1, f1, f0
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D3B64
 * Size:	00087C
 */
bool TAIAkillTouchPiki::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x6365
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x6E74
	  stwu      r1, -0x238(r1)
	  stfd      f31, 0x230(r1)
	  stfd      f30, 0x228(r1)
	  stmw      r23, 0x204(r1)
	  mr        r31, r4
	  stw       r0, 0x1CC(r1)
	  lwz       r3, 0x220(r4)
	  lwz       r4, 0x1CC(r1)
	  bl        -0x14A484
	  mr.       r30, r3
	  bne-      .loc_0x40
	  b         .loc_0x2DC

	.loc_0x40:
	  lfs       f1, -0x42E8(r2)
	  lfs       f0, 0x0(r30)
	  lwz       r3, 0x3120(r13)
	  fmuls     f31, f1, f0
	  bl        -0xBC7F0
	  lfs       f0, -0x4360(r2)
	  mr        r23, r3
	  addi      r6, r1, 0xD8
	  stfs      f0, 0x164(r1)
	  addi      r5, r1, 0xD4
	  addi      r4, r1, 0xD0
	  stfs      f0, 0x160(r1)
	  stfs      f0, 0x15C(r1)
	  lfs       f1, 0x9C(r3)
	  addi      r3, r1, 0x15C
	  lfs       f0, 0xC(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xD8(r1)
	  lfs       f1, 0x98(r23)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xD4(r1)
	  lfs       f1, 0x94(r23)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xD0(r1)
	  bl        -0x176580
	  lfs       f1, 0x15C(r1)
	  lfs       f0, 0x160(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x164(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1C5FF0
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x12C
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0xC
	  lwz       r3, 0x84(r3)
	  bl        -0xB0A38
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x1D0(r1)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x31FC
	  stw       r31, 0x1D4(r1)
	  li        r0, 0
	  addi      r3, r23, 0
	  stw       r4, 0x1D0(r1)
	  addi      r4, r1, 0x1D0
	  stfs      f1, 0x1D8(r1)
	  stw       r0, 0x1DC(r1)
	  stb       r0, 0x1E0(r1)
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x12C:
	  lwz       r3, 0x3068(r13)
	  li        r0, 0
	  stw       r3, 0x1E8(r1)
	  addi      r3, r1, 0x1E4
	  stw       r0, 0x1EC(r1)
	  bl        -0x143EE8
	  lis       r4, 0x802B
	  lfs       f30, -0x4360(r2)
	  lis       r3, 0x802B
	  subi      r29, r4, 0x3064
	  subi      r28, r3, 0x328C
	  addi      r24, r1, 0x1F0
	  addi      r30, r30, 0x4
	  addi      r27, r1, 0xCC
	  addi      r26, r1, 0xC8
	  addi      r25, r1, 0xC4
	  b         .loc_0x280

	.loc_0x170:
	  lwz       r4, 0x1E4(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x198
	  lwz       r3, 0x1E8(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC

	.loc_0x198:
	  lwz       r3, 0x1E8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1AC:
	  cmplwi    r3, 0
	  addi      r23, r3, 0
	  beq-      .loc_0x278
	  stfs      f30, 0x148(r1)
	  addi      r7, r3, 0x94
	  addi      r4, r25, 0
	  stfs      f30, 0x144(r1)
	  addi      r5, r26, 0
	  addi      r6, r27, 0
	  stfs      f30, 0x140(r1)
	  addi      r3, r1, 0x140
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xCC(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC8(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC4(r1)
	  bl        -0x1766E0
	  lfs       f1, 0x140(r1)
	  lfs       f0, 0x144(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x148(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1C6150
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x278
	  stw       r29, 0x1F0(r1)
	  li        r0, 0
	  addi      r3, r23, 0
	  stw       r31, 0x1F4(r1)
	  mr        r4, r24
	  stw       r28, 0x1F0(r1)
	  stw       r0, 0x1F8(r1)
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x1E4(r1)
	  cmpwi     r3, 0
	  blt-      .loc_0x278
	  subi      r0, r3, 0x1
	  stw       r0, 0x1E4(r1)

	.loc_0x278:
	  addi      r3, r1, 0x1E4
	  bl        -0x144148

	.loc_0x280:
	  lwz       r3, 0x1E8(r1)
	  lwz       r4, 0x1E4(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2A8
	  li        r0, 0x1
	  b         .loc_0x2D4

	.loc_0x2A8:
	  lwz       r3, 0x1E8(r1)
	  lwz       r4, 0x1E4(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2D0
	  li        r0, 0x1
	  b         .loc_0x2D4

	.loc_0x2D0:
	  li        r0, 0

	.loc_0x2D4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x170

	.loc_0x2DC:
	  lis       r3, 0x6B62
	  addi      r0, r3, 0x3031
	  stw       r0, 0x19C(r1)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x19C(r1)
	  bl        -0x14A744
	  mr.       r30, r3
	  bne-      .loc_0x300
	  b         .loc_0x59C

	.loc_0x300:
	  lfs       f1, -0x42E8(r2)
	  lfs       f0, 0x0(r30)
	  lwz       r3, 0x3120(r13)
	  fmuls     f31, f1, f0
	  bl        -0xBCAB0
	  lfs       f0, -0x4360(r2)
	  mr        r23, r3
	  addi      r6, r1, 0xC0
	  stfs      f0, 0x134(r1)
	  addi      r5, r1, 0xBC
	  addi      r4, r1, 0xB8
	  stfs      f0, 0x130(r1)
	  stfs      f0, 0x12C(r1)
	  lfs       f1, 0x9C(r3)
	  addi      r3, r1, 0x12C
	  lfs       f0, 0xC(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lfs       f1, 0x98(r23)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xBC(r1)
	  lfs       f1, 0x94(r23)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xB8(r1)
	  bl        -0x176840
	  lfs       f1, 0x12C(r1)
	  lfs       f0, 0x130(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x134(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1C62B0
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x3EC
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0xC
	  lwz       r3, 0x84(r3)
	  bl        -0xB0CF8
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x1A0(r1)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x31FC
	  stw       r31, 0x1A4(r1)
	  li        r0, 0
	  addi      r3, r23, 0
	  stw       r4, 0x1A0(r1)
	  addi      r4, r1, 0x1A0
	  stfs      f1, 0x1A8(r1)
	  stw       r0, 0x1AC(r1)
	  stb       r0, 0x1B0(r1)
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x3EC:
	  lwz       r3, 0x3068(r13)
	  li        r0, 0
	  stw       r3, 0x1B8(r1)
	  addi      r3, r1, 0x1B4
	  stw       r0, 0x1BC(r1)
	  bl        -0x1441A8
	  lis       r4, 0x802B
	  lfs       f30, -0x4360(r2)
	  lis       r3, 0x802B
	  subi      r29, r4, 0x3064
	  subi      r28, r3, 0x328C
	  addi      r27, r1, 0x1C0
	  addi      r30, r30, 0x4
	  addi      r24, r1, 0xB4
	  addi      r25, r1, 0xB0
	  addi      r26, r1, 0xAC
	  b         .loc_0x540

	.loc_0x430:
	  lwz       r4, 0x1B4(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x458
	  lwz       r3, 0x1B8(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x46C

	.loc_0x458:
	  lwz       r3, 0x1B8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x46C:
	  cmplwi    r3, 0
	  addi      r23, r3, 0
	  beq-      .loc_0x538
	  stfs      f30, 0x118(r1)
	  addi      r7, r3, 0x94
	  addi      r4, r26, 0
	  stfs      f30, 0x114(r1)
	  addi      r5, r25, 0
	  addi      r6, r24, 0
	  stfs      f30, 0x110(r1)
	  addi      r3, r1, 0x110
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xB4(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xB0(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xAC(r1)
	  bl        -0x1769A0
	  lfs       f1, 0x110(r1)
	  lfs       f0, 0x114(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x118(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1C6410
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x538
	  stw       r29, 0x1C0(r1)
	  li        r0, 0
	  addi      r3, r23, 0
	  stw       r31, 0x1C4(r1)
	  mr        r4, r27
	  stw       r28, 0x1C0(r1)
	  stw       r0, 0x1C8(r1)
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x1B4(r1)
	  cmpwi     r3, 0
	  blt-      .loc_0x538
	  subi      r0, r3, 0x1
	  stw       r0, 0x1B4(r1)

	.loc_0x538:
	  addi      r3, r1, 0x1B4
	  bl        -0x144408

	.loc_0x540:
	  lwz       r3, 0x1B8(r1)
	  lwz       r4, 0x1B4(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x568
	  li        r0, 0x1
	  b         .loc_0x594

	.loc_0x568:
	  lwz       r3, 0x1B8(r1)
	  lwz       r4, 0x1B4(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x590
	  li        r0, 0x1
	  b         .loc_0x594

	.loc_0x590:
	  li        r0, 0

	.loc_0x594:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x430

	.loc_0x59C:
	  lis       r3, 0x6D6E
	  addi      r0, r3, 0x3031
	  stw       r0, 0x16C(r1)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x16C(r1)
	  bl        -0x14AA04
	  mr.       r28, r3
	  bne-      .loc_0x5C0
	  b         .loc_0x85C

	.loc_0x5C0:
	  lfs       f1, -0x42E8(r2)
	  lfs       f0, 0x0(r28)
	  lwz       r3, 0x3120(r13)
	  fmuls     f31, f1, f0
	  bl        -0xBCD70
	  lfs       f0, -0x4360(r2)
	  mr        r23, r3
	  addi      r6, r1, 0xA8
	  stfs      f0, 0x104(r1)
	  addi      r5, r1, 0xA4
	  addi      r4, r1, 0xA0
	  stfs      f0, 0x100(r1)
	  stfs      f0, 0xFC(r1)
	  lfs       f1, 0x9C(r3)
	  addi      r3, r1, 0xFC
	  lfs       f0, 0xC(r28)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f1, 0x98(r23)
	  lfs       f0, 0x8(r28)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA4(r1)
	  lfs       f1, 0x94(r23)
	  lfs       f0, 0x4(r28)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  bl        -0x176B00
	  lfs       f1, 0xFC(r1)
	  lfs       f0, 0x100(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x104(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1C6570
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x6AC
	  lwz       r3, 0x2C4(r31)
	  li        r4, 0xC
	  lwz       r3, 0x84(r3)
	  bl        -0xB0FB8
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x170(r1)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x31FC
	  stw       r31, 0x174(r1)
	  li        r0, 0
	  addi      r3, r23, 0
	  stw       r4, 0x170(r1)
	  addi      r4, r1, 0x170
	  stfs      f1, 0x178(r1)
	  stw       r0, 0x17C(r1)
	  stb       r0, 0x180(r1)
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x6AC:
	  lwz       r3, 0x3068(r13)
	  li        r0, 0
	  stw       r3, 0x188(r1)
	  addi      r3, r1, 0x184
	  stw       r0, 0x18C(r1)
	  bl        -0x144468
	  lis       r4, 0x802B
	  lfs       f30, -0x4360(r2)
	  lis       r3, 0x802B
	  subi      r29, r4, 0x3064
	  subi      r30, r3, 0x328C
	  addi      r27, r1, 0x190
	  addi      r28, r28, 0x4
	  addi      r24, r1, 0x9C
	  addi      r25, r1, 0x98
	  addi      r26, r1, 0x94
	  b         .loc_0x800

	.loc_0x6F0:
	  lwz       r4, 0x184(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x718
	  lwz       r3, 0x188(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x72C

	.loc_0x718:
	  lwz       r3, 0x188(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x72C:
	  cmplwi    r3, 0
	  addi      r23, r3, 0
	  beq-      .loc_0x7F8
	  stfs      f30, 0xE8(r1)
	  addi      r7, r3, 0x94
	  addi      r4, r26, 0
	  stfs      f30, 0xE4(r1)
	  addi      r5, r25, 0
	  addi      r6, r24, 0
	  stfs      f30, 0xE0(r1)
	  addi      r3, r1, 0xE0
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x8(r28)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r28)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r28)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x94(r1)
	  bl        -0x176C60
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0xE4(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xE8(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1C66D0
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x7F8
	  stw       r29, 0x190(r1)
	  li        r0, 0
	  addi      r3, r23, 0
	  stw       r31, 0x194(r1)
	  mr        r4, r27
	  stw       r30, 0x190(r1)
	  stw       r0, 0x198(r1)
	  lwz       r12, 0x0(r23)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x184(r1)
	  cmpwi     r3, 0
	  blt-      .loc_0x7F8
	  subi      r0, r3, 0x1
	  stw       r0, 0x184(r1)

	.loc_0x7F8:
	  addi      r3, r1, 0x184
	  bl        -0x1446C8

	.loc_0x800:
	  lwz       r3, 0x188(r1)
	  lwz       r4, 0x184(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x828
	  li        r0, 0x1
	  b         .loc_0x854

	.loc_0x828:
	  lwz       r3, 0x188(r1)
	  lwz       r4, 0x184(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x850
	  li        r0, 0x1
	  b         .loc_0x854

	.loc_0x850:
	  li        r0, 0

	.loc_0x854:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x6F0

	.loc_0x85C:
	  lmw       r23, 0x204(r1)
	  li        r3, 0
	  lwz       r0, 0x23C(r1)
	  lfd       f31, 0x230(r1)
	  lfd       f30, 0x228(r1)
	  addi      r1, r1, 0x238
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D43E0
 * Size:	000190
 */
void TAIAdyingDororo::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0x220(r4)
	  lis       r4, 0x6B62
	  addi      r4, r4, 0x3031
	  bl        -0x14ACF8
	  mr.       r4, r3
	  beq-      .loc_0x4C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0xA2
	  li        r6, 0
	  li        r7, 0
	  bl        -0x378F0

	.loc_0x4C:
	  lis       r4, 0x6D6E
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x3031
	  bl        -0x14AD28
	  mr.       r4, r3
	  beq-      .loc_0x7C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r4, 0x4
	  li        r4, 0xA6
	  li        r6, 0
	  li        r7, 0
	  bl        -0x37920

	.loc_0x7C:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x2BF38
	  lwz       r3, 0x498(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0xA0:
	  lwz       r3, 0x49C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xB8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0xB8:
	  lwz       r3, 0x4A0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xD0
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0xD0:
	  lwz       r3, 0x4A4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0xE8:
	  lwz       r3, 0x4A8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x100
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x100:
	  lwz       r3, 0x4AC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x118
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x118:
	  lwz       r3, 0x4B0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x130
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x130:
	  lwz       r3, 0x4B4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x148
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x148:
	  lwz       r3, 0x4B8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x160
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x160:
	  mr        r3, r31
	  bl        -0x3588
	  lfs       f0, -0x4360(r2)
	  stfs      f0, 0x478(r31)
	  lfs       f0, -0x42F8(r2)
	  stfs      f0, 0x47C(r31)
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
 * Address:	801D4570
 * Size:	00022C
 */
bool TAIAdyingDororo::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r4
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x3A8(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x38
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x98
	  bl        -0x149FF0

	.loc_0x38:
	  lwz       r3, 0x2CC(r31)
	  lwz       r0, 0x38(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0xF8
	  lwz       r3, 0x410(r31)
	  lwz       r0, -0x9C8(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0xF8
	  lwz       r3, 0x498(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x70:
	  lwz       r3, 0x49C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x88
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x88:
	  lwz       r3, 0x4AC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0xA0:
	  lwz       r3, 0x4A4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xB8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0xB8:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x9B
	  bl        -0x14A080
	  mr        r3, r31
	  lwz       r4, -0x9C4(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, -0x9C8(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl

	.loc_0xF8:
	  lwz       r3, 0x410(r31)
	  lwz       r0, -0x9C8(r13)
	  and.      r0, r3, r0
	  bne-      .loc_0x210
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x478(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x478(r31)
	  lfs       f1, 0x478(r31)
	  lfs       f0, 0x47C(r31)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x210
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x2C080
	  lwz       r3, 0x498(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x150
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x150:
	  lwz       r3, 0x49C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x168
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x168:
	  lwz       r3, 0x4A0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x180
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x180:
	  lwz       r3, 0x4A4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x198
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x198:
	  lwz       r3, 0x4A8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1B0
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1B0:
	  lwz       r3, 0x4AC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1C8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1C8:
	  lwz       r3, 0x4B0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1E0
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1E0:
	  lwz       r3, 0x4B4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x1F8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x1F8:
	  lwz       r3, 0x4B8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x210
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)

	.loc_0x210:
	  lwz       r0, 0x54(r1)
	  li        r3, 0x1
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D479C
 * Size:	00005C
 */
void TAIAinitDororo::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x7465
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x7374
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  lfs       f0, -0x42E4(r2)
	  stfs      f0, 0x270(r4)
	  stw       r0, 0x350(r4)
	  lwz       r12, 0x0(r31)
	  lwz       r4, -0x9C8(r13)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x4360(r2)
	  stfs      f0, 0x4C4(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D47F8
 * Size:	000008
 */
bool TAIAinitDororo::act(Teki&) { return true; }
