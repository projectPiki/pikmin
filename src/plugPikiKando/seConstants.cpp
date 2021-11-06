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
 * Address:	800A3B04
 * Size:	000134
 */
SeConstant::SeConstant()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r4, 0x738C
  subi      r4, r13, 0x52F8
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  addi      r31, r3, 0
  lis       r3, 0x8022
  stw       r30, 0x40(r1)
  li        r30, 0
  stw       r0, 0x0(r31)
  addi      r0, r3, 0x737C
  addi      r3, r31, 0
  stw       r0, 0x0(r31)
  stw       r30, 0x10(r31)
  stw       r30, 0xC(r31)
  stw       r30, 0x8(r31)
  bl        -0x7EC78
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x0(r31)
  addi      r3, r31, 0
  subi      r4, r13, 0x52F8
  bl        -0x63428
  lis       r3, 0x802B
  addi      r0, r3, 0x1DC4
  stw       r0, 0x0(r31)
  addi      r5, r1, 0x20
  addi      r3, r31, 0x24
  stw       r30, 0x20(r31)
  addi      r4, r31, 0x20
  lwz       r0, -0x52F0(r13)
  stw       r0, 0x28(r1)
  lwz       r0, 0x28(r1)
  stw       r0, 0x20(r1)
  bl        -0x45114
  lis       r3, 0x802A
  addi      r30, r3, 0x6098
  stw       r30, 0x2C(r31)
  addi      r5, r1, 0x1C
  addi      r3, r31, 0x34
  lfs       f0, -0x7278(r2)
  addi      r4, r31, 0x20
  stfs      f0, 0x30(r31)
  lwz       r0, -0x52EC(r13)
  stw       r0, 0x30(r1)
  lwz       r0, 0x30(r1)
  stw       r0, 0x1C(r1)
  bl        -0x45148
  stw       r30, 0x3C(r31)
  addi      r5, r1, 0x18
  addi      r3, r31, 0x44
  lfs       f0, -0x7274(r2)
  addi      r4, r31, 0x20
  stfs      f0, 0x40(r31)
  lwz       r0, -0x52E8(r13)
  stw       r0, 0x38(r1)
  lwz       r0, 0x38(r1)
  stw       r0, 0x18(r1)
  bl        -0x45174
  stw       r30, 0x4C(r31)
  lis       r3, 0x802B
  addi      r5, r3, 0x1D2C
  lfs       f0, -0x7270(r2)
  mr        r3, r31
  subi      r4, r13, 0x52E4
  stfs      f0, 0x50(r31)
  li        r6, 0x1
  bl        -0x63578
  mr        r3, r31
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A3C38
 * Size:	000024
 */
void SeConstant::read(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x20
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x450B0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}
