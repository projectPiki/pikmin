

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014D2D0
 * Size:	00008C
 */
void makeObjectBoss()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x2C
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  bl        -0x1062E0
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x74
  lis       r4, 0x802D
  lis       r5, 0x802D
  subi      r6, r4, 0x18D8
  lis       r4, 0x626F
  subi      r5, r5, 0x18E4
  addi      r4, r4, 0x7373
  bl        -0x72658
  lis       r3, 0x802C
  subi      r0, r3, 0x5490
  lis       r3, 0x802D
  stw       r0, 0x4(r31)
  subi      r0, r3, 0x185C
  stw       r0, 0x4(r31)
  li        r3, 0
  li        r0, -0x1
  stw       r3, 0x18(r31)
  stw       r3, 0x1C(r31)
  stw       r3, 0x20(r31)
  stw       r3, 0x24(r31)
  stw       r0, 0x28(r31)

.loc_0x74:
  mr        r3, r31
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014D35C
 * Size:	000088
 */
void GenObjectBoss::initialise()
{
/*
.loc_0x0:
  lwz       r7, 0x3074(r13)
  lwz       r5, 0x0(r7)
  lwz       r0, 0x4(r7)
  cmpw      r5, r0
  bgelr-    
  lis       r4, 0x626F
  lwz       r3, 0x8(r7)
  addi      r4, r4, 0x7373
  rlwinm    r0,r5,4,0,27
  stwx      r4, r3, r0
  lis       r4, 0x8015
  lis       r3, 0x802D
  lwz       r0, 0x0(r7)
  subi      r6, r4, 0x2D30
  lwz       r4, 0x8(r7)
  subi      r5, r3, 0x18CC
  rlwinm    r0,r0,4,0,27
  add       r3, r4, r0
  stw       r6, 0x4(r3)
  li        r4, 0x2
  lwz       r0, 0x0(r7)
  lwz       r3, 0x8(r7)
  rlwinm    r0,r0,4,0,27
  add       r3, r3, r0
  stw       r5, 0x8(r3)
  lwz       r0, 0x0(r7)
  lwz       r3, 0x8(r7)
  rlwinm    r0,r0,4,0,27
  add       r3, r3, r0
  stw       r4, 0xC(r3)
  lwz       r3, 0x0(r7)
  addi      r0, r3, 0x1
  stw       r0, 0x0(r7)
  blr
*/
}

/*
 * --INFO--
 * Address:	8014D3E4
 * Size:	0000EC
 */
void GenObjectBoss::doRead(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r4, 0
  stw       r30, 0x20(r1)
  mr        r30, r3
  lwz       r3, 0xC(r3)
  subis     r0, r3, 0x7630
  cmplwi    r0, 0x2E30
  bne-      .loc_0x48
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x18(r30)
  b         .loc_0xD4

.loc_0x48:
  cmplwi    r3, 0x2
  bge-      .loc_0xC8
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x18(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x1C(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x20(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x24(r30)
  addi      r3, r1, 0x10
  bl        -0x10963C
  addi      r3, r1, 0x10
  addi      r4, r31, 0
  bl        -0x109408
  b         .loc_0xD4

.loc_0xC8:
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        0x7C

.loc_0xD4:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014D4D0
 * Size:	000020
 */
void GenObjectBoss::doWrite(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0xD4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014D4F0
 * Size:	000020
 */
void GenObjectBoss::ramLoadParameters(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x34
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014D510
 * Size:	000020
 */
void GenObjectBoss::ramSaveParameters(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x94
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014D530
 * Size:	000080
 */
void GenObjectBoss::readParameters(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  addi      r3, r4, 0
  lwz       r12, 0x4(r4)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x10(r1)
  lbz       r0, 0x13(r1)
  rlwinm    r0,r0,0,28,31
  stw       r0, 0x18(r31)
  lbz       r0, 0x13(r1)
  rlwinm    r0,r0,28,30,31
  stw       r0, 0x1C(r31)
  lbz       r0, 0x13(r1)
  rlwinm    r0,r0,26,30,31
  stw       r0, 0x20(r31)
  lbz       r0, 0x12(r1)
  rlwinm    r0,r0,0,28,31
  stw       r0, 0x24(r31)
  lwz       r0, 0x10(r1)
  rlwinm    r3,r0,20,12,31
  subi      r0, r3, 0x1
  stw       r0, 0x28(r31)
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014D5B0
 * Size:	000090
 */
void GenObjectBoss::writeParameters(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x18(r1)
  stw       r0, 0x10(r1)
  lwz       r5, 0x18(r3)
  lbz       r0, 0x13(r1)
  rlwimi    r0,r5,0,28,31
  stb       r0, 0x13(r1)
  lwz       r5, 0x1C(r3)
  lbz       r0, 0x13(r1)
  rlwimi    r0,r5,4,26,27
  stb       r0, 0x13(r1)
  lwz       r5, 0x20(r3)
  lbz       r0, 0x13(r1)
  rlwimi    r0,r5,6,24,25
  stb       r0, 0x13(r1)
  lwz       r5, 0x24(r3)
  lbz       r0, 0x12(r1)
  rlwimi    r0,r5,0,28,31
  stb       r0, 0x12(r1)
  lwz       r5, 0x28(r3)
  mr        r3, r4
  lwz       r0, 0x10(r1)
  addi      r4, r5, 0x1
  rlwimi    r0,r4,12,0,19
  stw       r0, 0x10(r1)
  lwz       r12, 0x4(r3)
  lwz       r4, 0x10(r1)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014D640
 * Size:	000150
 */
void GenObjectBoss::updateUseList(Generator *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x18(r3)
  cmpwi     r0, 0
  bne-      .loc_0x2C
  lwz       r3, 0x3168(r13)
  li        r4, 0
  li        r5, 0x1
  bl        0x2D24
  b         .loc_0x140

.loc_0x2C:
  cmpwi     r0, 0x1
  bne-      .loc_0x48
  lwz       r3, 0x3168(r13)
  li        r4, 0x1
  li        r5, 0x1
  bl        0x2D08
  b         .loc_0x140

.loc_0x48:
  cmpwi     r0, 0x2
  bne-      .loc_0x84
  lwz       r3, 0x3168(r13)
  li        r4, 0x2
  li        r5, 0x1
  bl        0x2CEC
  lwz       r3, 0x3168(r13)
  li        r4, 0x7
  li        r5, 0x1
  bl        0x2CDC
  lwz       r3, 0x3168(r13)
  li        r4, 0x8
  li        r5, 0x1
  bl        0x2CCC
  b         .loc_0x140

.loc_0x84:
  cmpwi     r0, 0x3
  bne-      .loc_0xA0
  lwz       r3, 0x3168(r13)
  li        r4, 0x3
  li        r5, 0x1
  bl        0x2CB0
  b         .loc_0x140

.loc_0xA0:
  cmpwi     r0, 0x4
  bne-      .loc_0xB8
  lwz       r3, 0x3168(r13)
  li        r4, 0x4
  bl        0x2C98
  b         .loc_0x140

.loc_0xB8:
  cmpwi     r0, 0x5
  bne-      .loc_0xD4
  lwz       r3, 0x3168(r13)
  li        r4, 0x5
  li        r5, 0x1
  bl        0x2C7C
  b         .loc_0x140

.loc_0xD4:
  cmpwi     r0, 0x6
  bne-      .loc_0xF0
  lwz       r3, 0x3168(r13)
  li        r4, 0x6
  li        r5, 0x1
  bl        0x2C60
  b         .loc_0x140

.loc_0xF0:
  cmpwi     r0, 0x7
  bne-      .loc_0x10C
  lwz       r3, 0x3168(r13)
  li        r4, 0x9
  li        r5, 0x1
  bl        0x2C44
  b         .loc_0x140

.loc_0x10C:
  cmpwi     r0, 0x8
  bne-      .loc_0x128
  lwz       r3, 0x3168(r13)
  li        r4, 0xA
  li        r5, 0x1
  bl        0x2C28
  b         .loc_0x140

.loc_0x128:
  cmpwi     r0, 0x9
  bne-      .loc_0x140
  lwz       r3, 0x3168(r13)
  li        r4, 0xB
  li        r5, 0x1
  bl        0x2C0C

.loc_0x140:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014D790
 * Size:	00013C
 */
void GenObjectBoss::birth(BirthInfo &)
{
/*
.loc_0x0:
  mflr      r0
  mr        r6, r3
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x18(r3)
  li        r3, 0
  cmpwi     r0, 0
  bne-      .loc_0x34
  lwz       r3, 0x3168(r13)
  addi      r5, r4, 0
  li        r4, 0
  bl        0x3C28
  b         .loc_0x12C

.loc_0x34:
  cmpwi     r0, 0x1
  bne-      .loc_0x50
  lwz       r3, 0x3168(r13)
  addi      r5, r4, 0
  li        r4, 0x1
  bl        0x3C0C
  b         .loc_0x12C

.loc_0x50:
  cmpwi     r0, 0x2
  bne-      .loc_0x6C
  lwz       r3, 0x3168(r13)
  addi      r5, r4, 0
  li        r4, 0x2
  bl        0x3BF0
  b         .loc_0x12C

.loc_0x6C:
  cmpwi     r0, 0x3
  bne-      .loc_0x88
  lwz       r3, 0x3168(r13)
  addi      r5, r4, 0
  li        r4, 0x3
  bl        0x3BD4
  b         .loc_0x12C

.loc_0x88:
  cmpwi     r0, 0x4
  bne-      .loc_0xA4
  lwz       r3, 0x3168(r13)
  addi      r5, r4, 0
  li        r4, 0x4
  bl        0x3BB8
  b         .loc_0x12C

.loc_0xA4:
  cmpwi     r0, 0x5
  bne-      .loc_0xC0
  lwz       r3, 0x3168(r13)
  addi      r5, r4, 0
  li        r4, 0x5
  bl        0x3B9C
  b         .loc_0x12C

.loc_0xC0:
  cmpwi     r0, 0x6
  bne-      .loc_0xDC
  lwz       r3, 0x3168(r13)
  addi      r5, r4, 0
  li        r4, 0x6
  bl        0x3B80
  b         .loc_0x12C

.loc_0xDC:
  cmpwi     r0, 0x7
  bne-      .loc_0xF8
  lwz       r3, 0x3168(r13)
  addi      r5, r4, 0
  li        r4, 0x7
  bl        0x3B64
  b         .loc_0x12C

.loc_0xF8:
  cmpwi     r0, 0x8
  bne-      .loc_0x114
  lwz       r3, 0x3168(r13)
  addi      r5, r4, 0
  li        r4, 0x8
  bl        0x3B48
  b         .loc_0x12C

.loc_0x114:
  cmpwi     r0, 0x9
  bne-      .loc_0x12C
  lwz       r3, 0x3168(r13)
  addi      r5, r4, 0
  li        r4, 0x9
  bl        0x3B2C

.loc_0x12C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}