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
 * Address:	80182318
 * Size:	000324
 */
zen::ogScrPauseMgr::ogScrPauseMgr()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stw       r31, 0x74(r1)
  stw       r30, 0x70(r1)
  addi      r30, r3, 0
  lis       r3, 0x802D
  stw       r29, 0x6C(r1)
  addi      r31, r3, 0x30C0
  li        r29, 0
  stw       r28, 0x68(r1)
  li        r3, 0xF8
  stb       r29, 0x44(r30)
  bl        -0x13B348
  addi      r28, r3, 0
  mr.       r0, r28
  beq-      .loc_0x94
  addi      r3, r1, 0x60
  li        r4, 0
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x312B8
  lis       r4, 0x726F
  addi      r7, r4, 0x6F74
  addi      r8, r1, 0x60
  addi      r3, r28, 0
  li        r4, 0
  li        r5, 0x8
  li        r6, 0x1
  bl        0x2E63C
  lis       r3, 0x802E
  addi      r0, r3, 0x7E0
  stw       r0, 0x0(r28)
  stb       r29, 0xEC(r28)
  stw       r29, 0xF0(r28)
  stw       r29, 0xF4(r28)

.loc_0x94:
  stw       r28, 0x1C(r30)
  addi      r4, r31, 0x1C
  li        r5, 0
  lwz       r3, 0x1C(r30)
  li        r6, 0
  li        r7, 0x1
  bl        0x3083C
  lwz       r3, 0x1C(r30)
  lis       r4, 0x626C
  addi      r4, r4, 0x636B
  lwz       r12, 0x0(r3)
  li        r5, 0x1
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x20(r30)
  li        r0, 0
  li        r3, 0x1D8
  lwz       r4, 0x20(r30)
  stb       r0, 0xF0(r4)
  bl        -0x13B3F8
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x104
  addi      r4, r31, 0x34
  li        r5, 0
  li        r6, 0
  bl        0x40CE4

.loc_0x104:
  stw       r28, 0xC(r30)
  lis       r3, 0x7961
  addi      r4, r3, 0x6D65
  lwz       r3, 0xC(r30)
  li        r5, 0x1
  addi      r0, r3, 0x4
  stw       r0, 0x14(r30)
  lwz       r3, 0x14(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x30(r30)
  lis       r3, 0x6865
  addi      r4, r3, 0x3032
  lwz       r3, 0x14(r30)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x34(r30)
  lis       r3, 0x686D
  addi      r4, r3, 0x3032
  lwz       r3, 0x14(r30)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x38(r30)
  li        r5, 0
  li        r3, 0x1D8
  lwz       r4, 0x30(r30)
  lwz       r0, 0x10C(r4)
  stw       r0, 0x3C(r30)
  lwz       r4, 0x34(r30)
  lwz       r0, 0x10C(r4)
  stw       r0, 0x40(r30)
  lwz       r4, 0x30(r30)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r4)
  bl        -0x13B4C4
  addi      r28, r3, 0
  mr.       r3, r28
  beq-      .loc_0x1D0
  addi      r4, r31, 0x4C
  li        r5, 0
  li        r6, 0
  bl        0x40C18

.loc_0x1D0:
  stw       r28, 0x10(r30)
  lis       r3, 0x7961
  addi      r4, r3, 0x6D65
  lwz       r3, 0x10(r30)
  li        r5, 0x1
  addi      r0, r3, 0x4
  stw       r0, 0x18(r30)
  lwz       r3, 0x18(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x24(r30)
  lis       r3, 0x7469
  addi      r4, r3, 0x746C
  lwz       r3, 0x18(r30)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x28(r30)
  lis       r3, 0x6576
  addi      r4, r3, 0x656E
  lwz       r3, 0x18(r30)
  li        r5, 0x1
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x2C(r30)
  lis       r31, 0x6261
  li        r29, 0
  lwz       r6, 0x24(r30)
  li        r0, -0x1
  addi      r4, r31, 0x636B
  lbz       r3, 0xC(r6)
  rlwimi    r3,r29,7,24,24
  li        r5, 0x1
  stb       r3, 0xC(r6)
  lwz       r6, 0x28(r30)
  lbz       r3, 0xC(r6)
  rlwimi    r3,r29,7,24,24
  stb       r3, 0xC(r6)
  lwz       r6, 0x2C(r30)
  lbz       r3, 0xC(r6)
  rlwimi    r3,r29,7,24,24
  stb       r3, 0xC(r6)
  stw       r0, 0x4(r30)
  stb       r29, 0x0(r30)
  lwz       r3, 0x14(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x48(r30)
  addi      r4, r31, 0x636B
  li        r5, 0x1
  lwz       r3, 0x48(r30)
  stb       r29, 0xF0(r3)
  lwz       r3, 0x48(r30)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r29,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x18(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x4C(r30)
  mr        r3, r30
  lwz       r4, 0x4C(r30)
  stb       r29, 0xF0(r4)
  lwz       r4, 0x4C(r30)
  lbz       r0, 0xC(r4)
  rlwimi    r0,r29,7,24,24
  stb       r0, 0xC(r4)
  lwz       r0, 0x7C(r1)
  lwz       r31, 0x74(r1)
  lwz       r30, 0x70(r1)
  lwz       r29, 0x6C(r1)
  lwz       r28, 0x68(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8018263C
 * Size:	00008C
 */
void zen::ogScrPauseMgr::start(bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r3
  stb       r4, 0x44(r3)
  lbz       r0, 0x44(r3)
  cmplwi    r0, 0
  beq-      .loc_0x40
  lwz       r0, 0x3C(r31)
  lwz       r3, 0x34(r31)
  stw       r0, 0x10C(r3)
  lwz       r0, 0x3C(r31)
  lwz       r3, 0x38(r31)
  stw       r0, 0x10C(r3)
  b         .loc_0x58

.loc_0x40:
  lwz       r0, 0x40(r31)
  lwz       r3, 0x34(r31)
  stw       r0, 0x10C(r3)
  lwz       r0, 0x40(r31)
  lwz       r3, 0x38(r31)
  stw       r0, 0x10C(r3)

.loc_0x58:
  lwz       r3, 0xC(r31)
  li        r4, -0x1
  bl        0x4161C
  li        r0, 0x1
  stw       r0, 0x4(r31)
  lfs       f0, -0x5098(r2)
  stfs      f0, 0x50(r31)
  stb       r0, 0x0(r31)
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801826C8
 * Size:	0003C0
 */
void zen::ogScrPauseMgr::update(Controller *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x98(r1)
  stw       r31, 0x94(r1)
  mr        r31, r3
  stw       r30, 0x90(r1)
  stw       r29, 0x8C(r1)
  addi      r29, r4, 0
  lwz       r3, 0x4(r3)
  cmpwi     r3, -0x1
  bne-      .loc_0x30
  b         .loc_0x3A4

.loc_0x30:
  cmpwi     r3, 0x5
  blt-      .loc_0x48
  li        r0, -0x1
  stw       r0, 0x4(r31)
  lwz       r3, 0x4(r31)
  b         .loc_0x3A4

.loc_0x48:
  lwz       r3, 0x2F6C(r13)
  bl        -0x101B64
  cmpwi     r3, 0
  beq-      .loc_0x74
  lwz       r3, 0x2F6C(r13)
  bl        -0x101B60
  subi      r30, r3, 0x1
  lwz       r3, 0x2F6C(r13)
  bl        -0x101B80
  cmpw      r3, r30
  bne-      .loc_0x88

.loc_0x74:
  lwz       r3, 0xC(r31)
  li        r4, 0x1
  li        r5, 0
  bl        0x421C4
  b         .loc_0x98

.loc_0x88:
  lwz       r3, 0xC(r31)
  li        r4, 0x1
  li        r5, 0x1
  bl        0x421B0

.loc_0x98:
  lwz       r3, 0x1C(r31)
  bl        0x303EC
  lwz       r3, 0xC(r31)
  mr        r4, r29
  bl        0x41D64
  lwz       r3, 0x10(r31)
  mr        r4, r29
  bl        0x41D58
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x50(r31)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x50(r31)
  lwz       r6, 0x4(r31)
  cmpwi     r6, 0x2
  beq-      .loc_0x14C
  bge-      .loc_0xEC
  cmpwi     r6, 0
  beq-      .loc_0x1A8
  bge-      .loc_0xF8
  b         .loc_0x3A0

.loc_0xEC:
  cmpwi     r6, 0x5
  bge-      .loc_0x3A0
  b         .loc_0x2EC

.loc_0xF8:
  lfs       f2, 0x50(r31)
  lfs       f1, -0x5094(r2)
  fcmpo     cr0, f2, f1
  bge-      .loc_0x134
  lfs       f0, -0x5090(r2)
  fmuls     f0, f0, f2
  fdivs     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x80(r1)
  lwz       r0, 0x84(r1)
  stb       r0, 0x54(r31)
  lbz       r0, 0x54(r31)
  lwz       r3, 0x20(r31)
  stb       r0, 0xF0(r3)
  b         .loc_0x3A0

.loc_0x134:
  lwz       r3, 0x20(r31)
  li        r4, 0x80
  li        r0, 0
  stb       r4, 0xF0(r3)
  stw       r0, 0x4(r31)
  b         .loc_0x3A0

.loc_0x14C:
  lfs       f2, 0x50(r31)
  lfs       f1, -0x5094(r2)
  fcmpo     cr0, f2, f1
  bge-      .loc_0x18C
  lfs       f0, -0x5090(r2)
  fmuls     f0, f0, f2
  fdivs     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x80(r1)
  lwz       r0, 0x84(r1)
  stb       r0, 0x54(r31)
  lbz       r0, 0x54(r31)
  lwz       r3, 0x20(r31)
  subfic    r0, r0, 0x80
  stb       r0, 0xF0(r3)
  b         .loc_0x3A0

.loc_0x18C:
  lwz       r3, 0x20(r31)
  li        r4, 0
  stb       r4, 0xF0(r3)
  lwz       r0, 0x8(r31)
  stw       r0, 0x4(r31)
  stb       r4, 0x0(r31)
  b         .loc_0x3A0

.loc_0x1A8:
  lwz       r4, 0xC(r31)
  lwz       r0, 0x1D0(r4)
  lwz       r3, 0x100(r4)
  cmpwi     r0, 0
  blt-      .loc_0x1C4
  lwz       r0, 0x110(r4)
  b         .loc_0x1DC

.loc_0x1C4:
  lbz       r0, 0x1D4(r4)
  cmplwi    r0, 0
  beq-      .loc_0x1D8
  li        r0, -0x1
  b         .loc_0x1DC

.loc_0x1D8:
  lwz       r0, 0x110(r4)

.loc_0x1DC:
  cmpwi     r3, 0
  bne-      .loc_0x3A0
  cmpwi     r0, 0
  bgt-      .loc_0x208
  li        r0, 0x5
  stw       r0, 0x8(r31)
  li        r0, 0x2
  stw       r0, 0x4(r31)
  lfs       f0, -0x5098(r2)
  stfs      f0, 0x50(r31)
  b         .loc_0x3A0

.loc_0x208:
  cmpwi     r0, 0x1
  bne-      .loc_0x260
  li        r0, 0x3
  stw       r0, 0x4(r31)
  li        r4, 0
  lwz       r3, 0x10(r31)
  bl        0x413D0
  lwz       r3, 0x24(r31)
  li        r5, 0
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x28(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r5,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x2C(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x3A0

.loc_0x260:
  cmpwi     r0, 0x2
  bne-      .loc_0x3A0
  li        r0, 0x4
  stw       r0, 0x4(r31)
  li        r4, 0
  lwz       r3, 0x10(r31)
  bl        0x41378
  lwz       r3, 0x24(r31)
  li        r4, 0
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x28(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lwz       r3, 0x2C(r31)
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  lbz       r0, 0x44(r31)
  cmplwi    r0, 0
  beq-      .loc_0x2D4
  lwz       r3, 0x24(r31)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x3A0

.loc_0x2D4:
  lwz       r3, 0x28(r31)
  li        r4, 0x1
  lbz       r0, 0xC(r3)
  rlwimi    r0,r4,7,24,24
  stb       r0, 0xC(r3)
  b         .loc_0x3A0

.loc_0x2EC:
  lwz       r3, 0x10(r31)
  lwz       r0, 0x1D0(r3)
  lwz       r4, 0x100(r3)
  cmpwi     r0, 0
  blt-      .loc_0x308
  lwz       r5, 0x110(r3)
  b         .loc_0x320

.loc_0x308:
  lbz       r0, 0x1D4(r3)
  cmplwi    r0, 0
  beq-      .loc_0x31C
  li        r5, -0x1
  b         .loc_0x320

.loc_0x31C:
  lwz       r5, 0x110(r3)

.loc_0x320:
  cmpwi     r4, 0
  bne-      .loc_0x3A0
  cmpwi     r5, 0
  bne-      .loc_0x370
  cmpwi     r6, 0x4
  beq-      .loc_0x354
  bge-      .loc_0x35C
  cmpwi     r6, 0x3
  bge-      .loc_0x348
  b         .loc_0x35C

.loc_0x348:
  li        r0, 0x6
  stw       r0, 0x8(r31)
  b         .loc_0x35C

.loc_0x354:
  li        r0, 0x7
  stw       r0, 0x8(r31)

.loc_0x35C:
  li        r0, 0x2
  stw       r0, 0x4(r31)
  lfs       f0, -0x5098(r2)
  stfs      f0, 0x50(r31)
  b         .loc_0x3A0

.loc_0x370:
  lbz       r0, 0x1D4(r3)
  cmplwi    r0, 0
  bne-      .loc_0x384
  cmpwi     r5, 0x1
  bne-      .loc_0x3A0

.loc_0x384:
  li        r4, -0x1
  bl        0x41EE8
  lwz       r3, 0xC(r31)
  li        r4, -0x1
  bl        0x4125C
  li        r0, 0
  stw       r0, 0x4(r31)

.loc_0x3A0:
  lwz       r3, 0x4(r31)

.loc_0x3A4:
  lwz       r0, 0x9C(r1)
  lwz       r31, 0x94(r1)
  lwz       r30, 0x90(r1)
  lwz       r29, 0x8C(r1)
  addi      r1, r1, 0x98
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80182A88
 * Size:	0000B0
 */
void zen::ogScrPauseMgr::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x100(r1)
  stw       r31, 0xFC(r1)
  addi      r31, r4, 0
  stw       r30, 0xF8(r1)
  mr        r30, r3
  lwz       r0, 0x4(r3)
  cmpwi     r0, -0x1
  beq-      .loc_0x98
  lfs       f1, -0x508C(r2)
  addi      r3, r1, 0x10
  lfs       f2, -0x5088(r2)
  li        r4, 0
  lfs       f3, -0x5084(r2)
  li        r5, 0
  li        r6, 0x280
  li        r7, 0x1E0
  bl        0x2D6C0
  addi      r3, r1, 0x10
  bl        0x2D7C8
  lwz       r3, 0x1C(r30)
  addi      r6, r1, 0x10
  li        r4, 0
  li        r5, 0
  bl        0x303E8
  lwz       r3, 0xC(r30)
  mr        r4, r31
  bl        0x41DE8
  lwz       r3, 0x10(r30)
  mr        r4, r31
  bl        0x41DDC
  lis       r3, 0x802E
  addi      r0, r3, 0x698
  lis       r3, 0x802E
  stw       r0, 0x10(r1)
  addi      r0, r3, 0x5D4
  stw       r0, 0x10(r1)

.loc_0x98:
  lwz       r0, 0x104(r1)
  lwz       r31, 0xFC(r1)
  lwz       r30, 0xF8(r1)
  addi      r1, r1, 0x100
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80182B38
 * Size:	00005C
 */
P2DPerspGraph::~P2DPerspGraph()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr.       r31, r3
  beq-      .loc_0x44
  lis       r3, 0x802E
  addi      r0, r3, 0x698
  stw       r0, 0x0(r31)
  beq-      .loc_0x34
  lis       r3, 0x802E
  addi      r0, r3, 0x5D4
  stw       r0, 0x0(r31)

.loc_0x34:
  extsh.    r0, r4
  ble-      .loc_0x44
  mr        r3, r31
  bl        -0x13B9CC

.loc_0x44:
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
