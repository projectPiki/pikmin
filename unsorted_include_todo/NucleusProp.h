#ifndef _NUCLEUSPROP_H
#define _NUCLEUSPROP_H

/**
 * .obj __vt__11NucleusProp, weak
 * .4byte __RTTI__11NucleusProp
 * .4byte 0
 * .4byte read__11NucleusPropFR18RandomAccessStream
 * .4byte __RTTI__11NucleusProp
 * .4byte 0xfffffe14
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@492@read__11NucleusPropFR18RandomAccessStream"
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
struct NucleusProp : public ANode {
	virtual void read(RandomAccessStream&); // _08

	NucleusProp();
};

#endif
