#include "zen/DrawUfoParts.h"

/*
 * --INFO--
 * Address:	801F1D60
 * Size:	0000EC
 */
zen::DrawUfoParts::DrawUfoParts()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0xC
	  bl        -0x3A4
	  li        r6, 0
	  stw       r6, 0x34(r30)
	  lis       r3, 0x8022
	  addi      r5, r3, 0x2758
	  stw       r6, 0x38(r30)
	  li        r3, 0x100
	  stw       r6, 0x3C(r30)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x44(r30)
	  stw       r0, 0x48(r30)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x4C(r30)
	  stw       r6, 0x40(r30)
	  bl        -0x1AADB4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x80
	  lis       r4, 0x802E
	  addi      r4, r4, 0x7148
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x32868

	.loc_0x80:
	  stw       r31, 0x8(r30)
	  addi      r3, r30, 0x34
	  lwz       r4, 0x8(r30)
	  addi      r4, r4, 0x4
	  bl        -0x38DC
	  li        r0, 0
	  stw       r0, 0x4(r30)
	  mr        r3, r30
	  stw       r0, 0x0(r30)
	  stb       r0, 0x1C(r1)
	  stb       r0, 0x18(r1)
	  stb       r0, 0x1D(r1)
	  stb       r0, 0x19(r1)
	  stb       r0, 0x1E(r1)
	  stb       r0, 0x1A(r1)
	  stb       r0, 0x1F(r1)
	  stb       r0, 0x1B(r1)
	  lwz       r0, 0x1C(r1)
	  stw       r0, 0x2C(r30)
	  lwz       r0, 0x18(r1)
	  stw       r0, 0x30(r30)
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
 * Address:	801F1E4C
 * Size:	000130
 */
void zen::DrawUfoParts::update(Controller*)
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
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x110
	  addi      r3, r29, 0xC
	  bl        -0x460
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x78
	  bge-      .loc_0x54
	  cmpwi     r0, 0x1
	  bge-      .loc_0x60
	  b         .loc_0xF4

	.loc_0x54:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xF4
	  b         .loc_0xDC

	.loc_0x60:
	  lwz       r0, 0xC(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0xF4
	  li        r0, 0x2
	  stw       r0, 0x0(r29)
	  b         .loc_0xF4

	.loc_0x78:
	  lis       r3, 0x100
	  lwz       r4, 0x28(r30)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0xA0
	  li        r3, 0x111
	  bl        -0x14CB68
	  li        r0, 0x2
	  stw       r0, 0x4(r29)
	  li        r31, 0x1

	.loc_0xA0:
	  lwz       r0, 0x28(r30)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0xF4
	  li        r3, 0x11D
	  bl        -0x14CB88
	  li        r0, 0x1
	  stw       r0, 0x4(r29)
	  addi      r3, r29, 0xC
	  li        r4, 0x1
	  lfs       f1, -0x3DB8(r2)
	  lfs       f2, -0x3DB4(r2)
	  bl        -0x208
	  li        r0, 0x3
	  stw       r0, 0x0(r29)
	  b         .loc_0xF4

	.loc_0xDC:
	  lwz       r0, 0xC(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0xF4
	  li        r0, 0
	  stw       r0, 0x0(r29)
	  li        r31, 0x1

	.loc_0xF4:
	  lwz       r3, 0x8(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r29, 0x34
	  bl        -0x37BC

	.loc_0x110:
	  mr        r3, r31
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
 * Address:	801F1F7C
 * Size:	0001B4
 */
void zen::DrawUfoParts::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stw       r31, 0x84(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x80(r1)
	  mr        r30, r3
	  stw       r29, 0x7C(r1)
	  stw       r28, 0x78(r1)
	  lwz       r0, 0x0(r3)
	  li        r3, 0
	  cmpwi     r0, 0
	  beq-      .loc_0x194
	  cmpwi     r0, 0x2
	  beq-      .loc_0x80
	  bge-      .loc_0x4C
	  cmpwi     r0, 0x1
	  bge-      .loc_0x58
	  b         .loc_0xAC

	.loc_0x4C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xAC
	  b         .loc_0x88

	.loc_0x58:
	  lwz       r0, 0x10(r30)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x6C
	  li        r0, 0x1
	  b         .loc_0x70

	.loc_0x6C:
	  li        r0, 0

	.loc_0x70:
	  cmpwi     r0, 0
	  beq-      .loc_0xAC
	  li        r3, 0x1
	  b         .loc_0xAC

	.loc_0x80:
	  li        r3, 0x1
	  b         .loc_0xAC

	.loc_0x88:
	  lwz       r0, 0x10(r30)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x9C
	  li        r0, 0x1
	  b         .loc_0xA0

	.loc_0x9C:
	  li        r0, 0

	.loc_0xA0:
	  cmpwi     r0, 0
	  beq-      .loc_0xAC
	  li        r3, 0x1

	.loc_0xAC:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x188
	  lwz       r6, 0x310(r31)
	  li        r28, 0
	  lwz       r0, 0x30C(r31)
	  addi      r5, r1, 0x28
	  addi      r3, r31, 0
	  stw       r28, 0x28(r1)
	  addi      r4, r1, 0x38
	  stw       r28, 0x2C(r1)
	  stw       r0, 0x30(r1)
	  stw       r6, 0x34(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0x24(r1)
	  li        r29, 0xFF
	  addi      r4, r1, 0x24
	  stb       r28, 0x25(r1)
	  mr        r3, r31
	  li        r5, 0x1
	  stb       r28, 0x26(r1)
	  stb       r29, 0x27(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r28, 0x20(r1)
	  addi      r4, r1, 0x20
	  addi      r3, r31, 0
	  stb       r28, 0x21(r1)
	  stb       r28, 0x22(r1)
	  stb       r29, 0x23(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r31)
	  addi      r4, r1, 0x10
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  stw       r28, 0x10(r1)
	  stw       r28, 0x14(r1)
	  stw       r0, 0x18(r1)
	  stw       r5, 0x1C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x8(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x188:
	  addi      r3, r30, 0xC
	  addi      r4, r31, 0
	  bl        -0x4E0

	.loc_0x194:
	  lwz       r0, 0x8C(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  lwz       r29, 0x7C(r1)
	  lwz       r28, 0x78(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F2130
 * Size:	000034
 */
void zen::DrawUfoParts::sleep()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r4, r3, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x0(r3)
	  addi      r3, r4, 0x34
	  stw       r0, 0x4(r4)
	  bl        -0x39D8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F2164
 * Size:	000068
 */
void zen::DrawUfoParts::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  addi      r3, r3, 0x4
	  bl        -0x329DC
	  li        r0, 0x1
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x4(r31)
	  bl        0x80
	  lfs       f1, -0x3DB0(r2)
	  addi      r3, r31, 0xC
	  lfs       f2, -0x3DB4(r2)
	  li        r4, 0
	  bl        -0x49C
	  addi      r3, r31, 0x34
	  bl        -0x399C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F21CC
 * Size:	00004C
 */
void zen::DrawUfoParts::operation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  addi      r3, r3, 0x4
	  bl        -0x32A44
	  li        r0, 0x2
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0x4(r31)
	  bl        .loc_0x4C
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x4C:
	*/
}

/*
 * --INFO--
 * Address:	801F2218
 * Size:	00020C
 */
void zen::DrawUfoParts::dataSet()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  stw       r30, 0x88(r1)
	  stw       r29, 0x84(r1)
	  li        r29, 0
	  stw       r28, 0x80(r1)
	  lwz       r3, 0x8(r3)
	  addi      r28, r3, 0x4

	.loc_0x28:
	  addi      r3, r1, 0x78
	  crclr     6, 0x6
	  addi      r5, r29, 0x1
	  addi      r4, r13, 0x2998
	  bl        0x24348
	  lwz       r12, 0x0(r28)
	  mr        r3, r28
	  lbz       r0, 0x79(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x78(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x7A(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x7B(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  addi      r30, r3, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x78
	  addi      r5, r29, 0x1
	  addi      r4, r13, 0x29A0
	  bl        0x242F8
	  lwz       r12, 0x0(r28)
	  mr        r3, r28
	  lbz       r0, 0x79(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x78(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x7A(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x7B(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lwz       r0, 0x2F6C(r13)
	  addi      r31, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x160
	  mr        r3, r29
	  bl        -0x15D798
	  mr        r4, r3
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x171CF8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1E0
	  li        r3, 0x30
	  stb       r3, 0x70(r1)
	  li        r4, 0
	  li        r0, 0xFF
	  stb       r3, 0x71(r1)
	  stb       r3, 0x72(r1)
	  stb       r4, 0x73(r1)
	  lwz       r3, 0x70(r1)
	  stw       r3, 0x10C(r30)
	  stb       r4, 0x68(r1)
	  stb       r4, 0x69(r1)
	  stb       r4, 0x6A(r1)
	  stb       r0, 0x6B(r1)
	  lwz       r0, 0x68(r1)
	  stw       r0, 0x108(r30)
	  stb       r4, 0x60(r1)
	  stb       r4, 0x61(r1)
	  stb       r4, 0x62(r1)
	  stb       r4, 0x63(r1)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0xF4(r31)
	  stb       r4, 0x58(r1)
	  stb       r4, 0x59(r1)
	  stb       r4, 0x5A(r1)
	  stb       r4, 0x5B(r1)
	  lwz       r0, 0x58(r1)
	  stw       r0, 0xF8(r31)
	  b         .loc_0x1E0

	.loc_0x160:
	  srawi     r0, r29, 0x1
	  addze     r0, r0
	  rlwinm    r0,r0,1,0,30
	  subc.     r0, r29, r0
	  bne-      .loc_0x1E0
	  li        r3, 0x30
	  stb       r3, 0x50(r1)
	  li        r4, 0
	  li        r0, 0xFF
	  stb       r3, 0x51(r1)
	  stb       r3, 0x52(r1)
	  stb       r4, 0x53(r1)
	  lwz       r3, 0x50(r1)
	  stw       r3, 0x10C(r30)
	  stb       r4, 0x48(r1)
	  stb       r4, 0x49(r1)
	  stb       r4, 0x4A(r1)
	  stb       r0, 0x4B(r1)
	  lwz       r0, 0x48(r1)
	  stw       r0, 0x108(r30)
	  stb       r4, 0x40(r1)
	  stb       r4, 0x41(r1)
	  stb       r4, 0x42(r1)
	  stb       r4, 0x43(r1)
	  lwz       r0, 0x40(r1)
	  stw       r0, 0xF4(r31)
	  stb       r4, 0x38(r1)
	  stb       r4, 0x39(r1)
	  stb       r4, 0x3A(r1)
	  stb       r4, 0x3B(r1)
	  lwz       r0, 0x38(r1)
	  stw       r0, 0xF8(r31)

	.loc_0x1E0:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x1E
	  blt+      .loc_0x28
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  lwz       r29, 0x84(r1)
	  lwz       r28, 0x80(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}
