#ifndef _PEVEBOOLEANCONDITION_H
#define _PEVEBOOLEANCONDITION_H

/**
 * .obj __vt__20PeveBooleanCondition, weak
 * .4byte __RTTI__20PeveBooleanCondition
 * .4byte 0
 * .4byte isMet__20PeveBooleanConditionFv
 * .4byte reset__13PeveConditionFv
 * .4byte update__13PeveConditionFv
*/

struct PeveCondition {
	virtual void isMet();  // _08
	virtual void reset();  // _0C (weak)
	virtual void update(); // _10 (weak)
};

/**
 * @brief TODO
 */
struct PeveBooleanCondition : public PeveCondition {
	virtual void isMet();  // _08

};

#endif
