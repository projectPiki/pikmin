#ifndef _POMPROP_H
#define _POMPROP_H

/**
 * .obj __vt__7PomProp, weak
 * .4byte __RTTI__7PomProp
 * .4byte 0
 * .4byte read__7PomPropFR18RandomAccessStream
 * .4byte __RTTI__7PomProp
 * .4byte 0xfffffe14
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@492@read__7PomPropFR18RandomAccessStream"
*/

struct ANode {
	virtual void read(RandomAccessStream &);  // _08
	virtual void _0C() = 0;                   // _0C
	virtual void _10() = 0;                   // _10
	virtual void getAgeNodeType();            // _14 (weak)
};

/**
 * @brief TODO
 */
struct PomProp : public ANode {
	virtual void read(RandomAccessStream &);  // _08

};

#endif
