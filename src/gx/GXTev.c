

/*
 * --INFO--
 * Address:	80212F9C
 * Size:	0001A4
 */
void GXSetTevOp(void)
{
/*
.loc_0x0:
  mflr      r0
  li        r6, 0xA
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0x5
  stw       r30, 0x10(r1)
  mr.       r30, r3
  beq-      .loc_0x2C
  li        r6, 0
  li        r31, 0

.loc_0x2C:
  cmpwi     r4, 0x2
  beq-      .loc_0xBC
  bge-      .loc_0x48
  cmpwi     r4, 0
  beq-      .loc_0x58
  bge-      .loc_0x88
  b         .loc_0x154

.loc_0x48:
  cmpwi     r4, 0x4
  beq-      .loc_0x124
  bge-      .loc_0x154
  b         .loc_0xF0

.loc_0x58:
  addi      r3, r30, 0
  li        r4, 0xF
  li        r5, 0x8
  li        r7, 0xF
  bl        .loc_0x1A4
  addi      r3, r30, 0
  addi      r6, r31, 0
  li        r4, 0x7
  li        r5, 0x4
  li        r7, 0x7
  bl        0x1A4
  b         .loc_0x154

.loc_0x88:
  addi      r3, r30, 0
  addi      r4, r6, 0
  li        r5, 0x8
  li        r6, 0x9
  li        r7, 0xF
  bl        .loc_0x1A4
  addi      r3, r30, 0
  addi      r7, r31, 0
  li        r4, 0x7
  li        r5, 0x7
  li        r6, 0x7
  bl        0x170
  b         .loc_0x154

.loc_0xBC:
  addi      r3, r30, 0
  addi      r4, r6, 0
  li        r5, 0xC
  li        r6, 0x8
  li        r7, 0xF
  bl        .loc_0x1A4
  addi      r3, r30, 0
  addi      r6, r31, 0
  li        r4, 0x7
  li        r5, 0x4
  li        r7, 0x7
  bl        0x13C
  b         .loc_0x154

.loc_0xF0:
  addi      r3, r30, 0
  li        r4, 0xF
  li        r5, 0xF
  li        r6, 0xF
  li        r7, 0x8
  bl        .loc_0x1A4
  addi      r3, r30, 0
  li        r4, 0x7
  li        r5, 0x7
  li        r6, 0x7
  li        r7, 0x4
  bl        0x108
  b         .loc_0x154

.loc_0x124:
  addi      r3, r30, 0
  addi      r7, r6, 0
  li        r4, 0xF
  li        r5, 0xF
  li        r6, 0xF
  bl        .loc_0x1A4
  addi      r3, r30, 0
  addi      r7, r31, 0
  li        r4, 0x7
  li        r5, 0x7
  li        r6, 0x7
  bl        0xD4

.loc_0x154:
  addi      r3, r30, 0
  li        r4, 0
  li        r5, 0
  li        r6, 0
  li        r7, 0x1
  li        r8, 0
  bl        0x13C
  addi      r3, r30, 0
  li        r4, 0
  li        r5, 0
  li        r6, 0
  li        r7, 0x1
  li        r8, 0
  bl        0x1E0
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr       

.loc_0x1A4:
*/
}

/*
 * --INFO--
 * Address:	80213140
 * Size:	000080
 */
void GXSetTevColorIn(void)
{
/*
.loc_0x0:
  rlwinm    r3,r3,2,0,29
  lwz       r0, 0x2A68(r13)
  addi      r9, r3, 0x130
  add       r9, r0, r9
  lwz       r3, 0x0(r9)
  rlwinm    r0,r4,12,0,19
  rlwinm    r8,r5,8,0,23
  rlwinm    r3,r3,0,20,15
  or        r0, r3, r0
  stw       r0, 0x0(r9)
  rlwinm    r4,r6,4,0,27
  li        r3, 0x61
  lwz       r6, 0x0(r9)
  lis       r5, 0xCC01
  li        r0, 0x1
  rlwinm    r6,r6,0,24,19
  or        r6, r6, r8
  stw       r6, 0x0(r9)
  lwz       r6, 0x0(r9)
  rlwinm    r6,r6,0,28,23
  or        r4, r6, r4
  stw       r4, 0x0(r9)
  lwz       r4, 0x0(r9)
  rlwinm    r4,r4,0,0,27
  or        r4, r4, r7
  stw       r4, 0x0(r9)
  stb       r3, -0x8000(r5)
  lwz       r3, 0x2A68(r13)
  lwz       r4, 0x0(r9)
  stw       r4, -0x8000(r5)
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	802131C0
 * Size:	000084
 */
void GXSetTevAlphaIn(void)
{
/*
.loc_0x0:
  rlwinm    r3,r3,2,0,29
  lwz       r0, 0x2A68(r13)
  addi      r9, r3, 0x170
  add       r9, r0, r9
  lwz       r8, 0x0(r9)
  rlwinm    r3,r4,13,0,18
  rlwinm    r0,r5,10,0,21
  rlwinm    r4,r8,0,19,15
  or        r3, r4, r3
  stw       r3, 0x0(r9)
  rlwinm    r6,r6,7,0,24
  rlwinm    r4,r7,4,0,27
  lwz       r7, 0x0(r9)
  li        r3, 0x61
  lis       r5, 0xCC01
  rlwinm    r7,r7,0,22,18
  or        r0, r7, r0
  stw       r0, 0x0(r9)
  li        r0, 0x1
  lwz       r7, 0x0(r9)
  rlwinm    r7,r7,0,25,21
  or        r6, r7, r6
  stw       r6, 0x0(r9)
  lwz       r6, 0x0(r9)
  rlwinm    r6,r6,0,28,24
  or        r4, r6, r4
  stw       r4, 0x0(r9)
  stb       r3, -0x8000(r5)
  lwz       r3, 0x2A68(r13)
  lwz       r4, 0x0(r9)
  stw       r4, -0x8000(r5)
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80213244
 * Size:	0000C0
 */
void GXSetTevColorOp(void)
{
/*
.loc_0x0:
  rlwinm    r3,r3,2,0,29
  lwz       r0, 0x2A68(r13)
  addi      r3, r3, 0x130
  add       r3, r0, r3
  lwz       r0, 0x0(r3)
  cmpwi     r4, 0x1
  rlwinm    r0,r0,0,14,12
  rlwimi    r0,r4,18,13,13
  stw       r0, 0x0(r3)
  bgt-      .loc_0x54
  lwz       r9, 0x0(r3)
  rlwinm    r4,r6,20,0,11
  rlwinm    r0,r5,16,0,15
  rlwinm    r5,r9,0,12,9
  or        r4, r5, r4
  stw       r4, 0x0(r3)
  lwz       r4, 0x0(r3)
  rlwinm    r4,r4,0,16,13
  or        r0, r4, r0
  stw       r0, 0x0(r3)
  b         .loc_0x74

.loc_0x54:
  lwz       r0, 0x0(r3)
  rlwinm    r0,r0,0,12,9
  rlwimi    r0,r4,19,10,11
  stw       r0, 0x0(r3)
  lwz       r0, 0x0(r3)
  rlwinm    r0,r0,0,16,13
  oris      r0, r0, 0x3
  stw       r0, 0x0(r3)

.loc_0x74:
  lwz       r4, 0x0(r3)
  rlwinm    r0,r7,19,5,12
  rlwinm    r6,r8,22,0,9
  rlwinm    r4,r4,0,13,11
  or        r0, r4, r0
  stw       r0, 0x0(r3)
  li        r4, 0x61
  lis       r5, 0xCC01
  lwz       r7, 0x0(r3)
  li        r0, 0x1
  rlwinm    r7,r7,0,10,7
  or        r6, r7, r6
  stw       r6, 0x0(r3)
  stb       r4, -0x8000(r5)
  lwz       r4, 0x2A68(r13)
  lwz       r3, 0x0(r3)
  stw       r3, -0x8000(r5)
  sth       r0, 0x2(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	80213304
 * Size:	0000C0
 */
void GXSetTevAlphaOp(void)
{
/*
.loc_0x0:
  rlwinm    r3,r3,2,0,29
  lwz       r0, 0x2A68(r13)
  addi      r3, r3, 0x170
  add       r3, r0, r3
  lwz       r0, 0x0(r3)
  cmpwi     r4, 0x1
  rlwinm    r0,r0,0,14,12
  rlwimi    r0,r4,18,13,13
  stw       r0, 0x0(r3)
  bgt-      .loc_0x54
  lwz       r9, 0x0(r3)
  rlwinm    r4,r6,20,0,11
  rlwinm    r0,r5,16,0,15
  rlwinm    r5,r9,0,12,9
  or        r4, r5, r4
  stw       r4, 0x0(r3)
  lwz       r4, 0x0(r3)
  rlwinm    r4,r4,0,16,13
  or        r0, r4, r0
  stw       r0, 0x0(r3)
  b         .loc_0x74

.loc_0x54:
  lwz       r0, 0x0(r3)
  rlwinm    r0,r0,0,12,9
  rlwimi    r0,r4,19,10,11
  stw       r0, 0x0(r3)
  lwz       r0, 0x0(r3)
  rlwinm    r0,r0,0,16,13
  oris      r0, r0, 0x3
  stw       r0, 0x0(r3)

.loc_0x74:
  lwz       r4, 0x0(r3)
  rlwinm    r0,r7,19,5,12
  rlwinm    r6,r8,22,0,9
  rlwinm    r4,r4,0,13,11
  or        r0, r4, r0
  stw       r0, 0x0(r3)
  li        r4, 0x61
  lis       r5, 0xCC01
  lwz       r7, 0x0(r3)
  li        r0, 0x1
  rlwinm    r7,r7,0,10,7
  or        r6, r7, r6
  stw       r6, 0x0(r3)
  stb       r4, -0x8000(r5)
  lwz       r4, 0x2A68(r13)
  lwz       r3, 0x0(r3)
  stw       r3, -0x8000(r5)
  sth       r0, 0x2(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	802133C4
 * Size:	000074
 */
void GXSetTevColor(void)
{
/*
.loc_0x0:
  lbz       r0, 0x3(r4)
  rlwinm    r8,r3,1,0,30
  lbz       r5, 0x0(r4)
  addi      r7, r8, 0xE0
  rlwinm    r9,r0,12,0,19
  rlwimi    r9,r5,0,24,31
  lbz       r10, 0x2(r4)
  lbz       r6, 0x1(r4)
  rlwinm    r7,r7,24,0,7
  li        r5, 0x61
  lwz       r3, 0x2A68(r13)
  lis       r4, 0xCC01
  stb       r5, -0x8000(r4)
  rlwimi    r7,r9,0,12,31
  addi      r0, r8, 0xE1
  stw       r7, -0x8000(r4)
  rlwinm    r7,r6,12,0,19
  rlwinm    r6,r0,24,0,7
  rlwimi    r7,r10,0,24,31
  stb       r5, -0x8000(r4)
  rlwimi    r6,r7,0,12,31
  stw       r6, -0x8000(r4)
  li        r0, 0x1
  stb       r5, -0x8000(r4)
  stw       r6, -0x8000(r4)
  stb       r5, -0x8000(r4)
  stw       r6, -0x8000(r4)
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80213438
 * Size:	000074
 */
void GXSetTevColorS10(void)
{
/*
.loc_0x0:
  lha       r0, 0x6(r4)
  rlwinm    r9,r3,1,0,30
  lha       r5, 0x0(r4)
  addi      r8, r9, 0xE0
  rlwinm    r10,r0,12,9,19
  rlwimi    r10,r5,0,21,31
  lha       r7, 0x4(r4)
  lha       r6, 0x2(r4)
  rlwinm    r8,r8,24,0,7
  li        r5, 0x61
  lwz       r3, 0x2A68(r13)
  lis       r4, 0xCC01
  stb       r5, -0x8000(r4)
  rlwimi    r8,r10,0,9,31
  addi      r0, r9, 0xE1
  stw       r8, -0x8000(r4)
  rlwinm    r8,r6,12,9,19
  rlwinm    r6,r0,24,0,7
  rlwimi    r8,r7,0,21,31
  stb       r5, -0x8000(r4)
  rlwimi    r6,r8,0,9,31
  stw       r6, -0x8000(r4)
  li        r0, 0x1
  stb       r5, -0x8000(r4)
  stw       r6, -0x8000(r4)
  stb       r5, -0x8000(r4)
  stw       r6, -0x8000(r4)
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	802134AC
 * Size:	000074
 */
void GXSetTevKColor(void)
{
/*
.loc_0x0:
  lbz       r0, 0x3(r4)
  rlwinm    r5,r3,1,0,30
  lbz       r6, 0x0(r4)
  addi      r7, r5, 0xE0
  rlwinm    r0,r0,12,0,19
  rlwimi    r0,r6,0,24,31
  lbz       r6, 0x1(r4)
  lbz       r9, 0x2(r4)
  rlwinm    r0,r0,0,12,7
  oris      r8, r0, 0x80
  lwz       r3, 0x2A68(r13)
  rlwinm    r7,r7,24,0,7
  li        r0, 0x61
  lis       r4, 0xCC01
  rlwinm    r6,r6,12,0,19
  stb       r0, -0x8000(r4)
  rlwimi    r7,r8,0,8,31
  stw       r7, -0x8000(r4)
  rlwimi    r6,r9,0,24,31
  addi      r5, r5, 0xE1
  stb       r0, -0x8000(r4)
  rlwinm    r0,r6,0,12,7
  oris      r6, r0, 0x80
  rlwinm    r0,r5,24,0,7
  rlwimi    r0,r6,0,8,31
  stw       r0, -0x8000(r4)
  li        r0, 0x1
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80213520
 * Size:	00006C
 */
void GXSetTevKColorSel(void)
{
/*
.loc_0x0:
  srawi     r5, r3, 0x1
  lwz       r6, 0x2A68(r13)
  rlwinm.   r0,r3,0,31,31
  rlwinm    r3,r5,2,0,29
  addi      r7, r3, 0x1B0
  add       r7, r6, r7
  beq-      .loc_0x34
  lwz       r3, 0x0(r7)
  rlwinm    r0,r4,14,0,17
  rlwinm    r3,r3,0,18,12
  or        r0, r3, r0
  stw       r0, 0x0(r7)
  b         .loc_0x48

.loc_0x34:
  lwz       r3, 0x0(r7)
  rlwinm    r0,r4,4,0,27
  rlwinm    r3,r3,0,28,22
  or        r0, r3, r0
  stw       r0, 0x0(r7)

.loc_0x48:
  li        r0, 0x61
  lwz       r3, 0x2A68(r13)
  lis       r5, 0xCC01
  stb       r0, -0x8000(r5)
  li        r0, 0x1
  lwz       r4, 0x0(r7)
  stw       r4, -0x8000(r5)
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8021358C
 * Size:	00006C
 */
void GXSetTevKAlphaSel(void)
{
/*
.loc_0x0:
  srawi     r5, r3, 0x1
  lwz       r6, 0x2A68(r13)
  rlwinm.   r0,r3,0,31,31
  rlwinm    r3,r5,2,0,29
  addi      r7, r3, 0x1B0
  add       r7, r6, r7
  beq-      .loc_0x34
  lwz       r3, 0x0(r7)
  rlwinm    r0,r4,19,0,12
  rlwinm    r3,r3,0,13,7
  or        r0, r3, r0
  stw       r0, 0x0(r7)
  b         .loc_0x48

.loc_0x34:
  lwz       r3, 0x0(r7)
  rlwinm    r0,r4,9,0,22
  rlwinm    r3,r3,0,23,17
  or        r0, r3, r0
  stw       r0, 0x0(r7)

.loc_0x48:
  li        r0, 0x61
  lwz       r3, 0x2A68(r13)
  lis       r5, 0xCC01
  stb       r0, -0x8000(r5)
  li        r0, 0x1
  lwz       r4, 0x0(r7)
  stw       r4, -0x8000(r5)
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	802135F8
 * Size:	000058
 */
void GXSetTevSwapMode(void)
{
/*
.loc_0x0:
  rlwinm    r3,r3,2,0,29
  lwz       r0, 0x2A68(r13)
  addi      r7, r3, 0x170
  add       r7, r0, r7
  lwz       r0, 0x0(r7)
  rlwinm    r6,r5,2,0,29
  li        r3, 0x61
  rlwinm    r0,r0,0,0,29
  or        r0, r0, r4
  stw       r0, 0x0(r7)
  lis       r5, 0xCC01
  li        r0, 0x1
  lwz       r4, 0x0(r7)
  rlwinm    r4,r4,0,30,27
  or        r4, r4, r6
  stw       r4, 0x0(r7)
  stb       r3, -0x8000(r5)
  lwz       r3, 0x2A68(r13)
  lwz       r4, 0x0(r7)
  stw       r4, -0x8000(r5)
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80213650
 * Size:	0000A0
 */
void GXSetTevSwapModeTable(void)
{
/*
.loc_0x0:
  rlwinm    r9,r3,1,0,30
  lwz       r0, 0x2A68(r13)
  rlwinm    r3,r3,3,0,28
  addi      r11, r3, 0x1B0
  add       r11, r0, r11
  lwz       r8, 0x0(r11)
  addi      r0, r9, 0x1
  rlwinm    r3,r0,2,0,29
  rlwinm    r0,r8,0,0,29
  or        r0, r0, r4
  stw       r0, 0x0(r11)
  rlwinm    r0,r5,2,0,29
  li        r9, 0x61
  lwz       r4, 0x0(r11)
  lis       r8, 0xCC01
  addi      r10, r3, 0x1B0
  rlwinm    r3,r4,0,30,27
  or        r0, r3, r0
  stw       r0, 0x0(r11)
  rlwinm    r3,r7,2,0,29
  li        r0, 0x1
  stb       r9, -0x8000(r8)
  lwz       r4, 0x2A68(r13)
  lwz       r5, 0x0(r11)
  add       r10, r4, r10
  stw       r5, -0x8000(r8)
  lwz       r4, 0x0(r10)
  rlwinm    r4,r4,0,0,29
  or        r4, r4, r6
  stw       r4, 0x0(r10)
  lwz       r4, 0x0(r10)
  rlwinm    r4,r4,0,30,27
  or        r3, r4, r3
  stw       r3, 0x0(r10)
  stb       r9, -0x8000(r8)
  lwz       r3, 0x2A68(r13)
  lwz       r4, 0x0(r10)
  stw       r4, -0x8000(r8)
  sth       r0, 0x2(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GXSetTevClampMode(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802136F0
 * Size:	000050
 */
void GXSetAlphaCompare(void)
{
/*
.loc_0x0:
  rlwinm    r7,r7,8,16,23
  lwz       r8, 0x2A68(r13)
  rlwimi    r7,r4,0,24,31
  rlwinm    r0,r3,16,0,15
  rlwimi    r0,r7,0,16,31
  rlwinm    r3,r0,0,13,9
  rlwinm    r0,r6,19,0,12
  or        r0, r3, r0
  rlwinm    r3,r0,0,10,7
  rlwinm    r0,r5,22,0,9
  or        r0, r3, r0
  rlwinm    r4,r0,0,8,31
  li        r0, 0x61
  lis       r3, 0xCC01
  stb       r0, -0x8000(r3)
  oris      r4, r4, 0xF300
  li        r0, 0x1
  stw       r4, -0x8000(r3)
  sth       r0, 0x2(r8)
  blr
*/
}

/*
 * --INFO--
 * Address:	80213740
 * Size:	000084
 */
void GXSetZTexture(void)
{
/*
.loc_0x0:
  cmpwi     r4, 0x13
  rlwinm    r0,r5,0,8,31
  oris      r7, r0, 0xF400
  beq-      .loc_0x34
  bge-      .loc_0x20
  cmpwi     r4, 0x11
  beq-      .loc_0x2C
  b         .loc_0x44

.loc_0x20:
  cmpwi     r4, 0x16
  beq-      .loc_0x3C
  b         .loc_0x44

.loc_0x2C:
  li        r6, 0
  b         .loc_0x48

.loc_0x34:
  li        r6, 0x1
  b         .loc_0x48

.loc_0x3C:
  li        r6, 0x2
  b         .loc_0x48

.loc_0x44:
  li        r6, 0x2

.loc_0x48:
  li        r0, 0x61
  lwz       r4, 0x2A68(r13)
  lis       r5, 0xCC01
  stb       r0, -0x8000(r5)
  rlwinm    r6,r6,0,30,27
  rlwinm    r3,r3,2,0,29
  stw       r7, -0x8000(r5)
  or        r3, r6, r3
  rlwinm    r3,r3,0,8,31
  stb       r0, -0x8000(r5)
  oris      r3, r3, 0xF500
  li        r0, 0x1
  stw       r3, -0x8000(r5)
  sth       r0, 0x2(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	802137C4
 * Size:	0001A0
 */
void GXSetTevOrder(void)
{
/*
.loc_0x0:
  srawi     r7, r3, 0x1
  lwz       r9, 0x2A68(r13)
  rlwinm    r10,r5,0,24,22
  addze     r7, r7
  rlwinm    r0,r3,2,0,29
  add       r8, r9, r0
  rlwinm    r7,r7,2,0,29
  stw       r5, 0x49C(r8)
  addi      r7, r7, 0x100
  cmplwi    r10, 0x8
  addi      r0, r10, 0
  add       r7, r9, r7
  blt-      .loc_0x3C
  li        r9, 0
  b         .loc_0x40

.loc_0x3C:
  mr        r9, r0

.loc_0x40:
  cmpwi     r4, 0x8
  blt-      .loc_0x4C
  li        r4, 0

.loc_0x4C:
  rlwinm.   r0,r3,0,31,31
  beq-      .loc_0xE4
  lwz       r8, 0x0(r7)
  rlwinm    r3,r9,12,0,19
  rlwinm    r0,r4,15,0,16
  rlwinm    r4,r8,0,20,16
  or        r3, r4, r3
  stw       r3, 0x0(r7)
  cmpwi     r6, 0xFF
  lwz       r3, 0x0(r7)
  rlwinm    r3,r3,0,17,13
  or        r0, r3, r0
  stw       r0, 0x0(r7)
  bne-      .loc_0x8C
  li        r0, 0x7
  b         .loc_0xA0

.loc_0x8C:
  lis       r3, 0x802F
  rlwinm    r4,r6,2,0,29
  subi      r0, r3, 0x7050
  add       r3, r0, r4
  lwz       r0, 0x0(r3)

.loc_0xA0:
  lwz       r3, 0x0(r7)
  rlwinm    r0,r0,19,0,12
  cmpwi     r5, 0xFF
  rlwinm    r3,r3,0,13,9
  or        r0, r3, r0
  stw       r0, 0x0(r7)
  li        r4, 0
  beq-      .loc_0xCC
  rlwinm.   r0,r5,0,23,23
  bne-      .loc_0xCC
  li        r4, 0x1

.loc_0xCC:
  lwz       r3, 0x0(r7)
  rlwinm    r0,r4,18,0,13
  rlwinm    r3,r3,0,14,12
  or        r0, r3, r0
  stw       r0, 0x0(r7)
  b         .loc_0x16C

.loc_0xE4:
  lwz       r3, 0x0(r7)
  rlwinm    r0,r4,3,0,28
  cmpwi     r6, 0xFF
  rlwinm    r3,r3,0,0,28
  or        r3, r3, r9
  stw       r3, 0x0(r7)
  lwz       r3, 0x0(r7)
  rlwinm    r3,r3,0,29,25
  or        r0, r3, r0
  stw       r0, 0x0(r7)
  bne-      .loc_0x118
  li        r0, 0x7
  b         .loc_0x12C

.loc_0x118:
  lis       r3, 0x802F
  rlwinm    r4,r6,2,0,29
  subi      r0, r3, 0x7050
  add       r3, r0, r4
  lwz       r0, 0x0(r3)

.loc_0x12C:
  lwz       r3, 0x0(r7)
  rlwinm    r0,r0,7,0,24
  cmpwi     r5, 0xFF
  rlwinm    r3,r3,0,25,21
  or        r0, r3, r0
  stw       r0, 0x0(r7)
  li        r4, 0
  beq-      .loc_0x158
  rlwinm.   r0,r5,0,23,23
  bne-      .loc_0x158
  li        r4, 0x1

.loc_0x158:
  lwz       r3, 0x0(r7)
  rlwinm    r0,r4,6,0,25
  rlwinm    r3,r3,0,26,24
  or        r0, r3, r0
  stw       r0, 0x0(r7)

.loc_0x16C:
  li        r0, 0x61
  lwz       r3, 0x2A68(r13)
  lis       r5, 0xCC01
  stb       r0, -0x8000(r5)
  li        r0, 0x1
  lwz       r4, 0x0(r7)
  stw       r4, -0x8000(r5)
  sth       r0, 0x2(r3)
  lwz       r3, 0x2A68(r13)
  lwz       r0, 0x4F0(r3)
  ori       r0, r0, 0x1
  stw       r0, 0x4F0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80213964
 * Size:	000034
 */
void GXSetNumTevStages(void)
{
/*
.loc_0x0:
  rlwinm    r3,r3,0,24,31
  lwz       r4, 0x2A68(r13)
  subi      r0, r3, 0x1
  lwzu      r3, 0x204(r4)
  rlwinm    r0,r0,10,0,21
  rlwinm    r3,r3,0,22,17
  or        r0, r3, r0
  stw       r0, 0x0(r4)
  lwz       r3, 0x2A68(r13)
  lwz       r0, 0x4F0(r3)
  ori       r0, r0, 0x4
  stw       r0, 0x4F0(r3)
  blr
*/
}