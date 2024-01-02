#ifndef _PEVECONDITION_H
#define _PEVECONDITION_H

/**
 * .obj __vt__13PeveCondition, weak
 * .4byte __RTTI__13PeveCondition
 * .4byte 0
 * .4byte 0
 * .4byte reset__13PeveConditionFv
 * .4byte update__13PeveConditionFv
*/

/**
 * @brief TODO
 */
struct PeveCondition {
	virtual void _08() = 0;  // _08
	virtual void reset();    // _0C (weak)
	virtual void update();   // _10 (weak)

};

#endif
