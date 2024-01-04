#ifndef _TEKICONDITION_H
#define _TEKICONDITION_H

/**
 * .obj __vt__13TekiCondition, weak
 * .4byte __RTTI__13TekiCondition
 * .4byte 0
 * .4byte satisfy__13TekiConditionFP8Creature
 */

/**
 * @brief TODO
 */
struct TekiCondition {
	virtual void satisfy(Creature*); // _08
};

#endif
