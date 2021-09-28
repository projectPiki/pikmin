

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jac_RegisterARAMCallback(unsigned long (*) (char *, unsigned long, unsigned long, unsigned long *, jaheap_ *))
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000D8A0
 * Size:	000064
 */
void LoadAram(char *, unsigned long *, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  addi      r8, r4, 0
  stw       r0, 0x4(r1)
  li        r6, 0
  li        r7, 0
  li        r9, 0
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r5, 0x10(r1)
  stw       r3, 0x8(r1)
  li        r3, 0
  lwz       r31, 0x10(r1)
  lwz       r4, 0x8(r1)
  addi      r5, r31, 0
  bl        -0x5AF8
  cmpwi     r3, -0x1
  bne-      .loc_0x4C
  li        r3, 0
  b         .loc_0x50

.loc_0x4C:
  mr        r3, r31

.loc_0x50:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000D920
 * Size:	000068
 */
void LoadAramSingle(char *, unsigned long, unsigned long, unsigned long *, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  addi      r8, r6, 0
  stw       r0, 0x4(r1)
  li        r9, 0
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  addi      r31, r7, 0
  stw       r5, 0x10(r1)
  mr        r5, r31
  stw       r3, 0x8(r1)
  li        r3, 0
  lwz       r7, 0x10(r1)
  stw       r4, 0xC(r1)
  lwz       r4, 0x8(r1)
  lwz       r6, 0xC(r1)
  bl        -0x5B7C
  cmpwi     r3, -0x1
  bne-      .loc_0x50
  li        r3, 0
  b         .loc_0x54

.loc_0x50:
  mr        r3, r31

.loc_0x54:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void Jac_WaveDirectorySet(char *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void Get_AramMotherHeap()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000D9A0
 * Size:	00002C
 */
void Show_AramMotherHeap()
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803E
  stw       r0, 0x4(r1)
  li        r4, 0
  subi      r3, r3, 0x5060
  stwu      r1, -0x8(r1)
  bl        0x1968
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000D9E0
 * Size:	00002C
 */
void Collect_AramMotherHeap()
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803E
  stw       r0, 0x4(r1)
  subi      r3, r3, 0x5060
  stwu      r1, -0x8(r1)
  bl        0x184C
  bl        -0x58
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000DA20
 * Size:	00006C
 */
void Init_AramMotherHeap()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  lbz       r0, 0x2BEC(r13)
  extsb.    r0, r0
  bne-      .loc_0x28
  li        r3, 0
  li        r0, 0x1
  stw       r3, 0x2BE8(r13)
  stb       r0, 0x2BEC(r13)

.loc_0x28:
  lwz       r0, 0x2BE8(r13)
  cmpwi     r0, 0
  bne-      .loc_0x5C
  li        r0, 0x1
  addi      r3, r1, 0x8
  stw       r0, 0x2BE8(r13)
  bl        -0x78A0
  lis       r5, 0x803E
  addi      r4, r3, 0
  subi      r3, r5, 0x5060
  lwz       r5, 0x8(r1)
  li        r6, 0
  bl        0x1368

.loc_0x5C:
  lwz       r0, 0x14(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000DAA0
 * Size:	0000F8
 */
void LoadAram_Default(char *, unsigned long, unsigned long, unsigned long *, jaheap_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC0(r1)
  stmw      r27, 0xAC(r1)
  addi      r27, r3, 0
  addi      r28, r4, 0
  addi      r29, r5, 0
  addi      r30, r6, 0
  addi      r31, r7, 0
  lwz       r0, -0x7FC4(r13)
  cmpwi     r0, 0
  beq-      .loc_0x3C
  bl        -0xB0
  li        r0, 0
  stw       r0, -0x7FC4(r13)

.loc_0x3C:
  lis       r4, 0x8022
  addi      r3, r1, 0x1C
  addi      r4, r4, 0x5028
  bl        0x20B870
  addi      r3, r1, 0x1C
  addi      r4, r27, 0
  bl        0x20B7F4
  cmplwi    r28, 0
  bne-      .loc_0xA8
  cmplwi    r29, 0
  bne-      .loc_0xA8
  addi      r3, r1, 0x1C
  bl        -0x5C8C
  lis       r4, 0x803E
  addi      r5, r3, 0
  subi      r4, r4, 0x5060
  addi      r3, r31, 0
  bl        0x1320
  cmpwi     r3, 0
  bne-      .loc_0x94
  li        r3, 0
  b         .loc_0xE4

.loc_0x94:
  lwz       r5, 0x8(r31)
  addi      r4, r30, 0
  addi      r3, r1, 0x1C
  bl        -0x2A0
  b         .loc_0xE4

.loc_0xA8:
  lis       r4, 0x803E
  addi      r3, r31, 0
  subi      r4, r4, 0x5060
  addi      r5, r29, 0
  bl        0x12E8
  cmpwi     r3, 0
  bne-      .loc_0xCC
  li        r3, 0
  b         .loc_0xE4

.loc_0xCC:
  lwz       r7, 0x8(r31)
  addi      r4, r28, 0
  addi      r5, r29, 0
  addi      r6, r30, 0
  addi      r3, r1, 0x1C
  bl        -0x260

.loc_0xE4:
  lmw       r27, 0xAC(r1)
  lwz       r0, 0xC4(r1)
  addi      r1, r1, 0xC0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000DBA0
 * Size:	000038
 */
void LoadAram_All(char *, unsigned long *, jaheap_ *)
{
/*
.loc_0x0:
  mflr      r0
  addi      r6, r4, 0
  stw       r0, 0x4(r1)
  addi      r7, r5, 0
  li        r4, 0
  li        r5, 0
  stwu      r1, -0x8(r1)
  lwz       r12, -0x7FC8(r13)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8000DBE0
 * Size:	000028
 */
void LoadAram_One(char *, unsigned long, unsigned long, unsigned long *, jaheap_ *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, -0x7FC8(r13)
  mtlr      r12
  blrl      
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}