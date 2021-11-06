#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017B3D4
 * Size:	000090
 */
MizuProp::MizuProp()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        -0x2DB1C
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
  addi      r4, r3, 0x1814
  stw       r6, 0x1F8(r31)
  addi      r5, r5, 0x1604
  addi      r0, r4, 0xC
  stw       r6, 0x1F4(r31)
  mr        r3, r31
  stw       r5, 0x1F0(r31)
  stw       r4, 0x54(r31)
  stw       r0, 0x1EC(r31)
  stw       r6, 0x200(r31)
  lfs       f1, -0x5178(r2)
  stfs      f1, 0x10(r31)
  lfs       f0, -0x5174(r2)
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
 * Address:	8017B464
 * Size:	000084
 */
Mizu::Mizu(CreatureProp *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  bl        -0x2D604
  lis       r3, 0x802D
  addi      r0, r3, 0x168C
  stw       r0, 0x0(r30)
  li        r3, 0x14
  bl        -0x13448C
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x44
  li        r4, 0x3
  bl        -0xF2874

.loc_0x44:
  stw       r31, 0x220(r30)
  li        r3, 0x14
  bl        -0x1344AC
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x64
  mr        r4, r30
  bl        0x394

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
 * Address:	8017B4E8
 * Size:	00005C
 */
void Mizu::attackDefaultPortion()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x33
  stw       r0, 0x4(r1)
  li        r6, 0
  li        r7, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  addi      r5, r31, 0x94
  lwz       r3, 0x3180(r13)
  bl        0x21628
  lwz       r3, 0x3180(r13)
  addi      r5, r31, 0x94
  li        r4, 0x32
  li        r6, 0
  li        r7, 0
  bl        0x21610
  lwz       r0, 0x1C(r1)
  li        r3, 0x1
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017B544
 * Size:	000008
 */
void Mizu::getiMass()
{
/*
.loc_0x0:
  lfs       f1, -0x5170(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	8017B54C
 * Size:	000040
 */
void Mizu::initMizu(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  mr        r4, r3
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x8(r1)
  lfs       f0, -0x516C(r2)
  stfs      f0, 0x270(r3)
  stb       r0, 0x2BE(r3)
  lfs       f0, -0x5168(r2)
  stfs      f0, 0x2E0(r3)
  lwz       r3, 0x3BC(r3)
  bl        0x360
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017B58C
 * Size:	000040
 */
void Mizu::initGeyzer(Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  mr        r4, r3
  stw       r0, 0x4(r1)
  li        r0, 0x1
  stwu      r1, -0x8(r1)
  lfs       f0, -0x516C(r2)
  stfs      f0, 0x270(r3)
  stb       r0, 0x2BE(r3)
  lfs       f0, -0x5168(r2)
  stfs      f0, 0x2E0(r3)
  lwz       r3, 0x3BC(r3)
  bl        0x3D8
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017B5CC
 * Size:	00004C
 */
void Mizu::doKill()
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
  bl        0x458
  lwz       r3, 0x3168(r13)
  mr        r4, r31
  bl        -0x29468
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017B618
 * Size:	000028
 */
void Mizu::exitCourse()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x3BC(r3)
  bl        0x420
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017B640
 * Size:	00004C
 */
void Mizu::update()
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
 * Address:	8017B68C
 * Size:	000098
 */
void Mizu::refresh(Graphics &)
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
  bl        -0x13D5C4
  lwz       r3, 0x2E4(r31)
  addi      r4, r30, 0x228
  addi      r5, r1, 0x10
  addi      r3, r3, 0x1E0
  bl        -0x13D5F8
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
  bl        -0x1463E4
  lwz       r3, 0x220(r30)
  addi      r4, r31, 0
  li        r5, 0
  bl        -0xF1C1C
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
 * Address:	8017B724
 * Size:	00006C
 */
void Mizu::drawShape(Graphics &)
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
  bl        -0x14B308
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
 * Address:	8017B790
 * Size:	000024
 */
void Mizu::doAI()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x3BC(r3)
  bl        0x720
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8017B7B4
 * Size:	000044
 */
void Mizu::doAnimation()
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
 * Address:	8017B7F8
 * Size:	000008
 */
void Mizu::isVisible()
{
/*
.loc_0x0:
  lbz       r3, 0x3B9(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8017B800
 * Size:	000050
 */
void MizuProp::read(RandomAccessStream &)
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
  bl        -0x11CC84
  addi      r3, r30, 0x58
  addi      r4, r31, 0
  bl        -0x11CC90
  addi      r3, r30, 0x200
  addi      r4, r31, 0
  bl        -0x11CC9C
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
 * Address:	8017B850
 * Size:	000008
 */
void MizuProp::@492@read(RandomAccessStream &)
{
/*
.loc_0x0:
  subi      r3, r3, 0x1EC
  b         -0x54
*/
}
