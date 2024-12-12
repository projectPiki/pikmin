#include "Peve/Condition.h"
#include "nlib/System.h"
#include "system.h"

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
 * Size:	000048
 */
PeveBooleanCondition::PeveBooleanCondition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PeveBooleanCondition::construct(bool)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
PeveDependenceCondition::PeveDependenceCondition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PeveDependenceCondition::construct(PeveCondition*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80125C68
 * Size:	000048
 */
PeveTimeCondition::PeveTimeCondition() { construct(0.0f); }

/*
 * --INFO--
 * Address:	80125CB0
 * Size:	000010
 */
void PeveTimeCondition::construct(f32 limit)
{
	mCurrTime = 0.0f;
	mLimit    = limit;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
PeveDistanceCondition::PeveDistanceCondition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void PeveDistanceCondition::construct(f32, NVector3fIO*, NVector3fIO*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80125CC0
 * Size:	00010C
 */
void PeveDistanceCondition::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  stw       r30, 0x58(r1)
	  stw       r29, 0x54(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x3C
	  bl        -0x8E8C
	  mr        r0, r3
	  lwz       r3, 0xC(r29)
	  mr        r31, r0
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0x30
	  bl        -0x8EB4
	  mr        r0, r3
	  lwz       r3, 0x10(r29)
	  mr        r30, r0
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x5E00(r2)
	  stfs      f0, 0x2C(r1)
	  stfs      f0, 0x28(r1)
	  stfs      f0, 0x24(r1)
	  lfs       f1, 0x0(r30)
	  lfs       f0, 0x0(r31)
	  lfs       f4, 0x8(r30)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r31)
	  lfs       f2, 0x4(r30)
	  lfs       f1, 0x4(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x20(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x20(r1)
	  stfs      f0, 0x24(r1)
	  stfs      f1, 0x28(r1)
	  stfs      f3, 0x2C(r1)
	  lfs       f1, 0x24(r1)
	  lfs       f0, 0x28(r1)
	  lfs       f2, 0x2C(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x118154
	  lfs       f0, 0x8(r29)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xF0
	  li        r0, 0x1
	  stb       r0, 0x4(r29)

	.loc_0xF0:
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  lwz       r29, 0x54(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
PeveComparisonYCondition::PeveComparisonYCondition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void PeveComparisonYCondition::construct(NVector3fIO*, NVector3fIO*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80125DCC
 * Size:	0000A0
 */
void PeveComparisonYCondition::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x18
	  bl        -0x8F98
	  mr        r0, r3
	  lwz       r3, 0x8(r29)
	  mr        r31, r0
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0xC
	  bl        -0x8FC0
	  mr        r0, r3
	  lwz       r3, 0xC(r29)
	  mr        r30, r0
	  lwz       r12, 0x0(r3)
	  mr        r4, r30
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x4(r31)
	  lfs       f0, 0x4(r30)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x84
	  li        r0, 0x1
	  stb       r0, 0x4(r29)

	.loc_0x84:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80125E6C
 * Size:	00000C
 */
void PeveComparisonYCondition::reset() { mValue = false; }

/*
 * --INFO--
 * Address:	80125E78
 * Size:	000008
 */
bool PeveBooleanCondition::isMet() { return mValue; }

/*
 * --INFO--
 * Address:	80125E80
 * Size:	00000C
 */
void PeveDistanceCondition::reset() { mValue = false; }

/*
 * --INFO--
 * Address:	80125E8C
 * Size:	00001C
 */
bool PeveTimeCondition::isMet() { return mCurrTime >= mLimit; }

/*
 * --INFO--
 * Address:	80125EA8
 * Size:	00000C
 */
void PeveTimeCondition::reset() { mCurrTime = 0.0f; }

/*
 * --INFO--
 * Address:	80125EB4
 * Size:	000018
 */
void PeveTimeCondition::update() { mCurrTime += NSystem::system->getFrameTime(); }

/*
 * --INFO--
 * Address:	80125ECC
 * Size:	000030
 */
bool PeveDependenceCondition::isMet()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
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
 * Address:	80125EFC
 * Size:	000004
 */
void PeveDependenceCondition::reset() { }

/*
 * --INFO--
 * Address:	80125F00
 * Size:	000004
 */
void PeveDependenceCondition::update() { }
