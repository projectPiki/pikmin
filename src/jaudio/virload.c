

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void JV_InitHeader(char *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E580
 * Size:	000138
 */
void JV_InitHeader_M(char *, unsigned char *, unsigned char *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r27, 0x24(r1)
  mr.       r30, r4
  lis       r4, 0x8031
  addi      r31, r5, 0
  subi      r29, r4, 0xD18
  stw       r3, 0x8(r1)
  bne-      .loc_0x74
  lwz       r28, 0x8(r1)
  mr        r3, r28
  bl        -0x6730
  cmplwi    r3, 0
  bne-      .loc_0x44
  li        r3, 0
  b         .loc_0x124

.loc_0x44:
  bl        -0x8E44
  mr.       r30, r3
  bne-      .loc_0x58
  li        r3, 0
  b         .loc_0x124

.loc_0x58:
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        -0x66E0
  cmplwi    r3, 0
  bne-      .loc_0x74
  li        r3, 0
  b         .loc_0x124

.loc_0x74:
  lwz       r28, 0x8(r1)
  mr        r3, r28
  bl        0x20AE10
  subic.    r27, r3, 0x1
  add       r3, r28, r27
  mtctr     r27
  beq-      .loc_0xA8

.loc_0x90:
  lbz       r0, 0x0(r3)
  cmpwi     r0, 0x2F
  beq-      .loc_0xA8
  subi      r27, r27, 0x1
  subi      r3, r3, 0x1
  bdnz+     .loc_0x90

.loc_0xA8:
  cmplwi    r27, 0
  bne-      .loc_0xC8
  lwz       r0, 0x2C10(r13)
  subi      r4, r2, 0x7F30
  rlwinm    r0,r0,6,0,25
  add       r3, r29, r0
  bl        0x20AD18
  b         .loc_0xE0

.loc_0xC8:
  lwz       r0, 0x2C10(r13)
  addi      r4, r28, 0
  addi      r5, r27, 0
  rlwinm    r0,r0,6,0,25
  add       r3, r29, r0
  bl        0x20ACB8

.loc_0xE0:
  lwz       r0, 0x2C10(r13)
  add       r4, r27, r28
  addi      r4, r4, 0x1
  rlwinm    r0,r0,5,0,26
  add       r3, r29, r0
  addi      r3, r3, 0x400
  bl        0x20ACE0
  lwz       r0, 0x2C10(r13)
  li        r3, 0x1
  rlwinm    r0,r0,2,0,29
  add       r4, r29, r0
  stw       r30, 0x600(r4)
  lwz       r4, 0x600(r4)
  stw       r31, 0x8(r4)
  lwz       r4, 0x2C10(r13)
  addi      r0, r4, 0x1
  stw       r0, 0x2C10(r13)

.loc_0x124:
  lmw       r27, 0x24(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000E6C0
 * Size:	00007C
 */
void JV_GetArchiveHandle(char *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8031
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stmw      r28, 0x10(r1)
  addi      r28, r3, 0
  subi      r30, r4, 0x918
  li        r29, 0
  li        r31, 0
  b         .loc_0x44

.loc_0x28:
  add       r4, r30, r31
  addi      r3, r28, 0
  bl        0x20AAD4
  cmpwi     r3, 0
  beq-      .loc_0x50
  addi      r29, r29, 0x1
  addi      r31, r31, 0x20

.loc_0x44:
  lwz       r0, 0x2C10(r13)
  cmplw     r29, r0
  blt+      .loc_0x28

.loc_0x50:
  lwz       r0, 0x2C10(r13)
  cmplw     r29, r0
  beq-      .loc_0x64
  rlwinm    r3,r29,16,0,15
  b         .loc_0x68

.loc_0x64:
  li        r3, -0x1

.loc_0x68:
  lmw       r28, 0x10(r1)
  lwz       r0, 0x24(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void JV_GetLogicalHandleS(char *, char *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000154
 */
void JV_GetLogicalHandle(char *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void JV_GetHandle(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E740
 * Size:	000080
 */
void JV_GetRealHandle(unsigned long)
{
/*
.loc_0x0:
  lwz       r0, 0x2C10(r13)
  rlwinm    r4,r3,16,16,31
  rlwinm    r5,r3,0,16,31
  cmplw     r4, r0
  blt-      .loc_0x1C
  li        r3, 0
  blr       

.loc_0x1C:
  lis       r3, 0x8031
  rlwinm    r4,r4,2,0,29
  subi      r0, r3, 0x718
  add       r3, r0, r4
  lwz       r4, 0x0(r3)
  cmplwi    r4, 0
  bne-      .loc_0x40
  li        r3, 0
  blr       

.loc_0x40:
  lwz       r0, 0xC(r4)
  cmplw     r5, r0
  blt-      .loc_0x54
  li        r3, 0
  blr       

.loc_0x54:
  rlwinm    r3,r5,5,0,26
  addi      r3, r3, 0x20
  add       r3, r4, r3
  b         .loc_0x70

.loc_0x64:
  rlwinm    r3,r0,5,0,26
  addi      r3, r3, 0x20
  add       r3, r4, r3

.loc_0x70:
  lhz       r0, 0xE(r3)
  cmplwi    r0, 0xFFFF
  bne+      .loc_0x64
  blr
*/
}

/*
 * --INFO--
 * Address:	8000E7C0
 * Size:	000034
 */
void JV_CheckSize(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x8C
  cmplwi    r3, 0
  bne-      .loc_0x20
  li        r3, 0
  b         .loc_0x24

.loc_0x20:
  lwz       r3, 0x1C(r3)

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
 * Size:	000004
 */
void __JV_Callback(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000E800
 * Size:	0000D0
 */
void JV_LoadFile(unsigned long, unsigned char *, unsigned long, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0xC8(r1)
  stmw      r30, 0xC0(r1)
  addi      r30, r5, 0
  stw       r3, 0x8(r1)
  lwz       r3, 0x8(r1)
  stw       r4, 0xC(r1)
  rlwinm    r31,r3,16,16,31
  stw       r6, 0x14(r1)
  stw       r0, 0x30(r1)
  bl        -0xF0
  lwz       r5, 0x18(r3)
  lis       r3, 0x8031
  subi      r0, r3, 0xD18
  rlwinm    r4,r31,6,0,25
  stw       r5, 0xB4(r1)
  add       r4, r0, r4
  addi      r3, r1, 0x34
  lwz       r0, 0xB4(r1)
  add       r0, r0, r30
  stw       r0, 0xB4(r1)
  bl        0x20AAFC
  addi      r3, r1, 0x34
  subi      r4, r2, 0x7F30
  bl        0x20AA80
  lis       r3, 0x8031
  rlwinm    r4,r31,2,0,29
  subi      r0, r3, 0x718
  addi      r3, r1, 0x34
  add       r4, r0, r4
  lwz       r4, 0x0(r4)
  addi      r4, r4, 0x10
  bl        0x20AA60
  lwz       r5, 0xC(r1)
  addi      r4, r1, 0x34
  lwz       r6, 0xB4(r1)
  addi      r8, r1, 0x30
  lwz       r7, 0x14(r1)
  li        r3, 0
  li        r9, 0
  bl        -0x6FA8

.loc_0xAC:
  lwz       r0, 0x30(r1)
  cmplwi    r0, 0
  beq+      .loc_0xAC
  lwz       r3, 0x30(r1)
  lwz       r0, 0xCC(r1)
  lmw       r30, 0xC0(r1)
  addi      r1, r1, 0xC8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000E8E0
 * Size:	0000E0
 */
void JV_LoadFile_Async2(unsigned long, unsigned char *, unsigned long, unsigned long, void (*) (unsigned long), unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xD8(r1)
  stmw      r28, 0xC8(r1)
  mr        r28, r5
  addi      r31, r7, 0
  addi      r29, r8, 0
  lbz       r0, 0x2C18(r13)
  stw       r3, 0x8(r1)
  extsb.    r0, r0
  stw       r4, 0xC(r1)
  stw       r6, 0x14(r1)
  bne-      .loc_0x40
  li        r0, 0x1
  stw       r0, 0x2C14(r13)
  stb       r0, 0x2C18(r13)

.loc_0x40:
  lwz       r3, 0x8(r1)
  rlwinm    r30,r3,16,16,31
  bl        -0x1E8
  lwz       r5, 0x18(r3)
  lis       r3, 0x8031
  subi      r0, r3, 0xD18
  rlwinm    r4,r30,6,0,25
  stw       r5, 0xBC(r1)
  add       r4, r0, r4
  addi      r3, r1, 0x3C
  lwz       r0, 0xBC(r1)
  add       r0, r0, r28
  stw       r0, 0xBC(r1)
  bl        0x20AA04
  addi      r3, r1, 0x3C
  subi      r4, r2, 0x7F30
  bl        0x20A988
  lis       r3, 0x8031
  rlwinm    r4,r30,2,0,29
  subi      r0, r3, 0x718
  addi      r3, r1, 0x3C
  add       r4, r0, r4
  lwz       r4, 0x0(r4)
  addi      r4, r4, 0x10
  bl        0x20A968
  lwz       r30, 0x14(r1)
  mr        r3, r29
  lwz       r5, 0xC(r1)
  mr        r9, r31
  lwz       r6, 0xBC(r1)
  addi      r7, r30, 0
  addi      r4, r1, 0x3C
  li        r8, 0
  bl        -0x70A4
  mr        r3, r30
  lmw       r28, 0xC8(r1)
  lwz       r0, 0xDC(r1)
  addi      r1, r1, 0xD8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void JV_GetMemoryFile(unsigned long)
{
	// UNUSED FUNCTION
}