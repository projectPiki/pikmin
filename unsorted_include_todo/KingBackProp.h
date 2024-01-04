#ifndef _KINGBACKPROP_H
#define _KINGBACKPROP_H

/**
 * .obj __vt__12KingBackProp, weak
 * .4byte __RTTI__12KingBackProp
 * .4byte 0
 * .4byte read__12KingBackPropFR18RandomAccessStream
 * .4byte __RTTI__12KingBackProp
 * .4byte 0xfffffe14
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@492@read__12KingBackPropFR18RandomAccessStream"
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
struct KingBackProp : public ANode {
	virtual void read(RandomAccessStream&); // _08
};

#endif
