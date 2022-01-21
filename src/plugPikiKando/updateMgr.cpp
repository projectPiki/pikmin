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
 * Address:	800A5444
 * Size:	000014
 */
UpdateContext::UpdateContext()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  stw       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A5458
 * Size:	00004C
 */
void UpdateContext::updatable()
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x0(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x24
	  li        r3, 0
	  b         .loc_0x3C

	.loc_0x24:
	  bl        0xE4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x38
	  li        r3, 0x1
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
 * Address:	800A54A4
 * Size:	000030
 */
void UpdateContext::init(UpdateMgr*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  stw       r4, 0x0(r3)
	  addi      r3, r4, 0
	  addi      r4, r5, 0
	  bl        0x164
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A54D4
 * Size:	00004C
 */
void UpdateContext::exit()
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
	  beq-      .loc_0x30
	  mr        r4, r31
	  bl        0x1BC
	  li        r0, 0
	  stw       r0, 0x0(r31)

	.loc_0x30:
	  li        r0, 0
	  stb       r0, 0x8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A5520
 * Size:	00001C
 */
UpdateMgr::UpdateMgr()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x8(r3)
	  stw       r0, 0xC(r3)
	  stw       r0, 0x0(r3)
	  stw       r0, 0x4(r3)
	  stw       r0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A553C
 * Size:	000024
 */
void UpdateMgr::update()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x10(r3)
	  addi      r4, r4, 0x1
	  stw       r4, 0x10(r3)
	  lwz       r0, 0x0(r3)
	  cmpw      r4, r0
	  bltlr-
	  li        r0, 0
	  stw       r0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A5560
 * Size:	000030
 */
void UpdateMgr::updatable(UpdateContext*)
{
	/*
	.loc_0x0:
	  cmplwi    r4, 0
	  bne-      .loc_0x10
	  li        r3, 0
	  blr

	.loc_0x10:
	  lwz       r4, 0x4(r4)
	  lwz       r0, 0x10(r3)
	  cmpw      r4, r0
	  bne-      .loc_0x28
	  li        r3, 0x1
	  blr

	.loc_0x28:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A5590
 * Size:	000094
 */
void UpdateMgr::create(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  rlwinm    r31,r4,2,0,29
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stw       r4, 0x0(r3)
	  mr        r3, r31
	  bl        -0x5E5B0
	  stw       r3, 0x8(r30)
	  mr        r3, r31
	  bl        -0x5E5BC
	  stw       r3, 0xC(r30)
	  li        r4, 0
	  addi      r5, r4, 0
	  stw       r4, 0x4(r30)
	  li        r6, 0
	  stw       r4, 0x10(r30)
	  b         .loc_0x68

	.loc_0x50:
	  lwz       r3, 0x8(r30)
	  addi      r6, r6, 0x1
	  stwx      r4, r3, r5
	  lwz       r3, 0xC(r30)
	  stwx      r4, r3, r5
	  addi      r5, r5, 0x4

	.loc_0x68:
	  lwz       r0, 0x0(r30)
	  cmpw      r6, r0
	  blt+      .loc_0x50
	  li        r0, 0
	  stw       r0, 0x14(r30)
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
 * Address:	800A5624
 * Size:	000090
 */
void UpdateMgr::addClient(UpdateContext*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  li        r7, -0x1
	  li        r8, 0x2710
	  cmpwi     r0, 0
	  mtctr     r0
	  li        r9, 0
	  li        r6, 0
	  ble-      .loc_0x44

	.loc_0x20:
	  lwz       r5, 0x8(r3)
	  lwzx      r0, r5, r6
	  cmpw      r0, r8
	  bge-      .loc_0x38
	  addi      r7, r9, 0
	  mr        r8, r0

	.loc_0x38:
	  addi      r6, r6, 0x4
	  addi      r9, r9, 0x1
	  bdnz+     .loc_0x20

	.loc_0x44:
	  cmpwi     r7, -0x1
	  beqlr-
	  stw       r7, 0x4(r4)
	  rlwinm    r7,r7,2,0,29
	  lwz       r6, 0x8(r3)
	  lwzx      r5, r6, r7
	  addi      r0, r5, 0x1
	  stwx      r0, r6, r7
	  lbz       r0, 0x8(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  lwz       r5, 0xC(r3)
	  lwzx      r4, r5, r7
	  addi      r0, r4, 0x1
	  stwx      r0, r5, r7

	.loc_0x80:
	  lwz       r4, 0x4(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A56B4
 * Size:	00005C
 */
void UpdateMgr::removeClient(UpdateContext*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r4)
	  cmpwi     r5, 0
	  blt-      .loc_0x14
	  lwz       r0, 0x0(r3)
	  cmpw      r5, r0

	.loc_0x14:
	  lwz       r7, 0x8(r3)
	  rlwinm    r6,r5,2,0,29
	  lwzx      r5, r7, r6
	  subi      r0, r5, 0x1
	  stwx      r0, r7, r6
	  lbz       r0, 0x8(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lwz       r0, 0x4(r4)
	  lwz       r6, 0xC(r3)
	  rlwinm    r5,r0,2,0,29
	  lwzx      r4, r6, r5
	  subi      r0, r4, 0x1
	  stwx      r0, r6, r5

	.loc_0x4C:
	  lwz       r4, 0x4(r3)
	  subi      r0, r4, 0x1
	  stw       r0, 0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void UpdateMgr::balanceClient(UpdateContext*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
void UpdateMgr::showInfo(Graphics&, int, int)
{
	// UNUSED FUNCTION
}
