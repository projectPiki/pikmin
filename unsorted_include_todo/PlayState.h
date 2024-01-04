#ifndef _PLAYSTATE_H
#define _PLAYSTATE_H

/**
 * .obj __vt__9PlayState, global
 * .4byte __RTTI__9PlayState
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__9PlayStateFR18RandomAccessStream
 * .4byte write__9PlayStateFR18RandomAccessStream
 */

struct ANode {
	virtual void getAgeNodeType(); // _08 (weak)
};

/**
 * @brief TODO
 */
struct PlayState : public ANode {
	virtual void read(RandomAccessStream&);  // _0C
	virtual void write(RandomAccessStream&); // _10

	void openStage(int);
};

#endif
