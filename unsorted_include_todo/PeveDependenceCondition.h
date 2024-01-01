#ifndef _PEVEDEPENDENCECONDITION_H
#define _PEVEDEPENDENCECONDITION_H

/**
 * .obj __vt__23PeveDependenceCondition, weak
 * .4byte __RTTI__23PeveDependenceCondition
 * .4byte 0
 * .4byte isMet__23PeveDependenceConditionFv
 * .4byte reset__23PeveDependenceConditionFv
 * .4byte update__23PeveDependenceConditionFv
*/

/**
 * @brief TODO
 */
struct PeveDependenceCondition {
	virtual void isMet();  // _08
	virtual void reset();  // _0C
	virtual void update(); // _10

};

#endif
