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
 * Address:	8008D954
 * Size:	000768
 */
void Creature::respondColl(Creature*, f32, CollPart*, CollPart*, const Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x180(r1)
	  stfd      f31, 0x178(r1)
	  stfd      f30, 0x170(r1)
	  stfd      f29, 0x168(r1)
	  stfd      f28, 0x160(r1)
	  stfd      f27, 0x158(r1)
	  stfd      f26, 0x150(r1)
	  stmw      r27, 0x13C(r1)
	  mr        r29, r3
	  addi      r30, r4, 0
	  addi      r27, r5, 0
	  addi      r28, r6, 0
	  addi      r31, r7, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x73C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x98(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x73C
	  stw       r29, 0x128(r1)
	  addi      r3, r30, 0
	  addi      r4, r1, 0x128
	  stw       r30, 0x11C(r1)
	  stw       r27, 0x12C(r1)
	  stw       r28, 0x120(r1)
	  stw       r28, 0x130(r1)
	  stw       r27, 0x124(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r1, 0x11C
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x94(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x73C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x94(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x100
	  b         .loc_0x73C

	.loc_0x100:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x84(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x73C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x84(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x13C
	  b         .loc_0x73C

	.loc_0x13C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x73C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x178
	  b         .loc_0x73C

	.loc_0x178:
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0x33
	  beq-      .loc_0x73C
	  lwz       r3, 0x6C(r29)
	  cmpwi     r3, 0x33
	  beq-      .loc_0x73C
	  cmpwi     r0, 0x33
	  beq-      .loc_0x73C
	  cmpwi     r3, 0
	  bne-      .loc_0x1B8
	  mr        r3, r29
	  bl        0x3AA5C
	  cmpwi     r3, 0xE
	  bne-      .loc_0x1B8
	  lwz       r3, 0x6C(r30)
	  bl        0x6F30

	.loc_0x1B8:
	  lfs       f0, 0x0(r31)
	  stfs      f0, 0x110(r1)
	  lfs       f0, 0x4(r31)
	  stfs      f0, 0x114(r1)
	  lfs       f0, 0x8(r31)
	  stfs      f0, 0x118(r1)
	  lfs       f1, 0x110(r1)
	  lfs       f0, 0x114(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x118(r1)
	  fmuls     f0, f0, f0
	  lfs       f3, -0x7528(r2)
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fcmpu     cr0, f3, f0
	  bne-      .loc_0x224
	  fmr       f28, f3
	  fmr       f1, f28
	  bl        0x18DFFC
	  fmr       f27, f1
	  fmr       f1, f28
	  bl        0x18E184
	  stfs      f1, 0x110(r1)
	  lfs       f0, -0x5CD0(r13)
	  stfs      f0, 0x114(r1)
	  stfs      f27, 0x118(r1)

	.loc_0x224:
	  lfs       f3, 0x70(r29)
	  mr        r3, r29
	  lfs       f2, 0x70(r30)
	  lfs       f1, 0x74(r29)
	  lfs       f0, 0x74(r30)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x110(r1)
	  fsubs     f0, f1, f0
	  lfs       f29, 0x114(r1)
	  lfs       f5, 0x78(r29)
	  lfs       f4, 0x78(r30)
	  fmuls     f1, f3, f2
	  fmuls     f0, f0, f29
	  lwz       r12, 0x0(r29)
	  fsubs     f2, f5, f4
	  lfs       f30, 0x118(r1)
	  lwz       r12, 0x38(r12)
	  fmuls     f2, f2, f30
	  mtlr      r12
	  fadds     f0, f1, f0
	  fadds     f27, f2, f0
	  blrl
	  lwz       r12, 0x0(r30)
	  fmr       f31, f1
	  mr        r3, r30
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  fadds     f2, f31, f1
	  lfs       f0, -0x7524(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x2AC
	  lfs       f31, -0x7520(r2)
	  fmr       f1, f31

	.loc_0x2AC:
	  lfs       f6, 0x110(r1)
	  fmuls     f0, f29, f29
	  lfs       f4, -0x751C(r2)
	  fmuls     f3, f30, f30
	  fmuls     f2, f6, f6
	  fneg      f5, f4
	  fadds     f4, f31, f1
	  addi      r6, r1, 0x60
	  fadds     f2, f2, f0
	  fneg      f0, f1
	  fmuls     f5, f5, f27
	  fadds     f1, f3, f2
	  addi      r5, r1, 0x5C
	  fmuls     f1, f4, f1
	  fdivs     f5, f5, f1
	  fmuls     f3, f6, f5
	  fmuls     f2, f29, f5
	  fmuls     f1, f30, f5
	  stfs      f3, 0x110(r1)
	  stfs      f2, 0x114(r1)
	  stfs      f1, 0x118(r1)
	  lfs       f1, 0x110(r1)
	  stfs      f1, 0xF0(r1)
	  lfs       f1, 0x114(r1)
	  stfs      f1, 0xF4(r1)
	  lfs       f1, 0x118(r1)
	  stfs      f1, 0xF8(r1)
	  lfs       f1, 0xF0(r1)
	  lfs       f2, 0xF4(r1)
	  fmuls     f1, f1, f31
	  lfs       f3, 0xF8(r1)
	  fmuls     f4, f2, f31
	  fmuls     f2, f3, f31
	  stfs      f1, 0xF0(r1)
	  stfs      f4, 0xF4(r1)
	  stfs      f2, 0xF8(r1)
	  lfs       f2, 0x70(r29)
	  lfs       f1, 0xF0(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0x98(r1)
	  lfs       f1, 0x98(r1)
	  stfs      f1, 0xC8(r1)
	  lfs       f2, 0x74(r29)
	  lfs       f1, 0xF4(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xCC(r1)
	  lfs       f2, 0x78(r29)
	  lfs       f1, 0xF8(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xD0(r1)
	  lwz       r3, 0xC8(r1)
	  lwz       r0, 0xCC(r1)
	  stw       r3, 0x70(r29)
	  stw       r0, 0x74(r29)
	  lwz       r0, 0xD0(r1)
	  stw       r0, 0x78(r29)
	  lwz       r0, 0x110(r1)
	  lwz       r3, 0x114(r1)
	  stw       r0, 0xF0(r1)
	  lwz       r0, 0x118(r1)
	  stw       r3, 0xF4(r1)
	  stw       r0, 0xF8(r1)
	  lfs       f1, 0xF0(r1)
	  lfs       f2, 0xF4(r1)
	  fmuls     f1, f1, f0
	  lfs       f3, 0xF8(r1)
	  fmuls     f2, f2, f0
	  fmuls     f0, f3, f0
	  stfs      f1, 0xF0(r1)
	  stfs      f2, 0xF4(r1)
	  stfs      f0, 0xF8(r1)
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0xF0(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x8C(r1)
	  stfs      f0, 0xBC(r1)
	  lfs       f1, 0x74(r30)
	  lfs       f0, 0xF4(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lfs       f1, 0x78(r30)
	  lfs       f0, 0xF8(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC4(r1)
	  lwz       r3, 0xBC(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r3, 0x70(r30)
	  stw       r0, 0x74(r30)
	  lwz       r0, 0xC4(r1)
	  stw       r0, 0x78(r30)
	  lfs       f0, 0x8(r31)
	  lfs       f1, -0x5CCC(r13)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x4(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x0(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x58(r1)
	  addi      r4, r1, 0x58
	  addi      r3, r1, 0xB0
	  bl        -0x56C80
	  lfs       f31, 0xB0(r1)
	  lfs       f30, 0xB4(r1)
	  fmuls     f1, f31, f31
	  lfs       f29, 0xB8(r1)
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x80180
	  fmr       f27, f1
	  lfs       f0, -0x7528(r2)
	  fcmpu     cr0, f0, f27
	  beq-      .loc_0x48C
	  fdivs     f31, f31, f27
	  fdivs     f30, f30, f27
	  fdivs     f29, f29, f27

	.loc_0x48C:
	  lfs       f0, -0x7528(r2)
	  fcmpo     cr0, f27, f0
	  ble-      .loc_0x734
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  fmr       f28, f1
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  fadds     f26, f1, f28
	  lfs       f0, -0x7528(r2)
	  fcmpo     cr0, f26, f0
	  ble-      .loc_0x4F8
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  fdivs     f28, f1, f26
	  lfs       f0, -0x7518(r2)
	  fsubs     f26, f0, f28
	  b         .loc_0x500

	.loc_0x4F8:
	  lfs       f26, -0x7514(r2)
	  fmr       f28, f26

	.loc_0x500:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x8C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x544
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x8C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x544
	  lfs       f28, -0x7528(r2)
	  lfs       f26, -0x7518(r2)
	  b         .loc_0x5C8

	.loc_0x544:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x8C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x588
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x8C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x588
	  lfs       f28, -0x7518(r2)
	  lfs       f26, -0x7528(r2)
	  b         .loc_0x5C8

	.loc_0x588:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x8C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5C8
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x8C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x5C8
	  lfs       f26, -0x7528(r2)
	  fmr       f28, f26

	.loc_0x5C8:
	  lwz       r3, 0x2DEC(r13)
	  fmuls     f1, f27, f28
	  fmuls     f0, f27, f26
	  lwz       r0, 0x6C(r29)
	  lfs       f2, 0x28C(r3)
	  cmpwi     r0, 0x36
	  fdivs     f5, f1, f2
	  fdivs     f6, f0, f2
	  beq-      .loc_0x61C
	  fmuls     f2, f5, f31
	  lfs       f3, -0x7514(r2)
	  fmuls     f1, f5, f29
	  fmuls     f0, f5, f30
	  fmuls     f2, f3, f2
	  fmuls     f1, f3, f1
	  stfs      f2, 0xBC(r29)
	  stfs      f1, 0xC4(r29)
	  lfs       f1, -0x7528(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xC0(r29)
	  b         .loc_0x660

	.loc_0x61C:
	  fmuls     f2, f5, f31
	  lfs       f3, -0x7514(r2)
	  fmuls     f1, f5, f29
	  lfs       f4, 0xBC(r29)
	  fmuls     f0, f5, f30
	  fmuls     f2, f3, f2
	  fmuls     f1, f3, f1
	  fadds     f2, f4, f2
	  stfs      f2, 0xBC(r29)
	  lfs       f2, 0xC4(r29)
	  fadds     f1, f2, f1
	  stfs      f1, 0xC4(r29)
	  lfs       f1, -0x7528(r2)
	  lfs       f2, 0xC0(r29)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xC0(r29)

	.loc_0x660:
	  lwz       r0, 0x6C(r30)
	  cmpwi     r0, 0x36
	  beq-      .loc_0x6A0
	  fneg      f0, f6
	  lfs       f3, -0x7514(r2)
	  fmuls     f2, f0, f31
	  fmuls     f1, f0, f29
	  fmuls     f0, f0, f30
	  fmuls     f2, f3, f2
	  fmuls     f1, f3, f1
	  stfs      f2, 0xBC(r30)
	  stfs      f1, 0xC4(r30)
	  lfs       f1, -0x7528(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xC0(r30)
	  b         .loc_0x6E8

	.loc_0x6A0:
	  fneg      f0, f6
	  lfs       f3, -0x7514(r2)
	  lfs       f4, 0xBC(r30)
	  fmuls     f2, f0, f31
	  fmuls     f1, f0, f29
	  fmuls     f0, f0, f30
	  fmuls     f2, f3, f2
	  fmuls     f1, f3, f1
	  fadds     f2, f4, f2
	  stfs      f2, 0xBC(r30)
	  lfs       f2, 0xC4(r30)
	  fadds     f1, f2, f1
	  stfs      f1, 0xC4(r30)
	  lfs       f1, -0x7528(r2)
	  lfs       f2, 0xC0(r30)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xC0(r30)

	.loc_0x6E8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x8C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x70C
	  li        r0, 0x1
	  stw       r0, 0x1A4(r29)

	.loc_0x70C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x8C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x73C
	  li        r0, 0x1
	  stw       r0, 0x1A4(r30)
	  b         .loc_0x73C

	.loc_0x734:
	  li        r0, 0
	  stw       r0, 0x1A4(r29)

	.loc_0x73C:
	  lmw       r27, 0x13C(r1)
	  lwz       r0, 0x184(r1)
	  lfd       f31, 0x178(r1)
	  lfd       f30, 0x170(r1)
	  lfd       f29, 0x168(r1)
	  lfd       f28, 0x160(r1)
	  lfd       f27, 0x158(r1)
	  lfd       f26, 0x150(r1)
	  addi      r1, r1, 0x180
	  mtlr      r0
	  blr
	*/
}
