#ifndef _BPIKIINF_H
#define _BPIKIINF_H

/**
 * .obj __vt__8BPikiInf, global
 * .4byte __RTTI__8BPikiInf
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte doStore__8BPikiInfFP8Creature
 * .4byte doRestore__8BPikiInfFP8Creature
 * .4byte saveCard__8BPikiInfFR18RandomAccessStream
 * .4byte loadCard__8BPikiInfFR18RandomAccessStream
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
struct BPikiInf : public ANode, public CoreNode {
	virtual void doStore(Creature *);             // _10
	virtual void doRestore(Creature *);           // _14
	virtual void saveCard(RandomAccessStream &);  // _18
	virtual void loadCard(RandomAccessStream &);  // _1C

};

#endif
