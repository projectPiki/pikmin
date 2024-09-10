#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008E2CC
 * Size:	000200
 */
void Creature::moveRotation(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  fmr       f31, f1
	  stw       r31, 0x84(r1)
	  mr        r31, r3
	  lwz       r0, 0xC8(r3)
	  rlwinm.   r0,r0,0,22,22
	  beq-      .loc_0xE8
	  lfs       f2, 0xD8(r31)
	  addi      r3, r1, 0x54
	  lfs       f1, 0xD4(r31)
	  addi      r4, r1, 0x64
	  lfs       f3, 0xDC(r31)
	  lfs       f0, -0x7510(r2)
	  fmuls     f4, f1, f31
	  fmuls     f2, f2, f31
	  stfs      f0, 0x6C(r1)
	  fmuls     f1, f3, f31
	  stfs      f0, 0x68(r1)
	  stfs      f0, 0x64(r1)
	  stfs      f4, 0x64(r1)
	  stfs      f2, 0x68(r1)
	  stfs      f1, 0x6C(r1)
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0xE0(r31)
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0xE4(r31)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0xE8(r31)
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0xEC(r31)
	  stfs      f0, 0x60(r1)
	  bl        -0x56510
	  lfs       f6, -0x750C(r2)
	  addi      r3, r31, 0xE0
	  lfs       f0, 0x54(r1)
	  lfs       f2, 0x58(r1)
	  fmuls     f0, f6, f0
	  lfs       f1, 0xE0(r31)
	  lfs       f4, 0x5C(r1)
	  fmuls     f2, f6, f2
	  lfs       f3, 0xE4(r31)
	  lfs       f5, 0x60(r1)
	  fadds     f0, f1, f0
	  fmuls     f1, f6, f4
	  lfs       f4, 0xE8(r31)
	  lfs       f7, 0xEC(r31)
	  fmuls     f5, f6, f5
	  fadds     f2, f3, f2
	  stfs      f0, 0xE0(r31)
	  fadds     f0, f4, f1
	  fadds     f1, f7, f5
	  stfs      f2, 0xE4(r31)
	  stfs      f0, 0xE8(r31)
	  stfs      f1, 0xEC(r31)
	  bl        -0x56480

	.loc_0xE8:
	  lwz       r3, 0xC8(r31)
	  rlwinm.   r4,r3,0,22,22
	  bne-      .loc_0x1C0
	  rlwinm.   r0,r3,0,21,21
	  bne-      .loc_0x1C0
	  lfs       f1, 0xA4(r31)
	  lfs       f2, 0xAC(r31)
	  fmuls     f4, f1, f1
	  lfs       f0, -0x7508(r2)
	  fmuls     f3, f2, f2
	  fadds     f3, f4, f3
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x18C
	  bl        0x18D610
	  lfs       f2, 0xA0(r31)
	  bl        -0x55E3C
	  lwz       r3, 0x224(r31)
	  lfs       f2, -0x7504(r2)
	  lfs       f3, 0x30(r3)
	  lfs       f0, 0xA0(r31)
	  fmuls     f1, f1, f3
	  fmuls     f1, f31, f1
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0xA0(r31)
	  lfs       f1, 0xA0(r31)
	  bl        -0x55E94
	  stfs      f1, 0xA0(r31)
	  lwz       r0, 0x158(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x170
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  b         .loc_0x1E8

	.loc_0x170:
	  lfs       f0, -0x5C70(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, -0x5C6C(r13)
	  stfs      f0, 0x90(r31)
	  b         .loc_0x1E8

	.loc_0x18C:
	  lwz       r0, 0x158(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A4
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  b         .loc_0x1E8

	.loc_0x1A4:
	  lfs       f0, -0x5C68(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, -0x5C64(r13)
	  stfs      f0, 0x90(r31)
	  b         .loc_0x1E8

	.loc_0x1C0:
	  cmplwi    r4, 0
	  bne-      .loc_0x1E8
	  rlwinm.   r0,r3,0,21,21
	  beq-      .loc_0x1E8
	  lfs       f0, -0x5C60(r13)
	  stfs      f0, 0x88(r31)
	  lfs       f0, 0xA0(r31)
	  stfs      f0, 0x8C(r31)
	  lfs       f0, -0x5C5C(r13)
	  stfs      f0, 0x90(r31)

	.loc_0x1E8:
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lwz       r31, 0x84(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008E4CC
 * Size:	000110
 */
void Creature::moveAttach()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  lwz       r3, 0x94(r3)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x29C(r30)
	  stw       r0, 0x2A0(r30)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x2A4(r30)
	  lwz       r4, 0x280(r30)
	  cmplwi    r4, 0
	  beq-      .loc_0xA8
	  mr        r3, r30
	  lwz       r31, 0x28(r4)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x78
	  lwz       r0, 0x184(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x94
	  mr        r3, r30
	  bl        0x1A18
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x94

	.loc_0x78:
	  lwz       r3, 0x280(r30)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x98

	.loc_0x94:
	  li        r31, 0

	.loc_0x98:
	  cmplwi    r31, 0
	  bne-      .loc_0xA8
	  li        r0, 0
	  stw       r0, 0x280(r30)

	.loc_0xA8:
	  lfs       f1, 0x29C(r30)
	  lfs       f0, 0x94(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x18(r1)
	  stfs      f0, 0x24(r1)
	  lfs       f1, 0x2A0(r30)
	  lfs       f0, 0x98(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  lfs       f1, 0x2A4(r30)
	  lfs       f0, 0x9C(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2C(r1)
	  lwz       r3, 0x24(r1)
	  lwz       r0, 0x28(r1)
	  stw       r3, 0x29C(r30)
	  stw       r0, 0x2A0(r30)
	  lwz       r0, 0x2C(r1)
	  stw       r0, 0x2A4(r30)
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
 * Address:	8008E5DC
 * Size:	000D60
 */
void Creature::moveNew(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x430(r1)
	  stfd      f31, 0x428(r1)
	  stfd      f30, 0x420(r1)
	  stfd      f29, 0x418(r1)
	  stfd      f28, 0x410(r1)
	  stfd      f27, 0x408(r1)
	  fmr       f27, f1
	  stfd      f26, 0x400(r1)
	  stw       r31, 0x3FC(r1)
	  stw       r30, 0x3F8(r1)
	  stw       r29, 0x3F4(r1)
	  mr        r29, r3
	  stw       r28, 0x3F0(r1)
	  lfs       f0, -0x7500(r2)
	  lfs       f2, 0x98(r3)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0xEC
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xEC
	  lwz       r0, 0x6C(r29)
	  cmpwi     r0, 0
	  bne-      .loc_0x94
	  lhz       r4, 0x510(r29)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E64
	  rlwinm    r3,r4,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)

	.loc_0x94:
	  lwz       r0, 0x6C(r29)
	  cmpwi     r0, 0x34
	  bne-      .loc_0xDC
	  li        r3, 0x10
	  subfic    r0, r3, 0x14
	  cmpwi     r3, 0x14
	  mtctr     r0
	  bge-      .loc_0xB8

	.loc_0xB4:
	  bdnz-     .loc_0xB4

	.loc_0xB8:
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x94(r29)
	  lfs       f2, 0x9C(r29)
	  bl        -0x267A0
	  lfs       f0, -0x74FC(r2)
	  fadds     f0, f0, f1
	  stfs      f0, 0x98(r29)
	  b         .loc_0xD28

	.loc_0xDC:
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        -0x39E0
	  b         .loc_0xD28

	.loc_0xEC:
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,25,25
	  bne-      .loc_0x16C
	  lwz       r0, 0x158(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x16C
	  lwz       r0, 0x184(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x130
	  mr        r3, r29
	  bl        0x1860
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x130
	  lwz       r3, 0x188(r29)
	  bl        -0x6A1C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x16C

	.loc_0x130:
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,24,24
	  bne-      .loc_0x16C
	  lwz       r0, 0x184(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  lwz       r0, 0x1A0(r29)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x16C

	.loc_0x154:
	  lwz       r3, 0x2F80(r13)
	  lfs       f1, 0x74(r29)
	  lfs       f0, 0x30(r3)
	  fmuls     f0, f27, f0
	  fsubs     f0, f1, f0
	  stfs      f0, 0x74(r29)

	.loc_0x16C:
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0x1CC
	  lfs       f0, 0xCC(r29)
	  lfs       f1, 0x74(r29)
	  fmuls     f0, f27, f0
	  fmuls     f0, f1, f0
	  fsubs     f0, f1, f0
	  stfs      f0, 0x74(r29)
	  lfs       f0, 0xCC(r29)
	  lfs       f1, -0x74F8(r2)
	  fmuls     f0, f27, f0
	  lfs       f2, 0x70(r29)
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x70(r29)
	  lfs       f0, 0xCC(r29)
	  lfs       f2, 0x78(r29)
	  fmuls     f0, f27, f0
	  fmuls     f0, f1, f0
	  fmuls     f0, f2, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x78(r29)

	.loc_0x1CC:
	  li        r0, 0
	  stw       r0, 0x28C(r29)
	  lwz       r0, 0x6C(r29)
	  cmpwi     r0, 0x12
	  bne-      .loc_0x6C0
	  lwz       r4, 0x2B8(r29)
	  lfsu      f2, 0x94(r4)
	  lwz       r31, 0x3068(r13)
	  stfs      f2, 0x3C8(r1)
	  lfs       f0, -0x7510(r2)
	  mr        r3, r31
	  lfs       f2, 0x4(r4)
	  lfs       f1, -0x7508(r2)
	  stfs      f2, 0x3CC(r1)
	  lfs       f2, 0x8(r4)
	  stfs      f2, 0x3D0(r1)
	  lfs       f2, 0x94(r29)
	  stfs      f2, 0x3D4(r1)
	  lfs       f2, 0x98(r29)
	  stfs      f2, 0x3D8(r1)
	  lfs       f2, 0x9C(r29)
	  stfs      f0, 0x3C4(r1)
	  stfs      f2, 0x3DC(r1)
	  stfs      f0, 0x3C0(r1)
	  stfs      f1, 0x3E0(r1)
	  stfs      f0, 0x3BC(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f29, -0x7510(r2)
	  mr        r30, r3
	  lfs       f28, -0x7508(r2)
	  b         .loc_0x424

	.loc_0x254:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x278
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x290

	.loc_0x278:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x290:
	  lwz       r4, 0x2FC(r29)
	  addi      r28, r3, 0
	  li        r5, 0x1
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x10
	  bne-      .loc_0x2BC
	  lhz       r3, 0x428(r4)
	  lhz       r0, 0x510(r28)
	  cmplw     r3, r0
	  beq-      .loc_0x2BC
	  li        r5, 0

	.loc_0x2BC:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x408
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x408
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x408
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x408
	  mr        r4, r28
	  lwz       r12, 0x0(r28)
	  addi      r3, r1, 0x220
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lfs       f30, 0x220(r1)
	  lwz       r12, 0x0(r28)
	  lfs       f31, 0x224(r1)
	  lwz       r12, 0x5C(r12)
	  lfs       f26, 0x228(r1)
	  mtlr      r12
	  blrl
	  stfs      f30, 0x38C(r1)
	  addi      r3, r1, 0x3C8
	  addi      r4, r1, 0x38C
	  stfs      f31, 0x390(r1)
	  addi      r5, r1, 0x3BC
	  addi      r6, r1, 0x3B8
	  stfs      f26, 0x394(r1)
	  stfs      f1, 0x398(r1)
	  bl        -0x79AC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x408
	  lwz       r0, 0x158(r28)
	  cmplwi    r0, 0
	  bne-      .loc_0x408
	  lfs       f1, 0x3B8(r1)
	  addi      r4, r29, 0
	  addi      r3, r1, 0x214
	  bl        0x6008
	  lfs       f3, 0x214(r1)
	  lfs       f1, 0x94(r28)
	  lfs       f2, 0x21C(r1)
	  lfs       f0, 0x9C(r28)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x18D06C
	  lfs       f0, 0x3B8(r1)
	  fmr       f30, f1
	  fcmpo     cr0, f0, f29
	  bge-      .loc_0x3C8
	  stfs      f29, 0x3B8(r1)

	.loc_0x3C8:
	  lfs       f0, 0x3B8(r1)
	  fcmpo     cr0, f0, f28
	  ble-      .loc_0x3D8
	  stfs      f28, 0x3B8(r1)

	.loc_0x3D8:
	  lfs       f1, 0x3B8(r1)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        0x2108
	  stfs      f30, 0xA0(r28)
	  addi      r4, r28, 0
	  li        r5, 0
	  lwz       r3, 0x490(r28)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x408:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x424:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x44C
	  li        r0, 0x1
	  b         .loc_0x478

	.loc_0x44C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x474
	  li        r0, 0x1
	  b         .loc_0x478

	.loc_0x474:
	  li        r0, 0

	.loc_0x478:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x254
	  lwz       r3, 0x2B8(r29)
	  lfsu      f1, 0x94(r3)
	  lfs       f3, 0x94(r29)
	  lfs       f2, 0x98(r29)
	  lfs       f0, 0x4(r3)
	  fsubs     f30, f3, f1
	  lfs       f1, 0x9C(r29)
	  fsubs     f29, f2, f0
	  lfs       f0, 0x8(r3)
	  fsubs     f28, f1, f0
	  fmuls     f1, f30, f30
	  fmuls     f0, f29, f29
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x80E58
	  fmr       f31, f1
	  lfs       f0, -0x7510(r2)
	  fcmpu     cr0, f0, f31
	  beq-      .loc_0x4DC
	  fdivs     f30, f30, f31
	  fdivs     f29, f29, f31
	  fdivs     f28, f28, f31

	.loc_0x4DC:
	  lfs       f1, 0x70(r29)
	  addi      r6, r1, 0xE0
	  lfs       f0, 0x74(r29)
	  addi      r5, r1, 0xDC
	  fmuls     f1, f1, f30
	  fmuls     f0, f0, f29
	  lfs       f2, 0x78(r29)
	  addi      r4, r1, 0xD8
	  fmuls     f2, f2, f28
	  fadds     f0, f1, f0
	  addi      r3, r1, 0x1F0
	  fadds     f0, f2, f0
	  fmuls     f2, f28, f0
	  fmuls     f1, f29, f0
	  fmuls     f0, f30, f0
	  stfs      f2, 0xE0(r1)
	  stfs      f1, 0xDC(r1)
	  stfs      f0, 0xD8(r1)
	  bl        -0x579E4
	  lfs       f5, 0x1F0(r1)
	  lfs       f0, 0x70(r29)
	  lfs       f4, 0x1F4(r1)
	  fsubs     f0, f0, f5
	  lfs       f3, 0x1F8(r1)
	  stfs      f0, 0x34C(r1)
	  lfs       f0, 0x74(r29)
	  fsubs     f0, f0, f4
	  stfs      f0, 0x350(r1)
	  lfs       f0, 0x78(r29)
	  fsubs     f0, f0, f3
	  stfs      f0, 0x354(r1)
	  lwz       r3, 0x34C(r1)
	  lwz       r0, 0x350(r1)
	  stw       r3, 0x70(r29)
	  stw       r0, 0x74(r29)
	  lwz       r0, 0x354(r1)
	  stw       r0, 0x78(r29)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f8, 0x70(r29)
	  lfs       f2, 0x28C(r3)
	  lfs       f6, 0x78(r29)
	  fmuls     f0, f8, f2
	  lfs       f7, 0x74(r29)
	  fmuls     f1, f6, f2
	  fmuls     f2, f7, f2
	  stfs      f0, 0x15C(r1)
	  lfs       f0, 0x15C(r1)
	  stfs      f0, 0x1C8(r1)
	  stfs      f2, 0x1CC(r1)
	  stfs      f1, 0x1D0(r1)
	  lfs       f0, 0x1C8(r1)
	  fsubs     f0, f8, f0
	  stfs      f0, 0x150(r1)
	  lfs       f0, 0x150(r1)
	  stfs      f0, 0x1D4(r1)
	  lfs       f0, 0x1CC(r1)
	  fsubs     f0, f7, f0
	  stfs      f0, 0x1D8(r1)
	  lfs       f0, 0x1D0(r1)
	  fsubs     f0, f6, f0
	  stfs      f0, 0x1DC(r1)
	  lwz       r3, 0x1D4(r1)
	  lwz       r0, 0x1D8(r1)
	  stw       r3, 0x70(r29)
	  stw       r0, 0x74(r29)
	  lwz       r0, 0x1DC(r1)
	  stw       r0, 0x78(r29)
	  lwz       r3, 0x34C(r1)
	  lwz       r0, 0x350(r1)
	  stw       r3, 0xA4(r29)
	  stw       r0, 0xA8(r29)
	  lwz       r0, 0x354(r1)
	  stw       r0, 0xAC(r29)
	  lwz       r3, 0x2B8(r29)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x12
	  bne-      .loc_0x658
	  addi      r4, r3, 0x70
	  lfs       f0, 0x70(r3)
	  fadds     f0, f0, f5
	  stfs      f0, 0x144(r1)
	  lfs       f0, 0x144(r1)
	  stfs      f0, 0x1B8(r1)
	  lfs       f0, 0x74(r3)
	  fadds     f0, f0, f4
	  stfs      f0, 0x1BC(r1)
	  lfs       f0, 0x78(r3)
	  fadds     f0, f0, f3
	  stfs      f0, 0x1C0(r1)
	  lwz       r3, 0x1B8(r1)
	  lwz       r0, 0x1BC(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x1C0(r1)
	  stw       r0, 0x8(r4)

	.loc_0x658:
	  lfs       f0, 0x2C0(r29)
	  fcmpu     cr0, f31, f0
	  beq-      .loc_0x6C0
	  fmuls     f2, f30, f0
	  fmuls     f1, f29, f0
	  fmuls     f0, f28, f0
	  stfs      f2, 0xE4(r1)
	  lwz       r3, 0x2B8(r29)
	  lfs       f2, 0xE4(r1)
	  lfsu      f3, 0x94(r3)
	  fadds     f2, f3, f2
	  stfs      f2, 0x138(r1)
	  lfs       f2, 0x138(r1)
	  stfs      f2, 0x1AC(r1)
	  lfs       f2, 0x4(r3)
	  fadds     f1, f2, f1
	  stfs      f1, 0x1B0(r1)
	  lfs       f1, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1B4(r1)
	  lwz       r3, 0x1AC(r1)
	  lwz       r0, 0x1B0(r1)
	  stw       r3, 0x94(r29)
	  stw       r0, 0x98(r29)
	  lwz       r0, 0x1B4(r1)
	  stw       r0, 0x9C(r29)

	.loc_0x6C0:
	  li        r30, 0
	  stw       r30, 0x280(r29)
	  lwz       r3, 0x6C(r29)
	  cmpwi     r3, 0x34
	  beq-      .loc_0x890
	  lfs       f0, 0x94(r29)
	  stfs      f0, 0x340(r1)
	  lfs       f0, 0x98(r29)
	  stfs      f0, 0x344(r1)
	  lfs       f0, 0x9C(r29)
	  stfs      f0, 0x348(r1)
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,23,23
	  beq-      .loc_0x708
	  lfs       f1, 0x344(r1)
	  lfs       f0, 0xD0(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x344(r1)

	.loc_0x708:
	  cmpwi     r3, 0xF
	  bne-      .loc_0x7C4
	  lfs       f2, 0x270(r29)
	  li        r3, 0x1
	  lfs       f0, -0x7510(r2)
	  li        r0, 0
	  fmr       f1, f27
	  stfs      f0, 0x320(r1)
	  mr        r4, r29
	  addi      r5, r1, 0x318
	  stfs      f0, 0x31C(r1)
	  stfs      f0, 0x318(r1)
	  stfs      f0, 0x32C(r1)
	  stfs      f0, 0x328(r1)
	  stfs      f0, 0x324(r1)
	  stb       r3, 0x338(r1)
	  lwz       r3, 0x340(r1)
	  lwz       r6, 0x344(r1)
	  stw       r3, 0x318(r1)
	  lwz       r3, 0x348(r1)
	  stw       r6, 0x31C(r1)
	  stw       r3, 0x320(r1)
	  lwz       r6, 0x70(r29)
	  lwz       r3, 0x74(r29)
	  stw       r6, 0x324(r1)
	  stw       r3, 0x328(r1)
	  lwz       r3, 0x78(r29)
	  stw       r3, 0x32C(r1)
	  stfs      f2, 0x330(r1)
	  lfs       f0, -0x7508(r2)
	  stw       r0, 0x33C(r1)
	  lwz       r3, 0x2F00(r13)
	  stfs      f0, 0x334(r1)
	  bl        -0x25F14
	  lwz       r3, 0x324(r1)
	  lwz       r0, 0x328(r1)
	  stw       r3, 0x70(r29)
	  stw       r0, 0x74(r29)
	  lwz       r0, 0x32C(r1)
	  stw       r0, 0x78(r29)
	  lwz       r3, 0x318(r1)
	  lwz       r0, 0x31C(r1)
	  stw       r3, 0x94(r29)
	  stw       r0, 0x98(r29)
	  lwz       r0, 0x320(r1)
	  stw       r0, 0x9C(r29)
	  b         .loc_0x870

	.loc_0x7C4:
	  lfs       f2, 0x270(r29)
	  li        r6, 0
	  lfs       f0, -0x7510(r2)
	  fmr       f1, f27
	  mr        r4, r29
	  stfs      f0, 0x2F8(r1)
	  addi      r5, r1, 0x2F0
	  stfs      f0, 0x2F4(r1)
	  stfs      f0, 0x2F0(r1)
	  stfs      f0, 0x304(r1)
	  stfs      f0, 0x300(r1)
	  stfs      f0, 0x2FC(r1)
	  stb       r6, 0x310(r1)
	  lwz       r0, 0x340(r1)
	  lwz       r3, 0x344(r1)
	  stw       r0, 0x2F0(r1)
	  lwz       r0, 0x348(r1)
	  stw       r3, 0x2F4(r1)
	  stw       r0, 0x2F8(r1)
	  lwz       r3, 0x70(r29)
	  lwz       r0, 0x74(r29)
	  stw       r3, 0x2FC(r1)
	  stw       r0, 0x300(r1)
	  lwz       r0, 0x78(r29)
	  stw       r0, 0x304(r1)
	  stfs      f2, 0x308(r1)
	  lfs       f0, -0x7508(r2)
	  stw       r6, 0x314(r1)
	  lwz       r3, 0x2F00(r13)
	  stfs      f0, 0x30C(r1)
	  bl        -0x25FC4
	  lwz       r3, 0x2FC(r1)
	  lwz       r0, 0x300(r1)
	  stw       r3, 0x70(r29)
	  stw       r0, 0x74(r29)
	  lwz       r0, 0x304(r1)
	  stw       r0, 0x78(r29)
	  lwz       r3, 0x2F0(r1)
	  lwz       r0, 0x2F4(r1)
	  stw       r3, 0x94(r29)
	  stw       r0, 0x98(r29)
	  lwz       r0, 0x2F8(r1)
	  stw       r0, 0x9C(r29)

	.loc_0x870:
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,23,23
	  beq-      .loc_0xB28
	  lfs       f1, 0x98(r29)
	  lfs       f0, 0xD0(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x98(r29)
	  b         .loc_0xB28

	.loc_0x890:
	  lbz       r0, 0x43C(r29)
	  addi      r28, r29, 0
	  cmplwi    r0, 0
	  beq-      .loc_0xA2C
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x750C(r2)
	  addi      r6, r1, 0x184
	  lfs       f3, 0x2D0(r28)
	  addi      r4, r1, 0x190
	  lfs       f2, -0x5C58(r13)
	  fmuls     f26, f0, f1
	  addi      r3, r1, 0x2A4
	  stfs      f2, 0x2E4(r1)
	  fneg      f29, f3
	  addi      r5, r28, 0xE0
	  stfs      f26, 0x2E8(r1)
	  lfs       f0, -0x5C54(r13)
	  stfs      f0, 0x2EC(r1)
	  lfs       f1, -0x5C44(r13)
	  lfs       f0, -0x5C50(r13)
	  stfs      f1, 0x184(r1)
	  lfs       f1, -0x5C40(r13)
	  stfs      f0, 0x190(r1)
	  lfs       f0, -0x5C4C(r13)
	  stfs      f1, 0x188(r1)
	  lfs       f1, -0x5C3C(r13)
	  stfs      f0, 0x194(r1)
	  lfs       f0, -0x5C48(r13)
	  stfs      f1, 0x18C(r1)
	  stfs      f0, 0x198(r1)
	  bl        -0x501F0
	  addi      r3, r1, 0x2E4
	  addi      r4, r1, 0x2A4
	  bl        -0x577B4
	  lfs       f28, 0x2E4(r1)
	  fmr       f1, f27
	  lfs       f2, 0x94(r29)
	  fadds     f0, f26, f29
	  lfs       f27, 0x2E8(r1)
	  lfs       f3, 0x98(r29)
	  fadds     f2, f28, f2
	  lfs       f26, 0x2EC(r1)
	  lfs       f4, 0x9C(r29)
	  fadds     f3, f27, f3
	  mr        r3, r29
	  stfs      f2, 0x2E4(r1)
	  fadds     f2, f26, f4
	  addi      r4, r1, 0x270
	  stfs      f3, 0x2E8(r1)
	  stfs      f2, 0x2EC(r1)
	  lfs       f2, -0x7510(r2)
	  stfs      f2, 0x278(r1)
	  stfs      f2, 0x274(r1)
	  stfs      f2, 0x270(r1)
	  stfs      f2, 0x284(r1)
	  stfs      f2, 0x280(r1)
	  stfs      f2, 0x27C(r1)
	  stb       r30, 0x290(r1)
	  lwz       r0, 0x2E4(r1)
	  lwz       r5, 0x2E8(r1)
	  stw       r0, 0x270(r1)
	  lwz       r0, 0x2EC(r1)
	  stw       r5, 0x274(r1)
	  stw       r0, 0x278(r1)
	  lwz       r5, 0x70(r29)
	  lwz       r0, 0x74(r29)
	  stw       r5, 0x27C(r1)
	  stw       r0, 0x280(r1)
	  lwz       r0, 0x78(r29)
	  stw       r0, 0x284(r1)
	  stfs      f0, 0x288(r1)
	  lfs       f0, -0x7508(r2)
	  stw       r30, 0x294(r1)
	  stfs      f0, 0x28C(r1)
	  bl        0x498
	  lwz       r3, 0x27C(r1)
	  lwz       r0, 0x280(r1)
	  stw       r3, 0x70(r29)
	  stw       r0, 0x74(r29)
	  lwz       r0, 0x284(r1)
	  stw       r0, 0x78(r29)
	  lfs       f0, 0x270(r1)
	  fsubs     f0, f0, f28
	  stfs      f0, 0x128(r1)
	  lfs       f0, 0x128(r1)
	  stfs      f0, 0x178(r1)
	  lfs       f0, 0x274(r1)
	  fsubs     f0, f0, f27
	  stfs      f0, 0x17C(r1)
	  lfs       f0, 0x278(r1)
	  fsubs     f0, f0, f26
	  stfs      f0, 0x180(r1)
	  lwz       r3, 0x178(r1)
	  lwz       r0, 0x17C(r1)
	  stw       r3, 0x94(r29)
	  stw       r0, 0x98(r29)
	  lwz       r0, 0x180(r1)
	  stw       r0, 0x9C(r29)
	  b         .loc_0xB28

	.loc_0xA2C:
	  lfs       f0, 0x94(r29)
	  stfs      f0, 0x264(r1)
	  lfs       f0, 0x98(r29)
	  stfs      f0, 0x268(r1)
	  lfs       f0, 0x9C(r29)
	  stfs      f0, 0x26C(r1)
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,23,23
	  beq-      .loc_0xA60
	  lfs       f1, 0x268(r1)
	  lfs       f0, 0xD0(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x268(r1)

	.loc_0xA60:
	  lfs       f2, 0x270(r29)
	  li        r6, 0
	  lfs       f0, -0x7510(r2)
	  fmr       f1, f27
	  mr        r4, r29
	  stfs      f0, 0x244(r1)
	  addi      r5, r1, 0x23C
	  stfs      f0, 0x240(r1)
	  stfs      f0, 0x23C(r1)
	  stfs      f0, 0x250(r1)
	  stfs      f0, 0x24C(r1)
	  stfs      f0, 0x248(r1)
	  stb       r6, 0x25C(r1)
	  lwz       r0, 0x264(r1)
	  lwz       r3, 0x268(r1)
	  stw       r0, 0x23C(r1)
	  lwz       r0, 0x26C(r1)
	  stw       r3, 0x240(r1)
	  stw       r0, 0x244(r1)
	  lwz       r3, 0x70(r29)
	  lwz       r0, 0x74(r29)
	  stw       r3, 0x248(r1)
	  stw       r0, 0x24C(r1)
	  lwz       r0, 0x78(r29)
	  stw       r0, 0x250(r1)
	  stfs      f2, 0x254(r1)
	  lfs       f0, -0x7508(r2)
	  stw       r6, 0x260(r1)
	  lwz       r3, 0x2F00(r13)
	  stfs      f0, 0x258(r1)
	  bl        -0x26260
	  lwz       r3, 0x248(r1)
	  lwz       r0, 0x24C(r1)
	  stw       r3, 0x70(r29)
	  stw       r0, 0x74(r29)
	  lwz       r0, 0x250(r1)
	  stw       r0, 0x78(r29)
	  lwz       r3, 0x23C(r1)
	  lwz       r0, 0x240(r1)
	  stw       r3, 0x94(r29)
	  stw       r0, 0x98(r29)
	  lwz       r0, 0x244(r1)
	  stw       r0, 0x9C(r29)
	  lwz       r0, 0xC8(r29)
	  rlwinm.   r0,r0,0,23,23
	  beq-      .loc_0xB28
	  lfs       f1, 0x98(r29)
	  lfs       f0, 0xD0(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x98(r29)

	.loc_0xB28:
	  lwz       r0, 0x28C(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0xB90
	  lwz       r0, 0x290(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0xB80
	  lwz       r3, 0x280(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0xB54
	  lwz       r3, 0x28(r3)
	  b         .loc_0xB58

	.loc_0xB54:
	  li        r3, 0

	.loc_0xB58:
	  cmplwi    r3, 0
	  beq-      .loc_0xB6C
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x26
	  bne-      .loc_0xB80

	.loc_0xB6C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl

	.loc_0xB80:
	  lwz       r0, 0xC8(r29)
	  ori       r0, r0, 0x4
	  stw       r0, 0xC8(r29)
	  b         .loc_0xD20

	.loc_0xB90:
	  lwz       r0, 0xC8(r29)
	  rlwinm    r0,r0,0,30,28
	  stw       r0, 0xC8(r29)
	  lwz       r4, 0x290(r29)
	  cmplwi    r4, 0
	  beq-      .loc_0xD20
	  lfs       f2, 0x94(r29)
	  li        r0, -0x1
	  lfs       f3, 0x28(r4)
	  lfs       f1, 0x2C(r4)
	  lfs       f0, 0x98(r29)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x30(r4)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x9C(r29)
	  lfs       f0, 0x34(r4)
	  fmuls     f3, f4, f3
	  lfs       f5, -0x74F4(r2)
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f5
	  cror      2, 0, 0x2
	  bne-      .loc_0xBF8
	  lha       r0, 0x12(r4)
	  fmr       f5, f0

	.loc_0xBF8:
	  lfs       f2, 0x94(r29)
	  lfs       f3, 0x38(r4)
	  lfs       f1, 0x3C(r4)
	  lfs       f0, 0x98(r29)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x40(r4)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x9C(r29)
	  lfs       f0, 0x44(r4)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f5
	  cror      2, 0, 0x2
	  bne-      .loc_0xC40
	  lha       r0, 0x14(r4)
	  fmr       f5, f0

	.loc_0xC40:
	  lfs       f2, 0x94(r29)
	  lfs       f3, 0x48(r4)
	  lfs       f1, 0x4C(r4)
	  lfs       f0, 0x98(r29)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x50(r4)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x9C(r29)
	  lfs       f0, 0x54(r4)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f5
	  cror      2, 0, 0x2
	  bne-      .loc_0xC84
	  lha       r0, 0x16(r4)

	.loc_0xC84:
	  cmpwi     r0, 0
	  bge-      .loc_0xCA4
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xB0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xD20

	.loc_0xCA4:
	  lwz       r3, 0x2F80(r13)
	  addi      r5, r4, 0x18
	  lwz       r4, 0x2F00(r13)
	  mulli     r0, r0, 0x58
	  lfs       f0, -0x74EC(r2)
	  lfs       f1, 0xE0(r3)
	  lwz       r4, 0x60(r4)
	  fdivs     f0, f1, f0
	  lfs       f1, -0x74F0(r2)
	  lwz       r3, 0x16C(r4)
	  lfs       f4, 0x0(r5)
	  add       r3, r3, r0
	  lfs       f5, 0x18(r3)
	  fmuls     f1, f1, f0
	  lfs       f2, 0x4(r5)
	  lfs       f3, 0x1C(r3)
	  fmuls     f4, f5, f4
	  lfs       f5, 0x20(r3)
	  fmuls     f0, f3, f2
	  lfs       f2, 0x8(r5)
	  fmuls     f2, f5, f2
	  fadds     f0, f4, f0
	  fadds     f27, f2, f0
	  bl        0x18C878
	  fcmpo     cr0, f27, f1
	  bge-      .loc_0xD20
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xB0(r12)
	  mtlr      r12
	  blrl

	.loc_0xD20:
	  lwz       r0, 0x28C(r29)
	  stw       r0, 0x290(r29)

	.loc_0xD28:
	  lwz       r0, 0x434(r1)
	  lfd       f31, 0x428(r1)
	  lfd       f30, 0x420(r1)
	  lfd       f29, 0x418(r1)
	  lfd       f28, 0x410(r1)
	  lfd       f27, 0x408(r1)
	  lfd       f26, 0x400(r1)
	  lwz       r31, 0x3FC(r1)
	  lwz       r30, 0x3F8(r1)
	  lwz       r29, 0x3F4(r1)
	  lwz       r28, 0x3F0(r1)
	  addi      r1, r1, 0x430
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002E8
 */
void Creature::checkForward(Vector3f&, f32, f32&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
void Creature::getNextTri(CollTriInfo*, Vector3f&, int&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008F33C
 * Size:	000100
 */
void Creature::getNearestPlane(CollTriInfo*)
{
	/*
	.loc_0x0:
	  lfs       f2, 0x94(r3)
	  li        r0, -0x1
	  lfs       f3, 0x28(r4)
	  lfs       f1, 0x2C(r4)
	  lfs       f0, 0x98(r3)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x30(r4)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x9C(r3)
	  lfs       f0, 0x34(r4)
	  fmuls     f3, f4, f3
	  lfs       f5, -0x74F4(r2)
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f5
	  cror      2, 0, 0x2
	  bne-      .loc_0x50
	  li        r0, 0
	  fmr       f5, f0

	.loc_0x50:
	  lfs       f2, 0x94(r3)
	  addi      r6, r4, 0x10
	  lfs       f3, 0x38(r4)
	  lfs       f0, 0x98(r3)
	  lfs       f1, 0x3C(r4)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x40(r4)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x9C(r3)
	  lfs       f0, 0x44(r4)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f5
	  cror      2, 0, 0x2
	  bne-      .loc_0x9C
	  li        r0, 0x1
	  fmr       f5, f0

	.loc_0x9C:
	  lfs       f2, 0x94(r3)
	  lfs       f3, 0x38(r6)
	  lfs       f0, 0x98(r3)
	  lfs       f1, 0x3C(r6)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x40(r6)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x9C(r3)
	  lfs       f0, 0x44(r6)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f5
	  cror      2, 0, 0x2
	  bne-      .loc_0xE0
	  li        r0, 0x2

	.loc_0xE0:
	  cmpwi     r0, -0x1
	  beq-      .loc_0xF8
	  rlwinm    r3,r0,4,0,27
	  addi      r3, r3, 0x28
	  add       r3, r4, r3
	  blr

	.loc_0xF8:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void Creature::renderCollTriInfo(Graphics&, CollTriInfo*, Colour&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8008F43C
 * Size:	000588
 */
void traceMove2(Creature*, MoveTrace&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stfd      f31, 0xD0(r1)
	  stfd      f30, 0xC8(r1)
	  stfd      f29, 0xC0(r1)
	  stfd      f28, 0xB8(r1)
	  fmr       f28, f1
	  stw       r31, 0xB4(r1)
	  li        r31, 0x1
	  stw       r30, 0xB0(r1)
	  stw       r29, 0xAC(r1)
	  mr        r29, r4
	  stw       r28, 0xA8(r1)
	  mr        r28, r3
	  li        r3, 0
	  lfs       f2, 0xC(r4)
	  lfs       f1, 0x10(r4)
	  fmuls     f2, f2, f2
	  lfs       f3, 0x14(r4)
	  fmuls     f1, f1, f1
	  lfs       f0, -0x7510(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xC4
	  fsqrte    f1, f4
	  lfd       f3, -0x74E8(r2)
	  lfd       f2, -0x74E0(r2)
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
	  stfs      f0, 0x38(r1)
	  lfs       f4, 0x38(r1)

	.loc_0xC4:
	  fmuls     f2, f28, f4
	  lfs       f1, -0x750C(r2)
	  b         .loc_0xDC

	.loc_0xD0:
	  fmuls     f2, f2, f1
	  rlwinm    r31,r31,1,0,30
	  addi      r3, r3, 0x1

	.loc_0xDC:
	  cmpwi     r3, 0x64
	  bge-      .loc_0xF4
	  lfs       f0, 0x18(r29)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  beq+      .loc_0xD0

	.loc_0xF4:
	  cmpwi     r3, 0x32
	  ble-      .loc_0x180
	  lfs       f1, 0xC(r29)
	  lfs       f0, 0x10(r29)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x14(r29)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x7510(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x180
	  fsqrte    f1, f4
	  lfd       f3, -0x74E8(r2)
	  lfd       f2, -0x74E0(r2)
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
	  stfs      f0, 0x34(r1)
	  lfs       f4, 0x34(r1)

	.loc_0x180:
	  lwz       r4, 0x2F00(r13)
	  xoris     r0, r31, 0x8000
	  stw       r0, 0xA4(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x10C(r4)
	  stw       r0, 0xA0(r1)
	  li        r30, 0
	  addi      r0, r3, 0x1
	  stw       r0, 0x10C(r4)
	  lfd       f0, 0xA0(r1)
	  lfd       f1, -0x74D0(r2)
	  lfs       f2, -0x7508(r2)
	  fsubs     f0, f0, f1
	  fdivs     f0, f2, f0
	  stfs      f0, 0x1C(r29)
	  lfs       f29, -0x7510(r2)
	  lfs       f30, -0x74D8(r2)
	  lfs       f31, -0x74D4(r2)
	  b         .loc_0x550

	.loc_0x1CC:
	  stfs      f29, 0x7C(r1)
	  stfs      f29, 0x78(r1)
	  stfs      f29, 0x74(r1)
	  stfs      f29, 0x88(r1)
	  stfs      f29, 0x84(r1)
	  stfs      f29, 0x80(r1)
	  lfs       f1, -0x5C88(r13)
	  lfs       f0, -0x5C84(r13)
	  stfs      f1, 0x74(r1)
	  stfs      f0, 0x78(r1)
	  lfs       f0, -0x5C80(r13)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, -0x5C7C(r13)
	  stfs      f0, 0x80(r1)
	  lfs       f0, -0x5C78(r13)
	  stfs      f0, 0x84(r1)
	  lfs       f0, -0x5C74(r13)
	  stfs      f0, 0x88(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x74(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x228
	  stfs      f1, 0x74(r1)

	.loc_0x228:
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x78(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x23C
	  stfs      f1, 0x78(r1)

	.loc_0x23C:
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x7C(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x250
	  stfs      f1, 0x7C(r1)

	.loc_0x250:
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x80(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x264
	  stfs      f1, 0x80(r1)

	.loc_0x264:
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x84(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x278
	  stfs      f1, 0x84(r1)

	.loc_0x278:
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x88(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x28C
	  stfs      f1, 0x88(r1)

	.loc_0x28C:
	  lfs       f0, 0x18(r29)
	  li        r4, 0
	  lfs       f1, 0x74(r1)
	  fmuls     f2, f30, f0
	  fmuls     f0, f31, f0
	  fsubs     f1, f1, f2
	  stfs      f1, 0x74(r1)
	  lfs       f1, 0x78(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x7C(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x18(r29)
	  lfs       f1, 0x80(r1)
	  fmuls     f2, f30, f0
	  fmuls     f0, f31, f0
	  fadds     f1, f1, f2
	  stfs      f1, 0x80(r1)
	  lfs       f1, 0x84(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x84(r1)
	  lfs       f0, 0x88(r1)
	  fadds     f0, f0, f2
	  stfs      f0, 0x88(r1)
	  stw       r28, 0x24(r29)
	  lwz       r3, 0x2F00(r13)
	  lwz       r3, 0x88(r3)
	  lwz       r7, 0x10(r3)
	  b         .loc_0x41C

	.loc_0x304:
	  lwz       r0, 0x28(r7)
	  cmplwi    r0, 0
	  beq-      .loc_0x318
	  cmplw     r0, r28
	  beq-      .loc_0x418

	.loc_0x318:
	  lfs       f1, 0x44(r7)
	  lfs       f0, 0x80(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x398
	  lfs       f1, 0x50(r7)
	  lfs       f0, 0x74(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x398
	  lfs       f1, 0x48(r7)
	  lfs       f0, 0x84(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x398
	  lfs       f1, 0x54(r7)
	  lfs       f0, 0x78(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x398
	  lfs       f1, 0x4C(r7)
	  lfs       f0, 0x88(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x398
	  lfs       f1, 0x58(r7)
	  lfs       f0, 0x7C(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x398
	  li        r0, 0x1
	  b         .loc_0x39C

	.loc_0x398:
	  li        r0, 0

	.loc_0x39C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x418
	  li        r8, 0
	  li        r6, 0
	  b         .loc_0x40C

	.loc_0x3B0:
	  lwz       r3, 0x40(r7)
	  lwz       r5, 0x38(r7)
	  lwzx      r3, r3, r6
	  lwz       r0, 0x18(r3)
	  lbzx      r0, r5, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x404
	  lwz       r0, 0x2C(r7)
	  stw       r0, 0x10(r3)
	  lwz       r3, 0x40(r7)
	  lwz       r0, 0x30(r7)
	  lwzx      r3, r3, r6
	  stw       r0, 0x14(r3)
	  lwz       r3, 0x40(r7)
	  lwzx      r3, r3, r6
	  stw       r7, 0x1C(r3)
	  lwz       r3, 0x40(r7)
	  lwzx      r3, r3, r6
	  stw       r4, 0x20(r3)
	  lwz       r3, 0x40(r7)
	  lwzx      r4, r3, r6

	.loc_0x404:
	  addi      r6, r6, 0x4
	  addi      r8, r8, 0x1

	.loc_0x40C:
	  lwz       r0, 0x3C(r7)
	  cmpw      r8, r0
	  blt+      .loc_0x3B0

	.loc_0x418:
	  lwz       r7, 0xC(r7)

	.loc_0x41C:
	  cmplwi    r7, 0
	  bne+      .loc_0x304
	  lwz       r3, 0x2F00(r13)
	  lfs       f3, 0x0(r29)
	  lwz       r7, 0x60(r3)
	  lfs       f1, 0x8(r29)
	  lfs       f2, 0x140(r7)
	  lfs       f0, 0x148(r7)
	  fsubs     f2, f3, f2
	  lfs       f3, 0x158(r7)
	  fsubs     f0, f1, f0
	  fdivs     f1, f2, f3
	  fctiwz    f1, f1
	  fdivs     f0, f0, f3
	  stfd      f1, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stfd      f1, 0xA0(r1)
	  cmpwi     r0, 0
	  fctiwz    f0, f0
	  lwz       r5, 0xA4(r1)
	  stfd      f0, 0x98(r1)
	  lwz       r3, 0x9C(r1)
	  blt-      .loc_0x498
	  cmpwi     r3, 0
	  blt-      .loc_0x498
	  lwz       r6, 0x15C(r7)
	  cmpw      r5, r6
	  bge-      .loc_0x498
	  lwz       r0, 0x160(r7)
	  cmpw      r3, r0
	  blt-      .loc_0x4A0

	.loc_0x498:
	  li        r5, 0
	  b         .loc_0x4B4

	.loc_0x4A0:
	  mullw     r0, r3, r6
	  lwz       r3, 0x164(r7)
	  add       r0, r5, r0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r5, r3, r0

	.loc_0x4B4:
	  cmplwi    r5, 0
	  beq-      .loc_0x4EC
	  lha       r0, 0x4(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x4EC
	  stw       r7, 0x10(r5)
	  li        r0, 0
	  lwz       r3, 0x2F00(r13)
	  lwz       r3, 0x60(r3)
	  lwz       r3, 0x23C(r3)
	  stw       r3, 0x14(r5)
	  stw       r0, 0x1C(r5)
	  stw       r4, 0x20(r5)
	  mr        r4, r5

	.loc_0x4EC:
	  cmplwi    r4, 0
	  beq-      .loc_0x508
	  fmr       f1, f28
	  lwz       r3, 0x2F00(r13)
	  mr        r5, r29
	  bl        -0x2731C
	  b         .loc_0x54C

	.loc_0x508:
	  lfs       f0, 0x1C(r29)
	  lfs       f2, 0xC(r29)
	  fmuls     f1, f28, f0
	  lfs       f3, 0x10(r29)
	  lfs       f4, 0x14(r29)
	  lfs       f0, 0x0(r29)
	  fmuls     f2, f2, f1
	  fmuls     f3, f3, f1
	  fmuls     f4, f4, f1
	  fadds     f0, f0, f2
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x4(r29)
	  fadds     f0, f0, f3
	  stfs      f0, 0x4(r29)
	  lfs       f0, 0x8(r29)
	  fadds     f0, f0, f4
	  stfs      f0, 0x8(r29)

	.loc_0x54C:
	  addi      r30, r30, 0x1

	.loc_0x550:
	  cmpw      r30, r31
	  blt+      .loc_0x1CC
	  lwz       r0, 0xDC(r1)
	  lfd       f31, 0xD0(r1)
	  lfd       f30, 0xC8(r1)
	  lfd       f29, 0xC0(r1)
	  lfd       f28, 0xB8(r1)
	  lwz       r31, 0xB4(r1)
	  lwz       r30, 0xB0(r1)
	  lwz       r29, 0xAC(r1)
	  lwz       r28, 0xA8(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}
