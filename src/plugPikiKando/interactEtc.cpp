#include "types.h"



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
 * Address:	8007C9F8
 * Size:	00003C
 */
void InteractTalk::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x2
  stwu      r1, -0x18(r1)
  lwz       r3, 0x4(r3)
  stw       r0, 0x10(r1)
  stw       r3, 0x14(r1)
  lwz       r3, 0x4F8(r4)
  addi      r4, r1, 0x10
  bl        0x470C8
  li        r3, 0x1
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8007CA34
 * Size:	000104
 */
void InteractWarn::actPiki(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r4, 0
  addi      r3, r30, 0
  bl        0x4BB04
  addi      r31, r3, 0
  addi      r3, r30, 0
  lwz       r12, 0x0(r30)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x48
  li        r3, 0
  b         .loc_0xEC

.loc_0x48:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0x120(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x7C
  lbz       r0, 0x409(r30)
  cmplwi    r0, 0
  beq-      .loc_0x7C
  lhz       r0, 0x4FC(r30)
  cmplwi    r0, 0x1
  bne-      .loc_0x84

.loc_0x7C:
  li        r3, 0
  b         .loc_0xEC

.loc_0x84:
  cmpwi     r31, 0x8
  beq-      .loc_0xA4
  cmpwi     r31, 0x18
  beq-      .loc_0xA4
  cmpwi     r31, 0x1A
  beq-      .loc_0xA4
  cmpwi     r31, 0x21
  bne-      .loc_0xAC

.loc_0xA4:
  li        r3, 0
  b         .loc_0xEC

.loc_0xAC:
  lbz       r0, 0x2B4(r30)
  cmplwi    r0, 0
  bne-      .loc_0xE0
  cmpwi     r31, 0x16
  beq-      .loc_0xE0
  lwz       r3, 0x490(r30)
  addi      r4, r30, 0
  li        r5, 0x1A
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  b         .loc_0xE8

.loc_0xE0:
  li        r0, 0x1
  stb       r0, 0x4A0(r30)

.loc_0xE8:
  li        r3, 0x1

.loc_0xEC:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
