#include "King.h"

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
 * Address:	80179E08
 * Size:	000090
 */
KingBackProp::KingBackProp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x2C550
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x1EC(r31)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x1EC(r31)
	  li        r6, 0
	  lis       r5, 0x802D
	  stw       r6, 0x1FC(r31)
	  lis       r3, 0x802D
	  addi      r4, r3, 0x1048
	  stw       r6, 0x1F8(r31)
	  addi      r5, r5, 0xE34
	  addi      r0, r4, 0xC
	  stw       r6, 0x1F4(r31)
	  mr        r3, r31
	  stw       r5, 0x1F0(r31)
	  stw       r4, 0x54(r31)
	  stw       r0, 0x1EC(r31)
	  stw       r6, 0x200(r31)
	  lfs       f1, -0x51C8(r2)
	  stfs      f1, 0x10(r31)
	  lfs       f0, -0x51C4(r2)
	  stfs      f0, 0x30(r31)
	  stfs      f1, 0x40(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80179E98
 * Size:	00006C
 */
KingBack::KingBack(CreatureProp* props)
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
	  bl        -0x2C038
	  lis       r3, 0x802D
	  addi      r0, r3, 0xEBC
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  li        r3, 0x14
	  stw       r0, 0x3FC(r30)
	  bl        -0x132EC8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x4C
	  li        r4, 0x4
	  bl        -0xF12B0

	.loc_0x4C:
	  stw       r31, 0x220(r30)
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
 * Address:	80179F04
 * Size:	000008
 */
f32 KingBack::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x51C0(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80179F0C
 * Size:	00004C
 */
void KingBack::init(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r4, r3, 0
	  stw       r0, 0x4(r1)
	  li        r3, 0
	  li        r0, 0x1
	  stwu      r1, -0x8(r1)
	  lfs       f0, -0x51BC(r2)
	  stfs      f0, 0x270(r4)
	  stb       r3, 0x2BB(r4)
	  addi      r3, r4, 0x3B8
	  stb       r0, 0x2BC(r4)
	  lwz       r6, 0x390(r4)
	  lwz       r5, 0x2F00(r13)
	  lwz       r6, 0x0(r6)
	  bl        -0xEBE84
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80179F58
 * Size:	00003C
 */
void KingBack::doKill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x3B8
	  bl        -0xEBE10
	  lwz       r3, 0x3168(r13)
	  mr        r4, r31
	  bl        -0x27DE4
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80179F94
 * Size:	000004
 */
void KingBack::exitCourse() { }

/*
 * --INFO--
 * Address:	80179F98
 * Size:	00004C
 */
void KingBack::update()
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
 * Address:	80179FE4
 * Size:	0000A4
 */
void KingBack::refresh(Graphics&)
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
	  bl        -0x13BF1C
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x10
	  addi      r3, r3, 0x1E0
	  bl        -0x13BF50
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
	  bl        -0x144D3C
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0xF0574
	  addi      r3, r30, 0x3B8
	  addi      r4, r31, 0
	  bl        -0xEBEA4
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
 * Address:	8017A088
 * Size:	00006C
 */
void KingBack::drawShape(Graphics&)
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
	  bl        -0x149C6C
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
 * Address:	8017A0F4
 * Size:	00001C
 */
void KingBack::doAI()
{
	/*
	.loc_0x0:
	  lfs       f0, 0x300(r3)
	  stfs      f0, 0x94(r3)
	  lfs       f0, 0x304(r3)
	  stfs      f0, 0x98(r3)
	  lfs       f0, 0x308(r3)
	  stfs      f0, 0x9C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017A110
 * Size:	000044
 */
void KingBack::doAnimation()
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
 * Address:	8017A154
 * Size:	000050
 */
void KingBackProp::read(RandomAccessStream&)
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
	  bl        -0x11B5D8
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0x11B5E4
	  addi      r3, r30, 0x200
	  addi      r4, r31, 0
	  bl        -0x11B5F0
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
