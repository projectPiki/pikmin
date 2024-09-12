#ifndef _DYNPARTICLE_H
#define _DYNPARTICLE_H

#include "types.h"
#include "CoreNode.h"

/**
 * @brief TODO
 */
struct DynParticle : public CoreNode {
	DynParticle();

	virtual bool isFree() { return !-mIsFree; }; // _10
	virtual f32 getSize();                       // _14
	virtual void refresh(struct Graphics&);      // _18
	virtual void doKill();                       // _1C

	// _00     = VTBL
	// _00-_14 = CoreNode
	u8 _14[0x48 - 0x14]; // _14, unknown
	int mIsFree;         // _48
	u8 _4C[0x90 - 0x4C]; // _4C, unknown
	f32 _90;             // _90
};

/**
 * @brief TODO
 */
struct DynParticleHeap {
	DynParticleHeap(int);

	void getFreeOne();
	void releaseOne(DynParticle*);

	// TODO: members
};

#endif
