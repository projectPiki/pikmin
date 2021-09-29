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
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8016B278
 * Size:	000078
 */
void SlimeCreature::SlimeCreature(CreatureProp *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        -0xE03B4
  lis       r3, 0x802D
  subi      r0, r3, 0x6C
  stw       r0, 0x0(r31)
  lis       r3, 0x8009
  subi      r4, r3, 0x5808
  lfs       f0, -0x5408(r2)
  addi      r3, r31, 0x2C8
  li        r5, 0
  stfs      f0, 0x2C4(r31)
  li        r6, 0xC
  li        r7, 0x3
  stfs      f0, 0x2C0(r31)
  stfs      f0, 0x2BC(r31)
  bl        0xA97AC
  addi      r3, r31, 0x1B8
  addi      r4, r31, 0x2C8
  li        r5, 0x3
  bl        -0x87654
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
 * Address:	8016B2F0
 * Size:	000080
 */
void SlimeCreature::init(Vector3f &, Slime *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  stw       r5, 0x2B8(r3)
  lfs       f0, -0x5404(r2)
  stfs      f0, 0x270(r31)
  lwz       r5, 0x0(r4)
  lwz       r0, 0x4(r4)
  stw       r5, 0x94(r31)
  stw       r0, 0x98(r31)
  lwz       r0, 0x8(r4)
  stw       r0, 0x9C(r31)
  lwz       r5, 0x0(r4)
  lwz       r0, 0x4(r4)
  stw       r5, 0x2BC(r31)
  stw       r0, 0x2C0(r31)
  lwz       r0, 0x8(r4)
  stw       r0, 0x2C4(r31)
  bl        -0xE08BC
  lwz       r0, 0xC8(r31)
  ori       r0, r0, 0x40
  stw       r0, 0xC8(r31)
  lwz       r0, 0xC8(r31)
  rlwinm    r0,r0,0,31,29
  stw       r0, 0xC8(r31)
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B370
 * Size:	000008
 */
void SlimeCreature::getSize()
{
/*
.loc_0x0:
  lfs       f1, -0x5404(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B378
 * Size:	000008
 */
void SlimeCreature::getiMass()
{
/*
.loc_0x0:
  lfs       f1, -0x5400(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B380
 * Size:	00001C
 */
void SlimeCreature::getCentre()
{
/*
.loc_0x0:
  lfs       f0, 0x94(r4)
  stfs      f0, 0x0(r3)
  lfs       f0, 0x98(r4)
  stfs      f0, 0x4(r3)
  lfs       f0, 0x9C(r4)
  stfs      f0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B39C
 * Size:	000024
 */
void SlimeCreature::doKill()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0xE06CC
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B3C0
 * Size:	000030
 */
void SlimeCreature::isAlive()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x2B8(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x88(r12)
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
 * Address:	8016B3F0
 * Size:	000030
 */
void SlimeCreature::isAtari()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x2B8(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x84(r12)
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
 * Address:	8016B420
 * Size:	000020
 */
void SlimeCreature::ignoreAtari(Creature *)
{
/*
.loc_0x0:
  lwz       r4, 0x6C(r4)
  lwz       r0, 0x6C(r3)
  cmpw      r4, r0
  bne-      .loc_0x18
  li        r3, 0x1
  blr       

.loc_0x18:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B440
 * Size:	000004
 */
void SlimeCreature::doAI()
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B444
 * Size:	000004
 */
void SlimeCreature::doAnimation()
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B448
 * Size:	00004C
 */
void SlimeCreature::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lfs       f0, -0x53FC(r2)
  lfs       f1, 0x98(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x98(r31)
  bl        -0xDE470
  lwz       r4, 0x2DEC(r13)
  mr        r3, r31
  lfs       f1, 0x28C(r4)
  bl        -0xDCEA0
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B494
 * Size:	000004
 */
void SlimeCreature::refresh(Graphics &)
{
	return;
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B498
 * Size:	000004
 */
void SlimeCreature::setCentre(Vector3f &)
{
	return;
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	8016B49C
 * Size:	000008
 */
BOOL SlimeCreature::isFixed()
{
	return TRUE;
/*
.loc_0x0:
  li        r3, 0x1
  blr
*/
}