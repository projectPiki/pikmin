#include "Pom.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000098
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
 * Address:	80177DE0
 * Size:	0002B4
 */
PomProp::PomProp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stw       r31, 0xDC(r1)
	  stw       r30, 0xD8(r1)
	  stw       r29, 0xD4(r1)
	  mr        r29, r3
	  stw       r28, 0xD0(r1)
	  bl        -0x2A534
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x1EC(r29)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x1EC(r29)
	  li        r30, 0
	  lis       r3, 0x802D
	  stw       r30, 0x1FC(r29)
	  addi      r6, r3, 0xCE0
	  lis       r4, 0x802D
	  stw       r30, 0x1F8(r29)
	  addi      r3, r4, 0xA78
	  addi      r0, r6, 0xC
	  stw       r30, 0x1F4(r29)
	  addi      r5, r1, 0x68
	  addi      r4, r29, 0x200
	  stw       r3, 0x1F0(r29)
	  addi      r3, r29, 0x204
	  stw       r6, 0x54(r29)
	  stw       r0, 0x1EC(r29)
	  stw       r30, 0x200(r29)
	  lwz       r0, 0x5AC(r13)
	  stw       r0, 0x70(r1)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0x68(r1)
	  bl        -0x1193EC
	  lis       r3, 0x802A
	  addi      r28, r3, 0x6098
	  stw       r28, 0x20C(r29)
	  addi      r5, r1, 0x64
	  addi      r3, r29, 0x214
	  lfs       f0, -0x5250(r2)
	  addi      r4, r29, 0x200
	  stfs      f0, 0x210(r29)
	  lwz       r0, 0x5B0(r13)
	  stw       r0, 0x78(r1)
	  lwz       r0, 0x78(r1)
	  stw       r0, 0x64(r1)
	  bl        -0x119420
	  stw       r28, 0x21C(r29)
	  addi      r5, r1, 0x60
	  addi      r3, r29, 0x224
	  lfs       f0, -0x524C(r2)
	  addi      r4, r29, 0x200
	  stfs      f0, 0x220(r29)
	  lwz       r0, 0x5B4(r13)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0x80(r1)
	  stw       r0, 0x60(r1)
	  bl        -0x11944C
	  stw       r28, 0x22C(r29)
	  addi      r5, r1, 0x5C
	  addi      r3, r29, 0x234
	  lfs       f0, -0x5248(r2)
	  addi      r4, r29, 0x200
	  stfs      f0, 0x230(r29)
	  lwz       r0, 0x5B8(r13)
	  stw       r0, 0x88(r1)
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x5C(r1)
	  bl        -0x119478
	  stw       r28, 0x23C(r29)
	  addi      r5, r1, 0x58
	  addi      r3, r29, 0x244
	  lfs       f0, -0x5244(r2)
	  addi      r4, r29, 0x200
	  stfs      f0, 0x240(r29)
	  lwz       r0, 0x5BC(r13)
	  stw       r0, 0x90(r1)
	  lwz       r0, 0x90(r1)
	  stw       r0, 0x58(r1)
	  bl        -0x1194A4
	  stw       r28, 0x24C(r29)
	  addi      r5, r1, 0x54
	  addi      r3, r29, 0x254
	  lfs       f0, -0x5240(r2)
	  addi      r4, r29, 0x200
	  stfs      f0, 0x250(r29)
	  lwz       r0, 0x5C0(r13)
	  stw       r0, 0x98(r1)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x54(r1)
	  bl        -0x1194D0
	  lis       r3, 0x802A
	  addi      r31, r3, 0x60C4
	  stw       r31, 0x25C(r29)
	  li        r28, 0xA
	  addi      r5, r1, 0x50
	  stw       r28, 0x260(r29)
	  addi      r3, r29, 0x264
	  addi      r4, r29, 0x200
	  lwz       r0, 0x5C4(r13)
	  stw       r0, 0xA0(r1)
	  lwz       r0, 0xA0(r1)
	  stw       r0, 0x50(r1)
	  bl        -0x119504
	  stw       r31, 0x26C(r29)
	  addi      r5, r1, 0x4C
	  addi      r3, r29, 0x274
	  stw       r28, 0x270(r29)
	  addi      r4, r29, 0x200
	  lwz       r0, 0x5C8(r13)
	  stw       r0, 0xA8(r1)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0x4C(r1)
	  bl        -0x11952C
	  stw       r31, 0x27C(r29)
	  addi      r5, r1, 0x48
	  addi      r3, r29, 0x284
	  stw       r28, 0x280(r29)
	  addi      r4, r29, 0x200
	  lwz       r0, 0x5CC(r13)
	  stw       r0, 0xB0(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r0, 0x48(r1)
	  bl        -0x119554
	  stw       r31, 0x28C(r29)
	  addi      r5, r1, 0x44
	  addi      r3, r29, 0x294
	  stw       r30, 0x290(r29)
	  addi      r4, r29, 0x200
	  lwz       r0, 0x5D0(r13)
	  stw       r0, 0xB8(r1)
	  lwz       r0, 0xB8(r1)
	  stw       r0, 0x44(r1)
	  bl        -0x11957C
	  stw       r31, 0x29C(r29)
	  addi      r5, r1, 0x40
	  addi      r3, r29, 0x2A4
	  stw       r30, 0x2A0(r29)
	  addi      r4, r29, 0x200
	  lwz       r0, 0x5D4(r13)
	  stw       r0, 0xC0(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r0, 0x40(r1)
	  bl        -0x1195A4
	  stw       r31, 0x2AC(r29)
	  li        r0, 0x1
	  addi      r5, r1, 0x3C
	  stw       r0, 0x2B0(r29)
	  addi      r3, r29, 0x2B4
	  addi      r4, r29, 0x200
	  lwz       r0, 0x5D8(r13)
	  stw       r0, 0xC8(r1)
	  lwz       r0, 0xC8(r1)
	  stw       r0, 0x3C(r1)
	  bl        -0x1195D0
	  stw       r31, 0x2BC(r29)
	  mr        r3, r29
	  stw       r30, 0x2C0(r29)
	  lfs       f1, -0x523C(r2)
	  stfs      f1, 0x10(r29)
	  lfs       f0, -0x5238(r2)
	  stfs      f0, 0x30(r29)
	  stfs      f1, 0x40(r29)
	  lwz       r0, 0xE4(r1)
	  lwz       r31, 0xDC(r1)
	  lwz       r30, 0xD8(r1)
	  lwz       r29, 0xD4(r1)
	  lwz       r28, 0xD0(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80178094
 * Size:	000098
 */
Pom::Pom(CreatureProp* props)
    : Boss(props)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  bl        -0x2A234
	  lis       r3, 0x802D
	  addi      r0, r3, 0xB00
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  li        r3, 0x14
	  stw       r0, 0x3C4(r30)
	  stw       r0, 0x3C8(r30)
	  stw       r0, 0x3CC(r30)
	  stw       r0, 0x3D0(r30)
	  bl        -0x1310D0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x58
	  li        r4, 0x10
	  bl        -0xEF4B8

	.loc_0x58:
	  stw       r31, 0x220(r30)
	  li        r3, 0x24
	  bl        -0x1310F0
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x78
	  mr        r4, r30
	  bl        0x450

	.loc_0x78:
	  stw       r31, 0x3C0(r30)
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
 * Address:	8017812C
 * Size:	000008
 */
f32 Pom::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x5234(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80178134
 * Size:	000050
 */
void Pom::init(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  addi      r4, r3, 0
	  stwu      r1, -0x8(r1)
	  lfs       f0, -0x5230(r2)
	  stfs      f0, 0x270(r3)
	  stb       r5, 0x2BB(r3)
	  stb       r0, 0x2BC(r3)
	  stb       r0, 0x2BE(r3)
	  lfs       f0, -0x522C(r2)
	  stfs      f0, 0x2E0(r3)
	  stb       r5, 0x3B8(r3)
	  lwz       r3, 0x3C0(r3)
	  bl        0x45C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80178184
 * Size:	00009C
 */
void Pom::setColor(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  stw       r4, 0x3BC(r3)
	  lwz       r0, 0x3BC(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x2C
	  cmpwi     r0, 0x2
	  ble-      .loc_0x74

	.loc_0x2C:
	  bl        0x9FEC0
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5220(r2)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x5228(r2)
	  stw       r0, 0x20(r1)
	  lfs       f1, -0x523C(r2)
	  lfd       f3, 0x20(r1)
	  lfs       f0, -0x5224(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stw       r0, 0x3BC(r31)

	.loc_0x74:
	  lwz       r3, 0x390(r31)
	  addi      r4, r31, 0x3C4
	  li        r5, 0
	  lwz       r3, 0x0(r3)
	  bl        -0x1488DC
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80178220
 * Size:	00004C
 */
void Pom::doKill()
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
	  lwz       r3, 0x3C0(r3)
	  bl        0x714
	  lwz       r3, 0x3168(r13)
	  mr        r4, r31
	  bl        -0x260BC
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017826C
 * Size:	000028
 */
void Pom::exitCourse()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x3C0(r3)
	  bl        0x6DC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80178294
 * Size:	00004C
 */
void Pom::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x104(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x108(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801782E0
 * Size:	0000E0
 */
void Pom::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r4
	  stw       r30, 0x60(r1)
	  mr        r30, r3
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC8
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0x13A230
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x14
	  addi      r3, r3, 0x1E0
	  bl        -0x13A264
	  addi      r3, r30, 0x33C
	  lwz       r12, 0x36C(r30)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x3BC(r30)
	  lis       r0, 0x4330
	  lfd       f1, -0x5220(r2)
	  addi      r3, r30, 0x3C4
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x5C(r1)
	  addi      r4, r1, 0x10
	  stw       r0, 0x58(r1)
	  lfd       f0, 0x58(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x10(r1)
	  bl        -0x1492E0
	  lwz       r3, 0x390(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x14
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0x143080
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0xEE8B8

	.loc_0xC8:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801783C0
 * Size:	000084
 */
void Pom::drawShape(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x6C
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x390(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  addi      r6, r30, 0x3C4
	  lwz       r3, 0x0(r3)
	  bl        -0x147FBC

	.loc_0x6C:
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
 * Address:	80178444
 * Size:	000024
 */
void Pom::doAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x3C0(r3)
	  bl        0x10F8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80178468
 * Size:	000044
 */
void Pom::doAnimation()
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
 * Address:	801784AC
 * Size:	000054
 */
void Pom::collisionCallback(CollEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x0(r4)
	  lwz       r0, 0x6C(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x24
	  cmpwi     r0, 0x36
	  bne-      .loc_0x44

	.loc_0x24:
	  lbz       r0, 0x3B8(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x38
	  li        r0, 0x1
	  stb       r0, 0x3B8(r3)

	.loc_0x38:
	  lwz       r3, 0x3C0(r3)
	  lwz       r4, 0x0(r4)
	  bl        0x4A8

	.loc_0x44:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
