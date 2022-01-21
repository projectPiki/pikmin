

/*
 * --INFO--
 * Address:	801FA3B4
 * Size:	0000F4
 */
void __OSResetSWInterruptHandler(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  bl        0x2FF4
	  lis       r5, 0x8000
	  stw       r4, 0x322C(r13)
	  lwz       r0, 0xF8(r5)
	  lis       r4, 0x431C
	  subi      r4, r4, 0x217D
	  stw       r3, 0x3228(r13)
	  rlwinm    r0,r0,30,2,31
	  mulhwu    r0, r4, r0
	  rlwinm    r0,r0,17,15,31
	  mulli     r0, r0, 0x64
	  rlwinm    r29,r0,29,3,31
	  li        r30, 0
	  lis       r31, 0xCC00

	.loc_0x50:
	  bl        0x2FBC
	  lwz       r6, 0x322C(r13)
	  xoris     r5, r30, 0x8000
	  lwz       r0, 0x3228(r13)
	  subc      r4, r4, r6
	  subfe     r0, r0, r3
	  xoris     r3, r0, 0x8000
	  subc      r0, r4, r29
	  subfe     r5, r5, r3
	  subfe     r5, r3, r3
	  neg.      r5, r5
	  beq-      .loc_0x8C
	  lwz       r0, 0x3000(r31)
	  rlwinm.   r0,r0,0,15,15
	  beq+      .loc_0x50

	.loc_0x8C:
	  lis       r3, 0xCC00
	  lwz       r0, 0x3000(r3)
	  rlwinm.   r0,r0,0,15,15
	  bne-      .loc_0xCC
	  li        r0, 0x1
	  stw       r0, 0x3214(r13)
	  li        r3, 0x200
	  stw       r0, 0x3218(r13)
	  bl        -0x1144
	  lwz       r12, 0x3210(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0xCC
	  li        r0, 0
	  mtlr      r12
	  stw       r0, 0x3210(r13)
	  blrl

	.loc_0xCC:
	  li        r0, 0x2
	  lis       r3, 0xCC00
	  stw       r0, 0x3000(r3)
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
 * Address:	........
 * Size:	000074
 */
void OSSetResetCallback(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FA4A8
 * Size:	0001F4
 */
void OSGetResetSwitchState(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  stw       r29, 0xC(r1)
	  bl        -0x1544
	  lis       r4, 0xCC00
	  lwz       r0, 0x3000(r4)
	  addi      r29, r3, 0
	  rlwinm.   r0,r0,0,15,15
	  bne-      .loc_0x110
	  lwz       r0, 0x3214(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x7C
	  lwz       r0, 0x3220(r13)
	  li        r4, 0
	  lwz       r3, 0x3224(r13)
	  li        r5, 0x1
	  xor       r0, r0, r4
	  xor       r3, r3, r4
	  stw       r5, 0x3214(r13)
	  or.       r0, r3, r0
	  beq-      .loc_0x64
	  b         .loc_0x68

	.loc_0x64:
	  mr        r5, r4

	.loc_0x68:
	  mr        r30, r5
	  bl        0x2EAC
	  stw       r4, 0x322C(r13)
	  stw       r3, 0x3228(r13)
	  b         .loc_0x1C8

	.loc_0x7C:
	  lwz       r0, 0x3220(r13)
	  li        r31, 0
	  lwz       r3, 0x3224(r13)
	  li        r30, 0x1
	  xor       r0, r0, r31
	  xor       r3, r3, r31
	  or.       r0, r3, r0
	  bne-      .loc_0xF4
	  bl        0x2E7C
	  lis       r5, 0x8000
	  lwz       r7, 0x322C(r13)
	  lwz       r0, 0xF8(r5)
	  lis       r5, 0x431C
	  subi      r5, r5, 0x217D
	  lwz       r6, 0x3228(r13)
	  rlwinm    r0,r0,30,2,31
	  mulhwu    r0, r5, r0
	  rlwinm    r0,r0,17,15,31
	  mulli     r0, r0, 0x64
	  subc      r5, r4, r7
	  subfe     r3, r6, r3
	  rlwinm    r0,r0,29,3,31
	  xoris     r4, r31, 0x8000
	  xoris     r3, r3, 0x8000
	  subc      r0, r0, r5
	  subfe     r3, r3, r4
	  subfe     r3, r4, r4
	  neg.      r3, r3
	  bne-      .loc_0xF4
	  mr        r30, r31

	.loc_0xF4:
	  cmpwi     r30, 0
	  beq-      .loc_0x104
	  li        r0, 0x1
	  b         .loc_0x108

	.loc_0x104:
	  li        r0, 0

	.loc_0x108:
	  mr        r30, r0
	  b         .loc_0x1C8

	.loc_0x110:
	  lwz       r0, 0x3214(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x144
	  lwz       r3, 0x3218(r13)
	  li        r0, 0
	  stw       r0, 0x3214(r13)
	  cmpwi     r3, 0
	  addi      r30, r3, 0
	  beq-      .loc_0x1C8
	  bl        0x2DE4
	  stw       r4, 0x3224(r13)
	  stw       r3, 0x3220(r13)
	  b         .loc_0x1C8

	.loc_0x144:
	  lwz       r0, 0x3220(r13)
	  li        r30, 0
	  lwz       r3, 0x3224(r13)
	  xor       r0, r0, r30
	  xor       r3, r3, r30
	  or.       r0, r3, r0
	  beq-      .loc_0x1B8
	  bl        0x2DB8
	  lis       r5, 0x8000
	  lwz       r7, 0x3224(r13)
	  lwz       r0, 0xF8(r5)
	  lis       r5, 0x1062
	  addi      r5, r5, 0x4DD3
	  lwz       r6, 0x3220(r13)
	  rlwinm    r0,r0,30,2,31
	  mulhwu    r0, r5, r0
	  rlwinm    r0,r0,26,6,31
	  mulli     r0, r0, 0x28
	  subc      r5, r4, r7
	  subfe     r3, r6, r3
	  xoris     r4, r3, 0x8000
	  xoris     r3, r30, 0x8000
	  subc      r0, r5, r0
	  subfe     r3, r3, r4
	  subfe     r3, r4, r4
	  neg.      r3, r3
	  beq-      .loc_0x1B8
	  li        r30, 0x1
	  b         .loc_0x1C8

	.loc_0x1B8:
	  li        r0, 0
	  stw       r0, 0x3224(r13)
	  li        r30, 0
	  stw       r0, 0x3220(r13)

	.loc_0x1C8:
	  stw       r30, 0x3218(r13)
	  mr        r3, r29
	  bl        -0x16D4
	  lwz       r0, 0x1C(r1)
	  mr        r3, r30
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  mtlr      r0
	  lwz       r29, 0xC(r1)
	  addi      r1, r1, 0x18
	  blr
	*/
}
