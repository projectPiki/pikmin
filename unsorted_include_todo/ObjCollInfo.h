#ifndef _OBJCOLLINFO_H
#define _OBJCOLLINFO_H

/**
 * .obj __vt__11ObjCollInfo, weak
 * .4byte __RTTI__11ObjCollInfo
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
struct ObjCollInfo : public ANode, public CoreNode {

	void loadini(CmdStream*);
};

#endif
