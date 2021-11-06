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
 * Address:	80047004
 * Size:	000164
 */
void System::alloc(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm.   r0,r3,0,30,31
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  li        r3, 0
  beq-      .loc_0x28
  addi      r0, r31, 0x3
  rlwinm    r31,r0,0,0,29

.loc_0x28:
  lwz       r4, 0x2DEC(r13)
  lwz       r0, 0x194(r4)
  cmpwi     r0, 0
  blt-      .loc_0x150
  mulli     r3, r0, 0x28
  addi      r3, r3, 0x54
  add       r3, r4, r3
  addi      r4, r31, 0
  bl        -0x228AC
  cmplwi    r3, 0
  cmplwi    r31, 0
  beq-      .loc_0x68
  lwz       r4, 0x2DEC(r13)
  lwz       r0, 0x198(r4)
  cmpwi     r0, 0
  beq-      .loc_0x94

.loc_0x68:
  lwz       r4, 0x2DEC(r13)
  li        r0, 0x1
  addi      r5, r4, 0x1C
  lwz       r4, 0x1C(r4)
  stw       r0, 0x0(r5)
  neg       r4, r4
  subic     r0, r4, 0x1
  subfe     r0, r0, r4
  lwz       r4, 0x2DEC(r13)
  rlwinm    r0,r0,0,24,31
  stw       r0, 0x1C(r4)

.loc_0x94:
  lwz       r4, 0x2DEC(r13)
  lwz       r4, 0x19C(r4)
  b         .loc_0xB0

.loc_0xA0:
  lwz       r0, 0x14(r4)
  add       r0, r0, r31
  stw       r0, 0x14(r4)
  lwz       r4, 0x8(r4)

.loc_0xB0:
  cmplwi    r4, 0
  bne+      .loc_0xA0
  rlwinm.   r0,r3,0,30,31
  rlwinm.   r5,r31,30,2,31
  li        r6, 0
  ble-      .loc_0x150
  cmpwi     r5, 0x8
  subi      r4, r5, 0x8
  ble-      .loc_0x144
  addi      r0, r4, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r4, 0
  mtctr     r0
  addi      r4, r3, 0
  li        r0, 0
  ble-      .loc_0x144

.loc_0xF0:
  stw       r0, 0x0(r4)
  addi      r6, r6, 0x8
  stw       r0, 0x4(r4)
  stw       r0, 0x8(r4)
  stw       r0, 0xC(r4)
  stw       r0, 0x10(r4)
  stw       r0, 0x14(r4)
  stw       r0, 0x18(r4)
  stw       r0, 0x1C(r4)
  addi      r4, r4, 0x20
  bdnz+     .loc_0xF0
  b         .loc_0x144

.loc_0x120:
  sub       r0, r5, r6
  cmpw      r6, r5
  mtctr     r0
  li        r0, 0
  bge-      .loc_0x150

.loc_0x134:
  stw       r0, 0x0(r4)
  addi      r4, r4, 0x4
  bdnz+     .loc_0x134
  b         .loc_0x150

.loc_0x144:
  rlwinm    r0,r6,2,0,29
  add       r4, r3, r0
  b         .loc_0x120

.loc_0x150:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void operator new (unsigned long, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80047168
 * Size:	000044
 */
void operator new[] (unsigned long, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0
  add       r3, r3, r31
  bl        -0x17C
  subi      r0, r31, 0x1
  add       r3, r31, r3
  not       r4, r0
  subi      r0, r3, 0x1
  and       r3, r4, r0
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800471AC
 * Size:	000004
 */
void operator delete (void *)
{
}

/*
 * --INFO--
 * Address:	800471B0
 * Size:	000004
 */
void operator delete[] (void *)
{
}
