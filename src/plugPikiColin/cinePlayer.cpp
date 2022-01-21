#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void CineShapeObject::init(char*, char*, char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8006FA1C
 * Size:	0001BC
 */
void CinematicPlayer::init(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  subi      r0, r13, 0x6848
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x20(r1)
	  li        r30, 0
	  stw       r29, 0x1C(r1)
	  stw       r28, 0x18(r1)
	  stw       r30, 0x2B0(r3)
	  stw       r30, 0x7C(r3)
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0x2A4(r3)
	  lfs       f0, -0x77AC(r2)
	  stfs      f0, 0x2A0(r3)
	  stw       r30, 0x5C(r3)
	  stw       r30, 0x58(r3)
	  stw       r30, 0x54(r3)
	  stw       r0, 0x50(r3)
	  stw       r30, 0x90(r3)
	  stw       r30, 0x8C(r3)
	  stw       r30, 0x88(r3)
	  stw       r0, 0x84(r3)
	  stw       r30, 0xC4(r3)
	  stw       r30, 0xC0(r3)
	  stw       r30, 0xBC(r3)
	  stw       r0, 0xB8(r3)
	  beq-      .loc_0x104
	  mr        r3, r31
	  bl        0x41C
	  stw       r30, 0x2B0(r31)
	  lwz       r30, 0xC4(r31)
	  b         .loc_0xB0

	.loc_0x90:
	  lwz       r3, 0x18(r30)
	  lwz       r0, 0x1C(r30)
	  sub       r3, r0, r3
	  bl        0x1A61E8
	  lwz       r0, 0x2B0(r31)
	  add       r0, r0, r3
	  stw       r0, 0x2B0(r31)
	  lwz       r30, 0xC(r30)

	.loc_0xB0:
	  cmplwi    r30, 0
	  bne+      .loc_0x90
	  lwz       r3, 0x2B0(r31)
	  lis       r0, 0x4330
	  lfd       f2, -0x77A0(r2)
	  xoris     r3, r3, 0x8000
	  lfs       f1, 0x2A4(r31)
	  stw       r3, 0x14(r1)
	  stw       r0, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f0, f0, f2
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x104
	  stw       r3, 0x14(r1)
	  lfs       f0, -0x77A8(r2)
	  stw       r0, 0x10(r1)
	  lfd       f1, 0x10(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2A4(r31)

	.loc_0x104:
	  lwz       r0, 0x7C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x198
	  lis       r3, 0x803A
	  lfs       f31, -0x77B0(r2)
	  subi      r30, r3, 0x77C0
	  li        r28, 0
	  li        r29, 0
	  b         .loc_0x154

	.loc_0x128:
	  lwz       r3, 0x1C(r3)
	  addi      r0, r29, 0x28
	  fmr       f1, f31
	  mr        r4, r30
	  stfsx     f31, r3, r0
	  lwz       r3, 0x7C(r31)
	  lwz       r0, 0x1C(r3)
	  add       r3, r0, r29
	  bl        -0x451CC
	  addi      r29, r29, 0x3F8
	  addi      r28, r28, 0x1

	.loc_0x154:
	  lwz       r3, 0x7C(r31)
	  lwz       r0, 0x28(r3)
	  cmpw      r28, r0
	  blt+      .loc_0x128
	  li        r30, 0
	  mulli     r29, r30, 0x334
	  b         .loc_0x188

	.loc_0x170:
	  lwz       r0, 0x20(r3)
	  lfs       f1, -0x77B0(r2)
	  add       r3, r0, r29
	  bl        -0x44ECC
	  addi      r29, r29, 0x334
	  addi      r30, r30, 0x1

	.loc_0x188:
	  lwz       r3, 0x7C(r31)
	  lwz       r0, 0x2C(r3)
	  cmpw      r30, r0
	  blt+      .loc_0x170

	.loc_0x198:
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
 * Address:	8006FBD8
 * Size:	0001B0
 */
CinematicPlayer::CinematicPlayer(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r9, r5, 0x738C
	  lis       r7, 0x802B
	  stwu      r1, -0x20(r1)
	  lis       r6, 0x802B
	  lis       r5, 0x8023
	  stw       r31, 0x1C(r1)
	  subi      r31, r13, 0x6848
	  subi      r7, r7, 0x60D0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  subi      r6, r6, 0x6100
	  stw       r29, 0x14(r1)
	  subi      r5, r5, 0x7730
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  lis       r3, 0x8022
	  stw       r9, 0x4C(r28)
	  addi      r8, r3, 0x737C
	  lis       r3, 0x802B
	  stw       r8, 0x4C(r28)
	  subi      r0, r3, 0x6134
	  addi      r3, r28, 0xDC
	  stw       r30, 0x5C(r28)
	  stw       r30, 0x58(r28)
	  stw       r30, 0x54(r28)
	  stw       r31, 0x50(r28)
	  stw       r7, 0x4C(r28)
	  stw       r30, 0x70(r28)
	  stw       r30, 0x74(r28)
	  stw       r30, 0x78(r28)
	  stw       r9, 0x80(r28)
	  stw       r8, 0x80(r28)
	  stw       r30, 0x90(r28)
	  stw       r30, 0x8C(r28)
	  stw       r30, 0x88(r28)
	  stw       r31, 0x84(r28)
	  stw       r6, 0x80(r28)
	  stw       r5, 0xAC(r28)
	  stw       r30, 0xA0(r28)
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0xA4(r28)
	  lfs       f0, -0x77AC(r2)
	  stfs      f0, 0xA8(r28)
	  stw       r30, 0xB0(r28)
	  stw       r30, 0x9C(r28)
	  stw       r30, 0x98(r28)
	  stw       r9, 0xB4(r28)
	  stw       r8, 0xB4(r28)
	  stw       r30, 0xC4(r28)
	  stw       r30, 0xC0(r28)
	  stw       r30, 0xBC(r28)
	  stw       r31, 0xB8(r28)
	  stw       r0, 0xB4(r28)
	  bl        .loc_0x1B0
	  stw       r30, 0x27C(r28)
	  li        r5, 0x3
	  addi      r0, r28, 0x27C
	  sth       r30, 0x280(r28)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  stb       r30, 0x282(r28)
	  stb       r30, 0x283(r28)
	  stw       r30, 0x288(r28)
	  stw       r30, 0x284(r28)
	  stw       r30, 0xCC(r28)
	  stw       r30, 0xD0(r28)
	  stw       r30, 0xEC(r28)
	  stw       r30, 0xE8(r28)
	  stw       r30, 0xE4(r28)
	  stw       r31, 0xE0(r28)
	  stw       r5, 0xC8(r28)
	  stw       r30, 0xD4(r28)
	  stw       r30, 0xD8(r28)
	  stw       r0, 0x288(r28)
	  stw       r0, 0x284(r28)
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0x2C0(r28)
	  stfs      f0, 0x2BC(r28)
	  stfs      f0, 0x2B8(r28)
	  stfs      f0, 0x2CC(r28)
	  stfs      f0, 0x2C8(r28)
	  stfs      f0, 0x2C4(r28)
	  stfs      f0, 0x2D8(r28)
	  stfs      f0, 0x2D4(r28)
	  stfs      f0, 0x2D0(r28)
	  stw       r30, 0x0(r28)
	  stw       r30, 0x4(r28)
	  stw       r30, 0x48(r28)
	  stw       r30, 0x290(r28)
	  stw       r30, 0x294(r28)
	  lfs       f0, -0x7798(r2)
	  stfs      f0, 0x2AC(r28)
	  stb       r30, 0x2E4(r28)
	  bl        -0x340
	  stw       r30, 0x2B4(r28)
	  mr        r3, r28
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr

	.loc_0x1B0:
	*/
}

/*
 * --INFO--
 * Address:	8006FD88
 * Size:	000130
 */
ActorInstance::ActorInstance()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  lis       r4, 0x8022
	  addi      r0, r4, 0x738C
	  stwu      r1, -0x20(r1)
	  subi      r5, r5, 0x6164
	  lis       r4, 0x802A
	  stw       r31, 0x1C(r1)
	  li        r6, 0xC
	  li        r7, 0x9
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lis       r3, 0x8022
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x8003
	  stw       r0, 0x0(r29)
	  addi      r31, r3, 0x5B24
	  addi      r0, r4, 0x5FFC
	  stw       r30, 0x10(r29)
	  subi      r3, r13, 0x6848
	  addi      r4, r31, 0
	  stw       r30, 0xC(r29)
	  stw       r30, 0x8(r29)
	  stw       r3, 0x4(r29)
	  addi      r3, r29, 0x9C
	  stw       r5, 0x0(r29)
	  li        r5, 0
	  stw       r0, 0x44(r29)
	  stw       r30, 0x48(r29)
	  stw       r30, 0x4C(r29)
	  stw       r30, 0x50(r29)
	  stw       r30, 0x54(r29)
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0x8C(r29)
	  stfs      f0, 0x88(r29)
	  stfs      f0, 0x84(r29)
	  stfs      f0, 0x98(r29)
	  stfs      f0, 0x94(r29)
	  stfs      f0, 0x90(r29)
	  bl        0x1A4C3C
	  addi      r4, r31, 0
	  addi      r3, r29, 0x108
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x4
	  bl        0x1A4C24
	  stw       r30, 0x5C(r29)
	  li        r5, 0x1
	  li        r4, -0x1
	  stw       r30, 0x60(r29)
	  li        r0, 0x2
	  addi      r3, r29, 0
	  stw       r30, 0x64(r29)
	  stw       r30, 0x14(r29)
	  stb       r30, 0x19E(r29)
	  stb       r30, 0x19D(r29)
	  stb       r30, 0x19F(r29)
	  stb       r30, 0x19C(r29)
	  stw       r30, 0x6C(r29)
	  stw       r5, 0x70(r29)
	  stw       r4, 0x74(r29)
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0x80(r29)
	  stw       r0, 0x68(r29)
	  stw       r30, 0x78(r29)
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
 * Address:	8006FEB8
 * Size:	000720
 */
void CinematicPlayer::loadCin(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  li        r6, 0x1
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stfd      f30, 0x80(r1)
	  stmw      r17, 0x44(r1)
	  addi      r30, r3, 0
	  stw       r0, 0x7C(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r17, r3
	  beq-      .loc_0x704
	  li        r3, 0x11C
	  bl        -0x28F00
	  addi      r18, r3, 0
	  mr.       r3, r18
	  beq-      .loc_0x64
	  mr        r4, r17
	  bl        -0x2F39C

	.loc_0x64:
	  cmplwi    r18, 0
	  addi      r31, r18, 0
	  beq-      .loc_0x6B0
	  lis       r3, 0x8005
	  lfs       f30, -0x77B0(r2)
	  lis       r7, 0x8022
	  lfs       f31, -0x77AC(r2)
	  lis       r6, 0x8022
	  lis       r5, 0x802B
	  lis       r4, 0x8023
	  lis       r9, 0x802B
	  lis       r8, 0x802B
	  lis       r10, 0x802B
	  addi      r22, r3, 0x7F4
	  addi      r28, r7, 0x738C
	  addi      r26, r6, 0x737C
	  subi      r24, r5, 0x6100
	  subi      r23, r4, 0x7730
	  subi      r25, r9, 0x60D0
	  subi      r18, r8, 0x62D8
	  subi      r21, r10, 0x62E4
	  b         .loc_0x690

	.loc_0xBC:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2EECC
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6844
	  bl        -0x2EBB4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xFC
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2EEEC
	  crclr     6, 0x6
	  addi      r5, r30, 0x4
	  subi      r4, r13, 0x683C
	  bl        0x1A80E8
	  b         .loc_0x690

	.loc_0xFC:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6838
	  bl        -0x2EBE8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x130
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2EF20
	  crclr     6, 0x6
	  addi      r5, r30, 0
	  subi      r4, r13, 0x683C
	  bl        0x1A80B4
	  b         .loc_0x690

	.loc_0x130:
	  addi      r3, r31, 0
	  addi      r4, r21, 0
	  bl        -0x2EC1C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x218
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2EF54
	  b         .loc_0x1D8

	.loc_0x154:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2EF64
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6830
	  bl        -0x2EC4C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D8
	  li        r3, 0x30
	  bl        -0x2902C
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x1B8
	  stw       r28, 0x0(r19)
	  li        r3, 0
	  subi      r0, r13, 0x6848
	  stw       r26, 0x0(r19)
	  stw       r3, 0x10(r19)
	  stw       r3, 0xC(r19)
	  stw       r3, 0x8(r19)
	  stw       r0, 0x4(r19)
	  stw       r25, 0x0(r19)
	  stw       r3, 0x24(r19)
	  stw       r3, 0x28(r19)
	  stw       r3, 0x2C(r19)

	.loc_0x1B8:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2EFC8
	  bl        -0x2FD3C
	  stw       r3, 0x4(r19)
	  addi      r4, r19, 0
	  addi      r3, r30, 0x4C
	  bl        -0x2FAB4

	.loc_0x1D8:
	  mr        r3, r31
	  bl        -0x2F33C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1F8
	  mr        r3, r31
	  bl        -0x2EC1C
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x154

	.loc_0x1F8:
	  mr        r3, r31
	  bl        -0x2F35C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x690
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F018
	  b         .loc_0x690

	.loc_0x218:
	  addi      r3, r31, 0
	  addi      r4, r18, 0
	  bl        -0x2ED04
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x36C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F03C
	  li        r19, 0
	  b         .loc_0x32C

	.loc_0x240:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F050
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6828
	  bl        -0x2ED38
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2D8
	  li        r3, 0x34
	  bl        -0x29118
	  addi      r19, r3, 0
	  mr.       r0, r19
	  beq-      .loc_0x2B4
	  stw       r28, 0x0(r19)
	  li        r3, 0
	  subi      r0, r13, 0x6848
	  stw       r26, 0x0(r19)
	  stw       r3, 0x10(r19)
	  stw       r3, 0xC(r19)
	  stw       r3, 0x8(r19)
	  stw       r0, 0x4(r19)
	  stw       r24, 0x0(r19)
	  stw       r23, 0x2C(r19)
	  stw       r3, 0x20(r19)
	  stfs      f30, 0x24(r19)
	  stfs      f31, 0x28(r19)
	  stw       r3, 0x30(r19)
	  stw       r3, 0x1C(r19)
	  stw       r3, 0x18(r19)

	.loc_0x2B4:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F0C4
	  bl        -0x2FE38
	  stw       r3, 0x4(r19)
	  addi      r4, r19, 0
	  addi      r3, r30, 0x80
	  bl        -0x2FBB0
	  b         .loc_0x32C

	.loc_0x2D8:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6820
	  bl        -0x2EDC4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x304
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F0FC
	  bl        -0x2FE70
	  stw       r3, 0x1C(r19)
	  b         .loc_0x32C

	.loc_0x304:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6818
	  bl        -0x2EDF0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x32C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F128
	  bl        -0x2FE9C
	  stw       r3, 0x18(r19)

	.loc_0x32C:
	  mr        r3, r31
	  bl        -0x2F490
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x34C
	  mr        r3, r31
	  bl        -0x2ED70
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x240

	.loc_0x34C:
	  mr        r3, r31
	  bl        -0x2F4B0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x690
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F16C
	  b         .loc_0x690

	.loc_0x36C:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6810
	  bl        -0x2EE58
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x690
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F190
	  li        r29, 0
	  li        r27, 0
	  b         .loc_0x654

	.loc_0x398:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F1A8
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6808
	  bl        -0x2EE90
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x42C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F1C8
	  crclr     6, 0x6
	  addi      r5, r1, 0x3C
	  subi      r4, r13, 0x683C
	  bl        0x1A7E0C
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F1E4
	  crclr     6, 0x6
	  addi      r5, r1, 0x38
	  subi      r4, r13, 0x683C
	  bl        0x1A7DF0
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F200
	  crclr     6, 0x6
	  addi      r5, r1, 0x34
	  subi      r4, r13, 0x683C
	  bl        0x1A7DD4
	  lwz       r4, 0x3C(r1)
	  mr        r3, r30
	  lwz       r5, 0x38(r1)
	  lwz       r6, 0x34(r1)
	  bl        0x3B8
	  addi      r29, r3, 0
	  li        r27, 0
	  b         .loc_0x654

	.loc_0x42C:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6838
	  bl        -0x2EF18
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x460
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F250
	  crclr     6, 0x6
	  addi      r5, r29, 0x14
	  subi      r4, r13, 0x683C
	  bl        0x1A7D84
	  b         .loc_0x654

	.loc_0x460:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6804
	  bl        -0x2EF4C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x494
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F284
	  addi      r4, r3, 0
	  addi      r3, r29, 0
	  bl        0xD18
	  mr        r27, r3
	  b         .loc_0x654

	.loc_0x494:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x67FC
	  bl        -0x2EF80
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x4C8
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F2B8
	  crclr     6, 0x6
	  addi      r5, r27, 0x68
	  subi      r4, r13, 0x683C
	  bl        0x1A7D1C
	  b         .loc_0x654

	.loc_0x4C8:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x67F4
	  bl        -0x2EFB4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x518
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F2EC
	  crclr     6, 0x6
	  addi      r5, r27, 0x70
	  subi      r4, r13, 0x683C
	  bl        0x1A7CE8
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F308
	  crclr     6, 0x6
	  addi      r5, r27, 0x74
	  subi      r4, r13, 0x683C
	  bl        0x1A7CCC
	  b         .loc_0x654

	.loc_0x518:
	  addi      r3, r31, 0
	  subi      r4, r13, 0x67EC
	  bl        -0x2F004
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x654
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F33C
	  crclr     6, 0x6
	  addi      r5, r1, 0x30
	  subi      r4, r13, 0x683C
	  bl        0x1A7C98
	  lwz       r19, 0x30(r1)
	  rlwinm    r3,r19,4,0,27
	  addi      r3, r3, 0x8
	  bl        -0x29408
	  addi      r4, r22, 0
	  addi      r7, r19, 0
	  li        r5, 0
	  li        r6, 0x10
	  bl        0x1A4808
	  addi      r20, r3, 0
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F380
	  li        r19, 0
	  b         .loc_0x63C

	.loc_0x584:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F394
	  crclr     6, 0x6
	  addi      r5, r1, 0x28
	  subi      r4, r13, 0x683C
	  bl        0x1A7C40
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F3B0
	  crclr     6, 0x6
	  addi      r5, r1, 0x24
	  subi      r4, r13, 0x683C
	  bl        0x1A7C24
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F3CC
	  crclr     6, 0x6
	  addi      r5, r1, 0x20
	  subi      r4, r13, 0x683C
	  bl        0x1A7C08
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F3E8
	  crclr     6, 0x6
	  addi      r5, r1, 0x1C
	  subi      r4, r13, 0x683C
	  bl        0x1A7BEC
	  lwz       r0, 0x28(r1)
	  addi      r19, r19, 0x1
	  extsh     r0, r0
	  sth       r0, 0x4(r20)
	  lwz       r0, 0x24(r1)
	  stb       r0, 0x7(r20)
	  lwz       r0, 0x20(r1)
	  stb       r0, 0x6(r20)
	  lwz       r0, 0x1C(r1)
	  stw       r0, 0x0(r20)
	  lwz       r4, 0x1D0(r29)
	  lwz       r0, 0xC(r4)
	  stw       r0, 0xC(r20)
	  stw       r4, 0x8(r20)
	  lwz       r3, 0xC(r4)
	  stw       r20, 0x8(r3)
	  stw       r20, 0xC(r4)
	  addi      r20, r20, 0x10

	.loc_0x63C:
	  lwz       r0, 0x30(r1)
	  cmpw      r19, r0
	  blt+      .loc_0x584
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F458

	.loc_0x654:
	  mr        r3, r31
	  bl        -0x2F7B8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x674
	  mr        r3, r31
	  bl        -0x2F098
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x398

	.loc_0x674:
	  mr        r3, r31
	  bl        -0x2F7D8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x690
	  addi      r3, r31, 0
	  li        r4, 0x1
	  bl        -0x2F494

	.loc_0x690:
	  mr        r3, r31
	  bl        -0x2F7F4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x6B0
	  mr        r3, r31
	  bl        -0x2F0D4
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0xBC

	.loc_0x6B0:
	  mr        r3, r17
	  lwz       r12, 0x4(r17)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r17, 0x5C(r30)
	  b         .loc_0x6DC

	.loc_0x6CC:
	  addi      r3, r30, 0
	  addi      r4, r17, 0
	  bl        .loc_0x720
	  lwz       r17, 0xC(r17)

	.loc_0x6DC:
	  cmplwi    r17, 0
	  bne+      .loc_0x6CC
	  lwz       r17, 0x90(r30)
	  b         .loc_0x6FC

	.loc_0x6EC:
	  addi      r3, r30, 0
	  addi      r4, r17, 0
	  bl        0x170
	  lwz       r17, 0xC(r17)

	.loc_0x6FC:
	  cmplwi    r17, 0
	  bne+      .loc_0x6EC

	.loc_0x704:
	  lmw       r17, 0x44(r1)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lfd       f30, 0x80(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr

	.loc_0x720:
	*/
}

/*
 * --INFO--
 * Address:	800705D8
 * Size:	0000B4
 */
void CinematicPlayer::addScene(SceneData*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  li        r6, 0x1
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r4
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x4(r4)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  beq-      .loc_0x90
	  li        r3, 0x11C
	  bl        -0x29624
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x68
	  mr        r4, r30
	  bl        -0x2FAC0

	.loc_0x68:
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x7C
	  mr        r3, r29
	  bl        -0x45720

	.loc_0x7C:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x90:
	  stw       r29, 0x7C(r28)
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
 * Size:	000124
 */
void CinematicPlayer::addScene(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8007068C
 * Size:	000090
 */
void CinematicPlayer::addCut(int, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  bl        0x104
	  stw       r29, 0x20(r3)
	  li        r5, 0
	  lwz       r0, 0x20(r3)
	  lwz       r4, 0x5C(r28)
	  b         .loc_0x58

	.loc_0x44:
	  cmpw      r5, r0
	  bne-      .loc_0x50
	  b         .loc_0x64

	.loc_0x50:
	  lwz       r4, 0xC(r4)
	  addi      r5, r5, 0x1

	.loc_0x58:
	  cmplwi    r4, 0
	  bne+      .loc_0x44
	  li        r4, 0

	.loc_0x64:
	  stw       r4, 0x24(r3)
	  stw       r30, 0x18(r3)
	  stw       r31, 0x1C(r3)
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
 * Address:	8007071C
 * Size:	0000A0
 */
void CinematicPlayer::addActor(CineShapeObject*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r3, r3, 0x2848
	  li        r5, 0x1
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  mr        r28, r4
	  lwz       r4, 0x4(r4)
	  lwz       r30, 0x1C(r28)
	  lwz       r31, 0x18(r28)
	  bl        -0x1DA44
	  cmplwi    r31, 0
	  stw       r3, 0x14(r28)
	  beq-      .loc_0x80
	  li        r3, 0xB8
	  bl        -0x29764
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x74
	  lis       r6, 0x1
	  lwz       r4, 0x14(r28)
	  addi      r5, r31, 0
	  addi      r7, r30, 0
	  subi      r6, r6, 0x8000
	  bl        -0x1FEE8

	.loc_0x74:
	  stw       r29, 0x30(r28)
	  lwz       r3, 0x30(r28)
	  stw       r31, 0x4(r3)

	.loc_0x80:
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
 * Size:	000128
 */
void CinematicPlayer::addActor(char*, char*, char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800707BC
 * Size:	000138
 */
void CinematicPlayer::addSceneCut()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  li        r3, 0x1DC
	  bl        -0x297DC
	  addi      r29, r3, 0
	  mr.       r4, r29
	  beq-      .loc_0xC4
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r29)
	  li        r30, 0
	  lis       r3, 0x802B
	  stw       r30, 0x10(r29)
	  subi      r31, r13, 0x6848
	  subi      r0, r3, 0x6134
	  stw       r30, 0xC(r29)
	  addi      r3, r4, 0x28
	  stw       r30, 0x8(r29)
	  stw       r31, 0x4(r29)
	  stw       r0, 0x0(r29)
	  bl        -0xAA8
	  stw       r30, 0x1C8(r29)
	  li        r3, 0x3
	  addi      r0, r29, 0x1C8
	  sth       r30, 0x1CC(r29)
	  stb       r30, 0x1CE(r29)
	  stb       r30, 0x1CF(r29)
	  stw       r30, 0x1D4(r29)
	  stw       r30, 0x1D0(r29)
	  stw       r30, 0x18(r29)
	  stw       r30, 0x1C(r29)
	  stw       r30, 0x38(r29)
	  stw       r30, 0x34(r29)
	  stw       r30, 0x30(r29)
	  stw       r31, 0x2C(r29)
	  stw       r3, 0x14(r29)
	  stw       r30, 0x20(r29)
	  stw       r30, 0x24(r29)
	  stw       r0, 0x1D4(r29)
	  stw       r0, 0x1D0(r29)

	.loc_0xC4:
	  stw       r28, 0x1D8(r29)
	  addi      r4, r29, 0
	  li        r5, 0
	  lwz       r0, 0x20(r29)
	  lwz       r3, 0x5C(r28)
	  b         .loc_0xF0

	.loc_0xDC:
	  cmpw      r5, r0
	  bne-      .loc_0xE8
	  b         .loc_0xFC

	.loc_0xE8:
	  lwz       r3, 0xC(r3)
	  addi      r5, r5, 0x1

	.loc_0xF0:
	  cmplwi    r3, 0
	  bne+      .loc_0xDC
	  li        r3, 0

	.loc_0xFC:
	  stw       r3, 0x24(r29)
	  addi      r3, r28, 0xB4
	  lwz       r5, 0x24(r29)
	  lwz       r0, 0x24(r5)
	  stw       r0, 0x1C(r29)
	  bl        -0x302F4
	  mr        r3, r29
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
 * Address:	800708F4
 * Size:	000084
 */
void CinematicPlayer::skipScene(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r5, 0x290(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x6C
	  lwz       r3, 0x18(r5)
	  lwz       r0, 0x1C(r5)
	  sub       r3, r0, r3
	  bl        0x1A5378
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x77A0(r2)
	  stw       r0, 0x14(r1)
	  lis       r0, 0x4330
	  lfs       f0, 0x29C(r30)
	  stw       r0, 0x10(r1)
	  lfd       f1, 0x10(r1)
	  fsubs     f1, f1, f2
	  fadds     f0, f0, f1
	  stfs      f0, 0x2A4(r30)
	  lfs       f0, 0x2A4(r30)
	  stfs      f0, 0x29C(r30)
	  stw       r31, 0x2B4(r30)

	.loc_0x6C:
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
 * Address:	80070978
 * Size:	000574
 */
void CinematicPlayer::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stmw      r26, 0x50(r1)
	  mr        r28, r3
	  li        r30, 0
	  lwz       r4, 0x290(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0xD0
	  lbz       r0, 0x2E5(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0xD0
	  lwz       r0, 0x2B4(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0xD0
	  lwz       r0, 0x298(r28)
	  cmpwi     r0, 0x2
	  bne-      .loc_0xD0
	  lwz       r3, 0x18(r4)
	  lwz       r0, 0x1C(r4)
	  sub       r3, r0, r3
	  bl        0x1A52D0
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x77A0(r2)
	  stw       r0, 0x4C(r1)
	  lis       r27, 0x4330
	  lfs       f1, 0x29C(r28)
	  stw       r27, 0x48(r1)
	  lfs       f0, 0x2A4(r28)
	  lfd       f2, 0x48(r1)
	  fsubs     f2, f2, f3
	  fadds     f1, f1, f2
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xD0
	  lwz       r4, 0x290(r28)
	  lwz       r3, 0x18(r4)
	  lwz       r0, 0x1C(r4)
	  sub       r3, r0, r3
	  bl        0x1A5288
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x77A0(r2)
	  stw       r0, 0x4C(r1)
	  li        r0, 0
	  lfs       f0, 0x2A4(r28)
	  stw       r27, 0x48(r1)
	  lfd       f1, 0x48(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f1
	  stfs      f0, 0x2A4(r28)
	  stw       r0, 0x294(r28)

	.loc_0xD0:
	  lwz       r0, 0x2B4(r28)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xF8
	  lfs       f0, 0x2A4(r28)
	  lwz       r0, 0x2B0(r28)
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r3, 0x4C(r1)
	  cmpw      r3, r0
	  blt-      .loc_0x128

	.loc_0xF8:
	  lwz       r3, 0x2B0(r28)
	  lis       r0, 0x4330
	  lfd       f1, -0x77A0(r2)
	  li        r30, 0x1
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x4C(r1)
	  stw       r0, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x2A4(r28)
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0x2A0(r28)

	.loc_0x128:
	  li        r0, 0
	  stw       r0, 0x2B4(r28)
	  li        r31, 0
	  lis       r27, 0x4330
	  stw       r0, 0x2B0(r28)
	  stw       r0, 0x290(r28)
	  lwz       r29, 0xC4(r28)
	  lfd       f31, -0x77A0(r2)
	  b         .loc_0x280

	.loc_0x14C:
	  lwz       r3, 0x18(r29)
	  lwz       r0, 0x1C(r29)
	  lwz       r26, 0x2B0(r28)
	  sub       r3, r0, r3
	  bl        0x1A51CC
	  xoris     r4, r26, 0x8000
	  lwz       r0, 0x2B0(r28)
	  stw       r4, 0x4C(r1)
	  add       r0, r0, r3
	  stw       r27, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  stw       r0, 0x2B0(r28)
	  fsubs     f0, f0, f31
	  lfs       f1, 0x2A4(r28)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x27C
	  lwz       r0, 0x2B0(r28)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x4C(r1)
	  stw       r27, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f0, f0, f31
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x27C
	  stw       r29, 0x290(r28)
	  li        r31, 0x1
	  lwz       r3, 0x290(r28)
	  stw       r4, 0x4C(r1)
	  lwz       r0, 0x24(r3)
	  stw       r27, 0x48(r1)
	  stw       r0, 0x7C(r28)
	  lfd       f0, 0x48(r1)
	  lwz       r3, 0x290(r28)
	  stw       r4, 0x2C(r1)
	  fsubs     f1, f0, f31
	  lwz       r0, 0x14(r3)
	  stw       r27, 0x28(r1)
	  rlwinm    r0,r0,31,29,31
	  stw       r0, 0x298(r28)
	  lfd       f0, 0x28(r1)
	  stfs      f1, 0x29C(r28)
	  fsubs     f0, f0, f31
	  lwz       r3, 0x1C(r29)
	  lwz       r0, 0x18(r29)
	  xoris     r3, r3, 0x8000
	  lfs       f1, 0x2A4(r28)
	  xoris     r0, r0, 0x8000
	  stw       r3, 0x44(r1)
	  fsubs     f2, f1, f0
	  stw       r0, 0x3C(r1)
	  stw       r27, 0x40(r1)
	  stw       r27, 0x38(r1)
	  lfd       f1, 0x40(r1)
	  lfd       f0, 0x38(r1)
	  fsubs     f1, f1, f31
	  stw       r3, 0x24(r1)
	  fsubs     f0, f0, f31
	  stw       r0, 0x1C(r1)
	  fsubs     f0, f1, f0
	  stw       r27, 0x20(r1)
	  stw       r27, 0x18(r1)
	  fabs      f3, f0
	  lfd       f1, 0x20(r1)
	  lfd       f0, 0x18(r1)
	  stw       r0, 0x34(r1)
	  fsubs     f1, f1, f31
	  fdivs     f2, f2, f3
	  stw       r27, 0x30(r1)
	  lfd       f3, 0x30(r1)
	  fsubs     f0, f0, f31
	  fsubs     f3, f3, f31
	  fsubs     f0, f1, f0
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x2A8(r28)

	.loc_0x27C:
	  lwz       r29, 0xC(r29)

	.loc_0x280:
	  cmplwi    r29, 0
	  bne+      .loc_0x14C
	  lwz       r0, 0x290(r28)
	  lwz       r3, 0x294(r28)
	  cmplw     r0, r3
	  beq-      .loc_0x2F8
	  cmplwi    r3, 0
	  beq-      .loc_0x2BC
	  lwz       r26, 0x38(r3)
	  b         .loc_0x2B4

	.loc_0x2A8:
	  mr        r3, r26
	  bl        0x5C4
	  lwz       r26, 0xC(r26)

	.loc_0x2B4:
	  cmplwi    r26, 0
	  bne+      .loc_0x2A8

	.loc_0x2BC:
	  lwz       r0, 0x290(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x2F0
	  lfs       f0, -0x7798(r2)
	  stfs      f0, 0x2AC(r28)
	  lwz       r3, 0x290(r28)
	  lwz       r26, 0x38(r3)
	  b         .loc_0x2E8

	.loc_0x2DC:
	  mr        r3, r26
	  bl        0x654
	  lwz       r26, 0xC(r26)

	.loc_0x2E8:
	  cmplwi    r26, 0
	  bne+      .loc_0x2DC

	.loc_0x2F0:
	  lwz       r0, 0x290(r28)
	  stw       r0, 0x294(r28)

	.loc_0x2F8:
	  lfs       f1, -0x7794(r2)
	  lis       r3, 0x803A
	  lfs       f0, 0x2A8(r28)
	  subi      r27, r3, 0x2848
	  lwz       r3, 0x1DC(r27)
	  fadds     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stw       r0, 0x120(r3)
	  lwz       r3, 0x290(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x400
	  lwz       r26, 0x1D4(r3)
	  lis       r29, 0x4330
	  lfd       f31, -0x77A0(r2)
	  b         .loc_0x3E8

	.loc_0x33C:
	  lwz       r0, 0x0(r26)
	  lfs       f0, 0x2AC(r28)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x1C(r1)
	  stw       r29, 0x18(r1)
	  lfd       f1, 0x18(r1)
	  fsubs     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3E4
	  stw       r0, 0x1C(r1)
	  lfs       f0, 0x2A8(r28)
	  stw       r29, 0x18(r1)
	  lfd       f1, 0x18(r1)
	  fsubs     f1, f1, f31
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x3E4
	  lbz       r0, 0x2E5(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C0
	  lwz       r3, 0x1E8(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C0
	  lha       r0, 0x4(r26)
	  cmpwi     r0, 0
	  bne-      .loc_0x3C0
	  lwz       r12, 0x0(r3)
	  lbz       r4, 0x7(r26)
	  lwz       r12, 0x8(r12)
	  lbz       r5, 0x6(r26)
	  mtlr      r12
	  blrl
	  b         .loc_0x3E4

	.loc_0x3C0:
	  lha       r0, 0x4(r26)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x3E4
	  lwz       r3, 0x2F78(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x3E4
	  lbz       r4, 0x7(r26)
	  lbz       r5, 0x6(r26)
	  bl        0x123E8

	.loc_0x3E4:
	  lwz       r26, 0xC(r26)

	.loc_0x3E8:
	  lwz       r3, 0x290(r28)
	  addi      r0, r3, 0x1C8
	  cmplw     r26, r0
	  bne+      .loc_0x33C
	  lfs       f0, 0x2A8(r28)
	  stfs      f0, 0x2AC(r28)

	.loc_0x400:
	  rlwinm.   r0,r31,0,24,31
	  bne-      .loc_0x410
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0x2A8(r28)

	.loc_0x410:
	  lwz       r0, 0x7C(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x538
	  li        r29, 0
	  li        r31, 0
	  b         .loc_0x4F4

	.loc_0x428:
	  lfs       f0, 0x2E0(r28)
	  addi      r0, r31, 0x28
	  lwz       r4, 0x1C(r3)
	  addi      r3, r31, 0x24
	  addi      r7, r31, 0xC
	  stfsx     f0, r4, r0
	  addi      r0, r31, 0x2C
	  addi      r5, r31, 0x18
	  lwz       r6, 0x7C(r28)
	  addi      r4, r28, 0x8
	  lfs       f0, 0x2DC(r28)
	  lwz       r6, 0x1C(r6)
	  stfsx     f0, r6, r3
	  lwz       r3, 0x7C(r28)
	  lwz       r6, 0x2B8(r28)
	  lwz       r8, 0x1C(r3)
	  lwz       r3, 0x2BC(r28)
	  add       r8, r8, r31
	  stw       r6, 0x0(r8)
	  stw       r3, 0x4(r8)
	  lwz       r3, 0x2C0(r28)
	  stw       r3, 0x8(r8)
	  lwz       r3, 0x7C(r28)
	  lwz       r6, 0x2C4(r28)
	  lwz       r8, 0x1C(r3)
	  lwz       r3, 0x2C8(r28)
	  add       r7, r8, r7
	  stw       r6, 0x0(r7)
	  stw       r3, 0x4(r7)
	  lwz       r3, 0x2CC(r28)
	  stw       r3, 0x8(r7)
	  lwz       r3, 0x7C(r28)
	  lbz       r6, 0x2E4(r28)
	  lwz       r3, 0x1C(r3)
	  stbx      r6, r3, r0
	  lwz       r6, 0x7C(r28)
	  lwz       r3, 0x2D0(r28)
	  lwz       r6, 0x1C(r6)
	  lwz       r0, 0x2D4(r28)
	  add       r5, r6, r5
	  stw       r3, 0x0(r5)
	  stw       r0, 0x4(r5)
	  lwz       r0, 0x2D8(r28)
	  stw       r0, 0x8(r5)
	  lwz       r3, 0x7C(r28)
	  lfs       f1, 0x2A8(r28)
	  lwz       r0, 0x1C(r3)
	  add       r3, r0, r31
	  bl        -0x464C8
	  addi      r31, r31, 0x3F8
	  addi      r29, r29, 0x1

	.loc_0x4F4:
	  lwz       r3, 0x7C(r28)
	  lwz       r0, 0x28(r3)
	  cmpw      r29, r0
	  blt+      .loc_0x428
	  li        r29, 0
	  mulli     r27, r29, 0x334
	  b         .loc_0x528

	.loc_0x510:
	  lwz       r0, 0x20(r3)
	  lfs       f1, 0x2A8(r28)
	  add       r3, r0, r27
	  bl        -0x461C8
	  addi      r27, r27, 0x334
	  addi      r29, r29, 0x1

	.loc_0x528:
	  lwz       r3, 0x7C(r28)
	  lwz       r0, 0x2C(r3)
	  cmpw      r29, r0
	  blt+      .loc_0x510

	.loc_0x538:
	  lfs       f1, 0x2A4(r28)
	  cmpwi     r30, 0
	  lfs       f0, -0x77A8(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2A4(r28)
	  beq-      .loc_0x558
	  li        r0, 0
	  stw       r0, 0x294(r28)

	.loc_0x558:
	  mr        r3, r30
	  lmw       r26, 0x50(r1)
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80070EEC
 * Size:	0000C4
 */
void CinematicPlayer::addLights(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r26, 0x10(r1)
	  mr        r26, r3
	  addi      r27, r4, 0
	  lwz       r0, 0x7C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xB0
	  lwz       r12, 0x3B4(r27)
	  lis       r4, 0x803A
	  mr        r3, r27
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  li        r29, 0
	  addi      r30, r29, 0
	  li        r28, 0
	  subi      r31, r13, 0x6848
	  b         .loc_0xA0

	.loc_0x58:
	  lwz       r0, 0x20(r3)
	  add       r3, r0, r29
	  lwz       r0, 0x54(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x98
	  stw       r30, 0x68(r3)
	  addi      r4, r3, 0x58
	  addi      r3, r27, 0x10
	  stw       r30, 0xC(r4)
	  stw       r30, 0x8(r4)
	  stw       r31, 0x4(r4)
	  lwz       r6, 0x2DEC(r13)
	  lwz       r5, 0x1B0(r6)
	  addi      r0, r5, 0x1
	  stw       r0, 0x1B0(r6)
	  bl        -0x309A8

	.loc_0x98:
	  addi      r29, r29, 0x334
	  addi      r28, r28, 0x1

	.loc_0xA0:
	  lwz       r3, 0x7C(r26)
	  lwz       r0, 0x2C(r3)
	  cmpw      r28, r0
	  blt+      .loc_0x58

	.loc_0xB0:
	  lmw       r26, 0x10(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80070FB0
 * Size:	0000A8
 */
void CinematicPlayer::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r5, r1, 0x14
	  stw       r30, 0x60(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x5C(r1)
	  addi      r29, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r29, 0x8
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x700
	  stw       r0, 0x4(r30)
	  lwz       r3, 0x290(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  lwz       r31, 0x38(r3)
	  b         .loc_0x84

	.loc_0x58:
	  lwz       r0, 0x68(r31)
	  rlwinm.   r0,r0,0,23,23
	  bne-      .loc_0x6C
	  addi      r6, r29, 0x2A8
	  b         .loc_0x70

	.loc_0x6C:
	  li        r6, 0

	.loc_0x70:
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  addi      r4, r1, 0x14
	  bl        0x1208
	  lwz       r31, 0xC(r31)

	.loc_0x84:
	  cmplwi    r31, 0
	  bne+      .loc_0x58

	.loc_0x8C:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80071058
 * Size:	000190
 */
void SceneCut::addInstance(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  li        r3, 0x1A0
	  bl        -0x2A070
	  mr.       r31, r3
	  beq-      .loc_0x11C
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r31)
	  li        r27, 0
	  lis       r5, 0x802B
	  stw       r27, 0x10(r31)
	  lis       r4, 0x802A
	  lis       r3, 0x8003
	  stw       r27, 0xC(r31)
	  addi      r28, r3, 0x5B24
	  subi      r3, r13, 0x6848
	  stw       r27, 0x8(r31)
	  subi      r5, r5, 0x6164
	  addi      r0, r4, 0x5FFC
	  stw       r3, 0x4(r31)
	  addi      r4, r28, 0
	  addi      r3, r31, 0x9C
	  stw       r5, 0x0(r31)
	  li        r5, 0
	  li        r6, 0xC
	  stw       r0, 0x44(r31)
	  li        r7, 0x9
	  stw       r27, 0x48(r31)
	  stw       r27, 0x4C(r31)
	  stw       r27, 0x50(r31)
	  stw       r27, 0x54(r31)
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0x8C(r31)
	  stfs      f0, 0x88(r31)
	  stfs      f0, 0x84(r31)
	  stfs      f0, 0x98(r31)
	  stfs      f0, 0x94(r31)
	  stfs      f0, 0x90(r31)
	  bl        0x1A3960
	  addi      r4, r28, 0
	  addi      r3, r31, 0x108
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x4
	  bl        0x1A3948
	  stw       r27, 0x5C(r31)
	  li        r4, 0x1
	  li        r3, -0x1
	  stw       r27, 0x60(r31)
	  li        r0, 0x2
	  stw       r27, 0x64(r31)
	  stw       r27, 0x14(r31)
	  stb       r27, 0x19E(r31)
	  stb       r27, 0x19D(r31)
	  stb       r27, 0x19F(r31)
	  stb       r27, 0x19C(r31)
	  stw       r27, 0x6C(r31)
	  stw       r4, 0x70(r31)
	  stw       r3, 0x74(r31)
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0x80(r31)
	  stw       r0, 0x68(r31)
	  stw       r27, 0x78(r31)

	.loc_0x11C:
	  lwz       r0, 0x1D8(r29)
	  cmplwi    r30, 0
	  addi      r28, r31, 0
	  stw       r0, 0x7C(r31)
	  beq-      .loc_0x16C
	  lwz       r3, 0x1D8(r29)
	  lwz       r27, 0x90(r3)
	  b         .loc_0x158

	.loc_0x13C:
	  lwz       r3, 0x4(r27)
	  mr        r4, r30
	  bl        0x1A8028
	  cmpwi     r3, 0
	  bne-      .loc_0x154
	  b         .loc_0x164

	.loc_0x154:
	  lwz       r27, 0xC(r27)

	.loc_0x158:
	  cmplwi    r27, 0
	  bne+      .loc_0x13C
	  li        r27, 0

	.loc_0x164:
	  stw       r27, 0x5C(r31)
	  stw       r27, 0x60(r31)

	.loc_0x16C:
	  addi      r3, r29, 0x28
	  addi      r4, r28, 0
	  bl        -0x30BF4
	  mr        r3, r31
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SceneCut::countEKeys()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void ActorInstance::onceInit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800711E8
 * Size:	0000C4
 */
void ActorInstance::exitInstance()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  addi      r27, r3, 0
	  lwz       r0, 0x3180(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xB0
	  addi      r30, r27, 0
	  li        r29, 0
	  li        r31, 0

	.loc_0x2C:
	  lwz       r4, 0x138(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x4C
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x130398
	  stw       r31, 0x138(r30)

	.loc_0x4C:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x9
	  addi      r30, r30, 0x4
	  blt+      .loc_0x2C
	  addi      r29, r27, 0
	  li        r28, 0
	  li        r31, 0

	.loc_0x68:
	  li        r27, 0
	  addi      r30, r29, 0

	.loc_0x70:
	  lwz       r4, 0x15C(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0x90
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x130354
	  stw       r31, 0x15C(r30)

	.loc_0x90:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x4
	  addi      r30, r30, 0x4
	  blt+      .loc_0x70
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x4
	  addi      r29, r29, 0x10
	  blt+      .loc_0x68

	.loc_0xB0:
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800712AC
 * Size:	0001BC
 */
void ActorInstance::initInstance()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r3, 0x60(r3)
	  stw       r3, 0x5C(r31)
	  stw       r0, 0x158(r31)
	  stw       r0, 0x154(r31)
	  stw       r0, 0x150(r31)
	  stw       r0, 0x14C(r31)
	  stw       r0, 0x148(r31)
	  stw       r0, 0x144(r31)
	  stw       r0, 0x140(r31)
	  stw       r0, 0x13C(r31)
	  stw       r0, 0x138(r31)
	  stw       r0, 0x15C(r31)
	  stw       r0, 0x160(r31)
	  stw       r0, 0x164(r31)
	  stw       r0, 0x168(r31)
	  stw       r0, 0x16C(r31)
	  stw       r0, 0x170(r31)
	  stw       r0, 0x174(r31)
	  stw       r0, 0x178(r31)
	  stw       r0, 0x17C(r31)
	  stw       r0, 0x180(r31)
	  stw       r0, 0x184(r31)
	  stw       r0, 0x188(r31)
	  stw       r0, 0x18C(r31)
	  stw       r0, 0x190(r31)
	  stw       r0, 0x194(r31)
	  stw       r0, 0x198(r31)
	  lwz       r3, 0x68(r31)
	  rlwinm.   r0,r3,0,22,22
	  beq-      .loc_0xE4
	  rlwinm.   r0,r3,0,13,13
	  beq-      .loc_0xB4
	  lwz       r0, 0x74(r31)
	  lis       r3, 0x802B
	  subi      r3, r3, 0x62B4
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  lfs       f0, -0x4(r3)
	  stfs      f0, 0x80(r31)

	.loc_0xB4:
	  lwz       r3, 0x3180(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xE4
	  addi      r5, r31, 0x9C
	  li        r4, 0x128
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B7BC
	  stw       r3, 0x138(r31)
	  addi      r0, r31, 0x9C
	  lwz       r3, 0x138(r31)
	  stw       r0, 0x18(r3)

	.loc_0xE4:
	  lwz       r0, 0x68(r31)
	  rlwinm.   r0,r0,0,26,26
	  beq-      .loc_0x114
	  lwz       r3, 0x3120(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x114
	  bl        0xA601C
	  cmplwi    r3, 0
	  beq-      .loc_0x114
	  lwz       r3, 0x3120(r13)
	  bl        0xA600C
	  bl        0x871A8

	.loc_0x114:
	  lwz       r0, 0x78(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x158
	  li        r0, 0x1
	  lis       r3, 0x803A
	  stw       r0, 0x78(r31)
	  lis       r4, 0x802B
	  subi      r3, r3, 0x2848
	  subi      r4, r4, 0x62CC
	  li        r5, 0x1
	  bl        -0x1E6D8
	  stw       r3, 0x58(r31)
	  addi      r4, r31, 0x48
	  li        r5, 0
	  lwz       r3, 0x60(r31)
	  lwz       r3, 0x14(r3)
	  bl        -0x41AD4

	.loc_0x158:
	  lwz       r3, 0x5C(r31)
	  lwz       r4, 0x30(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x1A8
	  lwz       r0, 0x74(r31)
	  cmpwi     r0, 0
	  blt-      .loc_0x1A8
	  addi      r0, r3, 0x20
	  stw       r0, 0x18(r31)
	  li        r0, 0
	  addi      r3, r31, 0x14
	  stw       r4, 0x14(r31)
	  li        r6, 0
	  li        r7, 0x8
	  stw       r0, 0x3C(r31)
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0x40(r31)
	  lwz       r4, 0x70(r31)
	  lwz       r5, 0x74(r31)
	  bl        -0x204E0

	.loc_0x1A8:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80071468
 * Size:	000DCC
 */
void ActorInstance::checkEventKeys(float, float, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1B8(r1)
	  stfd      f31, 0x1B0(r1)
	  stfd      f30, 0x1A8(r1)
	  fmr       f30, f2
	  stfd      f29, 0x1A0(r1)
	  fmr       f29, f1
	  stmw      r15, 0x15C(r1)
	  mr        r29, r3
	  addi      r0, r29, 0x108
	  stw       r0, 0x134(r1)
	  addi      r0, r29, 0x114
	  lis       r3, 0x802B
	  stw       r0, 0x138(r1)
	  addi      r0, r29, 0x120
	  addi      r24, r29, 0x9C
	  stw       r0, 0x13C(r1)
	  addi      r0, r1, 0xF0
	  addi      r25, r29, 0x84
	  stw       r0, 0x128(r1)
	  subi      r0, r3, 0x627C
	  addi      r22, r29, 0xA8
	  stw       r0, 0x130(r1)
	  addi      r0, r29, 0x12C
	  addi      r23, r4, 0
	  stw       r0, 0x140(r1)
	  li        r0, 0
	  addi      r15, r29, 0xFC
	  stw       r0, 0x124(r1)
	  lis       r0, 0x4330
	  addi      r16, r29, 0xF0
	  stw       r0, 0x12C(r1)
	  addi      r17, r29, 0xE4
	  addi      r18, r29, 0xD8
	  addi      r19, r29, 0xCC
	  lfd       f31, -0x77A0(r2)
	  addi      r20, r29, 0xC0
	  addi      r21, r29, 0xB4
	  b         .loc_0xD98

	.loc_0xA0:
	  lwz       r3, 0x3C(r29)
	  lwz       r4, 0x124(r1)
	  bl        -0x21084
	  lwz       r0, 0x0(r3)
	  xoris     r4, r0, 0x8000
	  lwz       r0, 0x12C(r1)
	  stw       r4, 0x14C(r1)
	  stw       r0, 0x148(r1)
	  lwz       r0, 0x12C(r1)
	  lfd       f0, 0x148(r1)
	  stw       r4, 0x154(r1)
	  fsubs     f0, f0, f31
	  stw       r0, 0x150(r1)
	  fcmpo     cr0, f29, f0
	  lfd       f0, 0x150(r1)
	  fsubs     f0, f0, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0xD8C
	  fcmpo     cr0, f0, f30
	  bge-      .loc_0xD8C
	  lha       r0, 0x4(r3)
	  extsh.    r4, r0
	  beq-      .loc_0xD8C
	  cmpwi     r0, 0x1
	  bne-      .loc_0xD8C
	  lbz       r3, 0x6(r3)
	  cmplwi    r3, 0x1F
	  bgt-      .loc_0xD8C
	  lwz       r4, 0x130(r1)
	  rlwinm    r0,r3,2,0,29
	  lwzx      r0, r4, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x2F00(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x144
	  lfs       f1, 0x0(r23)
	  li        r4, 0x1
	  lfs       f2, 0x8(r23)
	  bl        -0x96A0
	  stfs      f1, 0x4(r23)

	.loc_0x144:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r23, 0
	  li        r4, 0x44
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B578
	  b         .loc_0xD8C
	  lwz       r3, 0x2F00(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x180
	  lfs       f1, 0x0(r23)
	  li        r4, 0x1
	  lfs       f2, 0x8(r23)
	  bl        -0x96DC
	  stfs      f1, 0x4(r23)

	.loc_0x180:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r23, 0
	  li        r4, 0x43
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B53C
	  b         .loc_0xD8C
	  lfs       f0, -0x67E4(r13)
	  li        r4, 0x145
	  lfs       f1, -0x67E0(r13)
	  li        r6, 0
	  stfs      f0, 0xF0(r1)
	  lfs       f0, -0x67DC(r13)
	  li        r7, 0
	  stfs      f1, 0xF4(r1)
	  lwz       r5, 0x128(r1)
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0xF8(r1)
	  bl        0x12B508
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r23, 0
	  li        r4, 0x115
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B4EC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r23, 0
	  li        r4, 0x114
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B4D4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r23, 0
	  li        r4, 0x113
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B4BC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r23, 0
	  li        r4, 0x112
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B4A4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r23, 0
	  li        r4, 0x111
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B48C
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x9C
	  li        r4, 0x10E
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B470
	  stw       r3, 0x138(r29)
	  addi      r5, r24, 0
	  li        r4, 0x10F
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r24, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B44C
	  stw       r3, 0x13C(r29)
	  addi      r5, r24, 0
	  li        r4, 0x110
	  lwz       r3, 0x13C(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r24, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B428
	  stw       r3, 0x140(r29)
	  lwz       r3, 0x140(r29)
	  stw       r24, 0x18(r3)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0xA8
	  li        r4, 0x10E
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B400
	  stw       r3, 0x144(r29)
	  addi      r5, r22, 0
	  li        r4, 0x10F
	  lwz       r3, 0x144(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r22, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B3DC
	  stw       r3, 0x148(r29)
	  addi      r5, r22, 0
	  li        r4, 0x110
	  lwz       r3, 0x148(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r22, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B3B8
	  stw       r3, 0x14C(r29)
	  lwz       r3, 0x14C(r29)
	  stw       r22, 0x18(r3)
	  b         .loc_0xD8C
	  addi      r28, r29, 0
	  li        r30, 0
	  li        r26, 0

	.loc_0x338:
	  lwz       r4, 0x138(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0x358
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x12FE0C
	  stw       r26, 0x138(r28)

	.loc_0x358:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x6
	  addi      r28, r28, 0x4
	  blt+      .loc_0x338
	  lwz       r3, 0x30AC(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xD8C
	  bl        0x8145C
	  cmplwi    r3, 0
	  beq-      .loc_0xD8C
	  lwz       r3, 0x30AC(r13)
	  bl        0x8144C
	  li        r4, 0
	  li        r5, 0
	  bl        0x7623C
	  b         .loc_0xD8C
	  lfs       f0, -0x67D8(r13)
	  addi      r5, r1, 0x118
	  lfs       f1, -0x67D4(r13)
	  li        r4, 0x116
	  stfs      f0, 0x118(r1)
	  lfs       f0, -0x67D0(r13)
	  li        r6, 0
	  stfs      f1, 0x11C(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x120(r1)
	  bl        0x12B30C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x118
	  li        r4, 0x117
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B2F4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x118
	  li        r4, 0x118
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B2DC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x118
	  li        r4, 0x119
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B2C4
	  b         .loc_0xD8C
	  lfs       f0, -0x67CC(r13)
	  addi      r5, r1, 0x10C
	  lfs       f1, -0x67C8(r13)
	  li        r4, 0xEA
	  stfs      f0, 0x10C(r1)
	  lfs       f0, -0x67C4(r13)
	  li        r6, 0
	  stfs      f1, 0x110(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x114(r1)
	  bl        0x12B290
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x10C
	  li        r4, 0xEB
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B278
	  b         .loc_0xD8C
	  li        r28, 0
	  stb       r28, 0x19D(r29)
	  addi      r26, r29, 0
	  li        r27, 0

	.loc_0x470:
	  li        r30, 0
	  addi      r31, r26, 0

	.loc_0x478:
	  lwz       r4, 0x15C(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x498
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x12FCCC
	  stw       r28, 0x15C(r31)

	.loc_0x498:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x4
	  addi      r31, r31, 0x4
	  blt+      .loc_0x478
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x4
	  addi      r26, r26, 0x10
	  blt+      .loc_0x470
	  addi      r28, r29, 0
	  li        r30, 0
	  li        r26, 0

	.loc_0x4C4:
	  lwz       r4, 0x138(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0x4E4
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x12FC80
	  stw       r26, 0x138(r28)

	.loc_0x4E4:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x7
	  addi      r28, r28, 0x4
	  blt+      .loc_0x4C4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x84
	  li        r4, 0xF8
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B1C8
	  stw       r3, 0x138(r29)
	  addi      r5, r25, 0
	  li        r4, 0xF7
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r25, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B1A4
	  stw       r3, 0x13C(r29)
	  addi      r5, r25, 0
	  li        r4, 0xF6
	  lwz       r3, 0x13C(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r25, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B180
	  stw       r3, 0x140(r29)
	  addi      r5, r25, 0
	  li        r4, 0xF5
	  lwz       r3, 0x140(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r25, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B15C
	  stw       r3, 0x144(r29)
	  addi      r5, r25, 0
	  li        r4, 0xF4
	  lwz       r3, 0x144(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r25, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B138
	  stw       r3, 0x148(r29)
	  addi      r5, r25, 0
	  li        r4, 0xF3
	  lwz       r3, 0x148(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r25, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B114
	  stw       r3, 0x14C(r29)
	  addi      r5, r25, 0
	  li        r4, 0xF2
	  lwz       r3, 0x14C(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r25, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B0F0
	  stw       r3, 0x150(r29)
	  li        r0, 0x1
	  lwz       r3, 0x150(r29)
	  stw       r25, 0x18(r3)
	  stb       r0, 0x19C(r29)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x9C
	  li        r4, 0xF9
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B0C0
	  stw       r3, 0x138(r29)
	  addi      r5, r24, 0
	  li        r4, 0xFA
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r24, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B09C
	  stw       r3, 0x138(r29)
	  addi      r5, r24, 0
	  li        r4, 0xFB
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r24, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B078
	  stw       r3, 0x138(r29)
	  lwz       r3, 0x138(r29)
	  stw       r24, 0x18(r3)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0xA8
	  li        r4, 0xFC
	  li        r6, 0
	  li        r7, 0
	  bl        0x12B050
	  stw       r3, 0x138(r29)
	  addi      r5, r22, 0
	  li        r4, 0xFD
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r22, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B02C
	  stw       r3, 0x138(r29)
	  addi      r5, r22, 0
	  li        r4, 0xFE
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r22, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12B008
	  stw       r3, 0x138(r29)
	  lwz       r3, 0x138(r29)
	  stw       r22, 0x18(r3)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0xB4
	  li        r4, 0xFF
	  li        r6, 0
	  li        r7, 0
	  bl        0x12AFE0
	  stw       r3, 0x138(r29)
	  addi      r5, r21, 0
	  li        r4, 0x100
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r21, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AFBC
	  stw       r3, 0x138(r29)
	  addi      r5, r21, 0
	  li        r4, 0x101
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r21, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AF98
	  stw       r3, 0x138(r29)
	  lwz       r3, 0x138(r29)
	  stw       r21, 0x18(r3)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0xC0
	  li        r4, 0xFC
	  li        r6, 0
	  li        r7, 0
	  bl        0x12AF70
	  stw       r3, 0x138(r29)
	  addi      r5, r20, 0
	  li        r4, 0xFD
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r20, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AF4C
	  stw       r3, 0x138(r29)
	  addi      r5, r20, 0
	  li        r4, 0xFE
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r20, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AF28
	  stw       r3, 0x138(r29)
	  lwz       r3, 0x138(r29)
	  stw       r20, 0x18(r3)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0xCC
	  li        r4, 0xFF
	  li        r6, 0
	  li        r7, 0
	  bl        0x12AF00
	  stw       r3, 0x138(r29)
	  addi      r5, r19, 0
	  li        r4, 0x100
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r19, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AEDC
	  stw       r3, 0x138(r29)
	  addi      r5, r19, 0
	  li        r4, 0x101
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r19, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AEB8
	  stw       r3, 0x138(r29)
	  lwz       r3, 0x138(r29)
	  stw       r19, 0x18(r3)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0xD8
	  li        r4, 0xFF
	  li        r6, 0
	  li        r7, 0
	  bl        0x12AE90
	  stw       r3, 0x138(r29)
	  addi      r5, r18, 0
	  li        r4, 0x100
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r18, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AE6C
	  stw       r3, 0x138(r29)
	  addi      r5, r18, 0
	  li        r4, 0x101
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r18, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AE48
	  stw       r3, 0x138(r29)
	  lwz       r3, 0x138(r29)
	  stw       r18, 0x18(r3)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0xE4
	  li        r4, 0xFC
	  li        r6, 0
	  li        r7, 0
	  bl        0x12AE20
	  stw       r3, 0x138(r29)
	  addi      r5, r17, 0
	  li        r4, 0xFD
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r17, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12ADFC
	  stw       r3, 0x138(r29)
	  addi      r5, r17, 0
	  li        r4, 0xFE
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r17, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12ADD8
	  stw       r3, 0x138(r29)
	  lwz       r3, 0x138(r29)
	  stw       r17, 0x18(r3)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0xF0
	  li        r4, 0xFF
	  li        r6, 0
	  li        r7, 0
	  bl        0x12ADB0
	  stw       r3, 0x138(r29)
	  addi      r5, r16, 0
	  li        r4, 0x100
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r16, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AD8C
	  stw       r3, 0x138(r29)
	  addi      r5, r16, 0
	  li        r4, 0x101
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r16, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AD68
	  stw       r3, 0x138(r29)
	  lwz       r3, 0x138(r29)
	  stw       r16, 0x18(r3)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0xFC
	  li        r4, 0xFF
	  li        r6, 0
	  li        r7, 0
	  bl        0x12AD40
	  stw       r3, 0x138(r29)
	  addi      r5, r15, 0
	  li        r4, 0x100
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r15, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AD1C
	  stw       r3, 0x138(r29)
	  addi      r5, r15, 0
	  li        r4, 0x101
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r15, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12ACF8
	  stw       r3, 0x138(r29)
	  lwz       r3, 0x138(r29)
	  stw       r15, 0x18(r3)
	  b         .loc_0xD8C
	  lfs       f0, -0x67C0(r13)
	  addi      r5, r29, 0x9C
	  li        r4, 0x11C
	  stfs      f0, 0x9C(r29)
	  li        r6, 0
	  li        r7, 0
	  lfs       f0, -0x67BC(r13)
	  stfs      f0, 0xA0(r29)
	  lfs       f0, -0x67B8(r13)
	  stfs      f0, 0xA4(r29)
	  lwz       r3, 0x3180(r13)
	  bl        0x12ACB8
	  stw       r3, 0x13C(r29)
	  addi      r5, r24, 0
	  li        r4, 0x11B
	  lwz       r3, 0x13C(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r24, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AC94
	  stw       r3, 0x140(r29)
	  addi      r28, r29, 0
	  li        r31, 0
	  lwz       r3, 0x140(r29)
	  stw       r24, 0x18(r3)
	  lfs       f0, -0x67B4(r13)
	  lfs       f1, -0x67B0(r13)
	  stfs      f0, 0xE4(r1)
	  lfs       f0, -0x67AC(r13)
	  stfs      f1, 0xE8(r1)
	  stfs      f0, 0xEC(r1)
	  lwz       r3, 0x140(r29)
	  lwz       r0, 0xE4(r1)
	  lwz       r4, 0xE8(r1)
	  stw       r0, 0x1DC(r3)
	  stw       r4, 0x1E0(r3)
	  lwz       r0, 0xEC(r1)
	  stw       r0, 0x1E4(r3)
	  lfs       f0, -0x67A8(r13)
	  stfs      f0, 0xA8(r29)
	  lfs       f0, -0x67A4(r13)
	  stfs      f0, 0xAC(r29)
	  lfs       f0, -0x67A0(r13)
	  stfs      f0, 0xB0(r29)
	  lfs       f0, -0x679C(r13)
	  stfs      f0, 0xB4(r29)
	  lfs       f0, -0x6798(r13)
	  stfs      f0, 0xB8(r29)
	  lfs       f0, -0x6794(r13)
	  stfs      f0, 0xBC(r29)
	  lfs       f0, -0x6790(r13)
	  stfs      f0, 0xC0(r29)
	  lfs       f0, -0x678C(r13)
	  stfs      f0, 0xC4(r29)
	  lfs       f0, -0x6788(r13)
	  stfs      f0, 0xC8(r29)
	  lfs       f0, -0x6784(r13)
	  stfs      f0, 0xCC(r29)
	  lfs       f0, -0x6780(r13)
	  stfs      f0, 0xD0(r29)
	  lfs       f0, -0x677C(r13)
	  stfs      f0, 0xD4(r29)

	.loc_0xAE8:
	  addi      r0, r31, 0x1
	  lwz       r3, 0x3180(r13)
	  mulli     r4, r0, 0xC
	  addi      r30, r4, 0x9C
	  add       r30, r29, r30
	  addi      r5, r30, 0
	  li        r4, 0x144
	  li        r6, 0
	  li        r7, 0
	  bl        0x12ABC4
	  stw       r3, 0x15C(r28)
	  addi      r5, r30, 0
	  li        r4, 0x142
	  lwz       r3, 0x15C(r28)
	  li        r6, 0
	  li        r7, 0
	  stw       r30, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12ABA0
	  stw       r3, 0x160(r28)
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x4
	  lwz       r3, 0x160(r28)
	  stw       r30, 0x18(r3)
	  lfs       f0, -0x6778(r13)
	  lfs       f1, -0x6774(r13)
	  stfs      f0, 0xD8(r1)
	  lfs       f0, -0x6770(r13)
	  stfs      f1, 0xDC(r1)
	  stfs      f0, 0xE0(r1)
	  lwz       r3, 0x160(r28)
	  addi      r28, r28, 0x10
	  lwz       r4, 0xD8(r1)
	  lwz       r0, 0xDC(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0xE0(r1)
	  stw       r0, 0x1E4(r3)
	  blt+      .loc_0xAE8
	  li        r0, 0x1
	  stb       r0, 0x19D(r29)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x84
	  li        r4, 0xE7
	  li        r6, 0
	  li        r7, 0
	  bl        0x12AB2C
	  stw       r3, 0x138(r29)
	  addi      r5, r25, 0
	  li        r4, 0xE8
	  lwz       r3, 0x138(r29)
	  li        r6, 0
	  li        r7, 0
	  stw       r25, 0x18(r3)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AB08
	  stw       r3, 0x13C(r29)
	  li        r0, 0x1
	  lwz       r3, 0x13C(r29)
	  stw       r25, 0x18(r3)
	  stb       r0, 0x19E(r29)
	  b         .loc_0xD8C
	  subi      r0, r3, 0x15
	  lwz       r3, 0x3180(r13)
	  mulli     r4, r0, 0xC
	  addi      r5, r4, 0x9C
	  add       r5, r29, r5
	  li        r4, 0x102
	  li        r6, 0
	  li        r7, 0
	  bl        0x12AACC
	  b         .loc_0xD8C
	  lfs       f0, -0x676C(r13)
	  addi      r5, r29, 0x108
	  li        r4, 0xE6
	  stfs      f0, 0x108(r29)
	  li        r6, 0
	  li        r7, 0
	  lfs       f0, -0x6768(r13)
	  stfs      f0, 0x10C(r29)
	  lfs       f0, -0x6764(r13)
	  stfs      f0, 0x110(r29)
	  lfs       f0, -0x6760(r13)
	  stfs      f0, 0x114(r29)
	  lfs       f0, -0x675C(r13)
	  stfs      f0, 0x118(r29)
	  lfs       f0, -0x6758(r13)
	  stfs      f0, 0x11C(r29)
	  lfs       f0, -0x6754(r13)
	  stfs      f0, 0x120(r29)
	  lfs       f0, -0x6750(r13)
	  stfs      f0, 0x124(r29)
	  lfs       f0, -0x674C(r13)
	  stfs      f0, 0x128(r29)
	  lfs       f0, -0x6748(r13)
	  stfs      f0, 0x12C(r29)
	  lfs       f0, -0x6744(r13)
	  stfs      f0, 0x130(r29)
	  lfs       f0, -0x6740(r13)
	  stfs      f0, 0x134(r29)
	  lwz       r3, 0x3180(r13)
	  bl        0x12AA50
	  lwz       r0, 0x134(r1)
	  addi      r5, r29, 0x114
	  li        r4, 0xE6
	  stw       r0, 0x18(r3)
	  li        r6, 0
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  bl        0x12AA30
	  lwz       r0, 0x138(r1)
	  addi      r5, r29, 0x120
	  li        r4, 0xE6
	  stw       r0, 0x18(r3)
	  li        r6, 0
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  bl        0x12AA10
	  lwz       r0, 0x13C(r1)
	  addi      r5, r29, 0x12C
	  li        r4, 0xE6
	  stw       r0, 0x18(r3)
	  li        r6, 0
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  bl        0x12A9F0
	  lwz       r0, 0x140(r1)
	  stw       r0, 0x18(r3)
	  li        r0, 0x1
	  stb       r0, 0x19F(r29)
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x84
	  li        r4, 0xE4
	  li        r6, 0
	  li        r7, 0
	  bl        0x12A9C4
	  b         .loc_0xD8C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x9C
	  li        r4, 0x115
	  li        r6, 0
	  li        r7, 0
	  bl        0x12A9A8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x9C
	  li        r4, 0x114
	  li        r6, 0
	  li        r7, 0
	  bl        0x12A990
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x9C
	  li        r4, 0x113
	  li        r6, 0
	  li        r7, 0
	  bl        0x12A978
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x9C
	  li        r4, 0x112
	  li        r6, 0
	  li        r7, 0
	  bl        0x12A960
	  lwz       r3, 0x3180(r13)
	  addi      r5, r29, 0x9C
	  li        r4, 0x111
	  li        r6, 0
	  li        r7, 0
	  bl        0x12A948

	.loc_0xD8C:
	  lwz       r3, 0x124(r1)
	  addi      r3, r3, 0x1
	  stw       r3, 0x124(r1)

	.loc_0xD98:
	  lwz       r3, 0x3C(r29)
	  bl        -0x21DD4
	  lwz       r0, 0x124(r1)
	  cmpw      r0, r3
	  blt+      .loc_0xA0
	  lmw       r15, 0x15C(r1)
	  lwz       r0, 0x1BC(r1)
	  lfd       f31, 0x1B0(r1)
	  lfd       f30, 0x1A8(r1)
	  lfd       f29, 0x1A0(r1)
	  addi      r1, r1, 0x1B8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80072234
 * Size:	000F10
 */
void ActorInstance::refresh(Matrix4f&, Graphics&, float*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x190(r1)
	  stfd      f31, 0x188(r1)
	  stfd      f30, 0x180(r1)
	  stfd      f29, 0x178(r1)
	  stfd      f28, 0x170(r1)
	  stfd      f27, 0x168(r1)
	  stmw      r23, 0x144(r1)
	  mr        r30, r3
	  addi      r24, r4, 0
	  addi      r31, r5, 0
	  lwz       r0, 0x68(r3)
	  lis       r3, 0x803A
	  subi      r28, r3, 0x2228
	  rlwinm.   r7,r0,0,16,20
	  lis       r3, 0x802B
	  subi      r29, r3, 0x6300
	  beq-      .loc_0x64
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lwz       r0, 0x128(r3)
	  and.      r0, r0, r7
	  beq-      .loc_0xEE8

	.loc_0x64:
	  lwz       r0, 0x5C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xEE8
	  lfs       f31, -0x77B0(r2)
	  li        r27, 0
	  li        r26, 0
	  stfs      f31, 0x134(r1)
	  fmr       f30, f31
	  lwz       r0, 0x14(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xD8
	  cmplwi    r6, 0
	  lfs       f31, 0x40(r30)
	  beq-      .loc_0xA8
	  lfs       f0, 0x0(r6)
	  stfs      f0, 0x40(r30)
	  b         .loc_0xC0

	.loc_0xA8:
	  addi      r3, r30, 0x14
	  lfs       f1, -0x77AC(r2)
	  lwz       r12, 0x44(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0xC0:
	  addi      r3, r30, 0x14
	  bl        -0x21138
	  lfs       f30, 0x40(r30)
	  addi      r26, r30, 0x40
	  li        r27, 0x1
	  b         .loc_0x14C

	.loc_0xD8:
	  cmplwi    r6, 0
	  beq-      .loc_0x14C
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  lwz       r3, 0x18(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x30(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x14C
	  xoris     r0, r0, 0x8000
	  lfs       f29, 0x0(r6)
	  stw       r0, 0x13C(r1)
	  lis       r0, 0x4330
	  lfd       f1, -0x77A0(r2)
	  fabs      f2, f29
	  stw       r0, 0x138(r1)
	  lfd       f0, 0x138(r1)
	  fsubs     f28, f0, f1
	  fabs      f0, f28
	  fcmpo     cr0, f0, f2
	  ble-      .loc_0x130
	  b         .loc_0x144

	.loc_0x130:
	  fdivs     f1, f29, f28
	  bl        0x1A308C
	  bl        0x1A2FD4
	  fmuls     f0, f28, f1
	  fsubs     f29, f29, f0

	.loc_0x144:
	  stfs      f29, 0x134(r1)
	  addi      r26, r1, 0x134

	.loc_0x14C:
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x68(r30)
	  li        r25, 0x1
	  andi.     r0, r3, 0x440
	  beq-      .loc_0x398
	  lwz       r3, 0x5C(r30)
	  mr        r4, r28
	  lwz       r3, 0x14(r3)
	  bl        -0x3D3C4
	  lwz       r0, 0x68(r30)
	  rlwinm.   r0,r0,0,21,21
	  bne-      .loc_0x19C
	  li        r25, 0

	.loc_0x19C:
	  lwz       r0, 0x14(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x1BC
	  lwz       r5, 0x5C(r30)
	  li        r4, 0
	  lwz       r3, 0x14(r5)
	  addi      r5, r5, 0x20
	  bl        -0x3D388

	.loc_0x1BC:
	  lwz       r3, 0x5C(r30)
	  li        r0, 0
	  addi      r4, r31, 0
	  lwz       r3, 0x14(r3)
	  addi      r5, r24, 0
	  lwzu      r23, 0x24(r3)
	  addi      r6, r26, 0
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D104
	  lwz       r3, 0x5C(r30)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x9C
	  lwz       r3, 0x14(r3)
	  li        r5, 0
	  stw       r23, 0x24(r3)
	  lfs       f0, -0x673C(r13)
	  stfs      f0, 0x9C(r30)
	  lfs       f0, -0x6738(r13)
	  stfs      f0, 0xA0(r30)
	  lfs       f0, -0x6734(r13)
	  stfs      f0, 0xA4(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3CB90
	  lfs       f0, -0x6730(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xA8
	  stfs      f0, 0xA8(r30)
	  li        r5, 0
	  lfs       f0, -0x672C(r13)
	  stfs      f0, 0xAC(r30)
	  lfs       f0, -0x6728(r13)
	  stfs      f0, 0xB0(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3CBC0
	  rlwinm.   r0,r27,0,24,31
	  beq-      .loc_0x2A0
	  lfs       f0, -0x6724(r13)
	  mr        r4, r31
	  lfs       f1, -0x6720(r13)
	  addi      r6, r1, 0x128
	  stfs      f0, 0x128(r1)
	  lfs       f0, -0x671C(r13)
	  li        r5, 0
	  stfs      f1, 0x12C(r1)
	  stfs      f0, 0x130(r1)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3CBF8
	  fmr       f1, f31
	  mr        r3, r30
	  fmr       f2, f30
	  addi      r4, r1, 0x128
	  bl        -0x1068

	.loc_0x2A0:
	  lwz       r3, 0x5C(r30)
	  li        r4, 0
	  lwz       r3, 0x14(r3)
	  bl        -0x3D4F8
	  lwz       r4, 0x0(r3)
	  lwz       r0, 0x4(r3)
	  stw       r4, 0xE8(r1)
	  stw       r0, 0xEC(r1)
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  stw       r4, 0xF0(r1)
	  stw       r0, 0xF4(r1)
	  lwz       r4, 0x10(r3)
	  lwz       r0, 0x14(r3)
	  stw       r4, 0xF8(r1)
	  stw       r0, 0xFC(r1)
	  lwz       r4, 0x18(r3)
	  lwz       r0, 0x1C(r3)
	  stw       r4, 0x100(r1)
	  stw       r0, 0x104(r1)
	  lwz       r4, 0x20(r3)
	  lwz       r0, 0x24(r3)
	  stw       r4, 0x108(r1)
	  stw       r0, 0x10C(r1)
	  lwz       r4, 0x28(r3)
	  lwz       r0, 0x2C(r3)
	  stw       r4, 0x110(r1)
	  stw       r0, 0x114(r1)
	  lwz       r4, 0x30(r3)
	  lwz       r0, 0x34(r3)
	  stw       r4, 0x118(r1)
	  stw       r0, 0x11C(r1)
	  lwz       r4, 0x38(r3)
	  lwz       r0, 0x3C(r3)
	  stw       r4, 0x120(r1)
	  stw       r0, 0x124(r1)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D53C
	  lwz       r3, 0x30AC(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x440
	  bl        0x806BC
	  cmplwi    r3, 0
	  beq-      .loc_0x440
	  lwz       r0, 0x68(r30)
	  rlwinm.   r0,r0,0,21,21
	  beq-      .loc_0x368
	  li        r0, 0
	  stw       r0, 0x4(r31)

	.loc_0x368:
	  li        r23, 0x700
	  stw       r23, 0x4(r31)
	  lwz       r3, 0x30AC(r13)
	  bl        0x80690
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  addi      r5, r1, 0xE8
	  lwz       r12, 0xFC(r12)
	  mtlr      r12
	  blrl
	  stw       r23, 0x4(r31)
	  b         .loc_0x440

	.loc_0x398:
	  rlwinm.   r0,r3,0,24,24
	  beq-      .loc_0x440
	  lwz       r3, 0x5C(r30)
	  addi      r4, r28, 0
	  li        r25, 0
	  lwz       r3, 0x14(r3)
	  bl        -0x3D5EC
	  lwz       r0, 0x14(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x3D4
	  lwz       r5, 0x5C(r30)
	  li        r4, 0
	  lwz       r3, 0x14(r5)
	  addi      r5, r5, 0x20
	  bl        -0x3D5A0

	.loc_0x3D4:
	  lwz       r3, 0x5C(r30)
	  li        r0, 0
	  addi      r4, r31, 0
	  lwz       r3, 0x14(r3)
	  addi      r5, r24, 0
	  lwzu      r23, 0x24(r3)
	  addi      r6, r26, 0
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D31C
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  stw       r23, 0x24(r3)
	  lwz       r3, 0x7C(r30)
	  lwz       r3, 0x48(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x434
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0xFC(r12)
	  mtlr      r12
	  blrl

	.loc_0x434:
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D640

	.loc_0x440:
	  rlwinm.   r0,r25,0,24,31
	  beq-      .loc_0xEE8
	  lwz       r3, 0x5C(r30)
	  mr        r4, r28
	  lwz       r3, 0x14(r3)
	  bl        -0x3D690
	  lwz       r0, 0x14(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x478
	  lwz       r5, 0x5C(r30)
	  li        r4, 0
	  lwz       r3, 0x14(r5)
	  addi      r5, r5, 0x20
	  bl        -0x3D644

	.loc_0x478:
	  lwz       r3, 0x5C(r30)
	  addi      r4, r29, 0x104
	  li        r25, 0
	  lwz       r3, 0x14(r3)
	  lwz       r3, 0x4(r3)
	  bl        0x1A6B04
	  cmpwi     r3, 0
	  bne-      .loc_0x51C
	  li        r0, 0
	  stb       r0, 0xB4(r1)
	  li        r3, 0x32
	  li        r0, 0xFF
	  stb       r3, 0xB5(r1)
	  li        r25, 0x1
	  stb       r0, 0xB6(r1)
	  stb       r0, 0xB7(r1)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  lwz       r4, 0x44(r3)
	  lwz       r0, 0x4C(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x504
	  lbz       r0, 0xB4(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x0(r3)
	  lbz       r0, 0xB5(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x2(r3)
	  lbz       r0, 0xB6(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x4(r3)
	  lbz       r0, 0xB7(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x6(r3)
	  b         .loc_0x50C

	.loc_0x504:
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0x2C(r4)

	.loc_0x50C:
	  addi      r3, r30, 0x48
	  li        r4, 0
	  bl        -0x436AC
	  b         .loc_0x688

	.loc_0x51C:
	  lwz       r3, 0x5C(r30)
	  addi      r4, r29, 0x118
	  lwz       r3, 0x14(r3)
	  lwz       r3, 0x4(r3)
	  bl        0x1A6A64
	  cmpwi     r3, 0
	  bne-      .loc_0x5BC
	  li        r4, 0xFF
	  stb       r4, 0xB0(r1)
	  li        r3, 0x1E
	  li        r0, 0
	  stb       r3, 0xB1(r1)
	  li        r25, 0x1
	  stb       r0, 0xB2(r1)
	  stb       r4, 0xB3(r1)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  lwz       r4, 0x44(r3)
	  lwz       r0, 0x4C(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x5A4
	  lbz       r0, 0xB0(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x0(r3)
	  lbz       r0, 0xB1(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x2(r3)
	  lbz       r0, 0xB2(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x4(r3)
	  lbz       r0, 0xB3(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x6(r3)
	  b         .loc_0x5AC

	.loc_0x5A4:
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x2C(r4)

	.loc_0x5AC:
	  addi      r3, r30, 0x48
	  li        r4, 0
	  bl        -0x4374C
	  b         .loc_0x688

	.loc_0x5BC:
	  lwz       r3, 0x5C(r30)
	  addi      r4, r29, 0x12C
	  lwz       r3, 0x14(r3)
	  lwz       r3, 0x4(r3)
	  bl        0x1A69C4
	  cmpwi     r3, 0
	  bne-      .loc_0x65C
	  li        r4, 0xFF
	  stb       r4, 0xAC(r1)
	  li        r3, 0xD2
	  li        r0, 0
	  stb       r3, 0xAD(r1)
	  li        r25, 0x1
	  stb       r0, 0xAE(r1)
	  stb       r4, 0xAF(r1)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  lwz       r4, 0x44(r3)
	  lwz       r0, 0x4C(r4)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x644
	  lbz       r0, 0xAC(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x0(r3)
	  lbz       r0, 0xAD(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x2(r3)
	  lbz       r0, 0xAE(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x4(r3)
	  lbz       r0, 0xAF(r1)
	  lwz       r3, 0x90(r4)
	  sth       r0, 0x6(r3)
	  b         .loc_0x64C

	.loc_0x644:
	  lwz       r0, 0xAC(r1)
	  stw       r0, 0x2C(r4)

	.loc_0x64C:
	  addi      r3, r30, 0x48
	  li        r4, 0
	  bl        -0x437EC
	  b         .loc_0x688

	.loc_0x65C:
	  lwz       r3, 0x5C(r30)
	  addi      r4, r29, 0x140
	  lwz       r3, 0x14(r3)
	  lwz       r3, 0x4(r3)
	  bl        0x1A6924
	  cmpwi     r3, 0
	  bne-      .loc_0x688
	  addi      r3, r30, 0x48
	  li        r25, 0x2
	  li        r4, 0
	  bl        -0x4381C

	.loc_0x688:
	  cmpwi     r25, 0
	  bne-      .loc_0x70C
	  lwz       r3, 0x68(r30)
	  rlwinm.   r0,r3,0,13,13
	  beq-      .loc_0x6AC
	  addi      r3, r30, 0x48
	  addi      r4, r30, 0x80
	  bl        -0x4383C
	  b         .loc_0x70C

	.loc_0x6AC:
	  rlwinm    r0,r3,31,28,31
	  cmpwi     r0, 0x1
	  beq-      .loc_0x700
	  cmpwi     r0, 0x2
	  bne-      .loc_0x6CC
	  lfs       f0, -0x77B0(r2)
	  stfs      f0, 0x80(r30)
	  b         .loc_0x6F0

	.loc_0x6CC:
	  cmpwi     r0, 0x4
	  bne-      .loc_0x6E0
	  lfs       f0, -0x7790(r2)
	  stfs      f0, 0x80(r30)
	  b         .loc_0x6F0

	.loc_0x6E0:
	  cmpwi     r0, 0x8
	  bne-      .loc_0x6F0
	  lfs       f0, -0x778C(r2)
	  stfs      f0, 0x80(r30)

	.loc_0x6F0:
	  addi      r3, r30, 0x48
	  addi      r4, r30, 0x80
	  bl        -0x43890
	  b         .loc_0x70C

	.loc_0x700:
	  addi      r3, r30, 0x48
	  li        r4, 0
	  bl        -0x438A0

	.loc_0x70C:
	  lwz       r3, 0x5C(r30)
	  li        r0, 0
	  addi      r4, r31, 0
	  lwz       r3, 0x14(r3)
	  addi      r5, r24, 0
	  lwzu      r23, 0x24(r3)
	  addi      r6, r26, 0
	  stw       r0, 0x0(r3)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D654
	  lwz       r3, 0x5C(r30)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x84
	  lwz       r3, 0x14(r3)
	  li        r5, 0
	  stw       r23, 0x24(r3)
	  lfs       f0, -0x6718(r13)
	  stfs      f0, 0x84(r30)
	  lfs       f0, -0x6714(r13)
	  stfs      f0, 0x88(r30)
	  lfs       f0, -0x6710(r13)
	  stfs      f0, 0x8C(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D0E0
	  lfs       f0, -0x670C(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x90
	  stfs      f0, 0x90(r30)
	  li        r5, 0
	  lfs       f0, -0x6708(r13)
	  stfs      f0, 0x94(r30)
	  lfs       f0, -0x6704(r13)
	  stfs      f0, 0x98(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D018
	  lbz       r0, 0x19F(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x870
	  lfs       f0, -0x6700(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x108
	  stfs      f0, 0x108(r30)
	  li        r5, 0x45
	  lfs       f0, -0x66FC(r13)
	  stfs      f0, 0x10C(r30)
	  lfs       f0, -0x66F8(r13)
	  stfs      f0, 0x110(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D14C
	  lfs       f0, -0x66F4(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x114
	  stfs      f0, 0x114(r30)
	  li        r5, 0x44
	  lfs       f0, -0x66F0(r13)
	  stfs      f0, 0x118(r30)
	  lfs       f0, -0x66EC(r13)
	  stfs      f0, 0x11C(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D17C
	  lfs       f0, -0x66E8(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x120
	  stfs      f0, 0x120(r30)
	  li        r5, 0x43
	  lfs       f0, -0x66E4(r13)
	  stfs      f0, 0x124(r30)
	  lfs       f0, -0x66E0(r13)
	  stfs      f0, 0x128(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D1AC
	  lfs       f0, -0x66DC(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x12C
	  stfs      f0, 0x12C(r30)
	  li        r5, 0x42
	  lfs       f0, -0x66D8(r13)
	  stfs      f0, 0x130(r30)
	  lfs       f0, -0x66D4(r13)
	  stfs      f0, 0x134(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D1DC

	.loc_0x870:
	  lbz       r0, 0x19D(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x9AC
	  addi      r28, r30, 0
	  li        r26, 0

	.loc_0x884:
	  lwz       r4, 0x138(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0x998
	  lbz       r0, 0x19C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x980
	  lfs       f0, -0x66D0(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x84
	  stfs      f0, 0x84(r30)
	  li        r5, 0
	  lfs       f0, -0x66CC(r13)
	  stfs      f0, 0x88(r30)
	  lfs       f0, -0x66C8(r13)
	  stfs      f0, 0x8C(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D238
	  lfs       f0, 0x90(r30)
	  cmpwi     r26, 0x3
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0xE4(r1)
	  lwz       r4, 0x138(r28)
	  lwz       r3, 0xDC(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0xE4(r1)
	  stw       r0, 0xA8(r4)
	  blt-      .loc_0x998
	  lfs       f2, 0xE4(r1)
	  addi      r3, r1, 0x84
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0xDC(r1)
	  fneg      f28, f2
	  lwz       r4, 0x138(r28)
	  fneg      f29, f1
	  fneg      f27, f0
	  addi      r4, r4, 0x138
	  bl        .loc_0xF10
	  lfs       f1, 0x84(r1)
	  lfs       f0, 0x88(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x64F44
	  fmuls     f3, f27, f1
	  lwz       r3, 0x138(r28)
	  fmuls     f2, f29, f1
	  fmuls     f0, f28, f1
	  stfs      f3, 0x138(r3)
	  stfs      f2, 0x13C(r3)
	  stfs      f0, 0x140(r3)
	  lwz       r0, 0x84(r3)
	  oris      r0, r0, 0x2
	  stw       r0, 0x84(r3)
	  b         .loc_0x998

	.loc_0x980:
	  lwz       r3, 0x90(r30)
	  lwz       r0, 0x94(r30)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0x98(r30)
	  stw       r0, 0xA8(r4)

	.loc_0x998:
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x9
	  addi      r28, r28, 0x4
	  blt+      .loc_0x884
	  b         .loc_0xAF8

	.loc_0x9AC:
	  lfs       f0, -0x66C4(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x9C
	  stfs      f0, 0x9C(r30)
	  li        r5, 0
	  lfs       f0, -0x66C0(r13)
	  stfs      f0, 0xA0(r30)
	  lfs       f0, -0x66BC(r13)
	  stfs      f0, 0xA4(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D348
	  lfs       f0, -0x66B8(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xA8
	  stfs      f0, 0xA8(r30)
	  li        r5, 0
	  lfs       f0, -0x66B4(r13)
	  stfs      f0, 0xAC(r30)
	  lfs       f0, -0x66B0(r13)
	  stfs      f0, 0xB0(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D378
	  lfs       f0, -0x66AC(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xB4
	  stfs      f0, 0xB4(r30)
	  li        r5, 0
	  lfs       f0, -0x66A8(r13)
	  stfs      f0, 0xB8(r30)
	  lfs       f0, -0x66A4(r13)
	  stfs      f0, 0xBC(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D3A8
	  lfs       f0, -0x66A0(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xC0
	  stfs      f0, 0xC0(r30)
	  li        r5, 0
	  lfs       f0, -0x669C(r13)
	  stfs      f0, 0xC4(r30)
	  lfs       f0, -0x6698(r13)
	  stfs      f0, 0xC8(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D3D8
	  lfs       f0, -0x6694(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xCC
	  stfs      f0, 0xCC(r30)
	  li        r5, 0
	  lfs       f0, -0x6690(r13)
	  stfs      f0, 0xD0(r30)
	  lfs       f0, -0x668C(r13)
	  stfs      f0, 0xD4(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D408
	  li        r0, 0x7
	  mtctr     r0
	  addi      r4, r30, 0

	.loc_0xAA8:
	  lwz       r5, 0x138(r4)
	  cmplwi    r5, 0
	  beq-      .loc_0xAF0
	  lfs       f0, 0x90(r30)
	  fneg      f0, f0
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x94(r30)
	  fneg      f0, f0
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x98(r30)
	  fneg      f0, f0
	  stfs      f0, 0x80(r1)
	  lwz       r3, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  stw       r3, 0xA0(r5)
	  stw       r0, 0xA4(r5)
	  lwz       r0, 0x80(r1)
	  stw       r0, 0xA8(r5)

	.loc_0xAF0:
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0xAA8

	.loc_0xAF8:
	  lwz       r0, 0x68(r30)
	  rlwinm.   r0,r0,0,22,22
	  beq-      .loc_0xB64
	  lfs       f0, -0x6688(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x9C
	  stfs      f0, 0x9C(r30)
	  li        r5, 0x3
	  lfs       f0, -0x6684(r13)
	  stfs      f0, 0xA0(r30)
	  lfs       f0, -0x6680(r13)
	  stfs      f0, 0xA4(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D4A0
	  lfs       f0, -0x667C(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xA8
	  stfs      f0, 0xA8(r30)
	  li        r5, 0x1
	  lfs       f0, -0x6678(r13)
	  stfs      f0, 0xAC(r30)
	  lfs       f0, -0x6674(r13)
	  stfs      f0, 0xB0(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D4D0

	.loc_0xB64:
	  lwz       r0, 0x68(r30)
	  rlwinm.   r0,r0,0,15,15
	  beq-      .loc_0xD20
	  lfs       f0, -0x6670(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0x9C
	  stfs      f0, 0x9C(r30)
	  li        r5, 0x9
	  lfs       f0, -0x666C(r13)
	  stfs      f0, 0xA0(r30)
	  lfs       f0, -0x6668(r13)
	  stfs      f0, 0xA4(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D50C
	  lfs       f0, -0x6664(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xA8
	  stfs      f0, 0xA8(r30)
	  li        r5, 0x8
	  lfs       f0, -0x6660(r13)
	  stfs      f0, 0xAC(r30)
	  lfs       f0, -0x665C(r13)
	  stfs      f0, 0xB0(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D53C
	  lfs       f0, -0x6658(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xB4
	  stfs      f0, 0xB4(r30)
	  li        r5, 0x7
	  lfs       f0, -0x6654(r13)
	  stfs      f0, 0xB8(r30)
	  lfs       f0, -0x6650(r13)
	  stfs      f0, 0xBC(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D56C
	  lfs       f0, -0x664C(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xC0
	  stfs      f0, 0xC0(r30)
	  li        r5, 0x6
	  lfs       f0, -0x6648(r13)
	  stfs      f0, 0xC4(r30)
	  lfs       f0, -0x6644(r13)
	  stfs      f0, 0xC8(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D59C
	  lfs       f0, -0x6640(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xCC
	  stfs      f0, 0xCC(r30)
	  li        r5, 0x5
	  lfs       f0, -0x663C(r13)
	  stfs      f0, 0xD0(r30)
	  lfs       f0, -0x6638(r13)
	  stfs      f0, 0xD4(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D5CC
	  lfs       f0, -0x6634(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xD8
	  stfs      f0, 0xD8(r30)
	  li        r5, 0x4
	  lfs       f0, -0x6630(r13)
	  stfs      f0, 0xDC(r30)
	  lfs       f0, -0x662C(r13)
	  stfs      f0, 0xE0(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D5FC
	  lfs       f0, -0x6628(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xE4
	  stfs      f0, 0xE4(r30)
	  li        r5, 0x3
	  lfs       f0, -0x6624(r13)
	  stfs      f0, 0xE8(r30)
	  lfs       f0, -0x6620(r13)
	  stfs      f0, 0xEC(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D62C
	  lfs       f0, -0x661C(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xF0
	  stfs      f0, 0xF0(r30)
	  li        r5, 0x2
	  lfs       f0, -0x6618(r13)
	  stfs      f0, 0xF4(r30)
	  lfs       f0, -0x6614(r13)
	  stfs      f0, 0xF8(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D65C
	  lfs       f0, -0x6610(r13)
	  addi      r4, r31, 0
	  addi      r6, r30, 0xFC
	  stfs      f0, 0xFC(r30)
	  li        r5, 0x1
	  lfs       f0, -0x660C(r13)
	  stfs      f0, 0x100(r30)
	  lfs       f0, -0x6608(r13)
	  stfs      f0, 0x104(r30)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D68C

	.loc_0xD20:
	  rlwinm.   r0,r27,0,24,31
	  beq-      .loc_0xD6C
	  lfs       f0, -0x6604(r13)
	  mr        r4, r31
	  lfs       f1, -0x6600(r13)
	  addi      r6, r1, 0xC4
	  stfs      f0, 0xC4(r1)
	  lfs       f0, -0x65FC(r13)
	  li        r5, 0
	  stfs      f1, 0xC8(r1)
	  stfs      f0, 0xCC(r1)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3D6C4
	  fmr       f1, f31
	  mr        r3, r30
	  fmr       f2, f30
	  addi      r4, r1, 0xC4
	  bl        -0x1B34

	.loc_0xD6C:
	  lwz       r4, 0x68(r30)
	  andi.     r0, r4, 0x21
	  beq-      .loc_0xE08
	  lwz       r3, 0x3120(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xE48
	  bl        0xA440C
	  cmplwi    r3, 0
	  beq-      .loc_0xE48
	  lfs       f0, -0x65F8(r13)
	  li        r4, 0
	  lfs       f1, -0x65F4(r13)
	  stfs      f0, 0xB8(r1)
	  lfs       f0, -0x65F0(r13)
	  stfs      f1, 0xBC(r1)
	  stfs      f0, 0xC0(r1)
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3E000
	  addi      r4, r3, 0
	  addi      r3, r1, 0xB8
	  bl        -0x3B8A8
	  lwz       r4, 0x2E4(r31)
	  addi      r3, r1, 0xB8
	  addi      r4, r4, 0x220
	  bl        -0x3B8B8
	  lwz       r3, 0x3120(r13)
	  bl        0xA43B8
	  addi      r4, r1, 0xB8
	  bl        0x8555C
	  lwz       r3, 0x3120(r13)
	  bl        0xA43A8
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0xFC(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE48

	.loc_0xE08:
	  lwz       r3, 0x5C(r30)
	  rlwinm.   r0,r4,0,14,14
	  lwz       r3, 0x14(r3)
	  lwzu      r23, 0x14(r3)
	  beq-      .loc_0xE24
	  ori       r0, r23, 0x4
	  stw       r0, 0x0(r3)

	.loc_0xE24:
	  lwz       r3, 0x5C(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  addi      r6, r30, 0x48
	  lwz       r3, 0x14(r3)
	  bl        -0x42C00
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  stw       r23, 0x14(r3)

	.loc_0xE48:
	  cmpwi     r25, 0x1
	  bne-      .loc_0xE94
	  lwz       r3, 0x5C(r30)
	  li        r4, 0x6
	  lwz       r3, 0x14(r3)
	  bl        -0x3E0A8
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x58(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  bl        -0x42C54
	  b         .loc_0xEDC

	.loc_0xE94:
	  cmpwi     r25, 0x2
	  bne-      .loc_0xEDC
	  lwz       r3, 0x5C(r30)
	  li        r4, 0x3
	  lwz       r3, 0x14(r3)
	  bl        -0x3E0F4
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x58(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  bl        -0x42CA0

	.loc_0xEDC:
	  lwz       r3, 0x5C(r30)
	  lwz       r3, 0x14(r3)
	  bl        -0x3E0E8

	.loc_0xEE8:
	  lmw       r23, 0x144(r1)
	  lwz       r0, 0x194(r1)
	  lfd       f31, 0x188(r1)
	  lfd       f30, 0x180(r1)
	  lfd       f29, 0x178(r1)
	  lfd       f28, 0x170(r1)
	  lfd       f27, 0x168(r1)
	  addi      r1, r1, 0x190
	  mtlr      r0
	  blr

	.loc_0xF10:
	*/
}

/*
 * --INFO--
 * Address:	80073144
 * Size:	00001C
 */
Vector3f::Vector3f(const Vector3f&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x0(r3)
	  lfs       f0, 0x4(r4)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r4)
	  stfs      f0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80073160
 * Size:	000004
 */
void Creature::demoDraw(Graphics&, Matrix4f*) { }
