#ifndef _SAICONDITION_H
#define _SAICONDITION_H

/**
 * .obj __vt__12SAICondition, weak
 * .4byte __RTTI__12SAICondition
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte satisfy__12SAIConditionFP10AICreature
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

/**
 * @brief TODO
 */
struct SAICondition : public ANode, public CoreNode {
	virtual void satisfy(AICreature *);  // _10 (weak)

};

#endif
