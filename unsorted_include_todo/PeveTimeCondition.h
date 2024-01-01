#ifndef _PEVETIMECONDITION_H
#define _PEVETIMECONDITION_H

/**
 * .obj __vt__17PeveTimeCondition, weak
 * .4byte __RTTI__17PeveTimeCondition
 * .4byte 0
 * .4byte isMet__17PeveTimeConditionFv
 * .4byte reset__17PeveTimeConditionFv
 * .4byte update__17PeveTimeConditionFv
*/

/**
 * @brief TODO
 */
struct PeveTimeCondition {
	virtual void isMet();  // _08
	virtual void reset();  // _0C
	virtual void update(); // _10

};

#endif
