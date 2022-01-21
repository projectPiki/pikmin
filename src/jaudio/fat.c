

/*
 * --INFO--
 * Address:	8000DDE0
 * Size:	000044
 */
void Jac_FatMemory_Init(unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x8674
	  stw       r3, 0x2BF8(r13)
	  lwz       r3, 0x2BF8(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  mr        r4, r31
	  bl        0x34

	.loc_0x30:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000DE40
 * Size:	0000BC
 */
void FAT_InitSystem(unsigned char*, unsigned long)
{
	/*
	.loc_0x0:
	  lis       r6, 0x8031
	  lis       r5, 0x1
	  subi      r8, r6, 0x2118
	  subi      r6, r5, 0x1
	  li        r0, 0x100
	  li        r10, 0
	  li        r5, 0
	  li        r7, 0x1000
	  mtctr     r0

	.loc_0x24:
	  cmplwi    r4, 0x1000
	  blt-      .loc_0x50
	  add       r9, r8, r5
	  subi      r4, r4, 0x1000
	  stw       r3, 0x404(r9)
	  addi      r10, r10, 0x1
	  addi      r3, r3, 0x1000
	  addi      r5, r5, 0x8
	  sth       r7, 0x402(r9)
	  sth       r6, 0x400(r9)
	  bdnz+     .loc_0x24

	.loc_0x50:
	  li        r5, 0
	  lis       r3, 0x1
	  subfic    r0, r10, 0x100
	  stw       r10, 0x2BF0(r13)
	  subi      r4, r3, 0x1
	  rlwinm    r3,r10,3,0,28
	  stw       r5, 0x2BF4(r13)
	  mtctr     r0
	  cmplwi    r10, 0x100
	  bge-      .loc_0x8C

	.loc_0x78:
	  add       r6, r8, r3
	  addi      r3, r3, 0x8
	  sth       r4, 0x400(r6)
	  sth       r5, 0x402(r6)
	  bdnz+     .loc_0x78

	.loc_0x8C:
	  lis       r3, 0x1
	  li        r0, 0x100
	  subi      r4, r3, 0x1
	  li        r6, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0xA4:
	  add       r5, r8, r3
	  addi      r3, r3, 0x4
	  sth       r4, 0x0(r5)
	  sth       r6, 0x2(r5)
	  bdnz+     .loc_0xA4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000DF00
 * Size:	0000D4
 */
void FAT_AllocateMemory(unsigned long)
{
	/*
	.loc_0x0:
	  lis       r4, 0x8031
	  li        r0, 0x100
	  subi      r5, r4, 0x2118
	  li        r6, 0
	  li        r4, 0
	  mtctr     r0

	.loc_0x18:
	  addi      r0, r4, 0x2
	  lhzx      r0, r5, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  addi      r6, r6, 0x1
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x18

	.loc_0x34:
	  cmplwi    r6, 0x100
	  bne-      .loc_0x48
	  lis       r3, 0x1
	  subi      r3, r3, 0x1
	  blr

	.loc_0x48:
	  cmplwi    r3, 0
	  rlwinm    r8,r6,0,16,31
	  bne-      .loc_0x60
	  lis       r3, 0x1
	  subi      r3, r3, 0x1
	  blr

	.loc_0x60:
	  lwz       r7, 0x2BF4(r13)
	  addi      r3, r3, 0xFFF
	  lwz       r0, 0x2BF0(r13)
	  rlwinm    r6,r3,20,12,31
	  sub       r0, r0, r7
	  cmpw      r0, r6
	  bge-      .loc_0x88
	  lis       r3, 0x1
	  subi      r3, r3, 0x1
	  blr

	.loc_0x88:
	  add       r4, r7, r6
	  rlwinm    r3,r7,3,0,28
	  sub       r0, r4, r7
	  mtctr     r0
	  cmplw     r7, r4
	  bge-      .loc_0xB0

	.loc_0xA0:
	  add       r4, r5, r3
	  addi      r3, r3, 0x8
	  sth       r8, 0x400(r4)
	  bdnz+     .loc_0xA0

	.loc_0xB0:
	  rlwinm    r0,r8,2,0,29
	  addi      r3, r8, 0
	  sthx      r7, r5, r0
	  add       r4, r5, r0
	  sth       r6, 0x2(r4)
	  lwz       r0, 0x2BF4(r13)
	  add       r0, r0, r6
	  stw       r0, 0x2BF4(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000DFE0
 * Size:	000190
 */
void FAT_FreeMemory(unsigned short)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  lis       r4, 0x8031
	  subi      r4, r4, 0x2118
	  rlwinm    r0,r3,2,14,29
	  stmw      r30, 0x18(r1)
	  add       r3, r4, r0
	  li        r11, 0
	  lhzx      r0, r4, r0
	  lhz       r5, 0x2(r3)
	  sth       r11, 0x2(r3)
	  add       r3, r0, r5
	  rlwinm    r3,r3,0,16,31
	  lwz       r6, 0x2BF4(r13)
	  sub       r7, r6, r3
	  rlwinm.   r30,r7,0,16,31
	  bne-      .loc_0x84
	  sub       r0, r6, r5
	  lis       r3, 0x1
	  stw       r0, 0x2BF4(r13)
	  subi      r6, r3, 0x1
	  li        r8, 0
	  lwz       r7, 0x2BF4(r13)
	  mtctr     r5
	  cmplwi    r5, 0
	  ble-      .loc_0x7C

	.loc_0x64:
	  add       r0, r7, r8
	  addi      r8, r8, 0x1
	  rlwinm    r0,r0,3,0,28
	  add       r3, r4, r0
	  sth       r6, 0x400(r3)
	  bdnz+     .loc_0x64

	.loc_0x7C:
	  li        r3, 0
	  b         .loc_0x184

	.loc_0x84:
	  lis       r7, 0x1
	  addi      r6, r11, 0
	  subi      r7, r7, 0x1
	  mtctr     r5
	  cmplwi    r5, 0
	  ble-      .loc_0xCC

	.loc_0x9C:
	  add       r8, r0, r11
	  add       r10, r4, r6
	  rlwinm    r8,r8,3,0,28
	  addi      r11, r11, 0x1
	  add       r8, r4, r8
	  addi      r6, r6, 0x8
	  lwz       r9, 0x400(r8)
	  lwz       r8, 0x404(r8)
	  stw       r9, 0xC00(r10)
	  stw       r8, 0xC04(r10)
	  sth       r7, 0xC00(r10)
	  bdnz+     .loc_0x9C

	.loc_0xCC:
	  lis       r6, 0x1
	  li        r12, 0
	  subi      r31, r6, 0x1
	  mtctr     r30
	  cmplwi    r30, 0
	  ble-      .loc_0x130

	.loc_0xE4:
	  add       r6, r3, r12
	  add       r11, r0, r12
	  rlwinm    r7,r6,3,0,28
	  rlwinm    r6,r11,3,0,28
	  add       r10, r4, r7
	  add       r9, r4, r6
	  lwz       r8, 0x400(r10)
	  rlwinm    r6,r31,0,16,31
	  lwz       r7, 0x404(r10)
	  stw       r8, 0x400(r9)
	  stw       r7, 0x404(r9)
	  lhz       r7, 0x400(r10)
	  cmplw     r6, r7
	  beq-      .loc_0x128
	  rlwinm    r6,r7,2,0,29
	  mr        r31, r7
	  sthx      r11, r4, r6

	.loc_0x128:
	  addi      r12, r12, 0x1
	  bdnz+     .loc_0xE4

	.loc_0x130:
	  lwz       r0, 0x2BF4(r13)
	  li        r9, 0
	  li        r3, 0
	  sub       r0, r0, r5
	  stw       r0, 0x2BF4(r13)
	  lwz       r8, 0x2BF4(r13)
	  mtctr     r5
	  cmplwi    r5, 0
	  ble-      .loc_0x180

	.loc_0x154:
	  add       r7, r4, r3
	  add       r0, r8, r9
	  rlwinm    r6,r0,3,0,28
	  lwz       r5, 0xC00(r7)
	  lwz       r0, 0xC04(r7)
	  add       r6, r4, r6
	  addi      r9, r9, 0x1
	  addi      r3, r3, 0x8
	  stw       r5, 0x400(r6)
	  stw       r0, 0x404(r6)
	  bdnz+     .loc_0x154

	.loc_0x180:
	  li        r3, 0

	.loc_0x184:
	  lmw       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000E180
 * Size:	000048
 */
void FAT_GetPointer(unsigned short, unsigned long)
{
	/*
	.loc_0x0:
	  lis       r5, 0x8031
	  rlwinm    r7,r3,2,14,29
	  subi      r5, r5, 0x2118
	  rlwinm    r6,r4,20,12,31
	  add       r3, r5, r7
	  lhz       r0, 0x2(r3)
	  cmplw     r0, r6
	  bgt-      .loc_0x28
	  li        r3, 0
	  blr

	.loc_0x28:
	  lhzx      r0, r5, r7
	  rlwinm    r4,r4,0,20,31
	  add       r0, r6, r0
	  rlwinm    r0,r0,3,0,28
	  add       r3, r5, r0
	  lwz       r0, 0x404(r3)
	  add       r3, r0, r4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000E1E0
 * Size:	000034
 */
void FAT_ReadByte(unsigned short, unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x6C
	  cmplwi    r3, 0
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x24

	.loc_0x20:
	  lbz       r3, 0x0(r3)

	.loc_0x24:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void FAT_ReadWord(unsigned short, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void FAT_ReadWordD(unsigned short, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void FAT_ReadLong(unsigned short, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void FAT_ReadLongD(unsigned short, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E220
 * Size:	0000E0
 */
void FAT_StoreBlock(unsigned char*, unsigned short, unsigned long, unsigned long)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r27, r3, 0
	  addi      r30, r6, 0
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0xC8
	  addi      r31, r29, 0
	  rlwinm    r29,r29,0,20,31
	  addi      r4, r3, 0
	  sub       r31, r31, r29
	  b         .loc_0x78

	.loc_0x40:
	  lbz       r0, 0x0(r27)
	  addi      r29, r29, 0x1
	  cmplwi    r29, 0x1000
	  subi      r30, r30, 0x1
	  stb       r0, 0x0(r4)
	  addi      r4, r4, 0x1
	  addi      r27, r27, 0x1
	  bne-      .loc_0x78
	  addi      r31, r31, 0x1000
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        -0x10C
	  mr        r4, r3
	  b         .loc_0xAC

	.loc_0x78:
	  cmplwi    r30, 0
	  bne+      .loc_0x40
	  b         .loc_0xAC

	.loc_0x84:
	  addi      r3, r27, 0
	  li        r5, 0x1000
	  bl        -0x832C
	  addi      r31, r31, 0x1000
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  subi      r30, r30, 0x1000
	  addi      r27, r27, 0x1000
	  bl        -0x144
	  mr        r4, r3

	.loc_0xAC:
	  cmplwi    r30, 0x1000
	  bge+      .loc_0x84
	  cmplwi    r30, 0
	  beq-      .loc_0xC8
	  addi      r3, r27, 0
	  addi      r5, r30, 0
	  bl        -0x8364

	.loc_0xC8:
	  lmw       r27, 0x24(r1)
	  li        r3, 0
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}
