#include "TekiConditions.h"
#include "teki.h"
#include "Piki.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("tekiconditions")

/*
 * --INFO--
 * Address:	80149BC0
 * Size:	000054
 */
bool TekiPikiStateCondition::satisfy(Creature* target)
{
	u32 badCompiler;
	if (target->mObjType != OBJTYPE_Piki) {
		return false;
	}

	Piki* piki = static_cast<Piki*>(target);
	return piki->getState() == mPikiStateID;
}

/*
 * --INFO--
 * Address:	80149C14
 * Size:	00002C
 */
bool TekiStateCondition::satisfy(Creature* target)
{
	if (target->mObjType != OBJTYPE_Teki) {
		return false;
	}

	return static_cast<Teki*>(target)->mStateID == mStateID;
}

/*
 * --INFO--
 * Address:	80149C40
 * Size:	00002C
 */
bool TekiTypeCondition::satisfy(Creature* target)
{
	if (target->mObjType != OBJTYPE_Teki) {
		return false;
	}

	return static_cast<Teki*>(target)->mTekiType == mTekiType;
}

/*
 * --INFO--
 * Address:	80149C6C
 * Size:	000030
 */
bool TekiFreeCondition::satisfy(Creature* target)
{
	return target->isFree();
}

/*
 * --INFO--
 * Address:	80149C9C
 * Size:	000014
 */
bool TekiNaviCondition::satisfy(Creature* target)
{
	return target->mObjType == OBJTYPE_Navi;
}

/*
 * --INFO--
 * Address:	80149CB0
 * Size:	000020
 */
bool TekiNaviPikiCondition::satisfy(Creature* target)
{
	return target->mObjType == OBJTYPE_Navi || target->mObjType == OBJTYPE_Piki;
}

/*
 * --INFO--
 * Address:	80149CD0
 * Size:	000024
 */
bool TekiPelletCondition::satisfy(Creature* target)
{
	return BTeki::isPellet(target->mObjType);
}

/*
 * --INFO--
 * Address:	80149CF4
 * Size:	0000A8
 */
bool TekiPositionDistanceCondition::satisfy(Creature* target)
{
	return mPosition.distance(target->getPosition()) <= mDistance;
}

/*
 * --INFO--
 * Address:	80149D9C
 * Size:	000070
 */
bool TekiPositionCircleDistanceCondition::satisfy(Creature* target)
{
	return BTeki::calcCircleDistanceStatic(mPosition, mRadius, target->getPosition(), target->getSize()) <= 0.0f;
}

/*
 * --INFO--
 * Address:	80149E0C
 * Size:	000070
 */
bool TekiPositionSphereDistanceCondition::satisfy(Creature* target)
{
	return BTeki::calcSphereDistanceStatic(mPosition, mRadius, target->getPosition(), target->getSize()) <= 0.0f;
}

/*
 * --INFO--
 * Address:	80149E7C
 * Size:	000014
 */
bool TekiStickingCondition::satisfy(Creature* target)
{
	return target->getStickObject() != nullptr;
}

/*
 * --INFO--
 * Address:	80149E90
 * Size:	0000A8
 */
bool TekiRecognitionCondition::satisfy(Creature* target)
{
	return target->isVisible() && target->isAlive() && !target->isBuried();
}

/*
 * --INFO--
 * Address:	80149F38
 * Size:	000014
 */
bool TekiCreaturePointerCondition::satisfy(Creature* target)
{
	return mCreature == target;
}

/*
 * --INFO--
 * Address:	80149F4C
 * Size:	0000E4
 */
bool TekiDistanceCondition::satisfy(Creature* target)
{
	if (mTeki->cullableCenter(*target, mDistance)) {
		return false;
	}

	return mTeki->calcSphereDistance(*target) <= mDistance;
}

/*
 * --INFO--
 * Address:	8014A030
 * Size:	000070
 */
bool TekiSphereDistanceCondition::satisfy(Creature* target)
{
	u32 badCompiler;
	if (mTeki->cullableSphere(*target, mDistance)) {
		return false;
	}

	return sphereDist(mTeki, target) <= mDistance;
}

/*
 * --INFO--
 * Address:	8014A0A0
 * Size:	000018
 */
bool TekiStickerCondition::satisfy(Creature* target)
{
	return target->getStickObject() == mStickTarget;
}

/*
 * --INFO--
 * Address:	8014A0B8
 * Size:	000144
 */
bool TekiLowerRangeCondition::satisfy(Creature* target)
{
	f32 lowerRange = mTeki->getLowerRange();
	if (mTeki->cullableCenter(*target, lowerRange)) {
		return false;
	}

	return mTeki->calcSphereDistance(*target) <= lowerRange;
}

/*
 * --INFO--
 * Address:	8014A1FC
 * Size:	000024
 */
bool TekiAttackableCondition::satisfy(Creature* target)
{
	return mTeki->attackableCreature(*target);
}

/*
 * --INFO--
 * Address:	8014A220
 * Size:	000024
 */
bool TekiVisibleCondition::satisfy(Creature* target)
{
	return mTeki->visibleCreature(*target);
}

/*
 * --INFO--
 * Address:	8014A244
 * Size:	00003C
 */
bool TekiVisibleHeightCondition::satisfy(Creature* target)
{
	f32 visHeight = mTeki->getParameterF(TPF_VisibleHeight);
	if (target->getPosition().y > mTeki->getPosition().y + visHeight) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	8014A280
 * Size:	0000BC
 */
bool TekiLowerCondition::satisfy(Creature* target)
{
	TekiAndCondition& rangeAndNoStickCond
	    = TekiAndCondition(&TekiLowerRangeCondition(mTeki), &TekiNotCondition(&TekiStickerCondition(mTeki)));
	return rangeAndNoStickCond.satisfy(target);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r10, r5, 0xF68
	  lis       r5, 0x802C
	  stwu      r1, -0x80(r1)
	  addi      r9, r5, 0x6964
	  lis       r6, 0x802D
	  lwz       r11, 0x4(r3)
	  lis       r5, 0x802C
	  addi      r0, r5, 0x6890
	  stw       r10, 0x5C(r1)
	  lis       r7, 0x802D
	  subi      r6, r6, 0x2A4C
	  stw       r10, 0x64(r1)
	  addi      r8, r1, 0x5C
	  lis       r5, 0x802C
	  stw       r9, 0x5C(r1)
	  subi      r7, r7, 0x2A84
	  stw       r6, 0x5C(r1)
	  addi      r6, r5, 0x685C
	  addi      r5, r1, 0x6C
	  stw       r9, 0x64(r1)
	  stw       r0, 0x64(r1)
	  addi      r0, r1, 0x64
	  stw       r11, 0x60(r1)
	  addi      r11, r1, 0x74
	  stw       r8, 0x68(r1)
	  lwz       r8, 0x4(r3)
	  mr        r3, r11
	  stw       r10, 0x74(r1)
	  stw       r10, 0x6C(r1)
	  stw       r9, 0x74(r1)
	  stw       r9, 0x6C(r1)
	  stw       r6, 0x74(r1)
	  stw       r7, 0x6C(r1)
	  stw       r5, 0x78(r1)
	  stw       r8, 0x70(r1)
	  stw       r0, 0x7C(r1)
	  lwz       r12, 0x0(r11)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x84(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014A33C
 * Size:	00005C
 */
bool TekiAngleCondition::satisfy(Creature* target)
{
	f32 targetAngle = mTeki->calcTargetAngle(target->getPosition());
	if (targetAngle > NMathF::d2r(mAngle / 2.0f)) {
		return false;
	}

	return true;
}
