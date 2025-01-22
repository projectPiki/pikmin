#include "zen/DamageEffect.h"

/*
 * --INFO--
 * Address:	801F14F4
 * Size:	00000C
 */
zen::DamageEffect::DamageEffect()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x3DE8(r2)
	  stfs      f0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F1500
 * Size:	0000A8
 */
bool zen::DamageEffect::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x2848
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x338(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0x90
	  lwz       r3, 0x3120(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x40
	  li        r4, 0
	  bl        -0xDA100
	  mr        r5, r3

	.loc_0x40:
	  mr        r3, r5
	  bl        -0xF127C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x68
	  lfs       f1, -0x3DE8(r2)
	  lfs       f0, 0x0(r31)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0x68
	  lfs       f0, -0x3DE4(r2)
	  stfs      f0, 0x0(r31)

	.loc_0x68:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r31)
	  lfs       f1, 0x0(r31)
	  lfs       f0, -0x3DE8(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x90
	  stfs      f0, 0x0(r31)

	.loc_0x90:
	  lwz       r0, 0x24(r1)
	  li        r3, 0
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801F15A8
 * Size:	000430
 */
void zen::DamageEffect::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stw       r31, 0x94(r1)
	  mr        r31, r4
	  stw       r30, 0x90(r1)
	  mr        r30, r3
	  lfs       f0, -0x3DE8(r2)
	  lfs       f1, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x418
	  mr        r3, r31
	  lwz       r4, 0x2F00(r13)
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  lwz       r4, 0x4B8(r4)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0x1
	  li        r6, 0x2
	  li        r7, 0x3
	  bl        0x22048
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x3
	  bl        0x22030
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x3
	  bl        0x22018
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x3
	  bl        0x22000
	  li        r3, 0x4
	  bl        0x2230C
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x22158
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x22144
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x22130
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x4
	  bl        0x2211C
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0x1
	  bl        0x21F40
	  li        r3, 0
	  li        r4, 0xF
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0x8
	  bl        0x21A70
	  li        r3, 0
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x6
	  bl        0x21AD8
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x21B40
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x21BE4
	  li        r3, 0x1
	  li        r4, 0x2
	  li        r5, 0x2
	  bl        0x21EC8
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0x8
	  bl        0x219F8
	  li        r3, 0x1
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x6
	  bl        0x21A60
	  li        r3, 0x1
	  li        r4, 0xE
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x21AC8
	  li        r3, 0x2
	  li        r4, 0x3
	  li        r5, 0x3
	  bl        0x21E6C
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0xF
	  li        r6, 0xF
	  li        r7, 0x8
	  bl        0x2199C
	  li        r3, 0x2
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x6
	  bl        0x21A04
	  li        r3, 0x2
	  li        r4, 0xE
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x21A6C
	  li        r0, 0xEB
	  lfs       f2, -0x3DE0(r2)
	  stb       r0, 0x40(r1)
	  li        r0, 0x7F
	  lfs       f0, -0x3DE8(r2)
	  stb       r0, 0x41(r1)
	  stb       r0, 0x42(r1)
	  lfs       f1, 0x0(r30)
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x270
	  lfs       f0, -0x3DDC(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x278

	.loc_0x270:
	  lfs       f0, -0x3DDC(r2)
	  fsubs     f0, f1, f0

	.loc_0x278:
	  fctiwz    f0, f0
	  li        r3, 0x3
	  li        r4, 0xC
	  stfd      f0, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  stb       r0, 0x43(r1)
	  bl        0x21CE8
	  lwz       r0, 0x40(r1)
	  addi      r4, r1, 0x38
	  li        r3, 0
	  stw       r0, 0x38(r1)
	  bl        0x21C60
	  li        r3, 0x3
	  li        r4, 0xF
	  li        r5, 0
	  li        r6, 0xE
	  li        r7, 0xF
	  bl        0x218DC
	  li        r3, 0x3
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x6
	  bl        0x21944
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x219AC
	  lwz       r0, 0x30C(r31)
	  lis       r9, 0x4330
	  lwz       r3, 0x310(r31)
	  li        r8, 0
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x74(r1)
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x3DD0(r2)
	  addi      r5, r1, 0x18
	  stw       r0, 0x84(r1)
	  lfs       f4, -0x3DDC(r2)
	  addi      r4, r1, 0x28
	  stw       r9, 0x70(r1)
	  mr        r3, r31
	  lfs       f1, -0x3DD8(r2)
	  stw       r9, 0x80(r1)
	  li        r6, 0
	  lfd       f0, 0x70(r1)
	  lfd       f2, 0x80(r1)
	  fsubs     f0, f0, f3
	  stw       r8, 0x18(r1)
	  fsubs     f2, f2, f3
	  stw       r8, 0x1C(r1)
	  fmuls     f0, f4, f0
	  fmuls     f2, f4, f2
	  fctiwz    f0, f0
	  fctiwz    f2, f2
	  stfd      f0, 0x68(r1)
	  stfd      f2, 0x78(r1)
	  lwz       r0, 0x6C(r1)
	  lwz       r7, 0x7C(r1)
	  stw       r0, 0x20(r1)
	  stw       r7, 0x24(r1)
	  lwz       r0, 0x30C(r31)
	  lwz       r7, 0x310(r31)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x54(r1)
	  xoris     r0, r7, 0x8000
	  stw       r0, 0x64(r1)
	  stw       r9, 0x50(r1)
	  stw       r9, 0x60(r1)
	  lfd       f0, 0x50(r1)
	  lfd       f2, 0x60(r1)
	  fsubs     f0, f0, f3
	  stw       r8, 0x28(r1)
	  fsubs     f2, f2, f3
	  stw       r8, 0x2C(r1)
	  fmuls     f0, f0, f1
	  fmuls     f1, f2, f1
	  fctiwz    f0, f0
	  fctiwz    f1, f1
	  stfd      f0, 0x48(r1)
	  stfd      f1, 0x58(r1)
	  lwz       r0, 0x4C(r1)
	  lwz       r7, 0x5C(r1)
	  stw       r0, 0x30(r1)
	  stw       r7, 0x34(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        0x21C5C
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  bl        0x21C4C
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  bl        0x21C3C

	.loc_0x418:
	  lwz       r0, 0x9C(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}
