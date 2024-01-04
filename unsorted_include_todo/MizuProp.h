#ifndef _MIZUPROP_H
#define _MIZUPROP_H

/**
 * .obj __vt__8MizuProp, weak
 * .4byte __RTTI__8MizuProp
 * .4byte 0
 * .4byte read__8MizuPropFR18RandomAccessStream
 * .4byte __RTTI__8MizuProp
 * .4byte 0xfffffe14
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@492@read__8MizuPropFR18RandomAccessStream"
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
struct MizuProp : public ANode {
	virtual void read(RandomAccessStream&); // _08

	MizuProp();
};

#endif
