#ifndef _DYNCREATURE_H
#define _DYNCREATURE_H

#include "Creature.h"
#include "Matrix4f.h"
#include "types.h"

struct DynParticle;

/**
 * @brief TODO
 */
struct DynCreature : public Creature {
public:
	DynCreature();

	virtual void update();           // _E0
	virtual void refresh(Graphics&); // _EC
	virtual void doKill();           // _10C

	void enablePickOffset(f32);
	void disablePickOffset();
	void addParticle(f32, immut Vector3f&);
	void releaseAllParticles();
	void initialiseSystem();
	void simulate(f32);
	void applyTorque(int, f32);
	void createInvInertiaTensor();
	void calcModelMatrix(Matrix4f&);
	void simulate2(f32);

	f32 getPickOffset() { return mPickOffset; }

	u8 getGroundFlag() { return mGroundFlag; }

	// might be disableFriction
	void enableFriction() { setDynFlag(1); }

	// might be enableFriction
	void disableFriction() { resetDynFlag(1); }

protected:
	void setDynFlag(int flag) { mDynFlag |= flag; }
	void resetDynFlag(int flag) { mDynFlag &= ~flag; }
	bool isDynFlag(int flag) { return mDynFlag & flag; }

	// Users of the derived `Pellet` class access `mAngularMomentum` and `mAngularVelocity` in violating ways.
	// It's complicated enough that I doubt this class was ever properly encapsulated.  DualCreature totally was, though.
public:
	// _00      = VTBL
	// _00-_2B8 = Creature
	Vector3f mAngularMomentum; // _2B8
	Vector3f mAngularVelocity; // _2C4
	f32 mPickOffset;                 // _2D0
	u16 mParticleCount;              // _2D4, might be s16
	DynParticle* mParticleList;      // _2D8
	Vector3f mAngularImpulseAccum;   // _2DC
	Vector3f mCenterOfMass;          // _2E8
	f32 mMass;                       // _2F4
	Matrix4f mWorldInertiaTensor;    // _2F8
	Matrix4f mWorldInvInertiaTensor; // _338
	Matrix4f mInertiaTensor;         // _378
	Matrix4f mInvInertiaTensor;      // _3B8
	Matrix4f _3F8;                   // _3F8
	u8 mDynFlag;                     // _438
	u8 mGroundFlag;                  // _439
};

#endif
