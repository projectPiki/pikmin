#ifndef _DYNCREATURE_H
#define _DYNCREATURE_H

#include "types.h"
#include "Creature.h"

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
	u8 _2B8[0x2D0 - 0x2B8]; // _2B8
	f32 _2D0;               // _2D0
};

#endif
