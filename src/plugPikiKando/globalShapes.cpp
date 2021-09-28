

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
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007F2B4
 * Size:	000020
 */
void GlobalShape::exitCourse()
{
/*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x2F50(r13)
  stw       r0, 0x2F54(r13)
  stw       r0, 0x2F58(r13)
  stw       r0, 0x2F5C(r13)
  stw       r0, 0x2F60(r13)
  stw       r0, 0x2F64(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	8007F2D4
 * Size:	0000E4
 */
void GlobalShape::init()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802B
  stw       r0, 0x4(r1)
  lis       r3, 0x803A
  li        r5, 0x1
  stwu      r1, -0x10(r1)
  stw       r31, 0xC(r1)
  subi      r31, r3, 0x2848
  addi      r3, r31, 0
  stw       r30, 0x8(r1)
  subi      r30, r4, 0x2328
  addi      r4, r30, 0x20
  bl        -0x2C5F4
  stw       r3, 0x2F60(r13)
  addi      r3, r31, 0
  addi      r4, r30, 0x3C
  li        r5, 0x1
  bl        -0x2C608
  stw       r3, 0x2F64(r13)
  addi      r3, r31, 0
  addi      r4, r30, 0x58
  li        r5, 0x1
  bl        -0x2C61C
  addi      r3, r31, 0
  addi      r4, r30, 0x58
  li        r5, 0x1
  bl        -0x2C62C
  addi      r3, r31, 0
  addi      r4, r30, 0x58
  li        r5, 0x1
  bl        -0x2C63C
  addi      r3, r31, 0
  addi      r4, r30, 0x70
  li        r5, 0x1
  bl        -0x2C64C
  addi      r3, r31, 0
  addi      r4, r30, 0x88
  li        r5, 0x1
  bl        -0x2C65C
  addi      r3, r31, 0
  addi      r4, r30, 0x58
  li        r5, 0x1
  bl        -0x2C66C
  addi      r3, r31, 0
  addi      r4, r30, 0x58
  li        r5, 0x1
  bl        -0x2C67C
  addi      r3, r31, 0
  addi      r4, r30, 0x58
  li        r5, 0x1
  bl        -0x2C68C
  lwz       r0, 0x14(r1)
  lwz       r31, 0xC(r1)
  lwz       r30, 0x8(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}