#ifndef _DYNCREATURE_H
#define _DYNCREATURE_H

#include "types.h"
#include "Creature.h"
#include "Matrix4f.h"

struct DynParticle;

/**
 * @brief TODO
 */
struct DynCreature : public Creature {
	DynCreature();

	virtual void update();           // _E0
	virtual void refresh(Graphics&); // _EC
	virtual void doKill();           // _10C

	void enablePickOffset(f32);
	void disablePickOffset();
	void addParticle(f32, Vector3f&);
	void releaseAllParticles();
	void initialiseSystem();
	void simulate(f32);
	void applyTorque(int, f32);
	void createInvInertiaTensor();
	void calcModelMatrix(Matrix4f&);
	void simulate2(f32);

	f32 getPickOffset() { return mPickOffset; }

	bool isDynFlag(int flag) { return mDynFlag & flag; }
	void setDynFlag(int flag) { mDynFlag |= flag; }
	void resetDynFlag(int flag) { mDynFlag &= ~flag; }

	// might be disableFriction
	void enableFriction() { setDynFlag(1); }

	// might be enableFriction
	void disableFriction() { resetDynFlag(1); }

	// DLL inlines to make:
	// u8 getGroundFlag();

	// _00      = VTBL
	// _00-_2B8 = Creature
	Vector3f _2B8;              // _2B8
	Vector3f _2C4;              // _2C4
	f32 mPickOffset;            // _2D0
	u16 mParticleCount;         // _2D4, might be s16
	DynParticle* mParticleList; // _2D8
	Vector3f _2DC;              // _2DC
	Vector3f _2E8;              // _2E8
	f32 _2F4;                   // _2F4
	Matrix4f _2F8;              // _2F8
	Matrix4f _338;              // _338
	Matrix4f mInertiaTensor;    // _378
	Matrix4f mInvInertiaTensor; // _3B8
	Matrix4f _3F8;              // _3F8
	u8 mDynFlag;                // _438
	u8 _439;                    // _439
};

#endif
