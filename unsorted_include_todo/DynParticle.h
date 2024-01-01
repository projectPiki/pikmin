#ifndef _DYNPARTICLE_H
#define _DYNPARTICLE_H

/**
 * .obj __vt__11DynParticle, global
 * .4byte __RTTI__11DynParticle
 * .4byte 0
 * .4byte getAgeNodeType__5ANodeFv
 * .4byte read__8CoreNodeFR18RandomAccessStream
 * .4byte isFree__11DynParticleFv
 * .4byte getSize__11DynParticleFv
 * .4byte refresh__11DynParticleFR8Graphics
 * .4byte doKill__11DynParticleFv
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
struct DynParticle : public ANode, public CoreNode {
	virtual void isFree();             // _10
	virtual void getSize();            // _14
	virtual void refresh(Graphics &);  // _18
	virtual void doKill();             // _1C

};

#endif
