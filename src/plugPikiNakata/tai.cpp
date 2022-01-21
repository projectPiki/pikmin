#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80126E04
 * Size:	00005C
 */
TaiSerialAction::TaiSerialAction(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802C
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x6620
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x4(r3)
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6604
	  stw       r4, 0x0(r31)
	  stw       r0, 0x4(r31)
	  stw       r5, 0x8(r31)
	  lwz       r0, 0x8(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xDFE3C
	  stw       r3, 0xC(r31)
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80126E60
 * Size:	000044
 */
void TaiSerialAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x334(r4)
	  lwz       r0, 0x334(r4)
	  lwz       r3, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
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
 * Address:	80126EA4
 * Size:	000004
 */
void TaiAction::start(Teki&) { }

/*
 * --INFO--
 * Address:	80126EA8
 * Size:	000080
 */
void TaiSerialAction::finish(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  lwz       r3, 0xC(r28)
	  mr        r4, r29
	  lwzx      r3, r3, r31
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x54:
	  lwz       r0, 0x8(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	80126F28
 * Size:	000004
 */
void TaiAction::finish(Teki&) { }

/*
 * --INFO--
 * Address:	80126F2C
 * Size:	0000A8
 */
void TaiSerialAction::act(Teki&)
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
	  lwz       r0, 0x334(r4)
	  lwz       r3, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8C
	  lwz       r3, 0x8(r30)
	  lwz       r4, 0x334(r31)
	  subi      r0, r3, 0x1
	  cmpw      r4, r0
	  bne-      .loc_0x60
	  li        r3, 0x1
	  b         .loc_0x90

	.loc_0x60:
	  addi      r0, r4, 0x1
	  stw       r0, 0x334(r31)
	  mr        r4, r31
	  lwz       r0, 0x334(r31)
	  lwz       r3, 0xC(r30)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x8C:
	  li        r3, 0

	.loc_0x90:
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
 * Address:	80126FD4
 * Size:	000008
 */
u32 TaiAction::act(Teki&) { return 0x0; }

/*
 * --INFO--
 * Address:	80126FDC
 * Size:	0000B4
 */
void TaiSerialAction::actByEvent(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r31, 0x4(r4)
	  lwz       r3, 0xC(r3)
	  lwz       r0, 0x334(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x94
	  lwz       r3, 0x8(r29)
	  lwz       r4, 0x334(r31)
	  subi      r0, r3, 0x1
	  cmpw      r4, r0
	  bne-      .loc_0x68
	  li        r3, 0x1
	  b         .loc_0x98

	.loc_0x68:
	  addi      r0, r4, 0x1
	  stw       r0, 0x334(r31)
	  lwz       r0, 0x334(r31)
	  lwz       r3, 0xC(r29)
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x4(r30)
	  lwzx      r3, r3, r0
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x94:
	  li        r3, 0

	.loc_0x98:
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
 * Address:	80127090
 * Size:	000008
 */
u32 TaiAction::actByEvent(TekiEvent&) { return 0x0; }

/*
 * --INFO--
 * Address:	80127098
 * Size:	00004C
 */
TaiState::TaiState(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802C
	  stw       r0, 0x4(r1)
	  addi      r0, r5, 0x65C4
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x0(r3)
	  stw       r4, 0x4(r3)
	  lwz       r0, 0x4(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xE00C0
	  stw       r3, 0x8(r31)
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801270E4
 * Size:	000080
 */
void TaiState::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  lwz       r3, 0x8(r28)
	  mr        r4, r29
	  lwzx      r3, r3, r31
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x54:
	  lwz       r0, 0x4(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	80127164
 * Size:	000080
 */
void TaiState::finish(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  lwz       r3, 0x8(r28)
	  mr        r4, r29
	  lwzx      r3, r3, r31
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x54:
	  lwz       r0, 0x4(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	801271E4
 * Size:	0000EC
 */
void TaiState::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  li        r31, 0
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r28, 0x28(r1)
	  addi      r28, r3, 0
	  stw       r4, 0xC(r1)
	  lwz       r30, 0xC(r1)
	  stw       r31, 0x20(r1)
	  b         .loc_0xB8

	.loc_0x34:
	  lwz       r3, 0x8(r28)
	  mr        r4, r30
	  lwzx      r29, r3, r31
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA8
	  lwz       r0, 0x0(r29)
	  addi      r3, r30, 0x324
	  lwz       r4, 0x324(r30)
	  cmpwi     r0, -0x2
	  bne-      .loc_0x98
	  lwz       r0, 0x330(r30)
	  stw       r0, 0x0(r3)
	  b         .loc_0x9C

	.loc_0x98:
	  stw       r0, 0x0(r3)

	.loc_0x9C:
	  stw       r4, 0x330(r30)
	  li        r3, 0x1
	  b         .loc_0xCC

	.loc_0xA8:
	  lwz       r3, 0x20(r1)
	  addi      r31, r31, 0x4
	  addi      r0, r3, 0x1
	  stw       r0, 0x20(r1)

	.loc_0xB8:
	  lwz       r3, 0x20(r1)
	  lwz       r0, 0x4(r28)
	  cmpw      r3, r0
	  blt+      .loc_0x34
	  li        r3, 0

	.loc_0xCC:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801272D0
 * Size:	000020
 */
void TaiAction::hasNextState()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  li        r3, 0x1
	  cmpwi     r0, 0
	  bgelr-
	  cmpwi     r0, -0x2
	  beqlr-
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801272F0
 * Size:	0000F4
 */
void TaiState::eventPerformed(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  li        r31, 0
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x28(r1)
	  addi      r28, r3, 0
	  stw       r31, 0x24(r1)
	  b         .loc_0xC0

	.loc_0x30:
	  lwz       r3, 0x8(r28)
	  mr        r4, r29
	  lwzx      r30, r3, r31
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB0
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB0
	  lwz       r3, 0x4(r29)
	  stw       r3, 0x20(r1)
	  addi      r4, r3, 0x324
	  lwz       r0, 0x0(r30)
	  lwz       r5, 0x324(r3)
	  cmpwi     r0, -0x2
	  bne-      .loc_0x9C
	  lwz       r0, 0x330(r3)
	  stw       r0, 0x0(r4)
	  b         .loc_0xA0

	.loc_0x9C:
	  stw       r0, 0x0(r4)

	.loc_0xA0:
	  lwz       r4, 0x4(r29)
	  li        r3, 0x1
	  stw       r5, 0x330(r4)
	  b         .loc_0xD4

	.loc_0xB0:
	  lwz       r3, 0x24(r1)
	  addi      r31, r31, 0x4
	  addi      r0, r3, 0x1
	  stw       r0, 0x24(r1)

	.loc_0xC0:
	  lwz       r3, 0x24(r1)
	  lwz       r0, 0x4(r28)
	  cmpw      r3, r0
	  blt+      .loc_0x30
	  li        r3, 0

	.loc_0xD4:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801273E4
 * Size:	000064
 */
TaiStrategy::TaiStrategy(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  bl        0x25D9C
	  lis       r3, 0x802C
	  addi      r0, r3, 0x6590
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  bl        .loc_0x64
	  mr        r3, r29
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0x64:
	*/
}

/*
 * --INFO--
 * Address:	80127448
 * Size:	00004C
 */
void TaiStrategy::init(int, int)
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
	  stw       r4, 0x4(r3)
	  lwz       r0, 0x4(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xE046C
	  stw       r3, 0x8(r30)
	  stw       r31, 0xC(r30)
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
 * Address:	80127494
 * Size:	000014
 */
void TaiStrategy::start(Teki&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0xC(r3)
	  li        r0, 0x1
	  stw       r3, 0x324(r4)
	  stb       r0, 0x328(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801274A8
 * Size:	0000CC
 */
void TaiStrategy::act(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lbz       r0, 0x328(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x58
	  lwz       r0, 0x324(r30)
	  mr        r4, r30
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stb       r0, 0x328(r30)

	.loc_0x58:
	  lwz       r0, 0x324(r30)
	  mr        r4, r30
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r0,2,0,29
	  lwz       r31, 0x324(r30)
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB0
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r31,2,0,29
	  addi      r4, r30, 0
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stb       r0, 0x328(r30)

	.loc_0xB0:
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
 * Address:	80127574
 * Size:	000090
 */
void TaiStrategy::eventPerformed(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r31, 0x4(r4)
	  lwz       r3, 0x8(r3)
	  lwz       r0, 0x324(r31)
	  lwz       r30, 0x324(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x74
	  lwz       r3, 0x8(r29)
	  rlwinm    r0,r30,2,0,29
	  addi      r4, r31, 0
	  lwzx      r3, r3, r0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stb       r0, 0x328(r31)

	.loc_0x74:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
