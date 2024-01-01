#ifndef _SNAKEPROP_H
#define _SNAKEPROP_H

/**
 * .obj __vt__9SnakeProp, weak
 * .4byte __RTTI__9SnakeProp
 * .4byte 0
 * .4byte read__9SnakePropFR18RandomAccessStream
 * .4byte __RTTI__9SnakeProp
 * .4byte 0xfffffe14
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte "@492@read__9SnakePropFR18RandomAccessStream"
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
struct SnakeProp : public ANode {
	virtual void read(RandomAccessStream &);  // _08

};

#endif
