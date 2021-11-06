#include "types.h"



/*
 * --INFO--
 * Address:	80116080
 * Size:	00000C
 */
void MapCode::getAttribute(CollTriInfo *)
{
/*
.loc_0x0:
  lwz       r0, 0x0(r3)
  rlwinm    r3,r0,3,29,31
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void MapCode::getAttributeName(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011608C
 * Size:	00001C
 */
void MapCode::getSlipCode(CollTriInfo *)
{
/*
.loc_0x0:
  cmplwi    r3, 0
  beq-      .loc_0x14
  lwz       r0, 0x0(r3)
  rlwinm    r3,r0,5,30,31
  blr       

.loc_0x14:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801160A8
 * Size:	000068
 */
void MapCode::isBald(CollTriInfo *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  beq-      .loc_0x50
  lfs       f1, -0x6080(r2)
  bl        0x105C24
  lfs       f0, 0x1C(r31)
  fcmpo     cr0, f0, f1
  bge-      .loc_0x34
  li        r3, 0x1
  b         .loc_0x54

.loc_0x34:
  lwz       r0, 0x0(r31)
  rlwinm.   r0,r0,7,31,31
  beq-      .loc_0x48
  li        r3, 0
  b         .loc_0x54

.loc_0x48:
  li        r3, 0x1
  b         .loc_0x54

.loc_0x50:
  li        r3, 0x1

.loc_0x54:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
