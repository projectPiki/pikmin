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
 * Size:	000080
 */
void boundSphereDist(Creature *, Creature *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E0228
 * Size:	00010C
 */
void ObjectMgr::stickUpdate()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r3
  stw       r30, 0x20(r1)
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0x98

.loc_0x30:
  cmpwi     r30, -0x1
  bne-      .loc_0x54
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x6C

.loc_0x54:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x6C:
  lwz       r12, 0x0(r3)
  lwz       r12, 0xE8(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x98:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xC0
  li        r0, 0x1
  b         .loc_0xEC

.loc_0xC0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0xE8
  li        r0, 0x1
  b         .loc_0xEC

.loc_0xE8:
  li        r0, 0

.loc_0xEC:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x30
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E0334
 * Size:	000124
 */
void ObjectMgr::invalidateSearch()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  mr        r30, r3
  stw       r29, 0x24(r1)
  lwz       r12, 0x0(r30)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  b         .loc_0xAC

.loc_0x34:
  cmpwi     r29, -0x1
  bne-      .loc_0x5C
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0x78

.loc_0x5C:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0x78:
  addi      r3, r31, 0x168
  bl        -0x3AF58
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x90
  addi      r3, r31, 0x1B8
  bl        0x3AD4

.loc_0x90:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0xAC:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD4
  li        r0, 0x1
  b         .loc_0x100

.loc_0xD4:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0xFC
  li        r0, 0x1
  b         .loc_0x100

.loc_0xFC:
  li        r0, 0

.loc_0x100:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x34
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E0458
 * Size:	00010C
 */
void ObjectMgr::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r3
  stw       r30, 0x20(r1)
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0x98

.loc_0x30:
  cmpwi     r30, -0x1
  bne-      .loc_0x54
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x6C

.loc_0x54:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x6C:
  lwz       r12, 0x0(r3)
  lwz       r12, 0xE0(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x98:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xC0
  li        r0, 0x1
  b         .loc_0xEC

.loc_0xC0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0xE8
  li        r0, 0x1
  b         .loc_0xEC

.loc_0xE8:
  li        r0, 0

.loc_0xEC:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x30
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E0564
 * Size:	000004
 */
void ObjectMgr::store()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void ObjectMgr::restore()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E0568
 * Size:	000264
 */
void ObjectMgr::killAll()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  mr        r31, r3
  stw       r30, 0x28(r1)
  stw       r29, 0x24(r1)
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0xD4

.loc_0x34:
  cmpwi     r30, -0x1
  bne-      .loc_0x58
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x70

.loc_0x58:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x70:
  mr        r29, r3
  lwz       r12, 0x0(r29)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xB8
  addi      r3, r29, 0
  li        r4, 0x1
  bl        -0x5591C
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x110(r12)
  mtlr      r12
  blrl      
  cmpwi     r30, 0
  blt-      .loc_0xB8
  subi      r30, r30, 0x1

.loc_0xB8:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0xD4:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xFC
  li        r0, 0x1
  b         .loc_0x128

.loc_0xFC:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x124
  li        r0, 0x1
  b         .loc_0x128

.loc_0x124:
  li        r0, 0

.loc_0x128:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x34
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0x1EC

.loc_0x14C:
  cmpwi     r30, -0x1
  bne-      .loc_0x170
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x188

.loc_0x170:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x188:
  mr        r29, r3
  lwz       r12, 0x0(r29)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1D0
  addi      r3, r29, 0
  li        r4, 0x1
  bl        -0x55A34
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0x110(r12)
  mtlr      r12
  blrl      
  cmpwi     r30, 0
  blt-      .loc_0x1D0
  subi      r30, r30, 0x1

.loc_0x1D0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x1EC:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x214
  li        r0, 0x1
  b         .loc_0x240

.loc_0x214:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x23C
  li        r0, 0x1
  b         .loc_0x240

.loc_0x23C:
  li        r0, 0

.loc_0x240:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x14C
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E07CC
 * Size:	00016C
 */
void ObjectMgr::postUpdate(int, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stfd      f31, 0x38(r1)
  fmr       f31, f1
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  mr        r30, r3
  stw       r29, 0x2C(r1)
  stw       r28, 0x28(r1)
  mr        r28, r4
  lwz       r12, 0x0(r30)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  b         .loc_0xEC

.loc_0x44:
  cmpwi     r29, -0x1
  bne-      .loc_0x6C
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0x88

.loc_0x6C:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0x88:
  lwz       r12, 0x0(r31)
  fmr       f1, f31
  mr        r3, r31
  lwz       r12, 0xE4(r12)
  mr        r4, r28
  mtlr      r12
  blrl      
  lbz       r0, -0x5F07(r13)
  cmplwi    r0, 0
  bne-      .loc_0xD0
  lbz       r0, 0x2FAA(r13)
  cmplwi    r0, 0
  bne-      .loc_0xD0
  lwz       r0, 0x1CC(r31)
  cmplwi    r0, 0
  beq-      .loc_0xD0
  addi      r3, r31, 0x1B8
  bl        0x35C0

.loc_0xD0:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0xEC:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x114
  li        r0, 0x1
  b         .loc_0x140

.loc_0x114:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x13C
  li        r0, 0x1
  b         .loc_0x140

.loc_0x13C:
  li        r0, 0

.loc_0x140:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x44
  lwz       r0, 0x44(r1)
  lfd       f31, 0x38(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  lwz       r28, 0x28(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E0938
 * Size:	00011C
 */
void ObjectMgr::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r3
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  mr        r29, r4
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0xA4

.loc_0x38:
  cmpwi     r30, -0x1
  bne-      .loc_0x5C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x74

.loc_0x5C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x74:
  lwz       r12, 0x0(r3)
  mr        r4, r29
  lwz       r12, 0xEC(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0xA4:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xCC
  li        r0, 0x1
  b         .loc_0xF8

.loc_0xCC:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0xF4
  li        r0, 0x1
  b         .loc_0xF8

.loc_0xF4:
  li        r0, 0

.loc_0xF8:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x38
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E0A54
 * Size:	00025C
 */
void ObjectMgr::findClosest(Vector3f &, Condition *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC8(r1)
  stfd      f31, 0xC0(r1)
  stfd      f30, 0xB8(r1)
  stfd      f29, 0xB0(r1)
  stfd      f28, 0xA8(r1)
  stmw      r26, 0x90(r1)
  addi      r29, r3, 0
  addi      r26, r4, 0
  addi      r27, r5, 0
  addi      r3, r1, 0x74
  li        r28, 0
  lfs       f28, -0x674C(r2)
  bl        -0x4C9F4
  addi      r3, r1, 0x74
  addi      r4, r26, 0
  bl        -0x4C578
  addi      r30, r29, 0
  addi      r3, r30, 0
  lwz       r12, 0x0(r30)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f29, -0x6750(r2)
  mr        r29, r3
  lfd       f30, -0x6748(r2)
  lfd       f31, -0x6740(r2)
  b         .loc_0x1D8

.loc_0x74:
  cmpwi     r29, -0x1
  bne-      .loc_0x9C
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0xB8

.loc_0x9C:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0xB8:
  lbz       r0, -0x5F06(r13)
  cmplwi    r0, 0
  beq-      .loc_0xDC
  fmr       f1, f28
  addi      r3, r31, 0x40
  addi      r4, r1, 0x74
  bl        -0x4C734
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x1BC

.loc_0xDC:
  cmplwi    r27, 0
  beq-      .loc_0x104
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r31
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1BC

.loc_0x104:
  mr        r4, r31
  lwz       r12, 0x0(r31)
  addi      r3, r1, 0x40
  lwz       r12, 0x58(r12)
  mtlr      r12
  blrl      
  lfs       f3, 0x44(r1)
  lfs       f2, 0x4(r26)
  lfs       f1, 0x40(r1)
  lfs       f0, 0x0(r26)
  fsubs     f3, f3, f2
  lfs       f2, 0x48(r1)
  fsubs     f4, f1, f0
  lfs       f1, 0x8(r26)
  fmuls     f0, f3, f3
  fsubs     f2, f2, f1
  fmuls     f1, f4, f4
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f2, f2, f0
  fcmpo     cr0, f2, f29
  ble-      .loc_0x1AC
  fsqrte    f1, f2
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f0, f1, f0
  fmul      f0, f2, f0
  frsp      f0, f0
  stfs      f0, 0x38(r1)
  lfs       f2, 0x38(r1)

.loc_0x1AC:
  fcmpo     cr0, f2, f28
  bge-      .loc_0x1BC
  fmr       f28, f2
  mr        r28, r31

.loc_0x1BC:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0x1D8:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x200
  li        r0, 0x1
  b         .loc_0x22C

.loc_0x200:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x228
  li        r0, 0x1
  b         .loc_0x22C

.loc_0x228:
  li        r0, 0

.loc_0x22C:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x74
  mr        r3, r28
  lmw       r26, 0x90(r1)
  lwz       r0, 0xCC(r1)
  lfd       f31, 0xC0(r1)
  lfd       f30, 0xB8(r1)
  lfd       f29, 0xB0(r1)
  lfd       f28, 0xA8(r1)
  addi      r1, r1, 0xC8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E0CB0
 * Size:	000274
 */
void ObjectMgr::findClosest(Vector3f &, float, Condition *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xD0(r1)
  stfd      f31, 0xC8(r1)
  stfd      f30, 0xC0(r1)
  stfd      f29, 0xB8(r1)
  stfd      f28, 0xB0(r1)
  stfd      f27, 0xA8(r1)
  fmr       f27, f1
  stmw      r26, 0x90(r1)
  mr        r29, r3
  addi      r26, r4, 0
  addi      r27, r5, 0
  addi      r3, r1, 0x78
  li        r28, 0
  lfs       f28, -0x674C(r2)
  bl        -0x4CC58
  addi      r3, r1, 0x78
  addi      r4, r26, 0
  bl        -0x4C7DC
  addi      r30, r29, 0
  addi      r3, r30, 0
  lwz       r12, 0x0(r30)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f29, -0x6750(r2)
  mr        r29, r3
  lfd       f30, -0x6748(r2)
  lfd       f31, -0x6740(r2)
  b         .loc_0x1EC

.loc_0x7C:
  cmpwi     r29, -0x1
  bne-      .loc_0xA4
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0xC0

.loc_0xA4:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0xC0:
  lbz       r0, -0x5F06(r13)
  cmplwi    r0, 0
  beq-      .loc_0xE4
  fmr       f1, f28
  addi      r3, r31, 0x40
  addi      r4, r1, 0x78
  bl        -0x4C998
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x1D0

.loc_0xE4:
  cmplwi    r27, 0
  beq-      .loc_0x10C
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r31
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1D0

.loc_0x10C:
  mr        r4, r31
  lwz       r12, 0x0(r31)
  addi      r3, r1, 0x44
  lwz       r12, 0x58(r12)
  mtlr      r12
  blrl      
  lfs       f3, 0x48(r1)
  lfs       f2, 0x4(r26)
  lfs       f1, 0x44(r1)
  lfs       f0, 0x0(r26)
  fsubs     f3, f3, f2
  lfs       f2, 0x4C(r1)
  fsubs     f4, f1, f0
  lfs       f1, 0x8(r26)
  fmuls     f0, f3, f3
  fsubs     f2, f2, f1
  fmuls     f1, f4, f4
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f2, f2, f0
  fcmpo     cr0, f2, f29
  ble-      .loc_0x1B4
  fsqrte    f1, f2
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f30, f1
  fmul      f0, f2, f0
  fsub      f0, f31, f0
  fmul      f0, f1, f0
  fmul      f0, f2, f0
  frsp      f0, f0
  stfs      f0, 0x3C(r1)
  lfs       f2, 0x3C(r1)

.loc_0x1B4:
  fcmpo     cr0, f2, f27
  cror      2, 0, 0x2
  bne-      .loc_0x1D0
  fcmpo     cr0, f2, f28
  bge-      .loc_0x1D0
  fmr       f28, f2
  mr        r28, r31

.loc_0x1D0:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0x1EC:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x214
  li        r0, 0x1
  b         .loc_0x240

.loc_0x214:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x23C
  li        r0, 0x1
  b         .loc_0x240

.loc_0x23C:
  li        r0, 0

.loc_0x240:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x7C
  mr        r3, r28
  lmw       r26, 0x90(r1)
  lwz       r0, 0xD4(r1)
  lfd       f31, 0xC8(r1)
  lfd       f30, 0xC0(r1)
  lfd       f29, 0xB8(r1)
  lfd       f28, 0xB0(r1)
  lfd       f27, 0xA8(r1)
  addi      r1, r1, 0xD0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E0F24
 * Size:	000128
 */
void ObjectMgr::drawShadow(Graphics &, Texture *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r3
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  mr        r29, r4
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0xB0

.loc_0x38:
  cmpwi     r30, -0x1
  bne-      .loc_0x5C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x74

.loc_0x5C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x74:
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x94
  lwz       r12, 0x0(r3)
  mr        r4, r29
  lwz       r12, 0xF8(r12)
  mtlr      r12
  blrl      

.loc_0x94:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0xB0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD8
  li        r0, 0x1
  b         .loc_0x104

.loc_0xD8:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x100
  li        r0, 0x1
  b         .loc_0x104

.loc_0x100:
  li        r0, 0

.loc_0x104:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x38
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E104C
 * Size:	0000A4
 */
MonoObjectMgr::MonoObjectMgr()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802B
  stw       r0, 0x4(r1)
  subi      r0, r4, 0x2374
  subi      r4, r13, 0x38D8
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  stw       r0, 0x0(r3)
  addi      r3, r30, 0x8
  stw       r31, 0x4(r30)
  bl        -0xAC0C8
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x8(r30)
  addi      r3, r30, 0x8
  subi      r4, r13, 0x38D8
  bl        -0xA095C
  lis       r3, 0x802C
  subi      r3, r3, 0x4F80
  stw       r3, 0x0(r30)
  addi      r0, r3, 0x18
  lis       r3, 0x802C
  stw       r0, 0x8(r30)
  subi      r3, r3, 0x5038
  addi      r0, r3, 0x18
  stw       r3, 0x0(r30)
  mr        r3, r30
  stw       r0, 0x8(r30)
  stw       r31, 0x28(r30)
  stw       r31, 0x2C(r30)
  stw       r31, 0x30(r30)
  stw       r31, 0x38(r30)
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
 * Address:	800E10F0
 * Size:	0000B4
 */
void MonoObjectMgr::create(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  stw       r28, 0x18(r1)
  mr        r28, r3
  stw       r4, 0x2C(r3)
  lwz       r0, 0x2C(r3)
  rlwinm    r3,r0,2,0,29
  bl        -0x9A118
  stw       r3, 0x28(r28)
  lwz       r0, 0x2C(r28)
  rlwinm    r3,r0,2,0,29
  bl        -0x9A128
  stw       r3, 0x34(r28)
  li        r29, 0
  li        r30, 0
  li        r31, -0x1
  b         .loc_0x80

.loc_0x54:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  lwz       r4, 0x28(r28)
  addi      r29, r29, 0x1
  stwx      r3, r4, r30
  lwz       r3, 0x34(r28)
  stwx      r31, r3, r30
  addi      r30, r30, 0x4

.loc_0x80:
  lwz       r0, 0x2C(r28)
  cmpw      r29, r0
  blt+      .loc_0x54
  li        r0, 0
  stw       r0, 0x30(r28)
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E11A4
 * Size:	0000B8
 */
void MonoObjectMgr::postUpdate(int, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stfd      f31, 0x30(r1)
  fmr       f31, f1
  stmw      r27, 0x1C(r1)
  addi      r27, r3, 0
  addi      r28, r4, 0
  li        r30, 0
  li        r31, 0
  b         .loc_0x94

.loc_0x2C:
  lwz       r3, 0x34(r27)
  lwzx      r0, r3, r31
  cmpwi     r0, 0
  bne-      .loc_0x8C
  lwz       r3, 0x28(r27)
  fmr       f1, f31
  mr        r4, r28
  lwzx      r29, r3, r31
  mr        r3, r29
  lwz       r12, 0x0(r29)
  lwz       r12, 0xE4(r12)
  mtlr      r12
  blrl      
  lbz       r0, -0x5F07(r13)
  cmplwi    r0, 0
  bne-      .loc_0x8C
  lbz       r0, 0x2FAA(r13)
  cmplwi    r0, 0
  bne-      .loc_0x8C
  lwz       r0, 0x1CC(r29)
  cmplwi    r0, 0
  beq-      .loc_0x8C
  addi      r3, r29, 0x1B8
  bl        0x2C2C

.loc_0x8C:
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0x94:
  lwz       r0, 0x2C(r27)
  cmpw      r30, r0
  blt+      .loc_0x2C
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x3C(r1)
  lfd       f31, 0x30(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E125C
 * Size:	00009C
 */
void MonoObjectMgr::drawShadow(Graphics &, Texture *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  li        r31, 0
  stw       r30, 0x28(r1)
  li        r30, 0
  stw       r29, 0x24(r1)
  addi      r29, r4, 0
  stw       r28, 0x20(r1)
  addi      r28, r3, 0
  b         .loc_0x70

.loc_0x30:
  lwz       r3, 0x34(r28)
  lwzx      r0, r3, r31
  cmpwi     r0, 0
  bne-      .loc_0x68
  lwz       r3, 0x28(r28)
  lwzx      r3, r3, r31
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x68
  lwz       r12, 0x0(r3)
  mr        r4, r29
  lwz       r12, 0xF8(r12)
  mtlr      r12
  blrl      

.loc_0x68:
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0x70:
  lwz       r0, 0x2C(r28)
  cmpw      r30, r0
  blt+      .loc_0x30
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  lwz       r28, 0x20(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E12F8
 * Size:	000090
 */
void MonoObjectMgr::refresh(Graphics &)
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
  b         .loc_0x64

.loc_0x30:
  lwz       r3, 0x34(r28)
  lwzx      r0, r3, r31
  cmpwi     r0, 0
  bne-      .loc_0x5C
  lwz       r3, 0x28(r28)
  mr        r4, r29
  lwzx      r3, r3, r31
  lwz       r12, 0x0(r3)
  lwz       r12, 0xEC(r12)
  mtlr      r12
  blrl      

.loc_0x5C:
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0x64:
  lwz       r0, 0x2C(r28)
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
 * Address:	800E1388
 * Size:	0000EC
 */
void MonoObjectMgr::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  li        r30, 0
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  b         .loc_0xC4

.loc_0x28:
  lwz       r3, 0x34(r29)
  lwzx      r0, r3, r31
  cmpwi     r0, 0
  bne-      .loc_0x50
  lwz       r3, 0x28(r29)
  lwzx      r3, r3, r31
  lwz       r12, 0x0(r3)
  lwz       r12, 0xE0(r12)
  mtlr      r12
  blrl      

.loc_0x50:
  lwz       r3, 0x34(r29)
  lwzx      r5, r3, r31
  cmpwi     r5, -0x2
  bne-      .loc_0x98
  lwz       r3, 0x28(r29)
  lwzx      r4, r3, r31
  lwz       r0, 0x4(r4)
  cmpwi     r0, 0
  bne-      .loc_0x98
  lwz       r12, 0x0(r29)
  mr        r3, r29
  lwz       r12, 0x7C(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x34(r29)
  li        r0, -0x1
  stwx      r0, r3, r31
  b         .loc_0xBC

.loc_0x98:
  cmpwi     r5, -0x2
  bne-      .loc_0xBC
  lwz       r3, 0x28(r29)
  lwzx      r3, r3, r31
  lwz       r3, 0x6C(r3)
  bl        -0x4C9FC
  lwz       r3, 0x28(r29)
  lwzx      r3, r3, r31
  bl        0x2F10

.loc_0xBC:
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0xC4:
  lwz       r0, 0x2C(r29)
  cmpw      r30, r0
  blt+      .loc_0x28
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void MonoObjectMgr::getEmptyIndex()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void MonoObjectMgr::getIndex(Creature *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E1474
 * Size:	0000AC
 */
void MonoObjectMgr::birth()
{
/*
.loc_0x0:
  lwz       r0, 0x30(r3)
  lwz       r4, 0x2C(r3)
  cmpw      r0, r4
  blt-      .loc_0x3C
  cmpwi     r4, 0
  mtctr     r4
  li        r5, 0
  ble-      .loc_0x34

.loc_0x20:
  lwz       r4, 0x34(r3)
  lwzx      r0, r4, r5
  cmpwi     r0, -0x2
  addi      r5, r5, 0x4
  bdnz+     .loc_0x20

.loc_0x34:
  li        r3, 0
  blr       

.loc_0x3C:
  cmpwi     r4, 0
  mtctr     r4
  li        r5, 0
  addi      r6, r5, 0
  ble-      .loc_0x70

.loc_0x50:
  lwz       r4, 0x34(r3)
  lwzx      r0, r4, r6
  cmpwi     r0, -0x1
  bne-      .loc_0x64
  b         .loc_0x74

.loc_0x64:
  addi      r6, r6, 0x4
  addi      r5, r5, 0x1
  bdnz+     .loc_0x50

.loc_0x70:
  li        r5, -0x1

.loc_0x74:
  cmpwi     r5, -0x1
  bne-      .loc_0x84
  li        r3, 0
  blr       

.loc_0x84:
  lwz       r4, 0x34(r3)
  rlwinm    r5,r5,2,0,29
  li        r0, 0
  stwx      r0, r4, r5
  lwz       r4, 0x30(r3)
  addi      r0, r4, 0x1
  stw       r0, 0x30(r3)
  lwz       r3, 0x28(r3)
  lwzx      r3, r3, r5
  blr
*/
}

/*
 * --INFO--
 * Address:	800E1520
 * Size:	000084
 */
void MonoObjectMgr::kill(Creature *)
{
/*
.loc_0x0:
  lwz       r0, 0x2C(r3)
  li        r6, 0
  addi      r7, r6, 0
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x38

.loc_0x18:
  lwz       r5, 0x28(r3)
  lwzx      r0, r5, r7
  cmplw     r0, r4
  bne-      .loc_0x2C
  b         .loc_0x3C

.loc_0x2C:
  addi      r7, r7, 0x4
  addi      r6, r6, 0x1
  bdnz+     .loc_0x18

.loc_0x38:
  li        r6, -0x1

.loc_0x3C:
  cmpwi     r6, -0x1
  beqlr-    
  lwz       r0, 0x4(r4)
  cmpwi     r0, 0
  beq-      .loc_0x64
  lwz       r3, 0x34(r3)
  rlwinm    r0,r6,2,0,29
  li        r4, -0x2
  stwx      r4, r3, r0
  blr       

.loc_0x64:
  lwz       r5, 0x30(r3)
  rlwinm    r0,r6,2,0,29
  li        r4, -0x1
  subi      r5, r5, 0x1
  stw       r5, 0x30(r3)
  lwz       r3, 0x34(r3)
  stwx      r4, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E15A4
 * Size:	00003C
 */
void MonoObjectMgr::getCreature(int)
{
/*
.loc_0x0:
  cmpwi     r4, 0
  blt-      .loc_0x28
  lwz       r0, 0x2C(r3)
  cmpw      r4, r0
  bge-      .loc_0x28
  lwz       r5, 0x34(r3)
  rlwinm    r4,r4,2,0,29
  lwzx      r0, r5, r4
  cmpwi     r0, 0
  beq-      .loc_0x30

.loc_0x28:
  li        r3, 0
  blr       

.loc_0x30:
  lwz       r3, 0x28(r3)
  lwzx      r3, r3, r4
  blr
*/
}

/*
 * --INFO--
 * Address:	800E15E0
 * Size:	000058
 */
void MonoObjectMgr::getFirst()
{
/*
.loc_0x0:
  lwz       r6, 0x2C(r3)
  li        r7, -0x1
  li        r8, 0
  cmpwi     r6, 0
  mtctr     r6
  li        r5, 0
  ble-      .loc_0x40

.loc_0x1C:
  lwz       r4, 0x34(r3)
  lwzx      r0, r4, r5
  cmpwi     r0, 0
  bne-      .loc_0x34
  mr        r7, r8
  b         .loc_0x40

.loc_0x34:
  addi      r5, r5, 0x4
  addi      r8, r8, 0x1
  bdnz+     .loc_0x1C

.loc_0x40:
  cmpwi     r7, -0x1
  bne-      .loc_0x50
  mr        r3, r6
  blr       

.loc_0x50:
  mr        r3, r7
  blr
*/
}

/*
 * --INFO--
 * Address:	800E1638
 * Size:	00005C
 */
void MonoObjectMgr::getNext(int)
{
/*
.loc_0x0:
  lwz       r6, 0x2C(r3)
  addi      r8, r4, 0x1
  rlwinm    r5,r8,2,0,29
  sub       r0, r6, r8
  cmpw      r8, r6
  mtctr     r0
  li        r7, -0x1
  bge-      .loc_0x44

.loc_0x20:
  lwz       r4, 0x34(r3)
  lwzx      r0, r4, r5
  cmpwi     r0, 0
  bne-      .loc_0x38
  mr        r7, r8
  b         .loc_0x44

.loc_0x38:
  addi      r5, r5, 0x4
  addi      r8, r8, 0x1
  bdnz+     .loc_0x20

.loc_0x44:
  cmpwi     r7, -0x1
  bne-      .loc_0x54
  mr        r3, r6
  blr       

.loc_0x54:
  mr        r3, r7
  blr
*/
}

/*
 * --INFO--
 * Address:	800E1694
 * Size:	00001C
 */
void MonoObjectMgr::isDone(int)
{
/*
.loc_0x0:
  lwz       r0, 0x2C(r3)
  cmpw      r4, r0
  blt-      .loc_0x14
  li        r3, 0x1
  blr       

.loc_0x14:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E16B0
 * Size:	000388
 */
void MonoObjectMgr::search(ObjectMgr *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stfd      f31, 0x58(r1)
  stfd      f30, 0x50(r1)
  stfd      f29, 0x48(r1)
  stmw      r25, 0x2C(r1)
  addi      r25, r3, 0
  cmplw     r4, r25
  bne-      .loc_0x34
  mr        r3, r25
  bl        .loc_0x388
  b         .loc_0x368

.loc_0x34:
  lfs       f31, -0x6738(r2)
  addi      r30, r4, 0
  li        r27, 0
  li        r28, 0
  b         .loc_0x35C

.loc_0x48:
  lwz       r3, 0x34(r25)
  lwzx      r0, r3, r28
  cmpwi     r0, 0
  bne-      .loc_0x354
  lbz       r0, -0x5F07(r13)
  lwz       r3, 0x28(r25)
  cmplwi    r0, 0
  lwzx      r26, r3, r28
  beq-      .loc_0x7C
  addi      r3, r26, 0x168
  bl        -0x3C2C8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x354

.loc_0x7C:
  lwz       r0, 0x6C(r26)
  li        r3, 0
  cmpwi     r0, 0
  beq-      .loc_0x94
  cmpwi     r0, 0x36
  bne-      .loc_0x98

.loc_0x94:
  li        r3, 0x1

.loc_0x98:
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0xBC
  addi      r3, r26, 0x40
  bl        -0x4D5C4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xBC
  lwz       r0, 0xC8(r26)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x354

.loc_0xBC:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  b         .loc_0x2F8

.loc_0xD8:
  cmpwi     r29, -0x1
  bne-      .loc_0x100
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0x11C

.loc_0x100:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0x11C:
  lbz       r0, 0x2FAC(r13)
  cmplwi    r0, 0
  beq-      .loc_0x148
  addi      r3, r26, 0x168
  bl        -0x3C384
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x148
  addi      r3, r31, 0x168
  bl        -0x3C394
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2DC

.loc_0x148:
  lwz       r0, 0x6C(r31)
  li        r3, 0
  cmpwi     r0, 0
  beq-      .loc_0x160
  cmpwi     r0, 0x36
  bne-      .loc_0x164

.loc_0x160:
  li        r3, 0x1

.loc_0x164:
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x188
  addi      r3, r31, 0x40
  bl        -0x4D690
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x188
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x2DC

.loc_0x188:
  lwz       r0, -0x5F10(r13)
  cmpwi     r0, 0
  beq-      .loc_0x1D8
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  mr        r3, r26
  fmr       f29, f1
  lwz       r12, 0x0(r26)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  fadds     f1, f1, f29
  addi      r3, r26, 0x40
  addi      r4, r31, 0x40
  bl        -0x4D48C
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x2DC

.loc_0x1D8:
  addi      r3, r26, 0
  addi      r4, r31, 0
  bl        -0x55E60
  mr        r3, r31
  fmr       f29, f1
  lwz       r12, 0x0(r31)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  mr        r3, r26
  fmr       f30, f1
  lwz       r12, 0x0(r26)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  fadds     f0, f1, f30
  fsubs     f29, f29, f0
  fcmpo     cr0, f29, f31
  cror      2, 0, 0x2
  bne-      .loc_0x27C
  mr        r3, r26
  lwz       r12, 0x0(r26)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x27C
  lwz       r0, 0x1CC(r26)
  cmplwi    r0, 0
  beq-      .loc_0x27C
  lbz       r0, 0x2FAC(r13)
  cmplwi    r0, 0
  beq-      .loc_0x26C
  addi      r3, r26, 0x168
  bl        -0x3C4B8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x27C

.loc_0x26C:
  fmr       f1, f29
  addi      r4, r31, 0
  addi      r3, r26, 0x1B8
  bl        0x27B4

.loc_0x27C:
  fcmpo     cr0, f29, f31
  cror      2, 0, 0x2
  bne-      .loc_0x2DC
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2DC
  lwz       r0, 0x1CC(r31)
  cmplwi    r0, 0
  beq-      .loc_0x2DC
  lbz       r0, 0x2FAC(r13)
  cmplwi    r0, 0
  beq-      .loc_0x2CC
  addi      r3, r31, 0x168
  bl        -0x3C518
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2DC

.loc_0x2CC:
  fmr       f1, f29
  addi      r4, r26, 0
  addi      r3, r31, 0x1B8
  bl        0x2754

.loc_0x2DC:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0x2F8:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x320
  li        r0, 0x1
  b         .loc_0x34C

.loc_0x320:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x348
  li        r0, 0x1
  b         .loc_0x34C

.loc_0x348:
  li        r0, 0

.loc_0x34C:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0xD8

.loc_0x354:
  addi      r28, r28, 0x4
  addi      r27, r27, 0x1

.loc_0x35C:
  lwz       r0, 0x2C(r25)
  cmpw      r27, r0
  blt+      .loc_0x48

.loc_0x368:
  lmw       r25, 0x2C(r1)
  lwz       r0, 0x64(r1)
  lfd       f31, 0x58(r1)
  lfd       f30, 0x50(r1)
  lfd       f29, 0x48(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr       

.loc_0x388:
*/
}

/*
 * --INFO--
 * Address:	800E1A38
 * Size:	00030C
 */
void MonoObjectMgr::searchSelf()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stfd      f31, 0x50(r1)
  stfd      f30, 0x48(r1)
  stfd      f29, 0x40(r1)
  stmw      r23, 0x1C(r1)
  addi      r24, r3, 0
  li        r29, 0
  li        r28, 0
  li        r30, 0
  lfs       f31, -0x6738(r2)
  b         .loc_0x2DC

.loc_0x34:
  lwz       r3, 0x34(r24)
  lwzx      r0, r3, r30
  cmpwi     r0, 0
  bne-      .loc_0x2D4
  lwz       r3, 0x28(r24)
  li        r4, 0
  lwzx      r3, r3, r30
  lwz       r0, 0x6C(r3)
  addi      r27, r3, 0
  cmpwi     r0, 0
  beq-      .loc_0x68
  cmpwi     r0, 0x36
  bne-      .loc_0x88

.loc_0x68:
  lbz       r0, -0x5F05(r13)
  li        r4, 0x1
  cmplwi    r0, 0
  beq-      .loc_0x88
  lwz       r0, 0x6C(r27)
  cmpwi     r0, 0
  bne-      .loc_0x88
  li        r29, 0x1

.loc_0x88:
  rlwinm.   r0,r4,0,24,31
  bne-      .loc_0xAC
  addi      r3, r27, 0x40
  bl        -0x4D93C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xAC
  lwz       r0, 0xC8(r27)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x2D4

.loc_0xAC:
  addi      r26, r28, 0x1
  rlwinm    r31,r26,2,0,29
  rlwinm    r23,r29,0,24,31
  b         .loc_0x2C8

.loc_0xBC:
  lwz       r3, 0x34(r24)
  lwzx      r0, r3, r31
  cmpwi     r0, 0
  bne-      .loc_0x2C0
  lwz       r3, 0x28(r24)
  cmplwi    r23, 0
  lwzx      r25, r3, r31
  bne-      .loc_0xE8
  lbz       r0, 0x2FAC(r13)
  cmplwi    r0, 0
  beq-      .loc_0x108

.loc_0xE8:
  addi      r3, r27, 0x168
  bl        -0x3C6CC
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x108
  addi      r3, r25, 0x168
  bl        -0x3C6DC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2C0

.loc_0x108:
  lwz       r0, 0x6C(r25)
  li        r3, 0
  cmpwi     r0, 0
  beq-      .loc_0x120
  cmpwi     r0, 0x36
  bne-      .loc_0x124

.loc_0x120:
  li        r3, 0x1

.loc_0x124:
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x148
  addi      r3, r25, 0x40
  bl        -0x4D9D8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x148
  lwz       r0, 0xC8(r25)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x2C0

.loc_0x148:
  lwz       r0, -0x5F10(r13)
  cmpwi     r0, 0
  beq-      .loc_0x198
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  mr        r3, r27
  fmr       f29, f1
  lwz       r12, 0x0(r27)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  fadds     f1, f1, f29
  addi      r3, r27, 0x40
  addi      r4, r25, 0x40
  bl        -0x4D7D4
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x2C0

.loc_0x198:
  addi      r3, r27, 0
  addi      r4, r25, 0
  bl        -0x561A8
  mr        r3, r25
  fmr       f29, f1
  lwz       r12, 0x0(r25)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  mr        r3, r27
  fmr       f30, f1
  lwz       r12, 0x0(r27)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  fadds     f0, f1, f30
  fsubs     f0, f29, f0
  fcmpo     cr0, f0, f31
  fmr       f29, f0
  cror      2, 0, 0x2
  bne-      .loc_0x2C0
  mr        r3, r27
  lwz       r12, 0x0(r27)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2C0
  mr        r3, r27
  lwz       r12, 0x0(r27)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x264
  lwz       r0, 0x1CC(r27)
  cmplwi    r0, 0
  beq-      .loc_0x264
  lbz       r0, 0x2FAC(r13)
  cmplwi    r0, 0
  bne-      .loc_0x244
  cmplwi    r23, 0
  beq-      .loc_0x254

.loc_0x244:
  addi      r3, r27, 0x168
  bl        -0x3C828
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x264

.loc_0x254:
  fmr       f1, f29
  addi      r4, r25, 0
  addi      r3, r27, 0x1B8
  bl        0x2444

.loc_0x264:
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2C0
  lwz       r0, 0x1CC(r25)
  cmplwi    r0, 0
  beq-      .loc_0x2C0
  lbz       r0, 0x2FAC(r13)
  cmplwi    r0, 0
  bne-      .loc_0x2A0
  cmplwi    r23, 0
  beq-      .loc_0x2B0

.loc_0x2A0:
  addi      r3, r25, 0x168
  bl        -0x3C884
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2C0

.loc_0x2B0:
  fmr       f1, f29
  addi      r4, r27, 0
  addi      r3, r25, 0x1B8
  bl        0x23E8

.loc_0x2C0:
  addi      r31, r31, 0x4
  addi      r26, r26, 0x1

.loc_0x2C8:
  lwz       r0, 0x2C(r24)
  cmpw      r26, r0
  blt+      .loc_0xBC

.loc_0x2D4:
  addi      r30, r30, 0x4
  addi      r28, r28, 0x1

.loc_0x2DC:
  lwz       r3, 0x2C(r24)
  subi      r0, r3, 0x1
  cmpw      r28, r0
  blt+      .loc_0x34
  lmw       r23, 0x1C(r1)
  lwz       r0, 0x5C(r1)
  lfd       f31, 0x50(r1)
  lfd       f30, 0x48(r1)
  lfd       f29, 0x40(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E1D44
 * Size:	000260
 */
PolyObjectMgr::PolyObjectMgr(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stmw      r18, 0x18(r1)
  addi      r30, r4, 0
  li        r31, 0
  subi      r4, r13, 0x38D8
  stw       r3, 0x8(r1)
  lis       r3, 0x802B
  subi      r0, r3, 0x2374
  lwz       r18, 0x8(r1)
  stw       r0, 0x0(r18)
  addi      r3, r18, 0x8
  stw       r31, 0x4(r18)
  bl        -0xACDC4
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x8(r18)
  addi      r3, r18, 0x8
  subi      r4, r13, 0x38D8
  bl        -0xA1658
  lis       r3, 0x802C
  subi      r3, r3, 0x4F80
  stw       r3, 0x0(r18)
  addi      r0, r3, 0x18
  lis       r3, 0x802C
  stw       r0, 0x8(r18)
  subi      r3, r3, 0x50F4
  addi      r0, r3, 0x18
  stw       r3, 0x0(r18)
  mulli     r3, r30, 0xC
  stw       r0, 0x8(r18)
  stw       r31, 0x38(r18)
  stw       r31, 0x44(r18)
  stw       r30, 0x40(r18)
  bl        -0x9ADCC
  cmpwi     r30, 0
  stw       r3, 0x48(r18)
  li        r5, 0
  ble-      .loc_0x23C
  cmpwi     r30, 0x8
  subi      r3, r30, 0x8
  ble-      .loc_0x244
  addi      r0, r3, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r3, 0
  mtctr     r0
  ble-      .loc_0x244

.loc_0xC0:
  lwz       r3, 0x8(r1)
  li        r4, 0
  addi      r10, r31, 0x4
  lwz       r6, 0x48(r3)
  addi      r9, r31, 0x8
  li        r0, -0x1
  stwx      r4, r6, r31
  addi      r8, r31, 0xC
  addi      r7, r31, 0x10
  lwz       r11, 0x48(r3)
  addi      r6, r31, 0x14
  addi      r19, r31, 0x18
  stwx      r4, r11, r10
  addi      r20, r31, 0x1C
  addi      r21, r31, 0x20
  lwz       r10, 0x48(r3)
  addi      r22, r31, 0x24
  addi      r23, r31, 0x28
  stwx      r0, r10, r9
  addi      r24, r31, 0x2C
  addi      r25, r31, 0x30
  lwz       r9, 0x48(r3)
  addi      r26, r31, 0x34
  addi      r27, r31, 0x38
  stwx      r4, r9, r8
  addi      r28, r31, 0x3C
  addi      r29, r31, 0x40
  lwz       r8, 0x48(r3)
  addi      r12, r31, 0x44
  addi      r11, r31, 0x48
  stwx      r4, r8, r7
  addi      r10, r31, 0x4C
  addi      r9, r31, 0x50
  lwz       r18, 0x48(r3)
  addi      r8, r31, 0x54
  addi      r7, r31, 0x58
  stwx      r0, r18, r6
  addi      r6, r31, 0x5C
  addi      r31, r31, 0x60
  lwz       r18, 0x48(r3)
  addi      r5, r5, 0x8
  stwx      r4, r18, r19
  lwz       r19, 0x48(r3)
  stwx      r4, r19, r20
  lwz       r20, 0x48(r3)
  stwx      r0, r20, r21
  lwz       r21, 0x48(r3)
  stwx      r4, r21, r22
  lwz       r22, 0x48(r3)
  stwx      r4, r22, r23
  lwz       r23, 0x48(r3)
  stwx      r0, r23, r24
  lwz       r24, 0x48(r3)
  stwx      r4, r24, r25
  lwz       r25, 0x48(r3)
  stwx      r4, r25, r26
  lwz       r26, 0x48(r3)
  stwx      r0, r26, r27
  lwz       r27, 0x48(r3)
  stwx      r4, r27, r28
  lwz       r28, 0x48(r3)
  stwx      r4, r28, r29
  lwz       r29, 0x48(r3)
  stwx      r0, r29, r12
  lwz       r12, 0x48(r3)
  stwx      r4, r12, r11
  lwz       r11, 0x48(r3)
  stwx      r4, r11, r10
  lwz       r10, 0x48(r3)
  stwx      r0, r10, r9
  lwz       r9, 0x48(r3)
  stwx      r4, r9, r8
  lwz       r8, 0x48(r3)
  stwx      r4, r8, r7
  lwz       r3, 0x48(r3)
  stwx      r0, r3, r6
  bdnz+     .loc_0xC0
  b         .loc_0x244

.loc_0x1F8:
  sub       r0, r30, r5
  cmpw      r5, r30
  mtctr     r0
  li        r7, 0
  li        r4, -0x1
  bge-      .loc_0x23C

.loc_0x210:
  lwz       r6, 0x8(r1)
  addi      r3, r8, 0x4
  addi      r0, r8, 0x8
  lwz       r5, 0x48(r6)
  stwx      r7, r5, r8
  addi      r8, r8, 0xC
  lwz       r5, 0x48(r6)
  stwx      r7, r5, r3
  lwz       r3, 0x48(r6)
  stwx      r4, r3, r0
  bdnz+     .loc_0x210

.loc_0x23C:
  lwz       r3, 0x8(r1)
  b         .loc_0x24C

.loc_0x244:
  mulli     r8, r5, 0xC
  b         .loc_0x1F8

.loc_0x24C:
  lmw       r18, 0x18(r1)
  lwz       r0, 0x54(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E1FA4
 * Size:	00007C
 */
void PolyObjectMgr::create(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  li        r31, 0
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  stw       r31, 0x30(r3)
  stw       r4, 0x2C(r3)
  lwz       r0, 0x2C(r3)
  rlwinm    r3,r0,2,0,29
  bl        -0x9AFCC
  stw       r3, 0x3C(r30)
  li        r5, 0
  li        r4, -0x1
  b         .loc_0x50

.loc_0x40:
  lwz       r3, 0x3C(r30)
  addi      r5, r5, 0x1
  stwx      r4, r3, r31
  addi      r31, r31, 0x4

.loc_0x50:
  lwz       r0, 0x2C(r30)
  cmpw      r5, r0
  blt+      .loc_0x40
  li        r0, 0
  stw       r0, 0x28(r30)
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
 * Address:	800E2020
 * Size:	000108
 */
void PolyObjectMgr::update()
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
  addi      r29, r3, 0
  b         .loc_0xE0

.loc_0x28:
  lwz       r3, 0x3C(r29)
  lwzx      r0, r3, r31
  cmpwi     r0, 0
  blt-      .loc_0x5C
  addi      r3, r29, 0
  addi      r4, r30, 0
  bl        0x3AC
  cmplwi    r3, 0
  beq-      .loc_0x5C
  lwz       r12, 0x0(r3)
  lwz       r12, 0xE0(r12)
  mtlr      r12
  blrl      

.loc_0x5C:
  lwz       r3, 0x3C(r29)
  lwzx      r0, r3, r31
  cmpwi     r0, -0x2
  bne-      .loc_0xB8
  addi      r3, r29, 0
  addi      r4, r30, 0
  bl        0x378
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0
  bne-      .loc_0xB8
  addi      r3, r29, 0
  addi      r4, r30, 0
  bl        0x360
  addi      r3, r29, 0
  addi      r4, r30, 0
  bl        0x354
  lwz       r12, 0x0(r29)
  addi      r4, r3, 0
  addi      r3, r29, 0
  lwz       r12, 0x7C(r12)
  mtlr      r12
  blrl      
  b         .loc_0xD8

.loc_0xB8:
  lwz       r3, 0x3C(r29)
  lwzx      r0, r3, r31
  cmpwi     r0, -0x2
  bne-      .loc_0xD8
  addi      r3, r29, 0
  addi      r4, r30, 0
  bl        0x31C
  bl        0x225C

.loc_0xD8:
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0xE0:
  lwz       r0, 0x2C(r29)
  cmpw      r30, r0
  blt+      .loc_0x28
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
 * Address:	800E2128
 * Size:	0000AC
 */
void PolyObjectMgr::postUpdate(int, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stfd      f31, 0x28(r1)
  fmr       f31, f1
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  li        r30, 0
  stw       r29, 0x1C(r1)
  addi      r29, r4, 0
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  b         .loc_0x7C

.loc_0x38:
  lwz       r3, 0x3C(r28)
  lwzx      r0, r3, r31
  cmpwi     r0, 0
  blt-      .loc_0x74
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x294
  cmplwi    r3, 0
  beq-      .loc_0x74
  lwz       r12, 0x0(r3)
  fmr       f1, f31
  mr        r4, r29
  lwz       r12, 0xE4(r12)
  mtlr      r12
  blrl      

.loc_0x74:
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0x7C:
  lwz       r0, 0x2C(r28)
  cmpw      r30, r0
  blt+      .loc_0x38
  lwz       r0, 0x34(r1)
  lfd       f31, 0x28(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E21D4
 * Size:	00009C
 */
void PolyObjectMgr::refresh(Graphics &)
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
  b         .loc_0x70

.loc_0x30:
  lwz       r3, 0x3C(r28)
  lwzx      r0, r3, r31
  cmpwi     r0, 0
  blt-      .loc_0x68
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x1F0
  cmplwi    r3, 0
  beq-      .loc_0x68
  lwz       r12, 0x0(r3)
  mr        r4, r29
  lwz       r12, 0xEC(r12)
  mtlr      r12
  blrl      

.loc_0x68:
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0x70:
  lwz       r0, 0x2C(r28)
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
 * Address:	800E2270
 * Size:	0000A8
 */
void PolyObjectMgr::drawShadow(Graphics &, Texture *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  li        r31, 0
  stw       r30, 0x20(r1)
  li        r30, 0
  stw       r29, 0x1C(r1)
  addi      r29, r4, 0
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  b         .loc_0x7C

.loc_0x30:
  lwz       r3, 0x3C(r28)
  lwzx      r0, r3, r31
  cmpwi     r0, 0
  blt-      .loc_0x74
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x154
  cmplwi    r3, 0
  beq-      .loc_0x74
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x74
  lwz       r12, 0x0(r3)
  mr        r4, r29
  lwz       r12, 0xF8(r12)
  mtlr      r12
  blrl      

.loc_0x74:
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0x7C:
  lwz       r0, 0x2C(r28)
  cmpw      r30, r0
  blt+      .loc_0x30
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2318
 * Size:	000004
 */
void PolyObjectMgr::beginRegister()
{
}

/*
 * --INFO--
 * Address:	800E231C
 * Size:	000088
 */
void PolyObjectMgr::registerClass(int, Creature *, int)
{
/*
.loc_0x0:
  lwz       r0, 0x40(r3)
  li        r8, 0
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x30

.loc_0x14:
  lwz       r7, 0x48(r3)
  addi      r0, r8, 0x8
  lwzx      r0, r7, r0
  cmpw      r4, r0
  beqlr-    
  addi      r8, r8, 0xC
  bdnz+     .loc_0x14

.loc_0x30:
  lwz       r0, 0x28(r3)
  cmpw      r0, r6
  bge-      .loc_0x40
  stw       r6, 0x28(r3)

.loc_0x40:
  lwz       r0, 0x44(r3)
  lwz       r7, 0x48(r3)
  mulli     r0, r0, 0xC
  stwx      r5, r7, r0
  lwz       r0, 0x44(r3)
  lwz       r5, 0x48(r3)
  mulli     r0, r0, 0xC
  add       r5, r5, r0
  stw       r6, 0x4(r5)
  lwz       r0, 0x44(r3)
  lwz       r5, 0x48(r3)
  mulli     r0, r0, 0xC
  add       r5, r5, r0
  stw       r4, 0x8(r5)
  lwz       r4, 0x44(r3)
  addi      r0, r4, 0x1
  stw       r0, 0x44(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800E23A4
 * Size:	000068
 */
void PolyObjectMgr::endRegister()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lwz       r3, 0x2C(r3)
  lwz       r0, 0x28(r31)
  mullw     r3, r3, r0
  bl        -0x9B3C0
  stw       r3, 0x38(r31)
  li        r5, 0
  li        r4, 0xFF
  b         .loc_0x40

.loc_0x34:
  lwz       r3, 0x38(r31)
  stbx      r4, r3, r5
  addi      r5, r5, 0x1

.loc_0x40:
  lwz       r3, 0x2C(r31)
  lwz       r0, 0x28(r31)
  mullw     r0, r3, r0
  cmpw      r5, r0
  blt+      .loc_0x34
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
void PolyObjectMgr::getEmptyIndex()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void PolyObjectMgr::getIndex(Creature *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void PolyObjectMgr::getTemplateIndex(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E240C
 * Size:	000014
 */
void PolyObjectMgr::get(int)
{
/*
.loc_0x0:
  lwz       r0, 0x28(r3)
  lwz       r3, 0x38(r3)
  mullw     r0, r0, r4
  add       r3, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2420
 * Size:	00011C
 */
void PolyObjectMgr::birth(int)
{
/*
.loc_0x0:
  lwz       r0, 0x30(r3)
  lwz       r8, 0x2C(r3)
  cmpw      r0, r8
  blt-      .loc_0x18
  li        r3, 0
  blr       

.loc_0x18:
  lwz       r0, 0x40(r3)
  li        r6, 0
  addi      r7, r6, 0
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x54

.loc_0x30:
  lwz       r5, 0x48(r3)
  addi      r0, r7, 0x8
  lwzx      r0, r5, r0
  cmpw      r4, r0
  bne-      .loc_0x48
  b         .loc_0x58

.loc_0x48:
  addi      r7, r7, 0xC
  addi      r6, r6, 0x1
  bdnz+     .loc_0x30

.loc_0x54:
  li        r6, -0x1

.loc_0x58:
  cmpwi     r6, -0x1
  bne-      .loc_0x68
  li        r3, 0
  blr       

.loc_0x68:
  cmpwi     r8, 0
  mtctr     r8
  li        r10, 0
  addi      r7, r10, 0
  ble-      .loc_0x9C

.loc_0x7C:
  lwz       r5, 0x3C(r3)
  lwzx      r0, r5, r7
  cmpwi     r0, -0x1
  bne-      .loc_0x90
  b         .loc_0xA0

.loc_0x90:
  addi      r7, r7, 0x4
  addi      r10, r10, 0x1
  bdnz+     .loc_0x7C

.loc_0x9C:
  li        r10, -0x1

.loc_0xA0:
  cmpwi     r10, -0x1
  bne-      .loc_0xB0
  li        r3, 0
  blr       

.loc_0xB0:
  lwz       r0, 0x28(r3)
  mulli     r8, r6, 0xC
  lwz       r9, 0x48(r3)
  lwz       r7, 0x38(r3)
  mullw     r6, r0, r10
  lwz       r5, 0x3C(r3)
  rlwinm    r0,r10,2,0,29
  add       r6, r7, r6
  stwx      r4, r5, r0
  add       r7, r9, r8
  lwz       r5, 0x0(r7)
  addi      r4, r6, 0
  li        r8, 0
  b         .loc_0xFC

.loc_0xE8:
  lbz       r0, 0x0(r5)
  addi      r8, r8, 0x1
  addi      r5, r5, 0x1
  stb       r0, 0x0(r4)
  addi      r4, r4, 0x1

.loc_0xFC:
  lwz       r0, 0x4(r7)
  cmpw      r8, r0
  blt+      .loc_0xE8
  lwz       r4, 0x30(r3)
  addi      r0, r4, 0x1
  stw       r0, 0x30(r3)
  mr        r3, r6
  blr
*/
}

/*
 * --INFO--
 * Address:	800E253C
 * Size:	000080
 */
void PolyObjectMgr::kill(Creature *)
{
/*
.loc_0x0:
  lwz       r0, 0x2C(r3)
  li        r7, -0x1
  li        r6, 0
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x40

.loc_0x18:
  lwz       r0, 0x28(r3)
  lwz       r5, 0x38(r3)
  mullw     r0, r0, r6
  add       r0, r5, r0
  cmplw     r0, r4
  bne-      .loc_0x38
  mr        r7, r6
  b         .loc_0x40

.loc_0x38:
  addi      r6, r6, 0x1
  bdnz+     .loc_0x18

.loc_0x40:
  lwz       r0, 0x4(r4)
  cmpwi     r0, 0
  bne-      .loc_0x6C
  lwz       r4, 0x3C(r3)
  rlwinm    r0,r7,2,0,29
  li        r5, -0x1
  stwx      r5, r4, r0
  lwz       r4, 0x30(r3)
  subi      r0, r4, 0x1
  stw       r0, 0x30(r3)
  blr       

.loc_0x6C:
  lwz       r3, 0x3C(r3)
  rlwinm    r0,r7,2,0,29
  li        r4, -0x2
  stwx      r4, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E25BC
 * Size:	000044
 */
void PolyObjectMgr::getCreature(int)
{
/*
.loc_0x0:
  cmpwi     r4, 0
  blt-      .loc_0x28
  lwz       r0, 0x2C(r3)
  cmpw      r4, r0
  bge-      .loc_0x28
  lwz       r5, 0x3C(r3)
  rlwinm    r0,r4,2,0,29
  lwzx      r0, r5, r0
  cmpwi     r0, 0
  bge-      .loc_0x30

.loc_0x28:
  li        r3, 0
  blr       

.loc_0x30:
  lwz       r0, 0x28(r3)
  lwz       r3, 0x38(r3)
  mullw     r0, r0, r4
  add       r3, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2600
 * Size:	000058
 */
void PolyObjectMgr::getFirst()
{
/*
.loc_0x0:
  lwz       r6, 0x2C(r3)
  li        r7, -0x1
  li        r8, 0
  cmpwi     r6, 0
  mtctr     r6
  li        r5, 0
  ble-      .loc_0x40

.loc_0x1C:
  lwz       r4, 0x3C(r3)
  lwzx      r0, r4, r5
  cmpwi     r0, 0
  blt-      .loc_0x34
  mr        r7, r8
  b         .loc_0x40

.loc_0x34:
  addi      r5, r5, 0x4
  addi      r8, r8, 0x1
  bdnz+     .loc_0x1C

.loc_0x40:
  cmpwi     r7, -0x1
  bne-      .loc_0x50
  mr        r3, r6
  blr       

.loc_0x50:
  mr        r3, r7
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2658
 * Size:	00005C
 */
void PolyObjectMgr::getNext(int)
{
/*
.loc_0x0:
  lwz       r6, 0x2C(r3)
  addi      r8, r4, 0x1
  rlwinm    r5,r8,2,0,29
  sub       r0, r6, r8
  cmpw      r8, r6
  mtctr     r0
  li        r7, -0x1
  bge-      .loc_0x44

.loc_0x20:
  lwz       r4, 0x3C(r3)
  lwzx      r0, r4, r5
  cmpwi     r0, 0
  blt-      .loc_0x38
  mr        r7, r8
  b         .loc_0x44

.loc_0x38:
  addi      r5, r5, 0x4
  addi      r8, r8, 0x1
  bdnz+     .loc_0x20

.loc_0x44:
  cmpwi     r7, -0x1
  bne-      .loc_0x54
  mr        r3, r6
  blr       

.loc_0x54:
  mr        r3, r7
  blr
*/
}

/*
 * --INFO--
 * Address:	800E26B4
 * Size:	00001C
 */
void PolyObjectMgr::isDone(int)
{
/*
.loc_0x0:
  lwz       r0, 0x2C(r3)
  cmpw      r4, r0
  blt-      .loc_0x14
  li        r3, 0x1
  blr       

.loc_0x14:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E26D0
 * Size:	000028
 */
void PolyObjectMgr::search(ObjectMgr *)
{
/*
.loc_0x0:
  mflr      r0
  cmplw     r4, r3
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bne-      .loc_0x18
  bl        .loc_0x28

.loc_0x18:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr       

.loc_0x28:
*/
}

/*
 * --INFO--
 * Address:	800E26F8
 * Size:	0002C0
 */
void PolyObjectMgr::searchSelf()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stfd      f31, 0x48(r1)
  stfd      f30, 0x40(r1)
  stfd      f29, 0x38(r1)
  stmw      r25, 0x1C(r1)
  addi      r25, r3, 0
  li        r27, 0
  li        r29, 0
  lfs       f31, -0x6738(r2)
  b         .loc_0x290

.loc_0x30:
  lwz       r3, 0x3C(r25)
  lwzx      r0, r3, r29
  cmpwi     r0, 0
  blt-      .loc_0x288
  lwz       r0, 0x28(r25)
  li        r4, 0
  lwz       r3, 0x38(r25)
  mullw     r0, r0, r27
  add       r31, r3, r0
  lwz       r0, 0x6C(r31)
  cmpwi     r0, 0
  beq-      .loc_0x68
  cmpwi     r0, 0x36
  bne-      .loc_0x6C

.loc_0x68:
  li        r4, 0x1

.loc_0x6C:
  rlwinm.   r0,r4,0,24,31
  bne-      .loc_0x90
  addi      r3, r31, 0x40
  bl        -0x4E5E0
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x90
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x288

.loc_0x90:
  addi      r26, r27, 0x1
  rlwinm    r30,r26,2,0,29
  b         .loc_0x27C

.loc_0x9C:
  lwz       r3, 0x3C(r25)
  lwzx      r0, r3, r30
  cmpwi     r0, 0
  blt-      .loc_0x274
  lwz       r3, 0x28(r25)
  lbz       r0, 0x2FAC(r13)
  mullw     r3, r3, r26
  lwz       r4, 0x38(r25)
  cmplwi    r0, 0
  add       r28, r4, r3
  beq-      .loc_0xE8
  addi      r3, r31, 0x168
  bl        -0x3D36C
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0xE8
  addi      r3, r28, 0x168
  bl        -0x3D37C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x274

.loc_0xE8:
  lwz       r0, 0x6C(r28)
  li        r3, 0
  cmpwi     r0, 0
  beq-      .loc_0x100
  cmpwi     r0, 0x36
  bne-      .loc_0x104

.loc_0x100:
  li        r3, 0x1

.loc_0x104:
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x128
  addi      r3, r28, 0x40
  bl        -0x4E678
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x128
  lwz       r0, 0xC8(r28)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x274

.loc_0x128:
  lwz       r0, -0x5F10(r13)
  cmpwi     r0, 0
  beq-      .loc_0x178
  mr        r3, r28
  lwz       r12, 0x0(r28)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  fmr       f29, f1
  lwz       r12, 0x0(r31)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  fadds     f1, f1, f29
  addi      r3, r31, 0x40
  addi      r4, r28, 0x40
  bl        -0x4E474
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x274

.loc_0x178:
  addi      r3, r31, 0
  addi      r4, r28, 0
  bl        -0x56E48
  mr        r3, r28
  fmr       f29, f1
  lwz       r12, 0x0(r28)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  fmr       f30, f1
  lwz       r12, 0x0(r31)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  fadds     f0, f1, f30
  fsubs     f0, f29, f0
  fcmpo     cr0, f0, f31
  fmr       f29, f0
  cror      2, 0, 0x2
  bne-      .loc_0x274
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x220
  lwz       r0, 0x1CC(r31)
  cmplwi    r0, 0
  beq-      .loc_0x220
  lbz       r0, 0x2FAC(r13)
  cmplwi    r0, 0
  beq-      .loc_0x210
  addi      r3, r31, 0x168
  bl        -0x3D4A4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x220

.loc_0x210:
  fmr       f1, f29
  addi      r4, r28, 0
  addi      r3, r31, 0x1B8
  bl        0x17C8

.loc_0x220:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x274
  lwz       r0, 0x1CC(r28)
  cmplwi    r0, 0
  beq-      .loc_0x274
  lbz       r0, 0x2FAC(r13)
  cmplwi    r0, 0
  beq-      .loc_0x264
  addi      r3, r28, 0x168
  bl        -0x3D4F8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x274

.loc_0x264:
  fmr       f1, f29
  addi      r4, r31, 0
  addi      r3, r28, 0x1B8
  bl        0x1774

.loc_0x274:
  addi      r30, r30, 0x4
  addi      r26, r26, 0x1

.loc_0x27C:
  lwz       r0, 0x2C(r25)
  cmpw      r26, r0
  blt+      .loc_0x9C

.loc_0x288:
  addi      r29, r29, 0x4
  addi      r27, r27, 0x1

.loc_0x290:
  lwz       r3, 0x2C(r25)
  subi      r0, r3, 0x1
  cmpw      r27, r0
  blt+      .loc_0x30
  lmw       r25, 0x1C(r1)
  lwz       r0, 0x54(r1)
  lfd       f31, 0x48(r1)
  lfd       f30, 0x40(r1)
  lfd       f29, 0x38(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E29B8
 * Size:	000404
 */
void ObjectMgr::search(ObjectMgr *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x70(r1)
  stfd      f31, 0x68(r1)
  stfd      f30, 0x60(r1)
  stfd      f29, 0x58(r1)
  stmw      r26, 0x40(r1)
  mr        r29, r3
  mr        r26, r4
  lwz       r12, 0x0(r29)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f31, -0x6738(r2)
  addi      r28, r3, 0
  addi      r27, r26, 0
  b         .loc_0x388

.loc_0x44:
  cmpwi     r28, -0x1
  bne-      .loc_0x6C
  mr        r3, r29
  lwz       r12, 0x0(r29)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0x88

.loc_0x6C:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0x88:
  lwz       r4, 0x6C(r31)
  li        r3, 0
  addi      r0, r3, 0
  cmpwi     r4, 0
  beq-      .loc_0xA8
  cmpwi     r4, 0x36
  beq-      .loc_0xA8
  li        r0, 0x1

.loc_0xA8:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0xC0
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,11,11
  bne-      .loc_0xC0
  li        r3, 0x1

.loc_0xC0:
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xE4
  addi      r3, r31, 0x40
  bl        -0x4E8F4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xE4
  lwz       r0, 0xC8(r31)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x36C

.loc_0xE4:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r26, r3
  b         .loc_0x310

.loc_0x100:
  cmpwi     r26, -0x1
  bne-      .loc_0x128
  mr        r3, r27
  lwz       r12, 0x0(r27)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0x144

.loc_0x128:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r26
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x144:
  lwz       r4, 0x6C(r30)
  li        r3, 0
  addi      r0, r3, 0
  cmpwi     r4, 0
  beq-      .loc_0x164
  cmpwi     r4, 0x36
  beq-      .loc_0x164
  li        r0, 0x1

.loc_0x164:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x17C
  lwz       r0, 0xC8(r30)
  rlwinm.   r0,r0,0,11,11
  bne-      .loc_0x17C
  li        r3, 0x1

.loc_0x17C:
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1A0
  addi      r3, r30, 0x40
  bl        -0x4E9B0
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1A0
  lwz       r0, 0xC8(r30)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x2F4

.loc_0x1A0:
  lwz       r0, -0x5F10(r13)
  cmpwi     r0, 0
  beq-      .loc_0x1F0
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  fmr       f29, f1
  lwz       r12, 0x0(r31)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  fadds     f1, f1, f29
  addi      r3, r31, 0x40
  addi      r4, r30, 0x40
  bl        -0x4E7AC
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x2F4

.loc_0x1F0:
  addi      r3, r31, 0
  addi      r4, r30, 0
  bl        -0x57180
  mr        r3, r30
  fmr       f29, f1
  lwz       r12, 0x0(r30)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  fmr       f30, f1
  lwz       r12, 0x0(r31)
  lwz       r12, 0x64(r12)
  mtlr      r12
  blrl      
  fadds     f0, f1, f30
  fsubs     f29, f29, f0
  fcmpo     cr0, f29, f31
  cror      2, 0, 0x2
  bne-      .loc_0x294
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x294
  lwz       r0, 0x1CC(r31)
  cmplwi    r0, 0
  beq-      .loc_0x294
  lbz       r0, 0x2FAC(r13)
  cmplwi    r0, 0
  beq-      .loc_0x284
  addi      r3, r31, 0x168
  bl        -0x3D7D8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x294

.loc_0x284:
  fmr       f1, f29
  addi      r4, r30, 0
  addi      r3, r31, 0x1B8
  bl        0x1494

.loc_0x294:
  fcmpo     cr0, f29, f31
  cror      2, 0, 0x2
  bne-      .loc_0x2F4
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2F4
  lwz       r0, 0x1CC(r30)
  cmplwi    r0, 0
  beq-      .loc_0x2F4
  lbz       r0, 0x2FAC(r13)
  cmplwi    r0, 0
  beq-      .loc_0x2E4
  addi      r3, r30, 0x168
  bl        -0x3D838
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2F4

.loc_0x2E4:
  fmr       f1, f29
  addi      r4, r31, 0
  addi      r3, r30, 0x1B8
  bl        0x1434

.loc_0x2F4:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r26
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r26, r3

.loc_0x310:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r26
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x338
  li        r0, 0x1
  b         .loc_0x364

.loc_0x338:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r26
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x360
  li        r0, 0x1
  b         .loc_0x364

.loc_0x360:
  li        r0, 0

.loc_0x364:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x100

.loc_0x36C:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r28, r3

.loc_0x388:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x3B0
  li        r0, 0x1
  b         .loc_0x3DC

.loc_0x3B0:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x3D8
  li        r0, 0x1
  b         .loc_0x3DC

.loc_0x3D8:
  li        r0, 0

.loc_0x3DC:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x44
  lmw       r26, 0x40(r1)
  lwz       r0, 0x74(r1)
  lfd       f31, 0x68(r1)
  lfd       f30, 0x60(r1)
  lfd       f29, 0x58(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2DBC
 * Size:	000088
 */
void CreatureNodeMgr::getCreature(int)
{
/*
.loc_0x0:
  cmpwi     r4, 0
  lwz       r5, 0x38(r3)
  li        r6, 0
  ble-      .loc_0x70
  cmpwi     r4, 0x8
  subi      r3, r4, 0x8
  ble-      .loc_0x58
  addi      r0, r3, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r3, 0
  mtctr     r0
  ble-      .loc_0x58

.loc_0x30:
  lwz       r3, 0xC(r5)
  addi      r6, r6, 0x8
  lwz       r3, 0xC(r3)
  lwz       r3, 0xC(r3)
  lwz       r3, 0xC(r3)
  lwz       r3, 0xC(r3)
  lwz       r3, 0xC(r3)
  lwz       r3, 0xC(r3)
  lwz       r5, 0xC(r3)
  bdnz+     .loc_0x30

.loc_0x58:
  sub       r0, r4, r6
  cmpw      r6, r4
  mtctr     r0
  bge-      .loc_0x70

.loc_0x68:
  lwz       r5, 0xC(r5)
  bdnz+     .loc_0x68

.loc_0x70:
  cmplwi    r5, 0
  bne-      .loc_0x80
  li        r3, 0
  blr       

.loc_0x80:
  lwz       r3, 0x14(r5)
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2E44
 * Size:	000008
 */
u32  CreatureNodeMgr::getFirst()
{
	return 0x0;
}

/*
 * --INFO--
 * Address:	800E2E4C
 * Size:	000008
 */
void CreatureNodeMgr::getNext(int)
{
/*
.loc_0x0:
  addi      r3, r4, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2E54
 * Size:	000044
 */
void CreatureNodeMgr::isDone(int)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x28
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  bl        -0xA27EC
  cmpw      r31, r3
  blt-      .loc_0x2C
  li        r3, 0x1
  b         .loc_0x30

.loc_0x2C:
  li        r3, 0

.loc_0x30:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2E98
 * Size:	000024
 */
void CreatureNodeMgr::getSize()
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x28
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0xA2828
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2EBC
 * Size:	00006C
 */
CreatureNodeMgr::~CreatureNodeMgr()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  beq-      .loc_0x54
  lis       r3, 0x802C
  subi      r3, r3, 0x51A8
  stw       r3, 0x0(r31)
  addi      r0, r3, 0x18
  stw       r0, 0x8(r31)
  beq-      .loc_0x44
  lis       r3, 0x802C
  subi      r3, r3, 0x4F80
  stw       r3, 0x0(r31)
  addi      r0, r3, 0x18
  stw       r0, 0x8(r31)

.loc_0x44:
  extsh.    r0, r4
  ble-      .loc_0x54
  mr        r3, r31
  bl        -0x9BD60

.loc_0x54:
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2F28
 * Size:	000008
 */
void CreatureNodeMgr::getMax()
{
/*
.loc_0x0:
  lis       r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2F30
 * Size:	00006C
 */
PolyObjectMgr::~PolyObjectMgr()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  beq-      .loc_0x54
  lis       r3, 0x802C
  subi      r3, r3, 0x50F4
  stw       r3, 0x0(r31)
  addi      r0, r3, 0x18
  stw       r0, 0x8(r31)
  beq-      .loc_0x44
  lis       r3, 0x802C
  subi      r3, r3, 0x4F80
  stw       r3, 0x0(r31)
  addi      r0, r3, 0x18
  stw       r0, 0x8(r31)

.loc_0x44:
  extsh.    r0, r4
  ble-      .loc_0x54
  mr        r3, r31
  bl        -0x9BDD4

.loc_0x54:
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2F9C
 * Size:	000008
 */
void PolyObjectMgr::getSize()
{
/*
.loc_0x0:
  lwz       r3, 0x30(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2FA4
 * Size:	000008
 */
void PolyObjectMgr::getMax()
{
/*
.loc_0x0:
  lwz       r3, 0x2C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800E2FAC
 * Size:	000008
 */
void PolyObjectMgr::@8@update()
{
/*
.loc_0x0:
  subi      r3, r3, 0x8
  b         -0xF90
*/
}
