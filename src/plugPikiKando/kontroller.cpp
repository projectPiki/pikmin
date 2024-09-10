#include "types.h"

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
 * Address:	80115B8C
 * Size:	0000CC
 */
Kontroller::Kontroller(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r5, 0x738C
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  lis       r3, 0x8022
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802C
	  stw       r0, 0x0(r28)
	  addi      r31, r3, 0x2D9C
	  addi      r3, r28, 0
	  stw       r30, 0x10(r28)
	  addi      r4, r31, 0
	  stw       r30, 0xC(r28)
	  stw       r30, 0x8(r28)
	  bl        -0xF0D14
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r28)
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        -0xD54C4
	  lis       r3, 0x8023
	  subi      r0, r3, 0x714C
	  stw       r0, 0x0(r28)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0xD5268
	  lis       r3, 0x802C
	  addi      r0, r3, 0x2E24
	  stw       r0, 0x0(r28)
	  mr        r3, r28
	  stw       r30, 0x50(r28)
	  stw       r30, 0x54(r28)
	  stw       r30, 0x58(r28)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115C58
 * Size:	000050
 */
void Kontroller::save(RamStream*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  stw       r5, 0x54(r3)
	  mr        r3, r4
	  stw       r4, 0x58(r31)
	  li        r4, 0
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stw       r0, 0x50(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115CA8
 * Size:	000050
 */
void Kontroller::load(RamStream*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  stw       r5, 0x54(r3)
	  mr        r3, r4
	  stw       r4, 0x58(r31)
	  li        r4, 0
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x2
	  stw       r0, 0x50(r31)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void Kontroller::stop()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80115CF8
 * Size:	000168
 */
void Kontroller::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r0, 0x50(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x84
	  bge-      .loc_0x34
	  cmpwi     r0, 0
	  bge-      .loc_0x148
	  b         .loc_0x150

	.loc_0x34:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x150
	  mr        r3, r30
	  lwz       r4, 0x58(r30)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x54(r30)
	  subic.    r0, r3, 0x1
	  stw       r0, 0x54(r30)
	  bgt-      .loc_0x74
	  li        r0, 0
	  stw       r0, 0x50(r30)
	  stw       r0, 0x58(r30)
	  stw       r0, 0x54(r30)

	.loc_0x74:
	  mr        r3, r30
	  lwz       r4, 0x5C(r30)
	  bl        -0xD53A0
	  b         .loc_0x150

	.loc_0x84:
	  mr        r3, r30
	  bl        -0xD5310
	  mr        r3, r30
	  lwz       r4, 0x58(r30)
	  bl        0xDC
	  lwz       r3, 0x54(r30)
	  subic.    r0, r3, 0x1
	  stw       r0, 0x54(r30)
	  bgt-      .loc_0x150
	  lwz       r3, 0x58(r30)
	  lwz       r12, 0x4(r3)
	  lwz       r31, 0x8(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  bl        0xE0E28
	  li        r0, 0x2
	  mtctr     r0
	  li        r3, 0

	.loc_0xD8:
	  addi      r3, r3, 0x40
	  bdnz+     .loc_0xD8
	  lwz       r3, 0x58(r30)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x58(r30)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x58(r30)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x58(r30)
	  mr        r6, r3
	  lwz       r3, 0x2F88(r13)
	  lwz       r5, 0x8(r4)
	  li        r4, 0x1
	  bl        -0x91908
	  li        r0, 0
	  stw       r0, 0x50(r30)
	  stw       r0, 0x58(r30)
	  stw       r0, 0x54(r30)
	  b         .loc_0x150

	.loc_0x148:
	  mr        r3, r30
	  bl        -0xD53D4

	.loc_0x150:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115E60
 * Size:	000008
 */
void Kontroller::getSaveSize(int)
{
	/*
	.loc_0x0:
	  mulli     r3, r3, 0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80115E68
 * Size:	00010C
 */
void Kontroller::write(RandomAccessStream&)
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
	  lwz       r4, 0x20(r30)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x45(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x46(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x47(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x48(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x49(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x4A(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x4B(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lbz       r4, 0x4C(r30)
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
 * Address:	80115F74
 * Size:	00010C
 */
void Kontroller::read(RandomAccessStream&)
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
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x5C(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x45(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x46(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x47(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x48(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x49(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x4A(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x4B(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x4C(r30)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
