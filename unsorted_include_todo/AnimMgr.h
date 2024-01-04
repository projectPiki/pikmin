#ifndef _ANIMMGR_H
#define _ANIMMGR_H

/**
 * .obj __vt__7AnimMgr, global
 * .4byte __RTTI__7AnimMgr
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__7AnimMgrFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

/**
 * @brief TODO
 */
struct AnimMgr : public ANode {
	virtual void read(RandomAccessStream&); // _0C
};

#endif
