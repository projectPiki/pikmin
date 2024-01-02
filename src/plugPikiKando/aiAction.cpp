#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C3AE4
 * Size:	000240
 */
void Action::procMsg(Msg*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  stw       r30, 0x20(r1)
	  mr        r30, r3
	  lwz       r5, 0xC(r3)
	  lwz       r0, 0xC8(r5)
	  rlwinm.   r0,r0,0,20,20
	  bne-      .loc_0x228
	  lwz       r0, 0x0(r31)
	  cmplwi    r0, 0xA
	  bgt-      .loc_0x1AC
	  lis       r3, 0x802B
	  addi      r3, r3, 0x7EFC
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1AC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r5, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x1AC:
	  lha       r4, 0x8(r30)
	  cmpwi     r4, -0x1
	  beq-      .loc_0x228
	  lha       r0, 0xA(r30)
	  cmpw      r4, r0
	  bge-      .loc_0x228
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r4,3,0,28
	  lwzx      r30, r3, r0
	  cmplwi    r30, 0
	  beq-      .loc_0x228
	  lwz       r4, 0xC(r30)
	  lwz       r0, 0xC8(r4)
	  rlwinm.   r0,r0,0,20,20
	  bne-      .loc_0x228
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  bl        -0x1C3FC
	  lha       r4, 0x8(r30)
	  cmpwi     r4, -0x1
	  beq-      .loc_0x228
	  lha       r0, 0xA(r30)
	  cmpw      r4, r0
	  bge-      .loc_0x228
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r4,3,0,28
	  lwzx      r3, r3, r0
	  cmplwi    r3, 0
	  beq-      .loc_0x228
	  mr        r4, r31
	  bl        .loc_0x0

	.loc_0x228:
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
 * Address:	800C3D24
 * Size:	0000AC
 */
void Action::Child::initialise(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x0(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  lwz       r3, 0xC(r3)
	  li        r5, 0xA
	  li        r0, 0x2
	  stb       r5, 0x400(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0x3C:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x58
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x58:
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x98

	.loc_0x7C:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0x98:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C3DD0
 * Size:	000038
 */
Action::Action(Piki*, bool)
{
	/*
	.loc_0x0:
	  lis       r5, 0x802C
	  subi      r0, r5, 0x7E08
	  lis       r5, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r5, 0x7E6C
	  stw       r0, 0x0(r3)
	  li        r5, 0
	  subi      r0, r13, 0x4380
	  stw       r4, 0xC(r3)
	  stw       r5, 0x4(r3)
	  sth       r5, 0xA(r3)
	  sth       r5, 0x8(r3)
	  stw       r0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C3E08
 * Size:	000078
 */
Action::~Action()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7E6C
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x4(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  lis       r4, 0x800C
	  addi      r4, r4, 0x3E80
	  bl        0x150BAC

	.loc_0x44:
	  li        r3, 0
	  extsh.    r0, r31
	  stw       r3, 0x4(r30)
	  ble-      .loc_0x5C
	  mr        r3, r30
	  bl        -0x7CCB4

	.loc_0x5C:
	  mr        r3, r30
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
 * Address:	800C3E80
 * Size:	000080
 */
Action::Child::~Child()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x64
	  lwz       r3, 0x0(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x44
	  beq-      .loc_0x44
	  lwz       r12, 0x0(r3)
	  li        r4, 0x1
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl

	.loc_0x44:
	  lwz       r3, 0x4(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  bl        -0x7CD24

	.loc_0x54:
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x7CD34

	.loc_0x64:
	  mr        r3, r30
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
 * Address:	800C3F00
 * Size:	00000C
 */
void Action::init(Creature*)
{
	// Generated from sth r0, 0x8(r3)
	_08 = 0;
}

/*
 * --INFO--
 * Address:	800C3F0C
 * Size:	000008
 */
u32 Action::exec() { return 0x2; }

/*
 * --INFO--
 * Address:	800C3F14
 * Size:	0000E0
 */
void AndAction::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  sth       r0, 0x8(r3)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r31, r3, r0
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  lwz       r3, 0xC(r3)
	  li        r4, 0xA
	  li        r0, 0x2
	  stb       r4, 0x400(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0x60:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x80
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x80:
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xA4
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xC0

	.loc_0xA4:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0xC0:
	  stw       r30, 0x14(r29)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C3FF4
 * Size:	00014C
 */
void AndAction::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0x2
	  beq-      .loc_0x50
	  bge-      .loc_0x134
	  cmpwi     r3, 0x1
	  bge-      .loc_0x12C
	  b         .loc_0x134

	.loc_0x50:
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  lha       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  sth       r0, 0x8(r31)
	  lha       r4, 0x8(r31)
	  lha       r0, 0xA(r31)
	  cmpw      r4, r0
	  blt-      .loc_0x94
	  li        r3, 0x2
	  b         .loc_0x138

	.loc_0x94:
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,3,0,28
	  lwz       r4, 0x14(r31)
	  add       r31, r3, r0
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xCC
	  lwz       r3, 0xC(r3)
	  li        r5, 0xA
	  li        r0, 0x2
	  stb       r5, 0x400(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0xCC:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0xE8:
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x10C
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x134

	.loc_0x10C:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x134
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x134

	.loc_0x12C:
	  li        r3, 0x1
	  b         .loc_0x138

	.loc_0x134:
	  li        r3, 0

	.loc_0x138:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C4140
 * Size:	0000E0
 */
void OrAction::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  sth       r0, 0x8(r3)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r31, r3, r0
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  lwz       r3, 0xC(r3)
	  li        r4, 0xA
	  li        r0, 0x2
	  stb       r4, 0x400(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0x60:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x80
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x80:
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xA4
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xC0

	.loc_0xA4:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0xC0:
	  stw       r30, 0x14(r29)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C4220
 * Size:	000150
 */
void OrAction::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0x2
	  beq-      .loc_0x50
	  bge-      .loc_0x138
	  cmpwi     r3, 0x1
	  bge-      .loc_0x58
	  b         .loc_0x138

	.loc_0x50:
	  li        r3, 0x2
	  b         .loc_0x13C

	.loc_0x58:
	  lha       r0, 0x8(r31)
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  lha       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  sth       r0, 0x8(r31)
	  lha       r4, 0x8(r31)
	  lha       r0, 0xA(r31)
	  cmpw      r4, r0
	  blt-      .loc_0x9C
	  li        r3, 0x1
	  b         .loc_0x13C

	.loc_0x9C:
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,3,0,28
	  lwz       r4, 0x14(r31)
	  add       r31, r3, r0
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xD4
	  lwz       r3, 0xC(r3)
	  li        r5, 0xA
	  li        r0, 0x2
	  stb       r5, 0x400(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0xD4:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xF0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0xF0:
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x114
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x130

	.loc_0x114:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x130
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0x130:
	  li        r3, 0x1
	  b         .loc_0x13C

	.loc_0x138:
	  li        r3, 0

	.loc_0x13C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C4370
 * Size:	000124
 */
void Action::setChildren(int, ...)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stw       r31, 0x94(r1)
	  stw       r30, 0x90(r1)
	  stw       r29, 0x8C(r1)
	  stw       r28, 0x88(r1)
	  bne-      cr1, .loc_0x40
	  stfd      f1, 0x28(r1)
	  stfd      f2, 0x30(r1)
	  stfd      f3, 0x38(r1)
	  stfd      f4, 0x40(r1)
	  stfd      f5, 0x48(r1)
	  stfd      f6, 0x50(r1)
	  stfd      f7, 0x58(r1)
	  stfd      f8, 0x60(r1)

	.loc_0x40:
	  stw       r3, 0x8(r1)
	  addi      r31, r4, 0
	  addi      r30, r3, 0
	  stw       r4, 0xC(r1)
	  rlwinm    r4,r4,3,0,28
	  addi      r3, r4, 0x8
	  stw       r5, 0x10(r1)
	  stw       r6, 0x14(r1)
	  stw       r7, 0x18(r1)
	  stw       r8, 0x1C(r1)
	  stw       r9, 0x20(r1)
	  stw       r10, 0x24(r1)
	  bl        -0x7D3DC
	  lis       r4, 0x800C
	  lis       r5, 0x800C
	  addi      r4, r4, 0x4494
	  addi      r5, r5, 0x3E80
	  addi      r7, r31, 0
	  li        r6, 0x8
	  bl        0x15082C
	  stw       r3, 0x4(r30)
	  extsh     r0, r31
	  lis       r4, 0x200
	  sth       r0, 0xA(r30)
	  addi      r3, r1, 0xA0
	  addi      r0, r1, 0x8
	  stw       r4, 0x78(r1)
	  li        r28, 0
	  li        r29, 0
	  stw       r3, 0x7C(r1)
	  stw       r0, 0x80(r1)
	  b         .loc_0xFC

	.loc_0xC0:
	  addi      r3, r1, 0x78
	  li        r4, 0x1
	  bl        0x150438
	  lwz       r0, 0x0(r3)
	  addi      r3, r1, 0x78
	  lwz       r5, 0x4(r30)
	  li        r4, 0x1
	  stwx      r0, r5, r29
	  bl        0x150420
	  lwz       r4, 0x0(r3)
	  addi      r0, r29, 0x4
	  lwz       r3, 0x4(r30)
	  addi      r29, r29, 0x8
	  addi      r28, r28, 0x1
	  stwx      r4, r3, r0

	.loc_0xFC:
	  cmpw      r28, r31
	  blt+      .loc_0xC0
	  lwz       r0, 0x9C(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  lwz       r29, 0x8C(r1)
	  lwz       r28, 0x88(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C4494
 * Size:	000010
 */
Action::Child::Child()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  stw       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C44A4
 * Size:	000070
 */
void Action::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  rlwinm    r31,r30,3,0,28
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  b         .loc_0x48

	.loc_0x28:
	  lwz       r3, 0x4(r29)
	  lwzx      r3, r3, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x8
	  addi      r30, r30, 0x1

	.loc_0x48:
	  lha       r0, 0xA(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x28
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C4514
 * Size:	0000DC
 */
void TopAction::MotionListener::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x20
	  b         .loc_0xC8

	.loc_0x20:
	  lwz       r4, 0x4(r3)
	  li        r0, 0
	  stb       r0, 0x1A(r4)
	  lwz       r4, 0x4(r3)
	  lha       r0, 0x8(r4)
	  lwz       r3, 0x4(r4)
	  rlwinm    r0,r0,3,0,28
	  lwz       r4, 0x20(r4)
	  add       r31, r3, r0
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x6C
	  lwz       r3, 0xC(r3)
	  li        r5, 0xA
	  li        r0, 0x2
	  stb       r5, 0x400(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0x6C:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x88
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x88:
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xAC
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xC8

	.loc_0xAC:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xC8
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0xC8:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C45F0
 * Size:	00064C
 */
TopAction::TopAction(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802C
	  stw       r0, 0x4(r1)
	  lis       r6, 0x802B
	  stwu      r1, -0x178(r1)
	  stmw      r14, 0x130(r1)
	  addi      r31, r4, 0
	  li        r29, 0
	  stw       r3, 0xE8(r1)
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7E08
	  lwz       r30, 0xE8(r1)
	  lis       r3, 0x802B
	  addi      r4, r3, 0x7FD4
	  stw       r0, 0x0(r30)
	  subi      r0, r5, 0x7E6C
	  subi      r5, r13, 0x4380
	  stw       r0, 0x0(r30)
	  addi      r0, r6, 0x7EB0
	  addi      r3, r30, 0x30
	  stw       r31, 0xC(r30)
	  stw       r29, 0x4(r30)
	  sth       r29, 0xA(r30)
	  sth       r29, 0x8(r30)
	  stw       r5, 0x10(r30)
	  stw       r0, 0x128(r1)
	  stw       r4, 0x0(r30)
	  bl        0xEE0
	  lwz       r3, 0x128(r1)
	  stb       r29, 0x18(r30)
	  addi      r4, r3, 0xA4
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x3DF38
	  li        r3, 0x8
	  bl        -0x7D674
	  cmplwi    r3, 0
	  beq-      .loc_0xB0
	  lis       r4, 0x802B
	  subi      r0, r4, 0x246C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x7F80
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)

	.loc_0xB0:
	  lwz       r6, 0xE8(r1)
	  li        r5, 0
	  li        r4, -0x1
	  stw       r3, 0x14(r6)
	  lwz       r3, 0x128(r1)
	  stw       r5, 0x20(r6)
	  addi      r0, r3, 0xB0
	  stw       r4, 0x24(r6)
	  li        r3, 0x28
	  lfs       f0, -0x6A60(r2)
	  stfs      f0, 0x2C(r6)
	  stw       r5, 0x28(r6)
	  stb       r5, 0x19(r6)
	  stb       r5, 0x1A(r6)
	  stw       r0, 0x10(r6)
	  bl        -0x7D6D8
	  stw       r3, 0x124(r1)
	  lwz       r0, 0x124(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x10C
	  lwz       r3, 0x124(r1)
	  mr        r4, r31
	  bl        -0x39F0

	.loc_0x10C:
	  li        r3, 0x2C
	  bl        -0x7D6FC
	  stw       r3, 0x120(r1)
	  lwz       r0, 0x120(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x130
	  lwz       r3, 0x120(r1)
	  mr        r4, r31
	  bl        -0x1AC4

	.loc_0x130:
	  li        r3, 0x30
	  bl        -0x7D720
	  stw       r3, 0x11C(r1)
	  lwz       r0, 0x11C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  lwz       r3, 0x11C(r1)
	  mr        r4, r31
	  bl        -0xBF18

	.loc_0x154:
	  li        r3, 0x1C
	  bl        -0x7D744
	  stw       r3, 0x118(r1)
	  lwz       r0, 0x118(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x178
	  lwz       r3, 0x118(r1)
	  mr        r4, r31
	  bl        -0xF0DC

	.loc_0x178:
	  li        r3, 0x24
	  bl        -0x7D768
	  stw       r3, 0x114(r1)
	  lwz       r0, 0x114(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x19C
	  lwz       r3, 0x114(r1)
	  mr        r4, r31
	  bl        -0x9820

	.loc_0x19C:
	  li        r3, 0x1C
	  bl        -0x7D78C
	  stw       r3, 0x110(r1)
	  lwz       r0, 0x110(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C0
	  lwz       r3, 0x110(r1)
	  mr        r4, r31
	  bl        -0x7448

	.loc_0x1C0:
	  li        r3, 0x24
	  bl        -0x7D7B0
	  stw       r3, 0x10C(r1)
	  lwz       r0, 0x10C(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x1E4
	  lwz       r3, 0x10C(r1)
	  mr        r4, r31
	  bl        -0x4884

	.loc_0x1E4:
	  li        r3, 0x34
	  bl        -0x7D7D4
	  stw       r3, 0x108(r1)
	  lwz       r0, 0x108(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x208
	  lwz       r3, 0x108(r1)
	  mr        r4, r31
	  bl        -0xABF0

	.loc_0x208:
	  li        r3, 0x2C
	  bl        -0x7D7F8
	  stw       r3, 0x104(r1)
	  lwz       r0, 0x104(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x22C
	  lwz       r3, 0x104(r1)
	  mr        r4, r31
	  bl        -0x1C530

	.loc_0x22C:
	  li        r3, 0x28
	  bl        -0x7D81C
	  stw       r3, 0x100(r1)
	  lwz       r0, 0x100(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x250
	  lwz       r3, 0x100(r1)
	  mr        r4, r31
	  bl        -0x26D0

	.loc_0x250:
	  li        r3, 0x4C
	  bl        -0x7D840
	  stw       r3, 0xFC(r1)
	  lwz       r0, 0xFC(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x274
	  lwz       r3, 0xFC(r1)
	  mr        r4, r31
	  bl        -0x932C

	.loc_0x274:
	  li        r3, 0x1C
	  bl        -0x7D864
	  stw       r3, 0xF8(r1)
	  lwz       r0, 0xF8(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x298
	  lwz       r3, 0xF8(r1)
	  mr        r4, r31
	  bl        -0x7214

	.loc_0x298:
	  li        r3, 0x1C
	  bl        -0x7D888
	  stw       r3, 0xF4(r1)
	  lwz       r0, 0xF4(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2BC
	  lwz       r3, 0xF4(r1)
	  mr        r4, r31
	  bl        -0x7DAC

	.loc_0x2BC:
	  li        r3, 0x20
	  bl        -0x7D8AC
	  stw       r3, 0xF0(r1)
	  lwz       r0, 0xF0(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x2E0
	  lwz       r3, 0xF0(r1)
	  mr        r4, r31
	  bl        -0xD120

	.loc_0x2E0:
	  li        r3, 0x88
	  bl        -0x7D8D0
	  mr.       r14, r3
	  beq-      .loc_0x300
	  addi      r3, r14, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0xEE40

	.loc_0x300:
	  li        r3, 0x50
	  bl        -0x7D8F0
	  mr.       r15, r3
	  beq-      .loc_0x320
	  addi      r3, r15, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0xA30C

	.loc_0x320:
	  li        r3, 0x24
	  bl        -0x7D910
	  mr.       r16, r3
	  beq-      .loc_0x33C
	  addi      r3, r16, 0
	  addi      r4, r31, 0
	  bl        -0x2B04

	.loc_0x33C:
	  li        r3, 0x30
	  bl        -0x7D92C
	  mr.       r17, r3
	  beq-      .loc_0x358
	  addi      r3, r17, 0
	  addi      r4, r31, 0
	  bl        -0xC9E0

	.loc_0x358:
	  li        r3, 0x24
	  bl        -0x7D948
	  mr.       r18, r3
	  beq-      .loc_0x374
	  addi      r3, r18, 0
	  addi      r4, r31, 0
	  bl        -0xBBF8

	.loc_0x374:
	  li        r3, 0x34
	  bl        -0x7D964
	  mr.       r19, r3
	  beq-      .loc_0x390
	  addi      r3, r19, 0
	  addi      r4, r31, 0
	  bl        -0x16840

	.loc_0x390:
	  li        r3, 0x30
	  bl        -0x7D980
	  mr.       r20, r3
	  beq-      .loc_0x3B0
	  addi      r3, r20, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0xB6DC

	.loc_0x3B0:
	  li        r3, 0xC0
	  bl        -0x7D9A0
	  mr.       r21, r3
	  beq-      .loc_0x3D0
	  addi      r3, r21, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x157CC

	.loc_0x3D0:
	  li        r3, 0x38
	  bl        -0x7D9C0
	  mr.       r22, r3
	  beq-      .loc_0x3F0
	  addi      r3, r22, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x1046C

	.loc_0x3F0:
	  li        r3, 0x58
	  bl        -0x7D9E0
	  mr.       r23, r3
	  beq-      .loc_0x410
	  addi      r3, r23, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x17B5C

	.loc_0x410:
	  li        r3, 0x50
	  bl        -0x7DA00
	  mr.       r24, r3
	  beq-      .loc_0x430
	  addi      r3, r24, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x6A2C

	.loc_0x430:
	  li        r3, 0x30
	  bl        -0x7DA20
	  mr.       r25, r3
	  beq-      .loc_0x450
	  addi      r3, r25, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x5FA8

	.loc_0x450:
	  li        r3, 0x3C
	  bl        -0x7DA40
	  mr.       r26, r3
	  beq-      .loc_0x470
	  addi      r3, r26, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  bl        -0x3774

	.loc_0x470:
	  li        r3, 0x2C
	  bl        -0x7DA60
	  mr.       r27, r3
	  beq-      .loc_0x48C
	  addi      r3, r27, 0
	  addi      r4, r31, 0
	  bl        -0x19D0

	.loc_0x48C:
	  li        r3, 0x2C
	  bl        -0x7DA7C
	  mr.       r28, r3
	  beq-      .loc_0x4A8
	  addi      r3, r28, 0
	  addi      r4, r31, 0
	  bl        -0x1DD00

	.loc_0x4A8:
	  li        r3, 0x24
	  bl        -0x7DA98
	  mr.       r30, r3
	  beq-      .loc_0x4C4
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x187A4

	.loc_0x4C4:
	  li        r3, 0x34
	  bl        -0x7DAB4
	  mr.       r29, r3
	  beq-      .loc_0x4E0
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        -0x18330

	.loc_0x4E0:
	  lwz       r0, 0x118(r1)
	  crclr     6, 0x6
	  lwz       r3, 0x114(r1)
	  li        r4, 0x1F
	  stw       r0, 0x8(r1)
	  li        r0, 0
	  lwz       r5, 0x124(r1)
	  stw       r0, 0xC(r1)
	  li        r6, 0
	  lwz       r7, 0x120(r1)
	  li        r8, 0
	  stw       r3, 0x10(r1)
	  lwz       r3, 0x110(r1)
	  li        r10, 0
	  stw       r0, 0x14(r1)
	  lwz       r9, 0x11C(r1)
	  stw       r3, 0x18(r1)
	  lwz       r3, 0x10C(r1)
	  stw       r0, 0x1C(r1)
	  stw       r3, 0x20(r1)
	  lwz       r3, 0x108(r1)
	  stw       r0, 0x24(r1)
	  stw       r3, 0x28(r1)
	  lwz       r3, 0x104(r1)
	  stw       r0, 0x2C(r1)
	  stw       r3, 0x30(r1)
	  lwz       r3, 0x100(r1)
	  stw       r0, 0x34(r1)
	  stw       r3, 0x38(r1)
	  lwz       r3, 0xFC(r1)
	  stw       r0, 0x3C(r1)
	  stw       r3, 0x40(r1)
	  lwz       r3, 0xF8(r1)
	  stw       r0, 0x44(r1)
	  stw       r3, 0x48(r1)
	  lwz       r3, 0xF4(r1)
	  stw       r0, 0x4C(r1)
	  stw       r3, 0x50(r1)
	  lwz       r3, 0xF0(r1)
	  stw       r0, 0x54(r1)
	  stw       r3, 0x58(r1)
	  stw       r0, 0x5C(r1)
	  stw       r14, 0x60(r1)
	  stw       r0, 0x64(r1)
	  stw       r15, 0x68(r1)
	  stw       r0, 0x6C(r1)
	  stw       r16, 0x70(r1)
	  stw       r0, 0x74(r1)
	  stw       r17, 0x78(r1)
	  stw       r0, 0x7C(r1)
	  stw       r18, 0x80(r1)
	  stw       r0, 0x84(r1)
	  stw       r19, 0x88(r1)
	  stw       r0, 0x8C(r1)
	  stw       r20, 0x90(r1)
	  stw       r0, 0x94(r1)
	  stw       r21, 0x98(r1)
	  stw       r0, 0x9C(r1)
	  stw       r22, 0xA0(r1)
	  stw       r0, 0xA4(r1)
	  stw       r23, 0xA8(r1)
	  stw       r0, 0xAC(r1)
	  stw       r24, 0xB0(r1)
	  stw       r0, 0xB4(r1)
	  stw       r25, 0xB8(r1)
	  stw       r0, 0xBC(r1)
	  stw       r26, 0xC0(r1)
	  stw       r0, 0xC4(r1)
	  stw       r27, 0xC8(r1)
	  stw       r0, 0xCC(r1)
	  stw       r28, 0xD0(r1)
	  stw       r0, 0xD4(r1)
	  stw       r30, 0xD8(r1)
	  stw       r0, 0xDC(r1)
	  stw       r29, 0xE0(r1)
	  stw       r0, 0xE4(r1)
	  lwz       r3, 0xE8(r1)
	  bl        -0x894
	  lwz       r29, 0xE8(r1)
	  li        r0, -0x1
	  lwz       r3, 0x128(r1)
	  stw       r0, 0x1C(r29)
	  addi      r4, r3, 0xA4
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x3E3D8
	  mr        r3, r29
	  lmw       r14, 0x130(r1)
	  lwz       r0, 0x17C(r1)
	  addi      r1, r1, 0x178
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C4C3C
 * Size:	000088
 */
TopAction::~TopAction()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x6C
	  lis       r3, 0x802B
	  addi      r0, r3, 0x7FD4
	  stw       r0, 0x0(r30)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7E6C
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x4(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  lis       r4, 0x800C
	  addi      r4, r4, 0x3E80
	  bl        0x14FD68

	.loc_0x54:
	  li        r0, 0
	  stw       r0, 0x4(r30)

	.loc_0x5C:
	  extsh.    r0, r31
	  ble-      .loc_0x6C
	  mr        r3, r30
	  bl        -0x7DAF8

	.loc_0x6C:
	  mr        r3, r30
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
 * Address:	800C4CC4
 * Size:	0000E8
 */
void TopAction::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  sth       r0, 0x8(r3)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r31, r3, r0
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x58
	  lwz       r3, 0xC(r3)
	  li        r5, 0xA
	  li        r0, 0x2
	  stb       r5, 0x400(r3)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0x58:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r3, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r31)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xB4

	.loc_0x98:
	  lwz       r3, 0x0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xB4
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0xB4:
	  li        r0, 0
	  stw       r0, 0x20(r30)
	  lfs       f0, -0x6A60(r2)
	  stfs      f0, 0x2C(r30)
	  stw       r0, 0x28(r30)
	  stb       r0, 0x1A(r30)
	  stb       r0, 0x19(r30)
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
 * Address:	800C4DAC
 * Size:	000598
 */
void TopAction::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  mr        r30, r3
	  stw       r29, 0x4C(r1)
	  stw       r28, 0x48(r1)
	  lbz       r0, 0x19(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x38
	  li        r3, 0
	  b         .loc_0x574

	.loc_0x38:
	  lha       r0, 0x8(r30)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x108
	  lwz       r3, 0xC(r30)
	  bl        0x3760
	  cmpwi     r3, 0xE
	  beq-      .loc_0x100
	  lwz       r3, 0xC(r30)
	  li        r4, 0
	  li        r0, 0xF
	  sth       r4, 0x4FC(r3)
	  sth       r0, 0x8(r30)
	  lha       r0, 0x8(r30)
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r0,3,0,28
	  add       r28, r3, r0
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0xA0
	  lwz       r3, 0xC(r3)
	  li        r4, 0xA
	  li        r0, 0x2
	  stb       r4, 0x400(r3)
	  lwz       r3, 0x0(r28)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0xA0:
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0xC0
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0xC0:
	  lwz       r3, 0x4(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0xE4
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r28)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x100

	.loc_0xE4:
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x100
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0x100:
	  li        r3, 0
	  b         .loc_0x574

	.loc_0x108:
	  cmpwi     r0, 0x7
	  bne-      .loc_0x288
	  lwz       r3, 0xC(r30)
	  bl        0x74AC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x288
	  lha       r0, 0x8(r30)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x134
	  li        r3, 0
	  b         .loc_0x140

	.loc_0x134:
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0

	.loc_0x140:
	  lbz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x288
	  lwz       r29, 0x30AC(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x6A5C(r2)
	  mr        r28, r3
	  b         .loc_0x22C

	.loc_0x170:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x198
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  b         .loc_0x1B4

	.loc_0x198:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x1B4:
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x210
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x210
	  lwz       r0, 0x2A8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x210
	  mr        r3, r31
	  lwz       r4, 0xC(r30)
	  bl        -0x38120
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x210
	  lwz       r3, 0xC(r30)
	  li        r4, 0x5
	  lwz       r5, 0x504(r3)
	  bl        0x8218
	  b         .loc_0x288

	.loc_0x210:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x22C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x254
	  li        r0, 0x1
	  b         .loc_0x280

	.loc_0x254:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x27C
	  li        r0, 0x1
	  b         .loc_0x280

	.loc_0x27C:
	  li        r0, 0

	.loc_0x280:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x170

	.loc_0x288:
	  lha       r0, 0x8(r30)
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0x3
	  bge-      .loc_0x570
	  cmpwi     r3, 0x1
	  bge-      .loc_0x2C0
	  b         .loc_0x570

	.loc_0x2C0:
	  lha       r0, 0x8(r30)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x2D4
	  li        r3, 0x1
	  b         .loc_0x574

	.loc_0x2D4:
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x20(r30)
	  li        r0, -0x1
	  sth       r0, 0x8(r30)
	  lfs       f0, -0x6A60(r2)
	  stfs      f0, 0x2C(r30)
	  lwz       r4, 0xC(r30)
	  lhz       r0, 0x4FC(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x538
	  lbz       r0, 0x408(r4)
	  li        r28, 0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x33C
	  bge-      .loc_0x368
	  cmpwi     r0, 0
	  bge-      .loc_0x364
	  b         .loc_0x368
	  b         .loc_0x368

	.loc_0x33C:
	  lwz       r3, 0x504(r4)
	  bl        -0x38270
	  lwz       r3, 0xC(r30)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x478(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x368
	  li        r28, 0x1
	  b         .loc_0x368

	.loc_0x364:
	  li        r28, 0x1

	.loc_0x368:
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x3F4
	  lwz       r3, 0xC(r30)
	  li        r4, 0x1
	  li        r5, 0
	  lbz       r28, 0x400(r3)
	  bl        0x80A0
	  lwz       r3, 0xC(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C0
	  lwz       r4, 0xC(r30)
	  li        r5, 0x1D
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3EC

	.loc_0x3C0:
	  cmpwi     r28, 0xA
	  beq-      .loc_0x3EC
	  lwz       r3, 0xC(r30)
	  li        r5, 0x1F
	  stb       r28, 0x400(r3)
	  lwz       r4, 0xC(r30)
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x3EC:
	  li        r3, 0
	  b         .loc_0x574

	.loc_0x3F4:
	  lwz       r3, 0xC(r30)
	  lbz       r0, 0x408(r3)
	  cmplwi    r0, 0x3
	  bne-      .loc_0x420
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x420
	  lwz       r5, 0x504(r3)
	  li        r4, 0x12
	  bl        0x8008
	  b         .loc_0x570

	.loc_0x420:
	  lbz       r31, 0x400(r3)
	  li        r4, 0
	  li        r0, 0xF
	  sth       r4, 0x4FC(r3)
	  sth       r0, 0x8(r30)
	  lha       r0, 0x8(r30)
	  lwz       r3, 0x4(r30)
	  rlwinm    r0,r0,3,0,28
	  add       r28, r3, r0
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x46C
	  lwz       r3, 0xC(r3)
	  li        r4, 0xA
	  li        r0, 0x2
	  stb       r4, 0x400(r3)
	  lwz       r3, 0x0(r28)
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)

	.loc_0x46C:
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x48C
	  lwz       r12, 0x0(r3)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl

	.loc_0x48C:
	  lwz       r3, 0x4(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x4B0
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r28)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4CC

	.loc_0x4B0:
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x4CC
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0x4CC:
	  lwz       r3, 0xC(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x508
	  lwz       r4, 0xC(r30)
	  li        r5, 0x1D
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x570

	.loc_0x508:
	  cmpwi     r31, 0xA
	  beq-      .loc_0x570
	  lwz       r3, 0xC(r30)
	  li        r5, 0x1F
	  stb       r31, 0x400(r3)
	  lwz       r4, 0xC(r30)
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x570

	.loc_0x538:
	  lbz       r28, 0x400(r4)
	  mr        r3, r4
	  bl        0x2DD0
	  cmpwi     r28, 0xA
	  beq-      .loc_0x570
	  lwz       r3, 0xC(r30)
	  li        r5, 0x1F
	  stb       r28, 0x400(r3)
	  lwz       r4, 0xC(r30)
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x570:
	  li        r3, 0

	.loc_0x574:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  lwz       r28, 0x48(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C5344
 * Size:	000084
 */
void TopAction::abandon(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x54
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31

	.loc_0x54:
	  li        r0, -0x1
	  sth       r0, 0x8(r31)
	  li        r0, 0
	  stw       r0, 0x28(r31)
	  stw       r0, 0x24(r31)
	  stw       r0, 0x20(r31)
	  stb       r0, 0x19(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C53C8
 * Size:	00004C
 */
void TopAction::resumable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x38
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3C

	.loc_0x38:
	  li        r3, 0

	.loc_0x3C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C5414
 * Size:	00004C
 */
void TopAction::resume()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x8(r1)
	  stb       r0, 0x19(r3)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x3C
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl

	.loc_0x3C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C5460
 * Size:	00004C
 */
void TopAction::restart()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stb       r0, 0x19(r3)
	  lha       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x3C
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl

	.loc_0x3C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void TopAction::knowledgeCheck()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C54AC
 * Size:	000090
 */
TopAction::ObjBore::ObjBore()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x5
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  stw       r31, 0xC(r3)
	  stw       r0, 0x10(r3)
	  lwz       r0, 0x10(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x7E4D8
	  stw       r3, 0x0(r30)
	  lwz       r0, 0x10(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x7E4E8
	  stw       r3, 0x4(r30)
	  lwz       r3, 0x10(r30)
	  bl        -0x7E4F4
	  stw       r3, 0x8(r30)
	  li        r4, 0
	  b         .loc_0x68

	.loc_0x5C:
	  lwz       r3, 0x8(r30)
	  stbx      r31, r3, r4
	  addi      r4, r4, 0x1

	.loc_0x68:
	  lwz       r0, 0x10(r30)
	  cmpw      r4, r0
	  blt+      .loc_0x5C
	  mr        r3, r30
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
 * Address:	........
 * Size:	000044
 */
void TopAction::ObjBore::getIndex(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
void TopAction::ObjBore::addBoredom(int, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
void TopAction::ObjBore::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C553C
 * Size:	00008C
 */
TopAction::Boredom::Boredom()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1E
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  li        r31, 0
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  stw       r31, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r30, 0xC(r3)
	  mulli     r3, r30, 0x14
	  addi      r3, r3, 0x8
	  bl        -0x7E570
	  lis       r4, 0x800C
	  addi      r4, r4, 0x54AC
	  addi      r7, r30, 0
	  li        r5, 0
	  li        r6, 0x14
	  bl        0x14F69C
	  stw       r3, 0x0(r29)
	  lwz       r0, 0xC(r29)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x7E598
	  stw       r3, 0x4(r29)
	  mr        r3, r29
	  stw       r31, 0x10(r29)
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
 * Address:	........
 * Size:	000044
 */
void TopAction::Boredom::getIndex(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void TopAction::Boredom::getBoredom(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void TopAction::Boredom::addBoredom(int, int, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000134
 */
void TopAction::Boredom::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void TopAction::Boredom::draw2d(Graphics&, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C55C8
 * Size:	00003C
 */
void TopAction::getInfo(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x60(r12)
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
 * Address:	800C5604
 * Size:	000048
 */
void TopAction::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x18(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x38
	  lha       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r0,3,0,28
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl

	.loc_0x38:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800C564C
 * Size:	000088
 */
OrAction::~OrAction()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x6C
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7F54
	  stw       r0, 0x0(r30)
	  beq-      .loc_0x5C
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7E6C
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x4(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  lis       r4, 0x800C
	  addi      r4, r4, 0x3E80
	  bl        0x14F358

	.loc_0x54:
	  li        r0, 0
	  stw       r0, 0x4(r30)

	.loc_0x5C:
	  extsh.    r0, r31
	  ble-      .loc_0x6C
	  mr        r3, r30
	  bl        -0x7E508

	.loc_0x6C:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
