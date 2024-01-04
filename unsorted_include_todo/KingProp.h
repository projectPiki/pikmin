#ifndef _KINGPROP_H
#define _KINGPROP_H

/**
 * .obj __vt__8KingProp, weak
 * .4byte __RTTI__8KingProp
 * .4byte 0
 * .4byte read__8KingPropFR18RandomAccessStream
 * .4byte __RTTI__8KingProp
 * .4byte 0xfffffe14
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@492@read__8KingPropFR18RandomAccessStream"
 */

struct ANode {
	virtual void read(RandomAccessStream&); // _08
	virtual void _0C() = 0;                 // _0C
	virtual void _10() = 0;                 // _10
	virtual void getAgeNodeType();          // _14 (weak)
};

/**
 * @brief TODO
 */
struct KingProp : public ANode {
	virtual void read(RandomAccessStream&); // _08
};

#endif
