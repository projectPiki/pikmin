

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
 * Address:	........
 * Size:	000060
 */
void GenObjectNavi::GenObjectNavi()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800F8130
 * Size:	000070
 */
void makeObjectNavi()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x18
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  bl        -0xB1140
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x58
  lis       r4, 0x802C
  lis       r5, 0x802C
  subi      r6, r4, 0x30
  lis       r4, 0x6E61
  subi      r5, r5, 0x3C
  addi      r4, r4, 0x7669
  bl        -0x1D4B8
  lis       r3, 0x802C
  subi      r0, r3, 0x5490
  lis       r3, 0x802C
  stw       r0, 0x4(r31)
  addi      r0, r3, 0x60
  stw       r0, 0x4(r31)

.loc_0x58:
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
 * Address:	800F81A0
 * Size:	00008C
 */
void GenObjectNavi::initialise()
{
/*
.loc_0x0:
  lwz       r7, 0x3074(r13)
  lwz       r5, 0x0(r7)
  lwz       r0, 0x4(r7)
  cmpw      r5, r0
  bgelr-    
  lis       r4, 0x6E61
  lwz       r3, 0x8(r7)
  addi      r4, r4, 0x7669
  rlwinm    r0,r5,4,0,27
  stwx      r4, r3, r0
  lis       r6, 0x8010
  lis       r4, 0x802C
  lwz       r0, 0x0(r7)
  lis       r3, 0x7630
  lwz       r5, 0x8(r7)
  subi      r6, r6, 0x7ED0
  rlwinm    r0,r0,4,0,27
  add       r5, r5, r0
  stw       r6, 0x4(r5)
  subi      r5, r4, 0x1C
  addi      r4, r3, 0x2E30
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
 * Address:	800F822C
 * Size:	000004
 */
void GenObjectNavi::doRead(RandomAccessStream &)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	800F8230
 * Size:	0000B8
 */
void GenObjectNavi::birth(BirthInfo &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r4
  lwz       r3, 0x3120(r13)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x78(r12)
  mtlr      r12
  blrl      
  mr.       r31, r3
  beq-      .loc_0x9C
  lwz       r12, 0x0(r31)
  addi      r3, r31, 0
  addi      r4, r30, 0
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0xC(r30)
  mr        r3, r31
  lwz       r0, 0x10(r30)
  stw       r4, 0x88(r31)
  stw       r0, 0x8C(r31)
  lwz       r0, 0x14(r30)
  stw       r0, 0x90(r31)
  lfs       f0, 0x8C(r31)
  stfs      f0, 0xA0(r31)
  bl        0x1FE8
  lwz       r0, 0x24(r30)
  stw       r0, 0x64(r31)
  lwz       r3, 0x3120(r13)
  bl        0x1F114
  lwz       r0, 0x2E8(r3)
  lis       r3, 0x803A
  subi      r3, r3, 0x24E0
  stw       r0, 0x2E8(r31)
  li        r0, 0x1
  stw       r0, 0x230(r3)

.loc_0x9C:
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}