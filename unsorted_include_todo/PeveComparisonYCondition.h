#ifndef _PEVECOMPARISONYCONDITION_H
#define _PEVECOMPARISONYCONDITION_H

/**
 * .obj __vt__24PeveComparisonYCondition, global
 * .4byte __RTTI__24PeveComparisonYCondition
 * .4byte 0
 * .4byte isMet__20PeveBooleanConditionFv
 * .4byte reset__24PeveComparisonYConditionFv
 * .4byte update__24PeveComparisonYConditionFv
 */

struct PeveBooleanCondition {
	virtual void isMet(); // _08
};

/**
 * @brief TODO
 */
struct PeveComparisonYCondition : public PeveBooleanCondition {
	virtual void reset();  // _0C
	virtual void update(); // _10
};

#endif
