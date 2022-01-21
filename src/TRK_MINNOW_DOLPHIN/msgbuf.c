

/*
 * --INFO--
 * Address:	8021C4CC
 * Size:	000008
 */
void TRKSetBufferUsed(void a1)
{
	// Generated from stw r4, 0x4(r3)
	_04 = a1;
}

/*
 * --INFO--
 * Address:	8021C4D4
 * Size:	000078
 */
void TRKInitializeMessageBuffers(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x4320
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  stw       r30, 0x8(r1)
	  li        r30, 0
	  mulli     r4, r30, 0x890
	  add       r31, r0, r4

	.loc_0x28:
	  mr        r3, r31
	  bl        0x2198
	  mr        r3, r31
	  bl        0x2198
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x48
	  mr        r3, r31
	  bl        0x218C
	  addi      r30, r30, 0x1
	  addi      r31, r31, 0x890
	  cmpwi     r30, 0x3
	  blt+      .loc_0x28
	  lwz       r31, 0xC(r1)
	  li        r3, 0
	  lwz       r30, 0x8(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C54C
 * Size:	00009C
 */
void TRKGetFreeBuffer(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stmw      r27, 0xC(r1)
	  addi      r28, r4, 0
	  addi      r27, r3, 0
	  li        r31, 0x300
	  li        r30, 0
	  stw       r0, 0x0(r4)
	  b         .loc_0x7C

	.loc_0x2C:
	  mr        r3, r30
	  bl        .loc_0x9C
	  mr        r29, r3
	  bl        0x211C
	  lwz       r0, 0x4(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0x70
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        0xE0
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        -0xDC
	  stw       r29, 0x0(r28)
	  li        r31, 0
	  stw       r30, 0x0(r27)
	  li        r30, 0x3

	.loc_0x70:
	  mr        r3, r29
	  bl        0x20E8
	  addi      r30, r30, 0x1

	.loc_0x7C:
	  cmpwi     r30, 0x3
	  blt+      .loc_0x2C
	  mr        r3, r31
	  lmw       r27, 0xC(r1)
	  addi      r1, r1, 0x20
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr

	.loc_0x9C:
	*/
}

/*
 * --INFO--
 * Address:	8021C5E8
 * Size:	00002C
 */
void TRKGetBuffer(void)
{
	/*
	.loc_0x0:
	  cmpwi     r3, 0
	  li        r0, 0
	  blt-      .loc_0x24
	  cmpwi     r3, 0x3
	  bge-      .loc_0x24
	  mulli     r4, r3, 0x890
	  lis       r3, 0x803D
	  addi      r0, r3, 0x4320
	  add       r0, r0, r4

	.loc_0x24:
	  mr        r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C614
 * Size:	000068
 */
void TRKReleaseBuffer(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r3, -0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  beq-      .loc_0x54
	  cmpwi     r3, 0
	  blt-      .loc_0x54
	  cmpwi     r3, 0x3
	  bge-      .loc_0x54
	  mulli     r4, r3, 0x890
	  lis       r3, 0x803D
	  addi      r0, r3, 0x4320
	  add       r31, r0, r4
	  addi      r3, r31, 0
	  bl        0x2050
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x190
	  mr        r3, r31
	  bl        0x2044

	.loc_0x54:
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C67C
 * Size:	000040
 */
void TRKResetBuffer(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,31
	  stwu      r1, -0x8(r1)
	  stw       r5, 0x8(r3)
	  stw       r5, 0xC(r3)
	  bne-      .loc_0x30
	  addi      r3, r3, 0x10
	  li        r4, 0
	  li        r5, 0x880
	  bl        -0x219220

	.loc_0x30:
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C6BC
 * Size:	000030
 */
void TRKSetBufferPosition(void)
{
	/*
	.loc_0x0:
	  cmplwi    r4, 0x880
	  li        r5, 0
	  ble-      .loc_0x14
	  li        r5, 0x301
	  b         .loc_0x28

	.loc_0x14:
	  stw       r4, 0xC(r3)
	  lwz       r0, 0x8(r3)
	  cmplw     r4, r0
	  ble-      .loc_0x28
	  stw       r4, 0x8(r3)

	.loc_0x28:
	  mr        r3, r5
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C6EC
 * Size:	0000A4
 */
void TRKAppendBuffer(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r5
	  stw       r29, 0xC(r1)
	  addi      r29, r3, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x88

	.loc_0x30:
	  lwz       r3, 0xC(r29)
	  subfic    r0, r3, 0x880
	  cmplw     r0, r30
	  bge-      .loc_0x48
	  li        r31, 0x301
	  mr        r30, r0

	.loc_0x48:
	  cmplwi    r30, 0x1
	  bne-      .loc_0x60
	  lbz       r0, 0x0(r4)
	  add       r3, r29, r3
	  stb       r0, 0x10(r3)
	  b         .loc_0x70

	.loc_0x60:
	  addi      r3, r3, 0x10
	  addi      r5, r30, 0
	  add       r3, r29, r3
	  bl        -0x2192F4

	.loc_0x70:
	  lwz       r0, 0xC(r29)
	  addi      r3, r31, 0
	  add       r0, r0, r30
	  stw       r0, 0xC(r29)
	  lwz       r0, 0xC(r29)
	  stw       r0, 0x8(r29)

	.loc_0x88:
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  lwz       r29, 0xC(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C790
 * Size:	00008C
 */
void TRKReadBuffer(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r5
	  stw       r29, 0xC(r1)
	  addi      r29, r3, 0
	  addi      r3, r4, 0
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x70

	.loc_0x34:
	  lwz       r4, 0xC(r29)
	  lwz       r0, 0x8(r29)
	  sub       r0, r0, r4
	  cmplw     r30, r0
	  ble-      .loc_0x50
	  li        r31, 0x302
	  mr        r30, r0

	.loc_0x50:
	  addi      r4, r4, 0x10
	  addi      r5, r30, 0
	  add       r4, r29, r4
	  bl        -0x219388
	  lwz       r0, 0xC(r29)
	  addi      r3, r31, 0
	  add       r0, r0, r30
	  stw       r0, 0xC(r29)

	.loc_0x70:
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  lwz       r29, 0xC(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C81C
 * Size:	000054
 */
void TRKAppendBuffer1_ui16(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  sth       r4, 0x8(r1)
	  lwz       r0, 0x4318(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x28
	  addi      r4, r1, 0x8
	  b         .loc_0x3C

	.loc_0x28:
	  lbz       r0, 0x9(r1)
	  addi      r4, r1, 0xC
	  stb       r0, 0xC(r1)
	  lbz       r0, 0x8(r1)
	  stb       r0, 0xD(r1)

	.loc_0x3C:
	  li        r5, 0x2
	  bl        -0x170
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C870
 * Size:	000064
 */
void TRKAppendBuffer1_ui32(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r4, 0x8(r1)
	  lwz       r0, 0x4318(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x28
	  addi      r4, r1, 0x8
	  b         .loc_0x4C

	.loc_0x28:
	  lbz       r0, 0xB(r1)
	  addi      r4, r1, 0xC
	  stb       r0, 0xC(r1)
	  lbz       r0, 0xA(r1)
	  stb       r0, 0xD(r1)
	  lbz       r0, 0x9(r1)
	  stb       r0, 0xE(r1)
	  lbz       r0, 0x8(r1)
	  stb       r0, 0xF(r1)

	.loc_0x4C:
	  li        r5, 0x4
	  bl        -0x1D4
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021C8D4
 * Size:	000088
 */
void TRKAppendBuffer1_ui64(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r5, 0x8(r1)
	  stw       r6, 0xC(r1)
	  lwz       r0, 0x4318(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x2C
	  addi      r4, r1, 0x8
	  b         .loc_0x70

	.loc_0x2C:
	  lbz       r0, 0xF(r1)
	  addi      r4, r1, 0x10
	  stb       r0, 0x10(r1)
	  lbz       r0, 0xE(r1)
	  stb       r0, 0x11(r1)
	  lbz       r0, 0xD(r1)
	  stb       r0, 0x12(r1)
	  lbz       r0, 0xC(r1)
	  stb       r0, 0x13(r1)
	  lbz       r0, 0xB(r1)
	  stb       r0, 0x14(r1)
	  lbz       r0, 0xA(r1)
	  stb       r0, 0x15(r1)
	  lbz       r0, 0x9(r1)
	  stb       r0, 0x16(r1)
	  lbz       r0, 0x8(r1)
	  stb       r0, 0x17(r1)

	.loc_0x70:
	  li        r5, 0x8
	  bl        -0x25C
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void TRKAppendBuffer1_ui128(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021C95C
 * Size:	000068
 */
void TRKAppendBuffer_ui8(void)
{
	/*
	.loc_0x0:
	  li        r9, 0
	  li        r0, 0
	  b         .loc_0x50

	.loc_0xC:
	  lwz       r7, 0xC(r3)
	  lbz       r8, 0x0(r4)
	  cmplwi    r7, 0x880
	  blt-      .loc_0x24
	  li        r7, 0x301
	  b         .loc_0x44

	.loc_0x24:
	  addi      r6, r7, 0x1
	  addi      r0, r7, 0x10
	  stw       r6, 0xC(r3)
	  li        r7, 0
	  stbx      r8, r3, r0
	  lwz       r6, 0x8(r3)
	  addi      r0, r6, 0x1
	  stw       r0, 0x8(r3)

	.loc_0x44:
	  addi      r0, r7, 0
	  addi      r9, r9, 0x1
	  addi      r4, r4, 0x1

	.loc_0x50:
	  cmpwi     r0, 0
	  bne-      .loc_0x60
	  cmpw      r9, r5
	  blt+      .loc_0xC

	.loc_0x60:
	  mr        r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void TRKAppendBuffer_ui16(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021C9C4
 * Size:	00007C
 */
void TRKAppendBuffer_ui32(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  li        r30, 0
	  rlwinm    r0,r30,2,0,29
	  stw       r29, 0xC(r1)
	  add       r31, r4, r0
	  addi      r29, r5, 0
	  stw       r28, 0x8(r1)
	  addi      r28, r3, 0
	  li        r3, 0
	  b         .loc_0x4C

	.loc_0x38:
	  mr        r3, r28
	  lwz       r4, 0x0(r31)
	  bl        -0x194
	  addi      r30, r30, 0x1
	  addi      r31, r31, 0x4

	.loc_0x4C:
	  cmpwi     r3, 0
	  bne-      .loc_0x5C
	  cmpw      r30, r29
	  blt+      .loc_0x38

	.loc_0x5C:
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  lwz       r29, 0xC(r1)
	  lwz       r28, 0x8(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void TRKAppendBuffer_ui64(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void TRKAppendBuffer_ui128(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021CA40
 * Size:	000024
 */
void TRKReadBuffer1_ui8(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x2C0
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021CA64
 * Size:	000080
 */
void TRKReadBuffer1_ui16(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  lwz       r0, 0x4318(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x30
	  mr        r31, r30
	  b         .loc_0x34

	.loc_0x30:
	  addi      r31, r1, 0x8

	.loc_0x34:
	  addi      r4, r31, 0
	  li        r5, 0x2
	  bl        -0x310
	  lis       r4, 0x803D
	  lwz       r0, 0x4318(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x68
	  cmpwi     r3, 0
	  bne-      .loc_0x68
	  lbz       r0, 0x1(r31)
	  stb       r0, 0x0(r30)
	  lbz       r0, 0x0(r31)
	  stb       r0, 0x1(r30)

	.loc_0x68:
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021CAE4
 * Size:	000090
 */
void TRKReadBuffer1_ui32(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  lwz       r0, 0x4318(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x30
	  mr        r31, r30
	  b         .loc_0x34

	.loc_0x30:
	  addi      r31, r1, 0x8

	.loc_0x34:
	  addi      r4, r31, 0
	  li        r5, 0x4
	  bl        -0x390
	  lis       r4, 0x803D
	  lwz       r0, 0x4318(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x78
	  cmpwi     r3, 0
	  bne-      .loc_0x78
	  lbz       r0, 0x3(r31)
	  stb       r0, 0x0(r30)
	  lbz       r0, 0x2(r31)
	  stb       r0, 0x1(r30)
	  lbz       r0, 0x1(r31)
	  stb       r0, 0x2(r30)
	  lbz       r0, 0x0(r31)
	  stb       r0, 0x3(r30)

	.loc_0x78:
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021CB74
 * Size:	0000B0
 */
void TRKReadBuffer1_ui64(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  lwz       r0, 0x4318(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x30
	  mr        r31, r30
	  b         .loc_0x34

	.loc_0x30:
	  addi      r31, r1, 0x8

	.loc_0x34:
	  addi      r4, r31, 0
	  li        r5, 0x8
	  bl        -0x420
	  lis       r4, 0x803D
	  lwz       r0, 0x4318(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x98
	  cmpwi     r3, 0
	  bne-      .loc_0x98
	  lbz       r0, 0x7(r31)
	  stb       r0, 0x0(r30)
	  lbz       r0, 0x6(r31)
	  stb       r0, 0x1(r30)
	  lbz       r0, 0x5(r31)
	  stb       r0, 0x2(r30)
	  lbz       r0, 0x4(r31)
	  stb       r0, 0x3(r30)
	  lbz       r0, 0x3(r31)
	  stb       r0, 0x4(r30)
	  lbz       r0, 0x2(r31)
	  stb       r0, 0x5(r30)
	  lbz       r0, 0x1(r31)
	  stb       r0, 0x6(r30)
	  lbz       r0, 0x0(r31)
	  stb       r0, 0x7(r30)

	.loc_0x98:
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void TRKReadBuffer1_ui128(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021CC24
 * Size:	000074
 */
void TRKReadBuffer_ui8(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r5, 0
	  stw       r29, 0xC(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x8(r1)
	  addi      r28, r3, 0
	  li        r3, 0
	  b         .loc_0x44

	.loc_0x34:
	  addi      r3, r28, 0
	  add       r4, r29, r31
	  bl        -0x220
	  addi      r31, r31, 0x1

	.loc_0x44:
	  cmpwi     r3, 0
	  bne-      .loc_0x54
	  cmpw      r31, r30
	  blt+      .loc_0x34

	.loc_0x54:
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  lwz       r29, 0xC(r1)
	  lwz       r28, 0x8(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void TRKReadBuffer_ui16(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021CC98
 * Size:	00007C
 */
void TRKReadBuffer_ui32(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  li        r30, 0
	  rlwinm    r0,r30,2,0,29
	  stw       r29, 0xC(r1)
	  add       r31, r4, r0
	  addi      r29, r5, 0
	  stw       r28, 0x8(r1)
	  addi      r28, r3, 0
	  li        r3, 0
	  b         .loc_0x4C

	.loc_0x38:
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        -0x1F4
	  addi      r30, r30, 0x1
	  addi      r31, r31, 0x4

	.loc_0x4C:
	  cmpwi     r3, 0
	  bne-      .loc_0x5C
	  cmpw      r30, r29
	  blt+      .loc_0x38

	.loc_0x5C:
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  lwz       r29, 0xC(r1)
	  lwz       r28, 0x8(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void TRKReadBuffer_ui64(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void TRKReadBuffer_ui128(void)
{
	// UNUSED FUNCTION
}
