#ifndef _CREATURENODE_H
#define _CREATURENODE_H

/**
 * .obj __vt__12CreatureNode, weak
 * .4byte __RTTI__12CreatureNode
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                 // _08
	virtual void read(RandomAccessStream&); // _0C (weak)
};

/**
 * @brief TODO
 */
struct CreatureNode : public ANode, public CoreNode {
};

#endif
