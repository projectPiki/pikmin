#include "types.h"

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
 * Address:	801F0A80
 * Size:	0003D8
 */
zen::DrawHiScore::DrawHiScore()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stmw      r22, 0x48(r1)
	  li        r22, 0
	  addi      r29, r3, 0
	  stw       r22, 0x10(r3)
	  lis       r3, 0x8022
	  addi      r5, r3, 0x2758
	  stw       r22, 0x14(r29)
	  addi      r3, r29, 0x2C
	  stw       r22, 0x18(r29)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x20(r29)
	  stw       r0, 0x24(r29)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x28(r29)
	  stw       r22, 0x1C(r29)
	  bl        0xF0C
	  stw       r22, 0x0(r29)
	  li        r3, 0x100
	  bl        -0x1A9AD4
	  addi      r22, r3, 0
	  mr.       r3, r22
	  beq-      .loc_0x80
	  lis       r4, 0x802E
	  addi      r4, r4, 0x7130
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x31588

	.loc_0x80:
	  stw       r22, 0x4(r29)
	  lis       r3, 0x7474
	  addi      r4, r3, 0x616C
	  lwz       r3, 0x4(r29)
	  li        r5, 0x1
	  addi      r30, r3, 0x4
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8(r29)
	  addi      r3, r30, 0
	  lis       r4, 0x6368
	  lwz       r12, 0x0(r30)
	  addi      r4, r4, 0x6172
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC(r29)
	  addi      r4, r30, 0
	  addi      r3, r29, 0x10
	  bl        -0x2648
	  lwz       r4, 0x14(r29)
	  lis       r3, 0x803A
	  subi      r23, r3, 0x2848
	  lbz       r0, 0xC(r4)
	  li        r5, 0
	  li        r31, 0
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)
	  rlwinm    r0,r31,3,0,28
	  rlwinm    r3,r31,2,0,29
	  addi      r28, r1, 0x20
	  add       r25, r23, r0
	  add       r26, r23, r3
	  addi      r27, r23, 0x94
	  add       r28, r28, r3
	  li        r24, 0

	.loc_0x120:
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x40
	  addi      r4, r13, 0x2968
	  bl        0x259E8
	  lbz       r0, 0x41(r1)
	  mr        r3, r29
	  lbz       r5, 0x40(r1)
	  mr        r4, r30
	  rlwinm    r0,r0,16,0,15
	  lbz       r7, 0x42(r1)
	  rlwimi    r0,r5,24,0,7
	  lbz       r8, 0x43(r1)
	  rlwimi    r0,r7,8,16,23
	  lwz       r6, 0xBC(r25)
	  or        r5, r8, r0
	  li        r7, 0x2
	  li        r8, 0x1
	  bl        0x5D0
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x40
	  addi      r4, r13, 0x2970
	  bl        0x2599C
	  lbz       r0, 0x41(r1)
	  mr        r3, r29
	  lbz       r5, 0x40(r1)
	  mr        r4, r30
	  rlwinm    r0,r0,16,0,15
	  lbz       r7, 0x42(r1)
	  rlwimi    r0,r5,24,0,7
	  lbz       r8, 0x43(r1)
	  rlwimi    r0,r7,8,16,23
	  lwz       r6, 0xC0(r25)
	  or        r5, r8, r0
	  li        r7, 0x2
	  li        r8, 0x1
	  bl        0x584
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x40
	  addi      r4, r13, 0x2978
	  bl        0x25950
	  lbz       r0, 0x41(r1)
	  mr        r3, r29
	  lbz       r5, 0x40(r1)
	  mr        r4, r30
	  rlwinm    r0,r0,16,0,15
	  lbz       r7, 0x42(r1)
	  rlwimi    r0,r5,24,0,7
	  lbz       r8, 0x43(r1)
	  rlwimi    r0,r7,8,16,23
	  lwz       r6, 0xE4(r26)
	  or        r5, r8, r0
	  li        r7, 0x4
	  li        r8, 0x1
	  bl        0x538
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x40
	  addi      r4, r13, 0x2980
	  bl        0x25904
	  lwz       r0, 0xF8(r26)
	  cmpwi     r0, 0x270F
	  mr        r6, r0
	  bne-      .loc_0x22C
	  li        r6, -0x1

	.loc_0x22C:
	  lbz       r0, 0x41(r1)
	  mr        r3, r29
	  lbz       r5, 0x40(r1)
	  mr        r4, r30
	  rlwinm    r0,r0,16,0,15
	  lbz       r7, 0x42(r1)
	  rlwimi    r0,r5,24,0,7
	  lbz       r8, 0x43(r1)
	  rlwimi    r0,r7,8,16,23
	  or        r5, r8, r0
	  li        r7, 0x4
	  li        r8, 0x1
	  bl        0x4DC
	  cmpwi     r31, 0
	  blt-      .loc_0x290
	  cmpwi     r31, 0x5
	  bgt-      .loc_0x290
	  li        r0, 0x1
	  lbz       r3, 0xB6(r23)
	  slw       r0, r0, r31
	  and       r0, r3, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  b         .loc_0x294

	.loc_0x290:
	  li        r0, 0

	.loc_0x294:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x2FC
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x40
	  addi      r4, r13, 0x2988
	  bl        0x2586C
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x41(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x40(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x42(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x43(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  lbz       r0, 0xC(r3)
	  li        r4, 0
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x300

	.loc_0x2FC:
	  addi      r24, r24, 0x1

	.loc_0x300:
	  li        r22, 0

	.loc_0x304:
	  stw       r22, 0x20(r1)
	  addi      r3, r27, 0
	  addi      r4, r1, 0x20
	  bl        -0x19CECC
	  addi      r5, r22, 0
	  crclr     6, 0x6
	  addi      r6, r31, 0
	  addi      r3, r1, 0x40
	  addi      r4, r13, 0x2990
	  bl        0x257F0
	  lbz       r0, 0x41(r1)
	  mr        r3, r29
	  lbz       r5, 0x40(r1)
	  mr        r4, r30
	  rlwinm    r0,r0,16,0,15
	  lbz       r7, 0x42(r1)
	  rlwimi    r0,r5,24,0,7
	  lbz       r8, 0x43(r1)
	  rlwimi    r0,r7,8,16,23
	  lwz       r6, 0xC(r28)
	  or        r5, r8, r0
	  li        r7, 0x3
	  li        r8, 0x1
	  bl        0x3D8
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x5
	  blt+      .loc_0x304
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x5
	  addi      r25, r25, 0x8
	  addi      r26, r26, 0x4
	  addi      r28, r28, 0x4
	  blt+      .loc_0x120
	  cmpwi     r24, 0
	  bne-      .loc_0x3C0
	  lwz       r3, 0x8(r29)
	  li        r4, 0x1B
	  li        r5, 0x82
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r29)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x3C0:
	  mr        r3, r29
	  lmw       r22, 0x48(r1)
	  lwz       r0, 0x74(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F0E58
 * Size:	00012C
 */
void zen::DrawHiScore::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  li        r31, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lwz       r3, 0x4(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r29, 0x10
	  bl        -0x26F8
	  addi      r3, r29, 0x2C
	  bl        0xB84
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x88
	  bge-      .loc_0x64
	  cmpwi     r0, 0x1
	  bge-      .loc_0x70
	  b         .loc_0x10C

	.loc_0x64:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x10C
	  b         .loc_0xF4

	.loc_0x70:
	  lwz       r0, 0x2C(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0x10C
	  li        r0, 0x2
	  stw       r0, 0x0(r29)
	  b         .loc_0x10C

	.loc_0x88:
	  lwz       r0, 0x28(r30)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x10C
	  li        r3, 0x11D
	  bl        -0x14BB7C
	  li        r0, 0x3
	  stw       r0, 0x0(r29)
	  li        r5, 0
	  li        r0, 0xFF
	  stb       r5, 0x14(r1)
	  addi      r3, r29, 0x2C
	  li        r4, 0
	  stb       r5, 0x10(r1)
	  stb       r5, 0x15(r1)
	  stb       r5, 0x11(r1)
	  stb       r5, 0x16(r1)
	  stb       r5, 0x12(r1)
	  stb       r0, 0x17(r1)
	  stb       r0, 0x13(r1)
	  lwz       r0, 0x14(r1)
	  stw       r0, 0x4C(r29)
	  lwz       r0, 0x10(r1)
	  stw       r0, 0x50(r29)
	  lfs       f1, -0x3DF0(r2)
	  lfs       f2, -0x3DEC(r2)
	  bl        0xDCC
	  b         .loc_0x10C

	.loc_0xF4:
	  lwz       r0, 0x2C(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0x10C
	  li        r0, 0
	  stw       r0, 0x0(r29)
	  li        r31, 0x1

	.loc_0x10C:
	  mr        r3, r31
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F0F84
 * Size:	0001B0
 */
void zen::DrawHiScore::draw(Graphics&)
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
	  cmpwi     r0, 0x2
	  beq-      .loc_0x78
	  bge-      .loc_0x44
	  cmpwi     r0, 0x1
	  bge-      .loc_0x50
	  b         .loc_0xA4

	.loc_0x44:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xA4
	  b         .loc_0x80

	.loc_0x50:
	  lwz       r0, 0x30(r30)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x64
	  li        r0, 0x1
	  b         .loc_0x68

	.loc_0x64:
	  li        r0, 0

	.loc_0x68:
	  cmpwi     r0, 0
	  beq-      .loc_0xA4
	  li        r3, 0x1
	  b         .loc_0xA4

	.loc_0x78:
	  li        r3, 0x1
	  b         .loc_0xA4

	.loc_0x80:
	  lwz       r0, 0x30(r30)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x94
	  li        r0, 0x1
	  b         .loc_0x98

	.loc_0x94:
	  li        r0, 0

	.loc_0x98:
	  cmpwi     r0, 0
	  beq-      .loc_0xA4
	  li        r3, 0x1

	.loc_0xA4:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x184
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
	  li        r0, 0x40
	  addi      r4, r1, 0x20
	  stb       r28, 0x21(r1)
	  mr        r3, r31
	  stb       r0, 0x22(r1)
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
	  lwz       r3, 0x4(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x184:
	  addi      r3, r30, 0x2C
	  addi      r4, r31, 0
	  bl        0xB1C
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
 * Address:	801F1134
 * Size:	000084
 */
void zen::DrawHiScore::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x0(r3)
	  addi      r3, r31, 0x10
	  bl        -0x2918
	  li        r5, 0
	  stb       r5, 0x10(r1)
	  li        r0, 0xFF
	  addi      r3, r31, 0x2C
	  stb       r5, 0xC(r1)
	  li        r4, 0x1
	  stb       r5, 0x11(r1)
	  stb       r5, 0xD(r1)
	  stb       r5, 0x12(r1)
	  stb       r5, 0xE(r1)
	  stb       r0, 0x13(r1)
	  stb       r0, 0xF(r1)
	  lwz       r0, 0x10(r1)
	  stw       r0, 0x4C(r31)
	  lwz       r0, 0xC(r1)
	  stw       r0, 0x50(r31)
	  lfs       f1, -0x3DF0(r2)
	  lfs       f2, -0x3DEC(r2)
	  bl        0xB70
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F11B8
 * Size:	00033C
 */
void zen::DrawHiScore::rewriteNumber(P2DScreen*, u32, int, int, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stmw      r18, 0x30(r1)
	  mr        r29, r6
	  mr        r30, r7
	  addi      r18, r8, 0
	  stw       r5, 0x10(r1)
	  li        r5, 0x1
	  lwz       r12, 0x0(r4)
	  lwz       r4, 0x10(r1)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  lhz       r0, 0x8(r3)
	  cmplwi    r0, 0x13
	  bne-      .loc_0x328
	  addi      r3, r30, 0x1
	  bl        -0x1AA204
	  rlwinm.   r0,r18,0,24,31
	  beq-      .loc_0xF0
	  cmpwi     r29, 0
	  bge-      .loc_0xF0
	  cmpwi     r30, 0
	  li        r5, 0
	  ble-      .loc_0xE4
	  cmpwi     r30, 0x8
	  subi      r4, r30, 0x8
	  ble-      .loc_0xC0
	  addi      r0, r4, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r4, 0
	  mtctr     r0
	  li        r0, 0x2A
	  ble-      .loc_0xC0

	.loc_0x94:
	  add       r4, r3, r5
	  stb       r0, 0x0(r4)
	  addi      r5, r5, 0x8
	  stb       r0, 0x1(r4)
	  stb       r0, 0x2(r4)
	  stb       r0, 0x3(r4)
	  stb       r0, 0x4(r4)
	  stb       r0, 0x5(r4)
	  stb       r0, 0x6(r4)
	  stb       r0, 0x7(r4)
	  bdnz+     .loc_0x94

	.loc_0xC0:
	  sub       r0, r30, r5
	  cmpw      r5, r30
	  mtctr     r0
	  add       r4, r3, r5
	  li        r0, 0x2A
	  bge-      .loc_0xE4

	.loc_0xD8:
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0xD8

	.loc_0xE4:
	  li        r0, 0
	  stbx      r0, r3, r30
	  b         .loc_0x324

	.loc_0xF0:
	  cmpwi     r30, 0
	  li        r25, 0x1
	  li        r26, 0
	  ble-      .loc_0x31C
	  cmpwi     r30, 0x8
	  subi      r5, r30, 0x8
	  ble-      .loc_0x2CC
	  addi      r0, r5, 0x7
	  rlwinm    r0,r0,29,3,31
	  lis       r4, 0x6666
	  mtctr     r0
	  cmpwi     r5, 0
	  addi      r27, r4, 0x6667
	  ble-      .loc_0x2CC

	.loc_0x128:
	  divw      r18, r29, r25
	  mulli     r25, r25, 0xA
	  divw      r7, r29, r25
	  mulli     r25, r25, 0xA
	  divw      r6, r29, r25
	  mulli     r25, r25, 0xA
	  divw      r5, r29, r25
	  mulli     r25, r25, 0xA
	  divw      r4, r29, r25
	  mulli     r25, r25, 0xA
	  divw      r0, r29, r25
	  mulli     r25, r25, 0xA
	  divw      r22, r29, r25
	  mulhw     r8, r27, r18
	  srawi     r9, r8, 0x2
	  mulhw     r8, r27, r7
	  rlwinm    r10,r9,1,31,31
	  add       r10, r9, r10
	  srawi     r9, r8, 0x2
	  mulhw     r8, r27, r6
	  mulli     r12, r10, 0xA
	  rlwinm    r10,r9,1,31,31
	  add       r10, r9, r10
	  srawi     r9, r8, 0x2
	  mulhw     r8, r27, r5
	  mulli     r11, r10, 0xA
	  rlwinm    r10,r9,1,31,31
	  sub       r28, r18, r12
	  sub       r12, r30, r26
	  add       r10, r9, r10
	  srawi     r9, r8, 0x2
	  mulhw     r8, r27, r4
	  addi      r19, r26, 0x1
	  mulli     r21, r10, 0xA
	  rlwinm    r18,r9,1,31,31
	  sub       r11, r7, r11
	  sub       r10, r30, r19
	  add       r9, r9, r18
	  srawi     r20, r8, 0x2
	  mulhw     r7, r27, r0
	  addi      r8, r26, 0x2
	  mulli     r18, r9, 0xA
	  rlwinm    r19,r20,1,31,31
	  sub       r9, r6, r21
	  sub       r8, r30, r8
	  add       r6, r20, r19
	  srawi     r21, r7, 0x2
	  mulhw     r23, r27, r22
	  addi      r24, r26, 0x3
	  mulli     r19, r6, 0xA
	  rlwinm    r20,r21,1,31,31
	  sub       r7, r5, r18
	  sub       r6, r30, r24
	  add       r5, r21, r20
	  srawi     r24, r23, 0x2
	  addi      r21, r26, 0x4
	  mulli     r20, r5, 0xA
	  rlwinm    r23,r24,1,31,31
	  sub       r5, r4, r19
	  sub       r4, r30, r21
	  add       r23, r24, r23
	  addi      r21, r26, 0x5
	  mulli     r23, r23, 0xA
	  sub       r20, r0, r20
	  sub       r21, r30, r21
	  addi      r0, r26, 0x6
	  sub       r23, r22, r23
	  sub       r24, r30, r0
	  addi      r18, r28, 0x30
	  subi      r0, r12, 0x1
	  stbx      r18, r3, r0
	  addi      r11, r11, 0x30
	  subi      r0, r10, 0x1
	  stbx      r11, r3, r0
	  addi      r9, r9, 0x30
	  subi      r0, r8, 0x1
	  stbx      r9, r3, r0
	  addi      r7, r7, 0x30
	  subi      r0, r6, 0x1
	  stbx      r7, r3, r0
	  addi      r5, r5, 0x30
	  subi      r0, r4, 0x1
	  stbx      r5, r3, r0
	  addi      r4, r20, 0x30
	  subi      r0, r21, 0x1
	  stbx      r4, r3, r0
	  addi      r4, r23, 0x30
	  subi      r0, r24, 0x1
	  stbx      r4, r3, r0
	  mulli     r25, r25, 0xA
	  divw      r5, r29, r25
	  mulhw     r0, r27, r5
	  srawi     r0, r0, 0x2
	  rlwinm    r4,r0,1,31,31
	  add       r0, r0, r4
	  mulli     r4, r0, 0xA
	  addi      r0, r26, 0x7
	  sub       r5, r5, r4
	  sub       r4, r30, r0
	  addi      r5, r5, 0x30
	  subi      r0, r4, 0x1
	  mulli     r25, r25, 0xA
	  stbx      r5, r3, r0
	  addi      r26, r26, 0x8
	  bdnz+     .loc_0x128

	.loc_0x2CC:
	  sub       r0, r30, r26
	  lis       r4, 0x6666
	  mtctr     r0
	  cmpw      r26, r30
	  addi      r6, r4, 0x6667
	  bge-      .loc_0x31C

	.loc_0x2E4:
	  divw      r5, r29, r25
	  mulhw     r0, r6, r5
	  srawi     r0, r0, 0x2
	  rlwinm    r4,r0,1,31,31
	  add       r0, r0, r4
	  mulli     r0, r0, 0xA
	  sub       r4, r30, r26
	  sub       r5, r5, r0
	  addi      r5, r5, 0x30
	  subi      r0, r4, 0x1
	  mulli     r25, r25, 0xA
	  stbx      r5, r3, r0
	  addi      r26, r26, 0x1
	  bdnz+     .loc_0x2E4

	.loc_0x31C:
	  li        r0, 0
	  stbx      r0, r3, r30

	.loc_0x324:
	  stw       r3, 0x10C(r31)

	.loc_0x328:
	  lmw       r18, 0x30(r1)
	  lwz       r0, 0x6C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}
