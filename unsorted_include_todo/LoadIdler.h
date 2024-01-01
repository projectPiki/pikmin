#ifndef _LOADIDLER_H
#define _LOADIDLER_H

/**
 * .obj __vt__9LoadIdler, weak
 * .4byte __RTTI__9LoadIdler
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte init__9LoadIdlerFv
 * .4byte draw__9LoadIdlerFR8Graphics
*/

struct ANode {
	virtual void getAgeNodeType();  // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                   // _08
	virtual void read(RandomAccessStream &);  // _0C (weak)
};

/**
 * @brief TODO
 */
struct LoadIdler : public ANode, public CoreNode {
	virtual void init();            // _10 (weak)
	virtual void draw(Graphics &);  // _14 (weak)

};

#endif
