

/*
 * --INFO--
 * Address:	8001EC3C
 * Size:	000360
 */
void init_global_constants(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lis       r3, 0x8039
	  li        r0, 0x80
	  subi      r3, r3, 0x4300
	  stw       r31, 0x14(r1)
	  mtctr     r0
	  addi      r4, r3, 0
	  li        r5, 0
	  li        r6, -0x80

	.loc_0x24:
	  cmpwi     r6, 0
	  bge-      .loc_0x34
	  li        r0, 0
	  b         .loc_0x48

	.loc_0x34:
	  cmpwi     r6, 0xFF
	  ble-      .loc_0x44
	  li        r0, 0xFF
	  b         .loc_0x48

	.loc_0x44:
	  rlwinm    r0,r6,0,24,31

	.loc_0x48:
	  addic.    r6, r6, 0x1
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1
	  bge-      .loc_0x60
	  li        r0, 0
	  b         .loc_0x74

	.loc_0x60:
	  cmpwi     r6, 0xFF
	  ble-      .loc_0x70
	  li        r0, 0xFF
	  b         .loc_0x74

	.loc_0x70:
	  rlwinm    r0,r6,0,24,31

	.loc_0x74:
	  addic.    r6, r6, 0x1
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1
	  addi      r5, r5, 0x1
	  bge-      .loc_0x90
	  li        r0, 0
	  b         .loc_0xA4

	.loc_0x90:
	  cmpwi     r6, 0xFF
	  ble-      .loc_0xA0
	  li        r0, 0xFF
	  b         .loc_0xA4

	.loc_0xA0:
	  rlwinm    r0,r6,0,24,31

	.loc_0xA4:
	  addic.    r6, r6, 0x1
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1
	  addi      r5, r5, 0x1
	  bge-      .loc_0xC0
	  li        r0, 0
	  b         .loc_0xD4

	.loc_0xC0:
	  cmpwi     r6, 0xFF
	  ble-      .loc_0xD0
	  li        r0, 0xFF
	  b         .loc_0xD4

	.loc_0xD0:
	  rlwinm    r0,r6,0,24,31

	.loc_0xD4:
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1
	  addi      r5, r5, 0x1
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x24
	  li        r4, 0x10
	  li        r0, 0x1000
	  divw      r11, r0, r4
	  li        r4, 0x2
	  rlwinm    r4,r4,4,0,27
	  divw      r10, r0, r4
	  li        r4, 0x3
	  rlwinm    r4,r4,4,0,27
	  divw      r9, r0, r4
	  li        r4, 0x4
	  rlwinm    r4,r4,4,0,27
	  divw      r8, r0, r4
	  li        r4, 0x5
	  rlwinm    r4,r4,4,0,27
	  divw      r7, r0, r4
	  li        r4, 0x6
	  rlwinm    r4,r4,4,0,27
	  divw      r6, r0, r4
	  li        r4, 0x7
	  rlwinm    r4,r4,4,0,27
	  divw      r5, r0, r4
	  li        r4, 0x8
	  rlwinm    r4,r4,4,0,27
	  divw      r4, r0, r4
	  li        r12, 0
	  stw       r12, 0x200(r3)
	  rlwinm    r11,r11,4,0,27
	  rlwinm    r10,r10,4,0,27
	  stw       r11, 0x204(r3)
	  rlwinm    r9,r9,4,0,27
	  rlwinm    r8,r8,4,0,27
	  stw       r10, 0x208(r3)
	  rlwinm    r7,r7,4,0,27
	  rlwinm    r6,r6,4,0,27
	  stw       r9, 0x20C(r3)
	  rlwinm    r5,r5,4,0,27
	  rlwinm    r4,r4,4,0,27
	  stw       r8, 0x210(r3)
	  li        r8, 0x9
	  stw       r7, 0x214(r3)
	  stw       r6, 0x218(r3)
	  stw       r5, 0x21C(r3)
	  stw       r4, 0x220(r3)
	  b         .loc_0x330

	.loc_0x198:
	  subfic    r4, r8, 0x10
	  cmpwi     r8, 0x10
	  mtctr     r4
	  bge-      .loc_0x1C0

	.loc_0x1A8:
	  divw      r4, r0, r5
	  rlwinm    r4,r4,4,0,27
	  stw       r4, 0x0(r6)
	  addi      r5, r5, 0x10
	  addi      r6, r6, 0x4
	  bdnz+     .loc_0x1A8

	.loc_0x1C0:
	  li        r4, 0
	  li        r0, 0x15
	  stw       r4, 0x240(r3)
	  mtctr     r0
	  addi      r12, r3, 0x244
	  li        r31, 0x1

	.loc_0x1D8:
	  li        r11, 0x1000
	  divw      r10, r11, r31
	  addi      r9, r31, 0x1
	  stw       r10, 0x0(r12)
	  divw      r9, r11, r9
	  addi      r8, r31, 0x2
	  stw       r9, 0x4(r12)
	  divw      r8, r11, r8
	  addi      r7, r31, 0x3
	  stw       r8, 0x8(r12)
	  divw      r7, r11, r7
	  addi      r6, r31, 0x4
	  stw       r7, 0xC(r12)
	  divw      r6, r11, r6
	  addi      r5, r31, 0x5
	  stw       r6, 0x10(r12)
	  divw      r5, r11, r5
	  addi      r4, r31, 0x6
	  stw       r5, 0x14(r12)
	  divw      r4, r11, r4
	  addi      r0, r31, 0x7
	  stw       r4, 0x18(r12)
	  divw      r0, r11, r0
	  addi      r9, r31, 0x9
	  stw       r0, 0x1C(r12)
	  addi      r8, r31, 0xA
	  addi      r7, r31, 0xB
	  addi      r6, r31, 0xC
	  addi      r5, r31, 0xD
	  addi      r4, r31, 0xE
	  addi      r0, r31, 0xF
	  addi      r31, r31, 0x8
	  divw      r10, r11, r31
	  divw      r9, r11, r9
	  stw       r10, 0x20(r12)
	  stw       r9, 0x24(r12)
	  divw      r8, r11, r8
	  stw       r8, 0x28(r12)
	  divw      r7, r11, r7
	  stw       r7, 0x2C(r12)
	  divw      r6, r11, r6
	  stw       r6, 0x30(r12)
	  divw      r5, r11, r5
	  stw       r5, 0x34(r12)
	  divw      r4, r11, r4
	  stw       r4, 0x38(r12)
	  divw      r0, r11, r0
	  addi      r9, r31, 0x9
	  stw       r0, 0x3C(r12)
	  addi      r8, r31, 0xA
	  addi      r7, r31, 0xB
	  addi      r6, r31, 0xC
	  addi      r5, r31, 0xD
	  addi      r4, r31, 0xE
	  addi      r0, r31, 0xF
	  addi      r31, r31, 0x8
	  divw      r10, r11, r31
	  divw      r9, r11, r9
	  stw       r10, 0x40(r12)
	  divw      r8, r11, r8
	  stw       r9, 0x44(r12)
	  divw      r7, r11, r7
	  stw       r8, 0x48(r12)
	  divw      r6, r11, r6
	  stw       r7, 0x4C(r12)
	  divw      r5, r11, r5
	  stw       r6, 0x50(r12)
	  divw      r4, r11, r4
	  stw       r5, 0x54(r12)
	  divw      r0, r11, r0
	  stw       r4, 0x58(r12)
	  stw       r0, 0x5C(r12)
	  addi      r12, r12, 0x60
	  addi      r31, r31, 0x8
	  bdnz+     .loc_0x1D8
	  b         .loc_0x344

	.loc_0x308:
	  subfic    r0, r31, 0x200
	  cmpwi     r31, 0x200
	  mtctr     r0
	  bge-      .loc_0x354

	.loc_0x318:
	  divw      r0, r11, r31
	  stw       r0, 0x0(r3)
	  addi      r3, r3, 0x4
	  addi      r31, r31, 0x1
	  bdnz+     .loc_0x318
	  b         .loc_0x354

	.loc_0x330:
	  rlwinm    r4,r8,2,0,29
	  add       r6, r3, r4
	  rlwinm    r5,r8,4,0,27
	  addi      r6, r6, 0x200
	  b         .loc_0x198

	.loc_0x344:
	  rlwinm    r0,r31,2,0,29
	  add       r3, r3, r0
	  addi      r3, r3, 0x240
	  b         .loc_0x308

	.loc_0x354:
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void set_border(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001EF9C
 * Size:	00011C
 */
void setHVQPlaneDesc(void)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r5,0,24,31
	  lwz       r7, 0x0(r3)
	  mulli     r4, r4, 0x38
	  cmplwi    r0, 0x2
	  add       r4, r7, r4
	  bne-      .loc_0x20
	  li        r0, 0x1
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0

	.loc_0x24:
	  stb       r0, 0x30(r4)
	  rlwinm    r0,r6,0,24,31
	  cmplwi    r0, 0x2
	  lhz       r7, 0x4(r3)
	  lbz       r0, 0x30(r4)
	  sraw      r0, r7, r0
	  sth       r0, 0x28(r4)
	  bne-      .loc_0x4C
	  li        r0, 0x1
	  b         .loc_0x50

	.loc_0x4C:
	  li        r0, 0

	.loc_0x50:
	  stb       r0, 0x31(r4)
	  rlwinm    r8,r5,2,22,29
	  rlwinm    r7,r6,2,22,29
	  lhz       r9, 0x6(r3)
	  li        r10, 0x2
	  lbz       r0, 0x31(r4)
	  li        r6, 0
	  li        r5, 0x1
	  sraw      r0, r9, r0
	  sth       r0, 0x2A(r4)
	  li        r0, 0x4
	  lhz       r11, 0x28(r4)
	  lhz       r9, 0x2A(r4)
	  mullw     r9, r11, r9
	  stw       r9, 0x2C(r4)
	  lbz       r9, 0x30(r4)
	  sraw      r9, r10, r9
	  stb       r9, 0x32(r4)
	  lbz       r9, 0x31(r4)
	  sraw      r9, r10, r9
	  stb       r9, 0x33(r4)
	  lbz       r10, 0x32(r4)
	  lbz       r9, 0x33(r4)
	  mullw     r9, r10, r9
	  stb       r9, 0x34(r4)
	  lhz       r9, 0x4(r3)
	  divw      r8, r9, r8
	  sth       r8, 0x8(r4)
	  lhz       r3, 0x6(r3)
	  divw      r3, r3, r7
	  sth       r3, 0xA(r4)
	  lhz       r3, 0x8(r4)
	  addi      r3, r3, 0x2
	  sth       r3, 0xC(r4)
	  lhz       r3, 0xA(r4)
	  addi      r3, r3, 0x2
	  sth       r3, 0xE(r4)
	  sth       r6, 0x10(r4)
	  sth       r5, 0x16(r4)
	  lhz       r3, 0xC(r4)
	  sth       r3, 0x12(r4)
	  addi      r3, r3, 0x1
	  sth       r3, 0x14(r4)
	  stw       r6, 0x18(r4)
	  stw       r0, 0x24(r4)
	  lhz       r0, 0x28(r4)
	  rlwinm    r3,r0,2,0,29
	  stw       r3, 0x1C(r4)
	  addi      r0, r3, 0x4
	  stw       r0, 0x20(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void setCode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001F0B8
 * Size:	0002CC
 */
void _readTree(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  mr        r29, r4
	  addi      r28, r3, 0
	  lwz       r4, 0xC(r4)
	  cmpwi     r4, 0
	  bge-      .loc_0x40
	  lwz       r3, 0x0(r29)
	  li        r4, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x0(r29)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x8(r29)
	  b         .loc_0x44

	.loc_0x40:
	  lwz       r0, 0x8(r29)

	.loc_0x44:
	  srw       r0, r0, r4
	  rlwinm.   r3,r0,0,31,31
	  subi      r0, r4, 0x1
	  stw       r0, 0xC(r29)
	  beq-      .loc_0x220
	  lwz       r31, 0x0(r28)
	  addi      r0, r31, 0x1
	  stw       r0, 0x0(r28)
	  lwz       r4, 0xC(r29)
	  cmpwi     r4, 0
	  bge-      .loc_0x8C
	  lwz       r3, 0x0(r29)
	  li        r4, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x0(r29)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x8(r29)
	  b         .loc_0x90

	.loc_0x8C:
	  lwz       r0, 0x8(r29)

	.loc_0x90:
	  srw       r0, r0, r4
	  rlwinm.   r3,r0,0,31,31
	  subi      r0, r4, 0x1
	  stw       r0, 0xC(r29)
	  beq-      .loc_0xE8
	  lwz       r27, 0x0(r28)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  addi      r0, r27, 0x1
	  stw       r0, 0x0(r28)
	  bl        .loc_0x0
	  rlwinm    r4,r27,2,0,29
	  extsh     r0, r3
	  add       r26, r28, r4
	  stw       r0, 0x8(r26)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        .loc_0x0
	  extsh     r0, r3
	  stw       r0, 0x808(r26)
	  extsh     r3, r27
	  b         .loc_0x130

	.loc_0xE8:
	  mr        r3, r29
	  bl        .loc_0x2CC
	  lwz       r0, 0x2DC0(r13)
	  addi      r5, r3, 0
	  cmpwi     r0, 0
	  beq-      .loc_0x110
	  extsh     r0, r3
	  cmpwi     r0, 0x7F
	  ble-      .loc_0x110
	  subi      r5, r5, 0x100

	.loc_0x110:
	  lwz       r4, 0x2DC4(r13)
	  extsh     r5, r5
	  extsh     r0, r3
	  slw       r4, r5, r4
	  rlwinm    r0,r0,2,0,29
	  extsh     r5, r4
	  add       r4, r28, r0
	  stw       r5, 0x8(r4)

	.loc_0x130:
	  rlwinm    r30,r31,2,0,29
	  extsh     r0, r3
	  add       r3, r28, r30
	  stw       r0, 0x8(r3)
	  lwz       r4, 0xC(r29)
	  cmpwi     r4, 0
	  bge-      .loc_0x168
	  lwz       r3, 0x0(r29)
	  li        r4, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x0(r29)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x8(r29)
	  b         .loc_0x16C

	.loc_0x168:
	  lwz       r0, 0x8(r29)

	.loc_0x16C:
	  srw       r0, r0, r4
	  rlwinm.   r3,r0,0,31,31
	  subi      r0, r4, 0x1
	  stw       r0, 0xC(r29)
	  beq-      .loc_0x1C4
	  lwz       r26, 0x0(r28)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  addi      r0, r26, 0x1
	  stw       r0, 0x0(r28)
	  bl        .loc_0x0
	  rlwinm    r4,r26,2,0,29
	  extsh     r0, r3
	  add       r27, r28, r4
	  stw       r0, 0x8(r27)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        .loc_0x0
	  extsh     r0, r3
	  stw       r0, 0x808(r27)
	  extsh     r3, r26
	  b         .loc_0x20C

	.loc_0x1C4:
	  mr        r3, r29
	  bl        .loc_0x2CC
	  lwz       r0, 0x2DC0(r13)
	  addi      r5, r3, 0
	  cmpwi     r0, 0
	  beq-      .loc_0x1EC
	  extsh     r0, r3
	  cmpwi     r0, 0x7F
	  ble-      .loc_0x1EC
	  subi      r5, r5, 0x100

	.loc_0x1EC:
	  lwz       r4, 0x2DC4(r13)
	  extsh     r5, r5
	  extsh     r0, r3
	  slw       r4, r5, r4
	  rlwinm    r0,r0,2,0,29
	  extsh     r5, r4
	  add       r4, r28, r0
	  stw       r5, 0x8(r4)

	.loc_0x20C:
	  extsh     r0, r3
	  add       r3, r28, r30
	  stw       r0, 0x808(r3)
	  extsh     r3, r31
	  b         .loc_0x2B8

	.loc_0x220:
	  lwz       r6, 0xC(r29)
	  cmpwi     r6, 0x7
	  blt-      .loc_0x240
	  lwz       r7, 0x8(r29)
	  subi      r0, r6, 0x7
	  subi      r6, r6, 0x8
	  srw       r7, r7, r0
	  b         .loc_0x274

	.loc_0x240:
	  lwz       r4, 0x0(r29)
	  subfic    r5, r6, 0x7
	  lwz       r7, 0x8(r29)
	  addi      r0, r6, 0x19
	  addi      r3, r4, 0x4
	  stw       r3, 0x0(r29)
	  slw       r7, r7, r5
	  addi      r6, r6, 0x18
	  lwz       r3, 0x0(r4)
	  stw       r3, 0x8(r29)
	  lwz       r3, 0x8(r29)
	  srw       r0, r3, r0
	  or        r7, r7, r0

	.loc_0x274:
	  stw       r6, 0xC(r29)
	  rlwinm    r7,r7,0,24,31
	  extsh     r3, r7
	  lwz       r0, 0x2DC0(r13)
	  addi      r5, r3, 0
	  cmpwi     r0, 0
	  beq-      .loc_0x29C
	  cmpwi     r3, 0x7F
	  ble-      .loc_0x29C
	  subi      r5, r5, 0x100

	.loc_0x29C:
	  lwz       r4, 0x2DC4(r13)
	  extsh     r5, r5
	  rlwinm    r0,r3,2,0,29
	  slw       r4, r5, r4
	  extsh     r5, r4
	  add       r4, r28, r0
	  stw       r5, 0x8(r4)

	.loc_0x2B8:
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr

	.loc_0x2CC:
	*/
}

/*
 * --INFO--
 * Address:	8001F384
 * Size:	000064
 */
void getByte(void)
{
	/*
	.loc_0x0:
	  lwz       r8, 0xC(r3)
	  cmpwi     r8, 0x7
	  blt-      .loc_0x20
	  lwz       r7, 0x8(r3)
	  subi      r0, r8, 0x7
	  subi      r8, r8, 0x8
	  srw       r7, r7, r0
	  b         .loc_0x54

	.loc_0x20:
	  lwz       r5, 0x0(r3)
	  subfic    r6, r8, 0x7
	  lwz       r7, 0x8(r3)
	  addi      r0, r8, 0x19
	  addi      r4, r5, 0x4
	  stw       r4, 0x0(r3)
	  slw       r7, r7, r6
	  addi      r8, r8, 0x18
	  lwz       r4, 0x0(r5)
	  stw       r4, 0x8(r3)
	  lwz       r4, 0x8(r3)
	  srw       r0, r4, r0
	  or        r7, r7, r0

	.loc_0x54:
	  stw       r8, 0xC(r3)
	  rlwinm    r7,r7,0,24,31
	  extsh     r3, r7
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
void readTree(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void decodeUOvfSym(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001F3E8
 * Size:	0002C4
 */
void Ipic_BasisNumDec(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x48(r1)
	  addi      r6, r3, 0x618C
	  addi      r7, r3, 0x61B4
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  li        r30, 0
	  lwz       r4, 0x4(r3)
	  lhz       r0, 0x8(r3)
	  lhz       r5, 0xA(r3)
	  b         .loc_0x148

	.loc_0x28:
	  cmpwi     r0, 0
	  mtctr     r0
	  ble-      .loc_0x140

	.loc_0x34:
	  cmpwi     r30, 0
	  bne-      .loc_0x12C
	  lwz       r12, 0x10(r6)
	  lwz       r10, 0x4(r12)
	  b         .loc_0x94

	.loc_0x48:
	  lwz       r11, 0xC(r6)
	  cmpwi     r11, 0
	  bge-      .loc_0x70
	  lwz       r9, 0x0(r6)
	  li        r11, 0x1F
	  addi      r8, r9, 0x4
	  stw       r8, 0x0(r6)
	  lwz       r8, 0x0(r9)
	  stw       r8, 0x8(r6)
	  b         .loc_0x74

	.loc_0x70:
	  lwz       r8, 0x8(r6)

	.loc_0x74:
	  srw       r9, r8, r11
	  subi      r8, r11, 0x1
	  stw       r8, 0xC(r6)
	  rlwinm    r9,r9,11,20,20
	  rlwinm    r8,r10,2,0,29
	  add       r8, r9, r8
	  addi      r8, r8, 0x8
	  lwzx      r10, r12, r8

	.loc_0x94:
	  cmpwi     r10, 0x100
	  bge+      .loc_0x48
	  rlwinm    r8,r10,2,0,29
	  addi      r8, r8, 0x8
	  lwzx      r8, r12, r8
	  extsh     r31, r8
	  extsh.    r8, r31
	  bne-      .loc_0x120
	  lwz       r12, 0x10(r7)
	  lwz       r10, 0x4(r12)
	  b         .loc_0x10C

	.loc_0xC0:
	  lwz       r11, 0xC(r7)
	  cmpwi     r11, 0
	  bge-      .loc_0xE8
	  lwz       r9, 0x0(r7)
	  li        r11, 0x1F
	  addi      r8, r9, 0x4
	  stw       r8, 0x0(r7)
	  lwz       r8, 0x0(r9)
	  stw       r8, 0x8(r7)
	  b         .loc_0xEC

	.loc_0xE8:
	  lwz       r8, 0x8(r7)

	.loc_0xEC:
	  srw       r9, r8, r11
	  subi      r8, r11, 0x1
	  stw       r8, 0xC(r7)
	  rlwinm    r9,r9,11,20,20
	  rlwinm    r8,r10,2,0,29
	  add       r8, r9, r8
	  addi      r8, r8, 0x8
	  lwzx      r10, r12, r8

	.loc_0x10C:
	  cmpwi     r10, 0x100
	  bge+      .loc_0xC0
	  rlwinm    r8,r10,2,0,29
	  addi      r8, r8, 0x8
	  lwzx      r30, r12, r8

	.loc_0x120:
	  stb       r31, 0x1(r4)
	  addi      r4, r4, 0x2
	  b         .loc_0x13C

	.loc_0x12C:
	  li        r8, 0
	  stb       r8, 0x1(r4)
	  addi      r4, r4, 0x2
	  subi      r30, r30, 0x1

	.loc_0x13C:
	  bdnz+     .loc_0x34

	.loc_0x140:
	  addi      r4, r4, 0x4
	  subi      r5, r5, 0x1

	.loc_0x148:
	  cmpwi     r5, 0
	  bgt+      .loc_0x28
	  lwz       r7, 0x3C(r3)
	  addi      r4, r3, 0x61A0
	  lwz       r8, 0x74(r3)
	  addi      r5, r3, 0x61C8
	  lhz       r0, 0x40(r3)
	  lhz       r6, 0x42(r3)
	  li        r3, 0
	  b         .loc_0x2AC

	.loc_0x170:
	  cmpwi     r0, 0
	  mtctr     r0
	  ble-      .loc_0x2A0

	.loc_0x17C:
	  cmpwi     r3, 0
	  bne-      .loc_0x284
	  lwz       r31, 0x10(r4)
	  lwz       r11, 0x4(r31)
	  b         .loc_0x1DC

	.loc_0x190:
	  lwz       r12, 0xC(r4)
	  cmpwi     r12, 0
	  bge-      .loc_0x1B8
	  lwz       r10, 0x0(r4)
	  li        r12, 0x1F
	  addi      r9, r10, 0x4
	  stw       r9, 0x0(r4)
	  lwz       r9, 0x0(r10)
	  stw       r9, 0x8(r4)
	  b         .loc_0x1BC

	.loc_0x1B8:
	  lwz       r9, 0x8(r4)

	.loc_0x1BC:
	  srw       r10, r9, r12
	  subi      r9, r12, 0x1
	  stw       r9, 0xC(r4)
	  rlwinm    r10,r10,11,20,20
	  rlwinm    r9,r11,2,0,29
	  add       r9, r10, r9
	  addi      r9, r9, 0x8
	  lwzx      r11, r31, r9

	.loc_0x1DC:
	  cmpwi     r11, 0x100
	  bge+      .loc_0x190
	  rlwinm    r9,r11,2,0,29
	  addi      r9, r9, 0x8
	  lwzx      r9, r31, r9
	  extsh     r31, r9
	  extsh.    r9, r31
	  bne-      .loc_0x268
	  lwz       r12, 0x10(r5)
	  lwz       r10, 0x4(r12)
	  b         .loc_0x254

	.loc_0x208:
	  lwz       r11, 0xC(r5)
	  cmpwi     r11, 0
	  bge-      .loc_0x230
	  lwz       r9, 0x0(r5)
	  li        r11, 0x1F
	  addi      r3, r9, 0x4
	  stw       r3, 0x0(r5)
	  lwz       r3, 0x0(r9)
	  stw       r3, 0x8(r5)
	  b         .loc_0x234

	.loc_0x230:
	  lwz       r3, 0x8(r5)

	.loc_0x234:
	  srw       r9, r3, r11
	  subi      r3, r11, 0x1
	  stw       r3, 0xC(r5)
	  rlwinm    r9,r9,11,20,20
	  rlwinm    r3,r10,2,0,29
	  add       r3, r9, r3
	  addi      r3, r3, 0x8
	  lwzx      r10, r12, r3

	.loc_0x254:
	  cmpwi     r10, 0x100
	  bge+      .loc_0x208
	  rlwinm    r3,r10,2,0,29
	  addi      r3, r3, 0x8
	  lwzx      r3, r12, r3

	.loc_0x268:
	  rlwinm    r9,r31,0,28,31
	  stb       r9, 0x1(r7)
	  rlwinm    r9,r31,28,28,31
	  addi      r7, r7, 0x2
	  stb       r9, 0x1(r8)
	  addi      r8, r8, 0x2
	  b         .loc_0x29C

	.loc_0x284:
	  li        r9, 0
	  stb       r9, 0x1(r7)
	  subi      r3, r3, 0x1
	  addi      r7, r7, 0x2
	  stb       r9, 0x1(r8)
	  addi      r8, r8, 0x2

	.loc_0x29C:
	  bdnz+     .loc_0x17C

	.loc_0x2A0:
	  addi      r7, r7, 0x4
	  addi      r8, r8, 0x4
	  subi      r6, r6, 0x1

	.loc_0x2AC:
	  cmpwi     r6, 0
	  bgt+      .loc_0x170
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x48
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001F6AC
 * Size:	00013C
 */
void IpicDcvDec(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stmw      r15, 0x24(r1)
	  li        r15, 0
	  addi      r19, r3, 0
	  mulli     r0, r15, 0x14
	  addi      r28, r19, 0
	  add       r27, r19, r0

	.loc_0x24:
	  lhz       r0, 0xC(r28)
	  addi      r30, r27, 0x60D8
	  lhz       r22, 0x8(r28)
	  addi      r29, r27, 0x6114
	  lwz       r26, 0x4(r28)
	  lhz       r20, 0xA(r28)
	  rlwinm    r31,r0,1,0,30
	  li        r24, 0
	  b         .loc_0x10C

	.loc_0x48:
	  sub       r25, r26, r31
	  lbz       r23, 0x0(r25)
	  mr        r21, r22
	  b         .loc_0xFC

	.loc_0x58:
	  cmpwi     r24, 0
	  bne-      .loc_0xD0
	  lwz       r16, 0x6CC8(r19)
	  li        r18, 0
	  lwz       r17, 0x6CCC(r19)

	.loc_0x6C:
	  mr        r3, r30
	  bl        0x10C
	  cmpw      r17, r3
	  add       r18, r18, r3
	  bge+      .loc_0x6C
	  cmpw      r3, r16
	  bge+      .loc_0x6C
	  cmpwi     r18, 0
	  bne-      .loc_0xD8
	  lwz       r17, 0x6124(r27)
	  lwz       r16, 0x4(r17)
	  b         .loc_0xB8

	.loc_0x9C:
	  mr        r3, r29
	  bl        .loc_0x13C
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r16,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r16, r17, r0

	.loc_0xB8:
	  cmpwi     r16, 0x100
	  bge+      .loc_0x9C
	  rlwinm    r3,r16,2,0,29
	  addi      r0, r3, 0x8
	  lwzx      r24, r17, r0
	  b         .loc_0xD8

	.loc_0xD0:
	  li        r18, 0
	  subi      r24, r24, 0x1

	.loc_0xD8:
	  add       r4, r23, r18
	  lbzu      r5, 0x2(r25)
	  rlwinm    r3,r4,0,24,31
	  addi      r0, r3, 0x1
	  stb       r4, 0x0(r26)
	  add       r0, r5, r0
	  srawi     r23, r0, 0x1
	  subi      r21, r21, 0x1
	  addi      r26, r26, 0x2

	.loc_0xFC:
	  cmpwi     r21, 0
	  bgt+      .loc_0x58
	  addi      r26, r26, 0x4
	  subi      r20, r20, 0x1

	.loc_0x10C:
	  cmpwi     r20, 0
	  bgt+      .loc_0x48
	  addi      r15, r15, 0x1
	  cmpwi     r15, 0x3
	  addi      r28, r28, 0x38
	  addi      r27, r27, 0x14
	  blt+      .loc_0x24
	  lmw       r15, 0x24(r1)
	  lwz       r0, 0x6C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr

	.loc_0x13C:
	*/
}

/*
 * --INFO--
 * Address:	8001F7E8
 * Size:	000040
 */
void getBit(void)
{
	/*
	.loc_0x0:
	  lwz       r5, 0xC(r3)
	  cmpwi     r5, 0
	  bge-      .loc_0x28
	  lwz       r4, 0x0(r3)
	  li        r5, 0x1F
	  addi      r0, r4, 0x4
	  stw       r0, 0x0(r3)
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x8(r3)
	  b         .loc_0x2C

	.loc_0x28:
	  lwz       r0, 0x8(r3)

	.loc_0x2C:
	  srw       r4, r0, r5
	  subi      r0, r5, 0x1
	  stw       r0, 0xC(r3)
	  rlwinm    r3,r4,0,31,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001F828
 * Size:	000070
 */
void decodeHuff(void)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x10(r3)
	  lwz       r7, 0x4(r6)
	  b         .loc_0x58

	.loc_0xC:
	  lwz       r5, 0xC(r3)
	  cmpwi     r5, 0
	  bge-      .loc_0x34
	  lwz       r4, 0x0(r3)
	  li        r5, 0x1F
	  addi      r0, r4, 0x4
	  stw       r0, 0x0(r3)
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x8(r3)
	  b         .loc_0x38

	.loc_0x34:
	  lwz       r0, 0x8(r3)

	.loc_0x38:
	  srw       r4, r0, r5
	  subi      r0, r5, 0x1
	  stw       r0, 0xC(r3)
	  rlwinm    r4,r4,11,20,20
	  rlwinm    r0,r7,2,0,29
	  add       r4, r4, r0
	  addi      r0, r4, 0x8
	  lwzx      r7, r6, r0

	.loc_0x58:
	  cmpwi     r7, 0x100
	  bge+      .loc_0xC
	  rlwinm    r0,r7,2,0,29
	  add       r3, r6, r0
	  lwz       r3, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001F898
 * Size:	0003A4
 */
void MakeNest(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  lhz       r6, 0xC(r3)
	  lhz       r7, 0x8(r3)
	  mullw     r0, r5, r6
	  lhz       r8, 0x625C(r3)
	  lwz       r5, 0x4(r3)
	  lhz       r9, 0xA(r3)
	  add       r0, r4, r0
	  rlwinm    r0,r0,1,0,30
	  cmpw      r7, r8
	  addi      r4, r7, 0
	  add       r11, r5, r0
	  bge-      .loc_0x5C
	  sub       r10, r8, r4
	  cmpw      r10, r4
	  addi      r5, r4, 0
	  ble-      .loc_0x50
	  mr        r10, r4

	.loc_0x50:
	  add       r0, r4, r10
	  sub       r8, r8, r0
	  b         .loc_0x68

	.loc_0x5C:
	  addi      r5, r8, 0
	  li        r8, 0
	  li        r10, 0

	.loc_0x68:
	  lhz       r4, 0x625E(r3)
	  cmpw      r9, r4
	  bge-      .loc_0x94
	  sub       r12, r4, r9
	  cmpw      r12, r9
	  addi      r7, r9, 0
	  ble-      .loc_0x88
	  mr        r12, r9

	.loc_0x88:
	  add       r0, r9, r12
	  sub       r0, r4, r0
	  b         .loc_0xA0

	.loc_0x94:
	  addi      r7, r4, 0
	  li        r0, 0
	  li        r12, 0

	.loc_0xA0:
	  addi      r9, r8, 0
	  addi      r30, r7, 0
	  addi      r31, r5, 0
	  addi      r4, r3, 0x6261
	  rlwinm    r8,r6,1,0,30
	  b         .loc_0x268

	.loc_0xB8:
	  cmpwi     r31, 0
	  addi      r7, r11, 0
	  addi      r6, r31, 0
	  ble-      .loc_0x164
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x148

	.loc_0xD4:
	  lbz       r5, 0x0(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x0(r4)
	  lbz       r5, 0x2(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x1(r4)
	  lbz       r5, 0x4(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x2(r4)
	  lbz       r5, 0x6(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x3(r4)
	  lbz       r5, 0x8(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x4(r4)
	  lbz       r5, 0xA(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x5(r4)
	  lbz       r5, 0xC(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x6(r4)
	  lbz       r5, 0xE(r7)
	  addi      r7, r7, 0x10
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x7(r4)
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0xD4
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x164

	.loc_0x148:
	  mtctr     r6

	.loc_0x14C:
	  lbz       r5, 0x0(r7)
	  addi      r7, r7, 0x2
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x14C

	.loc_0x164:
	  cmpwi     r10, 0
	  addi      r6, r10, 0
	  ble-      .loc_0x204
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x1EC

	.loc_0x17C:
	  lbz       r5, -0x2(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x0(r4)
	  lbz       r5, -0x4(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x1(r4)
	  lbz       r5, -0x6(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x2(r4)
	  lbz       r5, -0x8(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x3(r4)
	  lbz       r5, -0xA(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x4(r4)
	  lbz       r5, -0xC(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x5(r4)
	  lbz       r5, -0xE(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x6(r4)
	  lbzu      r5, -0x10(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x7(r4)
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x17C
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x204

	.loc_0x1EC:
	  mtctr     r6

	.loc_0x1F0:
	  lbzu      r5, -0x2(r7)
	  rlwinm    r5,r5,28,28,31
	  stb       r5, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x1F0

	.loc_0x204:
	  cmpwi     r9, 0
	  addi      r6, r9, 0
	  li        r7, 0
	  ble-      .loc_0x260
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x250

	.loc_0x220:
	  stb       r7, 0x0(r4)
	  stb       r7, 0x1(r4)
	  stb       r7, 0x2(r4)
	  stb       r7, 0x3(r4)
	  stb       r7, 0x4(r4)
	  stb       r7, 0x5(r4)
	  stb       r7, 0x6(r4)
	  stb       r7, 0x7(r4)
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x220
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x260

	.loc_0x250:
	  mtctr     r6

	.loc_0x254:
	  stb       r7, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x254

	.loc_0x260:
	  add       r11, r11, r8
	  subi      r30, r30, 0x1

	.loc_0x268:
	  cmpwi     r30, 0
	  bgt+      .loc_0xB8
	  lhz       r5, 0x625C(r3)
	  addi      r7, r12, 0
	  sub       r8, r4, r5
	  b         .loc_0x318

	.loc_0x280:
	  lhz       r5, 0x625C(r3)
	  addi      r9, r8, 0
	  cmpwi     r5, 0
	  addi      r6, r5, 0
	  ble-      .loc_0x30C
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x2F4

	.loc_0x2A0:
	  lbz       r5, 0x0(r9)
	  stb       r5, 0x0(r4)
	  lbz       r5, 0x1(r9)
	  stb       r5, 0x1(r4)
	  lbz       r5, 0x2(r9)
	  stb       r5, 0x2(r4)
	  lbz       r5, 0x3(r9)
	  stb       r5, 0x3(r4)
	  lbz       r5, 0x4(r9)
	  stb       r5, 0x4(r4)
	  lbz       r5, 0x5(r9)
	  stb       r5, 0x5(r4)
	  lbz       r5, 0x6(r9)
	  stb       r5, 0x6(r4)
	  lbz       r5, 0x7(r9)
	  addi      r9, r9, 0x8
	  stb       r5, 0x7(r4)
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x2A0
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x30C

	.loc_0x2F4:
	  mtctr     r6

	.loc_0x2F8:
	  lbz       r5, 0x0(r9)
	  addi      r9, r9, 0x1
	  stb       r5, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x2F8

	.loc_0x30C:
	  lhz       r5, 0x625C(r3)
	  subi      r7, r7, 0x1
	  sub       r8, r8, r5

	.loc_0x318:
	  cmpwi     r7, 0
	  bgt+      .loc_0x280
	  mr        r7, r0
	  li        r6, 0
	  b         .loc_0x38C

	.loc_0x32C:
	  lhz       r0, 0x625C(r3)
	  cmpwi     r0, 0
	  mr        r5, r0
	  ble-      .loc_0x388
	  rlwinm.   r0,r5,29,3,31
	  mtctr     r0
	  beq-      .loc_0x378

	.loc_0x348:
	  stb       r6, 0x0(r4)
	  stb       r6, 0x1(r4)
	  stb       r6, 0x2(r4)
	  stb       r6, 0x3(r4)
	  stb       r6, 0x4(r4)
	  stb       r6, 0x5(r4)
	  stb       r6, 0x6(r4)
	  stb       r6, 0x7(r4)
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x348
	  andi.     r5, r5, 0x7
	  beq-      .loc_0x388

	.loc_0x378:
	  mtctr     r5

	.loc_0x37C:
	  stb       r6, 0x0(r4)
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x37C

	.loc_0x388:
	  subi      r7, r7, 0x1

	.loc_0x38C:
	  cmpwi     r7, 0
	  bgt+      .loc_0x32C
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001FC3C
 * Size:	000198
 */
void WeightImBlock(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x40(r1)
	  rlwinm    r10,r7,0,24,31
	  rlwinm    r11,r5,3,21,28
	  stmw      r23, 0x1C(r1)
	  rlwinm    r24,r6,0,24,31
	  rlwinm    r0,r8,0,24,31
	  rlwinm    r7,r9,0,24,31
	  rlwinm    r28,r5,1,23,30
	  add       r5, r24, r0
	  lis       r6, 0x8039
	  sub       r8, r24, r10
	  sub       r23, r0, r7
	  addi      r12, r11, 0x4
	  subi      r6, r6, 0x4300
	  add       r9, r8, r23
	  sub       r31, r5, r28
	  sub       r11, r8, r23
	  add       r5, r12, r9
	  add       r23, r31, r5
	  add       r8, r24, r7
	  sub       r30, r8, r28
	  sub       r27, r24, r0
	  sub       r26, r24, r7
	  add       r24, r10, r7
	  addi      r6, r6, 0x80
	  srawi     r23, r23, 0x3
	  sub       r29, r24, r28
	  lbzx      r24, r6, r23
	  add       r23, r27, r5
	  add       r25, r0, r10
	  stb       r24, 0x0(r3)
	  srawi     r23, r23, 0x3
	  lbzx      r24, r6, r23
	  add       r8, r12, r11
	  add       r23, r26, r8
	  stb       r24, 0x1(r3)
	  srawi     r23, r23, 0x3
	  add       r24, r30, r8
	  lbzx      r23, r6, r23
	  sub       r28, r25, r28
	  srawi     r25, r24, 0x3
	  sub       r24, r5, r27
	  stb       r23, 0x2(r3)
	  sub       r5, r12, r11
	  lbzx      r25, r6, r25
	  sub       r11, r10, r0
	  srawi     r24, r24, 0x3
	  stb       r25, 0x3(r3)
	  add       r27, r3, r4
	  sub       r0, r12, r29
	  lbzx      r25, r6, r24
	  srawi     r3, r0, 0x3
	  sub       r0, r12, r28
	  srawi     r24, r0, 0x3
	  stb       r25, 0x0(r27)
	  sub       r0, r8, r26
	  lbzx      r26, r6, r3
	  srawi     r25, r0, 0x3
	  sub       r3, r10, r7
	  stb       r26, 0x1(r27)
	  sub       r8, r5, r11
	  srawi     r26, r8, 0x3
	  lbzx      r8, r6, r24
	  sub       r7, r12, r30
	  srawi     r10, r7, 0x3
	  stb       r8, 0x2(r27)
	  sub       r0, r12, r9
	  sub       r7, r12, r31
	  lbzx      r12, r6, r25
	  srawi     r9, r7, 0x3
	  sub       r7, r0, r3
	  stb       r12, 0x3(r27)
	  add       r27, r27, r4
	  srawi     r8, r7, 0x3
	  lbzx      r12, r6, r26
	  add       r7, r28, r5
	  add       r3, r3, r0
	  stb       r12, 0x0(r27)
	  srawi     r7, r7, 0x3
	  add       r5, r11, r5
	  lbzx      r10, r6, r10
	  srawi     r5, r5, 0x3
	  srawi     r3, r3, 0x3
	  stb       r10, 0x1(r27)
	  add       r0, r29, r0
	  srawi     r0, r0, 0x3
	  lbzx      r9, r6, r9
	  stb       r9, 0x2(r27)
	  lbzx      r8, r6, r8
	  stb       r8, 0x3(r27)
	  add       r27, r27, r4
	  lbzx      r4, r6, r7
	  stb       r4, 0x0(r27)
	  lbzx      r4, r6, r5
	  stb       r4, 0x1(r27)
	  lbzx      r3, r6, r3
	  stb       r3, 0x2(r27)
	  lbzx      r0, r6, r0
	  stb       r0, 0x3(r27)
	  lmw       r23, 0x1C(r1)
	  addi      r1, r1, 0x40
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001FDD4
 * Size:	000048
 */
void OrgBlock(void)
{
	/*
	.loc_0x0:
	  rlwinm    r6,r6,4,0,27
	  addi      r6, r6, 0x61DC
	  add       r6, r3, r6
	  lwz       r3, 0x0(r6)
	  add       r10, r4, r5
	  lwz       r7, 0x4(r3)
	  addi      r0, r3, 0x10
	  lwz       r8, 0x8(r3)
	  lwz       r9, 0xC(r3)
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x0(r4)
	  stw       r7, 0x0(r10)
	  add       r10, r10, r5
	  stw       r8, 0x0(r10)
	  add       r10, r10, r5
	  stw       r9, 0x0(r10)
	  stw       r0, 0x0(r6)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001FE1C
 * Size:	0003D0
 */
void IntraAotBlock(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r7,0,24,31
	  cmplwi    r0, 0x6
	  stwu      r1, -0x100(r1)
	  stmw      r15, 0xBC(r1)
	  addi      r21, r3, 0
	  addi      r30, r4, 0
	  stw       r5, 0x74(r1)
	  stb       r6, 0x78(r1)
	  stw       r8, 0x7C(r1)
	  bne-      .loc_0x48
	  lwz       r5, 0x74(r1)
	  addi      r3, r21, 0
	  lwz       r6, 0x7C(r1)
	  addi      r4, r30, 0
	  bl        -0x88
	  b         .loc_0x3BC

	.loc_0x48:
	  lhz       r0, 0x625C(r21)
	  li        r31, 0
	  lbz       r19, 0x6CD0(r21)
	  addi      r29, r7, 0
	  stw       r0, 0x98(r1)
	  li        r0, 0
	  stw       r0, 0x1C(r1)
	  addi      r15, r31, 0
	  addi      r16, r31, 0
	  stw       r31, 0x94(r1)
	  addi      r17, r31, 0
	  addi      r18, r31, 0
	  stw       r31, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  stw       r31, 0x88(r1)
	  stw       r31, 0x84(r1)
	  stw       r31, 0x80(r1)
	  stw       r31, 0xB4(r1)
	  stw       r31, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  stw       r31, 0xA8(r1)
	  stw       r31, 0xA4(r1)
	  b         .loc_0x1E8

	.loc_0xA4:
	  lwz       r7, 0x98(r1)
	  mr        r3, r21
	  lwz       r8, 0x7C(r1)
	  addi      r4, r1, 0x20
	  addi      r5, r1, 0x1C
	  addi      r6, r21, 0x6261
	  bl        .loc_0x3D0
	  lbz       r5, 0x20(r1)
	  lbz       r4, 0x21(r1)
	  mullw     r5, r3, r5
	  lbz       r8, 0x25(r1)
	  lbz       r9, 0x24(r1)
	  lbz       r7, 0x26(r1)
	  lbz       r26, 0x27(r1)
	  mullw     r4, r3, r4
	  stw       r5, 0x9C(r1)
	  lbz       r6, 0x28(r1)
	  lbz       r5, 0x29(r1)
	  lbz       r0, 0x22(r1)
	  stw       r4, 0xA0(r1)
	  mullw     r25, r3, r8
	  lwz       r8, 0x9C(r1)
	  lbz       r4, 0x2D(r1)
	  lbz       r10, 0x23(r1)
	  lbz       r12, 0x2A(r1)
	  add       r18, r18, r8
	  lwz       r8, 0xA0(r1)
	  mullw     r9, r3, r9
	  lbz       r28, 0x2B(r1)
	  lbz       r27, 0x2C(r1)
	  lbz       r11, 0x2F(r1)
	  add       r17, r17, r8
	  lwz       r8, 0xA4(r1)
	  mullw     r24, r3, r7
	  add       r8, r8, r9
	  stw       r8, 0xA4(r1)
	  mullw     r23, r3, r6
	  lwz       r8, 0xA8(r1)
	  mullw     r20, r3, r0
	  lbz       r0, 0x2E(r1)
	  add       r8, r8, r25
	  stw       r8, 0xA8(r1)
	  mullw     r22, r3, r5
	  lwz       r8, 0xAC(r1)
	  add       r8, r8, r24
	  stw       r8, 0xAC(r1)
	  mullw     r10, r3, r10
	  lwz       r8, 0xB0(r1)
	  mullw     r26, r3, r26
	  add       r8, r8, r26
	  stw       r8, 0xB0(r1)
	  mullw     r5, r3, r12
	  lwz       r8, 0xB4(r1)
	  add       r8, r8, r23
	  stw       r8, 0xB4(r1)
	  mullw     r6, r3, r28
	  lwz       r8, 0x80(r1)
	  add       r8, r8, r22
	  stw       r8, 0x80(r1)
	  mullw     r7, r3, r27
	  lwz       r8, 0x84(r1)
	  add       r8, r8, r5
	  lwz       r5, 0x88(r1)
	  mullw     r4, r3, r4
	  stw       r8, 0x84(r1)
	  add       r5, r5, r6
	  stw       r5, 0x88(r1)
	  mullw     r0, r3, r0
	  lwz       r5, 0x8C(r1)
	  add       r5, r5, r7
	  stw       r5, 0x8C(r1)
	  mullw     r3, r3, r11
	  lwz       r5, 0x90(r1)
	  add       r5, r5, r4
	  lwz       r4, 0x94(r1)
	  stw       r5, 0x90(r1)
	  add       r16, r16, r20
	  add       r4, r4, r0
	  stw       r4, 0x94(r1)
	  add       r15, r15, r10
	  add       r31, r31, r3

	.loc_0x1E8:
	  rlwinm.   r0,r29,0,24,31
	  subi      r29, r29, 0x1
	  bne+      .loc_0xA4
	  add       r0, r17, r16
	  lwz       r8, 0xB0(r1)
	  add       r3, r0, r15
	  lwz       r0, 0xA4(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xA8(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xAC(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xB0(r1)
	  add       r3, r3, r0
	  lwz       r0, 0xB4(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x80(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x84(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x88(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x8C(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x90(r1)
	  add       r3, r3, r0
	  lwz       r0, 0x94(r1)
	  add       r0, r3, r0
	  add       r0, r0, r31
	  add       r4, r18, r0
	  lbz       r0, 0x78(r1)
	  lis       r3, 0x8039
	  srawi     r4, r4, 0x4
	  slw       r0, r0, r19
	  sub       r0, r0, r4
	  subi      r3, r3, 0x4300
	  add       r4, r18, r0
	  addi      r3, r3, 0x80
	  sraw      r4, r4, r19
	  lbzx      r4, r3, r4
	  add       r5, r17, r0
	  sraw      r5, r5, r19
	  stb       r4, 0x0(r30)
	  add       r4, r16, r0
	  sraw      r4, r4, r19
	  lbzx      r6, r3, r5
	  add       r5, r15, r0
	  sraw      r7, r5, r19
	  lwz       r5, 0xA4(r1)
	  stb       r6, 0x1(r30)
	  add       r5, r5, r0
	  lbzx      r4, r3, r4
	  sraw      r6, r5, r19
	  lwz       r5, 0xA8(r1)
	  add       r8, r8, r0
	  stb       r4, 0x2(r30)
	  add       r5, r5, r0
	  lwz       r4, 0xAC(r1)
	  lbzx      r7, r3, r7
	  sraw      r5, r5, r19
	  add       r4, r4, r0
	  stb       r7, 0x3(r30)
	  sraw      r4, r4, r19
	  lwz       r7, 0x74(r1)
	  sraw      r8, r8, r19
	  lbzx      r6, r3, r6
	  add       r30, r30, r7
	  lwz       r7, 0xB4(r1)
	  stb       r6, 0x0(r30)
	  add       r7, r7, r0
	  lwz       r6, 0x84(r1)
	  lbzx      r5, r3, r5
	  sraw      r11, r7, r19
	  lwz       r7, 0x80(r1)
	  add       r6, r6, r0
	  stb       r5, 0x1(r30)
	  add       r7, r7, r0
	  lwz       r5, 0x8C(r1)
	  lbzx      r4, r3, r4
	  sraw      r7, r7, r19
	  sraw      r10, r6, r19
	  lwz       r6, 0x88(r1)
	  stb       r4, 0x2(r30)
	  add       r6, r6, r0
	  lwz       r4, 0x94(r1)
	  lbzx      r8, r3, r8
	  sraw      r6, r6, r19
	  add       r5, r5, r0
	  stb       r8, 0x3(r30)
	  sraw      r9, r5, r19
	  lwz       r8, 0x74(r1)
	  add       r4, r4, r0
	  lwz       r5, 0x90(r1)
	  add       r30, r30, r8
	  lbzx      r8, r3, r11
	  add       r5, r5, r0
	  stb       r8, 0x0(r30)
	  sraw      r5, r5, r19
	  sraw      r4, r4, r19
	  lbzx      r7, r3, r7
	  add       r0, r31, r0
	  sraw      r0, r0, r19
	  stb       r7, 0x1(r30)
	  lbzx      r7, r3, r10
	  stb       r7, 0x2(r30)
	  lbzx      r6, r3, r6
	  stb       r6, 0x3(r30)
	  lwz       r6, 0x74(r1)
	  add       r30, r30, r6
	  lbzx      r6, r3, r9
	  stb       r6, 0x0(r30)
	  lbzx      r5, r3, r5
	  stb       r5, 0x1(r30)
	  lbzx      r4, r3, r4
	  stb       r4, 0x2(r30)
	  lbzx      r0, r3, r0
	  stb       r0, 0x3(r30)

	.loc_0x3BC:
	  lmw       r15, 0xBC(r1)
	  lwz       r0, 0x104(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr

	.loc_0x3D0:
	*/
}

/*
 * --INFO--
 * Address:	800201EC
 * Size:	00047C
 */
void GetAotBasis(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x38(r1)
	  rlwinm    r0,r8,4,0,27
	  add       r11, r3, r0
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  lwz       r10, 0x61DC(r11)
	  addi      r0, r10, 0x1
	  stw       r0, 0x61DC(r11)
	  lwz       r9, 0x61DC(r11)
	  lbz       r10, 0x0(r10)
	  addi      r0, r9, 0x1
	  stw       r0, 0x61DC(r11)
	  lbz       r0, 0x6260(r3)
	  lbz       r9, 0x0(r9)
	  cmplwi    r0, 0
	  addi      r0, r9, 0
	  rlwimi    r0,r10,8,16,23
	  beq-      .loc_0x74
	  rlwinm    r9,r0,26,27,31
	  mullw     r10, r9, r7
	  add       r11, r10, r6
	  rlwinm    r9,r0,20,31,31
	  rlwinm    r12,r0,0,26,31
	  rlwinm    r6,r0,21,31,31
	  li        r10, 0x1
	  add       r11, r12, r11
	  slw       r6, r10, r6
	  slw       r7, r7, r9
	  b         .loc_0x9C

	.loc_0x74:
	  rlwinm    r9,r0,0,26,31
	  mullw     r10, r9, r7
	  add       r11, r10, r6
	  rlwinm    r9,r0,21,31,31
	  rlwinm    r12,r0,26,27,31
	  rlwinm    r6,r0,20,31,31
	  li        r10, 0x1
	  add       r11, r12, r11
	  slw       r6, r10, r6
	  slw       r7, r7, r9

	.loc_0x9C:
	  lbz       r9, 0x0(r11)
	  add       r31, r11, r6
	  stb       r9, 0x0(r4)
	  rlwinm    r12,r9,0,24,31
	  addi      r10, r9, 0
	  lbz       r30, 0x0(r31)
	  cmplw     r30, r12
	  stb       r30, 0x1(r4)
	  ble-      .loc_0xC8
	  mr        r10, r30
	  b         .loc_0xD0

	.loc_0xC8:
	  bge-      .loc_0xD0
	  mr        r9, r30

	.loc_0xD0:
	  add       r31, r31, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x2(r4)
	  ble-      .loc_0xF0
	  mr        r10, r30
	  b         .loc_0x100

	.loc_0xF0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x100
	  mr        r9, r30

	.loc_0x100:
	  add       r31, r31, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x3(r4)
	  ble-      .loc_0x120
	  mr        r10, r30
	  b         .loc_0x130

	.loc_0x120:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x130
	  mr        r9, r30

	.loc_0x130:
	  add       r11, r11, r7
	  lbz       r30, 0x0(r11)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x4(r4)
	  ble-      .loc_0x150
	  mr        r10, r30
	  b         .loc_0x160

	.loc_0x150:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x160
	  mr        r9, r30

	.loc_0x160:
	  add       r31, r11, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x5(r4)
	  ble-      .loc_0x180
	  mr        r10, r30
	  b         .loc_0x190

	.loc_0x180:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x190
	  mr        r9, r30

	.loc_0x190:
	  add       r31, r31, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x6(r4)
	  ble-      .loc_0x1B0
	  mr        r10, r30
	  b         .loc_0x1C0

	.loc_0x1B0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x1C0
	  mr        r9, r30

	.loc_0x1C0:
	  add       r31, r31, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x7(r4)
	  ble-      .loc_0x1E0
	  mr        r10, r30
	  b         .loc_0x1F0

	.loc_0x1E0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x1F0
	  mr        r9, r30

	.loc_0x1F0:
	  add       r11, r11, r7
	  lbz       r30, 0x0(r11)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x8(r4)
	  ble-      .loc_0x210
	  mr        r10, r30
	  b         .loc_0x220

	.loc_0x210:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x220
	  mr        r9, r30

	.loc_0x220:
	  add       r31, r11, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0x9(r4)
	  ble-      .loc_0x240
	  mr        r10, r30
	  b         .loc_0x250

	.loc_0x240:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x250
	  mr        r9, r30

	.loc_0x250:
	  add       r31, r31, r6
	  lbz       r30, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r30, r12
	  stb       r30, 0xA(r4)
	  ble-      .loc_0x270
	  mr        r10, r30
	  b         .loc_0x280

	.loc_0x270:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x280
	  mr        r9, r30

	.loc_0x280:
	  add       r31, r31, r6
	  lbz       r31, 0x0(r31)
	  rlwinm    r12,r10,0,24,31
	  cmplw     r31, r12
	  stb       r31, 0xB(r4)
	  ble-      .loc_0x2A0
	  mr        r10, r31
	  b         .loc_0x2B0

	.loc_0x2A0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r31, r12
	  bge-      .loc_0x2B0
	  mr        r9, r31

	.loc_0x2B0:
	  add       r11, r11, r7
	  lbz       r12, 0x0(r11)
	  rlwinm    r7,r10,0,24,31
	  cmplw     r12, r7
	  stb       r12, 0xC(r4)
	  ble-      .loc_0x2D0
	  mr        r10, r12
	  b         .loc_0x2E0

	.loc_0x2D0:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r12, r7
	  bge-      .loc_0x2E0
	  mr        r9, r12

	.loc_0x2E0:
	  add       r11, r11, r6
	  lbz       r12, 0x0(r11)
	  rlwinm    r7,r10,0,24,31
	  cmplw     r12, r7
	  stb       r12, 0xD(r4)
	  ble-      .loc_0x300
	  mr        r10, r12
	  b         .loc_0x310

	.loc_0x300:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r12, r7
	  bge-      .loc_0x310
	  mr        r9, r12

	.loc_0x310:
	  add       r11, r11, r6
	  lbz       r12, 0x0(r11)
	  rlwinm    r7,r10,0,24,31
	  cmplw     r12, r7
	  stb       r12, 0xE(r4)
	  ble-      .loc_0x330
	  mr        r10, r12
	  b         .loc_0x340

	.loc_0x330:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r12, r7
	  bge-      .loc_0x340
	  mr        r9, r12

	.loc_0x340:
	  add       r11, r11, r6
	  lbz       r7, 0x0(r11)
	  rlwinm    r6,r10,0,24,31
	  cmplw     r7, r6
	  stb       r7, 0xF(r4)
	  ble-      .loc_0x360
	  mr        r10, r7
	  b         .loc_0x370

	.loc_0x360:
	  rlwinm    r4,r9,0,24,31
	  cmplw     r7, r4
	  bge-      .loc_0x370
	  mr        r9, r7

	.loc_0x370:
	  mulli     r6, r8, 0x14
	  add       r4, r3, r6
	  lwz       r11, 0x6160(r4)
	  addi      r7, r6, 0x6150
	  add       r7, r3, r7
	  lwz       r6, 0x4(r11)
	  b         .loc_0x3D8

	.loc_0x38C:
	  lwz       r8, 0xC(r7)
	  cmpwi     r8, 0
	  bge-      .loc_0x3B4
	  lwz       r4, 0x0(r7)
	  li        r8, 0x1F
	  addi      r3, r4, 0x4
	  stw       r3, 0x0(r7)
	  lwz       r3, 0x0(r4)
	  stw       r3, 0x8(r7)
	  b         .loc_0x3B8

	.loc_0x3B4:
	  lwz       r3, 0x8(r7)

	.loc_0x3B8:
	  srw       r4, r3, r8
	  subi      r3, r8, 0x1
	  stw       r3, 0xC(r7)
	  rlwinm    r4,r4,11,20,20
	  rlwinm    r3,r6,2,0,29
	  add       r3, r4, r3
	  addi      r3, r3, 0x8
	  lwzx      r6, r11, r3

	.loc_0x3D8:
	  cmpwi     r6, 0x100
	  bge+      .loc_0x38C
	  rlwinm    r3,r6,2,0,29
	  lwz       r4, 0x0(r5)
	  add       r3, r11, r3
	  lwz       r3, 0x8(r3)
	  rlwinm    r7,r0,0,16,31
	  rlwinm.   r0,r0,0,16,16
	  add       r3, r4, r3
	  stw       r3, 0x0(r5)
	  beq-      .loc_0x43C
	  rlwinm    r3,r9,0,24,31
	  lwz       r5, 0x0(r5)
	  rlwinm    r0,r10,0,24,31
	  sub       r0, r0, r3
	  lis       r3, 0x8039
	  rlwinm    r4,r0,2,0,29
	  subi      r0, r3, 0x4100
	  add       r3, r0, r4
	  lwz       r0, 0x0(r3)
	  rlwinm    r3,r7,19,30,31
	  add       r3, r5, r3
	  neg       r0, r0
	  mullw     r3, r3, r0
	  b         .loc_0x46C

	.loc_0x43C:
	  rlwinm    r3,r9,0,24,31
	  lwz       r6, 0x0(r5)
	  rlwinm    r0,r10,0,24,31
	  sub       r0, r0, r3
	  lis       r3, 0x8039
	  rlwinm    r5,r7,19,30,31
	  rlwinm    r4,r0,2,0,29
	  subi      r0, r3, 0x4100
	  add       r3, r0, r4
	  lwz       r0, 0x0(r3)
	  add       r3, r6, r5
	  mullw     r3, r3, r0

	.loc_0x46C:
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x38
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80020668
 * Size:	000144
 */
void IpicBlockDec(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r6
	  stw       r30, 0x18(r1)
	  lbz       r7, 0x13(r6)
	  cmplwi    r7, 0
	  bne-      .loc_0xA0
	  lwz       r3, 0x4(r31)
	  lbz       r30, 0x12(r31)
	  lbz       r0, 0x1(r3)
	  andi.     r0, r0, 0x77
	  beq-      .loc_0x40
	  mr        r0, r30
	  b         .loc_0x44

	.loc_0x40:
	  lbz       r0, 0x0(r3)

	.loc_0x44:
	  lwz       r3, 0xC(r31)
	  mr        r6, r0
	  lbz       r0, 0x1(r3)
	  andi.     r0, r0, 0x77
	  beq-      .loc_0x60
	  mr        r3, r30
	  b         .loc_0x64

	.loc_0x60:
	  lbz       r3, 0x0(r3)

	.loc_0x64:
	  lbz       r0, 0x11(r31)
	  addi      r7, r3, 0
	  andi.     r0, r0, 0x77
	  beq-      .loc_0x7C
	  mr        r0, r30
	  b         .loc_0x80

	.loc_0x7C:
	  lbz       r0, 0x10(r31)

	.loc_0x80:
	  lbz       r8, 0x14(r31)
	  addi      r3, r4, 0
	  addi      r4, r5, 0
	  mr        r9, r0
	  addi      r5, r30, 0
	  bl        -0xAC0
	  stb       r30, 0x14(r31)
	  b         .loc_0x114

	.loc_0xA0:
	  cmplwi    r7, 0x8
	  bne-      .loc_0x100
	  lbz       r0, 0x12(r31)
	  add       r3, r4, r5
	  stb       r0, 0x3(r4)
	  stb       r0, 0x2(r4)
	  stb       r0, 0x1(r4)
	  stb       r0, 0x0(r4)
	  stb       r0, 0x3(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x1(r3)
	  stb       r0, 0x0(r3)
	  add       r3, r3, r5
	  stb       r0, 0x3(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x1(r3)
	  stb       r0, 0x0(r3)
	  add       r3, r3, r5
	  stb       r0, 0x3(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x1(r3)
	  stb       r0, 0x0(r3)
	  stb       r0, 0x14(r31)
	  b         .loc_0x114

	.loc_0x100:
	  lbz       r6, 0x12(r31)
	  lwz       r8, 0x0(r31)
	  bl        -0x954
	  lbz       r0, 0x10(r31)
	  stb       r0, 0x14(r31)

	.loc_0x114:
	  lwz       r3, 0x4(r31)
	  addi      r0, r3, 0x2
	  stw       r0, 0x4(r31)
	  lwz       r3, 0xC(r31)
	  addi      r0, r3, 0x2
	  stw       r0, 0xC(r31)
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
 * Address:	800207AC
 * Size:	0000D4
 */
void IpicLineDec(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  mr        r30, r6
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  subi      r31, r7, 0x1
	  lwz       r6, 0x8(r6)
	  lhz       r0, 0x0(r6)
	  sth       r0, 0x10(r30)
	  lwz       r3, 0x8(r30)
	  lbz       r0, 0x0(r3)
	  stb       r0, 0x14(r30)
	  b         .loc_0x78

	.loc_0x40:
	  lhz       r0, 0x10(r30)
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  sth       r0, 0x12(r30)
	  addi      r5, r29, 0
	  addi      r6, r30, 0
	  lwz       r7, 0x8(r30)
	  addi      r7, r7, 0x2
	  stw       r7, 0x8(r30)
	  lhz       r0, 0x0(r7)
	  sth       r0, 0x10(r30)
	  bl        -0x1B0
	  addi      r28, r28, 0x4
	  subi      r31, r31, 0x1

	.loc_0x78:
	  cmpwi     r31, 0
	  bgt+      .loc_0x40
	  lhz       r0, 0x10(r30)
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  sth       r0, 0x12(r30)
	  addi      r5, r29, 0
	  addi      r6, r30, 0
	  lwz       r7, 0x8(r30)
	  addi      r0, r7, 0x6
	  stw       r0, 0x8(r30)
	  bl        -0x1E8
	  lwz       r3, 0x4(r30)
	  addi      r0, r3, 0x4
	  stw       r0, 0x4(r30)
	  lwz       r3, 0xC(r30)
	  addi      r0, r3, 0x4
	  stw       r0, 0xC(r30)
	  lwz       r0, 0x3C(r1)
	  lmw       r27, 0x24(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80020880
 * Size:	0000DC
 */
void IpicPlaneDec(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r4, 0x38
	  stwu      r1, -0x50(r1)
	  stmw      r25, 0x34(r1)
	  addi      r25, r3, 0
	  add       r31, r25, r0
	  mr        r26, r5
	  addi      r30, r31, 0x4
	  lhz       r8, 0x28(r31)
	  lhz       r27, 0x8(r31)
	  lhz       r0, 0xC(r31)
	  mr        r28, r8
	  addi      r5, r28, 0
	  stw       r4, 0x14(r1)
	  rlwinm    r0,r0,1,0,30
	  addi      r4, r26, 0
	  lwz       r6, 0x4(r31)
	  addi      r7, r27, 0
	  rlwinm    r29,r8,2,0,29
	  stw       r6, 0x18(r1)
	  add       r0, r6, r0
	  stw       r6, 0x1C(r1)
	  addi      r6, r1, 0x14
	  stw       r0, 0x20(r1)
	  bl        -0x138
	  lwz       r0, 0x0(r30)
	  add       r26, r26, r29
	  stw       r0, 0x18(r1)
	  lhz       r3, 0xA(r31)
	  subi      r30, r3, 0x2
	  b         .loc_0xA0

	.loc_0x80:
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  addi      r5, r28, 0
	  addi      r7, r27, 0
	  addi      r6, r1, 0x14
	  bl        -0x168
	  add       r26, r26, r29
	  subi      r30, r30, 0x1

	.loc_0xA0:
	  cmpwi     r30, 0
	  bgt+      .loc_0x80
	  lwz       r0, 0x1C(r1)
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  stw       r0, 0x20(r1)
	  addi      r5, r28, 0
	  addi      r7, r27, 0
	  addi      r6, r1, 0x14
	  bl        -0x198
	  lmw       r25, 0x34(r1)
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8002095C
 * Size:	00008C
 */
void initMCHandler(void)
{
	/*
	.loc_0x0:
	  li        r0, 0x3
	  mtctr     r0

	.loc_0x8:
	  li        r0, 0
	  stw       r0, 0x0(r4)
	  li        r0, 0x7F
	  li        r9, 0x8
	  stw       r0, 0x4(r4)
	  stw       r5, 0x10(r4)
	  stw       r6, 0x1C(r4)
	  stw       r7, 0x20(r4)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x8(r4)
	  stw       r0, 0xC(r4)
	  lbz       r0, 0x30(r3)
	  sraw      r0, r9, r0
	  sth       r0, 0x24(r4)
	  lbz       r8, 0x31(r3)
	  lhz       r0, 0x28(r3)
	  sraw      r8, r9, r8
	  mullw     r0, r8, r0
	  stw       r0, 0x28(r4)
	  lbz       r0, 0x32(r3)
	  stw       r0, 0x2C(r4)
	  lhz       r8, 0xC(r3)
	  lbz       r0, 0x33(r3)
	  mullw     r0, r8, r0
	  stw       r0, 0x30(r4)
	  addi      r4, r4, 0x34
	  lwz       r0, 0x2C(r3)
	  addi      r3, r3, 0x38
	  add       r5, r5, r0
	  add       r6, r6, r0
	  add       r7, r7, r0
	  bdnz+     .loc_0x8
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void resetMCHandler(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800209E8
 * Size:	00009C
 */
void _MotionComp_00(void)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x0(r5)
	  add       r7, r5, r6
	  add       r8, r3, r4
	  stb       r0, 0x0(r3)
	  lbz       r0, 0x1(r5)
	  stb       r0, 0x1(r3)
	  lbz       r0, 0x2(r5)
	  stb       r0, 0x2(r3)
	  lbz       r0, 0x3(r5)
	  stb       r0, 0x3(r3)
	  lbz       r0, 0x0(r7)
	  stb       r0, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  stb       r0, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  stb       r0, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  add       r7, r7, r6
	  stb       r0, 0x3(r8)
	  add       r8, r8, r4
	  lbz       r0, 0x0(r7)
	  stb       r0, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  stb       r0, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  stb       r0, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  add       r7, r7, r6
	  stb       r0, 0x3(r8)
	  add       r8, r8, r4
	  lbz       r0, 0x0(r7)
	  stb       r0, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  stb       r0, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  stb       r0, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  stb       r0, 0x3(r8)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80020A84
 * Size:	0001AC
 */
void _MotionComp_01(void)
{
	/*
	.loc_0x0:
	  add       r8, r5, r6
	  lbz       r11, 0x0(r5)
	  lbz       r10, 0x0(r8)
	  addi      r7, r8, 0
	  add       r9, r3, r4
	  addi      r0, r10, 0x1
	  add       r0, r11, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r3)
	  lbz       r10, 0x1(r8)
	  lbz       r11, 0x1(r5)
	  addi      r0, r10, 0x1
	  add       r0, r11, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r3)
	  lbz       r10, 0x2(r8)
	  lbz       r11, 0x2(r5)
	  addi      r0, r10, 0x1
	  add       r0, r11, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r3)
	  lbz       r10, 0x3(r8)
	  add       r8, r8, r6
	  lbz       r5, 0x3(r5)
	  addi      r0, r10, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r3)
	  lbz       r3, 0x0(r8)
	  lbz       r5, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r5, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r5, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  add       r8, r8, r6
	  lbz       r5, 0x3(r7)
	  add       r7, r7, r6
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r9)
	  add       r9, r9, r4
	  lbz       r3, 0x0(r8)
	  lbz       r5, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r5, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r5, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  add       r8, r8, r6
	  lbz       r5, 0x3(r7)
	  add       r7, r7, r6
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r9)
	  add       r9, r9, r4
	  lbz       r3, 0x0(r8)
	  lbz       r4, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r4, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r4, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  lbz       r4, 0x3(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r9)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80020C30
 * Size:	00019C
 */
void _MotionComp_10(void)
{
	/*
	.loc_0x0:
	  lbz       r9, 0x1(r5)
	  add       r7, r5, r6
	  lbz       r10, 0x0(r5)
	  add       r8, r3, r4
	  addi      r0, r9, 0x1
	  add       r0, r10, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r3)
	  lbz       r9, 0x2(r5)
	  lbz       r10, 0x1(r5)
	  addi      r0, r9, 0x1
	  add       r0, r10, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r3)
	  lbz       r9, 0x3(r5)
	  lbz       r10, 0x2(r5)
	  addi      r0, r9, 0x1
	  add       r0, r10, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r3)
	  lbz       r9, 0x4(r5)
	  lbz       r5, 0x3(r5)
	  addi      r0, r9, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r3)
	  lbz       r3, 0x1(r7)
	  lbz       r5, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r8)
	  lbz       r3, 0x2(r7)
	  lbz       r5, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r8)
	  lbz       r3, 0x3(r7)
	  lbz       r5, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r8)
	  lbz       r3, 0x4(r7)
	  lbz       r5, 0x3(r7)
	  add       r7, r7, r6
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r8)
	  add       r8, r8, r4
	  lbz       r3, 0x1(r7)
	  lbz       r5, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r8)
	  lbz       r3, 0x2(r7)
	  lbz       r5, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r8)
	  lbz       r3, 0x3(r7)
	  lbz       r5, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r8)
	  lbz       r3, 0x4(r7)
	  lbz       r5, 0x3(r7)
	  add       r7, r7, r6
	  addi      r0, r3, 0x1
	  add       r0, r5, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r8)
	  add       r8, r8, r4
	  lbz       r3, 0x1(r7)
	  lbz       r4, 0x0(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r8)
	  lbz       r3, 0x2(r7)
	  lbz       r4, 0x1(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r8)
	  lbz       r3, 0x3(r7)
	  lbz       r4, 0x2(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r8)
	  lbz       r3, 0x4(r7)
	  lbz       r4, 0x3(r7)
	  addi      r0, r3, 0x1
	  add       r0, r4, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r8)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80020DCC
 * Size:	0002AC
 */
void _MotionComp_11(void)
{
	/*
	.loc_0x0:
	  add       r8, r5, r6
	  lbz       r0, 0x1(r5)
	  lbz       r10, 0x0(r8)
	  mr        r7, r8
	  lbz       r11, 0x1(r8)
	  add       r9, r3, r4
	  add       r0, r0, r10
	  add       r10, r0, r11
	  lbz       r11, 0x0(r5)
	  addi      r0, r10, 0x2
	  add       r0, r11, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r3)
	  lbz       r10, 0x1(r8)
	  lbz       r0, 0x2(r5)
	  lbz       r12, 0x2(r8)
	  add       r0, r0, r10
	  lbz       r11, 0x1(r5)
	  add       r10, r0, r12
	  addi      r0, r10, 0x2
	  add       r0, r11, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r3)
	  lbz       r10, 0x2(r8)
	  lbz       r0, 0x3(r5)
	  lbz       r12, 0x3(r8)
	  add       r0, r0, r10
	  lbz       r11, 0x2(r5)
	  add       r10, r0, r12
	  addi      r0, r10, 0x2
	  add       r0, r11, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r3)
	  lbz       r10, 0x3(r8)
	  lbz       r0, 0x4(r5)
	  lbz       r11, 0x4(r8)
	  add       r8, r8, r6
	  add       r0, r0, r10
	  lbz       r10, 0x3(r5)
	  add       r5, r0, r11
	  addi      r0, r5, 0x2
	  add       r0, r10, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r3)
	  lbz       r3, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  lbz       r10, 0x1(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x0(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  lbz       r10, 0x2(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x1(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  lbz       r10, 0x3(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x2(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  lbz       r0, 0x4(r7)
	  lbz       r10, 0x4(r8)
	  add       r8, r8, r6
	  add       r0, r0, r3
	  lbz       r5, 0x3(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r9)
	  add       r7, r7, r6
	  add       r9, r9, r4
	  lbz       r3, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  lbz       r10, 0x1(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x0(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  lbz       r10, 0x2(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x1(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  lbz       r10, 0x3(r8)
	  add       r0, r0, r3
	  lbz       r5, 0x2(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  lbz       r0, 0x4(r7)
	  lbz       r10, 0x4(r8)
	  add       r8, r8, r6
	  add       r0, r0, r3
	  lbz       r5, 0x3(r7)
	  add       r3, r0, r10
	  addi      r0, r3, 0x2
	  add       r0, r5, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r9)
	  add       r7, r7, r6
	  add       r9, r9, r4
	  lbz       r3, 0x0(r8)
	  lbz       r0, 0x1(r7)
	  lbz       r5, 0x1(r8)
	  add       r0, r0, r3
	  lbz       r4, 0x0(r7)
	  add       r3, r0, r5
	  addi      r0, r3, 0x2
	  add       r0, r4, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r9)
	  lbz       r3, 0x1(r8)
	  lbz       r0, 0x2(r7)
	  lbz       r5, 0x2(r8)
	  add       r0, r0, r3
	  lbz       r4, 0x1(r7)
	  add       r3, r0, r5
	  addi      r0, r3, 0x2
	  add       r0, r4, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r9)
	  lbz       r3, 0x2(r8)
	  lbz       r0, 0x3(r7)
	  lbz       r5, 0x3(r8)
	  add       r0, r0, r3
	  lbz       r4, 0x2(r7)
	  add       r3, r0, r5
	  addi      r0, r3, 0x2
	  add       r0, r4, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r9)
	  lbz       r3, 0x3(r8)
	  lbz       r0, 0x4(r7)
	  lbz       r5, 0x4(r8)
	  add       r0, r0, r3
	  lbz       r4, 0x3(r7)
	  add       r3, r0, r5
	  addi      r0, r3, 0x2
	  add       r0, r4, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r9)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80021078
 * Size:	000A00
 */
void MotionComp(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x48(r1)
	  rlwinm.   r0,r5,0,31,31
	  stmw      r27, 0x34(r1)
	  bne-      .loc_0x4C0
	  rlwinm.   r0,r6,0,31,31
	  bne-      .loc_0x2A0
	  li        r7, 0

	.loc_0x1C:
	  lbz       r10, 0x30(r3)
	  addi      r8, r3, 0x18
	  lbz       r9, 0x31(r3)
	  addi      r0, r10, 0x1
	  lbz       r12, 0x34(r3)
	  sraw      r11, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r9, r9, 0x1
	  lwz       r10, 0x18(r4)
	  sraw      r9, r6, r9
	  mullw     r0, r9, r0
	  add       r0, r0, r10
	  cmpwi     r12, 0
	  addi      r10, r12, 0
	  add       r0, r11, r0
	  ble-      .loc_0x288
	  rlwinm.   r9,r10,31,1,31
	  mtctr     r9
	  beq-      .loc_0x1D0

	.loc_0x68:
	  lwz       r12, 0x0(r8)
	  lwz       r11, 0x14(r4)
	  add       r29, r0, r12
	  lhz       r27, 0x28(r3)
	  lbz       r9, 0x0(r29)
	  add       r28, r11, r12
	  add       r12, r29, r27
	  stb       r9, 0x0(r28)
	  add       r11, r28, r27
	  lbz       r9, 0x1(r29)
	  stb       r9, 0x1(r28)
	  lbz       r9, 0x2(r29)
	  stb       r9, 0x2(r28)
	  lbz       r9, 0x3(r29)
	  stb       r9, 0x3(r28)
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  stb       r9, 0x3(r11)
	  lwz       r12, 0x4(r8)
	  addi      r8, r8, 0x8
	  lwz       r11, 0x14(r4)
	  add       r29, r0, r12
	  lhz       r27, 0x28(r3)
	  lbz       r9, 0x0(r29)
	  add       r28, r11, r12
	  add       r12, r29, r27
	  stb       r9, 0x0(r28)
	  add       r11, r28, r27
	  lbz       r9, 0x1(r29)
	  stb       r9, 0x1(r28)
	  lbz       r9, 0x2(r29)
	  stb       r9, 0x2(r28)
	  lbz       r9, 0x3(r29)
	  stb       r9, 0x3(r28)
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  stb       r9, 0x3(r11)
	  bdnz+     .loc_0x68
	  andi.     r10, r10, 0x1
	  beq-      .loc_0x288

	.loc_0x1D0:
	  mtctr     r10

	.loc_0x1D4:
	  lwz       r12, 0x0(r8)
	  addi      r8, r8, 0x4
	  lwz       r11, 0x14(r4)
	  add       r29, r0, r12
	  lhz       r27, 0x28(r3)
	  lbz       r9, 0x0(r29)
	  add       r28, r11, r12
	  add       r12, r29, r27
	  stb       r9, 0x0(r28)
	  add       r11, r28, r27
	  lbz       r9, 0x1(r29)
	  stb       r9, 0x1(r28)
	  lbz       r9, 0x2(r29)
	  stb       r9, 0x2(r28)
	  lbz       r9, 0x3(r29)
	  stb       r9, 0x3(r28)
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  add       r12, r12, r27
	  stb       r9, 0x3(r11)
	  add       r11, r11, r27
	  lbz       r9, 0x0(r12)
	  stb       r9, 0x0(r11)
	  lbz       r9, 0x1(r12)
	  stb       r9, 0x1(r11)
	  lbz       r9, 0x2(r12)
	  stb       r9, 0x2(r11)
	  lbz       r9, 0x3(r12)
	  stb       r9, 0x3(r11)
	  bdnz+     .loc_0x1D4

	.loc_0x288:
	  addi      r7, r7, 0x1
	  cmpwi     r7, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x1C
	  b         .loc_0x9F4

	.loc_0x2A0:
	  li        r10, 0

	.loc_0x2A4:
	  lbz       r8, 0x30(r3)
	  addi      r12, r3, 0x18
	  lbz       r7, 0x31(r3)
	  addi      r0, r8, 0x1
	  lbz       r27, 0x34(r3)
	  sraw      r8, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r7, r7, 0x1
	  lwz       r9, 0x18(r4)
	  sraw      r7, r6, r7
	  mtctr     r27
	  mullw     r0, r7, r0
	  add       r11, r0, r9
	  cmpwi     r27, 0
	  add       r11, r8, r11
	  ble-      .loc_0x4A8

	.loc_0x2E4:
	  lwz       r28, 0x0(r12)
	  addi      r12, r12, 0x4
	  lhz       r0, 0x28(r3)
	  add       r30, r11, r28
	  lwz       r8, 0x14(r4)
	  add       r7, r30, r0
	  lbz       r27, 0x0(r30)
	  lbz       r9, 0x0(r7)
	  add       r31, r8, r28
	  addi      r8, r7, 0
	  addi      r9, r9, 0x1
	  add       r9, r27, r9
	  srawi     r9, r9, 0x1
	  stb       r9, 0x0(r31)
	  add       r9, r31, r0
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r31)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r31)
	  lbz       r27, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r28, 0x3(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r31)
	  lbz       r27, 0x0(r7)
	  lbz       r28, 0x0(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x0(r9)
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r9)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r9)
	  lbz       r27, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r28, 0x3(r8)
	  add       r8, r8, r0
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r9)
	  add       r9, r9, r0
	  lbz       r27, 0x0(r7)
	  lbz       r28, 0x0(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x0(r9)
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r9)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r8)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r9)
	  lbz       r27, 0x3(r7)
	  lbz       r28, 0x3(r8)
	  add       r8, r8, r0
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r9)
	  add       r7, r7, r0
	  lbz       r28, 0x0(r8)
	  lbz       r27, 0x0(r7)
	  add       r9, r9, r0
	  addi      r0, r27, 0x1
	  add       r0, r28, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r9)
	  lbz       r27, 0x1(r7)
	  lbz       r28, 0x1(r8)
	  addi      r0, r27, 0x1
	  add       r0, r28, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r9)
	  lbz       r27, 0x2(r7)
	  lbz       r28, 0x2(r8)
	  addi      r0, r27, 0x1
	  add       r0, r28, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r9)
	  lbz       r7, 0x3(r7)
	  lbz       r8, 0x3(r8)
	  addi      r0, r7, 0x1
	  add       r0, r8, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r9)
	  bdnz+     .loc_0x2E4

	.loc_0x4A8:
	  addi      r10, r10, 0x1
	  cmpwi     r10, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x2A4
	  b         .loc_0x9F4

	.loc_0x4C0:
	  rlwinm.   r0,r6,0,31,31
	  bne-      .loc_0x6D8
	  li        r9, 0

	.loc_0x4CC:
	  lbz       r8, 0x30(r3)
	  addi      r11, r3, 0x18
	  lbz       r7, 0x31(r3)
	  addi      r0, r8, 0x1
	  lbz       r12, 0x34(r3)
	  sraw      r8, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r7, r7, 0x1
	  lwz       r10, 0x18(r4)
	  sraw      r7, r6, r7
	  mtctr     r12
	  mullw     r0, r7, r0
	  add       r10, r0, r10
	  cmpwi     r12, 0
	  add       r10, r8, r10
	  ble-      .loc_0x6C0

	.loc_0x50C:
	  lwz       r12, 0x0(r11)
	  addi      r11, r11, 0x4
	  lwz       r8, 0x14(r4)
	  add       r30, r10, r12
	  lhz       r0, 0x28(r3)
	  lbz       r7, 0x1(r30)
	  add       r12, r8, r12
	  lbz       r27, 0x0(r30)
	  add       r8, r30, r0
	  addi      r7, r7, 0x1
	  add       r7, r27, r7
	  srawi     r7, r7, 0x1
	  stb       r7, 0x0(r12)
	  add       r7, r12, r0
	  lbz       r27, 0x2(r30)
	  lbz       r28, 0x1(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x1(r12)
	  lbz       r27, 0x3(r30)
	  lbz       r28, 0x2(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x2(r12)
	  lbz       r27, 0x4(r30)
	  lbz       r28, 0x3(r30)
	  addi      r27, r27, 0x1
	  add       r27, r28, r27
	  srawi     r27, r27, 0x1
	  stb       r27, 0x3(r12)
	  lbz       r12, 0x1(r8)
	  lbz       r27, 0x0(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x0(r7)
	  lbz       r12, 0x2(r8)
	  lbz       r27, 0x1(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x1(r7)
	  lbz       r12, 0x3(r8)
	  lbz       r27, 0x2(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x2(r7)
	  lbz       r12, 0x4(r8)
	  lbz       r27, 0x3(r8)
	  add       r8, r8, r0
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r12, 0x1(r8)
	  lbz       r27, 0x0(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x0(r7)
	  lbz       r12, 0x2(r8)
	  lbz       r27, 0x1(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x1(r7)
	  lbz       r12, 0x3(r8)
	  lbz       r27, 0x2(r8)
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x2(r7)
	  lbz       r12, 0x4(r8)
	  lbz       r27, 0x3(r8)
	  add       r8, r8, r0
	  addi      r12, r12, 0x1
	  add       r12, r27, r12
	  srawi     r12, r12, 0x1
	  stb       r12, 0x3(r7)
	  add       r7, r7, r0
	  lbz       r12, 0x1(r8)
	  lbz       r27, 0x0(r8)
	  addi      r0, r12, 0x1
	  add       r0, r27, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x0(r7)
	  lbz       r12, 0x2(r8)
	  lbz       r27, 0x1(r8)
	  addi      r0, r12, 0x1
	  add       r0, r27, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x1(r7)
	  lbz       r12, 0x3(r8)
	  lbz       r27, 0x2(r8)
	  addi      r0, r12, 0x1
	  add       r0, r27, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x2(r7)
	  lbz       r12, 0x4(r8)
	  lbz       r8, 0x3(r8)
	  addi      r0, r12, 0x1
	  add       r0, r8, r0
	  srawi     r0, r0, 0x1
	  stb       r0, 0x3(r7)
	  bdnz+     .loc_0x50C

	.loc_0x6C0:
	  addi      r9, r9, 0x1
	  cmpwi     r9, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x4CC
	  b         .loc_0x9F4

	.loc_0x6D8:
	  li        r10, 0

	.loc_0x6DC:
	  lbz       r8, 0x30(r3)
	  addi      r12, r3, 0x18
	  lbz       r7, 0x31(r3)
	  addi      r0, r8, 0x1
	  lbz       r27, 0x34(r3)
	  sraw      r8, r5, r0
	  lhz       r0, 0x28(r3)
	  addi      r7, r7, 0x1
	  lwz       r9, 0x18(r4)
	  sraw      r7, r6, r7
	  mtctr     r27
	  mullw     r0, r7, r0
	  add       r11, r0, r9
	  cmpwi     r27, 0
	  add       r11, r8, r11
	  ble-      .loc_0x9E0

	.loc_0x71C:
	  lwz       r28, 0x0(r12)
	  addi      r12, r12, 0x4
	  lhz       r0, 0x28(r3)
	  add       r30, r11, r28
	  lwz       r8, 0x14(r4)
	  add       r7, r30, r0
	  lbz       r9, 0x1(r30)
	  lbz       r27, 0x0(r7)
	  add       r31, r8, r28
	  lbz       r28, 0x1(r7)
	  addi      r8, r7, 0
	  add       r9, r9, r27
	  add       r9, r9, r28
	  lbz       r27, 0x0(r30)
	  addi      r9, r9, 0x2
	  add       r9, r27, r9
	  srawi     r9, r9, 0x2
	  stb       r9, 0x0(r31)
	  add       r9, r31, r0
	  lbz       r28, 0x1(r7)
	  lbz       r27, 0x2(r30)
	  lbz       r29, 0x2(r7)
	  add       r27, r27, r28
	  lbz       r28, 0x1(r30)
	  add       r27, r27, r29
	  addi      r27, r27, 0x2
	  add       r27, r28, r27
	  srawi     r27, r27, 0x2
	  stb       r27, 0x1(r31)
	  lbz       r28, 0x2(r7)
	  lbz       r27, 0x3(r30)
	  lbz       r29, 0x3(r7)
	  add       r27, r27, r28
	  lbz       r28, 0x2(r30)
	  add       r27, r27, r29
	  addi      r27, r27, 0x2
	  add       r27, r28, r27
	  srawi     r27, r27, 0x2
	  stb       r27, 0x2(r31)
	  lbz       r29, 0x4(r30)
	  lbz       r28, 0x3(r7)
	  lbz       r27, 0x4(r7)
	  add       r7, r7, r0
	  add       r29, r29, r28
	  lbz       r30, 0x3(r30)
	  add       r29, r29, r27
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x3(r31)
	  lbz       r30, 0x0(r7)
	  lbz       r29, 0x1(r8)
	  lbz       r31, 0x1(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x0(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x0(r9)
	  lbz       r30, 0x1(r7)
	  lbz       r29, 0x2(r8)
	  lbz       r31, 0x2(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x1(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x1(r9)
	  lbz       r30, 0x2(r7)
	  lbz       r29, 0x3(r8)
	  lbz       r31, 0x3(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x2(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x2(r9)
	  lbz       r30, 0x3(r7)
	  lbz       r29, 0x4(r8)
	  lbz       r31, 0x4(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x3(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x3(r9)
	  add       r7, r7, r0
	  add       r8, r8, r0
	  lbz       r30, 0x0(r7)
	  lbz       r29, 0x1(r8)
	  add       r9, r9, r0
	  lbz       r31, 0x1(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x0(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x0(r9)
	  lbz       r30, 0x1(r7)
	  lbz       r29, 0x2(r8)
	  lbz       r31, 0x2(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x1(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x1(r9)
	  lbz       r30, 0x2(r7)
	  lbz       r29, 0x3(r8)
	  lbz       r31, 0x3(r7)
	  add       r29, r29, r30
	  lbz       r30, 0x2(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x2(r9)
	  lbz       r30, 0x3(r7)
	  lbz       r29, 0x4(r8)
	  lbz       r31, 0x4(r7)
	  add       r7, r7, r0
	  add       r29, r29, r30
	  lbz       r30, 0x3(r8)
	  add       r29, r29, r31
	  addi      r29, r29, 0x2
	  add       r29, r30, r29
	  srawi     r29, r29, 0x2
	  stb       r29, 0x3(r9)
	  add       r8, r8, r0
	  add       r9, r9, r0
	  lbz       r29, 0x0(r7)
	  lbz       r0, 0x1(r8)
	  lbz       r31, 0x1(r7)
	  add       r0, r0, r29
	  lbz       r30, 0x0(r8)
	  add       r29, r0, r31
	  addi      r0, r29, 0x2
	  add       r0, r30, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x0(r9)
	  lbz       r29, 0x1(r7)
	  lbz       r0, 0x2(r8)
	  lbz       r31, 0x2(r7)
	  add       r0, r0, r29
	  lbz       r30, 0x1(r8)
	  add       r29, r0, r31
	  addi      r0, r29, 0x2
	  add       r0, r30, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x1(r9)
	  lbz       r30, 0x2(r7)
	  lbz       r0, 0x3(r8)
	  lbz       r29, 0x3(r7)
	  add       r0, r0, r30
	  lbz       r31, 0x2(r8)
	  add       r30, r0, r29
	  addi      r0, r30, 0x2
	  add       r0, r31, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x2(r9)
	  lbz       r30, 0x3(r7)
	  lbz       r0, 0x4(r8)
	  lbz       r7, 0x4(r7)
	  add       r0, r0, r30
	  lbz       r8, 0x3(r8)
	  add       r7, r0, r7
	  addi      r0, r7, 0x2
	  add       r0, r8, r0
	  srawi     r0, r0, 0x2
	  stb       r0, 0x3(r9)
	  bdnz+     .loc_0x71C

	.loc_0x9E0:
	  addi      r10, r10, 0x1
	  cmpwi     r10, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x6DC

	.loc_0x9F4:
	  lmw       r27, 0x34(r1)
	  addi      r1, r1, 0x48
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80021A78
 * Size:	00041C
 */
void decode_PB_cc(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x60(r1)
	  cmpwi     r5, 0x1
	  rlwinm    r6,r6,5,0,26
	  stw       r31, 0x5C(r1)
	  rlwinm    r0,r5,4,0,27
	  or        r7, r6, r0
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  bne-      .loc_0x12C
	  li        r9, 0

	.loc_0x28:
	  lbz       r5, 0x34(r3)
	  addi      r8, r3, 0x10
	  lwz       r6, 0x8(r4)
	  li        r10, 0
	  cmpwi     r5, 0
	  ble-      .loc_0x114
	  cmpwi     r5, 0x8
	  subi      r11, r5, 0x8
	  ble-      .loc_0xEC
	  addi      r0, r11, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r11, 0
	  mtctr     r0
	  ble-      .loc_0xEC

	.loc_0x60:
	  lhz       r0, 0x0(r8)
	  addi      r10, r10, 0x8
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x2(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x4(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x6(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0x8(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0xA(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0xC(r8)
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  lhz       r0, 0xE(r8)
	  addi      r8, r8, 0x10
	  rlwinm    r11,r0,1,0,30
	  addi      r0, r11, 0x1
	  stbx      r7, r6, r0
	  bdnz+     .loc_0x60

	.loc_0xEC:
	  sub       r0, r5, r10
	  cmpw      r10, r5
	  mtctr     r0
	  bge-      .loc_0x114

	.loc_0xFC:
	  lhz       r0, 0x0(r8)
	  addi      r8, r8, 0x2
	  rlwinm    r5,r0,1,0,30
	  addi      r0, r5, 0x1
	  stbx      r7, r6, r0
	  bdnz+     .loc_0xFC

	.loc_0x114:
	  addi      r9, r9, 0x1
	  cmpwi     r9, 0x3
	  addi      r4, r4, 0x34
	  addi      r3, r3, 0x38
	  blt+      .loc_0x28
	  b         .loc_0x408

	.loc_0x12C:
	  lbz       r0, 0x34(r3)
	  addi      r8, r3, 0x618C
	  lwz       r6, 0x8(r4)
	  addi      r9, r3, 0x61B4
	  cmpwi     r0, 0
	  mtctr     r0
	  addi      r5, r3, 0x10
	  rlwinm    r0,r7,0,24,31
	  ble-      .loc_0x28C

	.loc_0x150:
	  lwz       r10, 0x0(r4)
	  lhz       r12, 0x0(r5)
	  addi      r5, r5, 0x2
	  cmpwi     r10, 0
	  bne-      .loc_0x270
	  lwz       r29, 0x10(r8)
	  lwz       r31, 0x4(r29)
	  b         .loc_0x1BC

	.loc_0x170:
	  lwz       r30, 0xC(r8)
	  cmpwi     r30, 0
	  bge-      .loc_0x198
	  lwz       r11, 0x0(r8)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r8)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r8)
	  b         .loc_0x19C

	.loc_0x198:
	  lwz       r10, 0x8(r8)

	.loc_0x19C:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r8)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r31,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r31, r29, r10

	.loc_0x1BC:
	  cmpwi     r31, 0x100
	  bge+      .loc_0x170
	  rlwinm    r10,r31,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  extsh     r11, r10
	  extsh.    r10, r11
	  bne-      .loc_0x25C
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r6, r10
	  lwz       r29, 0x10(r9)
	  lwz       r12, 0x4(r29)
	  b         .loc_0x240

	.loc_0x1F4:
	  lwz       r30, 0xC(r9)
	  cmpwi     r30, 0
	  bge-      .loc_0x21C
	  lwz       r11, 0x0(r9)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r9)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r9)
	  b         .loc_0x220

	.loc_0x21C:
	  lwz       r10, 0x8(r9)

	.loc_0x220:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r9)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r12,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r12, r29, r10

	.loc_0x240:
	  cmpwi     r12, 0x100
	  bge+      .loc_0x1F4
	  rlwinm    r10,r12,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  stw       r10, 0x0(r4)
	  b         .loc_0x288

	.loc_0x25C:
	  rlwinm    r10,r12,1,0,30
	  or        r11, r0, r11
	  addi      r10, r10, 0x1
	  stbx      r11, r6, r10
	  b         .loc_0x288

	.loc_0x270:
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r6, r10
	  lwz       r10, 0x0(r4)
	  subi      r10, r10, 0x1
	  stw       r10, 0x0(r4)

	.loc_0x288:
	  bdnz+     .loc_0x150

	.loc_0x28C:
	  addi      r11, r3, 0x38
	  lwz       r8, 0x3C(r4)
	  lbz       r10, 0x6C(r3)
	  addi      r5, r3, 0x61A0
	  lwz       r9, 0x70(r4)
	  addi      r6, r3, 0x61C8
	  cmpwi     r10, 0
	  mtctr     r10
	  addi      r3, r11, 0x10
	  ble-      .loc_0x408

	.loc_0x2B4:
	  lwz       r10, 0x34(r4)
	  lhz       r12, 0x0(r3)
	  addi      r3, r3, 0x2
	  cmpwi     r10, 0
	  bne-      .loc_0x3E8
	  lwz       r29, 0x10(r5)
	  lwz       r31, 0x4(r29)
	  b         .loc_0x320

	.loc_0x2D4:
	  lwz       r30, 0xC(r5)
	  cmpwi     r30, 0
	  bge-      .loc_0x2FC
	  lwz       r11, 0x0(r5)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r5)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r5)
	  b         .loc_0x300

	.loc_0x2FC:
	  lwz       r10, 0x8(r5)

	.loc_0x300:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r5)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r31,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r31, r29, r10

	.loc_0x320:
	  cmpwi     r31, 0x100
	  bge+      .loc_0x2D4
	  rlwinm    r10,r31,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  extsh     r30, r10
	  extsh.    r10, r30
	  bne-      .loc_0x3C4
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r8, r10
	  stbx      r7, r9, r10
	  lwz       r29, 0x10(r6)
	  lwz       r12, 0x4(r29)
	  b         .loc_0x3A8

	.loc_0x35C:
	  lwz       r30, 0xC(r6)
	  cmpwi     r30, 0
	  bge-      .loc_0x384
	  lwz       r11, 0x0(r6)
	  li        r30, 0x1F
	  addi      r10, r11, 0x4
	  stw       r10, 0x0(r6)
	  lwz       r10, 0x0(r11)
	  stw       r10, 0x8(r6)
	  b         .loc_0x388

	.loc_0x384:
	  lwz       r10, 0x8(r6)

	.loc_0x388:
	  srw       r11, r10, r30
	  subi      r10, r30, 0x1
	  stw       r10, 0xC(r6)
	  rlwinm    r11,r11,11,20,20
	  rlwinm    r10,r12,2,0,29
	  add       r10, r11, r10
	  addi      r10, r10, 0x8
	  lwzx      r12, r29, r10

	.loc_0x3A8:
	  cmpwi     r12, 0x100
	  bge+      .loc_0x35C
	  rlwinm    r10,r12,2,0,29
	  addi      r10, r10, 0x8
	  lwzx      r10, r29, r10
	  stw       r10, 0x34(r4)
	  b         .loc_0x404

	.loc_0x3C4:
	  rlwinm    r11,r30,0,28,31
	  rlwinm    r29,r12,1,0,30
	  rlwinm    r10,r30,28,28,31
	  or        r12, r0, r11
	  addi      r11, r29, 0x1
	  stbx      r12, r8, r11
	  or        r10, r0, r10
	  stbx      r10, r9, r11
	  b         .loc_0x404

	.loc_0x3E8:
	  rlwinm    r10,r12,1,0,30
	  addi      r10, r10, 0x1
	  stbx      r7, r8, r10
	  stbx      r7, r9, r10
	  lwz       r10, 0x34(r4)
	  subi      r10, r10, 0x1
	  stw       r10, 0x34(r4)

	.loc_0x404:
	  bdnz+     .loc_0x2B4

	.loc_0x408:
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x60
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80021E94
 * Size:	00086C
 */
void PrediAotBlock(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r11, 0x8039
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x120(r1)
	  stmw      r16, 0xE0(r1)
	  addi      r23, r3, 0
	  lwz       r17, 0x128(r1)
	  addi      r24, r4, 0
	  addi      r20, r5, 0
	  addi      r25, r6, 0
	  addi      r19, r8, 0
	  addi      r18, r9, 0
	  addi      r26, r10, 0
	  subi      r22, r11, 0x4300
	  subi      r27, r7, 0x1
	  stw       r0, 0x38(r1)
	  stw       r0, 0xDC(r1)
	  stw       r0, 0xD8(r1)
	  stw       r0, 0xD4(r1)
	  stw       r0, 0xD0(r1)
	  stw       r0, 0xCC(r1)
	  stw       r0, 0xC8(r1)
	  stw       r0, 0xC4(r1)
	  stw       r0, 0xC0(r1)
	  stw       r0, 0xBC(r1)
	  stw       r0, 0xB8(r1)
	  stw       r0, 0xB4(r1)
	  stw       r0, 0xB0(r1)
	  stw       r0, 0xAC(r1)
	  stw       r0, 0xA8(r1)
	  stw       r0, 0xA4(r1)
	  stw       r0, 0xA0(r1)
	  b         .loc_0x1E4

	.loc_0x88:
	  addi      r3, r23, 0
	  addi      r6, r19, 0
	  addi      r7, r18, 0
	  addi      r8, r26, 0
	  addi      r4, r1, 0x3C
	  addi      r5, r1, 0x38
	  bl        .loc_0x86C
	  lbz       r4, 0x3C(r1)
	  lbz       r0, 0x3D(r1)
	  mullw     r4, r3, r4
	  lwz       r5, 0xA0(r1)
	  add       r4, r5, r4
	  stw       r4, 0xA0(r1)
	  mullw     r0, r3, r0
	  lwz       r4, 0xA4(r1)
	  add       r0, r4, r0
	  stw       r0, 0xA4(r1)
	  lbz       r0, 0x3E(r1)
	  lwz       r4, 0xA8(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xA8(r1)
	  lbz       r0, 0x3F(r1)
	  lwz       r4, 0xAC(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xAC(r1)
	  lbz       r0, 0x40(r1)
	  lwz       r4, 0xB0(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xB0(r1)
	  lbz       r0, 0x41(r1)
	  lwz       r4, 0xB4(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xB4(r1)
	  lbz       r0, 0x42(r1)
	  lwz       r4, 0xB8(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xB8(r1)
	  lbz       r0, 0x43(r1)
	  lwz       r4, 0xBC(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xBC(r1)
	  lbz       r0, 0x44(r1)
	  lwz       r4, 0xC0(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xC0(r1)
	  lbz       r0, 0x45(r1)
	  lwz       r4, 0xC4(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xC4(r1)
	  lbz       r0, 0x46(r1)
	  lwz       r4, 0xC8(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xC8(r1)
	  lbz       r0, 0x47(r1)
	  lwz       r4, 0xCC(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xCC(r1)
	  lbz       r0, 0x48(r1)
	  lwz       r4, 0xD0(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xD0(r1)
	  lbz       r0, 0x49(r1)
	  lwz       r4, 0xD4(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xD4(r1)
	  lbz       r0, 0x4A(r1)
	  lwz       r4, 0xD8(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xD8(r1)
	  lbz       r0, 0x4B(r1)
	  lwz       r4, 0xDC(r1)
	  mullw     r0, r3, r0
	  add       r0, r4, r0
	  stw       r0, 0xDC(r1)

	.loc_0x1E4:
	  rlwinm.   r0,r27,0,24,31
	  subi      r27, r27, 0x1
	  bne+      .loc_0x88
	  lwz       r5, 0xA8(r1)
	  lis       r3, 0x8022
	  lwz       r0, 0xA4(r1)
	  rlwinm    r4,r17,2,0,29
	  lwz       r6, 0xAC(r1)
	  add       r0, r0, r5
	  lwz       r5, 0xB0(r1)
	  add       r0, r0, r6
	  lwz       r6, 0xB4(r1)
	  add       r0, r0, r5
	  lwz       r5, 0xB8(r1)
	  add       r0, r0, r6
	  lwz       r6, 0xBC(r1)
	  add       r0, r0, r5
	  lwz       r5, 0xC0(r1)
	  add       r0, r0, r6
	  lwz       r6, 0xC4(r1)
	  add       r0, r0, r5
	  lwz       r5, 0xC8(r1)
	  add       r0, r0, r6
	  lwz       r6, 0xCC(r1)
	  add       r0, r0, r5
	  lwz       r5, 0xD0(r1)
	  add       r0, r0, r6
	  lwz       r6, 0xD4(r1)
	  add       r5, r0, r5
	  lwz       r7, 0xD8(r1)
	  addi      r0, r3, 0x72C0
	  lwz       r8, 0xDC(r1)
	  add       r5, r5, r6
	  lwz       r6, 0xA0(r1)
	  add       r3, r0, r4
	  add       r0, r5, r7
	  lwz       r12, 0x0(r3)
	  add       r0, r0, r8
	  add       r0, r6, r0
	  mtlr      r12
	  addi      r5, r20, 0
	  addi      r6, r25, 0
	  srawi     r29, r0, 0x4
	  addi      r3, r1, 0x90
	  li        r4, 0x4
	  blrl
	  lbz       r3, 0x92(r1)
	  lbz       r0, 0x91(r1)
	  lbz       r4, 0x93(r1)
	  add       r6, r0, r3
	  lbz       r5, 0x94(r1)
	  add       r7, r6, r4
	  lbz       r6, 0x95(r1)
	  add       r8, r7, r5
	  lbz       r7, 0x96(r1)
	  add       r9, r8, r6
	  lbz       r8, 0x97(r1)
	  add       r10, r9, r7
	  lbz       r9, 0x98(r1)
	  add       r11, r10, r8
	  lbz       r10, 0x99(r1)
	  add       r12, r11, r9
	  lbz       r11, 0x9A(r1)
	  add       r17, r12, r10
	  lbz       r12, 0x9B(r1)
	  add       r17, r17, r11
	  lbz       r18, 0x9C(r1)
	  add       r17, r17, r12
	  lbz       r19, 0x9D(r1)
	  add       r17, r17, r18
	  lbz       r20, 0x9E(r1)
	  add       r17, r17, r19
	  lbz       r21, 0x9F(r1)
	  add       r17, r17, r20
	  lbz       r16, 0x90(r1)
	  add       r17, r17, r21
	  addi      r17, r17, 0x8
	  add       r17, r16, r17
	  srawi     r17, r17, 0x4
	  sub       r27, r16, r17
	  sub       r0, r0, r17
	  stw       r27, 0x50(r1)
	  cmpw      r0, r27
	  stw       r0, 0x54(r1)
	  mr        r28, r27
	  bge-      .loc_0x344
	  mr        r27, r0
	  b         .loc_0x34C

	.loc_0x344:
	  ble-      .loc_0x34C
	  mr        r28, r0

	.loc_0x34C:
	  sub       r0, r3, r17
	  cmpw      r0, r27
	  stw       r0, 0x58(r1)
	  bge-      .loc_0x364
	  mr        r27, r0
	  b         .loc_0x370

	.loc_0x364:
	  cmpw      r0, r28
	  ble-      .loc_0x370
	  mr        r28, r0

	.loc_0x370:
	  sub       r0, r4, r17
	  cmpw      r0, r27
	  stw       r0, 0x5C(r1)
	  bge-      .loc_0x388
	  mr        r27, r0
	  b         .loc_0x394

	.loc_0x388:
	  cmpw      r0, r28
	  ble-      .loc_0x394
	  mr        r28, r0

	.loc_0x394:
	  sub       r0, r5, r17
	  cmpw      r0, r27
	  stw       r0, 0x60(r1)
	  bge-      .loc_0x3AC
	  mr        r27, r0
	  b         .loc_0x3B8

	.loc_0x3AC:
	  cmpw      r0, r28
	  ble-      .loc_0x3B8
	  mr        r28, r0

	.loc_0x3B8:
	  sub       r0, r6, r17
	  cmpw      r0, r27
	  stw       r0, 0x64(r1)
	  bge-      .loc_0x3D0
	  mr        r27, r0
	  b         .loc_0x3DC

	.loc_0x3D0:
	  cmpw      r0, r28
	  ble-      .loc_0x3DC
	  mr        r28, r0

	.loc_0x3DC:
	  sub       r0, r7, r17
	  cmpw      r0, r27
	  stw       r0, 0x68(r1)
	  bge-      .loc_0x3F4
	  mr        r27, r0
	  b         .loc_0x400

	.loc_0x3F4:
	  cmpw      r0, r28
	  ble-      .loc_0x400
	  mr        r28, r0

	.loc_0x400:
	  sub       r0, r8, r17
	  cmpw      r0, r27
	  stw       r0, 0x6C(r1)
	  bge-      .loc_0x418
	  mr        r27, r0
	  b         .loc_0x424

	.loc_0x418:
	  cmpw      r0, r28
	  ble-      .loc_0x424
	  mr        r28, r0

	.loc_0x424:
	  sub       r0, r9, r17
	  cmpw      r0, r27
	  stw       r0, 0x70(r1)
	  bge-      .loc_0x43C
	  mr        r27, r0
	  b         .loc_0x448

	.loc_0x43C:
	  cmpw      r0, r28
	  ble-      .loc_0x448
	  mr        r28, r0

	.loc_0x448:
	  sub       r0, r10, r17
	  cmpw      r0, r27
	  stw       r0, 0x74(r1)
	  bge-      .loc_0x460
	  mr        r27, r0
	  b         .loc_0x46C

	.loc_0x460:
	  cmpw      r0, r28
	  ble-      .loc_0x46C
	  mr        r28, r0

	.loc_0x46C:
	  sub       r0, r11, r17
	  cmpw      r0, r27
	  stw       r0, 0x78(r1)
	  bge-      .loc_0x484
	  mr        r27, r0
	  b         .loc_0x490

	.loc_0x484:
	  cmpw      r0, r28
	  ble-      .loc_0x490
	  mr        r28, r0

	.loc_0x490:
	  sub       r0, r12, r17
	  cmpw      r0, r27
	  stw       r0, 0x7C(r1)
	  bge-      .loc_0x4A8
	  mr        r27, r0
	  b         .loc_0x4B4

	.loc_0x4A8:
	  cmpw      r0, r28
	  ble-      .loc_0x4B4
	  mr        r28, r0

	.loc_0x4B4:
	  sub       r0, r18, r17
	  cmpw      r0, r27
	  stw       r0, 0x80(r1)
	  bge-      .loc_0x4CC
	  mr        r27, r0
	  b         .loc_0x4D8

	.loc_0x4CC:
	  cmpw      r0, r28
	  ble-      .loc_0x4D8
	  mr        r28, r0

	.loc_0x4D8:
	  sub       r0, r19, r17
	  cmpw      r0, r27
	  stw       r0, 0x84(r1)
	  bge-      .loc_0x4F0
	  mr        r27, r0
	  b         .loc_0x4FC

	.loc_0x4F0:
	  cmpw      r0, r28
	  ble-      .loc_0x4FC
	  mr        r28, r0

	.loc_0x4FC:
	  sub       r0, r20, r17
	  cmpw      r0, r27
	  stw       r0, 0x88(r1)
	  bge-      .loc_0x514
	  mr        r27, r0
	  b         .loc_0x520

	.loc_0x514:
	  cmpw      r0, r28
	  ble-      .loc_0x520
	  mr        r28, r0

	.loc_0x520:
	  sub       r0, r21, r17
	  cmpw      r0, r27
	  stw       r0, 0x8C(r1)
	  bge-      .loc_0x538
	  mr        r27, r0
	  b         .loc_0x544

	.loc_0x538:
	  cmpw      r0, r28
	  ble-      .loc_0x544
	  mr        r28, r0

	.loc_0x544:
	  mulli     r0, r26, 0x14
	  lbz       r26, 0x6CD0(r23)
	  lwz       r19, 0x6CC8(r23)
	  lwz       r20, 0x6CCC(r23)
	  add       r31, r23, r0
	  addi      r30, r31, 0x60D8
	  addi      r18, r30, 0
	  li        r21, 0

	.loc_0x564:
	  lwz       r17, 0x60E8(r31)
	  lwz       r16, 0x4(r17)
	  b         .loc_0x58C

	.loc_0x570:
	  mr        r3, r18
	  bl        -0x2C20
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r16,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r16, r17, r0

	.loc_0x58C:
	  cmpwi     r16, 0x100
	  bge+      .loc_0x570
	  rlwinm    r3,r16,2,0,29
	  addi      r0, r3, 0x8
	  lwzx      r0, r17, r0
	  cmpw      r20, r0
	  add       r21, r21, r0
	  bge+      .loc_0x564
	  cmpw      r0, r19
	  bge+      .loc_0x564
	  lbz       r0, 0x6CD1(r23)
	  li        r19, 0
	  lwz       r18, 0x6CC8(r23)
	  sraw      r0, r21, r0
	  lwz       r20, 0x6CCC(r23)
	  slw       r0, r0, r26
	  sub       r29, r0, r29

	.loc_0x5D0:
	  lwz       r17, 0x60E8(r31)
	  lwz       r16, 0x4(r17)
	  b         .loc_0x5F8

	.loc_0x5DC:
	  mr        r3, r30
	  bl        -0x2C8C
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r16,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r16, r17, r0

	.loc_0x5F8:
	  cmpwi     r16, 0x100
	  bge+      .loc_0x5DC
	  rlwinm    r3,r16,2,0,29
	  addi      r0, r3, 0x8
	  lwzx      r0, r17, r0
	  cmpw      r20, r0
	  add       r19, r19, r0
	  bge+      .loc_0x5D0
	  cmpw      r0, r18
	  bge+      .loc_0x5D0
	  sub       r3, r28, r27
	  lbz       r0, 0x6CD1(r23)
	  rlwinm    r3,r3,2,0,29
	  add       r3, r22, r3
	  lwz       r4, 0x240(r3)
	  sraw      r0, r19, r0
	  li        r3, 0x2
	  mullw     r0, r4, r0
	  mtctr     r3
	  addi      r5, r1, 0xA0
	  addi      r4, r5, 0
	  addi      r3, r1, 0x50

	.loc_0x650:
	  lwz       r6, 0x0(r3)
	  lwz       r7, 0x0(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x0(r4)
	  lwz       r6, 0x4(r3)
	  lwz       r7, 0x4(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x4(r4)
	  lwz       r6, 0x8(r3)
	  lwz       r7, 0x8(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x8(r4)
	  lwz       r6, 0xC(r3)
	  lwz       r7, 0xC(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0xC(r4)
	  lwz       r6, 0x10(r3)
	  lwz       r7, 0x10(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x10(r4)
	  lwz       r6, 0x14(r3)
	  lwz       r7, 0x14(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x14(r4)
	  lwz       r6, 0x18(r3)
	  lwz       r7, 0x18(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x18(r4)
	  lwz       r6, 0x1C(r3)
	  addi      r3, r3, 0x20
	  lwz       r7, 0x1C(r4)
	  mullw     r6, r0, r6
	  add       r6, r6, r7
	  add       r6, r29, r6
	  stw       r6, 0x1C(r4)
	  addi      r4, r4, 0x20
	  bdnz+     .loc_0x650
	  li        r0, 0x2
	  mtctr     r0
	  addi      r4, r1, 0x90
	  addi      r3, r1, 0xA0
	  li        r6, 0

	.loc_0x730:
	  lwz       r0, 0x0(r5)
	  addi      r11, r6, 0x1
	  lbz       r7, 0x0(r4)
	  addi      r9, r6, 0x2
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  addi      r7, r6, 0x3
	  rlwinm    r10,r9,2,0,29
	  stb       r0, 0x0(r24)
	  rlwinm    r11,r11,2,0,29
	  rlwinm    r8,r7,2,0,29
	  lwzx      r0, r3, r11
	  addi      r11, r6, 0x5
	  lbz       r7, 0x1(r4)
	  addi      r9, r6, 0x6
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  addi      r7, r6, 0x7
	  rlwinm    r11,r11,2,0,29
	  stb       r0, 0x1(r24)
	  addi      r6, r6, 0x8
	  lwzx      r0, r3, r10
	  rlwinm    r10,r9,2,0,29
	  lbz       r9, 0x2(r4)
	  sraw      r0, r0, r26
	  add       r9, r9, r0
	  addi      r0, r9, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x2(r24)
	  lwzx      r0, r3, r8
	  rlwinm    r8,r7,2,0,29
	  lbz       r7, 0x3(r4)
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x3(r24)
	  add       r24, r24, r25
	  lwz       r0, 0x10(r5)
	  addi      r5, r5, 0x20
	  lbz       r7, 0x4(r4)
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x0(r24)
	  lwzx      r0, r3, r11
	  lbz       r7, 0x5(r4)
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x1(r24)
	  lwzx      r0, r3, r10
	  lbz       r9, 0x6(r4)
	  sraw      r0, r0, r26
	  add       r9, r9, r0
	  addi      r0, r9, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x2(r24)
	  lwzx      r0, r3, r8
	  lbz       r7, 0x7(r4)
	  addi      r4, r4, 0x8
	  sraw      r0, r0, r26
	  add       r7, r7, r0
	  addi      r0, r7, 0x80
	  lbzx      r0, r22, r0
	  stb       r0, 0x3(r24)
	  add       r24, r24, r25
	  bdnz+     .loc_0x730
	  lmw       r16, 0xE0(r1)
	  lwz       r0, 0x124(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr

	.loc_0x86C:
	*/
}

/*
 * --INFO--
 * Address:	80022700
 * Size:	0004C4
 */
void GetMCAotBasis(void)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x40(r1)
	  rlwinm    r0,r8,4,0,27
	  add       r11, r3, r0
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  lwz       r10, 0x61DC(r11)
	  addi      r0, r10, 0x1
	  stw       r0, 0x61DC(r11)
	  lwz       r9, 0x61DC(r11)
	  lbz       r10, 0x0(r10)
	  addi      r0, r9, 0x1
	  stw       r0, 0x61DC(r11)
	  lbz       r0, 0x6260(r3)
	  lbz       r9, 0x0(r9)
	  cmplwi    r0, 0
	  addi      r0, r9, 0
	  rlwimi    r0,r10,8,16,23
	  beq-      .loc_0x78
	  rlwinm    r9,r0,26,27,31
	  mullw     r10, r9, r7
	  add       r11, r10, r6
	  rlwinm    r9,r0,20,31,31
	  rlwinm    r12,r0,0,26,31
	  rlwinm    r6,r0,21,31,31
	  li        r10, 0x1
	  add       r11, r12, r11
	  slw       r6, r10, r6
	  slw       r7, r7, r9
	  b         .loc_0xA0

	.loc_0x78:
	  rlwinm    r9,r0,0,26,31
	  mullw     r10, r9, r7
	  add       r11, r10, r6
	  rlwinm    r9,r0,21,31,31
	  rlwinm    r12,r0,26,27,31
	  rlwinm    r6,r0,20,31,31
	  li        r10, 0x1
	  add       r11, r12, r11
	  slw       r6, r10, r6
	  slw       r7, r7, r9

	.loc_0xA0:
	  lbz       r9, 0x0(r11)
	  add       r29, r11, r6
	  rlwinm    r9,r9,28,28,31
	  stb       r9, 0x0(r4)
	  rlwinm    r12,r9,0,24,31
	  addi      r10, r9, 0
	  lbz       r31, 0x0(r29)
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x1(r4)
	  ble-      .loc_0xD4
	  mr        r10, r30
	  b         .loc_0xDC

	.loc_0xD4:
	  bge-      .loc_0xDC
	  mr        r9, r30

	.loc_0xDC:
	  add       r29, r29, r6
	  lbz       r31, 0x0(r29)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x2(r4)
	  ble-      .loc_0x100
	  mr        r10, r30
	  b         .loc_0x110

	.loc_0x100:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x110
	  mr        r9, r30

	.loc_0x110:
	  add       r29, r29, r6
	  lbz       r31, 0x0(r29)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x3(r4)
	  ble-      .loc_0x134
	  mr        r10, r30
	  b         .loc_0x144

	.loc_0x134:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x144
	  mr        r9, r30

	.loc_0x144:
	  add       r11, r11, r7
	  lbz       r31, 0x0(r11)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x4(r4)
	  ble-      .loc_0x168
	  mr        r10, r30
	  b         .loc_0x178

	.loc_0x168:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x178
	  mr        r9, r30

	.loc_0x178:
	  add       r30, r11, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r31,r31,28,28,31
	  cmplw     r31, r12
	  stb       r31, 0x5(r4)
	  ble-      .loc_0x19C
	  mr        r10, r31
	  b         .loc_0x1AC

	.loc_0x19C:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r31, r12
	  bge-      .loc_0x1AC
	  mr        r9, r31

	.loc_0x1AC:
	  add       r30, r30, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r31,r31,28,28,31
	  cmplw     r31, r12
	  stb       r31, 0x6(r4)
	  ble-      .loc_0x1D0
	  mr        r10, r31
	  b         .loc_0x1E0

	.loc_0x1D0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r31, r12
	  bge-      .loc_0x1E0
	  mr        r9, r31

	.loc_0x1E0:
	  add       r30, r30, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x7(r4)
	  ble-      .loc_0x204
	  mr        r10, r30
	  b         .loc_0x214

	.loc_0x204:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x214
	  mr        r9, r30

	.loc_0x214:
	  add       r11, r11, r7
	  lbz       r31, 0x0(r11)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0x8(r4)
	  ble-      .loc_0x238
	  mr        r10, r30
	  b         .loc_0x248

	.loc_0x238:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x248
	  mr        r9, r30

	.loc_0x248:
	  add       r30, r11, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r31,r31,28,28,31
	  cmplw     r31, r12
	  stb       r31, 0x9(r4)
	  ble-      .loc_0x26C
	  mr        r10, r31
	  b         .loc_0x27C

	.loc_0x26C:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r31, r12
	  bge-      .loc_0x27C
	  mr        r9, r31

	.loc_0x27C:
	  add       r30, r30, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r31,r31,28,28,31
	  cmplw     r31, r12
	  stb       r31, 0xA(r4)
	  ble-      .loc_0x2A0
	  mr        r10, r31
	  b         .loc_0x2B0

	.loc_0x2A0:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r31, r12
	  bge-      .loc_0x2B0
	  mr        r9, r31

	.loc_0x2B0:
	  add       r30, r30, r6
	  lbz       r31, 0x0(r30)
	  rlwinm    r12,r10,0,24,31
	  rlwinm    r30,r31,28,28,31
	  cmplw     r30, r12
	  stb       r30, 0xB(r4)
	  ble-      .loc_0x2D4
	  mr        r10, r30
	  b         .loc_0x2E4

	.loc_0x2D4:
	  rlwinm    r12,r9,0,24,31
	  cmplw     r30, r12
	  bge-      .loc_0x2E4
	  mr        r9, r30

	.loc_0x2E4:
	  add       r11, r11, r7
	  lbz       r12, 0x0(r11)
	  rlwinm    r7,r10,0,24,31
	  rlwinm    r12,r12,28,28,31
	  cmplw     r12, r7
	  stb       r12, 0xC(r4)
	  ble-      .loc_0x308
	  mr        r10, r12
	  b         .loc_0x318

	.loc_0x308:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r12, r7
	  bge-      .loc_0x318
	  mr        r9, r12

	.loc_0x318:
	  add       r12, r11, r6
	  lbz       r11, 0x0(r12)
	  rlwinm    r7,r10,0,24,31
	  rlwinm    r11,r11,28,28,31
	  cmplw     r11, r7
	  stb       r11, 0xD(r4)
	  ble-      .loc_0x33C
	  mr        r10, r11
	  b         .loc_0x34C

	.loc_0x33C:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r11, r7
	  bge-      .loc_0x34C
	  mr        r9, r11

	.loc_0x34C:
	  add       r12, r12, r6
	  lbz       r11, 0x0(r12)
	  rlwinm    r7,r10,0,24,31
	  rlwinm    r11,r11,28,28,31
	  cmplw     r11, r7
	  stb       r11, 0xE(r4)
	  ble-      .loc_0x370
	  mr        r10, r11
	  b         .loc_0x380

	.loc_0x370:
	  rlwinm    r7,r9,0,24,31
	  cmplw     r11, r7
	  bge-      .loc_0x380
	  mr        r9, r11

	.loc_0x380:
	  add       r12, r12, r6
	  lbz       r7, 0x0(r12)
	  rlwinm    r6,r10,0,24,31
	  rlwinm    r7,r7,28,28,31
	  cmplw     r7, r6
	  stb       r7, 0xF(r4)
	  ble-      .loc_0x3A4
	  mr        r10, r7
	  b         .loc_0x3B4

	.loc_0x3A4:
	  rlwinm    r4,r9,0,24,31
	  cmplw     r7, r4
	  bge-      .loc_0x3B4
	  mr        r9, r7

	.loc_0x3B4:
	  mulli     r6, r8, 0x14
	  add       r4, r3, r6
	  lwz       r11, 0x6160(r4)
	  addi      r7, r6, 0x6150
	  add       r7, r3, r7
	  lwz       r6, 0x4(r11)
	  b         .loc_0x41C

	.loc_0x3D0:
	  lwz       r8, 0xC(r7)
	  cmpwi     r8, 0
	  bge-      .loc_0x3F8
	  lwz       r4, 0x0(r7)
	  li        r8, 0x1F
	  addi      r3, r4, 0x4
	  stw       r3, 0x0(r7)
	  lwz       r3, 0x0(r4)
	  stw       r3, 0x8(r7)
	  b         .loc_0x3FC

	.loc_0x3F8:
	  lwz       r3, 0x8(r7)

	.loc_0x3FC:
	  srw       r4, r3, r8
	  subi      r3, r8, 0x1
	  stw       r3, 0xC(r7)
	  rlwinm    r4,r4,11,20,20
	  rlwinm    r3,r6,2,0,29
	  add       r3, r4, r3
	  addi      r3, r3, 0x8
	  lwzx      r6, r11, r3

	.loc_0x41C:
	  cmpwi     r6, 0x100
	  bge+      .loc_0x3D0
	  rlwinm    r3,r6,2,0,29
	  lwz       r4, 0x0(r5)
	  add       r3, r11, r3
	  lwz       r3, 0x8(r3)
	  rlwinm    r7,r0,0,16,31
	  rlwinm.   r0,r0,0,16,16
	  add       r3, r4, r3
	  stw       r3, 0x0(r5)
	  beq-      .loc_0x480
	  rlwinm    r3,r9,0,24,31
	  lwz       r5, 0x0(r5)
	  rlwinm    r0,r10,0,24,31
	  sub       r0, r0, r3
	  lis       r3, 0x8039
	  rlwinm    r4,r0,2,0,29
	  subi      r0, r3, 0x4100
	  add       r3, r0, r4
	  lwz       r0, 0x0(r3)
	  rlwinm    r3,r7,19,30,31
	  add       r3, r5, r3
	  neg       r0, r0
	  mullw     r3, r3, r0
	  b         .loc_0x4B0

	.loc_0x480:
	  rlwinm    r3,r9,0,24,31
	  lwz       r6, 0x0(r5)
	  rlwinm    r0,r10,0,24,31
	  sub       r0, r0, r3
	  lis       r3, 0x8039
	  rlwinm    r5,r7,19,30,31
	  rlwinm    r4,r0,2,0,29
	  subi      r0, r3, 0x4100
	  add       r3, r0, r4
	  lwz       r0, 0x0(r3)
	  add       r3, r6, r5
	  mullw     r3, r3, r0

	.loc_0x4B0:
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80022BC4
 * Size:	000164
 */
void MCBlockDecMCNest(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r18, 0x28(r1)
	  addi      r18, r6, 0
	  addi      r19, r5, 0
	  addi      r31, r3, 0
	  rlwinm    r27,r18,0,31,31
	  srawi     r6, r19, 0x1
	  rlwimi    r27,r19,1,30,30
	  addi      r30, r4, 0
	  addi      r29, r31, 0
	  li        r26, 0
	  lhz       r0, 0x28(r3)
	  srawi     r3, r18, 0x1
	  subi      r5, r3, 0x10
	  lwz       r7, 0x18(r4)
	  mullw     r0, r5, r0
	  add       r5, r6, r7
	  add       r20, r5, r0
	  lis       r3, 0x8022
	  rlwinm    r5,r27,2,0,29
	  addi      r0, r3, 0x72C0
	  add       r28, r0, r5
	  subi      r20, r20, 0x20

	.loc_0x64:
	  lbz       r4, 0x30(r29)
	  addi      r23, r29, 0x10
	  lbz       r3, 0x31(r29)
	  addi      r22, r29, 0x18
	  addi      r0, r4, 0x1
	  sraw      r4, r19, r0
	  lhz       r0, 0x28(r29)
	  addi      r3, r3, 0x1
	  lwz       r5, 0x18(r30)
	  sraw      r3, r18, r3
	  lbz       r21, 0x34(r29)
	  mullw     r0, r3, r0
	  add       r24, r0, r5
	  add       r24, r4, r24
	  li        r25, 0
	  b         .loc_0x134

	.loc_0xA4:
	  lhz       r0, 0x0(r23)
	  addi      r23, r23, 0x2
	  lwz       r5, 0x0(r22)
	  addi      r22, r22, 0x4
	  rlwinm    r3,r0,1,0,30
	  lwz       r4, 0x8(r30)
	  addi      r3, r3, 0x1
	  lwz       r0, 0x14(r30)
	  lbzx      r3, r4, r3
	  add       r4, r0, r5
	  rlwinm    r7,r3,0,28,31
	  cmplwi    r7, 0x6
	  bne-      .loc_0xEC
	  lhz       r5, 0x28(r29)
	  addi      r3, r31, 0
	  addi      r6, r26, 0
	  bl        -0x2ED4
	  b         .loc_0x130

	.loc_0xEC:
	  cmplwi    r7, 0
	  add       r5, r24, r5
	  bne-      .loc_0x114
	  lwz       r12, 0x0(r28)
	  mr        r3, r4
	  lhz       r6, 0x28(r29)
	  mtlr      r12
	  addi      r4, r6, 0
	  blrl
	  b         .loc_0x130

	.loc_0x114:
	  stw       r27, 0x8(r1)
	  mr        r3, r31
	  addi      r8, r20, 0
	  lhz       r6, 0x28(r29)
	  addi      r10, r26, 0
	  lhz       r9, 0x28(r31)
	  bl        -0xE5C

	.loc_0x130:
	  addi      r25, r25, 0x1

	.loc_0x134:
	  cmpw      r25, r21
	  blt+      .loc_0xA4
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x3
	  addi      r30, r30, 0x34
	  addi      r29, r29, 0x38
	  blt+      .loc_0x64
	  lmw       r18, 0x28(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80022D28
 * Size:	000158
 */
void MCBlockDecDCNest(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r21, 0x1C(r1)
	  addi      r23, r3, 0
	  addi      r22, r4, 0
	  addi      r21, r23, 0
	  li        r31, 0

	.loc_0x20:
	  lwz       r30, 0x8(r22)
	  addi      r27, r21, 0x10
	  lhz       r29, 0x28(r21)
	  addi      r26, r21, 0x18
	  lhz       r28, 0xC(r21)
	  lbz       r25, 0x34(r21)
	  li        r24, 0
	  b         .loc_0x128

	.loc_0x40:
	  lhz       r0, 0x0(r27)
	  addi      r27, r27, 0x2
	  lwz       r4, 0x0(r26)
	  addi      r26, r26, 0x4
	  rlwinm    r3,r0,1,0,30
	  add       r3, r30, r3
	  lwz       r6, 0x14(r22)
	  lbz       r5, 0x1(r3)
	  lbz       r10, 0x0(r3)
	  add       r4, r6, r4
	  rlwinm    r5,r5,0,28,31
	  addi      r7, r5, 0
	  rlwinm.   r5,r5,0,24,31
	  bne-      .loc_0x110
	  sub       r5, r0, r28
	  rlwinm    r5,r5,1,0,30
	  add       r6, r30, r5
	  lbz       r5, 0x1(r6)
	  andi.     r5, r5, 0x77
	  beq-      .loc_0x98
	  mr        r6, r10
	  b         .loc_0x9C

	.loc_0x98:
	  lbz       r6, 0x0(r6)

	.loc_0x9C:
	  lbz       r5, -0x1(r3)
	  andi.     r5, r5, 0x77
	  beq-      .loc_0xB0
	  mr        r7, r10
	  b         .loc_0xB4

	.loc_0xB0:
	  lbz       r7, -0x2(r3)

	.loc_0xB4:
	  lbz       r5, 0x3(r3)
	  addi      r8, r7, 0
	  andi.     r5, r5, 0x77
	  beq-      .loc_0xCC
	  mr        r3, r10
	  b         .loc_0xD0

	.loc_0xCC:
	  lbz       r3, 0x2(r3)

	.loc_0xD0:
	  add       r0, r0, r28
	  rlwinm    r0,r0,1,0,30
	  add       r5, r30, r0
	  lbz       r0, 0x1(r5)
	  addi      r9, r3, 0
	  andi.     r0, r0, 0x77
	  beq-      .loc_0xF4
	  mr        r0, r10
	  b         .loc_0xF8

	.loc_0xF4:
	  lbz       r0, 0x0(r5)

	.loc_0xF8:
	  addi      r3, r4, 0
	  mr        r7, r0
	  addi      r4, r29, 0
	  addi      r5, r10, 0
	  bl        -0x31F4
	  b         .loc_0x124

	.loc_0x110:
	  addi      r3, r23, 0
	  addi      r5, r29, 0
	  addi      r6, r10, 0
	  addi      r8, r31, 0
	  bl        -0x302C

	.loc_0x124:
	  addi      r24, r24, 0x1

	.loc_0x128:
	  cmpw      r24, r25
	  blt+      .loc_0x40
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x3
	  addi      r22, r22, 0x34
	  addi      r21, r21, 0x38
	  blt+      .loc_0x20
	  lmw       r21, 0x1C(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void initMCBproc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void getMCBproc(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void initMCBtype(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void getMCBtype(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80022E80
 * Size:	000430
 */
void spread_PB_descMap(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stmw      r14, 0x90(r1)
	  mr        r16, r4
	  stw       r3, 0x78(r1)
	  lwz       r3, 0x78(r1)
	  lwz       r5, 0x0(r3)
	  lwz       r3, 0x6234(r5)
	  addi      r27, r5, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x84
	  lwz       r4, 0x6240(r27)
	  cmpwi     r4, 0
	  bge-      .loc_0x54
	  addi      r0, r3, 0x4
	  stw       r0, 0x6234(r27)
	  li        r4, 0x1F
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x623C(r27)
	  b         .loc_0x58

	.loc_0x54:
	  lwz       r0, 0x623C(r27)

	.loc_0x58:
	  srw       r0, r0, r4
	  subi      r3, r4, 0x1
	  rlwinm    r0,r0,0,31,31
	  stw       r3, 0x6240(r27)
	  li        r17, 0
	  stw       r0, 0x84(r1)

	.loc_0x70:
	  addi      r3, r27, 0x6234
	  bl        -0x36CC
	  cmpwi     r3, 0xFF
	  add       r17, r17, r3
	  bge+      .loc_0x70

	.loc_0x84:
	  lwz       r3, 0x6248(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x12C
	  lwz       r4, 0x6254(r27)
	  cmpwi     r4, 0
	  bge-      .loc_0xB4
	  addi      r0, r3, 0x4
	  stw       r0, 0x6248(r27)
	  li        r4, 0x1F
	  lwz       r3, 0x0(r3)
	  stw       r3, 0x6250(r27)
	  b         .loc_0xB8

	.loc_0xB4:
	  lwz       r3, 0x6250(r27)

	.loc_0xB8:
	  subi      r0, r4, 0x1
	  stw       r0, 0x6254(r27)
	  srw       r0, r3, r4
	  rlwinm    r0,r0,1,30,30
	  lwz       r4, 0x6254(r27)
	  stw       r0, 0x88(r1)
	  cmpwi     r4, 0
	  bge-      .loc_0xF4
	  lwz       r3, 0x6248(r27)
	  li        r4, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x6248(r27)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x6250(r27)
	  b         .loc_0xF8

	.loc_0xF4:
	  lwz       r0, 0x6250(r27)

	.loc_0xF8:
	  srw       r3, r0, r4
	  subi      r0, r4, 0x1
	  stw       r0, 0x6254(r27)
	  rlwinm    r3,r3,0,31,31
	  lwz       r0, 0x88(r1)
	  li        r18, 0
	  or        r0, r0, r3
	  stw       r0, 0x88(r1)

	.loc_0x118:
	  addi      r3, r27, 0x6248
	  bl        -0x3774
	  cmpwi     r3, 0xFF
	  add       r18, r18, r3
	  bge+      .loc_0x118

	.loc_0x12C:
	  lis       r3, 0x8022
	  addi      r0, r3, 0x22A0
	  stw       r0, 0x8C(r1)
	  li        r0, 0
	  addi      r15, r16, 0x34
	  stw       r0, 0x7C(r1)
	  addi      r14, r16, 0x68
	  b         .loc_0x408

	.loc_0x14C:
	  lwz       r3, 0x10(r16)
	  li        r0, 0
	  stw       r0, 0x80(r1)
	  stw       r3, 0x14(r16)
	  lwz       r0, 0x10(r15)
	  stw       r0, 0x14(r15)
	  lwz       r0, 0x10(r14)
	  stw       r0, 0x14(r14)
	  b         .loc_0x370

	.loc_0x170:
	  cmpwi     r18, 0
	  bne-      .loc_0x1EC
	  lwz       r3, 0x6254(r27)
	  cmpwi     r3, 0
	  bge-      .loc_0x1A0
	  lwz       r4, 0x6248(r27)
	  li        r3, 0x1F
	  addi      r0, r4, 0x4
	  stw       r0, 0x6248(r27)
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x6250(r27)
	  b         .loc_0x1A4

	.loc_0x1A0:
	  lwz       r0, 0x6250(r27)

	.loc_0x1A4:
	  srw       r0, r0, r3
	  rlwinm    r0,r0,0,31,31
	  mulli     r4, r0, 0xC
	  subi      r0, r3, 0x1
	  stw       r0, 0x6254(r27)
	  li        r18, 0
	  lwz       r0, 0x8C(r1)
	  add       r3, r0, r4
	  lwz       r0, 0x88(r1)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x88(r1)

	.loc_0x1D8:
	  addi      r3, r27, 0x6248
	  bl        -0x3834
	  cmpwi     r3, 0xFF
	  add       r18, r18, r3
	  bge+      .loc_0x1D8

	.loc_0x1EC:
	  lwz       r0, 0x88(r1)
	  subi      r18, r18, 0x1
	  cmpwi     r0, 0
	  bne-      .loc_0x2A4
	  addi      r31, r16, 0
	  addi      r21, r27, 0
	  addi      r20, r27, 0
	  li        r19, 0

	.loc_0x20C:
	  lbz       r22, 0x34(r21)
	  addi      r23, r20, 0x60D8
	  addi      r28, r21, 0x10
	  li        r29, 0
	  b         .loc_0x26C

	.loc_0x220:
	  lhz       r24, 0x0(r28)
	  li        r30, 0
	  lwz       r26, 0x6CC8(r27)
	  addi      r28, r28, 0x2
	  lwz       r25, 0x6CCC(r27)

	.loc_0x234:
	  mr        r3, r23
	  bl        -0x3890
	  cmpw      r25, r3
	  add       r30, r30, r3
	  bge+      .loc_0x234
	  cmpw      r3, r26
	  bge+      .loc_0x234
	  lwz       r0, 0x4(r31)
	  rlwinm    r3,r24,1,0,30
	  addi      r29, r29, 0x1
	  add       r0, r0, r30
	  stw       r0, 0x4(r31)
	  lwz       r4, 0x8(r31)
	  stbx      r0, r4, r3

	.loc_0x26C:
	  cmpw      r29, r22
	  blt+      .loc_0x220
	  addi      r19, r19, 0x1
	  cmpwi     r19, 0x3
	  addi      r31, r31, 0x34
	  addi      r21, r21, 0x38
	  addi      r20, r20, 0x14
	  blt+      .loc_0x20C
	  lwz       r6, 0x88(r1)
	  addi      r3, r27, 0
	  addi      r4, r16, 0
	  li        r5, 0
	  bl        -0x16A4
	  b         .loc_0x2F8

	.loc_0x2A4:
	  li        r0, 0x7F
	  stw       r0, 0x4(r16)
	  cmpwi     r17, 0
	  stw       r0, 0x38(r16)
	  stw       r0, 0x6C(r16)
	  bne-      .loc_0x2E0
	  lwz       r0, 0x84(r1)
	  li        r17, 0
	  xori      r0, r0, 0x1
	  stw       r0, 0x84(r1)

	.loc_0x2CC:
	  addi      r3, r27, 0x6234
	  bl        -0x3928
	  cmpwi     r3, 0xFF
	  add       r17, r17, r3
	  bge+      .loc_0x2CC

	.loc_0x2E0:
	  lwz       r5, 0x84(r1)
	  addi      r3, r27, 0
	  lwz       r6, 0x88(r1)
	  addi      r4, r16, 0
	  subi      r17, r17, 0x1
	  bl        -0x16FC

	.loc_0x2F8:
	  lwz       r3, 0x14(r16)
	  lhz       r0, 0x24(r16)
	  add       r0, r3, r0
	  stw       r0, 0x14(r16)
	  lwz       r0, 0x2C(r16)
	  lwz       r3, 0x8(r16)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x8(r16)
	  lwz       r3, 0x14(r15)
	  lhz       r0, 0x24(r15)
	  add       r0, r3, r0
	  stw       r0, 0x14(r15)
	  lwz       r0, 0x2C(r15)
	  lwz       r3, 0x8(r15)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x8(r15)
	  lwz       r3, 0x14(r14)
	  lhz       r0, 0x24(r14)
	  add       r0, r3, r0
	  stw       r0, 0x14(r14)
	  lwz       r0, 0x2C(r14)
	  lwz       r3, 0x8(r14)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  lwz       r3, 0x80(r1)
	  stw       r0, 0x8(r14)
	  addi      r3, r3, 0x8
	  stw       r3, 0x80(r1)

	.loc_0x370:
	  lwz       r3, 0x78(r1)
	  lwz       r0, 0x80(r1)
	  lhz       r3, 0x4(r3)
	  cmpw      r0, r3
	  blt+      .loc_0x170
	  lwz       r3, 0x10(r16)
	  lwz       r0, 0x28(r16)
	  add       r0, r3, r0
	  stw       r0, 0x10(r16)
	  lwz       r0, 0x30(r16)
	  lwz       r3, 0xC(r16)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xC(r16)
	  stw       r0, 0x8(r16)
	  lwz       r3, 0x10(r15)
	  lwz       r0, 0x28(r15)
	  add       r0, r3, r0
	  stw       r0, 0x10(r15)
	  lwz       r0, 0x30(r15)
	  lwz       r3, 0xC(r15)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xC(r15)
	  stw       r0, 0x8(r15)
	  lwz       r3, 0x10(r14)
	  lwz       r0, 0x28(r14)
	  add       r0, r3, r0
	  stw       r0, 0x10(r14)
	  lwz       r0, 0x30(r14)
	  lwz       r3, 0xC(r14)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  lwz       r3, 0x7C(r1)
	  stw       r0, 0xC(r14)
	  addi      r3, r3, 0x8
	  stw       r0, 0x8(r14)
	  stw       r3, 0x7C(r1)

	.loc_0x408:
	  lwz       r3, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  lhz       r3, 0x6(r3)
	  cmpw      r0, r3
	  blt+      .loc_0x14C
	  lmw       r14, 0x90(r1)
	  lwz       r0, 0xDC(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800232B0
 * Size:	00043C
 */
void BpicPlaneDec(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r7, r6, 0
	  stw       r0, 0x4(r1)
	  addi      r0, r5, 0
	  mr        r6, r0
	  stwu      r1, -0x150(r1)
	  stmw      r15, 0x10C(r1)
	  addi      r15, r4, 0
	  mr        r19, r3
	  addi      r5, r15, 0
	  addi      r4, r1, 0x68
	  lwz       r25, 0x0(r3)
	  addi      r3, r25, 0
	  bl        -0x2988
	  addi      r3, r19, 0
	  addi      r4, r1, 0x68
	  bl        -0x470
	  stw       r15, 0x78(r1)
	  li        r20, 0
	  rlwinm    r28,r20,1,0,30
	  lwz       r0, 0x4(r25)
	  addi      r31, r25, 0x620C
	  addi      r30, r25, 0x6220
	  stw       r0, 0x70(r1)
	  li        r22, -0x1
	  stw       r0, 0x74(r1)
	  lwz       r0, 0x2C(r25)
	  add       r3, r15, r0
	  stw       r3, 0xAC(r1)
	  lwz       r0, 0x3C(r25)
	  stw       r0, 0xA4(r1)
	  stw       r0, 0xA8(r1)
	  lwz       r0, 0x64(r25)
	  add       r3, r3, r0
	  stw       r3, 0xE0(r1)
	  lwz       r0, 0x74(r25)
	  stw       r0, 0xD8(r1)
	  stw       r0, 0xDC(r1)
	  b         .loc_0x41C

	.loc_0x9C:
	  lwz       r0, 0x78(r1)
	  li        r21, 0
	  rlwinm    r29,r21,1,0,30
	  stw       r0, 0x7C(r1)
	  lwz       r0, 0xAC(r1)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r0, 0xE4(r1)
	  b         .loc_0x390

	.loc_0xC0:
	  lwz       r3, 0x70(r1)
	  lbz       r27, 0x1(r3)
	  rlwinm.   r3,r27,27,30,31
	  bne-      .loc_0xE0
	  addi      r3, r25, 0
	  addi      r4, r1, 0x68
	  bl        -0x660
	  b         .loc_0x31C

	.loc_0xE0:
	  subi      r0, r3, 0x1
	  cmpw      r0, r22
	  beq-      .loc_0x134
	  cmpwi     r0, 0
	  mr        r22, r0
	  bne-      .loc_0x114
	  lwz       r0, 0x84(r1)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r0, 0xB4(r1)
	  lwz       r0, 0xEC(r1)
	  stw       r0, 0xE8(r1)
	  b         .loc_0x12C

	.loc_0x114:
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0xBC(r1)
	  stw       r0, 0xB4(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0xE8(r1)

	.loc_0x12C:
	  li        r23, 0
	  li        r24, 0

	.loc_0x134:
	  add       r26, r25, r22
	  lwz       r15, 0x621C(r25)
	  lbz       r16, 0x6CD2(r26)
	  li        r3, 0x1
	  lwz       r17, 0x4(r15)
	  addi      r0, r16, 0x5
	  slw       r18, r3, r0
	  b         .loc_0x170

	.loc_0x154:
	  mr        r3, r31
	  bl        -0x3C20
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r17,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r17, r15, r0

	.loc_0x170:
	  cmpwi     r17, 0x100
	  bge+      .loc_0x154
	  subic.    r4, r16, 0x1
	  rlwinm    r3,r17,2,0,29
	  addi      r3, r3, 0x8
	  addi      r0, r4, 0x1
	  lwzx      r3, r15, r3
	  mtctr     r0
	  slw       r5, r3, r16
	  blt-      .loc_0x1E4

	.loc_0x198:
	  lwz       r6, 0x6218(r25)
	  cmpwi     r6, 0
	  bge-      .loc_0x1C0
	  lwz       r3, 0x620C(r25)
	  li        r6, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x620C(r25)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x6214(r25)
	  b         .loc_0x1C4

	.loc_0x1C0:
	  lwz       r0, 0x6214(r25)

	.loc_0x1C4:
	  srw       r0, r0, r6
	  rlwinm    r0,r0,0,31,31
	  slw       r0, r0, r4
	  subi      r3, r6, 0x1
	  stw       r3, 0x6218(r25)
	  add       r5, r5, r0
	  subi      r4, r4, 0x1
	  bdnz+     .loc_0x198

	.loc_0x1E4:
	  add       r24, r24, r5
	  cmpw      r24, r18
	  blt-      .loc_0x1FC
	  rlwinm    r0,r18,1,0,30
	  sub       r24, r24, r0
	  b         .loc_0x210

	.loc_0x1FC:
	  neg       r0, r18
	  cmpw      r24, r0
	  bge-      .loc_0x210
	  rlwinm    r0,r18,1,0,30
	  add       r24, r24, r0

	.loc_0x210:
	  lbz       r15, 0x6CD4(r26)
	  li        r3, 0x1
	  lwz       r16, 0x6230(r25)
	  addi      r0, r15, 0x5
	  lwz       r17, 0x4(r16)
	  slw       r18, r3, r0
	  b         .loc_0x248

	.loc_0x22C:
	  mr        r3, r30
	  bl        -0x3CF8
	  rlwinm    r3,r3,11,0,20
	  rlwinm    r0,r17,2,0,29
	  add       r3, r3, r0
	  addi      r0, r3, 0x8
	  lwzx      r17, r16, r0

	.loc_0x248:
	  cmpwi     r17, 0x100
	  bge+      .loc_0x22C
	  subic.    r4, r15, 0x1
	  rlwinm    r3,r17,2,0,29
	  addi      r3, r3, 0x8
	  addi      r0, r4, 0x1
	  lwzx      r3, r16, r3
	  mtctr     r0
	  slw       r5, r3, r15
	  blt-      .loc_0x2BC

	.loc_0x270:
	  lwz       r6, 0x622C(r25)
	  cmpwi     r6, 0
	  bge-      .loc_0x298
	  lwz       r3, 0x6220(r25)
	  li        r6, 0x1F
	  addi      r0, r3, 0x4
	  stw       r0, 0x6220(r25)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x6228(r25)
	  b         .loc_0x29C

	.loc_0x298:
	  lwz       r0, 0x6228(r25)

	.loc_0x29C:
	  srw       r0, r0, r6
	  rlwinm    r0,r0,0,31,31
	  slw       r0, r0, r4
	  subi      r3, r6, 0x1
	  stw       r3, 0x622C(r25)
	  add       r5, r5, r0
	  subi      r4, r4, 0x1
	  bdnz+     .loc_0x270

	.loc_0x2BC:
	  add       r23, r23, r5
	  cmpw      r23, r18
	  blt-      .loc_0x2D4
	  rlwinm    r0,r18,1,0,30
	  sub       r23, r23, r0
	  b         .loc_0x2E8

	.loc_0x2D4:
	  neg       r0, r18
	  cmpw      r23, r0
	  bge-      .loc_0x2E8
	  rlwinm    r0,r18,1,0,30
	  add       r23, r23, r0

	.loc_0x2E8:
	  rlwinm.   r0,r27,28,31,31
	  bne-      .loc_0x308
	  addi      r3, r25, 0
	  addi      r4, r1, 0x68
	  add       r5, r29, r24
	  add       r6, r28, r23
	  bl        -0x9EC
	  b         .loc_0x31C

	.loc_0x308:
	  addi      r3, r25, 0
	  addi      r4, r1, 0x68
	  add       r5, r29, r24
	  add       r6, r28, r23
	  bl        -0x2550

	.loc_0x31C:
	  lwz       r3, 0x7C(r1)
	  addi      r29, r29, 0x10
	  lhz       r0, 0x8C(r1)
	  addi      r21, r21, 0x8
	  add       r0, r3, r0
	  stw       r0, 0x7C(r1)
	  lwz       r0, 0x94(r1)
	  lwz       r3, 0x70(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x70(r1)
	  lwz       r3, 0xB0(r1)
	  lhz       r0, 0xC0(r1)
	  add       r0, r3, r0
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xC8(r1)
	  lwz       r3, 0xA4(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xA4(r1)
	  lwz       r3, 0xE4(r1)
	  lhz       r0, 0xF4(r1)
	  add       r0, r3, r0
	  stw       r0, 0xE4(r1)
	  lwz       r0, 0xFC(r1)
	  lwz       r3, 0xD8(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xD8(r1)

	.loc_0x390:
	  lhz       r0, 0x4(r19)
	  cmpw      r21, r0
	  blt+      .loc_0xC0
	  lwz       r3, 0x78(r1)
	  addi      r28, r28, 0x10
	  lwz       r0, 0x90(r1)
	  addi      r20, r20, 0x8
	  add       r0, r3, r0
	  stw       r0, 0x78(r1)
	  lwz       r0, 0x98(r1)
	  lwz       r3, 0x74(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0x74(r1)
	  stw       r0, 0x70(r1)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xC4(r1)
	  add       r0, r3, r0
	  stw       r0, 0xAC(r1)
	  lwz       r0, 0xCC(r1)
	  lwz       r3, 0xA8(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xA8(r1)
	  stw       r0, 0xA4(r1)
	  lwz       r3, 0xE0(r1)
	  lwz       r0, 0xF8(r1)
	  add       r0, r3, r0
	  stw       r0, 0xE0(r1)
	  lwz       r0, 0x100(r1)
	  lwz       r3, 0xDC(r1)
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  stw       r0, 0xDC(r1)
	  stw       r0, 0xD8(r1)

	.loc_0x41C:
	  lhz       r0, 0x6(r19)
	  cmpw      r20, r0
	  blt+      .loc_0x9C
	  lmw       r15, 0x10C(r1)
	  lwz       r0, 0x154(r1)
	  addi      r1, r1, 0x150
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800236EC
 * Size:	000020
 */
void HVQM4InitDecoder(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x4ABC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8002370C
 * Size:	000024
 */
void HVQM4InitSeqObj(void)
{
	/*
	.loc_0x0:
	  lhz       r0, 0x0(r4)
	  sth       r0, 0x4(r3)
	  lhz       r0, 0x2(r4)
	  sth       r0, 0x6(r3)
	  lbz       r0, 0x4(r4)
	  stb       r0, 0x8(r3)
	  lbz       r0, 0x5(r4)
	  stb       r0, 0x9(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80023730
 * Size:	000074
 */
void HVQM4BuffSize(void)
{
	/*
	.loc_0x0:
	  lbz       r0, 0x8(r3)
	  lhz       r4, 0x4(r3)
	  cmplwi    r0, 0x2
	  srawi     r6, r4, 0x2
	  addze     r6, r6
	  bne-      .loc_0x20
	  srawi     r4, r6, 0x1
	  b         .loc_0x24

	.loc_0x20:
	  mr        r4, r6

	.loc_0x24:
	  lbz       r0, 0x9(r3)
	  lhz       r3, 0x6(r3)
	  cmplwi    r0, 0x2
	  srawi     r7, r3, 0x2
	  addze     r7, r7
	  bne-      .loc_0x44
	  srawi     r5, r7, 0x1
	  b         .loc_0x48

	.loc_0x44:
	  mr        r5, r7

	.loc_0x48:
	  addi      r3, r4, 0x2
	  addi      r0, r5, 0x2
	  mullw     r0, r3, r0
	  addi      r4, r6, 0x2
	  addi      r3, r7, 0x2
	  mullw     r3, r4, r3
	  rlwinm    r0,r0,1,0,30
	  add       r0, r3, r0
	  rlwinm    r3,r0,1,0,30
	  addi      r3, r3, 0x6CD8
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800237A4
 * Size:	000464
 */
void HVQM4SetBuffer(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  li        r6, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  li        r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stw       r31, 0x0(r3)
	  bl        -0x4834
	  lbz       r5, 0x8(r30)
	  mr        r3, r30
	  lbz       r6, 0x9(r30)
	  li        r4, 0x1
	  bl        -0x4848
	  lbz       r5, 0x8(r30)
	  mr        r3, r30
	  lbz       r6, 0x9(r30)
	  li        r4, 0x2
	  bl        -0x485C
	  lhz       r4, 0x4(r30)
	  li        r3, -0x1
	  lhz       r0, 0x6(r30)
	  subc      r0, r4, r0
	  subfze    r3, r3
	  rlwinm.   r0,r3,0,24,31
	  stb       r3, 0x6260(r31)
	  beq-      .loc_0x8C
	  li        r0, 0x46
	  sth       r0, 0x625C(r31)
	  li        r0, 0x26
	  sth       r0, 0x625E(r31)
	  b         .loc_0x9C

	.loc_0x8C:
	  li        r0, 0x26
	  sth       r0, 0x625C(r31)
	  li        r0, 0x46
	  sth       r0, 0x625E(r31)

	.loc_0x9C:
	  addi      r0, r31, 0x30C0
	  stw       r0, 0x61B0(r31)
	  addi      r9, r31, 0x10B0
	  addi      r8, r31, 0xA8
	  stw       r0, 0x619C(r31)
	  addi      r7, r31, 0x20B8
	  addi      r6, r31, 0x40C8
	  stw       r9, 0x61D8(r31)
	  addi      r5, r31, 0x50D0
	  addi      r3, r31, 0
	  stw       r9, 0x61C4(r31)
	  addi      r0, r31, 0x6CD8
	  li        r4, 0
	  stw       r8, 0x6110(r31)
	  stw       r8, 0x60FC(r31)
	  stw       r8, 0x60E8(r31)
	  stw       r9, 0x614C(r31)
	  stw       r9, 0x6138(r31)
	  stw       r9, 0x6124(r31)
	  stw       r7, 0x6188(r31)
	  stw       r7, 0x6174(r31)
	  stw       r7, 0x6160(r31)
	  stw       r6, 0x6230(r31)
	  stw       r6, 0x621C(r31)
	  stw       r5, 0x6258(r31)
	  stw       r5, 0x6244(r31)

	.loc_0x104:
	  stw       r0, 0x0(r3)
	  li        r8, 0x7F
	  li        r7, 0xFF
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  addi      r5, r5, 0x2
	  add       r5, r0, r5
	  stw       r5, 0x4(r3)
	  lhz       r6, 0xC(r3)
	  lhz       r5, 0xE(r3)
	  cmpwi     r6, 0
	  lwz       r9, 0x0(r3)
	  mullw     r5, r6, r5
	  rlwinm    r5,r5,1,0,30
	  add       r0, r0, r5
	  ble-      .loc_0x1B4
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x1A0

	.loc_0x150:
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  stb       r8, 0x2(r9)
	  stb       r7, 0x3(r9)
	  stb       r8, 0x4(r9)
	  stb       r7, 0x5(r9)
	  stb       r8, 0x6(r9)
	  stb       r7, 0x7(r9)
	  stb       r8, 0x8(r9)
	  stb       r7, 0x9(r9)
	  stb       r8, 0xA(r9)
	  stb       r7, 0xB(r9)
	  stb       r8, 0xC(r9)
	  stb       r7, 0xD(r9)
	  stb       r8, 0xE(r9)
	  stb       r7, 0xF(r9)
	  addi      r9, r9, 0x10
	  bdnz+     .loc_0x150
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x1B4

	.loc_0x1A0:
	  mtctr     r6

	.loc_0x1A4:
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  addi      r9, r9, 0x2
	  bdnz+     .loc_0x1A4

	.loc_0x1B4:
	  lhz       r5, 0xC(r3)
	  mr        r9, r0
	  li        r8, 0x7F
	  cmpwi     r5, 0
	  addi      r6, r5, 0
	  li        r7, 0xFF
	  ble-      .loc_0x240
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x22C

	.loc_0x1DC:
	  stb       r8, -0x2(r9)
	  stb       r7, -0x1(r9)
	  stb       r8, -0x4(r9)
	  stb       r7, -0x3(r9)
	  stb       r8, -0x6(r9)
	  stb       r7, -0x5(r9)
	  stb       r8, -0x8(r9)
	  stb       r7, -0x7(r9)
	  stb       r8, -0xA(r9)
	  stb       r7, -0x9(r9)
	  stb       r8, -0xC(r9)
	  stb       r7, -0xB(r9)
	  stb       r8, -0xE(r9)
	  stb       r7, -0xD(r9)
	  stb       r8, -0x10(r9)
	  stb       r7, -0xF(r9)
	  subi      r9, r9, 0x10
	  bdnz+     .loc_0x1DC
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x240

	.loc_0x22C:
	  mtctr     r6

	.loc_0x230:
	  stb       r8, -0x2(r9)
	  stb       r7, -0x1(r9)
	  subi      r9, r9, 0x2
	  bdnz+     .loc_0x230

	.loc_0x240:
	  lhz       r5, 0xE(r3)
	  li        r8, 0x7F
	  lhz       r6, 0xC(r3)
	  li        r7, 0xFF
	  subic.    r10, r5, 0x2
	  lwz       r9, 0x0(r3)
	  rlwinm    r5,r6,1,0,30
	  addi      r6, r10, 0
	  add       r9, r9, r5
	  ble-      .loc_0x33C
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x320

	.loc_0x274:
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  bdnz+     .loc_0x274
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x33C

	.loc_0x320:
	  mtctr     r6

	.loc_0x324:
	  stb       r8, 0x0(r9)
	  stb       r7, 0x1(r9)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r9, r9, r5
	  bdnz+     .loc_0x324

	.loc_0x33C:
	  lhz       r5, 0xE(r3)
	  li        r8, 0x7F
	  lhz       r6, 0xC(r3)
	  li        r7, 0xFF
	  subic.    r11, r5, 0x2
	  rlwinm    r5,r6,2,0,29
	  lwz       r9, 0x0(r3)
	  subi      r10, r5, 0x2
	  addi      r6, r11, 0
	  add       r10, r9, r10
	  ble-      .loc_0x43C
	  rlwinm.   r5,r6,29,3,31
	  mtctr     r5
	  beq-      .loc_0x420

	.loc_0x374:
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  bdnz+     .loc_0x374
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x43C

	.loc_0x420:
	  mtctr     r6

	.loc_0x424:
	  stb       r8, 0x0(r10)
	  stb       r7, 0x1(r10)
	  lhz       r5, 0xC(r3)
	  rlwinm    r5,r5,1,0,30
	  add       r10, r10, r5
	  bdnz+     .loc_0x424

	.loc_0x43C:
	  addi      r4, r4, 0x1
	  cmpwi     r4, 0x3
	  addi      r3, r3, 0x38
	  blt+      .loc_0x104
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  mtlr      r0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80023C08
 * Size:	000510
 */
void HVQM4DecodeIpic(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r4
	  addi      r0, r29, 0x48
	  stw       r28, 0x18(r1)
	  lwz       r31, 0x0(r3)
	  lbz       r3, 0x1(r4)
	  stb       r3, 0x6CD0(r31)
	  lwz       r3, 0x8(r4)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6190(r31)
	  bne-      .loc_0x58
	  li        r3, 0
	  stw       r3, 0x618C(r31)
	  b         .loc_0x60

	.loc_0x58:
	  addi      r3, r4, 0x4
	  stw       r3, 0x618C(r31)

	.loc_0x60:
	  li        r3, -0x1
	  stw       r3, 0x6198(r31)
	  lwz       r3, 0xC(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61B8(r31)
	  bne-      .loc_0x8C
	  li        r3, 0
	  stw       r3, 0x61B4(r31)
	  b         .loc_0x94

	.loc_0x8C:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61B4(r31)

	.loc_0x94:
	  li        r3, -0x1
	  stw       r3, 0x61C0(r31)
	  lwz       r3, 0x10(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61A4(r31)
	  bne-      .loc_0xC0
	  li        r3, 0
	  stw       r3, 0x61A0(r31)
	  b         .loc_0xC8

	.loc_0xC0:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61A0(r31)

	.loc_0xC8:
	  li        r3, -0x1
	  stw       r3, 0x61AC(r31)
	  lwz       r3, 0x14(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61CC(r31)
	  bne-      .loc_0xF4
	  li        r3, 0
	  stw       r3, 0x61C8(r31)
	  b         .loc_0xFC

	.loc_0xF4:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61C8(r31)

	.loc_0xFC:
	  li        r3, -0x1
	  stw       r3, 0x61D4(r31)
	  lwz       r3, 0x18(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x60DC(r31)
	  bne-      .loc_0x128
	  li        r3, 0
	  stw       r3, 0x60D8(r31)
	  b         .loc_0x130

	.loc_0x128:
	  addi      r3, r4, 0x4
	  stw       r3, 0x60D8(r31)

	.loc_0x130:
	  li        r3, -0x1
	  stw       r3, 0x60E4(r31)
	  lwz       r3, 0x1C(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6154(r31)
	  bne-      .loc_0x15C
	  li        r3, 0
	  stw       r3, 0x6150(r31)
	  b         .loc_0x164

	.loc_0x15C:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6150(r31)

	.loc_0x164:
	  li        r3, -0x1
	  stw       r3, 0x615C(r31)
	  lwz       r3, 0x20(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61E0(r31)
	  bne-      .loc_0x190
	  li        r3, 0
	  stw       r3, 0x61DC(r31)
	  b         .loc_0x198

	.loc_0x190:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61DC(r31)

	.loc_0x198:
	  li        r3, -0x1
	  stw       r3, 0x61E8(r31)
	  lwz       r3, 0x24(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x60F0(r31)
	  bne-      .loc_0x1C4
	  li        r3, 0
	  stw       r3, 0x60EC(r31)
	  b         .loc_0x1CC

	.loc_0x1C4:
	  addi      r3, r4, 0x4
	  stw       r3, 0x60EC(r31)

	.loc_0x1CC:
	  li        r3, -0x1
	  stw       r3, 0x60F8(r31)
	  lwz       r3, 0x28(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6168(r31)
	  bne-      .loc_0x1F8
	  li        r3, 0
	  stw       r3, 0x6164(r31)
	  b         .loc_0x200

	.loc_0x1F8:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6164(r31)

	.loc_0x200:
	  li        r3, -0x1
	  stw       r3, 0x6170(r31)
	  lwz       r3, 0x2C(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61F0(r31)
	  bne-      .loc_0x22C
	  li        r3, 0
	  stw       r3, 0x61EC(r31)
	  b         .loc_0x234

	.loc_0x22C:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61EC(r31)

	.loc_0x234:
	  li        r3, -0x1
	  stw       r3, 0x61F8(r31)
	  lwz       r3, 0x30(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6104(r31)
	  bne-      .loc_0x260
	  li        r3, 0
	  stw       r3, 0x6100(r31)
	  b         .loc_0x268

	.loc_0x260:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6100(r31)

	.loc_0x268:
	  li        r3, -0x1
	  stw       r3, 0x610C(r31)
	  lwz       r3, 0x34(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x617C(r31)
	  bne-      .loc_0x294
	  li        r3, 0
	  stw       r3, 0x6178(r31)
	  b         .loc_0x29C

	.loc_0x294:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6178(r31)

	.loc_0x29C:
	  li        r3, -0x1
	  stw       r3, 0x6184(r31)
	  lwz       r3, 0x38(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6200(r31)
	  bne-      .loc_0x2C8
	  li        r3, 0
	  stw       r3, 0x61FC(r31)
	  b         .loc_0x2D0

	.loc_0x2C8:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61FC(r31)

	.loc_0x2D0:
	  li        r3, -0x1
	  stw       r3, 0x6208(r31)
	  lwz       r3, 0x3C(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6118(r31)
	  bne-      .loc_0x2FC
	  li        r3, 0
	  stw       r3, 0x6114(r31)
	  b         .loc_0x304

	.loc_0x2FC:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6114(r31)

	.loc_0x304:
	  li        r3, -0x1
	  stw       r3, 0x6120(r31)
	  lwz       r3, 0x40(r29)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x612C(r31)
	  bne-      .loc_0x330
	  li        r3, 0
	  stw       r3, 0x6128(r31)
	  b         .loc_0x338

	.loc_0x330:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6128(r31)

	.loc_0x338:
	  li        r3, -0x1
	  stw       r3, 0x6134(r31)
	  lwz       r3, 0x44(r29)
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  stw       r0, 0x6140(r31)
	  bne-      .loc_0x364
	  li        r0, 0
	  stw       r0, 0x613C(r31)
	  b         .loc_0x36C

	.loc_0x364:
	  addi      r0, r3, 0x4
	  stw       r0, 0x613C(r31)

	.loc_0x36C:
	  li        r0, -0x1
	  stw       r0, 0x6148(r31)
	  li        r3, 0
	  li        r0, 0x100
	  lwz       r28, 0x619C(r31)
	  addi      r4, r31, 0x618C
	  stw       r3, 0x2DC0(r13)
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r28)
	  lwz       r0, 0x6190(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3B0
	  mr        r3, r28
	  bl        -0x4EF0
	  extsh     r0, r3
	  stw       r0, 0x4(r28)
	  b         .loc_0x3B4

	.loc_0x3B0:
	  stw       r3, 0x4(r28)

	.loc_0x3B4:
	  lwz       r28, 0x61C4(r31)
	  li        r3, 0
	  li        r0, 0x100
	  stw       r3, 0x2DC0(r13)
	  addi      r4, r31, 0x61B4
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r28)
	  lwz       r0, 0x61B8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3F0
	  mr        r3, r28
	  bl        -0x4F30
	  extsh     r0, r3
	  stw       r0, 0x4(r28)
	  b         .loc_0x3F4

	.loc_0x3F0:
	  stw       r3, 0x4(r28)

	.loc_0x3F4:
	  lbz       r5, 0x0(r29)
	  li        r3, 0x1
	  lwz       r28, 0x60E8(r31)
	  li        r0, 0x100
	  addi      r4, r31, 0x60D8
	  stw       r3, 0x2DC0(r13)
	  stw       r5, 0x2DC4(r13)
	  stw       r0, 0x0(r28)
	  lwz       r0, 0x60DC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x434
	  mr        r3, r28
	  bl        -0x4F74
	  extsh     r0, r3
	  stw       r0, 0x4(r28)
	  b         .loc_0x43C

	.loc_0x434:
	  li        r0, 0
	  stw       r0, 0x4(r28)

	.loc_0x43C:
	  lwz       r28, 0x6160(r31)
	  li        r5, 0
	  li        r3, 0x2
	  stw       r5, 0x2DC0(r13)
	  li        r0, 0x100
	  addi      r4, r31, 0x6150
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r28)
	  lwz       r0, 0x6154(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x47C
	  mr        r3, r28
	  bl        -0x4FBC
	  extsh     r0, r3
	  stw       r0, 0x4(r28)
	  b         .loc_0x480

	.loc_0x47C:
	  stw       r5, 0x4(r28)

	.loc_0x480:
	  lbz       r0, 0x0(r29)
	  li        r3, 0x7F
	  li        r4, -0x80
	  slw       r0, r3, r0
	  stw       r0, 0x6CC8(r31)
	  mr        r3, r31
	  lbz       r0, 0x0(r29)
	  slw       r0, r4, r0
	  stw       r0, 0x6CCC(r31)
	  bl        -0x4CC4
	  mr        r3, r31
	  bl        -0x4A08
	  lhz       r4, 0x4(r29)
	  mr        r3, r31
	  lhz       r5, 0x6(r29)
	  bl        -0x482C
	  li        r29, 0
	  addi      r28, r31, 0

	.loc_0x4C8:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  bl        -0x385C
	  addi      r29, r29, 0x1
	  lwz       r0, 0x2C(r28)
	  cmpwi     r29, 0x3
	  add       r30, r30, r0
	  addi      r28, r28, 0x38
	  blt+      .loc_0x4C8
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  mtlr      r0
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80024118
 * Size:	000024
 */
void HVQM4DecodePpic(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r7, r5
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        .loc_0x24
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x24:
	*/
}

/*
 * --INFO--
 * Address:	8002413C
 * Size:	0005A8
 */
void HVQM4DecodeBpic(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r25, 0x24(r1)
	  addi      r26, r3, 0
	  addi      r27, r4, 0
	  addi      r0, r27, 0x4C
	  addi      r28, r5, 0
	  addi      r29, r6, 0
	  addi      r30, r7, 0
	  lbz       r3, 0x1(r4)
	  lwz       r31, 0x0(r26)
	  stb       r3, 0x6CD0(r31)
	  lbz       r3, 0x0(r4)
	  stb       r3, 0x6CD1(r31)
	  lbz       r3, 0x2(r4)
	  stb       r3, 0x6CD2(r31)
	  lbz       r3, 0x3(r4)
	  stb       r3, 0x6CD4(r31)
	  lbz       r3, 0x4(r4)
	  stb       r3, 0x6CD3(r31)
	  lbz       r3, 0x5(r4)
	  stb       r3, 0x6CD5(r31)
	  lwz       r3, 0x8(r4)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6190(r31)
	  bne-      .loc_0x80
	  li        r3, 0
	  stw       r3, 0x618C(r31)
	  b         .loc_0x88

	.loc_0x80:
	  addi      r3, r4, 0x4
	  stw       r3, 0x618C(r31)

	.loc_0x88:
	  li        r3, -0x1
	  stw       r3, 0x6198(r31)
	  lwz       r3, 0xC(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61B8(r31)
	  bne-      .loc_0xB4
	  li        r3, 0
	  stw       r3, 0x61B4(r31)
	  b         .loc_0xBC

	.loc_0xB4:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61B4(r31)

	.loc_0xBC:
	  li        r3, -0x1
	  stw       r3, 0x61C0(r31)
	  lwz       r3, 0x10(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61A4(r31)
	  bne-      .loc_0xE8
	  li        r3, 0
	  stw       r3, 0x61A0(r31)
	  b         .loc_0xF0

	.loc_0xE8:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61A0(r31)

	.loc_0xF0:
	  li        r3, -0x1
	  stw       r3, 0x61AC(r31)
	  lwz       r3, 0x14(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61CC(r31)
	  bne-      .loc_0x11C
	  li        r3, 0
	  stw       r3, 0x61C8(r31)
	  b         .loc_0x124

	.loc_0x11C:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61C8(r31)

	.loc_0x124:
	  li        r3, -0x1
	  stw       r3, 0x61D4(r31)
	  lwz       r3, 0x18(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x60DC(r31)
	  bne-      .loc_0x150
	  li        r3, 0
	  stw       r3, 0x60D8(r31)
	  b         .loc_0x158

	.loc_0x150:
	  addi      r3, r4, 0x4
	  stw       r3, 0x60D8(r31)

	.loc_0x158:
	  li        r3, -0x1
	  stw       r3, 0x60E4(r31)
	  lwz       r3, 0x1C(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6154(r31)
	  bne-      .loc_0x184
	  li        r3, 0
	  stw       r3, 0x6150(r31)
	  b         .loc_0x18C

	.loc_0x184:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6150(r31)

	.loc_0x18C:
	  li        r3, -0x1
	  stw       r3, 0x615C(r31)
	  lwz       r3, 0x20(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61E0(r31)
	  bne-      .loc_0x1B8
	  li        r3, 0
	  stw       r3, 0x61DC(r31)
	  b         .loc_0x1C0

	.loc_0x1B8:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61DC(r31)

	.loc_0x1C0:
	  li        r3, -0x1
	  stw       r3, 0x61E8(r31)
	  lwz       r3, 0x24(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x60F0(r31)
	  bne-      .loc_0x1EC
	  li        r3, 0
	  stw       r3, 0x60EC(r31)
	  b         .loc_0x1F4

	.loc_0x1EC:
	  addi      r3, r4, 0x4
	  stw       r3, 0x60EC(r31)

	.loc_0x1F4:
	  li        r3, -0x1
	  stw       r3, 0x60F8(r31)
	  lwz       r3, 0x28(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6168(r31)
	  bne-      .loc_0x220
	  li        r3, 0
	  stw       r3, 0x6164(r31)
	  b         .loc_0x228

	.loc_0x220:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6164(r31)

	.loc_0x228:
	  li        r3, -0x1
	  stw       r3, 0x6170(r31)
	  lwz       r3, 0x2C(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x61F0(r31)
	  bne-      .loc_0x254
	  li        r3, 0
	  stw       r3, 0x61EC(r31)
	  b         .loc_0x25C

	.loc_0x254:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61EC(r31)

	.loc_0x25C:
	  li        r3, -0x1
	  stw       r3, 0x61F8(r31)
	  lwz       r3, 0x30(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6104(r31)
	  bne-      .loc_0x288
	  li        r3, 0
	  stw       r3, 0x6100(r31)
	  b         .loc_0x290

	.loc_0x288:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6100(r31)

	.loc_0x290:
	  li        r3, -0x1
	  stw       r3, 0x610C(r31)
	  lwz       r3, 0x34(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x617C(r31)
	  bne-      .loc_0x2BC
	  li        r3, 0
	  stw       r3, 0x6178(r31)
	  b         .loc_0x2C4

	.loc_0x2BC:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6178(r31)

	.loc_0x2C4:
	  li        r3, -0x1
	  stw       r3, 0x6184(r31)
	  lwz       r3, 0x38(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6200(r31)
	  bne-      .loc_0x2F0
	  li        r3, 0
	  stw       r3, 0x61FC(r31)
	  b         .loc_0x2F8

	.loc_0x2F0:
	  addi      r3, r4, 0x4
	  stw       r3, 0x61FC(r31)

	.loc_0x2F8:
	  li        r3, -0x1
	  stw       r3, 0x6208(r31)
	  lwz       r3, 0x3C(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6210(r31)
	  bne-      .loc_0x324
	  li        r3, 0
	  stw       r3, 0x620C(r31)
	  b         .loc_0x32C

	.loc_0x324:
	  addi      r3, r4, 0x4
	  stw       r3, 0x620C(r31)

	.loc_0x32C:
	  li        r3, -0x1
	  stw       r3, 0x6218(r31)
	  lwz       r3, 0x40(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x6224(r31)
	  bne-      .loc_0x358
	  li        r3, 0
	  stw       r3, 0x6220(r31)
	  b         .loc_0x360

	.loc_0x358:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6220(r31)

	.loc_0x360:
	  li        r3, -0x1
	  stw       r3, 0x622C(r31)
	  lwz       r3, 0x44(r27)
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  cmplwi    r3, 0
	  stw       r3, 0x624C(r31)
	  bne-      .loc_0x38C
	  li        r3, 0
	  stw       r3, 0x6248(r31)
	  b         .loc_0x394

	.loc_0x38C:
	  addi      r3, r4, 0x4
	  stw       r3, 0x6248(r31)

	.loc_0x394:
	  li        r3, -0x1
	  stw       r3, 0x6254(r31)
	  lwz       r3, 0x48(r27)
	  add       r3, r0, r3
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  stw       r0, 0x6238(r31)
	  bne-      .loc_0x3C0
	  li        r0, 0
	  stw       r0, 0x6234(r31)
	  b         .loc_0x3C8

	.loc_0x3C0:
	  addi      r0, r3, 0x4
	  stw       r0, 0x6234(r31)

	.loc_0x3C8:
	  li        r0, -0x1
	  stw       r0, 0x6240(r31)
	  li        r3, 0
	  li        r0, 0x100
	  lwz       r25, 0x619C(r31)
	  addi      r4, r31, 0x618C
	  stw       r3, 0x2DC0(r13)
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x6190(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x40C
	  mr        r3, r25
	  bl        -0x5480
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x410

	.loc_0x40C:
	  stw       r3, 0x4(r25)

	.loc_0x410:
	  lwz       r25, 0x61C4(r31)
	  li        r3, 0
	  li        r0, 0x100
	  stw       r3, 0x2DC0(r13)
	  addi      r4, r31, 0x61B4
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x61B8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x44C
	  mr        r3, r25
	  bl        -0x54C0
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x450

	.loc_0x44C:
	  stw       r3, 0x4(r25)

	.loc_0x450:
	  lbz       r5, 0x0(r27)
	  li        r3, 0x1
	  lwz       r25, 0x60E8(r31)
	  li        r0, 0x100
	  addi      r4, r31, 0x60D8
	  stw       r3, 0x2DC0(r13)
	  stw       r5, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x60DC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x490
	  mr        r3, r25
	  bl        -0x5504
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x498

	.loc_0x490:
	  li        r0, 0
	  stw       r0, 0x4(r25)

	.loc_0x498:
	  lwz       r25, 0x6160(r31)
	  li        r5, 0
	  li        r3, 0x2
	  stw       r5, 0x2DC0(r13)
	  li        r0, 0x100
	  addi      r4, r31, 0x6150
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x6154(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x4D8
	  mr        r3, r25
	  bl        -0x554C
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x4DC

	.loc_0x4D8:
	  stw       r5, 0x4(r25)

	.loc_0x4DC:
	  lwz       r25, 0x621C(r31)
	  li        r0, 0x1
	  li        r3, 0
	  stw       r0, 0x2DC0(r13)
	  li        r0, 0x100
	  addi      r4, r31, 0x620C
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x6210(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x51C
	  mr        r3, r25
	  bl        -0x5590
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x520

	.loc_0x51C:
	  stw       r3, 0x4(r25)

	.loc_0x520:
	  lwz       r25, 0x6258(r31)
	  li        r3, 0
	  li        r0, 0x100
	  stw       r3, 0x2DC0(r13)
	  addi      r4, r31, 0x6248
	  stw       r3, 0x2DC4(r13)
	  stw       r0, 0x0(r25)
	  lwz       r0, 0x624C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x55C
	  mr        r3, r25
	  bl        -0x55D0
	  extsh     r0, r3
	  stw       r0, 0x4(r25)
	  b         .loc_0x560

	.loc_0x55C:
	  stw       r3, 0x4(r25)

	.loc_0x560:
	  lbz       r0, 0x0(r27)
	  li        r3, 0x7F
	  li        r7, -0x80
	  slw       r0, r3, r0
	  stw       r0, 0x6CC8(r31)
	  addi      r3, r26, 0
	  addi      r4, r28, 0
	  lbz       r0, 0x0(r27)
	  addi      r5, r29, 0
	  addi      r6, r30, 0
	  slw       r0, r7, r0
	  stw       r0, 0x6CCC(r31)
	  bl        -0x141C
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}
