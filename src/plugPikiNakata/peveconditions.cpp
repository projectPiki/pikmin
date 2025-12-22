#include "DebugLog.h"
#include "Peve/Condition.h"
#include "nlib/Geometry.h"
#include "nlib/System.h"
#include "system.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("peveconditions")

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
PeveBooleanCondition::PeveBooleanCondition()
{
	construct(false);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PeveBooleanCondition::construct(bool value)
{
	mValue = value;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
PeveDependenceCondition::PeveDependenceCondition()
{
	construct(nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void PeveDependenceCondition::construct(PeveCondition* cond)
{
	mDependenceCondition = cond;
}

/**
 * @TODO: Documentation
 */
PeveTimeCondition::PeveTimeCondition()
{
	construct(0.0f);
}

/**
 * @TODO: Documentation
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
	construct(1.0f, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void PeveDistanceCondition::construct(f32 threshold, NVector3fIO* vecIOA, NVector3fIO* vecIOB)
{
	PeveBooleanCondition::construct(false);
	mThreshold = threshold;
	mVectorIOA = vecIOA;
	mVectorIOB = vecIOB;
}

/**
 * @TODO: Documentation
 */
void PeveDistanceCondition::update()
{
	NVector3f NRef vecA = NVector3f();
	mVectorIOA->output(vecA);

	NVector3f NRef vecB = NVector3f();
	mVectorIOB->output(vecB);

	f32 dist = vecA.distance(vecB);
	if (dist <= mThreshold) {
		setValue(true);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
PeveComparisonYCondition::PeveComparisonYCondition()
{
	construct(nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void PeveComparisonYCondition::construct(NVector3fIO* vecIOA, NVector3fIO* vecIOB)
{
	PeveBooleanCondition::construct(false);
	mVectorIOA = vecIOA;
	mVectorIOB = vecIOB;
}

/**
 * @TODO: Documentation
 */
void PeveComparisonYCondition::update()
{
	NVector3f NRef vecA = NVector3f();
	mVectorIOA->output(vecA);

	NVector3f NRef vecB = NVector3f();
	mVectorIOB->output(vecB);

	if (vecA.y > vecB.y) {
		setValue(true);
	}
}
