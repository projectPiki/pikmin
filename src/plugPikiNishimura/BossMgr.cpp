

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
 * Address:	8014FD88
 * Size:	00016C
 */
void BossMgr::getCreature(int)
{
/*
.loc_0x0:
  li        r0, 0x2
  mtctr     r0
  li        r8, 0
  li        r7, 0
  li        r6, 0

.loc_0x14:
  lwz       r5, 0x38(r3)
  addi      r0, r6, 0x10
  lwzx      r5, r5, r0
  b         .loc_0x3C

.loc_0x24:
  cmpw      r8, r4
  bne-      .loc_0x34
  lwz       r3, 0x14(r5)
  blr       

.loc_0x34:
  lwz       r5, 0xC(r5)
  addi      r8, r8, 0x1

.loc_0x3C:
  cmplwi    r5, 0
  bne+      .loc_0x24
  lwz       r5, 0x38(r3)
  addi      r0, r6, 0x28
  addi      r6, r6, 0x18
  lwzx      r5, r5, r0
  b         .loc_0x70

.loc_0x58:
  cmpw      r8, r4
  bne-      .loc_0x68
  lwz       r3, 0x14(r5)
  blr       

.loc_0x68:
  lwz       r5, 0xC(r5)
  addi      r8, r8, 0x1

.loc_0x70:
  cmplwi    r5, 0
  bne+      .loc_0x58
  lwz       r5, 0x38(r3)
  addi      r0, r6, 0x28
  addi      r7, r7, 0x1
  lwzx      r5, r5, r0
  addi      r6, r6, 0x18
  b         .loc_0xA8

.loc_0x90:
  cmpw      r8, r4
  bne-      .loc_0xA0
  lwz       r3, 0x14(r5)
  blr       

.loc_0xA0:
  lwz       r5, 0xC(r5)
  addi      r8, r8, 0x1

.loc_0xA8:
  cmplwi    r5, 0
  bne+      .loc_0x90
  lwz       r5, 0x38(r3)
  addi      r0, r6, 0x28
  addi      r7, r7, 0x1
  lwzx      r5, r5, r0
  addi      r6, r6, 0x18
  b         .loc_0xE0

.loc_0xC8:
  cmpw      r8, r4
  bne-      .loc_0xD8
  lwz       r3, 0x14(r5)
  blr       

.loc_0xD8:
  lwz       r5, 0xC(r5)
  addi      r8, r8, 0x1

.loc_0xE0:
  cmplwi    r5, 0
  bne+      .loc_0xC8
  lwz       r5, 0x38(r3)
  addi      r0, r6, 0x28
  addi      r7, r7, 0x1
  lwzx      r5, r5, r0
  addi      r6, r6, 0x18
  b         .loc_0x118

.loc_0x100:
  cmpw      r8, r4
  bne-      .loc_0x110
  lwz       r3, 0x14(r5)
  blr       

.loc_0x110:
  lwz       r5, 0xC(r5)
  addi      r8, r8, 0x1

.loc_0x118:
  cmplwi    r5, 0
  bne+      .loc_0x100
  lwz       r5, 0x38(r3)
  addi      r0, r6, 0x28
  addi      r7, r7, 0x1
  lwzx      r5, r5, r0
  addi      r6, r6, 0x18
  b         .loc_0x150

.loc_0x138:
  cmpw      r8, r4
  bne-      .loc_0x148
  lwz       r3, 0x14(r5)
  blr       

.loc_0x148:
  lwz       r5, 0xC(r5)
  addi      r8, r8, 0x1

.loc_0x150:
  cmplwi    r5, 0
  bne+      .loc_0x138
  addi      r6, r6, 0x18
  addi      r7, r7, 0x1
  bdnz+     .loc_0x14
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014FEF4
 * Size:	000008
 */
void BossMgr::getFirst()
{
/*
.loc_0x0:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014FEFC
 * Size:	000008
 */
void BossMgr::getNext(int)
{
/*
.loc_0x0:
  addi      r3, r4, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	8014FF04
 * Size:	00004C
 */
void BossMgr::isDone(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r4
  lwz       r12, 0x0(r3)
  lwz       r12, 0x60(r12)
  mtlr      r12
  blrl      
  cmpw      r31, r3
  blt-      .loc_0x34
  li        r3, 0x1
  b         .loc_0x38

.loc_0x34:
  li        r3, 0

.loc_0x38:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014FF50
 * Size:	000080
 */
void BossMgr::getSize()
{
/*
.loc_0x0:
  lwz       r6, 0x30(r3)
  li        r7, 0x8
  lwz       r5, 0x0(r6)
  lwz       r0, 0x4(r6)
  lwz       r4, 0x8(r6)
  add       r8, r5, r0
  lwz       r0, 0xC(r6)
  add       r8, r8, r4
  lwz       r4, 0x10(r6)
  add       r8, r8, r0
  lwz       r0, 0x14(r6)
  add       r8, r8, r4
  lwz       r4, 0x18(r6)
  add       r8, r8, r0
  lwz       r0, 0x1C(r6)
  add       r8, r8, r4
  add       r8, r8, r0
  b         .loc_0x74

.loc_0x48:
  subfic    r0, r7, 0xC
  cmpwi     r7, 0xC
  mtctr     r0
  bge-      .loc_0x6C

.loc_0x58:
  lwz       r4, 0x30(r3)
  lwzx      r0, r4, r5
  addi      r5, r5, 0x4
  add       r8, r8, r0
  bdnz+     .loc_0x58

.loc_0x6C:
  mr        r3, r8
  blr       

.loc_0x74:
  rlwinm    r5,r7,2,0,29
  b         .loc_0x48
  blr
*/
}

/*
 * --INFO--
 * Address:	8014FFD0
 * Size:	000080
 */
void BossMgr::getMax()
{
/*
.loc_0x0:
  lwz       r6, 0x34(r3)
  li        r7, 0x8
  lwz       r5, 0x0(r6)
  lwz       r0, 0x4(r6)
  lwz       r4, 0x8(r6)
  add       r8, r5, r0
  lwz       r0, 0xC(r6)
  add       r8, r8, r4
  lwz       r4, 0x10(r6)
  add       r8, r8, r0
  lwz       r0, 0x14(r6)
  add       r8, r8, r4
  lwz       r4, 0x18(r6)
  add       r8, r8, r0
  lwz       r0, 0x1C(r6)
  add       r8, r8, r4
  add       r8, r8, r0
  b         .loc_0x74

.loc_0x48:
  subfic    r0, r7, 0xC
  cmpwi     r7, 0xC
  mtctr     r0
  bge-      .loc_0x6C

.loc_0x58:
  lwz       r4, 0x34(r3)
  lwzx      r0, r4, r5
  addi      r5, r5, 0x4
  add       r8, r8, r0
  bdnz+     .loc_0x58

.loc_0x6C:
  mr        r3, r8
  blr       

.loc_0x74:
  rlwinm    r5,r7,2,0,29
  b         .loc_0x48
  blr
*/
}

/*
 * --INFO--
 * Address:	80150050
 * Size:	0002F4
 */
void BossMgr::BossMgr()
{
/*
.loc_0x0:
  mflr      r0
  subi      r4, r13, 0x438
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  stw       r3, 0x8(r1)
  lis       r3, 0x802B
  subi      r3, r3, 0x2374
  lwz       r31, 0x8(r1)
  stw       r3, 0x0(r31)
  addi      r3, r31, 0x8
  stw       r0, 0x4(r31)
  bl        -0x11B0D0
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x8(r31)
  addi      r3, r31, 0x8
  subi      r4, r13, 0x438
  bl        -0x10F964
  lis       r3, 0x802C
  subi      r3, r3, 0x4F80
  stw       r3, 0x0(r31)
  addi      r0, r3, 0x18
  lis       r3, 0x802D
  stw       r0, 0x8(r31)
  subi      r3, r3, 0xF20
  addi      r0, r3, 0x18
  stw       r3, 0x0(r31)
  li        r3, 0x30
  stw       r0, 0x8(r31)
  bl        -0x1090CC
  stw       r3, 0x30(r31)
  li        r3, 0x30
  bl        -0x1090D8
  stw       r3, 0x34(r31)
  li        r3, 0x128
  bl        -0x1090E4
  lis       r4, 0x8015
  addi      r30, r4, 0x344
  addi      r4, r30, 0
  li        r5, 0
  li        r6, 0x18
  li        r7, 0xC
  bl        0xC4B24
  stw       r3, 0x38(r31)
  li        r3, 0x128
  bl        -0x10910C
  addi      r4, r30, 0
  li        r5, 0
  li        r6, 0x18
  li        r7, 0xC
  bl        0xC4B04
  stw       r3, 0x3C(r31)
  li        r3, 0x24
  bl        -0x10912C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xF8
  mr        r4, r31
  bl        -0x6DC

.loc_0xF8:
  lwz       r31, 0x8(r1)
  stw       r30, 0x44(r31)
  bl        -0x304FC
  stw       r3, 0x50(r31)
  li        r3, 0x30
  bl        -0x109158
  stw       r3, 0x48(r31)
  li        r3, 0x30
  bl        -0x109164
  stw       r3, 0x4C(r31)
  li        r3, 0x30
  bl        -0x109170
  stw       r3, 0x40(r31)
  li        r0, 0x4
  li        r4, 0x1
  stw       r0, 0x28(r31)
  li        r0, 0
  li        r3, 0x8
  stb       r4, 0x2C(r31)
  lwz       r4, 0x30(r31)
  stw       r0, 0x0(r4)
  lwz       r4, 0x34(r31)
  stw       r0, 0x0(r4)
  lwz       r4, 0x48(r31)
  stw       r0, 0x0(r4)
  lwz       r4, 0x4C(r31)
  stw       r0, 0x0(r4)
  lwz       r4, 0x40(r31)
  stw       r0, 0x0(r4)
  lwz       r4, 0x30(r31)
  stw       r0, 0x4(r4)
  lwz       r4, 0x34(r31)
  stw       r0, 0x4(r4)
  lwz       r4, 0x48(r31)
  stw       r0, 0x4(r4)
  lwz       r4, 0x4C(r31)
  stw       r0, 0x4(r4)
  lwz       r4, 0x40(r31)
  stw       r0, 0x4(r4)
  lwz       r4, 0x30(r31)
  stw       r0, 0x8(r4)
  lwz       r4, 0x34(r31)
  stw       r0, 0x8(r4)
  lwz       r4, 0x48(r31)
  stw       r0, 0x8(r4)
  lwz       r4, 0x4C(r31)
  stw       r0, 0x8(r4)
  lwz       r4, 0x40(r31)
  stw       r0, 0x8(r4)
  lwz       r4, 0x30(r31)
  stw       r0, 0xC(r4)
  lwz       r4, 0x34(r31)
  stw       r0, 0xC(r4)
  lwz       r4, 0x48(r31)
  stw       r0, 0xC(r4)
  lwz       r4, 0x4C(r31)
  stw       r0, 0xC(r4)
  lwz       r4, 0x40(r31)
  stw       r0, 0xC(r4)
  lwz       r4, 0x30(r31)
  stw       r0, 0x10(r4)
  lwz       r4, 0x34(r31)
  stw       r0, 0x10(r4)
  lwz       r4, 0x48(r31)
  stw       r0, 0x10(r4)
  lwz       r4, 0x4C(r31)
  stw       r0, 0x10(r4)
  lwz       r4, 0x40(r31)
  stw       r0, 0x10(r4)
  lwz       r4, 0x30(r31)
  stw       r0, 0x14(r4)
  lwz       r4, 0x34(r31)
  stw       r0, 0x14(r4)
  lwz       r4, 0x48(r31)
  stw       r0, 0x14(r4)
  lwz       r4, 0x4C(r31)
  stw       r0, 0x14(r4)
  lwz       r4, 0x40(r31)
  stw       r0, 0x14(r4)
  lwz       r4, 0x30(r31)
  stw       r0, 0x18(r4)
  lwz       r4, 0x34(r31)
  stw       r0, 0x18(r4)
  lwz       r4, 0x48(r31)
  stw       r0, 0x18(r4)
  lwz       r4, 0x4C(r31)
  stw       r0, 0x18(r4)
  lwz       r4, 0x40(r31)
  stw       r0, 0x18(r4)
  lwz       r4, 0x30(r31)
  stw       r0, 0x1C(r4)
  lwz       r4, 0x34(r31)
  stw       r0, 0x1C(r4)
  lwz       r4, 0x48(r31)
  stw       r0, 0x1C(r4)
  lwz       r4, 0x4C(r31)
  stw       r0, 0x1C(r4)
  lwz       r4, 0x40(r31)
  stw       r0, 0x1C(r4)
  b         .loc_0x2D4

.loc_0x288:
  subfic    r4, r3, 0xC
  cmpwi     r3, 0xC
  mtctr     r4
  bge-      .loc_0x2CC

.loc_0x298:
  lwz       r4, 0x8(r1)
  lwz       r3, 0x30(r4)
  stwx      r0, r3, r5
  lwz       r3, 0x34(r4)
  stwx      r0, r3, r5
  lwz       r3, 0x48(r4)
  stwx      r0, r3, r5
  lwz       r3, 0x4C(r4)
  stwx      r0, r3, r5
  lwz       r3, 0x40(r4)
  stwx      r0, r3, r5
  addi      r5, r5, 0x4
  bdnz+     .loc_0x298

.loc_0x2CC:
  lwz       r3, 0x8(r1)
  b         .loc_0x2DC

.loc_0x2D4:
  rlwinm    r5,r3,2,0,29
  b         .loc_0x288

.loc_0x2DC:
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
 * Address:	80150344
 * Size:	000044
 */
void BossNode::BossNode()
{
/*
.loc_0x0:
  lis       r4, 0x8022
  addi      r0, r4, 0x738C
  lis       r4, 0x8022
  stw       r0, 0x0(r3)
  addi      r0, r4, 0x737C
  stw       r0, 0x0(r3)
  li        r6, 0
  lis       r5, 0x802D
  stw       r6, 0x10(r3)
  lis       r4, 0x802D
  subi      r5, r5, 0x13C4
  stw       r6, 0xC(r3)
  subi      r0, r4, 0xFE0
  stw       r6, 0x8(r3)
  stw       r5, 0x4(r3)
  stw       r0, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80150388
 * Size:	000018
 */
void BossMgr::addUseCount(int, int)
{
/*
.loc_0x0:
  lwz       r6, 0x40(r3)
  rlwinm    r3,r4,2,0,29
  lwzx      r0, r6, r3
  add       r0, r0, r5
  stwx      r0, r6, r3
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void BossMgr::useBoss(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void BossMgr::getUseCount(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801503A0
 * Size:	0009CC
 */
void BossMgr::constructBoss()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  stw       r29, 0x14(r1)
  stw       r28, 0x10(r1)
  stb       r0, 0x2C(r3)
  lis       r3, 0x802D
  subi      r31, r3, 0x13D0
  lwz       r3, 0x40(r30)
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0
  ble-      .loc_0x11C
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x18
  bl        -0xC9CB0
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r31, 0x28
  li        r5, 0x1
  bl        -0xFD6EC
  mr        r0, r3
  lwz       r3, 0x2FE8(r13)
  mr        r28, r0
  addi      r4, r31, 0x18
  bl        -0xC9BC8
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x40
  bl        -0xC9CE4
  li        r3, 0x18
  bl        -0x109420
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0xA0
  addi      r4, r28, 0
  subi      r5, r13, 0x430
  bl        0x2248

.loc_0xA0:
  lwz       r3, 0x48(r30)
  addi      r4, r31, 0x40
  stw       r29, 0x0(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0xC9C08
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x4C
  bl        -0xC9D24
  li        r3, 0x554
  bl        -0x109460
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0xD8
  bl        0x2320

.loc_0xD8:
  lwz       r3, 0x4C(r30)
  addi      r4, r31, 0x58
  addi      r5, r31, 0x68
  stw       r29, 0x0(r3)
  li        r6, 0x1
  lwz       r3, 0x4C(r30)
  lwz       r3, 0x0(r3)
  addi      r3, r3, 0x1EC
  bl        -0x10FDF8
  lwz       r5, 0x40(r30)
  addi      r3, r30, 0
  li        r4, 0
  lwz       r5, 0x0(r5)
  bl        0xA78
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x4C
  bl        -0xC9C70

.loc_0x11C:
  lwz       r3, 0x40(r30)
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0
  bgt-      .loc_0x138
  lwz       r0, 0x24(r3)
  cmpwi     r0, 0
  ble-      .loc_0x250

.loc_0x138:
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x74
  bl        -0xC9DA8
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r31, 0x80
  li        r5, 0x1
  bl        -0xFD7E4
  mr        r0, r3
  lwz       r3, 0x2FE8(r13)
  mr        r28, r0
  addi      r4, r31, 0x74
  bl        -0xC9CC0
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x98
  bl        -0xC9DDC
  li        r3, 0x18
  bl        -0x109518
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x198
  addi      r4, r28, 0
  subi      r5, r13, 0x428
  bl        0x2150

.loc_0x198:
  lwz       r3, 0x48(r30)
  addi      r4, r31, 0x98
  stw       r29, 0x4(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0xC9D00
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0xA4
  bl        -0xC9E1C
  li        r3, 0x504
  bl        -0x109558
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x1D0
  bl        0x9D58

.loc_0x1D0:
  lwz       r3, 0x4C(r30)
  addi      r4, r31, 0xB0
  addi      r5, r31, 0x68
  stw       r29, 0x4(r3)
  li        r6, 0x1
  lwz       r3, 0x4C(r30)
  lwz       r3, 0x4(r3)
  addi      r3, r3, 0x1EC
  bl        -0x10FEF0
  lwz       r3, 0x48(r30)
  lwz       r0, 0x4(r3)
  stw       r0, 0x24(r3)
  lwz       r3, 0x4C(r30)
  lwz       r0, 0x4(r3)
  stw       r0, 0x24(r3)
  lwz       r3, 0x40(r30)
  lwz       r5, 0x4(r3)
  cmpwi     r5, 0
  ble-      .loc_0x228
  addi      r3, r30, 0
  li        r4, 0x1
  bl        0x960

.loc_0x228:
  lwz       r3, 0x40(r30)
  lwz       r5, 0x24(r3)
  cmpwi     r5, 0
  ble-      .loc_0x244
  addi      r3, r30, 0
  li        r4, 0x9
  bl        0x944

.loc_0x244:
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0xA4
  bl        -0xC9DA4

.loc_0x250:
  lwz       r3, 0x40(r30)
  lwz       r0, 0x8(r3)
  cmpwi     r0, 0
  ble-      .loc_0x4C8
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0xC0
  bl        -0xC9ED0
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r31, 0xCC
  li        r5, 0x1
  bl        -0xFD90C
  mr        r0, r3
  lwz       r3, 0x2FE8(r13)
  mr        r28, r0
  addi      r4, r31, 0xC0
  bl        -0xC9DE8
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0xE4
  bl        -0xC9F04
  li        r3, 0x18
  bl        -0x109640
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x2C0
  addi      r4, r28, 0
  subi      r5, r13, 0x420
  bl        0x2028

.loc_0x2C0:
  lwz       r3, 0x48(r30)
  addi      r4, r31, 0xE4
  stw       r29, 0x8(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0xC9E28
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0xF0
  bl        -0xC9F44
  li        r3, 0x3C4
  bl        -0x109680
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x2F8
  bl        0x13080

.loc_0x2F8:
  lwz       r3, 0x4C(r30)
  addi      r4, r31, 0xFC
  addi      r5, r31, 0x68
  stw       r29, 0x8(r3)
  li        r6, 0x1
  lwz       r3, 0x4C(r30)
  lwz       r3, 0x8(r3)
  addi      r3, r3, 0x1EC
  bl        -0x110018
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0xF0
  bl        -0xC9E7C
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x10C
  bl        -0xC9F98
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r31, 0x11C
  li        r5, 0x1
  bl        -0xFD9D4
  mr        r0, r3
  lwz       r3, 0x2FE8(r13)
  mr        r28, r0
  addi      r4, r31, 0x10C
  bl        -0xC9EB0
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x138
  bl        -0xC9FCC
  li        r3, 0x18
  bl        -0x109708
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x388
  addi      r4, r28, 0
  subi      r5, r13, 0x418
  bl        0x1F60

.loc_0x388:
  lwz       r3, 0x48(r30)
  addi      r4, r31, 0x138
  stw       r29, 0x1C(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0xC9EF0
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x148
  bl        -0xCA00C
  li        r3, 0x204
  bl        -0x109748
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x3C0
  bl        0x29A50

.loc_0x3C0:
  lwz       r3, 0x4C(r30)
  addi      r4, r31, 0x158
  addi      r5, r31, 0x68
  stw       r29, 0x1C(r3)
  li        r6, 0x1
  lwz       r3, 0x4C(r30)
  lwz       r3, 0x1C(r3)
  addi      r3, r3, 0x1EC
  bl        -0x1100E0
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x148
  bl        -0xC9F44
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x168
  bl        -0xCA060
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r31, 0x17C
  li        r5, 0x1
  bl        -0xFDA9C
  mr        r0, r3
  lwz       r3, 0x2FE8(r13)
  mr        r28, r0
  addi      r4, r31, 0x168
  bl        -0xC9F78
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x194
  bl        -0xCA094
  li        r3, 0x18
  bl        -0x1097D0
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x450
  addi      r4, r28, 0
  subi      r5, r13, 0x410
  bl        0x1E98

.loc_0x450:
  lwz       r3, 0x48(r30)
  addi      r4, r31, 0x194
  stw       r29, 0x20(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0xC9FB8
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x1A8
  bl        -0xCA0D4
  li        r3, 0x204
  bl        -0x109810
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x488
  bl        0x2A130

.loc_0x488:
  lwz       r3, 0x4C(r30)
  addi      r4, r31, 0x1BC
  addi      r5, r31, 0x68
  stw       r29, 0x20(r3)
  li        r6, 0x1
  lwz       r3, 0x4C(r30)
  lwz       r3, 0x20(r3)
  addi      r3, r3, 0x1EC
  bl        -0x1101A8
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x1A8
  bl        -0xCA00C
  addi      r3, r30, 0
  li        r4, 0x2
  li        r5, 0x1
  bl        0x6C0

.loc_0x4C8:
  lwz       r3, 0x40(r30)
  lwz       r0, 0xC(r3)
  cmpwi     r0, 0
  ble-      .loc_0x5B4
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x1CC
  bl        -0xCA148
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r31, 0x1D8
  li        r5, 0x1
  bl        -0xFDB84
  mr        r0, r3
  lwz       r3, 0x2FE8(r13)
  mr        r28, r0
  addi      r4, r31, 0x1CC
  bl        -0xCA060
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x1F0
  bl        -0xCA17C
  li        r3, 0x18
  bl        -0x1098B8
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x538
  addi      r4, r28, 0
  subi      r5, r13, 0x408
  bl        0x1DB0

.loc_0x538:
  lwz       r3, 0x48(r30)
  addi      r4, r31, 0x1F0
  stw       r29, 0xC(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0xCA0A0
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x1FC
  bl        -0xCA1BC
  li        r3, 0x4A4
  bl        -0x1098F8
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x570
  bl        0x1AB98

.loc_0x570:
  lwz       r3, 0x4C(r30)
  addi      r4, r31, 0x208
  addi      r5, r31, 0x68
  stw       r29, 0xC(r3)
  li        r6, 0x1
  lwz       r3, 0x4C(r30)
  lwz       r3, 0xC(r3)
  addi      r3, r3, 0x1EC
  bl        -0x110290
  lwz       r5, 0x40(r30)
  addi      r3, r30, 0
  li        r4, 0x3
  lwz       r5, 0xC(r5)
  bl        0x5E0
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x1FC
  bl        -0xCA108

.loc_0x5B4:
  lwz       r3, 0x40(r30)
  lwz       r0, 0x10(r3)
  cmpwi     r0, 0
  ble-      .loc_0x6A0
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x218
  bl        -0xCA234
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r31, 0x228
  li        r5, 0x1
  bl        -0xFDC70
  mr        r0, r3
  lwz       r3, 0x2FE8(r13)
  mr        r28, r0
  addi      r4, r31, 0x218
  bl        -0xCA14C
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x244
  bl        -0xCA268
  li        r3, 0x18
  bl        -0x1099A4
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x624
  addi      r4, r28, 0
  subi      r5, r13, 0x400
  bl        0x1CC4

.loc_0x624:
  lwz       r3, 0x48(r30)
  addi      r4, r31, 0x244
  stw       r29, 0x10(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0xCA18C
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x250
  bl        -0xCA2A8
  li        r3, 0x2F4
  bl        -0x1099E4
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x65C
  bl        0x25038

.loc_0x65C:
  lwz       r3, 0x4C(r30)
  addi      r4, r31, 0x25C
  addi      r5, r31, 0x68
  stw       r29, 0x10(r3)
  li        r6, 0x1
  lwz       r3, 0x4C(r30)
  lwz       r3, 0x10(r3)
  addi      r3, r3, 0x1EC
  bl        -0x11037C
  lwz       r5, 0x40(r30)
  addi      r3, r30, 0
  li        r4, 0x4
  lwz       r5, 0x10(r5)
  bl        0x4F4
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x250
  bl        -0xCA1F4

.loc_0x6A0:
  lwz       r3, 0x40(r30)
  lwz       r0, 0x14(r3)
  cmpwi     r0, 0
  ble-      .loc_0x78C
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x26C
  bl        -0xCA320
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r31, 0x278
  li        r5, 0x1
  bl        -0xFDD5C
  mr        r0, r3
  lwz       r3, 0x2FE8(r13)
  mr        r28, r0
  addi      r4, r31, 0x26C
  bl        -0xCA238
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x28C
  bl        -0xCA354
  li        r3, 0x18
  bl        -0x109A90
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x710
  addi      r4, r28, 0
  subi      r5, r13, 0x3F8
  bl        0x1BD8

.loc_0x710:
  lwz       r3, 0x48(r30)
  addi      r4, r31, 0x28C
  stw       r29, 0x14(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0xCA278
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x298
  bl        -0xCA394
  li        r3, 0x2C4
  bl        -0x109AD0
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x748
  bl        0x272FC

.loc_0x748:
  lwz       r3, 0x4C(r30)
  addi      r4, r31, 0x2A4
  addi      r5, r31, 0x68
  stw       r29, 0x14(r3)
  li        r6, 0x1
  lwz       r3, 0x4C(r30)
  lwz       r3, 0x14(r3)
  addi      r3, r3, 0x1EC
  bl        -0x110468
  lwz       r5, 0x40(r30)
  addi      r3, r30, 0
  li        r4, 0x5
  lwz       r5, 0x14(r5)
  bl        0x408
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x298
  bl        -0xCA2E0

.loc_0x78C:
  lwz       r3, 0x40(r30)
  lwz       r0, 0x18(r3)
  cmpwi     r0, 0
  ble-      .loc_0x878
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x2B0
  bl        -0xCA40C
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r31, 0x2C0
  li        r5, 0x1
  bl        -0xFDE48
  mr        r0, r3
  lwz       r3, 0x2FE8(r13)
  mr        r28, r0
  addi      r4, r31, 0x2B0
  bl        -0xCA324
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x2E0
  bl        -0xCA440
  li        r3, 0x18
  bl        -0x109B7C
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x7FC
  addi      r4, r28, 0
  addi      r5, r31, 0x2F0
  bl        0x1AEC

.loc_0x7FC:
  lwz       r3, 0x48(r30)
  addi      r4, r31, 0x2E0
  stw       r29, 0x18(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0xCA364
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x2FC
  bl        -0xCA480
  li        r3, 0x204
  bl        -0x109BBC
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x834
  bl        0x29238

.loc_0x834:
  lwz       r3, 0x4C(r30)
  addi      r4, r31, 0x30C
  addi      r5, r31, 0x68
  stw       r29, 0x18(r3)
  li        r6, 0x1
  lwz       r3, 0x4C(r30)
  lwz       r3, 0x18(r3)
  addi      r3, r3, 0x1EC
  bl        -0x110554
  lwz       r5, 0x40(r30)
  addi      r3, r30, 0
  li        r4, 0x6
  lwz       r5, 0x18(r5)
  bl        0x31C
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x2FC
  bl        -0xCA3CC

.loc_0x878:
  lwz       r3, 0x40(r30)
  lwz       r0, 0x28(r3)
  cmpwi     r0, 0
  bgt-      .loc_0x894
  lwz       r0, 0x2C(r3)
  cmpwi     r0, 0
  ble-      .loc_0x9AC

.loc_0x894:
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x320
  bl        -0xCA504
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  addi      r4, r31, 0x32C
  li        r5, 0x1
  bl        -0xFDF40
  mr        r0, r3
  lwz       r3, 0x2FE8(r13)
  mr        r28, r0
  addi      r4, r31, 0x320
  bl        -0xCA41C
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x344
  bl        -0xCA538
  li        r3, 0x18
  bl        -0x109C74
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x8F4
  addi      r4, r28, 0
  subi      r5, r13, 0x3F4
  bl        0x19F4

.loc_0x8F4:
  lwz       r3, 0x48(r30)
  addi      r4, r31, 0x344
  stw       r29, 0x28(r3)
  lwz       r3, 0x2FE8(r13)
  bl        -0xCA45C
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x350
  bl        -0xCA578
  li        r3, 0x204
  bl        -0x109CB4
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x92C
  bl        0x2A70C

.loc_0x92C:
  lwz       r3, 0x4C(r30)
  addi      r4, r31, 0x35C
  addi      r5, r31, 0x68
  stw       r29, 0x28(r3)
  li        r6, 0x1
  lwz       r3, 0x4C(r30)
  lwz       r3, 0x28(r3)
  addi      r3, r3, 0x1EC
  bl        -0x11064C
  lwz       r3, 0x48(r30)
  lwz       r0, 0x28(r3)
  stw       r0, 0x2C(r3)
  lwz       r3, 0x4C(r30)
  lwz       r0, 0x28(r3)
  stw       r0, 0x2C(r3)
  lwz       r3, 0x40(r30)
  lwz       r5, 0x28(r3)
  cmpwi     r5, 0
  ble-      .loc_0x984
  addi      r3, r30, 0
  li        r4, 0xA
  bl        0x204

.loc_0x984:
  lwz       r3, 0x40(r30)
  lwz       r5, 0x2C(r3)
  cmpwi     r5, 0
  ble-      .loc_0x9A0
  addi      r3, r30, 0
  li        r4, 0xB
  bl        0x1E8

.loc_0x9A0:
  lwz       r3, 0x2FE8(r13)
  addi      r4, r31, 0x350
  bl        -0xCA500

.loc_0x9AC:
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
 * Address:	........
 * Size:	000040
 */
void BossMgr::animatorInit(Boss *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void BossMgr::initSpider(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initSnake(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initBoxSnake(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80150D6C
 * Size:	0001B8
 */
void BossMgr::initSlime(int)
{
/*
.loc_0x0:
  mflr      r0
  lis       r8, 0x802D
  stw       r0, 0x4(r1)
  lis       r6, 0x8022
  lis       r5, 0x8022
  stwu      r1, -0x48(r1)
  lis       r7, 0x802D
  stmw      r23, 0x24(r1)
  addi      r29, r3, 0
  addi      r25, r4, 0
  subi      r30, r8, 0x13D0
  addi      r28, r6, 0x738C
  addi      r27, r5, 0x737C
  subi      r31, r7, 0xFE0
  li        r26, 0
  b         .loc_0x19C

.loc_0x40:
  li        r3, 0x408
  bl        -0x109DAC
  addi      r24, r3, 0
  mr.       r23, r24
  beq-      .loc_0x74
  addi      r3, r29, 0
  li        r4, 0x2
  bl        0x1838
  lwz       r4, 0x4C(r29)
  addi      r5, r3, 0
  addi      r3, r23, 0
  lwz       r4, 0x8(r4)
  bl        0x12EB0

.loc_0x74:
  li        r3, 0x18
  bl        -0x109DE0
  addi      r23, r3, 0
  mr.       r3, r23
  beq-      .loc_0xB0
  stw       r28, 0x0(r23)
  li        r0, 0
  addi      r4, r30, 0xC
  stw       r27, 0x0(r23)
  stw       r0, 0x10(r23)
  stw       r0, 0xC(r23)
  stw       r0, 0x8(r23)
  bl        -0x12BF3C
  stw       r31, 0x0(r23)
  stw       r24, 0x14(r23)

.loc_0xB0:
  lwz       r3, 0x3C(r29)
  addi      r4, r23, 0
  addi      r3, r3, 0x30
  bl        -0x110850
  li        r3, 0x3C0
  bl        -0x109E2C
  addi      r23, r3, 0
  mr.       r3, r23
  beq-      .loc_0xE0
  lwz       r4, 0x4C(r29)
  lwz       r4, 0x1C(r4)
  bl        0x293F4

.loc_0xE0:
  li        r3, 0x18
  bl        -0x109E4C
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x11C
  stw       r28, 0x0(r24)
  li        r0, 0
  addi      r4, r30, 0xC
  stw       r27, 0x0(r24)
  stw       r0, 0x10(r24)
  stw       r0, 0xC(r24)
  stw       r0, 0x8(r24)
  bl        -0x12BFA8
  stw       r31, 0x0(r24)
  stw       r23, 0x14(r24)

.loc_0x11C:
  lwz       r3, 0x3C(r29)
  addi      r4, r24, 0
  addi      r3, r3, 0xA8
  bl        -0x1108BC
  li        r3, 0x3C8
  bl        -0x109E98
  addi      r23, r3, 0
  mr.       r3, r23
  beq-      .loc_0x14C
  lwz       r4, 0x4C(r29)
  lwz       r4, 0x20(r4)
  bl        0x29B30

.loc_0x14C:
  li        r3, 0x18
  bl        -0x109EB8
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x188
  stw       r28, 0x0(r24)
  li        r0, 0
  addi      r4, r30, 0xC
  stw       r27, 0x0(r24)
  stw       r0, 0x10(r24)
  stw       r0, 0xC(r24)
  stw       r0, 0x8(r24)
  bl        -0x12C014
  stw       r31, 0x0(r24)
  stw       r23, 0x14(r24)

.loc_0x188:
  lwz       r3, 0x3C(r29)
  addi      r4, r24, 0
  addi      r3, r3, 0xC0
  bl        -0x110928
  addi      r26, r26, 0x1

.loc_0x19C:
  cmpw      r26, r25
  blt+      .loc_0x40
  lmw       r23, 0x24(r1)
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initKing(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initKogane(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initPom(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initKingBack(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initMizu(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void BossMgr::initGeyzer(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void BossMgr::setBossParam(Boss *, GenObjectBoss *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void BossMgr::createBoss(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80150F24
 * Size:	0004C0
 */
void BossMgr::init(int, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x80(r1)
  stmw      r24, 0x60(r1)
  addi      r28, r4, 0
  lis       r4, 0x802D
  cmpwi     r28, 0xC
  addi      r31, r3, 0
  addi      r30, r5, 0
  subi      r29, r4, 0x13D0
  bge-      .loc_0x4AC
  cmpwi     r28, 0
  blt-      .loc_0x4AC
  cmpwi     r30, 0
  bgt-      .loc_0x40
  b         .loc_0x4AC

.loc_0x40:
  cmplwi    r28, 0xB
  bgt-      .loc_0x4A0
  lis       r3, 0x802D
  subi      r3, r3, 0x1064
  rlwinm    r0,r28,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  lis       r3, 0x802D
  subi      r27, r3, 0xFE0
  li        r26, 0
  b         .loc_0xC8

.loc_0x70:
  li        r3, 0x764
  bl        -0x109F94
  addi      r25, r3, 0
  mr.       r3, r25
  beq-      .loc_0x90
  lwz       r4, 0x4C(r31)
  lwz       r4, 0x0(r4)
  bl        0x21AC

.loc_0x90:
  li        r3, 0x18
  bl        -0x109FB4
  addi      r24, r3, 0
  mr.       r0, r24
  beq-      .loc_0xB8
  addi      r3, r24, 0
  addi      r4, r29, 0xC
  bl        -0x11C018
  stw       r27, 0x0(r24)
  stw       r25, 0x14(r24)

.loc_0xB8:
  lwz       r3, 0x3C(r31)
  mr        r4, r24
  bl        -0x110A0C
  addi      r26, r26, 0x1

.loc_0xC8:
  cmpw      r26, r30
  blt+      .loc_0x70
  b         .loc_0x4A0
  lis       r3, 0x802D
  subi      r27, r3, 0xFE0
  li        r26, 0
  b         .loc_0x140

.loc_0xE4:
  li        r3, 0x3DC
  bl        -0x10A008
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x104
  lwz       r4, 0x4C(r31)
  lwz       r4, 0x4(r4)
  bl        0x9B90

.loc_0x104:
  li        r3, 0x18
  bl        -0x10A028
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x12C
  addi      r3, r25, 0
  addi      r4, r29, 0xC
  bl        -0x11C08C
  stw       r27, 0x0(r25)
  stw       r24, 0x14(r25)

.loc_0x12C:
  lwz       r3, 0x3C(r31)
  addi      r4, r25, 0
  addi      r3, r3, 0x18
  bl        -0x110A84
  addi      r26, r26, 0x1

.loc_0x140:
  cmpw      r26, r30
  blt+      .loc_0xE4
  b         .loc_0x4A0
  lis       r3, 0x802D
  subi      r27, r3, 0xFE0
  li        r26, 0
  b         .loc_0x1B8

.loc_0x15C:
  li        r3, 0x3DC
  bl        -0x10A080
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x17C
  lwz       r4, 0x4C(r31)
  lwz       r4, 0x24(r4)
  bl        0x9B18

.loc_0x17C:
  li        r3, 0x18
  bl        -0x10A0A0
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x1A4
  addi      r3, r25, 0
  addi      r4, r29, 0xC
  bl        -0x11C104
  stw       r27, 0x0(r25)
  stw       r24, 0x14(r25)

.loc_0x1A4:
  lwz       r3, 0x3C(r31)
  addi      r4, r25, 0
  addi      r3, r3, 0xD8
  bl        -0x110AFC
  addi      r26, r26, 0x1

.loc_0x1B8:
  cmpw      r26, r30
  blt+      .loc_0x15C
  b         .loc_0x4A0
  addi      r3, r31, 0
  addi      r4, r30, 0
  bl        -0x384
  b         .loc_0x4A0
  lis       r3, 0x802D
  subi      r27, r3, 0xFE0
  li        r26, 0
  b         .loc_0x240

.loc_0x1E4:
  li        r3, 0x7A4
  bl        -0x10A108
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x204
  lwz       r4, 0x4C(r31)
  lwz       r4, 0xC(r4)
  bl        0x1AB3C

.loc_0x204:
  li        r3, 0x18
  bl        -0x10A128
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x22C
  addi      r3, r25, 0
  addi      r4, r29, 0xC
  bl        -0x11C18C
  stw       r27, 0x0(r25)
  stw       r24, 0x14(r25)

.loc_0x22C:
  lwz       r3, 0x3C(r31)
  addi      r4, r25, 0
  addi      r3, r3, 0x48
  bl        -0x110B84
  addi      r26, r26, 0x1

.loc_0x240:
  cmpw      r26, r30
  blt+      .loc_0x1E4
  b         .loc_0x4A0
  lis       r3, 0x802D
  subi      r27, r3, 0xFE0
  li        r26, 0
  b         .loc_0x2B8

.loc_0x25C:
  li        r3, 0x3C0
  bl        -0x10A180
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x27C
  lwz       r4, 0x4C(r31)
  lwz       r4, 0x10(r4)
  bl        0x24BC4

.loc_0x27C:
  li        r3, 0x18
  bl        -0x10A1A0
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x2A4
  addi      r3, r25, 0
  addi      r4, r29, 0xC
  bl        -0x11C204
  stw       r27, 0x0(r25)
  stw       r24, 0x14(r25)

.loc_0x2A4:
  lwz       r3, 0x3C(r31)
  addi      r4, r25, 0
  addi      r3, r3, 0x60
  bl        -0x110BFC
  addi      r26, r26, 0x1

.loc_0x2B8:
  cmpw      r26, r30
  blt+      .loc_0x25C
  b         .loc_0x4A0
  lis       r3, 0x802D
  subi      r27, r3, 0xFE0
  li        r26, 0
  b         .loc_0x330

.loc_0x2D4:
  li        r3, 0x3D4
  bl        -0x10A1F8
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x2F4
  lwz       r4, 0x4C(r31)
  lwz       r4, 0x14(r4)
  bl        0x26E80

.loc_0x2F4:
  li        r3, 0x18
  bl        -0x10A218
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x31C
  addi      r3, r25, 0
  addi      r4, r29, 0xC
  bl        -0x11C27C
  stw       r27, 0x0(r25)
  stw       r24, 0x14(r25)

.loc_0x31C:
  lwz       r3, 0x3C(r31)
  addi      r4, r25, 0
  addi      r3, r3, 0x78
  bl        -0x110C74
  addi      r26, r26, 0x1

.loc_0x330:
  cmpw      r26, r30
  blt+      .loc_0x2D4
  b         .loc_0x4A0
  lis       r3, 0x802D
  subi      r27, r3, 0xFE0
  li        r26, 0
  b         .loc_0x3A8

.loc_0x34C:
  li        r3, 0x400
  bl        -0x10A270
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x36C
  lwz       r4, 0x4C(r31)
  lwz       r4, 0x18(r4)
  bl        0x28C0C

.loc_0x36C:
  li        r3, 0x18
  bl        -0x10A290
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x394
  addi      r3, r25, 0
  addi      r4, r29, 0xC
  bl        -0x11C2F4
  stw       r27, 0x0(r25)
  stw       r24, 0x14(r25)

.loc_0x394:
  lwz       r3, 0x3C(r31)
  addi      r4, r25, 0
  addi      r3, r3, 0x90
  bl        -0x110CEC
  addi      r26, r26, 0x1

.loc_0x3A8:
  cmpw      r26, r30
  blt+      .loc_0x34C
  b         .loc_0x4A0
  lis       r3, 0x802D
  subi      r27, r3, 0xFE0
  li        r26, 0
  b         .loc_0x420

.loc_0x3C4:
  li        r3, 0x3C0
  bl        -0x10A2E8
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x3E4
  lwz       r4, 0x4C(r31)
  lwz       r4, 0x28(r4)
  bl        0x2A160

.loc_0x3E4:
  li        r3, 0x18
  bl        -0x10A308
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x40C
  addi      r3, r25, 0
  addi      r4, r29, 0xC
  bl        -0x11C36C
  stw       r27, 0x0(r25)
  stw       r24, 0x14(r25)

.loc_0x40C:
  lwz       r3, 0x3C(r31)
  addi      r4, r25, 0
  addi      r3, r3, 0xF0
  bl        -0x110D64
  addi      r26, r26, 0x1

.loc_0x420:
  cmpw      r26, r30
  blt+      .loc_0x3C4
  b         .loc_0x4A0
  lis       r3, 0x802D
  subi      r27, r3, 0xFE0
  li        r26, 0
  b         .loc_0x498

.loc_0x43C:
  li        r3, 0x3C0
  bl        -0x10A360
  addi      r24, r3, 0
  mr.       r3, r24
  beq-      .loc_0x45C
  lwz       r4, 0x4C(r31)
  lwz       r4, 0x2C(r4)
  bl        0x2A0E8

.loc_0x45C:
  li        r3, 0x18
  bl        -0x10A380
  addi      r25, r3, 0
  mr.       r0, r25
  beq-      .loc_0x484
  addi      r3, r25, 0
  addi      r4, r29, 0xC
  bl        -0x11C3E4
  stw       r27, 0x0(r25)
  stw       r24, 0x14(r25)

.loc_0x484:
  lwz       r3, 0x3C(r31)
  addi      r4, r25, 0
  addi      r3, r3, 0x108
  bl        -0x110DDC
  addi      r26, r26, 0x1

.loc_0x498:
  cmpw      r26, r30
  blt+      .loc_0x43C

.loc_0x4A0:
  lwz       r3, 0x34(r31)
  rlwinm    r0,r28,2,0,29
  stwx      r30, r3, r0

.loc_0x4AC:
  lmw       r24, 0x60(r1)
  lwz       r0, 0x84(r1)
  addi      r1, r1, 0x80
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801513E4
 * Size:	000DB4
 */
void BossMgr::create(int, BirthInfo &, GenObjectBoss *)
{
/*
.loc_0x0:
  mflr      r0
  cmplwi    r4, 0x9
  stw       r0, 0x4(r1)
  stwu      r1, -0xA8(r1)
  stw       r31, 0xA4(r1)
  addi      r31, r6, 0
  stw       r30, 0xA0(r1)
  addi      r30, r5, 0
  stw       r29, 0x9C(r1)
  addi      r29, r3, 0
  stw       r28, 0x98(r1)
  li        r28, 0
  bgt-      .loc_0xD90
  lis       r3, 0x802D
  subi      r3, r3, 0x1034
  rlwinm    r0,r4,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  lwz       r3, 0x3C(r29)
  lwz       r28, 0x10(r3)
  cmplwi    r28, 0
  bne-      .loc_0x64
  li        r28, 0
  b         .loc_0xD4

.loc_0x64:
  lwz       r5, 0x30(r29)
  mr        r3, r28
  lwz       r4, 0x0(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x0(r5)
  bl        -0x110E4C
  lwz       r3, 0x38(r29)
  mr        r4, r28
  bl        -0x110E90
  lwz       r28, 0x14(r28)
  addi      r3, r29, 0
  li        r4, 0
  bl        0x1188
  stw       r3, 0x390(r28)
  lwz       r4, 0x390(r28)
  cmplwi    r4, 0
  beq-      .loc_0xBC
  lwz       r5, 0x14(r4)
  addi      r3, r28, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x32378

.loc_0xBC:
  lwz       r4, 0x390(r28)
  li        r5, 0
  lwz       r3, 0x220(r28)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC7950

.loc_0xD4:
  cmplwi    r28, 0
  beq-      .loc_0xD90
  addi      r3, r28, 0
  addi      r4, r30, 0
  li        r5, 0x27
  bl        -0x3568
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x24(r31)
  stw       r0, 0x2FC(r28)
  lwz       r0, 0x1C(r31)
  stw       r0, 0x2F4(r28)
  lwz       r0, 0x20(r31)
  stw       r0, 0x2F8(r28)
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x28(r31)
  bl        -0xB8880
  cmplwi    r3, 0
  beq-      .loc_0x13C
  lwz       r0, 0x2C(r3)
  stw       r0, 0x31C(r28)
  b         .loc_0x148

.loc_0x13C:
  lis       r3, 0x6E6F
  addi      r0, r3, 0x6E65
  stw       r0, 0x31C(r28)

.loc_0x148:
  lwz       r3, 0x31C(r28)
  bl        -0xBC184
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD90
  lwz       r3, 0x2F28(r13)
  mr        r4, r28
  bl        -0xD5F18
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x31C(r28)
  bl        -0xB8A4C
  b         .loc_0xD90
  lwz       r3, 0x3C(r29)
  lwz       r28, 0x28(r3)
  cmplwi    r28, 0
  bne-      .loc_0x18C
  li        r28, 0
  b         .loc_0x200

.loc_0x18C:
  lwz       r5, 0x30(r29)
  mr        r3, r28
  lwz       r4, 0x4(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x4(r5)
  bl        -0x110F74
  lwz       r3, 0x38(r29)
  addi      r4, r28, 0
  addi      r3, r3, 0x18
  bl        -0x110FBC
  lwz       r28, 0x14(r28)
  addi      r3, r29, 0
  li        r4, 0x1
  bl        0x105C
  stw       r3, 0x390(r28)
  lwz       r4, 0x390(r28)
  cmplwi    r4, 0
  beq-      .loc_0x1E8
  lwz       r5, 0x14(r4)
  addi      r3, r28, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x324A4

.loc_0x1E8:
  lwz       r4, 0x390(r28)
  li        r5, 0
  lwz       r3, 0x220(r28)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC7A7C

.loc_0x200:
  cmplwi    r28, 0
  beq-      .loc_0xD90
  addi      r3, r28, 0
  addi      r4, r30, 0
  li        r5, 0x29
  bl        -0x3694
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x24(r31)
  stw       r0, 0x2FC(r28)
  lwz       r0, 0x1C(r31)
  stw       r0, 0x2F4(r28)
  lwz       r0, 0x20(r31)
  stw       r0, 0x2F8(r28)
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x28(r31)
  bl        -0xB89AC
  cmplwi    r3, 0
  beq-      .loc_0x268
  lwz       r0, 0x2C(r3)
  stw       r0, 0x31C(r28)
  b         .loc_0x274

.loc_0x268:
  lis       r3, 0x6E6F
  addi      r0, r3, 0x6E65
  stw       r0, 0x31C(r28)

.loc_0x274:
  lwz       r3, 0x31C(r28)
  bl        -0xBC2B0
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD90
  lwz       r3, 0x2F28(r13)
  mr        r4, r28
  bl        -0xD6044
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x31C(r28)
  bl        -0xB8B78
  b         .loc_0xD90
  lwz       r3, 0x3C(r29)
  lwz       r28, 0xE8(r3)
  cmplwi    r28, 0
  bne-      .loc_0x2B8
  li        r28, 0
  b         .loc_0x32C

.loc_0x2B8:
  lwz       r5, 0x30(r29)
  mr        r3, r28
  lwz       r4, 0x24(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x24(r5)
  bl        -0x1110A0
  lwz       r3, 0x38(r29)
  addi      r4, r28, 0
  addi      r3, r3, 0xD8
  bl        -0x1110E8
  lwz       r28, 0x14(r28)
  addi      r3, r29, 0
  li        r4, 0x9
  bl        0xF30
  stw       r3, 0x390(r28)
  lwz       r4, 0x390(r28)
  cmplwi    r4, 0
  beq-      .loc_0x314
  lwz       r5, 0x14(r4)
  addi      r3, r28, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x325D0

.loc_0x314:
  lwz       r4, 0x390(r28)
  li        r5, 0
  lwz       r3, 0x220(r28)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC7BA8

.loc_0x32C:
  cmplwi    r28, 0
  beq-      .loc_0xD90
  addi      r3, r28, 0
  addi      r4, r30, 0
  li        r5, 0x29
  bl        -0x37C0
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x24(r31)
  stw       r0, 0x2FC(r28)
  lwz       r0, 0x1C(r31)
  stw       r0, 0x2F4(r28)
  lwz       r0, 0x20(r31)
  stw       r0, 0x2F8(r28)
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x28(r31)
  bl        -0xB8AD8
  cmplwi    r3, 0
  beq-      .loc_0x394
  lwz       r0, 0x2C(r3)
  stw       r0, 0x31C(r28)
  b         .loc_0x3A0

.loc_0x394:
  lis       r3, 0x6E6F
  addi      r0, r3, 0x6E65
  stw       r0, 0x31C(r28)

.loc_0x3A0:
  lwz       r3, 0x31C(r28)
  bl        -0xBC3DC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x3C8
  lwz       r3, 0x2F28(r13)
  mr        r4, r28
  bl        -0xD6170
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x31C(r28)
  bl        -0xB8CA4

.loc_0x3C8:
  addi      r3, r28, 0
  li        r4, 0
  bl        0x9504
  b         .loc_0xD90
  lwz       r3, 0x3C(r29)
  lwz       r28, 0x40(r3)
  cmplwi    r28, 0
  bne-      .loc_0x3F0
  li        r28, 0
  b         .loc_0x464

.loc_0x3F0:
  lwz       r5, 0x30(r29)
  mr        r3, r28
  lwz       r4, 0x8(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x8(r5)
  bl        -0x1111D8
  lwz       r3, 0x38(r29)
  addi      r4, r28, 0
  addi      r3, r3, 0x30
  bl        -0x111220
  lwz       r28, 0x14(r28)
  addi      r3, r29, 0
  li        r4, 0x2
  bl        0xDF8
  stw       r3, 0x390(r28)
  lwz       r4, 0x390(r28)
  cmplwi    r4, 0
  beq-      .loc_0x44C
  lwz       r5, 0x14(r4)
  addi      r3, r28, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x32708

.loc_0x44C:
  lwz       r4, 0x390(r28)
  li        r5, 0
  lwz       r3, 0x220(r28)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC7CE0

.loc_0x464:
  cmplwi    r28, 0
  beq-      .loc_0xD90
  addi      r3, r28, 0
  addi      r4, r30, 0
  li        r5, 0x2C
  bl        -0x38F8
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x24(r31)
  stw       r0, 0x2FC(r28)
  lwz       r0, 0x1C(r31)
  stw       r0, 0x2F4(r28)
  lwz       r0, 0x20(r31)
  stw       r0, 0x2F8(r28)
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x28(r31)
  bl        -0xB8C10
  cmplwi    r3, 0
  beq-      .loc_0x4CC
  lwz       r0, 0x2C(r3)
  stw       r0, 0x31C(r28)
  b         .loc_0x4D8

.loc_0x4CC:
  lis       r3, 0x6E6F
  addi      r0, r3, 0x6E65
  stw       r0, 0x31C(r28)

.loc_0x4D8:
  lwz       r3, 0x31C(r28)
  bl        -0xBC514
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x500
  lwz       r3, 0x2F28(r13)
  mr        r4, r28
  bl        -0xD62A8
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x31C(r28)
  bl        -0xB8DDC

.loc_0x500:
  lwz       r3, 0x3C(r29)
  lwz       r31, 0xB8(r3)
  cmplwi    r31, 0
  bne-      .loc_0x518
  li        r31, 0
  b         .loc_0x58C

.loc_0x518:
  lwz       r5, 0x30(r29)
  mr        r3, r31
  lwz       r4, 0x1C(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x1C(r5)
  bl        -0x111300
  lwz       r3, 0x38(r29)
  addi      r4, r31, 0
  addi      r3, r3, 0xA8
  bl        -0x111348
  lwz       r31, 0x14(r31)
  addi      r3, r29, 0
  li        r4, 0x7
  bl        0xCD0
  stw       r3, 0x390(r31)
  lwz       r4, 0x390(r31)
  cmplwi    r4, 0
  beq-      .loc_0x574
  lwz       r5, 0x14(r4)
  addi      r3, r31, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x32830

.loc_0x574:
  lwz       r4, 0x390(r31)
  li        r5, 0
  lwz       r3, 0x220(r31)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC7E08

.loc_0x58C:
  addi      r3, r31, 0
  addi      r4, r30, 0
  li        r5, 0x30
  bl        -0x3A18
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  stw       r31, 0x3F8(r28)
  stw       r28, 0x3B8(r31)
  lwz       r3, 0x3C(r29)
  lwz       r31, 0xD0(r3)
  cmplwi    r31, 0
  bne-      .loc_0x5D4
  li        r31, 0
  b         .loc_0x648

.loc_0x5D4:
  lwz       r5, 0x30(r29)
  mr        r3, r31
  lwz       r4, 0x20(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x20(r5)
  bl        -0x1113BC
  lwz       r3, 0x38(r29)
  addi      r4, r31, 0
  addi      r3, r3, 0xC0
  bl        -0x111404
  lwz       r31, 0x14(r31)
  addi      r3, r29, 0
  li        r4, 0x8
  bl        0xC14
  stw       r3, 0x390(r31)
  lwz       r4, 0x390(r31)
  cmplwi    r4, 0
  beq-      .loc_0x630
  lwz       r5, 0x14(r4)
  addi      r3, r31, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x328EC

.loc_0x630:
  lwz       r4, 0x390(r31)
  li        r5, 0
  lwz       r3, 0x220(r31)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC7EC4

.loc_0x648:
  addi      r3, r31, 0
  addi      r4, r30, 0
  li        r5, 0x30
  bl        -0x3AD4
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  stw       r31, 0x3FC(r28)
  stw       r28, 0x3BC(r31)
  b         .loc_0xD90
  lwz       r3, 0x3C(r29)
  lwz       r28, 0x58(r3)
  cmplwi    r28, 0
  bne-      .loc_0x694
  li        r28, 0
  b         .loc_0x708

.loc_0x694:
  lwz       r5, 0x30(r29)
  mr        r3, r28
  lwz       r4, 0xC(r5)
  addi      r0, r4, 0x1
  stw       r0, 0xC(r5)
  bl        -0x11147C
  lwz       r3, 0x38(r29)
  addi      r4, r28, 0
  addi      r3, r3, 0x48
  bl        -0x1114C4
  lwz       r28, 0x14(r28)
  addi      r3, r29, 0
  li        r4, 0x3
  bl        0xB54
  stw       r3, 0x390(r28)
  lwz       r4, 0x390(r28)
  cmplwi    r4, 0
  beq-      .loc_0x6F0
  lwz       r5, 0x14(r4)
  addi      r3, r28, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x329AC

.loc_0x6F0:
  lwz       r4, 0x390(r28)
  li        r5, 0
  lwz       r3, 0x220(r28)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC7F84

.loc_0x708:
  cmplwi    r28, 0
  beq-      .loc_0xD90
  addi      r3, r28, 0
  addi      r4, r30, 0
  li        r5, 0x2B
  bl        -0x3B9C
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x24(r31)
  stw       r0, 0x2FC(r28)
  lwz       r0, 0x1C(r31)
  stw       r0, 0x2F4(r28)
  lwz       r0, 0x20(r31)
  stw       r0, 0x2F8(r28)
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x28(r31)
  bl        -0xB8EB4
  cmplwi    r3, 0
  beq-      .loc_0x770
  lwz       r0, 0x2C(r3)
  stw       r0, 0x31C(r28)
  b         .loc_0x77C

.loc_0x770:
  lis       r3, 0x6E6F
  addi      r0, r3, 0x6E65
  stw       r0, 0x31C(r28)

.loc_0x77C:
  lwz       r3, 0x31C(r28)
  bl        -0xBC7B8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD90
  lwz       r3, 0x2F28(r13)
  mr        r4, r28
  bl        -0xD654C
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x31C(r28)
  bl        -0xB9080
  b         .loc_0xD90
  lwz       r3, 0x3C(r29)
  lwz       r28, 0x70(r3)
  cmplwi    r28, 0
  bne-      .loc_0x7C0
  li        r28, 0
  b         .loc_0x834

.loc_0x7C0:
  lwz       r5, 0x30(r29)
  mr        r3, r28
  lwz       r4, 0x10(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x10(r5)
  bl        -0x1115A8
  lwz       r3, 0x38(r29)
  addi      r4, r28, 0
  addi      r3, r3, 0x60
  bl        -0x1115F0
  lwz       r28, 0x14(r28)
  addi      r3, r29, 0
  li        r4, 0x4
  bl        0xA28
  stw       r3, 0x390(r28)
  lwz       r4, 0x390(r28)
  cmplwi    r4, 0
  beq-      .loc_0x81C
  lwz       r5, 0x14(r4)
  addi      r3, r28, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x32AD8

.loc_0x81C:
  lwz       r4, 0x390(r28)
  li        r5, 0
  lwz       r3, 0x220(r28)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC80B0

.loc_0x834:
  cmplwi    r28, 0
  beq-      .loc_0xD90
  addi      r3, r28, 0
  addi      r4, r30, 0
  li        r5, 0x2D
  bl        -0x3CC8
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x24(r31)
  stw       r0, 0x2FC(r28)
  lwz       r0, 0x1C(r31)
  stw       r0, 0x2F4(r28)
  lwz       r0, 0x20(r31)
  stw       r0, 0x2F8(r28)
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x28(r31)
  bl        -0xB8FE0
  cmplwi    r3, 0
  beq-      .loc_0x89C
  lwz       r0, 0x2C(r3)
  stw       r0, 0x31C(r28)
  b         .loc_0x8A8

.loc_0x89C:
  lis       r3, 0x6E6F
  addi      r0, r3, 0x6E65
  stw       r0, 0x31C(r28)

.loc_0x8A8:
  lwz       r3, 0x31C(r28)
  bl        -0xBC8E4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD90
  lwz       r3, 0x2F28(r13)
  mr        r4, r28
  bl        -0xD6678
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x31C(r28)
  bl        -0xB91AC
  b         .loc_0xD90
  lwz       r4, 0x2F6C(r13)
  li        r3, 0x1
  lwz       r0, 0x20(r31)
  lbz       r4, 0x184(r4)
  slw       r0, r3, r0
  and.      r0, r4, r0
  beq-      .loc_0xD90
  lwz       r3, 0x3C(r29)
  lwz       r28, 0x88(r3)
  cmplwi    r28, 0
  bne-      .loc_0x908
  li        r28, 0
  b         .loc_0x97C

.loc_0x908:
  lwz       r5, 0x30(r29)
  mr        r3, r28
  lwz       r4, 0x14(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x14(r5)
  bl        -0x1116F0
  lwz       r3, 0x38(r29)
  addi      r4, r28, 0
  addi      r3, r3, 0x78
  bl        -0x111738
  lwz       r28, 0x14(r28)
  addi      r3, r29, 0
  li        r4, 0x5
  bl        0x8E0
  stw       r3, 0x390(r28)
  lwz       r4, 0x390(r28)
  cmplwi    r4, 0
  beq-      .loc_0x964
  lwz       r5, 0x14(r4)
  addi      r3, r28, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x32C20

.loc_0x964:
  lwz       r4, 0x390(r28)
  li        r5, 0
  lwz       r3, 0x220(r28)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC81F8

.loc_0x97C:
  cmplwi    r28, 0
  beq-      .loc_0xD90
  addi      r3, r28, 0
  addi      r4, r30, 0
  li        r5, 0x2E
  bl        -0x3E10
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x24(r31)
  stw       r0, 0x2FC(r28)
  lwz       r0, 0x1C(r31)
  stw       r0, 0x2F4(r28)
  lwz       r0, 0x20(r31)
  stw       r0, 0x2F8(r28)
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x28(r31)
  bl        -0xB9128
  cmplwi    r3, 0
  beq-      .loc_0x9E4
  lwz       r0, 0x2C(r3)
  stw       r0, 0x31C(r28)
  b         .loc_0x9F0

.loc_0x9E4:
  lis       r3, 0x6E6F
  addi      r0, r3, 0x6E65
  stw       r0, 0x31C(r28)

.loc_0x9F0:
  lwz       r3, 0x31C(r28)
  bl        -0xBCA2C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xA18
  lwz       r3, 0x2F28(r13)
  mr        r4, r28
  bl        -0xD67C0
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x31C(r28)
  bl        -0xB92F4

.loc_0xA18:
  mr        r3, r28
  lwz       r4, 0x20(r31)
  bl        0x26380
  b         .loc_0xD90
  lwz       r3, 0x3C(r29)
  lwz       r28, 0xA0(r3)
  cmplwi    r28, 0
  bne-      .loc_0xA40
  li        r28, 0
  b         .loc_0xAB4

.loc_0xA40:
  lwz       r5, 0x30(r29)
  mr        r3, r28
  lwz       r4, 0x18(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x18(r5)
  bl        -0x111828
  lwz       r3, 0x38(r29)
  addi      r4, r28, 0
  addi      r3, r3, 0x90
  bl        -0x111870
  lwz       r28, 0x14(r28)
  addi      r3, r29, 0
  li        r4, 0x6
  bl        0x7A8
  stw       r3, 0x390(r28)
  lwz       r4, 0x390(r28)
  cmplwi    r4, 0
  beq-      .loc_0xA9C
  lwz       r5, 0x14(r4)
  addi      r3, r28, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x32D58

.loc_0xA9C:
  lwz       r4, 0x390(r28)
  li        r5, 0
  lwz       r3, 0x220(r28)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC8330

.loc_0xAB4:
  cmplwi    r28, 0
  beq-      .loc_0xD90
  addi      r3, r28, 0
  addi      r4, r30, 0
  li        r5, 0x2F
  bl        -0x3F48
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x24(r31)
  stw       r0, 0x2FC(r28)
  lwz       r0, 0x1C(r31)
  stw       r0, 0x2F4(r28)
  lwz       r0, 0x20(r31)
  stw       r0, 0x2F8(r28)
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x28(r31)
  bl        -0xB9260
  cmplwi    r3, 0
  beq-      .loc_0xB1C
  lwz       r0, 0x2C(r3)
  stw       r0, 0x31C(r28)
  b         .loc_0xB28

.loc_0xB1C:
  lis       r3, 0x6E6F
  addi      r0, r3, 0x6E65
  stw       r0, 0x31C(r28)

.loc_0xB28:
  lwz       r3, 0x31C(r28)
  bl        -0xBCB64
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD90
  lwz       r3, 0x2F28(r13)
  mr        r4, r28
  bl        -0xD68F8
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x31C(r28)
  bl        -0xB942C
  b         .loc_0xD90
  lwz       r3, 0x3C(r29)
  lwz       r28, 0x100(r3)
  cmplwi    r28, 0
  bne-      .loc_0xB6C
  li        r28, 0
  b         .loc_0xBE0

.loc_0xB6C:
  lwz       r5, 0x30(r29)
  mr        r3, r28
  lwz       r4, 0x28(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x28(r5)
  bl        -0x111954
  lwz       r3, 0x38(r29)
  addi      r4, r28, 0
  addi      r3, r3, 0xF0
  bl        -0x11199C
  lwz       r28, 0x14(r28)
  addi      r3, r29, 0
  li        r4, 0xA
  bl        0x67C
  stw       r3, 0x390(r28)
  lwz       r4, 0x390(r28)
  cmplwi    r4, 0
  beq-      .loc_0xBC8
  lwz       r5, 0x14(r4)
  addi      r3, r28, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x32E84

.loc_0xBC8:
  lwz       r4, 0x390(r28)
  li        r5, 0
  lwz       r3, 0x220(r28)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC845C

.loc_0xBE0:
  cmplwi    r28, 0
  beq-      .loc_0xD90
  addi      r3, r28, 0
  addi      r4, r30, 0
  li        r5, 0x31
  bl        -0x4074
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x29568
  lwz       r0, 0x24(r31)
  stw       r0, 0x2FC(r28)
  lwz       r0, 0x1C(r31)
  stw       r0, 0x2F4(r28)
  lwz       r0, 0x20(r31)
  stw       r0, 0x2F8(r28)
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x28(r31)
  bl        -0xB9380
  cmplwi    r3, 0
  beq-      .loc_0xC3C
  lwz       r0, 0x2C(r3)
  stw       r0, 0x31C(r28)
  b         .loc_0xC48

.loc_0xC3C:
  lis       r3, 0x6E6F
  addi      r0, r3, 0x6E65
  stw       r0, 0x31C(r28)

.loc_0xC48:
  lwz       r3, 0x31C(r28)
  bl        -0xBCC84
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD90
  lwz       r3, 0x2F28(r13)
  mr        r4, r28
  bl        -0xD6A18
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x31C(r28)
  bl        -0xB954C
  b         .loc_0xD90
  lwz       r3, 0x3C(r29)
  lwz       r28, 0x118(r3)
  cmplwi    r28, 0
  bne-      .loc_0xC8C
  li        r28, 0
  b         .loc_0xD00

.loc_0xC8C:
  lwz       r5, 0x30(r29)
  mr        r3, r28
  lwz       r4, 0x2C(r5)
  addi      r0, r4, 0x1
  stw       r0, 0x2C(r5)
  bl        -0x111A74
  lwz       r3, 0x38(r29)
  addi      r4, r28, 0
  addi      r3, r3, 0x108
  bl        -0x111ABC
  lwz       r28, 0x14(r28)
  addi      r3, r29, 0
  li        r4, 0xB
  bl        0x55C
  stw       r3, 0x390(r28)
  lwz       r4, 0x390(r28)
  cmplwi    r4, 0
  beq-      .loc_0xCE8
  lwz       r5, 0x14(r4)
  addi      r3, r28, 0x33C
  lwz       r6, 0x50(r29)
  addi      r4, r4, 0x4
  bl        -0x32FA4

.loc_0xCE8:
  lwz       r4, 0x390(r28)
  li        r5, 0
  lwz       r3, 0x220(r28)
  li        r6, 0
  lwz       r4, 0x0(r4)
  bl        -0xC857C

.loc_0xD00:
  cmplwi    r28, 0
  beq-      .loc_0xD90
  addi      r3, r28, 0
  addi      r4, r30, 0
  li        r5, 0x31
  bl        -0x4194
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x29488
  lwz       r0, 0x24(r31)
  stw       r0, 0x2FC(r28)
  lwz       r0, 0x1C(r31)
  stw       r0, 0x2F4(r28)
  lwz       r0, 0x20(r31)
  stw       r0, 0x2F8(r28)
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x28(r31)
  bl        -0xB94A0
  cmplwi    r3, 0
  beq-      .loc_0xD5C
  lwz       r0, 0x2C(r3)
  stw       r0, 0x31C(r28)
  b         .loc_0xD68

.loc_0xD5C:
  lis       r3, 0x6E6F
  addi      r0, r3, 0x6E65
  stw       r0, 0x31C(r28)

.loc_0xD68:
  lwz       r3, 0x31C(r28)
  bl        -0xBCDA4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD90
  lwz       r3, 0x2F28(r13)
  mr        r4, r28
  bl        -0xD6B38
  lwz       r3, 0x301C(r13)
  lwz       r4, 0x31C(r28)
  bl        -0xB966C

.loc_0xD90:
  mr        r3, r28
  lwz       r0, 0xAC(r1)
  lwz       r31, 0xA4(r1)
  lwz       r30, 0xA0(r1)
  lwz       r29, 0x9C(r1)
  lwz       r28, 0x98(r1)
  addi      r1, r1, 0xA8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80152198
 * Size:	0000C0
 */
void BossMgr::kill(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0
  stw       r0, 0x4(r1)
  li        r0, 0xC
  mtctr     r0
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  li        r31, 0
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r3, 0

.loc_0x2C:
  lwz       r3, 0x38(r29)
  addi      r0, r5, 0x10
  lwzx      r3, r3, r0
  b         .loc_0x90

.loc_0x3C:
  lwz       r0, 0x14(r3)
  addi      r30, r3, 0
  cmplw     r4, r0
  bne-      .loc_0x8C
  lwz       r6, 0x30(r29)
  rlwinm    r5,r31,2,0,29
  addi      r3, r30, 0
  lwzx      r4, r6, r5
  subi      r0, r4, 0x1
  stwx      r0, r6, r5
  bl        -0x111BEC
  mulli     r0, r31, 0x18
  lwz       r3, 0x3C(r29)
  addi      r4, r30, 0
  add       r3, r3, r0
  bl        -0x111C38
  lwz       r3, 0x14(r30)
  li        r4, 0
  bl        -0xC753C
  b         .loc_0xA4

.loc_0x8C:
  lwz       r3, 0xC(r3)

.loc_0x90:
  cmplwi    r3, 0
  bne+      .loc_0x3C
  addi      r5, r5, 0x18
  addi      r31, r31, 0x1
  bdnz+     .loc_0x2C

.loc_0xA4:
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
 * Address:	80152258
 * Size:	0000B0
 */
void BossMgr::killAll()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r26, 0x10(r1)
  li        r31, 0
  addi      r26, r3, 0
  addi      r30, r31, 0
  li        r28, 0

.loc_0x20:
  lwz       r3, 0x38(r26)
  addi      r0, r31, 0x10
  lwzx      r3, r3, r0
  b         .loc_0x80

.loc_0x30:
  lwz       r5, 0x30(r26)
  mr        r27, r3
  lwz       r29, 0xC(r3)
  lwzx      r4, r30, r5
  subi      r0, r4, 0x1
  stwx      r0, r30, r5
  bl        -0x111C90
  lwz       r0, 0x3C(r26)
  addi      r4, r27, 0
  add       r3, r0, r31
  bl        -0x111CD8
  lwz       r3, 0x14(r27)
  li        r4, 0x1
  bl        -0xC75DC
  lwz       r3, 0x14(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x110(r12)
  mtlr      r12
  blrl      
  mr        r3, r29

.loc_0x80:
  cmplwi    r3, 0
  bne+      .loc_0x30
  addi      r28, r28, 0x1
  cmpwi     r28, 0xC
  addi      r31, r31, 0x18
  addi      r30, r30, 0x4
  blt+      .loc_0x20
  lmw       r26, 0x10(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80152308
 * Size:	000110
 */
void BossMgr::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stmw      r27, 0x24(r1)
  mr        r31, r3
  lbz       r0, 0x2C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x74
  li        r29, 0
  li        r30, 0

.loc_0x28:
  lwz       r3, 0x38(r31)
  addi      r0, r30, 0x10
  lwzx      r28, r3, r0
  b         .loc_0x58

.loc_0x38:
  lwz       r3, 0x14(r28)
  bl        -0x2F18
  lwz       r3, 0x14(r28)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xE0(r12)
  mtlr      r12
  blrl      
  lwz       r28, 0xC(r28)

.loc_0x58:
  cmplwi    r28, 0
  bne+      .loc_0x38
  addi      r29, r29, 0x1
  cmpwi     r29, 0xC
  addi      r30, r30, 0x18
  blt+      .loc_0x28
  b         .loc_0xFC

.loc_0x74:
  li        r29, 0
  li        r30, 0

.loc_0x7C:
  lwz       r3, 0x38(r31)
  addi      r0, r30, 0x10
  lwzx      r27, r3, r0
  b         .loc_0xE4

.loc_0x8C:
  lwz       r28, 0xC(r27)
  lwz       r3, 0x14(r27)
  bl        -0x2F70
  lwz       r4, 0x14(r27)
  lwz       r3, 0x224(r4)
  lwz       r0, 0x1E8(r3)
  cmpwi     r0, 0
  beq-      .loc_0xCC
  addi      r3, r4, 0x40
  bl        -0xBE228
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xCC
  lwz       r3, 0x14(r27)
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0xE0

.loc_0xCC:
  lwz       r3, 0x14(r27)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xE0(r12)
  mtlr      r12
  blrl      

.loc_0xE0:
  mr        r27, r28

.loc_0xE4:
  cmplwi    r27, 0
  bne+      .loc_0x8C
  addi      r29, r29, 0x1
  cmpwi     r29, 0xC
  addi      r30, r30, 0x18
  blt+      .loc_0x7C

.loc_0xFC:
  lmw       r27, 0x24(r1)
  lwz       r0, 0x3C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80152418
 * Size:	000158
 */
void BossMgr::refresh(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stmw      r27, 0x2C(r1)
  mr        r30, r3
  addi      r31, r4, 0
  lbz       r0, 0x2C(r3)
  cmplwi    r0, 0
  beq-      .loc_0x94
  li        r28, 0
  li        r29, 0

.loc_0x2C:
  lwz       r3, 0x38(r30)
  addi      r0, r29, 0x10
  lwzx      r27, r3, r0
  b         .loc_0x70

.loc_0x3C:
  lwz       r3, 0x14(r27)
  mr        r4, r31
  lwz       r12, 0x0(r3)
  lwz       r12, 0xEC(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x14(r27)
  mr        r4, r31
  lwz       r12, 0x0(r3)
  lwz       r12, 0x120(r12)
  mtlr      r12
  blrl      
  lwz       r27, 0xC(r27)

.loc_0x70:
  cmplwi    r27, 0
  bne+      .loc_0x3C
  addi      r28, r28, 0x1
  cmpwi     r28, 0xC
  addi      r29, r29, 0x18
  blt+      .loc_0x2C
  li        r0, 0
  stb       r0, 0x2C(r30)
  b         .loc_0x144

.loc_0x94:
  li        r27, 0
  li        r29, 0

.loc_0x9C:
  lwz       r3, 0x38(r30)
  addi      r0, r29, 0x10
  lwzx      r28, r3, r0
  b         .loc_0x12C

.loc_0xAC:
  lwz       r3, 0x14(r28)
  mr        r4, r31
  bl        -0x2FA0
  lwz       r4, 0x14(r28)
  lwz       r3, 0x224(r4)
  lwz       r0, 0x1E8(r3)
  cmpwi     r0, 0
  beq-      .loc_0xEC
  addi      r3, r4, 0x40
  bl        -0xBE358
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xEC
  lwz       r3, 0x14(r28)
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x104

.loc_0xEC:
  lwz       r3, 0x14(r28)
  mr        r4, r31
  lwz       r12, 0x0(r3)
  lwz       r12, 0xEC(r12)
  mtlr      r12
  blrl      

.loc_0x104:
  lwz       r3, 0x14(r28)
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x128
  lwz       r12, 0x0(r3)
  mr        r4, r31
  lwz       r12, 0x120(r12)
  mtlr      r12
  blrl      

.loc_0x128:
  lwz       r28, 0xC(r28)

.loc_0x12C:
  cmplwi    r28, 0
  bne+      .loc_0xAC
  addi      r27, r27, 0x1
  cmpwi     r27, 0xC
  addi      r29, r29, 0x18
  blt+      .loc_0x9C

.loc_0x144:
  lmw       r27, 0x2C(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80152570
 * Size:	000084
 */
void BossMgr::refresh2d(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  addi      r27, r3, 0
  addi      r28, r4, 0
  li        r30, 0
  li        r31, 0

.loc_0x20:
  lwz       r3, 0x38(r27)
  addi      r0, r31, 0x10
  lwzx      r29, r3, r0
  b         .loc_0x58

.loc_0x30:
  lwz       r3, 0x14(r29)
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,12,12
  bne-      .loc_0x54
  lwz       r12, 0x0(r3)
  mr        r4, r28
  lwz       r12, 0xF0(r12)
  mtlr      r12
  blrl      

.loc_0x54:
  lwz       r29, 0xC(r29)

.loc_0x58:
  cmplwi    r29, 0
  bne+      .loc_0x30
  addi      r30, r30, 0x1
  cmpwi     r30, 0xC
  addi      r31, r31, 0x18
  blt+      .loc_0x20
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x34(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801525F4
 * Size:	00000C
 */
void BossMgr::finalSetup()
{
/*
.loc_0x0:
  li        r0, 0x1
  stb       r0, 0x2C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80152600
 * Size:	000010
 */
void BossMgr::getBossShapeObject(int)
{
/*
.loc_0x0:
  lwz       r3, 0x48(r3)
  rlwinm    r0,r4,2,0,29
  lwzx      r3, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80152610
 * Size:	00006C
 */
void BossMgr::~BossMgr()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  beq-      .loc_0x54
  lis       r3, 0x802D
  subi      r3, r3, 0xF20
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
  bl        -0x10B4B4

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
 * Address:	8015267C
 * Size:	000008
 */
void BossMgr::@8@update()
{
/*
.loc_0x0:
  subi      r3, r3, 0x8
  b         -0x378
*/
}