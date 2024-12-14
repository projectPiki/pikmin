#include "zen/ogTotalScore.h"

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
 * Address:	80194204
 * Size:	000A0C
 */
zen::ogScrTotalScoreMgr::ogScrTotalScoreMgr(zen::TotalScoreType*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stmw      r23, 0x64(r1)
	  mr        r31, r3
	  stw       r4, 0x820(r3)
	  lwz       r0, 0x820(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x10C
	  li        r3, 0x44
	  bl        -0x14D228
	  stw       r3, 0x824(r31)
	  lis       r3, 0x55
	  li        r24, 0xB
	  lwz       r23, 0x824(r31)
	  li        r0, 0x16
	  li        r5, 0x14D
	  stw       r24, 0x0(r23)
	  li        r4, 0x115C
	  subi      r3, r3, 0x3A9D
	  stw       r0, 0x4(r23)
	  li        r0, 0x1
	  li        r25, 0xA
	  stw       r5, 0x8(r23)
	  li        r26, 0x1388
	  li        r30, 0
	  stw       r4, 0xC(r23)
	  li        r29, 0x2
	  li        r28, 0x1387
	  stw       r3, 0x10(r23)
	  li        r27, 0x3
	  li        r12, 0xC
	  sth       r0, 0x14(r23)
	  li        r11, 0x1386
	  li        r10, 0x14
	  sth       r0, 0x16(r23)
	  li        r9, 0x4
	  li        r8, 0xD
	  sth       r0, 0x18(r23)
	  li        r7, 0x1385
	  li        r6, 0x1E
	  sth       r0, 0x1A(r23)
	  li        r5, 0x5
	  li        r4, 0xE
	  sth       r25, 0x24(r23)
	  li        r3, 0x1384
	  li        r0, 0x28
	  sth       r26, 0x2E(r23)
	  sth       r30, 0x38(r23)
	  sth       r29, 0x1C(r23)
	  sth       r24, 0x26(r23)
	  sth       r28, 0x30(r23)
	  sth       r25, 0x3A(r23)
	  sth       r27, 0x1E(r23)
	  sth       r12, 0x28(r23)
	  sth       r11, 0x32(r23)
	  sth       r10, 0x3C(r23)
	  sth       r9, 0x20(r23)
	  sth       r8, 0x2A(r23)
	  sth       r7, 0x34(r23)
	  sth       r6, 0x3E(r23)
	  sth       r5, 0x22(r23)
	  sth       r4, 0x2C(r23)
	  sth       r3, 0x36(r23)
	  sth       r0, 0x40(r23)
	  lwz       r0, 0x824(r31)
	  stw       r0, 0x820(r31)

	.loc_0x10C:
	  li        r3, 0xF8
	  bl        -0x14D310
	  addi      r23, r3, 0
	  mr.       r0, r23
	  beq-      .loc_0x174
	  addi      r3, r1, 0x48
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1F2F0
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x48
	  addi      r3, r23, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x1C674
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r23)
	  li        r0, 0
	  stb       r0, 0xEC(r23)
	  stw       r0, 0xF0(r23)
	  stw       r0, 0xF4(r23)

	.loc_0x174:
	  stw       r23, 0x4(r31)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x6058
	  lwz       r3, 0x4(r31)
	  li        r5, 0x1
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        0x1E86C
	  lwz       r30, 0x4(r31)
	  li        r3, 0x1C
	  bl        -0x14D39C
	  cmplwi    r3, 0
	  beq-      .loc_0x1DC
	  li        r6, 0
	  stw       r6, 0x0(r3)
	  lis       r4, 0x8022
	  addi      r5, r4, 0x2758
	  stw       r6, 0x4(r3)
	  stw       r6, 0x8(r3)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x10(r3)
	  stw       r0, 0x14(r3)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x18(r3)
	  stw       r6, 0xC(r3)

	.loc_0x1DC:
	  stw       r3, 0x82C(r31)
	  lwz       r3, 0x82C(r31)
	  lwz       r4, 0x4(r31)
	  bl        0x5A128
	  li        r3, 0x4C4
	  bl        -0x14D3F0
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x210
	  li        r4, 0x10
	  li        r5, 0x400
	  li        r6, 0x400
	  bl        0x554B0

	.loc_0x210:
	  stw       r23, 0x828(r31)
	  addi      r3, r30, 0
	  lis       r27, 0x7769
	  lwz       r12, 0x0(r30)
	  addi      r4, r27, 0x6E31
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x80(r31)
	  addi      r3, r30, 0
	  addi      r4, r27, 0x6E32
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x84(r31)
	  addi      r3, r30, 0
	  addi      r4, r27, 0x6E33
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x88(r31)
	  addi      r3, r30, 0
	  addi      r4, r27, 0x6E34
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8C(r31)
	  addi      r3, r30, 0
	  lis       r27, 0x7061
	  lwz       r12, 0x0(r30)
	  addi      r4, r27, 0x5F6C
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x4C(r31)
	  addi      r3, r30, 0
	  addi      r4, r27, 0x5F72
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x50(r31)
	  addi      r3, r30, 0
	  lis       r28, 0x6461
	  lwz       r12, 0x0(r30)
	  addi      r4, r28, 0x5F6C
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x54(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F72
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x58(r31)
	  addi      r3, r30, 0
	  lis       r28, 0x6C70
	  lwz       r12, 0x0(r30)
	  addi      r4, r28, 0x5F34
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x5C(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F33
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x60(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F32
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x64(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F31
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x68(r31)
	  addi      r3, r30, 0
	  lis       r29, 0x6470
	  lwz       r12, 0x0(r30)
	  addi      r4, r29, 0x5F34
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x6C(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F33
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x70(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F32
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x74(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F31
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x78(r31)
	  addi      r3, r30, 0
	  lis       r4, 0x7064
	  lwz       r12, 0x0(r30)
	  addi      r4, r4, 0x5F73
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x7C(r31)
	  addi      r3, r30, 0
	  addi      r4, r27, 0x5F6B
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x90(r31)
	  addi      r3, r30, 0
	  addi      r4, r27, 0x5F64
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x94(r31)
	  addi      r3, r30, 0
	  addi      r4, r28, 0x5F68
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x98(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F68
	  lwz       r12, 0x0(r30)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x9C(r31)
	  li        r3, 0x1
	  lwz       r4, 0x820(r31)
	  lha       r4, 0x1A(r4)
	  bl        -0x14590
	  lwz       r4, 0x820(r31)
	  li        r3, 0x2
	  lha       r4, 0x24(r4)
	  bl        -0x145A0
	  lwz       r4, 0x820(r31)
	  li        r3, 0x3
	  lha       r4, 0x1C(r4)
	  bl        -0x145B0
	  lwz       r4, 0x820(r31)
	  li        r3, 0x4
	  lha       r4, 0x26(r4)
	  bl        -0x145C0
	  lwz       r4, 0x820(r31)
	  li        r3, 0x5
	  lha       r4, 0x1E(r4)
	  bl        -0x145D0
	  lwz       r4, 0x820(r31)
	  li        r3, 0x6
	  lha       r4, 0x28(r4)
	  bl        -0x145E0
	  lwz       r4, 0x820(r31)
	  li        r3, 0x7
	  lha       r4, 0x20(r4)
	  bl        -0x145F0
	  lwz       r4, 0x820(r31)
	  li        r3, 0x8
	  lha       r4, 0x2A(r4)
	  bl        -0x14600
	  lwz       r4, 0x820(r31)
	  li        r3, 0x9
	  lha       r4, 0x22(r4)
	  bl        -0x14610
	  lwz       r4, 0x820(r31)
	  li        r3, 0xA
	  lha       r4, 0x2C(r4)
	  bl        -0x14620
	  lwz       r4, 0x820(r31)
	  li        r3, 0xB
	  lha       r4, 0x2E(r4)
	  bl        -0x14630
	  lwz       r4, 0x820(r31)
	  li        r3, 0xC
	  lha       r4, 0x30(r4)
	  bl        -0x14640
	  lwz       r4, 0x820(r31)
	  li        r3, 0xD
	  lha       r4, 0x32(r4)
	  bl        -0x14650
	  lwz       r4, 0x820(r31)
	  li        r3, 0xE
	  lha       r4, 0x34(r4)
	  bl        -0x14660
	  lwz       r4, 0x820(r31)
	  li        r3, 0xF
	  lha       r4, 0x36(r4)
	  bl        -0x14670
	  lwz       r4, 0x820(r31)
	  li        r3, 0x10
	  lha       r4, 0x38(r4)
	  bl        -0x14680
	  lwz       r4, 0x820(r31)
	  li        r3, 0x11
	  lha       r4, 0x3A(r4)
	  bl        -0x14690
	  lwz       r4, 0x820(r31)
	  li        r3, 0x12
	  lha       r4, 0x3C(r4)
	  bl        -0x146A0
	  lwz       r4, 0x820(r31)
	  li        r3, 0x13
	  lha       r4, 0x3E(r4)
	  bl        -0x146B0
	  lwz       r4, 0x820(r31)
	  li        r3, 0x14
	  lha       r4, 0x40(r4)
	  bl        -0x146C0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lis       r4, 0x6E65
	  addi      r4, r4, 0x7764
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x48(r31)
	  addi      r23, r31, 0
	  addi      r24, r31, 0
	  li        r25, 0

	.loc_0x63C:
	  addi      r3, r1, 0x54
	  crclr     6, 0x6
	  addi      r5, r25, 0x1
	  addi      r4, r13, 0xDF8
	  bl        0x81D48
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x55(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x54(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x56(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x57(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  stw       r3, 0xC(r23)
	  addi      r26, r24, 0xA0
	  addi      r3, r26, 0
	  lwz       r4, 0xC(r23)
	  lwz       r4, 0x10C(r4)
	  bl        0x84AB8
	  mr        r3, r26
	  bl        -0x14730
	  lwz       r3, 0xC(r23)
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x5
	  stw       r26, 0x10C(r3)
	  addi      r23, r23, 0x4
	  addi      r24, r24, 0x80
	  blt+      .loc_0x63C
	  addi      r23, r31, 0
	  addi      r24, r31, 0
	  li        r25, 0

	.loc_0x6D0:
	  addi      r3, r1, 0x54
	  crclr     6, 0x6
	  addi      r5, r25, 0x1
	  addi      r4, r13, 0xE00
	  bl        0x81CB4
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x55(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x54(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x56(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x57(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  stw       r3, 0x20(r23)
	  addi      r26, r24, 0x320
	  addi      r3, r26, 0
	  lwz       r4, 0x20(r23)
	  lwz       r4, 0x10C(r4)
	  bl        0x84A24
	  mr        r3, r26
	  bl        -0x147C4
	  lwz       r3, 0x20(r23)
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x5
	  stw       r26, 0x10C(r3)
	  addi      r23, r23, 0x4
	  addi      r24, r24, 0x80
	  blt+      .loc_0x6D0
	  addi      r23, r31, 0
	  addi      r24, r31, 0
	  li        r25, 0

	.loc_0x764:
	  addi      r3, r1, 0x54
	  crclr     6, 0x6
	  addi      r5, r25, 0x1
	  addi      r4, r13, 0xE08
	  bl        0x81C20
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lbz       r0, 0x55(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x54(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x56(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x57(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  stw       r3, 0x34(r23)
	  addi      r26, r24, 0x5A0
	  addi      r3, r26, 0
	  lwz       r4, 0x34(r23)
	  lwz       r4, 0x10C(r4)
	  bl        0x84990
	  mr        r3, r26
	  bl        -0x14858
	  lwz       r3, 0x34(r23)
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x5
	  stw       r26, 0x10C(r3)
	  addi      r23, r23, 0x4
	  addi      r24, r24, 0x80
	  blt+      .loc_0x764
	  lis       r29, 0x7061
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F6C
	  li        r6, 0xA
	  bl        -0x16120
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F72
	  li        r6, 0x1
	  bl        -0x16134
	  lwz       r5, 0x820(r31)
	  lis       r29, 0x6461
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F6C
	  addi      r5, r5, 0x4
	  li        r6, 0xA
	  bl        -0x16150
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F72
	  addi      r5, r5, 0x4
	  li        r6, 0x1
	  bl        -0x16168
	  lwz       r5, 0x820(r31)
	  lis       r29, 0x6C70
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F34
	  addi      r5, r5, 0x8
	  li        r6, 0x3E8
	  bl        -0x16184
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F33
	  addi      r5, r5, 0x8
	  li        r6, 0x64
	  bl        -0x1619C
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F32
	  addi      r5, r5, 0x8
	  li        r6, 0xA
	  bl        -0x161B4
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F31
	  addi      r5, r5, 0x8
	  li        r6, 0x1
	  bl        -0x161CC
	  lwz       r5, 0x820(r31)
	  lis       r29, 0x6470
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F34
	  addi      r5, r5, 0xC
	  li        r6, 0x3E8
	  bl        -0x161E8
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F33
	  addi      r5, r5, 0xC
	  li        r6, 0x64
	  bl        -0x16200
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F32
	  addi      r5, r5, 0xC
	  li        r6, 0xA
	  bl        -0x16218
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F31
	  addi      r5, r5, 0xC
	  li        r6, 0x1
	  bl        -0x16230
	  lwz       r5, 0x820(r31)
	  lis       r29, 0x7470
	  lis       r6, 0x99
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F38
	  addi      r5, r5, 0x10
	  subi      r6, r6, 0x6980
	  bl        -0x16250
	  lwz       r5, 0x820(r31)
	  lis       r6, 0xF
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F37
	  addi      r5, r5, 0x10
	  addi      r6, r6, 0x4240
	  bl        -0x1626C
	  lwz       r5, 0x820(r31)
	  lis       r6, 0x2
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F36
	  addi      r5, r5, 0x10
	  subi      r6, r6, 0x7960
	  bl        -0x16288
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F35
	  addi      r5, r5, 0x10
	  li        r6, 0x2710
	  bl        -0x162A0
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F34
	  addi      r5, r5, 0x10
	  li        r6, 0x3E8
	  bl        -0x162B8
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F33
	  addi      r5, r5, 0x10
	  li        r6, 0x64
	  bl        -0x162D0
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F32
	  addi      r5, r5, 0x10
	  li        r6, 0xA
	  bl        -0x162E8
	  lwz       r5, 0x820(r31)
	  addi      r3, r30, 0
	  addi      r4, r29, 0x5F31
	  addi      r5, r5, 0x10
	  li        r6, 0x1
	  bl        -0x16300
	  lfs       f0, -0x4DE8(r2)
	  li        r0, -0x1
	  addi      r3, r31, 0
	  stfs      f0, 0x8(r31)
	  stw       r0, 0x0(r31)
	  lwz       r0, 0x8C(r1)
	  lmw       r23, 0x64(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80194C10
 * Size:	00003C
 */
void zen::ogScrTotalScoreMgr::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        0x948
	  li        r0, 0x1
	  stw       r0, 0x0(r31)
	  lwz       r3, 0x82C(r31)
	  bl        0x59BE4
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80194C4C
 * Size:	000190
 */
int zen::ogScrTotalScoreMgr::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x2C
	  b         .loc_0x178

	.loc_0x2C:
	  lwz       r3, 0x4(r30)
	  bl        0x1DED4
	  lwz       r3, 0x828(r30)
	  bl        0x54F04
	  lwz       r3, 0x82C(r30)
	  bl        0x59B10
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r30)
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xC0
	  lfs       f1, 0x8(r30)
	  lfs       f0, -0x4DE4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x94
	  lfs       f0, -0x4DE0(r2)
	  lwz       r3, 0x4(r30)
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r4, 0x24(r1)
	  bl        0x2AC00
	  b         .loc_0xB8

	.loc_0x94:
	  lwz       r3, 0x4(r30)
	  li        r4, 0xFF
	  bl        0x2ABF0
	  li        r0, 0
	  stw       r0, 0x0(r30)
	  mr        r3, r30
	  lfs       f0, -0x4DE8(r2)
	  stfs      f0, 0x8(r30)
	  bl        0x180

	.loc_0xB8:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x178

	.loc_0xC0:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x120
	  lfs       f1, 0x8(r30)
	  lfs       f0, -0x4DE4(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xFC
	  lfs       f0, -0x4DE0(r2)
	  lwz       r3, 0x4(r30)
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  subfic    r4, r0, 0xFF
	  bl        0x2AB98
	  b         .loc_0x118

	.loc_0xFC:
	  lwz       r3, 0x4(r30)
	  li        r4, 0
	  bl        0x2AB88
	  li        r0, 0x3
	  stw       r0, 0x0(r30)
	  lfs       f0, -0x4DE8(r2)
	  stfs      f0, 0x8(r30)

	.loc_0x118:
	  lwz       r3, 0x0(r30)
	  b         .loc_0x178

	.loc_0x120:
	  cmpwi     r0, 0x3
	  bne-      .loc_0x138
	  li        r0, -0x1
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x0(r30)
	  b         .loc_0x178

	.loc_0x138:
	  mr        r3, r30
	  bl        0x7E4
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x174
	  lwz       r0, 0x28(r31)
	  rlwinm.   r0,r0,0,0,31
	  beq-      .loc_0x174
	  li        r0, 0x2
	  stw       r0, 0x0(r30)
	  li        r4, 0x1
	  lfs       f0, -0x4DE8(r2)
	  stfs      f0, 0x8(r30)
	  lwz       r3, 0x828(r30)
	  bl        0x54F18

	.loc_0x174:
	  lwz       r3, 0x0(r30)

	.loc_0x178:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80194DDC
 * Size:	0000A4
 */
void zen::ogScrTotalScoreMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xF8(r1)
	  mr        r30, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x8C
	  lfs       f1, -0x4DDC(r2)
	  addi      r3, r1, 0x10
	  lfs       f2, -0x4DE4(r2)
	  li        r4, 0
	  lfs       f3, -0x4DD8(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x1B36C
	  addi      r3, r1, 0x10
	  bl        0x1B474
	  lwz       r3, 0x4(r30)
	  addi      r6, r1, 0x10
	  li        r4, 0
	  li        r5, 0
	  bl        0x1E094
	  lwz       r3, 0x828(r30)
	  mr        r4, r31
	  bl        0x54D60
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x10(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x10(r1)

	.loc_0x8C:
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  lwz       r30, 0xF8(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void zen::ogScrTotalScoreMgr::setEffect(P2DPane*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80194E80
 * Size:	0006EC
 */
void zen::ogScrTotalScoreMgr::setRankInEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1E0(r1)
	  stw       r31, 0x1DC(r1)
	  stw       r30, 0x1D8(r1)
	  mr        r30, r3
	  stw       r29, 0x1D4(r1)
	  lwz       r3, 0x820(r3)
	  lha       r3, 0x14(r3)
	  extsh.    r0, r3
	  blt-      .loc_0x368
	  cmpwi     r3, 0x5
	  bge-      .loc_0x368
	  lwz       r29, 0x80(r30)
	  addi      r4, r1, 0x16C
	  addi      r5, r1, 0x170
	  addi      r3, r29, 0
	  bl        0x2AC6C
	  lha       r3, 0x18(r29)
	  lis       r31, 0x4330
	  lha       r0, 0x1C(r29)
	  li        r7, 0
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0x170(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0x16C(r1)
	  addze     r4, r4
	  lfs       f3, -0x4DE8(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0x170(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0x178
	  lwz       r0, 0x170(r1)
	  li        r4, 0x2
	  stw       r3, 0x16C(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0x170(r1)
	  stfs      f3, 0x180(r1)
	  stfs      f3, 0x17C(r1)
	  lwz       r3, 0x16C(r1)
	  lwz       r0, 0x170(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x4DD0(r2)
	  stw       r3, 0x1CC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x1C8(r1)
	  stw       r0, 0x1C4(r1)
	  lfd       f0, 0x1C8(r1)
	  stw       r31, 0x1C0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1C0(r1)
	  stfs      f3, 0x178(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x178(r1)
	  stfs      f0, 0x17C(r1)
	  lfs       f0, 0xE10(r13)
	  stfs      f0, 0x180(r1)
	  lwz       r3, 0x828(r30)
	  bl        0x54BBC
	  lwz       r29, 0x80(r30)
	  addi      r4, r1, 0x14C
	  addi      r5, r1, 0x150
	  addi      r3, r29, 0
	  bl        0x2AB9C
	  lha       r3, 0x18(r29)
	  li        r7, 0
	  lha       r0, 0x1C(r29)
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0x150(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0x14C(r1)
	  addze     r4, r4
	  lfs       f3, -0x4DE8(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0x150(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0x158
	  lwz       r0, 0x150(r1)
	  li        r4, 0x3
	  stw       r3, 0x14C(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0x150(r1)
	  stfs      f3, 0x160(r1)
	  stfs      f3, 0x15C(r1)
	  lwz       r3, 0x14C(r1)
	  lwz       r0, 0x150(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x4DD0(r2)
	  stw       r3, 0x1BC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x1B8(r1)
	  stw       r0, 0x1B4(r1)
	  lfd       f0, 0x1B8(r1)
	  stw       r31, 0x1B0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1B0(r1)
	  stfs      f3, 0x158(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x158(r1)
	  stfs      f0, 0x15C(r1)
	  lfs       f0, 0xE10(r13)
	  stfs      f0, 0x160(r1)
	  lwz       r3, 0x828(r30)
	  bl        0x54AF0
	  lwz       r29, 0x84(r30)
	  addi      r4, r1, 0x12C
	  addi      r5, r1, 0x130
	  addi      r3, r29, 0
	  bl        0x2AAD0
	  lha       r3, 0x18(r29)
	  li        r7, 0
	  lha       r0, 0x1C(r29)
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0x130(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0x12C(r1)
	  addze     r4, r4
	  lfs       f3, -0x4DE8(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0x130(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0x138
	  lwz       r0, 0x130(r1)
	  li        r4, 0x2
	  stw       r3, 0x12C(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0x130(r1)
	  stfs      f3, 0x140(r1)
	  stfs      f3, 0x13C(r1)
	  lwz       r3, 0x12C(r1)
	  lwz       r0, 0x130(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x4DD0(r2)
	  stw       r3, 0x1AC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x1A8(r1)
	  stw       r0, 0x1A4(r1)
	  lfd       f0, 0x1A8(r1)
	  stw       r31, 0x1A0(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1A0(r1)
	  stfs      f3, 0x138(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x138(r1)
	  stfs      f0, 0x13C(r1)
	  lfs       f0, 0xE10(r13)
	  stfs      f0, 0x140(r1)
	  lwz       r3, 0x828(r30)
	  bl        0x54A24
	  lwz       r29, 0x84(r30)
	  addi      r4, r1, 0x10C
	  addi      r5, r1, 0x110
	  addi      r3, r29, 0
	  bl        0x2AA04
	  lha       r3, 0x18(r29)
	  li        r7, 0
	  lha       r0, 0x1C(r29)
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0x110(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0x10C(r1)
	  addze     r4, r4
	  lfs       f3, -0x4DE8(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0x110(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0x118
	  lwz       r0, 0x110(r1)
	  li        r4, 0x3
	  stw       r3, 0x10C(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0x110(r1)
	  stfs      f3, 0x120(r1)
	  stfs      f3, 0x11C(r1)
	  lwz       r3, 0x10C(r1)
	  lwz       r0, 0x110(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x4DD0(r2)
	  stw       r3, 0x19C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x198(r1)
	  stw       r0, 0x194(r1)
	  lfd       f0, 0x198(r1)
	  stw       r31, 0x190(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x190(r1)
	  stfs      f3, 0x118(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x118(r1)
	  stfs      f0, 0x11C(r1)
	  lfs       f0, 0xE10(r13)
	  stfs      f0, 0x120(r1)
	  lwz       r3, 0x828(r30)
	  bl        0x54958

	.loc_0x368:
	  lwz       r3, 0x820(r30)
	  lha       r3, 0x16(r3)
	  extsh.    r0, r3
	  blt-      .loc_0x51C
	  cmpwi     r3, 0x5
	  bge-      .loc_0x51C
	  lwz       r29, 0x88(r30)
	  addi      r4, r1, 0xEC
	  addi      r5, r1, 0xF0
	  addi      r3, r29, 0
	  bl        0x2A920
	  lha       r3, 0x18(r29)
	  lis       r31, 0x4330
	  lha       r0, 0x1C(r29)
	  li        r7, 0
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0xF0(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0xEC(r1)
	  addze     r4, r4
	  lfs       f3, -0x4DE8(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0xF0(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0xF8
	  lwz       r0, 0xF0(r1)
	  li        r4, 0
	  stw       r3, 0xEC(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0xF0(r1)
	  stfs      f3, 0x100(r1)
	  stfs      f3, 0xFC(r1)
	  lwz       r3, 0xEC(r1)
	  lwz       r0, 0xF0(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x4DD0(r2)
	  stw       r3, 0x194(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x190(r1)
	  stw       r0, 0x19C(r1)
	  lfd       f0, 0x190(r1)
	  stw       r31, 0x198(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x198(r1)
	  stfs      f3, 0xF8(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xF8(r1)
	  stfs      f0, 0xFC(r1)
	  lfs       f0, 0xE10(r13)
	  stfs      f0, 0x100(r1)
	  lwz       r3, 0x828(r30)
	  bl        0x54870
	  lwz       r29, 0x88(r30)
	  addi      r4, r1, 0xCC
	  addi      r5, r1, 0xD0
	  addi      r3, r29, 0
	  bl        0x2A850
	  lha       r3, 0x18(r29)
	  li        r7, 0
	  lha       r0, 0x1C(r29)
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0xD0(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0xCC(r1)
	  addze     r4, r4
	  lfs       f3, -0x4DE8(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0xD0(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0xD8
	  lwz       r0, 0xD0(r1)
	  li        r4, 0x1
	  stw       r3, 0xCC(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0xD0(r1)
	  stfs      f3, 0xE0(r1)
	  stfs      f3, 0xDC(r1)
	  lwz       r3, 0xCC(r1)
	  lwz       r0, 0xD0(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x4DD0(r2)
	  stw       r3, 0x1A4(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x1A0(r1)
	  stw       r0, 0x1AC(r1)
	  lfd       f0, 0x1A0(r1)
	  stw       r31, 0x1A8(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1A8(r1)
	  stfs      f3, 0xD8(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xD8(r1)
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0xE10(r13)
	  stfs      f0, 0xE0(r1)
	  lwz       r3, 0x828(r30)
	  bl        0x547A4

	.loc_0x51C:
	  lwz       r3, 0x820(r30)
	  lha       r3, 0x18(r3)
	  extsh.    r0, r3
	  blt-      .loc_0x6D0
	  cmpwi     r3, 0x5
	  bge-      .loc_0x6D0
	  lwz       r29, 0x8C(r30)
	  addi      r4, r1, 0xAC
	  addi      r5, r1, 0xB0
	  addi      r3, r29, 0
	  bl        0x2A76C
	  lha       r3, 0x18(r29)
	  lis       r31, 0x4330
	  lha       r0, 0x1C(r29)
	  li        r7, 0
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0xB0(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0xAC(r1)
	  addze     r4, r4
	  lfs       f3, -0x4DE8(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0xB0(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0xB8
	  lwz       r0, 0xB0(r1)
	  li        r4, 0
	  stw       r3, 0xAC(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0xB0(r1)
	  stfs      f3, 0xC0(r1)
	  stfs      f3, 0xBC(r1)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x4DD0(r2)
	  stw       r3, 0x194(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x190(r1)
	  stw       r0, 0x19C(r1)
	  lfd       f0, 0x190(r1)
	  stw       r31, 0x198(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x198(r1)
	  stfs      f3, 0xB8(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xB8(r1)
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xE10(r13)
	  stfs      f0, 0xC0(r1)
	  lwz       r3, 0x828(r30)
	  bl        0x546BC
	  lwz       r29, 0x8C(r30)
	  addi      r4, r1, 0x8C
	  addi      r5, r1, 0x90
	  addi      r3, r29, 0
	  bl        0x2A69C
	  lha       r3, 0x18(r29)
	  li        r7, 0
	  lha       r0, 0x1C(r29)
	  lha       r6, 0x1A(r29)
	  sub       r0, r0, r3
	  lha       r5, 0x1E(r29)
	  srawi     r4, r0, 0x1
	  lwz       r3, 0x90(r1)
	  sub       r0, r5, r6
	  lwz       r5, 0x8C(r1)
	  addze     r4, r4
	  lfs       f3, -0x4DE8(r2)
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r0, r3, r0
	  stw       r0, 0x90(r1)
	  add       r3, r5, r4
	  addi      r5, r1, 0x98
	  lwz       r0, 0x90(r1)
	  li        r4, 0x1
	  stw       r3, 0x8C(r1)
	  li        r6, 0
	  subfic    r0, r0, 0x1E0
	  stw       r0, 0x90(r1)
	  stfs      f3, 0xA0(r1)
	  stfs      f3, 0x9C(r1)
	  lwz       r3, 0x8C(r1)
	  lwz       r0, 0x90(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x4DD0(r2)
	  stw       r3, 0x1A4(r1)
	  xoris     r0, r0, 0x8000
	  stw       r31, 0x1A0(r1)
	  stw       r0, 0x1AC(r1)
	  lfd       f0, 0x1A0(r1)
	  stw       r31, 0x1A8(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x1A8(r1)
	  stfs      f3, 0x98(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x98(r1)
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0xE10(r13)
	  stfs      f0, 0xA0(r1)
	  lwz       r3, 0x828(r30)
	  bl        0x545F0

	.loc_0x6D0:
	  lwz       r0, 0x1E4(r1)
	  lwz       r31, 0x1DC(r1)
	  lwz       r30, 0x1D8(r1)
	  lwz       r29, 0x1D4(r1)
	  addi      r1, r1, 0x1E0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019556C
 * Size:	0001D4
 */
void zen::ogScrTotalScoreMgr::setRankInColor()
{
	/*
	.loc_0x0:
	  stwu      r1, -0xE8(r1)
	  lwz       r4, 0x48(r3)
	  lbz       r0, 0x108(r4)
	  stb       r0, 0xE4(r1)
	  lbz       r0, 0x109(r4)
	  stb       r0, 0xE5(r1)
	  lbz       r0, 0x10A(r4)
	  stb       r0, 0xE6(r1)
	  lbz       r0, 0x10B(r4)
	  stb       r0, 0xE7(r1)
	  lwz       r4, 0x820(r3)
	  lha       r4, 0x14(r4)
	  extsh.    r0, r4
	  blt-      .loc_0xCC
	  cmpwi     r4, 0x5
	  bge-      .loc_0xCC
	  rlwinm    r4,r4,2,0,29
	  lwz       r0, 0xE4(r1)
	  add       r5, r3, r4
	  lwz       r4, 0xC(r5)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0xC(r5)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)
	  lwz       r4, 0x4C(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x50(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x54(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x58(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x7C(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x90(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x90(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)
	  lwz       r4, 0x94(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x94(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)

	.loc_0xCC:
	  lwz       r4, 0x820(r3)
	  lha       r4, 0x16(r4)
	  extsh.    r0, r4
	  blt-      .loc_0x14C
	  cmpwi     r4, 0x5
	  bge-      .loc_0x14C
	  rlwinm    r4,r4,2,0,29
	  lwz       r0, 0xE4(r1)
	  add       r5, r3, r4
	  lwz       r4, 0x20(r5)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x20(r5)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)
	  lwz       r4, 0x5C(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x60(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x64(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x68(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x98(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x98(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)

	.loc_0x14C:
	  lwz       r4, 0x820(r3)
	  lha       r4, 0x18(r4)
	  extsh.    r0, r4
	  blt-      .loc_0x1CC
	  cmpwi     r4, 0x5
	  bge-      .loc_0x1CC
	  rlwinm    r4,r4,2,0,29
	  lwz       r0, 0xE4(r1)
	  add       r5, r3, r4
	  lwz       r4, 0x34(r5)
	  stw       r0, 0xF4(r4)
	  lwz       r4, 0x34(r5)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r4)
	  lwz       r4, 0x6C(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x70(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x74(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x78(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0x108(r4)
	  lwz       r4, 0x9C(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF4(r4)
	  lwz       r3, 0x9C(r3)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xF8(r3)

	.loc_0x1CC:
	  addi      r1, r1, 0xE8
	  blr
	*/
}
