#ifndef _EDITNODE_H
#define _EDITNODE_H

/**
 * .obj __vt__8EditNode, weak
 * .4byte __RTTI__8EditNode
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte msgCommand__8EditNodeFR7DataMsg
 * .4byte render2d__8EditNodeFR8GraphicsRi
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
struct EditNode : public ANode, public CoreNode {
	virtual void msgCommand(DataMsg&);      // _10 (weak)
	virtual void render2d(Graphics&, int&); // _14 (weak)
};

#endif
