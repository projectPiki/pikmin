

/*
 * --INFO--
 * Address:	8021CF78
 * Size:	000098
 */
void TRKMessageIntoReply(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  li        r4, 0x1
	  stw       r29, 0xC(r1)
	  addi      r29, r3, 0
	  bl        -0x924
	  lwz       r3, 0xC(r29)
	  cmplwi    r3, 0x880
	  bge-      .loc_0x54
	  addi      r0, r3, 0x1
	  add       r3, r29, r3
	  stw       r0, 0xC(r29)
	  stb       r30, 0x10(r3)
	  lwz       r3, 0x8(r29)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r29)

	.loc_0x54:
	  lwz       r3, 0xC(r29)
	  cmplwi    r3, 0x880
	  bge-      .loc_0x7C
	  addi      r0, r3, 0x1
	  add       r3, r29, r3
	  stw       r0, 0xC(r29)
	  stb       r31, 0x10(r3)
	  lwz       r3, 0x8(r29)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r29)

	.loc_0x7C:
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
 * Address:	8021D010
 * Size:	000050
 */
void TRKSendACK(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  li        r31, 0x3
	  stw       r30, 0x8(r1)
	  addi      r30, r3, 0

	.loc_0x1C:
	  mr        r3, r30
	  bl        -0xB8C
	  cmpwi     r3, 0
	  subi      r31, r31, 0x1
	  beq-      .loc_0x38
	  cmpwi     r31, 0
	  bgt+      .loc_0x1C

	.loc_0x38:
	  lwz       r31, 0xC(r1)
	  lwz       r30, 0x8(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021D060
 * Size:	000034
 */
void TRKStandardACK(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  mr        r31, r3
	  bl        -0xFC
	  mr        r3, r31
	  bl        -0x6C
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void TRKDoError(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8021D094
 * Size:	000028
 */
void TRKDoUnsupported(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x80
	  stw       r0, 0x4(r1)
	  li        r5, 0x10
	  stwu      r1, -0x8(r1)
	  bl        -0x48
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021D0BC
 * Size:	000028
 */
void TRKDoConnect(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x80
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  stwu      r1, -0x8(r1)
	  bl        -0x70
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021D0E4
 * Size:	000050
 */
void TRKDoDisconnect(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x80
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  bl        -0x9C
	  mr.       r31, r3
	  bne-      .loc_0x38
	  addi      r3, r1, 0x8
	  li        r4, 0x1
	  bl        -0xE3C
	  addi      r3, r1, 0x8
	  bl        -0xF24

	.loc_0x38:
	  mr        r3, r31
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021D134
 * Size:	000030
 */
void TRKDoReset(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x80
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  stwu      r1, -0x8(r1)
	  bl        -0xE8
	  bl        -0x217D60
	  li        r3, 0
	  addi      r1, r1, 0x8
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021D164
 * Size:	000184
 */
void TRKDoVersions(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  mr        r31, r3
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x34
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x2
	  bl        -0x130
	  b         .loc_0x170

	.loc_0x34:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0
	  bl        -0x22C
	  addi      r3, r1, 0x8
	  bl        0x1F44
	  cmpwi     r3, 0
	  bne-      .loc_0x8C
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0x8(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0x6C
	  li        r3, 0x301
	  b         .loc_0x8C

	.loc_0x6C:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x8C:
	  cmpwi     r3, 0
	  bne-      .loc_0xCC
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0x9(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0xAC
	  li        r3, 0x301
	  b         .loc_0xCC

	.loc_0xAC:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xCC:
	  cmpwi     r3, 0
	  bne-      .loc_0x10C
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0xA(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0xEC
	  li        r3, 0x301
	  b         .loc_0x10C

	.loc_0xEC:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x10C:
	  cmpwi     r3, 0
	  bne-      .loc_0x14C
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0xB(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0x12C
	  li        r3, 0x301
	  b         .loc_0x14C

	.loc_0x12C:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x14C:
	  cmpwi     r3, 0
	  beq-      .loc_0x168
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x3
	  bl        -0x264
	  b         .loc_0x170

	.loc_0x168:
	  mr        r3, r31
	  bl        -0x2C0

	.loc_0x170:
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021D2E8
 * Size:	0000DC
 */
void TRKDoSupportMask(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x34
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x2
	  bl        -0x2B4
	  b         .loc_0xC8

	.loc_0x34:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0
	  bl        -0x3B0
	  addi      r3, r1, 0x8
	  bl        0x1DE8
	  cmpwi     r3, 0
	  bne-      .loc_0x64
	  addi      r3, r31, 0
	  addi      r4, r1, 0x8
	  li        r5, 0x20
	  bl        -0xC5C

	.loc_0x64:
	  cmpwi     r3, 0
	  bne-      .loc_0xA4
	  lwz       r3, 0xC(r31)
	  cmplwi    r3, 0x880
	  blt-      .loc_0x80
	  li        r3, 0x301
	  b         .loc_0xA4

	.loc_0x80:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r0, 0x2
	  li        r3, 0
	  stb       r0, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xA4:
	  cmpwi     r3, 0
	  beq-      .loc_0xC0
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x3
	  bl        -0x340
	  b         .loc_0xC8

	.loc_0xC0:
	  mr        r3, r31
	  bl        -0x39C

	.loc_0xC8:
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021D3C4
 * Size:	000244
 */
void TRKDoCPUType(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0x1
	  beq-      .loc_0x34
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x2
	  bl        -0x390
	  b         .loc_0x230

	.loc_0x34:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0
	  bl        -0x48C
	  addi      r3, r1, 0x8
	  bl        0x1DB0
	  cmpwi     r3, 0
	  bne-      .loc_0x8C
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0x8(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0x6C
	  li        r3, 0x301
	  b         .loc_0x8C

	.loc_0x6C:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x8C:
	  cmpwi     r3, 0
	  bne-      .loc_0xCC
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0x9(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0xAC
	  li        r3, 0x301
	  b         .loc_0xCC

	.loc_0xAC:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xCC:
	  cmpwi     r3, 0
	  bne-      .loc_0x10C
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0xA(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0xEC
	  li        r3, 0x301
	  b         .loc_0x10C

	.loc_0xEC:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x10C:
	  cmpwi     r3, 0
	  bne-      .loc_0x14C
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0xB(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0x12C
	  li        r3, 0x301
	  b         .loc_0x14C

	.loc_0x12C:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x14C:
	  cmpwi     r3, 0
	  bne-      .loc_0x18C
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0xC(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0x16C
	  li        r3, 0x301
	  b         .loc_0x18C

	.loc_0x16C:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x18C:
	  cmpwi     r3, 0
	  bne-      .loc_0x1CC
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0xD(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0x1AC
	  li        r3, 0x301
	  b         .loc_0x1CC

	.loc_0x1AC:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x1CC:
	  cmpwi     r3, 0
	  bne-      .loc_0x20C
	  lwz       r3, 0xC(r31)
	  lbz       r5, 0xE(r1)
	  cmplwi    r3, 0x880
	  blt-      .loc_0x1EC
	  li        r3, 0x301
	  b         .loc_0x20C

	.loc_0x1EC:
	  addi      r0, r3, 0x1
	  add       r4, r31, r3
	  stw       r0, 0xC(r31)
	  li        r3, 0
	  stb       r5, 0x10(r4)
	  lwz       r4, 0x8(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x20C:
	  cmpwi     r3, 0
	  beq-      .loc_0x228
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x3
	  bl        -0x584
	  b         .loc_0x230

	.loc_0x228:
	  mr        r3, r31
	  bl        -0x5E0

	.loc_0x230:
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021D608
 * Size:	0001E8
 */
void TRKDoReadMemory(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x820(r1)
	  stw       r31, 0x81C(r1)
	  mr        r31, r3
	  stw       r30, 0x818(r1)
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0x8
	  beq-      .loc_0x38
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x2
	  bl        -0x5D8
	  b         .loc_0x1D0

	.loc_0x38:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0xF8C
	  addi      r3, r31, 0
	  addi      r4, r1, 0x8
	  bl        -0xC14
	  mr.       r30, r3
	  bne-      .loc_0x68
	  addi      r3, r31, 0
	  addi      r4, r1, 0x9
	  bl        -0xC28
	  mr        r30, r3

	.loc_0x68:
	  cmpwi     r30, 0
	  bne-      .loc_0x80
	  addi      r3, r31, 0
	  addi      r4, r1, 0xA
	  bl        -0xC1C
	  mr        r30, r3

	.loc_0x80:
	  cmpwi     r30, 0
	  bne-      .loc_0x98
	  addi      r3, r31, 0
	  addi      r4, r1, 0xC
	  bl        -0xBB4
	  mr        r30, r3

	.loc_0x98:
	  lbz       r0, 0x9(r1)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0xB8
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x12
	  bl        -0x658
	  b         .loc_0x1D0

	.loc_0xB8:
	  lhz       r0, 0xA(r1)
	  cmplwi    r0, 0x800
	  ble-      .loc_0xD8
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x11
	  bl        -0x678
	  b         .loc_0x1D0

	.loc_0xD8:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0
	  bl        -0x774
	  cmpwi     r30, 0
	  bne-      .loc_0x160
	  lbz       r0, 0x9(r1)
	  lhz       r3, 0xA(r1)
	  rlwinm.   r0,r0,0,28,28
	  stw       r3, 0x10(r1)
	  beq-      .loc_0x10C
	  li        r6, 0
	  b         .loc_0x110

	.loc_0x10C:
	  li        r6, 0x1

	.loc_0x110:
	  lwz       r4, 0xC(r1)
	  addi      r3, r1, 0x14
	  addi      r5, r1, 0x10
	  li        r7, 0x1
	  bl        0x12E0
	  lwz       r0, 0x10(r1)
	  mr.       r30, r3
	  sth       r0, 0xA(r1)
	  bne-      .loc_0x144
	  mr        r3, r31
	  lhz       r4, 0xA(r1)
	  bl        -0xF28
	  mr        r30, r3

	.loc_0x144:
	  cmpwi     r30, 0
	  bne-      .loc_0x160
	  lwz       r5, 0x10(r1)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x14
	  bl        -0x1074
	  mr        r30, r3

	.loc_0x160:
	  cmpwi     r30, 0
	  beq-      .loc_0x1C8
	  subi      r0, r30, 0x700
	  cmplwi    r0, 0x6
	  bgt-      .loc_0x1B4
	  lis       r3, 0x802F
	  subi      r3, r3, 0x6AB8
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  li        r5, 0x15
	  b         .loc_0x1B8
	  li        r5, 0x13
	  b         .loc_0x1B8
	  li        r5, 0x21
	  b         .loc_0x1B8
	  li        r5, 0x22
	  b         .loc_0x1B8
	  li        r5, 0x20
	  b         .loc_0x1B8

	.loc_0x1B4:
	  li        r5, 0x3

	.loc_0x1B8:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  bl        -0x768
	  b         .loc_0x1D0

	.loc_0x1C8:
	  mr        r3, r31
	  bl        -0x7C4

	.loc_0x1D0:
	  lwz       r31, 0x81C(r1)
	  lwz       r30, 0x818(r1)
	  addi      r1, r1, 0x820
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021D7F0
 * Size:	0001FC
 */
void TRKDoWriteMemory(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x820(r1)
	  stw       r31, 0x81C(r1)
	  mr        r31, r3
	  stw       r30, 0x818(r1)
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0x8
	  bgt-      .loc_0x38
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x2
	  bl        -0x7C0
	  b         .loc_0x1E4

	.loc_0x38:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x1174
	  addi      r3, r31, 0
	  addi      r4, r1, 0x8
	  bl        -0xDFC
	  mr.       r30, r3
	  bne-      .loc_0x68
	  addi      r3, r31, 0
	  addi      r4, r1, 0x9
	  bl        -0xE10
	  mr        r30, r3

	.loc_0x68:
	  cmpwi     r30, 0
	  bne-      .loc_0x80
	  addi      r3, r31, 0
	  addi      r4, r1, 0xA
	  bl        -0xE04
	  mr        r30, r3

	.loc_0x80:
	  cmpwi     r30, 0
	  bne-      .loc_0x98
	  addi      r3, r31, 0
	  addi      r4, r1, 0xC
	  bl        -0xD9C
	  mr        r30, r3

	.loc_0x98:
	  lbz       r0, 0x9(r1)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0xB8
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x12
	  bl        -0x840
	  b         .loc_0x1E4

	.loc_0xB8:
	  lhz       r4, 0xA(r1)
	  lwz       r3, 0x8(r31)
	  addi      r0, r4, 0x8
	  cmplw     r3, r0
	  bne-      .loc_0xD4
	  cmplwi    r4, 0x800
	  ble-      .loc_0xE8

	.loc_0xD4:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x11
	  bl        -0x870
	  b         .loc_0x1E4

	.loc_0xE8:
	  cmpwi     r30, 0
	  bne-      .loc_0x144
	  stw       r4, 0x10(r1)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x14
	  lwz       r5, 0x10(r1)
	  bl        -0x1160
	  mr.       r30, r3
	  bne-      .loc_0x13C
	  lbz       r0, 0x9(r1)
	  rlwinm.   r0,r0,0,28,28
	  beq-      .loc_0x120
	  li        r6, 0
	  b         .loc_0x124

	.loc_0x120:
	  li        r6, 0x1

	.loc_0x124:
	  lwz       r4, 0xC(r1)
	  addi      r3, r1, 0x14
	  addi      r5, r1, 0x10
	  li        r7, 0
	  bl        0x10E4
	  mr        r30, r3

	.loc_0x13C:
	  lwz       r0, 0x10(r1)
	  sth       r0, 0xA(r1)

	.loc_0x144:
	  cmpwi     r30, 0
	  bne-      .loc_0x15C
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0
	  bl        -0x9D0

	.loc_0x15C:
	  cmpwi     r30, 0
	  bne-      .loc_0x174
	  mr        r3, r31
	  lhz       r4, 0xA(r1)
	  bl        -0x1140
	  mr        r30, r3

	.loc_0x174:
	  cmpwi     r30, 0
	  beq-      .loc_0x1DC
	  subi      r0, r30, 0x700
	  cmplwi    r0, 0x6
	  bgt-      .loc_0x1C8
	  lis       r3, 0x802F
	  subi      r3, r3, 0x6A9C
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  li        r5, 0x15
	  b         .loc_0x1CC
	  li        r5, 0x13
	  b         .loc_0x1CC
	  li        r5, 0x21
	  b         .loc_0x1CC
	  li        r5, 0x22
	  b         .loc_0x1CC
	  li        r5, 0x20
	  b         .loc_0x1CC

	.loc_0x1C8:
	  li        r5, 0x3

	.loc_0x1CC:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  bl        -0x964
	  b         .loc_0x1E4

	.loc_0x1DC:
	  mr        r3, r31
	  bl        -0x9C0

	.loc_0x1E4:
	  lwz       r31, 0x81C(r1)
	  lwz       r30, 0x818(r1)
	  addi      r1, r1, 0x820
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021D9EC
 * Size:	000204
 */
void TRKDoReadRegisters(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0x6
	  beq-      .loc_0x34
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x2
	  bl        -0x9B8
	  b         .loc_0x1F0

	.loc_0x34:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x136C
	  addi      r3, r31, 0
	  addi      r4, r1, 0x8
	  bl        -0xFF4
	  cmpwi     r3, 0
	  bne-      .loc_0x60
	  addi      r3, r31, 0
	  addi      r4, r1, 0x9
	  bl        -0x1008

	.loc_0x60:
	  cmpwi     r3, 0
	  bne-      .loc_0x74
	  addi      r3, r31, 0
	  addi      r4, r1, 0xA
	  bl        -0xFF8

	.loc_0x74:
	  cmpwi     r3, 0
	  bne-      .loc_0x88
	  addi      r3, r31, 0
	  addi      r4, r1, 0xC
	  bl        -0x100C

	.loc_0x88:
	  lhz       r4, 0xA(r1)
	  lhz       r0, 0xC(r1)
	  cmplw     r4, r0
	  ble-      .loc_0xAC
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x14
	  bl        -0xA30
	  b         .loc_0x1F0

	.loc_0xAC:
	  cmpwi     r3, 0
	  bne-      .loc_0xC4
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0
	  bl        -0xB34

	.loc_0xC4:
	  lbz       r0, 0x9(r1)
	  rlwinm    r0,r0,0,29,31
	  cmpwi     r0, 0x2
	  beq-      .loc_0x12C
	  bge-      .loc_0xE8
	  cmpwi     r0, 0
	  beq-      .loc_0xF4
	  bge-      .loc_0x110
	  b         .loc_0x164

	.loc_0xE8:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x164
	  b         .loc_0x148

	.loc_0xF4:
	  lhz       r3, 0xA(r1)
	  mr        r5, r31
	  lhz       r4, 0xC(r1)
	  addi      r6, r1, 0x10
	  li        r7, 0x1
	  bl        0x10C4
	  b         .loc_0x168

	.loc_0x110:
	  lhz       r3, 0xA(r1)
	  mr        r5, r31
	  lhz       r4, 0xC(r1)
	  addi      r6, r1, 0x10
	  li        r7, 0x1
	  bl        0x11A4
	  b         .loc_0x168

	.loc_0x12C:
	  lhz       r3, 0xA(r1)
	  mr        r5, r31
	  lhz       r4, 0xC(r1)
	  addi      r6, r1, 0x10
	  li        r7, 0x1
	  bl        0x12D0
	  b         .loc_0x168

	.loc_0x148:
	  lhz       r3, 0xA(r1)
	  mr        r5, r31
	  lhz       r4, 0xC(r1)
	  addi      r6, r1, 0x10
	  li        r7, 0x1
	  bl        0x142C
	  b         .loc_0x168

	.loc_0x164:
	  li        r3, 0x703

	.loc_0x168:
	  cmpwi     r3, 0
	  beq-      .loc_0x1E8
	  cmpwi     r3, 0x704
	  beq-      .loc_0x1BC
	  bge-      .loc_0x194
	  cmpwi     r3, 0x702
	  beq-      .loc_0x1B4
	  bge-      .loc_0x1A4
	  cmpwi     r3, 0x701
	  bge-      .loc_0x1AC
	  b         .loc_0x1D4

	.loc_0x194:
	  cmpwi     r3, 0x706
	  beq-      .loc_0x1CC
	  bge-      .loc_0x1D4
	  b         .loc_0x1C4

	.loc_0x1A4:
	  li        r5, 0x12
	  b         .loc_0x1D8

	.loc_0x1AC:
	  li        r5, 0x14
	  b         .loc_0x1D8

	.loc_0x1B4:
	  li        r5, 0x15
	  b         .loc_0x1D8

	.loc_0x1BC:
	  li        r5, 0x21
	  b         .loc_0x1D8

	.loc_0x1C4:
	  li        r5, 0x22
	  b         .loc_0x1D8

	.loc_0x1CC:
	  li        r5, 0x20
	  b         .loc_0x1D8

	.loc_0x1D4:
	  li        r5, 0x3

	.loc_0x1D8:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  bl        -0xB6C
	  b         .loc_0x1F0

	.loc_0x1E8:
	  mr        r3, r31
	  bl        -0xBC8

	.loc_0x1F0:
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021DBF0
 * Size:	000208
 */
void TRKDoWriteRegisters(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0x6
	  bgt-      .loc_0x38
	  addi      r3, r30, 0
	  li        r4, 0x80
	  li        r5, 0x2
	  bl        -0xBC0
	  b         .loc_0x1F0

	.loc_0x38:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x1574
	  addi      r3, r30, 0
	  addi      r4, r1, 0x8
	  bl        -0x11FC
	  cmpwi     r3, 0
	  bne-      .loc_0x64
	  addi      r3, r30, 0
	  addi      r4, r1, 0x9
	  bl        -0x1210

	.loc_0x64:
	  cmpwi     r3, 0
	  bne-      .loc_0x78
	  addi      r3, r30, 0
	  addi      r4, r1, 0xA
	  bl        -0x1200

	.loc_0x78:
	  cmpwi     r3, 0
	  bne-      .loc_0x8C
	  addi      r3, r30, 0
	  addi      r4, r1, 0xC
	  bl        -0x1214

	.loc_0x8C:
	  lhz       r3, 0xA(r1)
	  lhz       r4, 0xC(r1)
	  cmplw     r3, r4
	  ble-      .loc_0xB0
	  addi      r3, r30, 0
	  li        r4, 0x80
	  li        r5, 0x14
	  bl        -0xC38
	  b         .loc_0x1F0

	.loc_0xB0:
	  lbz       r0, 0x9(r1)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x10C
	  bge-      .loc_0xD0
	  cmpwi     r0, 0
	  beq-      .loc_0xDC
	  bge-      .loc_0xF4
	  b         .loc_0x13C

	.loc_0xD0:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x13C
	  b         .loc_0x124

	.loc_0xDC:
	  addi      r6, r1, 0x10
	  addi      r5, r30, 0
	  li        r7, 0
	  bl        0xEE0
	  mr        r31, r3
	  b         .loc_0x140

	.loc_0xF4:
	  addi      r6, r1, 0x10
	  addi      r5, r30, 0
	  li        r7, 0
	  bl        0xFC4
	  mr        r31, r3
	  b         .loc_0x140

	.loc_0x10C:
	  addi      r6, r1, 0x10
	  addi      r5, r30, 0
	  li        r7, 0
	  bl        0x10F4
	  mr        r31, r3
	  b         .loc_0x140

	.loc_0x124:
	  addi      r6, r1, 0x10
	  addi      r5, r30, 0
	  li        r7, 0
	  bl        0x1254
	  mr        r31, r3
	  b         .loc_0x140

	.loc_0x13C:
	  li        r31, 0x703

	.loc_0x140:
	  cmpwi     r31, 0
	  bne-      .loc_0x158
	  addi      r3, r30, 0
	  li        r4, 0x80
	  li        r5, 0
	  bl        -0xDCC

	.loc_0x158:
	  cmpwi     r31, 0
	  beq-      .loc_0x1E8
	  cmpwi     r31, 0x703
	  beq-      .loc_0x19C
	  bge-      .loc_0x184
	  cmpwi     r31, 0x701
	  beq-      .loc_0x1A4
	  bge-      .loc_0x1B4
	  cmpwi     r31, 0x302
	  beq-      .loc_0x1AC
	  b         .loc_0x1D4

	.loc_0x184:
	  cmpwi     r31, 0x706
	  beq-      .loc_0x1CC
	  bge-      .loc_0x1D4
	  cmpwi     r31, 0x705
	  bge-      .loc_0x1C4
	  b         .loc_0x1BC

	.loc_0x19C:
	  li        r5, 0x12
	  b         .loc_0x1D8

	.loc_0x1A4:
	  li        r5, 0x14
	  b         .loc_0x1D8

	.loc_0x1AC:
	  li        r5, 0x2
	  b         .loc_0x1D8

	.loc_0x1B4:
	  li        r5, 0x15
	  b         .loc_0x1D8

	.loc_0x1BC:
	  li        r5, 0x21
	  b         .loc_0x1D8

	.loc_0x1C4:
	  li        r5, 0x22
	  b         .loc_0x1D8

	.loc_0x1CC:
	  li        r5, 0x20
	  b         .loc_0x1D8

	.loc_0x1D4:
	  li        r5, 0x3

	.loc_0x1D8:
	  addi      r3, r30, 0
	  li        r4, 0x80
	  bl        -0xD70
	  b         .loc_0x1F0

	.loc_0x1E8:
	  mr        r3, r30
	  bl        -0xDCC

	.loc_0x1F0:
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021DDF8
 * Size:	000138
 */
void TRKDoFlushCache(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0xA
	  beq-      .loc_0x38
	  addi      r3, r30, 0
	  li        r4, 0x80
	  li        r5, 0x2
	  bl        -0xDC8
	  b         .loc_0x120

	.loc_0x38:
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x177C
	  addi      r3, r30, 0
	  addi      r4, r1, 0x8
	  bl        -0x1404
	  mr.       r31, r3
	  bne-      .loc_0x68
	  addi      r3, r30, 0
	  addi      r4, r1, 0x9
	  bl        -0x1418
	  mr        r31, r3

	.loc_0x68:
	  cmpwi     r31, 0
	  bne-      .loc_0x80
	  addi      r3, r30, 0
	  addi      r4, r1, 0xC
	  bl        -0x138C
	  mr        r31, r3

	.loc_0x80:
	  cmpwi     r31, 0
	  bne-      .loc_0x98
	  addi      r3, r30, 0
	  addi      r4, r1, 0x10
	  bl        -0x13A4
	  mr        r31, r3

	.loc_0x98:
	  lwz       r4, 0xC(r1)
	  lwz       r5, 0x10(r1)
	  cmplw     r4, r5
	  ble-      .loc_0xBC
	  addi      r3, r30, 0
	  li        r4, 0x80
	  li        r5, 0x13
	  bl        -0xE4C
	  b         .loc_0x120

	.loc_0xBC:
	  cmpwi     r31, 0
	  bne-      .loc_0xD0
	  lbz       r3, 0x9(r1)
	  bl        0x1BFC
	  mr        r31, r3

	.loc_0xD0:
	  cmpwi     r31, 0
	  bne-      .loc_0xE8
	  addi      r3, r30, 0
	  li        r4, 0x80
	  li        r5, 0
	  bl        -0xF64

	.loc_0xE8:
	  cmpwi     r31, 0
	  beq-      .loc_0x118
	  cmpwi     r31, 0x703
	  beq-      .loc_0xFC
	  b         .loc_0x104

	.loc_0xFC:
	  li        r5, 0x12
	  b         .loc_0x108

	.loc_0x104:
	  li        r5, 0x3

	.loc_0x108:
	  addi      r3, r30, 0
	  li        r4, 0x80
	  bl        -0xEA8
	  b         .loc_0x120

	.loc_0x118:
	  mr        r3, r30
	  bl        -0xF04

	.loc_0x120:
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021DF30
 * Size:	000064
 */
void TRKDoContinue(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  mr        r31, r3
	  bl        0x1BB4
	  cmpwi     r3, 0
	  bne-      .loc_0x34
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x16
	  bl        -0xEFC
	  b         .loc_0x50

	.loc_0x34:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0
	  bl        -0xF10
	  cmpwi     r3, 0
	  bne-      .loc_0x50
	  bl        0x283C

	.loc_0x50:
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021DF94
 * Size:	000204
 */
void TRKDoStep(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0x3
	  bge-      .loc_0x34
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x2
	  bl        -0xF60
	  b         .loc_0x1F0

	.loc_0x34:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x1914
	  addi      r3, r31, 0
	  addi      r4, r1, 0x8
	  bl        -0x159C
	  cmpwi     r3, 0
	  bne-      .loc_0x60
	  addi      r3, r31, 0
	  addi      r4, r1, 0x9
	  bl        -0x15B0

	.loc_0x60:
	  lbz       r0, 0x9(r1)
	  cmpwi     r0, 0x10
	  beq-      .loc_0x94
	  bge-      .loc_0x88
	  cmpwi     r0, 0x1
	  beq-      .loc_0xC8
	  bge-      .loc_0x140
	  cmpwi     r0, 0
	  bge-      .loc_0x94
	  b         .loc_0x140

	.loc_0x88:
	  cmpwi     r0, 0x12
	  bge-      .loc_0x140
	  b         .loc_0xC8

	.loc_0x94:
	  cmpwi     r3, 0
	  bne-      .loc_0xA8
	  addi      r3, r31, 0
	  addi      r4, r1, 0xA
	  bl        -0x15F8

	.loc_0xA8:
	  lbz       r0, 0xA(r1)
	  cmplwi    r0, 0x1
	  bge-      .loc_0x154
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x11
	  bl        -0xFF4
	  b         .loc_0x1F0

	.loc_0xC8:
	  lwz       r0, 0x8(r31)
	  cmplwi    r0, 0xA
	  beq-      .loc_0xE8
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x2
	  bl        -0x1014
	  b         .loc_0x1F0

	.loc_0xE8:
	  cmpwi     r3, 0
	  bne-      .loc_0xFC
	  addi      r3, r31, 0
	  addi      r4, r1, 0xC
	  bl        -0x15A8

	.loc_0xFC:
	  cmpwi     r3, 0
	  bne-      .loc_0x110
	  addi      r3, r31, 0
	  addi      r4, r1, 0x10
	  bl        -0x15BC

	.loc_0x110:
	  bl        0x1918
	  lwz       r0, 0xC(r1)
	  cmplw     r3, r0
	  blt-      .loc_0x12C
	  lwz       r0, 0x10(r1)
	  cmplw     r3, r0
	  ble-      .loc_0x154

	.loc_0x12C:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x11
	  bl        -0x106C
	  b         .loc_0x1F0

	.loc_0x140:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x12
	  bl        -0x1080
	  b         .loc_0x1F0

	.loc_0x154:
	  bl        0x1A10
	  cmpwi     r3, 0
	  bne-      .loc_0x174
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0x16
	  bl        -0x10A0
	  b         .loc_0x1F0

	.loc_0x174:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  li        r5, 0
	  bl        -0x10B4
	  cmpwi     r3, 0
	  bne-      .loc_0x1F0
	  lbz       r0, 0x9(r1)
	  cmpwi     r0, 0x10
	  beq-      .loc_0x1C0
	  bge-      .loc_0x1B4
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1D8
	  bge-      .loc_0x1F0
	  cmpwi     r0, 0
	  bge-      .loc_0x1C0
	  b         .loc_0x1F0

	.loc_0x1B4:
	  cmpwi     r0, 0x12
	  bge-      .loc_0x1F0
	  b         .loc_0x1D8

	.loc_0x1C0:
	  subfic    r0, r0, 0x10
	  lbz       r3, 0xA(r1)
	  cntlzw    r0, r0
	  rlwinm    r4,r0,27,5,31
	  bl        0x17CC
	  b         .loc_0x1F0

	.loc_0x1D8:
	  subfic    r0, r0, 0x11
	  lwz       r3, 0xC(r1)
	  cntlzw    r0, r0
	  lwz       r4, 0x10(r1)
	  rlwinm    r5,r0,27,5,31
	  bl        0x17F4

	.loc_0x1F0:
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8021E198
 * Size:	000084
 */
void TRKDoStop(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  mr        r31, r3
	  bl        0x196C
	  cmpwi     r3, 0x704
	  beq-      .loc_0x48
	  bge-      .loc_0x30
	  cmpwi     r3, 0
	  beq-      .loc_0x40
	  b         .loc_0x60

	.loc_0x30:
	  cmpwi     r3, 0x706
	  beq-      .loc_0x58
	  bge-      .loc_0x60
	  b         .loc_0x50

	.loc_0x40:
	  li        r5, 0
	  b         .loc_0x64

	.loc_0x48:
	  li        r5, 0x21
	  b         .loc_0x64

	.loc_0x50:
	  li        r5, 0x22
	  b         .loc_0x64

	.loc_0x58:
	  li        r5, 0x20
	  b         .loc_0x64

	.loc_0x60:
	  li        r5, 0x1

	.loc_0x64:
	  addi      r3, r31, 0
	  li        r4, 0x80
	  bl        -0x11A4
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  lwz       r0, 0x4(r1)
	  mtlr      r0
	  blr
	*/
}
