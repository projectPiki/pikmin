#ifndef _CORENODE_H
#define _CORENODE_H

/**
 * .obj __vt__8CoreNode, weak
 * .4byte __RTTI__8CoreNode
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

/**
 * @brief TODO
 */
struct CoreNode : public ANode {
	virtual void read(RandomAccessStream&); // _0C (weak)

	void setName(char*);
	void add(CoreNode*);
	void del();
	void getChildCount();
	void load(char*, char*, unsigned long);
};

#endif
