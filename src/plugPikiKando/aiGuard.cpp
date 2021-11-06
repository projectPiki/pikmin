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
 * Address:	800BB534
 * Size:	000084
 */
ActGuard::ActGuard(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        0x8884
  lis       r3, 0x802B
  addi      r0, r3, 0x6CD0
  stw       r0, 0x0(r31)
  li        r0, 0
  addi      r3, r31, 0
  stw       r0, 0x14(r31)
  stw       r0, 0x18(r31)
  stw       r0, 0x1C(r31)
  lfs       f0, -0x6CA0(r2)
  stfs      f0, 0x28(r31)
  stfs      f0, 0x24(r31)
  stfs      f0, 0x20(r31)
  stfs      f0, 0x38(r31)
  stfs      f0, 0x34(r31)
  stfs      f0, 0x30(r31)
  stw       r0, 0x14(r31)
  stw       r0, 0x18(r31)
  stw       r0, 0x1C(r31)
  stb       r0, 0x49(r31)
  lfs       f0, -0x6C9C(r2)
  stfs      f0, 0x3C(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BB5B8
 * Size:	0000C4
 */
void ActGuard::init(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  li        r30, 0
  stw       r29, 0x24(r1)
  addi      r29, r3, 0
  stw       r30, 0x14(r3)
  stw       r30, 0x18(r29)
  stw       r30, 0x1C(r29)
  bl        0x8DC
  mr.       r31, r3
  beq-      .loc_0x64
  lwz       r3, 0x14(r29)
  cmplwi    r3, 0
  beq-      .loc_0x50
  beq-      .loc_0x50
  bl        0x28D6C
  stw       r30, 0x14(r29)

.loc_0x50:
  stw       r31, 0x14(r29)
  lwz       r3, 0x14(r29)
  cmplwi    r3, 0
  beq-      .loc_0x64
  bl        0x28D44

.loc_0x64:
  lfs       f0, -0x6C98(r2)
  li        r5, 0
  li        r0, 0x1
  stfs      f0, 0x40(r29)
  addi      r3, r1, 0x10
  li        r4, 0x3
  stb       r5, 0x48(r29)
  stb       r0, 0x49(r29)
  bl        0x6391C
  addi      r31, r3, 0
  addi      r3, r1, 0x18
  li        r4, 0x3
  bl        0x6390C
  mr        r4, r3
  lwz       r3, 0xC(r29)
  mr        r5, r31
  bl        0xF37C
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
 * Address:	800BB67C
 * Size:	00011C
 */
void ActGuard::cleanup()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  mr        r31, r3
  stw       r30, 0x38(r1)
  lwz       r3, 0x14(r3)
  cmplwi    r3, 0
  beq-      .loc_0x30
  bl        0x28CCC
  li        r0, 0
  stw       r0, 0x14(r31)

.loc_0x30:
  lwz       r3, 0x1C(r31)
  cmplwi    r3, 0
  beq-      .loc_0x94
  lwz       r3, 0x4F8(r3)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x54
  li        r3, 0
  b         .loc_0x60

.loc_0x54:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0x60:
  addi      r30, r3, 0x18
  lwz       r3, 0x18(r3)
  cmplwi    r3, 0
  beq-      .loc_0x7C
  bl        0x28C80
  li        r0, 0
  stw       r0, 0x0(r30)

.loc_0x7C:
  lwz       r3, 0x1C(r31)
  cmplwi    r3, 0
  beq-      .loc_0x94
  bl        0x28C68
  li        r0, 0
  stw       r0, 0x1C(r31)

.loc_0x94:
  lwz       r3, 0x18(r31)
  cmplwi    r3, 0
  beq-      .loc_0xF8
  lwz       r3, 0x4F8(r3)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0xB8
  li        r3, 0
  b         .loc_0xC4

.loc_0xB8:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0xC4:
  addi      r30, r3, 0x1C
  lwz       r3, 0x1C(r3)
  cmplwi    r3, 0
  beq-      .loc_0xE0
  bl        0x28C1C
  li        r0, 0
  stw       r0, 0x0(r30)

.loc_0xE0:
  lwz       r3, 0x18(r31)
  cmplwi    r3, 0
  beq-      .loc_0xF8
  bl        0x28C04
  li        r0, 0
  stw       r0, 0x18(r31)

.loc_0xF8:
  li        r0, 0
  stb       r0, 0x49(r31)
  bl        0x15C8F4
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BB798
 * Size:	00000C
 */
void ActGuard::dump()
{
/*
.loc_0x0:
  lwz       r0, 0x14(r3)
  cmplwi    r0, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BB7A4
 * Size:	00071C
 */
void ActGuard::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x2B8(r1)
  stfd      f31, 0x2B0(r1)
  stfd      f30, 0x2A8(r1)
  stw       r31, 0x2A4(r1)
  mr        r31, r3
  stw       r30, 0x2A0(r1)
  lfs       f0, -0x4820(r13)
  lwz       r3, 0xC(r3)
  stfsu     f0, 0xA4(r3)
  lfs       f0, -0x481C(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x4818(r13)
  stfs      f0, 0x8(r3)
  lwz       r0, 0x14(r31)
  cmplwi    r0, 0
  bne-      .loc_0x94
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x40(r31)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x40(r31)
  lfs       f1, 0x40(r31)
  lfs       f0, -0x6CA0(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x74
  li        r3, 0x1
  b         .loc_0x6FC

.loc_0x74:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x48(r12)
  mtlr      r12
  blrl      
  li        r3, 0
  b         .loc_0x6FC

.loc_0x94:
  lbz       r0, 0x48(r31)
  cmplwi    r0, 0
  beq-      .loc_0x5EC
  lwz       r30, 0x18(r31)
  cmplwi    r30, 0
  beq-      .loc_0x394
  lwz       r3, 0xC(r31)
  lfsu      f0, 0x94(r3)
  lfs       f1, 0x94(r30)
  lfs       f3, 0x98(r30)
  lfs       f2, 0x4(r3)
  fsubs     f0, f1, f0
  lfs       f4, 0x9C(r30)
  lfs       f1, 0x8(r3)
  fsubs     f2, f3, f2
  stfs      f0, 0x294(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x298(r1)
  stfs      f0, 0x29C(r1)
  lfs       f1, 0x294(r1)
  lfs       f2, 0x29C(r1)
  bl        0x16016C
  lfs       f2, 0x294(r1)
  fmr       f31, f1
  lfs       f0, 0x298(r1)
  fmuls     f3, f2, f2
  lfs       f4, 0x29C(r1)
  fmuls     f2, f0, f0
  fmuls     f4, f4, f4
  lfs       f0, -0x6CA0(r2)
  fadds     f2, f3, f2
  fadds     f5, f4, f2
  fcmpo     cr0, f5, f0
  ble-      .loc_0x174
  fsqrte    f1, f5
  lfd       f3, -0x6C90(r2)
  lfd       f2, -0x6C88(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f5, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f5, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f5, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f5, f0
  frsp      f0, f0
  stfs      f0, 0x124(r1)
  lfs       f5, 0x124(r1)

.loc_0x174:
  lfs       f1, -0x6C80(r2)
  addi      r3, r1, 0x238
  lfs       f0, 0x294(r1)
  addi      r4, r1, 0x294
  fdivs     f3, f1, f5
  lfs       f1, 0x298(r1)
  addi      r5, r1, 0x234
  lfs       f2, 0x29C(r1)
  fmuls     f0, f0, f3
  fmuls     f4, f1, f3
  fmuls     f1, f2, f3
  stfs      f0, 0x294(r1)
  stfs      f4, 0x298(r1)
  stfs      f1, 0x29C(r1)
  lfs       f0, 0x3C(r31)
  lwz       r6, 0x2DEC(r13)
  fsubs     f0, f5, f0
  lfs       f30, 0x28C(r6)
  stfs      f0, 0x234(r1)
  bl        -0x1C490
  lfs       f2, 0x240(r1)
  addi      r6, r1, 0x118
  lfs       f1, 0x23C(r1)
  addi      r5, r1, 0x114
  lfs       f0, 0x238(r1)
  fmuls     f2, f2, f30
  addi      r4, r1, 0x110
  fmuls     f1, f1, f30
  addi      r3, r1, 0x244
  fmuls     f0, f0, f30
  stfs      f2, 0x118(r1)
  stfs      f1, 0x114(r1)
  stfs      f0, 0x110(r1)
  bl        -0x84880
  lwz       r3, 0xC(r31)
  fmr       f1, f31
  lwz       r4, 0x2DEC(r13)
  lfs       f0, 0x70(r3)
  addi      r5, r3, 0x70
  lfs       f7, 0x28C(r4)
  lfs       f3, 0x78(r3)
  lfs       f2, 0x74(r3)
  fmuls     f0, f0, f7
  lfs       f5, 0x24C(r1)
  fmuls     f3, f3, f7
  fmuls     f6, f2, f7
  stfs      f0, 0x178(r1)
  lfs       f9, -0x4814(r13)
  lfs       f0, 0x178(r1)
  lfs       f4, 0x248(r1)
  lfs       f2, 0x244(r1)
  stfs      f0, 0x200(r1)
  fmuls     f7, f4, f9
  fmuls     f8, f2, f9
  stfs      f6, 0x204(r1)
  fmuls     f4, f5, f9
  stfs      f3, 0x208(r1)
  lfs       f0, 0x200(r1)
  lfs       f2, -0x4810(r13)
  fmuls     f0, f0, f2
  stfs      f0, 0x16C(r1)
  lfs       f0, 0x16C(r1)
  stfs      f0, 0x20C(r1)
  lfs       f0, 0x204(r1)
  fmuls     f0, f0, f2
  stfs      f0, 0x210(r1)
  lfs       f0, 0x208(r1)
  fmuls     f0, f0, f2
  stfs      f0, 0x214(r1)
  lfs       f0, 0x70(r3)
  lfs       f3, 0x78(r3)
  lfs       f2, 0x74(r3)
  fadds     f0, f0, f8
  fadds     f3, f3, f4
  fadds     f2, f2, f7
  stfs      f0, 0x184(r1)
  lfs       f0, 0x184(r1)
  stfs      f0, 0x218(r1)
  stfs      f2, 0x21C(r1)
  stfs      f3, 0x220(r1)
  lfs       f2, 0x218(r1)
  lfs       f0, 0x20C(r1)
  fsubs     f0, f2, f0
  stfs      f0, 0x160(r1)
  lfs       f0, 0x160(r1)
  stfs      f0, 0x224(r1)
  lfs       f2, 0x21C(r1)
  lfs       f0, 0x210(r1)
  fsubs     f0, f2, f0
  stfs      f0, 0x228(r1)
  lfs       f2, 0x220(r1)
  lfs       f0, 0x214(r1)
  fsubs     f0, f2, f0
  stfs      f0, 0x22C(r1)
  lwz       r3, 0x224(r1)
  lwz       r0, 0x228(r1)
  stw       r3, 0x0(r5)
  stw       r0, 0x4(r5)
  lwz       r0, 0x22C(r1)
  stw       r0, 0x8(r5)
  lfs       f2, 0xA0(r30)
  bl        -0x834F8
  lfs       f0, -0x6CA0(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x358
  lfs       f0, -0x6C7C(r2)
  lwz       r3, 0x2DEC(r13)
  fsubs     f1, f31, f0
  lfs       f30, 0x28C(r3)
  bl        -0x83544
  lwz       r3, 0xC(r31)
  lfs       f2, 0xA0(r3)
  bl        -0x83524
  fmuls     f1, f1, f30
  lfs       f0, -0x6C78(r2)
  lwz       r3, 0xC(r31)
  fdivs     f1, f1, f0
  lfs       f0, 0xA0(r3)
  fadds     f0, f0, f1
  stfs      f0, 0xA0(r3)
  b         .loc_0x394

.loc_0x358:
  lfs       f0, -0x6C7C(r2)
  lwz       r3, 0x2DEC(r13)
  fadds     f1, f0, f31
  lfs       f30, 0x28C(r3)
  bl        -0x83584
  lwz       r3, 0xC(r31)
  lfs       f2, 0xA0(r3)
  bl        -0x83564
  fmuls     f1, f1, f30
  lfs       f0, -0x6C78(r2)
  lwz       r3, 0xC(r31)
  fdivs     f1, f1, f0
  lfs       f0, 0xA0(r3)
  fadds     f0, f0, f1
  stfs      f0, 0xA0(r3)

.loc_0x394:
  lwz       r4, 0x1C(r31)
  cmplwi    r4, 0
  beq-      .loc_0x5E4
  lwz       r3, 0xC(r31)
  lfsu      f0, 0x94(r3)
  lfs       f1, 0x94(r4)
  lfs       f3, 0x98(r4)
  lfs       f2, 0x4(r3)
  fsubs     f0, f1, f0
  lfs       f4, 0x9C(r4)
  lfs       f1, 0x8(r3)
  fsubs     f2, f3, f2
  stfs      f0, 0x278(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x27C(r1)
  stfs      f0, 0x280(r1)
  lfs       f1, 0x278(r1)
  lfs       f3, 0x280(r1)
  lfs       f0, 0x27C(r1)
  fmuls     f2, f1, f1
  fmuls     f3, f3, f3
  fmuls     f1, f0, f0
  lfs       f0, -0x6CA0(r2)
  fadds     f1, f2, f1
  fadds     f5, f3, f1
  fcmpo     cr0, f5, f0
  ble-      .loc_0x458
  fsqrte    f1, f5
  lfd       f3, -0x6C90(r2)
  lfd       f2, -0x6C88(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f5, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f5, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f5, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f5, f0
  frsp      f0, f0
  stfs      f0, 0x11C(r1)
  lfs       f5, 0x11C(r1)

.loc_0x458:
  lfs       f1, -0x6C80(r2)
  addi      r3, r1, 0x1CC
  lfs       f0, 0x278(r1)
  addi      r4, r1, 0x278
  fdivs     f3, f1, f5
  lfs       f1, 0x27C(r1)
  addi      r5, r1, 0x1C8
  lfs       f2, 0x280(r1)
  fmuls     f0, f0, f3
  fmuls     f4, f1, f3
  fmuls     f1, f2, f3
  stfs      f0, 0x278(r1)
  stfs      f4, 0x27C(r1)
  stfs      f1, 0x280(r1)
  lfs       f0, 0x3C(r31)
  lwz       r6, 0x2DEC(r13)
  fsubs     f0, f5, f0
  lfs       f30, 0x28C(r6)
  stfs      f0, 0x1C8(r1)
  bl        -0x1C774
  lfs       f2, 0x1D4(r1)
  addi      r6, r1, 0x10C
  lfs       f1, 0x1D0(r1)
  addi      r5, r1, 0x108
  lfs       f0, 0x1CC(r1)
  fmuls     f2, f2, f30
  addi      r4, r1, 0x104
  fmuls     f1, f1, f30
  addi      r3, r1, 0x1D8
  fmuls     f0, f0, f30
  stfs      f2, 0x10C(r1)
  stfs      f1, 0x108(r1)
  stfs      f0, 0x104(r1)
  bl        -0x84B64
  lwz       r3, 0xC(r31)
  lwz       r4, 0x2DEC(r13)
  lfs       f0, 0x70(r3)
  addi      r5, r3, 0x70
  lfs       f5, 0x28C(r4)
  lfs       f2, 0x78(r3)
  fmuls     f0, f0, f5
  lfs       f1, 0x74(r3)
  fmuls     f4, f2, f5
  lfs       f3, 0x1E0(r1)
  fmuls     f5, f1, f5
  stfs      f0, 0x144(r1)
  lfs       f7, -0x480C(r13)
  lfs       f0, 0x144(r1)
  lfs       f1, 0x1D8(r1)
  fmuls     f3, f3, f7
  lfs       f2, 0x1DC(r1)
  stfs      f0, 0x194(r1)
  fmuls     f6, f1, f7
  stfs      f5, 0x198(r1)
  fmuls     f5, f2, f7
  stfs      f4, 0x19C(r1)
  lfs       f0, 0x194(r1)
  lfs       f1, -0x4808(r13)
  fmuls     f0, f0, f1
  stfs      f0, 0x138(r1)
  lfs       f0, 0x138(r1)
  stfs      f0, 0x1A0(r1)
  lfs       f0, 0x198(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x1A4(r1)
  lfs       f0, 0x19C(r1)
  fmuls     f0, f0, f1
  stfs      f0, 0x1A8(r1)
  lfs       f0, 0x70(r3)
  lfs       f2, 0x78(r3)
  lfs       f1, 0x74(r3)
  fadds     f0, f0, f6
  fadds     f2, f2, f3
  fadds     f1, f1, f5
  stfs      f0, 0x150(r1)
  lfs       f0, 0x150(r1)
  stfs      f0, 0x1AC(r1)
  stfs      f1, 0x1B0(r1)
  stfs      f2, 0x1B4(r1)
  lfs       f1, 0x1AC(r1)
  lfs       f0, 0x1A0(r1)
  fsubs     f0, f1, f0
  stfs      f0, 0x12C(r1)
  lfs       f0, 0x12C(r1)
  stfs      f0, 0x1B8(r1)
  lfs       f1, 0x1B0(r1)
  lfs       f0, 0x1A4(r1)
  fsubs     f0, f1, f0
  stfs      f0, 0x1BC(r1)
  lfs       f1, 0x1B4(r1)
  lfs       f0, 0x1A8(r1)
  fsubs     f0, f1, f0
  stfs      f0, 0x1C0(r1)
  lwz       r3, 0x1B8(r1)
  lwz       r0, 0x1BC(r1)
  stw       r3, 0x0(r5)
  stw       r0, 0x4(r5)
  lwz       r0, 0x1C0(r1)
  stw       r0, 0x8(r5)

.loc_0x5E4:
  li        r3, 0
  b         .loc_0x6FC

.loc_0x5EC:
  lwz       r0, 0x18(r31)
  cmplwi    r0, 0
  bne-      .loc_0x600
  lwz       r0, 0x1C(r31)
  cmplwi    r0, 0

.loc_0x600:
  mr        r3, r31
  bl        0x660
  lwz       r0, 0x44(r31)
  cmpwi     r0, 0x1
  bne-      .loc_0x620
  mr        r3, r31
  bl        0xB18
  b         .loc_0x628

.loc_0x620:
  mr        r3, r31
  bl        0x948

.loc_0x628:
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x6C4
  li        r3, 0x1
  stb       r3, 0x48(r31)
  lfs       f0, -0x6C9C(r2)
  stfs      f0, 0x3C(r31)
  lwz       r0, 0x44(r31)
  cmpwi     r0, 0x1
  bne-      .loc_0x658
  li        r0, 0
  stw       r0, 0x44(r31)
  b         .loc_0x65C

.loc_0x658:
  stw       r3, 0x44(r31)

.loc_0x65C:
  mr        r3, r31
  lwz       r4, 0x44(r31)
  bl        0x3A8
  mr.       r30, r3
  beq-      .loc_0x6DC
  lwz       r3, 0x14(r31)
  cmplwi    r3, 0
  beq-      .loc_0x68C
  beq-      .loc_0x68C
  bl        0x28548
  li        r0, 0
  stw       r0, 0x14(r31)

.loc_0x68C:
  stw       r30, 0x14(r31)
  lwz       r3, 0x14(r31)
  cmplwi    r3, 0
  beq-      .loc_0x6A0
  bl        0x2851C

.loc_0x6A0:
  lwz       r0, 0x44(r31)
  cmpwi     r0, 0x1
  bne-      .loc_0x6B8
  mr        r3, r31
  bl        0xA80
  b         .loc_0x6DC

.loc_0x6B8:
  mr        r3, r31
  bl        0x8B0
  b         .loc_0x6DC

.loc_0x6C4:
  lwz       r3, 0x14(r31)
  cmplwi    r3, 0
  beq-      .loc_0x6DC
  bl        0x284F8
  li        r0, 0
  stw       r0, 0x14(r31)

.loc_0x6DC:
  lwz       r4, 0xC(r31)
  li        r3, 0
  lfs       f0, -0x4804(r13)
  stfsu     f0, 0xA4(r4)
  lfs       f0, -0x4800(r13)
  stfs      f0, 0x4(r4)
  lfs       f0, -0x47FC(r13)
  stfs      f0, 0x8(r4)

.loc_0x6FC:
  lwz       r0, 0x2BC(r1)
  lfd       f31, 0x2B0(r1)
  lfd       f30, 0x2A8(r1)
  lwz       r31, 0x2A4(r1)
  lwz       r30, 0x2A0(r1)
  addi      r1, r1, 0x2B8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BBEC0
 * Size:	0001F4
 */
void ActGuard::findFriend()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x88(r1)
  stfd      f31, 0x80(r1)
  stfd      f30, 0x78(r1)
  stmw      r27, 0x64(r1)
  mr        r29, r3
  li        r30, 0
  lwz       r31, 0x3068(r13)
  lfs       f31, -0x6C74(r2)
  lwz       r12, 0x0(r31)
  addi      r3, r31, 0
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r28, r3
  b         .loc_0x14C

.loc_0x44:
  cmpwi     r28, -0x1
  bne-      .loc_0x68
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x80

.loc_0x68:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x80:
  lwz       r0, 0xC(r29)
  addi      r27, r3, 0
  cmplw     r3, r0
  beq-      .loc_0x130
  mr        r3, r27
  lwz       r12, 0x0(r27)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x130
  lhz       r0, 0x4FC(r27)
  cmplwi    r0, 0x4
  bne-      .loc_0x130
  lwz       r3, 0x4F8(r27)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0xD0
  li        r3, 0
  b         .loc_0xDC

.loc_0xD0:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0xDC:
  lbz       r0, 0x49(r3)
  cmplwi    r0, 0
  beq-      .loc_0x130
  mr        r3, r27
  lwz       r4, 0xC(r29)
  bl        -0x2F134
  fmr       f30, f1
  fcmpo     cr0, f30, f31
  bge-      .loc_0x130
  addi      r3, r29, 0
  addi      r4, r27, 0
  bl        0x638
  cmplwi    r3, 0
  beq-      .loc_0x128
  addi      r3, r29, 0
  addi      r4, r27, 0
  bl        0x6AC
  cmplwi    r3, 0
  bne-      .loc_0x130

.loc_0x128:
  mr        r30, r27
  fmr       f31, f30

.loc_0x130:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r28
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r28, r3

.loc_0x14C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r28
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x174
  li        r0, 0x1
  b         .loc_0x1A0

.loc_0x174:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r28
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x19C
  li        r0, 0x1
  b         .loc_0x1A0

.loc_0x19C:
  li        r0, 0

.loc_0x1A0:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x44
  cmplwi    r30, 0
  beq-      .loc_0x1D4
  lwz       r3, 0xC(r29)
  lfsu      f3, 0x94(r3)
  lfs       f1, 0x94(r30)
  lfs       f0, 0x9C(r30)
  lfs       f2, 0x8(r3)
  fsubs     f1, f3, f1
  fsubs     f2, f2, f0
  bl        0x15F96C
  stfs      f1, 0x2C(r29)

.loc_0x1D4:
  mr        r3, r30
  lmw       r27, 0x64(r1)
  lwz       r0, 0x8C(r1)
  lfd       f31, 0x80(r1)
  lfd       f30, 0x78(r1)
  addi      r1, r1, 0x88
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BC0B4
 * Size:	0000FC
 */
void ActGuard::checkLoop(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  li        r31, -0x1
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  addi      r29, r4, 0
  addi      r30, r29, 0
  stw       r28, 0x10(r1)
  addi      r28, r3, 0
  b         .loc_0x58

.loc_0x30:
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x514
  lwz       r0, 0xC(r28)
  cmplw     r3, r0
  bne-      .loc_0x50
  mr        r3, r31
  b         .loc_0xDC

.loc_0x50:
  addi      r30, r3, 0
  addi      r31, r31, 0x1

.loc_0x58:
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x4EC
  cmplwi    r3, 0
  beq-      .loc_0x80
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x4D8
  cmplw     r3, r29
  bne+      .loc_0x30

.loc_0x80:
  li        r31, -0x1
  b         .loc_0xB0

.loc_0x88:
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x544
  lwz       r0, 0xC(r28)
  cmplw     r3, r0
  bne-      .loc_0xA8
  mr        r3, r31
  b         .loc_0xDC

.loc_0xA8:
  addi      r30, r3, 0
  addi      r31, r31, 0x1

.loc_0xB0:
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x51C
  cmplwi    r3, 0
  beq-      .loc_0xD8
  addi      r3, r28, 0
  addi      r4, r30, 0
  bl        0x508
  cmplw     r3, r29
  bne+      .loc_0x88

.loc_0xD8:
  li        r3, -0x1

.loc_0xDC:
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
 * Address:	800BC1B0
 * Size:	000258
 */
void ActGuard::findFriend(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x90(r1)
  stfd      f31, 0x88(r1)
  stfd      f30, 0x80(r1)
  stmw      r26, 0x68(r1)
  mr        r27, r3
  addi      r28, r4, 0
  li        r29, 0
  lwz       r31, 0x3068(r13)
  lfs       f31, -0x6C70(r2)
  lwz       r12, 0x0(r31)
  addi      r3, r31, 0
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0x1B0

.loc_0x48:
  cmpwi     r30, -0x1
  bne-      .loc_0x6C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x84

.loc_0x6C:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x84:
  lwz       r0, 0x14(r27)
  addi      r26, r3, 0
  cmplw     r3, r0
  beq-      .loc_0x194
  lwz       r0, 0xC(r27)
  cmplw     r26, r0
  beq-      .loc_0x194
  mr        r3, r26
  lwz       r12, 0x0(r26)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x194
  lhz       r0, 0x4FC(r26)
  cmplwi    r0, 0x4
  bne-      .loc_0x194
  lwz       r3, 0x4F8(r26)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0xE0
  li        r3, 0
  b         .loc_0xEC

.loc_0xE0:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0xEC:
  lbz       r0, 0x49(r3)
  cmplwi    r0, 0
  beq-      .loc_0x194
  mr        r3, r26
  lwz       r4, 0xC(r27)
  bl        -0x2F434
  fmr       f30, f1
  addi      r3, r27, 0
  addi      r4, r26, 0
  bl        0x340
  cmplwi    r3, 0
  beq-      .loc_0x124
  cmpwi     r28, 0
  beq-      .loc_0x194

.loc_0x124:
  addi      r3, r27, 0
  addi      r4, r26, 0
  bl        0x3AC
  cmplwi    r3, 0
  beq-      .loc_0x140
  cmpwi     r28, 0x1
  beq-      .loc_0x194

.loc_0x140:
  addi      r3, r27, 0
  addi      r4, r26, 0
  bl        -0x244
  cmpwi     r3, -0x1
  beq-      .loc_0x15C
  cmpwi     r3, 0x3
  blt-      .loc_0x194

.loc_0x15C:
  fcmpo     cr0, f30, f31
  bge-      .loc_0x194
  addi      r3, r27, 0
  addi      r4, r26, 0
  bl        0x2E4
  cmplwi    r3, 0
  beq-      .loc_0x18C
  addi      r3, r27, 0
  addi      r4, r26, 0
  bl        0x358
  cmplwi    r3, 0
  bne-      .loc_0x194

.loc_0x18C:
  mr        r29, r26
  fmr       f31, f30

.loc_0x194:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0x1B0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1D8
  li        r0, 0x1
  b         .loc_0x204

.loc_0x1D8:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x200
  li        r0, 0x1
  b         .loc_0x204

.loc_0x200:
  li        r0, 0

.loc_0x204:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x48
  cmplwi    r29, 0
  beq-      .loc_0x238
  lwz       r3, 0xC(r27)
  lfsu      f3, 0x94(r3)
  lfs       f1, 0x94(r29)
  lfs       f0, 0x9C(r29)
  lfs       f2, 0x8(r3)
  fsubs     f1, f3, f1
  fsubs     f2, f2, f0
  bl        0x15F618
  stfs      f1, 0x2C(r27)

.loc_0x238:
  mr        r3, r29
  lmw       r26, 0x68(r1)
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
 * Address:	800BC408
 * Size:	0001F8
 */
void ActGuard::setGoal()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  stfd      f31, 0x60(r1)
  stfd      f30, 0x58(r1)
  stfd      f29, 0x50(r1)
  stw       r31, 0x4C(r1)
  stw       r30, 0x48(r1)
  mr        r30, r3
  lwz       r31, 0x14(r3)
  addi      r4, r31, 0
  bl        .loc_0x1F8
  cmplwi    r3, 0
  beq-      .loc_0x58
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        0x240
  cmplwi    r3, 0
  bne-      .loc_0x58
  li        r0, 0x1
  stw       r0, 0x44(r30)
  b         .loc_0x124

.loc_0x58:
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        .loc_0x1F8
  cmplwi    r3, 0
  bne-      .loc_0x8C
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        0x20C
  cmplwi    r3, 0
  beq-      .loc_0x8C
  li        r0, 0
  stw       r0, 0x44(r30)
  b         .loc_0x124

.loc_0x8C:
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        .loc_0x1F8
  cmplwi    r3, 0
  bne-      .loc_0x108
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        0x1D8
  cmplwi    r3, 0
  bne-      .loc_0x108
  bl        0x15BBB4
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6C60(r2)
  stw       r0, 0x44(r1)
  lis       r0, 0x4330
  lfs       f2, -0x6C6C(r2)
  stw       r0, 0x40(r1)
  lfs       f1, -0x6C80(r2)
  lfd       f3, 0x40(r1)
  lfs       f0, -0x6C78(r2)
  fsubs     f3, f3, f4
  fdivs     f2, f3, f2
  fmuls     f1, f1, f2
  fcmpo     cr0, f1, f0
  ble-      .loc_0xFC
  li        r0, 0x1
  stw       r0, 0x44(r30)
  b         .loc_0x124

.loc_0xFC:
  li        r0, 0
  stw       r0, 0x44(r30)
  b         .loc_0x124

.loc_0x108:
  lwz       r3, 0x14(r30)
  cmplwi    r3, 0
  beq-      .loc_0x1D4
  bl        0x27E50
  li        r0, 0
  stw       r0, 0x14(r30)
  b         .loc_0x1D4

.loc_0x124:
  lfs       f0, 0x94(r31)
  mr        r3, r31
  stfs      f0, 0x30(r1)
  lfs       f0, 0x98(r31)
  stfs      f0, 0x34(r1)
  lfs       f0, 0x9C(r31)
  stfs      f0, 0x38(r1)
  lwz       r12, 0x0(r31)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lfs       f0, -0x6C68(r2)
  lwz       r0, 0x44(r30)
  fmuls     f30, f0, f1
  cmpwi     r0, 0x1
  bne-      .loc_0x16C
  lfs       f0, 0x2C(r30)
  b         .loc_0x178

.loc_0x16C:
  lfs       f1, -0x6C64(r2)
  lfs       f0, 0x2C(r30)
  fsubs     f0, f1, f0

.loc_0x178:
  fmr       f29, f0
  fmr       f1, f29
  bl        0x15F5CC
  fmuls     f31, f30, f1
  fmr       f1, f29
  bl        0x15F754
  fmuls     f1, f30, f1
  lfs       f0, 0x30(r1)
  lfs       f3, 0x38(r1)
  lfs       f2, 0x34(r1)
  fadds     f0, f0, f1
  lfs       f1, -0x47F8(r13)
  fadds     f3, f3, f31
  fadds     f1, f2, f1
  stfs      f0, 0x30(r1)
  stfs      f1, 0x34(r1)
  stfs      f3, 0x38(r1)
  lwz       r3, 0x30(r1)
  lwz       r0, 0x34(r1)
  stw       r3, 0x20(r30)
  stw       r0, 0x24(r30)
  lwz       r0, 0x38(r1)
  stw       r0, 0x28(r30)

.loc_0x1D4:
  lwz       r0, 0x6C(r1)
  lfd       f31, 0x60(r1)
  lfd       f30, 0x58(r1)
  lfd       f29, 0x50(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr       

.loc_0x1F8:
*/
}

/*
 * --INFO--
 * Address:	800BC600
 * Size:	000088
 */
void ActGuard::getLeft(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  li        r31, 0
  stw       r30, 0x28(r1)
  addi      r30, r4, 0
  addi      r3, r30, 0
  lwz       r12, 0x0(r30)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x6C
  lhz       r0, 0x4FC(r30)
  cmplwi    r0, 0x4
  bne-      .loc_0x6C
  lwz       r3, 0x4F8(r30)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x5C
  li        r3, 0
  b         .loc_0x68

.loc_0x5C:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0x68:
  lwz       r31, 0x18(r3)

.loc_0x6C:
  mr        r3, r31
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BC688
 * Size:	000088
 */
void ActGuard::getRight(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  li        r31, 0
  stw       r30, 0x28(r1)
  addi      r30, r4, 0
  addi      r3, r30, 0
  lwz       r12, 0x0(r30)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x6C
  lhz       r0, 0x4FC(r30)
  cmplwi    r0, 0x4
  bne-      .loc_0x6C
  lwz       r3, 0x4F8(r30)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x5C
  li        r3, 0
  b         .loc_0x68

.loc_0x5C:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0x68:
  lwz       r31, 0x1C(r3)

.loc_0x6C:
  mr        r3, r31
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BC710
 * Size:	0001C4
 */
void ActGuard::setLeft()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  stw       r30, 0x48(r1)
  mr        r30, r3
  stw       r29, 0x44(r1)
  stw       r28, 0x40(r1)
  lwz       r31, 0x14(r3)
  lwz       r12, 0x0(r31)
  mr        r3, r31
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1A0
  lhz       r0, 0x4FC(r31)
  cmplwi    r0, 0x4
  bne-      .loc_0x1A0
  lwz       r12, 0x0(r31)
  mr        r3, r31
  li        r29, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x9C
  lhz       r0, 0x4FC(r31)
  cmplwi    r0, 0x4
  bne-      .loc_0x9C
  lwz       r3, 0x4F8(r31)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x8C
  b         .loc_0x98

.loc_0x8C:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r29, r3, r0

.loc_0x98:
  lwz       r29, 0x18(r29)

.loc_0x9C:
  cmplwi    r29, 0
  lwz       r3, 0x4F8(r31)
  lwz       r29, 0xC(r30)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0xBC
  li        r3, 0
  b         .loc_0xC8

.loc_0xBC:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0xC8:
  addi      r28, r3, 0x18
  lwz       r3, 0x18(r3)
  cmplwi    r3, 0
  beq-      .loc_0xE8
  beq-      .loc_0xE8
  bl        0x27B80
  li        r0, 0
  stw       r0, 0x0(r28)

.loc_0xE8:
  stw       r29, 0x0(r28)
  lwz       r3, 0x0(r28)
  cmplwi    r3, 0
  beq-      .loc_0xFC
  bl        0x27B54

.loc_0xFC:
  lwz       r3, 0x4F8(r31)
  addi      r4, r31, 0x94
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x118
  li        r3, 0
  b         .loc_0x124

.loc_0x118:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0x124:
  lfs       f0, 0x0(r4)
  stfsu     f0, 0x30(r3)
  lfs       f0, 0x4(r4)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r4)
  stfs      f0, 0x8(r3)
  lwz       r3, 0x4F8(r31)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x154
  li        r3, 0
  b         .loc_0x160

.loc_0x154:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0x160:
  li        r0, 0x1
  stb       r0, 0x48(r3)
  lwz       r3, 0x1C(r30)
  cmplwi    r3, 0
  beq-      .loc_0x184
  beq-      .loc_0x184
  bl        0x27AE4
  li        r0, 0
  stw       r0, 0x1C(r30)

.loc_0x184:
  stw       r31, 0x1C(r30)
  lwz       r3, 0x1C(r30)
  cmplwi    r3, 0
  beq-      .loc_0x198
  bl        0x27AB8

.loc_0x198:
  li        r3, 0x1
  b         .loc_0x1A4

.loc_0x1A0:
  li        r3, 0

.loc_0x1A4:
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  lwz       r29, 0x44(r1)
  lwz       r28, 0x40(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BC8D4
 * Size:	0001C4
 */
void ActGuard::setRight()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  stw       r30, 0x48(r1)
  mr        r30, r3
  stw       r29, 0x44(r1)
  stw       r28, 0x40(r1)
  lwz       r31, 0x14(r3)
  lwz       r12, 0x0(r31)
  mr        r3, r31
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x1A0
  lhz       r0, 0x4FC(r31)
  cmplwi    r0, 0x4
  bne-      .loc_0x1A0
  lwz       r12, 0x0(r31)
  mr        r3, r31
  li        r29, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x9C
  lhz       r0, 0x4FC(r31)
  cmplwi    r0, 0x4
  bne-      .loc_0x9C
  lwz       r3, 0x4F8(r31)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x8C
  b         .loc_0x98

.loc_0x8C:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r29, r3, r0

.loc_0x98:
  lwz       r29, 0x1C(r29)

.loc_0x9C:
  cmplwi    r29, 0
  lwz       r3, 0x4F8(r31)
  lwz       r29, 0xC(r30)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0xBC
  li        r3, 0
  b         .loc_0xC8

.loc_0xBC:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0xC8:
  addi      r28, r3, 0x1C
  lwz       r3, 0x1C(r3)
  cmplwi    r3, 0
  beq-      .loc_0xE8
  beq-      .loc_0xE8
  bl        0x279BC
  li        r0, 0
  stw       r0, 0x0(r28)

.loc_0xE8:
  stw       r29, 0x0(r28)
  lwz       r3, 0x0(r28)
  cmplwi    r3, 0
  beq-      .loc_0xFC
  bl        0x27990

.loc_0xFC:
  lwz       r3, 0x4F8(r31)
  addi      r4, r31, 0x94
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x118
  li        r3, 0
  b         .loc_0x124

.loc_0x118:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0x124:
  lfs       f0, 0x0(r4)
  stfsu     f0, 0x30(r3)
  lfs       f0, 0x4(r4)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x8(r4)
  stfs      f0, 0x8(r3)
  lwz       r3, 0x4F8(r31)
  lha       r0, 0x8(r3)
  cmpwi     r0, -0x1
  bne-      .loc_0x154
  li        r3, 0
  b         .loc_0x160

.loc_0x154:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r0,3,0,28
  lwzx      r3, r3, r0

.loc_0x160:
  li        r0, 0x1
  stb       r0, 0x48(r3)
  lwz       r3, 0x18(r30)
  cmplwi    r3, 0
  beq-      .loc_0x184
  beq-      .loc_0x184
  bl        0x27920
  li        r0, 0
  stw       r0, 0x18(r30)

.loc_0x184:
  stw       r31, 0x18(r30)
  lwz       r3, 0x18(r30)
  cmplwi    r3, 0
  beq-      .loc_0x198
  bl        0x278F4

.loc_0x198:
  li        r3, 0x1
  b         .loc_0x1A4

.loc_0x1A0:
  li        r3, 0

.loc_0x1A4:
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  lwz       r29, 0x44(r1)
  lwz       r28, 0x40(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BCA98
 * Size:	000064
 */
ActGuard::~ActGuard()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  mr.       r30, r3
  beq-      .loc_0x48
  lis       r3, 0x802B
  addi      r0, r3, 0x6CD0
  stw       r0, 0x0(r30)
  addi      r3, r30, 0
  li        r4, 0
  bl        0x733C
  extsh.    r0, r31
  ble-      .loc_0x48
  mr        r3, r30
  bl        -0x75930

.loc_0x48:
  mr        r3, r30
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
