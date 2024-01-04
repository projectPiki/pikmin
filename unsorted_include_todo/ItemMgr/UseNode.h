#ifndef _ITEMMGR_USENODE_H
#define _ITEMMGR_USENODE_H

/**
 * .obj __vt__Q27ItemMgr7UseNode, weak
 * .4byte __RTTI__Q27ItemMgr7UseNode
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

namespace ItemMgr {
/**
 * @brief TODO
 */
struct UseNode : public ANode, public CoreNode {
};
} // namespace ItemMgr

#endif
