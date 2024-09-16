#ifndef _DYNCREATURE_H
#define _DYNCREATURE_H

#include "types.h"
#include "Creature.h"
#include "Matrix4f.h"

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

	// _00      = VTBL
	// _00-_2B8 = Creature
	Vector3f _2B8;          // _2B8
	Vector3f _2C4;          // _2C4
	f32 _2D0;               // _2D0
	u16 _2D4;               // _2D4, might be s16
	u32 _2D8;               // _2D8, unknown
	Vector3f _2DC;          // _2DC
	Vector3f _2E8;          // _2E8
	f32 _2F4;               // _2F4
	Matrix4f _2F8;          // _2F8
	Matrix4f _338;          // _338
	Matrix4f _378;          // _378
	Matrix4f _3B8;          // _3B8
	u8 _3F8[0x438 - 0x3F8]; // _3F8, unknown
	u8 _438;                // _438, flag of some kind?
	u8 _439;                // _439
};

#endif
