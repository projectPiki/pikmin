

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
 * Address:	80043E5C
 * Size:	000038
 */
void ID32::ID32()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x6E6F
  stw       r0, 0x4(r1)
  addi      r4, r4, 0x6E65
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        0x4C
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80043E94
 * Size:	000030
 */
void ID32::ID32(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        .loc_0x30
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr       

.loc_0x30:
*/
}

/*
 * --INFO--
 * Address:	80043EC4
 * Size:	000024
 */
void ID32::setID(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  stw       r4, 0x0(r3)
  bl        0xE0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80043EE8
 * Size:	0000A8
 */
void ID32::match(unsigned long, char)
{
/*
.loc_0x0:
  stwu      r1, -0x18(r1)
  rlwinm    r5,r5,0,24,31
  stw       r4, 0xC(r1)
  addi      r4, r1, 0xC
  lbz       r6, 0xC(r1)
  cmplw     r5, r6
  beq-      .loc_0x30
  lbz       r0, 0x0(r3)
  cmplw     r6, r0
  beq-      .loc_0x30
  li        r3, 0
  b         .loc_0xA0

.loc_0x30:
  lbzu      r6, 0x1(r4)
  addi      r3, r3, 0x1
  cmplw     r5, r6
  beq-      .loc_0x54
  lbz       r0, 0x0(r3)
  cmplw     r6, r0
  beq-      .loc_0x54
  li        r3, 0
  b         .loc_0xA0

.loc_0x54:
  lbzu      r6, 0x1(r4)
  addi      r3, r3, 0x1
  cmplw     r5, r6
  beq-      .loc_0x78
  lbz       r0, 0x0(r3)
  cmplw     r6, r0
  beq-      .loc_0x78
  li        r3, 0
  b         .loc_0xA0

.loc_0x78:
  lbz       r6, 0x1(r4)
  addi      r3, r3, 0x1
  cmplw     r5, r6
  beq-      .loc_0x9C
  lbz       r0, 0x0(r3)
  cmplw     r6, r0
  beq-      .loc_0x9C
  li        r3, 0
  b         .loc_0xA0

.loc_0x9C:
  li        r3, 0x1

.loc_0xA0:
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	80043F90
 * Size:	000024
 */
void ID32::updateID()
{
/*
.loc_0x0:
  lbz       r0, 0x4(r3)
  stb       r0, 0x0(r3)
  lbz       r0, 0x5(r3)
  stb       r0, 0x1(r3)
  lbz       r0, 0x6(r3)
  stb       r0, 0x2(r3)
  lbz       r0, 0x7(r3)
  stb       r0, 0x3(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80043FB4
 * Size:	00002C
 */
void ID32::updateString()
{
/*
.loc_0x0:
  lbz       r4, 0x0(r3)
  li        r0, 0
  stb       r4, 0x4(r3)
  lbz       r4, 0x1(r3)
  stb       r4, 0x5(r3)
  lbz       r4, 0x2(r3)
  stb       r4, 0x6(r3)
  lbz       r4, 0x3(r3)
  stb       r4, 0x7(r3)
  stb       r0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void ID32::operator= (unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80043FE0
 * Size:	000014
 */
void ID32::operator== (unsigned long)
{
/*
.loc_0x0:
  lwz       r0, 0x0(r3)
  sub       r0, r4, r0
  cntlzw    r0, r0
  rlwinm    r3,r0,27,5,31
  blr
*/
}

/*
 * --INFO--
 * Address:	80043FF4
 * Size:	000014
 */
void ID32::operator!= (unsigned long)
{
/*
.loc_0x0:
  lwz       r0, 0x0(r3)
  sub       r3, r4, r0
  subic     r0, r3, 0x1
  subfe     r3, r0, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	80044008
 * Size:	000094
 */
void ID32::write(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x4(r31)
  lbz       r4, 0x3(r30)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x2(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x1(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x0(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8004409C
 * Size:	0000BC
 */
void ID32::read(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r4, 0
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x3(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x2(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x1(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x0(r30)
  li        r0, 0
  lbz       r3, 0x0(r30)
  stb       r3, 0x4(r30)
  lbz       r3, 0x1(r30)
  stb       r3, 0x5(r30)
  lbz       r3, 0x2(r30)
  stb       r3, 0x6(r30)
  lbz       r3, 0x3(r30)
  stb       r3, 0x7(r30)
  stb       r0, 0x8(r30)
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
 * Address:	80044158
 * Size:	000004
 */
void ID32::print()
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	8004415C
 * Size:	000038
 */
void ID32::sprint(char *)
{
/*
.loc_0x0:
  lwz       r5, 0x0(r3)
  li        r0, 0
  rlwinm    r5,r5,8,24,31
  stb       r5, 0x0(r4)
  lwz       r5, 0x0(r3)
  rlwinm    r5,r5,16,24,31
  stb       r5, 0x1(r4)
  lwz       r5, 0x0(r3)
  rlwinm    r5,r5,24,24,31
  stb       r5, 0x2(r4)
  lwz       r3, 0x0(r3)
  stb       r3, 0x3(r4)
  stb       r0, 0x4(r4)
  blr
*/
}