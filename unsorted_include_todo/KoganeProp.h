#ifndef _KOGANEPROP_H
#define _KOGANEPROP_H

/**
 * .obj __vt__10KoganeProp, weak
 * .4byte __RTTI__10KoganeProp
 * .4byte 0
 * .4byte read__10KoganePropFR18RandomAccessStream
 * .4byte __RTTI__10KoganeProp
 * .4byte 0xfffffe14
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@492@read__10KoganePropFR18RandomAccessStream"
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
struct KoganeProp : public ANode {
	virtual void read(RandomAccessStream&); // _08
};

#endif
