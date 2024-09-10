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
 * Address:	........
 * Size:	0001C0
 */
SmokeEmitter::SmokeEmitter(int, Texture*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
SmokeEmitter::Smoke::Smoke()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void SmokeEmitter::emit(Vector3f&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00016C
 */
void SmokeEmitter::update(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019BC60
 * Size:	00031C
 */
void SmokeEmitter::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x148(r1)
	  stfd      f31, 0x140(r1)
	  stfd      f30, 0x138(r1)
	  stmw      r25, 0x11C(r1)
	  mr        r28, r3
	  addi      r29, r4, 0
	  lwz       r0, 0x38(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x24C
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  lwz       r4, 0x28(r28)
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  mr        r31, r0
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
	  lwz       r12, 0x3B4(r29)
	  lis       r4, 0x803A
	  mr        r3, r29
	  lwz       r12, 0x70(r12)
	  subi      r4, r4, 0x77C0
	  addi      r5, r1, 0xB8
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r1, 0xB8
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r4, 0x34(r28)
	  lwz       r12, 0x3B4(r29)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  li        r4, 0x1
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1FC
	  lwz       r3, 0x2C(r28)
	  addi      r26, r1, 0x30
	  lfs       f30, -0x4C88(r2)
	  addi      r27, r1, 0x34
	  lwz       r25, 0x10(r3)
	  lfs       f31, -0x4C84(r2)
	  b         .loc_0x1F0

	.loc_0x11C:
	  lwz       r0, 0x28(r28)
	  cmpwi     r0, 0
	  bne-      .loc_0x170
	  lfs       f0, 0x20(r25)
	  li        r0, 0xFF
	  addi      r3, r29, 0
	  fmuls     f0, f30, f0
	  stb       r0, 0x34(r1)
	  mr        r4, r27
	  stb       r0, 0x35(r1)
	  li        r5, 0x1
	  fctiwz    f0, f0
	  stb       r0, 0x36(r1)
	  stfd      f0, 0x110(r1)
	  lwz       r0, 0x114(r1)
	  stb       r0, 0x37(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1C8

	.loc_0x170:
	  lfs       f0, 0x20(r25)
	  addi      r3, r29, 0
	  addi      r4, r26, 0
	  fmuls     f0, f30, f0
	  li        r5, 0x1
	  fctiwz    f0, f0
	  stfd      f0, 0x108(r1)
	  stfd      f0, 0x100(r1)
	  lwz       r0, 0x10C(r1)
	  stfd      f0, 0xF8(r1)
	  lwz       r6, 0x104(r1)
	  stb       r0, 0x30(r1)
	  lwz       r0, 0xFC(r1)
	  stfd      f0, 0x110(r1)
	  stb       r6, 0x31(r1)
	  lwz       r6, 0x114(r1)
	  stb       r0, 0x32(r1)
	  stb       r6, 0x33(r1)
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1C8:
	  mr        r3, r29
	  lfs       f0, 0xC(r25)
	  lwz       r12, 0x3B4(r29)
	  mr        r5, r25
	  fmuls     f1, f31, f0
	  lwz       r4, 0x2E4(r29)
	  lwz       r12, 0x8C(r12)
	  mtlr      r12
	  blrl
	  lwz       r25, 0x10(r25)

	.loc_0x1F0:
	  lwz       r0, 0x2C(r28)
	  cmplw     r25, r0
	  bne+      .loc_0x11C

	.loc_0x1FC:
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
	  b         .loc_0x300

	.loc_0x24C:
	  lwz       r3, 0x2C(r28)
	  addi      r26, r1, 0x18
	  addi      r27, r1, 0x24
	  lwz       r25, 0x10(r3)
	  b         .loc_0x2F4

	.loc_0x260:
	  lfs       f0, 0x1038(r13)
	  mr        r4, r27
	  lfs       f1, 0x103C(r13)
	  mr        r5, r26
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x1040(r13)
	  mr        r6, r25
	  stfs      f1, 0x1C(r1)
	  addi      r3, r1, 0x78
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0xC(r25)
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0xC(r25)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0xC(r25)
	  stfs      f0, 0x2C(r1)
	  bl        -0x15DE0C
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r1, 0x78
	  addi      r5, r1, 0x38
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r1, 0x38
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x38(r28)
	  mr        r4, r29
	  lwz       r5, 0x2E4(r29)
	  li        r6, 0
	  bl        -0x16BAE0
	  lwz       r25, 0x10(r25)

	.loc_0x2F4:
	  lwz       r0, 0x2C(r28)
	  cmplw     r25, r0
	  bne+      .loc_0x260

	.loc_0x300:
	  lmw       r25, 0x11C(r1)
	  lwz       r0, 0x14C(r1)
	  lfd       f31, 0x140(r1)
	  lfd       f30, 0x138(r1)
	  addi      r1, r1, 0x148
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
EffectParticleRegistration::EffectParticleRegistration(char*, char*, char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void EffectShape::initShape(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void EffectShape::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void EffectShape::refresh(Graphics&, Matrix4f&, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void EffShpInst::initEffShpInst()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019BF7C
 * Size:	000134
 */
void EffShpInst::update()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x30(r1)
	  li        r6, 0
	  lbz       r0, 0x42(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x128
	  lwz       r4, 0x38(r3)
	  lwz       r4, 0x14(r4)
	  lwz       r4, 0x18(r4)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x30(r4)
	  cmpwi     r0, 0
	  ble-      .loc_0xD4
	  lwz       r5, 0x2DEC(r13)
	  lis       r4, 0x4330
	  lfs       f1, -0x4C80(r2)
	  lfs       f0, 0x28C(r5)
	  lfs       f2, 0x3C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x3C(r3)
	  lwz       r5, 0x38(r3)
	  lfd       f1, -0x4C78(r2)
	  lwz       r5, 0x14(r5)
	  lfs       f2, 0x3C(r3)
	  lwz       r5, 0x18(r5)
	  lwz       r5, 0x0(r5)
	  lwz       r5, 0x30(r5)
	  subi      r0, r5, 0x1
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x2C(r1)
	  stw       r4, 0x28(r1)
	  lfd       f0, 0x28(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x128
	  xoris     r0, r5, 0x8000
	  stw       r0, 0x2C(r1)
	  stw       r4, 0x28(r1)
	  lfd       f0, 0x28(r1)
	  fsubs     f0, f0, f1
	  fsubs     f0, f2, f0
	  stfs      f0, 0x3C(r3)
	  lbz       r5, 0x41(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x128
	  lbz       r4, 0x40(r3)
	  addi      r4, r4, 0x1
	  rlwinm    r0,r4,0,24,31
	  stb       r4, 0x40(r3)
	  cmplw     r0, r5
	  blt-      .loc_0x128
	  li        r6, 0x1
	  b         .loc_0x128

	.loc_0xD4:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, -0x4C80(r2)
	  lfs       f0, 0x28C(r4)
	  lfs       f2, 0x3C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x3C(r3)
	  lfs       f1, 0x3C(r3)
	  lfs       f0, -0x4C8C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x128
	  lbz       r5, 0x41(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x128
	  lbz       r4, 0x40(r3)
	  addi      r4, r4, 0x1
	  rlwinm    r0,r4,0,24,31
	  stb       r4, 0x40(r3)
	  cmplw     r0, r5
	  blt-      .loc_0x128
	  li        r6, 0x1

	.loc_0x128:
	  mr        r3, r6
	  addi      r1, r1, 0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
void EffShpInst::draw(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
EffectGeometryRegistration::EffectGeometryRegistration(char*, char*, f32, u8)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019C0B0
 * Size:	0000FC
 */
void EffectGeometryRegistration::create(Vector3f&, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  mr        r27, r3
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  lwz       r3, 0x3180(r13)
	  bl        0xB2C
	  mr.       r31, r3
	  beq-      .loc_0xE4
	  li        r5, 0
	  stw       r5, 0x10(r31)
	  addi      r0, r13, 0x1068
	  addi      r4, r31, 0
	  stw       r5, 0xC(r31)
	  stw       r5, 0x8(r31)
	  stw       r0, 0x4(r31)
	  lwz       r0, 0x4(r27)
	  stw       r0, 0x38(r31)
	  lfs       f0, 0x8(r27)
	  stfs      f0, 0x14(r31)
	  lfs       f0, 0x8(r27)
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x8(r27)
	  stfs      f0, 0x1C(r31)
	  lfs       f1, 0x14(r31)
	  lfs       f0, 0x0(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x14(r31)
	  lfs       f1, 0x18(r31)
	  lfs       f0, 0x4(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x18(r31)
	  lfs       f1, 0x1C(r31)
	  lfs       f0, 0x8(r29)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x1C(r31)
	  lwz       r3, 0x0(r30)
	  lwz       r0, 0x4(r30)
	  stw       r3, 0x20(r31)
	  stw       r0, 0x24(r31)
	  lwz       r0, 0x8(r30)
	  stw       r0, 0x28(r31)
	  lwz       r3, 0x0(r28)
	  lwz       r0, 0x4(r28)
	  stw       r3, 0x2C(r31)
	  stw       r0, 0x30(r31)
	  lwz       r0, 0x8(r28)
	  stw       r0, 0x34(r31)
	  stb       r5, 0x40(r31)
	  lbz       r0, 0xC(r27)
	  stb       r0, 0x41(r31)
	  lwz       r3, 0x3180(r13)
	  addi      r3, r3, 0x12C
	  bl        -0x15BBB8

	.loc_0xE4:
	  mr        r3, r31
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
EffectSimpleParticleRegistration::EffectSimpleParticleRegistration(char*, Colour, Colour)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019C1AC
 * Size:	00064C
 */
EffectMgr::EffectMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  lis       r9, 0x802E
	  addi      r5, r5, 0x738C
	  stwu      r1, -0x90(r1)
	  li        r0, 0
	  lis       r8, 0x802D
	  stfd      f31, 0x88(r1)
	  subi      r9, r9, 0x5B00
	  stmw      r17, 0x4C(r1)
	  addi      r31, r8, 0x6CC0
	  lis       r8, 0x802D
	  addi      r10, r31, 0x10
	  addi      r18, r8, 0x68DC
	  stw       r3, 0x8(r1)
	  lis       r3, 0x8022
	  addi      r3, r3, 0x737C
	  lwz       r4, 0x8(r1)
	  stw       r5, 0x0(r4)
	  addi      r6, r4, 0x14
	  addi      r7, r6, 0x34
	  stw       r3, 0x0(r4)
	  addi      r12, r6, 0x14
	  addi      r17, r6, 0x24
	  stw       r0, 0x10(r4)
	  addi      r19, r7, 0x14
	  addi      r8, r6, 0x60
	  stw       r0, 0xC(r4)
	  stw       r0, 0x8(r4)
	  stw       r10, 0x4(r4)
	  addi      r10, r6, 0x4
	  stw       r9, 0x0(r4)
	  addi      r9, r7, 0x4
	  stw       r18, 0x18(r4)
	  stw       r10, 0x20(r4)
	  stw       r10, 0x1C(r4)
	  stw       r10, 0x14(r4)
	  lwz       r11, 0x14(r4)
	  stw       r11, 0x8(r11)
	  lwz       r10, 0x14(r4)
	  stw       r11, 0x4(r10)
	  stw       r18, 0x28(r4)
	  stw       r12, 0x30(r4)
	  stw       r12, 0x2C(r4)
	  stw       r12, 0x24(r4)
	  lwz       r11, 0x24(r4)
	  stw       r11, 0x8(r11)
	  lwz       r10, 0x24(r4)
	  stw       r11, 0x4(r10)
	  stw       r18, 0x38(r4)
	  stw       r17, 0x40(r4)
	  stw       r17, 0x3C(r4)
	  stw       r17, 0x34(r4)
	  lwz       r11, 0x34(r4)
	  stw       r11, 0x8(r11)
	  lwz       r10, 0x34(r4)
	  stw       r11, 0x4(r10)
	  stw       r18, 0x4C(r4)
	  stw       r9, 0x54(r4)
	  stw       r9, 0x50(r4)
	  stw       r9, 0x48(r4)
	  lwz       r10, 0x48(r4)
	  stw       r10, 0x8(r10)
	  lwz       r9, 0x48(r4)
	  stw       r10, 0x4(r9)
	  stw       r18, 0x5C(r4)
	  stw       r19, 0x64(r4)
	  stw       r19, 0x60(r4)
	  stw       r19, 0x58(r4)
	  lwz       r10, 0x58(r4)
	  stw       r10, 0x8(r10)
	  lwz       r9, 0x58(r4)
	  stw       r10, 0x4(r9)
	  stw       r0, 0x68(r4)
	  stw       r0, 0x6C(r4)
	  stw       r18, 0x78(r4)
	  addi      r10, r8, 0x4
	  stw       r10, 0xC(r8)
	  addi      r12, r4, 0xB4
	  addi      r11, r13, 0x1068
	  stw       r10, 0x8(r8)
	  lis       r9, 0x802E
	  lis       r7, 0x802E
	  stw       r10, 0x0(r8)
	  subi      r10, r9, 0x5AA8
	  subi      r9, r7, 0x5B50
	  lwz       r20, 0x0(r8)
	  li        r7, 0x1
	  stw       r20, 0x8(r20)
	  lwz       r17, 0x0(r8)
	  stw       r20, 0x4(r17)
	  stw       r0, 0x10(r8)
	  stw       r0, 0x30(r6)
	  stw       r0, 0x5C(r6)
	  stw       r18, 0xB4(r4)
	  stw       r12, 0xBC(r4)
	  stw       r12, 0xB8(r4)
	  stw       r12, 0xB0(r4)
	  lwz       r8, 0xB0(r4)
	  stw       r8, 0x8(r8)
	  lwz       r6, 0xB0(r4)
	  stw       r8, 0x4(r6)
	  stw       r5, 0xC0(r4)
	  stw       r3, 0xC0(r4)
	  stw       r0, 0xD0(r4)
	  stw       r0, 0xCC(r4)
	  stw       r0, 0xC8(r4)
	  stw       r11, 0xC4(r4)
	  stw       r10, 0xC0(r4)
	  stw       r0, 0xD8(r4)
	  stw       r0, 0xDC(r4)
	  stw       r0, 0xE0(r4)
	  stw       r0, 0xE4(r4)
	  stw       r5, 0xE8(r4)
	  stw       r3, 0xE8(r4)
	  stw       r0, 0xF8(r4)
	  stw       r0, 0xF4(r4)
	  stw       r0, 0xF0(r4)
	  stw       r11, 0xEC(r4)
	  stw       r9, 0xE8(r4)
	  lfs       f2, -0x4C90(r2)
	  stfs      f2, 0x104(r4)
	  fmr       f1, f2
	  fmr       f0, f2
	  stfs      f2, 0x100(r4)
	  stfs      f2, 0xFC(r4)
	  stfs      f2, 0x110(r4)
	  stfs      f2, 0x10C(r4)
	  stfs      f2, 0x108(r4)
	  stfs      f1, 0x11C(r4)
	  stfs      f1, 0x118(r4)
	  stfs      f1, 0x114(r4)
	  stfs      f0, 0x124(r4)
	  stw       r0, 0x120(r4)
	  lfs       f0, 0x1044(r13)
	  stfs      f0, 0xFC(r4)
	  lfs       f0, 0x1048(r13)
	  stfs      f0, 0x100(r4)
	  lfs       f0, 0x104C(r13)
	  stfs      f0, 0x104(r4)
	  lfs       f0, 0x1050(r13)
	  stfs      f0, 0x108(r4)
	  lfs       f0, 0x1054(r13)
	  stfs      f0, 0x10C(r4)
	  lfs       f0, 0x1058(r13)
	  stfs      f0, 0x110(r4)
	  lfs       f0, 0x105C(r13)
	  stfs      f0, 0x114(r4)
	  lfs       f0, 0x1060(r13)
	  stfs      f0, 0x118(r4)
	  lfs       f0, 0x1064(r13)
	  stfs      f0, 0x11C(r4)
	  stb       r0, 0x128(r4)
	  stb       r0, 0x129(r4)
	  stb       r7, 0x12A(r4)
	  stb       r7, 0x12A(r4)
	  stw       r5, 0x12C(r4)
	  stw       r3, 0x12C(r4)
	  stw       r0, 0x13C(r4)
	  stw       r0, 0x138(r4)
	  stw       r0, 0x134(r4)
	  stw       r11, 0x130(r4)
	  stw       r9, 0x12C(r4)
	  stfs      f2, 0x148(r4)
	  stfs      f2, 0x144(r4)
	  stfs      f2, 0x140(r4)
	  stfs      f2, 0x154(r4)
	  stfs      f2, 0x150(r4)
	  stfs      f2, 0x14C(r4)
	  stfs      f2, 0x160(r4)
	  stfs      f2, 0x15C(r4)
	  stfs      f2, 0x158(r4)
	  stfs      f2, 0x168(r4)
	  stw       r0, 0x164(r4)
	  lfs       f0, 0x1044(r13)
	  stfs      f0, 0x140(r4)
	  lfs       f0, 0x1048(r13)
	  stfs      f0, 0x144(r4)
	  lfs       f0, 0x104C(r13)
	  stfs      f0, 0x148(r4)
	  lfs       f0, 0x1050(r13)
	  stfs      f0, 0x14C(r4)
	  lfs       f0, 0x1054(r13)
	  stfs      f0, 0x150(r4)
	  lfs       f0, 0x1058(r13)
	  stfs      f0, 0x154(r4)
	  lfs       f0, 0x105C(r13)
	  stfs      f0, 0x158(r4)
	  lfs       f0, 0x1060(r13)
	  stfs      f0, 0x15C(r4)
	  lfs       f0, 0x1064(r13)
	  stfs      f0, 0x160(r4)
	  stb       r0, 0x16C(r4)
	  stb       r0, 0x16D(r4)
	  stb       r7, 0x16E(r4)
	  stb       r7, 0x16E(r4)
	  lwz       r0, 0x3180(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x324
	  stw       r4, 0x3180(r13)

	.loc_0x324:
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r13, 0x106C
	  bl        -0x115DA0
	  lwz       r17, 0x8(r1)
	  li        r4, 0x200
	  lfs       f1, 0x1110(r13)
	  li        r5, 0x700
	  addi      r3, r17, 0x14
	  li        r6, 0x400
	  bl        0x4C0C
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r13, 0x106C
	  bl        -0x115CB8
	  li        r22, 0
	  stw       r22, 0xD0(r17)
	  addi      r0, r13, 0x1068
	  addi      r4, r31, 0x3790
	  stw       r22, 0xCC(r17)
	  stw       r22, 0xC8(r17)
	  stw       r0, 0xC4(r17)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x115DEC
	  lis       r3, 0x802E
	  addi      r21, r31, 0x2770
	  subi      r17, r3, 0x5A7C
	  li        r23, 0

	.loc_0x38C:
	  li        r3, 0x10
	  bl        -0x155538
	  addi      r20, r3, 0
	  mr.       r0, r20
	  beq-      .loc_0x400
	  lwz       r4, 0x0(r21)
	  li        r5, 0x1
	  lwz       r19, 0x8(r21)
	  lwz       r18, 0x4(r21)
	  stw       r17, 0x0(r20)
	  lwz       r3, 0x3180(r13)
	  addi      r3, r3, 0xB0
	  bl        0x49BC
	  stw       r3, 0x4(r20)
	  addi      r4, r18, 0
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x15D474
	  cmplwi    r19, 0
	  stw       r3, 0x8(r20)
	  beq-      .loc_0x3F8
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r19, 0
	  li        r5, 0x1
	  bl        -0x15D490
	  stw       r3, 0xC(r20)
	  b         .loc_0x400

	.loc_0x3F8:
	  li        r0, 0
	  stw       r0, 0xC(r20)

	.loc_0x400:
	  addi      r23, r23, 0x1
	  lwz       r3, 0x8(r1)
	  addi      r0, r22, 0x170
	  cmpwi     r23, 0x14C
	  stwx      r20, r3, r0
	  addi      r21, r21, 0xC
	  addi      r22, r22, 0x4
	  blt+      .loc_0x38C
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r31, 0x3790
	  bl        -0x115D8C
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r31, 0x379C
	  bl        -0x115EA8
	  li        r18, 0
	  lis       r6, 0x8022
	  lis       r5, 0x8022
	  lis       r4, 0x802E
	  lis       r3, 0x803A
	  lis       r7, 0x802E
	  addi      r19, r18, 0
	  addi      r20, r31, 0x3754
	  addi      r27, r6, 0x738C
	  addi      r28, r5, 0x737C
	  subi      r29, r4, 0x5AA8
	  subi      r30, r3, 0x2848
	  subi      r26, r7, 0x5AD4

	.loc_0x46C:
	  li        r3, 0x10
	  bl        -0x155618
	  mr.       r22, r3
	  beq-      .loc_0x554
	  lbz       r23, 0xC(r20)
	  li        r3, 0x28
	  lfs       f31, 0x8(r20)
	  lwz       r24, 0x4(r20)
	  lwz       r25, 0x0(r20)
	  stw       r26, 0x0(r22)
	  bl        -0x15563C
	  addi      r21, r3, 0
	  mr.       r0, r21
	  beq-      .loc_0x510
	  stw       r27, 0x0(r21)
	  li        r17, 0
	  addi      r3, r21, 0
	  stw       r28, 0x0(r21)
	  addi      r4, r13, 0x1068
	  stw       r17, 0x10(r21)
	  stw       r17, 0xC(r21)
	  stw       r17, 0x8(r21)
	  bl        -0x17779C
	  stw       r29, 0x0(r21)
	  addi      r3, r30, 0
	  addi      r4, r25, 0
	  stw       r17, 0x18(r21)
	  li        r5, 0x1
	  stw       r17, 0x1C(r21)
	  stw       r17, 0x20(r21)
	  stw       r17, 0x24(r21)
	  bl        -0x149984
	  stw       r3, 0x14(r21)
	  addi      r4, r21, 0x18
	  li        r5, 0
	  lwz       r3, 0x14(r21)
	  lwz       r0, 0x14(r3)
	  ori       r0, r0, 0x4
	  stw       r0, 0x14(r3)
	  lwz       r3, 0x14(r21)
	  bl        -0x16CD8C

	.loc_0x510:
	  stw       r21, 0x4(r22)
	  lwz       r0, 0x4(r22)
	  cmplwi    r0, 0
	  beq-      .loc_0x554
	  cmplwi    r24, 0
	  beq-      .loc_0x53C
	  lwz       r3, 0x4(r22)
	  addi      r4, r24, 0
	  li        r5, 0x1
	  lwz       r3, 0x14(r3)
	  bl        -0x1678F0

	.loc_0x53C:
	  lwz       r3, 0x3180(r13)
	  lwz       r4, 0x4(r22)
	  addi      r3, r3, 0xC0
	  bl        -0x15C11C
	  stfs      f31, 0x8(r22)
	  stb       r23, 0xC(r22)

	.loc_0x554:
	  addi      r18, r18, 0x1
	  lwz       r3, 0x8(r1)
	  addi      r0, r19, 0x6A4
	  cmpwi     r18, 0x3
	  stwx      r22, r3, r0
	  addi      r20, r20, 0x10
	  addi      r19, r19, 0x4
	  blt+      .loc_0x46C
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r31, 0x379C
	  bl        -0x115EE0
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r31, 0x37A8
	  bl        -0x115FFC
	  addi      r18, r31, 0x3784
	  li        r3, 0xC
	  bl        -0x15573C
	  addi      r17, r3, 0
	  mr.       r0, r17
	  beq-      .loc_0x608
	  lbz       r0, 0x8(r18)
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  stb       r0, 0x24(r1)
	  lbz       r0, 0x9(r18)
	  stb       r0, 0x25(r1)
	  lbz       r0, 0xA(r18)
	  stb       r0, 0x26(r1)
	  lbz       r0, 0xB(r18)
	  stb       r0, 0x27(r1)
	  lbz       r0, 0x4(r18)
	  stb       r0, 0x2C(r1)
	  lbz       r0, 0x5(r18)
	  stb       r0, 0x2D(r1)
	  lbz       r0, 0x6(r18)
	  stb       r0, 0x2E(r1)
	  lbz       r0, 0x7(r18)
	  stb       r0, 0x2F(r1)
	  lwz       r4, 0x0(r18)
	  bl        -0x15D694
	  stw       r3, 0x0(r17)
	  lwz       r0, 0x2C(r1)
	  stw       r0, 0x4(r17)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x8(r17)

	.loc_0x608:
	  lwz       r18, 0x8(r1)
	  addi      r4, r31, 0x37A8
	  stw       r17, 0x6A0(r18)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x115F7C
	  addi      r3, r18, 0
	  li        r4, 0x10
	  bl        .loc_0x64C
	  li        r0, 0x1
	  stb       r0, 0x6B0(r18)
	  mr        r3, r18
	  lmw       r17, 0x4C(r1)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr

	.loc_0x64C:
	*/
}

/*
 * --INFO--
 * Address:	8019C7F8
 * Size:	000140
 */
void EffectMgr::initEffectGeometry(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r7, 0
	  stw       r0, 0x4(r1)
	  addi      r0, r13, 0x1068
	  lis       r6, 0x8022
	  stwu      r1, -0x30(r1)
	  lis       r5, 0x8022
	  stfd      f31, 0x28(r1)
	  stmw      r26, 0x10(r1)
	  addi      r26, r3, 0
	  addi      r27, r4, 0
	  addi      r29, r6, 0x738C
	  addi      r30, r5, 0x737C
	  li        r28, 0
	  stw       r7, 0x13C(r3)
	  stw       r7, 0x138(r3)
	  lis       r3, 0x802E
	  subi      r31, r3, 0x5B50
	  stw       r7, 0x134(r26)
	  stw       r0, 0x130(r26)
	  lfs       f31, -0x4C90(r2)
	  b         .loc_0x120

	.loc_0x58:
	  li        r3, 0x44
	  bl        -0x155850
	  mr.       r4, r3
	  beq-      .loc_0x114
	  stw       r29, 0x0(r3)
	  li        r6, 0
	  addi      r5, r13, 0x1068
	  stw       r30, 0x0(r3)
	  li        r0, 0x1
	  stw       r6, 0x10(r3)
	  stw       r6, 0xC(r3)
	  stw       r6, 0x8(r3)
	  stw       r5, 0x4(r3)
	  stw       r31, 0x0(r3)
	  stfs      f31, 0x1C(r3)
	  stfs      f31, 0x18(r3)
	  stfs      f31, 0x14(r3)
	  stfs      f31, 0x28(r3)
	  stfs      f31, 0x24(r3)
	  stfs      f31, 0x20(r3)
	  stfs      f31, 0x34(r3)
	  stfs      f31, 0x30(r3)
	  stfs      f31, 0x2C(r3)
	  stfs      f31, 0x3C(r3)
	  stw       r6, 0x38(r3)
	  lfs       f0, 0x1044(r13)
	  stfs      f0, 0x14(r3)
	  lfs       f0, 0x1048(r13)
	  stfs      f0, 0x18(r3)
	  lfs       f0, 0x104C(r13)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, 0x1050(r13)
	  stfs      f0, 0x20(r3)
	  lfs       f0, 0x1054(r13)
	  stfs      f0, 0x24(r3)
	  lfs       f0, 0x1058(r13)
	  stfs      f0, 0x28(r3)
	  lfs       f0, 0x105C(r13)
	  stfs      f0, 0x2C(r3)
	  lfs       f0, 0x1060(r13)
	  stfs      f0, 0x30(r3)
	  lfs       f0, 0x1064(r13)
	  stfs      f0, 0x34(r3)
	  stb       r6, 0x40(r3)
	  stb       r6, 0x41(r3)
	  stb       r0, 0x42(r3)
	  stb       r0, 0x42(r3)

	.loc_0x114:
	  addi      r3, r26, 0xE8
	  bl        -0x15C338
	  addi      r28, r28, 0x1

	.loc_0x120:
	  cmpw      r28, r27
	  blt+      .loc_0x58
	  lmw       r26, 0x10(r1)
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019C938
 * Size:	00007C
 */
void EffectMgr::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  addi      r3, r29, 0x14
	  bl        0x49A4
	  lwz       r30, 0x13C(r29)
	  b         .loc_0x58

	.loc_0x2C:
	  lwz       r31, 0xC(r30)
	  mr        r3, r30
	  bl        -0x9F0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x54
	  mr        r3, r30
	  bl        -0x15C36C
	  addi      r3, r29, 0xE8
	  addi      r4, r30, 0
	  bl        -0x15C3B0

	.loc_0x54:
	  mr        r30, r31

	.loc_0x58:
	  cmplwi    r30, 0
	  bne+      .loc_0x2C
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
 * Address:	8019C9B4
 * Size:	00003C
 */
void EffectMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x6B0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x24
	  addi      r3, r3, 0x14
	  bl        0x4AB0
	  b         .loc_0x2C

	.loc_0x24:
	  addi      r3, r3, 0x14
	  bl        0x4A30

	.loc_0x2C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019C9F0
 * Size:	000118
 */
void EffectMgr::drawshapes(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stmw      r25, 0xBC(r1)
	  addi      r25, r4, 0
	  addi      r29, r1, 0x9C
	  addi      r28, r1, 0xA8
	  subi      r31, r5, 0x77C0
	  lwz       r26, 0x13C(r3)
	  b         .loc_0xFC

	.loc_0x2C:
	  lbz       r0, 0x42(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0xF8
	  addi      r3, r1, 0x90
	  addi      r4, r26, 0x14
	  bl        -0x1298EC
	  addi      r3, r29, 0
	  addi      r4, r26, 0x20
	  bl        -0x1298F8
	  addi      r3, r28, 0
	  addi      r4, r26, 0x2C
	  bl        -0x129904
	  addi      r5, r29, 0
	  addi      r6, r28, 0
	  addi      r3, r1, 0x10
	  addi      r4, r1, 0x90
	  bl        -0x15E968
	  lwz       r3, 0x2E4(r25)
	  addi      r4, r1, 0x10
	  addi      r5, r1, 0x50
	  addi      r3, r3, 0x1E0
	  bl        -0x15E99C
	  lwz       r27, 0x38(r26)
	  addi      r30, r26, 0x3C
	  lwz       r3, 0x14(r27)
	  lwz       r3, 0x18(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x30(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xA8
	  li        r30, 0

	.loc_0xA8:
	  addi      r3, r27, 0x18
	  addi      r4, r30, 0
	  bl        -0x16DA04
	  lwz       r3, 0x14(r27)
	  addi      r4, r25, 0
	  addi      r6, r30, 0
	  addi      r5, r1, 0x50
	  bl        -0x1677A0
	  mr        r3, r25
	  lwz       r12, 0x3B4(r25)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x14(r27)
	  mr        r4, r25
	  lwz       r5, 0x2E4(r25)
	  addi      r6, r27, 0x18
	  bl        -0x16C678

	.loc_0xF8:
	  lwz       r26, 0xC(r26)

	.loc_0xFC:
	  cmplwi    r26, 0
	  bne+      .loc_0x2C
	  lmw       r25, 0xBC(r1)
	  lwz       r0, 0xDC(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019CB08
 * Size:	000030
 */
void EffectMgr::exit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x14
	  stw       r0, 0x4(r1)
	  li        r4, 0x1
	  stwu      r1, -0x8(r1)
	  bl        0x4A0C
	  li        r0, 0
	  stw       r0, 0x3180(r13)
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019CB38
 * Size:	000044
 */
void EffectMgr::create(EffectMgr::effTypeTable, Vector3f&, zen::CallBack1<zen::particleGenerator*>*,
                       zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,2,0,29
	  mr        r4, r5
	  stwu      r1, -0x8(r1)
	  add       r3, r3, r0
	  addi      r5, r6, 0
	  lwz       r3, 0x170(r3)
	  addi      r6, r7, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019CB7C
 * Size:	000040
 */
void EffectParticleRegistration::create(Vector3f&, zen::CallBack1<zen::particleGenerator*>*,
                                        zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r7, r4
	  stw       r0, 0x4(r1)
	  mr        r8, r5
	  mr        r9, r6
	  stwu      r1, -0x8(r1)
	  lwz       r10, 0x3180(r13)
	  lwz       r4, 0x4(r3)
	  lwz       r5, 0x8(r3)
	  lwz       r6, 0xC(r3)
	  addi      r3, r10, 0x14
	  bl        0x46E0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019CBBC
 * Size:	000044
 */
void EffectMgr::create(EffectMgr::modelTypeTable, Vector3f&, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,2,0,29
	  mr        r4, r5
	  stwu      r1, -0x8(r1)
	  add       r3, r3, r0
	  addi      r5, r6, 0
	  lwz       r3, 0x6A4(r3)
	  addi      r6, r7, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void EffectMgr::create(EffectMgr::simpleTypeTable, Vector3f&, s16, Vector3f&, Vector3f&, f32, f32, zen::CallBack1<zen::particleMdl*>*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019CC00
 * Size:	0000A8
 */
void EffectMgr::getShapeInst()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  lwz       r0, 0xF8(r3)
	  cmplwi    r0, 0
	  mr        r31, r0
	  beq-      .loc_0x90
	  mr        r3, r31
	  bl        -0x15C614
	  lfs       f0, -0x4C90(r2)
	  li        r3, 0
	  li        r0, 0x1
	  stfs      f0, 0x3C(r31)
	  stw       r3, 0x38(r31)
	  lfs       f0, 0x1044(r13)
	  stfs      f0, 0x14(r31)
	  lfs       f0, 0x1048(r13)
	  stfs      f0, 0x18(r31)
	  lfs       f0, 0x104C(r13)
	  stfs      f0, 0x1C(r31)
	  lfs       f0, 0x1050(r13)
	  stfs      f0, 0x20(r31)
	  lfs       f0, 0x1054(r13)
	  stfs      f0, 0x24(r31)
	  lfs       f0, 0x1058(r13)
	  stfs      f0, 0x28(r31)
	  lfs       f0, 0x105C(r13)
	  stfs      f0, 0x2C(r31)
	  lfs       f0, 0x1060(r13)
	  stfs      f0, 0x30(r31)
	  lfs       f0, 0x1064(r13)
	  stfs      f0, 0x34(r31)
	  stb       r3, 0x40(r31)
	  stb       r3, 0x41(r31)
	  stb       r0, 0x42(r31)

	.loc_0x90:
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
 * Address:	........
 * Size:	000048
 */
void EffectMgr::putShapeInst(EffShpInst*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8019CCA8
 * Size:	000064
 */
void EffectMgr::killAllShapes()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r30, 0x13C(r3)
	  b         .loc_0x40

	.loc_0x24:
	  lwz       r31, 0xC(r30)
	  mr        r3, r30
	  bl        -0x15C6C4
	  addi      r3, r29, 0xE8
	  addi      r4, r30, 0
	  bl        -0x15C708
	  mr        r30, r31

	.loc_0x40:
	  cmplwi    r30, 0
	  bne+      .loc_0x24
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
