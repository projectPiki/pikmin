

/*
 * --INFO--
 * Address:	8001B3E0
 * Size:	0000D0
 */
void Jaf_InitSeqArchive2(char *, unsigned char *, unsigned char *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r28, 0x20(r1)
  addi      r28, r4, 0
  addi      r29, r5, 0
  stw       r3, 0x8(r1)
  lwz       r31, 0x8(r1)
  mr        r3, r31
  bl        0x1FE008
  mr.       r30, r3
  mtctr     r30
  beq-      .loc_0x50

.loc_0x34:
  subi      r0, r30, 0x1
  lbzx      r0, r31, r0
  extsb     r0, r0
  cmpwi     r0, 0x2F
  beq-      .loc_0x50
  subi      r30, r30, 0x1
  bdnz+     .loc_0x34

.loc_0x50:
  addi      r3, r31, 0
  addi      r4, r28, 0
  addi      r5, r29, 0
  bl        -0xCEBC
  add       r3, r31, r30
  bl        -0xCD84
  li        r6, 0
  lis       r5, 0x8036
  li        r0, 0x100
  addi      r4, r6, 0
  stw       r3, 0x2D58(r13)
  addi      r5, r5, 0x4688
  mtctr     r0

.loc_0x84:
  add       r3, r5, r4
  addi      r4, r4, 0x4
  stw       r6, 0x0(r3)
  bdnz+     .loc_0x84
  lis       r3, 0x8037
  li        r0, 0x10
  subi      r5, r3, 0x7238
  li        r3, 0
  li        r6, -0x1
  mtctr     r0

.loc_0xAC:
  add       r4, r5, r3
  addi      r3, r3, 0x4
  stw       r6, 0x0(r4)
  bdnz+     .loc_0xAC
  lmw       r28, 0x20(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001B4C0
 * Size:	00003C
 */
void Jaf_CheckSeqSize(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r4, 0x2D58(r13)
  addis     r0, r4, 0x1
  cmplwi    r0, 0xFFFF
  bne-      .loc_0x24
  li        r3, 0
  b         .loc_0x2C

.loc_0x24:
  or        r3, r4, r3
  bl        -0xCD28

.loc_0x2C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001B500
 * Size:	000088
 */
void Jaf_LoadSeq(unsigned long, unsigned char *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stmw      r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r31, r4, 0
  lwz       r5, 0x2D58(r13)
  addis     r0, r5, 0x1
  cmplwi    r0, 0xFFFF
  bne-      .loc_0x30
  li        r3, 0
  b         .loc_0x74

.loc_0x30:
  mr        r3, r30
  bl        -0x74
  cmplwi    r3, 0
  bne-      .loc_0x48
  li        r3, 0
  b         .loc_0x74

.loc_0x48:
  lwz       r0, 0x2D58(r13)
  addi      r6, r3, 0
  addi      r4, r31, 0
  li        r5, 0
  or        r3, r0, r30
  bl        -0xCD5C
  lis       r4, 0x8036
  rlwinm    r5,r30,2,0,29
  addi      r0, r4, 0x4688
  add       r4, r0, r5
  stw       r31, 0x0(r4)

.loc_0x74:
  lwz       r0, 0x1C(r1)
  lmw       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001B5A0
 * Size:	00001C
 */
void Jaf_ClearSeq(unsigned long)
{
/*
.loc_0x0:
  lis       r4, 0x8036
  rlwinm    r3,r3,2,0,29
  addi      r0, r4, 0x4688
  li        r4, 0
  add       r3, r0, r3
  stw       r4, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001B5C0
 * Size:	000018
 */
void Jaf_CheckSeq(unsigned long)
{
/*
.loc_0x0:
  lis       r4, 0x8036
  rlwinm    r3,r3,2,0,29
  addi      r0, r4, 0x4688
  add       r3, r0, r3
  lwz       r3, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001B5E0
 * Size:	0000A0
 */
void Jaf_ReadySeq(unsigned long, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  cmplwi    r4, 0x100
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r28, 0x18(r1)
  addi      r28, r3, 0
  mulli     r0, r28, 0x434
  lis       r3, 0x8036
  addi      r31, r3, 0x4688
  add       r29, r31, r0
  addi      r29, r29, 0x400
  blt-      .loc_0x38
  li        r3, 0
  b         .loc_0x8C

.loc_0x38:
  rlwinm    r0,r4,2,0,29
  add       r30, r31, r0
  lwz       r0, 0x0(r30)
  cmplwi    r0, 0
  bne-      .loc_0x54
  li        r3, 0
  b         .loc_0x8C

.loc_0x54:
  mr        r3, r4
  bl        -0x178
  mr.       r5, r3
  bne-      .loc_0x6C
  li        r3, 0
  b         .loc_0x8C

.loc_0x6C:
  lwz       r4, 0x0(r30)
  addi      r3, r29, 0
  li        r6, 0
  bl        -0x7198
  rlwinm    r0,r28,2,0,29
  add       r4, r31, r0
  stw       r3, 0x4740(r4)
  lwz       r3, 0x4740(r4)

.loc_0x8C:
  lmw       r28, 0x18(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001B680
 * Size:	000038
 */
void Jaf_PlaySeq(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8037
  stw       r0, 0x4(r1)
  rlwinm    r3,r3,2,0,29
  subi      r0, r4, 0x7238
  stwu      r1, -0x8(r1)
  add       r3, r0, r3
  lwz       r3, 0x0(r3)
  bl        -0x6FE0
  li        r3, 0x1
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001B6C0
 * Size:	000038
 */
void Jaf_StartSeq(unsigned long, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        -0xF4
  mr        r3, r31
  bl        -0x5C
  lwz       r0, 0x1C(r1)
  li        r3, 0x1
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8001B700
 * Size:	000070
 */
void Jaf_StopSeq(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8037
  stw       r0, 0x4(r1)
  rlwinm    r3,r3,2,0,29
  subi      r0, r4, 0x7238
  stwu      r1, -0x20(r1)
  stmw      r30, 0x18(r1)
  add       r31, r0, r3
  lwz       r3, 0x0(r31)
  addis     r0, r3, 0x1
  cmplwi    r0, 0xFFFF
  bne-      .loc_0x38
  li        r3, 0
  b         .loc_0x5C

.loc_0x38:
  bl        -0x7378
  mr        r30, r3

.loc_0x40:
  lwz       r3, 0x0(r31)
  bl        -0x7724
  cmplwi    r3, 0
  bne+      .loc_0x40
  li        r0, -0x1
  addi      r3, r30, 0
  stw       r0, 0x0(r31)

.loc_0x5C:
  lwz       r0, 0x24(r1)
  lmw       r30, 0x18(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void Jaf_GetJamHandle(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001B780
 * Size:	000014
 */
void Jaf_HandleToSeq(unsigned long)
{
/*
.loc_0x0:
  mulli     r4, r3, 0x434
  lis       r3, 0x8036
  addi      r0, r3, 0x4A88
  add       r3, r0, r4
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void Jaf_LoadStartFinish(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001B7A0
 * Size:	000028
 */
void Jaf_LoadFinish(unsigned long)
{
/*
.loc_0x0:
  lwz       r0, 0x4(r3)
  lis       r4, 0x8036
  addi      r4, r4, 0x4688
  lwz       r6, 0xC(r3)
  rlwinm    r5,r0,2,0,29
  li        r0, 0
  add       r4, r4, r5
  stw       r6, 0x0(r4)
  stb       r0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8001B7E0
 * Size:	000124
 */
void __LoadSeqA(unsigned long, unsigned long, unsigned char *, void (*) (unsigned long))
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x8036
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r28, 0x28(r1)
  addi      r30, r6, 0
  addi      r31, r7, 0x4688
  lwz       r0, -0x7ED8(r13)
  stw       r3, 0x8(r1)
  cmplwi    r0, 0
  stw       r4, 0xC(r1)
  stw       r5, 0x10(r1)
  beq-      .loc_0x5C
  li        r3, 0
  li        r0, 0x8
  addi      r5, r3, 0
  mtctr     r0

.loc_0x44:
  add       r4, r31, r3
  addi      r3, r3, 0x10
  stb       r5, 0x4780(r4)
  bdnz+     .loc_0x44
  li        r0, 0
  stw       r0, -0x7ED8(r13)

.loc_0x5C:
  li        r0, 0x8
  li        r28, 0
  li        r3, 0
  mtctr     r0

.loc_0x6C:
  add       r4, r31, r3
  lbz       r0, 0x4780(r4)
  cmplwi    r0, 0
  beq-      .loc_0x88
  addi      r28, r28, 0x1
  addi      r3, r3, 0x10
  bdnz+     .loc_0x6C

.loc_0x88:
  cmplwi    r28, 0x8
  bne-      .loc_0x98
  li        r3, 0
  b         .loc_0x110

.loc_0x98:
  lwz       r3, 0x2D58(r13)
  addis     r0, r3, 0x1
  cmplwi    r0, 0xFFFF
  bne-      .loc_0xB0
  li        r3, 0
  b         .loc_0x110

.loc_0xB0:
  lwz       r29, 0xC(r1)
  mr        r3, r29
  bl        -0x3D8
  mr.       r6, r3
  bne-      .loc_0xCC
  li        r3, 0
  b         .loc_0x110

.loc_0xCC:
  lwz       r0, 0x2D58(r13)
  rlwinm    r4,r28,4,0,27
  li        r11, 0x1
  add       r8, r31, r4
  stbu      r11, 0x4780(r8)
  add       r10, r31, r4
  or        r3, r0, r29
  rlwinm    r0,r29,2,0,29
  stw       r29, 0x4784(r10)
  addi      r7, r30, 0
  li        r5, 0
  lwz       r4, 0x10(r1)
  stw       r4, 0x478C(r10)
  lwz       r9, 0x8(r1)
  stw       r9, 0x4788(r10)
  stwx      r11, r31, r0
  bl        -0xD00C

.loc_0x110:
  lmw       r28, 0x28(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void Jaf_LoadStartSeqA(unsigned long, unsigned long, unsigned char *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001B920
 * Size:	000034
 */
void Jaf_LoadSeqA(unsigned long, unsigned char *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r6, 0x8002
  stw       r0, 0x4(r1)
  addi      r5, r4, 0
  addi      r4, r3, 0
  subi      r6, r6, 0x4860
  stwu      r1, -0x8(r1)
  li        r3, 0
  bl        -0x160
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}