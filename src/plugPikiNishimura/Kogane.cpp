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
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80175A30
 * Size:	000330
 */
KoganeProp::KoganeProp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stw       r31, 0x104(r1)
	  stw       r30, 0x100(r1)
	  mr        r30, r3
	  bl        -0x2817C
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x1EC(r30)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x1EC(r30)
	  li        r7, 0
	  lis       r3, 0x802D
	  stw       r7, 0x1FC(r30)
	  addi      r6, r3, 0x964
	  lis       r4, 0x802D
	  stw       r7, 0x1F8(r30)
	  addi      r3, r4, 0x71C
	  addi      r0, r6, 0xC
	  stw       r7, 0x1F4(r30)
	  addi      r5, r1, 0x80
	  addi      r4, r30, 0x200
	  stw       r3, 0x1F0(r30)
	  addi      r3, r30, 0x204
	  stw       r6, 0x54(r30)
	  stw       r0, 0x1EC(r30)
	  stw       r7, 0x200(r30)
	  lwz       r0, 0x450(r13)
	  stw       r0, 0x88(r1)
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x80(r1)
	  bl        -0x117034
	  lis       r3, 0x802A
	  addi      r31, r3, 0x6098
	  stw       r31, 0x20C(r30)
	  addi      r5, r1, 0x7C
	  addi      r3, r30, 0x214
	  lfs       f0, -0x52E0(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x210(r30)
	  lwz       r0, 0x454(r13)
	  stw       r0, 0x90(r1)
	  lwz       r0, 0x90(r1)
	  stw       r0, 0x7C(r1)
	  bl        -0x117068
	  stw       r31, 0x21C(r30)
	  addi      r5, r1, 0x78
	  addi      r3, r30, 0x224
	  lfs       f0, -0x52DC(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x220(r30)
	  lwz       r0, 0x458(r13)
	  stw       r0, 0x98(r1)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x78(r1)
	  bl        -0x117094
	  stw       r31, 0x22C(r30)
	  addi      r5, r1, 0x74
	  addi      r3, r30, 0x234
	  lfs       f0, -0x52DC(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x230(r30)
	  lwz       r0, 0x45C(r13)
	  stw       r0, 0xA0(r1)
	  lwz       r0, 0xA0(r1)
	  stw       r0, 0x74(r1)
	  bl        -0x1170C0
	  stw       r31, 0x23C(r30)
	  addi      r5, r1, 0x70
	  addi      r3, r30, 0x244
	  lfs       f0, -0x52D8(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x240(r30)
	  lwz       r0, 0x460(r13)
	  stw       r0, 0xA8(r1)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0x70(r1)
	  bl        -0x1170EC
	  stw       r31, 0x24C(r30)
	  addi      r5, r1, 0x6C
	  addi      r3, r30, 0x254
	  lfs       f0, -0x52D4(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x250(r30)
	  lwz       r0, 0x464(r13)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x6C(r1)
	  bl        -0x117118
	  stw       r31, 0x25C(r30)
	  addi      r5, r1, 0x68
	  addi      r3, r30, 0x264
	  lfs       f0, -0x52E0(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x260(r30)
	  lwz       r0, 0x468(r13)
	  stw       r0, 0xB8(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r0, 0x68(r1)
	  bl        -0x117144
	  stw       r31, 0x26C(r30)
	  addi      r5, r1, 0x64
	  addi      r3, r30, 0x274
	  lfs       f0, -0x52D0(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x270(r30)
	  lwz       r0, 0x46C(r13)
	  stw       r0, 0xC0(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0x64(r1)
	  bl        -0x117170
	  stw       r31, 0x27C(r30)
	  addi      r5, r1, 0x60
	  addi      r3, r30, 0x284
	  lfs       f0, -0x52CC(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x280(r30)
	  lwz       r0, 0x470(r13)
	  stw       r0, 0xC8(r1)
	  lwz       r0, 0xC8(r1)
	  stw       r0, 0x60(r1)
	  bl        -0x11719C
	  stw       r31, 0x28C(r30)
	  addi      r5, r1, 0x5C
	  addi      r3, r30, 0x294
	  lfs       f0, -0x52C8(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x290(r30)
	  lwz       r0, 0x474(r13)
	  stw       r0, 0xD0(r1)
	  lwz       r0, 0xD0(r1)
	  stw       r0, 0x5C(r1)
	  bl        -0x1171C8
	  stw       r31, 0x29C(r30)
	  addi      r5, r1, 0x58
	  addi      r3, r30, 0x2A4
	  lfs       f0, -0x52C4(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x2A0(r30)
	  lwz       r0, 0x478(r13)
	  stw       r0, 0xD8(r1)
	  lwz       r0, 0xD8(r1)
	  stw       r0, 0x58(r1)
	  bl        -0x1171F4
	  stw       r31, 0x2AC(r30)
	  addi      r5, r1, 0x54
	  addi      r3, r30, 0x2B4
	  lfs       f0, -0x52E0(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x2B0(r30)
	  lwz       r0, 0x47C(r13)
	  stw       r0, 0xE0(r1)
	  lwz       r0, 0xE0(r1)
	  stw       r0, 0x54(r1)
	  bl        -0x117220
	  stw       r31, 0x2BC(r30)
	  addi      r5, r1, 0x50
	  addi      r3, r30, 0x2C4
	  lfs       f0, -0x52C0(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x2C0(r30)
	  lwz       r0, 0x480(r13)
	  stw       r0, 0xE8(r1)
	  lwz       r0, 0xE8(r1)
	  stw       r0, 0x50(r1)
	  bl        -0x11724C
	  stw       r31, 0x2CC(r30)
	  addi      r5, r1, 0x4C
	  addi      r3, r30, 0x2D4
	  lfs       f0, -0x52BC(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x2D0(r30)
	  lwz       r0, 0x484(r13)
	  stw       r0, 0xF0(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r0, 0x4C(r1)
	  bl        -0x117278
	  stw       r31, 0x2DC(r30)
	  addi      r5, r1, 0x48
	  addi      r3, r30, 0x2E4
	  lfs       f0, -0x52B8(r2)
	  addi      r4, r30, 0x200
	  stfs      f0, 0x2E0(r30)
	  lwz       r0, 0x488(r13)
	  stw       r0, 0xF8(r1)
	  lwz       r0, 0xF8(r1)
	  stw       r0, 0x48(r1)
	  bl        -0x1172A4
	  stw       r31, 0x2EC(r30)
	  mr        r3, r30
	  lfs       f1, -0x52B4(r2)
	  stfs      f1, 0x2F0(r30)
	  stfs      f1, 0x10(r30)
	  lfs       f0, -0x52B0(r2)
	  stfs      f0, 0x30(r30)
	  stfs      f1, 0x40(r30)
	  lwz       r0, 0x10C(r1)
	  lwz       r31, 0x104(r1)
	  lwz       r30, 0x100(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80175D60
 * Size:	000084
 */
Kogane::Kogane(CreatureProp*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  bl        -0x27F00
	  lis       r3, 0x802D
	  addi      r0, r3, 0x7A4
	  stw       r0, 0x0(r30)
	  li        r3, 0x14
	  bl        -0x12ED88
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x44
	  li        r4, 0x3
	  bl        -0xED170

	.loc_0x44:
	  stw       r31, 0x220(r30)
	  li        r3, 0x20
	  bl        -0x12EDA8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x64
	  mr        r4, r30
	  bl        0x528

	.loc_0x64:
	  stw       r31, 0x3BC(r30)
	  mr        r3, r30
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
 * Address:	80175DE4
 * Size:	000008
 */
void Kogane::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x52AC(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80175DEC
 * Size:	000054
 */
void Kogane::init(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  addi      r4, r3, 0
	  stwu      r1, -0x8(r1)
	  lfs       f0, -0x52A8(r2)
	  stfs      f0, 0x270(r3)
	  stb       r5, 0x2BB(r3)
	  stb       r0, 0x2BC(r3)
	  stb       r5, 0x2BE(r3)
	  lfs       f0, -0x52C4(r2)
	  stfs      f0, 0x2E0(r3)
	  stb       r5, 0x3B9(r3)
	  stb       r5, 0x3B8(r3)
	  lwz       r3, 0x3BC(r3)
	  bl        0x530
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80175E40
 * Size:	00004C
 */
void Kogane::doKill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stb       r0, 0x2B8(r3)
	  stb       r0, 0x2B9(r3)
	  lwz       r3, 0x3BC(r3)
	  bl        0x448
	  lwz       r3, 0x3168(r13)
	  mr        r4, r31
	  bl        -0x23CDC
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80175E8C
 * Size:	000028
 */
void Kogane::exitCourse()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x3BC(r3)
	  bl        0x410
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80175EB4
 * Size:	000020
 */
void Kogane::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0xEACB8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80175ED4
 * Size:	000098
 */
void Kogane::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0x137E0C
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x10
	  addi      r3, r3, 0x1E0
	  bl        -0x137E40
	  addi      r3, r30, 0x33C
	  lwz       r12, 0x36C(r30)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x390(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x10
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0x140C2C
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0xEC464
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80175F6C
 * Size:	00006C
 */
void Kogane::drawShape(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  lis       r4, 0x803A
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x3B4(r31)
	  subi      r4, r4, 0x77C0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x390(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  lwz       r3, 0x0(r3)
	  bl        -0x145B50
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
 * Address:	80175FD8
 * Size:	000038
 */
void Kogane::doAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x3BC(r3)
	  bl        0x1524
	  li        r0, 0
	  stb       r0, 0x2BF(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80176010
 * Size:	000044
 */
void Kogane::doAnimation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x390(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x34
	  lwz       r12, 0x36C(r4)
	  addi      r3, r4, 0x33C
	  lfs       f1, 0x2D8(r4)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80176054
 * Size:	000058
 */
void Kogane::collisionCallback(CollEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lbz       r0, 0x3B9(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x44
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x44
	  bl        -0xADB30
	  cmpwi     r3, 0xE
	  bne-      .loc_0x44
	  li        r0, 0x1
	  stb       r0, 0x3B9(r31)

	.loc_0x44:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801760AC
 * Size:	000050
 */
void KoganeProp::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        -0x117530
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0x11753C
	  addi      r3, r30, 0x200
	  addi      r4, r31, 0
	  bl        -0x117548
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
 * Address:	801760FC
 * Size:	000008
 */
void KoganeProp::@492 @read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x1EC
	  b         -0x54
	*/
}
