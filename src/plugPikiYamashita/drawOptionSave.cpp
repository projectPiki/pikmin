#include "zen/DrawSave.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F5500
 * Size:	00004C
 */
zen::DrawOptionSave::DrawOptionSave()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x4
	  bl        -0x2EBC
	  addi      r3, r31, 0x50
	  bl        -0x684D4
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0
	  bl        0x2F4
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
 * Address:	801F554C
 * Size:	000188
 */
bool zen::DrawOptionSave::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  li        r30, 0
	  stw       r29, 0x1C(r1)
	  mr        r29, r3
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0x9
	  bgt-      .loc_0x168
	  lis       r3, 0x802E
	  addi      r3, r3, 0x7258
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  addi      r3, r29, 0x4
	  addi      r4, r31, 0
	  bl        -0x2B18
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x168
	  lwz       r0, 0x4(r29)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x8C
	  bge-      .loc_0x168
	  cmpwi     r0, 0x3
	  beq-      .loc_0x78
	  b         .loc_0x168

	.loc_0x78:
	  addi      r3, r29, 0
	  addi      r5, r31, 0
	  li        r4, 0x2
	  bl        0x254
	  b         .loc_0x168

	.loc_0x8C:
	  addi      r3, r29, 0
	  li        r4, 0x8
	  li        r5, 0
	  bl        0x240
	  b         .loc_0x168
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        0x14C
	  b         .loc_0x168
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r31, r3, 0x24
	  addi      r3, r31, 0
	  bl        -0x181278
	  mr        r3, r31
	  bl        -0x17EBEC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xE8
	  addi      r3, r29, 0
	  li        r4, 0x4
	  li        r5, 0
	  bl        0x1F8
	  b         .loc_0x168

	.loc_0xE8:
	  addi      r3, r29, 0
	  li        r4, 0x5
	  li        r5, 0
	  bl        0x1E4
	  b         .loc_0x168
	  addi      r3, r29, 0x4
	  addi      r4, r31, 0
	  bl        -0x2BCC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x168
	  lwz       r0, 0x4(r29)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x168
	  addi      r3, r29, 0
	  li        r4, 0x6
	  li        r5, 0
	  bl        0x1B0
	  b         .loc_0x168
	  addi      r3, r29, 0x4
	  addi      r4, r31, 0
	  bl        -0x2C00
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x168
	  lwz       r0, 0x4(r29)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x168
	  addi      r3, r29, 0
	  li        r4, 0x7
	  li        r5, 0
	  bl        0x17C
	  b         .loc_0x168
	  li        r30, 0x1

	.loc_0x168:
	  mr        r3, r30
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F56D4
 * Size:	00006C
 */
void zen::DrawOptionSave::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x54
	  cmplwi    r0, 0x8
	  beq-      .loc_0x54
	  addi      r3, r30, 0x4
	  addi      r4, r31, 0
	  bl        -0x23E4
	  lwz       r0, 0x0(r30)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x54
	  addi      r3, r30, 0x50
	  addi      r4, r31, 0
	  bl        -0x66784

	.loc_0x54:
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
 * Address:	801F5740
 * Size:	000094
 */
void zen::DrawOptionSave::modeCardCheck(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x80
	  addi      r3, r31, 0x50
	  bl        -0x67684
	  cmpwi     r3, 0x14
	  beq-      .loc_0x5C
	  bge-      .loc_0x3C
	  cmpwi     r3, 0x13
	  bge-      .loc_0x48
	  b         .loc_0x80

	.loc_0x3C:
	  cmpwi     r3, 0x16
	  bge-      .loc_0x80
	  b         .loc_0x70

	.loc_0x48:
	  addi      r3, r31, 0
	  li        r4, 0x7
	  li        r5, 0
	  bl        0x90
	  b         .loc_0x80

	.loc_0x5C:
	  addi      r3, r31, 0
	  li        r4, 0x9
	  li        r5, 0
	  bl        0x7C
	  b         .loc_0x80

	.loc_0x70:
	  addi      r3, r31, 0
	  li        r4, 0x3
	  li        r5, 0
	  bl        0x68

	.loc_0x80:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F57D4
 * Size:	000028
 */
void zen::DrawOptionSave::init()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  stwu      r1, -0x8(r1)
	  bl        0x3C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F57FC
 * Size:	000028
 */
void zen::DrawOptionSave::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  stwu      r1, -0x8(r1)
	  bl        .loc_0x28
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x28:
	*/
}

/*
 * --INFO--
 * Address:	801F5824
 * Size:	000120
 */
void zen::DrawOptionSave::setMode(u32, Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r5
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  stw       r4, 0x0(r3)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0x9
	  bgt-      .loc_0x108
	  lis       r3, 0x802E
	  addi      r3, r3, 0x7280
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  addi      r3, r30, 0x4
	  bl        -0x2EC8
	  b         .loc_0x108
	  addi      r3, r30, 0x4
	  bl        -0x2EB0
	  b         .loc_0x108
	  addi      r3, r30, 0x50
	  bl        -0x67B5C
	  cmplwi    r31, 0
	  beq-      .loc_0x108
	  addi      r3, r30, 0x50
	  addi      r4, r31, 0
	  bl        -0x677BC
	  cmpwi     r3, 0x14
	  beq-      .loc_0xB0
	  bge-      .loc_0x90
	  cmpwi     r3, 0x13
	  bge-      .loc_0x9C
	  b         .loc_0x108

	.loc_0x90:
	  cmpwi     r3, 0x16
	  bge-      .loc_0x108
	  b         .loc_0xC4

	.loc_0x9C:
	  addi      r3, r30, 0
	  li        r4, 0x7
	  li        r5, 0
	  bl        .loc_0x0
	  b         .loc_0x108

	.loc_0xB0:
	  addi      r3, r30, 0
	  li        r4, 0x9
	  li        r5, 0
	  bl        .loc_0x0
	  b         .loc_0x108

	.loc_0xC4:
	  addi      r3, r30, 0
	  li        r4, 0x3
	  li        r5, 0
	  bl        .loc_0x0
	  b         .loc_0x108
	  li        r3, 0x128
	  bl        -0x15058C
	  b         .loc_0x108
	  li        r3, 0x12A
	  bl        -0x150598
	  addi      r3, r30, 0x4
	  bl        -0x2EB4
	  b         .loc_0x108
	  li        r3, 0x129
	  bl        -0x1505AC
	  addi      r3, r30, 0x4
	  bl        -0x2F10

	.loc_0x108:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
