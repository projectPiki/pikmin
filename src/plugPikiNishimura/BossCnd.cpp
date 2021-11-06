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
 * Size:	0000F0
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014FAFC
 * Size:	000040
 */
void CndIsAlive::satisfy(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  cmplwi    r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  beq-      .loc_0x2C
  mr        r3, r4
  lwz       r12, 0x0(r4)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  b         .loc_0x30

.loc_0x2C:
  li        r3, 0

.loc_0x30:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014FB3C
 * Size:	0000C8
 */
void CndBossFlick::satisfy(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr.       r31, r4
  stw       r30, 0x30(r1)
  addi      r30, r3, 0
  beq-      .loc_0xAC
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xAC
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,16,16
  bne-      .loc_0xAC
  lwz       r0, 0x184(r31)
  lwz       r3, 0x4(r30)
  cmplw     r0, r3
  bne-      .loc_0xAC
  lwz       r3, 0x224(r3)
  addi      r31, r3, 0x118
  bl        0xC84D4
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5790(r2)
  stw       r0, 0x2C(r1)
  lis       r0, 0x4330
  lfs       f3, -0x579C(r2)
  stw       r0, 0x28(r1)
  lfs       f2, -0x57A0(r2)
  lfd       f0, 0x28(r1)
  lfs       f1, -0x5798(r2)
  fsubs     f4, f0, f4
  lfs       f0, 0x0(r31)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f1, f1, f2
  fcmpo     cr0, f1, f0
  bge-      .loc_0xAC
  li        r3, 0x1
  b         .loc_0xB0

.loc_0xAC:
  li        r3, 0

.loc_0xB0:
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014FC04
 * Size:	000070
 */
void CndStickBossKill::satisfy(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr.       r31, r4
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  beq-      .loc_0x54
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x54
  lwz       r3, 0x184(r31)
  lwz       r0, 0x4(r30)
  cmplw     r3, r0
  bne-      .loc_0x54
  li        r3, 0x1
  b         .loc_0x58

.loc_0x54:
  li        r3, 0

.loc_0x58:
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
 * Address:	8014FC74
 * Size:	00007C
 */
void CndStickMouthKill::satisfy(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr.       r31, r4
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  beq-      .loc_0x60
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x60
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x60
  lwz       r3, 0x184(r31)
  lwz       r0, 0x4(r30)
  cmplw     r3, r0
  bne-      .loc_0x60
  li        r3, 0x1
  b         .loc_0x64

.loc_0x60:
  li        r3, 0

.loc_0x64:
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
 * Address:	8014FCF0
 * Size:	000098
 */
void CndBossCollKill::satisfy(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  mr.       r31, r4
  stw       r30, 0x28(r1)
  addi      r30, r3, 0
  beq-      .loc_0x7C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x7C
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,16,16
  bne-      .loc_0x7C
  lwz       r3, 0x184(r31)
  lwz       r0, 0x4(r30)
  cmplw     r3, r0
  bne-      .loc_0x7C
  lwz       r4, 0x188(r31)
  addi      r3, r1, 0x18
  bl        -0xC7EB0
  lwz       r3, 0x18(r1)
  lwz       r0, 0x8(r30)
  cmplw     r0, r3
  bne-      .loc_0x7C
  li        r3, 0x1
  b         .loc_0x80

.loc_0x7C:
  li        r3, 0

.loc_0x80:
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}
