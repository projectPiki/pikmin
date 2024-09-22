#include "TAI/EffectActions.h"

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
 * Address:	8012E5A8
 * Size:	000038
 */
void TaiEffectAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r6, r3
	  stw       r0, 0x4(r1)
	  addi      r5, r4, 0x94
	  li        r7, 0
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x8(r6)
	  li        r6, 0
	  lwz       r3, 0x3180(r13)
	  bl        0x6E56C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E5E0
 * Size:	00002C
 */
void TaiStartGenParticleGeneratorAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mr        r0, r4
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x8(r3)
	  mr        r3, r0
	  bl        0x1B400
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E60C
 * Size:	00002C
 */
void TaiStopGenParticleGeneratorAction::start(Teki&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mr        r0, r4
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x8(r3)
	  mr        r3, r0
	  bl        0x1B3F8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E638
 * Size:	00008C
 */
TaiJointEffectAction::TaiJointEffectAction(f32 p1, int p2, int p3, int p4, int p5, int p6)
    : TAIAeffCloudOfDust(p1, p2, p3, p4, p5, p6)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r10, r6, 0
	  stw       r0, 0x4(r1)
	  lis       r9, 0x802C
	  addi      r0, r9, 0x6620
	  stwu      r1, -0x38(r1)
	  addi      r9, r5, 0
	  li        r5, 0x1
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  li        r6, -0x1
	  stw       r0, 0x4(r3)
	  li        r0, -0x1
	  lis       r3, 0x802E
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x4BA8
	  mr        r3, r31
	  stw       r0, 0x4(r31)
	  stw       r7, 0x8(r1)
	  stw       r8, 0xC(r1)
	  addi      r8, r4, 0
	  li        r4, -0x1
	  lwz       r7, 0x22F0(r13)
	  bl        0xA77BC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x7EEC
	  stw       r0, 0x4(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  stb       r0, 0x20(r31)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8012E6C4
 * Size:	000004
 */
void TaiJointEffectAction::setType(Vector3f&, int, int) { }
