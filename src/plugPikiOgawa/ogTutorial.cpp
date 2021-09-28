

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
 * Address:	80182B94
 * Size:	000080
 */
void zen::ogScrTutorialMgr::ogScrTutorialMgr()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  subi      r3, r4, 0x5A10
  bl        -0x13BBB0
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x3C
  lis       r4, 0x802D
  addi      r4, r4, 0x3128
  bl        0x99D8

.loc_0x3C:
  stw       r31, 0x0(r30)
  lis       r3, 0x802D
  addi      r4, r3, 0x3DEC
  lwz       r3, 0x0(r30)
  bl        0x997C
  lwz       r3, 0x0(r30)
  li        r4, 0x1
  li        r0, -0x1
  stb       r4, 0x4E0(r3)
  mr        r3, r30
  stw       r0, 0x4(r30)
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
 * Address:	80182C14
 * Size:	0000BC
 */
void zen::ogScrTutorialMgr::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lwz       r3, 0x4(r3)
  cmpwi     r3, -0x1
  bne-      .loc_0x24
  b         .loc_0xA8

.loc_0x24:
  lwz       r3, 0x0(r31)
  bl        0x9D90
  cmpwi     r3, 0x2
  beq-      .loc_0x84
  bge-      .loc_0x50
  cmpwi     r3, 0
  beq-      .loc_0x6C
  bge-      .loc_0x78
  cmpwi     r3, -0x1
  bge-      .loc_0x60
  b         .loc_0xA4

.loc_0x50:
  cmpwi     r3, 0x4
  beq-      .loc_0x9C
  bge-      .loc_0xA4
  b         .loc_0x90

.loc_0x60:
  li        r0, -0x1
  stw       r0, 0x4(r31)
  b         .loc_0xA4

.loc_0x6C:
  li        r0, 0
  stw       r0, 0x4(r31)
  b         .loc_0xA4

.loc_0x78:
  li        r0, 0x1
  stw       r0, 0x4(r31)
  b         .loc_0xA4

.loc_0x84:
  li        r0, 0x2
  stw       r0, 0x4(r31)
  b         .loc_0xA4

.loc_0x90:
  li        r0, 0x3
  stw       r0, 0x4(r31)
  b         .loc_0xA4

.loc_0x9C:
  li        r0, 0x4
  stw       r0, 0x4(r31)

.loc_0xA4:
  lwz       r3, 0x4(r31)

.loc_0xA8:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80182CD0
 * Size:	000030
 */
void zen::ogScrTutorialMgr::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x4(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0x20
  lwz       r3, 0x0(r3)
  bl        0xA25C

.loc_0x20:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80182D00
 * Size:	0000E0
 */
void zen::ogScrTutorialMgr::start(zen::ogScrTutorialMgr::EnumTutorial)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r25, 0x14(r1)
  addi      r25, r3, 0
  addi      r26, r4, 0
  li        r31, 0x1
  li        r30, 0xA
  li        r29, 0x1E
  li        r28, 0x1
  li        r27, 0x4D
  lwz       r0, 0x2F6C(r13)
  cmplwi    r0, 0
  beq-      .loc_0x7C
  mr        r3, r0
  bl        -0x10218C
  mr        r0, r3
  lwz       r3, 0x2F6C(r13)
  mr        r31, r0
  bl        -0x1020DC
  mr        r0, r3
  lwz       r3, 0x2F6C(r13)
  mr        r30, r0
  bl        -0x1020F4
  sub       r29, r3, r30
  lwz       r3, 0x2F6C(r13)
  bl        -0x1021A4
  sub       r28, r3, r31
  lwz       r3, 0x2F6C(r13)
  bl        -0x101604
  mr        r27, r3

.loc_0x7C:
  li        r3, 0x1
  addi      r4, r31, 0
  bl        -0x2C38
  li        r3, 0x2
  addi      r4, r30, 0
  bl        -0x2C44
  li        r3, 0x3
  addi      r4, r29, 0
  bl        -0x2C50
  li        r3, 0x4
  addi      r4, r28, 0
  bl        -0x2C5C
  li        r3, 0x5
  addi      r4, r27, 0
  bl        -0x2C68
  lwz       r3, 0x0(r25)
  mr        r4, r26
  bl        0x8EF4
  li        r0, 0x1
  stw       r0, 0x4(r25)
  lmw       r25, 0x14(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void zen::ogScrTutorialMgr::nextPage()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void zen::ogScrTutorialMgr::backPage()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void zen::ogScrTutorialMgr::setCursorXY(P2DTextBox *)
{
	// UNUSED FUNCTION
}