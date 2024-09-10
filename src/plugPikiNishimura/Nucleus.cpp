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
 * Address:	8017A1AC
 * Size:	000090
 */
NucleusProp::NucleusProp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x2C8F4
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
	  addi      r4, r3, 0x129C
	  stw       r6, 0x1F8(r31)
	  addi      r5, r5, 0x108C
	  addi      r0, r4, 0xC
	  stw       r6, 0x1F4(r31)
	  mr        r3, r31
	  stw       r5, 0x1F0(r31)
	  stw       r4, 0x54(r31)
	  stw       r0, 0x1EC(r31)
	  stw       r6, 0x200(r31)
	  lfs       f1, -0x51B8(r2)
	  stfs      f1, 0x10(r31)
	  lfs       f0, -0x51B4(r2)
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
 * Address:	8017A23C
 * Size:	000084
 */
Nucleus::Nucleus(CreatureProp*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  bl        -0x2C3DC
	  lis       r3, 0x802D
	  addi      r0, r3, 0x1114
	  stw       r0, 0x0(r30)
	  li        r3, 0x14
	  bl        -0x133264
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x44
	  li        r4, 0x3
	  bl        -0xF164C

	.loc_0x44:
	  stw       r31, 0x220(r30)
	  li        r3, 0xC
	  bl        -0x133284
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x64
	  mr        r4, r30
	  bl        0x2A8

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
 * Address:	8017A2C0
 * Size:	000008
 */
void Nucleus::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x51B0(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017A2C8
 * Size:	000060
 */
void Nucleus::init(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  addi      r4, r3, 0
	  stwu      r1, -0x8(r1)
	  lfs       f0, -0x51AC(r2)
	  stfs      f0, 0x270(r3)
	  lfs       f0, 0x6E8(r13)
	  stfs      f0, 0x7C(r3)
	  lfs       f0, 0x6EC(r13)
	  stfs      f0, 0x80(r3)
	  lfs       f0, 0x6F0(r13)
	  stfs      f0, 0x84(r3)
	  stb       r5, 0x2B8(r3)
	  stb       r0, 0x2BE(r3)
	  lfs       f0, -0x51A8(r2)
	  stfs      f0, 0x2E0(r3)
	  lwz       r3, 0x3BC(r3)
	  bl        0x250
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017A328
 * Size:	000034
 */
void Nucleus::doKill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stb       r0, 0x2B8(r3)
	  stb       r0, 0x2B9(r3)
	  lwz       r3, 0x3168(r13)
	  bl        -0x281B0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017A35C
 * Size:	000004
 */
void Nucleus::exitCourse() { }

/*
 * --INFO--
 * Address:	8017A360
 * Size:	000020
 */
void Nucleus::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0xEF164
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017A380
 * Size:	000098
 */
void Nucleus::refresh(Graphics&)
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
	  bl        -0x13C2B8
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x10
	  addi      r3, r3, 0x1E0
	  bl        -0x13C2EC
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
	  bl        -0x1450D8
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0xF0910
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
 * Address:	8017A418
 * Size:	00006C
 */
void Nucleus::drawShape(Graphics&)
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
	  bl        -0x149FFC
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
 * Address:	8017A484
 * Size:	000024
 */
void Nucleus::doAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x3BC(r3)
	  bl        0x1F0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017A4A8
 * Size:	000044
 */
void Nucleus::doAnimation()
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
 * Address:	8017A4EC
 * Size:	000050
 */
void NucleusProp::read(RandomAccessStream&)
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
	  bl        -0x11B970
	  addi      r3, r30, 0x58
	  addi      r4, r31, 0
	  bl        -0x11B97C
	  addi      r3, r30, 0x200
	  addi      r4, r31, 0
	  bl        -0x11B988
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
 * Address:	8017A53C
 * Size:	000008
 */
void NucleusProp::@492 @read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  subi      r3, r3, 0x1EC
	  b         -0x54
	*/
}
