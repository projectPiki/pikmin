#ifndef _PEVEDISTANCECONDITION_H
#define _PEVEDISTANCECONDITION_H

/**
 * .obj __vt__21PeveDistanceCondition, global
 * .4byte __RTTI__21PeveDistanceCondition
 * .4byte 0
 * .4byte isMet__20PeveBooleanConditionFv
 * .4byte reset__21PeveDistanceConditionFv
 * .4byte update__21PeveDistanceConditionFv
 */

struct PeveBooleanCondition {
	virtual void isMet(); // _08
};

/**
 * @brief TODO
 */
struct PeveDistanceCondition : public PeveBooleanCondition {
	virtual void reset();  // _0C
	virtual void update(); // _10
};

#endif
