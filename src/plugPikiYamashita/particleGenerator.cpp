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
 * Address:	8019CD0C
 * Size:	00024C
 */
void zen::particleGenerator::init(u8*, Texture*, Texture*, Vector3f&, zen::particleMdlManager*,
                                  zen::CallBack1<zen::particleGenerator*>*, zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stmw      r25, 0x54(r1)
	  mr.       r26, r4
	  lis       r4, 0x802E
	  addi      r25, r3, 0
	  addi      r27, r7, 0
	  addi      r28, r8, 0
	  addi      r29, r9, 0
	  addi      r30, r10, 0
	  subi      r31, r4, 0x59E0
	  beq-      .loc_0x238
	  addi      r3, r25, 0
	  addi      r4, r5, 0
	  addi      r5, r6, 0
	  bl        0x2FC4
	  li        r0, 0x14
	  stw       r0, 0x80(r25)
	  lbz       r0, 0x6(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  addi      r3, r25, 0x48
	  addi      r4, r26, 0x8
	  bl        0x50A4
	  lwz       r3, 0x70(r31)
	  lwz       r0, 0x74(r31)
	  stw       r3, 0x1E8(r25)
	  stw       r0, 0x1EC(r25)
	  lwz       r0, 0x78(r31)
	  stw       r0, 0x1F0(r25)
	  b         .loc_0x1E4

	.loc_0x80:
	  lwz       r0, 0x8(r26)
	  addi      r3, r25, 0x48
	  addi      r4, r26, 0x10
	  stw       r0, 0x44(r1)
	  lfs       f0, 0x44(r1)
	  stfs      f0, 0x60(r25)
	  lwz       r0, 0xC(r26)
	  stw       r0, 0x3C(r1)
	  lfs       f0, 0x3C(r1)
	  stfs      f0, 0x64(r25)
	  bl        0x505C
	  lbz       r4, 0x4A(r25)
	  li        r3, 0
	  lbz       r0, 0x68(r25)
	  rlwimi    r0,r4,5,24,24
	  stb       r0, 0x68(r25)
	  rlwinm    r5,r4,28,29,31
	  cmplwi    r5, 0x6
	  lbz       r4, 0x4A(r25)
	  lbz       r0, 0x68(r25)
	  rlwimi    r0,r4,5,25,25
	  stb       r0, 0x68(r25)
	  lbz       r0, 0x68(r25)
	  rlwimi    r0,r3,5,26,26
	  stb       r0, 0x68(r25)
	  lbz       r0, 0x4A(r25)
	  rlwinm    r0,r0,0,31,31
	  stb       r0, 0x4A(r25)
	  lwz       r3, 0x7C(r31)
	  lwz       r0, 0x80(r31)
	  stw       r3, 0x1E8(r25)
	  stw       r0, 0x1EC(r25)
	  lwz       r0, 0x84(r31)
	  stw       r0, 0x1F0(r25)
	  bgt-      .loc_0x1E4
	  lis       r3, 0x802E
	  subi      r3, r3, 0x5904
	  rlwinm    r0,r5,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x88(r31)
	  lwz       r0, 0x8C(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0x90(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0xA0(r31)
	  lwz       r0, 0xA4(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0xA8(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0xAC(r31)
	  lwz       r0, 0xB0(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0xB4(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0xB8(r31)
	  lwz       r0, 0xBC(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0xC0(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0xC4(r31)
	  lwz       r0, 0xC8(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0xCC(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0xD0(r31)
	  lwz       r0, 0xD4(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0xD8(r31)
	  stw       r0, 0x1FC(r25)

	.loc_0x1E4:
	  lhz       r0, 0x4(r26)
	  addi      r3, r25, 0
	  add       r4, r26, r0
	  bl        0x328
	  stw       r28, 0x1D0(r25)
	  cmplwi    r29, 0
	  lwz       r3, 0x0(r27)
	  lwz       r0, 0x4(r27)
	  stw       r3, 0xC(r25)
	  stw       r0, 0x10(r25)
	  lwz       r0, 0x8(r27)
	  stw       r0, 0x14(r25)
	  stw       r29, 0x1D4(r25)
	  beq-      .loc_0x234
	  lwz       r3, 0x1D4(r25)
	  mr        r4, r25
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x234:
	  stw       r30, 0x1D8(r25)

	.loc_0x238:
	  lmw       r25, 0x54(r1)
	  lwz       r0, 0x74(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019CF58
 * Size:	000154
 */
void zen::particleGenerator::update(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  fmr       f31, f1
	  stw       r31, 0x2C(r1)
	  li        r31, 0
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lwz       r3, 0x80(r3)
	  rlwinm.   r0,r3,0,31,31
	  bne-      .loc_0x134
	  rlwinm.   r0,r3,0,30,30
	  bne-      .loc_0x4C
	  rlwinm.   r0,r3,0,28,28
	  bne-      .loc_0x7C
	  mr        r3, r30
	  bl        0xDE0
	  b         .loc_0x7C

	.loc_0x4C:
	  lwz       r4, 0x28(r30)
	  lwz       r0, 0x8(r4)
	  cmplw     r4, r0
	  bne-      .loc_0x7C
	  lwz       r4, 0x38(r30)
	  lwz       r0, 0x8(r4)
	  cmplw     r4, r0
	  bne-      .loc_0x7C
	  xoris     r0, r3, 0xFFFF
	  xori      r0, r0, 0xFFFB
	  stw       r0, 0x80(r30)
	  li        r31, 0x1

	.loc_0x7C:
	  mr        r3, r30
	  fmr       f1, f31
	  bl        0x26EC
	  lwz       r0, 0x80(r30)
	  rlwinm.   r0,r0,0,28,28
	  bne-      .loc_0xA0
	  lfs       f0, 0x8C(r30)
	  fadds     f0, f0, f31
	  stfs      f0, 0x8C(r30)

	.loc_0xA0:
	  lfs       f0, 0x8C(r30)
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  sth       r0, 0x90(r30)
	  lha       r3, 0x90(r30)
	  lha       r0, 0x1C8(r30)
	  cmpw      r3, r0
	  blt-      .loc_0x108
	  lfs       f0, -0x4C70(r2)
	  li        r0, 0
	  stfs      f0, 0x8C(r30)
	  sth       r0, 0x90(r30)
	  lbz       r3, 0x92(r30)
	  addi      r0, r3, 0x1
	  stb       r0, 0x92(r30)
	  rlwinm    r3,r0,0,24,31
	  lbz       r0, 0x1CA(r30)
	  cmplw     r3, r0
	  blt-      .loc_0x108
	  cmplwi    r0, 0
	  beq-      .loc_0x108
	  stb       r0, 0x92(r30)
	  lwz       r0, 0x80(r30)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r30)

	.loc_0x108:
	  lwz       r0, 0x80(r30)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x134
	  lwz       r3, 0x1D4(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x134
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x134:
	  mr        r3, r31
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019D0AC
 * Size:	000178
 */
void zen::particleGenerator::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r0, 0x80(r3)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x158
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x3B4(r29)
	  mr        r31, r0
	  li        r4, 0x1
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x3B4(r29)
	  mr        r30, r0
	  li        r4, 0
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x5C(r28)
	  cmplwi    r4, 0
	  beq-      .loc_0xB4
	  lwz       r12, 0x3B4(r29)
	  mr        r3, r29
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xD0

	.loc_0xB4:
	  mr        r3, r29
	  lwz       r4, 0x58(r28)
	  lwz       r12, 0x3B4(r29)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl

	.loc_0xD0:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        0x3930
	  mr        r3, r29
	  lwz       r4, 0x58(r28)
	  lwz       r12, 0x3B4(r29)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  addi      r12, r28, 0x1E8
	  bl        0x77B80
	  nop
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  li        r4, 0x1
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  mr        r4, r30
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x158:
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
 * Address:	8019D224
 * Size:	000B58
 */
void zen::particleGenerator::pmSetDDF(u8*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x510(r1)
	  stfd      f31, 0x508(r1)
	  stfd      f30, 0x500(r1)
	  stfd      f29, 0x4F8(r1)
	  stfd      f28, 0x4F0(r1)
	  stfd      f27, 0x4E8(r1)
	  stw       r31, 0x4E4(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x4E0(r1)
	  beq-      .loc_0xB2C
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x84(r31)
	  lwz       r0, 0xC(r4)
	  stw       r0, 0x324(r1)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x31C(r1)
	  lwz       r0, 0x4(r4)
	  stw       r0, 0x314(r1)
	  lfs       f0, 0x314(r1)
	  stfs      f0, 0x94(r31)
	  lfs       f0, 0x31C(r1)
	  stfs      f0, 0x98(r31)
	  lfs       f0, 0x324(r1)
	  stfs      f0, 0x9C(r31)
	  lwz       r0, 0x18(r4)
	  stw       r0, 0x30C(r1)
	  lwz       r0, 0x14(r4)
	  stw       r0, 0x304(r1)
	  lwz       r0, 0x10(r4)
	  stw       r0, 0x2FC(r1)
	  lfs       f0, 0x2FC(r1)
	  stfs      f0, 0xA0(r31)
	  lfs       f0, 0x304(r1)
	  stfs      f0, 0xA4(r31)
	  lfs       f0, 0x30C(r1)
	  stfs      f0, 0xA8(r31)
	  lwz       r0, 0x24(r4)
	  stw       r0, 0x2F4(r1)
	  lwz       r0, 0x20(r4)
	  stw       r0, 0x2EC(r1)
	  lwz       r0, 0x1C(r4)
	  stw       r0, 0x2E4(r1)
	  lfs       f0, 0x2E4(r1)
	  stfs      f0, 0xAC(r31)
	  lfs       f0, 0x2EC(r1)
	  stfs      f0, 0xB0(r31)
	  lfs       f0, 0x2F4(r1)
	  stfs      f0, 0xB4(r31)
	  lwz       r0, 0x28(r4)
	  stw       r0, 0x424(r1)
	  lfs       f0, 0x424(r1)
	  stfs      f0, 0xC0(r31)
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,24,25
	  beq-      .loc_0x1A8
	  lbz       r0, 0x2C(r4)
	  addi      r3, r4, 0x30
	  li        r4, 0
	  stb       r0, 0x1C4(r31)
	  lbz       r5, 0x1C4(r31)
	  cmplwi    r5, 0
	  stw       r3, 0x1AC(r31)
	  ble-      .loc_0x14C
	  cmplwi    r5, 0x8
	  subi      r6, r5, 0x8
	  ble-      .loc_0x134
	  addi      r0, r6, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmplwi    r6, 0
	  mtctr     r0
	  ble-      .loc_0x134

	.loc_0x128:
	  addi      r3, r3, 0x20
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x128

	.loc_0x134:
	  sub       r0, r5, r4
	  cmplw     r4, r5
	  mtctr     r0
	  bge-      .loc_0x14C

	.loc_0x144:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x144

	.loc_0x14C:
	  lbz       r5, 0x1C4(r31)
	  li        r4, 0
	  cmplwi    r5, 0
	  stw       r3, 0x1B0(r31)
	  ble-      .loc_0x1BC
	  cmplwi    r5, 0x8
	  subi      r6, r5, 0x8
	  ble-      .loc_0x18C
	  addi      r0, r6, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmplwi    r6, 0
	  mtctr     r0
	  ble-      .loc_0x18C

	.loc_0x180:
	  addi      r3, r3, 0x20
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x180

	.loc_0x18C:
	  sub       r0, r5, r4
	  cmplw     r4, r5
	  mtctr     r0
	  bge-      .loc_0x1BC

	.loc_0x19C:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x19C
	  b         .loc_0x1BC

	.loc_0x1A8:
	  lwz       r0, 0x2C(r4)
	  addi      r3, r4, 0x30
	  stw       r0, 0x41C(r1)
	  lfs       f0, 0x41C(r1)
	  stfs      f0, 0xB8(r31)

	.loc_0x1BC:
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x414(r1)
	  lfs       f0, 0x414(r1)
	  stfs      f0, 0xBC(r31)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x40C(r1)
	  lfs       f0, 0x40C(r1)
	  stfs      f0, 0xC4(r31)
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,22,23
	  beq-      .loc_0x2A8
	  lbz       r0, 0x8(r3)
	  addi      r3, r3, 0xC
	  li        r4, 0
	  stb       r0, 0x1C5(r31)
	  lbz       r5, 0x1C5(r31)
	  cmplwi    r5, 0
	  stw       r3, 0x1B4(r31)
	  ble-      .loc_0x24C
	  cmplwi    r5, 0x8
	  subi      r6, r5, 0x8
	  ble-      .loc_0x234
	  addi      r0, r6, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmplwi    r6, 0
	  mtctr     r0
	  ble-      .loc_0x234

	.loc_0x228:
	  addi      r3, r3, 0x20
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x228

	.loc_0x234:
	  sub       r0, r5, r4
	  cmplw     r4, r5
	  mtctr     r0
	  bge-      .loc_0x24C

	.loc_0x244:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x244

	.loc_0x24C:
	  lbz       r5, 0x1C5(r31)
	  li        r4, 0
	  cmplwi    r5, 0
	  stw       r3, 0x1B8(r31)
	  ble-      .loc_0x2BC
	  cmplwi    r5, 0x8
	  subi      r6, r5, 0x8
	  ble-      .loc_0x28C
	  addi      r0, r6, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmplwi    r6, 0
	  mtctr     r0
	  ble-      .loc_0x28C

	.loc_0x280:
	  addi      r3, r3, 0x20
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x280

	.loc_0x28C:
	  sub       r0, r5, r4
	  cmplw     r4, r5
	  mtctr     r0
	  bge-      .loc_0x2BC

	.loc_0x29C:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x29C
	  b         .loc_0x2BC

	.loc_0x2A8:
	  lwz       r0, 0x8(r3)
	  addi      r3, r3, 0xC
	  stw       r0, 0x404(r1)
	  lfs       f0, 0x404(r1)
	  stfs      f0, 0xC8(r31)

	.loc_0x2BC:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,20,21
	  beq-      .loc_0x388
	  lbz       r0, 0x0(r3)
	  addi      r3, r3, 0x4
	  li        r4, 0
	  stb       r0, 0x1C6(r31)
	  lbz       r5, 0x1C6(r31)
	  cmplwi    r5, 0
	  stw       r3, 0x1BC(r31)
	  ble-      .loc_0x32C
	  cmplwi    r5, 0x8
	  subi      r6, r5, 0x8
	  ble-      .loc_0x314
	  addi      r0, r6, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmplwi    r6, 0
	  mtctr     r0
	  ble-      .loc_0x314

	.loc_0x308:
	  addi      r3, r3, 0x20
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x308

	.loc_0x314:
	  sub       r0, r5, r4
	  cmplw     r4, r5
	  mtctr     r0
	  bge-      .loc_0x32C

	.loc_0x324:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x324

	.loc_0x32C:
	  lbz       r5, 0x1C6(r31)
	  li        r4, 0
	  cmplwi    r5, 0
	  stw       r3, 0x1C0(r31)
	  ble-      .loc_0x39C
	  cmplwi    r5, 0x8
	  subi      r6, r5, 0x8
	  ble-      .loc_0x36C
	  addi      r0, r6, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmplwi    r6, 0
	  mtctr     r0
	  ble-      .loc_0x36C

	.loc_0x360:
	  addi      r3, r3, 0x20
	  addi      r4, r4, 0x8
	  bdnz+     .loc_0x360

	.loc_0x36C:
	  sub       r0, r5, r4
	  cmplw     r4, r5
	  mtctr     r0
	  bge-      .loc_0x39C

	.loc_0x37C:
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x37C
	  b         .loc_0x39C

	.loc_0x388:
	  lwz       r0, 0x0(r3)
	  addi      r3, r3, 0x4
	  stw       r0, 0x3FC(r1)
	  lfs       f0, 0x3FC(r1)
	  stfs      f0, 0xCC(r31)

	.loc_0x39C:
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x3F4(r1)
	  lfs       f0, 0x3F4(r1)
	  stfs      f0, 0xD0(r31)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x3EC(r1)
	  lfs       f0, 0x3EC(r1)
	  stfs      f0, 0xD4(r31)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x3E4(r1)
	  lfs       f0, 0x3E4(r1)
	  stfs      f0, 0xD8(r31)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x3DC(r1)
	  lfs       f0, 0x3DC(r1)
	  stfs      f0, 0xDC(r31)
	  lwz       r0, 0x10(r3)
	  stw       r0, 0x3D4(r1)
	  lfs       f0, 0x3D4(r1)
	  stfs      f0, 0xE0(r31)
	  lwz       r0, 0x14(r3)
	  stw       r0, 0x3CC(r1)
	  lfs       f0, 0x3CC(r1)
	  stfs      f0, 0xE4(r31)
	  lwz       r0, 0x18(r3)
	  stw       r0, 0x3C4(r1)
	  lfs       f0, 0x3C4(r1)
	  stfs      f0, 0xE8(r31)
	  lwz       r0, 0x1C(r3)
	  stw       r0, 0x3BC(r1)
	  lfs       f0, 0x3BC(r1)
	  stfs      f0, 0xEC(r31)
	  lwz       r0, 0x20(r3)
	  stw       r0, 0x3B4(r1)
	  lfs       f0, 0x3B4(r1)
	  stfs      f0, 0xF0(r31)
	  lwz       r0, 0x24(r3)
	  stw       r0, 0x3AC(r1)
	  lfs       f0, 0x3AC(r1)
	  stfs      f0, 0xF4(r31)
	  lwz       r0, 0x28(r3)
	  stw       r0, 0x3A4(r1)
	  lfs       f0, 0x3A4(r1)
	  stfs      f0, 0xF8(r31)
	  lwz       r0, 0x2C(r3)
	  stw       r0, 0x39C(r1)
	  lfs       f0, 0x39C(r1)
	  stfs      f0, 0xFC(r31)
	  lwz       r0, 0x30(r3)
	  stw       r0, 0x394(r1)
	  lfs       f0, 0x394(r1)
	  stfs      f0, 0x100(r31)
	  lwz       r0, 0x34(r3)
	  stw       r0, 0x38C(r1)
	  lfs       f0, 0x38C(r1)
	  stfs      f0, 0x10C(r31)
	  lha       r0, 0x38(r3)
	  sth       r0, 0x104(r31)
	  lha       r0, 0x3A(r3)
	  sth       r0, 0x106(r31)
	  lha       r0, 0x3C(r3)
	  sth       r0, 0x108(r31)
	  lha       r0, 0x3E(r3)
	  sth       r0, 0x110(r31)
	  lha       r0, 0x40(r3)
	  sth       r0, 0x1C8(r31)
	  lbz       r0, 0x42(r3)
	  stb       r0, 0x1A8(r31)
	  lbz       r0, 0x43(r3)
	  stb       r0, 0x112(r31)
	  lbz       r0, 0x44(r3)
	  stb       r0, 0x1CA(r31)
	  lbz       r0, 0x45(r3)
	  stb       r0, 0x1CB(r31)
	  lbz       r0, 0x46(r3)
	  addi      r3, r3, 0x48
	  stb       r0, 0x1CC(r31)
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,15,15
	  beq-      .loc_0x510
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x2DC(r1)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x2D4(r1)
	  lwz       r0, 0x0(r3)
	  addi      r3, r3, 0xC
	  stw       r0, 0x2CC(r1)
	  lfs       f0, 0x2CC(r1)
	  stfs      f0, 0x12C(r31)
	  lfs       f0, 0x2D4(r1)
	  stfs      f0, 0x130(r31)
	  lfs       f0, 0x2DC(r1)
	  stfs      f0, 0x134(r31)

	.loc_0x510:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,14,14
	  beq-      .loc_0x550
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x2C4(r1)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x2BC(r1)
	  lwz       r0, 0x0(r3)
	  addi      r3, r3, 0xC
	  stw       r0, 0x2B4(r1)
	  lfs       f0, 0x2B4(r1)
	  stfs      f0, 0x138(r31)
	  lfs       f0, 0x2BC(r1)
	  stfs      f0, 0x13C(r31)
	  lfs       f0, 0x2C4(r1)
	  stfs      f0, 0x140(r31)

	.loc_0x550:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,13,13
	  beq-      .loc_0x5D0
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x2AC(r1)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x2A4(r1)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x29C(r1)
	  lfs       f0, 0x29C(r1)
	  stfs      f0, 0x144(r31)
	  lfs       f0, 0x2A4(r1)
	  stfs      f0, 0x148(r31)
	  lfs       f0, 0x2AC(r1)
	  stfs      f0, 0x14C(r31)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x384(r1)
	  lfs       f0, 0x384(r1)
	  stfs      f0, 0x150(r31)
	  lwz       r0, 0x10(r3)
	  stw       r0, 0x37C(r1)
	  lfs       f0, 0x37C(r1)
	  stfs      f0, 0x154(r31)
	  lwz       r0, 0x14(r3)
	  stw       r0, 0x374(r1)
	  lfs       f0, 0x374(r1)
	  stfs      f0, 0x158(r31)
	  lwz       r0, 0x18(r3)
	  addi      r3, r3, 0x1C
	  stw       r0, 0x36C(r1)
	  lfs       f0, 0x36C(r1)
	  stfs      f0, 0x15C(r31)

	.loc_0x5D0:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x620
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x294(r1)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x28C(r1)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x284(r1)
	  lfs       f0, 0x284(r1)
	  stfs      f0, 0x160(r31)
	  lfs       f0, 0x28C(r1)
	  stfs      f0, 0x164(r31)
	  lfs       f0, 0x294(r1)
	  stfs      f0, 0x168(r31)
	  lwz       r0, 0xC(r3)
	  addi      r3, r3, 0x10
	  stw       r0, 0x364(r1)
	  lfs       f0, 0x364(r1)
	  stfs      f0, 0x16C(r31)

	.loc_0x620:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,11,11
	  beq-      .loc_0x670
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x27C(r1)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x274(r1)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x26C(r1)
	  lfs       f0, 0x26C(r1)
	  stfs      f0, 0x170(r31)
	  lfs       f0, 0x274(r1)
	  stfs      f0, 0x174(r31)
	  lfs       f0, 0x27C(r1)
	  stfs      f0, 0x178(r31)
	  lwz       r0, 0xC(r3)
	  addi      r3, r3, 0x10
	  stw       r0, 0x35C(r1)
	  lfs       f0, 0x35C(r1)
	  stfs      f0, 0x17C(r31)

	.loc_0x670:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,10,10
	  beq-      .loc_0x6E4
	  lwz       r5, 0x8(r3)
	  lis       r4, 0x802E
	  subi      r0, r4, 0x2878
	  stw       r5, 0x264(r1)
	  lwz       r4, 0x4(r3)
	  stw       r4, 0x25C(r1)
	  lwz       r4, 0x0(r3)
	  stw       r4, 0x254(r1)
	  lfs       f0, 0x254(r1)
	  stfs      f0, 0x180(r31)
	  lfs       f0, 0x25C(r1)
	  stfs      f0, 0x184(r31)
	  lfs       f0, 0x264(r1)
	  stfs      f0, 0x188(r31)
	  lbz       r4, 0xC(r3)
	  stb       r4, 0x18C(r31)
	  lbz       r4, 0xD(r3)
	  stb       r4, 0x18E(r31)
	  lbz       r4, 0xE(r3)
	  addi      r3, r3, 0x10
	  stb       r4, 0x18D(r31)
	  lbz       r4, 0x18E(r31)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r0, r4
	  lwz       r0, 0x0(r4)
	  stw       r0, 0x7C(r31)

	.loc_0x6E4:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,9,9
	  beq-      .loc_0x704
	  lwz       r0, 0x0(r3)
	  addi      r3, r3, 0x4
	  stw       r0, 0x354(r1)
	  lfs       f0, 0x354(r1)
	  stfs      f0, 0x190(r31)

	.loc_0x704:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,8,8
	  beq-      .loc_0x764
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x24C(r1)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x244(r1)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x23C(r1)
	  lfs       f0, 0x23C(r1)
	  stfs      f0, 0x194(r31)
	  lfs       f0, 0x244(r1)
	  stfs      f0, 0x198(r31)
	  lfs       f0, 0x24C(r1)
	  stfs      f0, 0x19C(r31)
	  lwz       r0, 0xC(r3)
	  stw       r0, 0x34C(r1)
	  lfs       f0, 0x34C(r1)
	  stfs      f0, 0x1A0(r31)
	  lwz       r0, 0x10(r3)
	  addi      r3, r3, 0x14
	  stw       r0, 0x344(r1)
	  lfs       f0, 0x344(r1)
	  stfs      f0, 0x1A4(r31)

	.loc_0x764:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x7D0
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x33C(r1)
	  lfs       f0, 0x33C(r1)
	  stfs      f0, 0x114(r31)
	  lwz       r0, 0x4(r3)
	  stw       r0, 0x334(r1)
	  lfs       f0, 0x334(r1)
	  stfs      f0, 0x118(r31)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x32C(r1)
	  lfs       f0, 0x32C(r1)
	  stfs      f0, 0x11C(r31)
	  lbz       r0, 0xC(r3)
	  stb       r0, 0x120(r31)
	  lbz       r0, 0xD(r3)
	  stb       r0, 0x121(r31)
	  lbz       r0, 0xE(r3)
	  stb       r0, 0x122(r31)
	  lbz       r0, 0xF(r3)
	  stb       r0, 0x123(r31)
	  lbz       r0, 0x10(r3)
	  stb       r0, 0x124(r31)
	  lbz       r0, 0x11(r3)
	  stb       r0, 0x125(r31)

	.loc_0x7D0:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,13,13
	  beq-      .loc_0x938
	  lfs       f1, 0x144(r31)
	  lfs       f0, 0x148(r31)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x14C(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x4C70(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpu     cr0, f0, f1
	  fmr       f4, f1
	  bne-      .loc_0x8AC
	  bl        0x7A640
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4C48(r2)
	  stw       r0, 0x4DC(r1)
	  lis       r30, 0x4330
	  lfs       f1, -0x4C68(r2)
	  stw       r30, 0x4D8(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f2, 0x4D8(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f29, f0, f1
	  bl        0x7A610
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4C48(r2)
	  stw       r0, 0x4D4(r1)
	  fmr       f1, f29
	  lfs       f2, -0x4C68(r2)
	  stw       r30, 0x4D0(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f3, 0x4D0(r1)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f28, f0, f2
	  bl        0x7E258
	  fmr       f31, f1
	  fmr       f1, f29
	  bl        0x7E0B8
	  fmr       f30, f1
	  fmr       f1, f28
	  bl        0x7E240
	  fmr       f29, f1
	  fmr       f1, f28
	  bl        0x7E0A0
	  fmuls     f1, f31, f1
	  fmuls     f0, f31, f29
	  stfs      f1, 0x144(r31)
	  stfs      f0, 0x148(r31)
	  stfs      f30, 0x14C(r31)
	  b         .loc_0x938

	.loc_0x8AC:
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x910
	  fsqrte    f1, f4
	  lfd       f3, -0x4C60(r2)
	  lfd       f2, -0x4C58(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x434(r1)
	  lfs       f1, 0x434(r1)
	  b         .loc_0x914

	.loc_0x910:
	  fmr       f1, f4

	.loc_0x914:
	  lfs       f0, 0x144(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x144(r31)
	  lfs       f0, 0x148(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x148(r31)
	  lfs       f0, 0x14C(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x14C(r31)

	.loc_0x938:
	  lwz       r0, 0x84(r31)
	  rlwinm.   r0,r0,0,8,8
	  beq-      .loc_0xA94
	  lfs       f1, 0x194(r31)
	  lfs       f0, 0x198(r31)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x19C(r31)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x4C70(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpu     cr0, f0, f4
	  bne-      .loc_0xA10
	  bl        0x7A4DC
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4C48(r2)
	  stw       r0, 0x4D4(r1)
	  lis       r30, 0x4330
	  lfs       f1, -0x4C68(r2)
	  stw       r30, 0x4D0(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f2, 0x4D0(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f28, f0, f1
	  bl        0x7A4AC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4C48(r2)
	  stw       r0, 0x4DC(r1)
	  fmr       f1, f28
	  lfs       f2, -0x4C68(r2)
	  stw       r30, 0x4D8(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f3, 0x4D8(r1)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f27, f0, f2
	  bl        0x7E0F4
	  fmr       f29, f1
	  fmr       f1, f28
	  bl        0x7DF54
	  fmr       f30, f1
	  fmr       f1, f27
	  bl        0x7E0DC
	  fmr       f31, f1
	  fmr       f1, f27
	  bl        0x7DF3C
	  fmuls     f1, f29, f1
	  fmuls     f0, f29, f31
	  stfs      f1, 0x194(r31)
	  stfs      f0, 0x198(r31)
	  stfs      f30, 0x19C(r31)
	  b         .loc_0xA94

	.loc_0xA10:
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xA70
	  fsqrte    f1, f4
	  lfd       f3, -0x4C60(r2)
	  lfd       f2, -0x4C58(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x428(r1)
	  lfs       f4, 0x428(r1)

	.loc_0xA70:
	  lfs       f0, 0x194(r31)
	  fdivs     f0, f0, f4
	  stfs      f0, 0x194(r31)
	  lfs       f0, 0x198(r31)
	  fdivs     f0, f0, f4
	  stfs      f0, 0x198(r31)
	  lfs       f0, 0x19C(r31)
	  fdivs     f0, f0, f4
	  stfs      f0, 0x19C(r31)

	.loc_0xA94:
	  lfs       f0, -0x4C70(r2)
	  lfs       f2, 0xE0(r31)
	  fcmpu     cr0, f0, f2
	  bne-      .loc_0xAAC
	  lfs       f0, -0x4C50(r2)
	  b         .loc_0xABC

	.loc_0xAAC:
	  lfs       f1, -0x4C50(r2)
	  lfs       f0, 0xE8(r31)
	  fsubs     f0, f1, f0
	  fdivs     f0, f0, f2

	.loc_0xABC:
	  stfs      f0, 0x6C(r31)
	  lfs       f2, -0x4C50(r2)
	  lfs       f0, 0xE4(r31)
	  fcmpu     cr0, f2, f0
	  bne-      .loc_0xAD4
	  b         .loc_0xAE4

	.loc_0xAD4:
	  lfs       f1, 0xEC(r31)
	  fsubs     f0, f2, f0
	  fsubs     f1, f2, f1
	  fdivs     f2, f1, f0

	.loc_0xAE4:
	  stfs      f2, 0x70(r31)
	  lfs       f0, -0x4C70(r2)
	  lfs       f1, 0xF8(r31)
	  fcmpu     cr0, f0, f1
	  bne-      .loc_0xB00
	  lfs       f0, -0x4C50(r2)
	  b         .loc_0xB08

	.loc_0xB00:
	  lfs       f0, -0x4C50(r2)
	  fdivs     f0, f0, f1

	.loc_0xB08:
	  stfs      f0, 0x74(r31)
	  lfs       f1, -0x4C50(r2)
	  lfs       f0, 0xFC(r31)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0xB20
	  b         .loc_0xB28

	.loc_0xB20:
	  fsubs     f0, f1, f0
	  fdivs     f1, f1, f0

	.loc_0xB28:
	  stfs      f1, 0x78(r31)

	.loc_0xB2C:
	  lwz       r0, 0x514(r1)
	  lfd       f31, 0x508(r1)
	  lfd       f30, 0x500(r1)
	  lfd       f29, 0x4F8(r1)
	  lfd       f28, 0x4F0(r1)
	  lfd       f27, 0x4E8(r1)
	  lwz       r31, 0x4E4(r1)
	  lwz       r30, 0x4E0(r1)
	  addi      r1, r1, 0x510
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void zen::particleGenerator::pmIntpManual(f32*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
void zen::particleGenerator::pmIntpLinear(f32*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019DD7C
 * Size:	0002F8
 */
void zen::particleGenerator::SetPtclsLife()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stfd      f30, 0x80(r1)
	  stfd      f29, 0x78(r1)
	  stfd      f28, 0x70(r1)
	  stfd      f27, 0x68(r1)
	  stmw      r26, 0x50(r1)
	  mr        r31, r3
	  lwz       r3, 0x84(r3)
	  rlwinm.   r0,r3,0,19,19
	  bne-      .loc_0x2D0
	  rlwinm.   r0,r3,0,24,25
	  beq-      .loc_0x158
	  rlwinm.   r0,r3,0,25,25
	  beq-      .loc_0xB8
	  lwz       r4, 0x1AC(r31)
	  li        r5, 0x1
	  lha       r0, 0x1C8(r31)
	  lis       r3, 0x4330
	  lha       r8, 0x90(r31)
	  lwz       r6, 0x1B0(r31)
	  addi      r7, r4, 0x4
	  lfd       f3, -0x4C48(r2)
	  xoris     r4, r8, 0x8000
	  xoris     r0, r0, 0x8000
	  b         .loc_0x78

	.loc_0x70:
	  addi      r7, r7, 0x4
	  addi      r5, r5, 0x1

	.loc_0x78:
	  stw       r0, 0x44(r1)
	  lfs       f0, 0x0(r7)
	  stw       r3, 0x40(r1)
	  stw       r4, 0x4C(r1)
	  lfd       f1, 0x40(r1)
	  stw       r3, 0x48(r1)
	  fsubs     f1, f1, f3
	  lfd       f2, 0x48(r1)
	  fsubs     f2, f2, f3
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bgt+      .loc_0x70
	  rlwinm    r0,r5,2,0,29
	  add       r3, r6, r0
	  lfs       f27, -0x4(r3)
	  b         .loc_0x15C

	.loc_0xB8:
	  lha       r4, 0x90(r31)
	  lis       r3, 0x4330
	  lha       r0, 0x1C8(r31)
	  li        r5, 0x1
	  xoris     r4, r4, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x44(r1)
	  lwz       r7, 0x1AC(r31)
	  stw       r0, 0x4C(r1)
	  lfd       f2, -0x4C48(r2)
	  addi      r6, r7, 0x4
	  stw       r3, 0x40(r1)
	  lwz       r4, 0x1B0(r31)
	  stw       r3, 0x48(r1)
	  lfd       f1, 0x40(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fdivs     f3, f1, f0
	  b         .loc_0x110

	.loc_0x108:
	  addi      r6, r6, 0x4
	  addi      r5, r5, 0x1

	.loc_0x110:
	  lfs       f0, 0x0(r6)
	  fcmpo     cr0, f3, f0
	  bgt+      .loc_0x108
	  rlwinm    r0,r5,2,0,29
	  add       r3, r7, r0
	  lfsx      f5, r7, r0
	  lfs       f0, -0x4(r3)
	  add       r3, r4, r0
	  fsubs     f1, f5, f3
	  lfs       f2, -0x4(r3)
	  fsubs     f3, f3, f0
	  lfsx      f4, r4, r0
	  fsubs     f0, f5, f0
	  fmuls     f3, f4, f3
	  fmuls     f1, f2, f1
	  fadds     f1, f3, f1
	  fdivs     f27, f1, f0
	  b         .loc_0x15C

	.loc_0x158:
	  lfs       f27, 0xB8(r31)

	.loc_0x15C:
	  lfs       f0, 0xBC(r31)
	  fmuls     f28, f27, f0
	  bl        0x7A190
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x44(r1)
	  lis       r29, 0x4330
	  lfd       f30, -0x4C48(r2)
	  fmuls     f0, f0, f28
	  stw       r29, 0x40(r1)
	  lfs       f31, -0x4C68(r2)
	  addi      r30, r31, 0x48
	  lfd       f2, 0x40(r1)
	  lfs       f1, 0x88(r31)
	  li        r28, 0
	  fsubs     f2, f2, f30
	  fdivs     f2, f2, f31
	  fmuls     f0, f0, f2
	  fsubs     f0, f0, f28
	  fadds     f0, f27, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x88(r31)
	  lfs       f1, 0x88(r31)
	  fctiwz    f0, f1
	  stfd      f0, 0x48(r1)
	  lwz       r27, 0x4C(r1)
	  xoris     r0, r27, 0x8000
	  stw       r0, 0x3C(r1)
	  stw       r29, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  fsubs     f0, f0, f30
	  fsubs     f0, f1, f0
	  stfs      f0, 0x88(r31)
	  lfs       f28, -0x4C50(r2)
	  lfs       f29, -0x4C70(r2)
	  b         .loc_0x2C8

	.loc_0x1EC:
	  mr        r3, r31
	  bl        0x2E80
	  mr.       r26, r3
	  beq-      .loc_0x2C4
	  lfs       f27, 0x10C(r31)
	  bl        0x7A0F4
	  xoris     r0, r3, 0x8000
	  lha       r3, 0x110(r31)
	  stw       r0, 0x3C(r1)
	  li        r0, 0
	  xoris     r3, r3, 0x8000
	  stw       r29, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  stw       r3, 0x44(r1)
	  fsubs     f0, f0, f30
	  stw       r29, 0x40(r1)
	  fdivs     f1, f0, f31
	  lfd       f0, 0x40(r1)
	  fmuls     f2, f27, f1
	  fsubs     f1, f0, f30
	  fsubs     f0, f28, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r3, 0x4C(r1)
	  sth       r3, 0x2C(r26)
	  lha       r3, 0x2C(r26)
	  stfs      f29, 0x6C(r26)
	  stb       r0, 0x70(r26)
	  stw       r30, 0x74(r26)
	  lwz       r4, 0x74(r26)
	  cmplwi    r4, 0
	  beq-      .loc_0x290
	  lbz       r0, 0x2(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x284
	  sth       r3, 0x72(r26)
	  b         .loc_0x294

	.loc_0x284:
	  lbz       r0, 0x1(r4)
	  sth       r0, 0x72(r26)
	  b         .loc_0x294

	.loc_0x290:
	  sth       r3, 0x72(r26)

	.loc_0x294:
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        .loc_0x2F8
	  lwz       r3, 0x1D8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C4
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  addi      r5, r26, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C4:
	  addi      r28, r28, 0x1

	.loc_0x2C8:
	  cmpw      r28, r27
	  blt+      .loc_0x1EC

	.loc_0x2D0:
	  lmw       r26, 0x50(r1)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lfd       f30, 0x80(r1)
	  lfd       f29, 0x78(r1)
	  lfd       f28, 0x70(r1)
	  lfd       f27, 0x68(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr

	.loc_0x2F8:
	*/
}

/*
 * --INFO--
 * Address:	8019E074
 * Size:	000F00
 */
void zen::particleGenerator::PtclsGen(zen::particleMdl*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x290(r1)
	  stfd      f31, 0x288(r1)
	  stfd      f30, 0x280(r1)
	  stfd      f29, 0x278(r1)
	  stfd      f28, 0x270(r1)
	  stfd      f27, 0x268(r1)
	  stfd      f26, 0x260(r1)
	  stfd      f25, 0x258(r1)
	  stfd      f24, 0x250(r1)
	  stfd      f23, 0x248(r1)
	  stfd      f22, 0x240(r1)
	  stfd      f21, 0x238(r1)
	  stfd      f20, 0x230(r1)
	  stw       r31, 0x22C(r1)
	  mr        r31, r4
	  stw       r30, 0x228(r1)
	  mr        r30, r3
	  stw       r29, 0x224(r1)
	  lfs       f28, 0xA0(r3)
	  lfs       f29, 0xA4(r3)
	  fmuls     f2, f28, f28
	  lfs       f30, 0xA8(r3)
	  fmuls     f1, f29, f29
	  lfs       f0, -0x4C70(r2)
	  fmuls     f3, f30, f30
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpu     cr0, f0, f1
	  fmr       f4, f1
	  bne-      .loc_0x114
	  bl        0x79F7C
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4C48(r2)
	  stw       r0, 0x21C(r1)
	  lis       r29, 0x4330
	  lfs       f1, -0x4C68(r2)
	  stw       r29, 0x218(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f2, 0x218(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f20, f0, f1
	  bl        0x79F4C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4C48(r2)
	  stw       r0, 0x214(r1)
	  fmr       f1, f20
	  lfs       f2, -0x4C68(r2)
	  stw       r29, 0x210(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f3, 0x210(r1)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f22, f0, f2
	  bl        0x7DB94
	  fmr       f21, f1
	  fmr       f1, f20
	  bl        0x7D9F4
	  fmr       f30, f1
	  fmr       f1, f22
	  bl        0x7DB7C
	  fmr       f20, f1
	  fmr       f1, f22
	  bl        0x7D9DC
	  fmuls     f28, f21, f1
	  fmuls     f29, f21, f20
	  b         .loc_0x188

	.loc_0x114:
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x178
	  fsqrte    f1, f4
	  lfd       f3, -0x4C60(r2)
	  lfd       f2, -0x4C58(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x178(r1)
	  lfs       f0, 0x178(r1)
	  b         .loc_0x17C

	.loc_0x178:
	  fmr       f0, f4

	.loc_0x17C:
	  fdivs     f28, f28, f0
	  fdivs     f29, f29, f0
	  fdivs     f30, f30, f0

	.loc_0x188:
	  lwz       r0, 0x84(r30)
	  lfs       f22, 0xAC(r30)
	  rlwinm.   r3,r0,0,20,21
	  lfs       f20, 0xB0(r30)
	  lfs       f24, 0xB4(r30)
	  beq-      .loc_0x2BC
	  rlwinm.   r3,r0,0,21,21
	  beq-      .loc_0x21C
	  lwz       r3, 0x1BC(r30)
	  li        r6, 0x1
	  lha       r9, 0x1C8(r30)
	  lis       r4, 0x4330
	  lha       r5, 0x90(r30)
	  lwz       r7, 0x1C0(r30)
	  addi      r8, r3, 0x4
	  lfd       f3, -0x4C48(r2)
	  xoris     r5, r5, 0x8000
	  xoris     r3, r9, 0x8000
	  b         .loc_0x1DC

	.loc_0x1D4:
	  addi      r8, r8, 0x4
	  addi      r6, r6, 0x1

	.loc_0x1DC:
	  stw       r3, 0x21C(r1)
	  lfs       f0, 0x0(r8)
	  stw       r4, 0x218(r1)
	  stw       r5, 0x214(r1)
	  lfd       f1, 0x218(r1)
	  stw       r4, 0x210(r1)
	  fsubs     f1, f1, f3
	  lfd       f2, 0x210(r1)
	  fsubs     f2, f2, f3
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bgt+      .loc_0x1D4
	  rlwinm    r3,r6,2,0,29
	  add       r3, r7, r3
	  lfs       f31, -0x4(r3)
	  b         .loc_0x2C0

	.loc_0x21C:
	  lha       r5, 0x90(r30)
	  lis       r4, 0x4330
	  lha       r3, 0x1C8(r30)
	  li        r6, 0x1
	  xoris     r5, r5, 0x8000
	  xoris     r3, r3, 0x8000
	  stw       r5, 0x214(r1)
	  lwz       r7, 0x1BC(r30)
	  stw       r3, 0x21C(r1)
	  lfd       f2, -0x4C48(r2)
	  addi      r3, r7, 0x4
	  stw       r4, 0x210(r1)
	  lwz       r5, 0x1C0(r30)
	  stw       r4, 0x218(r1)
	  lfd       f1, 0x210(r1)
	  lfd       f0, 0x218(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fdivs     f3, f1, f0
	  b         .loc_0x274

	.loc_0x26C:
	  addi      r3, r3, 0x4
	  addi      r6, r6, 0x1

	.loc_0x274:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f3, f0
	  bgt+      .loc_0x26C
	  rlwinm    r4,r6,2,0,29
	  add       r3, r7, r4
	  lfsx      f5, r7, r4
	  lfs       f0, -0x4(r3)
	  add       r3, r5, r4
	  fsubs     f1, f5, f3
	  lfs       f2, -0x4(r3)
	  fsubs     f3, f3, f0
	  lfsx      f4, r5, r4
	  fsubs     f0, f5, f0
	  fmuls     f3, f4, f3
	  fmuls     f1, f2, f1
	  fadds     f1, f3, f1
	  fdivs     f31, f1, f0
	  b         .loc_0x2C0

	.loc_0x2BC:
	  lfs       f31, 0xCC(r30)

	.loc_0x2C0:
	  rlwinm.   r3,r0,0,22,23
	  beq-      .loc_0x3E4
	  rlwinm.   r3,r0,0,23,23
	  beq-      .loc_0x344
	  lwz       r3, 0x1B4(r30)
	  li        r6, 0x1
	  lha       r9, 0x1C8(r30)
	  lis       r4, 0x4330
	  lha       r5, 0x90(r30)
	  lwz       r7, 0x1B8(r30)
	  addi      r8, r3, 0x4
	  lfd       f3, -0x4C48(r2)
	  xoris     r5, r5, 0x8000
	  xoris     r3, r9, 0x8000
	  b         .loc_0x304

	.loc_0x2FC:
	  addi      r8, r8, 0x4
	  addi      r6, r6, 0x1

	.loc_0x304:
	  stw       r3, 0x21C(r1)
	  lfs       f0, 0x0(r8)
	  stw       r4, 0x218(r1)
	  stw       r5, 0x214(r1)
	  lfd       f1, 0x218(r1)
	  stw       r4, 0x210(r1)
	  fsubs     f1, f1, f3
	  lfd       f2, 0x210(r1)
	  fsubs     f2, f2, f3
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bgt+      .loc_0x2FC
	  rlwinm    r3,r6,2,0,29
	  add       r3, r7, r3
	  lfs       f26, -0x4(r3)
	  b         .loc_0x3E8

	.loc_0x344:
	  lha       r5, 0x90(r30)
	  lis       r4, 0x4330
	  lha       r3, 0x1C8(r30)
	  li        r6, 0x1
	  xoris     r5, r5, 0x8000
	  xoris     r3, r3, 0x8000
	  stw       r5, 0x214(r1)
	  lwz       r7, 0x1B4(r30)
	  stw       r3, 0x21C(r1)
	  lfd       f2, -0x4C48(r2)
	  addi      r3, r7, 0x4
	  stw       r4, 0x210(r1)
	  lwz       r5, 0x1B8(r30)
	  stw       r4, 0x218(r1)
	  lfd       f1, 0x210(r1)
	  lfd       f0, 0x218(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fdivs     f3, f1, f0
	  b         .loc_0x39C

	.loc_0x394:
	  addi      r3, r3, 0x4
	  addi      r6, r6, 0x1

	.loc_0x39C:
	  lfs       f0, 0x0(r3)
	  fcmpo     cr0, f3, f0
	  bgt+      .loc_0x394
	  rlwinm    r4,r6,2,0,29
	  add       r3, r7, r4
	  lfsx      f5, r7, r4
	  lfs       f0, -0x4(r3)
	  add       r3, r5, r4
	  fsubs     f1, f5, f3
	  lfs       f2, -0x4(r3)
	  fsubs     f3, f3, f0
	  lfsx      f4, r5, r4
	  fsubs     f0, f5, f0
	  fmuls     f3, f4, f3
	  fmuls     f1, f2, f1
	  fadds     f1, f3, f1
	  fdivs     f26, f1, f0
	  b         .loc_0x3E8

	.loc_0x3E4:
	  lfs       f26, 0xC8(r30)

	.loc_0x3E8:
	  lfs       f21, 0xC4(r30)
	  rlwinm    r3,r0,0,30,31
	  cmpwi     r3, 0x1
	  fmuls     f27, f21, f26
	  bne-      .loc_0x8CC
	  rlwinm    r0,r0,0,28,29
	  cmpwi     r0, 0x4
	  bne-      .loc_0x53C
	  bl        0x79BF4
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4C48(r2)
	  stw       r0, 0x214(r1)
	  lis       r29, 0x4330
	  lfs       f1, -0x4C68(r2)
	  stw       r29, 0x210(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f2, 0x210(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f20, f0, f1
	  bl        0x79BC4
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4C48(r2)
	  stw       r0, 0x21C(r1)
	  fmr       f1, f20
	  lfs       f2, -0x4C68(r2)
	  stw       r29, 0x218(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f3, 0x218(r1)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f22, f0, f2
	  bl        0x7D80C
	  fmr       f21, f1
	  fmr       f1, f20
	  bl        0x7D66C
	  fmr       f25, f1
	  fmr       f1, f22
	  bl        0x7D7F4
	  fmr       f20, f1
	  fmr       f1, f22
	  bl        0x7D654
	  fmuls     f24, f21, f20
	  fmuls     f23, f21, f1
	  bl        0x79B64
	  xoris     r0, r3, 0x8000
	  lfs       f0, 0xD0(r30)
	  stw       r0, 0x20C(r1)
	  fsubs     f3, f26, f27
	  lfd       f1, -0x4C48(r2)
	  fmuls     f26, f31, f0
	  stw       r29, 0x208(r1)
	  lfs       f4, -0x4C68(r2)
	  lfd       f0, 0x208(r1)
	  lfs       f2, 0x94(r30)
	  fsubs     f5, f0, f1
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x9C(r30)
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fadds     f3, f27, f3
	  fmuls     f5, f23, f3
	  fmuls     f4, f24, f3
	  fmuls     f3, f25, f3
	  fadds     f22, f2, f5
	  fadds     f21, f1, f4
	  fadds     f20, f0, f3
	  bl        0x79B08
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x204(r1)
	  lfd       f3, -0x4C48(r2)
	  fmuls     f0, f0, f26
	  stw       r29, 0x200(r1)
	  lfs       f1, -0x4C68(r2)
	  lfd       f2, 0x200(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fsubs     f0, f0, f26
	  fadds     f0, f31, f0
	  fmuls     f23, f23, f0
	  fmuls     f24, f24, f0
	  fmuls     f25, f25, f0
	  b         .loc_0xCA4

	.loc_0x53C:
	  cmpwi     r0, 0x8
	  bne-      .loc_0x6CC
	  lfs       f22, 0x94(r30)
	  lfs       f21, 0x98(r30)
	  lfs       f20, 0x9C(r30)
	  bl        0x79AAC
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4C48(r2)
	  stw       r0, 0x204(r1)
	  lis       r29, 0x4330
	  lfs       f1, -0x4C68(r2)
	  stw       r29, 0x200(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f2, 0x200(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f23, f0, f1
	  bl        0x79A7C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4C48(r2)
	  stw       r0, 0x20C(r1)
	  fmr       f1, f23
	  lfs       f2, -0x4C68(r2)
	  stw       r29, 0x208(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f3, 0x208(r1)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f26, f0, f2
	  bl        0x7D6C4
	  fmr       f25, f1
	  fmr       f1, f23
	  bl        0x7D524
	  fmr       f24, f1
	  fmr       f1, f26
	  bl        0x7D6AC
	  fmr       f23, f1
	  fmr       f1, f26
	  bl        0x7D50C
	  fmuls     f0, f25, f23
	  lfs       f23, 0xC0(r30)
	  fmuls     f1, f25, f1
	  fmuls     f4, f24, f29
	  fmuls     f5, f0, f30
	  fmuls     f3, f24, f28
	  fmuls     f2, f1, f30
	  fmuls     f1, f1, f29
	  fmuls     f0, f0, f28
	  fsubs     f26, f5, f4
	  fsubs     f24, f3, f2
	  fsubs     f25, f1, f0
	  bl        0x799F4
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4C48(r2)
	  stw       r0, 0x214(r1)
	  lfs       f0, -0x4C68(r2)
	  stw       r29, 0x210(r1)
	  lfd       f1, 0x210(r1)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  fmuls     f0, f23, f0
	  fmuls     f26, f26, f0
	  fmuls     f24, f24, f0
	  fmuls     f25, f25, f0
	  fadds     f23, f28, f26
	  fadds     f24, f29, f24
	  fadds     f25, f30, f25
	  fmuls     f1, f23, f23
	  fmuls     f0, f24, f24
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x190A90
	  lfs       f0, -0x4C70(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x678
	  fdivs     f23, f23, f1
	  fdivs     f24, f24, f1
	  fdivs     f25, f25, f1

	.loc_0x678:
	  lfs       f0, 0xD0(r30)
	  fmuls     f26, f31, f0
	  bl        0x7997C
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x204(r1)
	  lis       r0, 0x4330
	  lfd       f3, -0x4C48(r2)
	  fmuls     f0, f0, f26
	  stw       r0, 0x200(r1)
	  lfs       f1, -0x4C68(r2)
	  lfd       f2, 0x200(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fsubs     f0, f0, f26
	  fadds     f0, f31, f0
	  fmuls     f23, f23, f0
	  fmuls     f24, f24, f0
	  fmuls     f25, f25, f0
	  b         .loc_0xCA4

	.loc_0x6CC:
	  bl        0x79930
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4C48(r2)
	  stw       r0, 0x204(r1)
	  lis       r29, 0x4330
	  lfs       f1, -0x4C68(r2)
	  stw       r29, 0x200(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f2, 0x200(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f20, f0, f1
	  bl        0x79900
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4C48(r2)
	  stw       r0, 0x20C(r1)
	  fmr       f1, f20
	  lfs       f2, -0x4C68(r2)
	  stw       r29, 0x208(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f3, 0x208(r1)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f23, f0, f2
	  bl        0x7D548
	  fmr       f22, f1
	  fmr       f1, f20
	  bl        0x7D3A8
	  fmr       f21, f1
	  fmr       f1, f23
	  bl        0x7D530
	  fmr       f20, f1
	  fmr       f1, f23
	  bl        0x7D390
	  fmuls     f5, f22, f1
	  lfs       f0, -0x4C70(r2)
	  fmuls     f6, f22, f20
	  fmuls     f4, f21, f28
	  fmuls     f3, f5, f30
	  fmuls     f2, f6, f30
	  fmuls     f1, f21, f29
	  fsubs     f24, f4, f3
	  fmuls     f5, f5, f29
	  fsubs     f23, f2, f1
	  fmuls     f3, f6, f28
	  fmuls     f1, f24, f24
	  fmuls     f2, f23, f23
	  fsubs     f25, f5, f3
	  fadds     f1, f2, f1
	  fmuls     f2, f25, f25
	  fadds     f4, f2, f1
	  fcmpu     cr0, f0, f4
	  bne-      .loc_0x7B8
	  li        r0, 0x1
	  sth       r0, 0x2C(r31)
	  li        r0, 0
	  sth       r0, 0x2E(r31)
	  stfs      f0, 0x30(r31)
	  b         .loc_0x824

	.loc_0x7B8:
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x818
	  fsqrte    f1, f4
	  lfd       f3, -0x4C60(r2)
	  lfd       f2, -0x4C58(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x150(r1)
	  lfs       f4, 0x150(r1)

	.loc_0x818:
	  fdivs     f23, f23, f4
	  fdivs     f24, f24, f4
	  fdivs     f25, f25, f4

	.loc_0x824:
	  bl        0x797D8
	  xoris     r0, r3, 0x8000
	  lfs       f0, 0xD0(r30)
	  stw       r0, 0x204(r1)
	  lis       r29, 0x4330
	  lfd       f1, -0x4C48(r2)
	  fsubs     f3, f26, f27
	  stw       r29, 0x200(r1)
	  lfs       f4, -0x4C68(r2)
	  fmuls     f26, f31, f0
	  lfd       f0, 0x200(r1)
	  lfs       f2, 0x94(r30)
	  fsubs     f5, f0, f1
	  lfs       f1, 0x98(r30)
	  lfs       f0, 0x9C(r30)
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fadds     f3, f27, f3
	  fmuls     f5, f23, f3
	  fmuls     f4, f24, f3
	  fmuls     f3, f25, f3
	  fadds     f22, f2, f5
	  fadds     f21, f1, f4
	  fadds     f20, f0, f3
	  bl        0x79778
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x20C(r1)
	  lfd       f3, -0x4C48(r2)
	  fmuls     f0, f0, f26
	  stw       r29, 0x208(r1)
	  lfs       f1, -0x4C68(r2)
	  lfd       f2, 0x208(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fsubs     f0, f0, f26
	  fadds     f0, f31, f0
	  fmuls     f23, f23, f0
	  fmuls     f24, f24, f0
	  fmuls     f25, f25, f0
	  b         .loc_0xCA4

	.loc_0x8CC:
	  cmpwi     r3, 0x2
	  bne-      .loc_0x9E8
	  bl        0x79728
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4C48(r2)
	  stw       r0, 0x204(r1)
	  lis       r29, 0x4330
	  lfs       f3, -0x4C68(r2)
	  stw       r29, 0x200(r1)
	  lfs       f2, -0x4C40(r2)
	  lfd       f1, 0x200(r1)
	  lfs       f0, -0x4C50(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, 0x94(r30)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f22, f0
	  fadds     f22, f1, f0
	  bl        0x796E4
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4C48(r2)
	  stw       r0, 0x20C(r1)
	  lfs       f3, -0x4C68(r2)
	  stw       r29, 0x208(r1)
	  lfs       f2, -0x4C40(r2)
	  lfd       f1, 0x208(r1)
	  lfs       f0, -0x4C50(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, 0x98(r30)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f20, f0
	  fadds     f21, f1, f0
	  bl        0x796A4
	  xoris     r0, r3, 0x8000
	  lfs       f0, 0xD0(r30)
	  stw       r0, 0x214(r1)
	  lfd       f1, -0x4C48(r2)
	  fmuls     f23, f31, f0
	  stw       r29, 0x210(r1)
	  lfs       f3, -0x4C68(r2)
	  lfd       f0, 0x210(r1)
	  lfs       f2, -0x4C40(r2)
	  fsubs     f4, f0, f1
	  lfs       f0, -0x4C50(r2)
	  lfs       f1, 0x9C(r30)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f24, f0
	  fadds     f20, f1, f0
	  bl        0x7965C
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x21C(r1)
	  lfd       f3, -0x4C48(r2)
	  fmuls     f0, f0, f23
	  stw       r29, 0x218(r1)
	  lfs       f1, -0x4C68(r2)
	  lfd       f2, 0x218(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fsubs     f0, f0, f23
	  fadds     f0, f31, f0
	  fmuls     f23, f28, f0
	  fmuls     f24, f29, f0
	  fmuls     f25, f30, f0
	  b         .loc_0xCA4

	.loc_0x9E8:
	  bl        0x79614
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x4C48(r2)
	  stw       r0, 0x204(r1)
	  lis       r29, 0x4330
	  lfs       f1, -0x4C68(r2)
	  stw       r29, 0x200(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f2, 0x200(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f23, f0, f1
	  bl        0x795E4
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x4C48(r2)
	  stw       r0, 0x20C(r1)
	  fmr       f1, f23
	  lfs       f2, -0x4C68(r2)
	  stw       r29, 0x208(r1)
	  lfs       f0, -0x4C6C(r2)
	  lfd       f3, 0x208(r1)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f26, f0, f2
	  bl        0x7D22C
	  fmr       f25, f1
	  fmr       f1, f23
	  bl        0x7D08C
	  fmr       f24, f1
	  fmr       f1, f26
	  bl        0x7D214
	  fmr       f23, f1
	  fmr       f1, f26
	  bl        0x7D074
	  fmuls     f5, f25, f1
	  lfs       f0, -0x4C70(r2)
	  fmuls     f6, f25, f23
	  fmuls     f4, f24, f28
	  fmuls     f3, f5, f30
	  fmuls     f1, f24, f29
	  fmuls     f2, f6, f30
	  fsubs     f24, f4, f3
	  fmuls     f5, f5, f29
	  fsubs     f23, f2, f1
	  fmuls     f3, f6, f28
	  fmuls     f1, f24, f24
	  fmuls     f2, f23, f23
	  fsubs     f25, f5, f3
	  fadds     f1, f2, f1
	  fmuls     f2, f25, f25
	  fadds     f4, f2, f1
	  fcmpu     cr0, f0, f4
	  bne-      .loc_0xAD4
	  li        r0, 0x1
	  sth       r0, 0x2C(r31)
	  li        r0, 0
	  sth       r0, 0x2E(r31)
	  stfs      f0, 0x30(r31)
	  b         .loc_0xB40

	.loc_0xAD4:
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xB34
	  fsqrte    f1, f4
	  lfd       f3, -0x4C60(r2)
	  lfd       f2, -0x4C58(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x14C(r1)
	  lfs       f4, 0x14C(r1)

	.loc_0xB34:
	  fdivs     f23, f23, f4
	  fdivs     f24, f24, f4
	  fdivs     f25, f25, f4

	.loc_0xB40:
	  bl        0x794BC
	  xoris     r0, r3, 0x8000
	  lfd       f7, -0x4C48(r2)
	  stw       r0, 0x204(r1)
	  lis       r29, 0x4330
	  lfs       f5, -0x4C68(r2)
	  fmuls     f4, f23, f22
	  stw       r29, 0x200(r1)
	  lfs       f3, -0x4C40(r2)
	  fmuls     f2, f24, f22
	  lfd       f6, 0x200(r1)
	  lfs       f1, -0x4C50(r2)
	  fmuls     f0, f25, f22
	  fsubs     f6, f6, f7
	  fdivs     f5, f6, f5
	  fmuls     f3, f3, f5
	  fsubs     f1, f3, f1
	  fmuls     f1, f20, f1
	  fmuls     f5, f28, f1
	  fmuls     f3, f29, f1
	  fmuls     f1, f30, f1
	  fadds     f26, f5, f4
	  fadds     f22, f3, f2
	  fadds     f20, f1, f0
	  bl        0x7945C
	  xoris     r0, r3, 0x8000
	  lfs       f2, -0x4C50(r2)
	  stw       r0, 0x20C(r1)
	  lwz       r0, 0x84(r30)
	  fsubs     f0, f21, f2
	  stw       r29, 0x208(r1)
	  rlwinm    r0,r0,0,28,29
	  lfd       f3, -0x4C48(r2)
	  lfd       f1, 0x208(r1)
	  lfs       f4, -0x4C68(r2)
	  cmpwi     r0, 0x8
	  fsubs     f6, f1, f3
	  lfs       f5, 0x94(r30)
	  lfs       f3, 0x98(r30)
	  lfs       f1, 0x9C(r30)
	  fdivs     f4, f6, f4
	  fmuls     f0, f0, f4
	  fadds     f0, f2, f0
	  fmuls     f4, f26, f0
	  fmuls     f2, f22, f0
	  fmuls     f0, f20, f0
	  fadds     f22, f5, f4
	  fadds     f21, f3, f2
	  fadds     f20, f1, f0
	  bne-      .loc_0xC58
	  lfs       f0, 0xD0(r30)
	  fmuls     f23, f31, f0
	  bl        0x793EC
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x204(r1)
	  lfd       f3, -0x4C48(r2)
	  fmuls     f0, f0, f23
	  stw       r29, 0x200(r1)
	  lfs       f1, -0x4C68(r2)
	  lfd       f2, 0x200(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fsubs     f0, f0, f23
	  fadds     f0, f31, f0
	  fmuls     f23, f28, f0
	  fmuls     f24, f29, f0
	  fmuls     f25, f30, f0
	  b         .loc_0xCA4

	.loc_0xC58:
	  lfs       f0, 0xD0(r30)
	  fmuls     f26, f31, f0
	  bl        0x7939C
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x204(r1)
	  lfd       f3, -0x4C48(r2)
	  fmuls     f0, f0, f26
	  stw       r29, 0x200(r1)
	  lfs       f1, -0x4C68(r2)
	  lfd       f2, 0x200(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fsubs     f0, f0, f26
	  fadds     f0, f31, f0
	  fmuls     f23, f23, f0
	  fmuls     f24, f24, f0
	  fmuls     f25, f25, f0

	.loc_0xCA4:
	  lfs       f2, 0x1C(r30)
	  lfs       f1, 0x20(r30)
	  lfs       f0, 0x24(r30)
	  fadds     f23, f23, f2
	  fadds     f24, f24, f1
	  stfs      f22, 0xC(r31)
	  fadds     f25, f25, f0
	  stfs      f21, 0x10(r31)
	  stfs      f20, 0x14(r31)
	  stfs      f23, 0x34(r31)
	  stfs      f24, 0x38(r31)
	  stfs      f25, 0x3C(r31)
	  bl        0x79328
	  xoris     r0, r3, 0x8000
	  lfd       f1, -0x4C48(r2)
	  stw       r0, 0x204(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x4C68(r2)
	  stw       r0, 0x200(r1)
	  lfs       f2, -0x4C40(r2)
	  lfd       f0, 0x200(r1)
	  lfs       f5, 0xF4(r30)
	  fsubs     f4, f0, f1
	  lfs       f0, -0x4C50(r2)
	  fmuls     f1, f2, f5
	  lfs       f6, 0xF0(r30)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fsubs     f0, f5, f0
	  fmuls     f0, f6, f0
	  fadds     f0, f6, f0
	  stfs      f0, 0x24(r31)
	  lfs       f1, 0x24(r31)
	  lfs       f0, -0x4C70(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xD40
	  stfs      f0, 0x24(r31)

	.loc_0xD40:
	  bl        0x792BC
	  xoris     r3, r3, 0x8000
	  lha       r0, 0x106(r30)
	  stw       r3, 0x204(r1)
	  lis       r29, 0x4330
	  xoris     r0, r0, 0x8000
	  lha       r3, 0x104(r30)
	  stw       r29, 0x200(r1)
	  xoris     r3, r3, 0x8000
	  lfd       f4, -0x4C48(r2)
	  lfd       f0, 0x200(r1)
	  stw       r0, 0x214(r1)
	  fsubs     f1, f0, f4
	  lfs       f0, -0x4C68(r2)
	  stw       r29, 0x210(r1)
	  lfs       f2, -0x4C40(r2)
	  fdivs     f3, f1, f0
	  stw       r3, 0x20C(r1)
	  lfd       f1, 0x210(r1)
	  stw       r29, 0x208(r1)
	  lfs       f0, -0x4C50(r2)
	  fmuls     f3, f2, f3
	  lfd       f2, 0x208(r1)
	  fsubs     f1, f1, f4
	  fsubs     f2, f2, f4
	  fsubs     f0, f3, f0
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x218(r1)
	  lwz       r0, 0x21C(r1)
	  sth       r0, 0x5A(r31)
	  bl        0x7923C
	  xoris     r3, r3, 0x8000
	  lha       r0, 0x108(r30)
	  stw       r3, 0x1FC(r1)
	  xoris     r0, r0, 0x8000
	  lfd       f4, -0x4C48(r2)
	  stw       r29, 0x1F8(r1)
	  lfs       f1, -0x4C68(r2)
	  lfd       f0, 0x1F8(r1)
	  stw       r0, 0x1F4(r1)
	  fsubs     f3, f0, f4
	  lfs       f2, -0x4C40(r2)
	  stw       r29, 0x1F0(r1)
	  lfs       f0, -0x4C50(r2)
	  fdivs     f3, f3, f1
	  lfd       f1, 0x1F0(r1)
	  fmuls     f2, f2, f3
	  fsubs     f1, f1, f4
	  fsubs     f0, f2, f0
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x1E8(r1)
	  lwz       r0, 0x1EC(r1)
	  sth       r0, 0x58(r31)
	  lbz       r0, 0x112(r30)
	  lfd       f1, -0x4C38(r2)
	  stw       r0, 0x1E4(r1)
	  stw       r29, 0x1E0(r1)
	  lfd       f0, 0x1E0(r1)
	  fsubs     f20, f0, f1
	  bl        0x791C4
	  xoris     r0, r3, 0x8000
	  lfd       f2, -0x4C48(r2)
	  stw       r0, 0x1DC(r1)
	  lfs       f0, -0x4C68(r2)
	  stw       r29, 0x1D8(r1)
	  lfd       f1, 0x1D8(r1)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  fmuls     f0, f20, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x1D0(r1)
	  lwz       r0, 0x1D4(r1)
	  stb       r0, 0x4C(r31)
	  lwz       r3, 0x1DC(r30)
	  lwz       r0, 0x1E0(r30)
	  stw       r3, 0x5C(r31)
	  stw       r0, 0x60(r31)
	  lwz       r0, 0x1E4(r30)
	  stw       r0, 0x64(r31)
	  lwz       r4, 0x18(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0xE98
	  b         .loc_0xE9C

	.loc_0xE98:
	  addi      r4, r30, 0xC

	.loc_0xE9C:
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x18(r31)
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x20(r31)
	  lwz       r0, 0x294(r1)
	  lfd       f31, 0x288(r1)
	  lfd       f30, 0x280(r1)
	  lfd       f29, 0x278(r1)
	  lfd       f28, 0x270(r1)
	  lfd       f27, 0x268(r1)
	  lfd       f26, 0x260(r1)
	  lfd       f25, 0x258(r1)
	  lfd       f24, 0x250(r1)
	  lfd       f23, 0x248(r1)
	  lfd       f22, 0x240(r1)
	  lfd       f21, 0x238(r1)
	  lfd       f20, 0x230(r1)
	  lwz       r31, 0x22C(r1)
	  lwz       r30, 0x228(r1)
	  lwz       r29, 0x224(r1)
	  addi      r1, r1, 0x290
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019EF74
 * Size:	000754
 */
void zen::particleGenerator::pmCalcAccel(zen::particleMdl*)
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
	  stfd      f26, 0xA0(r1)
	  stfd      f25, 0x98(r1)
	  stw       r31, 0x94(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x90(r1)
	  mr        r30, r3
	  stw       r29, 0x8C(r1)
	  lwz       r0, 0x84(r3)
	  rlwinm.   r0,r0,0,15,15
	  beq-      .loc_0x78
	  lfs       f1, 0x40(r31)
	  lfs       f0, 0x12C(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x40(r31)
	  lfs       f1, 0x44(r31)
	  lfs       f0, 0x130(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x44(r31)
	  lfs       f1, 0x48(r31)
	  lfs       f0, 0x134(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x48(r31)

	.loc_0x78:
	  lwz       r0, 0x84(r30)
	  rlwinm.   r0,r0,0,13,13
	  beq-      .loc_0x208
	  lfs       f4, 0x144(r30)
	  lfs       f5, 0xC(r31)
	  lfs       f6, 0x148(r30)
	  lfs       f7, 0x10(r31)
	  fmuls     f2, f4, f5
	  lfs       f8, 0x14C(r30)
	  fmuls     f1, f6, f7
	  lfs       f9, 0x14(r31)
	  lfs       f0, -0x4C70(r2)
	  fmuls     f3, f8, f9
	  lfs       f10, 0x15C(r30)
	  fadds     f1, f2, f1
	  fcmpu     cr0, f0, f10
	  fadds     f0, f3, f1
	  fmuls     f2, f4, f0
	  fmuls     f1, f6, f0
	  fmuls     f0, f8, f0
	  fsubs     f29, f5, f2
	  fsubs     f30, f7, f1
	  fsubs     f31, f9, f0
	  fmuls     f1, f29, f29
	  fmuls     f0, f30, f30
	  fmuls     f2, f31, f31
	  fadds     f0, f1, f0
	  fadds     f3, f2, f0
	  bne-      .loc_0xF4
	  lfs       f2, -0x4C50(r2)
	  b         .loc_0x110

	.loc_0xF4:
	  lfs       f1, 0x158(r30)
	  fadds     f0, f10, f3
	  lfs       f2, -0x4C50(r2)
	  fmuls     f1, f1, f10
	  fsubs     f1, f1, f3
	  fdivs     f0, f1, f0
	  fadds     f2, f2, f0

	.loc_0x110:
	  lfs       f1, 0x154(r30)
	  lfs       f0, 0x150(r30)
	  fmuls     f3, f1, f2
	  fmuls     f26, f0, f2
	  fmuls     f29, f29, f3
	  fmr       f1, f26
	  fmuls     f30, f30, f3
	  fmuls     f31, f31, f3
	  bl        0x7CC44
	  fmr       f28, f1
	  fmr       f1, f26
	  bl        0x7CAA4
	  lfs       f0, -0x4C50(r2)
	  lfs       f9, 0x144(r30)
	  fsubs     f8, f0, f1
	  lfs       f10, 0x148(r30)
	  lfs       f25, 0x14C(r30)
	  fmuls     f13, f28, f9
	  fmuls     f27, f28, f10
	  fmuls     f4, f8, f9
	  lfs       f0, 0xC(r31)
	  fmuls     f5, f8, f10
	  lfs       f2, 0x10(r31)
	  fmuls     f6, f28, f25
	  fmuls     f7, f10, f4
	  lfs       f3, 0x14(r31)
	  fmuls     f26, f25, f4
	  fmuls     f28, f25, f5
	  fmuls     f4, f9, f4
	  fmuls     f5, f10, f5
	  fadds     f11, f7, f6
	  fadds     f12, f1, f4
	  fmuls     f4, f8, f25
	  fadds     f9, f1, f5
	  fsubs     f8, f7, f6
	  fsubs     f10, f26, f27
	  fmuls     f6, f25, f4
	  fadds     f5, f26, f27
	  fsubs     f4, f28, f13
	  fadds     f7, f28, f13
	  fadds     f6, f1, f6
	  fmuls     f12, f0, f12
	  fmuls     f1, f2, f11
	  fmuls     f9, f2, f9
	  fmuls     f8, f0, f8
	  fadds     f11, f12, f1
	  fmuls     f10, f3, f10
	  fmuls     f1, f0, f5
	  fmuls     f0, f2, f4
	  fadds     f2, f11, f10
	  fadds     f5, f9, f8
	  fmuls     f4, f3, f7
	  fadds     f7, f29, f2
	  fmuls     f2, f3, f6
	  fadds     f0, f1, f0
	  fadds     f1, f5, f4
	  stfs      f7, 0xC(r31)
	  fadds     f0, f2, f0
	  fadds     f1, f30, f1
	  fadds     f0, f31, f0
	  stfs      f1, 0x10(r31)
	  stfs      f0, 0x14(r31)

	.loc_0x208:
	  lwz       r0, 0x84(r30)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x28C
	  lfs       f1, 0x160(r30)
	  lfs       f0, 0xC(r31)
	  lfs       f2, 0x16C(r30)
	  fsubs     f1, f1, f0
	  lfs       f0, 0x34(r31)
	  lfs       f3, 0x40(r31)
	  fmuls     f1, f2, f1
	  fsubs     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x40(r31)
	  lfs       f1, 0x164(r30)
	  lfs       f0, 0x10(r31)
	  lfs       f2, 0x16C(r30)
	  fsubs     f1, f1, f0
	  lfs       f0, 0x38(r31)
	  lfs       f3, 0x44(r31)
	  fmuls     f1, f2, f1
	  fsubs     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x44(r31)
	  lfs       f1, 0x168(r30)
	  lfs       f0, 0x14(r31)
	  lfs       f2, 0x16C(r30)
	  fsubs     f1, f1, f0
	  lfs       f0, 0x3C(r31)
	  lfs       f3, 0x48(r31)
	  fmuls     f1, f2, f1
	  fsubs     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x48(r31)

	.loc_0x28C:
	  lwz       r0, 0x84(r30)
	  rlwinm.   r0,r0,0,11,11
	  beq-      .loc_0x2F8
	  lfs       f1, 0x170(r30)
	  lfs       f0, 0xC(r31)
	  lfs       f2, 0x17C(r30)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x40(r31)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x40(r31)
	  lfs       f1, 0x174(r30)
	  lfs       f0, 0x10(r31)
	  lfs       f2, 0x17C(r30)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x44(r31)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x44(r31)
	  lfs       f1, 0x178(r30)
	  lfs       f0, 0x14(r31)
	  lfs       f2, 0x17C(r30)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x48(r31)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x48(r31)

	.loc_0x2F8:
	  lwz       r0, 0x84(r30)
	  rlwinm.   r0,r0,0,10,10
	  beq-      .loc_0x53C
	  lfs       f1, 0xC(r31)
	  li        r0, 0x10
	  lbz       r3, 0x18C(r30)
	  li        r8, 0x1
	  fctiwz    f0, f1
	  addi      r4, r3, 0x5
	  lbz       r5, 0x18D(r30)
	  slw       r0, r0, r3
	  stfd      f0, 0x80(r1)
	  add       r6, r5, r0
	  lwz       r7, 0x84(r1)
	  slw       r4, r8, r4
	  add       r7, r7, r6
	  divw      r6, r7, r4
	  mullw     r6, r6, r4
	  sub.      r6, r7, r6
	  bge-      .loc_0x34C
	  add       r6, r6, r4

	.loc_0x34C:
	  fctiwz    f0, f1
	  sraw      r6, r6, r3
	  stfd      f0, 0x80(r1)
	  lwz       r7, 0x84(r1)
	  sub       r7, r7, r5
	  add       r8, r0, r7
	  divw      r7, r8, r4
	  mullw     r7, r7, r4
	  sub.      r7, r8, r7
	  bge-      .loc_0x378
	  add       r7, r7, r4

	.loc_0x378:
	  lfs       f1, 0x10(r31)
	  add       r8, r5, r0
	  sraw      r7, r7, r3
	  fctiwz    f0, f1
	  stfd      f0, 0x80(r1)
	  lwz       r9, 0x84(r1)
	  add       r9, r9, r8
	  divw      r8, r9, r4
	  mullw     r8, r8, r4
	  sub.      r8, r9, r8
	  bge-      .loc_0x3A8
	  add       r8, r8, r4

	.loc_0x3A8:
	  fctiwz    f0, f1
	  sraw      r8, r8, r3
	  stfd      f0, 0x80(r1)
	  lwz       r9, 0x84(r1)
	  sub       r9, r9, r5
	  add       r10, r0, r9
	  divw      r9, r10, r4
	  mullw     r9, r9, r4
	  sub.      r9, r10, r9
	  bge-      .loc_0x3D4
	  add       r9, r9, r4

	.loc_0x3D4:
	  lfs       f1, 0x14(r31)
	  add       r10, r5, r0
	  sraw      r9, r9, r3
	  fctiwz    f0, f1
	  stfd      f0, 0x80(r1)
	  lwz       r11, 0x84(r1)
	  add       r11, r11, r10
	  divw      r10, r11, r4
	  mullw     r10, r10, r4
	  sub.      r10, r11, r10
	  bge-      .loc_0x404
	  add       r10, r10, r4

	.loc_0x404:
	  fctiwz    f0, f1
	  sraw      r10, r10, r3
	  stfd      f0, 0x80(r1)
	  lwz       r11, 0x84(r1)
	  sub       r5, r11, r5
	  add       r5, r0, r5
	  divw      r0, r5, r4
	  mullw     r0, r0, r4
	  sub.      r0, r5, r0
	  bge-      .loc_0x430
	  add       r0, r0, r4

	.loc_0x430:
	  sraw      r0, r0, r3
	  lwz       r3, 0x7C(r30)
	  rlwinm    r4,r0,5,0,26
	  lfd       f2, -0x4C48(r2)
	  add       r5, r4, r9
	  lfs       f1, 0x180(r30)
	  rlwinm    r11,r5,1,0,30
	  lfs       f3, 0x40(r31)
	  rlwinm    r4,r10,5,0,26
	  lhzx      r11, r3, r11
	  add       r5, r4, r8
	  rlwinm    r4,r9,5,0,26
	  rlwinm    r9,r5,1,0,30
	  add       r5, r4, r7
	  lhzx      r9, r3, r9
	  rlwinm    r4,r8,5,0,26
	  add       r4, r4, r6
	  rlwinm    r5,r5,1,0,30
	  rlwinm    r4,r4,1,0,30
	  lhzx      r5, r3, r5
	  lhzx      r4, r3, r4
	  rlwinm    r11,r11,27,27,31
	  rlwinm    r5,r5,22,27,31
	  rlwinm    r4,r4,22,27,31
	  sub       r4, r4, r5
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x84(r1)
	  lis       r5, 0x4330
	  rlwinm    r8,r9,27,27,31
	  stw       r5, 0x80(r1)
	  sub       r8, r8, r11
	  xoris     r4, r8, 0x8000
	  lfd       f0, 0x80(r1)
	  rlwinm    r7,r7,5,0,26
	  stw       r4, 0x7C(r1)
	  add       r4, r7, r0
	  fsubs     f0, f0, f2
	  rlwinm    r6,r6,5,0,26
	  stw       r5, 0x78(r1)
	  add       r0, r6, r10
	  fmuls     f0, f1, f0
	  rlwinm    r4,r4,1,0,30
	  rlwinm    r0,r0,1,0,30
	  lhzx      r4, r3, r4
	  lhzx      r0, r3, r0
	  fadds     f1, f3, f0
	  lfd       f0, 0x78(r1)
	  rlwinm    r3,r4,0,27,31
	  rlwinm    r0,r0,0,27,31
	  fsubs     f0, f0, f2
	  stfs      f1, 0x40(r31)
	  sub       r0, r0, r3
	  xoris     r0, r0, 0x8000
	  lfs       f1, 0x184(r30)
	  stw       r0, 0x74(r1)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x44(r31)
	  stw       r5, 0x70(r1)
	  fadds     f1, f1, f0
	  lfd       f0, 0x70(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0x44(r31)
	  lfs       f1, 0x188(r30)
	  lfs       f2, 0x48(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x48(r31)

	.loc_0x53C:
	  lwz       r0, 0x84(r30)
	  rlwinm.   r0,r0,0,9,9
	  beq-      .loc_0x618
	  lfs       f28, 0x190(r30)
	  bl        0x78BB0
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x74(r1)
	  lis       r29, 0x4330
	  lfd       f4, -0x4C48(r2)
	  fmuls     f0, f0, f28
	  stw       r29, 0x70(r1)
	  lfs       f2, -0x4C68(r2)
	  lfd       f3, 0x70(r1)
	  lfs       f1, 0x40(r31)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f0, f0, f2
	  fsubs     f0, f0, f28
	  fadds     f0, f1, f0
	  stfs      f0, 0x40(r31)
	  lfs       f28, 0x190(r30)
	  bl        0x78B68
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x7C(r1)
	  lfd       f4, -0x4C48(r2)
	  fmuls     f0, f0, f28
	  stw       r29, 0x78(r1)
	  lfs       f2, -0x4C68(r2)
	  lfd       f3, 0x78(r1)
	  lfs       f1, 0x44(r31)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f0, f0, f2
	  fsubs     f0, f0, f28
	  fadds     f0, f1, f0
	  stfs      f0, 0x44(r31)
	  lfs       f28, 0x190(r30)
	  bl        0x78B24
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x84(r1)
	  lfd       f4, -0x4C48(r2)
	  fmuls     f0, f0, f28
	  stw       r29, 0x80(r1)
	  lfs       f2, -0x4C68(r2)
	  lfd       f3, 0x80(r1)
	  lfs       f1, 0x48(r31)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f0, f0, f2
	  fsubs     f0, f0, f28
	  fadds     f0, f1, f0
	  stfs      f0, 0x48(r31)

	.loc_0x618:
	  lwz       r0, 0x84(r30)
	  rlwinm.   r0,r0,0,8,8
	  beq-      .loc_0x6E0
	  lfs       f0, -0x4C70(r2)
	  stfs      f0, 0x3C(r31)
	  stfs      f0, 0x38(r31)
	  stfs      f0, 0x34(r31)
	  lfs       f11, 0x194(r30)
	  lfs       f12, 0xC(r31)
	  lfs       f7, 0x198(r30)
	  lfs       f8, 0x10(r31)
	  fmuls     f2, f11, f12
	  lfs       f9, 0x19C(r30)
	  fmuls     f1, f7, f8
	  lfs       f10, 0x14(r31)
	  lfs       f0, 0x1A0(r30)
	  fmuls     f6, f9, f10
	  lfs       f3, 0x1A4(r30)
	  fadds     f1, f2, f1
	  lfs       f5, 0x40(r31)
	  fmuls     f4, f0, f11
	  fadds     f0, f6, f1
	  fmuls     f2, f11, f0
	  fmuls     f1, f7, f0
	  fmuls     f0, f9, f0
	  fsubs     f2, f2, f12
	  fsubs     f1, f1, f8
	  fsubs     f0, f0, f10
	  fmuls     f2, f3, f2
	  fadds     f2, f4, f2
	  fadds     f2, f5, f2
	  stfs      f2, 0x40(r31)
	  lfs       f2, 0x1A4(r30)
	  lfs       f4, 0x1A0(r30)
	  lfs       f3, 0x198(r30)
	  fmuls     f1, f2, f1
	  lfs       f5, 0x44(r31)
	  fmuls     f2, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f5, f1
	  stfs      f1, 0x44(r31)
	  lfs       f1, 0x1A4(r30)
	  lfs       f3, 0x1A0(r30)
	  lfs       f2, 0x19C(r30)
	  fmuls     f0, f1, f0
	  lfs       f4, 0x48(r31)
	  fmuls     f1, f3, f2
	  fadds     f0, f1, f0
	  fadds     f0, f4, f0
	  stfs      f0, 0x48(r31)

	.loc_0x6E0:
	  lwz       r0, 0x84(r30)
	  rlwinm.   r0,r0,0,14,14
	  beq-      .loc_0x71C
	  lfs       f1, 0xC(r31)
	  lfs       f0, 0x138(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r31)
	  lfs       f1, 0x10(r31)
	  lfs       f0, 0x13C(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r31)
	  lfs       f1, 0x14(r31)
	  lfs       f0, 0x140(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r31)

	.loc_0x71C:
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lfd       f30, 0xC0(r1)
	  lfd       f29, 0xB8(r1)
	  lfd       f28, 0xB0(r1)
	  lfd       f27, 0xA8(r1)
	  lfd       f26, 0xA0(r1)
	  lfd       f25, 0x98(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  lwz       r29, 0x8C(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019F6C8
 * Size:	000648
 */
void zen::particleGenerator::UpdatePtclsStatus(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  stfd      f30, 0x100(r1)
	  stfd      f29, 0xF8(r1)
	  stfd      f28, 0xF0(r1)
	  stfd      f27, 0xE8(r1)
	  stfd      f26, 0xE0(r1)
	  stfd      f25, 0xD8(r1)
	  stfd      f24, 0xD0(r1)
	  stfd      f23, 0xC8(r1)
	  fmr       f23, f1
	  stfd      f22, 0xC0(r1)
	  stfd      f21, 0xB8(r1)
	  stfd      f20, 0xB0(r1)
	  stmw      r26, 0x98(r1)
	  mr        r26, r3
	  lfs       f24, 0xD8(r3)
	  bl        0x7895C
	  xoris     r0, r3, 0x8000
	  lwz       r29, 0x28(r26)
	  stw       r0, 0x94(r1)
	  lis       r30, 0x4330
	  lfd       f25, -0x4C48(r2)
	  stw       r30, 0x90(r1)
	  lfs       f26, -0x4C68(r2)
	  lfd       f1, 0x90(r1)
	  lfs       f0, 0xD4(r26)
	  fsubs     f1, f1, f25
	  lwz       r3, 0x8(r29)
	  lfs       f30, -0x4C40(r2)
	  lfd       f31, -0x4C38(r2)
	  fdivs     f1, f1, f26
	  lfs       f21, -0x4C70(r2)
	  lfs       f22, -0x4C30(r2)
	  lfd       f27, -0x4C60(r2)
	  lfd       f28, -0x4C58(r2)
	  fmuls     f1, f24, f1
	  lfs       f29, -0x4C50(r2)
	  fsubs     f24, f0, f1
	  b         .loc_0x5F0

	.loc_0xA8:
	  mr        r27, r3
	  lwz       r28, 0x8(r3)
	  lha       r3, 0x2E(r3)
	  lha       r0, 0x2C(r27)
	  addi      r3, r3, 0x1
	  cmpw      r3, r0
	  blt-      .loc_0xF8
	  mr        r3, r27
	  lwz       r31, 0x1D0(r26)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  mr        r4, r27
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5EC

	.loc_0xF8:
	  stfs      f21, 0x48(r27)
	  stfs      f21, 0x44(r27)
	  stfs      f21, 0x40(r27)
	  lha       r3, 0x2E(r27)
	  lbz       r0, 0x1A8(r26)
	  cmpw      r3, r0
	  blt-      .loc_0x120
	  addi      r3, r26, 0
	  addi      r4, r27, 0
	  bl        -0x870

	.loc_0x120:
	  lfs       f0, 0x34(r27)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x34(r27)
	  lfs       f0, 0x38(r27)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x38(r27)
	  lfs       f0, 0x3C(r27)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x3C(r27)
	  lfs       f1, 0x34(r27)
	  lfs       f0, 0x40(r27)
	  fadds     f0, f1, f0
	  stfs      f0, 0x34(r27)
	  lfs       f1, 0x38(r27)
	  lfs       f0, 0x44(r27)
	  fadds     f0, f1, f0
	  stfs      f0, 0x38(r27)
	  lfs       f1, 0x3C(r27)
	  lfs       f0, 0x48(r27)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C(r27)
	  lwz       r0, 0x84(r26)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x248
	  lfs       f1, 0x34(r27)
	  lfs       f0, 0x38(r27)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x3C(r27)
	  fmuls     f0, f0, f0
	  lfs       f3, 0xDC(r26)
	  fmuls     f2, f2, f2
	  fadds     f1, f1, f0
	  fmuls     f0, f3, f3
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  fmr       f2, f1
	  ble-      .loc_0x248
	  fcmpo     cr0, f2, f21
	  ble-      .loc_0x20C
	  fsqrte    f1, f2
	  fmul      f0, f1, f1
	  fmul      f1, f27, f1
	  fmul      f0, f2, f0
	  fsub      f0, f28, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f27, f1
	  fmul      f0, f2, f0
	  fsub      f0, f28, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f27, f1
	  fmul      f0, f2, f0
	  fsub      f0, f28, f0
	  fmul      f0, f1, f0
	  fmul      f0, f2, f0
	  frsp      f0, f0
	  stfs      f0, 0x6C(r1)
	  lfs       f2, 0x6C(r1)

	.loc_0x20C:
	  lfs       f0, 0xDC(r26)
	  lfs       f1, 0x34(r27)
	  fdivs     f0, f0, f2
	  fmuls     f0, f1, f0
	  stfs      f0, 0x34(r27)
	  lfs       f0, 0xDC(r26)
	  lfs       f1, 0x38(r27)
	  fdivs     f0, f0, f2
	  fmuls     f0, f1, f0
	  stfs      f0, 0x38(r27)
	  lfs       f0, 0xDC(r26)
	  lfs       f1, 0x3C(r27)
	  fdivs     f0, f0, f2
	  fmuls     f0, f1, f0
	  stfs      f0, 0x3C(r27)

	.loc_0x248:
	  lfs       f1, 0xC(r27)
	  lfs       f0, 0x34(r27)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r27)
	  lfs       f1, 0x10(r27)
	  lfs       f0, 0x38(r27)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r27)
	  lfs       f1, 0x14(r27)
	  lfs       f0, 0x3C(r27)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r27)
	  lha       r3, 0x2E(r27)
	  lha       r0, 0x2C(r27)
	  xoris     r3, r3, 0x8000
	  lfs       f0, 0xE0(r26)
	  xoris     r0, r0, 0x8000
	  stw       r3, 0x94(r1)
	  stw       r0, 0x8C(r1)
	  stw       r30, 0x90(r1)
	  stw       r30, 0x88(r1)
	  lfd       f2, 0x90(r1)
	  lfd       f1, 0x88(r1)
	  fsubs     f2, f2, f25
	  fsubs     f1, f1, f25
	  fdivs     f3, f2, f1
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x2D0
	  lfs       f0, 0x6C(r26)
	  lfs       f1, 0xE8(r26)
	  fmuls     f0, f3, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x50(r27)
	  b         .loc_0x2FC

	.loc_0x2D0:
	  lfs       f0, 0xE4(r26)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x2E4
	  stfs      f29, 0x50(r27)
	  b         .loc_0x2FC

	.loc_0x2E4:
	  fsubs     f1, f29, f3
	  lfs       f0, 0x70(r26)
	  lfs       f2, 0xEC(r26)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x50(r27)

	.loc_0x2FC:
	  lfs       f0, 0xF8(r26)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x318
	  lfs       f0, 0x74(r26)
	  fmuls     f0, f3, f0
	  stfs      f0, 0x54(r27)
	  b         .loc_0x33C

	.loc_0x318:
	  lfs       f0, 0xFC(r26)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x32C
	  stfs      f29, 0x54(r27)
	  b         .loc_0x33C

	.loc_0x32C:
	  fsubs     f1, f29, f3
	  lfs       f0, 0x78(r26)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x54(r27)

	.loc_0x33C:
	  lfs       f20, 0x100(r26)
	  bl        0x78668
	  xoris     r0, r3, 0x8000
	  lfs       f1, 0x54(r27)
	  stw       r0, 0x8C(r1)
	  stw       r30, 0x88(r1)
	  lfd       f0, 0x88(r1)
	  fsubs     f0, f0, f25
	  fdivs     f0, f0, f26
	  fmuls     f0, f20, f0
	  fsubs     f0, f29, f0
	  fmuls     f0, f1, f0
	  stfs      f0, 0x54(r27)
	  lhz       r3, 0x58(r27)
	  lha       r0, 0x5A(r27)
	  add       r0, r3, r0
	  sth       r0, 0x58(r27)
	  lfs       f0, 0x30(r27)
	  fadds     f0, f0, f23
	  stfs      f0, 0x30(r27)
	  lfs       f0, 0x30(r27)
	  fcmpo     cr0, f0, f21
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3A4
	  fadds     f0, f22, f0
	  b         .loc_0x3A8

	.loc_0x3A4:
	  fsubs     f0, f0, f22

	.loc_0x3A8:
	  fctiwz    f0, f0
	  stfd      f0, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  extsh     r0, r0
	  sth       r0, 0x2E(r27)
	  lwz       r0, 0x84(r26)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x5B4
	  lha       r4, 0x2E(r27)
	  lbz       r3, 0x125(r26)
	  addi      r4, r4, 0x1
	  divw      r0, r4, r3
	  mullw     r0, r0, r3
	  sub.      r0, r4, r0
	  bne-      .loc_0x5B4
	  mr        r3, r26
	  bl        0x1400
	  mr.       r31, r3
	  beq-      .loc_0x5B4
	  lwz       r3, 0x18(r27)
	  lwz       r0, 0x1C(r27)
	  stw       r3, 0x18(r31)
	  stw       r0, 0x1C(r31)
	  lwz       r0, 0x20(r27)
	  stw       r0, 0x20(r31)
	  lfs       f20, 0x11C(r26)
	  bl        0x78598
	  xoris     r0, r3, 0x8000
	  fmuls     f0, f30, f20
	  stw       r0, 0x8C(r1)
	  lfs       f1, 0xC(r27)
	  stw       r30, 0x88(r1)
	  lfd       f2, 0x88(r1)
	  fsubs     f2, f2, f25
	  fdivs     f2, f2, f26
	  fmuls     f0, f0, f2
	  fsubs     f0, f0, f20
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r31)
	  lfs       f20, 0x11C(r26)
	  bl        0x78560
	  xoris     r0, r3, 0x8000
	  fmuls     f0, f30, f20
	  stw       r0, 0x94(r1)
	  lfs       f1, 0x10(r27)
	  stw       r30, 0x90(r1)
	  lfd       f2, 0x90(r1)
	  fsubs     f2, f2, f25
	  fdivs     f2, f2, f26
	  fmuls     f0, f0, f2
	  fsubs     f0, f0, f20
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r31)
	  lfs       f20, 0x11C(r26)
	  bl        0x78528
	  xoris     r0, r3, 0x8000
	  fmuls     f0, f30, f20
	  stw       r0, 0x84(r1)
	  lfs       f1, 0x14(r27)
	  stw       r30, 0x80(r1)
	  lfd       f2, 0x80(r1)
	  fsubs     f2, f2, f25
	  fdivs     f2, f2, f26
	  fmuls     f0, f0, f2
	  fsubs     f0, f0, f20
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r31)
	  lfs       f1, 0x24(r27)
	  lfs       f0, 0x50(r27)
	  lfs       f2, 0x114(r26)
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  stfs      f0, 0x24(r31)
	  lwz       r0, 0x84(r26)
	  rlwinm.   r0,r0,0,17,17
	  beq-      .loc_0x4FC
	  lbz       r0, 0x28(r27)
	  stb       r0, 0x28(r31)
	  lbz       r0, 0x29(r27)
	  stb       r0, 0x29(r31)
	  lbz       r0, 0x2A(r27)
	  stb       r0, 0x2A(r31)
	  lbz       r0, 0x2B(r27)
	  stb       r0, 0x2B(r31)
	  b         .loc_0x51C

	.loc_0x4FC:
	  lbz       r3, 0x120(r26)
	  li        r0, 0xFF
	  stb       r3, 0x28(r31)
	  lbz       r3, 0x121(r26)
	  stb       r3, 0x29(r31)
	  lbz       r3, 0x122(r26)
	  stb       r3, 0x2A(r31)
	  stb       r0, 0x2B(r31)

	.loc_0x51C:
	  lbz       r3, 0x2B(r31)
	  li        r0, 0
	  lfs       f0, 0x118(r26)
	  stw       r3, 0x84(r1)
	  stw       r30, 0x80(r1)
	  lfd       f1, 0x80(r1)
	  fsubs     f1, f1, f31
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x88(r1)
	  lwz       r3, 0x8C(r1)
	  stb       r3, 0x2B(r31)
	  stfs      f21, 0x2C(r31)
	  stb       r0, 0x31(r31)
	  lbz       r0, 0x124(r26)
	  stb       r0, 0x30(r31)
	  lbz       r0, 0x30(r31)
	  lbz       r3, 0x2B(r31)
	  stw       r0, 0x7C(r1)
	  stw       r30, 0x78(r1)
	  lfd       f0, 0x78(r1)
	  stw       r3, 0x94(r1)
	  fsubs     f0, f0, f31
	  stw       r30, 0x90(r1)
	  fdivs     f0, f0, f23
	  lfd       f1, 0x90(r1)
	  fsubs     f1, f1, f31
	  fdivs     f0, f1, f0
	  fcmpo     cr0, f0, f21
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x5A0
	  fadds     f0, f22, f0
	  b         .loc_0x5A4

	.loc_0x5A0:
	  fsubs     f0, f0, f22

	.loc_0x5A4:
	  fctiwz    f0, f0
	  stfd      f0, 0x78(r1)
	  lwz       r0, 0x7C(r1)
	  stb       r0, 0x32(r31)

	.loc_0x5B4:
	  fmr       f1, f23
	  addi      r3, r27, 0x6C
	  addi      r4, r27, 0x28
	  addi      r5, r27, 0x68
	  bl        0x2220
	  lwz       r3, 0x1D8(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x5EC
	  lwz       r12, 0x0(r3)
	  addi      r4, r26, 0
	  addi      r5, r27, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x5EC:
	  mr        r3, r28

	.loc_0x5F0:
	  cmplw     r3, r29
	  bne+      .loc_0xA8
	  mr        r3, r26
	  fmr       f1, f23
	  bl        0xCDC
	  lmw       r26, 0x98(r1)
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lfd       f30, 0x100(r1)
	  lfd       f29, 0xF8(r1)
	  lfd       f28, 0xF0(r1)
	  lfd       f27, 0xE8(r1)
	  lfd       f26, 0xE0(r1)
	  lfd       f25, 0xD8(r1)
	  lfd       f24, 0xD0(r1)
	  lfd       f23, 0xC8(r1)
	  lfd       f22, 0xC0(r1)
	  lfd       f21, 0xB8(r1)
	  lfd       f20, 0xB0(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019FD10
 * Size:	0001C4
 */
void zen::particleGenerator::ClearPtclsStatus(Texture*, Texture*)
{
	/*
	.loc_0x0:
	  stw       r4, 0x58(r3)
	  li        r7, 0
	  li        r6, 0x5
	  stw       r5, 0x5C(r3)
	  li        r4, 0x32
	  li        r0, 0xFF
	  stw       r7, 0x18(r3)
	  lfs       f0, 0x10E8(r13)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, 0x10EC(r13)
	  stfs      f0, 0x20(r3)
	  lfs       f0, 0x10F0(r13)
	  stfs      f0, 0x24(r3)
	  stw       r7, 0x80(r3)
	  stw       r6, 0x84(r3)
	  lfs       f2, -0x4C70(r2)
	  stfs      f2, 0xC8(r3)
	  stfs      f2, 0xC4(r3)
	  stfs      f2, 0xC0(r3)
	  stfs      f2, 0xBC(r3)
	  stfs      f2, 0xB4(r3)
	  stfs      f2, 0xB0(r3)
	  stfs      f2, 0xAC(r3)
	  stfs      f2, 0xA8(r3)
	  stfs      f2, 0xA0(r3)
	  stfs      f2, 0x9C(r3)
	  stfs      f2, 0x98(r3)
	  stfs      f2, 0x94(r3)
	  lfs       f1, -0x4C50(r2)
	  stfs      f1, 0xA4(r3)
	  lfs       f0, -0x4C40(r2)
	  stfs      f0, 0xB8(r3)
	  lfs       f0, -0x4C2C(r2)
	  stfs      f0, 0xCC(r3)
	  stfs      f2, 0xDC(r3)
	  stfs      f2, 0xD8(r3)
	  stfs      f2, 0xD0(r3)
	  lfs       f0, -0x4C28(r2)
	  stfs      f0, 0xD4(r3)
	  stfs      f2, 0x100(r3)
	  stfs      f2, 0xF8(r3)
	  stfs      f2, 0x10C(r3)
	  stfs      f2, 0xF4(r3)
	  stfs      f2, 0xEC(r3)
	  stfs      f2, 0xE8(r3)
	  stfs      f2, 0xE0(r3)
	  sth       r7, 0x108(r3)
	  sth       r7, 0x106(r3)
	  sth       r7, 0x104(r3)
	  sth       r4, 0x110(r3)
	  stb       r7, 0x112(r3)
	  stfs      f1, 0xFC(r3)
	  stfs      f1, 0xE4(r3)
	  stfs      f1, 0xF0(r3)
	  stfs      f1, 0x114(r3)
	  stfs      f1, 0x118(r3)
	  stfs      f2, 0x11C(r3)
	  stb       r6, 0x125(r3)
	  stb       r6, 0x124(r3)
	  stb       r7, 0x120(r3)
	  stb       r7, 0x121(r3)
	  stb       r7, 0x122(r3)
	  stb       r0, 0x123(r3)
	  stfs      f2, 0x1A4(r3)
	  stfs      f2, 0x1A0(r3)
	  stfs      f2, 0x19C(r3)
	  stfs      f2, 0x194(r3)
	  stfs      f2, 0x190(r3)
	  stfs      f2, 0x188(r3)
	  stfs      f2, 0x184(r3)
	  stfs      f2, 0x180(r3)
	  stfs      f2, 0x17C(r3)
	  stfs      f2, 0x178(r3)
	  stfs      f2, 0x174(r3)
	  stfs      f2, 0x170(r3)
	  stfs      f2, 0x16C(r3)
	  stfs      f2, 0x168(r3)
	  stfs      f2, 0x164(r3)
	  stfs      f2, 0x160(r3)
	  stfs      f2, 0x158(r3)
	  stfs      f2, 0x154(r3)
	  stfs      f2, 0x150(r3)
	  stfs      f2, 0x14C(r3)
	  stfs      f2, 0x144(r3)
	  stfs      f2, 0x140(r3)
	  stfs      f2, 0x13C(r3)
	  stfs      f2, 0x138(r3)
	  stfs      f2, 0x134(r3)
	  stfs      f2, 0x130(r3)
	  stfs      f2, 0x12C(r3)
	  stfs      f1, 0x15C(r3)
	  li        r0, 0x50
	  stfs      f1, 0x198(r3)
	  stfs      f1, 0x148(r3)
	  stb       r7, 0x1A8(r3)
	  stb       r7, 0x18D(r3)
	  stb       r7, 0x18E(r3)
	  stb       r7, 0x18C(r3)
	  sth       r0, 0x1C8(r3)
	  stb       r7, 0x1CA(r3)
	  stfs      f2, 0x88(r3)
	  stfs      f2, 0x8C(r3)
	  sth       r7, 0x90(r3)
	  stb       r7, 0x92(r3)
	  stb       r7, 0x1CC(r3)
	  stb       r7, 0x1CB(r3)
	  lfs       f0, 0x10F4(r13)
	  stfs      f0, 0x1DC(r3)
	  lfs       f0, 0x10F8(r13)
	  stfs      f0, 0x1E0(r3)
	  lfs       f0, 0x10FC(r13)
	  stfs      f0, 0x1E4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019FED4
 * Size:	0001DC
 */
void zen::particleGenerator::drawPtclBillboard(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stfd      f30, 0x70(r1)
	  stfd      f29, 0x68(r1)
	  stfd      f28, 0x60(r1)
	  stmw      r26, 0x48(r1)
	  addi      r26, r4, 0
	  addi      r27, r3, 0
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  lwz       r4, 0x2E4(r4)
	  lwz       r12, 0x74(r12)
	  addi      r4, r4, 0x1E0
	  mtlr      r12
	  blrl
	  li        r3, 0x6
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0x3
	  li        r7, 0xFF
	  bl        0x737C0
	  mr        r3, r26
	  lbz       r4, 0x1CB(r27)
	  lwz       r12, 0x3B4(r26)
	  lbz       r5, 0x1CC(r27)
	  lwz       r12, 0x54(r12)
	  lbz       r6, 0x48(r27)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  li        r4, 0
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1B8
	  lwz       r29, 0x28(r27)
	  addi      r30, r1, 0x2C
	  lfd       f31, -0x4C38(r2)
	  lis       r31, 0x4330
	  lwz       r28, 0x8(r29)
	  lfs       f28, -0x4C70(r2)
	  lfs       f29, -0x4C30(r2)
	  lfs       f30, -0x4C24(r2)
	  b         .loc_0x1B0

	.loc_0xC4:
	  lbz       r0, 0x2B(r28)
	  lfs       f0, 0x54(r28)
	  stw       r0, 0x44(r1)
	  lwz       r27, 0x8(r28)
	  stw       r31, 0x40(r1)
	  lfd       f1, 0x40(r1)
	  fsubs     f1, f1, f31
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f0, f28
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xF8
	  fadds     f0, f29, f0
	  b         .loc_0xFC

	.loc_0xF8:
	  fsubs     f0, f0, f29

	.loc_0xFC:
	  lbz       r7, 0x2A(r28)
	  fctiwz    f0, f0
	  lbz       r6, 0x29(r28)
	  mr        r3, r26
	  lbz       r0, 0x28(r28)
	  stfd      f0, 0x40(r1)
	  addi      r4, r1, 0x38
	  stb       r0, 0x38(r1)
	  addi      r5, r28, 0x68
	  lwz       r0, 0x44(r1)
	  stb       r6, 0x39(r1)
	  stb       r7, 0x3A(r1)
	  stb       r0, 0x3B(r1)
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xB0(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xC(r28)
	  mr        r3, r26
	  lfs       f0, 0x18(r28)
	  mr        r5, r30
	  lfs       f4, 0x14(r28)
	  lfs       f3, 0x20(r28)
	  fadds     f0, f1, f0
	  lfs       f2, 0x10(r28)
	  lfs       f1, 0x1C(r28)
	  fadds     f3, f4, f3
	  stfs      f0, 0x24(r1)
	  fadds     f1, f2, f1
	  lfs       f0, 0x24(r1)
	  stfs      f0, 0x2C(r1)
	  stfs      f1, 0x30(r1)
	  stfs      f3, 0x34(r1)
	  lwz       r12, 0x3B4(r26)
	  lfs       f1, 0x24(r28)
	  lfs       f0, 0x50(r28)
	  lwz       r12, 0x90(r12)
	  fmuls     f0, f1, f0
	  lhz       r0, 0x58(r28)
	  mtlr      r12
	  lwz       r4, 0x2E4(r26)
	  neg       r6, r0
	  fmuls     f1, f30, f0
	  blrl
	  mr        r28, r27

	.loc_0x1B0:
	  cmplw     r28, r29
	  bne+      .loc_0xC4

	.loc_0x1B8:
	  lmw       r26, 0x48(r1)
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lfd       f30, 0x70(r1)
	  lfd       f29, 0x68(r1)
	  lfd       f28, 0x60(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A00B0
 * Size:	0006A8
 */
void zen::particleGenerator::drawPtclOriented(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F0(r1)
	  stfd      f31, 0x1E8(r1)
	  stfd      f30, 0x1E0(r1)
	  stfd      f29, 0x1D8(r1)
	  stfd      f28, 0x1D0(r1)
	  stfd      f27, 0x1C8(r1)
	  stfd      f26, 0x1C0(r1)
	  stfd      f25, 0x1B8(r1)
	  stfd      f24, 0x1B0(r1)
	  stfd      f23, 0x1A8(r1)
	  stfd      f22, 0x1A0(r1)
	  stfd      f21, 0x198(r1)
	  stfd      f20, 0x190(r1)
	  stmw      r22, 0x168(r1)
	  addi      r22, r3, 0
	  addi      r23, r4, 0
	  addi      r3, r23, 0
	  lwz       r12, 0x3B4(r23)
	  lbz       r4, 0x1CB(r22)
	  lwz       r12, 0x54(r12)
	  lbz       r5, 0x1CC(r22)
	  lbz       r6, 0x48(r22)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  bl        0x70D2C
	  bl        0x6FADC
	  li        r3, 0
	  li        r4, 0x1
	  bl        0x6F2D4
	  li        r3, 0x9
	  li        r4, 0x2
	  bl        0x6F2C8
	  li        r3, 0xD
	  li        r4, 0x2
	  bl        0x6F2BC
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x3
	  li        r7, 0
	  bl        0x6FAEC
	  li        r3, 0
	  li        r4, 0xD
	  li        r5, 0x1
	  li        r6, 0
	  li        r7, 0
	  bl        0x6FAD4
	  lis       r3, 0x802E
	  subi      r4, r3, 0x59A0
	  li        r3, 0x9
	  li        r5, 0x6
	  bl        0x70234
	  li        r3, 0xD
	  addi      r4, r13, 0x10E0
	  li        r5, 0x2
	  bl        0x70224
	  li        r3, 0
	  bl        0x71D34
	  li        r3, 0x1
	  bl        0x70580
	  li        r3, 0x1
	  bl        0x737B4
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0xFF
	  bl        0x73600
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0x4
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x70278
	  lfs       f23, -0x4C70(r2)
	  lis       r4, 0x8039
	  lis       r3, 0x8039
	  stfs      f23, 0x88(r1)
	  addi      r29, r4, 0x4840
	  addi      r30, r3, 0x840
	  stfs      f23, 0x84(r1)
	  lis       r28, 0x4330
	  lis       r31, 0xCC01
	  stfs      f23, 0xD0(r1)
	  lfs       f1, -0x4C24(r2)
	  stfs      f23, 0x80(r1)
	  lfd       f24, -0x4C38(r2)
	  stfs      f23, 0xB0(r1)
	  lfs       f25, -0x4C30(r2)
	  lfs       f0, 0x64(r22)
	  lfd       f26, -0x4C48(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lwz       r27, 0x28(r22)
	  lwz       r26, 0x8(r27)
	  b         .loc_0x65C

	.loc_0x18C:
	  lbz       r0, 0x2B(r26)
	  lfs       f0, 0x54(r26)
	  stw       r0, 0x164(r1)
	  lwz       r25, 0x8(r26)
	  stw       r28, 0x160(r1)
	  lfd       f1, 0x160(r1)
	  fsubs     f1, f1, f24
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f0, f23
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1C0
	  fadds     f0, f25, f0
	  b         .loc_0x1C4

	.loc_0x1C0:
	  fsubs     f0, f0, f25

	.loc_0x1C4:
	  lbz       r7, 0x2A(r26)
	  fctiwz    f0, f0
	  lbz       r6, 0x29(r26)
	  mr        r3, r23
	  lbz       r0, 0x28(r26)
	  stfd      f0, 0x160(r1)
	  addi      r4, r1, 0x74
	  stb       r0, 0x74(r1)
	  addi      r5, r26, 0x68
	  lwz       r0, 0x164(r1)
	  stb       r6, 0x75(r1)
	  stb       r7, 0x76(r1)
	  stb       r0, 0x77(r1)
	  lwz       r12, 0x3B4(r23)
	  lwz       r12, 0xB0(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0xD4
	  bl        0x5D8D8
	  lhz       r0, 0x58(r26)
	  mr        r3, r22
	  lfs       f2, 0x24(r26)
	  addi      r4, r1, 0xA4
	  rlwinm    r0,r0,30,18,29
	  add       r5, r29, r0
	  lfs       f1, 0x50(r26)
	  lfs       f0, 0x0(r5)
	  addi      r5, r1, 0x78
	  fmuls     f28, f2, f1
	  addi      r6, r1, 0x7C
	  stfs      f0, 0x7C(r1)
	  addi      r12, r22, 0x1F4
	  lhz       r0, 0x58(r26)
	  rlwinm    r0,r0,30,18,29
	  add       r7, r30, r0
	  lfs       f0, 0x0(r7)
	  stfs      f0, 0x78(r1)
	  bl        0x74A28
	  nop
	  lfs       f1, 0xC(r26)
	  addi      r3, r1, 0x104
	  lfs       f0, 0x18(r26)
	  lfs       f4, 0x10(r26)
	  lfs       f2, 0x1C(r26)
	  fadds     f1, f1, f0
	  lfs       f3, 0x14(r26)
	  lfs       f0, 0x20(r26)
	  fadds     f2, f4, f2
	  fadds     f3, f3, f0
	  bl        0x5DAA8
	  lwz       r3, 0x2E4(r23)
	  addi      r4, r1, 0x104
	  addi      r5, r4, 0
	  addi      r3, r3, 0x1E0
	  bl        0x5D874
	  lbz       r0, 0x68(r22)
	  rlwinm    r0,r0,25,31,31
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2C8
	  bge-      .loc_0x2CC
	  cmpwi     r0, 0
	  bge-      .loc_0x2C0
	  b         .loc_0x2CC

	.loc_0x2C0:
	  addi      r24, r26, 0x34
	  b         .loc_0x2CC

	.loc_0x2C8:
	  addi      r24, r26, 0xC

	.loc_0x2CC:
	  lfs       f30, 0x0(r24)
	  lfs       f31, 0x4(r24)
	  fmuls     f1, f30, f30
	  lfs       f29, 0x8(r24)
	  fmuls     f0, f31, f31
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x514
	  lfs       f0, 0x60(r22)
	  fmuls     f27, f28, f0
	  bl        -0x19276C
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x314
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1
	  fdivs     f29, f29, f1

	.loc_0x314:
	  lfs       f4, 0x60(r26)
	  lfs       f5, 0x5C(r26)
	  lfs       f1, 0x64(r26)
	  fmuls     f0, f29, f4
	  fmuls     f3, f29, f5
	  fmuls     f2, f30, f1
	  fmuls     f1, f31, f1
	  fmuls     f4, f30, f4
	  fsubs     f21, f3, f2
	  fsubs     f20, f1, f0
	  fmuls     f2, f31, f5
	  fmuls     f0, f21, f21
	  fmuls     f1, f20, f20
	  fsubs     f22, f4, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f22, f22
	  fadds     f1, f1, f0
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x4EC
	  bl        -0x1927D0
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x378
	  fdivs     f20, f20, f1
	  fdivs     f21, f21, f1
	  fdivs     f22, f22, f1

	.loc_0x378:
	  lbz       r0, 0x68(r22)
	  rlwinm.   r0,r0,27,31,31
	  beq-      .loc_0x3FC
	  lwz       r3, 0x5C(r26)
	  lwz       r0, 0x60(r26)
	  stw       r3, 0x80(r1)
	  stw       r0, 0x84(r1)
	  lwz       r0, 0x64(r26)
	  stw       r0, 0x88(r1)
	  lfs       f4, 0x84(r1)
	  lfs       f0, 0x88(r1)
	  lfs       f5, 0x80(r1)
	  fmuls     f3, f4, f22
	  fmuls     f2, f0, f21
	  fmuls     f1, f0, f20
	  fmuls     f0, f5, f22
	  fsubs     f30, f3, f2
	  fmuls     f3, f5, f21
	  fsubs     f31, f1, f0
	  fmuls     f2, f4, f20
	  fmuls     f1, f30, f30
	  fmuls     f0, f31, f31
	  fsubs     f29, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f29, f29
	  fadds     f1, f1, f0
	  bl        -0x192850
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x47C
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1
	  fdivs     f29, f29, f1
	  b         .loc_0x47C

	.loc_0x3FC:
	  fmuls     f1, f21, f29
	  fmuls     f0, f22, f31
	  fmuls     f3, f22, f30
	  fmuls     f2, f20, f29
	  fsubs     f4, f1, f0
	  fmuls     f1, f20, f31
	  fmuls     f0, f21, f30
	  fsubs     f2, f3, f2
	  stfs      f4, 0x80(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0x84(r1)
	  stfs      f0, 0x88(r1)
	  lfs       f1, 0x80(r1)
	  lfs       f0, 0x84(r1)
	  lfs       f2, 0x88(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1928BC
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x47C
	  lfs       f0, 0x80(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x84(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x84(r1)
	  lfs       f0, 0x88(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x88(r1)

	.loc_0x47C:
	  fmuls     f2, f20, f28
	  lfs       f0, 0x80(r1)
	  fmuls     f1, f21, f28
	  lwz       r3, 0x80(r1)
	  fmuls     f4, f22, f28
	  stfs      f2, 0xD4(r1)
	  fmuls     f3, f30, f27
	  fmuls     f2, f31, f27
	  lwz       r0, 0x84(r1)
	  stfs      f1, 0xE4(r1)
	  fmuls     f1, f29, f27
	  stfs      f4, 0xF4(r1)
	  fmuls     f0, f0, f28
	  stfs      f3, 0xD8(r1)
	  stfs      f2, 0xE8(r1)
	  stfs      f1, 0xF8(r1)
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0x84(r1)
	  fmuls     f0, f0, f28
	  stfs      f0, 0xEC(r1)
	  lfs       f0, 0x88(r1)
	  fmuls     f0, f0, f28
	  stfs      f0, 0xFC(r1)
	  stw       r3, 0x5C(r26)
	  stw       r0, 0x60(r26)
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x64(r26)
	  b         .loc_0x53C

	.loc_0x4EC:
	  lha       r0, 0x2C(r26)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  stw       r28, 0x160(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f0, f0, f26
	  stfs      f0, 0x30(r26)
	  lha       r0, 0x2C(r26)
	  sth       r0, 0x2E(r26)
	  b         .loc_0x658

	.loc_0x514:
	  lha       r0, 0x2C(r26)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  stw       r28, 0x160(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f0, f0, f26
	  stfs      f0, 0x30(r26)
	  lha       r0, 0x2C(r26)
	  sth       r0, 0x2E(r26)
	  b         .loc_0x658

	.loc_0x53C:
	  addi      r3, r1, 0xD4
	  addi      r5, r3, 0
	  addi      r4, r1, 0xA4
	  bl        0x5D5C8
	  addi      r3, r1, 0x104
	  addi      r5, r3, 0
	  addi      r4, r1, 0xD4
	  bl        0x5D5B8
	  addi      r3, r1, 0x104
	  li        r4, 0
	  bl        0x73E40
	  lbz       r0, 0x68(r22)
	  rlwinm.   r0,r0,26,31,31
	  beq-      .loc_0x608
	  li        r3, 0x80
	  li        r4, 0
	  li        r5, 0x8
	  bl        0x705A4
	  li        r9, 0
	  stb       r9, -0x8000(r31)
	  li        r8, 0x1
	  li        r7, 0x2
	  stb       r9, -0x8000(r31)
	  li        r6, 0x3
	  li        r5, 0x4
	  stb       r9, -0x8000(r31)
	  li        r4, 0x5
	  li        r3, 0x6
	  stb       r9, -0x8000(r31)
	  li        r0, 0x7
	  stb       r8, -0x8000(r31)
	  stb       r8, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r7, -0x8000(r31)
	  stb       r7, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r6, -0x8000(r31)
	  stb       r6, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r5, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r4, -0x8000(r31)
	  stb       r8, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r3, -0x8000(r31)
	  stb       r7, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r0, -0x8000(r31)
	  stb       r6, -0x8000(r31)
	  b         .loc_0x658

	.loc_0x608:
	  li        r3, 0x80
	  li        r4, 0
	  li        r5, 0x4
	  bl        0x70510
	  li        r5, 0
	  stb       r5, -0x8000(r31)
	  li        r4, 0x1
	  li        r3, 0x2
	  stb       r5, -0x8000(r31)
	  li        r0, 0x3
	  stb       r5, -0x8000(r31)
	  stb       r5, -0x8000(r31)
	  stb       r4, -0x8000(r31)
	  stb       r4, -0x8000(r31)
	  stb       r5, -0x8000(r31)
	  stb       r3, -0x8000(r31)
	  stb       r3, -0x8000(r31)
	  stb       r5, -0x8000(r31)
	  stb       r0, -0x8000(r31)
	  stb       r0, -0x8000(r31)

	.loc_0x658:
	  mr        r26, r25

	.loc_0x65C:
	  cmplw     r26, r27
	  bne+      .loc_0x18C
	  lmw       r22, 0x168(r1)
	  lwz       r0, 0x1F4(r1)
	  lfd       f31, 0x1E8(r1)
	  lfd       f30, 0x1E0(r1)
	  lfd       f29, 0x1D8(r1)
	  lfd       f28, 0x1D0(r1)
	  lfd       f27, 0x1C8(r1)
	  lfd       f26, 0x1C0(r1)
	  lfd       f25, 0x1B8(r1)
	  lfd       f24, 0x1B0(r1)
	  lfd       f23, 0x1A8(r1)
	  lfd       f22, 0x1A0(r1)
	  lfd       f21, 0x198(r1)
	  lfd       f20, 0x190(r1)
	  addi      r1, r1, 0x1F0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A0758
 * Size:	00003C
 */
void zen::particleGenerator::RotAxisX(f32 (&)[3][4], f32&, f32&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r6)
	  stfs      f0, 0x28(r4)
	  stfs      f0, 0x14(r4)
	  lfs       f1, 0x0(r5)
	  fneg      f0, f1
	  stfs      f1, 0x24(r4)
	  stfs      f0, 0x18(r4)
	  lfs       f0, -0x4C70(r2)
	  stfs      f0, 0x20(r4)
	  stfs      f0, 0x8(r4)
	  stfs      f0, 0x10(r4)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4C50(r2)
	  stfs      f0, 0x0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A0794
 * Size:	00003C
 */
void zen::particleGenerator::RotAxisY(f32 (&)[3][4], f32&, f32&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r6)
	  stfs      f0, 0x28(r4)
	  stfs      f0, 0x0(r4)
	  lfs       f1, 0x0(r5)
	  fneg      f0, f1
	  stfs      f1, 0x8(r4)
	  stfs      f0, 0x20(r4)
	  lfs       f0, -0x4C70(r2)
	  stfs      f0, 0x24(r4)
	  stfs      f0, 0x18(r4)
	  stfs      f0, 0x10(r4)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x4C50(r2)
	  stfs      f0, 0x14(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A07D0
 * Size:	00003C
 */
void zen::particleGenerator::RotAxisZ(f32 (&)[3][4], f32&, f32&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r6)
	  stfs      f0, 0x14(r4)
	  stfs      f0, 0x0(r4)
	  lfs       f1, 0x0(r5)
	  fneg      f0, f1
	  stfs      f1, 0x4(r4)
	  stfs      f0, 0x10(r4)
	  lfs       f0, -0x4C70(r2)
	  stfs      f0, 0x18(r4)
	  stfs      f0, 0x24(r4)
	  stfs      f0, 0x20(r4)
	  stfs      f0, 0x8(r4)
	  lfs       f0, -0x4C50(r2)
	  stfs      f0, 0x28(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A080C
 * Size:	000054
 */
void zen::particleGenerator::RotAxisXY(f32 (&)[3][4], f32&, f32&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r6)
	  stfs      f0, 0x14(r4)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x0(r5)
	  stfs      f0, 0x18(r4)
	  stfs      f0, 0x20(r4)
	  lfs       f1, 0x0(r5)
	  lfs       f0, 0x0(r6)
	  fneg      f1, f1
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8(r4)
	  stfs      f0, 0x24(r4)
	  lfs       f0, 0x0(r5)
	  fmuls     f0, f0, f0
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x0(r6)
	  fmuls     f0, f0, f0
	  stfs      f0, 0x28(r4)
	  lfs       f0, -0x4C70(r2)
	  stfs      f0, 0x10(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A0860
 * Size:	00005C
 */
void zen::particleGenerator::RotAxisXZ(f32 (&)[3][4], f32&, f32&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r6)
	  stfs      f0, 0x28(r4)
	  stfs      f0, 0x0(r4)
	  lfs       f1, 0x0(r5)
	  fneg      f0, f1
	  stfs      f1, 0x10(r4)
	  stfs      f0, 0x24(r4)
	  lfs       f1, 0x0(r5)
	  lfs       f0, 0x0(r6)
	  fmuls     f1, f1, f0
	  fneg      f0, f1
	  stfs      f1, 0x18(r4)
	  stfs      f0, 0x4(r4)
	  lfs       f1, 0x0(r5)
	  fneg      f0, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r4)
	  lfs       f0, 0x0(r6)
	  fmuls     f0, f0, f0
	  stfs      f0, 0x14(r4)
	  lfs       f0, -0x4C70(r2)
	  stfs      f0, 0x20(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A08BC
 * Size:	00005C
 */
void zen::particleGenerator::RotAxisYZ(f32 (&)[3][4], f32&, f32&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r6)
	  stfs      f0, 0x28(r4)
	  stfs      f0, 0x14(r4)
	  lfs       f1, 0x0(r5)
	  fneg      f0, f1
	  stfs      f1, 0x20(r4)
	  stfs      f0, 0x4(r4)
	  lfs       f1, 0x0(r5)
	  lfs       f0, 0x0(r6)
	  fmuls     f1, f1, f0
	  fneg      f0, f1
	  stfs      f1, 0x10(r4)
	  stfs      f0, 0x8(r4)
	  lfs       f1, 0x0(r5)
	  fneg      f0, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x18(r4)
	  lfs       f0, 0x0(r6)
	  fmuls     f0, f0, f0
	  stfs      f0, 0x0(r4)
	  lfs       f0, -0x4C70(r2)
	  stfs      f0, 0x24(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A0918
 * Size:	00008C
 */
void zen::particleGenerator::RotAxisXYZ(f32 (&)[3][4], f32&, f32&)
{
	/*
	.loc_0x0:
	  lfs       f0, 0x0(r6)
	  fmuls     f0, f0, f0
	  stfs      f0, 0x28(r4)
	  stfs      f0, 0x0(r4)
	  lfs       f1, 0x0(r6)
	  lfs       f0, 0x0(r5)
	  fneg      f1, f1
	  fmuls     f0, f1, f0
	  stfs      f0, 0x18(r4)
	  stfs      f0, 0x4(r4)
	  lfs       f2, 0x0(r5)
	  lfs       f1, -0x4C50(r2)
	  lfs       f0, 0x0(r6)
	  fsubs     f1, f1, f2
	  fmuls     f0, f0, f2
	  fmuls     f0, f1, f0
	  stfs      f0, 0x24(r4)
	  stfs      f0, 0x10(r4)
	  lfs       f0, 0x0(r5)
	  fneg      f0, f0
	  stfs      f0, 0x8(r4)
	  lfs       f2, 0x0(r5)
	  lfs       f1, 0x0(r6)
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r4)
	  lfs       f0, 0x0(r6)
	  lfs       f1, 0x0(r5)
	  fmuls     f0, f0, f0
	  fadds     f0, f1, f0
	  fmuls     f0, f1, f0
	  stfs      f0, 0x20(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A09A4
 * Size:	000110
 */
void zen::particleGenerator::updatePtclChildren(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stfd      f30, 0x48(r1)
	  stfd      f29, 0x40(r1)
	  fmr       f29, f1
	  stmw      r27, 0x2C(r1)
	  mr        r27, r3
	  lwz       r30, 0x38(r3)
	  lfs       f30, -0x4C70(r2)
	  lwz       r3, 0x8(r30)
	  lfs       f31, -0x4C30(r2)
	  b         .loc_0xE8

	.loc_0x38:
	  mr        r28, r3
	  lwz       r29, 0x8(r3)
	  lbz       r3, 0x31(r3)
	  lbz       r0, 0x30(r28)
	  addi      r3, r3, 0x1
	  cmpw      r3, r0
	  blt-      .loc_0x88
	  mr        r3, r28
	  lwz       r31, 0x1D0(r27)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r31)
	  mr        r4, r28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xE4

	.loc_0x88:
	  lbz       r0, 0x2B(r28)
	  lbz       r3, 0x32(r28)
	  cmplw     r0, r3
	  ble-      .loc_0xA4
	  sub       r0, r0, r3
	  stb       r0, 0x2B(r28)
	  b         .loc_0xAC

	.loc_0xA4:
	  li        r0, 0
	  stb       r0, 0x2B(r28)

	.loc_0xAC:
	  lfs       f0, 0x2C(r28)
	  fadds     f0, f0, f29
	  stfs      f0, 0x2C(r28)
	  lfs       f0, 0x2C(r28)
	  fcmpo     cr0, f0, f30
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xD0
	  fadds     f0, f31, f0
	  b         .loc_0xD4

	.loc_0xD0:
	  fsubs     f0, f0, f31

	.loc_0xD4:
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stb       r0, 0x31(r28)

	.loc_0xE4:
	  mr        r3, r29

	.loc_0xE8:
	  cmplw     r3, r30
	  bne+      .loc_0x38
	  lmw       r27, 0x2C(r1)
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
 * Address:	801A0AB4
 * Size:	000148
 */
void zen::particleGenerator::drawPtclChildren(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stmw      r27, 0x34(r1)
	  addi      r27, r4, 0
	  addi      r28, r3, 0
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  lwz       r4, 0x2E4(r4)
	  lwz       r12, 0x74(r12)
	  addi      r4, r4, 0x1E0
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lbz       r4, 0x1CB(r28)
	  lwz       r12, 0x3B4(r27)
	  li        r6, 0
	  lbz       r5, 0x1CC(r28)
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  li        r4, 0xF
	  li        r5, 0xC
	  li        r6, 0x2
	  li        r7, 0xF
	  bl        0x7261C
	  mr        r3, r27
	  lwz       r12, 0x3B4(r27)
	  li        r4, 0x1
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x130
	  lwz       r30, 0x38(r28)
	  addi      r31, r1, 0x20
	  lfs       f31, -0x4C24(r2)
	  lwz       r29, 0x8(r30)
	  b         .loc_0x128

	.loc_0xA8:
	  mr        r3, r27
	  lwz       r28, 0x8(r29)
	  lwz       r12, 0x3B4(r27)
	  addi      r4, r29, 0x28
	  addi      r5, r4, 0
	  lwz       r12, 0xB0(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0xC(r29)
	  mr        r3, r27
	  lfs       f0, 0x18(r29)
	  mr        r5, r31
	  lfs       f4, 0x14(r29)
	  lfs       f3, 0x20(r29)
	  fadds     f0, f1, f0
	  lfs       f2, 0x10(r29)
	  lfs       f1, 0x1C(r29)
	  fadds     f3, f4, f3
	  stfs      f0, 0x1C(r1)
	  fadds     f1, f2, f1
	  lfs       f0, 0x1C(r1)
	  stfs      f0, 0x20(r1)
	  stfs      f1, 0x24(r1)
	  stfs      f3, 0x28(r1)
	  lwz       r12, 0x3B4(r27)
	  lfs       f0, 0x24(r29)
	  lwz       r12, 0x8C(r12)
	  fmuls     f1, f31, f0
	  lwz       r4, 0x2E4(r27)
	  mtlr      r12
	  blrl
	  mr        r29, r28

	.loc_0x128:
	  cmplw     r29, r30
	  bne+      .loc_0xA8

	.loc_0x130:
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A0BFC
 * Size:	0000CC
 */
void zen::particleGenerator::forceFinish()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr        r29, r3
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)
	  b         .loc_0x5C

	.loc_0x2C:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r31, 0x1D0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x5C:
	  lwz       r3, 0x28(r29)
	  lwz       r30, 0x8(r3)
	  cmplw     r3, r30
	  bne+      .loc_0x2C
	  b         .loc_0xA0

	.loc_0x70:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r31, 0x1D0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r31)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xA0:
	  lwz       r3, 0x38(r29)
	  lwz       r30, 0x8(r3)
	  cmplw     r3, r30
	  bne+      .loc_0x70
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
 * Address:	801A0CC8
 * Size:	000034
 */
void zen::particleGenerator::finish(zen::CallBack1<zen::particleGenerator*>*, zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x1D4(r3)
	  cmplw     r0, r4
	  bne-      .loc_0x2C
	  lwz       r0, 0x1D8(r3)
	  cmplw     r0, r5
	  bne-      .loc_0x2C
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r3)
	  li        r3, 0x1
	  blr

	.loc_0x2C:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A0CFC
 * Size:	0000F0
 */
void zen::particleGenerator::forceFinish(zen::CallBack1<zen::particleGenerator*>*,
                                         zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  mr        r29, r3
	  lwz       r0, 0x1D4(r3)
	  cmplw     r0, r4
	  bne-      .loc_0xD0
	  lwz       r0, 0x1D8(r29)
	  cmplw     r0, r5
	  bne-      .loc_0xD0
	  lwz       r0, 0x80(r29)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r29)
	  b         .loc_0x74

	.loc_0x44:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r31, 0x1D0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  lwz       r3, 0x28(r29)
	  lwz       r30, 0x8(r3)
	  cmplw     r3, r30
	  bne+      .loc_0x44
	  b         .loc_0xB8

	.loc_0x88:
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r31, 0x1D0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r31)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xB8:
	  lwz       r3, 0x38(r29)
	  lwz       r30, 0x8(r3)
	  cmplw     r3, r30
	  bne+      .loc_0x88
	  li        r3, 0x1
	  b         .loc_0xD4

	.loc_0xD0:
	  li        r3, 0

	.loc_0xD4:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A0DEC
 * Size:	000070
 */
void zen::particleGenerator::pmGetParticle()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x1D0(r3)
	  bl        .loc_0x70
	  mr.       r31, r3
	  beq-      .loc_0x54
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x28(r30)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x54:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr

	.loc_0x70:
	*/
}

/*
 * --INFO--
 * Address:	801A0E5C
 * Size:	000054
 */
void zen::zenListManager::get()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x8(r3)
	  cmplw     r3, r0
	  beq-      .loc_0x3C
	  mr        r31, r0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x3C:
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
 * Address:	801A0EB0
 * Size:	000074
 */
void zen::particleGenerator::pmGetParticleChild()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x1D0(r3)
	  addi      r3, r3, 0x10
	  bl        -0x74
	  mr.       r31, r3
	  beq-      .loc_0x58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x38(r30)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x58:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
