#ifndef _CREATUREINF_H
#define _CREATUREINF_H

/**
 * .obj __vt__11CreatureInf, global
 * .4byte __RTTI__11CreatureInf
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte doStore__11CreatureInfFP8Creature
 * .4byte doRestore__11CreatureInfFP8Creature
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

struct BaseInf {
	virtual void _08() = 0;                       // _08
	virtual void _0C() = 0;                       // _0C
	virtual void doStore(Creature *);             // _10
	virtual void doRestore(Creature *);           // _14
	virtual void saveCard(RandomAccessStream &);  // _18
	virtual void loadCard(RandomAccessStream &);  // _1C
};

/**
 * @brief TODO
 */
struct CreatureInf : public ANode, public CoreNode, public BaseInf {
	virtual void doStore(Creature *);    // _10
	virtual void doRestore(Creature *);  // _14

};

#endif
