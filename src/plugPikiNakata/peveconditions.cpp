#include "DebugLog.h"
#include "Peve/Condition.h"
#include "nlib/Geometry.h"
#include "nlib/System.h"
#include "system.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("peveconditions")

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
PeveBooleanCondition::PeveBooleanCondition()
{
	construct(false);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008
 */
void PeveBooleanCondition::construct(bool value)
{
	mValue = value;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
PeveDependenceCondition::PeveDependenceCondition()
{
	construct(nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008
 */
void PeveDependenceCondition::construct(PeveCondition* cond)
{
	mDependenceCondition = cond;
}

/**
 * @todo: Documentation
 */
PeveTimeCondition::PeveTimeCondition()
{
	construct(0.0f);
}

/**
 * @todo: Documentation
 */
void PeveTimeCondition::construct(f32 limit)
{
	mCurrTime = 0.0f;
	mLimit    = limit;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000064
 */
PeveDistanceCondition::PeveDistanceCondition()
{
	construct(1.0f, nullptr, nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000018
 */
void PeveDistanceCondition::construct(f32 threshold, NVector3fIO* vecIOA, NVector3fIO* vecIOB)
{
	PeveBooleanCondition::construct(false);
	mThreshold = threshold;
	mVectorIOA = vecIOA;
	mVectorIOB = vecIOB;
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 000060
 */
PeveComparisonYCondition::PeveComparisonYCondition()
{
	construct(nullptr, nullptr);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000014
 */
void PeveComparisonYCondition::construct(NVector3fIO* vecIOA, NVector3fIO* vecIOB)
{
	PeveBooleanCondition::construct(false);
	mVectorIOA = vecIOA;
	mVectorIOB = vecIOB;
}

/**
 * @todo: Documentation
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
