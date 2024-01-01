#ifndef _PELLETMGR_USENODE_H
#define _PELLETMGR_USENODE_H

/**
 * .obj __vt__Q29PelletMgr7UseNode, weak
 * .4byte __RTTI__Q29PelletMgr7UseNode
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

namespace PelletMgr {
/**
 * @brief TODO
 */
struct UseNode : public ANode, public CoreNode {

};
} // namespace PelletMgr

#endif
