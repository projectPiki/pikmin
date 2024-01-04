#ifndef _MEMORYCARD_H
#define _MEMORYCARD_H

/**
 * .obj __vt__10MemoryCard, weak
 * .4byte __RTTI__10MemoryCard
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
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
struct MemoryCard : public ANode, public CoreNode {

	void getOptionsOffset(int);
};

#endif
