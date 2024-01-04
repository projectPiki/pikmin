#ifndef _MEMINFO_H
#define _MEMINFO_H

/**
 * .obj __vt__7MemInfo, weak
 * .4byte __RTTI__7MemInfo
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
struct MemInfo : public ANode, public CoreNode {
};

#endif
