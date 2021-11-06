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
 * Address:	80164B80
 * Size:	000008
 */
SlimeAi::SlimeAi(Slime *)
{
/*
.loc_0x0:
  stw       r4, 0x20(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80164B88
 * Size:	0000A8
 */
void SlimeAi::init(Slime *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0x7
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  mr        r31, r3
  stw       r4, 0x20(r3)
  addi      r3, r1, 0x30
  li        r4, 0
  lwz       r5, 0x20(r31)
  stw       r0, 0x2E4(r5)
  lwz       r5, 0x20(r31)
  stw       r0, 0x2E8(r5)
  bl        -0x45C64
  lwz       r5, 0x20(r31)
  addi      r4, r3, 0
  addi      r3, r5, 0x33C
  bl        -0x45A0C
  li        r4, 0
  stb       r4, 0x0(r31)
  li        r3, 0x1
  li        r0, -0x1
  stb       r3, 0x1(r31)
  stw       r4, 0x4(r31)
  stw       r4, 0xC(r31)
  stw       r0, 0x8(r31)
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0x10(r31)
  stfs      f0, 0x14(r31)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x240(r3)
  stfs      f0, 0x18(r31)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x250(r3)
  stfs      f0, 0x1C(r31)
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80164C30
 * Size:	000014
 */
void SlimeAi::addDamagePoint(float)
{
/*
.loc_0x0:
  lwz       r3, 0x20(r3)
  lfs       f0, 0x2C0(r3)
  fadds     f0, f0, f1
  stfs      f0, 0x2C0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void SlimeAi::setEveryFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void SlimeAi::afterProcessing()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80164C44
 * Size:	000310
 */
void SlimeAi::calcBubblePiki()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x90(r1)
  stfd      f31, 0x88(r1)
  stfd      f30, 0x80(r1)
  stmw      r25, 0x64(r1)
  mr        r28, r3
  lwz       r0, 0xC(r3)
  cmpwi     r0, 0x1
  beq-      .loc_0x60
  bge-      .loc_0x38
  cmpwi     r0, 0
  bge-      .loc_0x44
  b         .loc_0x98

.loc_0x38:
  cmpwi     r0, 0x3
  bge-      .loc_0x98
  b         .loc_0x7C

.loc_0x44:
  lwz       r5, 0x20(r28)
  lis       r3, 0x7374
  addi      r4, r3, 0x6B31
  lwz       r3, 0x220(r5)
  bl        -0xDB588
  mr        r29, r3
  b         .loc_0xB0

.loc_0x60:
  lwz       r5, 0x20(r28)
  lis       r3, 0x7374
  addi      r4, r3, 0x6B32
  lwz       r3, 0x220(r5)
  bl        -0xDB5A4
  mr        r29, r3
  b         .loc_0xB0

.loc_0x7C:
  lwz       r5, 0x20(r28)
  lis       r3, 0x7374
  addi      r4, r3, 0x6B33
  lwz       r3, 0x220(r5)
  bl        -0xDB5C0
  mr        r29, r3
  b         .loc_0xB0

.loc_0x98:
  lwz       r5, 0x20(r28)
  lis       r3, 0x7374
  addi      r4, r3, 0x6B34
  lwz       r3, 0x220(r5)
  bl        -0xDB5DC
  mr        r29, r3

.loc_0xB0:
  cmplwi    r29, 0
  beq-      .loc_0x2D4
  lwz       r31, 0x3068(r13)
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lis       r5, 0x802B
  lfs       f31, -0x54A4(r2)
  lis       r4, 0x802B
  lfs       f30, -0x54A8(r2)
  addi      r30, r3, 0
  subi      r26, r5, 0x3064
  subi      r27, r4, 0x3090
  b         .loc_0x278

.loc_0xF0:
  cmpwi     r30, -0x1
  bne-      .loc_0x118
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r25, r3
  b         .loc_0x134

.loc_0x118:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r25, r3

.loc_0x134:
  cmplwi    r25, 0
  beq-      .loc_0x25C
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x25C
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x25C
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x25C
  lhz       r0, 0x510(r25)
  cmplwi    r0, 0
  beq-      .loc_0x25C
  lfs       f1, 0x94(r25)
  lfs       f2, 0x9C(r25)
  lfs       f3, 0x4(r29)
  lfs       f4, 0xC(r29)
  bl        -0x12C7C8
  lfs       f0, 0x0(r29)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x25C
  stfs      f30, 0x38(r1)
  stfs      f30, 0x34(r1)
  stfs      f30, 0x30(r1)
  lfs       f1, 0x4(r29)
  lfs       f0, 0x94(r25)
  lfs       f4, 0xC(r29)
  lfs       f3, 0x9C(r25)
  fsubs     f0, f1, f0
  lfs       f2, 0x8(r29)
  lfs       f1, 0x98(r25)
  fsubs     f3, f4, f3
  stfs      f0, 0x28(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x28(r1)
  stfs      f0, 0x30(r1)
  stfs      f1, 0x34(r1)
  stfs      f3, 0x38(r1)
  lfs       f1, 0x30(r1)
  lfs       f0, 0x34(r1)
  lfs       f2, 0x38(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x157224
  lfs       f0, 0x0(r29)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x25C
  lwz       r0, 0x20(r28)
  addi      r3, r25, 0
  addi      r4, r1, 0x40
  stw       r26, 0x40(r1)
  stw       r0, 0x44(r1)
  stw       r27, 0x40(r1)
  stfs      f31, 0x48(r1)
  lwz       r12, 0x0(r25)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl      

.loc_0x25C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x278:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2A0
  li        r0, 0x1
  b         .loc_0x2CC

.loc_0x2A0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x2C8
  li        r0, 0x1
  b         .loc_0x2CC

.loc_0x2C8:
  li        r0, 0

.loc_0x2CC:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0xF0

.loc_0x2D4:
  lwz       r3, 0xC(r28)
  addi      r0, r3, 0x1
  stw       r0, 0xC(r28)
  lwz       r0, 0xC(r28)
  cmpwi     r0, 0x3
  ble-      .loc_0x2F4
  li        r0, 0
  stw       r0, 0xC(r28)

.loc_0x2F4:
  lmw       r25, 0x64(r1)
  lwz       r0, 0x94(r1)
  lfd       f31, 0x88(r1)
  lfd       f30, 0x80(r1)
  addi      r1, r1, 0x90
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80164F54
 * Size:	0000C4
 */
void SlimeAi::calcStickersRatio()
{
/*
.loc_0x0:
  stwu      r1, -0x48(r1)
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0x14(r3)
  lwz       r5, 0x20(r3)
  lwz       r4, 0x3F8(r5)
  lwz       r4, 0x3BC(r4)
  lwz       r0, 0x4(r4)
  cmpwi     r0, 0
  ble-      .loc_0x6C
  xoris     r0, r0, 0x8000
  lwz       r4, 0x224(r5)
  stw       r0, 0x44(r1)
  lis       r0, 0x4330
  lfd       f2, -0x5498(r2)
  stw       r0, 0x40(r1)
  lfs       f0, 0x290(r4)
  lfd       f1, 0x40(r1)
  lfs       f3, 0x14(r3)
  fsubs     f1, f1, f2
  fdivs     f0, f1, f0
  fadds     f0, f3, f0
  stfs      f0, 0x14(r3)
  lfs       f1, 0x14(r3)
  lfs       f0, -0x54A0(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x6C
  stfs      f0, 0x14(r3)

.loc_0x6C:
  lwz       r4, 0x20(r3)
  lfs       f0, -0x54A0(r2)
  lfs       f2, 0x14(r3)
  lwz       r5, 0x224(r4)
  fsubs     f3, f0, f2
  lfs       f1, 0x240(r5)
  lfs       f0, 0x260(r5)
  fmuls     f1, f3, f1
  fmuls     f0, f2, f0
  fadds     f0, f1, f0
  stfs      f0, 0x18(r3)
  lwz       r4, 0x20(r3)
  lfs       f1, 0x14(r3)
  lwz       r5, 0x224(r4)
  lfs       f2, 0x250(r5)
  lfs       f0, 0x270(r5)
  fmuls     f2, f3, f2
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x1C(r3)
  addi      r1, r1, 0x48
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void SlimeAi::setLeaderIndex()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000194
 */
void SlimeAi::makeInterrelation()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000104
 */
void SlimeAi::makeBodyThickness()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80165018
 * Size:	000164
 */
void SlimeAi::playExpandingSound()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stfd      f31, 0x40(r1)
  stw       r31, 0x3C(r1)
  mr        r31, r3
  lwz       r3, 0x20(r3)
  lfs       f0, -0x54A8(r2)
  lwz       r3, 0x3F4(r3)
  lwz       r4, 0xC(r3)
  lwz       r3, 0x0(r3)
  stfs      f0, 0x30(r1)
  stfs      f0, 0x2C(r1)
  stfs      f0, 0x28(r1)
  lfsu      f1, 0x94(r4)
  lfsu      f0, 0x94(r3)
  lfs       f4, 0x8(r4)
  fsubs     f0, f1, f0
  lfs       f3, 0x8(r3)
  lfs       f2, 0x4(r4)
  lfs       f1, 0x4(r3)
  fsubs     f3, f4, f3
  stfs      f0, 0x24(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x24(r1)
  stfs      f0, 0x28(r1)
  stfs      f1, 0x2C(r1)
  stfs      f3, 0x30(r1)
  lfs       f1, 0x28(r1)
  lfs       f0, 0x2C(r1)
  lfs       f2, 0x30(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x157468
  lfs       f0, 0x18(r31)
  lwz       r3, 0x20(r31)
  fdivs     f31, f1, f0
  lbz       r0, 0x3C4(r3)
  cmplwi    r0, 0
  beq-      .loc_0x12C
  lbz       r0, 0x1(r31)
  cmplwi    r0, 0
  beq-      .loc_0x12C
  lfs       f0, -0x5490(r2)
  fcmpo     cr0, f31, f0
  ble-      .loc_0x12C
  lfs       f1, 0x14(r31)
  lfs       f0, -0x548C(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xEC
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x124
  li        r4, 0x94
  bl        -0xC132C
  b         .loc_0x124

.loc_0xEC:
  lfs       f0, -0x54A8(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x110
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x124
  li        r4, 0x93
  bl        -0xC1350
  b         .loc_0x124

.loc_0x110:
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x124
  li        r4, 0x92
  bl        -0xC1368

.loc_0x124:
  li        r0, 0
  stb       r0, 0x1(r31)

.loc_0x12C:
  lbz       r0, 0x1(r31)
  cmplwi    r0, 0
  bne-      .loc_0x14C
  lfs       f0, -0x5488(r2)
  fcmpo     cr0, f31, f0
  bge-      .loc_0x14C
  li        r0, 0x1
  stb       r0, 0x1(r31)

.loc_0x14C:
  lwz       r0, 0x4C(r1)
  lfd       f31, 0x40(r1)
  lwz       r31, 0x3C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8016517C
 * Size:	00033C
 */
void SlimeAi::calcCollisionCheck()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x188(r1)
  stfd      f31, 0x180(r1)
  stfd      f30, 0x178(r1)
  stfd      f29, 0x170(r1)
  stfd      f28, 0x168(r1)
  stw       r31, 0x164(r1)
  mr        r31, r3
  lwz       r5, 0x20(r31)
  lfs       f3, 0x13C(r13)
  lwz       r4, 0x3F4(r5)
  lwz       r3, 0x4(r4)
  lfsu      f0, 0x94(r3)
  lfs       f2, 0x8(r3)
  fmuls     f0, f0, f3
  lfs       f1, 0x4(r3)
  fmuls     f2, f2, f3
  stfs      f0, 0xC0(r1)
  fmuls     f1, f1, f3
  lfs       f0, 0xC0(r1)
  stfs      f0, 0x12C(r1)
  stfs      f1, 0x130(r1)
  stfs      f2, 0x134(r1)
  lwz       r3, 0x0(r4)
  lfsu      f0, 0x94(r3)
  lfs       f3, 0x138(r13)
  lfs       f2, 0x8(r3)
  lfs       f1, 0x4(r3)
  fmuls     f0, f0, f3
  fmuls     f2, f2, f3
  fmuls     f1, f1, f3
  stfs      f0, 0xBC(r1)
  lfs       f0, 0xBC(r1)
  stfs      f0, 0x138(r1)
  stfs      f1, 0x13C(r1)
  stfs      f2, 0x140(r1)
  lfs       f1, 0x138(r1)
  lfs       f0, 0x12C(r1)
  fadds     f0, f1, f0
  stfs      f0, 0xF0(r1)
  lfs       f0, 0xF0(r1)
  stfs      f0, 0x144(r1)
  lfs       f1, 0x13C(r1)
  lfs       f0, 0x130(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x148(r1)
  lfs       f1, 0x140(r1)
  lfs       f0, 0x134(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x14C(r1)
  lwz       r3, 0x144(r1)
  lwz       r0, 0x148(r1)
  stw       r3, 0x3E8(r5)
  stw       r0, 0x3EC(r5)
  lwz       r0, 0x14C(r1)
  stw       r0, 0x3F0(r5)
  lwz       r5, 0x20(r31)
  lfs       f3, 0x144(r13)
  lwz       r4, 0x3F4(r5)
  lwz       r3, 0xC(r4)
  lfsu      f0, 0x94(r3)
  lfs       f2, 0x8(r3)
  fmuls     f0, f0, f3
  lfs       f1, 0x4(r3)
  fmuls     f2, f2, f3
  stfs      f0, 0xB8(r1)
  fmuls     f1, f1, f3
  lfs       f0, 0xB8(r1)
  stfs      f0, 0x108(r1)
  stfs      f1, 0x10C(r1)
  stfs      f2, 0x110(r1)
  lwz       r3, 0x8(r4)
  lfsu      f0, 0x94(r3)
  lfs       f3, 0x140(r13)
  lfs       f2, 0x8(r3)
  lfs       f1, 0x4(r3)
  fmuls     f0, f0, f3
  fmuls     f2, f2, f3
  fmuls     f1, f1, f3
  stfs      f0, 0xB4(r1)
  lfs       f0, 0xB4(r1)
  stfs      f0, 0x114(r1)
  stfs      f1, 0x118(r1)
  stfs      f2, 0x11C(r1)
  lfs       f1, 0x114(r1)
  lfs       f0, 0x108(r1)
  fadds     f0, f1, f0
  stfs      f0, 0xE4(r1)
  lfs       f0, 0xE4(r1)
  stfs      f0, 0x120(r1)
  lfs       f1, 0x118(r1)
  lfs       f0, 0x10C(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x124(r1)
  lfs       f1, 0x11C(r1)
  lfs       f0, 0x110(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x128(r1)
  lwz       r3, 0x120(r1)
  lwz       r0, 0x124(r1)
  stw       r3, 0x3DC(r5)
  stw       r0, 0x3E0(r5)
  lwz       r0, 0x128(r1)
  stw       r0, 0x3E4(r5)
  lwz       r3, 0x20(r31)
  lwz       r0, 0x2E4(r3)
  cmpwi     r0, 0x8
  beq-      .loc_0x318
  lwz       r4, 0x3FC(r3)
  lwz       r3, 0x3F8(r3)
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0xDC(r1)
  stfs      f0, 0xD8(r1)
  stfs      f0, 0xD4(r1)
  lfsu      f1, 0x94(r4)
  lfsu      f0, 0x94(r3)
  lfs       f4, 0x8(r4)
  fsubs     f0, f1, f0
  lfs       f3, 0x8(r3)
  lfs       f2, 0x4(r4)
  lfs       f1, 0x4(r3)
  fsubs     f3, f4, f3
  stfs      f0, 0xB0(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0xB0(r1)
  stfs      f0, 0xD4(r1)
  stfs      f1, 0xD8(r1)
  stfs      f3, 0xDC(r1)
  lfs       f1, 0xD4(r1)
  lfs       f0, 0xD8(r1)
  lfs       f2, 0xDC(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x157760
  lwz       r5, 0x20(r31)
  lwz       r3, 0x224(r5)
  lfs       f0, 0x280(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x318
  fsubs     f1, f0, f1
  lwz       r4, 0x3F8(r5)
  lwz       r3, 0x3FC(r5)
  lfs       f0, -0x548C(r2)
  lfsu      f3, 0x94(r3)
  lfsu      f2, 0x94(r4)
  fmuls     f28, f1, f0
  lfs       f1, 0x4(r3)
  lfs       f0, 0x4(r4)
  fsubs     f31, f3, f2
  lfs       f2, 0x8(r3)
  fsubs     f30, f1, f0
  lfs       f0, 0x8(r4)
  fmuls     f1, f31, f31
  fsubs     f29, f2, f0
  fmuls     f0, f30, f30
  fmuls     f2, f29, f29
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x1577C4
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x2A4
  fdivs     f31, f31, f1
  fdivs     f30, f30, f1
  fdivs     f29, f29, f1

.loc_0x2A4:
  fmuls     f31, f31, f28
  lwz       r3, 0x20(r31)
  lfsu      f0, 0x3E8(r3)
  fmuls     f30, f30, f28
  fmuls     f29, f29, f28
  fadds     f0, f0, f31
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r3)
  fadds     f0, f0, f30
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r3)
  fadds     f0, f0, f29
  stfs      f0, 0x8(r3)
  lwz       r3, 0x20(r31)
  lfsu      f0, 0x3DC(r3)
  fsubs     f0, f0, f31
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r3)
  fsubs     f0, f0, f30
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r3)
  fsubs     f0, f0, f29
  stfs      f0, 0x8(r3)
  lwz       r3, 0x20(r31)
  lwz       r0, 0x2E4(r3)
  cmpwi     r0, 0x5
  bne-      .loc_0x318
  mr        r3, r31
  bl        0xB7C

.loc_0x318:
  lwz       r0, 0x18C(r1)
  lfd       f31, 0x180(r1)
  lfd       f30, 0x178(r1)
  lfd       f29, 0x170(r1)
  lfd       f28, 0x168(r1)
  lwz       r31, 0x164(r1)
  addi      r1, r1, 0x188
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801654B8
 * Size:	0000E8
 */
void SlimeAi::setLeaderNearerTarget()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stfd      f31, 0x38(r1)
  stw       r31, 0x34(r1)
  mr        r31, r3
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  stw       r28, 0x28(r1)
  lwz       r30, 0x20(r3)
  lwz       r3, 0x3F8(r30)
  lwz       r3, 0x3BC(r3)
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0
  bne-      .loc_0xC4
  lwz       r0, 0x3CC(r30)
  addi      r28, r30, 0x30C
  lwz       r4, 0x3F4(r30)
  rlwinm    r0,r0,2,0,29
  lwz       r3, 0x3C8(r30)
  lwzx      r5, r4, r0
  rlwinm    r0,r3,2,0,29
  lfs       f3, 0x30C(r30)
  lwzx      r29, r4, r0
  lfs       f1, 0x94(r5)
  lfs       f2, 0x9C(r5)
  lfs       f4, 0x314(r30)
  bl        -0x12CEFC
  fmr       f31, f1
  lfs       f1, 0x94(r29)
  lfs       f2, 0x9C(r29)
  lfs       f3, 0x0(r28)
  lfs       f4, 0x8(r28)
  bl        -0x12CF14
  lwz       r3, 0x224(r30)
  lfs       f0, 0x280(r3)
  fsubs     f0, f1, f0
  fcmpo     cr0, f0, f31
  ble-      .loc_0xC4
  lwz       r3, 0x20(r31)
  li        r0, 0x1
  addi      r4, r3, 0x3C8
  lwz       r3, 0x3CC(r3)
  lwz       r5, 0x0(r4)
  stw       r3, 0x0(r4)
  lwz       r3, 0x20(r31)
  stw       r5, 0x3CC(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x3C4(r3)

.loc_0xC4:
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
 * Address:	801655A0
 * Size:	000118
 */
void SlimeAi::moveFlagCheck()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  mr        r31, r3
  lwz       r4, 0x20(r3)
  lfs       f0, -0x54A8(r2)
  lwz       r3, 0x3CC(r4)
  lwz       r0, 0x3C8(r4)
  lwz       r5, 0x3F4(r4)
  rlwinm    r3,r3,2,0,29
  rlwinm    r0,r0,2,0,29
  lwzx      r4, r5, r3
  lwzx      r3, r5, r0
  stfs      f0, 0x38(r1)
  stfs      f0, 0x34(r1)
  stfs      f0, 0x30(r1)
  lfsu      f1, 0x94(r4)
  lfsu      f0, 0x94(r3)
  lfs       f4, 0x8(r4)
  fsubs     f0, f1, f0
  lfs       f3, 0x8(r3)
  lfs       f2, 0x4(r4)
  lfs       f1, 0x4(r3)
  fsubs     f3, f4, f3
  stfs      f0, 0x24(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x24(r1)
  stfs      f0, 0x30(r1)
  stfs      f1, 0x34(r1)
  stfs      f3, 0x38(r1)
  lfs       f1, 0x30(r1)
  lfs       f0, 0x34(r1)
  lfs       f2, 0x38(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x1579FC
  lfs       f0, 0x18(r31)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xD4
  lwz       r3, 0x20(r31)
  lbzu      r0, 0x3C4(r3)
  cmplwi    r0, 0
  beq-      .loc_0x104
  li        r0, 0
  stb       r0, 0x0(r3)
  lfs       f0, -0x54A8(r2)
  lwz       r3, 0x20(r31)
  stfs      f0, 0x2D8(r3)
  b         .loc_0x104

.loc_0xD4:
  lfs       f0, 0x1C(r31)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x104
  lwz       r3, 0x20(r31)
  lbzu      r0, 0x3C4(r3)
  cmplwi    r0, 0
  bne-      .loc_0x104
  li        r0, 0x1
  stb       r0, 0x0(r3)
  lfs       f0, -0x54A8(r2)
  lwz       r3, 0x20(r31)
  stfs      f0, 0x2D8(r3)

.loc_0x104:
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void SlimeAi::makeTargetPosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801656B8
 * Size:	000144
 */
void SlimeAi::makeFollowerVelocity()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  mr        r30, r3
  lwz       r4, 0x20(r3)
  lwz       r3, 0x3CC(r4)
  lbz       r0, 0x3C4(r4)
  lwz       r4, 0x3F4(r4)
  rlwinm    r3,r3,2,0,29
  cmplwi    r0, 0
  lwzx      r31, r4, r3
  bne-      .loc_0x114
  lfs       f1, 0x2BC(r31)
  lfs       f0, 0x94(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0xA4(r31)
  lfs       f1, 0x2C0(r31)
  lfs       f0, 0x98(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0xA8(r31)
  lfs       f1, 0x2C4(r31)
  lfs       f0, 0x9C(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0xAC(r31)
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0xA8(r31)
  lfs       f1, 0xA4(r31)
  lfs       f0, 0xA8(r31)
  lfs       f2, 0xAC(r31)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x157B08
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xC4
  lfs       f0, 0xA4(r31)
  fdivs     f0, f0, f1
  stfs      f0, 0xA4(r31)
  lfs       f0, 0xA8(r31)
  fdivs     f0, f0, f1
  stfs      f0, 0xA8(r31)
  lfs       f0, 0xAC(r31)
  fdivs     f0, f0, f1
  stfs      f0, 0xAC(r31)

.loc_0xC4:
  lwz       r3, 0x20(r30)
  lfs       f4, 0x14(r30)
  lwz       r4, 0x224(r3)
  lfs       f0, -0x54A0(r2)
  lfs       f1, 0x230(r4)
  fsubs     f3, f0, f4
  lfs       f2, 0x220(r4)
  fmuls     f1, f4, f1
  lfs       f0, 0xA4(r31)
  fmuls     f2, f3, f2
  fadds     f1, f2, f1
  fmuls     f0, f0, f1
  stfs      f0, 0xA4(r31)
  lfs       f0, 0xA8(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0xA8(r31)
  lfs       f0, 0xAC(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0xAC(r31)
  b         .loc_0x12C

.loc_0x114:
  lfs       f0, 0x148(r13)
  stfs      f0, 0xA4(r31)
  lfs       f0, 0x14C(r13)
  stfs      f0, 0xA8(r31)
  lfs       f0, 0x150(r13)
  stfs      f0, 0xAC(r31)

.loc_0x12C:
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
 * Address:	801657FC
 * Size:	000124
 */
void SlimeAi::makeLeaderVelocity()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r3
  lwz       r4, 0x20(r3)
  lwz       r3, 0x3C8(r4)
  lbz       r0, 0x3C4(r4)
  lwz       r4, 0x3F4(r4)
  rlwinm    r3,r3,2,0,29
  cmplwi    r0, 0
  lwzx      r31, r4, r3
  beq-      .loc_0xF4
  lfs       f1, 0x2BC(r31)
  lfs       f0, 0x94(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0xA4(r31)
  lfs       f1, 0x2C0(r31)
  lfs       f0, 0x98(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0xA8(r31)
  lfs       f1, 0x2C4(r31)
  lfs       f0, 0x9C(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0xAC(r31)
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0xA8(r31)
  lfs       f1, 0xA4(r31)
  lfs       f0, 0xA8(r31)
  lfs       f2, 0xAC(r31)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x157C4C
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xC4
  lfs       f0, 0xA4(r31)
  fdivs     f0, f0, f1
  stfs      f0, 0xA4(r31)
  lfs       f0, 0xA8(r31)
  fdivs     f0, f0, f1
  stfs      f0, 0xA8(r31)
  lfs       f0, 0xAC(r31)
  fdivs     f0, f0, f1
  stfs      f0, 0xAC(r31)

.loc_0xC4:
  lwz       r3, 0x20(r30)
  lfs       f0, 0xA4(r31)
  lfs       f1, 0x3D0(r3)
  fmuls     f0, f0, f1
  stfs      f0, 0xA4(r31)
  lfs       f0, 0xA8(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0xA8(r31)
  lfs       f0, 0xAC(r31)
  fmuls     f0, f0, f1
  stfs      f0, 0xAC(r31)
  b         .loc_0x10C

.loc_0xF4:
  lfs       f0, 0x154(r13)
  stfs      f0, 0xA4(r31)
  lfs       f0, 0x158(r13)
  stfs      f0, 0xA8(r31)
  lfs       f0, 0x15C(r13)
  stfs      f0, 0xAC(r31)

.loc_0x10C:
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
 * Address:	80165920
 * Size:	0000E8
 */
void SlimeAi::setMidPointVelocity()
{
/*
.loc_0x0:
  li        r9, 0x1
  li        r7, 0x4
  b         .loc_0xD0

.loc_0xC:
  lwz       r5, 0x20(r3)
  addi      r9, r9, 0x1
  lwz       r4, 0x3F4(r5)
  lwz       r5, 0x224(r5)
  lwzx      r4, r4, r7
  lfs       f1, 0x2A0(r5)
  lfsu      f0, 0x70(r4)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r4)
  lfs       f0, 0x4(r4)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r4)
  lfs       f0, 0x8(r4)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r4)
  lwz       r4, 0x20(r3)
  lfs       f5, -0x54A8(r2)
  lwz       r5, 0x3F4(r4)
  lwz       r4, 0x224(r4)
  lwzx      r8, r5, r7
  lfs       f3, 0x2B0(r4)
  lfs       f1, 0x94(r8)
  lfs       f2, 0x2BC(r8)
  fmuls     f5, f5, f3
  lfs       f0, 0x70(r8)
  fsubs     f4, f2, f1
  lfs       f2, 0x2C4(r8)
  lfs       f1, 0x9C(r8)
  fmuls     f4, f4, f3
  fsubs     f1, f2, f1
  fadds     f0, f0, f4
  fmuls     f1, f1, f3
  stfs      f0, 0x70(r8)
  lfs       f0, 0x74(r8)
  fadds     f0, f0, f5
  stfs      f0, 0x74(r8)
  lfs       f0, 0x78(r8)
  fadds     f0, f0, f1
  stfs      f0, 0x78(r8)
  lwz       r4, 0x20(r3)
  lwz       r4, 0x3F4(r4)
  lwzx      r5, r4, r7
  addi      r7, r7, 0x4
  lwz       r4, 0x70(r5)
  lwz       r0, 0x74(r5)
  stw       r4, 0xA4(r5)
  stw       r0, 0xA8(r5)
  lwz       r0, 0x78(r5)
  stw       r0, 0xAC(r5)

.loc_0xD0:
  lwz       r4, 0x3168(r13)
  lwz       r4, 0x28(r4)
  subi      r0, r4, 0x1
  cmpw      r9, r0
  blt+      .loc_0xC
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000584
 */
void SlimeAi::walkAllState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80165A08
 * Size:	000104
 */
void SlimeAi::calcContractDamage()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stw       r31, 0x74(r1)
  mr        r31, r3
  lwz       r3, 0x20(r3)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x3F8(r3)
  lwz       r3, 0x3FC(r3)
  stfs      f0, 0x68(r1)
  stfs      f0, 0x64(r1)
  stfs      f0, 0x60(r1)
  lfsu      f1, 0x94(r4)
  lfsu      f0, 0x94(r3)
  lfs       f4, 0x8(r4)
  fsubs     f0, f1, f0
  lfs       f3, 0x8(r3)
  lfs       f2, 0x4(r4)
  lfs       f1, 0x4(r3)
  fsubs     f3, f4, f3
  stfs      f0, 0x48(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x48(r1)
  stfs      f0, 0x60(r1)
  stfs      f1, 0x64(r1)
  stfs      f3, 0x68(r1)
  lfs       f1, 0x60(r1)
  lfs       f0, 0x64(r1)
  lfs       f2, 0x68(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x157E50
  lwz       r3, 0x20(r31)
  lwz       r4, 0x224(r3)
  lfs       f0, 0x2C0(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xB8
  lfs       f0, 0x2E0(r4)
  li        r0, 0x2
  fmuls     f0, f1, f0
  stfs      f0, 0x10(r31)
  stw       r0, 0x8(r31)
  b         .loc_0xF0

.loc_0xB8:
  lfs       f0, 0x2D0(r4)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xDC
  lfs       f0, 0x2F0(r4)
  li        r0, 0x1
  fmuls     f0, f1, f0
  stfs      f0, 0x10(r31)
  stw       r0, 0x8(r31)
  b         .loc_0xF0

.loc_0xDC:
  lfs       f0, 0x300(r4)
  li        r0, 0
  fmuls     f0, f1, f0
  stfs      f0, 0x10(r31)
  stw       r0, 0x8(r31)

.loc_0xF0:
  lwz       r0, 0x7C(r1)
  lwz       r31, 0x74(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80165B0C
 * Size:	000280
 */
void SlimeAi::contractCoreFlickPiki()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB0(r1)
  stfd      f31, 0xA8(r1)
  stfd      f30, 0xA0(r1)
  stfd      f29, 0x98(r1)
  stmw      r25, 0x7C(r1)
  mr        r28, r3
  lwz       r3, 0x20(r3)
  lwz       r3, 0x3FC(r3)
  lwz       r3, 0x220(r3)
  bl        -0xDC430
  lwz       r30, 0x3068(r13)
  mr        r31, r3
  lfs       f1, -0x5484(r2)
  mr        r3, r30
  lfs       f0, 0x0(r31)
  lwz       r12, 0x0(r30)
  fadds     f31, f1, f0
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lis       r5, 0x802B
  lfs       f30, -0x5480(r2)
  lis       r4, 0x802B
  lfs       f29, -0x54A8(r2)
  addi      r29, r3, 0
  subi      r26, r5, 0x3064
  subi      r27, r4, 0x3168
  b         .loc_0x204

.loc_0x78:
  cmpwi     r29, -0x1
  bne-      .loc_0xA0
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r25, r3
  b         .loc_0xBC

.loc_0xA0:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r25, r3

.loc_0xBC:
  cmplwi    r25, 0
  beq-      .loc_0x1E8
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1E8
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1E8
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x1E8
  lfs       f1, 0x94(r25)
  lfs       f2, 0x9C(r25)
  lfs       f3, 0x4(r31)
  lfs       f4, 0xC(r31)
  bl        -0x12D60C
  fcmpo     cr0, f1, f31
  bge-      .loc_0x1E8
  stfs      f29, 0x50(r1)
  stfs      f29, 0x4C(r1)
  stfs      f29, 0x48(r1)
  lfs       f1, 0x4(r31)
  lfs       f0, 0x94(r25)
  lfs       f4, 0xC(r31)
  lfs       f3, 0x9C(r25)
  fsubs     f0, f1, f0
  lfs       f2, 0x8(r31)
  lfs       f1, 0x98(r25)
  fsubs     f3, f4, f3
  stfs      f0, 0x3C(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x3C(r1)
  stfs      f0, 0x48(r1)
  stfs      f1, 0x4C(r1)
  stfs      f3, 0x50(r1)
  lfs       f1, 0x48(r1)
  lfs       f0, 0x4C(r1)
  lfs       f2, 0x50(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x158064
  fcmpo     cr0, f1, f31
  bge-      .loc_0x1E8
  lwz       r5, 0x20(r28)
  addi      r3, r25, 0
  addi      r4, r1, 0x58
  lwz       r7, 0x3FC(r5)
  lwz       r6, 0x224(r7)
  lfs       f0, 0x128(r6)
  lfs       f1, 0x138(r6)
  stw       r26, 0x58(r1)
  stw       r7, 0x5C(r1)
  stw       r27, 0x58(r1)
  stfs      f0, 0x60(r1)
  stfs      f1, 0x64(r1)
  stfs      f30, 0x68(r1)
  lwz       r12, 0x0(r25)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl      

.loc_0x1E8:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0x204:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x22C
  li        r0, 0x1
  b         .loc_0x258

.loc_0x22C:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x254
  li        r0, 0x1
  b         .loc_0x258

.loc_0x254:
  li        r0, 0

.loc_0x258:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x78
  lmw       r25, 0x7C(r1)
  lwz       r0, 0xB4(r1)
  lfd       f31, 0xA8(r1)
  lfd       f30, 0xA0(r1)
  lfd       f29, 0x98(r1)
  addi      r1, r1, 0xB0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80165D8C
 * Size:	000280
 */
void SlimeAi::contractSubFlickPiki()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB0(r1)
  stfd      f31, 0xA8(r1)
  stfd      f30, 0xA0(r1)
  stfd      f29, 0x98(r1)
  stmw      r25, 0x7C(r1)
  mr        r28, r3
  lwz       r3, 0x20(r3)
  lwz       r3, 0x3F8(r3)
  lwz       r3, 0x220(r3)
  bl        -0xDC6B0
  lwz       r30, 0x3068(r13)
  mr        r31, r3
  lfs       f1, -0x5484(r2)
  mr        r3, r30
  lfs       f0, 0x0(r31)
  lwz       r12, 0x0(r30)
  fadds     f31, f1, f0
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lis       r5, 0x802B
  lfs       f30, -0x5480(r2)
  lis       r4, 0x802B
  lfs       f29, -0x54A8(r2)
  addi      r29, r3, 0
  subi      r26, r5, 0x3064
  subi      r27, r4, 0x3168
  b         .loc_0x204

.loc_0x78:
  cmpwi     r29, -0x1
  bne-      .loc_0xA0
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r25, r3
  b         .loc_0xBC

.loc_0xA0:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r25, r3

.loc_0xBC:
  cmplwi    r25, 0
  beq-      .loc_0x1E8
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1E8
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1E8
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x1E8
  lfs       f1, 0x94(r25)
  lfs       f2, 0x9C(r25)
  lfs       f3, 0x4(r31)
  lfs       f4, 0xC(r31)
  bl        -0x12D88C
  fcmpo     cr0, f1, f31
  bge-      .loc_0x1E8
  stfs      f29, 0x50(r1)
  stfs      f29, 0x4C(r1)
  stfs      f29, 0x48(r1)
  lfs       f1, 0x4(r31)
  lfs       f0, 0x94(r25)
  lfs       f4, 0xC(r31)
  lfs       f3, 0x9C(r25)
  fsubs     f0, f1, f0
  lfs       f2, 0x8(r31)
  lfs       f1, 0x98(r25)
  fsubs     f3, f4, f3
  stfs      f0, 0x3C(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x3C(r1)
  stfs      f0, 0x48(r1)
  stfs      f1, 0x4C(r1)
  stfs      f3, 0x50(r1)
  lfs       f1, 0x48(r1)
  lfs       f0, 0x4C(r1)
  lfs       f2, 0x50(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x1582E4
  fcmpo     cr0, f1, f31
  bge-      .loc_0x1E8
  lwz       r5, 0x20(r28)
  addi      r3, r25, 0
  addi      r4, r1, 0x58
  lwz       r7, 0x3F8(r5)
  lwz       r6, 0x224(r7)
  lfs       f0, 0x128(r6)
  lfs       f1, 0x138(r6)
  stw       r26, 0x58(r1)
  stw       r7, 0x5C(r1)
  stw       r27, 0x58(r1)
  stfs      f0, 0x60(r1)
  stfs      f1, 0x64(r1)
  stfs      f30, 0x68(r1)
  lwz       r12, 0x0(r25)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl      

.loc_0x1E8:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0x204:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x22C
  li        r0, 0x1
  b         .loc_0x258

.loc_0x22C:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x254
  li        r0, 0x1
  b         .loc_0x258

.loc_0x254:
  li        r0, 0

.loc_0x258:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x78
  lmw       r25, 0x7C(r1)
  lwz       r0, 0xB4(r1)
  lfd       f31, 0xA8(r1)
  lfd       f30, 0xA0(r1)
  lfd       f29, 0x98(r1)
  addi      r1, r1, 0xB0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8016600C
 * Size:	00029C
 */
void SlimeAi::inCaseOfContract()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stw       r31, 0x54(r1)
  mr        r31, r3
  lbz       r0, 0x0(r3)
  cmplwi    r0, 0
  bne-      .loc_0x288
  li        r0, 0x1
  stb       r0, 0x0(r31)
  mr        r3, r31
  bl        -0x2AC
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x20
  addi      r5, r1, 0x1C
  lfs       f0, 0x3E4(r3)
  addi      r8, r3, 0x3DC
  lfs       f1, 0x3F0(r3)
  addi      r7, r3, 0x3E8
  addi      r4, r1, 0x18
  fadds     f0, f1, f0
  addi      r3, r1, 0x2C
  stfs      f0, 0x20(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fadds     f0, f1, f0
  stfs      f0, 0x1C(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fadds     f0, f1, f0
  stfs      f0, 0x18(r1)
  bl        -0x12EF6C
  lfs       f2, 0x34(r1)
  addi      r6, r1, 0x14
  lfs       f3, 0x160(r13)
  addi      r5, r1, 0x10
  lfs       f1, 0x30(r1)
  lfs       f0, 0x2C(r1)
  fmuls     f2, f2, f3
  fmuls     f1, f1, f3
  addi      r4, r1, 0xC
  fmuls     f0, f0, f3
  stfs      f2, 0x14(r1)
  addi      r3, r1, 0x38
  stfs      f1, 0x10(r1)
  stfs      f0, 0xC(r1)
  bl        -0x12EFA8
  lfs       f1, 0x38(r1)
  lfs       f0, 0x3C(r1)
  stfs      f1, 0x44(r1)
  stfs      f0, 0x48(r1)
  lfs       f1, 0x40(r1)
  lfs       f0, -0x547C(r2)
  stfs      f1, 0x4C(r1)
  lfs       f1, 0x48(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x48(r1)
  lwz       r0, 0x8(r31)
  cmpwi     r0, 0
  bne-      .loc_0x168
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x44
  li        r4, 0x3F
  li        r6, 0
  li        r7, 0
  bl        0x36A28
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x44
  li        r4, 0x3E
  li        r6, 0
  li        r7, 0
  bl        0x36A10
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x44
  li        r4, 0x3D
  li        r6, 0
  li        r7, 0
  bl        0x369F8
  lwz       r3, 0x3178(r13)
  addi      r6, r1, 0x44
  li        r4, 0xF
  li        r5, 0
  bl        0x16C80
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x264
  li        r4, 0x8E
  bl        -0xC239C
  b         .loc_0x264

.loc_0x168:
  cmpwi     r0, 0x1
  bne-      .loc_0x1E8
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x44
  li        r4, 0x3C
  li        r6, 0
  li        r7, 0
  bl        0x369A8
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x44
  li        r4, 0x3B
  li        r6, 0
  li        r7, 0
  bl        0x36990
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x44
  li        r4, 0x3A
  li        r6, 0
  li        r7, 0
  bl        0x36978
  lwz       r3, 0x3178(r13)
  addi      r6, r1, 0x44
  li        r4, 0xA
  li        r5, 0
  bl        0x16C00
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x264
  li        r4, 0x8F
  bl        -0xC241C
  b         .loc_0x264

.loc_0x1E8:
  cmpwi     r0, 0x2
  bne-      .loc_0x264
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x44
  li        r4, 0x39
  li        r6, 0
  li        r7, 0
  bl        0x36928
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x44
  li        r4, 0x38
  li        r6, 0
  li        r7, 0
  bl        0x36910
  lwz       r3, 0x3180(r13)
  addi      r5, r1, 0x44
  li        r4, 0x37
  li        r6, 0
  li        r7, 0
  bl        0x368F8
  lwz       r3, 0x3178(r13)
  addi      r6, r1, 0x44
  li        r4, 0xE
  li        r5, 0
  bl        0x16B80
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x264
  li        r4, 0x90
  bl        -0xC249C

.loc_0x264:
  lwz       r3, 0x20(r31)
  li        r0, -0x1
  lfs       f0, 0x10(r31)
  lfs       f1, 0x2C0(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2C0(r3)
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0x10(r31)
  stw       r0, 0x8(r31)

.loc_0x288:
  lwz       r0, 0x5C(r1)
  lwz       r31, 0x54(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
void SlimeAi::setDieGoal()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000204
 */
void SlimeAi::setContractGoal()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000204
 */
void SlimeAi::setExpansionGoal()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
void SlimeAi::setAppearGoal()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000154
 */
void SlimeAi::bothEndsToGoal()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void SlimeAi::bothEndsToAppearGoal()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801662A8
 * Size:	00016C
 */
void SlimeAi::makeTargetRandom()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x90(r1)
  stfd      f31, 0x88(r1)
  stw       r31, 0x84(r1)
  mr        r31, r3
  stw       r30, 0x80(r1)
  stw       r29, 0x7C(r1)
  lwz       r3, 0x2DEC(r13)
  lwz       r4, 0x20(r31)
  lfs       f0, 0x28C(r3)
  lfs       f1, 0x2D0(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x2D0(r4)
  lwz       r3, 0x20(r31)
  lfs       f0, -0x5470(r2)
  lfs       f1, 0x2D0(r3)
  addi      r4, r3, 0x30C
  lwz       r0, 0x3C8(r3)
  addi      r30, r3, 0x300
  fcmpo     cr0, f1, f0
  lwz       r3, 0x3F4(r3)
  rlwinm    r0,r0,2,0,29
  lwzx      r3, r3, r0
  bgt-      .loc_0x84
  lfs       f1, 0x0(r4)
  lfs       f2, 0x8(r4)
  lfs       f3, 0x94(r3)
  lfs       f4, 0x9C(r3)
  bl        -0x12DCF4
  lfs       f0, -0x5470(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x14C

.loc_0x84:
  bl        0xB1D44
  xoris     r0, r3, 0x8000
  lfd       f4, -0x5498(r2)
  stw       r0, 0x74(r1)
  lis       r0, 0x4330
  lfs       f3, -0x546C(r2)
  stw       r0, 0x70(r1)
  lfs       f2, -0x54A0(r2)
  lfd       f0, 0x70(r1)
  lfs       f1, -0x5468(r2)
  fsubs     f4, f0, f4
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0x68(r1)
  fdivs     f3, f4, f3
  stfs      f0, 0x64(r1)
  stfs      f0, 0x60(r1)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x224(r3)
  fmuls     f0, f2, f3
  addi      r29, r3, 0x78
  fmuls     f31, f1, f0
  fmr       f1, f31
  bl        0xB5964
  lfs       f0, 0x0(r29)
  lwz       r3, 0x20(r31)
  fmuls     f2, f0, f1
  lfs       f0, 0x8(r30)
  lwz       r3, 0x224(r3)
  fmr       f1, f31
  fadds     f31, f0, f2
  addi      r29, r3, 0x78
  bl        0xB57AC
  lfs       f2, 0x0(r29)
  lfs       f0, 0x0(r30)
  fmuls     f1, f2, f1
  fadds     f0, f0, f1
  stfs      f0, 0x60(r1)
  lfs       f0, 0x4(r30)
  stfs      f0, 0x64(r1)
  stfs      f31, 0x68(r1)
  lwz       r4, 0x20(r31)
  lwz       r3, 0x60(r1)
  lwz       r0, 0x64(r1)
  stw       r3, 0x30C(r4)
  stw       r0, 0x310(r4)
  lwz       r0, 0x68(r1)
  stw       r0, 0x314(r4)
  lfs       f0, -0x54A8(r2)
  lwz       r3, 0x20(r31)
  stfs      f0, 0x2D0(r3)

.loc_0x14C:
  lwz       r0, 0x94(r1)
  lfd       f31, 0x88(r1)
  lwz       r31, 0x84(r1)
  lwz       r30, 0x80(r1)
  lwz       r29, 0x7C(r1)
  addi      r1, r1, 0x90
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void SlimeAi::setVelocity(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void SlimeAi::motionFinishTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SlimeAi::dieTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void SlimeAi::outSideChaseRangeTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void SlimeAi::inSideWaitRangeTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80166414
 * Size:	000308
 */
void SlimeAi::chaseNaviTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xF0(r1)
  stfd      f31, 0xE8(r1)
  stfd      f30, 0xE0(r1)
  stmw      r25, 0xC4(r1)
  mr        r26, r3
  li        r29, 0
  lwz       r3, 0x20(r3)
  lfs       f31, -0x5464(r2)
  lwz       r0, 0x3C8(r3)
  addi      r27, r3, 0x300
  lwz       r4, 0x318(r3)
  lwz       r3, 0x3F4(r3)
  rlwinm    r0,r0,2,0,29
  cmplwi    r4, 0
  lwzx      r28, r3, r0
  beq-      .loc_0xB8
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0x9C(r1)
  stfs      f0, 0x98(r1)
  stfs      f0, 0x94(r1)
  lfs       f1, 0x94(r4)
  lfs       f0, 0x94(r28)
  lfs       f4, 0x9C(r4)
  fsubs     f0, f1, f0
  lfs       f3, 0x9C(r28)
  lfs       f2, 0x98(r4)
  lfs       f1, 0x98(r28)
  fsubs     f3, f4, f3
  stfs      f0, 0x70(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x70(r1)
  stfs      f0, 0x94(r1)
  stfs      f1, 0x98(r1)
  stfs      f3, 0x9C(r1)
  lfs       f1, 0x94(r1)
  lfs       f0, 0x98(r1)
  lfs       f2, 0x9C(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x158884
  fmr       f31, f1

.loc_0xB8:
  lwz       r31, 0x3120(r13)
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f30, -0x54A8(r2)
  mr        r30, r3
  b         .loc_0x274

.loc_0xDC:
  cmpwi     r30, -0x1
  bne-      .loc_0x104
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r25, r3
  b         .loc_0x120

.loc_0x104:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r25, r3

.loc_0x120:
  lwz       r12, 0x0(r25)
  mr        r3, r25
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x258
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x258
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x258
  lfs       f1, 0x94(r25)
  lfs       f2, 0x9C(r25)
  lfs       f3, 0x0(r27)
  lfs       f4, 0x8(r27)
  bl        -0x12DF70
  lwz       r3, 0x20(r26)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x68(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x258
  lfs       f1, 0x94(r28)
  lfs       f2, 0x9C(r28)
  lfs       f3, 0x94(r25)
  lfs       f4, 0x9C(r25)
  bl        -0x12DF98
  lwz       r3, 0x20(r26)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x258
  fcmpo     cr0, f1, f31
  bge-      .loc_0x258
  stfs      f30, 0x84(r1)
  stfs      f30, 0x80(r1)
  stfs      f30, 0x7C(r1)
  lfs       f1, 0x94(r25)
  lfs       f0, 0x94(r28)
  lfs       f4, 0x9C(r25)
  lfs       f3, 0x9C(r28)
  fsubs     f0, f1, f0
  lfs       f2, 0x98(r25)
  lfs       f1, 0x98(r28)
  fsubs     f3, f4, f3
  stfs      f0, 0x68(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x68(r1)
  stfs      f0, 0x7C(r1)
  stfs      f1, 0x80(r1)
  stfs      f3, 0x84(r1)
  lfs       f1, 0x7C(r1)
  lfs       f0, 0x80(r1)
  lfs       f2, 0x84(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x158A04
  lwz       r3, 0x20(r26)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x258
  fcmpo     cr0, f1, f31
  bge-      .loc_0x258
  fmr       f31, f1
  mr        r29, r25

.loc_0x258:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x274:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x29C
  li        r0, 0x1
  b         .loc_0x2C8

.loc_0x29C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x2C4
  li        r0, 0x1
  b         .loc_0x2C8

.loc_0x2C4:
  li        r0, 0

.loc_0x2C8:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0xDC
  cmplwi    r29, 0
  beq-      .loc_0x2E8
  lwz       r4, 0x20(r26)
  li        r3, 0x1
  stw       r29, 0x318(r4)
  b         .loc_0x2EC

.loc_0x2E8:
  li        r3, 0

.loc_0x2EC:
  lmw       r25, 0xC4(r1)
  lwz       r0, 0xF4(r1)
  lfd       f31, 0xE8(r1)
  lfd       f30, 0xE0(r1)
  addi      r1, r1, 0xF0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8016671C
 * Size:	00030C
 */
void SlimeAi::chasePikiTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xF0(r1)
  stfd      f31, 0xE8(r1)
  stfd      f30, 0xE0(r1)
  stmw      r25, 0xC4(r1)
  mr        r26, r3
  li        r29, 0
  lwz       r3, 0x20(r3)
  lfs       f31, -0x5464(r2)
  lwz       r0, 0x3C8(r3)
  addi      r27, r3, 0x300
  lwz       r4, 0x318(r3)
  lwz       r3, 0x3F4(r3)
  rlwinm    r0,r0,2,0,29
  cmplwi    r4, 0
  lwzx      r28, r3, r0
  beq-      .loc_0xB8
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0x9C(r1)
  stfs      f0, 0x98(r1)
  stfs      f0, 0x94(r1)
  lfs       f1, 0x94(r4)
  lfs       f0, 0x94(r28)
  lfs       f4, 0x9C(r4)
  fsubs     f0, f1, f0
  lfs       f3, 0x9C(r28)
  lfs       f2, 0x98(r4)
  lfs       f1, 0x98(r28)
  fsubs     f3, f4, f3
  stfs      f0, 0x70(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x70(r1)
  stfs      f0, 0x94(r1)
  stfs      f1, 0x98(r1)
  stfs      f3, 0x9C(r1)
  lfs       f1, 0x94(r1)
  lfs       f0, 0x98(r1)
  lfs       f2, 0x9C(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x158B8C
  fmr       f31, f1

.loc_0xB8:
  lwz       r31, 0x3068(r13)
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f30, -0x54A8(r2)
  mr        r30, r3
  b         .loc_0x278

.loc_0xDC:
  cmpwi     r30, -0x1
  bne-      .loc_0x100
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x118

.loc_0x100:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x118:
  mr        r25, r3
  lwz       r12, 0x0(r25)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x25C
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x25C
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x25C
  lhz       r0, 0x510(r25)
  cmplwi    r0, 0
  beq-      .loc_0x25C
  lfs       f1, 0x94(r25)
  lfs       f2, 0x9C(r25)
  lfs       f3, 0x0(r27)
  lfs       f4, 0x8(r27)
  bl        -0x12E27C
  lwz       r3, 0x20(r26)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x68(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x25C
  lfs       f1, 0x94(r28)
  lfs       f2, 0x9C(r28)
  lfs       f3, 0x94(r25)
  lfs       f4, 0x9C(r25)
  bl        -0x12E2A4
  lwz       r3, 0x20(r26)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x25C
  fcmpo     cr0, f1, f31
  bge-      .loc_0x25C
  stfs      f30, 0x84(r1)
  stfs      f30, 0x80(r1)
  stfs      f30, 0x7C(r1)
  lfs       f1, 0x94(r25)
  lfs       f0, 0x94(r28)
  lfs       f4, 0x9C(r25)
  lfs       f3, 0x9C(r28)
  fsubs     f0, f1, f0
  lfs       f2, 0x98(r25)
  lfs       f1, 0x98(r28)
  fsubs     f3, f4, f3
  stfs      f0, 0x68(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x68(r1)
  stfs      f0, 0x7C(r1)
  stfs      f1, 0x80(r1)
  stfs      f3, 0x84(r1)
  lfs       f1, 0x7C(r1)
  lfs       f0, 0x80(r1)
  lfs       f2, 0x84(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x158D10
  lwz       r3, 0x20(r26)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x25C
  fcmpo     cr0, f1, f31
  bge-      .loc_0x25C
  fmr       f31, f1
  mr        r29, r25

.loc_0x25C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x278:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2A0
  li        r0, 0x1
  b         .loc_0x2CC

.loc_0x2A0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x2C8
  li        r0, 0x1
  b         .loc_0x2CC

.loc_0x2C8:
  li        r0, 0

.loc_0x2CC:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0xDC
  cmplwi    r29, 0
  beq-      .loc_0x2EC
  lwz       r4, 0x20(r26)
  li        r3, 0x1
  stw       r29, 0x318(r4)
  b         .loc_0x2F0

.loc_0x2EC:
  li        r3, 0

.loc_0x2F0:
  lmw       r25, 0xC4(r1)
  lwz       r0, 0xF4(r1)
  lfd       f31, 0xE8(r1)
  lfd       f30, 0xE0(r1)
  addi      r1, r1, 0xF0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80166A28
 * Size:	000198
 */
void SlimeAi::targetLostTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x70(r1)
  stw       r31, 0x6C(r1)
  stw       r30, 0x68(r1)
  stw       r29, 0x64(r1)
  stw       r28, 0x60(r1)
  mr        r28, r3
  lwz       r4, 0x20(r3)
  lwz       r31, 0x318(r4)
  cmplwi    r31, 0
  beq-      .loc_0x174
  mr        r3, r31
  lwz       r0, 0x3C8(r4)
  lwz       r12, 0x0(r31)
  lwz       r4, 0x3F4(r4)
  rlwinm    r0,r0,2,0,29
  lwz       r12, 0x88(r12)
  lwzx      r29, r4, r0
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x94
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x94
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xA8

.loc_0x94:
  lwz       r4, 0x20(r28)
  li        r0, 0
  li        r3, 0x1
  stw       r0, 0x318(r4)
  b         .loc_0x178

.loc_0xA8:
  lwz       r30, 0x20(r28)
  lfs       f1, 0x94(r31)
  lfs       f2, 0x9C(r31)
  lfs       f3, 0x300(r30)
  lfs       f4, 0x308(r30)
  bl        -0x12E4BC
  lwz       r3, 0x224(r30)
  lfs       f0, 0x68(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0xE4
  lwz       r4, 0x20(r28)
  li        r0, 0
  li        r3, 0x1
  stw       r0, 0x318(r4)
  b         .loc_0x178

.loc_0xE4:
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0x48(r1)
  stfs      f0, 0x44(r1)
  stfs      f0, 0x40(r1)
  lfs       f1, 0x94(r31)
  lfs       f0, 0x94(r29)
  lfs       f4, 0x9C(r31)
  fsubs     f0, f1, f0
  lfs       f3, 0x9C(r29)
  lfs       f2, 0x98(r31)
  lfs       f1, 0x98(r29)
  fsubs     f3, f4, f3
  stfs      f0, 0x34(r1)
  fsubs     f1, f2, f1
  lfs       f0, 0x34(r1)
  stfs      f0, 0x40(r1)
  stfs      f1, 0x44(r1)
  stfs      f3, 0x48(r1)
  lfs       f1, 0x40(r1)
  lfs       f0, 0x44(r1)
  lfs       f2, 0x48(r1)
  fmuls     f1, f1, f1
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x158F34
  lwz       r4, 0x20(r28)
  lwz       r3, 0x224(r4)
  lfs       f0, 0x88(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x174
  li        r0, 0
  stw       r0, 0x318(r4)
  li        r3, 0x1
  b         .loc_0x178

.loc_0x174:
  li        r3, 0

.loc_0x178:
  lwz       r0, 0x74(r1)
  lwz       r31, 0x6C(r1)
  lwz       r30, 0x68(r1)
  lwz       r29, 0x64(r1)
  lwz       r28, 0x60(r1)
  addi      r1, r1, 0x70
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void SlimeAi::collisionContractTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void SlimeAi::dissolutionContractTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void SlimeAi::finishContractTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SlimeAi::finishExpansionTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80166BC0
 * Size:	0002E4
 */
void SlimeAi::appearTransit()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stmw      r27, 0x64(r1)
  mr        r30, r3
  lwz       r29, 0x3120(r13)
  lwz       r4, 0x20(r3)
  lwz       r12, 0x0(r29)
  mr        r3, r29
  addi      r31, r4, 0x300
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r28, r3
  b         .loc_0x118

.loc_0x3C:
  cmpwi     r28, -0x1
  bne-      .loc_0x60
  mr        r3, r29
  lwz       r12, 0x0(r29)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x78

.loc_0x60:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x78:
  mr        r27, r3
  lwz       r12, 0x0(r27)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xFC
  mr        r3, r27
  lwz       r12, 0x0(r27)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xFC
  mr        r3, r27
  lwz       r12, 0x0(r27)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0xFC
  lfs       f1, 0x0(r31)
  lfs       f2, 0x8(r31)
  lfs       f3, 0x94(r27)
  lfs       f4, 0x9C(r27)
  bl        -0x12E674
  lwz       r3, 0x20(r30)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x210(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xFC
  li        r3, 0x1
  b         .loc_0x2D0

.loc_0xFC:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r28, r3

.loc_0x118:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x140
  li        r0, 0x1
  b         .loc_0x16C

.loc_0x140:
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x168
  li        r0, 0x1
  b         .loc_0x16C

.loc_0x168:
  li        r0, 0

.loc_0x16C:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x3C
  lwz       r28, 0x3068(r13)
  mr        r3, r28
  lwz       r12, 0x0(r28)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  b         .loc_0x270

.loc_0x194:
  cmpwi     r29, -0x1
  bne-      .loc_0x1B8
  mr        r3, r28
  lwz       r12, 0x0(r28)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x1D0

.loc_0x1B8:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x1D0:
  mr        r27, r3
  lwz       r12, 0x0(r27)
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x254
  mr        r3, r27
  lwz       r12, 0x0(r27)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x254
  mr        r3, r27
  lwz       r12, 0x0(r27)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x254
  lfs       f1, 0x0(r31)
  lfs       f2, 0x8(r31)
  lfs       f3, 0x94(r27)
  lfs       f4, 0x9C(r27)
  bl        -0x12E7CC
  lwz       r3, 0x20(r30)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x210(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x254
  li        r3, 0x1
  b         .loc_0x2D0

.loc_0x254:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0x270:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x298
  li        r0, 0x1
  b         .loc_0x2C4

.loc_0x298:
  mr        r3, r28
  lwz       r12, 0x0(r28)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x2C0
  li        r0, 0x1
  b         .loc_0x2C4

.loc_0x2C0:
  li        r0, 0

.loc_0x2C4:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x194
  li        r3, 0

.loc_0x2D0:
  lmw       r27, 0x64(r1)
  lwz       r0, 0x7C(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SlimeAi::disAppearTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80166EA4
 * Size:	00053C
 */
void SlimeAi::initDie(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x208(r1)
  stfd      f31, 0x200(r1)
  addi      r6, r1, 0x8C
  addi      r5, r1, 0x88
  stfd      f30, 0x1F8(r1)
  stfd      f29, 0x1F0(r1)
  stfd      f28, 0x1E8(r1)
  stfd      f27, 0x1E0(r1)
  stfd      f26, 0x1D8(r1)
  stfd      f25, 0x1D0(r1)
  stw       r31, 0x1CC(r1)
  mr        r31, r3
  stw       r30, 0x1C8(r1)
  stw       r29, 0x1C4(r1)
  lwz       r3, 0x20(r3)
  stw       r4, 0x2E8(r3)
  addi      r4, r1, 0x84
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  addi      r3, r1, 0x178
  lwz       r7, 0x20(r31)
  lfs       f1, -0x545C(r2)
  lwz       r7, 0x3F8(r7)
  lfs       f0, 0x2C4(r7)
  fsubs     f0, f0, f1
  stfs      f0, 0x2C4(r7)
  lwz       r7, 0x20(r31)
  lwz       r7, 0x3FC(r7)
  lfs       f0, 0x2C4(r7)
  fsubs     f0, f0, f1
  stfs      f0, 0x2C4(r7)
  lfs       f0, -0x54A8(r2)
  lwz       r7, 0x20(r31)
  stfs      f0, 0x2D4(r7)
  lwz       r7, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r10, 0x3F4(r7)
  lwz       r9, 0x224(r7)
  lwz       r8, 0xC(r10)
  lwz       r7, 0x0(r10)
  lfs       f2, 0x280(r9)
  addi      r8, r8, 0x94
  addi      r7, r7, 0x94
  lfs       f3, -0x5478(r2)
  fmuls     f2, f2, f0
  lfs       f1, 0x8(r7)
  lfs       f0, 0x8(r8)
  fadds     f31, f3, f2
  fadds     f0, f1, f0
  stfs      f0, 0x8C(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fadds     f0, f1, f0
  stfs      f0, 0x88(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fadds     f0, f1, f0
  stfs      f0, 0x84(r1)
  bl        -0x12FE7C
  lfs       f2, 0x180(r1)
  addi      r6, r1, 0x80
  lfs       f3, 0x168(r13)
  addi      r5, r1, 0x7C
  lfs       f1, 0x17C(r1)
  lfs       f0, 0x178(r1)
  fmuls     f2, f2, f3
  fmuls     f1, f1, f3
  addi      r4, r1, 0x78
  fmuls     f0, f0, f3
  stfs      f2, 0x80(r1)
  addi      r3, r1, 0x16C
  stfs      f1, 0x7C(r1)
  stfs      f0, 0x78(r1)
  bl        -0x12FEB8
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0xAC
  lfs       f30, 0x174(r1)
  addi      r5, r1, 0xA8
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0x170(r1)
  addi      r4, r1, 0xA4
  lwz       r3, 0x0(r3)
  lfs       f28, 0x16C(r1)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0x184
  fsubs     f0, f0, f30
  stfs      f0, 0xAC(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0xA8(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f28
  stfs      f0, 0xA4(r1)
  bl        -0x12FF0C
  lfs       f27, 0x184(r1)
  lfs       f26, 0x188(r1)
  fmuls     f1, f27, f27
  lfs       f25, 0x18C(r1)
  fmuls     f0, f26, f26
  fmuls     f2, f25, f25
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15940C
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x1C4
  fdivs     f27, f27, f1
  fdivs     f26, f26, f1
  fdivs     f25, f25, f1

.loc_0x1C4:
  fmuls     f27, f27, f31
  addi      r6, r1, 0x74
  fmuls     f26, f26, f31
  addi      r5, r1, 0x70
  fmuls     f25, f25, f31
  fadds     f0, f28, f27
  addi      r4, r1, 0x6C
  fadds     f4, f29, f26
  addi      r3, r1, 0x124
  fadds     f3, f30, f25
  stfs      f0, 0xE0(r1)
  fsubs     f2, f28, f27
  fsubs     f1, f29, f26
  lfs       f5, 0xE0(r1)
  fsubs     f0, f30, f25
  stfs      f5, 0x190(r1)
  stfs      f4, 0x194(r1)
  stfs      f3, 0x198(r1)
  lwz       r8, 0x20(r31)
  lwz       r7, 0x190(r1)
  lwz       r8, 0x3F4(r8)
  lwz       r0, 0x194(r1)
  lwz       r8, 0x0(r8)
  stw       r7, 0x2BC(r8)
  stw       r0, 0x2C0(r8)
  lwz       r0, 0x198(r1)
  stw       r0, 0x2C4(r8)
  stfs      f2, 0xD4(r1)
  lfs       f2, 0xD4(r1)
  stfs      f2, 0x19C(r1)
  stfs      f1, 0x1A0(r1)
  stfs      f0, 0x1A4(r1)
  lwz       r8, 0x20(r31)
  lwz       r7, 0x19C(r1)
  lwz       r8, 0x3F4(r8)
  lwz       r0, 0x1A0(r1)
  lwz       r8, 0xC(r8)
  stw       r7, 0x2BC(r8)
  stw       r0, 0x2C0(r8)
  lwz       r0, 0x1A4(r1)
  stw       r0, 0x2C4(r8)
  lwz       r7, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r10, 0x3F4(r7)
  lwz       r9, 0x224(r7)
  lwz       r8, 0xC(r10)
  lwz       r7, 0x0(r10)
  lfs       f2, 0x280(r9)
  addi      r8, r8, 0x2BC
  addi      r7, r7, 0x2BC
  lfs       f3, -0x547C(r2)
  fmuls     f2, f2, f0
  lfs       f1, 0x8(r7)
  lfs       f0, 0x8(r8)
  fadds     f31, f3, f2
  fadds     f0, f1, f0
  stfs      f0, 0x74(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fadds     f0, f1, f0
  stfs      f0, 0x70(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fadds     f0, f1, f0
  stfs      f0, 0x6C(r1)
  bl        -0x130050
  lfs       f2, 0x12C(r1)
  addi      r6, r1, 0x68
  lfs       f3, 0x16C(r13)
  addi      r5, r1, 0x64
  lfs       f1, 0x128(r1)
  lfs       f0, 0x124(r1)
  fmuls     f2, f2, f3
  fmuls     f1, f1, f3
  addi      r4, r1, 0x60
  fmuls     f0, f0, f3
  stfs      f2, 0x68(r1)
  addi      r3, r1, 0x118
  stfs      f1, 0x64(r1)
  stfs      f0, 0x60(r1)
  bl        -0x13008C
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x9C
  lfs       f28, 0x120(r1)
  addi      r5, r1, 0x98
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0x11C(r1)
  addi      r4, r1, 0x94
  lwz       r3, 0x0(r3)
  lfs       f30, 0x118(r1)
  lfs       f0, 0x2C4(r3)
  addi      r7, r3, 0x2BC
  addi      r3, r1, 0x130
  fsubs     f0, f0, f28
  stfs      f0, 0x9C(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x98(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f30
  stfs      f0, 0x94(r1)
  bl        -0x1300E0
  lfs       f25, 0x130(r1)
  lfs       f26, 0x134(r1)
  fmuls     f1, f25, f25
  lfs       f27, 0x138(r1)
  fmuls     f0, f26, f26
  fmuls     f2, f27, f27
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x1595E0
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x398
  fdivs     f25, f25, f1
  fdivs     f26, f26, f1
  fdivs     f27, f27, f1

.loc_0x398:
  fmuls     f25, f25, f31
  li        r4, 0x32
  fmuls     f26, f26, f31
  fmuls     f27, f27, f31
  fadds     f0, f30, f25
  fadds     f4, f29, f26
  fadds     f3, f28, f27
  stfs      f0, 0xBC(r1)
  fsubs     f2, f30, f25
  fsubs     f1, f29, f26
  lfs       f5, 0xBC(r1)
  fsubs     f0, f28, f27
  stfs      f5, 0x13C(r1)
  stfs      f4, 0x140(r1)
  stfs      f3, 0x144(r1)
  lwz       r5, 0x20(r31)
  lwz       r3, 0x13C(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0x140(r1)
  lwz       r5, 0x0(r5)
  stw       r3, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x144(r1)
  stw       r0, 0x2C4(r5)
  stfs      f2, 0xB0(r1)
  lfs       f2, 0xB0(r1)
  stfs      f2, 0x148(r1)
  stfs      f1, 0x14C(r1)
  stfs      f0, 0x150(r1)
  lwz       r5, 0x20(r31)
  lwz       r3, 0x148(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0x14C(r1)
  lwz       r5, 0xC(r5)
  stw       r3, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x150(r1)
  stw       r0, 0x2C4(r5)
  lwz       r3, 0x2F6C(r13)
  addi      r3, r3, 0x70
  bl        -0xE388C
  li        r29, 0
  rlwinm    r30,r29,2,0,29

.loc_0x444:
  lwz       r5, 0x20(r31)
  li        r4, 0x4B
  lwz       r3, 0x3180(r13)
  li        r6, 0
  lwz       r5, 0x3F4(r5)
  li        r7, 0
  lwzx      r5, r5, r30
  addi      r5, r5, 0x94
  bl        0x35830
  cmplwi    r3, 0
  beq-      .loc_0x484
  lwz       r4, 0x20(r31)
  lwz       r4, 0x3F4(r4)
  lwzx      r4, r4, r30
  addi      r0, r4, 0x94
  stw       r0, 0x18(r3)

.loc_0x484:
  lwz       r5, 0x20(r31)
  li        r4, 0x4A
  lwz       r3, 0x3180(r13)
  li        r6, 0
  lwz       r5, 0x3F4(r5)
  li        r7, 0
  lwzx      r5, r5, r30
  addi      r5, r5, 0x94
  bl        0x357F0
  cmplwi    r3, 0
  beq-      .loc_0x4C4
  lwz       r4, 0x20(r31)
  lwz       r4, 0x3F4(r4)
  lwzx      r4, r4, r30
  addi      r0, r4, 0x94
  stw       r0, 0x18(r3)

.loc_0x4C4:
  addi      r29, r29, 0x1
  cmpwi     r29, 0x4
  addi      r30, r30, 0x4
  blt+      .loc_0x444
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x4EC
  li        r4, 0x8D
  bl        -0xC34E8

.loc_0x4EC:
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x504
  li        r4, 0x95
  bl        -0xC35D4

.loc_0x504:
  lwz       r0, 0x20C(r1)
  lfd       f31, 0x200(r1)
  lfd       f30, 0x1F8(r1)
  lfd       f29, 0x1F0(r1)
  lfd       f28, 0x1E8(r1)
  lfd       f27, 0x1E0(r1)
  lfd       f26, 0x1D8(r1)
  lfd       f25, 0x1D0(r1)
  lwz       r31, 0x1CC(r1)
  lwz       r30, 0x1C8(r1)
  lwz       r29, 0x1C4(r1)
  addi      r1, r1, 0x208
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void SlimeAi::initWalk(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void SlimeAi::initChase(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000360
 */
void SlimeAi::initContract(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000268
 */
void SlimeAi::initExpansion(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000174
 */
void SlimeAi::initAppear(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void SlimeAi::initDisAppear(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000420
 */
void SlimeAi::dieState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00020C
 */
void SlimeAi::walkRandomState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
void SlimeAi::walkGoHomeState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void SlimeAi::chaseNaviState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D0
 */
void SlimeAi::chasePikiState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002C8
 */
void SlimeAi::contractState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002C8
 */
void SlimeAi::expansionState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SlimeAi::stayState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801673E0
 * Size:	000494
 */
void SlimeAi::appearState()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x150(r1)
  stmw      r26, 0x138(r1)
  mr        r26, r3
  lwz       r4, 0x20(r3)
  lfs       f0, -0x5460(r2)
  lfs       f1, 0x2D4(r4)
  lwz       r3, 0x224(r4)
  fcmpo     cr0, f1, f0
  lfs       f6, 0x380(r3)
  bge-      .loc_0xC0
  lfs       f2, -0x54A0(r2)
  fsubs     f3, f1, f0
  lfs       f4, -0x548C(r2)
  fmuls     f0, f6, f1
  fsubs     f5, f1, f2
  lfs       f2, -0x54A8(r2)
  fmuls     f4, f4, f6
  fmuls     f2, f2, f5
  fmuls     f0, f3, f0
  fmuls     f4, f4, f1
  fmuls     f2, f3, f2
  fmuls     f3, f5, f4
  fsubs     f0, f2, f0
  fadds     f0, f3, f0
  stfs      f0, 0x3D4(r4)
  lfs       f0, -0x5454(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x90
  lwz       r3, 0x20(r26)
  lfs       f0, -0x5450(r2)
  lfs       f2, 0x2D8(r3)
  fadds     f0, f2, f0
  stfs      f0, 0x2D8(r3)
  b         .loc_0xC4

.loc_0x90:
  lwz       r3, 0x20(r26)
  lfs       f0, -0x544C(r2)
  lfs       f2, 0x2D8(r3)
  fadds     f0, f2, f0
  stfs      f0, 0x2D8(r3)
  lwz       r3, 0x20(r26)
  lfs       f0, -0x5448(r2)
  lfsu      f2, 0x2D8(r3)
  fcmpo     cr0, f2, f0
  bge-      .loc_0xC4
  stfs      f0, 0x0(r3)
  b         .loc_0xC4

.loc_0xC0:
  stfs      f6, 0x3D4(r4)

.loc_0xC4:
  lwz       r3, 0x20(r26)
  lfs       f7, -0x54A0(r2)
  lfs       f0, 0x2D0(r3)
  fcmpo     cr0, f0, f7
  bge-      .loc_0x1C8
  lfs       f3, -0x5444(r2)
  fcmpo     cr0, f0, f3
  cror      2, 0x1, 0x2
  bne-      .loc_0x148
  lfs       f2, -0x5440(r2)
  fcmpo     cr0, f0, f2
  cror      2, 0, 0x2
  bne-      .loc_0x148
  fsubs     f2, f0, f3
  lfs       f4, -0x543C(r2)
  lfs       f3, -0x5460(r2)
  lwz       r3, 0x3FC(r3)
  fmuls     f8, f4, f2
  lfs       f4, -0x548C(r2)
  lfs       f2, -0x54A8(r2)
  fsubs     f6, f8, f7
  fmuls     f5, f4, f8
  fsubs     f4, f8, f3
  fmuls     f3, f2, f6
  fmuls     f2, f7, f8
  fmuls     f5, f6, f5
  fmuls     f3, f4, f3
  fmuls     f2, f4, f2
  fsubs     f2, f3, f2
  fadds     f2, f5, f2
  stfsu     f2, 0x7C(r3)
  stfs      f2, 0x4(r3)
  stfs      f2, 0x8(r3)

.loc_0x148:
  lfs       f3, -0x5438(r2)
  fcmpo     cr0, f0, f3
  cror      2, 0x1, 0x2
  bne-      .loc_0x1F0
  lfs       f2, -0x5434(r2)
  fcmpo     cr0, f0, f2
  cror      2, 0, 0x2
  bne-      .loc_0x1F0
  fsubs     f2, f0, f3
  lfs       f4, -0x543C(r2)
  lwz       r3, 0x20(r26)
  lfs       f3, -0x54A0(r2)
  fmuls     f7, f4, f2
  lfs       f4, -0x5460(r2)
  lfs       f2, -0x5488(r2)
  fsubs     f6, f7, f3
  lfs       f3, -0x54A8(r2)
  lfs       f5, -0x5430(r2)
  fsubs     f4, f7, f4
  fmuls     f2, f2, f7
  fmuls     f3, f3, f6
  lwz       r3, 0x3F8(r3)
  fmuls     f5, f5, f7
  fmuls     f2, f4, f2
  fmuls     f3, f4, f3
  fmuls     f4, f6, f5
  fsubs     f2, f3, f2
  fadds     f2, f4, f2
  stfsu     f2, 0x7C(r3)
  stfs      f2, 0x4(r3)
  stfs      f2, 0x8(r3)
  b         .loc_0x1F0

.loc_0x1C8:
  lwz       r3, 0x3FC(r3)
  stfsu     f7, 0x7C(r3)
  stfs      f7, 0x4(r3)
  stfs      f7, 0x8(r3)
  lwz       r3, 0x20(r26)
  lfs       f2, -0x5488(r2)
  lwz       r3, 0x3F8(r3)
  stfsu     f2, 0x7C(r3)
  stfs      f2, 0x4(r3)
  stfs      f2, 0x8(r3)

.loc_0x1F0:
  lfs       f2, -0x5460(r2)
  fcmpo     cr0, f1, f2
  ble-      .loc_0x260
  lfs       f1, -0x54A0(r2)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x260
  lwz       r3, 0x20(r26)
  li        r0, 0x1
  stb       r0, 0x2BD(r3)
  lwz       r3, 0x20(r26)
  lwz       r3, 0x3FC(r3)
  stb       r0, 0x2B8(r3)
  lwz       r3, 0x20(r26)
  lwz       r3, 0x3F8(r3)
  stb       r0, 0x2B8(r3)
  lwz       r3, 0x20(r26)
  lwz       r3, 0x3FC(r3)
  stfsu     f1, 0x7C(r3)
  stfs      f1, 0x4(r3)
  stfs      f1, 0x8(r3)
  lwz       r3, 0x20(r26)
  lfs       f0, -0x5488(r2)
  lwz       r3, 0x3F8(r3)
  stfsu     f0, 0x7C(r3)
  stfs      f0, 0x4(r3)
  stfs      f0, 0x8(r3)
  lwz       r3, 0x20(r26)
  stb       r0, 0x3C4(r3)

.loc_0x260:
  lwz       r4, 0x20(r26)
  addi      r30, r1, 0x74
  lwz       r3, 0x2DEC(r13)
  addi      r29, r1, 0x70
  lfs       f2, 0x2D8(r4)
  lfs       f0, 0x28C(r3)
  addi      r28, r1, 0x6C
  lfs       f1, 0x2D4(r4)
  li        r31, 0x1
  fmuls     f0, f2, f0
  li        r27, 0x4
  fadds     f0, f1, f0
  stfs      f0, 0x2D4(r4)
  lwz       r4, 0x20(r26)
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x2D0(r4)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2D0(r4)
  lfs       f0, -0x54A8(r2)
  stfs      f0, 0xB4(r1)
  stfs      f0, 0xB0(r1)
  stfs      f0, 0xAC(r1)
  lwz       r3, 0x20(r26)
  lwz       r3, 0x3F4(r3)
  lwz       r5, 0x0(r3)
  lfs       f0, 0x94(r5)
  lfs       f1, 0x2BC(r5)
  fsubs     f0, f1, f0
  stfs      f0, 0xAC(r1)
  lfs       f1, 0x2C0(r5)
  lfs       f0, 0x98(r5)
  fsubs     f0, f1, f0
  stfs      f0, 0xB0(r1)
  lfs       f1, 0x2C4(r5)
  lfs       f0, 0x9C(r5)
  fsubs     f0, f1, f0
  stfs      f0, 0xB4(r1)
  lfs       f0, 0xAC(r1)
  lfs       f1, -0x548C(r2)
  fmuls     f0, f0, f1
  stfs      f0, 0xAC(r1)
  lfs       f0, 0xB0(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0xB0(r1)
  lfs       f0, 0xB4(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0xB4(r1)
  lwz       r3, 0xAC(r1)
  lwz       r0, 0xB0(r1)
  stw       r3, 0xA4(r5)
  stw       r0, 0xA8(r5)
  lwz       r0, 0xB4(r1)
  stw       r0, 0xAC(r5)
  lwz       r4, 0x20(r26)
  lwz       r3, 0xAC(r1)
  lwz       r4, 0x3F4(r4)
  lwz       r0, 0xB0(r1)
  lwz       r4, 0x0(r4)
  stw       r3, 0x70(r4)
  stw       r0, 0x74(r4)
  lwz       r0, 0xB4(r1)
  stw       r0, 0x78(r4)
  b         .loc_0x46C

.loc_0x360:
  lwz       r3, 0x20(r26)
  addi      r4, r28, 0
  addi      r5, r29, 0
  lwz       r7, 0x3F4(r3)
  mr        r6, r30
  lwz       r8, 0x224(r3)
  addi      r3, r1, 0xA0
  lwzx      r7, r7, r27
  lfs       f1, 0x2A0(r8)
  lfsu      f0, 0x70(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r7)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r7)
  lfs       f0, 0x8(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r7)
  lwz       r7, 0x20(r26)
  lwz       r7, 0x3F4(r7)
  lwzx      r7, r7, r27
  addi      r8, r7, 0x94
  addi      r7, r7, 0x2BC
  lfs       f0, 0x8(r8)
  lfs       f1, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x74(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x70(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x6C(r1)
  bl        -0x1306B0
  lwz       r3, 0x20(r26)
  addi      r31, r31, 0x1
  lfs       f2, 0xA0(r1)
  lwz       r4, 0x224(r3)
  lwz       r3, 0x3F4(r3)
  lfs       f1, 0x2B0(r4)
  lwzx      r3, r3, r27
  fmuls     f2, f2, f1
  lfsu      f0, 0x70(r3)
  lfs       f4, 0xA8(r1)
  lfs       f3, -0x54A8(r2)
  fadds     f0, f0, f2
  fmuls     f3, f3, f1
  fmuls     f4, f4, f1
  stfs      f0, 0x0(r3)
  lfs       f0, 0x4(r3)
  fadds     f0, f0, f3
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r3)
  fadds     f0, f0, f4
  stfs      f0, 0x8(r3)
  lwz       r3, 0x20(r26)
  lwz       r3, 0x3F4(r3)
  lwzx      r4, r3, r27
  addi      r27, r27, 0x4
  lwz       r3, 0x70(r4)
  lwz       r0, 0x74(r4)
  stw       r3, 0xA4(r4)
  stw       r0, 0xA8(r4)
  lwz       r0, 0x78(r4)
  stw       r0, 0xAC(r4)

.loc_0x46C:
  lwz       r3, 0x3168(r13)
  lwz       r3, 0x28(r3)
  subi      r0, r3, 0x1
  cmpw      r31, r0
  blt+      .loc_0x360
  lmw       r26, 0x138(r1)
  lwz       r0, 0x154(r1)
  addi      r1, r1, 0x150
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001B4
 */
void SlimeAi::disAppearState()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80167874
 * Size:	002D88
 */
void SlimeAi::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xBA8(r1)
  stfd      f31, 0xBA0(r1)
  stfd      f30, 0xB98(r1)
  stfd      f29, 0xB90(r1)
  stfd      f28, 0xB88(r1)
  stw       r31, 0xB84(r1)
  mr        r31, r3
  stw       r30, 0xB80(r1)
  bl        -0x2C58
  mr        r3, r31
  bl        -0x2950
  lwz       r0, 0x4(r31)
  cmpwi     r0, 0
  bne-      .loc_0x88
  lwz       r4, 0x20(r31)
  lwz       r3, 0x3F8(r4)
  lwz       r3, 0x3BC(r3)
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0
  ble-      .loc_0x88
  addi      r3, r4, 0x3C8
  lwz       r0, 0x3C8(r4)
  cmpwi     r0, 0x3
  bne-      .loc_0x7C
  li        r0, 0
  stw       r0, 0x0(r3)
  li        r0, 0x3
  lwz       r3, 0x20(r31)
  stw       r0, 0x3CC(r3)

.loc_0x7C:
  lwz       r3, 0x20(r31)
  li        r0, 0x1
  stb       r0, 0x3C4(r3)

.loc_0x88:
  mr        r3, r31
  bl        -0x2784
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x3A4
  lfs       f1, 0x12C(r13)
  addi      r5, r1, 0x3A0
  lwz       r3, 0x3F4(r3)
  addi      r4, r1, 0x39C
  lwz       r3, 0xC(r3)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0xB4C
  fmuls     f0, f0, f1
  stfs      f0, 0x3A4(r1)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x3A0(r1)
  lfs       f0, 0x0(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x39C(r1)
  bl        -0x130830
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x398
  lfs       f1, 0x128(r13)
  addi      r5, r1, 0x394
  lwz       r3, 0x3F4(r3)
  addi      r4, r1, 0x390
  lwz       r3, 0x0(r3)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0xB40
  fmuls     f0, f0, f1
  stfs      f0, 0x398(r1)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x394(r1)
  lfs       f0, 0x0(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x390(r1)
  bl        -0x13087C
  lfs       f1, 0xB48(r1)
  addi      r6, r1, 0x5BC
  lfs       f0, 0xB54(r1)
  addi      r5, r1, 0x5B8
  lfs       f3, 0xB44(r1)
  fadds     f4, f1, f0
  lfs       f2, 0xB50(r1)
  lfs       f1, 0xB40(r1)
  addi      r4, r1, 0x5B4
  lfs       f0, 0xB4C(r1)
  fadds     f2, f3, f2
  stfs      f4, 0x5BC(r1)
  fadds     f0, f1, f0
  addi      r3, r1, 0xB34
  stfs      f2, 0x5B8(r1)
  stfs      f0, 0x5B4(r1)
  bl        -0x1308C0
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x38C
  lwz       r3, 0xB34(r1)
  addi      r5, r1, 0x388
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0xB38(r1)
  addi      r4, r1, 0x384
  lwz       r7, 0x4(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0xB70
  stw       r0, 0x2C0(r7)
  lwz       r0, 0xB3C(r1)
  stw       r0, 0x2C4(r7)
  lwz       r7, 0x20(r31)
  lfs       f1, 0x134(r13)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0xC(r7)
  addi      r7, r7, 0x94
  lfs       f0, 0x8(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x38C(r1)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x388(r1)
  lfs       f0, 0x0(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x384(r1)
  bl        -0x130930
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x380
  lfs       f1, 0x130(r13)
  addi      r5, r1, 0x37C
  lwz       r3, 0x3F4(r3)
  addi      r4, r1, 0x378
  lwz       r3, 0x0(r3)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0xB64
  fmuls     f0, f0, f1
  stfs      f0, 0x380(r1)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x37C(r1)
  lfs       f0, 0x0(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x378(r1)
  bl        -0x13097C
  lfs       f1, 0xB6C(r1)
  addi      r6, r1, 0x5B0
  lfs       f0, 0xB78(r1)
  addi      r5, r1, 0x5AC
  lfs       f3, 0xB68(r1)
  fadds     f4, f1, f0
  lfs       f2, 0xB74(r1)
  lfs       f1, 0xB64(r1)
  addi      r4, r1, 0x5A8
  lfs       f0, 0xB70(r1)
  fadds     f2, f3, f2
  stfs      f4, 0x5B0(r1)
  fadds     f0, f1, f0
  addi      r3, r1, 0xB58
  stfs      f2, 0x5AC(r1)
  stfs      f0, 0x5A8(r1)
  bl        -0x1309C0
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x374
  lwz       r3, 0xB58(r1)
  addi      r5, r1, 0x370
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0xB5C(r1)
  addi      r4, r1, 0x36C
  lwz       r7, 0x8(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0x59C
  stw       r0, 0x2C0(r7)
  lwz       r0, 0xB60(r1)
  stw       r0, 0x2C4(r7)
  lwz       r7, 0x20(r31)
  lfs       f0, -0x54A8(r2)
  lwz       r7, 0x3F4(r7)
  lwz       r8, 0xC(r7)
  lwz       r7, 0x0(r7)
  addi      r8, r8, 0x94
  stfs      f0, 0x5A4(r1)
  addi      r7, r7, 0x94
  stfs      f0, 0x5A0(r1)
  stfs      f0, 0x59C(r1)
  lfs       f1, 0x8(r8)
  lfs       f0, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x374(r1)
  lfs       f1, 0x4(r8)
  lfs       f0, 0x4(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x370(r1)
  lfs       f1, 0x0(r8)
  lfs       f0, 0x0(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x36C(r1)
  bl        -0x10A4E0
  lfs       f1, 0x59C(r1)
  lfs       f0, 0x5A0(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x5A4(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x159F50
  lwz       r5, 0x20(r31)
  lfs       f3, -0x54A8(r2)
  lwz       r4, 0x224(r5)
  lfs       f2, 0x250(r4)
  lfs       f0, 0x260(r4)
  fsubs     f1, f1, f2
  fsubs     f0, f0, f2
  fdivs     f0, f1, f0
  fcmpo     cr0, f0, f3
  bge-      .loc_0x34C
  b         .loc_0x360

.loc_0x34C:
  lfs       f3, -0x54A0(r2)
  fcmpo     cr0, f0, f3
  ble-      .loc_0x35C
  b         .loc_0x360

.loc_0x35C:
  fmr       f3, f0

.loc_0x360:
  lfs       f0, -0x54A0(r2)
  mr        r3, r31
  lfs       f2, 0x350(r4)
  fsubs     f1, f0, f3
  lfs       f0, 0x360(r4)
  fmuls     f2, f3, f2
  fmuls     f0, f1, f0
  fadds     f0, f2, f0
  stfs      f0, 0x3D8(r5)
  bl        -0x2BE0
  lwz       r3, 0x20(r31)
  lfs       f0, -0x54A8(r2)
  lfs       f1, 0x2C0(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x3A0
  bl        -0x196C8

.loc_0x3A0:
  lwz       r5, 0x20(r31)
  lwz       r0, 0x2E4(r5)
  cmplwi    r0, 0x9
  bgt-      .loc_0x2D4C
  lis       r3, 0x802D
  subi      r3, r3, 0x110
  rlwinm    r0,r0,2,0,29
  lwzx      r0, r3, r0
  mtctr     r0
  bctr      
  lfs       f0, -0x54A8(r2)
  addi      r6, r1, 0x580
  addi      r5, r1, 0x57C
  stfs      f0, 0xB24(r1)
  addi      r4, r1, 0x578
  addi      r3, r1, 0xB1C
  stfs      f0, 0xB20(r1)
  stfs      f0, 0xB1C(r1)
  lwz       r8, 0x20(r31)
  lwz       r7, 0x3F4(r8)
  lwz       r8, 0x224(r8)
  lwz       r7, 0x0(r7)
  lfs       f1, 0x310(r8)
  lfsu      f0, 0x70(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r7)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r7)
  lfs       f0, 0x8(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r7)
  lwz       r7, 0x20(r31)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0x0(r7)
  addi      r8, r7, 0x94
  addi      r7, r7, 0x2BC
  lfs       f0, 0x8(r8)
  lfs       f1, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x580(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x57C(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x578(r1)
  bl        -0x130BBC
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x574
  lfs       f0, 0xB1C(r1)
  addi      r5, r1, 0x570
  lwz       r3, 0x224(r3)
  addi      r4, r1, 0x56C
  lfs       f1, 0x320(r3)
  addi      r3, r1, 0xB1C
  fmuls     f0, f0, f1
  stfs      f0, 0xB1C(r1)
  lfs       f0, 0xB20(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0xB20(r1)
  lfs       f0, 0xB24(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0xB24(r1)
  lwz       r7, 0x20(r31)
  lfs       f0, 0xB1C(r1)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0x0(r7)
  lfsu      f1, 0x70(r7)
  fadds     f0, f1, f0
  stfs      f0, 0x0(r7)
  lfs       f1, 0x4(r7)
  lfs       f0, 0xB20(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r7)
  lfs       f1, 0x8(r7)
  lfs       f0, 0xB24(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r7)
  lwz       r8, 0x20(r31)
  lwz       r7, 0x3F4(r8)
  lwz       r8, 0x224(r8)
  lwz       r7, 0xC(r7)
  lfs       f1, 0x310(r8)
  lfsu      f0, 0x70(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r7)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r7)
  lfs       f0, 0x8(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r7)
  lwz       r7, 0x20(r31)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0xC(r7)
  addi      r8, r7, 0x94
  addi      r7, r7, 0x2BC
  lfs       f0, 0x8(r8)
  lfs       f1, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x574(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x570(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x56C(r1)
  bl        -0x130CB8
  lwz       r3, 0x20(r31)
  lfs       f0, 0xB1C(r1)
  lwz       r3, 0x224(r3)
  lfs       f1, 0x320(r3)
  fmuls     f0, f0, f1
  stfs      f0, 0xB1C(r1)
  lfs       f0, 0xB20(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0xB20(r1)
  lfs       f0, 0xB24(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0xB24(r1)
  lwz       r3, 0x20(r31)
  lfs       f0, 0xB1C(r1)
  lwz       r3, 0x3F4(r3)
  lwz       r3, 0xC(r3)
  lfsu      f1, 0x70(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x0(r3)
  lfs       f1, 0x4(r3)
  lfs       f0, 0xB20(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r3)
  lfs       f1, 0x8(r3)
  lfs       f0, 0xB24(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r3)
  lwz       r5, 0x20(r31)
  lfs       f3, -0x54A8(r2)
  lfs       f0, 0x2D4(r5)
  fcmpo     cr0, f0, f3
  ble-      .loc_0x6C0
  lwz       r4, 0x224(r5)
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x330(r4)
  lfs       f0, 0x28C(r3)
  lfs       f2, 0x3D4(r5)
  fmuls     f0, f1, f0
  fsubs     f0, f2, f0
  stfs      f0, 0x3D4(r5)
  lwz       r3, 0x20(r31)
  lfsu      f0, 0x3D4(r3)
  fcmpo     cr0, f0, f3
  bge-      .loc_0x618
  stfs      f3, 0x0(r3)

.loc_0x618:
  lwz       r3, 0x20(r31)
  lbzu      r0, 0x2BD(r3)
  cmplwi    r0, 0
  bne-      .loc_0x6C0
  li        r0, 0x1
  stb       r0, 0x0(r3)
  addi      r3, r1, 0xAFC
  lwz       r4, 0x20(r31)
  lwz       r5, 0x3F4(r4)
  lwz       r4, 0x0(r5)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x94
  addi      r5, r5, 0x94
  bl        .loc_0x2D88
  addi      r3, r1, 0xAF0
  addi      r4, r1, 0xAFC
  addi      r5, r13, 0x164
  bl        -0xC89FC
  lfs       f0, 0xAF0(r1)
  lfs       f1, 0xAF4(r1)
  stfs      f0, 0xAE4(r1)
  lfs       f0, 0xAF8(r1)
  stfs      f1, 0xAE8(r1)
  stfs      f0, 0xAEC(r1)
  lwz       r4, 0x20(r31)
  lwz       r3, 0xAE4(r1)
  lwz       r4, 0x3F4(r4)
  lwz       r0, 0xAE8(r1)
  lwz       r4, 0x0(r4)
  stw       r3, 0x2BC(r4)
  stw       r0, 0x2C0(r4)
  lwz       r0, 0xAEC(r1)
  stw       r0, 0x2C4(r4)
  lwz       r4, 0x20(r31)
  lwz       r3, 0xAE4(r1)
  lwz       r4, 0x3F4(r4)
  lwz       r0, 0xAE8(r1)
  lwz       r4, 0xC(r4)
  stw       r3, 0x2BC(r4)
  stw       r0, 0x2C0(r4)
  lwz       r0, 0xAEC(r1)
  stw       r0, 0x2C4(r4)

.loc_0x6C0:
  mr        r3, r31
  bl        -0x2618
  lwz       r4, 0x20(r31)
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x2D4(r4)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2D4(r4)
  lwz       r3, 0x20(r31)
  lfs       f1, -0x54A8(r2)
  lfs       f0, 0x3D4(r3)
  fcmpu     cr0, f1, f0
  bne-      .loc_0x6FC
  li        r0, 0x1
  b         .loc_0x700

.loc_0x6FC:
  li        r0, 0

.loc_0x700:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x2D4C
  li        r0, 0x9
  stw       r0, 0x2E8(r3)
  li        r0, 0
  li        r5, 0x1
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x3C4(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2B8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2B9(r3)
  lfs       f0, -0x54A8(r2)
  lwz       r3, 0x20(r31)
  stfs      f0, 0x2D4(r3)
  lwz       r3, 0x20(r31)
  lfs       f1, -0x5458(r2)
  addi      r4, r3, 0x94
  bl        -0x19EB4
  lwz       r5, 0x20(r31)
  li        r4, 0x39
  lwz       r3, 0x3180(r13)
  li        r6, 0
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x34B58
  lwz       r5, 0x20(r31)
  li        r4, 0x38
  lwz       r3, 0x3180(r13)
  li        r6, 0
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x34B3C
  lwz       r5, 0x20(r31)
  li        r4, 0x37
  lwz       r3, 0x3180(r13)
  li        r6, 0
  addi      r5, r5, 0x94
  li        r7, 0
  bl        0x34B20
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2D4C
  li        r4, 0x91
  bl        -0xC4260
  b         .loc_0x2D4C
  mr        r3, r31
  bl        -0x1D94
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0x224(r5)
  lfs       f0, 0x220(r4)
  stfs      f0, 0x3D0(r5)
  bl        -0x2B9C
  mr        r3, r31
  bl        -0x2ABC
  lwz       r6, 0x20(r31)
  lwz       r3, 0x3C8(r6)
  lwz       r0, 0x3CC(r6)
  lwz       r7, 0x3F4(r6)
  rlwinm    r4,r3,2,0,29
  rlwinm    r0,r0,2,0,29
  lwz       r3, 0x30C(r6)
  lwzx      r5, r7, r4
  lwzx      r4, r7, r0
  lwz       r0, 0x310(r6)
  stw       r3, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x314(r6)
  stw       r0, 0x2C4(r5)
  lwz       r3, 0x94(r5)
  lwz       r0, 0x98(r5)
  stw       r3, 0x2BC(r4)
  stw       r0, 0x2C0(r4)
  lwz       r0, 0x9C(r5)
  stw       r0, 0x2C4(r4)
  lwz       r3, 0x2DEC(r13)
  bl        -0xE8E08
  lwz       r4, 0x20(r31)
  mr        r3, r31
  lfs       f0, 0x2D8(r4)
  fadds     f0, f0, f1
  stfs      f0, 0x2D8(r4)
  bl        -0x2A14
  mr        r3, r31
  bl        -0x28D8
  mr        r3, r31
  bl        -0x27BC
  lwz       r4, 0x20(r31)
  lfs       f0, -0x54A8(r2)
  lfs       f1, 0x2C4(r4)
  fcmpo     cr0, f1, f0
  mfcr      r0
  rlwinm.   r0,r0,2,31,31
  bne-      .loc_0x898
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x1260
  b         .loc_0x2D4C

.loc_0x898:
  lbz       r0, 0x3C5(r4)
  cmplwi    r0, 0
  beq-      .loc_0x8AC
  li        r0, 0x1
  b         .loc_0x8B0

.loc_0x8AC:
  li        r0, 0

.loc_0x8B0:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0xAC8
  li        r0, 0x5
  stw       r0, 0x2E8(r4)
  li        r0, 0
  addi      r3, r1, 0xA84
  lwz       r4, 0x20(r31)
  stb       r0, 0x2BD(r4)
  stb       r0, 0x0(r31)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x20(r31)
  stfs      f0, 0x2D4(r4)
  lwz       r5, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r4, 0x224(r5)
  lwz       r5, 0x3F4(r5)
  lfs       f1, 0x280(r4)
  lwz       r4, 0x0(r5)
  fmuls     f0, f1, f0
  lfs       f2, -0x5478(r2)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x94
  fadds     f31, f2, f0
  addi      r5, r5, 0x94
  bl        .loc_0x2D88
  addi      r3, r1, 0xA78
  addi      r4, r1, 0xA84
  addi      r5, r13, 0x168
  bl        -0xC8CC0
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x350
  lfs       f30, 0xA80(r1)
  addi      r5, r1, 0x34C
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0xA7C(r1)
  addi      r4, r1, 0x348
  lwz       r3, 0x0(r3)
  lfs       f28, 0xA78(r1)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0xA90
  fsubs     f0, f0, f30
  stfs      f0, 0x350(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x34C(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f28
  stfs      f0, 0x348(r1)
  bl        -0x1310CC
  lfs       f1, 0xA90(r1)
  lfs       f0, 0xA94(r1)
  stfs      f1, 0xA6C(r1)
  stfs      f0, 0xA70(r1)
  lfs       f0, 0xA98(r1)
  stfs      f0, 0xA74(r1)
  lfs       f1, 0xA6C(r1)
  lfs       f0, 0xA70(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0xA74(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15A5E4
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x9C8
  addi      r3, r1, 0xA6C
  bl        -0xDECEC

.loc_0x9C8:
  lfs       f0, 0xA6C(r1)
  addi      r6, r1, 0x558
  addi      r5, r1, 0x554
  fmuls     f0, f0, f31
  addi      r4, r1, 0x550
  addi      r3, r1, 0xA9C
  stfs      f0, 0xA6C(r1)
  lfs       f0, 0xA70(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0xA70(r1)
  lfs       f0, 0xA74(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0xA74(r1)
  lfs       f1, 0xA74(r1)
  lfs       f0, 0xA6C(r1)
  fadds     f1, f30, f1
  fadds     f0, f28, f0
  stfs      f1, 0x558(r1)
  lfs       f1, 0xA70(r1)
  fadds     f1, f29, f1
  stfs      f0, 0x550(r1)
  stfs      f1, 0x554(r1)
  bl        -0x131178
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x54C
  lwz       r3, 0xA9C(r1)
  addi      r5, r1, 0x548
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0xAA0(r1)
  addi      r4, r1, 0x544
  lwz       r7, 0x0(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0xAA8
  stw       r0, 0x2C0(r7)
  lwz       r0, 0xAA4(r1)
  stw       r0, 0x2C4(r7)
  lfs       f1, 0xA74(r1)
  lfs       f0, 0xA6C(r1)
  fsubs     f1, f30, f1
  fsubs     f0, f28, f0
  stfs      f1, 0x54C(r1)
  lfs       f1, 0xA70(r1)
  fsubs     f1, f29, f1
  stfs      f0, 0x544(r1)
  stfs      f1, 0x548(r1)
  bl        -0x1311D4
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0xAA8(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0xAAC(r1)
  lwz       r5, 0xC(r5)
  stw       r4, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0xAB0(r1)
  stw       r0, 0x2C4(r5)
  bl        -0x2914
  mr        r3, r31
  bl        -0x2818
  lwz       r3, 0x20(r31)
  lwz       r3, 0x3FC(r3)
  lwz       r3, 0x3C0(r3)
  bl        0x12B50
  b         .loc_0x2D4C

.loc_0xAC8:
  lwz       r0, 0x4(r31)
  cmpwi     r0, 0
  ble-      .loc_0xAF0
  lwz       r3, 0x3F8(r4)
  lwz       r3, 0x3BC(r3)
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0
  bne-      .loc_0xAF0
  li        r0, 0x1
  b         .loc_0xAF4

.loc_0xAF0:
  li        r0, 0

.loc_0xAF4:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0xD0C
  li        r0, 0x5
  stw       r0, 0x2E8(r4)
  li        r0, 0
  addi      r3, r1, 0xA24
  lwz       r4, 0x20(r31)
  stb       r0, 0x2BD(r4)
  stb       r0, 0x0(r31)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x20(r31)
  stfs      f0, 0x2D4(r4)
  lwz       r5, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r4, 0x224(r5)
  lwz       r5, 0x3F4(r5)
  lfs       f1, 0x280(r4)
  lwz       r4, 0x0(r5)
  fmuls     f0, f1, f0
  lfs       f2, -0x5478(r2)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x94
  fadds     f31, f2, f0
  addi      r5, r5, 0x94
  bl        .loc_0x2D88
  addi      r3, r1, 0xA18
  addi      r4, r1, 0xA24
  addi      r5, r13, 0x168
  bl        -0xC8F04
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x344
  lfs       f28, 0xA20(r1)
  addi      r5, r1, 0x340
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0xA1C(r1)
  addi      r4, r1, 0x33C
  lwz       r3, 0x0(r3)
  lfs       f30, 0xA18(r1)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0xA30
  fsubs     f0, f0, f28
  stfs      f0, 0x344(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x340(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f30
  stfs      f0, 0x33C(r1)
  bl        -0x131310
  lfs       f1, 0xA30(r1)
  lfs       f0, 0xA34(r1)
  stfs      f1, 0xA0C(r1)
  stfs      f0, 0xA10(r1)
  lfs       f0, 0xA38(r1)
  stfs      f0, 0xA14(r1)
  lfs       f1, 0xA0C(r1)
  lfs       f0, 0xA10(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0xA14(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15A828
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xC0C
  addi      r3, r1, 0xA0C
  bl        -0xDEF30

.loc_0xC0C:
  lfs       f0, 0xA0C(r1)
  addi      r6, r1, 0x538
  addi      r5, r1, 0x534
  fmuls     f0, f0, f31
  addi      r4, r1, 0x530
  addi      r3, r1, 0xA3C
  stfs      f0, 0xA0C(r1)
  lfs       f0, 0xA10(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0xA10(r1)
  lfs       f0, 0xA14(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0xA14(r1)
  lfs       f1, 0xA14(r1)
  lfs       f0, 0xA0C(r1)
  fadds     f1, f28, f1
  fadds     f0, f30, f0
  stfs      f1, 0x538(r1)
  lfs       f1, 0xA10(r1)
  fadds     f1, f29, f1
  stfs      f0, 0x530(r1)
  stfs      f1, 0x534(r1)
  bl        -0x1313BC
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x52C
  lwz       r3, 0xA3C(r1)
  addi      r5, r1, 0x528
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0xA40(r1)
  addi      r4, r1, 0x524
  lwz       r7, 0x0(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0xA48
  stw       r0, 0x2C0(r7)
  lwz       r0, 0xA44(r1)
  stw       r0, 0x2C4(r7)
  lfs       f1, 0xA14(r1)
  lfs       f0, 0xA0C(r1)
  fsubs     f1, f28, f1
  fsubs     f0, f30, f0
  stfs      f1, 0x52C(r1)
  lfs       f1, 0xA10(r1)
  fsubs     f1, f29, f1
  stfs      f0, 0x524(r1)
  stfs      f1, 0x528(r1)
  bl        -0x131418
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0xA48(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0xA4C(r1)
  lwz       r5, 0xC(r5)
  stw       r4, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0xA50(r1)
  stw       r0, 0x2C4(r5)
  bl        -0x2B58
  mr        r3, r31
  bl        -0x2A5C
  lwz       r3, 0x20(r31)
  lwz       r3, 0x3FC(r3)
  lwz       r3, 0x3C0(r3)
  bl        0x1290C
  b         .loc_0x2D4C

.loc_0xD0C:
  mr        r3, r31
  bl        -0x2170
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD38
  lwz       r3, 0x20(r31)
  li        r4, 0x2
  li        r0, 0
  stw       r4, 0x2E8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  b         .loc_0x2D4C

.loc_0xD38:
  mr        r3, r31
  bl        -0x1E94
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2D4C
  lwz       r3, 0x20(r31)
  li        r4, 0x3
  li        r0, 0
  stw       r4, 0x2E8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  b         .loc_0x2D4C
  mr        r3, r5
  bl        -0x1A044
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0x224(r5)
  lfs       f0, 0x220(r4)
  stfs      f0, 0x3D0(r5)
  bl        -0x313C
  mr        r3, r31
  bl        -0x305C
  lwz       r6, 0x20(r31)
  lwz       r3, 0x3C8(r6)
  lwz       r0, 0x3CC(r6)
  lwz       r7, 0x3F4(r6)
  rlwinm    r4,r3,2,0,29
  rlwinm    r0,r0,2,0,29
  lwz       r3, 0x30C(r6)
  lwzx      r5, r7, r4
  lwzx      r4, r7, r0
  lwz       r0, 0x310(r6)
  stw       r3, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x314(r6)
  stw       r0, 0x2C4(r5)
  lwz       r3, 0x94(r5)
  lwz       r0, 0x98(r5)
  stw       r3, 0x2BC(r4)
  stw       r0, 0x2C0(r4)
  lwz       r0, 0x9C(r5)
  stw       r0, 0x2C4(r4)
  lwz       r3, 0x2DEC(r13)
  bl        -0xE93A8
  lwz       r4, 0x20(r31)
  mr        r3, r31
  lfs       f0, 0x2D8(r4)
  fadds     f0, f0, f1
  stfs      f0, 0x2D8(r4)
  bl        -0x2FB4
  mr        r3, r31
  bl        -0x2E78
  mr        r3, r31
  bl        -0x2D5C
  lwz       r30, 0x20(r31)
  lfs       f0, -0x54A8(r2)
  lfs       f1, 0x2C4(r30)
  fcmpo     cr0, f1, f0
  mfcr      r0
  rlwinm.   r0,r0,2,31,31
  bne-      .loc_0xE38
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x1800
  b         .loc_0x2D4C

.loc_0xE38:
  lbz       r0, 0x3C5(r30)
  cmplwi    r0, 0
  beq-      .loc_0xE4C
  li        r0, 0x1
  b         .loc_0xE50

.loc_0xE4C:
  li        r0, 0

.loc_0xE50:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x1068
  li        r0, 0x5
  stw       r0, 0x2E8(r30)
  li        r0, 0
  addi      r3, r1, 0x9AC
  lwz       r4, 0x20(r31)
  stb       r0, 0x2BD(r4)
  stb       r0, 0x0(r31)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x20(r31)
  stfs      f0, 0x2D4(r4)
  lwz       r5, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r4, 0x224(r5)
  lwz       r5, 0x3F4(r5)
  lfs       f1, 0x280(r4)
  lwz       r4, 0x0(r5)
  fmuls     f0, f1, f0
  lfs       f2, -0x5478(r2)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x94
  fadds     f31, f2, f0
  addi      r5, r5, 0x94
  bl        .loc_0x2D88
  addi      r3, r1, 0x9A0
  addi      r4, r1, 0x9AC
  addi      r5, r13, 0x168
  bl        -0xC9260
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x330
  lfs       f28, 0x9A8(r1)
  addi      r5, r1, 0x32C
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0x9A4(r1)
  addi      r4, r1, 0x328
  lwz       r3, 0x0(r3)
  lfs       f30, 0x9A0(r1)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0x9B8
  fsubs     f0, f0, f28
  stfs      f0, 0x330(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x32C(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f30
  stfs      f0, 0x328(r1)
  bl        -0x13166C
  lfs       f1, 0x9B8(r1)
  lfs       f0, 0x9BC(r1)
  stfs      f1, 0x994(r1)
  stfs      f0, 0x998(r1)
  lfs       f0, 0x9C0(r1)
  stfs      f0, 0x99C(r1)
  lfs       f1, 0x994(r1)
  lfs       f0, 0x998(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x99C(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15AB84
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0xF68
  addi      r3, r1, 0x994
  bl        -0xDF28C

.loc_0xF68:
  lfs       f0, 0x994(r1)
  addi      r6, r1, 0x514
  addi      r5, r1, 0x510
  fmuls     f0, f0, f31
  addi      r4, r1, 0x50C
  addi      r3, r1, 0x9C4
  stfs      f0, 0x994(r1)
  lfs       f0, 0x998(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x998(r1)
  lfs       f0, 0x99C(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x99C(r1)
  lfs       f1, 0x99C(r1)
  lfs       f0, 0x994(r1)
  fadds     f1, f28, f1
  fadds     f0, f30, f0
  stfs      f1, 0x514(r1)
  lfs       f1, 0x998(r1)
  fadds     f1, f29, f1
  stfs      f0, 0x50C(r1)
  stfs      f1, 0x510(r1)
  bl        -0x131718
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x508
  lwz       r3, 0x9C4(r1)
  addi      r5, r1, 0x504
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0x9C8(r1)
  addi      r4, r1, 0x500
  lwz       r7, 0x0(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0x9D0
  stw       r0, 0x2C0(r7)
  lwz       r0, 0x9CC(r1)
  stw       r0, 0x2C4(r7)
  lfs       f1, 0x99C(r1)
  lfs       f0, 0x994(r1)
  fsubs     f1, f28, f1
  fsubs     f0, f30, f0
  stfs      f1, 0x508(r1)
  lfs       f1, 0x998(r1)
  fsubs     f1, f29, f1
  stfs      f0, 0x500(r1)
  stfs      f1, 0x504(r1)
  bl        -0x131774
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0x9D0(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0x9D4(r1)
  lwz       r5, 0xC(r5)
  stw       r4, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x9D8(r1)
  stw       r0, 0x2C4(r5)
  bl        -0x2EB4
  mr        r3, r31
  bl        -0x2DB8
  lwz       r3, 0x20(r31)
  lwz       r3, 0x3FC(r3)
  lwz       r3, 0x3C0(r3)
  bl        0x125B0
  b         .loc_0x2D4C

.loc_0x1068:
  lwz       r0, 0x4(r31)
  cmpwi     r0, 0
  ble-      .loc_0x1090
  lwz       r3, 0x3F8(r30)
  lwz       r3, 0x3BC(r3)
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0
  bne-      .loc_0x1090
  li        r0, 0x1
  b         .loc_0x1094

.loc_0x1090:
  li        r0, 0

.loc_0x1094:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x12AC
  li        r0, 0x5
  stw       r0, 0x2E8(r30)
  li        r0, 0
  addi      r3, r1, 0x94C
  lwz       r4, 0x20(r31)
  stb       r0, 0x2BD(r4)
  stb       r0, 0x0(r31)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x20(r31)
  stfs      f0, 0x2D4(r4)
  lwz       r5, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r4, 0x224(r5)
  lwz       r5, 0x3F4(r5)
  lfs       f1, 0x280(r4)
  lwz       r4, 0x0(r5)
  fmuls     f0, f1, f0
  lfs       f2, -0x5478(r2)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x94
  fadds     f31, f2, f0
  addi      r5, r5, 0x94
  bl        .loc_0x2D88
  addi      r3, r1, 0x940
  addi      r4, r1, 0x94C
  addi      r5, r13, 0x168
  bl        -0xC94A4
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x324
  lfs       f28, 0x948(r1)
  addi      r5, r1, 0x320
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0x944(r1)
  addi      r4, r1, 0x31C
  lwz       r3, 0x0(r3)
  lfs       f30, 0x940(r1)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0x958
  fsubs     f0, f0, f28
  stfs      f0, 0x324(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x320(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f30
  stfs      f0, 0x31C(r1)
  bl        -0x1318B0
  lfs       f1, 0x958(r1)
  lfs       f0, 0x95C(r1)
  stfs      f1, 0x934(r1)
  stfs      f0, 0x938(r1)
  lfs       f0, 0x960(r1)
  stfs      f0, 0x93C(r1)
  lfs       f1, 0x934(r1)
  lfs       f0, 0x938(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x93C(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15ADC8
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x11AC
  addi      r3, r1, 0x934
  bl        -0xDF4D0

.loc_0x11AC:
  lfs       f0, 0x934(r1)
  addi      r6, r1, 0x4F4
  addi      r5, r1, 0x4F0
  fmuls     f0, f0, f31
  addi      r4, r1, 0x4EC
  addi      r3, r1, 0x964
  stfs      f0, 0x934(r1)
  lfs       f0, 0x938(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x938(r1)
  lfs       f0, 0x93C(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x93C(r1)
  lfs       f1, 0x93C(r1)
  lfs       f0, 0x934(r1)
  fadds     f1, f28, f1
  fadds     f0, f30, f0
  stfs      f1, 0x4F4(r1)
  lfs       f1, 0x938(r1)
  fadds     f1, f29, f1
  stfs      f0, 0x4EC(r1)
  stfs      f1, 0x4F0(r1)
  bl        -0x13195C
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x4E8
  lwz       r3, 0x964(r1)
  addi      r5, r1, 0x4E4
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0x968(r1)
  addi      r4, r1, 0x4E0
  lwz       r7, 0x0(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0x970
  stw       r0, 0x2C0(r7)
  lwz       r0, 0x96C(r1)
  stw       r0, 0x2C4(r7)
  lfs       f1, 0x93C(r1)
  lfs       f0, 0x934(r1)
  fsubs     f1, f28, f1
  fsubs     f0, f30, f0
  stfs      f1, 0x4E8(r1)
  lfs       f1, 0x938(r1)
  fsubs     f1, f29, f1
  stfs      f0, 0x4E0(r1)
  stfs      f1, 0x4E4(r1)
  bl        -0x1319B8
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0x970(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0x974(r1)
  lwz       r5, 0xC(r5)
  stw       r4, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x978(r1)
  stw       r0, 0x2C4(r5)
  bl        -0x30F8
  mr        r3, r31
  bl        -0x2FFC
  lwz       r3, 0x20(r31)
  lwz       r3, 0x3FC(r3)
  lwz       r3, 0x3C0(r3)
  bl        0x1236C
  b         .loc_0x2D4C

.loc_0x12AC:
  lwz       r0, 0x3C8(r30)
  lwz       r3, 0x3F4(r30)
  rlwinm    r0,r0,2,0,29
  lfs       f3, 0x300(r30)
  lwzx      r3, r3, r0
  lfs       f4, 0x308(r30)
  lfs       f1, 0x94(r3)
  lfs       f2, 0x9C(r3)
  bl        -0x130518
  lwz       r3, 0x224(r30)
  lfs       f0, 0x68(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x12E8
  li        r0, 0x1
  b         .loc_0x12EC

.loc_0x12E8:
  li        r0, 0

.loc_0x12EC:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x1330
  lwz       r3, 0x20(r31)
  li        r4, 0x4
  li        r0, 0
  stw       r4, 0x2E8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  lwz       r3, 0x20(r31)
  stw       r0, 0x318(r3)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2D4C
  li        r4, 0x8D
  bl        -0xC4DCC
  b         .loc_0x2D4C

.loc_0x1330:
  mr        r3, r31
  bl        -0x248C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x135C
  lwz       r3, 0x20(r31)
  li        r4, 0x3
  li        r0, 0
  stw       r4, 0x2E8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  b         .loc_0x2D4C

.loc_0x135C:
  mr        r3, r31
  bl        -0x21AC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2D4C
  lwz       r3, 0x20(r31)
  li        r4, 0x1
  li        r0, 0
  stw       r4, 0x2E8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  lwz       r3, 0x20(r31)
  stw       r0, 0x318(r3)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2D4C
  li        r4, 0x8D
  bl        -0xC4E44
  b         .loc_0x2D4C
  mr        r3, r5
  bl        -0x1A688
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0x224(r5)
  lfs       f0, 0x220(r4)
  stfs      f0, 0x3D0(r5)
  bl        -0x3780
  mr        r3, r31
  bl        -0x36A0
  lwz       r6, 0x20(r31)
  lwz       r3, 0x3C8(r6)
  lwz       r0, 0x3CC(r6)
  lwz       r7, 0x3F4(r6)
  rlwinm    r4,r3,2,0,29
  rlwinm    r0,r0,2,0,29
  lwz       r3, 0x30C(r6)
  lwzx      r5, r7, r4
  lwzx      r4, r7, r0
  lwz       r0, 0x310(r6)
  stw       r3, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x314(r6)
  stw       r0, 0x2C4(r5)
  lwz       r3, 0x94(r5)
  lwz       r0, 0x98(r5)
  stw       r3, 0x2BC(r4)
  stw       r0, 0x2C0(r4)
  lwz       r0, 0x9C(r5)
  stw       r0, 0x2C4(r4)
  lwz       r3, 0x2DEC(r13)
  bl        -0xE99EC
  lwz       r4, 0x20(r31)
  mr        r3, r31
  lfs       f0, 0x2D8(r4)
  fadds     f0, f0, f1
  stfs      f0, 0x2D8(r4)
  bl        -0x35F8
  mr        r3, r31
  bl        -0x34BC
  mr        r3, r31
  bl        -0x33A0
  lwz       r30, 0x20(r31)
  lfs       f0, -0x54A8(r2)
  lfs       f1, 0x2C4(r30)
  fcmpo     cr0, f1, f0
  mfcr      r0
  rlwinm.   r0,r0,2,31,31
  bne-      .loc_0x147C
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x1E44
  b         .loc_0x2D4C

.loc_0x147C:
  lbz       r0, 0x3C5(r30)
  cmplwi    r0, 0
  beq-      .loc_0x1490
  li        r0, 0x1
  b         .loc_0x1494

.loc_0x1490:
  li        r0, 0

.loc_0x1494:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x16AC
  li        r0, 0x5
  stw       r0, 0x2E8(r30)
  li        r0, 0
  addi      r3, r1, 0x8BC
  lwz       r4, 0x20(r31)
  stb       r0, 0x2BD(r4)
  stb       r0, 0x0(r31)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x20(r31)
  stfs      f0, 0x2D4(r4)
  lwz       r5, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r4, 0x224(r5)
  lwz       r5, 0x3F4(r5)
  lfs       f1, 0x280(r4)
  lwz       r4, 0x0(r5)
  fmuls     f0, f1, f0
  lfs       f2, -0x5478(r2)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x94
  fadds     f31, f2, f0
  addi      r5, r5, 0x94
  bl        .loc_0x2D88
  addi      r3, r1, 0x8B0
  addi      r4, r1, 0x8BC
  addi      r5, r13, 0x168
  bl        -0xC98A4
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x310
  lfs       f28, 0x8B8(r1)
  addi      r5, r1, 0x30C
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0x8B4(r1)
  addi      r4, r1, 0x308
  lwz       r3, 0x0(r3)
  lfs       f30, 0x8B0(r1)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0x8C8
  fsubs     f0, f0, f28
  stfs      f0, 0x310(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x30C(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f30
  stfs      f0, 0x308(r1)
  bl        -0x131CB0
  lfs       f1, 0x8C8(r1)
  lfs       f0, 0x8CC(r1)
  stfs      f1, 0x8A4(r1)
  stfs      f0, 0x8A8(r1)
  lfs       f0, 0x8D0(r1)
  stfs      f0, 0x8AC(r1)
  lfs       f1, 0x8A4(r1)
  lfs       f0, 0x8A8(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x8AC(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15B1C8
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x15AC
  addi      r3, r1, 0x8A4
  bl        -0xDF8D0

.loc_0x15AC:
  lfs       f0, 0x8A4(r1)
  addi      r6, r1, 0x4D0
  addi      r5, r1, 0x4CC
  fmuls     f0, f0, f31
  addi      r4, r1, 0x4C8
  addi      r3, r1, 0x8D4
  stfs      f0, 0x8A4(r1)
  lfs       f0, 0x8A8(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x8A8(r1)
  lfs       f0, 0x8AC(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x8AC(r1)
  lfs       f1, 0x8AC(r1)
  lfs       f0, 0x8A4(r1)
  fadds     f1, f28, f1
  fadds     f0, f30, f0
  stfs      f1, 0x4D0(r1)
  lfs       f1, 0x8A8(r1)
  fadds     f1, f29, f1
  stfs      f0, 0x4C8(r1)
  stfs      f1, 0x4CC(r1)
  bl        -0x131D5C
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x4C4
  lwz       r3, 0x8D4(r1)
  addi      r5, r1, 0x4C0
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0x8D8(r1)
  addi      r4, r1, 0x4BC
  lwz       r7, 0x0(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0x8E0
  stw       r0, 0x2C0(r7)
  lwz       r0, 0x8DC(r1)
  stw       r0, 0x2C4(r7)
  lfs       f1, 0x8AC(r1)
  lfs       f0, 0x8A4(r1)
  fsubs     f1, f28, f1
  fsubs     f0, f30, f0
  stfs      f1, 0x4C4(r1)
  lfs       f1, 0x8A8(r1)
  fsubs     f1, f29, f1
  stfs      f0, 0x4BC(r1)
  stfs      f1, 0x4C0(r1)
  bl        -0x131DB8
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0x8E0(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0x8E4(r1)
  lwz       r5, 0xC(r5)
  stw       r4, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x8E8(r1)
  stw       r0, 0x2C4(r5)
  bl        -0x34F8
  mr        r3, r31
  bl        -0x33FC
  lwz       r3, 0x20(r31)
  lwz       r3, 0x3FC(r3)
  lwz       r3, 0x3C0(r3)
  bl        0x11F6C
  b         .loc_0x2D4C

.loc_0x16AC:
  lwz       r0, 0x4(r31)
  cmpwi     r0, 0
  ble-      .loc_0x16D4
  lwz       r3, 0x3F8(r30)
  lwz       r3, 0x3BC(r3)
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0
  bne-      .loc_0x16D4
  li        r0, 0x1
  b         .loc_0x16D8

.loc_0x16D4:
  li        r0, 0

.loc_0x16D8:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x18F0
  li        r0, 0x5
  stw       r0, 0x2E8(r30)
  li        r0, 0
  addi      r3, r1, 0x85C
  lwz       r4, 0x20(r31)
  stb       r0, 0x2BD(r4)
  stb       r0, 0x0(r31)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x20(r31)
  stfs      f0, 0x2D4(r4)
  lwz       r5, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r4, 0x224(r5)
  lwz       r5, 0x3F4(r5)
  lfs       f1, 0x280(r4)
  lwz       r4, 0x0(r5)
  fmuls     f0, f1, f0
  lfs       f2, -0x5478(r2)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x94
  fadds     f31, f2, f0
  addi      r5, r5, 0x94
  bl        .loc_0x2D88
  addi      r3, r1, 0x850
  addi      r4, r1, 0x85C
  addi      r5, r13, 0x168
  bl        -0xC9AE8
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x304
  lfs       f28, 0x858(r1)
  addi      r5, r1, 0x300
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0x854(r1)
  addi      r4, r1, 0x2FC
  lwz       r3, 0x0(r3)
  lfs       f30, 0x850(r1)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0x868
  fsubs     f0, f0, f28
  stfs      f0, 0x304(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x300(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f30
  stfs      f0, 0x2FC(r1)
  bl        -0x131EF4
  lfs       f1, 0x868(r1)
  lfs       f0, 0x86C(r1)
  stfs      f1, 0x844(r1)
  stfs      f0, 0x848(r1)
  lfs       f0, 0x870(r1)
  stfs      f0, 0x84C(r1)
  lfs       f1, 0x844(r1)
  lfs       f0, 0x848(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x84C(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15B40C
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x17F0
  addi      r3, r1, 0x844
  bl        -0xDFB14

.loc_0x17F0:
  lfs       f0, 0x844(r1)
  addi      r6, r1, 0x4B0
  addi      r5, r1, 0x4AC
  fmuls     f0, f0, f31
  addi      r4, r1, 0x4A8
  addi      r3, r1, 0x874
  stfs      f0, 0x844(r1)
  lfs       f0, 0x848(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x848(r1)
  lfs       f0, 0x84C(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x84C(r1)
  lfs       f1, 0x84C(r1)
  lfs       f0, 0x844(r1)
  fadds     f1, f28, f1
  fadds     f0, f30, f0
  stfs      f1, 0x4B0(r1)
  lfs       f1, 0x848(r1)
  fadds     f1, f29, f1
  stfs      f0, 0x4A8(r1)
  stfs      f1, 0x4AC(r1)
  bl        -0x131FA0
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x4A4
  lwz       r3, 0x874(r1)
  addi      r5, r1, 0x4A0
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0x878(r1)
  addi      r4, r1, 0x49C
  lwz       r7, 0x0(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0x880
  stw       r0, 0x2C0(r7)
  lwz       r0, 0x87C(r1)
  stw       r0, 0x2C4(r7)
  lfs       f1, 0x84C(r1)
  lfs       f0, 0x844(r1)
  fsubs     f1, f28, f1
  fsubs     f0, f30, f0
  stfs      f1, 0x4A4(r1)
  lfs       f1, 0x848(r1)
  fsubs     f1, f29, f1
  stfs      f0, 0x49C(r1)
  stfs      f1, 0x4A0(r1)
  bl        -0x131FFC
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0x880(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0x884(r1)
  lwz       r5, 0xC(r5)
  stw       r4, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x888(r1)
  stw       r0, 0x2C4(r5)
  bl        -0x373C
  mr        r3, r31
  bl        -0x3640
  lwz       r3, 0x20(r31)
  lwz       r3, 0x3FC(r3)
  lwz       r3, 0x3C0(r3)
  bl        0x11D28
  b         .loc_0x2D4C

.loc_0x18F0:
  lwz       r0, 0x3C8(r30)
  lwz       r3, 0x3F4(r30)
  rlwinm    r0,r0,2,0,29
  lfs       f3, 0x300(r30)
  lwzx      r3, r3, r0
  lfs       f4, 0x308(r30)
  lfs       f1, 0x94(r3)
  lfs       f2, 0x9C(r3)
  bl        -0x130B5C
  lwz       r3, 0x224(r30)
  lfs       f0, 0x68(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x192C
  li        r0, 0x1
  b         .loc_0x1930

.loc_0x192C:
  li        r0, 0

.loc_0x1930:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x1974
  lwz       r3, 0x20(r31)
  li        r4, 0x4
  li        r0, 0
  stw       r4, 0x2E8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  lwz       r3, 0x20(r31)
  stw       r0, 0x318(r3)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2D4C
  li        r4, 0x8D
  bl        -0xC5410
  b         .loc_0x2D4C

.loc_0x1974:
  mr        r3, r31
  bl        -0x2DD8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x19A0
  lwz       r3, 0x20(r31)
  li        r4, 0x2
  li        r0, 0
  stw       r4, 0x2E8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  b         .loc_0x2D4C

.loc_0x19A0:
  mr        r3, r31
  bl        -0x2AFC
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x19CC
  lwz       r3, 0x20(r31)
  li        r4, 0x3
  li        r0, 0
  stw       r4, 0x2E8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  b         .loc_0x2D4C

.loc_0x19CC:
  mr        r3, r31
  bl        -0x281C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2D4C
  lwz       r3, 0x20(r31)
  li        r4, 0x1
  li        r0, 0
  stw       r4, 0x2E8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  lwz       r3, 0x20(r31)
  stw       r0, 0x318(r3)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2D4C
  li        r4, 0x8D
  bl        -0xC54B4
  b         .loc_0x2D4C
  lwz       r4, 0x300(r5)
  mr        r3, r31
  lwz       r0, 0x304(r5)
  stw       r4, 0x30C(r5)
  stw       r0, 0x310(r5)
  lwz       r0, 0x308(r5)
  stw       r0, 0x314(r5)
  lwz       r5, 0x20(r31)
  lwz       r4, 0x224(r5)
  lfs       f0, 0x220(r4)
  stfs      f0, 0x3D0(r5)
  bl        -0x3E00
  mr        r3, r31
  bl        -0x3D20
  lwz       r6, 0x20(r31)
  lwz       r3, 0x3C8(r6)
  lwz       r0, 0x3CC(r6)
  lwz       r7, 0x3F4(r6)
  rlwinm    r4,r3,2,0,29
  rlwinm    r0,r0,2,0,29
  lwz       r3, 0x30C(r6)
  lwzx      r5, r7, r4
  lwzx      r4, r7, r0
  lwz       r0, 0x310(r6)
  stw       r3, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x314(r6)
  stw       r0, 0x2C4(r5)
  lwz       r3, 0x94(r5)
  lwz       r0, 0x98(r5)
  stw       r3, 0x2BC(r4)
  stw       r0, 0x2C0(r4)
  lwz       r0, 0x9C(r5)
  stw       r0, 0x2C4(r4)
  lwz       r3, 0x2DEC(r13)
  bl        -0xEA06C
  lwz       r4, 0x20(r31)
  mr        r3, r31
  lfs       f0, 0x2D8(r4)
  fadds     f0, f0, f1
  stfs      f0, 0x2D8(r4)
  bl        -0x3C78
  mr        r3, r31
  bl        -0x3B3C
  mr        r3, r31
  bl        -0x3A20
  lwz       r30, 0x20(r31)
  lfs       f0, -0x54A8(r2)
  lfs       f1, 0x2C4(r30)
  fcmpo     cr0, f1, f0
  mfcr      r0
  rlwinm.   r0,r0,2,31,31
  bne-      .loc_0x1AFC
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x24C4
  b         .loc_0x2D4C

.loc_0x1AFC:
  lbz       r0, 0x3C5(r30)
  cmplwi    r0, 0
  beq-      .loc_0x1B10
  li        r0, 0x1
  b         .loc_0x1B14

.loc_0x1B10:
  li        r0, 0

.loc_0x1B14:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x1D2C
  li        r0, 0x5
  stw       r0, 0x2E8(r30)
  li        r0, 0
  addi      r3, r1, 0x7BC
  lwz       r4, 0x20(r31)
  stb       r0, 0x2BD(r4)
  stb       r0, 0x0(r31)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x20(r31)
  stfs      f0, 0x2D4(r4)
  lwz       r5, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r4, 0x224(r5)
  lwz       r5, 0x3F4(r5)
  lfs       f1, 0x280(r4)
  lwz       r4, 0x0(r5)
  fmuls     f0, f1, f0
  lfs       f2, -0x5478(r2)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x94
  fadds     f31, f2, f0
  addi      r5, r5, 0x94
  bl        .loc_0x2D88
  addi      r3, r1, 0x7B0
  addi      r4, r1, 0x7BC
  addi      r5, r13, 0x168
  bl        -0xC9F24
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x2F0
  lfs       f28, 0x7B8(r1)
  addi      r5, r1, 0x2EC
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0x7B4(r1)
  addi      r4, r1, 0x2E8
  lwz       r3, 0x0(r3)
  lfs       f30, 0x7B0(r1)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0x7C8
  fsubs     f0, f0, f28
  stfs      f0, 0x2F0(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x2EC(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f30
  stfs      f0, 0x2E8(r1)
  bl        -0x132330
  lfs       f1, 0x7C8(r1)
  lfs       f0, 0x7CC(r1)
  stfs      f1, 0x7A4(r1)
  stfs      f0, 0x7A8(r1)
  lfs       f0, 0x7D0(r1)
  stfs      f0, 0x7AC(r1)
  lfs       f1, 0x7A4(r1)
  lfs       f0, 0x7A8(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x7AC(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15B848
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x1C2C
  addi      r3, r1, 0x7A4
  bl        -0xDFF50

.loc_0x1C2C:
  lfs       f0, 0x7A4(r1)
  addi      r6, r1, 0x488
  addi      r5, r1, 0x484
  fmuls     f0, f0, f31
  addi      r4, r1, 0x480
  addi      r3, r1, 0x7D4
  stfs      f0, 0x7A4(r1)
  lfs       f0, 0x7A8(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x7A8(r1)
  lfs       f0, 0x7AC(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x7AC(r1)
  lfs       f1, 0x7AC(r1)
  lfs       f0, 0x7A4(r1)
  fadds     f1, f28, f1
  fadds     f0, f30, f0
  stfs      f1, 0x488(r1)
  lfs       f1, 0x7A8(r1)
  fadds     f1, f29, f1
  stfs      f0, 0x480(r1)
  stfs      f1, 0x484(r1)
  bl        -0x1323DC
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x47C
  lwz       r3, 0x7D4(r1)
  addi      r5, r1, 0x478
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0x7D8(r1)
  addi      r4, r1, 0x474
  lwz       r7, 0x0(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0x7E0
  stw       r0, 0x2C0(r7)
  lwz       r0, 0x7DC(r1)
  stw       r0, 0x2C4(r7)
  lfs       f1, 0x7AC(r1)
  lfs       f0, 0x7A4(r1)
  fsubs     f1, f28, f1
  fsubs     f0, f30, f0
  stfs      f1, 0x47C(r1)
  lfs       f1, 0x7A8(r1)
  fsubs     f1, f29, f1
  stfs      f0, 0x474(r1)
  stfs      f1, 0x478(r1)
  bl        -0x132438
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0x7E0(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0x7E4(r1)
  lwz       r5, 0xC(r5)
  stw       r4, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x7E8(r1)
  stw       r0, 0x2C4(r5)
  bl        -0x3B78
  mr        r3, r31
  bl        -0x3A7C
  lwz       r3, 0x20(r31)
  lwz       r3, 0x3FC(r3)
  lwz       r3, 0x3C0(r3)
  bl        0x118EC
  b         .loc_0x2D4C

.loc_0x1D2C:
  lwz       r0, 0x4(r31)
  cmpwi     r0, 0
  ble-      .loc_0x1D54
  lwz       r3, 0x3F8(r30)
  lwz       r3, 0x3BC(r3)
  lwz       r0, 0x4(r3)
  cmpwi     r0, 0
  bne-      .loc_0x1D54
  li        r0, 0x1
  b         .loc_0x1D58

.loc_0x1D54:
  li        r0, 0

.loc_0x1D58:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x1F70
  li        r0, 0x5
  stw       r0, 0x2E8(r30)
  li        r0, 0
  addi      r3, r1, 0x75C
  lwz       r4, 0x20(r31)
  stb       r0, 0x2BD(r4)
  stb       r0, 0x0(r31)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x20(r31)
  stfs      f0, 0x2D4(r4)
  lwz       r5, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r4, 0x224(r5)
  lwz       r5, 0x3F4(r5)
  lfs       f1, 0x280(r4)
  lwz       r4, 0x0(r5)
  fmuls     f0, f1, f0
  lfs       f2, -0x5478(r2)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x94
  fadds     f31, f2, f0
  addi      r5, r5, 0x94
  bl        .loc_0x2D88
  addi      r3, r1, 0x750
  addi      r4, r1, 0x75C
  addi      r5, r13, 0x168
  bl        -0xCA168
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x2E4
  lfs       f28, 0x758(r1)
  addi      r5, r1, 0x2E0
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0x754(r1)
  addi      r4, r1, 0x2DC
  lwz       r3, 0x0(r3)
  lfs       f30, 0x750(r1)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0x768
  fsubs     f0, f0, f28
  stfs      f0, 0x2E4(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x2E0(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f30
  stfs      f0, 0x2DC(r1)
  bl        -0x132574
  lfs       f1, 0x768(r1)
  lfs       f0, 0x76C(r1)
  stfs      f1, 0x744(r1)
  stfs      f0, 0x748(r1)
  lfs       f0, 0x770(r1)
  stfs      f0, 0x74C(r1)
  lfs       f1, 0x744(r1)
  lfs       f0, 0x748(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x74C(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15BA8C
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x1E70
  addi      r3, r1, 0x744
  bl        -0xE0194

.loc_0x1E70:
  lfs       f0, 0x744(r1)
  addi      r6, r1, 0x468
  addi      r5, r1, 0x464
  fmuls     f0, f0, f31
  addi      r4, r1, 0x460
  addi      r3, r1, 0x774
  stfs      f0, 0x744(r1)
  lfs       f0, 0x748(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x748(r1)
  lfs       f0, 0x74C(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x74C(r1)
  lfs       f1, 0x74C(r1)
  lfs       f0, 0x744(r1)
  fadds     f1, f28, f1
  fadds     f0, f30, f0
  stfs      f1, 0x468(r1)
  lfs       f1, 0x748(r1)
  fadds     f1, f29, f1
  stfs      f0, 0x460(r1)
  stfs      f1, 0x464(r1)
  bl        -0x132620
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x45C
  lwz       r3, 0x774(r1)
  addi      r5, r1, 0x458
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0x778(r1)
  addi      r4, r1, 0x454
  lwz       r7, 0x0(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0x780
  stw       r0, 0x2C0(r7)
  lwz       r0, 0x77C(r1)
  stw       r0, 0x2C4(r7)
  lfs       f1, 0x74C(r1)
  lfs       f0, 0x744(r1)
  fsubs     f1, f28, f1
  fsubs     f0, f30, f0
  stfs      f1, 0x45C(r1)
  lfs       f1, 0x748(r1)
  fsubs     f1, f29, f1
  stfs      f0, 0x454(r1)
  stfs      f1, 0x458(r1)
  bl        -0x13267C
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0x780(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0x784(r1)
  lwz       r5, 0xC(r5)
  stw       r4, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x788(r1)
  stw       r0, 0x2C4(r5)
  bl        -0x3DBC
  mr        r3, r31
  bl        -0x3CC0
  lwz       r3, 0x20(r31)
  lwz       r3, 0x3FC(r3)
  lwz       r3, 0x3C0(r3)
  bl        0x116A8
  b         .loc_0x2D4C

.loc_0x1F70:
  lwz       r0, 0x3CC(r30)
  lwz       r3, 0x3F4(r30)
  rlwinm    r0,r0,2,0,29
  lfs       f3, 0x300(r30)
  lwzx      r3, r3, r0
  lfs       f4, 0x308(r30)
  lfs       f1, 0x94(r3)
  lfs       f2, 0x9C(r3)
  bl        -0x1311DC
  lwz       r3, 0x224(r30)
  lfs       f0, 0x78(r3)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x1FAC
  li        r0, 0x1
  b         .loc_0x1FB0

.loc_0x1FAC:
  li        r0, 0

.loc_0x1FB0:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x2D4C
  lwz       r3, 0x20(r31)
  li        r4, 0x1
  li        r0, 0
  stw       r4, 0x2E8(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  lwz       r3, 0x20(r31)
  stw       r0, 0x318(r3)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2D4C
  li        r4, 0x8D
  bl        -0xC5A90
  b         .loc_0x2D4C
  lfs       f0, -0x54A8(r2)
  addi      r6, r1, 0x450
  addi      r5, r1, 0x44C
  stfs      f0, 0x720(r1)
  addi      r4, r1, 0x448
  addi      r3, r1, 0x718
  stfs      f0, 0x71C(r1)
  stfs      f0, 0x718(r1)
  lwz       r8, 0x20(r31)
  lwz       r7, 0x3F4(r8)
  lwz       r8, 0x224(r8)
  lwz       r7, 0x0(r7)
  lfs       f1, 0x310(r8)
  lfsu      f0, 0x70(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r7)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r7)
  lfs       f0, 0x8(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r7)
  lwz       r7, 0x20(r31)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0x0(r7)
  addi      r8, r7, 0x94
  addi      r7, r7, 0x2BC
  lfs       f0, 0x8(r8)
  lfs       f1, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x450(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x44C(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x448(r1)
  bl        -0x1327E8
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x444
  lfs       f0, 0x718(r1)
  addi      r5, r1, 0x440
  lwz       r3, 0x224(r3)
  addi      r4, r1, 0x43C
  lfs       f1, 0x320(r3)
  addi      r3, r1, 0x718
  fmuls     f0, f0, f1
  stfs      f0, 0x718(r1)
  lfs       f0, 0x71C(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x71C(r1)
  lfs       f0, 0x720(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x720(r1)
  lwz       r7, 0x20(r31)
  lfs       f0, 0x718(r1)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0x0(r7)
  lfsu      f1, 0x70(r7)
  fadds     f0, f1, f0
  stfs      f0, 0x0(r7)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x71C(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r7)
  lfs       f1, 0x8(r7)
  lfs       f0, 0x720(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r7)
  lwz       r8, 0x20(r31)
  lwz       r7, 0x3F4(r8)
  lwz       r8, 0x224(r8)
  lwz       r7, 0xC(r7)
  lfs       f1, 0x310(r8)
  lfsu      f0, 0x70(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r7)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r7)
  lfs       f0, 0x8(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r7)
  lwz       r7, 0x20(r31)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0xC(r7)
  addi      r8, r7, 0x94
  addi      r7, r7, 0x2BC
  lfs       f0, 0x8(r8)
  lfs       f1, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x444(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x440(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x43C(r1)
  bl        -0x1328E4
  lwz       r4, 0x20(r31)
  mr        r3, r31
  lfs       f0, 0x718(r1)
  lwz       r4, 0x224(r4)
  lfs       f1, 0x320(r4)
  fmuls     f0, f0, f1
  stfs      f0, 0x718(r1)
  lfs       f0, 0x71C(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x71C(r1)
  lfs       f0, 0x720(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x720(r1)
  lwz       r4, 0x20(r31)
  lfs       f0, 0x718(r1)
  lwz       r4, 0x3F4(r4)
  lwz       r4, 0xC(r4)
  lfsu      f1, 0x70(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x0(r4)
  lfs       f1, 0x4(r4)
  lfs       f0, 0x71C(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r4)
  lfs       f1, 0x8(r4)
  lfs       f0, 0x720(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r4)
  lwz       r5, 0x20(r31)
  lwz       r4, 0x2DEC(r13)
  lfs       f1, 0x2D4(r5)
  lfs       f0, 0x28C(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x2D4(r5)
  bl        -0x416C
  lwz       r3, 0x20(r31)
  lfs       f0, -0x54A8(r2)
  lfs       f1, 0x2C4(r3)
  fcmpo     cr0, f1, f0
  mfcr      r0
  rlwinm.   r0,r0,2,31,31
  bne-      .loc_0x2248
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x2C10
  b         .loc_0x2D4C

.loc_0x2248:
  lbz       r0, 0x0(r31)
  cmplwi    r0, 0
  bne-      .loc_0x2264
  lfs       f1, 0x2D4(r3)
  lfs       f0, -0x5460(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x226C

.loc_0x2264:
  li        r0, 0x1
  b         .loc_0x2270

.loc_0x226C:
  li        r0, 0

.loc_0x2270:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x2D4C
  li        r0, 0x6
  stw       r0, 0x2E8(r3)
  li        r5, 0
  li        r0, 0x1
  lwz       r4, 0x20(r31)
  addi      r3, r1, 0x6CC
  stb       r5, 0x2BD(r4)
  lwz       r4, 0x20(r31)
  stb       r5, 0x3C5(r4)
  lwz       r4, 0x20(r31)
  stb       r0, 0x3C4(r4)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x20(r31)
  stfs      f0, 0x2D4(r4)
  lwz       r5, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r4, 0x224(r5)
  lwz       r5, 0x3F4(r5)
  lfs       f1, 0x280(r4)
  lwz       r4, 0x0(r5)
  fmuls     f0, f1, f0
  lfs       f2, -0x547C(r2)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x2BC
  fadds     f31, f2, f0
  addi      r5, r5, 0x2BC
  bl        .loc_0x2D88
  addi      r3, r1, 0x6C0
  addi      r4, r1, 0x6CC
  addi      r5, r13, 0x16C
  bl        -0xCA690
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x2C8
  lfs       f28, 0x6C8(r1)
  addi      r5, r1, 0x2C4
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0x6C4(r1)
  addi      r4, r1, 0x2C0
  lwz       r3, 0x0(r3)
  lfs       f30, 0x6C0(r1)
  lfs       f0, 0x2C4(r3)
  addi      r7, r3, 0x2BC
  addi      r3, r1, 0x6D8
  fsubs     f0, f0, f28
  stfs      f0, 0x2C8(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x2C4(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f30
  stfs      f0, 0x2C0(r1)
  bl        -0x132A9C
  lfs       f1, 0x6D8(r1)
  lfs       f0, 0x6DC(r1)
  stfs      f1, 0x6B4(r1)
  stfs      f0, 0x6B8(r1)
  lfs       f0, 0x6E0(r1)
  stfs      f0, 0x6BC(r1)
  lfs       f1, 0x6B4(r1)
  lfs       f0, 0x6B8(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x6BC(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15BFB4
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x2398
  addi      r3, r1, 0x6B4
  bl        -0xE06BC

.loc_0x2398:
  lfs       f0, 0x6B4(r1)
  addi      r6, r1, 0x42C
  addi      r5, r1, 0x428
  fmuls     f0, f0, f31
  addi      r4, r1, 0x424
  addi      r3, r1, 0x6E4
  stfs      f0, 0x6B4(r1)
  lfs       f0, 0x6B8(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x6B8(r1)
  lfs       f0, 0x6BC(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x6BC(r1)
  lfs       f1, 0x6BC(r1)
  lfs       f0, 0x6B4(r1)
  fadds     f1, f28, f1
  fadds     f0, f30, f0
  stfs      f1, 0x42C(r1)
  lfs       f1, 0x6B8(r1)
  fadds     f1, f29, f1
  stfs      f0, 0x424(r1)
  stfs      f1, 0x428(r1)
  bl        -0x132B48
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x420
  lwz       r3, 0x6E4(r1)
  addi      r5, r1, 0x41C
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0x6E8(r1)
  addi      r4, r1, 0x418
  lwz       r7, 0x0(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0x6F0
  stw       r0, 0x2C0(r7)
  lwz       r0, 0x6EC(r1)
  stw       r0, 0x2C4(r7)
  lfs       f1, 0x6BC(r1)
  lfs       f0, 0x6B4(r1)
  fsubs     f1, f28, f1
  fsubs     f0, f30, f0
  stfs      f1, 0x420(r1)
  lfs       f1, 0x6B8(r1)
  fsubs     f1, f29, f1
  stfs      f0, 0x418(r1)
  stfs      f1, 0x41C(r1)
  bl        -0x132BA4
  lwz       r4, 0x20(r31)
  lwz       r3, 0x6F0(r1)
  lwz       r4, 0x3F4(r4)
  lwz       r0, 0x6F4(r1)
  lwz       r4, 0xC(r4)
  stw       r3, 0x2BC(r4)
  stw       r0, 0x2C0(r4)
  lwz       r0, 0x6F8(r1)
  stw       r0, 0x2C4(r4)
  b         .loc_0x2D4C
  lfs       f0, -0x54A8(r2)
  addi      r6, r1, 0x414
  addi      r5, r1, 0x410
  stfs      f0, 0x6A4(r1)
  addi      r4, r1, 0x40C
  addi      r3, r1, 0x69C
  stfs      f0, 0x6A0(r1)
  stfs      f0, 0x69C(r1)
  lwz       r8, 0x20(r31)
  lwz       r7, 0x3F4(r8)
  lwz       r8, 0x224(r8)
  lwz       r7, 0x0(r7)
  lfs       f1, 0x310(r8)
  lfsu      f0, 0x70(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r7)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r7)
  lfs       f0, 0x8(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r7)
  lwz       r7, 0x20(r31)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0x0(r7)
  addi      r8, r7, 0x94
  addi      r7, r7, 0x2BC
  lfs       f0, 0x8(r8)
  lfs       f1, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x414(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x410(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x40C(r1)
  bl        -0x132C6C
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x408
  lfs       f0, 0x69C(r1)
  addi      r5, r1, 0x404
  lwz       r3, 0x224(r3)
  addi      r4, r1, 0x400
  lfs       f1, 0x320(r3)
  addi      r3, r1, 0x69C
  fmuls     f0, f0, f1
  stfs      f0, 0x69C(r1)
  lfs       f0, 0x6A0(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x6A0(r1)
  lfs       f0, 0x6A4(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x6A4(r1)
  lwz       r7, 0x20(r31)
  lfs       f0, 0x69C(r1)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0x0(r7)
  lfsu      f1, 0x70(r7)
  fadds     f0, f1, f0
  stfs      f0, 0x0(r7)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x6A0(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r7)
  lfs       f1, 0x8(r7)
  lfs       f0, 0x6A4(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r7)
  lwz       r8, 0x20(r31)
  lwz       r7, 0x3F4(r8)
  lwz       r8, 0x224(r8)
  lwz       r7, 0xC(r7)
  lfs       f1, 0x310(r8)
  lfsu      f0, 0x70(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r7)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r7)
  lfs       f0, 0x8(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r7)
  lwz       r7, 0x20(r31)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0xC(r7)
  addi      r8, r7, 0x94
  addi      r7, r7, 0x2BC
  lfs       f0, 0x8(r8)
  lfs       f1, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x408(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x404(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x400(r1)
  bl        -0x132D68
  lwz       r4, 0x20(r31)
  mr        r3, r31
  lfs       f0, 0x69C(r1)
  lwz       r4, 0x224(r4)
  lfs       f1, 0x320(r4)
  fmuls     f0, f0, f1
  stfs      f0, 0x69C(r1)
  lfs       f0, 0x6A0(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x6A0(r1)
  lfs       f0, 0x6A4(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x6A4(r1)
  lwz       r4, 0x20(r31)
  lfs       f0, 0x69C(r1)
  lwz       r4, 0x3F4(r4)
  lwz       r4, 0xC(r4)
  lfsu      f1, 0x70(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x0(r4)
  lfs       f1, 0x4(r4)
  lfs       f0, 0x6A0(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r4)
  lfs       f1, 0x8(r4)
  lfs       f0, 0x6A4(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r4)
  lwz       r5, 0x20(r31)
  lwz       r4, 0x2DEC(r13)
  lfs       f1, 0x2D4(r5)
  lfs       f0, 0x28C(r4)
  fadds     f0, f1, f0
  stfs      f0, 0x2D4(r5)
  bl        -0x45F0
  lwz       r3, 0x20(r31)
  lfs       f0, -0x54A8(r2)
  lfs       f1, 0x2C4(r3)
  fcmpo     cr0, f1, f0
  mfcr      r0
  rlwinm.   r0,r0,2,31,31
  bne-      .loc_0x26CC
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x3094
  b         .loc_0x2D4C

.loc_0x26CC:
  lbz       r0, 0x3C5(r3)
  cmplwi    r0, 0
  beq-      .loc_0x26E0
  li        r0, 0x1
  b         .loc_0x26E4

.loc_0x26E0:
  li        r0, 0

.loc_0x26E4:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x28FC
  li        r0, 0x5
  stw       r0, 0x2E8(r3)
  li        r0, 0
  addi      r3, r1, 0x654
  lwz       r4, 0x20(r31)
  stb       r0, 0x2BD(r4)
  stb       r0, 0x0(r31)
  lfs       f0, -0x54A8(r2)
  lwz       r4, 0x20(r31)
  stfs      f0, 0x2D4(r4)
  lwz       r5, 0x20(r31)
  lfs       f0, -0x548C(r2)
  lwz       r4, 0x224(r5)
  lwz       r5, 0x3F4(r5)
  lfs       f1, 0x280(r4)
  lwz       r4, 0x0(r5)
  fmuls     f0, f1, f0
  lfs       f2, -0x5478(r2)
  lwz       r5, 0xC(r5)
  addi      r4, r4, 0x94
  fadds     f31, f2, f0
  addi      r5, r5, 0x94
  bl        .loc_0x2D88
  addi      r3, r1, 0x648
  addi      r4, r1, 0x654
  addi      r5, r13, 0x168
  bl        -0xCAAF4
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x2AC
  lfs       f28, 0x650(r1)
  addi      r5, r1, 0x2A8
  lwz       r3, 0x3F4(r3)
  lfs       f29, 0x64C(r1)
  addi      r4, r1, 0x2A4
  lwz       r3, 0x0(r3)
  lfs       f30, 0x648(r1)
  lfs       f0, 0x9C(r3)
  addi      r7, r3, 0x94
  addi      r3, r1, 0x660
  fsubs     f0, f0, f28
  stfs      f0, 0x2AC(r1)
  lfs       f0, 0x4(r7)
  fsubs     f0, f0, f29
  stfs      f0, 0x2A8(r1)
  lfs       f0, 0x0(r7)
  fsubs     f0, f0, f30
  stfs      f0, 0x2A4(r1)
  bl        -0x132F00
  lfs       f1, 0x660(r1)
  lfs       f0, 0x664(r1)
  stfs      f1, 0x63C(r1)
  stfs      f0, 0x640(r1)
  lfs       f0, 0x668(r1)
  stfs      f0, 0x644(r1)
  lfs       f1, 0x63C(r1)
  lfs       f0, 0x640(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x644(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x15C418
  lfs       f0, -0x54A8(r2)
  fcmpu     cr0, f0, f1
  beq-      .loc_0x27FC
  addi      r3, r1, 0x63C
  bl        -0xE0B20

.loc_0x27FC:
  lfs       f0, 0x63C(r1)
  addi      r6, r1, 0x3F0
  addi      r5, r1, 0x3EC
  fmuls     f0, f0, f31
  addi      r4, r1, 0x3E8
  addi      r3, r1, 0x66C
  stfs      f0, 0x63C(r1)
  lfs       f0, 0x640(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x640(r1)
  lfs       f0, 0x644(r1)
  fmuls     f0, f0, f31
  stfs      f0, 0x644(r1)
  lfs       f1, 0x644(r1)
  lfs       f0, 0x63C(r1)
  fadds     f1, f28, f1
  fadds     f0, f30, f0
  stfs      f1, 0x3F0(r1)
  lfs       f1, 0x640(r1)
  fadds     f1, f29, f1
  stfs      f0, 0x3E8(r1)
  stfs      f1, 0x3EC(r1)
  bl        -0x132FAC
  lwz       r4, 0x20(r31)
  addi      r6, r1, 0x3E4
  lwz       r3, 0x66C(r1)
  addi      r5, r1, 0x3E0
  lwz       r7, 0x3F4(r4)
  lwz       r0, 0x670(r1)
  addi      r4, r1, 0x3DC
  lwz       r7, 0x0(r7)
  stw       r3, 0x2BC(r7)
  addi      r3, r1, 0x678
  stw       r0, 0x2C0(r7)
  lwz       r0, 0x674(r1)
  stw       r0, 0x2C4(r7)
  lfs       f1, 0x644(r1)
  lfs       f0, 0x63C(r1)
  fsubs     f1, f28, f1
  fsubs     f0, f30, f0
  stfs      f1, 0x3E4(r1)
  lfs       f1, 0x640(r1)
  fsubs     f1, f29, f1
  stfs      f0, 0x3DC(r1)
  stfs      f1, 0x3E0(r1)
  bl        -0x133008
  lwz       r5, 0x20(r31)
  mr        r3, r31
  lwz       r4, 0x678(r1)
  lwz       r5, 0x3F4(r5)
  lwz       r0, 0x67C(r1)
  lwz       r5, 0xC(r5)
  stw       r4, 0x2BC(r5)
  stw       r0, 0x2C0(r5)
  lwz       r0, 0x680(r1)
  stw       r0, 0x2C4(r5)
  bl        -0x4748
  mr        r3, r31
  bl        -0x464C
  lwz       r3, 0x20(r31)
  lwz       r3, 0x3FC(r3)
  lwz       r3, 0x3C0(r3)
  bl        0x10D1C
  b         .loc_0x2D4C

.loc_0x28FC:
  lfs       f1, 0x2D4(r3)
  lfs       f0, -0x54A0(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x2914
  li        r0, 0x1
  b         .loc_0x2918

.loc_0x2914:
  li        r0, 0

.loc_0x2918:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x2D4C
  li        r0, 0x1
  stw       r0, 0x2E8(r3)
  li        r0, 0
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  lwz       r3, 0x20(r31)
  stw       r0, 0x318(r3)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2D4C
  li        r4, 0x8D
  bl        -0xC63F4
  b         .loc_0x2D4C
  mr        r3, r31
  bl        -0x3610
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x2D4C
  lwz       r3, 0x20(r31)
  li        r0, 0x8
  li        r4, 0
  stw       r0, 0x2E8(r3)
  li        r0, 0x1
  lwz       r3, 0x20(r31)
  stb       r4, 0x2BD(r3)
  lwz       r3, 0x20(r31)
  stb       r0, 0x3C4(r3)
  lfs       f0, -0x54A8(r2)
  lwz       r3, 0x20(r31)
  stfs      f0, 0x2D4(r3)
  lwz       r3, 0x20(r31)
  stfs      f0, 0x2D0(r3)
  lfs       f0, -0x548C(r2)
  lwz       r3, 0x20(r31)
  stfs      f0, 0x2D8(r3)
  lwz       r3, 0x3120(r13)
  bl        -0x52E60
  lwz       r4, 0x20(r31)
  lfs       f3, 0x94(r3)
  lfs       f1, 0x94(r4)
  lfs       f2, 0x9C(r3)
  lfs       f0, 0x9C(r4)
  fsubs     f1, f3, f1
  fsubs     f2, f2, f0
  bl        0xB17B4
  lwz       r3, 0x20(r31)
  fmr       f30, f1
  lfs       f2, -0x5474(r2)
  lwz       r3, 0x224(r3)
  lfs       f0, 0x280(r3)
  fadds     f29, f2, f0
  bl        0xB18F4
  fmr       f28, f1
  fmr       f1, f30
  bl        0xB1A7C
  lfs       f2, 0x170(r13)
  fmuls     f0, f1, f29
  fmuls     f3, f28, f29
  addi      r6, r1, 0x2A0
  fmuls     f1, f2, f29
  stfs      f0, 0x298(r1)
  addi      r5, r1, 0x29C
  stfs      f3, 0x2A0(r1)
  addi      r4, r1, 0x298
  addi      r3, r1, 0x600
  stfs      f1, 0x29C(r1)
  bl        -0x133180
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x3D0
  lfs       f0, 0x608(r1)
  addi      r5, r1, 0x3CC
  lfs       f2, 0x308(r3)
  addi      r7, r3, 0x300
  lfs       f1, 0x604(r1)
  fadds     f2, f2, f0
  lfs       f0, 0x600(r1)
  addi      r4, r1, 0x3C8
  addi      r3, r1, 0x5F4
  stfs      f2, 0x3D0(r1)
  lfs       f2, 0x4(r7)
  fadds     f1, f2, f1
  stfs      f1, 0x3CC(r1)
  lfs       f1, 0x0(r7)
  fadds     f0, f1, f0
  stfs      f0, 0x3C8(r1)
  bl        -0x1331CC
  lwz       r4, 0x20(r31)
  lwz       r3, 0x5F4(r1)
  lwz       r4, 0x3F4(r4)
  lwz       r0, 0x5F8(r1)
  lwz       r4, 0x0(r4)
  stw       r3, 0x2BC(r4)
  stw       r0, 0x2C0(r4)
  lwz       r0, 0x5FC(r1)
  stw       r0, 0x2C4(r4)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2D4C
  li        r4, 0x8D
  bl        -0xC6554
  b         .loc_0x2D4C
  mr        r3, r31
  bl        -0x2F50
  lwz       r3, 0x20(r31)
  lbz       r0, 0x2BD(r3)
  cmplwi    r0, 0
  beq-      .loc_0x2D4C
  li        r0, 0x1
  stw       r0, 0x2E8(r3)
  li        r0, 0
  lwz       r3, 0x20(r31)
  stb       r0, 0x2BD(r3)
  lwz       r3, 0x20(r31)
  stw       r0, 0x318(r3)
  lwz       r3, 0x20(r31)
  lwz       r3, 0x2C(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2D4C
  li        r4, 0x8D
  bl        -0xC65A4
  b         .loc_0x2D4C
  lfs       f0, -0x54A8(r2)
  addi      r6, r1, 0x3C0
  addi      r5, r1, 0x3BC
  stfs      f0, 0x5D4(r1)
  addi      r4, r1, 0x3B8
  addi      r3, r1, 0x5CC
  stfs      f0, 0x5D0(r1)
  stfs      f0, 0x5CC(r1)
  lwz       r8, 0x20(r31)
  lwz       r7, 0x3F4(r8)
  lwz       r8, 0x224(r8)
  lwz       r7, 0x0(r7)
  lfs       f1, 0x310(r8)
  lfsu      f0, 0x70(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r7)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r7)
  lfs       f0, 0x8(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r7)
  lwz       r7, 0x20(r31)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0x0(r7)
  addi      r8, r7, 0x94
  addi      r7, r7, 0x2BC
  lfs       f0, 0x8(r8)
  lfs       f1, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x3C0(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x3BC(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x3B8(r1)
  bl        -0x1332FC
  lwz       r3, 0x20(r31)
  addi      r6, r1, 0x3B4
  lfs       f0, 0x5CC(r1)
  addi      r5, r1, 0x3B0
  lwz       r3, 0x224(r3)
  addi      r4, r1, 0x3AC
  lfs       f1, 0x320(r3)
  addi      r3, r1, 0x5CC
  fmuls     f0, f0, f1
  stfs      f0, 0x5CC(r1)
  lfs       f0, 0x5D0(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x5D0(r1)
  lfs       f0, 0x5D4(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x5D4(r1)
  lwz       r7, 0x20(r31)
  lfs       f0, 0x5CC(r1)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0x0(r7)
  lfsu      f1, 0x70(r7)
  fadds     f0, f1, f0
  stfs      f0, 0x0(r7)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x5D0(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r7)
  lfs       f1, 0x8(r7)
  lfs       f0, 0x5D4(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r7)
  lwz       r8, 0x20(r31)
  lwz       r7, 0x3F4(r8)
  lwz       r8, 0x224(r8)
  lwz       r7, 0xC(r7)
  lfs       f1, 0x310(r8)
  lfsu      f0, 0x70(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x0(r7)
  lfs       f0, 0x4(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x4(r7)
  lfs       f0, 0x8(r7)
  fmuls     f0, f0, f1
  stfs      f0, 0x8(r7)
  lwz       r7, 0x20(r31)
  lwz       r7, 0x3F4(r7)
  lwz       r7, 0xC(r7)
  addi      r8, r7, 0x94
  addi      r7, r7, 0x2BC
  lfs       f0, 0x8(r8)
  lfs       f1, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x3B4(r1)
  lfs       f1, 0x4(r7)
  lfs       f0, 0x4(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x3B0(r1)
  lfs       f1, 0x0(r7)
  lfs       f0, 0x0(r8)
  fsubs     f0, f1, f0
  stfs      f0, 0x3AC(r1)
  bl        -0x1333F8
  lwz       r3, 0x20(r31)
  lfs       f0, 0x5CC(r1)
  lwz       r3, 0x224(r3)
  lfs       f1, 0x320(r3)
  fmuls     f0, f0, f1
  stfs      f0, 0x5CC(r1)
  lfs       f0, 0x5D0(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x5D0(r1)
  lfs       f0, 0x5D4(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x5D4(r1)
  lwz       r3, 0x20(r31)
  lfs       f0, 0x5CC(r1)
  lwz       r3, 0x3F4(r3)
  lwz       r3, 0xC(r3)
  lfsu      f1, 0x70(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x0(r3)
  lfs       f1, 0x4(r3)
  lfs       f0, 0x5D0(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x4(r3)
  lfs       f1, 0x8(r3)
  lfs       f0, 0x5D4(r1)
  fadds     f0, f1, f0
  stfs      f0, 0x8(r3)
  lwz       r3, 0x20(r31)
  lfs       f0, -0x542C(r2)
  lfs       f1, 0x2D4(r3)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x2D34
  lwz       r12, 0x0(r3)
  lwz       r12, 0x10C(r12)
  mtlr      r12
  blrl      

.loc_0x2D34:
  lwz       r4, 0x20(r31)
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x2D4(r4)
  lfs       f0, 0x28C(r3)
  fadds     f0, f1, f0
  stfs      f0, 0x2D4(r4)

.loc_0x2D4C:
  lwz       r3, 0x20(r31)
  lwz       r3, 0x3F8(r3)
  lwz       r3, 0x3BC(r3)
  lwz       r0, 0x4(r3)
  stw       r0, 0x4(r31)
  lwz       r0, 0xBAC(r1)
  lfd       f31, 0xBA0(r1)
  lfd       f30, 0xB98(r1)
  lfd       f29, 0xB90(r1)
  lfd       f28, 0xB88(r1)
  lwz       r31, 0xB84(r1)
  lwz       r30, 0xB80(r1)
  addi      r1, r1, 0xBA8
  mtlr      r0
  blr       

.loc_0x2D88:
*/
}

/*
 * --INFO--
 * Address:	8016A5FC
 * Size:	000034
 */
void operator+ (const Vector3f &, const Vector3f &)
{
/*
.loc_0x0:
  lfs       f1, 0x0(r4)
  lfs       f0, 0x0(r5)
  lfs       f3, 0x4(r4)
  lfs       f2, 0x4(r5)
  fadds     f0, f1, f0
  lfs       f4, 0x8(r4)
  lfs       f1, 0x8(r5)
  fadds     f2, f3, f2
  stfs      f0, 0x0(r3)
  fadds     f0, f4, f1
  stfs      f2, 0x4(r3)
  stfs      f0, 0x8(r3)
  blr
*/
}
