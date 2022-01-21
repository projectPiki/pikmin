

/*
 * --INFO--
 * Address:	80203BCC
 * Size:	000130
 */
void ClampStick(void)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x0(r3)
	  lbz       r12, 0x0(r4)
	  extsb.    r0, r0
	  extsb     r12, r12
	  mr        r11, r0
	  blt-      .loc_0x20
	  li        r0, 0x1
	  b         .loc_0x28

	.loc_0x20:
	  li        r0, -0x1
	  neg       r11, r11

	.loc_0x28:
	  cmpwi     r12, 0
	  blt-      .loc_0x38
	  li        r8, 0x1
	  b         .loc_0x40

	.loc_0x38:
	  li        r8, -0x1
	  neg       r12, r12

	.loc_0x40:
	  extsb     r7, r7
	  cmpw      r11, r7
	  bgt-      .loc_0x54
	  li        r11, 0
	  b         .loc_0x58

	.loc_0x54:
	  sub       r11, r11, r7

	.loc_0x58:
	  cmpw      r12, r7
	  bgt-      .loc_0x68
	  li        r12, 0
	  b         .loc_0x6C

	.loc_0x68:
	  sub       r12, r12, r7

	.loc_0x6C:
	  cmpwi     r11, 0
	  bne-      .loc_0x8C
	  cmpwi     r12, 0
	  bne-      .loc_0x8C
	  li        r0, 0
	  stb       r0, 0x0(r4)
	  stb       r0, 0x0(r3)
	  blr

	.loc_0x8C:
	  extsb     r6, r6
	  mullw     r9, r6, r12
	  mullw     r7, r6, r11
	  cmpw      r9, r7
	  bgt-      .loc_0xE0
	  extsb     r9, r5
	  sub       r5, r9, r6
	  mullw     r5, r12, r5
	  mullw     r9, r6, r9
	  add       r7, r7, r5
	  cmpw      r9, r7
	  bge-      .loc_0x11C
	  mullw     r6, r11, r9
	  mullw     r5, r12, r9
	  divw      r6, r6, r7
	  divw      r5, r5, r7
	  extsb     r6, r6
	  extsb     r5, r5
	  addi      r11, r6, 0
	  addi      r12, r5, 0
	  b         .loc_0x11C

	.loc_0xE0:
	  extsb     r7, r5
	  sub       r5, r7, r6
	  mullw     r5, r11, r5
	  mullw     r10, r6, r7
	  add       r7, r9, r5
	  cmpw      r10, r7
	  bge-      .loc_0x11C
	  mullw     r6, r11, r10
	  mullw     r5, r12, r10
	  divw      r6, r6, r7
	  divw      r5, r5, r7
	  extsb     r6, r6
	  extsb     r5, r5
	  addi      r11, r6, 0
	  addi      r12, r5, 0

	.loc_0x11C:
	  mullw     r5, r0, r11
	  mullw     r0, r8, r12
	  stb       r5, 0x0(r3)
	  stb       r0, 0x0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void ClampTrigger(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80203CFC
 * Size:	000108
 */
void PADClamp(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x14(r1)

	.loc_0x20:
	  lbz       r0, 0xA(r30)
	  extsb.    r0, r0
	  bne-      .loc_0xDC
	  addi      r29, r13, 0x2A30
	  lbz       r5, 0x3(r29)
	  addi      r3, r30, 0x2
	  lbz       r6, 0x4(r29)
	  addi      r4, r30, 0x3
	  lbz       r7, 0x2(r29)
	  bl        -0x174
	  lbz       r5, 0x6(r29)
	  addi      r3, r30, 0x4
	  lbz       r6, 0x7(r29)
	  addi      r4, r30, 0x5
	  lbz       r7, 0x5(r29)
	  bl        -0x18C
	  lbz       r3, 0x6(r30)
	  lbz       r0, 0x2A30(r13)
	  cmplw     r3, r0
	  bgt-      .loc_0x7C
	  li        r0, 0
	  stb       r0, 0x6(r30)
	  b         .loc_0x9C

	.loc_0x7C:
	  lbz       r0, 0x1(r29)
	  cmplw     r0, r3
	  bge-      .loc_0x8C
	  stb       r0, 0x6(r30)

	.loc_0x8C:
	  lbz       r3, 0x2A30(r13)
	  lbz       r0, 0x6(r30)
	  sub       r0, r0, r3
	  stb       r0, 0x6(r30)

	.loc_0x9C:
	  lbz       r4, 0x7(r30)
	  lbz       r0, 0x2A30(r13)
	  cmplw     r4, r0
	  bgt-      .loc_0xB8
	  li        r0, 0
	  stb       r0, 0x7(r30)
	  b         .loc_0xDC

	.loc_0xB8:
	  addi      r3, r13, 0x2A30
	  lbz       r0, 0x1(r3)
	  cmplw     r0, r4
	  bge-      .loc_0xCC
	  stb       r0, 0x7(r30)

	.loc_0xCC:
	  lbz       r3, 0x2A30(r13)
	  lbz       r0, 0x7(r30)
	  sub       r0, r0, r3
	  stb       r0, 0x7(r30)

	.loc_0xDC:
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x4
	  addi      r30, r30, 0xC
	  blt+      .loc_0x20
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  mtlr      r0
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}
