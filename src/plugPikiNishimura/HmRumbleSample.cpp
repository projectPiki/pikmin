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
 * Address:	8017D680
 * Size:	000014
 */
RumbleSample::RumbleSample(int)
{
/*
.loc_0x0:
  lfs       f0, -0x5110(r2)
  stfs      f0, 0x0(r3)
  stfs      f0, 0x4(r3)
  stw       r4, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void RumbleSample::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017D694
 * Size:	000028
 */
void RumbleSample::simpleStop()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x8(r3)
  bl        0x88044
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017D6BC
 * Size:	000088
 */
void RumbleSample::simpleStart(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  stfs      f1, 0x0(r3)
  lfs       f1, 0x4(r3)
  lfs       f0, 0x0(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r3)
  lfs       f1, 0x0(r3)
  lfs       f0, -0x5110(r2)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x44
  lwz       r3, 0x8(r3)
  li        r4, 0x2
  bl        0x87FF4
  b         .loc_0x78

.loc_0x44:
  lfs       f1, 0x4(r3)
  lfs       f0, -0x510C(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x64
  lwz       r3, 0x8(r3)
  li        r4, 0
  bl        0x87FD4
  b         .loc_0x78

.loc_0x64:
  fsubs     f0, f1, f0
  li        r4, 0x1
  stfs      f0, 0x4(r3)
  lwz       r3, 0x8(r3)
  bl        0x87FBC

.loc_0x78:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}
