#ifndef _BASEINF_H
#define _BASEINF_H

/**
 * .obj __vt__7BaseInf, global
 * .4byte __RTTI__7BaseInf
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte doStore__7BaseInfFP8Creature
 * .4byte doRestore__7BaseInfFP8Creature
 * .4byte saveCard__7BaseInfFR18RandomAccessStream
 * .4byte loadCard__7BaseInfFR18RandomAccessStream
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
struct BaseInf : public ANode, public CoreNode {
	virtual void doStore(Creature *);             // _10
	virtual void doRestore(Creature *);           // _14
	virtual void saveCard(RandomAccessStream &);  // _18
	virtual void loadCard(RandomAccessStream &);  // _1C

};

#endif
