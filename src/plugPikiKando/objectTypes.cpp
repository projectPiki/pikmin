#include "types.h"



/*
 * --INFO--
 * Address:	80094A38
 * Size:	000048
 */
void ObjType::getName(int)
{
/*
.loc_0x0:
  lis       r4, 0x802B
  subi      r4, r4, 0x410
  addi      r5, r4, 0x15C
  li        r6, 0
  b         .loc_0x34

.loc_0x14:
  cmpw      r3, r0
  bne-      .loc_0x2C
  rlwinm    r0,r6,3,0,28
  add       r3, r4, r0
  lwz       r3, 0x160(r3)
  blr       

.loc_0x2C:
  addi      r5, r5, 0x8
  addi      r6, r6, 0x1

.loc_0x34:
  lwz       r0, 0x0(r5)
  cmpwi     r0, 0x39
  bne+      .loc_0x14
  addi      r3, r4, 0x314
  blr
*/
}

/*
 * --INFO--
 * Address:	80094A80
 * Size:	000094
 */
void ObjType::getIndex(char *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802B
  stw       r0, 0x4(r1)
  subi      r0, r4, 0x2B4
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  li        r30, 0
  rlwinm    r5,r30,3,0,28
  stw       r29, 0x14(r1)
  add       r31, r0, r5
  addi      r29, r3, 0
  b         .loc_0x68

.loc_0x34:
  mr        r3, r29
  lwz       r4, 0x4(r31)
  bl        0x184708
  cmpwi     r3, 0
  bne-      .loc_0x60
  lis       r3, 0x802B
  rlwinm    r4,r30,3,0,28
  subi      r0, r3, 0x2B4
  add       r3, r0, r4
  lwz       r3, 0x0(r3)
  b         .loc_0x78

.loc_0x60:
  addi      r31, r31, 0x8
  addi      r30, r30, 0x1

.loc_0x68:
  lwz       r0, 0x0(r31)
  cmpwi     r0, 0x39
  bne+      .loc_0x34
  li        r3, -0x1

.loc_0x78:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}
