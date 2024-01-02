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
 * Address:	8015FCA8
 * Size:	000220
 */
void SnakeBody::setBodyOnGroundEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x80
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r3
	  lwz       r0, 0x0(r3)
	  lwz       r3, 0x884(r3)
	  stw       r0, 0x4(r3)
	  lwz       r5, 0x0(r31)
	  lwz       r3, 0x3180(r13)
	  lwz       r6, 0x884(r31)
	  addi      r5, r5, 0x94
	  bl        0x3CE58
	  cmplwi    r3, 0
	  beq-      .loc_0x50
	  lwz       r4, 0x0(r31)
	  addi      r0, r4, 0x94
	  stw       r0, 0x18(r3)

	.loc_0x50:
	  lwz       r0, 0x0(r31)
	  li        r4, 0x81
	  lwz       r3, 0x888(r31)
	  li        r7, 0
	  stw       r0, 0x4(r3)
	  lwz       r5, 0x0(r31)
	  lwz       r3, 0x3180(r13)
	  lwz       r6, 0x888(r31)
	  addi      r5, r5, 0x94
	  bl        0x3CE1C
	  cmplwi    r3, 0
	  beq-      .loc_0x8C
	  lwz       r4, 0x0(r31)
	  addi      r0, r4, 0x94
	  stw       r0, 0x18(r3)

	.loc_0x8C:
	  lwz       r3, 0x0(r31)
	  addi      r4, r3, 0x94
	  bl        -0x109CC
	  cmpwi     r3, 0x5
	  bne-      .loc_0x20C
	  lwz       r5, 0x0(r31)
	  li        r4, 0x55
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x3CDD8
	  lwz       r5, 0x0(r31)
	  li        r4, 0xE
	  lwz       r3, 0x3180(r13)
	  li        r7, 0
	  lwz       r6, 0x884(r31)
	  addi      r5, r5, 0x94
	  bl        0x3CDBC
	  cmplwi    r3, 0
	  beq-      .loc_0x12C
	  lwz       r4, 0x0(r31)
	  addi      r0, r4, 0x94
	  stw       r0, 0x18(r3)
	  lfs       f0, -0x48(r13)
	  lfs       f1, -0x44(r13)
	  stfs      f0, 0x54(r1)
	  lfs       f0, -0x40(r13)
	  stfs      f1, 0x58(r1)
	  stfs      f0, 0x5C(r1)
	  lwz       r4, 0x54(r1)
	  lwz       r0, 0x58(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x5C(r1)
	  stw       r0, 0x1E4(r3)
	  lfs       f1, -0x5550(r2)
	  lfs       f0, 0xF0(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xF0(r3)

	.loc_0x12C:
	  lwz       r5, 0x0(r31)
	  li        r4, 0xC
	  lwz       r3, 0x3180(r13)
	  li        r7, 0
	  lwz       r6, 0x884(r31)
	  addi      r5, r5, 0x94
	  bl        0x3CD4C
	  cmplwi    r3, 0
	  beq-      .loc_0x19C
	  lwz       r4, 0x0(r31)
	  addi      r0, r4, 0x94
	  stw       r0, 0x18(r3)
	  lfs       f0, -0x3C(r13)
	  lfs       f1, -0x38(r13)
	  stfs      f0, 0x48(r1)
	  lfs       f0, -0x34(r13)
	  stfs      f1, 0x4C(r1)
	  stfs      f0, 0x50(r1)
	  lwz       r4, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x50(r1)
	  stw       r0, 0x1E4(r3)
	  lfs       f1, -0x5550(r2)
	  lfs       f0, 0xF0(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xF0(r3)

	.loc_0x19C:
	  lwz       r5, 0x0(r31)
	  li        r4, 0xD
	  lwz       r3, 0x3180(r13)
	  li        r7, 0
	  lwz       r6, 0x884(r31)
	  addi      r5, r5, 0x94
	  bl        0x3CCDC
	  cmplwi    r3, 0
	  beq-      .loc_0x20C
	  lwz       r4, 0x0(r31)
	  addi      r0, r4, 0x94
	  stw       r0, 0x18(r3)
	  lfs       f0, -0x30(r13)
	  lfs       f1, -0x2C(r13)
	  stfs      f0, 0x3C(r1)
	  lfs       f0, -0x28(r13)
	  stfs      f1, 0x40(r1)
	  stfs      f0, 0x44(r1)
	  lwz       r4, 0x3C(r1)
	  lwz       r0, 0x40(r1)
	  stw       r4, 0x1DC(r3)
	  stw       r0, 0x1E0(r3)
	  lwz       r0, 0x44(r1)
	  stw       r0, 0x1E4(r3)
	  lfs       f1, -0x5550(r2)
	  lfs       f0, 0xF0(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xF0(r3)

	.loc_0x20C:
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015FEC8
 * Size:	000068
 */
void SnakeBody::killCallBackEffect(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  addi      r6, r31, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x3180(r13)
	  lwz       r0, 0x884(r30)
	  addi      r3, r3, 0x14
	  mr        r4, r0
	  bl        0x41760
	  lwz       r3, 0x3180(r13)
	  mr        r6, r31
	  lwz       r4, 0x888(r30)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x41748
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
 * Address:	8015FF30
 * Size:	000158
 */
SnakeBody::SnakeBody(Snake*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r6, 0xC
	  li        r7, 0x8
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x8003
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0x5B24
	  addi      r3, r31, 0x5C
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  addi      r4, r30, 0
	  lfs       f0, -0x554C(r2)
	  stfs      f0, 0x58(r31)
	  stfs      f0, 0x54(r31)
	  stfs      f0, 0x50(r31)
	  bl        0xB4AF4
	  addi      r4, r30, 0
	  addi      r3, r31, 0xBC
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x6
	  bl        0xB4ADC
	  addi      r4, r30, 0
	  addi      r3, r31, 0x104
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x20
	  bl        0xB4AC4
	  lis       r3, 0x8004
	  subi      r30, r3, 0xFE4
	  addi      r4, r30, 0
	  addi      r3, r31, 0x284
	  li        r5, 0
	  li        r6, 0x40
	  li        r7, 0x8
	  bl        0xB4AA4
	  addi      r4, r30, 0
	  addi      r3, r31, 0x484
	  li        r5, 0
	  li        r6, 0x40
	  li        r7, 0x8
	  bl        0xB4A8C
	  addi      r4, r30, 0
	  addi      r3, r31, 0x684
	  li        r5, 0
	  li        r6, 0x40
	  li        r7, 0x8
	  bl        0xB4A74
	  stw       r29, 0x0(r31)
	  li        r3, 0x8
	  bl        -0x119004
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802D
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x4E0
	  stw       r0, 0x0(r3)

	.loc_0xFC:
	  stw       r3, 0x884(r31)
	  li        r3, 0x8
	  bl        -0x119030
	  cmplwi    r3, 0
	  beq-      .loc_0x128
	  lis       r4, 0x802B
	  addi      r0, r4, 0x600
	  lis       r4, 0x802D
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x518
	  stw       r0, 0x0(r3)

	.loc_0x128:
	  stw       r3, 0x888(r31)
	  li        r3, 0x1C
	  bl        -0x11905C
	  stw       r3, 0x88C(r31)
	  mr        r3, r31
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
 * Address:	80160088
 * Size:	00009C
 */
void SnakeBody::init(Vector3f&, Snake*)
{
	/*
	.loc_0x0:
	  stw       r5, 0x0(r3)
	  li        r5, 0
	  li        r0, 0x7
	  stb       r5, 0x4(r3)
	  stb       r5, 0x5(r3)
	  lfs       f0, -0x554C(r2)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x14(r3)
	  lwz       r4, 0x88C(r3)
	  stw       r5, 0x0(r4)
	  stfs      f0, 0x18(r3)
	  lwz       r4, 0x88C(r3)
	  stw       r5, 0x4(r4)
	  stfs      f0, 0x1C(r3)
	  lwz       r4, 0x88C(r3)
	  stw       r5, 0x8(r4)
	  stfs      f0, 0x20(r3)
	  lwz       r4, 0x88C(r3)
	  stw       r5, 0xC(r4)
	  stfs      f0, 0x24(r3)
	  lwz       r4, 0x88C(r3)
	  stw       r5, 0x10(r4)
	  stfs      f0, 0x28(r3)
	  lwz       r4, 0x88C(r3)
	  stw       r5, 0x14(r4)
	  stfs      f0, 0x2C(r3)
	  lwz       r4, 0x88C(r3)
	  stw       r5, 0x18(r4)
	  lfs       f0, -0x5548(r2)
	  stfs      f0, 0x30(r3)
	  stfs      f0, 0x34(r3)
	  stfs      f0, 0x38(r3)
	  stfs      f0, 0x3C(r3)
	  stfs      f0, 0x40(r3)
	  stfs      f0, 0x44(r3)
	  stfs      f0, 0x48(r3)
	  stfs      f0, 0x4C(r3)
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80160124
 * Size:	000028
 */
void SnakeBody::initBlending(f32)
{
	/*
	.loc_0x0:
	  lfs       f2, 0xC(r3)
	  lfs       f0, -0x554C(r2)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x18
	  li        r0, 0x1
	  stb       r0, 0x5(r3)

	.loc_0x18:
	  lfs       f0, -0x5544(r2)
	  stfs      f0, 0xC(r3)
	  stfs      f1, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void SnakeBody::updateBlendingRatio()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void SnakeBody::setInitializePosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void SnakeBody::copyAnimPosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void SnakeBody::makeHeadDirection()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016014C
 * Size:	000318
 */
void SnakeBody::makeTurnVelocity()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1A0(r1)
	  stfd      f31, 0x198(r1)
	  stfd      f30, 0x190(r1)
	  stfd      f29, 0x188(r1)
	  stfd      f28, 0x180(r1)
	  stfd      f27, 0x178(r1)
	  stfd      f26, 0x170(r1)
	  stfd      f25, 0x168(r1)
	  stfd      f24, 0x160(r1)
	  stfd      f23, 0x158(r1)
	  stfd      f22, 0x150(r1)
	  stfd      f21, 0x148(r1)
	  stmw      r26, 0x130(r1)
	  mr        r31, r3
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x2D8
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x2D8
	  lfs       f1, 0x280(r31)
	  addi      r6, r1, 0x58
	  lfs       f0, 0x1F0(r31)
	  addi      r5, r1, 0x54
	  addi      r4, r1, 0x50
	  fadds     f0, f1, f0
	  addi      r3, r1, 0xE4
	  stfs      f0, 0x58(r1)
	  lfs       f1, 0x27C(r31)
	  lfs       f0, 0x1EC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x54(r1)
	  lfs       f1, 0x278(r31)
	  lfs       f0, 0x1E8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x50(r1)
	  bl        -0x1290C8
	  lfs       f1, 0xEC(r1)
	  addi      r6, r1, 0x74
	  lfs       f0, 0x130(r31)
	  addi      r5, r1, 0x70
	  lfs       f2, 0xE8(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0xE4(r1)
	  addi      r4, r1, 0x6C
	  addi      r3, r1, 0xF0
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x12C(r31)
	  fadds     f0, f2, f0
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x128(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x6C(r1)
	  bl        -0x12910C
	  lfs       f1, -0x5548(r2)
	  addi      r6, r1, 0x68
	  lfs       f0, -0x24(r13)
	  addi      r5, r1, 0x64
	  lfs       f2, 0xF8(r1)
	  fdivs     f3, f1, f0
	  lfs       f1, 0xF4(r1)
	  lfs       f0, 0xF0(r1)
	  addi      r4, r1, 0x60
	  addi      r3, r1, 0xFC
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  fmuls     f0, f0, f3
	  stfs      f2, 0x68(r1)
	  stfs      f1, 0x64(r1)
	  stfs      f0, 0x60(r1)
	  bl        -0x129150
	  lwz       r3, 0x0(r31)
	  lfs       f30, 0xFC(r1)
	  addi      r4, r3, 0x30C
	  lfs       f2, 0x30C(r3)
	  lfsu      f3, 0x94(r3)
	  lfs       f0, 0x4(r4)
	  lfs       f1, 0x4(r3)
	  fsubs     f27, f3, f2
	  lfs       f2, 0x8(r3)
	  fsubs     f26, f1, f0
	  lfs       f0, 0x8(r4)
	  fmuls     f1, f27, f27
	  fsubs     f25, f2, f0
	  lfs       f29, 0x100(r1)
	  fmuls     f0, f26, f26
	  lfs       f28, 0x104(r1)
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x15267C
	  lfs       f0, -0x554C(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x18C
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1

	.loc_0x18C:
	  lfs       f31, -0x554C(r2)
	  addi      r30, r31, 0x30
	  lfs       f24, -0x5540(r2)
	  li        r26, 0x1

	.loc_0x19C:
	  lfs       f0, 0x128(r30)
	  subi      r27, r26, 0x1
	  lfs       f1, 0x12C(r30)
	  fsubs     f21, f0, f30
	  lfs       f0, 0x130(r30)
	  fsubs     f22, f1, f29
	  fsubs     f23, f0, f28
	  fmuls     f1, f21, f21
	  fmuls     f0, f22, f22
	  fmuls     f2, f23, f23
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1526D8
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x1E4
	  fdivs     f21, f21, f1
	  fdivs     f22, f22, f1
	  fdivs     f23, f23, f1

	.loc_0x1E4:
	  fadds     f0, f27, f21
	  mulli     r0, r27, 0xC
	  fadds     f2, f26, f22
	  fadds     f1, f25, f23
	  stfs      f0, 0xA4(r1)
	  add       r3, r31, r0
	  lfs       f3, 0xA4(r1)
	  addi      r28, r3, 0xBC
	  lfs       f0, 0x254(r31)
	  addi      r29, r3, 0xC0
	  addi      r27, r3, 0xC4
	  fsubs     f0, f3, f0
	  stfs      f0, 0x98(r1)
	  lfs       f0, 0x98(r1)
	  stfs      f0, 0xCC(r1)
	  lfs       f0, 0x258(r31)
	  fsubs     f0, f2, f0
	  stfs      f0, 0xD0(r1)
	  lfs       f0, 0x25C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xD4(r1)
	  lwz       r3, 0xCC(r1)
	  lwz       r0, 0xD0(r1)
	  stw       r3, 0x0(r28)
	  stw       r0, 0x4(r28)
	  lwz       r0, 0xD4(r1)
	  stw       r0, 0x8(r28)
	  stfs      f31, 0x0(r29)
	  lfs       f1, 0x0(r28)
	  lfs       f0, 0x0(r29)
	  lfs       f2, 0x0(r27)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x152780
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x2A4
	  lfs       f0, 0x0(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r28)
	  lfs       f0, 0x0(r29)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x0(r27)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r27)

	.loc_0x2A4:
	  lfs       f0, 0x0(r28)
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x7
	  fmuls     f0, f0, f24
	  addi      r30, r30, 0x30
	  stfs      f0, 0x0(r28)
	  lfs       f0, 0x0(r29)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x0(r27)
	  fmuls     f0, f0, f24
	  stfs      f0, 0x0(r27)
	  blt+      .loc_0x19C

	.loc_0x2D8:
	  lmw       r26, 0x130(r1)
	  lwz       r0, 0x1A4(r1)
	  lfd       f31, 0x198(r1)
	  lfd       f30, 0x190(r1)
	  lfd       f29, 0x188(r1)
	  lfd       f28, 0x180(r1)
	  lfd       f27, 0x178(r1)
	  lfd       f26, 0x170(r1)
	  lfd       f25, 0x168(r1)
	  lfd       f24, 0x160(r1)
	  lfd       f23, 0x158(r1)
	  lfd       f22, 0x150(r1)
	  lfd       f21, 0x148(r1)
	  addi      r1, r1, 0x1A0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void SnakeBody::makeNewPosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80160464
 * Size:	0002F4
 */
void SnakeBody::makeResultPosition()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  stfd      f30, 0x120(r1)
	  stfd      f29, 0x118(r1)
	  stfd      f28, 0x110(r1)
	  stfd      f27, 0x108(r1)
	  stfd      f26, 0x100(r1)
	  stfd      f25, 0xF8(r1)
	  stfd      f24, 0xF0(r1)
	  stmw      r19, 0xBC(r1)
	  mr        r27, r3
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x2C0
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x2C0
	  lfs       f30, -0x554C(r2)
	  addi      r31, r1, 0x48
	  lfs       f31, -0x553C(r2)
	  li        r30, 0
	  stfs      f30, 0x44(r1)
	  stfs      f30, 0x40(r1)
	  stfs      f30, 0x3C(r1)
	  stfs      f30, 0x50(r1)
	  stfs      f30, 0x4C(r1)
	  stfs      f30, 0x48(r1)
	  stfs      f30, 0x5C(r1)
	  stfs      f30, 0x58(r1)
	  stfs      f30, 0x54(r1)
	  stfs      f30, 0x68(r1)
	  stfs      f30, 0x64(r1)
	  stfs      f30, 0x60(r1)
	  stfs      f30, 0x74(r1)
	  stfs      f30, 0x70(r1)
	  stfs      f30, 0x6C(r1)
	  stfs      f30, 0x80(r1)
	  stfs      f30, 0x7C(r1)
	  stfs      f30, 0x78(r1)
	  stfs      f30, 0x8C(r1)
	  stfs      f30, 0x88(r1)
	  stfs      f30, 0x84(r1)

	.loc_0xB0:
	  addi      r24, r31, 0
	  addi      r26, r27, 0x30
	  addi      r25, r27, 0x4
	  li        r29, 0x1

	.loc_0xC0:
	  subi      r28, r29, 0x1
	  lfs       f4, 0x128(r26)
	  mulli     r0, r28, 0x30
	  lfs       f3, 0x12C(r26)
	  lfs       f1, 0x130(r26)
	  add       r3, r27, r0
	  addi      r23, r3, 0x128
	  addi      r22, r3, 0x12C
	  lfs       f0, 0x128(r3)
	  lfs       f2, 0x12C(r3)
	  addi      r21, r3, 0x130
	  fsubs     f27, f4, f0
	  lfs       f0, 0x130(r3)
	  fsubs     f28, f3, f2
	  fsubs     f29, f1, f0
	  addi      r19, r29, 0x1
	  fmuls     f1, f27, f27
	  fmuls     f0, f28, f28
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x152938
	  fcmpu     cr0, f30, f1
	  beq-      .loc_0x12C
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1
	  fdivs     f29, f29, f1

	.loc_0x12C:
	  mulli     r0, r19, 0x30
	  lfs       f4, 0x128(r26)
	  lfs       f3, 0x12C(r26)
	  lfs       f1, 0x130(r26)
	  add       r3, r27, r0
	  addi      r19, r3, 0x128
	  lfs       f8, 0x0(r23)
	  addi      r23, r3, 0x12C
	  lfs       f0, 0x128(r3)
	  lfs       f2, 0x12C(r3)
	  addi      r20, r3, 0x130
	  fsubs     f24, f4, f0
	  lfs       f0, 0x130(r3)
	  fsubs     f25, f3, f2
	  rlwinm    r3,r28,2,0,29
	  fsubs     f26, f1, f0
	  addi      r0, r3, 0x14
	  fmuls     f1, f24, f24
	  lfsx      f3, r27, r0
	  fmuls     f0, f25, f25
	  fmuls     f2, f26, f26
	  lfs       f6, 0x0(r22)
	  fmuls     f7, f3, f27
	  lfs       f4, 0x0(r21)
	  fmuls     f5, f3, f28
	  fmuls     f3, f3, f29
	  fadds     f0, f1, f0
	  fadds     f29, f8, f7
	  fadds     f28, f6, f5
	  fadds     f27, f4, f3
	  fadds     f1, f2, f0
	  bl        -0x1529CC
	  fcmpu     cr0, f30, f1
	  beq-      .loc_0x1C0
	  fdivs     f24, f24, f1
	  fdivs     f25, f25, f1
	  fdivs     f26, f26, f1

	.loc_0x1C0:
	  lfs       f2, 0x14(r25)
	  addi      r29, r29, 0x1
	  lfs       f1, 0x0(r19)
	  cmpwi     r29, 0x7
	  fmuls     f0, f2, f24
	  fmuls     f4, f2, f25
	  lfs       f5, 0x0(r23)
	  fmuls     f2, f2, f26
	  lfs       f3, 0x0(r20)
	  fadds     f0, f1, f0
	  fadds     f1, f5, f4
	  addi      r26, r26, 0x30
	  fadds     f3, f3, f2
	  addi      r25, r25, 0x4
	  fadds     f2, f29, f0
	  fadds     f1, f28, f1
	  fadds     f0, f27, f3
	  fmuls     f2, f31, f2
	  fmuls     f1, f31, f1
	  fmuls     f0, f31, f0
	  stfs      f2, 0x0(r24)
	  stfs      f1, 0x4(r24)
	  stfs      f0, 0x8(r24)
	  addi      r24, r24, 0xC
	  blt+      .loc_0xC0
	  lfs       f0, 0x48(r1)
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0xA
	  stfs      f0, 0x158(r27)
	  lfs       f0, 0x4C(r1)
	  stfs      f0, 0x15C(r27)
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x160(r27)
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0x188(r27)
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0x18C(r27)
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x190(r27)
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x1B8(r27)
	  lfs       f0, 0x64(r1)
	  stfs      f0, 0x1BC(r27)
	  lfs       f0, 0x68(r1)
	  stfs      f0, 0x1C0(r27)
	  lfs       f0, 0x6C(r1)
	  stfs      f0, 0x1E8(r27)
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0x1EC(r27)
	  lfs       f0, 0x74(r1)
	  stfs      f0, 0x1F0(r27)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x218(r27)
	  lfs       f0, 0x7C(r1)
	  stfs      f0, 0x21C(r27)
	  lfs       f0, 0x80(r1)
	  stfs      f0, 0x220(r27)
	  lfs       f0, 0x84(r1)
	  stfs      f0, 0x248(r27)
	  lfs       f0, 0x88(r1)
	  stfs      f0, 0x24C(r27)
	  lfs       f0, 0x8C(r1)
	  stfs      f0, 0x250(r27)
	  blt+      .loc_0xB0

	.loc_0x2C0:
	  lmw       r19, 0xBC(r1)
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lfd       f30, 0x120(r1)
	  lfd       f29, 0x118(r1)
	  lfd       f28, 0x110(r1)
	  lfd       f27, 0x108(r1)
	  lfd       f26, 0x100(r1)
	  lfd       f25, 0xF8(r1)
	  lfd       f24, 0xF0(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80160758
 * Size:	000368
 */
void SnakeBody::makeVectorMatrix()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r3
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x348
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x348
	  lfs       f31, -0x554C(r2)
	  addi      r31, r29, 0
	  li        r30, 0

	.loc_0x44:
	  cmpwi     r30, 0x7
	  bge-      .loc_0x7C
	  lfs       f1, 0x158(r31)
	  lfs       f0, 0x128(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x104(r31)
	  lfs       f1, 0x15C(r31)
	  lfs       f0, 0x12C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x108(r31)
	  lfs       f1, 0x160(r31)
	  lfs       f0, 0x130(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x10C(r31)

	.loc_0x7C:
	  cmpwi     r30, 0
	  ble-      .loc_0x160
	  lwz       r3, 0xEC(r31)
	  lwz       r0, 0xF0(r31)
	  stw       r3, 0x11C(r31)
	  stw       r0, 0x120(r31)
	  lwz       r0, 0xF4(r31)
	  stw       r0, 0x124(r31)
	  lfs       f3, 0x120(r31)
	  lfs       f2, 0x10C(r31)
	  lfs       f1, 0x124(r31)
	  lfs       f0, 0x108(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x110(r31)
	  lfs       f3, 0x124(r31)
	  lfs       f2, 0x104(r31)
	  lfs       f1, 0x11C(r31)
	  lfs       f0, 0x10C(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x114(r31)
	  lfs       f3, 0x11C(r31)
	  lfs       f2, 0x108(r31)
	  lfs       f1, 0x120(r31)
	  lfs       f0, 0x104(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x118(r31)
	  lfs       f3, 0x108(r31)
	  lfs       f2, 0x118(r31)
	  lfs       f1, 0x10C(r31)
	  lfs       f0, 0x114(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x11C(r31)
	  lfs       f3, 0x10C(r31)
	  lfs       f2, 0x110(r31)
	  lfs       f1, 0x104(r31)
	  lfs       f0, 0x118(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x120(r31)
	  lfs       f3, 0x104(r31)
	  lfs       f2, 0x114(r31)
	  lfs       f1, 0x108(r31)
	  lfs       f0, 0x110(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x124(r31)
	  b         .loc_0x248

	.loc_0x160:
	  lwz       r3, 0x0(r29)
	  lfs       f1, 0xA0(r3)
	  bl        0xBB294
	  stfs      f1, 0x11C(r31)
	  stfs      f31, 0x120(r31)
	  lwz       r3, 0x0(r29)
	  lfs       f1, 0xA0(r3)
	  bl        0xBB414
	  fneg      f0, f1
	  stfs      f0, 0x124(r31)
	  lfs       f3, 0x120(r31)
	  lfs       f2, 0x10C(r31)
	  lfs       f1, 0x124(r31)
	  lfs       f0, 0x108(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x110(r31)
	  lfs       f3, 0x124(r31)
	  lfs       f2, 0x104(r31)
	  lfs       f1, 0x11C(r31)
	  lfs       f0, 0x10C(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x114(r31)
	  lfs       f3, 0x11C(r31)
	  lfs       f2, 0x108(r31)
	  lfs       f1, 0x120(r31)
	  lfs       f0, 0x104(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x118(r31)
	  lfs       f3, 0x108(r31)
	  lfs       f2, 0x118(r31)
	  lfs       f1, 0x10C(r31)
	  lfs       f0, 0x114(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x11C(r31)
	  lfs       f3, 0x10C(r31)
	  lfs       f2, 0x110(r31)
	  lfs       f1, 0x104(r31)
	  lfs       f0, 0x118(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x120(r31)
	  lfs       f3, 0x104(r31)
	  lfs       f2, 0x114(r31)
	  lfs       f1, 0x108(r31)
	  lfs       f0, 0x110(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x124(r31)

	.loc_0x248:
	  lfs       f1, 0x104(r31)
	  lfs       f0, 0x108(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x10C(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x152D80
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x298
	  lfs       f0, 0x104(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x104(r31)
	  lfs       f0, 0x108(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x108(r31)
	  lfs       f0, 0x10C(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x10C(r31)

	.loc_0x298:
	  lfs       f1, 0x110(r31)
	  lfs       f0, 0x114(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x118(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x152DD0
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x2E8
	  lfs       f0, 0x110(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x110(r31)
	  lfs       f0, 0x114(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x114(r31)
	  lfs       f0, 0x118(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x118(r31)

	.loc_0x2E8:
	  lfs       f1, 0x11C(r31)
	  lfs       f0, 0x120(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x124(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x152E20
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x338
	  lfs       f0, 0x11C(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x11C(r31)
	  lfs       f0, 0x120(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x120(r31)
	  lfs       f0, 0x124(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x124(r31)

	.loc_0x338:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x8
	  addi      r31, r31, 0x30
	  blt+      .loc_0x44

	.loc_0x348:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void SnakeBody::createDeadPellet(Vector3f&, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80160AC0
 * Size:	000254
 */
void SnakeBody::createDeadHeadEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  lfs       f0, -0x554C(r2)
	  stfs      f0, 0x30(r1)
	  stfs      f0, 0x2C(r1)
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x553C(r2)
	  lwz       r3, 0x0(r3)
	  lfs       f1, 0xA0(r3)
	  fsubs     f31, f1, f0
	  fmr       f1, f31
	  bl        0xBB1E4
	  lwz       r0, 0x8(r31)
	  lfs       f0, -0x5528(r2)
	  mulli     r0, r0, 0xC
	  fmuls     f2, f0, f1
	  fmr       f1, f31
	  add       r3, r31, r0
	  lfs       f0, 0x5C(r3)
	  fadds     f0, f0, f2
	  stfs      f0, 0x28(r1)
	  lwz       r0, 0x8(r31)
	  mulli     r0, r0, 0xC
	  add       r3, r31, r0
	  lfs       f0, 0x60(r3)
	  stfs      f0, 0x2C(r1)
	  bl        0xBB014
	  lwz       r0, 0x8(r31)
	  addi      r5, r1, 0x28
	  lfs       f0, -0x5528(r2)
	  li        r4, 0x84
	  mulli     r0, r0, 0xC
	  fmuls     f1, f0, f1
	  add       r3, r31, r0
	  lfs       f0, 0x64(r3)
	  li        r6, 0
	  li        r7, 0
	  fadds     f0, f0, f1
	  stfs      f0, 0x30(r1)
	  lwz       r3, 0x3180(r13)
	  bl        0x3BFC0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x28
	  li        r4, 0x83
	  li        r6, 0
	  li        r7, 0
	  bl        0x3BFA8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x28
	  li        r4, 0x82
	  li        r6, 0
	  li        r7, 0
	  bl        0x3BF90
	  lwz       r3, 0x3178(r13)
	  addi      r6, r1, 0x28
	  li        r4, 0xE
	  li        r5, 0
	  bl        0x1C218
	  lwz       r4, 0x0(r31)
	  lwz       r3, 0x224(r4)
	  lwz       r30, 0x4F0(r3)
	  cmpwi     r30, 0
	  blt-      .loc_0x1C8
	  lwz       r4, 0x2F8(r4)
	  cmpwi     r4, 0x2
	  bgt-      .loc_0x128
	  cmpwi     r4, 0
	  bge-      .loc_0x16C

	.loc_0x128:
	  bl        0xB7488
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5530(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x5538(r2)
	  stw       r0, 0x40(r1)
	  lfs       f1, -0x5548(r2)
	  lfd       f3, 0x40(r1)
	  lfs       f0, -0x5534(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x38(r1)
	  lwz       r4, 0x3C(r1)

	.loc_0x16C:
	  lwz       r3, 0x301C(r13)
	  mr        r5, r30
	  bl        -0xC86FC
	  mr.       r30, r3
	  beq-      .loc_0x1C8
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r1, 0x28
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x20(r13)
	  mr        r3, r30
	  li        r4, 0
	  stfs      f0, 0x70(r30)
	  lfs       f0, -0x1C(r13)
	  stfs      f0, 0x74(r30)
	  lfs       f0, -0x18(r13)
	  stfs      f0, 0x78(r30)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x1C8:
	  li        r29, 0
	  li        r30, 0

	.loc_0x1D0:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x28
	  li        r4, 0x86
	  li        r6, 0
	  li        r7, 0
	  bl        0x3BE94
	  lwz       r4, 0x88C(r31)
	  stwx      r3, r4, r30
	  lwz       r3, 0x88C(r31)
	  lwzx      r3, r3, r30
	  cmplwi    r3, 0
	  beq-      .loc_0x20C
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x20C:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x7
	  addi      r30, r30, 0x4
	  blt+      .loc_0x1D0
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x234
	  li        r4, 0x83
	  bl        -0xBCF20

	.loc_0x234:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80160D14
 * Size:	000244
 */
void SnakeBody::createDeadBodyEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r3
	  stw       r30, 0x48(r1)
	  lfs       f0, -0x554C(r2)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f0, 0x2C(r1)
	  lfs       f2, -0x553C(r2)
	  lwz       r3, 0x8(r3)
	  addi      r0, r3, 0x1
	  mulli     r5, r0, 0xC
	  mulli     r0, r3, 0xC
	  add       r5, r31, r5
	  add       r3, r31, r0
	  lfs       f1, 0x5C(r5)
	  lfs       f0, 0x5C(r3)
	  fadds     f0, f1, f0
	  fmuls     f0, f0, f2
	  stfs      f0, 0x2C(r1)
	  lwz       r0, 0x8(r31)
	  lfs       f1, 0x60(r5)
	  mulli     r0, r0, 0xC
	  add       r3, r31, r0
	  lfs       f0, 0x60(r3)
	  fadds     f0, f1, f0
	  fmuls     f0, f0, f2
	  stfs      f0, 0x30(r1)
	  lwz       r0, 0x8(r31)
	  lfs       f1, 0x64(r5)
	  mulli     r0, r0, 0xC
	  add       r3, r31, r0
	  lfs       f0, 0x64(r3)
	  fadds     f0, f1, f0
	  fmuls     f0, f0, f2
	  stfs      f0, 0x34(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x2C(r1)
	  lfs       f2, 0x34(r1)
	  bl        -0xF8EB8
	  lfs       f0, 0x30(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xBC
	  stfs      f1, 0x30(r1)

	.loc_0xBC:
	  lwz       r0, 0x8(r31)
	  lwz       r3, 0x88C(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r3, r0
	  cmplwi    r4, 0
	  beq-      .loc_0x108
	  lwz       r3, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x14(r4)
	  lwz       r0, 0x8(r31)
	  lwz       r3, 0x88C(r31)
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x108:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x2C
	  li        r4, 0x85
	  li        r6, 0
	  li        r7, 0
	  bl        0x3BD08
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0x2C
	  li        r4, 0x87
	  li        r6, 0
	  li        r7, 0
	  bl        0x3BCF0
	  lwz       r3, 0x3178(r13)
	  addi      r6, r1, 0x2C
	  li        r4, 0xF
	  li        r5, 0
	  bl        0x1BF78
	  lwz       r4, 0x0(r31)
	  lwz       r3, 0x224(r4)
	  lwz       r30, 0x500(r3)
	  cmpwi     r30, 0
	  blt-      .loc_0x214
	  lwz       r4, 0x2F8(r4)
	  cmpwi     r4, 0x2
	  bgt-      .loc_0x174
	  cmpwi     r4, 0
	  bge-      .loc_0x1B8

	.loc_0x174:
	  bl        0xB71E8
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5530(r2)
	  stw       r0, 0x44(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x5538(r2)
	  stw       r0, 0x40(r1)
	  lfs       f1, -0x5548(r2)
	  lfd       f3, 0x40(r1)
	  lfs       f0, -0x5534(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x38(r1)
	  lwz       r4, 0x3C(r1)

	.loc_0x1B8:
	  lwz       r3, 0x301C(r13)
	  mr        r5, r30
	  bl        -0xC899C
	  mr.       r30, r3
	  beq-      .loc_0x214
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r1, 0x2C
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x20(r13)
	  mr        r3, r30
	  li        r4, 0
	  stfs      f0, 0x70(r30)
	  lfs       f0, -0x1C(r13)
	  stfs      f0, 0x74(r30)
	  lfs       f0, -0x18(r13)
	  stfs      f0, 0x78(r30)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x214:
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x22C
	  li        r4, 0x96
	  bl        -0xBD16C

	.loc_0x22C:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80160F58
 * Size:	000190
 */
void SnakeBody::makeDeadPattern01()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r3
	  lbz       r5, 0x4(r3)
	  stb       r0, 0x4(r3)
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, 0x7
	  bne-      .loc_0x44
	  lwz       r3, 0x0(r31)
	  lwz       r4, 0x224(r3)
	  lfs       f31, 0x460(r4)
	  lfs       f2, 0x450(r4)
	  b         .loc_0x80

	.loc_0x44:
	  subfic    r0, r0, 0x6
	  lwz       r3, 0x0(r31)
	  xoris     r0, r0, 0x8000
	  lfd       f2, -0x5530(r2)
	  stw       r0, 0x84(r1)
	  lis       r0, 0x4330
	  lwz       r4, 0x224(r3)
	  stw       r0, 0x80(r1)
	  lfs       f0, 0x490(r4)
	  lfd       f1, 0x80(r1)
	  lfs       f3, 0x480(r4)
	  fsubs     f1, f1, f2
	  lfs       f2, 0x470(r4)
	  fmuls     f0, f1, f0
	  fsubs     f31, f3, f0

	.loc_0x80:
	  lwz       r4, 0x0(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D0(r4)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D0(r4)
	  lwz       r0, 0x8(r31)
	  lwz       r3, 0x2DEC(r13)
	  rlwinm    r0,r0,2,0,29
	  lfs       f0, -0x554C(r2)
	  add       r4, r31, r0
	  lfs       f1, 0x28C(r3)
	  lfsu      f3, 0x30(r4)
	  fmuls     f1, f2, f1
	  fsubs     f2, f3, f0
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xC8
	  b         .loc_0xCC

	.loc_0xC8:
	  fneg      f2, f2

	.loc_0xCC:
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0xDC
	  lfs       f0, -0x554C(r2)
	  b         .loc_0xF4

	.loc_0xDC:
	  lfs       f0, -0x554C(r2)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0xF0
	  fadds     f0, f3, f1
	  b         .loc_0xF4

	.loc_0xF0:
	  fsubs     f0, f3, f1

	.loc_0xF4:
	  cmplwi    r5, 0
	  stfs      f0, 0x0(r4)
	  bne-      .loc_0x12C
	  lbz       r0, 0x4(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x12C
	  lwz       r0, 0x8(r31)
	  cmpwi     r0, 0x7
	  bne-      .loc_0x124
	  mr        r3, r31
	  bl        -0x5B4
	  b         .loc_0x12C

	.loc_0x124:
	  mr        r3, r31
	  bl        -0x36C

	.loc_0x12C:
	  lwz       r4, 0x8(r31)
	  cmpwi     r4, 0
	  ble-      .loc_0x178
	  rlwinm    r0,r4,2,0,29
	  lfs       f1, -0x554C(r2)
	  add       r3, r31, r0
	  lfs       f0, 0x30(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x178
	  lwz       r3, 0x0(r31)
	  lfs       f0, 0x2D0(r3)
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x178
	  subi      r0, r4, 0x1
	  stw       r0, 0x8(r31)
	  li        r0, 0
	  stb       r0, 0x4(r31)
	  lwz       r3, 0x0(r31)
	  stfs      f1, 0x2D0(r3)

	.loc_0x178:
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void SnakeBody::makeDeadPattern02()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void SnakeBody::makeDeadScaleParms()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801610E8
 * Size:	000450
 */
void SnakeBody::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stw       r31, 0xB4(r1)
	  mr        r31, r3
	  lfs       f0, -0x554C(r2)
	  lfs       f1, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x90
	  lfs       f0, -0x5544(r2)
	  fcmpu     cr0, f0, f1
	  bne-      .loc_0x5C
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E8(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x5C
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x5C
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  li        r4, 0x38
	  bl        -0xBD370

	.loc_0x5C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r31)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0xC(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xC(r31)
	  lfs       f1, 0xC(r31)
	  lfs       f0, -0x5548(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x90
	  lfs       f0, -0x554C(r2)
	  stfs      f0, 0xC(r31)

	.loc_0x90:
	  lwz       r4, 0x0(r31)
	  lfs       f0, 0x300(r4)
	  stfs      f0, 0x94(r4)
	  lwz       r4, 0x0(r31)
	  lfs       f0, 0x308(r4)
	  stfs      f0, 0x9C(r4)
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x1C0
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x1C0
	  li        r0, 0x4
	  mtctr     r0
	  addi      r5, r31, 0
	  addi      r6, r31, 0

	.loc_0xD0:
	  lfs       f0, 0x284(r6)
	  addi      r3, r6, 0x284
	  addi      r7, r5, 0x128
	  stfs      f0, 0x104(r5)
	  addi      r4, r5, 0x134
	  addi      r9, r5, 0x140
	  lfs       f0, 0x294(r6)
	  addi      r6, r6, 0x40
	  addi      r8, r5, 0x14C
	  stfs      f0, 0x108(r5)
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0x10C(r5)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x110(r5)
	  lfs       f0, 0x14(r3)
	  stfs      f0, 0x114(r5)
	  lfs       f0, 0x24(r3)
	  stfs      f0, 0x118(r5)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x11C(r5)
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x120(r5)
	  lfs       f0, 0x28(r3)
	  stfs      f0, 0x124(r5)
	  addi      r5, r5, 0x30
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x1C(r3)
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x2C(r3)
	  addi      r3, r6, 0x284
	  addi      r6, r6, 0x40
	  stfs      f0, 0x8(r7)
	  addi      r7, r5, 0x128
	  addi      r5, r5, 0x30
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x10(r3)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0x8(r4)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x0(r9)
	  lfs       f0, 0x14(r3)
	  stfs      f0, 0x4(r9)
	  lfs       f0, 0x24(r3)
	  stfs      f0, 0x8(r9)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x0(r8)
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x4(r8)
	  lfs       f0, 0x28(r3)
	  stfs      f0, 0x8(r8)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x1C(r3)
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x2C(r3)
	  stfs      f0, 0x8(r7)
	  bdnz+     .loc_0xD0

	.loc_0x1C0:
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x2C8
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x2C8
	  lfs       f0, 0x278(r31)
	  lfsu      f1, 0x30C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x254(r31)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x27C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x258(r31)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x280(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x25C(r31)
	  lfs       f3, 0x258(r31)
	  lfs       f2, 0x268(r31)
	  lfs       f1, 0x25C(r31)
	  lfs       f0, 0x264(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x26C(r31)
	  lfs       f3, 0x25C(r31)
	  lfs       f2, 0x260(r31)
	  lfs       f1, 0x254(r31)
	  lfs       f0, 0x268(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x270(r31)
	  lfs       f3, 0x254(r31)
	  lfs       f2, 0x264(r31)
	  lfs       f1, 0x258(r31)
	  lfs       f0, 0x260(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x274(r31)
	  lfs       f3, 0x270(r31)
	  lfs       f2, 0x25C(r31)
	  lfs       f1, 0x274(r31)
	  lfs       f0, 0x258(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x260(r31)
	  lfs       f3, 0x274(r31)
	  lfs       f2, 0x254(r31)
	  lfs       f1, 0x26C(r31)
	  lfs       f0, 0x25C(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x264(r31)
	  lfs       f3, 0x26C(r31)
	  lfs       f2, 0x258(r31)
	  lfs       f1, 0x270(r31)
	  lfs       f0, 0x254(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x268(r31)

	.loc_0x2C8:
	  mr        r3, r31
	  bl        -0x1268
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x408
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x408
	  lfs       f1, 0x158(r31)
	  lfs       f0, 0xBC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x158(r31)
	  lfs       f1, 0x15C(r31)
	  lfs       f0, 0xC0(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x15C(r31)
	  lfs       f1, 0x160(r31)
	  lfs       f0, 0xC4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x160(r31)
	  lfs       f1, 0x188(r31)
	  lfs       f0, 0xC8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x188(r31)
	  lfs       f1, 0x18C(r31)
	  lfs       f0, 0xCC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18C(r31)
	  lfs       f1, 0x190(r31)
	  lfs       f0, 0xD0(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x190(r31)
	  lfs       f1, 0x1B8(r31)
	  lfs       f0, 0xD4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1B8(r31)
	  lfs       f1, 0x1BC(r31)
	  lfs       f0, 0xD8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1BC(r31)
	  lfs       f1, 0x1C0(r31)
	  lfs       f0, 0xDC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C0(r31)
	  lfs       f1, 0x1E8(r31)
	  lfs       f0, 0xE0(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1E8(r31)
	  lfs       f1, 0x1EC(r31)
	  lfs       f0, 0xE4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1EC(r31)
	  lfs       f1, 0x1F0(r31)
	  lfs       f0, 0xE8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1F0(r31)
	  lfs       f1, 0x218(r31)
	  lfs       f0, 0xEC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x218(r31)
	  lfs       f1, 0x21C(r31)
	  lfs       f0, 0xF0(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x21C(r31)
	  lfs       f1, 0x220(r31)
	  lfs       f0, 0xF4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x220(r31)
	  lfs       f1, 0x248(r31)
	  lfs       f0, 0xF8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x248(r31)
	  lfs       f1, 0x24C(r31)
	  lfs       f0, 0xFC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x24C(r31)
	  lfs       f1, 0x250(r31)
	  lfs       f0, 0x100(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x250(r31)

	.loc_0x408:
	  mr        r3, r31
	  bl        -0x1090
	  mr        r3, r31
	  bl        -0xDA4
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x43C
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x43C
	  mr        r3, r31
	  bl        -0x5C8

	.loc_0x43C:
	  lwz       r0, 0xBC(r1)
	  lwz       r31, 0xB4(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void SnakeBody::makeAnimation(BossShapeObject*, Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80161538
 * Size:	0001F8
 */
void SnakeBody::makeBodySize()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stfd      f31, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  stw       r30, 0xA8(r1)
	  stw       r29, 0xA4(r1)
	  lfs       f31, -0x554C(r2)
	  lfs       f0, 0x14(r3)
	  fcmpu     cr0, f31, f0
	  bne-      .loc_0x1D8
	  stfs      f31, 0x48(r1)
	  addi      r30, r1, 0x40
	  mr        r31, r3
	  stfs      f31, 0x44(r1)
	  li        r29, 0
	  stfs      f31, 0x40(r1)
	  stfs      f31, 0x54(r1)
	  stfs      f31, 0x50(r1)
	  stfs      f31, 0x4C(r1)
	  stfs      f31, 0x60(r1)
	  stfs      f31, 0x5C(r1)
	  stfs      f31, 0x58(r1)
	  stfs      f31, 0x6C(r1)
	  stfs      f31, 0x68(r1)
	  stfs      f31, 0x64(r1)
	  stfs      f31, 0x78(r1)
	  stfs      f31, 0x74(r1)
	  stfs      f31, 0x70(r1)
	  stfs      f31, 0x84(r1)
	  stfs      f31, 0x80(r1)
	  stfs      f31, 0x7C(r1)
	  stfs      f31, 0x90(r1)
	  stfs      f31, 0x8C(r1)
	  stfs      f31, 0x88(r1)
	  stfs      f31, 0x9C(r1)
	  stfs      f31, 0x98(r1)
	  stfs      f31, 0x94(r1)
	  lfs       f0, 0x290(r3)
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x2A0(r3)
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x2B0(r3)
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x2D0(r3)
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x2E0(r3)
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x2F0(r3)
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x310(r3)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x320(r3)
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x330(r3)
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x350(r3)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x360(r3)
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x370(r3)
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x390(r3)
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x3A0(r3)
	  stfs      f0, 0x74(r1)
	  lfs       f0, 0x3B0(r3)
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x3D0(r3)
	  stfs      f0, 0x7C(r1)
	  lfs       f0, 0x3E0(r3)
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x3F0(r3)
	  stfs      f0, 0x84(r1)
	  lfs       f0, 0x410(r3)
	  stfs      f0, 0x88(r1)
	  lfs       f0, 0x420(r3)
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x430(r3)
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x450(r3)
	  stfs      f0, 0x94(r1)
	  lfs       f0, 0x460(r3)
	  stfs      f0, 0x98(r1)
	  lfs       f0, 0x470(r3)
	  stfs      f0, 0x9C(r1)

	.loc_0x158:
	  stfs      f31, 0x3C(r1)
	  stfs      f31, 0x38(r1)
	  stfs      f31, 0x34(r1)
	  lfs       f1, 0xC(r30)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x34(r1)
	  lfs       f1, 0x10(r30)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x38(r1)
	  lfs       f1, 0x14(r30)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3C(r1)
	  lfs       f1, 0x34(r1)
	  lfs       f0, 0x38(r1)
	  lfs       f2, 0x3C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x153AB4
	  addi      r29, r29, 0x1
	  stfs      f1, 0x14(r31)
	  cmpwi     r29, 0x7
	  addi      r30, r30, 0xC
	  addi      r31, r31, 0x4
	  blt+      .loc_0x158

	.loc_0x1D8:
	  lwz       r0, 0xBC(r1)
	  lfd       f31, 0xB0(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  lwz       r29, 0xA4(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80161730
 * Size:	000198
 */
void SnakeBody::makeHeadPosition()
{
	/*
	.loc_0x0:
	  stwu      r1, -0xB8(r1)
	  lwz       r5, 0x0(r3)
	  lwz       r0, 0x2E4(r5)
	  cmpwi     r0, 0x4
	  bne-      .loc_0x12C
	  lis       r4, 0x8022
	  addi      r6, r4, 0x2708
	  lwz       r5, 0x0(r6)
	  addi      r4, r1, 0x78
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x78(r1)
	  stw       r0, 0x7C(r1)
	  lwz       r5, 0x8(r6)
	  lwz       r0, 0xC(r6)
	  stw       r5, 0x80(r1)
	  stw       r0, 0x84(r1)
	  lwz       r5, 0x10(r6)
	  lwz       r0, 0x14(r6)
	  stw       r5, 0x88(r1)
	  stw       r0, 0x8C(r1)
	  lwz       r5, 0x18(r6)
	  lwz       r0, 0x1C(r6)
	  stw       r5, 0x90(r1)
	  stw       r0, 0x94(r1)
	  lwz       r5, 0x20(r6)
	  lwz       r0, 0x24(r6)
	  stw       r5, 0x98(r1)
	  stw       r0, 0x9C(r1)
	  lwz       r5, 0x28(r6)
	  lwz       r0, 0x2C(r6)
	  stw       r5, 0xA0(r1)
	  stw       r0, 0xA4(r1)
	  lwz       r5, 0x30(r6)
	  lwz       r0, 0x34(r6)
	  stw       r5, 0xA8(r1)
	  stw       r0, 0xAC(r1)
	  lwz       r0, 0x38(r6)
	  stw       r0, 0xB0(r1)
	  lwz       r5, 0x0(r3)
	  lwz       r7, 0x3C8(r5)
	  lfs       f2, 0x368(r5)
	  lwz       r0, 0x14(r7)
	  mulli     r6, r0, 0xC
	  lfsx      f3, r4, r6
	  fcmpo     cr0, f2, f3
	  ble-      .loc_0x190
	  addi      r4, r1, 0x80
	  lfsx      f5, r4, r6
	  fcmpo     cr0, f2, f5
	  bge-      .loc_0x190
	  addi      r4, r1, 0x7C
	  lwz       r0, 0x30(r7)
	  lfsx      f4, r4, r6
	  add       r4, r0, r6
	  lfs       f0, 0x98(r5)
	  lfs       f1, 0x4(r4)
	  fcmpo     cr0, f2, f4
	  fsubs     f6, f1, f0
	  bge-      .loc_0x10C
	  fsubs     f1, f2, f3
	  lfs       f2, 0x460(r3)
	  fsubs     f0, f4, f3
	  fdivs     f0, f1, f0
	  fmuls     f0, f6, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x460(r3)
	  b         .loc_0x190

	.loc_0x10C:
	  fsubs     f1, f5, f2
	  lfs       f2, 0x460(r3)
	  fsubs     f0, f5, f4
	  fdivs     f0, f1, f0
	  fmuls     f0, f6, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x460(r3)
	  b         .loc_0x190

	.loc_0x12C:
	  cmpwi     r0, 0
	  bne-      .loc_0x190
	  lfs       f3, 0x368(r5)
	  lfs       f2, -0x5524(r2)
	  fcmpo     cr0, f3, f2
	  ble-      .loc_0x190
	  lwz       r4, 0x3C8(r5)
	  lfs       f0, -0x5520(r2)
	  lwz       r4, 0x30(r4)
	  fcmpo     cr0, f3, f0
	  lfs       f0, 0x98(r5)
	  lfs       f1, 0x10(r4)
	  fsubs     f4, f1, f0
	  bge-      .loc_0x184
	  fsubs     f1, f3, f2
	  lfs       f0, -0x5540(r2)
	  lfs       f2, 0x460(r3)
	  fdivs     f0, f1, f0
	  fmuls     f0, f4, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x460(r3)
	  b         .loc_0x190

	.loc_0x184:
	  lfs       f0, 0x460(r3)
	  fadds     f0, f0, f4
	  stfs      f0, 0x460(r3)

	.loc_0x190:
	  addi      r1, r1, 0xB8
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801618C8
 * Size:	0002F4
 */
void SnakeBody::makeBodyMatrix()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x130(r1)
	  stfd      f31, 0x128(r1)
	  stfd      f30, 0x120(r1)
	  stfd      f29, 0x118(r1)
	  stfd      f28, 0x110(r1)
	  stfd      f27, 0x108(r1)
	  stfd      f26, 0x100(r1)
	  stfd      f25, 0xF8(r1)
	  stfd      f24, 0xF0(r1)
	  stmw      r18, 0xB8(r1)
	  mr        r27, r3
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x4C
	  cmpwi     r0, 0
	  bne-      .loc_0x2C0

	.loc_0x4C:
	  lfs       f30, -0x554C(r2)
	  addi      r31, r1, 0x48
	  lfs       f31, -0x553C(r2)
	  li        r30, 0
	  stfs      f30, 0x44(r1)
	  stfs      f30, 0x40(r1)
	  stfs      f30, 0x3C(r1)
	  stfs      f30, 0x50(r1)
	  stfs      f30, 0x4C(r1)
	  stfs      f30, 0x48(r1)
	  stfs      f30, 0x5C(r1)
	  stfs      f30, 0x58(r1)
	  stfs      f30, 0x54(r1)
	  stfs      f30, 0x68(r1)
	  stfs      f30, 0x64(r1)
	  stfs      f30, 0x60(r1)
	  stfs      f30, 0x74(r1)
	  stfs      f30, 0x70(r1)
	  stfs      f30, 0x6C(r1)
	  stfs      f30, 0x80(r1)
	  stfs      f30, 0x7C(r1)
	  stfs      f30, 0x78(r1)
	  stfs      f30, 0x8C(r1)
	  stfs      f30, 0x88(r1)
	  stfs      f30, 0x84(r1)

	.loc_0xB0:
	  addi      r24, r31, 0
	  addi      r26, r27, 0x40
	  addi      r25, r27, 0x4
	  li        r29, 0x1

	.loc_0xC0:
	  subi      r28, r29, 0x1
	  lfs       f4, 0x290(r26)
	  rlwinm    r0,r28,6,0,25
	  lfs       f3, 0x2A0(r26)
	  add       r3, r27, r0
	  lfs       f1, 0x2B0(r26)
	  addi      r23, r3, 0x290
	  addi      r22, r3, 0x2A0
	  lfs       f0, 0x290(r3)
	  lfs       f2, 0x2A0(r3)
	  addi      r21, r3, 0x2B0
	  fsubs     f27, f4, f0
	  lfs       f0, 0x2B0(r3)
	  fsubs     f28, f3, f2
	  fsubs     f29, f1, f0
	  addi      r18, r29, 0x1
	  fmuls     f1, f27, f27
	  fmuls     f0, f28, f28
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x153D9C
	  fcmpu     cr0, f30, f1
	  beq-      .loc_0x12C
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1
	  fdivs     f29, f29, f1

	.loc_0x12C:
	  rlwinm    r0,r18,6,0,25
	  lfs       f4, 0x290(r26)
	  add       r3, r27, r0
	  lfs       f3, 0x2A0(r26)
	  addi      r18, r3, 0x290
	  lfs       f1, 0x2B0(r26)
	  addi      r20, r3, 0x2A0
	  lfs       f0, 0x290(r3)
	  lfs       f2, 0x2A0(r3)
	  addi      r19, r3, 0x2B0
	  fsubs     f24, f4, f0
	  lfs       f0, 0x2B0(r3)
	  fsubs     f25, f3, f2
	  rlwinm    r3,r28,2,0,29
	  fsubs     f26, f1, f0
	  addi      r0, r3, 0x14
	  fmuls     f1, f24, f24
	  lfsx      f8, r27, r0
	  fmuls     f0, f25, f25
	  fmuls     f2, f26, f26
	  lfs       f7, 0x0(r23)
	  fmuls     f6, f8, f27
	  lfs       f5, 0x0(r22)
	  fmuls     f4, f8, f28
	  fadds     f0, f1, f0
	  lfs       f3, 0x0(r21)
	  fmuls     f1, f8, f29
	  fadds     f29, f7, f6
	  fadds     f28, f5, f4
	  fadds     f27, f3, f1
	  fadds     f1, f2, f0
	  bl        -0x153E30
	  fcmpu     cr0, f30, f1
	  beq-      .loc_0x1C0
	  fdivs     f24, f24, f1
	  fdivs     f25, f25, f1
	  fdivs     f26, f26, f1

	.loc_0x1C0:
	  lfs       f2, 0x14(r25)
	  addi      r29, r29, 0x1
	  lfs       f1, 0x0(r18)
	  cmpwi     r29, 0x7
	  fmuls     f0, f2, f24
	  fmuls     f4, f2, f25
	  lfs       f5, 0x0(r20)
	  fmuls     f2, f2, f26
	  lfs       f3, 0x0(r19)
	  fadds     f0, f1, f0
	  fadds     f1, f5, f4
	  addi      r26, r26, 0x40
	  fadds     f3, f3, f2
	  addi      r25, r25, 0x4
	  fadds     f2, f29, f0
	  fadds     f1, f28, f1
	  fadds     f0, f27, f3
	  fmuls     f2, f31, f2
	  fmuls     f1, f31, f1
	  fmuls     f0, f31, f0
	  stfs      f2, 0x0(r24)
	  stfs      f1, 0x4(r24)
	  stfs      f0, 0x8(r24)
	  addi      r24, r24, 0xC
	  blt+      .loc_0xC0
	  lfs       f0, 0x48(r1)
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0xA
	  stfs      f0, 0x2D0(r27)
	  lfs       f0, 0x4C(r1)
	  stfs      f0, 0x2E0(r27)
	  lfs       f0, 0x50(r1)
	  stfs      f0, 0x2F0(r27)
	  lfs       f0, 0x54(r1)
	  stfs      f0, 0x310(r27)
	  lfs       f0, 0x58(r1)
	  stfs      f0, 0x320(r27)
	  lfs       f0, 0x5C(r1)
	  stfs      f0, 0x330(r27)
	  lfs       f0, 0x60(r1)
	  stfs      f0, 0x350(r27)
	  lfs       f0, 0x64(r1)
	  stfs      f0, 0x360(r27)
	  lfs       f0, 0x68(r1)
	  stfs      f0, 0x370(r27)
	  lfs       f0, 0x6C(r1)
	  stfs      f0, 0x390(r27)
	  lfs       f0, 0x70(r1)
	  stfs      f0, 0x3A0(r27)
	  lfs       f0, 0x74(r1)
	  stfs      f0, 0x3B0(r27)
	  lfs       f0, 0x78(r1)
	  stfs      f0, 0x3D0(r27)
	  lfs       f0, 0x7C(r1)
	  stfs      f0, 0x3E0(r27)
	  lfs       f0, 0x80(r1)
	  stfs      f0, 0x3F0(r27)
	  lfs       f0, 0x84(r1)
	  stfs      f0, 0x410(r27)
	  lfs       f0, 0x88(r1)
	  stfs      f0, 0x420(r27)
	  lfs       f0, 0x8C(r1)
	  stfs      f0, 0x430(r27)
	  blt+      .loc_0xB0

	.loc_0x2C0:
	  lmw       r18, 0xB8(r1)
	  lwz       r0, 0x134(r1)
	  lfd       f31, 0x128(r1)
	  lfd       f30, 0x120(r1)
	  lfd       f29, 0x118(r1)
	  lfd       f28, 0x110(r1)
	  lfd       f27, 0x108(r1)
	  lfd       f26, 0x100(r1)
	  lfd       f25, 0xF8(r1)
	  lfd       f24, 0xF0(r1)
	  addi      r1, r1, 0x130
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80161BBC
 * Size:	0003B8
 */
void SnakeBody::makeAnimMatrix()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1E8(r1)
	  stfd      f31, 0x1E0(r1)
	  stw       r31, 0x1DC(r1)
	  stw       r30, 0x1D8(r1)
	  stw       r29, 0x1D4(r1)
	  stw       r28, 0x1D0(r1)
	  mr        r28, r3
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x3C
	  cmpwi     r0, 0
	  bne-      .loc_0x394

	.loc_0x3C:
	  lis       r3, 0x8003
	  addi      r4, r3, 0x5B24
	  addi      r3, r1, 0x4C
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x20
	  bl        0xB2E60
	  li        r0, 0x4
	  addi      r30, r1, 0x4C
	  mtctr     r0
	  addi      r3, r28, 0
	  addi      r4, r30, 0

	.loc_0x6C:
	  lfs       f0, 0x284(r3)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x294(r3)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x2A4(r3)
	  stfs      f0, 0x8(r4)
	  lfs       f0, 0x288(r3)
	  stfs      f0, 0xC(r4)
	  lfs       f0, 0x298(r3)
	  stfs      f0, 0x10(r4)
	  lfs       f0, 0x2A8(r3)
	  stfs      f0, 0x14(r4)
	  lfs       f0, 0x28C(r3)
	  stfs      f0, 0x18(r4)
	  lfs       f0, 0x29C(r3)
	  stfs      f0, 0x1C(r4)
	  lfs       f0, 0x2AC(r3)
	  stfs      f0, 0x20(r4)
	  lfs       f0, 0x290(r3)
	  stfs      f0, 0x24(r4)
	  lfs       f0, 0x2A0(r3)
	  stfs      f0, 0x28(r4)
	  lfs       f0, 0x2B0(r3)
	  stfs      f0, 0x2C(r4)
	  lfs       f0, 0x2C4(r3)
	  stfs      f0, 0x30(r4)
	  lfs       f0, 0x2D4(r3)
	  stfs      f0, 0x34(r4)
	  lfs       f0, 0x2E4(r3)
	  stfs      f0, 0x38(r4)
	  lfs       f0, 0x2C8(r3)
	  stfs      f0, 0x3C(r4)
	  lfs       f0, 0x2D8(r3)
	  stfs      f0, 0x40(r4)
	  lfs       f0, 0x2E8(r3)
	  stfs      f0, 0x44(r4)
	  lfs       f0, 0x2CC(r3)
	  stfs      f0, 0x48(r4)
	  lfs       f0, 0x2DC(r3)
	  stfs      f0, 0x4C(r4)
	  lfs       f0, 0x2EC(r3)
	  stfs      f0, 0x50(r4)
	  lfs       f0, 0x2D0(r3)
	  stfs      f0, 0x54(r4)
	  lfs       f0, 0x2E0(r3)
	  stfs      f0, 0x58(r4)
	  lfs       f0, 0x2F0(r3)
	  addi      r3, r3, 0x80
	  stfs      f0, 0x5C(r4)
	  addi      r4, r4, 0x60
	  bdnz+     .loc_0x6C
	  lfs       f31, -0x554C(r2)
	  addi      r31, r30, 0
	  li        r29, 0

	.loc_0x144:
	  lfs       f1, 0x54(r31)
	  lfs       f0, 0x24(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r31)
	  lfs       f1, 0x58(r31)
	  lfs       f0, 0x28(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4(r31)
	  lfs       f1, 0x5C(r31)
	  lfs       f0, 0x2C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x8(r31)
	  lfs       f3, 0x1C(r31)
	  lfs       f2, 0x8(r31)
	  lfs       f1, 0x20(r31)
	  lfs       f0, 0x4(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0xC(r31)
	  lfs       f3, 0x20(r31)
	  lfs       f2, 0x0(r31)
	  lfs       f1, 0x18(r31)
	  lfs       f0, 0x8(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x10(r31)
	  lfs       f3, 0x18(r31)
	  lfs       f2, 0x4(r31)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, 0x0(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x14(r31)
	  lfs       f3, 0x4(r31)
	  lfs       f2, 0x14(r31)
	  lfs       f1, 0x8(r31)
	  lfs       f0, 0x10(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x18(r31)
	  lfs       f3, 0x8(r31)
	  lfs       f2, 0xC(r31)
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x14(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x1C(r31)
	  lfs       f3, 0x0(r31)
	  lfs       f2, 0x10(r31)
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0xC(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x20(r31)
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x4(r31)
	  lfs       f2, 0x8(r31)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1541D0
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x284
	  lfs       f0, 0x0(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x4(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x8(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r31)

	.loc_0x284:
	  lfs       f1, 0xC(r31)
	  lfs       f0, 0x10(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x14(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x154220
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x2D4
	  lfs       f0, 0xC(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xC(r31)
	  lfs       f0, 0x10(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x10(r31)
	  lfs       f0, 0x14(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x14(r31)

	.loc_0x2D4:
	  lfs       f1, 0x18(r31)
	  lfs       f0, 0x1C(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x20(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x154270
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x324
	  lfs       f0, 0x18(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x1C(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x1C(r31)
	  lfs       f0, 0x20(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x20(r31)

	.loc_0x324:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x7
	  addi      r31, r31, 0x30
	  blt+      .loc_0x144
	  li        r0, 0x7
	  mtctr     r0
	  addi      r3, r28, 0

	.loc_0x340:
	  lfs       f0, 0x0(r30)
	  stfs      f0, 0x284(r3)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x294(r3)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x2A4(r3)
	  lfs       f0, 0xC(r30)
	  stfs      f0, 0x288(r3)
	  lfs       f0, 0x10(r30)
	  stfs      f0, 0x298(r3)
	  lfs       f0, 0x14(r30)
	  stfs      f0, 0x2A8(r3)
	  lfs       f0, 0x18(r30)
	  stfs      f0, 0x28C(r3)
	  lfs       f0, 0x1C(r30)
	  stfs      f0, 0x29C(r3)
	  lfs       f0, 0x20(r30)
	  addi      r30, r30, 0x30
	  stfs      f0, 0x2AC(r3)
	  addi      r3, r3, 0x40
	  bdnz+     .loc_0x340

	.loc_0x394:
	  lwz       r0, 0x1EC(r1)
	  lfd       f31, 0x1E0(r1)
	  lwz       r31, 0x1DC(r1)
	  lwz       r30, 0x1D8(r1)
	  lwz       r29, 0x1D4(r1)
	  lwz       r28, 0x1D0(r1)
	  addi      r1, r1, 0x1E8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80161F74
 * Size:	000524
 */
void SnakeBody::caseOfMatrix(Matrix4f*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r3)
	  lwz       r0, 0x2E4(r5)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x120
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x120
	  li        r0, 0x4
	  lfs       f1, -0x554C(r2)
	  mtctr     r0
	  lfs       f0, -0x5548(r2)

	.loc_0x28:
	  lfs       f2, 0x104(r3)
	  stfs      f2, 0x0(r4)
	  lfs       f2, 0x108(r3)
	  stfs      f2, 0x10(r4)
	  lfs       f2, 0x10C(r3)
	  stfs      f2, 0x20(r4)
	  lfs       f2, 0x110(r3)
	  stfs      f2, 0x4(r4)
	  lfs       f2, 0x114(r3)
	  stfs      f2, 0x14(r4)
	  lfs       f2, 0x118(r3)
	  stfs      f2, 0x24(r4)
	  lfs       f2, 0x11C(r3)
	  stfs      f2, 0x8(r4)
	  lfs       f2, 0x120(r3)
	  stfs      f2, 0x18(r4)
	  lfs       f2, 0x124(r3)
	  stfs      f2, 0x28(r4)
	  lfs       f2, 0x128(r3)
	  stfs      f2, 0xC(r4)
	  lfs       f2, 0x12C(r3)
	  stfs      f2, 0x1C(r4)
	  lfs       f2, 0x130(r3)
	  stfs      f2, 0x2C(r4)
	  stfs      f1, 0x30(r4)
	  stfs      f1, 0x34(r4)
	  stfs      f1, 0x38(r4)
	  stfs      f0, 0x3C(r4)
	  lfs       f2, 0x134(r3)
	  stfs      f2, 0x40(r4)
	  lfs       f2, 0x138(r3)
	  stfs      f2, 0x50(r4)
	  lfs       f2, 0x13C(r3)
	  stfs      f2, 0x60(r4)
	  lfs       f2, 0x140(r3)
	  stfs      f2, 0x44(r4)
	  addi      r4, r4, 0x40
	  lfs       f2, 0x144(r3)
	  stfs      f2, 0x14(r4)
	  lfs       f2, 0x148(r3)
	  addi      r3, r3, 0x30
	  stfs      f2, 0x24(r4)
	  lfs       f2, 0x11C(r3)
	  stfs      f2, 0x8(r4)
	  lfs       f2, 0x120(r3)
	  stfs      f2, 0x18(r4)
	  lfs       f2, 0x124(r3)
	  stfs      f2, 0x28(r4)
	  lfs       f2, 0x128(r3)
	  stfs      f2, 0xC(r4)
	  lfs       f2, 0x12C(r3)
	  stfs      f2, 0x1C(r4)
	  lfs       f2, 0x130(r3)
	  addi      r3, r3, 0x30
	  stfs      f2, 0x2C(r4)
	  stfs      f1, 0x30(r4)
	  stfs      f1, 0x34(r4)
	  stfs      f1, 0x38(r4)
	  stfs      f0, 0x3C(r4)
	  addi      r4, r4, 0x40
	  bdnz+     .loc_0x28
	  blr

	.loc_0x120:
	  lwz       r5, 0x284(r3)
	  lwz       r0, 0x288(r3)
	  stw       r5, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r5, 0x28C(r3)
	  lwz       r0, 0x290(r3)
	  stw       r5, 0x8(r4)
	  stw       r0, 0xC(r4)
	  lwz       r5, 0x294(r3)
	  lwz       r0, 0x298(r3)
	  stw       r5, 0x10(r4)
	  stw       r0, 0x14(r4)
	  lwz       r5, 0x29C(r3)
	  lwz       r0, 0x2A0(r3)
	  stw       r5, 0x18(r4)
	  stw       r0, 0x1C(r4)
	  lwz       r5, 0x2A4(r3)
	  lwz       r0, 0x2A8(r3)
	  stw       r5, 0x20(r4)
	  stw       r0, 0x24(r4)
	  lwz       r5, 0x2AC(r3)
	  lwz       r0, 0x2B0(r3)
	  stw       r5, 0x28(r4)
	  stw       r0, 0x2C(r4)
	  lwz       r5, 0x2B4(r3)
	  lwz       r0, 0x2B8(r3)
	  stw       r5, 0x30(r4)
	  stw       r0, 0x34(r4)
	  lwz       r5, 0x2BC(r3)
	  lwz       r0, 0x2C0(r3)
	  stw       r5, 0x38(r4)
	  stw       r0, 0x3C(r4)
	  lwz       r5, 0x2C4(r3)
	  lwz       r0, 0x2C8(r3)
	  stw       r5, 0x40(r4)
	  stw       r0, 0x44(r4)
	  lwz       r5, 0x2CC(r3)
	  lwz       r0, 0x2D0(r3)
	  stw       r5, 0x48(r4)
	  stw       r0, 0x4C(r4)
	  lwz       r5, 0x2D4(r3)
	  lwz       r0, 0x2D8(r3)
	  stw       r5, 0x50(r4)
	  stw       r0, 0x54(r4)
	  lwz       r5, 0x2DC(r3)
	  lwz       r0, 0x2E0(r3)
	  stw       r5, 0x58(r4)
	  stw       r0, 0x5C(r4)
	  lwz       r5, 0x2E4(r3)
	  lwz       r0, 0x2E8(r3)
	  stw       r5, 0x60(r4)
	  stw       r0, 0x64(r4)
	  lwz       r5, 0x2EC(r3)
	  lwz       r0, 0x2F0(r3)
	  stw       r5, 0x68(r4)
	  stw       r0, 0x6C(r4)
	  lwz       r5, 0x2F4(r3)
	  lwz       r0, 0x2F8(r3)
	  stw       r5, 0x70(r4)
	  stw       r0, 0x74(r4)
	  lwz       r5, 0x2FC(r3)
	  lwz       r0, 0x300(r3)
	  stw       r5, 0x78(r4)
	  stw       r0, 0x7C(r4)
	  lwz       r5, 0x304(r3)
	  lwz       r0, 0x308(r3)
	  stw       r5, 0x80(r4)
	  stw       r0, 0x84(r4)
	  lwz       r5, 0x30C(r3)
	  lwz       r0, 0x310(r3)
	  stw       r5, 0x88(r4)
	  stw       r0, 0x8C(r4)
	  lwz       r5, 0x314(r3)
	  lwz       r0, 0x318(r3)
	  stw       r5, 0x90(r4)
	  stw       r0, 0x94(r4)
	  lwz       r5, 0x31C(r3)
	  lwz       r0, 0x320(r3)
	  stw       r5, 0x98(r4)
	  stw       r0, 0x9C(r4)
	  lwz       r5, 0x324(r3)
	  lwz       r0, 0x328(r3)
	  stw       r5, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r5, 0x32C(r3)
	  lwz       r0, 0x330(r3)
	  stw       r5, 0xA8(r4)
	  stw       r0, 0xAC(r4)
	  lwz       r5, 0x334(r3)
	  lwz       r0, 0x338(r3)
	  stw       r5, 0xB0(r4)
	  stw       r0, 0xB4(r4)
	  lwz       r5, 0x33C(r3)
	  lwz       r0, 0x340(r3)
	  stw       r5, 0xB8(r4)
	  stw       r0, 0xBC(r4)
	  lwz       r5, 0x344(r3)
	  lwz       r0, 0x348(r3)
	  stw       r5, 0xC0(r4)
	  stw       r0, 0xC4(r4)
	  lwz       r5, 0x34C(r3)
	  lwz       r0, 0x350(r3)
	  stw       r5, 0xC8(r4)
	  stw       r0, 0xCC(r4)
	  lwz       r5, 0x354(r3)
	  lwz       r0, 0x358(r3)
	  stw       r5, 0xD0(r4)
	  stw       r0, 0xD4(r4)
	  lwz       r5, 0x35C(r3)
	  lwz       r0, 0x360(r3)
	  stw       r5, 0xD8(r4)
	  stw       r0, 0xDC(r4)
	  lwz       r5, 0x364(r3)
	  lwz       r0, 0x368(r3)
	  stw       r5, 0xE0(r4)
	  stw       r0, 0xE4(r4)
	  lwz       r5, 0x36C(r3)
	  lwz       r0, 0x370(r3)
	  stw       r5, 0xE8(r4)
	  stw       r0, 0xEC(r4)
	  lwz       r5, 0x374(r3)
	  lwz       r0, 0x378(r3)
	  stw       r5, 0xF0(r4)
	  stw       r0, 0xF4(r4)
	  lwz       r5, 0x37C(r3)
	  lwz       r0, 0x380(r3)
	  stw       r5, 0xF8(r4)
	  stw       r0, 0xFC(r4)
	  lwz       r5, 0x384(r3)
	  lwz       r0, 0x388(r3)
	  stw       r5, 0x100(r4)
	  stw       r0, 0x104(r4)
	  lwz       r5, 0x38C(r3)
	  lwz       r0, 0x390(r3)
	  stw       r5, 0x108(r4)
	  stw       r0, 0x10C(r4)
	  lwz       r5, 0x394(r3)
	  lwz       r0, 0x398(r3)
	  stw       r5, 0x110(r4)
	  stw       r0, 0x114(r4)
	  lwz       r5, 0x39C(r3)
	  lwz       r0, 0x3A0(r3)
	  stw       r5, 0x118(r4)
	  stw       r0, 0x11C(r4)
	  lwz       r5, 0x3A4(r3)
	  lwz       r0, 0x3A8(r3)
	  stw       r5, 0x120(r4)
	  stw       r0, 0x124(r4)
	  lwz       r5, 0x3AC(r3)
	  lwz       r0, 0x3B0(r3)
	  stw       r5, 0x128(r4)
	  stw       r0, 0x12C(r4)
	  lwz       r5, 0x3B4(r3)
	  lwz       r0, 0x3B8(r3)
	  stw       r5, 0x130(r4)
	  stw       r0, 0x134(r4)
	  lwz       r5, 0x3BC(r3)
	  lwz       r0, 0x3C0(r3)
	  stw       r5, 0x138(r4)
	  stw       r0, 0x13C(r4)
	  lwz       r5, 0x3C4(r3)
	  lwz       r0, 0x3C8(r3)
	  stw       r5, 0x140(r4)
	  stw       r0, 0x144(r4)
	  lwz       r5, 0x3CC(r3)
	  lwz       r0, 0x3D0(r3)
	  stw       r5, 0x148(r4)
	  stw       r0, 0x14C(r4)
	  lwz       r5, 0x3D4(r3)
	  lwz       r0, 0x3D8(r3)
	  stw       r5, 0x150(r4)
	  stw       r0, 0x154(r4)
	  lwz       r5, 0x3DC(r3)
	  lwz       r0, 0x3E0(r3)
	  stw       r5, 0x158(r4)
	  stw       r0, 0x15C(r4)
	  lwz       r5, 0x3E4(r3)
	  lwz       r0, 0x3E8(r3)
	  stw       r5, 0x160(r4)
	  stw       r0, 0x164(r4)
	  lwz       r5, 0x3EC(r3)
	  lwz       r0, 0x3F0(r3)
	  stw       r5, 0x168(r4)
	  stw       r0, 0x16C(r4)
	  lwz       r5, 0x3F4(r3)
	  lwz       r0, 0x3F8(r3)
	  stw       r5, 0x170(r4)
	  stw       r0, 0x174(r4)
	  lwz       r5, 0x3FC(r3)
	  lwz       r0, 0x400(r3)
	  stw       r5, 0x178(r4)
	  stw       r0, 0x17C(r4)
	  lwz       r5, 0x404(r3)
	  lwz       r0, 0x408(r3)
	  stw       r5, 0x180(r4)
	  stw       r0, 0x184(r4)
	  lwz       r5, 0x40C(r3)
	  lwz       r0, 0x410(r3)
	  stw       r5, 0x188(r4)
	  stw       r0, 0x18C(r4)
	  lwz       r5, 0x414(r3)
	  lwz       r0, 0x418(r3)
	  stw       r5, 0x190(r4)
	  stw       r0, 0x194(r4)
	  lwz       r5, 0x41C(r3)
	  lwz       r0, 0x420(r3)
	  stw       r5, 0x198(r4)
	  stw       r0, 0x19C(r4)
	  lwz       r5, 0x424(r3)
	  lwz       r0, 0x428(r3)
	  stw       r5, 0x1A0(r4)
	  stw       r0, 0x1A4(r4)
	  lwz       r5, 0x42C(r3)
	  lwz       r0, 0x430(r3)
	  stw       r5, 0x1A8(r4)
	  stw       r0, 0x1AC(r4)
	  lwz       r5, 0x434(r3)
	  lwz       r0, 0x438(r3)
	  stw       r5, 0x1B0(r4)
	  stw       r0, 0x1B4(r4)
	  lwz       r5, 0x43C(r3)
	  lwz       r0, 0x440(r3)
	  stw       r5, 0x1B8(r4)
	  stw       r0, 0x1BC(r4)
	  lwz       r5, 0x444(r3)
	  lwz       r0, 0x448(r3)
	  stw       r5, 0x1C0(r4)
	  stw       r0, 0x1C4(r4)
	  lwz       r5, 0x44C(r3)
	  lwz       r0, 0x450(r3)
	  stw       r5, 0x1C8(r4)
	  stw       r0, 0x1CC(r4)
	  lwz       r5, 0x454(r3)
	  lwz       r0, 0x458(r3)
	  stw       r5, 0x1D0(r4)
	  stw       r0, 0x1D4(r4)
	  lwz       r5, 0x45C(r3)
	  lwz       r0, 0x460(r3)
	  stw       r5, 0x1D8(r4)
	  stw       r0, 0x1DC(r4)
	  lwz       r5, 0x464(r3)
	  lwz       r0, 0x468(r3)
	  stw       r5, 0x1E0(r4)
	  stw       r0, 0x1E4(r4)
	  lwz       r5, 0x46C(r3)
	  lwz       r0, 0x470(r3)
	  stw       r5, 0x1E8(r4)
	  stw       r0, 0x1EC(r4)
	  lwz       r5, 0x474(r3)
	  lwz       r0, 0x478(r3)
	  stw       r5, 0x1F0(r4)
	  stw       r0, 0x1F4(r4)
	  lwz       r5, 0x47C(r3)
	  lwz       r0, 0x480(r3)
	  stw       r5, 0x1F8(r4)
	  stw       r0, 0x1FC(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00082C
 */
void SnakeBody::checkBlendingParm(Matrix4f*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80162498
 * Size:	000540
 */
void SnakeBody::makeBlending(Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stmw      r25, 0xBC(r1)
	  mr        r25, r3
	  lfs       f0, -0x554C(r2)
	  lfs       f1, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x428
	  lfs       f0, -0x5548(r2)
	  li        r0, 0x2
	  mtctr     r0
	  addi      r3, r25, 0
	  fsubs     f3, f0, f1
	  addi      r5, r4, 0
	  addi      r6, r25, 0

	.loc_0x48:
	  lfs       f0, 0x490(r3)
	  lfs       f2, 0xC(r25)
	  lfs       f1, 0xC(r5)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x5C(r6)
	  lfs       f0, 0x4A0(r3)
	  lfs       f2, 0xC(r25)
	  lfs       f1, 0x1C(r5)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x60(r6)
	  lfs       f0, 0x4B0(r3)
	  lfs       f1, 0x2C(r5)
	  lfs       f2, 0xC(r25)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x64(r6)
	  lfs       f0, 0x4D0(r3)
	  lfs       f2, 0xC(r25)
	  lfs       f1, 0x4C(r5)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x68(r6)
	  lfs       f0, 0x4E0(r3)
	  lfs       f2, 0xC(r25)
	  lfs       f1, 0x5C(r5)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x6C(r6)
	  lfs       f0, 0x4F0(r3)
	  lfs       f1, 0x6C(r5)
	  lfs       f2, 0xC(r25)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x70(r6)
	  lfs       f0, 0x510(r3)
	  lfs       f2, 0xC(r25)
	  lfs       f1, 0x8C(r5)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x74(r6)
	  lfs       f0, 0x520(r3)
	  lfs       f2, 0xC(r25)
	  lfs       f1, 0x9C(r5)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x78(r6)
	  lfs       f0, 0x530(r3)
	  lfs       f1, 0xAC(r5)
	  lfs       f2, 0xC(r25)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x7C(r6)
	  lfs       f0, 0x550(r3)
	  lfs       f2, 0xC(r25)
	  lfs       f1, 0xCC(r5)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x80(r6)
	  lfs       f0, 0x560(r3)
	  lfs       f2, 0xC(r25)
	  lfs       f1, 0xDC(r5)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x84(r6)
	  lfs       f0, 0x570(r3)
	  addi      r3, r3, 0x100
	  lfs       f1, 0xEC(r5)
	  addi      r5, r5, 0x100
	  lfs       f2, 0xC(r25)
	  fmuls     f0, f3, f0
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x88(r6)
	  addi      r6, r6, 0x30
	  bdnz+     .loc_0x48
	  li        r26, 0
	  lfs       f31, -0x554C(r2)
	  rlwinm    r0,r26,6,0,25
	  lfs       f30, -0x5548(r2)
	  addi      r29, r25, 0
	  addi      r28, r25, 0
	  add       r31, r4, r0
	  add       r30, r25, r0
	  li        r27, 0x9

	.loc_0x1CC:
	  cmpwi     r27, 0x8
	  li        r3, 0
	  ble-      .loc_0x504
	  stfs      f31, 0x94(r1)
	  li        r3, 0x8
	  stfs      f31, 0x98(r1)
	  stfs      f31, 0x9C(r1)
	  stfs      f31, 0xA0(r1)
	  stfs      f31, 0xA4(r1)
	  stfs      f31, 0xA8(r1)
	  stfs      f31, 0xAC(r1)
	  stfs      f31, 0xB0(r1)
	  b         .loc_0x504

	.loc_0x200:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x21C

	.loc_0x210:
	  stfs      f31, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x210

	.loc_0x21C:
	  stfs      f30, 0xB4(r1)
	  cmpwi     r27, 0x8
	  li        r3, 0
	  stfs      f30, 0xA4(r1)
	  stfs      f30, 0x94(r1)
	  ble-      .loc_0x514
	  stfs      f31, 0x70(r1)
	  li        r3, 0x8
	  stfs      f31, 0x74(r1)
	  stfs      f31, 0x78(r1)
	  stfs      f31, 0x7C(r1)
	  stfs      f31, 0x80(r1)
	  stfs      f31, 0x84(r1)
	  stfs      f31, 0x88(r1)
	  stfs      f31, 0x8C(r1)
	  b         .loc_0x514

	.loc_0x25C:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0x278

	.loc_0x26C:
	  stfs      f31, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0x26C

	.loc_0x278:
	  lfs       f2, -0x14(r13)
	  mr        r3, r31
	  stfs      f30, 0x90(r1)
	  addi      r4, r1, 0x94
	  lfs       f1, -0x10(r13)
	  stfs      f31, 0x68(r1)
	  lfs       f0, -0xC(r13)
	  stfs      f31, 0x58(r1)
	  stfs      f2, 0x44(r1)
	  stfs      f30, 0x80(r1)
	  stfs      f31, 0x64(r1)
	  stfs      f31, 0x54(r1)
	  stfs      f1, 0x48(r1)
	  stfs      f30, 0x70(r1)
	  stfs      f31, 0x60(r1)
	  stfs      f31, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  bl        0x1A0C8
	  addi      r3, r1, 0x60
	  addi      r4, r1, 0x94
	  bl        -0x12AEA4
	  addi      r3, r30, 0x484
	  addi      r4, r1, 0x70
	  bl        0x1A0B0
	  addi      r3, r1, 0x50
	  addi      r4, r1, 0x70
	  bl        -0x12AEBC
	  lfs       f1, 0xC(r25)
	  addi      r3, r1, 0x50
	  addi      r4, r1, 0x60
	  li        r5, 0
	  bl        -0x12A608
	  cmpwi     r26, 0x7
	  bge-      .loc_0x374
	  stfs      f31, 0x40(r1)
	  stfs      f31, 0x3C(r1)
	  stfs      f31, 0x38(r1)
	  lfs       f1, 0x68(r29)
	  lfs       f0, 0x5C(r29)
	  lfs       f4, 0x70(r29)
	  lfs       f3, 0x64(r29)
	  fsubs     f0, f1, f0
	  lfs       f2, 0x6C(r29)
	  lfs       f1, 0x60(r29)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x34(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f1, 0x3C(r1)
	  stfs      f3, 0x40(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f0, 0x3C(r1)
	  lfs       f2, 0x40(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x154BBC
	  lfs       f0, 0x14(r28)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x44(r1)

	.loc_0x374:
	  addi      r3, r31, 0
	  addi      r4, r29, 0x5C
	  addi      r5, r1, 0x50
	  addi      r6, r1, 0x44
	  bl        -0x123B18
	  lwz       r3, 0x0(r31)
	  addi      r26, r26, 0x1
	  lwz       r0, 0x4(r31)
	  cmpwi     r26, 0x8
	  addi      r29, r29, 0xC
	  stw       r3, 0x684(r30)
	  addi      r28, r28, 0x4
	  stw       r0, 0x688(r30)
	  lwz       r3, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  stw       r3, 0x68C(r30)
	  stw       r0, 0x690(r30)
	  lwz       r3, 0x10(r31)
	  lwz       r0, 0x14(r31)
	  stw       r3, 0x694(r30)
	  stw       r0, 0x698(r30)
	  lwz       r3, 0x18(r31)
	  lwz       r0, 0x1C(r31)
	  stw       r3, 0x69C(r30)
	  stw       r0, 0x6A0(r30)
	  lwz       r3, 0x20(r31)
	  lwz       r0, 0x24(r31)
	  stw       r3, 0x6A4(r30)
	  stw       r0, 0x6A8(r30)
	  lwz       r3, 0x28(r31)
	  lwz       r0, 0x2C(r31)
	  stw       r3, 0x6AC(r30)
	  stw       r0, 0x6B0(r30)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x34(r31)
	  stw       r3, 0x6B4(r30)
	  stw       r0, 0x6B8(r30)
	  lwz       r3, 0x38(r31)
	  lwz       r0, 0x3C(r31)
	  addi      r31, r31, 0x40
	  stw       r3, 0x6BC(r30)
	  stw       r0, 0x6C0(r30)
	  addi      r30, r30, 0x40
	  blt+      .loc_0x1CC
	  b         .loc_0x4E8

	.loc_0x428:
	  lfs       f0, 0xC(r4)
	  stfs      f0, 0x5C(r25)
	  lfs       f0, 0x1C(r4)
	  stfs      f0, 0x60(r25)
	  lfs       f0, 0x2C(r4)
	  stfs      f0, 0x64(r25)
	  lfs       f0, 0x4C(r4)
	  stfs      f0, 0x68(r25)
	  lfs       f0, 0x5C(r4)
	  stfs      f0, 0x6C(r25)
	  lfs       f0, 0x6C(r4)
	  stfs      f0, 0x70(r25)
	  lfs       f0, 0x8C(r4)
	  stfs      f0, 0x74(r25)
	  lfs       f0, 0x9C(r4)
	  stfs      f0, 0x78(r25)
	  lfs       f0, 0xAC(r4)
	  stfs      f0, 0x7C(r25)
	  lfs       f0, 0xCC(r4)
	  stfs      f0, 0x80(r25)
	  lfs       f0, 0xDC(r4)
	  stfs      f0, 0x84(r25)
	  lfs       f0, 0xEC(r4)
	  stfs      f0, 0x88(r25)
	  lfs       f0, 0x10C(r4)
	  stfs      f0, 0x8C(r25)
	  lfs       f0, 0x11C(r4)
	  stfs      f0, 0x90(r25)
	  lfs       f0, 0x12C(r4)
	  stfs      f0, 0x94(r25)
	  lfs       f0, 0x14C(r4)
	  stfs      f0, 0x98(r25)
	  lfs       f0, 0x15C(r4)
	  stfs      f0, 0x9C(r25)
	  lfs       f0, 0x16C(r4)
	  stfs      f0, 0xA0(r25)
	  lfs       f0, 0x18C(r4)
	  stfs      f0, 0xA4(r25)
	  lfs       f0, 0x19C(r4)
	  stfs      f0, 0xA8(r25)
	  lfs       f0, 0x1AC(r4)
	  stfs      f0, 0xAC(r25)
	  lfs       f0, 0x1CC(r4)
	  stfs      f0, 0xB0(r25)
	  lfs       f0, 0x1DC(r4)
	  stfs      f0, 0xB4(r25)
	  lfs       f0, 0x1EC(r4)
	  stfs      f0, 0xB8(r25)

	.loc_0x4E8:
	  lwz       r3, 0xB0(r25)
	  lwz       r0, 0xB4(r25)
	  stw       r3, 0x50(r25)
	  stw       r0, 0x54(r25)
	  lwz       r0, 0xB8(r25)
	  stw       r0, 0x58(r25)
	  b         .loc_0x524

	.loc_0x504:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0x94
	  add       r4, r4, r0
	  b         .loc_0x200

	.loc_0x514:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0x70
	  add       r4, r4, r0
	  b         .loc_0x25C

	.loc_0x524:
	  lmw       r25, 0xBC(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801629D8
 * Size:	00010C
 */
void SnakeBody::setDeadPattern01(Matrix4f*)
{
	/*
	.loc_0x0:
	  li        r0, 0x8
	  mtctr     r0
	  li        r5, 0

	.loc_0xC:
	  lfs       f1, 0x0(r4)
	  cmpwi     r5, 0x7
	  lfs       f0, 0x30(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x0(r4)
	  lfs       f1, 0x10(r4)
	  lfs       f0, 0x30(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x10(r4)
	  lfs       f1, 0x20(r4)
	  lfs       f0, 0x30(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x20(r4)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x30(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x4(r4)
	  lfs       f1, 0x14(r4)
	  lfs       f0, 0x30(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x14(r4)
	  lfs       f1, 0x24(r4)
	  lfs       f0, 0x30(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x24(r4)
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x30(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x8(r4)
	  lfs       f1, 0x18(r4)
	  lfs       f0, 0x30(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x18(r4)
	  lfs       f1, 0x28(r4)
	  lfs       f0, 0x30(r3)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x28(r4)
	  bge-      .loc_0xF8
	  lfs       f2, 0xC(r4)
	  lfs       f0, 0x4C(r4)
	  lfs       f1, 0x30(r3)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x4C(r4)
	  lfs       f2, 0x1C(r4)
	  lfs       f0, 0x5C(r4)
	  lfs       f1, 0x30(r3)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x5C(r4)
	  lfs       f2, 0x2C(r4)
	  lfs       f0, 0x6C(r4)
	  lfs       f1, 0x30(r3)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x6C(r4)

	.loc_0xF8:
	  addi      r3, r3, 0x4
	  addi      r4, r4, 0x40
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000268
 */
void SnakeBody::setDeadPattern02(Matrix4f*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void SnakeBody::setDeadScale(Matrix4f*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80162AE4
 * Size:	0001E0
 */
void SnakeBody::returnJoint(BossShapeObject*, Graphics&, Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x170(r1)
	  stmw      r27, 0x15C(r1)
	  mr        r31, r4
	  addi      r27, r5, 0
	  addi      r28, r6, 0
	  lwz       r3, 0x0(r4)
	  li        r4, 0x7
	  bl        -0x12DB20
	  addi      r4, r1, 0x98
	  bl        -0x1246D4
	  lwz       r3, 0x0(r31)
	  li        r4, 0x8
	  bl        -0x12DB34
	  addi      r4, r1, 0xD8
	  bl        -0x1246E8
	  lwz       r3, 0x0(r31)
	  li        r4, 0xB
	  bl        -0x12DB48
	  addi      r4, r1, 0x58
	  bl        -0x1246FC
	  li        r29, 0
	  rlwinm    r0,r29,6,0,25
	  add       r30, r28, r0
	  li        r28, 0

	.loc_0x68:
	  lwz       r3, 0x0(r31)
	  mr        r4, r28
	  bl        -0x12DB6C
	  lwz       r6, 0x2E4(r27)
	  addi      r5, r3, 0
	  addi      r4, r30, 0
	  addi      r3, r6, 0x1E0
	  bl        -0x124A94
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x8
	  addi      r30, r30, 0x40
	  addi      r28, r28, 0x1
	  blt+      .loc_0x68
	  lwz       r3, 0x0(r31)
	  li        r4, 0x8
	  bl        -0x12DBA0
	  addi      r4, r3, 0
	  addi      r3, r1, 0x98
	  addi      r5, r1, 0x18
	  bl        -0x124AC4
	  lwz       r3, 0x0(r31)
	  li        r4, 0x8
	  bl        -0x12DBBC
	  mr        r30, r3
	  lwz       r3, 0x0(r31)
	  li        r4, 0x7
	  bl        -0x12DBCC
	  addi      r5, r30, 0
	  addi      r4, r1, 0x18
	  bl        -0x124AEC
	  li        r29, 0x9

	.loc_0xE4:
	  lwz       r3, 0x0(r31)
	  mr        r4, r29
	  bl        -0x12DBE8
	  addi      r4, r3, 0
	  addi      r3, r1, 0xD8
	  addi      r5, r1, 0x18
	  bl        -0x124B0C
	  lwz       r3, 0x0(r31)
	  mr        r4, r29
	  bl        -0x12DC04
	  mr        r30, r3
	  lwz       r3, 0x0(r31)
	  li        r4, 0x8
	  bl        -0x12DC14
	  addi      r5, r30, 0
	  addi      r4, r1, 0x18
	  bl        -0x124B34
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0xA
	  ble+      .loc_0xE4
	  lwz       r3, 0x0(r31)
	  li        r4, 0xB
	  bl        -0x12DC38
	  addi      r4, r3, 0
	  addi      r3, r1, 0x98
	  addi      r5, r1, 0x18
	  bl        -0x124B5C
	  lwz       r3, 0x0(r31)
	  li        r4, 0xB
	  bl        -0x12DC54
	  mr        r30, r3
	  lwz       r3, 0x0(r31)
	  li        r4, 0x7
	  bl        -0x12DC64
	  addi      r5, r30, 0
	  addi      r4, r1, 0x18
	  bl        -0x124B84
	  li        r29, 0xC

	.loc_0x17C:
	  lwz       r3, 0x0(r31)
	  mr        r4, r29
	  bl        -0x12DC80
	  addi      r4, r3, 0
	  addi      r3, r1, 0x58
	  addi      r5, r1, 0x18
	  bl        -0x124BA4
	  lwz       r3, 0x0(r31)
	  mr        r4, r29
	  bl        -0x12DC9C
	  mr        r30, r3
	  lwz       r3, 0x0(r31)
	  li        r4, 0xB
	  bl        -0x12DCAC
	  addi      r5, r30, 0
	  addi      r4, r1, 0x18
	  bl        -0x124BCC
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0xE
	  ble+      .loc_0x17C
	  lmw       r27, 0x15C(r1)
	  lwz       r0, 0x174(r1)
	  addi      r1, r1, 0x170
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80162CC4
 * Size:	0009B8
 */
void SnakeBody::refresh(BossShapeObject*, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2E0(r1)
	  stfd      f31, 0x2D8(r1)
	  stfd      f30, 0x2D0(r1)
	  stmw      r26, 0x2B8(r1)
	  mr        r28, r5
	  addi      r27, r4, 0
	  addi      r26, r3, 0
	  addi      r4, r1, 0x74
	  lwz       r5, 0x2E4(r5)
	  addi      r3, r5, 0x1E0
	  bl        -0x1248B8
	  li        r30, 0
	  lfs       f30, -0x554C(r2)
	  rlwinm    r0,r30,6,0,25
	  lfs       f31, -0x5548(r2)
	  addi      r31, r30, 0
	  add       r29, r26, r0

	.loc_0x4C:
	  lwz       r3, 0x0(r27)
	  mr        r4, r31
	  bl        -0x12DD30
	  lwz       r6, 0x0(r3)
	  addi      r4, r1, 0x34
	  lwz       r0, 0x4(r3)
	  addi      r5, r29, 0x284
	  stw       r6, 0x34(r1)
	  stw       r0, 0x38(r1)
	  lwz       r6, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  stw       r6, 0x3C(r1)
	  stw       r0, 0x40(r1)
	  lwz       r6, 0x10(r3)
	  lwz       r0, 0x14(r3)
	  stw       r6, 0x44(r1)
	  stw       r0, 0x48(r1)
	  lwz       r6, 0x18(r3)
	  lwz       r0, 0x1C(r3)
	  stw       r6, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  lwz       r6, 0x20(r3)
	  lwz       r0, 0x24(r3)
	  stw       r6, 0x54(r1)
	  stw       r0, 0x58(r1)
	  lwz       r6, 0x28(r3)
	  lwz       r0, 0x2C(r3)
	  stw       r6, 0x5C(r1)
	  stw       r0, 0x60(r1)
	  lwz       r6, 0x30(r3)
	  lwz       r0, 0x34(r3)
	  stw       r6, 0x64(r1)
	  stw       r0, 0x68(r1)
	  lwz       r6, 0x38(r3)
	  lwz       r0, 0x3C(r3)
	  addi      r3, r1, 0x74
	  stw       r6, 0x6C(r1)
	  stw       r0, 0x70(r1)
	  stfs      f30, 0x64(r1)
	  stfs      f30, 0x68(r1)
	  stfs      f30, 0x6C(r1)
	  stfs      f31, 0x70(r1)
	  bl        -0x124CE4
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x8
	  addi      r29, r29, 0x40
	  addi      r31, r31, 0x1
	  blt+      .loc_0x4C
	  mr        r3, r26
	  bl        -0x189C
	  mr        r3, r26
	  bl        -0x16AC
	  mr        r3, r26
	  bl        -0x151C
	  mr        r3, r26
	  bl        -0x1230
	  addi      r3, r26, 0
	  addi      r4, r1, 0xB4
	  bl        -0xE84
	  lfs       f1, -0x554C(r2)
	  lfs       f0, 0xC(r26)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x54C
	  lwz       r3, 0xB4(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r3, 0x484(r26)
	  stw       r0, 0x488(r26)
	  lwz       r3, 0xBC(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r3, 0x48C(r26)
	  stw       r0, 0x490(r26)
	  lwz       r3, 0xC4(r1)
	  lwz       r0, 0xC8(r1)
	  stw       r3, 0x494(r26)
	  stw       r0, 0x498(r26)
	  lwz       r3, 0xCC(r1)
	  lwz       r0, 0xD0(r1)
	  stw       r3, 0x49C(r26)
	  stw       r0, 0x4A0(r26)
	  lwz       r3, 0xD4(r1)
	  lwz       r0, 0xD8(r1)
	  stw       r3, 0x4A4(r26)
	  stw       r0, 0x4A8(r26)
	  lwz       r3, 0xDC(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r3, 0x4AC(r26)
	  stw       r0, 0x4B0(r26)
	  lwz       r3, 0xE4(r1)
	  lwz       r0, 0xE8(r1)
	  stw       r3, 0x4B4(r26)
	  stw       r0, 0x4B8(r26)
	  lwz       r3, 0xEC(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r3, 0x4BC(r26)
	  stw       r0, 0x4C0(r26)
	  lwz       r3, 0xF4(r1)
	  lwz       r0, 0xF8(r1)
	  stw       r3, 0x4C4(r26)
	  stw       r0, 0x4C8(r26)
	  lwz       r3, 0xFC(r1)
	  lwz       r0, 0x100(r1)
	  stw       r3, 0x4CC(r26)
	  stw       r0, 0x4D0(r26)
	  lwz       r3, 0x104(r1)
	  lwz       r0, 0x108(r1)
	  stw       r3, 0x4D4(r26)
	  stw       r0, 0x4D8(r26)
	  lwz       r3, 0x10C(r1)
	  lwz       r0, 0x110(r1)
	  stw       r3, 0x4DC(r26)
	  stw       r0, 0x4E0(r26)
	  lwz       r3, 0x114(r1)
	  lwz       r0, 0x118(r1)
	  stw       r3, 0x4E4(r26)
	  stw       r0, 0x4E8(r26)
	  lwz       r3, 0x11C(r1)
	  lwz       r0, 0x120(r1)
	  stw       r3, 0x4EC(r26)
	  stw       r0, 0x4F0(r26)
	  lwz       r3, 0x124(r1)
	  lwz       r0, 0x128(r1)
	  stw       r3, 0x4F4(r26)
	  stw       r0, 0x4F8(r26)
	  lwz       r3, 0x12C(r1)
	  lwz       r0, 0x130(r1)
	  stw       r3, 0x4FC(r26)
	  stw       r0, 0x500(r26)
	  lwz       r3, 0x134(r1)
	  lwz       r0, 0x138(r1)
	  stw       r3, 0x504(r26)
	  stw       r0, 0x508(r26)
	  lwz       r3, 0x13C(r1)
	  lwz       r0, 0x140(r1)
	  stw       r3, 0x50C(r26)
	  stw       r0, 0x510(r26)
	  lwz       r3, 0x144(r1)
	  lwz       r0, 0x148(r1)
	  stw       r3, 0x514(r26)
	  stw       r0, 0x518(r26)
	  lwz       r3, 0x14C(r1)
	  lwz       r0, 0x150(r1)
	  stw       r3, 0x51C(r26)
	  stw       r0, 0x520(r26)
	  lwz       r3, 0x154(r1)
	  lwz       r0, 0x158(r1)
	  stw       r3, 0x524(r26)
	  stw       r0, 0x528(r26)
	  lwz       r3, 0x15C(r1)
	  lwz       r0, 0x160(r1)
	  stw       r3, 0x52C(r26)
	  stw       r0, 0x530(r26)
	  lwz       r3, 0x164(r1)
	  lwz       r0, 0x168(r1)
	  stw       r3, 0x534(r26)
	  stw       r0, 0x538(r26)
	  lwz       r3, 0x16C(r1)
	  lwz       r0, 0x170(r1)
	  stw       r3, 0x53C(r26)
	  stw       r0, 0x540(r26)
	  lwz       r3, 0x174(r1)
	  lwz       r0, 0x178(r1)
	  stw       r3, 0x544(r26)
	  stw       r0, 0x548(r26)
	  lwz       r3, 0x17C(r1)
	  lwz       r0, 0x180(r1)
	  stw       r3, 0x54C(r26)
	  stw       r0, 0x550(r26)
	  lwz       r3, 0x184(r1)
	  lwz       r0, 0x188(r1)
	  stw       r3, 0x554(r26)
	  stw       r0, 0x558(r26)
	  lwz       r3, 0x18C(r1)
	  lwz       r0, 0x190(r1)
	  stw       r3, 0x55C(r26)
	  stw       r0, 0x560(r26)
	  lwz       r3, 0x194(r1)
	  lwz       r0, 0x198(r1)
	  stw       r3, 0x564(r26)
	  stw       r0, 0x568(r26)
	  lwz       r3, 0x19C(r1)
	  lwz       r0, 0x1A0(r1)
	  stw       r3, 0x56C(r26)
	  stw       r0, 0x570(r26)
	  lwz       r3, 0x1A4(r1)
	  lwz       r0, 0x1A8(r1)
	  stw       r3, 0x574(r26)
	  stw       r0, 0x578(r26)
	  lwz       r3, 0x1AC(r1)
	  lwz       r0, 0x1B0(r1)
	  stw       r3, 0x57C(r26)
	  stw       r0, 0x580(r26)
	  lwz       r3, 0x1B4(r1)
	  lwz       r0, 0x1B8(r1)
	  stw       r3, 0x584(r26)
	  stw       r0, 0x588(r26)
	  lwz       r3, 0x1BC(r1)
	  lwz       r0, 0x1C0(r1)
	  stw       r3, 0x58C(r26)
	  stw       r0, 0x590(r26)
	  lwz       r3, 0x1C4(r1)
	  lwz       r0, 0x1C8(r1)
	  stw       r3, 0x594(r26)
	  stw       r0, 0x598(r26)
	  lwz       r3, 0x1CC(r1)
	  lwz       r0, 0x1D0(r1)
	  stw       r3, 0x59C(r26)
	  stw       r0, 0x5A0(r26)
	  lwz       r3, 0x1D4(r1)
	  lwz       r0, 0x1D8(r1)
	  stw       r3, 0x5A4(r26)
	  stw       r0, 0x5A8(r26)
	  lwz       r3, 0x1DC(r1)
	  lwz       r0, 0x1E0(r1)
	  stw       r3, 0x5AC(r26)
	  stw       r0, 0x5B0(r26)
	  lwz       r3, 0x1E4(r1)
	  lwz       r0, 0x1E8(r1)
	  stw       r3, 0x5B4(r26)
	  stw       r0, 0x5B8(r26)
	  lwz       r3, 0x1EC(r1)
	  lwz       r0, 0x1F0(r1)
	  stw       r3, 0x5BC(r26)
	  stw       r0, 0x5C0(r26)
	  lwz       r3, 0x1F4(r1)
	  lwz       r0, 0x1F8(r1)
	  stw       r3, 0x5C4(r26)
	  stw       r0, 0x5C8(r26)
	  lwz       r3, 0x1FC(r1)
	  lwz       r0, 0x200(r1)
	  stw       r3, 0x5CC(r26)
	  stw       r0, 0x5D0(r26)
	  lwz       r3, 0x204(r1)
	  lwz       r0, 0x208(r1)
	  stw       r3, 0x5D4(r26)
	  stw       r0, 0x5D8(r26)
	  lwz       r3, 0x20C(r1)
	  lwz       r0, 0x210(r1)
	  stw       r3, 0x5DC(r26)
	  stw       r0, 0x5E0(r26)
	  lwz       r3, 0x214(r1)
	  lwz       r0, 0x218(r1)
	  stw       r3, 0x5E4(r26)
	  stw       r0, 0x5E8(r26)
	  lwz       r3, 0x21C(r1)
	  lwz       r0, 0x220(r1)
	  stw       r3, 0x5EC(r26)
	  stw       r0, 0x5F0(r26)
	  lwz       r3, 0x224(r1)
	  lwz       r0, 0x228(r1)
	  stw       r3, 0x5F4(r26)
	  stw       r0, 0x5F8(r26)
	  lwz       r3, 0x22C(r1)
	  lwz       r0, 0x230(r1)
	  stw       r3, 0x5FC(r26)
	  stw       r0, 0x600(r26)
	  lwz       r3, 0x234(r1)
	  lwz       r0, 0x238(r1)
	  stw       r3, 0x604(r26)
	  stw       r0, 0x608(r26)
	  lwz       r3, 0x23C(r1)
	  lwz       r0, 0x240(r1)
	  stw       r3, 0x60C(r26)
	  stw       r0, 0x610(r26)
	  lwz       r3, 0x244(r1)
	  lwz       r0, 0x248(r1)
	  stw       r3, 0x614(r26)
	  stw       r0, 0x618(r26)
	  lwz       r3, 0x24C(r1)
	  lwz       r0, 0x250(r1)
	  stw       r3, 0x61C(r26)
	  stw       r0, 0x620(r26)
	  lwz       r3, 0x254(r1)
	  lwz       r0, 0x258(r1)
	  stw       r3, 0x624(r26)
	  stw       r0, 0x628(r26)
	  lwz       r3, 0x25C(r1)
	  lwz       r0, 0x260(r1)
	  stw       r3, 0x62C(r26)
	  stw       r0, 0x630(r26)
	  lwz       r3, 0x264(r1)
	  lwz       r0, 0x268(r1)
	  stw       r3, 0x634(r26)
	  stw       r0, 0x638(r26)
	  lwz       r3, 0x26C(r1)
	  lwz       r0, 0x270(r1)
	  stw       r3, 0x63C(r26)
	  stw       r0, 0x640(r26)
	  lwz       r3, 0x274(r1)
	  lwz       r0, 0x278(r1)
	  stw       r3, 0x644(r26)
	  stw       r0, 0x648(r26)
	  lwz       r3, 0x27C(r1)
	  lwz       r0, 0x280(r1)
	  stw       r3, 0x64C(r26)
	  stw       r0, 0x650(r26)
	  lwz       r3, 0x284(r1)
	  lwz       r0, 0x288(r1)
	  stw       r3, 0x654(r26)
	  stw       r0, 0x658(r26)
	  lwz       r3, 0x28C(r1)
	  lwz       r0, 0x290(r1)
	  stw       r3, 0x65C(r26)
	  stw       r0, 0x660(r26)
	  lwz       r3, 0x294(r1)
	  lwz       r0, 0x298(r1)
	  stw       r3, 0x664(r26)
	  stw       r0, 0x668(r26)
	  lwz       r3, 0x29C(r1)
	  lwz       r0, 0x2A0(r1)
	  stw       r3, 0x66C(r26)
	  stw       r0, 0x670(r26)
	  lwz       r3, 0x2A4(r1)
	  lwz       r0, 0x2A8(r1)
	  stw       r3, 0x674(r26)
	  stw       r0, 0x678(r26)
	  lwz       r3, 0x2AC(r1)
	  lwz       r0, 0x2B0(r1)
	  stw       r3, 0x67C(r26)
	  stw       r0, 0x680(r26)
	  b         .loc_0x960

	.loc_0x54C:
	  lbz       r0, 0x5(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x960
	  lwz       r3, 0x684(r26)
	  lwz       r0, 0x688(r26)
	  stw       r3, 0x484(r26)
	  stw       r0, 0x488(r26)
	  lwz       r3, 0x68C(r26)
	  lwz       r0, 0x690(r26)
	  stw       r3, 0x48C(r26)
	  stw       r0, 0x490(r26)
	  lwz       r3, 0x694(r26)
	  lwz       r0, 0x698(r26)
	  stw       r3, 0x494(r26)
	  stw       r0, 0x498(r26)
	  lwz       r3, 0x69C(r26)
	  lwz       r0, 0x6A0(r26)
	  stw       r3, 0x49C(r26)
	  stw       r0, 0x4A0(r26)
	  lwz       r3, 0x6A4(r26)
	  lwz       r0, 0x6A8(r26)
	  stw       r3, 0x4A4(r26)
	  stw       r0, 0x4A8(r26)
	  lwz       r3, 0x6AC(r26)
	  lwz       r0, 0x6B0(r26)
	  stw       r3, 0x4AC(r26)
	  stw       r0, 0x4B0(r26)
	  lwz       r3, 0x6B4(r26)
	  lwz       r0, 0x6B8(r26)
	  stw       r3, 0x4B4(r26)
	  stw       r0, 0x4B8(r26)
	  lwz       r3, 0x6BC(r26)
	  lwz       r0, 0x6C0(r26)
	  stw       r3, 0x4BC(r26)
	  stw       r0, 0x4C0(r26)
	  lwz       r3, 0x6C4(r26)
	  lwz       r0, 0x6C8(r26)
	  stw       r3, 0x4C4(r26)
	  stw       r0, 0x4C8(r26)
	  lwz       r3, 0x6CC(r26)
	  lwz       r0, 0x6D0(r26)
	  stw       r3, 0x4CC(r26)
	  stw       r0, 0x4D0(r26)
	  lwz       r3, 0x6D4(r26)
	  lwz       r0, 0x6D8(r26)
	  stw       r3, 0x4D4(r26)
	  stw       r0, 0x4D8(r26)
	  lwz       r3, 0x6DC(r26)
	  lwz       r0, 0x6E0(r26)
	  stw       r3, 0x4DC(r26)
	  stw       r0, 0x4E0(r26)
	  lwz       r3, 0x6E4(r26)
	  lwz       r0, 0x6E8(r26)
	  stw       r3, 0x4E4(r26)
	  stw       r0, 0x4E8(r26)
	  lwz       r3, 0x6EC(r26)
	  lwz       r0, 0x6F0(r26)
	  stw       r3, 0x4EC(r26)
	  stw       r0, 0x4F0(r26)
	  lwz       r3, 0x6F4(r26)
	  lwz       r0, 0x6F8(r26)
	  stw       r3, 0x4F4(r26)
	  stw       r0, 0x4F8(r26)
	  lwz       r3, 0x6FC(r26)
	  lwz       r0, 0x700(r26)
	  stw       r3, 0x4FC(r26)
	  stw       r0, 0x500(r26)
	  lwz       r3, 0x704(r26)
	  lwz       r0, 0x708(r26)
	  stw       r3, 0x504(r26)
	  stw       r0, 0x508(r26)
	  lwz       r3, 0x70C(r26)
	  lwz       r0, 0x710(r26)
	  stw       r3, 0x50C(r26)
	  stw       r0, 0x510(r26)
	  lwz       r3, 0x714(r26)
	  lwz       r0, 0x718(r26)
	  stw       r3, 0x514(r26)
	  stw       r0, 0x518(r26)
	  lwz       r3, 0x71C(r26)
	  lwz       r0, 0x720(r26)
	  stw       r3, 0x51C(r26)
	  stw       r0, 0x520(r26)
	  lwz       r3, 0x724(r26)
	  lwz       r0, 0x728(r26)
	  stw       r3, 0x524(r26)
	  stw       r0, 0x528(r26)
	  lwz       r3, 0x72C(r26)
	  lwz       r0, 0x730(r26)
	  stw       r3, 0x52C(r26)
	  stw       r0, 0x530(r26)
	  lwz       r3, 0x734(r26)
	  lwz       r0, 0x738(r26)
	  stw       r3, 0x534(r26)
	  stw       r0, 0x538(r26)
	  lwz       r3, 0x73C(r26)
	  lwz       r0, 0x740(r26)
	  stw       r3, 0x53C(r26)
	  stw       r0, 0x540(r26)
	  lwz       r3, 0x744(r26)
	  lwz       r0, 0x748(r26)
	  stw       r3, 0x544(r26)
	  stw       r0, 0x548(r26)
	  lwz       r3, 0x74C(r26)
	  lwz       r0, 0x750(r26)
	  stw       r3, 0x54C(r26)
	  stw       r0, 0x550(r26)
	  lwz       r3, 0x754(r26)
	  lwz       r0, 0x758(r26)
	  stw       r3, 0x554(r26)
	  stw       r0, 0x558(r26)
	  lwz       r3, 0x75C(r26)
	  lwz       r0, 0x760(r26)
	  stw       r3, 0x55C(r26)
	  stw       r0, 0x560(r26)
	  lwz       r3, 0x764(r26)
	  lwz       r0, 0x768(r26)
	  stw       r3, 0x564(r26)
	  stw       r0, 0x568(r26)
	  lwz       r3, 0x76C(r26)
	  lwz       r0, 0x770(r26)
	  stw       r3, 0x56C(r26)
	  stw       r0, 0x570(r26)
	  lwz       r3, 0x774(r26)
	  lwz       r0, 0x778(r26)
	  stw       r3, 0x574(r26)
	  stw       r0, 0x578(r26)
	  lwz       r3, 0x77C(r26)
	  lwz       r0, 0x780(r26)
	  stw       r3, 0x57C(r26)
	  stw       r0, 0x580(r26)
	  lwz       r3, 0x784(r26)
	  lwz       r0, 0x788(r26)
	  stw       r3, 0x584(r26)
	  stw       r0, 0x588(r26)
	  lwz       r3, 0x78C(r26)
	  lwz       r0, 0x790(r26)
	  stw       r3, 0x58C(r26)
	  stw       r0, 0x590(r26)
	  lwz       r3, 0x794(r26)
	  lwz       r0, 0x798(r26)
	  stw       r3, 0x594(r26)
	  stw       r0, 0x598(r26)
	  lwz       r3, 0x79C(r26)
	  lwz       r0, 0x7A0(r26)
	  stw       r3, 0x59C(r26)
	  stw       r0, 0x5A0(r26)
	  lwz       r3, 0x7A4(r26)
	  lwz       r0, 0x7A8(r26)
	  stw       r3, 0x5A4(r26)
	  stw       r0, 0x5A8(r26)
	  lwz       r3, 0x7AC(r26)
	  lwz       r0, 0x7B0(r26)
	  stw       r3, 0x5AC(r26)
	  stw       r0, 0x5B0(r26)
	  lwz       r3, 0x7B4(r26)
	  lwz       r0, 0x7B8(r26)
	  stw       r3, 0x5B4(r26)
	  stw       r0, 0x5B8(r26)
	  lwz       r3, 0x7BC(r26)
	  lwz       r0, 0x7C0(r26)
	  stw       r3, 0x5BC(r26)
	  stw       r0, 0x5C0(r26)
	  lwz       r3, 0x7C4(r26)
	  lwz       r0, 0x7C8(r26)
	  stw       r3, 0x5C4(r26)
	  stw       r0, 0x5C8(r26)
	  lwz       r3, 0x7CC(r26)
	  lwz       r0, 0x7D0(r26)
	  stw       r3, 0x5CC(r26)
	  stw       r0, 0x5D0(r26)
	  lwz       r3, 0x7D4(r26)
	  lwz       r0, 0x7D8(r26)
	  stw       r3, 0x5D4(r26)
	  stw       r0, 0x5D8(r26)
	  lwz       r3, 0x7DC(r26)
	  lwz       r0, 0x7E0(r26)
	  stw       r3, 0x5DC(r26)
	  stw       r0, 0x5E0(r26)
	  lwz       r3, 0x7E4(r26)
	  lwz       r0, 0x7E8(r26)
	  stw       r3, 0x5E4(r26)
	  stw       r0, 0x5E8(r26)
	  lwz       r3, 0x7EC(r26)
	  lwz       r0, 0x7F0(r26)
	  stw       r3, 0x5EC(r26)
	  stw       r0, 0x5F0(r26)
	  lwz       r3, 0x7F4(r26)
	  lwz       r0, 0x7F8(r26)
	  stw       r3, 0x5F4(r26)
	  stw       r0, 0x5F8(r26)
	  lwz       r3, 0x7FC(r26)
	  lwz       r0, 0x800(r26)
	  stw       r3, 0x5FC(r26)
	  stw       r0, 0x600(r26)
	  lwz       r3, 0x804(r26)
	  lwz       r0, 0x808(r26)
	  stw       r3, 0x604(r26)
	  stw       r0, 0x608(r26)
	  lwz       r3, 0x80C(r26)
	  lwz       r0, 0x810(r26)
	  stw       r3, 0x60C(r26)
	  stw       r0, 0x610(r26)
	  lwz       r3, 0x814(r26)
	  lwz       r0, 0x818(r26)
	  stw       r3, 0x614(r26)
	  stw       r0, 0x618(r26)
	  lwz       r3, 0x81C(r26)
	  lwz       r0, 0x820(r26)
	  stw       r3, 0x61C(r26)
	  stw       r0, 0x620(r26)
	  lwz       r3, 0x824(r26)
	  lwz       r0, 0x828(r26)
	  stw       r3, 0x624(r26)
	  stw       r0, 0x628(r26)
	  lwz       r3, 0x82C(r26)
	  lwz       r0, 0x830(r26)
	  stw       r3, 0x62C(r26)
	  stw       r0, 0x630(r26)
	  lwz       r3, 0x834(r26)
	  lwz       r0, 0x838(r26)
	  stw       r3, 0x634(r26)
	  stw       r0, 0x638(r26)
	  lwz       r3, 0x83C(r26)
	  lwz       r0, 0x840(r26)
	  stw       r3, 0x63C(r26)
	  stw       r0, 0x640(r26)
	  lwz       r3, 0x844(r26)
	  lwz       r0, 0x848(r26)
	  stw       r3, 0x644(r26)
	  stw       r0, 0x648(r26)
	  lwz       r3, 0x84C(r26)
	  lwz       r0, 0x850(r26)
	  stw       r3, 0x64C(r26)
	  stw       r0, 0x650(r26)
	  lwz       r3, 0x854(r26)
	  lwz       r0, 0x858(r26)
	  stw       r3, 0x654(r26)
	  stw       r0, 0x658(r26)
	  lwz       r3, 0x85C(r26)
	  lwz       r0, 0x860(r26)
	  stw       r3, 0x65C(r26)
	  stw       r0, 0x660(r26)
	  lwz       r3, 0x864(r26)
	  lwz       r0, 0x868(r26)
	  stw       r3, 0x664(r26)
	  stw       r0, 0x668(r26)
	  lwz       r3, 0x86C(r26)
	  lwz       r0, 0x870(r26)
	  stw       r3, 0x66C(r26)
	  stw       r0, 0x670(r26)
	  lwz       r3, 0x874(r26)
	  lwz       r0, 0x878(r26)
	  stw       r3, 0x674(r26)
	  stw       r0, 0x678(r26)
	  lwz       r3, 0x87C(r26)
	  lwz       r0, 0x880(r26)
	  stw       r3, 0x67C(r26)
	  stw       r0, 0x680(r26)
	  li        r0, 0
	  stb       r0, 0x5(r26)

	.loc_0x960:
	  addi      r3, r26, 0
	  addi      r4, r1, 0xB4
	  bl        -0x1194
	  lwz       r3, 0x0(r26)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x988
	  addi      r3, r26, 0
	  addi      r4, r1, 0xB4
	  bl        -0xC70

	.loc_0x988:
	  addi      r3, r26, 0
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  addi      r6, r1, 0xB4
	  bl        -0xB78
	  lmw       r26, 0x2B8(r1)
	  lwz       r0, 0x2E4(r1)
	  lfd       f31, 0x2D8(r1)
	  lfd       f30, 0x2D0(r1)
	  addi      r1, r1, 0x2E0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8016367C
 * Size:	000064
 */
void SnakeGenBodyRotateCallBack::invoke(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r3)
	  lwz       r5, 0x3C8(r5)
	  lbz       r0, 0x4(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x24
	  lwz       r0, 0x80(r4)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r4)
	  b         .loc_0x30

	.loc_0x24:
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r4)

	.loc_0x30:
	  lwz       r3, 0x4(r3)
	  lfs       f0, -0x554C(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x50
	  lwz       r0, 0x2E8(r3)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x5C

	.loc_0x50:
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0x5C:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801636E0
 * Size:	000034
 */
void SnakeGenBodyOnGroundCallBack::invoke(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x4(r3)
	  lfs       f0, -0x554C(r2)
	  lfs       f1, 0x2C4(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x20
	  lwz       r0, 0x2E8(r3)
	  cmpwi     r0, 0x8
	  bne-      .loc_0x2C

	.loc_0x20:
	  lwz       r0, 0x80(r4)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r4)

	.loc_0x2C:
	  li        r3, 0x1
	  blr
	*/
}
