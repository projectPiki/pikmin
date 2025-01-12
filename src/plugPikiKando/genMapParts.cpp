#include "Generator.h"
#include "MapMgr.h"

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
 * Address:	8011785C
 * Size:	0001C0
 */
static GenObjectMapParts* makeObjectMapParts()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x90
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  bl        -0xD0870
	  mr.       r31, r3
	  beq-      .loc_0x1A4
	  lis       r4, 0x802C
	  lis       r3, 0x802C
	  addi      r5, r4, 0x309C
	  lis       r4, 0x6D70
	  addi      r6, r3, 0x30A8
	  addi      r3, r31, 0
	  addi      r4, r4, 0x6172
	  bl        -0x3CBE8
	  lis       r3, 0x802C
	  subi      r0, r3, 0x5490
	  lis       r3, 0x802C
	  stw       r0, 0x4(r31)
	  addi      r0, r3, 0x3138
	  stw       r0, 0x4(r31)
	  addi      r5, r1, 0x2C
	  addi      r4, r31, 0
	  lwz       r0, -0x22B0(r13)
	  addi      r3, r31, 0x18
	  stw       r0, 0x34(r1)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x2C(r1)
	  bl        -0xB8E54
	  lis       r3, 0x802A
	  addi      r30, r3, 0x60C4
	  stw       r30, 0x20(r31)
	  li        r0, 0x1
	  addi      r5, r1, 0x28
	  stw       r0, 0x24(r31)
	  mr        r4, r31
	  addi      r3, r31, 0x28
	  lwz       r0, -0x22AC(r13)
	  stw       r0, 0x3C(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x28(r1)
	  bl        -0xB8E88
	  stw       r30, 0x30(r31)
	  li        r0, 0x64
	  addi      r5, r1, 0x24
	  stw       r0, 0x34(r31)
	  mr        r4, r31
	  addi      r3, r31, 0x38
	  lwz       r0, -0x22A8(r13)
	  stw       r0, 0x44(r1)
	  lwz       r0, 0x44(r1)
	  stw       r0, 0x24(r1)
	  bl        -0xB8EB4
	  lis       r3, 0x802A
	  addi      r30, r3, 0x6098
	  stw       r30, 0x40(r31)
	  addi      r5, r1, 0x20
	  addi      r4, r31, 0
	  lfs       f0, -0x6058(r2)
	  addi      r3, r31, 0x48
	  stfs      f0, 0x44(r31)
	  lwz       r0, -0x22A4(r13)
	  stw       r0, 0x4C(r1)
	  lwz       r0, 0x4C(r1)
	  stw       r0, 0x20(r1)
	  bl        -0xB8EE8
	  stw       r30, 0x50(r31)
	  addi      r5, r1, 0x1C
	  addi      r4, r31, 0
	  lfs       f0, -0x6054(r2)
	  addi      r3, r31, 0x58
	  stfs      f0, 0x54(r31)
	  lwz       r0, -0x22A0(r13)
	  stw       r0, 0x54(r1)
	  lwz       r0, 0x54(r1)
	  stw       r0, 0x1C(r1)
	  bl        -0xB8F14
	  stw       r30, 0x60(r31)
	  li        r0, 0
	  lfs       f0, -0x6050(r2)
	  stfs      f0, 0x64(r31)
	  lfs       f0, -0x6058(r2)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x78(r31)
	  stfs      f0, 0x8C(r31)
	  stfs      f0, 0x88(r31)
	  stfs      f0, 0x84(r31)
	  stw       r0, 0x6C(r31)
	  stw       r0, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lfs       f0, -0x22F8(r13)
	  stfs      f0, 0x78(r31)
	  lfs       f0, -0x22F4(r13)
	  stfs      f0, 0x7C(r31)
	  lfs       f0, -0x22F0(r13)
	  stfs      f0, 0x80(r31)
	  lfs       f0, -0x22EC(r13)
	  stfs      f0, 0x84(r31)
	  lfs       f0, -0x22E8(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, -0x22E4(r13)
	  stfs      f0, 0x8C(r31)

	.loc_0x1A4:
	  mr        r3, r31
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80117A1C
 * Size:	000090
 */
void GenObjectMapParts::initialise(MapMgr*)
{
	/*
	.loc_0x0:
	  stw       r3, 0x3128(r13)
	  lwz       r7, 0x3074(r13)
	  lwz       r5, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  cmpw      r5, r0
	  bgelr-
	  lis       r4, 0x6D70
	  lwz       r3, 0x8(r7)
	  addi      r4, r4, 0x6172
	  rlwinm    r0,r5,4,0,27
	  stwx      r4, r3, r0
	  lis       r6, 0x8011
	  lis       r4, 0x802C
	  lwz       r0, 0x0(r7)
	  lis       r3, 0x7630
	  lwz       r5, 0x8(r7)
	  addi      r6, r6, 0x785C
	  rlwinm    r0,r0,4,0,27
	  add       r5, r5, r0
	  stw       r6, 0x4(r5)
	  addi      r5, r4, 0x30BC
	  addi      r4, r3, 0x2E30
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r5, 0x8(r3)
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x0(r7)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r7)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80117AAC
 * Size:	000118
 */
void GenObjectMapParts::doRead(RandomAccessStream&)
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
	  addi      r3, r31, 0
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x6C(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x70(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x74(r30)
	  lwz       r0, 0x74(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x100
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x78(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x7C(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x80(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x84(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x88(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x8C(r30)

	.loc_0x100:
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
 * Address:	80117BC4
 * Size:	000664
 */
void GenObjectMapParts::render(Graphics&, Generator*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2F0(r1)
	  stmw      r27, 0x2DC(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  mr        r31, r5
	  lfs       f0, -0x6058(r2)
	  stfs      f0, 0x250(r1)
	  stfs      f0, 0x24C(r1)
	  stfs      f0, 0x248(r1)
	  lfs       f0, -0x604C(r2)
	  stfs      f0, 0x248(r1)
	  stfs      f0, 0x24C(r1)
	  stfs      f0, 0x250(r1)
	  lwz       r0, 0x70(r3)
	  lwz       r3, -0x22E0(r13)
	  cmpw      r0, r3
	  bge-      .loc_0x60
	  lwz       r3, 0x3128(r13)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r28, 0x74(r3)
	  b         .loc_0x78

	.loc_0x60:
	  sub       r3, r0, r3
	  bl        0x880
	  mr        r4, r3
	  lwz       r3, 0x3128(r13)
	  bl        -0xAE810
	  mr        r28, r3

	.loc_0x78:
	  lfs       f1, 0xA0(r31)
	  addi      r6, r1, 0x98
	  lfs       f0, 0xAC(r31)
	  addi      r5, r1, 0x94
	  addi      r4, r1, 0x90
	  fadds     f0, f1, f0
	  addi      r3, r1, 0x184
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x9C(r31)
	  lfs       f0, 0xA8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x94(r1)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0xA4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x90(r1)
	  bl        -0xE0B60
	  lfs       f1, 0x78(r29)
	  lfs       f0, 0x184(r1)
	  lfs       f3, 0x7C(r29)
	  lfs       f2, 0x188(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0x80(r29)
	  lfs       f1, 0x18C(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x1F8(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x1FC(r1)
	  stfs      f0, 0x200(r1)
	  lbz       r0, 0x312D(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x104
	  li        r0, 0x1
	  stb       r0, 0x312C(r13)
	  stb       r0, 0x312D(r13)

	.loc_0x104:
	  lbz       r0, 0x312C(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x188
	  lfs       f1, 0x98(r31)
	  li        r0, 0
	  lfs       f0, 0xA4(r31)
	  lfs       f4, 0xA0(r31)
	  lfs       f3, 0xAC(r31)
	  fadds     f0, f1, f0
	  lfs       f2, 0x9C(r31)
	  lfs       f1, 0xA8(r31)
	  fadds     f3, f4, f3
	  stfs      f0, 0xB4(r1)
	  fadds     f1, f2, f1
	  lfs       f0, 0xB4(r1)
	  stfs      f0, 0x16C(r1)
	  stfs      f1, 0x170(r1)
	  stfs      f3, 0x174(r1)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0xA4(r31)
	  lfs       f4, 0xA0(r31)
	  lfs       f3, 0xAC(r31)
	  fadds     f0, f1, f0
	  lfs       f2, 0x9C(r31)
	  lfs       f1, 0xA8(r31)
	  fadds     f3, f4, f3
	  stfs      f0, 0xB0(r1)
	  fadds     f1, f2, f1
	  lfs       f0, 0xB0(r1)
	  stb       r0, 0x312C(r13)
	  stfs      f0, 0x160(r1)
	  stfs      f1, 0x164(r1)
	  stfs      f3, 0x168(r1)

	.loc_0x188:
	  lfs       f1, -0x2290(r13)
	  addi      r5, r1, 0x148
	  lfs       f0, -0x229C(r13)
	  addi      r4, r1, 0x154
	  stfs      f1, 0x148(r1)
	  lfs       f1, -0x228C(r13)
	  addi      r3, r1, 0x1B8
	  stfs      f0, 0x154(r1)
	  addi      r6, r1, 0x1F8
	  lfs       f0, -0x2298(r13)
	  stfs      f1, 0x14C(r1)
	  lfs       f1, -0x2288(r13)
	  stfs      f0, 0x158(r1)
	  lfs       f0, -0x2294(r13)
	  stfs      f1, 0x150(r1)
	  stfs      f0, 0x15C(r1)
	  bl        -0xD9C98
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x1B8
	  addi      r5, r1, 0x204
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x204
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0x1
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x2E4(r30)
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  li        r6, 0
	  bl        -0xE7988
	  lfs       f1, 0xA0(r31)
	  addi      r6, r1, 0xA4
	  lfs       f0, 0xAC(r31)
	  addi      r5, r1, 0xA0
	  addi      r4, r1, 0x9C
	  fadds     f0, f1, f0
	  addi      r3, r1, 0x13C
	  stfs      f0, 0xA4(r1)
	  lfs       f1, 0x9C(r31)
	  lfs       f0, 0xA8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0xA4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  bl        -0xE0D1C
	  lfs       f1, 0x84(r29)
	  addi      r5, r1, 0x124
	  lfs       f0, 0x13C(r1)
	  addi      r4, r1, 0x130
	  lfs       f3, 0x88(r29)
	  lfs       f2, 0x140(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8C(r29)
	  addi      r3, r1, 0x1B8
	  lfs       f1, 0x144(r1)
	  stfs      f0, 0x1F8(r1)
	  fadds     f2, f3, f2
	  addi      r6, r1, 0x1F8
	  fadds     f0, f4, f1
	  stfs      f2, 0x1FC(r1)
	  stfs      f0, 0x200(r1)
	  lfs       f1, -0x2278(r13)
	  lfs       f0, -0x2284(r13)
	  stfs      f1, 0x124(r1)
	  lfs       f1, -0x2274(r13)
	  stfs      f0, 0x130(r1)
	  lfs       f0, -0x2280(r13)
	  stfs      f1, 0x128(r1)
	  lfs       f1, -0x2270(r13)
	  stfs      f0, 0x134(r1)
	  lfs       f0, -0x227C(r13)
	  stfs      f1, 0x12C(r1)
	  stfs      f0, 0x138(r1)
	  bl        -0xD9DB8
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x1B8
	  addi      r5, r1, 0x204
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x204
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x2E4(r30)
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  li        r6, 0
	  bl        -0xE7A8C
	  lwz       r0, 0x74(r29)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x650
	  lfs       f1, 0xA0(r31)
	  addi      r6, r1, 0x8C
	  lfs       f0, 0xAC(r31)
	  addi      r5, r1, 0x88
	  addi      r4, r1, 0x84
	  fadds     f0, f1, f0
	  addi      r3, r1, 0x10C
	  stfs      f0, 0x8C(r1)
	  lfs       f1, 0x9C(r31)
	  lfs       f0, 0xA8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x88(r1)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0xA4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x84(r1)
	  bl        -0xE0E2C
	  lfs       f1, 0x78(r29)
	  addi      r5, r1, 0x100
	  lfs       f0, 0x10C(r1)
	  addi      r3, r1, 0x294
	  lfs       f3, 0x7C(r29)
	  lfs       f2, 0x110(r1)
	  fadds     f1, f1, f0
	  lfs       f5, 0x80(r29)
	  addi      r4, r1, 0x248
	  lfs       f0, -0x226C(r13)
	  stfs      f1, 0x1AC(r1)
	  fadds     f3, f3, f2
	  lfs       f4, 0x114(r1)
	  stfs      f0, 0x100(r1)
	  addi      r6, r1, 0x1AC
	  lfs       f1, -0x2268(r13)
	  fadds     f2, f5, f4
	  stfs      f3, 0x1B0(r1)
	  lfs       f0, -0x2264(r13)
	  stfs      f1, 0x104(r1)
	  stfs      f2, 0x1B4(r1)
	  stfs      f0, 0x108(r1)
	  bl        -0xD9EB0
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x294
	  addi      r5, r1, 0x254
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x254
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  li        r28, 0xFF
	  stb       r28, 0x1A8(r1)
	  li        r27, 0
	  addi      r4, r30, 0
	  stb       r27, 0x1A9(r1)
	  li        r6, 0
	  stb       r27, 0x1AA(r1)
	  stb       r28, 0x1AB(r1)
	  lwz       r3, 0x2F54(r13)
	  lwz       r0, 0x1A8(r1)
	  lwz       r3, 0x44(r3)
	  stw       r0, 0x2C(r3)
	  lwz       r3, 0x2F54(r13)
	  lwz       r5, 0x2E4(r30)
	  bl        -0xE7BAC
	  lfs       f1, 0xA0(r31)
	  addi      r6, r1, 0x80
	  lfs       f0, 0xAC(r31)
	  addi      r5, r1, 0x7C
	  addi      r4, r1, 0x78
	  fadds     f0, f1, f0
	  addi      r3, r1, 0xE8
	  stfs      f0, 0x80(r1)
	  lfs       f1, 0x9C(r31)
	  lfs       f0, 0xA8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x7C(r1)
	  lfs       f1, 0x98(r31)
	  lfs       f0, 0xA4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x78(r1)
	  bl        -0xE0F40
	  lfs       f1, 0x84(r29)
	  addi      r5, r1, 0xDC
	  lfs       f0, 0xE8(r1)
	  addi      r3, r1, 0x294
	  lfs       f3, 0x88(r29)
	  lfs       f2, 0xEC(r1)
	  fadds     f1, f1, f0
	  lfs       f5, 0x8C(r29)
	  addi      r4, r1, 0x248
	  lfs       f0, -0x2260(r13)
	  stfs      f1, 0x19C(r1)
	  fadds     f3, f3, f2
	  lfs       f4, 0xF0(r1)
	  stfs      f0, 0xDC(r1)
	  addi      r6, r1, 0x19C
	  lfs       f1, -0x225C(r13)
	  fadds     f2, f5, f4
	  stfs      f3, 0x1A0(r1)
	  lfs       f0, -0x2258(r13)
	  stfs      f1, 0xE0(r1)
	  stfs      f2, 0x1A4(r1)
	  stfs      f0, 0xE4(r1)
	  bl        -0xD9FC4
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x294
	  addi      r5, r1, 0x254
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x254
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  stb       r27, 0x1A8(r1)
	  addi      r4, r30, 0
	  li        r6, 0
	  stb       r27, 0x1A9(r1)
	  stb       r28, 0x1AA(r1)
	  stb       r28, 0x1AB(r1)
	  lwz       r3, 0x2F54(r13)
	  lwz       r0, 0x1A8(r1)
	  lwz       r3, 0x44(r3)
	  stw       r0, 0x2C(r3)
	  lwz       r3, 0x2F54(r13)
	  lwz       r5, 0x2E4(r30)
	  bl        -0xE7CB8
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  lwz       r4, 0x2E4(r30)
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  mr        r27, r0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0xD8(r1)
	  addi      r4, r1, 0xD8
	  addi      r3, r30, 0
	  stb       r28, 0xD9(r1)
	  li        r5, 0x1
	  stb       r28, 0xDA(r1)
	  stb       r28, 0xDB(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0xD4(r1)
	  addi      r4, r1, 0xD4
	  addi      r3, r30, 0
	  stb       r28, 0xD5(r1)
	  stb       r28, 0xD6(r1)
	  stb       r28, 0xD7(r1)
	  lwz       r12, 0x3B4(r30)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x1AC
	  addi      r5, r1, 0x19C
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x650:
	  lmw       r27, 0x2DC(r1)
	  lwz       r0, 0x2F4(r1)
	  addi      r1, r1, 0x2F0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80118228
 * Size:	00027C
 */
Creature* GenObjectMapParts::birth(BirthInfo&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  li        r31, 0
	  stw       r30, 0x68(r1)
	  stw       r29, 0x64(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x60(r1)
	  mr        r28, r3
	  lwz       r3, -0x22E0(r13)
	  lwz       r0, 0x70(r28)
	  cmpw      r0, r3
	  bge-      .loc_0x4C
	  lwz       r3, 0x3128(r13)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r30, 0x74(r3)
	  b         .loc_0x78

	.loc_0x4C:
	  sub       r3, r0, r3
	  bl        0x230
	  mr        r4, r3
	  lwz       r3, 0x3128(r13)
	  bl        -0xAEE60
	  mr.       r30, r3
	  bne-      .loc_0x78
	  lwz       r3, -0x22E0(r13)
	  lwz       r0, 0x70(r28)
	  sub       r3, r0, r3
	  bl        0x20C

	.loc_0x78:
	  lwz       r0, 0x6C(r28)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xF8
	  bge-      .loc_0x94
	  cmpwi     r0, 0
	  bge-      .loc_0xA0
	  b         .loc_0x150

	.loc_0x94:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x150
	  b         .loc_0x148

	.loc_0xA0:
	  li        r3, 0x184
	  bl        -0xD12C8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0xD4
	  lfs       f3, 0x64(r28)
	  addi      r4, r30, 0
	  lfs       f2, 0x54(r28)
	  li        r7, 0
	  lfs       f1, 0x44(r28)
	  lwz       r6, 0x34(r28)
	  lwz       r5, 0x24(r28)
	  bl        0x39C

	.loc_0xD4:
	  lwz       r3, 0x0(r29)
	  lwz       r0, 0x4(r29)
	  stw       r3, 0x150(r31)
	  stw       r0, 0x154(r31)
	  lwz       r0, 0x8(r29)
	  stw       r0, 0x158(r31)
	  lfs       f0, 0x10(r29)
	  stfs      f0, 0x15C(r31)
	  b         .loc_0x150

	.loc_0xF8:
	  li        r3, 0x150
	  bl        -0xD1320
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x114
	  mr        r4, r30
	  bl        0x1E4

	.loc_0x114:
	  lwz       r3, 0x0(r29)
	  lwz       r0, 0x4(r29)
	  stw       r3, 0x134(r31)
	  stw       r0, 0x138(r31)
	  lwz       r0, 0x8(r29)
	  stw       r0, 0x13C(r31)
	  lwz       r3, 0xC(r29)
	  lwz       r0, 0x10(r29)
	  stw       r3, 0x128(r31)
	  stw       r0, 0x12C(r31)
	  lwz       r0, 0x14(r29)
	  stw       r0, 0x130(r31)
	  b         .loc_0x150

	.loc_0x148:
	  li        r3, 0
	  b         .loc_0x25C

	.loc_0x150:
	  cmplwi    r31, 0
	  beq-      .loc_0x258
	  lwz       r0, 0x74(r28)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x234
	  li        r3, 0x18
	  bl        -0xD138C
	  cmplwi    r3, 0
	  beq-      .loc_0x190
	  lfs       f0, -0x6058(r2)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0xC(r3)

	.loc_0x190:
	  lfs       f1, 0x78(r28)
	  lfs       f0, 0x0(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x34(r1)
	  stfs      f0, 0x4C(r1)
	  lfs       f1, 0x7C(r28)
	  lfs       f0, 0x4(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x50(r1)
	  lfs       f1, 0x80(r28)
	  lfs       f0, 0x8(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x54(r1)
	  lwz       r4, 0x4C(r1)
	  lwz       r0, 0x50(r1)
	  stw       r4, 0x0(r3)
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x54(r1)
	  stw       r0, 0x8(r3)
	  lfs       f1, 0x84(r28)
	  lfs       f0, 0x0(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x88(r28)
	  lfs       f0, 0x4(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x44(r1)
	  lfs       f1, 0x8C(r28)
	  lfs       f0, 0x8(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x48(r1)
	  lwz       r4, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stw       r4, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0x48(r1)
	  stw       r0, 0x14(r3)
	  stw       r3, 0x140(r31)

	.loc_0x234:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3128(r13)
	  mr        r4, r31
	  lwz       r3, 0x88(r3)
	  bl        -0xD7EA4

	.loc_0x258:
	  li        r3, 0

	.loc_0x25C:
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  lwz       r28, 0x60(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801184A4
 * Size:	000004
 */
void MapParts::init()
{
}
