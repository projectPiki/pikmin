#include "TAI/Miurin.h"
#include "ComplexCreature.h"

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
 * Address:	801D624C
 * Size:	000084
 */
TAImiurinSoundTable::TAImiurinSoundTable()
    : PaniSoundTable(3)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  bl        -0xB71F8
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x58

	.loc_0x30:
	  li        r3, 0x4
	  bl        -0x18F27C
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  addi      r0, r30, 0x86
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
 * Address:	801D62D0
 * Size:	000404
 */
TAImiurinParameters::TAImiurinParameters()
    : TekiParameters(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802E
	  stw       r0, 0x4(r1)
	  li        r5, 0x36
	  stwu      r1, -0xE0(r1)
	  stw       r31, 0xDC(r1)
	  addi      r31, r4, 0x4BC8
	  li        r4, 0x17
	  stw       r30, 0xD8(r1)
	  addi      r30, r3, 0
	  bl        -0x8A5B0
	  lis       r3, 0x802E
	  addi      r0, r3, 0x5754
	  stw       r0, 0x0(r30)
	  li        r0, 0x14
	  li        r8, 0x15
	  lwz       r4, 0x84(r30)
	  li        r7, 0x16
	  li        r6, 0x32
	  lwz       r10, 0x0(r4)
	  li        r5, 0x33
	  lwz       r9, 0x4(r4)
	  mulli     r3, r0, 0xC
	  lwz       r11, 0x8(r10)
	  lwz       r0, 0x8(r9)
	  add       r10, r11, r3
	  addi      r3, r31, 0x1C
	  stw       r3, 0x0(r10)
	  li        r3, 0
	  mulli     r8, r8, 0xC
	  stw       r3, 0x4(r10)
	  li        r9, 0x64
	  stw       r9, 0x8(r10)
	  add       r10, r11, r8
	  addi      r8, r31, 0x30
	  stw       r8, 0x0(r10)
	  mulli     r7, r7, 0xC
	  stw       r3, 0x4(r10)
	  add       r8, r11, r7
	  stw       r9, 0x8(r10)
	  addi      r7, r31, 0x44
	  mulli     r6, r6, 0xC
	  stw       r7, 0x0(r8)
	  stw       r3, 0x4(r8)
	  mulli     r7, r5, 0xC
	  stw       r9, 0x8(r8)
	  add       r8, r0, r6
	  addi      r5, r31, 0x64
	  stw       r5, 0x0(r8)
	  li        r5, 0x34
	  mulli     r6, r5, 0xC
	  lfs       f7, -0x4260(r2)
	  stfs      f7, 0x4(r8)
	  li        r5, 0x35
	  mulli     r5, r5, 0xC
	  lfs       f6, -0x425C(r2)
	  stfs      f6, 0x8(r8)
	  add       r8, r0, r7
	  addi      r7, r31, 0x7C
	  stw       r7, 0x0(r8)
	  add       r9, r0, r6
	  addi      r7, r31, 0x90
	  stfs      f7, 0x4(r8)
	  add       r10, r0, r5
	  addi      r5, r31, 0xA8
	  stfs      f6, 0x8(r8)
	  li        r0, 0xA
	  li        r6, 0x1E
	  stw       r7, 0x0(r9)
	  stfs      f7, 0x4(r9)
	  lfs       f5, -0x4258(r2)
	  stfs      f5, 0x8(r9)
	  stw       r5, 0x0(r10)
	  stfs      f7, 0x4(r10)
	  lfs       f0, -0x4254(r2)
	  stfs      f0, 0x8(r10)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r0, 0x50(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r6, 0x54(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r0, 0x58(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4250(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xC8(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xCC(r5)
	  lwz       r5, 0x4(r4)
	  li        r9, -0x1
	  lfs       f4, -0x424C(r2)
	  li        r8, 0x5
	  lwz       r5, 0x0(r5)
	  li        r7, 0x2
	  stfs      f4, 0xD0(r5)
	  li        r6, 0x3
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4248(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0xD4(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r9, 0xC(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r8, 0x24(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r7, 0x28(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r8, 0x2C(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r0, 0x30(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r6, 0x34(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r6, 0x38(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r6, 0x3C(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r6, 0x40(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r3, 0x8(r5)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r3, 0x18(r5)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x8(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f3, -0x4244(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f3, 0x4(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4240(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x423C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xC(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4238(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x10(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4234(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4230(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x18(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x422C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  stfs      f5, 0x70(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f2, -0x4228(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f2, 0x20(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x4224(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x24(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f1, -0x4220(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f1, 0x28(r3)
	  lwz       r3, 0x4(r4)
	  lfs       f0, -0x421C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x2C(r3)
	  lwz       r5, 0x4(r4)
	  mr        r3, r30
	  lfs       f0, -0x4218(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x30(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4214(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x3C(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4210(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x40(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x420C(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x78(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4208(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x7C(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f3, 0x80(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f5, 0x84(r5)
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
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x94(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x4204(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x44(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x48(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f6, 0x98(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f2, 0x50(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f4, 0x54(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f7, 0x58(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f1, 0x5C(r5)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f7, 0x60(r4)
	  lwz       r0, 0xE4(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D66D4
 * Size:	0019CC
 */
TAImiurinStrategy::TAImiurinStrategy()
    : YaiStrategy(0, 0) // TODO: fix
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x18
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0x198(r1)
	  stmw      r14, 0x150(r1)
	  addi      r31, r3, 0
	  bl        0x12F64
	  lis       r3, 0x802E
	  addi      r0, r3, 0x4E78
	  stw       r0, 0x0(r31)
	  li        r3, 0x8
	  bl        -0x18F700
	  stw       r3, 0x14C(r1)
	  lwz       r0, 0x14C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x14C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x3
	  lwz       r3, 0x14C(r1)
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x568C
	  lwz       r3, 0x14C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x70:
	  li        r3, 0x8
	  bl        -0x18F744
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0xA4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r28)
	  li        r0, 0
	  lis       r3, 0x802E
	  stw       r0, 0x0(r28)
	  subi      r0, r3, 0xCB4
	  stw       r0, 0x4(r28)

	.loc_0xA4:
	  li        r3, 0xC
	  bl        -0x18F778
	  stw       r3, 0x148(r1)
	  lwz       r3, 0x148(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  li        r4, -0x1
	  li        r5, 0
	  bl        -0x29B44
	  lis       r3, 0x802E
	  subi      r0, r3, 0xD14
	  lwz       r3, 0x148(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5654
	  lwz       r3, 0x148(r1)
	  stw       r0, 0x4(r3)

	.loc_0xE8:
	  li        r3, 0xC
	  bl        -0x18F7BC
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x124
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r29)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r29)
	  subi      r3, r3, 0xE10
	  li        r0, 0x1
	  stw       r3, 0x4(r29)
	  stb       r0, 0x8(r29)

	.loc_0x124:
	  li        r3, 0x8
	  bl        -0x18F7F8
	  addi      r22, r3, 0
	  mr.       r0, r22
	  beq-      .loc_0x158
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r22)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r22)
	  subi      r0, r3, 0x6EC
	  stw       r0, 0x4(r22)

	.loc_0x158:
	  li        r3, 0xC
	  bl        -0x18F82C
	  stw       r3, 0x144(r1)
	  lwz       r3, 0x144(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x17C
	  li        r4, -0x1
	  li        r5, 0x2
	  bl        -0x29B6C

	.loc_0x17C:
	  li        r3, 0x24
	  bl        -0x18F850
	  stw       r3, 0x140(r1)
	  lwz       r3, 0x140(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x1F4
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  lwz       r4, 0x140(r1)
	  lis       r5, 0x6173
	  stw       r0, 0x4(r4)
	  li        r0, -0x1
	  lwz       r4, 0x140(r1)
	  lis       r6, 0x802E
	  addi      r9, r5, 0x6931
	  stw       r0, 0x0(r4)
	  addi      r0, r6, 0x4BA8
	  lwz       r4, 0x140(r1)
	  addi      r10, r5, 0x6932
	  li        r5, 0x1
	  stw       r0, 0x4(r4)
	  li        r0, 0
	  li        r4, 0x44
	  stw       r0, 0x8(r1)
	  li        r6, 0x86
	  li        r7, 0xF
	  stw       r0, 0xC(r1)
	  li        r8, 0x2
	  lfs       f1, -0x4200(r2)
	  bl        -0xA74

	.loc_0x1F4:
	  li        r3, 0x24
	  bl        -0x18F8C8
	  addi      r20, r3, 0
	  mr.       r3, r20
	  beq-      .loc_0x25C
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r20)
	  lis       r4, 0x6173
	  li        r0, -0x1
	  lis       r5, 0x802E
	  stw       r0, 0x0(r20)
	  addi      r0, r5, 0x4BA8
	  stw       r0, 0x4(r20)
	  li        r0, 0
	  addi      r9, r4, 0x6931
	  stw       r0, 0x8(r1)
	  addi      r10, r4, 0x6932
	  li        r4, 0x43
	  stw       r0, 0xC(r1)
	  li        r5, 0x1
	  li        r6, 0x60
	  lfs       f1, -0x4200(r2)
	  li        r7, 0xF
	  li        r8, 0x2
	  bl        -0xADC

	.loc_0x25C:
	  li        r3, 0x18
	  bl        -0x18F930
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x2B4
	  li        r4, 0x9
	  li        r5, 0x4
	  bl        -0x29C6C
	  lis       r3, 0x802E
	  subi      r0, r3, 0x6D0
	  stw       r0, 0x4(r18)
	  li        r5, 0x4
	  lis       r4, 0x802E
	  stw       r5, 0xC(r18)
	  lis       r3, 0x802E
	  li        r0, 0
	  stw       r5, 0x10(r18)
	  subi      r4, r4, 0x780
	  addi      r3, r3, 0x55E8
	  stb       r0, 0x14(r18)
	  stw       r4, 0x4(r18)
	  stw       r3, 0x4(r18)

	.loc_0x2B4:
	  li        r3, 0xC
	  bl        -0x18F988
	  stw       r3, 0x13C(r1)
	  lwz       r3, 0x13C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F8
	  li        r4, -0x1
	  li        r5, 0x6
	  bl        -0x29CC8
	  lis       r3, 0x802E
	  subi      r0, r3, 0x638
	  lwz       r3, 0x13C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x552C
	  lwz       r3, 0x13C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x2F8:
	  li        r3, 0x8
	  bl        -0x18F9CC
	  stw       r3, 0x138(r1)
	  lwz       r0, 0x138(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x34C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x138(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0xA
	  lwz       r3, 0x138(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x160
	  lwz       r3, 0x138(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5490
	  lwz       r3, 0x138(r1)
	  stw       r0, 0x4(r3)

	.loc_0x34C:
	  li        r3, 0xC
	  bl        -0x18FA20
	  stw       r3, 0x134(r1)
	  lwz       r3, 0x134(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x380
	  li        r4, 0xB
	  li        r5, 0x8
	  bl        -0x29D60
	  lis       r3, 0x802E
	  addi      r0, r3, 0x5420
	  lwz       r3, 0x134(r1)
	  stw       r0, 0x4(r3)

	.loc_0x380:
	  li        r3, 0x18
	  bl        -0x18FA54
	  stw       r3, 0x130(r1)
	  lwz       r3, 0x130(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x3D8
	  li        r4, 0xC
	  li        r5, 0xA
	  bl        -0x29D94
	  lis       r3, 0x802E
	  addi      r0, r3, 0x53DC
	  lwz       r3, 0x130(r1)
	  li        r4, 0xB
	  stw       r0, 0x4(r3)
	  li        r0, 0xC
	  lwz       r3, 0x130(r1)
	  stw       r0, 0xC(r3)
	  li        r0, 0xA
	  lwz       r3, 0x130(r1)
	  stw       r4, 0x10(r3)
	  lwz       r3, 0x130(r1)
	  stw       r0, 0x14(r3)

	.loc_0x3D8:
	  li        r3, 0x8
	  bl        -0x18FAAC
	  stw       r3, 0x12C(r1)
	  lwz       r0, 0x12C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x41C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x12C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x3
	  lwz       r3, 0x12C(r1)
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x5398
	  lwz       r3, 0x12C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x41C:
	  li        r3, 0x8
	  bl        -0x18FAF0
	  stw       r3, 0x128(r1)
	  lwz       r0, 0x128(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x460
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x128(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0xF
	  lwz       r3, 0x128(r1)
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x5398
	  lwz       r3, 0x128(r1)
	  stw       r0, 0x4(r3)

	.loc_0x460:
	  li        r3, 0x8
	  bl        -0x18FB34
	  stw       r3, 0x124(r1)
	  lwz       r0, 0x124(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x4B4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x124(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0xB
	  lwz       r3, 0x124(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x160
	  lwz       r3, 0x124(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5490
	  lwz       r3, 0x124(r1)
	  stw       r0, 0x4(r3)

	.loc_0x4B4:
	  li        r3, 0x8
	  bl        -0x18FB88
	  stw       r3, 0x120(r1)
	  lwz       r0, 0x120(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x4F8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x120(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0xD
	  lwz       r3, 0x120(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x211C
	  lwz       r3, 0x120(r1)
	  stw       r0, 0x4(r3)

	.loc_0x4F8:
	  li        r3, 0xC
	  bl        -0x18FBCC
	  stw       r3, 0x11C(r1)
	  lwz       r3, 0x11C(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x51C
	  li        r4, 0xE
	  li        r5, 0xD
	  bl        -0x29F0C

	.loc_0x51C:
	  li        r3, 0x8
	  bl        -0x18FBF0
	  stw       r3, 0x118(r1)
	  lwz       r0, 0x118(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x560
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x118(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x8
	  lwz       r3, 0x118(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5C
	  lwz       r3, 0x118(r1)
	  stw       r0, 0x4(r3)

	.loc_0x560:
	  li        r3, 0x8
	  bl        -0x18FC34
	  stw       r3, 0x114(r1)
	  lwz       r0, 0x114(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x5A4
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x114(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x2
	  lwz       r3, 0x114(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x211C
	  lwz       r3, 0x114(r1)
	  stw       r0, 0x4(r3)

	.loc_0x5A4:
	  li        r3, 0xC
	  bl        -0x18FC78
	  addi      r16, r3, 0
	  mr.       r0, r16
	  beq-      .loc_0x5EC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r16)
	  li        r0, 0x10
	  lis       r3, 0x802E
	  stw       r0, 0x0(r16)
	  subi      r0, r3, 0x1E0
	  lis       r3, 0x802E
	  stw       r0, 0x4(r16)
	  li        r4, 0
	  addi      r0, r3, 0x531C
	  stw       r4, 0x8(r16)
	  stw       r0, 0x4(r16)

	.loc_0x5EC:
	  li        r3, 0xC
	  bl        -0x18FCC0
	  addi      r15, r3, 0
	  mr.       r0, r15
	  beq-      .loc_0x634
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r15)
	  li        r0, 0x10
	  lis       r3, 0x802E
	  stw       r0, 0x0(r15)
	  addi      r0, r3, 0x3CC
	  lis       r3, 0x802E
	  stw       r0, 0x4(r15)
	  li        r0, -0x1
	  addi      r3, r3, 0x52B0
	  stw       r0, 0x8(r15)
	  stw       r3, 0x4(r15)

	.loc_0x634:
	  li        r3, 0xC
	  bl        -0x18FD08
	  stw       r3, 0x110(r1)
	  lwz       r3, 0x110(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x678
	  li        r4, 0xA
	  li        r5, 0x9
	  bl        -0x2A048
	  lis       r3, 0x802E
	  addi      r0, r3, 0x2EC
	  lwz       r3, 0x110(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5244
	  lwz       r3, 0x110(r1)
	  stw       r0, 0x4(r3)

	.loc_0x678:
	  li        r3, 0x8
	  bl        -0x18FD4C
	  stw       r3, 0x10C(r1)
	  lwz       r0, 0x10C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x6CC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x10C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x11
	  lwz       r3, 0x10C(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x20A4
	  lwz       r3, 0x10C(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x51AC
	  lwz       r3, 0x10C(r1)
	  stw       r0, 0x4(r3)

	.loc_0x6CC:
	  li        r3, 0xC
	  bl        -0x18FDA0
	  stw       r3, 0x108(r1)
	  lwz       r3, 0x108(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x710
	  li        r4, 0x13
	  li        r5, 0x9
	  bl        -0x2A0E0
	  lis       r3, 0x802E
	  addi      r0, r3, 0x2EC
	  lwz       r3, 0x108(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5244
	  lwz       r3, 0x108(r1)
	  stw       r0, 0x4(r3)

	.loc_0x710:
	  li        r3, 0x18
	  bl        -0x18FDE4
	  stw       r3, 0x104(r1)
	  lwz       r3, 0x104(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x774
	  li        r4, -0x1
	  li        r5, 0x7
	  bl        -0x2A124
	  lis       r3, 0x802E
	  lwz       r5, 0x104(r1)
	  subi      r0, r3, 0x6D0
	  lwz       r3, 0x104(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r3, 0x7
	  li        r0, 0
	  stw       r3, 0xC(r5)
	  subi      r5, r4, 0x780
	  lwz       r4, 0x104(r1)
	  stw       r3, 0x10(r4)
	  lwz       r3, 0x104(r1)
	  stb       r0, 0x14(r3)
	  lwz       r3, 0x104(r1)
	  stw       r5, 0x4(r3)

	.loc_0x774:
	  li        r3, 0x8
	  bl        -0x18FE48
	  stw       r3, 0x100(r1)
	  lwz       r0, 0x100(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x7B8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0x100(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x3
	  lwz       r3, 0x100(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1A0
	  lwz       r3, 0x100(r1)
	  stw       r0, 0x4(r3)

	.loc_0x7B8:
	  li        r3, 0x8
	  bl        -0x18FE8C
	  cmplwi    r3, 0
	  beq-      .loc_0x7E8
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r3)
	  li        r0, 0x3
	  lis       r4, 0x802E
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x5C
	  stw       r0, 0x4(r3)

	.loc_0x7E8:
	  li        r3, 0x8
	  bl        -0x18FEBC
	  stw       r3, 0xFC(r1)
	  lwz       r0, 0xFC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x83C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xFC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x13
	  lwz       r3, 0xFC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x160
	  lwz       r3, 0xFC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5490
	  lwz       r3, 0xFC(r1)
	  stw       r0, 0x4(r3)

	.loc_0x83C:
	  li        r3, 0xC
	  bl        -0x18FF10
	  stw       r3, 0xF8(r1)
	  lwz       r3, 0xF8(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x870
	  li        r4, 0x14
	  li        r5, 0x8
	  bl        -0x2A250
	  lis       r3, 0x802E
	  addi      r0, r3, 0x5420
	  lwz       r3, 0xF8(r1)
	  stw       r0, 0x4(r3)

	.loc_0x870:
	  li        r3, 0x18
	  bl        -0x18FF44
	  stw       r3, 0xF4(r1)
	  lwz       r3, 0xF4(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C8
	  li        r4, 0x15
	  li        r5, 0xA
	  bl        -0x2A284
	  lis       r3, 0x802E
	  addi      r0, r3, 0x53DC
	  lwz       r3, 0xF4(r1)
	  li        r4, 0xB
	  stw       r0, 0x4(r3)
	  li        r0, 0xC
	  lwz       r3, 0xF4(r1)
	  stw       r0, 0xC(r3)
	  li        r0, 0xA
	  lwz       r3, 0xF4(r1)
	  stw       r4, 0x10(r3)
	  lwz       r3, 0xF4(r1)
	  stw       r0, 0x14(r3)

	.loc_0x8C8:
	  li        r3, 0x8
	  bl        -0x18FF9C
	  stw       r3, 0xF0(r1)
	  lwz       r0, 0xF0(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x90C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xF0(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x16
	  lwz       r3, 0xF0(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x211C
	  lwz       r3, 0xF0(r1)
	  stw       r0, 0x4(r3)

	.loc_0x90C:
	  li        r3, 0x8
	  bl        -0x18FFE0
	  stw       r3, 0xEC(r1)
	  lwz       r0, 0xEC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x960
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  lwz       r3, 0xEC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  li        r0, 0x14
	  lwz       r3, 0xEC(r1)
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x160
	  lwz       r3, 0xEC(r1)
	  lis       r4, 0x802E
	  stw       r0, 0x4(r3)
	  addi      r0, r4, 0x5490
	  lwz       r3, 0xEC(r1)
	  stw       r0, 0x4(r3)

	.loc_0x960:
	  li        r3, 0xC
	  bl        -0x190034
	  stw       r3, 0xE8(r1)
	  lwz       r3, 0xE8(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0x984
	  li        r4, 0x3
	  li        r5, 0xD
	  bl        -0x2A374

	.loc_0x984:
	  li        r3, 0xC
	  bl        -0x190058
	  addi      r24, r3, 0
	  mr.       r0, r24
	  beq-      .loc_0x9C0
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r24)
	  li        r0, 0x5
	  lis       r3, 0x802E
	  stw       r0, 0x0(r24)
	  subi      r0, r3, 0x558
	  stw       r0, 0x4(r24)
	  lfs       f0, -0x41FC(r2)
	  stfs      f0, 0x8(r24)

	.loc_0x9C0:
	  li        r3, 0x18
	  bl        -0x190094
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0xA00
	  li        r4, 0x6
	  li        r5, 0x4
	  bl        -0x2A3D0
	  lis       r3, 0x802E
	  subi      r0, r3, 0x6D0
	  stw       r0, 0x4(r23)
	  li        r3, 0x4
	  li        r0, 0x1
	  stw       r3, 0xC(r23)
	  stw       r3, 0x10(r23)
	  stb       r0, 0x14(r23)

	.loc_0xA00:
	  li        r3, 0xC
	  bl        -0x1900D4
	  stw       r3, 0xE4(r1)
	  lwz       r3, 0xE4(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xA34
	  li        r4, 0x2
	  li        r5, 0x6
	  bl        -0x2A414
	  lis       r3, 0x802E
	  subi      r0, r3, 0x5A0
	  lwz       r3, 0xE4(r1)
	  stw       r0, 0x4(r3)

	.loc_0xA34:
	  li        r3, 0xC
	  bl        -0x190108
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0xA70
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r17)
	  li        r0, 0x3
	  lis       r3, 0x802E
	  stw       r0, 0x0(r17)
	  subi      r0, r3, 0x149C
	  stw       r0, 0x4(r17)
	  lfs       f0, -0x41F8(r2)
	  stfs      f0, 0x8(r17)

	.loc_0xA70:
	  li        r3, 0xC
	  bl        -0x190144
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0xAAC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r21)
	  li        r0, 0x3
	  lis       r3, 0x802E
	  stw       r0, 0x0(r21)
	  subi      r0, r3, 0x149C
	  stw       r0, 0x4(r21)
	  lfs       f0, -0x4218(r2)
	  stfs      f0, 0x8(r21)

	.loc_0xAAC:
	  li        r3, 0x10
	  bl        -0x190180
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0xAEC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r19)
	  li        r0, 0x7
	  lis       r3, 0x802E
	  stw       r0, 0x0(r19)
	  addi      r4, r3, 0x50FC
	  li        r3, 0x10
	  stw       r4, 0x4(r19)
	  stw       r0, 0x8(r19)
	  stw       r3, 0xC(r19)

	.loc_0xAEC:
	  li        r3, 0xC
	  bl        -0x1901C0
	  stw       r3, 0xE0(r1)
	  lwz       r3, 0xE0(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xB20
	  li        r4, 0x3
	  li        r5, 0x5
	  bl        -0x2A500
	  lis       r3, 0x802E
	  addi      r0, r3, 0x50C0
	  lwz       r3, 0xE0(r1)
	  stw       r0, 0x4(r3)

	.loc_0xB20:
	  li        r3, 0x8
	  bl        -0x1901F4
	  addi      r14, r3, 0
	  mr.       r0, r14
	  beq-      .loc_0xB54
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r14)
	  li        r0, 0xF
	  lis       r3, 0x802E
	  stw       r0, 0x0(r14)
	  addi      r0, r3, 0x507C
	  stw       r0, 0x4(r14)

	.loc_0xB54:
	  li        r3, 0x8
	  bl        -0x190228
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0xB94
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r25)
	  li        r0, 0x4
	  lis       r3, 0x802E
	  stw       r0, 0x0(r25)
	  subi      r0, r3, 0x5C
	  lis       r3, 0x802E
	  stw       r0, 0x4(r25)
	  addi      r0, r3, 0x503C
	  stw       r0, 0x4(r25)

	.loc_0xB94:
	  li        r3, 0x18
	  bl        -0x190268
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0xBE0
	  li        r4, 0x2
	  li        r5, 0x4
	  bl        -0x2A5A4
	  lis       r3, 0x802E
	  subi      r0, r3, 0x6D0
	  stw       r0, 0x4(r26)
	  li        r4, 0x4
	  lis       r3, 0x802E
	  stw       r4, 0xC(r26)
	  li        r0, 0
	  subi      r3, r3, 0x780
	  stw       r4, 0x10(r26)
	  stb       r0, 0x14(r26)
	  stw       r3, 0x4(r26)

	.loc_0xBE0:
	  li        r3, 0xC
	  bl        -0x1902B4
	  stw       r3, 0xDC(r1)
	  lwz       r3, 0xDC(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xC14
	  li        r4, 0x9
	  li        r5, 0x3
	  bl        -0x2A680
	  lis       r3, 0x802E
	  addi      r0, r3, 0x4F90
	  lwz       r3, 0xDC(r1)
	  stw       r0, 0x4(r3)

	.loc_0xC14:
	  li        r3, 0x8
	  bl        -0x1902E8
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xC48
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6620
	  stw       r0, 0x4(r30)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x4F38
	  stw       r0, 0x4(r30)

	.loc_0xC48:
	  li        r3, 0x10
	  bl        -0x19031C
	  cmplwi    r3, 0
	  beq-      .loc_0xC88
	  lis       r4, 0x802C
	  addi      r0, r4, 0x6620
	  stw       r0, 0x4(r3)
	  li        r0, 0x17
	  lis       r4, 0x802E
	  stw       r0, 0x0(r3)
	  subi      r4, r4, 0x298
	  li        r0, 0x1
	  stw       r4, 0x4(r3)
	  lfs       f0, -0x41F4(r2)
	  stfs      f0, 0x8(r3)
	  stb       r0, 0xC(r3)

	.loc_0xC88:
	  li        r3, 0xC
	  bl        -0x19035C
	  stw       r3, 0xD8(r1)
	  lwz       r3, 0xD8(r1)
	  cmplwi    r3, 0
	  beq-      .loc_0xCBC
	  li        r4, 0x3
	  li        r5, 0x5
	  bl        -0x2A69C
	  lis       r3, 0x802E
	  addi      r0, r3, 0x4EF4
	  lwz       r3, 0xD8(r1)
	  stw       r0, 0x4(r3)

	.loc_0xCBC:
	  li        r3, 0xC
	  bl        -0x190390
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xCD8
	  li        r4, 0x1
	  bl        -0xB0310

	.loc_0xCD8:
	  li        r0, 0
	  lwz       r4, 0x8(r27)
	  rlwinm    r3,r0,2,0,29
	  lwz       r0, 0x14C(r1)
	  stwx      r0, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x4(r4)
	  bl        -0x1903C8
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xD10
	  li        r4, 0x3
	  bl        -0xB0348

	.loc_0xD10:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x2
	  li        r3, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r4, 0x8(r27)
	  lwz       r0, 0x148(r1)
	  rlwinm    r3,r3,2,0,29
	  stwx      r0, r4, r3
	  li        r3, 0xC
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x0(r4)
	  bl        -0x190420
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xD68
	  li        r4, 0x4
	  bl        -0xB03A0

	.loc_0xD68:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r3, 0x1
	  li        r0, 0x2
	  lwz       r5, 0x8(r27)
	  rlwinm    r4,r3,2,0,29
	  li        r3, 0x3
	  stwx      r22, r5, r4
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r5,r3,2,0,29
	  lwz       r4, 0x8(r27)
	  li        r3, 0xC
	  stwx      r25, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r24, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r27, 0xC(r4)
	  bl        -0x190484
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xDCC
	  li        r4, 0x8
	  bl        -0xB0404

	.loc_0xDCC:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r4, 0x140(r1)
	  lwz       r3, 0x8(r27)
	  li        r0, 0x2
	  stwx      r4, r3, r5
	  li        r7, 0x4
	  li        r3, 0x5
	  lwz       r5, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r8,r3,2,0,29
	  stwx      r29, r5, r0
	  li        r6, 0x3
	  rlwinm    r0,r6,2,0,29
	  lwz       r6, 0x8(r27)
	  li        r4, 0x6
	  rlwinm    r7,r7,2,0,29
	  stwx      r28, r6, r0
	  rlwinm    r6,r4,2,0,29
	  li        r5, 0x7
	  lwz       r4, 0x8(r27)
	  rlwinm    r0,r5,2,0,29
	  li        r3, 0xC
	  stwx      r19, r4, r7
	  lwz       r4, 0x8(r27)
	  stwx      r16, r4, r8
	  lwz       r4, 0x8(r27)
	  stwx      r15, r4, r6
	  lwz       r4, 0x8(r27)
	  stwx      r26, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x10(r4)
	  bl        -0x19052C
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xE74
	  li        r4, 0x8
	  bl        -0xB04AC

	.loc_0xE74:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r4, 0x140(r1)
	  lwz       r3, 0x8(r27)
	  li        r6, 0x3
	  stwx      r4, r3, r5
	  li        r0, 0x2
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r5, 0x4
	  li        r7, 0x5
	  stwx      r29, r3, r4
	  li        r0, 0x6
	  rlwinm    r6,r6,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r4, 0x7
	  rlwinm    r5,r5,2,0,29
	  stwx      r28, r3, r6
	  rlwinm    r6,r4,2,0,29
	  rlwinm    r7,r7,2,0,29
	  lwz       r4, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  li        r3, 0xC
	  stwx      r19, r4, r5
	  lwz       r4, 0x8(r27)
	  stwx      r16, r4, r7
	  lwz       r4, 0x8(r27)
	  stwx      r15, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r23, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x14(r4)
	  bl        -0x1905D4
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xF1C
	  li        r4, 0x9
	  bl        -0xB0554

	.loc_0xF1C:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  lwz       r5, 0x140(r1)
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  rlwinm    r6,r4,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r0, 0x2
	  li        r4, 0x3
	  stwx      r5, r3, r6
	  li        r5, 0x4
	  li        r6, 0x5
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r29, r3, r0
	  li        r0, 0x7
	  rlwinm    r8,r5,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r7, 0x6
	  rlwinm    r6,r6,2,0,29
	  stwx      r28, r3, r4
	  rlwinm    r5,r7,2,0,29
	  li        r9, 0x8
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r7,r9,2,0,29
	  stwx      r19, r3, r8
	  li        r3, 0xC
	  lwz       r4, 0x8(r27)
	  stwx      r16, r4, r6
	  lwz       r4, 0x8(r27)
	  stwx      r15, r4, r5
	  lwz       r5, 0xE4(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r21, r4, r7
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x18(r4)
	  bl        -0x190690
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xFD8
	  li        r4, 0xA
	  bl        -0xB0610

	.loc_0xFD8:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r6,r0,2,0,29
	  lwz       r0, 0x140(r1)
	  lwz       r4, 0x8(r27)
	  li        r5, 0x2
	  stwx      r0, r4, r6
	  li        r0, 0x5
	  li        r9, 0x6
	  lwz       r4, 0x8(r27)
	  rlwinm    r5,r5,2,0,29
	  li        r8, 0x7
	  stwx      r29, r4, r5
	  li        r3, 0x3
	  rlwinm    r4,r3,2,0,29
	  lwz       r5, 0x8(r27)
	  li        r6, 0x4
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r5, r4
	  rlwinm    r4,r6,2,0,29
	  li        r3, 0x9
	  lwz       r5, 0x8(r27)
	  rlwinm    r6,r3,2,0,29
	  rlwinm    r9,r9,2,0,29
	  stwx      r19, r5, r4
	  li        r7, 0x8
	  rlwinm    r8,r8,2,0,29
	  lwz       r5, 0x8(r27)
	  rlwinm    r4,r7,2,0,29
	  li        r3, 0xC
	  stwx      r16, r5, r0
	  lwz       r0, 0x144(r1)
	  lwz       r5, 0x8(r27)
	  stwx      r15, r5, r9
	  lwz       r5, 0x8(r27)
	  stwx      r0, r5, r8
	  lwz       r5, 0x8(r27)
	  stwx      r17, r5, r4
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x8(r4)
	  bl        -0x19075C
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x10A4
	  li        r4, 0x5
	  bl        -0xB06DC

	.loc_0x10A4:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r4,2,0,29
	  li        r5, 0x3
	  stwx      r20, r3, r4
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x4
	  lwz       r3, 0x8(r27)
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r5,r4,2,0,29
	  stwx      r29, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0xDC(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r0, r4, r6
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x1C(r4)
	  bl        -0x1907D4
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x111C
	  li        r4, 0xA
	  bl        -0xB0754

	.loc_0x111C:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r6, 0x2
	  li        r0, 0x3
	  stwx      r20, r3, r4
	  li        r9, 0x6
	  li        r8, 0x7
	  lwz       r5, 0x8(r27)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r5, r6
	  li        r6, 0x9
	  li        r3, 0x4
	  lwz       r7, 0x8(r27)
	  li        r4, 0x5
	  li        r5, 0x8
	  stwx      r28, r7, r0
	  rlwinm    r0,r3,2,0,29
	  rlwinm    r7,r4,2,0,29
	  lwz       r3, 0x8(r27)
	  rlwinm    r9,r9,2,0,29
	  rlwinm    r8,r8,2,0,29
	  stwx      r19, r3, r0
	  rlwinm    r0,r5,2,0,29
	  lwz       r5, 0x12C(r1)
	  rlwinm    r6,r6,2,0,29
	  lwz       r4, 0x8(r27)
	  li        r3, 0xC
	  stwx      r5, r4, r7
	  lwz       r5, 0x138(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r18, r4, r9
	  lwz       r4, 0x8(r27)
	  stwx      r5, r4, r8
	  lwz       r4, 0x8(r27)
	  stwx      r16, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r15, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x20(r4)
	  bl        -0x1908A0
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x11E8
	  li        r4, 0x9
	  bl        -0xB0820

	.loc_0x11E8:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r0, 0x2
	  li        r4, 0x3
	  stwx      r29, r3, r5
	  li        r5, 0x4
	  rlwinm    r9,r5,2,0,29
	  lwz       r5, 0x138(r1)
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r28, r3, r0
	  li        r6, 0x5
	  li        r0, 0x7
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r4,2,0,29
	  rlwinm    r6,r6,2,0,29
	  stwx      r5, r3, r4
	  li        r7, 0x6
	  lwz       r4, 0x10C(r1)
	  rlwinm    r5,r7,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r8, 0x8
	  stwx      r4, r3, r9
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r7,r8,2,0,29
	  lwz       r4, 0x8(r27)
	  li        r3, 0xC
	  stwx      r16, r4, r6
	  lwz       r4, 0x8(r27)
	  stwx      r15, r4, r5
	  lwz       r5, 0x12C(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r5, r4, r0
	  lwz       r0, 0x13C(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r0, r4, r7
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x24(r4)
	  bl        -0x190964
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x12AC
	  li        r4, 0x5
	  bl        -0xB08E4

	.loc_0x12AC:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r20, r3, r0
	  li        r4, 0x1
	  li        r0, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r4,r4,2,0,29
	  li        r5, 0x3
	  stwx      r29, r3, r4
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x4
	  lwz       r3, 0x8(r27)
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r5,r4,2,0,29
	  stwx      r28, r3, r0
	  li        r3, 0xC
	  lwz       r0, 0x134(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r0, r4, r6
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x28(r4)
	  bl        -0x1909DC
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x1324
	  li        r4, 0x6
	  bl        -0xB095C

	.loc_0x1324:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r6, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x3
	  stwx      r20, r3, r0
	  li        r0, 0x4
	  rlwinm    r6,r6,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r5, 0x5
	  rlwinm    r4,r4,2,0,29
	  stwx      r29, r3, r6
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r5, 0x8(r27)
	  li        r3, 0xC
	  stwx      r28, r5, r4
	  lwz       r5, 0x130(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x2C(r4)
	  bl        -0x190A64
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x13AC
	  li        r4, 0x2
	  bl        -0xB09E4

	.loc_0x13AC:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x124(r1)
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0x120(r1)
	  lwz       r4, 0x8(r24)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x30(r4)
	  bl        -0x190AB0
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x13F8
	  li        r4, 0x8
	  bl        -0xB0A30

	.loc_0x13F8:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r5, 0x2
	  rlwinm    r6,r5,2,0,29
	  stwx      r20, r3, r4
	  li        r0, 0x3
	  li        r4, 0x5
	  lwz       r3, 0x8(r27)
	  li        r7, 0x4
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r6
	  li        r6, 0x7
	  li        r5, 0x6
	  lwz       r3, 0x8(r27)
	  rlwinm    r8,r4,2,0,29
	  rlwinm    r7,r7,2,0,29
	  stwx      r28, r3, r0
	  rlwinm    r0,r5,2,0,29
	  lwz       r5, 0x128(r1)
	  rlwinm    r6,r6,2,0,29
	  lwz       r4, 0x8(r27)
	  li        r3, 0xC
	  stwx      r5, r4, r7
	  lwz       r5, 0x11C(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r14, r4, r8
	  lwz       r4, 0x8(r27)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x34(r4)
	  bl        -0x190B5C
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x14A4
	  li        r4, 0x2
	  bl        -0xB0ADC

	.loc_0x14A4:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x118(r1)
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0x114(r1)
	  lwz       r4, 0x8(r24)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x38(r4)
	  bl        -0x190BA8
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x14F0
	  li        r4, 0x7
	  bl        -0xB0B28

	.loc_0x14F0:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0x140(r1)
	  lwz       r4, 0x8(r27)
	  li        r3, 0x2
	  stwx      r0, r4, r5
	  li        r5, 0x5
	  rlwinm    r3,r3,2,0,29
	  lwz       r4, 0x8(r27)
	  li        r6, 0x3
	  li        r0, 0x4
	  stwx      r29, r4, r3
	  rlwinm    r4,r6,2,0,29
	  rlwinm    r6,r0,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r7, 0x6
	  rlwinm    r5,r5,2,0,29
	  stwx      r28, r3, r4
	  rlwinm    r0,r7,2,0,29
	  li        r3, 0xC
	  lwz       r4, 0x8(r27)
	  stwx      r19, r4, r6
	  lwz       r6, 0xE0(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r6, r4, r5
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x3C(r4)
	  bl        -0x190C44
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x158C
	  li        r4, 0x6
	  bl        -0xB0BC4

	.loc_0x158C:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r0
	  li        r0, 0x1
	  li        r6, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x3
	  stwx      r28, r3, r0
	  li        r0, 0x4
	  rlwinm    r6,r6,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r5, 0x5
	  rlwinm    r4,r4,2,0,29
	  stwx      r30, r3, r6
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r5, 0x8(r27)
	  li        r3, 0xC
	  stwx      r20, r5, r4
	  lwz       r5, 0x110(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x40(r4)
	  bl        -0x190CCC
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x1614
	  li        r4, 0x4
	  bl        -0xB0C4C

	.loc_0x1614:
	  li        r0, 0
	  lwz       r3, 0x8(r26)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r3,r0,2,0,29
	  lwz       r4, 0x8(r26)
	  li        r5, 0x2
	  li        r0, 0x3
	  stwx      r22, r4, r3
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r26)
	  li        r3, 0xC
	  stwx      r20, r4, r5
	  lwz       r5, 0x108(r1)
	  lwz       r4, 0x8(r26)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r26, 0x44(r4)
	  bl        -0x190D34
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x167C
	  li        r4, 0x9
	  bl        -0xB0CB4

	.loc_0x167C:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r4, 0x1
	  rlwinm    r5,r4,2,0,29
	  lwz       r4, 0xFC(r1)
	  lwz       r3, 0x8(r27)
	  li        r6, 0x3
	  stwx      r4, r3, r5
	  li        r0, 0x2
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0x104(r1)
	  lwz       r3, 0x8(r27)
	  li        r4, 0x4
	  stwx      r0, r3, r5
	  li        r5, 0x7
	  li        r0, 0x8
	  lwz       r3, 0x8(r27)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r4,r4,2,0,29
	  stwx      r20, r3, r6
	  li        r7, 0x5
	  rlwinm    r6,r7,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r8, 0x6
	  rlwinm    r7,r8,2,0,29
	  stwx      r29, r3, r4
	  rlwinm    r5,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x8(r27)
	  li        r3, 0xC
	  stwx      r28, r4, r6
	  lwz       r6, 0x100(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r6, r4, r7
	  lwz       r4, 0x8(r27)
	  stwx      r16, r4, r5
	  lwz       r4, 0x8(r27)
	  stwx      r15, r4, r0
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x48(r4)
	  bl        -0x190DF4
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x173C
	  li        r4, 0x6
	  bl        -0xB0D74

	.loc_0x173C:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r6, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x3
	  stwx      r20, r3, r0
	  li        r0, 0x4
	  rlwinm    r6,r6,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r5, 0x5
	  rlwinm    r4,r4,2,0,29
	  stwx      r29, r3, r6
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r5, 0x8(r27)
	  li        r3, 0xC
	  stwx      r28, r5, r4
	  lwz       r5, 0xF8(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x4C(r4)
	  bl        -0x190E7C
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x17C4
	  li        r4, 0x6
	  bl        -0xB0DFC

	.loc_0x17C4:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  li        r6, 0x2
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  li        r4, 0x3
	  stwx      r20, r3, r0
	  li        r0, 0x4
	  rlwinm    r6,r6,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r5, 0x5
	  rlwinm    r4,r4,2,0,29
	  stwx      r29, r3, r6
	  rlwinm    r6,r5,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r5, 0x8(r27)
	  li        r3, 0xC
	  stwx      r28, r5, r4
	  lwz       r5, 0xF4(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x50(r4)
	  bl        -0x190F04
	  addi      r24, r3, 0
	  mr.       r3, r24
	  beq-      .loc_0x184C
	  li        r4, 0x2
	  bl        -0xB0E84

	.loc_0x184C:
	  li        r0, 0
	  lwz       r3, 0x8(r24)
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0xEC(r1)
	  stwx      r0, r3, r4
	  li        r0, 0x1
	  rlwinm    r5,r0,2,0,29
	  lwz       r0, 0xF0(r1)
	  lwz       r4, 0x8(r24)
	  li        r3, 0xC
	  stwx      r0, r4, r5
	  lwz       r4, 0x8(r31)
	  stw       r24, 0x54(r4)
	  bl        -0x190F50
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x1898
	  li        r4, 0x8
	  bl        -0xB0ED0

	.loc_0x1898:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r3, 0x8(r27)
	  li        r5, 0x2
	  rlwinm    r6,r5,2,0,29
	  stwx      r20, r3, r4
	  li        r0, 0x3
	  li        r4, 0x5
	  lwz       r3, 0x8(r27)
	  li        r7, 0x4
	  rlwinm    r0,r0,2,0,29
	  stwx      r29, r3, r6
	  li        r6, 0x7
	  li        r5, 0x6
	  lwz       r3, 0x8(r27)
	  rlwinm    r8,r4,2,0,29
	  rlwinm    r7,r7,2,0,29
	  stwx      r28, r3, r0
	  rlwinm    r0,r5,2,0,29
	  lwz       r5, 0x128(r1)
	  rlwinm    r6,r6,2,0,29
	  lwz       r4, 0x8(r27)
	  li        r3, 0xC
	  stwx      r5, r4, r7
	  lwz       r5, 0xE8(r1)
	  lwz       r4, 0x8(r27)
	  stwx      r14, r4, r8
	  lwz       r4, 0x8(r27)
	  stwx      r5, r4, r0
	  lwz       r4, 0x8(r27)
	  stwx      r22, r4, r6
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x58(r4)
	  bl        -0x190FFC
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x1944
	  li        r4, 0x6
	  bl        -0xB0F7C

	.loc_0x1944:
	  li        r0, 0
	  lwz       r3, 0x8(r27)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  li        r0, 0x1
	  rlwinm    r4,r0,2,0,29
	  lwz       r0, 0x140(r1)
	  lwz       r3, 0x8(r27)
	  li        r6, 0x2
	  stwx      r0, r3, r4
	  li        r5, 0x3
	  li        r4, 0x5
	  lwz       r3, 0x8(r27)
	  rlwinm    r6,r6,2,0,29
	  rlwinm    r5,r5,2,0,29
	  stwx      r29, r3, r6
	  li        r0, 0x4
	  rlwinm    r6,r0,2,0,29
	  lwz       r0, 0xD8(r1)
	  lwz       r7, 0x8(r27)
	  rlwinm    r4,r4,2,0,29
	  stwx      r28, r7, r5
	  mr        r3, r31
	  lwz       r5, 0x8(r27)
	  stwx      r0, r5, r6
	  lwz       r5, 0x8(r27)
	  stwx      r22, r5, r4
	  lwz       r4, 0x8(r31)
	  stw       r27, 0x5C(r4)
	  lmw       r14, 0x150(r1)
	  lwz       r0, 0x19C(r1)
	  addi      r1, r1, 0x198
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D80A0
 * Size:	0000C4
 */
void TAImiurinStrategy::interact(Teki&, TekiInteractionKey&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  lwz       r0, 0x0(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x28
	  b         .loc_0xA8

	.loc_0x28:
	  lwz       r3, 0x410(r30)
	  lwz       r0, -0x9B4(r13)
	  lwz       r4, 0x4(r5)
	  and.      r0, r3, r0
	  bne-      .loc_0x6C
	  lfs       f1, 0x33C(r30)
	  lfs       f0, 0x8(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x33C(r30)
	  lwz       r3, 0x410(r30)
	  lwz       r0, -0x9A4(r13)
	  and.      r0, r3, r0
	  beq-      .loc_0x6C
	  lfs       f1, 0x340(r30)
	  lfs       f0, -0x4244(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x340(r30)

	.loc_0x6C:
	  lwz       r3, 0x41C(r30)
	  lwz       r31, 0x4(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  beq-      .loc_0x8C
	  bl        -0xF3DB4
	  li        r0, 0
	  stw       r0, 0x41C(r30)

	.loc_0x8C:
	  stw       r31, 0x41C(r30)
	  lwz       r3, 0x41C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  bl        -0xF3DE0

	.loc_0xA0:
	  li        r3, 0x1
	  b         .loc_0xAC

	.loc_0xA8:
	  li        r3, 0x1

	.loc_0xAC:
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
 * Address:	801D8164
 * Size:	0006FC
 */
void TAImiurinAnimation::makeDefaultAnimations()
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
	  addi      r30, r3, 0x4BC8
	  cmplwi    r0, 0
	  beq-      .loc_0x6E4
	  lwz       r6, 0x3160(r13)
	  mr        r3, r31
	  lwz       r5, 0x2DEC(r13)
	  addi      r4, r30, 0xBC
	  lwz       r6, 0x124(r6)
	  lwz       r0, 0x0(r6)
	  stw       r0, 0x1FC(r5)
	  bl        -0x34C18
	  addi      r3, r31, 0
	  addi      r4, r30, 0xDC
	  bl        -0x34C24
	  addi      r3, r31, 0
	  addi      r4, r30, 0xFC
	  bl        -0x34C30
	  li        r3, 0x10
	  bl        -0x1911C8
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
	  bl        -0x191210
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
	  addi      r4, r30, 0x11C
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x34CD0
	  li        r3, 0x10
	  bl        -0x191268
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
	  bl        -0x1912B0
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
	  addi      r4, r30, 0x13C
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x34D70
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x187F4C
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187B04
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187B1C
	  li        r3, 0x10
	  bl        -0x191344
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
	  bl        -0x191390
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
	  addi      r4, r30, 0x160
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x34E54
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x188030
	  lwz       r3, 0x8(r31)
	  li        r0, 0x7
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187BE8
	  lwz       r3, 0x8(r31)
	  li        r0, 0x1B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187C00
	  li        r3, 0x10
	  bl        -0x191428
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
	  bl        -0x191474
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
	  addi      r4, r30, 0x184
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x34F38
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x188114
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187CCC
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187CE4
	  li        r3, 0x10
	  bl        -0x19150C
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
	  bl        -0x191558
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
	  addi      r4, r30, 0x1A4
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x3501C
	  lwz       r3, 0x8(r31)
	  li        r4, 0x6
	  bl        -0x1881F8
	  lwz       r3, 0x8(r31)
	  li        r0, 0xA
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187DB0
	  lwz       r3, 0x8(r31)
	  li        r0, 0x28
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187DC8
	  li        r3, 0x10
	  bl        -0x1915F0
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
	  bl        -0x19163C
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
	  addi      r4, r30, 0x1C4
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x35100
	  lwz       r3, 0x8(r31)
	  li        r0, 0x3A
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187E88
	  li        r3, 0x10
	  bl        -0x1916B0
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
	  addi      r4, r30, 0x1E4
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x35174
	  lwz       r3, 0x8(r31)
	  li        r0, 0x8
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187EFC
	  lwz       r3, 0x8(r31)
	  li        r0, 0x2B
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187F14
	  li        r3, 0x10
	  bl        -0x19173C
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
	  bl        -0x191788
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
	  addi      r4, r30, 0x204
	  lwz       r6, 0x60(r5)
	  lwz       r0, 0xC(r6)
	  stw       r0, 0xC(r7)
	  stw       r6, 0x8(r7)
	  lwz       r5, 0xC(r6)
	  stw       r7, 0x8(r5)
	  stw       r7, 0xC(r6)
	  bl        -0x3524C
	  lwz       r3, 0x8(r31)
	  li        r0, 0x20
	  lwz       r3, 0x40(r3)
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  bl        -0x187FD4
	  li        r3, 0x10
	  bl        -0x1917FC
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
 * Address:	801D8860
 * Size:	000038
 */
void TAIAgroggyMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x2BB70
	  lfs       f0, -0x4260(r2)
	  stfs      f0, 0x478(r31)
	  stfs      f0, 0x340(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D8898
 * Size:	0000AC
 */
bool TAIAgroggyMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  li        r31, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r4, 0
	  bl        -0x2B9FC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x90
	  lwz       r4, 0x2C4(r30)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x84(r4)
	  lfs       f1, 0x478(r30)
	  lwz       r4, 0x4(r4)
	  lfs       f0, 0x28C(r3)
	  lwz       r3, 0x0(r4)
	  fadds     f0, f1, f0
	  lfs       f1, 0xCC(r3)
	  fcmpo     cr0, f0, f1
	  stfs      f0, 0x478(r30)
	  ble-      .loc_0x80
	  cmplwi    r30, 0
	  addi      r5, r30, 0
	  beq-      .loc_0x68
	  lwz       r5, 0x2C0(r30)

	.loc_0x68:
	  addi      r3, r1, 0x48
	  li        r4, -0x1
	  bl        -0xB997C
	  mr        r4, r3
	  lwz       r3, 0x2CC(r30)
	  bl        -0xB96E4

	.loc_0x80:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x90
	  li        r31, 0x1

	.loc_0x90:
	  mr        r3, r31
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D8944
 * Size:	000034
 */
void TAIAresetAnimSpeedMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x1D0(r12)
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
 * Address:	801D8978
 * Size:	0000B8
 */
void TAIAangryMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r4
	  bl        -0x2BD14
	  lfs       f0, -0x4260(r2)
	  lis       r5, 0x802B
	  lis       r3, 0x802B
	  stfs      f0, 0x478(r31)
	  subi      r6, r5, 0x3064
	  subi      r0, r3, 0x3168
	  lwz       r5, 0x2C4(r31)
	  addi      r4, r1, 0x70
	  lfs       f0, 0xA0(r31)
	  mr        r3, r31
	  lwz       r5, 0x84(r5)
	  lfs       f1, -0x4254(r2)
	  lwz       r7, 0x4(r5)
	  mr        r5, r4
	  fadds     f0, f1, f0
	  lwz       r7, 0x0(r7)
	  lfs       f1, 0x8C(r7)
	  lfs       f2, 0x84(r7)
	  stw       r6, 0x70(r1)
	  stw       r31, 0x74(r1)
	  stw       r0, 0x70(r1)
	  stfs      f2, 0x78(r1)
	  stfs      f1, 0x7C(r1)
	  stfs      f0, 0x80(r1)
	  bl        -0x90C48
	  addi      r31, r31, 0x94
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r31, 0
	  li        r4, 0x3
	  bl        -0xB4A2C
	  lwz       r3, 0x3178(r13)
	  addi      r6, r31, 0
	  li        r4, 0xB
	  li        r5, 0
	  bl        -0x5BC44
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D8A30
 * Size:	000150
 */
bool TAIAangryMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  stw       r30, 0x70(r1)
	  li        r30, 0
	  stw       r29, 0x6C(r1)
	  addi      r29, r4, 0
	  bl        -0x2BD8C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x478(r29)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x478(r29)
	  lwz       r3, 0x3120(r13)
	  bl        -0xC16A8
	  lfs       f0, -0x4260(r2)
	  addi      r31, r29, 0x94
	  stfs      f0, 0x54(r1)
	  stfs      f0, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x94(r29)
	  lfs       f4, 0x8(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r29)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x98(r29)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x3C(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x3C(r1)
	  stfs      f0, 0x4C(r1)
	  stfs      f1, 0x50(r1)
	  stfs      f3, 0x54(r1)
	  lfs       f1, 0x4C(r1)
	  lfs       f2, 0x54(r1)
	  bl        -0xBACBC
	  stfs      f1, 0x394(r29)
	  lwz       r0, 0x3A8(r29)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x100
	  lfs       f0, 0x0(r31)
	  addi      r5, r1, 0x5C
	  li        r4, 0x4D
	  stfs      f0, 0x5C(r1)
	  li        r6, 0
	  li        r7, 0
	  lfs       f0, 0x4(r31)
	  stfs      f0, 0x60(r1)
	  lfs       f1, 0x8(r31)
	  lfs       f0, -0x424C(r2)
	  stfs      f1, 0x64(r1)
	  lfs       f1, 0x60(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x3BFDC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x5C
	  li        r4, 0x4E
	  li        r6, 0
	  li        r7, 0
	  bl        -0x3BFF4

	.loc_0x100:
	  lfs       f1, 0x478(r29)
	  lfs       f0, -0x41F0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x120
	  lfs       f1, 0x394(r29)
	  mr        r3, r29
	  lfs       f2, -0x41EC(r2)
	  bl        -0x91580

	.loc_0x120:
	  lwz       r0, 0x3A8(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0x130
	  li        r30, 0x1

	.loc_0x130:
	  mr        r3, r30
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D8B80
 * Size:	000010
 */
f32 TAIAangryMiurin::getFlickDirection(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x4254(r2)
	  lfs       f0, 0xA0(r4)
	  fadds     f1, f1, f0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D8B90
 * Size:	0000A8
 */
bool TAIAcheckNaviMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stw       r31, 0x54(r1)
	  li        r31, 0
	  stw       r30, 0x50(r1)
	  mr        r30, r4
	  stw       r29, 0x4C(r1)
	  addi      r29, r3, 0
	  lwz       r4, 0x2C4(r4)
	  lwz       r3, 0x84(r4)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f31, 0xD0(r3)
	  bl        0x3F4A4
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x41E0(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f1, -0x41E8(r2)
	  stw       r0, 0x40(r1)
	  lfs       f0, -0x4258(r2)
	  lfd       f2, 0x40(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0x84
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x2B410
	  mr        r31, r3

	.loc_0x84:
	  mr        r3, r31
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D8C38
 * Size:	0001D4
 */
bool TAIAcheckFlowerPikmin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stfd      f31, 0xD8(r1)
	  stmw      r26, 0xC0(r1)
	  addi      r26, r4, 0
	  li        r28, 0
	  li        r27, 0
	  lwz       r3, 0x30AC(r13)
	  lwz       r30, 0x64(r3)
	  lwz       r12, 0x0(r30)
	  addi      r3, r30, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x4260(r2)
	  addi      r29, r3, 0
	  addi      r31, r26, 0x94
	  b         .loc_0x15C

	.loc_0x4C:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x70
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x88

	.loc_0x70:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x88:
	  lwz       r0, 0x3D0(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x11C
	  stfs      f31, 0xAC(r1)
	  stfs      f31, 0xA8(r1)
	  stfs      f31, 0xA4(r1)
	  lfsu      f1, 0x94(r3)
	  lfs       f0, 0x0(r31)
	  lfs       f4, 0x8(r3)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r31)
	  lfs       f2, 0x4(r3)
	  lfs       f1, 0x4(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x90(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x90(r1)
	  stfs      f0, 0xA4(r1)
	  stfs      f1, 0xA8(r1)
	  stfs      f3, 0xAC(r1)
	  lfs       f1, 0xA4(r1)
	  lfs       f0, 0xA8(r1)
	  lfs       f2, 0xAC(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CB0F0
	  lwz       r3, 0x2C4(r26)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x40(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x11C
	  addi      r27, r27, 0x1

	.loc_0x11C:
	  lwz       r3, 0x2C4(r26)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x58(r3)
	  cmpw      r27, r0
	  blt-      .loc_0x140
	  li        r28, 0x1
	  b         .loc_0x1B8

	.loc_0x140:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x15C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x184
	  li        r0, 0x1
	  b         .loc_0x1B0

	.loc_0x184:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1AC
	  li        r0, 0x1
	  b         .loc_0x1B0

	.loc_0x1AC:
	  li        r0, 0

	.loc_0x1B0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4C

	.loc_0x1B8:
	  mr        r3, r28
	  lmw       r26, 0xC0(r1)
	  lwz       r0, 0xE4(r1)
	  lfd       f31, 0xD8(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D8E0C
 * Size:	000038
 */
void TAIAsatisfyMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x2C11C
	  lfs       f0, -0x4260(r2)
	  stfs      f0, 0x478(r31)
	  stfs      f0, 0x340(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D8E44
 * Size:	000128
 */
bool TAIAsatisfyMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  li        r31, 0
	  stw       r30, 0x60(r1)
	  addi      r30, r4, 0
	  bl        -0x2BFA8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8
	  lwz       r4, 0x2C4(r30)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x84(r4)
	  lfs       f1, 0x478(r30)
	  lwz       r4, 0x4(r4)
	  lfs       f0, 0x28C(r3)
	  lwz       r3, 0x0(r4)
	  fadds     f0, f1, f0
	  lfs       f1, 0xC8(r3)
	  fcmpo     cr0, f0, f1
	  stfs      f0, 0x478(r30)
	  ble-      .loc_0x80
	  cmplwi    r30, 0
	  addi      r5, r30, 0
	  beq-      .loc_0x68
	  lwz       r5, 0x2C0(r30)

	.loc_0x68:
	  addi      r3, r1, 0x4C
	  li        r4, -0x1
	  bl        -0xB9F28
	  mr        r4, r3
	  lwz       r3, 0x2CC(r30)
	  bl        -0xB9C90

	.loc_0x80:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x90
	  li        r31, 0x1

	.loc_0x90:
	  cmpwi     r0, 0x5
	  bne-      .loc_0xA8
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x88
	  bl        -0x14E934

	.loc_0xA8:
	  lwz       r0, 0x3A8(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x10C
	  lfs       f0, 0x94(r30)
	  li        r4, 0x1
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x5C(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x54(r1)
	  lfs       f2, 0x5C(r1)
	  bl        -0x17101C
	  stfs      f1, 0x58(r1)
	  addi      r5, r1, 0x54
	  li        r4, 0x43
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        -0x3C404
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x7
	  bl        -0x14E998

	.loc_0x10C:
	  mr        r3, r31
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
 * Address:	801D8F6C
 * Size:	0000E8
 */
bool TAIAwatchNaviMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r3, 0x3120(r13)
	  bl        -0xC1BD4
	  lfs       f1, 0x340(r29)
	  mr        r31, r3
	  lfs       f0, -0x4260(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x4C
	  li        r30, 0x1
	  b         .loc_0x74

	.loc_0x4C:
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        -0x922AC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  mr        r3, r31
	  bl        -0xE0BB8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  li        r30, 0x1

	.loc_0x74:
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0xC4
	  lwz       r3, 0x3120(r13)
	  bl        -0xC1C28
	  addi      r31, r3, 0
	  addi      r4, r31, 0
	  addi      r3, r29, 0x418
	  bl        .loc_0xE8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xBC
	  lwz       r0, 0xC(r28)
	  stw       r0, 0x0(r28)
	  b         .loc_0xC4

	.loc_0xBC:
	  lwz       r0, 0x8(r28)
	  stw       r0, 0x0(r28)

	.loc_0xC4:
	  mr        r3, r30
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0xE8:
	*/
}

/*
 * --INFO--
 * Address:	801D9054
 * Size:	000064
 */
void SmartPtr<Creature>::set(Creature*)
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
	  lwz       r3, 0x0(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  beq-      .loc_0x38
	  bl        -0xF4D14
	  li        r0, 0
	  stw       r0, 0x0(r30)

	.loc_0x38:
	  stw       r31, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x4C
	  bl        -0xF4D40

	.loc_0x4C:
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
 * Address:	801D90B8
 * Size:	0000C4
 */
bool TAIAwatchNaviMiurin::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  li        r29, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xA0
	  lwz       r3, 0x8(r30)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x36
	  bne-      .loc_0xA0
	  bl        -0xE0CE4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA0
	  lwz       r31, 0x4(r30)
	  li        r29, 0x1
	  lwz       r3, 0x3120(r13)
	  bl        -0xC1D50
	  addi      r30, r3, 0
	  addi      r4, r30, 0
	  addi      r3, r31, 0x418
	  bl        -0xD0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x98
	  lwz       r0, 0xC(r28)
	  stw       r0, 0x0(r28)
	  b         .loc_0xA0

	.loc_0x98:
	  lwz       r0, 0x8(r28)
	  stw       r0, 0x0(r28)

	.loc_0xA0:
	  mr        r3, r29
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
 * Address:	801D917C
 * Size:	000174
 */
bool TAIAoutsideTerritoryMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stw       r31, 0xB4(r1)
	  li        r31, 0
	  stw       r30, 0xB0(r1)
	  mr        r30, r4
	  lwz       r3, 0x2C4(r4)
	  li        r4, 0xF
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0xB6CD8
	  lwz       r3, 0x2C8(r30)
	  fmr       f31, f1
	  lfs       f0, -0x4260(r2)
	  addi      r6, r1, 0x74
	  addi      r8, r3, 0x10
	  stfs      f0, 0x90(r1)
	  addi      r5, r1, 0x70
	  stfs      f0, 0x8C(r1)
	  addi      r4, r1, 0x6C
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x18(r3)
	  addi      r3, r1, 0x88
	  lfs       f1, 0x9C(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x74(r1)
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  lfs       f1, 0x94(r30)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x6C(r1)
	  bl        -0x17BB80
	  lfs       f1, 0x88(r1)
	  lfs       f0, 0x8C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x90(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CB5F0
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0x154
	  lwz       r4, 0x2C8(r30)
	  lwz       r3, 0x418(r30)
	  lfs       f0, -0x4260(r2)
	  stfs      f0, 0xA8(r1)
	  stfs      f0, 0xA4(r1)
	  stfs      f0, 0xA0(r1)
	  lfsu      f1, 0x10(r4)
	  lfsu      f0, 0x94(r3)
	  lfs       f4, 0x8(r4)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x4(r4)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x98(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x98(r1)
	  stfs      f0, 0xA0(r1)
	  stfs      f1, 0xA4(r1)
	  stfs      f3, 0xA8(r1)
	  lfs       f1, 0xA0(r1)
	  lfs       f0, 0xA4(r1)
	  lfs       f2, 0xA8(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CB66C
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x3C(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x154
	  li        r31, 0x1

	.loc_0x154:
	  mr        r3, r31
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D92F0
 * Size:	000010
 */
f32 TAIAflickingMiurin::getFlickDirection(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x4254(r2)
	  lfs       f0, 0xA0(r4)
	  fadds     f1, f1, f0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9300
 * Size:	000020
 */
bool TAIAflickCheckMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x2A6E4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9320
 * Size:	000018
 */
int TAIAflickCheckMiurin::getDamageCountLimit(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x54(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9338
 * Size:	000018
 */
int TAIAstickingPikiMiurin::getPikiNum(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x50(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9350
 * Size:	000050
 */
bool TAIAcheckSatisfyMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  lwz       r3, 0x3120(r13)
	  bl        -0xC1FA4
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x38
	  li        r31, 0x1

	.loc_0x38:
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
 * Address:	801D93A0
 * Size:	000128
 */
void TAIAattackMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r3, 0x3120(r13)
	  bl        -0xC1FFC
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x8(r3)
	  lfs       f0, 0x9C(r31)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        -0xBB5D4
	  lfs       f2, 0xA0(r31)
	  lfs       f0, -0x4260(r2)
	  fsubs     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  fmr       f2, f1
	  bge-      .loc_0x60
	  fneg      f1, f2
	  b         .loc_0x64

	.loc_0x60:
	  fmr       f1, f2

	.loc_0x64:
	  lfs       f0, -0x4254(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x90
	  lfs       f0, -0x4260(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x88
	  lfs       f0, -0x41D8(r2)
	  fsubs     f2, f2, f0
	  b         .loc_0x90

	.loc_0x88:
	  lfs       f0, -0x41D8(r2)
	  fadds     f2, f2, f0

	.loc_0x90:
	  lfs       f0, -0x4260(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0xA4
	  fneg      f1, f2
	  b         .loc_0xA8

	.loc_0xA4:
	  fmr       f1, f2

	.loc_0xA8:
	  lfs       f0, -0x41D4(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xC0
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x8(r30)
	  b         .loc_0x104

	.loc_0xC0:
	  lfs       f0, -0x4234(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xD8
	  lwz       r0, 0xC(r30)
	  stw       r0, 0x8(r30)
	  b         .loc_0x104

	.loc_0xD8:
	  lfs       f0, -0x41D0(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xFC
	  lfs       f0, -0x41CC(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0xFC
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x8(r30)
	  b         .loc_0x104

	.loc_0xFC:
	  lwz       r0, 0x10(r30)
	  stw       r0, 0x8(r30)

	.loc_0x104:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x2C7A8
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
 * Address:	801D94C8
 * Size:	000900
 */
bool TAIAattackMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1B8(r1)
	  stfd      f31, 0x1B0(r1)
	  stfd      f30, 0x1A8(r1)
	  stmw      r22, 0x180(r1)
	  addi      r31, r4, 0
	  li        r30, 0
	  bl        -0x2C630
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8E0
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x464
	  lis       r4, 0x686E
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x6452
	  bl        -0x14FDFC
	  lfs       f0, -0x4260(r2)
	  mr.       r29, r3
	  stfs      f0, 0x13C(r1)
	  stfs      f0, 0x138(r1)
	  stfs      f0, 0x134(r1)
	  beq-      .loc_0x464
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x4(r29)
	  lfs       f2, 0xC(r29)
	  bl        -0x171634
	  lfs       f0, 0x4(r29)
	  addi      r5, r1, 0x134
	  li        r4, 0x43
	  stfs      f0, 0x134(r1)
	  li        r6, 0
	  li        r7, 0
	  stfs      f1, 0x138(r1)
	  lfs       f0, 0xC(r29)
	  stfs      f0, 0x13C(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x3CA2C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x4
	  li        r4, 0x4C
	  li        r6, 0
	  li        r7, 0
	  bl        -0x3CA44
	  lwz       r3, 0x3120(r13)
	  li        r0, 0
	  stw       r3, 0x144(r1)
	  addi      r3, r1, 0x140
	  stw       r0, 0x148(r1)
	  bl        -0x1497D8
	  lis       r4, 0x802B
	  lfs       f30, -0x4220(r2)
	  lis       r3, 0x802B
	  lfs       f31, -0x4260(r2)
	  subi      r28, r4, 0x3064
	  subi      r27, r3, 0x2EF0
	  addi      r26, r29, 0x4
	  addi      r25, r1, 0x7C
	  addi      r24, r1, 0x78
	  addi      r23, r1, 0x74
	  b         .loc_0x218

	.loc_0xFC:
	  lwz       r4, 0x140(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x124
	  lwz       r3, 0x144(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x138

	.loc_0x124:
	  lwz       r3, 0x144(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x138:
	  stfs      f31, 0xDC(r1)
	  addi      r7, r3, 0x94
	  addi      r22, r3, 0
	  stfs      f31, 0xD8(r1)
	  addi      r4, r23, 0
	  addi      r5, r24, 0
	  stfs      f31, 0xD4(r1)
	  addi      r6, r25, 0
	  addi      r3, r1, 0xD4
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x8(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x7C(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x74(r1)
	  bl        -0x17BFC8
	  lfs       f1, 0xD4(r1)
	  lfs       f0, 0xD8(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xDC(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CBA38
	  lfs       f0, 0x0(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x210
	  stw       r28, 0x14C(r1)
	  li        r0, 0x1
	  addi      r3, r22, 0
	  stw       r31, 0x150(r1)
	  addi      r4, r1, 0x14C
	  stw       r27, 0x14C(r1)
	  stb       r0, 0x154(r1)
	  stfs      f30, 0x158(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x36C74
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x210
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x33
	  addi      r3, r3, 0x70
	  bl        -0x155CD4

	.loc_0x210:
	  addi      r3, r1, 0x140
	  bl        -0x149A44

	.loc_0x218:
	  lwz       r3, 0x144(r1)
	  lwz       r4, 0x140(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x240
	  li        r0, 0x1
	  b         .loc_0x26C

	.loc_0x240:
	  lwz       r3, 0x144(r1)
	  lwz       r4, 0x140(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x268
	  li        r0, 0x1
	  b         .loc_0x26C

	.loc_0x268:
	  li        r0, 0

	.loc_0x26C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xFC
	  lwz       r3, 0x3068(r13)
	  li        r0, 0
	  stw       r3, 0x160(r1)
	  addi      r3, r1, 0x15C
	  stw       r0, 0x164(r1)
	  bl        -0x149994
	  lis       r4, 0x802B
	  lfs       f30, -0x4250(r2)
	  lis       r3, 0x802B
	  lfs       f31, -0x4260(r2)
	  subi      r28, r4, 0x3064
	  subi      r27, r3, 0x2EF0
	  addi      r26, r29, 0x4
	  addi      r23, r1, 0x70
	  addi      r24, r1, 0x6C
	  addi      r25, r1, 0x68
	  b         .loc_0x3D0

	.loc_0x2B8:
	  lwz       r4, 0x15C(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x2E4
	  lwz       r3, 0x160(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  b         .loc_0x2FC

	.loc_0x2E4:
	  lwz       r3, 0x160(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0x2FC:
	  lwz       r12, 0x0(r22)
	  mr        r3, r22
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C8
	  stfs      f31, 0xC4(r1)
	  mr        r4, r25
	  addi      r5, r24, 0
	  stfs      f31, 0xC0(r1)
	  addi      r6, r23, 0
	  addi      r3, r1, 0xBC
	  stfs      f31, 0xBC(r1)
	  lfs       f1, 0x9C(r22)
	  lfs       f0, 0x8(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  lfs       f1, 0x98(r22)
	  lfs       f0, 0x4(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x6C(r1)
	  lfs       f1, 0x94(r22)
	  lfs       f0, 0x0(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x68(r1)
	  bl        -0x17C1A0
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xC4(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CBC10
	  lfs       f0, 0x0(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3C8
	  stw       r28, 0x168(r1)
	  li        r0, 0x1
	  addi      r3, r22, 0
	  stw       r31, 0x16C(r1)
	  addi      r4, r1, 0x168
	  stw       r27, 0x168(r1)
	  stb       r0, 0x170(r1)
	  stfs      f30, 0x174(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x3C8:
	  addi      r3, r1, 0x15C
	  bl        -0x149BFC

	.loc_0x3D0:
	  lwz       r3, 0x160(r1)
	  lwz       r4, 0x15C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3F8
	  li        r0, 0x1
	  b         .loc_0x424

	.loc_0x3F8:
	  lwz       r3, 0x160(r1)
	  lwz       r4, 0x15C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x420
	  li        r0, 0x1
	  b         .loc_0x424

	.loc_0x420:
	  li        r0, 0

	.loc_0x424:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2B8
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x87
	  bl        -0x14F34C
	  addi      r22, r31, 0x94
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r22, 0
	  li        r4, 0x3
	  bl        -0xB593C
	  lwz       r3, 0x3178(r13)
	  addi      r6, r22, 0
	  li        r4, 0xA
	  li        r5, 0
	  bl        -0x5CB54

	.loc_0x464:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x89C
	  lis       r4, 0x686E
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x644C
	  bl        -0x150234
	  lfs       f0, -0x4260(r2)
	  mr.       r27, r3
	  stfs      f0, 0xF8(r1)
	  stfs      f0, 0xF4(r1)
	  stfs      f0, 0xF0(r1)
	  beq-      .loc_0x89C
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x4(r27)
	  lfs       f2, 0xC(r27)
	  bl        -0x171A6C
	  lfs       f0, 0x4(r27)
	  addi      r5, r1, 0xF0
	  li        r4, 0x43
	  stfs      f0, 0xF0(r1)
	  li        r6, 0
	  li        r7, 0
	  stfs      f1, 0xF4(r1)
	  lfs       f0, 0xC(r27)
	  stfs      f0, 0xF8(r1)
	  lwz       r3, 0x3180(r13)
	  bl        -0x3CE64
	  lwz       r3, 0x3180(r13)
	  addi      r5, r27, 0x4
	  li        r4, 0x4C
	  li        r6, 0
	  li        r7, 0
	  bl        -0x3CE7C
	  lwz       r3, 0x3120(r13)
	  li        r0, 0
	  stw       r3, 0x100(r1)
	  addi      r3, r1, 0xFC
	  stw       r0, 0x104(r1)
	  bl        -0x149C10
	  lis       r4, 0x802B
	  lfs       f30, -0x4220(r2)
	  lis       r3, 0x802B
	  lfs       f31, -0x4260(r2)
	  subi      r28, r4, 0x3064
	  subi      r29, r3, 0x2EF0
	  addi      r26, r27, 0x4
	  addi      r23, r1, 0x64
	  addi      r24, r1, 0x60
	  addi      r25, r1, 0x5C
	  b         .loc_0x650

	.loc_0x534:
	  lwz       r4, 0xFC(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x55C
	  lwz       r3, 0x100(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x570

	.loc_0x55C:
	  lwz       r3, 0x100(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x570:
	  stfs      f31, 0xA4(r1)
	  addi      r7, r3, 0x94
	  addi      r22, r3, 0
	  stfs      f31, 0xA0(r1)
	  addi      r4, r25, 0
	  addi      r5, r24, 0
	  stfs      f31, 0x9C(r1)
	  addi      r6, r23, 0
	  addi      r3, r1, 0x9C
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x8(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x5C(r1)
	  bl        -0x17C400
	  lfs       f1, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xA4(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CBE70
	  lfs       f0, 0x0(r27)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x648
	  stw       r28, 0x108(r1)
	  li        r0, 0x1
	  addi      r3, r22, 0
	  stw       r31, 0x10C(r1)
	  addi      r4, r1, 0x108
	  stw       r29, 0x108(r1)
	  stb       r0, 0x110(r1)
	  stfs      f30, 0x114(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x370AC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x648
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x33
	  addi      r3, r3, 0x70
	  bl        -0x15610C

	.loc_0x648:
	  addi      r3, r1, 0xFC
	  bl        -0x149E7C

	.loc_0x650:
	  lwz       r3, 0x100(r1)
	  lwz       r4, 0xFC(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x678
	  li        r0, 0x1
	  b         .loc_0x6A4

	.loc_0x678:
	  lwz       r3, 0x100(r1)
	  lwz       r4, 0xFC(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x6A0
	  li        r0, 0x1
	  b         .loc_0x6A4

	.loc_0x6A0:
	  li        r0, 0

	.loc_0x6A4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x534
	  lwz       r3, 0x3068(r13)
	  li        r0, 0
	  stw       r3, 0x11C(r1)
	  addi      r3, r1, 0x118
	  stw       r0, 0x120(r1)
	  bl        -0x149DCC
	  lis       r4, 0x802B
	  lfs       f31, -0x4250(r2)
	  lis       r3, 0x802B
	  lfs       f30, -0x4260(r2)
	  subi      r29, r4, 0x3064
	  subi      r28, r3, 0x2EF0
	  addi      r26, r27, 0x4
	  addi      r23, r1, 0x58
	  addi      r24, r1, 0x54
	  addi      r25, r1, 0x50
	  b         .loc_0x808

	.loc_0x6F0:
	  lwz       r4, 0x118(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x71C
	  lwz       r3, 0x11C(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3
	  b         .loc_0x734

	.loc_0x71C:
	  lwz       r3, 0x11C(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r22, r3

	.loc_0x734:
	  lwz       r12, 0x0(r22)
	  mr        r3, r22
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x800
	  stfs      f30, 0x8C(r1)
	  mr        r4, r25
	  addi      r5, r24, 0
	  stfs      f30, 0x88(r1)
	  addi      r6, r23, 0
	  addi      r3, r1, 0x84
	  stfs      f30, 0x84(r1)
	  lfs       f1, 0x9C(r22)
	  lfs       f0, 0x8(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r1)
	  lfs       f1, 0x98(r22)
	  lfs       f0, 0x4(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x54(r1)
	  lfs       f1, 0x94(r22)
	  lfs       f0, 0x0(r26)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x50(r1)
	  bl        -0x17C5D8
	  lfs       f1, 0x84(r1)
	  lfs       f0, 0x88(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1CC048
	  lfs       f0, 0x0(r27)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x800
	  stw       r29, 0x124(r1)
	  li        r0, 0x1
	  addi      r3, r22, 0
	  stw       r31, 0x128(r1)
	  addi      r4, r1, 0x124
	  stw       r28, 0x124(r1)
	  stb       r0, 0x12C(r1)
	  stfs      f31, 0x130(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x800:
	  addi      r3, r1, 0x118
	  bl        -0x14A034

	.loc_0x808:
	  lwz       r3, 0x11C(r1)
	  lwz       r4, 0x118(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x830
	  li        r0, 0x1
	  b         .loc_0x85C

	.loc_0x830:
	  lwz       r3, 0x11C(r1)
	  lwz       r4, 0x118(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x858
	  li        r0, 0x1
	  b         .loc_0x85C

	.loc_0x858:
	  li        r0, 0

	.loc_0x85C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x6F0
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x87
	  bl        -0x14F784
	  addi      r22, r31, 0x94
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r22, 0
	  li        r4, 0x3
	  bl        -0xB5D74
	  lwz       r3, 0x3178(r13)
	  addi      r6, r22, 0
	  li        r4, 0xA
	  li        r5, 0
	  bl        -0x5CF8C

	.loc_0x89C:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x5
	  bne-      .loc_0x8D0
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x8B8
	  lwz       r5, 0x2C0(r31)

	.loc_0x8B8:
	  addi      r3, r1, 0x178
	  li        r4, -0x1
	  bl        -0xBADFC
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0xBAB64

	.loc_0x8D0:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x8E0
	  li        r30, 0x1

	.loc_0x8E0:
	  mr        r3, r30
	  lmw       r22, 0x180(r1)
	  lwz       r0, 0x1BC(r1)
	  lfd       f31, 0x1B0(r1)
	  lfd       f30, 0x1A8(r1)
	  addi      r1, r1, 0x1B8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9DC8
 * Size:	00005C
 */
bool TAIAattackPosture::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  bl        -0x2CF28
	  rlwinm.   r0,r3,0,24,31
	  addi      r31, r3, 0
	  beq-      .loc_0x40
	  mr        r3, r30
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  mr        r3, r31
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
 * Address:	801D9E24
 * Size:	00005C
 */
bool TAIAattackableTargetMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bl        -0x2C04C
	  rlwinm.   r0,r3,0,24,31
	  addi      r31, r3, 0
	  beq-      .loc_0x44
	  lwz       r3, 0x3120(r13)
	  bl        -0xC2A84
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x44
	  li        r31, 0

	.loc_0x44:
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
 * Address:	801D9E80
 * Size:	00004C
 */
void TAIAapproachTargetPriorityFaceDirMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  bl        -0x30590
	  mr        r3, r31
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x425C(r2)
	  stfs      f0, 0x3B4(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9ECC
 * Size:	000018
 */
f32 TAIAapproachTargetPriorityFaceDirMiurin::getVelocity(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9EE4
 * Size:	00004C
 */
void TAIAturnFocusCreatureMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  bl        -0x2FAE0
	  mr        r3, r31
	  lwz       r4, -0x9BC(r13)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x425C(r2)
	  stfs      f0, 0x3B4(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9F30
 * Size:	000018
 */
f32 TAIAturnFocusCreatureMiurin::getTurnVelocity(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r4)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xD4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9F48
 * Size:	000034
 */
void TAIAdyingMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        -0x31A30
	  lfs       f0, -0x4260(r2)
	  stfs      f0, 0x478(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801D9F7C
 * Size:	0000F0
 */
bool TAIAdyingMiurin::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  mr        r30, r3
	  lwz       r5, 0x2DEC(r13)
	  lfs       f1, 0x478(r4)
	  lfs       f0, 0x28C(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x478(r4)
	  lfs       f1, 0x478(r4)
	  lfs       f0, -0x41F8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x68
	  cmplwi    r31, 0
	  addi      r5, r31, 0
	  beq-      .loc_0x50
	  lwz       r5, 0x2C0(r31)

	.loc_0x50:
	  addi      r3, r1, 0x28
	  li        r4, -0x1
	  bl        -0xBB048
	  mr        r4, r3
	  lwz       r3, 0x2CC(r31)
	  bl        -0xBADB0

	.loc_0x68:
	  lwz       r0, 0x3A8(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xCC
	  lfs       f0, 0x94(r31)
	  li        r4, 0x1
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x9C(r31)
	  stfs      f0, 0x38(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x30(r1)
	  lfs       f2, 0x38(r1)
	  bl        -0x172114
	  stfs      f1, 0x34(r1)
	  addi      r5, r1, 0x30
	  li        r4, 0x43
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  li        r7, 0
	  bl        -0x3D4FC
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x7
	  bl        -0x14FA90

	.loc_0xCC:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x31A2C
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
 * Address:	801DA06C
 * Size:	000014
 */
void TAIAinitMiurin::start(Teki&)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x4260(r2)
	  stfs      f0, 0x340(r4)
	  lfs       f0, -0x424C(r2)
	  stfs      f0, 0x270(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DA080
 * Size:	000008
 */
bool TAIAinitMiurin::act(Teki&) { return true; }
