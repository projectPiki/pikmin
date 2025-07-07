#ifndef _DYNPARTICLE_H
#define _DYNPARTICLE_H

#include "CoreNode.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0xAC.
 */
struct DynParticle : public CoreNode {
	DynParticle();

	virtual bool isFree() { return !-mIsFree; }; // _10
	virtual f32 getSize();                       // _14
	virtual void refresh(struct Graphics&);      // _18
	virtual void doKill();                       // _1C

	// _00     = VTBL
	// _00-_14 = CoreNode
	f32 mMass;                      // _14
	Vector3f mInitialPosition;      // _18
	Vector3f mLocalPosition;        // _24
	Vector3f _30;                   // _30
	Vector3f mPreCollisionVelocity; // _3C
	int mIsFree;                    // _48
	DynParticle* mNextParticle;     // _4C, maybe child particle?
	Matrix4f mInvCrossMatrix;       // _50
	f32 mCollisionRadius;           // _90
	Vector3f mWorldPosition;        // _94
	Vector3f mWorldVelocity;        // _A0
};

/**
 * @brief TODO
 */
struct DynParticleHeap {
	DynParticleHeap(int);

	DynParticle* getFreeOne();
	void releaseOne(DynParticle*);

	DynParticle mFreeParticleList; // _00
	DynParticle mUsedParticleList; // _AC
	int mNumParticles;             // _158
	DynParticle* mHeap;            // _15C
};

extern DynParticleHeap* particleHeap;

#endif
