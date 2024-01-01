#ifndef _CONDITION_H
#define _CONDITION_H

/**
 * .obj __vt__9Condition, weak
 * .4byte __RTTI__9Condition
 * .4byte 0
 * .4byte satisfy__9ConditionFP8Creature
*/

/**
 * @brief TODO
 */
struct Condition {
	virtual void satisfy(Creature *);  // _08

};

#endif
