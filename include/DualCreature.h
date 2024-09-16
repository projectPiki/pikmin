#ifndef _DUALCREATURE_H
#define _DUALCREATURE_H

#include "types.h"
#include "DynCreature.h"

struct ItemShapeObject;
struct MapMgr;

/**
 * @brief TODO
 */
struct DualCreature : public DynCreature {
	DualCreature();

	virtual void update();           // _E0
	virtual void refresh(Graphics&); // _EC
	virtual void doKill();           // _10C
	virtual void onGround();         // _114

	void isFrontFace();
	void getY();
	void useRealDynamics();
	void useSimpleDynamics();
	void rotateY(f32);

	// unused/inlined:
	void createCollisions(Graphics&);

	// _00      = VTBL
	// _00-_43C = DynCreature?
	// TODO: members
};

/**
 * @brief TODO
 */
struct PelCreature : public DualCreature {
	PelCreature(int, ItemShapeObject*, CreatureProp*, MapMgr*);

	virtual void init(Vector3f&);                // _28
	virtual void startAI(int);                   // _34
	virtual f32 getiMass();                      // _38
	virtual bool isAlive();                      // _88
	virtual void doRender(Graphics&, Matrix4f&); // _118
	virtual void doCreateColls(Graphics&);       // _11C

	// _00      = VTBL
	// _00-_43C = DualCreature?
	// TODO: members
};

#endif
