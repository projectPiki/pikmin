#ifndef _DISPLIST_H
#define _DISPLIST_H

/**
 * .obj __vt__8DispList, global
 * .4byte __RTTI__8DispList
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8DispListFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

/**
 * @brief TODO
 */
struct DispList : public ANode {
	virtual void read(RandomAccessStream&); // _0C
};

#endif
