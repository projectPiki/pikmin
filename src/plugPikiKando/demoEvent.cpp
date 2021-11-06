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
 * Address:	........
 * Size:	000090
 */
void DemoEventMgr::getEventName(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void DemoEventMgr::getSenderName(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008313C
 * Size:	000004
 */
DemoEventMgr::DemoEventMgr()
{
}

/*
 * --INFO--
 * Address:	80083140
 * Size:	00044C
 */
void DemoEventMgr::act(int, int)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r4, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x80(r1)
  stw       r31, 0x7C(r1)
  stw       r30, 0x78(r1)
  stw       r29, 0x74(r1)
  stw       r28, 0x70(r1)
  addi      r28, r5, 0
  beq-      .loc_0x1A8
  bge-      .loc_0x38
  cmpwi     r4, 0
  bge-      .loc_0x18C
  b         .loc_0x42C

.loc_0x38:
  cmpwi     r4, 0x5
  beq-      .loc_0x48
  bge-      .loc_0x42C
  b         .loc_0x280

.loc_0x48:
  cmpwi     r28, 0x1
  beq-      .loc_0x7C
  bge-      .loc_0x42C
  cmpwi     r28, 0
  bge-      .loc_0x60
  b         .loc_0x42C

.loc_0x60:
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r4, 0x20(r3)
  addi      r3, r3, 0x2D8
  lfs       f1, 0x20(r4)
  bl        -0x31998
  b         .loc_0x42C

.loc_0x7C:
  lwz       r30, 0x3068(r13)
  lwz       r12, 0x0(r30)
  mr        r3, r30
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0x12C

.loc_0x9C:
  cmpwi     r31, -0x1
  bne-      .loc_0xC0
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0xD8

.loc_0xC0:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r31
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0xD8:
  mr        r29, r3
  lwz       r12, 0x0(r29)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x110
  lwz       r3, 0x30AC(r13)
  lhz       r4, 0x510(r29)
  bl        0x6F77C
  cmplwi    r3, 0
  beq-      .loc_0x110
  mr        r4, r29
  bl        0x6800C

.loc_0x110:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r31
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0x12C:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r31
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x154
  li        r0, 0x1
  b         .loc_0x180

.loc_0x154:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r31
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x17C
  li        r0, 0x1
  b         .loc_0x180

.loc_0x17C:
  li        r0, 0

.loc_0x180:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x9C
  b         .loc_0x42C

.loc_0x18C:
  cmpwi     r28, 0
  beq-      .loc_0x198
  b         .loc_0x42C

.loc_0x198:
  lwz       r3, 0x3120(r13)
  bl        0x940E8
  bl        0x756A0
  b         .loc_0x42C

.loc_0x1A8:
  lwz       r3, 0x30AC(r13)
  bl        0x6F94C
  mr.       r29, r3
  beq-      .loc_0x42C
  cmplwi    r28, 0x7
  bgt-      .loc_0x42C
  lis       r3, 0x802B
  subi      r3, r3, 0x1E44
  rlwinm    r0,r28,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  addi      r3, r29, 0
  li        r4, 0
  bl        0x643F4
  b         .loc_0x42C
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x643E4
  b         .loc_0x42C
  addi      r3, r29, 0
  li        r4, 0x2
  bl        0x643D4
  b         .loc_0x42C
  mr        r3, r29
  bl        0x644F4
  addi      r3, r29, 0
  li        r4, 0
  bl        0x63E98
  lwz       r3, 0x2F6C(r13)
  li        r4, 0x1
  bl        -0x29A0
  lwz       r3, 0x3120(r13)
  bl        0x94058
  cmplwi    r3, 0
  beq-      .loc_0x42C
  bl        0x76ED0
  b         .loc_0x42C
  mr        r3, r29
  bl        0x65590
  lwz       r3, 0x3068(r13)
  bl        0x4BB30
  b         .loc_0x42C
  lwz       r4, 0x2F6C(r13)
  mr        r3, r29
  lbz       r4, 0x10(r4)
  bl        0x644C4
  b         .loc_0x42C
  mr        r3, r29
  bl        0x64C74
  b         .loc_0x42C
  mr        r3, r29
  bl        0x64D14
  b         .loc_0x42C

.loc_0x280:
  subi      r31, r4, 0x2
  lwz       r3, 0x30AC(r13)
  mr        r4, r31
  bl        0x6F5EC
  mr.       r30, r3
  beq-      .loc_0x42C
  cmplwi    r28, 0x6
  bgt-      .loc_0x42C
  lis       r3, 0x802B
  subi      r3, r3, 0x1E60
  rlwinm    r0,r28,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  lwz       r4, 0x2D0(r30)
  addi      r3, r30, 0
  addi      r0, r4, 0x1
  stw       r0, 0x2D0(r30)
  bl        0x689F4
  b         .loc_0x42C
  mr        r3, r30
  bl        0x6849C
  b         .loc_0x42C
  lwz       r4, 0x2F6C(r13)
  addi      r0, r31, 0x3
  li        r3, 0x1
  lbz       r4, 0x184(r4)
  slw       r0, r3, r0
  and.      r0, r4, r0
  beq-      .loc_0x42C
  mr        r3, r30
  bl        0x684A4
  b         .loc_0x42C
  lwz       r3, 0x2F6C(r13)
  li        r0, 0x1
  slw       r0, r0, r31
  lbz       r3, 0x184(r3)
  and.      r0, r3, r0
  beq-      .loc_0x42C
  mr        r3, r30
  bl        0x682D0
  b         .loc_0x42C
  lwz       r3, 0x2F6C(r13)
  li        r0, 0x1
  slw       r0, r0, r31
  lbz       r3, 0x184(r3)
  and.      r0, r3, r0
  beq-      .loc_0x42C
  mr        r3, r30
  bl        0x68328
  b         .loc_0x42C
  mr        r3, r30
  bl        0x688F8
  lwz       r4, 0x2F6C(r13)
  addi      r0, r31, 0x3
  li        r30, 0x1
  lbz       r3, 0x184(r4)
  slw       r0, r30, r0
  or        r0, r3, r0
  stb       r0, 0x184(r4)
  lwz       r3, 0x2F6C(r13)
  bl        -0x3040
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x42C
  lwz       r3, 0x2F6C(r13)
  lbz       r0, 0x11(r3)
  rlwinm.   r0,r0,0,28,28
  beq-      .loc_0x42C
  lwz       r3, 0x3120(r13)
  bl        0x93EF0
  lwz       r3, 0x2F6C(r13)
  lbz       r0, 0x11(r3)
  rlwinm    r0,r0,0,29,27
  stb       r0, 0x11(r3)
  lwz       r3, 0x30D8(r13)
  lwz       r3, 0x20(r3)
  bl        0x9FB84
  lwz       r3, 0x30D8(r13)
  li        r4, 0x1
  li        r5, 0
  lwz       r3, 0x20(r3)
  stb       r30, 0x30(r3)
  lwz       r3, 0x30D8(r13)
  lwz       r3, 0x20(r3)
  bl        0x9FAA4
  b         .loc_0x42C
  lwz       r5, 0x2F6C(r13)
  li        r0, 0x1
  slw       r0, r0, r31
  lbz       r3, 0x184(r5)
  and.      r0, r3, r0
  beq-      .loc_0x42C
  lis       r3, 0x803D
  rlwinm    r4,r31,2,0,29
  addi      r0, r3, 0x1ED0
  add       r3, r0, r4
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0
  bne-      .loc_0x42C
  addi      r3, r5, 0x70
  li        r4, 0x23
  bl        0x4AC
  lwz       r4, 0x2D0(r30)
  addi      r3, r30, 0
  addi      r0, r4, 0x1
  stw       r0, 0x2D0(r30)
  bl        0x68894

.loc_0x42C:
  lwz       r0, 0x84(r1)
  lwz       r31, 0x7C(r1)
  lwz       r30, 0x78(r1)
  lwz       r29, 0x74(r1)
  lwz       r28, 0x70(r1)
  addi      r1, r1, 0x80
  mtlr      r0
  blr
*/
}
