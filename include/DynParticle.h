#ifndef _DYNPARTICLE_H
#define _DYNPARTICLE_H

#include "types.h"
#include "CoreNode.h"

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

/**
 * @brief TODO
 */
struct DynParticle : public CoreNode {
	virtual bool isFree(){return !-mIsFree;};           // _10
	virtual f32 getSize();          // _14
	virtual void refresh(struct Graphics&); // _18
	virtual void doKill();           // _1C

	DynParticle();
	u8 _14[0x48 - 0x14];
	int mIsFree; // _48
	u8 _4C[0x90 - 0x4C];
	f32 _90; // _90
};

struct DynParticleHeap{
	void getFreeOne();
	void releaseOne(DynParticle*);
	DynParticleHeap(int);
};

#endif
