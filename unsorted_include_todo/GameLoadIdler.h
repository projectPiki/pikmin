#ifndef _GAMELOADIDLER_H
#define _GAMELOADIDLER_H

/**
 * .obj __vt__13GameLoadIdler, global
 * .4byte __RTTI__13GameLoadIdler
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte init__13GameLoadIdlerFv
 * .4byte draw__13GameLoadIdlerFR8Graphics
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

struct CoreNode {
	virtual void _08() = 0;                 // _08
	virtual void read(RandomAccessStream&); // _0C (weak)
};

/**
 * @brief TODO
 */
struct GameLoadIdler : public ANode, public CoreNode {
	virtual void init();          // _10
	virtual void draw(Graphics&); // _14
};

#endif
