#ifndef _JOINT_MATPOLY_H
#define _JOINT_MATPOLY_H

/**
 * .obj __vt__Q25Joint7MatPoly, weak
 * .4byte __RTTI__Q25Joint7MatPoly
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

namespace Joint {
/**
 * @brief TODO
 */
struct MatPoly : public ANode, public CoreNode {
};
} // namespace Joint

#endif
