#include "CardSelect.h"

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
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8005503C
 * Size:	00023C
 */
CardSelectSection::CardSelectSection()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r26, 0x10(r1)
	  addi      r31, r4, 0x7660
	  addi      r28, r3, 0
	  subi      r4, r13, 0x7350
	  bl        -0x200A4
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r28)
	  addi      r3, r28, 0
	  subi      r4, r13, 0x7350
	  bl        -0x14938
	  lis       r3, 0x802A
	  addi      r0, r3, 0x642C
	  lis       r3, 0x802A
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x77B4
	  stw       r0, 0x0(r28)
	  addi      r3, r28, 0
	  addi      r4, r31, 0x1C
	  bl        -0x1495C
	  lwz       r4, 0x2DEC(r13)
	  li        r0, 0x1
	  lis       r3, 0x803A
	  stw       r0, 0x14(r4)
	  subi      r27, r3, 0x24E0
	  li        r29, 0
	  stw       r29, 0xA8(r27)
	  lwz       r3, 0x2F6C(r13)
	  bl        0x2A4F0
	  lwz       r3, 0x3098(r13)
	  bl        0x89DEC
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  bl        0x70604
	  lwz       r26, 0x10(r27)
	  b         .loc_0xB0

	.loc_0xA0:
	  stw       r29, 0x20(r26)
	  addi      r3, r26, 0x2C
	  bl        0x71330
	  lwz       r26, 0xC(r26)

	.loc_0xB0:
	  cmplwi    r26, 0
	  bne+      .loc_0xA0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0
	  stb       r0, 0xB4(r3)
	  addi      r29, r3, 0x2B4
	  stb       r0, 0xB2(r3)
	  lwz       r0, 0x2B4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xE8
	  li        r3, 0x2
	  li        r4, 0
	  bl        -0x3B8A0

	.loc_0xE8:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0
	  li        r5, 0x1
	  lwz       r12, 0x1A0(r3)
	  li        r6, 0x3C
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x38
	  bl        -0xE144
	  mr.       r30, r3
	  beq-      .loc_0x204
	  addi      r3, r30, 0
	  subi      r4, r13, 0x7350
	  bl        -0x201A4
	  lis       r3, 0x8023
	  subi      r27, r3, 0x71E0
	  stw       r27, 0x0(r30)
	  addi      r3, r30, 0
	  subi      r4, r13, 0x7350
	  bl        -0x14A38
	  lis       r3, 0x802A
	  addi      r0, r3, 0x7730
	  stw       r0, 0x0(r30)
	  addi      r3, r31, 0x30
	  li        r0, 0x5
	  stw       r3, 0x4(r30)
	  li        r3, 0x50
	  stw       r0, 0x34(r30)
	  bl        -0xE194
	  addi      r26, r3, 0
	  mr.       r0, r26
	  beq-      .loc_0x1A0
	  addi      r3, r26, 0
	  addi      r4, r31, 0x44
	  bl        -0x201F8
	  stw       r27, 0x0(r26)
	  addi      r3, r26, 0
	  addi      r4, r31, 0x44
	  bl        -0x14A84
	  lis       r3, 0x8023
	  subi      r0, r3, 0x714C
	  stw       r0, 0x0(r26)
	  addi      r3, r26, 0
	  li        r4, 0x1
	  bl        -0x14828

	.loc_0x1A0:
	  stw       r26, 0x30(r30)
	  li        r0, 0
	  li        r3, 0x18
	  stw       r0, 0x20(r30)
	  stw       r0, 0x2E48(r13)
	  bl        -0xE1EC
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x1C8
	  bl        0x13E394

	.loc_0x1C8:
	  stw       r26, 0x2E48(r13)
	  lwz       r0, 0x0(r29)
	  lwz       r3, 0x2E48(r13)
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  subfe     r0, r0, r4
	  rlwinm    r4,r0,0,24,31
	  bl        0x13E484
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0
	  lfs       f0, -0x7AA8(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x7AA4(r2)
	  stfs      f0, 0xC(r3)
	  stw       r0, 0x24(r30)

	.loc_0x204:
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        -0x14C70
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lmw       r26, 0x10(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80055278
 * Size:	000298
 */
void CardSelectSetupSection::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  stw       r29, 0x24(r1)
	  lwz       r3, 0x30(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2E48(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x64
	  lwz       r0, 0x20(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x64
	  li        r0, 0x1
	  stw       r0, 0x20(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x7AA0(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x7AA4(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x64:
	  lwz       r0, 0x2E48(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xB0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x2B4(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0xB0
	  lwz       r3, 0x34(r30)
	  cmpwi     r3, 0
	  beq-      .loc_0xB0
	  subi      r0, r3, 0x1
	  stw       r0, 0x34(r30)
	  lwz       r0, 0x34(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0xB0
	  li        r3, 0x2
	  li        r4, 0
	  bl        -0x3BAA4

	.loc_0xB0:
	  lwz       r0, 0x20(r30)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x27C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7AA0(r2)
	  lfs       f0, 0x4(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x27C
	  li        r29, -0x1
	  stw       r29, 0x20(r30)
	  lwz       r0, 0x24(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xF8
	  lis       r3, 0x803A
	  rlwinm    r0,r0,16,16,31
	  subi      r3, r3, 0x2848
	  stw       r0, 0x1F4(r3)
	  b         .loc_0x264

	.loc_0xF8:
	  lis       r3, 0x803A
	  subi      r30, r3, 0x2848
	  addi      r4, r30, 0x2B4
	  lwz       r0, 0x2B4(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x208
	  li        r31, 0x1
	  stw       r31, 0x2FC(r30)
	  lbz       r0, 0xB2(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x178
	  addi      r3, r30, 0x24
	  bl        0x1F0C8
	  addi      r4, r30, 0x1C4
	  lbz       r0, 0x1C4(r30)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x164
	  stb       r31, 0x0(r4)
	  li        r3, 0
	  li        r0, 0x2
	  stw       r29, 0x1C0(r30)
	  stw       r29, 0x1BC(r30)
	  stw       r29, 0x1B8(r30)
	  stb       r31, 0x1C5(r30)
	  stb       r3, 0x1C6(r30)
	  stw       r31, 0x1C8(r30)
	  stb       r0, 0x0(r4)

	.loc_0x164:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0x6
	  stw       r0, 0x1F4(r3)
	  b         .loc_0x1A0

	.loc_0x178:
	  stb       r31, 0x1C4(r30)
	  li        r3, 0
	  li        r0, 0x5
	  stw       r29, 0x1C0(r30)
	  stw       r29, 0x1BC(r30)
	  stw       r29, 0x1B8(r30)
	  stb       r31, 0x1C5(r30)
	  stb       r3, 0x1C6(r30)
	  stw       r31, 0x1C8(r30)
	  stw       r0, 0x1F4(r30)

	.loc_0x1A0:
	  lwz       r3, 0x2F6C(r13)
	  bl        0x2B058
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x250
	  lis       r3, 0x803A
	  crclr     6, 0x6
	  subi      r31, r3, 0x24E0
	  lwz       r29, 0x10(r31)
	  addi      r3, r31, 0x130
	  subi      r4, r13, 0x7318
	  stw       r29, 0xA8(r31)
	  lwz       r5, 0x18(r29)
	  bl        0x1C1150
	  lwz       r5, 0x18(r29)
	  addi      r3, r31, 0x1B0
	  crclr     6, 0x6
	  subi      r4, r13, 0x7318
	  bl        0x1C113C
	  lis       r3, 0x803A
	  lfs       f1, -0x7A9C(r2)
	  subi      r31, r3, 0x2848
	  addi      r3, r31, 0x2D8
	  bl        -0x3C54
	  li        r0, 0x5
	  stw       r0, 0x1F4(r31)
	  b         .loc_0x250

	.loc_0x208:
	  li        r3, 0x1
	  stb       r3, 0x1C4(r30)
	  li        r0, 0
	  stw       r29, 0x1C0(r30)
	  stw       r29, 0x1BC(r30)
	  stw       r29, 0x1B8(r30)
	  stb       r3, 0x1C5(r30)
	  stb       r0, 0x1C6(r30)
	  stw       r3, 0x1C8(r30)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x240
	  lwz       r3, 0x2F6C(r13)
	  bl        0x2A6EC

	.loc_0x240:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0x6
	  stw       r0, 0x1F4(r3)

	.loc_0x250:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, -0x1
	  stw       r0, 0x1CC(r3)
	  stw       r0, 0x1D0(r3)

	.loc_0x264:
	  li        r3, 0xD
	  li        r4, 0
	  bl        -0x3B804
	  lwz       r3, 0x2DEC(r13)
	  li        r0, 0x1
	  stb       r0, 0x0(r3)

	.loc_0x27C:
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
 * Address:	80055510
 * Size:	0001F8
 */
void CardSelectSetupSection::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stw       r31, 0xBC(r1)
	  mr        r31, r4
	  stw       r30, 0xB8(r1)
	  mr        r30, r3
	  mr        r3, r31
	  stw       r29, 0xB4(r1)
	  li        r29, 0
	  lwz       r5, 0x310(r4)
	  lwz       r0, 0x30C(r4)
	  addi      r4, r1, 0x34
	  stw       r29, 0x34(r1)
	  stw       r29, 0x38(r1)
	  stw       r0, 0x3C(r1)
	  stw       r5, 0x40(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r31)
	  addi      r4, r1, 0x24
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  stw       r29, 0x24(r1)
	  stw       r29, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  stw       r5, 0x30(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  stb       r29, 0x20(r1)
	  addi      r4, r1, 0x20
	  addi      r3, r31, 0
	  stb       r29, 0x21(r1)
	  stb       r29, 0x22(r1)
	  stb       r29, 0x23(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xB4(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0x310(r31)
	  addi      r5, r1, 0x10
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  addi      r4, r1, 0x6C
	  stw       r29, 0x10(r1)
	  stw       r29, 0x14(r1)
	  stw       r0, 0x18(r1)
	  stw       r6, 0x1C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E48(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x1DC
	  stw       r29, 0x4C(r1)
	  addi      r5, r1, 0x44
	  lwz       r4, 0x30(r30)
	  bl        0x13E124
	  cmpwi     r3, 0x1
	  blt-      .loc_0x1C8
	  stw       r29, 0x2E48(r13)
	  bne-      .loc_0x150
	  lis       r0, 0xB
	  stw       r0, 0x24(r30)
	  li        r0, 0x1
	  stw       r0, 0x20(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x7AA0(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x7AA4(r2)
	  stfs      f0, 0xC(r3)
	  b         .loc_0x1C8

	.loc_0x150:
	  cmpwi     r3, 0x5
	  bne-      .loc_0x17C
	  stw       r29, 0x24(r30)
	  li        r0, 0x1
	  stw       r0, 0x20(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x7AA0(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x7AA4(r2)
	  stfs      f0, 0xC(r3)
	  b         .loc_0x1C8

	.loc_0x17C:
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  li        r5, 0x1
	  stb       r5, 0xB2(r4)
	  subi      r0, r3, 0x2
	  lwz       r3, 0x68(r1)
	  stw       r3, 0x1A0(r4)
	  stw       r0, 0x19C(r4)
	  lwz       r3, 0x44(r1)
	  addi      r0, r3, 0x1
	  stb       r0, 0xB4(r4)
	  lwz       r0, 0x50(r1)
	  stw       r0, 0x2FC(r4)
	  stw       r5, 0x20(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f0, -0x7AA0(r2)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x7AA4(r2)
	  stfs      f0, 0xC(r3)

	.loc_0x1C8:
	  lwz       r3, 0x2E48(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x1DC
	  mr        r4, r31
	  bl        0x13E1F8

	.loc_0x1DC:
	  lwz       r0, 0xC4(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  lwz       r29, 0xB4(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80055708
 * Size:	000004
 */
void CardSelectSection::init() { }
